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

	if (resultId == false/* || empty()*/)
		return InvalidId;

	auto it = begin();
	if (resultType /*&& size() > 1u*/) // skip resultType operand 
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

spvgentwo::Instruction* spvgentwo::Instruction::getType() const
{
	if (hasResultType()/* && empty() == false*/)
	{
		return front().getInstruction();
	}
	return nullptr;
}

spv::StorageClass spvgentwo::Instruction::getStorageClass() const
{
	if (m_Operation == spv::Op::OpVariable)
	{
		return static_cast<spv::StorageClass>((begin() + 2)->getLiteral().value);
	}

	return spv::StorageClass::Max;
}

bool spvgentwo::Instruction::isTypeOp() const
{
	return isType(m_Operation);
}

void spvgentwo::Instruction::write(IWriter* _pWriter, spv::Id& _resultId)
{
	resolveId(_resultId);

	auto offset = _pWriter->put(getOpCode());
	
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

void spvgentwo::Instruction::opNop()
{
	makeOp(spv::Op::OpNop);
}

spvgentwo::Instruction* spvgentwo::Instruction::opUndef(Instruction* _pResultType)
{
	return makeOp(spv::Op::OpUndef, _pResultType, InvalidId);
}

spvgentwo::Instruction* spvgentwo::Instruction::opSizeOf(Instruction* _pResultType, Instruction* _pPointerToVar)
{
	return makeOp(spv::Op::OpSizeOf, _pResultType, InvalidId, _pPointerToVar);
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

spvgentwo::Instruction* spvgentwo::Instruction::opExtInstImport(const char* _pExtName)
{
	return makeOp(spv::Op::OpExtInstImport, InvalidId, _pExtName);
}

spvgentwo::Instruction* spvgentwo::Instruction::opLabel()
{
	return makeOp(spv::Op::OpLabel, InvalidId);
}

spvgentwo::Instruction* spvgentwo::Instruction::opFunction(const Flag<spv::FunctionControlMask> _functionControl, Instruction* _pResultType, Instruction* _pFuncType)
{
	return makeOp(spv::Op::OpFunction, _pResultType, InvalidId, literal_t{ _functionControl.mask }, _pFuncType);
}

spvgentwo::Instruction* spvgentwo::Instruction::opFunctionParameter(Instruction* _pType)
{
	return makeOp(spv::Op::OpFunctionParameter, _pType, InvalidId);
}

void spvgentwo::Instruction::opReturn()
{
	makeOp(spv::Op::OpReturn);
}

void spvgentwo::Instruction::opReturnValue(Instruction* _pValue)
{
	makeOp(spv::Op::OpReturnValue, _pValue);
}

void spvgentwo::Instruction::opFunctionEnd()
{
	makeOp(spv::Op::OpFunctionEnd);
}

void spvgentwo::Instruction::opName(Instruction* _pTarget, const char* _pName)
{
	makeOp(spv::Op::OpName, _pTarget, _pName);
}

void spvgentwo::Instruction::opMemberName(Instruction* _pTargetStructType, unsigned int _memberIndex, const char* _pName)
{
	makeOp(spv::Op::OpMemberName, _pTargetStructType, _memberIndex, _pName);
}

void spvgentwo::Instruction::opSelectionMerge(Instruction* _pMergeLabel, const spv::SelectionControlMask _control)
{
	makeOp(spv::Op::OpSelectionMerge, _pMergeLabel, _control);
}

void spvgentwo::Instruction::opSelectionMergeEx(BasicBlock* _pMergeBlock, const spv::SelectionControlMask _control)
{
	makeOp(spv::Op::OpSelectionMerge, _pMergeBlock, _control);
}

void spvgentwo::Instruction::opBranch(Instruction* _pTargetLabel)
{
	makeOp(spv::Op::OpBranch, _pTargetLabel);
}

void spvgentwo::Instruction::opBranchEx(BasicBlock* _pTargetBlock)
{
	makeOp(spv::Op::OpBranch, _pTargetBlock);
}

void spvgentwo::Instruction::opBranchConditional(Instruction* _pCondition, Instruction* _pTrueLabel, Instruction* _pFalseLabel)
{
	makeOp(spv::Op::OpBranchConditional, _pCondition, _pTrueLabel, _pFalseLabel);
}

void spvgentwo::Instruction::opBranchConditional(Instruction* _pCondition, Instruction* _pTrueLabel, Instruction* _pFalseLabel, const unsigned int _trueWeight, const unsigned int _falseWeight)
{
	makeOp(spv::Op::OpBranchConditional, _pCondition, _pTrueLabel, _pFalseLabel, _trueWeight, _falseWeight);
}

void spvgentwo::Instruction::opBranchConditionalEx(Instruction* _pCondition, BasicBlock* _pTrueBlock, BasicBlock* _pFalseBlock)
{
	makeOp(spv::Op::OpBranchConditional, _pCondition, _pTrueBlock, _pFalseBlock);
}

void spvgentwo::Instruction::opBranchConditionalEx(Instruction* _pCondition, BasicBlock* _pTrueBlock, BasicBlock* _pFalseBlock, const unsigned int _trueWeight, const unsigned int _falseWeight)
{
	makeOp(spv::Op::OpBranchConditional, _pCondition, _pTrueBlock, _pFalseBlock, _trueWeight, _falseWeight);
}

spvgentwo::Instruction* spvgentwo::Instruction::opIAdd(Instruction* _pResultType, Instruction* _pLeft, Instruction* _pRight)
{
	return makeOp(spv::Op::OpIAdd, _pResultType, InvalidId, _pLeft, _pRight);
}

spvgentwo::Instruction* spvgentwo::Instruction::opISub(Instruction* _pResultType, Instruction* _pLeft, Instruction* _pRight)
{
	return makeOp(spv::Op::OpISub, _pResultType, InvalidId, _pLeft, _pRight);
}

spvgentwo::Instruction* spvgentwo::Instruction::opIMul(Instruction* _pResultType, Instruction* _pLeft, Instruction* _pRight)
{
	return makeOp(spv::Op::OpIMul, _pResultType, InvalidId, _pLeft, _pRight);
}