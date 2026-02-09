extern "C" void mul_partial_solution_0_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	unsigned autogen7_autocast = autogen2.countr_one();
	APInt autogen7(autogen2.getBitWidth(),autogen7_autocast);
	APInt autogen8 = autogen5&autogen3;
	APInt autogen9 = autogen4&autogen6;
	APInt autogen10 = autogen9;
	autogen10.clearSignBit();
	unsigned autogen11_autocast = autogen8.countr_zero();
	APInt autogen11(autogen8.getBitWidth(),autogen11_autocast);
	APInt autogen12;
	if (autogen11.uge(autogen11.getBitWidth())) {
		autogen12 = APInt(autogen6.getBitWidth(), 0);
	} else {
		autogen12 = autogen6.lshr(autogen11.getZExtValue());
	}
	APInt autogen13 = autogen10;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen13.setLowBits(autogen7.getZExtValue());
	else
		autogen13.setLowBits(autogen7.getBitWidth());
	autogen1[0] = autogen13;
	autogen1[1] = autogen12;
}

extern "C" void mul_partial_solution_1_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	unsigned autogen7_autocast = autogen2.countr_one();
	APInt autogen7(autogen2.getBitWidth(),autogen7_autocast);
	APInt autogen8;
	if (autogen5 == 0) {
		autogen8 = autogen4;
	} else {
		autogen8 = autogen4.srem(autogen5);
	}
	APInt autogen9 = autogen4^autogen8;
	APInt autogen10 = autogen3;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen10.setHighBits(autogen7.getZExtValue());
	else
		autogen10.setHighBits(autogen7.getBitWidth());
	unsigned autogen11_autocast = autogen10.countr_one();
	APInt autogen11(autogen10.getBitWidth(),autogen11_autocast);
	APInt autogen12 = autogen9;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen12.clearHighBits(autogen6.getZExtValue());
	else
		autogen12.clearHighBits(autogen6.getBitWidth());
	APInt autogen13 = autogen5;
	if (autogen11.ule(autogen11.getBitWidth()))
		autogen13.setLowBits(autogen11.getZExtValue());
	else
		autogen13.setLowBits(autogen11.getBitWidth());
	autogen1[0] = autogen13;
	autogen1[1] = autogen12;
}

extern "C" void mul_partial_solution_2_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	unsigned autogen7_autocast = autogen2.countl_one();
	APInt autogen7(autogen2.getBitWidth(),autogen7_autocast);
	APInt autogen8 = autogen6+autogen4;
	APInt autogen9 = ~autogen3;
	APInt autogen10;
	if (autogen8 == 0) {
		autogen10 = autogen5;
	} else {
		autogen10 = autogen5.srem(autogen8);
	}
	APInt autogen11 = autogen3&autogen10;
	unsigned autogen12_autocast = autogen9.countr_zero();
	APInt autogen12(autogen9.getBitWidth(),autogen12_autocast);
	APInt autogen13 = autogen2;
	if (autogen12.ule(autogen12.getBitWidth()))
		autogen13.clearHighBits(autogen12.getZExtValue());
	else
		autogen13.clearHighBits(autogen12.getBitWidth());
	APInt autogen14 = autogen11&autogen3;
	APInt autogen15 = autogen13&autogen6;
	APInt autogen16;
	if (autogen7.uge(autogen7.getBitWidth())) {
		autogen16 = APInt(autogen14.getBitWidth(), 0);
	} else {
		autogen16 = autogen14.shl(autogen7.getZExtValue());
	}
	APInt autogen17;
	if (autogen12.uge(autogen12.getBitWidth())) {
		autogen17 = APInt(autogen15.getBitWidth(), 0);
	} else {
		autogen17 = autogen15.shl(autogen12.getZExtValue());
	}
	autogen1[0] = autogen17;
	autogen1[1] = autogen16;
}

extern "C" void mul_partial_solution_3_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	unsigned autogen7_autocast = autogen5.countr_zero();
	APInt autogen7(autogen5.getBitWidth(),autogen7_autocast);
	APInt autogen8;
	if (autogen7.uge(autogen7.getBitWidth())) {
		autogen8 = APInt(autogen6.getBitWidth(), 0);
	} else {
		autogen8 = autogen6.lshr(autogen7.getZExtValue());
	}
	unsigned autogen9_autocast = autogen2.countr_one();
	APInt autogen9(autogen2.getBitWidth(),autogen9_autocast);
	APInt autogen10;
	if (autogen9.uge(autogen9.getBitWidth())) {
		autogen10 = APInt(autogen8.getBitWidth(), 0);
	} else {
		autogen10 = autogen8.shl(autogen9.getZExtValue());
	}
	APInt autogen11 = autogen10&autogen3;
	APInt autogen12 = autogen4&autogen5;
	autogen1[0] = autogen12;
	autogen1[1] = autogen11;
}

