#include "spvgentwo/Constant.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/Grammar.h"
#include "spvgentwo/Templates.h"

#include "common/HeapAllocator.h"

#include <catch2/catch_test_macros.hpp>
#include "test/SpvValidator.h"
#include "test/TestLogger.h"

using namespace spvgentwo;

namespace {
	HeapAllocator g_alloc;
	test::TestLogger g_logger;
	Grammar g_gram(&g_alloc);
	test::SpvValidator g_validator(g_gram);

	inline Constant constant() { return Constant(&g_alloc); }

	template <class T>
	inline bool testData(T val)
	{
		Constant c(constant().make<T>(val));
		const T* ptr = c.template getDataAs<T>();
		return ptr != nullptr && *ptr == val;
	}

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

TEST_CASE("Data consistency", "[Constants]")
{
	REQUIRE(testData((char)55));
	REQUIRE(testData((char)-13));
	REQUIRE(testData((unsigned char)255));
	REQUIRE(testData((short)4900));
	REQUIRE(testData((short)-1337));
	REQUIRE(testData((unsigned short)0xffff));
	REQUIRE(testData((unsigned short)12345));
	REQUIRE(testData(85301));
	REQUIRE(testData(-959999));
	REQUIRE(testData(0xffffffff));
	REQUIRE(testData(0xffffffffu));
	REQUIRE(testData(0x1u));
	REQUIRE(testData(-0xffffffffll));
	REQUIRE(testData(0xffffffffffffffffllu));
	REQUIRE(testData(-42.0f));
	REQUIRE(testData(-0.0f));
	REQUIRE(testData(-0.1 / 0.0000000000455667));
}

TEST_CASE("Create constant", "[Constants]")
{
	Module module(&g_alloc, &g_logger);
	module.setMemoryModel(spv::AddressingModel::Logical, spv::MemoryModel::Simple);
	module.addCapability(spv::Capability::Shader);

	Instruction* instr = module.constant(1337);
	REQUIRE(1337 == *instr->getConstant()->getDataAs<int>());

	EntryPoint& ep = module.addEntryPoint<void>(spv::ExecutionModel::Fragment, "main");
	ep.addExecutionMode(spv::ExecutionMode::OriginUpperLeft);

	BasicBlock& bb = *ep;
	bb.Add(instr, instr);
	bb.returnValue();

	REQUIRE(valid(module));
}