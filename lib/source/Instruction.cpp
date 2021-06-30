#include "spvgentwo/Instruction.h"
#include "spvgentwo/BasicBlock.h"
#include "spvgentwo/Type.h"
#include "spvgentwo/Writer.h"
#include "spvgentwo/Reader.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/TypeInferenceAndValiation.h"
#include "spvgentwo/Grammar.h"

#include "spvgentwo/InstructionTemplate.inl"
#include "spvgentwo/ModuleTemplate.inl"

spvgentwo::Instruction::Instruction(Instruction&& _other) noexcept :
	List(stdrep::move(_other)),
	m_Operation(_other.m_Operation),
	m_parentType(_other.m_parentType),
	m_parent(_other.m_parent)
{
	_other.m_parent = {};
}

spvgentwo::Instruction::Instruction(Module* _pModule, Instruction&& _other) noexcept :
	List(stdrep::move(_other)),
	m_Operation(_other.m_Operation),
	m_parentType(ParentType::Module)
{
	m_parent.pModule = _pModule;
}

spvgentwo::Instruction::Instruction(Function* _pFunction, Instruction&& _other) noexcept :
	List(stdrep::move(_other)),
	m_Operation(_other.m_Operation),
	m_parentType(ParentType::Function)
{
	m_parent.pFunction = _pFunction;
}

spvgentwo::Instruction::Instruction(BasicBlock* _pBasicBlock, Instruction&& _other) noexcept :
	List(stdrep::move(_other)),
	m_Operation(_other.m_Operation),
	m_parentType(ParentType::BasicBlock)
{
	m_parent.pBasicBlock = _pBasicBlock;
}

spvgentwo::Instruction::~Instruction()
{
}

spvgentwo::Instruction& spvgentwo::Instruction::operator=(Instruction&& _other) noexcept
{
	if (this == &_other) return *this;

	List::operator=(stdrep::move(_other));
	m_Operation = _other.m_Operation;

	return *this;
}

spvgentwo::BasicBlock* spvgentwo::Instruction::getBasicBlock() const
{
	return m_parentType == ParentType::BasicBlock ? m_parent.pBasicBlock : nullptr;
}

spvgentwo::Function* spvgentwo::Instruction::getFunction() const
{
	switch (m_parentType)
	{
	case ParentType::BasicBlock:
		return m_parent.pBasicBlock->getFunction();
	case ParentType::Function:
		return m_parent.pFunction;
	default:
		return nullptr;
	}
}

void spvgentwo::Instruction::setParent(Module* _pModule)
{
	if (m_parent.pModule == nullptr)
	{
		m_parentType = ParentType::Module;
		m_parent.pModule = _pModule;
		setAllocator(_pModule->getAllocator());
	}
}

void spvgentwo::Instruction::setParent(Function* _pFunction)
{
	if (m_parent.pFunction == nullptr)
	{
		m_parentType = ParentType::Function;
		m_parent.pFunction = _pFunction;
		setAllocator(_pFunction->getAllocator());
	}
}

void spvgentwo::Instruction::setParent(BasicBlock* _pBasicBlock)
{
	if (m_parent.pBasicBlock == nullptr)
	{
		m_parentType = ParentType::BasicBlock;
		m_parent.pBasicBlock = _pBasicBlock;
		setAllocator(_pBasicBlock->getAllocator());
	}
}

void spvgentwo::Instruction::setParent(const Instruction& _other)
{
	if (m_parent.pModule == nullptr)
	{
		m_parentType = _other.m_parentType;	
		m_parent = _other.m_parent;
		setAllocator(_other.getAllocator());
	}
}

spvgentwo::Module* spvgentwo::Instruction::getModule() const
{
	switch (m_parentType)
	{
	case ParentType::BasicBlock:
		return m_parent.pBasicBlock->getModule();
	case ParentType::Function:
		return m_parent.pFunction->getModule();
	case ParentType::Module:
		return m_parent.pModule;
	default:
		return nullptr;
	}
}

const char* spvgentwo::Instruction::getName(const unsigned int _memberIndex) const
{
	return getModule()->getName(this, _memberIndex);
}

bool spvgentwo::Instruction::getBranchTargets(List<BasicBlock*>& _outTargetBlocks) const
{
	if (isTerminator())
	{
		for (const Operand& o : *this)
		{
			if (o.isBranchTarget()) // || instr.op = Label -> parent bb
			{
				_outTargetBlocks.emplace_back(o.getBranchTarget());
			}
			else if (Instruction* instr = o.getInstruction(); instr != nullptr)
			{
				if (instr->getOperation() == spv::Op::OpLabel)
				{
					_outTargetBlocks.emplace_back(instr->getBasicBlock());
				}
			}
		}
		return true;
	}

	return false;
}

void spvgentwo::Instruction::reset()
{
	m_Operation = spv::Op::OpNop;
	clear(); // clear operands
}

unsigned int spvgentwo::Instruction::getWordCount() const
{
	return 1u + static_cast<unsigned int>(m_Elements); // (m_elements is number of operands)
}

unsigned int spvgentwo::Instruction::getOpCode() const
{
	return ((unsigned int )m_Operation & spv::OpCodeMask) | (getWordCount() << spv::WordCountShift);
}

spvgentwo::spv::Id spvgentwo::Instruction::getResultId() const
{
	auto it = getResultIdOperand();
	if (it == nullptr) return InvalidId;
	return it->getId();
}

spvgentwo::Instruction* spvgentwo::Instruction::getResultTypeInstr() const
{
	if (hasResultType())
	{
		return front().getInstruction();
	}

	getModule()->logError("Instruction has no result type");

	return error();
}

const spvgentwo::Type* spvgentwo::Instruction::getType() const
{
	const Module* pModule = getModule();
	if (isType()) 
	{
		return pModule->getTypeInfo(this);
	}
	else if (hasResultType())
	{
		return pModule->getTypeInfo(getResultTypeInstr());	
	}

	return nullptr;
}

const spvgentwo::Constant* spvgentwo::Instruction::getConstant() const
{
	if (isSpecOrConstant())
	{
		return getModule()->getConstantInfo(this);
	}

	getModule()->logError("Instruction is not a constant");

	return nullptr;
}

spvgentwo::Instruction::Iterator spvgentwo::Instruction::getResultTypeOperand() const
{
	if (hasResultType()) // result type is the first optional operand
		return begin();

	return nullptr;
}

spvgentwo::Instruction::Iterator spvgentwo::Instruction::getResultIdOperand() const
{
	bool res = false, type = false;
	spv::HasResultAndType(m_Operation, &res, &type);

	if (res)
	{
		auto it = begin();
		if (type) ++it; // skip <id> ResultType
		return it;
	}

	return nullptr;
}

spvgentwo::Instruction::Iterator spvgentwo::Instruction::getFirstActualOperand() const
{
	bool res = false, type = false;
	spv::HasResultAndType(m_Operation, &res, &type);

	auto it = begin();

	if (res) ++it;
	if (type) ++it;

	return it;
}

spvgentwo::spv::StorageClass spvgentwo::Instruction::getStorageClass() const
{
	switch (m_Operation)
	{
	case spv::Op::OpTypePointer:
		return static_cast<spv::StorageClass>((begin() + 1u)->getLiteral().value);
	case spv::Op::OpVariable:
		return static_cast<spv::StorageClass>((begin() + 2u)->getLiteral().value);
	default:
		return spv::StorageClass::Max;
	}
}

spvgentwo::spv::Id spvgentwo::Instruction::assignResultId(bool _overwrite)
{
	if (auto it = getResultIdOperand(); it != nullptr && (_overwrite || it->getId() == InvalidId)) 
	{
		*it = getModule()->getNextId();
		return it->id;
	}
	return InvalidId;
}

void spvgentwo::Instruction::assignResultId(spv::Id _id)
{
	if (auto it = getResultIdOperand(); it != nullptr)
	{
		*it = _id;
	}
}

