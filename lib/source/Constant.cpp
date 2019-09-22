#include "Constant.h"
#include "Operand.h"

spvgentwo::Constant::Constant(IAllocator* _pAllocator) : 
	m_Components(_pAllocator),
	m_literalData(_pAllocator),
	m_Type(_pAllocator)
{
}

spvgentwo::Constant::Constant(const Constant& _other) :
	m_Operation(_other.m_Operation),
	m_Components(_other.m_Components),
	m_literalData(_other.m_literalData),
	m_Type(_other.m_Type)
{
}

spvgentwo::Constant::Constant(Constant&& _other) noexcept:
	m_Operation(stdrep::move(_other.m_Operation)),
	m_Components(stdrep::move(_other.m_Components)),
	m_literalData(stdrep::move(_other.m_literalData)),
	m_Type(stdrep::move(_other.m_Type))
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