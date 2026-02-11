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

extern "C" void concrete_op(APInt* combinedConcreteArg, APInt* autogen2){
    APInt autogen0 = combinedConcreteArg[0];
    APInt autogen1 = combinedConcreteArg[1];
    APInt autogen3 = autogen0+autogen1;
    APInt autogen4;
    if (autogen0.uge(autogen0.getBitWidth())) {
        autogen4 = APInt(autogen3.getBitWidth(), 0);
    } else {
        autogen4 = autogen3.shl(autogen0.getZExtValue());
    }
    autogen2[0] = autogen0|autogen4;
}

void dump(APInt* arg){
    KnownBits kb;
    kb.Zero=arg[0];
    kb.One=arg[1];
    kb.dump();
}



extern "C" void baseTest(APInt** args, APInt* result) {
    getTop(args[0],result);
}

extern "C" void partial_solution_0_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    APInt autogen3 = autogen0[1];
    APInt autogen4 = autogen1[1];
    APInt autogen5(autogen4.getBitWidth(),0);
    APInt autogen6(autogen4.getBitWidth(),0);
    unsigned autogen7_autocast = autogen4.getBitWidth();
    APInt autogen7(autogen4.getBitWidth(),autogen7_autocast);
    int autogen8 = autogen7.eq(autogen6);
    APInt autogen9 = APIntOps::smin(autogen4,autogen5);
    APInt autogen10 = autogen8 ? autogen5 : autogen3 ;
    APInt autogen11 = autogen9;
    if (autogen10.ule(autogen10.getBitWidth()))
        autogen11.setLowBits(autogen10.getZExtValue());
    else
        autogen11.setLowBits(autogen10.getBitWidth());
    APInt autogen12 = autogen11;
    if (autogen3.ule(autogen3.getBitWidth()))
        autogen12.clearHighBits(autogen3.getZExtValue());
    else
        autogen12.clearHighBits(autogen3.getBitWidth());
    APInt autogen13 = autogen9|autogen3;
    APInt autogen14 = autogen12^autogen11;
    autogen2[0] = autogen14;
    autogen2[1] = autogen13;
}

extern "C" void partial_solution_1_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    APInt autogen3 = autogen0[1];
    APInt autogen4 = autogen1[0];
    APInt autogen5 = autogen1[1];
    APInt autogen6(autogen5.getBitWidth(),1);
    APInt autogen7(autogen5.getBitWidth(),0);
    APInt autogen8(autogen5.getBitWidth(),1);
    int autogen9 = autogen7.ult(autogen8);
    APInt autogen10 = autogen9 ? autogen4 : autogen4 ;
    APInt autogen11;
    if (autogen3.isMinSignedValue() && autogen6 == -1) {
        autogen11 = APInt::getSignedMinValue(autogen3.getBitWidth());
    } else if (autogen6 == 0 && autogen3.isNonNegative()) {
        autogen11 = APInt::getAllOnes(autogen3.getBitWidth());
    } else if (autogen6 == 0 && autogen3.isNegative()) {
        autogen11 = APInt(autogen3.getBitWidth(), 1);
    } else {
        autogen11 = autogen3.sdiv(autogen6);
    }
    APInt autogen12 = autogen11;
    autogen12.setSignBit();
    APInt autogen13 = autogen5;
    if (autogen3.ule(autogen3.getBitWidth()))
        autogen13.setHighBits(autogen3.getZExtValue());
    else
        autogen13.setHighBits(autogen3.getBitWidth());
    APInt autogen14 = APIntOps::smax(autogen13,autogen12);
    APInt autogen15 = APIntOps::umax(autogen10,autogen10);
    autogen2[0] = autogen15;
    autogen2[1] = autogen14;
}

extern "C" void partial_solution_1_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
    APInt autogen3 = autogen1[1];
    APInt autogen4(autogen3.getBitWidth(),0);
    APInt autogen5(autogen3.getBitWidth(),1);
    unsigned autogen6_autocast = autogen3.getBitWidth();
    APInt autogen6(autogen3.getBitWidth(),autogen6_autocast);
    APInt autogen7 = autogen4;
    autogen7.setSignBit();
    int autogen8 = autogen7.ult(autogen3);
    int autogen9 = autogen6.eq(autogen5);
    int autogen10 = autogen8|autogen9;
    autogen2[0] = autogen9|autogen10;
}

