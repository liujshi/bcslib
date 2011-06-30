/*
 * @file intel_calc.h
 *
 * Implementation of Calcuation functions using Intel IPP and MKL
 *
 * @author Dahua Lin
 */

#ifndef BCSLIB_INTEL_CALC_H_
#define BCSLIB_INTEL_CALC_H_

#include <bcslib/base/basic_defs.h>

#ifdef BCS_ENABLE_INTEL_IPPS
#include <bcslib/extern/ipps_select.h>
#define BCS_IPPS_CALL( statement ) if (n > 0) { ::statement; }
#define BCS_IPPS_STAT_CALL( T, statement ) T s = 0; if (n > 0) { ::statement; } return s;
#endif

#ifdef BCS_ENABLE_MKL_VMS
#include <bcslib/extern/mkl_vml_select.h>
#define BCS_MKL_VMS_CALL( statement ) if (n > 0) { ::statement; }
#endif

namespace bcs
{

#ifdef BCS_ENABLE_INTEL_IPPS

	/********************************************
	 *
	 *  Comparison
	 *
	 *******************************************/

	// max_each

	inline void vec_max_each(size_t n, const double* x1, const double* x2, double *y)
	{
		BCS_IPPS_CALL( ippsMaxEvery_64f(x1, x2, y, (Ipp32u)n) )
	}

	inline void vec_max_each(size_t n, const float* x1, const float* x2, float *y)
	{
		BCS_IPPS_CALL( ippsMaxEvery_32f(x1, x2, y, (Ipp32u)n) )
	}

	// min_each

	inline void vec_min_each(size_t n, const double* x1, const double* x2, double *y)
	{
		BCS_IPPS_CALL( ippsMinEvery_64f(x1, x2, y, (Ipp32u)n) )
	}

	inline void vec_min_each(size_t n, const float* x1, const float* x2, float *y)
	{
		BCS_IPPS_CALL( ippsMinEvery_32f(x1, x2, y, (Ipp32u)n) )
	}


	/********************************************
	 *
	 *  Bounding (Thresholding)
	 *
	 *******************************************/

	// lbound

	inline void vec_lbound(size_t n, const double* x, const double& lb, double *y)
	{
		BCS_IPPS_CALL( ippsThreshold_LT_64f(x, y, (int)n, lb) )
	}

	inline void vec_lbound(size_t n, const float* x, const float& lb, float *y)
	{
		BCS_IPPS_CALL( ippsThreshold_LT_32f(x, y, (int)n, lb) )
	}

	inline void vec_lbound_inplace(size_t n, double* y, const double& lb)
	{
		BCS_IPPS_CALL( ippsThreshold_LT_64f_I(y, (int)n, lb) )
	}

	inline void vec_lbound_inplace(size_t n, float* y, const float& lb)
	{
		BCS_IPPS_CALL( ippsThreshold_LT_32f_I(y, (int)n, lb) )
	}

	// ubound

	inline void vec_ubound(size_t n, const double* x, const double& ub, double *y)
	{
		BCS_IPPS_CALL( ippsThreshold_GT_64f(x, y, (int)n, ub) )
	}

	inline void vec_ubound(size_t n, const float* x, const float& ub, float *y)
	{
		BCS_IPPS_CALL( ippsThreshold_GT_32f(x, y, (int)n, ub) )
	}

	inline void vec_ubound_inplace(size_t n, double* y, const double& ub)
	{
		BCS_IPPS_CALL( ippsThreshold_GT_64f_I(y, (int)n, ub) )
	}

	inline void vec_ubound_inplace(size_t n, float* y, const float& ub)
	{
		BCS_IPPS_CALL( ippsThreshold_GT_32f_I(y, (int)n, ub) )
	}

	// abound

	inline void vec_abound(size_t n, const double* x, const double& ab, double *y)
	{
		BCS_IPPS_CALL( ippsThreshold_GTAbs_64f(x, y, (int)n, ab) )
	}

	inline void vec_abound(size_t n, const float* x, const float& ab, float *y)
	{
		BCS_IPPS_CALL( ippsThreshold_GTAbs_32f(x, y, (int)n, ab) )
	}

