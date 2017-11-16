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
#include "kevent_internal.h"
#include <assert.h>

#if !TARGET_OS_WIN32
static bool _dispatch_select_workaround;
static fd_set _dispatch_rfds;
static fd_set _dispatch_wfds;
static void *_dispatch_rfd_ptrs[FD_SETSIZE];
static void *_dispatch_wfd_ptrs[FD_SETSIZE];
#endif

#if TARGET_OS_WIN32
typedef HANDLE _queue_type;
#else
typedef int _queue_type;
#endif

static _queue_type _dispatch_kq;

#ifdef WINOBJC
typedef struct QueuedEvent
{
    LPOVERLAPPED result;
    ULONG_PTR completionKey;
    DWORD bytesTransferred;
    struct QueuedEvent *next;
} QueuedEvent;

typedef struct CompletionQueue
{
    CONDITION_VARIABLE cond;
    CRITICAL_SECTION mutex;
    QueuedEvent *first, *last;
} CompletionQueue;

static HANDLE CreateIoCompletionPort(
    HANDLE FileHandle,
    HANDLE ExistingCompletionPort,
    ULONG_PTR CompletionKey,
    DWORD NumberOfConcurrentThreads)
{
    assert(FileHandle == INVALID_HANDLE_VALUE && ExistingCompletionPort == NULL);

    CompletionQueue *ret = (CompletionQueue *) malloc(sizeof(CompletionQueue));
    InitializeCriticalSectionEx(&ret->mutex, 0, 0);
    InitializeConditionVariable(&ret->cond);
    ret->first = NULL;
    ret->last = NULL;

    return (HANDLE) ret;
}

static BOOL PostQueuedCompletionStatus(
    HANDLE CompletionPort,
    DWORD dwNumberOfBytesTransferred,
    ULONG_PTR dwCompletionKey,
    LPOVERLAPPED lpOverlapped
    )
{
    CompletionQueue *queue = (CompletionQueue *) CompletionPort;

    QueuedEvent *event = (QueuedEvent *) malloc(sizeof(QueuedEvent));
    event->result = lpOverlapped;
    event->bytesTransferred = dwNumberOfBytesTransferred;
    event->completionKey = dwCompletionKey;
    event->next = NULL;

    EnterCriticalSection(&queue->mutex);
    if ( queue->last == NULL ) {
        queue->last = event;
    } else {
        queue->last->next = event;
    }
    if ( queue->first == NULL ) {
        queue->first = event;
    }
    LeaveCriticalSection(&queue->mutex);
    WakeConditionVariable(&queue->cond);

    return TRUE;
}

static BOOL GetQueuedCompletionStatus(
    HANDLE CompletionPort,
    LPDWORD lpNumberOfBytesTransferred,
    PULONG_PTR lpCompletionKey,
    LPOVERLAPPED * lpOverlapped,
    DWORD dwMilliseconds)
{
    CompletionQueue *queue = (CompletionQueue *) CompletionPort;
    bool shouldWait = true;

    EnterCriticalSection(&queue->mutex);
    for ( ;; ) {
        if ( queue->first ) {
            //  Remove the event from the queue
            QueuedEvent *event = queue->first;
            queue->first = event->next;

            //  If this event is the last in the queue, there are no further queue items
            if ( queue->last == event ) {
                queue->last = NULL;
            }
            LeaveCriticalSection(&queue->mutex);
            if ( lpNumberOfBytesTransferred ) *lpNumberOfBytesTransferred = event->bytesTransferred;
            if ( lpCompletionKey ) *lpCompletionKey = event->completionKey;
            if ( lpOverlapped ) *lpOverlapped = event->result;
            free(event);
            return TRUE;
        }

        if ( !shouldWait ) {
            SetLastError(ERROR_TIMEOUT);
            return FALSE;
        }

        BOOL result = SleepConditionVariableCS(&queue->cond, &queue->mutex, dwMilliseconds);
        if ( !result ) { 
            LeaveCriticalSection(&queue->mutex);
            return FALSE;
        }

        //  Don't wait again - we'll return a timeout
        shouldWait = false;
    }
}
#endif

