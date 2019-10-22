#include "Operators.h"
#include "Instruction.h"
#include "Module.h"

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

spvgentwo::BasicBlock& spvgentwo::ops::operator==(BasicBlock& _left, Instruction* _pRight)
{
	return _left.Eq(_pRight);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator==(BasicBlock& _left, Instruction& _right)
{
	return _left.Eq(&_right);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator!=(BasicBlock& _left, Instruction* _pRight)
{
	return _left.Neq(_pRight);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator!=(BasicBlock& _left, Instruction& _right)
{
	return _left.Neq(&_right);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator<(BasicBlock& _left, Instruction* _pRight)
{
	return _left.Lt(_pRight);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator<(BasicBlock& _left, Instruction& _right)
{
	return _left.Lt(&_right);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator<=(BasicBlock& _left, Instruction* _pRight)
{
	return _left.Lte(_pRight);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator<=(BasicBlock& _left, Instruction& _right)
{
	return _left.Lte(&_right);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator>(BasicBlock& _left, Instruction* _pRight)
{
	return _left.Gt(_pRight);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator>(BasicBlock& _left, Instruction& _right)
{
	return _left.Gt(&_right);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator>=(BasicBlock& _left, Instruction* _pRight)
{
	return _left.Gte(_pRight);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator>=(BasicBlock& _left, Instruction& _right)
{
	return _left.Gte(&_right);
}