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

#include <Foundation/Foundation.h>
#include <libkern/OSAtomic.h>
#include <sys/sysctl.h>
#include <mach/mach.h>
#include <mach/mach_time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>
#include <pthread.h>
#include <math.h>
#ifdef __BLOCKS__
#include <Block.h>
#endif
#include <dispatch/dispatch.h>
#include <dispatch/private.h>

extern "C" {
__private_extern__ void func(void);
#ifdef __BLOCKS__
__private_extern__ void (^block)(void);
#endif
static void backflip(void *ctxt);
static void backflip_done(void);
}

@interface BasicObject : NSObject
{
}
- (void) method;
@end

@implementation BasicObject
- (void) method
{
}
@end

class BasicClass {
public:
	virtual void virtfunc(void) {
	};
};

static void *
force_a_thread(void *arg)
{
	pause();
	abort();
	return arg;
}

static volatile int32_t global;

static const size_t cnt = 10000000;
static const size_t cnt2 = 100000;

static uint64_t bfs;
static long double loop_cost;
static long double cycles_per_nanosecond;
static mach_timebase_info_data_t tbi;

//static void func2(void *, dispatch_item_t di);

static void __attribute__((noinline))
print_result(uint64_t s, const char *str)
{
	uint64_t d, e = mach_absolute_time();
	long double dd;

	d = e - s;

	if (tbi.numer != tbi.denom) {
		d *= tbi.numer;
		d /= tbi.denom;
	}

	dd = (typeof(dd))d / (typeof(dd))cnt;

	dd -= loop_cost;

	if (loop_cost == 0.0) {
		loop_cost = dd;
	}

	dd *= cycles_per_nanosecond;

	printf("%-45s%15.3Lf cycles\n", str, dd);
}

static void __attribute__((noinline))
print_result2(uint64_t s, const char *str)
{
	uint64_t d, e = mach_absolute_time();
	long double dd;

	d = e - s;

	if (tbi.numer != tbi.denom) {
		d *= tbi.numer;
		d /= tbi.denom;
	}

	dd = (typeof(dd))d / (typeof(dd))cnt2;

	dd -= loop_cost;
	dd *= cycles_per_nanosecond;

	printf("%-45s%15.3Lf cycles\n", str, dd);
}

#if defined(__i386__) || defined(__x86_64__)
static inline uint64_t
rdtsc(void)
{
	uint32_t lo, hi;

	asm volatile("rdtsc" : "=a" (lo), "=d" (hi));

	return (uint64_t)hi << 32 | lo;
}
#endif

static struct fml {
	struct fml *fml_next;
} *fixed_malloc_lifo_head;

struct fml *fixed_malloc_lifo(void);// __attribute__((noinline));
void fixed_free_lifo(struct fml *fml);// __attribute__((noinline));

struct fml *
fixed_malloc_lifo(void)
{
	struct fml *fml_r = fixed_malloc_lifo_head;

	if (fml_r) {
		fixed_malloc_lifo_head = fml_r->fml_next;
		return fml_r;
	} else {
		return (struct fml *)malloc(32);
	}
}

void
fixed_free_lifo(struct fml *fml)
{
	fml->fml_next = fixed_malloc_lifo_head;
	fixed_malloc_lifo_head = fml;
}

int
main(void)
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	pthread_mutex_t plock = PTHREAD_MUTEX_INITIALIZER;
	OSSpinLock slock = OS_SPINLOCK_INIT;
	BasicObject *bo;
	BasicClass *bc;
	pthread_t pthr_pause;
	dispatch_queue_t q, mq;
	kern_return_t kr;
	semaphore_t sem;
	uint64_t freq;
	uint64_t s;
	size_t freq_len = sizeof(freq);
	size_t bf_cnt = cnt;
	unsigned i;
	int r;

	r = sysctlbyname("hw.cpufrequency", &freq, &freq_len, NULL, 0);
	assert(r != -1);
	assert(freq_len == sizeof(freq));

	cycles_per_nanosecond = (long double)freq / (long double)NSEC_PER_SEC;

	assert(pool);

	/* Malloc has different logic for threaded apps. */
	r = pthread_create(&pthr_pause, NULL, force_a_thread, NULL);
	assert(r == 0);

	kr = mach_timebase_info(&tbi);
	assert(kr == 0);
#if defined(__i386__) || defined(__x86_64__)
	assert(tbi.numer == tbi.denom); /* This will fail on PowerPC. */
#endif

	bo = [[BasicObject alloc] init];
	assert(bo);

	bc = new BasicClass();
	assert(bc);

	q = dispatch_queue_create("com.apple.bench-dispatch", NULL);
	assert(q);

	mq = dispatch_get_main_queue();
	assert(mq);

	printf("%-45s%15Lf\n\n", "Cycles per nanosecond:", cycles_per_nanosecond);

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		asm volatile("");
	}
	print_result(s, "Empty loop:");

	printf("\nLoop cost subtracted from the following:\n\n");

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		mach_absolute_time();
	}
	print_result(s, "mach_absolute_time():");

#if defined(__i386__) || defined(__x86_64__)
	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		rdtsc();
	}
	print_result(s, "rdtsc():");
