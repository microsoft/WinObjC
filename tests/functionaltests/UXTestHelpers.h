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

UIWindow* GetCurrentWindow();

NSString* NSStringFromPropertyValue(RTObject* rtPropertyValue);
NSString* NSStringFromPropertyValue(const Microsoft::WRL::ComPtr<IInspectable>& inspPropertyValue);

class ViewControllerHelper {
public:
    ViewControllerHelper(UIViewController* viewController) : _externalViewController(viewController) {
        dispatch_sync(dispatch_get_main_queue(), ^{
            UIWindow* currentWindow = GetCurrentWindow();
            [currentWindow.rootViewController presentViewController:_externalViewController animated:NO completion:nil];
        });

        // Uncomment this sleep - only used to visually confirm that the view appears on screen
        //[NSThread sleepForTimeInterval:3];
    }

    ~ViewControllerHelper() {
        // Uncomment this sleep - only used to visually confirm the view before it is dismissed
        //[NSThread sleepForTimeInterval:3];

        dispatch_sync(dispatch_get_main_queue(), ^{
            [_externalViewController dismissViewControllerAnimated:NO completion:nil];
        });

        // Uncomment this sleep - only used to visually confirm that viewcontroller is dismissed
        //[NSThread sleepForTimeInterval:3];
    }

private:
    StrongId<UIViewController> _externalViewController;
};

typedef void (^XamlEventBlock)(WXDependencyObject*, WXDependencyProperty*);

class XamlEventSubscription {
public:
    XamlEventSubscription(WXDependencyObject* xamlObject, WXDependencyProperty* propertyToObserve, XamlEventBlock callbackHandler)
        : _xamlObject(xamlObject), _propertyToObserve(propertyToObserve) {
        // Register callback and wait for the property changed event to trigger
        _callbackToken = [_xamlObject registerPropertyChangedCallback:_propertyToObserve
                                                             callback:^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                                                                 callbackHandler(sender, dp);
                                                             }];
    }

    ~XamlEventSubscription() {
        // Unregister the callback
        [_xamlObject unregisterPropertyChangedCallback:_propertyToObserve token:_callbackToken];
    }

private:
    int64_t _callbackToken;
    StrongId<WXDependencyObject> _xamlObject;
    StrongId<WXDependencyProperty> _propertyToObserve;
};
