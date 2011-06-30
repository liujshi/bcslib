/**
 * @file random_streams.h
 *
 * Random stream classes
 * 
 * @author Dahua Lin
 */

#ifndef BCSLIB_RANDOM_STREAMS_H_
#define BCSLIB_RANDOM_STREAMS_H_

#include <bcslib/base/basic_defs.h>
#include <bcslib/base/mathfun.h>

#include <random>

namespace bcs
{

	/***
	 *
	 *   Random stream classes
	 *   ----------------------
	 *
	 *   1. A random stream is a wrapper of some facility to provide the service of
	 *      generating individual random number of batch of random numbers of
	 *      some classic distributions
	 *
	 *   2. Let rs be a random stream, it should support the following basic
	 *      functionality.
	 *
	 *      Each of the following function following the same name convention:
	 *      <distribution>_<type>: 		for generating individual random number
	 *      <distribution>_<type>_m:	for generating multiple random numbers in one batch
	 *
	 *      For types:
	 *      - i32:	32-bit signed integer number
	 *      - u32:	32-bit unsigned integer number
	 *      - f32:	single-precision floating point number
	 *      - f64:	double-precision floating point number
	 *
	 *		The basic distributions:
	 *
	 *		- Bernoulli distribution with success rate p. If p is omitted, it is considered as 0.5 by default.
	 *		  The value type is bool.
	 *
	 *			bernoulli();
	 *			bernoulli(p);
	 *
	 *			bernoulli_m(n, dst);
	 *			bernoulli_m(n, dst, p);
	 *
	 *      - Uniform integer distribution in [a, b]. If a and b are omitted, the distribution
	 *        is over the entire representable set of the corresponding type.
	 *
	 *      	uniform_i32();
	 *      	uniform_u32();
	 *      	uniform_i32(a, b);
	 *      	uniform_u32(a, b);
	 *
	 *      	uniform_i32_m(n, dst);
	 *      	uniform_u32_m(n, dst);
	 *      	uniform_i32_m(n, dst, a, b);
	 *      	uniform_u32_m(n, dst, a, b);
	 *
	 * 		- Uniform real value distribution in [a, b]. By default a = 0, b = 1.
	 *
	 * 			uniform_f32();
	 * 			uniform_f64();
	 * 			uniform_f32(a, b);
	 * 			uniform_f64(a, b);
	 *
	 * 			uniform_f32_m(n, dst);
	 * 			uniform_f64_m(n, dst);
	 * 			uniform_f32_m(n, dst, a, b);
	 * 			uniform_f64_m(n, dst, a, b);
	 *
	 * 		- Normal distribution with mean = mu, var = sig^2. By default, mu = 0, sig = 1.
	 *
	 * 			normal_f32();
	 * 			normal_f64();
	 * 			normal_f32(mu, sig);
	 * 			normal_f64(mu, sig);
	 *
	 * 			normal_f32(n, dst);
	 * 			normal_f64(n, dst);
	 * 			normal_f32(n, dst, mu, sig);
	 * 			normal_f64(n, dst, mu, sig);
	 *
	 *
	 * 		The more advanced distributions:
	 *
	 * 		- Lognormal distribution. By default mu = 0, sig = 1.
	 *
	 * 			lognormal_f64();
	 * 			lognormal_f64(mu, sig);
	 *
	 * 			lognormal_f64(n, dst);
	 * 			lognormal_f64(n, dst, mu, sig);
	 *
	 * 		- Exponential distribution with scale beta. By default, beta = 1.
	 *
	 * 			exponential_f64();
	 * 			exponential_f64(beta);
	 *
	 * 			exponential_f64_m(n, dst);
	 * 			exponential_f64_m(n, dst, beta);
	 *
	 * 		- Poisson distribution with mean = mu.
	 *
	 * 			poisson_i32(mu);
	 * 			poisson_u32(mu);
	 *
	 * 			poisson_i32(n, dst, mu);
	 * 			poisson_u32(n, dst, mu);
	 *
	 *		- Gamma distribution with shape alpha, and scale beta. By default, beta = 1
	 *
	 *			gamma_f64(alpha);
	 *			gamma_f64(alpha, beta);
	 *
	 *			gamma_f64(n, dst, alpha);
	 *			gamma_f64(n, dst, alpha, beta);
	 *
	 *		- Beta distribution with shape parameter (alpha, beta)
	 *
	 *			beta_f64(alpha, beta);
	 *
	 *			beta_f64(n, dst, alpha, beta);
	 *
	 *		- Weibull distribution with shape parameter alpha, and scale beta. By default beta = 1.
	 *
	 *			weibull_f64(alpha);
	 *			weibull_f64(alpha, beta);
	 *
	 *			weibull_f64(n, dst, alpha);
	 *			weibull_f64(n, dst, alpha, beta);
	 *
	 *		- Geometric distribution with Pr(x = k) = p * (1-p)^k. By default, p = 0.5
	 *
	 *			geometric_i32();
	 *			geometric_u32();
	 *			geometric_i32(p);
	 *			geometric_u32(p);
	 *
	 *			geometric_i32(n, dst);
	 *			geometric_u32(n, dst);
	 *			geometric_i32(n, dst, p);
	 *			geometric_u32(n, dst, p);
	 *
	 *		- Binomial distribution with #trials = k, success rate = p. By default, p = 0.5
	 *
	 *			binomial_i32(k);
	 *			binomial_u32(k);
	 *			binomial_i32(k, p);
	 *			binomial_u32(k, p);
	 *
	 *			binomial_i32(n, dst, k);
	 *			binomial_u32(n, dst, k);
	 *			binomial_i32(n, dst, k, p);
	 *			binomial_u32(n, dst, k, p);
	 *
	 */


}

#endif 
