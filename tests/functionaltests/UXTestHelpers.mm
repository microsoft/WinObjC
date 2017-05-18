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
#import "StringHelpers.h"
#import "CppWinRTHelpers.h"

using namespace winrt::Windows::UI::Xaml;

namespace UXTestAPI {

UIWindow* GetCurrentWindow() {
    return [[UIApplication sharedApplication] keyWindow];
}

FrameworkElement FindXamlChild(const FrameworkElement& parent, NSString* name) {
    FrameworkElement foundChild = nullptr;

    unsigned int childCount = Media::VisualTreeHelper::GetChildrenCount(parent);
    for (unsigned int i = 0; i < childCount && !foundChild; i++) {
        auto child = Media::VisualTreeHelper::GetChild(parent, i).as<FrameworkElement>();

        NSString* childName = objcwinrt::string(child.Name());
        if ([childName isEqualToString:name]) {
            foundChild = child;
            break;
        }

        // Recurse
        foundChild = FindXamlChild(child, name);
    }

    return foundChild;
}

void UIControlCheckStateTransition(
    UIControl* controlToTest, std::shared_ptr<UXEvent> waitForEvent, UIControlState controlState, SEL selector, id expectedValue) {
    LOG_INFO("State transition - current control state: %d", controlState);

    dispatch_sync(dispatch_get_main_queue(), ^{
        controlToTest.highlighted = controlState & UIControlStateHighlighted;
        controlToTest.selected = controlState & UIControlStateSelected;
        controlToTest.enabled = !(controlState & UIControlStateDisabled);
    });

    if (waitForEvent) {
        ASSERT_TRUE_MSG(waitForEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for state transition event failed!");
    }

    id currentValue = [controlToTest performSelector:selector];
    ASSERT_OBJCEQ(currentValue, expectedValue);
}

NSString* NSStringFromPropertyValue(const winrt::Windows::Foundation::IInspectable& rtPropertyValue) {
    auto propVal = rtPropertyValue.as<winrt::Windows::Foundation::IPropertyValue>();
    if (propVal) {
        return objcwinrt::string(propVal.GetString());
    }

    return nil;
}

double DoubleFromPropertyValue(const winrt::Windows::Foundation::IInspectable& rtPropertyValue) {
    auto propVal = rtPropertyValue.as<winrt::Windows::Foundation::IPropertyValue>();
    if (propVal) {
        return propVal.GetDouble();
    }

    return 0.0f;
}

bool IsRGBAEqual(const Media::SolidColorBrush& brush, UIColor* color) {
    CGFloat red, green, blue, alpha;
    [color getRed:&red green:&green blue:&blue alpha:&alpha];

    return brush.Color().R == (int)(red * 255) && brush.Color().G == (int)(green * 255) && brush.Color().B == (int)(blue * 255) &&
           brush.Color().A == (int)(alpha * 255);
}

//
// ViewControllerPresenter methods
//
ViewControllerPresenter::ViewControllerPresenter(UIViewController* viewController)
    : _externalViewController(viewController), _timeOutInSeconds(0.0f) {
    dispatch_sync(dispatch_get_main_queue(), ^{
        UIWindow* currentWindow = GetCurrentWindow();
        [currentWindow.rootViewController presentViewController:_externalViewController animated:NO completion:nil];
    });

    // Visually confirm that the view appears on screen
    [NSThread sleepForTimeInterval:_timeOutInSeconds];
}

ViewControllerPresenter::ViewControllerPresenter(UIViewController* viewController, double timeOutInSeconds)
    : _externalViewController(viewController), _timeOutInSeconds(timeOutInSeconds) {
    dispatch_sync(dispatch_get_main_queue(), ^{
        UIWindow* currentWindow = GetCurrentWindow();
        [currentWindow.rootViewController presentViewController:_externalViewController animated:NO completion:nil];
    });

    // Visually confirm that the view appears on screen
    [NSThread sleepForTimeInterval:_timeOutInSeconds];
}

ViewControllerPresenter::~ViewControllerPresenter() {
    // Visually confirm the view before it is dismissed
    [NSThread sleepForTimeInterval:_timeOutInSeconds];

    dispatch_sync(dispatch_get_main_queue(), ^{
        [_externalViewController dismissViewControllerAnimated:NO completion:nil];
    });

    // Visually confirm that viewcontroller is dismissed
    [NSThread sleepForTimeInterval:_timeOutInSeconds];
}

//
// XamlEventSubscription methods
//
void XamlEventSubscription::Set(const DependencyObject& xamlObject,
                                const DependencyProperty& propertyToObserve,
                                XamlEventBlock callbackHandler) {
    Reset();

    _xamlObject = xamlObject;
    _propertyToObserve = propertyToObserve;
    _eventBlock = [callbackHandler copy];

    // Register callback and wait for the property changed event to trigger
    _callbackToken = _xamlObject.RegisterPropertyChangedCallback(_propertyToObserve,
                                                                 objcwinrt::callback([this](const DependencyObject& sender,
                                                                                            const DependencyProperty& prop) {
                                                                     this->_eventBlock(sender, prop);
                                                                 }));
}

void XamlEventSubscription::Reset() {
    if (_callbackToken != -1) {
        _xamlObject.UnregisterPropertyChangedCallback(_propertyToObserve, _callbackToken);
        _callbackToken = -1;
    }

    _xamlObject = nullptr;
    _propertyToObserve = nullptr;

    [_eventBlock release];
    _eventBlock = nil;
}

//
// UXEvent methods
//
void UXEvent::Set() {
    [_condition lock];
    _signalCount++;

    if (_signalCount >= _signalCountTarget) {
        _signaled = true;
        [_condition signal];
    }

    [_condition unlock];
}

void UXEvent::Reset() {
    [_condition lock];
    _signaled = false;
    [_condition unlock];
}

bool UXEvent::Wait(int timeOutInSeconds) {
    [_condition lock];

    BOOL timeLimitReached = NO;
    while (!_signaled && !timeLimitReached) {
        timeLimitReached = ![_condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:timeOutInSeconds]];
    }

    bool waitSignal = _signaled;
    [_condition unlock];

    if (_eventType == AutoReset) {
        Reset();
    }

    return waitSignal;
}

bool UXEvent::Wait(int timeOutInSeconds, int signalCountTarget) {
    [_condition lock];
    _signalCountTarget = signalCountTarget;
    [_condition unlock];

    return Wait(timeOutInSeconds);
}

UIColor* ConvertWUColorToUIColor(const winrt::Windows::UI::Color& wuColor) {
    CGFloat r = wuColor.R / 255.0;
    CGFloat g = wuColor.G / 255.0;
    CGFloat b = wuColor.B / 255.0;
    CGFloat a = wuColor.A / 255.0;
    return [UIColor colorWithRed:r green:g blue:b alpha:a];
}

} // namespace UXTestAPI
