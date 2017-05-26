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

// WindowsGamingInputCustom.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Gaming.Input.Custom.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGamingInputCustom.h"
#include "WindowsGamingInputCustom_priv.h"

@implementation WGICIGameControllerInputSink

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::Custom::IGameControllerInputSink> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)onInputResumed:(uint64_t)timestamp {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerInputSink>(self);
    THROW_NS_IF_FAILED(_comInst->OnInputResumed(timestamp));
}

- (void)onInputSuspended:(uint64_t)timestamp {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerInputSink>(self);
    THROW_NS_IF_FAILED(_comInst->OnInputSuspended(timestamp));
}

@end

@implementation WGICIGipGameControllerInputSink

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::Custom::IGipGameControllerInputSink> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)onKeyReceived:(uint64_t)timestamp keyCode:(uint8_t)keyCode isPressed:(BOOL)isPressed {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGipGameControllerInputSink>(self);
    THROW_NS_IF_FAILED(_comInst->OnKeyReceived(timestamp, keyCode, (boolean)isPressed));
}

- (void)onMessageReceived:(uint64_t)timestamp
             messageClass:(WGICGipMessageClass)messageClass
                messageId:(uint8_t)messageId
               sequenceId:(uint8_t)sequenceId
            messageBuffer:(NSArray* /* uint8_t */)messageBuffer {
    UINT32 __messageBuffer_ArrayLen = 0;
    bool __messageBuffer_IsTemp = false;
    uint8_t* __messageBuffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(messageBuffer, &__messageBuffer_ArrayLen, &__messageBuffer_Array, &__messageBuffer_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGipGameControllerInputSink>(self);
    THROW_NS_IF_FAILED(_comInst->OnMessageReceived(timestamp,
                                                   (ABI::Windows::Gaming::Input::Custom::GipMessageClass)messageClass,
                                                   messageId,
                                                   sequenceId,
                                                   __messageBuffer_ArrayLen,
                                                   __messageBuffer_Array));
    if (__messageBuffer_IsTemp)
        CoTaskMemFree(__messageBuffer_Array);
}

- (void)onInputResumed:(uint64_t)timestamp {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerInputSink>(self);
    THROW_NS_IF_FAILED(_comInst->OnInputResumed(timestamp));
}

- (void)onInputSuspended:(uint64_t)timestamp {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerInputSink>(self);
    THROW_NS_IF_FAILED(_comInst->OnInputSuspended(timestamp));
}

@end

@implementation WGICIXusbGameControllerInputSink

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::Custom::IXusbGameControllerInputSink> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)onInputReceived:(uint64_t)timestamp reportId:(uint8_t)reportId inputBuffer:(NSArray* /* uint8_t */)inputBuffer {
    UINT32 __inputBuffer_ArrayLen = 0;
    bool __inputBuffer_IsTemp = false;
    uint8_t* __inputBuffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(inputBuffer, &__inputBuffer_ArrayLen, &__inputBuffer_Array, &__inputBuffer_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IXusbGameControllerInputSink>(self);
    THROW_NS_IF_FAILED(_comInst->OnInputReceived(timestamp, reportId, __inputBuffer_ArrayLen, __inputBuffer_Array));
    if (__inputBuffer_IsTemp)
        CoTaskMemFree(__inputBuffer_Array);
}

- (void)onInputResumed:(uint64_t)timestamp {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerInputSink>(self);
    THROW_NS_IF_FAILED(_comInst->OnInputResumed(timestamp));
}

- (void)onInputSuspended:(uint64_t)timestamp {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerInputSink>(self);
    THROW_NS_IF_FAILED(_comInst->OnInputSuspended(timestamp));
}

@end

@implementation WGICIGameControllerProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGICGameControllerVersionInfo*)firmwareVersionInfo {
    ABI::Windows::Gaming::Input::Custom::GameControllerVersionInfo unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirmwareVersionInfo(&unmarshalledReturn));
    return WGICGameControllerVersionInfo_create(unmarshalledReturn);
}

- (unsigned short)hardwareProductId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HardwareProductId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)hardwareVendorId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HardwareVendorId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WGICGameControllerVersionInfo*)hardwareVersionInfo {
    ABI::Windows::Gaming::Input::Custom::GameControllerVersionInfo unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HardwareVersionInfo(&unmarshalledReturn));
    return WGICGameControllerVersionInfo_create(unmarshalledReturn);
}

