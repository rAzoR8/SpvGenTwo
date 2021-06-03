#pragma once

#include "Graph.h"

namespace spvgentwo
{
	// forward decls
	class Function;
	class Instruction;

	class FunctionCallGraph : public Graph<Function*, Instruction*> // Function -> OpFunctionCall instruction
	{
	public:
		using Graph<Function*, Instruction*>::Graph;
		using NodeType = typename Graph<Function*, Instruction*>::NodeType;

		FunctionCallGraph(const Function& _func, IAllocator* _pAllocator = nullptr);

	private:
		void add(const Function& _func);
	};
} // !spvgentwo