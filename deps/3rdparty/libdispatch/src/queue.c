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
#if HAVE_MACH
#include "protocol.h"
#endif

#if defined(_MSC_VER)
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

static dispatch_once_t _dispatch_root_queues_pred;
static void _dispatch_root_queues_init(void *);

void
dummy_function(void)
{
}

long
dummy_function_r0(void)
{
	return 0;
}

static struct dispatch_semaphore_s _dispatch_thread_mediator[] = {
	{
		/*.do_vtable   = */	&_dispatch_semaphore_vtable,
		/*.do_next     = */	0,
		/*.do_ref_cnt  = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_xref_cnt = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
	},
	{
		/*.do_vtable   = */	&_dispatch_semaphore_vtable,
		/*.do_next     = */	0,
		/*.do_ref_cnt  = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_xref_cnt = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
	},
	{
		/*.do_vtable   = */	&_dispatch_semaphore_vtable,
		/*.do_next     = */	0,
		/*.do_ref_cnt  = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_xref_cnt = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
	},
	{
		/*.do_vtable   = */	&_dispatch_semaphore_vtable,
		/*.do_next     = */	0,
		/*.do_ref_cnt  = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_xref_cnt = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
	},
	{
		/*.do_vtable   = */	&_dispatch_semaphore_vtable,
		/*.do_next     = */	0,
		/*.do_ref_cnt  = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_xref_cnt = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
	},
	{
		/*.do_vtable   = */	&_dispatch_semaphore_vtable,
		/*.do_next     = */	0,
		/*.do_ref_cnt  = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_xref_cnt = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
	},
};

static DISPATCH_INLINE dispatch_queue_t
_dispatch_get_root_queue(long priority, bool overcommit)
{
	if (overcommit) switch (priority) {
	case DISPATCH_QUEUE_PRIORITY_LOW:
		return &_dispatch_root_queues[1];
	case DISPATCH_QUEUE_PRIORITY_DEFAULT:
		return &_dispatch_root_queues[3];
	case DISPATCH_QUEUE_PRIORITY_HIGH:
		return &_dispatch_root_queues[5];
	}
	switch (priority) {
	case DISPATCH_QUEUE_PRIORITY_LOW:
		return &_dispatch_root_queues[0];
	case DISPATCH_QUEUE_PRIORITY_DEFAULT:
		return &_dispatch_root_queues[2];
	case DISPATCH_QUEUE_PRIORITY_HIGH:
		return &_dispatch_root_queues[4];
	default:
		return NULL;
	}
}

#ifdef __BLOCKS__
dispatch_block_t
_dispatch_Block_copy(dispatch_block_t db)
{
	dispatch_block_t rval;

	while (!(rval = Block_copy(db))) {
		sleep(1);
	}

	return rval;
}
#define _dispatch_Block_copy(x) ((typeof(x))_dispatch_Block_copy(x))

void
_dispatch_call_block_and_release(void *block)
{
	void (^b)(void) = block;
	b();
	Block_release(b);
}

void
_dispatch_call_block_and_release2(void *block, void *ctxt)
{
	void (^b)(void*) = block;
	b(ctxt);
	Block_release(b);
}

#endif /* __BLOCKS__ */

struct dispatch_queue_attr_vtable_s {
	DISPATCH_VTABLE_HEADER(dispatch_queue_attr_s);
};

struct dispatch_queue_attr_s {
	DISPATCH_STRUCT_HEADER(dispatch_queue_attr_s, dispatch_queue_attr_vtable_s);

#ifndef DISPATCH_NO_LEGACY
	// Public:
	int qa_priority;
	void* finalizer_ctxt;
	dispatch_queue_finalizer_function_t finalizer_func;

