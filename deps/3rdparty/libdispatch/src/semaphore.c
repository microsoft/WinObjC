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

// semaphores are too fundamental to use the dispatch_assume*() macros
#if USE_MACH_SEM
#define DISPATCH_SEMAPHORE_VERIFY_KR(x)	do {	\
		if (x) {	\
			DISPATCH_CRASH("flawed group/semaphore logic");	\
		}	\
	} while (0)
#endif
#if USE_POSIX_SEM
#define	DISPATCH_SEMAPHORE_VERIFY_RET(x) do {				\
		if ((x) == -1) {					\
			DISPATCH_CRASH("flawed group/semaphore logic");	\
		}							\
	} while (0)
#endif
#if USE_WIN32_SEM
#define	DISPATCH_SEMAPHORE_VERIFY_RET(x) do {				\
		if ((x) == 0) {					\
			DISPATCH_CRASH("flawed group/semaphore logic");	\
		}							\
	} while (0)
#endif

struct dispatch_semaphore_vtable_s {
	DISPATCH_VTABLE_HEADER(dispatch_semaphore_s);
};

static void _dispatch_semaphore_dispose(dispatch_semaphore_t dsema);
static size_t _dispatch_semaphore_debug(dispatch_semaphore_t dsema, char *buf, size_t bufsiz);
static long _dispatch_group_wake(dispatch_semaphore_t dsema);

const struct dispatch_semaphore_vtable_s _dispatch_semaphore_vtable = {
	/*.do_type    = */	DISPATCH_SEMAPHORE_TYPE,
	/*.do_kind    = */	"semaphore",
	/*.do_debug   = */	_dispatch_semaphore_debug,
	/*.do_invoke  = */	0,
	/*.do_probe   = */	0,
	/*.do_dispose = */	_dispatch_semaphore_dispose,
};

dispatch_semaphore_t
_dispatch_get_thread_semaphore(void)
{
	dispatch_semaphore_t dsema;
	
	dsema = (dispatch_semaphore_t)fastpath(_dispatch_thread_getspecific(dispatch_sema4_key));
	if (!dsema) {
		while (!(dsema = dispatch_semaphore_create(0))) {
			sleep(1);
		}
	}
	_dispatch_thread_setspecific(dispatch_sema4_key, NULL);
	return dsema;
}

void
_dispatch_put_thread_semaphore(dispatch_semaphore_t dsema)
{
	dispatch_semaphore_t old_sema = (dispatch_semaphore_t)_dispatch_thread_getspecific(dispatch_sema4_key);
	_dispatch_thread_setspecific(dispatch_sema4_key, dsema);
	if (old_sema) {
		dispatch_release(as_do(old_sema));
	}
}

dispatch_group_t
dispatch_group_create(void)
{
	return (dispatch_group_t)dispatch_semaphore_create(LONG_MAX);
}

dispatch_semaphore_t
dispatch_semaphore_create(long value)
{
	dispatch_semaphore_t dsema;
#if USE_POSIX_SEM
	int ret;
#endif
	
	// If the internal value is negative, then the absolute of the value is
	// equal to the number of waiting threads. Therefore it is bogus to
	// initialize the semaphore with a negative value.
	if (value < 0) {
		return NULL;
	}
	
	dsema = (dispatch_semaphore_t)calloc(1, sizeof(struct dispatch_semaphore_s));
	
	if (fastpath(dsema)) {
		dsema->do_vtable = &_dispatch_semaphore_vtable;
		dsema->do_next = (dispatch_semaphore_t)DISPATCH_OBJECT_LISTLESS;
		dsema->do_ref_cnt = 1;
		dsema->do_xref_cnt = 1;
		dsema->do_targetq = dispatch_get_global_queue(0, 0);
		dsema->dsema_value = value;
		dsema->dsema_orig = value;
#if USE_POSIX_SEM
		ret = sem_init(&dsema->dsema_sem, 0, 0);
		dispatch_assume_zero(ret);
#endif
	}
	
	return dsema;
}

