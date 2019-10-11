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

		BasicBlock(IAllocator* _pAllocator);
		BasicBlock(Function* _pFunction);
		~BasicBlock();

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

		void write(IWriter* _pWriter, spv::Id& _resultId);

		// structured if: true and false block must NOT have a terminator yet!
		// returns last instruction of MergeBlock which creats a result
		Instruction* If(Instruction* _pCondition, BasicBlock& _trueBlock, BasicBlock& _falseBlock, BasicBlock& _mergeBlock, const spv::SelectionControlMask _mask = spv::SelectionControlMask::MaskNone);

		// infer op code from operands types, emplace instruction in this basic block
		Instruction* Add(Instruction* _pLeft, Instruction* _pRight);
		Instruction* Sub(Instruction* _pLeft, Instruction* _pRight);
		Instruction* Mul(Instruction* _pLeft, Instruction* _pRight);
		Instruction* Div(Instruction* _pLeft, Instruction* _pRight);

	private:
		Function* m_pFunction = nullptr; // parent
	};
} // !spvgentwo