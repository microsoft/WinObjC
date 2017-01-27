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

using namespace UXTestAPI;

TEST(UIButton, CreateXamlElement) {
    // TODO: Switch to UIKit.Xaml projections when they're available.
    Microsoft::WRL::ComPtr<IInspectable> xamlElement(XamlCreateButton());
    ASSERT_TRUE(xamlElement);
}

TEST(UIButton, GetXamlElement) {
    UIView* view = [[[UIButton alloc] init] autorelease];
    WXFrameworkElement* backingElement = [view xamlElement];
    ASSERT_OBJCNE(backingElement, nil);

    // TODO: Fix up when UIButton moves fully to XAML
    ASSERT_TRUE([backingElement isKindOfClass:[WXFrameworkElement class]]);
}

TEST(UIButton, TitleColorChanged) {
    __block auto uxEvent = UXEvent::CreateManual();
    __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();

    UIButtonWithControlsViewController* buttonVC = [[UIButtonWithControlsViewController alloc] init];
    UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

    dispatch_async(dispatch_get_main_queue(), ^{
        // Extract UIButton.titleLabel control to verify its visual state
        WXFrameworkElement* titleElement = [buttonVC.button.titleLabel xamlElement];
        ASSERT_OBJCNE(titleElement, nil);

        // Register RAII event subscription handler
        xamlSubscriber->Set(titleElement, [WXCTextBlock foregroundProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
            // Extract the foreground color from the XAML object
            WUXMSolidColorBrush* solidBrush = rt_dynamic_cast([WUXMSolidColorBrush class], [sender getValue:dp]);

            // Validation
            UIColor* titleColorNormal = [buttonVC.button titleColorForState:UIControlStateNormal];
            EXPECT_TRUE_MSG(UXTestAPI::IsRGBAEqual(solidBrush, titleColorNormal), @"Failed to match XAML- and UIButton title color");
            EXPECT_OBJCEQ_MSG(titleColorNormal, [buttonVC titleColorNormal], @"Failed to match expected color");

            uxEvent->Set();
        });

        // Action - validate this action takes effect on the control
        [buttonVC sliderTitleColorNormal].value = 150.0f;
    });

    ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event timed out!");
}

TEST(UIButton, TextChanged) {
    __block auto uxEvent = UXEvent::CreateManual();
    __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();

    NSString* expectedString = @"Functional testing";

    UIButtonWithControlsViewController* buttonVC = [[UIButtonWithControlsViewController alloc] init];
    UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

    dispatch_async(dispatch_get_main_queue(), ^{
        // Extract UIButton.titleLabel control to verify its visual state
        WXFrameworkElement* titleElement = [buttonVC.button.titleLabel xamlElement];
        ASSERT_TRUE(titleElement);

        // Register RAII event subscription handler
        xamlSubscriber->Set(titleElement, [WXCTextBlock textProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
            NSString* text = UXTestAPI::NSStringFromPropertyValue([sender getValue:dp]);
            NSString* textNormal = [buttonVC.button titleForState:UIControlStateNormal];

            // Validation
            EXPECT_OBJCEQ_MSG(text, textNormal, @"Failed to match strings in XAML and UIButton");
            EXPECT_OBJCEQ_MSG(text, expectedString, @"Failed to match expected string");

            uxEvent->Set();
        });

        // Action - validate this action takes effect on the control
        [buttonVC textTitleNormal].text = expectedString;
    });

    ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event timed out!");
}
