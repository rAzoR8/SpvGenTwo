#pragma once

#include "List.h"
#include "Operand.h"
#include "Flag.h"

namespace spvgentwo
{
	// forward delcs
	class Type;
	class Constant;
	class Function;
	class Module;
	class IReader;
	class Grammar;
	class String;

	class Instruction : public List<Operand>
	{
		friend class Module;
		friend class BasicBlock;

	public:
		enum class ParentType
		{
			BasicBlock,
			Function,
			Module
		};

	private:
		spv::Op m_Operation = spv::Op::OpNop;

		ParentType m_parentType = ParentType::BasicBlock;

		union
		{
			BasicBlock* pBasicBlock; // parent
			Function* pFunction;
			Module* pModule;
		} m_parent = {};

		using DualOpMemberFun = Instruction* (Instruction::*)(Instruction*, Instruction*);

	public:
		using Iterator = EntryIterator<Operand>;

		constexpr Instruction() = default;

		template <class ...Args>
		Instruction(Module* _pModule, const spv::Op _op, Args&& ... _args);
		template <class ...Args>
		Instruction(Function* _pFunction, const spv::Op _op, Args&& ... _args);
		template <class ...Args>
		Instruction(BasicBlock* _pBasicBlock, const spv::Op _op, Args&& ... _args);

		Instruction(Instruction&& _other) noexcept;

		Instruction(Module* _pModule, Instruction&& _other) noexcept;
		Instruction(Function* _pFunction, Instruction&& _other) noexcept;
		Instruction(BasicBlock* _pBasicBlock, Instruction&& _other) noexcept;

		Instruction(const Instruction&) = delete;

		virtual ~Instruction();

		Instruction& operator=(Instruction&& _other) noexcept;
		Instruction& operator=(const Instruction& _other) = delete;

		bool operator==(const spv::Op _op) const { return m_Operation == _op; }
		bool operator!=(const spv::Op _op) const { return m_Operation != _op; }

		ParentType getParentType() const { return m_parentType; }

		// set parent if non was set before
		void setParent(Module* _pModule);
		// set parent if non was set before
		void setParent(Function* _pFunction);
		// set parent if non was set before
		void setParent(BasicBlock* _pBasicBlock);
		// set parent if non was set before, copy parent type from _instr
		void setParent(const Instruction& _other);

		Module* getModule() const;
		Function* getFunction() const;
		BasicBlock* getBasicBlock() const;

		// get name that was assigned via opName
		const char* getName(const unsigned int _memberIndex = ~0u) const;

		// not so sure this is a good idea
		operator BasicBlock& () { return *getBasicBlock(); }
		operator const BasicBlock& () const { return *getBasicBlock(); }

		// manual instruction construction:
		void setOperation(const spv::Op _op) { m_Operation = _op; };
		spv::Op getOperation() const { return m_Operation; }
		template<class ...Args>
		Operand& addOperand(Args&& ... _operand) { return emplace_back(stdrep::forward<Args>(_operand)...); }

		spv::Id getResultId() const;
		Instruction* getResultTypeInstr() const;
		const Type* getType() const;
		const Constant* getConstant() const;

		// operand iterator helpers return null iterator of not compatible with operation 
		Iterator getResultTypeOperand() const; // <id> ResultType operand
		Iterator getResultIdOperand() const; // Result <id> operand
		Iterator getFirstActualOperand() const; // operand after Result <id>

		// get StorageClass of OpVariable and OpTypePointer instructions
		spv::StorageClass getStorageClass() const;

		// assign (overwrite prev. valid Id if _overwrite is true) next free Id from module to this instruction result (if it has a result)
		// returns assigned Id
		spv::Id assignResultId(bool _overwrite);

		// assign (overwrite allways) _id to this instruction result (if it has a result)
		void assignResultId(spv::Id _id);
	
		bool isType() const;
		bool isTerminator() const;
		bool isConstant() const;
		bool isSpecConstant() const;
		bool isSpecOrConstant() const;

		bool hasResult() const { return spv::HasResult(m_Operation); }
		bool hasResultType() const { return spv::HasResultType(m_Operation); }
		bool hasResultAndType() const { return hasResultAndTypeId(m_Operation); }

		// returns a list of BasicBlock branch targets if this instuction is a Terminator
		bool getBranchTargets(List<BasicBlock*>& _outTargetBlocks) const;

		// reset Operation and clear Operands
		void reset();

		// get number of 32 bit words used by this instruction
		unsigned int getWordCount() const;

		// get opcode encoded with instruction word count [16 bit op code, 16 bit number of operand words] 
		unsigned int getOpCode() const;

		// serialize instruction operands to the IWriter, returns false if IWriter::put returned false 
		bool write(IWriter& _writer) const;

		// deserialize instruction operands from this IReader
		bool readOperands(IReader& _reader, const Grammar& _grammar, spv::Op _op, unsigned int _operandCount);

		// transforms _args to operands, calls inferResultTypeOperand and validateOperands()
		template <class ...Args>
		Instruction* makeOp(const spv::Op _op, Args&& ... _args);

		// convert and add the raw data passed via _args as literal_t operands
		template <class ...Args>
		void appendLiterals(Args&& ... _args);

		// infer result type from operands, RestulType operand must be set to InvalidInstr
		// this function assigns the infered OpType instruction to the first operand of this instruction
		// uses ITypeInferenceAndValiation instance if present
		Instruction* inferResultTypeOperand();

		// validate m_Operations and operands with ITypeInferenceAndValiation instance if present, return true if okay
		bool validateOperands() const;

		// checks if this instruction is the Modules generic invalid instruction (OpNop)
		bool isErrorInstr() const;

		//
		// GENERIC OPERATIONS
		//

		Instruction* Add(Instruction* _pLeft, Instruction* _pRight) { return intFloatOp(_pLeft, _pRight, &Instruction::opIAdd, &Instruction::opFAdd, "Failed to match Add's operand types for this instruction"); }
		Instruction* Sub(Instruction* _pLeft, Instruction* _pRight) { return intFloatOp(_pLeft, _pRight, &Instruction::opISub, &Instruction::opFSub, "Failed to match Add's operand types for this instruction"); }
		Instruction* Mul(Instruction* _pLeft, Instruction* _pRight);
		Instruction* Div(Instruction* _pLeft, Instruction* _pRight, bool _allowVecDividedByScalar = true);

