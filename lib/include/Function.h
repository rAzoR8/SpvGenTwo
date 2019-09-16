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
		const Instruction* getFunction() const { return &m_Function; }

		BasicBlock& addBasicBlock() { return emplace_back(this); }

		Module* getModule() { return m_pModule; }
		const Module* getModule() const { return m_pModule; }

		void write(IWriter* _pWriter) const;

		// calls finalize internally (all-in-one function)
		template <class ... Types>
		void finalizeSignature(const Flag<spv::FunctionControlMask> _control, const Type& _returnType, Types&& ... _args);

		const List<Instruction>& getParameters() const { return m_Parameters; }

		// returns the OpTypeFunction, finalize needs to be called
		Type& createSignature();

		bool finalize(const Flag<spv::FunctionControlMask> _control = spv::FunctionControlMask::MaskNone);

		template <class ... Types>
		void addParameters(const Type& _type, const Types& ... _args);

	private:
		Module* m_pModule = nullptr; // parent

		Instruction m_Function; // OpFunction
		const Instruction* m_pFunctionType = nullptr;
		Type m_Type; // OpFunctionType

		List<Instruction> m_Parameters; // OpFunctionParameters
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

} // !spvgentwo