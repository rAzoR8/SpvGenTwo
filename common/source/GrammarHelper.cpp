#include "common/GrammarHelper.h"

namespace
{
	bool stringCmp(const char* _pLeft, const char* _pRight)
	{
		if (_pLeft == nullptr || _pRight == nullptr)
		{
			return false;
		}

		while (*_pLeft != '\0' && *_pRight != '\0')
		{
			if (*_pLeft != *_pRight)
			{
				return false;
			}

			++_pLeft;
			++_pRight;
		}

		return true;
	}
}

spvgentwo::Instruction::Iterator spvgentwo::GrammarHelper::getFirstOperandOfKind(const Instruction* _pInstruction, const Grammar& _gram, Grammar::OperandKind _kind, Grammar::Extension _ext)
{
	if (auto* info = _gram.getInfo(static_cast<unsigned int>(_pInstruction->getOperation()), _ext); info != nullptr)
	{
		auto opIt = info->operands.begin();

		for (auto it = _pInstruction->begin(); it != nullptr && opIt != nullptr; )
		{
			if (opIt->kind == _kind)
			{
				return it;
			}

			++it;
			++opIt;
		}
	}

	return nullptr;
}

spvgentwo::Instruction::Iterator spvgentwo::GrammarHelper::getOperandByName(const Instruction* _pInstruction, const Grammar& _gram, const char* _pName, Grammar::Extension _ext)
{
	if (auto* info = _gram.getInfo(static_cast<unsigned int>(_pInstruction->getOperation()), _ext); info != nullptr)
	{
		auto opIt = info->operands.begin();

		for (auto it = _pInstruction->begin(); it != nullptr && opIt != nullptr; )
		{
			if (stringCmp(_pName, opIt->name))
			{
				return it;
			}

			++it;
			++opIt;
		}
	}

	return nullptr;
}
