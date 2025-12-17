#include "llvm/Support/CommandLine.h"
#include "JIT.h"
#include "llvm/Support/raw_ostream.h"


using namespace llvm;

cl::opt<std::string> InputFile(
        "file",
        cl::desc("Specify input file name"),
        cl::init(""),
        cl::value_desc("filename")
);

cl::opt<std::string> SourceCode(
        "source",
        cl::desc("Specify input source code"),
        cl::init(""),
        cl::value_desc("source code")
);

// 3. List of function names (comma separated or multiple flags)
cl::list<std::string> FunctionNames(
        "func",
        cl::desc("Function names to process (can specify multiple times)"),
        cl::OneOrMore,
        cl::CommaSeparated,
        cl::value_desc("name")
);


cl::opt<std::string> domain(
        "domain",
        cl::desc("The name of evaluated domain"),
        cl::Required,
        cl::value_desc("string")
);

llvm::cl::list<std::string> JITConfig(
        "jit-config",
        llvm::cl::desc("Special configuration options for the JIT (can repeat)"),
        llvm::cl::ZeroOrMore,
        llvm::cl::value_desc("option")
);

int main(int argc, char** argv) {
  // Parse the command line
  cl::ParseCommandLineOptions(argc, argv, "JIT + Evaluator + Aggregator Tool\n");
  bool fromStdin=!SourceCode.empty();

  // Validate input: user must provide either file or stdin
  if (InputFile.empty() == SourceCode.empty()) {
    errs() << "Error: Must specify --file=<file> or --source\n";
    return 1;
  }

  // Echo the inputs
  outs() << "domain: " << domain << "\n";
  if (!InputFile.empty())
    outs() << "Input file: " << InputFile << "\n";
  if (fromStdin)
    outs() << "Reading source from stdin\n";

  outs() << "Function names:\n";
  for (const auto &fname : FunctionNames)
    outs() << "  " << fname << "\n";

  outs() << "JIT configuration options:\n";
  for (const auto &cfg : JITConfig) {
    outs() << "  " << cfg << "\n";
  }

  // Here you would pass InputFile/stdin, FunctionNames, and ID
  // to your JIT / Evaluator / Aggregator
  auto [ok, err] = compile(InputFile, JITConfig, SourceCode);
  llvm::errs() << err;
  return 0;
}