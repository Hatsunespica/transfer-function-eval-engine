#include <clang/CodeGen/CodeGenAction.h>
#include <clang/Driver/Compilation.h>
#include <clang/Driver/Driver.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/FrontendOptions.h>
#include <llvm/Config/llvm-config.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/VirtualFileSystem.h>
#include "llvm/IR/Module.h"
#include "llvm/ExecutionEngine/Orc/LLJIT.h"
#include "llvm/ExecutionEngine/Orc/ThreadSafeModule.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/ADT/APInt.h"
#include <llvm/ExecutionEngine/JITSymbol.h>
#include <llvm/ExecutionEngine/Orc/CompileUtils.h>
#include <llvm/ExecutionEngine/Orc/Core.h>
#include <llvm/ExecutionEngine/Orc/ExecutionUtils.h>
#include <llvm/ExecutionEngine/Orc/ExecutorProcessControl.h>
#include <llvm/ExecutionEngine/Orc/IRCompileLayer.h>
#include <llvm/ExecutionEngine/Orc/JITTargetMachineBuilder.h>
#include <llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h>
#include <llvm/ExecutionEngine/Orc/Shared/ExecutorAddress.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include "llvm/ExecutionEngine/Orc/SelfExecutorProcessControl.h"
#include <llvm/IR/DataLayout.h>
#include <llvm/IR/LLVMContext.h>
#include <vector>
#include "JIT.h"
#include "HEADER_INCLUDE_PATH.h"
#include <clang/Lex/PreprocessorOptions.h>
#include "clang/Frontend/TextDiagnosticPrinter.h"

using namespace llvm;
using namespace llvm::orc;
using namespace clang;

constexpr llvm::StringRef kTargetTriple = "x86_64-unknown-linux-gnu";

namespace {
    struct DiagsSaver : DiagnosticConsumer {
        std::string message;
        llvm::raw_string_ostream os{message};

        void HandleDiagnostic(DiagnosticsEngine::Level diagLevel, const Diagnostic &info) override {
            DiagnosticConsumer::HandleDiagnostic(diagLevel, info);
            const char *level;
            switch (diagLevel) {
                default:
                    return;
                case DiagnosticsEngine::Note:
                    level = "note";
                    break;
                case DiagnosticsEngine::Warning:
                    level = "warning";
                    break;
                case DiagnosticsEngine::Error:
                case DiagnosticsEngine::Fatal:
                    level = "error";
                    break;
            }

            llvm::SmallString<256> msg;
            info.FormatDiagnostic(msg);
            auto &sm = info.getSourceManager();
            auto loc = info.getLocation();
            auto fileLoc = sm.getFileLoc(loc);
            os << sm.getFilename(fileLoc) << ':' << sm.getSpellingLineNumber(fileLoc)
               << ':' << sm.getSpellingColumnNumber(fileLoc) << ": " << level << ": "
               << msg << '\n';
            if (loc.isMacroID()) {
                loc = sm.getSpellingLoc(loc);
                os << sm.getFilename(loc) << ':' << sm.getSpellingLineNumber(loc) << ':'
                   << sm.getSpellingColumnNumber(loc) << ": note: expanded from macro\n";
            }
        }
    };
}

