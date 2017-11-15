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

/*
 * IMPORTANT: This header file describes INTERNAL interfaces to libdispatch
 * which are subject to change in future releases of Mac OS X. Any applications
 * relying on these interfaces WILL break.
 */

#ifndef __DISPATCH_INTERNAL__
#define __DISPATCH_INTERNAL__

#include "platform/platform.h"

#ifdef __APPLE__
#include <TargetConditionals.h>
#endif

#define __DISPATCH_BUILDING_DISPATCH__
#define __DISPATCH_INDIRECT__

#include "dispatch/dispatch.h"
#include "dispatch/base.h"
#include "dispatch/atomic.h"
#include "dispatch/time.h"
#include "dispatch/queue.h"
#include "dispatch/object.h"
#include "dispatch/source.h"
#include "dispatch/group.h"
#include "dispatch/semaphore.h"
#include "dispatch/once.h"
#include "dispatch/interop.h"
#include "dispatch/benchmark.h"

/* private.h uses #include_next and must be included last to avoid picking
 * up installed headers. */
#include "queue_private.h"
#include "source_private.h"
#include "private.h"

#ifndef DISPATCH_NO_LEGACY
#include "legacy.h"
#endif
/* More #includes at EOF (dependent on the contents of internal.h) ... */

/* The "_debug" library build */
#ifndef DISPATCH_DEBUG
#define DISPATCH_DEBUG 0
#endif

#ifdef __GNUC__
#define DISPATCH_NOINLINE __attribute__((noinline))
#elif _MSC_VER
#define DISPATCH_NOINLINE __declspec(noinline)
#endif

#ifdef __GNUC__
#define DISPATCH_INLINE __attribute__((always_inline)) inline
#elif _MSC_VER
#define DISPATCH_INLINE __forceinline
#endif

#ifdef __GNUC__
#define DISPATCH_UNUSED __attribute__((unused))
#else
#define DISPATCH_UNUSED
#endif

// workaround 6368156
#ifdef NSEC_PER_SEC
#undef NSEC_PER_SEC
#endif
#ifdef USEC_PER_SEC
#undef USEC_PER_SEC
#endif
#ifdef NSEC_PER_USEC
#undef NSEC_PER_USEC
#endif
#define NSEC_PER_SEC 1000000000ull
#define USEC_PER_SEC 1000000ull
#define NSEC_PER_USEC 1000ull

/* I wish we had __builtin_expect_range() */
#if __GNUC__
#define fastpath(x)	((typeof(x))__builtin_expect((long)(x), ~0l))
#define slowpath(x)	((typeof(x))__builtin_expect((long)(x), 0l))
#else
#define fastpath(x) (x)
#define slowpath(x) (x)
#endif

#include "debug.h"

#if __GNUC__
#define DO_CAST(x) ((struct dispatch_object_s *)(x)._do)
#else
#define DO_CAST(x) ((struct dispatch_object_s *)(x))
#endif

#ifdef __BLOCKS__
dispatch_block_t _dispatch_Block_copy(dispatch_block_t block);
void _dispatch_call_block_and_release(void *block);
void _dispatch_call_block_and_release2(void *block, void *ctxt);
#endif /* __BLOCKS__ */

void dummy_function(void);
long dummy_function_r0(void);

uint64_t _dispatch_get_nanoseconds(void);

#ifndef DISPATCH_NO_LEGACY
dispatch_source_t
_dispatch_source_create2(dispatch_source_t ds,
	dispatch_source_attr_t attr,
	void *context,
	dispatch_source_handler_function_t handler);
#endif

void _dispatch_run_timers(void);
// Returns howsoon with updated time value, or NULL if no timers active.
struct timespec *_dispatch_get_next_timer_fire(struct timespec *howsoon);

dispatch_semaphore_t _dispatch_get_thread_semaphore(void);
void _dispatch_put_thread_semaphore(dispatch_semaphore_t);

bool _dispatch_source_testcancel(dispatch_source_t);

uint64_t _dispatch_timeout(dispatch_time_t when);
#if USE_POSIX_SEM
struct timespec _dispatch_timeout_ts(dispatch_time_t when);
#endif

__private_extern__ bool _dispatch_safe_fork;

__private_extern__ struct _dispatch_hw_config_s {
	uint32_t cc_max_active;
	uint32_t cc_max_logical;
	uint32_t cc_max_physical;
} _dispatch_hw_config;

/* #includes dependent on internal.h */
#include "object_internal.h"
#include "hw_shims.h"
#include "os_shims.h"
#include "queue_internal.h"
#include "semaphore_internal.h"
#include "source_internal.h"
#include "interop_internal.h"

#include "continuation_cache.h"

#endif /* __DISPATCH_INTERNAL__ */
