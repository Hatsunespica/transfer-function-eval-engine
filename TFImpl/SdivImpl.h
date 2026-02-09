extern "C" void sdiv_partial_solution_0_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = autogen0[0];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),0);
	APInt autogen5(autogen3.getBitWidth(),1);
	APInt autogen6 = APInt::getAllOnes(autogen3.getBitWidth());
	unsigned autogen7_autocast = autogen3.getBitWidth();
	APInt autogen7(autogen3.getBitWidth(),autogen7_autocast);
	unsigned autogen8_autocast = autogen2.countl_zero();
	APInt autogen8(autogen2.getBitWidth(),autogen8_autocast);
	APInt autogen9 = autogen5^autogen3;
	unsigned autogen10_autocast = autogen9.countl_zero();
	APInt autogen10(autogen9.getBitWidth(),autogen10_autocast);
	APInt autogen11;
	if (autogen7.uge(autogen7.getBitWidth())) {
		autogen11 = APInt(autogen9.getBitWidth(), 0);
	} else {
		autogen11 = autogen9.shl(autogen7.getZExtValue());
	}
	APInt autogen12;
	if (autogen4.isMinSignedValue() && autogen2 == -1) {
		autogen12 = APInt::getSignedMinValue(autogen4.getBitWidth());
	} else if (autogen2 == 0 && autogen4.isNonNegative()) {
		autogen12 = APInt(autogen4.getBitWidth(), -1);
	} else if (autogen2 == 0 && autogen4.isNegative()) {
		autogen12 = APInt(autogen4.getBitWidth(), 1);
	} else {
		autogen12 = autogen4.sdiv(autogen2);
	}
	APInt autogen13;
	if (autogen2.isMinSignedValue() && autogen11 == -1) {
		autogen13 = APInt::getSignedMinValue(autogen2.getBitWidth());
	} else if (autogen11 == 0 && autogen2.isNonNegative()) {
		autogen13 = APInt(autogen2.getBitWidth(), -1);
	} else if (autogen11 == 0 && autogen2.isNegative()) {
		autogen13 = APInt(autogen2.getBitWidth(), 1);
	} else {
		autogen13 = autogen2.sdiv(autogen11);
	}
	APInt autogen14 = autogen12;
	autogen14.clearSignBit();
	APInt autogen15 = autogen8+autogen10;
	APInt autogen16;
	if (autogen14.isMinSignedValue() && autogen13 == -1) {
		autogen16 = APInt::getSignedMinValue(autogen14.getBitWidth());
	} else if (autogen13 == 0 && autogen14.isNonNegative()) {
		autogen16 = APInt(autogen14.getBitWidth(), -1);
	} else if (autogen13 == 0 && autogen14.isNegative()) {
		autogen16 = APInt(autogen14.getBitWidth(), 1);
	} else {
		autogen16 = autogen14.sdiv(autogen13);
	}
	APInt autogen17 = autogen6;
	if (autogen15.ule(autogen15.getBitWidth()))
		autogen17.clearLowBits(autogen15.getZExtValue());
	else
		autogen17.clearLowBits(autogen15.getBitWidth());
	autogen1[0] = autogen17;
	autogen1[1] = autogen16;
}

extern "C" void sdiv_partial_solution_0_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[0];
	APInt autogen5 = autogen1[1];
	APInt autogen6 = APInt::getAllOnes(autogen5.getBitWidth());
	APInt autogen7 = autogen6-autogen3;
	APInt autogen8 = APIntOps::umin(autogen3,autogen4);
	autogen2[0] = autogen7.ult(autogen8);
}

extern "C" void sdiv_partial_solution_1_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	APInt autogen6(autogen4.getBitWidth(),1);
	unsigned autogen7_autocast = autogen4.getBitWidth();
	APInt autogen7(autogen4.getBitWidth(),autogen7_autocast);
	int autogen8 = autogen2.ule(autogen3);
	APInt autogen9 = autogen5^autogen4;
	APInt autogen10 = ~autogen5;
	APInt autogen11 = ~autogen10;
	APInt autogen12 = autogen11*autogen3;
	APInt autogen13 = autogen8 ? autogen4 : autogen12 ;
	APInt autogen14 = autogen7+autogen6;
	APInt autogen15 = APIntOps::smin(autogen3,autogen13);
	APInt autogen16 = autogen9;
	if (autogen14.ule(autogen14.getBitWidth()))
		autogen16.setLowBits(autogen14.getZExtValue());
	else
		autogen16.setLowBits(autogen14.getBitWidth());
	unsigned autogen17_autocast = autogen13.countl_zero();
	APInt autogen17(autogen13.getBitWidth(),autogen17_autocast);
	APInt autogen18;
	if (autogen10 == 0) {
		autogen18 = APInt(autogen15.getBitWidth(), -1);
	} else {
		autogen18 = autogen15.udiv(autogen10);
	}
	APInt autogen19;
	if (autogen17.uge(autogen17.getBitWidth())) {
		autogen19 = APInt(autogen16.getBitWidth(), 0);
	} else {
		autogen19 = autogen16.shl(autogen17.getZExtValue());
	}
	autogen1[0] = autogen19;
	autogen1[1] = autogen18;
}

