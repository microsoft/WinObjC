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

// WindowsDevicesI2cProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.I2c.Provider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesI2cProvider.h"
#include "WindowsDevicesI2cProvider_priv.h"

@implementation WDIPII2cControllerProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::I2c::Provider::II2cControllerProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WDIPII2cDeviceProvider>*)getDeviceProvider:(WDIPProviderI2cConnectionSettings*)settings {
    ComPtr<ABI::Windows::Devices::I2c::Provider::II2cDeviceProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::Provider::II2cControllerProvider>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetDeviceProvider(_getRtInterface<ABI::Windows::Devices::I2c::Provider::IProviderI2cConnectionSettings>(settings).Get(),
                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDIPII2cDeviceProvider>(unmarshalledReturn.Get());
}

@end

@implementation WDIPII2cProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::I2c::Provider::II2cProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getControllersAsyncWithSuccess:(void (^)(NSArray* /* RTObject<WDIPII2cControllerProvider>* */))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::I2c::Provider::II2cControllerProvider*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::Provider::II2cProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetControllersAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Devices::I2c::Provider::II2cControllerProvider*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::I2c::Provider::II2cControllerProvider*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::I2c::Provider::II2cControllerProvider*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_RTObject_WDIPII2cControllerProvider_create(result.Get()));
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

@implementation WDIPII2cDeviceProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::I2c::Provider::II2cDeviceProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::Provider::II2cDeviceProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)write:(NSArray* /* uint8_t */)buffer {
    UINT32 __buffer_ArrayLen = 0;
    bool __buffer_IsTemp = false;
    uint8_t* __buffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(buffer, &__buffer_ArrayLen, &__buffer_Array, &__buffer_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::Provider::II2cDeviceProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Write(__buffer_ArrayLen, __buffer_Array));
    if (__buffer_IsTemp)
        CoTaskMemFree(__buffer_Array);
}

- (WDIPProviderI2cTransferResult*)writePartial:(NSArray* /* uint8_t */)buffer {
    ABI::Windows::Devices::I2c::Provider::ProviderI2cTransferResult unmarshalledReturn;
    UINT32 __buffer_ArrayLen = 0;
    bool __buffer_IsTemp = false;
    uint8_t* __buffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(buffer, &__buffer_ArrayLen, &__buffer_Array, &__buffer_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::Provider::II2cDeviceProvider>(self);
    THROW_NS_IF_FAILED(_comInst->WritePartial(__buffer_ArrayLen, __buffer_Array, &unmarshalledReturn));
    if (__buffer_IsTemp)
        CoTaskMemFree(__buffer_Array);
    return WDIPProviderI2cTransferResult_create(unmarshalledReturn);
}

- (void)read:(NSArray* /* uint8_t */*)buffer {
    UINT32 __buffer_ArrayLen = (UINT32)[buffer count];
    uint8_t* __buffer_Array = (uint8_t*)[buffer ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::Provider::II2cDeviceProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Read(__buffer_ArrayLen, __buffer_Array));
}

- (WDIPProviderI2cTransferResult*)readPartial:(NSArray* /* uint8_t */*)buffer {
    ABI::Windows::Devices::I2c::Provider::ProviderI2cTransferResult unmarshalledReturn;
    UINT32 __buffer_ArrayLen = (UINT32)[buffer count];
    uint8_t* __buffer_Array = (uint8_t*)[buffer ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::Provider::II2cDeviceProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ReadPartial(__buffer_ArrayLen, __buffer_Array, &unmarshalledReturn));
    return WDIPProviderI2cTransferResult_create(unmarshalledReturn);
}

- (void)writeRead:(NSArray* /* uint8_t */)writeBuffer readBuffer:(NSArray* /* uint8_t */*)readBuffer {
    UINT32 __writeBuffer_ArrayLen = 0;
    bool __writeBuffer_IsTemp = false;
    uint8_t* __writeBuffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(writeBuffer, &__writeBuffer_ArrayLen, &__writeBuffer_Array, &__writeBuffer_IsTemp))
        assert(0);
    UINT32 __readBuffer_ArrayLen = (UINT32)[readBuffer count];
    uint8_t* __readBuffer_Array = (uint8_t*)[readBuffer ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::Provider::II2cDeviceProvider>(self);
    THROW_NS_IF_FAILED(_comInst->WriteRead(__writeBuffer_ArrayLen, __writeBuffer_Array, __readBuffer_ArrayLen, __readBuffer_Array));
    if (__writeBuffer_IsTemp)
        CoTaskMemFree(__writeBuffer_Array);
}

- (WDIPProviderI2cTransferResult*)writeReadPartial:(NSArray* /* uint8_t */)writeBuffer readBuffer:(NSArray* /* uint8_t */*)readBuffer {
    ABI::Windows::Devices::I2c::Provider::ProviderI2cTransferResult unmarshalledReturn;
    UINT32 __writeBuffer_ArrayLen = 0;
    bool __writeBuffer_IsTemp = false;
    uint8_t* __writeBuffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(writeBuffer, &__writeBuffer_ArrayLen, &__writeBuffer_Array, &__writeBuffer_IsTemp))
        assert(0);
    UINT32 __readBuffer_ArrayLen = (UINT32)[readBuffer count];
    uint8_t* __readBuffer_Array = (uint8_t*)[readBuffer ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::Provider::II2cDeviceProvider>(self);
    THROW_NS_IF_FAILED(_comInst->WriteReadPartial(__writeBuffer_ArrayLen,
                                                  __writeBuffer_Array,
                                                  __readBuffer_ArrayLen,
                                                  __readBuffer_Array,
                                                  &unmarshalledReturn));
    if (__writeBuffer_IsTemp)
        CoTaskMemFree(__writeBuffer_Array);
    return WDIPProviderI2cTransferResult_create(unmarshalledReturn);
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDIPProviderI2cConnectionSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::I2c::Provider::IProviderI2cConnectionSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)slaveAddress {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::Provider::IProviderI2cConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_SlaveAddress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSlaveAddress:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::Provider::IProviderI2cConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_SlaveAddress(value));
}

