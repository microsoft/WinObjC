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

// WindowsMediaStreamingAdaptive.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Streaming.Adaptive.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaStreamingAdaptive.h"
#include "WindowsMediaStreamingAdaptive_priv.h"

@implementation WMSAAdaptiveMediaSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceStatics> WMSAIAdaptiveMediaSourceStatics_inst() {
    ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.Streaming.Adaptive.AdaptiveMediaSource").Get(), &inst));
    return inst;
}

+ (BOOL)isContentTypeSupported:(NSString*)contentType {
    boolean unmarshalledReturn;
    auto _comInst = WMSAIAdaptiveMediaSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsContentTypeSupported(nsStrToHstr(contentType).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)createFromUriAsync:(WFUri*)uri
                   success:(void (^)(WMSAAdaptiveMediaSourceCreationResult*))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult*>>
        unmarshalledReturn;
    auto _comInst = WMSAIAdaptiveMediaSourceStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromUriAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMSAAdaptiveMediaSourceCreationResult>(result.Get()));
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

+ (void)createFromUriWithDownloaderAsync:(WFUri*)uri
                              httpClient:(WWHHttpClient*)httpClient
                                 success:(void (^)(WMSAAdaptiveMediaSourceCreationResult*))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult*>>
        unmarshalledReturn;
    auto _comInst = WMSAIAdaptiveMediaSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromUriWithDownloaderAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                                  _getRtInterface<ABI::Windows::Web::Http::IHttpClient>(httpClient).Get(),
                                                                  &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMSAAdaptiveMediaSourceCreationResult>(result.Get()));
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

+ (void)createFromStreamAsync:(RTObject<WSSIInputStream>*)stream
                          uri:(WFUri*)uri
                  contentType:(NSString*)contentType
                      success:(void (^)(WMSAAdaptiveMediaSourceCreationResult*))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult*>>
        unmarshalledReturn;
    auto _comInst = WMSAIAdaptiveMediaSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(stream).Get(),
                                                       _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                       nsStrToHstr(contentType).Get(),
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMSAAdaptiveMediaSourceCreationResult>(result.Get()));
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

+ (void)createFromStreamWithDownloaderAsync:(RTObject<WSSIInputStream>*)stream
                                        uri:(WFUri*)uri
                                contentType:(NSString*)contentType
                                 httpClient:(WWHHttpClient*)httpClient
                                    success:(void (^)(WMSAAdaptiveMediaSourceCreationResult*))success
                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult*>>
        unmarshalledReturn;
    auto _comInst = WMSAIAdaptiveMediaSourceStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromStreamWithDownloaderAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(stream).Get(),
                                                      _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                      nsStrToHstr(contentType).Get(),
                                                      _getRtInterface<ABI::Windows::Web::Http::IHttpClient>(httpClient).Get(),
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMSAAdaptiveMediaSourceCreationResult>(result.Get()));
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

- (BOOL)isLive {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsLive(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFTimeSpan*)desiredLiveOffset {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredLiveOffset(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setDesiredLiveOffset:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredLiveOffset(*[value internalStruct]));
}

- (unsigned int)initialBitrate {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_InitialBitrate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setInitialBitrate:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_InitialBitrate(value));
}

