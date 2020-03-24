#pragma once

#include "spvgentwo/Logger.h"

namespace spvgentwo
{
	class ConsoleLogger : public ILogger
	{
	public:
		ConsoleLogger();
		ConsoleLogger(const ConsoleLogger&) = delete;
		ConsoleLogger(ConsoleLogger&&) = delete;

	private:
		static void LogImpl(ILogger* _pInstance, LogLevel _level, const char* _pFormat, ...);
	};
} // !spvgentwo