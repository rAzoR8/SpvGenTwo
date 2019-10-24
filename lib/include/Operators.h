#pragma once

namespace spvgentwo
{
	// forward decls
	class Instruction;
	class BasicBlock;
	class Type;

	namespace ops
	{
		BasicBlock& operator!(BasicBlock& _left);

		BasicBlock& operator+(BasicBlock& _left, Instruction* _pRight);
		BasicBlock& operator+(BasicBlock& _left, Instruction& _right);

		BasicBlock& operator-(BasicBlock& _left, Instruction* _pRight);
		BasicBlock& operator-(BasicBlock& _left, Instruction& _right);

		BasicBlock& operator*(BasicBlock& _left, Instruction* _pRight);
		BasicBlock& operator*(BasicBlock& _left, Instruction& _right);

		BasicBlock& operator/(BasicBlock& _left, Instruction* _pRight);
		BasicBlock& operator/(BasicBlock& _left, Instruction& _right);

		BasicBlock& operator==(BasicBlock& _left, Instruction* _pRight);
		BasicBlock& operator==(BasicBlock& _left, Instruction& _right);

		BasicBlock& operator!=(BasicBlock& _left, Instruction* _pRight);
		BasicBlock& operator!=(BasicBlock& _left, Instruction& _right);

		BasicBlock& operator<(BasicBlock& _left, Instruction* _pRight);
		BasicBlock& operator<(BasicBlock& _left, Instruction& _right);

		BasicBlock& operator<=(BasicBlock& _left, Instruction* _pRight);
		BasicBlock& operator<=(BasicBlock& _left, Instruction& _right);

		BasicBlock& operator>(BasicBlock& _left, Instruction* _pRight);
		BasicBlock& operator>(BasicBlock& _left, Instruction& _right);

		BasicBlock& operator>=(BasicBlock& _left, Instruction* _pRight);
		BasicBlock& operator>=(BasicBlock& _left, Instruction& _right);
	} // !ops
} // !spvgentwo