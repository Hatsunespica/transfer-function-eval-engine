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


extern "C" void partial_solution_0_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3 = autogen0[1];
	APInt autogen4 = autogen1[0];
	APInt autogen5 = autogen1[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	APInt autogen7 = APInt::getAllOnes(autogen5.getBitWidth());
	APInt autogen8(autogen5.getBitWidth(),0);
	unsigned autogen9_autocast = autogen5.getBitWidth();
	APInt autogen9(autogen5.getBitWidth(),autogen9_autocast);
	int autogen10 = autogen9.ult(autogen8);
	APInt autogen11 = autogen10 ? autogen7 : autogen4 ;
	APInt autogen12 = autogen11&autogen11;
	APInt autogen13 = autogen11;
	if (autogen4.ule(autogen4.getBitWidth()))
		autogen13.clearLowBits(autogen4.getZExtValue());
	else
		autogen13.clearLowBits(autogen4.getBitWidth());
	APInt autogen14 = autogen3&autogen6;
	APInt autogen15;
	if (autogen7.uge(autogen7.getBitWidth()) && autogen13.isSignBitSet()) {
		autogen15 = APInt(autogen13.getBitWidth(), -1);
	} else if (autogen7.uge(autogen7.getBitWidth()) && autogen13.isSignBitClear()) {
		autogen15 = APInt(autogen13.getBitWidth(), 0);
	} else {
		autogen15 = autogen13.ashr(autogen7.getZExtValue());
	}
	APInt autogen16 = autogen12;
	if (autogen14.ule(autogen14.getBitWidth()))
		autogen16.setLowBits(autogen14.getZExtValue());
	else
		autogen16.setLowBits(autogen14.getBitWidth());
	autogen2[0] = autogen16;
	autogen2[1] = autogen15;
}

extern "C" void partial_solution_1_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = autogen1[0];
	APInt autogen6 = autogen1[1];
	APInt autogen7(autogen6.getBitWidth(),1);
	APInt autogen8 = autogen5|autogen7;
	unsigned autogen9_autocast = autogen3.countr_one();
	APInt autogen9(autogen3.getBitWidth(),autogen9_autocast);
	APInt autogen10 = autogen8;
	if (autogen9.ule(autogen9.getBitWidth()))
		autogen10.setLowBits(autogen9.getZExtValue());
	else
		autogen10.setLowBits(autogen9.getBitWidth());
	APInt autogen11 = autogen10+autogen3;
	APInt autogen12 = autogen4;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen12.clearLowBits(autogen7.getZExtValue());
	else
		autogen12.clearLowBits(autogen7.getBitWidth());
	unsigned autogen13_autocast = autogen8.countr_zero();
	APInt autogen13(autogen8.getBitWidth(),autogen13_autocast);
	APInt autogen14 = autogen12&autogen11;
	autogen2[0] = autogen14;
	autogen2[1] = autogen13;
}

extern "C" void partial_solution_2_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = autogen1[0];
	APInt autogen6 = autogen1[1];
	APInt autogen7(autogen6.getBitWidth(),1);
	APInt autogen8 = autogen6&autogen4;
	APInt autogen9 = APIntOps::umin(autogen7,autogen6);
	APInt autogen10;
	if (autogen7.uge(autogen7.getBitWidth())) {
		autogen10 = APInt(autogen8.getBitWidth(), 0);
	} else {
		autogen10 = autogen8.shl(autogen7.getZExtValue());
	}
	APInt autogen11 = autogen3|autogen6;
	APInt autogen12 = autogen3&autogen10;
	APInt autogen13 = autogen9+autogen9;
	unsigned autogen14_autocast = autogen13.countl_one();
	APInt autogen14(autogen13.getBitWidth(),autogen14_autocast);
	APInt autogen15 = autogen5;
	if (autogen3.ule(autogen3.getBitWidth()))
		autogen15.clearLowBits(autogen3.getZExtValue());
	else
		autogen15.clearLowBits(autogen3.getBitWidth());
	APInt autogen16;
	if (autogen11.uge(autogen11.getBitWidth()) && autogen14.isSignBitSet()) {
		autogen16 = APInt(autogen14.getBitWidth(), -1);
	} else if (autogen11.uge(autogen11.getBitWidth()) && autogen14.isSignBitClear()) {
		autogen16 = APInt(autogen14.getBitWidth(), 0);
	} else {
		autogen16 = autogen14.ashr(autogen11.getZExtValue());
	}
	APInt autogen17 = autogen12|autogen15;
	autogen2[0] = autogen17;
	autogen2[1] = autogen16;
}