	inline void vec_abound_inplace(size_t n, double *y, const double& ab)
	{
		BCS_IPPS_CALL( ippsThreshold_GTAbs_64f_I(y, (int)n, ab) )
	}

	inline void vec_abound_inplace(size_t n, float *y, const float& ab)
	{
		BCS_IPPS_CALL( ippsThreshold_GTAbs_32f_I(y, (int)n, ab) )
	}



	/********************************************
	 *
	 *  Arithmetic Calculation
	 *
	 *******************************************/

	// addition

	inline void vec_add(size_t n, const double *x1, const double *x2, double *y)
	{
		BCS_IPPS_CALL( ippsAdd_64f(x1, x2, y, (int)n) )
	}

	inline void vec_add(size_t n, const float *x1, const float *x2, float *y)
	{
		BCS_IPPS_CALL( ippsAdd_32f(x1, x2, y, (int)n) )
	}

	inline void vec_add(size_t n, const double* x1, const double& x2, double *y)
	{
		BCS_IPPS_CALL( ippsAddC_64f(x1, x2, y, (int)n) )
	}

	inline void vec_add(size_t n, const float* x1, const float& x2, float *y)
	{
		BCS_IPPS_CALL( ippsAddC_32f(x1, x2, y, (int)n) )
	}

	inline void vec_add_inplace(size_t n, double *y, const double *x)
	{
		BCS_IPPS_CALL( ippsAdd_64f_I(x, y, (int)n) )
	}

	inline void vec_add_inplace(size_t n, float *y, const float *x)
	{
		BCS_IPPS_CALL( ippsAdd_32f_I(x, y, (int)n) )
	}

	inline void vec_add_inplace(size_t n, double *y, const double& x)
	{
		BCS_IPPS_CALL( ippsAddC_64f_I(x, y, (int)n) )
	}

	inline void vec_add_inplace(size_t n, float *y, const float& x)
	{
		BCS_IPPS_CALL( ippsAddC_32f_I(x, y, (int)n) )
	}


	// subtraction

	inline void vec_sub(size_t n, const double *x1, const double *x2, double *y)
	{
		BCS_IPPS_CALL( ippsSub_64f(x2, x1, y, (int)n) )
	}

	inline void vec_sub(size_t n, const float *x1, const float *x2, float *y)
	{
		BCS_IPPS_CALL( ippsSub_32f(x2, x1, y, (int)n) )
	}

	inline void vec_sub(size_t n, const double* x1, const double& x2, double *y)
	{
		BCS_IPPS_CALL( ippsSubC_64f(x1, x2, y, (int)n) )
	}

	inline void vec_sub(size_t n, const float* x1, const float& x2, float *y)
	{
		BCS_IPPS_CALL( ippsSubC_32f(x1, x2, y, (int)n) )
	}

	inline void vec_sub(size_t n, const double& x1, const double* x2, double *y)
	{
		BCS_IPPS_CALL( ippsSubCRev_64f(x2, x1, y, (int)n) )
	}

	inline void vec_sub(size_t n, const float& x1, const float* x2, float *y)
	{
		BCS_IPPS_CALL( ippsSubCRev_32f(x2, x1, y, (int)n) )
	}

	inline void vec_sub_inplace(size_t n, double *y, const double *x)
	{
		BCS_IPPS_CALL( ippsSub_64f_I(x, y, (int)n) )
	}

	inline void vec_sub_inplace(size_t n, float *y, const float *x)
	{
		BCS_IPPS_CALL( ippsSub_32f_I(x, y, (int)n) )
	}

	inline void vec_sub_inplace(size_t n, double *y, const double& x)
	{
		BCS_IPPS_CALL( ippsSubC_64f_I(x, y, (int)n) )
	}

	inline void vec_sub_inplace(size_t n, float *y, const float& x)
	{
		BCS_IPPS_CALL( ippsSubC_32f_I(x, y, (int)n) )
	}

	inline void vec_sub_inplace(size_t n, const double& x, double *y)
	{
		BCS_IPPS_CALL( ippsSubCRev_64f_I(x, y, (int)n) )
	}

	inline void vec_sub_inplace(size_t n, const float& x, float *y)
	{
		BCS_IPPS_CALL( ippsSubCRev_32f_I(x, y, (int)n) )
	}


