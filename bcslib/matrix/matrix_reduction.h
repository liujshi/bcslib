/**
 * @file matrix_redux.h
 *
 * The matrix reduction functions
 *
 * @author Dahua Lin
 */

#ifdef _MSC_VER
#pragma once
#endif

#ifndef BCSLIB_MATRIX_REDUCTION_H_
#define BCSLIB_MATRIX_REDUCTION_H_

#include <bcslib/matrix/bits/matrix_reduction_internal.h>
#include <bcslib/math/basic_reductors.h>

namespace bcs
{

	/********************************************
	 *
	 *  Generic full-reduction evaluation
	 *
	 ********************************************/

	template<typename Reductor, class Mat>
	BCS_ENSURE_INLINE
	typename Reductor::result_type
	reduce(const Reductor& reduc,
			const IMatrixXpr<Mat, typename Reductor::argument_type>& A)
	{
#ifdef BCS_USE_STATIC_ASSERT
		static_assert(bcs::is_reductor<Reductor, 1>::value, "Reductor must be a unary reductor");
#endif

		return detail::unary_reduction_eval_helper<Reductor, Mat>::run(reduc, A.derived());
	}

	template<typename Reductor, class LMat, class RMat>
	BCS_ENSURE_INLINE
	typename Reductor::result_type
	reduce(const Reductor& reduc,
			const IMatrixXpr<LMat, typename Reductor::argument_type>& A,
			const IMatrixXpr<RMat, typename Reductor::argument_type>& B)
	{
#ifdef BCS_USE_STATIC_ASSERT
		static_assert(bcs::is_reductor<Reductor, 2>::value, "Reductor must be a binary reductor");
#endif

		check_arg( has_same_size(A, B),
				"The sizes of two operands for binary reduction are inconsistent.");

		return detail::binary_reduction_eval_helper<Reductor, LMat, RMat>::run(reduc, A.derived(), B.derived());
	}



	/********************************************
	 *
	 *  Specific reduction functions
	 *
	 ********************************************/

	// Unary

	template<typename T, class Mat>
	BCS_ENSURE_INLINE
	T sum(const IMatrixXpr<Mat, T>& A)
	{
		return reduce(sum_reductor<T>(), A);
	}

	template<typename T, class Mat>
	BCS_ENSURE_INLINE
	T mean(const IMatrixXpr<Mat, T>& A)
	{
		return reduce(mean_reductor<T>(), A);
	}

	template<typename T, class Mat>
	BCS_ENSURE_INLINE
	T min_val(const IMatrixXpr<Mat, T>& A)
	{
		return reduce(min_reductor<T>(), A);
	}

	template<typename T, class Mat>
	BCS_ENSURE_INLINE
	T max_val(const IMatrixXpr<Mat, T>& A)
	{
		return reduce(max_reductor<T>(), A);
	}

	template<typename T, class Mat>
	BCS_ENSURE_INLINE
	T L1norm(const IMatrixXpr<Mat, T>& A)
	{
		return reduce(L1norm_reductor<T>(), A);
	}

	template<typename T, class Mat>
	BCS_ENSURE_INLINE
	T sqL2norm(const IMatrixXpr<Mat, T>& A)
	{
		return reduce(sqL2norm_reductor<T>(), A);
	}

	template<typename T, class Mat>
	BCS_ENSURE_INLINE
	T L2norm(const IMatrixXpr<Mat, T>& A)
	{
		return reduce(L2norm_reductor<T>(), A);
	}

	template<typename T, class Mat>
	BCS_ENSURE_INLINE
	T Linfnorm(const IMatrixXpr<Mat, T>& A)
	{
		return reduce(Linfnorm_reductor<T>(), A);
	}


	// Binary

	template<typename T, class LMat, class RMat >
	BCS_ENSURE_INLINE
	T dot(const IMatrixXpr<LMat, T>& A, const IMatrixXpr<RMat, T>& B)
	{
		return reduce(dot_reductor<T>(), A, B);
	}

	template<typename T, class LMat, class RMat >
	BCS_ENSURE_INLINE
	T L1norm_diff(const IMatrixXpr<LMat, T>& A, const IMatrixXpr<RMat, T>& B)
	{
		return reduce(L1diffnorm_reductor<T>(), A, B);
	}

	template<typename T, class LMat, class RMat >
	BCS_ENSURE_INLINE
	T sqL2norm_diff(const IMatrixXpr<LMat, T>& A, const IMatrixXpr<RMat, T>& B)
	{
		return reduce(sqL2diffnorm_reductor<T>(), A, B);
	}

	template<typename T, class LMat, class RMat >
	BCS_ENSURE_INLINE
	T L2norm_diff(const IMatrixXpr<LMat, T>& A, const IMatrixXpr<RMat, T>& B)
	{
		return reduce(L2diffnorm_reductor<T>(), A, B);
	}

	template<typename T, class LMat, class RMat >
	BCS_ENSURE_INLINE
	T Linfnorm_diff(const IMatrixXpr<LMat, T>& A, const IMatrixXpr<RMat, T>& B)
	{
		return reduce(Linfdiffnorm_reductor<T>(), A, B);
	}

}

#endif /* MATRIX_REDUX_H_ */
