#pragma once

#include "List.h"
#include "SpvDefines.h"
#include "Hasher.h"

namespace spvgentwo
{
	// forward decls
	class IAllocator;

	class Type
	{
	public:
		using Iterator = List<Type>::Iterator;

		Type(IAllocator* _pAllocator, Type* _pParent = nullptr);
		Type(IAllocator* _pAllocator, const Type& _subType, const spv::Op _baseType);
		Type(IAllocator* _pAllocator, Type&& _subType, const spv::Op _baseType);

		Type(Type&& _other) noexcept;
		Type(const Type& _other);
		~Type();

		Type& operator=(Type&& _other) noexcept;
		Type& operator=(const Type& _other);

		bool operator==(const Type& _other) const;
		bool operator!=(const Type& _other) const { return !operator==(_other); }

		void reset();

		spv::Op getType() const { return m_Type; }
		void setType(const spv::Op _type);

		// get inner most subtype
		const Type& getBaseType() const;
		Type& getBaseType();

		spv::Op getBaseTypeOp() const;

		bool isBaseTypeOf(const spv::Op _type) const;
		bool hasSameBase(const Type& _other, const bool _onlyCheckTyeOp = false) const;

		// dimension, bits, elements
		unsigned int getIntWidth() const { return m_IntWidth; }
		void setIntWidth(const unsigned int _width) { m_IntWidth = _width; }

		unsigned int getFloatWidth() const { return m_FloatWidth; }
		void setFloatWidth(const unsigned int _width) { m_FloatWidth = _width; }

		unsigned int getImageDepth() const { return m_ImgDepth; }
		void setImageDepth(const unsigned int _depth) { m_ImgDepth = _depth; }

		bool getIntSign() const { return m_IntSign; }
		void setIntSign(const bool _sign) { m_IntSign = _sign; }

		spv::Dim getImageDimension() const { return m_ImgDimension; }
		void setImageDimension(const spv::Dim _dim) { m_ImgDimension = _dim; }

		bool getImageArray() const { return m_ImgArray; }
		void setImageArray(const bool _array) { m_ImgArray = _array; }

		bool getImageMultiSampled() const { return m_ImgMultiSampled; }
		void setImageMultiSampled(const bool _ms) { m_ImgMultiSampled = _ms; }

		SamplerImageAccess getImageSamplerAccess() const { return m_ImgSamplerAccess; }
		void setImageSamplerAccess(const SamplerImageAccess _access) { m_ImgSamplerAccess = _access; }

		spv::ImageFormat getImageFormat() const { return m_ImgFormat; }
		void setImageFormat(const spv::ImageFormat _format) { m_ImgFormat = _format; }

		unsigned int getVectorComponentCount() const { return m_VecComponentCount; }
		void setVectorComponentCount(unsigned int _count) { m_VecComponentCount = _count; }

		unsigned int getMatrixColumnCount() const { return m_MatColumnCount; }
		void setMatrixColumnCount(unsigned int _count) { m_MatColumnCount = _count; }

		unsigned int getArrayLength() const { return m_ArrayLength; }
		void setArrayLength(unsigned int _legnth) { m_ArrayLength = _legnth;}

		spv::StorageClass getStorageClass() const { return m_StorageClass; }
		void setStorageClass(const spv::StorageClass _storageClass) { m_StorageClass = _storageClass; }
		
		spv::AccessQualifier getAccessQualifier() const { return m_AccessQualier; }
		void setAccessQualifier(const spv::AccessQualifier _access) { m_AccessQualier = _access; }

		const List<Type>& getSubTypes() const { return m_subTypes; }
		List<Type>& getSubTypes() { return m_subTypes; }

		// return new subtype
		Type& Member(); // element ? rename to subtype?
		Type& Parent();

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
		Type& FloatM(const unsigned int _bits = 32u) { Member().Float(); return *this; }

		Type& Double() { return Float(64u); };
		Type& DoubleM() { Member().Float(44u); return *this; }

		// makes this a struct
		Type& Struct();

		// makes this an array
		Type& Array(const unsigned int _elements, const Type* _elementType = nullptr);
		// makes this an array, returns element type
		Type& ArrayElement(const unsigned int _elements) { Array(_elements); return m_subTypes.empty() ? Member() : m_subTypes.front(); }

		Type& RuntimeArray(const Type* _elementType);

		// makes this a function
		Type& Function();

