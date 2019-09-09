#pragma once

#include "Function.h"

namespace spvgentwo
{
	// forward decls
	class IAllocator;

	class Module : public List<Function>
	{
	public:
		Module(IAllocator* _pAllocator);
		~Module();

		EntryType* addFunction() { return emplace_back(this); }

	private:
	};
} // !spvgentwo