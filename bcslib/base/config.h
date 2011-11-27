/**
 * @file config.h
 *
 * The configuration file for Basic Computation Supporting Library
 *
 * @author dhlin
 */

#ifdef _MSC_VER
#pragma once
#endif

#ifndef BCSLIB_CONFIG_H
#define BCSLIB_CONFIG_H

// Platform-specific stuff

#define BCSLIB_MSVC 0x01
#define BCSLIB_GCC 0x02
#define BCSLIB_CLANG 0x03

#define BCS_WINDOWS_INTERFACE 0x11
#define BCS_POSIX_INTERFACE 0x12

#if (defined(_WIN32) || defined(_WIN64)) && defined(_MSC_VER)
	#if _MSC_VER < 1600
		#error Microsoft Visual C++ of version lower than MSVC 2010 is not supported.
	#endif
	#define BCSLIB_COMPILER BCSLIB_MSVC

	#define BCS_PLATFORM_INTERFACE BCS_WINDOWS_INTERFACE

#elif (defined(__GNUC__))
	#if (defined(__clang__))
		#if ((__clang_major__ < 2) || (__clang_major__ == 2 && __clang_minor__ < 1))
			#error CLANG of version lower than 2.1.0 is not supported
		#endif
		#define BCSLIB_COMPILER BCSLIB_CLANG
	#else
		#if ((__GNUC__ < 4) || (__GNUC__ == 4 && __GNUC_MINOR__ < 2))
			#error GCC of version lower than 4.2.0 is not supported
		#endif
		#define BCSLIB_COMPILER BCSLIB_GCC
	#endif

	#define BCS_PLATFORM_INTERFACE BCS_POSIX_INTERFACE

#else
	#error BCSLib can only be used with Microsoft Visual C++, GCC (G++), or clang (clang++).
#endif


#endif

