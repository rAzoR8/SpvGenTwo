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
		List(const List& _other);
		List(List&& _other);
		~List();

		List& operator=(const List& _other);
		List& operator=(List&& _other);

		IAllocator* getAllocator() { return m_pAllocator; }
		const IAllocator* getAllocator() const { return m_pAllocator; }

		template<class ...Args>
		Entry<T>* emplace_back_entry(Args&& ..._args);

		// emplace at the end of the linked list
		template<class ...Args>
		T& emplace_back(Args&& ..._args);

		// insert new entry before this entry
		//template<class ...Args>
		//Entry<T>* insert(Args&& ..._args);

		Iterator begin() const { return Iterator(m_pOperands); }
		Iterator end() const { return Iterator(nullptr); }

		T& front() { return m_pBegin->inner(); }
		const T& front() const { return m_pBegin->inner(); }

		T& back() { return m_pLast->inner(); }
		const T& back() const { return m_pLast->inner(); }

		bool empty() const { return m_pBegin != nullptr; }

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
	inline List<T>::List(const List& _other) :
		m_pAllocator(_other.m_pAllocator)
	{
		for (const T& e : _other)
		{
			emplace_back(e);
		}
	}

	template<class T>
	inline List<T>::List(List&& _other) :
		m_pAllocator(_other.m_pAllocator),
		m_pBegin(_other.m_pBegin),
		m_pLast(_other.m_pLast)
	{
		_other.m_pAllocator = nullptr;
		_other.m_pBegin = nullptr;
		_other.m_pLast = nullptr;
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
	inline List<T>& List<T>::operator=(const List<T>& _other)
	{
		if (this == &_other) return *this;

		Iterator l = begin(), le = end(), r = _other.begin(), re = _other.end();
		for (; l != le && r != re; ++l, ++r)
		{
			(*l).m_data = (*r).m_data;
		}

		// left side was longer, destroy rest
		if(l != le)
		{
			(*l).destroyList(m_pAllocator);
		}

		// right side was longer, emplace
		for (; r != re; ++r)
		{
			emplace_back((*r).m_data);
		}

		return *this;
	}

	template<class T>
	inline List<T>& List<T>::operator=(List<T>&& _other)
	{
		if (this == &_other) return this;

		// destroy left side
		if (m_pBegin != nullptr && m_pAllocator != nullptr)
		{
			m_pBegin->destroyList(m_pAllocator);
		}

		// assign right side
		m_pAllocator = _other.m_pAllocator;
		m_pBegin = _other.m_pBegin;
		m_pLast = _other.m_pLast;

		_other.m_pAllocator = nullptr;
		_other.m_pBegin = nullptr;
		_other.m_pLast = nullptr;

		return *this;
	}

	template<class T>
	template<class ...Args>
	inline Entry<T>* List<T>::emplace_back_entry(Args&& ..._args)
	{
		if (m_pBegin == nullptr)
		{
			m_pBegin = Entry<T>::create(m_pAllocator, forward<Args>(_args)...);
			m_pLast = m_pBegin;
		}
		else
		{
			m_pLast = m_pLast->emplace_back(m_pAllocator, forward<Args>(_args)...);
		}
		return m_pLast;
	}

	template<class T>
	template<class ...Args>
	inline T& List<T>::emplace_back(Args&& ..._args)
	{
		return **emplace_back_entry(forward<Args>(_args)...);
	}
} // !spvgentwo