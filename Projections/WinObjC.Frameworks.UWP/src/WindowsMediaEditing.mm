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

// WindowsMediaEditing.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Editing.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaEditing.h"
#include "WindowsMediaEditing_priv.h"

@implementation WMEMediaOverlay

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Editing::IMediaOverlay> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Editing::IMediaOverlayFactory> WMEIMediaOverlayFactory_inst() {
    ComPtr<ABI::Windows::Media::Editing::IMediaOverlayFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Editing.MediaOverlay").Get(), &inst));
    return inst;
}

+ (WMEMediaOverlay*)make:(WMEMediaClip*)clip {
    ComPtr<ABI::Windows::Media::Editing::IMediaOverlay> unmarshalledReturn;
    auto _comInst = WMEIMediaOverlayFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Media::Editing::IMediaClip>(clip).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMEMediaOverlay>(unmarshalledReturn.Get()) retain];
}

+ (WMEMediaOverlay*)makeWithPositionAndOpacity:(WMEMediaClip*)clip position:(WFRect*)position opacity:(double)opacity {
    ComPtr<ABI::Windows::Media::Editing::IMediaOverlay> unmarshalledReturn;
    auto _comInst = WMEIMediaOverlayFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithPositionAndOpacity(_getRtInterface<ABI::Windows::Media::Editing::IMediaClip>(clip).Get(),
                                                              *[position internalStruct],
                                                              opacity,
                                                              unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMEMediaOverlay>(unmarshalledReturn.Get()) retain];
}

- (WFRect*)position {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaOverlay>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)setPosition:(WFRect*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaOverlay>(self);
    THROW_NS_IF_FAILED(_comInst->put_Position(*[value internalStruct]));
}

- (void)setDelay:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaOverlay>(self);
    THROW_NS_IF_FAILED(_comInst->put_Delay(*[value internalStruct]));
}

