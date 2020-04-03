#include <cstdlib> // system

#include "spvgentwo/Logger.h"
#include "common/HeapAllocator.h"
#include "common/BinaryFileWriter.h"

// examples
#include "OldInstrTest.h"
#include "FunctionCall.h"
#include "ControlFlow.h"
#include "Extensions.h"
#include "Types.h"
#include "Constants.h"
#include "ExpressionGraph.h"

#include <stdarg.h>
#include <assert.h>

using namespace spvgentwo;

class TestLogger : public ILogger 
{
public:
	TestLogger() : ILogger(LogImpl) {}
	static void LogImpl(ILogger* _pInstance, LogLevel _level, const char* _pFormat, ...)
	{
		switch (_level)
		{
		case LogLevel::Debug:
			printf("Debug: "); break;
		case LogLevel::Info:
			printf("Info: "); break;
		case LogLevel::Warning:
			printf("Warning: "); break;
		case LogLevel::Error:
			printf("Error: "); break;
		case LogLevel::Fatal:
			printf("Fatal: "); break;
		default:
			break;
		}

		va_list args;
		va_start(args, _pFormat);
		vprintf(_pFormat, args);
		va_end(args);
		printf("\n");

		assert(_level == LogLevel::Debug || _level == LogLevel::Info);
	}

};

int main(int argc, char* argv[])
{
	TestLogger log;
	HeapAllocator alloc; // custom user allocator

		// expression graph example
	{
		BinaryFileWriter writer("test.spv");
		examples::expressionGraph(&alloc, &log).write(&writer);

		system("spirv-dis test.spv");
		assert(system("spirv-val test.spv") == 0);
	}

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