extern "C" void sub_partial_solution_0_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	APInt autogen7(autogen5.getBitWidth(),1);
	unsigned autogen8_autocast = autogen2.countr_zero();
	APInt autogen8(autogen2.getBitWidth(),autogen8_autocast);
	APInt autogen9 = autogen4-autogen2;
	APInt autogen10 = autogen3;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen10.clearHighBits(autogen7.getZExtValue());
	else
		autogen10.clearHighBits(autogen7.getBitWidth());
	unsigned autogen11_autocast = autogen9.countr_zero();
	APInt autogen11(autogen9.getBitWidth(),autogen11_autocast);
	APInt autogen12 = APIntOps::smax(autogen10,autogen5);
	APInt autogen13 = autogen6&autogen12;
	APInt autogen14 = APIntOps::umax(autogen11,autogen11);
	APInt autogen15 = autogen4;
	if (autogen8.ule(autogen8.getBitWidth()))
		autogen15.clearLowBits(autogen8.getZExtValue());
	else
		autogen15.clearLowBits(autogen8.getBitWidth());
	APInt autogen16 = autogen13;
	if (autogen14.ule(autogen14.getBitWidth()))
		autogen16.clearLowBits(autogen14.getZExtValue());
	else
		autogen16.clearLowBits(autogen14.getBitWidth());
	APInt autogen17 = autogen15&autogen6;
	autogen1[0] = autogen17;
	autogen1[1] = autogen16;
}

extern "C" void sub_partial_solution_1_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7(autogen4.getBitWidth(),0);
	APInt autogen8(autogen4.getBitWidth(),1);
	int autogen9 = autogen8.eq(autogen7);
	APInt autogen10 = autogen6&autogen2;
	APInt autogen11 = autogen5;
	autogen11.setSignBit();
	APInt autogen12 = autogen9 ? autogen6 : autogen2 ;
	unsigned autogen13_autocast = autogen11.countr_zero();
	APInt autogen13(autogen11.getBitWidth(),autogen13_autocast);
	APInt autogen14 = autogen2|autogen10;
	APInt autogen15 = autogen14&autogen4;
	APInt autogen16 = autogen14+autogen4;
	APInt autogen17;
	if (autogen5 == 0) {
		autogen17 = autogen3;
	} else {
		autogen17 = autogen3.urem(autogen5);
	}
	APInt autogen18 = autogen17&autogen12;
	APInt autogen19 = autogen16&autogen14;
	APInt autogen20;
	if (autogen13.uge(autogen13.getBitWidth())) {
		autogen20 = APInt(autogen18.getBitWidth(), 0);
	} else {
		autogen20 = autogen18.shl(autogen13.getZExtValue());
	}
	APInt autogen21 = autogen15&autogen19;
	autogen1[0] = autogen21;
	autogen1[1] = autogen20;
}

extern "C" void sub_partial_solution_2_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7 = autogen4&autogen2;
	APInt autogen8 = autogen7;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen8.setLowBits(autogen6.getZExtValue());
	else
		autogen8.setLowBits(autogen6.getBitWidth());
	APInt autogen9 = autogen2^autogen8;
	APInt autogen10 = autogen3+autogen9;
	APInt autogen11;
	if (autogen5 == 0) {
		autogen11 = autogen5;
	} else {
		autogen11 = autogen5.srem(autogen5);
	}
	APInt autogen12 = autogen10&autogen7;
	autogen1[0] = autogen12;
	autogen1[1] = autogen11;
}

extern "C" void sub_partial_solution_3_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	APInt autogen6 = autogen3+autogen5;
	APInt autogen7 = APIntOps::umin(autogen4,autogen6);
	APInt autogen8 = autogen6&autogen4;
	APInt autogen9 = autogen8&autogen2;
	APInt autogen10 = autogen9;
	autogen10.clearSignBit();
	APInt autogen11;
	if (autogen7 == 0) {
		autogen11 = autogen7;
	} else {
		autogen11 = autogen7.urem(autogen7);
	}
	APInt autogen12 = autogen10|autogen9;
	autogen1[0] = autogen12;
	autogen1[1] = autogen11;
}

extern "C" void sub_partial_solution_4_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen8 = autogen6+autogen3;
	APInt autogen9 = APIntOps::smin(autogen7,autogen6);
	APInt autogen10 = autogen4&autogen8;
	APInt autogen11 = APIntOps::smax(autogen7,autogen5);
	APInt autogen12 = APIntOps::umin(autogen2,autogen9);
	APInt autogen13 = autogen10&autogen12;
	APInt autogen14 = autogen11^autogen11;
	autogen1[0] = autogen14;
	autogen1[1] = autogen13;
}

