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

void
dispatch_debug(dispatch_object_t obj, const char *msg, ...)
{
	va_list ap;

	va_start(ap, msg);

	dispatch_debugv(obj, msg, ap);

	va_end(ap);
}

void
dispatch_debugv(dispatch_object_t dou, const char *msg, va_list ap)
{
	char buf[4096];
	size_t offs;

	struct dispatch_object_s *obj = dou._do;

	if (obj && obj->do_vtable->do_debug) {
		offs = dx_debug(obj, buf, sizeof(buf));
	} else {
		offs = snprintf(buf, sizeof(buf), "NULL vtable slot");
	}

	snprintf(buf + offs, sizeof(buf) - offs, ": %s", msg);

	_dispatch_logv(buf, ap);
}

void
dispatch_retain(dispatch_object_t dou)
{
	struct dispatch_object_s *obj = dou._do;

	if (obj->do_xref_cnt == DISPATCH_OBJECT_GLOBAL_REFCNT) {
		return; // global object
	}
	if ((dispatch_atomic_inc(&obj->do_xref_cnt) - 1) == 0) {
		DISPATCH_CLIENT_CRASH("Resurrection of an object");
	}
}

void
_dispatch_retain(dispatch_object_t dou)
{
	struct dispatch_object_s *obj = dou._do;

	if (obj->do_ref_cnt == DISPATCH_OBJECT_GLOBAL_REFCNT) {
		return; // global object
	}
	if ((dispatch_atomic_inc(&obj->do_ref_cnt) - 1) == 0) {
		DISPATCH_CLIENT_CRASH("Resurrection of an object");
	}
}

void
dispatch_release(dispatch_object_t dou)
{
	struct dispatch_object_s *obj = dou._do;

	uintptr_t oldval;

	if (obj->do_xref_cnt == DISPATCH_OBJECT_GLOBAL_REFCNT) {
		return;
	}

	oldval = dispatch_atomic_dec(&obj->do_xref_cnt) + 1;
	
	if (fastpath(oldval > 1)) {
		return;
	}
	if (oldval == 1) {
		if ((uintptr_t)obj->do_vtable == (uintptr_t)&_dispatch_source_kevent_vtable) {
			_dispatch_source_xref_release((dispatch_source_t)obj);
			return;
		}
		if (slowpath(DISPATCH_OBJECT_SUSPENDED(obj))) {
			// Arguments for and against this assert are within 6705399
			DISPATCH_CLIENT_CRASH("Release of a suspended object");
		}
		_dispatch_release(as_do(obj));
		return;
	}
	DISPATCH_CLIENT_CRASH("Over-release of an object");
}

void
_dispatch_dispose(dispatch_object_t dou)
{
	struct dispatch_object_s *obj = dou._do;

	dispatch_queue_t tq = obj->do_targetq;
	dispatch_function_t func = obj->do_finalizer;
	void *ctxt = obj->do_ctxt;

	obj->do_vtable = (struct dispatch_object_vtable_s *)(uintptr_t)0x200;

	free(obj);

	if (func && ctxt) {
		dispatch_async_f(tq, ctxt, func);
	}
	_dispatch_release(as_do(tq));
}

void
_dispatch_release(dispatch_object_t dou)
{
	struct dispatch_object_s *obj = dou._do;

	uintptr_t oldval;

	if (obj->do_ref_cnt == DISPATCH_OBJECT_GLOBAL_REFCNT) {
		return; // global object
	}

	oldval = dispatch_atomic_dec(&obj->do_ref_cnt) + 1;
	
	if (fastpath(oldval > 1)) {
		return;
	}
	if (oldval == 1) {
		if (obj->do_next != DISPATCH_OBJECT_LISTLESS) {
			DISPATCH_CRASH("release while enqueued");
		}
		if (obj->do_xref_cnt) {
			DISPATCH_CRASH("release while external references exist");
		}
		dx_dispose(obj);
		return;
	}
	DISPATCH_CRASH("over-release");
}

void *
dispatch_get_context(dispatch_object_t dou)
{
	struct dispatch_object_s *obj = dou._do;

	return obj->do_ctxt;
}

void
dispatch_set_context(dispatch_object_t dou, void *context)
{
	struct dispatch_object_s *obj = dou._do;

	if (obj->do_ref_cnt != DISPATCH_OBJECT_GLOBAL_REFCNT) {
		obj->do_ctxt = context;
	}
}

void
dispatch_set_finalizer_f(dispatch_object_t dou, dispatch_function_t finalizer)
{
	struct dispatch_object_s *obj = dou._do;

	obj->do_finalizer = finalizer;
}

void
dispatch_suspend(dispatch_object_t dou)
{
	struct dispatch_object_s *obj = dou._do;

	if (slowpath(obj->do_ref_cnt == DISPATCH_OBJECT_GLOBAL_REFCNT)) {
		return;
	}
	(void)dispatch_atomic_add(&obj->do_suspend_cnt, DISPATCH_OBJECT_SUSPEND_INTERVAL);
}

void
dispatch_resume(dispatch_object_t dou)
{
	struct dispatch_object_s *obj = dou._do;

	// Global objects cannot be suspended or resumed. This also has the
	// side effect of saturating the suspend count of an object and
	// guarding against resuming due to overflow.
	if (slowpath(obj->do_ref_cnt == DISPATCH_OBJECT_GLOBAL_REFCNT)) {
		return;
	}

	// Switch on the previous value of the suspend count.  If the previous
	// value was a single suspend interval, the object should be resumed.
	// If the previous value was less than the suspend interval, the object
	// has been over-resumed.
	switch (dispatch_atomic_sub(&obj->do_suspend_cnt, DISPATCH_OBJECT_SUSPEND_INTERVAL) + DISPATCH_OBJECT_SUSPEND_INTERVAL) {
	case DISPATCH_OBJECT_SUSPEND_INTERVAL:
		_dispatch_wakeup(as_do(obj));
		break;
	case DISPATCH_OBJECT_SUSPEND_LOCK:
	case 0:
		DISPATCH_CLIENT_CRASH("Over-resume of an object");
		break;
	default:
		break;
	}
}

size_t
dispatch_object_debug_attr(dispatch_object_t dou, char* buf, size_t bufsiz)
{
	struct dispatch_object_s *obj = dou._do;

	return snprintf(buf, bufsiz, "refcnt = 0x%p, suspend_cnt = 0x%p, ",
					obj->do_ref_cnt, obj->do_suspend_cnt);
}
