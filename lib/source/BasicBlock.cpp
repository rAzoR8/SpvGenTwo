#include "spvgentwo/BasicBlock.h"
#include "spvgentwo/Function.h"
#include "spvgentwo/Module.h"

spvgentwo::BasicBlock::BasicBlock(Function* _pFunction, const char* _pName) : List(_pFunction->getAllocator()),
	m_pFunction(_pFunction)
{
	Instruction* label = addInstruction()->opLabel();

	if (_pName != nullptr)
	{
		getModule()->addName(label, _pName);
	}
}

spvgentwo::BasicBlock::BasicBlock(Function* _pFunction, BasicBlock&& _other) noexcept :
	List(stdrep::move(_other)),
	m_pFunction(_pFunction)
{
	for (Instruction& instr : *this)
	{
		instr.m_parent.pBasicBlock = this;
	}

	if (empty())
	{
		addInstruction()->opLabel();
	}
}

spvgentwo::BasicBlock::~BasicBlock()
{
}

spvgentwo::BasicBlock& spvgentwo::BasicBlock::operator=(BasicBlock&& _other) noexcept
{
	if (this == &_other) return *this;

	List::operator=(stdrep::move(_other));

	for (Instruction& instr : *this)
	{
		instr.m_parent.pBasicBlock = this;
	}

	if (empty())
	{
		addInstruction()->opLabel();
	}

	return *this;
}

spvgentwo::Module* spvgentwo::BasicBlock::getModule() const
{
	return m_pFunction->getModule();
}

const char* spvgentwo::BasicBlock::getName() const
{
	return m_pBegin != nullptr ? getModule()->getName(m_pBegin->operator->()) : "";
}

spvgentwo::IAllocator* spvgentwo::BasicBlock::getAllocator()
{
	return getModule()->getAllocator();;
}

spvgentwo::BasicBlock::Iterator spvgentwo::BasicBlock::getTerminator()
{
	if (m_pLast != nullptr && (*m_pLast)->isTerminator())
	{
		return Iterator(m_pLast);
	}

	return Iterator(nullptr);
}

bool spvgentwo::BasicBlock::getBranchTargets(List<BasicBlock*>& _outTargetBlocks) const
{
	if (m_pBegin != m_pLast) // there is more then just initial opLabel
	{
		return back().getBranchTargets(_outTargetBlocks);
	}

	return false;
}

spvgentwo::Instruction* spvgentwo::BasicBlock::returnValue(Instruction* _pValue)
{
	Instruction* pRet = addInstruction();

	if (_pValue == nullptr)
	{
		pRet->opReturn();
	}
	else
	{
		// TODO: check return type with m_FunctionType
		pRet->opReturnValue(_pValue);
	}

	return pRet;
}

void spvgentwo::BasicBlock::write(IWriter* _pWriter, spv::Id& _resultId)
{
	for (Instruction& instr : *this)
	{
		instr.write(_pWriter, _resultId);
	}
}

spvgentwo::BasicBlock& spvgentwo::BasicBlock::If(Instruction* _pCondition, BasicBlock& _trueBlock, BasicBlock& _falseBlock, BasicBlock* _pMergeBlock, const Flag<spv::SelectionControlMask> _mask)
{
	// this block has not been terminated yet
	BasicBlock& mergeBB = _pMergeBlock != nullptr ? *_pMergeBlock : m_pFunction->addBasicBlock("IfMerge");

	addInstruction()->opSelectionMerge(&mergeBB, _mask);
	addInstruction()->opBranchConditional(_pCondition, &_trueBlock, &_falseBlock);
	_trueBlock->opBranch(&mergeBB);
	_falseBlock->opBranch(&mergeBB);

	return mergeBB;
}

spvgentwo::BasicBlock& spvgentwo::BasicBlock::If(Instruction* _pCondition, BasicBlock& _trueBlock, BasicBlock* _pMergeBlock, const Flag<spv::SelectionControlMask> _mask)
{
	// this block has not been terminated yet
	BasicBlock& mergeBB = _pMergeBlock != nullptr ? *_pMergeBlock : m_pFunction->addBasicBlock("IfMerge");

	addInstruction()->opSelectionMerge(&mergeBB, _mask);
	addInstruction()->opBranchConditional(_pCondition, &_trueBlock, &mergeBB);
	_trueBlock->opBranch(&mergeBB);

	return mergeBB;
}

