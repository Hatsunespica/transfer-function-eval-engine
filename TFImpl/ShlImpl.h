extern "C" void shl_partial_solution_0_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = autogen0[1];
	APInt autogen3(autogen2.getBitWidth(),1);
	APInt autogen4 = APInt::getAllOnes(autogen2.getBitWidth());
	APInt autogen5(autogen2.getBitWidth(),1);
	unsigned autogen6_autocast = autogen2.countl_zero();
	APInt autogen6(autogen2.getBitWidth(),autogen6_autocast);
	APInt autogen7 = autogen3-autogen2;
	APInt autogen8;
	if (autogen2 == 0) {
		autogen8 = autogen7;
	} else {
		autogen8 = autogen7.urem(autogen2);
	}
	APInt autogen9 = autogen8;
	if (autogen5.ule(autogen5.getBitWidth()))
		autogen9.clearLowBits(autogen5.getZExtValue());
	else
		autogen9.clearLowBits(autogen5.getBitWidth());
	APInt autogen10 = APIntOps::umin(autogen2,autogen9);
	APInt autogen11;
	if (autogen6.uge(autogen6.getBitWidth()) && autogen10.isSignBitSet()) {
		autogen11 = APInt(autogen10.getBitWidth(), -1);
	} else if (autogen6.uge(autogen6.getBitWidth()) && autogen10.isSignBitClear()) {
		autogen11 = APInt(autogen10.getBitWidth(), 0);
	} else {
		autogen11 = autogen10.ashr(autogen6.getZExtValue());
	}
	APInt autogen12 = autogen4;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen12.clearHighBits(autogen6.getZExtValue());
	else
		autogen12.clearHighBits(autogen6.getBitWidth());
	autogen1[0] = autogen12;
	autogen1[1] = autogen11;
}

extern "C" void shl_partial_solution_1_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),1);
	APInt autogen5(autogen3.getBitWidth(),1);
	unsigned autogen6_autocast = autogen3.getBitWidth();
	APInt autogen6(autogen3.getBitWidth(),autogen6_autocast);
	unsigned autogen7_autocast = autogen2.countr_one();
	APInt autogen7(autogen2.getBitWidth(),autogen7_autocast);
	APInt autogen8 = autogen4-autogen3;
	APInt autogen9 = autogen8*autogen3;
	int autogen10 = autogen7.eq(autogen5);
	APInt autogen11;
	if (autogen2 == 0) {
		autogen11 = autogen4;
	} else {
		autogen11 = autogen4.urem(autogen2);
	}
	APInt autogen12 = autogen8;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen12.clearLowBits(autogen7.getZExtValue());
	else
		autogen12.clearLowBits(autogen7.getBitWidth());
	APInt autogen13 = autogen10 ? autogen7 : autogen6 ;
	APInt autogen14 = autogen9;
	if (autogen13.ule(autogen13.getBitWidth()))
		autogen14.clearLowBits(autogen13.getZExtValue());
	else
		autogen14.clearLowBits(autogen13.getBitWidth());
	APInt autogen15 = APIntOps::umax(autogen3,autogen4);
	APInt autogen16 = autogen12-autogen14;
	APInt autogen17;
	if (autogen16 == 0) {
		autogen17 = autogen15;
	} else {
		autogen17 = autogen15.srem(autogen16);
	}
	APInt autogen18;
	if (autogen13.uge(autogen13.getBitWidth())) {
		autogen18 = APInt(autogen11.getBitWidth(), 0);
	} else {
		autogen18 = autogen11.lshr(autogen13.getZExtValue());
	}
	APInt autogen19 = autogen17-autogen9;
	autogen1[0] = autogen19;
	autogen1[1] = autogen18;
}

