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
		Type(IAllocator* _pAllocator);
		~Type();

		void setBaseType(const spv::Op _type);

		// makes this a void type
		Type& Void();
		
		Type& Bool();

		Type& Int(const unsigned int _bits = 32u, const bool _sign = true);
		Type& UInt(const unsigned int _bits = 32u) { return Int(_bits, false); }

		Type& Float(const unsigned int _bits = 32u);

		// makes this a struct, returns new member
		Type& StructMember();

		// makes this an array, returns inner type
		Type& Array(const unsigned int _elements);

	private:
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