	// Private:
	unsigned long qa_flags;
#endif
};

#if !TARGET_OS_WIN32
static int _dispatch_pthread_sigmask(int how, sigset_t *set, sigset_t *oset);
#endif

#define _dispatch_queue_trylock(dq) dispatch_atomic_cmpxchg(&(dq)->dq_running, 0, 1)

static DISPATCH_INLINE void _dispatch_queue_unlock(dispatch_queue_t dq);
static void _dispatch_queue_invoke(dispatch_queue_t dq);
static bool _dispatch_queue_wakeup_global(dispatch_queue_t dq);
static struct dispatch_object_s *_dispatch_queue_concurrent_drain_one(dispatch_queue_t dq);

const struct dispatch_queue_vtable_s _dispatch_queue_vtable = {
	/*.do_type    = */	DISPATCH_QUEUE_TYPE,
	/*.do_kind    = */	"queue",
	/*.do_debug   = */	dispatch_queue_debug,
	/*.do_invoke  = */	(struct dispatch_queue_s *(*)(struct dispatch_queue_s *))dummy_function_r0,
	/*.do_probe   = */	(bool(*)(struct dispatch_queue_s*))dummy_function_r0,
	/*.do_dispose = */	_dispatch_queue_dispose,
};

static const struct dispatch_queue_vtable_s _dispatch_queue_root_vtable = {
	/*.do_type    = */	DISPATCH_QUEUE_GLOBAL_TYPE,
	/*.do_kind    = */	"global-queue",
	/*.do_debug   = */	dispatch_queue_debug,
	/*.do_invoke  = */	0,
	/*.do_probe   = */	_dispatch_queue_wakeup_global,
	/*.do_dispose = */	0,
};

#define MAX_THREAD_COUNT 255

struct dispatch_root_queue_context_s {
#if HAVE_PTHREAD_WORKQUEUES
	pthread_workqueue_t dgq_kworkqueue;
#endif
	intptr_t dgq_pending;
	intptr_t dgq_thread_pool_size;
	dispatch_semaphore_t dgq_thread_mediator;
};

static struct dispatch_root_queue_context_s _dispatch_root_queue_contexts[] = {
	{
#if HAVE_PTHREAD_WORKQUEUES
		/*.dgq_kworkqueue       = */	0,
#endif
		/*.dgq_pending          = */	0,
		/*.dgq_thread_pool_size = */	MAX_THREAD_COUNT,
		/*.dgq_thread_mediator  = */	&_dispatch_thread_mediator[0],
	},
	{
#if HAVE_PTHREAD_WORKQUEUES
		/*.dgq_kworkqueue       = */	0,
#endif
		/*.dgq_pending          = */	0,
		/*.dgq_thread_pool_size = */	MAX_THREAD_COUNT,
		/*.dgq_thread_mediator  = */	&_dispatch_thread_mediator[1],
	},
	{
#if HAVE_PTHREAD_WORKQUEUES
		/*.dgq_kworkqueue       = */	0,
#endif
		/*.dgq_pending          = */	0,
		/*.dgq_thread_pool_size = */	MAX_THREAD_COUNT,
		/*.dgq_thread_mediator  = */	&_dispatch_thread_mediator[2],
	},
	{
#if HAVE_PTHREAD_WORKQUEUES
		/*.dgq_kworkqueue       = */	0,
#endif
		/*.dgq_pending          = */	0,
		/*.dgq_thread_pool_size = */	MAX_THREAD_COUNT,
		/*.dgq_thread_mediator  = */	&_dispatch_thread_mediator[3],
	},
	{
#if HAVE_PTHREAD_WORKQUEUES
		/*.dgq_kworkqueue       = */	0,
#endif
		/*.dgq_pending          = */	0,
		/*.dgq_thread_pool_size = */	MAX_THREAD_COUNT,
		/*.dgq_thread_mediator  = */	&_dispatch_thread_mediator[4],
	},
	{
#if HAVE_PTHREAD_WORKQUEUES
		/*.dgq_kworkqueue       = */	0,
#endif
		/*.dgq_pending          = */	0,
		/*.dgq_thread_pool_size = */	MAX_THREAD_COUNT,
		/*.dgq_thread_mediator  = */	&_dispatch_thread_mediator[5],
	},
};

// 6618342 Contact the team that owns the Instrument DTrace probe before renaming this symbol
// dq_running is set to 2 so that barrier operations go through the slow path
struct dispatch_queue_s _dispatch_root_queues[] = {
	{
		/*.do_vtable               = */	&_dispatch_queue_root_vtable,
		/*.do_next                 = */	0,
		/*.do_ref_cnt              = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_xref_cnt             = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_suspend_cnt          = */	DISPATCH_OBJECT_SUSPEND_LOCK,
		/*.do_targetq              = */	0,
		/*.do_ctxt                 = */	&_dispatch_root_queue_contexts[0],
		/*.do_finalizer            = */	0,
		/*.dq_running              = */	2,
		/*.dq_width                = */	INTPTR_MAX,
		/*.dq_items_tail           = */	0,
		/*.dq_items_head           = */	0,
		/*.dq_serialnum            = */	4,
		/*.dq_finalizer_ctxt       = */	0,
		/*.dq_specific_q           = */	NULL,
		/*.dq_specific_list        = */	NULL,
		/*.dq_manually_drained     = */	0,
		/*.dq_is_manually_draining = */	false,
		/*.dq_label                = */	"com.apple.root.low-priority",
	},
	{
		/*.do_vtable               = */	&_dispatch_queue_root_vtable,
		/*.do_next                 = */	0,
		/*.do_ref_cnt              = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_xref_cnt             = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_suspend_cnt          = */	DISPATCH_OBJECT_SUSPEND_LOCK,
		/*.do_targetq              = */	0,
		/*.do_ctxt                 = */	&_dispatch_root_queue_contexts[1],
		/*.do_finalizer            = */	0,
		/*.dq_running              = */	2,
		/*.dq_width                = */	INTPTR_MAX,
		/*.dq_items_tail           = */	0,
		/*.dq_items_head           = */	0,
		/*.dq_serialnum            = */	5,
		/*.dq_finalizer_ctxt       = */	0,
		/*.dq_specific_q           = */	NULL,
		/*.dq_specific_list        = */	NULL,
		/*.dq_manually_drained     = */	0,
		/*.dq_is_manually_draining = */	false,
		/*.dq_label                = */	"com.apple.root.low-overcommit-priority",
	},
	{
		/*.do_vtable               = */	&_dispatch_queue_root_vtable,
		/*.do_next                 = */	0,
		/*.do_ref_cnt              = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_xref_cnt             = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_suspend_cnt          = */	DISPATCH_OBJECT_SUSPEND_LOCK,
		/*.do_targetq              = */	0,
		/*.do_ctxt                 = */	&_dispatch_root_queue_contexts[2],
		/*.do_finalizer            = */	0,
		/*.dq_running              = */	2,
		/*.dq_width                = */	INTPTR_MAX,
		/*.dq_items_tail           = */	0,
		/*.dq_items_head           = */	0,
		/*.dq_serialnum            = */	6,
		/*.dq_finalizer_ctxt       = */	0,
		/*.dq_specific_q           = */	NULL,
		/*.dq_specific_list        = */	NULL,
		/*.dq_manually_drained     = */	0,
		/*.dq_is_manually_draining = */	false,
		/*.dq_label                = */	"com.apple.root.default-priority",
	},
	{
		/*.do_vtable               = */	&_dispatch_queue_root_vtable,
		/*.do_next                 = */	0,
		/*.do_ref_cnt              = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_xref_cnt             = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_suspend_cnt          = */	DISPATCH_OBJECT_SUSPEND_LOCK,
		/*.do_targetq              = */	0,
		/*.do_ctxt                 = */	&_dispatch_root_queue_contexts[3],
		/*.do_finalizer            = */	0,
		/*.dq_running              = */	2,
		/*.dq_width                = */	INTPTR_MAX,
		/*.dq_items_tail           = */	0,
		/*.dq_items_head           = */	0,
		/*.dq_serialnum            = */	7,
		/*.dq_finalizer_ctxt       = */	0,
		/*.dq_specific_q           = */	NULL,
		/*.dq_specific_list        = */	NULL,
		/*.dq_manually_drained     = */	0,
		/*.dq_is_manually_draining = */	false,
		/*.dq_label                = */	"com.apple.root.default-overcommit-priority",
	},
	{
		/*.do_vtable               = */	&_dispatch_queue_root_vtable,
		/*.do_next                 = */	0,
		/*.do_ref_cnt              = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_xref_cnt             = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_suspend_cnt          = */	DISPATCH_OBJECT_SUSPEND_LOCK,
		/*.do_targetq              = */	0,
		/*.do_ctxt                 = */	&_dispatch_root_queue_contexts[4],
		/*.do_finalizer            = */	0,
		/*.dq_running              = */	2,
		/*.dq_width                = */	INTPTR_MAX,
		/*.dq_items_tail           = */	0,
		/*.dq_items_head           = */	0,
		/*.dq_serialnum            = */	8,
		/*.dq_finalizer_ctxt       = */	0,
		/*.dq_specific_q           = */	NULL,
		/*.dq_specific_list        = */	NULL,
		/*.dq_manually_drained     = */	0,
		/*.dq_is_manually_draining = */	false,
		/*.dq_label                = */	"com.apple.root.high-priority",
	},
	{
		/*.do_vtable               = */	&_dispatch_queue_root_vtable,
		/*.do_next                 = */	0,
		/*.do_ref_cnt              = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_xref_cnt             = */	DISPATCH_OBJECT_GLOBAL_REFCNT,
		/*.do_suspend_cnt          = */	DISPATCH_OBJECT_SUSPEND_LOCK,
		/*.do_targetq              = */	0,
		/*.do_ctxt                 = */	&_dispatch_root_queue_contexts[5],
		/*.do_finalizer            = */	0,
		/*.dq_running              = */	2,
		/*.dq_width                = */	INTPTR_MAX,
		/*.dq_items_tail           = */	0,
		/*.dq_items_head           = */	0,
		/*.dq_serialnum            = */	9,
		/*.dq_finalizer_ctxt       = */	0,
		/*.dq_specific_q           = */	NULL,
		/*.dq_specific_list        = */	NULL,
		/*.dq_manually_drained     = */	0,
		/*.dq_is_manually_draining = */	false,
		/*.dq_label                = */	"com.apple.root.high-overcommit-priority",
	},
};

#if DISPATCH_PERF_MON
static OSSpinLock _dispatch_stats_lock;
static uintptr_t _dispatch_bad_ratio;
static struct {
	uint64_t time_total;
	uint64_t count_total;
	uint64_t thread_total;
} _dispatch_stats[65]; // ffs*/fls*() returns zero when no bits are set
static void _dispatch_queue_merge_stats(uint64_t start);
#endif

static void *_dispatch_worker_thread(void *context);
static void _dispatch_worker_thread2(void *context);

malloc_zone_t *_dispatch_ccache_zone;

static DISPATCH_INLINE void
_dispatch_continuation_free(dispatch_continuation_t dc)
{
	dispatch_continuation_t prev_dc = _dispatch_thread_getspecific(dispatch_cache_key);
	dc->do_next = prev_dc;
	_dispatch_thread_setspecific(dispatch_cache_key, dc);
}

static DISPATCH_INLINE void
_dispatch_continuation_pop(dispatch_object_t dou)
{
	dispatch_continuation_t dc = dou._dc;
	dispatch_group_t dg;

	if (DISPATCH_OBJ_IS_VTABLE(dou._do)) {
		_dispatch_queue_invoke(dou._dq);
		return;
	}

	// Add the item back to the cache before calling the function. This
	// allows the 'hot' continuation to be used for a quick callback.
	//
	// The ccache version is per-thread.
	// Therefore, the object has not been reused yet.
	// This generates better assembly.
	if ((uintptr_t)dou._do->do_vtable & DISPATCH_OBJ_ASYNC_BIT) {
		_dispatch_continuation_free(dc);
	}
	if ((uintptr_t)dou._do->do_vtable & DISPATCH_OBJ_GROUP_BIT) {
		dg = dc->dc_group;
	} else {
		dg = NULL;
	}
	dc->dc_func(dc->dc_ctxt);
	if (dg) {
		dispatch_group_leave(dg);
		_dispatch_release(as_do(dg));
	}
}

struct dispatch_object_s *
_dispatch_queue_concurrent_drain_one(dispatch_queue_t dq)
{
	struct dispatch_object_s *head, *next, *const mediator = (void *)(uintptr_t)~0ul;

	// The mediator value acts both as a "lock" and a signal
	head = dispatch_atomic_xchg_pointer(&dq->dq_items_head, mediator);

	if (slowpath(head == NULL)) {
		// The first xchg on the tail will tell the enqueueing thread that it
		// is safe to blindly write out to the head pointer. A cmpxchg honors
		// the algorithm.
#ifdef __GNUC__
		(void)
#endif
		dispatch_atomic_cmpxchg_pointer(&dq->dq_items_head, mediator, NULL);
		_dispatch_debug("no work on global work queue");
		return NULL;
	}

	if (slowpath(head == mediator)) {
		// This thread lost the race for ownership of the queue.
		//
		// The ratio of work to libdispatch overhead must be bad. This
		// scenario implies that there are too many threads in the pool.
		// Create a new pending thread and then exit this thread.
		// The kernel will grant a new thread when the load subsides.
		_dispatch_debug("Contention on queue: %p", dq);
		_dispatch_queue_wakeup_global(dq);
#if DISPATCH_PERF_MON
		dispatch_atomic_inc((intptr_t*)&_dispatch_bad_ratio);
#endif
		return NULL;
	}

	// Restore the head pointer to a sane value before returning.
	// If 'next' is NULL, then this item _might_ be the last item.
	next = fastpath(head->do_next);

	if (slowpath(!next)) {
		dq->dq_items_head = NULL;
		
		if (dispatch_atomic_cmpxchg_pointer(&dq->dq_items_tail, head, NULL)) {
			// both head and tail are NULL now
			goto out;
		}

		// There must be a next item now. This thread won't wait long.
		while (!(next = head->do_next)) {
			_dispatch_hardware_pause();
		}
	}

	dq->dq_items_head = next;
	_dispatch_queue_wakeup_global(dq);
out:
	return head;
}

dispatch_queue_t
dispatch_get_current_queue(void)
{
	dispatch_queue_t q = _dispatch_queue_get_current();
	return q ? q : _dispatch_get_root_queue(0, true);
}

struct _dispatch_hw_config_s _dispatch_hw_config;

static void
_dispatch_queue_set_width_init(void)
{
#ifdef __APPLE__
	size_t valsz = sizeof(uint32_t);
	int ret;

	ret = sysctlbyname("hw.activecpu", &_dispatch_hw_config.cc_max_active,
	    &valsz, NULL, 0);
	(void)dispatch_assume_zero(ret);
	(void)dispatch_assume(valsz == sizeof(uint32_t));

	ret = sysctlbyname("hw.logicalcpu_max",
	    &_dispatch_hw_config.cc_max_logical, &valsz, NULL, 0);
	(void)dispatch_assume_zero(ret);
	(void)dispatch_assume(valsz == sizeof(uint32_t));

	ret = sysctlbyname("hw.physicalcpu_max",
	    &_dispatch_hw_config.cc_max_physical, &valsz, NULL, 0);
	(void)dispatch_assume_zero(ret);
	(void)dispatch_assume(valsz == sizeof(uint32_t));
#elif defined(__FreeBSD__)
	size_t valsz = sizeof(uint32_t);
	int ret;

	ret = sysctlbyname("kern.smp.cpus", &_dispatch_hw_config.cc_max_active,
	    &valsz, NULL, 0);
	(void)dispatch_assume_zero(ret);
	(void)dispatch_assume(valsz == sizeof(uint32_t));

	_dispatch_hw_config.cc_max_logical =
	    _dispatch_hw_config.cc_max_physical =
	    _dispatch_hw_config.cc_max_active;
#elif HAVE_SYSCONF && defined(_SC_NPROCESSORS_ONLN)
	int ret;

	ret = sysconf(_SC_NPROCESSORS_ONLN);
	_dispatch_hw_config.cc_max_logical =
	    _dispatch_hw_config.cc_max_physical =
	    _dispatch_hw_config.cc_max_active = (ret < 0) ? 1 : ret;
#elif defined( TARGET_OS_WIN32 ) && !defined( WINOBJC )
	typedef DWORD(__stdcall *GetProcessorCountFn)(WORD);
	typedef VOID(__stdcall *GetCurrentProcessorNumberExFn)(PROCESSOR_NUMBER*);
	GetProcessorCountFn getMaximumProcessorCount = (GetProcessorCountFn)GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "GetMaximumProcessorCount");
	GetProcessorCountFn getActiveProcessorCount = (GetProcessorCountFn)GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "GetActiveProcessorCount");
	GetCurrentProcessorNumberExFn getCurrentProcessorNumberEx = (GetCurrentProcessorNumberExFn)GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "GetCurrentProcessorNumberEx");
	if(getMaximumProcessorCount && getActiveProcessorCount && getCurrentProcessorNumberEx) {
		PROCESSOR_NUMBER pn = {0};
		getCurrentProcessorNumberEx(&pn);
		_dispatch_hw_config.cc_max_logical = (uint32_t)getMaximumProcessorCount(pn.Group);
		_dispatch_hw_config.cc_max_physical = (uint32_t)getMaximumProcessorCount(pn.Group);
		_dispatch_hw_config.cc_max_active = (uint32_t)getActiveProcessorCount(pn.Group);
	} else {
		SYSTEM_INFO si = {0};
		GetSystemInfo(&si);
		_dispatch_hw_config.cc_max_logical = si.dwNumberOfProcessors;
		_dispatch_hw_config.cc_max_physical = si.dwNumberOfProcessors;
		_dispatch_hw_config.cc_max_active = si.dwNumberOfProcessors;
	}
