#pragma once

#include "Function.h"
#include "HashMap.h"
#include "Constant.h"

namespace spvgentwo
{
	// forward decls
	//class IAllocator;

	class Module : public List<Function>
	{
	public:
		Module(IAllocator* _pAllocator);
		~Module();

		static constexpr unsigned int GeneratorId = 'fabi';

		Function& addFunction() { return emplace_back(this); }

		void addCapability(const spv::Capability _capability);
		void addExtension(const char* _pExtName);
		Instruction* addExtensionInstructionImport(const char* _pExtName);

		const Instruction* addConstant(const Constant& _const);
		const Instruction* addType(const Type& _type);

		void setMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel);

		const List<Instruction>& getCapabilities() const { return m_Capabilities; }

		void write(IWriter* _pWriter) const;

		// creates new empty type using this modules allocator
		Type& newType();

		Constant& newConstant();

	private:

		// preamble
		List<Instruction> m_Capabilities;
		List<Instruction> m_Extensions;
		List<Instruction> m_ExtInstrImport; // todo: map between ext names and Instruction*
		Instruction m_MemoryModel;

		List<Instruction> m_TypesAndConstants;
		HashMap<Type, Instruction*> m_TypeBuilder;

		List<Type> m_userTypes; // just for convenience
		List<Constant> m_userConstants; // just for convenience

		unsigned int m_maxId = 0u;
	};
} // !spvgentwo