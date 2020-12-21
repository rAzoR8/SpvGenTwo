#include <cstdlib> // system

#include "spvgentwo/Logger.h"
#include "common/HeapAllocator.h"
#include "common/BinaryFileWriter.h"
#include "common/BinaryFileReader.h"

// examples
#include "example/OldInstrTest.h"
#include "example/FunctionCall.h"
#include "example/ControlFlow.h"
#include "example/Extensions.h"
#include "example/Types.h"
#include "example/Constants.h"
#include "example/ExpressionGraph.h"
#include "example/GeometryShader.h"
#include "example/FragmentShader.h"

#include <stdarg.h>
#include <assert.h>

using namespace spvgentwo;

class TestLogger : public ILogger 
{
public:
	TestLogger() : ILogger(LogImpl) {}
	static void LogImpl([[maybe_unused]] ILogger* _pInstance, LogLevel _level, const char* _pFormat, ...)
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
	if (BinaryFileWriter writer("expressionGraph.spv"); writer.isOpen())
	{
		examples::expressionGraph(&alloc, &log).write(&writer);
		writer.close();
		system("spirv-dis expressionGraph.spv");
		assert(system("spirv-val expressionGraph.spv") == 0);
	}

	// old cli test
	if (BinaryFileWriter writer("oldInstrTest.spv"); writer.isOpen())
	{
		examples::oldInstrTest(&alloc, &log).write(&writer);
		writer.close();
		system("spirv-dis oldInstrTest.spv");
		assert(system("spirv-val oldInstrTest.spv") == 0);
	}

	// function call example
	if (BinaryFileWriter writer("functionCall.spv"); writer.isOpen())
	{
		examples::functionCall(&alloc, &log).write(&writer);
		writer.close();
		system("spirv-dis functionCall.spv");
		assert(system("spirv-val functionCall.spv") == 0);
	}

	// control flow example
	if (BinaryFileWriter writer("controlFlow.spv"); writer.isOpen())
	{
		examples::controlFlow(&alloc, &log).write(&writer);
		writer.close();
		system("spirv-dis controlFlow.spv");
		assert(system("spirv-val controlFlow.spv") == 0);
	}

	// extension example
	if (BinaryFileWriter writer("extensions.spv"); writer.isOpen())
	{
		examples::extensions(&alloc, &log).write(&writer);
		writer.close();
		system("spirv-dis extensions.spv");
		assert(system("spirv-val extensions.spv") == 0);
	}

	// types example
	if (BinaryFileWriter writer("types.spv"); writer.isOpen())
	{
		examples::types(&alloc, &log).write(&writer);
		writer.close();
		system("spirv-dis types.spv");
		assert(system("spirv-val types.spv") == 0);
	}

	// constants example
	if (BinaryFileWriter writer("constants.spv"); writer.isOpen())
	{
		examples::constants(&alloc, &log).write(&writer);
		writer.close();
		system("spirv-dis constants.spv");
		assert(system("spirv-val constants.spv") == 0);
	}

	// geo shader example
	if (BinaryFileWriter writer("geometry.spv"); writer.isOpen())
	{
		examples::geometryShader(&alloc, &log).write(&writer);
		writer.close();
		system("spirv-dis geometry.spv");
		assert(system("spirv-val geometry.spv") == 0);
	}

	// geo shader example
	if (BinaryFileWriter writer("fragment.spv"); writer.isOpen())
	{
		examples::fragmentShader(&alloc, &log).write(&writer);
		writer.close();
		system("spirv-dis fragment.spv");
		assert(system("spirv-val fragment.spv") == 0);
	}

	return 0;
}