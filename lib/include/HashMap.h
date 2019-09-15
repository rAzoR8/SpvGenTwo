#pragma once

#include "List.h"
#include "Hasher.h"

namespace spvgentwo
{
	template <class Key, class Value>
	// with chaining => multimap
	class HashMap
	{
	public:
		static constexpr auto DefaultBucktCount = 64u;

		// TODO: implement iterator

		struct Node
		{
			template <class Key, class Value>
			friend class HashMap;

			template <class ...Args>
			Node(Args&& ... _args) : kv{ std::forward<Args>(_args)... }, hash{ 0u }{}

			struct //KV
			{
				Key key;
				Value value;
			} kv;

		private:
			Hash64 hash;
		};

		using Bucket = List<Node>;
	public:

		HashMap(IAllocator* _pAllocator, const unsigned int _buckets = DefaultBucktCount);
		~HashMap();

		template <class ... Args>
		Node& emplace(Args&& ... _args);

		// returns existing node if duplicate
		template <class ... Args>
		Node& emplaceUnique(Args&& ... _args);

		template <class ... Args>
		Node& emplaceUnique(const Key& _key, Args&& ... _args);

		Node& newNodeUnique(const Hash64& _hash);

		Value* get(const Hash64 _hash);
		Value* get(const Key& _key); // TODO: const variants

		const unsigned int count(const Hash64 _hash) const;

		const Bucket& getBucket(const unsigned int _index) const { return m_pBuckets[_index]; }
		unsigned int getBucketCount() const { return m_Buckets; }

	private:
		Bucket* m_pBuckets = nullptr;
		IAllocator* m_pAllocator = nullptr;
		unsigned int m_Buckets = 0u;
	};
	template<class Key, class Value>
	inline HashMap<Key, Value>::HashMap(IAllocator* _pAllocator, const unsigned int _buckets) :
		m_pAllocator(_pAllocator), m_Buckets(_buckets)
	{
		m_pBuckets = reinterpret_cast<Bucket*>(m_pAllocator->allocate(m_Buckets * sizeof(Bucket)));
		for (auto i = 0u; i < m_Buckets; ++i)
		{
			new(m_pBuckets + i) Bucket(m_pAllocator);
		}
	}

	template<class Key, class Value>
	inline HashMap<Key, Value>::~HashMap()
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
		}
	}

	template<class Key, class Value>
	inline Value* HashMap<Key, Value>::get(const Hash64 _hash)
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
	inline const unsigned int HashMap<Key, Value>::count(const Hash64 _hash) const
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
	inline Value* HashMap<Key, Value>::get(const Key& _key) 
	{
		return get(hash(_key));
	}

	template<class Key, class Value>
	template<class ...Args>
	inline typename HashMap<Key, Value>::Node& HashMap<Key, Value>::emplace(Args&& ..._args)
	{
		Entry<Node>* pNode = Entry<Node>::create(m_pAllocator, std::forward<Args>(_args)...);

		Node& n = pNode->inner();

		n.hash = hash(n.kv.key);
		const auto index = n.hash % m_Buckets;

		// append to chain
		m_pBuckets[index].append_entry(pNode);

		return n;
	}

	template<class Key, class Value>
	template<class ...Args> // (non trivial) key is constructed from args and then used to compute the hash
	inline typename HashMap<Key, Value>::Node& HashMap<Key, Value>::emplaceUnique(Args&& ..._args)
	{
		Entry<Node>* pNode = Entry<Node>::create(m_pAllocator, std::forward<Args>(_args)...);

		Node& n = pNode->inner();

		n.hash = hash(n.kv.key);
		const auto index = n.hash % m_Buckets;

		for (Node& existing : m_pBuckets[index])
		{
			if (existing.hash == n.hash)
			{
				m_pAllocator->destruct(pNode);
				return existing;
			}
		}

		m_pBuckets[index].append_entry(pNode);

		return n;
	}

	template<class Key, class Value>
	template<class ...Args>
	inline typename HashMap<Key, Value>::Node& HashMap<Key, Value>::emplaceUnique(const Key& _key, Args&& ..._args)
	{
		const Hash64 h = hash(_key);
		const auto index = h % m_Buckets;

		for (Node& existing : m_pBuckets[index])
		{
			if (existing.hash == h)
			{
				return existing;
			}
		}

		Node& n = m_pBuckets[index].emplace_back(_key, std::forward<Args>(_args)...);
		n.hash = h;
		return n;
	}

	template<class Key, class Value>
	inline typename HashMap<Key, Value>::Node& HashMap<Key, Value>::newNodeUnique(const Hash64& _hash)
	{
		const auto index = _hash % m_Buckets;

		for (Node& existing : m_pBuckets[index])
		{
			if (existing.hash == n.hash)
			{
				return existing;
			}
		}

		Node& n = m_pBuckets[index].emplace_back();
		n.hash = _hash;
		return n;
	}
} // !spvgentwo