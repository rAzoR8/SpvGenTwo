#pragma once

#include "Node.h"

namespace spvgentwo
{
	template <class N, class E>
	class Graph
	{
	public:
		using NodeType = Node<N, E>;
		using Iterator = typename List<NodeType>::Iterator;

		Graph(IAllocator* _pAllocator = nullptr);

		Iterator begin() const { return m_nodes.begin(); }
		Iterator end() const { return m_nodes.end(); }

		// add new node
		template <class ...Args>
		NodeType& emplace(Args&& ..._args);

		IAllocator* getAllocator() const { return m_nodes.getAllocator(); }

		Iterator erase(Iterator _pos);

	private:

		List<NodeType> m_nodes;
	};

	template<class N, class E>
	inline Graph<N, E>::Graph(IAllocator* _pAllocator) :
		m_nodes(_pAllocator)
	{
	}

	template<class N, class E>
	inline typename Graph<N, E>::Iterator Graph<N, E>::erase(Iterator _pos)
	{
		return m_nodes.erase(_pos);
	}

	template<class N, class E>
	template<class ...Args>
	inline Graph<N, E>::NodeType& Graph<N, E>::emplace(Args&& ..._args)
	{
		return m_nodes.emplace_back(getAllocator(), stdrep::forward<Args>(_args)...);
	}
} // spvgentwo