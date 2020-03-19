#pragma once

#include "spvgentwo/String.h"
#include "HeapAllocator.h"

namespace spvgentwo
{
	class HeapString : public String
	{
	public:
		using String::String;

		HeapString(const char* _pStr = nullptr, size_t _length = 0u) : String(HeapAllocator::instance(), _pStr, _length) {};

		template <size_t N>
		HeapString(const char(&_pStr)[N]) : String(HeapAllocator::instance(), _pStr) {};

		virtual ~HeapString() override = default;
	};
} // !spvgentwo