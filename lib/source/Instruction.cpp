#include "Instruction.h"
#include "BasicBlock.h"
#include "Type.h"
#include "Writer.h"
#include "InferResultType.h"
#include "Module.h"

spvgentwo::Instruction::~Instruction()
{
}

spvgentwo::BasicBlock* spvgentwo::Instruction::getBasicBlock()
{
	return m_parentType == ParentType::BasicBlock ? m_parent.pBasicBlock : nullptr;
}

const spvgentwo::BasicBlock* spvgentwo::Instruction::getBasicBlock() const
{
	return m_parentType == ParentType::BasicBlock ? m_parent.pBasicBlock : nullptr;
}

spvgentwo::Function* spvgentwo::Instruction::getFunction()
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

const spvgentwo::Function* spvgentwo::Instruction::getFunction() const
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

spvgentwo::Module* spvgentwo::Instruction::getModule()
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

const spvgentwo::Module* spvgentwo::Instruction::getModule() const
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

spv::Id spvgentwo::Instruction::getResultId() const
{
	bool resultId = false, resultType = false;
	spv::HasResultAndType(m_Operation, &resultId, &resultType);

	if (resultId == false/* || empty()*/)
		return InvalidId;

	auto it = begin();
	if (resultType /*&& size() > 1u*/) // skip resultType operand 
	{
		++it;
	}
	return it->getResultId();
}

void spvgentwo::Instruction::resolveId(spv::Id& _resultId)
{
	for (Operand& op : *this)
	{
		switch (op.type)
		{
		case Operand::Type::Instruction:
			op.instruction->resolveId(_resultId);
			break;
		case Operand::Type::BranchTarget:
			op.branchTarget->front().resolveId(_resultId);
			break;
		default:
			break;
		}
	}

	bool resultId = false, resultType = false;
	spv::HasResultAndType(m_Operation, &resultId, &resultType);

	if (resultId == false /*|| empty()*/)
		return;

	auto it = begin();
	if (resultType /*&& size() > 1u*/) // skip resultType operand 
	{
		++it;
	}

	if (it->resultId == InvalidId)
	{
		it->resultId = ++_resultId;
	}
}

spvgentwo::Instruction* spvgentwo::Instruction::getTypeInst() const
{
	if (hasResultType()/* && empty() == false*/)
	{
		return front().getInstruction();
	}
	return nullptr;
}

const spvgentwo::Type* spvgentwo::Instruction::getType() const
{
	const Module* pModule = getModule();
	if (isType()) 
	{
		return pModule->getTypeInfo(this);
	}

	return pModule->getTypeInfo(getTypeInst());
}

spv::StorageClass spvgentwo::Instruction::getStorageClass() const
{
	switch (m_Operation)
	{
	case spv::Op::OpTypePointer:
		return static_cast<spv::StorageClass>((begin() + 1)->getLiteral().value);
	case spv::Op::OpVariable:
		return static_cast<spv::StorageClass>((begin() + 2)->getLiteral().value);
	default:
		return spv::StorageClass::Max;
	}
}

bool spvgentwo::Instruction::isType() const
{
	return isTypeOp(m_Operation);
}

bool spvgentwo::Instruction::isTerminator() const
{
	return isTerminatorOp(m_Operation);
}

void spvgentwo::Instruction::write(IWriter* _pWriter, spv::Id& _resultId)
{
	resolveId(_resultId);

	_pWriter->put(getOpCode());
	
	for (const Operand& operand : *this)
	{
		operand.write(_pWriter);
	}
}

void spvgentwo::writeInstructions(IWriter* _pWriter, const List<Instruction>& _instructions, spv::Id& _resultId)
{
	for (Instruction& instr : _instructions)
	{
		instr.write(_pWriter, _resultId);
	}
}

spvgentwo::Instruction* spvgentwo::Instruction::makeOp(const spv::Op _instOp, Instruction* _pOp1, Instruction* _pOp2, Instruction* _pOp3, Instruction* _pResultType)
{
	Instruction* pResultType = _pResultType != nullptr ? _pResultType : inferType(_instOp, _pOp1, _pOp2, _pOp3);
	Instruction* pInst = makeOpEx(_instOp, pResultType, InvalidId, _pOp1);

	if (_pOp2 != nullptr)
	{
		pInst->addOperand(_pOp2);
	}
	if (_pOp3 != nullptr)
	{
		pInst->addOperand(_pOp3);
	}

	return pInst;
}

spvgentwo::Instruction* spvgentwo::Instruction::variable(Instruction* _pPtrType, const spv::StorageClass _storageClass, Instruction* _pInitialzer)
{
	return opVariable(_pPtrType, _storageClass, _pInitialzer);
}

void spvgentwo::Instruction::opNop()
{
	makeOpEx(spv::Op::OpNop);
}

spvgentwo::Instruction* spvgentwo::Instruction::opUndef(Instruction* _pResultType)
{
	return makeOpEx(spv::Op::OpUndef, _pResultType, InvalidId);
}

spvgentwo::Instruction* spvgentwo::Instruction::opSizeOf(Instruction* _pPointerToVar)
{
	return makeOp(spv::Op::OpSizeOf, _pPointerToVar);
}

void spvgentwo::Instruction::opCapability(const spv::Capability _capability)
{
	makeOpEx(spv::Op::OpCapability, _capability);
}

void spvgentwo::Instruction::opMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel)
{
	makeOpEx(spv::Op::OpMemoryModel, _addressModel, _memoryModel);
}

void spvgentwo::Instruction::opExtension(const char* _pExtName)
{
	makeOpEx(spv::Op::OpExtension, _pExtName);
}