#else
#warning "_dispatch_queue_set_width_init: no supported way to query CPU count"
	_dispatch_hw_config.cc_max_logical =
	    _dispatch_hw_config.cc_max_physical =
	    _dispatch_hw_config.cc_max_active = 1;
#endif
}

void
dispatch_queue_set_width(dispatch_queue_t dq, long width)
{
	int w = (int)width;	// intentional truncation
	uint32_t tmp;

	if (slowpath(dq->do_ref_cnt == DISPATCH_OBJECT_GLOBAL_REFCNT)) {
		return;
	}
	if (w == 1 || w == 0) {
		dq->dq_width = 1;
		return;
	}
	if (w > 0) {
		tmp = w;
	} else switch (w) {
	case DISPATCH_QUEUE_WIDTH_MAX_PHYSICAL_CPUS:
		tmp = _dispatch_hw_config.cc_max_physical;
		break;
	case DISPATCH_QUEUE_WIDTH_ACTIVE_CPUS:
		tmp = _dispatch_hw_config.cc_max_active;
		break;
	default:
		// fall through
	case DISPATCH_QUEUE_WIDTH_MAX_LOGICAL_CPUS:
		tmp = _dispatch_hw_config.cc_max_logical;
		break;
	}
	// multiply by two since the running count is inc/dec by two (the low bit == barrier)
	dq->dq_width = tmp * 2;

	// XXX if the queue has items and the width is increased, we should try to wake the queue
}

// skip zero
// 1 - main_q
// 2 - mgr_q
// 3 - _unused_
// 4,5,6,7,8,9 - global queues
// we use 'xadd' on Intel, so the initial value == next assigned
static intptr_t _dispatch_queue_serial_numbers = 10;

// Note to later developers: ensure that any initialization changes are
// made for statically allocated queues (i.e. _dispatch_main_q).
DISPATCH_INLINE void
_dispatch_queue_init(dispatch_queue_t dq)
{
	dq->do_vtable = &_dispatch_queue_vtable;
	dq->do_next = DISPATCH_OBJECT_LISTLESS;
	dq->do_ref_cnt = 1;
	dq->do_xref_cnt = 1;
	dq->do_targetq = _dispatch_get_root_queue(0, true);
	dq->dq_running = 0;
	dq->dq_width = 1;
	dq->dq_serialnum = dispatch_atomic_inc(&_dispatch_queue_serial_numbers) - 1;
	dq->dq_specific_q = NULL;
	dq->dq_specific_list = NULL,
	dq->dq_manually_drained = 0;
	dq->dq_is_manually_draining = false;
}

dispatch_queue_t
dispatch_queue_create(const char *label, dispatch_queue_attr_t attr)
{
	dispatch_queue_t dq;
	size_t label_len;

	if (!label) {
		label = "";
	}

	label_len = strlen(label);
	if (label_len < (DISPATCH_QUEUE_MIN_LABEL_SIZE - 1)) {
		label_len = (DISPATCH_QUEUE_MIN_LABEL_SIZE - 1);
	}

	// XXX switch to malloc()
	dq = calloc(1ul, sizeof(struct dispatch_queue_s) - DISPATCH_QUEUE_MIN_LABEL_SIZE + label_len + 1);
	if (slowpath(!dq)) {
		return dq;
	}

	_dispatch_queue_init(dq);
	strcpy(dq->dq_label, label);

#ifndef DISPATCH_NO_LEGACY
	if (slowpath(attr)) {
		dq->do_targetq = _dispatch_get_root_queue(attr->qa_priority, attr->qa_flags & DISPATCH_QUEUE_OVERCOMMIT);
		dq->dq_finalizer_ctxt = attr->finalizer_ctxt;
		dq->dq_finalizer_func = attr->finalizer_func;
#ifdef __BLOCKS__
		if (attr->finalizer_func == (void*)_dispatch_call_block_and_release2) {
			// if finalizer_ctxt is a Block, retain it.
			dq->dq_finalizer_ctxt = Block_copy(dq->dq_finalizer_ctxt);
			if (!(dq->dq_finalizer_ctxt)) {
				goto out_bad;
			}
		}
#endif
	}
#else
	(void)attr;
#endif

	return dq;

#if !defined(DISPATCH_NO_LEGACY) && defined(__BLOCKS__)
out_bad:
	free(dq);
	return NULL;
#endif
}

void _dispatch_queue_specific_list_release(dispatch_queue_specific_list_t dqsl) {
	dispatch_queue_specific_t lastvar = NULL;
	dispatch_queue_specific_t var;

	TAILQ_FOREACH(var, &dqsl->context_list, specific) {
		if (lastvar) {
			free(lastvar);
		}
		if (var->destructor) {
			var->destructor(var->context);
		}
		lastvar = var;
	}
	if (lastvar) {
		free(lastvar);
	}

	free(dqsl);
}

// 6618342 Contact the team that owns the Instrument DTrace probe before renaming this symbol
void
_dispatch_queue_dispose(dispatch_queue_t dq)
{
	if (slowpath(dq == _dispatch_queue_get_current())) {
		DISPATCH_CRASH("Release of a queue by itself");
	}
	if (slowpath(dq->dq_items_tail)) {
		DISPATCH_CRASH("Release of a queue while items are enqueued");
	}

#ifndef DISPATCH_NO_LEGACY
	if (dq->dq_finalizer_func) {
		dq->dq_finalizer_func(dq->dq_finalizer_ctxt, dq);
	}
#endif

	if (slowpath(dq->dq_specific_q)) {
		dispatch_release(dq->dq_specific_q);
	}
	if (slowpath(dq->dq_specific_list)) {
		_dispatch_queue_specific_list_release(dq->dq_specific_list);
	}

	// trash the tail queue so that use after free will crash
	dq->dq_items_tail = (void *)(uintptr_t)0x200;

	_dispatch_dispose(as_do(dq));
}

DISPATCH_NOINLINE 
void
_dispatch_queue_push_list_slow(dispatch_queue_t dq, struct dispatch_object_s *obj)
{
	// The queue must be retained before dq_items_head is written in order
	// to ensure that the reference is still valid when _dispatch_wakeup is
	// called. Otherwise, if preempted between the assignment to
	// dq_items_head and _dispatch_wakeup, the blocks submitted to the
	// queue may release the last reference to the queue when invoked by
	// _dispatch_queue_drain. <rdar://problem/6932776>
	_dispatch_retain(as_do(dq));
	dq->dq_items_head = obj;
	_dispatch_wakeup(as_do(dq));
	_dispatch_release(as_do(dq));
}

DISPATCH_NOINLINE
static void
_dispatch_barrier_async_f_slow(dispatch_queue_t dq, void *context, dispatch_function_t func)
{
	dispatch_continuation_t dc = fastpath(_dispatch_continuation_alloc_from_heap());

	dc->do_vtable = (void *)(uintptr_t)(DISPATCH_OBJ_ASYNC_BIT | DISPATCH_OBJ_BARRIER_BIT);
	dc->dc_func = func;
	dc->dc_ctxt = context;

	_dispatch_queue_push(dq, as_do(dc));
}

