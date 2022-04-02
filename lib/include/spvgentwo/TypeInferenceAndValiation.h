#pragma once

namespace spvgentwo
{
	// forward delcs
	class Instruction;

	class ITypeInferenceAndVailation
	{
	public:
		// some opXXXX functions already infer a result type before passing it to makeOp(), this function allows to override this behaviour
		// so that inferResultType() of this instance is call anyway
		virtual bool overridePredefinedResultType() const { return false; }

		// returns a new Instruction* to a opType based on _instr opcode and operands 
		virtual Instruction* inferResultType(const Instruction& _instr) const;
		
		// return true if operands match opcode
		virtual bool validateOperands(const Instruction& _instr) const;
	};
} //!spvgentwo