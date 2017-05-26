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

// WindowsMediaProtectionPlayReady.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Protection.PlayReady.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaProtectionPlayReady.h"
#include "WindowsMediaProtectionPlayReady_priv.h"

@implementation WMPPIPlayReadyLicense

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)fullyEvaluated {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_FullyEvaluated(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)usableForPlay {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsableForPlay(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (id /* WFDateTime* */)expirationDate {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationDate(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (unsigned int)expireAfterFirstPlay {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpireAfterFirstPlay(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFGUID*)domainAccountID {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainAccountID(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (unsigned int)chainDepth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChainDepth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFGUID*)getKIDAtChainDepth:(unsigned int)chainDepth {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense>(self);
    THROW_NS_IF_FAILED(_comInst->GetKIDAtChainDepth(chainDepth, &unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WMPPIPlayReadyDomain

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomain> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)accountId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomain>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccountId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFGUID*)serviceId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomain>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (unsigned int)revision {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomain>(self);
    THROW_NS_IF_FAILED(_comInst->get_Revision(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)friendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomain>(self);
    THROW_NS_IF_FAILED(_comInst->get_FriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFUri*)domainJoinUrl {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomain>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainJoinUrl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

@end

@implementation WMPPIPlayReadyLicenseSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WMPPIPlayReadyLicenseAcquisitionServiceRequest>*)createLAServiceRequest {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseSession>(self);
    THROW_NS_IF_FAILED(_comInst->CreateLAServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPIPlayReadyLicenseAcquisitionServiceRequest>(unmarshalledReturn.Get());
}

- (void)configureMediaProtectionManager:(WMPMediaProtectionManager*)mpm {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->ConfigureMediaProtectionManager(_getRtInterface<ABI::Windows::Media::Protection::IMediaProtectionManager>(mpm).Get()));
}

@end

@implementation WMPPINDDownloadEngine

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngine> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)open:(WFUri*)uri sessionIDBytes:(NSArray* /* uint8_t */)sessionIDBytes {
    UINT32 __sessionIDBytes_ArrayLen = 0;
    bool __sessionIDBytes_IsTemp = false;
    uint8_t* __sessionIDBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(sessionIDBytes, &__sessionIDBytes_ArrayLen, &__sessionIDBytes_Array, &__sessionIDBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngine>(self);
    THROW_NS_IF_FAILED(_comInst->Open(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                      __sessionIDBytes_ArrayLen,
                                      __sessionIDBytes_Array));
    if (__sessionIDBytes_IsTemp)
        CoTaskMemFree(__sessionIDBytes_Array);
}

- (void)pause {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngine>(self);
    THROW_NS_IF_FAILED(_comInst->Pause());
}

- (void)resume {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngine>(self);
    THROW_NS_IF_FAILED(_comInst->Resume());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngine>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (void)seek:(WFTimeSpan*)startPosition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngine>(self);
    THROW_NS_IF_FAILED(_comInst->Seek(*[startPosition internalStruct]));
}

- (BOOL)canSeek {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngine>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanSeek(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (unsigned int)bufferFullMinThresholdInSamples {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngine>(self);
    THROW_NS_IF_FAILED(_comInst->get_BufferFullMinThresholdInSamples(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)bufferFullMaxThresholdInSamples {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngine>(self);
    THROW_NS_IF_FAILED(_comInst->get_BufferFullMaxThresholdInSamples(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMPPNDDownloadEngineNotifier*)notifier {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngineNotifier> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngine>(self);
    THROW_NS_IF_FAILED(_comInst->get_Notifier(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPNDDownloadEngineNotifier>(unmarshalledReturn.Get());
}

@end

@implementation WMPPINDDownloadEngineNotifier

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngineNotifier> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)onStreamOpened {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngineNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnStreamOpened());
}

- (void)onPlayReadyObjectReceived:(NSArray* /* uint8_t */)dataBytes {
    UINT32 __dataBytes_ArrayLen = 0;
    bool __dataBytes_IsTemp = false;
    uint8_t* __dataBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(dataBytes, &__dataBytes_ArrayLen, &__dataBytes_Array, &__dataBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngineNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnPlayReadyObjectReceived(__dataBytes_ArrayLen, __dataBytes_Array));
    if (__dataBytes_IsTemp)
        CoTaskMemFree(__dataBytes_Array);
}

- (void)onContentIDReceived:(RTObject<WMPPINDLicenseFetchDescriptor>*)licenseFetchDescriptor {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngineNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnContentIDReceived(
        _getRtInterface<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor>(licenseFetchDescriptor).Get()));
}

- (void)onDataReceived:(NSArray* /* uint8_t */)dataBytes bytesReceived:(unsigned int)bytesReceived {
    UINT32 __dataBytes_ArrayLen = 0;
    bool __dataBytes_IsTemp = false;
    uint8_t* __dataBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(dataBytes, &__dataBytes_ArrayLen, &__dataBytes_Array, &__dataBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngineNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnDataReceived(__dataBytes_ArrayLen, __dataBytes_Array, bytesReceived));
    if (__dataBytes_IsTemp)
        CoTaskMemFree(__dataBytes_Array);
}

- (void)onEndOfStream {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngineNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnEndOfStream());
}

- (void)onNetworkError {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngineNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnNetworkError());
}

@end

@implementation WMPPINDLicenseFetchDescriptor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPPNDContentIDType)contentIDType {
    ABI::Windows::Media::Protection::PlayReady::NDContentIDType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentIDType(&unmarshalledReturn));
    return (WMPPNDContentIDType)unmarshalledReturn;
}

- (NSArray* /* uint8_t */)contentID {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentID(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (RTObject<WMPPINDCustomData>*)licenseFetchChallengeCustomData {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDCustomData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_LicenseFetchChallengeCustomData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPINDCustomData>(unmarshalledReturn.Get());
}

- (void)setLicenseFetchChallengeCustomData:(RTObject<WMPPINDCustomData>*)licenseFetchChallengeCustomData {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->put_LicenseFetchChallengeCustomData(
        _getRtInterface<ABI::Windows::Media::Protection::PlayReady::INDCustomData>(licenseFetchChallengeCustomData).Get()));
}

@end

@implementation WMPPINDCustomData

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDCustomData> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* uint8_t */)customDataTypeID {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDCustomData>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomDataTypeID(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (NSArray* /* uint8_t */)customData {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDCustomData>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomData(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WMPPINDStreamParser

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDStreamParser> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)parseData:(NSArray* /* uint8_t */)dataBytes {
    UINT32 __dataBytes_ArrayLen = 0;
    bool __dataBytes_IsTemp = false;
    uint8_t* __dataBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(dataBytes, &__dataBytes_ArrayLen, &__dataBytes_Array, &__dataBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDStreamParser>(self);
    THROW_NS_IF_FAILED(_comInst->ParseData(__dataBytes_ArrayLen, __dataBytes_Array));
    if (__dataBytes_IsTemp)
        CoTaskMemFree(__dataBytes_Array);
}

- (unsigned int)getStreamInformation:(RTObject<WMCIMediaStreamDescriptor>*)descriptor streamType:(WMPPNDMediaStreamType*)streamType {
    ABI::Windows::Media::Protection::PlayReady::NDMediaStreamType streamTypeOutUnmarshaled;
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDStreamParser>(self);
    THROW_NS_IF_FAILED(_comInst->GetStreamInformation(_getRtInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(descriptor).Get(),
                                                      &streamTypeOutUnmarshaled,
                                                      &unmarshalledReturn));
    *streamType = (WMPPNDMediaStreamType)streamTypeOutUnmarshaled;
    return unmarshalledReturn;
}

- (void)beginOfStream {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDStreamParser>(self);
    THROW_NS_IF_FAILED(_comInst->BeginOfStream());
}

- (void)endOfStream {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDStreamParser>(self);
    THROW_NS_IF_FAILED(_comInst->EndOfStream());
}

- (WMPPNDStreamParserNotifier*)notifier {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDStreamParserNotifier> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDStreamParser>(self);
    THROW_NS_IF_FAILED(_comInst->get_Notifier(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPNDStreamParserNotifier>(unmarshalledReturn.Get());
}

@end

@implementation WMPPINDStreamParserNotifier

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDStreamParserNotifier> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)onContentIDReceived:(RTObject<WMPPINDLicenseFetchDescriptor>*)licenseFetchDescriptor {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDStreamParserNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnContentIDReceived(
        _getRtInterface<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor>(licenseFetchDescriptor).Get()));
}

- (void)onMediaStreamDescriptorCreated:(NSMutableArray* /* WMCAudioStreamDescriptor* */)audioStreamDescriptors
                videoStreamDescriptors:(NSMutableArray* /* WMCVideoStreamDescriptor* */)videoStreamDescriptors {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDStreamParserNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnMediaStreamDescriptorCreated(
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Media::Core::AudioStreamDescriptor*,
                                                              ABI::Windows::Media::Core::IAudioStreamDescriptor*>>::type>*>(
            ConvertToVector<WMCAudioStreamDescriptor,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Media::Core::AudioStreamDescriptor*,
                                                                              ABI::Windows::Media::Core::IAudioStreamDescriptor*>>(
                audioStreamDescriptors)
                .Get()),
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Media::Core::VideoStreamDescriptor*,
                                                              ABI::Windows::Media::Core::IVideoStreamDescriptor*>>::type>*>(
            ConvertToVector<WMCVideoStreamDescriptor,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Media::Core::VideoStreamDescriptor*,
                                                                              ABI::Windows::Media::Core::IVideoStreamDescriptor*>>(
                videoStreamDescriptors)
                .Get())));
}

- (void)onSampleParsed:(unsigned int)streamID
            streamType:(WMPPNDMediaStreamType)streamType
          streamSample:(WMCMediaStreamSample*)streamSample
                   pts:(int64_t)pts
              ccFormat:(WMPPNDClosedCaptionFormat)ccFormat
           ccDataBytes:(NSArray* /* uint8_t */)ccDataBytes {
    UINT32 __ccDataBytes_ArrayLen = 0;
    bool __ccDataBytes_IsTemp = false;
    uint8_t* __ccDataBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(ccDataBytes, &__ccDataBytes_ArrayLen, &__ccDataBytes_Array, &__ccDataBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDStreamParserNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnSampleParsed(streamID,
                                                (ABI::Windows::Media::Protection::PlayReady::NDMediaStreamType)streamType,
                                                _getRtInterface<ABI::Windows::Media::Core::IMediaStreamSample>(streamSample).Get(),
                                                pts,
                                                (ABI::Windows::Media::Protection::PlayReady::NDClosedCaptionFormat)ccFormat,
                                                __ccDataBytes_ArrayLen,
                                                __ccDataBytes_Array));
    if (__ccDataBytes_IsTemp)
        CoTaskMemFree(__ccDataBytes_Array);
}

- (void)onBeginSetupDecryptor:(RTObject<WMCIMediaStreamDescriptor>*)descriptor
                        keyID:(WFGUID*)keyID
                     proBytes:(NSArray* /* uint8_t */)proBytes {
    UINT32 __proBytes_ArrayLen = 0;
    bool __proBytes_IsTemp = false;
    uint8_t* __proBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(proBytes, &__proBytes_ArrayLen, &__proBytes_Array, &__proBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDStreamParserNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnBeginSetupDecryptor(_getRtInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(descriptor).Get(),
                                                       keyID.guidValue,
                                                       __proBytes_ArrayLen,
                                                       __proBytes_Array));
    if (__proBytes_IsTemp)
        CoTaskMemFree(__proBytes_Array);
}

@end

@implementation WMPPINDSendResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDSendResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* uint8_t */)response {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDSendResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Response(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WMPPINDMessenger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDMessenger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)sendRegistrationRequestAsync:(NSArray* /* uint8_t */)sessionIDBytes
                  challengeDataBytes:(NSArray* /* uint8_t */)challengeDataBytes
                             success:(void (^)(RTObject<WMPPINDSendResult>*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>> unmarshalledReturn;
    UINT32 __sessionIDBytes_ArrayLen = 0;
    bool __sessionIDBytes_IsTemp = false;
    uint8_t* __sessionIDBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(sessionIDBytes, &__sessionIDBytes_ArrayLen, &__sessionIDBytes_Array, &__sessionIDBytes_IsTemp))
        assert(0);
    UINT32 __challengeDataBytes_ArrayLen = 0;
    bool __challengeDataBytes_IsTemp = false;
    uint8_t* __challengeDataBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(challengeDataBytes,
                                  &__challengeDataBytes_ArrayLen,
                                  &__challengeDataBytes_Array,
                                  &__challengeDataBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDMessenger>(self);
    THROW_NS_IF_FAILED(_comInst->SendRegistrationRequestAsync(__sessionIDBytes_ArrayLen,
                                                              __sessionIDBytes_Array,
                                                              __challengeDataBytes_ArrayLen,
                                                              __challengeDataBytes_Array,
                                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDSendResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMPPINDSendResult>(result.Get()));
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
    if (__sessionIDBytes_IsTemp)
        CoTaskMemFree(__sessionIDBytes_Array);
    if (__challengeDataBytes_IsTemp)
        CoTaskMemFree(__challengeDataBytes_Array);
}

- (void)sendProximityDetectionStartAsync:(WMPPNDProximityDetectionType)pdType
                 transmitterChannelBytes:(NSArray* /* uint8_t */)transmitterChannelBytes
                          sessionIDBytes:(NSArray* /* uint8_t */)sessionIDBytes
                      challengeDataBytes:(NSArray* /* uint8_t */)challengeDataBytes
                                 success:(void (^)(RTObject<WMPPINDSendResult>*))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>> unmarshalledReturn;
    UINT32 __transmitterChannelBytes_ArrayLen = 0;
    bool __transmitterChannelBytes_IsTemp = false;
    uint8_t* __transmitterChannelBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(transmitterChannelBytes,
                                  &__transmitterChannelBytes_ArrayLen,
                                  &__transmitterChannelBytes_Array,
                                  &__transmitterChannelBytes_IsTemp))
        assert(0);
    UINT32 __sessionIDBytes_ArrayLen = 0;
    bool __sessionIDBytes_IsTemp = false;
    uint8_t* __sessionIDBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(sessionIDBytes, &__sessionIDBytes_ArrayLen, &__sessionIDBytes_Array, &__sessionIDBytes_IsTemp))
        assert(0);
    UINT32 __challengeDataBytes_ArrayLen = 0;
    bool __challengeDataBytes_IsTemp = false;
    uint8_t* __challengeDataBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(challengeDataBytes,
                                  &__challengeDataBytes_ArrayLen,
                                  &__challengeDataBytes_Array,
                                  &__challengeDataBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDMessenger>(self);
    THROW_NS_IF_FAILED(
        _comInst->SendProximityDetectionStartAsync((ABI::Windows::Media::Protection::PlayReady::NDProximityDetectionType)pdType,
                                                   __transmitterChannelBytes_ArrayLen,
                                                   __transmitterChannelBytes_Array,
                                                   __sessionIDBytes_ArrayLen,
                                                   __sessionIDBytes_Array,
                                                   __challengeDataBytes_ArrayLen,
                                                   __challengeDataBytes_Array,
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDSendResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMPPINDSendResult>(result.Get()));
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
    if (__transmitterChannelBytes_IsTemp)
        CoTaskMemFree(__transmitterChannelBytes_Array);
    if (__sessionIDBytes_IsTemp)
        CoTaskMemFree(__sessionIDBytes_Array);
    if (__challengeDataBytes_IsTemp)
        CoTaskMemFree(__challengeDataBytes_Array);
}

- (void)sendProximityDetectionResponseAsync:(WMPPNDProximityDetectionType)pdType
                    transmitterChannelBytes:(NSArray* /* uint8_t */)transmitterChannelBytes
                             sessionIDBytes:(NSArray* /* uint8_t */)sessionIDBytes
                          responseDataBytes:(NSArray* /* uint8_t */)responseDataBytes
                                    success:(void (^)(RTObject<WMPPINDSendResult>*))success
                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>> unmarshalledReturn;
    UINT32 __transmitterChannelBytes_ArrayLen = 0;
    bool __transmitterChannelBytes_IsTemp = false;
    uint8_t* __transmitterChannelBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(transmitterChannelBytes,
                                  &__transmitterChannelBytes_ArrayLen,
                                  &__transmitterChannelBytes_Array,
                                  &__transmitterChannelBytes_IsTemp))
        assert(0);
    UINT32 __sessionIDBytes_ArrayLen = 0;
    bool __sessionIDBytes_IsTemp = false;
    uint8_t* __sessionIDBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(sessionIDBytes, &__sessionIDBytes_ArrayLen, &__sessionIDBytes_Array, &__sessionIDBytes_IsTemp))
        assert(0);
    UINT32 __responseDataBytes_ArrayLen = 0;
    bool __responseDataBytes_IsTemp = false;
    uint8_t* __responseDataBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(responseDataBytes,
                                  &__responseDataBytes_ArrayLen,
                                  &__responseDataBytes_Array,
                                  &__responseDataBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDMessenger>(self);
    THROW_NS_IF_FAILED(
        _comInst->SendProximityDetectionResponseAsync((ABI::Windows::Media::Protection::PlayReady::NDProximityDetectionType)pdType,
                                                      __transmitterChannelBytes_ArrayLen,
                                                      __transmitterChannelBytes_Array,
                                                      __sessionIDBytes_ArrayLen,
                                                      __sessionIDBytes_Array,
                                                      __responseDataBytes_ArrayLen,
                                                      __responseDataBytes_Array,
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDSendResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMPPINDSendResult>(result.Get()));
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
    if (__transmitterChannelBytes_IsTemp)
        CoTaskMemFree(__transmitterChannelBytes_Array);
    if (__sessionIDBytes_IsTemp)
        CoTaskMemFree(__sessionIDBytes_Array);
    if (__responseDataBytes_IsTemp)
        CoTaskMemFree(__responseDataBytes_Array);
}

- (void)sendLicenseFetchRequestAsync:(NSArray* /* uint8_t */)sessionIDBytes
                  challengeDataBytes:(NSArray* /* uint8_t */)challengeDataBytes
                             success:(void (^)(RTObject<WMPPINDSendResult>*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>> unmarshalledReturn;
    UINT32 __sessionIDBytes_ArrayLen = 0;
    bool __sessionIDBytes_IsTemp = false;
    uint8_t* __sessionIDBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(sessionIDBytes, &__sessionIDBytes_ArrayLen, &__sessionIDBytes_Array, &__sessionIDBytes_IsTemp))
        assert(0);
    UINT32 __challengeDataBytes_ArrayLen = 0;
    bool __challengeDataBytes_IsTemp = false;
    uint8_t* __challengeDataBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(challengeDataBytes,
                                  &__challengeDataBytes_ArrayLen,
                                  &__challengeDataBytes_Array,
                                  &__challengeDataBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDMessenger>(self);
    THROW_NS_IF_FAILED(_comInst->SendLicenseFetchRequestAsync(__sessionIDBytes_ArrayLen,
                                                              __sessionIDBytes_Array,
                                                              __challengeDataBytes_ArrayLen,
                                                              __challengeDataBytes_Array,
                                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDSendResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMPPINDSendResult>(result.Get()));
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
    if (__sessionIDBytes_IsTemp)
        CoTaskMemFree(__sessionIDBytes_Array);
    if (__challengeDataBytes_IsTemp)
        CoTaskMemFree(__challengeDataBytes_Array);
}

@end

@implementation WMPPINDTransmitterProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDTransmitterProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPPNDCertificateType)certificateType {
    ABI::Windows::Media::Protection::PlayReady::NDCertificateType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDTransmitterProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_CertificateType(&unmarshalledReturn));
    return (WMPPNDCertificateType)unmarshalledReturn;
}

- (WMPPNDCertificatePlatformID)platformIdentifier {
    ABI::Windows::Media::Protection::PlayReady::NDCertificatePlatformID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDTransmitterProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlatformIdentifier(&unmarshalledReturn));
    return (WMPPNDCertificatePlatformID)unmarshalledReturn;
}

- (NSArray* /* WMPPNDCertificateFeature */)supportedFeatures {
    ABI::Windows::Media::Protection::PlayReady::NDCertificateFeature* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDTransmitterProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedFeatures(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WMPPNDCertificateFeature_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (unsigned int)securityLevel {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDTransmitterProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_SecurityLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)securityVersion {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDTransmitterProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_SecurityVersion(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFDateTime*)expirationDate {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDTransmitterProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationDate(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSArray* /* uint8_t */)clientID {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDTransmitterProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClientID(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (NSArray* /* uint8_t */)modelDigest {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDTransmitterProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_ModelDigest(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (NSString*)modelManufacturerName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDTransmitterProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_ModelManufacturerName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)modelName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDTransmitterProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_ModelName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)modelNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDTransmitterProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_ModelNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMPPINDStartResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDStartResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCMediaStreamSource*)mediaStreamSource {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDStartResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaStreamSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaStreamSource>(unmarshalledReturn.Get());
}

@end

@implementation WMPPINDLicenseFetchResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WMPPINDCustomData>*)responseCustomData {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDCustomData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseCustomData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPINDCustomData>(unmarshalledReturn.Get());
}

@end

@implementation WMPPINDRegistrationCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDRegistrationCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WMPPINDCustomData>*)responseCustomData {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDCustomData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDRegistrationCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseCustomData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPINDCustomData>(unmarshalledReturn.Get());
}

- (RTObject<WMPPINDTransmitterProperties>*)transmitterProperties {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDTransmitterProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDRegistrationCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransmitterProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPINDTransmitterProperties>(unmarshalledReturn.Get());
}

- (BOOL)transmitterCertificateAccepted {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDRegistrationCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransmitterCertificateAccepted(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setTransmitterCertificateAccepted:(BOOL)accept {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDRegistrationCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_TransmitterCertificateAccepted((boolean)accept));
}

@end

@implementation WMPPINDProximityDetectionCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDProximityDetectionCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)proximityDetectionRetryCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDProximityDetectionCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProximityDetectionRetryCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMPPINDLicenseFetchCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WMPPINDCustomData>*)responseCustomData {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDCustomData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseCustomData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPINDCustomData>(unmarshalledReturn.Get());
}

@end

@implementation WMPPINDClosedCaptionDataReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDClosedCaptionDataReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPPNDClosedCaptionFormat)closedCaptionDataFormat {
    ABI::Windows::Media::Protection::PlayReady::NDClosedCaptionFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClosedCaptionDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClosedCaptionDataFormat(&unmarshalledReturn));
    return (WMPPNDClosedCaptionFormat)unmarshalledReturn;
}

- (int64_t)presentationTimestamp {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClosedCaptionDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PresentationTimestamp(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSArray* /* uint8_t */)closedCaptionData {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClosedCaptionDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClosedCaptionData(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WMPPINDStorageFileHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDStorageFileHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSMutableArray* /* NSString * */)getFileURLs:(RTObject<WSIStorageFile>*)file {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDStorageFileHelper>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetFileURLs(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WMPPIPlayReadyServiceRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)responseCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)challengeCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChallengeCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setChallengeCustomData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_ChallengeCustomData(nsStrToHstr(value).Get()));
}

- (RTObject<WFIAsyncAction>*)beginServiceRequest {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->BeginServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->NextServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPIPlayReadyServiceRequest>(unmarshalledReturn.Get());
}

- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySoapMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GenerateManualEnablingChallenge(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPPlayReadySoapMessage>(unmarshalledReturn.Get());
}

- (HRESULT)processManualEnablingResponse:(NSArray* /* uint8_t */)responseBytes {
    HRESULT unmarshalledReturn;
    UINT32 __responseBytes_ArrayLen = 0;
    bool __responseBytes_IsTemp = false;
    uint8_t* __responseBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(responseBytes, &__responseBytes_ArrayLen, &__responseBytes_Array, &__responseBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessManualEnablingResponse(__responseBytes_ArrayLen, __responseBytes_Array, &unmarshalledReturn));
    if (__responseBytes_IsTemp)
        CoTaskMemFree(__responseBytes_Array);
    return (HRESULT)unmarshalledReturn;
}

- (WFGUID*)protectionSystem {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionSystem(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFGUID*)type {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WMPPIPlayReadyLicenseAcquisitionServiceRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPPPlayReadyContentHeader*)contentHeader {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentHeader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPPlayReadyContentHeader>(unmarshalledReturn.Get());
}

- (void)setContentHeader:(WMPPPlayReadyContentHeader*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ContentHeader(_getRtInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader>(value).Get()));
}

- (WFGUID*)domainServiceId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainServiceId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (void)setDomainServiceId:(WFGUID*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_DomainServiceId(value.guidValue));
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)responseCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)challengeCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChallengeCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setChallengeCustomData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_ChallengeCustomData(nsStrToHstr(value).Get()));
}

- (RTObject<WFIAsyncAction>*)beginServiceRequest {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->BeginServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->NextServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPIPlayReadyServiceRequest>(unmarshalledReturn.Get());
}

- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySoapMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GenerateManualEnablingChallenge(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPPlayReadySoapMessage>(unmarshalledReturn.Get());
}

- (HRESULT)processManualEnablingResponse:(NSArray* /* uint8_t */)responseBytes {
    HRESULT unmarshalledReturn;
    UINT32 __responseBytes_ArrayLen = 0;
    bool __responseBytes_IsTemp = false;
    uint8_t* __responseBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(responseBytes, &__responseBytes_ArrayLen, &__responseBytes_Array, &__responseBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessManualEnablingResponse(__responseBytes_ArrayLen, __responseBytes_Array, &unmarshalledReturn));
    if (__responseBytes_IsTemp)
        CoTaskMemFree(__responseBytes_Array);
    return (HRESULT)unmarshalledReturn;
}

- (WFGUID*)protectionSystem {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionSystem(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFGUID*)type {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WMPPIPlayReadySecureStopServiceRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)sessionID {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_SessionID(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFDateTime*)startTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFDateTime*)updateTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_UpdateTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (BOOL)stopped {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Stopped(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* uint8_t */)publisherCertificate {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_PublisherCertificate(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)responseCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)challengeCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChallengeCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setChallengeCustomData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_ChallengeCustomData(nsStrToHstr(value).Get()));
}

- (RTObject<WFIAsyncAction>*)beginServiceRequest {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->BeginServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->NextServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPIPlayReadyServiceRequest>(unmarshalledReturn.Get());
}

- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySoapMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GenerateManualEnablingChallenge(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPPlayReadySoapMessage>(unmarshalledReturn.Get());
}

- (HRESULT)processManualEnablingResponse:(NSArray* /* uint8_t */)responseBytes {
    HRESULT unmarshalledReturn;
    UINT32 __responseBytes_ArrayLen = 0;
    bool __responseBytes_IsTemp = false;
    uint8_t* __responseBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(responseBytes, &__responseBytes_ArrayLen, &__responseBytes_Array, &__responseBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessManualEnablingResponse(__responseBytes_ArrayLen, __responseBytes_Array, &unmarshalledReturn));
    if (__responseBytes_IsTemp)
        CoTaskMemFree(__responseBytes_Array);
    return (HRESULT)unmarshalledReturn;
}

- (WFGUID*)protectionSystem {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionSystem(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFGUID*)type {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WMPPPlayReadyContentHeader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeaderFactory> WMPPIPlayReadyContentHeaderFactory_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeaderFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyContentHeader").Get(), &inst));
    return inst;
}

+ (WMPPPlayReadyContentHeader*)makeInstanceFromWindowsMediaDrmHeader:(NSArray* /* uint8_t */)headerBytes
                                               licenseAcquisitionUrl:(WFUri*)licenseAcquisitionUrl
                                  licenseAcquisitionUserInterfaceUrl:(WFUri*)licenseAcquisitionUserInterfaceUrl
                                                    customAttributes:(NSString*)customAttributes
                                                     domainServiceId:(WFGUID*)domainServiceId {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader> unmarshalledReturn;
    UINT32 __headerBytes_ArrayLen = 0;
    bool __headerBytes_IsTemp = false;
    uint8_t* __headerBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(headerBytes, &__headerBytes_ArrayLen, &__headerBytes_Array, &__headerBytes_IsTemp))
        assert(0);

    auto _comInst = WMPPIPlayReadyContentHeaderFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceFromWindowsMediaDrmHeader(
        __headerBytes_ArrayLen,
        __headerBytes_Array,
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(licenseAcquisitionUrl).Get(),
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(licenseAcquisitionUserInterfaceUrl).Get(),
        nsStrToHstr(customAttributes).Get(),
        domainServiceId.guidValue,
        unmarshalledReturn.GetAddressOf()));
    if (__headerBytes_IsTemp)
        CoTaskMemFree(__headerBytes_Array);
    return [_createRtProxy<WMPPPlayReadyContentHeader>(unmarshalledReturn.Get()) retain];
}

+ (WMPPPlayReadyContentHeader*)makeInstanceFromComponents:(WFGUID*)contentKeyId
                                       contentKeyIdString:(NSString*)contentKeyIdString
                               contentEncryptionAlgorithm:(WMPPPlayReadyEncryptionAlgorithm)contentEncryptionAlgorithm
                                    licenseAcquisitionUrl:(WFUri*)licenseAcquisitionUrl
                       licenseAcquisitionUserInterfaceUrl:(WFUri*)licenseAcquisitionUserInterfaceUrl
                                         customAttributes:(NSString*)customAttributes
                                          domainServiceId:(WFGUID*)domainServiceId {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader> unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyContentHeaderFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceFromComponents(
        contentKeyId.guidValue,
        nsStrToHstr(contentKeyIdString).Get(),
        (ABI::Windows::Media::Protection::PlayReady::PlayReadyEncryptionAlgorithm)contentEncryptionAlgorithm,
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(licenseAcquisitionUrl).Get(),
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(licenseAcquisitionUserInterfaceUrl).Get(),
        nsStrToHstr(customAttributes).Get(),
        domainServiceId.guidValue,
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMPPPlayReadyContentHeader>(unmarshalledReturn.Get()) retain];
}

+ (WMPPPlayReadyContentHeader*)makeInstanceFromPlayReadyHeader:(NSArray* /* uint8_t */)headerBytes {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader> unmarshalledReturn;
    UINT32 __headerBytes_ArrayLen = 0;
    bool __headerBytes_IsTemp = false;
    uint8_t* __headerBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(headerBytes, &__headerBytes_ArrayLen, &__headerBytes_Array, &__headerBytes_IsTemp))
        assert(0);

    auto _comInst = WMPPIPlayReadyContentHeaderFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateInstanceFromPlayReadyHeader(__headerBytes_ArrayLen, __headerBytes_Array, unmarshalledReturn.GetAddressOf()));
    if (__headerBytes_IsTemp)
        CoTaskMemFree(__headerBytes_Array);
    return [_createRtProxy<WMPPPlayReadyContentHeader>(unmarshalledReturn.Get()) retain];
}

static ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeaderFactory2> WMPPIPlayReadyContentHeaderFactory2_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeaderFactory2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyContentHeader").Get(), &inst));
    return inst;
}

+ (WMPPPlayReadyContentHeader*)makeInstanceFromComponents2:(unsigned int)dwFlags
                                             contentKeyIds:(NSArray* /* WFGUID* */)contentKeyIds
                                       contentKeyIdStrings:(NSArray* /* NSString * */)contentKeyIdStrings
                                contentEncryptionAlgorithm:(WMPPPlayReadyEncryptionAlgorithm)contentEncryptionAlgorithm
                                     licenseAcquisitionUrl:(WFUri*)licenseAcquisitionUrl
                        licenseAcquisitionUserInterfaceUrl:(WFUri*)licenseAcquisitionUserInterfaceUrl
                                          customAttributes:(NSString*)customAttributes
                                           domainServiceId:(WFGUID*)domainServiceId {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader> unmarshalledReturn;
    UINT32 __contentKeyIds_ArrayLen = 0;
    bool __contentKeyIds_IsTemp = false;
    GUID* __contentKeyIds_Array = NULL;
    if (!ConvertToCArray<GUID>(contentKeyIds, &__contentKeyIds_ArrayLen, &__contentKeyIds_Array, &__contentKeyIds_IsTemp))
        assert(0);
    UINT32 __contentKeyIdStrings_ArrayLen = 0;
    bool __contentKeyIdStrings_IsTemp = false;
    HSTRING* __contentKeyIdStrings_Array = NULL;
    if (!ConvertToCArray<HSTRING>(contentKeyIdStrings,
                                  &__contentKeyIdStrings_ArrayLen,
                                  &__contentKeyIdStrings_Array,
                                  &__contentKeyIdStrings_IsTemp))
        assert(0);

    auto _comInst = WMPPIPlayReadyContentHeaderFactory2_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceFromComponents2(
        dwFlags,
        __contentKeyIds_ArrayLen,
        __contentKeyIds_Array,
        __contentKeyIdStrings_ArrayLen,
        __contentKeyIdStrings_Array,
        (ABI::Windows::Media::Protection::PlayReady::PlayReadyEncryptionAlgorithm)contentEncryptionAlgorithm,
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(licenseAcquisitionUrl).Get(),
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(licenseAcquisitionUserInterfaceUrl).Get(),
        nsStrToHstr(customAttributes).Get(),
        domainServiceId.guidValue,
        unmarshalledReturn.GetAddressOf()));
    if (__contentKeyIds_IsTemp)
        CoTaskMemFree(__contentKeyIds_Array);
    if (__contentKeyIdStrings_IsTemp)
        CoTaskMemFree(__contentKeyIdStrings_Array);
    return [_createRtProxy<WMPPPlayReadyContentHeader>(unmarshalledReturn.Get()) retain];
}

- (WFGUID*)keyId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (NSString*)keyIdString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyIdString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFUri*)licenseAcquisitionUrl {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader>(self);
    THROW_NS_IF_FAILED(_comInst->get_LicenseAcquisitionUrl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (WFUri*)licenseAcquisitionUserInterfaceUrl {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader>(self);
    THROW_NS_IF_FAILED(_comInst->get_LicenseAcquisitionUserInterfaceUrl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (WFGUID*)domainServiceId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainServiceId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WMPPPlayReadyEncryptionAlgorithm)encryptionType {
    ABI::Windows::Media::Protection::PlayReady::PlayReadyEncryptionAlgorithm unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncryptionType(&unmarshalledReturn));
    return (WMPPPlayReadyEncryptionAlgorithm)unmarshalledReturn;
}

- (NSString*)customAttributes {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomAttributes(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMPPPlayReadyDecryptorSetup)decryptorSetup {
    ABI::Windows::Media::Protection::PlayReady::PlayReadyDecryptorSetup unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader>(self);
    THROW_NS_IF_FAILED(_comInst->get_DecryptorSetup(&unmarshalledReturn));
    return (WMPPPlayReadyDecryptorSetup)unmarshalledReturn;
}

- (NSArray* /* uint8_t */)getSerializedHeader {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader>(self);
    THROW_NS_IF_FAILED(_comInst->GetSerializedHeader(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (WMPPPlayReadyContentHeader*)headerWithEmbeddedUpdates {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader>(self);
    THROW_NS_IF_FAILED(_comInst->get_HeaderWithEmbeddedUpdates(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPPlayReadyContentHeader>(unmarshalledReturn.Get());
}

- (NSArray* /* WFGUID* */)keyIds {
    GUID* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader2>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyIds(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WFGUID_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (NSArray* /* NSString * */)keyIdStrings {
    HSTRING* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader2>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyIdStrings(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_NSString_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WMPPPlayReadySoapMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySoapMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* uint8_t */)getMessageBody {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadySoapMessage>(self);
    THROW_NS_IF_FAILED(_comInst->GetMessageBody(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (RTObject<WFCIPropertySet>*)messageHeaders {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadySoapMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageHeaders(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadySoapMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

@end

@implementation WMPPPlayReadyContentResolver

ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentResolver> WMPPIPlayReadyContentResolver_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentResolver> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyContentResolver").Get(), &inst));
    return inst;
}

+ (RTObject<WMPPIPlayReadyServiceRequest>*)serviceRequest:(WMPPPlayReadyContentHeader*)contentHeader {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest> unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyContentResolver_inst();
    THROW_NS_IF_FAILED(
        _comInst->ServiceRequest(_getRtInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader>(contentHeader).Get(),
                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPIPlayReadyServiceRequest>(unmarshalledReturn.Get());
}

@end

@implementation WMPPPlayReadyIndividualizationServiceRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyIndividualizationServiceRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyIndividualizationServiceRequest").Get(), &out));
    return [_createRtProxy<WMPPPlayReadyIndividualizationServiceRequest>(out.Get()) retain];
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)responseCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)challengeCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChallengeCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setChallengeCustomData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_ChallengeCustomData(nsStrToHstr(value).Get()));
}

- (RTObject<WFIAsyncAction>*)beginServiceRequest {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->BeginServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->NextServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPIPlayReadyServiceRequest>(unmarshalledReturn.Get());
}

- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySoapMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GenerateManualEnablingChallenge(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPPlayReadySoapMessage>(unmarshalledReturn.Get());
}

- (HRESULT)processManualEnablingResponse:(NSArray* /* uint8_t */)responseBytes {
    HRESULT unmarshalledReturn;
    UINT32 __responseBytes_ArrayLen = 0;
    bool __responseBytes_IsTemp = false;
    uint8_t* __responseBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(responseBytes, &__responseBytes_ArrayLen, &__responseBytes_Array, &__responseBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessManualEnablingResponse(__responseBytes_ArrayLen, __responseBytes_Array, &unmarshalledReturn));
    if (__responseBytes_IsTemp)
        CoTaskMemFree(__responseBytes_Array);
    return (HRESULT)unmarshalledReturn;
}

- (WFGUID*)protectionSystem {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionSystem(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFGUID*)type {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WMPPPlayReadyDomainJoinServiceRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomainJoinServiceRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyDomainJoinServiceRequest").Get(), &out));
    return [_createRtProxy<WMPPPlayReadyDomainJoinServiceRequest>(out.Get()) retain];
}

- (WFGUID*)domainAccountId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomainJoinServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainAccountId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (void)setDomainAccountId:(WFGUID*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomainJoinServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_DomainAccountId(value.guidValue));
}

- (NSString*)domainFriendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomainJoinServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainFriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDomainFriendlyName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomainJoinServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_DomainFriendlyName(nsStrToHstr(value).Get()));
}

- (WFGUID*)domainServiceId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomainJoinServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainServiceId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (void)setDomainServiceId:(WFGUID*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomainJoinServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_DomainServiceId(value.guidValue));
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)responseCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)challengeCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChallengeCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setChallengeCustomData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_ChallengeCustomData(nsStrToHstr(value).Get()));
}

- (RTObject<WFIAsyncAction>*)beginServiceRequest {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->BeginServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->NextServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPIPlayReadyServiceRequest>(unmarshalledReturn.Get());
}

- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySoapMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GenerateManualEnablingChallenge(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPPlayReadySoapMessage>(unmarshalledReturn.Get());
}

- (HRESULT)processManualEnablingResponse:(NSArray* /* uint8_t */)responseBytes {
    HRESULT unmarshalledReturn;
    UINT32 __responseBytes_ArrayLen = 0;
    bool __responseBytes_IsTemp = false;
    uint8_t* __responseBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(responseBytes, &__responseBytes_ArrayLen, &__responseBytes_Array, &__responseBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessManualEnablingResponse(__responseBytes_ArrayLen, __responseBytes_Array, &unmarshalledReturn));
    if (__responseBytes_IsTemp)
        CoTaskMemFree(__responseBytes_Array);
    return (HRESULT)unmarshalledReturn;
}

- (WFGUID*)protectionSystem {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionSystem(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFGUID*)type {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WMPPPlayReadyDomainLeaveServiceRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomainLeaveServiceRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyDomainLeaveServiceRequest").Get(), &out));
    return [_createRtProxy<WMPPPlayReadyDomainLeaveServiceRequest>(out.Get()) retain];
}

- (WFGUID*)domainAccountId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomainLeaveServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainAccountId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (void)setDomainAccountId:(WFGUID*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomainLeaveServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_DomainAccountId(value.guidValue));
}

- (WFGUID*)domainServiceId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomainLeaveServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainServiceId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (void)setDomainServiceId:(WFGUID*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomainLeaveServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_DomainServiceId(value.guidValue));
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)responseCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)challengeCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChallengeCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setChallengeCustomData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_ChallengeCustomData(nsStrToHstr(value).Get()));
}

- (RTObject<WFIAsyncAction>*)beginServiceRequest {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->BeginServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->NextServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPIPlayReadyServiceRequest>(unmarshalledReturn.Get());
}

- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySoapMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GenerateManualEnablingChallenge(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPPlayReadySoapMessage>(unmarshalledReturn.Get());
}

- (HRESULT)processManualEnablingResponse:(NSArray* /* uint8_t */)responseBytes {
    HRESULT unmarshalledReturn;
    UINT32 __responseBytes_ArrayLen = 0;
    bool __responseBytes_IsTemp = false;
    uint8_t* __responseBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(responseBytes, &__responseBytes_ArrayLen, &__responseBytes_Array, &__responseBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessManualEnablingResponse(__responseBytes_ArrayLen, __responseBytes_Array, &unmarshalledReturn));
    if (__responseBytes_IsTemp)
        CoTaskMemFree(__responseBytes_Array);
    return (HRESULT)unmarshalledReturn;
}

- (WFGUID*)protectionSystem {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionSystem(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFGUID*)type {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WMPPPlayReadyLicenseAcquisitionServiceRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyLicenseAcquisitionServiceRequest").Get(), &out));
    return [_createRtProxy<WMPPPlayReadyLicenseAcquisitionServiceRequest>(out.Get()) retain];
}

- (WMPPPlayReadyContentHeader*)contentHeader {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentHeader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPPlayReadyContentHeader>(unmarshalledReturn.Get());
}

- (void)setContentHeader:(WMPPPlayReadyContentHeader*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ContentHeader(_getRtInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader>(value).Get()));
}

- (WFGUID*)domainServiceId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainServiceId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (void)setDomainServiceId:(WFGUID*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_DomainServiceId(value.guidValue));
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)responseCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)challengeCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChallengeCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setChallengeCustomData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_ChallengeCustomData(nsStrToHstr(value).Get()));
}

- (RTObject<WFIAsyncAction>*)beginServiceRequest {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->BeginServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->NextServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPIPlayReadyServiceRequest>(unmarshalledReturn.Get());
}

- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySoapMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GenerateManualEnablingChallenge(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPPlayReadySoapMessage>(unmarshalledReturn.Get());
}

- (HRESULT)processManualEnablingResponse:(NSArray* /* uint8_t */)responseBytes {
    HRESULT unmarshalledReturn;
    UINT32 __responseBytes_ArrayLen = 0;
    bool __responseBytes_IsTemp = false;
    uint8_t* __responseBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(responseBytes, &__responseBytes_ArrayLen, &__responseBytes_Array, &__responseBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessManualEnablingResponse(__responseBytes_ArrayLen, __responseBytes_Array, &unmarshalledReturn));
    if (__responseBytes_IsTemp)
        CoTaskMemFree(__responseBytes_Array);
    return (HRESULT)unmarshalledReturn;
}

- (WFGUID*)protectionSystem {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionSystem(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFGUID*)type {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFGUID*)sessionId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SessionId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WMPPPlayReadyMeteringReportServiceRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyMeteringReportServiceRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyMeteringReportServiceRequest").Get(), &out));
    return [_createRtProxy<WMPPPlayReadyMeteringReportServiceRequest>(out.Get()) retain];
}

- (NSArray* /* uint8_t */)meteringCertificate {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyMeteringReportServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_MeteringCertificate(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (void)setMeteringCertificate:(NSArray* /* uint8_t */)meteringCertBytes {
    UINT32 __meteringCertBytes_ArrayLen = 0;
    bool __meteringCertBytes_IsTemp = false;
    uint8_t* __meteringCertBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(meteringCertBytes,
                                  &__meteringCertBytes_ArrayLen,
                                  &__meteringCertBytes_Array,
                                  &__meteringCertBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyMeteringReportServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_MeteringCertificate(__meteringCertBytes_ArrayLen, __meteringCertBytes_Array));
    if (__meteringCertBytes_IsTemp)
        CoTaskMemFree(__meteringCertBytes_Array);
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)responseCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)challengeCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChallengeCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setChallengeCustomData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_ChallengeCustomData(nsStrToHstr(value).Get()));
}

- (RTObject<WFIAsyncAction>*)beginServiceRequest {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->BeginServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->NextServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPIPlayReadyServiceRequest>(unmarshalledReturn.Get());
}

- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySoapMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GenerateManualEnablingChallenge(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPPlayReadySoapMessage>(unmarshalledReturn.Get());
}

- (HRESULT)processManualEnablingResponse:(NSArray* /* uint8_t */)responseBytes {
    HRESULT unmarshalledReturn;
    UINT32 __responseBytes_ArrayLen = 0;
    bool __responseBytes_IsTemp = false;
    uint8_t* __responseBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(responseBytes, &__responseBytes_ArrayLen, &__responseBytes_Array, &__responseBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessManualEnablingResponse(__responseBytes_ArrayLen, __responseBytes_Array, &unmarshalledReturn));
    if (__responseBytes_IsTemp)
        CoTaskMemFree(__responseBytes_Array);
    return (HRESULT)unmarshalledReturn;
}

- (WFGUID*)protectionSystem {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionSystem(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFGUID*)type {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WMPPPlayReadyRevocationServiceRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyRevocationServiceRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyRevocationServiceRequest").Get(), &out));
    return [_createRtProxy<WMPPPlayReadyRevocationServiceRequest>(out.Get()) retain];
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)responseCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)challengeCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChallengeCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setChallengeCustomData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_ChallengeCustomData(nsStrToHstr(value).Get()));
}

