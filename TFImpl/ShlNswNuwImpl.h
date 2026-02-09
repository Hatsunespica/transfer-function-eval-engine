extern "C" void shl_nsw_nuw_partial_solution_0_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6 = APInt::getAllOnes(autogen4.getBitWidth());
	int autogen7 = autogen5.eq(autogen6);
	APInt autogen8 = autogen7 ? autogen2 : autogen4 ;
	APInt autogen9 = APIntOps::smin(autogen3,autogen5);
	unsigned autogen10_autocast = autogen2.countr_one();
	APInt autogen10(autogen2.getBitWidth(),autogen10_autocast);
	APInt autogen11 = autogen8;
	if (autogen8.ule(autogen8.getBitWidth()))
		autogen11.setLowBits(autogen8.getZExtValue());
	else
		autogen11.setLowBits(autogen8.getBitWidth());
	APInt autogen12;
	if (autogen8.uge(autogen8.getBitWidth())) {
		autogen12 = APInt(autogen9.getBitWidth(), 0);
	} else {
		autogen12 = autogen9.lshr(autogen8.getZExtValue());
	}
	APInt autogen13 = autogen11;
	if (autogen10.ule(autogen10.getBitWidth()))
		autogen13.setLowBits(autogen10.getZExtValue());
	else
		autogen13.setLowBits(autogen10.getBitWidth());
	autogen1[0] = autogen13;
	autogen1[1] = autogen12;
}

extern "C" void shl_nsw_nuw_partial_solution_1_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	unsigned autogen7_autocast = autogen4.getBitWidth();
	APInt autogen7(autogen4.getBitWidth(),autogen7_autocast);
	unsigned autogen8_autocast = autogen7.countl_zero();
	APInt autogen8(autogen7.getBitWidth(),autogen8_autocast);
	APInt autogen9 = APIntOps::smin(autogen4,autogen2);
	APInt autogen10 = autogen5;
	if (autogen4.ule(autogen4.getBitWidth()))
		autogen10.setLowBits(autogen4.getZExtValue());
	else
		autogen10.setLowBits(autogen4.getBitWidth());
	unsigned autogen11_autocast = autogen4.countl_one();
	APInt autogen11(autogen4.getBitWidth(),autogen11_autocast);
	APInt autogen12 = autogen10;
	autogen12.clearSignBit();
	APInt autogen13 = autogen8;
	if (autogen3.ule(autogen3.getBitWidth()))
		autogen13.setLowBits(autogen3.getZExtValue());
	else
		autogen13.setLowBits(autogen3.getBitWidth());
	APInt autogen14 = APIntOps::umin(autogen6,autogen9);
	APInt autogen15 = autogen11;
	if (autogen13.ule(autogen13.getBitWidth()))
		autogen15.clearLowBits(autogen13.getZExtValue());
	else
		autogen15.clearLowBits(autogen13.getBitWidth());
	APInt autogen16 = autogen12;
	if (autogen14.ule(autogen14.getBitWidth()))
		autogen16.setHighBits(autogen14.getZExtValue());
	else
		autogen16.setHighBits(autogen14.getBitWidth());
	autogen1[0] = autogen16;
	autogen1[1] = autogen15;
}

extern "C" void shl_nsw_nuw_partial_solution_2_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen6(autogen4.getBitWidth(),0);
	unsigned autogen7_autocast = autogen4.getBitWidth();
	APInt autogen7(autogen4.getBitWidth(),autogen7_autocast);
	APInt autogen8 = autogen6;
	autogen8.setSignBit();
	int autogen9 = autogen5.ule(autogen3);
	APInt autogen10 = autogen9 ? autogen2 : autogen8 ;
	APInt autogen11 = autogen8;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen11.clearHighBits(autogen7.getZExtValue());
	else
		autogen11.clearHighBits(autogen7.getBitWidth());
	APInt autogen12 = autogen6;
	if (autogen4.ule(autogen4.getBitWidth()))
		autogen12.setLowBits(autogen4.getZExtValue());
	else
		autogen12.setLowBits(autogen4.getBitWidth());
	APInt autogen13 = autogen11&autogen7;
	APInt autogen14 = autogen2;
	if (autogen13.ule(autogen13.getBitWidth()))
		autogen14.setHighBits(autogen13.getZExtValue());
	else
		autogen14.setHighBits(autogen13.getBitWidth());
	APInt autogen15 = autogen14&autogen10;
	APInt autogen16 = autogen12;
	if (autogen11.ule(autogen11.getBitWidth()))
		autogen16.clearHighBits(autogen11.getZExtValue());
	else
		autogen16.clearHighBits(autogen11.getBitWidth());
	autogen1[0] = autogen16;
	autogen1[1] = autogen15;
}

