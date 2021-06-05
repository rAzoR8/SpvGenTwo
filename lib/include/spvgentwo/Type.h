#pragma once

#include "List.h"
#include "SpvDefines.h"
#include "FNV1aHasher.h"

namespace spvgentwo
{
	// forward decls
	class IAllocator;

#pragma region decls
	// opaque types
	struct event_t {};
	struct device_event_t {};
	struct reserve_id_t {};
	struct queue_t {};
	struct pipe_t {};
	struct pipe_storage_t {};
	struct named_barrier_t {};

	struct sampler_t {};

	struct ray_query_khr_t {};
	struct acceleration_structure_khr_t {};

	struct dyn_scalar_t
	{
		struct dyntype_desc_tag {};
		spv::Op baseType = spv::Op::OpTypeVoid; // OpTypeInt or OpTypeFloat
		unsigned int bits = 32u; // bit width of int / float
		bool sign = false; // integer sign
	};

	struct dyn_image_t
	{
		struct dyntype_desc_tag {};

		dyn_scalar_t sampledType{ spv::Op::OpTypeFloat };
		spv::Dim dimension = spv::Dim::Dim2D;
		unsigned int depth = 1u;
		bool array = false;
		bool multiSampled = false;
		SamplerImageAccess samplerAccess = SamplerImageAccess::Unknown;
		spv::ImageFormat format = spv::ImageFormat::Unknown;
		spv::AccessQualifier accessQualifier = spv::AccessQualifier::Max;
	};

	struct dyn_sampled_image_t { dyn_image_t imageType; struct dyntype_desc_tag {};};

	struct dyn_vector_t { dyn_scalar_t elementType; unsigned int elements;  struct dyntype_desc_tag {};};
	struct dyn_matrix_t { dyn_vector_t columnType; unsigned int columns; /*length of the row*/ struct dyntype_desc_tag {};};

	template<class T, unsigned int N>
	struct array_t {
		using array_element_type = T;
		static constexpr unsigned int Elements = N;
	};

	template<class T, unsigned int N>
	struct vector_t {
		using vec_element_type = T;
		static constexpr unsigned int Elements = N;
	};

	template<class T, unsigned int _Columns, unsigned int _Rows>
	struct matrix_t {
		using mat_column_type = vector_t<T, _Rows>;
		using mat_row_type = vector_t<T, _Columns>;
		static constexpr unsigned int Columns = _Columns;
		static constexpr unsigned int Rows = _Rows;
	};
#pragma endregion

	class Type
	{
	public:
		using Iterator = List<Type>::Iterator;

		constexpr Type(IAllocator* _pAllocator = nullptr, const spv::Op _type = spv::Op::OpTypeVoid);
		Type(IAllocator* _pAllocator, const Type& _subType, const spv::Op _baseType = spv::Op::OpTypeVoid);
		Type(IAllocator* _pAllocator, Type&& _subType, const spv::Op _baseType = spv::Op::OpTypeVoid);

		Type(Type&& _other) noexcept;
		Type(const Type& _other);
		~Type();

		Type& operator=(Type&& _other) noexcept;
		Type& operator=(const Type& _other);

		bool operator==(const Type& _other) const;
		bool operator!=(const Type& _other) const { return !operator==(_other); }

		bool operator==(spv::Op _type) const { return m_Type == _type; }
		bool operator!=(spv::Op _type) const { return m_Type != _type; }

		void reset();

		constexpr spv::Op getType() const { return m_Type; }
		void setType(const spv::Op _type);

		// get inner most subtype
		constexpr const Type& getBaseType() const;
		constexpr Type& getBaseType();

		// fundamentals only
		const char* getString() const;

		constexpr spv::Op getBaseTypeOp() const { return getBaseType().m_Type; }

		constexpr bool isBaseTypeOf(const spv::Op _type) const { return getBaseType().getType() == _type; }
		constexpr bool hasSameBase(const Type& _other, const bool _onlyCheckTypeOp = false) const;

		// dimension, bits, elements
		constexpr unsigned int getIntWidth() const { return m_IntWidth; }
		void setIntWidth(const unsigned int _width) { m_IntWidth = _width; }

		constexpr unsigned int getFloatWidth() const { return m_FloatWidth; }
		void setFloatWidth(const unsigned int _width) { m_FloatWidth = _width; }

		constexpr unsigned int getImageDepth() const { return m_ImgDepth; }
		void setImageDepth(const unsigned int _depth) { m_ImgDepth = _depth; }

		constexpr bool getIntSign() const { return m_IntSign; }
		void setIntSign(const bool _sign) { m_IntSign = _sign; }

		constexpr spv::Dim getImageDimension() const { return m_ImgDimension; }
		void setImageDimension(const spv::Dim _dim) { m_ImgDimension = _dim; }

		constexpr bool getImageArray() const { return m_ImgArray; }
		void setImageArray(const bool _array) { m_ImgArray = _array; }