extern "C" void sdiv_partial_solution_1_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[1];
	APInt autogen4 = autogen1[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7 = autogen3;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen7.setHighBits(autogen6.getZExtValue());
	else
		autogen7.setHighBits(autogen6.getBitWidth());
	APInt autogen8;
	if (autogen7 == 0) {
		autogen8 = APInt(autogen3.getBitWidth(), -1);
	} else {
		autogen8 = autogen3.udiv(autogen7);
	}
	APInt autogen9;
	if (autogen4.isMinSignedValue() && autogen5 == -1) {
		autogen9 = APInt::getSignedMinValue(autogen4.getBitWidth());
	} else if (autogen5 == 0 && autogen4.isNonNegative()) {
		autogen9 = APInt(autogen4.getBitWidth(), -1);
	} else if (autogen5 == 0 && autogen4.isNegative()) {
		autogen9 = APInt(autogen4.getBitWidth(), 1);
	} else {
		autogen9 = autogen4.sdiv(autogen5);
	}
	autogen2[0] = autogen9.eq(autogen8);
}

extern "C" void sdiv_partial_solution_2_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	unsigned autogen6_autocast = autogen4.getBitWidth();
	APInt autogen6(autogen4.getBitWidth(),autogen6_autocast);
	APInt autogen7 = ~autogen2;
	APInt autogen8 = APIntOps::umax(autogen6,autogen5);
	APInt autogen9;
	if (autogen3 == 0) {
		autogen9 = APInt(autogen7.getBitWidth(), -1);
	} else {
		autogen9 = autogen7.udiv(autogen3);
	}
	APInt autogen10;
	if (autogen8.uge(autogen8.getBitWidth())) {
		autogen10 = APInt(autogen3.getBitWidth(), 0);
	} else {
		autogen10 = autogen3.shl(autogen8.getZExtValue());
	}
	unsigned autogen11_autocast = autogen9.countl_zero();
	APInt autogen11(autogen9.getBitWidth(),autogen11_autocast);
	APInt autogen12 = autogen10;
	autogen12.setSignBit();
	APInt autogen13 = autogen10*autogen7;
	APInt autogen14 = autogen12;
	if (autogen11.ule(autogen11.getBitWidth()))
		autogen14.setHighBits(autogen11.getZExtValue());
	else
		autogen14.setHighBits(autogen11.getBitWidth());
	autogen1[0] = autogen14;
	autogen1[1] = autogen13;
}

extern "C" void sdiv_partial_solution_2_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen1[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen6(autogen4.getBitWidth(),0);
	APInt autogen7(autogen4.getBitWidth(),1);
	APInt autogen8 = autogen5;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen8.clearHighBits(autogen7.getZExtValue());
	else
		autogen8.clearHighBits(autogen7.getBitWidth());
	int autogen9 = autogen6.ult(autogen7);
	APInt autogen10 = autogen9 ? autogen3 : autogen8 ;
	autogen2[0] = autogen8.eq(autogen10);
}

extern "C" void sdiv_partial_solution_3_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),1);
	APInt autogen5 = APInt::getAllOnes(autogen3.getBitWidth());
	APInt autogen6(autogen3.getBitWidth(),1);
	unsigned autogen7_autocast = autogen3.getBitWidth();
	APInt autogen7(autogen3.getBitWidth(),autogen7_autocast);
	APInt autogen8 = autogen4;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen8.clearHighBits(autogen7.getZExtValue());
	else
		autogen8.clearHighBits(autogen7.getBitWidth());
	unsigned autogen9_autocast = autogen8.countr_one();
	APInt autogen9(autogen8.getBitWidth(),autogen9_autocast);
	APInt autogen10;
	if (autogen4.isMinSignedValue() && autogen4 == -1) {
		autogen10 = APInt::getSignedMinValue(autogen4.getBitWidth());
	} else if (autogen4 == 0 && autogen4.isNonNegative()) {
		autogen10 = APInt(autogen4.getBitWidth(), -1);
	} else if (autogen4 == 0 && autogen4.isNegative()) {
		autogen10 = APInt(autogen4.getBitWidth(), 1);
	} else {
		autogen10 = autogen4.sdiv(autogen4);
	}
	APInt autogen11 = APIntOps::umax(autogen2,autogen10);
	APInt autogen12 = autogen11;
	if (autogen9.ule(autogen9.getBitWidth()))
		autogen12.setLowBits(autogen9.getZExtValue());
	else
		autogen12.setLowBits(autogen9.getBitWidth());
	APInt autogen13 = autogen5+autogen4;
	unsigned autogen14_autocast = autogen11.countr_one();
	APInt autogen14(autogen11.getBitWidth(),autogen14_autocast);
	APInt autogen15;
	if (autogen14.uge(autogen14.getBitWidth())) {
		autogen15 = APInt(autogen12.getBitWidth(), 0);
	} else {
		autogen15 = autogen12.shl(autogen14.getZExtValue());
	}
	APInt autogen16;
	if (autogen5 == 0) {
		autogen16 = APInt(autogen8.getBitWidth(), -1);
	} else {
		autogen16 = autogen8.udiv(autogen5);
	}
	APInt autogen17;
	if (autogen6.uge(autogen6.getBitWidth())) {
		autogen17 = APInt(autogen16.getBitWidth(), 0);
	} else {
		autogen17 = autogen16.shl(autogen6.getZExtValue());
	}
	APInt autogen18;
	if (autogen15 == 0) {
		autogen18 = APInt(autogen13.getBitWidth(), -1);
	} else {
		autogen18 = autogen13.udiv(autogen15);
	}
	autogen1[0] = autogen18;
	autogen1[1] = autogen17;
}

