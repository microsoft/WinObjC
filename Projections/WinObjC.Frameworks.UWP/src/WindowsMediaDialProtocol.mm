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

// WindowsMediaDialProtocol.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.DialProtocol.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaDialProtocol.h"
#include "WindowsMediaDialProtocol_priv.h"

@implementation WMDDialAppStateDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::DialProtocol::IDialAppStateDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMDDialAppState)state {
    ABI::Windows::Media::DialProtocol::DialAppState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialAppStateDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WMDDialAppState)unmarshalledReturn;
}

- (NSString*)fullXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialAppStateDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_FullXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMDDialApp

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::DialProtocol::IDialApp> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)appName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialApp>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)requestLaunchAsync:(NSString*)appArgument success:(void (^)(WMDDialAppLaunchResult))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::DialProtocol::DialAppLaunchResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialApp>(self);
    THROW_NS_IF_FAILED(_comInst->RequestLaunchAsync(nsStrToHstr(appArgument).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::DialProtocol::DialAppLaunchResult>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::DialProtocol::DialAppLaunchResult>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Media::DialProtocol::DialAppLaunchResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WMDDialAppLaunchResult)result);
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)stopAsyncWithSuccess:(void (^)(WMDDialAppStopResult))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::DialProtocol::DialAppStopResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialApp>(self);
    THROW_NS_IF_FAILED(_comInst->StopAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::DialProtocol::DialAppStopResult>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::DialProtocol::DialAppStopResult>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Media::DialProtocol::DialAppStopResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WMDDialAppStopResult)result);
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getAppStateAsyncWithSuccess:(void (^)(WMDDialAppStateDetails*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::DialProtocol::DialAppStateDetails*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialApp>(self);
    THROW_NS_IF_FAILED(_comInst->GetAppStateAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::DialProtocol::DialAppStateDetails*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::DialProtocol::DialAppStateDetails*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::DialProtocol::IDialAppStateDetails> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDialAppStateDetails>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WMDDialDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::DialProtocol::IDialDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::DialProtocol::IDialDeviceStatics> WMDIDialDeviceStatics_inst() {
    ComPtr<ABI::Windows::Media::DialProtocol::IDialDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.DialProtocol.DialDevice").Get(), &inst));
    return inst;
}

+ (NSString*)getDeviceSelector:(NSString*)appName {
    HSTRING unmarshalledReturn;
    auto _comInst = WMDIDialDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(nsStrToHstr(appName).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)fromIdAsync:(NSString*)value success:(void (^)(WMDDialDevice*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::DialProtocol::DialDevice*>> unmarshalledReturn;
    auto _comInst = WMDIDialDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(value).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::DialProtocol::DialDevice*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::DialProtocol::DialDevice*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::DialProtocol::IDialDevice> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMDDialDevice>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)deviceInfoSupportsDialAsync:(WDEDeviceInformation*)device success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WMDIDialDeviceStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->DeviceInfoSupportsDialAsync(_getRtInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(device).Get(),
                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMDDialApp*)getDialApp:(NSString*)appName {
    ComPtr<ABI::Windows::Media::DialProtocol::IDialApp> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->GetDialApp(nsStrToHstr(appName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDDialApp>(unmarshalledReturn.Get());
}

- (NSString*)friendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevice2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WSSIRandomAccessStreamReference>*)thumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevice2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

@end

@implementation WMDDialDeviceSelectedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::DialProtocol::IDialDeviceSelectedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMDDialDevice*)selectedDialDevice {
    ComPtr<ABI::Windows::Media::DialProtocol::IDialDevice> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDeviceSelectedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedDialDevice(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDDialDevice>(unmarshalledReturn.Get());
}

@end

@implementation WMDDialDisconnectButtonClickedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMDDialDevice*)device {
    ComPtr<ABI::Windows::Media::DialProtocol::IDialDevice> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Device(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDDialDevice>(unmarshalledReturn.Get());
}

@end

@implementation WMDDialDevicePickerFilter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::DialProtocol::IDialDevicePickerFilter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSMutableArray* /* NSString * */)supportedAppNames {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevicePickerFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedAppNames(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WMDDialDevicePicker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::DialProtocol::IDialDevicePicker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.DialProtocol.DialDevicePicker").Get(), &out));
    return [_createRtProxy<WMDDialDevicePicker>(out.Get()) retain];
}

- (WMDDialDevicePickerFilter*)filter {
    ComPtr<ABI::Windows::Media::DialProtocol::IDialDevicePickerFilter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_Filter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDDialDevicePickerFilter>(unmarshalledReturn.Get());
}

- (WDEDevicePickerAppearance*)appearance {
    ComPtr<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_Appearance(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDevicePickerAppearance>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addDialDeviceSelectedEvent:(void (^)(WMDDialDevicePicker*, WMDDialDeviceSelectedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->add_DialDeviceSelected(
        Make<ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_Windows_Media_DialProtocol_DialDeviceSelectedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDialDeviceSelectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DialDeviceSelected(token));
}

- (EventRegistrationToken)addDisconnectButtonClickedEvent:(void (^)(WMDDialDevicePicker*,
                                                                    WMDDialDisconnectButtonClickedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->add_DisconnectButtonClicked(
        Make<
            ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_Windows_Media_DialProtocol_DialDisconnectButtonClickedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDisconnectButtonClickedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DisconnectButtonClicked(token));
}

- (EventRegistrationToken)addDialDevicePickerDismissedEvent:(void (^)(WMDDialDevicePicker*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->add_DialDevicePickerDismissed(
        Make<ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDialDevicePickerDismissedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DialDevicePickerDismissed(token));
}

- (void)show:(WFRect*)selection {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->Show(*[selection internalStruct]));
}

- (void)showWithPlacement:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->ShowWithPlacement(*[selection internalStruct], (ABI::Windows::UI::Popups::Placement)preferredPlacement));
}

- (void)pickSingleDialDeviceAsync:(WFRect*)selection success:(void (^)(WMDDialDevice*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::DialProtocol::DialDevice*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->PickSingleDialDeviceAsync(*[selection internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::DialProtocol::DialDevice*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::DialProtocol::DialDevice*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::DialProtocol::IDialDevice> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMDDialDevice>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)pickSingleDialDeviceAsyncWithPlacement:(WFRect*)selection
                            preferredPlacement:(WUPPlacement)preferredPlacement
                                       success:(void (^)(WMDDialDevice*))success
                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::DialProtocol::DialDevice*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->PickSingleDialDeviceAsyncWithPlacement(*[selection internalStruct],
                                                                        (ABI::Windows::UI::Popups::Placement)preferredPlacement,
                                                                        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::DialProtocol::DialDevice*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::DialProtocol::DialDevice*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::DialProtocol::IDialDevice> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMDDialDevice>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)hide {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->Hide());
}

- (void)setDisplayStatus:(WMDDialDevice*)device status:(WMDDialDeviceDisplayStatus)status {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::DialProtocol::IDialDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->SetDisplayStatus(_getRtInterface<ABI::Windows::Media::DialProtocol::IDialDevice>(device).Get(),
                                                  (ABI::Windows::Media::DialProtocol::DialDeviceDisplayStatus)status));
}

@end

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
