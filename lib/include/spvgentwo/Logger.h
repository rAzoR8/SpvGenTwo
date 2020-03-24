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
		using Callback = void (*) (ILogger* _pInstance, LogLevel _level, const char* _format, ...);

		ILogger(Callback _callback = nullptr) : m_callback(_callback){}

		void setCallback(Callback _callback) { m_callback = _callback; }

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
	};

	template<typename ...Args>
	inline void ILogger::log(LogLevel _level, const char* _pFormat, Args... _args)
	{
		if (m_callback != nullptr)
		{
			m_callback(this, _level, _pFormat, _args...);
		}
	}
} //! spvgentwo