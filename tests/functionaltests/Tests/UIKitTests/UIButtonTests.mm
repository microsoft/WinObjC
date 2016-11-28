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

// YUCKY YUCKY YUCKY
#import "../../../samples/XAMLCatalog/XAMLCatalog/UIButtonViewController.h"

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

TEST(UIButton, XAMLCatalog) {
    __block UIButtonViewController* buttonVC;
    __block NSCondition* condition = [[NSCondition alloc] init];

    dispatch_sync(dispatch_get_main_queue(), ^{
        buttonVC = [[UIButtonViewController alloc] init];
        [buttonVC view];

        // Extract the UIButton example from an existing XAMLCatalog cell in a TableViewController
        NSIndexPath* indexPath = [NSIndexPath indexPathForRow:6 inSection:0];
        UITableViewCell* cell = [buttonVC tableView : buttonVC.tableView cellForRowAtIndexPath:indexPath];
        ASSERT_TRUE(cell);

        UILabel* cellLabel = [cell.subviews objectAtIndex:1];
        LOG_INFO(@"Cell subview[1] text: %@", cellLabel.text);

        __block UIButton* cellButton = [cell.subviews objectAtIndex:2];
        NSString* normalStateTitle = [cellButton titleForState:UIControlStateNormal];
        LOG_INFO(@"Cell subview[2] name: %@", normalStateTitle);

        // Extract the backing XAML element
        __block WXUIElement* backingElement = [cellButton xamlElement];
        ASSERT_TRUE(backingElement);

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
                    ASSERT_TRUE(solidBrush.color.r == (int)(red * 255));
                    ASSERT_TRUE(solidBrush.color.g == (int)(green * 255));
                    ASSERT_TRUE(solidBrush.color.b == (int)(blue * 255));
                    ASSERT_TRUE(solidBrush.color.a == (int)(alpha * 255));
                }
                else {
                    ASSERT_FALSE_MSG(true, "Backing XAML element solid color brush not found");
                }

                // Unregister the callback
                [backingElement unregisterPropertyChangedCallback:[WXCControl backgroundProperty] token:callbackToken];
                [backingElement release];

                [condition signal];
        }];
    });

    // TODO: Investigate the improved conditioned wait for a response.
    if (![condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]]) {
        ASSERT_FALSE_MSG(true, "FAILED: Waiting for property changed event timed out!");
    }

    // Don't leak
    [buttonVC release];
}
