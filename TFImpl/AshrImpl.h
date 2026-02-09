extern "C" void ashr_partial_solution_0_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = autogen0[1];
	APInt autogen3(autogen2.getBitWidth(),1);
	unsigned autogen4_autocast = autogen2.getBitWidth();
	APInt autogen4(autogen2.getBitWidth(),autogen4_autocast);
	APInt autogen5 = APIntOps::umin(autogen4,autogen3);
	APInt autogen6;
	if (autogen5.uge(autogen5.getBitWidth())) {
		autogen6 = APInt(autogen2.getBitWidth(), 0);
	} else {
		autogen6 = autogen2.lshr(autogen5.getZExtValue());
	}
	unsigned autogen7_autocast = autogen6.countl_zero();
	APInt autogen7(autogen6.getBitWidth(),autogen7_autocast);
	APInt autogen8 = autogen6;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen8.clearLowBits(autogen7.getZExtValue());
	else
		autogen8.clearLowBits(autogen7.getBitWidth());
	APInt autogen9 = APIntOps::umin(autogen8,autogen8);
	autogen1[0] = autogen9;
	autogen1[1] = autogen8;
}

extern "C" void ashr_partial_solution_1_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	APInt autogen6;
	if (autogen3.isMinSignedValue() && autogen2 == -1) {
		autogen6 = APInt::getSignedMinValue(autogen3.getBitWidth());
	} else if (autogen2 == 0 && autogen3.isNonNegative()) {
		autogen6 = APInt(autogen3.getBitWidth(), -1);
	} else if (autogen2 == 0 && autogen3.isNegative()) {
		autogen6 = APInt(autogen3.getBitWidth(), 1);
	} else {
		autogen6 = autogen3.sdiv(autogen2);
	}
	APInt autogen7;
	if (autogen6 == 0) {
		autogen7 = APInt(autogen2.getBitWidth(), -1);
	} else {
		autogen7 = autogen2.udiv(autogen6);
	}
	APInt autogen8;
	if (autogen5.uge(autogen5.getBitWidth())) {
		autogen8 = APInt(autogen4.getBitWidth(), 0);
	} else {
		autogen8 = autogen4.shl(autogen5.getZExtValue());
	}
	unsigned autogen9_autocast = autogen8.countl_zero();
	APInt autogen9(autogen8.getBitWidth(),autogen9_autocast);
	APInt autogen10 = ~autogen7;
	APInt autogen11 = autogen7;
	if (autogen9.ule(autogen9.getBitWidth()))
		autogen11.clearLowBits(autogen9.getZExtValue());
	else
		autogen11.clearLowBits(autogen9.getBitWidth());
	autogen1[0] = autogen11;
	autogen1[1] = autogen10;
}

extern "C" void ashr_partial_solution_1_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = autogen4;
	autogen5.setSignBit();
	APInt autogen6;
	if (autogen5.isMinSignedValue() && autogen3 == -1) {
		autogen6 = APInt::getSignedMinValue(autogen5.getBitWidth());
	} else if (autogen3 == 0 && autogen5.isNonNegative()) {
		autogen6 = APInt(autogen5.getBitWidth(), -1);
	} else if (autogen3 == 0 && autogen5.isNegative()) {
		autogen6 = APInt(autogen5.getBitWidth(), 1);
	} else {
		autogen6 = autogen5.sdiv(autogen3);
	}
	autogen2[0] = autogen6.ult(autogen3);
}

