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

		static constexpr unsigned int GeneratorId = makeGeneratorId('fa', 0);

		Function& addFunction() { return emplace_back(this); }

		void addCapability(const spv::Capability _capability);
		void addExtension(const char* _pExtName);
		Instruction* addExtensionInstructionImport(const char* _pExtName);

		Instruction* addType(const Type& _type);
		const Type* getTypeInfo(const Instruction* _pTypeInstr) const;

		template <class T, class ... Props>
		Instruction* type(Props ... _props);

		Instruction* compositeType(const spv::Op _Type, const List<Instruction*>& _subTypes);
		
		template <class ... TypeInstr>
		Instruction* compositeType(const spv::Op _Type, TypeInstr ... _types);
		
		Instruction* addConstant(const Constant& _const);

		template <class T>
		Instruction* constant(const T& _value, const bool _spec = false);
		
		void setMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel);

		const List<Instruction>& getCapabilities() const { return m_Capabilities; }

		void write(IWriter* _pWriter);

		// for use with opString, opSource, opSourceContinued, opSourceExtension
		Instruction* addSourceStringInstr();

		// for use with opName and opMemberName
		Instruction* addNameInstr();

		// for use with opModuleProccessed
		Instruction* addModuleProccessedInstr();

		// for use with opDecoration, opMemberDecoration etc
		Instruction* addDecorationInstr();

		// for use with opVariable with StorageClass != Function
		Instruction* addGlobalVariableInstr();

		// creates new empty type using this modules allocator
		Type newType();

		Constant newConstant();

	private:
		template <class ... TypeInstr>
		void compositeType(Type& _compositeTye, Instruction* _pSubType, TypeInstr ... _types);

	private:

		// preamble
		List<Instruction> m_Capabilities;
		List<Instruction> m_Extensions;
		List<Instruction> m_ExtInstrImport; // todo: map between ext names and Instruction*
		Instruction m_MemoryModel;

		List<Instruction> m_SourceStrings; // opString, opSource, opSourceContinued, opSourceExtension
		List<Instruction> m_Names; // opName, opMemberName
		List<Instruction> m_ModuleProccessed; // opName, opMemberName

		List<Instruction> m_Decorations; // opDecorate, opMemberDecorate
		
		List<Instruction> m_TypesAndConstants;
		HashMap<Type, Instruction*> m_TypeToInstr;
		HashMap<Instruction*, Type*> m_InstrToType;

		HashMap<Constant, Instruction*> m_ConstantBuilder;

		List<Instruction> m_GlobalVariables; //opVariable with StorageClass != Function

		unsigned int m_maxId = 0u;
	};

	template<class T, class ...Props>
	inline Instruction* Module::type(Props ... _props)
	{
		Type dummy(m_pAllocator);
		return addType(dummy.make<T>(_props...));
	}

	template<class T>
	inline Instruction* Module::constant(const T& _value, const bool _spec)
	{
		Constant dummy(m_pAllocator);
		return addConstant(dummy.make<T>(_value, _spec));
	}

	template<class ...TypeInstr>
	inline Instruction* Module::compositeType(const spv::Op _Type, TypeInstr ..._types)
	{
		Type t(m_pAllocator);
		t.setType(_Type);

		if constexpr (sizeof...(_types) > 0u)
		{
			compositeType(t, _types...);
		}
	
		return addType(t);
	}

	template<class ...TypeInstr>
	inline void Module::compositeType(Type& _compositeType, Instruction* _pSubType, TypeInstr ..._types)
	{
		const Type* info = getTypeInfo(_pSubType);
		if (info != nullptr)
		{
			_compositeType.getSubTypes().emplace_back(*info);
		}

		if constexpr (sizeof...(_types) > 0u)
		{
			compositeType(_compositeType, _types...);
		};
	}
} // !spvgentwo