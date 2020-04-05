#pragma once

#include "EntryPoint.h"
#include "HashMap.h"
#include "Constant.h"
#include "Logger.h"
#include "String.h"

namespace spvgentwo
{
	// forward delcs:
	class ITypeInferenceAndVailation;

	class Module
	{
	public:
		Module(IAllocator* _pAllocator, const unsigned int _spvVersion = spv::Version,  ILogger* _pLogger = nullptr, ITypeInferenceAndVailation* _pTypeInferenceAndVailation = nullptr);
		Module(IAllocator* _pAllocator, const unsigned int _spvVersion, const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel,  ILogger* _pLogger = nullptr, ITypeInferenceAndVailation* _pTypeInferenceAndVailation = nullptr);

		Module(Module&& _other) noexcept;
		~Module();

		Module& operator=(Module&& _other) noexcept;

		static constexpr unsigned int GeneratorId = makeGeneratorId(0xfa, 0);

		// reset module to its initial / empty state - clear all functions and instructions etc (invalidate all pointers)
		void reset();

		unsigned int getSpvVersion() const { return m_spvVersion; }

		IAllocator* getAllocator() const { return m_pAllocator; }

		ILogger* getLogger() const { return m_pLogger; }
		void setLogger(ILogger* _pLogger) { m_pLogger = _pLogger; }
		ITypeInferenceAndVailation* getTypeInferenceAndVailation() const { return m_pTypeInferenceAndVailation; }
		void setITypeInferenceAndVailation(ITypeInferenceAndVailation* _pTypeInferenceAndVailation) { m_pTypeInferenceAndVailation = _pTypeInferenceAndVailation; }

		const List<Function>& getFunctions() const { return m_Functions; }
		List<Function>& getFunctions() { return m_Functions; }

		const List<EntryPoint>& getEntryPoints() const { return m_EntryPoints; }
		List<EntryPoint>& getEntryPoints() { return m_EntryPoints; }

		const List<Instruction>& getCapabilities() const { return m_Capabilities; }
		List<Instruction>& getCapabilities() { return m_Capabilities; }

		const List<Instruction>& getExtensions() const { return m_Extensions; }
		List<Instruction>& getExtensions() { return m_Extensions; }

		const HashMap<const char*, Instruction>& getExtInstrImports() const { return m_ExtInstrImport; }

		const Instruction& getMemoryModel() const { return m_MemoryModel; }
		Instruction& getMemoryModel() { return m_MemoryModel; }

		const List<Instruction>& getSourceStrings() const { return m_SourceStrings; }
		List<Instruction>& getSourceStrings() { return m_SourceStrings; }

		const List<Instruction>& getNames() const { return m_Names; }
		List<Instruction>& getNames() { return m_Names; }

		const List<Instruction>& getModulesProcessed() const { return m_ModuleProccessed; }
		List<Instruction>& getModulesProcessed() { return m_ModuleProccessed; }

		const List<Instruction>& getDecorations() const { return m_Decorations; }
		List<Instruction>& getDecorations() { return m_Decorations; }

		const List<Instruction>& getTypesAndConstants() const { return m_TypesAndConstants; }
		List<Instruction>& getTypesAndConstants() { return m_TypesAndConstants; }

		const List<Instruction>& getGlobalVariables() const { return m_GlobalVariables; }
		List<Instruction>& getGlobalVariables() { return m_GlobalVariables; }

		// add empty function
		Function& addFunction();

		template <class ReturnType = void, class ... ParameterTypes>
		Function& addFunction(const char* _pFunctionName = nullptr, const Flag<spv::FunctionControlMask> _control = spv::FunctionControlMask::MaskNone, const bool _addEntryBasicBlock = true);

		// add empty entry point
		EntryPoint& addEntryPoint();

		template <class ReturnType = void, class ... ParameterTypes>
		EntryPoint& addEntryPoint(const spv::ExecutionModel _model, const char* _pEntryPointName, const Flag<spv::FunctionControlMask> _control = spv::FunctionControlMask::MaskNone, const bool _addEntryBasicBlock = true);

