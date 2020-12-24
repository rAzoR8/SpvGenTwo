#include "spvgentwo/Logger.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/Grammar.h"

#include "common/HeapAllocator.h"
#include "common/BinaryFileReader.h"
#include "common/ConsoleLogger.h"
#include "common/ReflectionHelper.h"
#include "common/GrammarHelper.h"

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

// move to ReflectionHelper
Instruction::Iterator getDecorationLiteralOperand(const Instruction& decoration)
{
	Instruction::Iterator it = nullptr;

	if (decoration == spv::Op::OpDecorate)
	{
		it = decoration.getFirstActualOperand().next();
	}

	return it;
}

int main(int argc, char* argv[])
{
	ConsoleLogger logger;

	const char* spv = nullptr;
	const char* varName = nullptr; // variable to inspect

	bool printDescriptorSet = false;
	bool printLocation = false;

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
			printDescriptorSet = true;
		}
		else if (strcmp(arg, "--loc") == 0)
		{
			printLocation = true;
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

	if (varName != nullptr)
	{
		Instruction* inst = module.getInstructionByName(varName);

		if (inst == nullptr)
		{
			logger.logWarning("Instruction with OpName %s not found in module", varName);
			return -1;
		}

		List<const Instruction*> decorations(&alloc);
		ReflectionHelper::getVariableDecorations(module, inst, decorations);

		for (const Instruction* deco : decorations)
		{
			auto it = GrammarHelper::getOperandByName(deco, gram, "Decoration");

			if (it == nullptr || it.next() == nullptr) continue;

			if ((printDescriptorSet && it->getLiteral() == (unsigned)spv::Decoration::DescriptorSet) || 
				(printLocation && it->getLiteral() == (unsigned)spv::Decoration::Location))
			{
				printf("%u", it.next()->getLiteral().value);
			}
		}
	}
	
	return 0;
}