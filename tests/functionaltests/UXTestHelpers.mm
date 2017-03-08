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

namespace UXTestAPI {

UIWindow* GetCurrentWindow() {
    return [[UIApplication sharedApplication] keyWindow];
}

WXFrameworkElement* FindXamlChild(WXFrameworkElement* parent, NSString* name) {
    WXFrameworkElement* foundChild = nullptr;

    unsigned int childCount = [WUXMVisualTreeHelper getChildrenCount:parent];
    for (unsigned int i = 0; i < childCount && !foundChild; i++) {
        WXFrameworkElement* child = rt_dynamic_cast<WXFrameworkElement>([WUXMVisualTreeHelper getChild:parent childIndex:i]);

        NSString* childName = [child name];
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

NSString* NSStringFromPropertyValue(RTObject* rtPropertyValue) {
    WFIPropertyValue* propVal = rt_dynamic_cast<WFIPropertyValue>(rtPropertyValue);
    if (propVal) {
        return [propVal getString];
    }

    return nil;
}

double DoubleFromPropertyValue(RTObject* rtPropertyValue) {
    WFIPropertyValue* propVal = rt_dynamic_cast<WFIPropertyValue>(rtPropertyValue);
    if (propVal) {
        return [propVal getDouble];
    }

    return 0.0f;
}

bool IsRGBAEqual(WUXMSolidColorBrush* brush, UIColor* color) {
    CGFloat red, green, blue, alpha;
    [color getRed:&red green:&green blue:&blue alpha:&alpha];

    return [brush.color r] == (int)(red * 255) && [brush.color g] == (int)(green * 255) && [brush.color b] == (int)(blue * 255) &&
           [brush.color a] == (int)(alpha * 255);
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
void XamlEventSubscription::Set(WXDependencyObject* xamlObject, WXDependencyProperty* propertyToObserve, XamlEventBlock callbackHandler) {
    Reset();

    _xamlObject = xamlObject;
    _propertyToObserve = propertyToObserve;

    // Register callback and wait for the property changed event to trigger
    _callbackToken = [_xamlObject registerPropertyChangedCallback:_propertyToObserve
                                                         callback:^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                                                             callbackHandler(sender, dp);
                                                         }];
}

void XamlEventSubscription::Reset() {
    if (_callbackToken != -1) {
        [_xamlObject unregisterPropertyChangedCallback:_propertyToObserve token:_callbackToken];
        _callbackToken = -1;
    }

    _xamlObject = nil;
    _propertyToObserve = nil;
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

} // namespace UXTestAPI
