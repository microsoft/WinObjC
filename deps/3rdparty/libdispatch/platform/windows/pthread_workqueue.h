#ifndef PLATFORM_WINDOWS_PTHREAD_WORKQUEUE__H
#define PLATFORM_WINDOWS_PTHREAD_WORKQUEUE__H

#include "time.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define	WORKQ_HIGH_PRIOQUEUE	0	/* Assign to high priority queue.*/
#define WORKQ_DEFAULT_PRIOQUEUE	1	/* Assign to default priority queue.*/
#define WORKQ_LOW_PRIOQUEUE	2	/* Assign to low priority queue.*/
#define WORKQ_NUM_PRIOQUEUE	3

typedef struct pthread_workqueue_attr* pthread_workqueue_attr_t;
typedef struct pthread_workqueue* pthread_workqueue_t;
typedef struct pthread_workitem_handle pthread_workitem_handle_t;

typedef struct _TP_WORK TP_WORK;
typedef struct _TP_TIMER TP_TIMER;
typedef struct _pthread_workitem _pthread_workitem;

struct pthread_workitem_handle
{
#ifndef WINOBJC
	TP_WORK* work;
#endif
};
typedef struct pthread_workitem_handle pthread_workitem_handle_t;
struct pthread_timeritem_handle
{
	TP_TIMER* timer;
	_pthread_workitem* workitem;
};
typedef struct pthread_timeritem_handle pthread_timeritem_handle_t;

int pthread_workqueue_init_np(void);
int pthread_workqueue_attr_init_np(pthread_workqueue_attr_t* attr);
int pthread_workqueue_attr_destroy_np(pthread_workqueue_attr_t* attr);
int pthread_workqueue_attr_getqueuepriority_np(const pthread_workqueue_attr_t* attr, int* qprio);
int pthread_workqueue_attr_setqueuepriority_np(pthread_workqueue_attr_t* attr, int qprio);
int pthread_workqueue_attr_getstacksize_np(const pthread_workqueue_attr_t* attr, size_t* stacksizep);
int pthread_workqueue_attr_setstacksize_np(pthread_workqueue_attr_t* attr, size_t stacksize);
int pthread_workqueue_attr_getthreadtimeshare_np(const pthread_workqueue_attr_t* attr, int* istimesahrep);
int pthread_workqueue_attr_settthreadtimeshare_np(pthread_workqueue_attr_t* attr, int istimeshare);
int pthread_workqueue_attr_getthreadimportance_np(const pthread_workqueue_attr_t* attr, int* importancep);
int pthread_workqueue_attr_settthreadimportance_np(pthread_workqueue_attr_t* attr, int importance);
int pthread_workqueue_attr_getthreadaffinity_np(const pthread_workqueue_attr_t* attr, int* affinityp);
int pthread_workqueue_attr_settthreadaffinity_np(pthread_workqueue_attr_t* attr, int affinity);
int pthread_workqueue_attr_getovercommit_np(const pthread_workqueue_attr_t* attr, int* ocommp);
int pthread_workqueue_attr_setovercommit_np(pthread_workqueue_attr_t* attr, int ocomm);

int pthread_workqueue_create_np(pthread_workqueue_t* workqp, const pthread_workqueue_attr_t* attr);
int pthread_workqueue_destroy_np(pthread_workqueue_t workq, void (*callback_func)(pthread_workqueue_t, void*), void* callback_arg);
int pthread_workqueue_additem_np(pthread_workqueue_t workq, void (*workitem_func)(void*), void* workitem_arg, pthread_workitem_handle_t* itemhandlep);
int pthread_workqueue_removeitem_np(pthread_workqueue_t workq, pthread_workitem_handle_t itemhandle);
int pthread_workqueue_addtimeritem_np(pthread_workqueue_t workq, struct timespec* ts, long period, long leeway, void (*workitem_func)(void*), void* workitem_arg, pthread_timeritem_handle_t* itemhandlep);
int pthread_workqueue_settimeritem_np(pthread_workqueue_t workq, pthread_timeritem_handle_t itemhandle, struct timespec* ts, long period, long leeway);
int pthread_workqueue_removetimeritem_np(pthread_workqueue_t workq, pthread_timeritem_handle_t itemhandle);

int pthread_workqueue_addbarrier_np(pthread_workqueue_t workq, void (*callback_func)(pthread_workqueue_t, void*), void* callback_arg, int waitforcallback, pthread_workitem_handle_t* itemhandlep);
int pthread_workqueue_suspend_np(pthread_workqueue_t workq);
int pthread_workqueue_resume_np(pthread_workqueue_t workq);
int pthread_workqueue_requestconcurrency_np(int queue, int concurrency);
int pthread_workqueue_getovercommit_np(pthread_workqueue_t workq, unsigned int* ocommp);
int pthread_workqueue_setqueuepriority_np(pthread_workqueue_t workq, int qprio);

#ifdef __cplusplus
}
#endif

#endif
