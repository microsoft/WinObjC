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
#include <dispatch/dispatch.h>
#include "dispatch_test.h"

@interface TestClass : NSObject
@end

int g_value = 10;
@implementation TestClass

- (instancetype)init {
    self = [super init];
    LOG_INFO("Test class initialized...\n");
    g_value = 20;
    return self;
}
- (void)dealloc {
    LOG_INFO("Test class dealloced...\n");
    g_value = 0;
    [super dealloc];
}

@end

TEST(Dispatch, Autorelease) {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0),
                   ^{
                       [[[TestClass alloc] init] autorelease];
                       test_stop();
                   });
    Sleep(1000); // give some time for clean-up to happen.
    test_block_until_stopped();
    ASSERT_EQ_MSG(g_value, 0, "class was not autoreleased");
}
