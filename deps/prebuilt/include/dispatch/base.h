/*
 * Copyright (c) 2008-2009 Apple Inc. All rights reserved.
 *
 * @APPLE_APACHE_LICENSE_HEADER_START@
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * @APPLE_APACHE_LICENSE_HEADER_END@
 */

#ifndef __DISPATCH_BASE__
#define __DISPATCH_BASE__

#ifndef __DISPATCH_INDIRECT__
#error "Please #include <dispatch/dispatch.h> instead of this file directly."
#endif

#ifdef __GNUC__
#define DISPATCH_INLINE __attribute__((always_inline)) inline
#elif _MSC_VER
#define DISPATCH_INLINE __forceinline
#endif

#if __GNUC__
#define DISPATCH_EXPORT extern __attribute__((visibility("default")))
#else
#if defined(_WINDLL) // building a DLL
#define DISPATCH_EXPORT extern __declspec(dllexport)
#elif defined(_LIB) // building a static lib
#define DISPATCH_EXPORT extern
#elif defined(USE_DISPATCH_STATIC_LIB) // linking a static lib
#pragma message("Applications must link using /OPT:ICF, COMDAT folding, due to quirks of the Microsoft linker")
#define DISPATCH_EXPORT extern
#else
#define DISPATCH_EXPORT extern __declspec(dllimport)
#endif
#endif

#if defined(__cplusplus)
/*
 * Dispatch objects are NOT C++ objects. Nevertheless, we can at least keep C++
 * aware of type compatibility.
 */
typedef struct dispatch_object_s {
private:
	dispatch_object_s();
	~dispatch_object_s();
	dispatch_object_s(const dispatch_object_s &);
	void operator=(const dispatch_object_s &);
} *dispatch_object_t;
#elif defined(__GNUC__) || defined( WINOBJC )
typedef union {
	struct dispatch_object_s *_do;
	struct dispatch_continuation_s *_dc;
	struct dispatch_queue_s *_dq;
	struct dispatch_queue_attr_s *_dqa;
	struct dispatch_group_s *_dg;
	struct dispatch_source_s *_ds;
	struct dispatch_source_attr_s *_dsa;
	struct dispatch_semaphore_s *_dsema;
} dispatch_object_t __attribute__((transparent_union));

DISPATCH_INLINE dispatch_object_t as_do(dispatch_object_t do_)
{
	return do_;
}
#else
typedef union {
	struct dispatch_object_s *_do;
	struct dispatch_continuation_s *_dc;
	struct dispatch_queue_s *_dq;
	struct dispatch_queue_attr_s *_dqa;
	struct dispatch_group_s *_dg;
	struct dispatch_source_s *_ds;
	struct dispatch_source_attr_s *_dsa;
	struct dispatch_semaphore_s *_dsema;
} dispatch_object_t;

DISPATCH_INLINE dispatch_object_t as_do(void* v)
{
#pragma warning(suppress : 4204) // warning C4204: nonstandard extension used : non-constant aggregate initializer
	dispatch_object_t do_ = { v };
	return do_;
}
#endif

typedef void (*dispatch_function_t)(void *);
typedef void (*dispatch_function_apply_t)(void*, size_t);

#ifdef __cplusplus
#ifdef _MSC_VER
#define DISPATCH_DECL(name) \
__pragma(warning(suppress: 4624)) /* warning C4624: '%s' : destructor could not be generated because a base class destructor is inaccessible */ \
typedef struct name##_s : public dispatch_object_s {} *name##_t
#else
#define DISPATCH_DECL(name) typedef struct name##_s : public dispatch_object_s {} *name##_t
#endif
#else
/*! @parseOnly */
#define DISPATCH_DECL(name) typedef struct name##_s *name##_t
#endif

#ifdef __GNUC__
#define DISPATCH_NORETURN __attribute__((__noreturn__))
#define DISPATCH_NOTHROW __attribute__((__nothrow__))
#define DISPATCH_NONNULL1 __attribute__((__nonnull__(1)))
#define DISPATCH_NONNULL2 __attribute__((__nonnull__(2)))
#define DISPATCH_NONNULL3 __attribute__((__nonnull__(3)))
#define DISPATCH_NONNULL4 __attribute__((__nonnull__(4)))
#define DISPATCH_NONNULL5 __attribute__((__nonnull__(5)))
#define DISPATCH_NONNULL6 __attribute__((__nonnull__(6)))
#define DISPATCH_NONNULL7 __attribute__((__nonnull__(7)))
#if __clang__
// rdar://problem/6857843
#define DISPATCH_NONNULL_ALL
#else
#define DISPATCH_NONNULL_ALL __attribute__((__nonnull__))
#endif
#define DISPATCH_SENTINEL __attribute__((__sentinel__))
#define DISPATCH_PURE __attribute__((__pure__))
#define DISPATCH_WARN_RESULT __attribute__((__warn_unused_result__))
#define DISPATCH_MALLOC __attribute__((__malloc__))
#define DISPATCH_FORMAT(...) __attribute__((__format__(__VA_ARGS__)))
#else
/*! @parseOnly */
#ifdef _MSC_VER
#define DISPATCH_NORETURN __declspec(noreturn)
#else
#define DISPATCH_NORETURN
#endif
/*! @parseOnly */
#define DISPATCH_NOTHROW
/*! @parseOnly */
#define DISPATCH_NONNULL1
/*! @parseOnly */
#define DISPATCH_NONNULL2
/*! @parseOnly */
#define DISPATCH_NONNULL3
/*! @parseOnly */
#define DISPATCH_NONNULL4
/*! @parseOnly */
#define DISPATCH_NONNULL5
/*! @parseOnly */
#define DISPATCH_NONNULL6
/*! @parseOnly */
#define DISPATCH_NONNULL7
/*! @parseOnly */
#define DISPATCH_NONNULL_ALL
/*! @parseOnly */
#define DISPATCH_SENTINEL
/*! @parseOnly */
#define DISPATCH_PURE
/*! @parseOnly */
#define DISPATCH_WARN_RESULT
/*! @parseOnly */
#define DISPATCH_MALLOC
/*! @parseOnly */
#define DISPATCH_FORMAT(...)
#endif

#endif
