#pragma once
#include "spvgentwo/Spv.h"
#include "spvgentwo/Flag.h"

namespace spvgentwo
{
	// forward decls
	class Module;
	class Function;
	class IAllocator;
	class Instruction;
	class Grammar;
	class String;

	namespace ModulePrinter
	{
		class IModulePrinter;	
	}

	namespace LinkerHelper
	{
		// turn function definition into a declaration by removing its basic blocks and instruction decorates/names from the module
		bool removeFunctionBody(Function& _func);

		// adds & returns linkage OpDecorate for _varOrFunc ans symbol name
		Instruction* addLinkageDecoration(Instruction* _varOrFunc, spv::LinkageType _linkage, const char* name);

		// adds OpDecorateLinkage to global variables referenced in _func, use variable names (from OpName) as export name, if no name is present, it can't be exportet
		bool addLinkageDecorateForUsedGlobalVariables(const Function& _func, spv::LinkageType _linkage, IAllocator* _pAllocator = nullptr);

		// extract linkage type, symbol (optional) and name (optional) from OpDecorate, returns LinkageType::Max on error
		spv::LinkageType getLinkageTypeFromDecoration(const Instruction* _pDecoration, Instruction** _ppOutSymbol = nullptr, String* _pOutName = nullptr);

		enum class LinkerOptionBits
		{
			ImportMissingTypes = 1 << 0, // during instruction lookup, import missing types
			ImportMissingConstants = 1 << 1, // during instruction lookup, import missing constants
			ImportMissingExtensionSets = 1 << 2, // during instruction lookup, import missing OpExtInstImport
			ImportReferencedDecorations = 1 << 3, // referencing imported symbol
			ImportReferencedNames = 1 << 4, // referencing imported symbol
			ImportReferencedFunctions = 1 << 5, // functions called from an imported function, but were not exported themselves
			ImportReferencedVariables = 1 << 6, // global variables referenced in (auto) imported functions
			AssignResultIDs = 1 << 7, // on-the-fligh assing ResultIds while transfering instructions from lib to consumber module (leaves original IDs intact, can improve performance if module.assignIDs() is not used)
			RemoveLinkageCapability = 1 << 8, // remove linkage capability from the consumer library if all imports and exports have been resolved
			AutoAddRequiredCapabilitiesAndExtensions = 1 << 9, // instead of copying ALL Capabilities & Extensions from the all libs to the consumer module, use LinkerOptions.grammar to select only required Caps & Exts for the consumer module.
			UpdateEntryPointGlobalVarInterface = 1 << 10, // Add global variables referenced by the consumer EntryPoints to their OpEntryPoint, this should always be switched on unless Module.finalizeEntryPoints() is called after linking.
			CopyOpSourceStringInstructions = 1 << 11, // Copy OpString, OpSource, OpSourceContinued and OpSourceExtension instructions from lib to consumer module
			CopyOpLineInstructions = 1 << 12, // Copy OpLine, OpNoLine
			CopyOpModuleProcessedInstructions = 1 << 13, // Copy OpModuleProcessed
			All = CopyOpModuleProcessedInstructions | (CopyOpModuleProcessedInstructions - 1)
		};

		struct LinkerOptions 
		{
			Flag<LinkerOptionBits> flags{};
			ModulePrinter::IModulePrinter* printer = nullptr; // used to print instructions when transfered
			const Grammar* grammar = nullptr; // used for printing instructions & add required capabilities for the resulting module
			IAllocator* allocator = nullptr; // used for intermediate allocations, if nullptr, _consumer allocator is used
		};

		constexpr Flag<LinkerOptionBits> operator&(const LinkerOptions& l, const LinkerOptionBits& r) { return l.flags & r; }

		// import exported symbols of _lib to _consumber
		bool import(const Module& _lib, Module& _consumer, const LinkerOptions& _options);
	} // !LinkerHelper
} // spvgentwo