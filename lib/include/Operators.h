#pragma once

namespace spvgentwo
{
	// forward decls
	class Instruction;
	class BasicBlock;
	class Type;

	namespace ops
	{
		// result instructions are emplaced in the Basic block of the left Instruction by default,
		// if the left operand has no parent BasicBlock it will be inserted in the right BB or fail
		BasicBlock* getBasicBlock(Instruction& _left, Instruction& _right, bool* _pOutLeft = nullptr);

		// helper functions

		// if none of the operands have a parent BasicBlock, _left will be returned
		Instruction& operator+(Instruction& _left, Instruction& _right);

		Instruction& operator-(Instruction& _left, Instruction& _right);

		Instruction& operator*(Instruction& _left, Instruction& _right);

	} // !ops
} // !spvgentwo