extern "C" void partial_solution_3_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[0];
	APInt autogen5 = autogen1[1];
	APInt autogen6(autogen5.getBitWidth(),0);
	APInt autogen7 = APInt::getAllOnes(autogen5.getBitWidth());
	unsigned autogen8_autocast = autogen3.countr_one();
	APInt autogen8(autogen3.getBitWidth(),autogen8_autocast);
	APInt autogen9;
	if (autogen7 == 0) {
		autogen9 = APInt(autogen6.getBitWidth(), -1);
	} else {
		autogen9 = autogen6.udiv(autogen7);
	}
	APInt autogen10 = autogen5&autogen8;
	APInt autogen11 = autogen9|autogen4;
	autogen2[0] = autogen11;
	autogen2[1] = autogen10;
}

extern "C" void partial_solution_4_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = autogen1[0];
	APInt autogen6 = autogen1[1];
	APInt autogen7(autogen6.getBitWidth(),0);
	APInt autogen8(autogen6.getBitWidth(),1);
	APInt autogen9 = autogen5|autogen3;
	APInt autogen10;
	if (autogen8 == 0) {
		autogen10 = autogen5;
	} else {
		autogen10 = autogen5.srem(autogen8);
	}
	unsigned autogen11_autocast = autogen10.countl_one();
	APInt autogen11(autogen10.getBitWidth(),autogen11_autocast);
	unsigned autogen12_autocast = autogen9.countr_one();
	APInt autogen12(autogen9.getBitWidth(),autogen12_autocast);
	APInt autogen13 = autogen11+autogen12;
	APInt autogen14 = autogen11;
	if (autogen10.ule(autogen10.getBitWidth()))
		autogen14.setHighBits(autogen10.getZExtValue());
	else
		autogen14.setHighBits(autogen10.getBitWidth());
	APInt autogen15 = autogen7;
	if (autogen5.ule(autogen5.getBitWidth()))
		autogen15.setLowBits(autogen5.getZExtValue());
	else
		autogen15.setLowBits(autogen5.getBitWidth());
	APInt autogen16;
	if (autogen13.uge(autogen13.getBitWidth())) {
		autogen16 = APInt(autogen8.getBitWidth(), 0);
	} else {
		autogen16 = autogen8.shl(autogen13.getZExtValue());
	}
	APInt autogen17 = autogen14*autogen15;
	APInt autogen18 = autogen16&autogen4;
	autogen2[0] = autogen18;
	autogen2[1] = autogen17;
}

extern "C" void partial_solution_5_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[0];
	APInt autogen5 = autogen1[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	unsigned autogen7_autocast = autogen3.countr_zero();
	APInt autogen7(autogen3.getBitWidth(),autogen7_autocast);
	APInt autogen8 = APIntOps::smin(autogen4,autogen5);
	APInt autogen9 = autogen5&autogen6;
	APInt autogen10 = autogen9&autogen3;
	APInt autogen11;
	if (autogen7.uge(autogen7.getBitWidth()) && autogen10.isSignBitSet()) {
		autogen11 = APInt(autogen10.getBitWidth(), -1);
	} else if (autogen7.uge(autogen7.getBitWidth()) && autogen10.isSignBitClear()) {
		autogen11 = APInt(autogen10.getBitWidth(), 0);
	} else {
		autogen11 = autogen10.ashr(autogen7.getZExtValue());
	}
	APInt autogen12 = APIntOps::smax(autogen8,autogen4);
	autogen2[0] = autogen12;
	autogen2[1] = autogen11;
}

