#pragma once

#include "HashMapIterator.h"

namespace spvgentwo
{
	template <class Key, class Value>
	// with chaining => multimap
	class HashMap
	{
	public:
		using HashFunc = Hash64(*)(const Key& _key);

		static constexpr auto DefaultBucktCount = 64u;

		using Node = NodeT<Key, Value>;
		using Bucket = List<Node>;

		using Iterator = HashMapIterator<Key, Value>;
		using ValueType = Node;
		using ReferenceType = Node&;
		using PointerType = Node*;

		using TRange = Range<typename Bucket::Iterator>;
	public:

		constexpr HashMap() = default;
		HashMap(IAllocator* _pAllocator, unsigned int _buckets = DefaultBucktCount, HashFunc _func = hash<Key>);
		HashMap(HashMap&& _other) noexcept;

		// computes bucket size as sizeof..(_keyvals) * 2 + 1 (number of nodes constructed from args passed)
		// adding further nodes after construction is therefore suboptimal, use default consturctor with _buckets count for runtime decided count
		template <class ... Args>
		HashMap(IAllocator* _pAllocator, Key&& _key, Value&& _value, Args&& ... _keyvals);

		virtual ~HashMap();

		HashMap& operator=(HashMap&& _other) noexcept;

		template <class ... Args>
		Node& emplace(const Key& _key, Args&& ... _args);

		template <class ... Args>
		void emplaceArgs(Key&& _key, Value&& _value, Args&& ... _keyvals);

		template <class ... Args>
		Node& emplaceUnique(const Key& _key, Args&& ... _args);

		// retuns nullptr if not resident
		Value* get(const Hash64 _hash) const;

		// only enable overload of Key type differs from Hash64
		template <class T = Key, typename = stdrep::enable_if_t<stdrep::is_same_v<T, Key> && !stdrep::is_same_v<T, Hash64>>>
		Value* get(const T& _key) const { return get(m_pHashFunc(_key)); }

		// retuns nullptr if not resident
		Value* operator[](const Key& _key) const { return get(m_pHashFunc(_key)); }

		TRange getRange(const Hash64 _hash) const;

		// only enable overload of Key type differs from Hash64
		template <class T = Key, typename = stdrep::enable_if_t<stdrep::is_same_v<T, Key> && !stdrep::is_same_v<T, Hash64>>>
		TRange getRange(const T& _key) const { return getRange(m_pHashFunc(_key)); }

		Iterator find(const Key& _key) const;

		Key* findKey(const Value& _value) const;

		// remove value pointed to by pos, returns the next elements iterator or end
		Iterator erase(Iterator pos);

		// remove all elements with Key _key
		unsigned int eraseRange(const Key& _key);

		unsigned int count(const Hash64 _hash) const;
		unsigned int count(const Key& _key) const { return count(m_pHashFunc(_key)); }

		constexpr const Bucket& getBucket(const unsigned int _index) const { return m_pBuckets[_index]; }
		constexpr unsigned int getBucketCount() const { return m_Buckets; }

		constexpr Iterator begin() const;
		constexpr Iterator end() const { return Iterator(m_pBuckets + m_Buckets, m_pBuckets + m_Buckets, nullptr); }

		void clear();

		constexpr unsigned int elements() const { return m_Elements; }

	private:
		void destroy();

	private:
		IAllocator* m_pAllocator = nullptr;
		Bucket* m_pBuckets = nullptr;
		unsigned int m_Buckets = 0u;
		unsigned int m_Elements = 0u;
		HashFunc m_pHashFunc = nullptr;
	};

	template<class Key, class Value>
	inline HashMap<Key, Value>::HashMap(IAllocator* _pAllocator, unsigned int _buckets, HashFunc _func) :
		m_pAllocator(_pAllocator), m_Buckets(_buckets), m_pHashFunc(_func)
	{
		if (m_pAllocator != nullptr)
		{
			m_pBuckets = static_cast<Bucket*>(m_pAllocator->allocate(m_Buckets * sizeof(Bucket), alignof(Bucket)));
			for (auto i = 0u; i < m_Buckets; ++i)
			{
				new(m_pBuckets + i) Bucket(m_pAllocator);
			}
		}
	}

