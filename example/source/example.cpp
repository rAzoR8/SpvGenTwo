#include <cstdlib> // system

#include "common/ConsoleLogger.h"
#include "common/HeapAllocator.h"
#include "common/BinaryFileWriter.h"
#include "common/Graph.h"

// examples
#include "OldInstrTest.h"
#include "FunctionCall.h"
#include "ControlFlow.h"
#include "Extensions.h"
#include "Types.h"
#include "Constants.h"

#include <assert.h>

using namespace spvgentwo;

class TestLogger : public ConsoleLogger 
{
public:
	void log(const LogLevel _level, const char* _pMsg) final
	{
		ConsoleLogger::log(_level, _pMsg);
		assert(_level == LogLevel::Debug || _level == LogLevel::Info);
	}
};

int main(int argc, char* argv[])
{
	TestLogger log;
	HeapAllocator alloc; // custom user allocator

	Graph<spv::Op> g(&alloc);

	g.emplace(spv::Op::OpIAdd)->connect(g.emplace(spv::Op::OpIMul));

	// old cli test
	{
		BinaryFileWriter writer("test.spv");
		examples::oldInstrTest(&alloc, &log).write(&writer);

		system("spirv-dis test.spv");
		assert(system("spirv-val test.spv") == 0);
	}

	// function call example
	{
		BinaryFileWriter writer("test.spv");
		examples::functionCall(&alloc, &log).write(&writer);

		system("spirv-dis test.spv");
		assert(system("spirv-val test.spv") == 0);
	}

	// control flow example
	{
		BinaryFileWriter writer("test.spv");
		examples::controlFlow(&alloc, &log).write(&writer);

		system("spirv-dis test.spv");
		assert(system("spirv-val test.spv") == 0);
	}

	// extension example
	{
		BinaryFileWriter writer("test.spv");
		examples::extensions(&alloc, &log).write(&writer);

		system("spirv-dis test.spv");
		assert(system("spirv-val test.spv") == 0);
	}

	// types example
	{
		BinaryFileWriter writer("test.spv");
		examples::types(&alloc, &log).write(&writer);

		system("spirv-dis test.spv");
		assert(system("spirv-val test.spv") == 0);
	}

	// constants example
	{
		BinaryFileWriter writer("test.spv");
		examples::constants(&alloc, &log).write(&writer);

		system("spirv-dis test.spv");
		assert(system("spirv-val test.spv") == 0);
	}

	return 0;
}