		Instruction* Not(Instruction* _pIntOrBool); // lowecase not is a c++ keywork, hence generic functions need to be upper case

		Instruction* Equal(Instruction* _pLeft, Instruction* _pRight) { return intFloatBoolOp(_pLeft, _pRight, &Instruction::opIEqual, &Instruction::opFOrdEqual, &Instruction::opLogicalEqual, "Failed to match Equals's operand types for this instruction"); }
		Instruction* NotEqual(Instruction* _pLeft, Instruction* _pRight) { return intFloatBoolOp(_pLeft, _pRight, &Instruction::opINotEqual, &Instruction::opFOrdNotEqual, &Instruction::opLogicalNotEqual, "Failed to match NotEqual's operand types for this instruction"); }
		Instruction* Greater(Instruction* _pLeft, Instruction* _pRight) { return intFloatOp(_pLeft, _pRight, &Instruction::opSGreaterThan, &Instruction::opUGreaterThan, &Instruction::opFOrdGreaterThan, "Failed to match Greater's operand types for this instruction"); }
		Instruction* GreaterEqual(Instruction* _pLeft, Instruction* _pRight) { return intFloatOp(_pLeft, _pRight, &Instruction::opSGreaterThanEqual, &Instruction::opUGreaterThanEqual, &Instruction::opFOrdGreaterThanEqual, "Failed to match GreaterEqual's operand types for this instruction"); }
		Instruction* Less(Instruction* _pLeft, Instruction* _pRight) { return intFloatOp(_pLeft, _pRight, &Instruction::opSLessThan, &Instruction::opULessThan, &Instruction::opFOrdLessThan, "Failed to match Less's operand types for this instruction"); }
		Instruction* LessEqual(Instruction* _pLeft, Instruction* _pRight) { return intFloatOp(_pLeft, _pRight, &Instruction::opSLessThanEqual, &Instruction::opULessThanEqual, &Instruction::opFOrdLessThanEqual, "Failed to match LessEqual's operand types for this instruction"); }

		//
		// SPIR-V OPERATIONS
		//
		// all instructions generating a result id return a pointer to this instruction for reference (passing to other instruction operand)

		void opNop();

		Instruction* opUndef(Instruction* _pResultType);

		void opSourceContinued(const char* _pSourceText);

		void opSource(spv::SourceLanguage _lang, unsigned int _version, Instruction* _pFileString = nullptr, const char* _pSourceText = nullptr);

		void opSourceExtension(const char* _pExtensionName);

		void opName(Instruction* _pTarget, const char* _pName);

		void opMemberName(Instruction* _pTargetStructType, unsigned int _memberIndex, const char* _pName);

		Instruction* opString(const char* _str);

		void opLine(Instruction* _pFileString, unsigned int _line, unsigned int _column);

		// helper variant the turns _pFileString into opString Instruction*
		void opLine(const char* _pFileString, unsigned int _line, unsigned int _column);

		void opExtension(const char* _pExtName);

		// generates extension id
		Instruction* opExtInstImport(const char* _pExtName);

		template <class ...Operands>
		Instruction* opExtInst(Instruction* _pResultType, Instruction* _pExtensionId, unsigned int _instOpCode, Operands ... _operands);

		template <class ...Operands>
		Instruction* opExtInst(Instruction* _pResultType, const char* _pExtName, unsigned int _instOpCode, Operands ... _operands);

		void opMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel);

		//  _pFunction is result of opFunction
		template <class ... Instr>
		void opEntryPoint(const spv::ExecutionModel _model, Instruction* _pFunction, const char* _pName, Instr* ... _instr);

		// _pEntryPoint is result of opFunction (_pFunction operand of opEntryPoint)
		template <class ... ExecModeLiteral>
		void opExecutionMode(Instruction* _pEntryPoint, const spv::ExecutionMode _mode, ExecModeLiteral ... _args);

		void opCapability(const spv::Capability _capability);

		template <class ... ExecModeConstInstr>
		void opExecutionModeId(Instruction* _pEntryPoint, const spv::ExecutionMode _mode, ExecModeConstInstr* ... _args);

		// TODO: OpType### instructions
		// TODO: OpConstant### instructions
		// TODO: OpSpecConstant### instructions

		template <class ...ArgInstr>
		Instruction* opSpecConstantOp(Instruction* _pResultType, spv::Op _opcode, ArgInstr* ..._instrOperands);

		// convert this instruction to its OpSpecConstantOp variant
		Instruction* toSpecOp();

		Instruction* opFunction(const Flag<spv::FunctionControlMask> _functionControl, Instruction* _pResultType, Instruction* _pFuncType);
		
		Instruction* opFunctionParameter(Instruction* _pType);
		
		void opFunctionEnd();

		template <class ... ArgInstr>
		Instruction* opFunctionCall(Instruction* _pResultType, Instruction* _pFunction, ArgInstr* ... _args);

		Instruction* opFunctionCallDynamic(Instruction* _pResultType, Instruction* _pFunction, const List<Instruction*>& _args);

		// generic helper for opFunctionCall using Function class
		template <class ... ArgInstr>
		Instruction* call(Function* _pFunction, ArgInstr* ... _args);

		Instruction* callDynamic(Function* _pFunction, const List<Instruction*>& _args);
		
		// _pResultType must be of OpTypePointer
		Instruction* opVariable(Instruction* _pResultType, const spv::StorageClass _storageClass, Instruction* _pInitializer = nullptr);

		// Instruction* opImageTexelPointer(); TODO

		template <class ... Operands>
		Instruction* opLoad(Instruction* _pPointerToVar, const Flag<spv::MemoryAccessMask> _memOperands = spv::MemoryAccessMask::MaskNone, Operands ... _operands);

		template <class ... Operands>
		void opStore(Instruction* _pPointerToVar, Instruction* _valueToStore, const Flag<spv::MemoryAccessMask> _memOperands = spv::MemoryAccessMask::MaskNone, Operands ... _operands);