- (BOOL)isConnected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsConnected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WGICICustomGameControllerFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::Custom::ICustomGameControllerFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)createGameController:(RTObject<WGICIGameControllerProvider>*)provider {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::ICustomGameControllerFactory>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateGameController(_getRtInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider>(provider).Get(),
                                       unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)onGameControllerAdded:(RTObject<WGIIGameController>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::ICustomGameControllerFactory>(self);
    THROW_NS_IF_FAILED(_comInst->OnGameControllerAdded(_getRtInterface<ABI::Windows::Gaming::Input::IGameController>(value).Get()));
}

- (void)onGameControllerRemoved:(RTObject<WGIIGameController>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::ICustomGameControllerFactory>(self);
    THROW_NS_IF_FAILED(_comInst->OnGameControllerRemoved(_getRtInterface<ABI::Windows::Gaming::Input::IGameController>(value).Get()));
}

@end

@implementation WGICGipFirmwareUpdateResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::Custom::IGipFirmwareUpdateResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)extendedErrorCode {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGipFirmwareUpdateResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedErrorCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)finalComponentId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGipFirmwareUpdateResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_FinalComponentId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WGICGipFirmwareUpdateStatus)status {
    ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGipFirmwareUpdateResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WGICGipFirmwareUpdateStatus)unmarshalledReturn;
}

@end

@implementation WGICGipGameControllerProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::Custom::IGipGameControllerProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)sendMessage:(WGICGipMessageClass)messageClass messageId:(uint8_t)messageId messageBuffer:(NSArray* /* uint8_t */)messageBuffer {
    UINT32 __messageBuffer_ArrayLen = 0;
    bool __messageBuffer_IsTemp = false;
    uint8_t* __messageBuffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(messageBuffer, &__messageBuffer_ArrayLen, &__messageBuffer_Array, &__messageBuffer_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGipGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SendMessage((ABI::Windows::Gaming::Input::Custom::GipMessageClass)messageClass,
                                             messageId,
                                             __messageBuffer_ArrayLen,
                                             __messageBuffer_Array));
    if (__messageBuffer_IsTemp)
        CoTaskMemFree(__messageBuffer_Array);
}

- (void)sendReceiveMessage:(WGICGipMessageClass)messageClass
                 messageId:(uint8_t)messageId
      requestMessageBuffer:(NSArray* /* uint8_t */)requestMessageBuffer
     responseMessageBuffer:(NSArray* /* uint8_t */*)responseMessageBuffer {
    UINT32 __requestMessageBuffer_ArrayLen = 0;
    bool __requestMessageBuffer_IsTemp = false;
    uint8_t* __requestMessageBuffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(requestMessageBuffer,
                                  &__requestMessageBuffer_ArrayLen,
                                  &__requestMessageBuffer_Array,
                                  &__requestMessageBuffer_IsTemp))
        assert(0);
    UINT32 __responseMessageBuffer_ArrayLen = (UINT32)[responseMessageBuffer count];
    uint8_t* __responseMessageBuffer_Array = (uint8_t*)[responseMessageBuffer ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGipGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SendReceiveMessage((ABI::Windows::Gaming::Input::Custom::GipMessageClass)messageClass,
                                                    messageId,
                                                    __requestMessageBuffer_ArrayLen,
                                                    __requestMessageBuffer_Array,
                                                    __responseMessageBuffer_ArrayLen,
                                                    __responseMessageBuffer_Array));
    if (__requestMessageBuffer_IsTemp)
        CoTaskMemFree(__requestMessageBuffer_Array);
}

- (void)updateFirmwareAsync:(RTObject<WSSIInputStream>*)firmwareImage
                    success:(void (^)(WGICGipFirmwareUpdateResult*))success
                   progress:(void (^)(WGICGipFirmwareUpdateProgress*))progress
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateResult*,
                                                                 ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGipGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateFirmwareAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(firmwareImage).Get(),
                                                     &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateResult*,
                                                                     ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateResult*,
                                                                  ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress>* op,
            ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress status) {
            @autoreleasepool {
                progressRc(WGICGipFirmwareUpdateProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<
                                                                    ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateResult*,
                                                                    ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress>>>(
            [successRc, failureRc](
                ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateResult*,
                                                                      ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress>* op,
                AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        ComPtr<ABI::Windows::Gaming::Input::Custom::IGipFirmwareUpdateResult> result;
                        HRESULT hr = op->GetResults(result.GetAddressOf());
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(_createRtProxy<WGICGipFirmwareUpdateResult>(result.Get()));
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

- (WGICGameControllerVersionInfo*)firmwareVersionInfo {
    ABI::Windows::Gaming::Input::Custom::GameControllerVersionInfo unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirmwareVersionInfo(&unmarshalledReturn));
    return WGICGameControllerVersionInfo_create(unmarshalledReturn);
}

- (unsigned short)hardwareProductId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HardwareProductId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)hardwareVendorId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HardwareVendorId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WGICGameControllerVersionInfo*)hardwareVersionInfo {
    ABI::Windows::Gaming::Input::Custom::GameControllerVersionInfo unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HardwareVersionInfo(&unmarshalledReturn));
    return WGICGameControllerVersionInfo_create(unmarshalledReturn);
}

- (BOOL)isConnected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsConnected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WGICXusbGameControllerProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::Custom::IXusbGameControllerProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setVibration:(double)lowFrequencyMotorSpeed highFrequencyMotorSpeed:(double)highFrequencyMotorSpeed {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IXusbGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetVibration(lowFrequencyMotorSpeed, highFrequencyMotorSpeed));
}

