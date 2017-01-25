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

#import "UXTestHelpers.h"
#import "StringHelpers.h"

namespace UXTestAPI {

UIWindow* GetCurrentWindow() {
    return [[UIApplication sharedApplication] keyWindow];
}

NSString* NSStringFromPropertyValue(RTObject* rtPropertyValue) {
    // BUGBUG:8791977 - WFIPropertyValue is not publicly exposed via projections so we used a workaround
    Microsoft::WRL::ComPtr<IInspectable> inspPropVal = [rtPropertyValue comObj];
    return NSStringFromPropertyValue(inspPropVal);
}

NSString* NSStringFromPropertyValue(const Microsoft::WRL::ComPtr<IInspectable>& inspPropertyValue) {
    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::IPropertyValue> propVal;
    HRESULT hr = inspPropertyValue.As(&propVal);
    if (SUCCEEDED(hr)) {
        HSTRING str;
        auto freeHSTRING = wil::ScopeExit([&]() { WindowsDeleteString(str); });

        hr = propVal->GetString(&str);
        if (SUCCEEDED(hr)) {
            return Strings::WideToNSString<HSTRING>(str);
        }
    }

    return nil;
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
        // Unregister the callback
        [_xamlObject unregisterPropertyChangedCallback:_propertyToObserve token:_callbackToken];
        _callbackToken = -1;
    }
}

} // namespace UXTestAPI
