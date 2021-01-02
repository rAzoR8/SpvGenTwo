#include "spvgentwo/Logger.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/Grammar.h"

#include "common/HeapAllocator.h"
#include "common/BinaryFileReader.h"
#include "common/ConsoleLogger.h"
#include "common/ReflectionHelper.h"
#include "common/GrammarHelper.h"
#include "common/HeapList.h"
#include "common/HeapString.h"

#include <cstring>

using namespace spvgentwo;

template <class Pred, class Func>
void map(const List<const Instruction*>& instructions, Pred pred, Func func)
{
	for (const Instruction* instr : instructions)
	{
		if (pred(instr))
		{
			func(instr);
		}
	}
}

template <template <class> class Container>
void getList(const Container<Instruction>& _container, List<const Instruction*>& _instructions)
{
	for (const Instruction& instr : _container)
	{
		_instructions.emplace_back(&instr);
	}
}


HeapList<HeapString> getVariableNames(const Module& _module)
{
	HeapList<HeapString> names;
	for (const Instruction& var : _module.getGlobalVariables())
	{
		names.emplace_back(var.getName());
	}
	return names;
}

void printFunctions(const Module& _module)
{
	for (const EntryPoint& ep : _module.getEntryPoints())
	{
		printf("%s [EP]\n", ep.getName());
	}

	for (const Function& fun : _module.getFunctions())
	{
		printf("%s\n", fun.getName());
	}
}

int main(int argc, char* argv[])
{
	ConsoleLogger logger;

	const char* spv = nullptr;
	const char* varName = nullptr; // variable to inspect

	HeapList<spv::Decoration> decorationsToPrint;

	bool listFunctions = false;

	const int end = argc - 1;;

	for (int i = 1u; i < argc; ++i)
	{
		const char* arg = argv[i];
		if (spv == nullptr)
		{
			spv = arg;
		}
		else if (i < end && strcmp(arg, "--var") == 0)
		{
			varName = argv[++i];
		}
		else if (strcmp(arg, "--dset") == 0)
		{
			decorationsToPrint.emplace_back(spv::Decoration::DescriptorSet);
		}
		else if (strcmp(arg, "--loc") == 0)
		{
			decorationsToPrint.emplace_back(spv::Decoration::Location);
		}
		else if (strcmp(arg, "--funcs") == 0)
		{
			listFunctions = true;
		}
	}

	if (spv == nullptr)
	{
		return -1;
	}

	HeapAllocator alloc;

	BinaryFileReader reader(spv);
	if (reader.isOpen() == false)
	{
		logger.logError("Failed to open %s", spv);
		return -1;
	}

	Module module(&alloc, spv::Version, &logger);
	Grammar gram(&alloc);

	// parse the binary instructions & operands
	if (module.read(&reader, gram) == false)
	{
		return -1;
	}

	// turn <id> operands into instruction pointers
	if (module.resolveIDs() == false)
	{
		return -1;
	}

	// parses strings for lookup of named instructions, needed for printing
	if (module.reconstructNames() == false)
	{
		return -1;
	}

	if (listFunctions)
	{
		printFunctions(module);
	}

	//for (const String& name : getVariableNames(module))
	//{
	//	logger.logInfo("%s", name.c_str());
	//}

	List<const Instruction*> decorations(&alloc);

	if (varName != nullptr)
	{
		Instruction* inst = module.getInstructionByName(varName);

		if (inst == nullptr)
		{
			logger.logWarning("Instruction with OpName %s not found in module", varName);
			return -1;
		}

		ReflectionHelper::getVariableDecorations(inst, decorations);
	}
	else
	{
		getList(module.getDecorations(), decorations);
	}

	for (const Instruction* inst : decorations)
	{
		//auto it = deco->getFirstActualOperand(); // target

		//if (it != nullptr && it->isInstruction())
		//{
		//	if (const char* name = it->instruction->getName(); name != nullptr)
		//	{
		//		printf("%s: ", name);
		//	}
		//}

		for (spv::Decoration deco : decorationsToPrint)\
		{
			if (auto value = ReflectionHelper::getLiteralFromDecoration(deco, inst); value != ~0u) 
			{
				printf("%u\n", value);
			}
		}
	}
	
	return 0;
}