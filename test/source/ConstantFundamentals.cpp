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
	auto testData = [](auto val)
	{
		using T = decltype(val);
		Constant c(constant().make<T>(val));
		auto& data = c.getData();
		REQUIRE(data.size() > 0);
		REQUIRE(data.size() * sizeof(unsigned int) >= sizeof(T));
		const T* ptr = c.template getDataAs<T>();
		CHECK(ptr != nullptr);
		if ( ptr != nullptr )
		{
			T v = *ptr;
			CHECK(v == val);
		}
	};

	testData((char)55);
	testData((char)-13);
	testData((unsigned char)255);
	testData((short)4900);
	testData((short)-1337);
	testData((unsigned short)0xffff);
	testData((unsigned short)12345);
	testData(85301);
	testData(-959999);
	testData(0xffffffff);
	testData(0xffffffffu);
	testData(0x1u);
	testData(-0xffffffffll);
	testData(0xffffffffffffffffllu);
	testData(-42.0f);
	testData(-0.0f);
	testData(-0.1 / 0.0000000000455667);
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