#include "Parsing.h"
#include "spvgentwo/Grammar.h"

#include <cstdio>
using namespace spvgentwo;

spvgentwo::Module examples::parsing(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger, spvgentwo::IReader* _pReader)
{
	Module module(_pAllocator, spv::Version, _pLogger);

	Grammar gram(_pAllocator); // init lookup table

	module.read(_pReader, gram);
	module.resolveIDs(); // turn IDs into Instruction pointers
	module.reconstructTypeAndConstantInfo(); // creates Type & Constant infos for lookup
	module.reconstructNames(); // parses strings for lookup of decorated instructions

	auto printOperand = [](const Operand& op)
	{
		if (op.isId())
		{
			printf("%%%u ", op.id);
		}
		else if (op.isLiteral())
		{
			printf("%u ", op.literal.value);
		}
		else if (op.isInstruction())
		{
			if (const char* name = op.instruction->getName(); name != nullptr && stringLength(name) > 1)
			{
				printf("%%%s ", name);
			}
			else
			{
				printf("%%%u ", op.instruction->getResultId());
			}
		}
		else if (op.isBranchTarget())
		{
			if (const char* name = op.branchTarget->getName(); name != nullptr && stringLength(name) > 1)
			{
				printf("%%%s ", name);
			}
			else
			{
				printf("%%%u ", op.branchTarget->front().getResultId());
			}
		}
	};

	auto print = [&](Instruction& instr)
	{
		auto* info = gram.getInfo(static_cast<unsigned int>(instr.getOperation()));

		if (const char* name = instr.getName(); name != nullptr && stringLength(name) > 1)
		{
			printf("%%%s = ", name);
		}
		else
		{
			if (auto id = instr.getResultId(); id != InvalidId)
			{
				printf("%%%u = ", id);
			}
		}

		printf("%s ", info->name);

		if (auto it = instr.getResultTypeOperand(); it != nullptr)
		{
			printOperand(*it);
		}

		for (auto it = instr.getFirstActualOperand(), end = instr.end(); it != end; ++it)
		{
			printOperand(*it);
		}

		printf("\n");
	};

	//module.assignIDs();
	module.iterateInstructions(print);

	return module;
}
