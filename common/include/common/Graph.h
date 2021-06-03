#pragma once

#include "Node.h"

namespace spvgentwo
{
	template <class N, class E = EmptyEdge>
	class Graph
	{
	public:
		using NodeType = Node<N, E>;
		using Iterator = typename List<NodeType>::Iterator;

		constexpr Graph(IAllocator* _pAllocator = nullptr);

		Graph(Graph<N, E>&& _other) noexcept;

		// since nodes can not be copied, neither can graphs
		Graph(const Graph<N, E>& _other) = delete;

		Graph<N, E>& operator=(Graph<N, E>&& _other) noexcept;
		Graph<N, E>& operator=(const Graph<N, E>& _other) = delete;

		constexpr IAllocator* getAllocator() const { return m_nodes.getAllocator(); }

		constexpr Iterator begin() const { return m_nodes.begin(); }
		constexpr Iterator end() const { return m_nodes.end(); }

		// add new node
		template <class ...Args>
		NodeType* emplace(Args&& ..._args);

		Iterator erase(Iterator _pos);

		void clear();

		constexpr bool empty() const { return m_nodes.empty(); }

		constexpr sgt_size_t size() const { return m_nodes.size(); }

		NodeType& front() { return m_nodes.front(); }
		const NodeType& front() const { return m_nodes.front(); }

		NodeType& back() { return m_nodes.front(); }
		const NodeType& back() const { return m_nodes.front(); }

	protected:

		List<NodeType> m_nodes;
	};

	template<class N, class E>
	inline constexpr Graph<N, E>::Graph(IAllocator* _pAllocator) :
		m_nodes(_pAllocator)
	{
	}

	template<class N, class E>
	inline Graph<N, E>::Graph(Graph<N, E>&& _other) noexcept :
		m_nodes(stdrep::move(_other.m_nodes))
	{
	}

	template<class N, class E>
	inline Graph<N, E>& Graph<N, E>::operator=(Graph<N, E>&& _other) noexcept
	{
		m_nodes = stdrep::move(_other.m_nodes);
	}

	template<class N, class E>
	inline typename Graph<N, E>::Iterator Graph<N, E>::erase(Iterator _pos)
	{
		if (_pos != nullptr)
		{
			NodeType& n = *_pos;
			for (auto& in : n.inputs())
			{
				in.pTarget->remove_output(&n);
			}
			for (auto& out : n.outputs())
			{
				out.pTarget->remove_input(&n);
			}
			return m_nodes.erase(_pos);		
		}

		return _pos;
	}

	template<class N, class E>
	template<class ...Args>
	inline typename Graph<N, E>::NodeType* Graph<N, E>::emplace(Args&& ..._args)
	{
		return &m_nodes.emplace_back(getAllocator(), stdrep::forward<Args>(_args)...);
	}

	template<class N, class E>
	inline void Graph<N, E>::clear()
	{
		m_nodes.clear();
	}
} // spvgentwo