#if USE_MACH_SEM
static void
_dispatch_semaphore_create_port(semaphore_t *s4)
{
	kern_return_t kr;
	semaphore_t tmp;

	if (*s4) {
		return;
	}
	
	// lazily allocate the semaphore port
	
	// Someday:
	// 1) Switch to a doubly-linked FIFO in user-space.
	// 2) User-space timers for the timeout.
	// 3) Use the per-thread semaphore port.
	
	while (dispatch_assume_zero(kr = semaphore_create(mach_task_self(), &tmp, SYNC_POLICY_FIFO, 0))) {
		DISPATCH_VERIFY_MIG(kr);
		sleep(1);
	}
	
	if (!dispatch_atomic_cmpxchg(s4, 0, tmp)) {
		kr = semaphore_destroy(mach_task_self(), tmp);
		DISPATCH_SEMAPHORE_VERIFY_KR(kr);
	}

	_dispatch_safe_fork = false;
}
#endif

#if USE_WIN32_SEM
static void
_dispatch_semaphore_create_handle(HANDLE *s4)
{
	HANDLE tmp;

	if (*s4) {
		return;
	}

	// lazily allocate the semaphore handle

	while ((tmp = CreateSemaphoreExW(NULL, 0, LONG_MAX, NULL, 0, EVENT_ALL_ACCESS)) == NULL) {
		dispatch_assume(tmp);
		sleep(1);
	}

	if (!dispatch_atomic_cmpxchg_pointer(s4, 0, tmp)) {
		CloseHandle(tmp);
	}
}
#endif /* USE_WIN32_SEM */

