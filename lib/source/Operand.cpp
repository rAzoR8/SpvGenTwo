#include "spvgentwo/Operand.h"
#include "spvgentwo/Writer.h"
#include "spvgentwo/Instruction.h"
#include "spvgentwo/BasicBlock.h"

bool spvgentwo::Operand::write(IWriter& _writer) const
{
	switch (type)
	{
	case Type::Instruction:
		return _writer.put(static_cast<unsigned int>(instruction->getResultId()));
	case Type::BranchTarget:
		return _writer.put(static_cast<unsigned int>(branchTarget->getLabel()->getResultId()));
	case Type::Literal:
		return _writer.put(literal.value);
	case Type::Id:
		return id != InvalidId && _writer.put(static_cast<unsigned int>(id));
	default:
		return false;
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
		literal = _other.literal;
		break;
	case Type::Id:
		id = _other.id;
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
		literal = _other.literal;
		break;
	case Type::Id:
		id = _other.id;
		break;
	default:
		break;
	}
}

spvgentwo::Operand& spvgentwo::Operand::operator=(const Operand& _other)
{
	if (this == &_other) return *this;

	type = _other.type;
	switch (type)
	{
	case Type::Instruction:
		instruction = _other.instruction;
		break;
	case Type::BranchTarget:
		branchTarget = _other.branchTarget;
		break;
	case Type::Literal:
		literal = _other.literal;
		break;
	case Type::Id:
		id = _other.id;
		break;
	default:
		break;
	}

	return *this;
}

spvgentwo::Operand& spvgentwo::Operand::operator=(Operand&& _other) noexcept
{
	if (this == &_other) return *this;

	type = _other.type;
	switch (type)
	{
	case Type::Instruction:
		instruction = _other.instruction;
		break;
	case Type::BranchTarget:
		branchTarget = _other.branchTarget;
		break;
	case Type::Literal:
		literal = _other.literal;
		break;
	case Type::Id:
		id = _other.id;
		break;
	default:
		break;
	}

	return *this;
}

bool spvgentwo::Operand::operator==(const Operand& _other) const 
{
	return type == _other.type && 
		((type == Type::BranchTarget && branchTarget == _other.branchTarget) || 
		(type == Type::Instruction && instruction == _other.instruction) || 
		(type == Type::Literal && literal == _other.literal) || 
		(type == Type::Id && id == _other.id));
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
	return type == Type::Literal && literal == _value;
}

bool spvgentwo::Operand::operator==(const spv::Id& _resultID) const
{
	return type == Type::Id && id == _resultID;
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
	return type != Type::Literal || literal != _value;
}

bool spvgentwo::Operand::operator!=(const spv::Id& _resultID) const
{
	return type != Type::Id || id != _resultID;
}