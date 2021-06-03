#pragma once
#include "stdreplacement.h"

namespace spvgentwo
{
	struct Hash64
	{
		sgt_uint64_t value;
		constexpr Hash64(sgt_uint64_t _val = 0ull) : value(_val) {}
		constexpr Hash64(sgt_uint32_t _low, sgt_uint32_t _high) : value(_low | static_cast<sgt_uint64_t>(_high) << 32u) {}
		constexpr operator sgt_uint64_t() const { return value; }
		inline constexpr Hash64 operator^=(unsigned char _byte) { value ^= _byte; return *this; }
		inline constexpr Hash64 operator*=(const Hash64 _prime) { value *= _prime.value; return *this; }
	};
	
	namespace detail
	{
		constexpr Hash64 Offset{ 0xcbf29ce484222325ull };
		constexpr Hash64 Prime{ 0x100000001b3ull };
	}

	template <class Key>
	struct Hasher;

	// 64 bit FNV-1a hash
	class FNV1aHasher
	{
		template <class T>
		static constexpr Hash64 hasherOrDefault(const T& _data, Hash64 _seed)
		{
			if constexpr (traits::is_complete_v<Hasher<T>>) // check if specialization exists
			{
				Hasher<T> h{};
				return h(_data, _seed);
			}
			else // resort for default impl
			{
				const void* pErased = &_data; // avoid reinterpret_cast in constexpr
				const unsigned char* pBytes = static_cast<const unsigned char*>(pErased);
				for (sgt_size_t i = 0u; i < sizeof(_data); ++i)
				{
					_seed ^= pBytes[i];
					_seed *= detail::Prime;
				}
				return _seed;
			}
		}

	public:
		constexpr explicit FNV1aHasher(Hash64 _seed = detail::Offset);

		constexpr Hash64 add(const void* _pData, const sgt_size_t _length);

		constexpr Hash64 get() const { return m_Hash; }
		constexpr operator Hash64() const { return m_Hash; }

		constexpr Hash64 operator()(const char* _str);

		template <class T>
		constexpr Hash64 operator()(const T& _data);

		template <class T, class ...Tail>
		constexpr Hash64 operator()(const T& _data, const Tail&... _tail);

		constexpr  FNV1aHasher& operator<<(const char* _pStr) { operator()(_pStr); return *this; }

		template <class T>
		constexpr FNV1aHasher& operator<<(const T& _data) { operator()(_data); return *this; }

		template <class T>
		constexpr FNV1aHasher& operator<<(const T* _ptr) { operator()(_ptr); return *this; }

	private:
		Hash64 m_Hash = detail::Offset;
	};

	inline constexpr FNV1aHasher::FNV1aHasher(Hash64 _seed) :
		m_Hash(_seed)
	{
	}

	inline constexpr Hash64 spvgentwo::FNV1aHasher::add(const void* _pData, const sgt_size_t _length)
	{
		const unsigned char* pBytes = static_cast<const unsigned char*>(_pData);
		for (sgt_size_t i = 0u; i < _length; ++i)
		{
			m_Hash ^= pBytes[i];
			m_Hash *= detail::Prime;
		}

		return m_Hash;
	}

	inline constexpr Hash64 FNV1aHasher::operator()(const char* _pStr)
	{
		for (; *_pStr != 0; ++_pStr)
		{
			m_Hash ^= static_cast<unsigned char>(*_pStr);
			m_Hash *= detail::Prime;
		}

		return m_Hash;
	}

	template<class T>
	inline constexpr Hash64 FNV1aHasher::operator()(const T& _data)
	{
		m_Hash = hasherOrDefault(_data, m_Hash);
		return m_Hash;
	}

	template<class T, class ...Tail>
	inline constexpr Hash64 FNV1aHasher::operator()(const T& _data, const Tail& ..._tail)
	{
		operator()(_data);

		if constexpr (sizeof...(_tail) > 0)
		{
			operator()(_tail...);
		}

		return m_Hash;
	}

	template <class T, class ...Tail>
	inline constexpr Hash64 hash(const T& _data, const Tail&... _tail)
	{
		FNV1aHasher h{};
		return h(_data, _tail...);
	}
} // !spvgentwo