	// multiplication

	inline void vec_mul(size_t n, const double *x1, const double *x2, double *y)
	{
		BCS_IPPS_CALL( ippsMul_64f(x1, x2, y, (int)n) )
	}

	inline void vec_mul(size_t n, const float *x1, const float *x2, float *y)
	{
		BCS_IPPS_CALL( ippsMul_32f(x1, x2, y, (int)n) )
	}

	inline void vec_mul(size_t n, const double* x1, const double& x2, double *y)
	{
		BCS_IPPS_CALL( ippsMulC_64f(x1, x2, y, (int)n) )
	}

	inline void vec_mul(size_t n, const float* x1, const float& x2, float *y)
	{
		BCS_IPPS_CALL( ippsMulC_32f(x1, x2, y, (int)n) )
	}

	inline void vec_mul_inplace(size_t n, double *y, const double *x)
	{
		BCS_IPPS_CALL( ippsMul_64f_I(x, y, (int)n) )
	}

	inline void vec_mul_inplace(size_t n, float *y, const float *x)
	{
		BCS_IPPS_CALL( ippsMul_32f_I(x, y, (int)n) )
	}

	inline void vec_mul_inplace(size_t n, double *y, const double& x)
	{
		BCS_IPPS_CALL( ippsMulC_64f_I(x, y, (int)n) )
	}

	inline void vec_mul_inplace(size_t n, float *y, const float& x)
	{
		BCS_IPPS_CALL( ippsMulC_32f_I(x, y, (int)n) )
	}


	// division

	inline void vec_div(size_t n, const double *x1, const double *x2, double *y)
	{
		BCS_IPPS_CALL( ippsDiv_64f(x2, x1, y, (int)n) )
	}

	inline void vec_div(size_t n, const float *x1, const float *x2, float *y)
	{
		BCS_IPPS_CALL( ippsDiv_32f(x2, x1, y, (int)n) )
	}

	inline void vec_div(size_t n, const double* x1, const double& x2, double *y)
	{
		BCS_IPPS_CALL( ippsDivC_64f(x1, x2, y, (int)n) )
	}

	inline void vec_div(size_t n, const float* x1, const float& x2, float *y)
	{
		BCS_IPPS_CALL( ippsDivC_32f(x1, x2, y, (int)n) )
	}

	inline void vec_div_inplace(size_t n, double *y, const double *x)
	{
		BCS_IPPS_CALL( ippsDiv_64f_I(x, y, (int)n) )
	}

	inline void vec_div_inplace(size_t n, float *y, const float *x)
	{
		BCS_IPPS_CALL( ippsDiv_32f_I(x, y, (int)n) )
	}

	inline void vec_div_inplace(size_t n, double *y, const double& x)
	{
		BCS_IPPS_CALL( ippsDivC_64f_I(x, y, (int)n) )
	}

	inline void vec_div_inplace(size_t n, float *y, const float& x)
	{
		BCS_IPPS_CALL( ippsDivC_32f_I(x, y, (int)n) )
	}


	// negate

	inline void vec_negate(size_t n, const double *x, double *y)
	{
		BCS_IPPS_CALL( ippsSubCRev_64f(x, 0.0, y, (int)n));
	}

	inline void vec_negate(size_t n, const float *x, float *y)
	{
		BCS_IPPS_CALL( ippsSubCRev_32f(x, 0.0f, y, (int)n));
	}

	inline void vec_negate(size_t n, double *y)
	{
		BCS_IPPS_CALL( ippsSubCRev_64f(y, 0.0, y, (int)n));
	}

	inline void vec_negate(size_t n, float *y)
	{
		BCS_IPPS_CALL( ippsSubCRev_32f(y, 0.0f, y, (int)n));
	}


	// absolute value

	inline void vec_abs(size_t n, const double *x, double *y)
	{
		BCS_IPPS_CALL( ippsAbs_64f(x, y, (int)n) )
	}

	inline void vec_abs(size_t n, const float *x, float *y)
	{
		BCS_IPPS_CALL( ippsAbs_32f(x, y, (int)n) )
	}

#endif // BCS_ENABLE_INTEL_IPPS


#ifdef BCS_ENABLE_MKL_VMS