- (WGICGameControllerVersionInfo*)firmwareVersionInfo {
    ABI::Windows::Gaming::Input::Custom::GameControllerVersionInfo unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirmwareVersionInfo(&unmarshalledReturn));
    return WGICGameControllerVersionInfo_create(unmarshalledReturn);
}

- (unsigned short)hardwareProductId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HardwareProductId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)hardwareVendorId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HardwareVendorId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WGICGameControllerVersionInfo*)hardwareVersionInfo {
    ABI::Windows::Gaming::Input::Custom::GameControllerVersionInfo unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HardwareVersionInfo(&unmarshalledReturn));
    return WGICGameControllerVersionInfo_create(unmarshalledReturn);
}

- (BOOL)isConnected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::Custom::IGameControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsConnected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WGICGameControllerFactoryManager

ComPtr<ABI::Windows::Gaming::Input::Custom::IGameControllerFactoryManagerStatics> WGICIGameControllerFactoryManagerStatics_inst() {
    ComPtr<ABI::Windows::Gaming::Input::Custom::IGameControllerFactoryManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Gaming.Input.Custom.GameControllerFactoryManager").Get(), &inst));
    return inst;
}

+ (void)registerCustomFactoryForGipInterface:(RTObject<WGICICustomGameControllerFactory>*)factory interfaceId:(WFGUID*)interfaceId {
    auto _comInst = WGICIGameControllerFactoryManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RegisterCustomFactoryForGipInterface(
        _getRtInterface<ABI::Windows::Gaming::Input::Custom::ICustomGameControllerFactory>(factory).Get(), interfaceId.guidValue));
}

+ (void)registerCustomFactoryForHardwareId:(RTObject<WGICICustomGameControllerFactory>*)factory
                          hardwareVendorId:(unsigned short)hardwareVendorId
                         hardwareProductId:(unsigned short)hardwareProductId {
    auto _comInst = WGICIGameControllerFactoryManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RegisterCustomFactoryForHardwareId(
        _getRtInterface<ABI::Windows::Gaming::Input::Custom::ICustomGameControllerFactory>(factory).Get(),
        hardwareVendorId,
        hardwareProductId));
}

+ (void)registerCustomFactoryForXusbType:(RTObject<WGICICustomGameControllerFactory>*)factory
                                xusbType:(WGICXusbDeviceType)xusbType
                             xusbSubtype:(WGICXusbDeviceSubtype)xusbSubtype {
    auto _comInst = WGICIGameControllerFactoryManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RegisterCustomFactoryForXusbType(
        _getRtInterface<ABI::Windows::Gaming::Input::Custom::ICustomGameControllerFactory>(factory).Get(),
        (ABI::Windows::Gaming::Input::Custom::XusbDeviceType)xusbType,
        (ABI::Windows::Gaming::Input::Custom::XusbDeviceSubtype)xusbSubtype));
}

@end

@implementation WGICGameControllerVersionInfo {
    ABI::Windows::Gaming::Input::Custom::GameControllerVersionInfo structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Gaming::Input::Custom::GameControllerVersionInfo)s {
    WGICGameControllerVersionInfo* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Gaming::Input::Custom::GameControllerVersionInfo*)internalStruct {
    return &structVal;
}
- (unsigned short)major {
    return structVal.Major;
}
- (void)setMajor:(unsigned short)val {
    structVal.Major = val;
}
- (unsigned short)minor {
    return structVal.Minor;
}
- (void)setMinor:(unsigned short)val {
    structVal.Minor = val;
}
- (unsigned short)build {
    return structVal.Build;
}
- (void)setBuild:(unsigned short)val {
    structVal.Build = val;
}
- (unsigned short)revision {
    return structVal.Revision;
}
- (void)setRevision:(unsigned short)val {
    structVal.Revision = val;
}
@end
@implementation WGICGipFirmwareUpdateProgress {
    ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress)s {
    WGICGipFirmwareUpdateProgress* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress*)internalStruct {
    return &structVal;
}
- (double)percentCompleted {
    return structVal.PercentCompleted;
}
- (void)setPercentCompleted:(double)val {
    structVal.PercentCompleted = val;
}
- (unsigned int)currentComponentId {
    return structVal.CurrentComponentId;
}
- (void)setCurrentComponentId:(unsigned int)val {
    structVal.CurrentComponentId = val;
}
@end
id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
