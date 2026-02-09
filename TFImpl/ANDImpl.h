extern "C" void and_partial_solution_0_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),0);
	APInt autogen7(autogen5.getBitWidth(),1);
	unsigned autogen8_autocast = autogen5.getBitWidth();
	APInt autogen8(autogen5.getBitWidth(),autogen8_autocast);
	APInt autogen9 = autogen2|autogen4;
	APInt autogen10 = autogen4;
	if (autogen8.ule(autogen8.getBitWidth()))
		autogen10.clearHighBits(autogen8.getZExtValue());
	else
		autogen10.clearHighBits(autogen8.getBitWidth());
	APInt autogen11;
	if (autogen7.uge(autogen7.getBitWidth()) && autogen6.isSignBitSet()) {
		autogen11 = APInt(autogen6.getBitWidth(), -1);
	} else if (autogen7.uge(autogen7.getBitWidth()) && autogen6.isSignBitClear()) {
		autogen11 = APInt(autogen6.getBitWidth(), 0);
	} else {
		autogen11 = autogen6.ashr(autogen7.getZExtValue());
	}
	APInt autogen12 = autogen3|autogen10;
	APInt autogen13 = APIntOps::smax(autogen3,autogen12);
	unsigned autogen14_autocast = autogen11.countr_one();
	APInt autogen14(autogen11.getBitWidth(),autogen14_autocast);
	APInt autogen15 = autogen13&autogen5;
	APInt autogen16 = autogen9;
	if (autogen14.ule(autogen14.getBitWidth()))
		autogen16.clearLowBits(autogen14.getZExtValue());
	else
		autogen16.clearLowBits(autogen14.getBitWidth());
	autogen1[0] = autogen16;
	autogen1[1] = autogen15;
}

extern "C" void and_partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	and_partial_solution_0_body(autogen0,autogen1, autogen2);
}

extern "C" void and_solution(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	and_partial_solution_0(autogen0,autogen1, autogen2);
}