extern "C" void sub_partial_solution_5_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),0);
	APInt autogen7(autogen5.getBitWidth(),1);
	APInt autogen8 = autogen2&autogen5;
	APInt autogen9 = autogen4&autogen3;
	APInt autogen10;
	if (autogen7.uge(autogen7.getBitWidth())) {
		autogen10 = APInt(autogen9.getBitWidth(), 0);
	} else {
		autogen10 = autogen9.shl(autogen7.getZExtValue());
	}
	APInt autogen11 = autogen6;
	autogen11.setSignBit();
	APInt autogen12 = autogen8&autogen9;
	APInt autogen13 = autogen8&autogen10;
	APInt autogen14;
	if (autogen11 == 0) {
		autogen14 = autogen12;
	} else {
		autogen14 = autogen12.srem(autogen11);
	}
	autogen1[0] = autogen14;
	autogen1[1] = autogen13;
}

extern "C" void sub_partial_solution_6_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	unsigned autogen5_autocast = autogen4.getBitWidth();
	APInt autogen5(autogen4.getBitWidth(),autogen5_autocast);
	APInt autogen6 = autogen4&autogen3;
	unsigned autogen7_autocast = autogen3.countr_one();
	APInt autogen7(autogen3.getBitWidth(),autogen7_autocast);
	APInt autogen8 = autogen4;
	autogen8.clearSignBit();
	APInt autogen9 = autogen5-autogen7;
	APInt autogen10 = autogen2;
	if (autogen9.ule(autogen9.getBitWidth()))
		autogen10.clearHighBits(autogen9.getZExtValue());
	else
		autogen10.clearHighBits(autogen9.getBitWidth());
	APInt autogen11 = autogen8*autogen6;
	autogen1[0] = autogen11;
	autogen1[1] = autogen10;
}

extern "C" void sub_partial_solution_7_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	unsigned autogen7_autocast = autogen4.getBitWidth();
	APInt autogen7(autogen4.getBitWidth(),autogen7_autocast);
	unsigned autogen8_autocast = autogen3.countr_one();
	APInt autogen8(autogen3.getBitWidth(),autogen8_autocast);
	APInt autogen9 = autogen2|autogen6;
	APInt autogen10 = autogen7-autogen8;
	APInt autogen11;
	if (autogen7.uge(autogen7.getBitWidth()) && autogen5.isSignBitSet()) {
		autogen11 = APInt(autogen5.getBitWidth(), -1);
	} else if (autogen7.uge(autogen7.getBitWidth()) && autogen5.isSignBitClear()) {
		autogen11 = APInt(autogen5.getBitWidth(), 0);
	} else {
		autogen11 = autogen5.ashr(autogen7.getZExtValue());
	}
	APInt autogen12;
	if (autogen11.isMinSignedValue() && autogen9 == -1) {
		autogen12 = APInt::getSignedMinValue(autogen11.getBitWidth());
	} else if (autogen9 == 0 && autogen11.isNonNegative()) {
		autogen12 = APInt(autogen11.getBitWidth(), -1);
	} else if (autogen9 == 0 && autogen11.isNegative()) {
		autogen12 = APInt(autogen11.getBitWidth(), 1);
	} else {
		autogen12 = autogen11.sdiv(autogen9);
	}
	APInt autogen13 = autogen2;
	if (autogen10.ule(autogen10.getBitWidth()))
		autogen13.clearHighBits(autogen10.getZExtValue());
	else
		autogen13.clearHighBits(autogen10.getBitWidth());
	autogen1[0] = autogen13;
	autogen1[1] = autogen12;
}

extern "C" void sub_partial_solution_8_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	APInt autogen7 = APInt::getAllOnes(autogen5.getBitWidth());
	APInt autogen8 = autogen3+autogen6;
	APInt autogen9;
	if (autogen5 == 0) {
		autogen9 = autogen6;
	} else {
		autogen9 = autogen6.urem(autogen5);
	}
	APInt autogen10 = autogen9+autogen7;
	APInt autogen11 = autogen4&autogen2;
	APInt autogen12 = APIntOps::smin(autogen9,autogen7);
	APInt autogen13 = autogen8&autogen11;
	APInt autogen14 = autogen9&autogen10;
	APInt autogen15 = autogen12&autogen13;
	autogen1[0] = autogen15;
	autogen1[1] = autogen14;
}

