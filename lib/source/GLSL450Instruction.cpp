#include "GLSL450Instruction.h"
#include  <vulkan/GLSL.std.450.h>

#include "Module.h"

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::opCross(Instruction* _pLeft, Instruction* _pRight)
{
	Instruction* _pLeftTypeInstr = _pLeft->getTypeInst();
	Instruction* _pRightTypeInstr = _pRight->getTypeInst();

	const Type* pType = _pLeftTypeInstr->getType();
	if (_pLeftTypeInstr == _pRightTypeInstr && pType->isVectorOfScalar(3u))
	{
		return opExtInst(_pLeftTypeInstr, ExtName, GLSLstd450::GLSLstd450Cross, _pLeft, _pRight);	
	}
	
	getModule()->logError("Operands of opCross are not scalar vector of length 3");

	return nullptr;
}