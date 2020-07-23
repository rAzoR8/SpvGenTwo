#pragma once

#include "List.h"
#include "Hasher.h"

namespace spvgentwo
{
	template <class Key, class Value>
	struct NodeT
	{
		template <class K, class V>
		friend class HashMap;

		template <class ...Args>
		NodeT(Args&& ... _args) : kv{ stdrep::forward<Args>(_args)... }, hash{ 0u }{}

		struct KV
		{
			Key key;
			Value value;
		} kv;

	private:
		Hash64 hash;
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

		HashMapIterator(Bucket* _pBucket = nullptr, Bucket* _pEnd = nullptr, typename Bucket::Iterator _element = nullptr) : m_element(_element), m_pBucket(_pBucket), m_pEnd(_pEnd){}
		HashMapIterator(const HashMapIterator& _other) : m_element(_other.m_element), m_pBucket(_other.m_pBucket), m_pEnd(_other.m_pEnd) {}

		bool operator==(const HashMapIterator& _other) const;
		bool operator!=(const HashMapIterator& _other) const;

		bool operator==(sgt_nullptr_t) const;
		bool operator!=(sgt_nullptr_t) const;

		// pre
		HashMapIterator<Key, Value>& operator++();

		// post
		HashMapIterator<Key, Value> operator++(int);

		KeyValue& operator*() { return m_element->kv; }
		const KeyValue& operator*() const { return m_element->kv; }

		KeyValue* operator->() { return &m_element->kv; }
		const KeyValue* operator->() const { return &m_element->kv; }

		// check if iterator is valid, can be derefed. Might still be at end!
		operator bool() const { return m_pBucket != nullptr || m_element == nullptr; }

	private:
		typename Bucket::Iterator m_element = nullptr;
		Bucket* m_pBucket = nullptr;
		Bucket* m_pEnd = nullptr;
	};

	template<class Key, class Value>
	inline bool HashMapIterator<Key, Value>::operator==(const HashMapIterator& _other) const
	{
		return m_pBucket == _other.m_pBucket && m_pEnd == _other.m_pEnd && m_element == _other.m_element;;
	}

	template<class Key, class Value>
	inline bool HashMapIterator<Key, Value>::operator!=(const HashMapIterator& _other) const
	{
		return m_pBucket != _other.m_pBucket || m_pEnd != _other.m_pEnd || m_element != _other.m_element;;
	}

	template<class Key, class Value>
	inline bool HashMapIterator<Key, Value>::operator==(sgt_nullptr_t) const
	{
		return m_pBucket == nullptr || m_element == nullptr;
	}

	template<class Key, class Value>
	inline bool HashMapIterator<Key, Value>::operator!=(sgt_nullptr_t) const
	{
		return m_pBucket != nullptr && m_element != nullptr;
	}

	template<class Key, class Value>
	inline HashMapIterator<Key, Value>& HashMapIterator<Key, Value>::operator++()
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
	inline HashMapIterator<Key, Value> HashMapIterator<Key, Value>::operator++(int)
	{
		HashMapIterator<Key, Value> ret(*this);
		this->operator++();
		return ret;
	}
} // !spvgentwo