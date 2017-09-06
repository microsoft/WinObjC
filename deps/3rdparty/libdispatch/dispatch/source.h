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
#pragma once

#ifndef __DISPATCH_SOURCE__
#define __DISPATCH_SOURCE__

#ifndef __DISPATCH_INDIRECT__
#error "Please #include <dispatch/dispatch.h> instead of this file directly."
#include <dispatch/base.h> // for HeaderDoc
#endif

#if TARGET_OS_MAC
#include <mach/port.h>
#include <mach/message.h>
#endif

#ifndef _MSC_VER
#include <sys/signal.h>
#endif

/*!
 * @header
 * The dispatch framework provides a suite of interfaces for monitoring low-
 * level system objects (file descriptors, Mach ports, signals, VFS nodes, etc.)
 * for activity and automatically submitting event handler blocks to dispatch
 * queues when such activity occurs.
 *
 * This suite of interfaces is known as the Dispatch Source API.
 */

/*!
 * @typedef dispatch_source_t
 *
 * @abstract
 * Dispatch sources are used to automatically submit event handler blocks to
 * dispatch queues in response to external events.
 */
DISPATCH_DECL(dispatch_source);

__DISPATCH_BEGIN_DECLS

/*!
 * @typedef dispatch_source_type_t
 *
 * @abstract
 * Constants of this type represent the class of low-level system object that
 * is being monitored by the dispatch source. Constants of this type are
 * passed as a parameter to dispatch_source_create() and determine how the
 * handle argument is interpreted (i.e. as a file descriptor, mach port,
 * signal number, process identifer, etc.), and how the mask arugment is
 * interpreted.
 */
typedef const struct dispatch_source_type_s *dispatch_source_type_t;

/*!
 * @const DISPATCH_SOURCE_TYPE_DATA_ADD
 * @discussion A dispatch source that coalesces data obtained via calls to
 * dispatch_source_merge_data(). An ADD is used to coalesce the data.
 * The handle is unused (pass zero for now).
 * The mask is unused (pass zero for now).
 */
#define DISPATCH_SOURCE_TYPE_DATA_ADD (&_dispatch_source_type_data_add)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT
const struct dispatch_source_type_s _dispatch_source_type_data_add;

/*!
 * @const DISPATCH_SOURCE_TYPE_DATA_OR
 * @discussion A dispatch source that coalesces data obtained via calls to
 * dispatch_source_merge_data(). A logical OR is used to coalesce the data.
 * The handle is unused (pass zero for now).
 * The mask is used to perform a logical AND with the value passed to
 * dispatch_source_merge_data().
 */
#define DISPATCH_SOURCE_TYPE_DATA_OR (&_dispatch_source_type_data_or)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT
const struct dispatch_source_type_s _dispatch_source_type_data_or;

/*!
 * @const DISPATCH_SOURCE_TYPE_MACH_SEND
 * @discussion A dispatch source that monitors a Mach port for dead name
 * notifications (send right no longer has any corresponding receive right).
 * The handle is a Mach port with a send or send-once right (mach_port_t).
 * The mask is a mask of desired events from dispatch_source_mach_send_flags_t.
 */
#define DISPATCH_SOURCE_TYPE_MACH_SEND (&_dispatch_source_type_mach_send)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT
const struct dispatch_source_type_s _dispatch_source_type_mach_send;

/*!
 * @const DISPATCH_SOURCE_TYPE_MACH_RECV
 * @discussion A dispatch source that monitors a Mach port for pending messages.
 * The handle is a Mach port with a receive right (mach_port_t).
 * The mask is unused (pass zero for now).
 */
#define DISPATCH_SOURCE_TYPE_MACH_RECV (&_dispatch_source_type_mach_recv)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT
const struct dispatch_source_type_s _dispatch_source_type_mach_recv;

/*!
 * @const DISPATCH_SOURCE_TYPE_PROC
 * @discussion A dispatch source that monitors an external process for events
 * defined by dispatch_source_proc_flags_t.
 * The handle is a process identifier (pid_t).
 * The mask is a mask of desired events from dispatch_source_proc_flags_t.
 */
#define DISPATCH_SOURCE_TYPE_PROC (&_dispatch_source_type_proc)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT
const struct dispatch_source_type_s _dispatch_source_type_proc;

