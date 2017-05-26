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

// WindowsDevicesSpi.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Spi.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesSpi.h"
#include "WindowsDevicesSpi_priv.h"

@implementation WDSISpiDeviceStatics

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Spi::ISpiDeviceStatics> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiDeviceStatics>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getDeviceSelectorFromFriendlyName:(NSString*)friendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiDeviceStatics>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromFriendlyName(nsStrToHstr(friendlyName).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSSpiBusInfo*)getBusInfo:(NSString*)busId {
    ComPtr<ABI::Windows::Devices::Spi::ISpiBusInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiDeviceStatics>(self);
    THROW_NS_IF_FAILED(_comInst->GetBusInfo(nsStrToHstr(busId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSpiBusInfo>(unmarshalledReturn.Get());
}

- (void)fromIdAsync:(NSString*)busId
           settings:(WDSSpiConnectionSettings*)settings
            success:(void (^)(WDSSpiDevice*))success
            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Spi::SpiDevice*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiDeviceStatics>(self);
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(busId).Get(),
                                             _getRtInterface<ABI::Windows::Devices::Spi::ISpiConnectionSettings>(settings).Get(),
                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Spi::SpiDevice*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Spi::SpiDevice*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Spi::ISpiDevice> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSpiDevice>(result.Get()));
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

@implementation WDSSpiConnectionSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Spi::ISpiConnectionSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Spi::ISpiConnectionSettingsFactory> WDSISpiConnectionSettingsFactory_inst() {
    ComPtr<ABI::Windows::Devices::Spi::ISpiConnectionSettingsFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Spi.SpiConnectionSettings").Get(), &inst));
    return inst;
}

+ (WDSSpiConnectionSettings*)make:(int)chipSelectLine {
    ComPtr<ABI::Windows::Devices::Spi::ISpiConnectionSettings> unmarshalledReturn;
    auto _comInst = WDSISpiConnectionSettingsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(chipSelectLine, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDSSpiConnectionSettings>(unmarshalledReturn.Get()) retain];
}

- (int)chipSelectLine {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChipSelectLine(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setChipSelectLine:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_ChipSelectLine(value));
}

- (WDSSpiMode)mode {
    ABI::Windows::Devices::Spi::SpiMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WDSSpiMode)unmarshalledReturn;
}

- (void)setMode:(WDSSpiMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mode((ABI::Windows::Devices::Spi::SpiMode)value));
}

- (int)dataBitLength {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataBitLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDataBitLength:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_DataBitLength(value));
}

- (int)clockFrequency {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClockFrequency(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setClockFrequency:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_ClockFrequency(value));
}

- (WDSSpiSharingMode)sharingMode {
    ABI::Windows::Devices::Spi::SpiSharingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_SharingMode(&unmarshalledReturn));
    return (WDSSpiSharingMode)unmarshalledReturn;
}

- (void)setSharingMode:(WDSSpiSharingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_SharingMode((ABI::Windows::Devices::Spi::SpiSharingMode)value));
}

@end