extern "C" void shl_partial_solution_2_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),1);
	unsigned autogen5_autocast = autogen3.getBitWidth();
	APInt autogen5(autogen3.getBitWidth(),autogen5_autocast);
	APInt autogen6;
	if (autogen4.uge(autogen4.getBitWidth()) && autogen3.isSignBitSet()) {
		autogen6 = APInt(autogen3.getBitWidth(), -1);
	} else if (autogen4.uge(autogen4.getBitWidth()) && autogen3.isSignBitClear()) {
		autogen6 = APInt(autogen3.getBitWidth(), 0);
	} else {
		autogen6 = autogen3.ashr(autogen4.getZExtValue());
	}
	unsigned autogen7_autocast = autogen6.countr_zero();
	APInt autogen7(autogen6.getBitWidth(),autogen7_autocast);
	APInt autogen8 = autogen2;
	if (autogen5.ule(autogen5.getBitWidth()))
		autogen8.clearLowBits(autogen5.getZExtValue());
	else
		autogen8.clearLowBits(autogen5.getBitWidth());
	APInt autogen9 = autogen7+autogen7;
	APInt autogen10 = autogen6;
	if (autogen9.ule(autogen9.getBitWidth()))
		autogen10.setLowBits(autogen9.getZExtValue());
	else
		autogen10.setLowBits(autogen9.getBitWidth());
	APInt autogen11;
	if (autogen7.uge(autogen7.getBitWidth()) && autogen8.isSignBitSet()) {
		autogen11 = APInt(autogen8.getBitWidth(), -1);
	} else if (autogen7.uge(autogen7.getBitWidth()) && autogen8.isSignBitClear()) {
		autogen11 = APInt(autogen8.getBitWidth(), 0);
	} else {
		autogen11 = autogen8.ashr(autogen7.getZExtValue());
	}
	APInt autogen12 = APIntOps::smin(autogen6,autogen6);
	APInt autogen13;
	if (autogen12 == 0) {
		autogen13 = autogen11;
	} else {
		autogen13 = autogen11.urem(autogen12);
	}
	APInt autogen14;
	if (autogen9.uge(autogen9.getBitWidth())) {
		autogen14 = APInt(autogen10.getBitWidth(), 0);
	} else {
		autogen14 = autogen10.shl(autogen9.getZExtValue());
	}
	autogen1[0] = autogen14;
	autogen1[1] = autogen13;
}

extern "C" void shl_partial_solution_3_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen6(autogen4.getBitWidth(),0);
	APInt autogen7(autogen4.getBitWidth(),1);
	unsigned autogen8_autocast = autogen4.getBitWidth();
	APInt autogen8(autogen4.getBitWidth(),autogen8_autocast);
	APInt autogen9 = APIntOps::umin(autogen3,autogen2);
	APInt autogen10 = autogen2;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen10.setHighBits(autogen7.getZExtValue());
	else
		autogen10.setHighBits(autogen7.getBitWidth());
	APInt autogen11;
	if (autogen6.uge(autogen6.getBitWidth()) && autogen5.isSignBitSet()) {
		autogen11 = APInt(autogen5.getBitWidth(), -1);
	} else if (autogen6.uge(autogen6.getBitWidth()) && autogen5.isSignBitClear()) {
		autogen11 = APInt(autogen5.getBitWidth(), 0);
	} else {
		autogen11 = autogen5.ashr(autogen6.getZExtValue());
	}
	APInt autogen12;
	if (autogen5 == 0) {
		autogen12 = autogen10;
	} else {
		autogen12 = autogen10.urem(autogen5);
	}
	unsigned autogen13_autocast = autogen4.countl_zero();
	APInt autogen13(autogen4.getBitWidth(),autogen13_autocast);
	APInt autogen14;
	if (autogen10 == 0) {
		autogen14 = APInt(autogen9.getBitWidth(), -1);
	} else {
		autogen14 = autogen9.udiv(autogen10);
	}
	unsigned autogen15_autocast = autogen12.countr_one();
	APInt autogen15(autogen12.getBitWidth(),autogen15_autocast);
	APInt autogen16 = autogen13-autogen15;
	APInt autogen17 = autogen14;
	if (autogen8.ule(autogen8.getBitWidth()))
		autogen17.clearLowBits(autogen8.getZExtValue());
	else
		autogen17.clearLowBits(autogen8.getBitWidth());
	APInt autogen18 = autogen11;
	if (autogen16.ule(autogen16.getBitWidth()))
		autogen18.clearHighBits(autogen16.getZExtValue());
	else
		autogen18.clearHighBits(autogen16.getBitWidth());
	autogen1[0] = autogen18;
	autogen1[1] = autogen17;
}

