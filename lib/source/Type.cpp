#include "Type.h"

spvgentwo::Type::Type(IAllocator* _pAllocator) :
	m_subTypes(_pAllocator)
{
}

spvgentwo::Type::~Type()
{
}

void spvgentwo::Type::setBaseType(const spv::Op _type)
{
	if (IsType(_type))
	{
		m_Type = _type;
	}
}

spvgentwo::Type& spvgentwo::Type::Void()
{
	m_Type = spv::Op::OpTypeVoid;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::Bool()
{
	m_Type = spv::Op::OpTypeBool;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::Int(const unsigned int _bits, const bool _sign)
{
	m_Type = spv::Op::OpTypeInt;
	m_Dimension = _bits;
	m_Sign = _sign;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::Float(const unsigned int _bits)
{
	m_Type = spv::Op::OpTypeFloat;
	m_Dimension = _bits;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::StructMember()
{
	m_Type = spv::Op::OpTypeStruct;
	return m_subTypes.emplace_back(m_subTypes.getAllocator());
}

spvgentwo::Type& spvgentwo::Type::Array(const unsigned int _elements)
{
	m_Type = spv::Op::OpTypeArray;
	m_Dimension = _elements;
	if (m_subTypes.empty())
	{
		return m_subTypes.emplace_back(m_subTypes.getAllocator());
	}
	else
	{
		return m_subTypes.front();
	}
}
