#pragma once

#include "Entry.h"

namespace spvgentwo
{
	template <class T>
	class EntryIterator
	{
	public:
		constexpr EntryIterator(Entry<T>* _pEntry = nullptr) : m_pEntry(_pEntry) {}
		constexpr EntryIterator(const EntryIterator<T>& _other) : m_pEntry(_other.m_pEntry) {}

		constexpr EntryIterator& operator=(const EntryIterator<T>& _other);

		constexpr bool operator==(const EntryIterator<T>& _other) const;
		constexpr bool operator!=(const EntryIterator<T>& _other) const;

		constexpr bool operator==(sgt_nullptr_t) const;
		constexpr bool operator!=(sgt_nullptr_t) const;

		constexpr EntryIterator<T> operator+(unsigned int n) const;
		constexpr EntryIterator<T> operator-(unsigned int n) const;

		constexpr EntryIterator<T> prev() const;
		constexpr EntryIterator<T> next() const;

		// pre
		constexpr EntryIterator<T>& operator++();
		constexpr EntryIterator<T>& operator--();

		// post
		constexpr EntryIterator<T> operator++(int);
		constexpr EntryIterator<T> operator--(int);

		constexpr T& operator*() { return m_pEntry->inner(); }
		constexpr const T& operator*() const { return m_pEntry->inner(); }

		constexpr T* operator->() { return m_pEntry->operator->(); }
		constexpr const T* operator->() const { return m_pEntry->operator->(); }

		constexpr Entry<T>* entry() const { return m_pEntry; }

		constexpr operator Entry<T>* () const { return m_pEntry; }

	private:
		Entry<T>* m_pEntry = nullptr;
	};

	template <class Iterator>
	struct Range
	{
		Iterator m_Begin;
		Iterator m_End;

		constexpr Iterator begin() const { return m_Begin; }
		constexpr Iterator end() const { return m_End; }

		constexpr bool empty() const { return m_Begin == m_End; }
	};

	template<class T>
	inline constexpr EntryIterator<T>& EntryIterator<T>::operator=(const EntryIterator<T>& _other)
	{
		m_pEntry = _other.m_pEntry;
		return *this;
	}

	template<class T>
	inline constexpr bool EntryIterator<T>::operator==(const EntryIterator<T>& _other) const
	{
		return m_pEntry == _other.m_pEntry;
	}

	template<class T>
	inline constexpr bool EntryIterator<T>::operator!=(const EntryIterator<T>& _other) const
	{
		return m_pEntry != _other.m_pEntry;
	}

	template<class T>
	inline constexpr bool EntryIterator<T>::operator==(sgt_nullptr_t) const
	{
		return m_pEntry == nullptr;
	}

	template<class T>
	inline constexpr bool EntryIterator<T>::operator!=(sgt_nullptr_t) const
	{
		return m_pEntry != nullptr;
	}

	template<class T>
	inline  constexpr EntryIterator<T>& EntryIterator<T>::operator++()
	{
		if(m_pEntry != nullptr) m_pEntry = m_pEntry->next();
		return *this;
	}
	template<class T>
	inline constexpr EntryIterator<T>& EntryIterator<T>::operator--()
	{
		if (m_pEntry != nullptr) m_pEntry = m_pEntry->prev();
		return *this;
	}
	template<class T>
	inline constexpr EntryIterator<T> EntryIterator<T>::operator++(int)
	{
		EntryIterator<T> ret(m_pEntry);
		if (m_pEntry != nullptr) m_pEntry = m_pEntry->next();
		return ret;
	}

	template<class T>
	inline constexpr EntryIterator<T> EntryIterator<T>::operator--(int)
	{
		EntryIterator<T> ret(m_pEntry);
		if (m_pEntry != nullptr) m_pEntry = m_pEntry->prev();
		return ret;
	}

	template<class T>
	inline constexpr EntryIterator<T> EntryIterator<T>::operator+(unsigned int n) const
	{
		EntryIterator<T> ret(m_pEntry);
		for (unsigned int i = 0; i < n && ret != nullptr; ++i, ++ret) {}
		return ret;
	}

	template<class T>
	inline constexpr EntryIterator<T> EntryIterator<T>::operator-(unsigned int n) const
	{
		EntryIterator<T> ret(m_pEntry);
		for (unsigned int i = 0; i < n && ret != nullptr; ++i, --ret) {}
		return ret;
	}

	template<class T>
	inline constexpr EntryIterator<T> EntryIterator<T>::prev() const
	{
		EntryIterator<T> ret(m_pEntry); --ret;
		return ret;
	}

	template<class T>
	inline constexpr EntryIterator<T> EntryIterator<T>::next() const
	{
		EntryIterator<T> ret(m_pEntry); ++ret;
		return ret;
	}
} // !spvgentwo