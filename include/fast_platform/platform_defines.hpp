#pragma once

#include <cstdlib>
#include <cstdio>

#include "platform_types.hpp"

#define FPL_ABORT()				(void)(abort())
#define FPL_ABORT_MSG(fmt, ...) (void)(fprintf(stderr, fmt, ##__VA_ARGS__), FPL_ABORT())

#if		!defined(NDEBUG)
	#define FPL_PLATFORM_DEBUG		1
#else
	#define FPL_PLATFORM_DEBUG		0
#endif

#define FPL_PLATFORM_RELEASE		(Bool)(!FPL_PLATFORM_DEBUG)

#if		defined(_WIN32)
	#define FPL_PLATFORM_WINDOWS	1
#elif	defined(__unix)
	#define FPL_PLATFORM_LINUX		1
#endif

#if 	defined(_MSC_VER)
	#define FPL_COMPILER_MSVC 		1
#elif 	defined(__GNUC__) || defined(__clang__)
	#define FPL_COMPILER_GCC_CLANG	1
#endif

#if 	FPL_PLATFORM_DEBUG
	#include <cassert>
	#define FPL_ASSERT(expr)		(void)(assert(expr))
#else
	#define FPL_ASSERT(expr)
#endif

#if 	FPL_COMPILER_MSVC
	#include <sal.h>
	#define FPL_CHECK_RESULT		_Check_return_
	#define FPL_ALIGN_TYPE(size)	__declspec(alignas(size))
	#define FPL_FORCE_INLINE		__forceinline
#elif 	FPL_COMPILER_GCC_CLANG
	#define FPL_CHECK_RESULT		__attribute__((warn_unused_result))
	#define FPL_ALIGN_TYPE(size)	__attribute__((aligned(size)))
	#define	FPL_FORCE_INLINE		__attribute__((always_inline)) inline
#else
	#define FPL_CHECK_RESULT
	#define FPL_ALIGN_TYPE(size)	alignas(size)
	#define	FPL_FORCE_INLINE		inline
#endif
