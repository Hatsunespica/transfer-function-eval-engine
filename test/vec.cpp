#include "llvm/ADT/APInt.h"
#include "llvm/Support/KnownBits.h"
#include <vector>

using namespace llvm;
using namespace std;

 vector<APInt> getVector(APInt arg0, APInt arg1){
   return {arg0, arg1};
 }

 
 extern "C" void getVector_C(APInt* a,
                            APInt* b,
                            APInt* out) {
    out[0] = a[0];
    out[1] = b[0];
 }
 
  extern "C" int test(int a, int b) {
	return a+b;
 }


 extern "C" void getKB(APInt** args,
                            APInt* out) {
    out[0] = args[0][0];
    out[1] = args[1][0];
 }
