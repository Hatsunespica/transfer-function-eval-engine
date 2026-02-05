# transfer-function-eval-engine
This repo is used for evaluating C++ transfer functions generated from our xdsl-smt synthesizer. 

## To find JIT include path
```
clang -E -x c++ -V
```
should print out the search path for clang and use it to update 
`include/HEADER_INCLUDE_PATH.h`

## Installation and Test
```
 cmake -S. -Bbuild -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=/home/spica/GitRepo/llvm-project/build/bin/clang++ -DCMAKE_PREFIX_PATH="/home/spica/GitRepo/llvm-project/build"
 ninja -C build
 ./build/eval-engine --jit-config="-S" --domain=test --func=123,456,789 --file=./test/vec.cpp
 
 ./build/eval-engine --jit-config="-S" --domain=test --func=123,456,789 --source='
 
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

 
 '
 
 
 ./build/eval-engine  --file=./test/knownBitsTest.cpp  --transfer-function="test" --base-transfer-function="baseTest" --domain="knownBits" --abstract-domain-length=2 --enumerate-bit-width=4,3,2,1 --sample-bit-width=8 --sample-concrete-amount=100 --sample-abstract-amount=0 --jit-config="-S" --max-operation-length=32 --data-cache-path="./data" --transfer-function-arity=2

```