		constexpr bool getImageMultiSampled() const { return m_ImgMultiSampled; }
		void setImageMultiSampled(const bool _ms) { m_ImgMultiSampled = _ms; }

		constexpr SamplerImageAccess getImageSamplerAccess() const { return m_ImgSamplerAccess; }
		void setImageSamplerAccess(const SamplerImageAccess _access) { m_ImgSamplerAccess = _access; }

		constexpr spv::ImageFormat getImageFormat() const { return m_ImgFormat; }
		void setImageFormat(const spv::ImageFormat _format) { m_ImgFormat = _format; }

		constexpr unsigned int getVectorComponentCount() const { return m_VecComponentCount; }
		void setVectorComponentCount(unsigned int _count) { m_VecComponentCount = _count; }

		constexpr unsigned int getMatrixColumnCount() const { return m_MatColumnCount; }
		void setMatrixColumnCount(unsigned int _count) { m_MatColumnCount = _count; }

		unsigned int getMatrixRowCount() const { return isMatrix() ? front().getVectorComponentCount() : 0u; }
		void getMatrixRowCount(unsigned int _rows) { if(isMatrix()) front().setVectorComponentCount(_rows); }

		constexpr unsigned int getArrayLength() const { return m_ArrayLength; }
		void setArrayLength(unsigned int _legnth) { m_ArrayLength = _legnth;}

		constexpr spv::StorageClass getStorageClass() const { return m_StorageClass; }
		void setStorageClass(const spv::StorageClass _storageClass) { m_StorageClass = _storageClass; }
		
		constexpr spv::AccessQualifier getAccessQualifier() const { return m_AccessQualifier; }
		void setAccessQualifier(const spv::AccessQualifier _access) { m_AccessQualifier = _access; }

		constexpr const List<Type>& getSubTypes() const { return m_subTypes; }
		constexpr List<Type>& getSubTypes() { return m_subTypes; }

		// return new subtype, if _pSubType is not nullptr, returned member type is a copy of _pSubType
		Type& Member(const Type* _pSubType = nullptr);

		// makes this a void type
		Type& Void();

		// adds a new member of type void but returns this structure
		Type& VoidM() { Member().Void(); return *this; }
		
		Type& Bool();
		Type& BoolM() { Member().Bool(); return *this; }

		Type& Int(const unsigned int _bits = 32u, const bool _sign = true);
		Type& IntM(const unsigned int _bits = 32u, const bool _sign = true) { Member().Int(_bits, _sign); return *this; }

		Type& UInt(const unsigned int _bits = 32u) { return Int(_bits, false); }
		Type& UIntM(const unsigned int _bits = 32u) { return IntM(_bits, false); }

		Type& Float(const unsigned int _bits = 32u);
		Type& FloatM(const unsigned int _bits = 32u) { Member().Float(_bits); return *this; }

		Type& Double() { return Float(64u); };
		Type& DoubleM() { Member().Float(64u); return *this; }

		Type& Scalar(const spv::Op _base, const unsigned int _bits, const bool _sign);
		Type& Scalar(const dyn_scalar_t& _scalarType);

		// makes this a struct
		Type& Struct(const Type* _pSubType = nullptr);

		// makes this an array
		Type& Array(const unsigned int _elements = 0u, const Type* _elementType = nullptr);
		// makes this an array, returns element type
		Type& ArrayElement(const unsigned int _elements) { Array(_elements); return Member(); }

		Type& RuntimeArray(const Type* _elementType = nullptr);

		// makes this a function
		Type& Function();

		// make this a pointer
		Type& Pointer(const spv::StorageClass _storageClass = spv::StorageClass::Generic, const Type* _innerType = nullptr);
		Type& ForwardPointer(const spv::StorageClass _storageClass = spv::StorageClass::Generic, const Type* _innerType = nullptr);

		Type& Sampler();

		Type& Image(
			const dyn_scalar_t _sampledType = {spv::Op::OpTypeFloat},
			const spv::Dim _dim = spv::Dim::Dim2D,
			const unsigned int _depth = 1u,
			const bool _array = false,
			const bool _multiSampled = false,
			const SamplerImageAccess _sampled = SamplerImageAccess::Unknown,
			const spv::ImageFormat _format = spv::ImageFormat::Unknown,
			const spv::AccessQualifier _access = spv::AccessQualifier::Max);

		Type& Image(const dyn_image_t& _imageType);

		Type& SampledImage(const Type* _imageType = nullptr);
		Type& SampledImage(const dyn_image_t& _imageType);
		Type& SampledImage(const dyn_sampled_image_t& _sampledImageType) { return SampledImage(_sampledImageType.imageType); }

		Type& Event();

		Type& DeviceEvent();

		Type& ReserveId();

		Type& Queue();

		Type& Pipe();

		Type& PipeStorage();

		Type& NamedBarrier();

