#pragma once

#include "EntryPoint.h"
#include "HashMap.h"
#include "Constant.h"
#include "Logger.h"

namespace spvgentwo
{
	class Module
	{
	public:
		Module(const unsigned int _spvVersion, IAllocator* _pAllocator, ILogger* _pLogger = nullptr);
		~Module();

		static constexpr unsigned int GeneratorId = makeGeneratorId(0xfa, 0);

		unsigned int getSpvVersion() const { return m_spvVersion; }

		void log(const LogLevel _level, const char* _pMsg);
		void logDebug(const char* _pMsg) { log(LogLevel::Debug, _pMsg); }
		void logInfo(const char* _pMsg) { log(LogLevel::Info, _pMsg); }
		void logWarning(const char* _pMsg) { log(LogLevel::Warning, _pMsg); }
		void logError(const char* _pMsg) { log(LogLevel::Error, _pMsg); }
		void logFatal(const char* _pMsg) { log(LogLevel::Fatal, _pMsg); }

		IAllocator* getAllocator() const { return m_pAllocator; }

		template <class ReturnType = void, class ... ParameterTypes>
		Function& addFunction(const char* _pFunctionName = nullptr, const Flag<spv::FunctionControlMask> _control = spv::FunctionControlMask::MaskNone, const bool _addEntryBasicBlock = true);

		template <class ReturnType = void, class ... ParameterTypes>
		EntryPoint& addEntryPoint(const spv::ExecutionModel _model, const char* _pEntryPointName, const Flag<spv::FunctionControlMask> _control = spv::FunctionControlMask::MaskNone, const bool _addEntryBasicBlock = true);

		void addCapability(const spv::Capability _capability);
		bool checkCapability(const spv::Capability _capability) const;
		
		// adds capability if not present
		void checkAddCapability(const spv::Capability _capability);
		
		void addExtension(const char* _pExtName);
		Instruction* getExtensionInstructionImport(const char* _pExtName);

		Instruction* addType(const Type& _type);
		const Type* getTypeInfo(const Instruction* _pTypeInstr) const;

		template <class T, class ... Props>
		Instruction* type(const Props& ... _props);

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
		void addName(Instruction* _pTarget, const char* _pName);
		void addMemberName(Instruction* _pMember, const char* _pMemberName, unsigned int _memberIndex);

		// for use with opModuleProccessed
		Instruction* addModuleProccessedInstr();

		// for use with opDecoration, opMemberDecoration etc
		Instruction* addDecorationInstr();

		// creates new empty type using this modules allocator
		Type newType();

		// creates new type, calls make with Args using this modules allocator
		template <class T, class ... Props>
		Type newType(const Props& ... _props);

		Constant newConstant();

		// _pPtrType needs to be in the same StorageClass as _storageClass
		Instruction* variable(Instruction* _pPtrType, const spv::StorageClass _storageClass, const char* _pName = nullptr, Instruction* _pInitialzer = nullptr);

		template <class T> // adds Pointer to type T
		Instruction* variable(const spv::StorageClass _storageClass, const char* _pName = nullptr, Instruction* _pInitialzer = nullptr);

		template <class T>
		Instruction* variable(const spv::StorageClass _storageClass, const T& _initialValue, const char* _pName = nullptr);

		template <class T> // constant uniform variable
		Instruction* uniformConstant(const char* _pName, Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::UniformConstant, _pName, _pInitialzer); }
		template <class T> // constant uniform variable
		Instruction* uniformConstant(const char* _pName, const T& _dynTypeDesc) { return variable<T>(spv::StorageClass::UniformConstant, _dynTypeDesc, _pName); }