		template <class ... Operands>
		void opCopyMemory(Instruction* _pTargetPtr, Instruction* _pSourcePtr, Flag<spv::MemoryAccessMask> _targetMemOperands = spv::MemoryAccessMask::MaskNone, Flag<spv::MemoryAccessMask> _sourceMemOperands = spv::MemoryAccessMask::MaskNone, Operands ... _operands)
		{
			opCopyMemorySizedImpl(_pTargetPtr, _pSourcePtr, nullptr, _targetMemOperands, _sourceMemOperands, _operands...);
		}
		
		template <class ... Operands>
		void opCopyMemorySized(Instruction* _pTargetPtr, Instruction* _pSourcePtr, Instruction* _pSizeInBytesInt, Flag<spv::MemoryAccessMask> _targetMemOperands = spv::MemoryAccessMask::MaskNone, Flag<spv::MemoryAccessMask> _sourceMemOperands = spv::MemoryAccessMask::MaskNone, Operands ... _operands)
		{
			opCopyMemorySizedImpl(_pTargetPtr, _pSourcePtr, _pSizeInBytesInt, _targetMemOperands, _sourceMemOperands, _operands...);
		}

		// ConstInstr must be OpConstant (unsigne int) Instruction
		template <class ... ConstInstr>
		Instruction* opAccessChain(Instruction* _pResultType, Instruction* _pBase, ConstInstr* ... _pIndices);

		// IntIndices must be of type unsigned int, the first 0 index to unrwap _pBases pointer type can omitted!
		template <class ... IntIndices>
		Instruction* opAccessChain(Instruction* _pBase, IntIndices... _indices);
		
		// the first 0 index to unrwap _pBases pointer type can omitted!
		Instruction* opAccessChain(Instruction* _pBase, const List<unsigned int>& _indices);

		// ConstInstr must be OpConstant (unsigne int) Instruction
		template <class ... ConstInstr>
		Instruction* opInBoundsAccessChain(Instruction* _pResultType, Instruction* _pBase, Instruction* _pConstElementIndex, ConstInstr* ... _pIndices);

		// Instruction* OpPtrAccessChain(); TODO

		//Structure must be a logical pointer to an OpTypeStruct whose last	member is a run-time array.
		Instruction* opArrayLength(Instruction* _pStructure, unsigned int _ArrayMemberIndex);

		// Instruction* OpGenericPtrMemSemantics(); TODO
		// Instruction* OpInBoundsPtrAccessChain(); TODO

		template <class ... Decorations>
		void opDecorate(Instruction* _pTarget, spv::Decoration _decoration, Decorations ... _decorations);

		template <class ... Decorations>
		void opMemberDecorate(Instruction* _pTargetStructType, unsigned int _memberIndex, spv::Decoration _decoration, Decorations ... _decorations);

		// Instruction* OpDecorationGroup(); Deprecated
		// Instruction* OpGroupDecorate(); Deprecated
		// Instruction* OpGroupMemberDecorate(); Deprecated

		Instruction* opVectorExtractDynamic(Instruction* _pVector, Instruction* _pIndexInt);

		Instruction* opVectorInsertDynamic(Instruction* _pVector, Instruction* _pComponent, Instruction* _pIndexInt);

		// components must be unint32_ts
		template <class ... Components>
		Instruction* opVectorShuffle(Instruction* _pVector1, Instruction* _pVector2, Components ... _components);

		template <class ... ConstituentInstr>
		Instruction* opCompositeConstruct(Instruction* _pResultType, Instruction* _pFirstConstituent, ConstituentInstr* ... _constituents);

		Instruction* opCompositeConstructDynamic(Instruction* _pResultType, const List<Instruction*>& _constituents);

		template <class ... IntIndices>
		Instruction* opCompositeExtract(Instruction* _pComposite, IntIndices ... _indices);

		Instruction* opCompositeExtractDynamic(Instruction* _pComposite, const List<unsigned int>& _indices);

		template <class ... IntIndices>
		Instruction* opCompositeInsert(Instruction* _pComposite, Instruction* _pValue, IntIndices ... _indices);

		Instruction* opCopyObject(Instruction* _pObject);

		Instruction* opTranspose(Instruction* _pMatrix);

		Instruction* opSampledImage(Instruction* _pImage, Instruction* _pSampler);

#pragma region SampleMethods
		// Implicit
		template <class ...ImageOperands>
		Instruction* opImageSampleImplictLod(Instruction* _pSampledImage, Instruction* _pCoordinate, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return genericImageOp(spv::Op::OpImageSampleImplicitLod, _pSampledImage, _pCoordinate, nullptr, _imageOperands, _operands...);
		}

