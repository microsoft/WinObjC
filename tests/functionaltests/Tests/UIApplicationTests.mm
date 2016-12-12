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
#import <UIKit/UIKit.h>

class UIApplicationTests {
public:
    BEGIN_TEST_CLASS(UIApplicationTests)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(UIApplicationTestsSetup) {
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&UIApplicationDefaultInitialize));
    }

    TEST(UIApplicationTests, OpenURL) {
        // This test is to verify openURL does not block when an invalid URL is used.
        __block NSCondition* condition = [[NSCondition new] autorelease];
        __block BOOL success = YES;
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
            NSString* urlString = @"itms-apps://itunes.com/apps/iplayfulinc";
            [condition lock];
            success = [[UIApplication sharedApplication] openURL:[NSURL URLWithString:urlString]];
            [condition signal];
            [condition unlock];
        });

        [condition lock];
        ASSERT_TRUE(!success || [condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:2]]);
        [condition unlock];
    }
};
