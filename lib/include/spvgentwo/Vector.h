#pragma once

#include "Allocator.h"

namespace spvgentwo
{
	template <class U>
	class Vector
	{
	public:
		using T = typename stdrep::remove_cv_t<U>;
		using Iterator = T*;
		using ValueType = T;
		using ReferenceType = T&;
		using PointerType = T*;

		constexpr Vector(IAllocator* _pAllocator = nullptr);

		Vector(IAllocator* _pAllocator, sgt_size_t _size);

		// copy from array
		Vector(IAllocator* _pAllocator, const T* _pData, sgt_size_t _size = 0u);

		template <sgt_size_t Size>
		Vector(IAllocator* _pAllocator, const T(&_array)[Size]);

		constexpr Vector(Vector<U>&& _other) noexcept;

		Vector(const Vector<U>& _other);

		template <typename ...Args>
		Vector(IAllocator* _pAllocator, const T& _first, Args&& ... _args);

		virtual ~Vector();

		Vector<U>& operator=(Vector<U>&& _other) noexcept;

		Vector<U>& operator=(const Vector<U>& _other);

		template <sgt_size_t N>
		Vector<U>& operator=(const T(&_data)[N]);

		constexpr IAllocator* getAllocator() const { return m_pAllocator; }

		constexpr T& operator[](sgt_size_t _idx) { return m_pData[_idx]; };
		constexpr const T& operator[](sgt_size_t _idx) const { return m_pData[_idx]; }

		// reserve can only grow, returns false on allocation failure
		bool reserve(sgt_size_t _size);

		// resize calls {} constructor on new elements, returns false on allocation failure
		bool resize(sgt_size_t _size, const T* _pInitValue = nullptr);

		// only destructs, does not deallocate
		void clear();

		constexpr T* data() const noexcept { return m_pData; }
		constexpr sgt_size_t size() const noexcept { return m_elements; }
		constexpr sgt_size_t capacity() const noexcept { return m_capacity; }
		constexpr bool empty() const { return m_elements == 0; }

		constexpr Iterator begin() const noexcept { return m_pData; }
		constexpr Iterator end() const noexcept { return m_pData + m_elements; }

		constexpr T& front() { return *m_pData; }
		constexpr const T& front() const { return *m_pData; }

		constexpr T& back() { return m_pData[m_elements - 1u]; }
		constexpr const T& back() const { return m_pData[m_elements - 1u]; }

		template <class ...Args>
		T* emplace_back(Args&& ..._args);

		// emplace one element per argument
		template <class ...Args>
		void emplace_back_args(const T& _first, Args&& ..._tail);

		// assign _data to elements starting at _pos, _count == max means all
		void assign(const T& _data, sgt_size_t _pos = 0u, sgt_size_t _count = sgt_size_max);

		// insert _count elements from _pData starting at _pos. migt reallocate.
		// returns iterator to first inserted element, or nullptr if _pos is outside the valid range
		Iterator insert(sgt_size_t _pos, const T* _pData, sgt_size_t _count);

		// inserts _data at position _pos
		Iterator insert(sgt_size_t _pos, const T& _data) { return insert(_pos, &_data, 1u); }

		template <sgt_size_t N>
		Iterator insert(sgt_size_t _pos, const T(&_array)[N]) { return insert(_pos, _array, N); }

	protected:
		void deallocate();

	protected:
		IAllocator* m_pAllocator = nullptr;

		T* m_pData = nullptr;
		sgt_size_t m_elements = 0u;
		sgt_size_t m_capacity = 0u;
	};

	template<class U>
	inline constexpr Vector<U>::Vector(IAllocator* _pAllocator) :
		m_pAllocator(_pAllocator)
	{
	}

	template<class U>
	inline Vector<U>::Vector(IAllocator* _pAllocator, sgt_size_t _size) :
		m_pAllocator(_pAllocator)
	{
		reserve(_size);
	}

