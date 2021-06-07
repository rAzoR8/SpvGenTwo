#include "common/ModulePrinter.h"

#include "spvgentwo/String.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/ModuleTemplate.inl"
#include "spvgentwo/Grammar.h"

#include <cstdio>

namespace
{
	template <class T, unsigned int SIZE>
	bool printConstData(const spvgentwo::Constant& _c, char(&_buffer)[SIZE], const char* _pFormat)
	{
		if (const T* data = _c.getDataAs<T>(false); data != nullptr)
		{
			return snprintf(_buffer, SIZE, _pFormat, *data) > 0;
		}
		return false;
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

	bool printOperand(const spvgentwo::Instruction& _instr, const spvgentwo::Operand& op, const spvgentwo::Grammar::Operand& _info, const spvgentwo::Grammar& _grammar, spvgentwo::ModulePrinter::IModulePrinter& _printer, spvgentwo::ModulePrinter::PrintOptions _options)
	{
		using namespace spvgentwo;
		const auto& colors = _printer.getColorScheme();

 		if (op.isId() && _info.kind == Grammar::OperandKind::IdResult)  // skip result id
		{
			return true;
		}

		_printer << " ";
		if (op.isId())
		{
			if (op.id == InvalidId)
			{
				_printer.append("INVALID-INSTRID", colors.error, colors.defaultText);
				return false;
			}

			_printer << "%";
			_printer.append(static_cast<unsigned int>(op.id), colors.operandId, colors.defaultText);
			return true;
		}
		else if (op.isInstruction())
		{
			if (op.instruction == nullptr)
			{
				_printer.append("INVALID-INSTRPTR", colors.error, colors.defaultText);
				return false;
			}

			if (const char* name = op.instruction->getName(); (_options & ModulePrinter::PrintOptionsBits::InstructionName) && name != nullptr && stringLength(name) > 1)
			{
				_printer << "%";
				_printer.append(name, colors.operandId, colors.defaultText);
				return true;
			}
			else if (op.instruction->isType() && (_options & ModulePrinter::PrintOptionsBits::TypeName))
			{
				if (const Type* t = op.instruction->getType(); t != nullptr && (t->isVoid() || t->isScalar() || t->isVector() || t->isMatrix()))
				{
					if (const char* str = t->getString(); str != nullptr)
					{
						_printer.append(str, colors.operandId, colors.defaultText);
						return true;
					}
				}
			}
			else if (op.instruction->isSpecOrConstant() && (_options & ModulePrinter::PrintOptionsBits::ConstantData))
			{
				if (const Constant* c = op.instruction->getConstant(); c != nullptr)
				{
					if (_printer.append(*c, colors.constant, colors.defaultText))
						return true;
				}
			}

			if (op.instruction->getResultId() == InvalidId)
			{
				_printer.append("INVALID-INSTRID", colors.error, colors.defaultText);
				return false;
			}

			// fallback
			_printer << "%";
			_printer.append(static_cast<unsigned int>(op.instruction->getResultId()), colors.operandId, colors.defaultText);
			return true;	
		}
		else if (op.isBranchTarget())
		{
			if (op.branchTarget == nullptr)
			{
				_printer.append("INVALID-BASICBLOCKPTR", colors.error, colors.defaultText);
				return false;
			}
	
			_printer << "%";
			if (const char* name = op.branchTarget->getName(); _options & ModulePrinter::PrintOptionsBits::OperandName && name != nullptr && stringLength(name) > 1)
			{
				_printer.append(name, colors.operandId, colors.defaultText);
			}
			else
			{
				if (spv::Id id = op.branchTarget->getLabel()->getResultId(); id == InvalidId)
				{
					_printer.append("INVALID-INSTRID", colors.error, colors.defaultText);
					return false;
				}

				_printer.append(static_cast<unsigned int>(op.branchTarget->getLabel()->getResultId()), colors.operandId, colors.defaultText);
			}
			return true;
		}
		else if (op.isLiteral())
		{
			if (_instr.getOperation() == spv::Op::OpExtInst)
			{
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
							_printer.append(extInfo->name, colors.extinst, colors.defaultText);
							return true;
						}
					}
				}
			}
			else if (_info.category == Grammar::OperandCategory::BitEnum || _info.category == Grammar::OperandCategory::ValueEnum)
			{
				if (const char* name = _grammar.getOperandName(_info.kind, op.literal.value); name != nullptr && (_options & ModulePrinter::PrintOptionsBits::OperandName))
				{
					_printer.append(name, colors.enumValue, colors.defaultText);				
					return true;
				}
			}
			else if (_info.kind == Grammar::OperandKind::LiteralContextDependentNumber && _instr.isSpecOrConstant() && (_options & ModulePrinter::PrintOptionsBits::ConstantData))
			{
				if (const Constant* c = _instr.getConstant(); c != nullptr)
				{
					if (_printer.append(*c, colors.constant, colors.defaultText))
						return true;
				}
			}