		void addCapability(const spv::Capability _capability);
		bool checkCapability(const spv::Capability _capability) const;
		
		// adds capability if not present
		void checkAddCapability(const spv::Capability _capability);
		
		void addExtension(const char* _pExtName);
		Instruction* getExtensionInstructionImport(const char* _pExtName);

		Instruction* addType(const Type& _type, const char* _pName = nullptr);
		const Type* getTypeInfo(const Instruction* _pTypeInstr) const;

		template <class T, class ... Props>
		Instruction* type(const Props& ... _props);

		Instruction* compositeType(const spv::Op _Type, const List<Instruction*>& _subTypes);
		
		template <class ... TypeInstr>
		Instruction* compositeType(const spv::Op _Type, TypeInstr ... _types);
		
		Instruction* addConstant(const Constant& _const, const char* _pName = nullptr);

		template <class T>
		Instruction* constant(const T& _value, const bool _spec = false);
		
		void setMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel);

		// manually assign IDs to all unresolved instructions, returns bounds/max id
		spv::Id assignIDs();

		// automatically assigns IDs and serializes module to IWriter
		void write(IWriter* _pWriter);

		// for use with opString, opSource, opSourceContinued, opSourceExtension
		Instruction* addSourceStringInstr();

		// for use with opName and opMemberName
		Instruction* addNameInstr();
		void addName(Instruction* _pTarget, const char* _pName);
		void addMemberName(Instruction* _pMember, const char* _pMemberName, unsigned int _memberIndex);

		const char* getName(const Instruction* _pTarget) const;

		// for use with opModuleProccessed
		Instruction* addModuleProccessedInstr();

		// for use with opDecoration, opMemberDecoration etc
		Instruction* addDecorationInstr();

		// creates new empty type using this modules allocator
		Type newType();

		// creates new type, calls make with Args using this modules allocator
		template <class T, class ... Props>
		Type newType(const Props& ... _props);

		// creates new empty constant using this modules allocator
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
		template <class Func> // func takes Instruction& -> func(instr)
		void iterateInstructions(Func _func);

		// ILogger proxy calls
		template <typename ...Args>
		bool log(bool _pred, const LogLevel _level, const char* _pFormat, Args... _args) const;

		template <typename ...Args>
		void log(const LogLevel _level, const char* _pFormat, Args... _args) const { log(false, _level, _pFormat, _args...); }

		template <typename ...Args>
		void logDebug(const char* _pFormat, Args... _args) { log(LogLevel::Debug, _pFormat, _args...); }
		template <typename ...Args>
		void logInfo(const char* _pFormat, Args... _args) { log(LogLevel::Info, _pFormat, _args...); }
		template <typename ...Args>
		void logWarning(const char* _pFormat, Args... _args) { log(LogLevel::Warning, _pFormat, _args...); }
		template <typename ...Args>
		void logError(const char* _pFormat, Args... _args) { log(LogLevel::Error, _pFormat, _args...); }
		template <typename ...Args>
		void logFatal(const char* _pFormat, Args... _args) { log(LogLevel::Fatal, _pFormat, _args...); }

		// like assert, _pred == false -> log, returns _pred
		template <typename ...Args>
		bool logDebug(bool _pred, const char* _pFormat, Args... _args) { return log(_pred, LogLevel::Debug, _pFormat, _args...); }
		template <typename ...Args>
		bool logInfo(bool _pred, const char* _pFormat, Args... _args) { return log(_pred, LogLevel::Info, _pFormat, _args...); }
		template <typename ...Args>
		bool logWarning(bool _pred, const char* _pFormat, Args... _args) { return log(_pred, LogLevel::Warning, _pFormat, _args...); }
		template <typename ...Args>
		bool logError(bool _pred, const char* _pFormat, Args... _args) { return log(_pred, LogLevel::Error, _pFormat, _args...); }
		template <typename ...Args>
		bool logFatal(bool _pred, const char* _pFormat, Args... _args) { return log(_pred, LogLevel::Fatal, _pFormat, _args...); }

