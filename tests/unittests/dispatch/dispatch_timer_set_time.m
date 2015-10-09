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

#include "gtest-api.h"
#import <Foundation/Foundation.h>
#import <mach/mach_time.h>
#import <UIKit/UIKit.h>
#include <windows.h>
#include <dispatch/dispatch.h>
#include "dispatch_test.h"
#include <crtdbg.h>

static const unsigned __int64 intervals_per_second      = 10000000ULL;
static const unsigned __int64 microseconds_per_second   = 1000000ULL;
static const unsigned __int64 intervals_per_microsecond = 10ULL;
static const unsigned __int64 intervals_since_epoch     = 116444736000000000ULL;
static const unsigned __int64 microseconds_since_epoch  = 11644473600000000ULL;

int gettimeofday(struct timeval* tp, void* tzp) {
    FILETIME file_time;
    ULARGE_INTEGER ularge;

    GetSystemTimeAsFileTime(&file_time);
    ularge.LowPart = file_time.dwLowDateTime;
    ularge.HighPart = file_time.dwHighDateTime;
    ularge.QuadPart -= intervals_since_epoch;
    ularge.QuadPart /= intervals_per_microsecond;
    tp->tv_sec = (long) (ularge.QuadPart / microseconds_per_second);
    tp->tv_usec = (long) (ularge.QuadPart % microseconds_per_second);

    return 0;
}

struct timeval start_time;
dispatch_source_t timer;
int i = 0;

static void cancel_handler(void* context) {
    struct timeval end_time;
    gettimeofday(&end_time, NULL);
    // Make sure we actually managed to adjust the interval
    // duration.  Seven one second ticks would blow past
    // this.
    test_long_less_than("total duration", end_time.tv_sec - start_time.tv_sec, 3);
    test_ptr_notnull("finalizer ran", timer);
    test_stop();
}

static void event_handler(void* context) {
    ++i;
    fprintf(stderr, "%d\n", i);
    if (i >= 7) {
        dispatch_source_cancel(timer);
    } else if (i == 1) {
        dispatch_source_set_timer(timer, 0, 100, 0);
    }
}

TEST(Dispatch, DispatchSettime) {
    dispatch_queue_t main_q;
    test_start("Dispatch Update Timer");
    main_q = dispatch_get_main_queue();
    ASSERT_TRUE([NSThread isMainThread]);
    timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, main_q);
    dispatch_source_set_timer(timer, 1000000000ull, 0, 0);
    dispatch_source_set_cancel_handler_f(timer, cancel_handler);
    dispatch_source_set_event_handler_f(timer, event_handler);
    test_ptr_notnull("dispatch_source_timer_create", timer);

    gettimeofday(&start_time, NULL);
    dispatch_resume(as_do(timer));
        
    UIApplicationMainLoop();
}