- (RTObject<WFIAsyncAction>*)beginServiceRequest {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->BeginServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->NextServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPIPlayReadyServiceRequest>(unmarshalledReturn.Get());
}

- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySoapMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GenerateManualEnablingChallenge(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPPlayReadySoapMessage>(unmarshalledReturn.Get());
}

- (HRESULT)processManualEnablingResponse:(NSArray* /* uint8_t */)responseBytes {
    HRESULT unmarshalledReturn;
    UINT32 __responseBytes_ArrayLen = 0;
    bool __responseBytes_IsTemp = false;
    uint8_t* __responseBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(responseBytes, &__responseBytes_ArrayLen, &__responseBytes_Array, &__responseBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessManualEnablingResponse(__responseBytes_ArrayLen, __responseBytes_Array, &unmarshalledReturn));
    if (__responseBytes_IsTemp)
        CoTaskMemFree(__responseBytes_Array);
    return (HRESULT)unmarshalledReturn;
}

- (WFGUID*)protectionSystem {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionSystem(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFGUID*)type {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WMPPPlayReadyLicenseManagement

ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseManagement> WMPPIPlayReadyLicenseManagement_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseManagement> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyLicenseManagement").Get(), &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)deleteLicenses:(WMPPPlayReadyContentHeader*)contentHeader {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyLicenseManagement_inst();
    THROW_NS_IF_FAILED(
        _comInst->DeleteLicenses(_getRtInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader>(contentHeader).Get(),
                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WMPPPlayReadyLicense

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)fullyEvaluated {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_FullyEvaluated(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)usableForPlay {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsableForPlay(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (id /* WFDateTime* */)expirationDate {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationDate(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (unsigned int)expireAfterFirstPlay {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpireAfterFirstPlay(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFGUID*)domainAccountID {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainAccountID(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (unsigned int)chainDepth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChainDepth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFGUID*)getKIDAtChainDepth:(unsigned int)chainDepth {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense>(self);
    THROW_NS_IF_FAILED(_comInst->GetKIDAtChainDepth(chainDepth, &unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WMPPPlayReadyLicenseIterable

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IIterable<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseIterableFactory> WMPPIPlayReadyLicenseIterableFactory_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseIterableFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyLicenseIterable").Get(), &inst));
    return inst;
}

+ (WMPPPlayReadyLicenseIterable*)makeInstance:(WMPPPlayReadyContentHeader*)contentHeader fullyEvaluated:(BOOL)fullyEvaluated {
    ComPtr<IIterable<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicense*>> unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyLicenseIterableFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateInstance(_getRtInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeader>(contentHeader).Get(),
                                 (boolean)fullyEvaluated,
                                 unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMPPPlayReadyLicenseIterable>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyLicenseIterable").Get(),
                                              &out));
    return [_createRtProxy<WMPPPlayReadyLicenseIterable>(out.Get()) retain];
}

@end

@implementation WMPPPlayReadyLicenseIterator

// Failed to get type for default interface: Can't marshal
// Windows.Foundation.Collections.IIterator`1<Windows.Media.Protection.PlayReady.IPlayReadyLicense>
// Could not find base class Windows.Foundation.Collections.IIterator`1<Windows.Media.Protection.PlayReady.IPlayReadyLicense> type
// information
@end

@implementation WMPPPlayReadyDomain

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomain> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)accountId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomain>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccountId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFGUID*)serviceId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomain>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (unsigned int)revision {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomain>(self);
    THROW_NS_IF_FAILED(_comInst->get_Revision(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)friendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomain>(self);
    THROW_NS_IF_FAILED(_comInst->get_FriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFUri*)domainJoinUrl {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomain>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainJoinUrl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

@end

@implementation WMPPPlayReadyDomainIterable

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IIterable<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomain*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomainIterableFactory> WMPPIPlayReadyDomainIterableFactory_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomainIterableFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyDomainIterable").Get(), &inst));
    return inst;
}

+ (WMPPPlayReadyDomainIterable*)makeInstance:(WFGUID*)domainAccountId {
    ComPtr<IIterable<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomain*>> unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyDomainIterableFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance(domainAccountId.guidValue, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMPPPlayReadyDomainIterable>(unmarshalledReturn.Get()) retain];
}

@end

@implementation WMPPPlayReadyDomainIterator

// Failed to get type for default interface: Can't marshal
// Windows.Foundation.Collections.IIterator`1<Windows.Media.Protection.PlayReady.IPlayReadyDomain>
// Could not find base class Windows.Foundation.Collections.IIterator`1<Windows.Media.Protection.PlayReady.IPlayReadyDomain> type
// information
@end

@implementation WMPPPlayReadyStatics

ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyStatics2> WMPPIPlayReadyStatics2_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyStatics").Get(),
                                                       &inst));
    return inst;
}

+ (unsigned int)playReadyCertificateSecurityLevel {
    unsigned int unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_PlayReadyCertificateSecurityLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyStatics> WMPPIPlayReadyStatics_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyStatics").Get(),
                                                       &inst));
    return inst;
}

+ (WFGUID*)domainJoinServiceRequestType {
    GUID unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DomainJoinServiceRequestType(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)domainLeaveServiceRequestType {
    GUID unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DomainLeaveServiceRequestType(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)individualizationServiceRequestType {
    GUID unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IndividualizationServiceRequestType(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)licenseAcquirerServiceRequestType {
    GUID unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LicenseAcquirerServiceRequestType(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)meteringReportServiceRequestType {
    GUID unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MeteringReportServiceRequestType(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)revocationServiceRequestType {
    GUID unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RevocationServiceRequestType(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)mediaProtectionSystemId {
    GUID unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MediaProtectionSystemId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (unsigned int)playReadySecurityVersion {
    unsigned int unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PlayReadySecurityVersion(&unmarshalledReturn));
    return unmarshalledReturn;
}

ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyStatics4> WMPPIPlayReadyStatics4_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyStatics4> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyStatics").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)inputTrustAuthorityToCreate {
    HSTRING unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_InputTrustAuthorityToCreate(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (WFGUID*)protectionSystemId {
    GUID unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_ProtectionSystemId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyStatics3> WMPPIPlayReadyStatics3_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyStatics").Get(),
                                                       &inst));
    return inst;
}

+ (WFGUID*)secureStopServiceRequestType {
    GUID unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_SecureStopServiceRequestType(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (BOOL)checkSupportedHardware:(WMPPPlayReadyHardwareDRMFeatures)hwdrmFeature {
    boolean unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyStatics3_inst();
    THROW_NS_IF_FAILED(
        _comInst->CheckSupportedHardware((ABI::Windows::Media::Protection::PlayReady::PlayReadyHardwareDRMFeatures)hwdrmFeature,
                                         &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMPPPlayReadySecureStopServiceRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequestFactory>
WMPPIPlayReadySecureStopServiceRequestFactory_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequestFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadySecureStopServiceRequest").Get(), &inst));
    return inst;
}

+ (WMPPPlayReadySecureStopServiceRequest*)makeInstance:(NSArray* /* uint8_t */)publisherCertBytes {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest> unmarshalledReturn;
    UINT32 __publisherCertBytes_ArrayLen = 0;
    bool __publisherCertBytes_IsTemp = false;
    uint8_t* __publisherCertBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(publisherCertBytes,
                                  &__publisherCertBytes_ArrayLen,
                                  &__publisherCertBytes_Array,
                                  &__publisherCertBytes_IsTemp))
        assert(0);

    auto _comInst = WMPPIPlayReadySecureStopServiceRequestFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateInstance(__publisherCertBytes_ArrayLen, __publisherCertBytes_Array, unmarshalledReturn.GetAddressOf()));
    if (__publisherCertBytes_IsTemp)
        CoTaskMemFree(__publisherCertBytes_Array);
    return [_createRtProxy<WMPPPlayReadySecureStopServiceRequest>(unmarshalledReturn.Get()) retain];
}

+ (WMPPPlayReadySecureStopServiceRequest*)makeInstanceFromSessionID:(WFGUID*)sessionID
                                                 publisherCertBytes:(NSArray* /* uint8_t */)publisherCertBytes {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest> unmarshalledReturn;
    UINT32 __publisherCertBytes_ArrayLen = 0;
    bool __publisherCertBytes_IsTemp = false;
    uint8_t* __publisherCertBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(publisherCertBytes,
                                  &__publisherCertBytes_ArrayLen,
                                  &__publisherCertBytes_Array,
                                  &__publisherCertBytes_IsTemp))
        assert(0);

    auto _comInst = WMPPIPlayReadySecureStopServiceRequestFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceFromSessionID(sessionID.guidValue,
                                                             __publisherCertBytes_ArrayLen,
                                                             __publisherCertBytes_Array,
                                                             unmarshalledReturn.GetAddressOf()));
    if (__publisherCertBytes_IsTemp)
        CoTaskMemFree(__publisherCertBytes_Array);
    return [_createRtProxy<WMPPPlayReadySecureStopServiceRequest>(unmarshalledReturn.Get()) retain];
}

- (WFGUID*)sessionID {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_SessionID(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFDateTime*)startTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFDateTime*)updateTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_UpdateTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (BOOL)stopped {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Stopped(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* uint8_t */)publisherCertificate {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_PublisherCertificate(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)responseCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)challengeCustomData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChallengeCustomData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setChallengeCustomData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_ChallengeCustomData(nsStrToHstr(value).Get()));
}

- (RTObject<WFIAsyncAction>*)beginServiceRequest {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->BeginServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WMPPIPlayReadyServiceRequest>*)nextServiceRequest {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->NextServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPIPlayReadyServiceRequest>(unmarshalledReturn.Get());
}

- (WMPPPlayReadySoapMessage*)generateManualEnablingChallenge {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySoapMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GenerateManualEnablingChallenge(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPPlayReadySoapMessage>(unmarshalledReturn.Get());
}

- (HRESULT)processManualEnablingResponse:(NSArray* /* uint8_t */)responseBytes {
    HRESULT unmarshalledReturn;
    UINT32 __responseBytes_ArrayLen = 0;
    bool __responseBytes_IsTemp = false;
    uint8_t* __responseBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(responseBytes, &__responseBytes_ArrayLen, &__responseBytes_Array, &__responseBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessManualEnablingResponse(__responseBytes_ArrayLen, __responseBytes_Array, &unmarshalledReturn));
    if (__responseBytes_IsTemp)
        CoTaskMemFree(__responseBytes_Array);
    return (HRESULT)unmarshalledReturn;
}

- (WFGUID*)protectionSystem {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionSystem(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFGUID*)type {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WMPPPlayReadySecureStopIterable

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IIterable<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopIterableFactory>
WMPPIPlayReadySecureStopIterableFactory_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopIterableFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadySecureStopIterable").Get(), &inst));
    return inst;
}

+ (WMPPPlayReadySecureStopIterable*)makeInstance:(NSArray* /* uint8_t */)publisherCertBytes {
    ComPtr<IIterable<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest*>> unmarshalledReturn;
    UINT32 __publisherCertBytes_ArrayLen = 0;
    bool __publisherCertBytes_IsTemp = false;
    uint8_t* __publisherCertBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(publisherCertBytes,
                                  &__publisherCertBytes_ArrayLen,
                                  &__publisherCertBytes_Array,
                                  &__publisherCertBytes_IsTemp))
        assert(0);

    auto _comInst = WMPPIPlayReadySecureStopIterableFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateInstance(__publisherCertBytes_ArrayLen, __publisherCertBytes_Array, unmarshalledReturn.GetAddressOf()));
    if (__publisherCertBytes_IsTemp)
        CoTaskMemFree(__publisherCertBytes_Array);
    return [_createRtProxy<WMPPPlayReadySecureStopIterable>(unmarshalledReturn.Get()) retain];
}

@end

@implementation WMPPPlayReadySecureStopIterator

// Failed to get type for default interface: Can't marshal
// Windows.Foundation.Collections.IIterator`1<Windows.Media.Protection.PlayReady.IPlayReadySecureStopServiceRequest>
// Could not find base class
// Windows.Foundation.Collections.IIterator`1<Windows.Media.Protection.PlayReady.IPlayReadySecureStopServiceRequest> type information
@end

@implementation WMPPPlayReadyITADataGenerator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyITADataGenerator> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyITADataGenerator").Get(),
                                              &out));
    return [_createRtProxy<WMPPPlayReadyITADataGenerator>(out.Get()) retain];
}

- (NSArray* /* uint8_t */)generateData:(WFGUID*)guidCPSystemId
                        countOfStreams:(unsigned int)countOfStreams
                         configuration:(RTObject<WFCIPropertySet>*)configuration
                                format:(WMPPPlayReadyITADataFormat)format {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyITADataGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->GenerateData(guidCPSystemId.guidValue,
                                              countOfStreams,
                                              _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get(),
                                              (ABI::Windows::Media::Protection::PlayReady::PlayReadyITADataFormat)format,
                                              &unmarshalledReturnLen,
                                              &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WMPPPlayReadyLicenseSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseSessionFactory> WMPPIPlayReadyLicenseSessionFactory_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseSessionFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.Protection.PlayReady.PlayReadyLicenseSession").Get(), &inst));
    return inst;
}

+ (WMPPPlayReadyLicenseSession*)makeInstance:(RTObject<WFCIPropertySet>*)configuration {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseSession> unmarshalledReturn;
    auto _comInst = WMPPIPlayReadyLicenseSessionFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance(_getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMPPPlayReadyLicenseSession>(unmarshalledReturn.Get()) retain];
}

- (RTObject<WMPPIPlayReadyLicenseAcquisitionServiceRequest>*)createLAServiceRequest {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseSession>(self);
    THROW_NS_IF_FAILED(_comInst->CreateLAServiceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPIPlayReadyLicenseAcquisitionServiceRequest>(unmarshalledReturn.Get());
}

- (void)configureMediaProtectionManager:(WMPMediaProtectionManager*)mpm {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->ConfigureMediaProtectionManager(_getRtInterface<ABI::Windows::Media::Protection::IMediaProtectionManager>(mpm).Get()));
}

@end

@implementation WMPPNDDownloadEngineNotifier

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngineNotifier> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Protection.PlayReady.NDDownloadEngineNotifier").Get(),
                                              &out));
    return [_createRtProxy<WMPPNDDownloadEngineNotifier>(out.Get()) retain];
}

- (void)onStreamOpened {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngineNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnStreamOpened());
}

- (void)onPlayReadyObjectReceived:(NSArray* /* uint8_t */)dataBytes {
    UINT32 __dataBytes_ArrayLen = 0;
    bool __dataBytes_IsTemp = false;
    uint8_t* __dataBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(dataBytes, &__dataBytes_ArrayLen, &__dataBytes_Array, &__dataBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngineNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnPlayReadyObjectReceived(__dataBytes_ArrayLen, __dataBytes_Array));
    if (__dataBytes_IsTemp)
        CoTaskMemFree(__dataBytes_Array);
}

- (void)onContentIDReceived:(RTObject<WMPPINDLicenseFetchDescriptor>*)licenseFetchDescriptor {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngineNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnContentIDReceived(
        _getRtInterface<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor>(licenseFetchDescriptor).Get()));
}

- (void)onDataReceived:(NSArray* /* uint8_t */)dataBytes bytesReceived:(unsigned int)bytesReceived {
    UINT32 __dataBytes_ArrayLen = 0;
    bool __dataBytes_IsTemp = false;
    uint8_t* __dataBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(dataBytes, &__dataBytes_ArrayLen, &__dataBytes_Array, &__dataBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngineNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnDataReceived(__dataBytes_ArrayLen, __dataBytes_Array, bytesReceived));
    if (__dataBytes_IsTemp)
        CoTaskMemFree(__dataBytes_Array);
}

- (void)onEndOfStream {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngineNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnEndOfStream());
}

- (void)onNetworkError {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngineNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnNetworkError());
}

@end

@implementation WMPPNDStreamParserNotifier

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDStreamParserNotifier> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Protection.PlayReady.NDStreamParserNotifier").Get(),
                                              &out));
    return [_createRtProxy<WMPPNDStreamParserNotifier>(out.Get()) retain];
}

