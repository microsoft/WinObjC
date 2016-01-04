//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// Copyright (c) 2008-2009 Apple Inc. All rights reserved.
//
// @APPLE_APACHE_LICENSE_HEADER_START@
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// @APPLE_APACHE_LICENSE_HEADER_END@
//
//******************************************************************************

#include <TestFramework.h>
#import <UIKit/UIKit.h>
#include <dispatch/dispatch.h>
#include "dispatch_test.h"

#if HAVE_TARGETCONDITIONALS_H
#include <TargetConditionals.h>
#endif

int done = 0;

#define BLOCKS 128
#define PRIORITIES 3

#if TARGET_OS_EMBEDDED
#define LOOP_COUNT 2000000
#else
#define LOOP_COUNT 100000000
#endif

char* labels[PRIORITIES] = { (char*)"LOW", (char*) "DEFAULT", (char*) "HIGH" };
int priorities[PRIORITIES] = { DISPATCH_QUEUE_PRIORITY_LOW, DISPATCH_QUEUE_PRIORITY_DEFAULT, DISPATCH_QUEUE_PRIORITY_HIGH };

union {
    long count;
    char padding[64];
} counts[PRIORITIES];

#define ITERATIONS (long)(PRIORITIES * BLOCKS * 0.50)
long iterations = ITERATIONS;

static void histogram(void) {
    long maxcount = BLOCKS;
    long sc[PRIORITIES];

    long total = 0;

    long x, y;
    for (y = 0; y < PRIORITIES; ++y) {
        sc[y] = counts[y].count;
    }

    for (y = 0; y < PRIORITIES; ++y) {
        LOG_INFO("%s: %ld\n", labels[y], sc[y]);
        total += sc[y];

        double fraction = (double)sc[y] / (double)maxcount;
        double value = fraction * (double)80;
        for (x = 0; x < 80; ++x) {
            printf("%s", (value > x) ? "*" : " ");
        }
        printf("\n");
    }

    test_long("blocks completed", total, ITERATIONS);
    test_long_less_than("high priority precedence", (long)sc[0], (long)sc[2]);
}

void cpubusy(void* context) {
    long* count = (long*)context;
    long iterdone;

    long idx;
    for (idx = 0; idx < LOOP_COUNT; ++idx) {
        if (done)
            break;
    }

    if ((iterdone = __sync_sub_and_fetch(&iterations, 1)) == 0) {
        __sync_add_and_fetch(&done, 1);
        __sync_add_and_fetch(count, 1);
        histogram();
        test_stop();

    } else if (iterdone > 0) {
        __sync_add_and_fetch(count, 1);
    }
}

void submit_work(dispatch_queue_t queue, void* context) {
    int i;

    for (i = 0; i < BLOCKS; ++i) {
        dispatch_async_f(queue, context, cpubusy);
    }

#if USE_SET_TARGET_QUEUE
    dispatch_release(queue);
#endif
}

TEST(Dispatch, DispatchPriority) {
    dispatch_queue_t q[PRIORITIES];
    int i;

#if USE_SET_TARGET_QUEUE
    test_start("Dispatch Priority (Set Target Queue)");
    for (i = 0; i < PRIORITIES; i++) {
        q[i] = dispatch_queue_create(labels[i], NULL);
        test_ptr_notnull("q[i]", q[i]);
        assert(q[i]);
        dispatch_set_target_queue(q[i], dispatch_get_global_queue(priorities[i], 0));
        dispatch_queue_set_width(q[i], DISPATCH_QUEUE_WIDTH_MAX_LOGICAL_CPUS);
    }
#else
    test_start("Dispatch Priority");
    for (i = 0; i < PRIORITIES; i++) {
        q[i] = dispatch_get_global_queue(priorities[i], 0);
    }
#endif

    for (i = 0; i < PRIORITIES; i++) {
        submit_work(q[i], &counts[i].count);
    }

    UIApplicationMainLoop();
}