bool spvgentwo::Instruction::isType() const
{
	return spv::IsTypeOp(m_Operation);
}

bool spvgentwo::Instruction::isTerminator() const
{
	return isTerminatorOp(m_Operation);
}

bool spvgentwo::Instruction::isConstant() const
{
	return spv::IsConstantOp(m_Operation);
}

bool spvgentwo::Instruction::isSpecConstant() const
{
	return spv::IsSpecConstantOp(m_Operation);
}

bool spvgentwo::Instruction::isSpecOrConstant() const
{
	return isSpecOrConstantOp(m_Operation);
}

bool spvgentwo::Instruction::write(IWriter& _writer) const
{
	if (_writer.put(getOpCode()) == false)
		return false;
	
	for (const Operand& operand : *this)
	{
		if (operand.write(_writer) == false)
		{
			const char* name = getName();
			getModule()->logError("Failed to write operand for op %s [%u]", name != nullptr ? name : "", m_Operation);
			return false;
		}
	}

	return true;
}

bool spvgentwo::Instruction::readOperands(IReader& _reader, const Grammar& _grammar, spv::Op _op, unsigned int _operandCount)
{
	reset();

	m_Operation = _op;

	if (_operandCount == 0u)
	{
		return true; // nothing left to do
	}

	const Grammar::Instruction* info = _grammar.getInfo(static_cast<unsigned int>(m_Operation));

	if (info == nullptr)
	{
		getModule()->logError("Unkown op code %u", m_Operation);
		return false;
	}

	auto it = info->operands.begin();
	const auto end = info->operands.end();

	auto parseLiteralString = [&](unsigned int& _operands) -> bool
	{
		unsigned int word{ 0u };
		while (_operands-- > 0u)
		{
			if (_reader.get(word) == false)
			{
				getModule()->logError("Unexpected end of instruction stream for %s", info->name);
				return false;
			}

			addOperand(static_cast<literal_t>(word));
			if (hasStringTerminator(word)) // reached end of string
			{
				return true;
			}
		}

		return true;
	};

	auto parseId = [&](unsigned int& _operands) -> bool
	{
		unsigned int word{ 0u };
		if (_reader.get(word) == false)
		{
			getModule()->logError("Unexpected end of instruction stream for %s", info->name);
			return false;
		}
		--_operands;
		addOperand(static_cast<spv::Id>(word));
		return true;
	};

	auto parseLiteral = [&](unsigned int& _operands) -> bool
	{
		unsigned int word{ 0u };
		if (_reader.get(word) == false)
		{
			getModule()->logError("Unexpected end of instruction stream for %s", info->name);
			return false;
		}
		--_operands;
		addOperand(static_cast<literal_t>(word));
		return true;
	};

	auto parseSimpleOps = [&](unsigned int& _operands, const Grammar::Operand& _op) -> bool
	{
		if (_op.category == Grammar::OperandCategory::Id) // this is a simplified categorization
		{
			return parseId(_operands);
		}
		else if (_op.kind == Grammar::OperandKind::LiteralString)
		{
			return parseLiteralString(_operands);
		}
		else
		{
			return parseLiteral(_operands);
		}
	};

	while (_operandCount != 0u && it != end)
	{
		const auto& op = *it;

		if (op.kind == Grammar::OperandKind::LiteralString) 
		{
			if (parseLiteralString(_operandCount) == false)
			{
				return false;
			}

			++it;
			continue; // next operand
		}
		else if (op.kind == Grammar::OperandKind::LiteralSpecConstantOpInteger) // OpSpecConstantOp
		{
			if (parseLiteral(_operandCount) == false) // opcode
			{
				return false;
			}

			// remaining operands must be IDs
			while (_operandCount > 0u)
			{
				if (parseId(_operandCount) == false)
				{
					return false;
				}
			}

			++it; // no more operands after this one
			break; // end of instruction
		}

		if (op.category == Grammar::OperandCategory::Composite)
		{
			if (it + 1u != end) // all known compisites are trailing args
			{
				getModule()->logError("Unexpected end of composite operands for %s", info->name);
				return false;
			}

			if (const auto* bases = _grammar.getOperandBases(op.kind); bases != nullptr)
			{
				if (_operandCount % bases->size() != 0u)
				{
					getModule()->logError("Unexpected end of composite operands for %s", info->name);
					return false;
				}

				auto bit = bases->begin();
				auto bend = bases->end();

				while (_operandCount > 0u && bit != bend)
				{
					if (parseSimpleOps(_operandCount, *bit) == false)
					{
						return false;
					}

					if (++bit == bend) // reset
					{
						bit = bases->begin();
					}
				}
			}
			else
			{
				getModule()->logError("Faild to fetch operand bases for %s from grammar", info->name);
				return false;
			}

			break; // end of instruction
		}
		else if (op.category == Grammar::OperandCategory::ValueEnum || op.category == Grammar::OperandCategory::BitEnum)
		{
			if (parseLiteral(_operandCount) == false) // enum value
			{
				return false;
			}

			if (Grammar::hasOperandParameters(op.kind))
			{
				const unsigned int enumVal = back().getLiteral(); // last added operand

				if (auto* params = _grammar.getOperandParameters(op.kind, enumVal); params != nullptr)
				{
					for (const auto& param : *params)
					{
						if (parseSimpleOps(_operandCount, param) == false)
						{
							return false;
						}
					}
				}
			}
		}
		else if (op.category == Grammar::OperandCategory::Id)
		{
			if (parseId(_operandCount) == false) return false;
		}
		else if (op.category == Grammar::OperandCategory::Literal)
		{
			if (op.kind == Grammar::OperandKind::LiteralContextDependentNumber) // OpConstant
			{
				while (_operandCount > 0u)
				{
					if (parseLiteral(_operandCount) == false) return false;
				}
			}
			else if (parseLiteral(_operandCount) == false)
			{
				return false;			
			}
		}
		else
		{
			getModule()->logError("Could not parse all operands of %s [unkown operand category]", info->name);
			return false;
		}

		if (op.quantifier != Grammar::Quantifier::ZeroOrAny) // not trailing args
		{
			++it; // single quantifier		
		}
	} // operand loop

	if (_operandCount > 0u || (it != end && it->quantifier == Grammar::Quantifier::One))
	{
		getModule()->logError("Could not parse all operands of %s", info->name);
		return false;
	}

	return true;
}

