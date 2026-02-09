extern "C" void shl_nsw_partial_solution_0_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	APInt autogen6(autogen4.getBitWidth(),0);
	APInt autogen7(autogen4.getBitWidth(),1);
	unsigned autogen8_autocast = autogen4.getBitWidth();
	APInt autogen8(autogen4.getBitWidth(),autogen8_autocast);
	unsigned autogen9_autocast = autogen4.countl_zero();
	APInt autogen9(autogen4.getBitWidth(),autogen9_autocast);
	APInt autogen10 = APIntOps::umin(autogen2,autogen3);
	APInt autogen11 = autogen5;
	if (autogen9.ule(autogen9.getBitWidth()))
		autogen11.clearHighBits(autogen9.getZExtValue());
	else
		autogen11.clearHighBits(autogen9.getBitWidth());
	APInt autogen12 = APIntOps::umax(autogen8,autogen7);
	APInt autogen13;
	if (autogen12.uge(autogen12.getBitWidth())) {
		autogen13 = APInt(autogen2.getBitWidth(), 0);
	} else {
		autogen13 = autogen2.shl(autogen12.getZExtValue());
	}
	unsigned autogen14_autocast = autogen10.countl_one();
	APInt autogen14(autogen10.getBitWidth(),autogen14_autocast);
	APInt autogen15 = autogen13^autogen11;
	APInt autogen16 = autogen9+autogen12;
	int autogen17 = autogen8.eq(autogen14);
	APInt autogen18 = autogen17 ? autogen16 : autogen6 ;
	APInt autogen19;
	if (autogen9.uge(autogen9.getBitWidth())) {
		autogen19 = APInt(autogen10.getBitWidth(), 0);
	} else {
		autogen19 = autogen10.lshr(autogen9.getZExtValue());
	}
	APInt autogen20;
	if (autogen18.uge(autogen18.getBitWidth()) && autogen15.isSignBitSet()) {
		autogen20 = APInt(autogen15.getBitWidth(), -1);
	} else if (autogen18.uge(autogen18.getBitWidth()) && autogen15.isSignBitClear()) {
		autogen20 = APInt(autogen15.getBitWidth(), 0);
	} else {
		autogen20 = autogen15.ashr(autogen18.getZExtValue());
	}
	autogen1[0] = autogen20;
	autogen1[1] = autogen19;
}

extern "C" void shl_nsw_partial_solution_1_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7(autogen4.getBitWidth(),0);
	APInt autogen8(autogen4.getBitWidth(),1);
	unsigned autogen9_autocast = autogen4.getBitWidth();
	APInt autogen9(autogen4.getBitWidth(),autogen9_autocast);
	int autogen10 = autogen7.eq(autogen8);
	unsigned autogen11_autocast = autogen2.countl_zero();
	APInt autogen11(autogen2.getBitWidth(),autogen11_autocast);
	APInt autogen12;
	if (autogen11.uge(autogen11.getBitWidth())) {
		autogen12 = APInt(autogen6.getBitWidth(), 0);
	} else {
		autogen12 = autogen6.lshr(autogen11.getZExtValue());
	}
	APInt autogen13 = autogen6;
	if (autogen9.ule(autogen9.getBitWidth()))
		autogen13.clearHighBits(autogen9.getZExtValue());
	else
		autogen13.clearHighBits(autogen9.getBitWidth());
	unsigned autogen14_autocast = autogen12.countl_zero();
	APInt autogen14(autogen12.getBitWidth(),autogen14_autocast);
	APInt autogen15 = autogen10 ? autogen2 : autogen13 ;
	APInt autogen16 = autogen15;
	if (autogen14.ule(autogen14.getBitWidth()))
		autogen16.setLowBits(autogen14.getZExtValue());
	else
		autogen16.setLowBits(autogen14.getBitWidth());
	APInt autogen17 = autogen5;
	autogen17.setSignBit();
	APInt autogen18 = autogen17&autogen3;
	APInt autogen19 = ~autogen16;
	autogen1[0] = autogen19;
	autogen1[1] = autogen18;
}

extern "C" void shl_nsw_partial_solution_2_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),1);
	unsigned autogen5_autocast = autogen2.countr_one();
	APInt autogen5(autogen2.getBitWidth(),autogen5_autocast);
	APInt autogen6 = autogen3-autogen4;
	APInt autogen7 = autogen6+autogen4;
	unsigned autogen8_autocast = autogen6.countl_zero();
	APInt autogen8(autogen6.getBitWidth(),autogen8_autocast);
	APInt autogen9 = autogen7;
	if (autogen8.ule(autogen8.getBitWidth()))
		autogen9.clearLowBits(autogen8.getZExtValue());
	else
		autogen9.clearLowBits(autogen8.getBitWidth());
	APInt autogen10 = autogen7;
	if (autogen5.ule(autogen5.getBitWidth()))
		autogen10.setLowBits(autogen5.getZExtValue());
	else
		autogen10.setLowBits(autogen5.getBitWidth());
	autogen1[0] = autogen10;
	autogen1[1] = autogen9;
}

