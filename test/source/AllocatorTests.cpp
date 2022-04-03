#include <catch2/catch_test_macros.hpp>
#include <catch2/reporters/catch_reporter_console.hpp>
#include <catch2/catch_reporter_registrars.hpp>

#include "common/HeapAllocator.h"
using namespace spvgentwo;

TEST_CASE( "alignment", "[HeapAllocator]" ) {
    HeapAllocator alloc;

    // not a power of two, must fail
    REQUIRE( alloc.allocate( 10u, 3 ) == nullptr );
}