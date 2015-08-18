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

/*
 * LEGACY: This header file describles LEGACY interfaces to libdispatch from an
 * earlier revision of the API. These interfaces WILL be removed in the future.
 */
 
#ifndef __DISPATCH_LEGACY__
#define __DISPATCH_LEGACY__

#ifndef __DISPATCH_INDIRECT__
#error "Please #include <dispatch/dispatch.h> instead of this file directly."
#include <dispatch/base.h> // for HeaderDoc
#endif

#if HAVE_MACH
#include <mach/mach_types.h>
#endif

#define DISPATCH_DEPRECATED __attribute__((deprecated))
#define DISPATCH_PUBLIC_API __attribute__((visibility("default")))

typedef struct dispatch_item_s *dispatch_item_t;

struct dispatch_item_s {
	void *                                        di_objc_isa;    /* FIXME -- someday... */
	struct dispatch_item_s *volatile        di_next;
	dispatch_queue_t                        di_cback_q;
	uint32_t                                di_flags;
#if USE_MACH_SEM
	semaphore_t                             di_semaphore;
#endif
#if USE_POSIX_SEM
	/* Legacy API not supported except with Mach semaphores. */
#endif
	void *					di_work_func;
	void *                                  di_work_ctxt;
	void *					di_cback_func;
	void *                                  di_cback_ctxt;
	void *                                  di_ctxt;
};

// Use: dispatch_source_t
typedef struct dispatch_source_s *dispatch_event_t;

// Obsolete
#ifdef __BLOCKS__
typedef void (^dispatch_legacy_block_t)(dispatch_item_t);
typedef void (^dispatch_queue_deletion_block_t)(dispatch_queue_t queue);
typedef void (^dispatch_source_deletion_t)(dispatch_source_t source);
typedef void (^dispatch_event_callback_t)(dispatch_event_t event);
typedef void (^dispatch_source_handler_t)(dispatch_source_t source);
typedef dispatch_source_handler_t dispatch_event_handler_t;
typedef void (^dispatch_source_finalizer_t)(dispatch_source_t source);
#endif /* __BLOCKS__ */

// Obsolete
typedef void (*dispatch_source_handler_function_t)(void *, dispatch_source_t);
typedef void (*dispatch_source_finalizer_function_t)(void *, dispatch_source_t);
typedef dispatch_source_handler_function_t dispatch_event_handler_function_t;

DISPATCH_DECL(dispatch_source_attr);

#define DISPATCH_SOURCE_CREATE_SUSPENDED	((dispatch_source_attr_t)~0ul)

#ifdef __BLOCKS__
typedef void (^dispatch_queue_finalizer_t)(dispatch_queue_t queue);
#endif

typedef void (*dispatch_queue_finalizer_function_t)(void *, dispatch_queue_t);

__DISPATCH_BEGIN_DECLS

