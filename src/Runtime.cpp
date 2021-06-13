#include <iostream>
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/Instruction.h"
#include "SymbolicInterpreter.h"
#include "z3++.h"
extern SymbolicInterpreter SI;
using namespace  z3;
using namespace llvm;
using namespace std;
/*
 * Implement your transfer functions.
 */
extern "C" void __DSE_Alloca__(int R, int *Ptr)
{ /* Add your code here */
    Address Addr(R);
    expr SE = SI.getContext().int_val((uintptr_t)Ptr);
    SI.getMemory().insert(make_pair(Addr, SE));
}

extern "C" void __DSE_Store__(int *X)
{ /* Add your code here */
    expr SE = SI.getStack().top();
    SI.getStack().pop();
    Address Addr(X);
    SI.getMemory().insert(make_pair(Addr,SE));
}

extern "C" void __DSE_Load__(int Y, int *X)
{ /* Add your code here */
    Address Addr(Y);
    Address addr(X);
    expr SE = SI.getMemory().at(addr);
    SI.getMemory().insert(make_pair(Addr,SE));
}

extern "C" void __DSE_ICmp__(int R, int Op)
{ /* Add your code here */
    expr X1 = SI.getStack().top();      //取第一个操作数
    SI.getStack().pop();
    expr X2 = SI.getStack().top();      //取第二个操作数
    SI.getStack().pop();
    Address addr(R);
    if(Op == CmpInst::Predicate::ICMP_EQ)
        SI.getMemory().insert(make_pair(addr, X1 == X2));
    else if(Op == CmpInst::Predicate::ICMP_UGT || Op == CmpInst::Predicate::ICMP_SGT)
        SI.getMemory().insert(make_pair(addr, X1 > X2));
    else if(Op == CmpInst::Predicate::ICMP_UGE || Op == CmpInst::Predicate::ICMP_SGE)
        SI.getMemory().insert(make_pair(addr, X1 >= X2));
    else if(Op == CmpInst::Predicate::ICMP_ULT || Op == CmpInst::Predicate::ICMP_SLT)
        SI.getMemory().insert(make_pair(addr, X1 < X2));
    else if(Op == CmpInst::Predicate::ICMP_ULE || Op == CmpInst::Predicate::ICMP_SLE)
        SI.getMemory().insert(make_pair(addr, X1 <= X2));
}

extern "C" void __DSE_BinOp__(int R, int Op)
{ /* Add your code here */
    expr X1 = SI.getStack().top();      //取第一个操作数
    SI.getStack().pop();
    expr X2 = SI.getStack().top();      //取第二个操作数
    SI.getStack().pop();
    Address addr(R);
    if(Op == Instruction::Add)
        SI.getMemory().insert(make_pair(addr,X1 + X2));
    else if(Op == Instruction::Sub)
        SI.getMemory().insert(make_pair(addr,X1 - X2));
    else if(Op == Instruction::Mul)
        SI.getMemory().insert(make_pair(addr,X1 * X2));
    else if(Op == Instruction::SDiv || Op == Instruction::FDiv || Op == Instruction::UDiv)
        SI.getMemory().insert(make_pair(addr,X1 / X2));
    else if(Op == Instruction::And)
        SI.getMemory().insert(make_pair(addr,X1 & X2));
    else if(Op == Instruction::Or)
        SI.getMemory().insert(make_pair(addr,X1 | X2));
    else if(Op == Instruction::Xor)
        SI.getMemory().insert(make_pair(addr,X1 ^ X2));
}