		template <class T> // uniform variable
		Instruction* uniform(const char* _pName, Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::Uniform, _pName, _pInitialzer); }
		template <class T> // uniform variable
		Instruction* uniform(const char* _pName, const T& _dynTypeDesc) { return variable<T>(spv::StorageClass::Uniform, _dynTypeDesc, _pName); }

		template <class T> // input variable
		Instruction* input(const char* _pName, Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::Input, _pName, _pInitialzer); }
		template <class T> // input variable
		Instruction* input(const char* _pName, const T& _dynTypeDesc) { return variable<T>(spv::StorageClass::Input, _dynTypeDesc, _pName); }

		template <class T> // output variable
		Instruction* output(const char* _pName, Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::Output, _pName, _pInitialzer); }
		template <class T> // output variable
		Instruction* output(const char* _pName, const T& _dynTypeDesc) { return variable<T>(spv::StorageClass::Output, _dynTypeDesc, _pName); }

		template <class T> // push constant variable
		Instruction* pushConstant(const char* _pName, Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::PushConstant, _pName, _pInitialzer); }
		template <class T> // push constant variable
		Instruction* pushConstant(const char* _pName, const T& _dynTypeDesc) { return variable<T>(spv::StorageClass::PushConstant, _dynTypeDesc, _pName); }

		template <class T> // (strage )image variable
		Instruction* image(const char* _pName, Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::Image, _pName, _pInitialzer); }
		template <class T> // (strage )image variable
		Instruction* image(const char* _pName, const T& _dynTypeDesc) { return variable<T>(spv::StorageClass::Image, _dynTypeDesc, _pName); }

		template <class T> // image variable
		Instruction* storageBuffer(const char* _pName, Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::StorageBuffer, _pName, _pInitialzer); }
		template <class T> // image variable
		Instruction* storageBuffer(const char* _pName, const T& _dynTypeDesc) { return variable<T>(spv::StorageClass::StorageBuffer, _dynTypeDesc, _pName); }

		// iterates over all instructions in this module in serialization order, should be called AFTER write() which does some finalization
		template <class Func> // func takes const Instruction& -> func(instr)
		void iterateInstructions(const Func& _func) const;

	private:
		template <class ... TypeInstr>
		void compositeType(Type& _compositeTye, Instruction* _pSubType, TypeInstr ... _types);

	private:
		IAllocator* m_pAllocator = nullptr;
		ILogger* m_pLogger = nullptr;
		unsigned int m_spvVersion = spv::Version;
		List<Function> m_Functions;
		List<EntryPoint> m_EntryPoints;

		// preamble
		List<Instruction> m_Capabilities;
		List<Instruction> m_Extensions;
		HashMap<const char*, Instruction> m_ExtInstrImport; // todo: map between ext names and Instruction*
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
	inline Function& Module::addFunction(const char* _pFunctionName, const Flag<spv::FunctionControlMask> _control, const bool _addEntryBasicBlock)
	{
		Function& func = m_Functions.emplace_back(this, _pFunctionName, _control, type<ReturnType>(), type<ParameterTypes>()...);

		if (_addEntryBasicBlock)
		{
			func.addBasicBlock();		
		}

		return func;
	}

	template<class ReturnType, class ...ParameterTypes>
	inline EntryPoint& Module::addEntryPoint(const spv::ExecutionModel _model, const char* _pEntryPointName, const Flag<spv::FunctionControlMask> _control, const bool _addEntryBasicBlock)
	{
		EntryPoint& entry = m_EntryPoints.emplace_back(this, _model, _pEntryPointName, _control, type<ReturnType>(), type<ParameterTypes>()...);

		if (_addEntryBasicBlock)
		{
			entry.addBasicBlock();
		}

		return entry;
	}

	template<class T, class ... Props>
	inline Instruction* Module::type(const Props& ... _props)
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

	template<class T, class ... Props>
	inline Type Module::newType(const Props& ... _props)
	{
		Type t(m_pAllocator);
		t.make<T>(_props...);
		return t;
	}

	template<class T>
	inline Instruction* Module::variable(const spv::StorageClass _storageClass, const char* _pName, Instruction* _pInitialzer)
	{
		return variable(type<T*>(_storageClass), _storageClass, _pName, _pInitialzer);
	}

	template<class T>
	inline Instruction* Module::variable(const spv::StorageClass _storageClass, const T& _initialValue, const char* _pName)
	{
		if constexpr (is_dyntype_desc_v<T>)
		{
			return variable(type<T*>(_initialValue, _storageClass), _storageClass, _pName);
		}
		else
		{
			return variable<T>(_storageClass, _pName, constant(_initialValue));		
		}
	}

	template<class Func, class Container>
	inline void iterateInstructionContainer(const Func& _func, const Container& _container)
	{
		static_assert(traits::is_invocable_v<Func, const Instruction&>, "Func _func is not invocable: _func(const Instruction& _instr)");

		for (const auto& instr : _container)
		{
			_func(traits::to_ref(instr));
		}
	}

	template<class Func>
	inline void Module::iterateInstructions(const Func& _func) const
	{
		static_assert(traits::is_invocable_v<Func, const Instruction&>, "Func _func is not invocable: _func(const Instruction& _instr)");
		iterateInstructionContainer(_func, m_Capabilities);
		iterateInstructionContainer(_func, m_Extensions);

		for (const auto& [key, value] : m_ExtInstrImport)
		{
			_func(value);
		}

		_func(m_MemoryModel);

		for (const EntryPoint& ep : m_EntryPoints)
		{
			_func(*ep.getEntryPoint());
		}
		for (const EntryPoint& ep : m_EntryPoints)
		{
			iterateInstructionContainer(_func, ep.getExecutionModes());
		}

		iterateInstructionContainer(_func, m_SourceStrings);
		iterateInstructionContainer(_func, m_Names);
		iterateInstructionContainer(_func, m_ModuleProccessed);
		iterateInstructionContainer(_func, m_Decorations);
		iterateInstructionContainer(_func, m_TypesAndConstants);
		iterateInstructionContainer(_func, m_GlobalVariables);

		auto iterateFuncion = [&_func](const Function& f)
		{
			_func(*f.getFunction());
			iterateInstructionContainer(_func, f.getParameters());
			for (const BasicBlock& bb : f)
			{
				iterateInstructionContainer(_func, bb);
			}
			_func(*f.getFunctionEnd());
		};

		for (Function& fun : m_Functions)
		{
			if (fun.empty())
			{
				iterateFuncion(fun);
			}
		}

		// write functions with bodies
		for (Function& fun : m_Functions)
		{
			if (fun.empty() == false)
			{
				iterateFuncion(fun);
			}
		}
		for (EntryPoint& ep : m_EntryPoints)
		{
			if (ep.empty() == false) // can entry points be empty forward decls?
			{
				iterateFuncion(ep);
			}
		}
	}
} // !spvgentwo