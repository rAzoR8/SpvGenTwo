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
		enum class Type : unsigned int
		{
			Instruction = 0,
			BranchTarget,
			Literal,
			ResultId
		} type;

		union {
			BasicBlock* branchTarget = nullptr; 
			Instruction* instruction; // intermediate or type
			literal_t value;
			spv::Id resultId;
		};

		bool isBranchTarget() const { return type == Type::BranchTarget; }
		bool isInstruction() const { return type == Type::Instruction; }
		bool isLiteral() const { return type == Type::Literal; }
		bool isResultId() const { return type == Type::ResultId; }

		BasicBlock* getBranchTarget() const { return isBranchTarget() ? branchTarget : nullptr; }
		Instruction* getInstruction() const { return isInstruction() ? instruction : nullptr; }
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

		Operand(BasicBlock* _target) : branchTarget(_target), type(Type::BranchTarget) {}
		Operand(Instruction* _instr) : instruction(_instr), type(Type::Instruction) {}
		Operand(const literal_t _value) : value(_value), type(Type::Literal) {}
		Operand(const spv::Id _resutlId) : resultId(_resutlId), type(Type::ResultId) {}

		void write(IWriter* _pWriter) const;
	};

	template<class Container, class T, class ...Args>
	void appendLiteralsToContainer(Container& _out, T first, Args ..._args)
	{
		constexpr auto bytes = sizeof(T);
		constexpr auto words = wordCount(bytes) - (bytes % sizeof(unsigned int) == 0 ? 0 : 1);

		for (auto w = 0u; w < words; ++w)
		{
			_out.emplace_back(reinterpret_cast<const literal_t*>(&first)[w]);
		}

		if constexpr (bytes % sizeof(unsigned int) != 0)
		{
			literal_t lastWord{ 0u };
			const auto offset = words * sizeof(unsigned int);
			for (auto b = offset; b < bytes; ++b)
			{
				reinterpret_cast<char*>(&lastWord)[b - offset] = reinterpret_cast<const char*>(&first)[b];
			}
			_out.emplace_back(lastWord);
		}

		if constexpr (sizeof...(_args) > 0u)
		{
			appendLiteralsToContainer(_out, _args...);
		}
	}

	template <class Container>
	void appendLiteralsToContainer(Container& _out, const char* _pStr)
	{
		literal_t word{ 0u };
		unsigned int l = 0u;
		char c = 0u;

		do
		{
			c = _pStr[l];
			const auto mod = l++ % sizeof(unsigned int);
			reinterpret_cast<char*>(&word)[mod] = c;

			if (c == 0 || mod == 3)
			{
				_out.emplace_back(word);
				word.value = 0u;
			}

		} while (c != 0);
	}
} // !spvgentwo 