#pragma once
#include "Instruction.h"

namespace spvgentwo
{
	// forward delcs
	class Module;
	class Function;
	class IAllocator;

	using TInstruction = Entry<Instruction>;

	class BasicBlock
	{
	public:
		using Iterator = EntryIterator<Instruction>;

		BasicBlock(Function* _pFunction);
		~BasicBlock();

		Function* getFunction() { return m_pFunction; }
		const Function* getFunction() const { return m_pFunction; }

		Module* getModule();
		IAllocator* getAllocator();

	private:
		Function* m_pFunction = nullptr; // parent
		TInstruction* m_pInstructions = nullptr;
	};
} // !spvgentwo