extern "C" void sub_partial_solution_9_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	unsigned autogen7_autocast = autogen5.getBitWidth();
	APInt autogen7(autogen5.getBitWidth(),autogen7_autocast);
	APInt autogen8 = autogen6;
	autogen8.clearSignBit();
	APInt autogen9 = autogen3;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen9.setHighBits(autogen7.getZExtValue());
	else
		autogen9.setHighBits(autogen7.getBitWidth());
	APInt autogen10 = autogen2&autogen5;
	APInt autogen11 = autogen8+autogen4;
	APInt autogen12 = APIntOps::umin(autogen9,autogen10);
	APInt autogen13 = autogen12&autogen11;
	APInt autogen14 = autogen4&autogen13;
	autogen1[0] = autogen14;
	autogen1[1] = autogen13;
}

extern "C" void sub_partial_solution_10_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	APInt autogen6 = autogen5&autogen3;
	APInt autogen7 = autogen2&autogen4;
	APInt autogen8 = autogen6+autogen5;
	APInt autogen9 = autogen3;
	autogen9.clearSignBit();
	APInt autogen10 = autogen8&autogen4;
	APInt autogen11 = autogen9&autogen7;
	APInt autogen12 = autogen10&autogen9;
	autogen1[0] = autogen12;
	autogen1[1] = autogen11;
}

extern "C" void sub_partial_solution_11_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	APInt autogen7 = APInt::getAllOnes(autogen5.getBitWidth());
	unsigned autogen8_autocast = autogen5.getBitWidth();
	APInt autogen8(autogen5.getBitWidth(),autogen8_autocast);
	APInt autogen9 = autogen2+autogen5;
	APInt autogen10 = autogen3;
	if (autogen8.ule(autogen8.getBitWidth()))
		autogen10.setHighBits(autogen8.getZExtValue());
	else
		autogen10.setHighBits(autogen8.getBitWidth());
	APInt autogen11;
	if (autogen9.isMinSignedValue() && autogen10 == -1) {
		autogen11 = APInt::getSignedMinValue(autogen9.getBitWidth());
	} else if (autogen10 == 0 && autogen9.isNonNegative()) {
		autogen11 = APInt(autogen9.getBitWidth(), -1);
	} else if (autogen10 == 0 && autogen9.isNegative()) {
		autogen11 = APInt(autogen9.getBitWidth(), 1);
	} else {
		autogen11 = autogen9.sdiv(autogen10);
	}
	APInt autogen12 = APIntOps::smax(autogen11,autogen6);
	APInt autogen13 = autogen9&autogen4;
	APInt autogen14 = autogen3&autogen13;
	APInt autogen15 = autogen11&autogen6;
	APInt autogen16;
	if (autogen7 == 0) {
		autogen16 = autogen15;
	} else {
		autogen16 = autogen15.srem(autogen7);
	}
	APInt autogen17 = autogen12&autogen14;
	autogen1[0] = autogen17;
	autogen1[1] = autogen16;
}

extern "C" void sub_partial_solution_12_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	APInt autogen6 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen7 = autogen2;
	autogen7.setSignBit();
	APInt autogen8 = autogen3+autogen6;
	APInt autogen9;
	if (autogen8 == 0) {
		autogen9 = autogen8;
	} else {
		autogen9 = autogen8.srem(autogen8);
	}
	APInt autogen10 = autogen9&autogen5;
	APInt autogen11 = autogen10&autogen7;
	APInt autogen12 = autogen4&autogen2;
	APInt autogen13 = autogen2&autogen11;
	autogen1[0] = autogen13;
	autogen1[1] = autogen12;
}

extern "C" void sub_partial_solution_12_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen6 = autogen3*autogen5;
	autogen2[0] = autogen6.eq(autogen4);
}

