#pragma once

#include "Entry.h"

namespace spvgentwo
{
	// forward decls
	class IAllocator;
	class Function;

	using TFunction = Entry<Function>;

	class Module
	{
	public:
		Module(IAllocator* _pAllocator);
		~Module();

		TFunction* addFunction();

		IAllocator* getAllocator() { return m_pAllocator; }
		const IAllocator* getAllocator() const { return m_pAllocator; }
	private:
		TFunction* m_pFunctions = nullptr;
		IAllocator* m_pAllocator = nullptr;
	};
} // !spvgentwo