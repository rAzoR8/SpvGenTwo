#include "spvgentwo/Type.h"

spvgentwo::Type::Type(IAllocator* _pAllocator) :
	m_subTypes(_pAllocator)
{
}

spvgentwo::Type::Type(IAllocator* _pAllocator, const Type& _subType, const spv::Op _baseType) :
	m_Type(_baseType),
	m_subTypes(_pAllocator)
{
	m_subTypes.emplace_back(_subType);
}

spvgentwo::Type::Type(IAllocator* _pAllocator, Type&& _subType, const spv::Op _baseType) :
	m_Type(_baseType),
	m_subTypes(_pAllocator)
{
	m_subTypes.emplace_back(stdrep::move(_subType));
}

spvgentwo::Type::Type(Type&& _other) noexcept:
	m_Type(_other.m_Type),
	m_IntWidth(_other.m_IntWidth),
	m_IntSign(_other.m_IntSign),
	m_StorageClass(_other.m_StorageClass),
	m_ImgDimension(_other.m_ImgDimension),
	m_ImgArray(_other.m_ImgArray),
	m_ImgMultiSampled(_other.m_ImgMultiSampled),
	m_ImgSamplerAccess(_other.m_ImgSamplerAccess),
	m_ImgFormat(_other.m_ImgFormat),
	m_AccessQualifier(_other.m_AccessQualifier),
	m_subTypes(stdrep::move(_other.m_subTypes))
{
}

spvgentwo::Type::Type(const Type& _other) : 
	m_Type(_other.m_Type),
	m_IntWidth(_other.m_IntWidth),
	m_IntSign(_other.m_IntSign),
	m_StorageClass(_other.m_StorageClass),
	m_ImgDimension(_other.m_ImgDimension),
	m_ImgArray(_other.m_ImgArray),
	m_ImgMultiSampled(_other.m_ImgMultiSampled),
	m_ImgSamplerAccess(_other.m_ImgSamplerAccess),
	m_ImgFormat(_other.m_ImgFormat),
	m_AccessQualifier(_other.m_AccessQualifier),
	m_subTypes(_other.m_subTypes)
{
}

spvgentwo::Type::~Type()
{
}

spvgentwo::Type& spvgentwo::Type::operator=(Type&& _other) noexcept
{
	if (this == &_other) return *this;

	m_subTypes = stdrep::move(_other.m_subTypes);

	m_Type = _other.m_Type;
	m_IntSign = _other.m_IntSign;
	m_IntWidth = _other.m_IntWidth;
	m_ImgDimension = _other.m_ImgDimension;
	m_ImgArray = _other.m_ImgArray;
	m_ImgMultiSampled = _other.m_ImgMultiSampled;
	m_ImgSamplerAccess = _other.m_ImgSamplerAccess;
	m_ImgFormat = _other.m_ImgFormat;
	m_StorageClass = _other.m_StorageClass;
	m_AccessQualifier = _other.m_AccessQualifier;

	return *this;
}
spvgentwo::Type& spvgentwo::Type::operator=(const Type& _other)
{
	if (this == &_other) return *this;
	m_subTypes = _other.m_subTypes;

	m_Type = _other.m_Type;
	m_IntSign = _other.m_IntSign;
	m_IntWidth = _other.m_IntWidth;
	m_ImgDimension = _other.m_ImgDimension;
	m_ImgArray = _other.m_ImgArray;
	m_ImgMultiSampled = _other.m_ImgMultiSampled;
	m_ImgSamplerAccess = _other.m_ImgSamplerAccess;
	m_ImgFormat = _other.m_ImgFormat;
	m_StorageClass = _other.m_StorageClass;
	m_AccessQualifier = _other.m_AccessQualifier;

	return *this;
}

bool spvgentwo::Type::operator==(const Type& _other) const
{
	return
		m_Type == _other.m_Type &&
		m_IntSign == _other.m_IntSign &&
		m_IntWidth == _other.m_IntWidth &&
		m_ImgDimension == _other.m_ImgDimension &&
		m_ImgArray == _other.m_ImgArray &&
		m_ImgMultiSampled == _other.m_ImgMultiSampled &&
		m_ImgSamplerAccess ==_other.m_ImgSamplerAccess &&
		m_ImgFormat == _other.m_ImgFormat &&
		m_StorageClass == _other.m_StorageClass &&
		m_AccessQualifier == _other.m_AccessQualifier &&
		m_subTypes == _other.m_subTypes;
}

const spvgentwo::Type& spvgentwo::Type::getBaseType() const
{
	if (m_subTypes.empty())
	{
		return *this;
	}

	return front().getBaseType();
}

spvgentwo::Type& spvgentwo::Type::getBaseType()
{
	if (m_subTypes.empty())
	{
		return *this;
	}

	return front().getBaseType();
}

