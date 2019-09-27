#pragma once

#include "Type.h"

namespace spvgentwo
{
	class Constant
	{
	public:
		Constant(IAllocator* _pAllocator, Constant* _pParent = nullptr);
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

		Constant& Component();

	private:
		Constant* m_pParent = nullptr;
		spv::Op m_Operation = spv::Op::OpConstantNull;
		Type m_Type;

		List<unsigned int> m_literalData;
		List<Constant> m_Components;
	};

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
		return const_vector_t<remove_cvref_t<T>, 1 + sizeof...(_elements)>{stdrep::forward<T>(val), stdrep::forward<Elems>(_elements)...};
	};

	template <class T, unsigned int C, unsigned int R>
	struct const_matrix_t
	{
		using const_matrix_type = matrix_t<T, C, R>;
		static constexpr unsigned int Columns = C;
		static constexpr unsigned int Rows = R;
		const_vector_t<T,R> data[C]; // columns
	};

	template<class, class = stdrep::void_t<>>
	struct is_const_matrix : stdrep::false_type {};
	template<class T>
	struct is_const_matrix<T, stdrep::void_t<typename T::const_matrix_type>> : stdrep::true_type {};
	template<class T>
	constexpr bool is_const_matrix_v = is_const_matrix<T>::value;

	//template <class T, unsigned int N, class ...Elems>
	//auto make_matrix(const_vector_t<T,N> && val, Elems&& ... _elements) {
	//	return const_matrix_t<remove_cvref_t<T>, 1 + sizeof...(_elements), N>{stdrep::forward<T>(val), stdrep::forward<Elems>(_elements)...};
	//};

	template <class T, unsigned int N>
	struct const_array_t
	{
		using const_array_type = array_t<T, N>;
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
		return const_array_t<remove_cvref_t<T>, 1 + sizeof...(_elements)>{stdrep::forward<T>(val), stdrep::forward<Elems>(_elements)...};
	};

	template <class T>
	Constant& Constant::make(const T& _value, const bool _spec)
	{
		// TODO: handle OpConstantNull, OpSpecConstantOp
		if constexpr (is_const_array_v<T>)
		{
			m_Type.make<typename T::const_array_type>();
			for (unsigned int i = 0u; i < T::Elements; ++i)
			{
				Component().make(_value.data[i]);
			}
		}
		else if constexpr (is_const_vector_v<T>)
		{
			m_Type.make<typename T::const_vector_type>();
			for (unsigned int i = 0u; i < T::Elements; ++i)
			{
				Component().make(_value.data[i]);
			}
		}
		else if constexpr (is_const_matrix_v<T>)
		{
			m_Type.make<typename T::const_matrix_type>();
			for (unsigned int i = 0u; i < T::Columns; ++i)
			{
				Component().make(_value.data[i]);
			}
		}
		else if constexpr(is_const_sampler_v<T>)
		{
			m_Type.make<typename T::const_sampler_type>();
			appendLiteralsToContainer(m_literalData, _value.addressMode);
			appendLiteralsToContainer(m_literalData, _value.coordMode);
			appendLiteralsToContainer(m_literalData, _value.filterMode);
		}
		else
		{
			m_Type.make<T>();			
			appendLiteralsToContainer(m_literalData, _value);
		}

		if constexpr (stdrep::is_same_v<T, bool>)
		{
			m_Operation = _value ? (_spec ? spv::Op::OpSpecConstantTrue : spv::Op::OpConstantTrue) : (_spec ? spv::Op::OpSpecConstantFalse : spv::Op::OpConstantFalse);
		}
		else if constexpr(traits::is_primitive_type_v<T>)
		{
			m_Operation = _spec ? spv::Op::OpSpecConstant : spv::Op::OpConstant;
		}
		else // composite type
		{
			m_Operation = _spec ? spv::Op::OpSpecConstantComposite : spv::Op::OpConstantComposite;
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