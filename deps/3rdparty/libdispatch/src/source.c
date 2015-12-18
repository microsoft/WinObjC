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
#if HAVE_MACH
#include "protocol.h"
#include "protocolServer.h"
#endif

static inline size_t max(size_t a, size_t b) {
    return (a > b) ? a : b;
}

#ifndef DISPATCH_NO_LEGACY
struct dispatch_source_attr_vtable_s {
	DISPATCH_VTABLE_HEADER(dispatch_source_attr_s);
};

struct dispatch_source_attr_s {
	DISPATCH_STRUCT_HEADER(dispatch_source_attr_s, dispatch_source_attr_vtable_s);
	void* finalizer_ctxt;
	dispatch_source_finalizer_function_t finalizer_func;
	void* context;
};
#endif /* DISPATCH_NO_LEGACY */

#define _dispatch_source_call_block ((void *)-1)
static void _dispatch_source_latch_and_call(dispatch_source_t ds);
static void _dispatch_source_cancel_callout(dispatch_source_t ds);
static size_t dispatch_source_debug_attr(dispatch_source_t ds, char* buf, size_t bufsiz);

void
dispatch_source_cancel(dispatch_source_t ds)
{
#if DISPATCH_DEBUG
	dispatch_debug(as_do(ds), __FUNCTION__);
#endif
	// Right after we set the cancel flag, someone else
	// could potentially invoke the source, do the cancelation, 
	// unregister the source, and deallocate it. We would
	// need to therefore retain/release before setting the bit

	_dispatch_retain(as_do(ds));
	dispatch_atomic_or(&ds->ds_atomic_flags, DSF_CANCELED);
	_dispatch_wakeup(as_do(ds));
	_dispatch_release(as_do(ds));
}

DISPATCH_NOINLINE
void
_dispatch_source_xref_release(dispatch_source_t ds)
{
#ifndef DISPATCH_NO_LEGACY
	if (ds->ds_is_legacy) {
		if (!(ds->ds_timer.flags & DISPATCH_TIMER_TYPE_MASK == DISPATCH_TIMER_ONESHOT)) {
			dispatch_source_cancel(ds);
		}
		// Clients often leave sources suspended at the last release
		dispatch_atomic_and(&ds->do_suspend_cnt, DISPATCH_OBJECT_SUSPEND_LOCK);
	} else
#endif
	if (slowpath(DISPATCH_OBJECT_SUSPENDED(ds))) {
		// Arguments for and against this assert are within 6705399
		DISPATCH_CLIENT_CRASH("Release of a suspended object");
	}
	_dispatch_wakeup(as_do(ds));
	_dispatch_release(as_do(ds));
}

long
dispatch_source_testcancel(dispatch_source_t ds)
{
	return (bool)(ds->ds_atomic_flags & DSF_CANCELED);
}

uintptr_t
dispatch_source_get_mask(dispatch_source_t ds)
{
	return ds->ds_pending_data_mask;
}

uintptr_t
dispatch_source_get_handle(dispatch_source_t ds)
{
	return ds->ds_ident_hack;
}

uintptr_t
dispatch_source_get_data(dispatch_source_t ds)
{
	return ds->ds_data;
}

dispatch_queue_t
_dispatch_source_invoke(dispatch_source_t ds)
{
	// This function performs all source actions. Each action is responsible
	// for verifying that it takes place on the appropriate queue. If the
	// current queue is not the correct queue for this action, the correct queue
	// will be returned and the invoke will be re-driven on that queue.

	// The order of tests here in invoke and in probe should be consistent.
	
	dispatch_queue_t dq = _dispatch_queue_get_current();

	if (!ds->ds_is_installed) {
		// The source needs to be installed on the manager queue.
		if (dq != &_dispatch_mgr_q) {
			return &_dispatch_mgr_q;
		}
		_dispatch_kevent_merge(ds);
	} else if ((ds->ds_atomic_flags & DSF_CANCELED) || (ds->do_xref_cnt == 0)) {
		// The source has been cancelled and needs to be uninstalled from the
		// manager queue. After uninstallation, the cancellation handler needs
		// to be delivered to the target queue.
		if (ds->ds_dkev) {
			if (dq != &_dispatch_mgr_q) {
				return &_dispatch_mgr_q;
			}
			_dispatch_kevent_release(ds);
			return ds->do_targetq;
		} else if (ds->ds_cancel_handler) {
			if (dq != ds->do_targetq) {
				return ds->do_targetq;
			}
		}	
		_dispatch_source_cancel_callout(ds);
	} else if (ds->ds_pending_data) {
		// The source has pending data to deliver via the event handler callback
		// on the target queue. Some sources need to be rearmed on the manager
		// queue after event delivery.
		if (dq != ds->do_targetq) {
			return ds->do_targetq;
		}
		_dispatch_source_latch_and_call(ds);
		if (ds->ds_needs_rearm) {
			return &_dispatch_mgr_q;
		}
	} else if (ds->ds_needs_rearm && !ds->ds_is_armed) {
		// The source needs to be rearmed on the manager queue.
		if (dq != &_dispatch_mgr_q) {
			return &_dispatch_mgr_q;
		}
		_dispatch_source_kevent_resume(ds, 0, 0);
		ds->ds_is_armed = true;
	}

	return NULL;
}

