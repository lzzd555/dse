#include "Instrument.h"
using namespace llvm;
namespace instrument {

/*
 * Implement your instrumentation for dynamic symbolic execution engine
 */
bool Instrument::runOnFunction(Function &F) {
    /* Add your code here */
    LLVMContext &ctx = F.getContext();
    auto initFuc = F.getParent()->getOrInsertFunction("__DSE_Init__",Type::getVoidTy(ctx));
    auto regFuc = F.getParent()->getOrInsertFunction("__DSE_Register__",Type::getVoidTy(ctx),Type::getInt32Ty(ctx));
    auto constFuc = F.getParent()->getOrInsertFunction("__DSE_Const__",Type::getVoidTy(ctx),Type::getInt32Ty(ctx));
    auto allocaFuc = F.getParent()->getOrInsertFunction("__DSE_Alloca__",Type::getVoidTy(ctx),Type::getInt32Ty(ctx),Type::getInt32PtrTy(ctx));
    auto storeFuc = F.getParent()->getOrInsertFunction("__DSE_Store__",Type::getVoidTy(ctx),Type::getInt32PtrTy(ctx));
    auto loadFuc = F.getParent()->getOrInsertFunction("__DSE_Load__",Type::getVoidTy(ctx),Type::getInt32Ty(ctx),Type::getInt32PtrTy(ctx));
    auto icmpFuc = F.getParent()->getOrInsertFunction("__DSE_ICmp__",Type::getVoidTy(ctx),Type::getInt32Ty(ctx),Type::getInt32Ty(ctx));
    auto binOpFuc = F.getParent()->getOrInsertFunction("__DSE_BinOp__",Type::getVoidTy(ctx),Type::getInt32Ty(ctx),Type::getInt32Ty(ctx));
    auto branchFuc = F.getParent()->getOrInsertFunction("__DSE_Branch__",Type::getVoidTy(ctx),Type::getInt32Ty(ctx),Type::getInt32Ty(ctx),Type::getInt32Ty(ctx));
    //auto exitFuc = F.getParent()->getOrInsertFunction("__DSE_Exit__",Type::getVoidTy(ctx));

    for(auto BB = F.begin(); BB != F.end(); BB++)
    {
        for(auto instr = BB->begin(); instr != BB->end(); instr++)
        {
            IRBuilder<> builder(&*instr);
            builder.SetInsertPoint(&*BB,++builder.GetInsertPoint());
            if(instr == BB->begin() && BB == F.begin())         //init插桩
                builder.CreateCall(initFuc);
//            if(instr == BB->end() && BB == F.end())
//                builder.CreateCall(exitFuc);
            else if(auto* op = dyn_cast<AllocaInst>(&*instr))        //Alloca命令插桩
            {
                Value* arg1 = ConstantInt::get(Type::getInt32Ty(ctx),getRegisterID(op));
                Value* args[] = {arg1,op};
                builder.CreateCall(allocaFuc,args);
            }
            else if(auto* op = dyn_cast<LoadInst>(&*instr))           //Load命令插桩
            {
                Value* arg1 = ConstantInt::get(Type::getInt32Ty(ctx),getRegisterID(op));
                Value* arg2 = op->getOperand(0);
                Value* args[] = {arg1,arg2};
                builder.CreateCall(loadFuc,args);
            }
            else if(auto* op = dyn_cast<StoreInst>(&*instr))         //Store命令插桩
            {
                Value* arg1 = op->getOperand(0);
                Value* arg2 = op->getOperand(1);
//                errs()<< "Store::";
//                arg1->print(errs());
//                errs()<<"   Store::arg1->getName() : "<<arg1->getName()<<"\n";

                if(dyn_cast<ConstantInt>(arg1))
                    builder.CreateCall(constFuc,arg1);
                else
                    builder.CreateCall(regFuc,ConstantInt::get(Type::getInt32Ty(ctx),getRegisterID(arg1)));
                builder.CreateCall(storeFuc,arg2);
            }
            else if(auto* op = dyn_cast<BinaryOperator>(&*instr))     //BinOp命令插桩
            {
                Value* lhs = op->getOperand(0);
                Value* rhs = op->getOperand(1);
//                errs()<< "lhs = "<< lhs->getName() << "\n";
//                errs()<< "rhs = "<< rhs->getName() << "\n";
//                errs()<< "instr->getName = "<< instr->getName() << "\n";
//                errs()<< "op = "<< op->getName() << "\n";
                if(dyn_cast<ConstantInt>(lhs))
                    builder.CreateCall(constFuc,lhs);
                else
                    builder.CreateCall(regFuc,ConstantInt::get(Type::getInt32Ty(ctx),getRegisterID(lhs)));

                if(dyn_cast<ConstantInt>(rhs))
                    builder.CreateCall(constFuc,rhs);
                else
                    builder.CreateCall(regFuc,ConstantInt::get(Type::getInt32Ty(ctx),getRegisterID(rhs)));

                Value* args[] = {ConstantInt::get(Type::getInt32Ty(ctx),getRegisterID(op)),
                                 ConstantInt::get(Type::getInt32Ty(ctx),op->getOpcode())};
                builder.CreateCall(binOpFuc,args);
            }
            else if(auto* op = dyn_cast<ICmpInst>(&*instr))          //ICmp命令插桩
            {
                Value* lhs = op->getOperand(0);
                Value* rhs = op->getOperand(1);
//                errs()<< "ICmp::lhs = "<< lhs->getName() << "\n";
//                errs()<< "ICmp::rhs = "<< rhs->getName() << "\n";
//                errs()<< "ICmp::op->getPredicate() = "<< op->getPredicate() << "\n";
                if(dyn_cast<ConstantInt>(lhs))
                    builder.CreateCall(constFuc,lhs);
                else
                    builder.CreateCall(regFuc,ConstantInt::get(Type::getInt32Ty(ctx),getRegisterID(lhs)));
                if(dyn_cast<ConstantInt>(rhs))
                    builder.CreateCall(constFuc,rhs);
                else
                    builder.CreateCall(regFuc,ConstantInt::get(Type::getInt32Ty(ctx),getRegisterID(rhs)));
                Value* args[] = {ConstantInt::get(Type::getInt32Ty(ctx),getRegisterID(op)),
                                 ConstantInt::get(Type::getInt32Ty(ctx),op->getPredicate())};
                builder.CreateCall(icmpFuc,args);
            }
            else if(auto *op = dyn_cast<BranchInst>(&*instr))        //Branch命令插桩
            {
                int num = op->getNumOperands();
                if(num == 3)
                {
//                    errs()<<"Branch::op->getOperand() "<<op->getOperand(0)<<"\n";
//                    op->getOperand(0)->getType()->print(errs());
//                    errs()<<"\n";
                    Value* cmp_res = op->getOperand(0);
//                    builder.SetInsertPoint(&*BB,instr);
//                    builder.CreateCall(branchFuc,{ConstantInt::get(Type::getInt32Ty(ctx),getBranchID(op)),
//                                                   ConstantInt::get(Type::getInt32Ty(ctx),getRegisterID(cmp_res)),
//                                                   ConstantInt::get(Type::getInt32Ty(ctx),1)});
                    //cmp_res->print(errs());
                    BasicBlock* tb = op->getSuccessor(0);
                    BasicBlock* fb = op->getSuccessor(1);
                    builder.SetInsertPoint(tb,tb->begin());
                    builder.CreateCall(branchFuc,{ConstantInt::get(Type::getInt32Ty(ctx),getBranchID(op)),
                                                  ConstantInt::get(Type::getInt32Ty(ctx),getRegisterID(cmp_res)),
                                                  ConstantInt::get(Type::getInt32Ty(ctx),1)});
                    builder.SetInsertPoint(fb,fb->begin());
                    builder.CreateCall(branchFuc,{ConstantInt::get(Type::getInt32Ty(ctx),getBranchID(op)),
                                                  ConstantInt::get(Type::getInt32Ty(ctx),getRegisterID(cmp_res)),
                                                  ConstantInt::get(Type::getInt32Ty(ctx),0)});
                }
            }
        }
    }

    return true;
}
char Instrument::ID = 1;
static RegisterPass<Instrument>
    X("Instrument", "Instrumentations for Dynamic Symbolic Execution", false,
      false);
} // namespace instrument
