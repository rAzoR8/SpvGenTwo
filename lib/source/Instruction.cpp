#include "spvgentwo/Instruction.h"
#include "spvgentwo/BasicBlock.h"
#include "spvgentwo/Type.h"
#include "spvgentwo/Writer.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/TypeInferenceAndValiation.h"

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

const char* spvgentwo::Instruction::getName() const
{
	return getModule()->getName(this);
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

spv::Id spvgentwo::Instruction::getResultId() const
{
	auto it = getResultIdOperand();
	if (it == nullptr) return InvalidId;
	return it->getResultId();
}

spv::Id spvgentwo::Instruction::resolveId(spv::Id& _previousId)
{
	for (Operand& op : *this)
	{
		switch (op.type)
		{
		case Operand::Type::Instruction:
			if (getModule()->logError(op.instruction != nullptr, "Invalid instruction operand (null)") == false)
			{	
				return InvalidId;
			}
			op.instruction->resolveId(_previousId);
			break;
		case Operand::Type::BranchTarget:
			if (getModule()->logError(op.branchTarget != nullptr, "Invalid branch target operand (null)") == false)
			{
				return InvalidId;
			}
			op.branchTarget->front().resolveId(_previousId);
			break;
		default:
			break;
		}
	}

	auto it = getResultIdOperand();
	if (it == nullptr) return InvalidId;

	if (it->resultId == InvalidId)
	{
		it->resultId = ++_previousId;
	}

	return it->resultId;
}

spvgentwo::Instruction* spvgentwo::Instruction::getTypeInstr() const
{
	if (hasResultType())
	{
		return front().getInstruction();
	}

	getModule()->logError("Instruction has no result type");

	return nullptr;
}

const spvgentwo::Type* spvgentwo::Instruction::getType() const
{
	const Module* pModule = getModule();
	if (isType()) 
	{
		return pModule->getTypeInfo(this);
	}

	return pModule->getTypeInfo(getTypeInstr());
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

bool spvgentwo::Instruction::isConstant() const
{
	return isConstantOp(m_Operation);
}

bool spvgentwo::Instruction::isSpecConstant() const
{
	return isSpecOp(m_Operation);
}

bool spvgentwo::Instruction::isSpecOrConstant() const
{
	return isSpecOrConstantOp(m_Operation);
}

void spvgentwo::Instruction::write(IWriter* _pWriter)
{
	_pWriter->put(getOpCode());
	
	for (const Operand& operand : *this)
	{
		operand.write(_pWriter);
	}
}

spvgentwo::Instruction* spvgentwo::Instruction::Mul(Instruction* _pLeft, Instruction* _pRight)
{
	const Type* lType = _pLeft->getType();
	const Type* rType = _pRight->getType();

	if (lType == nullptr || rType == nullptr) return this;

	if (lType->isInt() && rType->isInt())
	{
		return opIMul(_pLeft, _pRight);
	}
	else if (lType->isFloat() && rType->isFloat())
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

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::Div(Instruction* _pLeft, Instruction* _pRight, bool _allowVecDividedByScalar)
{
	const Type* lType = _pLeft->getType();
	const Type* rType = _pRight->getType();

	if (lType == nullptr || rType == nullptr) return this;

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

		// TODO: find a better way to construct constants from a Type with a value thats not exaclty of type, e.g. getModule()->constant(lType, 1)
		if (rType->isF32())
		{
			one = getModule()->constant(1.f);
		}
		else if (rType->isF64())
		{
			one = getModule()->constant(1.0);
		}
		else if (rType->isInt(32u))
		{
			one = getModule()->constant(1u);
		}
		else if (rType->isInt(64u))
		{
			one = getModule()->constant(1ull);
		}

		if (one != nullptr)
		{			
			// vec / scalar => vec * ( 1 / scalar )
			return (*bb)->Mul(_pLeft, Div(one, _pRight));
		}
	}

	getModule()->logError("Failed to match Div's operand types for this instruction");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::Not(Instruction* _pIntOrBool)
{
	const Type* type = _pIntOrBool->getType();

	if (type == nullptr) return this;

	if (type->isBaseTypeOf(spv::Op::OpTypeInt))
	{
		return opNot(_pIntOrBool);
	}
	else if (type->isBaseTypeOf(spv::Op::OpTypeBool))
	{
		return opLogicalNot(_pIntOrBool);
	}

	return this;
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
	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opSizeOf(Instruction* _pPointerToVar)
{
	const Type* ptrType = _pPointerToVar->getType();
	if (ptrType == nullptr) return this;

	if (ptrType->isPointer())
	{
		return makeOp(spv::Op::OpSizeOf, InvalidInstr, InvalidId, _pPointerToVar);	
	}
	getModule()->logError("Operand of opSizeOf must be a pointer to a concrete type");
	return this;
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
		return makeOp(spv::Op::OpFunction, _pResultType, InvalidId, literal_t{ _functionControl.mask }, _pFuncType);
	}
	getModule()->logError("ResultType operand of opFunction must type instruction, function type instruction must be OpTypeFunction");
	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opFunctionParameter(Instruction* _pType)
{
	if (_pType->isType())
	{
		return makeOp(spv::Op::OpFunctionParameter, _pType, InvalidId);
	}
	getModule()->logError("Operand of opFunctionParameter must type instruction");
	return this;
}

void spvgentwo::Instruction::opReturn()
{
	makeOp(spv::Op::OpReturn);
}

void spvgentwo::Instruction::opReturnValue(Instruction* _pValue)
{
	Function* func = getFunction();
	if (func != nullptr && (func->getReturnType() != nullptr && func->getReturnType()->getType() == _pValue->getType()))
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

spvgentwo::Instruction* spvgentwo::Instruction::opVariable(Instruction* _pResultType, const spv::StorageClass _storageClass, Instruction* _pInitializer)
{
	if (_pInitializer == nullptr)
	{
		return makeOp(spv::Op::OpVariable, _pResultType, InvalidId, _storageClass);
	}
	else
	{
		return makeOp(spv::Op::OpVariable, _pResultType, InvalidId, _storageClass, _pInitializer);
	}
}

spvgentwo::Instruction* spvgentwo::Instruction::opOuterProduct(Instruction* _pLeft, Instruction* _pRight)
{
	const Type* pLeftType = _pLeft->getType();
	const Type* pRightType = _pRight->getType();

	if (pLeftType == nullptr || pRightType == nullptr) return this;

	if (pLeftType->isVectorOfFloat() && pRightType->isVectorOfFloat() && pLeftType->hasSameBase(*pRightType))
	{
		return makeOp(spv::Op::OpOuterProduct, InvalidInstr, InvalidId, _pLeft, _pRight);
	}

	getModule()->logError("Operands of opOuterProduct are not scalar vector of length 3");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opDot(Instruction* _pLeft, Instruction* _pRight)
{
	Instruction* pLeftTypeInstr = _pLeft->getTypeInstr();
	Instruction* pRightTypeInstr = _pRight->getTypeInstr();

	if (pLeftTypeInstr == nullptr || pRightTypeInstr == nullptr) return this;

	const Type* pType = pLeftTypeInstr->getType();
	if (pLeftTypeInstr == pRightTypeInstr && pType->isVectorOfFloat())
	{
		return makeOp(spv::Op::OpDot, InvalidInstr, InvalidId, _pLeft, _pRight);
	}

	getModule()->logError("Operands of opDot are not scalar vector of length 3");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opAny(Instruction* _pBoolVec)
{
	const Type* type = _pBoolVec->getType();
	if (type == nullptr) return this;

	if (type->isVectorOfBool())
	{
		return makeOp(spv::Op::OpAny, InvalidInstr, InvalidId, _pBoolVec);
	}

	getModule()->logError("Operands of opAny is not a vector of bool");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opAll(Instruction* _pBoolVec)
{
	const Type* type = _pBoolVec->getType();
	if (type == nullptr) return this;

	if (type->isVectorOfBool())
	{
		return makeOp(spv::Op::OpAll, InvalidInstr, InvalidId, _pBoolVec);
	}

	getModule()->logError("Operands of opAll is not a vector of bool");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opCopyObject(Instruction* _pObject)
{
	return makeOp(spv::Op::OpCopyObject, _pObject->getTypeInstr(), InvalidId, _pObject);
}

spvgentwo::Instruction* spvgentwo::Instruction::opTranspose(Instruction* _pMatrix)
{
	const Type* type = _pMatrix->getType();
	if (type == nullptr) return this;

	if (type->isMatrix())
	{
		return makeOp(spv::Op::OpTranspose, InvalidInstr, InvalidId, _pMatrix);	
	}

	getModule()->logError("Operand of opTranspose is not a matrix type");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opVectorExtractDynamic(Instruction* _pVector, Instruction* _pIndexInt)
{
	const Type* vecType = _pVector->getType();
	const Type* indexType = _pIndexInt->getType();
	if (vecType == nullptr || indexType == nullptr) return this;

	if (vecType->isVector() && indexType->isInt())
	{
		auto component = _pVector->getTypeInstr()->getFirstActualOperand();
		return makeOp(spv::Op::OpVectorExtractDynamic, component->getInstruction(), InvalidId, _pVector, _pIndexInt);	
	}

	getModule()->logError("opVectorExtractDynamic: _pVector must be of type vector, _pIndexInt must be of type integer");
	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opVectorInsertDynamic(Instruction* _pVector, Instruction* _pComponent, Instruction* _pIndexInt)
{
	const Type* pVecType = _pVector->getType();
	const Type* indexType = _pIndexInt->getType();
	if (pVecType == nullptr || indexType == nullptr) return this;

	if (pVecType->isVector() && pVecType->front() == *_pComponent->getType() && indexType->isInt())
	{
		return makeOp(spv::Op::OpVectorInsertDynamic, InvalidInstr, InvalidId, _pVector, _pComponent, _pIndexInt);
	}

	getModule()->logError("opVectorInsertDyanmic: _pVector component type does not match type of _pComponent or _pIndexInt is not of type integer");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opSelect(Instruction* _pCondBool, Instruction* _pTrueObj, Instruction* _pFalseObj)
{
	const Type* trueType = _pTrueObj->getType();
	const Type* falseType = _pFalseObj->getType();
	const Type* condType = _pCondBool->getType();

	if (trueType == nullptr || falseType == false || condType == false) return this;

	if (*trueType == *falseType && condType->isScalarOrVectorOf(spv::Op::OpTypeBool) && 
		condType->getVectorComponentCount() == trueType->getVectorComponentCount())
	{
		// Before version1.4, results are only computed per component.
		// Before version1.4, Result Type must be a pointer, scalar, or vector.Starting withv ersion1.4, Result Type can additionally be a composite type other than a vector.

		if (trueType->isScalar() || trueType->isVector() || trueType->isPointer() ||
			(getModule()->getSpvVersion() >= makeVersion(1u, 4u) && trueType->isComposite()))
		{
			return makeOp(spv::Op::OpSelect, _pTrueObj->getTypeInstr(), InvalidId, _pCondBool, _pTrueObj, _pFalseObj);
		}

		getModule()->logError("Object arguments of opSelect are not of type Scalar|Vector|Pointer|Composite");

		return this;
	}

	getModule()->logError("Condition type does not match extent of object arguments");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opVectorTimesScalar(Instruction* _pVector, Instruction* _pScalar)
{
	const Type* pVecType = _pVector->getType();
	const Type* pScalarType = _pScalar->getType();

	if (pVecType == nullptr || pScalarType == nullptr) return this;

	if (pScalarType->isFloat() && pVecType->isVectorOfFloat(0u, pScalarType->getFloatWidth()))
	{
		return makeOp(spv::Op::OpVectorTimesScalar, _pVector->getTypeInstr(), InvalidId, _pVector, _pScalar);
	}

	getModule()->logError("Operand of OpVectorTimesScalar is not a scalar or vector of float type");
	
	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opMatrixTimesScalar(Instruction* _pMatrix, Instruction* _pScalar)
{
	const Type* pMatType = _pMatrix->getType();
	const Type* pScalarType = _pScalar->getType();

	if (pMatType == nullptr || pScalarType == nullptr) return this;

	if (pScalarType->isFloat() && pMatType->hasSameBase(*pScalarType) && pMatType->isMatrix())
	{
		return makeOp(spv::Op::OpMatrixTimesScalar, _pMatrix->getTypeInstr(), InvalidId, _pMatrix, _pScalar);
	}

	getModule()->logError("Operand of OpMatrixTimesScalar is not a scalar or matrix of float type");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opVectorTimesMatrix(Instruction* _pVector, Instruction* _pMatrix)
{
	const Type* pVecType = _pVector->getType();
	const Type* pMatType = _pMatrix->getType();

	if (pVecType == nullptr || pMatType == nullptr) return this;

	if (pVecType->isVectorOfFloat() && pMatType->isMatrix() && pMatType->hasSameBase(*pVecType) && pMatType->front().getVectorComponentCount() == pVecType->getVectorComponentCount())
	{
		return makeOp(spv::Op::OpVectorTimesMatrix, _pVector->getTypeInstr(), InvalidId, _pVector, _pMatrix);
	}

	getModule()->logError("Operand of OpVectorTimesMatrix is not a vector or matrix of float type");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opMatrixTimesVector(Instruction* _pMatrix, Instruction* _pVector)
{
	const Type* pMatType = _pMatrix->getType();
	const Type* pVecType = _pVector->getType();

	if (pVecType == nullptr || pMatType == nullptr) return this;

	if (pVecType->isVectorOfFloat() && pMatType->isMatrix() && pMatType->hasSameBase(*pVecType) && pMatType->getMatrixColumnCount() == pVecType->getVectorComponentCount())
	{
		return makeOp(spv::Op::OpMatrixTimesVector, InvalidInstr, InvalidId, _pMatrix, _pVector);
	}

	getModule()->logError("Operand of OpMatrixTimesVector is not a vector or matrix of float type");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opMatrixTimesMatrix(Instruction* _pLeft, Instruction* _pRight)
{
	const Type* pLeftType = _pLeft->getType();
	const Type* pRightType = _pRight->getType();

	if (pLeftType == nullptr || pRightType == nullptr) return this;

	// RightMatrix must be a matrix with the same Component Type as the Component Type in Result Type. Its number of columns must equal the number of columns in Result Type.
	// Its columns must have the same number of components as the number of columns in LeftMatrix.

	if (pLeftType->isMatrixOf(spv::Op::OpTypeFloat) && pRightType->isMatrixOf(spv::Op::OpTypeFloat) &&
		pLeftType->hasSameBase(*pRightType) && pLeftType->getMatrixColumnCount() == pRightType->front().getVectorComponentCount())
	{
		return makeOp(spv::Op::OpMatrixTimesMatrix, InvalidInstr, InvalidId, _pLeft, _pRight);
	}

	getModule()->logError("Operand of OpMatrixTimesMatrix is not a matrix of float type");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opSampledImage(Instruction* _pImage, Instruction* _pSampler)
{
	const Type* imageType = _pImage->getType();
	const Type* samplerType = _pSampler->getType();

	if (imageType == nullptr || samplerType == nullptr) return this;

	if (imageType->isImage() && samplerType->isSampler() && imageType->getImageSamplerAccess() != SamplerImageAccess::Storage && imageType->getImageDimension() != spv::Dim::SubpassData)
	{
		return makeOp(spv::Op::OpSampledImage, InvalidInstr, InvalidId, _pImage, _pSampler);
	}

	getModule()->logError("Image or sampler type does not match (storage / subpass image not allowed)");
	
	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opUConvert(Instruction* _pUintVec, unsigned int _bitWidth)
{
	const Type* type = _pUintVec->getType();

	if (type == nullptr) return this;

	if (Type t = type->getBaseType(); t.isScalarOrVectorOf(spv::Op::OpTypeInt, 0u, 0u, Sign::Unsigned) && t.getIntWidth() != _bitWidth)
	{
		t.getBaseType().setIntWidth(_bitWidth);
		return makeOp(spv::Op::OpUConvert, getModule()->addType(t), InvalidId, _pUintVec);
	}

	getModule()->logError("Operand of OpUConvert is not a unsigned integer type with differing component width");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opSConvert(Instruction* _pSIntVec, unsigned int _bitWidth)
{
	const Type* type = _pSIntVec->getType();

	if (type == nullptr) return this;

	if (Type t = type->getBaseType(); t.isScalarOrVectorOf(spv::Op::OpTypeInt, 0u, 0u, Sign::Signed) && t.getIntWidth() != _bitWidth)
	{
		t.getBaseType().setIntWidth(_bitWidth);
		return makeOp(spv::Op::OpSConvert, getModule()->addType(t), InvalidId, _pSIntVec);
	}

	getModule()->logError("Operand of OpsConvert is not a signed integer type with differing component width");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opFConvert(Instruction* _pFloatVec, unsigned int _bitWidth)
{
	const Type* type = _pFloatVec->getType();

	if (type == nullptr) return this;

	if (Type t = type->getBaseType(); t.isScalarOrVectorOf(spv::Op::OpTypeFloat) && t.getFloatWidth() != _bitWidth)
	{
		t.getBaseType().setFloatWidth(_bitWidth);
		return makeOp(spv::Op::OpFConvert, getModule()->addType(t), InvalidId, _pFloatVec);
	}

	getModule()->logError("Operand of OpFConvert is not a float type with differing component width");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opQuantizeToF16(Instruction* _pFloatVec)
{
	const Type* type = _pFloatVec->getType();

	if (type == nullptr) return this;

	if (type->isScalarOrVectorOf(spv::Op::OpTypeFloat, 0u, 32u))
	{
		return makeOp(spv::Op::OpQuantizeToF16, _pFloatVec->getTypeInstr(), InvalidId, _pFloatVec);
	}

	getModule()->logError("Operand of OpQuantizeToF16 is not a float type with 32 bit component width");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opConvertPtrToU(Instruction* _pPhysPtr, unsigned int _bitWidth)
{
	const Type* type = _pPhysPtr->getType();

	if (type == nullptr) return this;

	if (type->isPointer() && type->getStorageClass() == spv::StorageClass::PhysicalStorageBuffer)
	{
		Type t(getModule()->newType());
		return makeOp(spv::Op::OpConvertPtrToU, getModule()->addType(t.UInt(_bitWidth)), InvalidId, _pPhysPtr);
	}

	getModule()->logError("Operand of OpConvertPtrToU is not a physical pointer type");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opBitcast(Instruction* _pResultType, Instruction* _pOperand)
{
	const Type* resultType = _pResultType->getType();
	const Type* operandType = _pOperand->getType();

	if (resultType == nullptr || operandType == nullptr) return this;

	if (*resultType == *operandType)
	{
		getModule()->logError("Operand and result type of OpBitcast are identical");
		return this;
	}

	if ((operandType->isPointer() && resultType->isPointer()) || 
		(operandType->getScalarOrVectorLength() * operandType->getBaseType().getIntWidth() ==
			resultType->getScalarOrVectorLength() * resultType->getBaseType().getIntWidth()))
	{
		return makeOp(spv::Op::OpBitcast, _pResultType, InvalidId, _pOperand);
	}

	getModule()->logError("Operand or result type of OpBitcast is not a pointer or numerical scalar or vector type whose total bitwidth match");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::scalarVecOp(spv::Op _op, spv::Op _type, Sign _sign, Instruction* _pLeft, Instruction* _pRight, const char* _pErrorMsg, bool _checkSign)
{
	const Type* pLeftType = _pLeft->getType();
	const Type* pRightType = _pRight != nullptr ? _pRight->getType() : nullptr;

	if (pLeftType == nullptr) return this;

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
	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::scalarVecOp(spv::Op _op, Instruction* _pLeft, Instruction* _pRight, const char* _pErrorMsg, bool _checkSign)
{
	Sign sign = Sign::Any;
	const spv::Op type = getTypeFromOp(_op, sign);

	if (type == spv::Op::OpNop)
	{
		getModule()->logError("Could not derive operand type from instruction _op");
		return this;
	}

	return scalarVecOp(_op, type, sign, _pLeft, _pRight, _pErrorMsg, _checkSign);
}

spvgentwo::Instruction* spvgentwo::Instruction::intFloatOp(Instruction* _pLeft, Instruction* _pRight, DualOpMemberFun _intFun, DualOpMemberFun _floatFun, const char* _pErrorMsg)
{
	const Type* lType = _pLeft->getType();
	const Type* rType = _pRight->getType();

	if (lType == nullptr || rType == nullptr) return this;

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

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::intFloatOp(Instruction* _pLeft, Instruction* _pRight, DualOpMemberFun _sIntFun, DualOpMemberFun _uIntFun, DualOpMemberFun _floatFun, const char* _pErrorMsg)
{
	const Type* lType = _pLeft->getType();
	const Type* rType = _pRight->getType();

	if (lType == nullptr || rType == nullptr) return this;

	if (lType->getBaseType().isUInt() && rType->getBaseType().isUInt())
	{
		return (this->*_uIntFun)(_pLeft, _pRight);
	}
	else if (lType->getBaseType().isInt() && rType->getBaseType().isInt()) // if l or r is unsinged call signed func
	{
		return (this->*_sIntFun)(_pLeft, _pRight);
	}
	else if (lType->getBaseType().isFloat() && rType->getBaseType().isFloat())
	{
		return (this->*_floatFun)(_pLeft, _pRight);
	}

	if (_pErrorMsg != nullptr)
	{
		getModule()->logError(_pErrorMsg);
	}

	return this;
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