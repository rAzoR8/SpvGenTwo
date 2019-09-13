#include "Type.h"

spvgentwo::Type::Type(IAllocator* _pAllocator, Type* _pParent) :
	m_subTypes(_pAllocator),
	m_pParent(_pParent)
{
}

spvgentwo::Type::Type(Type&& _other) noexcept:
	m_subTypes(std::move(_other.m_subTypes)),
	m_Type(_other.m_Type),
	m_Dimension(_other.m_Dimension),
	m_Sign(_other.m_Sign)
{
	for (Type& t : m_subTypes)
	{
		t.m_pParent = this;
	}
}

spvgentwo::Type::Type(const Type& _other) : 
	m_subTypes(_other.m_subTypes),
	m_Type(_other.m_Type),
	m_Dimension(_other.m_Dimension),
	m_Sign(_other.m_Sign)
{
	for (Type& t : m_subTypes)
	{
		t.m_pParent = this;
	}
}

spvgentwo::Type::~Type()
{
}

spvgentwo::Type& spvgentwo::Type::operator=(Type&& _other) noexcept
{
	if (this == &_other) return *this;

	m_subTypes = std::move(_other.m_subTypes);

	m_Type = _other.m_Type;
	m_Dimension = _other.m_Dimension;
	m_Sign = _other.m_Sign;

	for (Type& t : m_subTypes)
	{
		t.m_pParent = this;
	}

	return *this;
}
spvgentwo::Type& spvgentwo::Type::operator=(const Type& _other)
{
	if (this == &_other) return *this;
	m_subTypes = _other.m_subTypes;

	m_Type = _other.m_Type;
	m_Dimension = _other.m_Dimension;
	m_Sign = _other.m_Sign;

	for (Type& t : m_subTypes)
	{
		t.m_pParent = this;
	}

	return *this;
}

void spvgentwo::Type::setBaseType(const spv::Op _type)
{
	if (isType(_type))
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

spvgentwo::Type& spvgentwo::Type::Struct()
{
	m_Type = spv::Op::OpTypeStruct;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::Array(const unsigned int _elements)
{
	m_Type = spv::Op::OpTypeArray;
	m_Dimension = _elements;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::Function()
{
	m_Type = spv::Op::OpTypeFunction;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::Member()
{
	return m_subTypes.emplace_back(m_subTypes.getAllocator(), this);
}

spvgentwo::Type& spvgentwo::Type::Parent()
{
	if (m_pParent == nullptr) return *this;
	return *m_pParent;
}

spvgentwo::Type& spvgentwo::Type::Top()
{
	Type* parent = this;
	while (true) {
		if (parent->m_pParent == nullptr) { return *parent; }
		parent = parent->m_pParent;
	}
}