extern "C" void shl_nsw_partial_solution_3_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[1];
	unsigned autogen4_autocast = autogen3.getBitWidth();
	APInt autogen4(autogen3.getBitWidth(),autogen4_autocast);
	APInt autogen5 = ~autogen2;
	unsigned autogen6_autocast = autogen5.countr_zero();
	APInt autogen6(autogen5.getBitWidth(),autogen6_autocast);
	APInt autogen7 = APIntOps::umin(autogen6,autogen4);
	APInt autogen8 = autogen2;
	if (autogen4.ule(autogen4.getBitWidth()))
		autogen8.clearLowBits(autogen4.getZExtValue());
	else
		autogen8.clearLowBits(autogen4.getBitWidth());
	APInt autogen9;
	if (autogen7.uge(autogen7.getBitWidth())) {
		autogen9 = APInt(autogen3.getBitWidth(), 0);
	} else {
		autogen9 = autogen3.shl(autogen7.getZExtValue());
	}
	autogen1[0] = autogen9;
	autogen1[1] = autogen8;
}

extern "C" void shl_nsw_partial_solution_4_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = autogen0[0];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),0);
	APInt autogen5(autogen3.getBitWidth(),1);
	unsigned autogen6_autocast = autogen2.countl_one();
	APInt autogen6(autogen2.getBitWidth(),autogen6_autocast);
	APInt autogen7;
	if (autogen5.uge(autogen5.getBitWidth())) {
		autogen7 = APInt(autogen3.getBitWidth(), 0);
	} else {
		autogen7 = autogen3.lshr(autogen5.getZExtValue());
	}
	APInt autogen8;
	if (autogen4 == 0) {
		autogen8 = autogen3;
	} else {
		autogen8 = autogen3.urem(autogen4);
	}
	APInt autogen9 = autogen7;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen9.clearHighBits(autogen6.getZExtValue());
	else
		autogen9.clearHighBits(autogen6.getBitWidth());
	unsigned autogen10_autocast = autogen3.countl_zero();
	APInt autogen10(autogen3.getBitWidth(),autogen10_autocast);
	APInt autogen11 = autogen7;
	if (autogen5.ule(autogen5.getBitWidth()))
		autogen11.clearHighBits(autogen5.getZExtValue());
	else
		autogen11.clearHighBits(autogen5.getBitWidth());
	APInt autogen12 = autogen9;
	if (autogen10.ule(autogen10.getBitWidth()))
		autogen12.clearLowBits(autogen10.getZExtValue());
	else
		autogen12.clearLowBits(autogen10.getBitWidth());
	APInt autogen13 = autogen11+autogen8;
	autogen1[0] = autogen13;
	autogen1[1] = autogen12;
}

extern "C" void shl_nsw_partial_solution_5_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = autogen4&autogen4;
	APInt autogen6 = autogen3+autogen4;
	APInt autogen7 = autogen5^autogen6;
	APInt autogen8 = autogen2+autogen5;
	autogen1[0] = autogen8;
	autogen1[1] = autogen7;
}

extern "C" void shl_nsw_partial_solution_5_cond(APInt* autogen0, APInt* autogen1, int* autogen2){
	APInt autogen3 = autogen1[0];
	APInt autogen4 = autogen1[1];
	APInt autogen5 = APInt::getAllOnes(autogen4.getBitWidth());
	unsigned autogen6_autocast = autogen4.getBitWidth();
	APInt autogen6(autogen4.getBitWidth(),autogen6_autocast);
	APInt autogen7 = autogen3;
	if (autogen6.ule(autogen6.getBitWidth()))
		autogen7.clearLowBits(autogen6.getZExtValue());
	else
		autogen7.clearLowBits(autogen6.getBitWidth());
	int autogen8 = autogen3.eq(autogen5);
	int autogen9 = autogen6.eq(autogen6);
	int autogen10 = autogen5.eq(autogen7);
	int autogen11 = autogen10^autogen9;
	int autogen12 = autogen8&autogen9;
	autogen2[0] = autogen12&autogen11;
}