extern "C" void mul_partial_solution_4_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	APInt autogen6 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen7(autogen4.getBitWidth(),1);
	APInt autogen8 = autogen5;
	autogen8.clearSignBit();
	APInt autogen9 = autogen3*autogen6;
	APInt autogen10;
	if (autogen7.uge(autogen7.getBitWidth())) {
		autogen10 = APInt(autogen8.getBitWidth(), 0);
	} else {
		autogen10 = autogen8.shl(autogen7.getZExtValue());
	}
	APInt autogen11 = autogen3&autogen9;
	APInt autogen12 = autogen10&autogen2;
	APInt autogen13;
	if (autogen7.uge(autogen7.getBitWidth())) {
		autogen13 = APInt(autogen5.getBitWidth(), 0);
	} else {
		autogen13 = autogen5.lshr(autogen7.getZExtValue());
	}
	APInt autogen14 = autogen12&autogen11;
	autogen1[0] = autogen14;
	autogen1[1] = autogen13;
}

extern "C" void mul_partial_solution_5_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	APInt autogen7 = APInt::getAllOnes(autogen5.getBitWidth());
	unsigned autogen8_autocast = autogen2.countr_one();
	APInt autogen8(autogen2.getBitWidth(),autogen8_autocast);
	APInt autogen9;
	if (autogen8.uge(autogen8.getBitWidth())) {
		autogen9 = APInt(autogen6.getBitWidth(), 0);
	} else {
		autogen9 = autogen6.shl(autogen8.getZExtValue());
	}
	unsigned autogen10_autocast = autogen4.countr_zero();
	APInt autogen10(autogen4.getBitWidth(),autogen10_autocast);
	APInt autogen11;
	if (autogen6 == 0) {
		autogen11 = autogen3;
	} else {
		autogen11 = autogen3.urem(autogen6);
	}
	APInt autogen12 = ~autogen11;
	APInt autogen13;
	if (autogen10.uge(autogen10.getBitWidth())) {
		autogen13 = APInt(autogen9.getBitWidth(), 0);
	} else {
		autogen13 = autogen9.lshr(autogen10.getZExtValue());
	}
	APInt autogen14 = autogen7;
	autogen14.clearSignBit();
	unsigned autogen15_autocast = autogen12.countr_one();
	APInt autogen15(autogen12.getBitWidth(),autogen15_autocast);
	APInt autogen16 = autogen6;
	if (autogen15.ule(autogen15.getBitWidth()))
		autogen16.clearHighBits(autogen15.getZExtValue());
	else
		autogen16.clearHighBits(autogen15.getBitWidth());
	APInt autogen17 = APIntOps::umin(autogen13,autogen14);
	autogen1[0] = autogen17;
	autogen1[1] = autogen16;
}

extern "C" void mul_partial_solution_6_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	APInt autogen6(autogen4.getBitWidth(),1);
	unsigned autogen7_autocast = autogen4.countl_zero();
	APInt autogen7(autogen4.getBitWidth(),autogen7_autocast);
	APInt autogen8 = ~autogen4;
	APInt autogen9;
	if (autogen7.uge(autogen7.getBitWidth())) {
		autogen9 = APInt(autogen5.getBitWidth(), 0);
	} else {
		autogen9 = autogen5.lshr(autogen7.getZExtValue());
	}
	unsigned autogen10_autocast = autogen8.countr_one();
	APInt autogen10(autogen8.getBitWidth(),autogen10_autocast);
	APInt autogen11 = autogen3&autogen8;
	APInt autogen12 = autogen11&autogen5;
	APInt autogen13 = autogen9&autogen8;
	APInt autogen14 = autogen13;
	autogen14.clearSignBit();
	APInt autogen15 = autogen12;
	autogen15.clearSignBit();
	APInt autogen16 = autogen14;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen16.clearHighBits(autogen6.getZExtValue());
	else
		autogen16.clearHighBits(autogen6.getBitWidth());
	APInt autogen17;
	if (autogen10.uge(autogen10.getBitWidth())) {
		autogen17 = APInt(autogen15.getBitWidth(), 0);
	} else {
		autogen17 = autogen15.shl(autogen10.getZExtValue());
	}
	APInt autogen18 = autogen16&autogen2;
	autogen1[0] = autogen18;
	autogen1[1] = autogen17;
}

extern "C" void mul_partial_solution_6_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen1[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5 = ~autogen4;
	int autogen6 = autogen5.eq(autogen3);
	int autogen7 = autogen3.eq(autogen5);
	int autogen8 = autogen6|autogen7;
	int autogen9 = autogen8&autogen8;
	autogen2[0] = autogen9|autogen8;
}