/*!
 * @function dispatch_queue_attr_create
 *
 * @abstract
 * Creates a new dispatch queue attribute structure. These attributes may be
 * provided at creation time to modify the default behavior of the queue.
 *
 * @discussion
 * The values present in this structure are copied to newly created queues.
 * The same attribute structure may be provided to multiple calls to
 * dispatch_queue_create() but only the values in the structure at the time the
 * call is made will be used.
 *
 * @result
 * The new dispatch queue attribute structure, initialized to default values.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_WARN_RESULT DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_queue_attr_t
dispatch_queue_attr_create(void);

/*!
 * @function dispatch_queue_attr_set_priority
 *
 * @abstract
 * Set the priority level for a dispatch queue.
 *
 * @discussion
 * Priority levels may be:
 * - DISPATCH_QUEUE_PRIORITY_HIGH
 * - DISPATCH_QUEUE_PRIORITY_DEFAULT
 * - DISPATCH_QUEUE_PRIORITY_LOW
 * Queues set to high priority will be processed
 * before queues set to default priority or low priority.
 * Queues set to low priority will be processed only if all
 * high priority and default priority queues are empty.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL1 DISPATCH_NOTHROW DISPATCH_DEPRECATED
void
dispatch_queue_attr_set_priority(dispatch_queue_attr_t attr, int priority);

#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL1 DISPATCH_NOTHROW DISPATCH_DEPRECATED
long
dispatch_queue_attr_set_finalizer(
								  dispatch_queue_attr_t attr,
								  dispatch_queue_finalizer_t finalizer);
#endif

__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL1 DISPATCH_NOTHROW DISPATCH_DEPRECATED
void
dispatch_queue_attr_set_finalizer_f(dispatch_queue_attr_t attr, void *context, dispatch_queue_finalizer_function_t finalizer);

/*!
 * @function dispatch_get_concurrent_queue
 *
 * @abstract
 * Returns a well-known global concurrent queue of a given priority level.
 *
 * @discussion
 * Blocks submitted to the returned queue may be invoked concurrently with
 * respect to each other.
 *
 * These queues are useful for performing one-shot asynchronous operations,
 * e.g. dispatch_async() to an "anonymous" queue; or for performing parallel
 * loops concurrently on multiple processors, e.g. dispatch_apply().
 *
 * The dispatch queues returned by this function are managed by the system for
 * the lifetime of the application, and need not be retained or released
 * directly by the application. Furthermore, dispatch_suspend() and
 * dispatch_queue_resume() are not supported on these global queues, and will
 * be ignored.
 *
 * @param priority
 * The requested priority level for the queue (default is zero):
 * - DISPATCH_QUEUE_PRIORITY_HIGH
 * - DISPATCH_QUEUE_PRIORITY_DEFAULT
 * - DISPATCH_QUEUE_PRIORITY_LOW
 *
 * @result
 * Returns a concurrent dispatch queue for use with dispatch_async(),
 * dispatch_apply(), et al.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_PURE DISPATCH_WARN_RESULT DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_queue_t
dispatch_get_concurrent_queue(long priority);

DISPATCH_PUBLIC_API DISPATCH_DEPRECATED
void
dispatch_queue_attr_set_flags(dispatch_queue_attr_t attr, uint64_t flags);

#ifdef __BLOCKS__
DISPATCH_PUBLIC_API DISPATCH_NONNULL1 DISPATCH_NONNULL2 DISPATCH_DEPRECATED
dispatch_item_t
dispatch_call(dispatch_queue_t, dispatch_legacy_block_t work, dispatch_legacy_block_t completion)
__asm__("_dispatch_call2");
#endif /* __BLOCKS__ */

DISPATCH_PUBLIC_API DISPATCH_PURE DISPATCH_WARN_RESULT DISPATCH_DEPRECATED
dispatch_queue_t
dispatch_queue_get_current(void);

// Use: dispatch_retain
DISPATCH_PUBLIC_API DISPATCH_NONNULL_ALL DISPATCH_DEPRECATED
void
dispatch_queue_retain(dispatch_queue_t);

// Use: dispatch_release
DISPATCH_PUBLIC_API DISPATCH_NONNULL_ALL DISPATCH_DEPRECATED
void
dispatch_queue_release(dispatch_queue_t);

// Use: dispatch_resume
DISPATCH_PUBLIC_API DISPATCH_NONNULL_ALL DISPATCH_DEPRECATED
void
dispatch_queue_resume(dispatch_queue_t);

// Use: dispatch_release
DISPATCH_PUBLIC_API DISPATCH_NONNULL_ALL DISPATCH_DEPRECATED
void
dispatch_source_release(dispatch_source_t);

// Use: dispatch_suspend
DISPATCH_PUBLIC_API DISPATCH_NONNULL_ALL DISPATCH_DEPRECATED
void
dispatch_source_suspend(dispatch_source_t);

// Use: dispatch_resume
DISPATCH_PUBLIC_API DISPATCH_NONNULL_ALL DISPATCH_DEPRECATED
void
dispatch_source_resume(dispatch_source_t);

// Use: dispatch_release
DISPATCH_PUBLIC_API DISPATCH_NONNULL_ALL DISPATCH_DEPRECATED
void
dispatch_queue_attr_release(dispatch_queue_attr_t);

// Use: dispatch_release
DISPATCH_PUBLIC_API DISPATCH_NONNULL_ALL DISPATCH_DEPRECATED
void
dispatch_source_attr_release(dispatch_source_attr_t);

// Use: dispatch_source_get_handle
DISPATCH_PUBLIC_API DISPATCH_NONNULL_ALL DISPATCH_WARN_RESULT DISPATCH_DEPRECATED
sigset_t
dispatch_event_get_signals(dispatch_event_t event);

// Use: dispatch_get_context
DISPATCH_PUBLIC_API DISPATCH_NONNULL_ALL DISPATCH_DEPRECATED
void *
dispatch_queue_get_context(dispatch_queue_t queue);
  
// Use: dispatch_set_context
DISPATCH_PUBLIC_API DISPATCH_NONNULL1 DISPATCH_DEPRECATED
void
dispatch_queue_set_context(dispatch_queue_t queue, void *context);

// Use: dispatch_get_context
DISPATCH_PUBLIC_API DISPATCH_NONNULL_ALL DISPATCH_DEPRECATED
void *
dispatch_source_get_context(dispatch_source_t source);

