extern "C" void lshr_exact_partial_solution_0_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),0);
	APInt autogen5(autogen3.getBitWidth(),1);
	APInt autogen6 = APInt::getAllOnes(autogen3.getBitWidth());
	APInt autogen7 = autogen6*autogen3;
	APInt autogen8 = APIntOps::umax(autogen5,autogen3);
	unsigned autogen9_autocast = autogen8.countl_zero();
	APInt autogen9(autogen8.getBitWidth(),autogen9_autocast);
	APInt autogen10;
	if (autogen4 == 0) {
		autogen10 = APInt(autogen7.getBitWidth(), -1);
	} else {
		autogen10 = autogen7.udiv(autogen4);
	}
	APInt autogen11 = autogen2;
	if (autogen9.ule(autogen9.getBitWidth()))
		autogen11.clearHighBits(autogen9.getZExtValue());
	else
		autogen11.clearHighBits(autogen9.getBitWidth());
	unsigned autogen12_autocast = autogen3.countl_zero();
	APInt autogen12(autogen3.getBitWidth(),autogen12_autocast);
	APInt autogen13 = autogen10&autogen11;
	APInt autogen14 = autogen10;
	if (autogen12.ule(autogen12.getBitWidth()))
		autogen14.clearLowBits(autogen12.getZExtValue());
	else
		autogen14.clearLowBits(autogen12.getBitWidth());
	autogen1[0] = autogen14;
	autogen1[1] = autogen13;
}

extern "C" void lshr_exact_partial_solution_1_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	APInt autogen6 = APInt::getAllOnes(autogen4.getBitWidth());
	unsigned autogen7_autocast = autogen4.getBitWidth();
	APInt autogen7(autogen4.getBitWidth(),autogen7_autocast);
	int autogen8 = autogen5.ult(autogen4);
	APInt autogen9 = autogen4|autogen2;
	APInt autogen10 = autogen8 ? autogen9 : autogen6 ;
	APInt autogen11 = ~autogen10;
	APInt autogen12 = autogen4;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen12.clearHighBits(autogen7.getZExtValue());
	else
		autogen12.clearHighBits(autogen7.getBitWidth());
	APInt autogen13 = autogen3-autogen12;
	APInt autogen14 = autogen9^autogen11;
	autogen1[0] = autogen14;
	autogen1[1] = autogen13;
}

extern "C" void lshr_exact_partial_solution_1_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[1];
	APInt autogen4 = autogen1[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	APInt autogen6 = autogen3;
	if (autogen5.ule(autogen5.getBitWidth()))
		autogen6.setLowBits(autogen5.getZExtValue());
	else
		autogen6.setLowBits(autogen5.getBitWidth());
	autogen2[0] = autogen6.eq(autogen3);
}

extern "C" void lshr_exact_partial_solution_2_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6 = APInt::getAllOnes(autogen4.getBitWidth());
	unsigned autogen7_autocast = autogen2.countl_one();
	APInt autogen7(autogen2.getBitWidth(),autogen7_autocast);
	APInt autogen8;
	if (autogen5 == 0) {
		autogen8 = autogen5;
	} else {
		autogen8 = autogen5.srem(autogen5);
	}
	APInt autogen9;
	if (autogen7.uge(autogen7.getBitWidth()) && autogen3.isSignBitSet()) {
		autogen9 = APInt(autogen3.getBitWidth(), -1);
	} else if (autogen7.uge(autogen7.getBitWidth()) && autogen3.isSignBitClear()) {
		autogen9 = APInt(autogen3.getBitWidth(), 0);
	} else {
		autogen9 = autogen3.ashr(autogen7.getZExtValue());
	}
	APInt autogen10 = APIntOps::smin(autogen6,autogen5);
	unsigned autogen11_autocast = autogen2.countl_one();
	APInt autogen11(autogen2.getBitWidth(),autogen11_autocast);
	APInt autogen12;
	if (autogen10 == 0) {
		autogen12 = APInt(autogen9.getBitWidth(), -1);
	} else {
		autogen12 = autogen9.udiv(autogen10);
	}
	APInt autogen13 = autogen8;
	if (autogen11.ule(autogen11.getBitWidth()))
		autogen13.setHighBits(autogen11.getZExtValue());
	else
		autogen13.setHighBits(autogen11.getBitWidth());
	autogen1[0] = autogen13;
	autogen1[1] = autogen12;
}

