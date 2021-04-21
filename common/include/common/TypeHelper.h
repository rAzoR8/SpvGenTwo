#pragma once

namespace spvgentwo
{
	// forward decls:
	class Type;
	class String;
	class Instruction;

	namespace TypeHelper
	{
		// returns true if all types / subtypes could be resolved
		// _pOpTypeInstr is used to obtain names assigned via OpName. (struct names, optional parameter)
		bool getTypeName(const Type& _type, String& _outName, const Instruction* _pOpTypeInstr = nullptr);
	} // TypeHelper
} // spvgentwo