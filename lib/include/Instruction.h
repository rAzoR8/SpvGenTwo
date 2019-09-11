#pragma once

#include "List.h"
#include "Operand.h"
#include "SpvDefines.h"

namespace spvgentwo
{
	// forward delcs
	class Type;

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
		template<class ...Args>
		EntryType* addOperand(Args&& ... _operand) { return emplace_back(forward<Args>(_operand)...); }

		spv::Id getId() const { return m_ResultId; }
		Type* getType() { return m_pType; }

		// memory of _pType is owned externaly
		void setSharedType(Type* _pType);

		// type is owned by this instruction (modules allocator)
		Type* createType();

	private:
		BasicBlock* m_pBasicBlock = nullptr;
		spv::Op m_Operation = spv::Op::OpNop;
		spv::Id m_ResultId = InvalidId;
		
		Type* m_pType = nullptr;
		bool m_bSharedType = false; // if not shared, this instruction owns type memory
	};
} // !spvgentwo