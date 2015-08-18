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

#include "internal.h"

#ifndef DISPATCH_NO_LEGACY
#include "legacy.h"

/*
 * LEGACY: This header file describles LEGACY interfaces to libdispatch from an
 * earlier revision of the API. These interfaces WILL be removed in the future.
 */

#ifdef __BLOCKS__
DISPATCH_PUBLIC_API DISPATCH_NONNULL1 DISPATCH_NONNULL2
dispatch_item_t
LEGACY_dispatch_call(dispatch_queue_t, dispatch_legacy_block_t work, dispatch_legacy_block_t completion)
__asm__("_dispatch_call2");
#endif

DISPATCH_PUBLIC_API DISPATCH_PURE DISPATCH_WARN_RESULT
dispatch_queue_t
LEGACY_dispatch_queue_get_current(void)
__asm__("_dispatch_queue_get_current");

/////////////////////////////////////////////////////////////////////////////

dispatch_queue_t
LEGACY_dispatch_queue_get_current(void)
{
	return _dispatch_queue_get_current();
}

#ifdef __BLOCKS__
dispatch_item_t
LEGACY_dispatch_call(dispatch_queue_t dq,
	dispatch_legacy_block_t dispatch_block,
	dispatch_legacy_block_t callback_block)
{
	dispatch_queue_t lq = _dispatch_queue_get_current() ?: dispatch_get_main_queue();
	dispatch_item_t di;

	di = dispatch_block ? calloc(1, ROUND_UP_TO_CACHELINE_SIZE(sizeof(*di))) : NULL;

	if (!di) {
		return di;
	}

	if (callback_block) {
		dispatch_retain(lq);
	}

	dispatch_async(dq, ^{
		dispatch_block(di);

		if (callback_block) {
			dispatch_async(lq, ^{
				callback_block(di);
				free(di);
				dispatch_release(lq);
			});
		} else {
			free(di);
		}
	});

	return di;
}
#endif /* __BLOCKS__ */

sigset_t
dispatch_event_get_signals(dispatch_event_t de)
{
	sigset_t ret;
	sigemptyset(&ret);
	sigaddset(&ret, (int)dispatch_event_get_signal(de));
	return ret;
}

void dispatch_cancel(dispatch_source_t ds) { dispatch_source_cancel(ds); }
long dispatch_testcancel(dispatch_source_t ds) { return dispatch_source_testcancel(ds); }

void dispatch_queue_resume(dispatch_queue_t dq) { dispatch_resume(dq); }
void dispatch_queue_retain(dispatch_queue_t dq) { dispatch_retain(dq); }
void dispatch_queue_release(dispatch_queue_t dq) { dispatch_release(dq); }

void dispatch_source_suspend(dispatch_source_t ds) { dispatch_suspend(ds); }
void dispatch_source_resume(dispatch_source_t ds) { dispatch_resume(ds); }
void dispatch_source_release(dispatch_source_t ds) { dispatch_release(ds); }

void dispatch_source_attr_release(dispatch_source_attr_t attr) { dispatch_release(attr); }
void dispatch_queue_attr_release(dispatch_queue_attr_t attr) { dispatch_release(attr); }

void *dispatch_queue_get_context(dispatch_queue_t dq) { return dispatch_get_context(dq); }
void  dispatch_queue_set_context(dispatch_queue_t dq, void *context) { dispatch_set_context(dq, context); }

void *dispatch_source_get_context(dispatch_source_t ds) { return dispatch_get_context(ds); }
void  dispatch_source_set_context(dispatch_source_t ds, void *context) { dispatch_set_context(ds, context); }

void dispatch_source_custom_trigger(dispatch_source_t ds) { dispatch_source_merge_data(ds, 1); }

void
dispatch_source_trigger(dispatch_source_t ds, unsigned long val)
{
	dispatch_source_merge_data(ds, val);
}

int dispatch_source_get_descriptor(dispatch_source_t ds) { return (int)dispatch_source_get_handle(ds); }

pid_t dispatch_source_get_pid(dispatch_source_t ds) { return (pid_t)dispatch_source_get_handle(ds); }

mach_port_t dispatch_source_get_machport(dispatch_source_t ds) { return (mach_port_t)dispatch_source_get_handle(ds); }

uint64_t dispatch_source_get_flags(dispatch_source_t ds) { return dispatch_source_get_mask(ds); }

dispatch_source_t dispatch_event_get_source(dispatch_event_t event) { return event; }

long dispatch_event_get_error(dispatch_event_t event, long* error) { return dispatch_source_get_error(event, error); }

uint64_t dispatch_event_get_flags(dispatch_event_t event)  { return dispatch_source_get_data(event); }

size_t dispatch_event_get_bytes_available(dispatch_event_t event) { return (size_t)dispatch_source_get_data(event); }

unsigned long dispatch_event_get_count(dispatch_event_t event) { return (unsigned long)dispatch_source_get_data(event); }

long dispatch_event_get_signal(dispatch_event_t event) { return (long)dispatch_source_get_handle(event); }

