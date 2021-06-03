#include "spvgentwo/Module.h"
#include "spvgentwo/Grammar.h"
#include "spvgentwo/Templates.h"

#include "common/BinaryFileReader.h"
#include "common/BinaryFileWriter.h"
#include "common/ConsoleLogger.h"
#include "common/HeapList.h"
#include "common/HeapString.h"
#include "common/ModulePrinter.h"
#include "common/LinkerHelper.h"

#include <cstring> // strcmp
#include <cstdio> // printf, note windows console, and others too, don't print SPIR-V's UTF-8 strings properly
#include <cstdlib> // strtoul
#include <cctype> // to lower

using namespace spvgentwo;
using namespace ModulePrinter;

auto g_printer = ModuleSimpleFuncPrinter([](const char* _pStr) { printf("%s", _pStr); });
ConsoleLogger g_logger;
HeapAllocator g_alloc;
const Grammar g_gram(&g_alloc);

// import/export target
struct Target
{
	Instruction* instr = nullptr;
	const char* name = nullptr;
	spv::LinkageType type = spv::LinkageType::Max;
	bool exportAllReferencedVars = false; // for instr == OpFunction export
};

const char* g_out = nullptr;
const char* g_patchspv = nullptr;
const char* g_targetspv = nullptr;

HeapList<Target> g_targets;
HeapList<Module> g_libs;
LinkerHelper::LinkerOptions g_options{};

Module g_patchModule(&g_alloc, &g_logger);
Module g_targetModule(&g_alloc, &g_logger);

int patch(Module& _module, const HeapList<Target>& _targets, const char* _out)
{
	_module.addCapability(spv::Capability::Linkage);

	for (auto& t : _targets)
	{
		if (*t.instr == spv::Op::OpFunction && t.instr->getFunction()->isEntryPoint() == false)
		{
			Function* func = t.instr->getFunction();

			if (t.type == spv::LinkageType::Import)
			{
				if (func->empty() == false)
				{
					g_logger.logInfo("Functions marked for Import must not contain any basic blocks, removing %u blocks", func->size());
					LinkerHelper::removeFunctionBody(*func);
				}
			}
			else if (t.type == spv::LinkageType::Export && t.exportAllReferencedVars)
			{
				if (LinkerHelper::addLinkageDecorateForUsedGlobalVariables(*func, t.type, &g_alloc) == false)
				{
					return -1;
				}
			}
		}

		if (*t.instr != spv::Op::OpFunction && *t.instr != spv::Op::OpVariable)
		{
			g_logger.logError("Only OpFunctions which are not EntryPoints and global OpVariables can be imported/exported [%s]", g_gram.getInfo(static_cast<unsigned int>(t.instr->getOperation())));
			return -1;
		}

		Instruction* instr = _module.addDecorationInstr();
		instr->opDecorate(t.instr, spv::Decoration::LinkageAttributes, t.name, t.type);
		g_printer << "Added "; printInstruction(*instr, g_gram, g_printer); g_printer << "\n";
	}

	BinaryFileWriter writer(g_alloc, _out);
	if (writer.isOpen() == false)
	{
		g_logger.logError("Failed to open \'%s\'", _out);
		return -1;
	}

	_module.finalizeAndWrite(writer);
	return 0;
}

int link(HeapList<Module>& _libs, Module& _target, const LinkerHelper::LinkerOptions& _options, const char* _out)
{
	bool success = true;
	for (const Module& lib : _libs)
	{
		success &= LinkerHelper::import(lib, _target, _options);
	}

	if (success == false)
	{
		return -1;
	}

	BinaryFileWriter writer(g_alloc, _out);
	if (writer.isOpen() == false)
	{
		g_logger.logError("Failed to open \'%s\'", _out);
		return -1;
	}

	_target.finalizeEntryPoints();

	// don't need to call assignIDs, we are using AssignResultIDs
	if (_target.write(writer) == false) 
	{
		g_logger.logError("Failed to write \'%s\'", _out);
		return -1;
	}

	return 0;
}

