#pragma once

#include "spvgentwo/List.h"
#include "spvgentwo/Spv.h"
#include "Callable.h"

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
		void getGlobalVariablesByStorageClass(const Module& _module, spv::StorageClass _class, List<const Instruction*>& _outVariables);

		// get all instructions which have been decorated with _decoration & _value
		void getVariablesWithDecoration(const Module& _module, spv::Decoration _decoration, List<const Instruction*>& _outTargets, const unsigned int* _pValue = nullptr);

		// get call func with instructions which have been decorated with _decoration & _value
		void getVariablesWithDecoration(const Module& _module, spv::Decoration _decoration, Callable<void(const Instruction*)> _func, const unsigned int* _pValue = nullptr);

		// get list of OpDecorate, OpMemberDecorate etc that target _pTarget in the instruction's module
		void getDecorations(const Instruction* _pTarget, List<const Instruction*>& _outDecorations);

		// given OpDecorate or OpMemberDecorate, returns spv::Decorations, returns Decoration::Max if invalid input parameter
		spv::Decoration getSpvDecorationKindFromDecoration(const Instruction* _pDecoration);

		// given OpDecorate or OpMemberDecorate, returns spv::Decorations & literal value via output parameters, returns false if invalid input parameter
		bool getSpvDecorationAndLiteralFromDecoration(const Instruction* _pInDecoration, spv::Decoration& _outDecoration, unsigned int& _outValue);

		// _pDecoration must be OpDecorate (not OpMemberDecorate etc), returns uint_max if invalid/not applicable
		unsigned int getLiteralFromDecoration(spv::Decoration _decoration, const Instruction* _pDecoration);

		// get the literal value of _decoration used to decorate _pTarget instruction (type or variable)
		// _pOutDecoration can be used to receive the OpDecoration instruction associated to the target & decoration type
		unsigned int getDecorationLiteralFromTarget(spv::Decoration _decoration, const Instruction* _pTarget, const Instruction** _pOutDecoration = nullptr);
	};
} // !spvgentwo