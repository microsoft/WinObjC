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

#ifndef __DISPATCH_QUEUE_PRIVATE__
#define __DISPATCH_QUEUE_PRIVATE__

#ifndef __DISPATCH_INDIRECT__
#error "Please #include <dispatch/dispatch.h> instead of this file directly."
#include <dispatch/base.h> // for HeaderDoc
#endif

__DISPATCH_BEGIN_DECLS
	
/*!
 * @enum dispatch_queue_flags_t
 *
 * @constant DISPATCH_QUEUE_OVERCOMMIT
 * The queue will create a new thread for invoking blocks, regardless of how
 * busy the computer is.
 */
enum {
	DISPATCH_QUEUE_OVERCOMMIT = 0x2ull,
};

#define DISPATCH_QUEUE_FLAGS_MASK	(DISPATCH_QUEUE_OVERCOMMIT)

#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_barrier_sync(dispatch_queue_t queue, dispatch_block_t block);
#endif

__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL1 DISPATCH_NONNULL3 DISPATCH_NOTHROW
void
dispatch_barrier_sync_f(dispatch_queue_t dq, void *context, dispatch_function_t work);

#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_barrier_async(dispatch_queue_t queue, dispatch_block_t block);
#endif

__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL1 DISPATCH_NONNULL3 DISPATCH_NOTHROW
void
dispatch_barrier_async_f(dispatch_queue_t dq, void *context, dispatch_function_t work);

/*!
 * @function dispatch_queue_set_width
 *
 * @abstract
 * Set the width of concurrency for a given queue. The default width of a
 * privately allocated queue is one.
 *
 * @param queue
 * The queue to adjust. Passing the main queue, a default concurrent queue or
 * any other default queue will be ignored.
 *
 * @param width
 * The new maximum width of concurrency depending on available resources.
 * If zero is passed, then the value is promoted to one.
 * Negative values are magic values that map to automatic width values.
 * Unknown negative values default to DISPATCH_QUEUE_WIDTH_MAX_LOGICAL_CPUS.
 */
#define DISPATCH_QUEUE_WIDTH_ACTIVE_CPUS	-1
#define DISPATCH_QUEUE_WIDTH_MAX_PHYSICAL_CPUS	-2
#define DISPATCH_QUEUE_WIDTH_MAX_LOGICAL_CPUS	-3

__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_queue_set_width(dispatch_queue_t dq, long width);

__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
extern const struct dispatch_queue_offsets_s {
	// always add new fields at the end
	const uint16_t dqo_version;
	const uint16_t dqo_label;
	const uint16_t dqo_label_size;
	const uint16_t dqo_flags;
	const uint16_t dqo_flags_size;
	const uint16_t dqo_serialnum;
	const uint16_t dqo_serialnum_size;
	const uint16_t dqo_width;
	const uint16_t dqo_width_size;
	const uint16_t dqo_running;
	const uint16_t dqo_running_size;
} dispatch_queue_offsets;

__DISPATCH_END_DECLS

#endif
