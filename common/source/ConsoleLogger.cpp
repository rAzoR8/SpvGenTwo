#include "common/ConsoleLogger.h"
#include <stdio.h>
#include <stdarg.h>

namespace
{
	void LogImpl( [[maybe_unused]] spvgentwo::ILogger* _pInstance, spvgentwo::LogLevel _level, const char* _pFormat, ... )
	{
		switch( _level )
		{
		case spvgentwo::LogLevel::Debug:
			printf( "Debug: " ); break;
		case spvgentwo::LogLevel::Info:
			printf( "Info: " ); break;
		case spvgentwo::LogLevel::Warning:
			printf( "Warning: " ); break;
		case spvgentwo::LogLevel::Error:
			printf( "Error: " ); break;
		case spvgentwo::LogLevel::Fatal:
			printf( "Fatal: " ); break;
		default:
			break;
		}

		va_list args;
		va_start( args, _pFormat );
		vprintf( _pFormat, args );
		va_end( args );
		printf( "\n" );
	}
}

spvgentwo::ConsoleLogger::ConsoleLogger( Flag<LogLevel> _filter ) : ILogger( LogImpl, _filter )
{
}
