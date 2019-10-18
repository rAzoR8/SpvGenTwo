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

spvgentwo::Operand::Operand(const Operand& _other) :
	type(_other.type)
{
	switch (type)
	{
	case Type::Instruction:
		instruction = _other.instruction;
		break;
	case Type::BranchTarget:
		branchTarget = _other.branchTarget;
		break;
	case Type::Literal:
		value = _other.value;
		break;
	case Type::ResultId:
		resultId = _other.resultId;
		break;
	default:
		break;
	}
}

spvgentwo::Operand::Operand(Operand&& _other) noexcept : type(_other.type)
{
	switch (type)
	{
	case Type::Instruction:
		instruction = _other.instruction;
		break;
	case Type::BranchTarget:
		branchTarget = _other.branchTarget;
		break;
	case Type::Literal:
		value = _other.value;
		break;
	case Type::ResultId:
		resultId = _other.resultId;
		break;
	default:
		break;
	}
}

bool spvgentwo::Operand::operator==(const Operand& _other) const 
{
	return type == _other.type && 
		((type == Type::BranchTarget && branchTarget == _other.branchTarget) || 
		(type == Type::Instruction && instruction == _other.instruction) || 
		(type == Type::Literal && value == _other.value) || 
		(type == Type::ResultId && resultId == _other.resultId));
}

bool spvgentwo::Operand::operator==(const BasicBlock* _block) const
{
	return type == Type::BranchTarget && branchTarget == _block;
}

bool spvgentwo::Operand::operator==(const Instruction* _instr) const
{
	return type == Type::Instruction && instruction == _instr;
}

bool spvgentwo::Operand::operator==(const literal_t& _value) const
{
	return type == Type::Literal && value == _value;
}

bool spvgentwo::Operand::operator==(const spv::Id& _resultID) const
{
	return type == Type::ResultId && resultId == _resultID;
}

bool spvgentwo::Operand::operator!=(const BasicBlock* _block) const
{
	return type != Type::BranchTarget || branchTarget != _block;
}

bool spvgentwo::Operand::operator!=(const Instruction* _instr) const
{
	return type != Type::Instruction || instruction != _instr;
}

bool spvgentwo::Operand::operator!=(const literal_t& _value) const
{
	return type != Type::Literal || value != _value;
}

bool spvgentwo::Operand::operator!=(const spv::Id& _resultID) const
{
	return type != Type::ResultId || resultId != _resultID;
}