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

// MicrosoftAdvertisingWinRTUI.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Microsoft.Advertising.WinRT.UI.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "MicrosoftAdvertisingWinRTUI.h"
#include "MicrosoftAdvertisingWinRTUI_priv.h"

@implementation MAWUIAdvertisingWebBrowser

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::IAdvertisingWebBrowser> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)getContainerWidth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::IAdvertisingWebBrowser>(self);
    THROW_NS_IF_FAILED(_comInst->GetContainerWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)getContainerHeight {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::IAdvertisingWebBrowser>(self);
    THROW_NS_IF_FAILED(_comInst->GetContainerHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)expand1:(WFUri*)uri expandProperties:(MAWUExpandProperties*)expandProperties isLegacyAd:(BOOL)isLegacyAd {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::IAdvertisingWebBrowser>(self);
    THROW_NS_IF_FAILED(_comInst->Expand1(
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
        _getRtInterface<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesPublicNonVirtuals>(expandProperties).Get(),
        (boolean)isLegacyAd));
}

- (void)expand2:(WFUri*)uri expandProperties:(MAWUExpandProperties*)expandProperties {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::IAdvertisingWebBrowser>(self);
    THROW_NS_IF_FAILED(_comInst->Expand2(
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
        _getRtInterface<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesPublicNonVirtuals>(expandProperties).Get()));
}

- (void)resize:(double)width height:(double)height {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::IAdvertisingWebBrowser>(self);
    THROW_NS_IF_FAILED(_comInst->Resize(width, height));
}

- (void)updateExpandProperties:(MAWUExpandProperties*)expandProps {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::IAdvertisingWebBrowser>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateExpandProperties(
        _getRtInterface<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesPublicNonVirtuals>(expandProps).Get()));
}

- (void)setUseCustomClose:(BOOL)useCustomClose {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::IAdvertisingWebBrowser>(self);
    THROW_NS_IF_FAILED(_comInst->SetUseCustomClose((boolean)useCustomClose));
}

- (void)raiseAdLoadFailedEvent:(NSString*)message {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::IAdvertisingWebBrowser>(self);
    THROW_NS_IF_FAILED(_comInst->RaiseAdLoadFailedEvent(nsStrToHstr(message).Get()));
}

- (void)closeExpandedView {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::IAdvertisingWebBrowser>(self);
    THROW_NS_IF_FAILED(_comInst->CloseExpandedView());
}

@end

@implementation MAWUAdErrorEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IAdErrorEventArgsPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (MAErrorCode)errorCode {
    ABI::Microsoft::Advertising::ErrorCode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdErrorEventArgsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (MAErrorCode)unmarshalledReturn;
}

- (NSString*)errorMessage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdErrorEventArgsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorMessage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation MAWUManipulationStateChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IManipulationStateChangedEventArgsPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IManipulationStateChangedEventArgsFactory>
MAWU__IManipulationStateChangedEventArgsFactory_inst() {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IManipulationStateChangedEventArgsFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Microsoft.Advertising.WinRT.UI.ManipulationStateChangedEventArgs").Get(), &inst));
    return inst;
}

+ (MAWUManipulationStateChangedEventArgs*)makeInstance1:(int)current last:(int)last {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IManipulationStateChangedEventArgsPublicNonVirtuals> unmarshalledReturn;
    auto _comInst = MAWU__IManipulationStateChangedEventArgsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance1(current, last, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<MAWUManipulationStateChangedEventArgs>(unmarshalledReturn.Get()) retain];
}

