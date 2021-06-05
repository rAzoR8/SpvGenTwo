// Auto generated - do not modify
#include "spvgentwo/Grammar.h"
#include "spvgentwo/Glsl.h"
#include "spvgentwo/OpenCl.h"
using namespace spvgentwo;

Grammar::Grammar(IAllocator* _pAllocator) : m_instructions(_pAllocator, 817u), m_operandNames(_pAllocator, 791u), m_operandParameters(_pAllocator, 104u), m_operandBases(_pAllocator, 3u)
{
	{
		auto& bases = m_operandBases.emplaceUnique(OperandKind::PairLiteralIntegerIdRef, _pAllocator).kv.value;
		bases.reserve(2u);
		bases.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
		bases.emplace_back(OperandKind::IdRef, OperandCategory::Id, "", Quantifier::One);
	}
	{
		auto& bases = m_operandBases.emplaceUnique(OperandKind::PairIdRefLiteralInteger, _pAllocator).kv.value;
		bases.reserve(2u);
		bases.emplace_back(OperandKind::IdRef, OperandCategory::Id, "", Quantifier::One);
		bases.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
	}
	{
		auto& bases = m_operandBases.emplaceUnique(OperandKind::PairIdRefIdRef, _pAllocator).kv.value;
		bases.reserve(2u);
		bases.emplace_back(OperandKind::IdRef, OperandCategory::Id, "", Quantifier::One);
		bases.emplace_back(OperandKind::IdRef, OperandCategory::Id, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(0u, 0x0001), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(0u, 0x0002), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(0u, 0x0004), _pAllocator).kv.value;
		parameters.reserve(2u);
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "", Quantifier::One);
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(0u, 0x0008), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(0u, 0x0010), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(0u, 0x0020), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(0u, 0x0040), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(0u, 0x0080), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(0u, 0x0100), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdScope, OperandCategory::Id, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(0u, 0x0200), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdScope, OperandCategory::Id, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(3u, 0x0008), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(3u, 0x0010), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(3u, 0x0020), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(3u, 0x0040), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(3u, 0x0080), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(3u, 0x0100), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(3u, 0x10000), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(3u, 0x20000), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(3u, 0x40000), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(3u, 0x80000), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(3u, 0x100000), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(3u, 0x200000), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(3u, 0x400000), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(3u, 0x800000), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(6u, 0x0002), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(6u, 0x0008), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdScope, OperandCategory::Id, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(6u, 0x0010), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdScope, OperandCategory::Id, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 0u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Number of <<Invocation,invocations>>'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 17u), _pAllocator).kv.value;
		parameters.reserve(3u);
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'x size'", Quantifier::One);
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'y size'", Quantifier::One);
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'z size'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 18u), _pAllocator).kv.value;
		parameters.reserve(3u);
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'x size'", Quantifier::One);
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'y size'", Quantifier::One);
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'z size'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 26u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Vertex count'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 30u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Vector type'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 35u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Subgroup Size'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 36u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Subgroups Per Workgroup'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 37u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Subgroups Per Workgroup'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 38u), _pAllocator).kv.value;
		parameters.reserve(3u);
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x size'", Quantifier::One);
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y size'", Quantifier::One);
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'z size'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 39u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Local Size Hint'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 4459u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Target Width'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 4460u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Target Width'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 4461u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Target Width'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 4462u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Target Width'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 4463u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Target Width'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 5270u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Primitive count'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 5618u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Size'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 5620u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Target Width'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 5621u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Target Width'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 5622u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Target Width'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 5623u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Target Width'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 5893u), _pAllocator).kv.value;
		parameters.reserve(3u);
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'max_x_size'", Quantifier::One);
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'max_y_size'", Quantifier::One);
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'max_z_size'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 5894u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'max_dimensions'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 5896u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'vector_width'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(14u, 5903u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'target_fmax'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 1u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Specialization Constant ID'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 6u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Array Stride'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 7u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Matrix Stride'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 11u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::BuiltIn, OperandCategory::ValueEnum, "", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 27u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 29u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Stream Number'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 30u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Location'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 31u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Component'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 32u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Index'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 33u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Binding Point'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 34u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Descriptor Set'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 35u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Byte Offset'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 36u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'XFB Buffer Number'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 37u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'XFB Stride'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 38u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::FunctionParameterAttribute, OperandCategory::ValueEnum, "'Function Parameter Attribute'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 39u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::FPRoundingMode, OperandCategory::ValueEnum, "'Floating-Point Rounding Mode'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 40u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::FPFastMathMode, OperandCategory::BitEnum, "'Fast-Math Mode'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 41u), _pAllocator).kv.value;
		parameters.reserve(2u);
		parameters.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Name'", Quantifier::One);
		parameters.emplace_back(OperandKind::LinkageType, OperandCategory::ValueEnum, "'Linkage Type'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 43u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Attachment Index'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 44u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Alignment'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 45u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Max Byte Offset'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 46u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Alignment'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 47u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Max Byte Offset'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5256u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Offset'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5599u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'N'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5607u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Register'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5625u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Kind'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5628u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Offset'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5634u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Counter Buffer'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5635u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Semantic'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5636u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'User Type'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5822u), _pAllocator).kv.value;
		parameters.reserve(2u);
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Target Width'", Quantifier::One);
		parameters.emplace_back(OperandKind::FPRoundingMode, OperandCategory::ValueEnum, "'FP Rounding Mode'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5823u), _pAllocator).kv.value;
		parameters.reserve(2u);
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Target Width'", Quantifier::One);
		parameters.emplace_back(OperandKind::FPDenormMode, OperandCategory::ValueEnum, "'FP Denorm Mode'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5826u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Memory Type'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5827u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Banks'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5828u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Bank Width'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5829u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Maximum Copies'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5832u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Maximum Replicates'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5834u), _pAllocator).kv.value;
		parameters.reserve(2u);
		parameters.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Merge Key'", Quantifier::One);
		parameters.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Merge Type'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5835u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Bank Bits'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5836u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Force Key'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5900u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Cache Size in bytes'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5902u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Prefetcher Size in bytes'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5921u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Buffer Location ID'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 5944u), _pAllocator).kv.value;
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'IO Pipe ID'", Quantifier::One);
	}
	{
		auto& parameters = m_operandParameters.emplaceUnique(Hash64(28u, 6080u), _pAllocator).kv.value;
		parameters.reserve(2u);
		parameters.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Target Width'", Quantifier::One);
		parameters.emplace_back(OperandKind::FPOperationMode, OperandCategory::ValueEnum, "'FP Operation Mode'", Quantifier::One);
	}
	m_instructions.emplaceUnique(Hash64(0u, 0u), Instruction{"OpNop", _pAllocator, _pAllocator, _pAllocator, 0u});
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(1u, 0u), Instruction{"OpUndef", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(2u, 0u), Instruction{"OpSourceContinued", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Continued Source'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(3u, 0u), Instruction{"OpSource", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::SourceLanguage, OperandCategory::ValueEnum, "", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Version'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'File'", Quantifier::ZeroOrOne);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Source'", Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4u, 0u), Instruction{"OpSourceExtension", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Extension'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5u, 0u), Instruction{"OpName", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Name'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6u, 0u), Instruction{"OpMemberName", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Member'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Name'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(7u, 0u), Instruction{"OpString", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'String'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(8u, 0u), Instruction{"OpLine", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'File'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Line'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Column'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(10u, 0u), Instruction{"OpExtension", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Name'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(11u, 0u), Instruction{"OpExtInstImport", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Name'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(12u, 0u), Instruction{"OpExtInst", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Set'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralExtInstInteger, OperandCategory::Literal, "'Instruction'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1', +'Operand 2', +...", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(14u, 0u), Instruction{"OpMemoryModel", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::AddressingModel, OperandCategory::ValueEnum, "", Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryModel, OperandCategory::ValueEnum, "", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(15u, 0u), Instruction{"OpEntryPoint", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::ExecutionModel, OperandCategory::ValueEnum, "", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Entry Point'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Name'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Interface'", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(16u, 0u), Instruction{"OpExecutionMode", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Entry Point'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ExecutionMode, OperandCategory::ValueEnum, "'Mode'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(17u, 0u), Instruction{"OpCapability", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::Capability, OperandCategory::ValueEnum, "'Capability'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(19u, 0u), Instruction{"OpTypeVoid", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(20u, 0u), Instruction{"OpTypeBool", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(21u, 0u), Instruction{"OpTypeInt", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Width'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Signedness'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(22u, 0u), Instruction{"OpTypeFloat", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Width'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(23u, 0u), Instruction{"OpTypeVector", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Component Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Component Count'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(24u, 0u), Instruction{"OpTypeMatrix", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Column Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Column Count'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(25u, 0u), Instruction{"OpTypeImage", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(9u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::Dim, OperandCategory::ValueEnum, "", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Depth'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Arrayed'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'MS'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Sampled'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageFormat, OperandCategory::ValueEnum, "", Quantifier::One);
		instr.operands.emplace_back(OperandKind::AccessQualifier, OperandCategory::ValueEnum, "", Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(26u, 0u), Instruction{"OpTypeSampler", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(27u, 0u), Instruction{"OpTypeSampledImage", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image Type'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(28u, 0u), Instruction{"OpTypeArray", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Element Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Length'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(29u, 0u), Instruction{"OpTypeRuntimeArray", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Element Type'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(30u, 0u), Instruction{"OpTypeStruct", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Member 0 type', +'member 1 type', +...", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(31u, 0u), Instruction{"OpTypeOpaque", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "The name of the opaque type.", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(32u, 0u), Instruction{"OpTypePointer", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::StorageClass, OperandCategory::ValueEnum, "", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Type'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(33u, 0u), Instruction{"OpTypeFunction", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Return Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Parameter 0 Type', +'Parameter 1 Type', +...", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(34u, 0u), Instruction{"OpTypeEvent", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(35u, 0u), Instruction{"OpTypeDeviceEvent", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(36u, 0u), Instruction{"OpTypeReserveId", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(37u, 0u), Instruction{"OpTypeQueue", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(38u, 0u), Instruction{"OpTypePipe", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::AccessQualifier, OperandCategory::ValueEnum, "'Qualifier'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(39u, 0u), Instruction{"OpTypeForwardPointer", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::StorageClass, OperandCategory::ValueEnum, "", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
		instr.capabilities.emplace_back(spv::Capability::PhysicalStorageBufferAddresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(41u, 0u), Instruction{"OpConstantTrue", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(42u, 0u), Instruction{"OpConstantFalse", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(43u, 0u), Instruction{"OpConstant", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralContextDependentNumber, OperandCategory::Literal, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(44u, 0u), Instruction{"OpConstantComposite", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Constituents'", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(45u, 0u), Instruction{"OpConstantSampler", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::SamplerAddressingMode, OperandCategory::ValueEnum, "", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Param'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::SamplerFilterMode, OperandCategory::ValueEnum, "", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::LiteralSampler);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(46u, 0u), Instruction{"OpConstantNull", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(48u, 0u), Instruction{"OpSpecConstantTrue", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(49u, 0u), Instruction{"OpSpecConstantFalse", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(50u, 0u), Instruction{"OpSpecConstant", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralContextDependentNumber, OperandCategory::Literal, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(51u, 0u), Instruction{"OpSpecConstantComposite", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Constituents'", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(52u, 0u), Instruction{"OpSpecConstantOp", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralSpecConstantOpInteger, OperandCategory::Literal, "'Opcode'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(54u, 0u), Instruction{"OpFunction", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::FunctionControl, OperandCategory::BitEnum, "", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Function Type'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(55u, 0u), Instruction{"OpFunctionParameter", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
	}
	m_instructions.emplaceUnique(Hash64(56u, 0u), Instruction{"OpFunctionEnd", _pAllocator, _pAllocator, _pAllocator, 0u});
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(57u, 0u), Instruction{"OpFunctionCall", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Function'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Argument 0', +'Argument 1', +...", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(59u, 0u), Instruction{"OpVariable", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::StorageClass, OperandCategory::ValueEnum, "", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Initializer'", Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(60u, 0u), Instruction{"OpImageTexelPointer", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sample'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(61u, 0u), Instruction{"OpLoad", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(62u, 0u), Instruction{"OpStore", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Object'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(63u, 0u), Instruction{"OpCopyMemory", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Source'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(64u, 0u), Instruction{"OpCopyMemorySized", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Source'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(65u, 0u), Instruction{"OpAccessChain", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Indexes'", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(66u, 0u), Instruction{"OpInBoundsAccessChain", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Indexes'", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(67u, 0u), Instruction{"OpPtrAccessChain", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Element'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Indexes'", Quantifier::ZeroOrAny);
		instr.capabilities.reserve(4u);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
		instr.capabilities.emplace_back(spv::Capability::VariablePointers);
		instr.capabilities.emplace_back(spv::Capability::VariablePointersStorageBuffer);
		instr.capabilities.emplace_back(spv::Capability::PhysicalStorageBufferAddresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(68u, 0u), Instruction{"OpArrayLength", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Structure'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Array member'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(69u, 0u), Instruction{"OpGenericPtrMemSemantics", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(70u, 0u), Instruction{"OpInBoundsPtrAccessChain", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Element'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Indexes'", Quantifier::ZeroOrAny);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(71u, 0u), Instruction{"OpDecorate", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::Decoration, OperandCategory::ValueEnum, "", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(72u, 0u), Instruction{"OpMemberDecorate", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Structure Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Member'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::Decoration, OperandCategory::ValueEnum, "", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(73u, 0u), Instruction{"OpDecorationGroup", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(74u, 0u), Instruction{"OpGroupDecorate", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Decoration Group'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Targets'", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(75u, 0u), Instruction{"OpGroupMemberDecorate", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Decoration Group'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::PairIdRefLiteralInteger, OperandCategory::Composite, "'Targets'", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(77u, 0u), Instruction{"OpVectorExtractDynamic", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(78u, 0u), Instruction{"OpVectorInsertDynamic", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Component'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(79u, 0u), Instruction{"OpVectorShuffle", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 2'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Components'", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(80u, 0u), Instruction{"OpCompositeConstruct", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Constituents'", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(81u, 0u), Instruction{"OpCompositeExtract", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Composite'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Indexes'", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(82u, 0u), Instruction{"OpCompositeInsert", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Object'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Composite'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Indexes'", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(83u, 0u), Instruction{"OpCopyObject", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(84u, 0u), Instruction{"OpTranspose", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Matrix'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(86u, 0u), Instruction{"OpSampledImage", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampler'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(87u, 0u), Instruction{"OpImageSampleImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(88u, 0u), Instruction{"OpImageSampleExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(89u, 0u), Instruction{"OpImageSampleDrefImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(90u, 0u), Instruction{"OpImageSampleDrefExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(91u, 0u), Instruction{"OpImageSampleProjImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(92u, 0u), Instruction{"OpImageSampleProjExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(93u, 0u), Instruction{"OpImageSampleProjDrefImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(94u, 0u), Instruction{"OpImageSampleProjDrefExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(95u, 0u), Instruction{"OpImageFetch", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(96u, 0u), Instruction{"OpImageGather", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Component'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(97u, 0u), Instruction{"OpImageDrefGather", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(98u, 0u), Instruction{"OpImageRead", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(99u, 0u), Instruction{"OpImageWrite", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Texel'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(100u, 0u), Instruction{"OpImage", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(101u, 0u), Instruction{"OpImageQueryFormat", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(102u, 0u), Instruction{"OpImageQueryOrder", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(103u, 0u), Instruction{"OpImageQuerySizeLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Level of Detail'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
		instr.capabilities.emplace_back(spv::Capability::ImageQuery);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(104u, 0u), Instruction{"OpImageQuerySize", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
		instr.capabilities.emplace_back(spv::Capability::ImageQuery);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(105u, 0u), Instruction{"OpImageQueryLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::ImageQuery);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(106u, 0u), Instruction{"OpImageQueryLevels", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
		instr.capabilities.emplace_back(spv::Capability::ImageQuery);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(107u, 0u), Instruction{"OpImageQuerySamples", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
		instr.capabilities.emplace_back(spv::Capability::ImageQuery);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(109u, 0u), Instruction{"OpConvertFToU", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Float Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(110u, 0u), Instruction{"OpConvertFToS", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Float Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(111u, 0u), Instruction{"OpConvertSToF", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Signed Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(112u, 0u), Instruction{"OpConvertUToF", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Unsigned Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(113u, 0u), Instruction{"OpUConvert", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Unsigned Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(114u, 0u), Instruction{"OpSConvert", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Signed Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(115u, 0u), Instruction{"OpFConvert", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Float Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(116u, 0u), Instruction{"OpQuantizeToF16", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(117u, 0u), Instruction{"OpConvertPtrToU", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
		instr.capabilities.emplace_back(spv::Capability::PhysicalStorageBufferAddresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(118u, 0u), Instruction{"OpSatConvertSToU", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Signed Value'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(119u, 0u), Instruction{"OpSatConvertUToS", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Unsigned Value'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(120u, 0u), Instruction{"OpConvertUToPtr", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Integer Value'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
		instr.capabilities.emplace_back(spv::Capability::PhysicalStorageBufferAddresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(121u, 0u), Instruction{"OpPtrCastToGeneric", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(122u, 0u), Instruction{"OpGenericCastToPtr", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(123u, 0u), Instruction{"OpGenericCastToPtrExplicit", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::StorageClass, OperandCategory::ValueEnum, "'Storage'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(124u, 0u), Instruction{"OpBitcast", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(126u, 0u), Instruction{"OpSNegate", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(127u, 0u), Instruction{"OpFNegate", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(128u, 0u), Instruction{"OpIAdd", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(129u, 0u), Instruction{"OpFAdd", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(130u, 0u), Instruction{"OpISub", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(131u, 0u), Instruction{"OpFSub", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(132u, 0u), Instruction{"OpIMul", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(133u, 0u), Instruction{"OpFMul", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(134u, 0u), Instruction{"OpUDiv", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(135u, 0u), Instruction{"OpSDiv", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(136u, 0u), Instruction{"OpFDiv", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(137u, 0u), Instruction{"OpUMod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(138u, 0u), Instruction{"OpSRem", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(139u, 0u), Instruction{"OpSMod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(140u, 0u), Instruction{"OpFRem", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(141u, 0u), Instruction{"OpFMod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(142u, 0u), Instruction{"OpVectorTimesScalar", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Scalar'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(143u, 0u), Instruction{"OpMatrixTimesScalar", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Matrix'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Scalar'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(144u, 0u), Instruction{"OpVectorTimesMatrix", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Matrix'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(145u, 0u), Instruction{"OpMatrixTimesVector", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Matrix'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(146u, 0u), Instruction{"OpMatrixTimesMatrix", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'LeftMatrix'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RightMatrix'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(147u, 0u), Instruction{"OpOuterProduct", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 2'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(148u, 0u), Instruction{"OpDot", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(149u, 0u), Instruction{"OpIAddCarry", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(150u, 0u), Instruction{"OpISubBorrow", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(151u, 0u), Instruction{"OpUMulExtended", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(152u, 0u), Instruction{"OpSMulExtended", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(154u, 0u), Instruction{"OpAny", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(155u, 0u), Instruction{"OpAll", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(156u, 0u), Instruction{"OpIsNan", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(157u, 0u), Instruction{"OpIsInf", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(158u, 0u), Instruction{"OpIsFinite", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(159u, 0u), Instruction{"OpIsNormal", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(160u, 0u), Instruction{"OpSignBitSet", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(161u, 0u), Instruction{"OpLessOrGreater", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(162u, 0u), Instruction{"OpOrdered", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(163u, 0u), Instruction{"OpUnordered", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(164u, 0u), Instruction{"OpLogicalEqual", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(165u, 0u), Instruction{"OpLogicalNotEqual", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(166u, 0u), Instruction{"OpLogicalOr", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(167u, 0u), Instruction{"OpLogicalAnd", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(168u, 0u), Instruction{"OpLogicalNot", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(169u, 0u), Instruction{"OpSelect", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Condition'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Object 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Object 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(170u, 0u), Instruction{"OpIEqual", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(171u, 0u), Instruction{"OpINotEqual", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(172u, 0u), Instruction{"OpUGreaterThan", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(173u, 0u), Instruction{"OpSGreaterThan", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(174u, 0u), Instruction{"OpUGreaterThanEqual", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(175u, 0u), Instruction{"OpSGreaterThanEqual", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(176u, 0u), Instruction{"OpULessThan", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(177u, 0u), Instruction{"OpSLessThan", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(178u, 0u), Instruction{"OpULessThanEqual", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(179u, 0u), Instruction{"OpSLessThanEqual", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(180u, 0u), Instruction{"OpFOrdEqual", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(181u, 0u), Instruction{"OpFUnordEqual", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(182u, 0u), Instruction{"OpFOrdNotEqual", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(183u, 0u), Instruction{"OpFUnordNotEqual", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(184u, 0u), Instruction{"OpFOrdLessThan", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(185u, 0u), Instruction{"OpFUnordLessThan", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(186u, 0u), Instruction{"OpFOrdGreaterThan", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(187u, 0u), Instruction{"OpFUnordGreaterThan", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(188u, 0u), Instruction{"OpFOrdLessThanEqual", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(189u, 0u), Instruction{"OpFUnordLessThanEqual", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(190u, 0u), Instruction{"OpFOrdGreaterThanEqual", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(191u, 0u), Instruction{"OpFUnordGreaterThanEqual", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(194u, 0u), Instruction{"OpShiftRightLogical", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Shift'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(195u, 0u), Instruction{"OpShiftRightArithmetic", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Shift'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(196u, 0u), Instruction{"OpShiftLeftLogical", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Shift'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(197u, 0u), Instruction{"OpBitwiseOr", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(198u, 0u), Instruction{"OpBitwiseXor", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(199u, 0u), Instruction{"OpBitwiseAnd", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(200u, 0u), Instruction{"OpNot", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(201u, 0u), Instruction{"OpBitFieldInsert", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Insert'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Count'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(202u, 0u), Instruction{"OpBitFieldSExtract", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Count'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(203u, 0u), Instruction{"OpBitFieldUExtract", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Count'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(204u, 0u), Instruction{"OpBitReverse", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(205u, 0u), Instruction{"OpBitCount", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(207u, 0u), Instruction{"OpDPdx", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(208u, 0u), Instruction{"OpDPdy", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(209u, 0u), Instruction{"OpFwidth", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(210u, 0u), Instruction{"OpDPdxFine", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(211u, 0u), Instruction{"OpDPdyFine", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(212u, 0u), Instruction{"OpFwidthFine", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(213u, 0u), Instruction{"OpDPdxCoarse", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(214u, 0u), Instruction{"OpDPdyCoarse", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(215u, 0u), Instruction{"OpFwidthCoarse", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(218u, 0u), Instruction{"OpEmitVertex", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::Geometry);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(219u, 0u), Instruction{"OpEndPrimitive", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::Geometry);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(220u, 0u), Instruction{"OpEmitStreamVertex", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Stream'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GeometryStreams);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(221u, 0u), Instruction{"OpEndStreamPrimitive", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Stream'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GeometryStreams);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(224u, 0u), Instruction{"OpControlBarrier", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(225u, 0u), Instruction{"OpMemoryBarrier", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(227u, 0u), Instruction{"OpAtomicLoad", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(228u, 0u), Instruction{"OpAtomicStore", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(229u, 0u), Instruction{"OpAtomicExchange", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(230u, 0u), Instruction{"OpAtomicCompareExchange", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(8u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Equal'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Unequal'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Comparator'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(231u, 0u), Instruction{"OpAtomicCompareExchangeWeak", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(8u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Equal'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Unequal'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Comparator'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(232u, 0u), Instruction{"OpAtomicIIncrement", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(233u, 0u), Instruction{"OpAtomicIDecrement", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(234u, 0u), Instruction{"OpAtomicIAdd", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(235u, 0u), Instruction{"OpAtomicISub", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(236u, 0u), Instruction{"OpAtomicSMin", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(237u, 0u), Instruction{"OpAtomicUMin", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(238u, 0u), Instruction{"OpAtomicSMax", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(239u, 0u), Instruction{"OpAtomicUMax", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(240u, 0u), Instruction{"OpAtomicAnd", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(241u, 0u), Instruction{"OpAtomicOr", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(242u, 0u), Instruction{"OpAtomicXor", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(245u, 0u), Instruction{"OpPhi", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::PairIdRefIdRef, OperandCategory::Composite, "'Variable, Parent, ...'", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(246u, 0u), Instruction{"OpLoopMerge", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Merge Block'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Continue Target'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LoopControl, OperandCategory::BitEnum, "", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(247u, 0u), Instruction{"OpSelectionMerge", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Merge Block'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::SelectionControl, OperandCategory::BitEnum, "", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(248u, 0u), Instruction{"OpLabel", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(249u, 0u), Instruction{"OpBranch", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target Label'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(250u, 0u), Instruction{"OpBranchConditional", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Condition'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'True Label'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'False Label'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Branch weights'", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(251u, 0u), Instruction{"OpSwitch", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Selector'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Default'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::PairLiteralIntegerIdRef, OperandCategory::Composite, "'Target'", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(252u, 0u), Instruction{"OpKill", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	m_instructions.emplaceUnique(Hash64(253u, 0u), Instruction{"OpReturn", _pAllocator, _pAllocator, _pAllocator, 0u});
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(254u, 0u), Instruction{"OpReturnValue", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
	}
	m_instructions.emplaceUnique(Hash64(255u, 0u), Instruction{"OpUnreachable", _pAllocator, _pAllocator, _pAllocator, 0u});
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(256u, 0u), Instruction{"OpLifetimeStart", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Size'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(257u, 0u), Instruction{"OpLifetimeStop", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Size'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(259u, 0u), Instruction{"OpGroupAsyncCopy", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(8u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Destination'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Source'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Elements'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Stride'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(260u, 0u), Instruction{"OpGroupWaitEvents", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Events'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Events List'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(261u, 0u), Instruction{"OpGroupAll", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(262u, 0u), Instruction{"OpGroupAny", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(263u, 0u), Instruction{"OpGroupBroadcast", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'LocalId'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(264u, 0u), Instruction{"OpGroupIAdd", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(265u, 0u), Instruction{"OpGroupFAdd", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(266u, 0u), Instruction{"OpGroupFMin", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(267u, 0u), Instruction{"OpGroupUMin", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(268u, 0u), Instruction{"OpGroupSMin", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(269u, 0u), Instruction{"OpGroupFMax", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(270u, 0u), Instruction{"OpGroupUMax", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(271u, 0u), Instruction{"OpGroupSMax", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(274u, 0u), Instruction{"OpReadPipe", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(275u, 0u), Instruction{"OpWritePipe", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(276u, 0u), Instruction{"OpReservedReadPipe", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(8u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(277u, 0u), Instruction{"OpReservedWritePipe", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(8u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(278u, 0u), Instruction{"OpReserveReadPipePackets", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Packets'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(279u, 0u), Instruction{"OpReserveWritePipePackets", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Packets'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(280u, 0u), Instruction{"OpCommitReadPipe", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(281u, 0u), Instruction{"OpCommitWritePipe", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(282u, 0u), Instruction{"OpIsValidReserveId", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(283u, 0u), Instruction{"OpGetNumPipePackets", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(284u, 0u), Instruction{"OpGetMaxPipePackets", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(285u, 0u), Instruction{"OpGroupReserveReadPipePackets", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(7u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Packets'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(286u, 0u), Instruction{"OpGroupReserveWritePipePackets", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(7u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Packets'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(287u, 0u), Instruction{"OpGroupCommitReadPipe", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(288u, 0u), Instruction{"OpGroupCommitWritePipe", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(291u, 0u), Instruction{"OpEnqueueMarker", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Queue'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Events'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Wait Events'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ret Event'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(292u, 0u), Instruction{"OpEnqueueKernel", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(13u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Queue'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Flags'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ND Range'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Events'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Wait Events'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ret Event'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Local Size'", Quantifier::ZeroOrAny);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(293u, 0u), Instruction{"OpGetKernelNDrangeSubGroupCount", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(7u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ND Range'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(294u, 0u), Instruction{"OpGetKernelNDrangeMaxSubGroupSize", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(7u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ND Range'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(295u, 0u), Instruction{"OpGetKernelWorkGroupSize", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(296u, 0u), Instruction{"OpGetKernelPreferredWorkGroupSizeMultiple", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(297u, 0u), Instruction{"OpRetainEvent", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(298u, 0u), Instruction{"OpReleaseEvent", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(299u, 0u), Instruction{"OpCreateUserEvent", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(300u, 0u), Instruction{"OpIsValidEvent", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(301u, 0u), Instruction{"OpSetUserEventStatus", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Status'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(302u, 0u), Instruction{"OpCaptureEventProfilingInfo", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Profiling Info'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(303u, 0u), Instruction{"OpGetDefaultQueue", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(304u, 0u), Instruction{"OpBuildNDRange", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'GlobalWorkSize'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'LocalWorkSize'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'GlobalWorkOffset'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(305u, 0u), Instruction{"OpImageSparseSampleImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(306u, 0u), Instruction{"OpImageSparseSampleExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(307u, 0u), Instruction{"OpImageSparseSampleDrefImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(308u, 0u), Instruction{"OpImageSparseSampleDrefExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(309u, 0u), Instruction{"OpImageSparseSampleProjImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(310u, 0u), Instruction{"OpImageSparseSampleProjExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(311u, 0u), Instruction{"OpImageSparseSampleProjDrefImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(312u, 0u), Instruction{"OpImageSparseSampleProjDrefExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(313u, 0u), Instruction{"OpImageSparseFetch", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(314u, 0u), Instruction{"OpImageSparseGather", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Component'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(315u, 0u), Instruction{"OpImageSparseDrefGather", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(316u, 0u), Instruction{"OpImageSparseTexelsResident", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Resident Code'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	m_instructions.emplaceUnique(Hash64(317u, 0u), Instruction{"OpNoLine", _pAllocator, _pAllocator, _pAllocator, 0u});
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(318u, 0u), Instruction{"OpAtomicFlagTestAndSet", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(319u, 0u), Instruction{"OpAtomicFlagClear", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(320u, 0u), Instruction{"OpImageSparseRead", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(321u, 0u), Instruction{"OpSizeOf", _pAllocator, _pAllocator, _pAllocator, 65792u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(322u, 0u), Instruction{"OpTypePipeStorage", _pAllocator, _pAllocator, _pAllocator, 65792u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::PipeStorage);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(323u, 0u), Instruction{"OpConstantPipeStorage", _pAllocator, _pAllocator, _pAllocator, 65792u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Packet Alignment'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Capacity'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::PipeStorage);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(324u, 0u), Instruction{"OpCreatePipeFromPipeStorage", _pAllocator, _pAllocator, _pAllocator, 65792u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe Storage'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::PipeStorage);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(325u, 0u), Instruction{"OpGetKernelLocalSizeForSubgroupCount", _pAllocator, _pAllocator, _pAllocator, 65792u}).kv.value;
		instr.operands.reserve(7u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Subgroup Count'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupDispatch);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(326u, 0u), Instruction{"OpGetKernelMaxNumSubgroups", _pAllocator, _pAllocator, _pAllocator, 65792u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupDispatch);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(327u, 0u), Instruction{"OpTypeNamedBarrier", _pAllocator, _pAllocator, _pAllocator, 65792u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::NamedBarrier);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(328u, 0u), Instruction{"OpNamedBarrierInitialize", _pAllocator, _pAllocator, _pAllocator, 65792u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Subgroup Count'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::NamedBarrier);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(329u, 0u), Instruction{"OpMemoryNamedBarrier", _pAllocator, _pAllocator, _pAllocator, 65792u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Named Barrier'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::NamedBarrier);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(330u, 0u), Instruction{"OpModuleProcessed", _pAllocator, _pAllocator, _pAllocator, 65792u}).kv.value;
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Process'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(331u, 0u), Instruction{"OpExecutionModeId", _pAllocator, _pAllocator, _pAllocator, 66048u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Entry Point'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ExecutionMode, OperandCategory::ValueEnum, "'Mode'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(332u, 0u), Instruction{"OpDecorateId", _pAllocator, _pAllocator, _pAllocator, 66048u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::Decoration, OperandCategory::ValueEnum, "", Quantifier::One);
		instr.extensions.emplace_back(spv::Extension::SPV_GOOGLE_hlsl_functionality1);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(333u, 0u), Instruction{"OpGroupNonUniformElect", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniform);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(334u, 0u), Instruction{"OpGroupNonUniformAll", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformVote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(335u, 0u), Instruction{"OpGroupNonUniformAny", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformVote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(336u, 0u), Instruction{"OpGroupNonUniformAllEqual", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformVote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(337u, 0u), Instruction{"OpGroupNonUniformBroadcast", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Id'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(338u, 0u), Instruction{"OpGroupNonUniformBroadcastFirst", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(339u, 0u), Instruction{"OpGroupNonUniformBallot", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(340u, 0u), Instruction{"OpGroupNonUniformInverseBallot", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(341u, 0u), Instruction{"OpGroupNonUniformBallotBitExtract", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(342u, 0u), Instruction{"OpGroupNonUniformBallotBitCount", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(343u, 0u), Instruction{"OpGroupNonUniformBallotFindLSB", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(344u, 0u), Instruction{"OpGroupNonUniformBallotFindMSB", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(345u, 0u), Instruction{"OpGroupNonUniformShuffle", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Id'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformShuffle);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(346u, 0u), Instruction{"OpGroupNonUniformShuffleXor", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Mask'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformShuffle);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(347u, 0u), Instruction{"OpGroupNonUniformShuffleUp", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Delta'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformShuffleRelative);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(348u, 0u), Instruction{"OpGroupNonUniformShuffleDown", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Delta'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformShuffleRelative);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(349u, 0u), Instruction{"OpGroupNonUniformIAdd", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'", Quantifier::ZeroOrOne);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(350u, 0u), Instruction{"OpGroupNonUniformFAdd", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'", Quantifier::ZeroOrOne);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(351u, 0u), Instruction{"OpGroupNonUniformIMul", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'", Quantifier::ZeroOrOne);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(352u, 0u), Instruction{"OpGroupNonUniformFMul", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'", Quantifier::ZeroOrOne);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(353u, 0u), Instruction{"OpGroupNonUniformSMin", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'", Quantifier::ZeroOrOne);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(354u, 0u), Instruction{"OpGroupNonUniformUMin", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'", Quantifier::ZeroOrOne);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(355u, 0u), Instruction{"OpGroupNonUniformFMin", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'", Quantifier::ZeroOrOne);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(356u, 0u), Instruction{"OpGroupNonUniformSMax", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'", Quantifier::ZeroOrOne);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(357u, 0u), Instruction{"OpGroupNonUniformUMax", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'", Quantifier::ZeroOrOne);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(358u, 0u), Instruction{"OpGroupNonUniformFMax", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'", Quantifier::ZeroOrOne);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(359u, 0u), Instruction{"OpGroupNonUniformBitwiseAnd", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'", Quantifier::ZeroOrOne);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(360u, 0u), Instruction{"OpGroupNonUniformBitwiseOr", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'", Quantifier::ZeroOrOne);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(361u, 0u), Instruction{"OpGroupNonUniformBitwiseXor", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'", Quantifier::ZeroOrOne);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(362u, 0u), Instruction{"OpGroupNonUniformLogicalAnd", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'", Quantifier::ZeroOrOne);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(363u, 0u), Instruction{"OpGroupNonUniformLogicalOr", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'", Quantifier::ZeroOrOne);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(364u, 0u), Instruction{"OpGroupNonUniformLogicalXor", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'", Quantifier::ZeroOrOne);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(365u, 0u), Instruction{"OpGroupNonUniformQuadBroadcast", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformQuad);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(366u, 0u), Instruction{"OpGroupNonUniformQuadSwap", _pAllocator, _pAllocator, _pAllocator, 66304u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformQuad);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(400u, 0u), Instruction{"OpCopyLogical", _pAllocator, _pAllocator, _pAllocator, 66560u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(401u, 0u), Instruction{"OpPtrEqual", _pAllocator, _pAllocator, _pAllocator, 66560u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(402u, 0u), Instruction{"OpPtrNotEqual", _pAllocator, _pAllocator, _pAllocator, 66560u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(403u, 0u), Instruction{"OpPtrDiff", _pAllocator, _pAllocator, _pAllocator, 66560u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
		instr.capabilities.emplace_back(spv::Capability::VariablePointers);
		instr.capabilities.emplace_back(spv::Capability::VariablePointersStorageBuffer);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4416u, 0u), Instruction{"OpTerminateInvocation", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::Shader);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_terminate_invocation);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4421u, 0u), Instruction{"OpSubgroupBallotKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupBallotKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4422u, 0u), Instruction{"OpSubgroupFirstInvocationKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupBallotKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4428u, 0u), Instruction{"OpSubgroupAllKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupVoteKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_subgroup_vote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4429u, 0u), Instruction{"OpSubgroupAnyKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupVoteKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_subgroup_vote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4430u, 0u), Instruction{"OpSubgroupAllEqualKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupVoteKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_subgroup_vote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4432u, 0u), Instruction{"OpSubgroupReadInvocationKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupBallotKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4445u, 0u), Instruction{"OpTraceRayKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(11u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Accel'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ray Flags'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Cull Mask'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'SBT Offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'SBT Stride'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Miss Index'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ray Origin'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ray Tmin'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ray Direction'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ray Tmax'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayTracingKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4446u, 0u), Instruction{"OpExecuteCallableKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'SBT Index'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Callable Data'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayTracingKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4447u, 0u), Instruction{"OpConvertUToAccelerationStructureKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Accel'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::RayTracingKHR);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.reserve(2u);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4448u, 0u), Instruction{"OpIgnoreIntersectionKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::RayTracingKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4449u, 0u), Instruction{"OpTerminateRayKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::RayTracingKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4472u, 0u), Instruction{"OpTypeRayQueryKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4473u, 0u), Instruction{"OpRayQueryInitializeKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(8u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Accel'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayFlags'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'CullMask'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayOrigin'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayTMin'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayDirection'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayTMax'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4474u, 0u), Instruction{"OpRayQueryTerminateKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4475u, 0u), Instruction{"OpRayQueryGenerateIntersectionKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'HitT'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4476u, 0u), Instruction{"OpRayQueryConfirmIntersectionKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4477u, 0u), Instruction{"OpRayQueryProceedKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4479u, 0u), Instruction{"OpRayQueryGetIntersectionTypeKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5000u, 0u), Instruction{"OpGroupIAddNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5001u, 0u), Instruction{"OpGroupFAddNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5002u, 0u), Instruction{"OpGroupFMinNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5003u, 0u), Instruction{"OpGroupUMinNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5004u, 0u), Instruction{"OpGroupSMinNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5005u, 0u), Instruction{"OpGroupFMaxNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5006u, 0u), Instruction{"OpGroupUMaxNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5007u, 0u), Instruction{"OpGroupSMaxNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5011u, 0u), Instruction{"OpFragmentMaskFetchAMD", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::FragmentMaskAMD);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_fragment_mask);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5012u, 0u), Instruction{"OpFragmentFetchAMD", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fragment Index'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::FragmentMaskAMD);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_fragment_mask);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5056u, 0u), Instruction{"OpReadClockKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::ShaderClockKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_shader_clock);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5283u, 0u), Instruction{"OpImageSampleFootprintNV", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(7u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Granularity'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coarse'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::ImageFootprintNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_shader_image_footprint);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5296u, 0u), Instruction{"OpGroupNonUniformPartitionNV", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_shader_subgroup_partitioned);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5299u, 0u), Instruction{"OpWritePackedPrimitiveIndices4x8NV", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index Offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Indices'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::MeshShadingNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_mesh_shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5334u, 0u), Instruction{"OpReportIntersectionKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Hit'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'HitKind'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::RayTracingNV);
		instr.capabilities.emplace_back(spv::Capability::RayTracingKHR);
		instr.extensions.reserve(2u);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_ray_tracing);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5335u, 0u), Instruction{"OpIgnoreIntersectionNV", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::RayTracingNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5336u, 0u), Instruction{"OpTerminateRayNV", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::RayTracingNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5337u, 0u), Instruction{"OpTraceNV", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(11u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Accel'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ray Flags'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Cull Mask'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'SBT Offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'SBT Stride'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Miss Index'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ray Origin'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ray Tmin'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ray Direction'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ray Tmax'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'PayloadId'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayTracingNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5341u, 0u), Instruction{"OpTypeAccelerationStructureKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::RayTracingNV);
		instr.capabilities.emplace_back(spv::Capability::RayTracingKHR);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.reserve(3u);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_ray_tracing);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5344u, 0u), Instruction{"OpExecuteCallableNV", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'SBT Index'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Callable DataId'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayTracingNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5358u, 0u), Instruction{"OpTypeCooperativeMatrixNV", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Component Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Rows'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Columns'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::CooperativeMatrixNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_cooperative_matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5359u, 0u), Instruction{"OpCooperativeMatrixLoadNV", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Stride'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Column Major'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::CooperativeMatrixNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_cooperative_matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5360u, 0u), Instruction{"OpCooperativeMatrixStoreNV", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Object'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Stride'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Column Major'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "", Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::CooperativeMatrixNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_cooperative_matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5361u, 0u), Instruction{"OpCooperativeMatrixMulAddNV", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'A'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'B'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'C'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::CooperativeMatrixNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_cooperative_matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5362u, 0u), Instruction{"OpCooperativeMatrixLengthNV", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Type'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::CooperativeMatrixNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_cooperative_matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5364u, 0u), Instruction{"OpBeginInvocationInterlockEXT", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderSampleInterlockEXT);
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderPixelInterlockEXT);
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderShadingRateInterlockEXT);
		instr.extensions.emplace_back(spv::Extension::SPV_EXT_fragment_shader_interlock);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5365u, 0u), Instruction{"OpEndInvocationInterlockEXT", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderSampleInterlockEXT);
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderPixelInterlockEXT);
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderShadingRateInterlockEXT);
		instr.extensions.emplace_back(spv::Extension::SPV_EXT_fragment_shader_interlock);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5380u, 0u), Instruction{"OpDemoteToHelperInvocationEXT", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::DemoteToHelperInvocationEXT);
		instr.extensions.emplace_back(spv::Extension::SPV_EXT_demote_to_helper_invocation);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5381u, 0u), Instruction{"OpIsHelperInvocationEXT", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DemoteToHelperInvocationEXT);
		instr.extensions.emplace_back(spv::Extension::SPV_EXT_demote_to_helper_invocation);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5571u, 0u), Instruction{"OpSubgroupShuffleINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Data'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'InvocationId'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupShuffleINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5572u, 0u), Instruction{"OpSubgroupShuffleDownINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Current'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Next'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Delta'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupShuffleINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5573u, 0u), Instruction{"OpSubgroupShuffleUpINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Previous'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Current'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Delta'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupShuffleINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5574u, 0u), Instruction{"OpSubgroupShuffleXorINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Data'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupShuffleINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5575u, 0u), Instruction{"OpSubgroupBlockReadINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ptr'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupBufferBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5576u, 0u), Instruction{"OpSubgroupBlockWriteINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ptr'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Data'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupBufferBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5577u, 0u), Instruction{"OpSubgroupImageBlockReadINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupImageBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5578u, 0u), Instruction{"OpSubgroupImageBlockWriteINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Data'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupImageBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5580u, 0u), Instruction{"OpSubgroupImageMediaBlockReadINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Width'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Height'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupImageMediaBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5581u, 0u), Instruction{"OpSubgroupImageMediaBlockWriteINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Width'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Height'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Data'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupImageMediaBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5585u, 0u), Instruction{"OpUCountLeadingZerosINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5586u, 0u), Instruction{"OpUCountTrailingZerosINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5587u, 0u), Instruction{"OpAbsISubINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5588u, 0u), Instruction{"OpAbsUSubINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5589u, 0u), Instruction{"OpIAddSatINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5590u, 0u), Instruction{"OpUAddSatINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5591u, 0u), Instruction{"OpIAverageINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5592u, 0u), Instruction{"OpUAverageINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5593u, 0u), Instruction{"OpIAverageRoundedINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5594u, 0u), Instruction{"OpUAverageRoundedINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5595u, 0u), Instruction{"OpISubSatINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5596u, 0u), Instruction{"OpUSubSatINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5597u, 0u), Instruction{"OpIMul32x16INTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5598u, 0u), Instruction{"OpUMul32x16INTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5600u, 0u), Instruction{"OpConstFunctionPointerINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Function'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::FunctionPointersINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_function_pointers);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5601u, 0u), Instruction{"OpFunctionPointerCallINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'", Quantifier::ZeroOrAny);
		instr.capabilities.emplace_back(spv::Capability::FunctionPointersINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_function_pointers);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5609u, 0u), Instruction{"OpAsmTargetINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Asm target'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::AsmINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5610u, 0u), Instruction{"OpAsmINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Asm type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Asm instructions'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Constraints'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::AsmINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5611u, 0u), Instruction{"OpAsmCallINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Asm'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Argument 0'", Quantifier::ZeroOrAny);
		instr.capabilities.emplace_back(spv::Capability::AsmINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5614u, 0u), Instruction{"OpAtomicFMinEXT", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::AtomicFloat16MinMaxEXT);
		instr.capabilities.emplace_back(spv::Capability::AtomicFloat32MinMaxEXT);
		instr.capabilities.emplace_back(spv::Capability::AtomicFloat64MinMaxEXT);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5615u, 0u), Instruction{"OpAtomicFMaxEXT", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.capabilities.reserve(3u);
		instr.capabilities.emplace_back(spv::Capability::AtomicFloat16MinMaxEXT);
		instr.capabilities.emplace_back(spv::Capability::AtomicFloat32MinMaxEXT);
		instr.capabilities.emplace_back(spv::Capability::AtomicFloat64MinMaxEXT);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5632u, 0u), Instruction{"OpDecorateString", _pAllocator, _pAllocator, _pAllocator, 66560u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::Decoration, OperandCategory::ValueEnum, "", Quantifier::One);
		instr.extensions.reserve(2u);
		instr.extensions.emplace_back(spv::Extension::SPV_GOOGLE_decorate_string);
		instr.extensions.emplace_back(spv::Extension::SPV_GOOGLE_hlsl_functionality1);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5633u, 0u), Instruction{"OpMemberDecorateString", _pAllocator, _pAllocator, _pAllocator, 66560u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Struct Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Member'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::Decoration, OperandCategory::ValueEnum, "", Quantifier::One);
		instr.extensions.reserve(2u);
		instr.extensions.emplace_back(spv::Extension::SPV_GOOGLE_decorate_string);
		instr.extensions.emplace_back(spv::Extension::SPV_GOOGLE_hlsl_functionality1);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5699u, 0u), Instruction{"OpVmeImageINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampler'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5700u, 0u), Instruction{"OpTypeVmeImageINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image Type'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5701u, 0u), Instruction{"OpTypeAvcImePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5702u, 0u), Instruction{"OpTypeAvcRefPayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5703u, 0u), Instruction{"OpTypeAvcSicPayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5704u, 0u), Instruction{"OpTypeAvcMcePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5705u, 0u), Instruction{"OpTypeAvcMceResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5706u, 0u), Instruction{"OpTypeAvcImeResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5707u, 0u), Instruction{"OpTypeAvcImeResultSingleReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5708u, 0u), Instruction{"OpTypeAvcImeResultDualReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5709u, 0u), Instruction{"OpTypeAvcImeSingleReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5710u, 0u), Instruction{"OpTypeAvcImeDualReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5711u, 0u), Instruction{"OpTypeAvcRefResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5712u, 0u), Instruction{"OpTypeAvcSicResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5713u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultInterBaseMultiReferencePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5714u, 0u), Instruction{"OpSubgroupAvcMceSetInterBaseMultiReferencePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reference Base Penalty'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5715u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultInterShapePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5716u, 0u), Instruction{"OpSubgroupAvcMceSetInterShapePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Shape Penalty'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5717u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultInterDirectionPenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5718u, 0u), Instruction{"OpSubgroupAvcMceSetInterDirectionPenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction Cost'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5719u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultIntraLumaShapePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5720u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultInterMotionVectorCostTableINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5721u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultHighPenaltyCostTableINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5722u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultMediumPenaltyCostTableINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5723u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultLowPenaltyCostTableINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5724u, 0u), Instruction{"OpSubgroupAvcMceSetMotionVectorCostFunctionINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Cost Center Delta'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Cost Table'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Cost Precision'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5725u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultIntraLumaModePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5726u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultNonDcLumaIntraPenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5727u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultIntraChromaModeBasePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationChromaINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5728u, 0u), Instruction{"OpSubgroupAvcMceSetAcOnlyHaarINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5729u, 0u), Instruction{"OpSubgroupAvcMceSetSourceInterlacedFieldPolarityINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Source Field Polarity'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5730u, 0u), Instruction{"OpSubgroupAvcMceSetSingleReferenceInterlacedFieldPolarityINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reference Field Polarity'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5731u, 0u), Instruction{"OpSubgroupAvcMceSetDualReferenceInterlacedFieldPolaritiesINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Forward Reference Field Polarity'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Backward Reference Field Polarity'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5732u, 0u), Instruction{"OpSubgroupAvcMceConvertToImePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5733u, 0u), Instruction{"OpSubgroupAvcMceConvertToImeResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5734u, 0u), Instruction{"OpSubgroupAvcMceConvertToRefPayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5735u, 0u), Instruction{"OpSubgroupAvcMceConvertToRefResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5736u, 0u), Instruction{"OpSubgroupAvcMceConvertToSicPayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5737u, 0u), Instruction{"OpSubgroupAvcMceConvertToSicResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5738u, 0u), Instruction{"OpSubgroupAvcMceGetMotionVectorsINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5739u, 0u), Instruction{"OpSubgroupAvcMceGetInterDistortionsINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5740u, 0u), Instruction{"OpSubgroupAvcMceGetBestInterDistortionsINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5741u, 0u), Instruction{"OpSubgroupAvcMceGetInterMajorShapeINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5742u, 0u), Instruction{"OpSubgroupAvcMceGetInterMinorShapeINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5743u, 0u), Instruction{"OpSubgroupAvcMceGetInterDirectionsINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5744u, 0u), Instruction{"OpSubgroupAvcMceGetInterMotionVectorCountINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5745u, 0u), Instruction{"OpSubgroupAvcMceGetInterReferenceIdsINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5746u, 0u), Instruction{"OpSubgroupAvcMceGetInterReferenceInterlacedFieldPolaritiesINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Ids'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Parameter Field Polarities'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5747u, 0u), Instruction{"OpSubgroupAvcImeInitializeINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Coord'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Partition Mask'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'SAD Adjustment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5748u, 0u), Instruction{"OpSubgroupAvcImeSetSingleReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Search Window Config'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5749u, 0u), Instruction{"OpSubgroupAvcImeSetDualReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'id> Search Window Config'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5750u, 0u), Instruction{"OpSubgroupAvcImeRefWindowSizeINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Search Window Config'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Dual Ref'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5751u, 0u), Instruction{"OpSubgroupAvcImeAdjustRefOffsetINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Coord'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Window Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image Size'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5752u, 0u), Instruction{"OpSubgroupAvcImeConvertToMcePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5753u, 0u), Instruction{"OpSubgroupAvcImeSetMaxMotionVectorCountINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Max Motion Vector Count'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5754u, 0u), Instruction{"OpSubgroupAvcImeSetUnidirectionalMixDisableINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5755u, 0u), Instruction{"OpSubgroupAvcImeSetEarlySearchTerminationThresholdINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Threshold'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5756u, 0u), Instruction{"OpSubgroupAvcImeSetWeightedSadINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Sad Weights'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5757u, 0u), Instruction{"OpSubgroupAvcImeEvaluateWithSingleReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5758u, 0u), Instruction{"OpSubgroupAvcImeEvaluateWithDualReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5759u, 0u), Instruction{"OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Streamin Components'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5760u, 0u), Instruction{"OpSubgroupAvcImeEvaluateWithDualReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(7u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Streamin Components'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5761u, 0u), Instruction{"OpSubgroupAvcImeEvaluateWithSingleReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5762u, 0u), Instruction{"OpSubgroupAvcImeEvaluateWithDualReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5763u, 0u), Instruction{"OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Streamin Components'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5764u, 0u), Instruction{"OpSubgroupAvcImeEvaluateWithDualReferenceStreaminoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(7u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Streamin Components'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5765u, 0u), Instruction{"OpSubgroupAvcImeConvertToMceResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5766u, 0u), Instruction{"OpSubgroupAvcImeGetSingleReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5767u, 0u), Instruction{"OpSubgroupAvcImeGetDualReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5768u, 0u), Instruction{"OpSubgroupAvcImeStripSingleReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5769u, 0u), Instruction{"OpSubgroupAvcImeStripDualReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5770u, 0u), Instruction{"OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeMotionVectorsINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5771u, 0u), Instruction{"OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeDistortionsINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5772u, 0u), Instruction{"OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeReferenceIdsINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5773u, 0u), Instruction{"OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeMotionVectorsINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5774u, 0u), Instruction{"OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeDistortionsINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5775u, 0u), Instruction{"OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeReferenceIdsINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5776u, 0u), Instruction{"OpSubgroupAvcImeGetBorderReachedINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image Select'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5777u, 0u), Instruction{"OpSubgroupAvcImeGetTruncatedSearchIndicationINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5778u, 0u), Instruction{"OpSubgroupAvcImeGetUnidirectionalEarlySearchTerminationINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5779u, 0u), Instruction{"OpSubgroupAvcImeGetWeightingPatternMinimumMotionVectorINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5780u, 0u), Instruction{"OpSubgroupAvcImeGetWeightingPatternMinimumDistortionINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5781u, 0u), Instruction{"OpSubgroupAvcFmeInitializeINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(9u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Coord'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Motion Vectors'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shapes'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Minor Shapes'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pixel Resolution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sad Adjustment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5782u, 0u), Instruction{"OpSubgroupAvcBmeInitializeINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(10u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Coord'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Motion Vectors'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shapes'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Minor Shapes'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pixel Resolution'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bidirectional Weight'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sad Adjustment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5783u, 0u), Instruction{"OpSubgroupAvcRefConvertToMcePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5784u, 0u), Instruction{"OpSubgroupAvcRefSetBidirectionalMixDisableINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5785u, 0u), Instruction{"OpSubgroupAvcRefSetBilinearFilterEnableINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5786u, 0u), Instruction{"OpSubgroupAvcRefEvaluateWithSingleReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5787u, 0u), Instruction{"OpSubgroupAvcRefEvaluateWithDualReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5788u, 0u), Instruction{"OpSubgroupAvcRefEvaluateWithMultiReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Ids'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5789u, 0u), Instruction{"OpSubgroupAvcRefEvaluateWithMultiReferenceInterlacedINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Ids'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Field Polarities'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5790u, 0u), Instruction{"OpSubgroupAvcRefConvertToMceResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5791u, 0u), Instruction{"OpSubgroupAvcSicInitializeINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Coord'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5792u, 0u), Instruction{"OpSubgroupAvcSicConfigureSkcINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(8u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Skip Block Partition Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Skip Motion Vector Mask'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Motion Vectors'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bidirectional Weight'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sad Adjustment'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5793u, 0u), Instruction{"OpSubgroupAvcSicConfigureIpeLumaINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(10u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Luma Intra Partition Mask'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intra Neighbour Availabilty'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Left Edge Luma Pixels'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Upper Left Corner Luma Pixel'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Upper Edge Luma Pixels'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Upper Right Edge Luma Pixels'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sad Adjustment'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5794u, 0u), Instruction{"OpSubgroupAvcSicConfigureIpeLumaChromaINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(13u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Luma Intra Partition Mask'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intra Neighbour Availabilty'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Left Edge Luma Pixels'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Upper Left Corner Luma Pixel'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Upper Edge Luma Pixels'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Upper Right Edge Luma Pixels'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Left Edge Chroma Pixels'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Upper Left Corner Chroma Pixel'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Upper Edge Chroma Pixels'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sad Adjustment'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationChromaINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5795u, 0u), Instruction{"OpSubgroupAvcSicGetMotionVectorMaskINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Skip Block Partition Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5796u, 0u), Instruction{"OpSubgroupAvcSicConvertToMcePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5797u, 0u), Instruction{"OpSubgroupAvcSicSetIntraLumaShapePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Shape Penalty'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5798u, 0u), Instruction{"OpSubgroupAvcSicSetIntraLumaModeCostFunctionINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Luma Mode Penalty'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Luma Packed Neighbor Modes'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Luma Packed Non Dc Penalty'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5799u, 0u), Instruction{"OpSubgroupAvcSicSetIntraChromaModeCostFunctionINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Chroma Mode Base Penalty'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationChromaINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5800u, 0u), Instruction{"OpSubgroupAvcSicSetBilinearFilterEnableINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5801u, 0u), Instruction{"OpSubgroupAvcSicSetSkcForwardTransformEnableINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Sad Coefficients'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5802u, 0u), Instruction{"OpSubgroupAvcSicSetBlockBasedRawSkipSadINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Block Based Skip Type'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5803u, 0u), Instruction{"OpSubgroupAvcSicEvaluateIpeINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5804u, 0u), Instruction{"OpSubgroupAvcSicEvaluateWithSingleReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5805u, 0u), Instruction{"OpSubgroupAvcSicEvaluateWithDualReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5806u, 0u), Instruction{"OpSubgroupAvcSicEvaluateWithMultiReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(5u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Ids'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5807u, 0u), Instruction{"OpSubgroupAvcSicEvaluateWithMultiReferenceInterlacedINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Ids'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Field Polarities'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5808u, 0u), Instruction{"OpSubgroupAvcSicConvertToMceResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5809u, 0u), Instruction{"OpSubgroupAvcSicGetIpeLumaShapeINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5810u, 0u), Instruction{"OpSubgroupAvcSicGetBestIpeLumaDistortionINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5811u, 0u), Instruction{"OpSubgroupAvcSicGetBestIpeChromaDistortionINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5812u, 0u), Instruction{"OpSubgroupAvcSicGetPackedIpeLumaModesINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5813u, 0u), Instruction{"OpSubgroupAvcSicGetIpeChromaModeINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationChromaINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5814u, 0u), Instruction{"OpSubgroupAvcSicGetPackedSkcLumaCountThresholdINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5815u, 0u), Instruction{"OpSubgroupAvcSicGetPackedSkcLumaSumThresholdINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5816u, 0u), Instruction{"OpSubgroupAvcSicGetInterRawSadsINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5818u, 0u), Instruction{"OpVariableLengthArrayINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Lenght'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::VariableLengthArrayINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5819u, 0u), Instruction{"OpSaveMemoryINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::VariableLengthArrayINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5820u, 0u), Instruction{"OpRestoreMemoryINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ptr'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::VariableLengthArrayINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5887u, 0u), Instruction{"OpLoopControlINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Loop Control Parameters'", Quantifier::ZeroOrAny);
		instr.capabilities.emplace_back(spv::Capability::UnstructuredLoopControlsINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_unstructured_loop_controls);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5934u, 0u), Instruction{"OpPtrCastToCrossWorkgroupINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::USMStorageClassesINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5938u, 0u), Instruction{"OpCrossWorkgroupCastToPtrINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::USMStorageClassesINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5946u, 0u), Instruction{"OpReadPipeBlockingINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::BlockingPipesINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_blocking_pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5947u, 0u), Instruction{"OpWritePipeBlockingINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::BlockingPipesINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_blocking_pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5949u, 0u), Instruction{"OpFPGARegINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Result'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Input'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::FPGARegINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_fpga_reg);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6016u, 0u), Instruction{"OpRayQueryGetRayTMinKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6017u, 0u), Instruction{"OpRayQueryGetRayFlagsKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6018u, 0u), Instruction{"OpRayQueryGetIntersectionTKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6019u, 0u), Instruction{"OpRayQueryGetIntersectionInstanceCustomIndexKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6020u, 0u), Instruction{"OpRayQueryGetIntersectionInstanceIdKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6021u, 0u), Instruction{"OpRayQueryGetIntersectionInstanceShaderBindingTableRecordOffsetKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6022u, 0u), Instruction{"OpRayQueryGetIntersectionGeometryIndexKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6023u, 0u), Instruction{"OpRayQueryGetIntersectionPrimitiveIndexKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6024u, 0u), Instruction{"OpRayQueryGetIntersectionBarycentricsKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6025u, 0u), Instruction{"OpRayQueryGetIntersectionFrontFaceKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6026u, 0u), Instruction{"OpRayQueryGetIntersectionCandidateAABBOpaqueKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6027u, 0u), Instruction{"OpRayQueryGetIntersectionObjectRayDirectionKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6028u, 0u), Instruction{"OpRayQueryGetIntersectionObjectRayOriginKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6029u, 0u), Instruction{"OpRayQueryGetWorldRayDirectionKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6030u, 0u), Instruction{"OpRayQueryGetWorldRayOriginKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6031u, 0u), Instruction{"OpRayQueryGetIntersectionObjectToWorldKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6032u, 0u), Instruction{"OpRayQueryGetIntersectionWorldToObjectKHR", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6035u, 0u), Instruction{"OpAtomicFAddEXT", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(6u);
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
		instr.capabilities.reserve(2u);
		instr.capabilities.emplace_back(spv::Capability::AtomicFloat32AddEXT);
		instr.capabilities.emplace_back(spv::Capability::AtomicFloat64AddEXT);
		instr.extensions.emplace_back(spv::Extension::SPV_EXT_shader_atomic_float_add);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6086u, 0u), Instruction{"OpTypeBufferSurfaceINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::VectorComputeINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6090u, 0u), Instruction{"OpTypeStructContinuedINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Member 0 type', +'member 1 type', +...", Quantifier::ZeroOrAny);
		instr.capabilities.emplace_back(spv::Capability::LongConstantCompositeINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6091u, 0u), Instruction{"OpConstantCompositeContinuedINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Constituents'", Quantifier::ZeroOrAny);
		instr.capabilities.emplace_back(spv::Capability::LongConstantCompositeINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6092u, 0u), Instruction{"OpSpecConstantCompositeContinuedINTEL", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Constituents'", Quantifier::ZeroOrAny);
		instr.capabilities.emplace_back(spv::Capability::LongConstantCompositeINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(1u, 1u), Instruction{"Round", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(2u, 1u), Instruction{"RoundEven", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(3u, 1u), Instruction{"Trunc", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4u, 1u), Instruction{"FAbs", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5u, 1u), Instruction{"SAbs", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6u, 1u), Instruction{"FSign", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(7u, 1u), Instruction{"SSign", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(8u, 1u), Instruction{"Floor", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(9u, 1u), Instruction{"Ceil", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(10u, 1u), Instruction{"Fract", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(11u, 1u), Instruction{"Radians", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'degrees'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(12u, 1u), Instruction{"Degrees", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'radians'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(13u, 1u), Instruction{"Sin", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(14u, 1u), Instruction{"Cos", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(15u, 1u), Instruction{"Tan", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(16u, 1u), Instruction{"Asin", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(17u, 1u), Instruction{"Acos", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(18u, 1u), Instruction{"Atan", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y_over_x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(19u, 1u), Instruction{"Sinh", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(20u, 1u), Instruction{"Cosh", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(21u, 1u), Instruction{"Tanh", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(22u, 1u), Instruction{"Asinh", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(23u, 1u), Instruction{"Acosh", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(24u, 1u), Instruction{"Atanh", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(25u, 1u), Instruction{"Atan2", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(26u, 1u), Instruction{"Pow", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(27u, 1u), Instruction{"Exp", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(28u, 1u), Instruction{"Log", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(29u, 1u), Instruction{"Exp2", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(30u, 1u), Instruction{"Log2", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(31u, 1u), Instruction{"Sqrt", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(32u, 1u), Instruction{"InverseSqrt", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(33u, 1u), Instruction{"Determinant", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(34u, 1u), Instruction{"MatrixInverse", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(35u, 1u), Instruction{"Modf", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'i'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(36u, 1u), Instruction{"ModfStruct", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(37u, 1u), Instruction{"FMin", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(38u, 1u), Instruction{"UMin", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(39u, 1u), Instruction{"SMin", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(40u, 1u), Instruction{"FMax", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(41u, 1u), Instruction{"UMax", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(42u, 1u), Instruction{"SMax", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(43u, 1u), Instruction{"FClamp", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minVal'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxVal'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(44u, 1u), Instruction{"UClamp", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minVal'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxVal'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(45u, 1u), Instruction{"SClamp", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minVal'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxVal'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(46u, 1u), Instruction{"FMix", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(47u, 1u), Instruction{"IMix", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(48u, 1u), Instruction{"Step", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(49u, 1u), Instruction{"SmoothStep", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge0'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(50u, 1u), Instruction{"Fma", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(51u, 1u), Instruction{"Frexp", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'exp'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(52u, 1u), Instruction{"FrexpStruct", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(53u, 1u), Instruction{"Ldexp", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'exp'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(54u, 1u), Instruction{"PackSnorm4x8", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(55u, 1u), Instruction{"PackUnorm4x8", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(56u, 1u), Instruction{"PackSnorm2x16", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(57u, 1u), Instruction{"PackUnorm2x16", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(58u, 1u), Instruction{"PackHalf2x16", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(59u, 1u), Instruction{"PackDouble2x32", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Float64);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(60u, 1u), Instruction{"UnpackSnorm2x16", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(61u, 1u), Instruction{"UnpackUnorm2x16", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(62u, 1u), Instruction{"UnpackHalf2x16", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(63u, 1u), Instruction{"UnpackSnorm4x8", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(64u, 1u), Instruction{"UnpackUnorm4x8", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(65u, 1u), Instruction{"UnpackDouble2x32", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Float64);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(66u, 1u), Instruction{"Length", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(67u, 1u), Instruction{"Distance", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p0'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p1'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(68u, 1u), Instruction{"Cross", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(69u, 1u), Instruction{"Normalize", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(70u, 1u), Instruction{"FaceForward", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'N'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'I'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Nref'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(71u, 1u), Instruction{"Reflect", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'I'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'N'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(72u, 1u), Instruction{"Refract", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'I'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'N'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'eta'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(73u, 1u), Instruction{"FindILsb", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(74u, 1u), Instruction{"FindSMsb", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(75u, 1u), Instruction{"FindUMsb", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(76u, 1u), Instruction{"InterpolateAtCentroid", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'interpolant'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::InterpolationFunction);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(77u, 1u), Instruction{"InterpolateAtSample", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'interpolant'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'sample'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::InterpolationFunction);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(78u, 1u), Instruction{"InterpolateAtOffset", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'interpolant'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'", Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::InterpolationFunction);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(79u, 1u), Instruction{"NMin", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(80u, 1u), Instruction{"NMax", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(81u, 1u), Instruction{"NClamp", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minVal'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxVal'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(0u, 2u), Instruction{"acos", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(1u, 2u), Instruction{"acosh", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(2u, 2u), Instruction{"acospi", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(3u, 2u), Instruction{"asin", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4u, 2u), Instruction{"asinh", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5u, 2u), Instruction{"asinpi", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6u, 2u), Instruction{"atan", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(7u, 2u), Instruction{"atan2", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(8u, 2u), Instruction{"atanh", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(9u, 2u), Instruction{"atanpi", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(10u, 2u), Instruction{"atan2pi", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(11u, 2u), Instruction{"cbrt", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(12u, 2u), Instruction{"ceil", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(13u, 2u), Instruction{"copysign", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(14u, 2u), Instruction{"cos", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(15u, 2u), Instruction{"cosh", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(16u, 2u), Instruction{"cospi", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(17u, 2u), Instruction{"erfc", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(18u, 2u), Instruction{"erf", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(19u, 2u), Instruction{"exp", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(20u, 2u), Instruction{"exp2", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(21u, 2u), Instruction{"exp10", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(22u, 2u), Instruction{"expm1", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(23u, 2u), Instruction{"fabs", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(24u, 2u), Instruction{"fdim", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(25u, 2u), Instruction{"floor", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(26u, 2u), Instruction{"fma", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(27u, 2u), Instruction{"fmax", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(28u, 2u), Instruction{"fmin", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(29u, 2u), Instruction{"fmod", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(30u, 2u), Instruction{"fract", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ptr'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(31u, 2u), Instruction{"frexp", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'exp'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(32u, 2u), Instruction{"hypot", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(33u, 2u), Instruction{"ilogb", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(34u, 2u), Instruction{"ldexp", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'k'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(35u, 2u), Instruction{"lgamma", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(36u, 2u), Instruction{"lgamma_r", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'signp'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(37u, 2u), Instruction{"log", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(38u, 2u), Instruction{"log2", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(39u, 2u), Instruction{"log10", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(40u, 2u), Instruction{"log1p", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(41u, 2u), Instruction{"logb", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(42u, 2u), Instruction{"mad", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(43u, 2u), Instruction{"maxmag", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(44u, 2u), Instruction{"minmag", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(45u, 2u), Instruction{"modf", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'iptr'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(46u, 2u), Instruction{"nan", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'nancode'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(47u, 2u), Instruction{"nextafter", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(48u, 2u), Instruction{"pow", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(49u, 2u), Instruction{"pown", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(50u, 2u), Instruction{"powr", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(51u, 2u), Instruction{"remainder", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(52u, 2u), Instruction{"remquo", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'quo'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(53u, 2u), Instruction{"rint", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(54u, 2u), Instruction{"rootn", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(55u, 2u), Instruction{"round", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(56u, 2u), Instruction{"rsqrt", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(57u, 2u), Instruction{"sin", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(58u, 2u), Instruction{"sincos", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'cosval'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(59u, 2u), Instruction{"sinh", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(60u, 2u), Instruction{"sinpi", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(61u, 2u), Instruction{"sqrt", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(62u, 2u), Instruction{"tan", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(63u, 2u), Instruction{"tanh", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(64u, 2u), Instruction{"tanpi", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(65u, 2u), Instruction{"tgamma", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(66u, 2u), Instruction{"trunc", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(67u, 2u), Instruction{"half_cos", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(68u, 2u), Instruction{"half_divide", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(69u, 2u), Instruction{"half_exp", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(70u, 2u), Instruction{"half_exp2", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(71u, 2u), Instruction{"half_exp10", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(72u, 2u), Instruction{"half_log", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(73u, 2u), Instruction{"half_log2", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(74u, 2u), Instruction{"half_log10", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(75u, 2u), Instruction{"half_powr", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(76u, 2u), Instruction{"half_recip", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(77u, 2u), Instruction{"half_rsqrt", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(78u, 2u), Instruction{"half_sin", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(79u, 2u), Instruction{"half_sqrt", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(80u, 2u), Instruction{"half_tan", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(81u, 2u), Instruction{"native_cos", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(82u, 2u), Instruction{"native_divide", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(83u, 2u), Instruction{"native_exp", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(84u, 2u), Instruction{"native_exp2", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(85u, 2u), Instruction{"native_exp10", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(86u, 2u), Instruction{"native_log", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(87u, 2u), Instruction{"native_log2", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(88u, 2u), Instruction{"native_log10", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(89u, 2u), Instruction{"native_powr", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(90u, 2u), Instruction{"native_recip", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(91u, 2u), Instruction{"native_rsqrt", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(92u, 2u), Instruction{"native_sin", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(93u, 2u), Instruction{"native_sqrt", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(94u, 2u), Instruction{"native_tan", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(141u, 2u), Instruction{"s_abs", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(142u, 2u), Instruction{"s_abs_diff", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(143u, 2u), Instruction{"s_add_sat", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(144u, 2u), Instruction{"u_add_sat", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(145u, 2u), Instruction{"s_hadd", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(146u, 2u), Instruction{"u_hadd", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(147u, 2u), Instruction{"s_rhadd", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(148u, 2u), Instruction{"u_rhadd", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(149u, 2u), Instruction{"s_clamp", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minval'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxval'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(150u, 2u), Instruction{"u_clamp", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minval'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxval'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(151u, 2u), Instruction{"clz", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(152u, 2u), Instruction{"ctz", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(153u, 2u), Instruction{"s_mad_hi", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(154u, 2u), Instruction{"u_mad_sat", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'z'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(155u, 2u), Instruction{"s_mad_sat", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'z'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(156u, 2u), Instruction{"s_max", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(157u, 2u), Instruction{"u_max", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(158u, 2u), Instruction{"s_min", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(159u, 2u), Instruction{"u_min", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(160u, 2u), Instruction{"s_mul_hi", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(161u, 2u), Instruction{"rotate", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'i'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(162u, 2u), Instruction{"s_sub_sat", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(163u, 2u), Instruction{"u_sub_sat", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(164u, 2u), Instruction{"u_upsample", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'hi'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'lo'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(165u, 2u), Instruction{"s_upsample", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'hi'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'lo'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(166u, 2u), Instruction{"popcount", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(167u, 2u), Instruction{"s_mad24", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'z'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(168u, 2u), Instruction{"u_mad24", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'z'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(169u, 2u), Instruction{"s_mul24", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(170u, 2u), Instruction{"u_mul24", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(201u, 2u), Instruction{"u_abs", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(202u, 2u), Instruction{"u_abs_diff", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(203u, 2u), Instruction{"u_mul_hi", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(204u, 2u), Instruction{"u_mad_hi", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(95u, 2u), Instruction{"fclamp", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minval'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxval'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(96u, 2u), Instruction{"degrees", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'radians'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(97u, 2u), Instruction{"fmax_common", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(98u, 2u), Instruction{"fmin_common", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(99u, 2u), Instruction{"mix", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(100u, 2u), Instruction{"radians", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'degrees'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(101u, 2u), Instruction{"step", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(102u, 2u), Instruction{"smoothstep", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge0'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge1'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(103u, 2u), Instruction{"sign", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(104u, 2u), Instruction{"cross", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p0'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p1'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(105u, 2u), Instruction{"distance", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p0'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p1'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(106u, 2u), Instruction{"length", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(107u, 2u), Instruction{"normalize", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(108u, 2u), Instruction{"fast_distance", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p0'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p1'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(109u, 2u), Instruction{"fast_length", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(110u, 2u), Instruction{"fast_normalize", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(186u, 2u), Instruction{"bitselect", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(187u, 2u), Instruction{"select", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(171u, 2u), Instruction{"vloadn", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'n'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(172u, 2u), Instruction{"vstoren", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(173u, 2u), Instruction{"vload_half", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(174u, 2u), Instruction{"vload_halfn", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'n'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(175u, 2u), Instruction{"vstore_half", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(176u, 2u), Instruction{"vstore_half_r", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::FPRoundingMode, OperandCategory::ValueEnum, "'mode'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(177u, 2u), Instruction{"vstore_halfn", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(178u, 2u), Instruction{"vstore_halfn_r", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::FPRoundingMode, OperandCategory::ValueEnum, "'mode'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(179u, 2u), Instruction{"vloada_halfn", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'n'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(180u, 2u), Instruction{"vstorea_halfn", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(181u, 2u), Instruction{"vstorea_halfn_r", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(4u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::FPRoundingMode, OperandCategory::ValueEnum, "'mode'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(182u, 2u), Instruction{"shuffle", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'shuffle mask'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(183u, 2u), Instruction{"shuffle2", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(3u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'shuffle mask'", Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(184u, 2u), Instruction{"printf", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'format'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'additional arguments'", Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(185u, 2u), Instruction{"prefetch", _pAllocator, _pAllocator, _pAllocator, 0u}).kv.value;
		instr.operands.reserve(2u);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ptr'", Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'num elements'", Quantifier::One);
	}
	m_operandNames.emplaceUnique(Hash64(0u, 0x0000u), "None");
	m_operandNames.emplaceUnique(Hash64(0u, 0x0001u), "Bias");
	m_operandNames.emplaceUnique(Hash64(0u, 0x0002u), "Lod");
	m_operandNames.emplaceUnique(Hash64(0u, 0x0004u), "Grad");
	m_operandNames.emplaceUnique(Hash64(0u, 0x0008u), "ConstOffset");
	m_operandNames.emplaceUnique(Hash64(0u, 0x0010u), "Offset");
	m_operandNames.emplaceUnique(Hash64(0u, 0x0020u), "ConstOffsets");
	m_operandNames.emplaceUnique(Hash64(0u, 0x0040u), "Sample");
	m_operandNames.emplaceUnique(Hash64(0u, 0x0080u), "MinLod");
	m_operandNames.emplaceUnique(Hash64(0u, 0x0100u), "MakeTexelAvailable");
	m_operandNames.emplaceUnique(Hash64(0u, 0x0100u), "MakeTexelAvailableKHR");
	m_operandNames.emplaceUnique(Hash64(0u, 0x0200u), "MakeTexelVisible");
	m_operandNames.emplaceUnique(Hash64(0u, 0x0200u), "MakeTexelVisibleKHR");
	m_operandNames.emplaceUnique(Hash64(0u, 0x0400u), "NonPrivateTexel");
	m_operandNames.emplaceUnique(Hash64(0u, 0x0400u), "NonPrivateTexelKHR");
	m_operandNames.emplaceUnique(Hash64(0u, 0x0800u), "VolatileTexel");
	m_operandNames.emplaceUnique(Hash64(0u, 0x0800u), "VolatileTexelKHR");
	m_operandNames.emplaceUnique(Hash64(0u, 0x1000u), "SignExtend");
	m_operandNames.emplaceUnique(Hash64(0u, 0x2000u), "ZeroExtend");
	m_operandNames.emplaceUnique(Hash64(1u, 0x0000u), "None");
	m_operandNames.emplaceUnique(Hash64(1u, 0x0001u), "NotNaN");
	m_operandNames.emplaceUnique(Hash64(1u, 0x0002u), "NotInf");
	m_operandNames.emplaceUnique(Hash64(1u, 0x0004u), "NSZ");
	m_operandNames.emplaceUnique(Hash64(1u, 0x0008u), "AllowRecip");
	m_operandNames.emplaceUnique(Hash64(1u, 0x0010u), "Fast");
	m_operandNames.emplaceUnique(Hash64(1u, 0x10000u), "AllowContractFastINTEL");
	m_operandNames.emplaceUnique(Hash64(1u, 0x20000u), "AllowReassocINTEL");
	m_operandNames.emplaceUnique(Hash64(2u, 0x0000u), "None");
	m_operandNames.emplaceUnique(Hash64(2u, 0x0001u), "Flatten");
	m_operandNames.emplaceUnique(Hash64(2u, 0x0002u), "DontFlatten");
	m_operandNames.emplaceUnique(Hash64(3u, 0x0000u), "None");
	m_operandNames.emplaceUnique(Hash64(3u, 0x0001u), "Unroll");
	m_operandNames.emplaceUnique(Hash64(3u, 0x0002u), "DontUnroll");
	m_operandNames.emplaceUnique(Hash64(3u, 0x0004u), "DependencyInfinite");
	m_operandNames.emplaceUnique(Hash64(3u, 0x0008u), "DependencyLength");
	m_operandNames.emplaceUnique(Hash64(3u, 0x0010u), "MinIterations");
	m_operandNames.emplaceUnique(Hash64(3u, 0x0020u), "MaxIterations");
	m_operandNames.emplaceUnique(Hash64(3u, 0x0040u), "IterationMultiple");
	m_operandNames.emplaceUnique(Hash64(3u, 0x0080u), "PeelCount");
	m_operandNames.emplaceUnique(Hash64(3u, 0x0100u), "PartialCount");
	m_operandNames.emplaceUnique(Hash64(3u, 0x10000u), "InitiationIntervalINTEL");
	m_operandNames.emplaceUnique(Hash64(3u, 0x20000u), "MaxConcurrencyINTEL");
	m_operandNames.emplaceUnique(Hash64(3u, 0x40000u), "DependencyArrayINTEL");
	m_operandNames.emplaceUnique(Hash64(3u, 0x80000u), "PipelineEnableINTEL");
	m_operandNames.emplaceUnique(Hash64(3u, 0x100000u), "LoopCoalesceINTEL");
	m_operandNames.emplaceUnique(Hash64(3u, 0x200000u), "MaxInterleavingINTEL");
	m_operandNames.emplaceUnique(Hash64(3u, 0x400000u), "SpeculatedIterationsINTEL");
	m_operandNames.emplaceUnique(Hash64(3u, 0x800000u), "NoFusionINTEL");
	m_operandNames.emplaceUnique(Hash64(4u, 0x0000u), "None");
	m_operandNames.emplaceUnique(Hash64(4u, 0x0001u), "Inline");
	m_operandNames.emplaceUnique(Hash64(4u, 0x0002u), "DontInline");
	m_operandNames.emplaceUnique(Hash64(4u, 0x0004u), "Pure");
	m_operandNames.emplaceUnique(Hash64(4u, 0x0008u), "Const");
	m_operandNames.emplaceUnique(Hash64(5u, 0x0000u), "Relaxed");
	m_operandNames.emplaceUnique(Hash64(5u, 0x0000u), "None");
	m_operandNames.emplaceUnique(Hash64(5u, 0x0002u), "Acquire");
	m_operandNames.emplaceUnique(Hash64(5u, 0x0004u), "Release");
	m_operandNames.emplaceUnique(Hash64(5u, 0x0008u), "AcquireRelease");
	m_operandNames.emplaceUnique(Hash64(5u, 0x0010u), "SequentiallyConsistent");
	m_operandNames.emplaceUnique(Hash64(5u, 0x0040u), "UniformMemory");
	m_operandNames.emplaceUnique(Hash64(5u, 0x0080u), "SubgroupMemory");
	m_operandNames.emplaceUnique(Hash64(5u, 0x0100u), "WorkgroupMemory");
	m_operandNames.emplaceUnique(Hash64(5u, 0x0200u), "CrossWorkgroupMemory");
	m_operandNames.emplaceUnique(Hash64(5u, 0x0400u), "AtomicCounterMemory");
	m_operandNames.emplaceUnique(Hash64(5u, 0x0800u), "ImageMemory");
	m_operandNames.emplaceUnique(Hash64(5u, 0x1000u), "OutputMemory");
	m_operandNames.emplaceUnique(Hash64(5u, 0x1000u), "OutputMemoryKHR");
	m_operandNames.emplaceUnique(Hash64(5u, 0x2000u), "MakeAvailable");
	m_operandNames.emplaceUnique(Hash64(5u, 0x2000u), "MakeAvailableKHR");
	m_operandNames.emplaceUnique(Hash64(5u, 0x4000u), "MakeVisible");
	m_operandNames.emplaceUnique(Hash64(5u, 0x4000u), "MakeVisibleKHR");
	m_operandNames.emplaceUnique(Hash64(5u, 0x8000u), "Volatile");
	m_operandNames.emplaceUnique(Hash64(6u, 0x0000u), "None");
	m_operandNames.emplaceUnique(Hash64(6u, 0x0001u), "Volatile");
	m_operandNames.emplaceUnique(Hash64(6u, 0x0002u), "Aligned");
	m_operandNames.emplaceUnique(Hash64(6u, 0x0004u), "Nontemporal");
	m_operandNames.emplaceUnique(Hash64(6u, 0x0008u), "MakePointerAvailable");
	m_operandNames.emplaceUnique(Hash64(6u, 0x0008u), "MakePointerAvailableKHR");
	m_operandNames.emplaceUnique(Hash64(6u, 0x0010u), "MakePointerVisible");
	m_operandNames.emplaceUnique(Hash64(6u, 0x0010u), "MakePointerVisibleKHR");
	m_operandNames.emplaceUnique(Hash64(6u, 0x0020u), "NonPrivatePointer");
	m_operandNames.emplaceUnique(Hash64(6u, 0x0020u), "NonPrivatePointerKHR");
	m_operandNames.emplaceUnique(Hash64(7u, 0x0000u), "None");
	m_operandNames.emplaceUnique(Hash64(7u, 0x0001u), "CmdExecTime");
	m_operandNames.emplaceUnique(Hash64(8u, 0x0000u), "NoneKHR");
	m_operandNames.emplaceUnique(Hash64(8u, 0x0001u), "OpaqueKHR");
	m_operandNames.emplaceUnique(Hash64(8u, 0x0002u), "NoOpaqueKHR");
	m_operandNames.emplaceUnique(Hash64(8u, 0x0004u), "TerminateOnFirstHitKHR");
	m_operandNames.emplaceUnique(Hash64(8u, 0x0008u), "SkipClosestHitShaderKHR");
	m_operandNames.emplaceUnique(Hash64(8u, 0x0010u), "CullBackFacingTrianglesKHR");
	m_operandNames.emplaceUnique(Hash64(8u, 0x0020u), "CullFrontFacingTrianglesKHR");
	m_operandNames.emplaceUnique(Hash64(8u, 0x0040u), "CullOpaqueKHR");
	m_operandNames.emplaceUnique(Hash64(8u, 0x0080u), "CullNoOpaqueKHR");
	m_operandNames.emplaceUnique(Hash64(8u, 0x0100u), "SkipTrianglesKHR");
	m_operandNames.emplaceUnique(Hash64(8u, 0x0200u), "SkipAABBsKHR");
	m_operandNames.emplaceUnique(Hash64(9u, 0x0001u), "Vertical2Pixels");
	m_operandNames.emplaceUnique(Hash64(9u, 0x0002u), "Vertical4Pixels");
	m_operandNames.emplaceUnique(Hash64(9u, 0x0004u), "Horizontal2Pixels");
	m_operandNames.emplaceUnique(Hash64(9u, 0x0008u), "Horizontal4Pixels");
	m_operandNames.emplaceUnique(Hash64(10u, 0u), "Unknown");
	m_operandNames.emplaceUnique(Hash64(10u, 1u), "ESSL");
	m_operandNames.emplaceUnique(Hash64(10u, 2u), "GLSL");
	m_operandNames.emplaceUnique(Hash64(10u, 3u), "OpenCL_C");
	m_operandNames.emplaceUnique(Hash64(10u, 4u), "OpenCL_CPP");
	m_operandNames.emplaceUnique(Hash64(10u, 5u), "HLSL");
	m_operandNames.emplaceUnique(Hash64(11u, 0u), "Vertex");
	m_operandNames.emplaceUnique(Hash64(11u, 1u), "TessellationControl");
	m_operandNames.emplaceUnique(Hash64(11u, 2u), "TessellationEvaluation");
	m_operandNames.emplaceUnique(Hash64(11u, 3u), "Geometry");
	m_operandNames.emplaceUnique(Hash64(11u, 4u), "Fragment");
	m_operandNames.emplaceUnique(Hash64(11u, 5u), "GLCompute");
	m_operandNames.emplaceUnique(Hash64(11u, 6u), "Kernel");
	m_operandNames.emplaceUnique(Hash64(11u, 5267u), "TaskNV");
	m_operandNames.emplaceUnique(Hash64(11u, 5268u), "MeshNV");
	m_operandNames.emplaceUnique(Hash64(11u, 5313u), "RayGenerationNV");
	m_operandNames.emplaceUnique(Hash64(11u, 5313u), "RayGenerationKHR");
	m_operandNames.emplaceUnique(Hash64(11u, 5314u), "IntersectionNV");
	m_operandNames.emplaceUnique(Hash64(11u, 5314u), "IntersectionKHR");
	m_operandNames.emplaceUnique(Hash64(11u, 5315u), "AnyHitNV");
	m_operandNames.emplaceUnique(Hash64(11u, 5315u), "AnyHitKHR");
	m_operandNames.emplaceUnique(Hash64(11u, 5316u), "ClosestHitNV");
	m_operandNames.emplaceUnique(Hash64(11u, 5316u), "ClosestHitKHR");
	m_operandNames.emplaceUnique(Hash64(11u, 5317u), "MissNV");
	m_operandNames.emplaceUnique(Hash64(11u, 5317u), "MissKHR");
	m_operandNames.emplaceUnique(Hash64(11u, 5318u), "CallableNV");
	m_operandNames.emplaceUnique(Hash64(11u, 5318u), "CallableKHR");
	m_operandNames.emplaceUnique(Hash64(12u, 0u), "Logical");
	m_operandNames.emplaceUnique(Hash64(12u, 1u), "Physical32");
	m_operandNames.emplaceUnique(Hash64(12u, 2u), "Physical64");
	m_operandNames.emplaceUnique(Hash64(12u, 5348u), "PhysicalStorageBuffer64");
	m_operandNames.emplaceUnique(Hash64(12u, 5348u), "PhysicalStorageBuffer64EXT");
	m_operandNames.emplaceUnique(Hash64(13u, 0u), "Simple");
	m_operandNames.emplaceUnique(Hash64(13u, 1u), "GLSL450");
	m_operandNames.emplaceUnique(Hash64(13u, 2u), "OpenCL");
	m_operandNames.emplaceUnique(Hash64(13u, 3u), "Vulkan");
	m_operandNames.emplaceUnique(Hash64(13u, 3u), "VulkanKHR");
	m_operandNames.emplaceUnique(Hash64(14u, 0u), "Invocations");
	m_operandNames.emplaceUnique(Hash64(14u, 1u), "SpacingEqual");
	m_operandNames.emplaceUnique(Hash64(14u, 2u), "SpacingFractionalEven");
	m_operandNames.emplaceUnique(Hash64(14u, 3u), "SpacingFractionalOdd");
	m_operandNames.emplaceUnique(Hash64(14u, 4u), "VertexOrderCw");
	m_operandNames.emplaceUnique(Hash64(14u, 5u), "VertexOrderCcw");
	m_operandNames.emplaceUnique(Hash64(14u, 6u), "PixelCenterInteger");
	m_operandNames.emplaceUnique(Hash64(14u, 7u), "OriginUpperLeft");
	m_operandNames.emplaceUnique(Hash64(14u, 8u), "OriginLowerLeft");
	m_operandNames.emplaceUnique(Hash64(14u, 9u), "EarlyFragmentTests");
	m_operandNames.emplaceUnique(Hash64(14u, 10u), "PointMode");
	m_operandNames.emplaceUnique(Hash64(14u, 11u), "Xfb");
	m_operandNames.emplaceUnique(Hash64(14u, 12u), "DepthReplacing");
	m_operandNames.emplaceUnique(Hash64(14u, 14u), "DepthGreater");
	m_operandNames.emplaceUnique(Hash64(14u, 15u), "DepthLess");
	m_operandNames.emplaceUnique(Hash64(14u, 16u), "DepthUnchanged");
	m_operandNames.emplaceUnique(Hash64(14u, 17u), "LocalSize");
	m_operandNames.emplaceUnique(Hash64(14u, 18u), "LocalSizeHint");
	m_operandNames.emplaceUnique(Hash64(14u, 19u), "InputPoints");
	m_operandNames.emplaceUnique(Hash64(14u, 20u), "InputLines");
	m_operandNames.emplaceUnique(Hash64(14u, 21u), "InputLinesAdjacency");
	m_operandNames.emplaceUnique(Hash64(14u, 22u), "Triangles");
	m_operandNames.emplaceUnique(Hash64(14u, 23u), "InputTrianglesAdjacency");
	m_operandNames.emplaceUnique(Hash64(14u, 24u), "Quads");
	m_operandNames.emplaceUnique(Hash64(14u, 25u), "Isolines");
	m_operandNames.emplaceUnique(Hash64(14u, 26u), "OutputVertices");
	m_operandNames.emplaceUnique(Hash64(14u, 27u), "OutputPoints");
	m_operandNames.emplaceUnique(Hash64(14u, 28u), "OutputLineStrip");
	m_operandNames.emplaceUnique(Hash64(14u, 29u), "OutputTriangleStrip");
	m_operandNames.emplaceUnique(Hash64(14u, 30u), "VecTypeHint");
	m_operandNames.emplaceUnique(Hash64(14u, 31u), "ContractionOff");
	m_operandNames.emplaceUnique(Hash64(14u, 33u), "Initializer");
	m_operandNames.emplaceUnique(Hash64(14u, 34u), "Finalizer");
	m_operandNames.emplaceUnique(Hash64(14u, 35u), "SubgroupSize");
	m_operandNames.emplaceUnique(Hash64(14u, 36u), "SubgroupsPerWorkgroup");
	m_operandNames.emplaceUnique(Hash64(14u, 37u), "SubgroupsPerWorkgroupId");
	m_operandNames.emplaceUnique(Hash64(14u, 38u), "LocalSizeId");
	m_operandNames.emplaceUnique(Hash64(14u, 39u), "LocalSizeHintId");
	m_operandNames.emplaceUnique(Hash64(14u, 4446u), "PostDepthCoverage");
	m_operandNames.emplaceUnique(Hash64(14u, 4459u), "DenormPreserve");
	m_operandNames.emplaceUnique(Hash64(14u, 4460u), "DenormFlushToZero");
	m_operandNames.emplaceUnique(Hash64(14u, 4461u), "SignedZeroInfNanPreserve");
	m_operandNames.emplaceUnique(Hash64(14u, 4462u), "RoundingModeRTE");
	m_operandNames.emplaceUnique(Hash64(14u, 4463u), "RoundingModeRTZ");
	m_operandNames.emplaceUnique(Hash64(14u, 5027u), "StencilRefReplacingEXT");
	m_operandNames.emplaceUnique(Hash64(14u, 5269u), "OutputLinesNV");
	m_operandNames.emplaceUnique(Hash64(14u, 5270u), "OutputPrimitivesNV");
	m_operandNames.emplaceUnique(Hash64(14u, 5289u), "DerivativeGroupQuadsNV");
	m_operandNames.emplaceUnique(Hash64(14u, 5290u), "DerivativeGroupLinearNV");
	m_operandNames.emplaceUnique(Hash64(14u, 5298u), "OutputTrianglesNV");
	m_operandNames.emplaceUnique(Hash64(14u, 5366u), "PixelInterlockOrderedEXT");
	m_operandNames.emplaceUnique(Hash64(14u, 5367u), "PixelInterlockUnorderedEXT");
	m_operandNames.emplaceUnique(Hash64(14u, 5368u), "SampleInterlockOrderedEXT");
	m_operandNames.emplaceUnique(Hash64(14u, 5369u), "SampleInterlockUnorderedEXT");
	m_operandNames.emplaceUnique(Hash64(14u, 5370u), "ShadingRateInterlockOrderedEXT");
	m_operandNames.emplaceUnique(Hash64(14u, 5371u), "ShadingRateInterlockUnorderedEXT");
	m_operandNames.emplaceUnique(Hash64(14u, 5618u), "SharedLocalMemorySizeINTEL");
	m_operandNames.emplaceUnique(Hash64(14u, 5620u), "RoundingModeRTPINTEL");
	m_operandNames.emplaceUnique(Hash64(14u, 5621u), "RoundingModeRTNINTEL");
	m_operandNames.emplaceUnique(Hash64(14u, 5622u), "FloatingPointModeALTINTEL");
	m_operandNames.emplaceUnique(Hash64(14u, 5623u), "FloatingPointModeIEEEINTEL");
	m_operandNames.emplaceUnique(Hash64(14u, 5893u), "MaxWorkgroupSizeINTEL");
	m_operandNames.emplaceUnique(Hash64(14u, 5894u), "MaxWorkDimINTEL");
	m_operandNames.emplaceUnique(Hash64(14u, 5895u), "NoGlobalOffsetINTEL");
	m_operandNames.emplaceUnique(Hash64(14u, 5896u), "NumSIMDWorkitemsINTEL");
	m_operandNames.emplaceUnique(Hash64(14u, 5903u), "SchedulerTargetFmaxMhzINTEL");
	m_operandNames.emplaceUnique(Hash64(15u, 0u), "UniformConstant");
	m_operandNames.emplaceUnique(Hash64(15u, 1u), "Input");
	m_operandNames.emplaceUnique(Hash64(15u, 2u), "Uniform");
	m_operandNames.emplaceUnique(Hash64(15u, 3u), "Output");
	m_operandNames.emplaceUnique(Hash64(15u, 4u), "Workgroup");
	m_operandNames.emplaceUnique(Hash64(15u, 5u), "CrossWorkgroup");
	m_operandNames.emplaceUnique(Hash64(15u, 6u), "Private");
	m_operandNames.emplaceUnique(Hash64(15u, 7u), "Function");
	m_operandNames.emplaceUnique(Hash64(15u, 8u), "Generic");
	m_operandNames.emplaceUnique(Hash64(15u, 9u), "PushConstant");
	m_operandNames.emplaceUnique(Hash64(15u, 10u), "AtomicCounter");
	m_operandNames.emplaceUnique(Hash64(15u, 11u), "Image");
	m_operandNames.emplaceUnique(Hash64(15u, 12u), "StorageBuffer");
	m_operandNames.emplaceUnique(Hash64(15u, 5328u), "CallableDataNV");
	m_operandNames.emplaceUnique(Hash64(15u, 5328u), "CallableDataKHR");
	m_operandNames.emplaceUnique(Hash64(15u, 5329u), "IncomingCallableDataNV");
	m_operandNames.emplaceUnique(Hash64(15u, 5329u), "IncomingCallableDataKHR");
	m_operandNames.emplaceUnique(Hash64(15u, 5338u), "RayPayloadNV");
	m_operandNames.emplaceUnique(Hash64(15u, 5338u), "RayPayloadKHR");
	m_operandNames.emplaceUnique(Hash64(15u, 5339u), "HitAttributeNV");
	m_operandNames.emplaceUnique(Hash64(15u, 5339u), "HitAttributeKHR");
	m_operandNames.emplaceUnique(Hash64(15u, 5342u), "IncomingRayPayloadNV");
	m_operandNames.emplaceUnique(Hash64(15u, 5342u), "IncomingRayPayloadKHR");
	m_operandNames.emplaceUnique(Hash64(15u, 5343u), "ShaderRecordBufferNV");
	m_operandNames.emplaceUnique(Hash64(15u, 5343u), "ShaderRecordBufferKHR");
	m_operandNames.emplaceUnique(Hash64(15u, 5349u), "PhysicalStorageBuffer");
	m_operandNames.emplaceUnique(Hash64(15u, 5349u), "PhysicalStorageBufferEXT");
	m_operandNames.emplaceUnique(Hash64(15u, 5605u), "CodeSectionINTEL");
	m_operandNames.emplaceUnique(Hash64(15u, 5936u), "DeviceOnlyINTEL");
	m_operandNames.emplaceUnique(Hash64(15u, 5937u), "HostOnlyINTEL");
	m_operandNames.emplaceUnique(Hash64(16u, 0u), "Dim1D");
	m_operandNames.emplaceUnique(Hash64(16u, 1u), "Dim2D");
	m_operandNames.emplaceUnique(Hash64(16u, 2u), "Dim3D");
	m_operandNames.emplaceUnique(Hash64(16u, 3u), "Cube");
	m_operandNames.emplaceUnique(Hash64(16u, 4u), "Rect");
	m_operandNames.emplaceUnique(Hash64(16u, 5u), "Buffer");
	m_operandNames.emplaceUnique(Hash64(16u, 6u), "SubpassData");
	m_operandNames.emplaceUnique(Hash64(17u, 0u), "None");
	m_operandNames.emplaceUnique(Hash64(17u, 1u), "ClampToEdge");
	m_operandNames.emplaceUnique(Hash64(17u, 2u), "Clamp");
	m_operandNames.emplaceUnique(Hash64(17u, 3u), "Repeat");
	m_operandNames.emplaceUnique(Hash64(17u, 4u), "RepeatMirrored");
	m_operandNames.emplaceUnique(Hash64(18u, 0u), "Nearest");
	m_operandNames.emplaceUnique(Hash64(18u, 1u), "Linear");
	m_operandNames.emplaceUnique(Hash64(19u, 0u), "Unknown");
	m_operandNames.emplaceUnique(Hash64(19u, 1u), "Rgba32f");
	m_operandNames.emplaceUnique(Hash64(19u, 2u), "Rgba16f");
	m_operandNames.emplaceUnique(Hash64(19u, 3u), "R32f");
	m_operandNames.emplaceUnique(Hash64(19u, 4u), "Rgba8");
	m_operandNames.emplaceUnique(Hash64(19u, 5u), "Rgba8Snorm");
	m_operandNames.emplaceUnique(Hash64(19u, 6u), "Rg32f");
	m_operandNames.emplaceUnique(Hash64(19u, 7u), "Rg16f");
	m_operandNames.emplaceUnique(Hash64(19u, 8u), "R11fG11fB10f");
	m_operandNames.emplaceUnique(Hash64(19u, 9u), "R16f");
	m_operandNames.emplaceUnique(Hash64(19u, 10u), "Rgba16");
	m_operandNames.emplaceUnique(Hash64(19u, 11u), "Rgb10A2");
	m_operandNames.emplaceUnique(Hash64(19u, 12u), "Rg16");
	m_operandNames.emplaceUnique(Hash64(19u, 13u), "Rg8");
	m_operandNames.emplaceUnique(Hash64(19u, 14u), "R16");
	m_operandNames.emplaceUnique(Hash64(19u, 15u), "R8");
	m_operandNames.emplaceUnique(Hash64(19u, 16u), "Rgba16Snorm");
	m_operandNames.emplaceUnique(Hash64(19u, 17u), "Rg16Snorm");
	m_operandNames.emplaceUnique(Hash64(19u, 18u), "Rg8Snorm");
	m_operandNames.emplaceUnique(Hash64(19u, 19u), "R16Snorm");
	m_operandNames.emplaceUnique(Hash64(19u, 20u), "R8Snorm");
	m_operandNames.emplaceUnique(Hash64(19u, 21u), "Rgba32i");
	m_operandNames.emplaceUnique(Hash64(19u, 22u), "Rgba16i");
	m_operandNames.emplaceUnique(Hash64(19u, 23u), "Rgba8i");
	m_operandNames.emplaceUnique(Hash64(19u, 24u), "R32i");
	m_operandNames.emplaceUnique(Hash64(19u, 25u), "Rg32i");
	m_operandNames.emplaceUnique(Hash64(19u, 26u), "Rg16i");
	m_operandNames.emplaceUnique(Hash64(19u, 27u), "Rg8i");
	m_operandNames.emplaceUnique(Hash64(19u, 28u), "R16i");
	m_operandNames.emplaceUnique(Hash64(19u, 29u), "R8i");
	m_operandNames.emplaceUnique(Hash64(19u, 30u), "Rgba32ui");
	m_operandNames.emplaceUnique(Hash64(19u, 31u), "Rgba16ui");
	m_operandNames.emplaceUnique(Hash64(19u, 32u), "Rgba8ui");
	m_operandNames.emplaceUnique(Hash64(19u, 33u), "R32ui");
	m_operandNames.emplaceUnique(Hash64(19u, 34u), "Rgb10a2ui");
	m_operandNames.emplaceUnique(Hash64(19u, 35u), "Rg32ui");
	m_operandNames.emplaceUnique(Hash64(19u, 36u), "Rg16ui");
	m_operandNames.emplaceUnique(Hash64(19u, 37u), "Rg8ui");
	m_operandNames.emplaceUnique(Hash64(19u, 38u), "R16ui");
	m_operandNames.emplaceUnique(Hash64(19u, 39u), "R8ui");
	m_operandNames.emplaceUnique(Hash64(19u, 40u), "R64ui");
	m_operandNames.emplaceUnique(Hash64(19u, 41u), "R64i");
	m_operandNames.emplaceUnique(Hash64(20u, 0u), "R");
	m_operandNames.emplaceUnique(Hash64(20u, 1u), "A");
	m_operandNames.emplaceUnique(Hash64(20u, 2u), "RG");
	m_operandNames.emplaceUnique(Hash64(20u, 3u), "RA");
	m_operandNames.emplaceUnique(Hash64(20u, 4u), "RGB");
	m_operandNames.emplaceUnique(Hash64(20u, 5u), "RGBA");
	m_operandNames.emplaceUnique(Hash64(20u, 6u), "BGRA");
	m_operandNames.emplaceUnique(Hash64(20u, 7u), "ARGB");
	m_operandNames.emplaceUnique(Hash64(20u, 8u), "Intensity");
	m_operandNames.emplaceUnique(Hash64(20u, 9u), "Luminance");
	m_operandNames.emplaceUnique(Hash64(20u, 10u), "Rx");
	m_operandNames.emplaceUnique(Hash64(20u, 11u), "RGx");
	m_operandNames.emplaceUnique(Hash64(20u, 12u), "RGBx");
	m_operandNames.emplaceUnique(Hash64(20u, 13u), "Depth");
	m_operandNames.emplaceUnique(Hash64(20u, 14u), "DepthStencil");
	m_operandNames.emplaceUnique(Hash64(20u, 15u), "sRGB");
	m_operandNames.emplaceUnique(Hash64(20u, 16u), "sRGBx");
	m_operandNames.emplaceUnique(Hash64(20u, 17u), "sRGBA");
	m_operandNames.emplaceUnique(Hash64(20u, 18u), "sBGRA");
	m_operandNames.emplaceUnique(Hash64(20u, 19u), "ABGR");
	m_operandNames.emplaceUnique(Hash64(21u, 0u), "SnormInt8");
	m_operandNames.emplaceUnique(Hash64(21u, 1u), "SnormInt16");
	m_operandNames.emplaceUnique(Hash64(21u, 2u), "UnormInt8");
	m_operandNames.emplaceUnique(Hash64(21u, 3u), "UnormInt16");
	m_operandNames.emplaceUnique(Hash64(21u, 4u), "UnormShort565");
	m_operandNames.emplaceUnique(Hash64(21u, 5u), "UnormShort555");
	m_operandNames.emplaceUnique(Hash64(21u, 6u), "UnormInt101010");
	m_operandNames.emplaceUnique(Hash64(21u, 7u), "SignedInt8");
	m_operandNames.emplaceUnique(Hash64(21u, 8u), "SignedInt16");
	m_operandNames.emplaceUnique(Hash64(21u, 9u), "SignedInt32");
	m_operandNames.emplaceUnique(Hash64(21u, 10u), "UnsignedInt8");
	m_operandNames.emplaceUnique(Hash64(21u, 11u), "UnsignedInt16");
	m_operandNames.emplaceUnique(Hash64(21u, 12u), "UnsignedInt32");
	m_operandNames.emplaceUnique(Hash64(21u, 13u), "HalfFloat");
	m_operandNames.emplaceUnique(Hash64(21u, 14u), "Float");
	m_operandNames.emplaceUnique(Hash64(21u, 15u), "UnormInt24");
	m_operandNames.emplaceUnique(Hash64(21u, 16u), "UnormInt101010_2");
	m_operandNames.emplaceUnique(Hash64(22u, 0u), "RTE");
	m_operandNames.emplaceUnique(Hash64(22u, 1u), "RTZ");
	m_operandNames.emplaceUnique(Hash64(22u, 2u), "RTP");
	m_operandNames.emplaceUnique(Hash64(22u, 3u), "RTN");
	m_operandNames.emplaceUnique(Hash64(23u, 0u), "Preserve");
	m_operandNames.emplaceUnique(Hash64(23u, 1u), "FlushToZero");
	m_operandNames.emplaceUnique(Hash64(24u, 0u), "IEEE");
	m_operandNames.emplaceUnique(Hash64(24u, 1u), "ALT");
	m_operandNames.emplaceUnique(Hash64(25u, 0u), "Export");
	m_operandNames.emplaceUnique(Hash64(25u, 1u), "Import");
	m_operandNames.emplaceUnique(Hash64(26u, 0u), "ReadOnly");
	m_operandNames.emplaceUnique(Hash64(26u, 1u), "WriteOnly");
	m_operandNames.emplaceUnique(Hash64(26u, 2u), "ReadWrite");
	m_operandNames.emplaceUnique(Hash64(27u, 0u), "Zext");
	m_operandNames.emplaceUnique(Hash64(27u, 1u), "Sext");
	m_operandNames.emplaceUnique(Hash64(27u, 2u), "ByVal");
	m_operandNames.emplaceUnique(Hash64(27u, 3u), "Sret");
	m_operandNames.emplaceUnique(Hash64(27u, 4u), "NoAlias");
	m_operandNames.emplaceUnique(Hash64(27u, 5u), "NoCapture");
	m_operandNames.emplaceUnique(Hash64(27u, 6u), "NoWrite");
	m_operandNames.emplaceUnique(Hash64(27u, 7u), "NoReadWrite");
	m_operandNames.emplaceUnique(Hash64(28u, 0u), "RelaxedPrecision");
	m_operandNames.emplaceUnique(Hash64(28u, 1u), "SpecId");
	m_operandNames.emplaceUnique(Hash64(28u, 2u), "Block");
	m_operandNames.emplaceUnique(Hash64(28u, 3u), "BufferBlock");
	m_operandNames.emplaceUnique(Hash64(28u, 4u), "RowMajor");
	m_operandNames.emplaceUnique(Hash64(28u, 5u), "ColMajor");
	m_operandNames.emplaceUnique(Hash64(28u, 6u), "ArrayStride");
	m_operandNames.emplaceUnique(Hash64(28u, 7u), "MatrixStride");
	m_operandNames.emplaceUnique(Hash64(28u, 8u), "GLSLShared");
	m_operandNames.emplaceUnique(Hash64(28u, 9u), "GLSLPacked");
	m_operandNames.emplaceUnique(Hash64(28u, 10u), "CPacked");
	m_operandNames.emplaceUnique(Hash64(28u, 11u), "BuiltIn");
	m_operandNames.emplaceUnique(Hash64(28u, 13u), "NoPerspective");
	m_operandNames.emplaceUnique(Hash64(28u, 14u), "Flat");
	m_operandNames.emplaceUnique(Hash64(28u, 15u), "Patch");
	m_operandNames.emplaceUnique(Hash64(28u, 16u), "Centroid");
	m_operandNames.emplaceUnique(Hash64(28u, 17u), "Sample");
	m_operandNames.emplaceUnique(Hash64(28u, 18u), "Invariant");
	m_operandNames.emplaceUnique(Hash64(28u, 19u), "Restrict");
	m_operandNames.emplaceUnique(Hash64(28u, 20u), "Aliased");
	m_operandNames.emplaceUnique(Hash64(28u, 21u), "Volatile");
	m_operandNames.emplaceUnique(Hash64(28u, 22u), "Constant");
	m_operandNames.emplaceUnique(Hash64(28u, 23u), "Coherent");
	m_operandNames.emplaceUnique(Hash64(28u, 24u), "NonWritable");
	m_operandNames.emplaceUnique(Hash64(28u, 25u), "NonReadable");
	m_operandNames.emplaceUnique(Hash64(28u, 26u), "Uniform");
	m_operandNames.emplaceUnique(Hash64(28u, 27u), "UniformId");
	m_operandNames.emplaceUnique(Hash64(28u, 28u), "SaturatedConversion");
	m_operandNames.emplaceUnique(Hash64(28u, 29u), "Stream");
	m_operandNames.emplaceUnique(Hash64(28u, 30u), "Location");
	m_operandNames.emplaceUnique(Hash64(28u, 31u), "Component");
	m_operandNames.emplaceUnique(Hash64(28u, 32u), "Index");
	m_operandNames.emplaceUnique(Hash64(28u, 33u), "Binding");
	m_operandNames.emplaceUnique(Hash64(28u, 34u), "DescriptorSet");
	m_operandNames.emplaceUnique(Hash64(28u, 35u), "Offset");
	m_operandNames.emplaceUnique(Hash64(28u, 36u), "XfbBuffer");
	m_operandNames.emplaceUnique(Hash64(28u, 37u), "XfbStride");
	m_operandNames.emplaceUnique(Hash64(28u, 38u), "FuncParamAttr");
	m_operandNames.emplaceUnique(Hash64(28u, 39u), "FPRoundingMode");
	m_operandNames.emplaceUnique(Hash64(28u, 40u), "FPFastMathMode");
	m_operandNames.emplaceUnique(Hash64(28u, 41u), "LinkageAttributes");
	m_operandNames.emplaceUnique(Hash64(28u, 42u), "NoContraction");
	m_operandNames.emplaceUnique(Hash64(28u, 43u), "InputAttachmentIndex");
	m_operandNames.emplaceUnique(Hash64(28u, 44u), "Alignment");
	m_operandNames.emplaceUnique(Hash64(28u, 45u), "MaxByteOffset");
	m_operandNames.emplaceUnique(Hash64(28u, 46u), "AlignmentId");
	m_operandNames.emplaceUnique(Hash64(28u, 47u), "MaxByteOffsetId");
	m_operandNames.emplaceUnique(Hash64(28u, 4469u), "NoSignedWrap");
	m_operandNames.emplaceUnique(Hash64(28u, 4470u), "NoUnsignedWrap");
	m_operandNames.emplaceUnique(Hash64(28u, 4999u), "ExplicitInterpAMD");
	m_operandNames.emplaceUnique(Hash64(28u, 5248u), "OverrideCoverageNV");
	m_operandNames.emplaceUnique(Hash64(28u, 5250u), "PassthroughNV");
	m_operandNames.emplaceUnique(Hash64(28u, 5252u), "ViewportRelativeNV");
	m_operandNames.emplaceUnique(Hash64(28u, 5256u), "SecondaryViewportRelativeNV");
	m_operandNames.emplaceUnique(Hash64(28u, 5271u), "PerPrimitiveNV");
	m_operandNames.emplaceUnique(Hash64(28u, 5272u), "PerViewNV");
	m_operandNames.emplaceUnique(Hash64(28u, 5273u), "PerTaskNV");
	m_operandNames.emplaceUnique(Hash64(28u, 5285u), "PerVertexNV");
	m_operandNames.emplaceUnique(Hash64(28u, 5300u), "NonUniform");
	m_operandNames.emplaceUnique(Hash64(28u, 5300u), "NonUniformEXT");
	m_operandNames.emplaceUnique(Hash64(28u, 5355u), "RestrictPointer");
	m_operandNames.emplaceUnique(Hash64(28u, 5355u), "RestrictPointerEXT");
	m_operandNames.emplaceUnique(Hash64(28u, 5356u), "AliasedPointer");
	m_operandNames.emplaceUnique(Hash64(28u, 5356u), "AliasedPointerEXT");
	m_operandNames.emplaceUnique(Hash64(28u, 5599u), "SIMTCallINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5602u), "ReferencedIndirectlyINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5607u), "ClobberINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5608u), "SideEffectsINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5624u), "VectorComputeVariableINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5625u), "FuncParamIOKindINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5626u), "VectorComputeFunctionINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5627u), "StackCallINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5628u), "GlobalVariableOffsetINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5634u), "CounterBuffer");
	m_operandNames.emplaceUnique(Hash64(28u, 5634u), "HlslCounterBufferGOOGLE");
	m_operandNames.emplaceUnique(Hash64(28u, 5635u), "UserSemantic");
	m_operandNames.emplaceUnique(Hash64(28u, 5635u), "HlslSemanticGOOGLE");
	m_operandNames.emplaceUnique(Hash64(28u, 5636u), "UserTypeGOOGLE");
	m_operandNames.emplaceUnique(Hash64(28u, 5822u), "FunctionRoundingModeINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5823u), "FunctionDenormModeINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5825u), "RegisterINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5826u), "MemoryINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5827u), "NumbanksINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5828u), "BankwidthINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5829u), "MaxPrivateCopiesINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5830u), "SinglepumpINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5831u), "DoublepumpINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5832u), "MaxReplicatesINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5833u), "SimpleDualPortINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5834u), "MergeINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5835u), "BankBitsINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5836u), "ForcePow2DepthINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5899u), "BurstCoalesceINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5900u), "CacheSizeINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5901u), "DontStaticallyCoalesceINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5902u), "PrefetchINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5905u), "StallEnableINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5907u), "FuseLoopsInFunctionINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5921u), "BufferLocationINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 5944u), "IOPipeStorageINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 6080u), "FunctionFloatingPointModeINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 6085u), "SingleElementVectorINTEL");
	m_operandNames.emplaceUnique(Hash64(28u, 6087u), "VectorComputeCallableFunctionINTEL");
	m_operandNames.emplaceUnique(Hash64(29u, 0u), "Position");
	m_operandNames.emplaceUnique(Hash64(29u, 1u), "PointSize");
	m_operandNames.emplaceUnique(Hash64(29u, 3u), "ClipDistance");
	m_operandNames.emplaceUnique(Hash64(29u, 4u), "CullDistance");
	m_operandNames.emplaceUnique(Hash64(29u, 5u), "VertexId");
	m_operandNames.emplaceUnique(Hash64(29u, 6u), "InstanceId");
	m_operandNames.emplaceUnique(Hash64(29u, 7u), "PrimitiveId");
	m_operandNames.emplaceUnique(Hash64(29u, 8u), "InvocationId");
	m_operandNames.emplaceUnique(Hash64(29u, 9u), "Layer");
	m_operandNames.emplaceUnique(Hash64(29u, 10u), "ViewportIndex");
	m_operandNames.emplaceUnique(Hash64(29u, 11u), "TessLevelOuter");
	m_operandNames.emplaceUnique(Hash64(29u, 12u), "TessLevelInner");
	m_operandNames.emplaceUnique(Hash64(29u, 13u), "TessCoord");
	m_operandNames.emplaceUnique(Hash64(29u, 14u), "PatchVertices");
	m_operandNames.emplaceUnique(Hash64(29u, 15u), "FragCoord");
	m_operandNames.emplaceUnique(Hash64(29u, 16u), "PointCoord");
	m_operandNames.emplaceUnique(Hash64(29u, 17u), "FrontFacing");
	m_operandNames.emplaceUnique(Hash64(29u, 18u), "SampleId");
	m_operandNames.emplaceUnique(Hash64(29u, 19u), "SamplePosition");
	m_operandNames.emplaceUnique(Hash64(29u, 20u), "SampleMask");
	m_operandNames.emplaceUnique(Hash64(29u, 22u), "FragDepth");
	m_operandNames.emplaceUnique(Hash64(29u, 23u), "HelperInvocation");
	m_operandNames.emplaceUnique(Hash64(29u, 24u), "NumWorkgroups");
	m_operandNames.emplaceUnique(Hash64(29u, 25u), "WorkgroupSize");
	m_operandNames.emplaceUnique(Hash64(29u, 26u), "WorkgroupId");
	m_operandNames.emplaceUnique(Hash64(29u, 27u), "LocalInvocationId");
	m_operandNames.emplaceUnique(Hash64(29u, 28u), "GlobalInvocationId");
	m_operandNames.emplaceUnique(Hash64(29u, 29u), "LocalInvocationIndex");
	m_operandNames.emplaceUnique(Hash64(29u, 30u), "WorkDim");
	m_operandNames.emplaceUnique(Hash64(29u, 31u), "GlobalSize");
	m_operandNames.emplaceUnique(Hash64(29u, 32u), "EnqueuedWorkgroupSize");
	m_operandNames.emplaceUnique(Hash64(29u, 33u), "GlobalOffset");
	m_operandNames.emplaceUnique(Hash64(29u, 34u), "GlobalLinearId");
	m_operandNames.emplaceUnique(Hash64(29u, 36u), "SubgroupSize");
	m_operandNames.emplaceUnique(Hash64(29u, 37u), "SubgroupMaxSize");
	m_operandNames.emplaceUnique(Hash64(29u, 38u), "NumSubgroups");
	m_operandNames.emplaceUnique(Hash64(29u, 39u), "NumEnqueuedSubgroups");
	m_operandNames.emplaceUnique(Hash64(29u, 40u), "SubgroupId");
	m_operandNames.emplaceUnique(Hash64(29u, 41u), "SubgroupLocalInvocationId");
	m_operandNames.emplaceUnique(Hash64(29u, 42u), "VertexIndex");
	m_operandNames.emplaceUnique(Hash64(29u, 43u), "InstanceIndex");
	m_operandNames.emplaceUnique(Hash64(29u, 4416u), "SubgroupEqMask");
	m_operandNames.emplaceUnique(Hash64(29u, 4416u), "SubgroupEqMaskKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 4417u), "SubgroupGeMask");
	m_operandNames.emplaceUnique(Hash64(29u, 4417u), "SubgroupGeMaskKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 4418u), "SubgroupGtMask");
	m_operandNames.emplaceUnique(Hash64(29u, 4418u), "SubgroupGtMaskKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 4419u), "SubgroupLeMask");
	m_operandNames.emplaceUnique(Hash64(29u, 4419u), "SubgroupLeMaskKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 4420u), "SubgroupLtMask");
	m_operandNames.emplaceUnique(Hash64(29u, 4420u), "SubgroupLtMaskKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 4424u), "BaseVertex");
	m_operandNames.emplaceUnique(Hash64(29u, 4425u), "BaseInstance");
	m_operandNames.emplaceUnique(Hash64(29u, 4426u), "DrawIndex");
	m_operandNames.emplaceUnique(Hash64(29u, 4432u), "PrimitiveShadingRateKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 4438u), "DeviceIndex");
	m_operandNames.emplaceUnique(Hash64(29u, 4440u), "ViewIndex");
	m_operandNames.emplaceUnique(Hash64(29u, 4444u), "ShadingRateKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 4992u), "BaryCoordNoPerspAMD");
	m_operandNames.emplaceUnique(Hash64(29u, 4993u), "BaryCoordNoPerspCentroidAMD");
	m_operandNames.emplaceUnique(Hash64(29u, 4994u), "BaryCoordNoPerspSampleAMD");
	m_operandNames.emplaceUnique(Hash64(29u, 4995u), "BaryCoordSmoothAMD");
	m_operandNames.emplaceUnique(Hash64(29u, 4996u), "BaryCoordSmoothCentroidAMD");
	m_operandNames.emplaceUnique(Hash64(29u, 4997u), "BaryCoordSmoothSampleAMD");
	m_operandNames.emplaceUnique(Hash64(29u, 4998u), "BaryCoordPullModelAMD");
	m_operandNames.emplaceUnique(Hash64(29u, 5014u), "FragStencilRefEXT");
	m_operandNames.emplaceUnique(Hash64(29u, 5253u), "ViewportMaskNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5257u), "SecondaryPositionNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5258u), "SecondaryViewportMaskNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5261u), "PositionPerViewNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5262u), "ViewportMaskPerViewNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5264u), "FullyCoveredEXT");
	m_operandNames.emplaceUnique(Hash64(29u, 5274u), "TaskCountNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5275u), "PrimitiveCountNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5276u), "PrimitiveIndicesNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5277u), "ClipDistancePerViewNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5278u), "CullDistancePerViewNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5279u), "LayerPerViewNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5280u), "MeshViewCountNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5281u), "MeshViewIndicesNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5286u), "BaryCoordNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5287u), "BaryCoordNoPerspNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5292u), "FragSizeEXT");
	m_operandNames.emplaceUnique(Hash64(29u, 5292u), "FragmentSizeNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5293u), "FragInvocationCountEXT");
	m_operandNames.emplaceUnique(Hash64(29u, 5293u), "InvocationsPerPixelNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5319u), "LaunchIdNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5319u), "LaunchIdKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 5320u), "LaunchSizeNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5320u), "LaunchSizeKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 5321u), "WorldRayOriginNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5321u), "WorldRayOriginKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 5322u), "WorldRayDirectionNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5322u), "WorldRayDirectionKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 5323u), "ObjectRayOriginNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5323u), "ObjectRayOriginKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 5324u), "ObjectRayDirectionNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5324u), "ObjectRayDirectionKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 5325u), "RayTminNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5325u), "RayTminKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 5326u), "RayTmaxNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5326u), "RayTmaxKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 5327u), "InstanceCustomIndexNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5327u), "InstanceCustomIndexKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 5330u), "ObjectToWorldNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5330u), "ObjectToWorldKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 5331u), "WorldToObjectNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5331u), "WorldToObjectKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 5332u), "HitTNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5333u), "HitKindNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5333u), "HitKindKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 5351u), "IncomingRayFlagsNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5351u), "IncomingRayFlagsKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 5352u), "RayGeometryIndexKHR");
	m_operandNames.emplaceUnique(Hash64(29u, 5374u), "WarpsPerSMNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5375u), "SMCountNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5376u), "WarpIDNV");
	m_operandNames.emplaceUnique(Hash64(29u, 5377u), "SMIDNV");
	m_operandNames.emplaceUnique(Hash64(30u, 0u), "CrossDevice");
	m_operandNames.emplaceUnique(Hash64(30u, 1u), "Device");
	m_operandNames.emplaceUnique(Hash64(30u, 2u), "Workgroup");
	m_operandNames.emplaceUnique(Hash64(30u, 3u), "Subgroup");
	m_operandNames.emplaceUnique(Hash64(30u, 4u), "Invocation");
	m_operandNames.emplaceUnique(Hash64(30u, 5u), "QueueFamily");
	m_operandNames.emplaceUnique(Hash64(30u, 5u), "QueueFamilyKHR");
	m_operandNames.emplaceUnique(Hash64(30u, 6u), "ShaderCallKHR");
	m_operandNames.emplaceUnique(Hash64(31u, 0u), "Reduce");
	m_operandNames.emplaceUnique(Hash64(31u, 1u), "InclusiveScan");
	m_operandNames.emplaceUnique(Hash64(31u, 2u), "ExclusiveScan");
	m_operandNames.emplaceUnique(Hash64(31u, 3u), "ClusteredReduce");
	m_operandNames.emplaceUnique(Hash64(31u, 6u), "PartitionedReduceNV");
	m_operandNames.emplaceUnique(Hash64(31u, 7u), "PartitionedInclusiveScanNV");
	m_operandNames.emplaceUnique(Hash64(31u, 8u), "PartitionedExclusiveScanNV");
	m_operandNames.emplaceUnique(Hash64(32u, 0u), "NoWait");
	m_operandNames.emplaceUnique(Hash64(32u, 1u), "WaitKernel");
	m_operandNames.emplaceUnique(Hash64(32u, 2u), "WaitWorkGroup");
	m_operandNames.emplaceUnique(Hash64(33u, 0u), "Matrix");
	m_operandNames.emplaceUnique(Hash64(33u, 1u), "Shader");
	m_operandNames.emplaceUnique(Hash64(33u, 2u), "Geometry");
	m_operandNames.emplaceUnique(Hash64(33u, 3u), "Tessellation");
	m_operandNames.emplaceUnique(Hash64(33u, 4u), "Addresses");
	m_operandNames.emplaceUnique(Hash64(33u, 5u), "Linkage");
	m_operandNames.emplaceUnique(Hash64(33u, 6u), "Kernel");
	m_operandNames.emplaceUnique(Hash64(33u, 7u), "Vector16");
	m_operandNames.emplaceUnique(Hash64(33u, 8u), "Float16Buffer");
	m_operandNames.emplaceUnique(Hash64(33u, 9u), "Float16");
	m_operandNames.emplaceUnique(Hash64(33u, 10u), "Float64");
	m_operandNames.emplaceUnique(Hash64(33u, 11u), "Int64");
	m_operandNames.emplaceUnique(Hash64(33u, 12u), "Int64Atomics");
	m_operandNames.emplaceUnique(Hash64(33u, 13u), "ImageBasic");
	m_operandNames.emplaceUnique(Hash64(33u, 14u), "ImageReadWrite");
	m_operandNames.emplaceUnique(Hash64(33u, 15u), "ImageMipmap");
	m_operandNames.emplaceUnique(Hash64(33u, 17u), "Pipes");
	m_operandNames.emplaceUnique(Hash64(33u, 18u), "Groups");
	m_operandNames.emplaceUnique(Hash64(33u, 19u), "DeviceEnqueue");
	m_operandNames.emplaceUnique(Hash64(33u, 20u), "LiteralSampler");
	m_operandNames.emplaceUnique(Hash64(33u, 21u), "AtomicStorage");
	m_operandNames.emplaceUnique(Hash64(33u, 22u), "Int16");
	m_operandNames.emplaceUnique(Hash64(33u, 23u), "TessellationPointSize");
	m_operandNames.emplaceUnique(Hash64(33u, 24u), "GeometryPointSize");
	m_operandNames.emplaceUnique(Hash64(33u, 25u), "ImageGatherExtended");
	m_operandNames.emplaceUnique(Hash64(33u, 27u), "StorageImageMultisample");
	m_operandNames.emplaceUnique(Hash64(33u, 28u), "UniformBufferArrayDynamicIndexing");
	m_operandNames.emplaceUnique(Hash64(33u, 29u), "SampledImageArrayDynamicIndexing");
	m_operandNames.emplaceUnique(Hash64(33u, 30u), "StorageBufferArrayDynamicIndexing");
	m_operandNames.emplaceUnique(Hash64(33u, 31u), "StorageImageArrayDynamicIndexing");
	m_operandNames.emplaceUnique(Hash64(33u, 32u), "ClipDistance");
	m_operandNames.emplaceUnique(Hash64(33u, 33u), "CullDistance");
	m_operandNames.emplaceUnique(Hash64(33u, 34u), "ImageCubeArray");
	m_operandNames.emplaceUnique(Hash64(33u, 35u), "SampleRateShading");
	m_operandNames.emplaceUnique(Hash64(33u, 36u), "ImageRect");
	m_operandNames.emplaceUnique(Hash64(33u, 37u), "SampledRect");
	m_operandNames.emplaceUnique(Hash64(33u, 38u), "GenericPointer");
	m_operandNames.emplaceUnique(Hash64(33u, 39u), "Int8");
	m_operandNames.emplaceUnique(Hash64(33u, 40u), "InputAttachment");
	m_operandNames.emplaceUnique(Hash64(33u, 41u), "SparseResidency");
	m_operandNames.emplaceUnique(Hash64(33u, 42u), "MinLod");
	m_operandNames.emplaceUnique(Hash64(33u, 43u), "Sampled1D");
	m_operandNames.emplaceUnique(Hash64(33u, 44u), "Image1D");
	m_operandNames.emplaceUnique(Hash64(33u, 45u), "SampledCubeArray");
	m_operandNames.emplaceUnique(Hash64(33u, 46u), "SampledBuffer");
	m_operandNames.emplaceUnique(Hash64(33u, 47u), "ImageBuffer");
	m_operandNames.emplaceUnique(Hash64(33u, 48u), "ImageMSArray");
	m_operandNames.emplaceUnique(Hash64(33u, 49u), "StorageImageExtendedFormats");
	m_operandNames.emplaceUnique(Hash64(33u, 50u), "ImageQuery");
	m_operandNames.emplaceUnique(Hash64(33u, 51u), "DerivativeControl");
	m_operandNames.emplaceUnique(Hash64(33u, 52u), "InterpolationFunction");
	m_operandNames.emplaceUnique(Hash64(33u, 53u), "TransformFeedback");
	m_operandNames.emplaceUnique(Hash64(33u, 54u), "GeometryStreams");
	m_operandNames.emplaceUnique(Hash64(33u, 55u), "StorageImageReadWithoutFormat");
	m_operandNames.emplaceUnique(Hash64(33u, 56u), "StorageImageWriteWithoutFormat");
	m_operandNames.emplaceUnique(Hash64(33u, 57u), "MultiViewport");
	m_operandNames.emplaceUnique(Hash64(33u, 58u), "SubgroupDispatch");
	m_operandNames.emplaceUnique(Hash64(33u, 59u), "NamedBarrier");
	m_operandNames.emplaceUnique(Hash64(33u, 60u), "PipeStorage");
	m_operandNames.emplaceUnique(Hash64(33u, 61u), "GroupNonUniform");
	m_operandNames.emplaceUnique(Hash64(33u, 62u), "GroupNonUniformVote");
	m_operandNames.emplaceUnique(Hash64(33u, 63u), "GroupNonUniformArithmetic");
	m_operandNames.emplaceUnique(Hash64(33u, 64u), "GroupNonUniformBallot");
	m_operandNames.emplaceUnique(Hash64(33u, 65u), "GroupNonUniformShuffle");
	m_operandNames.emplaceUnique(Hash64(33u, 66u), "GroupNonUniformShuffleRelative");
	m_operandNames.emplaceUnique(Hash64(33u, 67u), "GroupNonUniformClustered");
	m_operandNames.emplaceUnique(Hash64(33u, 68u), "GroupNonUniformQuad");
	m_operandNames.emplaceUnique(Hash64(33u, 69u), "ShaderLayer");
	m_operandNames.emplaceUnique(Hash64(33u, 70u), "ShaderViewportIndex");
	m_operandNames.emplaceUnique(Hash64(33u, 4422u), "FragmentShadingRateKHR");
	m_operandNames.emplaceUnique(Hash64(33u, 4423u), "SubgroupBallotKHR");
	m_operandNames.emplaceUnique(Hash64(33u, 4427u), "DrawParameters");
	m_operandNames.emplaceUnique(Hash64(33u, 4428u), "WorkgroupMemoryExplicitLayoutKHR");
	m_operandNames.emplaceUnique(Hash64(33u, 4429u), "WorkgroupMemoryExplicitLayout8BitAccessKHR");
	m_operandNames.emplaceUnique(Hash64(33u, 4430u), "WorkgroupMemoryExplicitLayout16BitAccessKHR");
	m_operandNames.emplaceUnique(Hash64(33u, 4431u), "SubgroupVoteKHR");
	m_operandNames.emplaceUnique(Hash64(33u, 4433u), "StorageBuffer16BitAccess");
	m_operandNames.emplaceUnique(Hash64(33u, 4433u), "StorageUniformBufferBlock16");
	m_operandNames.emplaceUnique(Hash64(33u, 4434u), "UniformAndStorageBuffer16BitAccess");
	m_operandNames.emplaceUnique(Hash64(33u, 4434u), "StorageUniform16");
	m_operandNames.emplaceUnique(Hash64(33u, 4435u), "StoragePushConstant16");
	m_operandNames.emplaceUnique(Hash64(33u, 4436u), "StorageInputOutput16");
	m_operandNames.emplaceUnique(Hash64(33u, 4437u), "DeviceGroup");
	m_operandNames.emplaceUnique(Hash64(33u, 4439u), "MultiView");
	m_operandNames.emplaceUnique(Hash64(33u, 4441u), "VariablePointersStorageBuffer");
	m_operandNames.emplaceUnique(Hash64(33u, 4442u), "VariablePointers");
	m_operandNames.emplaceUnique(Hash64(33u, 4445u), "AtomicStorageOps");
	m_operandNames.emplaceUnique(Hash64(33u, 4447u), "SampleMaskPostDepthCoverage");
	m_operandNames.emplaceUnique(Hash64(33u, 4448u), "StorageBuffer8BitAccess");
	m_operandNames.emplaceUnique(Hash64(33u, 4449u), "UniformAndStorageBuffer8BitAccess");
	m_operandNames.emplaceUnique(Hash64(33u, 4450u), "StoragePushConstant8");
	m_operandNames.emplaceUnique(Hash64(33u, 4464u), "DenormPreserve");
	m_operandNames.emplaceUnique(Hash64(33u, 4465u), "DenormFlushToZero");
	m_operandNames.emplaceUnique(Hash64(33u, 4466u), "SignedZeroInfNanPreserve");
	m_operandNames.emplaceUnique(Hash64(33u, 4467u), "RoundingModeRTE");
	m_operandNames.emplaceUnique(Hash64(33u, 4468u), "RoundingModeRTZ");
	m_operandNames.emplaceUnique(Hash64(33u, 4471u), "RayQueryProvisionalKHR");
	m_operandNames.emplaceUnique(Hash64(33u, 4472u), "RayQueryKHR");
	m_operandNames.emplaceUnique(Hash64(33u, 4478u), "RayTraversalPrimitiveCullingKHR");
	m_operandNames.emplaceUnique(Hash64(33u, 4479u), "RayTracingKHR");
	m_operandNames.emplaceUnique(Hash64(33u, 5008u), "Float16ImageAMD");
	m_operandNames.emplaceUnique(Hash64(33u, 5009u), "ImageGatherBiasLodAMD");
	m_operandNames.emplaceUnique(Hash64(33u, 5010u), "FragmentMaskAMD");
	m_operandNames.emplaceUnique(Hash64(33u, 5013u), "StencilExportEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5015u), "ImageReadWriteLodAMD");
	m_operandNames.emplaceUnique(Hash64(33u, 5016u), "Int64ImageEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5055u), "ShaderClockKHR");
	m_operandNames.emplaceUnique(Hash64(33u, 5249u), "SampleMaskOverrideCoverageNV");
	m_operandNames.emplaceUnique(Hash64(33u, 5251u), "GeometryShaderPassthroughNV");
	m_operandNames.emplaceUnique(Hash64(33u, 5254u), "ShaderViewportIndexLayerEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5254u), "ShaderViewportIndexLayerNV");
	m_operandNames.emplaceUnique(Hash64(33u, 5255u), "ShaderViewportMaskNV");
	m_operandNames.emplaceUnique(Hash64(33u, 5259u), "ShaderStereoViewNV");
	m_operandNames.emplaceUnique(Hash64(33u, 5260u), "PerViewAttributesNV");
	m_operandNames.emplaceUnique(Hash64(33u, 5265u), "FragmentFullyCoveredEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5266u), "MeshShadingNV");
	m_operandNames.emplaceUnique(Hash64(33u, 5282u), "ImageFootprintNV");
	m_operandNames.emplaceUnique(Hash64(33u, 5284u), "FragmentBarycentricNV");
	m_operandNames.emplaceUnique(Hash64(33u, 5288u), "ComputeDerivativeGroupQuadsNV");
	m_operandNames.emplaceUnique(Hash64(33u, 5291u), "FragmentDensityEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5291u), "ShadingRateNV");
	m_operandNames.emplaceUnique(Hash64(33u, 5297u), "GroupNonUniformPartitionedNV");
	m_operandNames.emplaceUnique(Hash64(33u, 5301u), "ShaderNonUniform");
	m_operandNames.emplaceUnique(Hash64(33u, 5301u), "ShaderNonUniformEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5302u), "RuntimeDescriptorArray");
	m_operandNames.emplaceUnique(Hash64(33u, 5302u), "RuntimeDescriptorArrayEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5303u), "InputAttachmentArrayDynamicIndexing");
	m_operandNames.emplaceUnique(Hash64(33u, 5303u), "InputAttachmentArrayDynamicIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5304u), "UniformTexelBufferArrayDynamicIndexing");
	m_operandNames.emplaceUnique(Hash64(33u, 5304u), "UniformTexelBufferArrayDynamicIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5305u), "StorageTexelBufferArrayDynamicIndexing");
	m_operandNames.emplaceUnique(Hash64(33u, 5305u), "StorageTexelBufferArrayDynamicIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5306u), "UniformBufferArrayNonUniformIndexing");
	m_operandNames.emplaceUnique(Hash64(33u, 5306u), "UniformBufferArrayNonUniformIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5307u), "SampledImageArrayNonUniformIndexing");
	m_operandNames.emplaceUnique(Hash64(33u, 5307u), "SampledImageArrayNonUniformIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5308u), "StorageBufferArrayNonUniformIndexing");
	m_operandNames.emplaceUnique(Hash64(33u, 5308u), "StorageBufferArrayNonUniformIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5309u), "StorageImageArrayNonUniformIndexing");
	m_operandNames.emplaceUnique(Hash64(33u, 5309u), "StorageImageArrayNonUniformIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5310u), "InputAttachmentArrayNonUniformIndexing");
	m_operandNames.emplaceUnique(Hash64(33u, 5310u), "InputAttachmentArrayNonUniformIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5311u), "UniformTexelBufferArrayNonUniformIndexing");
	m_operandNames.emplaceUnique(Hash64(33u, 5311u), "UniformTexelBufferArrayNonUniformIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5312u), "StorageTexelBufferArrayNonUniformIndexing");
	m_operandNames.emplaceUnique(Hash64(33u, 5312u), "StorageTexelBufferArrayNonUniformIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5340u), "RayTracingNV");
	m_operandNames.emplaceUnique(Hash64(33u, 5345u), "VulkanMemoryModel");
	m_operandNames.emplaceUnique(Hash64(33u, 5345u), "VulkanMemoryModelKHR");
	m_operandNames.emplaceUnique(Hash64(33u, 5346u), "VulkanMemoryModelDeviceScope");
	m_operandNames.emplaceUnique(Hash64(33u, 5346u), "VulkanMemoryModelDeviceScopeKHR");
	m_operandNames.emplaceUnique(Hash64(33u, 5347u), "PhysicalStorageBufferAddresses");
	m_operandNames.emplaceUnique(Hash64(33u, 5347u), "PhysicalStorageBufferAddressesEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5350u), "ComputeDerivativeGroupLinearNV");
	m_operandNames.emplaceUnique(Hash64(33u, 5353u), "RayTracingProvisionalKHR");
	m_operandNames.emplaceUnique(Hash64(33u, 5357u), "CooperativeMatrixNV");
	m_operandNames.emplaceUnique(Hash64(33u, 5363u), "FragmentShaderSampleInterlockEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5372u), "FragmentShaderShadingRateInterlockEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5373u), "ShaderSMBuiltinsNV");
	m_operandNames.emplaceUnique(Hash64(33u, 5378u), "FragmentShaderPixelInterlockEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5379u), "DemoteToHelperInvocationEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5568u), "SubgroupShuffleINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5569u), "SubgroupBufferBlockIOINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5570u), "SubgroupImageBlockIOINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5579u), "SubgroupImageMediaBlockIOINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5582u), "RoundToInfinityINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5583u), "FloatingPointModeINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5584u), "IntegerFunctions2INTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5603u), "FunctionPointersINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5604u), "IndirectReferencesINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5606u), "AsmINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5612u), "AtomicFloat32MinMaxEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5613u), "AtomicFloat64MinMaxEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5616u), "AtomicFloat16MinMaxEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 5617u), "VectorComputeINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5619u), "VectorAnyINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5696u), "SubgroupAvcMotionEstimationINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5697u), "SubgroupAvcMotionEstimationIntraINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5698u), "SubgroupAvcMotionEstimationChromaINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5817u), "VariableLengthArrayINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5821u), "FunctionFloatControlINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5824u), "FPGAMemoryAttributesINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5837u), "FPFastMathModeINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5844u), "ArbitraryPrecisionIntegersINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5886u), "UnstructuredLoopControlsINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5888u), "FPGALoopControlsINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5892u), "KernelAttributesINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5897u), "FPGAKernelAttributesINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5898u), "FPGAMemoryAccessesINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5904u), "FPGAClusterAttributesINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5906u), "LoopFuseINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5920u), "FPGABufferLocationINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5935u), "USMStorageClassesINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5943u), "IOPipesINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5945u), "BlockingPipesINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 5948u), "FPGARegINTEL");
	m_operandNames.emplaceUnique(Hash64(33u, 6033u), "AtomicFloat32AddEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 6034u), "AtomicFloat64AddEXT");
	m_operandNames.emplaceUnique(Hash64(33u, 6089u), "LongConstantCompositeINTEL");
	m_operandNames.emplaceUnique(Hash64(34u, 0u), "RayQueryCandidateIntersectionKHR");
	m_operandNames.emplaceUnique(Hash64(34u, 1u), "RayQueryCommittedIntersectionKHR");
	m_operandNames.emplaceUnique(Hash64(35u, 0u), "RayQueryCommittedIntersectionNoneKHR");
	m_operandNames.emplaceUnique(Hash64(35u, 1u), "RayQueryCommittedIntersectionTriangleKHR");
	m_operandNames.emplaceUnique(Hash64(35u, 2u), "RayQueryCommittedIntersectionGeneratedKHR");
	m_operandNames.emplaceUnique(Hash64(36u, 0u), "RayQueryCandidateIntersectionTriangleKHR");
	m_operandNames.emplaceUnique(Hash64(36u, 1u), "RayQueryCandidateIntersectionAABBKHR");
}
const Grammar::Instruction* Grammar::getInfo(unsigned int _opcode, Extension _extension) const
{
	return m_instructions.get(Hash64(_opcode, static_cast<unsigned int>(_extension)));
}
const char* Grammar::getOperandName(OperandKind _kind, unsigned int _literalValue) const
{
	const char** name = m_operandNames.get(Hash64(static_cast<unsigned int>(_kind), _literalValue));
	return name == nullptr ? nullptr : *name;
}
const Vector<Grammar::Operand>* Grammar::getOperandParameters(OperandKind _kind, unsigned int _literalValue) const
{
	return m_operandParameters.get(Hash64(static_cast<unsigned int>(_kind), _literalValue));
}
const Vector<Grammar::Operand>* Grammar::getOperandBases(OperandKind _kind) const
{
	return m_operandBases.get(_kind);
}
bool Grammar::hasOperandParameters(OperandKind _kind)
{
	switch (_kind) {
	default: return false; // majority of operand kinds don't have parameters
	case OperandKind::ImageOperands: return true;
	case OperandKind::LoopControl: return true;
	case OperandKind::MemoryAccess: return true;
	case OperandKind::ExecutionMode: return true;
	case OperandKind::Decoration: return true;
	};
}
