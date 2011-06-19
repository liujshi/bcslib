/**
 * @file array_calc.h
 *
 * Vectorized calculation on arrays
 * 
 * @author Dahua Lin
 */

#ifndef BCSLIB_ARRAY_CALC_H
#define BCSLIB_ARRAY_CALC_H

#include <bcslib/array/generic_array_calc.h>

#include <bcslib/array/array1d.h>
#include <bcslib/array/array2d.h>
#include <bcslib/base/arg_check.h>
#include <type_traits>

namespace bcs
{

	/******************************************************
	 *
	 *  add, sub, mul, div, negate
	 *
	 ******************************************************/

	// addition

	// 1D

	template<typename T, class LIndexer, class RIndexer>
	inline array1d<T> operator + (const aview1d<T, LIndexer>& lhs, const aview1d<T, RIndexer>& rhs)
	{
		return add_arr_arr(lhs, rhs);
	}

	template<typename T, class LIndexer>
	inline array1d<T> operator + (const aview1d<T, LIndexer>& lhs, const T& v2)
	{
		return add_arr_sca(lhs, v2);
	}

	template<typename T, class RIndexer>
	inline array1d<T> operator + (const T& lhs, const aview1d<T, RIndexer>& rhs)
	{
		return add_arr_sca(rhs, lhs);
	}

	template<typename T, class LIndexer, class RIndexer>
	inline aview1d<T, LIndexer>& operator += (aview1d<T, LIndexer>& lhs, const aview1d<T, RIndexer>& rhs)
	{
		add_arr_arr_inplace(lhs, rhs);
		return lhs;
	}

	template<typename T, class LIndexer>
	inline aview1d<T, LIndexer>& operator += (aview1d<T, LIndexer>& lhs, const T& rhs)
	{
		add_arr_sca_inplace(lhs, rhs);
		return lhs;
	}

	// 2D

	template<typename T, typename TOrd, class LIndexer0, class LIndexer1, class RIndexer0, class RIndexer1>
	inline array2d<T, TOrd> operator + (
			const aview2d<T, TOrd, LIndexer0, LIndexer1>& lhs,
			const aview2d<T, TOrd, RIndexer0, RIndexer1>& rhs)
	{
		return add_arr_arr(lhs, rhs);
	}

	template<typename T, typename TOrd, class LIndexer0, class LIndexer1>
	inline array2d<T, TOrd> operator + (const aview2d<T, TOrd, LIndexer0, LIndexer1>& lhs, const T& v2)
	{
		return add_arr_sca(lhs, v2);
	}

	template<typename T, typename TOrd, class RIndexer0, class RIndexer1>
	inline array2d<T, TOrd> operator + (const T& lhs, const aview2d<T, TOrd, RIndexer0, RIndexer1>& rhs)
	{
		return add_arr_sca(rhs, lhs);
	}

	template<typename T, typename TOrd, class LIndexer0, class LIndexer1, class RIndexer0, class RIndexer1>
	inline aview2d<T, TOrd, LIndexer0, LIndexer1>& operator += (
			aview2d<T, TOrd, LIndexer0, LIndexer1>& lhs,
			const aview2d<T, TOrd, RIndexer0, RIndexer1>& rhs)
	{
		add_arr_arr_inplace(lhs, rhs);
		return lhs;
	}

	template<typename T, typename TOrd, class LIndexer0, class LIndexer1>
	inline aview2d<T, TOrd, LIndexer0, LIndexer1>& operator += (aview2d<T, TOrd, LIndexer0, LIndexer1>& lhs, const T& rhs)
	{
		add_arr_sca_inplace(lhs, rhs);
		return lhs;
	}



}

#endif 