extern "C" void sdiv_partial_solution_4_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen8(autogen4.getBitWidth(),0);
	unsigned autogen9_autocast = autogen4.getBitWidth();
	APInt autogen9(autogen4.getBitWidth(),autogen9_autocast);
	int autogen10 = autogen5.ule(autogen4);
	APInt autogen11 = autogen9-autogen9;
	APInt autogen12 = autogen7+autogen7;
	APInt autogen13 = autogen2+autogen6;
	APInt autogen14 = autogen10 ? autogen8 : autogen11 ;
	APInt autogen15 = autogen13;
	autogen15.setSignBit();
	APInt autogen16 = ~autogen12;
	unsigned autogen17_autocast = autogen15.countl_zero();
	APInt autogen17(autogen15.getBitWidth(),autogen17_autocast);
	unsigned autogen18_autocast = autogen3.countl_zero();
	APInt autogen18(autogen3.getBitWidth(),autogen18_autocast);
	APInt autogen19 = autogen16;
	if (autogen11.ule(autogen11.getBitWidth()))
		autogen19.setLowBits(autogen11.getZExtValue());
	else
		autogen19.setLowBits(autogen11.getBitWidth());
	APInt autogen20 = autogen14-autogen17;
	APInt autogen21 = autogen20+autogen18;
	APInt autogen22;
	if (autogen19 == 0) {
		autogen22 = autogen15;
	} else {
		autogen22 = autogen15.srem(autogen19);
	}
	APInt autogen23 = autogen12;
	if (autogen21.ule(autogen21.getBitWidth()))
		autogen23.clearLowBits(autogen21.getZExtValue());
	else
		autogen23.clearLowBits(autogen21.getBitWidth());
	autogen1[0] = autogen23;
	autogen1[1] = autogen22;
}

extern "C" void sdiv_partial_solution_4_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	APInt autogen6 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen7 = autogen6-autogen5;
	int autogen8 = autogen6.ule(autogen6);
	int autogen9 = autogen7.eq(autogen3);
	autogen2[0] = autogen9&autogen8;
}

extern "C" void sdiv_partial_solution_5_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),0);
	APInt autogen7 = APInt::getAllOnes(autogen5.getBitWidth());
	APInt autogen8(autogen5.getBitWidth(),1);
	APInt autogen9;
	if (autogen5 == 0) {
		autogen9 = autogen7;
	} else {
		autogen9 = autogen7.srem(autogen5);
	}
	APInt autogen10;
	if (autogen6 == 0) {
		autogen10 = autogen2;
	} else {
		autogen10 = autogen2.srem(autogen6);
	}
	unsigned autogen11_autocast = autogen4.countl_zero();
	APInt autogen11(autogen4.getBitWidth(),autogen11_autocast);
	APInt autogen12 = APIntOps::umax(autogen11,autogen8);
	APInt autogen13 = APIntOps::umax(autogen12,autogen11);
	APInt autogen14 = autogen9;
	if (autogen13.ule(autogen13.getBitWidth()))
		autogen14.setLowBits(autogen13.getZExtValue());
	else
		autogen14.setLowBits(autogen13.getBitWidth());
	APInt autogen15 = ~autogen4;
	APInt autogen16 = APIntOps::umin(autogen10,autogen3);
	APInt autogen17;
	if (autogen15 == 0) {
		autogen17 = APInt(autogen16.getBitWidth(), -1);
	} else {
		autogen17 = autogen16.udiv(autogen15);
	}
	APInt autogen18 = autogen14;
	if (autogen12.ule(autogen12.getBitWidth()))
		autogen18.clearLowBits(autogen12.getZExtValue());
	else
		autogen18.clearLowBits(autogen12.getBitWidth());
	autogen1[0] = autogen18;
	autogen1[1] = autogen17;
}

extern "C" void sdiv_partial_solution_5_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = autogen1[1];
	APInt autogen6 = APInt::getAllOnes(autogen5.getBitWidth());
	int autogen7 = autogen6.ule(autogen4);
	int autogen8 = autogen3.ult(autogen5);
	autogen2[0] = autogen7&autogen8;
}