std::pair<bool, std::string> compile(const std::string& fileName,
                                     const std::vector<std::string>& compileArgs,
                                     const std::string& source) {
    auto fs = llvm::vfs::getRealFileSystem();
    DiagsSaver dc;
    std::vector<const char *> args{"clang"};
    bool fromFile=!fileName.empty();
    if(fromFile){
        args.push_back(fileName.c_str());
        for(const auto& s:compileArgs){
            args.push_back(s.c_str());
        }

    }else{
        args.push_back("tmp.cpp");
        for(const auto& s:compileArgs){
            args.push_back(s.c_str());
        }
    }


    auto diagsOptions = DiagnosticOptions();
    auto diags = CompilerInstance::createDiagnostics(
            *fs,
            diagsOptions, &dc, false);
    clang::driver::Driver d(args[0], kTargetTriple, *diags, "cc", fs);
    d.setCheckInputsExist(false);
    std::unique_ptr<clang::driver::Compilation> comp(d.BuildCompilation(args));
    const auto &jobs = comp->getJobs();

    llvm:errs()<<jobs.size()<<"\n";
    for(auto it=jobs.begin();it!=jobs.end();++it){
        for(const auto& s:it->getArguments()){
            llvm::errs()<<s<<" ";
        }
        llvm::errs()<<"\n=====\n";
    }
    if (jobs.size() != 1)
        return {false, "only support one job"};
    const llvm::opt::ArgStringList &ccArgs = jobs.begin()->getArguments();
    auto ci = std::make_unique<CompilerInstance>();

    CompilerInvocation::CreateFromArgs(ci->getInvocation(), ccArgs, *diags);

    HeaderSearchOptions &HSO = ci->getInvocation().getHeaderSearchOpts();
    for(const auto& path:INCLUDE_PATHS){
        HSO.AddPath(path,
                    clang::frontend::Angled,
                    false, false);
    }

    ci->createDiagnostics(*fs, &dc, false);
    ci->getDiagnostics().getDiagnosticOptions().ShowCarets = false;
    ci->createFileManager(fs);
    ci->createSourceManager(ci->getFileManager());

    ci->getDiagnostics().setClient(
        new clang::TextDiagnosticPrinter(llvm::errs(), ci->getDiagnostics().getDiagnosticOptions())
        );
    if (!fromFile) {
        //ci->getPreprocessorOpts().addRemappedFile(
        //    "tmp.cpp", llvm::MemoryBuffer::getMemBuffer(source).release());
auto buffer = llvm::MemoryBuffer::getMemBuffer(source, "<jit-input>");
        ci->getSourceManager().setMainFileID(
    ci->getSourceManager().createFileID(std::move(buffer))
);
auto &FEOpts = ci->getInvocation().getFrontendOpts();
FEOpts.Inputs.clear();
FEOpts.Inputs.emplace_back(
    ci->getSourceManager().getBufferOrFake(ci->getSourceManager().getMainFileID()),
    clang::InputKind(clang::Language::CXX)
);

    }
    ci->getCodeGenOpts().DisableFree = false;
    ci->getFrontendOpts().DisableFree = false;

    LLVMInitializeX86AsmParser();
    LLVMInitializeX86AsmPrinter();
    LLVMInitializeX86Target();
    LLVMInitializeX86TargetInfo();
    LLVMInitializeX86TargetMC();

    std::unique_ptr<clang::EmitLLVMOnlyAction> action =
            std::make_unique<clang::EmitLLVMOnlyAction>();

    if (!ci->ExecuteAction(*action)) {
        llvm::errs() << "Failed to emit LLVM IR\n";
        return {false, "error"};
    }


    std::unique_ptr<llvm::Module> M = action->takeModule();
    //M->dump();

    /*switch (ci->getFrontendOpts().ProgramAction) {
    case frontend::ActionKind::EmitObj: {
      EmitObjAction action;
      ci->ExecuteAction(action);
    } break;
    case frontend::ActionKind::EmitAssembly: {
      EmitAssemblyAction action;
      ci->ExecuteAction(action);
    } break;
    case frontend::ActionKind::EmitLLVM: {
      EmitLLVMAction action;
      ci->ExecuteAction(action);
    } break;
    default:
      return {false, "unhandled action"};
    }*/

    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();

    // ─────────────────────────────────────────────
    // Build JIT
    // ─────────────────────────────────────────────
    std::unique_ptr<llvm::orc::LLJIT> JIT=llvm::cantFail(llvm::orc::LLJITBuilder().create());

    auto EPC = cantFail(orc::SelfExecutorProcessControl::Create());
    auto ES = std::make_unique<orc::ExecutionSession>(std::move(EPC));

    orc::JITTargetMachineBuilder JTMB(
            ES->getExecutorProcessControl().getTargetTriple());

    auto DL = cantFail(JTMB.getDefaultDataLayoutForTarget());

    // allow JITed code to use libstdc++ / libc++ / libLLVM symbols
    JIT->getMainJITDylib().addGenerator(
            cantFail(DynamicLibrarySearchGenerator::GetForCurrentProcess(DL.getGlobalPrefix()))
    );

    // ─────────────────────────────────────────────
    // Load LLVM IR file
    // ─────────────────────────────────────────────
    //std::unique_ptr<Module> M(parseIRFile("wrapper.ll", err, ctx));
    if (!M) {
        return {false, "error"};
    }

    llvm::ExitOnError ExitOnErr;

    ExitOnErr(JIT->addIRModule(ThreadSafeModule(std::move(M), std::make_unique<LLVMContext>())));

    // ─────────────────────────────────────────────
    // Lookup symbol
    // ─────────────────────────────────────────────
    using TestFnTy = int(*)(int,int);
    auto testSym = ExitOnErr(JIT->lookup("test"));


    TestFnTy testFn = (TestFnTy)testSym.toPtr<TestFnTy>();
    outs() << "Result 1 = " << testFn(1,2) << "\n";


    auto sym = ExitOnErr(JIT->lookup("getKB"));

    using FnTy = void(*)(APInt**, APInt*);
    FnTy getVector_C = (FnTy)sym.toPtr<FnTy>();

    // ─────────────────────────────────────────────
    // Prepare arguments
    // ─────────────────────────────────────────────
    std::vector<APInt> arg0{APInt(64, 123), APInt(64, 123)};
    std::vector<APInt> arg1{APInt(64, 456), APInt(64, 456)};

    std::vector<APInt*> vargs{arg0.data(), arg1.data()};
    std::vector<APInt> result={APInt(64, 456), APInt(64, 456)};

    // ─────────────────────────────────────────────
    // CALL THE JIT FUNCTION
    // ─────────────────────────────────────────────
    getVector_C(vargs.data(), result.data());

    outs() << "Result 0 = " << result[0] << "\n";
    outs() << "Result 1 = " << result[1] << "\n";

    if (auto Err = ES->endSession())
        ES->reportError(std::move(Err));
    return {true, std::move(dc.message)};
}