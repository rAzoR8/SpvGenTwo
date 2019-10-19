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
		Function(Module* _pModule);
		~Function();

		// OpFunction 
		Instruction* getFunction() { return &m_Function; }

		// OpEntryPoint
		Instruction* getEntryPoint() { return &m_EntryPoint; }

		// only valid after finalization
		Instruction* getReturnType();

		BasicBlock& addBasicBlock() { return emplace_back(this); }

		Module* getModule() { return m_pModule; }
		const Module* getModule() const { return m_pModule; }

		void write(IWriter* _pWriter, spv::Id& _resultId);

		// return OpFunctionParameter
		Instruction* addParameter(Instruction* _pType);

		template<class T>
		Instruction* addParameter() { return addParameter(m_pModule->type<T>()); }

		const List<Instruction>& getParameters() const { return m_Parameters; }

		bool finalize(Instruction* _pReturnType, const Flag<spv::FunctionControlMask> _control = spv::FunctionControlMask::MaskNone);

		template <class ResultType = void>
		bool finalize(const Flag<spv::FunctionControlMask> _control = spv::FunctionControlMask::MaskNone) { return finalize(m_pModule->type<ResultType>(), _control); }

		void promoteToEntryPoint(const spv::ExecutionModel _model, const char* _pEntryPointName);
		bool isEntryPoint() const { return m_ExecutionModel != spv::ExecutionModel::Max && m_pEntryPointName != nullptr; }

		spv::ExecutionModel getExecutionModel() const { return m_ExecutionModel;}
		const char* getEntryPointName() const { return m_pEntryPointName; }

		template <class ... Args>
		Instruction* addExecutionMode(const spv::ExecutionMode _mode, Args ... _args);
		const List<Instruction>& getExecutionModes() const { return m_ExecutionModes; }

	private:
		// get all the global OpVariables with StorageClass != Function used in this function
		void getGlobalVariableInterface(List<Operand>& _outVarinstr) const;

	private:
		Module* m_pModule = nullptr; // parent

		Instruction m_Function; // OpFunction
		Instruction* m_pFunctionType = nullptr;

		List<Instruction> m_Parameters; // OpFunctionParameters

		// entry point
		Instruction m_EntryPoint; // OpEntryPoint
		List<Instruction> m_ExecutionModes;
		spv::ExecutionModel m_ExecutionModel = spv::ExecutionModel::Max;
		const char* m_pEntryPointName = nullptr;
	};

	template<class ...Args>
	inline Instruction* Function::addExecutionMode(const spv::ExecutionMode _mode, Args ..._args)
	{
		Instruction* pInstr = &m_ExecutionModes.emplace_back(this);

		pInstr->makeOpEx(getExecutionModeOp(_mode), &m_Function, _mode, _args...);

		return pInstr;
	}

} // !spvgentwo