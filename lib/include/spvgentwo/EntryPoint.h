#pragma once

#include "Function.h"
#include "String.h"

namespace spvgentwo
{
	class EntryPoint : public Function
	{
		friend class Module;
	public:
		EntryPoint();

		// empty function, call setReturnType() first, then use addParameters() and then finalize() to create the function
		EntryPoint(Module* _pModule);

		// creates the whole function signature, finalize() does NOT need to be called
		template <class ... TypeInstr>
		EntryPoint(Module* _pModule, const spv::ExecutionModel _model, const char* _pEntryPointName, const Flag<spv::FunctionControlMask> _control, Instruction* _pReturnType, TypeInstr* ... _paramTypeInstructions);
		
		~EntryPoint() override;

		const char* getName() const;

		// TODO: move constructor & asignment

		spv::ExecutionModel getExecutionModel() const { return m_ExecutionModel; }
		void setExecutionModel(const spv::ExecutionModel _model) { m_ExecutionModel = _model; }

		// OpEntryPoint
		Instruction* getEntryPoint() { return &m_EntryPoint; }
		const Instruction* getEntryPoint() const { return &m_EntryPoint; }

		template <class ... Args>
		Instruction* addExecutionMode(const spv::ExecutionMode _mode, Args ... _args);

		// overrides Functions finalize (used internally), _pEntryPointName is mandatory parameter, returns opFunction
		Instruction* finalize(const spv::ExecutionModel _model, const Flag<spv::FunctionControlMask> _control, const char* _pEntryPointName);

		// get Variable interface (instructions) operands of OpEntryPoint
		Range<Instruction::Iterator> getInterfaceVariables() const;

	private:
		// only to be called by the Module before serialization
		void finalizeGlobalInterface(const GlobalInterfaceVersion _version);

		String& getNameStorage();

	private:
		Instruction m_EntryPoint; // OpEntryPoint
		spv::ExecutionModel m_ExecutionModel = spv::ExecutionModel::Max;
		String m_nameStorage; // literal string of EP name that was encoded in OpEntryPoint
	};
} // !spvgentwo