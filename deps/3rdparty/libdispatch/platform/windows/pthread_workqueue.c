#include "pthread_workqueue.h"

#define _CRT_SECURE_NO_WARNINGS 1

#include <SDKDDKVer.h>
#include <Windows.h>

#ifdef _MSC_VER

#if defined DEBUG || defined _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_CLIENTBLOCK new(_CLIENT_BLOCK, __FILE__, __LINE__)
#define new DEBUG_CLIENTBLOCK
#endif

#endif

#include <errno.h>

#include "pthread.h"

typedef struct pthread_workqueue_attr
{
	TP_CALLBACK_ENVIRON environment;
	int qprio;
	size_t stackcommit;
	size_t stackreserve;
}* pthread_workqueue_attr_t;

typedef struct pthread_workqueue
{
	TP_POOL* pool;
	pthread_workqueue_attr_t attr;
}* pthread_workqueue_t;

typedef struct _pthread_workitem
{
	void (*function)(void*);
	void* context;
	pthread_workqueue_t q;
	pthread_timeritem_handle_t* handle;
} _pthread_workitem;

static size_t default_stack_commit = 0;
static size_t default_stack_reserve = 0;
static INIT_ONCE stacksizes_set = {0};

BOOL CALLBACK get_default_stacksizes(INIT_ONCE* init_once, void* context, void** result)
{
	typedef BOOL (*QueryThreadpoolStackInformationFn)(TP_POOL*, TP_POOL_STACK_INFORMATION*);
	QueryThreadpoolStackInformationFn queryThreadpoolStackInformation = (QueryThreadpoolStackInformationFn)GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "QueryThreadpoolStackInformation");

	UNREFERENCED_PARAMETER(init_once);
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(result);

	if(queryThreadpoolStackInformation) {
		TP_POOL* pool = CreateThreadpool(NULL);
		TP_POOL_STACK_INFORMATION psi;
		queryThreadpoolStackInformation(pool, &psi);
		default_stack_commit = psi.StackCommit;
		default_stack_reserve = psi.StackReserve;
		CloseThreadpool(pool);
	} else {
		default_stack_commit = 1024 * 1024;
		default_stack_reserve = 1024 * 1024;
	}
	return TRUE;
}

int pthread_workqueue_init_np(void)
{
	InitOnceExecuteOnce(&stacksizes_set, get_default_stacksizes, NULL, NULL);
	return 0;
}

int pthread_workqueue_attr_init_np(pthread_workqueue_attr_t* attr)
{
	InitOnceExecuteOnce(&stacksizes_set, get_default_stacksizes, NULL, NULL);
	if(!attr)
	{
		return EINVAL;
	}
	*attr = calloc(1, sizeof(struct pthread_workqueue_attr));
	if(!*attr)
	{
		return ENOMEM;
	}
	InitializeThreadpoolEnvironment(&(*attr)->environment);
	(*attr)->qprio = WORKQ_DEFAULT_PRIOQUEUE;
	(*attr)->stackcommit = default_stack_commit;
	(*attr)->stackreserve = default_stack_reserve;
	return 0;
}

int pthread_workqueue_attr_destroy_np(pthread_workqueue_attr_t* attr)
{
	if(!attr || !*attr)
	{
		return EINVAL;
	}
	DestroyThreadpoolEnvironment(&(*attr)->environment);
	free(*attr);
	return 0;
}

int pthread_workqueue_attr_getqueuepriority_np(const pthread_workqueue_attr_t* attr, int* qprio)
{
	if(!attr || !*attr || !qprio)
	{
		return EINVAL;
	}
	*qprio = (*attr)->qprio;
	return 0;
}

int pthread_workqueue_attr_setqueuepriority_np(pthread_workqueue_attr_t* attr, int qprio)
{
	TP_CALLBACK_PRIORITY new_priority = TP_CALLBACK_PRIORITY_INVALID;
	if(!attr || !*attr)
	{
		return EINVAL;
	}
	switch(qprio)
	{
	case WORKQ_HIGH_PRIOQUEUE:
		new_priority = TP_CALLBACK_PRIORITY_HIGH;
		break;
	case WORKQ_DEFAULT_PRIOQUEUE:
		new_priority = TP_CALLBACK_PRIORITY_NORMAL;
		break;
	case WORKQ_LOW_PRIOQUEUE:
		new_priority = TP_CALLBACK_PRIORITY_LOW;
		break;
	default:
		return EINVAL;
	}
	// I can't GetProcAddress this, because in spite of the documentation this
	// is NOT an export from kernel32.dll, it's an inline function in winbase.h.
#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)
	SetThreadpoolCallbackPriority(&(*attr)->environment, new_priority);
#endif
	(*attr)->qprio = qprio;
	return 0;
}

