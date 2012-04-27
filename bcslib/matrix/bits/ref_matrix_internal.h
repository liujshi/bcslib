/**
 * @file ref_matrix_internal.h
 *
 * The internal implementation of ref_matrix
 *
 * @author Dahua Lin
 */

#ifdef _MSC_VER
#pragma once
#endif

#ifndef BCSLIB_REF_MATRIX_INTERNAL_H_
#define BCSLIB_REF_MATRIX_INTERNAL_H_

#include <bcslib/matrix/matrix_base.h>
#include <bcslib/matrix/bits/matrix_helpers.h>

namespace bcs { namespace detail {

	template<typename T, int CTRows, int CTCols>
	class ref_matrix_internal
	{
	public:
		BCS_ENSURE_INLINE
		ref_matrix_internal(T *pdata, index_t m, index_t n)
		: m_pdata(pdata)
		{
			check_with_compile_time_dims(m == CTRows && n == CTCols);
		}

		BCS_ENSURE_INLINE index_t nrows() const { return CTRows; }

		BCS_ENSURE_INLINE index_t ncolumns() const { return CTCols; }

		BCS_ENSURE_INLINE index_t lead_dim() const { return CTRows; }

		BCS_ENSURE_INLINE T* ptr_data() const { return m_pdata; }

	private:
		T* m_pdata;
	};

	template<typename T, int CTCols>
	class ref_matrix_internal<T, DynamicDim, CTCols>
	{
	public:
		BCS_ENSURE_INLINE
		ref_matrix_internal(T *pdata, index_t m, index_t n)
		: m_pdata(pdata), m_nrows(m)
		{
			check_with_compile_time_dims(n == CTCols);
		}

		BCS_ENSURE_INLINE index_t nrows() const { return m_nrows; }

		BCS_ENSURE_INLINE index_t ncolumns() const { return CTCols; }

		BCS_ENSURE_INLINE index_t lead_dim() const { return m_nrows; }

		BCS_ENSURE_INLINE T* ptr_data() const { return m_pdata; }

	private:
		T* m_pdata;
		index_t m_nrows;
	};


	template<typename T, int CTRows>
	class ref_matrix_internal<T, CTRows, DynamicDim>
	{
	public:
		BCS_ENSURE_INLINE
		ref_matrix_internal(T *pdata, index_t m, index_t n)
		: m_pdata(pdata), m_ncols(n)
		{
			check_with_compile_time_dims(m == CTRows);
		}

		BCS_ENSURE_INLINE index_t nrows() const { return CTRows; }

		BCS_ENSURE_INLINE index_t ncolumns() const { return m_ncols; }

		BCS_ENSURE_INLINE index_t lead_dim() const { return CTRows; }

		BCS_ENSURE_INLINE T* ptr_data() const { return m_pdata; }

	private:
		T* m_pdata;
		index_t m_ncols;
	};


	template<typename T>
	class ref_matrix_internal<T, DynamicDim, DynamicDim>
	{
	public:
		BCS_ENSURE_INLINE
		ref_matrix_internal(T *pdata, index_t m, index_t n)
		: m_pdata(pdata), m_nrows(m), m_ncols(n)
		{
		}

		BCS_ENSURE_INLINE index_t nrows() const { return m_nrows; }

		BCS_ENSURE_INLINE index_t ncolumns() const { return m_ncols; }

		BCS_ENSURE_INLINE index_t lead_dim() const { return m_nrows; }

		BCS_ENSURE_INLINE T* ptr_data() const { return m_pdata; }

	private:
		T* m_pdata;
		index_t m_nrows;
		index_t m_ncols;
	};


} }

#endif /* REF_MATRIX_INTERNAL_H_ */
