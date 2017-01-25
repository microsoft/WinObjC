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
#import "FunctionalTestHelpers.h"
#import "UXTestHelpers.h"

// Re-use existing sample code for validation
#import "UIKitControls/UIButtonViewController.h"
#import "UIKitControls/UIButtonWithControlsViewController.h"

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

TEST(UIButton, TitleColorChanged) {
    __block BOOL signaled = NO;
    __block NSCondition* condition = [[NSCondition alloc] init];
    __block auto xamlSubscriber = std::make_shared<UXTestAPI::XamlEventSubscription>();

    UIButtonWithControlsViewController* buttonVC = [[UIButtonWithControlsViewController alloc] init];
    UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

    dispatch_async(dispatch_get_main_queue(), ^{
        // Extract UIButton.titleLabel control to verify its visual state
        WXFrameworkElement* titleElement = [buttonVC.button.titleLabel xamlElement];
        ASSERT_TRUE(titleElement);

        // Register RAII event subscription handler
        xamlSubscriber->Set(titleElement, [WXCTextBlock foregroundProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
            // Extract the foreground color from the XAML object
            WUXMSolidColorBrush* solidBrush = rt_dynamic_cast([WUXMSolidColorBrush class], [sender getValue:dp]);
            LOG_INFO("XAML element color (rgba): %d,%d,%d,%d",
                     [solidBrush.color r],
                     [solidBrush.color g],
                     [solidBrush.color b],
                     [solidBrush.color a]);

            // Extract the title color for the normal state
            UIColor* titleColorNormal = [buttonVC.button titleColorForState:UIControlStateNormal];

            CGFloat red, green, blue, alpha;
            [titleColorNormal getRed:&red green:&green blue:&blue alpha:&alpha];
            LOG_INFO("UIButton.titleColorForState:normal (rgba): %.2f,%.2f,%.2f,%.2f", red, green, blue, alpha);

            // Validate that the change is reflected on the backing XAML control
            EXPECT_EQ_MSG(solidBrush.color.r, (int)(red * 255), @"Failed to match red component");
            EXPECT_EQ_MSG(solidBrush.color.g, (int)(green * 255), @"Failed to match green component");
            EXPECT_EQ_MSG(solidBrush.color.b, (int)(blue * 255), @"Failed to match blue component");
            EXPECT_EQ_MSG(solidBrush.color.a, (int)(alpha * 255), @"Failed to match alpha component");

            // Ensure that the XAML color values match the viewcontroller property
            CGFloat VCred, VCgreen, VCblue, VCalpha;
            [[buttonVC titleColorNormal] getRed:&VCred green:&VCgreen blue:&VCblue alpha:&VCalpha];
            EXPECT_EQ_MSG(solidBrush.color.r, (int)(red * 255), @"Failed to match red component on the VC");
            EXPECT_EQ_MSG(solidBrush.color.g, (int)(green * 255), @"Failed to match green component on the VC");
            EXPECT_EQ_MSG(solidBrush.color.b, (int)(blue * 255), @"Failed to match blue component on the VC");
            EXPECT_EQ_MSG(solidBrush.color.a, (int)(alpha * 255), @"Failed to match alpha component on the VC");

            [condition lock];
            signaled = YES;
            [condition signal];
            [condition unlock];
        });

        // Action - validate this action takes effect on the control
        [buttonVC sliderTitleColorNormal].value = 150.0f;
    });

    [condition lock];
    ASSERT_TRUE_MSG(signaled || [condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]],
                    "FAILED: Waiting for property changed event timed out!");
    [condition unlock];
}

TEST(UIButton, TextChanged) {
    __block BOOL signaled = NO;
    __block NSCondition* condition = [[NSCondition alloc] init];
    __block auto xamlSubscriber = std::make_shared<UXTestAPI::XamlEventSubscription>();

    __block NSString* expectedString = @"Functional testing";

    UIButtonWithControlsViewController* buttonVC = [[UIButtonWithControlsViewController alloc] init];
    UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

    dispatch_async(dispatch_get_main_queue(), ^{
        // Extract UIButton.titleLabel control to verify its visual state
        WXFrameworkElement* titleElement = [buttonVC.button.titleLabel xamlElement];
        ASSERT_TRUE(titleElement);

        // Register RAII event subscription handler
        xamlSubscriber->Set(titleElement, [WXCTextBlock textProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
            // Extract the text from the XAML object
            NSString* text = UXTestAPI::NSStringFromPropertyValue([sender getValue:dp]);
            LOG_INFO("TextBlock text: %@", text);

            // Extract the text for the normal state
            NSString* textNormal = [buttonVC.button titleForState:UIControlStateNormal];
            LOG_INFO("UIButton title - normal: %@", textNormal);

            // Validate that the change is reflected on the backing XAML control
            EXPECT_OBJCEQ_MSG(text, textNormal, @"Failed to match strings in XAML and UIButton");
            EXPECT_OBJCEQ_MSG(text, expectedString, @"Failed to match expected string");

            [condition lock];
            signaled = YES;
            [condition signal];
            [condition unlock];
        });

        // Action - validate this action takes effect on the control
        [buttonVC textTitleNormal].text = expectedString;
    });

    [condition lock];
    ASSERT_TRUE_MSG(signaled || [condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]],
                    "FAILED: Waiting for property changed event timed out!");
    [condition unlock];
}
