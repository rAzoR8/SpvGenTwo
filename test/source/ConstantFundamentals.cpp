#include "spvgentwo/Constant.h"
#include "common/ExternalMemoryAllocator.h"
#include <catch2/catch_test_macros.hpp>

using namespace spvgentwo;

StackAllocator<32> g_alloc;
inline Constant constant() { return Constant(&g_alloc); }

template <class T>
inline bool test(T val)
{
	const T* ptr = constant().make<T>(val).template getDataAs<T>();
	return ptr != nullptr && *ptr == val;
}

TEST_CASE("Data consistency", "[Constants]")
{
	REQUIRE(test((char)55));
	REQUIRE(test((char)-13));
	REQUIRE(test((unsigned char)255));
	REQUIRE(test((short)4900));
	REQUIRE(test((short)-1337));
	REQUIRE(test((unsigned short)0xffff));
	REQUIRE(test((unsigned short)12345));
	REQUIRE(test(85301));
	REQUIRE(test(-959999));
	REQUIRE(test(0xffffffff));
	REQUIRE(test(0xffffffffu));
	REQUIRE(test(0x1u));
	REQUIRE(test(-0xffffffffll));
	REQUIRE(test(0xffffffffffffffffllu));
	REQUIRE(test(-42.0f));
	REQUIRE(test(-0.0f));
	REQUIRE(test(-0.1 / 0.0000000000455667));
}
