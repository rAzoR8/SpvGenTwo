#pragma once

#include "Vector.h"

namespace spvgentwo
{
	// forward decl
	//class IAllocator;

	class String : public Vector<char>
	{
	public:
		String(IAllocator* _pAllocator) : Vector(_pAllocator) {};
		~String() {};

	private:
	};
}