#ifdef __BLOCKS__
void
dispatch_barrier_async(dispatch_queue_t dq, void (^work)(void))
{
	dispatch_barrier_async_f(dq, _dispatch_Block_copy(work), _dispatch_call_block_and_release);
}
#endif

DISPATCH_NOINLINE
void
dispatch_barrier_async_f(dispatch_queue_t dq, void *context, dispatch_function_t func)
{
	dispatch_continuation_t dc = fastpath(_dispatch_continuation_alloc_cacheonly());

	if (!dc) {
		_dispatch_barrier_async_f_slow(dq, context, func);
		return;
	}

	dc->do_vtable = (void *)(uintptr_t)(DISPATCH_OBJ_ASYNC_BIT | DISPATCH_OBJ_BARRIER_BIT);
	dc->dc_func = func;
	dc->dc_ctxt = context;

	_dispatch_queue_push(dq, as_do(dc));
}

DISPATCH_NOINLINE
static void
_dispatch_async_f_slow(dispatch_queue_t dq, void *context, dispatch_function_t func)
{
	dispatch_continuation_t dc = fastpath(_dispatch_continuation_alloc_from_heap());

	dc->do_vtable = (void *)(uintptr_t)DISPATCH_OBJ_ASYNC_BIT;
	dc->dc_func = func;
	dc->dc_ctxt = context;

	_dispatch_queue_push(dq, as_do(dc));
}

#ifdef __BLOCKS__
void
dispatch_async(dispatch_queue_t dq, void (^work)(void))
{
	dispatch_async_f(dq, _dispatch_Block_copy(work), _dispatch_call_block_and_release);
}
#endif

DISPATCH_NOINLINE
void
dispatch_async_f(dispatch_queue_t dq, void *ctxt, dispatch_function_t func)
{
	dispatch_continuation_t dc = fastpath(_dispatch_continuation_alloc_cacheonly());

	// unlike dispatch_sync_f(), we do NOT need to check the queue width,
	// the "drain" function will do this test

	if (!dc) {
		_dispatch_async_f_slow(dq, ctxt, func);
		return;
	}

	dc->do_vtable = (void *)(uintptr_t)DISPATCH_OBJ_ASYNC_BIT;
	dc->dc_func = func;
	dc->dc_ctxt = ctxt;

	_dispatch_queue_push(dq, as_do(dc));
}

struct dispatch_barrier_sync_slow2_s {
	dispatch_queue_t dbss2_dq;
	dispatch_function_t dbss2_func;
	dispatch_function_t dbss2_ctxt;
	dispatch_semaphore_t dbss2_sema;
};

static void
_dispatch_barrier_sync_f_slow_invoke(void *ctxt)
{
	struct dispatch_barrier_sync_slow2_s *dbss2 = ctxt;

	dispatch_assert(dbss2->dbss2_dq == dispatch_get_current_queue());
	// ALL blocks on thread-affinitized queues drain in those threads
	if (dbss2->dbss2_dq->dq_manually_drained) {
		dbss2->dbss2_func(dbss2->dbss2_ctxt);
	} else {
		dispatch_suspend(as_do(dbss2->dbss2_dq));
	}
	dispatch_semaphore_signal(dbss2->dbss2_sema);
}

DISPATCH_NOINLINE
static void
_dispatch_barrier_sync_f_slow(dispatch_queue_t dq, void *ctxt, dispatch_function_t func)
{
	
	// It's preferred to execute synchronous blocks on the current thread
	// due to thread-local side effects, garbage collection, etc. However,
	// blocks submitted to the main thread MUST be run on the main thread
	
	struct dispatch_barrier_sync_slow2_s dbss2 = {
		/*.dbss2_dq   = */	dq,
		/*.dbss2_func = */	func,
		/*.dbss2_ctxt = */	ctxt,
		/*.dbss2_sema = */	_dispatch_get_thread_semaphore(),
	};
	struct dispatch_barrier_sync_slow_s {
		DISPATCH_CONTINUATION_HEADER(dispatch_barrier_sync_slow_s);
	} dbss = {
		/*.do_vtable = */	(void *)(uintptr_t)DISPATCH_OBJ_BARRIER_BIT,
		/*.do_next   = */	0,
		/*.dc_func   = */	_dispatch_barrier_sync_f_slow_invoke,
		/*.dc_ctxt   = */	&dbss2,
	};
	
	dispatch_queue_t old_dq = _dispatch_thread_getspecific(dispatch_queue_key);
	_dispatch_queue_push(dq, as_do((void *)&dbss));
	dispatch_semaphore_wait(dbss2.dbss2_sema, DISPATCH_TIME_FOREVER);

	if (!dq->dq_manually_drained) {
		_dispatch_thread_setspecific(dispatch_queue_key, dq);
		func(ctxt);
		_dispatch_workitem_inc();
		_dispatch_thread_setspecific(dispatch_queue_key, old_dq);
		dispatch_resume(as_do(dq));
	}
	_dispatch_put_thread_semaphore(dbss2.dbss2_sema);
}

#ifdef __BLOCKS__
void
dispatch_barrier_sync(dispatch_queue_t dq, void (^work)(void))
{
	// Blocks submitted to the main queue MUST be run on the main thread,
	// therefore we must Block_copy in order to notify the thread-local
	// garbage collector that the objects are transferring to the main thread
	if (dq->dq_manually_drained) {
		dispatch_block_t block = Block_copy(work);
		return dispatch_barrier_sync_f(dq, block, _dispatch_call_block_and_release);
	}	
	struct Block_basic *bb = (void *)work;

	dispatch_barrier_sync_f(dq, work, (dispatch_function_t)bb->Block_invoke);
}
#endif

DISPATCH_NOINLINE
void
dispatch_barrier_sync_f(dispatch_queue_t dq, void *ctxt, dispatch_function_t func)
{
	dispatch_queue_t old_dq = _dispatch_thread_getspecific(dispatch_queue_key);

	// 1) ensure that this thread hasn't enqueued anything ahead of this call
	// 2) the queue is not suspended
	// 3) the queue is not weird
	if (slowpath(dq->dq_items_tail)
			|| slowpath(DISPATCH_OBJECT_SUSPENDED(dq))
			|| slowpath(!_dispatch_queue_trylock(dq))) {
		_dispatch_barrier_sync_f_slow(dq, ctxt, func);
		return;
	}

	_dispatch_thread_setspecific(dispatch_queue_key, dq);
	func(ctxt);
	_dispatch_workitem_inc();
	_dispatch_thread_setspecific(dispatch_queue_key, old_dq);
	_dispatch_queue_unlock(dq);
}

static void
_dispatch_sync_f_slow2(void *ctxt)
{
	dispatch_queue_t dq = _dispatch_queue_get_current();
	dispatch_atomic_add(&dq->dq_running, 2);
	dispatch_semaphore_signal(ctxt);
}

DISPATCH_NOINLINE
static void
_dispatch_sync_f_slow(dispatch_queue_t dq)
{
	// the global root queues do not need strict ordering
	if (dq->do_targetq == NULL) {
		dispatch_atomic_add(&dq->dq_running, 2);
		return;
	}
	else
	{
		struct dispatch_sync_slow_s {
			DISPATCH_CONTINUATION_HEADER(dispatch_sync_slow_s);
		} dss = {
			/*.do_vtable = */	NULL,
			/*.do_next   = */	0,
			/*.dc_func   = */	_dispatch_sync_f_slow2,
			/*.dc_ctxt   = */	_dispatch_get_thread_semaphore(),
		};

		// XXX FIXME -- concurrent queues can be come serial again
		_dispatch_queue_push(dq, as_do((void *)&dss));

		dispatch_semaphore_wait((dispatch_semaphore_t)dss.dc_ctxt, DISPATCH_TIME_FOREVER);
		_dispatch_put_thread_semaphore((dispatch_semaphore_t)dss.dc_ctxt);
	}
}

#ifdef __BLOCKS__
void
dispatch_sync(dispatch_queue_t dq, void (^work)(void))
{
	struct Block_basic *bb = (void *)work;
	dispatch_sync_f(dq, work, (dispatch_function_t)bb->Block_invoke);
}
#endif

DISPATCH_NOINLINE
void
dispatch_sync_f(dispatch_queue_t dq, void *ctxt, dispatch_function_t func)
{
	uintptr_t prev_cnt;
	dispatch_queue_t old_dq;

	if (dq->dq_width == 1) {
		dispatch_barrier_sync_f(dq, ctxt, func);
		return;
	}

	// 1) ensure that this thread hasn't enqueued anything ahead of this call
	// 2) the queue is not suspended
	if (slowpath(dq->dq_items_tail) || slowpath(DISPATCH_OBJECT_SUSPENDED(dq))) {
		_dispatch_sync_f_slow(dq);
	} else {
		prev_cnt = dispatch_atomic_add(&dq->dq_running, 2) - 2;

		if (slowpath(prev_cnt & 1)) {
			if (dispatch_atomic_sub(&dq->dq_running, 2) == 0) {
				_dispatch_wakeup(as_do(dq));
			}
			_dispatch_sync_f_slow(dq);
		}
	}

	old_dq = _dispatch_thread_getspecific(dispatch_queue_key);
	_dispatch_thread_setspecific(dispatch_queue_key, dq);
	func(ctxt);
	_dispatch_workitem_inc();
	_dispatch_thread_setspecific(dispatch_queue_key, old_dq);

	if (slowpath(dispatch_atomic_sub(&dq->dq_running, 2) == 0)) {
		_dispatch_wakeup(as_do(dq));
	}
}

const char *
dispatch_queue_get_label(dispatch_queue_t dq)
{
	return dq->dq_label;
}

