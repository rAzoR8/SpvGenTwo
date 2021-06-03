#pragma once

#include "SpvDefines.h"
#include "stdreplacement.h"

namespace spvgentwo
{
	// forward decls
	class Instruction;
	class BasicBlock;
	class IWriter;

	static constexpr spv::Id InvalidId{ 0u };
	static constexpr Instruction* InvalidInstr = nullptr;

	struct literal_t
	{
		constexpr literal_t() = default;
		template <class Arg>
		constexpr literal_t(Arg&& _arg) : value{ static_cast<unsigned int>(_arg) } {}

		unsigned int value = 0u;
		operator unsigned int() const { return value; }
	};
	
	static_assert(sizeof(literal_t) == sizeof(unsigned int), "literal_t padded");

	struct Operand
	{
		enum class Type : unsigned int
		{
			Instruction = 0,
			BranchTarget,
			Literal,
			Id
		} type{};

		union
		{
			Instruction* instruction = nullptr; // intermediate or type
			literal_t literal;
			spv::Id id;
			BasicBlock* branchTarget; 
		};

		constexpr bool isBranchTarget() const { return type == Type::BranchTarget; }
		constexpr bool isInstruction() const { return type == Type::Instruction; }
		constexpr bool isLiteral() const { return type == Type::Literal; }
		constexpr bool isId() const { return type == Type::Id; }

		constexpr BasicBlock* getBranchTarget() const { return isBranchTarget() ? branchTarget : nullptr; }
		constexpr Instruction* getInstruction() const { return isInstruction() ? instruction : nullptr; }
		constexpr literal_t getLiteral() const { return isLiteral() ? literal : literal_t{}; }
		constexpr spv::Id getId() const { return isId() ? id : InvalidId; }

		constexpr explicit operator Instruction*() const { return getInstruction(); }
		constexpr explicit operator spv::Id() const { return getId(); }
		constexpr explicit operator literal_t() const { return getLiteral(); }
		constexpr explicit operator BasicBlock* () const { return getBranchTarget(); }

		Operand(const Operand& _other);
		Operand(Operand&& _other) noexcept;

		Operand(BasicBlock* _target) : type(Type::BranchTarget), branchTarget(_target) {}
		Operand(Instruction* _instr) : type(Type::Instruction), instruction(_instr) {}
		Operand(const literal_t _value) : type(Type::Literal), instruction(nullptr) { literal = _value; }
		Operand(const spv::Id _resutlId) : type(Type::Id), instruction(nullptr) { id = _resutlId; }

		bool write(IWriter& _writer) const;

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
		constexpr auto words = bytes / sizeof(unsigned int);

		for (auto w = 0u; w < words; ++w)
		{
			_out.emplace_back(reinterpret_cast<const literal_t*>(&first)[w]);
		}

		if constexpr (bytes % sizeof(unsigned int) != 0)
		{
			using S = stdrep::decay_t<T>;
			literal_t lastWord{ 0u };
			if constexpr (stdrep::is_same_v<S, short> || stdrep::is_same_v<S, char>) // int16_t and int8_t must be sign extended
			{
				// The high-order bits of a literal number must be 0 for a floating-point type, or 0 for an integer type with Signedness of 0, or sign extended when Signedness is 1
				lastWord = first < 0 ? ~0u : 0u;
			}

			auto offset = words * sizeof(unsigned int);
			for (auto i = 0u; offset < bytes; ++offset, ++i)
			{
				reinterpret_cast<unsigned char*>(&lastWord)[i] = reinterpret_cast<const unsigned char*>(&first)[offset];
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