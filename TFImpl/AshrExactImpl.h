extern "C" void ashr_exact_partial_solution_0_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	unsigned autogen6_autocast = autogen2.countr_zero();
	APInt autogen6(autogen2.getBitWidth(),autogen6_autocast);
	APInt autogen7;
	if (autogen6.uge(autogen6.getBitWidth()) && autogen4.isSignBitSet()) {
		autogen7 = APInt(autogen4.getBitWidth(), -1);
	} else if (autogen6.uge(autogen6.getBitWidth()) && autogen4.isSignBitClear()) {
		autogen7 = APInt(autogen4.getBitWidth(), 0);
	} else {
		autogen7 = autogen4.ashr(autogen6.getZExtValue());
	}
	APInt autogen8;
	if (autogen5 == 0) {
		autogen8 = autogen7;
	} else {
		autogen8 = autogen7.urem(autogen5);
	}
	APInt autogen9 = autogen7|autogen8;
	unsigned autogen10_autocast = autogen2.countl_one();
	APInt autogen10(autogen2.getBitWidth(),autogen10_autocast);
	unsigned autogen11_autocast = autogen3.countr_one();
	APInt autogen11(autogen3.getBitWidth(),autogen11_autocast);
	APInt autogen12 = autogen8;
	if (autogen10.ule(autogen10.getBitWidth()))
		autogen12.setHighBits(autogen10.getZExtValue());
	else
		autogen12.setHighBits(autogen10.getBitWidth());
	APInt autogen13 = autogen9;
	if (autogen11.ule(autogen11.getBitWidth()))
		autogen13.clearHighBits(autogen11.getZExtValue());
	else
		autogen13.clearHighBits(autogen11.getBitWidth());
	autogen1[0] = autogen13;
	autogen1[1] = autogen12;
}

extern "C" void ashr_exact_partial_solution_1_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	unsigned autogen7_autocast = autogen5.getBitWidth();
	APInt autogen7(autogen5.getBitWidth(),autogen7_autocast);
	unsigned autogen8_autocast = autogen4.countr_one();
	APInt autogen8(autogen4.getBitWidth(),autogen8_autocast);
	APInt autogen9;
	if (autogen8.uge(autogen8.getBitWidth())) {
		autogen9 = APInt(autogen5.getBitWidth(), 0);
	} else {
		autogen9 = autogen5.shl(autogen8.getZExtValue());
	}
	unsigned autogen10_autocast = autogen9.countl_zero();
	APInt autogen10(autogen9.getBitWidth(),autogen10_autocast);
	APInt autogen11 = autogen3;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen11.setLowBits(autogen7.getZExtValue());
	else
		autogen11.setLowBits(autogen7.getBitWidth());
	APInt autogen12;
	if (autogen9 == 0) {
		autogen12 = autogen3;
	} else {
		autogen12 = autogen3.urem(autogen9);
	}
	APInt autogen13 = autogen6;
	if (autogen10.ule(autogen10.getBitWidth()))
		autogen13.clearHighBits(autogen10.getZExtValue());
	else
		autogen13.clearHighBits(autogen10.getBitWidth());
	APInt autogen14 = APIntOps::smax(autogen13,autogen5);
	APInt autogen15 = APIntOps::umax(autogen12,autogen3);
	APInt autogen16 = APIntOps::umax(autogen9,autogen6);
	int autogen17 = autogen14.ult(autogen15);
	APInt autogen18 = autogen12*autogen16;
	APInt autogen19 = autogen17 ? autogen2 : autogen11 ;
	autogen1[0] = autogen19;
	autogen1[1] = autogen18;
}

extern "C" void ashr_exact_partial_solution_1_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[1];
	APInt autogen4 = autogen1[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	APInt autogen6 = APIntOps::umin(autogen3,autogen3);
	APInt autogen7 = autogen5|autogen6;
	APInt autogen8 = autogen6-autogen4;
	autogen2[0] = autogen7.eq(autogen8);
}

