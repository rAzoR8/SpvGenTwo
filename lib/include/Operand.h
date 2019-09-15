#pragma once

namespace spvgentwo
{
	// forward decls
	class Instruction;
	class BasicBlock;
	class IWriter;

	struct Operand
	{
		union {
			const BasicBlock* branchTarget;
			const Instruction* instruction;
			unsigned int literal;
		};
		enum class Type : unsigned int
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

		Operand(Operand&& _other) noexcept : type(_other.type)
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

		Operand(const BasicBlock* _target) : branchTarget(_target), type(Type::BranchTarget) {}
		Operand(const Instruction* _instr) : instruction(_instr), type(Type::Instruction) {}
		Operand(unsigned int _literal) : literal(_literal), type(Type::Literal) {}

		void write(IWriter* _pWriter) const;
	};
} // !spvgentwo