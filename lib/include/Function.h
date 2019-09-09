#pragma once
#include "BasicBlock.h"

namespace spvgentwo
{
	// forward delcs
	class Module;
	class IAllocator;

	using TBasicBlock = Entry<BasicBlock>;

	class Function
	{
	public:
		using Iterator = EntryIterator<BasicBlock>;

		Function(Module* _pModule);
		~Function();

		TBasicBlock* addBasicBlock();

		Module* getModule() { return m_pModule; }
		const Module* getModule() const { return m_pModule; }

		Iterator begin() const { return Iterator(m_pBasicBlocks); }
		Iterator end() const { return Iterator(nullptr); }

		IAllocator* getAllocator();
	private:
		Module* m_pModule = nullptr; // parent
		TBasicBlock* m_pBasicBlocks = nullptr;
	};
} // !spvgentwo