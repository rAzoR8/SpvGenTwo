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
			else if (o.isInstruction())
			{
				Instruction* instr = o.getInstruction();

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
			op.instruction->resolveId(_previousId);
			break;
		case Operand::Type::BranchTarget:
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

spv::Id spvgentwo::Instruction::write(IWriter* _pWriter, spv::Id& _resultId)
{
	const spv::Id ID = resolveId(_resultId);

	_pWriter->put(getOpCode());
	
	for (const Operand& operand : *this)
	{
		operand.write(_pWriter);
	}
	
	return ID;
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
	if (_pPointerToVar->getType()->isPointer())
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
	if (func != nullptr && func->getReturnType()->getType() == _pValue->getType())
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
	Instruction* _pLeftTypeInstr = _pLeft->getTypeInstr();
	Instruction* _pRightTypeInstr = _pRight->getTypeInstr();

	const Type* pLeftType = _pLeftTypeInstr->getType();
	const Type* pRightType = _pRightTypeInstr->getType();

	if (pLeftType->isVectorOfFloat() && pRightType->isVectorOfFloat() && pLeftType->hasSameBase(*pRightType))
	{
		return makeOp(spv::Op::OpOuterProduct, InvalidInstr, InvalidId, _pLeft, _pRight);
	}

	getModule()->logError("Operands of opOuterProduct are not scalar vector of length 3");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opDot(Instruction* _pLeft, Instruction* _pRight)
{
	Instruction* _pLeftTypeInstr = _pLeft->getTypeInstr();
	Instruction* _pRightTypeInstr = _pRight->getTypeInstr();

	const Type* pType = _pLeftTypeInstr->getType();
	if (_pLeftTypeInstr == _pRightTypeInstr && pType->isVectorOfFloat())
	{
		return makeOp(spv::Op::OpDot, InvalidInstr, InvalidId, _pLeft, _pRight);
	}

	getModule()->logError("Operands of opDot are not scalar vector of length 3");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opAny(Instruction* _pBoolVec)
{
	if (_pBoolVec->getType()->isVectorOfBool())
	{
		return makeOp(spv::Op::OpAny, InvalidInstr, InvalidId, _pBoolVec);
	}

	getModule()->logError("Operands of opAny is not a vector of bool");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opAll(Instruction* _pBoolVec)
{
	if (_pBoolVec->getType()->isVectorOfBool())
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
	if (_pMatrix->getType()->isMatrix())
	{
		return makeOp(spv::Op::OpTranspose, InvalidInstr, InvalidId, _pMatrix);	
	}

	getModule()->logError("Operand of opTranspose is not a matrix type");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opSNegate(Instruction* _pSignedInt)
{
	if (_pSignedInt->getType()->isInt() || _pSignedInt->getType()->isVectorOfInt())
	{
		return makeOp(spv::Op::OpSNegate, InvalidInstr, InvalidId, _pSignedInt);
	}

	getModule()->logError("Operand of opSNegate is not a scalar or vector of integer type");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opFNegate(Instruction* _pFloat)
{
	if (_pFloat->getType()->isFloat() || _pFloat->getType()->isVectorOfSInt())
	{
		return makeOp(spv::Op::OpFNegate, InvalidInstr, InvalidId, _pFloat);
	}

	getModule()->logError("Operand of OpFNegate is not a scalar or vector of float type");

	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opVectorExtractDynamic(Instruction* _pVector, Instruction* _pIndexInt)
{
	if (_pVector->getType()->isVector() && _pIndexInt->getType()->isInt())
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

	if (pVecType->isVector() && pVecType->front() == *_pComponent->getType() && _pIndexInt->getType()->isInt())
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

spvgentwo::Instruction* spvgentwo::Instruction::opSampledImage(Instruction* _pImage, Instruction* _pSampler)
{
	const Type* imageType = _pImage->getType();
	const Type* samplerType = _pSampler->getType();

	if (imageType->isImage() && samplerType->isSampler() && imageType->getImageSamplerAccess() != SamplerImageAccess::Storage && imageType->getImageDimension() != spv::Dim::SubpassData)
	{
		return makeOp(spv::Op::OpSampledImage, InvalidInstr, InvalidId, _pImage, _pSampler);
	}

	getModule()->logError("Image or sampler type does not match (storage / subpass image not allowed");
	
	return this;
}

spvgentwo::Instruction* spvgentwo::Instruction::opScalarVec(const spv::Op _op, Instruction* _pLeft, Instruction* _pRight, const char* _pErrorMsg)
{
	const spv::Op type = getTypeFromOp(_op);
	if (_pRight == nullptr && _pLeft->getType()->isScalarOrVectorOf(type))
	{
		return makeOp(_op, InvalidInstr, InvalidId, _pLeft);
	}
	else if (_pLeft->getType()->isScalarOrVectorOfSameLength(type, *_pRight->getType()))
	{
		return makeOp(_op, InvalidInstr, InvalidId, _pLeft, _pRight);
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
