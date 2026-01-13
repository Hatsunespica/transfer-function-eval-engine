#include "llvm/ADT/APInt.h"
#include <vector>

using namespace llvm;
using namespace std;

extern "C" void evalHead(){};

extern "C" bool getConstraint(APInt* abstractDomain){
    APInt zero = APInt::getZero(abstractDomain[0].getBitWidth());
    APInt andResult = abstractDomain[0] & abstractDomain[1];
    return zero == andResult;
}

extern "C" bool  getInstanceConstraint(APInt* abstractDomain, APInt* concreteValue) {
    APInt orOne = abstractDomain[1] | concreteValue[0];
    APInt neg = ~concreteValue[0];
    APInt orZero = abstractDomain[0] | neg;
    bool cmp1 = orOne == abstractDomain[1];
    bool cmp2 = orZero == abstractDomain[0];
    return cmp1 && cmp2;
}

extern "C" void getTop(APInt* abstractDomain, APInt* result) {
    APInt zero = APInt::getZero(abstractDomain[0].getBitWidth());
    APInt allOnes = APInt::getAllOnes(abstractDomain[0].getBitWidth());
    result[0] = zero;
    result[1]= allOnes;
}

extern "C" void distance(APInt* abstractDomain1, APInt* abstractDomain2, APInt* result) {
    APInt xor0 = abstractDomain1[0] ^ abstractDomain2[0];
    APInt xor1 = abstractDomain1[1] ^ abstractDomain2[1];
    unsigned popcount0 = xor0.popcount();
    unsigned popcount1 = xor1.popcount();
    result[0] = APInt(32, popcount0 +popcount1);
}

extern "C" void fromConcrete(APInt* concreteValue, APInt* abstractDomain) {
    abstractDomain[0] = ~concreteValue[0];
    abstractDomain[1] = concreteValue[0];
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


extern "C" void getVector_C(APInt* a,
                           APInt* b,
                           APInt* out) {
    out[0] = a[0];
    out[1] = b[0];
}



extern "C" void getKB(APInt** args,
                           APInt* out) {
    out[0] = args[0][0];
    out[1] = args[1][0];
}
