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

// We'd use __attribute__((aligned(x))), but it does not atually increase the
// alignment of stack variables. All we really need is the stack usage of the
// local thread to be sufficiently away to avoid cache-line contention with the
// busy 'da_index' variable.
//
// NOTE: 'char' arrays cause GCC to insert buffer overflow detection logic 
struct dispatch_apply_s {
	long	_da_pad0[DISPATCH_CACHELINE_SIZE / sizeof(long)];
	dispatch_function_apply_t da_func;
	void	*da_ctxt;
	size_t	da_iterations;
	size_t	da_index;
	size_t	da_thr_cnt;
	dispatch_semaphore_t da_sema;
	long	_da_pad1[DISPATCH_CACHELINE_SIZE / sizeof(long)];
};

static void
_dispatch_apply2(void *_ctxt)
{
	struct dispatch_apply_s *da = _ctxt;
	size_t const iter = da->da_iterations;
	dispatch_function_apply_t func = da->da_func;
	void *const ctxt = da->da_ctxt;
	size_t idx;

	_dispatch_workitem_dec(); // this unit executes many items

	// Striding is the responsibility of the caller.
	while (fastpath((idx = dispatch_atomic_inc((intptr_t*)&da->da_index) - 1) < iter)) {
		func(ctxt, idx);
		_dispatch_workitem_inc();
	}

	if (dispatch_atomic_dec((intptr_t*)&da->da_thr_cnt) == 0) {
		dispatch_semaphore_signal(da->da_sema);
	}
}

static void
_dispatch_apply_serial(void *context)
{
	struct dispatch_apply_s *da = context;
	size_t idx = 0;

	_dispatch_workitem_dec(); // this unit executes many items
	do {
		da->da_func(da->da_ctxt, idx);
		_dispatch_workitem_inc();
	} while (++idx < da->da_iterations);
}

#ifdef __BLOCKS__
void
dispatch_apply(size_t iterations, dispatch_queue_t dq, void (^work)(size_t))
{
	struct Block_basic *bb = (void *)work;

	dispatch_apply_f(iterations, dq, bb, (void *)bb->Block_invoke);
}
#endif

// 256 threads should be good enough for the short to mid term
#define DISPATCH_APPLY_MAX_CPUS	256

DISPATCH_NOINLINE
void
dispatch_apply_f(size_t iterations, dispatch_queue_t dq, void *ctxt, dispatch_function_apply_t func)
{
	struct dispatch_apply_dc_s {
		DISPATCH_CONTINUATION_HEADER(dispatch_apply_dc_s);
	} da_dc[DISPATCH_APPLY_MAX_CPUS];
	struct dispatch_apply_s da;
	size_t i;

	da.da_func = func;
	da.da_ctxt = ctxt;
	da.da_iterations = iterations;
	da.da_index = 0;
	da.da_thr_cnt = _dispatch_hw_config.cc_max_active;

	if (da.da_thr_cnt > DISPATCH_APPLY_MAX_CPUS) {
		da.da_thr_cnt = DISPATCH_APPLY_MAX_CPUS;
	}
	if (slowpath(iterations == 0)) {
		return;
	}
	if (iterations < da.da_thr_cnt) {
		da.da_thr_cnt = iterations;
	}
	if (slowpath(dq->dq_width <= 2 || da.da_thr_cnt <= 1)) {
		dispatch_sync_f(dq, &da, _dispatch_apply_serial);
		return;
	}

	for (i = 0; i < da.da_thr_cnt; i++) {
		da_dc[i].do_vtable = NULL;
		da_dc[i].do_next = &da_dc[i + 1];
		da_dc[i].dc_func = _dispatch_apply2;
		da_dc[i].dc_ctxt = &da;
	}

	da.da_sema = _dispatch_get_thread_semaphore();

	// some queues are easy to borrow and some are not
	if (slowpath(dq->do_targetq)) {
		_dispatch_queue_push_list(dq, as_do((void *)&da_dc[0]), as_do((void *)&da_dc[da.da_thr_cnt - 1]));
	} else {
		dispatch_queue_t old_dq = _dispatch_thread_getspecific(dispatch_queue_key);
		// root queues are always concurrent and safe to borrow
		_dispatch_queue_push_list(dq, as_do((void *)&da_dc[1]), as_do((void *)&da_dc[da.da_thr_cnt - 1]));
		_dispatch_thread_setspecific(dispatch_queue_key, dq);
		// The first da_dc[] element was explicitly not pushed on to the queue.
		// We need to either call it like so:
		//     da_dc[0].dc_func(da_dc[0].dc_ctxt);
		// Or, given that we know the 'func' and 'ctxt', we can call it directly:
		_dispatch_apply2(&da);
		_dispatch_workitem_inc();
		_dispatch_thread_setspecific(dispatch_queue_key, old_dq);
	}
	dispatch_semaphore_wait(da.da_sema, DISPATCH_TIME_FOREVER);
	_dispatch_put_thread_semaphore(da.da_sema);
}

#if 0
#ifdef __BLOCKS__
void
dispatch_stride(size_t offset, size_t stride, size_t iterations, dispatch_queue_t dq, void (^work)(size_t))
{
	struct Block_basic *bb = (void *)work;
	dispatch_stride_f(offset, stride, iterations, dq, bb, (void *)bb->Block_invoke);
}
#endif

DISPATCH_NOINLINE
void
dispatch_stride_f(size_t offset, size_t stride, size_t iterations,
		dispatch_queue_t dq, void *ctxt, dispatch_function_apply_t func)
{
	if (stride == 0) {
		stride = 1;
	}
	dispatch_apply(iterations / stride, queue, ^(size_t idx) {
		size_t i = idx * stride + offset;
		size_t stop = i + stride;
		do {
			func(ctxt, i++);
		} while (i < stop);
	});

	dispatch_sync(queue, ^{
		size_t i;
		for (i = iterations - (iterations % stride); i < iterations; i++) {
			func(ctxt, i + offset);
		}
	});
}
#endif
