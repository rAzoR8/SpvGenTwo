#include "BasicBlock.h"
#include "Function.h"
#include "Module.h"

spvgentwo::BasicBlock::BasicBlock(Function* _pFunction) : List(_pFunction->getAllocator()),
	m_pFunction(_pFunction)
{
	addInstruction()->opLabel();
}

spvgentwo::BasicBlock::~BasicBlock()
{
}

spvgentwo::Module* spvgentwo::BasicBlock::getModule()
{
	return m_pFunction->getModule();
}

const spvgentwo::Module* spvgentwo::BasicBlock::getModule() const
{
	return m_pFunction->getModule();
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
	BasicBlock& mergeBB = _pMergeBlock != nullptr ? *_pMergeBlock : m_pFunction->addBasicBlock();

	addInstruction()->opSelectionMerge(&mergeBB, _mask);
	addInstruction()->opBranchConditional(_pCondition, &_trueBlock, &_falseBlock);
	_trueBlock->opBranch(&mergeBB);
	_falseBlock->opBranch(&mergeBB);

	return mergeBB;
}

spvgentwo::BasicBlock& spvgentwo::BasicBlock::Loop(Instruction* _pCondition, BasicBlock& _continue, BasicBlock& _body, BasicBlock* _pMergeBlock, const Flag<spv::LoopControlMask> _mask)
{
	BasicBlock& mergeBB = _pMergeBlock != nullptr ? *_pMergeBlock : m_pFunction->addBasicBlock();
	BasicBlock& condBB = *_pCondition->getBasicBlock();

	addInstruction()->opLoopMerge(&mergeBB, &_continue, _mask);
	addInstruction()->opBranch(&condBB);

	condBB->opBranchConditional(_pCondition, &_body, &mergeBB);
	_body->opBranch(&_continue); // branch to "increment" / continue block
	_continue->opBranch(this); // back edge to loop merge

	return mergeBB;
}

spvgentwo::BasicBlock& spvgentwo::BasicBlock::Mul(Instruction* _pLeft, Instruction* _pRight)
{
	const Type* lType = _pLeft->getType();
	const Type* rType = _pRight->getType();

	if (lType->hasSameBase(*rType) == false)
	{
		getModule()->logError("Operands of Mul() must have the same component type");
		return *this;
	}

	// both are scalar or vector of int
	if ((lType->isInt() && rType->isInt()) || lType->hasSameVectorLength(*rType, spv::Op::OpTypeInt))
	{
		addInstruction()->makeOp(spv::Op::OpIMul, _pLeft, _pRight);
	}// both are scalar or vector of float
	else if ((lType->isFloat() && rType->isFloat()) || lType->hasSameVectorLength(*rType, spv::Op::OpTypeFloat))
	{
		addInstruction()->makeOp(spv::Op::OpFMul, _pLeft, _pRight);
	}// left scalar times right vector float
	else if ((lType->isFloat() && rType->isVectorOfFloat()) || (lType->isInt() && rType->isVectorOfInt()))
	{// OpVectorTimesScalar expects vector as first operand
		addInstruction()->makeOp(spv::Op::OpVectorTimesScalar, _pRight, _pLeft);
	}// left vector times right scalar
	else if ((lType->isVectorOfFloat() && rType->isFloat()) || (lType->isVectorOfInt() && rType->isInt()))
	{
		addInstruction()->makeOp(spv::Op::OpVectorTimesScalar, _pLeft, _pRight);
	}
	else if (lType->isScalar() && rType->isMatrix())
	{// OpMatrixTimesScalar expects matrix as first operand
		addInstruction()->makeOp(spv::Op::OpMatrixTimesScalar, _pRight, _pLeft);
	}
	else if (lType->isMatrix() && rType->isScalar())
	{
		addInstruction()->makeOp(spv::Op::OpMatrixTimesScalar, _pLeft, _pRight);
	}
	else if (lType->isVector() && rType->isMatrix())
	{// OpMatrixTimesVector expects matrix as first operand
		addInstruction()->makeOp(spv::Op::OpMatrixTimesVector, _pRight, _pLeft);
	}
	else if (lType->isMatrix() && rType->isVector())
	{
		addInstruction()->makeOp(spv::Op::OpMatrixTimesVector, _pLeft, _pRight);
	}
	else if (lType->isMatrix() && rType->isMatrix())
	{
		addInstruction()->makeOp(spv::Op::OpMatrixTimesMatrix, _pLeft, _pRight);
	}
	else
	{
		getModule()->logError("Failed to match Mul()'s operand types for this instruction");
	}

	return *this;
}

