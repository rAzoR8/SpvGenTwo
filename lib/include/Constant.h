#pragma once

#include "Type.h"

namespace spvgentwo
{
	class Constant
	{
	public:
		Constant(IAllocator* _pAllocator);
		Constant(const Constant& _other);
		Constant(Constant&& _other) noexcept;
		~Constant();

		Constant& operator=(const Constant& _other);
		Constant& operator=(Constant&& _other) noexcept;

		spv::Op getOperation() const { return m_Operation; }
		const Type& getType() const { return m_Type; }

		const List<unsigned int>& getData() const { return m_literalData; }
		const List<Constant>& getComponents() const { return m_Components; }

		template <class T>
		Constant& make(const T& _value, const bool _spec = false);

	private:
		//Constant* m_pParent = nullptr;
		spv::Op m_Operation = spv::Op::OpConstantNull;
		Type m_Type;

		List<unsigned int> m_literalData;
		List<Constant> m_Components;
	};

	template <class T>
	Constant& Constant::make(const T& _value, const bool _spec)
	{
		// TODO: handle OpConstantNull, OpConstantComposite (vector, matrix), OpConstantSampler, OpSpecConstantOp

		if constexpr (traits::is_primitive_type_v<T>)
		{
			m_Type.fundamental<T>(); // TODO: implement generic make<T> for Type
			appendLiteralsToContainer(m_literalData, _value);
		}

		if constexpr (stdrep::is_same_v<T, bool>)
		{
			m_Operation = _value ? (_spec ? spv::Op::OpSpecConstantTrue : spv::Op::OpConstantTrue) : (_spec ? spv::Op::OpSpecConstantFalse : spv::Op::OpConstantFalse);
		}
		else
		{
			m_Operation = _spec ? spv::Op::OpSpecConstant : spv::Op::OpConstant;
		}

		return *this;
	}

	template <>
	struct Hasher<Constant>
	{
		Hash64 operator()(const Constant& _const, FNV1aHasher& _hasher) const
		{
			_hasher << _const.getOperation();
			Hasher<Type>()(_const.getType(), _hasher);
			for (const auto& l : _const.getData())
			{
				_hasher << l;
			}

			for (const Constant& component : _const.getComponents())
			{
				operator()(component, _hasher);
			}

			return _hasher;
		}

		Hash64 operator()(const Constant& _const) const
		{
			FNV1aHasher hasher;
			return operator()(_const, hasher);
		}
	};
} // !spvgentwo