#pragma once

namespace spvgentwo
{
	enum class LogLevel : unsigned int 
	{
		Debug, // for dev
		Info, // detail msg
		Warning, // missing information
		Error, // invalid program / spirv state
		Fatal // program should terminate
	};

	class ILogger
	{
	public:
		virtual ~ILogger() {}
		virtual void log(const LogLevel _level, const char* _pMsg) = 0;
	};
} //! spvgentwo