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

		Module(IAllocator* _pAllocator = nullptr, ILogger* _pLogger = nullptr, ITypeInferenceAndVailation* _pTypeInferenceAndVailation = nullptr);
		Module(IAllocator* _pAllocator, const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel,  ILogger* _pLogger = nullptr, ITypeInferenceAndVailation* _pTypeInferenceAndVailation = nullptr);

		Module(Module&& _other) noexcept;
		~Module();

		Module& operator=(Module&& _other) noexcept;

		// SpvGenTwo SPIR-V IR Tools" - https://github.com/KhronosGroup/SPIRV-Headers/pull/210
		static constexpr unsigned int GeneratorId = makeGeneratorId(30, 0);

		// reset module to its initial / empty state - clear all functions and instructions etc (invalidate all pointers)
		void reset();

		unsigned int getSpvVersion() const { return m_spvVersion; }
		void setSpvVersion(unsigned int _version) { m_spvVersion = _version; }
		void setSpvVersion(unsigned char _major, unsigned char _minor) { m_spvVersion = makeVersion(_major, _minor); }
		void ensureSpvVersion(unsigned char _major, unsigned char _minor);

		unsigned int getMajorVersion() const { return spvgentwo::getMajorVersion(m_spvVersion); }
		unsigned int getMinorVersion() const { return spvgentwo::getMinorVersion(m_spvVersion); }

		unsigned int getGeneratorVersion() const { return spvgentwo::getGeneratorVersion(m_spvGenerator); }
		unsigned int getGeneratorId() const { return spvgentwo::getGeneratorId(m_spvGenerator); }

		unsigned int getSpvGenerator() const { return m_spvGenerator; }
		void setSpvGenerator(unsigned int _generator) { m_spvGenerator = _generator; }

		unsigned int getSpvBound() const { return m_spvBound; }
		void setSpvBound(unsigned int _bound) { m_spvBound = _bound; }

		unsigned int getSpvSchema() const { return m_spvSchema; }
		void setSpvSchema(unsigned int _schema) { m_spvSchema = _schema; }

		// get next free Id for use as ResultId operand
		spv::Id getNextId() { return spv::Id{ m_spvBound++ }; }

		IAllocator* getAllocator() const { return m_pAllocator; }

		ILogger* getLogger() const { return m_pLogger; }
		void setLogger(ILogger* _pLogger) { m_pLogger = _pLogger; }

		ITypeInferenceAndVailation* getTypeInferenceAndVailation() const { return m_pTypeInferenceAndVailation; }
		void setITypeInferenceAndVailation(ITypeInferenceAndVailation* _pTypeInferenceAndVailation) { m_pTypeInferenceAndVailation = _pTypeInferenceAndVailation; }

		const List<Function>& getFunctions() const { return m_Functions; }
		List<Function>& getFunctions() { return m_Functions; }

		const List<EntryPoint>& getEntryPoints() const { return m_EntryPoints; }
		List<EntryPoint>& getEntryPoints() { return m_EntryPoints; }

		const HashMap<spv::Capability, Instruction>& getCapabilities() const { return m_Capabilities; }
		HashMap<spv::Capability, Instruction>& getCapabilities() { return m_Capabilities; }

		const HashMap<String, Instruction>& getExtensions() const { return m_Extensions; }
		HashMap<String, Instruction>& getExtensions() { return m_Extensions; }

		const HashMap<String, Instruction>& getExtInstrImports() const { return m_ExtInstrImport; }
		HashMap<String, Instruction>& getExtInstrImports() { return m_ExtInstrImport; }

		const Instruction& getMemoryModel() const { return m_MemoryModel; }
		Instruction& getMemoryModel() { return m_MemoryModel; }

		const List<Instruction>& getExecutionModes() const { return m_ExecutionModes; }
		List<Instruction>& getExecutionModes() { return m_ExecutionModes; }

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

		// look for instructions referenced by OpName matching string _pName (case sensitive)
		Instruction* getInstructionByName(const char* _pName) const;

		// add empty function
		Function& addFunction();

		template <class ReturnType = void, class ... ParameterTypes>
		Function& addFunction(const char* _pFunctionName = nullptr, Flag<spv::FunctionControlMask> _control = spv::FunctionControlMask::MaskNone, bool _addEntryBasicBlock = true);

		// remove Function or EntryPoint, returns list of Instructions which consumed the function (calls outside the function itself)
		// _pAllocator to use for allocating List<Instruction*> (use modules allocator if nullptr)
		List<Instruction*> remove(const Function* _pFunction, Function* _pReplacementToCall = nullptr, IAllocator* _pAllocator = nullptr);

		// add empty entry point
		EntryPoint& addEntryPoint();

		template <class ReturnType = void, class ... ParameterTypes>
		EntryPoint& addEntryPoint(spv::ExecutionModel _model, const char* _pEntryPointName, Flag<spv::FunctionControlMask> _control = spv::FunctionControlMask::MaskNone, bool _addEntryBasicBlock = true);

		// add OpCapability if not present in the module, _addDependentCapablity adds base capabilities (not required) for _capability: Geometry->Shader etc.
		void addCapability(spv::Capability _capability, bool _addDependentCapablity = false);

		// check if OpCapability is present in the module
		bool checkCapability(spv::Capability _capability) const;

		// returns true if OpCapability matching _capability was in the module
		bool removeCapability(spv::Capability _capability);
		
		// add OpExtension with name _pExtName
		void addExtension(const char* _pExtName);

		// add OpExtension
		void addExtension(spv::Extension _ext) { addExtension(spv::ExtensionNames[static_cast<unsigned int>(_ext)]); }

		// add OpExtInstImport with name _pExtName
		Instruction* addExtensionInstructionImport(const char* _pExtName);

		// look up OpExtInstImport with name _pExtName, returns nullptr if not found
		Instruction* getExtensionInstructionImport(const char* _pExtName) const;

		// add OpTypeXXX instruction for _type to the type system, returns OpType;
		// implicitly adds OpConstant instruction for OpTypeArray operand
		Instruction* addType(const Type& _type, const char* _pName = nullptr);

		//get OpTypeXXX instruction for _type or nullptr if not in the type system
		Instruction* getTypeInstr(const Type& _type) const;

		// get type info associated to OpTypeXXX _pTypeInstr
		const Type* getTypeInfo(const Instruction* _pTypeInstr) const;

		// add a new instruction to m_TypesAndConstants, if _pType is not nullptr, also add entries in m_TypeToInstr and m_InstrToType maps
		Instruction* addTypeInstr(const Type* _pType = nullptr);

		// add a new instruction to m_TypesAndConstants, if _pConstant is not nullptr, also add entry in m_ConstantBuilder map
		Instruction* addConstantInstr(const Constant* _pConstant = nullptr);

		// construct a new OpType from:
		// T = type like int, float*, vector_t<float,3>, dyn_sampled_image_t etc.
		// Props = list of modifiers from spv::StorageClass, spv::Dim, spv::Op, spv::AccessQualifier, SamplerImageAccess, spv::ImageFormat, spv::ImageFormat or even a subtype const Type&
		template <class T, class ... Props>
		Instruction* type(const Props& ... _props);

		Instruction* compositeType(const spv::Op _Type, const List<Instruction*>& _subTypes);
		
		// create new composite type from _type as base type and Instruction* _types as subtypes
		template <class ... TypeInstr>
		Instruction* compositeType(const spv::Op _Type, TypeInstr* ... _types);
		
		Instruction* addConstant(const Constant& _const, const char* _pName = nullptr);
		const Constant* getConstantInfo(const Instruction* _pConstantInstr);

		template <class T>
		Instruction* constant(const T& _value, bool _spec = false, const char* _pName = nullptr);

		template <class T>
		Instruction* specConstant(const T& _value, const char* _pName = nullptr) { return constant<T>(_value, true, _pName); }
		
		void setMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel);

		// assign IDs to all unresolved instructions, returns bounds/max id
		// converts any Instruction pointer operand to an spv::Id
		// adds missing OpCapabilities if _pGrammar != nullptr
		// adds missing OpExtensions if _pGrammar != nullptr
		// sets minimum required version if _pGrammar != nullptr
		spv::Id assignIDs(const Grammar* _pGrammar = nullptr);

		// converts any spv::Id operand to Instruction pointer operands
		// resets resultId to InvalidId for new assignment
		bool resolveIDs(IAllocator* _pAllocator = nullptr);

		// create 'Type' and 'Constant' infos from OpType### and OpConstant### instructions in m_TypesAndConstants and add them to m_TypeToInstr and m_InstrToType
		// resolveIDs() must have been called before to allow sub type lookup
		bool reconstructTypeAndConstantInfo(IAllocator* _pAllocator = nullptr);

		// recover the strings from OpName instructions for m_NameLookup
		bool reconstructNames(IAllocator* _pAllocator = nullptr);

		// serializes module to IWriter, IDs must have been assigned using assignIDs()
		// IDs dont need to be assigned if the module was parsed using read()
		// returns false if IWriter::put failed
		bool write(IWriter& _writer) const;

		// call this function before any call to module.write()!
		// calls finalizeGlobalInterface() on EntryPoints
		// automatically assigns IDs (calls assignIDs, adds Required Capabilities & Extensions & Version if _pGrammar != nullptr)
		spv::Id finalize( const Grammar* _pGrammar = nullptr );

		// calls finalize()
		// serializes module to IWriter
		bool finalizeAndWrite(IWriter& _writer, const Grammar* _pGrammar = nullptr);

		// calls finalizeGlobalInterface() on all EntryPoints, adds referenced global variables to OpEntryPoint parameters
		void finalizeEntryPoints();

		// parse a binary SPIR-V program from IReader using _grammer generated from SPIR-V machinereadable grammer json
		bool read(IReader& _reader, const Grammar& _grammar);

		// calls read(), resolveIDs, reconstructNames and reconstrucTypesAndConstantInfo
		bool readAndInit(IReader& _reader, const Grammar& _grammar);

		// for use with opExtensionMode, opExtensionModeId
		Instruction* addExtensionModeInstr();

		// for use with opString, opSource, opSourceContinued, opSourceExtension
		Instruction* addSourceStringInstr();

		// for use with opName and opMemberName, is not added to nameLookup
		Instruction* addNameInstr();

		void addName(Instruction* _pTarget, const char* _pName);
		void addMemberName(Instruction* _pTargetBase, const char* _pMemberName, unsigned int _memberIndex);

		// get name string of instruction _pTarget that was decorated with OpName
		const char* getName(const Instruction* _pTarget, const unsigned int _memberIndex = ~0u) const;

		struct MemberNameCStr { const char* name; unsigned int memberIndex; };

		// get all names associated to these instruction
		List<MemberNameCStr> getNames(const Instruction* _pTarget, IAllocator* _pAllocator = nullptr) const;

		// for use with opModuleProccessed
		Instruction* addModuleProccessedInstr();

		// for use with opDecoration, opMemberDecoration etc
		Instruction* addDecorationInstr();

		// creates new empty type using this modules allocator
		Type newType() const;

		// creates new type, calls make with Args using this modules allocator
		template <class T, class ... Props>
		Type newType(const Props& ... _props) const;

		// creates new empty constant using this modules allocator
		Constant newConstant() const;

		// add empty instruction which must be OpVarible with StorageClass != function
		Instruction* addGlobalVariableInstr(const char* _pName = nullptr);

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
		bool iterateInstructions(Func _func);

		template <class Func> // func takes const Instruction& -> func(instr)
		bool iterateInstructions(Func _func) const;

		// search for instruction assigned to _resultId (for use with resolved instructions generated by assignIDs())
		Instruction* getInstructionById(const spv::Id _resultId);

		// collect all instructions which consume _pInstr (needs to generate result id) and replase its reference with _pReplacement if not nullptr
		void gatherUses(const Instruction* _pInstr, List<Instruction*>& _outUses, Instruction* _pReplacement = nullptr);

		// replace any use of _pInstr as an operand with _pReplacement
		void replaceUses(const Instruction* _pInstr, Instruction* _pReplacement);

		// remove _pInstr from type/constant and name lookup maps
		void removeFromLookupMaps(const Instruction* _pInstr);

		// remove _pInstr if it is homed in this module, its functions and basic blocks, returns true if it was removed
		bool remove(const Instruction* _pInstr);

		// scans instructions of this module, looking for required OpCapabilities using _grammar, adding them to m_Capabilities
		void addRequiredCapabilities(const Grammar& _grammar);

		// scans instructions of this module, looking for required OpExtensions using _grammar, adding them to m_Extensions
		void addRequiredExtensions(const Grammar& _grammar);

		// scans instrucions of this module, getting the highest required SPIR-V version
		unsigned int getRequiredVersion(const Grammar& _grammar) const;

		// overwrites m_spvVersion with getRequiredVersion(), returns version
		unsigned int setRequiredVersion(const Grammar& _grammar);

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
		void updateParentPointers();

	private:
		IAllocator* m_pAllocator = nullptr;
		ILogger* m_pLogger = nullptr;
		ITypeInferenceAndVailation* m_pTypeInferenceAndVailation = nullptr;
		unsigned int m_spvVersion = spv::Version;
		unsigned int m_spvGenerator = GeneratorId;
		unsigned int m_spvBound = 0u;
		unsigned int m_spvSchema = 0u;
		List<Function> m_Functions;
		List<EntryPoint> m_EntryPoints;

		// preamble
		HashMap<spv::Capability, Instruction> m_Capabilities;
		HashMap<String, Instruction> m_Extensions; // map between extension name and OpExtension
		HashMap<String, Instruction> m_ExtInstrImport; // map between instruction extension names and opExtInstImport
		Instruction m_MemoryModel;

		List<Instruction> m_ExecutionModes; // opExecutionMode, opExecutionModeId
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
} // !spvgentwo