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

// WindowsDevicesUsb.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Usb.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesUsb.h"
#include "WindowsDevicesUsb_priv.h"

@implementation WDUUsbControlRequestType

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbControlRequestType> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Usb.UsbControlRequestType").Get(), &out));
    return [_createRtProxy<WDUUsbControlRequestType>(out.Get()) retain];
}

- (WDUUsbTransferDirection)direction {
    ABI::Windows::Devices::Usb::UsbTransferDirection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbControlRequestType>(self);
    THROW_NS_IF_FAILED(_comInst->get_Direction(&unmarshalledReturn));
    return (WDUUsbTransferDirection)unmarshalledReturn;
}

- (void)setDirection:(WDUUsbTransferDirection)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbControlRequestType>(self);
    THROW_NS_IF_FAILED(_comInst->put_Direction((ABI::Windows::Devices::Usb::UsbTransferDirection)value));
}

- (WDUUsbControlTransferType)controlTransferType {
    ABI::Windows::Devices::Usb::UsbControlTransferType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbControlRequestType>(self);
    THROW_NS_IF_FAILED(_comInst->get_ControlTransferType(&unmarshalledReturn));
    return (WDUUsbControlTransferType)unmarshalledReturn;
}

- (void)setControlTransferType:(WDUUsbControlTransferType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbControlRequestType>(self);
    THROW_NS_IF_FAILED(_comInst->put_ControlTransferType((ABI::Windows::Devices::Usb::UsbControlTransferType)value));
}

- (WDUUsbControlRecipient)recipient {
    ABI::Windows::Devices::Usb::UsbControlRecipient unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbControlRequestType>(self);
    THROW_NS_IF_FAILED(_comInst->get_Recipient(&unmarshalledReturn));
    return (WDUUsbControlRecipient)unmarshalledReturn;
}

- (void)setRecipient:(WDUUsbControlRecipient)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbControlRequestType>(self);
    THROW_NS_IF_FAILED(_comInst->put_Recipient((ABI::Windows::Devices::Usb::UsbControlRecipient)value));
}

