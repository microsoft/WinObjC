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

@interface UIDeallocTestButton : UIButton {
    std::shared_ptr<UXEvent> _event;
}
@end

@implementation UIDeallocTestButton

- (void)setDeallocEvent:(std::shared_ptr<UXEvent>)event {
    _event = event;
}

- (void)dealloc {
    _event->Set();
    [super dealloc];
}
@end

class UIButtonTests {
public:
    BEGIN_TEST_CLASS(UIButtonTests)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(UIButtonTestsClassSetup) {
        return FunctionalTestSetupUIApplication();
    }

    TEST_CLASS_CLEANUP(UIButtonTestsClassCleanup) {
        return FunctionalTestCleanupUIApplication();
    }

    TEST_METHOD(UIButton_CreateXamlElement) {
        FrameworkHelper::RunOnUIThread([]() {
            // TODO: Switch to UIKit.Xaml projections when they're available.
            Microsoft::WRL::ComPtr<IInspectable> xamlElement;
            XamlCreateButton(&xamlElement);
            ASSERT_TRUE(xamlElement);
        });
    }

    TEST_METHOD(UIButton_GetXamlElement) {
        FrameworkHelper::RunOnUIThread([]() {
            UIView* view = [[[UIButton alloc] init] autorelease];
            WXFrameworkElement* backingElement = [view xamlElement];
            ASSERT_OBJCNE(backingElement, nil);

            // TODO: Fix up when UIButton moves fully to XAML
            ASSERT_TRUE([backingElement isKindOfClass:[WXFrameworkElement class]]);
        });
    }

    TEST_METHOD(UIButton_CheckForLeaks) {
        Microsoft::WRL::WeakRef weakXamlElement;
        {
            StrongId<UIButtonWithControlsViewController> buttonVC;
            buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
            UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

            __block UIDeallocTestButton* testButton = nil;
            __block auto event = UXEvent::CreateAuto();

            // Create and render the button
            dispatch_sync(dispatch_get_main_queue(), ^{
                testButton = [[UIDeallocTestButton alloc] initWithFrame:CGRectMake(100, 100, 100, 100)];
                testButton.backgroundColor = [UIColor redColor];
                [testButton setDeallocEvent:event];
                [[buttonVC view] addSubview:testButton];
            });

            // Grab a weak reference to the backing Xaml element
            Microsoft::WRL::ComPtr<IInspectable> xamlElement([[testButton xamlElement] comObj]);
            ASSERT_TRUE_MSG(SUCCEEDED(xamlElement.AsWeak(&weakXamlElement)),
                            "Failed to acquire a weak reference to the backing Xaml element.");
            xamlElement = nullptr;

            // Free the button
            dispatch_sync(dispatch_get_main_queue(), ^{
                // Nil out testButton and remove it from its superview
                [testButton removeFromSuperview];
                [testButton release];
                testButton = nil;
            });

            // Validate that dealloc was called
            ASSERT_TRUE_MSG(event->Wait(c_testTimeoutInSec), "FAILED: Waiting for dealloc call failed!");
        }

        // Unfortunately we have to wait a bit for the button to actually finish deallocation
        [NSThread sleepForTimeInterval:.25];

        // Validate that we can no longer acquire a strong reference to the UIButton's backing Xaml element
        Microsoft::WRL::ComPtr<IInspectable> xamlElement;
        weakXamlElement.As(&xamlElement);
        ASSERT_EQ_MSG(xamlElement.Get(), nullptr, "Unexpectedly able to reacquire a strong reference to the backing Xaml element.");
    }

    TEST_METHOD(UIButton_TitleColorChanged) {
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

    TEST_METHOD(UIButton_TextChanged) {
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
};