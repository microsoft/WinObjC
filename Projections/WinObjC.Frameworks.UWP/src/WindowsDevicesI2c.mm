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

// WindowsDevicesI2c.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.I2c.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesI2c.h"
#include "WindowsDevicesI2c_priv.h"

@implementation WDIII2cDeviceStatics

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::I2c::II2cDeviceStatics> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cDeviceStatics>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getDeviceSelectorFromFriendlyName:(NSString*)friendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cDeviceStatics>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromFriendlyName(nsStrToHstr(friendlyName).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)fromIdAsync:(NSString*)deviceId
           settings:(WDII2cConnectionSettings*)settings
            success:(void (^)(WDII2cDevice*))success
            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::I2c::I2cDevice*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cDeviceStatics>(self);
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(),
                                             _getRtInterface<ABI::Windows::Devices::I2c::II2cConnectionSettings>(settings).Get(),
                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::I2c::I2cDevice*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::I2c::I2cDevice*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::I2c::II2cDevice> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDII2cDevice>(result.Get()));
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

@implementation WDII2cConnectionSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::I2c::II2cConnectionSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::I2c::II2cConnectionSettingsFactory> WDIII2cConnectionSettingsFactory_inst() {
    ComPtr<ABI::Windows::Devices::I2c::II2cConnectionSettingsFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.I2c.I2cConnectionSettings").Get(), &inst));
    return inst;
}

+ (WDII2cConnectionSettings*)make:(int)slaveAddress {
    ComPtr<ABI::Windows::Devices::I2c::II2cConnectionSettings> unmarshalledReturn;
    auto _comInst = WDIII2cConnectionSettingsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(slaveAddress, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDII2cConnectionSettings>(unmarshalledReturn.Get()) retain];
}

- (int)slaveAddress {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_SlaveAddress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSlaveAddress:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_SlaveAddress(value));
}

- (WDII2cBusSpeed)busSpeed {
    ABI::Windows::Devices::I2c::I2cBusSpeed unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_BusSpeed(&unmarshalledReturn));
    return (WDII2cBusSpeed)unmarshalledReturn;
}

- (void)setBusSpeed:(WDII2cBusSpeed)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_BusSpeed((ABI::Windows::Devices::I2c::I2cBusSpeed)value));
}

- (WDII2cSharingMode)sharingMode {
    ABI::Windows::Devices::I2c::I2cSharingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_SharingMode(&unmarshalledReturn));
    return (WDII2cSharingMode)unmarshalledReturn;
}

- (void)setSharingMode:(WDII2cSharingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_SharingMode((ABI::Windows::Devices::I2c::I2cSharingMode)value));
}

@end

@implementation WDII2cDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::I2c::II2cDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::I2c::II2cDeviceStatics> WDIII2cDeviceStatics_inst() {
    ComPtr<ABI::Windows::Devices::I2c::II2cDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.I2c.I2cDevice").Get(), &inst));
    return inst;
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDIII2cDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorFromFriendlyName:(NSString*)friendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = WDIII2cDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromFriendlyName(nsStrToHstr(friendlyName).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)fromIdAsync:(NSString*)deviceId
           settings:(WDII2cConnectionSettings*)settings
            success:(void (^)(WDII2cDevice*))success
            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::I2c::I2cDevice*>> unmarshalledReturn;
    auto _comInst = WDIII2cDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(),
                                             _getRtInterface<ABI::Windows::Devices::I2c::II2cConnectionSettings>(settings).Get(),
                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::I2c::I2cDevice*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::I2c::I2cDevice*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::I2c::II2cDevice> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDII2cDevice>(result.Get()));
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
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDII2cConnectionSettings*)connectionSettings {
    ComPtr<ABI::Windows::Devices::I2c::II2cConnectionSettings> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionSettings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDII2cConnectionSettings>(unmarshalledReturn.Get());
}