- (int)currentState {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IManipulationStateChangedEventArgsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentState(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)lastState {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IManipulationStateChangedEventArgsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastState(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation MAWUPointerMoveEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IPointerMoveEventArgsPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFPoint*)mouseCoordinate {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IPointerMoveEventArgsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_MouseCoordinate(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

@end

@implementation MAWUMouseWheelEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IMouseWheelEventArgsPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (MAWUPointerMoveEventArgs*)pointerCoordinate {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IPointerMoveEventArgsPublicNonVirtuals> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IMouseWheelEventArgsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerCoordinate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<MAWUPointerMoveEventArgs>(unmarshalledReturn.Get());
}

- (BOOL)ctrlKeyPressed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IMouseWheelEventArgsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_CtrlKeyPressed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)wheelDelta {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IMouseWheelEventArgsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_WheelDelta(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation MAWUPointerDownEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IPointerDownEventArgsPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (MAWUPointerMoveEventArgs*)pointerCoordinate {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IPointerMoveEventArgsPublicNonVirtuals> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IPointerDownEventArgsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerCoordinate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<MAWUPointerMoveEventArgs>(unmarshalledReturn.Get());
}

- (NSString*)pointerType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IPointerDownEventArgsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)keyCode {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IPointerDownEventArgsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation MAWUAdControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Microsoft.Advertising.WinRT.UI.AdControl").Get(), &out));
    return [_createRtProxy<MAWUAdControl>(out.Get()) retain];
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (EventRegistrationToken)addErrorOccurredEvent:(void (^)(RTObject*, MAWUAdErrorEventArgs*))__param0 {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->add_ErrorOccurred(Make<EventHandler_Microsoft_Advertising_WinRT_UI_AdErrorEventArgs>(__param0).Get(),
                                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeErrorOccurredEvent:(EventRegistrationToken)__param0 {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ErrorOccurred(__param0));
}

- (EventRegistrationToken)addAdRefreshedEvent:(void (^)(RTObject*, WXRoutedEventArgs*))__param0 {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->add_AdRefreshed(Make<EventHandler_Windows_UI_Xaml_RoutedEventArgs>(__param0).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAdRefreshedEvent:(EventRegistrationToken)__param0 {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AdRefreshed(__param0));
}

- (EventRegistrationToken)addIsEngagedChangedEvent:(void (^)(RTObject*, WXRoutedEventArgs*))__param0 {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_IsEngagedChanged(Make<EventHandler_Windows_UI_Xaml_RoutedEventArgs>(__param0).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeIsEngagedChangedEvent:(EventRegistrationToken)__param0 {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->remove_IsEngagedChanged(__param0));
}

- (EventRegistrationToken)addOnPointerUpEvent:(void (^)(RTObject*, WXRoutedEventArgs*))__param0 {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->add_OnPointerUp(Make<EventHandler_Windows_UI_Xaml_RoutedEventArgs>(__param0).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOnPointerUpEvent:(EventRegistrationToken)__param0 {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OnPointerUp(__param0));
}

- (EventRegistrationToken)addOnPointerDownEvent:(void (^)(RTObject*, MAWUPointerDownEventArgs*))__param0 {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->add_OnPointerDown(Make<EventHandler_Microsoft_Advertising_WinRT_UI_PointerDownEventArgs>(__param0).Get(),
                                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOnPointerDownEvent:(EventRegistrationToken)__param0 {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OnPointerDown(__param0));
}

- (EventRegistrationToken)addOnMouseWheelEvent:(void (^)(RTObject*, MAWUMouseWheelEventArgs*))__param0 {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->add_OnMouseWheel(Make<EventHandler_Microsoft_Advertising_WinRT_UI_MouseWheelEventArgs>(__param0).Get(),
                                                  &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOnMouseWheelEvent:(EventRegistrationToken)__param0 {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OnMouseWheel(__param0));
}

- (EventRegistrationToken)addOnPointerMoveEvent:(void (^)(RTObject*, MAWUPointerMoveEventArgs*))__param0 {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->add_OnPointerMove(Make<EventHandler_Microsoft_Advertising_WinRT_UI_PointerMoveEventArgs>(__param0).Get(),
                                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOnPointerMoveEvent:(EventRegistrationToken)__param0 {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OnPointerMove(__param0));
}

- (EventRegistrationToken)addOnManipulationStateChangedEvent:(void (^)(RTObject*, MAWUManipulationStateChangedEventArgs*))__param0 {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->add_OnManipulationStateChanged(
        Make<EventHandler_Microsoft_Advertising_WinRT_UI_ManipulationStateChangedEventArgs>(__param0).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOnManipulationStateChangedEvent:(EventRegistrationToken)__param0 {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OnManipulationStateChanged(__param0));
}

- (NSString*)adUnitId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdUnitId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAdUnitId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_AdUnitId(nsStrToHstr(value).Get()));
}

- (NSString*)applicationId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApplicationId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setApplicationId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_ApplicationId(nsStrToHstr(value).Get()));
}

- (BOOL)isEngaged {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEngaged(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isAutoRefreshEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAutoRefreshEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsAutoRefreshEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsAutoRefreshEnabled((boolean)value));
}

- (int)autoRefreshIntervalInSeconds {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoRefreshIntervalInSeconds(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setAutoRefreshIntervalInSeconds:(int)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoRefreshIntervalInSeconds(value));
}

- (NSString*)keywords {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Keywords(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setKeywords:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_Keywords(nsStrToHstr(value).Get()));
}

- (NSString*)countryOrRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_CountryOrRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCountryOrRegion:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_CountryOrRegion(nsStrToHstr(value).Get()));
}

- (NSString*)postalCode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_PostalCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPostalCode:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_PostalCode(nsStrToHstr(value).Get()));
}

- (BOOL)isSuspended {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSuspended(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)hasAd {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasAd(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)refresh1 {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->Refresh1());
}

- (void)addAdTag:(NSString*)tagName tagValue:(NSString*)tagValue {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->AddAdTag(nsStrToHstr(tagName).Get(), nsStrToHstr(tagValue).Get()));
}

- (void)removeAdTag:(NSString*)tagName {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAdTag(nsStrToHstr(tagName).Get()));
}

- (void)suspend {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->Suspend());
}

- (void)resume {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IAdControlPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->Resume());
}

@end

@implementation MAWUExpandProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesFactory> MAWU__IExpandPropertiesFactory_inst() {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Microsoft.Advertising.WinRT.UI.ExpandProperties").Get(),
                                                       &inst));
    return inst;
}

