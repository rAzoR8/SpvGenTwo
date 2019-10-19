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
		virtual ~Function();

		// OpFunction 
		Instruction* getFunction() { return &m_Function; }

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

		//void promoteToEntryPoint(const spv::ExecutionModel _model, const char* _pEntryPointName);
		//bool isEntryPoint() const { return m_ExecutionModel != spv::ExecutionModel::Max && m_pEntryPointName != nullptr; }

	private:
		Module* m_pModule = nullptr; // parent

		Instruction m_Function; // OpFunction
		Instruction* m_pFunctionType = nullptr;

		List<Instruction> m_Parameters; // OpFunctionParameters
	};



} // !spvgentwo