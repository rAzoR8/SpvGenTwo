#pragma once
#include "Instruction.h"

namespace spvgentwo
{
	// forward delcs
	class Module;
	class Function;
	class IAllocator;
	class IWriter;

	class BasicBlock : public List<Instruction>
	{
	public:

		BasicBlock(Function* _pFunction);
		~BasicBlock();

		BasicBlock(const BasicBlock&) = delete;

		Function* getFunction() { return m_pFunction; }
		const Function* getFunction() const { return m_pFunction; }

		Module* getModule();
		const Module* getModule() const;

		IAllocator* getAllocator();

		// get last instruction
		Iterator getTerminator();

		// manual instruction add
		Instruction* addInstruction() { return &emplace_back(this); }

		Instruction* operator->() { return &emplace_back(this); }

		// set return value of this block (used in function), returns opReturn/opReturnValue instruction
		Instruction* returnValue(Instruction* _pValue = nullptr);

		// return last operation
		operator Instruction* () const { return m_pLast != nullptr ? m_pLast->operator->() : nullptr; };

		void write(IWriter* _pWriter, spv::Id& _resultId);

		// structured if: true and false block must NOT have a terminator yet!
		// returns last instruction of MergeBlock which creats a result
		Instruction* If(Instruction* _pCondition, BasicBlock& _trueBlock, BasicBlock& _falseBlock, BasicBlock& _mergeBlock, const spv::SelectionControlMask _mask = spv::SelectionControlMask::MaskNone);

		template <class TrueFunc, class FalseFunc>
		BasicBlock& If(Instruction* _pCondition, TrueFunc& _true, FalseFunc& _false, const spv::SelectionControlMask _mask = spv::SelectionControlMask::MaskNone);

		// infer op code from operands types, emplace instruction in this basic block
		BasicBlock& Add(Instruction* _pLeft, Instruction* _pRight);
		BasicBlock& Sub(Instruction* _pLeft, Instruction* _pRight);
		BasicBlock& Mul(Instruction* _pLeft, Instruction* _pRight);
		BasicBlock& Div(Instruction* _pLeft, Instruction* _pRight);

		BasicBlock& Add(Instruction* _pRight);// add _pRight to last instruction in this basic block and push the result (stack like) to this basic block
		BasicBlock& Sub(Instruction* _pRight);
		BasicBlock& Mul(Instruction* _pRight);
		BasicBlock& Div(Instruction* _pRight);

		BasicBlock& Eq(Instruction* _pLeft, Instruction* _pRight);
		BasicBlock& Neq(Instruction* _pLeft, Instruction* _pRight);

		BasicBlock& Eq(Instruction* _pRight);
		BasicBlock& Neq(Instruction* _pRight);

	private:
		Function* m_pFunction = nullptr; // parent
	};

	template<class TrueFunc, class FalseFunc>
	inline BasicBlock& BasicBlock::If(Instruction* _pCondition, TrueFunc& _true, FalseFunc& _false, const spv::SelectionControlMask _mask)
	{
		static_assert(traits::is_invocable_v<TrueFunc, BasicBlock&>, "TrueFunc _true is not invocable: _true(BasicBlock& trueBranchBB)");
		static_assert(traits::is_invocable_v<FalseFunc, BasicBlock&>, "FalseFunc _false is not invocable: _true(BasicBlock& falseBranchBB)");

		BasicBlock& trueBB = m_pFunction->addBasicBlock();
		BasicBlock& falseBB = m_pFunction->addBasicBlock();
		BasicBlock& mergeBB = m_pFunction->addBasicBlock();

		addInstruction()->opSelectionMerge(&mergeBB, _mask);
		addInstruction()->opBranchConditional(_pCondition, &trueBB, &falseBB);

		_true(trueBB);
		_false(falseBB);

		trueBB->opBranch(&mergeBB);
		falseBB->opBranch(&mergeBB);

		return mergeBB;
	}
} // !spvgentwo