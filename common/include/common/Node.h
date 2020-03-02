#pragma once

#include "spvgentwo/List.h"

namespace spvgentwo
{
	class IAllocator;

	struct EmptyEdge {};

	template <class Node, class Data = EmptyEdge>
	struct Edge
	{
		Node* pTarget;
		Data data;
	};

	// N = node data, E = edge data
	template <class N, class E = EmptyEdge>
	class Node
	{
	public:
		using EdgeType = Edge<Node, E>;

		Node(IAllocator* _pAllocator = nullptr);

		template <class ...Args>
		Node(IAllocator* _pAllocator, Args&& ... _args);

		template <class ...EdgeArgs>
		void connect(Node* _pTarget, EdgeArgs&& ..._args);

		const List<EdgeType>& inputs() const { return m_inputs; }
		List<EdgeType>& inputs() { return m_inputs; }

		const List<EdgeType>& outputs() const { return m_outputs; }
		List<EdgeType>& outputs() { return m_outputs; }

		const N& data() const { return m_data; }
		N& data() { return m_data; }

		typename List<EdgeType>::Iterator remove_input(const Node* _pNode);
		typename List<EdgeType>::Iterator remove_output(const Node* _pNode);

	private:
		N m_data;

		List<EdgeType> m_inputs;
		List<EdgeType> m_outputs;
	};

	template<class N, class E>
	inline Node<N, E>::Node(IAllocator* _pAllocator) :
		m_inputs(_pAllocator),
		m_outputs(_pAllocator)
	{
	}

	template<class N, class E>
	inline typename List<typename Node<N, E>::EdgeType>::Iterator Node<N, E>::remove_input(const Node* _pNode)
	{
		auto it = m_inputs.find([_pNode](const Edge& e) {return e.pTarget == _pNode; });
		if (it != nullptr)
		{
			return m_inputs.erase(it);
		}
		return it;
	}

	template<class N, class E>
	inline typename List<typename Node<N, E>::EdgeType>::Iterator Node<N, E>::remove_output(const Node* _pNode)
	{
		auto it = m_outputs.find([_pNode](const Edge& e) {return e.pTarget == _pNode; });
		if (it != nullptr)
		{
			return m_outputs.erase(it);
		}
		return it;
	}

	template<class N, class E>
	template<class ...Args>
	inline Node<N, E>::Node(IAllocator* _pAllocator, Args&& ..._args) :
		m_data{stdrep::forward<Args>(_args)...},
		m_inputs(_pAllocator),
		m_outputs(_pAllocator)
	{
	}

	template<class N, class E>
	template<class ...EdgeArgs>
	inline void Node<N, E>::connect(Node* _pTarget, EdgeArgs&& ..._args)
	{
		m_outputs.emplace_back(_pTarget, stdrep::forward<EdgeArgs>(_args)...);
		_pTarget->m_inputs.emplace_back(this, stdrep::forward<EdgeArgs>(_args)...);
	}
} // spvgentwo