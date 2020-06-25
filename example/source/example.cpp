#include <cstdlib> // system

#include "spvgentwo/Logger.h"
#include "common/HeapAllocator.h"
#include "common/BinaryFileWriter.h"
#include "common/BinaryFileReader.h"

// examples
#include "OldInstrTest.h"
#include "FunctionCall.h"
#include "ControlFlow.h"
#include "Extensions.h"
#include "Types.h"
#include "Constants.h"
#include "ExpressionGraph.h"
#include "Parsing.h"

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
	if (BinaryFileWriter writer("test.spv"); writer.isOpen())
	{
		examples::expressionGraph(&alloc, &log).write(&writer);
		writer.close();
		system("spirv-dis test.spv");
		assert(system("spirv-val test.spv") == 0);
	}

	// old cli test
	if (BinaryFileWriter writer("test.spv"); writer.isOpen())
	{
		examples::oldInstrTest(&alloc, &log).write(&writer);
		writer.close();
		system("spirv-dis test.spv");
		assert(system("spirv-val test.spv") == 0);
	}

	if (BinaryFileReader reader("test.spv"); reader.isOpen())
	{
		if (BinaryFileWriter writer("test_serialized.spv"); writer.isOpen())
		{
			examples::parsing(&alloc, &log, &reader).write(&writer);
			writer.close();
			system("spirv-dis test_serialized.spv");
			assert(system("spirv-val test_serialized.spv") == 0);
		}
	}

	// function call example
	if (BinaryFileWriter writer("test.spv"); writer.isOpen())
	{
		examples::functionCall(&alloc, &log).write(&writer);
		writer.close();
		system("spirv-dis test.spv");
		assert(system("spirv-val test.spv") == 0);
	}

	// control flow example
	if (BinaryFileWriter writer("test.spv"); writer.isOpen())
	{
		examples::controlFlow(&alloc, &log).write(&writer);
		writer.close();
		system("spirv-dis test.spv");
		assert(system("spirv-val test.spv") == 0);
	}

	// extension example
	if (BinaryFileWriter writer("test.spv"); writer.isOpen())
	{
		examples::extensions(&alloc, &log).write(&writer);
		writer.close();
		system("spirv-dis test.spv");
		assert(system("spirv-val test.spv") == 0);
	}

	// types example
	if (BinaryFileWriter writer("test.spv"); writer.isOpen())
	{
		examples::types(&alloc, &log).write(&writer);
		writer.close();
		system("spirv-dis test.spv");
		assert(system("spirv-val test.spv") == 0);
	}

	// constants example
	if (BinaryFileWriter writer("test.spv"); writer.isOpen())
	{
		examples::constants(&alloc, &log).write(&writer);
		writer.close();
		system("spirv-dis test.spv");
		assert(system("spirv-val test.spv") == 0);
	}

	return 0;
}