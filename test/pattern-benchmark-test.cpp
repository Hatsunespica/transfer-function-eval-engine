#include "llvm/ADT/APInt.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/KnownBits.h"
#include <vector>

using namespace llvm;
using namespace std;

#include "../TFImpl/Utils.h"
#include "../TFImpl/XORImpl.h"
#include "../TFImpl/ANDImpl.h"
#include "../TFImpl/ORImpl.h"
#include "../TFImpl/MulImpl.h"
#include "../TFImpl/AddImpl.h"
#include "../TFImpl/SubImpl.h"
#include "../TFImpl/LshrExactImpl.h"
#include "../TFImpl/LshrImpl.h"
#include "../TFImpl/AshrExactImpl.h"
#include "../TFImpl/AshrImpl.h"
#include "../TFImpl/ShlImpl.h"
#include "../TFImpl/ShlNuwImpl.h"
#include "../TFImpl/ShlNswImpl.h"
#include "../TFImpl/ShlNswNuwImpl.h"
#include "../TFImpl/SdivImpl.h"
#include "../TFImpl/SdivExactImpl.h"


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
    bool cmp1 = (orOne == concreteValue[0]);
    bool cmp2 = (orZero == neg);
    return cmp1 && cmp2;
}

extern "C" bool contains(APInt* abstractDomain1, APInt* abstractDomain2) {
    return ((abstractDomain1[0] | abstractDomain2[0]) ==abstractDomain2[0]) &&
        ((abstractDomain1[1] | abstractDomain2[1]) ==abstractDomain2[1]);
}

extern "C" void getTop(APInt* abstractDomain, APInt* result) {
    APInt zero = APInt::getZero(abstractDomain[0].getBitWidth());
    APInt allOnes = APInt::getAllOnes(abstractDomain[0].getBitWidth());
    result[0] = zero;
    result[1]= zero;
}

extern "C" void meet(APInt* abstractDomain1, APInt* abstractDomain2, APInt* result) {
    result[0] = abstractDomain1[0] | abstractDomain2[0];
    result[1] = abstractDomain1[1] | abstractDomain2[1];
}

extern "C" void join(APInt* abstractDomain1, APInt* abstractDomain2, APInt* result) {
    result[0] = abstractDomain1[0] & abstractDomain2[0];
    result[1] = abstractDomain1[1] & abstractDomain2[1];
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
    APInt tmp = args[0] + args[1];
    result[0] = tmp & args[1];
}

void dump(APInt* arg){
    KnownBits kb;
    kb.Zero=arg[0];
    kb.One=arg[1];
    kb.dump();
}


extern "C" void solution(APInt** combinedAbstractArg, APInt* autogen2){
    APInt* autogen0 = combinedAbstractArg[0];
    APInt* autogen1 = combinedAbstractArg[1];
    APInt autogen3[2];
    llvm::errs()<<"Input:\n";
    dump(autogen0);
    dump(autogen1);
    add_solution(autogen0,autogen1, autogen3);
    llvm::errs()<<"Add:\n";
    dump(autogen3);
    and_solution(autogen1,autogen3, autogen2);
    llvm::errs()<<"Result:\n";
    dump(autogen2);
}



extern "C" void baseTest(APInt** args, APInt* result) {
    getTop(args[0],result);
}
