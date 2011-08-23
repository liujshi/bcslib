/**
 * @file bcs_cuda_test_basics.h
 *
 * Some useful functions for CUDA testing
 * 
 * @author Dahua Lin
 */

#ifndef BCS_CUDA_TEST_BASICS_H_
#define BCS_CUDA_TEST_BASICS_H_

#include <gtest/gtest.h>
#include <bcslib/cuda/cuda_base.h>

namespace bcs { namespace cuda {


	template<typename T>
	class host_scoped_buffer : private noncopyable
	{
	public:
		host_scoped_buffer(size_t n)
		: m_data(new T[n]), m_n(n) { }

		host_scoped_buffer(size_t n, device_cptr<T> a)
		: m_data(new T[n]), m_n(n)
		{
			copy_memory(n, a, make_host_ptr(m_data));
		}

		host_scoped_buffer(size_t m, size_t n, device_cptr<T> a, size_t pitch)
		: m_data(new T[m * n]), m_n(n)
		{
			copy_memory2d(m, n, a, pitch, make_host_ptr(m_data), n * sizeof(T));
		}

		~host_scoped_buffer() { delete[] m_data; }

		T *data() { return m_data; }
		const T *data() const { return m_data; }

		size_t size() const { return m_n; }

	private:
		T *m_data;
		size_t m_n;
	};


	template<typename T>
	__host__ bool verify_device_mem1d(size_t n, device_cptr<T> a, const T *ref)
	{
		host_scoped_buffer<T> buf(n, a);
		const T *b = buf.data();

		for (size_t i = 0; i < n; ++i)
		{
			if (b[i] != ref[i]) return false;
		}

		return true;
	}

	template<typename T>
	__host__ bool verify_host_mem1d(size_t n, host_cptr<T> a, const T *ref)
	{
		const T *b = a.get();

		for (size_t i = 0; i < n; ++i)
		{
			if (b[i] != ref[i]) return false;
		}

		return true;
	}

	template<typename T>
	__host__ bool verify_device_mem2d(size_t m, size_t n, device_cptr<T> a, size_t pitch, const T *ref)
	{
		host_scoped_buffer<T> buf(m, n, a, pitch);
		const T *b = buf.data();

		size_t N = m * n;
		for (size_t i = 0; i < N; ++i)
		{
			if (b[i] != ref[i]) return false;
		}

		return true;
	}

} }


#endif 