extern "C" void lshr_exact_partial_solution_3_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen7(autogen4.getBitWidth(),0);
	APInt autogen8(autogen4.getBitWidth(),1);
	unsigned autogen9_autocast = autogen4.getBitWidth();
	APInt autogen9(autogen4.getBitWidth(),autogen9_autocast);
	unsigned autogen10_autocast = autogen2.countr_one();
	APInt autogen10(autogen2.getBitWidth(),autogen10_autocast);
	APInt autogen11;
	if (autogen8.uge(autogen8.getBitWidth())) {
		autogen11 = APInt(autogen4.getBitWidth(), 0);
	} else {
		autogen11 = autogen4.shl(autogen8.getZExtValue());
	}
	APInt autogen12;
	if (autogen9.uge(autogen9.getBitWidth())) {
		autogen12 = APInt(autogen3.getBitWidth(), 0);
	} else {
		autogen12 = autogen3.shl(autogen9.getZExtValue());
	}
	int autogen13 = autogen6.ule(autogen5);
	APInt autogen14 = autogen11-autogen4;
	unsigned autogen15_autocast = autogen12.countl_zero();
	APInt autogen15(autogen12.getBitWidth(),autogen15_autocast);
	APInt autogen16 = autogen3;
	if (autogen10.ule(autogen10.getBitWidth()))
		autogen16.clearHighBits(autogen10.getZExtValue());
	else
		autogen16.clearHighBits(autogen10.getBitWidth());
	unsigned autogen17_autocast = autogen14.countl_zero();
	APInt autogen17(autogen14.getBitWidth(),autogen17_autocast);
	APInt autogen18 = autogen13 ? autogen15 : autogen7 ;
	APInt autogen19 = autogen18+autogen17;
	APInt autogen20;
	if (autogen19.uge(autogen19.getBitWidth())) {
		autogen20 = APInt(autogen3.getBitWidth(), 0);
	} else {
		autogen20 = autogen3.shl(autogen19.getZExtValue());
	}
	APInt autogen21 = autogen13 ? autogen16 : autogen20 ;
	APInt autogen22 = autogen21;
	if (autogen8.ule(autogen8.getBitWidth()))
		autogen22.clearHighBits(autogen8.getZExtValue());
	else
		autogen22.clearHighBits(autogen8.getBitWidth());
	autogen1[0] = autogen22;
	autogen1[1] = autogen21;
}

extern "C" void lshr_exact_partial_solution_4_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	APInt autogen6 = APIntOps::umin(autogen2,autogen4);
	unsigned autogen7_autocast = autogen3.countl_zero();
	APInt autogen7(autogen3.getBitWidth(),autogen7_autocast);
	APInt autogen8 = autogen4^autogen5;
	APInt autogen9 = APIntOps::umax(autogen5,autogen8);
	unsigned autogen10_autocast = autogen6.countr_one();
	APInt autogen10(autogen6.getBitWidth(),autogen10_autocast);
	unsigned autogen11_autocast = autogen4.countr_one();
	APInt autogen11(autogen4.getBitWidth(),autogen11_autocast);
	APInt autogen12;
	if (autogen3.isMinSignedValue() && autogen9 == -1) {
		autogen12 = APInt::getSignedMinValue(autogen3.getBitWidth());
	} else if (autogen9 == 0 && autogen3.isNonNegative()) {
		autogen12 = APInt(autogen3.getBitWidth(), -1);
	} else if (autogen9 == 0 && autogen3.isNegative()) {
		autogen12 = APInt(autogen3.getBitWidth(), 1);
	} else {
		autogen12 = autogen3.sdiv(autogen9);
	}
	APInt autogen13 = autogen10+autogen7;
	APInt autogen14 = autogen12;
	if (autogen13.ule(autogen13.getBitWidth()))
		autogen14.clearHighBits(autogen13.getZExtValue());
	else
		autogen14.clearHighBits(autogen13.getBitWidth());
	APInt autogen15;
	if (autogen11.uge(autogen11.getBitWidth())) {
		autogen15 = APInt(autogen2.getBitWidth(), 0);
	} else {
		autogen15 = autogen2.lshr(autogen11.getZExtValue());
	}
	autogen1[0] = autogen15;
	autogen1[1] = autogen14;
}

extern "C" void lshr_exact_partial_solution_4_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen1[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen7;
	if (autogen5 == 0) {
		autogen7 = autogen3;
	} else {
		autogen7 = autogen3.urem(autogen5);
	}
	APInt autogen8 = autogen7;
	autogen8.setSignBit();
	autogen2[0] = autogen6.ule(autogen8);
}

extern "C" void lshr_exact_partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	lshr_exact_partial_solution_0_body(autogen0,autogen1, autogen2);
}

extern "C" void lshr_exact_partial_solution_1(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	lshr_exact_partial_solution_1_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	lshr_exact_partial_solution_1_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void lshr_exact_partial_solution_2(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	lshr_exact_partial_solution_2_body(autogen0,autogen1, autogen2);
}

extern "C" void lshr_exact_partial_solution_3(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	lshr_exact_partial_solution_3_body(autogen0,autogen1, autogen2);
}

extern "C" void lshr_exact_partial_solution_4(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	lshr_exact_partial_solution_4_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	lshr_exact_partial_solution_4_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void lshr_exact_solution(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	lshr_exact_partial_solution_0(autogen0,autogen1, autogen3);
	APInt autogen4[2];
	lshr_exact_partial_solution_1(autogen0,autogen1, autogen4);
	APInt autogen5[2];
	lshr_exact_partial_solution_2(autogen0,autogen1, autogen5);
	APInt autogen6[2];
	lshr_exact_partial_solution_3(autogen0,autogen1, autogen6);
	APInt autogen7[2];
	lshr_exact_partial_solution_4(autogen0,autogen1, autogen7);
	APInt autogen8[2];
	tf_meet(autogen3,autogen4, autogen8);
	APInt autogen9[2];
	tf_meet(autogen8,autogen5, autogen9);
	APInt autogen10[2];
	tf_meet(autogen9,autogen6, autogen10);
	tf_meet(autogen10,autogen7, autogen2);
}

