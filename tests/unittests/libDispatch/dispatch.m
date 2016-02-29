//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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
#include "dispatch_test.h"
#import <UIKit/UIKit.h>
#include <dispatch/dispatch.h>

static int ranAsyncBlock = 0;

TEST(Dispatch, DispatchTest) {
    test_start("Dispatch Test");
    dispatch_async(dispatch_get_main_queue(),
                   ^void() {
                       ASSERT_TRUE([NSThread isMainThread]);
                       ranAsyncBlock++;
                       LOG_INFO("async1 method called.");
                       dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 1 * NSEC_PER_SEC),
                                      dispatch_get_main_queue(),
                                      ^void() {
                                          ranAsyncBlock++;
                                          LOG_INFO("async timer method called\n");
                                          dispatch_async(dispatch_get_main_queue(),
                                                         ^void() {
                                                             ranAsyncBlock++;
                                                             LOG_INFO("async shutdown method called.");
                                                             test_stop();
                                                         });
                                      });
                   });

    test_block_until_stopped();
    ASSERT_EQ_MSG(ranAsyncBlock, 3, "Main queue was NOT drained from main runloop.");
}