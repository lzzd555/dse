#include "Instrument.h"
#include "iostream"
using namespace llvm;
//using namespace std;
namespace instrument {

/*
 * Implement your instrumentation for dynamic symbolic execution engine
 */
bool Instrument::runOnFunction(Function &F) {
    /* Add your code here */
    LLVMContext &ctx = F.getContext();
    auto initFuc = F.getParent()->getOrInsertFunction("__DSE_Init__",Type::getVoidTy(ctx));
    auto regFuc = F.getParent()->getOrInsertFunction("__DSE_Register__",Type::getVoidTy(ctx));
    auto constFuc = F.getParent()->getOrInsertFunction("__DSE_Const__",Type::getVoidTy(ctx));
    auto allocaFuc = F.getParent()->getOrInsertFunction("__DSE_Alloca__",Type::getVoidTy(ctx));
    auto storeFuc = F.getParent()->getOrInsertFunction("__DSE_Store__",Type::getVoidTy(ctx));
    auto loadFuc = F.getParent()->getOrInsertFunction("__DSE_Load__",Type::getVoidTy(ctx));
    auto icmpFuc = F.getParent()->getOrInsertFunction("__DSE_ICmp__",Type::getVoidTy(ctx));
    auto binOpFuc = F.getParent()->getOrInsertFunction("__DSE_BinOp__",Type::getVoidTy(ctx));
    auto branchFuc = F.getParent()->getOrInsertFunction("__DSE_Branch__",Type::getVoidTy(ctx));
    auto inputFuc = F.getParent()->getOrInsertFunction("__DSE_Input__",Type::getVoidTy(ctx));
    auto exitFuc = F.getParent()->getOrInsertFunction("__DSE_Exit__",Type::getVoidTy(ctx));

    for(auto BB = F.begin(); BB != F.end(); BB++)
    {
        for(auto instr = BB->begin(); instr != BB->end(); instr++)
        {
            IRBuilder<> builder(&*instr);
            builder.SetInsertPoint(&*BB,++builder.GetInsertPoint());
            if(instr == BB->begin() && BB == F.begin())
                builder.CreateCall(initFuc);
            if(auto* op = dyn_cast<AllocaInst>(&instr))        //Alloca命令插桩
            {
                Value* arg1 = ConstantInt::get(Type::getInt64Ty(ctx),getRegisterID(op));
                Value* args[] = {arg1,op};
                builder.CreateCall(allocaFuc,args);
            }
            if(auto* op = dyn_cast<LoadInst>(&instr))           //Load命令插桩
            {
                Value* arg1 = ConstantInt::get(Type::getInt64Ty(ctx),getRegisterID(op));
                Value* args[] = {arg1,op};
                builder.CreateCall(allocaFuc,args);
            }
            if(auto* op = dyn_cast<StoreInst>(&instr))         //Store命令插桩
            {
                auto reg = ConstantInt::get(Type::getInt64Ty(ctx), getRegisterID(instr.getOperand(1)));
                if(X1->getType()->isIntegerTy())
                {
                    Value* args1[] = {X1};
                    Value* args2[] = {reg};
                }
                else
                {
                    Value* args1[] = {ConstantInt::get(Type::getInt64Ty(ctx), getRegisterID(X1))};
                    Value* args2[] = {reg};
                }
            }
            if(auto* op = dyn_cast<BinaryOperator>(&instr))     //BinOp和ICmp命令插桩
            {
                IRBuilder<> builder(op);
                Value* lhs = op->getOperand(0);
                Value* rhs = op->getOperand(1);
                Value* args[] = {};
                lhs = ConstantInt::get(Type::getInt64Ty(ctx),getRegisterID((lhs)));
                if(!(rhs->getType()->isIntegerTy() || rhs->getType()->isDoubleTy() || rhs->getType()->isFloatTy()))
                    rhs = ConstantInt::get(Type::getInt64Ty(ctx),getRegisterID((rhs)));

                {
                    Value * args[] = {lhs,ConstantInt::get(Type::getInt64Ty(ctx),op->getOpcode())};
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
