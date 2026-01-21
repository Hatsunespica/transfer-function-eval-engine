#include "llvm/Support/CommandLine.h"
#include "JIT.h"
#include "llvm/Support/raw_ostream.h"
#include "EvaluationEngine.h"


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

cl::opt<std::string> DataCachePath(
        "data-cache-path",
        cl::desc("Specify data cache path"),
        cl::init(""),
        cl::value_desc("data cache path")
);

cl::list<std::string> TransferFunctionNames(
        "transfer-function",
        cl::desc("Transfer Function names to process"),
        cl::OneOrMore,
        cl::CommaSeparated,
        cl::value_desc("transfer function names")
);

cl::list<std::string> BaseTransferFunctionNames(
        "base-transfer-function",
        cl::desc("Base transfer Function names to process"),
        cl::OneOrMore,
        cl::CommaSeparated,
        cl::value_desc("base transfer function names")
);

cl::opt<size_t> MaxOperationLength(
        "max-operation-length",
        cl::desc("The maximal length of operations"),
        cl::Required,
        cl::value_desc("length")
);

cl::opt<std::string> domain(
        "domain",
        cl::desc("The name of evaluated domain"),
        cl::Required,
        cl::value_desc("string")
);

cl::opt<size_t> AbstractDomainLength(
        "abstract-domain-length",
        cl::desc("The length of the abstract domain"),
        cl::Required,
        cl::value_desc("length")
);

cl::opt<size_t> TransferFunctionArity(
        "transfer-function-arity",
        cl::desc("The arity of transfer functions"),
        cl::Required,
        cl::value_desc("arity")
);

cl::list<size_t> EnumerateBitWidth(
    "enumerate-bit-width",
    cl::desc("Bit widths used for enumeration"),
    cl::OneOrMore,
    cl::CommaSeparated,
    cl::value_desc("int")
);

cl::list<size_t> SampleBitWidth(
    "sample-bit-width",
    cl::desc("Bit widths used for sampling"),
    cl::OneOrMore,
    cl::CommaSeparated,
    cl::value_desc("int")
);

cl::list<size_t> SampleAbstractAmount(
    "sample-abstract-amount",
    cl::desc("Number of abstract samples to generate"),
    cl::OneOrMore,
    cl::CommaSeparated,
    cl::value_desc("int")
);

cl::list<size_t> SampleConcreteAmount(
    "sample-concrete-amount",
    cl::desc("Number of concrete samples to generate"),
    cl::OneOrMore,
    cl::CommaSeparated,
    cl::value_desc("int")
);


llvm::cl::list<std::string> JITConfig(
        "jit-config",
        llvm::cl::desc("Special configuration options for the JIT (can repeat)"),
        llvm::cl::ZeroOrMore,
        llvm::cl::value_desc("option")
);

#include "llvm/Support/KnownBits.h"

int main(int argc, char** argv) {
    llvm::KnownBits a(4), b(4);
    b.One |= llvm::APInt(4, 1);
    a.dump();
    b.dump();
    llvm::KnownBits::add(a,a).dump();
    (a&(llvm::KnownBits::add(a, b))).dump();
    exit(0);
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
  for (const auto &fname : TransferFunctionNames)
    outs() << "  " << fname << "\n";

  outs() << "JIT configuration options:\n";
  for (const auto &cfg : JITConfig) {
    outs() << "  " << cfg << "\n";
  }

    // Here you would pass InputFile/stdin, FunctionNames, and ID
    // to your JIT / Evaluator / Aggregator
    // auto [ok, err] = compile(InputFile, JITConfig, SourceCode);
    // llvm::errs() << err;
    std::unique_ptr<llvm::orc::LLJIT> jitModulePtr = createJITModule(InputFile, JITConfig, SourceCode);
    using namespace Evaluation;
    size_t ConcreteDomainLength = 1;
    EvaluationParameter evaluationParameter(DataCachePath, TransferFunctionNames, BaseTransferFunctionNames,
        MaxOperationLength, domain,
        ConcreteDomainLength, AbstractDomainLength, TransferFunctionArity, EnumerateBitWidth, SampleBitWidth, SampleAbstractAmount,
        SampleConcreteAmount);
    EvaluationBatch evaluationBatch(*jitModulePtr, evaluationParameter);
    EvaluationEngine evaluationEngine(evaluationParameter, evaluationBatch);
    auto result = evaluationEngine.evaluateBatch();
    printEvaluationResultOnAllBitWidth(result);

  return 0;
}