#pragma once

#include "spvgentwo/HashMap.h"
#include "HeapAllocator.h"

namespace spvgentwo
{
	template <class Key, class Value>
	class HeapHashMap : public HashMap<Key, Value>
	{
	public:
		using HashMap<Key, Value>::HashMap;
	
		HeapHashMap(unsigned int _buckets = HashMap<Key, Value>::DefaultBucktCount) : HashMap<Key, Value>(HeapAllocator::instance(), _buckets) {}
		HeapHashMap(HeapHashMap&& _other) noexcept : HashMap<Key, Value>(stdrep::move(_other)) {}

		template <class ... Args>
		HeapHashMap(Key&& _key, Value&& _value, Args&& ... _keyvals) : 
			HashMap<Key, Value>(HeapAllocator::instance(), stdrep::forward<Key>(_key), stdrep::forward<Value>(_value), stdrep::forward<Args>(_keyvals)...)
		{}

		HeapHashMap& operator=(HeapHashMap&& _other) noexcept { HashMap<Key, Value>::operator=(stdrep::move(_other)); return *this; }

		virtual ~HeapHashMap() override = default;
	};
}// !spvgentwo