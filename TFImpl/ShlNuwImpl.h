extern "C" void shl_nuw_partial_solution_0_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),0);
	APInt autogen5(autogen3.getBitWidth(),1);
	int autogen6 = autogen5.ult(autogen3);
	unsigned autogen7_autocast = autogen2.countl_zero();
	APInt autogen7(autogen2.getBitWidth(),autogen7_autocast);
	APInt autogen8 = APIntOps::smin(autogen4,autogen2);
	APInt autogen9 = autogen3;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen9.clearLowBits(autogen7.getZExtValue());
	else
		autogen9.clearLowBits(autogen7.getBitWidth());
	APInt autogen10 = autogen6 ? autogen9 : autogen8 ;
	APInt autogen11 = autogen3;
	autogen11.clearSignBit();
	autogen1[0] = autogen11;
	autogen1[1] = autogen10;
}

extern "C" void shl_nuw_partial_solution_1_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),1);
	unsigned autogen5_autocast = autogen2.countr_one();
	APInt autogen5(autogen2.getBitWidth(),autogen5_autocast);
	APInt autogen6 = autogen4&autogen3;
	APInt autogen7 = autogen6;
	if (autogen5.ule(autogen5.getBitWidth()))
		autogen7.setLowBits(autogen5.getZExtValue());
	else
		autogen7.setLowBits(autogen5.getBitWidth());
	APInt autogen8;
	if (autogen2 == 0) {
		autogen8 = autogen2;
	} else {
		autogen8 = autogen2.urem(autogen2);
	}
	APInt autogen9 = autogen8+autogen7;
	autogen1[0] = autogen9;
	autogen1[1] = autogen8;
}

extern "C" void shl_nuw_partial_solution_2_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	unsigned autogen6_autocast = autogen4.countl_zero();
	APInt autogen6(autogen4.getBitWidth(),autogen6_autocast);
	APInt autogen7 = autogen3-autogen4;
	APInt autogen8;
	if (autogen5.isMinSignedValue() && autogen7 == -1) {
		autogen8 = APInt::getSignedMinValue(autogen5.getBitWidth());
	} else if (autogen7 == 0 && autogen5.isNonNegative()) {
		autogen8 = APInt(autogen5.getBitWidth(), -1);
	} else if (autogen7 == 0 && autogen5.isNegative()) {
		autogen8 = APInt(autogen5.getBitWidth(), 1);
	} else {
		autogen8 = autogen5.sdiv(autogen7);
	}
	APInt autogen9;
	if (autogen8 == 0) {
		autogen9 = APInt(autogen8.getBitWidth(), -1);
	} else {
		autogen9 = autogen8.udiv(autogen8);
	}
	APInt autogen10 = APIntOps::umax(autogen3,autogen9);
	APInt autogen11 = autogen2;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen11.clearLowBits(autogen6.getZExtValue());
	else
		autogen11.clearLowBits(autogen6.getBitWidth());
	APInt autogen12 = autogen10;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen12.clearHighBits(autogen6.getZExtValue());
	else
		autogen12.clearHighBits(autogen6.getBitWidth());
	autogen1[0] = autogen12;
	autogen1[1] = autogen11;
}

extern "C" void shl_nuw_partial_solution_3_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7(autogen4.getBitWidth(),1);
	int autogen8 = autogen5.ult(autogen4);
	unsigned autogen9_autocast = autogen3.countl_zero();
	APInt autogen9(autogen3.getBitWidth(),autogen9_autocast);
	APInt autogen10 = APIntOps::umin(autogen6,autogen3);
	APInt autogen11 = APIntOps::smin(autogen3,autogen3);
	APInt autogen12 = autogen4;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen12.setHighBits(autogen7.getZExtValue());
	else
		autogen12.setHighBits(autogen7.getBitWidth());
	unsigned autogen13_autocast = autogen10.countl_one();
	APInt autogen13(autogen10.getBitWidth(),autogen13_autocast);
	APInt autogen14 = autogen12;
	if (autogen9.ule(autogen9.getBitWidth()))
		autogen14.clearLowBits(autogen9.getZExtValue());
	else
		autogen14.clearLowBits(autogen9.getBitWidth());
	APInt autogen15 = autogen8 ? autogen14 : autogen11 ;
	APInt autogen16;
	if (autogen13.uge(autogen13.getBitWidth())) {
		autogen16 = APInt(autogen2.getBitWidth(), 0);
	} else {
		autogen16 = autogen2.lshr(autogen13.getZExtValue());
	}
	autogen1[0] = autogen16;
	autogen1[1] = autogen15;
}

