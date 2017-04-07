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
#import "UILabelInternal.h"

// Re-use existing sample code for validation
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

    TEST_METHOD(UIButton_CreateButtonWithDefaultInit) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC defaultButton];

        WXCControl* xamlControl = rt_dynamic_cast([WXCControl class], [buttonToTest xamlElement]);
        ASSERT_OBJCNE(xamlControl, nil);

        // Extract UIButton.titleLabel control to verify its visual state
        WXFrameworkElement* titleLabelXamlElement = [buttonToTest.titleLabel _getXamlTextBlock];
        ASSERT_OBJCNE(titleLabelXamlElement, nil);

        WXCTextBlock* textBlock = rt_dynamic_cast([WXCTextBlock class], titleLabelXamlElement);
        ASSERT_OBJCNE(textBlock, nil);

        // buttonType
        ASSERT_EQ(buttonToTest.buttonType, UIButtonTypeCustom);

        // Background color
        dispatch_sync(dispatch_get_main_queue(), ^{
            WUXMSolidColorBrush* solidBackgroundBrush = rt_dynamic_cast([WUXMSolidColorBrush class], xamlControl.background);
            UIColor* expectedBackgroundColor = [UIColor colorWithRed:1.0f green:1.0f blue:1.0f alpha:0.0f];
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedBackgroundColor));
        });

        // Title color
        __block auto uxEvent = UXEvent::CreateManual();
        __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();

        dispatch_sync(dispatch_get_main_queue(), ^{
            UIColor* expectedColor = [UIColor whiteColor];

            // Register RAII event subscription handler
            xamlSubscriber->Set(textBlock, [WXCTextBlock foregroundProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                WUXMSolidColorBrush* solidBrush = rt_dynamic_cast([WUXMSolidColorBrush class], [sender getValue:dp]);

                // Validation
                if (UXTestAPI::IsRGBAEqual(solidBrush, expectedColor)) {
                    uxEvent->Set();
                }
            });

            // Check the current state of the foreground brush in case it is already set which means the property callback will not get triggered
            WUXMSolidColorBrush* solidBrush = rt_dynamic_cast([WUXMSolidColorBrush class], textBlock.foreground);
            if (UXTestAPI::IsRGBAEqual(solidBrush, expectedColor)) {
                uxEvent->Set();
            }
        });

        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event state timed out!");

        // adjustImageWhen* is YES by default
        EXPECT_TRUE(buttonToTest.adjustsImageWhenHighlighted);
        EXPECT_TRUE(buttonToTest.adjustsImageWhenDisabled);

        // Title
        EXPECT_OBJCEQ(buttonToTest.currentTitle, nil);
    }

    TEST_METHOD(UIButton_CreateButtonWithTypeCustom) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC customButton];

        WXCControl* xamlControl = rt_dynamic_cast([WXCControl class], [buttonToTest xamlElement]);
        ASSERT_OBJCNE(xamlControl, nil);

        // Extract UIButton.titleLabel control to verify its visual state
        WXFrameworkElement* titleLabelXamlElement = [buttonToTest.titleLabel _getXamlTextBlock];
        ASSERT_OBJCNE(titleLabelXamlElement, nil);

        WXCTextBlock* textBlock = rt_dynamic_cast([WXCTextBlock class], titleLabelXamlElement);
        ASSERT_OBJCNE(textBlock, nil);

        // buttonType
        ASSERT_EQ(buttonToTest.buttonType, UIButtonTypeCustom);

        // Background color
        dispatch_sync(dispatch_get_main_queue(), ^{
            WUXMSolidColorBrush* solidBackgroundBrush = rt_dynamic_cast([WUXMSolidColorBrush class], xamlControl.background);
            UIColor* expectedBackgroundColor = [UIColor colorWithRed:1.0f green:1.0f blue:1.0f alpha:0.0f];
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedBackgroundColor));
        });

        // Title color
        __block auto uxEvent = UXEvent::CreateManual();
        __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();

        dispatch_sync(dispatch_get_main_queue(), ^{
            UIColor* expectedColor = [UIColor whiteColor];

            // Register RAII event subscription handler
            xamlSubscriber->Set(textBlock, [WXCTextBlock foregroundProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                WUXMSolidColorBrush* solidBrush = rt_dynamic_cast([WUXMSolidColorBrush class], [sender getValue:dp]);

                // Validation
                if (UXTestAPI::IsRGBAEqual(solidBrush, expectedColor)) {
                    uxEvent->Set();
                }
            });

            // Check the current state of the foreground brush in case it is already set which means the property callback will not get triggered
            WUXMSolidColorBrush* solidBrush = rt_dynamic_cast([WUXMSolidColorBrush class], textBlock.foreground);
            if (UXTestAPI::IsRGBAEqual(solidBrush, expectedColor)) {
                uxEvent->Set();
            }
        });

        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event state timed out!");

        // adjustImageWhen* is YES by default
        EXPECT_TRUE(buttonToTest.adjustsImageWhenHighlighted);
        EXPECT_TRUE(buttonToTest.adjustsImageWhenDisabled);

        // Title
        EXPECT_OBJCEQ(buttonToTest.currentTitle, nil);
    }

    TEST_METHOD(UIButton_CreateButtonWithTypeSystem) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        // Change to the UIButtonTypeSystem
        UIButton* buttonToTest = [buttonVC systemButton];

        WXCControl* xamlControl = rt_dynamic_cast([WXCControl class], [buttonToTest xamlElement]);
        ASSERT_OBJCNE(xamlControl, nil);

        // Extract UIButton.titleLabel control to verify its visual state
        WXFrameworkElement* titleLabelXamlElement = [buttonToTest.titleLabel _getXamlTextBlock];
        ASSERT_OBJCNE(titleLabelXamlElement, nil);

        WXCTextBlock* textBlock = rt_dynamic_cast([WXCTextBlock class], titleLabelXamlElement);
        ASSERT_OBJCNE(textBlock, nil);

        // buttonType
        ASSERT_EQ(buttonToTest.buttonType, UIButtonTypeSystem);

        // Background color
        dispatch_sync(dispatch_get_main_queue(), ^{
            WUXMSolidColorBrush* solidBackgroundBrush = rt_dynamic_cast([WUXMSolidColorBrush class], xamlControl.background);
            UIColor* expectedBackgroundColor = [UIColor colorWithRed:1.0f green:1.0f blue:1.0f alpha:0.0f];
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedBackgroundColor));
        });

        // Title color
        __block auto uxEvent = UXEvent::CreateManual();
        __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();

        dispatch_sync(dispatch_get_main_queue(), ^{
            UIColor* expectedColor = [UIColor colorWithRed:0.0f green:0.47843137f blue:1.0f alpha:1.0f];

            // Register RAII event subscription handler
            xamlSubscriber->Set(textBlock, [WXCTextBlock foregroundProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                WUXMSolidColorBrush* solidBrush = rt_dynamic_cast([WUXMSolidColorBrush class], [sender getValue:dp]);

                // Validation
                if (UXTestAPI::IsRGBAEqual(solidBrush, expectedColor)) {
                    uxEvent->Set();
                }
            });

            // Check the current state of the foreground brush in case it is already set which means the property callback will not get triggered
            WUXMSolidColorBrush* solidBrush = rt_dynamic_cast([WUXMSolidColorBrush class], textBlock.foreground);
            if (UXTestAPI::IsRGBAEqual(solidBrush, expectedColor)) {
                uxEvent->Set();
            }
        });

        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event state timed out!");

        // adjustImageWhen* is YES by default
        EXPECT_TRUE(buttonToTest.adjustsImageWhenHighlighted);
        EXPECT_TRUE(buttonToTest.adjustsImageWhenDisabled);

        // Title
        EXPECT_OBJCEQ(buttonToTest.currentTitle, nil);
    }

    TEST_METHOD(UIButton_AdjustImageWhenHighlighted) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC defaultButton];

        __block auto uxEvent = UXEvent::CreateAuto();
        __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();
        __block StrongId<WXFrameworkElement> buttonBorder;
        __block StrongId<UIColor> expectedColor;

        WXFrameworkElement* xamlElement = [buttonToTest xamlElement];
        ASSERT_OBJCNE(xamlElement, nil);

        // Find buttonBorder in the visual tree
        dispatch_sync(dispatch_get_main_queue(), ^{
            buttonBorder = FindXamlChild(xamlElement, @"buttonBorder");
        });
        ASSERT_OBJCNE(buttonBorder, nil);

        dispatch_sync(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(buttonBorder, [WXCBorder backgroundProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                if (expectedColor) {
                    WUXMSolidColorBrush* solidBrush = rt_dynamic_cast([WUXMSolidColorBrush class], [sender getValue:dp]);

                    // Validation
                    EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBrush, expectedColor));
                }
                else {
                    // In adjustsImageWhenHighlighted == NO scenario, we set the border background brush to nil
                    EXPECT_OBJCEQ([sender getValue:dp], nil);
                }

                uxEvent->Set();
            });
        });

        // There should be no border background color change if there is no title/image/background image set on the button
        dispatch_sync(dispatch_get_main_queue(), ^{
            buttonToTest.highlighted = YES;
        });
        ASSERT_FALSE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Unexpected background color changed event fired!");

        // Set a title and validate that the border background color has changed
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedColor = [UIColor colorWithRed:0.0f green:0.0f blue:0.0f alpha:0.255f];
            [buttonVC textTitle].text = @"adjustsImageWhenHighlighted";
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event timed out!");

        // Set adjustsImageWhenHiglighted to NO
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedColor = nil;
            buttonToTest.adjustsImageWhenHighlighted = NO;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event timed out!");

        // Set adjustsImageWhenHiglighted to YES again
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedColor = [UIColor colorWithRed:0.0f green:0.0f blue:0.0f alpha:0.255f];
            buttonToTest.adjustsImageWhenHighlighted = YES;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event timed out!");

        // Setting an image for state UIControlStateHighlighted should not generate a border background color
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedColor = nil;
            [buttonVC textImageStateField].text = @"H;";
            [buttonVC textImage].text = @"button_image.png";
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event timed out!");
    }

    TEST_METHOD(UIButton_AdjustImageWhenDisabled) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC defaultButton];

        __block auto uxEvent = UXEvent::CreateAuto();
        __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();
        __block StrongId<WXFrameworkElement> buttonBorder;
        __block StrongId<UIColor> expectedColor;

        WXFrameworkElement* xamlElement = [buttonToTest xamlElement];
        ASSERT_OBJCNE(xamlElement, nil);

        // Find buttonBorder in the visual tree
        dispatch_sync(dispatch_get_main_queue(), ^{
            buttonBorder = FindXamlChild(xamlElement, @"buttonBorder");
        });
        ASSERT_OBJCNE(buttonBorder, nil);

        dispatch_sync(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(buttonBorder, [WXCBorder backgroundProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                if (expectedColor) {
                    WUXMSolidColorBrush* solidBrush = rt_dynamic_cast([WUXMSolidColorBrush class], [sender getValue:dp]);

                    // Validation
                    EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBrush, expectedColor));
                }
                else {
                    // In adjustsImageWhenDisabled == NO scenario, we set the border background brush to nil
                    EXPECT_OBJCEQ([sender getValue:dp], nil);
                }

                uxEvent->Set();
            });
        });

        // Set a title and validate that the border background color has changed when disabled
        dispatch_sync(dispatch_get_main_queue(), ^{
            buttonToTest.enabled = NO;
            expectedColor = [UIColor colorWithRed:1.0f green:1.0f blue:1.0f alpha:0.59f];
            [buttonVC textTitle].text = @"adjustsImageWhenDisabled";
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event timed out!");

        // Set adjustsImageWhenDisabled to NO
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedColor = nil;
            buttonToTest.adjustsImageWhenDisabled = NO;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event timed out!");

        // Set adjustsImageWhenDisabled to YES again
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedColor = [UIColor colorWithRed:1.0f green:1.0f blue:1.0f alpha:0.59f];
            buttonToTest.adjustsImageWhenDisabled = YES;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event timed out!");

        // Setting the image for state UIControlStateDisabled should not generate a border background color
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedColor = nil;
            [buttonVC textImageStateField].text = @"D;";
            [buttonVC textImage].text = @"button_image.png";
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event timed out!");
    }

    TEST_METHOD(UIButton_TitleForStateCumulative) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC defaultButton];

        __block auto uxEvent = UXEvent::CreateAuto();
        __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();
        __block NSString* expectedString;

        // Extract UIButton.titleLabel control to verify its visual state
        WXFrameworkElement* xamlElement = [buttonToTest.titleLabel _getXamlTextBlock];
        ASSERT_TRUE(xamlElement);

        dispatch_async(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(xamlElement, [WXCTextBlock textProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                NSString* text = UXTestAPI::NSStringFromPropertyValue([sender getValue:dp]);
                LOG_INFO("XAML text: %@", text);

                // Validation
                if ([text isEqualToString:expectedString]) {
                    uxEvent->Set();
                }
            });
        });

        // Set UIControlStateNormal state value - test transitions to other states.
        // Without previously defined state values, any transition to those states should fallback to normal state value
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedString = @"Normal";
            [buttonVC textTitleStateField].text = @"N;"; // normal
            [buttonVC textTitle].text = expectedString;

            buttonToTest.highlighted = NO;
            buttonToTest.selected = NO;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Normal state timed out!");

        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateHighlighted,
                                      @selector(currentTitle),
                                      [buttonToTest titleForState:UIControlStateNormal]);
        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateSelected,
                                      @selector(currentTitle),
                                      [buttonToTest titleForState:UIControlStateNormal]);
        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateHighlighted | UIControlStateSelected,
                                      @selector(currentTitle),
                                      [buttonToTest titleForState:UIControlStateNormal]);

        // Set UIControlStateHighlighted state value - test transitions to other states.
        // Without previously defined state values, any transition to those states should fallback to normal state value
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedString = @"Highlighted";
            [buttonVC textTitleStateField].text = @"H;"; // highlighted
            [buttonVC textTitle].text = expectedString;

            buttonToTest.highlighted = YES;
            buttonToTest.selected = NO;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Highlighted state timed out!");

        expectedString = @"Normal";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateNormal,
                                      @selector(currentTitle),
                                      [buttonToTest titleForState:UIControlStateNormal]);
        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateSelected,
                                      @selector(currentTitle),
                                      [buttonToTest titleForState:UIControlStateNormal]);
        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateHighlighted | UIControlStateSelected,
                                      @selector(currentTitle),
                                      [buttonToTest titleForState:UIControlStateNormal]);

        // Set UIControlStateSelected state value - test transitions to other states.
        // Without previously defined state values, any transition to those states should fallback to normal state value
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedString = @"Selected";
            [buttonVC textTitleStateField].text = @"S;"; // selected
            [buttonVC textTitle].text = expectedString;

            buttonToTest.highlighted = NO;
            buttonToTest.selected = YES;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Selected state timed out!");

        expectedString = @"Normal";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateNormal,
                                      @selector(currentTitle),
                                      [buttonToTest titleForState:UIControlStateNormal]);
        expectedString = @"Highlighted";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateHighlighted,
                                      @selector(currentTitle),
                                      [buttonToTest titleForState:UIControlStateHighlighted]);
        expectedString = @"Normal";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateHighlighted | UIControlStateSelected,
                                      @selector(currentTitle),
                                      [buttonToTest titleForState:UIControlStateNormal]);

        // Set UIControlStateHighlighted|UIControlStateSelected state value - test transitions to other states.
        // Without previously defined state values, any transition to those states should fallback to normal state value
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedString = @"HighlightedSelected";
            [buttonVC textTitleStateField].text = @"HS;"; // highlighted-selected
            [buttonVC textTitle].text = expectedString;

            buttonToTest.highlighted = YES;
            buttonToTest.selected = YES;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: HighlightedSelected state timed out!");

        expectedString = @"Normal";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateNormal,
                                      @selector(currentTitle),
                                      [buttonToTest titleForState:UIControlStateNormal]);
        expectedString = @"Highlighted";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateHighlighted,
                                      @selector(currentTitle),
                                      [buttonToTest titleForState:UIControlStateHighlighted]);
        expectedString = @"Selected";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateSelected,
                                      @selector(currentTitle),
                                      [buttonToTest titleForState:UIControlStateSelected]);
    }

    TEST_METHOD(UIButton_TitleColorForStateCumulative) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC defaultButton];

        __block auto uxEvent = UXEvent::CreateAuto();
        __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();
        __block NSString* expectedColor;

        // Extract UIButton.titleLabel control to verify its visual state
        WXFrameworkElement* xamlElement = [buttonToTest.titleLabel _getXamlTextBlock];
        ASSERT_OBJCNE(xamlElement, nil);

        dispatch_async(dispatch_get_main_queue(), ^{
            // Add some text which helps display the changes in all states during development
            [buttonVC textTitle].text = @"Functional testing";

            // Register RAII event subscription handler
            xamlSubscriber->Set(xamlElement, [WXCTextBlock foregroundProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                WUXMSolidColorBrush* solidBrush = rt_dynamic_cast([WUXMSolidColorBrush class], [sender getValue:dp]);
                LOG_INFO("XAML solid color brush (rgba): %d,%d,%d,%d",
                         [solidBrush.color r],
                         [solidBrush.color g],
                         [solidBrush.color b],
                         [solidBrush.color a]);

                // Validation
                UIColor* color = [UIColor performSelector:NSSelectorFromString(expectedColor)];
                if (UXTestAPI::IsRGBAEqual(solidBrush, color)) {
                    uxEvent->Set();
                }
            });
        });

        // Set UIControlStateNormal state value - test transitions to other states.
        // Without previously defined state values, any transition to those states should fallback to normal state value
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedColor = @"redColor";
            [buttonVC textTitleColorStateField].text = @"N;"; // normal
            [buttonVC textTitleColor].text = expectedColor;

            buttonToTest.highlighted = NO;
            buttonToTest.selected = NO;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Normal state timed out!");

        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateHighlighted,
                                      @selector(currentTitleColor),
                                      [buttonToTest titleColorForState:UIControlStateNormal]);
        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateSelected,
                                      @selector(currentTitleColor),
                                      [buttonToTest titleColorForState:UIControlStateNormal]);
        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateHighlighted | UIControlStateSelected,
                                      @selector(currentTitleColor),
                                      [buttonToTest titleColorForState:UIControlStateNormal]);

        // Set UIControlStateHighlighted state value - test transitions to other states.
        // Without previously defined state values, any transition to those states should fallback to normal state value
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedColor = @"greenColor";
            [buttonVC textTitleColorStateField].text = @"H;"; // highlighted
            [buttonVC textTitleColor].text = expectedColor;

            buttonToTest.highlighted = YES;
            buttonToTest.selected = NO;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Highlighted state timed out!");

        expectedColor = @"redColor";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateNormal,
                                      @selector(currentTitleColor),
                                      [buttonToTest titleColorForState:UIControlStateNormal]);
        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateSelected,
                                      @selector(currentTitleColor),
                                      [buttonToTest titleColorForState:UIControlStateNormal]);
        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateHighlighted | UIControlStateSelected,
                                      @selector(currentTitleColor),
                                      [buttonToTest titleColorForState:UIControlStateNormal]);

        // Set UIControlStateSelected state value - test transitions to other states.
        // Without previously defined state values, any transition to those states should fallback to normal state value
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedColor = @"brownColor";
            [buttonVC textTitleColorStateField].text = @"S;"; // selected
            [buttonVC textTitleColor].text = expectedColor;

            buttonToTest.highlighted = NO;
            buttonToTest.selected = YES;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Selected state timed out!");

        expectedColor = @"redColor";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateNormal,
                                      @selector(currentTitleColor),
                                      [buttonToTest titleColorForState:UIControlStateNormal]);
        expectedColor = @"greenColor";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateHighlighted,
                                      @selector(currentTitleColor),
                                      [buttonToTest titleColorForState:UIControlStateHighlighted]);
        expectedColor = @"redColor";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateHighlighted | UIControlStateSelected,
                                      @selector(currentTitleColor),
                                      [buttonToTest titleColorForState:UIControlStateNormal]);

        // Set UIControlStateHighlighted|UIControlStateSelected state value - test transitions to other states.
        // Without previously defined state values, any transition to those states should fallback to normal state value
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedColor = @"yellowColor";
            [buttonVC textTitleColorStateField].text = @"HS;"; // highlighted-selected
            [buttonVC textTitleColor].text = expectedColor;

            buttonToTest.highlighted = YES;
            buttonToTest.selected = YES;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: HighlightedSelected state timed out!");

        expectedColor = @"redColor";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateNormal,
                                      @selector(currentTitleColor),
                                      [buttonToTest titleColorForState:UIControlStateNormal]);
        expectedColor = @"greenColor";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateHighlighted,
                                      @selector(currentTitleColor),
                                      [buttonToTest titleColorForState:UIControlStateHighlighted]);
        expectedColor = @"brownColor";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateSelected,
                                      @selector(currentTitleColor),
                                      [buttonToTest titleColorForState:UIControlStateSelected]);
    }

    TEST_METHOD(UIButton_ImageForStateCumulative) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC defaultButton];

        __block auto uxEvent = UXEvent::CreateAuto();
        __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();
        __block NSString* expectedImage;

        // Extract UIButton.imageView control to verify its visual state
        WXFrameworkElement* xamlElement = [buttonToTest.imageView xamlElement];
        ASSERT_OBJCNE(xamlElement, nil);

        dispatch_async(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(xamlElement, [WXCImage sourceProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                WUXMIBitmapSource* bitmapSource = rt_dynamic_cast([WUXMIBitmapSource class], [sender getValue:dp]);
                LOG_INFO("XAML bitmap dimensions: %dx%d", [bitmapSource pixelWidth], [bitmapSource pixelHeight]);

                NSString* imageDimensions = [NSString stringWithFormat:@"%dx%d.png", [bitmapSource pixelWidth], [bitmapSource pixelHeight]];
                if ([imageDimensions isEqualToString:expectedImage]) {
                    uxEvent->Set();
                }
            });
        });

        // Set UIControlStateNormal state value - test transitions to other states.
        // Without previously defined state values, any transition to those states should fallback to normal state value
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedImage = @"50x50.png"; // image used in normal state
            [buttonVC textImageStateField].text = @"N;"; // normal state
            [buttonVC textImage].text = expectedImage;

            buttonToTest.highlighted = NO;
            buttonToTest.selected = NO;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Normal state timed out!");

        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateHighlighted,
                                      @selector(currentImage),
                                      [buttonToTest imageForState:UIControlStateNormal]);
        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateSelected,
                                      @selector(currentImage),
                                      [buttonToTest imageForState:UIControlStateNormal]);
        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateHighlighted | UIControlStateSelected,
                                      @selector(currentImage),
                                      [buttonToTest imageForState:UIControlStateNormal]);

        // Set UIControlStateHighlighted state value - test transitions to other states.
        // Without previously defined state values, any transition to those states should fallback to normal state value
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedImage = @"75x75.png";
            [buttonVC textImageStateField].text = @"H;"; // highlighted
            [buttonVC textImage].text = expectedImage;

            buttonToTest.highlighted = YES;
            buttonToTest.selected = NO;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Highlighted state timed out!");

        // Each transition ends with the normal state value, either it transitions or falls back on normal state value
        expectedImage = @"50x50.png";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateNormal,
                                      @selector(currentImage),
                                      [buttonToTest imageForState:UIControlStateNormal]);
        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateSelected,
                                      @selector(currentImage),
                                      [buttonToTest imageForState:UIControlStateNormal]);
        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateHighlighted | UIControlStateSelected,
                                      @selector(currentImage),
                                      [buttonToTest imageForState:UIControlStateNormal]);

        // Set UIControlStateSelected state value - test transitions to other states.
        // Without previously defined state values, any transition to those states should fallback to normal state value
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedImage = @"125x125.png";
            [buttonVC textImageStateField].text = @"S;"; // selected
            [buttonVC textImage].text = expectedImage;

            buttonToTest.highlighted = NO;
            buttonToTest.selected = YES;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Selected state timed out!");

        expectedImage = @"50x50.png"; // pre-defined normal state
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateNormal,
                                      @selector(currentImage),
                                      [buttonToTest imageForState:UIControlStateNormal]);
        expectedImage = @"75x75.png"; // pre-defined highlighted state
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateHighlighted,
                                      @selector(currentImage),
                                      [buttonToTest imageForState:UIControlStateHighlighted]);
        expectedImage = @"50x50.png"; // fallback to normal state
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateHighlighted | UIControlStateSelected,
                                      @selector(currentImage),
                                      [buttonToTest imageForState:UIControlStateNormal]);

        // Set UIControlStateHighlighted|UIControlStateSelected state value - test transitions to other states.
        // Without previously defined state values, any transition to those states should fallback to normal state value
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedImage = @"150x150.png";
            [buttonVC textImageStateField].text = @"HS;"; // highlighted-selected
            [buttonVC textImage].text = expectedImage;

            buttonToTest.highlighted = YES;
            buttonToTest.selected = YES;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: HighlightedSelected state timed out!");

        expectedImage = @"50x50.png";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateNormal,
                                      @selector(currentImage),
                                      [buttonToTest imageForState:UIControlStateNormal]);
        expectedImage = @"75x75.png";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateHighlighted,
                                      @selector(currentImage),
                                      [buttonToTest imageForState:UIControlStateHighlighted]);
        expectedImage = @"125x125.png";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateSelected,
                                      @selector(currentImage),
                                      [buttonToTest imageForState:UIControlStateSelected]);
    }

    TEST_METHOD(UIButton_BackgroundImageForStateCumulative) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC defaultButton];

        __block auto uxLayoutEvent = UXEvent::CreateManual();
        __block StrongId<WXFrameworkElement> layerContent;

        __block auto uxEvent = UXEvent::CreateAuto();
        __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();
        __block NSString* expectedBackgroundImage;
        EventRegistrationToken ert{};
        EventRegistrationToken* const ertAddr = &ert;

        WXFrameworkElement* xamlElement = [buttonToTest xamlElement];
        ASSERT_OBJCNE(xamlElement, nil);

        // Wait for the layerContent to be part of the visual tree
        dispatch_sync(dispatch_get_main_queue(), ^{
            *ertAddr = [xamlElement addLayoutUpdatedEvent:^(RTObject* sender, RTObject* args) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    // Initially there is no LayerContent element unless we set a background image
                    if (layerContent == nil) {
                        // Initially there is no LayerContent element
                        layerContent = FindXamlChild(xamlElement, @"LayerContent");
                        if (layerContent) {
                            // Ignore further layout events
                            [xamlElement removeLayoutUpdatedEvent:*ertAddr];
                            uxLayoutEvent->Set();
                        }
                    }
                });
            }];

            // Set a default background image so we trigger the LayerContent XAML addition
            [buttonVC textBackgroundImage].text = @"yellow_background.jpg";
        });

        // Wait for the LayerContent to be present before running background image tests
        uxLayoutEvent->Wait(c_testTimeoutInSec);
        ASSERT_OBJCNE(layerContent, nil);

        dispatch_sync(dispatch_get_main_queue(), ^{
            xamlSubscriber->Set(layerContent, [WXCImage sourceProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                // Upon cleanup or dismissal of the view, LayerCoordinator sets the source to NULL which we should avoid
                RTObject* rtObject = [sender getValue:dp];
                if (rtObject) {
                    WUXMIBitmapSource* bitmapSource = rt_dynamic_cast([WUXMIBitmapSource class], rtObject);
                    LOG_INFO("XAML bitmap dimensions: %dx%d", [bitmapSource pixelWidth], [bitmapSource pixelHeight]);

                    NSString* imageDimensions =
                        [NSString stringWithFormat:@"%dx%d.png", [bitmapSource pixelWidth], [bitmapSource pixelHeight]];
                    if ([imageDimensions isEqualToString:expectedBackgroundImage]) {
                        uxEvent->Set();
                    }
                }
            });
        });

        // Set UIControlStateNormal state value - test transitions to other states.
        // Without previously defined state values, any transition to those states should fallback to normal state value
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedBackgroundImage = @"50x50.png";
            [buttonVC textBackgroundImageStateField].text = @"N;"; // normal
            [buttonVC textBackgroundImage].text = expectedBackgroundImage;

            buttonToTest.highlighted = NO;
            buttonToTest.selected = NO;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Normal state timed out!");

        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateHighlighted,
                                      @selector(currentBackgroundImage),
                                      [buttonToTest backgroundImageForState:UIControlStateNormal]);
        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateSelected,
                                      @selector(currentBackgroundImage),
                                      [buttonToTest backgroundImageForState:UIControlStateNormal]);
        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateHighlighted | UIControlStateSelected,
                                      @selector(currentBackgroundImage),
                                      [buttonToTest backgroundImageForState:UIControlStateNormal]);

        // Set UIControlStateHighlighted state value - test transitions to other states.
        // Without previously defined state values, any transition to those states should fallback to normal state value
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedBackgroundImage = @"75x75.png";
            [buttonVC textBackgroundImageStateField].text = @"H;"; // highlighted
            [buttonVC textBackgroundImage].text = expectedBackgroundImage;

            buttonToTest.highlighted = YES;
            buttonToTest.selected = NO;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Highlighted state timed out!");

        expectedBackgroundImage = @"50x50.png";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateNormal,
                                      @selector(currentBackgroundImage),
                                      [buttonToTest backgroundImageForState:UIControlStateNormal]);
        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateSelected,
                                      @selector(currentBackgroundImage),
                                      [buttonToTest backgroundImageForState:UIControlStateNormal]);
        UIControlCheckStateTransition(buttonToTest,
                                      nullptr,
                                      UIControlStateHighlighted | UIControlStateSelected,
                                      @selector(currentBackgroundImage),
                                      [buttonToTest backgroundImageForState:UIControlStateNormal]);

        // Set UIControlStateSelected state value - test transitions to other states.
        // Without previously defined state values, any transition to those states should fallback to normal state value
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedBackgroundImage = @"125x125.png";
            [buttonVC textBackgroundImageStateField].text = @"S;"; // selected
            [buttonVC textBackgroundImage].text = expectedBackgroundImage;

            buttonToTest.highlighted = NO;
            buttonToTest.selected = YES;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Selected state timed out!");

        expectedBackgroundImage = @"50x50.png";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateNormal,
                                      @selector(currentBackgroundImage),
                                      [buttonToTest backgroundImageForState:UIControlStateNormal]);
        expectedBackgroundImage = @"75x75.png";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateHighlighted,
                                      @selector(currentBackgroundImage),
                                      [buttonToTest backgroundImageForState:UIControlStateHighlighted]);
        expectedBackgroundImage = @"50x50.png";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateHighlighted | UIControlStateSelected,
                                      @selector(currentBackgroundImage),
                                      [buttonToTest backgroundImageForState:UIControlStateNormal]);

        // Set UIControlStateHighlighted|UIControlStateSelected state value - test transitions to other states.
        // Without previously defined state values, any transition to those states should fallback to normal state value
        dispatch_sync(dispatch_get_main_queue(), ^{
            expectedBackgroundImage = @"150x150.png";
            [buttonVC textBackgroundImageStateField].text = @"SH;"; // selected-highlighted
            [buttonVC textBackgroundImage].text = expectedBackgroundImage;

            buttonToTest.highlighted = YES;
            buttonToTest.selected = YES;
        });
        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: HighlightedSelected state timed out!");

        expectedBackgroundImage = @"50x50.png";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateNormal,
                                      @selector(currentBackgroundImage),
                                      [buttonToTest backgroundImageForState:UIControlStateNormal]);
        expectedBackgroundImage = @"75x75.png";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateHighlighted,
                                      @selector(currentBackgroundImage),
                                      [buttonToTest backgroundImageForState:UIControlStateHighlighted]);
        expectedBackgroundImage = @"125x125.png";
        UIControlCheckStateTransition(buttonToTest,
                                      uxEvent,
                                      UIControlStateSelected,
                                      @selector(currentBackgroundImage),
                                      [buttonToTest backgroundImageForState:UIControlStateSelected]);
    }

    TEST_METHOD(UIButton_TitleLabel) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC defaultButton];

        WXFrameworkElement* xamlElement = [buttonToTest.titleLabel _getXamlTextBlock];
        ASSERT_OBJCNE(xamlElement, nil);
    }

    TEST_METHOD(UIButton_ContentEdgeInsets) {
        BEGIN_TEST_METHOD_PROPERTIES()
        TEST_METHOD_PROPERTY(L"ignore", L"true")
        END_TEST_METHOD_PROPERTIES()

        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC defaultButton];

        __block auto uxEvent = UXEvent::CreateAuto();
        __block auto xamlImageWidthSubscriber = std::make_shared<XamlEventSubscription>();
        __block auto xamlImageHeightSubscriber = std::make_shared<XamlEventSubscription>();
        __block auto xamlImageCanvasLeftSubscriber = std::make_shared<XamlEventSubscription>();
        __block auto xamlImageCanvasTopSubscriber = std::make_shared<XamlEventSubscription>();
        __block auto xamlTitleWidthSubscriber = std::make_shared<XamlEventSubscription>();
        __block auto xamlTitleHeightSubscriber = std::make_shared<XamlEventSubscription>();

        WXFrameworkElement* xamlImageElement = [buttonToTest.imageView xamlElement];
        ASSERT_OBJCNE(xamlImageElement, nil);

        WXFrameworkElement* xamlTitleElement = [buttonToTest.titleLabel xamlElement];
        ASSERT_OBJCNE(xamlTitleElement, nil);

        dispatch_sync(dispatch_get_main_queue(), ^{
            [buttonVC textImageStateField].text = @"N;";
            [buttonVC textImage].text = @"50x50.png";

            [buttonVC textTitleStateField].text = @"N;";
            [buttonVC textTitle].text = @"Normal";
            [buttonVC textTitleColorStateField].text = @"N;";
            [buttonVC textTitleColor].text = @"redColor";

            // Register RAII event subscription handler
            xamlImageWidthSubscriber->Set(xamlImageElement, [WXCImage widthProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                double width = DoubleFromPropertyValue([sender getValue:dp]);

                // Validation
                EXPECT_EQ(width, 40.0f);
                uxEvent->Set();
            });
            xamlImageHeightSubscriber->Set(xamlImageElement, [WXCImage heightProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                double height = DoubleFromPropertyValue([sender getValue:dp]);

                // Validation
                EXPECT_EQ(height, 40.0f);
                uxEvent->Set();
            });
            xamlImageCanvasLeftSubscriber->Set(xamlImageElement, [WXCCanvas leftProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                double left = DoubleFromPropertyValue([sender getValue:dp]);

                // Validation
                EXPECT_EQ(left, 80.0f);
                uxEvent->Set();
            });
            xamlImageCanvasTopSubscriber->Set(xamlImageElement, [WXCCanvas topProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                double top = DoubleFromPropertyValue([sender getValue:dp]);

                // Validation
                EXPECT_EQ(top, 80.0f);
                uxEvent->Set();
            });

            xamlTitleWidthSubscriber->Set(xamlTitleElement, [WXCGrid widthProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                double width = DoubleFromPropertyValue([sender getValue:dp]);

                // Validation
                EXPECT_EQ((int)width, 52);
                uxEvent->Set();
            });
            xamlTitleHeightSubscriber->Set(xamlTitleElement, [WXCGrid heightProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                double height = DoubleFromPropertyValue([sender getValue:dp]);

                // Validation
                EXPECT_EQ((int)height, 18);
                uxEvent->Set();
            });

            // Action
            [buttonVC textContentEdgeInsets].text = @"{80.0f, 80.0f, 80.0f, 80.0f}";
        });

        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec, 6 /* signal count */), "FAILED: Waiting for property changed events timed out!");

        // Ideally, we can capture the XAML event when the layout is updated but in testing the layout updated event can happen before the inset was applied.
        // For now confirm that the values matches the expected frame value after it has been set
        dispatch_sync(dispatch_get_main_queue(), ^{
            WUXMTransformGroup* transformGroup = rt_dynamic_cast([WUXMTransformGroup class],[xamlTitleElement renderTransform]);
            EXPECT_OBJCNE(transformGroup, nil);

            // Compare against the expected frame X and Y
            WUXMMatrix* matrix = [transformGroup value];
            EXPECT_EQ([matrix offsetX], 98.0f);
            EXPECT_EQ([matrix offsetY], 90.0f);
        });
    }

    TEST_METHOD(UIButton_TitleEdgeInsets) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC defaultButton];

        __block auto uxEvent = UXEvent::CreateAuto();
        __block auto xamlWidthSubscriber = std::make_shared<XamlEventSubscription>();
        __block auto xamlHeightSubscriber = std::make_shared<XamlEventSubscription>();

        // Extract UIButton.titleLabel "grid" to verify its visual state
        WXFrameworkElement* xamlElement = [buttonToTest.titleLabel xamlElement];
        ASSERT_OBJCNE(xamlElement, nil);

        dispatch_sync(dispatch_get_main_queue(), ^{
            [buttonVC textTitleStateField].text = @"N;";
            [buttonVC textTitle].text = @"Normal";
            [buttonVC textTitleColorStateField].text = @"N;";
            [buttonVC textTitleColor].text = @"redColor";

            // Register RAII event subscription handler
            xamlWidthSubscriber->Set(xamlElement, [WXCGrid widthProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                double width = DoubleFromPropertyValue([sender getValue:dp]);

                // Validation - see #2155
                EXPECT_EQ((int)width, 40);
                uxEvent->Set();
            });
            xamlHeightSubscriber->Set(xamlElement, [WXCGrid heightProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                double height = DoubleFromPropertyValue([sender getValue:dp]);

                // Validation
                EXPECT_EQ((int)height, 18);
                uxEvent->Set();
            });

            // Action
            [buttonVC textTitleEdgeInsets].text = @"{80.0f, 80.0f, 80.0f, 80.0f}";
        });

        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec, 2 /* signal count */), "FAILED: Waiting for property changed events timed out!");

        dispatch_sync(dispatch_get_main_queue(), ^{
            WUXMTransformGroup* transformGroup = rt_dynamic_cast([WUXMTransformGroup class],[xamlElement renderTransform]);
            EXPECT_OBJCNE(transformGroup, nil);

            // Compare against the expected frame X and Y - see #2155
            WUXMMatrix* matrix = [transformGroup value];
            EXPECT_EQ([matrix offsetX], 80.0f);
            EXPECT_EQ([matrix offsetY], 90.0f);
        });
    }

    TEST_METHOD(UIButton_ImageEdgeInsets) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC defaultButton];

        __block auto uxEvent = UXEvent::CreateAuto();
        __block auto xamlWidthSubscriber = std::make_shared<XamlEventSubscription>();
        __block auto xamlHeightSubscriber = std::make_shared<XamlEventSubscription>();
        __block auto xamlCanvasLeftSubscriber = std::make_shared<XamlEventSubscription>();
        __block auto xamlCanvasTopSubscriber = std::make_shared<XamlEventSubscription>();

        // Extract UIButton.imageView control to verify its visual state
        WXFrameworkElement* xamlElement = [buttonToTest.imageView xamlElement];
        ASSERT_OBJCNE(xamlElement, nil);

        dispatch_sync(dispatch_get_main_queue(), ^{
            [buttonVC textImageStateField].text = @"N;";
            [buttonVC textImage].text = @"50x50.png";

            // Register RAII event subscription handler
            xamlWidthSubscriber->Set(xamlElement, [WXCImage widthProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                double width = DoubleFromPropertyValue([sender getValue:dp]);

                // Validation
                EXPECT_EQ(width, 40.0f);
                uxEvent->Set();
            });
            xamlHeightSubscriber->Set(xamlElement, [WXCImage heightProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                double height = DoubleFromPropertyValue([sender getValue:dp]);

                // Validation
                EXPECT_EQ(height, 40.0f);
                uxEvent->Set();
            });
            xamlCanvasLeftSubscriber->Set(xamlElement, [WXCCanvas leftProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                double left = DoubleFromPropertyValue([sender getValue:dp]);

                // Validation
                EXPECT_EQ(left, 80.0f);
                uxEvent->Set();
            });
            xamlCanvasTopSubscriber->Set(xamlElement, [WXCCanvas topProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                double top = DoubleFromPropertyValue([sender getValue:dp]);

                // Validation
                EXPECT_EQ(top, 80.0f);
                uxEvent->Set();
            });

            // Action
            [buttonVC textImageEdgeInsets].text = @"{80.0f, 80.0f, 80.0f, 80.0f}";
        });

        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec, 4 /* signal count */), "FAILED: Waiting for property changed events timed out!");
    }

    TEST_METHOD(UIButton_CurrentTitle) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC defaultButton];

        __block auto uxEvent = UXEvent::CreateAuto();
        __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();
        __block NSString* expectedString = @"Functional testing - currentTitle";

        // Extract UIButton.titleLabel control to verify its visual state
        WXFrameworkElement* xamlElement = [buttonToTest.titleLabel _getXamlTextBlock];
        ASSERT_OBJCNE(xamlElement, nil);

        dispatch_sync(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(xamlElement, [WXCTextBlock textProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                NSString* text = UXTestAPI::NSStringFromPropertyValue([sender getValue:dp]);

                // Validation
                if ([text isEqualToString:expectedString]) {
                    uxEvent->Set();
                }
            });

            // Action
            [buttonVC textTitle].text = expectedString;
        });

        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event timed out!");
    }

    TEST_METHOD(UIButton_CurrentTitleColor) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC defaultButton];

        __block auto uxEvent = UXEvent::CreateAuto();
        __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();

        // Extract UIButton.titleLabel control to verify its visual state
        WXFrameworkElement* xamlElement = [buttonToTest.titleLabel _getXamlTextBlock];
        ASSERT_OBJCNE(xamlElement, nil);

        dispatch_async(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(xamlElement, [WXCTextBlock foregroundProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                WUXMSolidColorBrush* solidBrush = rt_dynamic_cast([WUXMSolidColorBrush class], [sender getValue:dp]);

                // Validation
                EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBrush, buttonToTest.currentTitleColor));
                uxEvent->Set();
            });

            // Action
            [buttonVC textTitleColor].text = @"redColor";
        });

        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event timed out!");
    }

    TEST_METHOD(UIButton_CurrentImage) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC defaultButton];

        __block auto uxEvent = UXEvent::CreateAuto();
        __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();
        __block NSString* expectedImage = @"50x50.png";

        // Extract UIButton.imageView control to verify its visual state
        WXFrameworkElement* xamlElement = [buttonToTest.imageView xamlElement];
        ASSERT_OBJCNE(xamlElement, nil);

        dispatch_async(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(xamlElement, [WXCImage sourceProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                WUXMIBitmapSource* bitmapSource = rt_dynamic_cast([WUXMIBitmapSource class], [sender getValue:dp]);

                // Validation
                UIImage* image = buttonToTest.currentImage;
                EXPECT_EQ([bitmapSource pixelWidth], (int)image.size.width);
                EXPECT_EQ([bitmapSource pixelHeight], (int)image.size.height);
                uxEvent->Set();
            });

            // Action
            [buttonVC textImage].text = expectedImage;
        });

        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event timed out!");
    }

    TEST_METHOD(UIButton_CurrentBackgroundImage) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC defaultButton];

        __block auto uxLayoutEvent = UXEvent::CreateManual();
        __block StrongId<WXFrameworkElement> layerContent;

        __block auto uxEvent = UXEvent::CreateAuto();
        __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();
        __block NSString* expectedBackgroundImage = @"150x150.png";
        EventRegistrationToken ert{};
        EventRegistrationToken* const ertAddr = &ert;

        WXFrameworkElement* xamlElement = [buttonToTest xamlElement];
        ASSERT_OBJCNE(xamlElement, nil);

        // Wait for the layerContent to be part of the visual tree
        dispatch_sync(dispatch_get_main_queue(), ^{
            *ertAddr = [xamlElement addLayoutUpdatedEvent:^(RTObject* sender, RTObject* args) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    // Initially there is no LayerContent element unless we set a background image
                    if (layerContent == nil) {
                        // Initially there is no LayerContent element
                        layerContent = FindXamlChild(xamlElement, @"LayerContent");
                        if (layerContent) {
                            // Ignore further layout events
                            [xamlElement removeLayoutUpdatedEvent:*ertAddr];
                            uxLayoutEvent->Set();
                        }
                    }
                });
            }];

            // Set a default background image so we trigger the LayerContent XAML addition
            [buttonVC textBackgroundImage].text = expectedBackgroundImage;
        });

        // Wait for the LayerContent to be present before running background image tests
        uxLayoutEvent->Wait(c_testTimeoutInSec);
        ASSERT_OBJCNE(layerContent, nil);

        dispatch_sync(dispatch_get_main_queue(), ^{
            xamlSubscriber->Set(layerContent, [WXCImage sourceProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                // Upon cleanup or dismissal of the view, LayerCoordinator sets the source to NULL which we should avoid
                RTObject* rtObject = [sender getValue:dp];
                if (rtObject) {
                    WUXMIBitmapSource* bitmapSource = rt_dynamic_cast([WUXMIBitmapSource class], rtObject);

                    // Validation
                    UIImage* image = buttonToTest.currentBackgroundImage;
                    EXPECT_EQ([bitmapSource pixelWidth], (int)image.size.width);
                    EXPECT_EQ([bitmapSource pixelHeight], (int)image.size.height);
                    uxEvent->Set();
                }
            });

            // Action
            expectedBackgroundImage = @"125x125.png";
            [buttonVC textBackgroundImage].text = expectedBackgroundImage;
        });

        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event timed out!");
    }

    TEST_METHOD(UIButton_ImageView) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC);

        UIButton* buttonToTest = [buttonVC defaultButton];
        WXFrameworkElement* xamlElement = [buttonToTest.imageView xamlElement];
        ASSERT_OBJCNE(xamlElement, nil);
    }
};