spvgentwo::Instruction* spvgentwo::Instruction::opExtInstImport(const char* _pExtName)
{
	return makeOpEx(spv::Op::OpExtInstImport, InvalidId, _pExtName);
}

spvgentwo::Instruction* spvgentwo::Instruction::opLabel()
{
	return makeOpEx(spv::Op::OpLabel, InvalidId);
}

spvgentwo::Instruction* spvgentwo::Instruction::opFunction(const Flag<spv::FunctionControlMask> _functionControl, Instruction* _pResultType, Instruction* _pFuncType)
{
	return makeOpEx(spv::Op::OpFunction, _pResultType, InvalidId, literal_t{ _functionControl.mask }, _pFuncType);
}

spvgentwo::Instruction* spvgentwo::Instruction::opFunctionParameter(Instruction* _pType)
{
	return makeOpEx(spv::Op::OpFunctionParameter, _pType, InvalidId);
}

void spvgentwo::Instruction::opReturn()
{
	makeOpEx(spv::Op::OpReturn);
}

void spvgentwo::Instruction::opReturnValue(Instruction* _pValue)
{
	makeOpEx(spv::Op::OpReturnValue, _pValue);
}

void spvgentwo::Instruction::opFunctionEnd()
{
	makeOpEx(spv::Op::OpFunctionEnd);
}

void spvgentwo::Instruction::opName(Instruction* _pTarget, const char* _pName)
{
	makeOpEx(spv::Op::OpName, _pTarget, _pName);
}

void spvgentwo::Instruction::opMemberName(Instruction* _pTargetStructType, unsigned int _memberIndex, const char* _pName)
{
	makeOpEx(spv::Op::OpMemberName, _pTargetStructType, _memberIndex, _pName);
}

void spvgentwo::Instruction::opSelectionMerge(BasicBlock* _pMergeBlock, const spv::SelectionControlMask _control)
{
	makeOpEx(spv::Op::OpSelectionMerge, _pMergeBlock, _control);
}

void spvgentwo::Instruction::opBranch(BasicBlock* _pTargetBlock)
{
	makeOpEx(spv::Op::OpBranch, _pTargetBlock);
}

void spvgentwo::Instruction::opBranchConditional(Instruction* _pCondition, BasicBlock* _pTrueBlock, BasicBlock* _pFalseBlock)
{
	makeOpEx(spv::Op::OpBranchConditional, _pCondition, _pTrueBlock, _pFalseBlock);
}

void spvgentwo::Instruction::opBranchConditional(Instruction* _pCondition, BasicBlock* _pTrueBlock, BasicBlock* _pFalseBlock, const unsigned int _trueWeight, const unsigned int _falseWeight)
{
	makeOpEx(spv::Op::OpBranchConditional, _pCondition, _pTrueBlock, _pFalseBlock, _trueWeight, _falseWeight);
}

spvgentwo::Instruction* spvgentwo::Instruction::opVariable(Instruction* _pResultType, const spv::StorageClass _storageClass, Instruction* _pInitializer)
{
	if (_pInitializer == nullptr)
	{
		return makeOpEx(spv::Op::OpVariable, _pResultType, InvalidId, _storageClass);
	}
	else
	{
		return makeOpEx(spv::Op::OpVariable, _pResultType, InvalidId, _storageClass, _pInitializer);
	}
}

spvgentwo::Instruction* spvgentwo::Instruction::opOuterProduct(Instruction* _pLeft, Instruction* _pRight)
{
	Instruction* _pLeftTypeInstr = _pLeft->getTypeInst();
	Instruction* _pRightTypeInstr = _pRight->getTypeInst();

	const Type* pLeftType = _pLeftTypeInstr->getType();
	const Type* pRightType = _pLeftTypeInstr->getType();

	if (pLeftType->isVectorOfFloat() && pRightType->isVectorOfFloat() && pLeftType->hasSameBase(*pRightType))
	{
		return makeOp(spv::Op::OpOuterProduct, _pLeft, _pRight);
	}

	getModule()->logError("Operands of opOuterProduct are not scalar vector of length 3");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::Instruction::opDot(Instruction* _pLeft, Instruction* _pRight)
{
	Instruction* _pLeftTypeInstr = _pLeft->getTypeInst();
	Instruction* _pRightTypeInstr = _pRight->getTypeInst();

	const Type* pType = _pLeftTypeInstr->getType();
	if (_pLeftTypeInstr == _pRightTypeInstr && pType->isVectorOfFloat())
	{
		return makeOp(spv::Op::OpDot, _pLeft, _pRight);
	}

	getModule()->logError("Operands of opDot are not scalar vector of length 3");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::Instruction::opAny(Instruction* _pBoolVec)
{
	if (_pBoolVec->getType()->isVectorOfBool())
	{
		return makeOp(spv::Op::OpAny, _pBoolVec);
	}

	getModule()->logError("Operands of opAny is not a vector of bool");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::Instruction::opAll(Instruction* _pBoolVec)
{
	if (_pBoolVec->getType()->isVectorOfBool())
	{
		return makeOp(spv::Op::OpAll, _pBoolVec);
	}

	getModule()->logError("Operands of opAll is not a vector of bool");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::Instruction::opCopyObject(Instruction* _pObject)
{
	return makeOpEx(spv::Op::OpCopyObject, _pObject->getTypeInst(), InvalidId, _pObject);
}

spvgentwo::Instruction* spvgentwo::Instruction::opTranspose(Instruction* _pMatrix)
{
	return makeOp(spv::Op::OpTranspose, _pMatrix);
}