static void
_dispatch_get_kq_init(void *context DISPATCH_UNUSED)
{
#if TARGET_OS_WIN32
	_dispatch_kq = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 1);
	if(_dispatch_kq == NULL) {
		dispatch_assert_zero(GetLastError());
	}
#else
	static const struct kevent kev = {
		/* .ident  = */	1,
		/* .filter = */	EVFILT_USER,
		/* .flags  = */	EV_ADD|EV_CLEAR
	};

	_dispatch_kq = kqueue();
	_dispatch_safe_fork = false;
	// in case we fall back to select()
	FD_SET(_dispatch_kq, &_dispatch_rfds);

	if (_dispatch_kq == -1) {
		dispatch_assert_zero(errno);
	}

#if defined(__GNUC__)
	(void)
#endif
	dispatch_assume_zero(kevent(_dispatch_kq, &kev, 1, NULL, 0, NULL)); 
#endif

	_dispatch_queue_push(_dispatch_mgr_q.do_targetq, as_do(&_dispatch_mgr_q));
}

static _queue_type
_dispatch_get_kq(void)
{
	static dispatch_once_t pred;

	dispatch_once_f(&pred, NULL, _dispatch_get_kq_init);

	return _dispatch_kq;
}

static void
_dispatch_mgr_thread2(struct kevent *kev, size_t cnt)
{
	size_t i;

	for (i = 0; i < cnt; i++) {
		// EVFILT_USER isn't used by sources
		if (kev[i].filter == EVFILT_USER) {
			// If _dispatch_mgr_thread2() ever is changed to return to the
			// caller, then this should become _dispatch_queue_drain()
			_dispatch_queue_serial_drain_till_empty(&_dispatch_mgr_q);
		} else {
			_dispatch_source_drain_kevent(&kev[i]);
		}
	}
}

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4702) // warning C4702: unreachable code
#endif
static dispatch_queue_t
_dispatch_mgr_invoke(dispatch_queue_t dq)
{
#if TARGET_OS_WIN32
	struct timespec ts = {0};
	DWORD bytes_transferred = 0;
	ULONG_PTR completion_key = 0;
	OVERLAPPED* ol = NULL;
	DWORD timeout = 0;

	_dispatch_thread_setspecific(dispatch_queue_key, dq);

	for (;;) {
		_dispatch_run_timers();

		if(NULL != _dispatch_get_next_timer_fire(&ts)) {
			timeout = (DWORD)(ts.tv_sec * 1000) + (DWORD)((unsigned __int64)(ts.tv_nsec) / NSEC_PER_MSEC);
		} else {
			timeout = INFINITE;
		}

		SetLastError(0);
		GetQueuedCompletionStatus(_dispatch_get_kq(), &bytes_transferred, &completion_key, &ol, timeout);

		switch(GetLastError()) {
		default:
			dispatch_assume_zero(GetLastError());
			continue;
		case ERROR_SUCCESS:
			{
				struct kevent* kev = (struct kevent*)completion_key;
				if(ol) {
					kev->data = (intptr_t)ol;
				}
				_dispatch_mgr_thread2(kev, 1);
			}
			// fall through
		case WAIT_TIMEOUT:
			_dispatch_force_cache_cleanup();
			break;
		}
	}
#else
	static const struct timespec timeout_immediately = { 0, 0 };
	struct timespec timeout;
	const struct timespec *timeoutp;
	struct timeval sel_timeout, *sel_timeoutp;
	fd_set tmp_rfds, tmp_wfds;
	struct kevent kev[1];
	int k_cnt, k_err, i, r;

	_dispatch_thread_setspecific(dispatch_queue_key, dq);

	for (;;) {
		_dispatch_run_timers();

		timeoutp = _dispatch_get_next_timer_fire(&timeout);
		
		if (_dispatch_select_workaround) {
			FD_COPY(&_dispatch_rfds, &tmp_rfds);
			FD_COPY(&_dispatch_wfds, &tmp_wfds);
			if (timeoutp) {
				sel_timeout.tv_sec = timeoutp->tv_sec;
				sel_timeout.tv_usec = (typeof(sel_timeout.tv_usec))(timeoutp->tv_nsec / 1000u);
				sel_timeoutp = &sel_timeout;
			} else {
				sel_timeoutp = NULL;
			}
			
			r = select(FD_SETSIZE, &tmp_rfds, &tmp_wfds, NULL, sel_timeoutp);
			if (r == -1) {
				if (errno != EBADF) {
#if defined(__GNUC__)
					(void)
#endif
					dispatch_assume_zero(errno);
					continue;
				}
				for (i = 0; i < FD_SETSIZE; i++) {
					if (i == _dispatch_kq) {
						continue;
					}
					if (!FD_ISSET(i, &_dispatch_rfds) && !FD_ISSET(i, &_dispatch_wfds)) {
						continue;
					}
					r = dup(i);
					if (r != -1) {
						close(r);
					} else {
						FD_CLR(i, &_dispatch_rfds);
						FD_CLR(i, &_dispatch_wfds);
						_dispatch_rfd_ptrs[i] = 0;
						_dispatch_wfd_ptrs[i] = 0;
					}
				}
				continue;
			}
			
			if (r > 0) {
				for (i = 0; i < FD_SETSIZE; i++) {
					if (i == _dispatch_kq) {
						continue;
					}
					if (FD_ISSET(i, &tmp_rfds)) {
						FD_CLR(i, &_dispatch_rfds);	// emulate EV_DISABLE
						EV_SET(&kev[0], i, EVFILT_READ, EV_ADD|EV_ENABLE|EV_DISPATCH, 0, 1, _dispatch_rfd_ptrs[i]);
						_dispatch_rfd_ptrs[i] = 0;
						_dispatch_mgr_thread2(kev, 1);
					}
					if (FD_ISSET(i, &tmp_wfds)) {
						FD_CLR(i, &_dispatch_wfds);	// emulate EV_DISABLE
						EV_SET(&kev[0], i, EVFILT_WRITE, EV_ADD|EV_ENABLE|EV_DISPATCH, 0, 1, _dispatch_wfd_ptrs[i]);
						_dispatch_wfd_ptrs[i] = 0;
						_dispatch_mgr_thread2(kev, 1);
					}
				}
			}
			
			timeoutp = &timeout_immediately;
		}
		
		k_cnt = kevent(_dispatch_kq, NULL, 0, kev, sizeof(kev) / sizeof(kev[0]), timeoutp);
		k_err = errno;

		switch (k_cnt) {
		case -1:
			{
				if (k_err == EBADF) {
					DISPATCH_CLIENT_CRASH("Do not close random Unix descriptors");
				}
#if defined(__GNUC__)
				(void)
#endif
				dispatch_assume_zero(k_err);
			}
			continue;
		default:
			_dispatch_mgr_thread2(kev, (size_t)k_cnt);
			// fall through
		case 0:
			_dispatch_force_cache_cleanup();
			continue;
		}
	}
#endif

	return NULL;
}
#ifdef _MSC_VER
#pragma warning(pop)
#endif