bool
_dispatch_source_probe(dispatch_source_t ds)
{
	// This function determines whether the source needs to be invoked.
	// The order of tests here in probe and in invoke should be consistent.

	if (!ds->ds_is_installed) {
		// The source needs to be installed on the manager queue.
		return true;
	} else if ((ds->ds_atomic_flags & DSF_CANCELED) || (ds->do_xref_cnt == 0)) {
		// The source needs to be uninstalled from the manager queue, or the
		// cancellation handler needs to be delivered to the target queue.
		// Note: cancellation assumes installation.
		if (ds->ds_dkev || ds->ds_cancel_handler) {
			return true;
		}
	} else if (ds->ds_pending_data) {
		// The source has pending data to deliver to the target queue.
		return true;
	} else if (ds->ds_needs_rearm && !ds->ds_is_armed) {
		// The source needs to be rearmed on the manager queue.
		return true;
	}
	// Nothing to do.
	return false;
}

void
_dispatch_source_dispose(dispatch_source_t ds)
{
	_dispatch_queue_dispose((dispatch_queue_t)ds);
}

void
_dispatch_source_latch_and_call(dispatch_source_t ds)
{
	uintptr_t prev;

	if ((ds->ds_atomic_flags & DSF_CANCELED) || (ds->do_xref_cnt == 0)) {
		return;
	}
	prev = dispatch_atomic_xchg((intptr_t*)&ds->ds_pending_data, 0);
	if (ds->ds_is_level) {
		ds->ds_data = ~prev;
	} else {
		ds->ds_data = prev;
	}
	dispatch_assume(prev);
	if (prev) {
		if (ds->ds_handler_func) {
#ifndef DISPATCH_NO_LEGACY
			((dispatch_source_handler_function_t)ds->ds_handler_func)(ds->ds_handler_ctxt, ds);
#else
			ds->ds_handler_func(ds->ds_handler_ctxt);
#endif
		}
	}
}

void
_dispatch_source_cancel_callout(dispatch_source_t ds)
{
	ds->ds_pending_data_mask = 0;
	ds->ds_pending_data = 0;
	ds->ds_data = 0;

#ifdef __BLOCKS__
	if (ds->ds_handler_is_block) {
		Block_release(ds->ds_handler_ctxt);
		ds->ds_handler_is_block = false;
		ds->ds_handler_func = NULL;
		ds->ds_handler_ctxt = NULL;
	}
#endif

	if (!ds->ds_cancel_handler) {
		return;
	}
	if (ds->ds_cancel_is_block) {
#ifdef __BLOCKS__
		dispatch_block_t b = ds->ds_cancel_handler;
		if (ds->ds_atomic_flags & DSF_CANCELED) {
			b();
		}
		Block_release(ds->ds_cancel_handler);
		ds->ds_cancel_is_block = false;
#endif
	} else {
		dispatch_function_t f = ds->ds_cancel_handler;
		if (ds->ds_atomic_flags & DSF_CANCELED) {
			f(ds->do_ctxt);
		}
	}
	ds->ds_cancel_handler = NULL;
}

size_t
dispatch_source_debug_attr(dispatch_source_t ds, char* buf, size_t bufsiz)
{
	dispatch_queue_t target = ds->do_targetq;
	return snprintf(buf, bufsiz,
			"target = %s[%p], pending_data = 0x%p, pending_data_mask = 0x%p, ",
			target ? target->dq_label : "", target,
			ds->ds_pending_data, ds->ds_pending_data_mask);
}

