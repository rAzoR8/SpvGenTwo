#include "Operand.h"
#include "Writer.h"
#include "Instruction.h"
#include "BasicBlock.h"

void spvgentwo::Operand::write(IWriter* _pWriter) const
{
	switch (type)
	{
	case Type::Instruction:
		_pWriter->put(instruction->getResultId());
		break;
	case Type::BranchTarget:
		_pWriter->put(branchTarget->front().getResultId()); // TODO: check if BB is empty?
		break;
	case Type::Literal:
		_pWriter->put(value.value);
		break;
	case Type::ResultId:
		_pWriter->put(resultId);
	default:
		break;
	}
}