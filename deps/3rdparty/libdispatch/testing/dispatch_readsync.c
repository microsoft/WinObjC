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

#include "config/config.h"

#include <dispatch/dispatch.h>
#define __DISPATCH_INDIRECT__
#include "src/queue_private.h"
#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <assert.h>

#include "dispatch_test.h"

#define LAPS 10000
#define INTERVAL 100

static size_t r_count = LAPS;
static size_t w_count = LAPS / INTERVAL;

static void
writer(void *ctxt __attribute__((unused)))
{
	if (--w_count == 0) {
		if (r_count == 0) {
			test_stop();
		}
	}
}

static void
reader(void *ctxt __attribute__((unused)))
{
	if (__sync_sub_and_fetch(&r_count, 1) == 0) {
		if (r_count == 0) {
			test_stop();
		}
	}
}

int
main(void)
{
	dispatch_queue_t dq;

	test_start("Dispatch Reader/Writer Queues");

	dq = dispatch_queue_create("com.apple.libdispatch.test_readsync", NULL);
	assert(dq);

	dispatch_queue_set_width(dq, LONG_MAX);

	dispatch_apply(LAPS, dispatch_get_global_queue(0, 0), ^(size_t idx) {
		dispatch_sync_f(dq, NULL, reader);

		if (idx % INTERVAL) {
			dispatch_barrier_async_f(dq, NULL, writer);
		}
	});

	dispatch_release(dq);

	dispatch_main();
}
