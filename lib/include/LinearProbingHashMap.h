#pragma once

#include "List.h"
#include "Hasher.h"

namespace spvgentwo
{
	// forward decls
	
	template <class Key, class Value>
	// with chaining
	class LinearProbingHashMap
	{
	public:
		static constexpr auto DefaultBucktCount = 64u;

		struct Node
		{
			Key key;
			Value value;
		};

	private:
		struct NodeStore
		{
			template <class ...Args>
			NodeStore(Args&& ... _args) : kv{ std::forward<Args>(_args)... }, hash{ 0u }{}

			Node kv;
			Hash64 hash;
		};

		using Chain = List<NodeStore>;
	public:
		
		LinearProbingHashMap(IAllocator* _pAllocator, const unsigned int _buckets = DefaultBucktCount);
		~LinearProbingHashMap();

		template <class ... Args>
		Node& insert(Args&& ... _args);

		const Value* get(const Key& _key) const;

	private:
		Chain* m_pBuckets = nullptr;
		IAllocator* m_pAllocator = nullptr;
		unsigned int m_Buckets = 0u;
	};
	template<class Key, class Value>
	inline LinearProbingHashMap<Key, Value>::LinearProbingHashMap(IAllocator* _pAllocator, const unsigned int _buckets) : 
		m_pAllocator(_pAllocator), m_Buckets(_buckets)
	{
		m_pBuckets = reinterpret_cast<Chain*>(m_pAllocator->allocate(m_Buckets * sizeof(Chain)));
		for (auto i = 0u; i < m_Buckets; ++i)
		{
			new(m_pBuckets + i) Chain(m_pAllocator);
		}
	}
	template<class Key, class Value>
	inline LinearProbingHashMap<Key, Value>::~LinearProbingHashMap()
	{
		if (m_pBuckets != nullptr && m_pAllocator != nullptr)
		{
			for (auto i = 0u; i < m_Buckets; ++i)
			{
				m_pBuckets[i].~List();
			}
			m_pAllocator->deallocate(m_pBuckets, m_Buckets * sizeof(Chain));
			m_pBuckets = nullptr;
			m_pAllocator = nullptr;
		}
	}

	template<class Key, class Value>
	inline const Value* LinearProbingHashMap<Key, Value>::get(const Key& _key) const
	{
		const auto hash = Hasher<Key>()(_key);
		const auto index = hash % m_Buckets;

		for (const NodeStore& n : m_pBuckets[index])
		{
			if (n.hash == hash) 
				return &n.kv.value;
		}

		return nullptr;
	}
	
	template<class Key, class Value>
	template<class ...Args>
	inline typename LinearProbingHashMap<Key, Value>::Node& LinearProbingHashMap<Key, Value>::insert(Args&& ..._args)
	{
		Entry<NodeStore>* pNode = Entry<NodeStore>::create(m_pAllocator, std::forward<Args>(_args)...);

		NodeStore& n = pNode->inner();

		n.hash = Hasher<Key>()(n.kv.key);
		const auto index = n.hash % m_Buckets;

		// append to chain
		m_pBuckets[index].append_entry(pNode);

		return n.kv;
	}
} // !spvgentwo