#pragma once

#include "List.h"
namespace spvgentwo
{
	// forward decls
	class IAllocator;

	class Type
	{
	public:
		Type(IAllocator* _pAllocator);
		~Type();

	private:
		List<Type> m_subTypes;
	};
} // !spvgentwo