spvgentwo::BasicBlock& spvgentwo::BasicBlock::Loop(Instruction* _pCondition, BasicBlock& _continue, BasicBlock& _body, BasicBlock* _pMergeBlock, const Flag<spv::LoopControlMask> _mask)
{
	BasicBlock& mergeBB = _pMergeBlock != nullptr ? *_pMergeBlock : m_pFunction->addBasicBlock("LoopMerge");
	BasicBlock& condBB = *_pCondition->getBasicBlock();

	addInstruction()->opLoopMerge(&mergeBB, &_continue, _mask);
	addInstruction()->opBranch(&condBB);

	condBB->opBranchConditional(_pCondition, &_body, &mergeBB);
	_body->opBranch(&_continue); // branch to "increment" / continue block
	_continue->opBranch(this); // back edge to loop merge

	return mergeBB;
}

spvgentwo::BasicBlock& spvgentwo::BasicBlock::Not(Instruction* _pLeft)
{
	const Type* lType = _pLeft->getType();

	if (lType->isScalarOrVectorOf(spv::Op::OpTypeBool))
	{
		addInstruction()->makeOp(spv::Op::OpLogicalNot, InvalidInstr, InvalidId, _pLeft);
	}
	else
	{
		getModule()->logError("Failed to match Not()'s operand types for this instruction (scalar or vector of bool)");
	}

	return *this;
}

spvgentwo::BasicBlock& spvgentwo::BasicBlock::IntFltOp(Instruction* _pLeft, Instruction* _pRight, const spv::Op _int, const spv::Op _float)
{
	const Type* lType = _pLeft->getType();
	const Type* rType = _pRight->getType();

	if (lType->hasSameBase(*rType) == false)
	{
		getModule()->logError("Operands of IntFltOp() must have the same component type");
		return *this;
	}

	if ((lType->isInt() && rType->isInt()) || lType->hasSameVectorLength(*rType, spv::Op::OpTypeInt))
	{
		addInstruction()->makeOp(_int, InvalidInstr, InvalidId, _pLeft, _pRight);
	}
	else if ((lType->isFloat() && rType->isFloat()) || lType->hasSameVectorLength(*rType, spv::Op::OpTypeFloat))
	{
		addInstruction()->makeOp(_float, InvalidInstr, InvalidId, _pLeft, _pRight);
	}
	else
	{
		getModule()->logError("Failed to match IntFltOp()'s operand types for this instruction");
	}

	return *this;
}

spvgentwo::BasicBlock& spvgentwo::BasicBlock::SUIntFltOp(Instruction* _pLeft, Instruction* _pRight, const spv::Op _unsigned, const spv::Op _signed, const spv::Op _float)
{
	const Type* lType = _pLeft->getType();
	const Type* rType = _pRight->getType();

	if (lType->hasSameBase(*rType) == false)
	{
		getModule()->logError("Operands of SUIntFltOp() must have the same component type");
		return *this;
	}

	if ((lType->isUInt() && rType->isUInt()) || (lType->isUInt() && lType->hasSameVectorLength(*rType, spv::Op::OpTypeInt)))
	{
		addInstruction()->makeOp(_unsigned, InvalidInstr, InvalidId, _pLeft, _pRight);
	}
	else if ((lType->isSInt() && rType->isSInt()) || (lType->isSInt() && lType->hasSameVectorLength(*rType, spv::Op::OpTypeInt)))
	{
		addInstruction()->makeOp(_signed, InvalidInstr, InvalidId, _pLeft, _pRight);
	}
	else if ((lType->isFloat() && rType->isFloat()) || lType->hasSameVectorLength(*rType, spv::Op::OpTypeFloat))
	{
		addInstruction()->makeOp(_float, InvalidInstr, InvalidId, _pLeft, _pRight);
	}
	else
	{
		getModule()->logError("Failed to match SUIntFltOp()'s operand types for this instruction");
	}

	return *this;
}