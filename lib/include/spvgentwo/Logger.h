#pragma once

#include "Flag.h"

namespace spvgentwo
{
	enum class LogLevel : unsigned int 
	{
		None = 0,
		Debug = 1 << 0, // for dev
		Info = 1 << 1, // detail msg
		Warning = 1 << 2, // missing information
		Error = 1 << 3, // invalid program / spirv state
		Fatal = 1 << 4, // program should terminate
		All = Debug | Info | Warning | Error | Fatal
	};

	class ILogger
	{
	public:
		using Callback = void (*) (ILogger* _pInstance, LogLevel _level, const char* _format, ...);

		ILogger( Callback _callback = nullptr, Flag<LogLevel> _filter = LogLevel::All ) : m_callback( _callback ), m_filter(_filter) {}

		void setCallback( Callback _callback ) { m_callback = _callback; }
		void setFilter( Flag<LogLevel> _filter ) { m_filter = _filter; }

		virtual ~ILogger() {}

		template <typename ...Args>
		void log(LogLevel _level, const char* _pFormat, Args... _args);

		template <typename ...Args>
		void logDebug(const char* _pFormat, Args... _args) { log(LogLevel::Debug, _pFormat, _args...); }
		template <typename ...Args>
		void logInfo(const char* _pFormat, Args... _args) { log(LogLevel::Info, _pFormat, _args...); }
		template <typename ...Args>
		void logWarning(const char* _pFormat, Args... _args) { log(LogLevel::Warning, _pFormat, _args...); }
		template <typename ...Args>
		void logError(const char* _pFormat, Args... _args) { log(LogLevel::Error, _pFormat, _args...); }
		template <typename ...Args>
		void logFatal(const char* _pFormat, Args... _args) { log(LogLevel::Fatal, _pFormat, _args...); }

	private:
		Callback m_callback = nullptr;
		Flag<LogLevel> m_filter = LogLevel::All;
	};

	template<typename ...Args>
	inline void ILogger::log(LogLevel _level, const char* _pFormat, Args... _args)
	{
		LogLevel level =  _level & m_filter;
		if (m_callback != nullptr && level != LogLevel::None )
		{			
			m_callback(this, level, _pFormat, _args...);
		}
	}
} //! spvgentwo