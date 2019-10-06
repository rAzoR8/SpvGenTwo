#include "BasicBlock.h"
#include "Function.h"
#include "Module.h"

spvgentwo::BasicBlock::BasicBlock(IAllocator* _pAllocator) :
	m_pFunction(nullptr), List(_pAllocator)
{
	addInstruction()->opLabel();
}

spvgentwo::BasicBlock::BasicBlock(Function* _pFunction) :
	m_pFunction(_pFunction), List(_pFunction->getAllocator())
{
	addInstruction()->opLabel();
}

spvgentwo::BasicBlock::~BasicBlock()
{
}

spvgentwo::Module* spvgentwo::BasicBlock::getModule()
{
	return m_pFunction->getModule();
}

const spvgentwo::Module* spvgentwo::BasicBlock::getModule() const
{
	return m_pFunction->getModule();
}

spvgentwo::IAllocator* spvgentwo::BasicBlock::getAllocator()
{
	return getModule()->getAllocator();;
}

spvgentwo::BasicBlock::Iterator spvgentwo::BasicBlock::getTerminator()
{
	if (m_pLast != nullptr && (*m_pLast)->isTerminator())
	{
		return Iterator(m_pLast);
	}

	return Iterator(nullptr);
}

spvgentwo::Instruction* spvgentwo::BasicBlock::returnValue(Instruction* _pValue)
{
	Instruction* pRet = addInstruction();

	if (_pValue == nullptr)
	{
		pRet->opReturn();
	}
	else
	{
		// TODO: check return type with m_FunctionType
		pRet->opReturnValue(_pValue);
	}

	return pRet;
}

void spvgentwo::BasicBlock::write(IWriter* _pWriter, spv::Id& _resultId)
{
	for (Instruction& instr : *this)
	{
		instr.write(_pWriter, _resultId);
	}
}

spvgentwo::Instruction* spvgentwo::BasicBlock::If(Instruction* _pCondition, BasicBlock& _trueBlock, BasicBlock& _falseBlock, BasicBlock& _mergeBlock, const spv::SelectionControlMask _mask)
{
	// this block has not been terminated yet
	//if (getTerminator() == nullptr)
	{
		addInstruction()->opSelectionMergeEx(&_mergeBlock, _mask);
		addInstruction()->opBranchConditionalEx(_pCondition, &_trueBlock, &_falseBlock);
		_trueBlock->opBranchEx(&_mergeBlock);
		_falseBlock->opBranchEx(&_mergeBlock);
	}

	for (auto it = _mergeBlock.last(); it != _mergeBlock.begin(); --it)
	{
		if (it->isTerminator() == false && it->hasResult()) // hasResultAndType
		{
			return it.operator->();
		}
	}

	return nullptr;
}