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
		void addExtension(const char* _pExtName);
		Instruction* addExtensionInstructionImport(const char* _pExtName);

		void setMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel);

		const List<Instruction>& getCapabilities() const { return m_Capabilities; }

	private:

		// preamble
		List<Instruction> m_Capabilities;
		List<Instruction> m_Extensions;
		List<Instruction> m_ExtInstrImport; // todo: map between ext names and Instruction*
		Instruction m_MemoryModel;
	};
} // !spvgentwo