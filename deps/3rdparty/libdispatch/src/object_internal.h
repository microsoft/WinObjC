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

#ifndef __DISPATCH_OBJECT_INTERNAL__
#define __DISPATCH_OBJECT_INTERNAL__

enum {
	_DISPATCH_CONTINUATION_TYPE		=	 0x00000, // meta-type for continuations
	_DISPATCH_QUEUE_TYPE			=    0x10000, // meta-type for queues
	_DISPATCH_SOURCE_TYPE			=    0x20000, // meta-type for sources
	_DISPATCH_SEMAPHORE_TYPE		=    0x30000, // meta-type for semaphores
	_DISPATCH_ATTR_TYPE				= 0x10000000, // meta-type for attribute structures
	
	DISPATCH_CONTINUATION_TYPE		= _DISPATCH_CONTINUATION_TYPE,
	
	DISPATCH_QUEUE_ATTR_TYPE		= _DISPATCH_QUEUE_TYPE | _DISPATCH_ATTR_TYPE,

	DISPATCH_QUEUE_TYPE				= 1 | _DISPATCH_QUEUE_TYPE,
	DISPATCH_QUEUE_GLOBAL_TYPE		= 2 | _DISPATCH_QUEUE_TYPE,
	DISPATCH_QUEUE_MGR_TYPE			= 3 | _DISPATCH_QUEUE_TYPE,

	DISPATCH_SEMAPHORE_TYPE			= _DISPATCH_SEMAPHORE_TYPE,
	
	DISPATCH_SOURCE_ATTR_TYPE		= _DISPATCH_SOURCE_TYPE | _DISPATCH_ATTR_TYPE,
	
	DISPATCH_SOURCE_KEVENT_TYPE		= 1 | _DISPATCH_SOURCE_TYPE,
};

#define DISPATCH_VTABLE_HEADER(x)	\
	unsigned long const do_type;	\
	const char *const do_kind; \
	size_t (*const do_debug)(struct x *, char *, size_t);	\
	struct dispatch_queue_s *(*const do_invoke)(struct x *);	\
	bool (*const do_probe)(struct x *); \
	void (*const do_dispose)(struct x *)

#define dx_type(x) (x)->do_vtable->do_type
#define dx_kind(x) (x)->do_vtable->do_kind
#define dx_debug(x, y, z) (x)->do_vtable->do_debug((x), (y), (z))
#define dx_dispose(x) (x)->do_vtable->do_dispose(x)
#define dx_invoke(x) (x)->do_vtable->do_invoke(x)
#define dx_probe(x) (x)->do_vtable->do_probe(x)

#define DISPATCH_STRUCT_HEADER(x, y)	\
	const struct y *do_vtable;	\
	struct x *volatile do_next;	\
	intptr_t do_ref_cnt;	\
	intptr_t do_xref_cnt;	\
	intptr_t do_suspend_cnt;	\
	struct dispatch_queue_s *do_targetq;	\
	void *do_ctxt; \
	dispatch_function_t do_finalizer

#define DISPATCH_OBJECT_GLOBAL_REFCNT	(~0u)
#define DISPATCH_OBJECT_SUSPEND_LOCK		1u	// "word and bit" must be a power of two to be safely subtracted
#define DISPATCH_OBJECT_SUSPEND_INTERVAL	2u
#define DISPATCH_OBJECT_SUSPENDED(x)	((x)->do_suspend_cnt >= DISPATCH_OBJECT_SUSPEND_INTERVAL)
#if defined(__LP64__) || defined(__LLP64__)
// the bottom nibble must not be zero, the rest of the bits should be random
// we sign extend the 64-bit version so that a better instruction encoding is generated on Intel
#define DISPATCH_OBJECT_LISTLESS	((void *)0xffffffff89abcdef)
#else
#define DISPATCH_OBJECT_LISTLESS	((void *)0x89abcdef)
#endif

#define _dispatch_trysuspend(x) __sync_bool_compare_and_swap(&(x)->do_suspend_cnt, 0, DISPATCH_OBJECT_SUSPEND_INTERVAL)
// _dispatch_source_invoke() relies on this testing the whole suspend count
// word, not just the lock bit. In other words, no point taking the lock
// if the source is suspended or canceled.
#define _dispatch_trylock(x)	dispatch_atomic_cmpxchg(&(x)->do_suspend_cnt, 0, DISPATCH_OBJECT_SUSPEND_LOCK)

struct dispatch_object_vtable_s {
	DISPATCH_VTABLE_HEADER(dispatch_object_s);
};

struct dispatch_object_s {
	DISPATCH_STRUCT_HEADER(dispatch_object_s, dispatch_object_vtable_s);
};

size_t dispatch_object_debug_attr(dispatch_object_t dou, char* buf, size_t bufsiz);

void _dispatch_retain(dispatch_object_t dou);
void _dispatch_release(dispatch_object_t dou);
void _dispatch_dispose(dispatch_object_t dou);
dispatch_queue_t _dispatch_wakeup(dispatch_object_t dou);

#endif
