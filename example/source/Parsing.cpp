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

	auto printOperand = [&gram](const Operand& op, const Grammar::Operand& info)
	{
		if (op.isId())
		{
			printf("%%%u ", op.id);
		}
		else if (op.isLiteral())
		{
			if (info.category == Grammar::OperandCategory::BitEnum || info.category == Grammar::OperandCategory::ValueEnum)
			{
				const char* name = gram.getOperandName(info.kind, op.literal.value);
				printf("%s ", name == nullptr ? "UNKNOWN" : name);
			}
			else if (info.kind == Grammar::OperandKind::LiteralString)
			{
				size_t i = 0u;
				for (const char* str = reinterpret_cast<const char*>(&op.literal.value); i < sizeof(unsigned int) && str[i] != 0; ++i)
				{
					printf("%c", str[i]);				
				}
			}
			else
			{
				printf("%u ", op.literal.value);			
			} // check for OpConstant args like floats
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

		auto it = info->operands.begin();
		auto end = info->operands.end();
		for (const Operand& op : instr)
		{
			if (it == end)
			{
				printf("Invalid instruction");
				break;
			}

			printOperand(op, *it);

			if (it->kind != Grammar::OperandKind::ImageOperands &&
				it->kind != Grammar::OperandKind::LiteralString &&
				it->quantifier != Grammar::Quantifier::ZeroOrAny)
			{
				++it;
			}
			else if (it->kind == Grammar::OperandKind::LiteralString && hasStringTerminator(op.literal.value)) // reached end of string
			{
				++it;
			}
		}

		printf("\n");
	};

	module.iterateInstructions(print);

	return module;
}
