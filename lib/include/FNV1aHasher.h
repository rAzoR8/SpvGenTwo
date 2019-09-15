#pragma once

#include <stddef.h> // size_t

namespace spvgentwo
{
	// 64 bit FNV-1a hash
	class FNV1aHash
	{
	public:
		using Hash64 = unsigned long long;
		static constexpr Hash64 Offset = 0xcbf29ce484222325ui64;
		static constexpr Hash64 Prime = 0x100000001b3ui64;

		Hash64 add(const char* _pStr);

		Hash64 add(const void* _pData, const size_t _length);

		template <class T>
		FNV1aHash& operator<<(const T& _data);

		FNV1aHash& operator<<(const char* _pStr);

		operator Hash64() const { return m_Hash; }

	private:
		unsigned long long m_Hash = Offset;
	};

	inline FNV1aHash::Hash64 FNV1aHash::add(const char* _pStr)
	{
		for (; *_pStr != 0; ++ _pStr)
		{
			m_Hash ^= static_cast<unsigned char>(*_pStr);
			m_Hash *= Prime;
		}

		return m_Hash;
	}

	inline FNV1aHash::FNV1aHash::Hash64 spvgentwo::FNV1aHash::add(const void* _pData, const size_t _length)
	{
		const unsigned char* pBytes = reinterpret_cast<const unsigned char*>(_pData);
		for (size_t i = 0u; i < _length; ++i)
		{
			m_Hash ^= pBytes[i];
			m_Hash *= Prime;
		}

		return m_Hash;
	}

	inline FNV1aHash& FNV1aHash::operator<<(const char* _pStr)
	{
		add(_pStr);
		return *this;
	}

	template<class T>
	inline FNV1aHash& FNV1aHash::operator<<(const T& _data)
	{
		add(&_data, sizeof(T));
		return *this;
	}
} // !spvgentwo