extern "C" void add_partial_solution_0_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	APInt autogen7(autogen5.getBitWidth(),1);
	APInt autogen8 = autogen3&autogen4;
	APInt autogen9 = autogen2+autogen4;
	APInt autogen10 = autogen9+autogen6;
	APInt autogen11 = autogen5&autogen2;
	APInt autogen12 = autogen5&autogen3;
	APInt autogen13 = ~autogen10;
	APInt autogen14 = autogen8^autogen11;
	APInt autogen15 = autogen7&autogen10;
	APInt autogen16 = autogen13&autogen14;
	APInt autogen17 = autogen12&autogen15;
	autogen1[0] = autogen17;
	autogen1[1] = autogen16;
}

extern "C" void add_partial_solution_1_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6 = APInt::getAllOnes(autogen5.getBitWidth());
	APInt autogen7(autogen5.getBitWidth(),1);
	APInt autogen8 = autogen4+autogen7;
	APInt autogen9 = autogen8+autogen2;
	APInt autogen10 = autogen6+autogen7;
	APInt autogen11 = ~autogen10;
	APInt autogen12 = autogen4|autogen3;
	APInt autogen13 = autogen3^autogen9;
	APInt autogen14 = autogen12&autogen13;
	APInt autogen15 = ~autogen11;
	APInt autogen16 = autogen14&autogen2;
	autogen1[0] = autogen16;
	autogen1[1] = autogen15;
}

extern "C" void add_partial_solution_2_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	APInt autogen7 = autogen3+autogen5;
	APInt autogen8 = ~autogen3;
	APInt autogen9 = autogen4|autogen6;
	APInt autogen10 = autogen9&autogen2;
	APInt autogen11 = autogen8|autogen7;
	APInt autogen12 = ~autogen9;
	APInt autogen13 = autogen11|autogen12;
	APInt autogen14 = autogen10&autogen7;
	APInt autogen15 = ~autogen13;
	autogen1[0] = autogen15;
	autogen1[1] = autogen14;
}

extern "C" void add_partial_solution_3_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[1];
	APInt autogen5 = autogen4|autogen4;
	APInt autogen6 = autogen3+autogen5;
	APInt autogen7 = autogen6^autogen2;
	APInt autogen8 = autogen5&autogen7;
	APInt autogen9 = autogen2&autogen8;
	APInt autogen10 = autogen8&autogen3;
	APInt autogen11 = autogen7&autogen9;
	autogen1[0] = autogen11;
	autogen1[1] = autogen10;
}

extern "C" void add_partial_solution_4_body(APInt* arg0, APInt* autogen0, APInt* autogen1){
	APInt autogen2 = arg0[0];
	APInt autogen3 = arg0[1];
	APInt autogen4 = autogen0[0];
	APInt autogen5 = autogen0[1];
	APInt autogen6(autogen5.getBitWidth(),1);
	APInt autogen7 = autogen2|autogen2;
	APInt autogen8 = autogen4+autogen6;
	APInt autogen9 = autogen8+autogen7;
	APInt autogen10 = autogen9&autogen5;
	APInt autogen11 = ~autogen6;
	APInt autogen12 = autogen6&autogen11;
	APInt autogen13 = autogen10&autogen3;
	autogen1[0] = autogen13;
	autogen1[1] = autogen12;
}

extern "C" void add_partial_solution_0(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	add_partial_solution_0_body(autogen0,autogen1, autogen2);
}

extern "C" void add_partial_solution_1(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	add_partial_solution_1_body(autogen0,autogen1, autogen2);
}

extern "C" void add_partial_solution_2(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	add_partial_solution_2_body(autogen0,autogen1, autogen2);
}

extern "C" void add_partial_solution_3(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	add_partial_solution_3_body(autogen0,autogen1, autogen2);
}

extern "C" void add_partial_solution_4(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	add_partial_solution_4_body(autogen0,autogen1, autogen2);
}

extern "C" void add_solution(APInt* autogen0, APInt* autogen1, APInt* autogen2){
	APInt autogen3[2];
	add_partial_solution_0(autogen0,autogen1, autogen3);
	APInt autogen4[2];
	add_partial_solution_1(autogen0,autogen1, autogen4);
	APInt autogen5[2];
	add_partial_solution_2(autogen0,autogen1, autogen5);
	APInt autogen6[2];
	add_partial_solution_3(autogen0,autogen1, autogen6);
	APInt autogen7[2];
	add_partial_solution_4(autogen0,autogen1, autogen7);
	APInt autogen8[2];
	tf_meet(autogen3,autogen4, autogen8);
	APInt autogen9[2];
	tf_meet(autogen8,autogen5, autogen9);
	APInt autogen10[2];
	tf_meet(autogen9,autogen6, autogen10);
	tf_meet(autogen10,autogen7, autogen2);
}