extern "C" void ashr_exact_partial_solution_2_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),0);
	APInt autogen5 = APInt::getAllOnes(autogen3.getBitWidth());
	APInt autogen6(autogen3.getBitWidth(),0);
	APInt autogen7(autogen3.getBitWidth(),1);
	unsigned autogen8_autocast = autogen3.getBitWidth();
	APInt autogen8(autogen3.getBitWidth(),autogen8_autocast);
	int autogen9 = autogen6.ult(autogen8);
	unsigned autogen10_autocast = autogen2.countl_one();
	APInt autogen10(autogen2.getBitWidth(),autogen10_autocast);
	APInt autogen11;
	if (autogen3 == 0) {
		autogen11 = autogen3;
	} else {
		autogen11 = autogen3.srem(autogen3);
	}
	APInt autogen12 = autogen9 ? autogen7 : autogen8 ;
	APInt autogen13 = autogen5+autogen3;
	APInt autogen14 = autogen11;
	if (autogen10.ule(autogen10.getBitWidth()))
		autogen14.setHighBits(autogen10.getZExtValue());
	else
		autogen14.setHighBits(autogen10.getBitWidth());
	APInt autogen15 = APIntOps::smax(autogen3,autogen2);
	APInt autogen16;
	if (autogen12.uge(autogen12.getBitWidth())) {
		autogen16 = APInt(autogen14.getBitWidth(), 0);
	} else {
		autogen16 = autogen14.lshr(autogen12.getZExtValue());
	}
	APInt autogen17;
	if (autogen4 == 0) {
		autogen17 = autogen13;
	} else {
		autogen17 = autogen13.srem(autogen4);
	}
	APInt autogen18;
	if (autogen17 == 0) {
		autogen18 = autogen4;
	} else {
		autogen18 = autogen4.urem(autogen17);
	}
	APInt autogen19 = autogen15*autogen18;
	APInt autogen20;
	if (autogen14 == 0) {
		autogen20 = autogen19;
	} else {
		autogen20 = autogen19.urem(autogen14);
	}
	APInt autogen21;
	if (autogen7.uge(autogen7.getBitWidth())) {
		autogen21 = APInt(autogen16.getBitWidth(), 0);
	} else {
		autogen21 = autogen16.shl(autogen7.getZExtValue());
	}
	autogen1[0] = autogen21;
	autogen1[1] = autogen20;
}

extern "C" void ashr_exact_partial_solution_3_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[1];
	unsigned autogen4_autocast = autogen3.getBitWidth();
	APInt autogen4(autogen3.getBitWidth(),autogen4_autocast);
	APInt autogen5;
	if (autogen4.uge(autogen4.getBitWidth()) && autogen2.isSignBitSet()) {
		autogen5 = APInt(autogen2.getBitWidth(), -1);
	} else if (autogen4.uge(autogen4.getBitWidth()) && autogen2.isSignBitClear()) {
		autogen5 = APInt(autogen2.getBitWidth(), 0);
	} else {
		autogen5 = autogen2.ashr(autogen4.getZExtValue());
	}
	APInt autogen6 = ~autogen3;
	unsigned autogen7_autocast = autogen3.countl_zero();
	APInt autogen7(autogen3.getBitWidth(),autogen7_autocast);
	APInt autogen8 = autogen3&autogen6;
	APInt autogen9;
	if (autogen7.uge(autogen7.getBitWidth())) {
		autogen9 = APInt(autogen5.getBitWidth(), 0);
	} else {
		autogen9 = autogen5.shl(autogen7.getZExtValue());
	}
	autogen1[0] = autogen9;
	autogen1[1] = autogen8;
}

extern "C" void ashr_exact_partial_solution_4_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[1];
	APInt autogen4 = autogen3;
	autogen4.clearSignBit();
	APInt autogen5 = autogen4*autogen3;
	APInt autogen6 = autogen2|autogen5;
	APInt autogen7 = APIntOps::umin(autogen6,autogen4);
	APInt autogen8;
	if (autogen7 == 0) {
		autogen8 = autogen5;
	} else {
		autogen8 = autogen5.urem(autogen7);
	}
	APInt autogen9;
	if (autogen6 == 0) {
		autogen9 = autogen8;
	} else {
		autogen9 = autogen8.urem(autogen6);
	}
	autogen1[0] = autogen9;
	autogen1[1] = autogen8;
}

extern "C" void ashr_exact_partial_solution_5_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6 = APInt::getAllOnes(autogen4.getBitWidth());
	unsigned autogen7_autocast = autogen4.getBitWidth();
	APInt autogen7(autogen4.getBitWidth(),autogen7_autocast);
	APInt autogen8 = autogen2|autogen4;
	APInt autogen9 = autogen5;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen9.setHighBits(autogen7.getZExtValue());
	else
		autogen9.setHighBits(autogen7.getBitWidth());
	int autogen10 = autogen4.eq(autogen5);
	APInt autogen11 = autogen9&autogen3;
	APInt autogen12 = autogen10 ? autogen8 : autogen6 ;
	autogen1[0] = autogen12;
	autogen1[1] = autogen11;
}

extern "C" void ashr_exact_partial_solution_5_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen1[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen6(autogen4.getBitWidth(),0);
	unsigned autogen7_autocast = autogen4.getBitWidth();
	APInt autogen7(autogen4.getBitWidth(),autogen7_autocast);
	int autogen8 = autogen5.eq(autogen3);
	int autogen9 = autogen7.ult(autogen6);
	int autogen10 = autogen8&autogen9;
	autogen2[0] = autogen8^autogen10;
}