size_t
_dispatch_source_debug(dispatch_source_t ds, char* buf, size_t bufsiz)
{
        size_t offset = 0;
        offset += snprintf(&buf[offset], bufsiz - offset, "%s[%p] = { ", dx_kind(ds), ds);
        offset += dispatch_object_debug_attr(as_do(ds), &buf[offset], bufsiz - offset);
        offset += dispatch_source_debug_attr(ds, &buf[offset], bufsiz - offset);
        return offset;
}

#ifndef DISPATCH_NO_LEGACY
static void
dispatch_source_attr_dispose(dispatch_source_attr_t attr)
{
	// release the finalizer block if necessary
	dispatch_source_attr_set_finalizer(attr, NULL);
	_dispatch_dispose(attr);
}

static const struct dispatch_source_attr_vtable_s dispatch_source_attr_vtable = {
	.do_type = DISPATCH_SOURCE_ATTR_TYPE,
	.do_kind = "source-attr",
	.do_dispose = dispatch_source_attr_dispose,
};

dispatch_source_attr_t
dispatch_source_attr_create(void)
{
	dispatch_source_attr_t rval = calloc(1, sizeof(struct dispatch_source_attr_s));

	if (rval) {
		rval->do_vtable = &dispatch_source_attr_vtable;
		rval->do_next = DISPATCH_OBJECT_LISTLESS;
		rval->do_targetq = dispatch_get_global_queue(0, 0);
		rval->do_ref_cnt = 1;
		rval->do_xref_cnt = 1;
	}

	return rval;
}

void
dispatch_source_attr_set_finalizer_f(dispatch_source_attr_t attr,
	void *context, dispatch_source_finalizer_function_t finalizer)
{
#ifdef __BLOCKS__
	if (attr->finalizer_func == (void*)_dispatch_call_block_and_release2) {
		Block_release(attr->finalizer_ctxt);
	}
#endif

	attr->finalizer_ctxt = context;
	attr->finalizer_func = finalizer;
}

#ifdef __BLOCKS__
long
dispatch_source_attr_set_finalizer(dispatch_source_attr_t attr,
	dispatch_source_finalizer_t finalizer)
{
	void *ctxt;
	dispatch_source_finalizer_function_t func;

	if (finalizer) {
		if (!(ctxt = Block_copy(finalizer))) {
			return 1;
		}
		func = (void *)_dispatch_call_block_and_release2;
	} else {
		ctxt = NULL;
		func = NULL;
	}

	dispatch_source_attr_set_finalizer_f(attr, ctxt, func);

	return 0;
}

dispatch_source_finalizer_t
dispatch_source_attr_get_finalizer(dispatch_source_attr_t attr)
{
	if (attr->finalizer_func == (void*)_dispatch_call_block_and_release2) {
		return (dispatch_source_finalizer_t)attr->finalizer_ctxt;
	} else if (attr->finalizer_func == NULL) {
		return NULL;
	} else {
		abort(); // finalizer is not a block...
	}
}
#endif

void
dispatch_source_attr_set_context(dispatch_source_attr_t attr, void *context)
{
	attr->context = context;
}

dispatch_source_attr_t
dispatch_source_attr_copy(dispatch_source_attr_t proto)
{
	dispatch_source_attr_t rval = NULL;

	if (proto && (rval = malloc(sizeof(struct dispatch_source_attr_s)))) {
		memcpy(rval, proto, sizeof(struct dispatch_source_attr_s));
#ifdef __BLOCKS__
		if (rval->finalizer_func == (void*)_dispatch_call_block_and_release2) {
			rval->finalizer_ctxt = Block_copy(rval->finalizer_ctxt);
		}
#endif
	} else if (!proto) {
		rval = dispatch_source_attr_create();
	}
	return rval;
}
#endif /* DISPATCH_NO_LEGACY */


