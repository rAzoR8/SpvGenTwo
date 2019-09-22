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

		BasicBlock& addBasicBlock() { return emplace_back(this); }

		Module* getModule() { return m_pModule; }
		const Module* getModule() const { return m_pModule; }

		void write(IWriter* _pWriter, spv::Id& _resultId);

		// calls finalize internally (all-in-one function)
		template <class ... Types>
		void finalizeSignature(const Flag<spv::FunctionControlMask> _control, const Type& _returnType, Types&& ... _args);

		const List<Instruction>& getParameters() const { return m_Parameters; }

		// returns the OpTypeFunction, finalize needs to be called
		Type& createSignature();

		bool finalize(const Flag<spv::FunctionControlMask> _control = spv::FunctionControlMask::MaskNone);

		template <class ... Types>
		void addParameters(const Type& _type, const Types& ... _args);

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
		Type m_Type; // OpFunctionType

		List<Instruction> m_Parameters; // OpFunctionParameters

		// entry point
		Instruction m_EntryPoint; // OpEntryPoint
		List<Instruction> m_ExecutionModes;
		spv::ExecutionModel m_ExecutionModel = spv::ExecutionModel::Max;
		const char* m_pEntryPointName = nullptr;
	};

	template<class ...Types>
	inline void Function::finalizeSignature(const Flag<spv::FunctionControlMask> _control, const Type& _returnType, Types&& ... _args)
	{
		addParameters(_returnType, _args...);

		finalize(_control);
	}

	template<class ...Types>
	inline void Function::addParameters(const Type& _type, const Types& ..._args)
	{
		m_Type.getSubTypes().emplace_back(_type);

		if constexpr (sizeof...(_args) > 0)
		{
			addParameters(_args...);
		}
	}

	template<class ...Args>
	inline Instruction* Function::addExecutionMode(const spv::ExecutionMode _mode, Args ..._args)
	{
		Instruction* pInstr = &m_ExecutionModes.emplace_back(m_pAllocator);

		pInstr->makeOp(getExecutionModeOp(_mode), &m_Function, _mode, _args...);

		return pInstr;
	}

} // !spvgentwo