spvgentwo::BasicBlock& spvgentwo::BasicBlock::Div(Instruction* _pLeft, Instruction* _pRight)
{
	const Type* lType = _pLeft->getType();
	const Type* rType = _pRight->getType();

	if (lType->hasSameBase(*rType) == false)
	{
		getModule()->logError("Operands of Div() must have the same component type");
		return *this;
	}

	if ((lType->isUInt() && rType->isUInt()) || (lType->hasSameVectorLength(*rType) && lType->isUInt()))
	{
		addInstruction()->makeOp(spv::Op::OpUDiv, _pLeft, _pRight);
	} 
	else if ((lType->isInt() && rType->isInt()) || (lType->hasSameVectorLength(*rType) && lType->isSInt()))
	{
		addInstruction()->makeOp(spv::Op::OpSDiv, _pLeft, _pRight);
	}
	else if ((lType->isFloat() && rType->isFloat()) || lType->hasSameVectorLength(*rType, spv::Op::OpTypeFloat))
	{
		addInstruction()->makeOp(spv::Op::OpFDiv, _pLeft, _pRight);
	}
	else if (lType->isVectorOfScalar() && rType->isScalar())
	{
		Instruction* one = nullptr;
		// TODO: find a better way to construct constants from a Type with a value thats not exaclty of type
		// e.g. getModule()->constant(lType, 1)
		if(rType->isF32())
		{
			one = getModule()->constant(1.f);
		} 
		else if (rType->isF64())
		{
			one = getModule()->constant(1.0);
		}
		else if (rType->getIntWidth() == 32u)
		{
			one = getModule()->constant(1);
		}
		else if (rType->getIntWidth() == 64u)
		{
			one = getModule()->constant(1ull);
		}

		// vec / scalar => vec * ( 1 / scalar )
		Mul(_pLeft, Div(one, _pRight));
	}
	else
	{
		getModule()->logError("Failed to match Div()'s operand types for this instruction");
	}

	return *this;
}

spvgentwo::BasicBlock& spvgentwo::BasicBlock::Not(Instruction* _pLeft)
{
	const Type* lType = _pLeft->getType();

	if (lType->isScalarOrVectorOf(spv::Op::OpTypeBool))
	{
		addInstruction()->makeOp(spv::Op::OpLogicalNot, _pLeft);
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
		addInstruction()->makeOp(_int, _pLeft, _pRight);
	}
	else if ((lType->isFloat() && rType->isFloat()) || lType->hasSameVectorLength(*rType, spv::Op::OpTypeFloat))
	{
		addInstruction()->makeOp(_float, _pLeft, _pRight);
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
		addInstruction()->makeOp(_unsigned, _pLeft, _pRight);
	}
	else if ((lType->isSInt() && rType->isSInt()) || (lType->isSInt() && lType->hasSameVectorLength(*rType, spv::Op::OpTypeInt)))
	{
		addInstruction()->makeOp(_signed, _pLeft, _pRight);
	}
	else if ((lType->isFloat() && rType->isFloat()) || lType->hasSameVectorLength(*rType, spv::Op::OpTypeFloat))
	{
		addInstruction()->makeOp(_float, _pLeft, _pRight);
	}
	else
	{
		getModule()->logError("Failed to match SUIntFltOp()'s operand types for this instruction");
	}

	return *this;
}