		// Explicit
		template <class ...ImageOperands>
		Instruction* opImageSampleExplicitLodLevel(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pLodLevel, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return genericImageOp(spv::Op::OpImageSampleExplicitLod, _pSampledImage, _pCoordinate, nullptr, _imageOperands | spv::ImageOperandsMask::Lod, _pLodLevel, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageSampleExplicitLodGrad(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pGrad, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return genericImageOp(spv::Op::OpImageSampleExplicitLod, _pSampledImage, _pCoordinate, nullptr, _imageOperands | spv::ImageOperandsMask::Grad, _pGrad, _operands...);
		}

		// Proj
		template <class ...ImageOperands>
		Instruction* opImageSampleProjImplictLod(Instruction* _pSampledImage, Instruction* _pCoordinate, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return genericImageOp(spv::Op::OpImageSampleProjImplicitLod, _pSampledImage, _pCoordinate, nullptr, _imageOperands, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageSampleProjExplicitLodLevel(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pLodLevel, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return genericImageOp(spv::Op::OpImageSampleProjExplicitLod, _pSampledImage, _pCoordinate, nullptr, _imageOperands | spv::ImageOperandsMask::Lod, _pLodLevel, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageSampleProjExplicitLodGrad(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pGrad, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return genericImageOp(spv::Op::OpImageSampleProjExplicitLod, _pSampledImage, _pCoordinate, nullptr, _imageOperands | spv::ImageOperandsMask::Grad, _pGrad, _operands...);
		}

		//
		// Dref
		//

		// Implicit
		template <class ...ImageOperands>
		Instruction* opImageSampleDrefImplictLod(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDepthReference, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return genericImageOp(spv::Op::OpImageSampleDrefImplicitLod, _pSampledImage, _pCoordinate, _pDepthReference, _imageOperands, _operands...);
		}

		// Explicit
		template <class ...ImageOperands>
		Instruction* opImageSampleDrefExplicitLodLevel(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDepthReference, Instruction* _pLodLevel, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return genericImageOp(spv::Op::OpImageSampleDrefExplicitLod, _pSampledImage, _pCoordinate, _pDepthReference, _imageOperands | spv::ImageOperandsMask::Lod, _pLodLevel, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageSampleDrefExplicitLodGrad(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDepthReference, Instruction* _pGrad, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return genericImageOp(spv::Op::OpImageSampleDrefExplicitLod, _pSampledImage, _pCoordinate, _pDepthReference, _imageOperands | spv::ImageOperandsMask::Grad, _pGrad, _operands...);
		}

		// Proj
		template <class ...ImageOperands>
		Instruction* opImageSampleProjDrefImplictLod(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDepthReference, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return genericImageOp(spv::Op::OpImageSampleProjDrefImplicitLod, _pSampledImage, _pCoordinate, _pDepthReference, _imageOperands, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageSampleProjDrefExplicitLodLevel(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDepthReference, Instruction* _pLodLevel, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return genericImageOp(spv::Op::OpImageSampleProjDrefExplicitLod, _pSampledImage, _pCoordinate, _pDepthReference, _imageOperands | spv::ImageOperandsMask::Lod, _pLodLevel, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageSampleProjDrefExplicitLodGrad(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDepthReference, Instruction* _pGrad, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return genericImageOp(spv::Op::OpImageSampleProjDrefExplicitLod, _pSampledImage, _pCoordinate, _pDepthReference, _imageOperands | spv::ImageOperandsMask::Grad, _pGrad, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageFetch(Instruction* _pImage, Instruction* _pCoordinate, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return genericImageOp(spv::Op::OpImageFetch, _pImage, _pCoordinate, nullptr, _imageOperands, _operands...);
		}

		// Gather
		template <class ...ImageOperands>
		Instruction* opImageGather(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pComponent, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return genericImageOp(spv::Op::OpImageGather, _pSampledImage, _pCoordinate, _pComponent, _imageOperands, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageDrefGather(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDepthReference, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return genericImageOp(spv::Op::OpImageDrefGather, _pSampledImage, _pCoordinate, _pDepthReference, _imageOperands, _operands...);
		}

#pragma endregion

		template <class ...ImageOperands>
		Instruction* opImageRead(Instruction* _pImage, Instruction* _pCoordinate, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return genericImageOp(spv::Op::OpImageRead, _pImage, _pCoordinate, nullptr, _imageOperands, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageWrite(Instruction* _pImage, Instruction* _pCoordinate, Instruction* _pTexel, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands);

		Instruction* opImage(Instruction* _pSampledImage);

		Instruction* opImageQueryFormat(Instruction* _pImage);

		Instruction* opImageQueryOrder(Instruction* _pImage);

		Instruction* opImageQuerySizeLod(Instruction* _pImage, Instruction* _pLoDInt);

		Instruction* opImageQuerySize(Instruction* _pImage);

		Instruction* opImageQueryLod(Instruction* _pSampledImage, Instruction* _pCoordinate);

		Instruction* opImageQueryLevels(Instruction* _pImage);

		Instruction* opImageQuerySamples(Instruction* _pImage);

		Instruction* opConvertFToU(Instruction* _pFloatVec) { return scalarVecOp(spv::Op::OpConvertFToU, _pFloatVec, nullptr, "Operand of OpConvertFToU is not a scalar or vector of float type", false); }

		Instruction* opConvertFToS(Instruction* _pFloatVec) { return scalarVecOp(spv::Op::OpConvertFToS, _pFloatVec, nullptr, "Operand of OpConvertFToS is not a scalar or vector of float type", false); }

		Instruction* opConvertSToF(Instruction* _pSIntVec) { return scalarVecOp(spv::Op::OpConvertSToF, _pSIntVec, nullptr, "Operand of OpConvertSToF is not a scalar or vector of int type"); }

		Instruction* opConvertUToF(Instruction* _pUIntVec) { return scalarVecOp(spv::Op::OpConvertUToF, _pUIntVec, nullptr, "Operand of OpConvertUToF is not a scalar or vector of int type"); }

		// convert scalar or vector to different componenet bit width
		Instruction* opUConvert(Instruction* _pUIntVec, unsigned int _bitWidth);

		Instruction* opSConvert(Instruction* _pSIntVec, unsigned int _bitWidth);

		Instruction* opFConvert(Instruction* _pFloatVec, unsigned int _bitWidth);

		Instruction* opQuantizeToF16(Instruction* _pFloatVec);

		Instruction* opConvertPtrToU(Instruction* _pPhysPtr, unsigned int _bitWidth);

		Instruction* opSatConvertSToU(Instruction* _pSignedInt) { return scalarVecOp(spv::Op::OpSatConvertSToU, _pSignedInt, nullptr, "Operand of OpSatConvertSToU is not a scalar or vector of signed integer type"); }
		
		Instruction* opSatConvertUToS(Instruction* _pSignedInt) { return scalarVecOp(spv::Op::OpSatConvertUToS, _pSignedInt, nullptr, "Operand of OpSatConvertUToS is not a scalar or vector of unsigned integer type"); }

		// Instruction* OpConvertUToPtr(); TODO
		Instruction* opConvertUToPtr(Instruction* _pResultType, Instruction* _pUInt);

		// Instruction* OpPtrCastToGeneric(); TODO
		// Instruction* OpGenericCastToPtr(); TODO
		// Instruction* OpGenericCastToPtrExplicit(); TODO

		Instruction* opBitcast(Instruction* _pResultType, Instruction* _pOperand);

		template<class T> // generic version of opBitcast, generates spv type from T
		Instruction* bitcast(Instruction* _pOperand);

		Instruction* opSNegate(Instruction* _pSignedInt) { return scalarVecOp(spv::Op::OpSNegate, _pSignedInt, nullptr, "Operand of OpSNegate is not a scalar or vector of int type"); }

		Instruction* opFNegate(Instruction* _pFloat) { return scalarVecOp(spv::Op::OpFNegate, _pFloat, nullptr, "Operand of OpFNegate is not a scalar or vector of float type"); }

		Instruction* opIAdd(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpIAdd, _pLeft, _pRight, "Operand of opIAdd is not a scalar or vector of int type"); }

		Instruction* opFAdd(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFAdd, _pLeft, _pRight, "Operand of OpFAdd is not a scalar or vector of float type"); }

		Instruction* opISub(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpISub, _pLeft, _pRight, "Operand of OpISub is not a scalar or vector of int type"); }

		Instruction* opFSub(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFSub, _pLeft, _pRight, "Operand of OpFSub is not a scalar or vector of float type"); }

		Instruction* opIMul(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpIMul, _pLeft, _pRight, "Operand of OpIMul is not a scalar or vector of int type"); }

		Instruction* opFMul(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFMul, _pLeft, _pRight, "Operand of OpFMul is not a scalar or vector of float type"); }

		Instruction* opUDiv(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpUDiv, _pLeft, _pRight, "Operand of OpUDiv is not a scalar or vector of unsigned int type"); }

		Instruction* opSDiv(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpSDiv, _pLeft, _pRight, "Operand of OpSDiv is not a scalar or vector of signed int type", false); }

		Instruction* opFDiv(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFDiv, _pLeft, _pRight, "Operand of OpFDiv is not a scalar or vector of float type"); }

		Instruction* opUMod(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpUMod, _pLeft, _pRight, "Operand of OpUMod is not a scalar or vector of unsigned int type"); }

		Instruction* opSRem(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpSRem, _pLeft, _pRight, "Operand of OpSRem is not a scalar or vector of int type", false); }

		Instruction* opSMod(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpSMod, _pLeft, _pRight, "Operand of OpSMod is not a scalar or vector of int type", false); }

		Instruction* opFRem(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFRem, _pLeft, _pRight, "Operand of OpFRem is not a scalar or vector of float type"); }

		Instruction* opFMod(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFMod, _pLeft, _pRight, "Operand of OpFMod is not a scalar or vector of float type"); }

		Instruction* opVectorTimesScalar(Instruction* _pVector, Instruction* _pScalar);

		Instruction* opMatrixTimesScalar(Instruction* _pMatrix, Instruction* _pScalar);

		Instruction* opVectorTimesMatrix(Instruction* _pVector, Instruction* _pMatrix);

		Instruction* opMatrixTimesVector(Instruction* _pMatrix, Instruction* _pVector);

		Instruction* opMatrixTimesMatrix(Instruction* _pLeft, Instruction* _pRight);

		Instruction* opOuterProduct(Instruction* _pLeft, Instruction* _pRight);

		Instruction* opDot(Instruction* _pLeft, Instruction* _pRight);

		Instruction* opIAddCarry(Instruction* _pUIntVec1, Instruction* _pUIntVec2) { return scalarVecOp(spv::Op::OpIAddCarry, _pUIntVec1, _pUIntVec2, "Operand of OpIAddCarry is not a scalar or vector of unsigned int type"); }
		
		Instruction* opISubBorrow(Instruction* _pUIntVec1, Instruction* _pUIntVec2) { return scalarVecOp(spv::Op::OpISubBorrow, _pUIntVec1, _pUIntVec2, "Operand of OpISubBorrow is not a scalar or vector of unsigned int type"); }

		Instruction* opUMulExtended(Instruction* _pUIntVec1, Instruction* _pUIntVec2) { return scalarVecOp(spv::Op::OpUMulExtended, _pUIntVec1, _pUIntVec2, "Operand of OpUMulExtended is not a scalar or vector of unsigned int type"); }

		Instruction* OpSMulExtended(Instruction* _pSIntVec1, Instruction* _pSIntVec2) { return scalarVecOp(spv::Op::OpSMulExtended, _pSIntVec1, _pSIntVec2, "Operand of OpSMulExtended is not a scalar or vector of signed int type"); }

		Instruction* opAny(Instruction* _pBoolVec);

		Instruction* opAll(Instruction* _pBoolVec);

		Instruction* opIsNan(Instruction* _pFloatVec) { return scalarVecOp(spv::Op::OpIsNan, _pFloatVec, nullptr, "Operand of OpIsNan is not a scalar or vector of float type", false); }

		Instruction* opIsInf(Instruction* _pFloatVec) { return scalarVecOp(spv::Op::OpIsInf, _pFloatVec, nullptr, "Operand of OpIsInf is not a scalar or vector of float type", false); }

		Instruction* opIsFinite(Instruction* _pFloatVec) { return scalarVecOp(spv::Op::OpIsFinite, _pFloatVec, nullptr, "Operand of OpIsFinite is not a scalar or vector of float type", false); }

		Instruction* opIsNormal(Instruction* _pFloatVec) { return scalarVecOp(spv::Op::OpIsNormal, _pFloatVec, nullptr, "Operand of OpIsNormal is not a scalar or vector of float type", false); }

		Instruction* opSignBitSet(Instruction* _pFloatVec) { return scalarVecOp(spv::Op::OpSignBitSet, _pFloatVec, nullptr, "Operand of OpSignBitSet is not a scalar or vector of float type", false); }

		// Instruction* OpLessOrGreater(); DEPRECATED
		
		Instruction* opOrdered(Instruction* _pFloatVec1, Instruction* _pFloatVec2) { return scalarVecOp(spv::Op::OpOrdered, _pFloatVec1, _pFloatVec2, "Operand of OpOrdered is not a scalar or vector of bool type"); }

		Instruction* opUnordered(Instruction* _pFloatVec1, Instruction* _pFloatVec2) { return scalarVecOp(spv::Op::OpUnordered, _pFloatVec1, _pFloatVec2, "Operand of OpUnordered is not a scalar or vector of bool type"); }

		Instruction* opLogicalEqual(Instruction* _pBoolVec1, Instruction* _pBoolVec2) { return scalarVecOp(spv::Op::OpLogicalEqual, _pBoolVec1, _pBoolVec2, "Operand of OpLogicalEqual is not a scalar or vector of bool type"); }

		Instruction* opLogicalNotEqual(Instruction* _pBoolVec1, Instruction* _pBoolVec2) { return scalarVecOp(spv::Op::OpLogicalNotEqual, _pBoolVec1, _pBoolVec2, "Operand of OpLogicalNotEqual is not a scalar or vector of bool type"); }

		Instruction* opLogicalOr(Instruction* _pBoolVec1, Instruction* _pBoolVec2) { return scalarVecOp(spv::Op::OpLogicalOr, _pBoolVec1, _pBoolVec2, "Operand of OpLogicalOr is not a scalar or vector of bool type"); }

		Instruction* opLogicalAnd(Instruction* _pBoolVec1, Instruction* _pBoolVec2) { return scalarVecOp(spv::Op::OpLogicalAnd, _pBoolVec1, _pBoolVec2, "Operand of OpLogicalAnd is not a scalar or vector of bool type"); }

		Instruction* opLogicalNot(Instruction* _pBoolVec) { return scalarVecOp(spv::Op::OpLogicalNot, _pBoolVec, nullptr, "Operand of OpLogicalNot is not a scalar or vector of bool type"); }

		Instruction* opSelect(Instruction* _pCondBool, Instruction* _pTrueObj, Instruction* _pFalseObj);
		
		Instruction* opIEqual(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpIEqual, _pLeft, _pRight, "Operand of OpIEqual is not a scalar or vector of int type"); }

		Instruction* opINotEqual(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpINotEqual, _pLeft, _pRight, "Operand of OpINotEqual is not a scalar or vector of int type"); }

		Instruction* opUGreaterThan(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpUGreaterThan, _pLeft, _pRight, "Operand of OpUGreaterThan is not a scalar or vector of int type", false); }

		Instruction* opUGreaterThanEqual(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpUGreaterThanEqual, _pLeft, _pRight, "Operand of OpUGreaterThanEqual is not a scalar or vector of int type", false); }