extern "C" void sdiv_partial_solution_6_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = autogen0[0];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),0);
	APInt autogen5(autogen3.getBitWidth(),1);
	APInt autogen6(autogen3.getBitWidth(),1);
	unsigned autogen7_autocast = autogen3.getBitWidth();
	APInt autogen7(autogen3.getBitWidth(),autogen7_autocast);
	int autogen8 = autogen6.eq(autogen7);
	unsigned autogen9_autocast = autogen2.countr_zero();
	APInt autogen9(autogen2.getBitWidth(),autogen9_autocast);
	APInt autogen10 = APIntOps::umax(autogen5,autogen2);
	APInt autogen11 = APIntOps::umax(autogen6,autogen7);
	APInt autogen12 = autogen6-autogen9;
	APInt autogen13 = autogen8 ? autogen12 : autogen11 ;
	APInt autogen14 = APIntOps::umin(autogen10,autogen3);
	APInt autogen15 = autogen3;
	if (autogen13.ule(autogen13.getBitWidth()))
		autogen15.setHighBits(autogen13.getZExtValue());
	else
		autogen15.setHighBits(autogen13.getBitWidth());
	APInt autogen16;
	if (autogen7.uge(autogen7.getBitWidth()) && autogen4.isSignBitSet()) {
		autogen16 = APInt(autogen4.getBitWidth(), -1);
	} else if (autogen7.uge(autogen7.getBitWidth()) && autogen4.isSignBitClear()) {
		autogen16 = APInt(autogen4.getBitWidth(), 0);
	} else {
		autogen16 = autogen4.ashr(autogen7.getZExtValue());
	}
	unsigned autogen17_autocast = autogen14.countl_zero();
	APInt autogen17(autogen14.getBitWidth(),autogen17_autocast);
	APInt autogen18;
	if (autogen12.uge(autogen12.getBitWidth()) && autogen16.isSignBitSet()) {
		autogen18 = APInt(autogen16.getBitWidth(), -1);
	} else if (autogen12.uge(autogen12.getBitWidth()) && autogen16.isSignBitClear()) {
		autogen18 = APInt(autogen16.getBitWidth(), 0);
	} else {
		autogen18 = autogen16.ashr(autogen12.getZExtValue());
	}
	APInt autogen19 = APIntOps::umin(autogen18,autogen2);
	APInt autogen20 = autogen15;
	if (autogen17.ule(autogen17.getBitWidth()))
		autogen20.clearLowBits(autogen17.getZExtValue());
	else
		autogen20.clearLowBits(autogen17.getBitWidth());
	autogen1[0] = autogen20;
	autogen1[1] = autogen19;
}

extern "C" void sdiv_partial_solution_6_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[0];
	APInt autogen5 = autogen1[1];
	APInt autogen6(autogen5.getBitWidth(),0);
	APInt autogen7 = APIntOps::smin(autogen6,autogen3);
	int autogen8 = autogen5.ule(autogen7);
	APInt autogen9;
	if (autogen4 == 0) {
		autogen9 = APInt(autogen3.getBitWidth(), -1);
	} else {
		autogen9 = autogen3.udiv(autogen4);
	}
	int autogen10 = autogen9.eq(autogen6);
	autogen2[0] = autogen8&autogen10;
}

extern "C" void sdiv_partial_solution_7_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),0);
	APInt autogen7 = APInt::getAllOnes(autogen5.getBitWidth());
	APInt autogen8(autogen5.getBitWidth(),1);
	APInt autogen9;
	if (autogen5 == 0) {
		autogen9 = autogen7;
	} else {
		autogen9 = autogen7.srem(autogen5);
	}
	APInt autogen10;
	if (autogen6 == 0) {
		autogen10 = autogen2;
	} else {
		autogen10 = autogen2.srem(autogen6);
	}
	unsigned autogen11_autocast = autogen4.countl_zero();
	APInt autogen11(autogen4.getBitWidth(),autogen11_autocast);
	APInt autogen12 = APIntOps::umax(autogen11,autogen8);
	APInt autogen13 = APIntOps::umax(autogen12,autogen11);
	APInt autogen14 = autogen9;
	if (autogen13.ule(autogen13.getBitWidth()))
		autogen14.setLowBits(autogen13.getZExtValue());
	else
		autogen14.setLowBits(autogen13.getBitWidth());
	APInt autogen15 = ~autogen4;
	APInt autogen16 = APIntOps::umin(autogen10,autogen3);
	APInt autogen17;
	if (autogen15 == 0) {
		autogen17 = APInt(autogen16.getBitWidth(), -1);
	} else {
		autogen17 = autogen16.udiv(autogen15);
	}
	APInt autogen18 = autogen14;
	if (autogen12.ule(autogen12.getBitWidth()))
		autogen18.clearLowBits(autogen12.getZExtValue());
	else
		autogen18.clearLowBits(autogen12.getBitWidth());
	autogen1[0] = autogen18;
	autogen1[1] = autogen17;
}

extern "C" void sdiv_partial_solution_7_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen1[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen6(autogen4.getBitWidth(),1);
	unsigned autogen7_autocast = autogen4.getBitWidth();
	APInt autogen7(autogen4.getBitWidth(),autogen7_autocast);
	int autogen8 = autogen7.eq(autogen6);
	APInt autogen9 = autogen5;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen9.clearHighBits(autogen6.getZExtValue());
	else
		autogen9.clearHighBits(autogen6.getBitWidth());
	int autogen10 = autogen3.eq(autogen9);
	autogen2[0] = autogen8|autogen10;
}

