#pragma once

namespace spvgentwo
{
	template<class TrueFunc, class FalseFunc>
	inline BasicBlock& BasicBlock::If(Instruction* _pCondition, TrueFunc _true, FalseFunc _false, BasicBlock* _pMergeBlock, const Flag < spv::SelectionControlMask> _mask)
	{
		static_assert(traits::is_invocable_v<TrueFunc, BasicBlock&>, "TrueFunc _true is not invocable: _true(BasicBlock& trueBranchBB)");
		static_assert(traits::is_invocable_v<FalseFunc, BasicBlock&>, "FalseFunc _false is not invocable: _true(BasicBlock& falseBranchBB)");

		BasicBlock& trueBB = m_pFunction->addBasicBlock("IfTrue");
		BasicBlock& falseBB = m_pFunction->addBasicBlock("IfFalse");
		BasicBlock& mergeBB = _pMergeBlock != nullptr ? *_pMergeBlock : m_pFunction->addBasicBlock("IfMerge");

		addInstruction()->opSelectionMerge(&mergeBB, _mask);
		addInstruction()->opBranchConditional(_pCondition, &trueBB, &falseBB);

		_true(trueBB);
		_false(falseBB);

		// check if user didnt exit controlflow via kill or similar
		if (trueBB.empty() == false && trueBB.back().isTerminator() == false)
		{
			trueBB->opBranch(&mergeBB);
		}
		if (falseBB.empty() == false && falseBB.back().isTerminator() == false)
		{
			falseBB->opBranch(&mergeBB);
		}

		return mergeBB;
	}

	template<class TrueFunc>
	inline BasicBlock& BasicBlock::If(Instruction* _pCondition, TrueFunc _true, BasicBlock* _pMergeBlock, const Flag<spv::SelectionControlMask> _mask)
	{
		static_assert(traits::is_invocable_v<TrueFunc, BasicBlock&>, "TrueFunc _true is not invocable: _true(BasicBlock& trueBranchBB)");

		BasicBlock& trueBB = m_pFunction->addBasicBlock("IfTrue");
		BasicBlock& mergeBB = _pMergeBlock != nullptr ? *_pMergeBlock : m_pFunction->addBasicBlock("IfMerge");

		addInstruction()->opSelectionMerge(&mergeBB, _mask);
		addInstruction()->opBranchConditional(_pCondition, &trueBB, &mergeBB);

		_true(trueBB);

		// check if user didnt exit controlflow via kill or similar
		if (trueBB.empty() == false && trueBB.back().isTerminator() == false)
		{
			trueBB->opBranch(&mergeBB);		
		}

		return mergeBB;
	}

	// ContinueFunc is increment func
	template<class ConditionFunc, class ContinueFunc, class LoopBodyFunc>
	inline BasicBlock& BasicBlock::Loop(ConditionFunc _condition, ContinueFunc _continue, LoopBodyFunc _body, BasicBlock* _pMergeBlock, const Flag<spv::LoopControlMask> _mask)
	{
		static_assert(traits::is_invocable_v<ConditionFunc, BasicBlock&>, "ConditionFunc _condition is not invocable: _condition(BasicBlock& condBB)");
		static_assert(traits::is_invocable_v<ContinueFunc, BasicBlock&>, "ContinueFunc _continue is not invocable: _continue(BasicBlock& continueBB)");
		static_assert(traits::is_invocable_v<LoopBodyFunc, BasicBlock&>, "LoopBodyFunc _body is not invocable: _body(BasicBlock& bodyBB)");

		BasicBlock& loop = m_pFunction->addBasicBlock("LoopEntry");
		addInstruction()->opBranch(&loop);

		BasicBlock& condBB = m_pFunction->addBasicBlock("LoopCondition");
		BasicBlock& bodyBB = m_pFunction->addBasicBlock("LoopBody");
		BasicBlock& continueBB = m_pFunction->addBasicBlock("LoopContinue");
		BasicBlock& mergeBB = _pMergeBlock != nullptr ? *_pMergeBlock : m_pFunction->addBasicBlock("LoopMerge");

		loop->opLoopMerge(&mergeBB, &continueBB, _mask);
		loop->opBranch(&condBB);

		static_assert(stdrep::is_same_v<Instruction*, decltype(_condition(condBB))>, "ConditionFunc _condition needs to return a Instruction*");

		Instruction* pCond = _condition(condBB);
		// take last instruction of condBB as conditional
		condBB->opBranchConditional(pCond, &bodyBB, &mergeBB);

		_body(bodyBB);
		bodyBB->opBranch(&continueBB); // branch to "increment" / continue block

		_continue(continueBB);
		continueBB->opBranch(&loop); // back edge to loop merge

		return mergeBB;
	}
} // !spvgentwo