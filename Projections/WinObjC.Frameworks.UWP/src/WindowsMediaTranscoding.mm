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

// WindowsMediaTranscoding.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Transcoding.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaTranscoding.h"
#include "WindowsMediaTranscoding_priv.h"

@implementation WMTPrepareTranscodeResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Transcoding::IPrepareTranscodeResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)canTranscode {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IPrepareTranscodeResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanTranscode(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WMTTranscodeFailureReason)failureReason {
    ABI::Windows::Media::Transcoding::TranscodeFailureReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IPrepareTranscodeResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_FailureReason(&unmarshalledReturn));
    return (WMTTranscodeFailureReason)unmarshalledReturn;
}

// Failed to generate member TranscodeAsync (Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<Double>)
@end

@implementation WMTMediaTranscoder

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Transcoding::IMediaTranscoder> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Transcoding.MediaTranscoder").Get(), &out));
    return [_createRtProxy<WMTMediaTranscoder>(out.Get()) retain];
}

- (void)setTrimStartTime:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder>(self);
    THROW_NS_IF_FAILED(_comInst->put_TrimStartTime(*[value internalStruct]));
}

- (WFTimeSpan*)trimStartTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrimStartTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setTrimStopTime:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder>(self);
    THROW_NS_IF_FAILED(_comInst->put_TrimStopTime(*[value internalStruct]));
}

- (WFTimeSpan*)trimStopTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrimStopTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setAlwaysReencode:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder>(self);
    THROW_NS_IF_FAILED(_comInst->put_AlwaysReencode((boolean)value));
}

- (BOOL)alwaysReencode {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlwaysReencode(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHardwareAccelerationEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder>(self);
    THROW_NS_IF_FAILED(_comInst->put_HardwareAccelerationEnabled((boolean)value));
}

- (BOOL)hardwareAccelerationEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder>(self);
    THROW_NS_IF_FAILED(_comInst->get_HardwareAccelerationEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)addAudioEffect:(NSString*)activatableClassId {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder>(self);
    THROW_NS_IF_FAILED(_comInst->AddAudioEffect(nsStrToHstr(activatableClassId).Get()));
}

- (void)addAudioEffectWithSettings:(NSString*)activatableClassId
                    effectRequired:(BOOL)effectRequired
                     configuration:(RTObject<WFCIPropertySet>*)configuration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddAudioEffectWithSettings(nsStrToHstr(activatableClassId).Get(),
                                             (boolean)effectRequired,
                                             _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get()));
}

- (void)addVideoEffect:(NSString*)activatableClassId {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder>(self);
    THROW_NS_IF_FAILED(_comInst->AddVideoEffect(nsStrToHstr(activatableClassId).Get()));
}

- (void)addVideoEffectWithSettings:(NSString*)activatableClassId
                    effectRequired:(BOOL)effectRequired
                     configuration:(RTObject<WFCIPropertySet>*)configuration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddVideoEffectWithSettings(nsStrToHstr(activatableClassId).Get(),
                                             (boolean)effectRequired,
                                             _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get()));
}

- (void)clearEffects {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder>(self);
    THROW_NS_IF_FAILED(_comInst->ClearEffects());
}

- (void)prepareFileTranscodeAsync:(RTObject<WSIStorageFile>*)source
                      destination:(RTObject<WSIStorageFile>*)destination
                          profile:(WMMMediaEncodingProfile*)profile
                          success:(void (^)(WMTPrepareTranscodeResult*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Transcoding::PrepareTranscodeResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder>(self);
    THROW_NS_IF_FAILED(
        _comInst->PrepareFileTranscodeAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(source).Get(),
                                            _getRtInterface<ABI::Windows::Storage::IStorageFile>(destination).Get(),
                                            _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(profile).Get(),
                                            &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Transcoding::PrepareTranscodeResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Transcoding::PrepareTranscodeResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Transcoding::IPrepareTranscodeResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMTPrepareTranscodeResult>(result.Get()));
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

- (void)prepareStreamTranscodeAsync:(RTObject<WSSIRandomAccessStream>*)source
                        destination:(RTObject<WSSIRandomAccessStream>*)destination
                            profile:(WMMMediaEncodingProfile*)profile
                            success:(void (^)(WMTPrepareTranscodeResult*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Transcoding::PrepareTranscodeResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder>(self);
    THROW_NS_IF_FAILED(
        _comInst->PrepareStreamTranscodeAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(source).Get(),
                                              _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(destination).Get(),
                                              _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(profile).Get(),
                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Transcoding::PrepareTranscodeResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Transcoding::PrepareTranscodeResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Transcoding::IPrepareTranscodeResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMTPrepareTranscodeResult>(result.Get()));
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

- (void)prepareMediaStreamSourceTranscodeAsync:(RTObject<WMCIMediaSource>*)source
                                   destination:(RTObject<WSSIRandomAccessStream>*)destination
                                       profile:(WMMMediaEncodingProfile*)profile
                                       success:(void (^)(WMTPrepareTranscodeResult*))success
                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Transcoding::PrepareTranscodeResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder2>(self);
    THROW_NS_IF_FAILED(_comInst->PrepareMediaStreamSourceTranscodeAsync(
        _getRtInterface<ABI::Windows::Media::Core::IMediaSource>(source).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(destination).Get(),
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(profile).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Transcoding::PrepareTranscodeResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Transcoding::PrepareTranscodeResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Transcoding::IPrepareTranscodeResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMTPrepareTranscodeResult>(result.Get()));
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

- (void)setVideoProcessingAlgorithm:(WMTMediaVideoProcessingAlgorithm)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder2>(self);
    THROW_NS_IF_FAILED(_comInst->put_VideoProcessingAlgorithm((ABI::Windows::Media::Transcoding::MediaVideoProcessingAlgorithm)value));
}

- (WMTMediaVideoProcessingAlgorithm)videoProcessingAlgorithm {
    ABI::Windows::Media::Transcoding::MediaVideoProcessingAlgorithm unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Transcoding::IMediaTranscoder2>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoProcessingAlgorithm(&unmarshalledReturn));
    return (WMTMediaVideoProcessingAlgorithm)unmarshalledReturn;
}

@end
