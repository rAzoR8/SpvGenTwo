#pragma once

#include "EntryPoint.h"
#include "HashMap.h"
#include "Constant.h"

namespace spvgentwo
{
	class Module
	{
	public:
		Module(IAllocator* _pAllocator);
		~Module();

		static constexpr unsigned int GeneratorId = makeGeneratorId('fa', 0);

		IAllocator* getAllocator() { return m_pAllocator; }
		const IAllocator* getAllocator() const { return m_pAllocator; }

		template <class ReturnType = void, class ... ParameterTypes>
		Function& addFunction(const Flag<spv::FunctionControlMask> _control = spv::FunctionControlMask::MaskNone);

		template <class ReturnType = void, class ... ParameterTypes>
		EntryPoint& addEntryPoint(const spv::ExecutionModel _model, const char* _pEntryPointName, const Flag<spv::FunctionControlMask> _control = spv::FunctionControlMask::MaskNone);

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

		// creates new empty type using this modules allocator
		Type newType();

		Constant newConstant();

		// _pPtrType needs to be in the same StorageClass as _storageClass
		Instruction* variable(Instruction* _pPtrType, const spv::StorageClass _storageClass, Instruction* _pInitialzer = nullptr);

		template <class T> // adds Pointer to type T
		Instruction* variable(const spv::StorageClass _storageClass, Instruction* _pInitialzer = nullptr);

		template <class T>
		Instruction* variable(const spv::StorageClass _storageClass, const T& _initialValue);

		template <class T> // constant uniform variable
		Instruction* uniformConstant(Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::UniformConstant, _pInitialzer); }

		template <class T> // uniform variable
		Instruction* uniform(Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::Uniform, _pInitialzer); }

		template <class T> // input variable
		Instruction* input(Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::Input, _pInitialzer); }

		template <class T> // output variable
		Instruction* output(Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::Output, _pInitialzer); }

		template <class T> // push constant variable
		Instruction* pushConstant(Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::PushConstant, _pInitialzer); }

		template <class T> // image variable
		Instruction* image(Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::Image, _pInitialzer); }

		template <class T> // image variable
		Instruction* storageBuffer(Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::StorageBuffer, _pInitialzer); }

	private:
		template <class ... TypeInstr>
		void compositeType(Type& _compositeTye, Instruction* _pSubType, TypeInstr ... _types);

	private:
		IAllocator* m_pAllocator = nullptr;
		List<Function> m_Functions;
		List<EntryPoint> m_EntryPoints;

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

	template<class ReturnType, class ...ParameterTypes>
	inline Function& Module::addFunction(const Flag<spv::FunctionControlMask> _control)
	{
		return m_Functions.emplace_back(this, _control, type<ReturnType>(), type<ParameterTypes>()...);
	}

	template<class ReturnType, class ...ParameterTypes>
	inline EntryPoint& Module::addEntryPoint(const spv::ExecutionModel _model, const char* _pEntryPointName, const Flag<spv::FunctionControlMask> _control)
	{
		return m_EntryPoints.emplace_back(this, _model, _pEntryPointName, _control, type<ReturnType>(), type<ParameterTypes>()...);
	}

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

	template<class T>
	inline Instruction* Module::variable(const spv::StorageClass _storageClass, Instruction* _pInitialzer)
	{
		return variable(type<T*>(_storageClass), _storageClass, _pInitialzer);
	}

	template<class T>
	inline Instruction* Module::variable(const spv::StorageClass _storageClass, const T& _initialValue)
	{
		return variable<T>(_storageClass, constant(_initialValue));
	}
} // !spvgentwo