extern "C" void shl_nuw_partial_solution_3_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = autogen1[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	APInt autogen7 = APInt::getAllOnes(autogen5.getBitWidth());
	APInt autogen8 = autogen7-autogen4;
	int autogen9 = autogen6.ule(autogen3);
	int autogen10 = autogen9|autogen9;
	int autogen11 = autogen9&autogen10;
	int autogen12 = autogen4.ule(autogen8);
	int autogen13 = autogen11^autogen12;
	autogen2[0] = autogen13&autogen11;
}

extern "C" void shl_nuw_partial_solution_4_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen8(autogen4.getBitWidth(),1);
	int autogen9 = autogen8.ule(autogen8);
	APInt autogen10 = autogen8+autogen8;
	APInt autogen11;
	if (autogen6 == 0) {
		autogen11 = autogen3;
	} else {
		autogen11 = autogen3.urem(autogen6);
	}
	APInt autogen12 = autogen2|autogen11;
	unsigned autogen13_autocast = autogen12.countr_one();
	APInt autogen13(autogen12.getBitWidth(),autogen13_autocast);
	APInt autogen14 = APIntOps::umin(autogen10,autogen8);
	APInt autogen15;
	if (autogen14.uge(autogen14.getBitWidth()) && autogen3.isSignBitSet()) {
		autogen15 = APInt(autogen3.getBitWidth(), -1);
	} else if (autogen14.uge(autogen14.getBitWidth()) && autogen3.isSignBitClear()) {
		autogen15 = APInt(autogen3.getBitWidth(), 0);
	} else {
		autogen15 = autogen3.ashr(autogen14.getZExtValue());
	}
	APInt autogen16 = APIntOps::umin(autogen8,autogen13);
	APInt autogen17 = autogen9 ? autogen7 : autogen15 ;
	APInt autogen18 = autogen4;
	if (autogen8.ule(autogen8.getBitWidth()))
		autogen18.clearHighBits(autogen8.getZExtValue());
	else
		autogen18.clearHighBits(autogen8.getBitWidth());
	APInt autogen19;
	if (autogen5.isMinSignedValue() && autogen17 == -1) {
		autogen19 = APInt::getSignedMinValue(autogen5.getBitWidth());
	} else if (autogen17 == 0 && autogen5.isNonNegative()) {
		autogen19 = APInt(autogen5.getBitWidth(), -1);
	} else if (autogen17 == 0 && autogen5.isNegative()) {
		autogen19 = APInt(autogen5.getBitWidth(), 1);
	} else {
		autogen19 = autogen5.sdiv(autogen17);
	}
	APInt autogen20;
	if (autogen16.uge(autogen16.getBitWidth())) {
		autogen20 = APInt(autogen18.getBitWidth(), 0);
	} else {
		autogen20 = autogen18.shl(autogen16.getZExtValue());
	}
	autogen1[0] = autogen20;
	autogen1[1] = autogen19;
}

extern "C" void shl_nuw_partial_solution_5_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = autogen0[0];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),0);
	APInt autogen5(autogen3.getBitWidth(),1);
	APInt autogen6;
	if (autogen4.isMinSignedValue() && autogen5 == -1) {
		autogen6 = APInt::getSignedMinValue(autogen4.getBitWidth());
	} else if (autogen5 == 0 && autogen4.isNonNegative()) {
		autogen6 = APInt(autogen4.getBitWidth(), -1);
	} else if (autogen5 == 0 && autogen4.isNegative()) {
		autogen6 = APInt(autogen4.getBitWidth(), 1);
	} else {
		autogen6 = autogen4.sdiv(autogen5);
	}
	APInt autogen7;
	if (autogen3 == 0) {
		autogen7 = autogen2;
	} else {
		autogen7 = autogen2.urem(autogen3);
	}
	APInt autogen8;
	if (autogen4 == 0) {
		autogen8 = autogen7;
	} else {
		autogen8 = autogen7.urem(autogen4);
	}
	APInt autogen9 = autogen8;
	autogen9.clearSignBit();
	APInt autogen10 = autogen6&autogen2;
	APInt autogen11 = autogen9*autogen3;
	autogen1[0] = autogen11;
	autogen1[1] = autogen10;
}