	/********************************************
	 *
	 *  Elementary Functions
	 *
	 *******************************************/

	// power functions

	// sqr

	inline void vec_sqr(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdSqr((int)n, x, y) )
	}

	inline void vec_sqr(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsSqr((int)n, x, y) )
	}

	// sqrt

	inline void vec_sqrt(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdSqrt((int)n, x, y) )
	}

	inline void vec_sqrt(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsSqrt((int)n, x, y) )
	}

	// rcp

	inline void vec_rcp(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdInv((int)n, x, y) )
	}

	inline void vec_rcp(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsInv((int)n, x, y) )
	}

	// rsqrt

	inline void vec_rsqrt(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdInvSqrt((int)n, x, y) )
	}

	inline void vec_rsqrt(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsInvSqrt((int)n, x, y) )
	}

	// pow

	inline void vec_pow(size_t n, const double *x, const double *e, double *y)
	{
		BCS_MKL_VMS_CALL( vdPow((int)n, x, e, y) )
	}

	inline void vec_pow(size_t n, const float *x, const float *e, float *y)
	{
		BCS_MKL_VMS_CALL( vsPow((int)n, x, e, y) )
	}

	inline void vec_pow(size_t n, const double *x, const double& e, double *y)
	{
		BCS_MKL_VMS_CALL( vdPowx((int)n, x, e, y) )
	}

	inline void vec_pow(size_t n, const float *x, const float& e, float *y)
	{
		BCS_MKL_VMS_CALL( vsPowx((int)n, x, e, y) )
	}


	// exponential and logarithm functions

	// exp

	inline void vec_exp(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdExp((int)n, x, y) )
	}

	inline void vec_exp(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsExp((int)n, x, y) )
	}

	// log

	inline void vec_log(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdLn((int)n, x, y) )
	}

	inline void vec_log(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsLn((int)n, x, y) )
	}

	// log10

	inline void vec_log10(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdLog10((int)n, x, y) )
	}

	inline void vec_log10(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsLog10((int)n, x, y) )
	}


	// rounding functions

	// floor

	inline void vec_floor(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdFloor((int)n, x, y) )
	}

	inline void vec_floor(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsFloor((int)n, x, y) )
	}

	// ceil

	inline void vec_ceil(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdCeil((int)n, x, y) )
	}

	inline void vec_ceil(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsCeil((int)n, x, y) )
	}


	// trigonometric functions

	// sin

	inline void vec_sin(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdSin((int)n, x, y) )
	}

	inline void vec_sin(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsSin((int)n, x, y) )
	}

	// cos

	inline void vec_cos(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdCos((int)n, x, y) )
	}

	inline void vec_cos(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsCos((int)n, x, y) )
	}

	// tan

	inline void vec_tan(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdTan((int)n, x, y) )
	}

	inline void vec_tan(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsTan((int)n, x, y) )
	}

	// asin

	inline void vec_asin(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdAsin((int)n, x, y) )
	}

	inline void vec_asin(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsAsin((int)n, x, y) )
	}

	// acos

	inline void vec_acos(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdAcos((int)n, x, y) )
	}

	inline void vec_acos(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsAcos((int)n, x, y) )
	}

	// atan

	inline void vec_atan(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdAtan((int)n, x, y) )
	}

	inline void vec_atan(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsAtan((int)n, x, y) )
	}

	// atan2

	inline void vec_atan2(size_t n, const double *x1, const double *x2, double *y)
	{
		BCS_MKL_VMS_CALL( vdAtan2((int)n, x1, x2, y) )
	}

	inline void vec_atan2(size_t n, const float *x1, const float *x2, float *y)
	{
		BCS_MKL_VMS_CALL( vsAtan2((int)n, x1, x2, y) )
	}


	// hyperbolic functions

	// sinh

	inline void vec_sinh(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdSinh((int)n, x, y) )
	}

	inline void vec_sinh(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsSinh((int)n, x, y) )
	}

	// cosh

	inline void vec_cosh(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdCosh((int)n, x, y) )
	}

	inline void vec_cosh(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsCosh((int)n, x, y) )
	}

	// tanh

	inline void vec_tanh(size_t n, const double *x, double *y)
	{
		BCS_MKL_VMS_CALL( vdTanh((int)n, x, y) )
	}

	inline void vec_tanh(size_t n, const float *x, float *y)
	{
		BCS_MKL_VMS_CALL( vsTanh((int)n, x, y) )
	}


	// others

	// hypot

	inline void vec_hypot(size_t n, const double *x1, const double *x2, double *y)
	{
		BCS_MKL_VMS_CALL( vdHypot((int)n, x1, x2, y) )
	}

	inline void vec_hypot(size_t n, const float *x1, const float *x2, float *y)
	{
		BCS_MKL_VMS_CALL( vsHypot((int)n, x1, x2, y) )
	}