void addTarget(spv::LinkageType type, int& _i, int _argc, char* _argv[])
{
	Instruction* instr = nullptr;
	const char* target = _argv[++_i];
	if (auto id = static_cast<unsigned int>(strtoul(target, nullptr, 10)); id != 0u && id != sgt_uint32_max)
	{
		instr = g_patchModule.getInstructionById(spv::Id{ id });
	}
	else
	{
		instr = g_patchModule.getInstructionByName(target);
	}

	if (instr == nullptr)
	{
		g_logger.logError("Could not find %s in %s", target, g_patchspv);
		return;
	}

	if (const char* name = _argv[++_i]; name != nullptr)
	{
		bool exportVars = false;
		if (type == spv::LinkageType::Export && _i + 1 < _argc && (strcmp(_argv[_i + 1], "-vars") == 0))
		{
			++_i;
			exportVars = true;
		}

		g_targets.emplace_back(instr, name, type, exportVars);
		g_logger.logInfo("Adding %s target instruction \'%s\' with name \'%s\'", type == spv::LinkageType::Import ? "import" : "export", target, name);
	}
}

int main(int argc, char* argv[])
{
	g_logger.logInfo("SpvGenTwoLinker by Fabian Wahlster - https://github.com/rAzoR8/SpvGenTwo");

	using namespace LinkerHelper;

	struct CMDOption
	{
		using Func = bool(int& i, int _argc, char* _argv[]);
		const char* str = nullptr;
		const char* alt = nullptr;
		Func* func = nullptr;
		int args = 0;
	};

	
#define FLAGOPTION(x, acronym) {"-" #x, "-"#acronym, []([[maybe_unused]] int& _i, [[maybe_unused]] int _argc, [[maybe_unused]] char* _argv[]){g_options.flags |= LinkerOptionBits::x; g_logger.logInfo("Option: " #x); return true;}}

	const CMDOption CmdOptions[] =
	{
		FLAGOPTION(ImportMissingTypes, types),
		FLAGOPTION(ImportMissingConstants, constants),
		FLAGOPTION(ImportMissingExtensionSets, extsets),
		FLAGOPTION(ImportReferencedDecorations, refdecos),
		FLAGOPTION(ImportReferencedNames, refnames),
		FLAGOPTION(ImportReferencedFunctions, reffuncs),
		FLAGOPTION(ImportReferencedVariables, refvars),
		//FLAGOPTION(AssignResultIDs, asid), // already on by default
		FLAGOPTION(RemoveLinkageCapability, rmcap),
		FLAGOPTION(AutoAddRequiredCapabilitiesAndExtensions, addcaps),
		FLAGOPTION(UpdateEntryPointGlobalVarInterface, variface),
		FLAGOPTION(CopyOpSourceStringInstructions, srcstrings),
		FLAGOPTION(CopyOpLineInstructions, lines),
		FLAGOPTION(CopyOpModuleProcessedInstructions, processed),
		{
			"-AllOptions", "-auto",
			[]([[maybe_unused]] int& _i, [[maybe_unused]] int _argc, [[maybe_unused]] char* _argv[]) {
				g_options.flags |= LinkerOptionBits::All; g_logger.logInfo("Option: AllOptions"); return true;
			}
		},
		{ // verbose
			"-PrintInstructions", "-verbose",
			[]([[maybe_unused]] int& _i, [[maybe_unused]] int _argc, [[maybe_unused]] char* _argv[]){
				g_options.grammar = &g_gram;
				g_options.printer = &g_printer;
				g_logger.logInfo("Verbose instruction printing enabled");
				return true;
			}
		},
		{ // patch spv
			"-patchspv", "-p",
			[](int& _i, [[maybe_unused]] int _argc, char* _argv[]) {
				g_patchspv = _argv[++_i];
				BinaryFileReader reader(g_alloc, g_patchspv);
				if (reader == false)
				{
					g_logger.logError("Failed to open \'%s\'", g_patchspv);
					return false;
				}
				else if (g_patchModule.readAndInit(reader, g_gram) == false)
				{
					return false;
				}
				g_logger.logInfo("Loaded patch target \'%s\'", g_patchspv);
				return true;
			},
			1 // one additonal path arg
		},
		{ // lib module
			"-lib", "-l",
			[](int& _i, [[maybe_unused]] int _argc, char* _argv[]) {
				const char* file = _argv[++_i];
				BinaryFileReader reader(g_alloc, file);
				if (reader == false)
				{
					g_logger.logError("Failed to open \'%s\'", file);
					return false;
				}
				else if (g_libs.emplace_back(&g_alloc, &g_logger).readAndInit(reader, g_gram) == false)
				{
					return false;
				}
				g_logger.logInfo("Loaded lib \'%s\'", file);
				return true;
			},
			1 // one additonal path arg
		},
		{ // target/consumer module
			"-consumer", "-c",
			[](int& _i, [[maybe_unused]] int _argc, char* _argv[]) {
				g_targetspv = _argv[++_i];
				BinaryFileReader reader(g_alloc, g_targetspv);
				if (reader == false)
				{
					g_logger.logError("Failed to open \'%s\'", g_targetspv);
					return false;
				}
				else if (g_targetModule.readAndInit(reader, g_gram) == false)
				{
					return false;
				}
				g_logger.logInfo("Loaded consumer \'%s\'", g_targetspv);
				return true;
			},
			1 // one additonal path arg
		},
		{ // (link) output  module
			"-out", "-o",
			[](int& _i, [[maybe_unused]] int _argc, char* _argv[]) {
				g_out = _argv[++_i];
				g_logger.logInfo("Output file \'%s\'", g_out);
				return true;
			},
			1 // one additonal path arg
		},
		{ // import symbol
			"-import", "-i",
			[](int& _i, int _argc, char* _argv[]) {
				addTarget(spv::LinkageType::Import, _i, _argc, _argv);
				return true;
			},
			2 // symbol name and export name
		},
		{ // import symbol
			"-export", "-e",
			[](int& _i, int _argc, char* _argv[]) {
				addTarget(spv::LinkageType::Export, _i, _argc, _argv);
				return true;
			},
			2 // symbol name and export name and -vars (optional)
		}
	};

	g_options.flags = LinkerOptionBits::AssignResultIDs;
	// we dont want to set LinkerOptionBits::UpdateEntryPointGlobalVarInterface, we call finalizeEntryPoints() manually 

	auto checkParam = [argc, argv, &CmdOptions](const char* arg, int& i) -> bool
	{
		auto casecmp = [](const char* l, const char* r)
		{
			while (*l != 0 && *r != 0)
			{
				if (tolower(*l) != tolower(*r))
					return false;
				++l; ++r;
			}
			return *l == 0 && *r == 0;
		};
		for (const CMDOption& o : CmdOptions)
		{
			if (casecmp(arg, o.alt) || casecmp(arg, o.str))
			{
				if (i + o.args < argc)
				{
					return o.func(i, argc, argv);				
				}
				g_logger.logError("Insufficient trailing arguments: i %i + args %i >= argc %i", i, o.args, argc);
				return false;
			}
		}
		g_logger.logWarning("Unkown parameter %s", arg);
		return false;
	};

	for (int i = 1; i < argc; ++i)
	{
		checkParam(argv[i], i);
	}

	if (g_targets.empty() == false)
	{
		return patch(g_patchModule, g_targets, g_out != nullptr ? g_out : g_patchspv);
	}

	if (g_libs.empty() == false)
	{
		return link(g_libs, g_targetModule, g_options, g_out != nullptr ? g_out : g_targetspv);
	}

	if (argc == 1 || (g_libs.empty() && g_targets.empty())) // print 'help'
	{
		for (const CMDOption& o : CmdOptions)
		{
			g_logger.logInfo("Option %s or %s with %i args", o.str, o.alt, o.args);
		}
	}

	return 0;
}