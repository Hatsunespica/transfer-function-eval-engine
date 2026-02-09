extern "C" void lshr_partial_solution_0_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),0);
	APInt autogen5(autogen3.getBitWidth(),1);
	APInt autogen6 = APIntOps::umin(autogen5,autogen5);
	APInt autogen7 = autogen3;
	if (autogen5.ule(autogen5.getBitWidth()))
		autogen7.clearLowBits(autogen5.getZExtValue());
	else
		autogen7.clearLowBits(autogen5.getBitWidth());
	unsigned autogen8_autocast = autogen7.countr_zero();
	APInt autogen8(autogen7.getBitWidth(),autogen8_autocast);
	unsigned autogen9_autocast = autogen2.countl_one();
	APInt autogen9(autogen2.getBitWidth(),autogen9_autocast);
	APInt autogen10 = APIntOps::umin(autogen9,autogen8);
	APInt autogen11 = autogen3|autogen10;
	APInt autogen12 = autogen5-autogen6;
	APInt autogen13 = autogen12;
	autogen13.clearSignBit();
	APInt autogen14 = autogen4;
	if (autogen11.ule(autogen11.getBitWidth()))
		autogen14.setHighBits(autogen11.getZExtValue());
	else
		autogen14.setHighBits(autogen11.getBitWidth());
	autogen1[0] = autogen14;
	autogen1[1] = autogen13;
}

extern "C" void lshr_partial_solution_1_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),1);
	unsigned autogen5_autocast = autogen3.getBitWidth();
	APInt autogen5(autogen3.getBitWidth(),autogen5_autocast);
	APInt autogen6 = autogen4;
	if (autogen5.ule(autogen5.getBitWidth()))
		autogen6.clearLowBits(autogen5.getZExtValue());
	else
		autogen6.clearLowBits(autogen5.getBitWidth());
	APInt autogen7 = ~autogen6;
	APInt autogen8 = ~autogen2;
	APInt autogen9;
	if (autogen3.uge(autogen3.getBitWidth())) {
		autogen9 = APInt(autogen8.getBitWidth(), 0);
	} else {
		autogen9 = autogen8.lshr(autogen3.getZExtValue());
	}
	unsigned autogen10_autocast = autogen7.countl_zero();
	APInt autogen10(autogen7.getBitWidth(),autogen10_autocast);
	APInt autogen11;
	if (autogen9.uge(autogen9.getBitWidth())) {
		autogen11 = APInt(autogen7.getBitWidth(), 0);
	} else {
		autogen11 = autogen7.shl(autogen9.getZExtValue());
	}
	autogen1[0] = autogen11;
	autogen1[1] = autogen10;
}

extern "C" void lshr_partial_solution_2_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6 = APIntOps::umin(autogen2,autogen4);
	APInt autogen7;
	if (autogen4.uge(autogen4.getBitWidth())) {
		autogen7 = APInt(autogen4.getBitWidth(), 0);
	} else {
		autogen7 = autogen4.shl(autogen4.getZExtValue());
	}
	APInt autogen8 = autogen5;
	if (autogen4.ule(autogen4.getBitWidth()))
		autogen8.setHighBits(autogen4.getZExtValue());
	else
		autogen8.setHighBits(autogen4.getBitWidth());
	APInt autogen9 = APIntOps::smin(autogen7,autogen6);
	APInt autogen10;
	if (autogen9.uge(autogen9.getBitWidth())) {
		autogen10 = APInt(autogen9.getBitWidth(), 0);
	} else {
		autogen10 = autogen9.lshr(autogen9.getZExtValue());
	}
	APInt autogen11 = autogen10;
	if (autogen3.ule(autogen3.getBitWidth()))
		autogen11.clearHighBits(autogen3.getZExtValue());
	else
		autogen11.clearHighBits(autogen3.getBitWidth());
	APInt autogen12 = APIntOps::umax(autogen2,autogen8);
	autogen1[0] = autogen12;
	autogen1[1] = autogen11;
}

extern "C" void lshr_partial_solution_2_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen1[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7 = autogen3;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen7.setHighBits(autogen6.getZExtValue());
	else
		autogen7.setHighBits(autogen6.getBitWidth());
	int autogen8 = autogen7.eq(autogen5);
	int autogen9 = autogen5.ule(autogen6);
	int autogen10 = autogen8&autogen9;
	autogen2[0] = autogen10|autogen8;
}

extern "C" void lshr_partial_solution_3_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6 = APIntOps::umin(autogen3,autogen2);
	APInt autogen7 = autogen5;
	if (autogen4.ule(autogen4.getBitWidth()))
		autogen7.setHighBits(autogen4.getZExtValue());
	else
		autogen7.setHighBits(autogen4.getBitWidth());
	unsigned autogen8_autocast = autogen6.countl_one();
	APInt autogen8(autogen6.getBitWidth(),autogen8_autocast);
	unsigned autogen9_autocast = autogen8.countl_one();
	APInt autogen9(autogen8.getBitWidth(),autogen9_autocast);
	APInt autogen10 = APIntOps::umax(autogen4,autogen7);
	autogen1[0] = autogen10;
	autogen1[1] = autogen9;
}

extern "C" void lshr_partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	lshr_partial_solution_0_body(autogen0,autogen1, autogen2);
}

extern "C" void lshr_partial_solution_1(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	lshr_partial_solution_1_body(autogen0,autogen1, autogen2);
}

extern "C" void lshr_partial_solution_2(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	lshr_partial_solution_2_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	lshr_partial_solution_2_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void lshr_partial_solution_3(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	lshr_partial_solution_3_body(autogen0,autogen1, autogen2);
}

extern "C" void lshr_solution(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	lshr_partial_solution_0(autogen0,autogen1, autogen3);
	APInt autogen4[2];
	lshr_partial_solution_1(autogen0,autogen1, autogen4);
	APInt autogen5[2];
	lshr_partial_solution_2(autogen0,autogen1, autogen5);
	APInt autogen6[2];
	lshr_partial_solution_3(autogen0,autogen1, autogen6);
	APInt autogen7[2];
	tf_meet(autogen3,autogen4, autogen7);
	APInt autogen8[2];
	tf_meet(autogen7,autogen5, autogen8);
	tf_meet(autogen8,autogen6, autogen2);
}

