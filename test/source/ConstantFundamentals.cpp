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
		if (ptr == nullptr) return false;
		T v = *ptr;
		return v == val;
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
	CHECK(testData((char)55));
	CHECK(testData((char)-13));
	CHECK(testData((unsigned char)255));
	CHECK(testData((short)4900));
	CHECK(testData((short)-1337));
	CHECK(testData((unsigned short)0xffff));
	CHECK(testData((unsigned short)12345));
	CHECK(testData(85301));
	CHECK(testData(-959999));
	CHECK(testData(0xffffffff));
	CHECK(testData(0xffffffffu));
	CHECK(testData(0x1u));
	CHECK(testData(-0xffffffffll));
	CHECK(testData(0xffffffffffffffffllu));
	CHECK(testData(-42.0f));
	CHECK(testData(-0.0f));
	CHECK(testData(-0.1 / 0.0000000000455667));
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