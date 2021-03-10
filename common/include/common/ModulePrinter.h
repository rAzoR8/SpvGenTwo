#pragma once

#include "spvgentwo/Flag.h"

namespace spvgentwo
{
	// forward decl
	class Module;
	class Instruction;
	class Grammar;
	class String;

	namespace ModulePrinter
	{
		class IModulePrinter
		{
		public:
			// expects ANSI color codes, nullptr does nothing
			virtual void append(const char* _pText, const char* _pushColor = nullptr, const char* _popColor = nullptr) = 0;
			// append a literal value as base10 ascii string
			void append(unsigned int _literal, const char* _pushColor = nullptr, const char* _popColor = nullptr);

			IModulePrinter& operator<<(const char* _pStr) { append(_pStr); return *this; }
			IModulePrinter& operator<<(unsigned int _literal) { append(_literal); return *this; }
		};

		// default example implementation
		class ModuleStringPrinter : public IModulePrinter
		{
		public:
			ModuleStringPrinter(String& _outBuffer, bool _useColorCodes = false) : m_buffer(_outBuffer), m_useColor(_useColorCodes) {}

			void append(const char* _pStr, const char* _pushColor = nullptr, const char* _popColor = nullptr) final;

		private:
			String& m_buffer;
			bool m_useColor = false;
		};

		template <class FuncStr> // void FuncStr(const char* _pStr, const char* _pushColor, const char* _popColor)
		class ModuleFuncPrinter : public IModulePrinter
		{
		public:
			ModuleFuncPrinter(FuncStr _strFunc) :
				m_strFunc{ _strFunc } {}

			void append(const char* _pStr, const char* _pushColor = nullptr, const char* _popColor = nullptr) final { m_strFunc(_pStr, _pushColor, _popColor); }

		private:
			FuncStr m_strFunc{};
		};

		template <class FuncStr>
		ModuleFuncPrinter(FuncStr _strFunc)->ModuleFuncPrinter<FuncStr>;

		template <class SimpleFuncStr> // void SimpleFuncStr(const char*)
		class ModuleSimpleFuncPrinter : public IModulePrinter
		{
		public:
			ModuleSimpleFuncPrinter(SimpleFuncStr _strFunc, bool _useColorCodes = false) :
				m_strFunc{ _strFunc }, m_useColor(_useColorCodes) {}

			void append(const char* _pStr, const char* _pushColor = nullptr, const char* _popColor = nullptr) final
			{
				if (_pushColor != nullptr && m_useColor)
				{
					m_strFunc(_pushColor);
				}
				if (_pStr != nullptr)
				{
					m_strFunc(_pStr);
				}
				if (_popColor != nullptr && m_useColor)
				{
					m_strFunc(_popColor);
				}
			}

		private:
			SimpleFuncStr m_strFunc{};
			bool m_useColor = false;
		};

		template <class FuncStr>
		ModuleSimpleFuncPrinter(FuncStr _strFunc, bool _useColorCodes = false)->ModuleSimpleFuncPrinter<FuncStr>;

		enum class PrintOptionsBits
		{
			Preamble = 1 << 0,
			InstructionName = 1 << 1,
			OperandName = 1 << 2,
			ResultId = 1 << 3,
			OperationName = 1 << 4,
			TypeName = 1 << 5,
			All = TypeName | (TypeName - 1)
		};

		using PrintOptions = Flag<PrintOptionsBits>;

		// returns false on failure / invalid instruction
		bool printInstruction(const Instruction& _instr, const Grammar& _grammar, IModulePrinter& _pOutput, PrintOptions _options = PrintOptionsBits::All, const char* _pIndentation = "\t\t");

		bool printModule(const Module& _module, const Grammar& _grammar, IModulePrinter& _pOutput, PrintOptions _options = PrintOptionsBits::All, const char* _pIndentation = "\t\t");
	} // !ModulePrinter
}