extern "C" void sdiv_partial_solution_8_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	unsigned autogen6_autocast = autogen4.getBitWidth();
	APInt autogen6(autogen4.getBitWidth(),autogen6_autocast);
	APInt autogen7 = ~autogen2;
	APInt autogen8 = APIntOps::umax(autogen6,autogen5);
	APInt autogen9;
	if (autogen3 == 0) {
		autogen9 = APInt(autogen7.getBitWidth(), -1);
	} else {
		autogen9 = autogen7.udiv(autogen3);
	}
	APInt autogen10;
	if (autogen8.uge(autogen8.getBitWidth())) {
		autogen10 = APInt(autogen3.getBitWidth(), 0);
	} else {
		autogen10 = autogen3.shl(autogen8.getZExtValue());
	}
	unsigned autogen11_autocast = autogen9.countl_zero();
	APInt autogen11(autogen9.getBitWidth(),autogen11_autocast);
	APInt autogen12 = autogen10;
	autogen12.setSignBit();
	APInt autogen13 = autogen10*autogen7;
	APInt autogen14 = autogen12;
	if (autogen11.ule(autogen11.getBitWidth()))
		autogen14.setHighBits(autogen11.getZExtValue());
	else
		autogen14.setHighBits(autogen11.getBitWidth());
	autogen1[0] = autogen14;
	autogen1[1] = autogen13;
}

extern "C" void sdiv_partial_solution_8_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[1];
	APInt autogen4 = autogen1[0];
	APInt autogen5 = autogen1[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	APInt autogen7 = APInt::getAllOnes(autogen5.getBitWidth());
	int autogen8 = autogen7.eq(autogen3);
	int autogen9 = autogen4.eq(autogen6);
	autogen2[0] = autogen9&autogen8;
}

extern "C" void sdiv_partial_solution_9_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen8 = APIntOps::smax(autogen4,autogen3);
	APInt autogen9;
	if (autogen5 == 0) {
		autogen9 = APInt(autogen2.getBitWidth(), -1);
	} else {
		autogen9 = autogen2.udiv(autogen5);
	}
	APInt autogen10 = autogen2-autogen3;
	int autogen11 = autogen2.ule(autogen7);
	APInt autogen12 = autogen9|autogen10;
	unsigned autogen13_autocast = autogen8.countl_zero();
	APInt autogen13(autogen8.getBitWidth(),autogen13_autocast);
	APInt autogen14 = autogen11 ? autogen6 : autogen8 ;
	APInt autogen15;
	if (autogen13.uge(autogen13.getBitWidth())) {
		autogen15 = APInt(autogen14.getBitWidth(), 0);
	} else {
		autogen15 = autogen14.shl(autogen13.getZExtValue());
	}
	APInt autogen16 = ~autogen12;
	APInt autogen17 = autogen12*autogen15;
	autogen1[0] = autogen17;
	autogen1[1] = autogen16;
}

extern "C" void sdiv_partial_solution_9_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[0];
	APInt autogen5 = autogen1[1];
	APInt autogen6(autogen5.getBitWidth(),0);
	APInt autogen7(autogen5.getBitWidth(),1);
	APInt autogen8 = autogen6;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen8.setHighBits(autogen7.getZExtValue());
	else
		autogen8.setHighBits(autogen7.getBitWidth());
	int autogen9 = autogen4.ule(autogen8);
	int autogen10 = autogen8.ult(autogen3);
	int autogen11 = autogen9|autogen10;
	autogen2[0] = autogen11^autogen9;
}

extern "C" void sdiv_partial_solution_10_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),0);
	APInt autogen7 = APInt::getAllOnes(autogen5.getBitWidth());
	APInt autogen8(autogen5.getBitWidth(),1);
	unsigned autogen9_autocast = autogen5.getBitWidth();
	APInt autogen9(autogen5.getBitWidth(),autogen9_autocast);
	unsigned autogen10_autocast = autogen2.countl_zero();
	APInt autogen10(autogen2.getBitWidth(),autogen10_autocast);
	APInt autogen11 = autogen4^autogen2;
	APInt autogen12;
	if (autogen7 == 0) {
		autogen12 = APInt(autogen11.getBitWidth(), -1);
	} else {
		autogen12 = autogen11.udiv(autogen7);
	}
	int autogen13 = autogen6.ule(autogen4);
	APInt autogen14 = autogen9+autogen8;
	APInt autogen15;
	if (autogen11 == 0) {
		autogen15 = autogen11;
	} else {
		autogen15 = autogen11.srem(autogen11);
	}
	int autogen16 = autogen15.ule(autogen4);
	unsigned autogen17_autocast = autogen5.countl_zero();
	APInt autogen17(autogen5.getBitWidth(),autogen17_autocast);
	APInt autogen18 = APIntOps::smin(autogen3,autogen4);
	APInt autogen19;
	if (autogen17.uge(autogen17.getBitWidth())) {
		autogen19 = APInt(autogen12.getBitWidth(), 0);
	} else {
		autogen19 = autogen12.lshr(autogen17.getZExtValue());
	}
	APInt autogen20 = autogen13 ? autogen14 : autogen10 ;
	APInt autogen21 = autogen16 ? autogen20 : autogen9 ;
	APInt autogen22 = APIntOps::smax(autogen19,autogen15);
	APInt autogen23;
	if (autogen21.uge(autogen21.getBitWidth())) {
		autogen23 = APInt(autogen18.getBitWidth(), 0);
	} else {
		autogen23 = autogen18.shl(autogen21.getZExtValue());
	}
	APInt autogen24 = autogen22&autogen3;
	autogen1[0] = autogen24;
	autogen1[1] = autogen23;
}

