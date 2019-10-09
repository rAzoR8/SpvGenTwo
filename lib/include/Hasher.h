#pragma once

#include "FNV1aHasher.h"

namespace spvgentwo
{
	template <class Key>
	class Hasher;

	template<> struct Hasher<bool> { Hash64 operator()(const bool data) const noexcept { return FNV1aHasher(data); } };
	template<> struct Hasher<char> { Hash64 operator()(const char data) const noexcept { return FNV1aHasher(data); } };
	template<> struct Hasher<unsigned char> { Hash64 operator()(const unsigned char data) const noexcept { return FNV1aHasher(data); } };
	template<> struct Hasher<short> { Hash64 operator()(const short data) const noexcept { return FNV1aHasher(data); } };
	template<> struct Hasher<unsigned short> { Hash64 operator()(const unsigned short data) const noexcept { return FNV1aHasher(data); } };
	template<> struct Hasher<int> { Hash64 operator()(const int data) const noexcept { return FNV1aHasher(data); } };
	template<> struct Hasher<unsigned int> { Hash64 operator()(const unsigned int data) const noexcept { return FNV1aHasher(data); } };
	template<> struct Hasher<long> { Hash64 operator()(const long data) const noexcept { return FNV1aHasher(data); } };
	template<> struct Hasher<unsigned long> { Hash64 operator()(const unsigned long data) const noexcept { return FNV1aHasher(data); } };
	template<> struct Hasher<long long> { Hash64 operator()(const long long data) const noexcept { return FNV1aHasher(data); } };
	template<> struct Hasher<unsigned long long> { Hash64 operator()(const unsigned long long data) const noexcept { return FNV1aHasher(data); } };
	template<> struct Hasher<float> { Hash64 operator()(const float data) const noexcept { return FNV1aHasher(data); } };
	template<> struct Hasher<double> { Hash64 operator()(const double data) const noexcept { return FNV1aHasher(data); } };
	template<> struct Hasher<long double> { Hash64 operator()(const long double data) const noexcept { return FNV1aHasher(data); } };
	template<> struct Hasher<const char*> { Hash64 operator()(const char* data) const noexcept { return FNV1aHasher(data); } };	

	template<class T> struct Hasher<T*> { Hash64 operator()(/*const*/ T* ptr) const noexcept { return reinterpret_cast<Hash64>(ptr); } };

	template <class T>
	const Hash64 hash(const T& data) { return Hasher<T>()(data); }
} // !spvgentwo