dispatch_source_t
dispatch_source_create(dispatch_source_type_t type,
	uintptr_t handle,
	uintptr_t mask,
	dispatch_queue_t q)
{
	dispatch_source_t ds = NULL;
	static char source_label[sizeof(ds->dq_label)] = "source";

	// input validation
	if (type == NULL || (mask & ~type->mask)) {
		goto out_bad;
	}

	ds = calloc(1ul, sizeof(struct dispatch_source_s));
	if (slowpath(!ds)) {
		goto out_bad;
	}

	// Initialize as a queue first, then override some settings below.
	_dispatch_queue_init((dispatch_queue_t)ds);
	memcpy(ds->dq_label, source_label, sizeof(source_label));

	// Dispatch Object
	ds->do_vtable = &_dispatch_source_kevent_vtable;
	ds->do_ref_cnt++; // the reference the manger queue holds
	ds->do_suspend_cnt = DISPATCH_OBJECT_SUSPEND_INTERVAL;
	// do_targetq will be retained below, past point of no-return
	ds->do_targetq = q;

	if (slowpath(!type->init(ds, type, handle, mask, q))) {
		goto out_bad;
	}

	dispatch_assert(!(ds->ds_is_level && ds->ds_is_adder));
#if DISPATCH_DEBUG
	dispatch_debug(as_do(ds), __FUNCTION__);
#endif

	_dispatch_retain(as_do(ds->do_targetq));
	return ds;
	
out_bad:
	free(ds);
	return NULL;
}

#ifdef __BLOCKS__
// 6618342 Contact the team that owns the Instrument DTrace probe before renaming this symbol
static void
_dispatch_source_set_event_handler2(void *context)
{
	struct Block_layout *bl = context;

	dispatch_source_t ds = (dispatch_source_t)_dispatch_queue_get_current();
	dispatch_assert(ds->do_vtable == &_dispatch_source_kevent_vtable);
	
	if (ds->ds_handler_is_block && ds->ds_handler_ctxt) {
		Block_release(ds->ds_handler_ctxt);
	}
	ds->ds_handler_func = bl ? (void *)bl->invoke : NULL;
	ds->ds_handler_ctxt = bl;
	ds->ds_handler_is_block = true;
}

void
dispatch_source_set_event_handler(dispatch_source_t ds, dispatch_block_t handler)
{
	dispatch_assert(!ds->ds_is_legacy);
	handler = _dispatch_Block_copy(handler);
	dispatch_barrier_async_f((dispatch_queue_t)ds,
		handler, _dispatch_source_set_event_handler2);
}
#endif /* __BLOCKS__ */

static void
_dispatch_source_set_event_handler_f(void *context)
{
	dispatch_source_t ds = (dispatch_source_t)_dispatch_queue_get_current();
	dispatch_assert(ds->do_vtable == &_dispatch_source_kevent_vtable);
	
#ifdef __BLOCKS__
	if (ds->ds_handler_is_block && ds->ds_handler_ctxt) {
		Block_release(ds->ds_handler_ctxt);
	}
#endif
	ds->ds_handler_func = context;
	ds->ds_handler_ctxt = ds->do_ctxt;
	ds->ds_handler_is_block = false;
}

void
dispatch_source_set_event_handler_f(dispatch_source_t ds,
	dispatch_function_t handler)
{
	dispatch_assert(!ds->ds_is_legacy);
	dispatch_barrier_async_f((dispatch_queue_t)ds,
		handler, _dispatch_source_set_event_handler_f);
}

#ifdef __BLOCKS__
// 6618342 Contact the team that owns the Instrument DTrace probe before renaming this symbol
static void
_dispatch_source_set_cancel_handler2(void *context)
{
	dispatch_source_t ds = (dispatch_source_t)_dispatch_queue_get_current();
	dispatch_assert(ds->do_vtable == &_dispatch_source_kevent_vtable);
	
	if (ds->ds_cancel_is_block && ds->ds_cancel_handler) {
		Block_release(ds->ds_cancel_handler);
	}
	ds->ds_cancel_handler = context;
	ds->ds_cancel_is_block = true;
}

void
dispatch_source_set_cancel_handler(dispatch_source_t ds,
	dispatch_block_t handler)
{
	dispatch_assert(!ds->ds_is_legacy);
	handler = _dispatch_Block_copy(handler);
	dispatch_barrier_async_f((dispatch_queue_t)ds,
							 handler, _dispatch_source_set_cancel_handler2);
}
#endif /* __BLOCKS__ */

