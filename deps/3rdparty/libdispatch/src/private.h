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

#ifndef __DISPATCH_PRIVATE__
#define __DISPATCH_PRIVATE__

#ifndef __DISPATCH_BUILDING_DISPATCH__
#include_next <dispatch/dispatch.h>

// Workaround <rdar://problem/6597365/>
#ifndef __DISPATCH_PUBLIC__
#include "/usr/include/dispatch/dispatch.h"
#endif

#ifndef __DISPATCH_INDIRECT__
#define __DISPATCH_INDIRECT__
#endif

#include <dispatch/benchmark.h>
#include <dispatch/queue_private.h>
#include <dispatch/source_private.h>

#ifndef DISPATCH_NO_LEGACY
#include <dispatch/legacy.h>
#endif

#undef __DISPATCH_INDIRECT__

#endif /* !__DISPATCH_BUILDING_DISPATCH__ */

/* LEGACY: Use DISPATCH_API_VERSION */
#define LIBDISPATCH_VERSION DISPATCH_API_VERSION

__DISPATCH_BEGIN_DECLS

DISPATCH_EXPORT DISPATCH_NOTHROW
void
#if USE_LIBDISPATCH_INIT_CONSTRUCTOR
libdispatch_init(void) __attribute__ ((constructor));
#else
libdispatch_init(void);
#endif

/* pthreads magic */

#if !TARGET_OS_WIN32
DISPATCH_NOTHROW void dispatch_atfork_prepare(void);
DISPATCH_NOTHROW void dispatch_atfork_parent(void);
DISPATCH_NOTHROW void dispatch_atfork_child(void);
DISPATCH_NOTHROW void dispatch_init_pthread(pthread_t);
#endif

#if HAVE_MACH
/*
 * Extract the context pointer from a mach message trailer.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
void *
dispatch_mach_msg_get_context(mach_msg_header_t *msg);
#endif

__DISPATCH_END_DECLS

#endif