			//fallback
			_printer.append(op.literal.value, colors.literal, colors.defaultText);
			return true;
		}
		else
		{
			_printer.append("UNKNOWN-OPERANDTYPE", colors.error, colors.defaultText);
			return false;
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
	bool success = true;

	auto* instrInfo = _grammar.getInfo(static_cast<unsigned int>(_instr.getOperation()));
	const auto& colors = _printer.getColorScheme();

	if (_instr.hasResult() && ((_options & PrintOptionsBits::InstructionName) || (_options & PrintOptionsBits::ResultId)))
	{
		if (const char* name = _instr.getName(); (_options & PrintOptionsBits::InstructionName) && name != nullptr && stringLength(name) > 1)
		{
			_printer << "%";
			_printer.append(name, colors.resultId, colors.defaultText);
		}
		else if (_options & PrintOptionsBits::ResultId)
		{
			if (auto id = _instr.getResultId(); id != InvalidId)
			{
				_printer << "%";
				_printer.append(static_cast<unsigned int>(id), colors.resultId, colors.defaultText);
			}
			else
			{
				_printer.append("INVALID-RESULTID", colors.error, colors.defaultText);
				success = false; // invalid instruction
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
			if (info.quantifier == Grammar::Quantifier::One) // last operand was not optional
			{
				_printer.append("\nINVALID INSTRUCTION\n", colors.error, colors.defaultText);
				return false; // invalid instruction			
			}
			break;
		}

		if (info.kind == Grammar::OperandKind::LiteralString)
		{
			_printer << " \"";
			it = appendLiteralString(_printer, it, end, colors.string, colors.defaultText);
			_printer << "\"";

			continue;
		}
		
		if (info.category == Grammar::OperandCategory::Composite)
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

					success &= printOperand(_instr, *it, *bit, _grammar, _printer, _options);
				}

				continue;
			}
			else
			{
				_printer.append("\nINVALID INSTRUCTION\n", colors.error, colors.defaultText);
				return false; // invalid instruction
			}
		}

		success &= printOperand(_instr, *it, info, _grammar, _printer, _options);
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
			success &= printInstruction(constInstr, _grammar, _printer, _options ^ PrintOptionsBits::ResultId, nullptr);
			_printer << "]";
		}
		else if (Grammar::hasOperandParameters(info.kind))
		{
			if (auto* params = _grammar.getOperandParameters(info.kind, it->getLiteral()); params != nullptr)
			{
				auto pit = params->begin();
				auto pend = params->end();

				for (++it; it != end && pit != pend; ++pit)
				{
					if (pit->kind == Grammar::OperandKind::LiteralString)
					{
						_printer << " \"";
						it = appendLiteralString(_printer, it, end, colors.string, colors.defaultText);
						_printer << "\"";

						continue;
					}

					success &= printOperand(_instr, *it, *pit, _grammar, _printer, _options);
					++it;
				}
			}
		}
		else if (info.quantifier == Grammar::Quantifier::ZeroOrAny)
		{
			while(++it != end)
			{
				success &= printOperand(_instr, *it, info, _grammar, _printer, _options);			
			}
		}
		else
		{
			++it;		
		}
	}

	return success;
}

bool spvgentwo::ModulePrinter::printModule(const Module& _module, const Grammar& _grammar, IModulePrinter& _printer, PrintOptions _options, const char* _pIndentation)
{
	if (_options & PrintOptionsBits::Preamble)
	{
		_printer << "# SPIR-V Version " << _module.getMajorVersion() << "." << _module.getMinorVersion() << "\n";
		_printer << "# Generator " << _module.getGeneratorId() << " | " << _module.getGeneratorVersion() << "\n";
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

bool spvgentwo::ModulePrinter::IModulePrinter::append(const Constant& _constant, const char* _pushColor, const char* _popColor)
{
	switch (_constant.getOperation())
	{		
	case spv::Op::OpConstantNull: append("null", _pushColor, _popColor); return true;
	case spv::Op::OpConstantTrue: append("true", _pushColor, _popColor); return true;
	case spv::Op::OpSpecConstantTrue: append("true", _pushColor, _popColor); return true;
	case spv::Op::OpConstantFalse: append("false", _pushColor, _popColor); return true;
	case spv::Op::OpSpecConstantFalse: append("false", _pushColor, _popColor); return true;
	case spv::Op::OpConstantSampler: return false; // can't print
	default: break;
	}

	const Type& t = _constant.getType();

	if (t.isBool())
	{
		if (const bool* data = _constant.getDataAs<bool>(false); data != nullptr)
		{
			append(*data ? "true" : "false", _pushColor, _popColor);
			return true;
		}
		return false;
	}

	char buf[64]{ '\0' };
	bool printed = false;

	if (!printed && t.isS8())	printed = printConstData<char>(_constant, buf, "%d");
	if (!printed && t.isS16())	printed = printConstData<short>(_constant, buf, "%d");
	if (!printed && t.isS32())	printed = printConstData<int>(_constant, buf, "%d");
	if (!printed && t.isS64())	printed = printConstData<long long>(_constant, buf, "%lld");
	if (!printed && t.isU8())	printed = printConstData<unsigned char>(_constant, buf, "%u");
	if (!printed && t.isU16())	printed = printConstData<unsigned short>(_constant, buf, "%u");
	if (!printed && t.isU32())	printed = printConstData<unsigned int>(_constant, buf, "%u");
	if (!printed && t.isU64())	printed = printConstData<unsigned long long>(_constant, buf, "%llu");
	if (!printed && t.isF32())	printed = printConstData<float>(_constant, buf, "%f");
	if (!printed && t.isF64())	printed = printConstData<double>(_constant, buf, "%f");

	if (printed)
	{
		append(buf, _pushColor, _popColor);
	}

	return printed;
}

void spvgentwo::ModulePrinter::IModulePrinter::append(unsigned int _literal, const char* _pushColor, const char* _popColor)
{
	char buf[11] = { '\0' }; // max length is log10(UINT_MAX) ~ 9.6 + null terminator -> 11
	uintToString(_literal, buf, 10, 10u);

	append(buf, _pushColor, _popColor);
}