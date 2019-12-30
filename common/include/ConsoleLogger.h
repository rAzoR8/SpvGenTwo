#pragma once

#include "Logger.h"
namespace spvgentwo
{
	class ConsoleLogger : public ILogger
	{
	public:
		void log(const LogLevel _level, const char* _pMsg) final;
	};
} // !spvgentwo