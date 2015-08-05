/*
 * Copyright (c) 2008-2011 Apple Inc. All rights reserved.
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

#if __GNUC__
#define DISPATCH_NORETURN __attribute__((__noreturn__))
#define DISPATCH_NOTHROW __attribute__((__nothrow__))
#define DISPATCH_NONNULL1 __attribute__((__nonnull__(1)))
#define DISPATCH_NONNULL2 __attribute__((__nonnull__(2)))
#define DISPATCH_NONNULL3 __attribute__((__nonnull__(3)))
#define DISPATCH_NONNULL4 __attribute__((__nonnull__(4)))
#define DISPATCH_NONNULL5 __attribute__((__nonnull__(5)))
#define DISPATCH_NONNULL6 __attribute__((__nonnull__(6)))
#define DISPATCH_NONNULL7 __attribute__((__nonnull__(7)))
#if __clang__ && __clang_major__ < 3
// rdar://problem/6857843
#define DISPATCH_NONNULL_ALL
#else
#define DISPATCH_NONNULL_ALL __attribute__((__nonnull__))
#endif
#define DISPATCH_SENTINEL __attribute__((__sentinel__))
#define DISPATCH_PURE __attribute__((__pure__))
#define DISPATCH_CONST __attribute__((__const__))
#define DISPATCH_WARN_RESULT __attribute__((__warn_unused_result__))
#define DISPATCH_MALLOC __attribute__((__malloc__))
#define DISPATCH_ALWAYS_INLINE __attribute__((__always_inline__))
#else
/*! @parseOnly */
#define DISPATCH_NORETURN
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
#define DISPATCH_CONST
/*! @parseOnly */
#define DISPATCH_WARN_RESULT
/*! @parseOnly */
#define DISPATCH_MALLOC
/*! @parseOnly */
#define DISPATCH_ALWAYS_INLINE
#endif

#ifndef DISPATCH_IMPEXP
 #define DISPATCH_IMPEXP __declspec(dllimport)
#endif

#ifdef DISPATCH_IMPEXP
 #define DISPATCH_EXPORT DISPATCH_IMPEXP extern
#endif

#ifndef DISPATCH_EXPORT
 #if __GNUC__
  #define DISPATCH_EXPORT extern __attribute__((visibility("default")))
 #else
  #define DISPATCH_EXPORT extern
 #endif
#endif

#if __GNUC__
#define DISPATCH_INLINE static __inline__
#else
#define DISPATCH_INLINE static inline
#endif

#if __GNUC__
#define DISPATCH_EXPECT(x, v) __builtin_expect((x), (v))
#else
#define DISPATCH_EXPECT(x, v) (x)
#endif

typedef void (*dispatch_function_t)(void *);

#endif
