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

#ifndef __DISPATCH_SEMAPHORE_INTERNAL__
#define __DISPATCH_SEMAPHORE_INTERNAL__

struct dispatch_sema_notify_s {
	struct dispatch_sema_notify_s *dsn_next;
	dispatch_queue_t dsn_queue;
	void *dsn_ctxt;
	void (*dsn_func)(void *);
};

struct dispatch_semaphore_s {
	DISPATCH_STRUCT_HEADER(dispatch_semaphore_s, dispatch_semaphore_vtable_s);
	intptr_t dsema_value;
	intptr_t dsema_orig;
	intptr_t dsema_sent_ksignals;
#if (USE_MACH_SEM + USE_POSIX_SEM + USE_WIN32_SEM) > 1
#error "Too many supported semaphore types"
#elif USE_MACH_SEM
	semaphore_t dsema_port;
	semaphore_t dsema_waiter_port;
#elif USE_POSIX_SEM
	sem_t dsema_sem;
#elif USE_WIN32_SEM
	HANDLE dsema_handle;
	HANDLE dsema_waiter_handle;
#else
#error "No supported semaphore type"
#endif
	intptr_t dsema_group_waiters;
	struct dispatch_sema_notify_s *dsema_notify_head;
	struct dispatch_sema_notify_s *dsema_notify_tail;
};

extern const struct dispatch_semaphore_vtable_s _dispatch_semaphore_vtable;

#endif
