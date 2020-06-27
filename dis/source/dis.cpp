#include "spvgentwo/Logger.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/Grammar.h"
#include "common/HeapAllocator.h"
#include "common/BinaryFileWriter.h"
#include "common/BinaryFileReader.h"
#include "common/ConsoleLogger.h"

#include <cstring>

#ifndef NDEBUG
#include <cstdlib> // system
#endif // !_NDEBUG

using namespace spvgentwo;

int main(int argc, char* argv[])
{
	ConsoleLogger logger;

	const char* spv = nullptr;
	bool serialize = false; // for debugging
	bool reassignIDs = false;
	bool callSPIRVDis = false;

	for (int i = 1u; i < argc; ++i)
	{
		const char* arg = argv[i];
		if (spv == nullptr)
		{
			spv = arg;
		}
		else if (strcmp(arg, "--serialize") == 0)
		{
			serialize = true;
		}
		else if (strcmp(arg, "--assignIDs") == 0 || strcmp(arg, "--assignids") == 0)
		{
			reassignIDs = true;
		}
		else if (strcmp(arg, "--calldis") == 0)
		{
			callSPIRVDis = true;
		}
	}

	if (spv == nullptr)
	{
		return -1;
	}

	HeapAllocator alloc;

#ifndef NDEBUG
	if (callSPIRVDis)
	{
		String cmd(&alloc, "spirv-dis ");
		cmd += spv;
		system(cmd.c_str());
	}
#endif

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

		auto printOperand = [&gram, &alloc](Instruction& instr, const Operand& op, const Grammar::Operand* info)
		{
			if (op.isId() && info->kind != Grammar::OperandKind::IdResult) // skip result id
			{
				printf(" \x1B[33m%%%u\033[0m", op.id);
			}
			else if (op.isLiteral())
			{
				if (instr.getOperation() == spv::Op::OpExtInst)
				{
					bool printedName = false;
					if (auto set = instr.getFirstActualOperand(); set != nullptr && set->isInstruction() && set->instruction->getOperation() == spv::Op::OpExtInstImport) // extension set
					{
						String extName(&alloc);
						getLiteralString(extName, set->instruction->getFirstActualOperand(), set->instruction->end());

						Grammar::Extension ext = Grammar::Extension::Core;
						if (extName == "GLSL.std.450")
						{
							ext = Grammar::Extension::Glsl;
						}
						else if (extName == "OpenCL.std")
						{
							ext = Grammar::Extension::OpenCl;
						}

						if (ext != Grammar::Extension::Core)
						{
							if (auto* extInfo = gram.getInfo(static_cast<unsigned int>(op.literal.value), ext); extInfo != nullptr)
							{
								printf(" \x1B[35m%s\033[0m", extInfo->name);
								printedName = true;
							}
						}
					}

					if (printedName == false)
					{
						printf(" \x1B[31m%u\033[0m", op.literal.value);
					}
				} 
				else if (info->category == Grammar::OperandCategory::BitEnum || info->category == Grammar::OperandCategory::ValueEnum)
				{
					const char* name = gram.getOperandName(info->kind, op.literal.value);
					printf(" %s", name == nullptr ? "UNKNOWN" : name);
				}
				else
				{
					printf(" \x1B[31m%u\033[0m", op.literal.value);
				} // check for OpConstant args like floats
			}
			else if (op.isInstruction())
			{
				if (const char* name = op.instruction->getName(); name != nullptr && stringLength(name) > 1)
				{
					printf(" \x1B[33m%%%s\033[0m", name);
				}
				else
				{
					printf(" \x1B[33m%%%u\033[0m", op.instruction->getResultId());
				}
			}
			else if (op.isBranchTarget())
			{
				if (const char* name = op.branchTarget->getName(); name != nullptr && stringLength(name) > 1)
				{
					printf(" \x1B[33m%%%s\033[0m", name);
				}
				else
				{
					printf(" %%%u", op.branchTarget->front().getResultId());
				}
			}
		};

		bool success = true;
		auto print = [&](Instruction& instr) -> bool
		{
			auto* info = gram.getInfo(static_cast<unsigned int>(instr.getOperation()));

			if (const char* name = instr.getName(); name != nullptr && stringLength(name) > 1)
			{
				printf("\x1B[34m%%%s\033[0m =", name);
			}
			else
			{
				if (auto id = instr.getResultId(); id != InvalidId)
				{
					printf("\x1B[34m%%%u\033[0m =", id);
				}
			}

			printf("\t%s", info->name);

			auto infoIt = info->operands.begin();
			auto infoEnd = info->operands.end();

			for (auto it = instr.begin(), end = instr.end(); it != end;)
			{
				if (infoIt == infoEnd)
				{
					printf("\nINVALID INSTRUCTION\n");
					success = false;
					return true; // stop iteration
				}

				if (infoIt->kind == Grammar::OperandKind::LiteralString)
				{
					String litString(&alloc);
					it = getLiteralString(litString, it, end);

					printf(" \"\x1B[32m%s\033[0m\"", litString.c_str());

					++infoIt;
					continue;
				}

				printOperand(instr, *it, infoIt);

				if (infoIt->kind != Grammar::OperandKind::ImageOperands &&
					infoIt->kind != Grammar::OperandKind::LiteralString &&
					infoIt->kind != Grammar::OperandKind::ExecutionMode &&
					infoIt->kind != Grammar::OperandKind::Decoration &&
					infoIt->quantifier != Grammar::Quantifier::ZeroOrAny)
				{
					++infoIt;
				}

				++it;
			}

			printf("\n");
			return false;
		};

		if (reassignIDs)
		{
			module.assignIDs(); // compact ids
		}

		printf("# SPIR-V Version %u.%u\n", module.getMajorVersion(), module.getMinorVersion());
		printf("# Generator 0x%X\n", module.getSpvGenerator());
		printf("# Bound %u\n", module.getSpvBound());
		printf("# Schema %u\n\n", module.getSpvSchema());

		// print text
		module.iterateInstructions(print);

		if (success == false)
		{
			return -1;
		}

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