- (void)onContentIDReceived:(RTObject<WMPPINDLicenseFetchDescriptor>*)licenseFetchDescriptor {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDStreamParserNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnContentIDReceived(
        _getRtInterface<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor>(licenseFetchDescriptor).Get()));
}

- (void)onMediaStreamDescriptorCreated:(NSMutableArray* /* WMCAudioStreamDescriptor* */)audioStreamDescriptors
                videoStreamDescriptors:(NSMutableArray* /* WMCVideoStreamDescriptor* */)videoStreamDescriptors {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDStreamParserNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnMediaStreamDescriptorCreated(
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Media::Core::AudioStreamDescriptor*,
                                                              ABI::Windows::Media::Core::IAudioStreamDescriptor*>>::type>*>(
            ConvertToVector<WMCAudioStreamDescriptor,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Media::Core::AudioStreamDescriptor*,
                                                                              ABI::Windows::Media::Core::IAudioStreamDescriptor*>>(
                audioStreamDescriptors)
                .Get()),
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Media::Core::VideoStreamDescriptor*,
                                                              ABI::Windows::Media::Core::IVideoStreamDescriptor*>>::type>*>(
            ConvertToVector<WMCVideoStreamDescriptor,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Media::Core::VideoStreamDescriptor*,
                                                                              ABI::Windows::Media::Core::IVideoStreamDescriptor*>>(
                videoStreamDescriptors)
                .Get())));
}

