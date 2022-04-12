#include <catch2/catch_test_macros.hpp>
#include <catch2/reporters/catch_reporter_console.hpp>

#include "common/HeapAllocator.h"
using namespace spvgentwo;

TEST_CASE( "alignment", "[HeapAllocator]" ) {
    HeapAllocator alloc;

    auto test = [&alloc](unsigned bytes)
    {
        void* p = alloc.allocate(10u, 4);
        REQUIRE(p != nullptr);
        alloc.deallocate(p, bytes);
    };

    test(1);
    test(10);
    test(10);
    test(10);
    test(16);
    test(1337);
}