		// make this a pointer
		Type& Pointer(const spv::StorageClass _storageClass = spv::StorageClass::Generic);
		Type& ForwardPointer(const spv::StorageClass _storageClass = spv::StorageClass::Generic);

		Type& Sampler();

		Type& Image(
			const Type* _pSampledType = nullptr,
			const spv::Dim _dim = spv::Dim::Dim2D,
			const unsigned int _depth = 1u,
			const bool _array = false,
			const bool _multiSampled = false,
			const SamplerImageAccess _sampled = SamplerImageAccess::Unknown,
			const spv::ImageFormat _format = spv::ImageFormat::Unknown,
			const spv::AccessQualifier _access = spv::AccessQualifier::Max);

		Type& SampledImage(const Type* _imageType = nullptr);

		Type& Event();

		Type& DeviceEvent();

		Type& ReserveId();

		Type& Queue();

		Type& PipeStorage();

		Type& NamedBarrier();

		Type& Vector(unsigned int _elements, const Type* _elementType = nullptr);

		// makes this a vector type, returns element type
		Type& VectorElement(unsigned int _elements) { Vector(_elements); return Member(); }

		Type& Matrix(unsigned int _columns, const Type* _columnType = nullptr);

		// makes this a matrix type, returns column type
		Type& MatrixColumn(unsigned int _columns) { Matrix(_columns); return Member(); }
		
		// return top most type
		Type& Top();

		Iterator begin() const { return m_subTypes.begin(); }
		Iterator end() const { return m_subTypes.end(); }

		Type& front() { return m_subTypes.front(); }
		const Type& front() const { return m_subTypes.front(); }

		Type& back() { return m_subTypes.back(); }
		const Type& back() const { return m_subTypes.back(); }

		template <class T>
		Type& fundamental(const T* _typeInfo = nullptr) { static_assert(false, "incompatible type"); return *this; }

		template <class T, class ... Props>
		Type& make(Props ... _props);

		// set Properties by type: unsigned int -> Dimension etc
		template <class Prop, class ...Props>
		const Prop* setProperties(const Prop _first, Props ... _props);

		bool isVoid() const { return m_Type == spv::Op::OpTypeVoid; }
		bool isBool() const { return m_Type == spv::Op::OpTypeBool;	}
		bool isPointer() const { return m_Type == spv::Op::OpTypePointer; }
		bool isStruct() const { return m_Type == spv::Op::OpTypeStruct; }
		bool isArray() const { return m_Type == spv::Op::OpTypeArray; }
		bool isImage() const { return m_Type == spv::Op::OpTypeImage; }
		bool isSampler() const { return m_Type == spv::Op::OpTypeSampler; }
		bool isSampledImage() const { return m_Type == spv::Op::OpTypeSampledImage; }
		bool isVector() const { return m_Type == spv::Op::OpTypeVector; }
		bool isMatrix() const { return m_Type == spv::Op::OpTypeMatrix; }
		bool isInt() const { return m_Type == spv::Op::OpTypeInt; }
		bool isUInt() const { return m_Type == spv::Op::OpTypeInt && m_IntSign == false; }
		bool isSInt() const { return m_Type == spv::Op::OpTypeInt && m_IntSign; }
		bool isFloat() const { return m_Type == spv::Op::OpTypeFloat; }
		bool isF16() const { return m_Type == spv::Op::OpTypeFloat && m_FloatWidth == 16u; }
		bool isF32() const { return m_Type == spv::Op::OpTypeFloat && m_FloatWidth == 32u; }
		bool isF64() const { return m_Type == spv::Op::OpTypeFloat && m_FloatWidth == 64u; }

		bool isScalar() const { return isInt() || isFloat(); }

		bool isVectorOf(const spv::Op _type) const { return isVector() && front().getType() == _type; }
		bool isVectorOfInt() const { return isVector() && front().isInt(); }
		bool isVectorOfSInt() const { return isVector() && front().isSInt(); }
		bool isVectorOfUInt() const { return isVector() && front().isUInt(); }
		bool isVectorOfFloat() const { return isVector() && front().isFloat(); }
		bool isVectorOfScalar() const { return isVector() && front().isScalar(); }

		bool isScalarOrVectorOf(const spv::Op _type) const { return m_Type == _type || isVectorOf(_type); }
		bool hasSameVectorLength(const Type& _other) const { return isVector() && _other.isVector() && m_VecComponentCount == _other.m_VecComponentCount; }
		bool hasSameVectorLength(const Type& _other, const spv::Op _componentType) const { return isVectorOf(_componentType) && _other.isVectorOf(_componentType) && m_VecComponentCount == _other.m_VecComponentCount; }

