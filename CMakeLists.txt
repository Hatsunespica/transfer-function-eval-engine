project(eval-engine)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
cmake_minimum_required(VERSION 3.16)
find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS} ${CLANG_INCLUDE_DIRS})
add_executable(eval-engine src/main.cpp)
llvm_map_components_to_libnames(LLVM_LIBS
    Core
    IRReader
    Support
    OrcJIT
    ExecutionEngine
    native           # Initializes native target
    nativecodegen    # Needed if you JIT nontrivial code
)


if(NOT LLVM_ENABLE_RTTI)
  target_compile_options(eval-engine PRIVATE -fno-rtti)
endif()

if(CLANG_LINK_CLANG_DYLIB)
  target_link_libraries(eval-engine PRIVATE clang-cpp)
else()
  target_link_libraries(eval-engine PRIVATE
    clangAST
    clangBasic
    clangCodeGen
    clangDriver
    clangFrontend
    clangLex
    clangParse
    clangSema
    clangSerialization
  )
    target_link_libraries(eval-engine PRIVATE
    ${LLVM_LIBS}
  )
endif()

if(LLVM_LINK_LLVM_DYLIB)
  target_link_libraries(eval-engine PRIVATE LLVM)
else()
  target_link_libraries(eval-engine PRIVATE LLVMOption LLVMSupport LLVMTarget
    LLVMX86AsmParser LLVMX86CodeGen LLVMX86Desc LLVMX86Info)
endif()