// Use: dispatch_set_context
DISPATCH_PUBLIC_API DISPATCH_NONNULL1 DISPATCH_DEPRECATED
void
dispatch_source_set_context(dispatch_source_t source, void * context);

// Use: dispatch_source_merge_data
DISPATCH_PUBLIC_API DISPATCH_NONNULL_ALL DISPATCH_DEPRECATED
void
dispatch_source_custom_trigger(dispatch_source_t ds);

// Use: dispatch_source_cancel
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL_ALL DISPATCH_NOTHROW DISPATCH_DEPRECATED
void
dispatch_cancel(dispatch_source_t);

// Use: dispatch_source_testcancel
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL_ALL DISPATCH_NOTHROW DISPATCH_DEPRECATED
long
dispatch_testcancel(dispatch_source_t);

// Use: dispatch_source_set_timer
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL1 DISPATCH_NOTHROW DISPATCH_DEPRECATED
long
dispatch_source_timer_set_time(dispatch_source_t ds,
							   uint64_t nanoseconds,
							   uint64_t leeway);

// Use: dispatch_source_merge_data
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL_ALL DISPATCH_NOTHROW DISPATCH_DEPRECATED
void
dispatch_source_trigger(dispatch_source_t source, unsigned long value);

enum {
	DISPATCH_ERROR_DOMAIN_NO_ERROR = 0,
	DISPATCH_ERROR_DOMAIN_POSIX = 1,
	DISPATCH_ERROR_DOMAIN_MACH = 2,
};

// Obsolete
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL1 DISPATCH_WARN_RESULT DISPATCH_NOTHROW DISPATCH_DEPRECATED
long
dispatch_source_get_error(dispatch_source_t source, long* error);

#if HAVE_MACH
// Use: dispatch_source_get_handle
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL_ALL DISPATCH_WARN_RESULT DISPATCH_NOTHROW DISPATCH_DEPRECATED
mach_port_t
dispatch_source_get_machport(dispatch_source_t source);
#endif

// Use: dispatch_source_get_handle
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL_ALL DISPATCH_WARN_RESULT DISPATCH_NOTHROW DISPATCH_DEPRECATED
pid_t
dispatch_source_get_descriptor(dispatch_source_t source);

// Use: dispatch_source_get_handle
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL_ALL DISPATCH_WARN_RESULT DISPATCH_NOTHROW DISPATCH_DEPRECATED
pid_t
dispatch_source_get_pid(dispatch_source_t source);

// Use: dispatch_source_get_mask
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL_ALL DISPATCH_WARN_RESULT DISPATCH_NOTHROW DISPATCH_DEPRECATED
uint64_t
dispatch_source_get_flags(dispatch_source_t source);

// LEGACY: dispatch_event_t == dispatch_source_t
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL_ALL DISPATCH_WARN_RESULT DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_event_get_source(dispatch_event_t event);

// Use: dispatch_source_get_error
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL1 DISPATCH_WARN_RESULT DISPATCH_NOTHROW DISPATCH_DEPRECATED
long
dispatch_event_get_error(dispatch_event_t event, long* error);

__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL_ALL DISPATCH_WARN_RESULT DISPATCH_NOTHROW DISPATCH_DEPRECATED
uint64_t
dispatch_event_get_nanoseconds(dispatch_event_t event);

// Use: dispatch_source_get_handle
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL_ALL DISPATCH_WARN_RESULT DISPATCH_NOTHROW DISPATCH_DEPRECATED
long
dispatch_event_get_signal(dispatch_event_t event);

// Use: dispatch_source_get_data
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL_ALL DISPATCH_WARN_RESULT DISPATCH_NOTHROW DISPATCH_DEPRECATED
uint64_t
dispatch_event_get_flags(dispatch_event_t event);

// Use: dispatch_source_get_data
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL_ALL DISPATCH_WARN_RESULT DISPATCH_NOTHROW DISPATCH_DEPRECATED
size_t
dispatch_event_get_bytes_available(dispatch_event_t event);

// Use: dispatch_source_get_data
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL_ALL DISPATCH_NOTHROW DISPATCH_DEPRECATED
unsigned long
dispatch_event_get_count(dispatch_event_t event);

// Obsolete
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_WARN_RESULT DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_attr_t
dispatch_source_attr_create(void);

// Obsolete
#if defined(__BLOCKS__)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_finalizer_t
dispatch_source_attr_get_finalizer(dispatch_source_attr_t attr);
#endif /* __BLOCKS__ */

// Obsolete
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_WARN_RESULT DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_attr_t
dispatch_source_attr_copy(dispatch_source_attr_t proto);