extern "C" void sdiv_partial_solution_11_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7 = APInt::getAllOnes(autogen4.getBitWidth());
	unsigned autogen8_autocast = autogen4.getBitWidth();
	APInt autogen8(autogen4.getBitWidth(),autogen8_autocast);
	unsigned autogen9_autocast = autogen4.countl_zero();
	APInt autogen9(autogen4.getBitWidth(),autogen9_autocast);
	APInt autogen10 = autogen6+autogen3;
	APInt autogen11 = APIntOps::smin(autogen7,autogen7);
	APInt autogen12 = APIntOps::umin(autogen11,autogen2);
	unsigned autogen13_autocast = autogen10.countl_zero();
	APInt autogen13(autogen10.getBitWidth(),autogen13_autocast);
	APInt autogen14;
	if (autogen2.isMinSignedValue() && autogen10 == -1) {
		autogen14 = APInt::getSignedMinValue(autogen2.getBitWidth());
	} else if (autogen10 == 0 && autogen2.isNonNegative()) {
		autogen14 = APInt(autogen2.getBitWidth(), -1);
	} else if (autogen10 == 0 && autogen2.isNegative()) {
		autogen14 = APInt(autogen2.getBitWidth(), 1);
	} else {
		autogen14 = autogen2.sdiv(autogen10);
	}
	APInt autogen15 = APIntOps::smin(autogen5,autogen7);
	APInt autogen16 = autogen13+autogen9;
	APInt autogen17;
	if (autogen8.uge(autogen8.getBitWidth())) {
		autogen17 = APInt(autogen14.getBitWidth(), 0);
	} else {
		autogen17 = autogen14.shl(autogen8.getZExtValue());
	}
	APInt autogen18;
	if (autogen16.uge(autogen16.getBitWidth())) {
		autogen18 = APInt(autogen15.getBitWidth(), 0);
	} else {
		autogen18 = autogen15.shl(autogen16.getZExtValue());
	}
	APInt autogen19 = autogen11&autogen17;
	APInt autogen20 = APIntOps::umax(autogen18,autogen12);
	autogen1[0] = autogen20;
	autogen1[1] = autogen19;
}

extern "C" void sdiv_partial_solution_11_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = autogen1[0];
	APInt autogen6 = autogen1[1];
	APInt autogen7(autogen6.getBitWidth(),1);
	APInt autogen8 = autogen3;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen8.setHighBits(autogen7.getZExtValue());
	else
		autogen8.setHighBits(autogen7.getBitWidth());
	int autogen9 = autogen4.eq(autogen8);
	int autogen10 = autogen5.eq(autogen3);
	autogen2[0] = autogen10&autogen9;
}

extern "C" void sdiv_partial_solution_12_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),0);
	APInt autogen7 = APInt::getAllOnes(autogen5.getBitWidth());
	APInt autogen8(autogen5.getBitWidth(),1);
	APInt autogen9;
	if (autogen5 == 0) {
		autogen9 = autogen7;
	} else {
		autogen9 = autogen7.srem(autogen5);
	}
	APInt autogen10;
	if (autogen6 == 0) {
		autogen10 = autogen2;
	} else {
		autogen10 = autogen2.srem(autogen6);
	}
	unsigned autogen11_autocast = autogen4.countl_zero();
	APInt autogen11(autogen4.getBitWidth(),autogen11_autocast);
	APInt autogen12 = APIntOps::umax(autogen11,autogen8);
	APInt autogen13 = APIntOps::umax(autogen12,autogen11);
	APInt autogen14 = autogen9;
	if (autogen13.ule(autogen13.getBitWidth()))
		autogen14.setLowBits(autogen13.getZExtValue());
	else
		autogen14.setLowBits(autogen13.getBitWidth());
	APInt autogen15 = ~autogen4;
	APInt autogen16 = APIntOps::umin(autogen10,autogen3);
	APInt autogen17;
	if (autogen15 == 0) {
		autogen17 = APInt(autogen16.getBitWidth(), -1);
	} else {
		autogen17 = autogen16.udiv(autogen15);
	}
	APInt autogen18 = autogen14;
	if (autogen12.ule(autogen12.getBitWidth()))
		autogen18.clearLowBits(autogen12.getZExtValue());
	else
		autogen18.clearLowBits(autogen12.getBitWidth());
	autogen1[0] = autogen18;
	autogen1[1] = autogen17;
}

extern "C" void sdiv_partial_solution_12_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5(autogen4.getBitWidth(),1);
	APInt autogen6 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen7 = autogen3|autogen5;
	int autogen8 = autogen6.ule(autogen7);
	int autogen9 = autogen8^autogen8;
	autogen2[0] = autogen9^autogen8;
}

