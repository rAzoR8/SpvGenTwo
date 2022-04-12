#include <catch2/catch_test_macros.hpp>
#include <catch2/reporters/catch_reporter_console.hpp>

#include "common/HeapAllocator.h"
using namespace spvgentwo;

TEST_CASE( "alignment", "[HeapAllocator]" ) {
    HeapAllocator alloc;

    // not a power of two, must fail
    REQUIRE( alloc.allocate( 10u, 3 ) == nullptr );

    auto test = [&alloc](unsigned bytes, unsigned align)
    {
        void* p = alloc.allocate(10u, 4);
        REQUIRE(p != nullptr);
        REQUIRE((sgt_uint64_t)p % align == 0);
        alloc.deallocate(p, bytes);
    };

    test(1, 1);
    test(10, 1);
    test(10, 4);
    test(10, 8);
    test(16, 16);
    test(16, 16);
    test(1337, 1);
}