/*!
 * @const DISPATCH_SOURCE_TYPE_OIO
 * @discussion A dispatch source that receives overlapped I/O events
 * The handle is a Win32 HANDLE in overlapped mode.
 * The mask is unused (pass zero for now).
 */
#define DISPATCH_SOURCE_TYPE_OIO (&_dispatch_source_type_oio)
DISPATCH_EXPORT
const struct dispatch_source_type_s _dispatch_source_type_oio;

/*!
 * @const DISPATCH_SOURCE_TYPE_READ
 * @discussion A dispatch source that monitors a file descriptor for pending
 * bytes available to be read.
 * The handle is a file descriptor (int).
 * The mask is unused (pass zero for now).
 */
#define DISPATCH_SOURCE_TYPE_READ (&_dispatch_source_type_read)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT
const struct dispatch_source_type_s _dispatch_source_type_read;

/*!
 * @const DISPATCH_SOURCE_TYPE_SIGNAL
 * @discussion A dispatch source that monitors the current process for signals.
 * The handle is a signal number (int).
 * The mask is unused (pass zero for now).
 */
#define DISPATCH_SOURCE_TYPE_SIGNAL (&_dispatch_source_type_signal)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT
const struct dispatch_source_type_s _dispatch_source_type_signal;

/*!
 * @const DISPATCH_SOURCE_TYPE_TIMER
 * @discussion A dispatch source that submits the event handler block based
 * on a timer.
 * The handle is unused (pass zero for now).
 * The mask is unused (pass zero for now).
 */
#define DISPATCH_SOURCE_TYPE_TIMER (&_dispatch_source_type_timer)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT
const struct dispatch_source_type_s _dispatch_source_type_timer;

/*!
 * @const DISPATCH_SOURCE_TYPE_VNODE
 * @discussion A dispatch source that monitors a file descriptor for events
 * defined by dispatch_source_vnode_flags_t.
 * The handle is a file descriptor (int).
 * The mask is a mask of desired events from dispatch_source_vnode_flags_t.
 */
#define DISPATCH_SOURCE_TYPE_VNODE (&_dispatch_source_type_vnode)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT
const struct dispatch_source_type_s _dispatch_source_type_vnode;

/*!
 * @const DISPATCH_SOURCE_TYPE_WRITE
 * @discussion A dispatch source that monitors a file descriptor for available
 * buffer space to write bytes.
 * The handle is a file descriptor (int).
 * The mask is unused (pass zero for now).
 */
#define DISPATCH_SOURCE_TYPE_WRITE (&_dispatch_source_type_write)
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT
const struct dispatch_source_type_s _dispatch_source_type_write;

/*!
 * @enum dispatch_source_mach_send_flags_t
 *
 * @constant DISPATCH_MACH_SEND_DEAD
 * The receive right corresponding to the given send right was destroyed.
 */
enum {
	DISPATCH_MACH_SEND_DEAD = 0x1,
};

/*!
 * @enum dispatch_source_proc_flags_t
 *
 * @constant DISPATCH_PROC_EXIT
 * The process has exited (perhaps cleanly, perhaps not).
 *
 * @constant DISPATCH_PROC_FORK
 * The process has created one or more child processes.
 *
 * @constant DISPATCH_PROC_EXEC
 * The process has become another executable image via
 * exec*() or posix_spawn*().
 *
 * @constant DISPATCH_PROC_SIGNAL
 * A Unix signal was delivered to the process.
 */
enum : unsigned __int64 {
	DISPATCH_PROC_EXIT = 0x80000000,
	DISPATCH_PROC_FORK = 0x40000000,
	DISPATCH_PROC_EXEC = 0x20000000,
	DISPATCH_PROC_SIGNAL = 0x08000000,
};

