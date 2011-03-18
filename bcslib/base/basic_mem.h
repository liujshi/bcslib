/**
 * @file basic_mem.h
 *
 * Basic facilities for memory management
 * 
 * @author Dahua Lin
 */

#ifndef BCSLIB_BASIC_MEM_H
#define BCSLIB_BASIC_MEM_H

#include <bcslib/base/config.h>
#include <bcslib/base/basic_defs.h>
#include <cstring>
#include <memory>

namespace bcs
{

    template<typename T>
    inline void copy_elements(const T *src, T *dst, size_t n)
    {
            std::memcpy(dst, src, sizeof(T) * n);
    }


    template<typename T>
    inline bool elements_equal(const T *a, const T *b, size_t n)
    {
            return std::memcmp(a, b, sizeof(T) * n) == 0;
    }

    template<typename T>
    inline void set_zeros_to_elements(T *dst, size_t n)
    {
            std::memset(dst, 0, sizeof(T) * n);
    }

    template<typename T>
    inline void fill_elements(T *dst, size_t n, const T& v)
    {
            for (size_t i = 0; i < n; ++i) dst[i] = v;
    }


    /**
     *  The class to refer to a block of read/write memory that
     *  it takes care of its management by itself
     */
    template<typename T, typename TAlloc = std::allocator<T> >
	class block
	{
	public:
		typedef T value_type;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;

		typedef T* pointer;
		typedef T& reference;
		typedef const T* const_pointer;
		typedef const T& const_reference;

		typedef TAlloc allocator_type;

	public:
		block(size_type n) :
			m_base(_alloc.allocate(n)), m_n(n)
		{
		}

		~block()
		{
			_alloc.deallocate(this->pbase(), this->nelems());
		}

		size_type nelems() const
		{
			return m_n;
		}

		const_pointer pbase() const
		{
			return m_base;
		}

		pointer pbase()
		{
			return m_base;
		}

		const_pointer pend() const
		{
			return m_base + m_n;
		}

		pointer pend()
		{
			return m_base + m_n;
		}

		const_reference operator[](difference_type i) const
		{
			return m_base[i];
		}

		reference operator[](difference_type i)
		{
			return m_base[i];
		}

	private:
		block(const block<T>&);
		block<T>& operator =(const block<T>&);

	private:
		pointer m_base;
		size_type m_n;

		allocator_type _alloc;

	}; // end class block

}


#endif 