extern "C" void ashr_exact_partial_solution_6_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen6;
	if (autogen4 == 0) {
		autogen6 = autogen3;
	} else {
		autogen6 = autogen3.urem(autogen4);
	}
	APInt autogen7 = ~autogen3;
	unsigned autogen8_autocast = autogen2.countl_zero();
	APInt autogen8(autogen2.getBitWidth(),autogen8_autocast);
	int autogen9 = autogen5.ule(autogen7);
	APInt autogen10;
	if (autogen8.uge(autogen8.getBitWidth())) {
		autogen10 = APInt(autogen4.getBitWidth(), 0);
	} else {
		autogen10 = autogen4.shl(autogen8.getZExtValue());
	}
	unsigned autogen11_autocast = autogen6.countl_zero();
	APInt autogen11(autogen6.getBitWidth(),autogen11_autocast);
	APInt autogen12 = autogen10;
	if (autogen11.ule(autogen11.getBitWidth()))
		autogen12.clearLowBits(autogen11.getZExtValue());
	else
		autogen12.clearLowBits(autogen11.getBitWidth());
	APInt autogen13 = autogen9 ? autogen3 : autogen12 ;
	autogen1[0] = autogen13;
	autogen1[1] = autogen12;
}

extern "C" void ashr_exact_partial_solution_7_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	unsigned autogen6_autocast = autogen3.countr_zero();
	APInt autogen6(autogen3.getBitWidth(),autogen6_autocast);
	APInt autogen7 = autogen5;
	autogen7.setSignBit();
	APInt autogen8 = autogen7&autogen2;
	APInt autogen9 = autogen4;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen9.clearLowBits(autogen6.getZExtValue());
	else
		autogen9.clearLowBits(autogen6.getBitWidth());
	APInt autogen10 = APIntOps::umin(autogen9,autogen4);
	APInt autogen11 = autogen10|autogen8;
	autogen1[0] = autogen11;
	autogen1[1] = autogen10;
}

extern "C" void ashr_exact_partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	ashr_exact_partial_solution_0_body(autogen0,autogen1, autogen2);
}

extern "C" void ashr_exact_partial_solution_1(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	ashr_exact_partial_solution_1_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	ashr_exact_partial_solution_1_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void ashr_exact_partial_solution_2(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	ashr_exact_partial_solution_2_body(autogen0,autogen1, autogen2);
}

extern "C" void ashr_exact_partial_solution_3(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	ashr_exact_partial_solution_3_body(autogen0,autogen1, autogen2);
}

extern "C" void ashr_exact_partial_solution_4(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	ashr_exact_partial_solution_4_body(autogen0,autogen1, autogen2);
}

extern "C" void ashr_exact_partial_solution_5(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	ashr_exact_partial_solution_5_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	ashr_exact_partial_solution_5_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void ashr_exact_partial_solution_6(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	ashr_exact_partial_solution_6_body(autogen0,autogen1, autogen2);
}

extern "C" void ashr_exact_partial_solution_7(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	ashr_exact_partial_solution_7_body(autogen0,autogen1, autogen2);
}

extern "C" void ashr_exact_solution(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	ashr_exact_partial_solution_0(autogen0,autogen1, autogen3);
	APInt autogen4[2];
	ashr_exact_partial_solution_1(autogen0,autogen1, autogen4);
	APInt autogen5[2];
	ashr_exact_partial_solution_2(autogen0,autogen1, autogen5);
	APInt autogen6[2];
	ashr_exact_partial_solution_3(autogen0,autogen1, autogen6);
	APInt autogen7[2];
	ashr_exact_partial_solution_4(autogen0,autogen1, autogen7);
	APInt autogen8[2];
	ashr_exact_partial_solution_5(autogen0,autogen1, autogen8);
	APInt autogen9[2];
	ashr_exact_partial_solution_6(autogen0,autogen1, autogen9);
	APInt autogen10[2];
	ashr_exact_partial_solution_7(autogen0,autogen1, autogen10);
	APInt autogen11[2];
	tf_meet(autogen3,autogen4, autogen11);
	APInt autogen12[2];
	tf_meet(autogen11,autogen5, autogen12);
	APInt autogen13[2];
	tf_meet(autogen12,autogen6, autogen13);
	APInt autogen14[2];
	tf_meet(autogen13,autogen7, autogen14);
	APInt autogen15[2];
	tf_meet(autogen14,autogen8, autogen15);
	APInt autogen16[2];
	tf_meet(autogen15,autogen9, autogen16);
	tf_meet(autogen16,autogen10, autogen2);
}