DISPATCH_NOINLINE
static long
_dispatch_semaphore_wait_slow(dispatch_semaphore_t dsema, dispatch_time_t timeout)
{
#if USE_MACH_SEM
	mach_timespec_t _timeout;
	kern_return_t kr;
#endif
#if USE_POSIX_SEM
	struct timespec _timeout;
#endif
#if USE_POSIX_SEM || USE_WIN32_SEM
	int ret;
#endif
	long orig;
	
again:
	// Mach semaphores appear to sometimes spuriously wake up.  Therefore,
	// we keep a parallel count of the number of times a Mach semaphore is
	// signaled (6880961).
	while ((orig = dsema->dsema_sent_ksignals)) {
		if (dispatch_atomic_cmpxchg(&dsema->dsema_sent_ksignals, orig, orig - 1)) {
			return 0;
		}
	}

#if USE_MACH_SEM
	_dispatch_semaphore_create_port(&dsema->dsema_port);
#endif
#if USE_WIN32_SEM
	_dispatch_semaphore_create_handle(&dsema->dsema_handle);
#endif

	// From xnu/osfmk/kern/sync_sema.c:
	// wait_semaphore->count = -1;  /* we don't keep an actual count */
	//
	// The code above does not match the documentation, and that fact is
	// not surprising. The documented semantics are clumsy to use in any
	// practical way. The above hack effectively tricks the rest of the
	// Mach semaphore logic to behave like the libdispatch algorithm.

	switch (timeout) {
	default:
#if USE_MACH_SEM
		do {
			uint64_t nsec;
			// timeout() already calculates relative time left
			nsec = _dispatch_timeout(timeout);
			_timeout.tv_sec = (typeof(_timeout.tv_sec))(nsec / NSEC_PER_SEC);
			_timeout.tv_nsec = (typeof(_timeout.tv_nsec))(nsec % NSEC_PER_SEC);
			kr = slowpath(semaphore_timedwait(dsema->dsema_port, _timeout));
		} while (kr == KERN_ABORTED);

		if (kr != KERN_OPERATION_TIMED_OUT) {
			DISPATCH_SEMAPHORE_VERIFY_KR(kr);
			break;
		}
#endif
#if USE_POSIX_SEM
		do {
			_timeout = _dispatch_timeout_ts(timeout);
			ret = slowpath(sem_timedwait(&dsema->dsema_sem,
			    &_timeout));
		} while (ret == -1 && errno == EINTR);

		if (!(ret == -1 && errno == ETIMEDOUT)) {
			DISPATCH_SEMAPHORE_VERIFY_RET(ret);
			break;
		}
#endif
#if USE_WIN32_SEM
		do {
			uint64_t nsec;
			DWORD msec;
			nsec = _dispatch_timeout(timeout);
			msec = (DWORD)(nsec / (uint64_t)1000000);
			ret = WaitForSingleObjectEx(dsema->dsema_handle, msec, FALSE);
		} while (ret != WAIT_OBJECT_0 && ret != WAIT_TIMEOUT);
		if (ret != WAIT_TIMEOUT) {
			break;
		}
#endif /* USE_WIN32_SEM */
		// Fall through and try to undo what the fast path did to dsema->dsema_value
	case DISPATCH_TIME_NOW:
		while ((orig = dsema->dsema_value) < 0) {
			if (dispatch_atomic_cmpxchg(&dsema->dsema_value, orig, orig + 1)) {
#if USE_MACH_SEM
				return KERN_OPERATION_TIMED_OUT;
#endif
#if USE_POSIX_SEM || USE_WIN32_SEM
				errno = ETIMEDOUT;
				return -1;
#endif
			}
		}
		// Another thread called semaphore_signal().
		// Fall through and drain the wakeup.
	case DISPATCH_TIME_FOREVER:
#if USE_MACH_SEM
		do {
			kr = semaphore_wait(dsema->dsema_port);
		} while (kr == KERN_ABORTED);
		DISPATCH_SEMAPHORE_VERIFY_KR(kr);
#endif
#if USE_POSIX_SEM
		do {
			ret = sem_wait(&dsema->dsema_sem);
		} while (ret != 0);
		DISPATCH_SEMAPHORE_VERIFY_RET(ret);
#endif
#if USE_WIN32_SEM
		do {
			ret = WaitForSingleObjectEx(dsema->dsema_handle, INFINITE, FALSE);
		} while (ret != WAIT_OBJECT_0);
#endif
		break;
	}

	goto again;
}

DISPATCH_NOINLINE
void
dispatch_group_enter(dispatch_group_t dg)
{
	dispatch_semaphore_t dsema = (dispatch_semaphore_t)dg;
#if USE_APPLE_SEMAPHORE_OPTIMIZATIONS && defined(__OPTIMIZE__) && defined(__GNUC__) && (defined(__x86_64__) || defined(__i386__)) && !defined(__llvm__)
	// This assumes:
	// 1) Way too much about the optimizer of GCC.
	// 2) There will never be more than LONG_MAX threads.
	//    Therefore: no overflow detection
	asm(
#ifdef __LP64__ 
		"lock decq	%0\n\t"
#else
		"lock decl	%0\n\t"
#endif
		"js 	1f\n\t"
		"ret\n\t"
		"1:"
		: "+m" (dsema->dsema_value)
		:
		: "cc"
	);
	_dispatch_semaphore_wait_slow(dsema, DISPATCH_TIME_FOREVER);
#else
	dispatch_semaphore_wait(dsema, DISPATCH_TIME_FOREVER);
#endif
}