extern "C" void shl_partial_solution_4_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),0);
	APInt autogen7(autogen4.getBitWidth(),1);
	unsigned autogen8_autocast = autogen4.getBitWidth();
	APInt autogen8(autogen4.getBitWidth(),autogen8_autocast);
	APInt autogen9 = APIntOps::umin(autogen8,autogen7);
	APInt autogen10 = autogen4;
	autogen10.setSignBit();
	unsigned autogen11_autocast = autogen10.countr_one();
	APInt autogen11(autogen10.getBitWidth(),autogen11_autocast);
	APInt autogen12;
	if (autogen4 == 0) {
		autogen12 = autogen5;
	} else {
		autogen12 = autogen5.srem(autogen4);
	}
	unsigned autogen13_autocast = autogen4.countr_one();
	APInt autogen13(autogen4.getBitWidth(),autogen13_autocast);
	APInt autogen14;
	if (autogen11.uge(autogen11.getBitWidth())) {
		autogen14 = APInt(autogen2.getBitWidth(), 0);
	} else {
		autogen14 = autogen2.shl(autogen11.getZExtValue());
	}
	int autogen15 = autogen11.ule(autogen9);
	APInt autogen16;
	if (autogen12 == 0) {
		autogen16 = autogen14;
	} else {
		autogen16 = autogen14.urem(autogen12);
	}
	APInt autogen17 = autogen15 ? autogen6 : autogen13 ;
	APInt autogen18;
	if (autogen13.uge(autogen13.getBitWidth())) {
		autogen18 = APInt(autogen3.getBitWidth(), 0);
	} else {
		autogen18 = autogen3.shl(autogen13.getZExtValue());
	}
	APInt autogen19 = autogen16;
	if (autogen17.ule(autogen17.getBitWidth()))
		autogen19.clearLowBits(autogen17.getZExtValue());
	else
		autogen19.clearLowBits(autogen17.getBitWidth());
	autogen1[0] = autogen19;
	autogen1[1] = autogen18;
}

extern "C" void shl_partial_solution_4_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[0];
	APInt autogen5 = autogen1[1];
	APInt autogen6(autogen5.getBitWidth(),0);
	APInt autogen7 = APInt::getAllOnes(autogen5.getBitWidth());
	APInt autogen8 = APIntOps::umax(autogen4,autogen3);
	int autogen9 = autogen8.eq(autogen7);
	int autogen10 = autogen6.ule(autogen8);
	int autogen11 = autogen9&autogen10;
	autogen2[0] = autogen11|autogen9;
}

extern "C" void shl_partial_solution_5_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),1);
	APInt autogen5 = APInt::getAllOnes(autogen3.getBitWidth());
	APInt autogen6(autogen3.getBitWidth(),1);
	unsigned autogen7_autocast = autogen3.getBitWidth();
	APInt autogen7(autogen3.getBitWidth(),autogen7_autocast);
	APInt autogen8 = APIntOps::smin(autogen3,autogen2);
	APInt autogen9;
	if (autogen3 == 0) {
		autogen9 = APInt(autogen5.getBitWidth(), -1);
	} else {
		autogen9 = autogen5.udiv(autogen3);
	}
	APInt autogen10 = autogen2^autogen8;
	APInt autogen11 = autogen4;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen11.clearHighBits(autogen6.getZExtValue());
	else
		autogen11.clearHighBits(autogen6.getBitWidth());
	APInt autogen12;
	if (autogen3 == 0) {
		autogen12 = APInt(autogen9.getBitWidth(), -1);
	} else {
		autogen12 = autogen9.udiv(autogen3);
	}
	APInt autogen13;
	if (autogen7.uge(autogen7.getBitWidth())) {
		autogen13 = APInt(autogen11.getBitWidth(), 0);
	} else {
		autogen13 = autogen11.lshr(autogen7.getZExtValue());
	}
	APInt autogen14;
	if (autogen12 == 0) {
		autogen14 = APInt(autogen10.getBitWidth(), -1);
	} else {
		autogen14 = autogen10.udiv(autogen12);
	}
	autogen1[0] = autogen14;
	autogen1[1] = autogen13;
}