int pthread_workqueue_attr_getstacksize_np(const pthread_workqueue_attr_t* attr, size_t* stacksizep)
{
	if(!attr || !*attr || !stacksizep)
	{
		return EINVAL;
	}
	*stacksizep = (*attr)->stackreserve;
	return 0;
}

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int pthread_workqueue_attr_setstacksize_np(pthread_workqueue_attr_t* attr, size_t stacksize)
{
	if(!attr || !*attr)
	{
		return EINVAL;
	}

	(*attr)->stackreserve = stacksize;
	return 0;
}

//int pthread_workqueue_attr_getthreadtimeshare_np(const pthread_workqueue_attr_t* attr, int* istimesahrep);
//int pthread_workqueue_attr_settthreadtimeshare_np(pthread_workqueue_attr_t* attr, int istimeshare);
//int pthread_workqueue_attr_getthreadimportance_np(const pthread_workqueue_attr_t* attr, int* importancep);
//int pthread_workqueue_attr_settthreadimportance_np(pthread_workqueue_attr_t* attr, int importance);
//int pthread_workqueue_attr_getthreadaffinity_np(const pthread_workqueue_attr_t* attr, int* affinityp);
//int pthread_workqueue_attr_settthreadaffinity_np(pthread_workqueue_attr_t* attr, int affinity);

int pthread_workqueue_attr_getovercommit_np(const pthread_workqueue_attr_t* attr, int* ocommp)
{
	if(!attr || !*attr || !ocommp)
	{
		return EINVAL;
	}
	*ocommp = 1;
	return 0;
}

int pthread_workqueue_attr_setovercommit_np(pthread_workqueue_attr_t* attr, int ocomm)
{
	if(!attr || !*attr)
	{
		return EINVAL;
	}

	UNREFERENCED_PARAMETER(ocomm);

	return ENOTSUP;
}

int _pthread_workqueue_attr_clone(const pthread_workqueue_attr_t* orig, pthread_workqueue_attr_t* clone)
{
	if(!orig|| !clone)
	{
		return EINVAL;
	}

	*clone = calloc(1, sizeof(struct pthread_workqueue_attr));
	if(!*clone)
	{
		return ENOMEM;
	}
	(**clone) = (**orig);
	return 0;
}

int pthread_workqueue_create_np(pthread_workqueue_t* workqp, const pthread_workqueue_attr_t* attr)
{
	if(!workqp || !attr)
	{
		return EINVAL;
	}

	*workqp = calloc(1, sizeof(struct pthread_workqueue));
	if(!*workqp)
	{
		return ENOMEM;
	}

	(*workqp)->pool = CreateThreadpool(NULL);
	_pthread_workqueue_attr_clone(attr, &(*workqp)->attr);
	SetThreadpoolCallbackPool(&(*workqp)->attr->environment, (*workqp)->pool);
	return 0;
}

typedef struct
{
	void (*function)(pthread_workqueue_t, void*);
	pthread_workqueue_t q;
	void* context;
} _pthread_callback_context;

void _pthread_workqueue_call_callback(void* context)
{
	_pthread_callback_context* pcc = context;
	pcc->function(pcc->q, pcc->context);
	free(context);
}

void _pthread_workqueue_call_workitem(void* context)
{
	_pthread_workitem* pw = context;
	pw->function(pw->context);
	free(context);
}

void _pthread_workqueue_destroyer(pthread_workqueue_t q, void* context)
{
	_pthread_callback_context* pcc = context;

	if(context)
	{
		pcc->function(pcc->q, pcc->context);
	}
	CloseThreadpool(q->pool);
	free(q->attr);
	free(q);
	free(context);
}

void _pthread_workqueue_barrier(pthread_workqueue_t q, void* context)
{
	_pthread_callback_context* pcc = context;

	UNREFERENCED_PARAMETER(q);

	if(context)
	{
		pcc->function(pcc->q, pcc->context);
	}
	free(context);
}

int _qprio_to_win32_prio(int qprio)
{
	switch(qprio)
	{
	case WORKQ_HIGH_PRIOQUEUE:
		return THREAD_PRIORITY_HIGHEST;
	case WORKQ_LOW_PRIOQUEUE:
		return THREAD_PRIORITY_LOWEST;
	default:
		return THREAD_PRIORITY_NORMAL;
	}
}

void CALLBACK _native_work_callback(TP_CALLBACK_INSTANCE* instance, void* context, TP_WORK* work)
{
	_pthread_workitem* workitem = context;
	int original_priority = GetThreadPriority(GetCurrentThread());

	UNREFERENCED_PARAMETER(instance);

	_pthread_tls_attach_thread();

	SetThreadPriority(GetCurrentThread(), _qprio_to_win32_prio(workitem->q->attr->qprio));
	workitem->function(workitem->context);
	CloseThreadpoolWork(work);
	free(workitem);
	SetThreadPriority(GetCurrentThread(), original_priority);

	_pthread_tls_detach_thread();
}

