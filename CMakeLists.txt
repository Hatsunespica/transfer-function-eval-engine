project(eval-engine)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
cmake_minimum_required(VERSION 3.16)
find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

include_directories(include)
include_directories(TFImpl)
include_directories(${LLVM_INCLUDE_DIRS} ${CLANG_INCLUDE_DIRS})
add_executable(eval-engine
        src/main.cpp
        src/JIT.cpp
        src/EvaluationBatch.cpp
        src/EvaluationResult.cpp
        src/EvaluationEngine.cpp
        src/DataSampler.cpp
        src/EvaluationParameter.cpp)

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

target_compile_options(eval-engine PRIVATE -fopenmp)

if(LLVM_BUILD_BINARY_DIR)
  file(TO_CMAKE_PATH "${LLVM_BUILD_BINARY_DIR}" _llvm_build_dir)
  set(openmp_lib "${_llvm_build_dir}/runtimes/runtimes-bins/openmp/runtime/src/libomp.so")
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

if(DEFINED openmp_lib AND EXISTS "${openmp_lib}")
  message(STATUS "Using libomp from LLVM build: ${openmp_lib}")

  # create an imported target for the concrete runtime library
  add_library(local_libomp SHARED IMPORTED)
  set_target_properties(local_libomp PROPERTIES
          IMPORTED_LOCATION "${openmp_lib}"
  )

  # link the imported runtime so symbol resolution at runtime uses this lib
  target_link_libraries(eval-engine PRIVATE local_libomp)

  # embed rpath so runtime prefers the build lib at execution time
  #get_filename_component(_omp_dir "${openmp_lib}" DIRECTORY)
  #set_target_properties(eval-engine PROPERTIES
  #        BUILD_RPATH "${_omp_dir}"
  #)
else()
  message(STATUS "libomp not found in LLVM build tree (or LLVM_BUILD_BINARY_DIR not set). Using system runtime (-lomp).")
  # Optionally: user can pass -DOPENMP_RUNTIME=/path/to/libomp.so to force another lib.
endif()

