#include "common/ModuleToString.h"

#include "spvgentwo/String.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/Grammar.h"

void spvgentwo::ModuleStringPrinter::append(const char* _pStr, const char* _pushColor, const char* _popColor)
{
    if (_pushColor != nullptr && m_useColor)
    {
        m_buffer.append(_pushColor);
    }

    if(_pStr != nullptr)
    {
        m_buffer.append(_pStr);
    }

    if (_popColor != nullptr && m_useColor)
    {
        m_buffer.append(_popColor);
    }
}

void spvgentwo::ModuleStringPrinter::append(unsigned int _literal, const char* _pushColor, const char* _popColor)
{
    if (_pushColor != nullptr && m_useColor)
    {
        m_buffer.append(_pushColor);
    }

    char buf[11] = { '\0' }; // max length is log10(UINT_MAX) ~ 9.6 + null terminator -> 11

	unsigned int val = _literal;

	unsigned int len = 0u; // compute length of our string
	for (; val != 0u; val /= 10u, ++len) {}
	len = _literal == 0u ? 1u : len;

	do
	{
		buf[--len] = '0' + (_literal % 10u);
		_literal /= 10u;
	}while (_literal != 0 && len > 0u);

    m_buffer.append(static_cast<const char*>(buf));

    if (_popColor != nullptr && m_useColor)
    {
        m_buffer.append(_popColor);
    }
}

bool spvgentwo::moduleToString(Module& _module, const Grammar& _grammar, IAllocator* _pAlloc, IModulePrinter* _pOutput, bool _writePreamble)
{
	if (_pAlloc == nullptr || _pOutput == nullptr)
	{
		return false;
	}

	String extName(_pAlloc);
	auto printOperand = [&](const Instruction& instr, const Operand& op, const Grammar::Operand* info)
	{
		if (op.isId() && info->kind == Grammar::OperandKind::IdResult)  // skip result id
		{
			return;
		}

		*_pOutput << " ";
		if (op.isId() && info->kind != Grammar::OperandKind::IdResult)
		{
			*_pOutput << "%";
			_pOutput->append(op.id, "\x1B[33m", "\033[0m");
		}
		else if (op.isLiteral())
		{
			if (instr.getOperation() == spv::Op::OpExtInst)
			{
				bool printedName = false;
				if (auto set = instr.getFirstActualOperand(); set != nullptr && set->isInstruction() && set->instruction->getOperation() == spv::Op::OpExtInstImport) // extension set
				{
					extName.clear();
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
						if (auto* extInfo = _grammar.getInfo(static_cast<unsigned int>(op.literal.value), ext); extInfo != nullptr)
						{
							_pOutput->append(extInfo->name, "\x1B[35m", "\033[0m");
							printedName = true;
						}
					}
				}

				if (printedName == false)
				{
					_pOutput->append(op.literal.value, "\x1B[31m", "\033[0m");
				}
			}
			else if (info->category == Grammar::OperandCategory::BitEnum || info->category == Grammar::OperandCategory::ValueEnum)
			{
				const char* name = _grammar.getOperandName(info->kind, op.literal.value);
				_pOutput->append(name == nullptr ? "UNKNOWN" : name);
			}
			else if (info->kind == Grammar::OperandKind::LiteralSpecConstantOpInteger)
			{
				if (auto* instrInfo = _grammar.getInfo(op.literal.value); instrInfo != nullptr)
				{
					_pOutput->append(instrInfo->name);
				}
				else
				{
					_pOutput->append(op.literal.value, "\x1B[31m", "\033[0m");
				}
			}
			else
			{
				_pOutput->append(op.literal.value, "\x1B[31m", "\033[0m");
			} // TODO: check for OpConstant args like floats
		}
		else if (op.isInstruction())
		{
			*_pOutput << "%";
			if (op.instruction == nullptr)
			{
				_pOutput->append("INVALIDINSTRPTR", "\x1B[33m", "\033[0m");
				return;
			}

			if (const char* name = op.instruction->getName(); name != nullptr && stringLength(name) > 1)
			{
				_pOutput->append(name, "\x1B[33m", "\033[0m");
			}
			else
			{
				_pOutput->append(op.instruction->getResultId(), "\x1B[33m", "\033[0m");
			}
		}
		else if (op.isBranchTarget())
		{
			*_pOutput << "%";

			if (op.branchTarget == nullptr)
			{
				_pOutput->append("INVALIDBASICBLOCKPTR", " \x1B[33m", "\033[0m");
				return;
			}

			if (const char* name = op.branchTarget->getName(); name != nullptr && stringLength(name) > 1)
			{
				_pOutput->append(name, "\x1B[33m", "\033[0m");
			}
			else
			{
				_pOutput->append(op.branchTarget->getLabel()->getResultId());
			}
		}
	};

	String litString(_pAlloc);

	bool success = true;
	auto print = [&](const Instruction& instr) -> bool
	{
		auto* info = _grammar.getInfo(static_cast<unsigned int>(instr.getOperation()));

		if (instr.hasResult())
		{
			*_pOutput << "%";
			if (const char* name = instr.getName(); name != nullptr && stringLength(name) > 1)
			{
				_pOutput->append(name, "\x1B[34m", "\033[0m");
				*_pOutput << " = ";
			}
			else if (auto id = instr.getResultId(); id != InvalidId)
			{
				_pOutput->append(id, "\x1B[34m", "\033[0m");
				*_pOutput << " =\t";
			}
			else
			{
				return true; // invalid instruction
			}
		}
		else
		{
			*_pOutput << "\t";
		}

		*_pOutput << info->name;

		auto infoIt = info->operands.begin();
		auto infoEnd = info->operands.end();

		for (auto it = instr.begin(), end = instr.end(); it != end;)
		{
			if (infoIt == infoEnd)
			{
				_pOutput->append("\nINVALID INSTRUCTION\n");
				success = false;
				return true; // stop iteration
			}

			if (infoIt->kind == Grammar::OperandKind::LiteralString)
			{
				litString.clear();
				it = getLiteralString(litString, it, end);
				*_pOutput << " \"";
				_pOutput->append(litString.c_str(), "\x1B[32m", "\033[0m");
				*_pOutput << "\"";

				++infoIt;
				continue;
			}

			printOperand(instr, *it, infoIt);

			if (infoIt->kind != Grammar::OperandKind::ImageOperands &&
				infoIt->kind != Grammar::OperandKind::LiteralSpecConstantOpInteger &&
				infoIt->kind != Grammar::OperandKind::Decoration &&
				infoIt->kind != Grammar::OperandKind::ExecutionMode &&
				infoIt->kind != Grammar::OperandKind::LiteralString &&
				infoIt->quantifier != Grammar::Quantifier::ZeroOrAny)
			{
				++infoIt;
			}

			++it;
		}

		_pOutput->append("\n");
		return false;
	};

	if (_writePreamble)
	{
		*_pOutput << "# SPIR-V Version " << _module.getMajorVersion() << "." << _module.getMinorVersion() << "\n";
		*_pOutput << "# Generator " << _module.getSpvGenerator() << "\n";
		*_pOutput << "# Bound " << _module.getSpvBound() << "\n";
		*_pOutput << "# Schema " << _module.getSpvBound() << "\n\n";
	}

	// print text
	_module.iterateInstructions(print);

	return success;
}