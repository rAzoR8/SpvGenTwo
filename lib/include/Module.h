#pragma once

#include "Function.h"

namespace spvgentwo
{
	// forward decls
	//class IAllocator;

	class Module : public List<Function>
	{
	public:
		Module(IAllocator* _pAllocator);
		~Module();

		Function& addFunction() { return emplace_back(this); }

		void addCapability(const spv::Capability _capability);

		const List<Instruction>& getCapabilities() const { return m_Capabilities; }

	private:

		// preamble
		List<Instruction> m_Capabilities;
	};
} // !spvgentwo