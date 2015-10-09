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

#include "gtest-api.h"
#import <UIKit/UIKit.h>
#include <dispatch/dispatch.h>

UIKIT_EXPORT void UIShutdown();

static int ranAsyncBlock = 0;

TEST(Dispatch, DispatchTest) {
     dispatch_async(dispatch_get_main_queue(), ^void() {
        ASSERT_TRUE([NSThread isMainThread]);
        ranAsyncBlock++;
        LOG_INFO("async1 method called.");
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 1 * NSEC_PER_SEC), dispatch_get_main_queue(), ^void() {
            ranAsyncBlock++;
            LOG_INFO("async timer method called\n");
            dispatch_async(dispatch_get_main_queue(), ^void() {
                ranAsyncBlock++;
                LOG_INFO("async shutdown method called.");
                UIShutdown();
            });
        });
    });
    
    UIApplicationMainLoop();
    ASSERT_EQ_MSG(ranAsyncBlock, 3, "Main queue was NOT drained from main runloop.");
}