extern "C" void ashr_partial_solution_2_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen7(autogen4.getBitWidth(),0);
	unsigned autogen8_autocast = autogen4.getBitWidth();
	APInt autogen8(autogen4.getBitWidth(),autogen8_autocast);
	APInt autogen9;
	if (autogen4 == 0) {
		autogen9 = autogen4;
	} else {
		autogen9 = autogen4.srem(autogen4);
	}
	APInt autogen10;
	if (autogen6.isMinSignedValue() && autogen3 == -1) {
		autogen10 = APInt::getSignedMinValue(autogen6.getBitWidth());
	} else if (autogen3 == 0 && autogen6.isNonNegative()) {
		autogen10 = APInt(autogen6.getBitWidth(), -1);
	} else if (autogen3 == 0 && autogen6.isNegative()) {
		autogen10 = APInt(autogen6.getBitWidth(), 1);
	} else {
		autogen10 = autogen6.sdiv(autogen3);
	}
	int autogen11 = autogen7.ult(autogen8);
	unsigned autogen12_autocast = autogen2.countl_one();
	APInt autogen12(autogen2.getBitWidth(),autogen12_autocast);
	APInt autogen13 = autogen10;
	autogen13.setSignBit();
	APInt autogen14 = autogen9;
	if (autogen12.ule(autogen12.getBitWidth()))
		autogen14.setHighBits(autogen12.getZExtValue());
	else
		autogen14.setHighBits(autogen12.getBitWidth());
	APInt autogen15;
	if (autogen8.uge(autogen8.getBitWidth()) && autogen13.isSignBitSet()) {
		autogen15 = APInt(autogen13.getBitWidth(), -1);
	} else if (autogen8.uge(autogen8.getBitWidth()) && autogen13.isSignBitClear()) {
		autogen15 = APInt(autogen13.getBitWidth(), 0);
	} else {
		autogen15 = autogen13.ashr(autogen8.getZExtValue());
	}
	APInt autogen16 = autogen11 ? autogen6 : autogen5 ;
	APInt autogen17;
	if (autogen14.isMinSignedValue() && autogen16 == -1) {
		autogen17 = APInt::getSignedMinValue(autogen14.getBitWidth());
	} else if (autogen16 == 0 && autogen14.isNonNegative()) {
		autogen17 = APInt(autogen14.getBitWidth(), -1);
	} else if (autogen16 == 0 && autogen14.isNegative()) {
		autogen17 = APInt(autogen14.getBitWidth(), 1);
	} else {
		autogen17 = autogen14.sdiv(autogen16);
	}
	APInt autogen18 = APIntOps::umin(autogen14,autogen15);
	APInt autogen19;
	if (autogen8.uge(autogen8.getBitWidth())) {
		autogen19 = APInt(autogen17.getBitWidth(), 0);
	} else {
		autogen19 = autogen17.shl(autogen8.getZExtValue());
	}
	autogen1[0] = autogen19;
	autogen1[1] = autogen18;
}

extern "C" void ashr_partial_solution_3_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	APInt autogen6 = APInt::getAllOnes(autogen4.getBitWidth());
	unsigned autogen7_autocast = autogen4.getBitWidth();
	APInt autogen7(autogen4.getBitWidth(),autogen7_autocast);
	unsigned autogen8_autocast = autogen2.countl_one();
	APInt autogen8(autogen2.getBitWidth(),autogen8_autocast);
	APInt autogen9 = autogen5-autogen3;
	APInt autogen10 = APIntOps::smin(autogen6,autogen2);
	unsigned autogen11_autocast = autogen4.countl_zero();
	APInt autogen11(autogen4.getBitWidth(),autogen11_autocast);
	int autogen12 = autogen9.eq(autogen10);
	APInt autogen13 = autogen12 ? autogen7 : autogen11 ;
	APInt autogen14;
	if (autogen13.uge(autogen13.getBitWidth()) && autogen10.isSignBitSet()) {
		autogen14 = APInt(autogen10.getBitWidth(), -1);
	} else if (autogen13.uge(autogen13.getBitWidth()) && autogen10.isSignBitClear()) {
		autogen14 = APInt(autogen10.getBitWidth(), 0);
	} else {
		autogen14 = autogen10.ashr(autogen13.getZExtValue());
	}
	unsigned autogen15_autocast = autogen14.countr_one();
	APInt autogen15(autogen14.getBitWidth(),autogen15_autocast);
	APInt autogen16 = autogen15-autogen8;
	APInt autogen17 = autogen9;
	if (autogen13.ule(autogen13.getBitWidth()))
		autogen17.setLowBits(autogen13.getZExtValue());
	else
		autogen17.setLowBits(autogen13.getBitWidth());
	APInt autogen18;
	if (autogen17 == 0) {
		autogen18 = autogen6;
	} else {
		autogen18 = autogen6.srem(autogen17);
	}
	APInt autogen19 = autogen6;
	if (autogen16.ule(autogen16.getBitWidth()))
		autogen19.clearLowBits(autogen16.getZExtValue());
	else
		autogen19.clearLowBits(autogen16.getBitWidth());
	autogen1[0] = autogen19;
	autogen1[1] = autogen18;
}

