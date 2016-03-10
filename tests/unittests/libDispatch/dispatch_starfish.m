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
#include <windows.h>
#include <dispatch/dispatch.h>
#include "dispatch_test.h"

#if HAVE_TARGETCONDITIONALS_H
#include <TargetConditionals.h>
#endif

#define COUNT 300ul
#define LAPS 5ul

static dispatch_queue_t queues[COUNT];
static size_t lap_count_down = LAPS;
static size_t count_down;
static size_t total_run_count;
static uint64_t start;
static bool test_completed;

static void do_test(void);

#define _dispatch_time_mach2nano(x) ((x))
#define _dispatch_absolute_time() GetTickCount64() * 1000000LL

void test_done(void* arg __attribute__((unused))) {
    if (!test_completed) {
        test_completed = true;
        Sleep(1);
        test_stop();
    }
}

static void collect(void* context __attribute__((unused))) {
    uint64_t delta;
    size_t i;

    ++total_run_count;

    if (--count_down) {
        return;
    }

    delta = _dispatch_absolute_time() - start;
    delta = _dispatch_time_mach2nano(delta);

    LOG_INFO("lap: %lu", lap_count_down);
    LOG_INFO("count: %lu", COUNT);
    LOG_INFO("delta: %lu ms\n", (uintmax_t)delta / NSEC_PER_MSEC);

    for (i = 0; i < COUNT; i++) {
        dispatch_release(queues[i]);
    }

    if (--lap_count_down) {
        return do_test();
    }

    // give the threads some time to settle before test_stop() runs "leaks"
    // ...also note, this is a total cheat.   dispatch_after lets this
    // thread go idle, so dispatch cleans up the continuations cache.
    // Doign the "old style" sleep left that stuff around and leaks
    // took a LONG TIME to complete.   Long enough that the test harness
    // decided to kill us.
    dispatch_after_f(dispatch_time(DISPATCH_TIME_NOW, 2 * NSEC_PER_SEC), dispatch_get_main_queue(), NULL, test_done);
}

static void pong(void* context) {
    dispatch_queue_t this_q = reinterpret_cast<dispatch_queue_t>(context);
    size_t replies = reinterpret_cast<size_t>(dispatch_get_context(this_q));

    dispatch_set_context(this_q, reinterpret_cast<void*>(--replies));
    if (!replies) {
        // printf("collect from: %s\n", dispatch_queue_get_label(dispatch_get_current_queue()));
        dispatch_async_f(dispatch_get_main_queue(), NULL, collect);
    }
}

static void ping(void* context) {
    dispatch_queue_t reply_q = reinterpret_cast<dispatch_queue_t>(context);

    dispatch_async_f(reply_q, reply_q, pong);
}

static void start_node(void* context) {
    dispatch_queue_t this_q = reinterpret_cast<dispatch_queue_t>(context);
    size_t i;

    dispatch_set_context(this_q, reinterpret_cast<void*>(COUNT));

    for (i = 0; i < COUNT; i++) {
        dispatch_async_f(queues[i], this_q, ping);
    }
}

void do_test(void) {
    size_t i;

    count_down = COUNT;

    start = _dispatch_absolute_time();

    for (i = 0; i < COUNT; i++) {
        char buf[1000];
        _snprintf(buf, sizeof(buf), "com.example.starfish-node#%ld", i);
        queues[i] = dispatch_queue_create(buf, NULL);
        dispatch_suspend(queues[i]);
    }

    for (i = 0; i < COUNT; i++) {
        dispatch_async_f(queues[i], queues[i], start_node);
    }

    for (i = 0; i < COUNT; i++) {
        dispatch_resume(queues[i]);
    }
}

TEST(Dispatch, DispatchStarfish) {
    test_start("Dispatch Starfish");

    do_test();

    // Test watchdog to make sure the test does not run for more than 15 seconds if something is hung.
    dispatch_after_f(dispatch_time(DISPATCH_TIME_NOW, 15 * NSEC_PER_SEC), dispatch_get_main_queue(), NULL, test_done);
    test_block_until_stopped();

    test_long("Total test run count", total_run_count, COUNT * LAPS);
}