extern "C" void sdiv_partial_solution_13_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = autogen0[0];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),1);
	APInt autogen5(autogen3.getBitWidth(),1);
	unsigned autogen6_autocast = autogen3.getBitWidth();
	APInt autogen6(autogen3.getBitWidth(),autogen6_autocast);
	APInt autogen7 = autogen6+autogen6;
	APInt autogen8 = APIntOps::umin(autogen3,autogen2);
	APInt autogen9 = APIntOps::smax(autogen2,autogen4);
	APInt autogen10 = APIntOps::umax(autogen7,autogen5);
	APInt autogen11;
	if (autogen10.uge(autogen10.getBitWidth())) {
		autogen11 = APInt(autogen9.getBitWidth(), 0);
	} else {
		autogen11 = autogen9.shl(autogen10.getZExtValue());
	}
	unsigned autogen12_autocast = autogen8.countl_zero();
	APInt autogen12(autogen8.getBitWidth(),autogen12_autocast);
	APInt autogen13 = autogen11;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen13.setLowBits(autogen7.getZExtValue());
	else
		autogen13.setLowBits(autogen7.getBitWidth());
	unsigned autogen14_autocast = autogen2.countr_zero();
	APInt autogen14(autogen2.getBitWidth(),autogen14_autocast);
	APInt autogen15 = autogen11+autogen11;
	APInt autogen16 = APIntOps::umin(autogen12,autogen10);
	APInt autogen17 = autogen15;
	if (autogen14.ule(autogen14.getBitWidth()))
		autogen17.clearLowBits(autogen14.getZExtValue());
	else
		autogen17.clearLowBits(autogen14.getBitWidth());
	APInt autogen18 = autogen13;
	if (autogen16.ule(autogen16.getBitWidth()))
		autogen18.clearLowBits(autogen16.getZExtValue());
	else
		autogen18.clearLowBits(autogen16.getBitWidth());
	autogen1[0] = autogen18;
	autogen1[1] = autogen17;
}

extern "C" void sdiv_partial_solution_13_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[0];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = autogen1[1];
	APInt autogen6(autogen5.getBitWidth(),0);
	APInt autogen7(autogen5.getBitWidth(),1);
	APInt autogen8 = APInt::getAllOnes(autogen5.getBitWidth());
	APInt autogen9 = autogen5+autogen3;
	int autogen10 = autogen6.eq(autogen7);
	APInt autogen11 = APIntOps::smax(autogen4,autogen9);
	int autogen12 = autogen8.ule(autogen11);
	autogen2[0] = autogen10^autogen12;
}

extern "C" void sdiv_partial_solution_14_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	APInt autogen7 = APInt::getAllOnes(autogen5.getBitWidth());
	APInt autogen8(autogen5.getBitWidth(),1);
	unsigned autogen9_autocast = autogen5.getBitWidth();
	APInt autogen9(autogen5.getBitWidth(),autogen9_autocast);
	int autogen10 = autogen4.ule(autogen2);
	APInt autogen11 = autogen10 ? autogen9 : autogen8 ;
	APInt autogen12 = APIntOps::umin(autogen4,autogen5);
	APInt autogen13 = autogen11+autogen9;
	APInt autogen14;
	if (autogen13.uge(autogen13.getBitWidth())) {
		autogen14 = APInt(autogen6.getBitWidth(), 0);
	} else {
		autogen14 = autogen6.lshr(autogen13.getZExtValue());
	}
	unsigned autogen15_autocast = autogen12.countl_zero();
	APInt autogen15(autogen12.getBitWidth(),autogen15_autocast);
	APInt autogen16;
	if (autogen15.uge(autogen15.getBitWidth())) {
		autogen16 = APInt(autogen6.getBitWidth(), 0);
	} else {
		autogen16 = autogen6.shl(autogen15.getZExtValue());
	}
	APInt autogen17 = autogen3&autogen14;
	APInt autogen18 = autogen7*autogen16;
	autogen1[0] = autogen18;
	autogen1[1] = autogen17;
}

extern "C" void sdiv_partial_solution_14_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen1[1];
	APInt autogen4(autogen3.getBitWidth(),0);
	APInt autogen5 = APInt::getAllOnes(autogen3.getBitWidth());
	APInt autogen6(autogen3.getBitWidth(),1);
	APInt autogen7 = autogen5-autogen3;
	int autogen8 = autogen6.ule(autogen6);
	int autogen9 = autogen4.ult(autogen7);
	autogen2[0] = autogen9^autogen8;
}

