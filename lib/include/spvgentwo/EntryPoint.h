#pragma once

#include "Function.h"

namespace spvgentwo
{
	enum class GlobalInterfaceVersion
	{
		SpirV1_3, // 1.0 - 1.3 Input and Output StorageClass
		SpirV14_x // 1.4 - 1.x any StorageClass != Function
	};

	class EntryPoint : public Function
	{
		friend class Module;
	public:
		// empty function, call setReturnType() first, then use addParameters() and then finalize() to create the function
		EntryPoint(Module* _pModule);

		// creates the whole function signature, finalize() does NOT need to be called
		template <class ... TypeInstr>
		EntryPoint(Module* _pModule, const spv::ExecutionModel _model, const char* _pEntryPointName, const Flag<spv::FunctionControlMask> _control, Instruction* _pReturnType, TypeInstr* ... _paramTypeInstructions);
		
		~EntryPoint() override;

		// get all the global OpVariables with StorageClass != Function used in this function
		void getGlobalVariableInterface(List<Operand>& _outVarinstr, const GlobalInterfaceVersion _version) const;

		spv::ExecutionModel getExecutionModel() const { return m_ExecutionModel; }
		const char* getEntryPointName() const { return m_pEntryPointName; }

		// OpEntryPoint
		Instruction* getEntryPoint() { return &m_EntryPoint; }
		const Instruction* getEntryPoint() const { return &m_EntryPoint; }

		template <class ... Args>
		Instruction* addExecutionMode(const spv::ExecutionMode _mode, Args ... _args);
		const List<Instruction>& getExecutionModes() const { return m_ExecutionModes; }

		// overrides Functions finalize (used internally), _pEntryPointName is mandatory parameter, returns opFunction
		Instruction* finalize(const spv::ExecutionModel _model, const Flag<spv::FunctionControlMask> _control, const char* _pEntryPointName);

	private:
		// only to be called by the Module before serialization
		void finalizeGlobalInterface(const GlobalInterfaceVersion _version);

	private:
		Instruction m_EntryPoint; // OpEntryPoint
		List<Instruction> m_ExecutionModes;
		spv::ExecutionModel m_ExecutionModel = spv::ExecutionModel::Max;
		const char* m_pEntryPointName = nullptr;
		bool m_finalized = false;
	};

	template<class ...TypeInstr>
	inline EntryPoint::EntryPoint(Module* _pModule, const spv::ExecutionModel _model, const char* _pEntryPointName, const Flag<spv::FunctionControlMask> _control, Instruction* _pReturnType, TypeInstr* ..._paramTypeInstructions) :
		Function(_pModule, _pEntryPointName, _control, _pReturnType, _paramTypeInstructions...),
		m_EntryPoint(this),
		m_ExecutionModes(_pModule->getAllocator()),
		m_ExecutionModel(_model),
		m_pEntryPointName(_pEntryPointName)
	{
		m_EntryPoint.opEntryPoint(_model, &m_Function, m_pEntryPointName);
	}

	template<class ...Args>
	inline Instruction* EntryPoint::addExecutionMode(const spv::ExecutionMode _mode, Args ..._args)
	{
		Instruction* pInstr = &m_ExecutionModes.emplace_back(this);

		pInstr->makeOpEx(getExecutionModeOp(_mode), &m_Function, _mode, _args...);

		return pInstr;
	}
} // !spvgentwo