// Obsolete
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL1 DISPATCH_NOTHROW DISPATCH_DEPRECATED
long
dispatch_source_attr_set_finalizer(
	dispatch_source_attr_t attr,
	dispatch_source_finalizer_t finalizer);
#endif /* __BLOCKS__ */

// Obsolete
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL1 DISPATCH_NOTHROW DISPATCH_DEPRECATED
void
dispatch_source_attr_set_finalizer_f(
	dispatch_source_attr_t attr,
	void *context,
	dispatch_source_finalizer_function_t finalizer);

// Obsolete
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_NONNULL1 DISPATCH_NOTHROW DISPATCH_DEPRECATED
void
dispatch_source_attr_set_context(
	dispatch_source_attr_t attr,
	void *context);

#if HAVE_MACH
// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_MACH_RECV, ...)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL4 DISPATCH_NONNULL5 DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_mig_create(
	mach_port_t mport, 
	size_t max_size,
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	dispatch_mig_callback_t mig_callback);
#endif

enum {
	DISPATCH_TIMER_WALL_CLOCK	= 0x4,
};

enum {
	DISPATCH_TIMER_INTERVAL	= 0x0,
	DISPATCH_TIMER_ONESHOT	= 0x1,
	DISPATCH_TIMER_ABSOLUTE	= 0x3,
};

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, ...)
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL5 DISPATCH_NONNULL6 DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_timer_create(
	uint64_t flags,
	uint64_t nanoseconds,
	uint64_t leeway,
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	dispatch_source_handler_t handler);
#endif /* __BLOCKS__ */

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, ...)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL5 DISPATCH_NONNULL7 DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_timer_create_f(
	uint64_t flags,
	uint64_t nanoseconds,
	uint64_t leeway,
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	void *h_context,
	dispatch_source_handler_function_t handler);

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_SIGNAL, ...)
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_signal_create(
	unsigned long signo,
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	dispatch_source_handler_t handler);
#endif /* __BLOCKS__ */

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_SIGNAL, ...)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL3 DISPATCH_NONNULL5 DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_signal_create_f(
	unsigned long sig,
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	void *h_context,
	dispatch_source_handler_function_t handler);

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_READ, ...)
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL3 DISPATCH_NONNULL4 DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_read_create(
	int descriptor,
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	dispatch_source_handler_t handler);
#endif /* __BLOCKS__ */

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_READ, ...)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL3 DISPATCH_NONNULL5 DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_read_create_f(
	int descriptor,
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	void *h_context,
	dispatch_source_handler_function_t handler);

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_WRITE, ...)
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL3 DISPATCH_NONNULL4 DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_write_create(
	int descriptor, 
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	dispatch_source_handler_t handler);
#endif /* __BLOCKS__ */

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_WRITE, ...)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL3 DISPATCH_NONNULL5 DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_write_create_f(
	int descriptor, 
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	void *h_context,
	dispatch_source_handler_function_t handler);

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_VNODE, ...)
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL4 DISPATCH_NONNULL5 DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_vnode_create(
	int descriptor,
	uint64_t flags,
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	dispatch_source_handler_t handler);
#endif /* __BLOCKS__ */

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_VNODE, ...)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL4 DISPATCH_NONNULL6 DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_vnode_create_f(
	int descriptor,
	uint64_t flags,
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	void *h_context,
	dispatch_source_handler_function_t handler);

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_PROC, ...)
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL4 DISPATCH_NONNULL5 DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_proc_create(
	pid_t pid,
	uint64_t flags,
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	dispatch_source_handler_t handler);
#endif /* __BLOCKS__ */

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_PROC, ...)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL4 DISPATCH_NONNULL6 DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_proc_create_f(
	pid_t pid,
	uint64_t flags, 
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	void *h_context,
	dispatch_source_handler_function_t handler);

enum {
	DISPATCH_MACHPORT_DEAD = 0x1,
	DISPATCH_MACHPORT_RECV = 0x2,
	DISPATCH_MACHPORT_DELETED = 0x4,
};

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_MACH_RECV, ...)
#if HAVE_MACH
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_machport_create(
	mach_port_t mport,
	uint64_t flags, 
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	dispatch_source_handler_t handler);
#endif /* __BLOCKS__ */

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_MACH_RECV, ...)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_machport_create_f(
	mach_port_t mport,
	uint64_t flags, 
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	void *h_context,
	dispatch_source_handler_function_t handler);
#endif /* HAVE_MACH */