		Type& Vector(unsigned int _elements = 0u, const Type* _elementType = nullptr);
		Type& VectorM(unsigned int _elements = 0u, const Type* _elementType = nullptr) { Member().Vector(_elements, _elementType); return *this; }
		Type& Vector(const dyn_vector_t& _vectorType);

		// makes this a vector type, returns element type
		Type& VectorElement(unsigned int _elements) { Vector(_elements); return Member(); }

		Type& Matrix(unsigned int _columns = 0, const Type* _columnType = nullptr);
		Type& Matrix(const dyn_matrix_t& _matrixType);
		Type& Matrix(unsigned int _columns, unsigned int _rows, const Type* _componentType);

		// makes this a matrix type, returns column vector type
		Type& MatrixColumn(unsigned int _columns) { Matrix(_columns); return Member().Vector(); }
		
		Type& RayQueryKHR();

		Type& AccelerationStructureKHR();

		constexpr Iterator begin() const { return m_subTypes.begin(); }
		constexpr Iterator end() const { return m_subTypes.end(); }

		constexpr Type& front() { return m_subTypes.front(); }
		constexpr const Type& front() const { return m_subTypes.front(); }

		constexpr Type& back() { return m_subTypes.back(); }
		constexpr const Type& back() const { return m_subTypes.back(); }

		template <class T>
		Type& fundamental([[maybe_unused]] const T* _typeInfo = nullptr) { /*static_assert(false, "incompatible type"); GCC doesnt like this*/ return *this; }

		template <class T, class ... Props>
		Type& make(const Props& ... _props);

		// set Properties by type: spv::Dim -> image Dimension etc
		template <class Prop, class ...Props>
		void setProperties(const Prop& _first, const Props& ... _props);

		constexpr bool isVoid() const { return m_Type == spv::Op::OpTypeVoid; }
		constexpr bool isBool() const { return m_Type == spv::Op::OpTypeBool;	}
		constexpr bool isPointer() const { return m_Type == spv::Op::OpTypePointer; }
		constexpr bool isForwardPointer() const { return m_Type == spv::Op::OpTypeForwardPointer; }
		constexpr bool isStruct() const { return m_Type == spv::Op::OpTypeStruct; }
		constexpr bool isArray() const { return m_Type == spv::Op::OpTypeArray; }
		constexpr bool isRuntimeArray() const { return m_Type == spv::Op::OpTypeRuntimeArray; }
		constexpr bool isImage() const { return m_Type == spv::Op::OpTypeImage; }
		constexpr bool isSampler() const { return m_Type == spv::Op::OpTypeSampler; }
		constexpr bool isSampledImage() const { return m_Type == spv::Op::OpTypeSampledImage; }
		constexpr bool isVector() const { return m_Type == spv::Op::OpTypeVector; }
		constexpr bool isMatrix() const { return m_Type == spv::Op::OpTypeMatrix; }
		constexpr bool isInt(unsigned int _bitWidth = 0u, Sign _sign = Sign::Any) const { return m_Type == spv::Op::OpTypeInt && (_bitWidth == 0u || _bitWidth == m_IntWidth) && hasSign(_sign); }
		constexpr bool isUInt(unsigned int _bitWidth = 0u) const { return isInt(_bitWidth) && m_IntSign == false; }
		constexpr bool isSInt(unsigned int _bitWidth = 0u) const { return isInt(_bitWidth) && m_IntSign; }
		constexpr bool isI8() const { return isInt(8u); }
		constexpr bool isU8() const { return isUInt(8u); }
		constexpr bool isS8() const { return isSInt(8u); }
		constexpr bool isI16() const { return isInt(16u); }
		constexpr bool isU16() const { return isUInt(16u); }
		constexpr bool isS16() const { return isSInt(16u); }
		constexpr bool isI32() const { return isInt(32u); }
		constexpr bool isU32() const { return isUInt(32u); }
		constexpr bool isS32() const { return isSInt(32u); }
		constexpr bool isI64() const { return isInt(64u); }
		constexpr bool isU64() const { return isUInt(64u); }
		constexpr bool isS64() const { return isSInt(64u); }
		constexpr bool isFloat(unsigned int _bitWidth = 0u) const { return m_Type == spv::Op::OpTypeFloat && (_bitWidth == 0u || _bitWidth == m_FloatWidth); }
		constexpr bool isF16() const { return m_Type == spv::Op::OpTypeFloat && m_FloatWidth == 16u; }
		constexpr bool isF32() const { return m_Type == spv::Op::OpTypeFloat && m_FloatWidth == 32u; }
		constexpr bool isF64() const { return m_Type == spv::Op::OpTypeFloat && m_FloatWidth == 64u; }

		constexpr bool isNumerial() const { return isInt() || isFloat(); }
		constexpr bool isScalar() const { return isNumerial() || isBool(); }
		constexpr bool isAggregate() const { return isStruct() || isArray(); }
		constexpr bool isComposite() const { return isAggregate() || isMatrix() || isVector(); }