DISPATCH_NOINLINE
static void
_dispatch_queue_cleanup2(dispatch_queue_t q)
{
	dispatch_atomic_dec(&q->dq_running);

	if (dispatch_atomic_sub(&(q->do_suspend_cnt), DISPATCH_OBJECT_SUSPEND_LOCK) == 0) {
		_dispatch_wakeup(as_do(q));
	}

	_dispatch_queue_cleanup_manual(q);
}

#ifndef DISPATCH_NO_LEGACY
dispatch_queue_t
dispatch_get_concurrent_queue(long pri)
{
	if (pri > 0) {
		pri = DISPATCH_QUEUE_PRIORITY_HIGH;
	} else if (pri < 0) {
		pri = DISPATCH_QUEUE_PRIORITY_LOW;
	}
	return _dispatch_get_root_queue(pri, false);
}
#endif

static void
_dispatch_queue_cleanup(void *ctxt)
{
	if(((dispatch_queue_t)ctxt)->dq_manually_drained) {
		_dispatch_queue_cleanup2(ctxt);
		return;
	}
    dispatch_queue_t queue = (dispatch_queue_t)ctxt;
	// POSIX defines that destructors are only called if 'ctxt' is non-null
	DISPATCH_CRASH("Premature thread exit while a dispatch queue is running");
}

static void
_dispatch_queue_cleanup_and_release(void* ctxt)
{
	_dispatch_queue_cleanup(ctxt);
	dispatch_release(as_do((dispatch_queue_t)ctxt));
}

dispatch_queue_t
dispatch_get_global_queue(long priority, unsigned long flags)
{
	if (flags & ~DISPATCH_QUEUE_OVERCOMMIT) {
		return NULL;
	}
	return _dispatch_get_root_queue(priority, flags & DISPATCH_QUEUE_OVERCOMMIT);
}

#define countof(x)	(sizeof(x) / sizeof(x[0]))
void
libdispatch_init(void)
{
	dispatch_assert(DISPATCH_QUEUE_PRIORITY_COUNT == 3);
	dispatch_assert(DISPATCH_ROOT_QUEUE_COUNT == 6);

	dispatch_assert(DISPATCH_QUEUE_PRIORITY_LOW == -DISPATCH_QUEUE_PRIORITY_HIGH);
	dispatch_assert(countof(_dispatch_root_queues) == DISPATCH_ROOT_QUEUE_COUNT);
	dispatch_assert(countof(_dispatch_thread_mediator) == DISPATCH_ROOT_QUEUE_COUNT);
	dispatch_assert(countof(_dispatch_root_queue_contexts) == DISPATCH_ROOT_QUEUE_COUNT);

#if HAVE_PTHREAD_KEY_INIT_NP
	_dispatch_thread_key_init_np(dispatch_queue_key, _dispatch_queue_cleanup);
	_dispatch_thread_key_init_np(dispatch_sema4_key, (void (*)(void *))dispatch_release);	// use the extern release
	_dispatch_thread_key_init_np(dispatch_cache_key, _dispatch_cache_cleanup2);
#if DISPATCH_PERF_MON
	_dispatch_thread_key_init_np(dispatch_bcounter_key, NULL);
#endif
#else /* !HAVE_PTHREAD_KEY_INIT_NP */
	_dispatch_thread_key_create(&dispatch_queue_key, _dispatch_queue_cleanup);
	_dispatch_thread_key_create(&dispatch_sema4_key, (void (*)(void *))dispatch_release); // use the extern release
	_dispatch_thread_key_create(&dispatch_cache_key, _dispatch_cache_cleanup2);
	_dispatch_thread_key_create(&dispatch_threaded_queue_key, _dispatch_queue_cleanup_and_release);
#ifdef DISPATCH_PERF_MON
	_dispatch_thread_key_create(&dispatch_bcounter_key, NULL);
#endif
#endif /* HAVE_PTHREAD_KEY_INIT_NP */

	_dispatch_main_q.dq_manually_drained = pthread_self();
	_dispatch_thread_setspecific(dispatch_queue_key, &_dispatch_main_q);

	_dispatch_queue_set_width_init();
}

#if TARGET_OS_WIN32

void NTAPI call_libdispatch_init(void* dll, DWORD reason, void* reserved)
{
	UNREFERENCED_PARAMETER(dll);
	UNREFERENCED_PARAMETER(reserved);

	switch(reason)
	{
	case DLL_PROCESS_ATTACH:
		libdispatch_init();
		break;
	}
}

#if defined(_LIB)

#ifdef _M_IX86
#pragma comment (linker, "/INCLUDE:__tls_used")
#pragma comment (linker, "/INCLUDE:_dispatch_tls_callback")
#else
#pragma comment (linker, "/INCLUDE:_tls_used")
#pragma comment (linker, "/INCLUDE:dispatch_tls_callback")
#endif

#ifdef _M_X64
#pragma const_seg(".CRT$XLG")
EXTERN_C const
#elif defined( WINOBJC ) && !defined( _M_IX86 )
#pragma const_seg(".CRT$XLG")
EXTERN_C const
#else
#pragma data_seg(".CRT$XLG")
EXTERN_C
#endif

PIMAGE_TLS_CALLBACK dispatch_tls_callback = call_libdispatch_init;

#ifdef _M_X64
#pragma const_seg()
#elif defined( WINOBJC ) && !defined( _M_IX86 )
#pragma const_seg()
#else
#pragma data_seg()
#endif

#elif defined(_WINDLL)

// put dllmain here

#endif

#endif

dispatch_queue_t
dispatch_get_current_thread_queue(void)
{
	dispatch_queue_t q = _dispatch_thread_getspecific(dispatch_threaded_queue_key);
	if(q == NULL) {
		char thread_label[DISPATCH_QUEUE_MIN_LABEL_SIZE] = {0};
		snprintf(thread_label, DISPATCH_QUEUE_MIN_LABEL_SIZE, "thread-q-%x", pthread_self());
		q = dispatch_queue_create(thread_label, 0);
		q->do_suspend_cnt = DISPATCH_OBJECT_SUSPEND_LOCK;
		q->dq_running = 1;
		q->dq_manually_drained = pthread_self();

		_dispatch_thread_setspecific(dispatch_threaded_queue_key, q);
	}
	dispatch_retain(as_do(q));
	return q;
}

void
_dispatch_queue_unlock(dispatch_queue_t dq)
{
	if (slowpath(dispatch_atomic_dec(&dq->dq_running))) {
		return;
	}

	_dispatch_wakeup(as_do(dq));
}

#if TARGET_OS_WIN32
static void _dispatch_noop(void* unused DISPATCH_UNUSED)
{
	UNREFERENCED_PARAMETER(unused);
}
#endif

// 6618342 Contact the team that owns the Instrument DTrace probe before renaming this symbol
dispatch_queue_t
_dispatch_wakeup(dispatch_object_t dou)
{
	dispatch_queue_t tq;
#if TARGET_OS_WIN32
	bool needs_sync = ((dx_type(dou._do) & _DISPATCH_SOURCE_TYPE) != 0) && !dou._ds->ds_is_installed;
#endif

	if (slowpath(DISPATCH_OBJECT_SUSPENDED(dou._do))) {
		return NULL;
	}
	if (!dx_probe(dou._do) && !dou._dq->dq_items_tail) {
		return NULL;
	}

	if (!_dispatch_trylock(dou._do)) {
		if(dou._dq->dq_manually_drained) {
			_dispatch_queue_wakeup_manual(dou._dq);
		}
		return NULL;
	}
	_dispatch_retain(as_do(dou._do));
	tq = dou._do->do_targetq;
	_dispatch_queue_push(tq, as_do(dou._do));

#if TARGET_OS_WIN32
	// There is a race; I have to ensure that dispatch_sources are wired up to the IOCP
	// immediately, or else ReadFile (etc.) could be called before there's anything set
	// up to respond to the completion notification:
	// main thread                                                       dispatch_mgr thread
	// HANDLE h = ...;                                                   <sleep>
	// s = dispatch_create_source(..., h, ...);                          <sleep>
	// dispatch_resume(s);                      |-_dispatch_mgr_wakeup-> <sleep>
	// ReadFile(h, ...);                                                 <waiting for CPU>
	// <read completes>                                                  <waiting for CPU>
	// <read tries to notify attached IOCP>                              <waiting for CPU>
	// <no IOCP attached>                                                <waiting for CPU>
	//                                                                   process message
	//                                                                   CreateIoCompletionPort(..., h, ...)
	//                                                                   <never going to receive the missed notification>
	// I am not actually 100% sure this fixes the race: I might have to do something more aggressive like registering
	// directly from this thread. The primary reason for uncertainty is that I think things end up getting queued
	// to parallel queues, and there's no way to reliably drain a parallel queue.
	if(needs_sync) {
		// first, ensure that the initial setup messages get pushed from the dispatch source to the manager queue
		dispatch_sync_f(dou._dq, NULL, &_dispatch_noop);
		// then ensure that the manager queue gets run
		dispatch_sync_f(&_dispatch_mgr_q, NULL, &_dispatch_noop);
	}
#endif
	return tq;	// libdispatch doesn't need this, but the Instrument DTrace probe does
}

#if HAVE_PTHREAD_WORKQUEUES
static DISPATCH_INLINE int
_dispatch_rootq2wq_pri(long idx)
{
#ifdef WORKQ_DEFAULT_PRIOQUEUE
	switch (idx) {
	case 0:
	case 1:
		return WORKQ_LOW_PRIOQUEUE;
	case 2:
	case 3:
	default:
		return WORKQ_DEFAULT_PRIOQUEUE;
	case 4:
	case 5:
		return WORKQ_HIGH_PRIOQUEUE;
	}
#else
	return pri;
#endif
}
#endif

