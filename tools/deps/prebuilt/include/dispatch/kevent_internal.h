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

#ifndef __DISPATCH_KEVENT_INTERNAL__
#define __DISPATCH_KEVENT_INTERNAL__

#include "internal.h"

struct dispatch_kevent_s {
	TAILQ_ENTRY(dispatch_kevent_s) dk_list;
	TAILQ_HEAD(, dispatch_source_s) dk_sources;
	struct kevent dk_kevent;
};

extern const struct dispatch_source_vtable_s _dispatch_source_kevent_vtable;

#if DISPATCH_DEBUG
void dispatch_debug_kevents(struct kevent* kev, size_t count, const char* str);
#else
#define dispatch_debug_kevents(x, y, z)
#endif

void _dispatch_source_drain_kevent(struct kevent *);
void _dispatch_update_kq(const struct kevent *);

#endif /* __DISPATCH_KEVENT_INTERNAL__ */
