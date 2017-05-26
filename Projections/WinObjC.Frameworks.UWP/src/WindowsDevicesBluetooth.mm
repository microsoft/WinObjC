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

// WindowsDevicesBluetooth.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Bluetooth.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesBluetooth.h"
#include "WindowsDevicesBluetooth_priv.h"

@implementation WDBBluetoothDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothDeviceStatics> WDBIBluetoothDeviceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Bluetooth.BluetoothDevice").Get(), &inst));
    return inst;
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDBBluetoothDevice*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::BluetoothDevice*>> unmarshalledReturn;
    auto _comInst = WDBIBluetoothDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Bluetooth::BluetoothDevice*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::BluetoothDevice*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothDevice> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDBBluetoothDevice>(result.Get()));
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

+ (void)fromHostNameAsync:(WNHostName*)hostName success:(void (^)(WDBBluetoothDevice*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::BluetoothDevice*>> unmarshalledReturn;
    auto _comInst = WDBIBluetoothDeviceStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FromHostNameAsync(_getRtInterface<ABI::Windows::Networking::IHostName>(hostName).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Bluetooth::BluetoothDevice*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::BluetoothDevice*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothDevice> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDBBluetoothDevice>(result.Get()));
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

+ (void)fromBluetoothAddressAsync:(uint64_t)address success:(void (^)(WDBBluetoothDevice*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::BluetoothDevice*>> unmarshalledReturn;
    auto _comInst = WDBIBluetoothDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromBluetoothAddressAsync(address, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Bluetooth::BluetoothDevice*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::BluetoothDevice*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothDevice> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDBBluetoothDevice>(result.Get()));
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

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBIBluetoothDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothDeviceStatics2> WDBIBluetoothDeviceStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothDeviceStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Bluetooth.BluetoothDevice").Get(), &inst));
    return inst;
}

+ (NSString*)getDeviceSelectorFromPairingState:(BOOL)pairingState {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBIBluetoothDeviceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromPairingState((boolean)pairingState, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorFromConnectionStatus:(WDBBluetoothConnectionStatus)connectionStatus {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBIBluetoothDeviceStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetDeviceSelectorFromConnectionStatus((ABI::Windows::Devices::Bluetooth::BluetoothConnectionStatus)connectionStatus,
                                                        &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorFromDeviceName:(NSString*)deviceName {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBIBluetoothDeviceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromDeviceName(nsStrToHstr(deviceName).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorFromBluetoothAddress:(uint64_t)bluetoothAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBIBluetoothDeviceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromBluetoothAddress(bluetoothAddress, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorFromClassOfDevice:(WDBBluetoothClassOfDevice*)classOfDevice {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBIBluetoothDeviceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromClassOfDevice(
        _getRtInterface<ABI::Windows::Devices::Bluetooth::IBluetoothClassOfDevice>(classOfDevice).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNHostName*)hostName {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_HostName(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDBBluetoothClassOfDevice*)classOfDevice {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothClassOfDevice> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClassOfDevice(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBBluetoothClassOfDevice>(unmarshalledReturn.Get());
}

- (NSArray* /* RTObject<WSSIBuffer>* */)sdpRecords {
    ComPtr<IVectorView<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_SdpRecords(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_WSSIBuffer_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDBRRfcommDeviceService* */)rfcommServices {
    ComPtr<IVectorView<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_RfcommServices(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDBRRfcommDeviceService_create(unmarshalledReturn.Get());
}

- (WDBBluetoothConnectionStatus)connectionStatus {
    ABI::Windows::Devices::Bluetooth::BluetoothConnectionStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionStatus(&unmarshalledReturn));
    return (WDBBluetoothConnectionStatus)unmarshalledReturn;
}

- (uint64_t)bluetoothAddress {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_BluetoothAddress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addNameChangedEvent:(void (^)(WDBBluetoothDevice*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_NameChanged(Make<ITypedEventHandler_Windows_Devices_Bluetooth_BluetoothDevice_System_Object>(handler).Get(),
                                  &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeNameChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_NameChanged(token));
}

- (EventRegistrationToken)addSdpRecordsChangedEvent:(void (^)(WDBBluetoothDevice*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_SdpRecordsChanged(Make<ITypedEventHandler_Windows_Devices_Bluetooth_BluetoothDevice_System_Object>(handler).Get(),
                                        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSdpRecordsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SdpRecordsChanged(token));
}

- (EventRegistrationToken)addConnectionStatusChangedEvent:(void (^)(WDBBluetoothDevice*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(self);
    THROW_NS_IF_FAILED(_comInst->add_ConnectionStatusChanged(
        Make<ITypedEventHandler_Windows_Devices_Bluetooth_BluetoothDevice_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeConnectionStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ConnectionStatusChanged(token));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (WDEDeviceInformation*)deviceInformation {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformation>(unmarshalledReturn.Get());
}

- (WDEDeviceAccessInformation*)deviceAccessInformation {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceAccessInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice3>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceAccessInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceAccessInformation>(unmarshalledReturn.Get());
}

- (void)requestAccessAsyncWithSuccess:(void (^)(WDEDeviceAccessStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceAccessStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice3>(self);
    THROW_NS_IF_FAILED(_comInst->RequestAccessAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::DeviceAccessStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceAccessStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Devices::Enumeration::DeviceAccessStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WDEDeviceAccessStatus)result);
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

- (void)getRfcommServicesAsyncWithSuccess:(void (^)(WDBRRfcommDeviceServicesResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice3>(self);
    THROW_NS_IF_FAILED(_comInst->GetRfcommServicesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDBRRfcommDeviceServicesResult>(result.Get()));
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

- (void)getRfcommServicesWithCacheModeAsync:(WDBBluetoothCacheMode)cacheMode
                                    success:(void (^)(WDBRRfcommDeviceServicesResult*))success
                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice3>(self);
    THROW_NS_IF_FAILED(_comInst->GetRfcommServicesWithCacheModeAsync((ABI::Windows::Devices::Bluetooth::BluetoothCacheMode)cacheMode,
                                                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDBRRfcommDeviceServicesResult>(result.Get()));
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

- (void)getRfcommServicesForIdAsync:(WDBRRfcommServiceId*)serviceId
                            success:(void (^)(WDBRRfcommDeviceServicesResult*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice3>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetRfcommServicesForIdAsync(_getRtInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId>(serviceId).Get(),
                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDBRRfcommDeviceServicesResult>(result.Get()));
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

- (void)getRfcommServicesForIdWithCacheModeAsync:(WDBRRfcommServiceId*)serviceId
                                       cacheMode:(WDBBluetoothCacheMode)cacheMode
                                         success:(void (^)(WDBRRfcommDeviceServicesResult*))success
                                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice3>(self);
    THROW_NS_IF_FAILED(_comInst->GetRfcommServicesForIdWithCacheModeAsync(
        _getRtInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId>(serviceId).Get(),
        (ABI::Windows::Devices::Bluetooth::BluetoothCacheMode)cacheMode,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDBRRfcommDeviceServicesResult>(result.Get()));
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

@implementation WDBBluetoothClassOfDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothClassOfDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothClassOfDeviceStatics> WDBIBluetoothClassOfDeviceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothClassOfDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Bluetooth.BluetoothClassOfDevice").Get(),
                                                       &inst));
    return inst;
}

+ (WDBBluetoothClassOfDevice*)fromRawValue:(unsigned int)rawValue {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothClassOfDevice> unmarshalledReturn;
    auto _comInst = WDBIBluetoothClassOfDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromRawValue(rawValue, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBBluetoothClassOfDevice>(unmarshalledReturn.Get());
}

+ (WDBBluetoothClassOfDevice*)fromParts:(WDBBluetoothMajorClass)majorClass
                             minorClass:(WDBBluetoothMinorClass)minorClass
                    serviceCapabilities:(WDBBluetoothServiceCapabilities)serviceCapabilities {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothClassOfDevice> unmarshalledReturn;
    auto _comInst = WDBIBluetoothClassOfDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromParts((ABI::Windows::Devices::Bluetooth::BluetoothMajorClass)majorClass,
                                           (ABI::Windows::Devices::Bluetooth::BluetoothMinorClass)minorClass,
                                           (ABI::Windows::Devices::Bluetooth::BluetoothServiceCapabilities)serviceCapabilities,
                                           unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBBluetoothClassOfDevice>(unmarshalledReturn.Get());
}

- (unsigned int)rawValue {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothClassOfDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDBBluetoothMajorClass)majorClass {
    ABI::Windows::Devices::Bluetooth::BluetoothMajorClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothClassOfDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_MajorClass(&unmarshalledReturn));
    return (WDBBluetoothMajorClass)unmarshalledReturn;
}

- (WDBBluetoothMinorClass)minorClass {
    ABI::Windows::Devices::Bluetooth::BluetoothMinorClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothClassOfDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinorClass(&unmarshalledReturn));
    return (WDBBluetoothMinorClass)unmarshalledReturn;
}

- (WDBBluetoothServiceCapabilities)serviceCapabilities {
    ABI::Windows::Devices::Bluetooth::BluetoothServiceCapabilities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothClassOfDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceCapabilities(&unmarshalledReturn));
    return (WDBBluetoothServiceCapabilities)unmarshalledReturn;
}

@end

@implementation WDBBluetoothLEAppearanceCategories

ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearanceCategoriesStatics> WDBIBluetoothLEAppearanceCategoriesStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearanceCategoriesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.BluetoothLEAppearanceCategories").Get(), &inst));
    return inst;
}

+ (unsigned short)uncategorized {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Uncategorized(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)phone {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Phone(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)computer {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Computer(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)watch {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Watch(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)clock {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Clock(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)display {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Display(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)remoteControl {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RemoteControl(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)eyeGlasses {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EyeGlasses(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)tag {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Tag(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)keyring {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Keyring(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)mediaPlayer {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MediaPlayer(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)barcodeScanner {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BarcodeScanner(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)thermometer {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Thermometer(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)heartRate {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HeartRate(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)bloodPressure {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BloodPressure(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)humanInterfaceDevice {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HumanInterfaceDevice(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)glucoseMeter {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GlucoseMeter(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)runningWalking {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RunningWalking(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)cycling {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Cycling(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)pulseOximeter {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PulseOximeter(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)weightScale {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_WeightScale(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)outdoorSportActivity {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OutdoorSportActivity(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDBBluetoothLEAppearanceSubcategories

ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearanceSubcategoriesStatics> WDBIBluetoothLEAppearanceSubcategoriesStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearanceSubcategoriesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.BluetoothLEAppearanceSubcategories").Get(), &inst));
    return inst;
}

+ (unsigned short)generic {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Generic(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)sportsWatch {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SportsWatch(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)thermometerEar {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ThermometerEar(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)heartRateBelt {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HeartRateBelt(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)bloodPressureArm {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BloodPressureArm(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)bloodPressureWrist {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BloodPressureWrist(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)keyboard {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Keyboard(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)mouse {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Mouse(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)joystick {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Joystick(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)gamepad {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gamepad(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)digitizerTablet {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DigitizerTablet(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)cardReader {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CardReader(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)digitalPen {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DigitalPen(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)barcodeScanner {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BarcodeScanner(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)runningWalkingInShoe {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RunningWalkingInShoe(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)runningWalkingOnShoe {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RunningWalkingOnShoe(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)runningWalkingOnHip {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RunningWalkingOnHip(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)cyclingComputer {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CyclingComputer(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)cyclingSpeedSensor {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CyclingSpeedSensor(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)cyclingCadenceSensor {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CyclingCadenceSensor(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)cyclingPowerSensor {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CyclingPowerSensor(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)cyclingSpeedCadenceSensor {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CyclingSpeedCadenceSensor(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)oximeterFingertip {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OximeterFingertip(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)oximeterWristWorn {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OximeterWristWorn(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)locationDisplay {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LocationDisplay(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)locationNavigationDisplay {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LocationNavigationDisplay(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)locationPod {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LocationPod(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned short)locationNavigationPod {
    unsigned short unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LocationNavigationPod(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDBBluetoothLEAppearance

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearance> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearanceStatics> WDBIBluetoothLEAppearanceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearanceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Bluetooth.BluetoothLEAppearance").Get(),
                                                       &inst));
    return inst;
}

+ (WDBBluetoothLEAppearance*)fromRawValue:(unsigned short)rawValue {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearance> unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromRawValue(rawValue, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBBluetoothLEAppearance>(unmarshalledReturn.Get());
}

+ (WDBBluetoothLEAppearance*)fromParts:(unsigned short)appearanceCategory appearanceSubCategory:(unsigned short)appearanceSubCategory {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearance> unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEAppearanceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromParts(appearanceCategory, appearanceSubCategory, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBBluetoothLEAppearance>(unmarshalledReturn.Get());
}

- (unsigned short)rawValue {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)category {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->get_Category(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)subCategory {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearance>(self);
    THROW_NS_IF_FAILED(_comInst->get_SubCategory(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDBBluetoothLEDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics> WDBIBluetoothLEDeviceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Bluetooth.BluetoothLEDevice").Get(),
                                                       &inst));
    return inst;
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDBBluetoothLEDevice*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::BluetoothLEDevice*>> unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Bluetooth::BluetoothLEDevice*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::BluetoothLEDevice*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDBBluetoothLEDevice>(result.Get()));
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

+ (void)fromBluetoothAddressAsync:(uint64_t)bluetoothAddress
                          success:(void (^)(WDBBluetoothLEDevice*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::BluetoothLEDevice*>> unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromBluetoothAddressAsync(bluetoothAddress, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Bluetooth::BluetoothLEDevice*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::BluetoothLEDevice*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDBBluetoothLEDevice>(result.Get()));
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

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics2> WDBIBluetoothLEDeviceStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Bluetooth.BluetoothLEDevice").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)getDeviceSelectorFromPairingState:(BOOL)pairingState {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEDeviceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromPairingState((boolean)pairingState, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorFromConnectionStatus:(WDBBluetoothConnectionStatus)connectionStatus {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEDeviceStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetDeviceSelectorFromConnectionStatus((ABI::Windows::Devices::Bluetooth::BluetoothConnectionStatus)connectionStatus,
                                                        &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorFromDeviceName:(NSString*)deviceName {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEDeviceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromDeviceName(nsStrToHstr(deviceName).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorFromBluetoothAddress:(uint64_t)bluetoothAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEDeviceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromBluetoothAddress(bluetoothAddress, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorFromBluetoothAddressWithBluetoothAddressType:(uint64_t)bluetoothAddress
                                                      bluetoothAddressType:(WDBBluetoothAddressType)bluetoothAddressType {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEDeviceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromBluetoothAddressWithBluetoothAddressType(
        bluetoothAddress, (ABI::Windows::Devices::Bluetooth::BluetoothAddressType)bluetoothAddressType, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorFromAppearance:(WDBBluetoothLEAppearance*)appearance {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEDeviceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromAppearance(
        _getRtInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearance>(appearance).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)fromBluetoothAddressWithBluetoothAddressTypeAsync:(uint64_t)bluetoothAddress
                                     bluetoothAddressType:(WDBBluetoothAddressType)bluetoothAddressType
                                                  success:(void (^)(WDBBluetoothLEDevice*))success
                                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::BluetoothLEDevice*>> unmarshalledReturn;
    auto _comInst = WDBIBluetoothLEDeviceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->FromBluetoothAddressWithBluetoothAddressTypeAsync(
        bluetoothAddress, (ABI::Windows::Devices::Bluetooth::BluetoothAddressType)bluetoothAddressType, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Bluetooth::BluetoothLEDevice*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::BluetoothLEDevice*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDBBluetoothLEDevice>(result.Get()));
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

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* WDBGGattDeviceService* */)gattServices {
    ComPtr<IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_GattServices(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDBGGattDeviceService_create(unmarshalledReturn.Get());
}

- (WDBBluetoothConnectionStatus)connectionStatus {
    ABI::Windows::Devices::Bluetooth::BluetoothConnectionStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionStatus(&unmarshalledReturn));
    return (WDBBluetoothConnectionStatus)unmarshalledReturn;
}

- (uint64_t)bluetoothAddress {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_BluetoothAddress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDBGGattDeviceService*)getGattService:(WFGUID*)serviceUuid {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice>(self);
    THROW_NS_IF_FAILED(_comInst->GetGattService(serviceUuid.guidValue, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBGGattDeviceService>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addNameChangedEvent:(void (^)(WDBBluetoothLEDevice*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_NameChanged(Make<ITypedEventHandler_Windows_Devices_Bluetooth_BluetoothLEDevice_System_Object>(handler).Get(),
                                  &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeNameChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_NameChanged(token));
}

- (EventRegistrationToken)addGattServicesChangedEvent:(void (^)(WDBBluetoothLEDevice*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_GattServicesChanged(Make<ITypedEventHandler_Windows_Devices_Bluetooth_BluetoothLEDevice_System_Object>(handler).Get(),
                                          &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeGattServicesChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_GattServicesChanged(token));
}

- (EventRegistrationToken)addConnectionStatusChangedEvent:(void (^)(WDBBluetoothLEDevice*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice>(self);
    THROW_NS_IF_FAILED(_comInst->add_ConnectionStatusChanged(
        Make<ITypedEventHandler_Windows_Devices_Bluetooth_BluetoothLEDevice_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeConnectionStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ConnectionStatusChanged(token));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (WDEDeviceInformation*)deviceInformation {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformation>(unmarshalledReturn.Get());
}

- (WDBBluetoothLEAppearance*)appearance {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearance> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Appearance(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBBluetoothLEAppearance>(unmarshalledReturn.Get());
}

- (WDBBluetoothAddressType)bluetoothAddressType {
    ABI::Windows::Devices::Bluetooth::BluetoothAddressType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice2>(self);
    THROW_NS_IF_FAILED(_comInst->get_BluetoothAddressType(&unmarshalledReturn));
    return (WDBBluetoothAddressType)unmarshalledReturn;
}

@end

@implementation WDBBluetoothSignalStrengthFilter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Bluetooth.BluetoothSignalStrengthFilter").Get(),
                                              &out));
    return [_createRtProxy<WDBBluetoothSignalStrengthFilter>(out.Get()) retain];
}

- (id /* int16_t */)inRangeThresholdInDBm {
    ComPtr<IReference<int16_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_InRangeThresholdInDBm(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int16_t, int16_t>::convert(unmarshalledReturn.Get());
}

- (void)setInRangeThresholdInDBm:(id /* int16_t */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_InRangeThresholdInDBm(BuildNullable<int16_t>(value)));
}

- (id /* int16_t */)outOfRangeThresholdInDBm {
    ComPtr<IReference<int16_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutOfRangeThresholdInDBm(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int16_t, int16_t>::convert(unmarshalledReturn.Get());
}

- (void)setOutOfRangeThresholdInDBm:(id /* int16_t */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutOfRangeThresholdInDBm(BuildNullable<int16_t>(value)));
}

- (id /* WFTimeSpan* */)outOfRangeTimeout {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutOfRangeTimeout(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setOutOfRangeTimeout:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutOfRangeTimeout(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (id /* WFTimeSpan* */)samplingInterval {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SamplingInterval(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setSamplingInterval:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_SamplingInterval(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

@end

id RTProxiedNSArray_RTObject_WSSIBuffer_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Storage::Streams::IBuffer*>,
                                         RTArrayObj<ABI::Windows::Storage::Streams::IBuffer*,
                                                    IVectorView<ABI::Windows::Storage::Streams::IBuffer*>,
                                                    RTObject<WSSIBuffer>,
                                                    ABI::Windows::Storage::Streams::IBuffer*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDBGGattDeviceService_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService*>,
                        RTArrayObj<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService*,
                                   IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService*>,
                                   WDBGGattDeviceService,
                                   ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDBRRfcommDeviceService_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService*>,
                                         RTArrayObj<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService*,
                                                    IVectorView<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService*>,
                                                    WDBRRfcommDeviceService,
                                                    ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