- (WFTimeSpan*)delay {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaOverlay>(self);
    THROW_NS_IF_FAILED(_comInst->get_Delay(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (double)opacity {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaOverlay>(self);
    THROW_NS_IF_FAILED(_comInst->get_Opacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOpacity:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaOverlay>(self);
    THROW_NS_IF_FAILED(_comInst->put_Opacity(value));
}

- (WMEMediaOverlay*)clone {
    ComPtr<ABI::Windows::Media::Editing::IMediaOverlay> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaOverlay>(self);
    THROW_NS_IF_FAILED(_comInst->Clone(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMEMediaOverlay>(unmarshalledReturn.Get());
}

- (WMEMediaClip*)clip {
    ComPtr<ABI::Windows::Media::Editing::IMediaClip> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaOverlay>(self);
    THROW_NS_IF_FAILED(_comInst->get_Clip(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMEMediaClip>(unmarshalledReturn.Get());
}

- (BOOL)audioEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaOverlay>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAudioEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaOverlay>(self);
    THROW_NS_IF_FAILED(_comInst->put_AudioEnabled((boolean)value));
}

@end

@implementation WMEMediaClip

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Editing::IMediaClip> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::Editing::IMediaClipStatics> WMEIMediaClipStatics_inst() {
    ComPtr<ABI::Windows::Media::Editing::IMediaClipStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Editing.MediaClip").Get(), &inst));
    return inst;
}

+ (WMEMediaClip*)createFromColor:(WUColor*)color originalDuration:(WFTimeSpan*)originalDuration {
    ComPtr<ABI::Windows::Media::Editing::IMediaClip> unmarshalledReturn;
    auto _comInst = WMEIMediaClipStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromColor(*[color internalStruct], *[originalDuration internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMEMediaClip>(unmarshalledReturn.Get());
}

+ (void)createFromFileAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(WMEMediaClip*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Editing::MediaClip*>> unmarshalledReturn;
    auto _comInst = WMEIMediaClipStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromFileAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Editing::MediaClip*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Editing::MediaClip*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Editing::IMediaClip> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMEMediaClip>(result.Get()));
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

+ (void)createFromImageFileAsync:(RTObject<WSIStorageFile>*)file
                originalDuration:(WFTimeSpan*)originalDuration
                         success:(void (^)(WMEMediaClip*))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Editing::MediaClip*>> unmarshalledReturn;
    auto _comInst = WMEIMediaClipStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromImageFileAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                          *[originalDuration internalStruct],
                                                          &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Editing::MediaClip*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Editing::MediaClip*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Editing::IMediaClip> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMEMediaClip>(result.Get()));
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

ComPtr<ABI::Windows::Media::Editing::IMediaClipStatics2> WMEIMediaClipStatics2_inst() {
    ComPtr<ABI::Windows::Media::Editing::IMediaClipStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Editing.MediaClip").Get(), &inst));
    return inst;
}

+ (WMEMediaClip*)createFromSurface:(RTObject<WGDDIDirect3DSurface>*)surface originalDuration:(WFTimeSpan*)originalDuration {
    ComPtr<ABI::Windows::Media::Editing::IMediaClip> unmarshalledReturn;
    auto _comInst = WMEIMediaClipStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromSurface(_getRtInterface<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface>(surface).Get(),
                                    *[originalDuration internalStruct],
                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMEMediaClip>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)trimTimeFromStart {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrimTimeFromStart(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setTrimTimeFromStart:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->put_TrimTimeFromStart(*[value internalStruct]));
}

- (WFTimeSpan*)trimTimeFromEnd {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrimTimeFromEnd(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setTrimTimeFromEnd:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->put_TrimTimeFromEnd(*[value internalStruct]));
}

- (WFTimeSpan*)originalDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->get_OriginalDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)trimmedDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrimmedDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (NSMutableDictionary* /* NSString *, NSString * */)userData {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserData(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

- (WMEMediaClip*)clone {
    ComPtr<ABI::Windows::Media::Editing::IMediaClip> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->Clone(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMEMediaClip>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)startTimeInComposition {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTimeInComposition(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)endTimeInComposition {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndTimeInComposition(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (NSArray* /* WMEEmbeddedAudioTrack* */)embeddedAudioTracks {
    ComPtr<IVectorView<ABI::Windows::Media::Editing::EmbeddedAudioTrack*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmbeddedAudioTracks(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMEEmbeddedAudioTrack_create(unmarshalledReturn.Get());
}

- (unsigned int)selectedEmbeddedAudioTrackIndex {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedEmbeddedAudioTrackIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSelectedEmbeddedAudioTrackIndex:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedEmbeddedAudioTrackIndex(value));
}

- (void)setVolume:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->put_Volume(value));
}

- (double)volume {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->get_Volume(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMVideoEncodingProperties*)getVideoEncodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->GetVideoEncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMVideoEncodingProperties>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */)audioEffectDefinitions {
    ComPtr<IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioEffectDefinitions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* RTObject<WMEIVideoEffectDefinition>* */)videoEffectDefinitions {
    ComPtr<IVector<ABI::Windows::Media::Effects::IVideoEffectDefinition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaClip>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoEffectDefinitions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WMEIVideoEffectDefinition_create(unmarshalledReturn.Get());
}

@end

@implementation WMEEmbeddedAudioTrack

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Editing::IEmbeddedAudioTrack> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMMAudioEncodingProperties*)getAudioEncodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IEmbeddedAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->GetAudioEncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

@end

@implementation WMEBackgroundAudioTrack

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Editing::IBackgroundAudioTrack> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::Editing::IBackgroundAudioTrackStatics> WMEIBackgroundAudioTrackStatics_inst() {
    ComPtr<ABI::Windows::Media::Editing::IBackgroundAudioTrackStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Editing.BackgroundAudioTrack").Get(), &inst));
    return inst;
}

+ (WMEBackgroundAudioTrack*)createFromEmbeddedAudioTrack:(WMEEmbeddedAudioTrack*)embeddedAudioTrack {
    ComPtr<ABI::Windows::Media::Editing::IBackgroundAudioTrack> unmarshalledReturn;
    auto _comInst = WMEIBackgroundAudioTrackStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromEmbeddedAudioTrack(_getRtInterface<ABI::Windows::Media::Editing::IEmbeddedAudioTrack>(embeddedAudioTrack).Get(),
                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMEBackgroundAudioTrack>(unmarshalledReturn.Get());
}

+ (void)createFromFileAsync:(RTObject<WSIStorageFile>*)file
                    success:(void (^)(WMEBackgroundAudioTrack*))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Editing::BackgroundAudioTrack*>> unmarshalledReturn;
    auto _comInst = WMEIBackgroundAudioTrackStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromFileAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Editing::BackgroundAudioTrack*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Editing::BackgroundAudioTrack*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Editing::IBackgroundAudioTrack> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMEBackgroundAudioTrack>(result.Get()));
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

- (WFTimeSpan*)trimTimeFromStart {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IBackgroundAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrimTimeFromStart(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setTrimTimeFromStart:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IBackgroundAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->put_TrimTimeFromStart(*[value internalStruct]));
}

- (WFTimeSpan*)trimTimeFromEnd {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IBackgroundAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrimTimeFromEnd(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setTrimTimeFromEnd:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IBackgroundAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->put_TrimTimeFromEnd(*[value internalStruct]));
}

- (WFTimeSpan*)originalDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IBackgroundAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_OriginalDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)trimmedDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IBackgroundAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrimmedDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (NSMutableDictionary* /* NSString *, NSString * */)userData {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IBackgroundAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserData(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

- (void)setDelay:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IBackgroundAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->put_Delay(*[value internalStruct]));
}

- (WFTimeSpan*)delay {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IBackgroundAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Delay(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setVolume:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IBackgroundAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->put_Volume(value));
}

- (double)volume {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IBackgroundAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Volume(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMEBackgroundAudioTrack*)clone {
    ComPtr<ABI::Windows::Media::Editing::IBackgroundAudioTrack> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IBackgroundAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->Clone(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMEBackgroundAudioTrack>(unmarshalledReturn.Get());
}

- (WMMAudioEncodingProperties*)getAudioEncodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IBackgroundAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->GetAudioEncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */)audioEffectDefinitions {
    ComPtr<IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IBackgroundAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioEffectDefinitions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(unmarshalledReturn.Get());
}

@end

@implementation WMEMediaComposition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Editing::IMediaComposition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Editing.MediaComposition").Get(), &out));
    return [_createRtProxy<WMEMediaComposition>(out.Get()) retain];
}

ComPtr<ABI::Windows::Media::Editing::IMediaCompositionStatics> WMEIMediaCompositionStatics_inst() {
    ComPtr<ABI::Windows::Media::Editing::IMediaCompositionStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Editing.MediaComposition").Get(), &inst));
    return inst;
}

+ (void)loadAsync:(WSStorageFile*)file success:(void (^)(WMEMediaComposition*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Editing::MediaComposition*>> unmarshalledReturn;
    auto _comInst = WMEIMediaCompositionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LoadAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Editing::MediaComposition*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Editing::MediaComposition*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Editing::IMediaComposition> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMEMediaComposition>(result.Get()));
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

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaComposition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (NSMutableArray* /* WMEMediaClip* */)clips {
    ComPtr<IVector<ABI::Windows::Media::Editing::MediaClip*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaComposition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Clips(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WMEMediaClip_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WMEBackgroundAudioTrack* */)backgroundAudioTracks {
    ComPtr<IVector<ABI::Windows::Media::Editing::BackgroundAudioTrack*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaComposition>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackgroundAudioTracks(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WMEBackgroundAudioTrack_create(unmarshalledReturn.Get());
}

- (NSMutableDictionary* /* NSString *, NSString * */)userData {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaComposition>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserData(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

- (WMEMediaComposition*)clone {
    ComPtr<ABI::Windows::Media::Editing::IMediaComposition> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaComposition>(self);
    THROW_NS_IF_FAILED(_comInst->Clone(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMEMediaComposition>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)saveAsync:(RTObject<WSIStorageFile>*)file {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaComposition>(self);
    THROW_NS_IF_FAILED(
        _comInst->SaveAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)getThumbnailAsync:(WFTimeSpan*)timeFromStart
              scaledWidth:(int)scaledWidth
             scaledHeight:(int)scaledHeight
           framePrecision:(WMEVideoFramePrecision)framePrecision
                  success:(void (^)(WGIImageStream*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::ImageStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaComposition>(self);
    THROW_NS_IF_FAILED(_comInst->GetThumbnailAsync(*[timeFromStart internalStruct],
                                                   scaledWidth,
                                                   scaledHeight,
                                                   (ABI::Windows::Media::Editing::VideoFramePrecision)framePrecision,
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::ImageStream*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::ImageStream*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIImageStream>(result.Get()));
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

- (void)getThumbnailsAsync:(id<NSFastEnumeration> /* WFTimeSpan* */)timesFromStart
               scaledWidth:(int)scaledWidth
              scaledHeight:(int)scaledHeight
            framePrecision:(WMEVideoFramePrecision)framePrecision
                   success:(void (^)(NSArray* /* WGIImageStream* */))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Graphics::Imaging::ImageStream*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaComposition>(self);
    THROW_NS_IF_FAILED(_comInst->GetThumbnailsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::TimeSpan>::type>*>(
            ConvertToIterable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>(timesFromStart).Get()),
        scaledWidth,
        scaledHeight,
        (ABI::Windows::Media::Editing::VideoFramePrecision)framePrecision,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Graphics::Imaging::ImageStream*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Graphics::Imaging::ImageStream*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Graphics::Imaging::ImageStream*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WGIImageStream_create(result.Get()));
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

- (void)renderToFileAsync:(RTObject<WSIStorageFile>*)destination
                  success:(void (^)(WMTTranscodeFailureReason))success
                 progress:(void (^)(double))progress
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Transcoding::TranscodeFailureReason, double>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaComposition>(self);
    THROW_NS_IF_FAILED(
        _comInst->RenderToFileAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(destination).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Media::Transcoding::TranscodeFailureReason, double>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Transcoding::TranscodeFailureReason, double>* op,
            double status) {
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
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Media::Transcoding::TranscodeFailureReason,
                                                                              double>>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Transcoding::TranscodeFailureReason, double>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Media::Transcoding::TranscodeFailureReason result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WMTTranscodeFailureReason)result);
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

- (void)renderToFileWithTrimmingPreferenceAsync:(RTObject<WSIStorageFile>*)destination
                             trimmingPreference:(WMEMediaTrimmingPreference)trimmingPreference
                                        success:(void (^)(WMTTranscodeFailureReason))success
                                       progress:(void (^)(double))progress
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Transcoding::TranscodeFailureReason, double>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaComposition>(self);
    THROW_NS_IF_FAILED(
        _comInst->RenderToFileWithTrimmingPreferenceAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(destination).Get(),
                                                          (ABI::Windows::Media::Editing::MediaTrimmingPreference)trimmingPreference,
                                                          &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Media::Transcoding::TranscodeFailureReason, double>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Transcoding::TranscodeFailureReason, double>* op,
            double status) {
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
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Media::Transcoding::TranscodeFailureReason,
                                                                              double>>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Transcoding::TranscodeFailureReason, double>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Media::Transcoding::TranscodeFailureReason result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WMTTranscodeFailureReason)result);
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

- (void)renderToFileWithProfileAsync:(RTObject<WSIStorageFile>*)destination
                  trimmingPreference:(WMEMediaTrimmingPreference)trimmingPreference
                     encodingProfile:(WMMMediaEncodingProfile*)encodingProfile
                             success:(void (^)(WMTTranscodeFailureReason))success
                            progress:(void (^)(double))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Transcoding::TranscodeFailureReason, double>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaComposition>(self);
    THROW_NS_IF_FAILED(_comInst->RenderToFileWithProfileAsync(
        _getRtInterface<ABI::Windows::Storage::IStorageFile>(destination).Get(),
        (ABI::Windows::Media::Editing::MediaTrimmingPreference)trimmingPreference,
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(encodingProfile).Get(),
        &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Media::Transcoding::TranscodeFailureReason, double>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Transcoding::TranscodeFailureReason, double>* op,
            double status) {
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
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Media::Transcoding::TranscodeFailureReason,
                                                                              double>>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Transcoding::TranscodeFailureReason, double>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Media::Transcoding::TranscodeFailureReason result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WMTTranscodeFailureReason)result);
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

- (WMMMediaEncodingProfile*)createDefaultEncodingProfile {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaComposition>(self);
    THROW_NS_IF_FAILED(_comInst->CreateDefaultEncodingProfile(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaEncodingProfile>(unmarshalledReturn.Get());
}

- (WMCMediaStreamSource*)generateMediaStreamSource {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaComposition>(self);
    THROW_NS_IF_FAILED(_comInst->GenerateMediaStreamSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaStreamSource>(unmarshalledReturn.Get());
}

- (WMCMediaStreamSource*)generateMediaStreamSourceWithProfile:(WMMMediaEncodingProfile*)encodingProfile {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaComposition>(self);
    THROW_NS_IF_FAILED(_comInst->GenerateMediaStreamSourceWithProfile(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(encodingProfile).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaStreamSource>(unmarshalledReturn.Get());
}

- (WMCMediaStreamSource*)generatePreviewMediaStreamSource:(int)scaledWidth scaledHeight:(int)scaledHeight {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaComposition>(self);
    THROW_NS_IF_FAILED(_comInst->GeneratePreviewMediaStreamSource(scaledWidth, scaledHeight, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaStreamSource>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WMEMediaOverlayLayer* */)overlayLayers {
    ComPtr<IVector<ABI::Windows::Media::Editing::MediaOverlayLayer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaComposition2>(self);
    THROW_NS_IF_FAILED(_comInst->get_OverlayLayers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WMEMediaOverlayLayer_create(unmarshalledReturn.Get());
}

@end

@implementation WMEMediaOverlayLayer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Editing::IMediaOverlayLayer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Editing::IMediaOverlayLayerFactory> WMEIMediaOverlayLayerFactory_inst() {
    ComPtr<ABI::Windows::Media::Editing::IMediaOverlayLayerFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Editing.MediaOverlayLayer").Get(), &inst));
    return inst;
}

+ (WMEMediaOverlayLayer*)makeWithCompositorDefinition:(RTObject<WMEIVideoCompositorDefinition>*)compositorDefinition {
    ComPtr<ABI::Windows::Media::Editing::IMediaOverlayLayer> unmarshalledReturn;
    auto _comInst = WMEIMediaOverlayLayerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithCompositorDefinition(
        _getRtInterface<ABI::Windows::Media::Effects::IVideoCompositorDefinition>(compositorDefinition).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMEMediaOverlayLayer>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Editing.MediaOverlayLayer").Get(), &out));
    return [_createRtProxy<WMEMediaOverlayLayer>(out.Get()) retain];
}

- (WMEMediaOverlayLayer*)clone {
    ComPtr<ABI::Windows::Media::Editing::IMediaOverlayLayer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaOverlayLayer>(self);
    THROW_NS_IF_FAILED(_comInst->Clone(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMEMediaOverlayLayer>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WMEMediaOverlay* */)overlays {
    ComPtr<IVector<ABI::Windows::Media::Editing::MediaOverlay*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaOverlayLayer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Overlays(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WMEMediaOverlay_create(unmarshalledReturn.Get());
}

- (RTObject<WMEIVideoCompositorDefinition>*)customCompositorDefinition {
    ComPtr<ABI::Windows::Media::Effects::IVideoCompositorDefinition> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Editing::IMediaOverlayLayer>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomCompositorDefinition(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMEIVideoCompositorDefinition>(unmarshalledReturn.Get());
}

@end

id RTProxiedIterableNSArray_WFTimeSpan_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Foundation::TimeSpan>,
                                                 RTIterableObj<ABI::Windows::Foundation::TimeSpan,
                                                               IIterable<ABI::Windows::Foundation::TimeSpan>,
                                                               WFTimeSpan,
                                                               ABI::Windows::Foundation::TimeSpan,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WGIImageStream_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Graphics::Imaging::ImageStream*>,
                                         RTArrayObj<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*,
                                                    IVectorView<ABI::Windows::Graphics::Imaging::ImageStream*>,
                                                    WGIImageStream,
                                                    ABI::Windows::Graphics::Imaging::ImageStream*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMEEmbeddedAudioTrack_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Editing::EmbeddedAudioTrack*>,
                                         RTArrayObj<ABI::Windows::Media::Editing::IEmbeddedAudioTrack*,
                                                    IVectorView<ABI::Windows::Media::Editing::EmbeddedAudioTrack*>,
                                                    WMEEmbeddedAudioTrack,
                                                    ABI::Windows::Media::Editing::EmbeddedAudioTrack*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>,
                                                RTMutableArrayObj<ABI::Windows::Media::Effects::IAudioEffectDefinition*,
                                                                  IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>,
                                                                  RTObject<WMEIAudioEffectDefinition>,
                                                                  ABI::Windows::Media::Effects::IAudioEffectDefinition*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_RTObject_WMEIVideoEffectDefinition_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Media::Effects::IVideoEffectDefinition*>,
                                                RTMutableArrayObj<ABI::Windows::Media::Effects::IVideoEffectDefinition*,
                                                                  IVector<ABI::Windows::Media::Effects::IVideoEffectDefinition*>,
                                                                  RTObject<WMEIVideoEffectDefinition>,
                                                                  ABI::Windows::Media::Effects::IVideoEffectDefinition*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WMEBackgroundAudioTrack_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Media::Editing::BackgroundAudioTrack*>,
                                                RTMutableArrayObj<ABI::Windows::Media::Editing::IBackgroundAudioTrack*,
                                                                  IVector<ABI::Windows::Media::Editing::BackgroundAudioTrack*>,
                                                                  WMEBackgroundAudioTrack,
                                                                  ABI::Windows::Media::Editing::BackgroundAudioTrack*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WMEMediaClip_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Media::Editing::MediaClip*>,
                                                RTMutableArrayObj<ABI::Windows::Media::Editing::IMediaClip*,
                                                                  IVector<ABI::Windows::Media::Editing::MediaClip*>,
                                                                  WMEMediaClip,
                                                                  ABI::Windows::Media::Editing::MediaClip*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WMEMediaOverlay_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Media::Editing::MediaOverlay*>,
                                                RTMutableArrayObj<ABI::Windows::Media::Editing::IMediaOverlay*,
                                                                  IVector<ABI::Windows::Media::Editing::MediaOverlay*>,
                                                                  WMEMediaOverlay,
                                                                  ABI::Windows::Media::Editing::MediaOverlay*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WMEMediaOverlayLayer_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Media::Editing::MediaOverlayLayer*>,
                                                RTMutableArrayObj<ABI::Windows::Media::Editing::IMediaOverlayLayer*,
                                                                  IVector<ABI::Windows::Media::Editing::MediaOverlayLayer*>,
                                                                  WMEMediaOverlayLayer,
                                                                  ABI::Windows::Media::Editing::MediaOverlayLayer*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableDictionary_NSString_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<
        MutableDictionaryAdapterObj<IMap<HSTRING, HSTRING>,
                                    DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, HSTRING>>,
                                    RTMapObj<HSTRING,
                                             HSTRING,
                                             HSTRING,
                                             HSTRING,
                                             NSString,
                                             NSString,
                                             IMap<HSTRING, HSTRING>,
                                             dummyObjCCreator,
                                             dummyObjCCreator,
                                             dummyWRLCreator,
                                             dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
