extern "C" void or_partial_solution_0_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	APInt autogen7(autogen5.getBitWidth(),1);
	unsigned autogen8_autocast = autogen5.getBitWidth();
	APInt autogen8(autogen5.getBitWidth(),autogen8_autocast);
	int autogen9 = autogen4.ule(autogen2);
	APInt autogen10 = APIntOps::umax(autogen7,autogen8);
	APInt autogen11 = autogen5|autogen3;
	APInt autogen12 = autogen4&autogen6;
	APInt autogen13;
	if (autogen10.uge(autogen10.getBitWidth())) {
		autogen13 = APInt(autogen4.getBitWidth(), 0);
	} else {
		autogen13 = autogen4.shl(autogen10.getZExtValue());
	}
	APInt autogen14 = autogen9 ? autogen13 : autogen5 ;
	APInt autogen15 = autogen12;
	if (autogen10.ule(autogen10.getBitWidth()))
		autogen15.clearLowBits(autogen10.getZExtValue());
	else
		autogen15.clearLowBits(autogen10.getBitWidth());
	APInt autogen16 = autogen15;
	if (autogen10.ule(autogen10.getBitWidth()))
		autogen16.clearHighBits(autogen10.getZExtValue());
	else
		autogen16.clearHighBits(autogen10.getBitWidth());
	APInt autogen17 = autogen16&autogen6;
	APInt autogen18 = autogen4&autogen2;
	APInt autogen19 = APIntOps::umax(autogen11,autogen14);
	APInt autogen20;
	if (autogen17 == 0) {
		autogen20 = autogen18;
	} else {
		autogen20 = autogen18.urem(autogen17);
	}
	autogen1[0] = autogen20;
	autogen1[1] = autogen19;
}

extern "C" void or_partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	or_partial_solution_0_body(autogen0,autogen1, autogen2);
}

extern "C" void or_solution(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	or_partial_solution_0(autogen0,autogen1, autogen2);
}