extern "C" void shl_nsw_nuw_partial_solution_3_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),0);
	APInt autogen5 = APInt::getAllOnes(autogen3.getBitWidth());
	APInt autogen6(autogen3.getBitWidth(),0);
	APInt autogen7(autogen3.getBitWidth(),1);
	unsigned autogen8_autocast = autogen3.getBitWidth();
	APInt autogen8(autogen3.getBitWidth(),autogen8_autocast);
	unsigned autogen9_autocast = autogen8.countr_zero();
	APInt autogen9(autogen8.getBitWidth(),autogen9_autocast);
	int autogen10 = autogen6.ult(autogen7);
	APInt autogen11 = autogen2;
	autogen11.setSignBit();
	APInt autogen12 = APIntOps::smax(autogen2,autogen5);
	APInt autogen13 = autogen6;
	autogen13.setSignBit();
	APInt autogen14 = autogen13;
	if (autogen12.ule(autogen12.getBitWidth()))
		autogen14.setHighBits(autogen12.getZExtValue());
	else
		autogen14.setHighBits(autogen12.getBitWidth());
	APInt autogen15 = autogen11;
	if (autogen3.ule(autogen3.getBitWidth()))
		autogen15.clearHighBits(autogen3.getZExtValue());
	else
		autogen15.clearHighBits(autogen3.getBitWidth());
	APInt autogen16 = autogen10 ? autogen4 : autogen9 ;
	APInt autogen17;
	if (autogen15.uge(autogen15.getBitWidth())) {
		autogen17 = APInt(autogen14.getBitWidth(), 0);
	} else {
		autogen17 = autogen14.shl(autogen15.getZExtValue());
	}
	autogen1[0] = autogen17;
	autogen1[1] = autogen16;
}

extern "C" void shl_nsw_nuw_partial_solution_4_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),0);
	APInt autogen5(autogen3.getBitWidth(),1);
	APInt autogen6(autogen3.getBitWidth(),0);
	APInt autogen7(autogen3.getBitWidth(),1);
	unsigned autogen8_autocast = autogen3.getBitWidth();
	APInt autogen8(autogen3.getBitWidth(),autogen8_autocast);
	APInt autogen9 = autogen8;
	autogen9.setSignBit();
	APInt autogen10;
	if (autogen3.uge(autogen3.getBitWidth())) {
		autogen10 = APInt(autogen2.getBitWidth(), 0);
	} else {
		autogen10 = autogen2.shl(autogen3.getZExtValue());
	}
	APInt autogen11 = autogen9;
	autogen11.clearSignBit();
	APInt autogen12 = autogen4;
	if (autogen5.ule(autogen5.getBitWidth()))
		autogen12.setHighBits(autogen5.getZExtValue());
	else
		autogen12.setHighBits(autogen5.getBitWidth());
	APInt autogen13 = autogen6;
	if (autogen3.ule(autogen3.getBitWidth()))
		autogen13.setLowBits(autogen3.getZExtValue());
	else
		autogen13.setLowBits(autogen3.getBitWidth());
	APInt autogen14 = autogen12-autogen7;
	APInt autogen15;
	if (autogen11.uge(autogen11.getBitWidth())) {
		autogen15 = APInt(autogen10.getBitWidth(), 0);
	} else {
		autogen15 = autogen10.lshr(autogen11.getZExtValue());
	}
	APInt autogen16 = APIntOps::smin(autogen14,autogen13);
	autogen1[0] = autogen16;
	autogen1[1] = autogen15;
}

extern "C" void shl_nsw_nuw_partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nsw_nuw_partial_solution_0_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nsw_nuw_partial_solution_1(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nsw_nuw_partial_solution_1_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nsw_nuw_partial_solution_2(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nsw_nuw_partial_solution_2_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nsw_nuw_partial_solution_3(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nsw_nuw_partial_solution_3_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nsw_nuw_partial_solution_4(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nsw_nuw_partial_solution_4_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nsw_nuw_solution(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	shl_nsw_nuw_partial_solution_0(autogen0,autogen1, autogen3);
	APInt autogen4[2];
	shl_nsw_nuw_partial_solution_1(autogen0,autogen1, autogen4);
	APInt autogen5[2];
	shl_nsw_nuw_partial_solution_2(autogen0,autogen1, autogen5);
	APInt autogen6[2];
	shl_nsw_nuw_partial_solution_3(autogen0,autogen1, autogen6);
	APInt autogen7[2];
	shl_nsw_nuw_partial_solution_4(autogen0,autogen1, autogen7);
	APInt autogen8[2];
	tf_meet(autogen3,autogen4, autogen8);
	APInt autogen9[2];
	tf_meet(autogen8,autogen5, autogen9);
	APInt autogen10[2];
	tf_meet(autogen9,autogen6, autogen10);
	tf_meet(autogen10,autogen7, autogen2);
}

