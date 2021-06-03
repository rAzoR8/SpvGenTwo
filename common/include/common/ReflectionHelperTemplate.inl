#pragma once

#include "spvgentwo/Module.h"
#include "ReflectionHelper.h"

// get call func with instructions which have been decorated with _decoration & _value
template <class Func>
void spvgentwo::ReflectionHelper::getVariablesWithDecorationFunc(const Module& _module, spv::Decoration _decoration, Func _func, const unsigned int* _pValue)
{
	for (const Instruction& deco : _module.getDecorations())
	{
		auto target = deco.getFirstActualOperand();

		auto it = target.next(); // skip target ID

		bool match = false;
		if (deco == spv::Op::OpDecorate && it != nullptr && static_cast<spv::Decoration>(it->getLiteral().value) == _decoration)
		{
			match = true;
		}
		else if (deco == spv::Op::OpMemberDecorate && it.next() != nullptr && static_cast<spv::Decoration>(it.next()->getLiteral().value) == _decoration)
		{
			match = true;
			++it;
		}

		if (match && it.next() != nullptr)
		{
			if (_pValue != nullptr)
			{
				if (*_pValue == it.next()->getLiteral())
				{
					_func(target->getInstruction());
				}
			}
			else
			{
				_func(target->getInstruction());
			}
		}
	}
}

template<class Func>
void spvgentwo::ReflectionHelper::getDecorationsFunc(const Instruction* _pTarget, Func _func)
{
	if (_pTarget == nullptr || _pTarget->getModule() == nullptr)
		return;

	for (Instruction& decoration : _pTarget->getModule()->getDecorations())
	{
		if (*decoration.getFirstActualOperand() == _pTarget) // check target
		{
			_func(&decoration);
		}
	}
}

template<class Func>
void spvgentwo::ReflectionHelper::getNamesFunc(const Instruction* _pTarget, Func _func)
{
	if (_pTarget == nullptr || _pTarget->getModule() == nullptr)
		return;

	for (Instruction& name : _pTarget->getModule()->getNames())
	{
		if (*name.getFirstActualOperand() == _pTarget) // check target
		{
			_func(&name);
		}
	}
}