		// check if this type has same sign as _sign
		constexpr bool hasSign(Sign _sign) const { return _sign == Sign::Any || ((_sign == Sign::Signed) == getBaseType().isSInt()); }
		constexpr void setSign(bool _signum) { getBaseType().m_IntSign = _signum; }

		// check for base sign of int
		constexpr bool isSigned() const { return getBaseType().isSInt(); }
		constexpr bool isUnsigned() const { return getBaseType().isUInt(); }

		constexpr bool isOpaque() const { return m_Type == spv::Op::OpTypeOpaque; }
		constexpr bool isFunction() const { return m_Type == spv::Op::OpTypeFunction; }
		constexpr bool isEvent() const { return m_Type == spv::Op::OpTypeEvent; }
		constexpr bool isDeviceEvent() const { return m_Type == spv::Op::OpTypeDeviceEvent; }
		constexpr bool isReservedId() const { return m_Type == spv::Op::OpTypeReserveId; }
		constexpr bool isPipe() const { return m_Type == spv::Op::OpTypePipe; }
		constexpr bool isPipeStorage() const { return m_Type == spv::Op::OpTypePipeStorage; }
		constexpr bool isQueue() const { return m_Type == spv::Op::OpTypeQueue; }

		constexpr bool isRayQueryKHR() const { return m_Type == spv::Op::OpTypeRayQueryKHR; }
		constexpr bool isAccelerationStructure() const { return m_Type == spv::Op::OpTypeAccelerationStructureKHR; }

		constexpr bool isVectorOf(const spv::Op _type, const unsigned int _length = 0u, const unsigned int _componentWidth = 0u, Sign _sign = Sign::Any) const { return isVector() && front().getType() == _type && (_length == 0u || m_VecComponentCount == _length) && (_componentWidth == 0u || front().getIntWidth() == _componentWidth) && front().hasSign(_sign); }

		// does not check for type
		constexpr bool isVectorOfLength(const unsigned int _length, const unsigned int _componentWidth = 0u, Sign _sign = Sign::Any) const { return isVector() && front().hasSign(_sign) && (_length == 0u || m_VecComponentCount == _length) && (_componentWidth == 0u || front().getIntWidth() == _componentWidth); }
		constexpr bool isVectorOfInt(const unsigned int _length = 0u, const unsigned int _componentWidth = 0u, Sign _sign = Sign::Any) const { return isVectorOfLength(_length, _componentWidth, _sign) && front().isInt(); }
		constexpr bool isVectorOfSInt(const unsigned int _length = 0u, const unsigned int _componentWidth = 0u) const { return isVectorOfInt(_length, _componentWidth, Sign::Signed); }
		constexpr bool isVectorOfUInt(const unsigned int _length = 0u, const unsigned int _componentWidth = 0u) const { return isVectorOfInt(_length, _componentWidth, Sign::Unsigned); }
		constexpr bool isVectorOfFloat(const unsigned int _length = 0u, const unsigned int _componentWidth = 0u) const { return isVectorOfLength(_length, _componentWidth) && front().isFloat(); }
		constexpr bool isVectorOfBool(const unsigned int _length = 0u) const { return isVectorOfLength(_length) && front().isBool(); }

		constexpr bool isScalarOrVectorOf(const spv::Op _type, const unsigned int _length = 0u, const unsigned int _componentWidth = 0u, Sign _sign = Sign::Any) const { return (m_Type == _type && (_componentWidth == 0u || m_IntWidth == _componentWidth) && hasSign(_sign)) || isVectorOf(_type, _length, _componentWidth, _sign); }
		constexpr bool isNumericalScalarOrVector(const unsigned int _length = 0u, const unsigned int _componentWidth = 0u, Sign _sign = Sign::Any) const { return (isNumerial() && (_componentWidth == 0u || m_IntWidth == _componentWidth) && hasSign(_sign)) || (isVectorOfLength(_length, _componentWidth, _sign) && front().isNumerial()); }

		constexpr bool hasSameVectorLength(const Type& _other) const { return isVector() && _other.isVector() && m_VecComponentCount == _other.m_VecComponentCount; }
		constexpr bool hasSameVectorLength(const Type& _other, const spv::Op _componentType) const { return isVectorOf(_componentType) && _other.isVectorOf(_componentType) && m_VecComponentCount == _other.m_VecComponentCount; }
		constexpr bool isScalarOrVectorOfSameLength(const spv::Op _type, const Type& _other, bool _sameComponentWidth = true) const { return (!_sameComponentWidth || getBaseType().getIntWidth() == _other.getBaseType().getIntWidth()) && (hasSameVectorLength(_other, _type) || (m_Type == _type && _other.m_Type == _type && isScalar() && _other.isScalar())); }
		constexpr bool hasSameComponentWidth(const Type& _other) const { const Type& a = getBaseType(); const Type& b = _other.getBaseType(); return a.getType() == b.getType() && a.getIntWidth() == b.getIntWidth(); }