- (void)onSampleParsed:(unsigned int)streamID
            streamType:(WMPPNDMediaStreamType)streamType
          streamSample:(WMCMediaStreamSample*)streamSample
                   pts:(int64_t)pts
              ccFormat:(WMPPNDClosedCaptionFormat)ccFormat
           ccDataBytes:(NSArray* /* uint8_t */)ccDataBytes {
    UINT32 __ccDataBytes_ArrayLen = 0;
    bool __ccDataBytes_IsTemp = false;
    uint8_t* __ccDataBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(ccDataBytes, &__ccDataBytes_ArrayLen, &__ccDataBytes_Array, &__ccDataBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDStreamParserNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnSampleParsed(streamID,
                                                (ABI::Windows::Media::Protection::PlayReady::NDMediaStreamType)streamType,
                                                _getRtInterface<ABI::Windows::Media::Core::IMediaStreamSample>(streamSample).Get(),
                                                pts,
                                                (ABI::Windows::Media::Protection::PlayReady::NDClosedCaptionFormat)ccFormat,
                                                __ccDataBytes_ArrayLen,
                                                __ccDataBytes_Array));
    if (__ccDataBytes_IsTemp)
        CoTaskMemFree(__ccDataBytes_Array);
}

- (void)onBeginSetupDecryptor:(RTObject<WMCIMediaStreamDescriptor>*)descriptor
                        keyID:(WFGUID*)keyID
                     proBytes:(NSArray* /* uint8_t */)proBytes {
    UINT32 __proBytes_ArrayLen = 0;
    bool __proBytes_IsTemp = false;
    uint8_t* __proBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(proBytes, &__proBytes_ArrayLen, &__proBytes_Array, &__proBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDStreamParserNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->OnBeginSetupDecryptor(_getRtInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(descriptor).Get(),
                                                       keyID.guidValue,
                                                       __proBytes_ArrayLen,
                                                       __proBytes_Array));
    if (__proBytes_IsTemp)
        CoTaskMemFree(__proBytes_Array);
}