	template<class Key, class Value>
	inline HashMap<Key, Value>::HashMap(HashMap&& _other) noexcept :
		m_pAllocator(_other.m_pAllocator),
		m_pBuckets(_other.m_pBuckets),
		m_Buckets(_other.m_Buckets),
		m_Elements(_other.m_Elements),
		m_pHashFunc(_other.m_pHashFunc)
	{
		_other.m_pAllocator = nullptr;
		_other.m_pBuckets = nullptr;
		_other.m_Buckets = 0u;
		_other.m_Elements = 0u;
		_other.m_pHashFunc = nullptr;
	}

	template<class Key, class Value>
	inline void HashMap<Key, Value>::destroy()
	{
		if (m_pBuckets != nullptr && m_pAllocator != nullptr)
		{
			for (auto i = 0u; i < m_Buckets; ++i)
			{
				m_pBuckets[i].~List();
			}
			m_pAllocator->deallocate(m_pBuckets, m_Buckets * sizeof(Bucket));
			m_pBuckets = nullptr;
			m_pAllocator = nullptr;
			m_Elements = 0u;
			m_pHashFunc = nullptr;
		}
	}

	template<class Key, class Value>
	inline void HashMap<Key, Value>::clear()
	{
		if (m_pBuckets != nullptr)
		{
			for (auto i = 0u; i < m_Buckets; ++i)
			{
				m_pBuckets[i].clear();
			}
		}
		m_Elements = 0u;
	}

	template<class Key, class Value>
	inline HashMap<Key, Value>::~HashMap()
	{
		destroy();
	}

	template<class Key, class Value>
	inline HashMap<Key, Value>& HashMap<Key, Value>::operator=(HashMap&& _other) noexcept
	{
		if (this == &_other) return *this;

		// free left side
		destroy();

		m_Buckets = _other.m_Buckets;
		m_pAllocator = _other.m_pAllocator;
		m_pBuckets = _other.m_pBuckets;
		m_Elements = _other.m_Elements;
		m_pHashFunc = _other.m_pHashFunc;

		_other.m_Buckets = 0u;
		_other.m_pAllocator = nullptr;
		_other.m_pBuckets = nullptr;
		_other.m_Elements = 0u;
		_other.m_pHashFunc = nullptr;

		return *this;
	}

	template<class Key, class Value>
	inline Value* HashMap<Key, Value>::get(const Hash64 _hash) const
	{
		const auto index = _hash % m_Buckets;

		for (Node& n : m_pBuckets[index])
		{
			if (n.hash == _hash)
				return &n.kv.value;
		}

		return nullptr;
	}

	template<class Key, class Value>
	inline typename HashMap<Key, Value>::TRange HashMap<Key, Value>::getRange(const Hash64 _hash) const
	{
		const auto index = _hash % m_Buckets;
		const Bucket& bucket = m_pBuckets[index];

		auto first = bucket.end();
		auto last = first;

		for (auto it = bucket.begin(); it != bucket.end(); ++it)
		{
			const Node& n = *it;
			if (n.hash == _hash)
			{
				if (first == bucket.end())
				{
					first = it;
				}
				last = it + 1u;
			}
			
		}

		return { first , last };
	}

	template<class Key, class Value>
	inline typename HashMap<Key, Value>::Iterator HashMap<Key, Value>::erase(Iterator pos)
	{
		if(pos && pos != end())
		{
			auto next = pos.next();
			pos.m_pBucket->erase(pos.m_element);
			--m_Elements;
			return next;
		}
		return end();
	}

	template<class Key, class Value>
	inline unsigned int HashMap<Key, Value>::eraseRange(const Key& _key)
	{
		Hash64 h = 0u;

		if constexpr (stdrep::is_same_v<Key, Hash64>)
		{
			h = _key;
		}
		else
		{
			h = m_pHashFunc(_key);
		}

		unsigned int keys = 0u;
		const auto index = h % m_Buckets;

		Bucket& bucket = m_pBuckets[index];

		for (auto it = bucket.begin(), e = bucket.end(); it != e;)
		{
			if (it->hash == h)
			{
				it = bucket.erase(it);
				++keys;
			}
			else 
			{
				++it;
			}
		}

		return keys;
	}

