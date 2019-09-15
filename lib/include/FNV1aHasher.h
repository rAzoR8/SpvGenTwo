#pragma once

#include <stddef.h> // size_t

namespace spvgentwo
{
	// 64 bit FNV-1a hash
	class FNV1aHasher
	{
	public:
		using Hash64 = unsigned long long;
		static constexpr Hash64 Offset = 0xcbf29ce484222325ui64;
		static constexpr Hash64 Prime = 0x100000001b3ui64;

		Hash64 add(const char* _pStr);

		Hash64 add(const void* _pData, const size_t _length);

		template <class T>
		FNV1aHasher& operator<<(const T& _data);

		FNV1aHasher& operator<<(const char* _str);

		operator Hash64() const { return m_Hash; }

		template <class T>
		Hash64 operator()(const T& _data) { return add(&_data, sizeof(T)); }

		Hash64 operator()(const char* _str) { return add(_str); }

	private:
		unsigned long long m_Hash = Offset;
	};

	inline FNV1aHasher::Hash64 FNV1aHasher::add(const char* _pStr)
	{
		for (; *_pStr != 0; ++ _pStr)
		{
			m_Hash ^= static_cast<unsigned char>(*_pStr);
			m_Hash *= Prime;
		}

		return m_Hash;
	}

	inline FNV1aHasher::FNV1aHasher::Hash64 spvgentwo::FNV1aHasher::add(const void* _pData, const size_t _length)
	{
		const unsigned char* pBytes = reinterpret_cast<const unsigned char*>(_pData);
		for (size_t i = 0u; i < _length; ++i)
		{
			m_Hash ^= pBytes[i];
			m_Hash *= Prime;
		}

		return m_Hash;
	}

	inline FNV1aHasher& FNV1aHasher::operator<<(const char* _pStr)
	{
		add(_pStr);
		return *this;
	}

	template<class T>
	inline FNV1aHasher& FNV1aHasher::operator<<(const T& _data)
	{
		add(&_data, sizeof(T));
		return *this;
	}
} // !spvgentwo