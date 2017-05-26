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

// WindowsDevicesBluetoothGenericAttributeProfile.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Bluetooth.GenericAttributeProfile.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesBluetoothGenericAttributeProfile.h"
#include "WindowsDevicesBluetoothGenericAttributeProfile_priv.h"

@implementation WDBGGattDeviceService

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceServiceStatics> WDBGIGattDeviceServiceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceServiceStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattDeviceService").Get(), &inst));
    return inst;
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDBGGattDeviceService*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService*>>
        unmarshalledReturn;
    auto _comInst = WDBGIGattDeviceServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDBGGattDeviceService>(result.Get()));
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

+ (NSString*)getDeviceSelectorFromUuid:(WFGUID*)serviceUuid {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBGIGattDeviceServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromUuid(serviceUuid.guidValue, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorFromShortId:(unsigned short)serviceShortId {
    HSTRING unmarshalledReturn;
    auto _comInst = WDBGIGattDeviceServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromShortId(serviceShortId, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (WFGUID*)convertShortIdToUuid:(unsigned short)shortId {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattDeviceServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ConvertShortIdToUuid(shortId, &unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (NSArray* /* WDBGGattCharacteristic* */)getCharacteristics:(WFGUID*)characteristicUuid {
    ComPtr<IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService>(self);
    THROW_NS_IF_FAILED(_comInst->GetCharacteristics(characteristicUuid.guidValue, unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDBGGattCharacteristic_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDBGGattDeviceService* */)getIncludedServices:(WFGUID*)serviceUuid {
    ComPtr<IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService>(self);
    THROW_NS_IF_FAILED(_comInst->GetIncludedServices(serviceUuid.guidValue, unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDBGGattDeviceService_create(unmarshalledReturn.Get());
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFGUID*)uuid {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uuid(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (unsigned short)attributeHandle {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService>(self);
    THROW_NS_IF_FAILED(_comInst->get_AttributeHandle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (WDBBluetoothLEDevice*)device {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Device(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBBluetoothLEDevice>(unmarshalledReturn.Get());
}

- (NSArray* /* WDBGGattDeviceService* */)parentServices {
    ComPtr<IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentServices(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDBGGattDeviceService_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDBGGattCharacteristic* */)getAllCharacteristics {
    ComPtr<IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService2>(self);
    THROW_NS_IF_FAILED(_comInst->GetAllCharacteristics(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDBGGattCharacteristic_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDBGGattDeviceService* */)getAllIncludedServices {
    ComPtr<IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService2>(self);
    THROW_NS_IF_FAILED(_comInst->GetAllIncludedServices(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDBGGattDeviceService_create(unmarshalledReturn.Get());
}

@end

@implementation WDBGGattCharacteristic

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristicStatics> WDBGIGattCharacteristicStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristicStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattCharacteristic").Get(), &inst));
    return inst;
}

+ (WFGUID*)convertShortIdToUuid:(unsigned short)shortId {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ConvertShortIdToUuid(shortId, &unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (NSArray* /* WDBGGattDescriptor* */)getDescriptors:(WFGUID*)descriptorUuid {
    ComPtr<IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDescriptor*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(self);
    THROW_NS_IF_FAILED(_comInst->GetDescriptors(descriptorUuid.guidValue, unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDBGGattDescriptor_create(unmarshalledReturn.Get());
}

- (WDBGGattCharacteristicProperties)characteristicProperties {
    ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristicProperties unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(self);
    THROW_NS_IF_FAILED(_comInst->get_CharacteristicProperties(&unmarshalledReturn));
    return (WDBGGattCharacteristicProperties)unmarshalledReturn;
}

- (WDBGGattProtectionLevel)protectionLevel {
    ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattProtectionLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionLevel(&unmarshalledReturn));
    return (WDBGGattProtectionLevel)unmarshalledReturn;
}

- (void)setProtectionLevel:(WDBGGattProtectionLevel)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ProtectionLevel((ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattProtectionLevel)value));
}

- (NSString*)userDescription {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserDescription(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFGUID*)uuid {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uuid(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (unsigned short)attributeHandle {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(self);
    THROW_NS_IF_FAILED(_comInst->get_AttributeHandle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSArray* /* WDBGGattPresentationFormat* */)presentationFormats {
    ComPtr<IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattPresentationFormat*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(self);
    THROW_NS_IF_FAILED(_comInst->get_PresentationFormats(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDBGGattPresentationFormat_create(unmarshalledReturn.Get());
}

- (void)readValueAsyncWithSuccess:(void (^)(WDBGGattReadResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(self);
    THROW_NS_IF_FAILED(_comInst->ReadValueAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDBGGattReadResult>(result.Get()));
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

- (void)readValueWithCacheModeAsync:(WDBBluetoothCacheMode)cacheMode
                            success:(void (^)(WDBGGattReadResult*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReadValueWithCacheModeAsync((ABI::Windows::Devices::Bluetooth::BluetoothCacheMode)cacheMode, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDBGGattReadResult>(result.Get()));
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

- (void)writeValueAsync:(RTObject<WSSIBuffer>*)value
                success:(void (^)(WDBGGattCommunicationStatus))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(self);
    THROW_NS_IF_FAILED(
        _comInst->WriteValueAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WDBGGattCommunicationStatus)result);
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

- (void)writeValueWithOptionAsync:(RTObject<WSSIBuffer>*)value
                      writeOption:(WDBGGattWriteOption)writeOption
                          success:(void (^)(WDBGGattCommunicationStatus))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(self);
    THROW_NS_IF_FAILED(
        _comInst->WriteValueWithOptionAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get(),
                                            (ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattWriteOption)writeOption,
                                            &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WDBGGattCommunicationStatus)result);
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

- (void)readClientCharacteristicConfigurationDescriptorAsyncWithSuccess:
            (void (^)(WDBGGattReadClientCharacteristicConfigurationDescriptorResult*))success
                                                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadClientCharacteristicConfigurationDescriptorResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(self);
    THROW_NS_IF_FAILED(_comInst->ReadClientCharacteristicConfigurationDescriptorAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
            ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadClientCharacteristicConfigurationDescriptorResult*>,
        FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<
            ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadClientCharacteristicConfigurationDescriptorResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<
                    ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadClientCharacteristicConfigurationDescriptorResult>
                    result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDBGGattReadClientCharacteristicConfigurationDescriptorResult>(result.Get()));
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

- (void)writeClientCharacteristicConfigurationDescriptorAsync:
            (WDBGGattClientCharacteristicConfigurationDescriptorValue)clientCharacteristicConfigurationDescriptorValue
                                                      success:(void (^)(WDBGGattCommunicationStatus))success
                                                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(self);
    THROW_NS_IF_FAILED(_comInst->WriteClientCharacteristicConfigurationDescriptorAsync(
        (ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattClientCharacteristicConfigurationDescriptorValue)
            clientCharacteristicConfigurationDescriptorValue,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WDBGGattCommunicationStatus)result);
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

- (EventRegistrationToken)addValueChangedEvent:(void (^)(WDBGGattCharacteristic*, WDBGGattValueChangedEventArgs*))valueChangedHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(self);
    THROW_NS_IF_FAILED(_comInst->add_ValueChanged(
        Make<
            ITypedEventHandler_Windows_Devices_Bluetooth_GenericAttributeProfile_GattCharacteristic_Windows_Devices_Bluetooth_GenericAttributeProfile_GattValueChangedEventArgs>(
            valueChangedHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeValueChangedEvent:(EventRegistrationToken)valueChangedEventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ValueChanged(valueChangedEventCookie));
}

- (WDBGGattDeviceService*)service {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Service(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBGGattDeviceService>(unmarshalledReturn.Get());
}

- (NSArray* /* WDBGGattDescriptor* */)getAllDescriptors {
    ComPtr<IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDescriptor*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic2>(self);
    THROW_NS_IF_FAILED(_comInst->GetAllDescriptors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDBGGattDescriptor_create(unmarshalledReturn.Get());
}

@end

@implementation WDBGGattDescriptor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptorStatics> WDBGIGattDescriptorStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptorStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattDescriptor").Get(), &inst));
    return inst;
}

+ (WFGUID*)convertShortIdToUuid:(unsigned short)shortId {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattDescriptorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ConvertShortIdToUuid(shortId, &unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WDBGGattProtectionLevel)protectionLevel {
    ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattProtectionLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionLevel(&unmarshalledReturn));
    return (WDBGGattProtectionLevel)unmarshalledReturn;
}

- (void)setProtectionLevel:(WDBGGattProtectionLevel)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptor>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ProtectionLevel((ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattProtectionLevel)value));
}

- (WFGUID*)uuid {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uuid(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (unsigned short)attributeHandle {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_AttributeHandle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)readValueAsyncWithSuccess:(void (^)(WDBGGattReadResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->ReadValueAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDBGGattReadResult>(result.Get()));
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

- (void)readValueWithCacheModeAsync:(WDBBluetoothCacheMode)cacheMode
                            success:(void (^)(WDBGGattReadResult*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptor>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReadValueWithCacheModeAsync((ABI::Windows::Devices::Bluetooth::BluetoothCacheMode)cacheMode, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDBGGattReadResult>(result.Get()));
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

- (void)writeValueAsync:(RTObject<WSSIBuffer>*)value
                success:(void (^)(WDBGGattCommunicationStatus))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptor>(self);
    THROW_NS_IF_FAILED(
        _comInst->WriteValueAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WDBGGattCommunicationStatus)result);
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

@implementation WDBGGattPresentationFormat

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormat> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormatStatics>
WDBGIGattPresentationFormatStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormatStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattPresentationFormat").Get(), &inst));
    return inst;
}

+ (uint8_t)bluetoothSigAssignedNumbers {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BluetoothSigAssignedNumbers(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)formatType {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_FormatType(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)exponent {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Exponent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)unit {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Unit(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)Namespace {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Namespace(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)Description {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDBGGattReadResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDBGGattCommunicationStatus)status {
    ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDBGGattCommunicationStatus)unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)value {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WDBGGattReadClientCharacteristicConfigurationDescriptorResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadClientCharacteristicConfigurationDescriptorResult>
        defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDBGGattCommunicationStatus)status {
    ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadClientCharacteristicConfigurationDescriptorResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDBGGattCommunicationStatus)unmarshalledReturn;
}

- (WDBGGattClientCharacteristicConfigurationDescriptorValue)clientCharacteristicConfigurationDescriptor {
    ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattClientCharacteristicConfigurationDescriptorValue unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadClientCharacteristicConfigurationDescriptorResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClientCharacteristicConfigurationDescriptor(&unmarshalledReturn));
    return (WDBGGattClientCharacteristicConfigurationDescriptorValue)unmarshalledReturn;
}

@end

@implementation WDBGGattValueChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattValueChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIBuffer>*)characteristicValue {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattValueChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CharacteristicValue(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattValueChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

@end

@implementation WDBGGattServiceUuids

ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattServiceUuidsStatics> WDBGIGattServiceUuidsStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattServiceUuidsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattServiceUuids").Get(), &inst));
    return inst;
}

+ (WFGUID*)battery {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Battery(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)bloodPressure {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BloodPressure(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)cyclingSpeedAndCadence {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CyclingSpeedAndCadence(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)genericAccess {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GenericAccess(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)genericAttribute {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GenericAttribute(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)glucose {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Glucose(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)healthThermometer {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HealthThermometer(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)heartRate {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HeartRate(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)runningSpeedAndCadence {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RunningSpeedAndCadence(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattServiceUuidsStatics2> WDBGIGattServiceUuidsStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattServiceUuidsStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattServiceUuids").Get(), &inst));
    return inst;
}

+ (WFGUID*)alertNotification {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_AlertNotification(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)currentTime {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_CurrentTime(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)cyclingPower {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_CyclingPower(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)deviceInformation {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_DeviceInformation(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)humanInterfaceDevice {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_HumanInterfaceDevice(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)immediateAlert {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ImmediateAlert(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)linkLoss {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_LinkLoss(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)locationAndNavigation {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_LocationAndNavigation(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)nextDstChange {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_NextDstChange(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)phoneAlertStatus {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_PhoneAlertStatus(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)referenceTimeUpdate {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ReferenceTimeUpdate(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)scanParameters {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ScanParameters(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)txPower {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattServiceUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_TxPower(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WDBGGattCharacteristicUuids

ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristicUuidsStatics>
WDBGIGattCharacteristicUuidsStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristicUuidsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattCharacteristicUuids").Get(), &inst));
    return inst;
}

+ (WFGUID*)batteryLevel {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BatteryLevel(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)bloodPressureFeature {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BloodPressureFeature(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)bloodPressureMeasurement {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BloodPressureMeasurement(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)bodySensorLocation {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BodySensorLocation(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)cscFeature {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CscFeature(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)cscMeasurement {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CscMeasurement(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)glucoseFeature {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GlucoseFeature(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)glucoseMeasurement {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GlucoseMeasurement(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)glucoseMeasurementContext {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GlucoseMeasurementContext(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)heartRateControlPoint {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HeartRateControlPoint(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)heartRateMeasurement {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HeartRateMeasurement(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)intermediateCuffPressure {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IntermediateCuffPressure(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)intermediateTemperature {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IntermediateTemperature(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)measurementInterval {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MeasurementInterval(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)recordAccessControlPoint {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RecordAccessControlPoint(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)rscFeature {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RscFeature(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)rscMeasurement {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RscMeasurement(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)sCControlPoint {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SCControlPoint(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)sensorLocation {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SensorLocation(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)temperatureMeasurement {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TemperatureMeasurement(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)temperatureType {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TemperatureType(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristicUuidsStatics2>
WDBGIGattCharacteristicUuidsStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristicUuidsStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattCharacteristicUuids").Get(), &inst));
    return inst;
}

+ (WFGUID*)alertCategoryId {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_AlertCategoryId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)alertCategoryIdBitMask {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_AlertCategoryIdBitMask(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)alertLevel {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_AlertLevel(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)alertNotificationControlPoint {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_AlertNotificationControlPoint(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)alertStatus {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_AlertStatus(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)gapAppearance {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_GapAppearance(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)bootKeyboardInputReport {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_BootKeyboardInputReport(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)bootKeyboardOutputReport {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_BootKeyboardOutputReport(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)bootMouseInputReport {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_BootMouseInputReport(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)currentTime {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_CurrentTime(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)cyclingPowerControlPoint {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_CyclingPowerControlPoint(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)cyclingPowerFeature {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_CyclingPowerFeature(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)cyclingPowerMeasurement {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_CyclingPowerMeasurement(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)cyclingPowerVector {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_CyclingPowerVector(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)dateTime {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_DateTime(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)dayDateTime {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_DayDateTime(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)dayOfWeek {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_DayOfWeek(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)gapDeviceName {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_GapDeviceName(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)dstOffset {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_DstOffset(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)exactTime256 {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExactTime256(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)firmwareRevisionString {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_FirmwareRevisionString(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)hardwareRevisionString {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_HardwareRevisionString(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)hidControlPoint {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_HidControlPoint(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)hidInformation {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_HidInformation(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)ieee1107320601RegulatoryCertificationDataList {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ieee1107320601RegulatoryCertificationDataList(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)lnControlPoint {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_LnControlPoint(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)lnFeature {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_LnFeature(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)localTimeInformation {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_LocalTimeInformation(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)locationAndSpeed {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_LocationAndSpeed(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)manufacturerNameString {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ManufacturerNameString(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)modelNumberString {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ModelNumberString(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)navigation {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_Navigation(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)newAlert __attribute__((ns_returns_not_retained)) {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_NewAlert(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)gapPeripheralPreferredConnectionParameters {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_GapPeripheralPreferredConnectionParameters(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)gapPeripheralPrivacyFlag {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_GapPeripheralPrivacyFlag(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)pnpId {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_PnpId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)positionQuality {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_PositionQuality(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)protocolMode {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ProtocolMode(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)gapReconnectionAddress {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_GapReconnectionAddress(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)referenceTimeInformation {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ReferenceTimeInformation(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)report {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_Report(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)reportMap {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ReportMap(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)ringerControlPoint {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_RingerControlPoint(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)ringerSetting {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_RingerSetting(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)scanIntervalWindow {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ScanIntervalWindow(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)scanRefresh {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ScanRefresh(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)serialNumberString {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_SerialNumberString(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)gattServiceChanged {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_GattServiceChanged(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)softwareRevisionString {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_SoftwareRevisionString(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)supportedNewAlertCategory {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_SupportedNewAlertCategory(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)supportUnreadAlertCategory {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_SupportUnreadAlertCategory(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)systemId {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_SystemId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)timeAccuracy {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_TimeAccuracy(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)timeSource {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_TimeSource(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)timeUpdateControlPoint {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_TimeUpdateControlPoint(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)timeUpdateState {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_TimeUpdateState(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)timeWithDst {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_TimeWithDst(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)timeZone {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_TimeZone(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)txPowerLevel {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_TxPowerLevel(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)unreadAlertStatus {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattCharacteristicUuidsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_UnreadAlertStatus(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WDBGGattDescriptorUuids

ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptorUuidsStatics> WDBGIGattDescriptorUuidsStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptorUuidsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattDescriptorUuids").Get(), &inst));
    return inst;
}

+ (WFGUID*)characteristicAggregateFormat {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattDescriptorUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CharacteristicAggregateFormat(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)characteristicExtendedProperties {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattDescriptorUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CharacteristicExtendedProperties(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)characteristicPresentationFormat {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattDescriptorUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CharacteristicPresentationFormat(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)characteristicUserDescription {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattDescriptorUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CharacteristicUserDescription(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)clientCharacteristicConfiguration {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattDescriptorUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ClientCharacteristicConfiguration(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)serverCharacteristicConfiguration {
    GUID unmarshalledReturn;
    auto _comInst = WDBGIGattDescriptorUuidsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ServerCharacteristicConfiguration(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WDBGGattReliableWriteTransaction

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReliableWriteTransaction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattReliableWriteTransaction").Get(), &out));
    return [_createRtProxy<WDBGGattReliableWriteTransaction>(out.Get()) retain];
}

- (void)writeValue:(WDBGGattCharacteristic*)characteristic value:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReliableWriteTransaction>(self);
    THROW_NS_IF_FAILED(_comInst->WriteValue(
        _getRtInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(characteristic).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (void)commitAsyncWithSuccess:(void (^)(WDBGGattCommunicationStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReliableWriteTransaction>(self);
    THROW_NS_IF_FAILED(_comInst->CommitAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WDBGGattCommunicationStatus)result);
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

@implementation WDBGGattPresentationFormatTypes

ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormatTypesStatics>
WDBGIGattPresentationFormatTypesStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormatTypesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattPresentationFormatTypes").Get(), &inst));
    return inst;
}

+ (uint8_t)boolean {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Boolean(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)bit2 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Bit2(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)nibble {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Nibble(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)uInt8 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UInt8(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)uInt12 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UInt12(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)uInt16 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UInt16(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)uInt24 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UInt24(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)uInt32 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UInt32(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)uInt48 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UInt48(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)uInt64 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UInt64(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)uInt128 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UInt128(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)sInt8 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SInt8(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)sInt12 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SInt12(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)sInt16 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SInt16(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)sInt24 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SInt24(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)sInt32 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SInt32(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)sInt48 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SInt48(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)sInt64 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SInt64(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)sInt128 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SInt128(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)float32 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Float32(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)float64 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Float64(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)sFloat {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SFloat(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)Float {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Float(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)dUInt16 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DUInt16(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)utf8 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Utf8(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)utf16 {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Utf16(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)Struct {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBGIGattPresentationFormatTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Struct(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

id RTProxiedNSArray_WDBGGattCharacteristic_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic*>,
                        RTArrayObj<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic*,
                                   IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic*>,
                                   WDBGGattCharacteristic,
                                   ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDBGGattDescriptor_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDescriptor*>,
                                         RTArrayObj<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptor*,
                                                    IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDescriptor*>,
                                                    WDBGGattDescriptor,
                                                    ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDescriptor*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDBGGattPresentationFormat_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattPresentationFormat*>,
                        RTArrayObj<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormat*,
                                   IVectorView<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattPresentationFormat*>,
                                   WDBGGattPresentationFormat,
                                   ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattPresentationFormat*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
