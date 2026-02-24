#include "llvm/ADT/APInt.h"

using namespace llvm;
using namespace std;

extern "C" void evalHead(){};

extern "C" void getConstraint(APInt* arg0, int* autogen0){
    APInt arg00 = arg0[0];
    APInt arg01 = arg0[1];
    APInt andi = arg00&arg01;
    APInt const0(arg00.getBitWidth(),0);
    int result = andi.eq(const0);
    autogen0[0] = result;
}

extern "C" void getInstanceConstraint(APInt* arg0, APInt inst, int* autogen0){
    APInt arg00 = arg0[0];
    APInt arg01 = arg0[1];
    APInt neg_inst = ~inst;
    APInt or1 = neg_inst|arg00;
    APInt or2 = inst|arg01;
    int cmp1 = or1.eq(neg_inst);
    int cmp2 = or2.eq(inst);
    int result = cmp1&cmp2;
    autogen0[0] = result;
}

extern "C" void contains(APInt* arg0, APInt* arg1, int* autogen0){
    APInt arg00 = arg0[0];
    APInt arg01 = arg0[1];
    APInt arg10 = arg1[0];
    APInt arg11 = arg1[1];
    APInt andi0 = arg00&arg10;
    APInt andi1 = arg01&arg11;
    int result0 = andi0.eq(arg10);
    int result1 = andi1.eq(arg11);
    int result = result0&result1;
    autogen0[0] = result;
}

extern "C" void meet(APInt* arg0, APInt* arg1, APInt* autogen0){
    APInt arg00 = arg0[0];
    APInt arg01 = arg0[1];
    APInt arg10 = arg1[0];
    APInt arg11 = arg1[1];
    APInt and0 = arg00|arg10;
    APInt and1 = arg01|arg11;
    APInt result[2];
    result[0] = and0;
    result[1] = and1;
    autogen0[0] = result[0];
    autogen0[1] = result[1];
}

extern "C" void join(APInt* arg0, APInt* arg1, APInt* autogen0){
    APInt arg00 = arg0[0];
    APInt arg01 = arg0[1];
    APInt arg10 = arg1[0];
    APInt arg11 = arg1[1];
    APInt and0 = arg00&arg10;
    APInt and1 = arg01&arg11;
    APInt result[2];
    result[0] = and0;
    result[1] = and1;
    autogen0[0] = result[0];
    autogen0[1] = result[1];
}

extern "C" void getTop(APInt* arg0, APInt* autogen0){
    APInt arg00 = arg0[0];
    APInt const0(arg00.getBitWidth(),0);
    APInt result[2];
    result[0] = const0;
    result[1] = const0;
    autogen0[0] = result[0];
    autogen0[1] = result[1];
}

extern "C" void fromConcrete(APInt inst, APInt* autogen0){
    APInt neg_inst = ~inst;
    APInt result[2];
    result[0] = neg_inst;
    result[1] = inst;
    autogen0[0] = result[0];
    autogen0[1] = result[1];
}

extern "C" void distance(APInt* arg0, APInt* arg1, APInt* autogen0){
    APInt arg00 = arg0[0];
    APInt arg01 = arg0[1];
    APInt arg10 = arg1[0];
    APInt arg11 = arg1[1];
    APInt xori0 = arg00^arg10;
    APInt xori1 = arg01^arg11;
    unsigned result0_autocast = xori0.popcount();
    APInt result0(xori0.getBitWidth(),result0_autocast);
    unsigned result1_autocast = xori1.popcount();
    APInt result1(xori1.getBitWidth(),result1_autocast);
    APInt result = result0+result1;
    autogen0[0] = result;
}


extern "C" void concrete_op(APInt* args, APInt* result) {
    result[0] = args[0] & args[1];
}


extern "C" void test(APInt** args, APInt* result) {
    result[0] = args[0][0] | args[1][0];
    result[1] = args[0][1] & args[1][1];
}

extern "C" void baseTest(APInt** args, APInt* result) {
    getTop(args[0],result);
}