extern "C" void sdiv_partial_solution_15_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = autogen0[0];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),0);
	APInt autogen5(autogen3.getBitWidth(),1);
	APInt autogen6(autogen3.getBitWidth(),1);
	unsigned autogen7_autocast = autogen3.getBitWidth();
	APInt autogen7(autogen3.getBitWidth(),autogen7_autocast);
	int autogen8 = autogen6.eq(autogen7);
	unsigned autogen9_autocast = autogen2.countr_zero();
	APInt autogen9(autogen2.getBitWidth(),autogen9_autocast);
	APInt autogen10 = APIntOps::umax(autogen5,autogen2);
	APInt autogen11 = APIntOps::umax(autogen6,autogen7);
	APInt autogen12 = autogen6-autogen9;
	APInt autogen13 = autogen8 ? autogen12 : autogen11 ;
	APInt autogen14 = APIntOps::umin(autogen10,autogen3);
	APInt autogen15 = autogen3;
	if (autogen13.ule(autogen13.getBitWidth()))
		autogen15.setHighBits(autogen13.getZExtValue());
	else
		autogen15.setHighBits(autogen13.getBitWidth());
	APInt autogen16;
	if (autogen7.uge(autogen7.getBitWidth()) && autogen4.isSignBitSet()) {
		autogen16 = APInt(autogen4.getBitWidth(), -1);
	} else if (autogen7.uge(autogen7.getBitWidth()) && autogen4.isSignBitClear()) {
		autogen16 = APInt(autogen4.getBitWidth(), 0);
	} else {
		autogen16 = autogen4.ashr(autogen7.getZExtValue());
	}
	unsigned autogen17_autocast = autogen14.countl_zero();
	APInt autogen17(autogen14.getBitWidth(),autogen17_autocast);
	APInt autogen18;
	if (autogen12.uge(autogen12.getBitWidth()) && autogen16.isSignBitSet()) {
		autogen18 = APInt(autogen16.getBitWidth(), -1);
	} else if (autogen12.uge(autogen12.getBitWidth()) && autogen16.isSignBitClear()) {
		autogen18 = APInt(autogen16.getBitWidth(), 0);
	} else {
		autogen18 = autogen16.ashr(autogen12.getZExtValue());
	}
	APInt autogen19 = APIntOps::umin(autogen18,autogen2);
	APInt autogen20 = autogen15;
	if (autogen17.ule(autogen17.getBitWidth()))
		autogen20.clearLowBits(autogen17.getZExtValue());
	else
		autogen20.clearLowBits(autogen17.getBitWidth());
	autogen1[0] = autogen20;
	autogen1[1] = autogen19;
}

extern "C" void sdiv_partial_solution_15_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen0[1];
	APInt autogen4 = autogen1[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	int autogen6 = autogen3.eq(autogen5);
	int autogen7 = autogen4.ult(autogen5);
	int autogen8 = autogen6&autogen7;
	int autogen9 = autogen6|autogen6;
	autogen2[0] = autogen9^autogen8;
}

extern "C" void sdiv_partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sdiv_partial_solution_0_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sdiv_partial_solution_0_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sdiv_partial_solution_1(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sdiv_partial_solution_1_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sdiv_partial_solution_1_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sdiv_partial_solution_2(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sdiv_partial_solution_2_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sdiv_partial_solution_2_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sdiv_partial_solution_3(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	sdiv_partial_solution_3_body(autogen0,autogen1, autogen2);
}

extern "C" void sdiv_partial_solution_4(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sdiv_partial_solution_4_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sdiv_partial_solution_4_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sdiv_partial_solution_5(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sdiv_partial_solution_5_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sdiv_partial_solution_5_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sdiv_partial_solution_6(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sdiv_partial_solution_6_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sdiv_partial_solution_6_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sdiv_partial_solution_7(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sdiv_partial_solution_7_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sdiv_partial_solution_7_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sdiv_partial_solution_8(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sdiv_partial_solution_8_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sdiv_partial_solution_8_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sdiv_partial_solution_9(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sdiv_partial_solution_9_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sdiv_partial_solution_9_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sdiv_partial_solution_10(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	sdiv_partial_solution_10_body(autogen0,autogen1, autogen2);
}

extern "C" void sdiv_partial_solution_11(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sdiv_partial_solution_11_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sdiv_partial_solution_11_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sdiv_partial_solution_12(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sdiv_partial_solution_12_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sdiv_partial_solution_12_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sdiv_partial_solution_13(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sdiv_partial_solution_13_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sdiv_partial_solution_13_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sdiv_partial_solution_14(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sdiv_partial_solution_14_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sdiv_partial_solution_14_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sdiv_partial_solution_15(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	sdiv_partial_solution_15_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	sdiv_partial_solution_15_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void sdiv_solution(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	sdiv_partial_solution_0(autogen0,autogen1, autogen3);
	APInt autogen4[2];
	sdiv_partial_solution_1(autogen0,autogen1, autogen4);
	APInt autogen5[2];
	sdiv_partial_solution_2(autogen0,autogen1, autogen5);
	APInt autogen6[2];
	sdiv_partial_solution_3(autogen0,autogen1, autogen6);
	APInt autogen7[2];
	sdiv_partial_solution_4(autogen0,autogen1, autogen7);
	APInt autogen8[2];
	sdiv_partial_solution_5(autogen0,autogen1, autogen8);
	APInt autogen9[2];
	sdiv_partial_solution_6(autogen0,autogen1, autogen9);
	APInt autogen10[2];
	sdiv_partial_solution_7(autogen0,autogen1, autogen10);
	APInt autogen11[2];
	sdiv_partial_solution_8(autogen0,autogen1, autogen11);
	APInt autogen12[2];
	sdiv_partial_solution_9(autogen0,autogen1, autogen12);
	APInt autogen13[2];
	sdiv_partial_solution_10(autogen0,autogen1, autogen13);
	APInt autogen14[2];
	sdiv_partial_solution_11(autogen0,autogen1, autogen14);
	APInt autogen15[2];
	sdiv_partial_solution_12(autogen0,autogen1, autogen15);
	APInt autogen16[2];
	sdiv_partial_solution_13(autogen0,autogen1, autogen16);
	APInt autogen17[2];
	sdiv_partial_solution_14(autogen0,autogen1, autogen17);
	APInt autogen18[2];
	sdiv_partial_solution_15(autogen0,autogen1, autogen18);
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

