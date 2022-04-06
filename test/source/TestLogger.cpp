#include "test/TestLogger.h"

#include <stdio.h>
#include <stdarg.h>

#include <catch2/catch_test_macros.hpp>

test::TestLogger::TestLogger() : spvgentwo::ILogger([](spvgentwo::ILogger* _pInstance, spvgentwo::LogLevel _level, const char* _format, ...)
	{
		char buffer[1024]{};

		va_list args;
		va_start(args, _format);
		vsnprintf(buffer, sizeof(buffer), _format, args);
		va_end(args);
		
		switch (_level)
		{
		case spvgentwo::LogLevel::Info:
			UNSCOPED_INFO(buffer);
			break;
		case spvgentwo::LogLevel::Warning:
			WARN(buffer);
			break;
		case spvgentwo::LogLevel::Error:
		case spvgentwo::LogLevel::Fatal:
			FAIL(buffer);
			break;
		case spvgentwo::LogLevel::Debug:
		default:
			break;
		}
	}
)
{
}
