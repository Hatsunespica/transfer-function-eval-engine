extern "C" void xor_partial_solution_0_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6 = autogen5&autogen2;
	APInt autogen7 = autogen4&autogen3;
	APInt autogen8 = autogen6+autogen7;
	APInt autogen9 = autogen5&autogen3;
	autogen1[0] = autogen9;
	autogen1[1] = autogen8;
}

extern "C" void xor_partial_solution_1_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	unsigned autogen7_autocast = autogen5.getBitWidth();
	APInt autogen7(autogen5.getBitWidth(),autogen7_autocast);
	APInt autogen8 = autogen5;
	if (autogen7.ule(autogen7.getBitWidth()))
		autogen8.clearLowBits(autogen7.getZExtValue());
	else
		autogen8.clearLowBits(autogen7.getBitWidth());
	APInt autogen9 = autogen3;
	autogen9.clearSignBit();
	APInt autogen10 = autogen9-autogen6;
	unsigned autogen11_autocast = autogen8.countr_one();
	APInt autogen11(autogen8.getBitWidth(),autogen11_autocast);
	APInt autogen12 = autogen2&autogen4;
	APInt autogen13 = APIntOps::umin(autogen8,autogen10);
	APInt autogen14 = autogen12;
	if (autogen11.ule(autogen11.getBitWidth()))
		autogen14.clearHighBits(autogen11.getZExtValue());
	else
		autogen14.clearHighBits(autogen11.getBitWidth());
	autogen1[0] = autogen14;
	autogen1[1] = autogen13;
}

extern "C" void xor_partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	xor_partial_solution_0_body(autogen0,autogen1, autogen2);
}

extern "C" void xor_partial_solution_1(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	xor_partial_solution_1_body(autogen0,autogen1, autogen2);
}

extern "C" void xor_solution(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	xor_partial_solution_0(autogen0,autogen1, autogen3);
	APInt autogen4[2];
	xor_partial_solution_1(autogen0,autogen1, autogen4);
	tf_meet(autogen3,autogen4, autogen2);
}

