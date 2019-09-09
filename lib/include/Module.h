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
		using Iterator = EntryIterator<Function>;

		Module(IAllocator* _pAllocator);
		~Module();

		TFunction* addFunction();

		IAllocator* getAllocator() { return m_pAllocator; }
		const IAllocator* getAllocator() const { return m_pAllocator; }

		Iterator begin() const { return Iterator(m_pFunctions); }
		Iterator end() const { return Iterator(nullptr); }

	private:
		TFunction* m_pFunctions = nullptr;
		IAllocator* m_pAllocator = nullptr;
	};
} // !spvgentwo