static void
_dispatch_source_set_cancel_handler_f(void *context)
{
	dispatch_source_t ds = (dispatch_source_t)_dispatch_queue_get_current();
	dispatch_assert(ds->do_vtable == &_dispatch_source_kevent_vtable);
	
#ifdef __BLOCKS__
	if (ds->ds_cancel_is_block && ds->ds_cancel_handler) {
		Block_release(ds->ds_cancel_handler);
	}
#endif
	ds->ds_cancel_handler = context;
	ds->ds_cancel_is_block = false;
}

void
dispatch_source_set_cancel_handler_f(dispatch_source_t ds,
	dispatch_function_t handler)
{
	dispatch_assert(!ds->ds_is_legacy);
	dispatch_barrier_async_f((dispatch_queue_t)ds,
							 handler, _dispatch_source_set_cancel_handler_f);
}

#ifndef DISPATCH_NO_LEGACY
// 6618342 Contact the team that owns the Instrument DTrace probe before renaming this symbol
dispatch_source_t
_dispatch_source_create2(dispatch_source_t ds,
	dispatch_source_attr_t attr,
	void *context,
	dispatch_source_handler_function_t handler)
{
	if (ds == NULL || handler == NULL) {
		return NULL;
	}

	ds->ds_is_legacy = true;

	ds->ds_handler_func = (dispatch_function_t)handler;
	ds->ds_handler_ctxt = context;
		
	if (attr && attr != DISPATCH_SOURCE_CREATE_SUSPENDED) {
		ds->dq_finalizer_ctxt = attr->finalizer_ctxt;
		ds->dq_finalizer_func = (typeof(ds->dq_finalizer_func))attr->finalizer_func;
		ds->do_ctxt = attr->context;
	}
#ifdef __BLOCKS__
	if (ds->dq_finalizer_func == (void*)_dispatch_call_block_and_release2) {
		ds->dq_finalizer_ctxt = Block_copy(ds->dq_finalizer_ctxt);
		if (!ds->dq_finalizer_ctxt) {
			goto out_bad;
		}
	}
	if (handler == _dispatch_source_call_block) {
		struct Block_layout *bl = ds->ds_handler_ctxt = Block_copy(context);
		if (!ds->ds_handler_ctxt) {
			if (ds->dq_finalizer_func == (void*)_dispatch_call_block_and_release2) {
				Block_release(ds->dq_finalizer_ctxt);
			}
			goto out_bad;
		}
		ds->ds_handler_func = (void *)bl->invoke;
		ds->ds_handler_is_block = true;
	}

	// all legacy sources get a cancellation event on the normal event handler.
	dispatch_function_t func = ds->ds_handler_func;
	dispatch_source_handler_t block = ds->ds_handler_ctxt;
	void *ctxt = ds->ds_handler_ctxt;
	bool handler_is_block = ds->ds_handler_is_block;
	
	ds->ds_cancel_is_block = true;
	if (handler_is_block) {
		ds->ds_cancel_handler = _dispatch_Block_copy(^{
			block(ds);
		});
	} else {
		ds->ds_cancel_handler = _dispatch_Block_copy(^{
			((dispatch_source_handler_function_t)func)(ctxt, ds);
		});
	}
#endif
	if (attr != DISPATCH_SOURCE_CREATE_SUSPENDED) {
		dispatch_resume(ds);
	}

	return ds;

#ifdef __BLOCKS__
out_bad:
	free(ds);
	return NULL;
#endif
}

long
dispatch_source_get_error(dispatch_source_t ds, long *err_out)
{
	// 6863892 don't report ECANCELED until kevent is unregistered
	if ((ds->ds_atomic_flags & DSF_CANCELED) && !ds->ds_dkev) {
		if (err_out) {
			*err_out = ECANCELED;
		}
		return DISPATCH_ERROR_DOMAIN_POSIX;
	} else {
		return DISPATCH_ERROR_DOMAIN_NO_ERROR;
	}
}
#endif /* DISPATCH_NO_LEGACY */

// To be called from the context of the _dispatch_mgr_q
static void
_dispatch_source_set_timer2(void *context)
{
	struct dispatch_set_timer_params *params = context;
	dispatch_source_t ds = params->ds;
	ds->ds_ident_hack = params->ident;
	ds->ds_timer = params->values;
	_dispatch_timer_list_update(ds);
	dispatch_resume(as_do(ds));
	dispatch_release(as_do(ds));
	free(params);
}

