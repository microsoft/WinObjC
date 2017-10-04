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

#ifndef __DISPATCH_HW_SHIMS__
#define __DISPATCH_HW_SHIMS__

/* x86 has a 64 byte cacheline */
#define DISPATCH_CACHELINE_SIZE	64
#define ROUND_UP_TO_CACHELINE_SIZE(x)	(((x) + (DISPATCH_CACHELINE_SIZE - 1)) & ~(DISPATCH_CACHELINE_SIZE - 1))
#define ROUND_UP_TO_VECTOR_SIZE(x)	(((x) + 15) & ~15)

#if defined( __GNUC__ )
#if defined(__i386__) || defined(__x86_64__)
#define _dispatch_hardware_pause() asm("pause")
#define _dispatch_debugger() asm("int3")
#else
#define _dispatch_hardware_pause() asm("")
#define _dispatch_debugger() asm("trap")
#endif
// really just a low level abort()
#define _dispatch_hardware_crash() __builtin_trap()
#elif defined( WINOBJC )
#define _dispatch_hardware_pause() 
#define _dispatch_debugger() abort()
#define _dispatch_hardware_crash() abort()
#elif _MSC_VER
#define _dispatch_hardware_pause() YieldProcessor()
#define _dispatch_debugger() DebugBreak()
#define _dispatch_hardware_crash() (DebugBreak(), FatalExit(-1))
#endif

#endif
