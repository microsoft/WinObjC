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

#ifndef __DISPATCH_SOURCE_INTERNAL__
#define __DISPATCH_SOURCE_INTERNAL__

#ifndef __DISPATCH_INDIRECT__
#error "Please #include <dispatch/dispatch.h> instead of this file directly."
#include <dispatch/base.h> // for HeaderDoc
#endif

struct dispatch_source_vtable_s {
	DISPATCH_VTABLE_HEADER(dispatch_source_s);
};

extern const struct dispatch_source_vtable_s _dispatch_source_kevent_vtable;

struct dispatch_kevent_s;
typedef struct dispatch_kevent_s *dispatch_kevent_t;

struct dispatch_timer_source_s {
	uint64_t target;
	uint64_t start;
	uint64_t interval;
	uint64_t leeway;
	uint64_t flags; // dispatch_timer_flags_t
};

struct dispatch_set_timer_params {
	dispatch_source_t ds;
	uintptr_t ident;
	struct dispatch_timer_source_s values;
};

#define DSF_CANCELED 1 // cancellation has been requested

struct dispatch_source_s {
	DISPATCH_STRUCT_HEADER(dispatch_source_s, dispatch_source_vtable_s);
	DISPATCH_QUEUE_HEADER;
	// Instruments always copies DISPATCH_QUEUE_MIN_LABEL_SIZE, which is 64,
	// so the remainder of the structure must be big enough
	union {
		char _ds_pad[DISPATCH_QUEUE_MIN_LABEL_SIZE];
		struct {
			char dq_label[8];
			dispatch_kevent_t ds_dkev;
			
			dispatch_function_t ds_handler_func;
			void *ds_handler_ctxt;
			
			void *ds_cancel_handler;
			
			unsigned int ds_is_level:1,
			ds_is_adder:1,
			ds_is_installed:1,
			ds_needs_rearm:1,
			ds_is_armed:1,
			ds_is_legacy:1,
			ds_cancel_is_block:1,
			ds_handler_is_block:1;

			intptr_t ds_atomic_flags;

			uintptr_t ds_data;
			uintptr_t ds_pending_data;
			uintptr_t ds_pending_data_mask;
			
			TAILQ_ENTRY(dispatch_source_s) ds_list;
			
			uintptr_t ds_ident_hack;
			
			struct dispatch_timer_source_s ds_timer;
		};
	};
};


void _dispatch_source_xref_release(dispatch_source_t ds);
dispatch_queue_t _dispatch_source_invoke(dispatch_source_t ds);
bool _dispatch_source_probe(dispatch_source_t ds);
void _dispatch_source_dispose(dispatch_source_t ds);
size_t _dispatch_source_debug(dispatch_source_t ds, char* buf, size_t bufsiz);

void _dispatch_source_kevent_resume(dispatch_source_t ds, uint32_t new_flags, uint32_t del_flags);
void _dispatch_kevent_merge(dispatch_source_t ds);
void _dispatch_kevent_release(dispatch_source_t ds);
void _dispatch_timer_list_update(dispatch_source_t ds);

struct dispatch_source_type_s {
        void *opaque;
        uint64_t mask;
        bool (*init) (dispatch_source_t ds,
                      dispatch_source_type_t type,
                      uintptr_t handle,
                      uintptr_t mask,
                      dispatch_queue_t q);
};

#define DISPATCH_TIMER_INDEX_WALL 0
#define DISPATCH_TIMER_INDEX_MACH 1

#ifdef DISPATCH_NO_LEGACY
enum {
        DISPATCH_TIMER_INTERVAL   = 0x0,
        DISPATCH_TIMER_ONESHOT    = 0x1,
        DISPATCH_TIMER_TYPE_MASK  = 0x1,
        DISPATCH_TIMER_ABSOLUTE   = 0x0,
        DISPATCH_TIMER_WALL_CLOCK = 0x2,
        DISPATCH_TIMER_CLOCK_MASK = 0x2
};
#if HAVE_MACH
enum {
        DISPATCH_MACHPORT_DEAD = 0x1,
        DISPATCH_MACHPORT_RECV = 0x2,
        DISPATCH_MACHPORT_DELETED = 0x4,
};
#endif
#endif


extern const struct dispatch_source_type_s _dispatch_source_type_timer;
extern const struct dispatch_source_type_s _dispatch_source_type_read;
extern const struct dispatch_source_type_s _dispatch_source_type_write;
extern const struct dispatch_source_type_s _dispatch_source_type_proc;
extern const struct dispatch_source_type_s _dispatch_source_type_signal;
extern const struct dispatch_source_type_s _dispatch_source_type_vnode;
extern const struct dispatch_source_type_s _dispatch_source_type_vfs;

#if HAVE_MACH
extern const struct dispatch_source_type_s _dispatch_source_type_mach_send;
extern const struct dispatch_source_type_s _dispatch_source_type_mach_recv;
#endif

extern const struct dispatch_source_type_s _dispatch_source_type_data_add;
extern const struct dispatch_source_type_s _dispatch_source_type_data_or;

extern const struct dispatch_source_type_s _dispatch_source_type_oio;

#endif /* __DISPATCH_SOURCE_INTERNAL__ */
