#include "common/ReflectionHelper.h"
#include "common/ReflectionHelperTemplate.inl"

#include "spvgentwo/Module.h"

bool spvgentwo::ReflectionHelper::getLocalSize(const Module& _module, unsigned int& _x, unsigned int& _y, unsigned int& _z)
{
	for (const auto& mode : _module.getExecutionModes()) 
	{
		if (auto it = mode.begin().next(); it != nullptr && mode.size() > 4u)
		{
			if (mode == spv::Op::OpExecutionMode && (*it == spv::ExecutionMode::LocalSize || *it == spv::ExecutionMode::LocalSizeHint))
			{
				_x = (++it)->getLiteral();
				_y = (++it)->getLiteral();
				_z = (++it)->getLiteral();

				return true;
			}
			else if (mode == spv::Op::OpExecutionModeId && (*it == spv::ExecutionMode::LocalSizeId || *it == spv::ExecutionMode::LocalSizeHintId))
			{
				auto getValue = [](const Instruction* instr) -> unsigned int
				{
					if (instr == nullptr || instr->isSpecOrConstant() == false)
						return 0u;

					if(const Constant* c = instr->getConstant(); c != nullptr && c->getData().empty() == false && c->getType().isInt())
					{
						return c->getData().front();
					}

					return 0u;
				};

				_x = getValue((++it)->getInstruction());
				_y = getValue((++it)->getInstruction());
				_z = getValue((++it)->getInstruction());

				return true;
			}
		}
	}

	return false;
}

void spvgentwo::ReflectionHelper::getGlobalVariablesByStorageClass(const Module& _module, spv::StorageClass _class, List<const Instruction*>& _outVariables)
{
	for (const Instruction& var : _module.getGlobalVariables()) 
	{
		if (var.getStorageClass() == _class)
		{
			_outVariables.emplace_back(&var);
		}
	}
}

void spvgentwo::ReflectionHelper::getVariablesWithDecoration(const Module& _module, spv::Decoration _decoration, List<const Instruction*>& _outTargets, const unsigned int* _pValue)
{
	getVariablesWithDecorationFunc(_module, _decoration, [&_outTargets](const Instruction* _pTarget) {_outTargets.emplace_back(_pTarget); }, _pValue);
}

void spvgentwo::ReflectionHelper::getDecorations(const Instruction* _pTarget, List<Instruction*>& _outDecorations)
{
	if (_pTarget == nullptr || _pTarget->getModule() == nullptr)
		return;

	for(Instruction& decoration : _pTarget->getModule()->getDecorations())
	{
		if (*decoration.getFirstActualOperand() == _pTarget) // check target
		{
			_outDecorations.emplace_back(&decoration);
		}
	}
}

spvgentwo::spv::Decoration spvgentwo::ReflectionHelper::getSpvDecorationKindFromDecoration(const Instruction* _pDecoration)
{
	if (_pDecoration == nullptr)
	{
		return spv::Decoration::Max;
	}

	auto it = _pDecoration->getFirstActualOperand().next(); // skip target ID

	if (*_pDecoration == spv::Op::OpDecorate && it != nullptr)
	{
		return static_cast<spv::Decoration>(it->getLiteral().value);
	}
	else if (*_pDecoration == spv::Op::OpMemberDecorate && it.next() != nullptr)
	{
		return static_cast<spv::Decoration>(it.next()->getLiteral().value); // skip member index
	}

	return spv::Decoration::Max;
}

bool spvgentwo::ReflectionHelper::getSpvDecorationAndLiteralFromDecoration(const Instruction* _pInDecoration, spv::Decoration& _outDecoration, unsigned int& _outValue)
{
	if (_pInDecoration == nullptr || (*_pInDecoration != spv::Op::OpDecorate && *_pInDecoration == spv::Op::OpMemberDecorate))
	{
		return false;
	}

	auto it = _pInDecoration->getFirstActualOperand().next(); // skip target ID

	if (*_pInDecoration == spv::Op::OpMemberDecorate )
	{
		++it; // skip member index
	}

	if (it != nullptr)
	{
		_outDecoration = static_cast<spv::Decoration>(it->getLiteral().value);

		if (it.next() != nullptr)
		{
			_outValue = it.next()->getLiteral();
		}

		return true;
	}

	return false;
}

unsigned int spvgentwo::ReflectionHelper::getLiteralFromDecoration(spv::Decoration _decoration, const Instruction* _pDecoration)
{
	spv::Decoration deco{};
	unsigned int value = sgt_uint32_max;

	if (getSpvDecorationAndLiteralFromDecoration(_pDecoration, deco, value) == false || deco != _decoration)
	{
		return sgt_uint32_max;	
	}

	return value;
}

unsigned int spvgentwo::ReflectionHelper::getDecorationLiteralFromTarget(spv::Decoration _decoration, const Instruction* _pTarget, const Instruction** _pOutDecoration)
{
	if (_pTarget == nullptr || _pTarget->getModule() == nullptr)
		return sgt_uint32_max;

	for (const Instruction& decoration : _pTarget->getModule()->getDecorations())
	{
		auto target = decoration.getFirstActualOperand();

		if (target != nullptr && *target == _pTarget)
		{
			if (decoration == spv::Op::OpMemberDecorate)
			{
				target = target.next(); // skip member index
			}

			if (auto deco = target.next(); deco != nullptr && deco.next() != nullptr && deco->getLiteral() == static_cast<unsigned int>(_decoration))
			{
				if (_pOutDecoration != nullptr)
				{
					*_pOutDecoration = &decoration;
				}

				return deco.next()->getLiteral();
			}
		}
	}

	return sgt_uint32_max;
}
