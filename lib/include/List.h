#pragma once

#include "EntryIterator.h"

namespace spvgentwo
{
	// forward decls
	class IAllocator;

	template <class T>
	class List
	{
	public:
		using Iterator = EntryIterator<T>;
		using EntryType = Entry<T>;
		using ValueType = T;
		using ReferenceType = T &;
		using PointerType = T *;

		List(IAllocator* _pAllocator);
		~List();

		IAllocator* getAllocator() { return m_pAllocator; }
		const IAllocator* getAllocator() const { return m_pAllocator; }

		// emplace at the end of the linked list
		template<class ...Args>
		Entry<T>* emplace_back(Args&& ..._args);

		// insert new entry before this entry
		//template<class ...Args>
		//Entry<T>* insert(Args&& ..._args);

		Iterator begin() const { return Iterator(m_pOperands); }
		Iterator end() const { return Iterator(nullptr); }

		Entry<T>& front() { return *m_pBegin; }
		const Entry<T>& front() const { return *m_pBegin; }

		Entry<T>& back() { return *m_pLast; }
		const Entry<T>& back() const { return *m_pLast; }

	protected:
		IAllocator* m_pAllocator = nullptr;
		Entry<T>* m_pBegin = nullptr;
		Entry<T>* m_pLast = nullptr;
	};

	template<class T>
	inline List<T>::List(IAllocator* _pAllocator) : m_pAllocator(_pAllocator)
	{
	}

	template<class T>
	inline List<T>::~List()
	{
		if (m_pBegin != nullptr && m_pAllocator != nullptr)
		{
			m_pBegin->destroyList(m_pAllocator);
			m_pBegin = nullptr;
		}
		m_pAllocator = nullptr;
	}

	template<class T>
	template<class ...Args>
	inline Entry<T>* List<T>::emplace_back(Args&& ..._args)
	{
		if (m_pBegin == nullptr)
		{
			m_pBegin = Entry<T>::create(m_pAllocator, static_cast<Args&&>(_args)...);
			m_pLast = m_pBegin;
		}
		else
		{
			m_pLast = m_pLast->emplace_back(m_pAllocator, static_cast<Args&&>(_args)...);
		}
		return m_pLast;
	}
} // !spvgentwo