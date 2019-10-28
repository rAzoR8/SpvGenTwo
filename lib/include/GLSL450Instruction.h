#pragma once

#include "Instruction.h"

namespace spvgentwo
{
	class GLSL450Intruction : public Instruction
	{
	public:
		using Instruction::Instruction;

		static constexpr const char* ExtName = "GLSL.std.450";

		Instruction* opCross(Instruction* _pLeft, Instruction* _pRight);

	};
} // !spvgentwo