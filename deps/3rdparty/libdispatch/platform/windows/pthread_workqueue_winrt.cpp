#include "pthread_workqueue.h"

#define _CRT_SECURE_NO_WARNINGS 1

#include <SDKDDKVer.h>
#include <Windows.h>
#include <concrt.h>
#include <assert.h>
#include <Windows.Foundation.h>
#include <Windows.System.Threading.h>
#include <wrl/event.h>

#ifdef _MSC_VER

#if defined DEBUG || defined _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_CLIENTBLOCK new(_CLIENT_BLOCK, __FILE__, __LINE__)
#define new DEBUG_CLIENTBLOCK
#endif

#endif

#include <time.h>

#include <errno.h>

#include "pthread.h"

#define WINOBJC

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::System::Threading;

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
#if 0
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
#else
	//  TODO
	default_stack_commit = 1024 * 1024;
	default_stack_reserve = 1024 * 1024;
#endif
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
	*attr = (pthread_workqueue_attr_t) calloc(1, sizeof(struct pthread_workqueue_attr));
	if(!*attr)
	{
		return ENOMEM;
	}
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

	*clone = (pthread_workqueue_attr_t) calloc(1, sizeof(struct pthread_workqueue_attr));
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

	*workqp = (pthread_workqueue_t) calloc(1, sizeof(struct pthread_workqueue));
	if(!*workqp)
	{
		return ENOMEM;
	}

#if 0
	(*workqp)->pool = CreateThreadpool(NULL);
#endif
	_pthread_workqueue_attr_clone(attr, &(*workqp)->attr);
#if 0
	SetThreadpoolCallbackPool(&(*workqp)->attr->environment, (*workqp)->pool);
#endif
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
	_pthread_callback_context* pcc = (_pthread_callback_context*) context;
	pcc->function(pcc->q, pcc->context);
	free(context);
}

void _pthread_workqueue_call_workitem(void* context)
{
	_pthread_workitem* pw = (_pthread_workitem*) context;
	pw->function(pw->context);
	free(context);
}

void _pthread_workqueue_destroyer(pthread_workqueue_t q, void* context)
{
	_pthread_callback_context* pcc = (_pthread_callback_context*)context;

	if(context)
	{
		pcc->function(pcc->q, pcc->context);
	}
#if 0
	CloseThreadpool(q->pool);
#endif
	free(q->attr);
	free(q);
	free(context);
}