- (uint8_t)asByte {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbControlRequestType>(self);
    THROW_NS_IF_FAILED(_comInst->get_AsByte(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setAsByte:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbControlRequestType>(self);
    THROW_NS_IF_FAILED(_comInst->put_AsByte(value));
}

@end

@implementation WDUUsbSetupPacket

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbSetupPacket> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Usb::IUsbSetupPacketFactory> WDUIUsbSetupPacketFactory_inst() {
    ComPtr<ABI::Windows::Devices::Usb::IUsbSetupPacketFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Usb.UsbSetupPacket").Get(), &inst));
    return inst;
}

+ (WDUUsbSetupPacket*)makeWithEightByteBuffer:(RTObject<WSSIBuffer>*)eightByteBuffer {
    ComPtr<ABI::Windows::Devices::Usb::IUsbSetupPacket> unmarshalledReturn;
    auto _comInst = WDUIUsbSetupPacketFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithEightByteBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(eightByteBuffer).Get(),
                                                           unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDUUsbSetupPacket>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Usb.UsbSetupPacket").Get(), &out));
    return [_createRtProxy<WDUUsbSetupPacket>(out.Get()) retain];
}

- (WDUUsbControlRequestType*)requestType {
    ComPtr<ABI::Windows::Devices::Usb::IUsbControlRequestType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbSetupPacket>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestType(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbControlRequestType>(unmarshalledReturn.Get());
}

- (void)setRequestType:(WDUUsbControlRequestType*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbSetupPacket>(self);
    THROW_NS_IF_FAILED(_comInst->put_RequestType(_getRtInterface<ABI::Windows::Devices::Usb::IUsbControlRequestType>(value).Get()));
}

- (uint8_t)request {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbSetupPacket>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRequest:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbSetupPacket>(self);
    THROW_NS_IF_FAILED(_comInst->put_Request(value));
}

- (unsigned int)value {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbSetupPacket>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setValue:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbSetupPacket>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(value));
}

- (unsigned int)index {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbSetupPacket>(self);
    THROW_NS_IF_FAILED(_comInst->get_Index(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIndex:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbSetupPacket>(self);
    THROW_NS_IF_FAILED(_comInst->put_Index(value));
}

- (unsigned int)length {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbSetupPacket>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLength:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbSetupPacket>(self);
    THROW_NS_IF_FAILED(_comInst->put_Length(value));
}

@end

@implementation WDUUsbDeviceClass

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceClass> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Usb.UsbDeviceClass").Get(), &out));
    return [_createRtProxy<WDUUsbDeviceClass>(out.Get()) retain];
}

- (uint8_t)classCode {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDeviceClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClassCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setClassCode:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDeviceClass>(self);
    THROW_NS_IF_FAILED(_comInst->put_ClassCode(value));
}

- (id /* uint8_t */)subclassCode {
    ComPtr<IReference<uint8_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDeviceClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_SubclassCode(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint8_t, uint8_t>::convert(unmarshalledReturn.Get());
}

- (void)setSubclassCode:(id /* uint8_t */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDeviceClass>(self);
    THROW_NS_IF_FAILED(_comInst->put_SubclassCode(BuildNullable<uint8_t>(value)));
}

- (id /* uint8_t */)protocolCode {
    ComPtr<IReference<uint8_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDeviceClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtocolCode(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint8_t, uint8_t>::convert(unmarshalledReturn.Get());
}

- (void)setProtocolCode:(id /* uint8_t */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDeviceClass>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProtocolCode(BuildNullable<uint8_t>(value)));
}

@end

@implementation WDUUsbDeviceClasses

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceClasses> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceClassesStatics> WDUIUsbDeviceClassesStatics_inst() {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceClassesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Usb.UsbDeviceClasses").Get(), &inst));
    return inst;
}

+ (WDUUsbDeviceClass*)cdcControl {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceClass> unmarshalledReturn;
    auto _comInst = WDUIUsbDeviceClassesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CdcControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbDeviceClass>(unmarshalledReturn.Get());
}

+ (WDUUsbDeviceClass*)physical {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceClass> unmarshalledReturn;
    auto _comInst = WDUIUsbDeviceClassesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Physical(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbDeviceClass>(unmarshalledReturn.Get());
}

+ (WDUUsbDeviceClass*)personalHealthcare {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceClass> unmarshalledReturn;
    auto _comInst = WDUIUsbDeviceClassesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PersonalHealthcare(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbDeviceClass>(unmarshalledReturn.Get());
}

+ (WDUUsbDeviceClass*)activeSync {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceClass> unmarshalledReturn;
    auto _comInst = WDUIUsbDeviceClassesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ActiveSync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbDeviceClass>(unmarshalledReturn.Get());
}

+ (WDUUsbDeviceClass*)palmSync {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceClass> unmarshalledReturn;
    auto _comInst = WDUIUsbDeviceClassesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PalmSync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbDeviceClass>(unmarshalledReturn.Get());
}

+ (WDUUsbDeviceClass*)deviceFirmwareUpdate {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceClass> unmarshalledReturn;
    auto _comInst = WDUIUsbDeviceClassesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DeviceFirmwareUpdate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbDeviceClass>(unmarshalledReturn.Get());
}

+ (WDUUsbDeviceClass*)irda {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceClass> unmarshalledReturn;
    auto _comInst = WDUIUsbDeviceClassesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Irda(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbDeviceClass>(unmarshalledReturn.Get());
}

+ (WDUUsbDeviceClass*)measurement {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceClass> unmarshalledReturn;
    auto _comInst = WDUIUsbDeviceClassesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Measurement(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbDeviceClass>(unmarshalledReturn.Get());
}

+ (WDUUsbDeviceClass*)vendorSpecific {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceClass> unmarshalledReturn;
    auto _comInst = WDUIUsbDeviceClassesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VendorSpecific(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbDeviceClass>(unmarshalledReturn.Get());
}

@end

@implementation WDUUsbDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceStatics> WDUIUsbDeviceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Usb.UsbDevice").Get(), &inst));
    return inst;
}

+ (NSString*)getDeviceSelector:(unsigned int)vendorId productId:(unsigned int)productId winUsbInterfaceClass:(WFGUID*)winUsbInterfaceClass {
    HSTRING unmarshalledReturn;
    auto _comInst = WDUIUsbDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(vendorId, productId, winUsbInterfaceClass.guidValue, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorGuidOnly:(WFGUID*)winUsbInterfaceClass {
    HSTRING unmarshalledReturn;
    auto _comInst = WDUIUsbDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorGuidOnly(winUsbInterfaceClass.guidValue, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorVidPidOnly:(unsigned int)vendorId productId:(unsigned int)productId {
    HSTRING unmarshalledReturn;
    auto _comInst = WDUIUsbDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorVidPidOnly(vendorId, productId, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceClassSelector:(WDUUsbDeviceClass*)usbClass {
    HSTRING unmarshalledReturn;
    auto _comInst = WDUIUsbDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceClassSelector(_getRtInterface<ABI::Windows::Devices::Usb::IUsbDeviceClass>(usbClass).Get(),
                                                        &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDUUsbDevice*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Usb::UsbDevice*>> unmarshalledReturn;
    auto _comInst = WDUIUsbDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Usb::UsbDevice*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Usb::UsbDevice*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Usb::IUsbDevice> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDUUsbDevice>(result.Get()));
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

- (void)sendControlOutTransferAsync:(WDUUsbSetupPacket*)setupPacket
                             buffer:(RTObject<WSSIBuffer>*)buffer
                            success:(void (^)(unsigned int))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->SendControlOutTransferAsync(_getRtInterface<ABI::Windows::Devices::Usb::IUsbSetupPacket>(setupPacket).Get(),
                                              _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(),
                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<unsigned int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<unsigned int>* op, AsyncStatus status) {
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

- (void)sendControlOutTransferAsyncNoBuffer:(WDUUsbSetupPacket*)setupPacket
                                    success:(void (^)(unsigned int))success
                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->SendControlOutTransferAsyncNoBuffer(_getRtInterface<ABI::Windows::Devices::Usb::IUsbSetupPacket>(setupPacket).Get(),
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<unsigned int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<unsigned int>* op, AsyncStatus status) {
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

- (void)sendControlInTransferAsync:(WDUUsbSetupPacket*)setupPacket
                            buffer:(RTObject<WSSIBuffer>*)buffer
                           success:(void (^)(RTObject<WSSIBuffer>*))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDevice>(self);
    THROW_NS_IF_FAILED(_comInst->SendControlInTransferAsync(_getRtInterface<ABI::Windows::Devices::Usb::IUsbSetupPacket>(setupPacket).Get(),
                                                            _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(),
                                                            &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>* op,
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

- (void)sendControlInTransferAsyncNoBuffer:(WDUUsbSetupPacket*)setupPacket
                                   success:(void (^)(RTObject<WSSIBuffer>*))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->SendControlInTransferAsyncNoBuffer(_getRtInterface<ABI::Windows::Devices::Usb::IUsbSetupPacket>(setupPacket).Get(),
                                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>* op,
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

- (WDUUsbInterface*)defaultInterface {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterface> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultInterface(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbInterface>(unmarshalledReturn.Get());
}

- (WDUUsbDeviceDescriptor*)deviceDescriptor {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceDescriptor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceDescriptor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbDeviceDescriptor>(unmarshalledReturn.Get());
}

- (WDUUsbConfiguration*)configuration {
    ComPtr<ABI::Windows::Devices::Usb::IUsbConfiguration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_Configuration(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbConfiguration>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDUUsbInterface

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterface> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WDUUsbBulkInPipe* */)bulkInPipes {
    ComPtr<IVectorView<ABI::Windows::Devices::Usb::UsbBulkInPipe*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterface>(self);
    THROW_NS_IF_FAILED(_comInst->get_BulkInPipes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDUUsbBulkInPipe_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDUUsbInterruptInPipe* */)interruptInPipes {
    ComPtr<IVectorView<ABI::Windows::Devices::Usb::UsbInterruptInPipe*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterface>(self);
    THROW_NS_IF_FAILED(_comInst->get_InterruptInPipes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDUUsbInterruptInPipe_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDUUsbBulkOutPipe* */)bulkOutPipes {
    ComPtr<IVectorView<ABI::Windows::Devices::Usb::UsbBulkOutPipe*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterface>(self);
    THROW_NS_IF_FAILED(_comInst->get_BulkOutPipes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDUUsbBulkOutPipe_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDUUsbInterruptOutPipe* */)interruptOutPipes {
    ComPtr<IVectorView<ABI::Windows::Devices::Usb::UsbInterruptOutPipe*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterface>(self);
    THROW_NS_IF_FAILED(_comInst->get_InterruptOutPipes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDUUsbInterruptOutPipe_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDUUsbInterfaceSetting* */)interfaceSettings {
    ComPtr<IVectorView<ABI::Windows::Devices::Usb::UsbInterfaceSetting*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterface>(self);
    THROW_NS_IF_FAILED(_comInst->get_InterfaceSettings(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDUUsbInterfaceSetting_create(unmarshalledReturn.Get());
}

- (uint8_t)interfaceNumber {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterface>(self);
    THROW_NS_IF_FAILED(_comInst->get_InterfaceNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSArray* /* WDUUsbDescriptor* */)descriptors {
    ComPtr<IVectorView<ABI::Windows::Devices::Usb::UsbDescriptor*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterface>(self);
    THROW_NS_IF_FAILED(_comInst->get_Descriptors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDUUsbDescriptor_create(unmarshalledReturn.Get());
}

@end

@implementation WDUUsbDeviceDescriptor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceDescriptor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)bcdUsb {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDeviceDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_BcdUsb(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)maxPacketSize0 {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDeviceDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPacketSize0(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)vendorId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDeviceDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_VendorId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)productId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDeviceDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProductId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)bcdDeviceRevision {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDeviceDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_BcdDeviceRevision(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)numberOfConfigurations {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDeviceDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberOfConfigurations(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDUUsbConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WDUUsbInterface* */)usbInterfaces {
    ComPtr<IVectorView<ABI::Windows::Devices::Usb::UsbInterface*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsbInterfaces(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDUUsbInterface_create(unmarshalledReturn.Get());
}

- (WDUUsbConfigurationDescriptor*)configurationDescriptor {
    ComPtr<ABI::Windows::Devices::Usb::IUsbConfigurationDescriptor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConfigurationDescriptor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbConfigurationDescriptor>(unmarshalledReturn.Get());
}

- (NSArray* /* WDUUsbDescriptor* */)descriptors {
    ComPtr<IVectorView<ABI::Windows::Devices::Usb::UsbDescriptor*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Descriptors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDUUsbDescriptor_create(unmarshalledReturn.Get());
}

@end

@implementation WDUUsbDescriptor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbDescriptor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (uint8_t)length {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)descriptorType {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_DescriptorType(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)readDescriptorBuffer:(RTObject<WSSIBuffer>*)buffer {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->ReadDescriptorBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get()));
}

@end

@implementation WDUUsbConfigurationDescriptor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbConfigurationDescriptor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Usb::IUsbConfigurationDescriptorStatics> WDUIUsbConfigurationDescriptorStatics_inst() {
    ComPtr<ABI::Windows::Devices::Usb::IUsbConfigurationDescriptorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Usb.UsbConfigurationDescriptor").Get(),
                                                       &inst));
    return inst;
}

+ (BOOL)tryParse:(WDUUsbDescriptor*)descriptor parsed:(WDUUsbConfigurationDescriptor**)parsed {
    ComPtr<ABI::Windows::Devices::Usb::IUsbConfigurationDescriptor> parsedOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WDUIUsbConfigurationDescriptorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryParse(_getRtInterface<ABI::Windows::Devices::Usb::IUsbDescriptor>(descriptor).Get(),
                                          parsedOutUnmarshaled.GetAddressOf(),
                                          &unmarshalledReturn));
    *parsed = _createRtProxy<WDUUsbConfigurationDescriptor>(parsedOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

+ (WDUUsbConfigurationDescriptor*)parse:(WDUUsbDescriptor*)descriptor {
    ComPtr<ABI::Windows::Devices::Usb::IUsbConfigurationDescriptor> unmarshalledReturn;
    auto _comInst = WDUIUsbConfigurationDescriptorStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->Parse(_getRtInterface<ABI::Windows::Devices::Usb::IUsbDescriptor>(descriptor).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbConfigurationDescriptor>(unmarshalledReturn.Get());
}

- (uint8_t)configurationValue {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbConfigurationDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConfigurationValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)maxPowerMilliamps {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbConfigurationDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPowerMilliamps(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)selfPowered {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbConfigurationDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelfPowered(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)remoteWakeup {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbConfigurationDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteWakeup(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDUUsbInterfaceDescriptor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterfaceDescriptor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Usb::IUsbInterfaceDescriptorStatics> WDUIUsbInterfaceDescriptorStatics_inst() {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterfaceDescriptorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Usb.UsbInterfaceDescriptor").Get(), &inst));
    return inst;
}

+ (BOOL)tryParse:(WDUUsbDescriptor*)descriptor parsed:(WDUUsbInterfaceDescriptor**)parsed {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterfaceDescriptor> parsedOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WDUIUsbInterfaceDescriptorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryParse(_getRtInterface<ABI::Windows::Devices::Usb::IUsbDescriptor>(descriptor).Get(),
                                          parsedOutUnmarshaled.GetAddressOf(),
                                          &unmarshalledReturn));
    *parsed = _createRtProxy<WDUUsbInterfaceDescriptor>(parsedOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

+ (WDUUsbInterfaceDescriptor*)parse:(WDUUsbDescriptor*)descriptor {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterfaceDescriptor> unmarshalledReturn;
    auto _comInst = WDUIUsbInterfaceDescriptorStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->Parse(_getRtInterface<ABI::Windows::Devices::Usb::IUsbDescriptor>(descriptor).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbInterfaceDescriptor>(unmarshalledReturn.Get());
}

- (uint8_t)classCode {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterfaceDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClassCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)subclassCode {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterfaceDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_SubclassCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)protocolCode {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterfaceDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtocolCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)alternateSettingNumber {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterfaceDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlternateSettingNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)interfaceNumber {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterfaceDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_InterfaceNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDUUsbBulkInEndpointDescriptor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbBulkInEndpointDescriptor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)maxPacketSize {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkInEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPacketSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)endpointNumber {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkInEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndpointNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDUUsbBulkInPipe*)pipe {
    ComPtr<ABI::Windows::Devices::Usb::IUsbBulkInPipe> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkInEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pipe(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbBulkInPipe>(unmarshalledReturn.Get());
}

@end

@implementation WDUUsbInterruptInEndpointDescriptor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)maxPacketSize {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPacketSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)endpointNumber {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndpointNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)interval {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Interval(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WDUUsbInterruptInPipe*)pipe {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterruptInPipe> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pipe(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbInterruptInPipe>(unmarshalledReturn.Get());
}

@end

@implementation WDUUsbBulkOutEndpointDescriptor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)maxPacketSize {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPacketSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)endpointNumber {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndpointNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDUUsbBulkOutPipe*)pipe {
    ComPtr<ABI::Windows::Devices::Usb::IUsbBulkOutPipe> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pipe(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbBulkOutPipe>(unmarshalledReturn.Get());
}

@end

@implementation WDUUsbInterruptOutEndpointDescriptor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)maxPacketSize {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPacketSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)endpointNumber {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndpointNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)interval {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Interval(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WDUUsbInterruptOutPipe*)pipe {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterruptOutPipe> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pipe(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbInterruptOutPipe>(unmarshalledReturn.Get());
}

@end

@implementation WDUUsbEndpointDescriptor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbEndpointDescriptor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Usb::IUsbEndpointDescriptorStatics> WDUIUsbEndpointDescriptorStatics_inst() {
    ComPtr<ABI::Windows::Devices::Usb::IUsbEndpointDescriptorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Usb.UsbEndpointDescriptor").Get(), &inst));
    return inst;
}

+ (BOOL)tryParse:(WDUUsbDescriptor*)descriptor parsed:(WDUUsbEndpointDescriptor**)parsed {
    ComPtr<ABI::Windows::Devices::Usb::IUsbEndpointDescriptor> parsedOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WDUIUsbEndpointDescriptorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryParse(_getRtInterface<ABI::Windows::Devices::Usb::IUsbDescriptor>(descriptor).Get(),
                                          parsedOutUnmarshaled.GetAddressOf(),
                                          &unmarshalledReturn));
    *parsed = _createRtProxy<WDUUsbEndpointDescriptor>(parsedOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

+ (WDUUsbEndpointDescriptor*)parse:(WDUUsbDescriptor*)descriptor {
    ComPtr<ABI::Windows::Devices::Usb::IUsbEndpointDescriptor> unmarshalledReturn;
    auto _comInst = WDUIUsbEndpointDescriptorStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->Parse(_getRtInterface<ABI::Windows::Devices::Usb::IUsbDescriptor>(descriptor).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbEndpointDescriptor>(unmarshalledReturn.Get());
}

- (uint8_t)endpointNumber {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndpointNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDUUsbTransferDirection)direction {
    ABI::Windows::Devices::Usb::UsbTransferDirection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Direction(&unmarshalledReturn));
    return (WDUUsbTransferDirection)unmarshalledReturn;
}

- (WDUUsbEndpointType)endpointType {
    ABI::Windows::Devices::Usb::UsbEndpointType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndpointType(&unmarshalledReturn));
    return (WDUUsbEndpointType)unmarshalledReturn;
}

- (WDUUsbBulkInEndpointDescriptor*)asBulkInEndpointDescriptor {
    ComPtr<ABI::Windows::Devices::Usb::IUsbBulkInEndpointDescriptor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_AsBulkInEndpointDescriptor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbBulkInEndpointDescriptor>(unmarshalledReturn.Get());
}

- (WDUUsbInterruptInEndpointDescriptor*)asInterruptInEndpointDescriptor {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_AsInterruptInEndpointDescriptor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbInterruptInEndpointDescriptor>(unmarshalledReturn.Get());
}

- (WDUUsbBulkOutEndpointDescriptor*)asBulkOutEndpointDescriptor {
    ComPtr<ABI::Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_AsBulkOutEndpointDescriptor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbBulkOutEndpointDescriptor>(unmarshalledReturn.Get());
}

- (WDUUsbInterruptOutEndpointDescriptor*)asInterruptOutEndpointDescriptor {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbEndpointDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_AsInterruptOutEndpointDescriptor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbInterruptOutEndpointDescriptor>(unmarshalledReturn.Get());
}

@end

@implementation WDUUsbInterruptInEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterruptInEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIBuffer>*)interruptData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptInEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InterruptData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WDUUsbInterruptInPipe

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterruptInPipe> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDUUsbInterruptInEndpointDescriptor*)endpointDescriptor {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptInPipe>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndpointDescriptor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbInterruptInEndpointDescriptor>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)clearStallAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptInPipe>(self);
    THROW_NS_IF_FAILED(_comInst->ClearStallAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addDataReceivedEvent:(void (^)(WDUUsbInterruptInPipe*, WDUUsbInterruptInEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptInPipe>(self);
    THROW_NS_IF_FAILED(_comInst->add_DataReceived(
        Make<ITypedEventHandler_Windows_Devices_Usb_UsbInterruptInPipe_Windows_Devices_Usb_UsbInterruptInEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDataReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptInPipe>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DataReceived(token));
}

@end

@implementation WDUUsbBulkInPipe

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbBulkInPipe> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)maxTransferSizeBytes {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkInPipe>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxTransferSizeBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDUUsbBulkInEndpointDescriptor*)endpointDescriptor {
    ComPtr<ABI::Windows::Devices::Usb::IUsbBulkInEndpointDescriptor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkInPipe>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndpointDescriptor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbBulkInEndpointDescriptor>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)clearStallAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkInPipe>(self);
    THROW_NS_IF_FAILED(_comInst->ClearStallAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)setReadOptions:(WDUUsbReadOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkInPipe>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReadOptions((ABI::Windows::Devices::Usb::UsbReadOptions)value));
}

- (WDUUsbReadOptions)readOptions {
    ABI::Windows::Devices::Usb::UsbReadOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkInPipe>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadOptions(&unmarshalledReturn));
    return (WDUUsbReadOptions)unmarshalledReturn;
}

- (void)flushBuffer {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkInPipe>(self);
    THROW_NS_IF_FAILED(_comInst->FlushBuffer());
}

- (RTObject<WSSIInputStream>*)inputStream {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkInPipe>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

@end

@implementation WDUUsbBulkOutPipe

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbBulkOutPipe> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDUUsbBulkOutEndpointDescriptor*)endpointDescriptor {
    ComPtr<ABI::Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkOutPipe>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndpointDescriptor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbBulkOutEndpointDescriptor>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)clearStallAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkOutPipe>(self);
    THROW_NS_IF_FAILED(_comInst->ClearStallAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)setWriteOptions:(WDUUsbWriteOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkOutPipe>(self);
    THROW_NS_IF_FAILED(_comInst->put_WriteOptions((ABI::Windows::Devices::Usb::UsbWriteOptions)value));
}

- (WDUUsbWriteOptions)writeOptions {
    ABI::Windows::Devices::Usb::UsbWriteOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkOutPipe>(self);
    THROW_NS_IF_FAILED(_comInst->get_WriteOptions(&unmarshalledReturn));
    return (WDUUsbWriteOptions)unmarshalledReturn;
}

- (RTObject<WSSIOutputStream>*)outputStream {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbBulkOutPipe>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutputStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIOutputStream>(unmarshalledReturn.Get());
}

@end

@implementation WDUUsbInterruptOutPipe

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterruptOutPipe> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDUUsbInterruptOutEndpointDescriptor*)endpointDescriptor {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptOutPipe>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndpointDescriptor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbInterruptOutEndpointDescriptor>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)clearStallAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptOutPipe>(self);
    THROW_NS_IF_FAILED(_comInst->ClearStallAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)setWriteOptions:(WDUUsbWriteOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptOutPipe>(self);
    THROW_NS_IF_FAILED(_comInst->put_WriteOptions((ABI::Windows::Devices::Usb::UsbWriteOptions)value));
}

- (WDUUsbWriteOptions)writeOptions {
    ABI::Windows::Devices::Usb::UsbWriteOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptOutPipe>(self);
    THROW_NS_IF_FAILED(_comInst->get_WriteOptions(&unmarshalledReturn));
    return (WDUUsbWriteOptions)unmarshalledReturn;
}

- (RTObject<WSSIOutputStream>*)outputStream {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterruptOutPipe>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutputStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIOutputStream>(unmarshalledReturn.Get());
}

@end

@implementation WDUUsbInterfaceSetting

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterfaceSetting> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WDUUsbBulkInEndpointDescriptor* */)bulkInEndpoints {
    ComPtr<IVectorView<ABI::Windows::Devices::Usb::UsbBulkInEndpointDescriptor*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterfaceSetting>(self);
    THROW_NS_IF_FAILED(_comInst->get_BulkInEndpoints(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDUUsbBulkInEndpointDescriptor_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDUUsbInterruptInEndpointDescriptor* */)interruptInEndpoints {
    ComPtr<IVectorView<ABI::Windows::Devices::Usb::UsbInterruptInEndpointDescriptor*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterfaceSetting>(self);
    THROW_NS_IF_FAILED(_comInst->get_InterruptInEndpoints(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDUUsbInterruptInEndpointDescriptor_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDUUsbBulkOutEndpointDescriptor* */)bulkOutEndpoints {
    ComPtr<IVectorView<ABI::Windows::Devices::Usb::UsbBulkOutEndpointDescriptor*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterfaceSetting>(self);
    THROW_NS_IF_FAILED(_comInst->get_BulkOutEndpoints(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDUUsbBulkOutEndpointDescriptor_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDUUsbInterruptOutEndpointDescriptor* */)interruptOutEndpoints {
    ComPtr<IVectorView<ABI::Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterfaceSetting>(self);
    THROW_NS_IF_FAILED(_comInst->get_InterruptOutEndpoints(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDUUsbInterruptOutEndpointDescriptor_create(unmarshalledReturn.Get());
}

- (BOOL)selected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterfaceSetting>(self);
    THROW_NS_IF_FAILED(_comInst->get_Selected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)selectSettingAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterfaceSetting>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSettingAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (WDUUsbInterfaceDescriptor*)interfaceDescriptor {
    ComPtr<ABI::Windows::Devices::Usb::IUsbInterfaceDescriptor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterfaceSetting>(self);
    THROW_NS_IF_FAILED(_comInst->get_InterfaceDescriptor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDUUsbInterfaceDescriptor>(unmarshalledReturn.Get());
}

- (NSArray* /* WDUUsbDescriptor* */)descriptors {
    ComPtr<IVectorView<ABI::Windows::Devices::Usb::UsbDescriptor*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Usb::IUsbInterfaceSetting>(self);
    THROW_NS_IF_FAILED(_comInst->get_Descriptors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDUUsbDescriptor_create(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_WDUUsbBulkInEndpointDescriptor_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Usb::UsbBulkInEndpointDescriptor*>,
                                         RTArrayObj<ABI::Windows::Devices::Usb::IUsbBulkInEndpointDescriptor*,
                                                    IVectorView<ABI::Windows::Devices::Usb::UsbBulkInEndpointDescriptor*>,
                                                    WDUUsbBulkInEndpointDescriptor,
                                                    ABI::Windows::Devices::Usb::UsbBulkInEndpointDescriptor*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDUUsbBulkInPipe_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Usb::UsbBulkInPipe*>,
                                         RTArrayObj<ABI::Windows::Devices::Usb::IUsbBulkInPipe*,
                                                    IVectorView<ABI::Windows::Devices::Usb::UsbBulkInPipe*>,
                                                    WDUUsbBulkInPipe,
                                                    ABI::Windows::Devices::Usb::UsbBulkInPipe*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDUUsbBulkOutEndpointDescriptor_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Usb::UsbBulkOutEndpointDescriptor*>,
                                         RTArrayObj<ABI::Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor*,
                                                    IVectorView<ABI::Windows::Devices::Usb::UsbBulkOutEndpointDescriptor*>,
                                                    WDUUsbBulkOutEndpointDescriptor,
                                                    ABI::Windows::Devices::Usb::UsbBulkOutEndpointDescriptor*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDUUsbBulkOutPipe_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Usb::UsbBulkOutPipe*>,
                                         RTArrayObj<ABI::Windows::Devices::Usb::IUsbBulkOutPipe*,
                                                    IVectorView<ABI::Windows::Devices::Usb::UsbBulkOutPipe*>,
                                                    WDUUsbBulkOutPipe,
                                                    ABI::Windows::Devices::Usb::UsbBulkOutPipe*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDUUsbDescriptor_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Usb::UsbDescriptor*>,
                                         RTArrayObj<ABI::Windows::Devices::Usb::IUsbDescriptor*,
                                                    IVectorView<ABI::Windows::Devices::Usb::UsbDescriptor*>,
                                                    WDUUsbDescriptor,
                                                    ABI::Windows::Devices::Usb::UsbDescriptor*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDUUsbInterface_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Usb::UsbInterface*>,
                                         RTArrayObj<ABI::Windows::Devices::Usb::IUsbInterface*,
                                                    IVectorView<ABI::Windows::Devices::Usb::UsbInterface*>,
                                                    WDUUsbInterface,
                                                    ABI::Windows::Devices::Usb::UsbInterface*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDUUsbInterfaceSetting_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Usb::UsbInterfaceSetting*>,
                                         RTArrayObj<ABI::Windows::Devices::Usb::IUsbInterfaceSetting*,
                                                    IVectorView<ABI::Windows::Devices::Usb::UsbInterfaceSetting*>,
                                                    WDUUsbInterfaceSetting,
                                                    ABI::Windows::Devices::Usb::UsbInterfaceSetting*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDUUsbInterruptInEndpointDescriptor_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Usb::UsbInterruptInEndpointDescriptor*>,
                                         RTArrayObj<ABI::Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor*,
                                                    IVectorView<ABI::Windows::Devices::Usb::UsbInterruptInEndpointDescriptor*>,
                                                    WDUUsbInterruptInEndpointDescriptor,
                                                    ABI::Windows::Devices::Usb::UsbInterruptInEndpointDescriptor*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDUUsbInterruptInPipe_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Usb::UsbInterruptInPipe*>,
                                         RTArrayObj<ABI::Windows::Devices::Usb::IUsbInterruptInPipe*,
                                                    IVectorView<ABI::Windows::Devices::Usb::UsbInterruptInPipe*>,
                                                    WDUUsbInterruptInPipe,
                                                    ABI::Windows::Devices::Usb::UsbInterruptInPipe*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDUUsbInterruptOutEndpointDescriptor_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor*>,
                                         RTArrayObj<ABI::Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor*,
                                                    IVectorView<ABI::Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor*>,
                                                    WDUUsbInterruptOutEndpointDescriptor,
                                                    ABI::Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDUUsbInterruptOutPipe_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Usb::UsbInterruptOutPipe*>,
                                         RTArrayObj<ABI::Windows::Devices::Usb::IUsbInterruptOutPipe*,
                                                    IVectorView<ABI::Windows::Devices::Usb::UsbInterruptOutPipe*>,
                                                    WDUUsbInterruptOutPipe,
                                                    ABI::Windows::Devices::Usb::UsbInterruptOutPipe*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
