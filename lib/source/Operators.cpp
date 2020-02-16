#include "spvgentwo/Operators.h"
#include "spvgentwo/BasicBlock.h"

spvgentwo::BasicBlock& spvgentwo::ops::operator!(BasicBlock& _left)
{
	return _left.Not();
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

spvgentwo::BasicBlock& spvgentwo::ops::operator==(BasicBlock& _left, Instruction* _pRight)
{
	return _left.Equal(_pRight);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator==(BasicBlock& _left, Instruction& _right)
{
	return _left.Equal(&_right);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator!=(BasicBlock& _left, Instruction* _pRight)
{
	return _left.NotEqual(_pRight);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator!=(BasicBlock& _left, Instruction& _right)
{
	return _left.NotEqual(&_right);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator<(BasicBlock& _left, Instruction* _pRight)
{
	return _left.Less(_pRight);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator<(BasicBlock& _left, Instruction& _right)
{
	return _left.Less(&_right);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator<=(BasicBlock& _left, Instruction* _pRight)
{
	return _left.LessEqual(_pRight);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator<=(BasicBlock& _left, Instruction& _right)
{
	return _left.LessEqual(&_right);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator>(BasicBlock& _left, Instruction* _pRight)
{
	return _left.Greater(_pRight);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator>(BasicBlock& _left, Instruction& _right)
{
	return _left.Greater(&_right);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator>=(BasicBlock& _left, Instruction* _pRight)
{
	return _left.GreaterEqual(_pRight);
}

spvgentwo::BasicBlock& spvgentwo::ops::operator>=(BasicBlock& _left, Instruction& _right)
{
	return _left.GreaterEqual(&_right);
}