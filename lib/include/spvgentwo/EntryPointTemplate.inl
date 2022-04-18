#pragma once

namespace spvgentwo
{
	template<class ...TypeInstr>
	inline EntryPoint::EntryPoint(Module* _pModule, const spv::ExecutionModel _model, const char* _pEntryPointName, const Flag<spv::FunctionControlMask> _control, Instruction* _pReturnType, TypeInstr* ..._paramTypeInstructions) :
		Function(_pModule, _pEntryPointName, _control, _pReturnType, _paramTypeInstructions...),
		m_EntryPoint(this, spv::Op::OpNop),
		m_ExecutionModel(_model)
	{
		m_isEntryPoint = true;
		m_EntryPoint.opEntryPoint(_model, &m_Function, _pEntryPointName);
	}

	template<class ...Args>
	inline Instruction* EntryPoint::addExecutionMode(const spv::ExecutionMode _mode, Args ..._args)
	{
		Instruction* pInstr = getModule()->addExtensionModeInstr();

		if (getExecutionModeOp(_mode) == spv::Op::OpExecutionModeId)
		{
			if constexpr (sizeof...(_args) > 0 && stdrep::conjunction_v<stdrep::is_same<Instruction*, Args>...>)
			{
				pInstr->opExecutionModeId(&m_Function, _mode, _args...);			
			}
			else if constexpr (sizeof...(_args) == 0)
			{
				pInstr->opExecutionModeId(&m_Function, _mode);
			}
		}
		else
		{
			if constexpr (sizeof...(_args) > 0 && false == stdrep::conjunction_v<stdrep::is_same<Instruction*, Args>...>)
			{
				pInstr->opExecutionMode(&m_Function, _mode, _args...);
			}
			else if constexpr (sizeof...(_args) == 0)
			{
				pInstr->opExecutionMode(&m_Function, _mode);
			}
		}

		return pInstr;
	}
} // !spvgentwo