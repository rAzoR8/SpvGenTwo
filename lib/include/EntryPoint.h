#pragma once

#include "Function.h"

namespace spvgentwo
{
	class EntryPoint : public Function
	{
	public:
		EntryPoint(Module* _pModule, const spv::ExecutionModel _model, const char* _pEntryPointName);
		~EntryPoint() override;

		// get all the global OpVariables with StorageClass != Function used in this function
		void getGlobalVariableInterface(List<Operand>& _outVarinstr) const;

		spv::ExecutionModel getExecutionModel() const { return m_ExecutionModel; }
		const char* getEntryPointName() const { return m_pEntryPointName; }

		// OpEntryPoint
		Instruction* getEntryPoint() { return &m_EntryPoint; }

		template <class ... Args>
		Instruction* addExecutionMode(const spv::ExecutionMode _mode, Args ... _args);
		const List<Instruction>& getExecutionModes() const { return m_ExecutionModes; }

		// only to be called by the Module before serialization
		bool finalizeEP(Instruction* _pReturnType, const Flag<spv::FunctionControlMask> _control = spv::FunctionControlMask::MaskNone);

	private:
		// entry point
		Instruction m_EntryPoint; // OpEntryPoint
		List<Instruction> m_ExecutionModes;
		spv::ExecutionModel m_ExecutionModel = spv::ExecutionModel::Max;
		const char* m_pEntryPointName = nullptr;
		bool m_finalized = false;
	};

	template<class ...Args>
	inline Instruction* EntryPoint::addExecutionMode(const spv::ExecutionMode _mode, Args ..._args)
	{
		Instruction* pInstr = &m_ExecutionModes.emplace_back(this);

		pInstr->makeOpEx(getExecutionModeOp(_mode), &m_Function, _mode, _args...);

		return pInstr;
	}
} // !spvgentwo