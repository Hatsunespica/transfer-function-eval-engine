// knownbits_wrappers.cpp

#include "llvm/ADT/APInt.h"
#include "llvm/Support/KnownBits.h"

using namespace llvm;


// ADD
extern "C"
void add_solution(APInt* arg0, APInt* arg1, APInt* result) {

    KnownBits A;
    A.Zero = arg0[0];
    A.One  = arg0[1];

    KnownBits B;
    B.Zero = arg1[0];
    B.One  = arg1[1];

    KnownBits R = KnownBits::add(A, B);

    result[0] = R.Zero;
    result[1] = R.One;
}


// SUB
extern "C"
void sub_solution(APInt* arg0, APInt* arg1, APInt* result) {

    KnownBits A;
    A.Zero = arg0[0];
    A.One  = arg0[1];

    KnownBits B;
    B.Zero = arg1[0];
    B.One  = arg1[1];

    KnownBits R = KnownBits::sub(A, B);

    result[0] = R.Zero;
    result[1] = R.One;
}


// MUL
extern "C"
void mul_solution(APInt* arg0, APInt* arg1, APInt* result) {

    KnownBits A;
    A.Zero = arg0[0];
    A.One  = arg0[1];

    KnownBits B;
    B.Zero = arg1[0];
    B.One  = arg1[1];

    KnownBits R = KnownBits::mul(A, B);

    result[0] = R.Zero;
    result[1] = R.One;
}


// UREM
extern "C"
void urem_solution(APInt* arg0, APInt* arg1, APInt* result) {

    KnownBits A;
    A.Zero = arg0[0];
    A.One  = arg0[1];

    KnownBits B;
    B.Zero = arg1[0];
    B.One  = arg1[1];

    KnownBits R = KnownBits::urem(A, B);

    result[0] = R.Zero;
    result[1] = R.One;
}


// SREM
extern "C"
void srem_solution(APInt* arg0, APInt* arg1, APInt* result) {

    KnownBits A;
    A.Zero = arg0[0];
    A.One  = arg0[1];

    KnownBits B;
    B.Zero = arg1[0];
    B.One  = arg1[1];

    KnownBits R = KnownBits::srem(A, B);

    result[0] = R.Zero;
    result[1] = R.One;
}


// SHL
extern "C"
void shl_solution(APInt* arg0, APInt* arg1, APInt* result) {

    KnownBits A;
    A.Zero = arg0[0];
    A.One  = arg0[1];

    KnownBits B;
    B.Zero = arg1[0];
    B.One  = arg1[1];

    KnownBits R = KnownBits::shl(A, B);

    result[0] = R.Zero;
    result[1] = R.One;
}


// LSHR
extern "C"
void lshr_solution(APInt* arg0, APInt* arg1, APInt* result) {

    KnownBits A;
    A.Zero = arg0[0];
    A.One  = arg0[1];

    KnownBits B;
    B.Zero = arg1[0];
    B.One  = arg1[1];

    KnownBits R = KnownBits::lshr(A, B);

    result[0] = R.Zero;
    result[1] = R.One;
}


// ASHR
extern "C"
void ashr_solution(APInt* arg0, APInt* arg1, APInt* result) {

    KnownBits A;
    A.Zero = arg0[0];
    A.One  = arg0[1];

    KnownBits B;
    B.Zero = arg1[0];
    B.One  = arg1[1];

    KnownBits R = KnownBits::ashr(A, B);

    result[0] = R.Zero;
    result[1] = R.One;
}


// AND
extern "C"
void and_solution(APInt* arg0, APInt* arg1, APInt* result) {

    KnownBits A;
    A.Zero = arg0[0];
    A.One  = arg0[1];

    KnownBits B;
    B.Zero = arg1[0];
    B.One  = arg1[1];

    KnownBits R = A & B;

    result[0] = R.Zero;
    result[1] = R.One;
}


// OR
extern "C"
void or_solution(APInt* arg0, APInt* arg1, APInt* result) {

    KnownBits A;
    A.Zero = arg0[0];
    A.One  = arg0[1];

    KnownBits B;
    B.Zero = arg1[0];
    B.One  = arg1[1];

    KnownBits R = A | B;

    result[0] = R.Zero;
    result[1] = R.One;
}


// XOR
extern "C"
void xor_solution(APInt* arg0, APInt* arg1, APInt* result) {

    KnownBits A;
    A.Zero = arg0[0];
    A.One  = arg0[1];

    KnownBits B;
    B.Zero = arg1[0];
    B.One  = arg1[1];

    KnownBits R = A ^ B;

    result[0] = R.Zero;
    result[1] = R.One;
}

// SDIV: R = A sdiv B
extern "C"
void sdiv_solution(APInt* arg0, APInt* arg1, APInt* result) {

    KnownBits A;
    A.Zero = arg0[0];
    A.One  = arg0[1];

    KnownBits B;
    B.Zero = arg1[0];
    B.One  = arg1[1];

    KnownBits R = KnownBits::sdiv(A, B);

    result[0] = R.Zero;
    result[1] = R.One;
}

// UDIV: R = A udiv B
extern "C"
void udiv_solution(APInt* arg0, APInt* arg1, APInt* result) {

    KnownBits A;
    A.Zero = arg0[0];
    A.One  = arg0[1];

    KnownBits B;
    B.Zero = arg1[0];
    B.One  = arg1[1];

    KnownBits R = KnownBits::udiv(A, B);

    result[0] = R.Zero;
    result[1] = R.One;
}