extern "C" void mul_partial_solution_7_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen8(autogen4.getBitWidth(),0);
	APInt autogen9(autogen4.getBitWidth(),1);
	unsigned autogen10_autocast = autogen4.getBitWidth();
	APInt autogen10(autogen4.getBitWidth(),autogen10_autocast);
	int autogen11 = autogen10.ule(autogen9);
	APInt autogen12 = autogen2^autogen6;
	APInt autogen13 = autogen12&autogen2;
	APInt autogen14 = autogen11 ? autogen8 : autogen8 ;
	APInt autogen15 = autogen7;
	if (autogen9.ule(autogen9.getBitWidth()))
		autogen15.clearLowBits(autogen9.getZExtValue());
	else
		autogen15.clearLowBits(autogen9.getBitWidth());
	int autogen16 = autogen15.ule(autogen3);
	APInt autogen17 = autogen10+autogen14;
	APInt autogen18;
	if (autogen17.uge(autogen17.getBitWidth())) {
		autogen18 = APInt(autogen15.getBitWidth(), 0);
	} else {
		autogen18 = autogen15.shl(autogen17.getZExtValue());
	}
	APInt autogen19;
	if (autogen2 == 0) {
		autogen19 = autogen18;
	} else {
		autogen19 = autogen18.srem(autogen2);
	}
	APInt autogen20 = autogen16 ? autogen13 : autogen5 ;
	autogen1[0] = autogen20;
	autogen1[1] = autogen19;
}

extern "C" void mul_partial_solution_8_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = autogen0[1];
	APInt autogen3(autogen2.getBitWidth(),0);
	APInt autogen4(autogen2.getBitWidth(),1);
	APInt autogen5 = autogen4+autogen4;
	APInt autogen6 = autogen3;
	autogen6.setSignBit();
	APInt autogen7 = ~autogen4;
	unsigned autogen8_autocast = autogen5.countr_one();
	APInt autogen8(autogen5.getBitWidth(),autogen8_autocast);
	APInt autogen9 = autogen2;
	if (autogen8.ule(autogen8.getBitWidth()))
		autogen9.clearHighBits(autogen8.getZExtValue());
	else
		autogen9.clearHighBits(autogen8.getBitWidth());
	APInt autogen10 = autogen6^autogen7;
	APInt autogen11 = autogen4&autogen10;
	APInt autogen12 = autogen9&autogen5;
	APInt autogen13 = autogen11;
	if (autogen8.ule(autogen8.getBitWidth()))
		autogen13.clearLowBits(autogen8.getZExtValue());
	else
		autogen13.clearLowBits(autogen8.getBitWidth());
	autogen1[0] = autogen13;
	autogen1[1] = autogen12;
}

extern "C" void mul_partial_solution_8_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[1];
	APInt autogen4 = autogen1[0];
	APInt autogen5 = autogen1[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	APInt autogen7;
	if (autogen6.uge(autogen6.getBitWidth())) {
		autogen7 = APInt(autogen3.getBitWidth(), 0);
	} else {
		autogen7 = autogen3.shl(autogen6.getZExtValue());
	}
	APInt autogen8 = ~autogen7;
	autogen2[0] = autogen8.eq(autogen4);
}

extern "C" void mul_partial_solution_9_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	APInt autogen7(autogen5.getBitWidth(),0);
	unsigned autogen8_autocast = autogen5.getBitWidth();
	APInt autogen8(autogen5.getBitWidth(),autogen8_autocast);
	unsigned autogen9_autocast = autogen2.countr_one();
	APInt autogen9(autogen2.getBitWidth(),autogen9_autocast);
	APInt autogen10 = autogen4;
	if (autogen9.ule(autogen9.getBitWidth()))
		autogen10.setLowBits(autogen9.getZExtValue());
	else
		autogen10.setLowBits(autogen9.getBitWidth());
	APInt autogen11 = autogen8+autogen8;
	APInt autogen12;
	if (autogen11.uge(autogen11.getBitWidth())) {
		autogen12 = APInt(autogen5.getBitWidth(), 0);
	} else {
		autogen12 = autogen5.lshr(autogen11.getZExtValue());
	}
	unsigned autogen13_autocast = autogen10.countr_zero();
	APInt autogen13(autogen10.getBitWidth(),autogen13_autocast);
	APInt autogen14 = autogen6|autogen12;
	int autogen15 = autogen11.ule(autogen7);
	APInt autogen16;
	if (autogen13.uge(autogen13.getBitWidth())) {
		autogen16 = APInt(autogen14.getBitWidth(), 0);
	} else {
		autogen16 = autogen14.lshr(autogen13.getZExtValue());
	}
	APInt autogen17 = autogen15 ? autogen10 : autogen16 ;
	unsigned autogen18_autocast = autogen14.countl_one();
	APInt autogen18(autogen14.getBitWidth(),autogen18_autocast);
	APInt autogen19 = autogen3*autogen12;
	APInt autogen20 = autogen17;
	if (autogen18.ule(autogen18.getBitWidth()))
		autogen20.clearLowBits(autogen18.getZExtValue());
	else
		autogen20.clearLowBits(autogen18.getBitWidth());
	autogen1[0] = autogen20;
	autogen1[1] = autogen19;
}