	template<class U>
	inline Vector<U>::Vector(IAllocator* _pAllocator, const T* _pData, sgt_size_t _size) :
		m_pAllocator(_pAllocator)
	{
		if ( reserve(_size) )
		{
			// copy construct
			for ( sgt_size_t i = 0u; i < _size; ++i )
			{
				traits::constructWithArgs(m_pData + i, _pData[i]);
			}

			m_elements = _size;
		}
	}

	template<class U>
	inline constexpr Vector<U>::Vector(Vector<U>&& _other) noexcept :
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
	inline Vector<U>::Vector(const Vector<U>& _other) : Vector(_other.m_pAllocator, _other.m_pData, _other.m_elements) {}

	template<class U>
	template<typename ...Args>
	inline Vector<U>::Vector(IAllocator* _pAllocator, const T& _first, Args&& ..._args) :
		m_pAllocator(_pAllocator)
	{
		if ( reserve(sizeof...(_args) + 1u) )
		{
			emplace_back_args(_first, stdrep::forward<Args>(_args)...);
		}
	}

	template<class U>
	inline Vector<U>::~Vector()
	{
		clear(); // destruct

		deallocate(); // free memory / return to allocator
	}

	template<class U>
	inline Vector<U>& Vector<U>::operator=(Vector<U>&& _other) noexcept
	{
		if ( this == &_other ) return *this;

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
		if ( this == &_other ) return *this;

		if ( resize(_other.m_elements) )
		{
			for ( sgt_size_t i = 0u; i < _other.m_elements; ++i )
			{
				m_pData[i] = _other.m_pData[i];
			}
		}

		return *this;
	}

	template<class U>
	template<sgt_size_t N>
	inline Vector<U>& Vector<U>::operator=(const T(&_data)[N])
	{
		if ( resize(N) )
		{
			for ( sgt_size_t i = 0u; i < N; ++i )
			{
				m_pData[i] = _data[i];
			}
		}

		return *this;
	}

	template<class U>
	inline bool Vector<U>::reserve(sgt_size_t _size)
	{
		if ( m_capacity >= _size )
		{
			return true;
		}

		if ( m_pAllocator == nullptr )
		{
			return false;
		}

		T* pNewData = static_cast<T*>(m_pAllocator->allocate(_size * sizeof(T), alignof(T)));

		if ( pNewData == nullptr )
		{
			return false;
		}

		if ( m_pData != nullptr )
		{
			//  move or copy old to new data (if any)
			for ( sgt_size_t i = 0u; i < m_elements; ++i )
			{
				traits::constructWithArgs(pNewData + i, stdrep::move(m_pData[i]));
			}

			// free old data
			for ( sgt_size_t i = 0u; i < m_elements; ++i )
			{
				m_pData[i].~T();
			}
			m_pAllocator->deallocate(m_pData, m_capacity * sizeof(T));
		}

		m_pData = pNewData;
		m_capacity = _size;  // number of elements does not change

		return true;
	}

