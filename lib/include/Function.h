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
		Function(IAllocator* _pAllocator);
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

		const List<Instruction>& getParameters() const { return m_Parameters; }

		bool finalize(Instruction* _pReturnType, const Flag<spv::FunctionControlMask> _control = spv::FunctionControlMask::MaskNone);

		void promoteToEntryPoint(const spv::ExecutionModel _model, const char* _pEntryPointName);
		bool isEntryPoint() const { return m_ExecutionModel != spv::ExecutionModel::Max && m_pEntryPointName != nullptr; }

		spv::ExecutionModel getExecutionModel() const { return m_ExecutionModel;}
		const char* getEntryPointName() const { return m_pEntryPointName; }

		// get all the global OpVariables with StorageClass != Function used in this function
		List<Instruction*> getGlobalVariableInterface() const; // TODO: make private?

		template <class ... Args>
		Instruction* addExecutionMode(const spv::ExecutionMode _mode, Args ... _args);
		const List<Instruction>& getExecutionModes() const { return m_ExecutionModes; }

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
		Instruction* pInstr = &m_ExecutionModes.emplace_back(m_pAllocator);

		pInstr->makeOp(getExecutionModeOp(_mode), &m_Function, _mode, _args...);

		return pInstr;
	}

} // !spvgentwo