extern "C" void partial_solution_6_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = autogen1[1];
	APInt autogen6(autogen5.getBitWidth(),0);
	APInt autogen7(autogen5.getBitWidth(),1);
	APInt autogen8 = APInt::getAllOnes(autogen5.getBitWidth());
	APInt autogen9 = APIntOps::umin(autogen4,autogen3);
	APInt autogen10;
	if (autogen5.uge(autogen5.getBitWidth()) && autogen9.isSignBitSet()) {
		autogen10 = APInt(autogen9.getBitWidth(), -1);
	} else if (autogen5.uge(autogen5.getBitWidth()) && autogen9.isSignBitClear()) {
		autogen10 = APInt(autogen9.getBitWidth(), 0);
	} else {
		autogen10 = autogen9.ashr(autogen5.getZExtValue());
	}
	APInt autogen11 = APIntOps::umax(autogen9,autogen4);
	APInt autogen12;
	if (autogen8.isMinSignedValue() && autogen8 == -1) {
		autogen12 = APInt::getSignedMinValue(autogen8.getBitWidth());
	} else if (autogen8 == 0 && autogen8.isNonNegative()) {
		autogen12 = APInt(autogen8.getBitWidth(), -1);
	} else if (autogen8 == 0 && autogen8.isNegative()) {
		autogen12 = APInt(autogen8.getBitWidth(), 1);
	} else {
		autogen12 = autogen8.sdiv(autogen8);
	}
	APInt autogen13 = autogen10;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen13.setHighBits(autogen7.getZExtValue());
	else
		autogen13.setHighBits(autogen7.getBitWidth());
	APInt autogen14 = APIntOps::smax(autogen12,autogen13);
	APInt autogen15;
	if (autogen14 == 0) {
		autogen15 = APInt(autogen5.getBitWidth(), -1);
	} else {
		autogen15 = autogen5.udiv(autogen14);
	}
	APInt autogen16 = autogen10;
	if (autogen11.ule(autogen11.getBitWidth()))
		autogen16.setLowBits(autogen11.getZExtValue());
	else
		autogen16.setLowBits(autogen11.getBitWidth());
	APInt autogen17 = autogen6;
	if (autogen16.ule(autogen16.getBitWidth()))
		autogen17.setHighBits(autogen16.getZExtValue());
	else
		autogen17.setHighBits(autogen16.getBitWidth());
	APInt autogen18;
	if (autogen16 == 0) {
		autogen18 = autogen11;
	} else {
		autogen18 = autogen11.srem(autogen16);
	}
	APInt autogen19 = autogen15;
	if (autogen17.ule(autogen17.getBitWidth()))
		autogen19.clearLowBits(autogen17.getZExtValue());
	else
		autogen19.clearLowBits(autogen17.getBitWidth());
	APInt autogen20;
	if (autogen19 == 0) {
		autogen20 = autogen18;
	} else {
		autogen20 = autogen18.urem(autogen19);
	}
	autogen2[0] = autogen20;
	autogen2[1] = autogen19;
}

extern "C" void partial_solution_6_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = autogen1[1];
	APInt autogen6 = APInt::getAllOnes(autogen5.getBitWidth());
	APInt autogen7 = autogen4+autogen6;
	autogen2[0] = autogen3.eq(autogen7);
}

extern "C" void partial_solution_7_body(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[0];
	APInt autogen5 = autogen1[1];
	APInt autogen6 = APInt::getAllOnes(autogen5.getBitWidth());
	APInt autogen7 = autogen3&autogen5;
	unsigned autogen8_autocast = autogen4.countr_one();
	APInt autogen8(autogen4.getBitWidth(),autogen8_autocast);
	APInt autogen9 = APIntOps::smin(autogen4,autogen4);
	unsigned autogen10_autocast = autogen7.countr_one();
	APInt autogen10(autogen7.getBitWidth(),autogen10_autocast);
	APInt autogen11 = APIntOps::smax(autogen6,autogen10);
	APInt autogen12;
	if (autogen8.uge(autogen8.getBitWidth()) && autogen11.isSignBitSet()) {
		autogen12 = APInt(autogen11.getBitWidth(), -1);
	} else if (autogen8.uge(autogen8.getBitWidth()) && autogen11.isSignBitClear()) {
		autogen12 = APInt(autogen11.getBitWidth(), 0);
	} else {
		autogen12 = autogen11.ashr(autogen8.getZExtValue());
	}
	APInt autogen13 = APIntOps::umax(autogen9,autogen4);
	autogen2[0] = autogen13;
	autogen2[1] = autogen12;
}

extern "C" void partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	partial_solution_0_body(autogen0,autogen1, autogen2);
}

extern "C" void partial_solution_1(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	partial_solution_1_body(autogen0,autogen1, autogen2);
}

extern "C" void partial_solution_2(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	partial_solution_2_body(autogen0,autogen1, autogen2);
}

extern "C" void partial_solution_3(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	partial_solution_3_body(autogen0,autogen1, autogen2);
}

extern "C" void partial_solution_4(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	partial_solution_4_body(autogen0,autogen1, autogen2);
}

extern "C" void partial_solution_5(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	partial_solution_5_body(autogen0,autogen1, autogen2);
}

extern "C" void partial_solution_6(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	partial_solution_6_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	partial_solution_6_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void partial_solution_7(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	partial_solution_7_body(autogen0,autogen1, autogen2);
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
	meet(autogen3,autogen4, autogen11);
	APInt autogen12[2];
	meet(autogen11,autogen5, autogen12);
	APInt autogen13[2];
	meet(autogen12,autogen6, autogen13);
	APInt autogen14[2];
	meet(autogen13,autogen7, autogen14);
	APInt autogen15[2];
	meet(autogen14,autogen8, autogen15);
	APInt autogen16[2];
	meet(autogen15,autogen9, autogen16);
	meet(autogen16,autogen10, autogen2);
}



extern "C" void baseTest(APInt** args, APInt* result) {
    getTop(args[0],result);
}
