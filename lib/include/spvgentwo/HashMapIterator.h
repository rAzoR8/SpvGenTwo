#pragma once

#include "List.h"
#include "FNV1aHasher.h"

namespace spvgentwo
{
	template <class Key, class Value>
	struct NodeT
	{
		template <class K, class V>
		friend class HashMap;

		template <class ...Args>
		constexpr NodeT( Args&& ... _args) : kv( stdrep::forward<Args>(_args)... ) {}

		struct KV
		{
			template <class KeyT, class ...Args>
			constexpr KV(KeyT&& _key, Args&& ... _args) :
				key{ stdrep::forward<KeyT>(_key) },
				value{ stdrep::forward<Args>(_args)... } {}
			
			Key key{};
			Value value{};
		} kv;

	private:
		Hash64 hash{0u};
	};

	template <class Key, class Value>
	class HashMapIterator
	{
		template <class K, class V>
		friend class HashMap;

	public:
		using Node = NodeT<Key, Value>;
		using KeyValue = typename Node::KV;
		using Bucket = List<Node>;

		constexpr HashMapIterator(Bucket* _pBucket = nullptr, Bucket* _pEnd = nullptr, typename Bucket::Iterator _element = nullptr) : m_element(_element), m_pBucket(_pBucket), m_pEnd(_pEnd){}
		constexpr HashMapIterator(const HashMapIterator& _other) : m_element(_other.m_element), m_pBucket(_other.m_pBucket), m_pEnd(_other.m_pEnd) {}

		constexpr bool operator==(const HashMapIterator& _other) const;
		constexpr bool operator!=(const HashMapIterator& _other) const;

		// pre
		constexpr HashMapIterator<Key, Value>& operator++();

		// post
		constexpr HashMapIterator<Key, Value> operator++(int);

		constexpr HashMapIterator<Key, Value> next() const;

		constexpr KeyValue& operator*() { return m_element->kv; }
		constexpr const KeyValue& operator*() const { return m_element->kv; }

		constexpr KeyValue* operator->() { return &m_element->kv; }
		constexpr const KeyValue* operator->() const { return &m_element->kv; }

		// check if iterator is valid, can be derefed. Might still be at end!
		constexpr operator bool() const { return m_pBucket != nullptr || m_element == nullptr; }

	private:
		typename Bucket::Iterator m_element = nullptr;
		Bucket* m_pBucket = nullptr;
		Bucket* m_pEnd = nullptr;
	};

	template<class Key, class Value>
	inline constexpr bool HashMapIterator<Key, Value>::operator==(const HashMapIterator& _other) const
	{
		return m_pBucket == _other.m_pBucket && m_pEnd == _other.m_pEnd && m_element == _other.m_element;
	}

	template<class Key, class Value>
	inline constexpr bool HashMapIterator<Key, Value>::operator!=(const HashMapIterator& _other) const
	{
		return m_pBucket != _other.m_pBucket || m_pEnd != _other.m_pEnd || m_element != _other.m_element;
	}

	template<class Key, class Value>
	inline constexpr HashMapIterator<Key, Value>& HashMapIterator<Key, Value>::operator++()
	{
		if (++m_element == nullptr)
		{
			while (++m_pBucket < m_pEnd)
			{
				if (m_pBucket->empty() == false)
				{
					m_element = m_pBucket->begin();
					break;
				}
			}
		}

		return *this;
	}

	template<class Key, class Value>
	inline constexpr HashMapIterator<Key, Value> HashMapIterator<Key, Value>::operator++(int)
	{
		HashMapIterator<Key, Value> ret(*this);
		this->operator++();
		return ret;
	}

	template<class Key, class Value>
	inline constexpr HashMapIterator<Key, Value> HashMapIterator<Key, Value>::next() const
	{
		HashMapIterator<Key, Value> ret(*this);
		return ++ret;
	}
} // !spvgentwo