- (void)write:(NSArray* /* uint8_t */)buffer {
    UINT32 __buffer_ArrayLen = 0;
    bool __buffer_IsTemp = false;
    uint8_t* __buffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(buffer, &__buffer_ArrayLen, &__buffer_Array, &__buffer_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cDevice>(self);
    THROW_NS_IF_FAILED(_comInst->Write(__buffer_ArrayLen, __buffer_Array));
    if (__buffer_IsTemp)
        CoTaskMemFree(__buffer_Array);
}

- (WDII2cTransferResult*)writePartial:(NSArray* /* uint8_t */)buffer {
    ABI::Windows::Devices::I2c::I2cTransferResult unmarshalledReturn;
    UINT32 __buffer_ArrayLen = 0;
    bool __buffer_IsTemp = false;
    uint8_t* __buffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(buffer, &__buffer_ArrayLen, &__buffer_Array, &__buffer_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cDevice>(self);
    THROW_NS_IF_FAILED(_comInst->WritePartial(__buffer_ArrayLen, __buffer_Array, &unmarshalledReturn));
    if (__buffer_IsTemp)
        CoTaskMemFree(__buffer_Array);
    return WDII2cTransferResult_create(unmarshalledReturn);
}

- (void)read:(NSArray* /* uint8_t */*)buffer {
    UINT32 __buffer_ArrayLen = (UINT32)[buffer count];
    uint8_t* __buffer_Array = (uint8_t*)[buffer ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cDevice>(self);
    THROW_NS_IF_FAILED(_comInst->Read(__buffer_ArrayLen, __buffer_Array));
}

- (WDII2cTransferResult*)readPartial:(NSArray* /* uint8_t */*)buffer {
    ABI::Windows::Devices::I2c::I2cTransferResult unmarshalledReturn;
    UINT32 __buffer_ArrayLen = (UINT32)[buffer count];
    uint8_t* __buffer_Array = (uint8_t*)[buffer ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cDevice>(self);
    THROW_NS_IF_FAILED(_comInst->ReadPartial(__buffer_ArrayLen, __buffer_Array, &unmarshalledReturn));
    return WDII2cTransferResult_create(unmarshalledReturn);
}

- (void)writeRead:(NSArray* /* uint8_t */)writeBuffer readBuffer:(NSArray* /* uint8_t */*)readBuffer {
    UINT32 __writeBuffer_ArrayLen = 0;
    bool __writeBuffer_IsTemp = false;
    uint8_t* __writeBuffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(writeBuffer, &__writeBuffer_ArrayLen, &__writeBuffer_Array, &__writeBuffer_IsTemp))
        assert(0);
    UINT32 __readBuffer_ArrayLen = (UINT32)[readBuffer count];
    uint8_t* __readBuffer_Array = (uint8_t*)[readBuffer ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cDevice>(self);
    THROW_NS_IF_FAILED(_comInst->WriteRead(__writeBuffer_ArrayLen, __writeBuffer_Array, __readBuffer_ArrayLen, __readBuffer_Array));
    if (__writeBuffer_IsTemp)
        CoTaskMemFree(__writeBuffer_Array);
}

- (WDII2cTransferResult*)writeReadPartial:(NSArray* /* uint8_t */)writeBuffer readBuffer:(NSArray* /* uint8_t */*)readBuffer {
    ABI::Windows::Devices::I2c::I2cTransferResult unmarshalledReturn;
    UINT32 __writeBuffer_ArrayLen = 0;
    bool __writeBuffer_IsTemp = false;
    uint8_t* __writeBuffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(writeBuffer, &__writeBuffer_ArrayLen, &__writeBuffer_Array, &__writeBuffer_IsTemp))
        assert(0);
    UINT32 __readBuffer_ArrayLen = (UINT32)[readBuffer count];
    uint8_t* __readBuffer_Array = (uint8_t*)[readBuffer ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cDevice>(self);
    THROW_NS_IF_FAILED(_comInst->WriteReadPartial(__writeBuffer_ArrayLen,
                                                  __writeBuffer_Array,
                                                  __readBuffer_ArrayLen,
                                                  __readBuffer_Array,
                                                  &unmarshalledReturn));
    if (__writeBuffer_IsTemp)
        CoTaskMemFree(__writeBuffer_Array);
    return WDII2cTransferResult_create(unmarshalledReturn);
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDII2cController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::I2c::II2cController> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::I2c::II2cControllerStatics> WDIII2cControllerStatics_inst() {
    ComPtr<ABI::Windows::Devices::I2c::II2cControllerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.I2c.I2cController").Get(), &inst));
    return inst;
}

+ (void)getControllersAsync:(RTObject<WDIPII2cProvider>*)provider
                    success:(void (^)(NSArray* /* WDII2cController* */))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::I2c::I2cController*>*>> unmarshalledReturn;
    auto _comInst = WDIII2cControllerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetControllersAsync(_getRtInterface<ABI::Windows::Devices::I2c::Provider::II2cProvider>(provider).Get(),
                                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Devices::I2c::I2cController*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::I2c::I2cController*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::I2c::I2cController*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WDII2cController_create(result.Get()));
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

+ (void)getDefaultAsyncWithSuccess:(void (^)(WDII2cController*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::I2c::I2cController*>> unmarshalledReturn;
    auto _comInst = WDIII2cControllerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::I2c::I2cController*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::I2c::I2cController*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::I2c::II2cController> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDII2cController>(result.Get()));
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

- (WDII2cDevice*)getDevice:(WDII2cConnectionSettings*)settings {
    ComPtr<ABI::Windows::Devices::I2c::II2cDevice> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::II2cController>(self);
    THROW_NS_IF_FAILED(_comInst->GetDevice(_getRtInterface<ABI::Windows::Devices::I2c::II2cConnectionSettings>(settings).Get(),
                                           unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDII2cDevice>(unmarshalledReturn.Get());
}

@end

@implementation WDII2cTransferResult {
    ABI::Windows::Devices::I2c::I2cTransferResult structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Devices::I2c::I2cTransferResult)s {
    WDII2cTransferResult* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Devices::I2c::I2cTransferResult*)internalStruct {
    return &structVal;
}
- (WDII2cTransferStatus)status {
    return (WDII2cTransferStatus)structVal.Status;
}
- (void)setStatus:(WDII2cTransferStatus)val {
    structVal.Status = (ABI::Windows::Devices::I2c::I2cTransferStatus)val;
}
- (unsigned int)bytesTransferred {
    return structVal.BytesTransferred;
}
- (void)setBytesTransferred:(unsigned int)val {
    structVal.BytesTransferred = val;
}
@end
id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDII2cController_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::I2c::I2cController*>,
                                         RTArrayObj<ABI::Windows::Devices::I2c::II2cController*,
                                                    IVectorView<ABI::Windows::Devices::I2c::I2cController*>,
                                                    WDII2cController,
                                                    ABI::Windows::Devices::I2c::I2cController*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