static bool
_dispatch_mgr_wakeup(dispatch_queue_t dq)
{
	static const struct kevent kev = {
		/* .ident  = */ 1,
		/* .filter = */ EVFILT_USER,
		/* .flags  = */ 0,
		/* .fflags = */ NOTE_TRIGGER
	};

	_dispatch_debug("waking up the _dispatch_mgr_q: %p", dq);

	_dispatch_update_kq(&kev);

	return false;
}

void
_dispatch_update_kq(const struct kevent *kev)
{
#if TARGET_OS_WIN32
	switch(kev->filter) {
	case EVFILT_USER:
		{
			switch(kev->fflags) {
			case NOTE_TRIGGER:
				{
					BOOL rval = PostQueuedCompletionStatus(_dispatch_get_kq(), 0, (ULONG_PTR)(kev), NULL);
					if (rval == FALSE) { 
						dispatch_assume_zero(GetLastError());
					}
				}
				break;
			default:
				break;
			}
		}
		break;
	case EVFILT_OIO:
		{
			if(kev->flags & EV_ADD) {
				HANDLE result = CreateIoCompletionPort((HANDLE)kev->ident, _dispatch_get_kq(), (ULONG_PTR)kev, 1);
				dispatch_assert(result == _dispatch_get_kq());
			} else if(kev->flags & EV_DELETE) {
				// :( stupid win32.
			}
		}
		break;
	default:
		break;
	}
#else
	struct kevent kev_copy = *kev;
	int rval = 0;
	
	kev_copy.flags |= EV_RECEIPT;

	if (kev_copy.flags & EV_DELETE) {
		switch (kev_copy.filter) {
		case EVFILT_READ:
			if (FD_ISSET((int)kev_copy.ident, &_dispatch_rfds)) {
				FD_CLR((int)kev_copy.ident, &_dispatch_rfds);
				_dispatch_rfd_ptrs[kev_copy.ident] = 0;
				return;
			}
		case EVFILT_WRITE:
			if (FD_ISSET((int)kev_copy.ident, &_dispatch_wfds)) {
				FD_CLR((int)kev_copy.ident, &_dispatch_wfds);
				_dispatch_wfd_ptrs[kev_copy.ident] = 0;
				return;
			}
		default:
			break;
		}
	}
	
	rval = kevent(_dispatch_get_kq(), &kev_copy, 1, &kev_copy, 1, NULL);

	if (rval == -1) { 
		// If we fail to register with kevents, for other reasons aside from
		// changelist elements.
#if defined(__GNUC__)
		(void)
#endif
		dispatch_assume_zero(errno);
		//kev_copy.flags |= EV_ERROR;
		//kev_copy.data = error;
		return;
	}

	// The following select workaround only applies to adding kevents
	if (!(kev->flags & EV_ADD)) {
		return;
	}

	switch (kev_copy.data) {
	case 0:
		return;
	case EBADF:
		break;
	default:
		// If an error occurred while registering with kevent, and it was 
		// because of a kevent changelist processing && the kevent involved
		// either doing a read or write, it would indicate we were trying
		// to register a /dev/* port; fall back to select
		switch (kev_copy.filter) {
		case EVFILT_READ:
			_dispatch_select_workaround = true;
			FD_SET((int)kev_copy.ident, &_dispatch_rfds);
			_dispatch_rfd_ptrs[kev_copy.ident] = kev_copy.udata;
			break;
		case EVFILT_WRITE:
			_dispatch_select_workaround = true;
			FD_SET((int)kev_copy.ident, &_dispatch_wfds);
			_dispatch_wfd_ptrs[kev_copy.ident] = kev_copy.udata;
			break;
		default:
			_dispatch_source_drain_kevent(&kev_copy); 
			break;
		}
		break;
	}
#endif
}

