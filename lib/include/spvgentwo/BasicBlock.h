#pragma once
#include "Instruction.h"

namespace spvgentwo
{
	// forward delcs
	class Module;
	class Function;
	class IAllocator;
	class IWriter;
	class GLSL450Intruction;

	class BasicBlock : public List<Instruction>
	{
		friend class Module;
		friend class Function;
	private:

		Function* m_pFunction = nullptr; // parent
		Instruction m_Label;

	public:
		BasicBlock() = default;

		BasicBlock(Function* _pFunction, const char* _pName = nullptr);
		BasicBlock(Function* _pFunction, BasicBlock&& _other) noexcept;
		BasicBlock(const BasicBlock&) = delete;

		virtual ~BasicBlock();

		BasicBlock& operator=(BasicBlock&& _other) noexcept;
		BasicBlock& operator=(const BasicBlock& _other) = delete;

		Function* getFunction() const { return m_pFunction; }
		Module* getModule() const;

		const char* getName() const;

		IAllocator* getAllocator() const;

		Instruction* getLabel() { return &m_Label;	}
		const Instruction* getLabel() const { return &m_Label; }

		// get last instruction
		Instruction* getTerminator() const;

		// returns a list of BasicBlock branch targets of this blocks terminator
		bool getBranchTargets(List<BasicBlock*>& _outTargetBlocks) const;

		// manual instruction add
		Instruction* addInstruction();

		Instruction* operator->() { return &emplace_back(this, spv::Op::OpNop); }

		template <class ExtInstr>
		ExtInstr* ext() { return reinterpret_cast<ExtInstr*>(addInstruction()); }

		// call ext<GLSL450Intruction>()
		GLSL450Intruction* glsl();

		// set return value of this block (used in function), returns opReturn/opReturnValue instruction
		Instruction* returnValue(Instruction* _pValue = nullptr);

		// return last operation
		operator Instruction* () const { return m_pLast != nullptr ? m_pLast->operator->() : nullptr; };

		void write(IWriter& _writer) const;

		bool read(IReader& _reader, const Grammar& _grammar);

		// remove instruction from this block (if it is in this block). OpLabel can't be removed. Returns true if the instruction was removed
		bool remove(const Instruction* _pInstr);

		// structured if, returns last instruction of MergeBlock which creats a result
		BasicBlock& If(Instruction* _pCondition, BasicBlock& _trueBlock, BasicBlock& _falseBlock, BasicBlock* _pMergeBlock = nullptr, const Flag<spv::SelectionControlMask> _mask = spv::SelectionControlMask::MaskNone);

		// If without else block
		BasicBlock& If(Instruction* _pCondition, BasicBlock& _trueBlock, BasicBlock* _pMergeBlock = nullptr, const Flag<spv::SelectionControlMask> _mask = spv::SelectionControlMask::MaskNone);
		
		// MergeBlock for selection merge is returned. If _pMergeBlock is nullptr, a new block will be added to the function
		template <class TrueFunc, class FalseFunc>
		BasicBlock& If(Instruction* _pCondition, TrueFunc _true, FalseFunc _false, BasicBlock* _pMergeBlock = nullptr, const Flag<spv::SelectionControlMask> _mask = spv::SelectionControlMask::MaskNone);

		template <class TrueFunc> // If without else block
		BasicBlock& If(Instruction* _pCondition, TrueFunc _true, BasicBlock* _pMergeBlock = nullptr, const Flag<spv::SelectionControlMask> _mask = spv::SelectionControlMask::MaskNone);

		BasicBlock& Loop(Instruction* _pCondition, BasicBlock& _continue, BasicBlock& _body, BasicBlock* _pMergeBlock = nullptr, const Flag<spv::LoopControlMask> _mask = spv::LoopControlMask::MaskNone);

		template <class ConditionFunc, class ContinueFunc, class LoopBodyFunc>
		BasicBlock& Loop(ConditionFunc _condition, ContinueFunc _continue, LoopBodyFunc _body, BasicBlock* _pMergeBlock = nullptr, const Flag<spv::LoopControlMask> _mask = spv::LoopControlMask::MaskNone);

		// infer op code from operands types, emplace instruction in this basic block
		BasicBlock& Add(Instruction* _pLeft, Instruction* _pRight) { addInstruction()->Add(_pLeft, _pRight); return *this; }
		BasicBlock& Sub(Instruction* _pLeft, Instruction* _pRight) { addInstruction()->Sub(_pLeft, _pRight); return *this; }
		BasicBlock& Mul(Instruction* _pLeft, Instruction* _pRight) { addInstruction()->Mul(_pLeft, _pRight); return *this; }
		BasicBlock& Div(Instruction* _pLeft, Instruction* _pRight) { addInstruction()->Div(_pLeft, _pRight); return *this; }

		BasicBlock& Not(Instruction* _pIntOrBool) { addInstruction()->Not(_pIntOrBool); return *this; }
		BasicBlock& Equal(Instruction* _pLeft, Instruction* _pRight) { addInstruction()->Equal(_pLeft, _pRight); return *this; }
		BasicBlock& NotEqual(Instruction* _pLeft, Instruction* _pRight) { addInstruction()->NotEqual(_pLeft, _pRight); return *this; }
		BasicBlock& Less(Instruction* _pLeft, Instruction* _pRight) { addInstruction()->Less(_pLeft, _pRight); return *this; }
		BasicBlock& LessEqual(Instruction* _pLeft, Instruction* _pRight) { addInstruction()->LessEqual(_pLeft, _pRight); return *this; }
		BasicBlock& Greater(Instruction* _pLeft, Instruction* _pRight) { addInstruction()->Greater(_pLeft, _pRight); return *this; }
		BasicBlock& GreaterEqual(Instruction* _pLeft, Instruction* _pRight) { addInstruction()->GreaterEqual(_pLeft, _pRight); return *this; }

		// add _pRight to last instruction in this basic block and push the result (stack like) to this basic block
		BasicBlock& Add(Instruction* _pRight) { return Add(&back(), _pRight); }
		BasicBlock& Sub(Instruction* _pRight) { return Sub(&back(), _pRight); }
		BasicBlock& Mul(Instruction* _pRight) { return Mul(&back(), _pRight); }
		BasicBlock& Div(Instruction* _pRight) { return Div(&back(), _pRight); }
		BasicBlock& Not() { return Not(&back()); }
		BasicBlock& Equal(Instruction* _pRight) { return Equal(&back(), _pRight); }
		BasicBlock& NotEqual(Instruction* _pRight) { return NotEqual(&back(), _pRight); }
		BasicBlock& Less(Instruction* _pRight) { return Less(&back(), _pRight); }
		BasicBlock& LessEqual(Instruction* _pRight) { return LessEqual(&back(), _pRight); }
		BasicBlock& Greater(Instruction* _pRight) { return Greater(&back(), _pRight); }
		BasicBlock& GreaterEqual(Instruction* _pRight) { return GreaterEqual(&back(), _pRight); }
	};
} // !spvgentwo