	template<class U>
	inline bool Vector<U>::resize(sgt_size_t _size, const T* _pInitValue)
	{
		if ( _size > m_capacity )
		{
			if ( reserve(_size) == false )
			{
				return false;
			}

			if ( _pInitValue == nullptr || stdrep::is_copy_constructible_v<T> == false )
			{
				for ( sgt_size_t i = m_elements; i < m_capacity; ++i )
				{
					new(m_pData + i) T{};
				}
			}
			else if constexpr ( stdrep::is_copy_constructible_v<T> )
			{
				for ( sgt_size_t i = m_elements; i < m_capacity; ++i )
				{
					new(m_pData + i) T{ *_pInitValue };
				}
			}
		}
		else if ( _size < m_elements ) // shrink
		{
			// destruct shrinke elements
			for ( sgt_size_t i = _size; i < m_elements; ++i )
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
		// call destructor
		for ( sgt_size_t i = 0u; i < m_elements; ++i )
		{
			m_pData[i].~T();
		}

		m_elements = 0u;
	}

	template<class U>
	inline void Vector<U>::assign(const T& _data, sgt_size_t _pos, sgt_size_t _count)
	{
		if ( _pos + _count > m_elements )
		{
			_count = m_elements - _pos;
		}

		for ( sgt_size_t i = _pos; i < _pos + _count; ++i )
		{
			m_pData[i] = _data;
		}
	}

	template<class U>
	inline typename Vector<U>::Iterator Vector<U>::insert(sgt_size_t _pos, const T* _pData, sgt_size_t _count)
	{
		// check if _pos is within the valid range [0, m_elements]
		if ( m_elements == 0u ) // empty string
		{
			// if the string is empty, we can only insert at the beginning
			_pos = 0u;
		}
		else if ( _pos > m_elements )
		{
			return nullptr;
		}

		// no reallocation needed
		if ( m_elements + _count <= m_capacity )
		{
			auto remainder = m_elements - _pos;

			// move-construct last remainder elements to reserved but un-initialized data at the end
			for ( sgt_size_t i = 0u; i < remainder; ++i )
			{
				traits::constructWithArgs(m_pData + _pos + _count + i, stdrep::move(m_pData[_pos + i]));
			}
			for ( sgt_size_t i = 0u; i < remainder; ++i )
			{
				m_pData[_pos + i] = _pData[i];
			}
			auto rest = _count - remainder;
			for ( sgt_size_t i = 0u; i < rest; ++i )
			{
				traits::constructWithArgs(m_pData + m_elements + i, stdrep::move(_pData[remainder + i]));
			}

			m_elements += _count;
		}
		else
		{
			const auto newSize = m_elements + _count;
			const auto newCapacity = newSize + (newSize >> 2); // grow by 1.25

			T* pNewData = static_cast<T*>(m_pAllocator->allocate(newCapacity * sizeof(T), alignof(T)));

			if ( pNewData == nullptr )
			{
				return nullptr;
			}

			// copy original data [0, .., _pos]
			for ( sgt_size_t i = 0u; i < _pos; ++i )
			{
				traits::constructWithArgs(pNewData + i, stdrep::move(m_pData[i]));
			}
			//[_pos, .., _pos + count]
			for ( sgt_size_t i = 0u; i < _count; ++i ) // inserted data
			{
				traits::constructWithArgs(pNewData + _pos + i, _pData[i]);
			}
			//[_pos, ..., m_elements]
			auto rest = m_elements - _pos;
			for ( sgt_size_t i = 0u; i < rest; ++i )
			{
				traits::constructWithArgs(pNewData + _pos + _count + i, stdrep::move(m_pData[_pos + i]));
			}

			if ( m_pData != nullptr )
			{
				m_pAllocator->deallocate(m_pData, m_capacity * sizeof(T));
			}

			m_pData = pNewData;
			m_elements = newSize;
			m_capacity = newCapacity;
		}

		return m_pData + _pos;
	}

	template<class U>
	inline void Vector<U>::deallocate()
	{
		if ( m_pAllocator != nullptr && m_pData != nullptr )
		{
			m_pAllocator->deallocate(m_pData, m_capacity * sizeof(T));
			m_capacity = 0u;
			m_pData = nullptr;
		}
	}

	template<class U>
	template<sgt_size_t Size>
	inline Vector<U>::Vector(IAllocator* _pAllocator, const T(&_array)[Size]) : Vector(_pAllocator, _array, Size) {}

	template<class U>
	template<class ...Args>
	inline typename Vector<U>::T* Vector<U>::emplace_back(Args&& ..._args)
	{
		// we ran out of capacity, reallocate
		if ( m_elements >= m_capacity )
		{
			// grow by factor 1.25 + 1
			if ( reserve(m_capacity + 1u + (m_capacity >> 2)) == false )
			{
				return nullptr;
			}
		}

		return traits::constructWithArgs(m_pData + m_elements++, stdrep::forward<Args>(_args)...);
	}

	template<class U>
	template<class ...Args>
	inline void Vector<U>::emplace_back_args(const T& _first, Args&& ..._tail)
	{
		emplace_back(_first);

		if constexpr ( sizeof...(_tail) > 0 )
		{
			emplace_back_args(stdrep::forward<Args>(_tail)...);
		}
	}

} // !spvgentwo