@end

@implementation WMPPNDTCPMessenger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDMessenger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Protection::PlayReady::INDTCPMessengerFactory> WMPPINDTCPMessengerFactory_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDTCPMessengerFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Protection.PlayReady.NDTCPMessenger").Get(),
                                                       &inst));
    return inst;
}

+ (WMPPNDTCPMessenger*)makeInstance:(NSString*)remoteHostName remoteHostPort:(unsigned int)remoteHostPort {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDMessenger> unmarshalledReturn;
    auto _comInst = WMPPINDTCPMessengerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance(nsStrToHstr(remoteHostName).Get(), remoteHostPort, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMPPNDTCPMessenger>(unmarshalledReturn.Get()) retain];
}

- (void)sendRegistrationRequestAsync:(NSArray* /* uint8_t */)sessionIDBytes
                  challengeDataBytes:(NSArray* /* uint8_t */)challengeDataBytes
                             success:(void (^)(RTObject<WMPPINDSendResult>*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>> unmarshalledReturn;
    UINT32 __sessionIDBytes_ArrayLen = 0;
    bool __sessionIDBytes_IsTemp = false;
    uint8_t* __sessionIDBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(sessionIDBytes, &__sessionIDBytes_ArrayLen, &__sessionIDBytes_Array, &__sessionIDBytes_IsTemp))
        assert(0);
    UINT32 __challengeDataBytes_ArrayLen = 0;
    bool __challengeDataBytes_IsTemp = false;
    uint8_t* __challengeDataBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(challengeDataBytes,
                                  &__challengeDataBytes_ArrayLen,
                                  &__challengeDataBytes_Array,
                                  &__challengeDataBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDMessenger>(self);
    THROW_NS_IF_FAILED(_comInst->SendRegistrationRequestAsync(__sessionIDBytes_ArrayLen,
                                                              __sessionIDBytes_Array,
                                                              __challengeDataBytes_ArrayLen,
                                                              __challengeDataBytes_Array,
                                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDSendResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMPPINDSendResult>(result.Get()));
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
    if (__sessionIDBytes_IsTemp)
        CoTaskMemFree(__sessionIDBytes_Array);
    if (__challengeDataBytes_IsTemp)
        CoTaskMemFree(__challengeDataBytes_Array);
}

- (void)sendProximityDetectionStartAsync:(WMPPNDProximityDetectionType)pdType
                 transmitterChannelBytes:(NSArray* /* uint8_t */)transmitterChannelBytes
                          sessionIDBytes:(NSArray* /* uint8_t */)sessionIDBytes
                      challengeDataBytes:(NSArray* /* uint8_t */)challengeDataBytes
                                 success:(void (^)(RTObject<WMPPINDSendResult>*))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>> unmarshalledReturn;
    UINT32 __transmitterChannelBytes_ArrayLen = 0;
    bool __transmitterChannelBytes_IsTemp = false;
    uint8_t* __transmitterChannelBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(transmitterChannelBytes,
                                  &__transmitterChannelBytes_ArrayLen,
                                  &__transmitterChannelBytes_Array,
                                  &__transmitterChannelBytes_IsTemp))
        assert(0);
    UINT32 __sessionIDBytes_ArrayLen = 0;
    bool __sessionIDBytes_IsTemp = false;
    uint8_t* __sessionIDBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(sessionIDBytes, &__sessionIDBytes_ArrayLen, &__sessionIDBytes_Array, &__sessionIDBytes_IsTemp))
        assert(0);
    UINT32 __challengeDataBytes_ArrayLen = 0;
    bool __challengeDataBytes_IsTemp = false;
    uint8_t* __challengeDataBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(challengeDataBytes,
                                  &__challengeDataBytes_ArrayLen,
                                  &__challengeDataBytes_Array,
                                  &__challengeDataBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDMessenger>(self);
    THROW_NS_IF_FAILED(
        _comInst->SendProximityDetectionStartAsync((ABI::Windows::Media::Protection::PlayReady::NDProximityDetectionType)pdType,
                                                   __transmitterChannelBytes_ArrayLen,
                                                   __transmitterChannelBytes_Array,
                                                   __sessionIDBytes_ArrayLen,
                                                   __sessionIDBytes_Array,
                                                   __challengeDataBytes_ArrayLen,
                                                   __challengeDataBytes_Array,
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDSendResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMPPINDSendResult>(result.Get()));
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
    if (__transmitterChannelBytes_IsTemp)
        CoTaskMemFree(__transmitterChannelBytes_Array);
    if (__sessionIDBytes_IsTemp)
        CoTaskMemFree(__sessionIDBytes_Array);
    if (__challengeDataBytes_IsTemp)
        CoTaskMemFree(__challengeDataBytes_Array);
}

- (void)sendProximityDetectionResponseAsync:(WMPPNDProximityDetectionType)pdType
                    transmitterChannelBytes:(NSArray* /* uint8_t */)transmitterChannelBytes
                             sessionIDBytes:(NSArray* /* uint8_t */)sessionIDBytes
                          responseDataBytes:(NSArray* /* uint8_t */)responseDataBytes
                                    success:(void (^)(RTObject<WMPPINDSendResult>*))success
                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>> unmarshalledReturn;
    UINT32 __transmitterChannelBytes_ArrayLen = 0;
    bool __transmitterChannelBytes_IsTemp = false;
    uint8_t* __transmitterChannelBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(transmitterChannelBytes,
                                  &__transmitterChannelBytes_ArrayLen,
                                  &__transmitterChannelBytes_Array,
                                  &__transmitterChannelBytes_IsTemp))
        assert(0);
    UINT32 __sessionIDBytes_ArrayLen = 0;
    bool __sessionIDBytes_IsTemp = false;
    uint8_t* __sessionIDBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(sessionIDBytes, &__sessionIDBytes_ArrayLen, &__sessionIDBytes_Array, &__sessionIDBytes_IsTemp))
        assert(0);
    UINT32 __responseDataBytes_ArrayLen = 0;
    bool __responseDataBytes_IsTemp = false;
    uint8_t* __responseDataBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(responseDataBytes,
                                  &__responseDataBytes_ArrayLen,
                                  &__responseDataBytes_Array,
                                  &__responseDataBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDMessenger>(self);
    THROW_NS_IF_FAILED(
        _comInst->SendProximityDetectionResponseAsync((ABI::Windows::Media::Protection::PlayReady::NDProximityDetectionType)pdType,
                                                      __transmitterChannelBytes_ArrayLen,
                                                      __transmitterChannelBytes_Array,
                                                      __sessionIDBytes_ArrayLen,
                                                      __sessionIDBytes_Array,
                                                      __responseDataBytes_ArrayLen,
                                                      __responseDataBytes_Array,
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDSendResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMPPINDSendResult>(result.Get()));
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
    if (__transmitterChannelBytes_IsTemp)
        CoTaskMemFree(__transmitterChannelBytes_Array);
    if (__sessionIDBytes_IsTemp)
        CoTaskMemFree(__sessionIDBytes_Array);
    if (__responseDataBytes_IsTemp)
        CoTaskMemFree(__responseDataBytes_Array);
}

- (void)sendLicenseFetchRequestAsync:(NSArray* /* uint8_t */)sessionIDBytes
                  challengeDataBytes:(NSArray* /* uint8_t */)challengeDataBytes
                             success:(void (^)(RTObject<WMPPINDSendResult>*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>> unmarshalledReturn;
    UINT32 __sessionIDBytes_ArrayLen = 0;
    bool __sessionIDBytes_IsTemp = false;
    uint8_t* __sessionIDBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(sessionIDBytes, &__sessionIDBytes_ArrayLen, &__sessionIDBytes_Array, &__sessionIDBytes_IsTemp))
        assert(0);
    UINT32 __challengeDataBytes_ArrayLen = 0;
    bool __challengeDataBytes_IsTemp = false;
    uint8_t* __challengeDataBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(challengeDataBytes,
                                  &__challengeDataBytes_ArrayLen,
                                  &__challengeDataBytes_Array,
                                  &__challengeDataBytes_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDMessenger>(self);
    THROW_NS_IF_FAILED(_comInst->SendLicenseFetchRequestAsync(__sessionIDBytes_ArrayLen,
                                                              __sessionIDBytes_Array,
                                                              __challengeDataBytes_ArrayLen,
                                                              __challengeDataBytes_Array,
                                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDSendResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDSendResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMPPINDSendResult>(result.Get()));
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
    if (__sessionIDBytes_IsTemp)
        CoTaskMemFree(__sessionIDBytes_Array);
    if (__challengeDataBytes_IsTemp)
        CoTaskMemFree(__challengeDataBytes_Array);
}

@end

@implementation WMPPNDLicenseFetchDescriptor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptorFactory> WMPPINDLicenseFetchDescriptorFactory_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptorFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.Protection.PlayReady.NDLicenseFetchDescriptor").Get(), &inst));
    return inst;
}

+ (WMPPNDLicenseFetchDescriptor*)makeInstance:(WMPPNDContentIDType)contentIDType
                               contentIDBytes:(NSArray* /* uint8_t */)contentIDBytes
              licenseFetchChallengeCustomData:(RTObject<WMPPINDCustomData>*)licenseFetchChallengeCustomData {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor> unmarshalledReturn;
    UINT32 __contentIDBytes_ArrayLen = 0;
    bool __contentIDBytes_IsTemp = false;
    uint8_t* __contentIDBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(contentIDBytes, &__contentIDBytes_ArrayLen, &__contentIDBytes_Array, &__contentIDBytes_IsTemp))
        assert(0);

    auto _comInst = WMPPINDLicenseFetchDescriptorFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance(
        (ABI::Windows::Media::Protection::PlayReady::NDContentIDType)contentIDType,
        __contentIDBytes_ArrayLen,
        __contentIDBytes_Array,
        _getRtInterface<ABI::Windows::Media::Protection::PlayReady::INDCustomData>(licenseFetchChallengeCustomData).Get(),
        unmarshalledReturn.GetAddressOf()));
    if (__contentIDBytes_IsTemp)
        CoTaskMemFree(__contentIDBytes_Array);
    return [_createRtProxy<WMPPNDLicenseFetchDescriptor>(unmarshalledReturn.Get()) retain];
}