#endif

	s = mach_absolute_time();
	for (i = cnt2; i; i--) {
		pthread_t pthr;
		void *pr;

		r = pthread_create(&pthr, NULL, (void *(*)(void *))func, NULL);
		assert(r == 0);
		r = pthread_join(pthr, &pr);
		assert(r == 0);
	}
	print_result2(s, "pthread create+join:");

	s = mach_absolute_time();
	for (i = cnt2; i; i--) {
		kr = semaphore_create(mach_task_self(), &sem, SYNC_POLICY_FIFO, 0);
		assert(kr == 0);
		kr = semaphore_destroy(mach_task_self(), sem);
		assert(kr == 0);
	}
	print_result2(s, "Mach semaphore create/destroy:");

	kr = semaphore_create(mach_task_self(), &sem, SYNC_POLICY_FIFO, 0);
	assert(kr == 0);
	s = mach_absolute_time();
	for (i = cnt2; i; i--) {
		kr = semaphore_signal(sem);
		assert(kr == 0);
	}
	print_result2(s, "Mach semaphore signal:");
	kr = semaphore_destroy(mach_task_self(), sem);
	assert(kr == 0);

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		pthread_yield_np();
	}
	print_result(s, "pthread_yield_np():");

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		free(malloc(32));
	}
	print_result(s, "free(malloc(32)):");

	s = mach_absolute_time();
	for (i = cnt / 2; i; i--) {
		void *m1 = malloc(32);
		void *m2 = malloc(32);
		free(m1);
		free(m2);
	}
	print_result(s, "Avoiding the MRU cache of free(malloc(32)):");

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		fixed_free_lifo(fixed_malloc_lifo());
	}
	print_result(s, "per-thread/fixed free(malloc(32)):");

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		assert(strtoull("18446744073709551615", NULL, 0) == ~0ull);
	}
	print_result(s, "strtoull(\"18446744073709551615\") == ~0ull:");

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		func();
	}
	print_result(s, "Empty function call:");

#ifdef __BLOCKS__
	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		block();
	}
	print_result(s, "Empty block call:");
#endif

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		[bo method];
	}
	print_result(s, "Empty ObjC call:");

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		bc->virtfunc();
	}
	print_result(s, "Empty C++ virtual call:");

	s = mach_absolute_time();
	for (i = cnt2; i; i--) {
		[bo description];
	}
	print_result2(s, "\"description\" ObjC call:");

	[pool release];

	pool = NULL;

#if defined(__i386__) || defined(__x86_64__)
	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		asm("nop");
	}
	print_result(s, "raw 'nop':");

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		asm("pause");
	}
	print_result(s, "raw 'pause':");

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		asm("mfence");
	}
	print_result(s, "Atomic mfence:");

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		asm("lfence");
	}
	print_result(s, "Atomic lfence:");

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		asm("sfence");
	}
	print_result(s, "Atomic sfence:");

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		uint64_t sidt_rval;
		asm("sidt %0" : "=m" (sidt_rval));
	}
	print_result(s, "'sidt' instruction:");

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		int prev;
		asm volatile("cmpxchg %1,%2" : "=a" (prev) : "r" (0l), "m" (global), "0" (1l));
	}
	print_result(s, "'cmpxchg' without the 'lock' prefix:");
#endif

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		__sync_lock_test_and_set(&global, 0);
	}
	print_result(s, "Atomic xchg:");

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		__sync_val_compare_and_swap(&global, 1, 0);
	}
	print_result(s, "Atomic cmpxchg:");

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		__sync_fetch_and_add(&global, 1);
	}
	print_result(s, "Atomic increment:");

	global = 0;

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		OSAtomicIncrement32Barrier(&global);
	}
	print_result(s, "OSAtomic increment:");

	global = 0;

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		while (!__sync_bool_compare_and_swap(&global, 0, 1)) {
			do {
#if defined(__i386__) || defined(__x86_64__)
				asm("pause");
#endif
			} while (global);
		}
		global = 0;
	}
	print_result(s, "Inlined spin lock/unlock:");

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		OSSpinLockLock(&slock);
		OSSpinLockUnlock(&slock);
	}
	print_result(s, "OS spin lock/unlock:");

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		r = pthread_mutex_lock(&plock);
		assert(r == 0);
		r = pthread_mutex_unlock(&plock);
		assert(r == 0);
	}
	print_result(s, "pthread lock/unlock:");

#ifdef __BLOCKS__
	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		dispatch_sync(q, ^{ });
	}
	print_result(s, "dispatch_sync:");
#endif

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		dispatch_sync_f(q, NULL, (void (*)(void *))func);
	}
	print_result(s, "dispatch_sync_f:");

#ifdef __BLOCKS__
	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		dispatch_barrier_sync(q, ^{ });
	}
	print_result(s, "dispatch_barrier_sync:");
#endif

	s = mach_absolute_time();
	for (i = cnt; i; i--) {
		dispatch_barrier_sync_f(q, NULL, (void (*)(void *))func);
	}
	print_result(s, "dispatch_barrier_sync_f:");

	s = mach_absolute_time();
	dispatch_apply_f(cnt, dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), NULL, (void (*)(void *, size_t))func);
	s += loop_cost; /* cancel out the implicit subtraction done by the next line */
	print_result(s, "dispatch_apply_f():");

	// we do a "double backflip" to hit the fast-path of the enqueue/dequeue logic
	bfs = mach_absolute_time();
	dispatch_async_f(dispatch_get_main_queue(), &bf_cnt, backflip);
	dispatch_async_f(dispatch_get_main_queue(), &bf_cnt, backflip);

	dispatch_main();
}

__attribute__((noinline))
void
backflip_done(void)
{
	print_result(bfs, "dispatch_async_f():");
	exit(EXIT_SUCCESS);
}

void
backflip(void *ctxt)
{
	size_t *bf_cnt = (size_t *)ctxt;
	if (--(*bf_cnt)) {
		return dispatch_async_f(dispatch_get_main_queue(), ctxt, backflip);
	}
	backflip_done();
}
