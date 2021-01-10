#pragma once

namespace spvgentwo
{
	// forward decl
	class Module;
	class Grammar;
	class String;
	class IAllocator;

	class IModulePrinter
	{
	public:
		// expects ANSI color codes, nullptr does nothing
		virtual void append(const char* _pText, const char* _pushColor = nullptr, const char* _popColor = nullptr) = 0;
		// append a literal value as base10 ascii string
		virtual void append(unsigned int _literal, const char* _pushColor = nullptr, const char* _popColor = nullptr) = 0;

		IModulePrinter& operator<<(const char* _pStr) {	append(_pStr); return *this;}
		IModulePrinter& operator<<(unsigned int _literal) { append(_literal); return *this; }
	};

	// default example implementation
	class ModuleStringPrinter : public IModulePrinter
	{
	public:
		ModuleStringPrinter(String& _outBuffer, bool _useColorCodes = false) : m_buffer(_outBuffer), m_useColor(_useColorCodes){}

		void append(const char* _pStr, const char* _pushColor = nullptr, const char* _popColor = nullptr) final;
		void append(unsigned int _literal, const char* _pushColor = nullptr, const char* _popColor = nullptr) final;

	private:
		String& m_buffer;
		bool m_useColor = false;
	};

	bool moduleToString(const Module& _module, const Grammar& _grammar, IModulePrinter* _pOutput, bool _writePreamble = true);
}