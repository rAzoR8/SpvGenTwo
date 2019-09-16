#include "Instruction.h"
#include "BasicBlock.h"
#include "Type.h"
#include "Writer.h"

spvgentwo::Instruction::~Instruction()
{
}

void spvgentwo::Instruction::reset()
{
	m_Operation = spv::Op::OpNop;
	m_pType = nullptr;
	m_ResultId = InvalidId;
	clear(); // clear operands
}

unsigned int spvgentwo::Instruction::getWordCount() const
{
	// TODO: check with spv::HasResultAndType if m_pType and m_ResultId have been set correctly
	return 1u + (m_pType != nullptr ? 1u : 0) + (m_ResultId != InvalidId ? 1u : 0u) + static_cast<unsigned int>(m_Elements); // (m_elements is number of operands)
}

unsigned int spvgentwo::Instruction::getOpCode() const
{
	return (unsigned int (m_Operation) & spv::OpCodeMask) | (getWordCount() << spv::WordCountShift);
}

void spvgentwo::Instruction::setType(const Instruction* _pType)
{
	m_pType = _pType;
}

bool spvgentwo::Instruction::isTypeOp() const
{
	return isType(m_Operation);
}

void spvgentwo::Instruction::write(IWriter* _pWriter) const
{
	_pWriter->put(getOpCode());

	if (m_pType != nullptr && m_pType->m_ResultId != InvalidId)
	{
		_pWriter->put(m_pType->m_ResultId);
	}

	if (m_ResultId != InvalidId)
	{
		_pWriter->put(m_ResultId);
	}
	
	for (const Operand& operand : *this)
	{
		operand.write(_pWriter);
	}
}

void spvgentwo::writeInstructions(IWriter* _pWriter, const List<Instruction>& _instructions)
{
	for (const Instruction& cap : _instructions)
	{
		cap.write(_pWriter);
	}
}

void spvgentwo::Instruction::opCapability(const spv::Capability _capability)
{
	makeOp(spv::Op::OpCapability, _capability);
}

void spvgentwo::Instruction::opMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel)
{
	makeOp(spv::Op::OpMemoryModel, _addressModel, _memoryModel);
}

void spvgentwo::Instruction::opExtension(const char* _pExtName)
{
	makeOp(spv::Op::OpExtension, _pExtName);
}

spvgentwo::Instruction* spvgentwo::Instruction::opExtInstrImport(const char* _pExtName)
{
	makeOp(spv::Op::OpExtInstImport, _pExtName);
	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opLabel()
{
	makeOp(spv::Op::OpLabel);
	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opFunction(const Flag<spv::FunctionControlMask> _functionControl, const Instruction* _pResultType, const Instruction* _pFuncType)
{
	makeOp(spv::Op::OpFunction, _pResultType, _functionControl.mask, _pFuncType);
	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opFunctionParameter(const Instruction* _pType)
{
	makeOp(spv::Op::OpFunctionParameter, _pType);
	return this;
}

void spvgentwo::Instruction::opFunctionEnd()
{
	makeOp(spv::Op::OpFunctionEnd);
}