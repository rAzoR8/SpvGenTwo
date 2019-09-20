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
	m_Operation(std::move(_other.m_Operation)),
	m_Components(std::move(_other.m_Components)),
	m_literalData(std::move(_other.m_literalData)),
	m_Type(std::move(_other.m_Type))
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
	m_Components = std::move(_other.m_Components);
	m_literalData = std::move(_other.m_literalData);
	m_Operation = std::move(_other.m_Operation);
	m_Type = std::move(_other.m_Type);
	return *this;
}

spvgentwo::Constant& spvgentwo::Constant::make(const bool _value, const bool _spec)
{
	m_Operation = _value ? (_spec ? spv::Op::OpSpecConstantTrue : spv::Op::OpConstantTrue) : (_spec ? spv::Op::OpSpecConstantFalse : spv::Op::OpConstantFalse);
	return *this;
}

spvgentwo::Constant& spvgentwo::Constant::make(const short _value, const bool _spec)
{
	m_Operation = _spec ? spv::Op::OpSpecConstant : spv::Op::OpConstant;
	appendLiteralsToContainer(m_literalData, _value);
	return *this;
}

spvgentwo::Constant& spvgentwo::Constant::make(const unsigned short _value, const bool _spec)
{
	m_Operation = _spec ? spv::Op::OpSpecConstant : spv::Op::OpConstant;
	appendLiteralsToContainer(m_literalData, _value);
	return *this;
}

spvgentwo::Constant& spvgentwo::Constant::make(const int _value, const bool _spec)
{
	m_Operation = _spec ? spv::Op::OpSpecConstant : spv::Op::OpConstant;
	appendLiteralsToContainer(m_literalData, _value);
	return *this;
}

spvgentwo::Constant& spvgentwo::Constant::make(const unsigned int _value, const bool _spec)
{
	m_Operation = _spec ? spv::Op::OpSpecConstant : spv::Op::OpConstant;
	appendLiteralsToContainer(m_literalData, _value);
	return *this;
}

spvgentwo::Constant& spvgentwo::Constant::make(const long long _value, const bool _spec)
{
	m_Operation = _spec ? spv::Op::OpSpecConstant : spv::Op::OpConstant;
	appendLiteralsToContainer(m_literalData, _value);
	return *this;
}

spvgentwo::Constant& spvgentwo::Constant::make(const unsigned long long _value, const bool _spec)
{
	m_Operation = _spec ? spv::Op::OpSpecConstant : spv::Op::OpConstant;
	appendLiteralsToContainer(m_literalData, _value);
	return *this;
}

spvgentwo::Constant& spvgentwo::Constant::make(const float _value, const bool _spec)
{
	m_Operation = _spec ? spv::Op::OpSpecConstant : spv::Op::OpConstant;
	appendLiteralsToContainer(m_literalData, _value);
	return *this;
}

spvgentwo::Constant& spvgentwo::Constant::make(const double _value, const bool _spec)
{
	m_Operation = _spec ? spv::Op::OpSpecConstant : spv::Op::OpConstant;
	appendLiteralsToContainer(m_literalData, _value);
	return *this;
}