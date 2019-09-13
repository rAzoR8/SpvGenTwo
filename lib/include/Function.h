#pragma once
#include "BasicBlock.h"

namespace spvgentwo
{
	// forward delcs
	class Module;
	class IAllocator;

	class Function : public List<BasicBlock>
	{
	public:
		Function(IAllocator* _pAllocator);
		Function(Module* _pModule);
		~Function();

		BasicBlock& addBasicBlock() { return emplace_back(this); }

		Module* getModule() { return m_pModule; }
		const Module* getModule() const { return m_pModule; }

		IAllocator* getAllocator();
	private:
		Module* m_pModule = nullptr; // parent
	};
} // !spvgentwo