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

		constexpr List(IAllocator* _pAllocator = nullptr);
		List(const List& _other);
		constexpr List(List&& _other) noexcept;

		// construct from variadic argument list of T: List l(instr1, instr2, instr3)
		template <class ...Args> // args must be of type T
		List(IAllocator* _pAllocator, T&& _first, Args&& ... _args);

		virtual ~List();

		List& operator=(const List& _other);
		List& operator=(List&& _other) noexcept;

		constexpr bool operator==(const List<T>&  other) const;
		constexpr bool operator!=(const List<T>& _other) const { return !operator==(_other); }

		constexpr IAllocator* getAllocator()  const { return m_pAllocator; }

		// set allocator if non was set earlier
		void setAllocator(IAllocator* _pAllocator);

		void clear(); // destroy entries

		template<class ...Args>
		Entry<T>* emplace_front_entry(Args&& ..._args);

		template<class ...Args>
		T& emplace_front(Args&& ..._args);

		template<class ...Args>
		Entry<T>* emplace_back_entry(Args&& ..._args);

		Entry<T>* prepend_entry(Entry<T>* _entry);

		// adds _entry to the end of the chain, returns same entry
		Entry<T>* append_entry(Entry<T>* _entry);

		// emplace at the end of the linked list
		template<class ...Args>
		T& emplace_back(Args&& ..._args);

		// insert new entry before this entry
		template<class ...Args>
		Entry<T>* insert_before(Iterator _pos, Args&& ..._args);

		// insert new entry before this entry
		template<class ...Args>
		Entry<T>* insert_after(Iterator _pos, Args&& ..._args);

		// removes element at pos from list, returns next element
		Entry<T>* erase(Iterator _pos, const bool _destruct = true);

		T pop_back();
		T pop_front();

		constexpr Iterator begin() const { return Iterator(m_pBegin); }
		constexpr Iterator end() const { return Iterator(nullptr); }
		constexpr Iterator last() const { return Iterator(m_pLast); }

		constexpr T& front() const { return m_pBegin->inner(); }

		constexpr T& back() const { return m_pLast->inner(); }

		constexpr Entry<T>* lastEntry() const { return m_pLast; }

		constexpr bool empty() const { return m_pBegin == nullptr; }

		constexpr sgt_size_t size() const { return m_Elements; }

		template <class Comparable>
		constexpr Iterator find(const Comparable& _val) const;

		template<class _Pred>
		constexpr Iterator find_if(const _Pred& _pred) const;

		template <class Comparable>
		constexpr bool contains(const Comparable& _val) const { return find(_val) != nullptr; }

	protected:
		Entry<T>* m_pBegin = nullptr;
		Entry<T>* m_pLast = nullptr;
		sgt_size_t m_Elements = 0u;
		IAllocator* m_pAllocator = nullptr;
	};

	template<class T>
	inline constexpr List<T>::List(IAllocator* _pAllocator) : m_pAllocator(_pAllocator)
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
	inline constexpr List<T>::List(List&& _other) noexcept:
		m_pBegin(_other.m_pBegin),
		m_pLast(_other.m_pLast),
		m_Elements(_other.m_Elements),
		m_pAllocator(_other.m_pAllocator)
	{
		_other.m_pAllocator = nullptr;
		_other.m_pBegin = nullptr;
		_other.m_pLast = nullptr;
		_other.m_Elements = 0u;
	}

	template<class T>
	template<class ...Args>
	inline List<T>::List(IAllocator* _pAllocator, T&& _first, Args&& ..._args) : m_pAllocator(_pAllocator)
	{
		emplace_back(stdrep::forward<T>(_first));

		if constexpr (sizeof...(_args) > 0)
		{
			(emplace_back(stdrep::forward<Args>(_args)), ...);
		}
	}

	template<class T>
	inline List<T>::~List()
	{
		clear();
		m_pAllocator = nullptr;
	}

	template<class T>
	inline void List<T>::setAllocator(IAllocator* _pAllocator)
	{
		if (m_pAllocator == nullptr)
		{
			m_pAllocator = _pAllocator;
		}
	}

	template<class T>
	inline void List<T>::clear()
	{
		if (m_pBegin != nullptr && m_pAllocator != nullptr)
		{
			m_pBegin->destroyList(m_pAllocator);
			m_pBegin = nullptr;
			m_pLast = nullptr;
			m_Elements = 0u;
		}
	}

	template<class T>
	inline List<T>& List<T>::operator=(const List<T>& _other)
	{
		if (this == &_other) return *this;

		Iterator l = begin(), le = end(), r = _other.begin(), re = _other.end();
		for (; l != le && r != re; ++l, ++r)
		{
			(*l) = (*r);
		}

		// left side was longer, destroy rest
		if(l != le)
		{
			l.entry()->destroyList(m_pAllocator);
		}

		// right side was longer, emplace
		for (; r != re; ++r)
		{
			emplace_back(*r);
		}

		m_Elements = _other.m_Elements;
		return *this;
	}

	template<class T>
	inline List<T>& List<T>::operator=(List<T>&& _other) noexcept
	{
		if (this == &_other) return *this;

		// destroy left side
		if (m_pBegin != nullptr && m_pAllocator != nullptr)
		{
			m_pBegin->destroyList(m_pAllocator);
		}

		// assign right side
		m_pAllocator = _other.m_pAllocator;
		m_pBegin = _other.m_pBegin;
		m_pLast = _other.m_pLast;
		m_Elements = _other.m_Elements;

		_other.m_pAllocator = nullptr;
		_other.m_pBegin = nullptr;
		_other.m_pLast = nullptr;
		_other.m_Elements = 0u;

		return *this;
	}

	template <class T>
	constexpr bool List<T>::operator==(const List<T>& _other) const
	{
		Iterator l = begin(), le = end(), r = _other.begin(), re = _other.end();
		for (; l != le && r != re; ++l, ++r)
		{
			if ((*l) != (*r)) return false;
		}

		// check if both list are at the end (same length)
		return l == le && r == re;
	}

	template<class T>
	inline Entry<T>* List<T>::prepend_entry(Entry<T>* _entry)
	{
		if (m_pBegin == nullptr)
		{
			m_pBegin = _entry;
			m_pLast = m_pBegin;
		}
		else
		{
			m_pBegin = m_pBegin->prepend(_entry);
		}
		++m_Elements;
		return m_pBegin;
	}

	template<class T>
	inline Entry<T>* List<T>::append_entry(Entry<T>* _entry)
	{
		if (m_pBegin == nullptr)
		{
			m_pBegin = _entry;
			m_pLast = m_pBegin;
		}
		else
		{
			m_pLast = m_pLast->append(_entry);
		}
		++m_Elements;
		return m_pLast;
	}

	template<class T>
	template<class ...Args>
	inline Entry<T>* List<T>::emplace_front_entry(Args&& ..._args)
	{
		return prepend_entry(Entry<T>::create(m_pAllocator, stdrep::forward<Args>(_args)...));
	}

	template<class T>
	template<class ...Args>
	inline Entry<T>* List<T>::emplace_back_entry(Args&& ..._args)
	{
		return append_entry(Entry<T>::create(m_pAllocator, stdrep::forward<Args>(_args)...));
	}

	template<class T>
	template<class ...Args>
	inline T& List<T>::emplace_front(Args&& ..._args)
	{
		return **emplace_front_entry(stdrep::forward<Args>(_args)...);
	}

	template<class T>
	template<class ...Args>
	inline T& List<T>::emplace_back(Args&& ..._args)
	{
		return **emplace_back_entry(stdrep::forward<Args>(_args)...);
	}

	template<class T>
	template<class ...Args>
	inline Entry<T>* List<T>::insert_before(Iterator _pos, Args&& ..._args)
	{
		++m_Elements;
		Entry<T>* entry = _pos.entry()->insertBefore(m_pAllocator, stdrep::forward<Args>(_args)...);
		if (_pos.entry() == m_pBegin)
		{
			m_pBegin = entry;
		}
		return entry;
	}

	template<class T>
	template<class ...Args>
	inline Entry<T>* List<T>::insert_after(Iterator _pos, Args&& ..._args)
	{
		++m_Elements;
		Entry<T>* entry = _pos.entry()->insertAfter(m_pAllocator, stdrep::forward<Args>(_args)...);
		if (_pos.entry() == m_pLast)
		{
			m_pLast = entry;
		}
		return entry;
	}

	template<class T>
	inline T List<T>::pop_back()
	{
		T ret(back());
		if (--m_Elements == 0u) m_pBegin = nullptr;
		auto prev = m_pLast->prev();
		m_pLast->remove(m_pAllocator);
		m_pLast = prev;
		return ret;
	}

	template<class T>
	inline T List<T>::pop_front()
	{
		T ret(front());
		if (--m_Elements == 0u) m_pLast = nullptr;
		auto next = m_pBegin->next();
		m_pBegin->remove(m_pAllocator);
		m_pBegin = next;
		return ret;
	}

	template<class T>
	inline Entry<T>* List<T>::erase(Iterator _pos, const bool _destruct)
	{
		--m_Elements;

		if (_pos.entry() == m_pLast)
		{
			m_pLast = m_pLast->prev();
		}
		if (_pos.entry() == m_pBegin)
		{
			m_pBegin = m_pBegin->next();
		}	

		return _pos.entry()->remove(_destruct ? m_pAllocator : nullptr);
	}

	template<class T>
	template<class Comparable>
	inline constexpr typename List<T>::Iterator List<T>::find(const Comparable& _val) const
	{
		auto it = begin();
		for (; it != nullptr && !(*it == _val); ++it) {}
		return it;
	}

	template<class T>
	template<class _Pred>
	inline constexpr typename List<T>::Iterator List<T>::find_if(const _Pred& _pred) const
	{
		auto it = begin();
		for (; it != nullptr && !_pred(*it); ++it) {}
		return it;
	}
} // !spvgentwo