extern "C" void shl_nuw_partial_solution_6_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7(autogen4.getBitWidth(),1);
	int autogen8 = autogen5.ult(autogen4);
	unsigned autogen9_autocast = autogen3.countl_zero();
	APInt autogen9(autogen3.getBitWidth(),autogen9_autocast);
	APInt autogen10 = APIntOps::umin(autogen6,autogen3);
	APInt autogen11 = APIntOps::smin(autogen3,autogen3);
	APInt autogen12 = autogen4;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen12.setHighBits(autogen7.getZExtValue());
	else
		autogen12.setHighBits(autogen7.getBitWidth());
	unsigned autogen13_autocast = autogen10.countl_one();
	APInt autogen13(autogen10.getBitWidth(),autogen13_autocast);
	APInt autogen14 = autogen12;
	if (autogen9.ule(autogen9.getBitWidth()))
		autogen14.clearLowBits(autogen9.getZExtValue());
	else
		autogen14.clearLowBits(autogen9.getBitWidth());
	APInt autogen15 = autogen8 ? autogen14 : autogen11 ;
	APInt autogen16;
	if (autogen13.uge(autogen13.getBitWidth())) {
		autogen16 = APInt(autogen2.getBitWidth(), 0);
	} else {
		autogen16 = autogen2.lshr(autogen13.getZExtValue());
	}
	autogen1[0] = autogen16;
	autogen1[1] = autogen15;
}

extern "C" void shl_nuw_partial_solution_6_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen1[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	unsigned autogen6_autocast = autogen4.getBitWidth();
	APInt autogen6(autogen4.getBitWidth(),autogen6_autocast);
	APInt autogen7 = autogen3;
	if (autogen5.ule(autogen5.getBitWidth()))
		autogen7.setHighBits(autogen5.getZExtValue());
	else
		autogen7.setHighBits(autogen5.getBitWidth());
	APInt autogen8 = ~autogen7;
	APInt autogen9 = autogen8;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen9.setHighBits(autogen6.getZExtValue());
	else
		autogen9.setHighBits(autogen6.getBitWidth());
	autogen2[0] = autogen7.eq(autogen9);
}

extern "C" void shl_nuw_partial_solution_7_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7 = APIntOps::smax(autogen4,autogen2);
	APInt autogen8;
	if (autogen6.uge(autogen6.getBitWidth()) && autogen7.isSignBitSet()) {
		autogen8 = APInt(autogen7.getBitWidth(), -1);
	} else if (autogen6.uge(autogen6.getBitWidth()) && autogen7.isSignBitClear()) {
		autogen8 = APInt(autogen7.getBitWidth(), 0);
	} else {
		autogen8 = autogen7.ashr(autogen6.getZExtValue());
	}
	APInt autogen9;
	if (autogen8 == 0) {
		autogen9 = autogen5;
	} else {
		autogen9 = autogen5.urem(autogen8);
	}
	APInt autogen10;
	if (autogen9 == 0) {
		autogen10 = APInt(autogen3.getBitWidth(), -1);
	} else {
		autogen10 = autogen3.udiv(autogen9);
	}
	APInt autogen11;
	if (autogen4 == 0) {
		autogen11 = APInt(autogen10.getBitWidth(), -1);
	} else {
		autogen11 = autogen10.udiv(autogen4);
	}
	APInt autogen12;
	if (autogen11 == 0) {
		autogen12 = APInt(autogen8.getBitWidth(), -1);
	} else {
		autogen12 = autogen8.udiv(autogen11);
	}
	APInt autogen13;
	if (autogen9 == 0) {
		autogen13 = autogen12;
	} else {
		autogen13 = autogen12.urem(autogen9);
	}
	autogen1[0] = autogen13;
	autogen1[1] = autogen12;
}

