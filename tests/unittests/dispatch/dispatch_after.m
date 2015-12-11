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
#include <Block.h>
#include <windows.h>

void done(void* arg __attribute__((unused))) {
    Sleep(1);
    test_stop();
}

TEST(Dispatch, DispatchAfter) {
    __block dispatch_time_t time_a_min, time_a, time_a_max;
    __block dispatch_time_t time_b_min, time_b, time_b_max;
    __block dispatch_time_t time_c_min, time_c, time_c_max;

    test_start("Dispatch After");

    dispatch_async(dispatch_get_main_queue(),
                   ^{
                       time_a_min = dispatch_time(0, 5.5 * NSEC_PER_SEC);
                       time_a = dispatch_time(0, 6 * NSEC_PER_SEC);
                       time_a_max = dispatch_time(0, 6.5 * NSEC_PER_SEC);
                       dispatch_after(time_a,
                                      dispatch_get_current_queue(),
                                      ^{
                                          dispatch_time_t now_a = dispatch_time(0, 0);
                                          test_long_less_than("can't finish faster than 5.5s", 0, now_a - time_a_min);
                                          test_long_less_than("must finish faster than  6.5s", 0, time_a_max - now_a);

                                          time_b_min = dispatch_time(0, 1.5 * NSEC_PER_SEC);
                                          time_b = dispatch_time(0, 2 * NSEC_PER_SEC);
                                          time_b_max = dispatch_time(0, 2.5 * NSEC_PER_SEC);
                                          dispatch_after(time_b,
                                                         dispatch_get_current_queue(),
                                                         ^{
                                                             dispatch_time_t now_b = dispatch_time(0, 0);
                                                             test_long_less_than("can't finish faster than 1.5s", 0, now_b - time_b_min);
                                                             test_long_less_than("must finish faster than  2.5s", 0, time_b_max - now_b);

                                                             time_c_min = dispatch_time(0, 0 * NSEC_PER_SEC);
                                                             time_c = dispatch_time(0, 0 * NSEC_PER_SEC);
                                                             time_c_max = dispatch_time(0, .5 * NSEC_PER_SEC);
                                                             dispatch_after(time_c,
                                                                            dispatch_get_current_queue(),
                                                                            ^{
                                                                                dispatch_time_t now_c = dispatch_time(0, 0);
                                                                                test_long_less_than("can't finish faster than 0s",
                                                                                                    0,
                                                                                                    now_c - time_c_min);
                                                                                test_long_less_than("must finish faster than .5s",
                                                                                                    0,
                                                                                                    time_c_max - now_c);

                                                                                dispatch_async_f(dispatch_get_current_queue(), NULL, done);
                                                                            });
                                                         });
                                      });
                   });

    UIApplicationMainLoop();
}
