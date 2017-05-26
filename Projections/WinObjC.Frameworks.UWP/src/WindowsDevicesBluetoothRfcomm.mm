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

// WindowsDevicesBluetoothRfcomm.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Bluetooth.Rfcomm.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesBluetoothRfcomm.h"
#include "WindowsDevicesBluetoothRfcomm_priv.h"

@implementation WDBRRfcommDeviceService

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics2> WDBRIRfcommDeviceServiceStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.Rfcomm.RfcommDeviceService").Get(), &inst));
    return inst;
}

+ (NSString*)getDeviceSelectorForBluetoothDevice:(WDBBluetoothDevice*)bluetoothDevice {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBRIRfcommDeviceServiceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorForBluetoothDevice(
        _getRtInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(bluetoothDevice).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorForBluetoothDeviceWithCacheMode:(WDBBluetoothDevice*)bluetoothDevice
                                                    cacheMode:(WDBBluetoothCacheMode)cacheMode {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBRIRfcommDeviceServiceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorForBluetoothDeviceWithCacheMode(
        _getRtInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(bluetoothDevice).Get(),
        (ABI::Windows::Devices::Bluetooth::BluetoothCacheMode)cacheMode,
        &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorForBluetoothDeviceAndServiceId:(WDBBluetoothDevice*)bluetoothDevice
                                                   serviceId:(WDBRRfcommServiceId*)serviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBRIRfcommDeviceServiceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorForBluetoothDeviceAndServiceId(
        _getRtInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(bluetoothDevice).Get(),
        _getRtInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId>(serviceId).Get(),
        &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorForBluetoothDeviceAndServiceIdWithCacheMode:(WDBBluetoothDevice*)bluetoothDevice
                                                                serviceId:(WDBRRfcommServiceId*)serviceId
                                                                cacheMode:(WDBBluetoothCacheMode)cacheMode {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBRIRfcommDeviceServiceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorForBluetoothDeviceAndServiceIdWithCacheMode(
        _getRtInterface<ABI::Windows::Devices::Bluetooth::IBluetoothDevice>(bluetoothDevice).Get(),
        _getRtInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId>(serviceId).Get(),
        (ABI::Windows::Devices::Bluetooth::BluetoothCacheMode)cacheMode,
        &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics> WDBRIRfcommDeviceServiceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.Rfcomm.RfcommDeviceService").Get(), &inst));
    return inst;
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDBRRfcommDeviceService*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService*>> unmarshalledReturn;
    auto _comInst = WDBRIRfcommDeviceServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDBRRfcommDeviceService>(result.Get()));
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

+ (NSString*)getDeviceSelector:(WDBRRfcommServiceId*)serviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBRIRfcommDeviceServiceStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetDeviceSelector(_getRtInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId>(serviceId).Get(),
                                    &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNHostName*)connectionHostName {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionHostName(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (NSString*)connectionServiceName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionServiceName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDBRRfcommServiceId*)serviceId {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceId(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBRRfcommServiceId>(unmarshalledReturn.Get());
}

- (WNSSocketProtectionLevel)protectionLevel {
    ABI::Windows::Networking::Sockets::SocketProtectionLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionLevel(&unmarshalledReturn));
    return (WNSSocketProtectionLevel)unmarshalledReturn;
}

- (WNSSocketProtectionLevel)maxProtectionLevel {
    ABI::Windows::Networking::Sockets::SocketProtectionLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxProtectionLevel(&unmarshalledReturn));
    return (WNSSocketProtectionLevel)unmarshalledReturn;
}

- (void)getSdpRawAttributesAsyncWithSuccess:(void (^)(NSDictionary* /* unsigned int, RTObject<WSSIBuffer>* */))success
                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMapView<unsigned int, ABI::Windows::Storage::Streams::IBuffer*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService>(self);
    THROW_NS_IF_FAILED(_comInst->GetSdpRawAttributesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IMapView<unsigned int, ABI::Windows::Storage::Streams::IBuffer*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IMapView<unsigned int, ABI::Windows::Storage::Streams::IBuffer*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IMapView<unsigned int, ABI::Windows::Storage::Streams::IBuffer*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSDictionary_UInt32_RTObject_WSSIBuffer_create(result.Get()));
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

- (void)getSdpRawAttributesWithCacheModeAsync:(WDBBluetoothCacheMode)cacheMode
                                      success:(void (^)(NSDictionary* /* unsigned int, RTObject<WSSIBuffer>* */))success
                                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMapView<unsigned int, ABI::Windows::Storage::Streams::IBuffer*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService>(self);
    THROW_NS_IF_FAILED(_comInst->GetSdpRawAttributesWithCacheModeAsync((ABI::Windows::Devices::Bluetooth::BluetoothCacheMode)cacheMode,
                                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IMapView<unsigned int, ABI::Windows::Storage::Streams::IBuffer*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IMapView<unsigned int, ABI::Windows::Storage::Streams::IBuffer*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IMapView<unsigned int, ABI::Windows::Storage::Streams::IBuffer*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSDictionary_UInt32_RTObject_WSSIBuffer_create(result.Get()));
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

- (WDBBluetoothDevice*)device {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothDevice> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Device(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBBluetoothDevice>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (WDEDeviceAccessInformation*)deviceAccessInformation {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceAccessInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService3>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceAccessInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceAccessInformation>(unmarshalledReturn.Get());
}

- (void)requestAccessAsyncWithSuccess:(void (^)(WDEDeviceAccessStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::DeviceAccessStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService3>(self);
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

@end

@implementation WDBRRfcommDeviceServicesResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDBBluetoothError)error {
    ABI::Windows::Devices::Bluetooth::BluetoothError unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Error(&unmarshalledReturn));
    return (WDBBluetoothError)unmarshalledReturn;
}

- (NSArray* /* WDBRRfcommDeviceService* */)services {
    ComPtr<IVectorView<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Services(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDBRRfcommDeviceService_create(unmarshalledReturn.Get());
}

@end

@implementation WDBRRfcommServiceId

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics> WDBRIRfcommServiceIdStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Bluetooth.Rfcomm.RfcommServiceId").Get(),
                                                       &inst));
    return inst;
}

+ (WDBRRfcommServiceId*)fromUuid:(WFGUID*)uuid {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> unmarshalledReturn;
    auto _comInst = WDBRIRfcommServiceIdStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromUuid(uuid.guidValue, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBRRfcommServiceId>(unmarshalledReturn.Get());
}

+ (WDBRRfcommServiceId*)fromShortId:(unsigned int)shortId {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> unmarshalledReturn;
    auto _comInst = WDBRIRfcommServiceIdStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromShortId(shortId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBRRfcommServiceId>(unmarshalledReturn.Get());
}

+ (WDBRRfcommServiceId*)serialPort {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> unmarshalledReturn;
    auto _comInst = WDBRIRfcommServiceIdStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SerialPort(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBRRfcommServiceId>(unmarshalledReturn.Get());
}

+ (WDBRRfcommServiceId*)obexObjectPush {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> unmarshalledReturn;
    auto _comInst = WDBRIRfcommServiceIdStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ObexObjectPush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBRRfcommServiceId>(unmarshalledReturn.Get());
}

+ (WDBRRfcommServiceId*)obexFileTransfer {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> unmarshalledReturn;
    auto _comInst = WDBRIRfcommServiceIdStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ObexFileTransfer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBRRfcommServiceId>(unmarshalledReturn.Get());
}

+ (WDBRRfcommServiceId*)phoneBookAccessPce {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> unmarshalledReturn;
    auto _comInst = WDBRIRfcommServiceIdStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PhoneBookAccessPce(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBRRfcommServiceId>(unmarshalledReturn.Get());
}

+ (WDBRRfcommServiceId*)phoneBookAccessPse {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> unmarshalledReturn;
    auto _comInst = WDBRIRfcommServiceIdStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PhoneBookAccessPse(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBRRfcommServiceId>(unmarshalledReturn.Get());
}

+ (WDBRRfcommServiceId*)genericFileTransfer {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> unmarshalledReturn;
    auto _comInst = WDBRIRfcommServiceIdStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GenericFileTransfer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBRRfcommServiceId>(unmarshalledReturn.Get());
}

- (WFGUID*)uuid {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uuid(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (unsigned int)asShortId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId>(self);
    THROW_NS_IF_FAILED(_comInst->AsShortId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)asString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId>(self);
    THROW_NS_IF_FAILED(_comInst->AsString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDBRRfcommServiceProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProviderStatics> WDBRIRfcommServiceProviderStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProviderStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.Rfcomm.RfcommServiceProvider").Get(), &inst));
    return inst;
}

+ (void)createAsync:(WDBRRfcommServiceId*)serviceId
            success:(void (^)(WDBRRfcommServiceProvider*))success
            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommServiceProvider*>> unmarshalledReturn;
    auto _comInst = WDBRIRfcommServiceProviderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateAsync(_getRtInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId>(serviceId).Get(),
                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommServiceProvider*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommServiceProvider*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDBRRfcommServiceProvider>(result.Get()));
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

- (WDBRRfcommServiceId*)serviceId {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceId(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBRRfcommServiceId>(unmarshalledReturn.Get());
}

- (NSMutableDictionary* /* unsigned int, RTObject<WSSIBuffer>* */)sdpRawAttributes {
    ComPtr<IMap<unsigned int, ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_SdpRawAttributes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_UInt32_RTObject_WSSIBuffer_create(unmarshalledReturn.Get());
}

- (void)startAdvertising:(WNSStreamSocketListener*)listener {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider>(self);
    THROW_NS_IF_FAILED(
        _comInst->StartAdvertising(_getRtInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener>(listener).Get()));
}

- (void)stopAdvertising {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider>(self);
    THROW_NS_IF_FAILED(_comInst->StopAdvertising());
}

- (void)startAdvertisingWithRadioDiscoverability:(WNSStreamSocketListener*)listener radioDiscoverable:(BOOL)radioDiscoverable {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider2>(self);
    THROW_NS_IF_FAILED(_comInst->StartAdvertisingWithRadioDiscoverability(
        _getRtInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener>(listener).Get(), (boolean)radioDiscoverable));
}

@end

id RTProxiedNSDictionary_UInt32_RTObject_WSSIBuffer_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<DictionaryAdapterObj<
        IMapView<unsigned int, ABI::Windows::Storage::Streams::IBuffer*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<unsigned int, unsigned int, unsigned int, ABI::Windows::Storage::Streams::IBuffer*>>,
        RTMapViewObj<unsigned int,
                     unsigned int,
                     ABI::Windows::Storage::Streams::IBuffer*,
                     ABI::Windows::Storage::Streams::IBuffer*,
                     unsigned int,
                     RTObject<WSSIBuffer>,
                     IMapView<unsigned int, ABI::Windows::Storage::Streams::IBuffer*>,
                     dummyObjCCreator,
                     dummyObjCCreator,
                     dummyWRLCreator,
                     dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableDictionary_UInt32_RTObject_WSSIBuffer_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<MutableDictionaryAdapterObj<
        IMap<unsigned int, ABI::Windows::Storage::Streams::IBuffer*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<unsigned int, unsigned int, unsigned int, ABI::Windows::Storage::Streams::IBuffer*>>,
        RTMapObj<unsigned int,
                 unsigned int,
                 ABI::Windows::Storage::Streams::IBuffer*,
                 ABI::Windows::Storage::Streams::IBuffer*,
                 unsigned int,
                 RTObject<WSSIBuffer>,
                 IMap<unsigned int, ABI::Windows::Storage::Streams::IBuffer*>,
                 dummyObjCCreator,
                 dummyObjCCreator,
                 dummyWRLCreator,
                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