		template<class... Indices>
		List<Type>::Iterator getSubType(const unsigned int _i, Indices... _indices) const;

		// wraps a copy of this type in a new type of _baseType
		Type wrap(const spv::Op _baseType);

		// moves this into wrap type of _baseType
		Type moveWrap(const spv::Op _baseType);

	private:
		spv::Op m_Type = spv::Op::OpTypeVoid; // base type
		Type* m_pParent = nullptr;

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
		spv::AccessQualifier m_AccessQualier = spv::AccessQualifier::Max;

		List<Type> m_subTypes;
	};

	template<class ...Indices>
	inline List<Type>::Iterator Type::getSubType(const unsigned int _i, Indices ..._indices) const
	{
		auto it = m_subTypes.begin() + _i;
		
		if constexpr (sizeof...(_indices) > 0)
		{
			if (it != nullptr && it->m_subTypes.empty() == false) 
			{
				return it->getSubType(_indices...);
			}
		}
		return it;
	}

	// opaque types
	struct event_t {};
	struct device_event_t {};
	struct reserve_id_t {};
	struct queue_t {};
	struct pipe_storage_t {};
	struct named_barrier_t {};

	struct sampler_t {};
	struct dyn_sampled_image_t { Type imageType; };

	struct dyn_image_t
	{
		Type sampledType;
		spv::Dim dimension = spv::Dim::Max;
		unsigned int depth = 1u;
		bool array = false;
		bool multiSampled = false;
		SamplerImageAccess samplerAccess = SamplerImageAccess::Unknown;
		spv::ImageFormat format = spv::ImageFormat::Unknown;
		spv::AccessQualifier accessQualier = spv::AccessQualifier::Max;
	};

	struct dyn_vector_t { Type elementType; unsigned int elements; };
	struct dyn_matrix_t { Type columnType; unsigned int columns; /*length of the row*/ };
	
	struct dyn_array_t { Type elementType; unsigned int length; };
	struct dyn_runtime_array_t { Type elementType; };

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
	//template <spv::SamplerAddressingMode _addr, ConstantSamplerCoordMode _coord, spv::SamplerFilterMode _filter>
	struct const_sampler_t
	{
		using const_sampler_type = sampler_t;
		spv::SamplerAddressingMode addressMode = spv::SamplerAddressingMode::None;
		ConstantSamplerCoordMode coordMode = ConstantSamplerCoordMode::UnNormalized;
		spv::SamplerFilterMode filterMode = spv::SamplerFilterMode::Nearest;;
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
		T data[N];
	};

	template<class, class = stdrep::void_t<>>
	struct is_const_vector : stdrep::false_type {};
	template<class T>
	struct is_const_vector<T, stdrep::void_t<typename T::const_vector_type>> : stdrep::true_type {};
	template<class T>
	constexpr bool is_const_vector_v = is_const_vector<T>::value;

	template <class T, class ...Elems>
	auto make_vector(T&& val, Elems&& ... _elements) {
		return const_vector_t<traits::remove_cvref_t<T>, 1 + sizeof...(_elements)>{stdrep::forward<T>(val), stdrep::forward<Elems>(_elements)...};
	};

	template <class T, unsigned int _Columns, unsigned int _Rows>
	struct const_matrix_t
	{
		using const_matrix_type = matrix_t<T, _Columns, _Rows>;
		using element_type = T;
		static constexpr unsigned int Columns = _Columns;
		static constexpr unsigned int Rows = _Rows;
		const_vector_t<T, Rows> data[Columns]; // columns
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
	};

	template <class T, unsigned int N>
	struct const_array_t
	{
		using const_array_type = array_t<T, N>;
		using element_type = T;
		static constexpr unsigned int Elements = N;
		T data[N];
	};

	template<class, class = stdrep::void_t<>>
	struct is_const_array : stdrep::false_type {};
	template<class T>
	struct is_const_array<T, stdrep::void_t<typename T::const_array_type>> : stdrep::true_type {};
	template<class T>
	constexpr bool is_const_array_v = is_const_array<T>::value;