extern "C" void partial_solution_2_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    APInt autogen3 = autogen0[0];
    APInt autogen4 = autogen0[1];
    APInt autogen5 = autogen1[0];
    APInt autogen6 = autogen1[1];
    APInt autogen7(autogen6.getBitWidth(),0);
    APInt autogen8(autogen6.getBitWidth(),1);
    unsigned autogen9_autocast = autogen3.countr_one();
    APInt autogen9(autogen3.getBitWidth(),autogen9_autocast);
    APInt autogen10 = autogen3+autogen8;
    APInt autogen11;
    if (autogen9.uge(autogen9.getBitWidth())) {
        autogen11 = APInt(autogen9.getBitWidth(), 0);
    } else {
        autogen11 = autogen9.lshr(autogen9.getZExtValue());
    }
    APInt autogen12 = autogen11&autogen10;
    APInt autogen13 = autogen5&autogen9;
    APInt autogen14 = autogen4;
    if (autogen8.ule(autogen8.getBitWidth()))
        autogen14.setLowBits(autogen8.getZExtValue());
    else
        autogen14.setLowBits(autogen8.getBitWidth());
    APInt autogen15 = autogen12;
    if (autogen5.ule(autogen5.getBitWidth()))
        autogen15.clearLowBits(autogen5.getZExtValue());
    else
        autogen15.clearLowBits(autogen5.getBitWidth());
    APInt autogen16;
    if (autogen7 == 0) {
        autogen16 = autogen13;
    } else {
        autogen16 = autogen13.srem(autogen7);
    }
    unsigned autogen17_autocast = autogen14.countr_zero();
    APInt autogen17(autogen14.getBitWidth(),autogen17_autocast);
    APInt autogen18 = autogen16;
    if (autogen15.ule(autogen15.getBitWidth()))
        autogen18.clearHighBits(autogen15.getZExtValue());
    else
        autogen18.clearHighBits(autogen15.getBitWidth());
    autogen2[0] = autogen18;
    autogen2[1] = autogen17;
}

extern "C" void partial_solution_3_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    APInt autogen3 = autogen0[0];
    APInt autogen4 = autogen0[1];
    APInt autogen5 = autogen1[0];
    APInt autogen6 = autogen1[1];
    APInt autogen7(autogen6.getBitWidth(),1);
    int autogen8 = autogen7.ule(autogen4);
    APInt autogen9;
    if (autogen5 == 0) {
        autogen9 = autogen5;
    } else {
        autogen9 = autogen5.urem(autogen5);
    }
    APInt autogen10 = autogen9|autogen9;
    APInt autogen11 = autogen5|autogen3;
    APInt autogen12 = autogen8 ? autogen3 : autogen6 ;
    APInt autogen13 = autogen11&autogen5;
    APInt autogen14 = autogen7;
    if (autogen4.ule(autogen4.getBitWidth()))
        autogen14.setHighBits(autogen4.getZExtValue());
    else
        autogen14.setHighBits(autogen4.getBitWidth());
    APInt autogen15 = autogen8 ? autogen10 : autogen13 ;
    APInt autogen16 = APIntOps::smin(autogen6,autogen12);
    APInt autogen17;
    if (autogen15.isMinSignedValue() && autogen14 == -1) {
        autogen17 = APInt::getSignedMinValue(autogen15.getBitWidth());
    } else if (autogen14 == 0 && autogen15.isNonNegative()) {
        autogen17 = APInt::getAllOnes(autogen15.getBitWidth());
    } else if (autogen14 == 0 && autogen15.isNegative()) {
        autogen17 = APInt(autogen15.getBitWidth(), 1);
    } else {
        autogen17 = autogen15.sdiv(autogen14);
    }
    autogen2[0] = autogen17;
    autogen2[1] = autogen16;
}

extern "C" void partial_solution_3_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
    APInt autogen3 = autogen0[0];
    APInt autogen4 = autogen0[1];
    APInt autogen5 = autogen1[1];
    APInt autogen6 = APInt::getAllOnes(autogen5.getBitWidth());
    APInt autogen7 = ~autogen3;
    APInt autogen8 = APIntOps::umax(autogen4,autogen3);
    APInt autogen9 = autogen8;
    if (autogen7.ule(autogen7.getBitWidth()))
        autogen9.clearLowBits(autogen7.getZExtValue());
    else
        autogen9.clearLowBits(autogen7.getBitWidth());
    autogen2[0] = autogen6.eq(autogen9);
}

