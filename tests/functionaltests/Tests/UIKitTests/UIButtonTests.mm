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

static const NSTimeInterval c_testTimeoutInSec = 5;

TEST(UIButton, CreateXamlElement) {
    // TODO: Switch to UIKit.Xaml projections when they're available.
    Microsoft::WRL::ComPtr<IInspectable> xamlElement(XamlCreateButton());
    ASSERT_TRUE(xamlElement);
}

TEST(UIButton, GetXamlElement) {
    UIView* view = [[[UIButton alloc] init] autorelease];
    WXFrameworkElement* backingElement = [view xamlElement];
    ASSERT_TRUE(backingElement);

    // TODO: Fix up when UIButton moves fully to XAML
    ASSERT_TRUE([backingElement isKindOfClass:[WXFrameworkElement class]]);
}

TEST(UIButton, BackgroundColorChanged) {
    __block UIButtonViewController* buttonVC;
    __block NSCondition* condition = [[[NSCondition alloc] init] autorelease];

    dispatch_sync(dispatch_get_main_queue(), ^{
        buttonVC = [[UIButtonViewController alloc] init];
        [buttonVC view];

        // Extract the UIButton example from an existing XAMLCatalog cell in a TableViewController
        NSIndexPath* indexPath = [NSIndexPath indexPathForRow:1 inSection:0];
        UITableViewCell* cell = [buttonVC tableView : buttonVC.tableView cellForRowAtIndexPath:indexPath];
        ASSERT_TRUE(cell);

        UILabel* cellLabel = [cell.subviews objectAtIndex:1];
        LOG_INFO(@"Cell subview[1] text: %@", cellLabel.text);

        __block UIButton* cellButton = [cell.subviews objectAtIndex:2];
        NSString* normalStateTitle = [cellButton titleForState:UIControlStateNormal];
        LOG_INFO(@"Cell subview[2] name: %@", normalStateTitle);

        // We have to artificially ref the element since the block needs to keep it around
        __block WXUIElement* backingElement = [cellButton xamlElement];
        [backingElement retain];

        // Register callback and wait for the property changed event to trigger
        __block int64_t callbackToken = [backingElement
            registerPropertyChangedCallback:[WXCControl backgroundProperty]
                            callback:^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                WUXMSolidColorBrush* solidBrush = rt_dynamic_cast([WUXMSolidColorBrush class], [sender getValue:dp]);
                if (solidBrush) {
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
                }
                else {
                    EXPECT_FALSE_MSG(solidBrush == nil, "Backing XAML element solid color brush not found");
                }

                // Unregister the callback
                [backingElement unregisterPropertyChangedCallback:[WXCControl backgroundProperty] token:callbackToken];
                [backingElement release];

                [condition lock];
                [condition signal];
                [condition unlock];
        }];
    });

    [condition lock];
    ASSERT_TRUE_MSG([condition waitUntilDate : [NSDate dateWithTimeIntervalSinceNow : c_testTimeoutInSec]],
        "FAILED: Waiting for property changed event timed out!");
    [condition unlock];

    // Don't leak
    [buttonVC release];
}
