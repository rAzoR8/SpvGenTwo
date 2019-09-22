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

		//Instruction* getReturnOp() { return &m_Return; }
		//Instruction* getReturnValue();

		void write(IWriter* _pWriter, spv::Id& _resultId);

	private:
		Function* m_pFunction = nullptr; // parent
	};
} // !spvgentwo