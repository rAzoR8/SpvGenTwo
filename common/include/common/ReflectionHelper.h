#pragma once

#include "spvgentwo/List.h"
#include "spvgentwo/Spv.h"

namespace spvgentwo
{
	// forward decls

	class Module;
	class Instruction;

	class ReflectionHelper
	{
	public:
		ReflectionHelper(const Module& _module);
		~ReflectionHelper();

		// parse OpExecutionMode/Id operands, returns false if LocalSize or LocalSizeHint is present
		bool getLocalSize(unsigned int& _x, unsigned int& _y, unsigned int& _z) const;

		void getVariablesByStorageClass(spv::StorageClass _class, List<const Instruction*>& _outVariables) const;

		void getVariableDecorations(const Instruction* _pVariable, List<const Instruction*>& _outDecorations) const;

	private:
		const Module& m_module;
	};
} // !spvgentwo