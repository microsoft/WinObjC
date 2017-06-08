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
#import "UIViewInternal.h"
#include "CppWinRTHelpers.h"

// Re-use existing sample code for validation
#import "UIKitControls/UIButtonWithControlsViewController.h"

#include "COMIncludes.h"
#import <winrt/Windows.UI.Xaml.Media.Imaging.h>
#include "COMIncludes_End.h"

using namespace UXTestAPI;
using namespace winrt::Windows::UI::Xaml;
namespace WF = winrt::Windows::Foundation;

// Callback object for the CurrentBackgroundImage test.
// Normally a closure can be created with a lambda, but a compiler issue prevents that in
// this case. Until it's fixed, use this object as a workaround.
class LayoutUpdatedCallback
{
public:
    LayoutUpdatedCallback(FrameworkElement* layerContentAddr, std::shared_ptr<UXTestAPI::UXEvent>& uxLayoutEvent, winrt::event_token* ert, const FrameworkElement& xamlElement) :
        _layerContentAddr(layerContentAddr), _uxLayoutEvent(uxLayoutEvent), _ert(ert), _xamlElement(xamlElement) {
    }

    LayoutUpdatedCallback(LayoutUpdatedCallback&& other) :
        _layerContentAddr(other._layerContentAddr), _uxLayoutEvent(other._uxLayoutEvent), _ert(other._ert), _xamlElement(other._xamlElement) {
    }

    LayoutUpdatedCallback(const LayoutUpdatedCallback& other) :
        _layerContentAddr(other._layerContentAddr), _uxLayoutEvent(other._uxLayoutEvent), _ert(other._ert), _xamlElement(other._xamlElement) {
    }

