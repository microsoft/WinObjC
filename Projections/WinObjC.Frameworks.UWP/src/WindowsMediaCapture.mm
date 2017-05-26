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

// WindowsMediaCapture.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Capture.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaCapture.h"
#include "WindowsMediaCapture_priv.h"

@implementation WMCAppCapture

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IAppCapture> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::Capture::IAppCaptureStatics> WMCIAppCaptureStatics_inst() {
    ComPtr<ABI::Windows::Media::Capture::IAppCaptureStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Capture.AppCapture").Get(), &inst));
    return inst;
}

+ (WMCAppCapture*)getForCurrentView {
    ComPtr<ABI::Windows::Media::Capture::IAppCapture> unmarshalledReturn;
    auto _comInst = WMCIAppCaptureStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCAppCapture>(unmarshalledReturn.Get());
}

- (BOOL)isCapturingAudio {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCapture>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCapturingAudio(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCapturingVideo {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCapture>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCapturingVideo(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addCapturingChangedEvent:(void (^)(WMCAppCapture*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCapture>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_CapturingChanged(Make<ITypedEventHandler_Windows_Media_Capture_AppCapture_System_Object>(handler).Get(),
                                       &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCapturingChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCapture>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CapturingChanged(token));
}

@end

@implementation WMCCameraCaptureUIPhotoCaptureSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCCameraCaptureUIPhotoFormat)format {
    ABI::Windows::Media::Capture::CameraCaptureUIPhotoFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_Format(&unmarshalledReturn));
    return (WMCCameraCaptureUIPhotoFormat)unmarshalledReturn;
}

- (void)setFormat:(WMCCameraCaptureUIPhotoFormat)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_Format((ABI::Windows::Media::Capture::CameraCaptureUIPhotoFormat)value));
}

- (WMCCameraCaptureUIMaxPhotoResolution)maxResolution {
    ABI::Windows::Media::Capture::CameraCaptureUIMaxPhotoResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxResolution(&unmarshalledReturn));
    return (WMCCameraCaptureUIMaxPhotoResolution)unmarshalledReturn;
}

- (void)setMaxResolution:(WMCCameraCaptureUIMaxPhotoResolution)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxResolution((ABI::Windows::Media::Capture::CameraCaptureUIMaxPhotoResolution)value));
}

- (WFSize*)croppedSizeInPixels {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CroppedSizeInPixels(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (void)setCroppedSizeInPixels:(WFSize*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_CroppedSizeInPixels(*[value internalStruct]));
}

- (WFSize*)croppedAspectRatio {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CroppedAspectRatio(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (void)setCroppedAspectRatio:(WFSize*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_CroppedAspectRatio(*[value internalStruct]));
}

- (BOOL)allowCropping {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowCropping(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowCropping:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowCropping((boolean)value));
}

@end

@implementation WMCCameraCaptureUIVideoCaptureSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCCameraCaptureUIVideoFormat)format {
    ABI::Windows::Media::Capture::CameraCaptureUIVideoFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_Format(&unmarshalledReturn));
    return (WMCCameraCaptureUIVideoFormat)unmarshalledReturn;
}

- (void)setFormat:(WMCCameraCaptureUIVideoFormat)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_Format((ABI::Windows::Media::Capture::CameraCaptureUIVideoFormat)value));
}

- (WMCCameraCaptureUIMaxVideoResolution)maxResolution {
    ABI::Windows::Media::Capture::CameraCaptureUIMaxVideoResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxResolution(&unmarshalledReturn));
    return (WMCCameraCaptureUIMaxVideoResolution)unmarshalledReturn;
}

- (void)setMaxResolution:(WMCCameraCaptureUIMaxVideoResolution)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxResolution((ABI::Windows::Media::Capture::CameraCaptureUIMaxVideoResolution)value));
}

- (float)maxDurationInSeconds {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxDurationInSeconds(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMaxDurationInSeconds:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxDurationInSeconds(value));
}

- (BOOL)allowTrimming {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowTrimming(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowTrimming:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowTrimming((boolean)value));
}

@end

@implementation WMCCameraCaptureUI

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::ICameraCaptureUI> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Capture.CameraCaptureUI").Get(), &out));
    return [_createRtProxy<WMCCameraCaptureUI>(out.Get()) retain];
}

- (WMCCameraCaptureUIPhotoCaptureSettings*)photoSettings {
    ComPtr<ABI::Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUI>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhotoSettings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCameraCaptureUIPhotoCaptureSettings>(unmarshalledReturn.Get());
}

- (WMCCameraCaptureUIVideoCaptureSettings*)videoSettings {
    ComPtr<ABI::Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUI>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoSettings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCameraCaptureUIVideoCaptureSettings>(unmarshalledReturn.Get());
}