		constexpr bool isMatrixOf(const spv::Op _baseType, const unsigned int _columns = 0u, const unsigned int _rows = 0u, const unsigned int _componentWidth = 0u, Sign _sign = Sign::Any) const { return isMatrix() && getBaseTypeOp() == _baseType && (_columns == 0u || (getMatrixColumnCount() == _columns)) && (_rows == 0u || (front().getVectorComponentCount() == _rows)) && (_componentWidth == 0u || getBaseType().getFloatWidth() == _componentWidth) && getBaseType().hasSign(_sign); }
		constexpr bool isMatrixOfFloat(const unsigned int _columns = 0u, const unsigned int _rows = 0u, const unsigned int _componentWidth = 0u) const { return isMatrixOf(spv::Op::OpTypeFloat, _columns, _rows, _componentWidth); }
		constexpr bool isMatrixOfInt(const unsigned int _columns = 0u, const unsigned int _rows = 0u, const unsigned int _componentWidth = 0u, const Sign _sign = Sign::Any) const { return isMatrixOf(spv::Op::OpTypeInt, _columns, _rows, _componentWidth, _sign); }

		constexpr bool isSqareMatrix() const { return isMatrix() && m_MatColumnCount == front().getVectorComponentCount(); }
		constexpr bool isSqareMatrixOf(const spv::Op _baseType) const { return isMatrixOf(_baseType) && m_MatColumnCount == front().getVectorComponentCount(); }

		// return 1 if type is a scalar, return component count if type is vector, 0 otherwise
		constexpr unsigned int getScalarOrVectorLength() const { return isScalar() ? 1u : isVector() ? getVectorComponentCount() : 0u; }

		// depth first traversal of type hierarchy using integer indices (static variant), returns the iterator of the last valid type accessed by index
		template<class... Indices>
		Iterator getSubType(const unsigned int _i, Indices... _indices) const;

		// depth first traversal of type hierarchy using integer indices (dynamic variant), returns the iterator of the last valid type accessed by index
		Iterator getSubType(const List<unsigned int>& _indices) const;

		// creates a new empty type from this types allocator
		Type New() const;

		// wraps a copy of this type in a new type of _baseType
		Type wrap(const spv::Op _baseType) const;

		// moves this into wrap type of _baseType
		Type moveWrap(const spv::Op _baseType);

		// wraps a copy of this into a new pointer of this type
		Type wrapPointer(const spv::StorageClass _storageClass = spv::StorageClass::Generic) const;

		// wraps a copy of this into a new vector of _elements
		Type wrapVector(const unsigned int _elements) const;

		// wraps a copy of this column type into a matrix of _columns
		Type wrapMatrix(const unsigned int _columns) const;

		// wraps a copy of this into a new array of _elements
		Type wrapArray(const unsigned int _elements) const;

		// wraps this type into a new struct
		Type wrapStruct() const;

	private:
		spv::Op m_Type = spv::Op::OpTypeVoid; // base type

		union 
		{
			unsigned int m_ImgDepth = 0u;
			unsigned int m_FloatWidth;
			unsigned int m_IntWidth;
			unsigned int m_VecComponentCount;
			unsigned int m_MatColumnCount;
			unsigned int m_ArrayLength;
		};

		bool m_IntSign = false;

		// for OpTypePointer
		spv::StorageClass m_StorageClass = spv::StorageClass::Generic;
		
		// image
		spv::Dim m_ImgDimension = spv::Dim::Max;
		bool m_ImgArray = false;
		bool m_ImgMultiSampled = false;
		SamplerImageAccess m_ImgSamplerAccess = SamplerImageAccess::Unknown;
		spv::ImageFormat m_ImgFormat = spv::ImageFormat::Unknown;

		// image and pipe
		spv::AccessQualifier m_AccessQualifier = spv::AccessQualifier::Max;

		List<Type> m_subTypes;
	};

	inline constexpr Type::Type(IAllocator* _pAllocator, const spv::Op _type) :
		m_Type(_type),
		m_subTypes(_pAllocator)
	{
	}

	inline constexpr const Type& Type::getBaseType() const
	{
		if (m_subTypes.empty())
		{
			return *this;
		}

		return front().getBaseType();
	}

	inline constexpr Type& Type::getBaseType()
	{
		if (m_subTypes.empty())
		{
			return *this;
		}

		return front().getBaseType();
	}

	inline constexpr bool Type::hasSameBase(const Type& _other, const bool _onlyCheckTyeOp) const
	{
		const Type& lBase = getBaseType();
		const Type& rBase = _other.getBaseType();

		return _onlyCheckTyeOp ? lBase.m_Type == rBase.m_Type : lBase == rBase;
	}

	// more decls
	struct dyn_array_t { Type elementType; unsigned int length; struct dyntype_desc_tag {};};
	struct dyn_runtime_array_t { Type elementType; struct dyntype_desc_tag {};};

