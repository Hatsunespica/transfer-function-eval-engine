# transfer-function-eval-engine
This repo is used for evaluating C++ transfer functions generated from our xdsl-smt synthesizer. 


## Installation and Test
```
 cmake -S. -Bbuild -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=/home/spica/GitRepo/llvm-project/build/bin/clang++ -DCMAKE_PREFIX_PATH="/home/spica/GitRepo/llvm-project/build"
 ninja -C build
 ./build/eval-engine --jit-config="-S" --domain=test --func=123,456,789 --file=./test/vec.cpp
 ./build/eval-engine --jit-config="-S" --domain=test --func=123,456,789 --source='
 
 ***source code in vec.cpp here***
 
 `
```