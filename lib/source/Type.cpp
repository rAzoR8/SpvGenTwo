#include "Type.h"

spvgentwo::Type::Type(IAllocator* _pAllocator) :
	m_subTypes(_pAllocator)
{
}

spvgentwo::Type::~Type()
{
}

spvgentwo::Type spvgentwo::Type::Void()
{
	return Type(m_subTypes.getAllocator());
}
