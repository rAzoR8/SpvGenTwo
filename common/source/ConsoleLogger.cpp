#include "common/ConsoleLogger.h"
#include <cstdio>

void spvgentwo::ConsoleLogger::log(const LogLevel _level, const char* _pMsg)
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

	printf("%s", _pMsg);
	printf("\n");
}
