#pragma once

#include "spvgentwo/Flag.h"

namespace spvgentwo
{
	// forward decl
	class Module;
	class Instruction;
	class Grammar;
	class String;
	class Constant;

	namespace ModulePrinter
	{
		namespace detail
		{
			struct EmptyConstantPrintFunc
			{
				constexpr bool append([[maybe_unused]] const Constant& _constant, [[maybe_unused]] const char* _pushColor, [[maybe_unused]] const char* _popColor) const { return false; }
			};

			constexpr auto PushRed = u8"\x1B[31m";
			constexpr auto PushGreen = u8"\x1B[32m";
			constexpr auto PushYellow = u8"\x1B[33m";
			constexpr auto PushBlue = u8"\x1B[34m";
			constexpr auto PushPurple = u8"\x1B[35m"; 
			constexpr auto PushLightBlue = u8"\x1B[36m";
			constexpr auto PushWhite = u8"\x1B[97m";
			constexpr auto PushRedBG = u8"\x1B[41m";
			constexpr auto PopGrey = u8"\033[0m";
		}

		struct ColorScheme
		{
			const char* literal = detail::PushRed;
			const char* string = detail::PushGreen;
			const char* operandId = detail::PushYellow;
			const char* resultId = detail::PushBlue;
			const char* extinst = detail::PushPurple; // ExtInst Instructions names
			const char* constant = detail::PushLightBlue;
			const char* enumValue = detail::PushWhite;
			const char* error = detail::PushRedBG;
			const char* defaultText = detail::PopGrey;
		};

		class IModulePrinter
		{
		public:

			// expects ANSI color codes, nullptr does nothing
			virtual void append(const char* _pText, const char* _pushColor = nullptr, const char* _popColor = nullptr) = 0;
			// print contents of _constants, returns false if implementation unable to print this type
			virtual bool append(const Constant& _constant, const char* _pushColor = nullptr, const char* _popColor = nullptr);

			// append a literal value as base10 ascii string
			void append(unsigned int _literal, const char* _pushColor = nullptr, const char* _popColor = nullptr);

			void setColorScheme(const ColorScheme& _colors) { m_colors = _colors; }
			const ColorScheme& getColorScheme() const { return m_colors; }

			IModulePrinter& operator<<(const char* _pStr) { append(_pStr); return *this; }
			IModulePrinter& operator<<(unsigned int _literal) { append(_literal); return *this; }
			IModulePrinter& operator<<(const Constant& _constant) { append(_constant); return *this; }

		private:
			ColorScheme m_colors{};
		};

		// void FuncStr(const char* _pStr, const char* _pushColor, const char* _popColor)
		// void FuncConstant(const Constant& _constant, const char* _pushColor, const char* _popColor)
		template <class FuncStr, class FuncConstant = detail::EmptyConstantPrintFunc>
		class ModuleFuncPrinter : public IModulePrinter
		{
		public:
			ModuleFuncPrinter(FuncStr _strFunc) :
				m_strFunc{ _strFunc } {}

			ModuleFuncPrinter(FuncStr _strFunc, FuncConstant _constantFunc) :
				m_strFunc{ _strFunc }, m_constantFunc{ _constantFunc } {}

			void append(const char* _pStr, const char* _pushColor = nullptr, const char* _popColor = nullptr) final { m_strFunc(_pStr, _pushColor, _popColor); }

			bool append(const Constant& _constant, const char* _pushColor = nullptr, const char* _popColor = nullptr) final { return m_constantFunc(_constant, _pushColor, _popColor); };

		private:
			FuncStr m_strFunc{};
			FuncConstant m_constantFunc{};
		};

		template <class FuncStr>
		ModuleFuncPrinter(FuncStr _strFunc)->ModuleFuncPrinter<FuncStr>;

		template <class FuncStr, class FuncConstant>
		ModuleFuncPrinter(FuncStr _strFunc, FuncConstant _constantFunc)->ModuleFuncPrinter<FuncStr, FuncConstant>;

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

		class ModuleStringPrinter : public IModulePrinter
		{
		public:
			ModuleStringPrinter(String& _outBuffer, bool _useColorCodes = false) : m_buffer(_outBuffer), m_useColor(_useColorCodes) {}

			void append(const char* _pStr, const char* _pushColor = nullptr, const char* _popColor = nullptr) final;

		protected:
			String& m_buffer;
			bool m_useColor = false;
		};

		enum class PrintOptionsBits
		{
			Preamble = 1 << 0,
			InstructionName = 1 << 1,
			OperandName = 1 << 2,
			ResultId = 1 << 3,
			OperationName = 1 << 4,
			TypeName = 1 << 5,
			ConstantData = 1 << 6,
			All = ConstantData | (ConstantData - 1)
		};

		using PrintOptions = Flag<PrintOptionsBits>;

		// returns false on failure / invalid instruction
		bool printInstruction(const Instruction& _instr, const Grammar& _grammar, IModulePrinter& _printer, PrintOptions _options = PrintOptionsBits::All, const char* _pIndentation = "\t\t");

		bool printModule(const Module& _module, const Grammar& _grammar, IModulePrinter& _printer, PrintOptions _options = PrintOptionsBits::All, const char* _pIndentation = "\t\t");
	} // !ModulePrinter
}