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
#include <COMIncludes_end.h>

#import "ObjCXamlControls.h"
#import "UWP/WindowsUIXamlControls.h"

namespace UXTestAPI {

using XamlEventBlock = void (^)(WXDependencyObject*, WXDependencyProperty*);

// Extract the current key window for the app
UIWindow* GetCurrentWindow();

// Utility string functions to convert PropertyValue strings to NSString
NSString* NSStringFromPropertyValue(RTObject* rtPropertyValue);
NSString* NSStringFromPropertyValue(const Microsoft::WRL::ComPtr<IInspectable>& inspPropertyValue);

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
    XamlEventSubscription() : _callbackToken(-1) {
    }

    ~XamlEventSubscription() {
        Reset();
    }

    XamlEventSubscription(const XamlEventSubscription& other) = delete; // no copy
    XamlEventSubscription& operator=(const XamlEventSubscription& other) = delete;

    void Set(WXDependencyObject* xamlObject, WXDependencyProperty* propertyToObserve, XamlEventBlock callbackHandler);
    void Reset();

private:
    int64_t _callbackToken;
    StrongId<WXDependencyObject> _xamlObject;
    StrongId<WXDependencyProperty> _propertyToObserve;
}; // class XamlEventSubscription

} // namespace UXTestAPI
