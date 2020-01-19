#pragma once

#include <stddef.h> // size_t

namespace spvgentwo
{
	using Hash64 = unsigned long long;
	
	namespace detail
	{
		constexpr Hash64 Offset = 0xcbf29ce484222325ui64;
		constexpr Hash64 Prime = 0x100000001b3ui64;
	}

	template <class Key>
	struct Hasher
	{
		// default implementation
		Hash64 operator()(const Key& _key, Hash64 _seed = detail::Offset)
		{
			const unsigned char* pBytes = reinterpret_cast<const unsigned char*>(&_key);
			for (size_t i = 0u; i < sizeof(Key); ++i)
			{
				_seed ^= pBytes[i];
				_seed *= detail::Prime;
			}
			return _seed;
		}
	};

	// 64 bit FNV-1a hash
	class FNV1aHasher
	{
	public:
		FNV1aHasher() = default;

		template<class T>
		FNV1aHasher(const T& _data);

		FNV1aHasher(const char* _str);

		Hash64 add(const char* _pStr);

		Hash64 add(const void* _pData, const size_t _length);

		template <class T>
		FNV1aHasher& operator<<(const T& _data);

		FNV1aHasher& operator<<(const char* _str);

		Hash64 get() const { return m_Hash; }
		operator Hash64() const { return m_Hash; }

		template <class T>
		Hash64 operator()(const T& _data);

		template <class T, class ...Tail>
		Hash64 operator()(const T& _data,  const Tail&... _tail);

		Hash64 operator()(const char* _str);

	private:
		unsigned long long m_Hash = detail::Offset;
	};

	inline FNV1aHasher::FNV1aHasher(const char* _str)
	{
		add(_str);
	}

	inline Hash64 FNV1aHasher::add(const char* _pStr)
	{
		for (; *_pStr != 0; ++ _pStr)
		{
			m_Hash ^= static_cast<unsigned char>(*_pStr);
			m_Hash *= detail::Prime;
		}

		return m_Hash;
	}

	inline Hash64 spvgentwo::FNV1aHasher::add(const void* _pData, const size_t _length)
	{
		const unsigned char* pBytes = reinterpret_cast<const unsigned char*>(_pData);
		for (size_t i = 0u; i < _length; ++i)
		{
			m_Hash ^= pBytes[i];
			m_Hash *= detail::Prime;
		}

		return m_Hash;
	}

	inline FNV1aHasher& FNV1aHasher::operator<<(const char* _pStr)
	{
		add(_pStr);
		return *this;
	}

	inline Hash64 FNV1aHasher::operator()(const char* _str)
	{
		return add(_str);
	}

	template<class T>
	inline FNV1aHasher::FNV1aHasher(const T& _data)
	{
		Hasher<T> func;
		m_Hash = func(_data, m_Hash);
	}

	template<class T>
	inline FNV1aHasher& FNV1aHasher::operator<<(const T& _data)
	{
		Hasher<T> func;
		m_Hash = func(_data, m_Hash);
		return *this;
	}

	template<class T>
	inline Hash64 FNV1aHasher::operator()(const T& _data)
	{
		Hasher<T> func;
		m_Hash = func(_data, m_Hash);
		return m_Hash;
	}

	template<class T, class ...Tail>
	inline Hash64 FNV1aHasher::operator()(const T& _data, const Tail& ..._tail)
	{
		operator()(_data);

		if constexpr (sizeof...(_tail) > 0)
		{
			operator()(_tail...);
		}

		return m_Hash;
	}
} // !spvgentwo