DISPATCH_NOINLINE
long
dispatch_semaphore_wait(dispatch_semaphore_t dsema, dispatch_time_t timeout)
{
#if USE_APPLE_SEMAPHORE_OPTIMIZATIONS && defined(__OPTIMIZE__) && defined(__GNUC__) && (defined(__x86_64__) || defined(__i386__)) && !defined(__llvm__)
	// This assumes:
	// 1) Way too much about the optimizer of GCC.
	// 2) There will never be more than LONG_MAX threads.
	//    Therefore: no overflow detection
	asm(
#ifdef __LP64__ 
		"lock decq	%0\n\t"
#else
		"lock decl	%0\n\t"
#endif
		"js 	1f\n\t"
		"xor	%%eax, %%eax\n\t"
		"ret\n\t"
		"1:"
		: "+m" (dsema->dsema_value)
		:
		: "cc"
	);
#else
	if (dispatch_atomic_dec(&dsema->dsema_value) >= 0) {
		return 0;
	}
#endif
	return _dispatch_semaphore_wait_slow(dsema, timeout);
}

DISPATCH_NOINLINE
static long
_dispatch_semaphore_signal_slow(dispatch_semaphore_t dsema)
{
#if USE_POSIX_SEM || USE_WIN32_SEM
	int ret;
#endif
#if USE_MACH_SEM
	kern_return_t kr;
	
	_dispatch_semaphore_create_port(&dsema->dsema_port);
#endif
#if USE_WIN32_SEM
	_dispatch_semaphore_create_handle(&dsema->dsema_handle);
#endif

	// Before dsema_sent_ksignals is incremented we can rely on the reference
	// held by the waiter. However, once this value is incremented the waiter
	// may return between the atomic increment and the semaphore_signal(),
	// therefore an explicit reference must be held in order to safely access
	// dsema after the atomic increment.
	_dispatch_retain(as_do(dsema));
	
	dispatch_atomic_inc(&dsema->dsema_sent_ksignals);
	
#if USE_MACH_SEM
	kr = semaphore_signal(dsema->dsema_port);
	DISPATCH_SEMAPHORE_VERIFY_KR(kr);
#endif
#if USE_POSIX_SEM
	ret = sem_post(&dsema->dsema_sem);
	DISPATCH_SEMAPHORE_VERIFY_RET(ret);
#endif
#if USE_WIN32_SEM
	// Signal the semaphore.
	ret = ReleaseSemaphore(dsema->dsema_handle, 1, NULL);
	DISPATCH_SEMAPHORE_VERIFY_RET(ret);
#endif

	_dispatch_release(as_do(dsema));
	
	return 1;
}

void
dispatch_group_leave(dispatch_group_t dg)
{
	dispatch_semaphore_t dsema = (dispatch_semaphore_t)dg;

	dispatch_semaphore_signal(dsema);

	if (dsema->dsema_value == dsema->dsema_orig) {
		_dispatch_group_wake(dsema);
	}
}

DISPATCH_NOINLINE
long
dispatch_semaphore_signal(dispatch_semaphore_t dsema)
{
#if USE_APPLE_SEMAPHORE_OPTIMIZATIONS && defined(__OPTIMIZE__) && defined(__GNUC__) && (defined(__x86_64__) || defined(__i386__)) && !defined(__llvm__)
	// overflow detection
	// this assumes way too much about the optimizer of GCC
	asm(
#ifdef __LP64__ 
		"lock incq	%0\n\t"
#else
		"lock incl	%0\n\t"
#endif
		"jo 	1f\n\t"
		"jle 	2f\n\t"
		"xor	%%eax, %%eax\n\t"
		"ret\n\t"
		"1:\n\t"
		"int	$4\n\t"
		"2:"
		: "+m" (dsema->dsema_value)
		:
		: "cc"
	);
#else
	if (dispatch_atomic_inc(&dsema->dsema_value) > 0) {
		return 0;
	}
#endif
	return _dispatch_semaphore_signal_slow(dsema);
}

