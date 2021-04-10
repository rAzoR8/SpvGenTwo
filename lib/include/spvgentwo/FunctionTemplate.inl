#pragma once

namespace spvgentwo
{
	template<class ...TypeInstr>
	inline Function::Function(Module* _pModule, const char* _pName, const Flag<spv::FunctionControlMask> _control, Instruction* _pReturnType, TypeInstr* ..._paramTypeInstructions) :
		Function(_pModule)
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
		if (const Type* type = _pParamType->getType(); type != nullptr)
		{
			if (type->isVoid())
			{
				m_pModule->logError("_pParamType cannot be OpTypeVoid");
				return nullptr;
			}
			m_FunctionType.getSubTypes().emplace_back(*type);
		}
		
		[[maybe_unused]] Instruction* param = m_Parameters.emplace_back(this).opFunctionParameter(_pParamType);
		
		if constexpr (sizeof...(_paramTypeInstructions) > 0)
		{
			return addParameters(_paramTypeInstructions...);
		}
		else
		{
			return param;		
		}
	}

	template<class T>
	inline Instruction* Function::variable(const char* _pName, Instruction* _pInitialzer)
	{
		return variable(getModule()->template type<T*>(spv::StorageClass::Function), _pName, _pInitialzer);
	}

	template<class T>
	inline Instruction* Function::variable(const T& _initialValue, const char* _pName)
	{
		return variable(getModule()->template type<T*>(spv::StorageClass::Function, _initialValue), _pName, getModule()->constant(_initialValue));
	}
} // !spvgentwo