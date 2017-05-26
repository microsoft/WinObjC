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

// WindowsDevicesSpiProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Spi.Provider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesSpiProvider.h"
#include "WindowsDevicesSpiProvider_priv.h"

@implementation WDSPISpiControllerProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Spi::Provider::ISpiControllerProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WDSPISpiDeviceProvider>*)getDeviceProvider:(WDSPProviderSpiConnectionSettings*)settings {
    ComPtr<ABI::Windows::Devices::Spi::Provider::ISpiDeviceProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::ISpiControllerProvider>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetDeviceProvider(_getRtInterface<ABI::Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings>(settings).Get(),
                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSPISpiDeviceProvider>(unmarshalledReturn.Get());
}

@end

@implementation WDSPISpiProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Spi::Provider::ISpiProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getControllersAsyncWithSuccess:(void (^)(NSArray* /* RTObject<WDSPISpiControllerProvider>* */))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Spi::Provider::ISpiControllerProvider*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::ISpiProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetControllersAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Devices::Spi::Provider::ISpiControllerProvider*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Spi::Provider::ISpiControllerProvider*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Spi::Provider::ISpiControllerProvider*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_RTObject_WDSPISpiControllerProvider_create(result.Get()));
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

@implementation WDSPISpiDeviceProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Spi::Provider::ISpiDeviceProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::ISpiDeviceProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSPProviderSpiConnectionSettings*)connectionSettings {
    ComPtr<ABI::Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::ISpiDeviceProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionSettings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSPProviderSpiConnectionSettings>(unmarshalledReturn.Get());
}

- (void)write:(NSArray* /* uint8_t */)buffer {
    UINT32 __buffer_ArrayLen = 0;
    bool __buffer_IsTemp = false;
    uint8_t* __buffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(buffer, &__buffer_ArrayLen, &__buffer_Array, &__buffer_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::ISpiDeviceProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Write(__buffer_ArrayLen, __buffer_Array));
    if (__buffer_IsTemp)
        CoTaskMemFree(__buffer_Array);
}

- (void)read:(NSArray* /* uint8_t */*)buffer {
    UINT32 __buffer_ArrayLen = (UINT32)[buffer count];
    uint8_t* __buffer_Array = (uint8_t*)[buffer ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::ISpiDeviceProvider>(self);
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

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::ISpiDeviceProvider>(self);
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

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::ISpiDeviceProvider>(self);
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

@implementation WDSPProviderSpiConnectionSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Spi::Provider::IProviderSpiConnectionSettingsFactory>
WDSPIProviderSpiConnectionSettingsFactory_inst() {
    ComPtr<ABI::Windows::Devices::Spi::Provider::IProviderSpiConnectionSettingsFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Spi.Provider.ProviderSpiConnectionSettings").Get(), &inst));
    return inst;
}

+ (WDSPProviderSpiConnectionSettings*)make:(int)chipSelectLine {
    ComPtr<ABI::Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings> unmarshalledReturn;
    auto _comInst = WDSPIProviderSpiConnectionSettingsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(chipSelectLine, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDSPProviderSpiConnectionSettings>(unmarshalledReturn.Get()) retain];
}

- (int)chipSelectLine {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChipSelectLine(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setChipSelectLine:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_ChipSelectLine(value));
}

- (WDSPProviderSpiMode)mode {
    ABI::Windows::Devices::Spi::Provider::ProviderSpiMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WDSPProviderSpiMode)unmarshalledReturn;
}

- (void)setMode:(WDSPProviderSpiMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mode((ABI::Windows::Devices::Spi::Provider::ProviderSpiMode)value));
}

- (int)dataBitLength {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataBitLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDataBitLength:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_DataBitLength(value));
}

- (int)clockFrequency {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClockFrequency(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setClockFrequency:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_ClockFrequency(value));
}

- (WDSPProviderSpiSharingMode)sharingMode {
    ABI::Windows::Devices::Spi::Provider::ProviderSpiSharingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_SharingMode(&unmarshalledReturn));
    return (WDSPProviderSpiSharingMode)unmarshalledReturn;
}

- (void)setSharingMode:(WDSPProviderSpiSharingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_SharingMode((ABI::Windows::Devices::Spi::Provider::ProviderSpiSharingMode)value));
}

@end

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_RTObject_WDSPISpiControllerProvider_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Spi::Provider::ISpiControllerProvider*>,
                                         RTArrayObj<ABI::Windows::Devices::Spi::Provider::ISpiControllerProvider*,
                                                    IVectorView<ABI::Windows::Devices::Spi::Provider::ISpiControllerProvider*>,
                                                    RTObject<WDSPISpiControllerProvider>,
                                                    ABI::Windows::Devices::Spi::Provider::ISpiControllerProvider*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