static const struct dispatch_queue_vtable_s _dispatch_queue_mgr_vtable = {
	/*.do_type   = */	DISPATCH_QUEUE_MGR_TYPE,
	/*.do_kind   = */	"mgr-queue",
	/*.do_debug  = */	dispatch_queue_debug,
	/*.do_invoke = */	_dispatch_mgr_invoke,
	/*.do_probe  = */	_dispatch_mgr_wakeup,
};

// 6618342 Contact the team that owns the Instrument DTrace probe before renaming this symbol
struct dispatch_queue_s _dispatch_mgr_q = {
	/*.do_vtable               = */	&_dispatch_queue_mgr_vtable,
	/*.do_next                 = */	0,
	/*.do_ref_cnt              = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
	/*.do_xref_cnt             = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
	/*.do_suspend_cnt          = */	DISPATCH_OBJECT_SUSPEND_LOCK,
	/*.do_targetq              = */	&_dispatch_root_queues[DISPATCH_ROOT_QUEUE_COUNT - 1],
	/*.do_ctxt                 = */	0,
	/*.do_finalizer            = */	0,
	/*.dq_running              = */	0,
	/*.dq_width                = */	1,
	/*.dq_items_tail           = */	0,
	/*.dq_items_head           = */	0,
	/*.dq_serialnum            = */	2,
	/*.dq_finalizer_ctxt       = */	0,
	/*.dq_specific_q           = */	NULL,
	/*.dq_specific_list        = */	NULL,
	/*.dq_manually_drained     = */	0,
	/*.dq_is_manually_draining = */	false,
	/*.dq_label                = */	"com.apple.libdispatch-manager",
};