extern "C" void partial_solution_4_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    APInt autogen3 = autogen0[0];
    APInt autogen4 = autogen0[1];
    APInt autogen5 = autogen1[0];
    APInt autogen6 = autogen1[1];
    APInt autogen7(autogen6.getBitWidth(),1);
    APInt autogen8 = autogen4;
    if (autogen7.ule(autogen7.getBitWidth()))
        autogen8.clearLowBits(autogen7.getZExtValue());
    else
        autogen8.clearLowBits(autogen7.getBitWidth());
    APInt autogen9 = autogen8&autogen4;
    unsigned autogen10_autocast = autogen9.countl_zero();
    APInt autogen10(autogen9.getBitWidth(),autogen10_autocast);
    APInt autogen11 = autogen4&autogen5;
    APInt autogen12 = autogen10|autogen11;
    APInt autogen13 = autogen9;
    if (autogen3.ule(autogen3.getBitWidth()))
        autogen13.clearLowBits(autogen3.getZExtValue());
    else
        autogen13.clearLowBits(autogen3.getBitWidth());
    APInt autogen14;
    if (autogen12 == 0) {
        autogen14 = APInt::getAllOnes(autogen9.getBitWidth());
    } else {
        autogen14 = autogen9.udiv(autogen12);
    }
    autogen2[0] = autogen14;
    autogen2[1] = autogen13;
}

extern "C" void partial_solution_5_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    APInt autogen3 = autogen0[0];
    APInt autogen4 = autogen0[1];
    APInt autogen5 = autogen1[0];
    APInt autogen6 = autogen1[1];
    APInt autogen7(autogen6.getBitWidth(),1);
    APInt autogen8 = APIntOps::umax(autogen3,autogen3);
    APInt autogen9 = autogen7&autogen8;
    APInt autogen10 = APIntOps::smax(autogen6,autogen7);
    APInt autogen11 = autogen9&autogen5;
    APInt autogen12 = autogen3;
    if (autogen10.ule(autogen10.getBitWidth()))
        autogen12.setHighBits(autogen10.getZExtValue());
    else
        autogen12.setHighBits(autogen10.getBitWidth());
    unsigned autogen13_autocast = autogen10.countl_one();
    APInt autogen13(autogen10.getBitWidth(),autogen13_autocast);
    APInt autogen14 = autogen5&autogen13;
    APInt autogen15 = APIntOps::umax(autogen14,autogen11);
    APInt autogen16 = APIntOps::smax(autogen12,autogen4);
    APInt autogen17 = APIntOps::umin(autogen15,autogen7);
    autogen2[0] = autogen17;
    autogen2[1] = autogen16;
}

extern "C" void partial_solution_6_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    APInt autogen3 = autogen0[1];
    APInt autogen4 = autogen1[0];
    APInt autogen5 = autogen1[1];
    APInt autogen6(autogen5.getBitWidth(),1);
    APInt autogen7 = APInt::getAllOnes(autogen5.getBitWidth());
    APInt autogen8 = autogen3;
    if (autogen6.ule(autogen6.getBitWidth()))
        autogen8.clearLowBits(autogen6.getZExtValue());
    else
        autogen8.clearLowBits(autogen6.getBitWidth());
    APInt autogen9 = autogen7;
    if (autogen8.ule(autogen8.getBitWidth()))
        autogen9.clearLowBits(autogen8.getZExtValue());
    else
        autogen9.clearLowBits(autogen8.getBitWidth());
    unsigned autogen10_autocast = autogen5.countl_one();
    APInt autogen10(autogen5.getBitWidth(),autogen10_autocast);
    APInt autogen11 = autogen4&autogen10;
    APInt autogen12;
    if (autogen5 == 0) {
        autogen12 = autogen5;
    } else {
        autogen12 = autogen5.srem(autogen5);
    }
    unsigned autogen13_autocast = autogen11.countr_one();
    APInt autogen13(autogen11.getBitWidth(),autogen13_autocast);
    APInt autogen14 = autogen11^autogen5;
    APInt autogen15;
    if (autogen14 == 0) {
        autogen15 = APInt::getAllOnes(autogen9.getBitWidth());
    } else {
        autogen15 = autogen9.udiv(autogen14);
    }
    APInt autogen16;
    if (autogen12.isMinSignedValue() && autogen15 == -1) {
        autogen16 = APInt::getSignedMinValue(autogen12.getBitWidth());
    } else if (autogen15 == 0 && autogen12.isNonNegative()) {
        autogen16 = APInt::getAllOnes(autogen12.getBitWidth());
    } else if (autogen15 == 0 && autogen12.isNegative()) {
        autogen16 = APInt(autogen12.getBitWidth(), 1);
    } else {
        autogen16 = autogen12.sdiv(autogen15);
    }
    APInt autogen17 = APIntOps::umin(autogen13,autogen14);
    autogen2[0] = autogen17;
    autogen2[1] = autogen16;
}