extern "C" void shl_partial_solution_6_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),0);
	APInt autogen7 = APInt::getAllOnes(autogen5.getBitWidth());
	APInt autogen8(autogen5.getBitWidth(),1);
	int autogen9 = autogen7.ule(autogen3);
	APInt autogen10 = autogen9 ? autogen6 : autogen7 ;
	APInt autogen11 = autogen10;
	if (autogen8.ule(autogen8.getBitWidth()))
		autogen11.setLowBits(autogen8.getZExtValue());
	else
		autogen11.setLowBits(autogen8.getBitWidth());
	unsigned autogen12_autocast = autogen5.countr_one();
	APInt autogen12(autogen5.getBitWidth(),autogen12_autocast);
	APInt autogen13;
	if (autogen11 == 0) {
		autogen13 = autogen6;
	} else {
		autogen13 = autogen6.srem(autogen11);
	}
	unsigned autogen14_autocast = autogen10.countr_one();
	APInt autogen14(autogen10.getBitWidth(),autogen14_autocast);
	APInt autogen15 = autogen2+autogen13;
	APInt autogen16 = autogen4;
	if (autogen14.ule(autogen14.getBitWidth()))
		autogen16.clearLowBits(autogen14.getZExtValue());
	else
		autogen16.clearLowBits(autogen14.getBitWidth());
	APInt autogen17;
	if (autogen12.uge(autogen12.getBitWidth())) {
		autogen17 = APInt(autogen15.getBitWidth(), 0);
	} else {
		autogen17 = autogen15.shl(autogen12.getZExtValue());
	}
	autogen1[0] = autogen17;
	autogen1[1] = autogen16;
}

extern "C" void shl_partial_solution_6_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7 = autogen3;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen7.setHighBits(autogen6.getZExtValue());
	else
		autogen7.setHighBits(autogen6.getBitWidth());
	int autogen8 = autogen5.eq(autogen7);
	int autogen9 = autogen8&autogen8;
	autogen2[0] = autogen8|autogen9;
}

extern "C" void shl_partial_solution_7_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	unsigned autogen7_autocast = autogen4.getBitWidth();
	APInt autogen7(autogen4.getBitWidth(),autogen7_autocast);
	unsigned autogen8_autocast = autogen3.countl_zero();
	APInt autogen8(autogen3.getBitWidth(),autogen8_autocast);
	APInt autogen9 = autogen2;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen9.setHighBits(autogen7.getZExtValue());
	else
		autogen9.setHighBits(autogen7.getBitWidth());
	APInt autogen10 = autogen4;
	if (autogen8.ule(autogen8.getBitWidth()))
		autogen10.clearHighBits(autogen8.getZExtValue());
	else
		autogen10.clearHighBits(autogen8.getBitWidth());
	APInt autogen11;
	if (autogen10.isMinSignedValue() && autogen10 == -1) {
		autogen11 = APInt::getSignedMinValue(autogen10.getBitWidth());
	} else if (autogen10 == 0 && autogen10.isNonNegative()) {
		autogen11 = APInt(autogen10.getBitWidth(), -1);
	} else if (autogen10 == 0 && autogen10.isNegative()) {
		autogen11 = APInt(autogen10.getBitWidth(), 1);
	} else {
		autogen11 = autogen10.sdiv(autogen10);
	}
	unsigned autogen12_autocast = autogen10.countr_zero();
	APInt autogen12(autogen10.getBitWidth(),autogen12_autocast);
	APInt autogen13;
	if (autogen11 == 0) {
		autogen13 = APInt(autogen4.getBitWidth(), -1);
	} else {
		autogen13 = autogen4.udiv(autogen11);
	}
	APInt autogen14;
	if (autogen9 == 0) {
		autogen14 = autogen5;
	} else {
		autogen14 = autogen5.urem(autogen9);
	}
	APInt autogen15 = autogen14;
	if (autogen12.ule(autogen12.getBitWidth()))
		autogen15.setLowBits(autogen12.getZExtValue());
	else
		autogen15.setLowBits(autogen12.getBitWidth());
	APInt autogen16;
	if (autogen6.uge(autogen6.getBitWidth())) {
		autogen16 = APInt(autogen3.getBitWidth(), 0);
	} else {
		autogen16 = autogen3.shl(autogen6.getZExtValue());
	}
	unsigned autogen17_autocast = autogen15.countl_zero();
	APInt autogen17(autogen15.getBitWidth(),autogen17_autocast);
	APInt autogen18 = autogen16*autogen13;
	APInt autogen19 = autogen2;
	if (autogen17.ule(autogen17.getBitWidth()))
		autogen19.clearHighBits(autogen17.getZExtValue());
	else
		autogen19.clearHighBits(autogen17.getBitWidth());
	autogen1[0] = autogen19;
	autogen1[1] = autogen18;
}