extern "C" void sub_partial_solution_13_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen7(autogen4.getBitWidth(),1);
	unsigned autogen8_autocast = autogen4.getBitWidth();
	APInt autogen8(autogen4.getBitWidth(),autogen8_autocast);
	APInt autogen9 = APIntOps::umin(autogen7,autogen8);
	APInt autogen10;
	if (autogen8.uge(autogen8.getBitWidth())) {
		autogen10 = APInt(autogen2.getBitWidth(), 0);
	} else {
		autogen10 = autogen2.lshr(autogen8.getZExtValue());
	}
	unsigned autogen11_autocast = autogen10.countl_one();
	APInt autogen11(autogen10.getBitWidth(),autogen11_autocast);
	APInt autogen12 = autogen10;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen12.clearLowBits(autogen7.getZExtValue());
	else
		autogen12.clearLowBits(autogen7.getBitWidth());
	APInt autogen13 = autogen5;
	if (autogen11.ule(autogen11.getBitWidth()))
		autogen13.setHighBits(autogen11.getZExtValue());
	else
		autogen13.setHighBits(autogen11.getBitWidth());
	APInt autogen14;
	if (autogen7.uge(autogen7.getBitWidth()) && autogen10.isSignBitSet()) {
		autogen14 = APInt(autogen10.getBitWidth(), -1);
	} else if (autogen7.uge(autogen7.getBitWidth()) && autogen10.isSignBitClear()) {
		autogen14 = APInt(autogen10.getBitWidth(), 0);
	} else {
		autogen14 = autogen10.ashr(autogen7.getZExtValue());
	}
	APInt autogen15 = APIntOps::umin(autogen9,autogen7);
	int autogen16 = autogen6.ule(autogen2);
	APInt autogen17 = autogen7+autogen7;
	APInt autogen18 = autogen13-autogen12;
	APInt autogen19 = autogen15-autogen8;
	int autogen20 = autogen17.eq(autogen19);
	APInt autogen21 = autogen20 ? autogen19 : autogen9 ;
	APInt autogen22 = autogen16 ? autogen3 : autogen18 ;
	APInt autogen23;
	if (autogen21.uge(autogen21.getBitWidth())) {
		autogen23 = APInt(autogen14.getBitWidth(), 0);
	} else {
		autogen23 = autogen14.lshr(autogen21.getZExtValue());
	}
	autogen1[0] = autogen23;
	autogen1[1] = autogen22;
}

extern "C" void sub_partial_solution_14_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6 = APInt::getAllOnes(autogen4.getBitWidth());
	int autogen7 = autogen2.eq(autogen6);
	APInt autogen8;
	if (autogen5 == 0) {
		autogen8 = autogen5;
	} else {
		autogen8 = autogen5.urem(autogen5);
	}
	APInt autogen9 = autogen3+autogen8;
	APInt autogen10 = autogen9&autogen8;
	APInt autogen11 = autogen7 ? autogen4 : autogen10 ;
	autogen1[0] = autogen11;
	autogen1[1] = autogen10;
}

extern "C" void sub_partial_solution_15_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	unsigned autogen6_autocast = autogen4.getBitWidth();
	APInt autogen6(autogen4.getBitWidth(),autogen6_autocast);
	APInt autogen7;
	if (autogen6.uge(autogen6.getBitWidth())) {
		autogen7 = APInt(autogen3.getBitWidth(), 0);
	} else {
		autogen7 = autogen3.lshr(autogen6.getZExtValue());
	}
	APInt autogen8 = APIntOps::umax(autogen5,autogen6);
	APInt autogen9 = autogen3;
	autogen9.clearSignBit();
	APInt autogen10 = APIntOps::umax(autogen5,autogen6);
	APInt autogen11 = autogen8-autogen10;
	APInt autogen12 = autogen7;
	if (autogen11.ule(autogen11.getBitWidth()))
		autogen12.setLowBits(autogen11.getZExtValue());
	else
		autogen12.setLowBits(autogen11.getBitWidth());
	APInt autogen13 = autogen2&autogen9;
	autogen1[0] = autogen13;
	autogen1[1] = autogen12;
}

extern "C" void sub_partial_solution_15_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[1];
	APInt autogen4 = autogen1[0];
	APInt autogen5 = autogen1[1];
	APInt autogen6(autogen5.getBitWidth(),0);
	APInt autogen7 = autogen4+autogen3;
	autogen2[0] = autogen6.eq(autogen7);
}

extern "C" void sub_partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	sub_partial_solution_0_body(autogen0,autogen1, autogen2);
}

extern "C" void sub_partial_solution_1(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	sub_partial_solution_1_body(autogen0,autogen1, autogen2);
}

extern "C" void sub_partial_solution_2(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	sub_partial_solution_2_body(autogen0,autogen1, autogen2);
}

