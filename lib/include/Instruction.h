#pragma once

#include "EntryIterator.h"
#include <vulkan/spirv.hpp11>

namespace spvgentwo
{
	// forward decl
	class BasicBlock;
	class Instruction;

	struct Operand
	{
		union {
			Instruction* instr;
			unsigned int literal;
		};
		enum class Type
		{
			Instruction = 0,
			Literal
		} type;

		Operand(const Operand& _other) : type(_other.type) { if (type == Type::Instruction) instr = _other.instr; else literal = _other.literal; }
		Operand(Operand&& _other) noexcept : type(_other.type) { if (type == Type::Instruction) instr = _other.instr; else literal = _other.literal; }

		Operand(Instruction* _instr) : instr(_instr), type(Type::Instruction) {}
		Operand(unsigned int _literal) : literal(_literal), type(Type::Literal) {}
	};

	using TOperand = Entry<Operand>;

	class Instruction
	{
	public:
		using Iterator = EntryIterator<Operand>;

		Instruction(BasicBlock* _pBasicBlock);
		~Instruction();

		BasicBlock* getBasicBlock() { return m_pBasicBlock; }
		const BasicBlock* getBasicBlock() const { return m_pBasicBlock; }

		// manual instruction construction:
		void setOpCode(const spv::Op _op) { m_Operation = _op; };
		spv::Op getOpCode() const { return m_Operation; }
		TOperand* addOperand(const Operand _operand);

		Iterator begin() const { return Iterator(m_pOperands); }
		Iterator end() const { return Iterator(nullptr); }

	private:
		BasicBlock* m_pBasicBlock = nullptr;
		spv::Op m_Operation = spv::Op::OpNop;

		TOperand* m_pOperands = nullptr;
	};
} // !spvgentwo