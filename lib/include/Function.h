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
		Function(Module* _pModule, const Flag<spv::FunctionControlMask> _control, Instruction* _pReturnType, TypeInstr* ... _paramTypeInstructions);

		virtual ~Function();

		// OpFunction 
		Instruction* getFunction() { return &m_Function; }
		Instruction* getReturnType() { return m_pReturnType; }
		Instruction* getFunctionType() { return m_pFunctionType; }

		Module* getModule() { return m_pModule; }
		const Module* getModule() const { return m_pModule; }

		BasicBlock& addBasicBlock() { return emplace_back(this); }

		Instruction* getParameter(unsigned int _index);

		void write(IWriter* _pWriter, spv::Id& _resultId);		

		const List<Instruction>& getParameters() const { return m_Parameters; }

	private:
		template <class ... TypeInstr>
		void addParameters(Instruction* _pParamType, TypeInstr* ... _paramTypeInstructions);

	private:
		Module* m_pModule = nullptr; // parent
		Instruction* m_pReturnType = nullptr;

		Instruction m_Function; // OpFunction
		Instruction* m_pFunctionType = nullptr;

		List<Instruction> m_Parameters; // OpFunctionParameters
	};

	template<class ...TypeInstr>
	inline Function::Function(Module* _pModule, const Flag<spv::FunctionControlMask> _control, Instruction* _pReturnType, TypeInstr* ..._paramTypeInstructions) :
		List(_pModule->getAllocator()), 
		m_pModule(_pModule),
		m_pReturnType(_pReturnType),
		m_Function(this),
		m_Parameters(_pModule->getAllocator())
	{
		// function signature type
		m_pFunctionType = m_pModule->compositeType(spv::Op::OpTypeFunction, _pReturnType);

		if constexpr (sizeof...(_paramTypeInstructions) > 0)
		{
			addParameters(_paramTypeInstructions...);		
		}

		m_Function.opFunction(_control, _pReturnType, m_pFunctionType);
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

} // !spvgentwo