	//template <class S, class T = stdrep::remove_cv_t<stdrep::remove_reference_t<S>>>
	template<class, class = stdrep::void_t<> >
	struct is_dyntype_desc : stdrep::false_type { };

	template<class T>
	struct is_dyntype_desc<T, stdrep::void_t<typename T::dyntype_desc_tag>> : stdrep::true_type { };

	template <class T>
	constexpr bool is_dyntype_desc_v = is_dyntype_desc<traits::remove_cvref_ptr_t<T>>::value;

	template<class, class = stdrep::void_t<>>
	struct is_array : stdrep::false_type {};
	template<class T>
	struct is_array<T, stdrep::void_t<typename T::array_element_type>> : stdrep::true_type {};
	template<class T>
	constexpr bool is_array_v = is_array<T>::value;

	template<class, class = stdrep::void_t<>>
	struct is_vector: stdrep::false_type {};
	template<class T>
	struct is_vector<T, stdrep::void_t<typename T::vec_element_type>> : stdrep::true_type {};
	template<class T>
	constexpr bool is_vector_v = is_vector<T>::value;

	template<class, class = stdrep::void_t<>>
	struct is_matrix : stdrep::false_type{};
	template<class T>
	struct is_matrix<T, stdrep::void_t<typename T::mat_column_type>> : stdrep::true_type {};
	template<class T>
	constexpr bool is_matrix_v = is_matrix<T>::value;

#pragma region const_types
	template <class T>
	struct const_null_t
	{
		using const_null_type = T;
	};

	template<class, class = stdrep::void_t<>>
	struct is_const_null : stdrep::false_type {};
	template<class T>
	struct is_const_null<T, stdrep::void_t<typename T::const_null_type>> : stdrep::true_type {};
	template<class T>
	constexpr bool is_const_null_v = is_const_null<T>::value;

	struct const_sampler_t
	{
		using const_sampler_type = sampler_t;
		spv::SamplerAddressingMode addressMode = spv::SamplerAddressingMode::None;
		ConstantSamplerCoordMode coordMode = ConstantSamplerCoordMode::UnNormalized;
		spv::SamplerFilterMode filterMode = spv::SamplerFilterMode::Nearest;
	};

	template<class, class = stdrep::void_t<>>
	struct is_const_sampler : stdrep::false_type {};
	template<class T>
	struct is_const_sampler<T, stdrep::void_t<typename T::const_sampler_type>> : stdrep::true_type {};
	template<class T>
	constexpr bool is_const_sampler_v = is_const_sampler<T>::value;

	template <class T, unsigned int N>
	struct const_vector_t
	{
		using const_vector_type = vector_t<T, N>;
		using element_type = T;
		static constexpr unsigned int Elements = N;
		T data[N]{};
	};

	template<class, class = stdrep::void_t<>>
	struct is_const_vector : stdrep::false_type {};
	template<class T>
	struct is_const_vector<T, stdrep::void_t<typename T::const_vector_type>> : stdrep::true_type {};
	template<class T>
	constexpr bool is_const_vector_v = is_const_vector<T>::value;

	template <class T, class ...Elems>
	auto make_vector(T&& first, T&& second, Elems&& ... _elements) {
		return const_vector_t<traits::remove_cvref_t<T>, 2 + sizeof...(_elements)>{stdrep::forward<T>(first), stdrep::forward<T>(second), stdrep::forward<Elems>(_elements)...};
	}

	template <class T, unsigned int N>
	auto make_vector(const T (&val)[N]) {
		const_vector_t<traits::remove_cvref_t<T>, N> v;
		for (auto i = 0u; i < N; ++i)
		{
			v.data[i] = val[i];
		}
		return v;
	}

	template <class T, unsigned int _Columns, unsigned int _Rows>
	struct const_matrix_t
	{
		using const_matrix_type = matrix_t<T, _Columns, _Rows>;
		using element_type = T;
		static constexpr unsigned int Columns = _Columns;
		static constexpr unsigned int Rows = _Rows;
		const_vector_t<T, Rows> data[Columns]{}; // columns
	};

	template<class, class = stdrep::void_t<>>
	struct is_const_matrix : stdrep::false_type {};
	template<class T>
	struct is_const_matrix<T, stdrep::void_t<typename T::const_matrix_type>> : stdrep::true_type {};
	template<class T>
	constexpr bool is_const_matrix_v = is_const_matrix<T>::value;

	template <class T, unsigned int Rows, class ...Columns>
	auto make_matrix(const_vector_t<T, Rows> col0, Columns ... _columns) {
		return const_matrix_t<traits::remove_cvref_t<T>, 1 + sizeof...(_columns), Rows>{col0, _columns...};
	}

