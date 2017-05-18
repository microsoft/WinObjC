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

#pragma once

// UX helper methods
#import <UIKit/UIKit.h>

#include <COMIncludes.h>
#import <WRLHelpers.h>
#import <ErrorHandling.h>
#import <RawBuffer.h>
#import <wrl/client.h>
#import <wrl/implements.h>
#import <wrl/async.h>
#import <wrl/wrappers/corewrappers.h>
#import <windows.foundation.h>
#import <winrt/Windows.UI.Xaml.h>
#import <winrt/Windows.UI.Xaml.Controls.h>
#include <COMIncludes_end.h>

#import "ObjCXamlControls.h"

namespace UXTestAPI {

using XamlEventBlock = void (^)(const winrt::Windows::UI::Xaml::DependencyObject&, const winrt::Windows::UI::Xaml::DependencyProperty&);

// Forward declaration
class UXEvent;

// Extract the current key window for the app
UIWindow* GetCurrentWindow();

// Walk the XAML child tree starting at control and find a child element matching name
winrt::Windows::UI::Xaml::FrameworkElement FindXamlChild(const winrt::Windows::UI::Xaml::FrameworkElement& parent, NSString* name);

// Looks at the UIControl for specified state and confirms that the expected value is present
void UIControlCheckStateTransition(
    UIControl* controlToTest, std::shared_ptr<UXEvent> waitForEvent, UIControlState controlState, SEL selector, id expectedValue);

// Utility string functions to convert PropertyValue types into NSString, primitive types, etc.
NSString* NSStringFromPropertyValue(const winrt::Windows::Foundation::IInspectable& rtPropertyValue);
double DoubleFromPropertyValue(const winrt::Windows::Foundation::IInspectable& rtPropertyValue);

// WUXMSolidColorBrush helper
bool IsRGBAEqual(const winrt::Windows::UI::Xaml::Media::SolidColorBrush& brush, UIColor* color);

// Class that is used to display and dismiss the viewController's view within the test
class ViewControllerPresenter {
public:
    ViewControllerPresenter(UIViewController* viewController);
    ViewControllerPresenter(UIViewController* viewController, double timeOutInSeconds);
    ~ViewControllerPresenter();

    ViewControllerPresenter(const ViewControllerPresenter& other) = delete; // no copy
    ViewControllerPresenter& operator=(const ViewControllerPresenter& other) = delete;

private:
    double _timeOutInSeconds;
    StrongId<UIViewController> _externalViewController;
}; // class ViewControllerPresenter

// Class to set user-supplied block to monitor XAML property changed events
class XamlEventSubscription {
public:
    XamlEventSubscription() : _callbackToken(-1), _xamlObject(nullptr), _propertyToObserve(nullptr), _eventBlock(nil) {
    }

    ~XamlEventSubscription() {
        Reset();
    }

    XamlEventSubscription(const XamlEventSubscription& other) = delete; // no copy
    XamlEventSubscription& operator=(const XamlEventSubscription& other) = delete;

    void Set(const winrt::Windows::UI::Xaml::DependencyObject& xamlObject,
             const winrt::Windows::UI::Xaml::DependencyProperty& propertyToObserve,
             XamlEventBlock callbackHandler);
    void Reset();

private:
    int64_t _callbackToken;

    winrt::Windows::UI::Xaml::DependencyObject _xamlObject;
    winrt::Windows::UI::Xaml::DependencyProperty _propertyToObserve;
    XamlEventBlock _eventBlock;
}; // class XamlEventSubscription

// Class used to signal and wait during a test run
class UXEvent {
public:
    enum EventType { Manual, AutoReset };

    static std::shared_ptr<UXEvent> CreateManual() {
        return std::make_shared<UXEvent>(Manual);
    }

    static std::shared_ptr<UXEvent> CreateAuto() {
        return std::make_shared<UXEvent>(AutoReset);
    }

    UXEvent(EventType eventType) : _eventType(eventType), _signaled(false), _signalCount(0), _signalCountTarget(0) {
        _condition.attach([[NSCondition alloc] init]);
    }

    UXEvent(const UXEvent& other) = delete; // no copy
    UXEvent& operator=(const UXEvent& other) = delete;

    void Set();
    void Reset();
    bool Wait(int timeoutInSeconds);
    bool Wait(int timeoutInSeconds, int signalCount);

private:
    bool _signaled;
    unsigned int _signalCount; // number of signal activations
    unsigned int _signalCountTarget; // target number of signal activations to reach before we signal

    EventType _eventType;
    StrongId<NSCondition> _condition;
}; // class UXEvent

UIColor* ConvertWUColorToUIColor(const winrt::Windows::UI::Color& wuColor);

} // namespace UXTestAPI
