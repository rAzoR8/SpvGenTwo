#pragma once

#include "List.h"
#include "Operand.h"
#include "Flag.h"

namespace spvgentwo
{
	// forward delcs
	class Type;

	class Instruction : public List<Operand>
	{
	public:
		using Iterator = EntryIterator<Operand>;

		template <class ...Args>
		Instruction(IAllocator* _pAllocator, const spv::Op _op = spv::Op::OpNop, Args&& ... _args);
		template <class ...Args>
		Instruction(BasicBlock* _pBasicBlock, const spv::Op _op = spv::Op::OpNop, Args&& ... _args);

		~Instruction();

		BasicBlock* getBasicBlock() { return m_pBasicBlock; }
		const BasicBlock* getBasicBlock() const { return m_pBasicBlock; }

		// manual instruction construction:
		void setOperation(const spv::Op _op) { m_Operation = _op; };
		spv::Op getOperation() const { return m_Operation; }
		template<class ...Args>
		Operand& addOperand(Args&& ... _operand) { return emplace_back(stdrep::forward<Args>(_operand)...); }

		spv::Id getResultId() const;
		void setResultId(const spv::Id _resultId); // todo: make private
		const Instruction* getType() const;
	
		bool isTypeOp() const;

		void reset();

		// get number of 32 bit words used by this instruction
		unsigned int getWordCount() const;
		unsigned int getOpCode() const;

		void write(IWriter* _pWriter) const;

		// creates literals
		template <class T, class ...Args>
		Instruction* makeOp(T first, Args ... _args);

		template <class ...Args>
		void appendLiterals(Args ... _args);

		// instruction generators:
		// all instructions generating a result id return a pointer to this instruction for reference (passing to other instruction operand)
		void opCapability(const spv::Capability _capability);

		void opMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel);

		void opExtension(const char* _pExtName);

		Instruction* opExtInstrImport(const char* _pExtName);

		Instruction* opLabel();

		Instruction* opFunction(const Flag<spv::FunctionControlMask> _functionControl, const Instruction* _pResultType, const Instruction* _pFuncType);

		Instruction* opFunctionParameter(const Instruction* _pType);

		void opFunctionEnd();

		//  _pFunction is result of opFunction
		template <class ... Instr>
		void opEntryPoint(const spv::ExecutionModel _model, const Instruction* _pFunction, const char* _pName, Instr ... _instr);

		Instruction* opIAdd(const Instruction* _pResultType, const Instruction* _pLeft, const Instruction* _pRight);

	private:
		spv::Op m_Operation = spv::Op::OpNop;
		BasicBlock* m_pBasicBlock = nullptr; // parent
	};

	// free helper function
	void writeInstructions(IWriter* _pWriter, const List<Instruction>& _instructions);

	template<class ...Args>
	inline Instruction::Instruction(IAllocator* _pAllocator, const spv::Op _op, Args&& ..._args) :
		m_pBasicBlock(nullptr), List(_pAllocator)
	{
		makeOp(_op, stdrep::forward<Args>(_args)...);
	}

	template<class ...Args>
	inline Instruction::Instruction(BasicBlock* _pBasicBlock, const spv::Op _op, Args&& ..._args) :
		m_pBasicBlock(_pBasicBlock), List(_pBasicBlock->getAllocator())
	{
		makeOp(_op, stdrep::forward<Args>(_args)...);
	}
	
	template<class T, class ...Args>
	inline Instruction* Instruction::makeOp(T _first, Args ..._args)
	{
		if constexpr (is_same_base_type_v<T, spv::Op>)
		{
			m_Operation = _first;
		} 
		else if constexpr (is_same_base_type_v<T, Instruction*>)
		{
			addOperand(_first);
		}
		else if constexpr(is_same_base_type_v<T, BasicBlock*>)
		{
			addOperand(_first);
		}
		else if constexpr (sizeof(T) == sizeof(literal_t)) // bitcast to 32 bit literal
		{
			addOperand(*reinterpret_cast<const literal_t*>(&_first));
		}
		else
		{
			appendLiterals(_first);
		}

		if constexpr (sizeof...(_args) > 0u)
		{
			makeOp(_args...);
		}

		return this;
	}

	template<class ...Args>
	inline void Instruction::appendLiterals(Args ..._args)
	{
		appendLiteralsToContainer(*this, _args...);
	}

	template<class ...Instr>
	inline void Instruction::opEntryPoint(const spv::ExecutionModel _model, const Instruction* _pFunction, const char* _pName, Instr ..._instr)
	{
		makeOp(_model, _pFunction, _pName, _instr...);
	}
} // !spvgentwo