extern "C" void shl_nsw_partial_solution_6_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = autogen0[1];
	APInt autogen3(autogen2.getBitWidth(),1);
	APInt autogen4 = autogen3+autogen3;
	APInt autogen5 = APIntOps::umin(autogen2,autogen2);
	unsigned autogen6_autocast = autogen5.countl_one();
	APInt autogen6(autogen5.getBitWidth(),autogen6_autocast);
	APInt autogen7;
	if (autogen3.uge(autogen3.getBitWidth())) {
		autogen7 = APInt(autogen2.getBitWidth(), 0);
	} else {
		autogen7 = autogen2.lshr(autogen3.getZExtValue());
	}
	APInt autogen8 = autogen5;
	autogen8.clearSignBit();
	APInt autogen9 = APIntOps::umax(autogen6,autogen4);
	APInt autogen10 = autogen9+autogen9;
	APInt autogen11 = autogen10+autogen3;
	APInt autogen12 = autogen8;
	if (autogen11.ule(autogen11.getBitWidth()))
		autogen12.clearLowBits(autogen11.getZExtValue());
	else
		autogen12.clearLowBits(autogen11.getBitWidth());
	APInt autogen13 = autogen7|autogen5;
	autogen1[0] = autogen13;
	autogen1[1] = autogen12;
}

extern "C" void shl_nsw_partial_solution_7_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[1];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),1);
	APInt autogen5(autogen3.getBitWidth(),1);
	unsigned autogen6_autocast = autogen3.getBitWidth();
	APInt autogen6(autogen3.getBitWidth(),autogen6_autocast);
	unsigned autogen7_autocast = autogen2.countr_zero();
	APInt autogen7(autogen2.getBitWidth(),autogen7_autocast);
	APInt autogen8 = autogen3&autogen2;
	APInt autogen9 = APIntOps::umin(autogen5,autogen6);
	APInt autogen10 = APIntOps::umin(autogen6,autogen9);
	APInt autogen11;
	if (autogen10.uge(autogen10.getBitWidth()) && autogen8.isSignBitSet()) {
		autogen11 = APInt(autogen8.getBitWidth(), -1);
	} else if (autogen10.uge(autogen10.getBitWidth()) && autogen8.isSignBitClear()) {
		autogen11 = APInt(autogen8.getBitWidth(), 0);
	} else {
		autogen11 = autogen8.ashr(autogen10.getZExtValue());
	}
	APInt autogen12 = APIntOps::umin(autogen8,autogen11);
	APInt autogen13;
	if (autogen4 == 0) {
		autogen13 = autogen3;
	} else {
		autogen13 = autogen3.srem(autogen4);
	}
	APInt autogen14;
	if (autogen7.uge(autogen7.getBitWidth())) {
		autogen14 = APInt(autogen12.getBitWidth(), 0);
	} else {
		autogen14 = autogen12.shl(autogen7.getZExtValue());
	}
	autogen1[0] = autogen14;
	autogen1[1] = autogen13;
}

extern "C" void shl_nsw_partial_solution_8_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5(autogen4.getBitWidth(),0);
	APInt autogen6(autogen4.getBitWidth(),1);
	APInt autogen7 = APIntOps::umin(autogen2,autogen3);
	APInt autogen8 = autogen5;
	autogen8.setSignBit();
	APInt autogen9;
	if (autogen6.uge(autogen6.getBitWidth())) {
		autogen9 = APInt(autogen7.getBitWidth(), 0);
	} else {
		autogen9 = autogen7.shl(autogen6.getZExtValue());
	}
	APInt autogen10;
	if (autogen8 == 0) {
		autogen10 = APInt(autogen8.getBitWidth(), -1);
	} else {
		autogen10 = autogen8.udiv(autogen8);
	}
	unsigned autogen11_autocast = autogen9.countl_zero();
	APInt autogen11(autogen9.getBitWidth(),autogen11_autocast);
	unsigned autogen12_autocast = autogen10.countr_zero();
	APInt autogen12(autogen10.getBitWidth(),autogen12_autocast);
	APInt autogen13;
	if (autogen11.uge(autogen11.getBitWidth()) && autogen4.isSignBitSet()) {
		autogen13 = APInt(autogen4.getBitWidth(), -1);
	} else if (autogen11.uge(autogen11.getBitWidth()) && autogen4.isSignBitClear()) {
		autogen13 = APInt(autogen4.getBitWidth(), 0);
	} else {
		autogen13 = autogen4.ashr(autogen11.getZExtValue());
	}
	APInt autogen14;
	if (autogen12.uge(autogen12.getBitWidth())) {
		autogen14 = APInt(autogen13.getBitWidth(), 0);
	} else {
		autogen14 = autogen13.lshr(autogen12.getZExtValue());
	}
	autogen1[0] = autogen14;
	autogen1[1] = autogen13;
}

