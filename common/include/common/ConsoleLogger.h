#pragma once

#include "spvgentwo/Logger.h"

namespace spvgentwo
{
	class ConsoleLogger : public ILogger
	{
	public:
		ConsoleLogger( Flag<LogLevel> _filter = LogLevel::All );
		ConsoleLogger(const ConsoleLogger&) = delete;
		ConsoleLogger(ConsoleLogger&&) = delete;
	};
} // !spvgentwo