#pragma once

#include "spvgentwo/List.h"
#include "spvgentwo/Spv.h"

namespace spvgentwo
{
	// forward decls

	class Module;
	class Instruction;

	namespace ReflectionHelper
	{
		// parse OpExecutionMode/Id operands, returns false if LocalSize or LocalSizeHint is present
		bool getLocalSize(const Module& _module, unsigned int& _x, unsigned int& _y, unsigned int& _z);

		void getVariablesByStorageClass(const Module& _module, spv::StorageClass _class, List<const Instruction*>& _outVariables);

		void getVariableDecorations(const Instruction* _pVariable, List<const Instruction*>& _outDecorations);

		// _pDecoration must be OpDecorate (not OpMemberDecorate etc), returns uint_max if invalid/not applicable
		unsigned int getLiteralFromDecoration(spv::Decoration _decoration, const Instruction* _pDecoration);

		unsigned int getDecorationLiteralFromVariable(spv::Decoration _decoration, const Instruction* _pVariable);
	};
} // !spvgentwo