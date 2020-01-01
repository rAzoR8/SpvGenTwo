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
		friend class Module;
		friend class Function;
	private:

		Function* m_pFunction = nullptr; // parent
	public:

		BasicBlock(Function* _pFunction);
		BasicBlock(Function* _pFunction, BasicBlock&& _other) noexcept;
		BasicBlock(const BasicBlock&) = delete;

		virtual ~BasicBlock();

		BasicBlock& operator=(BasicBlock&& _other) noexcept;
		BasicBlock& operator=(const BasicBlock& _other) = delete;

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

		template <class ExtInstr>
		ExtInstr* ext() { return reinterpret_cast<ExtInstr*>(addInstruction()); }

		// set return value of this block (used in function), returns opReturn/opReturnValue instruction
		Instruction* returnValue(Instruction* _pValue = nullptr);

		// return last operation
		operator Instruction* () const { return m_pLast != nullptr ? m_pLast->operator->() : nullptr; };

		void write(IWriter* _pWriter, spv::Id& _resultId);

		// structured if: true and false block must NOT have a terminator yet!
		// returns last instruction of MergeBlock which creats a result
		BasicBlock& If(Instruction* _pCondition, BasicBlock& _trueBlock, BasicBlock& _falseBlock, BasicBlock* _pMergeBlock = nullptr, const Flag<spv::SelectionControlMask> _mask = spv::SelectionControlMask::MaskNone);

		// If without else block
		BasicBlock& If(Instruction* _pCondition, BasicBlock& _trueBlock, BasicBlock* _pMergeBlock = nullptr, const Flag<spv::SelectionControlMask> _mask = spv::SelectionControlMask::MaskNone);
		
		// MergeBlock for selection merge is returned. If _pMergeBlock is nullptr, a new block will be added to the function
		// Example usage:
		
		/*Instruction* res1 = nullptr;
		Instruction* res2 = nullptr;

		BasicBlock& merge = bb.If(cond, [&](BasicBlock& trueBB)
		{
			res1 = trueBB.Add(z, x) * uniX;
		}, [&](BasicBlock& falseBB)
		{
			res2 = falseBB.Sub(z, x) * uniX;
		});

		merge.returnValue(merge->opPhi(res1, res2));*/

		template <class TrueFunc, class FalseFunc>
		BasicBlock& If(Instruction* _pCondition, TrueFunc _true, FalseFunc _false, BasicBlock* _pMergeBlock = nullptr, const Flag<spv::SelectionControlMask> _mask = spv::SelectionControlMask::MaskNone);

		template <class TrueFunc> // If without else block
		BasicBlock& If(Instruction* _pCondition, TrueFunc _true, BasicBlock* _pMergeBlock = nullptr, const Flag<spv::SelectionControlMask> _mask = spv::SelectionControlMask::MaskNone);

		BasicBlock& Loop(Instruction* _pCondition, BasicBlock& _continue, BasicBlock& _body, BasicBlock* _pMergeBlock = nullptr, const Flag<spv::LoopControlMask> _mask = spv::LoopControlMask::MaskNone);

		template <class ConditionFunc, class ContinueFunc, class LoopBodyFunc>
		BasicBlock& Loop(ConditionFunc _condition, ContinueFunc _continue, LoopBodyFunc _body, BasicBlock* _pMergeBlock = nullptr, const Flag<spv::LoopControlMask> _mask = spv::LoopControlMask::MaskNone);

		// infer op code from operands types, emplace instruction in this basic block
		BasicBlock& Add(Instruction* _pLeft, Instruction* _pRight) { return IntFltOp(_pLeft, _pRight, spv::Op::OpIAdd, spv::Op::OpFAdd); }
		BasicBlock& Sub(Instruction* _pLeft, Instruction* _pRight) { return IntFltOp(_pLeft, _pRight, spv::Op::OpISub, spv::Op::OpFSub); }
		BasicBlock& Mul(Instruction* _pLeft, Instruction* _pRight);
		BasicBlock& Div(Instruction* _pLeft, Instruction* _pRight);

		BasicBlock& Not(Instruction* _pLeft);
		BasicBlock& Eq(Instruction* _pLeft, Instruction* _pRight) { return IntFltOp(_pLeft, _pRight, spv::Op::OpIEqual, spv::Op::OpFOrdEqual); }
		BasicBlock& Neq(Instruction* _pLeft, Instruction* _pRight) { return IntFltOp(_pLeft, _pRight, spv::Op::OpINotEqual, spv::Op::OpFOrdNotEqual); }
		BasicBlock& Lt(Instruction* _pLeft, Instruction* _pRight) {	return SUIntFltOp(_pLeft, _pRight, spv::Op::OpSLessThan, spv::Op::OpULessThan, spv::Op::OpFOrdLessThan); }
		BasicBlock& Lte(Instruction* _pLeft, Instruction* _pRight) { return SUIntFltOp(_pLeft, _pRight, spv::Op::OpSLessThanEqual, spv::Op::OpULessThanEqual, spv::Op::OpFOrdLessThanEqual); }
		BasicBlock& Gt(Instruction* _pLeft, Instruction* _pRight) { return SUIntFltOp(_pLeft, _pRight, spv::Op::OpSGreaterThan, spv::Op::OpUGreaterThan, spv::Op::OpFOrdGreaterThan); }
		BasicBlock& Gte(Instruction* _pLeft, Instruction* _pRight) { return SUIntFltOp(_pLeft, _pRight, spv::Op::OpSGreaterThanEqual, spv::Op::OpUGreaterThanEqual, spv::Op::OpFOrdGreaterThanEqual); }

		// add _pRight to last instruction in this basic block and push the result (stack like) to this basic block
		BasicBlock& Add(Instruction* _pRight) { Add(m_pLast->operator->(), _pRight); return *this; }
		BasicBlock& Sub(Instruction* _pRight) { Sub(m_pLast->operator->(), _pRight); return *this; }
		BasicBlock& Mul(Instruction* _pRight) { Mul(m_pLast->operator->(), _pRight); return *this; }
		BasicBlock& Div(Instruction* _pRight) { Div(m_pLast->operator->(), _pRight); return *this; }
		BasicBlock& Not() { Not(m_pLast->operator->()); return *this; }
		BasicBlock& Eq(Instruction* _pRight) { Eq(m_pLast->operator->(), _pRight); return *this; }
		BasicBlock& Neq(Instruction* _pRight) { Neq(m_pLast->operator->(), _pRight); return *this; }
		BasicBlock& Lt(Instruction* _pRight) { Lt(m_pLast->operator->(), _pRight); return *this; }
		BasicBlock& Lte(Instruction* _pRight) { Lte(m_pLast->operator->(), _pRight); return *this; }
		BasicBlock& Gt(Instruction* _pRight) { Gt(m_pLast->operator->(), _pRight); return *this; }
		BasicBlock& Gte(Instruction* _pRight) { Gte(m_pLast->operator->(), _pRight); return *this; }

	private:
		BasicBlock& IntFltOp(Instruction* _pLeft, Instruction* _pRight, const spv::Op _int, const spv::Op _float);
		BasicBlock& SUIntFltOp(Instruction* _pLeft, Instruction* _pRight, const spv::Op _unsigned, const spv::Op _signed, const spv::Op _float);
	};

	template<class TrueFunc, class FalseFunc>
	inline BasicBlock& BasicBlock::If(Instruction* _pCondition, TrueFunc _true, FalseFunc _false, BasicBlock* _pMergeBlock, const Flag < spv::SelectionControlMask> _mask)
	{
		static_assert(traits::is_invocable_v<TrueFunc, BasicBlock&>, "TrueFunc _true is not invocable: _true(BasicBlock& trueBranchBB)");
		static_assert(traits::is_invocable_v<FalseFunc, BasicBlock&>, "FalseFunc _false is not invocable: _true(BasicBlock& falseBranchBB)");

		BasicBlock& trueBB = m_pFunction->addBasicBlock();
		BasicBlock& falseBB = m_pFunction->addBasicBlock();
		BasicBlock& mergeBB = _pMergeBlock != nullptr ? *_pMergeBlock : m_pFunction->addBasicBlock();

		addInstruction()->opSelectionMerge(&mergeBB, _mask);
		addInstruction()->opBranchConditional(_pCondition, &trueBB, &falseBB);

		_true(trueBB);
		_false(falseBB);

		trueBB->opBranch(&mergeBB);
		falseBB->opBranch(&mergeBB);

		return mergeBB;
	}

	template<class TrueFunc>
	inline BasicBlock& BasicBlock::If(Instruction* _pCondition, TrueFunc _true, BasicBlock* _pMergeBlock, const Flag<spv::SelectionControlMask> _mask)
	{
		static_assert(traits::is_invocable_v<TrueFunc, BasicBlock&>, "TrueFunc _true is not invocable: _true(BasicBlock& trueBranchBB)");

		BasicBlock& trueBB = m_pFunction->addBasicBlock();
		BasicBlock& mergeBB = _pMergeBlock != nullptr ? *_pMergeBlock : m_pFunction->addBasicBlock();

		addInstruction()->opSelectionMerge(&mergeBB, _mask);
		addInstruction()->opBranchConditional(_pCondition, &trueBB, &mergeBB);

		_true(trueBB);

		trueBB->opBranch(&mergeBB);

		return mergeBB;
	}

	// ContinueFunc is increment func
	template<class ConditionFunc, class ContinueFunc, class LoopBodyFunc>
	inline BasicBlock& BasicBlock::Loop(ConditionFunc _condition, ContinueFunc _continue, LoopBodyFunc _body, BasicBlock* _pMergeBlock, const Flag<spv::LoopControlMask> _mask)
	{
		static_assert(traits::is_invocable_v<ConditionFunc, BasicBlock&>, "ConditionFunc _condition is not invocable: _condition(BasicBlock& condBB)");
		static_assert(traits::is_invocable_v<ContinueFunc, BasicBlock&>, "ContinueFunc _continue is not invocable: _continue(BasicBlock& continueBB)");
		static_assert(traits::is_invocable_v<LoopBodyFunc, BasicBlock&>, "LoopBodyFunc _body is not invocable: _body(BasicBlock& bodyBB)");

		BasicBlock& condBB = m_pFunction->addBasicBlock();
		BasicBlock& bodyBB = m_pFunction->addBasicBlock();
		BasicBlock& continueBB = m_pFunction->addBasicBlock();
		BasicBlock& mergeBB = _pMergeBlock != nullptr ? *_pMergeBlock : m_pFunction->addBasicBlock();

		addInstruction()->opLoopMerge(&mergeBB, &continueBB, _mask);
		addInstruction()->opBranch(&condBB);

		_condition(condBB);
		if (condBB.getTerminator() == nullptr)
		{
			Instruction* pCond = condBB;
			// take last instruction of condBB as conditional
			condBB->opBranchConditional(pCond, &bodyBB, &mergeBB);
		}

		_body(bodyBB);
		bodyBB->opBranch(&continueBB); // branch to "increment" / continue block

		_continue(continueBB);
		continueBB->opBranch(this); // back edge to loop merge

		return mergeBB;
	}
} // !spvgentwo