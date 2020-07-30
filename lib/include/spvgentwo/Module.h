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
		struct MemberName { String name; unsigned int member = 0u; };

		Module() = default;

		Module(IAllocator* _pAllocator, const unsigned int _spvVersion = spv::Version,  ILogger* _pLogger = nullptr, ITypeInferenceAndVailation* _pTypeInferenceAndVailation = nullptr);
		Module(IAllocator* _pAllocator, const unsigned int _spvVersion, const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel,  ILogger* _pLogger = nullptr, ITypeInferenceAndVailation* _pTypeInferenceAndVailation = nullptr);

		Module(Module&& _other) noexcept;
		~Module();

		Module& operator=(Module&& _other) noexcept;

		// 0xFabian's SPIR-V generator
		static constexpr unsigned int GeneratorId = makeGeneratorId(0xfa, 0);

		// reset module to its initial / empty state - clear all functions and instructions etc (invalidate all pointers)
		void reset();

		unsigned int getSpvVersion() const { return m_spvVersion; }
		unsigned int getMajorVersion() const { return spvgentwo::getMajorVersion(m_spvVersion); }
		unsigned int getMinorVersion() const { return spvgentwo::getMinorVersion(m_spvVersion); }
		unsigned int getSpvGenerator() const { return m_spvGenerator; }
		unsigned int getSpvBound() const { return m_spvBound; }
		unsigned int getSpvSchema() const { return m_spvSchema; }

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
		HashMap<const char*, Instruction>& getExtInstrImports() { return m_ExtInstrImport; }

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

		const List<Instruction>& getUndefs() const { return m_Undefs; }
		List<Instruction>& getUndefs() { return m_Undefs; }

		const List<Instruction>& getLines() const { return m_Lines; }
		List<Instruction>& getLines() { return m_Lines; }

		const HashMap<const Instruction*, MemberName>& getNameLookupMap() const { return m_NameLookup; }
		HashMap<const Instruction*, MemberName>& getNameLookupMap() { return m_NameLookup; }

		// add empty function
		Function& addFunction();

		template <class ReturnType = void, class ... ParameterTypes>
		Function& addFunction(const char* _pFunctionName = nullptr, const Flag<spv::FunctionControlMask> _control = spv::FunctionControlMask::MaskNone, const bool _addEntryBasicBlock = true);

		// remove Function or EntryPoint, returns list of Instructions which consumed the function (calls outside the function itself)
		List<Instruction*> remove(const Function* _pFunction, Function* _pReplacementToCall = nullptr);

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

		// add a new instruction to m_TypesAndConstants, if _pType is not nullptr, also add entries in m_TypeToInstr and m_InstrToType maps
		Instruction* addTypeInstr(const Type* _pType = nullptr);

		// add a new instruction to m_TypesAndConstants, if _pConstant is not nullptr, also add entry in m_ConstantBuilder map
		Instruction* addConstantInstr(const Constant* _pConstant = nullptr);

		template <class T, class ... Props>
		Instruction* type(const Props& ... _props);

		Instruction* compositeType(const spv::Op _Type, const List<Instruction*>& _subTypes);
		
		template <class ... TypeInstr>
		Instruction* compositeType(const spv::Op _Type, TypeInstr ... _types);
		
		Instruction* addConstant(const Constant& _const, const char* _pName = nullptr);
		const Constant* getConstantInfo(const Instruction* _pConstantInstr);

		template <class T>
		Instruction* constant(const T& _value, const bool _spec = false);

		template <class T>
		Instruction* specConstant(const T& _value) { return constant<T>(_value, true); };
		
		void setMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel);

		// manually assign IDs to all unresolved instructions, returns bounds/max id
		// converts any Instruction pointer operand to an spv::Id
		spv::Id assignIDs();

		// converts any spv::Id operand to Instruction pointer operands
		// resets resultId to InvalidId for new assignment
		bool resolveIDs();

		// create 'Type' and 'Constant' infos from OpType### and OpConstant### instructions in m_TypesAndConstants and add them to m_TypeToInstr and m_InstrToType
		// resolveIDs() must have been called before to allow sub type lookup
		bool reconstructTypeAndConstantInfo();

		// recover the strings from OpName instructions for m_NameLookup
		bool reconstructNames();

		// automatically assigns IDs if _assingIDs (otherwise m_Bounds must be set) and serializes module to IWriter
		// IDs dont need to be assigned if the module was parsed using read()
		void write(IWriter* _pWriter, const bool _assingIDs = true);

		// parse a binary SPIR-V program from IReader using _grammer generated from SPIR-V machinereadable grammer json
		bool read(IReader* _pReader, const Grammar& _grammar);

		// for use with opString, opSource, opSourceContinued, opSourceExtension
		Instruction* addSourceStringInstr();

		// for use with opName and opMemberName
		Instruction* addNameInstr();
		void addName(Instruction* _pTarget, const char* _pName);
		void addMemberName(Instruction* _pTargetBase, const char* _pMemberName, unsigned int _memberIndex);

		// get name string of instruction _pTarget that was decorated with OpName
		const char* getName(const Instruction* _pTarget, const unsigned int _memberIndex = ~0u) const;

		struct MemberNameCStr { const char* name; unsigned int memberIndex; };
		// get all names associated to theis instruction
		Vector<MemberNameCStr> getNames(const Instruction* _pTarget) const;

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

		// add empty instruction which must be OpVarible with StorageClass != function
		Instruction* addGlobalVariableInstr();

		// _pPtrType needs to be in the same StorageClass as _storageClass
		Instruction* variable(Instruction* _pPtrType, const spv::StorageClass _storageClass, const char* _pName = nullptr, Instruction* _pInitialzer = nullptr);

		// if ptrType is not a pointer, it will be wrapped by a pointer with _storageClass
		Instruction* variable(const Type& _ptrType, const spv::StorageClass _storageClass, const char* _pName = nullptr, Instruction* _pInitialzer = nullptr);

		template <class T> // adds Pointer to type T
		Instruction* variable(const spv::StorageClass _storageClass, const char* _pName = nullptr, Instruction* _pInitialzer = nullptr);

		template <class T>
		Instruction* variable(const spv::StorageClass _storageClass, const T& _initialValue, const char* _pName = nullptr);

		Instruction* uniformConstant(const Type& _ptrType, const char* _pName, Instruction* _pInitialzer = nullptr) { return variable(_ptrType, spv::StorageClass::UniformConstant, _pName, _pInitialzer); }
		template <class T> // constant uniform variable
		Instruction* uniformConstant(const char* _pName, Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::UniformConstant, _pName, _pInitialzer); }
		template <class T> // constant uniform variable
		Instruction* uniformConstant(const char* _pName, const T& _dynTypeDesc) { return variable<T>(spv::StorageClass::UniformConstant, _dynTypeDesc, _pName); }

		Instruction* uniform(const Type& _ptrType, const char* _pName, Instruction* _pInitialzer = nullptr) { return variable(_ptrType, spv::StorageClass::Uniform, _pName, _pInitialzer); }
		template <class T> // uniform variable
		Instruction* uniform(const char* _pName, Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::Uniform, _pName, _pInitialzer); }
		template <class T> // uniform variable
		Instruction* uniform(const char* _pName, const T& _dynTypeDesc) { return variable<T>(spv::StorageClass::Uniform, _dynTypeDesc, _pName); }

		Instruction* input(const Type& _ptrType, const char* _pName, Instruction* _pInitialzer = nullptr) { return variable(_ptrType, spv::StorageClass::Input, _pName, _pInitialzer); }
		template <class T> // input variable
		Instruction* input(const char* _pName, Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::Input, _pName, _pInitialzer); }
		template <class T> // input variable
		Instruction* input(const char* _pName, const T& _dynTypeDesc) { return variable<T>(spv::StorageClass::Input, _dynTypeDesc, _pName); }

		Instruction* output(const Type& _ptrType, const char* _pName, Instruction* _pInitialzer = nullptr) { return variable(_ptrType, spv::StorageClass::Output, _pName, _pInitialzer); }
		template <class T> // output variable
		Instruction* output(const char* _pName, Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::Output, _pName, _pInitialzer); }
		template <class T> // output variable
		Instruction* output(const char* _pName, const T& _dynTypeDesc) { return variable<T>(spv::StorageClass::Output, _dynTypeDesc, _pName); }

		Instruction* pushConstant(const Type& _ptrType, const char* _pName, Instruction* _pInitialzer = nullptr) { return variable(_ptrType, spv::StorageClass::PushConstant, _pName, _pInitialzer); }
		template <class T> // push constant variable
		Instruction* pushConstant(const char* _pName, Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::PushConstant, _pName, _pInitialzer); }
		template <class T> // push constant variable
		Instruction* pushConstant(const char* _pName, const T& _dynTypeDesc) { return variable<T>(spv::StorageClass::PushConstant, _dynTypeDesc, _pName); }

		Instruction* image(const Type& _ptrType, const char* _pName, Instruction* _pInitialzer = nullptr) { return variable(_ptrType, spv::StorageClass::Image, _pName, _pInitialzer); }
		template <class T> // image variable
		Instruction* image(const char* _pName, Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::Image, _pName, _pInitialzer); }
		template <class T> // image variable
		Instruction* image(const char* _pName, const T& _dynTypeDesc) { return variable<T>(spv::StorageClass::Image, _dynTypeDesc, _pName); }

		Instruction* storageBuffer(const Type& _ptrType, const char* _pName, Instruction* _pInitialzer = nullptr) { return variable(_ptrType, spv::StorageClass::StorageBuffer, _pName, _pInitialzer); }
		template <class T> // buffer variable
		Instruction* storageBuffer(const char* _pName, Instruction* _pInitialzer = nullptr) { return variable<T>(spv::StorageClass::StorageBuffer, _pName, _pInitialzer); }
		template <class T> // buffer variable
		Instruction* storageBuffer(const char* _pName, const T& _dynTypeDesc) { return variable<T>(spv::StorageClass::StorageBuffer, _dynTypeDesc, _pName); }

		// add empty instruction which must be OpUndef
		Instruction* addUndefInstr();

		// add empty instruction which must be OpLine or OpNoLine
		Instruction* addLineInstr();

		// iterates over all instructions in this module in serialization order, should be called AFTER write() which does some finalization
		template <class Func> // func takes Instruction& -> func(instr)
		void iterateInstructions(Func _func) { iterateModuleInstructions(*this, _func); }

		template <class Func> // func takes const Instruction& -> func(instr)
		void iterateInstructions(Func _func) const { iterateModuleInstructions(*this, _func); }

		// search for instruction assigned to _resultId (for use with resolved instructions generated by assignIDs())
		Instruction* findInstructionById(const spv::Id _resultId);

		// collect all instructions which consume _pInstr (needs to generate result id) and replase its reference with _pReplacement if not nullptr
		void gatherUses(const Instruction* _pInstr, List<Instruction*>& _outUses, Instruction* _pReplacement = nullptr);

		// replace any use of _pInstr as an operand with _pReplacement
		void replaceUses(const Instruction* _pInstr, Instruction* _pReplacement);

		// remove _pInstr from type/constant and name lookup maps
		void removeFromLookupMaps(const Instruction* _pInstr);

		// remove _pInstr if it is homed in this module, its functions and basic blocks, returns true if it was removed
		bool remove(const Instruction* _pInstr);

		// ILogger proxy calls
		template <typename ...Args>
		bool log(bool _pred, const LogLevel _level, const char* _pFormat, Args... _args) const;

		template <typename ...Args>
		void log(const LogLevel _level, const char* _pFormat, Args... _args) const { log(false, _level, _pFormat, _args...); }

		template <typename ...Args>
		void logDebug(const char* _pFormat, Args... _args) const { log(LogLevel::Debug, _pFormat, _args...); }
		template <typename ...Args>
		void logInfo(const char* _pFormat, Args... _args) const { log(LogLevel::Info, _pFormat, _args...); }
		template <typename ...Args>
		void logWarning(const char* _pFormat, Args... _args) const { log(LogLevel::Warning, _pFormat, _args...); }
		template <typename ...Args>
		void logError(const char* _pFormat, Args... _args) const { log(LogLevel::Error, _pFormat, _args...); }
		template <typename ...Args>
		void logFatal(const char* _pFormat, Args... _args) const { log(LogLevel::Fatal, _pFormat, _args...); }

		// like assert, _pred == false -> log, returns _pred
		template <typename ...Args>
		bool logDebug(bool _pred, const char* _pFormat, Args... _args) const { return log(_pred, LogLevel::Debug, _pFormat, _args...); }
		template <typename ...Args>
		bool logInfo(bool _pred, const char* _pFormat, Args... _args) const { return log(_pred, LogLevel::Info, _pFormat, _args...); }
		template <typename ...Args>
		bool logWarning(bool _pred, const char* _pFormat, Args... _args) const { return log(_pred, LogLevel::Warning, _pFormat, _args...); }
		template <typename ...Args>
		bool logError(bool _pred, const char* _pFormat, Args... _args) const { return log(_pred, LogLevel::Error, _pFormat, _args...); }
		template <typename ...Args>
		bool logFatal(bool _pred, const char* _pFormat, Args... _args) const { return log(_pred, LogLevel::Fatal, _pFormat, _args...); }

		// this instruction can be used as a return value for a failed operation (instruction could not be constructed etc)
		Instruction* getErrorInstr() { return &m_errorInstr; }
		const Instruction* getErrorInstr() const { return &m_errorInstr; }

	private:
		template <class ... TypeInstr>
		void compositeType(Type& _compositeTye, Instruction* _pSubType, TypeInstr ... _types);

		void updateParentPointers();

	private:
		IAllocator* m_pAllocator = nullptr;
		ILogger* m_pLogger = nullptr;
		ITypeInferenceAndVailation* m_pTypeInferenceAndVailation = nullptr;
		unsigned int m_spvVersion = spv::Version;
		unsigned int m_spvGenerator = GeneratorId;
		unsigned int m_spvBound = InvalidId;
		unsigned int m_spvSchema = 0u;
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
		HashMap<const Instruction*, const Type*> m_InstrToType;
		HashMap<Constant, Instruction*> m_ConstantToInstr;
		HashMap<const Instruction*, const Constant*> m_InstrToConstant;

		// instruction that was decorated with opName or OpMemberName(Target) -> name
		HashMap<const Instruction*, MemberName> m_NameLookup;

		List<Instruction> m_GlobalVariables; //opVariable with StorageClass != Function

		List<Instruction> m_Undefs; // opUndef
		List<Instruction> m_Lines; // opLine, opNoLine

		Instruction m_errorInstr; // opNop
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
		else
		{
			logError("Type info not found for _pSubType");
			return;
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

	// returns TRUE if Func has bool return value and returned true (to exit loop)
	template<class Func, class Container>
	inline bool iterateInstructionContainer(Func _func, Container& _container)
	{
		static_assert(traits::is_invocable_v<Func, Instruction&>, "Func _func is not invocable: _func(Instruction& _instr)");
		using Ret = decltype(stdrep::declval<Func>()(stdrep::declval<Instruction&>()));

		for (auto& instr : _container)
		{
			if constexpr (stdrep::is_same_v<Ret, bool>)
			{
				if (_func(traits::to_ref(instr)))
					return true;
			}
			else
			{
				_func(traits::to_ref(instr));			
			}
		}

		return false;
	}

	// if func returns a bool, TRUE indecates to abort iterating
	template<class ModuleT, class Func>
	inline void iterateModuleInstructions(ModuleT& _module, Func _func)
	{
		static_assert(traits::is_invocable_v<Func, Instruction&>, "Func _func is not invocable: _func(Instruction& _instr)");
		using Ret = decltype(stdrep::declval<Func>()(stdrep::declval<Instruction&>()));
		
		if (iterateInstructionContainer(_func, _module.getCapabilities())) return;
		if (iterateInstructionContainer(_func, _module.getExtensions())) return;

		auto pred = [&_func](auto& instr) -> bool
		{
			if constexpr (stdrep::is_same_v<Ret, bool>)
			{
				return _func(instr);
			}
			else
			{
				_func(instr);
			}

			return false;
		};

		for (auto& [key, value] : _module.getExtInstrImports())
		{
			if (pred(value)) return;
		}

		if (pred(_module.getMemoryModel())) return;

		for (auto& ep : _module.getEntryPoints())
		{
			if (pred(*ep.getEntryPoint())) return;
		}
		for (auto& ep : _module.getEntryPoints())
		{
			if (iterateInstructionContainer(_func, ep.getExecutionModes())) return;
		}

		if (iterateInstructionContainer(_func, _module.getSourceStrings())) return;
		if (iterateInstructionContainer(_func, _module.getNames())) return;
		if (iterateInstructionContainer(_func, _module.getModulesProcessed())) return;
		if (iterateInstructionContainer(_func, _module.getDecorations())) return;
		if (iterateInstructionContainer(_func, _module.getTypesAndConstants())) return;
		if (iterateInstructionContainer(_func, _module.getGlobalVariables())) return;
		if (iterateInstructionContainer(_func, _module.getUndefs())) return;
		if (iterateInstructionContainer(_func, _module.getLines())) return;

		auto iterateFuncion = [&_module, &pred, &_func](auto& f) -> bool
		{
			if (pred(*f.getFunction())) return true;
			if (iterateInstructionContainer(_func, f.getParameters())) return true;
			for (auto& bb : f)
			{
				if (pred(*bb.getLabel())) return true;
				if (iterateInstructionContainer(_func, bb)) return true;
				if (bb.getTerminator() == nullptr)
				{
					_module.logError("BasicBlock %s has no terminator instruction, missing opReturn?", bb.getName());
					return true;
				}
			}
			if (pred(*f.getFunctionEnd())) return true;
			return false;
		};

		for (auto& fun : _module.getFunctions())
		{
			if (fun.empty())
			{
				if (iterateFuncion(fun)) return;
			}
		}

		// write functions with bodies
		for (auto& fun : _module.getFunctions())
		{
			if (fun.empty() == false)
			{
				if (iterateFuncion(fun)) return;
			}
		}
		for (auto& ep : _module.getEntryPoints())
		{
			if (ep.empty() == false) // can entry points be empty forward decls?
			{
				if (iterateFuncion(ep)) return;
			}
		}
	}
} // !spvgentwo