		Instruction* opSGreaterThan(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpSGreaterThan, _pLeft, _pRight, "Operand of OpSGreaterThan is not a scalar or vector of int type", false); }

		Instruction* opSGreaterThanEqual(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpSGreaterThanEqual, _pLeft, _pRight, "Operand of OpSGreaterThanEqual is not a scalar or vector of int type", false); }

		Instruction* opULessThan(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpULessThan, _pLeft, _pRight, "Operand of OpULessThan is not a scalar or vector of int type", false); }

		Instruction* opULessThanEqual(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpULessThanEqual, _pLeft, _pRight, "Operand of OpULessThanEqual is not a scalar or vector of int type", false); }

		Instruction* opSLessThan(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpSLessThan, _pLeft, _pRight, "Operand of OpSLessThan is not a scalar or vector of int type", false); }

		Instruction* opSLessThanEqual(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpSLessThanEqual, _pLeft, _pRight, "Operand of OpSLessThanEqual is not a scalar or vector of int type", false); }

		Instruction* opFOrdEqual(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFOrdEqual, _pLeft, _pRight, "Operand of OpFOrdEqual is not a scalar or vector of float type"); }

		Instruction* opFUnordEqual(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFUnordEqual, _pLeft, _pRight, "Operand of OpFUnordEqual is not a scalar or vector of float type"); }

		Instruction* opFOrdNotEqual(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFOrdNotEqual, _pLeft, _pRight, "Operand of OpFOrdNotEqual is not a scalar or vector of float type"); }

		Instruction* opFUnordNotEqual(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFUnordNotEqual, _pLeft, _pRight, "Operand of OpFUnordNotEqual is not a scalar or vector of float type"); }

		Instruction* opFOrdLessThan(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFOrdLessThan, _pLeft, _pRight, "Operand of OpFOrdLessThan is not a scalar or vector of float type"); }

		Instruction* opFUnordLessThan(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFUnordLessThan, _pLeft, _pRight, "Operand of OpFUnordLessThan is not a scalar or vector of float type"); }

		Instruction* opFOrdGreaterThan(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFOrdGreaterThan, _pLeft, _pRight, "Operand of OpFOrdGreaterThan is not a scalar or vector of float type"); }

		Instruction* opFUnordGreaterThan(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFUnordGreaterThan, _pLeft, _pRight, "Operand of OpFUnordGreaterThan is not a scalar or vector of float type"); }

		Instruction* opFOrdLessThanEqual(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFOrdLessThanEqual, _pLeft, _pRight, "Operand of OpFOrdLessThanEqual is not a scalar or vector of float type"); }

		Instruction* opFUnordLessThanEqual(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFUnordLessThanEqual, _pLeft, _pRight, "Operand of OpFUnordLessThanEqual is not a scalar or vector of float type"); }

		Instruction* opFOrdGreaterThanEqual(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFOrdGreaterThanEqual, _pLeft, _pRight, "Operand of OpFOrdGreaterThanEqual is not a scalar or vector of float type"); }

		Instruction* opFUnordGreaterThanEqual(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpFUnordGreaterThanEqual, _pLeft, _pRight, "Operand of OpFUnordGreaterThanEqual is not a scalar or vector of float type"); }
		
		Instruction* opShiftRightLogical(Instruction* _pBaseIntVec, Instruction* _pShiftIntVec) { return scalarVecOp(spv::Op::OpShiftRightLogical, _pBaseIntVec, _pShiftIntVec, "Operand of OpShiftRightLogical is not a scalar or vector of int", false); }
		
		Instruction* opShiftRightArithmetic(Instruction* _pBaseIntVec, Instruction* _pShiftIntVec) { return scalarVecOp(spv::Op::OpShiftRightArithmetic, _pBaseIntVec, _pShiftIntVec, "Operand of OpShiftRightArithmetic is not a scalar or vector of int", false); }
		
		Instruction* opShiftLeftLogical(Instruction* _pBaseIntVec, Instruction* _pShiftIntVec) { return scalarVecOp(spv::Op::OpShiftLeftLogical, _pBaseIntVec, _pShiftIntVec, "Operand of OpShiftLeftLogical is not a scalar or vector of int", false); }

		Instruction* opBitwiseOr(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpBitwiseOr, _pLeft, _pRight, "Operand of OpBitwiseOr is not a scalar or vector of int", false); }

		Instruction* opBitwiseXor(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpBitwiseXor, _pLeft, _pRight, "Operand of OpBitwiseXor is not a scalar or vector of int", false); }

		Instruction* opBitwiseAnd(Instruction* _pLeft, Instruction* _pRight) { return scalarVecOp(spv::Op::OpBitwiseAnd, _pLeft, _pRight, "Operand of OpBitwiseAnd is not a scalar or vector of int", false); }

		Instruction* opNot(Instruction* _pIntVec) { return scalarVecOp(spv::Op::OpNot, _pIntVec, nullptr, "Operand of OpNot is not a scalar or vector of int type"); }

		Instruction* opBitFieldInsert(Instruction* _pBase, Instruction* _pInsert, Instruction* _pOffset, Instruction* _pCount);
		Instruction* opBitFieldSExtract(Instruction* _pBase, Instruction* _pOffset, Instruction* _pCount);
		Instruction* opBitFieldUExtract(Instruction* _pBase, Instruction* _pOffset, Instruction* _pCount);
		Instruction* opBitReverse(Instruction* _pBase) { return scalarVecOp(spv::Op::OpBitReverse, _pBase, nullptr, "Operand of OpBitReverse is not a scalar or vector of int type"); }
		Instruction* opBitCount(Instruction* _pBase) { return scalarVecOp(spv::Op::OpBitCount, _pBase, nullptr, "Operand of OpBitCount is not a scalar or vector of int type"); }

		Instruction* opDPdx(Instruction* _pFloatVec) { return scalarVecOp(spv::Op::OpDPdx, _pFloatVec, nullptr, "Operand of OpDPdx is not a scalar or vector of float type"); }
		Instruction* opDPdy(Instruction* _pFloatVec) { return scalarVecOp(spv::Op::OpDPdy, _pFloatVec, nullptr, "Operand of OpDPdy is not a scalar or vector of float type"); }
		Instruction* opFwidth(Instruction* _pFloatVec) { return scalarVecOp(spv::Op::OpFwidth, _pFloatVec, nullptr, "Operand of OpFwidth is not a scalar or vector of float type"); }

		Instruction* opDPdxFine(Instruction* _pFloatVec) { return scalarVecOp(spv::Op::OpDPdxFine, _pFloatVec, nullptr, "Operand of OpDPdxFine is not a scalar or vector of float type"); }
		Instruction* opDPdyFine(Instruction* _pFloatVec) { return scalarVecOp(spv::Op::OpDPdyFine, _pFloatVec, nullptr, "Operand of OpDPdyFine is not a scalar or vector of float type"); }
		Instruction* opFwidthFine(Instruction* _pFloatVec) { return scalarVecOp(spv::Op::OpFwidthFine, _pFloatVec, nullptr, "Operand of OpFwidthFine is not a scalar or vector of float type"); }

		Instruction* opDPdxCoarse(Instruction* _pFloatVec) { return scalarVecOp(spv::Op::OpDPdxCoarse, _pFloatVec, nullptr, "Operand of OpDPdxCoarse is not a scalar or vector of float type"); }
		Instruction* opDPdyCoarse(Instruction* _pFloatVec) { return scalarVecOp(spv::Op::OpDPdyCoarse, _pFloatVec, nullptr, "Operand of OpDPdyCoarse is not a scalar or vector of float type"); }
		Instruction* opFwidthCoarse(Instruction* _pFloatVec) { return scalarVecOp(spv::Op::OpFwidthCoarse, _pFloatVec, nullptr, "Operand of OpFwidthCoarse is not a scalar or vector of float type"); }

		Instruction* opEmitVertex();
		Instruction* opEndPrimitive();
		Instruction* opEmitStreamVertex(Instruction* _pConstIntId);
		Instruction* opEndStreamPrimitive(Instruction* _pConstIntId);

		// Instruction* OpControlBarrier(); TODO
		// Instruction* OpMemoryBarrier(); TODO

		// Instruction* OpAtomicLoad(); TODO
		// Instruction* OpAtomicStore(); TODO
		// Instruction* OpAtomicExchange(); TODO
		// Instruction* OpAtomicCompareExchange(); TODO
		// Instruction* OpAtomicCompareExchangeWeak(); TODO
		// Instruction* OpAtomicIIncrement(); TODO
		// Instruction* OpAtomicIDecrement(); TODO
		// Instruction* OpAtomicIAdd(); TODO
		// Instruction* OpAtomicISub(); TODO
		// Instruction* OpAtomicSMin(); TODO
		// Instruction* OpAtomicUMin(); TODO
		// Instruction* OpAtomicSMax(); TODO
		// Instruction* OpAtomicUMax(); TODO
		// Instruction* OpAtomicAnd(); TODO
		// Instruction* OpAtomicOr(); TODO
		// Instruction* OpAtomicXor(); TODO

		// deduce parent form input variables
		template <class ... VarInst>
		Instruction* opPhi(Instruction* _pVar, VarInst* ... _variables);

		// Non-Standard helper
		Instruction* opPhiDynamic(const List<Instruction*>& _variables);

		template <class ...LoopControlParams>
		void opLoopMerge(BasicBlock* _pMergeBlock, BasicBlock* _pContinueBlock, const Flag<spv::LoopControlMask> _loopControl, LoopControlParams ... _params);

		void opSelectionMerge(BasicBlock* _pMergeBlock, const spv::SelectionControlMask _control);

		Instruction* opLabel();

		// label is infered from the basic block on serialization
		void opBranch(BasicBlock* _pTargetBlock);

		// label is infered from the basic block on serialization
		void opBranchConditional(Instruction* _pCondition, BasicBlock* _pTrueBlock, BasicBlock* _pFalseBlock);
		void opBranchConditional(Instruction* _pCondition, BasicBlock* _pTrueBlock, BasicBlock* _pFalseBlock, const unsigned int _trueWeight, const unsigned int _falseWeight);

		// Instruction* OpSwitch(); TODO

		Instruction* opKill();

		void opReturn();

		void opReturnValue(Instruction* _pValue);

		// Instruction* OpUnreachable() till opNoLine; TODO
		void opUnreachable();

		void opNoLine();

		// Instruction* OpAtomicFlagTestAndSet(); TODO
		// Instruction* OpAtomicFlagClear(); TODO
		// Instruction* OpImageSparseRead(); TODO

		Instruction* opSizeOf(Instruction* _pPointerToVar);

		// Instruction* OpTypePipeStorage(); TODO
		// Instruction* OpConstantPipeStorage(); TODO CONSTANT <<<<<<<
		// Instruction* OpCreatePipeFromPipeStorage(); TODO
		// Instruction* OpGetKernelLocalSizeForSubgroupCount(); TODO
		// Instruction* OpGetKernelMaxNumSubgroups(); TODO
		// Instruction* OpTypeNamedBarrier(); TODO TYPE <<<<<<<
		// Instruction* OpNamedBarrierInitialize(); TODO
		// Instruction* OpModuleProcessed(); TODO
		// Instruction* OpExecutionModeId(); TODO

		template <class ... Instr>
		void opDecorateId(Instruction* _pTarget, spv::Decoration _decoration, Instruction* _pId, Instr*..._ids);

		// TODO: All the rest to at least maybe OpDecorateString without the INTEL extension instructions?

		// START FROM: 401 OpPtrEqual
		Instruction* opPtrEqual(Instruction* _pLeftPtr, Instruction* _pRightPtr);

		Instruction* opPtrNotEqual(Instruction* _pLeftPtr, Instruction* _pRightPtr);
	protected:
		// return error instr
		[[nodiscard]] Instruction* error() const;

		template <class ... Operands>
		void opCopyMemorySizedImpl(Instruction* _pTargetPtr, Instruction* _pSourcePtr, Instruction* _pSizeInt, Flag<spv::MemoryAccessMask> _targetMemOperands = spv::MemoryAccessMask::MaskNone, Flag<spv::MemoryAccessMask> _sourceMemOperands = spv::MemoryAccessMask::MaskNone, Operands ... _operands);

		enum class CheckImgCoord
		{
			IsProjective = 1 << 0,
			CanBeInt = 1 << 1,
			MustBeInt = 1 << 2
		};

		// Checks dimension & element type of coordiantes to access a image of type _pImageType
		// _pImageType must be OpTypeImage
		bool checkImageCoordinateType(const Type* _pImageType, const Type* _pCoordType, Flag<CheckImgCoord> _args) const;

		// creates literals
		template <class T, class ...Args>
		void makeOpInternal(T&& first, Args&& ... _args);

		// generic base case with image operands
		template <class ...ImageOperands>
		Instruction* genericImageOp(const spv::Op _imageOp, Instruction* _pTargetImage, Instruction* _pCoordinate, Instruction* _pDrefOrCompnent, const Flag<spv::ImageOperandsMask> _imageOperands, ImageOperands... _operands);

		// checks types based on passed _type and_sign
		Instruction* scalarVecOp(spv::Op _op, spv::Op _type, Sign _sign, Instruction* _pLeft, Instruction* _pRight, const char* _pErrorMsg, bool _checkSign);

		// checks types based on passed _op using getTypeFromOp(_op, sign)
		Instruction* scalarVecOp(spv::Op _op, Instruction* _pLeft, Instruction* _pRight = nullptr, const char* _pErrorMsg = nullptr, bool _checkSign = true);

		// decides based on type of _pLeft and _pRight if _intFun or _floatFun should be called
		Instruction* intFloatOp(Instruction* _pLeft, Instruction* _pRight, DualOpMemberFun _intFun, DualOpMemberFun _floatFun, const char* _pErrorMsg = nullptr);

		// decides based on type of _pLeft and _pRight if _intFun or _floatFun or _boolFun should be called
		Instruction* intFloatBoolOp(Instruction* _pLeft, Instruction* _pRight, DualOpMemberFun _intFun, DualOpMemberFun _floatFun, DualOpMemberFun _boolFun, const char* _pErrorMsg = nullptr);
		
		// decides based on type of _pLeft and _pRight if signed _sIntFun, unsigned _uIntFund or float _floatFun should be called
		// unsigned & unsinged => unsigned, signed & unsigned => signed, float & float => float
		Instruction* intFloatOp(Instruction* _pLeft, Instruction* _pRight, DualOpMemberFun _sIntFun, DualOpMemberFun _uIntFun, DualOpMemberFun _floatFun, const char* _pErrorMsg = nullptr);

		// decides based on type of _pLeft and _pRight if signed _sIntFun, unsigned _uIntFund or float _floatFun or _boolFun should be called
		// unsigned & unsinged => unsigned, signed & unsigned => signed, float & float => float
		Instruction* intFloatBoolOp(Instruction* _pLeft, Instruction* _pRight, DualOpMemberFun _sIntFun, DualOpMemberFun _uIntFun, DualOpMemberFun _floatFun, DualOpMemberFun _boolFun, const char* _pErrorMsg = nullptr);
	};

	// accumulates literal values to _out, returns iterator to the first operand after the literal containing the string terminator
	// or null-iterator if some operand was not a literal value
	Instruction::Iterator getLiteralString(String& _out, Instruction::Iterator _begin, Instruction::Iterator _end);

	// advance _begin iterator to the first operand after the last word of the literal string containing the string terminator
	Instruction::Iterator skipLiteralString(Instruction::Iterator _begin);

	// compares _pStr element-by-elemnt with byte elements of literals in the literal string range [_begin, _end[ or until length of _pStr (_StrLength) until string terminator is encountered
	// note that SPIR-V strings are UTF-8 encoded
	bool compareLiteralString(const char* _pStr, Instruction::Iterator _begin, Instruction::Iterator _end, sgt_size_t _StrLength = sgt_size_max);
} // !spvgentwo