static void
_dispatch_root_queues_init(void *context DISPATCH_UNUSED)
{
#if HAVE_PTHREAD_WORKQUEUES
 #ifndef WINOBJC
	bool disable_wq = getenv("LIBDISPATCH_DISABLE_KWQ") != NULL;
 #else
	bool disable_wq = false;
 #endif
	pthread_workqueue_attr_t pwq_attr;
	int r;
#endif
#if USE_MACH_SEM
	kern_return_t kr;
#endif
#if USE_POSIX_SEM
	int ret;
#endif
	int i;

#if HAVE_PTHREAD_WORKQUEUES
	r = pthread_workqueue_attr_init_np(&pwq_attr);
#if defined(__GNUC__)
	(void)
#endif
	dispatch_assume_zero(r);
#endif

	for (i = 0; i < DISPATCH_ROOT_QUEUE_COUNT; i++) {
// some software hangs if the non-overcommitting queues do not overcommit when threads block
#if 0
		if (!(i & 1)) {
			dispatch_root_queue_contexts[i].dgq_thread_pool_size = _dispatch_hw_config.cc_max_active;
		}
#endif
#if HAVE_PTHREAD_WORKQUEUES
		r = pthread_workqueue_attr_setqueuepriority_np(&pwq_attr, _dispatch_rootq2wq_pri(i));
#if defined(__GNUC__)
		(void)
#endif
		dispatch_assume_zero(r);
#if !TARGET_OS_WIN32
		r = pthread_workqueue_attr_setovercommit_np(&pwq_attr, i & 1);
#if defined(__GNUC__)
		(void)
#endif
		dispatch_assume_zero(r);
#endif
		r = 0;
		if (disable_wq || (r = pthread_workqueue_create_np(&_dispatch_root_queue_contexts[i].dgq_kworkqueue, &pwq_attr))) {
			if (r != ENOTSUP) {
#if defined(__GNUC__)
				(void)
#endif
				dispatch_assume_zero(r);
			}
#endif /* HAVE_PTHREAD_WORKQUEUES */
#if USE_MACH_SEM
			// override the default FIFO behavior for the pool semaphores
			kr = semaphore_create(mach_task_self(), &_dispatch_thread_mediator[i].dsema_port, SYNC_POLICY_LIFO, 0);
			DISPATCH_VERIFY_MIG(kr);
			(void)dispatch_assume_zero(kr);
			(void)dispatch_assume(_dispatch_thread_mediator[i].dsema_port);
#endif
#if USE_POSIX_SEM
			/* XXXRW: POSIX semaphores don't support LIFO? */
			ret = sem_init(&_dispatch_thread_mediator[i].dsema_sem, 0, 0);
			(void)dispatch_assume_zero(ret);
#endif
#if USE_WIN32_SEM
			_dispatch_thread_mediator[i].dsema_handle = CreateSemaphoreExW(NULL, 0, LONG_MAX, NULL, 0, EVENT_ALL_ACCESS);
			dispatch_assume(_dispatch_thread_mediator[i].dsema_handle);
#endif
#if HAVE_PTHREAD_WORKQUEUES
		} else {
#if defined(__GNUC__)
			(void)
#endif
			dispatch_assume(_dispatch_root_queue_contexts[i].dgq_kworkqueue);
		}
#endif
	}

#if HAVE_PTHREAD_WORKQUEUES
	r = pthread_workqueue_attr_destroy_np(&pwq_attr);
#if defined(__GNUC__)
	(void)
#endif
	dispatch_assume_zero(r);
#endif
}

bool
_dispatch_queue_wakeup_global(dispatch_queue_t dq)
{
	struct dispatch_root_queue_context_s *qc = dq->do_ctxt;
#if HAVE_PTHREAD_WORKQUEUES
	pthread_workitem_handle_t wh;
#if !TARGET_OS_WIN32
	unsigned int gen_cnt;
#endif
#endif
	pthread_t pthr;
	int r;
	uintptr_t t_count;

	if (!dq->dq_items_tail) {
		return false;
	}

	_dispatch_safe_fork = false;

	dispatch_debug_queue(dq, __PRETTY_FUNCTION__);

	dispatch_once_f(&_dispatch_root_queues_pred, NULL, _dispatch_root_queues_init);

#if HAVE_PTHREAD_WORKQUEUES
	if (qc->dgq_kworkqueue) {
		if (dispatch_atomic_cmpxchg(&qc->dgq_pending, 0, 1)) {
			_dispatch_debug("requesting new worker thread");
#if TARGET_OS_WIN32
			r = pthread_workqueue_additem_np(qc->dgq_kworkqueue, _dispatch_worker_thread2, dq, &wh);
#else
			r = pthread_workqueue_additem_np(qc->dgq_kworkqueue, _dispatch_worker_thread2, dq, &wh, &gen_cnt);
#endif
#if defined(__GNUC__)
			(void)
#endif
			dispatch_assume_zero(r);
		} else {
			_dispatch_debug("work thread request still pending on global queue: %p", dq);
		}
		goto out;
	}
#endif

	if (dispatch_semaphore_signal(qc->dgq_thread_mediator)) {
		goto out;
	}

	do {
		t_count = qc->dgq_thread_pool_size;
		if (!t_count) {
			_dispatch_debug("The thread pool is full: %p", dq);
			goto out;
		}
	} while (!dispatch_atomic_cmpxchg(&qc->dgq_thread_pool_size, t_count, t_count - 1));

	while ((r = pthread_create(&pthr, NULL, _dispatch_worker_thread, dq))) {
		if (r != EAGAIN) {
#if defined(__GNUC__)
			(void)
#endif
			dispatch_assume_zero(r);
		}
		sleep(1);
	}
	r = pthread_detach(pthr);
#if defined(__GNUC__)
	(void)
#endif
	dispatch_assume_zero(r);

out:
	return false;
}

void
_dispatch_queue_serial_drain_till_empty(dispatch_queue_t dq)
{
#if DISPATCH_PERF_MON
	uint64_t start = _dispatch_absolute_time();
#endif
	_dispatch_queue_drain(dq);
#if DISPATCH_PERF_MON
	_dispatch_queue_merge_stats(start);
#endif
	_dispatch_force_cache_cleanup();
}

// 6618342 Contact the team that owns the Instrument DTrace probe before renaming this symbol
DISPATCH_NOINLINE
void
_dispatch_queue_invoke(dispatch_queue_t dq)
{
	dispatch_queue_t tq = dq->do_targetq;

	if (!slowpath(DISPATCH_OBJECT_SUSPENDED(dq)) && fastpath(_dispatch_queue_trylock(dq))) {
		_dispatch_queue_drain(dq);
		if (tq == dq->do_targetq) {
			tq = dx_invoke(dq);
		} else {
			tq = dq->do_targetq;
		}
		// We do not need to check the result.
		// When the suspend-count lock is dropped, then the check will happen.
		dispatch_atomic_dec(&dq->dq_running);
		if (tq) {
			_dispatch_queue_push(tq, as_do(dq));
			return;
		}
	}

	dq->do_next = DISPATCH_OBJECT_LISTLESS;
	if (dispatch_atomic_sub(&dq->do_suspend_cnt, DISPATCH_OBJECT_SUSPEND_LOCK) == 0) {
		if (dq->dq_running == 0) {
			_dispatch_wakeup(as_do(dq));	// verify that the queue is idle
		}
	}
	_dispatch_release(as_do(dq));	// added when the queue is put on the list
}

// 6618342 Contact the team that owns the Instrument DTrace probe before renaming this symbol
static void
_dispatch_set_target_queue2(void *ctxt)
{
	dispatch_queue_t prev_dq, dq = _dispatch_queue_get_current();
		  
	prev_dq = dq->do_targetq;
	dq->do_targetq = ctxt;
	_dispatch_release(as_do(prev_dq));
}

void
dispatch_set_target_queue(dispatch_object_t dou, dispatch_queue_t dq)
{
	if (slowpath(dou._do->do_xref_cnt == DISPATCH_OBJECT_GLOBAL_REFCNT)) {
		return;
	}
	// NOTE: we test for NULL target queues internally to detect root queues
	// therefore, if the retain crashes due to a bad input, that is OK
	_dispatch_retain(as_do(dq));
	dispatch_barrier_async_f(dou._dq, dq, _dispatch_set_target_queue2);
}

static void
_dispatch_async_f_redirect2(void *_ctxt)
{
	struct dispatch_continuation_s *dc = _ctxt;
	struct dispatch_continuation_s *other_dc = dc->dc_data[1];
	dispatch_queue_t old_dq, dq = dc->dc_data[0];

	old_dq = _dispatch_thread_getspecific(dispatch_queue_key);
	_dispatch_thread_setspecific(dispatch_queue_key, dq);
	_dispatch_continuation_pop(as_do(other_dc));
	_dispatch_thread_setspecific(dispatch_queue_key, old_dq);

	if (dispatch_atomic_sub(&dq->dq_running, 2) == 0) {
		_dispatch_wakeup(as_do(dq));
	}
	_dispatch_release(as_do(dq));
}