#endif // BCS_ENABLE_MKL_VMS



#ifdef BCS_ENABLE_INTEL_IPPS

	/********************************************
	 *
	 *  Vector Statistics
	 *
	 *******************************************/

	// sum

	inline double vec_sum(size_t n, const double *x)
	{
		BCS_IPPS_STAT_CALL( double, ippsSum_64f(x, (int)n, &s) )
	}

	inline float vec_sum(size_t n, const float *x)
	{
		BCS_IPPS_STAT_CALL( float, ippsSum_32f(x, (int)n, &s, ippAlgHintNone) )
	}

	// dot prod

	inline double vec_dot_prod(size_t n, const double *x, const double *y)
	{
		BCS_IPPS_STAT_CALL( double, ippsDotProd_64f(x, y, (int)n, &s) )
	}

	inline float vec_dot_prod(size_t n, const float *x, const float *y)
	{
		BCS_IPPS_STAT_CALL( float, ippsDotProd_32f(x, y, (int)n, &s) )
	}

	// sum_log

	inline double vec_sum_log(size_t n, const double *x)
	{
		BCS_IPPS_STAT_CALL( double, ippsSumLn_64f(x, (int)n, &s) )
	}

	inline float vec_sum_log(size_t n, const float *x)
	{
		BCS_IPPS_STAT_CALL( float, ippsSumLn_32f(x, (int)n, &s) )
	}

	// mean

	inline double vec_mean(size_t n, const double *x)
	{
		BCS_IPPS_STAT_CALL( double, ippsMean_64f(x, (int)n, &s) )
	}

	inline float vec_mean(size_t n, const float *x)
	{
		BCS_IPPS_STAT_CALL( float, ippsMean_32f(x, (int)n, &s, ippAlgHintNone) )
	}

	// min

	inline double vec_min(size_t n, const double *x)
	{
		check_arg(n > 0, "n must be positive for vec_min.");

		double r;
		ippsMin_64f(x, (int)n, &r);
		return r;
	}

	inline float vec_min(size_t n, const float *x)
	{
		check_arg(n > 0, "n must be positive for vec_min.");

		float r;
		ippsMin_32f(x, (int)n, &r);
		return r;
	}

	// max

	inline double vec_max(size_t n, const double *x)
	{
		check_arg(n > 0, "n must be positive for vec_max.");

		double r;
		ippsMax_64f(x, (int)n, &r);
		return r;
	}

	inline float vec_max(size_t n, const float *x)
	{
		check_arg(n > 0, "n must be positive for vec_max.");

		float r;
		ippsMax_32f(x, (int)n, &r);
		return r;
	}

	// minmax

	inline std::pair<double, double> vec_minmax(size_t n, const double *x)
	{
		check_arg(n > 0, "n must be positive for vec_max.");

		std::pair<double, double> r;
		ippsMinMax_64f(x, (int)n, &(r.first), &(r.second));
		return r;
	}

	inline std::pair<float, float> vec_minmax(size_t n, const float *x)
	{
		check_arg(n > 0, "n must be positive for vec_max.");

		std::pair<float, float> r;
		ippsMinMax_32f(x, (int)n, &(r.first), &(r.second));
		return r;
	}

	// min_index

	inline index_t vec_min_index(size_t n, const double *x)
	{
		check_arg(n > 0, "n must be positive for vec_min.");

		double v;
		int p;
		ippsMinIndx_64f(x, (int)n, &v, &p);
		return p;
	}

	inline index_t vec_min_index(size_t n, const float *x)
	{
		check_arg(n > 0, "n must be positive for vec_min.");

		float v;
		int p;
		ippsMinIndx_32f(x, (int)n, &v, &p);
		return p;
	}


	// max_index

	inline index_t vec_max_index(size_t n, const double *x)
	{
		check_arg(n > 0, "n must be positive for vec_max.");

		double v;
		int p;
		ippsMaxIndx_64f(x, (int)n, &v, &p);
		return p;
	}

	inline index_t vec_max_index(size_t n, const float *x)
	{
		check_arg(n > 0, "n must be positive for vec_max.");

		float v;
		int p;
		ippsMaxIndx_32f(x, (int)n, &v, &p);
		return p;
	}


	// norm L1

	inline double vec_norm_L1(size_t n, const double *x)
	{
		BCS_IPPS_STAT_CALL( double, ippsNorm_L1_64f(x, (int)n, &s) )
	}

	inline float vec_norm_L1(size_t n, const float *x)
	{
		BCS_IPPS_STAT_CALL( float, ippsNorm_L1_32f(x, (int)n, &s) )
	}

	inline double vec_diff_norm_L1(size_t n, const double *x, const double *y)
	{
		BCS_IPPS_STAT_CALL( double, ippsNormDiff_L1_64f(x, y, (int)n, &s) )
	}

	inline float vec_diff_norm_L1(size_t n, const float *x, const float *y)
	{
		BCS_IPPS_STAT_CALL( float, ippsNormDiff_L1_32f(x, y, (int)n, &s) )
	}

	// norm L2

	inline double vec_norm_L2(size_t n, const double *x)
	{
		BCS_IPPS_STAT_CALL( double, ippsNorm_L2_64f(x, (int)n, &s) )
	}

	inline float vec_norm_L2(size_t n, const float *x)
	{
		BCS_IPPS_STAT_CALL( float, ippsNorm_L2_32f(x, (int)n, &s) )
	}

	inline double vec_diff_norm_L2(size_t n, const double *x, const double *y)
	{
		BCS_IPPS_STAT_CALL( double, ippsNormDiff_L2_64f(x, y, (int)n, &s) )
	}

	inline float vec_diff_norm_L2(size_t n, const float *x, const float *y)
	{
		BCS_IPPS_STAT_CALL( float, ippsNormDiff_L2_32f(x, y, (int)n, &s) )
	}


	// sqrsum

	inline double vec_sqrsum(size_t n, const double *x)
	{
		double s = 0;
		if (n > 0)
		{
			ippsNorm_L2_64f(x, (int)n, &s);
		}
		return sqr(s);
	}

	inline float vec_sqrsum(size_t n, const float *x)
	{
		float s = 0;
		if (n > 0)
		{
			ippsNorm_L2_32f(x, (int)n, &s);
		}
		return sqr(s);
	}

	inline double vec_diff_sqrsum(size_t n, const double *x, const double *y)
	{
		double s = 0;
		if (n > 0)
		{
			ippsNormDiff_L2_64f(x, y, (int)n, &s);
		}
		return sqr(s);
	}

	inline float vec_diff_sqrsum(size_t n, const float *x, const float *y)
	{
		float s = 0;
		if (n > 0)
		{
			ippsNormDiff_L2_32f(x, y, (int)n, &s);
		}
		return sqr(s);
	}


	// norm Linf

	inline double vec_norm_Linf(size_t n, const double *x)
	{
		BCS_IPPS_STAT_CALL( double, ippsNorm_Inf_64f(x, (int)n, &s) )
	}

	inline float vec_norm_Linf(size_t n, const float *x)
	{
		BCS_IPPS_STAT_CALL( float, ippsNorm_Inf_32f(x, (int)n, &s) )
	}

	inline double vec_diff_norm_Linf(size_t n, const double *x, const double *y)
	{
		BCS_IPPS_STAT_CALL( double, ippsNormDiff_Inf_64f(x, y, (int)n, &s) )
	}

	inline float vec_diff_norm_Linf(size_t n, const float *x, const float *y)
	{
		BCS_IPPS_STAT_CALL( float, ippsNormDiff_Inf_32f(x, y, (int)n, &s) )
	}


#endif // BCS_ENABLE_INTEL_IPPS


}


#endif