dispatch_source_t
dispatch_source_custom_create(
							  unsigned long behavior,
							  dispatch_source_attr_t attr,
							  dispatch_queue_t queue,
							  dispatch_event_handler_t handler) {
	return dispatch_source_data_create(behavior, attr, queue, handler);
}

dispatch_source_t
dispatch_source_custom_create_f(
								unsigned long behavior,
								dispatch_source_attr_t attr,
								dispatch_queue_t queue,
								void *h_context,
								dispatch_event_handler_function_t handler) {
	return dispatch_source_data_create_f(behavior, attr, queue, h_context, handler);
}

#define _dispatch_source_call_block ((void *)-1)



#ifdef __BLOCKS__
dispatch_source_t
dispatch_source_timer_create(uint64_t flags,
	uint64_t nanoseconds,
	uint64_t leeway,
	dispatch_source_attr_t attr,
	dispatch_queue_t q,
	dispatch_source_handler_t callback)
{
	return dispatch_source_timer_create_f(flags, nanoseconds, leeway,
		attr, q, callback, _dispatch_source_call_block);
}
#endif

dispatch_source_t
dispatch_source_timer_create_f(uint64_t timer_flags,
	uint64_t nanoseconds,
	uint64_t leeway,
	dispatch_source_attr_t attr,
	dispatch_queue_t q,
	void *context, 
	dispatch_source_handler_function_t callback)
{
	dispatch_source_t ds;
	dispatch_time_t start;

	// 6866347 - make sure nanoseconds won't overflow
	if ((int64_t)nanoseconds < 0) {
		nanoseconds = INT64_MAX;
	}

	if (timer_flags & DISPATCH_TIMER_ONESHOT) {
		timer_flags |= DISPATCH_TIMER_WALL_CLOCK;
	}
	if (timer_flags == (DISPATCH_TIMER_ABSOLUTE|DISPATCH_TIMER_WALL_CLOCK)) {
		static const struct timespec t0;
		start = dispatch_walltime(&t0, nanoseconds);
	} else if (timer_flags & DISPATCH_TIMER_WALL_CLOCK) {
		start = dispatch_walltime(DISPATCH_TIME_NOW, nanoseconds);
	} else {
		start = dispatch_time(DISPATCH_TIME_NOW, nanoseconds);
	}
	if (timer_flags & DISPATCH_TIMER_ONESHOT) {
		// 6866347 - make sure nanoseconds won't overflow
		nanoseconds = INT64_MAX; // non-repeating (~292 years)
	}

	ds = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, (unsigned long)timer_flags, q);
	if (!ds) {
		return NULL;
	}
	ds = _dispatch_source_create2(ds, attr, context, callback);
	if (!ds) {
		return NULL;
	}
	dispatch_source_set_timer(ds, start, nanoseconds, leeway);

	return ds;
}

#ifdef __BLOCKS__
dispatch_source_t
dispatch_source_read_create(int descriptor,
	dispatch_source_attr_t attr,
	dispatch_queue_t q,
	dispatch_source_handler_t callback)
{
	return dispatch_source_read_create_f(descriptor,
		attr, q, callback, _dispatch_source_call_block);
}
#endif

dispatch_source_t
dispatch_source_read_create_f(int fd,
	dispatch_source_attr_t attr,
	dispatch_queue_t q,
	void *context,
	dispatch_source_handler_function_t callback)
{
	dispatch_source_t ds;
	ds = dispatch_source_create(DISPATCH_SOURCE_TYPE_READ, fd, 0, q);
	return _dispatch_source_create2(ds, attr, context, callback);
}

#ifdef __BLOCKS__
dispatch_source_t
dispatch_source_write_create(int descriptor,
	dispatch_source_attr_t attr,
	dispatch_queue_t q,
	dispatch_source_handler_t callback)
{
	return dispatch_source_write_create_f(descriptor,
		attr, q, callback, _dispatch_source_call_block);
}
#endif

dispatch_source_t
dispatch_source_write_create_f(int fd,
	dispatch_source_attr_t attr,
	dispatch_queue_t q,
	void *context,
	dispatch_source_handler_function_t callback)
{
	dispatch_source_t ds;
	ds = dispatch_source_create(DISPATCH_SOURCE_TYPE_WRITE, fd, 0, q);
	return _dispatch_source_create2(ds, attr, context, callback);
}

#ifdef __BLOCKS__
dispatch_source_t
dispatch_source_vnode_create(int descriptor,
	uint64_t flags,
	dispatch_source_attr_t attr,
	dispatch_queue_t q,
	dispatch_source_handler_t callback)
{
	return dispatch_source_vnode_create_f(descriptor,
		flags, attr, q, callback, _dispatch_source_call_block);
}
#endif

dispatch_source_t
dispatch_source_vnode_create_f(int fd,
	uint64_t event_mask,
	dispatch_source_attr_t attr,
	dispatch_queue_t q,
	void *context,
	dispatch_source_handler_function_t callback)
{
	dispatch_source_t ds;
	ds = dispatch_source_create(DISPATCH_SOURCE_TYPE_VNODE, fd, (unsigned long)event_mask, q);
	return _dispatch_source_create2(ds, attr, context, callback);
}

