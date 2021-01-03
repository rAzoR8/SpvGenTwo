#include "common/ReflectionHelper.h"

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

					if(const Constant* c = instr->getConstant(); c != nullptr && c->getData().empty() == false)
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

void spvgentwo::ReflectionHelper::getVariablesByStorageClass(const Module& _module, spv::StorageClass _class, List<const Instruction*>& _outVariables)
{
	for (const Instruction& var : _module.getGlobalVariables()) 
	{
		if (var.getStorageClass() == _class)
		{
			_outVariables.emplace_back(&var);
		}
	}
}

void spvgentwo::ReflectionHelper::getVariableDecorations(const Instruction* _pVariable, List<const Instruction*>& _outDecorations)
{
	if (_pVariable == nullptr || _pVariable->getModule() == nullptr)
		return;

	for(const Instruction& decoration : _pVariable->getModule()->getDecorations())
	{
		if (*decoration.getFirstActualOperand() == _pVariable) // check target
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
	if (_pDecoration == nullptr || *_pDecoration != spv::Op::OpDecorate)
		return ~0u;

	auto decorate = _pDecoration->getFirstActualOperand().next(); // skip target operand

	// check if this is the kind of decoration we are lookin for
	if (decorate != nullptr && decorate.next() != nullptr && decorate->getLiteral() == static_cast<unsigned int>(_decoration))
	{
		return decorate.next()->getLiteral();
	}

	return ~0u;
}

unsigned int spvgentwo::ReflectionHelper::getDecorationLiteralFromVariable(spv::Decoration _decoration, const Instruction* _pVariable)
{
	if (_pVariable == nullptr || *_pVariable != spv::Op::OpVariable || _pVariable->getModule() == nullptr)
		return ~0u;

	for (const Instruction& decoration : _pVariable->getModule()->getDecorations())
	{
		auto target = decoration.getFirstActualOperand();

		if (target != nullptr && *target == _pVariable)
		{
			if (auto deco = target.next(); deco != nullptr && deco.next() != nullptr && deco->getLiteral() == static_cast<unsigned int>(_decoration))
			{
				return deco.next()->getLiteral();
			}
		}
	}

	return ~0u;
}
