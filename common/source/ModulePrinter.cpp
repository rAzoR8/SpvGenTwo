#include "common/ModulePrinter.h"
#include "common/ExternalMemoryAllocator.h"

#include "spvgentwo/String.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/Grammar.h"

namespace
{
	// _outBuffer must have space for at least 10 digits ( max length is log10(UINT_MAX) ~ 9.6 )
	void uintToString(unsigned int _value, char* _outBuffer)
	{
		unsigned int len = 0u; // count length of our string
		for (unsigned int val = _value; val != 0u; val /= 10u, ++len) {}
		len = _value == 0u ? 1u : len;

		do
		{
			_outBuffer[--len] = '0' + (_value % 10u);
			_value /= 10u;
		} while (_value != 0 && len > 0u);
	}

	spvgentwo::Instruction::Iterator appendLiteralString(spvgentwo::ModulePrinter::IModulePrinter& _printer, spvgentwo::Instruction::Iterator _it, spvgentwo::Instruction::Iterator _end, const char* _pushColor, const char* _popColor)
	{
		for (; _it != _end && _it->isLiteral(); ++_it)
		{
			char buf[5] = { '\0' }; // make sure we always have a terminator
			const char* str = reinterpret_cast<const char*>(&_it->literal.value);
			for (unsigned int i = 0u; i < sizeof(unsigned int); ++i)
			{
				buf[i] = str[i];
				if (str[i] == '\0')
				{
					_printer.append(buf, _pushColor, _popColor);
					return _it.next();
				}
			}
			_printer.append(buf, _pushColor, _popColor);
		}

		return _it;
	}

	void printOperand(const spvgentwo::Instruction& _instr, const spvgentwo::Operand& op, const spvgentwo::Grammar::Operand& _info, const spvgentwo::Grammar& _grammar, spvgentwo::ModulePrinter::IModulePrinter& _printer, spvgentwo::ModulePrinter::PrintOptions _options)
	{
		using namespace spvgentwo;

 		if (op.isId() && _info.kind == Grammar::OperandKind::IdResult)  // skip result id
		{
			return;
		}

		_printer << " ";
		if (op.isId() && _info.kind != Grammar::OperandKind::IdResult)
		{
			_printer << "%";
			_printer.append(op.id, "\x1B[33m", "\033[0m");
		}
		else if (op.isLiteral())
		{
			if (_instr.getOperation() == spv::Op::OpExtInst)
			{
				bool printedName = false;
				if (auto set = _instr.getFirstActualOperand(); set != nullptr && set->isInstruction() && *set->instruction == spv::Op::OpExtInstImport) // extension set
				{					
					Grammar::Extension ext = Grammar::Extension::Core;
					if (compareLiteralString("GLSL.std.450", set->instruction->getFirstActualOperand(), set->instruction->end()))
					{
						ext = Grammar::Extension::Glsl;
					}
					else if (compareLiteralString("OpenCL.std", set->instruction->getFirstActualOperand(), set->instruction->end()))
					{
						ext = Grammar::Extension::OpenCl;
					}

					if (ext != Grammar::Extension::Core)
					{
						if (auto* extInfo = _grammar.getInfo(static_cast<unsigned int>(op.literal.value), ext); extInfo != nullptr)
						{
							_printer.append(extInfo->name, "\x1B[35m", "\033[0m");
							printedName = true;
						}
					}
				}

				if (printedName == false)
				{
					_printer.append(op.literal.value, "\x1B[31m", "\033[0m");
				}
			}
			else if (_info.category == Grammar::OperandCategory::BitEnum || _info.category == Grammar::OperandCategory::ValueEnum)
			{
				if (const char* name = _grammar.getOperandName(_info.kind, op.literal.value); name != nullptr && (_options & ModulePrinter::PrintOptionsBits::OperandName))
				{
					_printer.append(name);				
				}
				else
				{
					_printer.append(op.literal.value, "\x1B[31m", "\033[0m");
				}
			}
			else
			{
				_printer.append(op.literal.value, "\x1B[31m", "\033[0m");
			} // TODO: check for OpConstant args like floats
		}
		else if (op.isInstruction())
		{
			_printer << "%";
			if (op.instruction == nullptr)
			{
				_printer.append("INVALIDINSTRPTR", "\x1B[33m", "\033[0m");
				return;
			}

			if (const char* name = op.instruction->getName(); (_options & ModulePrinter::PrintOptionsBits::InstructionName) && name != nullptr && stringLength(name) > 1)
			{
				_printer.append(name, "\x1B[33m", "\033[0m");
			}
			else
			{
				_printer.append(op.instruction->getResultId(), "\x1B[33m", "\033[0m");
			}
		}
		else if (op.isBranchTarget())
		{
			_printer << "%";

			if (op.branchTarget == nullptr)
			{
				_printer.append("INVALIDBASICBLOCKPTR", " \x1B[33m", "\033[0m");
				return;
			}

			if (const char* name = op.branchTarget->getName(); _options & ModulePrinter::PrintOptionsBits::OperandName && name != nullptr && stringLength(name) > 1)
			{
				_printer.append(name, "\x1B[33m", "\033[0m");
			}
			else
			{
				_printer.append(op.branchTarget->getLabel()->getResultId());
			}
		}
	}
} // !anonymous

