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
		ILogger();
		virtual ~ILogger();

		virtual void log(const LogLevel _level, const char* _pMsg) = 0;
		void logDebug(const char* _pMsg) { log(LogLevel::Debug, _pMsg); }
		void logInfo(const char* _pMsg) { log(LogLevel::Info, _pMsg); }
		void logWarning(const char* _pMsg) { log(LogLevel::Warning, _pMsg); }
		void logError(const char* _pMsg) { log(LogLevel::Error, _pMsg); }
		void logFatal(const char* _pMsg) { log(LogLevel::Fatal, _pMsg); }
	};
} //! spvgentwo