#pragma once

#include "SpvDefines.h"

namespace spvgentwo
{
	// forward delcs
	class Module;
	class Instruction;
	class Type;

	// infer result type from _operation and operands (_rightOperand ignored if single Operand operation)
	Instruction* inferType(const spv::Op _operation, Instruction* _leftOperand, Instruction* _rightOperand, Module& _module);

	// returns the operand which matches _type base type or nullptr
	const Type* selectType(const spv::Op _type, const Type* _left, const Type* _right);

	Instruction* selectType(const spv::Op _type, Instruction* _leftTypeInstr, Instruction* _rightTypeInstr);

	// check if type OpCode matches _type, returns _typeInstr or nullptr
	Instruction* checkType(const spv::Op _type, Instruction* _typeInstr);

} //!spvgentwo