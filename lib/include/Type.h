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
		Type(Type&& _other) noexcept;
		Type(const Type& _other);
		~Type();

		Type& operator=(Type&& _other) noexcept;
		Type& operator=(const Type& _other);

		bool operator==(const Type& _other) const;
		bool operator!=(const Type& _other) const { return !operator==(_other); }

		spv::Op getBaseType() const { return m_Type; }
		void setBaseType(const spv::Op _type);

		// dimension, bits, elements
		unsigned int getDimension() const { return m_Dimension; }
		bool getSign() const { return m_Sign; } // integer
		const List<Type>& getSubTypes() const { return m_subTypes; }

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

		// makes this a struct
		Type& Struct();

		// makes this an array
		Type& Array(const unsigned int _elements);
		// makes this an array, returns element type
		Type& ArrayElement(const unsigned int _elements) { Array(_elements); return m_subTypes.empty() ? Member() : m_subTypes.front(); }
			   
		// makes this a function
		Type& Function();

		// return top most type
		Type& Top();

		Iterator begin() const { return m_subTypes.begin(); }
		Iterator end() const { return m_subTypes.end(); }

		Type& front() { return m_subTypes.front(); }
		const Type& front() const { return m_subTypes.front(); }

		Type& back() { return m_subTypes.back(); }
		const Type& back() const { return m_subTypes.back(); }

	private:
		spv::Op m_Type = spv::Op::OpTypeVoid; // base type
		Type* m_pParent = nullptr;
		unsigned int m_Dimension = 0u;
		bool m_Sign = false;

		// image
		//bool m_Array = false;
		//bool m_MultiSampled = false;
		// depth tex type
		// sampler access

		List<Type> m_subTypes;
	};

	template <>
	struct Hasher<Type>
	{
		Hash64 operator()(const Type& _type, FNV1aHasher& _hasher) const
		{
			_hasher << _type.getBaseType();
			_hasher << _type.getDimension();
			_hasher << _type.getSign();

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
} // !spvgentwo