#pragma once

#include "spvgentwo/List.h"

namespace spvgentwo
{
	class IAllocator;

	struct EmptyEdge {};

	template <class Node, class Data = EmptyEdge>
	struct Edge
	{
		Node* pTarget{};
		Data data{};
	};

	// N = node data, E = edge data
	template <class N, class E = EmptyEdge>
	class Node
	{
	public:
		using EdgeType = Edge<Node, E>;

		Node(Node<N, E>&& _other) noexcept;

		// node edges store pointers to other graph nodes and cant be copied
		Node(const Node<N, E>& _other) = delete;

		constexpr Node(IAllocator* _pAllocator = nullptr);

		template <class ...Args>
		constexpr Node(IAllocator* _pAllocator, Args&& ... _args);

		Node<N, E>& operator=(Node<N, E>&& _other) noexcept;
		Node<N, E>& operator=(const Node<N, E>& _other) = delete;

		// connect this nodes (output edge) to target (input edge)
		template <class ...EdgeArgs>
		void connect(Node* _pTarget, EdgeArgs&& ..._args);

		// disconnect pTarget form this outputs, and remove this from pTarget inputs
		void disconnect(Node* _pTarget);

		const List<EdgeType>& inputs() const { return m_inputs; }
		List<EdgeType>& inputs() { return m_inputs; }

		const List<EdgeType>& outputs() const { return m_outputs; }
		List<EdgeType>& outputs() { return m_outputs; }

		const N& data() const { return m_data; }
		N& data() { return m_data; }

		typename List<EdgeType>::Iterator remove_input(const Node* _pNode);
		typename List<EdgeType>::Iterator remove_output(const Node* _pNode);

	private:
		N m_data{};

		List<EdgeType> m_inputs;
		List<EdgeType> m_outputs;
	};

	template<class N, class E>
	inline Node<N, E>::Node(Node<N,E>&& _other) noexcept :
		m_data(stdrep::move(_other.m_data)),
		m_inputs(stdrep::move(_other.m_inputs)),
		m_outputs(stdrep::move(_other.m_outputs))
	{
	}

	template<class N, class E>
	inline constexpr Node<N, E>::Node(IAllocator* _pAllocator) :
		m_inputs(_pAllocator),
		m_outputs(_pAllocator)
	{
	}

	template<class N, class E>
	inline Node<N, E>& Node<N, E>::operator=(Node<N, E>&& _other) noexcept
	{
		if (this == &_other) return this;

		m_data = stdrep::move(_other.m_data);
		m_inputs = stdrep::move(_other.m_inputs);
		m_outputs = stdrep::move(_other.m_outputs);

		return *this;
	}

	template<class N, class E>
	inline typename List<typename Node<N, E>::EdgeType>::Iterator Node<N, E>::remove_input(const Node* _pNode)
	{
		auto it = m_inputs.find_if([_pNode](const auto& e) {return e.pTarget == _pNode; });
		if (it != nullptr)
		{
			return m_inputs.erase(it);
		}
		return it;
	}

	template<class N, class E>
	inline typename List<typename Node<N, E>::EdgeType>::Iterator Node<N, E>::remove_output(const Node* _pNode)
	{
		auto it = m_outputs.find_if([_pNode](const auto& e) {return e.pTarget == _pNode; });
		if (it != nullptr)
		{
			return m_outputs.erase(it);
		}
		return it;
	}

	template<class N, class E>
	template<class ...Args>
	inline constexpr Node<N, E>::Node(IAllocator* _pAllocator, Args&& ..._args) :
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

	template<class N, class E>
	inline void Node<N, E>::disconnect(Node* _pTarget)
	{
		remove_output(_pTarget);
		_pTarget->remove_input(this);
	}
} // spvgentwo