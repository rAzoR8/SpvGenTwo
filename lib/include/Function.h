#pragma once
#include "BasicBlock.h"
#include "Type.h"

namespace spvgentwo
{
	// forward delcs
	class Module;
	class IAllocator;

	class Function : public List<BasicBlock>
	{
	public:
		// empty function, call setReturnType() first, then use addParameters() and then finalize() to create the function
		Function(Module* _pModule);

		// creates the whole function signature, finalize() does NOT need to be called
		template <class ... TypeInstr>
		Function(Module* _pModule, const char* _pName, const Flag<spv::FunctionControlMask> _control, Instruction* _pReturnType, TypeInstr* ... _paramTypeInstructions);

		Function(Function&& _other) noexcept;

		virtual ~Function();

		Function& operator=(Function&& _other) noexcept;

		// OpFunction 
		Instruction* getFunction() { return &m_Function; }
		const Instruction* getFunction() const { return &m_Function; }
		Instruction* getReturnType() const { return m_pReturnType; }
		Instruction* getFunctionType() const { return m_pFunctionType; }

		Instruction* getFunctionEnd() { return &m_FunctionEnd; }
		const Instruction* getFunctionEnd() const { return &m_FunctionEnd; }

		Module* getModule() { return m_pModule; }
		const Module* getModule() const { return m_pModule; }

		BasicBlock& addBasicBlock() { return emplace_back(this); }

		// return entry bb (avoid confusion when adding a BB to this function and instructions are "magically" added to the last BB if using m_pLast
		BasicBlock& operator->() { return m_pBegin->inner(); }
		operator BasicBlock& () {return m_pBegin->inner();}
		BasicBlock& operator*() { return m_pBegin->inner(); }

		Instruction* getParameter(unsigned int _index);

		void write(IWriter* _pWriter, spv::Id& _resultId);		

		const List<Instruction>& getParameters() const { return m_Parameters; }

		// storage class is Function
		Instruction* variable(Instruction* _pPtrType, Instruction* _pInitialzer = nullptr, const char* _pName = nullptr);

		template <class T> // adds Pointer to type T
		Instruction* variable(Instruction* _pInitialzer = nullptr, const char* _pName = nullptr);

		template <class T>
		Instruction* variable(const T& _initialValue, const char* _pName = nullptr);

		// creates m_pFunctionType with OpTypeFunction and _pReturnType (opperands are added by addParameters), returns m_pFunctionType
		Instruction* setReturnType(Instruction* _pReturnType);

		// adds opFunctionParameter(_pParamType) to m_parameters and _pParamType to m_pFunctionType, returns last opFunctionParameter generated
		template <class ... TypeInstr>
		Instruction* addParameters(Instruction* _pParamType, TypeInstr* ... _paramTypeInstructions);

		// creates opFunction, m_pFunctionType must have been completed (all parameters added via addParameters), returns opFunction
		Instruction* finalize(const Flag<spv::FunctionControlMask> _control, const char* _pName = nullptr);

	protected:
		Module* m_pModule = nullptr; // parent
		Instruction* m_pReturnType = nullptr;

		Instruction m_Function; // OpFunction
		Instruction m_FunctionEnd;

		Instruction* m_pFunctionType = nullptr;

		List<Instruction> m_Parameters; // OpFunctionParameters
	};

	template<class ...TypeInstr>
	inline Function::Function(Module* _pModule, const char* _pName, const Flag<spv::FunctionControlMask> _control, Instruction* _pReturnType, TypeInstr* ..._paramTypeInstructions) :
		List(_pModule->getAllocator()), 
		m_pModule(_pModule),
		m_pReturnType(_pReturnType),
		m_Function(this),
		m_FunctionEnd(this, spv::Op::OpFunctionEnd),
		m_Parameters(_pModule->getAllocator())
	{
		// function signature type
		setReturnType(_pReturnType);

		if constexpr (sizeof...(_paramTypeInstructions) > 0)
		{
			addParameters(_paramTypeInstructions...);		
		}

		finalize(_control, _pName);
	}

	template<class ... TypeInstr>
	inline Instruction* Function::addParameters(Instruction* _pParamType, TypeInstr* ..._paramTypeInstructions)
	{
		Instruction* param = m_Parameters.emplace_back(this).opFunctionParameter(_pParamType);
		m_pFunctionType->addOperand(_pParamType);

		if constexpr (sizeof...(_paramTypeInstructions) > 0)
		{
			return addParameters(_paramTypeInstructions...);
		}

		return param;
	}

	template<class T>
	inline Instruction* Function::variable(Instruction* _pInitialzer, const char* _pName)
	{
		return variable(getModule()->type<T*>(spv::StorageClass::Function), _pInitialzer, _pName);
	}

	template<class T>
	inline Instruction* Function::variable(const T& _initialValue, const char* _pName)
	{
		return variable(getModule()->type<T*>(spv::StorageClass::Function, _initialValue), getModule()->constant(_initialValue), _pName);
	}
} // !spvgentwo