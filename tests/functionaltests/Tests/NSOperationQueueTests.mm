//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <TestFramework.h>
#import <Foundation/Foundation.h>
#import "UIViewInternal.h"

class NSOperationQueueTests {
public:
    BEGIN_TEST_CLASS(NSOperationQueueTests)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(NSOperationQueueTestsClassSetup) {
        return FunctionalTestSetupUIApplication();
    }

    TEST_CLASS_CLEANUP(NSOperationQueueTestsClassCleanup) {
        return FunctionalTestCleanupUIApplication();
    }

    TEST_METHOD(MainQueue_CurrentQueue) {
        // This test is to verify the currentQueue is mainQueue on the mainThread
        RunSynchronouslyOnMainThread(^{
            ASSERT_TRUE([NSThread isMainThread]);
            ASSERT_OBJCEQ([NSOperationQueue mainQueue], [NSOperationQueue currentQueue]);
        });
    }
};