- (WDIPProviderI2cBusSpeed)busSpeed {
    ABI::Windows::Devices::I2c::Provider::ProviderI2cBusSpeed unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::Provider::IProviderI2cConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_BusSpeed(&unmarshalledReturn));
    return (WDIPProviderI2cBusSpeed)unmarshalledReturn;
}

- (void)setBusSpeed:(WDIPProviderI2cBusSpeed)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::Provider::IProviderI2cConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_BusSpeed((ABI::Windows::Devices::I2c::Provider::ProviderI2cBusSpeed)value));
}

- (WDIPProviderI2cSharingMode)sharingMode {
    ABI::Windows::Devices::I2c::Provider::ProviderI2cSharingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::Provider::IProviderI2cConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_SharingMode(&unmarshalledReturn));
    return (WDIPProviderI2cSharingMode)unmarshalledReturn;
}

- (void)setSharingMode:(WDIPProviderI2cSharingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::I2c::Provider::IProviderI2cConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_SharingMode((ABI::Windows::Devices::I2c::Provider::ProviderI2cSharingMode)value));
}

@end

@implementation WDIPProviderI2cTransferResult {
    ABI::Windows::Devices::I2c::Provider::ProviderI2cTransferResult structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Devices::I2c::Provider::ProviderI2cTransferResult)s {
    WDIPProviderI2cTransferResult* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Devices::I2c::Provider::ProviderI2cTransferResult*)internalStruct {
    return &structVal;
}
- (WDIPProviderI2cTransferStatus)status {
    return (WDIPProviderI2cTransferStatus)structVal.Status;
}
- (void)setStatus:(WDIPProviderI2cTransferStatus)val {
    structVal.Status = (ABI::Windows::Devices::I2c::Provider::ProviderI2cTransferStatus)val;
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

id RTProxiedNSArray_RTObject_WDIPII2cControllerProvider_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::I2c::Provider::II2cControllerProvider*>,
                                         RTArrayObj<ABI::Windows::Devices::I2c::Provider::II2cControllerProvider*,
                                                    IVectorView<ABI::Windows::Devices::I2c::Provider::II2cControllerProvider*>,
                                                    RTObject<WDIPII2cControllerProvider>,
                                                    ABI::Windows::Devices::I2c::Provider::II2cControllerProvider*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
