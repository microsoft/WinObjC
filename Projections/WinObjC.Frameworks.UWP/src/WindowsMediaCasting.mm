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

// WindowsMediaCasting.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Casting.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaCasting.h"
#include "WindowsMediaCasting_priv.h"

@implementation WMCCastingSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Casting::ICastingSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFUri*)preferredSourceUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreferredSourceUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setPreferredSourceUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_PreferredSourceUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

@end

@implementation WMCCastingConnectionErrorOccurredEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Casting::ICastingConnectionErrorOccurredEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCCastingConnectionErrorStatus)errorStatus {
    ABI::Windows::Media::Casting::CastingConnectionErrorStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingConnectionErrorOccurredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorStatus(&unmarshalledReturn));
    return (WMCCastingConnectionErrorStatus)unmarshalledReturn;
}

- (NSString*)message {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingConnectionErrorOccurredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMCCastingDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Casting::ICastingDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::Casting::ICastingDeviceStatics> WMCICastingDeviceStatics_inst() {
    ComPtr<ABI::Windows::Media::Casting::ICastingDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Casting.CastingDevice").Get(), &inst));
    return inst;
}

+ (NSString*)getDeviceSelector:(WMCCastingPlaybackTypes)type {
    HSTRING unmarshalledReturn;
    auto _comInst = WMCICastingDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector((ABI::Windows::Media::Casting::CastingPlaybackTypes)type, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)getDeviceSelectorFromCastingSourceAsync:(WMCCastingSource*)castingSource
                                        success:(void (^)(NSString*))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WMCICastingDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromCastingSourceAsync(
        _getRtInterface<ABI::Windows::Media::Casting::ICastingSource>(castingSource).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

+ (void)fromIdAsync:(NSString*)value success:(void (^)(WMCCastingDevice*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Casting::CastingDevice*>> unmarshalledReturn;
    auto _comInst = WMCICastingDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(value).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Casting::CastingDevice*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Casting::CastingDevice*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Casting::ICastingDevice> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMCCastingDevice>(result.Get()));
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

+ (void)deviceInfoSupportsCastingAsync:(WDEDeviceInformation*)device success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WMCICastingDeviceStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->DeviceInfoSupportsCastingAsync(_getRtInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(device).Get(),
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
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)friendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_FriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WSSIRandomAccessStreamWithContentType>*)icon {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_Icon(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamWithContentType>(unmarshalledReturn.Get());
}

- (void)getSupportedCastingPlaybackTypesAsyncWithSuccess:(void (^)(WMCCastingPlaybackTypes))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Casting::CastingPlaybackTypes>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevice>(self);
    THROW_NS_IF_FAILED(_comInst->GetSupportedCastingPlaybackTypesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Casting::CastingPlaybackTypes>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Casting::CastingPlaybackTypes>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Media::Casting::CastingPlaybackTypes result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WMCCastingPlaybackTypes)result);
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

- (WMCCastingConnection*)createCastingConnection {
    ComPtr<ABI::Windows::Media::Casting::ICastingConnection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevice>(self);
    THROW_NS_IF_FAILED(_comInst->CreateCastingConnection(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCastingConnection>(unmarshalledReturn.Get());
}

@end

@implementation WMCCastingConnection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Casting::ICastingConnection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCCastingConnectionState)state {
    ABI::Windows::Media::Casting::CastingConnectionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingConnection>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WMCCastingConnectionState)unmarshalledReturn;
}

- (WMCCastingDevice*)device {
    ComPtr<ABI::Windows::Media::Casting::ICastingDevice> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingConnection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Device(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCastingDevice>(unmarshalledReturn.Get());
}

- (WMCCastingSource*)source {
    ComPtr<ABI::Windows::Media::Casting::ICastingSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingConnection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCastingSource>(unmarshalledReturn.Get());
}

- (void)setSource:(WMCCastingSource*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingConnection>(self);
    THROW_NS_IF_FAILED(_comInst->put_Source(_getRtInterface<ABI::Windows::Media::Casting::ICastingSource>(value).Get()));
}

- (EventRegistrationToken)addStateChangedEvent:(void (^)(WMCCastingConnection*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingConnection>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_StateChanged(Make<ITypedEventHandler_Windows_Media_Casting_CastingConnection_System_Object>(handler).Get(),
                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStateChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StateChanged(token));
}

- (EventRegistrationToken)addErrorOccurredEvent:(void (^)(WMCCastingConnection*, WMCCastingConnectionErrorOccurredEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_ErrorOccurred(
        Make<ITypedEventHandler_Windows_Media_Casting_CastingConnection_Windows_Media_Casting_CastingConnectionErrorOccurredEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeErrorOccurredEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ErrorOccurred(token));
}

- (void)requestStartCastingAsync:(WMCCastingSource*)value
                         success:(void (^)(WMCCastingConnectionErrorStatus))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Casting::CastingConnectionErrorStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingConnection>(self);
    THROW_NS_IF_FAILED(_comInst->RequestStartCastingAsync(_getRtInterface<ABI::Windows::Media::Casting::ICastingSource>(value).Get(),
                                                          &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Casting::CastingConnectionErrorStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Casting::CastingConnectionErrorStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Media::Casting::CastingConnectionErrorStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WMCCastingConnectionErrorStatus)result);
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

- (void)disconnectAsyncWithSuccess:(void (^)(WMCCastingConnectionErrorStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Casting::CastingConnectionErrorStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingConnection>(self);
    THROW_NS_IF_FAILED(_comInst->DisconnectAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Casting::CastingConnectionErrorStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Casting::CastingConnectionErrorStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Media::Casting::CastingConnectionErrorStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WMCCastingConnectionErrorStatus)result);
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMCCastingDeviceSelectedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Casting::ICastingDeviceSelectedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCCastingDevice*)selectedCastingDevice {
    ComPtr<ABI::Windows::Media::Casting::ICastingDevice> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDeviceSelectedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedCastingDevice(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCastingDevice>(unmarshalledReturn.Get());
}

@end

@implementation WMCCastingDevicePickerFilter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Casting::ICastingDevicePickerFilter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supportsAudio {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevicePickerFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportsAudio(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSupportsAudio:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevicePickerFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_SupportsAudio((boolean)value));
}

- (BOOL)supportsVideo {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevicePickerFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportsVideo(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSupportsVideo:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevicePickerFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_SupportsVideo((boolean)value));
}

- (BOOL)supportsPictures {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevicePickerFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportsPictures(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSupportsPictures:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevicePickerFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_SupportsPictures((boolean)value));
}

- (NSMutableArray* /* WMCCastingSource* */)supportedCastingSources {
    ComPtr<IVector<ABI::Windows::Media::Casting::CastingSource*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevicePickerFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedCastingSources(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WMCCastingSource_create(unmarshalledReturn.Get());
}

@end

@implementation WMCCastingDevicePicker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Casting::ICastingDevicePicker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Casting.CastingDevicePicker").Get(), &out));
    return [_createRtProxy<WMCCastingDevicePicker>(out.Get()) retain];
}

- (WMCCastingDevicePickerFilter*)filter {
    ComPtr<ABI::Windows::Media::Casting::ICastingDevicePickerFilter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_Filter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCastingDevicePickerFilter>(unmarshalledReturn.Get());
}

- (WDEDevicePickerAppearance*)appearance {
    ComPtr<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_Appearance(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDevicePickerAppearance>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addCastingDeviceSelectedEvent:(void (^)(WMCCastingDevicePicker*, WMCCastingDeviceSelectedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->add_CastingDeviceSelected(
        Make<ITypedEventHandler_Windows_Media_Casting_CastingDevicePicker_Windows_Media_Casting_CastingDeviceSelectedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCastingDeviceSelectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CastingDeviceSelected(token));
}

- (EventRegistrationToken)addCastingDevicePickerDismissedEvent:(void (^)(WMCCastingDevicePicker*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->add_CastingDevicePickerDismissed(
        Make<ITypedEventHandler_Windows_Media_Casting_CastingDevicePicker_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCastingDevicePickerDismissedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CastingDevicePickerDismissed(token));
}

- (void)show:(WFRect*)selection {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->Show(*[selection internalStruct]));
}

- (void)showWithPlacement:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->ShowWithPlacement(*[selection internalStruct], (ABI::Windows::UI::Popups::Placement)preferredPlacement));
}

- (void)hide {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Casting::ICastingDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->Hide());
}

@end

id RTProxiedNSMutableArray_WMCCastingSource_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Media::Casting::CastingSource*>,
                                                RTMutableArrayObj<ABI::Windows::Media::Casting::ICastingSource*,
                                                                  IVector<ABI::Windows::Media::Casting::CastingSource*>,
                                                                  WMCCastingSource,
                                                                  ABI::Windows::Media::Casting::CastingSource*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
