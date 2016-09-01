//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#include <TestFramework.h>
#import <Starboard/SmartTypes.h>
#import <Foundation/Foundation.h>
#import "UWP/WindowsUICore.h"

static const NSTimeInterval c_testTimeoutInSec = 5;

TEST(Projection, WUCCoreDispatcherSanity) {
    LOG_INFO("Projection CoreDispatcher Sanity Test: ");

    ASSERT_FALSE_MSG([NSThread isMainThread], "Failed: Test cannot run on Main thread")

    __block dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);

    WUCDispatchedHandler dispatchedHandler = ^() {
        dispatch_semaphore_signal(semaphore);
    };

    __block StrongId<WUCCoreDispatcher> coreDispatcher;

    // Get the dispatcher for the main thread.
    // RunAsync needs to be called on the dispatcher for main thread.
    dispatch_sync(dispatch_get_main_queue(),
                  ^{
                      coreDispatcher = [[WUCCoreWindow getForCurrentThread] dispatcher];
                  });

    [coreDispatcher runAsync:WUCCoreDispatcherPriorityNormal agileCallback:dispatchedHandler];
    long result = dispatch_semaphore_wait(semaphore, dispatch_time(DISPATCH_TIME_NOW, (int64_t)(c_testTimeoutInSec * NSEC_PER_SEC)));
    dispatch_release(semaphore);

    ASSERT_EQ_MSG(0, result, "FAILED: Test timed out, handler not called\n");
}