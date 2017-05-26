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

// WindowsDevicesEnumeration.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Enumeration.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesEnumeration.h"
#include "WindowsDevicesEnumeration_priv.h"

@implementation WDEIDevicePairingSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDevicePairingSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WDEDeviceConnectionChangeTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceConnectionChangeTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceConnectionChangeTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDEDevicePickerAppearance

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (WUColor*)foregroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->get_ForegroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setForegroundColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->put_ForegroundColor(*[value internalStruct]));
}

- (WUColor*)backgroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackgroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setBackgroundColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->put_BackgroundColor(*[value internalStruct]));
}

- (WUColor*)accentColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccentColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setAccentColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->put_AccentColor(*[value internalStruct]));
}

- (WUColor*)selectedForegroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedForegroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setSelectedForegroundColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedForegroundColor(*[value internalStruct]));
}

- (WUColor*)selectedBackgroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedBackgroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setSelectedBackgroundColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedBackgroundColor(*[value internalStruct]));
}

- (WUColor*)selectedAccentColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedAccentColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setSelectedAccentColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedAccentColor(*[value internalStruct]));
}

@end

@implementation WDEDeviceSelectedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceSelectedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDEDeviceInformation*)selectedDevice {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceSelectedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedDevice(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformation>(unmarshalledReturn.Get());
}

@end

@implementation WDEDeviceDisconnectButtonClickedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceDisconnectButtonClickedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDEDeviceInformation*)device {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceDisconnectButtonClickedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Device(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformation>(unmarshalledReturn.Get());
}

@end

@implementation WDEDevicePickerFilter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDevicePickerFilter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSMutableArray* /* WDEDeviceClass */)supportedDeviceClasses {
    ComPtr<IVector<ABI::Windows::Devices::Enumeration::DeviceClass>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePickerFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedDeviceClasses(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDEDeviceClass_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* NSString * */)supportedDeviceSelectors {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePickerFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedDeviceSelectors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WDEDevicePicker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDevicePicker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Enumeration.DevicePicker").Get(), &out));
    return [_createRtProxy<WDEDevicePicker>(out.Get()) retain];
}

- (WDEDevicePickerFilter*)filter {
    ComPtr<ABI::Windows::Devices::Enumeration::IDevicePickerFilter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_Filter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDevicePickerFilter>(unmarshalledReturn.Get());
}

- (WDEDevicePickerAppearance*)appearance {
    ComPtr<ABI::Windows::Devices::Enumeration::IDevicePickerAppearance> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_Appearance(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDevicePickerAppearance>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* NSString * */)requestedProperties {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestedProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addDeviceSelectedEvent:(void (^)(WDEDevicePicker*, WDEDeviceSelectedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->add_DeviceSelected(
        Make<ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_Windows_Devices_Enumeration_DeviceSelectedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDeviceSelectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DeviceSelected(token));
}

- (EventRegistrationToken)addDisconnectButtonClickedEvent:(void (^)(WDEDevicePicker*, WDEDeviceDisconnectButtonClickedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->add_DisconnectButtonClicked(
        Make<
            ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_Windows_Devices_Enumeration_DeviceDisconnectButtonClickedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDisconnectButtonClickedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DisconnectButtonClicked(token));
}

- (EventRegistrationToken)addDevicePickerDismissedEvent:(void (^)(WDEDevicePicker*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePicker>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_DevicePickerDismissed(Make<ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_System_Object>(handler).Get(),
                                            &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDevicePickerDismissedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DevicePickerDismissed(token));
}

- (void)show:(WFRect*)selection {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->Show(*[selection internalStruct]));
}

- (void)showWithPlacement:(WFRect*)selection placement:(WUPPlacement)placement {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->ShowWithPlacement(*[selection internalStruct], (ABI::Windows::UI::Popups::Placement)placement));
}

- (void)pickSingleDeviceAsync:(WFRect*)selection success:(void (^)(WDEDeviceInformation*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->PickSingleDeviceAsync(*[selection internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DeviceInformation*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformation*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDeviceInformation>(result.Get()));
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

- (void)pickSingleDeviceAsyncWithPlacement:(WFRect*)selection
                                 placement:(WUPPlacement)placement
                                   success:(void (^)(WDEDeviceInformation*))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->PickSingleDeviceAsyncWithPlacement(*[selection internalStruct],
                                                                    (ABI::Windows::UI::Popups::Placement)placement,
                                                                    &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DeviceInformation*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformation*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDeviceInformation>(result.Get()));
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
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->Hide());
}

- (void)setDisplayStatus:(WDEDeviceInformation*)device status:(NSString*)status options:(WDEDevicePickerDisplayStatusOptions)options {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePicker>(self);
    THROW_NS_IF_FAILED(_comInst->SetDisplayStatus(_getRtInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(device).Get(),
                                                  nsStrToHstr(status).Get(),
                                                  (ABI::Windows::Devices::Enumeration::DevicePickerDisplayStatusOptions)options));
}

@end

@implementation WDEDeviceThumbnail

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (uint64_t)size {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSize:(uint64_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->put_Size(value));
}

- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->GetInputStreamAt(position, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->GetOutputStreamAt(position, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIOutputStream>(unmarshalledReturn.Get());
}

- (uint64_t)position {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)seek:(uint64_t)position {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->Seek(position));
}

- (RTObject<WSSIRandomAccessStream>*)cloneStream {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->CloneStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStream>(unmarshalledReturn.Get());
}

- (BOOL)canRead {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanRead(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canWrite {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanWrite(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned int)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, unsigned int>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IInputStream>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(),
                                           count,
                                           (ABI::Windows::Storage::Streams::InputStreamOptions)options,
                                           &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IBuffer*, unsigned int>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, unsigned int>* op,
                         unsigned int status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*, unsigned int>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, unsigned int>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned int))success
          progress:(void (^)(unsigned int))progress
           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IOutputStream>(self);
    THROW_NS_IF_FAILED(_comInst->WriteAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<unsigned int, unsigned int>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>* op, unsigned int status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<unsigned int, unsigned int>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    unsigned int result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
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

- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IOutputStream>(self);
    THROW_NS_IF_FAILED(_comInst->FlushAsync(&unmarshalledReturn));

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

- (NSString*)contentType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IContentTypeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDEEnclosureLocation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IEnclosureLocation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)inDock {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IEnclosureLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_InDock(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)inLid {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IEnclosureLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_InLid(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDEPanel)panel {
    ABI::Windows::Devices::Enumeration::Panel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IEnclosureLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Panel(&unmarshalledReturn));
    return (WDEPanel)unmarshalledReturn;
}

- (unsigned int)rotationAngleInDegreesClockwise {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IEnclosureLocation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationAngleInDegreesClockwise(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDEDeviceInformationUpdate

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationUpdate> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationUpdate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSDictionary* /* NSString *, RTObject* */)properties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationUpdate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

- (WDEDeviceInformationKind)kind {
    ABI::Windows::Devices::Enumeration::DeviceInformationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationUpdate2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WDEDeviceInformationKind)unmarshalledReturn;
}

@end

@implementation WDEDeviceInformationCollection {
    RTArrayObj<ABI::Windows::Devices::Enumeration::IDeviceInformation*,
               IVectorView<ABI::Windows::Devices::Enumeration::DeviceInformation*>,
               WDEDeviceInformation,
               ABI::Windows::Devices::Enumeration::DeviceInformation*,
               dummyObjCCreator,
               dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTORVIEW_FULL(self.comObj,
                             WDEDeviceInformation,
                             ABI::Windows::Devices::Enumeration::IDeviceInformation*,
                             ABI::Windows::Devices::Enumeration::DeviceInformation*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVectorView<ABI::Windows::Devices::Enumeration::DeviceInformation*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WDEDeviceWatcher

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceWatcher> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addAddedEvent:(void (^)(WDEDeviceWatcher*, WDEDeviceInformation*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Added(
        Make<ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_Windows_Devices_Enumeration_DeviceInformation>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAddedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Added(token));
}

- (EventRegistrationToken)addUpdatedEvent:(void (^)(WDEDeviceWatcher*, WDEDeviceInformationUpdate*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Updated(
        Make<ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_Windows_Devices_Enumeration_DeviceInformationUpdate>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Updated(token));
}

- (EventRegistrationToken)addRemovedEvent:(void (^)(WDEDeviceWatcher*, WDEDeviceInformationUpdate*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Removed(
        Make<ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_Windows_Devices_Enumeration_DeviceInformationUpdate>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Removed(token));
}

- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WDEDeviceWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcher>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_EnumerationCompleted(Make<ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_System_Object>(handler).Get(),
                                           &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_EnumerationCompleted(token));
}

- (EventRegistrationToken)addStoppedEvent:(void (^)(WDEDeviceWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcher>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Stopped(Make<ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_System_Object>(handler).Get(),
                              &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStoppedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Stopped(token));
}

- (WDEDeviceWatcherStatus)status {
    ABI::Windows::Devices::Enumeration::DeviceWatcherStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDEDeviceWatcherStatus)unmarshalledReturn;
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (WABDeviceWatcherTrigger*)getBackgroundTrigger:(id<NSFastEnumeration> /* WDEDeviceWatcherEventKind */)requestedEventKinds {
    ComPtr<ABI::Windows::ApplicationModel::Background::IDeviceWatcherTrigger> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcher2>(self);
    THROW_NS_IF_FAILED(_comInst->GetBackgroundTrigger(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Devices::Enumeration::DeviceWatcherEventKind>::type>*>(
            ConvertToIterable<WDEDeviceWatcherEventKind, ABI::Windows::Devices::Enumeration::DeviceWatcherEventKind>(requestedEventKinds)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABDeviceWatcherTrigger>(unmarshalledReturn.Get());
}

@end

@implementation WDEDeviceInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationStatics2> WDEIDeviceInformationStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Enumeration.DeviceInformation").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)getAqsFilterFromDeviceClass:(WDEDeviceClass)deviceClass {
    HSTRING unmarshalledReturn;
    auto _comInst = WDEIDeviceInformationStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetAqsFilterFromDeviceClass((ABI::Windows::Devices::Enumeration::DeviceClass)deviceClass, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)createFromIdAsyncWithKindAndAdditionalProperties:(NSString*)deviceId
                                    additionalProperties:(id<NSFastEnumeration> /* NSString * */)additionalProperties
                                                    kind:(WDEDeviceInformationKind)kind
                                                 success:(void (^)(WDEDeviceInformation*))success
                                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformation*>> unmarshalledReturn;
    auto _comInst = WDEIDeviceInformationStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromIdAsyncWithKindAndAdditionalProperties(
        nsStrToHstr(deviceId).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(additionalProperties).Get()),
        (ABI::Windows::Devices::Enumeration::DeviceInformationKind)kind,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DeviceInformation*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformation*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDeviceInformation>(result.Get()));
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

+ (void)findAllAsyncWithKindAqsFilterAndAdditionalProperties:(NSString*)aqsFilter
                                        additionalProperties:(id<NSFastEnumeration> /* NSString * */)additionalProperties
                                                        kind:(WDEDeviceInformationKind)kind
                                                     success:(void (^)(WDEDeviceInformationCollection*))success
                                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformationCollection*>> unmarshalledReturn;
    auto _comInst = WDEIDeviceInformationStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllAsyncWithKindAqsFilterAndAdditionalProperties(
        nsStrToHstr(aqsFilter).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(additionalProperties).Get()),
        (ABI::Windows::Devices::Enumeration::DeviceInformationKind)kind,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DeviceInformationCollection*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformationCollection*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Enumeration::DeviceInformation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDeviceInformationCollection>(result.Get()));
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

+ (WDEDeviceWatcher*)createWatcherWithKindAqsFilterAndAdditionalProperties:(NSString*)aqsFilter
                                                      additionalProperties:(id<NSFastEnumeration> /* NSString * */)additionalProperties
                                                                      kind:(WDEDeviceInformationKind)kind {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceWatcher> unmarshalledReturn;
    auto _comInst = WDEIDeviceInformationStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWatcherWithKindAqsFilterAndAdditionalProperties(
        nsStrToHstr(aqsFilter).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(additionalProperties).Get()),
        (ABI::Windows::Devices::Enumeration::DeviceInformationKind)kind,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceWatcher>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationStatics> WDEIDeviceInformationStatics_inst() {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Enumeration.DeviceInformation").Get(),
                                                       &inst));
    return inst;
}

+ (void)createFromIdAsync:(NSString*)deviceId success:(void (^)(WDEDeviceInformation*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformation*>> unmarshalledReturn;
    auto _comInst = WDEIDeviceInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DeviceInformation*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformation*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDeviceInformation>(result.Get()));
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

+ (void)createFromIdAsyncAdditionalProperties:(NSString*)deviceId
                         additionalProperties:(id<NSFastEnumeration> /* NSString * */)additionalProperties
                                      success:(void (^)(WDEDeviceInformation*))success
                                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformation*>> unmarshalledReturn;
    auto _comInst = WDEIDeviceInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromIdAsyncAdditionalProperties(
        nsStrToHstr(deviceId).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(additionalProperties).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DeviceInformation*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformation*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDeviceInformation>(result.Get()));
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

+ (void)findAllAsyncWithSuccess:(void (^)(WDEDeviceInformationCollection*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformationCollection*>> unmarshalledReturn;
    auto _comInst = WDEIDeviceInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DeviceInformationCollection*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformationCollection*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Enumeration::DeviceInformation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDeviceInformationCollection>(result.Get()));
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

+ (void)findAllAsyncDeviceClass:(WDEDeviceClass)deviceClass
                        success:(void (^)(WDEDeviceInformationCollection*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformationCollection*>> unmarshalledReturn;
    auto _comInst = WDEIDeviceInformationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FindAllAsyncDeviceClass((ABI::Windows::Devices::Enumeration::DeviceClass)deviceClass, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DeviceInformationCollection*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformationCollection*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Enumeration::DeviceInformation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDeviceInformationCollection>(result.Get()));
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

+ (void)findAllAsyncAqsFilter:(NSString*)aqsFilter
                      success:(void (^)(WDEDeviceInformationCollection*))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformationCollection*>> unmarshalledReturn;
    auto _comInst = WDEIDeviceInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllAsyncAqsFilter(nsStrToHstr(aqsFilter).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DeviceInformationCollection*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformationCollection*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Enumeration::DeviceInformation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDeviceInformationCollection>(result.Get()));
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

+ (void)findAllAsyncAqsFilterAndAdditionalProperties:(NSString*)aqsFilter
                                additionalProperties:(id<NSFastEnumeration> /* NSString * */)additionalProperties
                                             success:(void (^)(WDEDeviceInformationCollection*))success
                                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformationCollection*>> unmarshalledReturn;
    auto _comInst = WDEIDeviceInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllAsyncAqsFilterAndAdditionalProperties(
        nsStrToHstr(aqsFilter).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(additionalProperties).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DeviceInformationCollection*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceInformationCollection*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Enumeration::DeviceInformation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDeviceInformationCollection>(result.Get()));
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

+ (WDEDeviceWatcher*)createWatcher {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceWatcher> unmarshalledReturn;
    auto _comInst = WDEIDeviceInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceWatcher>(unmarshalledReturn.Get());
}

+ (WDEDeviceWatcher*)createWatcherDeviceClass:(WDEDeviceClass)deviceClass {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceWatcher> unmarshalledReturn;
    auto _comInst = WDEIDeviceInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWatcherDeviceClass((ABI::Windows::Devices::Enumeration::DeviceClass)deviceClass,
                                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceWatcher>(unmarshalledReturn.Get());
}

+ (WDEDeviceWatcher*)createWatcherAqsFilter:(NSString*)aqsFilter {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceWatcher> unmarshalledReturn;
    auto _comInst = WDEIDeviceInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWatcherAqsFilter(nsStrToHstr(aqsFilter).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceWatcher>(unmarshalledReturn.Get());
}

+ (WDEDeviceWatcher*)createWatcherAqsFilterAndAdditionalProperties:(NSString*)aqsFilter
                                              additionalProperties:(id<NSFastEnumeration> /* NSString * */)additionalProperties {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceWatcher> unmarshalledReturn;
    auto _comInst = WDEIDeviceInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWatcherAqsFilterAndAdditionalProperties(
        nsStrToHstr(aqsFilter).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(additionalProperties).Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceWatcher>(unmarshalledReturn.Get());
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDefault {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDefault(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDEEnclosureLocation*)enclosureLocation {
    ComPtr<ABI::Windows::Devices::Enumeration::IEnclosureLocation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnclosureLocation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEEnclosureLocation>(unmarshalledReturn.Get());
}

- (NSDictionary* /* NSString *, RTObject* */)properties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

- (void)update:(WDEDeviceInformationUpdate*)updateInfo {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->Update(_getRtInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationUpdate>(updateInfo).Get()));
}

- (void)getThumbnailAsyncWithSuccess:(void (^)(WDEDeviceThumbnail*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->GetThumbnailAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DeviceThumbnail*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceThumbnail*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDeviceThumbnail>(result.Get()));
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

- (void)getGlyphThumbnailAsyncWithSuccess:(void (^)(WDEDeviceThumbnail*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->GetGlyphThumbnailAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DeviceThumbnail*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceThumbnail*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDeviceThumbnail>(result.Get()));
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

- (WDEDeviceInformationKind)kind {
    ABI::Windows::Devices::Enumeration::DeviceInformationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WDEDeviceInformationKind)unmarshalledReturn;
}

- (WDEDeviceInformationPairing*)pairing {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationPairing> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pairing(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformationPairing>(unmarshalledReturn.Get());
}

@end

@implementation WDEDevicePairingResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDevicePairingResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDEDevicePairingResultStatus)status {
    ABI::Windows::Devices::Enumeration::DevicePairingResultStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePairingResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDEDevicePairingResultStatus)unmarshalledReturn;
}

- (WDEDevicePairingProtectionLevel)protectionLevelUsed {
    ABI::Windows::Devices::Enumeration::DevicePairingProtectionLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePairingResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionLevelUsed(&unmarshalledReturn));
    return (WDEDevicePairingProtectionLevel)unmarshalledReturn;
}

@end

@implementation WDEDeviceUnpairingResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceUnpairingResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDEDeviceUnpairingResultStatus)status {
    ABI::Windows::Devices::Enumeration::DeviceUnpairingResultStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceUnpairingResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDEDeviceUnpairingResultStatus)unmarshalledReturn;
}

@end

@implementation WDEDevicePairingRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDevicePairingRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDEDeviceInformation*)deviceInformation {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePairingRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformation>(unmarshalledReturn.Get());
}

- (WDEDevicePairingKinds)pairingKind {
    ABI::Windows::Devices::Enumeration::DevicePairingKinds unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePairingRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PairingKind(&unmarshalledReturn));
    return (WDEDevicePairingKinds)unmarshalledReturn;
}

- (NSString*)pin {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePairingRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pin(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)accept {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePairingRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->Accept());
}

- (void)acceptWithPin:(NSString*)pin {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePairingRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->AcceptWithPin(nsStrToHstr(pin).Get()));
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDevicePairingRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WDEDeviceInformationCustomPairing

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationCustomPairing> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)pairAsync:(WDEDevicePairingKinds)pairingKindsSupported
          success:(void (^)(WDEDevicePairingResult*))success
          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DevicePairingResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationCustomPairing>(self);
    THROW_NS_IF_FAILED(
        _comInst->PairAsync((ABI::Windows::Devices::Enumeration::DevicePairingKinds)pairingKindsSupported, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DevicePairingResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DevicePairingResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Enumeration::IDevicePairingResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDevicePairingResult>(result.Get()));
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

- (void)pairWithProtectionLevelAsync:(WDEDevicePairingKinds)pairingKindsSupported
                  minProtectionLevel:(WDEDevicePairingProtectionLevel)minProtectionLevel
                             success:(void (^)(WDEDevicePairingResult*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DevicePairingResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationCustomPairing>(self);
    THROW_NS_IF_FAILED(
        _comInst->PairWithProtectionLevelAsync((ABI::Windows::Devices::Enumeration::DevicePairingKinds)pairingKindsSupported,
                                               (ABI::Windows::Devices::Enumeration::DevicePairingProtectionLevel)minProtectionLevel,
                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DevicePairingResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DevicePairingResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Enumeration::IDevicePairingResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDevicePairingResult>(result.Get()));
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

- (void)pairWithProtectionLevelAndSettingsAsync:(WDEDevicePairingKinds)pairingKindsSupported
                             minProtectionLevel:(WDEDevicePairingProtectionLevel)minProtectionLevel
                          devicePairingSettings:(RTObject<WDEIDevicePairingSettings>*)devicePairingSettings
                                        success:(void (^)(WDEDevicePairingResult*))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DevicePairingResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationCustomPairing>(self);
    THROW_NS_IF_FAILED(_comInst->PairWithProtectionLevelAndSettingsAsync(
        (ABI::Windows::Devices::Enumeration::DevicePairingKinds)pairingKindsSupported,
        (ABI::Windows::Devices::Enumeration::DevicePairingProtectionLevel)minProtectionLevel,
        _getRtInterface<ABI::Windows::Devices::Enumeration::IDevicePairingSettings>(devicePairingSettings).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DevicePairingResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DevicePairingResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Enumeration::IDevicePairingResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDevicePairingResult>(result.Get()));
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

- (EventRegistrationToken)addPairingRequestedEvent:(void (^)(WDEDeviceInformationCustomPairing*,
                                                             WDEDevicePairingRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationCustomPairing>(self);
    THROW_NS_IF_FAILED(_comInst->add_PairingRequested(
        Make<
            ITypedEventHandler_Windows_Devices_Enumeration_DeviceInformationCustomPairing_Windows_Devices_Enumeration_DevicePairingRequestedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePairingRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationCustomPairing>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PairingRequested(token));
}

@end

@implementation WDEDeviceInformationPairing

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationPairing> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationPairingStatics> WDEIDeviceInformationPairingStatics_inst() {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationPairingStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Enumeration.DeviceInformationPairing").Get(), &inst));
    return inst;
}

+ (BOOL)tryRegisterForAllInboundPairingRequests:(WDEDevicePairingKinds)pairingKindsSupported {
    boolean unmarshalledReturn;
    auto _comInst = WDEIDeviceInformationPairingStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryRegisterForAllInboundPairingRequests((ABI::Windows::Devices::Enumeration::DevicePairingKinds)pairingKindsSupported,
                                                          &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaired {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationPairing>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaired(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canPair {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationPairing>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanPair(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)pairAsyncWithSuccess:(void (^)(WDEDevicePairingResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DevicePairingResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationPairing>(self);
    THROW_NS_IF_FAILED(_comInst->PairAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DevicePairingResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DevicePairingResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Enumeration::IDevicePairingResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDevicePairingResult>(result.Get()));
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

- (void)pairWithProtectionLevelAsync:(WDEDevicePairingProtectionLevel)minProtectionLevel
                             success:(void (^)(WDEDevicePairingResult*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DevicePairingResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationPairing>(self);
    THROW_NS_IF_FAILED(
        _comInst->PairWithProtectionLevelAsync((ABI::Windows::Devices::Enumeration::DevicePairingProtectionLevel)minProtectionLevel,
                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DevicePairingResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DevicePairingResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Enumeration::IDevicePairingResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDevicePairingResult>(result.Get()));
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

- (WDEDevicePairingProtectionLevel)protectionLevel {
    ABI::Windows::Devices::Enumeration::DevicePairingProtectionLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationPairing2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionLevel(&unmarshalledReturn));
    return (WDEDevicePairingProtectionLevel)unmarshalledReturn;
}

- (WDEDeviceInformationCustomPairing*)custom {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationCustomPairing> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationPairing2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Custom(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformationCustomPairing>(unmarshalledReturn.Get());
}

- (void)pairWithProtectionLevelAndSettingsAsync:(WDEDevicePairingProtectionLevel)minProtectionLevel
                          devicePairingSettings:(RTObject<WDEIDevicePairingSettings>*)devicePairingSettings
                                        success:(void (^)(WDEDevicePairingResult*))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DevicePairingResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationPairing2>(self);
    THROW_NS_IF_FAILED(_comInst->PairWithProtectionLevelAndSettingsAsync(
        (ABI::Windows::Devices::Enumeration::DevicePairingProtectionLevel)minProtectionLevel,
        _getRtInterface<ABI::Windows::Devices::Enumeration::IDevicePairingSettings>(devicePairingSettings).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DevicePairingResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DevicePairingResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Enumeration::IDevicePairingResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDevicePairingResult>(result.Get()));
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

- (void)unpairAsyncWithSuccess:(void (^)(WDEDeviceUnpairingResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceUnpairingResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceInformationPairing2>(self);
    THROW_NS_IF_FAILED(_comInst->UnpairAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DeviceUnpairingResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceUnpairingResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceUnpairingResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEDeviceUnpairingResult>(result.Get()));
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

@implementation WDEDeviceAccessChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceAccessChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDEDeviceAccessStatus)status {
    ABI::Windows::Devices::Enumeration::DeviceAccessStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceAccessChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDEDeviceAccessStatus)unmarshalledReturn;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceAccessChangedEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDEDeviceAccessInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceAccessInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Enumeration::IDeviceAccessInformationStatics> WDEIDeviceAccessInformationStatics_inst() {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceAccessInformationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Enumeration.DeviceAccessInformation").Get(),
                                                       &inst));
    return inst;
}

+ (WDEDeviceAccessInformation*)createFromId:(NSString*)deviceId {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceAccessInformation> unmarshalledReturn;
    auto _comInst = WDEIDeviceAccessInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromId(nsStrToHstr(deviceId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceAccessInformation>(unmarshalledReturn.Get());
}

+ (WDEDeviceAccessInformation*)createFromDeviceClassId:(WFGUID*)deviceClassId {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceAccessInformation> unmarshalledReturn;
    auto _comInst = WDEIDeviceAccessInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromDeviceClassId(deviceClassId.guidValue, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceAccessInformation>(unmarshalledReturn.Get());
}

+ (WDEDeviceAccessInformation*)createFromDeviceClass:(WDEDeviceClass)deviceClass {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceAccessInformation> unmarshalledReturn;
    auto _comInst = WDEIDeviceAccessInformationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromDeviceClass((ABI::Windows::Devices::Enumeration::DeviceClass)deviceClass, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceAccessInformation>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addAccessChangedEvent:(void (^)(WDEDeviceAccessInformation*, WDEDeviceAccessChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceAccessInformation>(self);
    THROW_NS_IF_FAILED(_comInst->add_AccessChanged(
        Make<
            ITypedEventHandler_Windows_Devices_Enumeration_DeviceAccessInformation_Windows_Devices_Enumeration_DeviceAccessChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAccessChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceAccessInformation>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AccessChanged(cookie));
}

- (WDEDeviceAccessStatus)currentStatus {
    ABI::Windows::Devices::Enumeration::DeviceAccessStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceAccessInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentStatus(&unmarshalledReturn));
    return (WDEDeviceAccessStatus)unmarshalledReturn;
}

@end

@implementation WDEDeviceWatcherEvent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceWatcherEvent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDEDeviceWatcherEventKind)kind {
    ABI::Windows::Devices::Enumeration::DeviceWatcherEventKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcherEvent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WDEDeviceWatcherEventKind)unmarshalledReturn;
}

- (WDEDeviceInformation*)deviceInformation {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcherEvent>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformation>(unmarshalledReturn.Get());
}

- (WDEDeviceInformationUpdate*)deviceInformationUpdate {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationUpdate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcherEvent>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceInformationUpdate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformationUpdate>(unmarshalledReturn.Get());
}

@end

@implementation WDEDeviceWatcherTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceWatcherTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WDEDeviceWatcherEvent* */)deviceWatcherEvents {
    ComPtr<IVectorView<ABI::Windows::Devices::Enumeration::DeviceWatcherEvent*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::IDeviceWatcherTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceWatcherEvents(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDEDeviceWatcherEvent_create(unmarshalledReturn.Get());
}

@end

id RTProxiedIterableNSArray_WDEDeviceWatcherEventKind_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Devices::Enumeration::DeviceWatcherEventKind>,
                                                 RTIterableObj<ABI::Windows::Devices::Enumeration::DeviceWatcherEventKind,
                                                               IIterable<ABI::Windows::Devices::Enumeration::DeviceWatcherEventKind>,
                                                               WDEDeviceWatcherEventKind,
                                                               ABI::Windows::Devices::Enumeration::DeviceWatcherEventKind,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDEDeviceWatcherEvent_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Enumeration::DeviceWatcherEvent*>,
                                         RTArrayObj<ABI::Windows::Devices::Enumeration::IDeviceWatcherEvent*,
                                                    IVectorView<ABI::Windows::Devices::Enumeration::DeviceWatcherEvent*>,
                                                    WDEDeviceWatcherEvent,
                                                    ABI::Windows::Devices::Enumeration::DeviceWatcherEvent*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WDEDeviceClass_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Devices::Enumeration::DeviceClass>,
                                                RTMutableArrayObj<ABI::Windows::Devices::Enumeration::DeviceClass,
                                                                  IVector<ABI::Windows::Devices::Enumeration::DeviceClass>,
                                                                  WDEDeviceClass,
                                                                  ABI::Windows::Devices::Enumeration::DeviceClass,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
