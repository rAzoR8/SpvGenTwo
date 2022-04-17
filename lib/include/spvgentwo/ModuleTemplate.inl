#pragma once

namespace 
{
	template<class ...TypeInstr>
	inline void compositeTypeHelper(spvgentwo::Type& _compositeType, spvgentwo::Instruction* _pSubType, TypeInstr* ..._types)
	{
		if (const spvgentwo::Type* info = _pSubType->getType(); info != nullptr)
		{
			_compositeType.getSubTypes().emplace_back(*info);
		}
		else
		{
			_pSubType->getModule()->logError("Type info not found for _pSubType");
			return;
		}

		if constexpr (sizeof...(_types) > 0u)
		{
			compositeTypeHelper(_compositeType, _types...);
		};
	}
}

namespace spvgentwo
{
	template<class Func>
	inline bool Module::iterateInstructions(Func _func)
	{
		return iterateModuleInstructions(*this, _func);
	}

	template<class Func>
	inline bool Module::iterateInstructions(Func _func) const
	{
		return iterateModuleInstructions(*this, _func);
	}

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
	inline Function& Module::addFunction(const char* _pFunctionName, Flag<spv::FunctionControlMask> _control, bool _addEntryBasicBlock)
	{
		Function& func = m_Functions.emplace_back(this, _pFunctionName, _control, type<ReturnType>(), type<ParameterTypes>()...);

		if (_addEntryBasicBlock)
		{
			func.addBasicBlock("FunctionEntry");		
		}

		return func;
	}

	template<class ReturnType, class ...ParameterTypes>
	inline EntryPoint& Module::addEntryPoint(spv::ExecutionModel _model, const char* _pEntryPointName, Flag<spv::FunctionControlMask> _control, bool _addEntryBasicBlock)
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
		const char* const* name = traits::selectTypeFromArgs<const char*>(_props...);
		return addType(dummy.make<T>(_props...), name != nullptr ? *name : nullptr);
	}

	template<class T>
	inline Instruction* Module::constant(const T& _value, bool _spec, const char* _pName)
	{
		Constant dummy(m_pAllocator);
		return addConstant(dummy.make<T>(_value, _spec), _pName);
	}

	template<class ...TypeInstr>
	inline Instruction* Module::compositeType(const spv::Op _Type, TypeInstr* ..._types)
	{
		Type t(m_pAllocator);
		t.setType(_Type);

		if constexpr (sizeof...(_types) > 0u)
		{
			compositeTypeHelper(t, _types...);
		}
	
		return addType(t);
	}

	template<class T, class ... Props>
	inline Type Module::newType(const Props& ... _props) const
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

	// returns TRUE if Func has bool return value and returned true (to exit loop)
	template<class Func, class Container>
	inline bool iterateInstructionContainer(Func _func, Container& _container)
	{
		static_assert(traits::is_invocable_v<Func, Instruction&>, "Func _func is not invocable: _func(Instruction& _instr)");
		using Ret = decltype(stdrep::declval<Func>()(stdrep::declval<Instruction&>()));

		for (auto& instr : _container)
		{
			if constexpr (stdrep::is_same_v<Ret, bool>)
			{
				if (_func(traits::to_ref(instr)))
					return true;
			}
			else
			{
				_func(traits::to_ref(instr));
			}
		}

		return false;
	}

	// if func returns a bool, TRUE indecates to abort iterating
	// iterateModuleInstructions returns TRUE if not all instructions were enumarated because _func returned TRUE
	template<class ModuleT, class Func>
	inline bool iterateModuleInstructions(ModuleT& _module, Func _func)
	{
		static_assert(traits::is_invocable_v<Func, Instruction&>, "Func _func is not invocable: _func(Instruction& _instr)");
		using Ret = decltype(stdrep::declval<Func>()(stdrep::declval<Instruction&>()));

		auto pred = [&_func](auto& instr) -> bool
		{
			if constexpr (stdrep::is_same_v<Ret, bool>)
			{
				return _func(instr);
			}
			else
			{
				_func(instr);
				return false;
			}
		};

		for (auto& [key, instr] : _module.getCapabilities())
		{
			if (pred(instr)) return true;
		}

		for (auto& [key, instr] : _module.getExtensions())
		{
			if (pred(instr)) return true;
		}

		for (auto& [key, instr] : _module.getExtInstrImports())
		{
			if (pred(instr)) return true;
		}

		if (pred(_module.getMemoryModel())) return true;

		for (auto& ep : _module.getEntryPoints())
		{
			if (pred(*ep.getEntryPoint())) return true;
		}

		if (iterateInstructionContainer(_func, _module.getExecutionModes())) return true;
		if (iterateInstructionContainer(_func, _module.getSourceStrings())) return true;
		if (iterateInstructionContainer(_func, _module.getNames())) return true;
		if (iterateInstructionContainer(_func, _module.getModulesProcessed())) return true;
		if (iterateInstructionContainer(_func, _module.getDecorations())) return true;
		if (iterateInstructionContainer(_func, _module.getTypesAndConstants())) return true;
		if (iterateInstructionContainer(_func, _module.getGlobalVariables())) return true;
		if (iterateInstructionContainer(_func, _module.getUndefs())) return true;
		if (iterateInstructionContainer(_func, _module.getLines())) return true;

		auto iterateFuncion = [&_module, &pred, &_func](auto& f) -> bool
		{
			if (pred(*f.getFunction())) return true;
			if (iterateInstructionContainer(_func, f.getParameters())) return true;
			for (auto& bb : f)
			{
				if (pred(*bb.getLabel())) return true;
				if (iterateInstructionContainer(_func, bb)) return true;
				if (bb.getTerminator() == nullptr)
				{
					_module.logError("BasicBlock %s has no terminator instruction, missing opReturn?", bb.getName());
					return true;
				}
			}
			if (pred(*f.getFunctionEnd())) return true;
			return false;
		};

		for (auto& fun : _module.getFunctions())
		{
			if (fun.empty())
			{
				if (iterateFuncion(fun)) return true;
			}
		}

		// write functions with bodies
		for (auto& fun : _module.getFunctions())
		{
			if (fun.empty() == false)
			{
				if (iterateFuncion(fun)) return true;
			}
		}
		for (auto& ep : _module.getEntryPoints())
		{
			if (ep.empty() == false) // can entry points be empty forward decls?
			{
				if (iterateFuncion(ep)) return true;
			}
		}

		return false;
	}
} // !spvgentwo