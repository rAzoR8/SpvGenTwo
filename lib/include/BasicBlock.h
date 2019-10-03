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
		void If(Instruction* _pCondition, BasicBlock& _trueBlock, BasicBlock& _falseBlock, BasicBlock& _mergeBlock, const spv::SelectionControlMask _mask = spv::SelectionControlMask::MaskNone);

	private:
		Function* m_pFunction = nullptr; // parent
	};
} // !spvgentwo