DISPATCH_NOINLINE
long
_dispatch_group_wake(dispatch_semaphore_t dsema)
{
	struct dispatch_sema_notify_s *tmp;
	struct dispatch_sema_notify_s *head = (struct dispatch_sema_notify_s *)dispatch_atomic_xchg_pointer(&dsema->dsema_notify_head, NULL);
	intptr_t rval = dispatch_atomic_xchg(&dsema->dsema_group_waiters, 0);
	bool do_rel = (head != NULL);
#if USE_MACH_SEM
	long kr;
#endif
#if USE_POSIX_SEM || USE_WIN32_SEM
	int ret;
#endif

	// wake any "group" waiter or notify blocks
	
	if (rval) {
#if USE_MACH_SEM
		_dispatch_semaphore_create_port(&dsema->dsema_waiter_port);
		do {
			kr = semaphore_signal(dsema->dsema_waiter_port);
			DISPATCH_SEMAPHORE_VERIFY_KR(kr);
		} while (--rval);
#endif
#if USE_POSIX_SEM
		do {
			ret = sem_post(&dsema->dsema_sem);
			DISPATCH_SEMAPHORE_VERIFY_RET(ret);
		} while (--rval);
#endif
#if USE_WIN32_SEM
		_dispatch_semaphore_create_handle(&dsema->dsema_waiter_handle);
		do {
			ret = ReleaseSemaphore(dsema->dsema_waiter_handle, 1, NULL);
			DISPATCH_SEMAPHORE_VERIFY_RET(ret);
		} while (--rval);
#endif
	}
	while (head) {
		dispatch_async_f(head->dsn_queue, head->dsn_ctxt, head->dsn_func);
		_dispatch_release(as_do(head->dsn_queue));
		do {
			tmp = head->dsn_next;
		} while (!tmp && !dispatch_atomic_cmpxchg_pointer(&dsema->dsema_notify_tail, head, NULL));
		free(head);
		head = tmp;
	}
	if (do_rel) {
		_dispatch_release(as_do(dsema));
	}
	return 0;
}

