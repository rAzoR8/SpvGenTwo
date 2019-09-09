#pragma once
#include "Instruction.h"

namespace spvgentwo
{
	// forward delcs
	class Module;
	class Function;
	class IAllocator;

	class BasicBlock : public List<Instruction>
	{
	public:

		BasicBlock(Function* _pFunction);
		~BasicBlock();

		Function* getFunction() { return m_pFunction; }
		const Function* getFunction() const { return m_pFunction; }

		Module* getModule();
		IAllocator* getAllocator();

		// get last instruction
		Iterator getTerminator();

		// manual instruction add
		EntryType* addInstruction() { return emplace_back(this); }

	private:
		Function* m_pFunction = nullptr; // parent
	};
} // !spvgentwo