int _pthread_workqueue_submit_workitem(pthread_workqueue_t workq, void (*workitem_func)(void*), void* workitem_arg, pthread_workitem_handle_t* workitem_handle)
{
	_pthread_workitem* pw = calloc(1, sizeof(_pthread_workitem));
	pthread_workitem_handle_t pwh;

	if(!pw)
	{
		return ENOMEM;
	}

	pw->function = workitem_func;
	pw->q = workq;
	pw->context = workitem_arg;
	pwh.work = CreateThreadpoolWork(_native_work_callback, pw, &workq->attr->environment);
	if(workitem_handle)
	{
		workitem_handle->work = pwh.work;
	}
	SubmitThreadpoolWork(pwh.work);
	return 0;
}

void CALLBACK _native_timer_callback(TP_CALLBACK_INSTANCE* instance, void* context, TP_TIMER* timer)
{
	_pthread_workitem* workitem = context;
	int original_priority = GetThreadPriority(GetCurrentThread());

	UNREFERENCED_PARAMETER(instance);
	UNREFERENCED_PARAMETER(timer);

	_pthread_tls_attach_thread();

	SetThreadPriority(GetCurrentThread(), _qprio_to_win32_prio(workitem->q->attr->qprio));
	workitem->function(workitem->context);
	if(workitem->handle)
	{
		CloseThreadpoolTimer(workitem->handle->timer);
		free(workitem->handle);
		free(workitem);
	}
	SetThreadPriority(GetCurrentThread(), original_priority);

	_pthread_tls_detach_thread();
}

FILETIME _timespec_to_filetime(struct timespec* ts)
{
	LARGE_INTEGER computable_time = {0};
	FILETIME when = {0};

	computable_time.QuadPart = (ts->tv_sec * INTERVALS_PER_SEC) + (ts->tv_nsec / NSEC_PER_INTERVAL);
	computable_time.QuadPart += EPOCH_DIFFERENCE;

	when.dwHighDateTime = computable_time.HighPart;
	when.dwLowDateTime = computable_time.LowPart;
	return when;
}

int _pthread_workqueue_submit_timeritem(pthread_workqueue_t workq, struct timespec* ts, long period, long leeway, void (*workitem_func)(void*), void* workitem_arg, pthread_timeritem_handle_t* timeritem_handle)
{
	_pthread_workitem* pw = calloc(1, sizeof(_pthread_workitem));
	FILETIME actual_time = {0};

	if(!pw)
	{
		return ENOMEM;
	}

	pw->function = workitem_func;
	pw->context = workitem_arg;
	pw->q = workq;
	if(!timeritem_handle && !period)
	{
		timeritem_handle = calloc(1, sizeof(pthread_timeritem_handle_t));
		pw->handle = timeritem_handle;
	}
	if(!timeritem_handle)
	{
		return ENOMEM;
	}
	timeritem_handle->timer = CreateThreadpoolTimer(_native_timer_callback, pw, &workq->attr->environment);
	actual_time = _timespec_to_filetime(ts);
	SetThreadpoolTimer(timeritem_handle->timer, &actual_time, (DWORD)period, (DWORD)leeway);
	return 0;
}

int pthread_workqueue_destroy_np(pthread_workqueue_t workq, void (*callback_func)(pthread_workqueue_t, void*), void* callback_arg)
{
	_pthread_callback_context* pcc_outer = NULL;
	_pthread_callback_context* pcc_inner = NULL;

	if(!workq || (!callback_func && callback_arg))
	{
		return EINVAL;
	}

	pcc_outer = calloc(1, sizeof(_pthread_callback_context));
	if(!pcc_outer)
	{
		return ENOMEM;
	}
	if(callback_func)
	{
		pcc_inner = calloc(1, sizeof(_pthread_callback_context));
		if(!pcc_inner)
		{
			free(pcc_outer);
			return ENOMEM;
		}
		pcc_inner->context = callback_arg;
		pcc_inner->function = callback_func;
		pcc_inner->q = workq;
	}
	pcc_outer->context = pcc_inner;
	pcc_outer->function = _pthread_workqueue_destroyer;
	pcc_outer->q = workq;

	return _pthread_workqueue_submit_workitem(workq, _pthread_workqueue_call_callback, pcc_outer, NULL);
}