DISPATCH_NOINLINE
static long
_dispatch_group_wait_slow(dispatch_semaphore_t dsema, dispatch_time_t timeout)
{
#if USE_MACH_SEM
	mach_timespec_t _timeout;
	kern_return_t kr;
#endif
#if USE_POSIX_SEM
	struct timespec _timeout;
#endif
#if USE_POSIX_SEM || USE_WIN32_SEM
	int ret;
#endif
	size_t orig;
	
again:
	// check before we cause another signal to be sent by incrementing dsema->dsema_group_waiters
	if (dsema->dsema_value == dsema->dsema_orig) {
		return _dispatch_group_wake(dsema);
	}
	// Mach semaphores appear to sometimes spuriously wake up.  Therefore,
	// we keep a parallel count of the number of times a Mach semaphore is
	// signaled (6880961).
	(void)dispatch_atomic_inc(&dsema->dsema_group_waiters);
	// check the values again in case we need to wake any threads
	if (dsema->dsema_value == dsema->dsema_orig) {
		return _dispatch_group_wake(dsema);
	}

#if USE_MACH_SEM
	_dispatch_semaphore_create_port(&dsema->dsema_waiter_port);
#endif
#if USE_WIN32_SEM
	_dispatch_semaphore_create_handle(&dsema->dsema_waiter_handle);
#endif
	
	// From xnu/osfmk/kern/sync_sema.c:
	// wait_semaphore->count = -1;  /* we don't keep an actual count */
	//
	// The code above does not match the documentation, and that fact is
	// not surprising. The documented semantics are clumsy to use in any
	// practical way. The above hack effectively tricks the rest of the
	// Mach semaphore logic to behave like the libdispatch algorithm.
	
	switch (timeout) {
	default:
#if USE_MACH_SEM
		do {
			uint64_t nsec;
			nsec = _dispatch_timeout(timeout);
			_timeout.tv_sec = (typeof(_timeout.tv_sec))(nsec / NSEC_PER_SEC);
			_timeout.tv_nsec = (typeof(_timeout.tv_nsec))(nsec % NSEC_PER_SEC);
			kr = slowpath(semaphore_timedwait(dsema->dsema_waiter_port, _timeout));
		} while (kr == KERN_ABORTED);
		if (kr != KERN_OPERATION_TIMED_OUT) {
			DISPATCH_SEMAPHORE_VERIFY_KR(kr);
			break;
		}
#endif
#if USE_POSIX_SEM
		do {
			_timeout = _dispatch_timeout_ts(timeout);
			ret = slowpath(sem_timedwait(&dsema->dsema_sem,
			    &_timeout));
		} while (ret == -1 && errno == EINTR);

		if (!(ret == -1 && errno == ETIMEDOUT)) {
			DISPATCH_SEMAPHORE_VERIFY_RET(ret);
			break;
		}
#endif
#if USE_WIN32_SEM
		do {
			uint64_t nsec;
			DWORD msec;
			nsec = _dispatch_timeout(timeout);
			msec = (DWORD)(nsec / (uint64_t)1000000);
			ret = WaitForSingleObjectEx(dsema->dsema_waiter_handle, msec, FALSE);
		} while (ret != WAIT_OBJECT_0 && ret != WAIT_TIMEOUT);
		if (ret != WAIT_TIMEOUT) {
			break;
		}
#endif /* USE_WIN32_SEM */
		// Fall through and try to undo the earlier change to dsema->dsema_group_waiters
	case DISPATCH_TIME_NOW:
		while ((orig = dsema->dsema_group_waiters)) {
			if (dispatch_atomic_cmpxchg(&dsema->dsema_group_waiters, orig, orig - 1)) {
#if USE_MACH_SEM
				return KERN_OPERATION_TIMED_OUT;
#endif
#if USE_POSIX_SEM || USE_WIN32_SEM
				errno = ETIMEDOUT;
				return -1;
#endif
			}
		}
		// Another thread called semaphore_signal().
		// Fall through and drain the wakeup.
	case DISPATCH_TIME_FOREVER:
#if USE_MACH_SEM
		do {
			kr = semaphore_wait(dsema->dsema_waiter_port);
		} while (kr == KERN_ABORTED);
		DISPATCH_SEMAPHORE_VERIFY_KR(kr);
#endif
#if USE_POSIX_SEM
		do {
			ret = sem_wait(&dsema->dsema_sem);
		} while (ret == -1 && errno == EINTR);
		DISPATCH_SEMAPHORE_VERIFY_RET(ret);
#endif
#if USE_WIN32_SEM
		do {
			ret = WaitForSingleObjectEx(dsema->dsema_waiter_handle, INFINITE, FALSE);
		} while (ret != WAIT_OBJECT_0);
#endif

		break;
	}

	goto again;
}

long
dispatch_group_wait(dispatch_group_t dg, dispatch_time_t timeout)
{
	dispatch_semaphore_t dsema = (dispatch_semaphore_t)dg;

	if (dsema->dsema_value == dsema->dsema_orig) {
		return 0;
	}
	if (timeout == 0) {
#if USE_MACH_SEM
		return KERN_OPERATION_TIMED_OUT;
#endif
#if USE_POSIX_SEM || USE_WIN32_SEM
		errno = ETIMEDOUT;
		return (-1);
#endif
	}
	return _dispatch_group_wait_slow(dsema, timeout);
}

#ifdef __BLOCKS__
void
dispatch_group_notify(dispatch_group_t dg, dispatch_queue_t dq, dispatch_block_t db)
{
	dispatch_group_notify_f(dg, dq, _dispatch_Block_copy(db), _dispatch_call_block_and_release);
}
#endif

