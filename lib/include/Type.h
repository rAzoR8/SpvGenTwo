#pragma once

#include "List.h"
#include "SpvDefines.h"

namespace spvgentwo
{
	// forward decls
	class IAllocator;

	class Type
	{
	public:
		Type(IAllocator* _pAllocator, Type* _pParent = nullptr);
		~Type();

		// return new subtype
		Type& Member(); // element ? rename to subtype?

		Type& Parent();

		void setBaseType(const spv::Op _type);

		// makes this a void type
		Type& Void();
		Type& VoidP() { Void(); return Parent(); }
		
		Type& Bool();
		Type& BoolP() { Bool(); return Parent(); }

		Type& Int(const unsigned int _bits = 32u, const bool _sign = true);
		Type& IntP(const unsigned int _bits = 32u, const bool _sign = true) { Int(_bits, _sign); return Parent(); }

		Type& UInt(const unsigned int _bits = 32u) { return Int(_bits, false); }
		Type& UIntP(const unsigned int _bits = 32u) { return IntP(_bits, false); } // return parent

		Type& Float(const unsigned int _bits = 32u);
		Type& FloatP(const unsigned int _bits = 32u) { Float(); return Parent(); }

		// makes this a struct
		Type& Struct();
		// makes this a struct, returns new member
		Type& StructM() { Struct(); return Member(); }

		// makes this an array
		Type& Array(const unsigned int _elements);
		// makes this an array, returns element type
		Type& ArrayM(const unsigned int _elements) { Array(_elements); return Member(); }
			   
		// makes this a function
		Type& Function();
		// make this a function, return 'return type'
		Type& FunctionM() { Function(); return Member(); }

		// return top most type
		Type& Top();

	private:
		Type* m_pParent = nullptr;
		spv::Op m_Type = spv::Op::OpTypeVoid; // base type
		unsigned int m_Dimension = 0u;
		bool m_Sign = false;

		// image
		bool m_Array = false;
		bool m_MultiSampled = false;
		// depth tex type
		// sampler access

		List<Type> m_subTypes;
	};
} // !spvgentwo