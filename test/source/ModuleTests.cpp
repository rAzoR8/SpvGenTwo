#include "spvgentwo/Grammar.h"
#include "common/HeapAllocator.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/reporters/catch_reporter_console.hpp>

// test
#include "test/Modules.h"
#include "test/SpvValidator.h"
#include "test/TestLogger.h"

#include "spvgentwo/Templates.h"

using namespace spvgentwo;
using namespace test;

namespace 
{
	HeapAllocator g_alloc;
	TestLogger g_logger;
	Grammar g_gram(&g_alloc);
	SpvValidator g_validator(g_gram);

	bool valid(spvgentwo::Module&& _module)
	{
		_module.finalize(&g_gram);
		return g_validator.validate(_module);
	}

	bool valid(spvgentwo::Module& _module)
	{
		_module.finalize(&g_gram);
		return g_validator.validate(_module);
	}
}

TEST_CASE("funcName", "[Modules]")
{
	spvgentwo::Module module(&g_alloc);
	spvgentwo::Function& funcAdd = module.addFunction("add", spvgentwo::spv::FunctionControlMask::Const);
	REQUIRE(funcAdd.getName() != nullptr);

	String name(&g_alloc, funcAdd.getName() );
	REQUIRE(name == "add");
}

TEST_CASE( "types", "[Modules]" )
{
	REQUIRE( valid( test::types( &g_alloc, &g_logger ) ) );
}

TEST_CASE( "constants", "[Modules]" )
{
	REQUIRE( valid( test::constants( &g_alloc, &g_logger ) ) );
}

TEST_CASE( "extensions", "[Modules]" )
{
	REQUIRE( valid( test::extensions( &g_alloc, &g_logger ) ) );
}

TEST_CASE( "oldInstrTest", "[Modules]" )
{
	REQUIRE( valid( test::oldInstrTest( &g_alloc, &g_logger ) ) );
}

TEST_CASE( "functionCall", "[Modules]" )
{
	REQUIRE( valid( test::functionCall( &g_alloc, &g_logger ) ) );
}

TEST_CASE( "controlFlow", "[Modules]" )
{
	REQUIRE( valid( test::controlFlow( &g_alloc, &g_logger ) ) );
}

TEST_CASE( "geometryShader", "[Modules]" )
{
	REQUIRE( valid( test::geometryShader( &g_alloc, &g_logger ) ) );
}

TEST_CASE( "fragmentShader", "[Modules]" )
{
	REQUIRE( valid( test::fragmentShader( &g_alloc, &g_logger ) ) );
}

TEST_CASE( "compute", "[Modules]" )
{
	REQUIRE( valid( test::computeShader( &g_alloc, &g_logger ) ) );
}

TEST_CASE( "expressionGraph", "[Modules]" )
{
	REQUIRE( valid( test::expressionGraph( &g_alloc, &g_logger ) ) );
}

TEST_CASE( "linking", "[Modules]" )
{
	Module libA, libB, consumer;

	libA = test::linkageLibA( &g_alloc, &g_logger );
	REQUIRE( valid( libA ) );

	libB = test::linkageLibB( &g_alloc, &g_logger );
	REQUIRE( valid( libB ) );

	consumer = test::linkageConsumer( &g_alloc, &g_logger );
	REQUIRE( valid( consumer ) );

	REQUIRE( test::linkageLinked( libA, libB, consumer, &g_alloc, &g_gram ) );
	REQUIRE( valid( consumer ) );
}