- (void)captureFileAsync:(WMCCameraCaptureUIMode)mode success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICameraCaptureUI>(self);
    THROW_NS_IF_FAILED(_comInst->CaptureFileAsync((ABI::Windows::Media::Capture::CameraCaptureUIMode)mode, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFile*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFile> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFile>(result.Get()));
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

@implementation WMCMediaCaptureFailedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IMediaCaptureFailedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)message {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned int)code {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Code(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMCMediaCapture

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IMediaCapture> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Capture.MediaCapture").Get(), &out));
    return [_createRtProxy<WMCMediaCapture>(out.Get()) retain];
}

ComPtr<ABI::Windows::Media::Capture::IMediaCaptureStatics> WMCIMediaCaptureStatics_inst() {
    ComPtr<ABI::Windows::Media::Capture::IMediaCaptureStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Capture.MediaCapture").Get(), &inst));
    return inst;
}

+ (BOOL)isVideoProfileSupported:(NSString*)videoDeviceId {
    boolean unmarshalledReturn;
    auto _comInst = WMCIMediaCaptureStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsVideoProfileSupported(nsStrToHstr(videoDeviceId).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (NSArray* /* WMCMediaCaptureVideoProfile* */)findAllVideoProfiles:(NSString*)videoDeviceId {
    ComPtr<IVectorView<ABI::Windows::Media::Capture::MediaCaptureVideoProfile*>> unmarshalledReturn;
    auto _comInst = WMCIMediaCaptureStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllVideoProfiles(nsStrToHstr(videoDeviceId).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMCMediaCaptureVideoProfile_create(unmarshalledReturn.Get());
}

+ (NSArray* /* WMCMediaCaptureVideoProfile* */)findConcurrentProfiles:(NSString*)videoDeviceId {
    ComPtr<IVectorView<ABI::Windows::Media::Capture::MediaCaptureVideoProfile*>> unmarshalledReturn;
    auto _comInst = WMCIMediaCaptureStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindConcurrentProfiles(nsStrToHstr(videoDeviceId).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMCMediaCaptureVideoProfile_create(unmarshalledReturn.Get());
}

+ (NSArray* /* WMCMediaCaptureVideoProfile* */)findKnownVideoProfiles:(NSString*)videoDeviceId name:(WMCKnownVideoProfile)name {
    ComPtr<IVectorView<ABI::Windows::Media::Capture::MediaCaptureVideoProfile*>> unmarshalledReturn;
    auto _comInst = WMCIMediaCaptureStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindKnownVideoProfiles(nsStrToHstr(videoDeviceId).Get(),
                                                        (ABI::Windows::Media::Capture::KnownVideoProfile)name,
                                                        unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMCMediaCaptureVideoProfile_create(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)initializeAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->InitializeAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)initializeWithSettingsAsync:(WMCMediaCaptureInitializationSettings*)mediaCaptureInitializationSettings {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->InitializeWithSettingsAsync(
        _getRtInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings>(mediaCaptureInitializationSettings).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)startRecordToStorageFileAsync:(WMMMediaEncodingProfile*)encodingProfile file:(RTObject<WSIStorageFile>*)file {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->StartRecordToStorageFileAsync(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(encodingProfile).Get(),
        _getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)startRecordToStreamAsync:(WMMMediaEncodingProfile*)encodingProfile
                                               stream:(RTObject<WSSIRandomAccessStream>*)stream {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->StartRecordToStreamAsync(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(encodingProfile).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(stream).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)startRecordToCustomSinkAsync:(WMMMediaEncodingProfile*)encodingProfile
                                          customMediaSink:(RTObject<WMIMediaExtension>*)customMediaSink {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->StartRecordToCustomSinkAsync(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(encodingProfile).Get(),
        _getRtInterface<ABI::Windows::Media::IMediaExtension>(customMediaSink).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)startRecordToCustomSinkIdAsync:(WMMMediaEncodingProfile*)encodingProfile
                                     customSinkActivationId:(NSString*)customSinkActivationId
                                         customSinkSettings:(RTObject<WFCIPropertySet>*)customSinkSettings {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->StartRecordToCustomSinkIdAsync(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(encodingProfile).Get(),
        nsStrToHstr(customSinkActivationId).Get(),
        _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(customSinkSettings).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)stopRecordAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->StopRecordAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)capturePhotoToStorageFileAsync:(WMMImageEncodingProperties*)type file:(RTObject<WSIStorageFile>*)file {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->CapturePhotoToStorageFileAsync(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IImageEncodingProperties>(type).Get(),
        _getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)capturePhotoToStreamAsync:(WMMImageEncodingProperties*)type stream:(RTObject<WSSIRandomAccessStream>*)stream {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(
        _comInst->CapturePhotoToStreamAsync(_getRtInterface<ABI::Windows::Media::MediaProperties::IImageEncodingProperties>(type).Get(),
                                            _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(stream).Get(),
                                            unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)addEffectAsync:(WMCMediaStreamType)mediaStreamType
                         effectActivationID:(NSString*)effectActivationID
                             effectSettings:(RTObject<WFCIPropertySet>*)effectSettings {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->AddEffectAsync((ABI::Windows::Media::Capture::MediaStreamType)mediaStreamType,
                                                nsStrToHstr(effectActivationID).Get(),
                                                _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(effectSettings).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)clearEffectsAsync:(WMCMediaStreamType)mediaStreamType {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(
        _comInst->ClearEffectsAsync((ABI::Windows::Media::Capture::MediaStreamType)mediaStreamType, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)setEncoderProperty:(WMCMediaStreamType)mediaStreamType propertyId:(WFGUID*)propertyId propertyValue:(RTObject*)propertyValue {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->SetEncoderProperty((ABI::Windows::Media::Capture::MediaStreamType)mediaStreamType,
                                                    propertyId.guidValue,
                                                    [propertyValue comObj].Get()));
}

- (RTObject*)getEncoderProperty:(WMCMediaStreamType)mediaStreamType propertyId:(WFGUID*)propertyId {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->GetEncoderProperty((ABI::Windows::Media::Capture::MediaStreamType)mediaStreamType,
                                                    propertyId.guidValue,
                                                    unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addFailedEvent:(WMCMediaCaptureFailedEventHandler)errorEventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->add_Failed(Make<WMCMediaCaptureFailedEventHandler_shim>(errorEventHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeFailedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Failed(eventCookie));
}

- (EventRegistrationToken)addRecordLimitationExceededEvent:(WMCRecordLimitationExceededEventHandler)recordLimitationExceededEventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->add_RecordLimitationExceeded(
        Make<WMCRecordLimitationExceededEventHandler_shim>(recordLimitationExceededEventHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRecordLimitationExceededEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RecordLimitationExceeded(eventCookie));
}

- (WMCMediaCaptureSettings*)mediaCaptureSettings {
    ComPtr<ABI::Windows::Media::Capture::IMediaCaptureSettings> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaCaptureSettings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaCaptureSettings>(unmarshalledReturn.Get());
}

- (WMDAudioDeviceController*)audioDeviceController {
    ComPtr<ABI::Windows::Media::Devices::IAudioDeviceController> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioDeviceController(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDAudioDeviceController>(unmarshalledReturn.Get());
}

- (WMDVideoDeviceController*)videoDeviceController {
    ComPtr<ABI::Windows::Media::Devices::IVideoDeviceController> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoDeviceController(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDVideoDeviceController>(unmarshalledReturn.Get());
}

- (void)setPreviewMirroring:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->SetPreviewMirroring((boolean)value));
}

- (BOOL)getPreviewMirroring {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->GetPreviewMirroring(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setPreviewRotation:(WMCVideoRotation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->SetPreviewRotation((ABI::Windows::Media::Capture::VideoRotation)value));
}

- (WMCVideoRotation)getPreviewRotation {
    ABI::Windows::Media::Capture::VideoRotation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->GetPreviewRotation(&unmarshalledReturn));
    return (WMCVideoRotation)unmarshalledReturn;
}

- (void)setRecordRotation:(WMCVideoRotation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->SetRecordRotation((ABI::Windows::Media::Capture::VideoRotation)value));
}

- (WMCVideoRotation)getRecordRotation {
    ABI::Windows::Media::Capture::VideoRotation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture>(self);
    THROW_NS_IF_FAILED(_comInst->GetRecordRotation(&unmarshalledReturn));
    return (WMCVideoRotation)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)startPreviewAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoPreview>(self);
    THROW_NS_IF_FAILED(_comInst->StartPreviewAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)startPreviewToCustomSinkAsync:(WMMMediaEncodingProfile*)encodingProfile
                                           customMediaSink:(RTObject<WMIMediaExtension>*)customMediaSink {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoPreview>(self);
    THROW_NS_IF_FAILED(_comInst->StartPreviewToCustomSinkAsync(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(encodingProfile).Get(),
        _getRtInterface<ABI::Windows::Media::IMediaExtension>(customMediaSink).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)startPreviewToCustomSinkIdAsync:(WMMMediaEncodingProfile*)encodingProfile
                                      customSinkActivationId:(NSString*)customSinkActivationId
                                          customSinkSettings:(RTObject<WFCIPropertySet>*)customSinkSettings {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoPreview>(self);
    THROW_NS_IF_FAILED(_comInst->StartPreviewToCustomSinkIdAsync(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(encodingProfile).Get(),
        nsStrToHstr(customSinkActivationId).Get(),
        _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(customSinkSettings).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)stopPreviewAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoPreview>(self);
    THROW_NS_IF_FAILED(_comInst->StopPreviewAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)prepareLowLagRecordToStorageFileAsync:(WMMMediaEncodingProfile*)encodingProfile
                                         file:(RTObject<WSIStorageFile>*)file
                                      success:(void (^)(WMCLowLagMediaRecording*))success
                                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::LowLagMediaRecording*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture2>(self);
    THROW_NS_IF_FAILED(_comInst->PrepareLowLagRecordToStorageFileAsync(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(encodingProfile).Get(),
        _getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::LowLagMediaRecording*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::LowLagMediaRecording*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Capture::ILowLagMediaRecording> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMCLowLagMediaRecording>(result.Get()));
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

- (void)prepareLowLagRecordToStreamAsync:(WMMMediaEncodingProfile*)encodingProfile
                                  stream:(RTObject<WSSIRandomAccessStream>*)stream
                                 success:(void (^)(WMCLowLagMediaRecording*))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::LowLagMediaRecording*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture2>(self);
    THROW_NS_IF_FAILED(_comInst->PrepareLowLagRecordToStreamAsync(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(encodingProfile).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(stream).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::LowLagMediaRecording*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::LowLagMediaRecording*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Capture::ILowLagMediaRecording> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMCLowLagMediaRecording>(result.Get()));
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

- (void)prepareLowLagRecordToCustomSinkAsync:(WMMMediaEncodingProfile*)encodingProfile
                             customMediaSink:(RTObject<WMIMediaExtension>*)customMediaSink
                                     success:(void (^)(WMCLowLagMediaRecording*))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::LowLagMediaRecording*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture2>(self);
    THROW_NS_IF_FAILED(_comInst->PrepareLowLagRecordToCustomSinkAsync(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(encodingProfile).Get(),
        _getRtInterface<ABI::Windows::Media::IMediaExtension>(customMediaSink).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::LowLagMediaRecording*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::LowLagMediaRecording*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Capture::ILowLagMediaRecording> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMCLowLagMediaRecording>(result.Get()));
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

- (void)prepareLowLagRecordToCustomSinkIdAsync:(WMMMediaEncodingProfile*)encodingProfile
                        customSinkActivationId:(NSString*)customSinkActivationId
                            customSinkSettings:(RTObject<WFCIPropertySet>*)customSinkSettings
                                       success:(void (^)(WMCLowLagMediaRecording*))success
                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::LowLagMediaRecording*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture2>(self);
    THROW_NS_IF_FAILED(_comInst->PrepareLowLagRecordToCustomSinkIdAsync(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(encodingProfile).Get(),
        nsStrToHstr(customSinkActivationId).Get(),
        _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(customSinkSettings).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::LowLagMediaRecording*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::LowLagMediaRecording*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Capture::ILowLagMediaRecording> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMCLowLagMediaRecording>(result.Get()));
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

- (void)prepareLowLagPhotoCaptureAsync:(WMMImageEncodingProperties*)type
                               success:(void (^)(WMCLowLagPhotoCapture*))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::LowLagPhotoCapture*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture2>(self);
    THROW_NS_IF_FAILED(_comInst->PrepareLowLagPhotoCaptureAsync(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IImageEncodingProperties>(type).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::LowLagPhotoCapture*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::LowLagPhotoCapture*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Capture::ILowLagPhotoCapture> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMCLowLagPhotoCapture>(result.Get()));
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

- (void)prepareLowLagPhotoSequenceCaptureAsync:(WMMImageEncodingProperties*)type
                                       success:(void (^)(WMCLowLagPhotoSequenceCapture*))success
                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::LowLagPhotoSequenceCapture*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture2>(self);
    THROW_NS_IF_FAILED(_comInst->PrepareLowLagPhotoSequenceCaptureAsync(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IImageEncodingProperties>(type).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::LowLagPhotoSequenceCapture*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::LowLagPhotoSequenceCapture*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Capture::ILowLagPhotoSequenceCapture> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMCLowLagPhotoSequenceCapture>(result.Get()));
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

- (RTObject<WFIAsyncAction>*)setEncodingPropertiesAsync:(WMCMediaStreamType)mediaStreamType
                                mediaEncodingProperties:(RTObject<WMMIMediaEncodingProperties>*)mediaEncodingProperties
                                      encoderProperties:(WMMMediaPropertySet*)encoderProperties {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture2>(self);
    THROW_NS_IF_FAILED(_comInst->SetEncodingPropertiesAsync(
        (ABI::Windows::Media::Capture::MediaStreamType)mediaStreamType,
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(mediaEncodingProperties).Get(),
        _getRtInterface<IMap<GUID, IInspectable*>>(encoderProperties).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (void)prepareVariablePhotoSequenceCaptureAsync:(WMMImageEncodingProperties*)type
                                         success:(void (^)(WMCCVariablePhotoSequenceCapture*))success
                                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::Core::VariablePhotoSequenceCapture*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture3>(self);
    THROW_NS_IF_FAILED(_comInst->PrepareVariablePhotoSequenceCaptureAsync(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IImageEncodingProperties>(type).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::Core::VariablePhotoSequenceCapture*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::Core::VariablePhotoSequenceCapture*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Capture::Core::IVariablePhotoSequenceCapture> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMCCVariablePhotoSequenceCapture>(result.Get()));
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

- (EventRegistrationToken)addFocusChangedEvent:(void (^)(WMCMediaCapture*, WMCMediaCaptureFocusChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture3>(self);
    THROW_NS_IF_FAILED(_comInst->add_FocusChanged(
        Make<ITypedEventHandler_Windows_Media_Capture_MediaCapture_Windows_Media_Capture_MediaCaptureFocusChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeFocusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture3>(self);
    THROW_NS_IF_FAILED(_comInst->remove_FocusChanged(token));
}

- (EventRegistrationToken)addPhotoConfirmationCapturedEvent:(void (^)(WMCMediaCapture*, WMCPhotoConfirmationCapturedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture3>(self);
    THROW_NS_IF_FAILED(_comInst->add_PhotoConfirmationCaptured(
        Make<ITypedEventHandler_Windows_Media_Capture_MediaCapture_Windows_Media_Capture_PhotoConfirmationCapturedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePhotoConfirmationCapturedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture3>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PhotoConfirmationCaptured(token));
}

- (void)addAudioEffectAsync:(RTObject<WMEIAudioEffectDefinition>*)definition
                    success:(void (^)(RTObject<WMIMediaExtension>*))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::IMediaExtension*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture4>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddAudioEffectAsync(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get(),
                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::IMediaExtension*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::IMediaExtension*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::IMediaExtension> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMIMediaExtension>(result.Get()));
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

- (void)addVideoEffectAsync:(RTObject<WMEIVideoEffectDefinition>*)definition
            mediaStreamType:(WMCMediaStreamType)mediaStreamType
                    success:(void (^)(RTObject<WMIMediaExtension>*))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::IMediaExtension*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture4>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddVideoEffectAsync(_getRtInterface<ABI::Windows::Media::Effects::IVideoEffectDefinition>(definition).Get(),
                                      (ABI::Windows::Media::Capture::MediaStreamType)mediaStreamType,
                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::IMediaExtension*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::IMediaExtension*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::IMediaExtension> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMIMediaExtension>(result.Get()));
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

- (RTObject<WFIAsyncAction>*)pauseRecordAsync:(WMDMediaCapturePauseBehavior)behavior {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture4>(self);
    THROW_NS_IF_FAILED(
        _comInst->PauseRecordAsync((ABI::Windows::Media::Devices::MediaCapturePauseBehavior)behavior, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)resumeRecordAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture4>(self);
    THROW_NS_IF_FAILED(_comInst->ResumeRecordAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addCameraStreamStateChangedEvent:(void (^)(WMCMediaCapture*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture4>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_CameraStreamStateChanged(Make<ITypedEventHandler_Windows_Media_Capture_MediaCapture_System_Object>(handler).Get(),
                                               &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCameraStreamStateChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture4>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CameraStreamStateChanged(token));
}

- (WMDCameraStreamState)cameraStreamState {
    ABI::Windows::Media::Devices::CameraStreamState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture4>(self);
    THROW_NS_IF_FAILED(_comInst->get_CameraStreamState(&unmarshalledReturn));
    return (WMDCameraStreamState)unmarshalledReturn;
}

- (void)getPreviewFrameAsyncWithSuccess:(void (^)(WMVideoFrame*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::VideoFrame*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture4>(self);
    THROW_NS_IF_FAILED(_comInst->GetPreviewFrameAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::VideoFrame*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::VideoFrame*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::IVideoFrame> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMVideoFrame>(result.Get()));
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

- (void)getPreviewFrameCopyAsync:(WMVideoFrame*)destination success:(void (^)(WMVideoFrame*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::VideoFrame*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture4>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetPreviewFrameCopyAsync(_getRtInterface<ABI::Windows::Media::IVideoFrame>(destination).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::VideoFrame*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::VideoFrame*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::IVideoFrame> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMVideoFrame>(result.Get()));
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

- (EventRegistrationToken)addThermalStatusChangedEvent:(void (^)(WMCMediaCapture*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture4>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ThermalStatusChanged(Make<ITypedEventHandler_Windows_Media_Capture_MediaCapture_System_Object>(handler).Get(),
                                           &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeThermalStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture4>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ThermalStatusChanged(token));
}

- (WMCMediaCaptureThermalStatus)thermalStatus {
    ABI::Windows::Media::Capture::MediaCaptureThermalStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture4>(self);
    THROW_NS_IF_FAILED(_comInst->get_ThermalStatus(&unmarshalledReturn));
    return (WMCMediaCaptureThermalStatus)unmarshalledReturn;
}

- (void)prepareAdvancedPhotoCaptureAsync:(WMMImageEncodingProperties*)encodingProperties
                                 success:(void (^)(WMCAdvancedPhotoCapture*))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::AdvancedPhotoCapture*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture4>(self);
    THROW_NS_IF_FAILED(_comInst->PrepareAdvancedPhotoCaptureAsync(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IImageEncodingProperties>(encodingProperties).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::AdvancedPhotoCapture*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::AdvancedPhotoCapture*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Capture::IAdvancedPhotoCapture> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMCAdvancedPhotoCapture>(result.Get()));
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

- (RTObject<WFIAsyncAction>*)removeEffectAsync:(RTObject<WMIMediaExtension>*)effect {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture5>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveEffectAsync(_getRtInterface<ABI::Windows::Media::IMediaExtension>(effect).Get(),
                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)pauseRecordWithResultAsync:(WMDMediaCapturePauseBehavior)behavior
                           success:(void (^)(WMCMediaCapturePauseResult*))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::MediaCapturePauseResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture5>(self);
    THROW_NS_IF_FAILED(
        _comInst->PauseRecordWithResultAsync((ABI::Windows::Media::Devices::MediaCapturePauseBehavior)behavior, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::MediaCapturePauseResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::MediaCapturePauseResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Capture::IMediaCapturePauseResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMCMediaCapturePauseResult>(result.Get()));
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

- (void)stopRecordWithResultAsyncWithSuccess:(void (^)(WMCMediaCaptureStopResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::MediaCaptureStopResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture5>(self);
    THROW_NS_IF_FAILED(_comInst->StopRecordWithResultAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::MediaCaptureStopResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::MediaCaptureStopResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Capture::IMediaCaptureStopResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMCMediaCaptureStopResult>(result.Get()));
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

- (NSDictionary* /* NSString *, WMCFMediaFrameSource* */)frameSources {
    ComPtr<IMapView<HSTRING, ABI::Windows::Media::Capture::Frames::MediaFrameSource*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture5>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameSources(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_WMCFMediaFrameSource_create(unmarshalledReturn.Get());
}

- (void)createFrameReaderAsync:(WMCFMediaFrameSource*)inputSource
                       success:(void (^)(WMCFMediaFrameReader*))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::Frames::MediaFrameReader*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture5>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateFrameReaderAsync(_getRtInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSource>(inputSource).Get(),
                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::Frames::MediaFrameReader*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::Frames::MediaFrameReader*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameReader> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMCFMediaFrameReader>(result.Get()));
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

- (void)createFrameReaderWithSubtypeAsync:(WMCFMediaFrameSource*)inputSource
                            outputSubtype:(NSString*)outputSubtype
                                  success:(void (^)(WMCFMediaFrameReader*))success
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::Frames::MediaFrameReader*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture5>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFrameReaderWithSubtypeAsync(
        _getRtInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSource>(inputSource).Get(),
        nsStrToHstr(outputSubtype).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::Frames::MediaFrameReader*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::Frames::MediaFrameReader*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameReader> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMCFMediaFrameReader>(result.Get()));
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

- (void)createFrameReaderWithSubtypeAndSizeAsync:(WMCFMediaFrameSource*)inputSource
                                   outputSubtype:(NSString*)outputSubtype
                                      outputSize:(WGIBitmapSize*)outputSize
                                         success:(void (^)(WMCFMediaFrameReader*))success
                                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::Frames::MediaFrameReader*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapture5>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFrameReaderWithSubtypeAndSizeAsync(
        _getRtInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSource>(inputSource).Get(),
        nsStrToHstr(outputSubtype).Get(),
        *[outputSize internalStruct],
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::Frames::MediaFrameReader*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::Frames::MediaFrameReader*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameReader> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMCFMediaFrameReader>(result.Get()));
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

@implementation WMCMediaCaptureVideoProfileMediaDescription

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)width {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_Width(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)height {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)frameRate {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameRate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isVariablePhotoSequenceSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsVariablePhotoSequenceSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isHdrVideoSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsHdrVideoSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMCMediaCaptureVideoProfile

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IMediaCaptureVideoProfile> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)videoDeviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoDeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* WMCMediaCaptureVideoProfileMediaDescription* */)supportedPreviewMediaDescription {
    ComPtr<IVectorView<ABI::Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedPreviewMediaDescription(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMCMediaCaptureVideoProfileMediaDescription_create(unmarshalledReturn.Get());
}

- (NSArray* /* WMCMediaCaptureVideoProfileMediaDescription* */)supportedRecordMediaDescription {
    ComPtr<IVectorView<ABI::Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedRecordMediaDescription(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMCMediaCaptureVideoProfileMediaDescription_create(unmarshalledReturn.Get());
}

- (NSArray* /* WMCMediaCaptureVideoProfileMediaDescription* */)supportedPhotoMediaDescription {
    ComPtr<IVectorView<ABI::Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedPhotoMediaDescription(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMCMediaCaptureVideoProfileMediaDescription_create(unmarshalledReturn.Get());
}

- (NSArray* /* WMCMediaCaptureVideoProfile* */)getConcurrency {
    ComPtr<IVectorView<ABI::Windows::Media::Capture::MediaCaptureVideoProfile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoProfile>(self);
    THROW_NS_IF_FAILED(_comInst->GetConcurrency(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMCMediaCaptureVideoProfile_create(unmarshalledReturn.Get());
}

@end

@implementation WMCMediaCaptureInitializationSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Capture.MediaCaptureInitializationSettings").Get(),
                                              &out));
    return [_createRtProxy<WMCMediaCaptureInitializationSettings>(out.Get()) retain];
}

- (void)setAudioDeviceId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_AudioDeviceId(nsStrToHstr(value).Get()));
}

- (NSString*)audioDeviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioDeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setVideoDeviceId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_VideoDeviceId(nsStrToHstr(value).Get()));
}

- (NSString*)videoDeviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoDeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setStreamingCaptureMode:(WMCStreamingCaptureMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_StreamingCaptureMode((ABI::Windows::Media::Capture::StreamingCaptureMode)value));
}

- (WMCStreamingCaptureMode)streamingCaptureMode {
    ABI::Windows::Media::Capture::StreamingCaptureMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_StreamingCaptureMode(&unmarshalledReturn));
    return (WMCStreamingCaptureMode)unmarshalledReturn;
}

- (void)setPhotoCaptureSource:(WMCPhotoCaptureSource)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_PhotoCaptureSource((ABI::Windows::Media::Capture::PhotoCaptureSource)value));
}

- (WMCPhotoCaptureSource)photoCaptureSource {
    ABI::Windows::Media::Capture::PhotoCaptureSource unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhotoCaptureSource(&unmarshalledReturn));
    return (WMCPhotoCaptureSource)unmarshalledReturn;
}

- (void)setMediaCategory:(WMCMediaCategory)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->put_MediaCategory((ABI::Windows::Media::Capture::MediaCategory)value));
}

- (WMCMediaCategory)mediaCategory {
    ABI::Windows::Media::Capture::MediaCategory unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaCategory(&unmarshalledReturn));
    return (WMCMediaCategory)unmarshalledReturn;
}

- (void)setAudioProcessing:(WMAudioProcessing)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AudioProcessing((ABI::Windows::Media::AudioProcessing)value));
}

- (WMAudioProcessing)audioProcessing {
    ABI::Windows::Media::AudioProcessing unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioProcessing(&unmarshalledReturn));
    return (WMAudioProcessing)unmarshalledReturn;
}

- (void)setAudioSource:(RTObject<WMCIMediaSource>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings3>(self);
    THROW_NS_IF_FAILED(_comInst->put_AudioSource(_getRtInterface<ABI::Windows::Media::Core::IMediaSource>(value).Get()));
}

- (RTObject<WMCIMediaSource>*)audioSource {
    ComPtr<ABI::Windows::Media::Core::IMediaSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings3>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCIMediaSource>(unmarshalledReturn.Get());
}

- (void)setVideoSource:(RTObject<WMCIMediaSource>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings3>(self);
    THROW_NS_IF_FAILED(_comInst->put_VideoSource(_getRtInterface<ABI::Windows::Media::Core::IMediaSource>(value).Get()));
}

- (RTObject<WMCIMediaSource>*)videoSource {
    ComPtr<ABI::Windows::Media::Core::IMediaSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings3>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCIMediaSource>(unmarshalledReturn.Get());
}

- (WMCMediaCaptureVideoProfile*)videoProfile {
    ComPtr<ABI::Windows::Media::Capture::IMediaCaptureVideoProfile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings4>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoProfile(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaCaptureVideoProfile>(unmarshalledReturn.Get());
}

- (void)setVideoProfile:(WMCMediaCaptureVideoProfile*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings4>(self);
    THROW_NS_IF_FAILED(_comInst->put_VideoProfile(_getRtInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoProfile>(value).Get()));
}

- (WMCMediaCaptureVideoProfileMediaDescription*)previewMediaDescription {
    ComPtr<ABI::Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings4>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviewMediaDescription(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaCaptureVideoProfileMediaDescription>(unmarshalledReturn.Get());
}

- (void)setPreviewMediaDescription:(WMCMediaCaptureVideoProfileMediaDescription*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings4>(self);
    THROW_NS_IF_FAILED(_comInst->put_PreviewMediaDescription(
        _getRtInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription>(value).Get()));
}

- (WMCMediaCaptureVideoProfileMediaDescription*)recordMediaDescription {
    ComPtr<ABI::Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings4>(self);
    THROW_NS_IF_FAILED(_comInst->get_RecordMediaDescription(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaCaptureVideoProfileMediaDescription>(unmarshalledReturn.Get());
}

- (void)setRecordMediaDescription:(WMCMediaCaptureVideoProfileMediaDescription*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings4>(self);
    THROW_NS_IF_FAILED(_comInst->put_RecordMediaDescription(
        _getRtInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription>(value).Get()));
}

- (WMCMediaCaptureVideoProfileMediaDescription*)photoMediaDescription {
    ComPtr<ABI::Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings4>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhotoMediaDescription(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaCaptureVideoProfileMediaDescription>(unmarshalledReturn.Get());
}

- (void)setPhotoMediaDescription:(WMCMediaCaptureVideoProfileMediaDescription*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings4>(self);
    THROW_NS_IF_FAILED(_comInst->put_PhotoMediaDescription(
        _getRtInterface<ABI::Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription>(value).Get()));
}

- (WMCFMediaFrameSourceGroup*)sourceGroup {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGroup> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings5>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceGroup(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFMediaFrameSourceGroup>(unmarshalledReturn.Get());
}

- (void)setSourceGroup:(WMCFMediaFrameSourceGroup*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings5>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_SourceGroup(_getRtInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGroup>(value).Get()));
}

- (WMCMediaCaptureSharingMode)sharingMode {
    ABI::Windows::Media::Capture::MediaCaptureSharingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings5>(self);
    THROW_NS_IF_FAILED(_comInst->get_SharingMode(&unmarshalledReturn));
    return (WMCMediaCaptureSharingMode)unmarshalledReturn;
}

- (void)setSharingMode:(WMCMediaCaptureSharingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings5>(self);
    THROW_NS_IF_FAILED(_comInst->put_SharingMode((ABI::Windows::Media::Capture::MediaCaptureSharingMode)value));
}

- (WMCMediaCaptureMemoryPreference)memoryPreference {
    ABI::Windows::Media::Capture::MediaCaptureMemoryPreference unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings5>(self);
    THROW_NS_IF_FAILED(_comInst->get_MemoryPreference(&unmarshalledReturn));
    return (WMCMediaCaptureMemoryPreference)unmarshalledReturn;
}

- (void)setMemoryPreference:(WMCMediaCaptureMemoryPreference)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings5>(self);
    THROW_NS_IF_FAILED(_comInst->put_MemoryPreference((ABI::Windows::Media::Capture::MediaCaptureMemoryPreference)value));
}

@end

@implementation WMCMediaCaptureSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IMediaCaptureSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)audioDeviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioDeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)videoDeviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoDeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMCStreamingCaptureMode)streamingCaptureMode {
    ABI::Windows::Media::Capture::StreamingCaptureMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_StreamingCaptureMode(&unmarshalledReturn));
    return (WMCStreamingCaptureMode)unmarshalledReturn;
}

- (WMCPhotoCaptureSource)photoCaptureSource {
    ABI::Windows::Media::Capture::PhotoCaptureSource unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhotoCaptureSource(&unmarshalledReturn));
    return (WMCPhotoCaptureSource)unmarshalledReturn;
}

- (WMCVideoDeviceCharacteristic)videoDeviceCharacteristic {
    ABI::Windows::Media::Capture::VideoDeviceCharacteristic unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoDeviceCharacteristic(&unmarshalledReturn));
    return (WMCVideoDeviceCharacteristic)unmarshalledReturn;
}

- (BOOL)concurrentRecordAndPhotoSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConcurrentRecordAndPhotoSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)concurrentRecordAndPhotoSequenceSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConcurrentRecordAndPhotoSequenceSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)cameraSoundRequiredForRegion {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CameraSoundRequiredForRegion(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (id /* unsigned int */)horizontal35mmEquivalentFocalLength {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Horizontal35mmEquivalentFocalLength(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (id /* int */)pitchOffsetDegrees {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PitchOffsetDegrees(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (id /* unsigned int */)vertical35mmEquivalentFocalLength {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Vertical35mmEquivalentFocalLength(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (WMCMediaCategory)mediaCategory {
    ABI::Windows::Media::Capture::MediaCategory unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaCategory(&unmarshalledReturn));
    return (WMCMediaCategory)unmarshalledReturn;
}

- (WMAudioProcessing)audioProcessing {
    ABI::Windows::Media::AudioProcessing unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioProcessing(&unmarshalledReturn));
    return (WMAudioProcessing)unmarshalledReturn;
}

@end

@implementation WMCLowLagMediaRecording

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::ILowLagMediaRecording> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WFIAsyncAction>*)startAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ILowLagMediaRecording>(self);
    THROW_NS_IF_FAILED(_comInst->StartAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)stopAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ILowLagMediaRecording>(self);
    THROW_NS_IF_FAILED(_comInst->StopAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)finishAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ILowLagMediaRecording>(self);
    THROW_NS_IF_FAILED(_comInst->FinishAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)pauseAsync:(WMDMediaCapturePauseBehavior)behavior {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ILowLagMediaRecording2>(self);
    THROW_NS_IF_FAILED(
        _comInst->PauseAsync((ABI::Windows::Media::Devices::MediaCapturePauseBehavior)behavior, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)resumeAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ILowLagMediaRecording2>(self);
    THROW_NS_IF_FAILED(_comInst->ResumeAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)pauseWithResultAsync:(WMDMediaCapturePauseBehavior)behavior
                     success:(void (^)(WMCMediaCapturePauseResult*))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::MediaCapturePauseResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ILowLagMediaRecording3>(self);
    THROW_NS_IF_FAILED(
        _comInst->PauseWithResultAsync((ABI::Windows::Media::Devices::MediaCapturePauseBehavior)behavior, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::MediaCapturePauseResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::MediaCapturePauseResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Capture::IMediaCapturePauseResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMCMediaCapturePauseResult>(result.Get()));
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

- (void)stopWithResultAsyncWithSuccess:(void (^)(WMCMediaCaptureStopResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::MediaCaptureStopResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ILowLagMediaRecording3>(self);
    THROW_NS_IF_FAILED(_comInst->StopWithResultAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::MediaCaptureStopResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::MediaCaptureStopResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Capture::IMediaCaptureStopResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMCMediaCaptureStopResult>(result.Get()));
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

@implementation WMCLowLagPhotoCapture

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::ILowLagPhotoCapture> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)captureAsyncWithSuccess:(void (^)(WMCCapturedPhoto*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::CapturedPhoto*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ILowLagPhotoCapture>(self);
    THROW_NS_IF_FAILED(_comInst->CaptureAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::CapturedPhoto*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::CapturedPhoto*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Capture::ICapturedPhoto> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMCCapturedPhoto>(result.Get()));
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

- (RTObject<WFIAsyncAction>*)finishAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ILowLagPhotoCapture>(self);
    THROW_NS_IF_FAILED(_comInst->FinishAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WMCLowLagPhotoSequenceCapture

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::ILowLagPhotoSequenceCapture> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WFIAsyncAction>*)startAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ILowLagPhotoSequenceCapture>(self);
    THROW_NS_IF_FAILED(_comInst->StartAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)stopAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ILowLagPhotoSequenceCapture>(self);
    THROW_NS_IF_FAILED(_comInst->StopAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)finishAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ILowLagPhotoSequenceCapture>(self);
    THROW_NS_IF_FAILED(_comInst->FinishAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addPhotoCapturedEvent:(void (^)(WMCLowLagPhotoSequenceCapture*, WMCPhotoCapturedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ILowLagPhotoSequenceCapture>(self);
    THROW_NS_IF_FAILED(_comInst->add_PhotoCaptured(
        Make<ITypedEventHandler_Windows_Media_Capture_LowLagPhotoSequenceCapture_Windows_Media_Capture_PhotoCapturedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePhotoCapturedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ILowLagPhotoSequenceCapture>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PhotoCaptured(token));
}

@end

@implementation WMCMediaCaptureFocusChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IMediaCaptureFocusChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMDMediaCaptureFocusState)focusState {
    ABI::Windows::Media::Devices::MediaCaptureFocusState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureFocusChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_FocusState(&unmarshalledReturn));
    return (WMDMediaCaptureFocusState)unmarshalledReturn;
}

@end

@implementation WMCPhotoConfirmationCapturedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IPhotoConfirmationCapturedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCCapturedFrame*)frame {
    ComPtr<ABI::Windows::Media::Capture::ICapturedFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IPhotoConfirmationCapturedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Frame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCapturedFrame>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)captureTimeOffset {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IPhotoConfirmationCapturedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CaptureTimeOffset(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

@end

@implementation WMCAdvancedPhotoCapture

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IAdvancedPhotoCapture> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)captureAsyncWithSuccess:(void (^)(WMCAdvancedCapturedPhoto*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::AdvancedCapturedPhoto*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAdvancedPhotoCapture>(self);
    THROW_NS_IF_FAILED(_comInst->CaptureAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::AdvancedCapturedPhoto*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::AdvancedCapturedPhoto*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Capture::IAdvancedCapturedPhoto> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMCAdvancedCapturedPhoto>(result.Get()));
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

- (void)captureWithContextAsync:(RTObject*)context
                        success:(void (^)(WMCAdvancedCapturedPhoto*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::AdvancedCapturedPhoto*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAdvancedPhotoCapture>(self);
    THROW_NS_IF_FAILED(_comInst->CaptureWithContextAsync([context comObj].Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::AdvancedCapturedPhoto*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::AdvancedCapturedPhoto*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Capture::IAdvancedCapturedPhoto> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMCAdvancedCapturedPhoto>(result.Get()));
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

- (EventRegistrationToken)addOptionalReferencePhotoCapturedEvent:(void (^)(WMCAdvancedPhotoCapture*,
                                                                           WMCOptionalReferencePhotoCapturedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAdvancedPhotoCapture>(self);
    THROW_NS_IF_FAILED(_comInst->add_OptionalReferencePhotoCaptured(
        Make<ITypedEventHandler_Windows_Media_Capture_AdvancedPhotoCapture_Windows_Media_Capture_OptionalReferencePhotoCapturedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOptionalReferencePhotoCapturedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAdvancedPhotoCapture>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OptionalReferencePhotoCaptured(token));
}

- (EventRegistrationToken)addAllPhotosCapturedEvent:(void (^)(WMCAdvancedPhotoCapture*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAdvancedPhotoCapture>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_AllPhotosCaptured(Make<ITypedEventHandler_Windows_Media_Capture_AdvancedPhotoCapture_System_Object>(handler).Get(),
                                        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAllPhotosCapturedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAdvancedPhotoCapture>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AllPhotosCaptured(token));
}

- (RTObject<WFIAsyncAction>*)finishAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAdvancedPhotoCapture>(self);
    THROW_NS_IF_FAILED(_comInst->FinishAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WMCMediaCapturePauseResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IMediaCapturePauseResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMVideoFrame*)lastFrame {
    ComPtr<ABI::Windows::Media::IVideoFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapturePauseResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMVideoFrame>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)recordDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCapturePauseResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_RecordDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMCMediaCaptureStopResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IMediaCaptureStopResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMVideoFrame*)lastFrame {
    ComPtr<ABI::Windows::Media::IVideoFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureStopResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMVideoFrame>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)recordDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IMediaCaptureStopResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_RecordDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMCCapturedPhoto

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::ICapturedPhoto> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCCapturedFrame*)frame {
    ComPtr<ABI::Windows::Media::Capture::ICapturedFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedPhoto>(self);
    THROW_NS_IF_FAILED(_comInst->get_Frame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCapturedFrame>(unmarshalledReturn.Get());
}

- (WMCCapturedFrame*)thumbnail {
    ComPtr<ABI::Windows::Media::Capture::ICapturedFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedPhoto>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCapturedFrame>(unmarshalledReturn.Get());
}

@end

@implementation WMCAdvancedCapturedPhoto

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IAdvancedCapturedPhoto> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCCapturedFrame*)frame {
    ComPtr<ABI::Windows::Media::Capture::ICapturedFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAdvancedCapturedPhoto>(self);
    THROW_NS_IF_FAILED(_comInst->get_Frame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCapturedFrame>(unmarshalledReturn.Get());
}

- (WMDAdvancedPhotoMode)mode {
    ABI::Windows::Media::Devices::AdvancedPhotoMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAdvancedCapturedPhoto>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WMDAdvancedPhotoMode)unmarshalledReturn;
}

- (RTObject*)context {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAdvancedCapturedPhoto>(self);
    THROW_NS_IF_FAILED(_comInst->get_Context(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (id /* WFRect* */)frameBoundsRelativeToReferencePhoto {
    ComPtr<IReference<ABI::Windows::Foundation::Rect>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAdvancedCapturedPhoto2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameBoundsRelativeToReferencePhoto(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFRect, ABI::Windows::Foundation::Rect>::convert(unmarshalledReturn.Get());
}

@end

@implementation WMCOptionalReferencePhotoCapturedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IOptionalReferencePhotoCapturedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCCapturedFrame*)frame {
    ComPtr<ABI::Windows::Media::Capture::ICapturedFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IOptionalReferencePhotoCapturedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Frame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCapturedFrame>(unmarshalledReturn.Get());
}

- (RTObject*)context {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IOptionalReferencePhotoCapturedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Context(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WMCCapturedFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::ICapturedFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)width {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_Width(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)height {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)size {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSize:(uint64_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->put_Size(value));
}

- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->GetInputStreamAt(position, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->GetOutputStreamAt(position, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIOutputStream>(unmarshalledReturn.Get());
}

- (uint64_t)position {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)seek:(uint64_t)position {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->Seek(position));
}

- (RTObject<WSSIRandomAccessStream>*)cloneStream {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->CloneStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStream>(unmarshalledReturn.Get());
}

- (BOOL)canRead {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanRead(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canWrite {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanWrite(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned int)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, unsigned int>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IInputStream>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(),
                                           count,
                                           (ABI::Windows::Storage::Streams::InputStreamOptions)options,
                                           &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IBuffer*, unsigned int>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, unsigned int>* op,
                         unsigned int status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*, unsigned int>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, unsigned int>* op,
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

- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned int))success
          progress:(void (^)(unsigned int))progress
           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IOutputStream>(self);
    THROW_NS_IF_FAILED(_comInst->WriteAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<unsigned int, unsigned int>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>* op, unsigned int status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<unsigned int, unsigned int>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>* op, AsyncStatus status) {
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

- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IOutputStream>(self);
    THROW_NS_IF_FAILED(_comInst->FlushAsync(&unmarshalledReturn));

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

- (NSString*)contentType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IContentTypeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGISoftwareBitmap*)softwareBitmap {
    ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrameWithSoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->get_SoftwareBitmap(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGISoftwareBitmap>(unmarshalledReturn.Get());
}

@end

@implementation WMCPhotoCapturedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IPhotoCapturedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCCapturedFrame*)frame {
    ComPtr<ABI::Windows::Media::Capture::ICapturedFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IPhotoCapturedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Frame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCapturedFrame>(unmarshalledReturn.Get());
}

- (WMCCapturedFrame*)thumbnail {
    ComPtr<ABI::Windows::Media::Capture::ICapturedFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IPhotoCapturedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCapturedFrame>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)captureTimeOffset {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IPhotoCapturedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CaptureTimeOffset(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

@end

@implementation WMCCapturedFrameControlValues

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::ICapturedFrameControlValues> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* WFTimeSpan* */)exposure {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrameControlValues>(self);
    THROW_NS_IF_FAILED(_comInst->get_Exposure(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (id /* float */)exposureCompensation {
    ComPtr<IReference<float>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrameControlValues>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExposureCompensation(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<float, float>::convert(unmarshalledReturn.Get());
}

- (id /* unsigned int */)isoSpeed {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrameControlValues>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsoSpeed(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (id /* unsigned int */)focus {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrameControlValues>(self);
    THROW_NS_IF_FAILED(_comInst->get_Focus(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (id /* WMDCaptureSceneMode */)sceneMode {
    ComPtr<IReference<ABI::Windows::Media::Devices::CaptureSceneMode>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrameControlValues>(self);
    THROW_NS_IF_FAILED(_comInst->get_SceneMode(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WMDCaptureSceneMode, ABI::Windows::Media::Devices::CaptureSceneMode>::convert(unmarshalledReturn.Get());
}

- (id /* BOOL */)flashed {
    ComPtr<IReference<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrameControlValues>(self);
    THROW_NS_IF_FAILED(_comInst->get_Flashed(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<BOOL, ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>::convert(unmarshalledReturn.Get());
}

- (id /* float */)flashPowerPercent {
    ComPtr<IReference<float>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrameControlValues>(self);
    THROW_NS_IF_FAILED(_comInst->get_FlashPowerPercent(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<float, float>::convert(unmarshalledReturn.Get());
}

- (id /* unsigned int */)whiteBalance {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrameControlValues>(self);
    THROW_NS_IF_FAILED(_comInst->get_WhiteBalance(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (id /* float */)zoomFactor {
    ComPtr<IReference<float>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrameControlValues>(self);
    THROW_NS_IF_FAILED(_comInst->get_ZoomFactor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<float, float>::convert(unmarshalledReturn.Get());
}

- (id /* WMDMediaCaptureFocusState */)focusState {
    ComPtr<IReference<ABI::Windows::Media::Devices::MediaCaptureFocusState>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrameControlValues2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FocusState(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WMDMediaCaptureFocusState, ABI::Windows::Media::Devices::MediaCaptureFocusState>::convert(
        unmarshalledReturn.Get());
}

- (id /* double */)isoDigitalGain {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrameControlValues2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsoDigitalGain(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (id /* double */)isoAnalogGain {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrameControlValues2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsoAnalogGain(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (WMMMediaRatio*)sensorFrameRate {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaRatio> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrameControlValues2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SensorFrameRate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaRatio>(unmarshalledReturn.Get());
}

- (id /* WMCWhiteBalanceGain* */)whiteBalanceGain {
    ComPtr<IReference<ABI::Windows::Media::Capture::WhiteBalanceGain>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ICapturedFrameControlValues2>(self);
    THROW_NS_IF_FAILED(_comInst->get_WhiteBalanceGain(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WMCWhiteBalanceGain, ABI::Windows::Media::Capture::WhiteBalanceGain>::convert(unmarshalledReturn.Get());
}

@end

@implementation WMCVideoStreamConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IVideoStreamConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMMVideoEncodingProperties*)inputProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IVideoStreamConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMVideoEncodingProperties>(unmarshalledReturn.Get());
}

- (WMMVideoEncodingProperties*)outputProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IVideoStreamConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutputProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMVideoEncodingProperties>(unmarshalledReturn.Get());
}

@end

@implementation WMCAppCaptureSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IAppCaptureSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setAppCaptureDestinationFolder:(WSStorageFolder*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_AppCaptureDestinationFolder(_getRtInterface<ABI::Windows::Storage::IStorageFolder>(value).Get()));
}

- (WSStorageFolder*)appCaptureDestinationFolder {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppCaptureDestinationFolder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

- (void)setAudioEncodingBitrate:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_AudioEncodingBitrate(value));
}

- (unsigned int)audioEncodingBitrate {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioEncodingBitrate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIsAudioCaptureEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsAudioCaptureEnabled((boolean)value));
}

- (BOOL)isAudioCaptureEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAudioCaptureEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCustomVideoEncodingBitrate:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_CustomVideoEncodingBitrate(value));
}

- (unsigned int)customVideoEncodingBitrate {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomVideoEncodingBitrate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCustomVideoEncodingHeight:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_CustomVideoEncodingHeight(value));
}

- (unsigned int)customVideoEncodingHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomVideoEncodingHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCustomVideoEncodingWidth:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_CustomVideoEncodingWidth(value));
}

- (unsigned int)customVideoEncodingWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomVideoEncodingWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setHistoricalBufferLength:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_HistoricalBufferLength(value));
}

- (unsigned int)historicalBufferLength {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_HistoricalBufferLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setHistoricalBufferLengthUnit:(WMCAppCaptureHistoricalBufferLengthUnit)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_HistoricalBufferLengthUnit((ABI::Windows::Media::Capture::AppCaptureHistoricalBufferLengthUnit)value));
}

- (WMCAppCaptureHistoricalBufferLengthUnit)historicalBufferLengthUnit {
    ABI::Windows::Media::Capture::AppCaptureHistoricalBufferLengthUnit unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_HistoricalBufferLengthUnit(&unmarshalledReturn));
    return (WMCAppCaptureHistoricalBufferLengthUnit)unmarshalledReturn;
}

- (void)setIsHistoricalCaptureEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsHistoricalCaptureEnabled((boolean)value));
}

- (BOOL)isHistoricalCaptureEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsHistoricalCaptureEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsHistoricalCaptureOnBatteryAllowed:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsHistoricalCaptureOnBatteryAllowed((boolean)value));
}

- (BOOL)isHistoricalCaptureOnBatteryAllowed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsHistoricalCaptureOnBatteryAllowed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsHistoricalCaptureOnWirelessDisplayAllowed:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsHistoricalCaptureOnWirelessDisplayAllowed((boolean)value));
}

- (BOOL)isHistoricalCaptureOnWirelessDisplayAllowed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsHistoricalCaptureOnWirelessDisplayAllowed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setMaximumRecordLength:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaximumRecordLength(*[value internalStruct]));
}

- (WFTimeSpan*)maximumRecordLength {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaximumRecordLength(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setScreenshotDestinationFolder:(WSStorageFolder*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScreenshotDestinationFolder(_getRtInterface<ABI::Windows::Storage::IStorageFolder>(value).Get()));
}

- (WSStorageFolder*)screenshotDestinationFolder {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScreenshotDestinationFolder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

- (void)setVideoEncodingBitrateMode:(WMCAppCaptureVideoEncodingBitrateMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_VideoEncodingBitrateMode((ABI::Windows::Media::Capture::AppCaptureVideoEncodingBitrateMode)value));
}

- (WMCAppCaptureVideoEncodingBitrateMode)videoEncodingBitrateMode {
    ABI::Windows::Media::Capture::AppCaptureVideoEncodingBitrateMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoEncodingBitrateMode(&unmarshalledReturn));
    return (WMCAppCaptureVideoEncodingBitrateMode)unmarshalledReturn;
}

- (void)setVideoEncodingResolutionMode:(WMCAppCaptureVideoEncodingResolutionMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_VideoEncodingResolutionMode((ABI::Windows::Media::Capture::AppCaptureVideoEncodingResolutionMode)value));
}

- (WMCAppCaptureVideoEncodingResolutionMode)videoEncodingResolutionMode {
    ABI::Windows::Media::Capture::AppCaptureVideoEncodingResolutionMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoEncodingResolutionMode(&unmarshalledReturn));
    return (WMCAppCaptureVideoEncodingResolutionMode)unmarshalledReturn;
}

- (void)setIsAppCaptureEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsAppCaptureEnabled((boolean)value));
}

- (BOOL)isAppCaptureEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAppCaptureEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCpuConstrained {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCpuConstrained(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDisabledByPolicy {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDisabledByPolicy(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isMemoryConstrained {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsMemoryConstrained(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)hasHardwareEncoder {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasHardwareEncoder(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isGpuConstrained {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsGpuConstrained(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WMCAppCaptureAlternateShortcutKeys*)alternateShortcutKeys {
    ComPtr<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlternateShortcutKeys(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCAppCaptureAlternateShortcutKeys>(unmarshalledReturn.Get());
}

- (void)setIsMicrophoneCaptureEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings3>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsMicrophoneCaptureEnabled((boolean)value));
}

- (BOOL)isMicrophoneCaptureEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings3>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsMicrophoneCaptureEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsMicrophoneCaptureEnabledByDefault:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings4>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsMicrophoneCaptureEnabledByDefault((boolean)value));
}

- (BOOL)isMicrophoneCaptureEnabledByDefault {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings4>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsMicrophoneCaptureEnabledByDefault(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSystemAudioGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings4>(self);
    THROW_NS_IF_FAILED(_comInst->put_SystemAudioGain(value));
}

- (double)systemAudioGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings4>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemAudioGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMicrophoneGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings4>(self);
    THROW_NS_IF_FAILED(_comInst->put_MicrophoneGain(value));
}

- (double)microphoneGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings4>(self);
    THROW_NS_IF_FAILED(_comInst->get_MicrophoneGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setVideoEncodingFrameRateMode:(WMCAppCaptureVideoEncodingFrameRateMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings4>(self);
    THROW_NS_IF_FAILED(_comInst->put_VideoEncodingFrameRateMode((ABI::Windows::Media::Capture::AppCaptureVideoEncodingFrameRateMode)value));
}

- (WMCAppCaptureVideoEncodingFrameRateMode)videoEncodingFrameRateMode {
    ABI::Windows::Media::Capture::AppCaptureVideoEncodingFrameRateMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureSettings4>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoEncodingFrameRateMode(&unmarshalledReturn));
    return (WMCAppCaptureVideoEncodingFrameRateMode)unmarshalledReturn;
}

@end

@implementation WMCAppCaptureAlternateShortcutKeys

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setToggleGameBarKey:(WSVirtualKey)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->put_ToggleGameBarKey((ABI::Windows::System::VirtualKey)value));
}

- (WSVirtualKey)toggleGameBarKey {
    ABI::Windows::System::VirtualKey unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleGameBarKey(&unmarshalledReturn));
    return (WSVirtualKey)unmarshalledReturn;
}

- (void)setToggleGameBarKeyModifiers:(WSVirtualKeyModifiers)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->put_ToggleGameBarKeyModifiers((ABI::Windows::System::VirtualKeyModifiers)value));
}

- (WSVirtualKeyModifiers)toggleGameBarKeyModifiers {
    ABI::Windows::System::VirtualKeyModifiers unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleGameBarKeyModifiers(&unmarshalledReturn));
    return (WSVirtualKeyModifiers)unmarshalledReturn;
}

- (void)setSaveHistoricalVideoKey:(WSVirtualKey)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->put_SaveHistoricalVideoKey((ABI::Windows::System::VirtualKey)value));
}

- (WSVirtualKey)saveHistoricalVideoKey {
    ABI::Windows::System::VirtualKey unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->get_SaveHistoricalVideoKey(&unmarshalledReturn));
    return (WSVirtualKey)unmarshalledReturn;
}

- (void)setSaveHistoricalVideoKeyModifiers:(WSVirtualKeyModifiers)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->put_SaveHistoricalVideoKeyModifiers((ABI::Windows::System::VirtualKeyModifiers)value));
}

- (WSVirtualKeyModifiers)saveHistoricalVideoKeyModifiers {
    ABI::Windows::System::VirtualKeyModifiers unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->get_SaveHistoricalVideoKeyModifiers(&unmarshalledReturn));
    return (WSVirtualKeyModifiers)unmarshalledReturn;
}

- (void)setToggleRecordingKey:(WSVirtualKey)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->put_ToggleRecordingKey((ABI::Windows::System::VirtualKey)value));
}

- (WSVirtualKey)toggleRecordingKey {
    ABI::Windows::System::VirtualKey unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleRecordingKey(&unmarshalledReturn));
    return (WSVirtualKey)unmarshalledReturn;
}

- (void)setToggleRecordingKeyModifiers:(WSVirtualKeyModifiers)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->put_ToggleRecordingKeyModifiers((ABI::Windows::System::VirtualKeyModifiers)value));
}

- (WSVirtualKeyModifiers)toggleRecordingKeyModifiers {
    ABI::Windows::System::VirtualKeyModifiers unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleRecordingKeyModifiers(&unmarshalledReturn));
    return (WSVirtualKeyModifiers)unmarshalledReturn;
}

- (void)setTakeScreenshotKey:(WSVirtualKey)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->put_TakeScreenshotKey((ABI::Windows::System::VirtualKey)value));
}

- (WSVirtualKey)takeScreenshotKey {
    ABI::Windows::System::VirtualKey unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->get_TakeScreenshotKey(&unmarshalledReturn));
    return (WSVirtualKey)unmarshalledReturn;
}

- (void)setTakeScreenshotKeyModifiers:(WSVirtualKeyModifiers)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->put_TakeScreenshotKeyModifiers((ABI::Windows::System::VirtualKeyModifiers)value));
}

- (WSVirtualKeyModifiers)takeScreenshotKeyModifiers {
    ABI::Windows::System::VirtualKeyModifiers unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->get_TakeScreenshotKeyModifiers(&unmarshalledReturn));
    return (WSVirtualKeyModifiers)unmarshalledReturn;
}

- (void)setToggleRecordingIndicatorKey:(WSVirtualKey)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->put_ToggleRecordingIndicatorKey((ABI::Windows::System::VirtualKey)value));
}

- (WSVirtualKey)toggleRecordingIndicatorKey {
    ABI::Windows::System::VirtualKey unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleRecordingIndicatorKey(&unmarshalledReturn));
    return (WSVirtualKey)unmarshalledReturn;
}

- (void)setToggleRecordingIndicatorKeyModifiers:(WSVirtualKeyModifiers)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->put_ToggleRecordingIndicatorKeyModifiers((ABI::Windows::System::VirtualKeyModifiers)value));
}

- (WSVirtualKeyModifiers)toggleRecordingIndicatorKeyModifiers {
    ABI::Windows::System::VirtualKeyModifiers unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleRecordingIndicatorKeyModifiers(&unmarshalledReturn));
    return (WSVirtualKeyModifiers)unmarshalledReturn;
}

- (void)setToggleMicrophoneCaptureKey:(WSVirtualKey)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ToggleMicrophoneCaptureKey((ABI::Windows::System::VirtualKey)value));
}

- (WSVirtualKey)toggleMicrophoneCaptureKey {
    ABI::Windows::System::VirtualKey unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleMicrophoneCaptureKey(&unmarshalledReturn));
    return (WSVirtualKey)unmarshalledReturn;
}

- (void)setToggleMicrophoneCaptureKeyModifiers:(WSVirtualKeyModifiers)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ToggleMicrophoneCaptureKeyModifiers((ABI::Windows::System::VirtualKeyModifiers)value));
}

- (WSVirtualKeyModifiers)toggleMicrophoneCaptureKeyModifiers {
    ABI::Windows::System::VirtualKeyModifiers unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleMicrophoneCaptureKeyModifiers(&unmarshalledReturn));
    return (WSVirtualKeyModifiers)unmarshalledReturn;
}

- (void)setToggleCameraCaptureKey:(WSVirtualKey)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys3>(self);
    THROW_NS_IF_FAILED(_comInst->put_ToggleCameraCaptureKey((ABI::Windows::System::VirtualKey)value));
}

- (WSVirtualKey)toggleCameraCaptureKey {
    ABI::Windows::System::VirtualKey unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys3>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleCameraCaptureKey(&unmarshalledReturn));
    return (WSVirtualKey)unmarshalledReturn;
}

- (void)setToggleCameraCaptureKeyModifiers:(WSVirtualKeyModifiers)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys3>(self);
    THROW_NS_IF_FAILED(_comInst->put_ToggleCameraCaptureKeyModifiers((ABI::Windows::System::VirtualKeyModifiers)value));
}

- (WSVirtualKeyModifiers)toggleCameraCaptureKeyModifiers {
    ABI::Windows::System::VirtualKeyModifiers unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys3>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleCameraCaptureKeyModifiers(&unmarshalledReturn));
    return (WSVirtualKeyModifiers)unmarshalledReturn;
}

- (void)setToggleBroadcastKey:(WSVirtualKey)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys3>(self);
    THROW_NS_IF_FAILED(_comInst->put_ToggleBroadcastKey((ABI::Windows::System::VirtualKey)value));
}

- (WSVirtualKey)toggleBroadcastKey {
    ABI::Windows::System::VirtualKey unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys3>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleBroadcastKey(&unmarshalledReturn));
    return (WSVirtualKey)unmarshalledReturn;
}

- (void)setToggleBroadcastKeyModifiers:(WSVirtualKeyModifiers)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys3>(self);
    THROW_NS_IF_FAILED(_comInst->put_ToggleBroadcastKeyModifiers((ABI::Windows::System::VirtualKeyModifiers)value));
}

- (WSVirtualKeyModifiers)toggleBroadcastKeyModifiers {
    ABI::Windows::System::VirtualKeyModifiers unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys3>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleBroadcastKeyModifiers(&unmarshalledReturn));
    return (WSVirtualKeyModifiers)unmarshalledReturn;
}

@end

@implementation WMCAppCaptureManager

ComPtr<ABI::Windows::Media::Capture::IAppCaptureManagerStatics> WMCIAppCaptureManagerStatics_inst() {
    ComPtr<ABI::Windows::Media::Capture::IAppCaptureManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Capture.AppCaptureManager").Get(), &inst));
    return inst;
}

+ (WMCAppCaptureSettings*)getCurrentSettings {
    ComPtr<ABI::Windows::Media::Capture::IAppCaptureSettings> unmarshalledReturn;
    auto _comInst = WMCIAppCaptureManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetCurrentSettings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCAppCaptureSettings>(unmarshalledReturn.Get());
}

+ (void)applySettings:(WMCAppCaptureSettings*)appCaptureSettings {
    auto _comInst = WMCIAppCaptureManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->ApplySettings(_getRtInterface<ABI::Windows::Media::Capture::IAppCaptureSettings>(appCaptureSettings).Get()));
}

@end

@implementation WMCCameraOptionsUI

ComPtr<ABI::Windows::Media::Capture::ICameraOptionsUIStatics> WMCICameraOptionsUIStatics_inst() {
    ComPtr<ABI::Windows::Media::Capture::ICameraOptionsUIStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Capture.CameraOptionsUI").Get(), &inst));
    return inst;
}

+ (void)show:(WMCMediaCapture*)mediaCapture {
    auto _comInst = WMCICameraOptionsUIStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Show(_getRtInterface<ABI::Windows::Media::Capture::IMediaCapture>(mediaCapture).Get()));
}

@end

@implementation WMCScreenCapture

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::IScreenCapture> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::Capture::IScreenCaptureStatics> WMCIScreenCaptureStatics_inst() {
    ComPtr<ABI::Windows::Media::Capture::IScreenCaptureStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Capture.ScreenCapture").Get(), &inst));
    return inst;
}

+ (WMCScreenCapture*)getForCurrentView {
    ComPtr<ABI::Windows::Media::Capture::IScreenCapture> unmarshalledReturn;
    auto _comInst = WMCIScreenCaptureStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCScreenCapture>(unmarshalledReturn.Get());
}

- (RTObject<WMCIMediaSource>*)audioSource {
    ComPtr<ABI::Windows::Media::Core::IMediaSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IScreenCapture>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCIMediaSource>(unmarshalledReturn.Get());
}

- (RTObject<WMCIMediaSource>*)videoSource {
    ComPtr<ABI::Windows::Media::Core::IMediaSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IScreenCapture>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCIMediaSource>(unmarshalledReturn.Get());
}

- (BOOL)isAudioSuspended {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IScreenCapture>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAudioSuspended(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isVideoSuspended {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IScreenCapture>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsVideoSuspended(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addSourceSuspensionChangedEvent:(void (^)(WMCScreenCapture*, WMCSourceSuspensionChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IScreenCapture>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourceSuspensionChanged(
        Make<ITypedEventHandler_Windows_Media_Capture_ScreenCapture_Windows_Media_Capture_SourceSuspensionChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceSuspensionChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::IScreenCapture>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceSuspensionChanged(token));
}

@end

@implementation WMCSourceSuspensionChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::ISourceSuspensionChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isAudioSuspended {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ISourceSuspensionChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAudioSuspended(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isVideoSuspended {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::ISourceSuspensionChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsVideoSuspended(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMCWhiteBalanceGain {
    ABI::Windows::Media::Capture::WhiteBalanceGain structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Media::Capture::WhiteBalanceGain)s {
    WMCWhiteBalanceGain* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Media::Capture::WhiteBalanceGain*)internalStruct {
    return &structVal;
}
- (double)r {
    return structVal.R;
}
- (void)setR:(double)val {
    structVal.R = val;
}
- (double)g {
    return structVal.G;
}
- (void)setG:(double)val {
    structVal.G = val;
}
- (double)b {
    return structVal.B;
}
- (void)setB:(double)val {
    structVal.B = val;
}
@end
id RTProxiedNSArray_WMCMediaCaptureVideoProfile_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Capture::MediaCaptureVideoProfile*>,
                                         RTArrayObj<ABI::Windows::Media::Capture::IMediaCaptureVideoProfile*,
                                                    IVectorView<ABI::Windows::Media::Capture::MediaCaptureVideoProfile*>,
                                                    WMCMediaCaptureVideoProfile,
                                                    ABI::Windows::Media::Capture::MediaCaptureVideoProfile*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMCMediaCaptureVideoProfileMediaDescription_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription*>,
                                         RTArrayObj<ABI::Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription*,
                                                    IVectorView<ABI::Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription*>,
                                                    WMCMediaCaptureVideoProfileMediaDescription,
                                                    ABI::Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_WMCFMediaFrameSource_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<DictionaryAdapterObj<
        IMapView<HSTRING, ABI::Windows::Media::Capture::Frames::MediaFrameSource*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::Media::Capture::Frames::MediaFrameSource*>>,
        RTMapViewObj<HSTRING,
                     HSTRING,
                     ABI::Windows::Media::Capture::Frames::MediaFrameSource*,
                     ABI::Windows::Media::Capture::Frames::IMediaFrameSource*,
                     NSString,
                     WMCFMediaFrameSource,
                     IMapView<HSTRING, ABI::Windows::Media::Capture::Frames::MediaFrameSource*>,
                     dummyObjCCreator,
                     dummyObjCCreator,
                     dummyWRLCreator,
                     dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
