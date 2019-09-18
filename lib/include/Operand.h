#pragma once

#include "SpvDefines.h"

namespace spvgentwo
{
	// forward decls
	class Instruction;
	class BasicBlock;
	class IWriter;

	static constexpr spv::Id InvalidId = 0u;

	struct literal_t
	{
		unsigned int value = 0u;
		operator unsigned int() const { return value; }
	};
	
	struct Operand
	{
		union {
			const BasicBlock* branchTarget;
			const Instruction* instruction; // intermediate or type
			literal_t value;
			spv::Id resultId;
		};
		enum class Type : unsigned int
		{
			Instruction = 0,
			BranchTarget,
			Literal,
			ResultId
		} type;

		bool isBranchTarget() const { return type == Type::BranchTarget; }
		bool isInstruction() const { return type == Type::Instruction; }
		bool isLiteral() const { return type == Type::Literal; }
		bool isResultId() const { return type == Type::ResultId; }

		const BasicBlock* getBranchTarget() const { return isBranchTarget() ? branchTarget : nullptr; }
		const Instruction* getInstruction() const { return isInstruction() ? instruction : nullptr; }
		const literal_t getLiteral() const { return isLiteral() ? value : literal_t{}; }
		const spv::Id getResultId() const { return isResultId() ? resultId : InvalidId; }

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
				value = _other.value;
				break;
			case Type::ResultId:
				resultId = _other.resultId;
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
				value = _other.value;
				break;
			case Type::ResultId:
				resultId = _other.resultId;
				break;
			default:
				break;
			}
		}

		Operand(const BasicBlock* _target) : branchTarget(_target), type(Type::BranchTarget) {}
		Operand(const Instruction* _instr) : instruction(_instr), type(Type::Instruction) {}
		Operand(const literal_t _value) : value(_value), type(Type::Literal) {}
		Operand(const spv::Id _resutlId) : resultId(_resutlId), type(Type::ResultId) {}

		void write(IWriter* _pWriter) const;
	};
} // !spvgentwo 