extern "C" void shl_partial_solution_7_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen1[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen6 = autogen3;
	autogen6.setSignBit();
	autogen2[0] = autogen5.ule(autogen6);
}

extern "C" void shl_partial_solution_8_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7(autogen4.getBitWidth(),0);
	APInt autogen8(autogen4.getBitWidth(),1);
	unsigned autogen9_autocast = autogen4.getBitWidth();
	APInt autogen9(autogen4.getBitWidth(),autogen9_autocast);
	int autogen10 = autogen9.ult(autogen7);
	int autogen11 = autogen4.eq(autogen3);
	unsigned autogen12_autocast = autogen2.countl_one();
	APInt autogen12(autogen2.getBitWidth(),autogen12_autocast);
	APInt autogen13;
	if (autogen2 == 0) {
		autogen13 = APInt(autogen2.getBitWidth(), -1);
	} else {
		autogen13 = autogen2.udiv(autogen2);
	}
	APInt autogen14 = autogen5;
	if (autogen9.ule(autogen9.getBitWidth()))
		autogen14.setLowBits(autogen9.getZExtValue());
	else
		autogen14.setLowBits(autogen9.getBitWidth());
	APInt autogen15 = APIntOps::umax(autogen8,autogen12);
	APInt autogen16 = autogen10 ? autogen15 : autogen8 ;
	APInt autogen17 = autogen14*autogen3;
	APInt autogen18 = APIntOps::smax(autogen13,autogen4);
	APInt autogen19 = autogen18-autogen6;
	APInt autogen20 = autogen11 ? autogen16 : autogen9 ;
	APInt autogen21 = APIntOps::smax(autogen17,autogen13);
	APInt autogen22 = autogen21;
	if (autogen20.ule(autogen20.getBitWidth()))
		autogen22.clearLowBits(autogen20.getZExtValue());
	else
		autogen22.clearLowBits(autogen20.getBitWidth());
	APInt autogen23 = autogen18*autogen19;
	autogen1[0] = autogen23;
	autogen1[1] = autogen22;
}

extern "C" void shl_partial_solution_9_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen8(autogen4.getBitWidth(),1);
	unsigned autogen9_autocast = autogen4.getBitWidth();
	APInt autogen9(autogen4.getBitWidth(),autogen9_autocast);
	APInt autogen10 = APIntOps::umin(autogen8,autogen9);
	APInt autogen11;
	if (autogen4 == 0) {
		autogen11 = autogen2;
	} else {
		autogen11 = autogen2.urem(autogen4);
	}
	APInt autogen12 = autogen6;
	if (autogen8.ule(autogen8.getBitWidth()))
		autogen12.clearLowBits(autogen8.getZExtValue());
	else
		autogen12.clearLowBits(autogen8.getBitWidth());
	APInt autogen13 = autogen6&autogen11;
	APInt autogen14 = APIntOps::smax(autogen5,autogen7);
	int autogen15 = autogen9.eq(autogen10);
	APInt autogen16 = APIntOps::umin(autogen2,autogen12);
	APInt autogen17;
	if (autogen4 == 0) {
		autogen17 = APInt(autogen14.getBitWidth(), -1);
	} else {
		autogen17 = autogen14.udiv(autogen4);
	}
	APInt autogen18 = ~autogen17;
	unsigned autogen19_autocast = autogen3.countr_zero();
	APInt autogen19(autogen3.getBitWidth(),autogen19_autocast);
	APInt autogen20 = APIntOps::smin(autogen13,autogen2);
	APInt autogen21 = autogen15 ? autogen13 : autogen20 ;
	int autogen22 = autogen19.ule(autogen19);
	APInt autogen23 = APIntOps::smax(autogen13,autogen2);
	APInt autogen24 = autogen22 ? autogen16 : autogen23 ;
	APInt autogen25 = APIntOps::umax(autogen21,autogen18);
	autogen1[0] = autogen25;
	autogen1[1] = autogen24;
}

