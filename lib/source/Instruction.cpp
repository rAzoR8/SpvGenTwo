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

void spvgentwo::Instruction::resolveId(spv::Id& _resultId)
{
	for (Operand& op : *this)
	{
		switch (op.type)
		{
		case Operand::Type::Instruction:
			op.instruction->resolveId(_resultId);
			break;
		case Operand::Type::BranchTarget:
			op.branchTarget->front().resolveId(_resultId);
		default:
			break;
		}
	}

	bool resultId = false, resultType = false;
	spv::HasResultAndType(m_Operation, &resultId, &resultType);

	if (resultId == false /*|| empty()*/)
		return;

	auto it = begin();
	if (resultType /*&& size() > 1u*/) // skip resultType operand 
	{
		++it;
	}

	if (it->resultId == InvalidId)
	{
		it->resultId = ++_resultId;
	}
}

spvgentwo::Instruction* spvgentwo::Instruction::getType()
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

void spvgentwo::Instruction::write(IWriter* _pWriter, spv::Id& _resultId)
{
	resolveId(_resultId);

	_pWriter->put(getOpCode());
	
	for (const Operand& operand : *this)
	{
		operand.write(_pWriter);
	}
}

void spvgentwo::writeInstructions(IWriter* _pWriter, const List<Instruction>& _instructions, spv::Id& _resultId)
{
	for (Instruction& instr : _instructions)
	{
		instr.write(_pWriter, _resultId);
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

spvgentwo::Instruction* spvgentwo::Instruction::opFunction(const Flag<spv::FunctionControlMask> _functionControl, Instruction* _pResultType, Instruction* _pFuncType)
{
	return makeOp(spv::Op::OpFunction, _pResultType, InvalidId, _functionControl.mask, _pFuncType);
}

spvgentwo::Instruction* spvgentwo::Instruction::opFunctionParameter(Instruction* _pType)
{
	return makeOp(spv::Op::OpFunctionParameter, _pType, InvalidId);
}


spvgentwo::Instruction* spvgentwo::Instruction::opIAdd(Instruction* _pResultType, Instruction* _pLeft, Instruction* _pRight)
{
	return makeOp(spv::Op::OpIAdd, _pResultType, InvalidId, _pLeft, _pRight);
}

void spvgentwo::Instruction::opFunctionEnd()
{
	makeOp(spv::Op::OpFunctionEnd);
}