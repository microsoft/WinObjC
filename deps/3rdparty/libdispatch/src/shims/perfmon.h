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

#ifndef __DISPATCH_SHIMS_PERFMON__
#define __DISPATCH_SHIMS_PERFMON__

#if DISPATCH_PERF_MON

#if defined (USE_APPLE_TSD_OPTIMIZATIONS) && defined(SIMULATE_5491082) && (defined(__i386__) || defined(__x86_64__))
#ifdef __LP64__
#define _dispatch_workitem_inc()	asm("incq %%gs:%0" : "+m"	\
		(*(void **)(dispatch_bcounter_key * sizeof(void *) + _PTHREAD_TSD_OFFSET)) :: "cc")
#define _dispatch_workitem_dec()	asm("decq %%gs:%0" : "+m"	\
		(*(void **)(dispatch_bcounter_key * sizeof(void *) + _PTHREAD_TSD_OFFSET)) :: "cc")
#else
#define _dispatch_workitem_inc()	asm("incl %%gs:%0" : "+m"	\
		(*(void **)(dispatch_bcounter_key * sizeof(void *) + _PTHREAD_TSD_OFFSET)) :: "cc")
#define _dispatch_workitem_dec()	asm("decl %%gs:%0" : "+m"	\
		(*(void **)(dispatch_bcounter_key * sizeof(void *) + _PTHREAD_TSD_OFFSET)) :: "cc")
#endif
#else /* !USE_APPLE_TSD_OPTIMIZATIONS */
static DISPATCH_INLINE void
_dispatch_workitem_inc(void)
{
	uintptr_t cnt = (uintptr_t)_dispatch_thread_getspecific(dispatch_bcounter_key);
	_dispatch_thread_setspecific(dispatch_bcounter_key, (void *)++cnt);
}
static DISPATCH_INLINE void
_dispatch_workitem_dec(void)
{
	uintptr_t cnt = (uintptr_t)_dispatch_thread_getspecific(dispatch_bcounter_key);
	_dispatch_thread_setspecific(dispatch_bcounter_key, (void *)--cnt);
}
#endif /* USE_APPLE_TSD_OPTIMIZATIONS */

// C99 doesn't define flsll() or ffsll()
#if defined(__LP64__)
#define flsll(x) flsl(x)
#elif !defined(__LLP64__)
static DISPATCH_INLINE unsigned int
flsll(uint64_t val)
{
	union {
		struct {
#ifdef __BIG_ENDIAN__
			unsigned int hi, low;
#else
			unsigned int low, hi;
#endif
		} words;
		uint64_t word;
	} _bucket = { 0 };

	_bucket.word = val;
	
	if (_bucket.words.hi) {
		return fls(_bucket.words.hi) + 32;
	}
	return fls(_bucket.words.low);
}
#endif

#else
#define _dispatch_workitem_inc()
#define _dispatch_workitem_dec()
#endif	// DISPATCH_PERF_MON

#endif /* __DISPATCH_SHIMS_PERFMON__ */
