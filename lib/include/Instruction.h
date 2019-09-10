#pragma once

#include "List.h"
#include "Operand.h"
#include "SpvDefines.h"

namespace spvgentwo
{
	static constexpr spv::Id InvalidId = 0xFFFFFFFF;

	class Instruction : public List<Operand>
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
		EntryType* addOperand(const Operand& _operand) { return emplace_back(_operand); }

		spv::Id getId() const { return m_ResultId; }
		spv::Id getTypeId() const { return m_TypeId; }

	private:
		BasicBlock* m_pBasicBlock = nullptr;
		spv::Op m_Operation = spv::Op::OpNop;
		spv::Id m_ResultId = InvalidId;
		spv::Id m_TypeId = InvalidId;
	};
} // !spvgentwo