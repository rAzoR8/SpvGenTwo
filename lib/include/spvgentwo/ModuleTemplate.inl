#pragma once

namespace spvgentwo
{
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
} // !spvgentwo