- (unsigned int)currentDownloadBitrate {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentDownloadBitrate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)currentPlaybackBitrate {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentPlaybackBitrate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSArray* /* unsigned int */)availableBitrates {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_AvailableBitrates(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

- (id /* unsigned int */)desiredMinBitrate {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredMinBitrate(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (void)setDesiredMinBitrate:(id /* unsigned int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredMinBitrate(BuildNullable<unsigned int>(value)));
}

- (id /* unsigned int */)desiredMaxBitrate {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredMaxBitrate(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (void)setDesiredMaxBitrate:(id /* unsigned int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredMaxBitrate(BuildNullable<unsigned int>(value)));
}

- (BOOL)audioOnlyPlayback {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioOnlyPlayback(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (uint64_t)inboundBitsPerSecond {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_InboundBitsPerSecond(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)inboundBitsPerSecondWindow {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_InboundBitsPerSecondWindow(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setInboundBitsPerSecondWindow:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_InboundBitsPerSecondWindow(*[value internalStruct]));
}

- (EventRegistrationToken)addDownloadBitrateChangedEvent:(void (^)(WMSAAdaptiveMediaSource*,
                                                                   WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_DownloadBitrateChanged(
        Make<
            ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadBitrateChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDownloadBitrateChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DownloadBitrateChanged(token));
}

- (EventRegistrationToken)addPlaybackBitrateChangedEvent:(void (^)(WMSAAdaptiveMediaSource*,
                                                                   WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PlaybackBitrateChanged(
        Make<
            ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourcePlaybackBitrateChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePlaybackBitrateChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PlaybackBitrateChanged(token));
}

- (EventRegistrationToken)addDownloadRequestedEvent:(void (^)(WMSAAdaptiveMediaSource*,
                                                              WMSAAdaptiveMediaSourceDownloadRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_DownloadRequested(
        Make<
            ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadRequestedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDownloadRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DownloadRequested(token));
}

- (EventRegistrationToken)addDownloadCompletedEvent:(void (^)(WMSAAdaptiveMediaSource*,
                                                              WMSAAdaptiveMediaSourceDownloadCompletedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_DownloadCompleted(
        Make<
            ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadCompletedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDownloadCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DownloadCompleted(token));
}

- (EventRegistrationToken)addDownloadFailedEvent:(void (^)(WMSAAdaptiveMediaSource*,
                                                           WMSAAdaptiveMediaSourceDownloadFailedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_DownloadFailed(
        Make<
            ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadFailedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDownloadFailedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DownloadFailed(token));
}

- (WMSAAdaptiveMediaSourceAdvancedSettings*)advancedSettings {
    ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdvancedSettings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMSAAdaptiveMediaSourceAdvancedSettings>(unmarshalledReturn.Get());
}

@end

@implementation WMSAAdaptiveMediaSourceCreationResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMSAAdaptiveMediaSourceCreationStatus)status {
    ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WMSAAdaptiveMediaSourceCreationStatus)unmarshalledReturn;
}

- (WMSAAdaptiveMediaSource*)mediaSource {
    ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMSAAdaptiveMediaSource>(unmarshalledReturn.Get());
}

- (WWHHttpResponseMessage*)httpResponseMessage {
    ComPtr<ABI::Windows::Web::Http::IHttpResponseMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_HttpResponseMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpResponseMessage>(unmarshalledReturn.Get());
}

@end

@implementation WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)oldValue {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)newValue {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)oldValue {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)newValue {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)audioOnly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioOnly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMSAAdaptiveMediaSourceDownloadRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMSAAdaptiveMediaSourceResourceType)resourceType {
    ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceType(&unmarshalledReturn));
    return (WMSAAdaptiveMediaSourceResourceType)unmarshalledReturn;
}

- (WFUri*)resourceUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (id /* uint64_t */)resourceByteRangeOffset {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceByteRangeOffset(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (id /* uint64_t */)resourceByteRangeLength {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceByteRangeLength(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (WMSAAdaptiveMediaSourceDownloadResult*)result {
    ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Result(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMSAAdaptiveMediaSourceDownloadResult>(unmarshalledReturn.Get());
}

- (WMSAAdaptiveMediaSourceDownloadRequestedDeferral*)getDeferral {
    ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMSAAdaptiveMediaSourceDownloadRequestedDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WMSAAdaptiveMediaSourceDownloadCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMSAAdaptiveMediaSourceResourceType)resourceType {
    ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceType(&unmarshalledReturn));
    return (WMSAAdaptiveMediaSourceResourceType)unmarshalledReturn;
}

- (WFUri*)resourceUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (id /* uint64_t */)resourceByteRangeOffset {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceByteRangeOffset(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (id /* uint64_t */)resourceByteRangeLength {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceByteRangeLength(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (WWHHttpResponseMessage*)httpResponseMessage {
    ComPtr<ABI::Windows::Web::Http::IHttpResponseMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_HttpResponseMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpResponseMessage>(unmarshalledReturn.Get());
}

@end

@implementation WMSAAdaptiveMediaSourceDownloadFailedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMSAAdaptiveMediaSourceResourceType)resourceType {
    ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceType(&unmarshalledReturn));
    return (WMSAAdaptiveMediaSourceResourceType)unmarshalledReturn;
}

- (WFUri*)resourceUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (id /* uint64_t */)resourceByteRangeOffset {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceByteRangeOffset(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (id /* uint64_t */)resourceByteRangeLength {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceByteRangeLength(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (WWHHttpResponseMessage*)httpResponseMessage {
    ComPtr<ABI::Windows::Web::Http::IHttpResponseMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_HttpResponseMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpResponseMessage>(unmarshalledReturn.Get());
}

@end

@implementation WMSAAdaptiveMediaSourceAdvancedSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)allSegmentsIndependent {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllSegmentsIndependent(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllSegmentsIndependent:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllSegmentsIndependent((boolean)value));
}

- (id /* double */)desiredBitrateHeadroomRatio {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredBitrateHeadroomRatio(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (void)setDesiredBitrateHeadroomRatio:(id /* double */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredBitrateHeadroomRatio(BuildNullable<double>(value)));
}

- (id /* double */)bitrateDowngradeTriggerRatio {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitrateDowngradeTriggerRatio(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (void)setBitrateDowngradeTriggerRatio:(id /* double */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_BitrateDowngradeTriggerRatio(BuildNullable<double>(value)));
}

@end

@implementation WMSAAdaptiveMediaSourceDownloadResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFUri*)resourceUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setResourceUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult>(self);
    THROW_NS_IF_FAILED(_comInst->put_ResourceUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (RTObject<WSSIInputStream>*)inputStream {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

- (void)setInputStream:(RTObject<WSSIInputStream>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult>(self);
    THROW_NS_IF_FAILED(_comInst->put_InputStream(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(value).Get()));
}

- (RTObject<WSSIBuffer>*)buffer {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Buffer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setBuffer:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult>(self);
    THROW_NS_IF_FAILED(_comInst->put_Buffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (NSString*)contentType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setContentType:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentType(nsStrToHstr(value).Get()));
}

- (unsigned int)extendedStatus {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedStatus(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setExtendedStatus:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExtendedStatus(value));
}

- (id /* uint64_t */)resourceByteRangeOffset {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceByteRangeOffset(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (void)setResourceByteRangeOffset:(id /* uint64_t */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ResourceByteRangeOffset(BuildNullable<uint64_t>(value)));
}

- (id /* uint64_t */)resourceByteRangeLength {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceByteRangeLength(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (void)setResourceByteRangeLength:(id /* uint64_t */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ResourceByteRangeLength(BuildNullable<uint64_t>(value)));
}

@end

@implementation WMSAAdaptiveMediaSourceDownloadRequestedDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

id RTProxiedNSArray_UInt32_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<
        IVectorView<unsigned int>,
        RTArrayObj<unsigned int, IVectorView<unsigned int>, unsigned int, unsigned int, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
