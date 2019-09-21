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
	clear(); // clear operands
}

unsigned int spvgentwo::Instruction::getWordCount() const
{
	return 1u + static_cast<unsigned int>(m_Elements); // (m_elements is number of operands)
}

unsigned int spvgentwo::Instruction::getOpCode() const
{
	return (unsigned int (m_Operation) & spv::OpCodeMask) | (getWordCount() << spv::WordCountShift);
}

spv::Id spvgentwo::Instruction::getResultId() const
{
	bool resultId = false, resultType = false;
	spv::HasResultAndType(m_Operation, &resultId, &resultType);

	if (resultId == false || empty())
		return InvalidId;

	auto it = begin();
	if (resultType && size() > 1u) // skip resultType operand 
	{
		++it;
	}
	return it->getResultId();
}

void spvgentwo::Instruction::setResultId(const spv::Id _resultId)
{
	bool resultId = false, resultType = false;
	spv::HasResultAndType(m_Operation, &resultId, &resultType);

	if (resultId == false || empty())
		return;

	auto it = begin();
	if (resultType && size() > 1u) // skip resultType operand 
	{
		++it;
	}
	it->resultId = _resultId;
}

const spvgentwo::Instruction* spvgentwo::Instruction::getType() const
{
	if (hasResultType(m_Operation) && empty() == false)
	{
		return front().getInstruction();
	}
	return nullptr;
}

bool spvgentwo::Instruction::isTypeOp() const
{
	return isType(m_Operation);
}

void spvgentwo::Instruction::write(IWriter* _pWriter) const
{
	_pWriter->put(getOpCode());
	
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
	return makeOp(spv::Op::OpExtInstImport, InvalidId, _pExtName);
}

spvgentwo::Instruction* spvgentwo::Instruction::opLabel()
{
	return makeOp(spv::Op::OpLabel, InvalidId);
}

spvgentwo::Instruction* spvgentwo::Instruction::opFunction(const Flag<spv::FunctionControlMask> _functionControl, const Instruction* _pResultType, const Instruction* _pFuncType)
{
	return makeOp(spv::Op::OpFunction, _pResultType, InvalidId, _functionControl.mask, _pFuncType);
}

spvgentwo::Instruction* spvgentwo::Instruction::opFunctionParameter(const Instruction* _pType)
{
	return makeOp(spv::Op::OpFunctionParameter, _pType, InvalidId);
}


spvgentwo::Instruction* spvgentwo::Instruction::opIAdd(const Instruction* _pResultType, const Instruction* _pLeft, const Instruction* _pRight)
{
	return makeOp(_pResultType, InvalidId, _pLeft, _pRight);
}

void spvgentwo::Instruction::opFunctionEnd()
{
	makeOp(spv::Op::OpFunctionEnd);
}