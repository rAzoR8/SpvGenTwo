#pragma once

#include "SpvDefines.h"

namespace spvgentwo
{
	// forward delcs
	class Module;
	class Instruction;
	class Type;

	// default impelemntation
	Instruction* inferResultType(/*const*/ Instruction& _instr);

	// default implementation
	bool validateOperands(/*const*/ Instruction& _instr);

	// returns the operand which matches _type base type or nullptr
	const Type* selectType(const spv::Op _type, const Type* _left, const Type* _right);

	Instruction* selectType(const spv::Op _type, Instruction* _leftTypeInstr, Instruction* _rightTypeInstr);

	// check if type OpCode matches _type, returns _typeInstr or nullptr
	Instruction* checkType(const spv::Op _type, Instruction* _typeInstr);

	class ITypeInferenceAndVailation
	{
	public:
		// returns a new Instruction* to a opType based on _instr opcode and operands 
		virtual Instruction* inferResultType(/*const*/ Instruction& _instr) { return inferResultType(_instr); };
		
		// return true if operands match opcode
		virtual bool validateOperands(/*const*/ Instruction& _instr) { return validateOperands(_instr); }
	};

} //!spvgentwo