#pragma once

#include <stdint.h>

namespace spvgentwo
{
	// forward decls
	class Instruction;
	class BasicBlock;

	struct Operand
	{
		union {
			BasicBlock* branchTarget;
			Instruction* instruction;
			uint32_t literal;
		};
		enum class Type
		{
			Instruction = 0,
			BranchTarget,
			Literal
		} type;

		Operand(const Operand& _other) : type(_other.type)
		{
			switch (type)
			{
			case Type::Instruction:
				instruction = _other.instruction;
				break;
			case Type::BranchTarget:
				branchTarget = _other.branchTarget;
				break;
			case Type::Literal:
				literal = _other.literal;
				break;
			default:
				break;
			}
		}

		Operand(BasicBlock* _target) : branchTarget(_target), type(Type::BranchTarget) {}
		Operand(Instruction* _instr) : instruction(_instr), type(Type::Instruction) {}
		Operand(uint32_t _literal) : literal(_literal), type(Type::Literal) {}
	};
} // !spvgentwo