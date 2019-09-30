#pragma once

#include "SpvDefines.h"

namespace spvgentwo
{
	// forward delcs
	class Module;
	class Instruction;
	class Type;

	Instruction* inferType(const spv::Op _operation, Instruction* _leftOperand, Instruction* _rightOperand, Module& _module);

	// returns the operand which matches _type base type or nullptr
	const Type* selectType(const spv::Op _type, const Type* _left, const Type* _right);

	Instruction* selectType(const spv::Op _type, Instruction* _leftTypeInstr, Instruction* _rightTypeInstr);

} //!spvgentwo