static void
_dispatch_async_f_redirect(dispatch_queue_t dq, struct dispatch_object_s *other_dc)
{
	dispatch_continuation_t dc = (void *)other_dc;
	dispatch_queue_t root_dq = dq;

	if (dc->dc_func == _dispatch_sync_f_slow2) {
		dc->dc_func(dc->dc_ctxt);
		return;
	}

	dispatch_atomic_add(&dq->dq_running, 2);
	_dispatch_retain(as_do(dq));

	dc = _dispatch_continuation_alloc_cacheonly();
	dc = dc ? dc : _dispatch_continuation_alloc_from_heap();

	dc->do_vtable = (void *)(uintptr_t)DISPATCH_OBJ_ASYNC_BIT;
	dc->dc_func = _dispatch_async_f_redirect2;
	dc->dc_ctxt = dc;
	dc->dc_data[0] = dq;
	dc->dc_data[1] = other_dc;

	do {
		root_dq = root_dq->do_targetq;
	} while (root_dq->do_targetq);

	_dispatch_queue_push(root_dq, as_do(dc));
}

void
_dispatch_queue_drain(dispatch_queue_t dq)
{
	dispatch_queue_t orig_tq, old_dq = _dispatch_thread_getspecific(dispatch_queue_key);
	struct dispatch_object_s *dc = NULL, *next_dc = NULL;

	orig_tq = dq->do_targetq;

	_dispatch_thread_setspecific(dispatch_queue_key, dq);

	while (dq->dq_items_tail) {
		while (!fastpath(dq->dq_items_head)) {
			_dispatch_hardware_pause();
		}

		dc = dq->dq_items_head;
		dq->dq_items_head = NULL;

		do {
			// Enqueue is TIGHTLY controlled, we won't wait long.
			do {
				next_dc = fastpath(dc->do_next);
			} while (!next_dc && !dispatch_atomic_cmpxchg_pointer(&dq->dq_items_tail, dc, NULL));
			if (DISPATCH_OBJECT_SUSPENDED(dq)) {
				goto out;
			}
			if (dq->dq_running > dq->dq_width) {
				goto out;
			}
			if (orig_tq != dq->do_targetq) {
				goto out;
			}
			if (fastpath(dq->dq_width == 1)) {
				_dispatch_continuation_pop(as_do(dc));
				_dispatch_workitem_inc();
			} else if ((uintptr_t)dc->do_vtable & DISPATCH_OBJ_BARRIER_BIT) {
				if (dq->dq_running > 1) {
					goto out;
				}
				_dispatch_continuation_pop(as_do(dc));
				_dispatch_workitem_inc();
			} else {
				_dispatch_async_f_redirect(dq, dc);
			}
		} while ((dc = next_dc));
	}

out:
	// if this is not a complete drain, we must undo some things
	if (slowpath(dc)) {
		// 'dc' must NOT be "popped"
		// 'dc' might be the last item
		if (next_dc || dispatch_atomic_cmpxchg_pointer(&dq->dq_items_tail, NULL, dc)) {
			dq->dq_items_head = dc;
		} else {
			while (!(next_dc = dq->dq_items_head)) {
				_dispatch_hardware_pause();
			}
			dq->dq_items_head = dc;
			dc->do_next = next_dc;
		}
	}

	_dispatch_thread_setspecific(dispatch_queue_key, old_dq);
}

// 6618342 Contact the team that owns the Instrument DTrace probe before renaming this symbol
void *
_dispatch_worker_thread(void *context)
{
	dispatch_queue_t dq = context;
	struct dispatch_root_queue_context_s *qc = dq->do_ctxt;

#if !TARGET_OS_WIN32
	sigset_t mask;
	int r;

	// workaround tweaks the kernel workqueue does for us
	r = sigfillset(&mask);
	(void)dispatch_assume_zero(r);
	r = _dispatch_pthread_sigmask(SIG_BLOCK, &mask, NULL);
	(void)dispatch_assume_zero(r);
#endif

	do {
		_dispatch_worker_thread2(context);
		// we use 65 seconds in case there are any timers that run once a minute
	} while (dispatch_semaphore_wait(qc->dgq_thread_mediator, dispatch_time(0, 65ull * NSEC_PER_SEC)) == 0);

	dispatch_atomic_inc(&(qc->dgq_thread_pool_size));
	if (dq->dq_items_tail) {
		_dispatch_queue_wakeup_global(dq);
	}

	return NULL;
}

// 6618342 Contact the team that owns the Instrument DTrace probe before renaming this symbol
void
_dispatch_worker_thread2(void *context)
{
	struct dispatch_object_s *item;
	dispatch_queue_t dq = context;
	struct dispatch_root_queue_context_s *qc = dq->do_ctxt;
#if DISPATCH_PERF_MON
	uint64_t start;
#endif

	if (_dispatch_thread_getspecific(dispatch_queue_key)) {
		DISPATCH_CRASH("Premature thread recycling");
	}

	_dispatch_thread_setspecific(dispatch_queue_key, dq);
	qc->dgq_pending = 0;

#if DISPATCH_COCOA_COMPAT
	// ensure that high-level memory management techniques do not leak/crash
	dispatch_begin_thread_4GC();
#endif
#if DISPATCH_COCOA_COMPAT || WINOBJC
    // we don't support GC in WinOBJC because iOS doesnt support it.
    void *pool = _dispatch_begin_NSAutoReleasePool();
#endif

#if DISPATCH_PERF_MON
	start = _dispatch_absolute_time();
#endif
	while ((item = fastpath(_dispatch_queue_concurrent_drain_one(dq)))) {
		_dispatch_continuation_pop(as_do(item));
	}
#if DISPATCH_PERF_MON
	_dispatch_queue_merge_stats(start);
#endif

#if DISPATCH_COCOA_COMPAT || WINOBJC
	_dispatch_end_NSAutoReleasePool(pool);
#endif

#if DISPATCH_COCOA_COMPAT
    dispatch_end_thread_4GC();
#endif

	_dispatch_thread_setspecific(dispatch_queue_key, NULL);

	_dispatch_force_cache_cleanup();
}

#if DISPATCH_PERF_MON
void
_dispatch_queue_merge_stats(uint64_t start)
{
	uint64_t avg, delta = _dispatch_absolute_time() - start;
	uintptr_t count, bucket;

	count = (uintptr_t)_dispatch_thread_getspecific(dispatch_bcounter_key);
	_dispatch_thread_setspecific(dispatch_bcounter_key, NULL);

	if (count) {
		avg = delta / count;
		bucket = flsll(avg);
	} else {
		bucket = 0;
	}

	// 64-bit counters on 32-bit require a lock or a queue
	OSSpinLockLock(&_dispatch_stats_lock);

	_dispatch_stats[bucket].time_total += delta;
	_dispatch_stats[bucket].count_total += count;
	_dispatch_stats[bucket].thread_total++;

	OSSpinLockUnlock(&_dispatch_stats_lock);
}
#endif

size_t
dispatch_queue_debug_attr(dispatch_queue_t dq, char* buf, size_t bufsiz)
{
	return snprintf(buf, bufsiz, "parent = %p ", dq->do_targetq);
}

size_t
dispatch_queue_debug(dispatch_queue_t dq, char* buf, size_t bufsiz)
{
	size_t offset = 0;
	offset += snprintf(&buf[offset], bufsiz - offset, "%s[%p] = { ", dq->dq_label, dq);
	offset += dispatch_object_debug_attr(as_do(dq), &buf[offset], bufsiz - offset);
	offset += dispatch_queue_debug_attr(dq, &buf[offset], bufsiz - offset);
	offset += snprintf(&buf[offset], bufsiz - offset, "}");
	return offset;
}

#if DISPATCH_DEBUG
void
dispatch_debug_queue(dispatch_queue_t dq, const char* str) {
	if (fastpath(dq)) {
		dispatch_debug(as_do(dq), "%s", str);
	} else {
		_dispatch_log("queue[NULL]: %s", str);
	}
}
#endif

#ifndef DISPATCH_NO_LEGACY
static void
dispatch_queue_attr_dispose(dispatch_queue_attr_t attr)
{
	dispatch_queue_attr_set_finalizer_f(attr, NULL, NULL);
	_dispatch_dispose(attr);
}

static const struct dispatch_queue_attr_vtable_s dispatch_queue_attr_vtable = {
	/*.do_type    = */	DISPATCH_QUEUE_ATTR_TYPE,
	/*.do_kind    = */	"queue-attr",
	/*.do_debug   = */	0,
	/*.do_invoke  = */	0,
	/*.do_probe   = */	0,
	/*.do_dispose = */ dispatch_queue_attr_dispose
};

dispatch_queue_attr_t
dispatch_queue_attr_create(void)
{
	dispatch_queue_attr_t a = calloc(1, sizeof(struct dispatch_queue_attr_s));

	if (a) {
		a->do_vtable = &dispatch_queue_attr_vtable;
		a->do_next = DISPATCH_OBJECT_LISTLESS;
		a->do_ref_cnt = 1;
		a->do_xref_cnt = 1;
		a->do_targetq = _dispatch_get_root_queue(0, 0);
		a->qa_flags = DISPATCH_QUEUE_OVERCOMMIT;
	}
	return a;
}

void
dispatch_queue_attr_set_flags(dispatch_queue_attr_t attr, uint64_t flags)
{
	dispatch_assert_zero(flags & ~DISPATCH_QUEUE_FLAGS_MASK);
	attr->qa_flags = (unsigned long)flags & DISPATCH_QUEUE_FLAGS_MASK;
}
	
void
dispatch_queue_attr_set_priority(dispatch_queue_attr_t attr, int priority)
{
	dispatch_debug_assert(attr, "NULL pointer");
	dispatch_debug_assert(priority <= DISPATCH_QUEUE_PRIORITY_HIGH && priority >= DISPATCH_QUEUE_PRIORITY_LOW, "Invalid priority");

	if (priority > 0) {
		priority = DISPATCH_QUEUE_PRIORITY_HIGH;
	} else if (priority < 0) {
		priority = DISPATCH_QUEUE_PRIORITY_LOW;
	}

	attr->qa_priority = priority;
}