const char* spvgentwo::Type::getString() const
{
	if (isVoid()) return "void";
	if (isBool()) return "bool";
	if (isS16()) return "int16_t";
	if (isU16()) return "uint16_t";
	if (isS32()) return "int32_t";
	if (isU32()) return "uint32_t";
	if (isS64()) return "int64_t";
	if (isU64()) return "uint64_t";
	if (isF16()) return "half";
	if (isF32()) return "float";
	if (isF64()) return "double";
	if (isVector()) return "vec";
	if (isMatrix()) return "mat";
	if (isArray()) return "array";
	if (isStruct()) return "struct";
	if (isImage()) return "image";
	if (isSampledImage()) return "sampledimage";
	if (isSampler()) return "sampler";
	if (isPointer()) return "pointer";
	if (isForwardPointer()) return "forwardpointer";

	return "";
}

spv::Op spvgentwo::Type::getBaseTypeOp() const
{
	return getBaseType().m_Type;
}

bool spvgentwo::Type::isBaseTypeOf(const spv::Op _type) const
{
	return getBaseType().getType() == _type;
}

bool spvgentwo::Type::hasSameBase(const Type& _other, const bool _onlyCheckTyeOp) const
{
	const Type& lBase = getBaseType();
	const Type& rBase = _other.getBaseType();

	return _onlyCheckTyeOp ? lBase.m_Type == rBase.m_Type : lBase == rBase;
}

void spvgentwo::Type::setType(const spv::Op _type)
{
	if (isTypeOp(_type))
	{
		m_Type = _type;
	}
}

void spvgentwo::Type::reset()
{
	m_Type = spv::Op::OpTypeVoid;
	m_subTypes.clear();

	m_ImgDepth = 0u;
	m_IntSign = false;

	m_StorageClass = spv::StorageClass::Generic;

	m_ImgDimension = spv::Dim::Max;
	m_ImgArray = false;
	m_ImgMultiSampled = false;
	m_ImgSamplerAccess = SamplerImageAccess::Unknown;
	m_ImgFormat = spv::ImageFormat::Unknown;

	m_AccessQualifier = spv::AccessQualifier::Max;
}