+ (MAWUExpandProperties*)makeInstance1:(int)width
                                height:(int)height
                        useCustomClose:(BOOL)useCustomClose
                       lockOrientation:(BOOL)lockOrientation {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesPublicNonVirtuals> unmarshalledReturn;
    auto _comInst = MAWU__IExpandPropertiesFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateInstance1(width, height, (boolean)useCustomClose, (boolean)lockOrientation, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<MAWUExpandProperties>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesStatics> MAWU__IExpandPropertiesStatics_inst() {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Microsoft.Advertising.WinRT.UI.ExpandProperties").Get(),
                                                       &inst));
    return inst;
}

+ (MAWUExpandProperties*)getDefault {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesPublicNonVirtuals> unmarshalledReturn;
    auto _comInst = MAWU__IExpandPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<MAWUExpandProperties>(unmarshalledReturn.Get());
}

- (int)width {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Width(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setWidth:(int)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_Width(value));
}

- (int)height {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setHeight:(int)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_Height(value));
}

- (BOOL)useCustomClose {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_UseCustomClose(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setUseCustomClose:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_UseCustomClose((boolean)value));
}

- (BOOL)isModal {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsModal(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)lockOrientation {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_LockOrientation(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setLockOrientation:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IExpandPropertiesPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_LockOrientation((boolean)value));
}

@end

@implementation MAWUblank

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IblankPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Microsoft.Advertising.WinRT.UI.blank").Get(), &out));
    return [_createRtProxy<MAWUblank>(out.Get()) retain];
}

- (void)connect:(int)connectionId target:(RTObject*)target {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IComponentConnector>(self);
    THROW_NS_IF_FAILED(_comInst->Connect(connectionId, [target comObj].Get()));
}

- (RTObject<WUXMIComponentConnector>*)getBindingConnector:(int)connectionId target:(RTObject*)target {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IComponentConnector> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IComponentConnector2>(self);
    THROW_NS_IF_FAILED(_comInst->GetBindingConnector(connectionId, [target comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMIComponentConnector>(unmarshalledReturn.Get());
}

- (void)initializeComponent {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IblankPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->InitializeComponent());
}

@end

@implementation MAWUInterstitialAd

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Microsoft.Advertising.WinRT.UI.InterstitialAd").Get(), &out));
    return [_createRtProxy<MAWUInterstitialAd>(out.Get()) retain];
}

- (void)requestAd1:(MAWUAdType)adType applicationId:(NSString*)applicationId adUnitId:(NSString*)adUnitId {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->RequestAd1((ABI::Microsoft::Advertising::WinRT::UI::AdType)adType,
                                            nsStrToHstr(applicationId).Get(),
                                            nsStrToHstr(adUnitId).Get()));
}

