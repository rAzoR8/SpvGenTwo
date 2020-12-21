#include "common/ConsoleLogger.h"
#include <stdio.h>
#include <stdarg.h>

spvgentwo::ConsoleLogger::ConsoleLogger() : ILogger(LogImpl)
{
}

void spvgentwo::ConsoleLogger::LogImpl([[maybe_unused]] ILogger* _pInstance, LogLevel _level, const char* _pFormat, ...)
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
}