spvgentwo::Instruction* spvgentwo::Instruction::Mul(Instruction* _pLeft, Instruction* _pRight)
{
	const Type* lType = _pLeft->getType();
	const Type* rType = _pRight->getType();

	if (lType == nullptr || rType == nullptr) return error();

	if (lType->isScalarOrVectorOfSameLength(spv::Op::OpTypeInt, *rType))
	{
		return opIMul(_pLeft, _pRight);
	}
	else if (lType->isScalarOrVectorOfSameLength(spv::Op::OpTypeFloat, *rType))
	{
		return opFMul(_pLeft, _pRight);
	}
	else if (lType->isVectorOfFloat() && rType->isFloat())
	{
		return opVectorTimesScalar(_pLeft, _pRight);
	}
	else if (lType->isFloat() && rType->isVectorOfFloat())
	{
		return opVectorTimesScalar(_pRight, _pLeft); // OpVectorTimesScalar expects vector as first operand
	}
	else if (lType->isMatrixOfFloat() && rType->isFloat())
	{
		return opMatrixTimesScalar(_pLeft, _pRight);
	}
	else if (lType->isFloat() && rType->isMatrixOfFloat())
	{
		return opMatrixTimesScalar(_pRight, _pLeft); // opMatrixTimesScalar expects vector as first operand
	}
	else if (lType->isVector() && rType->isMatrix())
	{
		return opVectorTimesMatrix(_pLeft, _pRight);
	}
	else if (lType->isMatrix() && rType->isVector())
	{
		return opMatrixTimesVector(_pLeft, _pRight);
	}
	else if (lType->isMatrix() && rType->isMatrix())
	{
		return opMatrixTimesMatrix(_pLeft, _pRight);
	}

	getModule()->logError("Failed to match Mul's operand types for this instruction");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::Div(Instruction* _pLeft, Instruction* _pRight, bool _allowVecDividedByScalar)
{
	const Type* lType = _pLeft->getType();
	const Type* rType = _pRight->getType();

	if (lType == nullptr || rType == nullptr) return error();

	if (lType->isScalarOrVectorOfSameLength(spv::Op::OpTypeInt, *rType) && lType->isUnsigned() && rType->isUnsigned())
	{
		return opUDiv(_pLeft, _pRight);
	}
	else if (lType->isScalarOrVectorOfSameLength(spv::Op::OpTypeInt, *rType))
	{
		return opSDiv(_pLeft, _pRight);
	}
	else if (lType->isScalarOrVectorOfSameLength(spv::Op::OpTypeFloat, *rType))
	{
		return opFDiv(_pLeft, _pRight);
	}
	else if (BasicBlock* bb = getBasicBlock(); bb != nullptr && _allowVecDividedByScalar &&
		lType->isVector() && rType->isScalar())
	{
		Instruction* one = nullptr;

		if (rType->isF32())
		{
			one = getModule()->constant(1.f);
		}
		else if (rType->isF64())
		{
			one = getModule()->constant(1.0);
		}
		// there is no OpVectorTimes Scalar (Mul) for integer types

		if (one != nullptr)
		{			
			// vec / scalar => vec * ( 1 / scalar )
			Instruction* factor = Div(one, _pRight); // this instruction
			return (*bb)->Mul(_pLeft, factor); // new instruction (BasicBlock->operator)
		}
	}

	getModule()->logError("Failed to match Div's operand types for this instruction");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::Not(Instruction* _pIntOrBool)
{
	const Type* type = _pIntOrBool->getType();

	if (type == nullptr) return error();

	if (type->isBaseTypeOf(spv::Op::OpTypeInt))
	{
		return opNot(_pIntOrBool);
	}
	else if (type->isBaseTypeOf(spv::Op::OpTypeBool))
	{
		return opLogicalNot(_pIntOrBool);
	}

	return error();
}

void spvgentwo::Instruction::opNop()
{
	makeOp(spv::Op::OpNop);
}

spvgentwo::Instruction* spvgentwo::Instruction::opUndef(Instruction* _pResultType)
{
	if (_pResultType->isType())
	{
		return makeOp(spv::Op::OpUndef, _pResultType, InvalidId);
	}
	getModule()->logError("opUndef ResultType is not a type instruction");
	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opSizeOf(Instruction* _pPointerToVar)
{
	const Type* ptrType = _pPointerToVar->getType();
	if (ptrType == nullptr) return error();

	if (ptrType->isPointer())
	{
		return makeOp(spv::Op::OpSizeOf, InvalidInstr, InvalidId, _pPointerToVar);	
	}
	getModule()->logError("Operand of opSizeOf must be a pointer to a concrete type");
	return error();
}

void spvgentwo::Instruction::opSourceContinued(const char* _pSourceText)
{
	makeOp(spv::Op::OpSourceContinued, _pSourceText);
}

void spvgentwo::Instruction::opSource(spv::SourceLanguage _lang, unsigned int _version, Instruction* _pFileString, const char* _pSourceText)
{
	makeOp(spv::Op::OpSource, literal_t{ _lang }, _version);
	if (_pFileString != nullptr)
	{
		if (_pFileString->getOperation() == spv::Op::OpString)
		{
			addOperand(_pFileString);
		}
		else
		{
			getModule()->logError("Operand of _pFileString of opSource target must be OpString instruction");
		}
	}
	if (_pSourceText != nullptr)
	{
		appendLiterals(_pSourceText);
	}
}

void spvgentwo::Instruction::opSourceExtension(const char* _pExtensionName)
{
	makeOp(spv::Op::OpSourceExtension, _pExtensionName);
}

void spvgentwo::Instruction::opCapability(const spv::Capability _capability)
{
	makeOp(spv::Op::OpCapability, _capability);
}

void spvgentwo::Instruction::opMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel)
{
	makeOp(spv::Op::OpMemoryModel, _addressModel, _memoryModel);
}

void spvgentwo::Instruction::opExtension(const char* _pExtName)
{
	makeOp(spv::Op::OpExtension, _pExtName);
}

spvgentwo::Instruction* spvgentwo::Instruction::opExtInstImport(const char* _pExtName)
{
	return makeOp(spv::Op::OpExtInstImport, InvalidId, _pExtName);
}

spvgentwo::Instruction* spvgentwo::Instruction::opLabel()
{
	return makeOp(spv::Op::OpLabel, InvalidId);
}

spvgentwo::Instruction* spvgentwo::Instruction::opFunction(const Flag<spv::FunctionControlMask> _functionControl, Instruction* _pResultType, Instruction* _pFuncType)
{
	if (_pResultType->isType() && _pFuncType->getOperation() == spv::Op::OpTypeFunction)
	{
		return makeOp(spv::Op::OpFunction, _pResultType, InvalidId, literal_t{ _functionControl }, _pFuncType);
	}
	getModule()->logError("ResultType operand of opFunction must type instruction, function type instruction must be OpTypeFunction");
	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opFunctionParameter(Instruction* _pType)
{
	if (_pType->isType())
	{
		return makeOp(spv::Op::OpFunctionParameter, _pType, InvalidId);
	}
	getModule()->logError("Operand of opFunctionParameter must type instruction");
	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opKill()
{
	return makeOp(spv::Op::OpKill);
}

void spvgentwo::Instruction::opReturn()
{
	makeOp(spv::Op::OpReturn);
}

void spvgentwo::Instruction::opReturnValue(Instruction* _pValue)
{
	Function* func = getFunction();
	if (func != nullptr && _pValue->getType() != nullptr && func->getReturnType() == *_pValue->getType())
	{
		makeOp(spv::Op::OpReturnValue, _pValue);	
	}
	else
	{
		getModule()->logError("Operand of opReturnValue must match return type of the function");
	}
}

void spvgentwo::Instruction::opFunctionEnd()
{
	makeOp(spv::Op::OpFunctionEnd);
}

spvgentwo::Instruction* spvgentwo::Instruction::opFunctionCallDynamic(Instruction* _pResultType, Instruction* _pFunction, const List<Instruction*>& _args)
{
	if (_pResultType == nullptr || _pFunction == nullptr) return error();

	if (_pResultType->isType() && _pFunction->getOperation() == spv::Op::OpFunction)
	{
		makeOp(spv::Op::OpFunctionCall, _pResultType, InvalidId, _pFunction);

		for (Instruction* arg : _args)
		{
			addOperand(arg);
		}

		return this;
	}

	getModule()->logError("_pResultType is not a type instruction or _pFunction is not OpFunction");

	return error();
}

void spvgentwo::Instruction::opName(Instruction* _pTarget, const char* _pName)
{
	if (_pTarget->hasResult())
	{
		makeOp(spv::Op::OpName, _pTarget, _pName);	
	}
	else
	{
		getModule()->logError("opName target operand must have a result Id");
	}
}

void spvgentwo::Instruction::opMemberName(Instruction* _pTargetStructType, unsigned int _memberIndex, const char* _pName)
{
	if (_pTargetStructType->getOperation() == spv::Op::OpTypeStruct)
	{
		makeOp(spv::Op::OpMemberName, _pTargetStructType, _memberIndex, _pName);	
	}
	else
	{
		getModule()->logError("Operand of opMemberName target must be of type struct");
	}
}

spvgentwo::Instruction* spvgentwo::Instruction::opString(const char* _str)
{
	return makeOp(spv::Op::OpString, InvalidId, _str);
}

void spvgentwo::Instruction::opLine(Instruction* _pFileString, unsigned int _line, unsigned int _column)
{
	if (_pFileString->getOperation() == spv::Op::OpString)
	{
		makeOp(spv::Op::OpLine, _pFileString, _line, _column);
	}
	else
	{
		getModule()->logError("Operand _pFileString of opLine must be OpString instruction");
	}
}

void spvgentwo::Instruction::opLine(const char* _pFileString, unsigned int _line, unsigned int _column)
{
	opLine(getModule()->addSourceStringInstr()->opString(_pFileString), _line, _column);
}

void spvgentwo::Instruction::opNoLine()
{
	makeOp(spv::Op::OpNoLine);
}

spvgentwo::Instruction* spvgentwo::Instruction::opEmitVertex()
{
	return makeOp(spv::Op::OpEmitVertex);
}

spvgentwo::Instruction* spvgentwo::Instruction::opEndPrimitive()
{
	return makeOp(spv::Op::OpEndPrimitive);
}

spvgentwo::Instruction* spvgentwo::Instruction::opEmitStreamVertex(Instruction* _pConstIntId)
{
	const Type* type = _pConstIntId->getType();

	if (type == nullptr) return error();

	if (_pConstIntId->isSpecOrConstant() && type->isInt())
	{
		return makeOp(spv::Op::OpEmitStreamVertex, _pConstIntId);
	}

	getModule()->logError("Operand _pConstIntId of opEmitStreamVertex must be constant instruction of type int");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opEndStreamPrimitive(Instruction* _pConstIntId)
{
	const Type* type = _pConstIntId->getType();

	if (type == nullptr) return error();

	if (_pConstIntId->isSpecOrConstant() && type->isInt())
	{
		return makeOp(spv::Op::OpEndStreamPrimitive, _pConstIntId);
	}

	getModule()->logError("Operand _pConstIntId of opEndStreamPrimitive must be constant instruction of type int");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opPhiDynamic(const List<Instruction*>& _variables)
{
	if (_variables.size() < 2u)
	{
		getModule()->logError("Not enough variables passed to opPhiDynamic");
		return error();
	}

	Instruction* type = _variables.front()->getResultTypeInstr();

	if (type == nullptr) return error();

	makeOp(spv::Op::OpPhi, type, InvalidId);

	for (auto it = _variables.begin().next(); it != _variables.end(); ++it)
	{
		Instruction* var = *it;
		if (var == nullptr || (var->getResultTypeInstr() != type) || (var->getBasicBlock() == nullptr))
		{
			getModule()->logError("Invalid variable (type or null) passed to opPhiDynamic");
			return error();
		}

		addOperand(var);
		addOperand(var->getBasicBlock());
	}

	return this;
}

void spvgentwo::Instruction::opSelectionMerge(BasicBlock* _pMergeBlock, const spv::SelectionControlMask _control)
{
	makeOp(spv::Op::OpSelectionMerge, _pMergeBlock, _control);
}

void spvgentwo::Instruction::opBranch(BasicBlock* _pTargetBlock)
{
	makeOp(spv::Op::OpBranch, _pTargetBlock);
}

void spvgentwo::Instruction::opBranchConditional(Instruction* _pCondition, BasicBlock* _pTrueBlock, BasicBlock* _pFalseBlock)
{
	makeOp(spv::Op::OpBranchConditional, _pCondition, _pTrueBlock, _pFalseBlock);
}

void spvgentwo::Instruction::opBranchConditional(Instruction* _pCondition, BasicBlock* _pTrueBlock, BasicBlock* _pFalseBlock, const unsigned int _trueWeight, const unsigned int _falseWeight)
{
	makeOp(spv::Op::OpBranchConditional, _pCondition, _pTrueBlock, _pFalseBlock, _trueWeight, _falseWeight);
}

spvgentwo::Instruction* spvgentwo::Instruction::callDynamic(Function* _pFunction, const List<Instruction*>& _args)
{
	return opFunctionCallDynamic(_pFunction->getReturnTypeInstr(), _pFunction->getFunction(), _args);
}

spvgentwo::Instruction* spvgentwo::Instruction::opVariable(Instruction* _pResultType, const spv::StorageClass _storageClass, Instruction* _pInitializer)
{
	if (_pInitializer == nullptr)
	{
		return makeOp(spv::Op::OpVariable, _pResultType, InvalidId, literal_t{ _storageClass });
	}
	else
	{
		return makeOp(spv::Op::OpVariable, _pResultType, InvalidId, literal_t{ _storageClass }, _pInitializer);
	}
}

void spvgentwo::Instruction::opCopyMemory(Instruction* _pTargetPtr, Instruction* _pSourcePtr, Flag<spv::MemoryAccessMask> _targetMemOperands, Flag<spv::MemoryAccessMask> _sourceMemOperands)
{
	Module* module = getModule();

	const Type* targetType = _pTargetPtr->getType();
	const Type* sourceType = _pSourcePtr->getType();

	if (targetType == nullptr || sourceType == nullptr)
	{
		return;
	}

	if(targetType->isPointer() == false || sourceType->isPointer() == false)
	{
		module->logError("Operand of OpCopyMemory is not a pointer type");
		return;
	}
	else if(targetType->containsType(spv::Op::OpTypeRuntimeArray) || sourceType->containsType(spv::Op::OpTypeRuntimeArray))
	{
		module->logError("Operand of OpCopyMemory must not contain any OpTypeRuntimeArray");
		return;
	}
	else if (targetType->front() != sourceType->front())
	{
		module->logError("Operand types for _pTargetPtr and _pSourcePtr of OpCopyMemory don't match");
		return;
	}

	if(module->getSpvVersion() <= makeVersion(1u, 4u))
	{
		if (_sourceMemOperands != spv::MemoryAccessMask::MaskNone)
		{
			module->logWarning("Operand _sourceMemOperands of OpCopyMemory will be ignored for SPIR-V 1.4 and below");
		}

		makeOp(spv::Op::OpCopyMemory, _pTargetPtr, _pSourcePtr, literal_t{_targetMemOperands});
	}
	else
	{
		makeOp(spv::Op::OpCopyMemory, _pTargetPtr, _pSourcePtr, literal_t{_targetMemOperands}, literal_t{_sourceMemOperands});	
	}
}

spvgentwo::Instruction* spvgentwo::Instruction::opAccessChain(Instruction* _pBase, const List<unsigned int>& _indices)
{
	// Base must be a pointer, pointing to the base of a composite object.
	const Type* pBaseType = _pBase->getType();
	if (pBaseType == nullptr) return error();

	auto it = pBaseType->getSubType(0u); // base is a pointer type, so 0 is used to get the inner type

	if (it != nullptr)
	{
		it = it->getSubType(_indices);
	}

	if (it != nullptr)
	{
		Module* pModule = _pBase->getModule();

		// Result Type must be an OpTypePointer.
		// Its Type operand must be the type reached by walking the Base’s type hierarchy down to the last provided index in Indexes, and its Storage Class operand must be the same as the Storage Class of Base.

		Instruction* pResultType = pModule->addType(it->wrapPointer(pBaseType->getStorageClass()));

		makeOp(spv::Op::OpAccessChain, pResultType, InvalidId, _pBase);
		
		for (auto i : _indices) 
		{
			addOperand(pModule->constant(i));
		}

		return this;
	}

	getModule()->logError("Failed to deduct composite type of base operand for OpAccessChain");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opArrayLength(Instruction* _pStructure, unsigned int _ArrayMemberIndex)
{
	const Type* type = _pStructure->getType();
	if (type == nullptr) return error();


	if (type->isPointer() == false || type->front().isStruct() == false || type->front().back().isRuntimeArray() == false)
	{
		getModule()->logError("Operand _pStructure of OpArrayLength must be a logical pointer to an OpTypeStruct whose last	member is a run-time array");
		return error();
	} 

	return makeOp(spv::Op::OpArrayLength, InvalidInstr, InvalidId, _pStructure, literal_t{ _ArrayMemberIndex });
}

spvgentwo::Instruction* spvgentwo::Instruction::opOuterProduct(Instruction* _pLeft, Instruction* _pRight)
{
	const Type* pLeftType = _pLeft->getType();
	const Type* pRightType = _pRight->getType();

	if (pLeftType == nullptr || pRightType == nullptr) return error();

	if (pLeftType->isVectorOfFloat() && pRightType->isVectorOfFloat() && pLeftType->hasSameBase(*pRightType))
	{
		return makeOp(spv::Op::OpOuterProduct, InvalidInstr, InvalidId, _pLeft, _pRight);
	}

	getModule()->logError("Operands of opOuterProduct are not scalar vector of length 3");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opDot(Instruction* _pLeft, Instruction* _pRight)
{
	Instruction* pLeftTypeInstr = _pLeft->getResultTypeInstr();
	Instruction* pRightTypeInstr = _pRight->getResultTypeInstr();

	if (pLeftTypeInstr == nullptr || pRightTypeInstr == nullptr) return error();

	const Type* pType = pLeftTypeInstr->getType();
	if (pLeftTypeInstr == pRightTypeInstr && pType->isVectorOfFloat())
	{
		return makeOp(spv::Op::OpDot, InvalidInstr, InvalidId, _pLeft, _pRight);
	}

	getModule()->logError("Operands of opDot are not scalar vector of length 3");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opAny(Instruction* _pBoolVec)
{
	const Type* type = _pBoolVec->getType();
	if (type == nullptr) return error();

	if (type->isVectorOfBool())
	{
		return makeOp(spv::Op::OpAny, InvalidInstr, InvalidId, _pBoolVec);
	}

	getModule()->logError("Operands of opAny is not a vector of bool");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opAll(Instruction* _pBoolVec)
{
	const Type* type = _pBoolVec->getType();
	if (type == nullptr) return error();

	if (type->isVectorOfBool())
	{
		return makeOp(spv::Op::OpAll, InvalidInstr, InvalidId, _pBoolVec);
	}

	getModule()->logError("Operands of opAll is not a vector of bool");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opCompositeConstructDynamic(Instruction* _pResultType, const List<Instruction*>& _constituents)
{
	const Type* type = _pResultType->getType();
	if (type == nullptr) return error();

	if (type->isComposite() == false)
	{
		getModule()->logError("Result type of opCompositeConstruct is not a composite type");
		return error();
	}

	makeOp(spv::Op::OpCompositeConstruct, _pResultType, InvalidId);

	for (Instruction* constituent : _constituents)
	{
		addOperand(constituent);
	}

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opCompositeExtractDynamic(Instruction* _pComposite, const List<unsigned int>& _indices)
{
	const Type* pBaseType = _pComposite->getType();
	if (pBaseType == nullptr) return error();

	Module* pModule = _pComposite->getModule();

	if (pBaseType->isComposite() == false)
	{
		pModule->logError("Argument of opCompositeExtract is not a composite type");
		return error();
	}

	auto it = pBaseType->getSubType(0u);

	if (it != nullptr)
	{
		it = it->getSubType(_indices);
	}

	if (it != nullptr)
	{
		Instruction* pResultType = pModule->addType(*it);
		makeOp(spv::Op::OpCompositeExtract, pResultType, InvalidId, _pComposite);

		for (auto i : _indices)
		{
			addOperand(literal_t{ i });
		}

		return this;
	}

	pModule->logError("Invalid index sequence specified for composite type extraction");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opCopyObject(Instruction* _pObject)
{
	return makeOp(spv::Op::OpCopyObject, _pObject->getResultTypeInstr(), InvalidId, _pObject);
}

spvgentwo::Instruction* spvgentwo::Instruction::opTranspose(Instruction* _pMatrix)
{
	const Type* type = _pMatrix->getType();
	if (type == nullptr) return error();

	if (type->isMatrix())
	{
		return makeOp(spv::Op::OpTranspose, InvalidInstr, InvalidId, _pMatrix);	
	}

	getModule()->logError("Operand of opTranspose is not a matrix type");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opVectorExtractDynamic(Instruction* _pVector, Instruction* _pIndexInt)
{
	const Type* vecType = _pVector->getType();
	const Type* indexType = _pIndexInt->getType();
	if (vecType == nullptr || indexType == nullptr) return error();

	if (vecType->isVector() && indexType->isInt())
	{
		auto component = _pVector->getResultTypeInstr()->getFirstActualOperand();
		return makeOp(spv::Op::OpVectorExtractDynamic, component->getInstruction(), InvalidId, _pVector, _pIndexInt);	
	}

	getModule()->logError("opVectorExtractDynamic: _pVector must be of type vector, _pIndexInt must be of type integer");
	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opVectorInsertDynamic(Instruction* _pVector, Instruction* _pComponent, Instruction* _pIndexInt)
{
	const Type* pVecType = _pVector->getType();
	const Type* indexType = _pIndexInt->getType();
	if (pVecType == nullptr || indexType == nullptr) return error();

	if (pVecType->isVector() && pVecType->front() == *_pComponent->getType() && indexType->isInt())
	{
		return makeOp(spv::Op::OpVectorInsertDynamic, InvalidInstr, InvalidId, _pVector, _pComponent, _pIndexInt);
	}

	getModule()->logError("opVectorInsertDyanmic: _pVector component type does not match type of _pComponent or _pIndexInt is not of type integer");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opSelect(Instruction* _pCondBool, Instruction* _pTrueObj, Instruction* _pFalseObj)
{
	const Type* trueType = _pTrueObj->getType();
	const Type* falseType = _pFalseObj->getType();
	const Type* condType = _pCondBool->getType();

	if (trueType == nullptr || falseType == nullptr || condType == nullptr) return error();

	if (*trueType == *falseType && condType->isScalarOrVectorOf(spv::Op::OpTypeBool) && 
		condType->getScalarOrVectorLength() == trueType->getScalarOrVectorLength())
	{
		// Before version1.4, results are only computed per component.
		// Before version1.4, Result Type must be a pointer, scalar, or vector. Starting with version 1.4, Result Type can additionally be a composite type other than a vector.

		if (trueType->isScalar() || trueType->isVector() || trueType->isPointer() ||
			(getModule()->getSpvVersion() >= makeVersion(1u, 4u) && trueType->isComposite()))
		{
			return makeOp(spv::Op::OpSelect, _pTrueObj->getResultTypeInstr(), InvalidId, _pCondBool, _pTrueObj, _pFalseObj);
		}

		getModule()->logError("Object arguments of opSelect are not of type Scalar|Vector|Pointer|Composite");

		return error();
	}

	getModule()->logError("Condition type does not match extent of object arguments");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opVectorTimesScalar(Instruction* _pVector, Instruction* _pScalar)
{
	const Type* pVecType = _pVector->getType();
	const Type* pScalarType = _pScalar->getType();

	if (pVecType == nullptr || pScalarType == nullptr) return error();

	if (pScalarType->isFloat() && pVecType->isVectorOfFloat(0u, pScalarType->getFloatWidth()))
	{
		return makeOp(spv::Op::OpVectorTimesScalar, _pVector->getResultTypeInstr(), InvalidId, _pVector, _pScalar);
	}

	getModule()->logError("Operand of OpVectorTimesScalar is not a scalar or vector of float type");
	
	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opMatrixTimesScalar(Instruction* _pMatrix, Instruction* _pScalar)
{
	const Type* pMatType = _pMatrix->getType();
	const Type* pScalarType = _pScalar->getType();

	if (pMatType == nullptr || pScalarType == nullptr) return error();

	if (pScalarType->isFloat() && pMatType->hasSameBase(*pScalarType) && pMatType->isMatrix())
	{
		return makeOp(spv::Op::OpMatrixTimesScalar, _pMatrix->getResultTypeInstr(), InvalidId, _pMatrix, _pScalar);
	}

	getModule()->logError("Operand of OpMatrixTimesScalar is not a scalar or matrix of float type");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opVectorTimesMatrix(Instruction* _pVector, Instruction* _pMatrix)
{
	const Type* pVecType = _pVector->getType();
	const Type* pMatType = _pMatrix->getType();

	if (pVecType == nullptr || pMatType == nullptr) return error();

	if (pVecType->isVectorOfFloat() && pMatType->isMatrix() && pMatType->hasSameBase(*pVecType) && pMatType->front().getVectorComponentCount() == pVecType->getVectorComponentCount())
	{
		return makeOp(spv::Op::OpVectorTimesMatrix, _pVector->getResultTypeInstr(), InvalidId, _pVector, _pMatrix);
	}

	getModule()->logError("Operand of OpVectorTimesMatrix is not a vector or matrix of float type");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opMatrixTimesVector(Instruction* _pMatrix, Instruction* _pVector)
{
	const Type* pMatType = _pMatrix->getType();
	const Type* pVecType = _pVector->getType();

	if (pVecType == nullptr || pMatType == nullptr) return error();

	if (pVecType->isVectorOfFloat() && pMatType->isMatrix() && pMatType->hasSameBase(*pVecType) && pMatType->getMatrixColumnCount() == pVecType->getVectorComponentCount())
	{
		return makeOp(spv::Op::OpMatrixTimesVector, InvalidInstr, InvalidId, _pMatrix, _pVector);
	}

	getModule()->logError("Operand of OpMatrixTimesVector is not a vector or matrix of float type");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opMatrixTimesMatrix(Instruction* _pLeft, Instruction* _pRight)
{
	const Type* pLeftType = _pLeft->getType();
	const Type* pRightType = _pRight->getType();

	if (pLeftType == nullptr || pRightType == nullptr) return error();

	// RightMatrix must be a matrix with the same Component Type as the Component Type in Result Type. Its number of columns must equal the number of columns in Result Type.
	// Its columns must have the same number of components as the number of columns in LeftMatrix.

	if (pLeftType->isMatrixOf(spv::Op::OpTypeFloat) && pRightType->isMatrixOf(spv::Op::OpTypeFloat) &&
		pLeftType->hasSameBase(*pRightType) && pLeftType->getMatrixColumnCount() == pRightType->front().getVectorComponentCount())
	{
		return makeOp(spv::Op::OpMatrixTimesMatrix, InvalidInstr, InvalidId, _pLeft, _pRight);
	}

	getModule()->logError("Operand of OpMatrixTimesMatrix is not a matrix of float type");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opSampledImage(Instruction* _pImage, Instruction* _pSampler)
{
	const Type* imageType = _pImage->getType();
	const Type* samplerType = _pSampler->getType();

	if (imageType == nullptr || samplerType == nullptr) return error();

	if (imageType->isImage() && samplerType->isSampler() && imageType->getImageSamplerAccess() != SamplerImageAccess::Storage && imageType->getImageDimension() != spv::Dim::SubpassData)
	{
		return makeOp(spv::Op::OpSampledImage, InvalidInstr, InvalidId, _pImage, _pSampler);
	}

	getModule()->logError("OpSampledImage: image or sampler type does not match (storage / subpass image not allowed)");
	
	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opImage(Instruction* _pSampledImage)
{
	const Type* type = _pSampledImage->getType();
	if (type == nullptr) return error();

	if (type->isSampledImage() == false)
	{
		getModule()->logError("Operand _pSampledImage of OpImage is not of type OpTypeSampledImage");
		return error();
	}

	return makeOp(spv::Op::OpImage, _pSampledImage->getResultTypeInstr()->getFirstActualOperand()->getInstruction(), InvalidId, _pSampledImage);
}

spvgentwo::Instruction* spvgentwo::Instruction::opImageQueryFormat(Instruction* _pImage)
{
	const Type* type = _pImage->getType();
	if (type == nullptr) return error();

	if (type->isImage() == false || type->getImageFormat() != spv::ImageFormat::Unknown)
	{
		getModule()->logError("Operand _pImage of OpImageQueryFormat is not of type OpTypeImage with Unknown ImageFormat");
		return error();
	}

	return makeOp(spv::Op::OpImageQueryFormat, InvalidInstr, InvalidId, _pImage);
}

spvgentwo::Instruction* spvgentwo::Instruction::opImageQueryOrder(Instruction* _pImage)
{
	const Type* type = _pImage->getType();
	if (type == nullptr) return error();

	if (type->isImage() == false || type->getImageFormat() != spv::ImageFormat::Unknown)
	{
		getModule()->logError("Operand _pImage of OpImageQueryOrder is not of type OpTypeImage with Unknown ImageFormat");
		return error();
	}

	return makeOp(spv::Op::OpImageQueryOrder, InvalidInstr, InvalidId, _pImage);
}

spvgentwo::Instruction* spvgentwo::Instruction::opImageQuerySizeLod(Instruction* _pImage, Instruction* _pLoDInt)
{
	const Type* type = _pImage->getType();
	if (type == nullptr) return error();

	if (type->isImage() == false)
	{
		getModule()->logError("Operand of OpImageQuerySizeLod is not of type OpTypeImage");
		return error();
	}
	else if (spv::Dim d = type->getImageDimension(); d != spv::Dim::Dim1D && d != spv::Dim::Dim2D && d != spv::Dim::Dim3D && d != spv::Dim::Cube)
	{
		getModule()->logError("Dimension of OpImageQuerySizeLod operand _pImage is not 1D, 2D, 3D or Cube");
		return error();
	}
	else if (type->getImageMultiSampled())
	{
		getModule()->logError("Operand _pImage of OpImageQuerySizeLod must not be MS 1 (multi sampled)");
		return error();
	}
	else if (const Type* lodType = _pLoDInt->getType(); lodType == nullptr || lodType->isUInt() == false)
	{
		getModule()->logError("Operand _pLoDInt of OpImageQuerySizeLod must be of type unsinged scalar integer");
		return error();
	}	

	return makeOp(spv::Op::OpImageQuerySizeLod, InvalidInstr, InvalidId, _pImage, _pLoDInt);
}

spvgentwo::Instruction* spvgentwo::Instruction::opImageQuerySize(Instruction* _pImage)
{
	const Type* type = _pImage->getType();
	if (type == nullptr) return error();

	if (type->isImage() == false)
	{
		getModule()->logError("Operand of OpImageQuerySize is not of type OpTypeImage");
		return error();
	}
	else if (spv::Dim d = type->getImageDimension(); d != spv::Dim::Dim1D && d != spv::Dim::Dim2D && d != spv::Dim::Dim3D && d != spv::Dim::Cube && d != spv::Dim::Rect)
	{
		getModule()->logError("Dimension of OpImageQuerySize operand _pImage is not 1D, 2D, 3D, Cube or Rect");
		return error();
	}
	else if (d != spv::Dim::Rect && type->getImageMultiSampled() == false && type->getImageSamplerAccess() == SamplerImageAccess::Sampled)
	{
		// Additionally, if its Dim is 1D, 2D, 3D, or Cube, it must also have either an MS of 1 or a Sampled of 0 or 2.
		getModule()->logError("Operand _pImage of OpImageQuerySize must have either an MS of 1 or a Sampled of 0 or 2");
		return error();
	}

	return makeOp(spv::Op::OpImageQuerySize, InvalidInstr, InvalidId, _pImage);
}

spvgentwo::Instruction* spvgentwo::Instruction::opImageQueryLod(Instruction* _pSampledImage, Instruction* _pCoordinate)
{
	return genericImageOp(spv::Op::OpImageQueryLod, _pSampledImage, _pCoordinate, nullptr, spv::ImageOperandsMask::MaskNone);
}

spvgentwo::Instruction* spvgentwo::Instruction::opImageQueryLevels(Instruction* _pImage)
{
	const Type* type = _pImage->getType();
	if (type == nullptr) return error();

	if (spv::Dim d = type->getImageDimension(); type->isImage() == false || (d != spv::Dim::Dim1D && d != spv::Dim::Dim2D && d != spv::Dim::Dim3D && d != spv::Dim::Cube))
	{
		getModule()->logError("Operand _pImage of OpImageQueryLevels is not of type OpTypeImage with dimension 1D, 2D, 3D or Cube");
		return error();
	}

	return makeOp(spv::Op::OpImageQueryLevels, InvalidInstr, InvalidId, _pImage);
}

spvgentwo::Instruction* spvgentwo::Instruction::opImageQuerySamples(Instruction* _pImage)
{
	const Type* type = _pImage->getType();
	if (type == nullptr) return error();

	if (type->isImage() == false || type->getImageDimension() != spv::Dim::Dim2D || type->getImageMultiSampled() == false)
	{
		getModule()->logError("Operand _pImage of OpImageQuerySamples is not of type OpTypeImage with dimension 2D and MS 1");
		return error();
	}

	return makeOp(spv::Op::OpImageQuerySamples, InvalidInstr, InvalidId, _pImage);
}

spvgentwo::Instruction* spvgentwo::Instruction::opUConvert(Instruction* _pUintVec, unsigned int _bitWidth)
{
	const Type* type = _pUintVec->getType();

	if (type == nullptr) return error();

	if (Type t = *type; t.isScalarOrVectorOf(spv::Op::OpTypeInt, 0u, 0u, Sign::Unsigned) && t.getBaseType().getIntWidth() != _bitWidth)
	{
		t.getBaseType().setIntWidth(_bitWidth);
		return makeOp(spv::Op::OpUConvert, getModule()->addType(t), InvalidId, _pUintVec);
	}

	getModule()->logError("Operand of OpUConvert is not a unsigned integer type with differing component width");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opSConvert(Instruction* _pSIntVec, unsigned int _bitWidth)
{
	const Type* type = _pSIntVec->getType();

	if (type == nullptr) return error();

	if (Type t = *type; t.isScalarOrVectorOf(spv::Op::OpTypeInt, 0u, 0u, Sign::Signed) && t.getBaseType().getIntWidth() != _bitWidth)
	{
		t.getBaseType().setIntWidth(_bitWidth);
		return makeOp(spv::Op::OpSConvert, getModule()->addType(t), InvalidId, _pSIntVec);
	}

	getModule()->logError("Operand of OpsConvert is not a signed integer type with differing component width");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opFConvert(Instruction* _pFloatVec, unsigned int _bitWidth)
{
	const Type* type = _pFloatVec->getType();

	if (type == nullptr) return error();

	// copy type for manipulation
	if (Type t = *type; t.isScalarOrVectorOf(spv::Op::OpTypeFloat) && t.getBaseType().getFloatWidth() != _bitWidth)
	{
		t.getBaseType().setFloatWidth(_bitWidth);
		return makeOp(spv::Op::OpFConvert, getModule()->addType(t), InvalidId, _pFloatVec);
	}

	getModule()->logError("Operand of OpFConvert is not a float type with differing component width");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opQuantizeToF16(Instruction* _pFloatVec)
{
	const Type* type = _pFloatVec->getType();

	if (type == nullptr) return error();

	if (type->isScalarOrVectorOf(spv::Op::OpTypeFloat, 0u, 32u))
	{
		return makeOp(spv::Op::OpQuantizeToF16, _pFloatVec->getResultTypeInstr(), InvalidId, _pFloatVec);
	}

	getModule()->logError("Operand of OpQuantizeToF16 is not a float type with 32 bit component width");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opConvertPtrToU(Instruction* _pPhysPtr, unsigned int _bitWidth)
{
	const Type* type = _pPhysPtr->getType();

	if (type == nullptr) return error();

	if (type->isPointer() && type->getStorageClass() == spv::StorageClass::PhysicalStorageBuffer)
	{
		Type t(getModule()->newType());
		return makeOp(spv::Op::OpConvertPtrToU, getModule()->addType(t.UInt(_bitWidth)), InvalidId, _pPhysPtr);
	}

	getModule()->logError("Operand of OpConvertPtrToU is not a physical pointer type");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::opBitcast(Instruction* _pResultType, Instruction* _pOperand)
{
	if (_pResultType == nullptr || _pOperand == nullptr) return error();

	const Type* resultType = _pResultType->getType();
	const Type* operandType = _pOperand->getType();

	if (resultType == nullptr || operandType == nullptr) return error();

	if (*resultType == *operandType)
	{
		getModule()->logError("Operand and result type of OpBitcast are identical");
		return error();
	}

	if ((operandType->isPointer() && resultType->isPointer()) || 
		(operandType->getScalarOrVectorLength() * operandType->getBaseType().getIntWidth() ==
			resultType->getScalarOrVectorLength() * resultType->getBaseType().getIntWidth()))
	{
		return makeOp(spv::Op::OpBitcast, _pResultType, InvalidId, _pOperand);
	}

	getModule()->logError("Operand or result type of OpBitcast is not a pointer or numerical scalar or vector type whose total bitwidth match");

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::toSpecOp()
{
	spv::Op opcode = m_Operation;
	m_Operation = spv::Op::OpSpecConstantOp;

	auto it = getFirstActualOperand();
	if (it == nullptr)
	{
		getModule()->logError("First actual operand for OpSpecConstantOp not found");
		return error();
	}

	insert_before(it, opcode);

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::error() const
{
	return getModule()->getErrorInstr();
}

bool spvgentwo::Instruction::checkImageCoordinateType(const Type* _pImageType, const Type* _pCoordType, Flag<CheckImgCoord> _args) const
{
	if (_pImageType->isImage() == false)
		return false;

	Module* module = getModule();

	unsigned int dim = getImageDimension(_pImageType->getImageDimension());

	if(dim == 0u)
	{
		module->logError("Image dimension not supported/implemented");
		return false;
	}

	if (_pImageType->getImageArray())
	{
		dim += 1u;
	}

	if (_args & CheckImgCoord::IsProjective)
	{
		dim += 1u;
	}

	if (dim > 1u && _pCoordType->getVectorComponentCount() < dim)
	{
		module->logError("Dimension of coordinates does not match image type");
		return false;
	}

	if (_pCoordType->isScalarOrVectorOf(spv::Op::OpTypeInt))
	{
		if (_args.none(CheckImgCoord::CanBeInt, CheckImgCoord::MustBeInt))
		{
			module->logError("Image operation does not support integer coordinates");
			return false;
		}
	}
	else if (_args & CheckImgCoord::MustBeInt)
	{
		module->logError("Coordinate type must be scalar or vector of integer");
		return false;
	}
	else if (_pCoordType->isScalarOrVectorOf(spv::Op::OpTypeFloat) == false)
	{
		module->logError("Coordinate type must be scalar or vector of float");
		return false;
	}

	return true;
}

spvgentwo::Instruction* spvgentwo::Instruction::scalarVecOp(spv::Op _op, spv::Op _type, Sign _sign, Instruction* _pLeft, Instruction* _pRight, const char* _pErrorMsg, bool _checkSign)
{
	if (_pLeft == nullptr) return error();

	const Type* pLeftType = _pLeft->getType();
	const Type* pRightType = _pRight != nullptr ? _pRight->getType() : nullptr;

	if (pLeftType == nullptr) return error();

	if (_pRight == nullptr && pLeftType->isScalarOrVectorOf(_type) && (!_checkSign || pLeftType->getBaseType().hasSign(_sign)))
	{
		return makeOp(_op, InvalidInstr, InvalidId, _pLeft);
	}
	else if (pRightType != nullptr && pLeftType->isScalarOrVectorOfSameLength(_type, *pRightType) && (!_checkSign || (pLeftType->getBaseType().hasSign(_sign) && pRightType->getBaseType().hasSign(_sign))))
	{
		return makeOp(_op, InvalidInstr, InvalidId, _pLeft, _pRight);
	}
	if (_pErrorMsg != nullptr)
	{
		getModule()->logError(_pErrorMsg);
	}
	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::scalarVecOp(spv::Op _op, Instruction* _pLeft, Instruction* _pRight, const char* _pErrorMsg, bool _checkSign)
{
	Sign sign = Sign::Any;
	const spv::Op type = getTypeFromOp(_op, sign);

	if (type == spv::Op::OpNop)
	{
		getModule()->logError("Could not derive operand type from instruction _op");
		return error();
	}

	return scalarVecOp(_op, type, sign, _pLeft, _pRight, _pErrorMsg, _checkSign);
}

spvgentwo::Instruction* spvgentwo::Instruction::intFloatOp(Instruction* _pLeft, Instruction* _pRight, DualOpMemberFun _intFun, DualOpMemberFun _floatFun, const char* _pErrorMsg)
{
	if (_pLeft == nullptr || _pRight == nullptr) return error();

	const Type* lType = _pLeft->getType();
	const Type* rType = _pRight->getType();

	if (lType == nullptr || rType == nullptr) return error();

	if (lType->getBaseType().isInt() && rType->getBaseType().isInt())
	{
		return (this->*_intFun)(_pLeft, _pRight);
	}
	else if (lType->getBaseType().isFloat() && rType->getBaseType().isFloat())
	{
		return (this->*_floatFun)(_pLeft, _pRight);
	}

	if (_pErrorMsg != nullptr)
	{
		getModule()->logError(_pErrorMsg);
	}

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::intFloatBoolOp(Instruction* _pLeft, Instruction* _pRight, DualOpMemberFun _intFun, DualOpMemberFun _floatFun, DualOpMemberFun _boolFun, const char* _pErrorMsg)
{
	if (_pLeft == nullptr || _pRight == nullptr) return error();

	const Type* lType = _pLeft->getType();
	const Type* rType = _pRight->getType();

	if (lType == nullptr || rType == nullptr) return error();

	if (_intFun != nullptr && lType->getBaseType().isInt() && rType->getBaseType().isInt())
	{
		return (this->*_intFun)(_pLeft, _pRight);
	}
	else if (_floatFun != nullptr && lType->getBaseType().isFloat() && rType->getBaseType().isFloat())
	{
		return (this->*_floatFun)(_pLeft, _pRight);
	}
	else if (_boolFun != nullptr && lType->getBaseType().isBool() && rType->getBaseType().isBool())
	{
		return (this->*_boolFun)(_pLeft, _pRight);
	}

	if (_pErrorMsg != nullptr)
	{
		getModule()->logError(_pErrorMsg);
	}

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::intFloatOp(Instruction* _pLeft, Instruction* _pRight, DualOpMemberFun _sIntFun, DualOpMemberFun _uIntFun, DualOpMemberFun _floatFun, const char* _pErrorMsg)
{
	if (_pLeft == nullptr || _pRight == nullptr) return error();

	const Type* lType = _pLeft->getType();
	const Type* rType = _pRight->getType();

	if (lType == nullptr || rType == nullptr) return error();

	if (_uIntFun != nullptr && lType->getBaseType().isUInt() && rType->getBaseType().isUInt())
	{
		return (this->*_uIntFun)(_pLeft, _pRight);
	}
	else if (_sIntFun != nullptr && lType->getBaseType().isInt() && rType->getBaseType().isInt()) // if l or r is unsinged call signed func
	{
		return (this->*_sIntFun)(_pLeft, _pRight);
	}
	else if (_floatFun != nullptr && lType->getBaseType().isFloat() && rType->getBaseType().isFloat())
	{
		return (this->*_floatFun)(_pLeft, _pRight);
	}

	if (_pErrorMsg != nullptr)
	{
		getModule()->logError(_pErrorMsg);
	}

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::intFloatBoolOp(Instruction* _pLeft, Instruction* _pRight, DualOpMemberFun _sIntFun, DualOpMemberFun _uIntFun, DualOpMemberFun _floatFun, DualOpMemberFun _boolFun, const char* _pErrorMsg)
{
	if (_pLeft == nullptr || _pRight == nullptr) return error();

	const Type* lType = _pLeft->getType();
	const Type* rType = _pRight->getType();

	if (lType == nullptr || rType == nullptr) return error();

	if (_uIntFun != nullptr && lType->getBaseType().isUInt() && rType->getBaseType().isUInt())
	{
		return (this->*_uIntFun)(_pLeft, _pRight);
	}
	else if (_sIntFun != nullptr && lType->getBaseType().isInt() && rType->getBaseType().isInt()) // if l or r is unsinged call signed func
	{
		return (this->*_sIntFun)(_pLeft, _pRight);
	}
	else if (_floatFun != nullptr && lType->getBaseType().isFloat() && rType->getBaseType().isFloat())
	{
		return (this->*_floatFun)(_pLeft, _pRight);
	}
	else if (_boolFun != nullptr && lType->getBaseType().isBool() && rType->getBaseType().isBool())
	{
		return (this->*_boolFun)(_pLeft, _pRight);
	}

	if (_pErrorMsg != nullptr)
	{
		getModule()->logError(_pErrorMsg);
	}

	return error();
}

spvgentwo::Instruction* spvgentwo::Instruction::inferResultTypeOperand()
{
	Instruction* pResultType = nullptr;

	// operation has a result type and user passed nullptr
	if (hasResultType())
	{
		if (empty() || front().isInstruction() == false)
		{
			getModule()->logError("result type operand not present or incorrect type");
			return pResultType;
		}

		Operand& retType = front();

		ITypeInferenceAndVailation* validator = getModule()->getTypeInferenceAndVailation();
		const bool allowOverride = validator != nullptr && validator->overridePredefinedResultType();

		if(retType.instruction == nullptr || allowOverride)
		{
			pResultType = validator != nullptr ? validator->inferResultType(*this) : defaultimpl::inferResultType(*this);
			retType = pResultType;
		}
		else
		{
			pResultType = retType.instruction;
		}
	}

	return pResultType;
}

bool spvgentwo::Instruction::validateOperands()
{
	ITypeInferenceAndVailation* validator = getModule()->getTypeInferenceAndVailation();
	return validator != nullptr ? validator->validateOperands(*this) : defaultimpl::validateOperands(*this);
}

bool spvgentwo::Instruction::isErrorInstr() const
{
	return getModule()->getErrorInstr() == this;
}

spvgentwo::Instruction::Iterator spvgentwo::getLiteralString(String& _out, Instruction::Iterator _it, Instruction::Iterator _end)
{
	for (; _it != _end; ++_it)
	{
		if (_it->isLiteral() == false)
		{
			return _it;
		}

		const char* str = reinterpret_cast<const char*>(&_it->literal.value);
		for (unsigned int i = 0u; i < sizeof(unsigned int); ++i)
		{
			if (str[i] == '\0')
				return _it.next();
			_out.emplace_back(str[i]);
		}
	}

	return _it;
}

spvgentwo::Instruction::Iterator spvgentwo::skipLiteralString(Instruction::Iterator _begin)
{
	for (; _begin != nullptr && _begin->isLiteral(); ++_begin)
	{ 
		if (hasStringTerminator(_begin->literal))
		{
			return _begin.next();
		}
	}
	return _begin;
}

bool spvgentwo::compareLiteralString(const char* _pStr, Instruction::Iterator _begin, Instruction::Iterator _end, sgt_size_t _StrLength)
{
	sgt_size_t j = 0u;
	for (auto it = _begin; it != _end && it->isLiteral() && j < _StrLength; ++it)
	{
		const char* str = reinterpret_cast<const char*>(&it->literal.value);
		for (unsigned int i = 0u; i < sizeof(unsigned int); ++i)
		{
			if (str[i] == '\0' && _pStr[j] == '\0')
			{
				return true;
			}
			else if (str[i] != _pStr[j++])
			{
				return false;
			}
		}
	};
	return true;
}