void
dispatch_group_notify_f(dispatch_group_t dg, dispatch_queue_t dq, void *ctxt, void (*func)(void *))
{
	dispatch_semaphore_t dsema = (dispatch_semaphore_t)dg;
	struct dispatch_sema_notify_s *dsn, *prev;

	// FIXME -- this should be updated to use the continuation cache
	while (!(dsn = (struct dispatch_sema_notify_s *)malloc(sizeof(*dsn)))) {
		sleep(1);
	}

	dsn->dsn_next = NULL;
	dsn->dsn_queue = dq;
	dsn->dsn_ctxt = ctxt;
	dsn->dsn_func = func;
	_dispatch_retain(as_do(dq));

	prev = (struct dispatch_sema_notify_s *)dispatch_atomic_xchg_pointer(&dsema->dsema_notify_tail, dsn);
	if (fastpath(prev)) {
		prev->dsn_next = dsn;
	} else {
		_dispatch_retain(as_do(dg));
		dsema->dsema_notify_head = dsn;
		if (dsema->dsema_value == dsema->dsema_orig) {
			_dispatch_group_wake(dsema);
		}
	}
}

void
_dispatch_semaphore_dispose(dispatch_semaphore_t dsema)
{
#if USE_MACH_SEM
	kern_return_t kr;
#endif
#if USE_POSIX_SEM
	int ret;
#endif
	
	if (dsema->dsema_value < dsema->dsema_orig) {
		DISPATCH_CLIENT_CRASH("Semaphore/group object deallocated while in use");
	}
	
#if USE_MACH_SEM
	if (dsema->dsema_port) {
		kr = semaphore_destroy(mach_task_self(), dsema->dsema_port);
		DISPATCH_SEMAPHORE_VERIFY_KR(kr);
	}
	if (dsema->dsema_waiter_port) {
		kr = semaphore_destroy(mach_task_self(), dsema->dsema_waiter_port);
		DISPATCH_SEMAPHORE_VERIFY_KR(kr);
	}
#endif
#if USE_POSIX_SEM
	ret = sem_destroy(&dsema->dsema_sem);
	DISPATCH_SEMAPHORE_VERIFY_RET(ret);
#endif
#if USE_WIN32_SEM
	if (dsema->dsema_handle) {
		CloseHandle(dsema->dsema_handle);
	}
	if (dsema->dsema_waiter_handle) {
		CloseHandle(dsema->dsema_waiter_handle);
	}
#endif

	_dispatch_dispose(as_do(dsema));
}

size_t
_dispatch_semaphore_debug(dispatch_semaphore_t dsema, char *buf, size_t bufsiz)
{
	size_t offset = 0;
	offset += snprintf(&buf[offset], bufsiz - offset, "%s[%p] = { ", dx_kind(dsema), dsema);
	offset += dispatch_object_debug_attr(as_do(dsema), &buf[offset], bufsiz - offset);
#if USE_MACH_SEM
	offset += snprintf(&buf[offset], bufsiz - offset, "port = 0x%u, ",
	    dsema->dsema_port);
#endif
	offset += snprintf(&buf[offset], bufsiz - offset,
	    "value = %" PRIdPTR ", orig = %" PRIdPTR " }", dsema->dsema_value, dsema->dsema_orig);
	return offset;
}

#ifdef __BLOCKS__
void
dispatch_group_async(dispatch_group_t dg, dispatch_queue_t dq, dispatch_block_t db)
{
	dispatch_group_async_f(dg, dq, _dispatch_Block_copy(db), _dispatch_call_block_and_release);
}
#endif

DISPATCH_NOINLINE
void
dispatch_group_async_f(dispatch_group_t dg, dispatch_queue_t dq, void *ctxt, void (*func)(void *))
{
	dispatch_continuation_t dc;

	_dispatch_retain(as_do(dg));
	dispatch_group_enter(dg);

	dc = _dispatch_continuation_alloc_cacheonly();
	if (dc == NULL) {
		dc = _dispatch_continuation_alloc_from_heap();
	}

	dc->do_vtable = (void *)(uintptr_t)(DISPATCH_OBJ_ASYNC_BIT|DISPATCH_OBJ_GROUP_BIT);
	dc->dc_func = func;
	dc->dc_ctxt = ctxt;
	dc->dc_group = dg;

	_dispatch_queue_push(dq, as_do(dc));
}