	template <class T, unsigned int Columns, unsigned int Rows>
	auto make_matrix(const T(&val)[Columns][Rows]) {
		const_matrix_t<traits::remove_cvref_t<T>, Columns, Rows> m;
		for (auto c = 0u; c < Columns; ++c)
		{
			for (auto r = 0u; r < Rows; ++r)
			{
				m.data[c].data[r] = val[c][r];
			}
		}
		return m;
	}

	template <class T, unsigned int N>
	struct const_array_t
	{
		using const_array_type = array_t<T, N>;
		using element_type = T;
		static constexpr unsigned int Elements = N;
		T data[N]{};
	};

	template<class, class = stdrep::void_t<>>
	struct is_const_array : stdrep::false_type {};
	template<class T>
	struct is_const_array<T, stdrep::void_t<typename T::const_array_type>> : stdrep::true_type {};
	template<class T>
	constexpr bool is_const_array_v = is_const_array<T>::value;

	template <class T, unsigned int N>
	auto make_array(const T(&val)[N]) {
		const_array_t<traits::remove_cvref_t<T>, N> a;
		for (auto i = 0u; i < N; ++i)
		{
			a.data[i] = val[i];
		}
		return a;
	}

	template <class T, class ...Elems>
	auto make_array(T&& first, T&& second, Elems&& ... _elements) {
		return const_array_t<traits::remove_cvref_t<T>, 2 + sizeof...(_elements)>{stdrep::forward<T>(first), stdrep::forward<T>(second), stdrep::forward<Elems>(_elements)...};
	}
#pragma endregion

	template <>
	struct Hasher<Type>
	{
		constexpr Hash64 operator()(const Type& _type, Hash64 _seed) const
		{
			FNV1aHasher h(_seed);
			return operator()(_type, h);
		}

		constexpr Hash64 operator()(const Type& _type, FNV1aHasher& _hasher) const
		{
			_hasher << _type.getType();
			_hasher << _type.getIntWidth(); // image depth, float width
			_hasher << _type.getIntSign(); // float sign
			_hasher << _type.getStorageClass(); // pointer
			_hasher << _type.getImageDimension();
			_hasher << _type.getImageArray();
			_hasher << _type.getImageMultiSampled();
			_hasher << _type.getImageSamplerAccess();
			_hasher << _type.getImageFormat();
			_hasher << _type.getAccessQualifier();
				
			for (const Type& sub : _type.getSubTypes()) {
				operator()(sub, _hasher); // go deeper
			}

			return _hasher;
		}
	};

	template<class ...Indices>
	inline List<Type>::Iterator Type::getSubType(const unsigned int _i, Indices ..._indices) const
	{
		auto it = m_subTypes.begin() + (_i < m_subTypes.size() ? _i : 0u);

		if constexpr (sizeof...(_indices) > 0)
		{
			if (it != nullptr && it->m_subTypes.empty() == false)
			{
				return it->getSubType(_indices...);
			}
		}

		return it;
	}

	template<class Prop, class ...Props>
	inline void Type::setProperties([[maybe_unused]] const Prop& _first, const Props& ..._props)
	{
		// check for properties first
		if constexpr (stdrep::is_same_v<Prop, spv::StorageClass>)
		{
			m_StorageClass = _first;
		}
		if constexpr (stdrep::is_same_v<Prop, spv::Dim>)
		{
			m_ImgDimension = _first;
		}
		else if constexpr (stdrep::is_same_v<Prop, spv::Op>)
		{
			m_Type = _first;
		}
		else if constexpr (stdrep::is_same_v<Prop, spv::AccessQualifier>)
		{
			m_AccessQualifier = _first;
		}
		else if constexpr (stdrep::is_same_v<Prop, SamplerImageAccess>)
		{
			m_ImgSamplerAccess = _first;
		}
		else if constexpr (stdrep::is_same_v<Prop, spv::ImageFormat>)
		{
			m_ImgFormat = _first;
		}
		else if constexpr (stdrep::is_same_v<Prop, Type>)
		{
			m_subTypes.emplace_back(_first);
		}

		if constexpr (sizeof...(_props) > 0)
		{
			setProperties(_props...);
		}
	}

	template<class T, class ...Props>
	inline Type& Type::make(const Props& ..._props)
	{
		if constexpr (sizeof...(_props) > 0)
		{
			setProperties(_props...);
		}

		// first process types that need to be unwraped (non dynamic composite types)
		if constexpr (stdrep::is_pointer_v<T>)
		{
			using S = stdrep::remove_pointer_t<T>;
			if (const S* dyn = traits::selectTypeFromArgs<S>(_props...); dyn != nullptr)
			{
				Pointer(m_StorageClass).Member().make<S>(*dyn);
			}
			else
			{
				Pointer(m_StorageClass).Member().make<S>();
			}
		}
		else if constexpr (is_array_v<T>)
		{
			Array(T::Elements).Member().template make<typename T::array_element_type>();
		}
		else if constexpr (is_const_array_v<T>)
		{
			make<typename T::const_array_type>();
		}
		else if constexpr (is_vector_v<T>)
		{
			Vector(T::Elements).Member().template make<typename T::vec_element_type>();
		}
		else if constexpr (is_const_vector_v<T>)
		{
			make<typename T::const_vector_type>();
		}
		else if constexpr(is_matrix_v<T>)
		{
			Matrix(T::Columns).Member().template make<typename T::mat_column_type>();
		}
		else if constexpr (is_const_matrix_v<T>)
		{
			make<typename T::const_matrix_type>();
		}
		else if constexpr (is_const_sampler_v<T>)
		{
			make<typename T::const_sampler_type>();
		}
		else if constexpr (is_const_null_v<T>)
		{
			make<typename T::const_null_type>();
		}
		else
		{
			fundamental<T>(traits::selectTypeFromArgs<T>(_props...));
		}

		return *this;
	}