void
dispatch_queue_attr_set_finalizer_f(dispatch_queue_attr_t attr,
        void *context, dispatch_queue_finalizer_function_t finalizer)
{
#ifdef __BLOCKS__
	if (attr->finalizer_func == (void*)_dispatch_call_block_and_release2) {
		Block_release(attr->finalizer_ctxt);
	}
#endif
	attr->finalizer_ctxt = context;
	attr->finalizer_func = finalizer;
}

#ifdef __BLOCKS__
long
dispatch_queue_attr_set_finalizer(dispatch_queue_attr_t attr,
        dispatch_queue_finalizer_t finalizer)
{
	void *ctxt;
	dispatch_queue_finalizer_function_t func;

	if (finalizer) {
		if (!(ctxt = Block_copy(finalizer))) {
			return 1;
		}
		func = (void *)_dispatch_call_block_and_release2;
	} else {
		ctxt = NULL;
		func = NULL;
	}

	dispatch_queue_attr_set_finalizer_f(attr, ctxt, func);

	return 0;
}
#endif
#endif /* DISPATCH_NO_LEGACY */

#if !TARGET_OS_WIN32

int
_dispatch_pthread_sigmask(int how, sigset_t *set, sigset_t *oset)
{
	int r;

	/* Workaround: 6269619 Not all signals can be delivered on any thread */

	r = sigdelset(set, SIGILL);
	dispatch_assume_zero(r);
	r = sigdelset(set, SIGTRAP);
	dispatch_assume_zero(r);
#if HAVE_DECL_SIGEMT
	r = sigdelset(set, SIGEMT);
	(void)dispatch_assume_zero(r);
#endif
	r = sigdelset(set, SIGFPE);
	dispatch_assume_zero(r);
	r = sigdelset(set, SIGBUS);
	dispatch_assume_zero(r);
	r = sigdelset(set, SIGSEGV);
	dispatch_assume_zero(r);
	r = sigdelset(set, SIGSYS);
	dispatch_assume_zero(r);
	r = sigdelset(set, SIGPIPE);
	dispatch_assume_zero(r);

	return pthread_sigmask(how, set, oset);
}

#endif

#if !TARGET_OS_WIN32

bool _dispatch_safe_fork = true;

void
dispatch_atfork_prepare(void)
{
}

void
dispatch_atfork_parent(void)
{
}

void
dispatch_atfork_child(void)
{
	void *crash = (void *)(uintptr_t)0x100;
	size_t i;

	if (_dispatch_safe_fork) {
		return;
	}

	_dispatch_main_q.dq_items_head = crash;
	_dispatch_main_q.dq_items_tail = crash;

	_dispatch_mgr_q.dq_items_head = crash;
	_dispatch_mgr_q.dq_items_tail = crash;

	for (i = 0; i < DISPATCH_ROOT_QUEUE_COUNT; i++) {
		_dispatch_root_queues[i].dq_items_head = crash;
		_dispatch_root_queues[i].dq_items_tail = crash;
	}
}

void
dispatch_init_pthread(pthread_t pthr DISPATCH_UNUSED)
{
}

const struct dispatch_queue_offsets_s dispatch_queue_offsets = {
	/*.dqo_version        = */	3,
	/*.dqo_label          = */	offsetof(struct dispatch_queue_s, dq_label),
	/*.dqo_label_size     = */	sizeof(_dispatch_main_q.dq_label),
	/*.dqo_flags          = */	0,
	/*.dqo_flags_size     = */	0,
	/*.dqo_serialnum      = */	offsetof(struct dispatch_queue_s, dq_serialnum),
	/*.dqo_serialnum_size = */	sizeof(_dispatch_main_q.dq_serialnum),
	/*.dqo_width          = */	offsetof(struct dispatch_queue_s, dq_width),
	/*.dqo_width_size     = */	sizeof(_dispatch_main_q.dq_width),
	/*.dqo_running        = */	offsetof(struct dispatch_queue_s, dq_running),
	/*.dqo_running_size   = */	sizeof(_dispatch_main_q.dq_running),
};

#endif

#ifdef __BLOCKS__
void
dispatch_after(dispatch_time_t when, dispatch_queue_t queue, dispatch_block_t work)
{
	// test before the copy of the block
	if (when == DISPATCH_TIME_FOREVER) {
#if DISPATCH_DEBUG
		DISPATCH_CLIENT_CRASH("dispatch_after() called with 'when' == infinity");
#endif
		return;
	}
	dispatch_after_f(when, queue, _dispatch_Block_copy(work), _dispatch_call_block_and_release);
}
#endif

struct _dispatch_after_time_s {
	void *datc_ctxt;
	void (*datc_func)(void *);
	dispatch_source_t ds;
};

static void
_dispatch_after_timer_cancel(void *ctxt)
{
	struct _dispatch_after_time_s *datc = ctxt;
	dispatch_source_t ds = datc->ds;

	free(datc);
	dispatch_release(as_do(ds));	// MUST NOT be _dispatch_release()
}

static void
_dispatch_after_timer_callback(void *ctxt)
{
	struct _dispatch_after_time_s *datc = ctxt;

	dispatch_assert(datc->datc_func);
	datc->datc_func(datc->datc_ctxt);

	dispatch_source_cancel(datc->ds);
}

DISPATCH_NOINLINE
void
dispatch_after_f(dispatch_time_t when, dispatch_queue_t queue, void *ctxt, void (*func)(void *))
{
	uint64_t delta;
	struct _dispatch_after_time_s *datc = NULL;
	dispatch_source_t ds = NULL;

	if (when == DISPATCH_TIME_FOREVER) {
#if DISPATCH_DEBUG
		DISPATCH_CLIENT_CRASH("dispatch_after_f() called with 'when' == infinity");
#endif
		return;
	}

	delta = _dispatch_timeout(when);
	if (delta == 0) {
		dispatch_async_f(queue, ctxt, func);
		return;
	}

	// this function should be optimized to not use a dispatch source
	ds = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, queue);
	dispatch_assert(ds);

	datc = malloc(sizeof(struct _dispatch_after_time_s));
	dispatch_assert(datc);
	datc->datc_ctxt = ctxt;
	datc->datc_func = func;
	datc->ds = ds;

	dispatch_set_context(as_do(ds), datc);
	dispatch_source_set_event_handler_f(ds, _dispatch_after_timer_callback);
	dispatch_source_set_cancel_handler_f(ds, _dispatch_after_timer_cancel);
	dispatch_source_set_timer(ds, when, 0, 0);
	dispatch_resume(as_do(ds));
}

static void _dispatch_queue_init_specific_list(dispatch_queue_t dq) {
	dispatch_queue_t newQueue = dispatch_queue_create("SpecificQueue", NULL);
	dispatch_queue_specific_list_t dqsl;
	dqsl = calloc(1, sizeof(struct dispatch_queue_specific_list_s));
	TAILQ_INIT(&dqsl->context_list);
	newQueue->dq_specific_list = dqsl;
	
	if(slowpath(!dispatch_atomic_cmpxchg_pointer(&dq->dq_specific_q, NULL, newQueue))) {
		dispatch_release(newQueue);
	}
}

static void _dispatch_queue_insert_specific(dispatch_queue_specific_t dqs) {
	dispatch_queue_t dq = _dispatch_queue_get_current();
	dispatch_queue_specific_list_t dqsl = dq->dq_specific_list;
	dispatch_queue_specific_t var;

	TAILQ_FOREACH(var, &dqsl->context_list, specific) {
		if (var->key == dqs->key) {
			if(var->destructor) {
				var->destructor(var->context);
			}

			// If a specific exists with this key, simply update the context on that specific
			if(dqs->context) {
				var->context = dqs->context;
				var->destructor = dqs->destructor;
			} else {
				TAILQ_REMOVE(&dqsl->context_list, var, specific);
				free(var);
			}
			free(dqs);
			return;
		}
	}

	if(dqs->context) {
		TAILQ_INSERT_TAIL(&dqsl->context_list, dqs, specific);
	}
}

void dispatch_queue_set_specific(dispatch_queue_t queue, const void *key, void *_Nullable context, dispatch_function_t _Nullable destructor) {
	if (slowpath(!key)) {
		return;
	}
	dispatch_queue_specific_t specific = calloc(1, sizeof(struct dispatch_queue_specific_s));
	specific->key = key;
	specific->context = context;
	specific->destructor = destructor;

	// Delayed initialization
	if (slowpath(!queue->dq_specific_q)) {
		_dispatch_queue_init_specific_list(queue);
	}

	dispatch_barrier_sync_f(queue->dq_specific_q, specific, _dispatch_queue_insert_specific);
}

static void _dispatch_queue_get_specific(void* context) {
	dispatch_queue_t dq = _dispatch_queue_get_current();
	dispatch_queue_specific_list_t dqsl = dq->dq_specific_list;
	dispatch_queue_specific_t var;

	// The parameter passed in is reference to a void* key
	void** ctxt = context;
	void* key = *ctxt;

	TAILQ_FOREACH(var, &dqsl->context_list, specific) {
		if (var->key == key) {
			*ctxt = var->context;
			return;
		}
	}
	*ctxt = NULL;
}

void* _Nullable dispatch_queue_get_specific(dispatch_queue_t queue, const void *key) {
	void* context = NULL;
	if (queue->dq_specific_q) {
		context = key;
		dispatch_sync_f(queue->dq_specific_q, &context, _dispatch_queue_get_specific);
	}
	return context;
}

void* _Nullable dispatch_get_specific(const void *key) {
	return dispatch_queue_get_specific(_dispatch_queue_get_current(), key);
}