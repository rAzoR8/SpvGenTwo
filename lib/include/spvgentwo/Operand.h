#pragma once

#include "SpvDefines.h"

namespace spvgentwo
{
	// forward decls
	class Instruction;
	class BasicBlock;
	class IWriter;

	static constexpr spv::Id InvalidId = 0u;
	static constexpr Instruction* InvalidInstr = nullptr;

	struct literal_t
	{
		literal_t() = default;
		template <class Arg>
		literal_t(Arg&& _arg) : value{ static_cast<unsigned int>(_arg) } {}

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
			Id
		} type;

		union {
			BasicBlock* branchTarget = nullptr; 
			Instruction* instruction; // intermediate or type
			literal_t literal;
			spv::Id id;
		};

		bool isBranchTarget() const { return type == Type::BranchTarget; }
		bool isInstruction() const { return type == Type::Instruction; }
		bool isLiteral() const { return type == Type::Literal; }
		bool isId() const { return type == Type::Id; }

		BasicBlock* getBranchTarget() const { return isBranchTarget() ? branchTarget : nullptr; }
		Instruction* getInstruction() const { return isInstruction() ? instruction : nullptr; }
		const literal_t getLiteral() const { return isLiteral() ? literal : literal_t{}; }
		spv::Id getId() const { return isId() ? id : InvalidId; }

		Operand(const Operand& _other);
		Operand(Operand&& _other) noexcept;

		Operand(BasicBlock* _target) : type(Type::BranchTarget), branchTarget(_target) {}
		Operand(Instruction* _instr) : type(Type::Instruction), instruction(_instr) {}
		Operand(const literal_t _value) : type(Type::Literal), instruction(nullptr) { literal = _value; }
		Operand(const spv::Id _resutlId) : type(Type::Id), instruction(nullptr) { id = _resutlId; }

		void write(IWriter* _pWriter) const;

		Operand& operator=(const Operand& _other);
		Operand& operator=(Operand&& _other) noexcept;

		bool operator==(const Operand& _other) const;

		bool operator==(const BasicBlock* _target) const;
		bool operator==(const Instruction* _instr) const;
		bool operator==(const literal_t& _value) const;
		bool operator==(const spv::Id& _resultId) const;

		bool operator!=(const BasicBlock* _target) const;
		bool operator!=(const Instruction* _instr) const;
		bool operator!=(const literal_t& _value) const;
		bool operator!=(const spv::Id& _resultId) const;
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