#pragma once

#include "SpvDefines.h"

namespace spvgentwo
{
	// forward delcs
	class Module;
	class Instruction;
	class Type;

	// infer result type from _operation and operands (_op2 and _op3 are ignored if single Operand operation)
	Instruction* inferType(const spv::Op _operation, Instruction* _op1, Instruction* _op2 = nullptr, Instruction* _op3 = nullptr);

	Instruction* inferType(const spv::Op _operation, Module& _module, Instruction* _pTypeInst1, Instruction* _pTypeInst2, Instruction* _pTypeInst3, const Type* _pType1, const Type* _pType2, const Type* _pType3);

	// returns the operand which matches _type base type or nullptr
	const Type* selectType(const spv::Op _type, const Type* _left, const Type* _right);

	Instruction* selectType(const spv::Op _type, Instruction* _leftTypeInstr, Instruction* _rightTypeInstr);

	// check if type OpCode matches _type, returns _typeInstr or nullptr
	Instruction* checkType(const spv::Op _type, Instruction* _typeInstr);

} //!spvgentwo