extern "C" void mul_partial_solution_9_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	unsigned autogen6_autocast = autogen4.getBitWidth();
	APInt autogen6(autogen4.getBitWidth(),autogen6_autocast);
	APInt autogen7;
	if (autogen6.uge(autogen6.getBitWidth())) {
		autogen7 = APInt(autogen5.getBitWidth(), 0);
	} else {
		autogen7 = autogen5.shl(autogen6.getZExtValue());
	}
	APInt autogen8;
	if (autogen3.isMinSignedValue() && autogen7 == -1) {
		autogen8 = APInt::getSignedMinValue(autogen3.getBitWidth());
	} else if (autogen7 == 0 && autogen3.isNonNegative()) {
		autogen8 = APInt(autogen3.getBitWidth(), -1);
	} else if (autogen7 == 0 && autogen3.isNegative()) {
		autogen8 = APInt(autogen3.getBitWidth(), 1);
	} else {
		autogen8 = autogen3.sdiv(autogen7);
	}
	autogen2[0] = autogen8.eq(autogen5);
}

extern "C" void mul_partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	mul_partial_solution_0_body(autogen0,autogen1, autogen2);
}

extern "C" void mul_partial_solution_1(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	mul_partial_solution_1_body(autogen0,autogen1, autogen2);
}

extern "C" void mul_partial_solution_2(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	mul_partial_solution_2_body(autogen0,autogen1, autogen2);
}

extern "C" void mul_partial_solution_3(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	mul_partial_solution_3_body(autogen0,autogen1, autogen2);
}

extern "C" void mul_partial_solution_4(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	mul_partial_solution_4_body(autogen0,autogen1, autogen2);
}

extern "C" void mul_partial_solution_5(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	mul_partial_solution_5_body(autogen0,autogen1, autogen2);
}

extern "C" void mul_partial_solution_6(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	mul_partial_solution_6_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	mul_partial_solution_6_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void mul_partial_solution_7(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	mul_partial_solution_7_body(autogen0,autogen1, autogen2);
}

extern "C" void mul_partial_solution_8(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	mul_partial_solution_8_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	mul_partial_solution_8_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void mul_partial_solution_9(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	mul_partial_solution_9_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	mul_partial_solution_9_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void mul_solution(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	mul_partial_solution_0(autogen0,autogen1, autogen3);
	APInt autogen4[2];
	mul_partial_solution_1(autogen0,autogen1, autogen4);
	APInt autogen5[2];
	mul_partial_solution_2(autogen0,autogen1, autogen5);
	APInt autogen6[2];
	mul_partial_solution_3(autogen0,autogen1, autogen6);
	APInt autogen7[2];
	mul_partial_solution_4(autogen0,autogen1, autogen7);
	APInt autogen8[2];
	mul_partial_solution_5(autogen0,autogen1, autogen8);
	APInt autogen9[2];
	mul_partial_solution_6(autogen0,autogen1, autogen9);
	APInt autogen10[2];
	mul_partial_solution_7(autogen0,autogen1, autogen10);
	APInt autogen11[2];
	mul_partial_solution_8(autogen0,autogen1, autogen11);
	APInt autogen12[2];
	mul_partial_solution_9(autogen0,autogen1, autogen12);
	APInt autogen13[2];
	tf_meet(autogen3,autogen4, autogen13);
	APInt autogen14[2];
	tf_meet(autogen13,autogen5, autogen14);
	APInt autogen15[2];
	tf_meet(autogen14,autogen6, autogen15);
	APInt autogen16[2];
	tf_meet(autogen15,autogen7, autogen16);
	APInt autogen17[2];
	tf_meet(autogen16,autogen8, autogen17);
	APInt autogen18[2];
	tf_meet(autogen17,autogen9, autogen18);
	APInt autogen19[2];
	tf_meet(autogen18,autogen10, autogen19);
	APInt autogen20[2];
	tf_meet(autogen19,autogen11, autogen20);
	tf_meet(autogen20,autogen12, autogen2);
}