extern "C" void shl_nsw_partial_solution_9_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = autogen0[1];
	APInt autogen4(autogen3.getBitWidth(),1);
	unsigned autogen5_autocast = autogen3.getBitWidth();
	APInt autogen5(autogen3.getBitWidth(),autogen5_autocast);
	APInt autogen6 = autogen3;
	autogen6.clearSignBit();
	APInt autogen7 = autogen4;
	autogen7.clearSignBit();
	unsigned autogen8_autocast = autogen7.countl_zero();
	APInt autogen8(autogen7.getBitWidth(),autogen8_autocast);
	APInt autogen9;
	if (autogen5.uge(autogen5.getBitWidth())) {
		autogen9 = APInt(autogen4.getBitWidth(), 0);
	} else {
		autogen9 = autogen4.lshr(autogen5.getZExtValue());
	}
	unsigned autogen10_autocast = autogen6.countl_zero();
	APInt autogen10(autogen6.getBitWidth(),autogen10_autocast);
	APInt autogen11 = autogen7&autogen9;
	APInt autogen12 = autogen9-autogen2;
	APInt autogen13 = autogen11;
	if (autogen8.ule(autogen8.getBitWidth()))
		autogen13.clearLowBits(autogen8.getZExtValue());
	else
		autogen13.clearLowBits(autogen8.getBitWidth());
	APInt autogen14;
	if (autogen10.uge(autogen10.getBitWidth())) {
		autogen14 = APInt(autogen12.getBitWidth(), 0);
	} else {
		autogen14 = autogen12.lshr(autogen10.getZExtValue());
	}
	APInt autogen15;
	if (autogen10.uge(autogen10.getBitWidth())) {
		autogen15 = APInt(autogen14.getBitWidth(), 0);
	} else {
		autogen15 = autogen14.lshr(autogen10.getZExtValue());
	}
	APInt autogen16;
	if (autogen9 == 0) {
		autogen16 = autogen13;
	} else {
		autogen16 = autogen13.srem(autogen9);
	}
	APInt autogen17 = autogen15+autogen14;
	autogen1[0] = autogen17;
	autogen1[1] = autogen16;
}

extern "C" void shl_nsw_partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nsw_partial_solution_0_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nsw_partial_solution_1(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nsw_partial_solution_1_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nsw_partial_solution_2(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nsw_partial_solution_2_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nsw_partial_solution_3(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nsw_partial_solution_3_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nsw_partial_solution_4(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nsw_partial_solution_4_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nsw_partial_solution_5(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	tf_getTop(autogen0, autogen3);
	APInt autogen4 = autogen3[0];
	APInt autogen5 = autogen3[1];
	APInt autogen6[2];
	shl_nsw_partial_solution_5_body(autogen0,autogen1, autogen6);
	APInt autogen7 = autogen6[0];
	APInt autogen8 = autogen6[1];
	int autogen9;
	shl_nsw_partial_solution_5_cond(autogen0,autogen1,&autogen9);
	APInt autogen10 = autogen9 ? autogen7 : autogen4 ;
	APInt autogen11 = autogen9 ? autogen8 : autogen5 ;
	autogen2[0] = autogen10;
	autogen2[1] = autogen11;
}

extern "C" void shl_nsw_partial_solution_6(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nsw_partial_solution_6_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nsw_partial_solution_7(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nsw_partial_solution_7_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nsw_partial_solution_8(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nsw_partial_solution_8_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nsw_partial_solution_9(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	shl_nsw_partial_solution_9_body(autogen0,autogen1, autogen2);
}

extern "C" void shl_nsw_solution(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	shl_nsw_partial_solution_0(autogen0,autogen1, autogen3);
	APInt autogen4[2];
	shl_nsw_partial_solution_1(autogen0,autogen1, autogen4);
	APInt autogen5[2];
	shl_nsw_partial_solution_2(autogen0,autogen1, autogen5);
	APInt autogen6[2];
	shl_nsw_partial_solution_3(autogen0,autogen1, autogen6);
	APInt autogen7[2];
	shl_nsw_partial_solution_4(autogen0,autogen1, autogen7);
	APInt autogen8[2];
	shl_nsw_partial_solution_5(autogen0,autogen1, autogen8);
	APInt autogen9[2];
	shl_nsw_partial_solution_6(autogen0,autogen1, autogen9);
	APInt autogen10[2];
	shl_nsw_partial_solution_7(autogen0,autogen1, autogen10);
	APInt autogen11[2];
	shl_nsw_partial_solution_8(autogen0,autogen1, autogen11);
	APInt autogen12[2];
	shl_nsw_partial_solution_9(autogen0,autogen1, autogen12);
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