extern "C" void shl_partial_solution_9_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen6 = autogen3;
	autogen6.setSignBit();
	autogen2[0] = autogen6.eq(autogen5);
}

extern "C" void shl_partial_solution_10_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = autogen0[1];
	APInt autogen3 = APInt::getAllOnes(autogen2.getBitWidth());
	APInt autogen4(autogen2.getBitWidth(),1);
	APInt autogen5 = autogen2;
	if (autogen4.ule(autogen4.getBitWidth()))
		autogen5.clearHighBits(autogen4.getZExtValue());
	else
		autogen5.clearHighBits(autogen4.getBitWidth());
	APInt autogen6 = autogen3+autogen5;
	APInt autogen7;
	if (autogen6 == 0) {
		autogen7 = autogen3;
	} else {
		autogen7 = autogen3.urem(autogen6);
	}
	APInt autogen8 = autogen2;
	autogen8.clearSignBit();
	APInt autogen9 = autogen7*autogen8;
	APInt autogen10;
	if (autogen8 == 0) {
		autogen10 = autogen9;
	} else {
		autogen10 = autogen9.srem(autogen8);
	}
	APInt autogen11 = APIntOps::smax(autogen3,autogen2);
	autogen1[0] = autogen11;
	autogen1[1] = autogen10;
}

extern "C" void shl_partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_partial_solution_0_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_partial_solution_1(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_partial_solution_1_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_partial_solution_2(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_partial_solution_2_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_partial_solution_3(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_partial_solution_3_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_partial_solution_4(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	shl_partial_solution_4_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	shl_partial_solution_4_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void shl_partial_solution_5(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_partial_solution_5_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_partial_solution_6(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	shl_partial_solution_6_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	shl_partial_solution_6_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void shl_partial_solution_7(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	shl_partial_solution_7_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	shl_partial_solution_7_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void shl_partial_solution_8(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_partial_solution_8_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_partial_solution_9(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	shl_partial_solution_9_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	shl_partial_solution_9_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void shl_partial_solution_10(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_partial_solution_10_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_solution(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	shl_partial_solution_0(autogen0,autogen1, autogen3);
	APInt autogen4[2];
	shl_partial_solution_1(autogen0,autogen1, autogen4);
	APInt autogen5[2];
	shl_partial_solution_2(autogen0,autogen1, autogen5);
	APInt autogen6[2];
	shl_partial_solution_3(autogen0,autogen1, autogen6);
	APInt autogen7[2];
	shl_partial_solution_4(autogen0,autogen1, autogen7);
	APInt autogen8[2];
	shl_partial_solution_5(autogen0,autogen1, autogen8);
	APInt autogen9[2];
	shl_partial_solution_6(autogen0,autogen1, autogen9);
	APInt autogen10[2];
	shl_partial_solution_7(autogen0,autogen1, autogen10);
	APInt autogen11[2];
	shl_partial_solution_8(autogen0,autogen1, autogen11);
	APInt autogen12[2];
	shl_partial_solution_9(autogen0,autogen1, autogen12);
	APInt autogen13[2];
	shl_partial_solution_10(autogen0,autogen1, autogen13);
	APInt autogen14[2];
	tf_meet(autogen3,autogen4, autogen14);
	APInt autogen15[2];
	tf_meet(autogen14,autogen5, autogen15);
	APInt autogen16[2];
	tf_meet(autogen15,autogen6, autogen16);
	APInt autogen17[2];
	tf_meet(autogen16,autogen7, autogen17);
	APInt autogen18[2];
	tf_meet(autogen17,autogen8, autogen18);
	APInt autogen19[2];
	tf_meet(autogen18,autogen9, autogen19);
	APInt autogen20[2];
	tf_meet(autogen19,autogen10, autogen20);
	APInt autogen21[2];
	tf_meet(autogen20,autogen11, autogen21);
	APInt autogen22[2];
	tf_meet(autogen21,autogen12, autogen22);
	tf_meet(autogen22,autogen13, autogen2);
}

