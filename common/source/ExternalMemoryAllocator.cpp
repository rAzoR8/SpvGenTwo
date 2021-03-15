#include "common/ExternalMemoryAllocator.h"

void* spvgentwo::ExternalMemoryAllocator::allocate(const sgt_size_t _bytes, const unsigned int _aligment)
{
	const auto capacity = static_cast<sgt_size_t>(static_cast<const char*>(m_pEnd) - static_cast<const char*>(m_pCurrent));
	void* ptr = alignPowerOf2(_aligment, _bytes, m_pCurrent, capacity);
	m_pCurrent = static_cast<char*>(m_pCurrent) + _bytes;
	return ptr;
}

void spvgentwo::ExternalMemoryAllocator::deallocate(void* _ptr, const sgt_size_t _bytes)
{
	// _ptr was the previous allocation
	if (static_cast<char*>(_ptr) + _bytes == m_pCurrent)
	{
		m_pCurrent = _ptr;
	}
}