	template <>
	inline Type& Type::fundamental<sampler_t>(const sampler_t*) { return Sampler(); }

	template <>
	inline Type& Type::fundamental<dyn_sampled_image_t>(const dyn_sampled_image_t* _prop)
	{
		return  _prop == nullptr ? SampledImage(nullptr) :  SampledImage(*_prop);
	}

	template <>
	inline Type& Type::fundamental<dyn_image_t>(const dyn_image_t* _prop)
	{
		return _prop == nullptr ? Image() : Image(*_prop);
	}

	template <>
	inline Type& Type::fundamental<event_t>(const event_t*) { return Event(); }

	template <>
	inline Type& Type::fundamental<device_event_t>(const device_event_t*) { return DeviceEvent(); }

	template <>
	inline Type& Type::fundamental<reserve_id_t>(const reserve_id_t*) { return ReserveId(); }

	template <>
	inline Type& Type::fundamental<queue_t>(const queue_t*) { return Queue(); }

	template <>
	inline Type& Type::fundamental<pipe_t>(const pipe_t*) { return Pipe(); }

	template <>
	inline Type& Type::fundamental<pipe_storage_t>(const pipe_storage_t*) { return PipeStorage(); }

	template <>
	inline Type& Type::fundamental<named_barrier_t>(const named_barrier_t*) { return NamedBarrier(); }

	template <>
	inline Type& Type::fundamental<ray_query_khr_t>(const ray_query_khr_t*) { return RayQueryKHR(); }

	template <>
	inline Type& Type::fundamental<acceleration_structure_khr_t>(const acceleration_structure_khr_t*) { return AccelerationStructureKHR(); }

	template <>
	inline Type& Type::fundamental<dyn_scalar_t>(const dyn_scalar_t* _prop)
	{
		return _prop == nullptr ? Void() : Scalar(_prop->baseType, _prop->bits, _prop->sign);
	}

	template <>
	inline Type& Type::fundamental<dyn_array_t>(const dyn_array_t* _prop)
	{ 
		return _prop == nullptr ? Array(0) : Array(_prop->length, &_prop->elementType);
	}

	template <>
	inline Type& Type::fundamental<dyn_runtime_array_t>(const dyn_runtime_array_t* _prop)
	{
		return RuntimeArray(_prop == nullptr ? nullptr : &_prop->elementType);
	}

	template <>
	inline Type& Type::fundamental<dyn_vector_t>(const dyn_vector_t* _prop)
	{
		return _prop == nullptr ? Vector(0) : Vector(*_prop);
	}

	template <>
	inline Type& Type::fundamental<dyn_matrix_t>(const dyn_matrix_t* _prop)
	{
		return _prop == nullptr ? Matrix(0) : Matrix(*_prop);
	}

	template <>
	inline Type& Type::fundamental<void>(const void*) { return Void(); }

	template <>
	inline Type& Type::fundamental<bool>(const bool*) { return Bool(); }

	template <>
	inline Type& Type::fundamental<char>(const char*) { return Int(8u); }

	template <>
	inline Type& Type::fundamental<unsigned char>(const unsigned char*) { return UInt(8u); }

	template <>
	inline Type& Type::fundamental<short>(const short*) { return Int(16u); }

	template <>
	inline Type& Type::fundamental<unsigned short>(const unsigned short*) { return UInt(16u); }
	
	template <>
	inline Type& Type::fundamental<int>(const int*) { return Int(); }

	template <>
	inline Type& Type::fundamental<unsigned int>(const unsigned int*) { return UInt(); }

	template <>
	inline Type& Type::fundamental<long>(const long*) { return Int(); }

	template <>
	inline Type& Type::fundamental<unsigned long>(const unsigned long*) { return UInt(); }

	template <>
	inline Type& Type::fundamental<long long>(const long long*) { return Int(64u); }

	template <>
	inline Type& Type::fundamental<unsigned long long>(const unsigned long long*) { return UInt(64u); }

	template <>
	inline Type& Type::fundamental<float>(const float*) { return Float(); }

	template <>
	inline Type& Type::fundamental<double>(const double*) { return Double(); }
} // !spvgentwo