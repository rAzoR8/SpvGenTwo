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

		// get all GLOBAL variables by StorageClass, Function variables are not gathered
		void getVariablesByStorageClass(const Module& _module, spv::StorageClass _class, List<const Instruction*>& _outVariables);

		// get list of OpDecorate, OpMemberDecorate etc that reference _pVariable in the variables module
		void getVariableDecorations(const Instruction* _pVariable, List<const Instruction*>& _outDecorations);

		// given OpDecorate or OpMemberDecorate, returns spv::Decorations, returns Decoration::Max if invalid input parameter
		spv::Decoration getSpvDecorationKindFromDecoration(const Instruction* _pDecoration);

		// given OpDecorate or OpMemberDecorate, returns spv::Decorations & literal value via output parameters, returns false if invalid input parameter
		bool getSpvDecorationAndLiteralFromDecoration(const Instruction* _pInDecoration, spv::Decoration& _outDecoration, unsigned int& _outValue);

		// _pDecoration must be OpDecorate (not OpMemberDecorate etc), returns uint_max if invalid/not applicable
		unsigned int getLiteralFromDecoration(spv::Decoration _decoration, const Instruction* _pDecoration);

		// get the literal value of _decoration used to decorate _pVariable
		unsigned int getDecorationLiteralFromVariable(spv::Decoration _decoration, const Instruction* _pVariable);
	};
} // !spvgentwo