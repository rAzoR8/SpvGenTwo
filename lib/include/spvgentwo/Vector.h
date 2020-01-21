#pragma once

#include "Allocator.h"

namespace spvgentwo
{
	template <class U>
	class Vector
	{
	public:
		using T = typename stdrep::remove_cv_t<U>;

		Vector(IAllocator* _pAllocator = nullptr, size_t _size = 0u);

		// copy from array
		Vector(IAllocator* _pAllocator, const T* _pData, size_t _size = 0u);

		template <size_t Size>
		Vector(IAllocator* _pAllocator, const T(&_array)[Size]);

		Vector(Vector<U>&& _other) noexcept;

		Vector(const Vector<U>& _other);

		virtual ~Vector();

		Vector<U>& operator=(Vector<U>&& _other) noexcept;

		Vector<U>& operator=(const Vector<U>& _other);

		T& operator[](size_t _idx);
		const T& operator[](size_t _idx) const;

		// reserve can only grow
		bool reserve(size_t _size);

		// resize calls {} constructor on new elements
		bool resize(size_t _size);

		// only destructs, does not deallocate
		void clear();

		T* data() const noexcept{ return m_pData; }
		size_t size() const noexcept { return m_elements; }

		T* begin() const noexcept { return m_pData; }
		T* end() const noexcept { return m_pData + m_elements; }

		T& front() { return *m_pData; }
		const T& front() const{ return *m_pData; }
		
		T& back() { return m_pData[m_elements-1u]; }
		const T& back() const { return m_pData[m_elements-1u]; }

		template <class ...Args>
		T* emplace_back(Args&& ..._args);

		bool empty() const { return m_elements == 0; }

	protected:
		void deallocate();

	protected:
		IAllocator* m_pAllocator = nullptr;

		T* m_pData = nullptr;
		size_t m_elements = 0u;
		size_t m_capacity = 0u;
	};

	template<class U>
	inline Vector<U>::Vector(IAllocator* _pAllocator, size_t _size) :
		m_pAllocator(_pAllocator)
	{
		reserve(_size)
	}

	template<class U>
	inline Vector<U>::Vector(IAllocator* _pAllocator, const T* _pData, size_t _size) :
		m_pAllocator(_pAllocator)
	{
		if (reserve(_size))
		{
			// copy construct
			for (size_t i = 0u; i < _size; ++i)
			{
				traits::constructWithArgs(m_pData + i, _pData[i]);
			}

			m_elements = _size;
		}
	}

	template<class U>
	inline Vector<U>::Vector(Vector<U>&& _other) noexcept :
		m_pAllocator(_other.m_pAllocator),
		m_pData(_other.m_pData),
		m_elements(_other.m_elements),
		m_capacity(_other.m_capacity)
	{
		_other.m_pAllocator = nullptr;
		_other.m_pData = nullptr;
		_other.m_elements = 0u;
		_other.m_capacity = 0u;
	}

	template<class U>
	inline Vector<U>::Vector(const Vector<U>& _other) : Vector(_other.m_pAllocator, _other.m_pData, _other.m_elements)	{}

	template<class U>
	inline Vector<U>::~Vector()
	{
		clear(); // destruct

		deallocate(); // free memory / return to allocator
	}

	template<class U>
	inline Vector<U>& Vector<U>::operator=(Vector<U>&& _other) noexcept
	{
		if (this == &_other) return *this;

		// destruct left side
		clear();
		deallocate();

		// take over right side
		m_pAllocator = _other.m_pAllocator;
		m_pData = _other.m_pData;
		m_elements = _other.m_elements;
		m_capacity = _other.m_capacity;

		// reset right side
		_other.m_pAllocator = nullptr;
		_other.m_pData = nullptr;
		_other.m_elements = 0u;
		_other.m_capacity = 0u;

		return *this;
	}

	template<class U>
	inline Vector<U>& Vector<U>::operator=(const Vector<U>& _other)
	{
		if (this == &_other) return *this;

		if (reserve(_other.m_elements))
		{
			for (size_t i = 0u; i < _other.m_elements; ++i)
			{
				m_pData[i] = _other.m_pData[i];
			}

			m_elements = _other.m_elements;
		}

		return *this;
	}

	template<class U>
	inline typename Vector<U>::T& Vector<U>::operator[](size_t _idx)
	{
		return m_pData[_idx];
	}

	template<class U>
	inline const typename Vector<U>::T& Vector<U>::operator[](size_t _idx) const
	{
		return m_pData[_idx];
	}

	template<class U>
	inline bool Vector<U>::reserve(size_t _size)
	{
		if (m_capacity >= _size)
		{
			return true;
		}

		if (m_pAllocator == nullptr)
		{
			return false;
		}

		T* pNewData = reinterpret_cast<T*>(m_pAllocator->allocate(_size * sizeof(T)));

		if (pNewData == nullptr)
		{
			return false;
		}

		//  move or copy old to new data (if any)
		for (size_t i = 0u; i < m_elements; ++i)
		{
			if constexpr (stdrep::is_constructible_v<T, stdrep::remove_reference_t<T>&&>) // move constructible
			{
				new(pNewData + i) T(stdrep::move(m_pData[i]));
			}
			else if constexpr(stdrep::is_constructible_v<T, const stdrep::remove_reference_t<T>&>) // copy constructible
			{
				new(pNewData + i) T(m_pData[i]);
			}
			else // aggregate init
			{
				new(pNewData + i) T{m_pData[i]};
			}
		}

		// free old data
		if (m_pData != nullptr)
		{
			m_pAllocator->deallocate(m_pData, m_capacity * sizeof(T));
		}

		m_pData = pNewData;
		m_capacity = _size;  // number of elements does not change

		return true;
	}

	template<class U>
	inline bool Vector<U>::resize(size_t _size)
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

	template<class U>
	inline void Vector<U>::clear()
	{
		// call destructor (TODO: if there is one)
		for (size_t i = 0; i < m_elements; ++i)
		{
			m_pData[i].~T();
		}

		m_elements = 0u;
	}

	template<class U>
	inline void Vector<U>::deallocate()
	{
		if (m_pAllocator != nullptr && m_pData != nullptr)
		{
			m_pAllocator->deallocate(m_pData, m_capacity * sizeof(T));
			m_capacity = 0u;
			m_pData = nullptr;
		}
	}

	template<class U>
	template<size_t Size>
	inline Vector<U>::Vector(IAllocator* _pAllocator, const T(&_array)[Size]) : Vector(_pAllocator, _array, Size){}

	template<class U>
	template<class ...Args>
	inline typename Vector<U>::T* Vector<U>::emplace_back(Args&& ..._args)
	{
		// we ran out of capacity, reallocate
		if (m_elements >= m_capacity)
		{
			// grow by factor 1.25 + 1
			if (reserve(m_capacity + 1u + (m_capacity >> 2)) == false)
			{
				return nullptr;
			}
		}

		return traits::constructWithArgs(m_pData + m_elements++, stdrep::forward<Args>(_args)...);
	}

} // !spvgentwo