@implementation WDSSpiBusInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Spi::ISpiBusInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)chipSelectLineCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiBusInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChipSelectLineCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)minClockFrequency {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiBusInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinClockFrequency(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)maxClockFrequency {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiBusInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxClockFrequency(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSArray* /* int */)supportedDataBitLengths {
    ComPtr<IVectorView<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiBusInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedDataBitLengths(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_Int32_create(unmarshalledReturn.Get());
}

@end

@implementation WDSSpiDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Spi::ISpiDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Spi::ISpiDeviceStatics> WDSISpiDeviceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Spi::ISpiDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Spi.SpiDevice").Get(), &inst));
    return inst;
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDSISpiDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorFromFriendlyName:(NSString*)friendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = WDSISpiDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromFriendlyName(nsStrToHstr(friendlyName).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (WDSSpiBusInfo*)getBusInfo:(NSString*)busId {
    ComPtr<ABI::Windows::Devices::Spi::ISpiBusInfo> unmarshalledReturn;
    auto _comInst = WDSISpiDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetBusInfo(nsStrToHstr(busId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSpiBusInfo>(unmarshalledReturn.Get());
}

+ (void)fromIdAsync:(NSString*)busId
           settings:(WDSSpiConnectionSettings*)settings
            success:(void (^)(WDSSpiDevice*))success
            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Spi::SpiDevice*>> unmarshalledReturn;
    auto _comInst = WDSISpiDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(busId).Get(),
                                             _getRtInterface<ABI::Windows::Devices::Spi::ISpiConnectionSettings>(settings).Get(),
                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Spi::SpiDevice*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Spi::SpiDevice*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Spi::ISpiDevice> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSpiDevice>(result.Get()));
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
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSSpiConnectionSettings*)connectionSettings {
    ComPtr<ABI::Windows::Devices::Spi::ISpiConnectionSettings> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionSettings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSpiConnectionSettings>(unmarshalledReturn.Get());
}

- (void)write:(NSArray* /* uint8_t */)buffer {
    UINT32 __buffer_ArrayLen = 0;
    bool __buffer_IsTemp = false;
    uint8_t* __buffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(buffer, &__buffer_ArrayLen, &__buffer_Array, &__buffer_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiDevice>(self);
    THROW_NS_IF_FAILED(_comInst->Write(__buffer_ArrayLen, __buffer_Array));
    if (__buffer_IsTemp)
        CoTaskMemFree(__buffer_Array);
}

- (void)read:(NSArray* /* uint8_t */*)buffer {
    UINT32 __buffer_ArrayLen = (UINT32)[buffer count];
    uint8_t* __buffer_Array = (uint8_t*)[buffer ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiDevice>(self);
    THROW_NS_IF_FAILED(_comInst->Read(__buffer_ArrayLen, __buffer_Array));
}

- (void)transferSequential:(NSArray* /* uint8_t */)writeBuffer readBuffer:(NSArray* /* uint8_t */*)readBuffer {
    UINT32 __writeBuffer_ArrayLen = 0;
    bool __writeBuffer_IsTemp = false;
    uint8_t* __writeBuffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(writeBuffer, &__writeBuffer_ArrayLen, &__writeBuffer_Array, &__writeBuffer_IsTemp))
        assert(0);
    UINT32 __readBuffer_ArrayLen = (UINT32)[readBuffer count];
    uint8_t* __readBuffer_Array = (uint8_t*)[readBuffer ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->TransferSequential(__writeBuffer_ArrayLen, __writeBuffer_Array, __readBuffer_ArrayLen, __readBuffer_Array));
    if (__writeBuffer_IsTemp)
        CoTaskMemFree(__writeBuffer_Array);
}

- (void)transferFullDuplex:(NSArray* /* uint8_t */)writeBuffer readBuffer:(NSArray* /* uint8_t */*)readBuffer {
    UINT32 __writeBuffer_ArrayLen = 0;
    bool __writeBuffer_IsTemp = false;
    uint8_t* __writeBuffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(writeBuffer, &__writeBuffer_ArrayLen, &__writeBuffer_Array, &__writeBuffer_IsTemp))
        assert(0);
    UINT32 __readBuffer_ArrayLen = (UINT32)[readBuffer count];
    uint8_t* __readBuffer_Array = (uint8_t*)[readBuffer ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->TransferFullDuplex(__writeBuffer_ArrayLen, __writeBuffer_Array, __readBuffer_ArrayLen, __readBuffer_Array));
    if (__writeBuffer_IsTemp)
        CoTaskMemFree(__writeBuffer_Array);
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDSSpiController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Spi::ISpiController> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Spi::ISpiControllerStatics> WDSISpiControllerStatics_inst() {
    ComPtr<ABI::Windows::Devices::Spi::ISpiControllerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Spi.SpiController").Get(), &inst));
    return inst;
}

+ (void)getDefaultAsyncWithSuccess:(void (^)(WDSSpiController*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Spi::SpiController*>> unmarshalledReturn;
    auto _comInst = WDSISpiControllerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Spi::SpiController*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Spi::SpiController*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Spi::ISpiController> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSpiController>(result.Get()));
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

+ (void)getControllersAsync:(RTObject<WDSPISpiProvider>*)provider
                    success:(void (^)(NSArray* /* WDSSpiController* */))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Spi::SpiController*>*>> unmarshalledReturn;
    auto _comInst = WDSISpiControllerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetControllersAsync(_getRtInterface<ABI::Windows::Devices::Spi::Provider::ISpiProvider>(provider).Get(),
                                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Devices::Spi::SpiController*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Spi::SpiController*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Spi::SpiController*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WDSSpiController_create(result.Get()));
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

- (WDSSpiDevice*)getDevice:(WDSSpiConnectionSettings*)settings {
    ComPtr<ABI::Windows::Devices::Spi::ISpiDevice> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::ISpiController>(self);
    THROW_NS_IF_FAILED(_comInst->GetDevice(_getRtInterface<ABI::Windows::Devices::Spi::ISpiConnectionSettings>(settings).Get(),
                                           unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSpiDevice>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_Int32_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<int>, RTArrayObj<int, IVectorView<int>, int, int, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDSSpiController_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Spi::SpiController*>,
                                         RTArrayObj<ABI::Windows::Devices::Spi::ISpiController*,
                                                    IVectorView<ABI::Windows::Devices::Spi::SpiController*>,
                                                    WDSSpiController,
                                                    ABI::Windows::Devices::Spi::SpiController*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