extern "C" void shl_nuw_partial_solution_8_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),1);
	APInt autogen5 = APInt::getAllOnes(autogen3.getBitWidth());
	APInt autogen6(autogen3.getBitWidth(),1);
	APInt autogen7;
	if (autogen4 == 0) {
		autogen7 = APInt(autogen3.getBitWidth(), -1);
	} else {
		autogen7 = autogen3.udiv(autogen4);
	}
	APInt autogen8 = autogen2*autogen5;
	APInt autogen9 = autogen8*autogen7;
	APInt autogen10;
	if (autogen3 == 0) {
		autogen10 = autogen9;
	} else {
		autogen10 = autogen9.srem(autogen3);
	}
	APInt autogen11 = autogen10;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen11.clearHighBits(autogen6.getZExtValue());
	else
		autogen11.clearHighBits(autogen6.getBitWidth());
	APInt autogen12 = APIntOps::smax(autogen7,autogen5);
	autogen1[0] = autogen12;
	autogen1[1] = autogen11;
}

extern "C" void shl_nuw_partial_solution_9_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	APInt autogen7(autogen5.getBitWidth(),0);
	APInt autogen8(autogen5.getBitWidth(),1);
	unsigned autogen9_autocast = autogen5.getBitWidth();
	APInt autogen9(autogen5.getBitWidth(),autogen9_autocast);
	APInt autogen10 = autogen5;
	if (autogen8.ule(autogen8.getBitWidth()))
		autogen10.clearHighBits(autogen8.getZExtValue());
	else
		autogen10.clearHighBits(autogen8.getBitWidth());
	int autogen11 = autogen6.ult(autogen10);
	APInt autogen12 = autogen11 ? autogen9 : autogen7 ;
	APInt autogen13 = autogen11 ? autogen4 : autogen2 ;
	unsigned autogen14_autocast = autogen10.countr_one();
	APInt autogen14(autogen10.getBitWidth(),autogen14_autocast);
	APInt autogen15;
	if (autogen14.uge(autogen14.getBitWidth())) {
		autogen15 = APInt(autogen3.getBitWidth(), 0);
	} else {
		autogen15 = autogen3.shl(autogen14.getZExtValue());
	}
	APInt autogen16 = autogen13;
	if (autogen12.ule(autogen12.getBitWidth()))
		autogen16.setHighBits(autogen12.getZExtValue());
	else
		autogen16.setHighBits(autogen12.getBitWidth());
	autogen1[0] = autogen16;
	autogen1[1] = autogen15;
}

extern "C" void shl_nuw_partial_solution_9_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7 = autogen3;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen7.setHighBits(autogen6.getZExtValue());
	else
		autogen7.setHighBits(autogen6.getBitWidth());
	int autogen8 = autogen7.eq(autogen5);
	autogen2[0] = autogen8|autogen8;
}

extern "C" void shl_nuw_partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nuw_partial_solution_0_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nuw_partial_solution_1(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nuw_partial_solution_1_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nuw_partial_solution_2(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nuw_partial_solution_2_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nuw_partial_solution_3(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	shl_nuw_partial_solution_3_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	shl_nuw_partial_solution_3_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void shl_nuw_partial_solution_4(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nuw_partial_solution_4_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nuw_partial_solution_5(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nuw_partial_solution_5_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nuw_partial_solution_6(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	shl_nuw_partial_solution_6_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	shl_nuw_partial_solution_6_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void shl_nuw_partial_solution_7(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nuw_partial_solution_7_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nuw_partial_solution_8(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nuw_partial_solution_8_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nuw_partial_solution_9(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	shl_nuw_partial_solution_9_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	shl_nuw_partial_solution_9_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void shl_nuw_solution(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	shl_nuw_partial_solution_0(autogen0,autogen1, autogen3);
	APInt autogen4[2];
	shl_nuw_partial_solution_1(autogen0,autogen1, autogen4);
	APInt autogen5[2];
	shl_nuw_partial_solution_2(autogen0,autogen1, autogen5);
	APInt autogen6[2];
	shl_nuw_partial_solution_3(autogen0,autogen1, autogen6);
	APInt autogen7[2];
	shl_nuw_partial_solution_4(autogen0,autogen1, autogen7);
	APInt autogen8[2];
	shl_nuw_partial_solution_5(autogen0,autogen1, autogen8);
	APInt autogen9[2];
	shl_nuw_partial_solution_6(autogen0,autogen1, autogen9);
	APInt autogen10[2];
	shl_nuw_partial_solution_7(autogen0,autogen1, autogen10);
	APInt autogen11[2];
	shl_nuw_partial_solution_8(autogen0,autogen1, autogen11);
	APInt autogen12[2];
	shl_nuw_partial_solution_9(autogen0,autogen1, autogen12);
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