- (void)show {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->Show());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (void)addAdTag:(NSString*)tagName tagValue:(NSString*)tagValue {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->AddAdTag(nsStrToHstr(tagName).Get(), nsStrToHstr(tagValue).Get()));
}

- (void)removeAdTag:(NSString*)tagName {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAdTag(nsStrToHstr(tagName).Get()));
}

- (MAWUInterstitialAdState)state {
    ABI::Microsoft::Advertising::WinRT::UI::InterstitialAdState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (MAWUInterstitialAdState)unmarshalledReturn;
}

- (unsigned int)requestTimeout {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestTimeout(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRequestTimeout:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_RequestTimeout(value));
}

- (NSString*)keywords {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Keywords(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setKeywords:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_Keywords(nsStrToHstr(value).Get()));
}

- (NSString*)countryOrRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_CountryOrRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCountryOrRegion:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_CountryOrRegion(nsStrToHstr(value).Get()));
}

- (NSString*)postalCode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_PostalCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPostalCode:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_PostalCode(nsStrToHstr(value).Get()));
}

- (EventRegistrationToken)addAdReadyEvent:(void (^)(RTObject*, RTObject*))__param0 {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->add_AdReady(Make<EventHandler_System_Object>(__param0).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAdReadyEvent:(EventRegistrationToken)__param0 {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AdReady(__param0));
}

- (EventRegistrationToken)addCompletedEvent:(void (^)(RTObject*, RTObject*))__param0 {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->add_Completed(Make<EventHandler_System_Object>(__param0).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCompletedEvent:(EventRegistrationToken)__param0 {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Completed(__param0));
}

- (EventRegistrationToken)addCancelledEvent:(void (^)(RTObject*, RTObject*))__param0 {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->add_Cancelled(Make<EventHandler_System_Object>(__param0).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCancelledEvent:(EventRegistrationToken)__param0 {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Cancelled(__param0));
}

- (EventRegistrationToken)addErrorOccurredEvent:(void (^)(RTObject*, MAWUAdErrorEventArgs*))__param0 {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->add_ErrorOccurred(Make<EventHandler_Microsoft_Advertising_WinRT_UI_AdErrorEventArgs>(__param0).Get(),
                                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeErrorOccurredEvent:(EventRegistrationToken)__param0 {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IInterstitialAdPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ErrorOccurred(__param0));
}

@end

@implementation MAWUVpaidEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::WinRT::UI::__IVpaidEventArgsPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)eventName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IVpaidEventArgsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_EventName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)message {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::WinRT::UI::__IVpaidEventArgsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

id RTProxiedIterableNSArray_RTProxiedIterableNSArray_WFPoint_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<IterableArrayAdapterObj<
        IIterable<IIterable<ABI::Windows::Foundation::Point>*>,
        RTIterableObj<IIterable<ABI::Windows::Foundation::Point>*,
                      IIterable<IIterable<ABI::Windows::Foundation::Point>*>,
                      RTProxiedIterableNSArray,
                      IIterable<ABI::Windows::Foundation::Point>*,
                      RTProxiedIterableNSArray_WFPoint_create,
                      ConvertToIterable<RTProxiedIterableNSArray,
                                        ABI::Windows::Foundation::Internal::AggregateType<IIterable<ABI::Windows::Foundation::Point>*,
                                                                                          IIterable<ABI::Windows::Foundation::Point>*>,
                                        RTProxiedIterableNSArray_WFPoint_create>>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WFPoint_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Foundation::Point>,
                                                 RTIterableObj<ABI::Windows::Foundation::Point,
                                                               IIterable<ABI::Windows::Foundation::Point>,
                                                               WFPoint,
                                                               ABI::Windows::Foundation::Point,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_Single_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<float>, RTArrayObj<float, IVectorView<float>, float, float, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WUXIPointer_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Xaml::Input::Pointer*>,
                                         RTArrayObj<ABI::Windows::UI::Xaml::Input::IPointer*,
                                                    IVectorView<ABI::Windows::UI::Xaml::Input::Pointer*>,
                                                    WUXIPointer,
                                                    ABI::Windows::UI::Xaml::Input::Pointer*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
