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