/*!
 * @enum dispatch_source_vnode_flags_t
 *
 * @constant DISPATCH_VNODE_DELETE
 * The filesystem object was deleted from the namespace.
 *
 * @constant DISPATCH_VNODE_WRITE
 * The filesystem object data changed.
 *
 * @constant DISPATCH_VNODE_EXTEND
 * The filesystem object changed in size.
 *
 * @constant DISPATCH_VNODE_ATTRIB
 * The filesystem object metadata changed.
 *
 * @constant DISPATCH_VNODE_LINK
 * The filesystem object link count changed.
 *
 * @constant DISPATCH_VNODE_RENAME
 * The filesystem object was renamed in the namespace.
 *
 * @constant DISPATCH_VNODE_REVOKE
 * The filesystem object was revoked.
 */
enum {
	DISPATCH_VNODE_DELETE = 0x1,
	DISPATCH_VNODE_WRITE = 0x2,
	DISPATCH_VNODE_EXTEND = 0x4,
	DISPATCH_VNODE_ATTRIB = 0x8,
	DISPATCH_VNODE_LINK	= 0x10,
	DISPATCH_VNODE_RENAME = 0x20,
	DISPATCH_VNODE_REVOKE = 0x40,
};

/*!
 * @function dispatch_source_create
 *
 * @abstract
 * Creates a new dispatch source to monitor low-level system objects and auto-
 * matically submit a handler block to a dispatch queue in response to events.
 *
 * @discussion
 * Dispatch sources are not reentrant. Any events received while the dispatch
 * source is suspended or while the event handler block is currently executing
 * will be coalesced and delivered after the dispatch source is resumed or the
 * event handler block has returned.
 *
 * Dispatch sources are created in a suspended state. After creating the
 * source and setting any desired attributes (i.e. the handler, context, etc.),
 * a call must be made to dispatch_resume() in order to begin event delivery.
 *
 * @param type
 * Declares the type of the dispatch source. Must be one of the defined
 * dispatch_source_type_t constants.
 * @param handle
 * The underlying system handle to monitor. The interpretation of this argument
 * is determined by the constant provided in the type parameter.
 * @param mask
 * A mask of flags specifying which events are desired. The interpretation of
 * this argument is determined by the constant provided in the type parameter.
 * @param queue
 * The dispatch queue to which the event handler block will be submited.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_MALLOC DISPATCH_NOTHROW
dispatch_source_t
dispatch_source_create(dispatch_source_type_t type,
	uintptr_t handle,
	uintptr_t mask,
	dispatch_queue_t queue);

/*!
 * @function dispatch_source_set_event_handler
 *
 * @abstract
 * Sets the event handler block for the given dispatch source.
 *
 * @param source
 * The dispatch source to modify.
 * The result of passing NULL in this parameter is undefined.
 * 
 * @param handler
 * The event handler block to submit to the source's target queue.
 */
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL1 DISPATCH_NOTHROW
void
dispatch_source_set_event_handler(dispatch_source_t source,
	dispatch_block_t handler);
#endif /* __BLOCKS__ */

/*!
 * @function dispatch_source_set_event_handler_f
 *
 * @abstract
 * Sets the event handler function for the given dispatch source.
 *
 * @param source
 * The dispatch source to modify.
 * The result of passing NULL in this parameter is undefined.
 *
 * @param handler
 * The event handler function to submit to the source's target queue.
 * The context parameter passed to the event handler function is the current
 * context of the dispatch source at the time the handler call is made.
 * The result of passing NULL in this parameter is undefined.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL1 DISPATCH_NOTHROW
void
dispatch_source_set_event_handler_f(dispatch_source_t source,
	dispatch_function_t handler);

/*!
 * @function dispatch_source_set_cancel_handler
 *
 * @abstract
 * Sets the cancellation handler block for the given dispatch source.
 *
 * @discussion
 * The cancellation handler (if specified) will be submitted to the source's
 * target queue in response to a call to dispatch_source_cancel() once the
 * system has released all references to the source's underlying handle and
 * the source's event handler block has returned.
 *
 * IMPORTANT:
 * A cancellation handler is required for file descriptor and mach port based
 * sources in order to safely close the descriptor or destroy the port. Closing
 * the descriptor or port before the cancellation handler may result in a race
 * condition. If a new descriptor is allocated with the same value as the
 * recently closed descriptor while the source's event handler is still running,
 * the event handler may read/write data to the wrong descriptor.
 *
 * @param source
 * The dispatch source to modify.
 * The result of passing NULL in this parameter is undefined.
 * 
 * @param handler
 * The cancellation handler block to submit to the source's target queue.
 */
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL1 DISPATCH_NOTHROW
void
dispatch_source_set_cancel_handler(dispatch_source_t source,
	dispatch_block_t cancel_handler);