- (WMPPNDContentIDType)contentIDType {
    ABI::Windows::Media::Protection::PlayReady::NDContentIDType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentIDType(&unmarshalledReturn));
    return (WMPPNDContentIDType)unmarshalledReturn;
}

- (NSArray* /* uint8_t */)contentID {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentID(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (RTObject<WMPPINDCustomData>*)licenseFetchChallengeCustomData {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDCustomData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_LicenseFetchChallengeCustomData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPINDCustomData>(unmarshalledReturn.Get());
}

- (void)setLicenseFetchChallengeCustomData:(RTObject<WMPPINDCustomData>*)licenseFetchChallengeCustomData {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->put_LicenseFetchChallengeCustomData(
        _getRtInterface<ABI::Windows::Media::Protection::PlayReady::INDCustomData>(licenseFetchChallengeCustomData).Get()));
}

@end

@implementation WMPPNDCustomData

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDCustomData> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Protection::PlayReady::INDCustomDataFactory> WMPPINDCustomDataFactory_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDCustomDataFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Protection.PlayReady.NDCustomData").Get(),
                                                       &inst));
    return inst;
}

+ (WMPPNDCustomData*)makeInstance:(NSArray* /* uint8_t */)customDataTypeIDBytes customDataBytes:(NSArray* /* uint8_t */)customDataBytes {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDCustomData> unmarshalledReturn;
    UINT32 __customDataTypeIDBytes_ArrayLen = 0;
    bool __customDataTypeIDBytes_IsTemp = false;
    uint8_t* __customDataTypeIDBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(customDataTypeIDBytes,
                                  &__customDataTypeIDBytes_ArrayLen,
                                  &__customDataTypeIDBytes_Array,
                                  &__customDataTypeIDBytes_IsTemp))
        assert(0);
    UINT32 __customDataBytes_ArrayLen = 0;
    bool __customDataBytes_IsTemp = false;
    uint8_t* __customDataBytes_Array = NULL;
    if (!ConvertToCArray<uint8_t>(customDataBytes, &__customDataBytes_ArrayLen, &__customDataBytes_Array, &__customDataBytes_IsTemp))
        assert(0);

    auto _comInst = WMPPINDCustomDataFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance(__customDataTypeIDBytes_ArrayLen,
                                                __customDataTypeIDBytes_Array,
                                                __customDataBytes_ArrayLen,
                                                __customDataBytes_Array,
                                                unmarshalledReturn.GetAddressOf()));
    if (__customDataTypeIDBytes_IsTemp)
        CoTaskMemFree(__customDataTypeIDBytes_Array);
    if (__customDataBytes_IsTemp)
        CoTaskMemFree(__customDataBytes_Array);
    return [_createRtProxy<WMPPNDCustomData>(unmarshalledReturn.Get()) retain];
}

