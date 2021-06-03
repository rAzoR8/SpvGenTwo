#pragma once

#include "BasicBlock.h"
#include "Type.h"

namespace spvgentwo
{
	// forward delcs
	class Module;
	class IAllocator;
	class EntryPoint;

	enum class GlobalInterfaceVersion
	{
		SpirV1_3, // 1.0 - 1.3 Input and Output StorageClass
		SpirV14_x // 1.4 - 1.x any StorageClass != Function
	};

	class Function : public List<BasicBlock>
	{
		friend class Module;

	public:
		Function() = default;

		// empty function, call setReturnType() first, then use addParameters() and then finalize() to create the function
		Function(Module* _pModule);

		// creates the whole function signature, finalize() does NOT need to be called
		template <class ... TypeInstr>
		Function(Module* _pModule, const char* _pName, const Flag<spv::FunctionControlMask> _control, Instruction* _pReturnType, TypeInstr* ... _paramTypeInstructions);

		Function(Module* _pModule, Function&& _other) noexcept;
		Function(const Function& _other) = delete;

		virtual ~Function();

		Function& operator=(Function&& _other) noexcept;
		Function& operator=(const Function& _other) = delete;

		// OpFunction 
		Instruction* getFunction() { return &m_Function; }
		const Instruction* getFunction() const { return &m_Function; }

		// returns void by default
		const Type& getReturnType() const { return m_FunctionType.front(); }
		Type& getReturnType() { return m_FunctionType.front(); }

		// calling this function will materialize the result type operand of OpTypeFunction (add it to the module type lookup)
		Instruction* getReturnTypeInstr() const;

		const Type& getFunctionType() const { return m_FunctionType; }
		Type& getFunctionType() { return m_FunctionType; }

		// calling this function will materialize the OpTypeFunction. It should only be called after finalizing
		Instruction* getFunctionTypeInstr() const;

		Instruction* getFunctionEnd() { return &m_FunctionEnd; }
		const Instruction* getFunctionEnd() const { return &m_FunctionEnd; }

		Module* getModule() const { return m_pModule; }

		// get name assigned by OpName (if any). Calls Module::getName(&m_Function)
		const char* getName() const;

		bool isEntryPoint() const { return m_isEntryPoint; }
		EntryPoint* asEntryPoint() { return m_isEntryPoint ? reinterpret_cast<EntryPoint*>(this) : nullptr; }
		const EntryPoint* asEntryPoint() const { return m_isEntryPoint ? reinterpret_cast<const EntryPoint*>(this) : nullptr; }

		BasicBlock& addBasicBlock(const char* _pName = nullptr) { return emplace_back(this, _pName); }

		// remove _pBB from this function (destroying it), optionally replacing it with _pReplacement, returning uses of this basic block or its label
		// if bool _gatherReferencedInstructions is true, also return uses of instructions from the removed basic block (OpName etc)
		List<Instruction*> remove(const BasicBlock* _pBB, BasicBlock* _pReplacement = nullptr, IAllocator* _pAllocator = nullptr);

		// return entry bb (avoid confusion when adding a BB to this function and instructions are "magically" added to the last BB if using m_pLast
		BasicBlock& operator->() { return m_pBegin->inner(); }
		operator BasicBlock& () { return m_pBegin->inner();}
		BasicBlock& operator*() { return m_pBegin->inner(); }

		// write OpFunction OpFunctionParameters <BasicBlocks> OpFunctionEnd to IWriter
		void write(IWriter& _writer) const;

		// read function from IReader user _grammer, assuming OpFunction was already parsed/consumed by module::read(Reader* _pReader)
		bool read(IReader& _rader, const Grammar& _grammar, Instruction&& _opFunc);

		// storage class is Function
		Instruction* variable(Instruction* _pPtrType, const char* _pName = nullptr, Instruction* _pInitialzer = nullptr);

		// if ptrType is not a pointer, it will be wrapped by a pointer with _storageClass
		Instruction* variable(const Type& _ptrType, const char* _pName = nullptr, Instruction* _pInitialzer = nullptr);

		template <class T> // adds Pointer to type T
		Instruction* variable(const char* _pName = nullptr, Instruction* _pInitialzer = nullptr);

		template <class T>
		Instruction* variable(const T& _initialValue, const char* _pName = nullptr);

		// set the first subtype of OpTypeFunction (opperands are added by addParameters), returns true on success
		bool setReturnType(Instruction* _pReturnType);
		bool setReturnType(const Type& _returnType);

		// sets m_FunctionType (OpTypeFunction), return true on success
		bool setFunctionType(Instruction* _pFunctionType);
		bool setFunctionType(const Type& _functionType);

		// adds opFunctionParameter(_pParamType) to m_parameters and _pParamType to m_pFunctionType, returns last opFunctionParameter generated
		template <class ... TypeInstr>
		Instruction* addParameters(Instruction* _pParamType, TypeInstr* ... _paramTypeInstructions);

		// get opFunctionParameter in order they were added by addParameters
		Instruction* getParameter(unsigned int _index) const;

		// get list of all OpFunctionParameter instructions added by addParameters()
		const List<Instruction>& getParameters() const { return m_Parameters; }
		List<Instruction>& getParameters() { return m_Parameters; }

		// creates opFunction, m_pFunctionType must have been completed (all parameters added via addParameters), returns opFunction
		Instruction* finalize(const Flag<spv::FunctionControlMask> _control, const char* _pName = nullptr);

		// returns true if this Functions has a valid OpFunctionType & m_Function is setup to OpFunction
		bool isFinalized() const;

		Flag<spv::FunctionControlMask> getFunctionControl() const;

	protected:
		Module* m_pModule = nullptr; // parent

		Instruction m_Function; // OpFunction
		Instruction m_FunctionEnd;

		Type m_FunctionType;

		List<Instruction> m_Parameters; // OpFunctionParameters

		bool m_isEntryPoint = false;
	};

	// get all the global OpVariables with StorageClass != Function used in this function
	void collectReferencedVariables(const Function& _func, List<Operand>& _outVarInstr, const GlobalInterfaceVersion _version, IAllocator* _pAllocator);
} // !spvgentwo