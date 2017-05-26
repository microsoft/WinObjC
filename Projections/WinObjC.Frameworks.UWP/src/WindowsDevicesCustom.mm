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

// WindowsDevicesCustom.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Custom.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesCustom.h"
#include "WindowsDevicesCustom_priv.h"

@implementation WDCIIOControlCode

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Custom::IIOControlCode> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDCIOControlAccessMode)accessMode {
    ABI::Windows::Devices::Custom::IOControlAccessMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Custom::IIOControlCode>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessMode(&unmarshalledReturn));
    return (WDCIOControlAccessMode)unmarshalledReturn;
}

- (WDCIOControlBufferingMethod)bufferingMethod {
    ABI::Windows::Devices::Custom::IOControlBufferingMethod unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Custom::IIOControlCode>(self);
    THROW_NS_IF_FAILED(_comInst->get_BufferingMethod(&unmarshalledReturn));
    return (WDCIOControlBufferingMethod)unmarshalledReturn;
}

- (unsigned short)function {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Custom::IIOControlCode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Function(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)deviceType {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Custom::IIOControlCode>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceType(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)controlCode {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Custom::IIOControlCode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ControlCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDCKnownDeviceTypes

ComPtr<ABI::Windows::Devices::Custom::IKnownDeviceTypesStatics> WDCIKnownDeviceTypesStatics_inst() {
    ComPtr<ABI::Windows::Devices::Custom::IKnownDeviceTypesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Custom.KnownDeviceTypes").Get(), &inst));
    return inst;
}

+ (unsigned short)unknown {
    unsigned short unmarshalledReturn;
    auto _comInst = WDCIKnownDeviceTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Unknown(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDCIOControlCode

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Custom::IIOControlCode> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Custom::IIOControlCodeFactory> WDCIIOControlCodeFactory_inst() {
    ComPtr<ABI::Windows::Devices::Custom::IIOControlCodeFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Custom.IOControlCode").Get(), &inst));
    return inst;
}

+ (WDCIOControlCode*)makeIOControlCode:(unsigned short)deviceType
                              function:(unsigned short)function
                            accessMode:(WDCIOControlAccessMode)accessMode
                       bufferingMethod:(WDCIOControlBufferingMethod)bufferingMethod {
    ComPtr<ABI::Windows::Devices::Custom::IIOControlCode> unmarshalledReturn;
    auto _comInst = WDCIIOControlCodeFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateIOControlCode(deviceType,
                                                     function,
                                                     (ABI::Windows::Devices::Custom::IOControlAccessMode)accessMode,
                                                     (ABI::Windows::Devices::Custom::IOControlBufferingMethod)bufferingMethod,
                                                     unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDCIOControlCode>(unmarshalledReturn.Get()) retain];
}

- (WDCIOControlAccessMode)accessMode {
    ABI::Windows::Devices::Custom::IOControlAccessMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Custom::IIOControlCode>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessMode(&unmarshalledReturn));
    return (WDCIOControlAccessMode)unmarshalledReturn;
}

- (WDCIOControlBufferingMethod)bufferingMethod {
    ABI::Windows::Devices::Custom::IOControlBufferingMethod unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Custom::IIOControlCode>(self);
    THROW_NS_IF_FAILED(_comInst->get_BufferingMethod(&unmarshalledReturn));
    return (WDCIOControlBufferingMethod)unmarshalledReturn;
}

- (unsigned short)function {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Custom::IIOControlCode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Function(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)deviceType {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Custom::IIOControlCode>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceType(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)controlCode {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Custom::IIOControlCode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ControlCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDCCustomDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Custom::ICustomDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Custom::ICustomDeviceStatics> WDCICustomDeviceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Custom::ICustomDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Custom.CustomDevice").Get(), &inst));
    return inst;
}

+ (NSString*)getDeviceSelector:(WFGUID*)classGuid {
    HSTRING unmarshalledReturn;
    auto _comInst = WDCICustomDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(classGuid.guidValue, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)fromIdAsync:(NSString*)deviceId
      desiredAccess:(WDCDeviceAccessMode)desiredAccess
        sharingMode:(WDCDeviceSharingMode)sharingMode
            success:(void (^)(WDCCustomDevice*))success
            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Custom::CustomDevice*>> unmarshalledReturn;
    auto _comInst = WDCICustomDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(),
                                             (ABI::Windows::Devices::Custom::DeviceAccessMode)desiredAccess,
                                             (ABI::Windows::Devices::Custom::DeviceSharingMode)sharingMode,
                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Custom::CustomDevice*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Custom::CustomDevice*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Custom::ICustomDevice> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDCCustomDevice>(result.Get()));
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

- (RTObject<WSSIInputStream>*)inputStream {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Custom::ICustomDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

- (RTObject<WSSIOutputStream>*)outputStream {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Custom::ICustomDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutputStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIOutputStream>(unmarshalledReturn.Get());
}

- (void)sendIOControlAsync:(RTObject<WDCIIOControlCode>*)ioControlCode
               inputBuffer:(RTObject<WSSIBuffer>*)inputBuffer
              outputBuffer:(RTObject<WSSIBuffer>*)outputBuffer
                   success:(void (^)(unsigned int))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Custom::ICustomDevice>(self);
    THROW_NS_IF_FAILED(_comInst->SendIOControlAsync(_getRtInterface<ABI::Windows::Devices::Custom::IIOControlCode>(ioControlCode).Get(),
                                                    _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(inputBuffer).Get(),
                                                    _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(outputBuffer).Get(),
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

- (void)trySendIOControlAsync:(RTObject<WDCIIOControlCode>*)ioControlCode
                  inputBuffer:(RTObject<WSSIBuffer>*)inputBuffer
                 outputBuffer:(RTObject<WSSIBuffer>*)outputBuffer
                      success:(void (^)(BOOL))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Custom::ICustomDevice>(self);
    THROW_NS_IF_FAILED(_comInst->TrySendIOControlAsync(_getRtInterface<ABI::Windows::Devices::Custom::IIOControlCode>(ioControlCode).Get(),
                                                       _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(inputBuffer).Get(),
                                                       _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(outputBuffer).Get(),
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

@end
