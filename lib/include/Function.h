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
		template <class ... TypeInstr>
		Function(Module* _pModule, const char* _pName, const Flag<spv::FunctionControlMask> _control, Instruction* _pReturnType, TypeInstr* ... _paramTypeInstructions);

		virtual ~Function();

		// OpFunction 
		Instruction* getFunction() { return &m_Function; }
		const Instruction* getFunction() const { return &m_Function; }
		Instruction* getReturnType() const { return m_pReturnType; }
		Instruction* getFunctionType() const { return m_pFunctionType; }
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

	private:
		template <class ... TypeInstr>
		void addParameters(Instruction* _pParamType, TypeInstr* ... _paramTypeInstructions);

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
		m_pFunctionType = m_pModule->compositeType(spv::Op::OpTypeFunction, _pReturnType);

		if constexpr (sizeof...(_paramTypeInstructions) > 0)
		{
			addParameters(_paramTypeInstructions...);		
		}

		Instruction* pFunc = m_Function.opFunction(_control, _pReturnType, m_pFunctionType);
		m_pModule->addName(pFunc, _pName);
	}

	template<class ... TypeInstr>
	inline void Function::addParameters(Instruction* _pParamType, TypeInstr* ..._paramTypeInstructions)
	{
		m_Parameters.emplace_back(this).opFunctionParameter(_pParamType);
		m_pFunctionType->addOperand(_pParamType);

		if constexpr (sizeof...(_paramTypeInstructions) > 0)
		{
			addParameters(_paramTypeInstructions...);
		}
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