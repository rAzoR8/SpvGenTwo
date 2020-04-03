#pragma once

#include "spvgentwo/Writer.h"

namespace spvgentwo
{
	template <typename U32Vector>
	class BinaryVectorWriter : public IWriter
	{
	public:
		BinaryVectorWriter(U32Vector& _vector) : m_vector(_vector) {};
		virtual ~BinaryVectorWriter() {};

		long put(unsigned int _word) final;
		void putAt(unsigned int _word, const long _offset) final;

	private:
		U32Vector& m_vector;
	};

	template<typename U32Vector>
	inline long BinaryVectorWriter<U32Vector>::put(unsigned int _word)
	{
		m_vector.emplace_back(_word);
		return static_cast<long>(m_vector.size() * sizeof(unsigned int));
	}

	template<typename U32Vector>
	inline void BinaryVectorWriter<U32Vector>::putAt(unsigned int _word, const long _offset)
	{
		const auto index = _offset / sizeof(unsigned int);
		if (m_vector.size() <= index)
		{
			m_vector.resize(index + 1u);
		}

		m_vector[index] = _word;
	}
} //!spvgentwo
