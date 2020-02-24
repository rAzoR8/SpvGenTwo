#pragma once

#include "spvgentwo/List.h"

namespace spvgentwo
{
	class IAllocator;

	// N = node data, E = edge data
	template <class N, class E>
	class Node
	{
	public:
		struct Edge
		{
			Node* pTarget;
			E data;
		};

		Node(IAllocator* _pAllocator = nullptr);

		template <class ...Args>
		Node(IAllocator* _pAllocator, Args&& ... _args);

		template <class ...EdgeArgs>
		void connect(Node* _pTarget, EdgeArgs&& ..._args);

		const List<Edge>& inputs() const { return m_inputs; }
		List<Edge>& inputs() { return m_inputs; }

		const List<Edge>& outputs() const { return m_outputs; }
		List<Edge>& output() { return m_outputs; }

		const N& data() const { return m_data(); }
		N& data() { return m_data(); }

	private:
		N m_data;

		List<Edge> m_inputs;
		List<Edge> m_outputs;
	};

	template<class N, class E>
	inline Node<N, E>::Node(IAllocator* _pAllocator) :
		m_inputs(_pAllocator),
		m_outputs(_pAllocator)
	{
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