extern "C" void sdiv_exact_partial_solution_0_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen8(autogen4.getBitWidth(),0);
	APInt autogen9(autogen4.getBitWidth(),1);
	unsigned autogen10_autocast = autogen4.getBitWidth();
	APInt autogen10(autogen4.getBitWidth(),autogen10_autocast);
	int autogen11 = autogen6.ult(autogen7);
	APInt autogen12 = autogen11 ? autogen8 : autogen9 ;
	APInt autogen13;
	if (autogen5.isMinSignedValue() && autogen3 == -1) {
		autogen13 = APInt::getSignedMinValue(autogen5.getBitWidth());
	} else if (autogen3 == 0 && autogen5.isNonNegative()) {
		autogen13 = APInt(autogen5.getBitWidth(), -1);
	} else if (autogen3 == 0 && autogen5.isNegative()) {
		autogen13 = APInt(autogen5.getBitWidth(), 1);
	} else {
		autogen13 = autogen5.sdiv(autogen3);
	}
	APInt autogen14 = autogen5;
	if (autogen10.ule(autogen10.getBitWidth()))
		autogen14.setHighBits(autogen10.getZExtValue());
	else
		autogen14.setHighBits(autogen10.getBitWidth());
	APInt autogen15 = autogen12-autogen12;
	APInt autogen16;
	if (autogen15.uge(autogen15.getBitWidth())) {
		autogen16 = APInt(autogen13.getBitWidth(), 0);
	} else {
		autogen16 = autogen13.shl(autogen15.getZExtValue());
	}
	APInt autogen17 = autogen13^autogen14;
	unsigned autogen18_autocast = autogen2.countr_one();
	APInt autogen18(autogen2.getBitWidth(),autogen18_autocast);
	int autogen19 = autogen15.ule(autogen18);
	APInt autogen20 = autogen17|autogen17;
	APInt autogen21 = autogen19 ? autogen16 : autogen20 ;
	autogen1[0] = autogen21;
	autogen1[1] = autogen20;
}

extern "C" void sdiv_exact_partial_solution_0_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	autogen2[0] = autogen5.eq(autogen3);
}

extern "C" void sdiv_exact_partial_solution_1_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7;
	if (autogen3 == 0) {
		autogen7 = APInt(autogen2.getBitWidth(), -1);
	} else {
		autogen7 = autogen2.udiv(autogen3);
	}
	APInt autogen8;
	if (autogen4 == 0) {
		autogen8 = autogen3;
	} else {
		autogen8 = autogen3.urem(autogen4);
	}
	APInt autogen9 = APIntOps::smin(autogen5,autogen7);
	APInt autogen10 = APIntOps::smax(autogen9,autogen9);
	APInt autogen11 = ~autogen10;
	APInt autogen12 = autogen6|autogen7;
	int autogen13 = autogen7.eq(autogen8);
	APInt autogen14 = autogen13 ? autogen12 : autogen11 ;
	APInt autogen15;
	if (autogen14 == 0) {
		autogen15 = APInt(autogen5.getBitWidth(), -1);
	} else {
		autogen15 = autogen5.udiv(autogen14);
	}
	autogen1[0] = autogen15;
	autogen1[1] = autogen14;
}

extern "C" void sdiv_exact_partial_solution_1_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen1[1];
	APInt autogen4(autogen3.getBitWidth(),0);
	APInt autogen5(autogen3.getBitWidth(),1);
	unsigned autogen6_autocast = autogen3.getBitWidth();
	APInt autogen6(autogen3.getBitWidth(),autogen6_autocast);
	int autogen7 = autogen6.ule(autogen5);
	int autogen8 = autogen3.ult(autogen4);
	int autogen9 = autogen7^autogen8;
	int autogen10 = autogen8|autogen7;
	int autogen11 = autogen7^autogen10;
	autogen2[0] = autogen9^autogen11;
}

extern "C" void sdiv_exact_partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sdiv_exact_partial_solution_0_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sdiv_exact_partial_solution_0_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sdiv_exact_partial_solution_1(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sdiv_exact_partial_solution_1_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sdiv_exact_partial_solution_1_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sdiv_exact_solution(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	sdiv_exact_partial_solution_0(autogen0,autogen1, autogen3);
	APInt autogen4[2];
	sdiv_exact_partial_solution_1(autogen0,autogen1, autogen4);
	tf_meet(autogen3,autogen4, autogen2);
}

