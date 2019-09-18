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
	if (hasResult(m_Operation) && empty() == false)
	{
		return front().getResultId();
	}
	return InvalidId;
}

void spvgentwo::Instruction::setResultId(const spv::Id _resultId)
{
	if (hasResult(m_Operation) && empty() == false)
	{
		front().resultId = _resultId;
	}
}

const spvgentwo::Instruction* spvgentwo::Instruction::getType() const
{
	bool resultId = false, resultType = false;
	spv::HasResultAndType(m_Operation, &resultId, &resultType);

	if (resultType == false || empty())
		return nullptr;

	auto it = begin();
	if (resultId && size() > 1u) // skip result op 
	{
		++it;
	}
	return it->getInstruction();
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