void
dispatch_source_set_timer(dispatch_source_t ds,
	dispatch_time_t start,
	uint64_t interval,
	uint64_t leeway)
{
	struct dispatch_set_timer_params *params;
	
	// we use zero internally to mean disabled
	// we really don't.
	//if (interval == 0) {
	//	interval = 1;
	//} else
	if ((int64_t)interval < 0) {
		// 6866347 - make sure nanoseconds won't overflow
		interval = INT64_MAX;
	}

	// Suspend the source so that it doesn't fire with pending changes
	// The use of suspend/resume requires the external retain/release
	dispatch_retain(as_do(ds));
	dispatch_suspend(as_do(ds));
	
	if (start == DISPATCH_TIME_NOW) {
		start = _dispatch_absolute_time();
	} else if (start == DISPATCH_TIME_FOREVER) {
		start = INT64_MAX;
	}
	if ((int64_t)leeway < 0) {
		leeway = INT64_MAX;
	}

	while (!(params = malloc(sizeof(struct dispatch_set_timer_params)))) {
		sleep(1);
	}

	params->ds = ds;
	params->values.flags = ds->ds_timer.flags;

	if ((int64_t)start < 0) {
		// wall clock
		params->ident = DISPATCH_TIMER_INDEX_WALL;
		params->values.start = -((int64_t)start);
		params->values.target = -((int64_t)start);
		params->values.interval = interval;
		params->values.leeway = leeway;
		params->values.flags &= ~DISPATCH_TIMER_CLOCK_MASK;
		params->values.flags |= DISPATCH_TIMER_WALL_CLOCK;
	} else {
		// absolute clock
		params->ident = DISPATCH_TIMER_INDEX_MACH;
		params->values.start = start;
		params->values.target = start;
		params->values.interval = interval == 0 ? 0 : max(_dispatch_time_nano2mach(interval), 1); // avoid flushing small intervals to zero.
		params->values.leeway = _dispatch_time_nano2mach(leeway);
		params->values.flags &= ~DISPATCH_TIMER_CLOCK_MASK;
		params->values.flags |= DISPATCH_TIMER_ABSOLUTE;
	}

	if(interval == 0) {
		params->values.flags &= ~DISPATCH_TIMER_TYPE_MASK;
		params->values.flags |= DISPATCH_TIMER_ONESHOT;
	} else {
		params->values.flags &= ~DISPATCH_TIMER_TYPE_MASK;
		params->values.flags |= DISPATCH_TIMER_INTERVAL;
	}

	dispatch_barrier_async_f(&_dispatch_mgr_q, params, _dispatch_source_set_timer2);
}

#ifndef DISPATCH_NO_LEGACY
// LEGACY
long
dispatch_source_timer_set_time(dispatch_source_t ds, uint64_t nanoseconds, uint64_t leeway)
{
	dispatch_time_t start;
	if (nanoseconds == 0) {
		nanoseconds = 1;
	}
	if (ds->ds_timer.flags == (DISPATCH_TIMER_ABSOLUTE|DISPATCH_TIMER_WALL_CLOCK)) {
		static const struct timespec t0;
		start = dispatch_walltime(&t0, nanoseconds);
	} else if (ds->ds_timer.flags & DISPATCH_TIMER_WALL_CLOCK) {
		start = dispatch_walltime(DISPATCH_TIME_NOW, nanoseconds);
	} else {
		start = dispatch_time(DISPATCH_TIME_NOW, nanoseconds);
	}
	if (ds->ds_timer.flags & (DISPATCH_TIMER_ABSOLUTE|DISPATCH_TIMER_ONESHOT)) {
		// 6866347 - make sure nanoseconds won't overflow
		nanoseconds = INT64_MAX; // non-repeating (~292 years)
	}
	dispatch_source_set_timer(ds, start, nanoseconds, leeway);
	return 0;
}

// LEGACY
uint64_t
dispatch_event_get_nanoseconds(dispatch_source_t ds)
{
	if (ds->ds_timer.flags & DISPATCH_TIMER_WALL_CLOCK) {
		return ds->ds_timer.interval;
	} else {
		return _dispatch_time_mach2nano(ds->ds_timer.interval);
	}
}
#endif /* DISPATCH_NO_LEGACY */

