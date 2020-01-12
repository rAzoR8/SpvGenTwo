#include "spvgentwo/Constant.h"
#include "spvgentwo/Operand.h"

spvgentwo::Constant::Constant(IAllocator* _pAllocator) : 
	m_Type(_pAllocator),
	m_Components(_pAllocator),
	m_literalData(_pAllocator)
{
}

spvgentwo::Constant::Constant(const Constant& _other) :
	m_Operation(_other.m_Operation),
	m_Type(_other.m_Type),
	m_Components(_other.m_Components),
	m_literalData(_other.m_literalData)
{
}

spvgentwo::Constant::Constant(Constant&& _other) noexcept:
	m_Operation(stdrep::move(_other.m_Operation)),
	m_Type(stdrep::move(_other.m_Type)),
	m_Components(stdrep::move(_other.m_Components)),
	m_literalData(stdrep::move(_other.m_literalData))
{
}

spvgentwo::Constant::~Constant()
{
}

spvgentwo::Constant& spvgentwo::Constant::operator=(const Constant& _other)
{
	if (this == &_other) return *this;

	m_Components = _other.m_Components;
	m_literalData = _other.m_literalData;
	m_Operation = _other.m_Operation;
	m_Type = _other.m_Type;

	return *this;
}

spvgentwo::Constant& spvgentwo::Constant::operator=(Constant&& _other) noexcept
{
	if (this == &_other) return *this;

	m_Components = stdrep::move(_other.m_Components);
	m_literalData = stdrep::move(_other.m_literalData);
	m_Operation = stdrep::move(_other.m_Operation);
	m_Type = stdrep::move(_other.m_Type);

	return *this;
}

spvgentwo::Constant& spvgentwo::Constant::Component()
{
	return m_Components.emplace_back(m_Components.getAllocator());
}

void spvgentwo::Constant::reset()
{
	m_Operation = spv::Op::OpConstantNull;
	m_Components.clear();
	m_literalData.clear();
	m_Type.reset();
}