    template <typename TSender, typename TArgs>
    void operator()(TSender&&, TArgs&&) {
        @autoreleasepool {
            // Initially there is no LayerContent element unless we set a background image
            if (!*_layerContentAddr) {
                // Initially there is no LayerContent element
                *_layerContentAddr = FindXamlChild(_xamlElement, @"LayerContent");
                if (*_layerContentAddr) {
                    // Ignore further layout events
                    _xamlElement.LayoutUpdated(*_ert);
                    _uxLayoutEvent->Set();
                }
            }
        }
    }

private:
    FrameworkElement* _layerContentAddr;
    std::shared_ptr<UXTestAPI::UXEvent>& _uxLayoutEvent;
    winrt::event_token* _ert;
    FrameworkElement _xamlElement;
};

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
            FrameworkElement backingElement = [view _winrtXamlElement];
            ASSERT_TRUE(backingElement);
        });
    }

    TEST_METHOD(UIButton_CheckForLeaks) {
        Microsoft::WRL::WeakRef weakXamlElement;

        @autoreleasepool {
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

        Controls::Control xamlControl = [buttonToTest _winrtXamlElement].as<Controls::Control>();
        ASSERT_TRUE(xamlControl);

        // Extract UIButton.titleLabel control to verify its visual state
        FrameworkElement titleLabelXamlElement = [buttonToTest.titleLabel _getXamlTextBlock];
        ASSERT_TRUE(titleLabelXamlElement);

        auto textBlock = titleLabelXamlElement.as<Controls::TextBlock>();
        ASSERT_TRUE(textBlock);

        // buttonType
        ASSERT_EQ(buttonToTest.buttonType, UIButtonTypeCustom);

        // Background color
        dispatch_sync(dispatch_get_main_queue(), ^{
            auto solidBackgroundBrush = xamlControl.Background().as<Media::SolidColorBrush>();
            UIColor* expectedBackgroundColor = [UIColor colorWithRed:1.0f green:1.0f blue:1.0f alpha:0.0f];
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedBackgroundColor));
        });

        // Title color
        __block auto uxEvent = UXEvent::CreateAuto();
        __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();
        UIColor* expectedColor = [UIColor whiteColor];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(textBlock, Controls::TextBlock::ForegroundProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                auto solidBrush = sender.GetValue(dp).as<Media::SolidColorBrush>();

                // Validation
                if (UXTestAPI::IsRGBAEqual(solidBrush, expectedColor)) {
                    uxEvent->Set();
                }
            });

            // Check the current state of the foreground brush in case it is already set which means the property callback will not get triggered
            auto solidBrush = textBlock.Foreground().as<Media::SolidColorBrush>();
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

        auto xamlControl = [buttonToTest _winrtXamlElement].as<Controls::Control>();
        ASSERT_TRUE(xamlControl);

        // Extract UIButton.titleLabel control to verify its visual state
        FrameworkElement titleLabelXamlElement = [buttonToTest.titleLabel _getXamlTextBlock];
        ASSERT_TRUE(titleLabelXamlElement);

        auto textBlock = titleLabelXamlElement.as<Controls::TextBlock>();
        ASSERT_TRUE(textBlock);

        // buttonType
        ASSERT_EQ(buttonToTest.buttonType, UIButtonTypeCustom);

        // Background color
        dispatch_sync(dispatch_get_main_queue(), ^{
            auto solidBackgroundBrush = xamlControl.Background().as<Media::SolidColorBrush>();
            UIColor* expectedBackgroundColor = [UIColor colorWithRed:1.0f green:1.0f blue:1.0f alpha:0.0f];
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedBackgroundColor));
        });

        // Title color
        __block auto uxEvent = UXEvent::CreateManual();
        __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();

        dispatch_sync(dispatch_get_main_queue(), ^{
            UIColor* expectedColor = [UIColor whiteColor];

            // Register RAII event subscription handler
            xamlSubscriber->Set(textBlock, Controls::TextBlock::ForegroundProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                auto solidBrush = sender.GetValue(dp).as<Media::SolidColorBrush>();

                // Validation
                if (UXTestAPI::IsRGBAEqual(solidBrush, expectedColor)) {
                    uxEvent->Set();
                }
            });

            // Check the current state of the foreground brush in case it is already set which means the property callback will not get triggered
            auto solidBrush = textBlock.Foreground().as<Media::SolidColorBrush>();
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

        auto xamlControl = [buttonToTest _winrtXamlElement].as<Controls::Control>();
        ASSERT_TRUE(xamlControl);

        // Extract UIButton.titleLabel control to verify its visual state
        FrameworkElement titleLabelXamlElement = [buttonToTest.titleLabel _getXamlTextBlock];
        ASSERT_TRUE(titleLabelXamlElement);

        auto textBlock = titleLabelXamlElement.as<Controls::TextBlock>();
        ASSERT_TRUE(textBlock);

        // buttonType
        ASSERT_EQ(buttonToTest.buttonType, UIButtonTypeSystem);

        // Background color
        dispatch_sync(dispatch_get_main_queue(), ^{
            auto solidBackgroundBrush = xamlControl.Background().as<Media::SolidColorBrush>();
            UIColor* expectedBackgroundColor = [UIColor colorWithRed:1.0f green:1.0f blue:1.0f alpha:0.0f];
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedBackgroundColor));
        });

        // Title color
        __block auto uxEvent = UXEvent::CreateManual();
        __block auto xamlSubscriber = std::make_shared<XamlEventSubscription>();
        dispatch_sync(dispatch_get_main_queue(), ^{
            UIColor* expectedColor = [UIColor colorWithRed:0.0f green:0.47843137f blue:1.0f alpha:1.0f];

            // Register RAII event subscription handler
            xamlSubscriber->Set(textBlock, Controls::TextBlock::ForegroundProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                auto solidBrush = sender.GetValue(dp).as<Media::SolidColorBrush>();

                // Validation
                if (UXTestAPI::IsRGBAEqual(solidBrush, expectedColor)) {
                    uxEvent->Set();
                }
            });

            // Check the current state of the foreground brush in case it is already set which means the property callback will not get triggered
            auto solidBrush = textBlock.Foreground().as<Media::SolidColorBrush>();
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
        __block FrameworkElement buttonBorder = nullptr;
        __block StrongId<UIColor> expectedColor;

        FrameworkElement xamlElement = [buttonToTest _winrtXamlElement];
        ASSERT_TRUE(xamlElement);

        // Find buttonBorder in the visual tree
        dispatch_sync(dispatch_get_main_queue(), ^{
            buttonBorder = FindXamlChild(xamlElement, @"buttonBorder");
        });
        ASSERT_TRUE(buttonBorder);

        dispatch_sync(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(buttonBorder, Controls::Border::BackgroundProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                if (expectedColor) {
                    auto solidBrush = sender.GetValue(dp).as<Media::SolidColorBrush>();

                    // Validation
                    EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBrush, expectedColor));
                }
                else {
                    // In adjustsImageWhenHighlighted == NO scenario, we set the border background brush to nil
                    EXPECT_FALSE(sender.GetValue(dp));
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
        __block FrameworkElement buttonBorder = nullptr;
        __block StrongId<UIColor> expectedColor;

        FrameworkElement xamlElement = [buttonToTest _winrtXamlElement];
        ASSERT_TRUE(xamlElement);

        // Find buttonBorder in the visual tree
        dispatch_sync(dispatch_get_main_queue(), ^{
            buttonBorder = FindXamlChild(xamlElement, @"buttonBorder");
        });
        ASSERT_TRUE(buttonBorder);

        dispatch_sync(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(buttonBorder, Controls::Border::BackgroundProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                if (expectedColor) {
                    auto solidBrush = sender.GetValue(dp).as<Media::SolidColorBrush>();

                    // Validation
                    EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBrush, expectedColor));
                }
                else {
                    // In adjustsImageWhenDisabled == NO scenario, we set the border background brush to nil
                    EXPECT_FALSE(sender.GetValue(dp));
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
        FrameworkElement xamlElement = [buttonToTest.titleLabel _getXamlTextBlock];
        ASSERT_TRUE(xamlElement);

        dispatch_async(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(xamlElement, Controls::TextBlock::TextProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                NSString* text = UXTestAPI::NSStringFromPropertyValue(sender.GetValue(dp));
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
        FrameworkElement xamlElement = [buttonToTest.titleLabel _getXamlTextBlock];
        ASSERT_TRUE(xamlElement);

        dispatch_async(dispatch_get_main_queue(), ^{
            // Add some text which helps display the changes in all states during development
            [buttonVC textTitle].text = @"Functional testing";

            // Register RAII event subscription handler
            xamlSubscriber->Set(xamlElement, Controls::TextBlock::ForegroundProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                auto solidBrush = sender.GetValue(dp).as<Media::SolidColorBrush>();
                LOG_INFO("XAML solid color brush (rgba): %d,%d,%d,%d",
                         solidBrush.Color().R,
                         solidBrush.Color().G,
                         solidBrush.Color().B,
                         solidBrush.Color().A);

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

        auto uxEvent = UXEvent::CreateAuto();
        auto xamlSubscriber = std::make_shared<XamlEventSubscription>();
        __block NSString* expectedImage;

        // Extract UIButton.imageView control to verify its visual state
        FrameworkElement xamlElement = [buttonToTest.imageView _winrtXamlElement];
        ASSERT_TRUE(xamlElement);

        dispatch_async(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(xamlElement, Controls::Image::SourceProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                auto bitmapSource = sender.GetValue(dp).as<Media::Imaging::BitmapSource>();
                LOG_INFO("XAML bitmap dimensions: %dx%d", bitmapSource.PixelWidth(), bitmapSource.PixelHeight());

                NSString* imageDimensions = [NSString stringWithFormat:@"%dx%d.png", bitmapSource.PixelWidth(), bitmapSource.PixelHeight()];
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

        auto uxLayoutEvent = UXEvent::CreateManual();
        FrameworkElement layerContent = nullptr;
        FrameworkElement* layerContentAddr = &layerContent;

        auto uxEvent = UXEvent::CreateAuto();
        auto xamlSubscriber = std::make_shared<XamlEventSubscription>();
        __block NSString* expectedBackgroundImage;
        __block winrt::event_token ert;
        winrt::event_token* const ertAddr = &ert;

        FrameworkElement xamlElement = [buttonToTest _winrtXamlElement];
        ASSERT_TRUE(xamlElement);

        // Wait for the layerContent to be part of the visual tree
        dispatch_sync(dispatch_get_main_queue(), ^{
            ert = xamlElement.LayoutUpdated(objcwinrt::callback([layerContentAddr, uxLayoutEvent, ertAddr, xamlElement] (const WF::IInspectable&, const WF::IInspectable&) {
                // Initially there is no LayerContent element unless we set a background image
                if (!*layerContentAddr) {
                    // Initially there is no LayerContent element
                    *layerContentAddr = FindXamlChild(xamlElement, @"LayerContent");
                    if (*layerContentAddr) {
                        // Ignore further layout events
                        xamlElement.LayoutUpdated(*ertAddr);
                        uxLayoutEvent->Set();
                    }
                }
            }));

            // Set a default background image so we trigger the LayerContent XAML addition
            [buttonVC textBackgroundImage].text = @"yellow_background.jpg";
        });

        // Wait for the LayerContent to be present before running background image tests
        uxLayoutEvent->Wait(c_testTimeoutInSec);
        ASSERT_TRUE(layerContent);

        dispatch_sync(dispatch_get_main_queue(), ^{
            xamlSubscriber->Set(layerContent, Controls::Image::SourceProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                // Upon cleanup or dismissal of the view, LayerCoordinator sets the source to NULL which we should avoid
                WF::IInspectable rtObject = sender.GetValue(dp);
                if (rtObject) {
                    auto bitmapSource = rtObject.as<Media::Imaging::BitmapSource>();
                    LOG_INFO("XAML bitmap dimensions: %dx%d", bitmapSource.PixelWidth(), bitmapSource.PixelHeight());

                    NSString* imageDimensions =
                        [NSString stringWithFormat:@"%dx%d.png", bitmapSource.PixelWidth(), bitmapSource.PixelHeight()];
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

        FrameworkElement xamlElement = [buttonToTest.titleLabel _getXamlTextBlock];
        ASSERT_TRUE(xamlElement);
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

        FrameworkElement xamlImageElement = [buttonToTest.imageView _winrtXamlElement];
        ASSERT_TRUE(xamlImageElement);

        FrameworkElement xamlTitleElement = [buttonToTest.titleLabel _winrtXamlElement];
        ASSERT_TRUE(xamlTitleElement);

        dispatch_sync(dispatch_get_main_queue(), ^{
            [buttonVC textImageStateField].text = @"N;";
            [buttonVC textImage].text = @"50x50.png";

            [buttonVC textTitleStateField].text = @"N;";
            [buttonVC textTitle].text = @"Normal";
            [buttonVC textTitleColorStateField].text = @"N;";
            [buttonVC textTitleColor].text = @"redColor";

            // Register RAII event subscription handler
            xamlImageWidthSubscriber->Set(xamlImageElement, FrameworkElement::WidthProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                double width = DoubleFromPropertyValue(sender.GetValue(dp));

                // Validation
                EXPECT_EQ(width, 40.0f);
                uxEvent->Set();
            });
            xamlImageHeightSubscriber->Set(xamlImageElement, FrameworkElement::HeightProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                double height = DoubleFromPropertyValue(sender.GetValue(dp));

                // Validation
                EXPECT_EQ(height, 40.0f);
                uxEvent->Set();
            });
            xamlImageCanvasLeftSubscriber->Set(xamlImageElement, Controls::Canvas::LeftProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                double left = DoubleFromPropertyValue(sender.GetValue(dp));

                // Validation
                EXPECT_EQ(left, 80.0f);
                uxEvent->Set();
            });
            xamlImageCanvasTopSubscriber->Set(xamlImageElement, Controls::Canvas::TopProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                double top = DoubleFromPropertyValue(sender.GetValue(dp));

                // Validation
                EXPECT_EQ(top, 80.0f);
                uxEvent->Set();
            });
            xamlTitleWidthSubscriber->Set(xamlTitleElement, FrameworkElement::WidthProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                double width = DoubleFromPropertyValue(sender.GetValue(dp));

                // Validation
                EXPECT_EQ((int)width, 52);
                uxEvent->Set();
            });
            xamlTitleHeightSubscriber->Set(xamlTitleElement, FrameworkElement::HeightProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                double height = DoubleFromPropertyValue(sender.GetValue(dp));

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
            auto transformGroup = xamlTitleElement.RenderTransform().as<Media::TransformGroup>();
            EXPECT_TRUE(transformGroup);

            // Compare against the expected frame X and Y
            Media::Matrix matrix = transformGroup.Value();
            EXPECT_EQ(matrix.OffsetX, 98.0f);
            EXPECT_EQ(matrix.OffsetY, 90.0f);
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

        FrameworkElement xamlElement = [buttonToTest.titleLabel _winrtXamlElement];
        ASSERT_TRUE(xamlElement);

        dispatch_sync(dispatch_get_main_queue(), ^{
            [buttonVC textTitleStateField].text = @"N;";
            [buttonVC textTitle].text = @"Normal";
            [buttonVC textTitleColorStateField].text = @"N;";
            [buttonVC textTitleColor].text = @"redColor";

            // Register RAII event subscription handler
            xamlWidthSubscriber->Set(xamlElement, FrameworkElement::WidthProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                double width = DoubleFromPropertyValue(sender.GetValue(dp));

                // Validation - see #2155
                EXPECT_EQ((int)width, 40);
                uxEvent->Set();
            });
            xamlHeightSubscriber->Set(xamlElement, FrameworkElement::HeightProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                double height = DoubleFromPropertyValue(sender.GetValue(dp));

                // Validation
                EXPECT_EQ((int)height, 18);
                uxEvent->Set();
            });

            // Action
            [buttonVC textTitleEdgeInsets].text = @"{80.0f, 80.0f, 80.0f, 80.0f}";
        });

        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec, 2 /* signal count */), "FAILED: Waiting for property changed events timed out!");

        dispatch_sync(dispatch_get_main_queue(), ^{
            auto transformGroup = xamlElement.RenderTransform().as<Media::TransformGroup>();
            EXPECT_TRUE(transformGroup);

            // Compare against the expected frame X and Y - see #2155
            Media::Matrix matrix = transformGroup.Value();
            EXPECT_EQ(matrix.OffsetX, 80.0f);
            EXPECT_EQ(matrix.OffsetY, 90.0f);
        });
    }

    TEST_METHOD(UIButton_ImageEdgeInsets) {
        StrongId<UIButtonWithControlsViewController> buttonVC;
        buttonVC.attach([[UIButtonWithControlsViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(buttonVC, 2);
        LOG_INFO("UIButton_ImageEdgeInsets - present VC");

        UIButton* buttonToTest = [buttonVC defaultButton];

        __block auto uxEvent = UXEvent::CreateAuto();
        __block auto xamlWidthSubscriber = std::make_shared<XamlEventSubscription>();
        __block auto xamlHeightSubscriber = std::make_shared<XamlEventSubscription>();
        __block auto xamlCanvasLeftSubscriber = std::make_shared<XamlEventSubscription>();
        __block auto xamlCanvasTopSubscriber = std::make_shared<XamlEventSubscription>();

        // Extract UIButton.imageView control to verify its visual state
        FrameworkElement xamlElement = [buttonToTest.imageView _winrtXamlElement];
        ASSERT_TRUE(xamlElement);
        LOG_INFO("UIButton_ImageEdgeInsets - retrieve backing xaml element");

        dispatch_sync(dispatch_get_main_queue(), ^{
            [buttonVC textImageStateField].text = @"N;";
            [buttonVC textImage].text = @"50x50.png";

            // Register RAII event subscription handler
            xamlWidthSubscriber->Set(xamlElement, FrameworkElement::WidthProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                double width = DoubleFromPropertyValue(sender.GetValue(dp));
                LOG_INFO("UIButton_ImageEdgeInsets - width changed");

                // Validation
                EXPECT_EQ(width, 40.0f);
                uxEvent->Set();
            });
            xamlHeightSubscriber->Set(xamlElement, FrameworkElement::HeightProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                double height = DoubleFromPropertyValue(sender.GetValue(dp));
                LOG_INFO("UIButton_ImageEdgeInsets - height changed");

                // Validation
                EXPECT_EQ(height, 40.0f);
                uxEvent->Set();
            });
            xamlCanvasLeftSubscriber->Set(xamlElement, Controls::Canvas::LeftProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                double left = DoubleFromPropertyValue(sender.GetValue(dp));
                LOG_INFO("UIButton_ImageEdgeInsets - left changed");

                // Validation
                EXPECT_EQ(left, 80.0f);
                uxEvent->Set();
            });
            xamlCanvasTopSubscriber->Set(xamlElement, Controls::Canvas::TopProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                double top = DoubleFromPropertyValue(sender.GetValue(dp));
                LOG_INFO("UIButton_ImageEdgeInsets - top changed");

                // Validation
                EXPECT_EQ(top, 80.0f);
                uxEvent->Set();
            });

            // Action
            [buttonVC textImageEdgeInsets].text = @"{80.0f, 80.0f, 80.0f, 80.0f}";
            LOG_INFO("UIButton_ImageEdgeInsets - trigger imedgeEdgeInsets properties to change");
        });

        ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec, 4 /* signal count */), "FAILED: Waiting for property changed events timed out after 4 seconds!");
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
        FrameworkElement xamlElement = [buttonToTest.titleLabel _getXamlTextBlock];
        ASSERT_TRUE(xamlElement);

        dispatch_sync(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(xamlElement, Controls::TextBlock::TextProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                NSString* text = UXTestAPI::NSStringFromPropertyValue(sender.GetValue(dp));

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
        FrameworkElement xamlElement = [buttonToTest.titleLabel _getXamlTextBlock];
        ASSERT_TRUE(xamlElement);

        dispatch_async(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(xamlElement, Controls::TextBlock::ForegroundProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                auto solidBrush = sender.GetValue(dp).as<Media::SolidColorBrush>();

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
        FrameworkElement xamlElement = [buttonToTest.imageView _winrtXamlElement];
        ASSERT_TRUE(xamlElement);

        dispatch_async(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(xamlElement, Controls::Image::SourceProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                auto bitmapSource = sender.GetValue(dp).as<Media::Imaging::BitmapSource>();

                // Validation
                UIImage* image = buttonToTest.currentImage;
                EXPECT_EQ(bitmapSource.PixelWidth(), (int)image.size.width);
                EXPECT_EQ(bitmapSource.PixelHeight(), (int)image.size.height);
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
        FrameworkElement layerContent = nullptr;
        FrameworkElement* const layerContentAddr = &layerContent;

        auto uxEvent = UXEvent::CreateAuto();
        auto xamlSubscriber = std::make_shared<XamlEventSubscription>();
        __block NSString* expectedBackgroundImage = @"150x150.png";
        __block winrt::event_token ert;
        winrt::event_token* const ertAddr = &ert;

        FrameworkElement xamlElement = [buttonToTest _winrtXamlElement];
        ASSERT_TRUE(xamlElement);

        // Wait for the layerContent to be part of the visual tree
        dispatch_sync(dispatch_get_main_queue(), ^{
            LayoutUpdatedCallback callback(layerContentAddr, uxLayoutEvent, ertAddr, xamlElement);
            ert = xamlElement.LayoutUpdated(callback);

            // Set a default background image so we trigger the LayerContent XAML addition
            [buttonVC textBackgroundImage].text = expectedBackgroundImage;
        });

        // Wait for the LayerContent to be present before running background image tests
        uxLayoutEvent->Wait(c_testTimeoutInSec);
        ASSERT_TRUE(layerContent);

        dispatch_sync(dispatch_get_main_queue(), ^{
            xamlSubscriber->Set(layerContent, Controls::Image::SourceProperty(), ^(const DependencyObject& sender, const DependencyProperty& dp) {
                // Upon cleanup or dismissal of the view, LayerCoordinator sets the source to NULL which we should avoid
                WF::IInspectable rtObject = sender.GetValue(dp);
                if (rtObject) {
                    auto bitmapSource = rtObject.as<Media::Imaging::BitmapSource>();

                    // Validation
                    UIImage* image = buttonToTest.currentBackgroundImage;
                    EXPECT_EQ(bitmapSource.PixelWidth(), (int)image.size.width);
                    EXPECT_EQ(bitmapSource.PixelHeight(), (int)image.size.height);
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
        FrameworkElement xamlElement = [buttonToTest.imageView _winrtXamlElement];
        ASSERT_TRUE(xamlElement);
    }
};