spvgentwo::Type& spvgentwo::Type::Void()
{
	m_Type = spv::Op::OpTypeVoid;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::Bool()
{
	m_Type = spv::Op::OpTypeBool;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::Int(const unsigned int _bits, const bool _sign)
{
	m_Type = spv::Op::OpTypeInt;
	m_IntWidth = _bits;
	m_IntSign = _sign;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::Float(const unsigned int _bits)
{
	m_Type = spv::Op::OpTypeFloat;
	m_FloatWidth = _bits;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::Scalar(const spv::Op _base, const unsigned int _bits, const bool _sign)
{
	m_Type = _base;
	m_FloatWidth = _bits;
	m_IntSign = _sign;

	return *this;
}

spvgentwo::Type& spvgentwo::Type::Scalar(const dyn_scalar_t& _scalarType)
{
	m_Type = _scalarType.baseType;
	m_FloatWidth = _scalarType.bits;
	m_IntSign = _scalarType.sign;

	return *this;
}

spvgentwo::Type& spvgentwo::Type::Struct(const Type* _pSubType)
{
	m_Type = spv::Op::OpTypeStruct;

	if (_pSubType != nullptr)
	{
		m_subTypes.emplace_back(*_pSubType);
	}

	return *this;
}

spvgentwo::Type& spvgentwo::Type::Array(const unsigned int _elements, const Type* _pElementType)
{
	m_Type = spv::Op::OpTypeArray;
	m_ArrayLength = _elements;

	if(_pElementType != nullptr)
	{
		m_subTypes.emplace_back(*_pElementType);
	}

	return *this;
}

spvgentwo::Type& spvgentwo::Type::RuntimeArray(const Type* _elementType)
{
	m_Type = spv::Op::OpTypeRuntimeArray;

	if (_elementType != nullptr)
	{
		m_subTypes.emplace_back(*_elementType);
	}

	return *this;
}

spvgentwo::Type& spvgentwo::Type::Function()
{
	m_Type = spv::Op::OpTypeFunction;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::Pointer(const spv::StorageClass _storageClass, const Type* _pInnerType)
{
	m_Type = spv::Op::OpTypePointer;
	m_StorageClass = _storageClass;

	if (_pInnerType != nullptr)
	{
		m_subTypes.emplace_back(*_pInnerType);
	}

	return *this;
}

spvgentwo::Type& spvgentwo::Type::ForwardPointer(const spv::StorageClass _storageClass, const Type* _pInnerType)
{
	m_Type = spv::Op::OpTypeForwardPointer;
	m_StorageClass = _storageClass;

	if (_pInnerType != nullptr)
	{
		m_subTypes.emplace_back(*_pInnerType);
	}

	return *this;
}

spvgentwo::Type& spvgentwo::Type::Sampler()
{
	m_Type = spv::Op::OpTypeSampler;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::Image(const dyn_scalar_t _sampledType, const spv::Dim _dim, const unsigned int _depth, const bool _array, const bool _multiSampled, const SamplerImageAccess _sampled, const spv::ImageFormat _format, const spv::AccessQualifier _access)
{
	m_Type = spv::Op::OpTypeImage;

	Member().Scalar(_sampledType.baseType, _sampledType.bits, _sampledType.sign);

	m_ImgDimension = _dim;
	m_ImgDepth = _depth;
	m_ImgArray = _array;
	m_ImgMultiSampled = _multiSampled;
	m_ImgSamplerAccess = _sampled;
	m_ImgFormat = _format;
	m_AccessQualifier = _access;

	return *this;
}

spvgentwo::Type& spvgentwo::Type::Image(const dyn_image_t& _imageType)
{
	return Image(
		_imageType.sampledType,
		_imageType.dimension,
		_imageType.depth,
		_imageType.array,
		_imageType.multiSampled,
		_imageType.samplerAccess,
		_imageType.format,
		_imageType.accessQualifier);
}

spvgentwo::Type& spvgentwo::Type::SampledImage(const Type* _imageType)
{
	m_Type = spv::Op::OpTypeSampledImage;

	if (_imageType != nullptr)
	{
		m_subTypes.emplace_back(*_imageType);
	}

	return *this;
}

spvgentwo::Type& spvgentwo::Type::SampledImage(const dyn_image_t& _imageType)
{
	m_Type = spv::Op::OpTypeSampledImage;

	Member().Image(_imageType);

	return *this;
}

spvgentwo::Type& spvgentwo::Type::Event()
{
	m_Type = spv::Op::OpTypeEvent;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::DeviceEvent()
{
	m_Type = spv::Op::OpTypeDeviceEvent;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::ReserveId()
{
	m_Type = spv::Op::OpTypeReserveId;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::Queue()
{
	m_Type = spv::Op::OpTypeQueue;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::PipeStorage()
{
	m_Type = spv::Op::OpTypePipeStorage;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::NamedBarrier()
{
	m_Type = spv::Op::OpTypeNamedBarrier;
	return *this;
}

spvgentwo::Type& spvgentwo::Type::Vector(unsigned int _elements, const Type* _elementType)
{
	m_Type = spv::Op::OpTypeVector;
	m_VecComponentCount = _elements;

	if (_elementType != nullptr)
	{
		m_subTypes.emplace_back(*_elementType);
	}

	return *this;
}

spvgentwo::Type& spvgentwo::Type::Vector(const dyn_vector_t& _vectorType)
{
	m_Type = spv::Op::OpTypeVector;
	m_VecComponentCount = _vectorType.elements;

	Member().Scalar(_vectorType.elementType);

	return *this;
}

spvgentwo::Type& spvgentwo::Type::Matrix(unsigned int _columns, const Type* _columnType)
{
	m_Type = spv::Op::OpTypeMatrix;
	m_MatColumnCount = _columns; // length of the row

	if (_columnType != nullptr)
	{
		m_subTypes.emplace_back(*_columnType);
	}

	return *this;
}

spvgentwo::Type& spvgentwo::Type::Matrix(const dyn_matrix_t& _matrixType)
{
	m_Type = spv::Op::OpTypeMatrix;
	m_MatColumnCount = _matrixType.columns; // length of the row

	Member().Vector(_matrixType.columnType);

	return *this;
}

spvgentwo::Type& spvgentwo::Type::Member(const Type* _pSubType)
{
	if (_pSubType == nullptr)
	{
		return m_subTypes.emplace_back(m_subTypes.getAllocator());	
	}
	else
	{
		return m_subTypes.emplace_back(*_pSubType);
	}
}

spvgentwo::Type spvgentwo::Type::New() const
{
	return Type(m_subTypes.getAllocator());
}

spvgentwo::Type spvgentwo::Type::wrap(const spv::Op _baseType) const
{
	 return Type(m_subTypes.getAllocator(), *this, _baseType);
}

spvgentwo::Type spvgentwo::Type::moveWrap(const spv::Op _baseType)
{
	return Type(m_subTypes.getAllocator(), stdrep::move(*this), _baseType);
}

spvgentwo::Type spvgentwo::Type::wrapPointer(const spv::StorageClass _storageClass) const
{
	Type vec(m_subTypes.getAllocator());
	vec.Pointer(_storageClass, this);
	return vec;
}

spvgentwo::Type spvgentwo::Type::wrapVector(const unsigned int _elements) const
{
	Type vec(m_subTypes.getAllocator());
	vec.Vector(_elements, this);
	return vec;
};

spvgentwo::Type spvgentwo::Type::wrapMatrix(const unsigned int _columns)
{
	Type mat(m_subTypes.getAllocator());
	mat.Matrix(_columns, this);
	return mat;
}

spvgentwo::Type spvgentwo::Type::wrapArray(const unsigned int _elements) const
{
	Type array(m_subTypes.getAllocator());
	array.Array(_elements, this);
	return array;
}

spvgentwo::Type spvgentwo::Type::wrapStruct() const
{
	Type st(m_subTypes.getAllocator());
	st.Struct(this);
	return st;
}