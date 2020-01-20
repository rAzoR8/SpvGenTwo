#pragma once

#include "Allocator.h"

namespace spvgentwo
{
	template <class T>
	class Vector
	{
	public:
		Vector(IAllocator* _pAllocator = nullptr, size_t _size = 0);
		// TODO: copy & asignment etc

		virtual ~Vector();

		// reserve can only grow
		bool reserve(size_t _size);
		bool resize(size_t _size);

		// only destructs, does not deallocate
		void clear();

		T* data() const { return m_pData; }
		size_t size() const { return m_elements; }

		T* begin() const { return m_pData; }
		T* end() const { return m_pData + m_elements; }

	private:
		IAllocator* m_pAllocator = nullptr;

		T* m_pData = nullptr;
		size_t m_elements = 0u;
		size_t m_capacity = 0u;
	};

	template<class T>
	inline Vector<T>::Vector(IAllocator* _pAllocator, size_t _size) :
		m_pAllocator(_pAllocator)
	{
		reserve(_size)
	}

	template<class T>
	inline Vector<T>::~Vector()
	{
		clear();

		// dealloc data
		if (m_pAllocator != nullptr && m_pData != nullptr)
		{
			m_pAllocator->deallocate(m_pData, m_capacity * sizeof(T));
			m_capacity = 0u;
			m_pData = nullptr;
		}
	}

	template<class T>
	inline bool Vector<T>::reserve(size_t _size)
	{
		if (m_capacity >= _size)
		{
			return true;
		}

		if (m_pAllocator == nullptr)
		{
			return false;
		}

		const size_t oldByteSize = m_elements * sizeof(T);
		const size_t newByteSize = _size * sizeof(T);
		unsigned char* newDataBytes = m_pAllocator->allocate(newByteSize);

		if (newDataBytes == nullptr)
		{
			return false;
		}

		const unsigned char* oldDataBytes = reinterpret_cast<unsigned char*>(newData);

		// 'memcpy' old to new data, no destructor or move called
		for (size_t i = 0u; i < oldByteSize; ++i)
		{
			newDataBytes[i] = oldDataBytes[i];
		}

		// free old data
		m_pAllocator->deallocate(m_pData, m_capacity * sizeof(T));

		m_pData = reinterpret_cast<T*>(newDataBytes);
		m_capacity = _size;  // number of elements does not change

		return true;
	}

	template<class T>
	inline bool Vector<T>::resize(size_t _size)
	{
		if (_size > m_capacity)
		{
			if (reserve(_size) == false)
			{
				return false;
			}

			for (size_t i = m_elements; i < m_capacity; ++i)
			{
				new(m_pData[i]) T{};
			}
		}
		else if (_size < m_elements) // shrink
		{
			// destruct shrinke elements
			for (size_t i = _size; i < m_elements; ++i)
			{
				m_pData[i].~T();
			}
		}

		m_elements = m_capacity;

		return true;
	}

	template<class T>
	inline void Vector<T>::clear()
	{
		// call destructor (TODO: if there is one)
		for (size_t i = 0; i < m_elements; ++i)
		{
			m_pData[i].~T();
		}

		m_elements = 0u;
	}

} // !spvgentwo