	private:
		template <class ... TypeInstr>
		void compositeType(Type& _compositeTye, Instruction* _pSubType, TypeInstr ... _types);

		void updateParentPointers();

	private:
		IAllocator* m_pAllocator = nullptr;
		ILogger* m_pLogger = nullptr;
		ITypeInferenceAndVailation* m_pTypeInferenceAndVailation = nullptr;
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
		List<Instruction> m_ModuleProccessed; // OpModuleProcessed
		List<Instruction> m_Decorations; // opDecorate, opMemberDecorate
		
		List<Instruction> m_TypesAndConstants;
		HashMap<Type, Instruction*> m_TypeToInstr;
		HashMap<const Instruction*, Type*> m_InstrToType;

		// instruction that was decorated with opName -> name
		HashMap<const Instruction*, String> m_NameLookup;

		HashMap<Constant, Instruction*> m_ConstantBuilder;

		List<Instruction> m_GlobalVariables; //opVariable with StorageClass != Function
	};

	template<typename ...Args>
	inline bool Module::log(bool _pred, const LogLevel _level, const char* _pFormat, Args ..._args) const
	{
#ifdef SPVGENTWO_LOGGING
		if (m_pLogger != nullptr && _pred == false)
		{
			m_pLogger->log(_level, _pFormat, _args...);
		}
#endif
		return _pred;
	}

	template<class ReturnType, class ...ParameterTypes>
	inline Function& Module::addFunction(const char* _pFunctionName, const Flag<spv::FunctionControlMask> _control, const bool _addEntryBasicBlock)
	{
		Function& func = m_Functions.emplace_back(this, _pFunctionName, _control, type<ReturnType>(), type<ParameterTypes>()...);

		if (_addEntryBasicBlock)
		{
			func.addBasicBlock("FunctionEntry");		
		}

		return func;
	}

	template<class ReturnType, class ...ParameterTypes>
	inline EntryPoint& Module::addEntryPoint(const spv::ExecutionModel _model, const char* _pEntryPointName, const Flag<spv::FunctionControlMask> _control, const bool _addEntryBasicBlock)
	{
		EntryPoint& entry = m_EntryPoints.emplace_back(this, _model, _pEntryPointName, _control, type<ReturnType>(), type<ParameterTypes>()...);

		if (_addEntryBasicBlock)
		{
			entry.addBasicBlock("FunctionEntry");
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
	inline void iterateInstructionContainer(Func& _func, Container& _container)
	{
		static_assert(traits::is_invocable_v<Func, Instruction&>, "Func _func is not invocable: _func(const Instruction& _instr)");

		for (auto& instr : _container)
		{
			_func(traits::to_ref(instr));
		}
	}

	template<class Func>
	inline void Module::iterateInstructions(Func _func)
	{
		static_assert(traits::is_invocable_v<Func, Instruction&>, "Func _func is not invocable: _func(const Instruction& _instr)");
		iterateInstructionContainer(_func, m_Capabilities);
		iterateInstructionContainer(_func, m_Extensions);

		for (auto& [key, value] : m_ExtInstrImport)
		{
			_func(value);
		}

		_func(m_MemoryModel);

		for (EntryPoint& ep : m_EntryPoints)
		{
			_func(*ep.getEntryPoint());
		}
		for (EntryPoint& ep : m_EntryPoints)
		{
			iterateInstructionContainer(_func, ep.getExecutionModes());
		}

		iterateInstructionContainer(_func, m_SourceStrings);
		iterateInstructionContainer(_func, m_Names);
		iterateInstructionContainer(_func, m_ModuleProccessed);
		iterateInstructionContainer(_func, m_Decorations);
		iterateInstructionContainer(_func, m_TypesAndConstants);
		iterateInstructionContainer(_func, m_GlobalVariables);

		auto iterateFuncion = [&_func](Function& f)
		{
			_func(*f.getFunction());
			iterateInstructionContainer(_func, f.getParameters());
			for (BasicBlock& bb : f)
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