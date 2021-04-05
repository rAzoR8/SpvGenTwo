#pragma once

#include "Type.h"
#include "Operand.h" // for appendLiteralsToContainer
#include "Vector.h"

namespace spvgentwo
{
	class Constant
	{
	public:
		Constant(IAllocator* _pAllocator = nullptr);
		Constant(const Constant& _other);
		Constant(Constant&& _other) noexcept;
		~Constant();

		Constant& operator=(const Constant& _other);
		Constant& operator=(Constant&& _other) noexcept;

		constexpr spv::Op getOperation() const { return m_Operation; }
		void setOperation(const spv::Op _op) { m_Operation = _op; }
		constexpr const Type& getType() const { return m_Type; }
		constexpr Type& getType() { return m_Type; }

		template <class T>
		Type& setType();

		constexpr const Vector<unsigned int>& getData() const { return m_literalData; }
		constexpr Vector<unsigned int>& getData() { return m_literalData; }

		template <class T>
		void addData(const T& _data);

		constexpr const List<Constant>& getComponents() const { return m_Components; }
		constexpr List<Constant>& getComponents() { return m_Components; }

		template <class T>
		Constant& make(const T& _value, const bool _spec = false);

		// adds a new constituent constant
		Constant& Component();

		void reset();

		// get top-level data (would be empty for structs)
		template <class T>
		const T* getDataAs(bool _checkType = true) const;

	private:
		spv::Op m_Operation = spv::Op::OpConstantNull;
		Type m_Type;

		List<Constant> m_Components;
		Vector<unsigned int> m_literalData;
	};

	template<class T>
	inline Type& Constant::setType()
	{
		return m_Type.make<T>();
	}

	template<class T>
	inline void Constant::addData(const T& _data)
	{
		m_literalData.reserve(m_literalData.size() + wordCount<T>());
		appendLiteralsToContainer(m_literalData, _data);
	}

	template <class T>
	Constant& Constant::make(const T& _value, const bool _spec)
	{
		if constexpr (stdrep::is_same_v<T, bool>)
		{
			m_Operation = _value ? (_spec ? spv::Op::OpSpecConstantTrue : spv::Op::OpConstantTrue) : (_spec ? spv::Op::OpSpecConstantFalse : spv::Op::OpConstantFalse);
			m_Type.make<bool>();
			addData(_value);
		}
		else if constexpr (traits::is_primitive_type_v<traits::remove_cvref_t<T>>)
		{
			m_Operation = _spec ? spv::Op::OpSpecConstant : spv::Op::OpConstant;
			m_Type.make<T>();
			addData(_value);
		}
		else if constexpr (is_const_null_v<T>)
		{
			m_Type.make<typename T::const_null_type>();
			m_Operation = spv::Op::OpConstantNull; // no literal data
		}
		else if constexpr (is_const_array_v<T>)
		{
			m_Operation = _spec ? spv::Op::OpSpecConstantComposite : spv::Op::OpConstantComposite;
			m_Type.make<typename T::const_array_type>();
			for (unsigned int i = 0u; i < T::Elements; ++i)
			{
				Component().make(_value.data[i]);
			}
		}
		else if constexpr (is_const_vector_v<T>)
		{
			m_Operation = _spec ? spv::Op::OpSpecConstantComposite : spv::Op::OpConstantComposite;
			m_Type.make<typename T::const_vector_type>();
			for (unsigned int i = 0u; i < T::Elements; ++i)
			{
				Component().make(_value.data[i]);
			}
		}
		else if constexpr (is_const_matrix_v<T>)
		{
			m_Operation = _spec ? spv::Op::OpSpecConstantComposite : spv::Op::OpConstantComposite;
			m_Type.make<typename T::const_matrix_type>();
			for (unsigned int i = 0u; i < T::Columns; ++i)
			{
				Component().make(_value.data[i]);
			}
		}
		else if constexpr(is_const_sampler_v<T>)
		{
			m_Operation = spv::Op::OpConstantSampler;
			m_Type.make<typename T::const_sampler_type>();
			addData(_value.addressMode);
			addData(_value.coordMode);
			addData(_value.filterMode);
		}
		else
		{
			// required for clang which can't deduce that this code is unreachable for supported type instantiation
			constexpr bool match =
				stdrep::is_same_v<T, bool> ||
				traits::is_primitive_type_v<traits::remove_cvref_t<T>> ||
				is_const_null_v<T> ||
				is_const_array_v<T> ||
				is_const_vector_v<T> ||
				is_const_matrix_v<T> ||
				is_const_sampler_v<T>;

			static_assert(match, "Could not match type");
		}

		return *this;
	}

	template<class T>
	inline const T* Constant::getDataAs(bool _checkType) const
	{
		if (sizeof(T) <= m_literalData.size() * sizeof(unsigned int)) 
		{
			if (_checkType) 
			{
				Type t(m_literalData.getAllocator());
				if (t.make<T>() != m_Type)
				{
					return nullptr;
				}
			}

			return reinterpret_cast<const T*>(m_literalData.data());
		}
		return nullptr;
	}

	template <>
	struct Hasher<Constant>
	{
		constexpr Hash64 operator()(const Constant& _const, Hash64 _seed) const
		{
			FNV1aHasher hasher(_seed);
			return operator()(_const, hasher);
		}

		constexpr Hash64 operator()(const Constant& _const, FNV1aHasher& _hasher) const
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
	};
} // !spvgentwo