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

// Re-use existing sample code for validation
#import "XAMLCatalog/UIButtonViewController.h"

#include <COMIncludes.h>
#import <WRLHelpers.h>
#import <ErrorHandling.h>
#import <RawBuffer.h>
#import <wrl/client.h>
#import <wrl/implements.h>
#import <wrl/async.h>
#import <wrl/wrappers/corewrappers.h>
#import <windows.foundation.h>
#include <COMIncludes_end.h>

#import "ObjCXamlControls.h"
#import "UWP/WindowsUIXamlControls.h"

// TODO: Consolidate this into a common place so that all tests can use it
static const NSTimeInterval c_testTimeoutInSec = 5;

class UIKitButtonTests {
public:
    BEGIN_TEST_CLASS(UIKitButtonTests)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(UIKitTestsSetup) {
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&UIApplicationDefaultInitialize));
    }

    TEST_METHOD_CLEANUP(UIKitTestsCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST(UIButton, CreateXamlElement) {
        FrameworkHelper::RunOnUIThread([]() {
            // TODO: Switch to UIKit.Xaml projections when they're available.
            Microsoft::WRL::ComPtr<IInspectable> xamlElement(XamlCreateButton());
            ASSERT_TRUE(xamlElement);
        });
    }

    TEST(UIButton, GetXamlElement) {
        FrameworkHelper::RunOnUIThread([]() {
            UIView* view = [[[UIButton alloc] init] autorelease];
            WXFrameworkElement* backingElement = [view xamlElement];
            ASSERT_TRUE(backingElement);

            // TODO: Fix up when UIButton moves fully to XAML
            ASSERT_TRUE([backingElement isKindOfClass:[WXFrameworkElement class]]);
        });
    }

    TEST(UIButton, BackgroundColorChanged) {
        __block UIButtonViewController* buttonVC;
        __block NSCondition* condition = [[[NSCondition alloc] init] autorelease];
        __block WXUIElement* backingElement = nil;

        dispatch_sync(dispatch_get_main_queue(), ^{
            buttonVC = [[UIButtonViewController alloc] init];

            // TODO: Remove this line once we hook up to the root view controller which will trigger the view method
            [buttonVC view];

            // Extract the UIButton example from an existing XAMLCatalog cell in a TableViewController
            NSIndexPath* indexPath = [NSIndexPath indexPathForRow:1 inSection:0];
            UITableViewCell* cell = [buttonVC tableView:buttonVC.tableView cellForRowAtIndexPath:indexPath];
            ASSERT_TRUE(cell);

            // TODO: Formalize a way to extract existing buttons and their states from our test or sample apps
            UILabel* cellLabel = [cell.subviews objectAtIndex:1];
            UIButton* cellButton = [cell.subviews objectAtIndex:2];
            LOG_INFO(@"Cell subview[1] text: %@", cellLabel.text);

            // We have to artificially ref the element since the block needs to keep it around
            backingElement = [cellButton xamlElement];
            [backingElement retain];

            // Register callback and wait for the property changed event to trigger
            int64_t callbackToken = [backingElement
                registerPropertyChangedCallback:[WXCControl backgroundProperty]
                                       callback:^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                                           WUXMSolidColorBrush* solidBrush =
                                               rt_dynamic_cast([WUXMSolidColorBrush class], [sender getValue:dp]);
                                           ASSERT_TRUE(solidBrush);

                                           LOG_INFO("Backing XAML element backgroundColor (rgba): %d,%d,%d,%d",
                                                    [solidBrush.color r],
                                                    [solidBrush.color g],
                                                    [solidBrush.color b],
                                                    [solidBrush.color a]);

                                           CGFloat red, green, blue, alpha;
                                           [cellButton.backgroundColor getRed:&red green:&green blue:&blue alpha:&alpha];
                                           LOG_INFO("UIButton.backgroundColor (rgba): %.2f,%.2f,%.2f,%.2f", red, green, blue, alpha);

                                           // Validate that the change is reflected on the backing XAML control
                                           EXPECT_EQ_MSG(solidBrush.color.r, (int)(red * 255), @"Failed to match red component");
                                           EXPECT_EQ_MSG(solidBrush.color.g, (int)(green * 255), @"Failed to match green component");
                                           EXPECT_EQ_MSG(solidBrush.color.b, (int)(blue * 255), @"Failed to match blue component");
                                           EXPECT_EQ_MSG(solidBrush.color.a, (int)(alpha * 255), @"Failed to match alpha component");

                                           // UIButton's background should be grayColor to match the value set for this button cell in
                                           // XAMLCatalog
                                           EXPECT_EQ_MSG(solidBrush.color.r, 127, @"Failed to match expected value for red component");
                                           EXPECT_EQ_MSG(solidBrush.color.g, 127, @"Failed to match expected value for green component");
                                           EXPECT_EQ_MSG(solidBrush.color.b, 127, @"Failed to match expected value for blue component");
                                           EXPECT_EQ_MSG(solidBrush.color.a, 255, @"Failed to match expected value for alpha component");

                                           // Unregister the callback
                                           [backingElement unregisterPropertyChangedCallback:[WXCControl backgroundProperty]
                                                                                       token:callbackToken];

                                           [condition lock];
                                           [condition signal];
                                           [condition unlock];
                                       }];
        });

        [condition lock];
        ASSERT_TRUE_MSG([condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]],
                        "FAILED: Waiting for property changed event timed out!");
        [condition unlock];

        // Don't leak
        [backingElement release];
        [buttonVC release];
    }

};