void spvgentwo::ModulePrinter::ModuleStringPrinter::append(const char* _pStr, const char* _pushColor, const char* _popColor)
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

bool spvgentwo::ModulePrinter::printInstruction(const Instruction& _instr, const Grammar& _grammar, IModulePrinter& _printer, PrintOptions _options, const char* _pIndentation)
{
	auto* instrInfo = _grammar.getInfo(static_cast<unsigned int>(_instr.getOperation()));

	if (_instr.hasResult() && ((_options & PrintOptionsBits::InstructionName) || (_options & PrintOptionsBits::ResultId)))
	{
		_printer << "%";
		if (const char* name = _instr.getName(); (_options & PrintOptionsBits::InstructionName) && name != nullptr && stringLength(name) > 1)
		{
			_printer.append(name, "\x1B[34m", "\033[0m");
		}
		else if (_options & PrintOptionsBits::ResultId)
		{
			if (auto id = _instr.getResultId(); id != InvalidId)
			{
				_printer.append(id, "\x1B[34m", "\033[0m");
			}
			else
			{
				_printer.append("\nINVALID INSTRUCTION\n");
				return false; // invalid instruction
			}
		}
	}

	if (_pIndentation != nullptr)
	{
		_printer << _pIndentation;
	}

	if (_options & PrintOptionsBits::OperationName)
	{
		_printer <<  instrInfo->name;	
	}

	auto it = _instr.begin();
	auto end = _instr.end();

	for (const Grammar::Operand& info : instrInfo->operands)
	{
		if (it == end)
		{
			if (info.quantifier == Grammar::Quantifier::One)
			{
				_printer.append("\nINVALID INSTRUCTION\n");
				return false; // invalid instruction			
			}

			continue;
		}

		if (info.kind == Grammar::OperandKind::LiteralString)
		{
			_printer << " \"";
			it = appendLiteralString(_printer, it, end, "\x1B[32m", "\033[0m");
			_printer << "\"";

			continue;
		}
		
		if (info.category == Grammar::OperandCategory::Composite /*&& info.quantifier == Grammar::Quantifier::ZeroOrAny*/)
		{
			if (auto* bases = _grammar.getOperandBases(info.kind); bases != nullptr)
			{
				auto bit = bases->begin();
				auto bend = bases->end();

				for (; it != end; ++it, ++bit)
				{
					if (bit == bend) // reset
					{
						bit = bases->begin();
					}

					printOperand(_instr, *it, *bit, _grammar, _printer, _options);
				}

				continue;
			}
			else
			{
				_printer.append("\nINVALID INSTRUCTION\n");
				return false; // invalid instruction
			}
		}

		printOperand(_instr, *it, info, _grammar, _printer, _options);
		// need to increment 'it' after this part

		if (info.kind == Grammar::OperandKind::LiteralSpecConstantOpInteger)
		{
			Instruction constInstr;
			constInstr.setParent(_instr); // allocator
			constInstr.setOperation(static_cast<spv::Op>(it->getLiteral().value)); // opcode
			if (constInstr.hasResultType())
			{
				constInstr.addOperand(*_instr.getResultTypeOperand());
			}
			if (constInstr.hasResult())
			{
				constInstr.addOperand(InvalidId);
			}

			// copy remaining operands
			for (++it ;it != end; ++it)
			{
				constInstr.addOperand(*it);
			}

			_printer << " [";
			printInstruction(constInstr, _grammar, _printer, _options ^ PrintOptionsBits::ResultId, nullptr);
			_printer << "]";
		}
		else if (auto* params = _grammar.getOperandParameters(info.kind, it->getLiteral()); params != nullptr)
		{
			auto pit = params->begin();
			auto pend = params->end();

			for (++it; it != end && pit != pend; ++it, ++pit)
			{
				printOperand(_instr, *it, *pit, _grammar, _printer, _options);
			}
		}
		else
		{
			++it;
		}
	}

	return true;
}

bool spvgentwo::ModulePrinter::printModule(const Module& _module, const Grammar& _grammar, IModulePrinter& _printer, PrintOptions _options, const char* _pIndentation)
{
	if (_options & PrintOptionsBits::Preamble)
	{
		_printer << "# SPIR-V Version " << _module.getMajorVersion() << "." << _module.getMinorVersion() << "\n";
		_printer << "# Generator " << _module.getSpvGenerator() << "\n";
		_printer << "# Bound " << _module.getSpvBound() << "\n";
		_printer << "# Schema " << _module.getSpvSchema() << "\n\n";
	}

	auto print = [&](const Instruction& instr) -> bool
	{
		if (printInstruction(instr, _grammar, _printer, _options, _pIndentation))
		{
			_printer.append("\n");
			return false; // continue iteration
		}
		return true;
	};

	// print text
	const bool success = !_module.iterateInstructions(print);

	return success;
}

void spvgentwo::ModulePrinter::IModulePrinter::append(unsigned int _literal, const char* _pushColor, const char* _popColor)
{
	char buf[11] = { '\0' }; // max length is log10(UINT_MAX) ~ 9.6 + null terminator -> 11
	uintToString(_literal, buf);

	append(buf, _pushColor, _popColor);
}