extern "C" void sub_partial_solution_3(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	sub_partial_solution_3_body(autogen0,autogen1, autogen2);
}

extern "C" void sub_partial_solution_4(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	sub_partial_solution_4_body(autogen0,autogen1, autogen2);
}

extern "C" void sub_partial_solution_5(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	sub_partial_solution_5_body(autogen0,autogen1, autogen2);
}

extern "C" void sub_partial_solution_6(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	sub_partial_solution_6_body(autogen0,autogen1, autogen2);
}

extern "C" void sub_partial_solution_7(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	sub_partial_solution_7_body(autogen0,autogen1, autogen2);
}

extern "C" void sub_partial_solution_8(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	sub_partial_solution_8_body(autogen0,autogen1, autogen2);
}

extern "C" void sub_partial_solution_9(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	sub_partial_solution_9_body(autogen0,autogen1, autogen2);
}

extern "C" void sub_partial_solution_10(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	sub_partial_solution_10_body(autogen0,autogen1, autogen2);
}

extern "C" void sub_partial_solution_11(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	sub_partial_solution_11_body(autogen0,autogen1, autogen2);
}

extern "C" void sub_partial_solution_12(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sub_partial_solution_12_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sub_partial_solution_12_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sub_partial_solution_13(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	sub_partial_solution_13_body(autogen0,autogen1, autogen2);
}

extern "C" void sub_partial_solution_14(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	sub_partial_solution_14_body(autogen0,autogen1, autogen2);
}

extern "C" void sub_partial_solution_15(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sub_partial_solution_15_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sub_partial_solution_15_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sub_solution(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	sub_partial_solution_0(autogen0,autogen1, autogen3);
	APInt autogen4[2];
	sub_partial_solution_1(autogen0,autogen1, autogen4);
	APInt autogen5[2];
	sub_partial_solution_2(autogen0,autogen1, autogen5);
	APInt autogen6[2];
	sub_partial_solution_3(autogen0,autogen1, autogen6);
	APInt autogen7[2];
	sub_partial_solution_4(autogen0,autogen1, autogen7);
	APInt autogen8[2];
	sub_partial_solution_5(autogen0,autogen1, autogen8);
	APInt autogen9[2];
	sub_partial_solution_6(autogen0,autogen1, autogen9);
	APInt autogen10[2];
	sub_partial_solution_7(autogen0,autogen1, autogen10);
	APInt autogen11[2];
	sub_partial_solution_8(autogen0,autogen1, autogen11);
	APInt autogen12[2];
	sub_partial_solution_9(autogen0,autogen1, autogen12);
	APInt autogen13[2];
	sub_partial_solution_10(autogen0,autogen1, autogen13);
	APInt autogen14[2];
	sub_partial_solution_11(autogen0,autogen1, autogen14);
	APInt autogen15[2];
	sub_partial_solution_12(autogen0,autogen1, autogen15);
	APInt autogen16[2];
	sub_partial_solution_13(autogen0,autogen1, autogen16);
	APInt autogen17[2];
	sub_partial_solution_14(autogen0,autogen1, autogen17);
	APInt autogen18[2];
	sub_partial_solution_15(autogen0,autogen1, autogen18);
	APInt autogen19[2];
	tf_meet(autogen3,autogen4, autogen19);
	APInt autogen20[2];
	tf_meet(autogen19,autogen5, autogen20);
	APInt autogen21[2];
	tf_meet(autogen20,autogen6, autogen21);
	APInt autogen22[2];
	tf_meet(autogen21,autogen7, autogen22);
	APInt autogen23[2];
	tf_meet(autogen22,autogen8, autogen23);
	APInt autogen24[2];
	tf_meet(autogen23,autogen9, autogen24);
	APInt autogen25[2];
	tf_meet(autogen24,autogen10, autogen25);
	APInt autogen26[2];
	tf_meet(autogen25,autogen11, autogen26);
	APInt autogen27[2];
	tf_meet(autogen26,autogen12, autogen27);
	APInt autogen28[2];
	tf_meet(autogen27,autogen13, autogen28);
	APInt autogen29[2];
	tf_meet(autogen28,autogen14, autogen29);
	APInt autogen30[2];
	tf_meet(autogen29,autogen15, autogen30);
	APInt autogen31[2];
	tf_meet(autogen30,autogen16, autogen31);
	APInt autogen32[2];
	tf_meet(autogen31,autogen17, autogen32);
	tf_meet(autogen32,autogen18, autogen2);
}