	template <class T, class ...Elems>
	auto make_array(T&& val, Elems&& ... _elements) {
		return const_array_t<traits::remove_cvref_t<T>, 1 + sizeof...(_elements)>{stdrep::forward<T>(val), stdrep::forward<Elems>(_elements)...};
	};
#pragma endregion

	template <>
	struct Hasher<Type>
	{
		Hash64 operator()(const Type& _type, FNV1aHasher& _hasher) const
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

		Hash64 operator()(const Type& _type) const
		{
			FNV1aHasher h;
			return operator()(_type, h);
		}
	};

	template<class Prop, class ...Props>
	inline const Prop* Type::setProperties(const Prop _first, Props ..._props)
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
			m_AccessQualier = _first;
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

		// check for dynamic types
		if constexpr (stdrep::is_same_v<Prop, dyn_image_t>)
		{
			return &_first;
		}
		else if constexpr (stdrep::is_same_v<Prop, dyn_sampled_image_t>)
		{
			return &_first;
		}
		else if constexpr (stdrep::is_same_v<Prop, dyn_array_t>)
		{
			return &_first;
		}
		else if constexpr (stdrep::is_same_v<Prop, dyn_runtime_array_t>)
		{
			return &_first;
		}
		else if constexpr (stdrep::is_same_v<Prop, dyn_vector_t>)
		{
			return &_first;
		}
		else if constexpr (stdrep::is_same_v<Prop, dyn_matrix_t>)
		{
			return &_first;
		}

		return nullptr;
	}

	template<class T, class ...Props>
	inline Type& Type::make(Props ..._props)
	{
		// first process types that need to be unwraped (non dynamic composite types)
		if constexpr (stdrep::is_pointer_v<T>)
		{
			Pointer().Member().make<stdrep::remove_pointer_t<T>>();

			if constexpr (sizeof...(_props) > 0)
			{
				 setProperties(_props...);
			}
		}
		else if constexpr (is_array_v<T>)
		{
			Array(T::Elements).Member().make<typename T::array_element_type>();
		}
		else if constexpr (is_const_array_v<T>)
		{
			make<typename T::const_array_type>();
		}
		else if constexpr (is_vector_v<T>)
		{
			Vector(T::Elements).Member().make<typename T::vec_element_type>();
		}
		else if constexpr (is_const_vector_v<T>)
		{
			make<typename T::const_vector_type>();
		}
		else if constexpr(is_matrix_v<T>)
		{
			Matrix(T::Columns).Member().make<typename T::mat_column_type>();
		}
		else if constexpr (is_const_matrix_v<T>)
		{
			make<typename T::const_matrix_type>();
		}
		else if constexpr (is_const_sampler_v<T>)
		{
			make<typename T::const_sampler_type>();
		}
		else
		{
			const void* pProp = nullptr;
			if constexpr (sizeof...(_props) > 0)
			{
				pProp = setProperties(_props...);
			}

			fundamental<T>(reinterpret_cast<const T*>(pProp));
		}

		return *this;
	}

	template <>
	inline Type& Type::fundamental<sampler_t>(const sampler_t*) { return Sampler(); }

	template <>
	inline Type& Type::fundamental<dyn_sampled_image_t>(const dyn_sampled_image_t* _prop)
	{
		return SampledImage(_prop == nullptr ? nullptr : &_prop->imageType);
	}

	template <>
	inline Type& Type::fundamental<dyn_image_t>(const dyn_image_t* _prop)
	{
		if (_prop == nullptr)
		{
			return Image();
		}
		else
		{
			return Image(&_prop->sampledType, _prop->dimension, _prop->depth, _prop->array, _prop->multiSampled, _prop->samplerAccess, _prop->format, _prop->accessQualier);
		}
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
	inline Type& Type::fundamental<pipe_storage_t>(const pipe_storage_t*) { return PipeStorage(); }

	template <>
	inline Type& Type::fundamental<named_barrier_t>(const named_barrier_t*) { return NamedBarrier(); }

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
		return _prop == nullptr ? Vector(0) : Vector(_prop->elements, &_prop->elementType);
	}

	template <>
	inline Type& Type::fundamental<dyn_matrix_t>(const dyn_matrix_t* _prop)
	{
		return _prop == nullptr ? Matrix(0) : Matrix(_prop->columns, &_prop->columnType);
	}

	template <>
	inline Type& Type::fundamental<void>(const void*) { return Void(); }

	template <>
	inline Type& Type::fundamental<bool>(const bool*) { return Bool(); }

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
} // !spvgentwI