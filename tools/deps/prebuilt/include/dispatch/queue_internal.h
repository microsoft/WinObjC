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

#ifndef __DISPATCH_QUEUE_INTERNAL__
#define __DISPATCH_QUEUE_INTERNAL__

#ifndef __DISPATCH_INDIRECT__
#error "Please #include <dispatch/dispatch.h> instead of this file directly."
#include <dispatch/base.h> // for HeaderDoc
#endif

#define DISPATCH_OBJ_ASYNC_BIT	0x1
#define DISPATCH_OBJ_BARRIER_BIT	0x2
#define DISPATCH_OBJ_GROUP_BIT	0x4
// vtables are pointers far away from the low page in memory
#define DISPATCH_OBJ_IS_VTABLE(x)	((uintptr_t)(x)->do_vtable > 127ul)

struct dispatch_queue_vtable_s {
	DISPATCH_VTABLE_HEADER(dispatch_queue_s);
};

extern const struct dispatch_queue_vtable_s _dispatch_queue_vtable;

#define DISPATCH_QUEUE_MIN_LABEL_SIZE	64

DISPATCH_DECL(dispatch_queue_specific_list);
DISPATCH_DECL(dispatch_queue_specific);

#ifndef DISPATCH_NO_LEGACY
#define DISPATCH_QUEUE_HEADER \
	intptr_t dq_running; \
	intptr_t dq_width; \
	struct dispatch_object_s *dq_items_tail; \
	struct dispatch_object_s *volatile dq_items_head; \
	intptr_t dq_serialnum; \
	void *dq_finalizer_ctxt; \
	struct dispatch_queue_s *dq_specific_q; \
	struct dispatch_queue_specific_list_s *dq_specific_list; \
	dispatch_queue_finalizer_function_t dq_finalizer_func
#else
#define DISPATCH_QUEUE_HEADER \
	intptr_t dq_running; \
	intptr_t dq_width; \
	struct dispatch_object_s *dq_items_tail; \
	struct dispatch_object_s *volatile dq_items_head; \
	intptr_t dq_serialnum; \
	void *dq_finalizer_ctxt; \
	struct dispatch_queue_s *dq_specific_q; \
	struct dispatch_queue_specific_list_s *dq_specific_list; \
	void* dq_manually_drained; \
	bool dq_is_manually_draining
#endif

struct dispatch_queue_specific_list_s {
	TAILQ_HEAD(dispatch_queue_specific_head_s, dispatch_queue_specific_s) context_list;
};

struct dispatch_queue_specific_s {
	const void *key;
	void *context;
	dispatch_function_t destructor;
	TAILQ_ENTRY(dispatch_queue_specific_s) specific;
};

struct dispatch_queue_s {
	DISPATCH_STRUCT_HEADER(dispatch_queue_s, dispatch_queue_vtable_s);
	DISPATCH_QUEUE_HEADER;
	char dq_label[DISPATCH_QUEUE_MIN_LABEL_SIZE];	// must be last
};

extern struct dispatch_queue_s _dispatch_mgr_q;

#define DISPATCH_ROOT_QUEUE_COUNT (DISPATCH_QUEUE_PRIORITY_COUNT * 2)
extern struct dispatch_queue_s _dispatch_root_queues[];

void _dispatch_queue_init(dispatch_queue_t dq);
void _dispatch_queue_drain(dispatch_queue_t dq);
void _dispatch_queue_dispose(dispatch_queue_t dq);
void _dispatch_queue_push_list_slow(dispatch_queue_t dq, struct dispatch_object_s *obj);
void _dispatch_queue_serial_drain_till_empty(dispatch_queue_t dq);
void _dispatch_force_cache_cleanup(void);

DISPATCH_INLINE
static void
_dispatch_queue_push_list(dispatch_queue_t dq, dispatch_object_t _head, dispatch_object_t _tail)
{
	struct dispatch_object_s *prev, *head = _head._do, *tail = _tail._do;

	tail->do_next = NULL;
	prev = fastpath(dispatch_atomic_xchg_pointer(&dq->dq_items_tail, tail));
	if (prev) {
		// if we crash here with a value less than 0x1000, then we are at a known bug in client code
		// for example, see _dispatch_queue_dispose or _dispatch_atfork_child
		prev->do_next = head;
	} else {
		_dispatch_queue_push_list_slow(dq, head);
	}
}

#define _dispatch_queue_push(x, y) _dispatch_queue_push_list((x), (y), (y))

#define DISPATCH_QUEUE_PRIORITY_COUNT 3

#if DISPATCH_DEBUG
void dispatch_debug_queue(dispatch_queue_t dq, const char* str);
#else
static DISPATCH_INLINE void dispatch_debug_queue(dispatch_queue_t dq DISPATCH_UNUSED, const char* str DISPATCH_UNUSED) {}
#endif

size_t dispatch_queue_debug(dispatch_queue_t dq, char* buf, size_t bufsiz);
size_t dispatch_queue_debug_attr(dispatch_queue_t dq, char* buf, size_t bufsiz);

static DISPATCH_INLINE dispatch_queue_t
_dispatch_queue_get_current(void)
{
	return _dispatch_thread_getspecific(dispatch_queue_key);
}

#endif