enum {
	DISPATCH_SOURCE_DATA_ADD = 1,
	DISPATCH_SOURCE_DATA_OR,
};

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_DATA..., ...)
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL3 DISPATCH_NONNULL4 DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_data_create(
	unsigned long behavior,
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	dispatch_source_handler_t handler);
#endif /* __BLOCKS__ */

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_DATA..., ...)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL3 DISPATCH_NONNULL5 DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_data_create_f(
	unsigned long behavior,
	dispatch_source_attr_t attr,
	dispatch_queue_t queue,
	void *h_context,
	dispatch_source_handler_function_t handler);

enum {
	DISPATCH_SOURCE_CUSTOM_ADD = DISPATCH_SOURCE_DATA_ADD,
	DISPATCH_SOURCE_CUSTOM_OR = DISPATCH_SOURCE_DATA_OR,
};

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_DATA..., ...)
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL2 DISPATCH_NONNULL3 DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_custom_create(
							  unsigned long behavior,
							  dispatch_source_attr_t attr,
							  dispatch_queue_t queue,
							  dispatch_event_handler_t handler);
#endif /* __BLOCKS__ */

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_DATA..., ...)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL2 DISPATCH_NONNULL4 DISPATCH_NOTHROW DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_custom_create_f(
								unsigned long behavior,
								dispatch_source_attr_t attr,
								dispatch_queue_t queue,
								void *h_context,
								dispatch_event_handler_function_t handler);

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_VFS, ...)
#if defined(__BLOCKS__)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL3 DISPATCH_NONNULL4 DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_vfs_create(
						   uint64_t flags,
						   dispatch_source_attr_t attr,
						   dispatch_queue_t queue,
						   dispatch_source_handler_t handler);
#endif /* __BLOCKS__ */

// Use: dispatch_source_create(DISPATCH_SOURCE_TYPE_VFS, ...)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_MALLOC DISPATCH_NONNULL3 DISPATCH_NONNULL5 DISPATCH_DEPRECATED
dispatch_source_t
dispatch_source_vfs_create_f(
							 uint64_t flags,
							 dispatch_source_attr_t attr,
							 dispatch_queue_t queue,
							 void *h_context,
							 dispatch_source_handler_function_t handler);

#if HAVE_MACH
/*
 * Raw Mach message support from MIG source.
 *
 * It is possible to use the following callback style with the MIG source to
 * obtain the raw mach message (and send no reply) similar to CFMachPort.
 * (For more specific CFMachPort compatibility, see below).
 *
 * void handle_mach_msg(mach_msg_header *msg) { ... }
 * ...
 * DISPATCH_MACHPORT_CALLBACK_DECL(mig_compat_callback, handle_mach_msg);
 * ...
 * mig = dispatch_source_mig_create(mp, MY_MAX_MSG_SIZE, NULL,
 *         queue, mig_compat_callback);
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_DEPRECATED
boolean_t
_dispatch_machport_callback(mach_msg_header_t *msg, mach_msg_header_t *reply, void (*callback)(mach_msg_header_t *));

#define DISPATCH_MACHPORT_CALLBACK_DECL(new_callback, existing_callback) \
__private_extern__ boolean_t \
new_callback(mach_msg_header_t *msg, mach_msg_header_t *reply) \
{ return _dispatch_machport_callback(msg, reply, existing_callback); }

/*
 * CFMachPort compatibility.
 *
 * It is possible to use existing CFMachPort callbacks with dispatch mig sources
 * by delcaring the following shim and using the shim as the mig server callback
 * to dispatch_source_mig_create().
 * The CFMachPortRef "port" parameter of the CFMachPortCallBack will be NULL. 
 * If mach_port_set_context() is used, that value will be passed into the "info"
 * parameter of the CFMachPortCallBack.
 *
 * DISPATCH_CFMACHPORT_CALLBACK_DECL(mig_callback, MyCFMachPortCallBack);
 *
 * ...
 * {
 * kr = mach_port_set_context(mach_task_self(), mp, (mach_vm_address_t)context);
 * mig = dispatch_source_mig_create(mp, MY_MAX_MSG_SIZE, NULL,
 *         queue, mig_callback);
 */
struct __CFMachPort;

__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_DEPRECATED
boolean_t
_dispatch_CFMachPortCallBack(mach_msg_header_t *msg, mach_msg_header_t *reply, void (*callback)(struct __CFMachPort *, void *msg, signed long size, void *));

#define DISPATCH_CFMACHPORT_CALLBACK_DECL(new_callback, existing_callback) \
__private_extern__ boolean_t \
new_callback(mach_msg_header_t *msg, mach_msg_header_t *reply) \
{ return _dispatch_CFMachPortCallBack(msg, reply, existing_callback); }

#endif /* HAVE_MACH */

__DISPATCH_END_DECLS

#endif
