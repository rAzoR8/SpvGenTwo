#include "spvgentwo/Logger.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/Grammar.h"
#include "common/HeapAllocator.h"
#include "common/BinaryFileWriter.h"
#include "common/BinaryFileReader.h"
#include "common/ConsoleLogger.h"

#include <cstring>

using namespace spvgentwo;

int main(int argc, char* argv[])
{
	ConsoleLogger logger;

	const char* spv = nullptr;
	bool serialize = false; // for debugging

	for (int i = 1u; i < argc; ++i)
	{
		const char* arg = argv[i];
		if (spv == nullptr)
		{
			spv = arg;
		}
		else if (strcmp(arg, "--serialize"))
		{
			serialize = true;
		}
	}

	if (spv == nullptr)
	{
		return -1;
	}

	HeapAllocator alloc;

	if (BinaryFileReader reader(spv); reader.isOpen())
	{
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

		// creates type & constant infos for lookup (needed for codegen)
		if (module.reconstructTypeAndConstantInfo() == false)
		{
			return -1;
		}

		// parses strings for lookup of named instructions, needed for printing
		if (module.reconstructNames() == false)
		{
			return -1;
		}

		auto printOperand = [&gram](const Operand& op, const Grammar::Operand* info)
		{
			if (op.isId())
			{
				printf(" %%%u", op.id);
			}
			else if (op.isLiteral())
			{
				if (info->category == Grammar::OperandCategory::BitEnum || info->category == Grammar::OperandCategory::ValueEnum)
				{
					const char* name = gram.getOperandName(info->kind, op.literal.value);
					printf(" %s", name == nullptr ? "UNKNOWN" : name);
				}
				else if (info->kind == Grammar::OperandKind::LiteralString)
				{
					auto prev = info - 1u;

					if (prev->kind != Grammar::OperandKind::LiteralString) // danger hack
					{
						printf(" ");
					}

					size_t i = 0u;
					for (const char* str = reinterpret_cast<const char*>(&op.literal.value); i < sizeof(unsigned int) && str[i] != 0; ++i)
					{
						printf("%c", str[i]);
					}
				}
				else
				{
					printf(" %u", op.literal.value);
				} // check for OpConstant args like floats
			}
			else if (op.isInstruction())
			{
				if (const char* name = op.instruction->getName(); name != nullptr && stringLength(name) > 1)
				{
					printf(" %%%s", name);
				}
				else
				{
					printf(" %%%u", op.instruction->getResultId());
				}
			}
			else if (op.isBranchTarget())
			{
				if (const char* name = op.branchTarget->getName(); name != nullptr && stringLength(name) > 1)
				{
					printf(" %%%s", name);
				}
				else
				{
					printf(" %%%u", op.branchTarget->front().getResultId());
				}
			}
		};

		auto print = [&](Instruction& instr)
		{
			auto* info = gram.getInfo(static_cast<unsigned int>(instr.getOperation()));

			if (const char* name = instr.getName(); name != nullptr && stringLength(name) > 1)
			{
				printf("%%%s =", name);
			}
			else
			{
				if (auto id = instr.getResultId(); id != InvalidId)
				{
					printf("%%%u =", id);
				}
			}

			printf("\t%s", info->name);

			auto it = info->operands.begin();
			auto end = info->operands.end();
			for (const Operand& op : instr)
			{
				if (it == end)
				{
					printf("Invalid instruction");
					break;
				}

				printOperand(op, it);

				if (it->kind != Grammar::OperandKind::ImageOperands &&
					it->kind != Grammar::OperandKind::LiteralString &&
					it->kind != Grammar::OperandKind::Decoration &&
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

		if (serialize)
		{
			if (BinaryFileWriter writer("serialized.spv"); writer.isOpen())
			{
				module.write(&writer);
			}
		}
	}
	else
	{
		logger.logError("Failed to open %s", spv);
	}

	return 0;
}