#ifdef __BLOCKS__
dispatch_source_t
dispatch_source_signal_create(unsigned long sig,
	dispatch_source_attr_t attr,
	dispatch_queue_t q,
	dispatch_source_handler_t callback)
{
	return dispatch_source_signal_create_f(sig,
		attr, q, callback, _dispatch_source_call_block);
}
#endif

dispatch_source_t
dispatch_source_signal_create_f(unsigned long signo,
	dispatch_source_attr_t attr,
	dispatch_queue_t q,
	void *context,
	dispatch_source_handler_function_t callback)
{
	dispatch_source_t ds;
	ds = dispatch_source_create(DISPATCH_SOURCE_TYPE_SIGNAL, signo, 0, q);
	return _dispatch_source_create2(ds, attr, context, callback);
}

#ifdef __BLOCKS__
dispatch_source_t
dispatch_source_proc_create(pid_t pid,
	uint64_t flags,
	dispatch_source_attr_t attr,
	dispatch_queue_t q,
	dispatch_source_handler_t callback)
{
	return dispatch_source_proc_create_f(pid,
		flags, attr, q, callback, _dispatch_source_call_block);
}
#endif

dispatch_source_t
dispatch_source_proc_create_f(pid_t pid,
	uint64_t event_mask,
	dispatch_source_attr_t attr,
	dispatch_queue_t q,
	void *context,
	dispatch_source_handler_function_t callback)
{
	dispatch_source_t ds;
	ds = dispatch_source_create(DISPATCH_SOURCE_TYPE_PROC, pid, (unsigned long)event_mask, q);
	return _dispatch_source_create2(ds, attr, context, callback);
}

#ifdef __BLOCKS__
dispatch_source_t
dispatch_source_vfs_create(uint64_t flags,
	dispatch_source_attr_t attr,
	dispatch_queue_t q,
	dispatch_source_handler_t callback)
{
	return dispatch_source_vfs_create_f(flags,
		attr, q, callback, _dispatch_source_call_block);
}
#endif

dispatch_source_t
dispatch_source_vfs_create_f(uint64_t event_mask,
	dispatch_source_attr_t attr,
	dispatch_queue_t q,
	void *context,
	dispatch_source_handler_function_t callback)
{
	dispatch_source_t ds;
	ds = dispatch_source_create(DISPATCH_SOURCE_TYPE_VFS, 0, (unsigned long)event_mask, q);
	return _dispatch_source_create2(ds, attr, context, callback);
}

#ifdef __BLOCKS__
dispatch_source_t
dispatch_source_data_create(unsigned long behavior,
	dispatch_source_attr_t attr,
	dispatch_queue_t q,
	dispatch_source_handler_t callback)
{
	return dispatch_source_data_create_f(behavior,
		attr, q, callback, _dispatch_source_call_block);
}
#endif

#ifdef __BLOCKS__
dispatch_source_t
dispatch_source_machport_create(mach_port_t mport,
	uint64_t flags,
	dispatch_source_attr_t attr,
	dispatch_queue_t dq,
	dispatch_source_handler_t callback)
{
	return dispatch_source_machport_create_f(mport, flags,
		attr, dq, callback, _dispatch_source_call_block);
}
#endif

dispatch_source_t
dispatch_source_data_create_f(unsigned long behavior,
	dispatch_source_attr_t attr,
	dispatch_queue_t q,
	void *context,
	dispatch_source_handler_function_t callback)
{
	dispatch_source_t ds;
	dispatch_source_type_t type;
	switch (behavior) {
		case DISPATCH_SOURCE_CUSTOM_ADD:
			type = DISPATCH_SOURCE_TYPE_DATA_ADD;
			break;
		case DISPATCH_SOURCE_CUSTOM_OR:
			type = DISPATCH_SOURCE_TYPE_DATA_OR;
			break;
		default:
			return NULL;
	}
	ds = dispatch_source_create(type, 0, 0, q);
	return _dispatch_source_create2(ds, attr, context, callback);
}

dispatch_source_t
dispatch_source_machport_create_f(mach_port_t mport,
	uint64_t flags,
	dispatch_source_attr_t attr,
	dispatch_queue_t dq,
	void *ctxt,
	dispatch_source_handler_function_t func)
{
	dispatch_source_t ds;
	dispatch_source_type_t type;
	unsigned long newflags = 0;

	if (flags & ~(DISPATCH_MACHPORT_DEAD|DISPATCH_MACHPORT_RECV)) {
		return NULL;
	}
	// XXX DELETED
	if (flags & DISPATCH_MACHPORT_DEAD) {
		type = DISPATCH_SOURCE_TYPE_MACH_SEND;
		newflags |= DISPATCH_MACH_SEND_DEAD;
	} else {
		type = DISPATCH_SOURCE_TYPE_MACH_RECV;
	}

	ds = dispatch_source_create(type, mport, newflags, dq);
	return _dispatch_source_create2(ds, attr, ctxt, func);
}

#endif /* DISPATCH_NO_LEGACY */