#endif /* __BLOCKS__ */

/*!
 * @function dispatch_source_set_cancel_handler_f
 *
 * @abstract
 * Sets the cancellation handler function for the given dispatch source.
 *
 * @discussion
 * See dispatch_source_set_cancel_handler() for more details.
 *
 * @param source
 * The dispatch source to modify.
 * The result of passing NULL in this parameter is undefined.
 *
 * @param handler
 * The cancellation handler function to submit to the source's target queue.
 * The context parameter passed to the event handler function is the current
 * context of the dispatch source at the time the handler call is made.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL1 DISPATCH_NOTHROW
void
dispatch_source_set_cancel_handler_f(dispatch_source_t source,
	dispatch_function_t cancel_handler);

/*!
 * @function dispatch_source_cancel
 *
 * @abstract
 * Asynchronously cancel the dispatch source, preventing any further invocation
 * of its event handler block.
 *
 * @discussion
 * Cancellation prevents any further invocation of the event handler block for
 * the specified dispatch source, but does not interrupt an event handler
 * block that is already in progress.
 *
 * The cancellation handler is submitted to the source's target queue once the
 * the source's event handler has finished, indicating it is now safe to close
 * the source's handle (i.e. file descriptor or mach port).
 *
 * See dispatch_source_set_cancel_handler() for more information.
 *
 * @param source
 * The dispatch source to be canceled.
 * The result of passing NULL in this parameter is undefined.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_source_cancel(dispatch_source_t source);

/*!
 * @function dispatch_source_testcancel
 *
 * @abstract
 * Tests whether the given dispatch source has been canceled.
 *
 * @param source
 * The dispatch source to be tested.
 * The result of passing NULL in this parameter is undefined.
 *
 * @result
 * Non-zero if canceled and zero if not canceled.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
long
dispatch_source_testcancel(dispatch_source_t source);

/*!
 * @function dispatch_source_get_handle
 *
 * @abstract
 * Returns the underlying system handle associated with this dispatch source.
 *
 * @param source
 * The result of passing NULL in this parameter is undefined.
 *
 * @result
 * The return value should be interpreted according to the type of the dispatch
 * source, and may be one of the following handles:
 *
 *  DISPATCH_SOURCE_TYPE_DATA_ADD:        n/a
 *  DISPATCH_SOURCE_TYPE_DATA_OR:         n/a
 *  DISPATCH_SOURCE_TYPE_MACH_SEND:       mach port (mach_port_t)
 *  DISPATCH_SOURCE_TYPE_MACH_RECV:       mach port (mach_port_t)
 *  DISPATCH_SOURCE_TYPE_PROC:            process identifier (pid_t)
 *  DISPATCH_SOURCE_TYPE_READ:            file descriptor (int)
 *  DISPATCH_SOURCE_TYPE_SIGNAL:          signal number (int) 
 *  DISPATCH_SOURCE_TYPE_TIMER:           n/a
 *  DISPATCH_SOURCE_TYPE_VNODE:           file descriptor (int)
 *  DISPATCH_SOURCE_TYPE_WRITE:           file descriptor (int)
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_WARN_RESULT DISPATCH_PURE DISPATCH_NOTHROW
uintptr_t
dispatch_source_get_handle(dispatch_source_t source);

/*!
 * @function dispatch_source_get_mask
 *
 * @abstract
 * Returns the mask of events monitored by the dispatch source.
 *
 * @param source
 * The result of passing NULL in this parameter is undefined.
 *
 * @result
 * The return value should be interpreted according to the type of the dispatch
 * source, and may be one of the following flag sets:
 *
 *  DISPATCH_SOURCE_TYPE_DATA_ADD:        n/a
 *  DISPATCH_SOURCE_TYPE_DATA_OR:         n/a
 *  DISPATCH_SOURCE_TYPE_MACH_SEND:       dispatch_source_mach_send_flags_t
 *  DISPATCH_SOURCE_TYPE_MACH_RECV:       n/a
 *  DISPATCH_SOURCE_TYPE_PROC:            dispatch_source_proc_flags_t
 *  DISPATCH_SOURCE_TYPE_READ:            n/a
 *  DISPATCH_SOURCE_TYPE_SIGNAL:          n/a
 *  DISPATCH_SOURCE_TYPE_TIMER:           n/a
 *  DISPATCH_SOURCE_TYPE_VNODE:           dispatch_source_vnode_flags_t
 *  DISPATCH_SOURCE_TYPE_WRITE:           n/a
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_WARN_RESULT DISPATCH_PURE DISPATCH_NOTHROW
uintptr_t
dispatch_source_get_mask(dispatch_source_t source);

/*!
 * @function dispatch_source_get_data
 *
 * @abstract
 * Returns pending data for the dispatch source.
 *
 * @discussion
 * This function is intended to be called from within the event handler block.
 * The result of calling this function outside of the event handler callback is
 * undefined.
 *
 * @param source
 * The result of passing NULL in this parameter is undefined.
 *
 * @result
 * The return value should be interpreted according to the type of the dispatch
 * source, and may be one of the following:
 *
 *  DISPATCH_SOURCE_TYPE_DATA_ADD:        application defined data
 *  DISPATCH_SOURCE_TYPE_DATA_OR:         application defined data
 *  DISPATCH_SOURCE_TYPE_MACH_SEND:       dispatch_source_mach_send_flags_t
 *  DISPATCH_SOURCE_TYPE_MACH_RECV:       n/a
 *  DISPATCH_SOURCE_TYPE_PROC:            dispatch_source_proc_flags_t
 *  DISPATCH_SOURCE_TYPE_READ:            estimated bytes available to read
 *  DISPATCH_SOURCE_TYPE_SIGNAL:          number of signals delivered since
 *                                            the last handler invocation
 *  DISPATCH_SOURCE_TYPE_TIMER:           number of times the timer has fired
 *                                            since the last handler invocation
 *  DISPATCH_SOURCE_TYPE_VNODE:           dispatch_source_vnode_flags_t
 *  DISPATCH_SOURCE_TYPE_WRITE:           estimated buffer space available
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_WARN_RESULT DISPATCH_PURE DISPATCH_NOTHROW
uintptr_t
dispatch_source_get_data(dispatch_source_t source);

/*!
 * @function dispatch_source_merge_data
 *
 * @abstract
 * Merges data into a dispatch source of type DISPATCH_SOURCE_TYPE_DATA_ADD or
 * DISPATCH_SOURCE_TYPE_DATA_OR and submits its event handler block to its
 * target queue.
 *
 * @param source
 * The result of passing NULL in this parameter is undefined.
 *
 * @param value
 * The value to coalesce with the pending data using a logical OR or an ADD
 * as specified by the dispatch source type. A value of zero has no effect
 * and will not result in the submission of the event handler block.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_source_merge_data(dispatch_source_t source, uintptr_t value);

/*!
 * @function dispatch_source_set_timer
 *
 * @abstract
 * Sets a start time, interval, and leeway value for a timer source.
 *
 * @discussion
 * Calling this function has no effect if the timer source has already been
 * canceled.
 * 
 * The start time argument also determines which clock will be used for the
 * timer. If the start time is DISPATCH_TIME_NOW or created with
 * dispatch_time() then the timer is based on mach_absolute_time(). Otherwise,
 * if the start time of the timer is created with dispatch_walltime() then the
 * timer is based on gettimeofday(3).
 * 
 * @param start
 * The start time of the timer. See dispatch_time() and dispatch_walltime()
 * for more information.
 *
 * @param interval
 * The nanosecond interval for the timer.
 *
 * @param leeway
 * A hint given to the system by the application for the amount of leeway, in
 * nanoseconds, that the system may defer the timer in order to align with other
 * system activity for improved system performance or power consumption. (For
 * example, an application might perform a periodic task every 5 minutes, with
 * a leeway of up to 30 seconds.)  Note that some latency is to be expected for
 * all timers even when a leeway value of zero is specified.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_source_set_timer(dispatch_source_t source,
	dispatch_time_t start,
	uint64_t interval,
	uint64_t leeway);

__DISPATCH_END_DECLS

#endif
