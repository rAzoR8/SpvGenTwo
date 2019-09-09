#pragma once
#include "BasicBlock.h"

namespace spvgentwo
{
	// forward delcs
	class Module;
	//class BasicBlock;
	class IAllocator;

	using TBasicBlock = Entry<BasicBlock>;

	class Function
	{
	public:
		Function(Module* _pModule);
		~Function();

		TBasicBlock* addBasicBlock();

		Module* getModule() { return m_pModule; }
		const Module* getModule() const { return m_pModule; }

		IAllocator* getAllocator();
	private:
		Module* m_pModule = nullptr; // parent
		TBasicBlock* m_pBasicBlocks = nullptr;
	};
} // !spvgentwo