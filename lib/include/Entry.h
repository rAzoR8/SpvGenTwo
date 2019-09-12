#pragma once
#include "Allocator.h"

namespace spvgentwo
{
	template <class T>
	class Entry
	{
	public:
		template <class ...Args>
		Entry(Args&& ..._args);
		~Entry();

		template<class ...Args>
		static Entry* create(IAllocator* _pAlloc, Args&& ..._args);

		// emplace at the end of the linked list
		template<class ...Args>
		Entry* emplace_back(IAllocator* _pAlloc, Args&& ..._args);

		// insert new entry before this entry
		template<class ...Args>
		Entry* insert(IAllocator* _pAlloc, Args&& ..._args);

		// removes this entry from the list (and destroys it if allocator is provieded), returns next entry
		Entry* remove(IAllocator* _pAllo);

		Entry* last();

		void destroyList(IAllocator* _pAlloc);

		bool operator==(const Entry<T>& _other) const;
		bool operator!=(const Entry<T>& _other) const;

		T& inner() { return m_data; }
		const T& inner() const { return m_data; }

		T& operator*() { return m_data; }
		const T& operator*() const { return m_data; }

		T* operator->() { return &m_data; }
		const T* operator->() const { return &m_data; }

	private:
		T m_data;
		Entry* m_pPrev = nullptr;
		Entry* m_pNext = nullptr;
	};

	template<class T>
	template<class ...Args>
	inline Entry<T>::Entry(Args&& ..._args) :
		m_data(static_cast<Args&&>(_args)...)
	{
	}

	template<class T>
	inline Entry<T>::~Entry()
	{		
	}

	template<class T>
	template<class ...Args>
	inline Entry<T>* Entry<T>::create(IAllocator* _pAlloc, Args&& ..._args)
	{
		return _pAlloc->construct<Entry<T>>(std::forward<Args>(_args)...);
	}

	template<class T>
	template<class ...Args>
	inline Entry<T>* Entry<T>::emplace_back(IAllocator* _pAlloc, Args&& ..._args)
	{
		if (m_pNext == nullptr)
		{
			m_pNext = _pAlloc->construct<Entry<T>>(static_cast<Args&&>(_args)...);	
			if (m_pNext != nullptr)
			{
				m_pNext->m_pPrev = this;
			}
			return m_pNext;
		}
		else
		{
			return last()->emplace_back(_pAlloc, static_cast<Args&&>(_args)...);
		}
	}

	template<class T>
	template<class ...Args>
	inline Entry<T>* Entry<T>::insert(IAllocator* _pAlloc, Args&& ..._args)
	{
		Entry<T>* entry = create(_pAlloc, static_cast<Args&&>(_args)...);

		if (entry == nullptr)
		{
			return nullptr;
		}

		if (m_pPrev != nullptr)
		{
			m_pPrev->m_pNext = entry;
		}

		entry->m_pPrev = m_pPrev;
		entry->m_pNext = this;
		
		return entry;
	}
	template<class T>
	inline Entry<T>* Entry<T>::remove(IAllocator* _pAlloc)
	{
		Entry<T>* next = m_pNext;

		if (m_pPrev != nullptr)
		{
			m_pPrev->m_pNext = next;
		}

		if (next != nullptr)
		{
			next->m_pPrev = m_pPrev;
		}

		if (_pAlloc != nullptr)
		{
			_pAlloc->destruct(this);
		}

		return next;
	}
	template<class T>
	inline Entry<T>* Entry<T>::last()
	{
		Entry<T>* next = this;
		while (true){
			if (next->m_pNext == nullptr) { return next; }
			next = next->m_pNext;
		}
	}

	template<class T>
	inline void Entry<T>::destroyList(IAllocator* _pAlloc)
	{
		Entry<T>* entry = this;

		while (entry != nullptr)
		{
			Entry<T>* next = entry->m_pNext;

			entry->~Entry();
			_pAlloc->deallocate(entry);

			entry = next;
		}
	}
	template<class T>
	inline bool Entry<T>::operator==(const Entry<T>& _other) const
	{
		return this == &_other;
	}
	template<class T>
	inline bool Entry<T>::operator!=(const Entry<T>& _other) const
	{
		return this != &_other;
	}
} // !spvgentwo