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
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#include <dispatch/dispatch.h>
#include "dispatch_test.h"

#define LAPS 10000

TEST(Dispatch, DispatchSema) {
    static size_t total;
    dispatch_semaphore_t dsema;

    test_start("Dispatch Semaphore");

    dsema = dispatch_semaphore_create(1);
    assert(dsema);

    dispatch_apply(LAPS,
                   dispatch_get_global_queue(0, 0),
                   ^(size_t idx __attribute__((unused))) {
                       dispatch_semaphore_wait(dsema, DISPATCH_TIME_FOREVER);
                       total++;
                       dispatch_semaphore_signal(dsema);
                   });

    dispatch_release(dsema);

    test_long("count", total, LAPS);

    test_stop();
}

TEST(Dispatch, DispatchSemaphoreWait) {
    dispatch_time_t time_a_min, time_a, time_a_max, now_a;

    test_start("Dispatch Semaphore Wait");

    dispatch_semaphore_t dsema = dispatch_semaphore_create(0);

    time_a_min = dispatch_time(DISPATCH_TIME_NOW, 2.5 * NSEC_PER_SEC);
    time_a = dispatch_time(DISPATCH_TIME_NOW, 3 * NSEC_PER_SEC);
    time_a_max = dispatch_time(DISPATCH_TIME_NOW, 3.5 * NSEC_PER_SEC);
    long ret = dispatch_semaphore_wait(dsema, time_a);
    now_a = dispatch_time(DISPATCH_TIME_NOW, 0);
    ASSERT_TRUE_MSG((ret != 0), "dispatch_semaphore_wait should have timed out!");
    test_long_less_than("Can't finish faster than 2.5s", 0, now_a - time_a_min);
    test_long_less_than("Must finish faster than 3.5s", 0, time_a_max - now_a);

    test_stop();
}