extern "C" void ashr_partial_solution_3_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen1[1];
	APInt autogen4(autogen3.getBitWidth(),0);
	APInt autogen5 = APInt::getAllOnes(autogen3.getBitWidth());
	APInt autogen6;
	if (autogen3.isMinSignedValue() && autogen5 == -1) {
		autogen6 = APInt::getSignedMinValue(autogen3.getBitWidth());
	} else if (autogen5 == 0 && autogen3.isNonNegative()) {
		autogen6 = APInt(autogen3.getBitWidth(), -1);
	} else if (autogen5 == 0 && autogen3.isNegative()) {
		autogen6 = APInt(autogen3.getBitWidth(), 1);
	} else {
		autogen6 = autogen3.sdiv(autogen5);
	}
	autogen2[0] = autogen6.ule(autogen4);
}

extern "C" void ashr_partial_solution_4_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	unsigned autogen7_autocast = autogen4.getBitWidth();
	APInt autogen7(autogen4.getBitWidth(),autogen7_autocast);
	APInt autogen8 = autogen6-autogen7;
	APInt autogen9 = autogen3^autogen2;
	APInt autogen10 = APIntOps::smax(autogen5,autogen3);
	unsigned autogen11_autocast = autogen3.countl_zero();
	APInt autogen11(autogen3.getBitWidth(),autogen11_autocast);
	APInt autogen12 = autogen9;
	if (autogen8.ule(autogen8.getBitWidth()))
		autogen12.setLowBits(autogen8.getZExtValue());
	else
		autogen12.setLowBits(autogen8.getBitWidth());
	APInt autogen13 = APIntOps::umax(autogen6,autogen11);
	APInt autogen14 = APIntOps::umax(autogen13,autogen8);
	APInt autogen15;
	if (autogen11.uge(autogen11.getBitWidth())) {
		autogen15 = APInt(autogen3.getBitWidth(), 0);
	} else {
		autogen15 = autogen3.lshr(autogen11.getZExtValue());
	}
	APInt autogen16;
	if (autogen14.uge(autogen14.getBitWidth()) && autogen15.isSignBitSet()) {
		autogen16 = APInt(autogen15.getBitWidth(), -1);
	} else if (autogen14.uge(autogen14.getBitWidth()) && autogen15.isSignBitClear()) {
		autogen16 = APInt(autogen15.getBitWidth(), 0);
	} else {
		autogen16 = autogen15.ashr(autogen14.getZExtValue());
	}
	APInt autogen17;
	if (autogen10 == 0) {
		autogen17 = autogen12;
	} else {
		autogen17 = autogen12.srem(autogen10);
	}
	APInt autogen18 = APIntOps::umin(autogen17,autogen16);
	APInt autogen19 = ~autogen16;
	autogen1[0] = autogen19;
	autogen1[1] = autogen18;
}

extern "C" void ashr_partial_solution_4_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5 = ~autogen4;
	autogen2[0] = autogen5.ult(autogen3);
}

extern "C" void ashr_partial_solution_5_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6 = APInt::getAllOnes(autogen5.getBitWidth());
	unsigned autogen7_autocast = autogen5.getBitWidth();
	APInt autogen7(autogen5.getBitWidth(),autogen7_autocast);
	APInt autogen8;
	if (autogen7.uge(autogen7.getBitWidth())) {
		autogen8 = APInt(autogen2.getBitWidth(), 0);
	} else {
		autogen8 = autogen2.lshr(autogen7.getZExtValue());
	}
	APInt autogen9;
	if (autogen3 == 0) {
		autogen9 = APInt(autogen4.getBitWidth(), -1);
	} else {
		autogen9 = autogen4.udiv(autogen3);
	}
	APInt autogen10;
	if (autogen9.isMinSignedValue() && autogen5 == -1) {
		autogen10 = APInt::getSignedMinValue(autogen9.getBitWidth());
	} else if (autogen5 == 0 && autogen9.isNonNegative()) {
		autogen10 = APInt(autogen9.getBitWidth(), -1);
	} else if (autogen5 == 0 && autogen9.isNegative()) {
		autogen10 = APInt(autogen9.getBitWidth(), 1);
	} else {
		autogen10 = autogen9.sdiv(autogen5);
	}
	APInt autogen11;
	if (autogen10 == 0) {
		autogen11 = autogen6;
	} else {
		autogen11 = autogen6.urem(autogen10);
	}
	APInt autogen12 = APIntOps::smin(autogen8,autogen2);
	autogen1[0] = autogen12;
	autogen1[1] = autogen11;
}

extern "C" void ashr_partial_solution_5_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[1];
	APInt autogen4 = autogen1[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7;
	if (autogen6.uge(autogen6.getBitWidth()) && autogen3.isSignBitSet()) {
		autogen7 = APInt(autogen3.getBitWidth(), -1);
	} else if (autogen6.uge(autogen6.getBitWidth()) && autogen3.isSignBitClear()) {
		autogen7 = APInt(autogen3.getBitWidth(), 0);
	} else {
		autogen7 = autogen3.ashr(autogen6.getZExtValue());
	}
	autogen2[0] = autogen5.ule(autogen7);
}