extern "C" void partial_solution_7_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    APInt autogen3 = autogen0[1];
    APInt autogen4 = autogen1[1];
    APInt autogen5(autogen4.getBitWidth(),1);
    APInt autogen6 = APIntOps::umax(autogen5,autogen4);
    unsigned autogen7_autocast = autogen6.countl_zero();
    APInt autogen7(autogen6.getBitWidth(),autogen7_autocast);
    APInt autogen8;
    if (autogen6 == 0) {
        autogen8 = autogen4;
    } else {
        autogen8 = autogen4.srem(autogen6);
    }
    APInt autogen9;
    if (autogen3 == 0) {
        autogen9 = APInt::getAllOnes(autogen7.getBitWidth());
    } else {
        autogen9 = autogen7.udiv(autogen3);
    }
    APInt autogen10;
    if (autogen9 == 0) {
        autogen10 = APInt::getAllOnes(autogen8.getBitWidth());
    } else {
        autogen10 = autogen8.udiv(autogen9);
    }
    APInt autogen11;
    if (autogen8.isMinSignedValue() && autogen5 == -1) {
        autogen11 = APInt::getSignedMinValue(autogen8.getBitWidth());
    } else if (autogen5 == 0 && autogen8.isNonNegative()) {
        autogen11 = APInt::getAllOnes(autogen8.getBitWidth());
    } else if (autogen5 == 0 && autogen8.isNegative()) {
        autogen11 = APInt(autogen8.getBitWidth(), 1);
    } else {
        autogen11 = autogen8.sdiv(autogen5);
    }
    autogen2[0] = autogen11;
    autogen2[1] = autogen10;
}

extern "C" void partial_solution_8_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    APInt autogen3 = autogen0[0];
    APInt autogen4 = autogen0[1];
    APInt autogen5 = autogen1[0];
    APInt autogen6 = autogen1[1];
    APInt autogen7(autogen6.getBitWidth(),0);
    APInt autogen8(autogen6.getBitWidth(),1);
    APInt autogen9 = APInt::getAllOnes(autogen6.getBitWidth());
    APInt autogen10 = autogen8;
    if (autogen4.ule(autogen4.getBitWidth()))
        autogen10.clearHighBits(autogen4.getZExtValue());
    else
        autogen10.clearHighBits(autogen4.getBitWidth());
    APInt autogen11 = autogen9*autogen10;
    APInt autogen12;
    if (autogen7.uge(autogen7.getBitWidth()) && autogen3.isSignBitSet()) {
        autogen12 = APInt::getAllOnes(autogen3.getBitWidth());
    } else if (autogen7.uge(autogen7.getBitWidth()) && autogen3.isSignBitClear()) {
        autogen12 = APInt(autogen3.getBitWidth(), 0);
    } else {
        autogen12 = autogen3.ashr(autogen7.getZExtValue());
    }
    unsigned autogen13_autocast = autogen6.countr_one();
    APInt autogen13(autogen6.getBitWidth(),autogen13_autocast);
    APInt autogen14 = autogen9;
    if (autogen13.ule(autogen13.getBitWidth()))
        autogen14.clearHighBits(autogen13.getZExtValue());
    else
        autogen14.clearHighBits(autogen13.getBitWidth());
    APInt autogen15 = autogen10-autogen13;
    APInt autogen16 = autogen14^autogen8;
    APInt autogen17 = autogen6&autogen5;
    APInt autogen18;
    if (autogen16.uge(autogen16.getBitWidth()) && autogen10.isSignBitSet()) {
        autogen18 = APInt::getAllOnes(autogen10.getBitWidth());
    } else if (autogen16.uge(autogen16.getBitWidth()) && autogen10.isSignBitClear()) {
        autogen18 = APInt(autogen10.getBitWidth(), 0);
    } else {
        autogen18 = autogen10.ashr(autogen16.getZExtValue());
    }
    APInt autogen19 = APIntOps::umin(autogen5,autogen12);
    APInt autogen20;
    if (autogen11 == 0) {
        autogen20 = APInt::getAllOnes(autogen19.getBitWidth());
    } else {
        autogen20 = autogen19.udiv(autogen11);
    }
    APInt autogen21 = autogen18;
    if (autogen15.ule(autogen15.getBitWidth()))
        autogen21.clearLowBits(autogen15.getZExtValue());
    else
        autogen21.clearLowBits(autogen15.getBitWidth());
    APInt autogen22 = APIntOps::smin(autogen17,autogen20);
    autogen2[0] = autogen22;
    autogen2[1] = autogen21;
}

