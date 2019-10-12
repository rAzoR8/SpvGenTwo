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

spvgentwo::Instruction& spvgentwo::ops::operator+(Instruction& _left, Instruction& _right)
{
	BasicBlock* pBB = getBasicBlock(_left, _right);
	if (pBB != nullptr) 
	{
		return *pBB->Add(&_left, &_right);
	}

	return _left;
}

spvgentwo::Instruction& spvgentwo::ops::operator-(Instruction& _left, Instruction& _right)
{
	BasicBlock* pBB = getBasicBlock(_left, _right);
	if (pBB != nullptr)
	{
		return *pBB->Sub(&_left, &_right);
	}

	return _left;
}

spvgentwo::Instruction& spvgentwo::ops::operator*(Instruction& _left, Instruction& _right)
{
	BasicBlock* pBB = getBasicBlock(_left, _right);
	if (pBB != nullptr)
	{
		return *pBB->Mul(&_left, &_right);
	}

	return _left;
}

spvgentwo::Instruction& spvgentwo::ops::operator/(Instruction& _left, Instruction& _right)
{
	BasicBlock* pBB = getBasicBlock(_left, _right);
	if (pBB != nullptr)
	{
		return *pBB->Div(&_left, &_right);
	}

	return _left;
}

spvgentwo::BasicBlock& spvgentwo::ops::operator+(BasicBlock& _left, Instruction* _pRight)
{
	return _left.Add(_pRight);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator+(BasicBlock& _left, Instruction& _right)
{
	return _left.Add(&_right);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator-(BasicBlock& _left, Instruction* _pRight)
{
	return _left.Sub(_pRight);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator-(BasicBlock& _left, Instruction& _right)
{
	return _left.Sub(&_right);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator*(BasicBlock& _left, Instruction* _pRight)
{
	return _left.Mul(_pRight);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator*(BasicBlock& _left, Instruction& _right)
{
	return _left.Mul(&_right);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator/(BasicBlock& _left, Instruction* _pRight)
{
	return _left.Div(_pRight);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator/(BasicBlock& _left, Instruction& _right)
{
	return _left.Div(&_right);
}