#pragma once

#include "spvgentwo/Instruction.h"
#include "spvgentwo/Grammar.h"

namespace spvgentwo
{
	namespace GrammarHelper
	{
		Instruction::Iterator getFirstOperandOfKind(const Instruction* _pInstruction, const Grammar& _gram, Grammar::OperandKind _kind, Grammar::Extension _ext = Grammar::Extension::Core);

		Instruction::Iterator getOperandByName(const Instruction* _pInstruction, const Grammar& _gram, const char* _pName, Grammar::Extension _ext = Grammar::Extension::Core);
	}
} // spvgentwo