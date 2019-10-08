#include "Operators.h"
#include "Instruction.h"
#include "Module.h"

spvgentwo::BasicBlock* spvgentwo::ops::getBasicBlock(Instruction& _left, Instruction& _right, bool* _pOutLeft)
{
	BasicBlock* pBB = _left.getBasicBlock();
	if (pBB != nullptr)
	{
		if (_pOutLeft != nullptr)
		{
			*_pOutLeft = true; 
		}

		return pBB;
	}

	pBB = _right.getBasicBlock();
	if (pBB != nullptr)
	{
		if (_pOutLeft != nullptr)
		{
			*_pOutLeft = false;
		}

		return pBB;
	}

	return nullptr;
}

const spvgentwo::Type* spvgentwo::ops::getType(const Instruction& _operand)
{
	return _operand.getModule()->getTypeInfo(_operand.getType());
}

spvgentwo::Instruction& spvgentwo::ops::operator+(Instruction& _left, Instruction& _right)
{
	BasicBlock* pBB = getBasicBlock(_left, _right);
	if (pBB != nullptr) 
	{
		BasicBlock& BB = *pBB;
		const Type* lType = getType(_left);

		spv::Op op = spv::Op::OpNop;

		if (lType->isScalarOrVectorOf(spv::Op::OpTypeInt))
		{
			op = spv::Op::OpIAdd;
		}
		else if (lType->isScalarOrVectorOf(spv::Op::OpTypeFloat))
		{
			op = spv::Op::OpFAdd;
		}

		return *BB->makeOp(op, &_left, &_right);
	}

	return _left;
}

spvgentwo::Instruction& spvgentwo::ops::operator-(Instruction& _left, Instruction& _right)
{
	BasicBlock* pBB = getBasicBlock(_left, _right);
	if (pBB != nullptr)
	{
		BasicBlock& BB = *pBB;
		const Type* lType = getType(_left);

		spv::Op op = spv::Op::OpNop;

		if (lType->isScalarOrVectorOf(spv::Op::OpTypeInt))
		{
			op = spv::Op::OpISub;
		}
		else if (lType->isScalarOrVectorOf(spv::Op::OpTypeFloat))
		{
			op = spv::Op::OpFSub;
		}

		return *BB->makeOp(op, &_left, &_right);
	}

	return _left;
}

spvgentwo::Instruction& spvgentwo::ops::operator*(Instruction& _left, Instruction& _right)
{
	BasicBlock* pBB = getBasicBlock(_left, _right);
	if (pBB != nullptr)
	{
		BasicBlock& BB = *pBB;
		const Type* lType = getType(_left);
		const Type* rType = getType(_right);

		// both are scalar or vector of int
		if ((lType->isInt() && rType->isInt()) ||
			(lType->isVectorOf(spv::Op::OpTypeInt) && rType->isVectorOf(spv::Op::OpTypeInt)))
		{
			return *BB->makeOp(spv::Op::OpIMul, &_left, &_right);
		}// both are scalar or vector of float
		else if ((lType->isFloat() && rType->isFloat()) ||
			(lType->isVectorOf(spv::Op::OpTypeFloat) && rType->isVectorOf(spv::Op::OpTypeFloat)))
		{
			return *BB->makeOp(spv::Op::OpFMul, &_left, &_right);
		}// left scalar times right vector float
		else if ((lType->isFloat() &&  rType->isVectorOf(spv::Op::OpTypeFloat)) && 
			(lType->isInt() && rType->isVectorOf(spv::Op::OpTypeInt)))
		{// OpVectorTimesScalar expects vector as first operand
			return *BB->makeOp(spv::Op::OpVectorTimesScalar, &_right, &_left);
		}// left vector times right scalar
		else if ((lType->isVectorOf(spv::Op::OpTypeFloat) && rType->isFloat()) &&
			(lType->isVectorOf(spv::Op::OpTypeInt) && rType->isInt()))
		{
			return *BB->makeOp(spv::Op::OpVectorTimesScalar, &_left, &_right);
		}
		else if (lType->isScalar() && rType->isMatrix()) // TODO: check for same component type
		{// OpMatrixTimesScalar expects matrix as first operand
			return *BB->makeOp(spv::Op::OpMatrixTimesScalar, &_right, &_left);
		}
		else if (lType->isMatrix() && rType->isScalar()) // TODO: check for same component type
		{
			return *BB->makeOp(spv::Op::OpMatrixTimesScalar, &_left, &_right);
		}
		else if (lType->isVector() && rType->isMatrix()) // TODO: check for same component type
		{// OpMatrixTimesVector expects matrix as first operand
			return *BB->makeOp(spv::Op::OpMatrixTimesVector, &_right, &_left);
		}
		else if (lType->isMatrix() && rType->isVector()) // TODO: check for same component type
		{
			return *BB->makeOp(spv::Op::OpMatrixTimesVector, &_left, &_right);
		}
		else if (lType->isMatrix() && rType->isMatrix()) // TODO: check for same component type
		{
			return *BB->makeOp(spv::Op::OpMatrixTimesMatrix, &_left, &_right);
		}
	}

	return _left;
}