- (NSArray* /* uint8_t */)customDataTypeID {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDCustomData>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomDataTypeID(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (NSArray* /* uint8_t */)customData {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDCustomData>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomData(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WMPPNDClient

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDClient> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Protection::PlayReady::INDClientFactory> WMPPINDClientFactory_inst() {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDClientFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Protection.PlayReady.NDClient").Get(),
                                                       &inst));
    return inst;
}

+ (WMPPNDClient*)makeInstance:(RTObject<WMPPINDDownloadEngine>*)downloadEngine
                 streamParser:(RTObject<WMPPINDStreamParser>*)streamParser
                   pMessenger:(RTObject<WMPPINDMessenger>*)pMessenger {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDClient> unmarshalledReturn;
    auto _comInst = WMPPINDClientFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateInstance(_getRtInterface<ABI::Windows::Media::Protection::PlayReady::INDDownloadEngine>(downloadEngine).Get(),
                                 _getRtInterface<ABI::Windows::Media::Protection::PlayReady::INDStreamParser>(streamParser).Get(),
                                 _getRtInterface<ABI::Windows::Media::Protection::PlayReady::INDMessenger>(pMessenger).Get(),
                                 unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMPPNDClient>(unmarshalledReturn.Get()) retain];
}

- (EventRegistrationToken)addRegistrationCompletedEvent:(void (^)(WMPPNDClient*, RTObject<WMPPINDRegistrationCompletedEventArgs>*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClient>(self);
    THROW_NS_IF_FAILED(_comInst->add_RegistrationCompleted(
        Make<
            ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDRegistrationCompletedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRegistrationCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClient>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RegistrationCompleted(token));
}

- (EventRegistrationToken)addProximityDetectionCompletedEvent:(void (^)(WMPPNDClient*,
                                                                        RTObject<WMPPINDProximityDetectionCompletedEventArgs>*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClient>(self);
    THROW_NS_IF_FAILED(_comInst->add_ProximityDetectionCompleted(
        Make<
            ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDProximityDetectionCompletedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeProximityDetectionCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClient>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ProximityDetectionCompleted(token));
}

- (EventRegistrationToken)addLicenseFetchCompletedEvent:(void (^)(WMPPNDClient*, RTObject<WMPPINDLicenseFetchCompletedEventArgs>*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClient>(self);
    THROW_NS_IF_FAILED(_comInst->add_LicenseFetchCompleted(
        Make<
            ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDLicenseFetchCompletedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLicenseFetchCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClient>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LicenseFetchCompleted(token));
}

- (EventRegistrationToken)addReRegistrationNeededEvent:(void (^)(WMPPNDClient*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClient>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReRegistrationNeeded(
        Make<ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReRegistrationNeededEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClient>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReRegistrationNeeded(token));
}

- (EventRegistrationToken)addClosedCaptionDataReceivedEvent:(void (^)(WMPPNDClient*,
                                                                      RTObject<WMPPINDClosedCaptionDataReceivedEventArgs>*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClient>(self);
    THROW_NS_IF_FAILED(_comInst->add_ClosedCaptionDataReceived(
        Make<
            ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDClosedCaptionDataReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosedCaptionDataReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClient>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ClosedCaptionDataReceived(token));
}

- (void)startAsync:(WFUri*)contentUrl
         startAsyncOptions:(unsigned int)startAsyncOptions
    registrationCustomData:(RTObject<WMPPINDCustomData>*)registrationCustomData
    licenseFetchDescriptor:(RTObject<WMPPINDLicenseFetchDescriptor>*)licenseFetchDescriptor
                   success:(void (^)(RTObject<WMPPINDStartResult>*))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDStartResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClient>(self);
    THROW_NS_IF_FAILED(_comInst->StartAsync(
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(contentUrl).Get(),
        startAsyncOptions,
        _getRtInterface<ABI::Windows::Media::Protection::PlayReady::INDCustomData>(registrationCustomData).Get(),
        _getRtInterface<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor>(licenseFetchDescriptor).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Protection::PlayReady::INDStartResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDStartResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDStartResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMPPINDStartResult>(result.Get()));
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

- (void)licenseFetchAsync:(RTObject<WMPPINDLicenseFetchDescriptor>*)licenseFetchDescriptor
                  success:(void (^)(RTObject<WMPPINDLicenseFetchResult>*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClient>(self);
    THROW_NS_IF_FAILED(_comInst->LicenseFetchAsync(
        _getRtInterface<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptor>(licenseFetchDescriptor).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMPPINDLicenseFetchResult>(result.Get()));
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

- (RTObject<WFIAsyncAction>*)reRegistrationAsync:(RTObject<WMPPINDCustomData>*)registrationCustomData {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClient>(self);
    THROW_NS_IF_FAILED(_comInst->ReRegistrationAsync(
        _getRtInterface<ABI::Windows::Media::Protection::PlayReady::INDCustomData>(registrationCustomData).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDClient>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMPPNDStorageFileHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::PlayReady::INDStorageFileHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Protection.PlayReady.NDStorageFileHelper").Get(),
                                              &out));
    return [_createRtProxy<WMPPNDStorageFileHelper>(out.Get()) retain];
}

- (NSMutableArray* /* NSString * */)getFileURLs:(RTObject<WSIStorageFile>*)file {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::PlayReady::INDStorageFileHelper>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetFileURLs(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_C_NSString_create(UINT32 size, HSTRING* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<HSTRING, RTCArrayObj<HSTRING, NSString, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WFGUID_create(UINT32 size, GUID* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<GUID, RTCArrayObj<GUID, WFGUID, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WMPPNDCertificateFeature_create(UINT32 size, ABI::Windows::Media::Protection::PlayReady::NDCertificateFeature* val) {
    std::unique_ptr<CArrayAdapter> adapter = std::make_unique<CArrayAdapterObj<
        ABI::Windows::Media::Protection::PlayReady::NDCertificateFeature,
        RTCArrayObj<ABI::Windows::Media::Protection::PlayReady::NDCertificateFeature, WMPPNDCertificateFeature, dummyObjCCreator>>>(size,
                                                                                                                                    val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WMCAudioStreamDescriptor_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Media::Core::AudioStreamDescriptor*>,
                                                RTMutableArrayObj<ABI::Windows::Media::Core::IAudioStreamDescriptor*,
                                                                  IVector<ABI::Windows::Media::Core::AudioStreamDescriptor*>,
                                                                  WMCAudioStreamDescriptor,
                                                                  ABI::Windows::Media::Core::AudioStreamDescriptor*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WMCVideoStreamDescriptor_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Media::Core::VideoStreamDescriptor*>,
                                                RTMutableArrayObj<ABI::Windows::Media::Core::IVideoStreamDescriptor*,
                                                                  IVector<ABI::Windows::Media::Core::VideoStreamDescriptor*>,
                                                                  WMCVideoStreamDescriptor,
                                                                  ABI::Windows::Media::Core::VideoStreamDescriptor*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