extern "C" void partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    partial_solution_0_body(autogen0,autogen1, autogen2);
}

extern "C" void partial_solution_1(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    APInt autogen3[2];
    getTop(autogen0, autogen3);
    APInt autogen4 = autogen3[0];
    APInt autogen5 = autogen3[1];
    APInt autogen6[2];
    partial_solution_1_body(autogen0,autogen1, autogen6);
    APInt autogen7 = autogen6[0];
    APInt autogen8 = autogen6[1];
    int autogen9;
    partial_solution_1_cond(autogen0,autogen1,&autogen9);
    APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
    APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
    autogen2[0] = autogen10;
    autogen2[1] = autogen11;
}

extern "C" void partial_solution_2(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    partial_solution_2_body(autogen0,autogen1, autogen2);
}

extern "C" void partial_solution_3(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    APInt autogen3[2];
    getTop(autogen0, autogen3);
    APInt autogen4 = autogen3[0];
    APInt autogen5 = autogen3[1];
    APInt autogen6[2];
    partial_solution_3_body(autogen0,autogen1, autogen6);
    APInt autogen7 = autogen6[0];
    APInt autogen8 = autogen6[1];
    int autogen9;
    partial_solution_3_cond(autogen0,autogen1,&autogen9);
    APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
    APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
    autogen2[0] = autogen10;
    autogen2[1] = autogen11;
}

extern "C" void partial_solution_4(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    partial_solution_4_body(autogen0,autogen1, autogen2);
}

extern "C" void partial_solution_5(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    partial_solution_5_body(autogen0,autogen1, autogen2);
}

extern "C" void partial_solution_6(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    partial_solution_6_body(autogen0,autogen1, autogen2);
}

extern "C" void partial_solution_7(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    partial_solution_7_body(autogen0,autogen1, autogen2);
}

extern "C" void partial_solution_8(APInt* autogen0, APInt* autogen1, APInt* autogen2){
    partial_solution_8_body(autogen0,autogen1, autogen2);
}

extern "C" void solution(APInt** combinedAbstractArg, APInt* autogen2){
    APInt* autogen0 = combinedAbstractArg[0];
    APInt* autogen1 = combinedAbstractArg[1];
    APInt autogen3[2];
    partial_solution_0(autogen0,autogen1, autogen3);
    APInt autogen4[2];
    partial_solution_1(autogen0,autogen1, autogen4);
    APInt autogen5[2];
    partial_solution_2(autogen0,autogen1, autogen5);
    APInt autogen6[2];
    partial_solution_3(autogen0,autogen1, autogen6);
    APInt autogen7[2];
    partial_solution_4(autogen0,autogen1, autogen7);
    APInt autogen8[2];
    partial_solution_5(autogen0,autogen1, autogen8);
    APInt autogen9[2];
    partial_solution_6(autogen0,autogen1, autogen9);
    APInt autogen10[2];
    partial_solution_7(autogen0,autogen1, autogen10);
    APInt autogen11[2];
    partial_solution_8(autogen0,autogen1, autogen11);
    APInt autogen12[2];
    meet(autogen3,autogen4, autogen12);
    APInt autogen13[2];
    meet(autogen12,autogen5, autogen13);
    APInt autogen14[2];
    meet(autogen13,autogen6, autogen14);
    APInt autogen15[2];
    meet(autogen14,autogen7, autogen15);
    APInt autogen16[2];
    meet(autogen15,autogen8, autogen16);
    APInt autogen17[2];
    meet(autogen16,autogen9, autogen17);
    APInt autogen18[2];
    meet(autogen17,autogen10, autogen18);
    meet(autogen18,autogen11, autogen2);
}
