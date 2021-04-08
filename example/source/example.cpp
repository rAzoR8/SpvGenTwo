#include <cstdlib> // system

#include "spvgentwo/Logger.h"
#include "spvgentwo/Grammar.h"

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
#include "example/Linkage.h"

#include <cstdarg>
#include <cassert>
#include <cstdio>

using namespace spvgentwo;

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

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

		char buf[256]{ '\0' };

		va_list args;
		va_start(args, _pFormat);
		vsnprintf(buf, sizeof(buf), _pFormat, args);
		va_end(args);

		printf("%s\n", buf);

#ifdef _WIN32
		OutputDebugStringA(buf);
		OutputDebugStringA("\n");
#endif

		assert(_level == LogLevel::Debug || _level == LogLevel::Info);
	}

};

int main(int argc, char* argv[])
{
	TestLogger log;
	HeapAllocator alloc; // custom user allocator
	const Grammar gram(&alloc);

	{
		Module lib, consumer;
		// linkage export lib example
		if (BinaryFileWriter writer("export.spv"); writer.isOpen())
		{
			lib = examples::linkageLib(&alloc, &log);
			lib.finalizeAndWrite(writer, &gram);
			writer.close();
			system("spirv-dis export.spv");
			assert(system("spirv-val export.spv") == 0);
		}

		// linkage import lib example
		if (BinaryFileWriter writer("import.spv"); writer.isOpen())
		{
			consumer = examples::linkageConsumer(&alloc, &log);
			consumer.finalizeAndWrite(writer);
			writer.close();
			system("spirv-dis import.spv");
			assert(system("spirv-val import.spv") == 0);
		}

		// linkage importing example
		if (BinaryFileWriter writer("linkageOutput.spv"); writer.isOpen())
		{
			assert(examples::linkageLinked(lib, consumer, &alloc, &gram));
			consumer.finalizeAndWrite(writer);
			writer.close();
			system("spirv-dis linkageOutput.spv");
			assert(system("spirv-val linkageOutput.spv") == 0);
		}
	}

	// expression graph example
	if (BinaryFileWriter writer("expressionGraph.spv"); writer.isOpen())
	{
		examples::expressionGraph(&alloc, &log).finalizeAndWrite(writer);
		writer.close();
		system("spirv-dis expressionGraph.spv");
		assert(system("spirv-val expressionGraph.spv") == 0);
	}

	// old cli test
	if (BinaryFileWriter writer("oldInstrTest.spv"); writer.isOpen())
	{
		examples::oldInstrTest(&alloc, &log).finalizeAndWrite(writer);
		writer.close();
		system("spirv-dis oldInstrTest.spv");
		assert(system("spirv-val oldInstrTest.spv") == 0);
	}

	// function call example
	if (BinaryFileWriter writer("functionCall.spv"); writer.isOpen())
	{
		examples::functionCall(&alloc, &log).finalizeAndWrite(writer);
		writer.close();
		system("spirv-dis functionCall.spv");
		assert(system("spirv-val functionCall.spv") == 0);
	}

	// control flow example
	if (BinaryFileWriter writer("controlFlow.spv"); writer.isOpen())
	{
		examples::controlFlow(&alloc, &log).finalizeAndWrite(writer);
		writer.close();
		system("spirv-dis controlFlow.spv");
		assert(system("spirv-val controlFlow.spv") == 0);
	}

	// extension example
	if (BinaryFileWriter writer("extensions.spv"); writer.isOpen())
	{
		examples::extensions(&alloc, &log).finalizeAndWrite(writer);
		writer.close();
		system("spirv-dis extensions.spv");
		assert(system("spirv-val extensions.spv") == 0);
	}

	// types example
	if (BinaryFileWriter writer("types.spv"); writer.isOpen())
	{
		examples::types(&alloc, &log).finalizeAndWrite(writer);
		writer.close();
		system("spirv-dis types.spv");
		assert(system("spirv-val types.spv") == 0);
	}

	// constants example
	if (BinaryFileWriter writer("constants.spv"); writer.isOpen())
	{
		examples::constants(&alloc, &log).finalizeAndWrite(writer);
		writer.close();
		system("spirv-dis constants.spv");
		assert(system("spirv-val constants.spv") == 0);
	}

	// geo shader example
	if (BinaryFileWriter writer("geometry.spv"); writer.isOpen())
	{
		examples::geometryShader(&alloc, &log).finalizeAndWrite(writer);
		writer.close();
		system("spirv-dis geometry.spv");
		assert(system("spirv-val geometry.spv") == 0);
	}

	// fragment shader example
	if (BinaryFileWriter writer("fragment.spv"); writer.isOpen())
	{
		examples::fragmentShader(&alloc, &log).finalizeAndWrite(writer);
		writer.close();
		system("spirv-dis fragment.spv");
		assert(system("spirv-val fragment.spv") == 0);
	}

	return 0;
}