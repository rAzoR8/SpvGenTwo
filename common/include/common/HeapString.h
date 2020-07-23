#pragma once

#include "spvgentwo/String.h"
#include "HeapAllocator.h"

namespace spvgentwo
{
	class HeapString : public String
	{
	public:
		using String::String;

		HeapString(const HeapString& _other) : String(_other) {}

		HeapString(HeapString&& _other) noexcept: String(stdrep::move(_other)) {}

		HeapString(const char* _pStr = nullptr, sgt_size_t _length = 0u) : String(HeapAllocator::instance(), _pStr, _length) {};

		template <sgt_size_t N>
		HeapString(const char(&_pStr)[N]) : String(HeapAllocator::instance(), _pStr) {};

		virtual ~HeapString() override = default;

		HeapString& operator=(const HeapString& _other) { String::operator=(_other); return *this; }
		HeapString& operator=(HeapString&& _other) noexcept { String::operator=(stdrep::move(_other)); return *this; }
	};
} // !spvgentwo