	template<class Key, class Value>
	inline unsigned int HashMap<Key, Value>::count(const Hash64 _hash) const
	{
		unsigned int keys = 0u;
		const auto index = _hash % m_Buckets;

		for (const Node& n : m_pBuckets[index])
		{
			if (n.hash == _hash)
			{
				++keys;
			}
		}

		return keys;
	}

	template<class Key, class Value>
	inline typename HashMap<Key, Value>::Iterator HashMap<Key, Value>::find(const Key& _key) const
	{
		Hash64 h = 0u;

		if constexpr (stdrep::is_same_v<Key, Hash64>)
		{
			h = _key;
		}
		else
		{
			h = m_pHashFunc(_key);
		}

		const auto index = h % m_Buckets;

		const Bucket& bucket = m_pBuckets[index];

		for (auto it = bucket.begin(), e = bucket.end(); it != e; ++it)
		{
			if (it->hash == h)
			{
				return Iterator(m_pBuckets + index, m_pBuckets + m_Buckets, it);
			}
		}

		return end();
	}

	template<class Key, class Value>
	inline Key* HashMap<Key, Value>::findKey(const Value& _value) const
	{
		for (auto i = 0u; i < m_Buckets; ++i)
		{
			for (Bucket& b : m_pBuckets[i])
			{
				for (Node& n : b)
				{
					if (n.kv.value == _value)
					{
						return &n.kv.key;
					}
				}
			}
		}

		return nullptr;
	}

	template<class Key, class Value>
	template<class ...Args>
	inline HashMap<Key, Value>::HashMap(IAllocator* _pAllocator, Key&& _key, Value&& _value, Args && ..._keyvals) :
		HashMap<Key, Value>(_pAllocator, sizeof...(_keyvals) * 2u + 1u)
	{
		emplaceArgs(stdrep::forward<Key>(_key), stdrep::forward<Value>(_value), stdrep::forward<Args>(_keyvals)...);
	}

	template<class Key, class Value>
	template<class ...Args>
	inline typename HashMap<Key, Value>::Node& HashMap<Key, Value>::emplace(const Key& _key, Args&& ..._args)
	{
		Entry<Node>* pNode = Entry<Node>::create(m_pAllocator, _key, stdrep::forward<Args>(_args)...);

		Node& n = pNode->inner();

		if constexpr (stdrep::is_same_v<Key, Hash64>)
		{
			n.hash = _key;
		}
		else
		{
			n.hash = m_pHashFunc(_key);
		}

		const auto index = n.hash % m_Buckets;

		// append to chain
		m_pBuckets[index].append_entry(pNode);

		++m_Elements;

		return n;
	}

	template<class Key, class Value>
	template<class ...Args>
	inline void HashMap<Key, Value>::emplaceArgs(Key&& _key, Value&& _value, Args && ..._keyvals)
	{
		emplace(stdrep::forward<Key>(_key), stdrep::forward<Value>(_value));

		if constexpr (sizeof...(_keyvals) > 1)
		{
			emplaceArgs(stdrep::forward<Args>(_keyvals)...);
		}
	}

	template<class Key, class Value>
	template<class ...Args>
	inline typename HashMap<Key, Value>::Node& HashMap<Key, Value>::emplaceUnique(const Key& _key, Args&& ..._args)
	{
		Hash64 h = 0u;

		if constexpr (stdrep::is_same_v<Key, Hash64>)
		{
			h = _key;
		}
		else
		{
			h = m_pHashFunc(_key);
		}

		const auto index = h % m_Buckets;

		for (Node& existing : m_pBuckets[index])
		{
			if (existing.hash == h)
			{
				return existing;
			}
		}

		Node& n = m_pBuckets[index].emplace_back(_key, stdrep::forward<Args>(_args)...);
		n.hash = h;

		++m_Elements;

		return n;
	}

	template<class Key, class Value>
	inline constexpr typename HashMap<Key, Value>::Iterator HashMap<Key, Value>::begin() const
	{
		for (unsigned int i = 0u; i < m_Buckets; ++i)
		{
			if (m_pBuckets[i].empty() == false)
			{
				return Iterator(m_pBuckets + i, m_pBuckets + m_Buckets, m_pBuckets[i].begin());
			}
		}

		return end();
	}
} // !spvgentwo