void _pthread_workqueue_barrier(pthread_workqueue_t q, void* context)
{
	_pthread_callback_context* pcc = (_pthread_callback_context*) context;

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

void CALLBACK _native_work_callback(void* context)
{
	_pthread_workitem* workitem = (_pthread_workitem*) context;
	int original_priority = GetThreadPriority(GetCurrentThread());

	_pthread_tls_attach_thread();

	SetThreadPriority(GetCurrentThread(), _qprio_to_win32_prio(workitem->q->attr->qprio));
	workitem->function(workitem->context);
	free(workitem);
	SetThreadPriority(GetCurrentThread(), original_priority);

	_pthread_tls_detach_thread();
}

int _pthread_workqueue_submit_workitem(pthread_workqueue_t workq, void (*workitem_func)(void*), void* workitem_arg, pthread_workitem_handle_t* workitem_handle)
{
	_pthread_workitem* pw = (_pthread_workitem*) calloc(1, sizeof(_pthread_workitem));
	pthread_workitem_handle_t pwh;

	if(!pw)
	{
		return ENOMEM;
	}

	pw->function = workitem_func;
	pw->q = workq;
	pw->context = workitem_arg;

	pwh.work = NULL;

	auto workItem = Callback<
		Implements<RuntimeClassFlags<ClassicCom>,
		ABI::Windows::System::Threading::IWorkItemHandler,
		FtmBase>>([pw](IAsyncAction* asyncAction)
		{
			UNREFERENCED_PARAMETER(asyncAction);
			_native_work_callback(pw);
			return S_OK;
		});

	if(workitem_handle)
	{
		workitem_handle->work = pwh.work;
	}

	WorkItemPriority prio = WorkItemPriority::WorkItemPriority_Normal;

	switch ( pw->q->attr->qprio ) {
		case WORKQ_HIGH_PRIOQUEUE:
			prio = WorkItemPriority::WorkItemPriority_High;
			break;
		case WORKQ_LOW_PRIOQUEUE:
			prio = WorkItemPriority::WorkItemPriority_Low;
			break;
		default:
			prio = WorkItemPriority::WorkItemPriority_Normal;
			break;
	}

	ComPtr<IThreadPoolStatics> threadPool;
	HRESULT hr = GetActivationFactory(HStringReference(RuntimeClass_Windows_System_Threading_ThreadPool).Get(), &threadPool);
	if (FAILED(hr))
	{
		abort();
	}

	ComPtr<IAsyncAction> asyncAction;
	hr = threadPool->RunWithPriorityAsync(workItem.Get(), prio, &asyncAction);
	if (FAILED(hr))
	{
		abort();
	}

	return 0;
}

void CALLBACK _native_timer_callback(TP_CALLBACK_INSTANCE* instance, void* context, TP_TIMER* timer)
{
	_pthread_workitem* workitem = (_pthread_workitem*)context;
	int original_priority = GetThreadPriority(GetCurrentThread());

	UNREFERENCED_PARAMETER(instance);
	UNREFERENCED_PARAMETER(timer);

	_pthread_tls_attach_thread();

	SetThreadPriority(GetCurrentThread(), _qprio_to_win32_prio(workitem->q->attr->qprio));
	workitem->function(workitem->context);
	if(workitem->handle)
	{
#if 0
		CloseThreadpoolTimer(workitem->handle->timer);
#endif
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
	_pthread_workitem* pw = (_pthread_workitem*)calloc(1, sizeof(_pthread_workitem));
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
		timeritem_handle = (pthread_timeritem_handle_t*) calloc(1, sizeof(pthread_timeritem_handle_t));
		pw->handle = timeritem_handle;
	}
	if(!timeritem_handle)
	{
		return ENOMEM;
	}
#if 0
	timeritem_handle->timer = CreateThreadpoolTimer(_native_timer_callback, pw, &workq->attr->environment);
#else
	assert(0 && "Timers not implemented for WinRT threadpools");
#endif
	actual_time = _timespec_to_filetime(ts);
#if 0
	SetThreadpoolTimer(timeritem_handle->timer, &actual_time, (DWORD)period, (DWORD)leeway);
#endif
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

	pcc_outer = (_pthread_callback_context*)calloc(1, sizeof(_pthread_callback_context));
	if(!pcc_outer)
	{
		return ENOMEM;
	}
	if(callback_func)
	{
		pcc_inner = (_pthread_callback_context*)calloc(1, sizeof(_pthread_callback_context));
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
#if 0
	WaitForThreadpoolWorkCallbacks(itemhandle.work, TRUE);
	CloseThreadpoolWork(itemhandle.work);
#else
	assert(0 && "Threadpool item removal not yet supported on WinRT");
#endif
	itemhandle.work = NULL;
	return 0;
}

int pthread_workqueue_removetimeritem_np(pthread_workqueue_t workq, pthread_timeritem_handle_t itemhandle)
{
	if(!workq || !itemhandle.timer)
	{
		return EINVAL;
	}
#if 0
	SetThreadpoolTimer(itemhandle.timer, NULL, 0, 0);
	WaitForThreadpoolTimerCallbacks(itemhandle.timer, TRUE);
	CloseThreadpoolTimer(itemhandle.timer);
#endif
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
#if 0
	SetThreadpoolTimer(timeritem_handle.timer, &actual_time, (DWORD)period, (DWORD)leeway);
#else
	assert(0 && "Threadpool timers not yet supported on WinRT");
#endif
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

	pcc_outer = (_pthread_callback_context*) calloc(1, sizeof(_pthread_callback_context));
	if(!pcc_outer)
	{
		return ENOMEM;
	}
	if(callback_func)
	{
		pcc_inner = (_pthread_callback_context*) calloc(1, sizeof(_pthread_callback_context));
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
#if 0
		WaitForThreadpoolWorkCallbacks(pwh.work, FALSE);
#else
		assert(0 && "Threadpool barriers not yet supported on WinRT");
#endif
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
#if 0
	SetThreadpoolThreadMaximum(NULL, (DWORD)concurrency);
#endif
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