int pthread_workqueue_additem_np(pthread_workqueue_t workq, void (*workitem_func)(void*), void* workitem_arg, pthread_workitem_handle_t* itemhandlep)
{
	if(!workq || !workitem_func)
	{
		return EINVAL;
	}

	return _pthread_workqueue_submit_workitem(workq, workitem_func, workitem_arg, itemhandlep);
}

int pthread_workqueue_addtimeritem_np(pthread_workqueue_t workq, struct timespec* ts, long period, long leeway, void (*workitem_func)(void*), void* workitem_arg, pthread_timeritem_handle_t* itemhandlep)
{
	if(!workq || !ts || !workitem_func)
	{
		return EINVAL;
	}
	if(period > 0 && !itemhandlep)
	{
		return EINVAL;
	}

	return _pthread_workqueue_submit_timeritem(workq, ts, period, leeway, workitem_func, workitem_arg, itemhandlep);
}

int pthread_workqueue_removeitem_np(pthread_workqueue_t workq, pthread_workitem_handle_t itemhandle)
{
	if(!workq || !itemhandle.work)
	{
		return EINVAL;
	}
	WaitForThreadpoolWorkCallbacks(itemhandle.work, TRUE);
	CloseThreadpoolWork(itemhandle.work);
	itemhandle.work = NULL;
	return 0;
}

int pthread_workqueue_removetimeritem_np(pthread_workqueue_t workq, pthread_timeritem_handle_t itemhandle)
{
	if(!workq || !itemhandle.timer)
	{
		return EINVAL;
	}
	SetThreadpoolTimer(itemhandle.timer, NULL, 0, 0);
	WaitForThreadpoolTimerCallbacks(itemhandle.timer, TRUE);
	CloseThreadpoolTimer(itemhandle.timer);
	itemhandle.timer = NULL;
	free(itemhandle.workitem);
	itemhandle.workitem = NULL;
	return 0;
}

int pthread_workqueue_settimeritem_np(pthread_workqueue_t workq, pthread_timeritem_handle_t timeritem_handle, struct timespec* ts, long period, long leeway)
{
	FILETIME actual_time = {0};
	if(!workq || !timeritem_handle.timer)
	{
		return EINVAL;
	}
	actual_time = _timespec_to_filetime(ts);
	SetThreadpoolTimer(timeritem_handle.timer, &actual_time, (DWORD)period, (DWORD)leeway);
	return 0;
}

int pthread_workqueue_addbarrier_np(pthread_workqueue_t workq, void (*callback_func)(pthread_workqueue_t, void*), void* callback_arg, int waitforcallback, pthread_workitem_handle_t* itemhandlep)
{
	_pthread_callback_context* pcc_outer = NULL;
	_pthread_callback_context* pcc_inner = NULL;
	pthread_workitem_handle_t pwh;

	if(!workq || (!callback_func && callback_arg))
	{
		return EINVAL;
	}

	pcc_outer = calloc(1, sizeof(_pthread_callback_context));
	if(!pcc_outer)
	{
		return ENOMEM;
	}
	if(callback_func)
	{
		pcc_inner = calloc(1, sizeof(_pthread_callback_context));
		if(!pcc_inner)
		{
			free(pcc_outer);
			return ENOMEM;
		}
		pcc_inner->context = callback_arg;
		pcc_inner->function = callback_func;
		pcc_inner->q = workq;
	}
	pcc_outer->context = pcc_inner;
	pcc_outer->function = _pthread_workqueue_barrier;
	pcc_outer->q = workq;

	_pthread_workqueue_submit_workitem(workq, _pthread_workqueue_call_callback, pcc_outer, &pwh);
	if(itemhandlep)
	{
		itemhandlep->work = pwh.work;
	}
	if(waitforcallback)
	{
		WaitForThreadpoolWorkCallbacks(pwh.work, FALSE);
	}
	return 0;
}

//int pthread_workqueue_suspend_np(pthread_workqueue_t workq);
//int pthread_workqueue_resume_np(pthread_workqueue_t workq);

int pthread_workqueue_requestconcurrency_np(int queue, int concurrency)
{
	if(queue < 0 || queue > WORKQ_NUM_PRIOQUEUE)
	{
		return EINVAL;
	}
	SetThreadpoolThreadMaximum(NULL, (DWORD)concurrency);
	return 0;
}

int pthread_workqueue_getovercommit_np(pthread_workqueue_t workq,  unsigned int* ocommp)
{
	if(!workq || !ocommp)
	{
		return EINVAL;
	}
	*ocommp = 1;
	return 0;
}

int pthread_workqueue_setqueuepriority_np(pthread_workqueue_t workq, int qprio)
{
	if(!workq)
	{
		return EINVAL;
	}

	return pthread_workqueue_attr_setqueuepriority_np(&workq->attr, qprio);
}