extern "C" void ashr_partial_solution_6_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	APInt autogen6(autogen4.getBitWidth(),0);
	APInt autogen7(autogen4.getBitWidth(),1);
	unsigned autogen8_autocast = autogen4.getBitWidth();
	APInt autogen8(autogen4.getBitWidth(),autogen8_autocast);
	int autogen9 = autogen7.eq(autogen8);
	APInt autogen10 = autogen9 ? autogen6 : autogen8 ;
	APInt autogen11;
	if (autogen10.uge(autogen10.getBitWidth())) {
		autogen11 = APInt(autogen5.getBitWidth(), 0);
	} else {
		autogen11 = autogen5.lshr(autogen10.getZExtValue());
	}
	APInt autogen12 = autogen3|autogen11;
	APInt autogen13;
	if (autogen5.isMinSignedValue() && autogen12 == -1) {
		autogen13 = APInt::getSignedMinValue(autogen5.getBitWidth());
	} else if (autogen12 == 0 && autogen5.isNonNegative()) {
		autogen13 = APInt(autogen5.getBitWidth(), -1);
	} else if (autogen12 == 0 && autogen5.isNegative()) {
		autogen13 = APInt(autogen5.getBitWidth(), 1);
	} else {
		autogen13 = autogen5.sdiv(autogen12);
	}
	APInt autogen14 = autogen13^autogen5;
	APInt autogen15;
	if (autogen13 == 0) {
		autogen15 = APInt(autogen14.getBitWidth(), -1);
	} else {
		autogen15 = autogen14.udiv(autogen13);
	}
	APInt autogen16;
	if (autogen15 == 0) {
		autogen16 = autogen2;
	} else {
		autogen16 = autogen2.srem(autogen15);
	}
	autogen1[0] = autogen16;
	autogen1[1] = autogen15;
}

extern "C" void ashr_partial_solution_6_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7 = APIntOps::smax(autogen6,autogen3);
	APInt autogen8 = ~autogen3;
	APInt autogen9;
	if (autogen8 == 0) {
		autogen9 = autogen7;
	} else {
		autogen9 = autogen7.urem(autogen8);
	}
	autogen2[0] = autogen9.eq(autogen5);
}

extern "C" void ashr_partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	ashr_partial_solution_0_body(autogen0,autogen1, autogen2);
}

extern "C" void ashr_partial_solution_1(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	ashr_partial_solution_1_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	ashr_partial_solution_1_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void ashr_partial_solution_2(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	ashr_partial_solution_2_body(autogen0,autogen1, autogen2);
}

extern "C" void ashr_partial_solution_3(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	ashr_partial_solution_3_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	ashr_partial_solution_3_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void ashr_partial_solution_4(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	ashr_partial_solution_4_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	ashr_partial_solution_4_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void ashr_partial_solution_5(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	ashr_partial_solution_5_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	ashr_partial_solution_5_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void ashr_partial_solution_6(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	ashr_partial_solution_6_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	ashr_partial_solution_6_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void ashr_solution(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	ashr_partial_solution_0(autogen0,autogen1, autogen3);
	APInt autogen4[2];
	ashr_partial_solution_1(autogen0,autogen1, autogen4);
	APInt autogen5[2];
	ashr_partial_solution_2(autogen0,autogen1, autogen5);
	APInt autogen6[2];
	ashr_partial_solution_3(autogen0,autogen1, autogen6);
	APInt autogen7[2];
	ashr_partial_solution_4(autogen0,autogen1, autogen7);
	APInt autogen8[2];
	ashr_partial_solution_5(autogen0,autogen1, autogen8);
	APInt autogen9[2];
	ashr_partial_solution_6(autogen0,autogen1, autogen9);
	APInt autogen10[2];
	tf_meet(autogen3,autogen4, autogen10);
	APInt autogen11[2];
	tf_meet(autogen10,autogen5, autogen11);
	APInt autogen12[2];
	tf_meet(autogen11,autogen6, autogen12);
	APInt autogen13[2];
	tf_meet(autogen12,autogen7, autogen13);
	APInt autogen14[2];
	tf_meet(autogen13,autogen8, autogen14);
	tf_meet(autogen14,autogen9, autogen2);
}

