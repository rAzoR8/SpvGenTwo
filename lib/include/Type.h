#pragma once

#include "List.h"
#include "SpvDefines.h"
#include "Hasher.h"

namespace spvgentwo
{
	// forward decls
	class IAllocator;
	//class Instruction;

	class Type
	{
	public:
		using Iterator = List<Type>::Iterator;

		Type(IAllocator* _pAllocator, Type* _pParent = nullptr);
		Type(Type&& _other) noexcept;
		Type(const Type& _other);
		~Type();

		Type& operator=(Type&& _other) noexcept;
		Type& operator=(const Type& _other);

		bool operator==(const Type& _other) const;
		bool operator!=(const Type& _other) const { return !operator==(_other); }

		void reset();

		spv::Op getBaseType() const { return m_Type; }
		void setBaseType(const spv::Op _type);

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
		void setImageSamplerAccess(const SamplerImageAccess _access) { m_ImgSamplerAccess; }

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

		Type& Event();

		Type& DeviceEvent();

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

	// opaque types
	struct sampler_t {};
	struct sampled_image_t { Type imageType; };
	struct event_t {};
	struct device_event_t {};
	struct reserve_id_t {};
	struct queue_t {};
	struct pipe_storage_t {};
	struct named_barrier_t {};
	struct array_t { Type elementType; unsigned int length; };
	struct runtime_array_t { Type elementType; };

	struct image_t
	{
		Type sampledType;
		spv::Dim dimension = spv::Dim::Max;
		bool array = false;
		bool multiSampled = false;
		SamplerImageAccess samplerAccess = SamplerImageAccess::Unknown;
		spv::ImageFormat format = spv::ImageFormat::Unknown;
		spv::AccessQualifier accessQualier = spv::AccessQualifier::Max;
	};

	template <>
	struct Hasher<Type>
	{
		Hash64 operator()(const Type& _type, FNV1aHasher& _hasher) const
		{
			_hasher << _type.getBaseType();
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

		if constexpr (stdrep::is_same_v<Prop, image_t>)
		{
			return &_first;
		}
		else if constexpr (stdrep::is_same_v<Prop, sampled_image_t>)
		{
			return &_first;
		}
		else if constexpr (stdrep::is_same_v<Prop, array_t>)
		{
			return &_first;
		}
		else if constexpr (stdrep::is_same_v<Prop, runtime_array_t>)
		{
			return &_first;
		}

		return nullptr;
	}

	template<class T, class ...Props>
	inline Type& Type::make(Props ..._props)
	{
		if constexpr (stdrep::is_pointer_v<T>)
		{
			Pointer().Member().make<stdrep::remove_pointer_t<T>>();

			if constexpr (sizeof...(_props) > 0)
			{
				 setProperties(_props...);
			}
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