#include "common/ReflectionHelper.h"

#include "spvgentwo/Module.h"

spvgentwo::ReflectionHelper::ReflectionHelper(const Module& _module) : m_module(_module)
{
}

spvgentwo::ReflectionHelper::~ReflectionHelper()
{
}

bool spvgentwo::ReflectionHelper::getLocalSize(unsigned int& _x, unsigned int& _y, unsigned int& _z) const
{
	for (const auto& mode : m_module.getExecutionModes()) 
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

void spvgentwo::ReflectionHelper::getVariablesByStorageClass(spv::StorageClass _class, List<const Instruction*>& _outVariables) const
{
	for (const Instruction& var : m_module.getGlobalVariables()) 
	{
		if (var.getStorageClass() == _class)
		{
			_outVariables.emplace_back(&var);
		}
	}
}

void spvgentwo::ReflectionHelper::getVariableDecorations(const Instruction* _pVariable, List<const Instruction*>& _outDecorations) const
{
	if (_pVariable == nullptr)
		return;

	for(const Instruction& decoration : m_module.getDecorations())
	{
		if (*decoration.getFirstActualOperand() == _pVariable)
		{
			_outDecorations.emplace_back(&decoration);
		}
	}
}
