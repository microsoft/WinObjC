// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Core.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::Core {

struct WINRT_EBO AudioStreamDescriptor :
    Windows::Media::Core::IAudioStreamDescriptor,
    impl::require<AudioStreamDescriptor, Windows::Media::Core::IAudioStreamDescriptor2>
{
    AudioStreamDescriptor(std::nullptr_t) noexcept {}
    AudioStreamDescriptor(const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties);
};

struct WINRT_EBO AudioTrack :
    Windows::Media::Core::IMediaTrack,
    impl::require<AudioTrack, Windows::Media::Core::IAudioTrack>
{
    AudioTrack(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AudioTrackOpenFailedEventArgs :
    Windows::Media::Core::IAudioTrackOpenFailedEventArgs
{
    AudioTrackOpenFailedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AudioTrackSupportInfo :
    Windows::Media::Core::IAudioTrackSupportInfo
{
    AudioTrackSupportInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DataCue :
    Windows::Media::Core::IDataCue
{
    DataCue(std::nullptr_t) noexcept {}
    DataCue();
};

struct WINRT_EBO FaceDetectedEventArgs :
    Windows::Media::Core::IFaceDetectedEventArgs
{
    FaceDetectedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FaceDetectionEffect :
    Windows::Media::Core::IFaceDetectionEffect
{
    FaceDetectionEffect(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FaceDetectionEffectDefinition :
    Windows::Media::Effects::IVideoEffectDefinition,
    impl::require<FaceDetectionEffectDefinition, Windows::Media::Core::IFaceDetectionEffectDefinition>
{
    FaceDetectionEffectDefinition(std::nullptr_t) noexcept {}
    FaceDetectionEffectDefinition();
};

struct WINRT_EBO FaceDetectionEffectFrame :
    Windows::Media::Core::IFaceDetectionEffectFrame
{
    FaceDetectionEffectFrame(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HighDynamicRangeControl :
    Windows::Media::Core::IHighDynamicRangeControl
{
    HighDynamicRangeControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HighDynamicRangeOutput :
    Windows::Media::Core::IHighDynamicRangeOutput
{
    HighDynamicRangeOutput(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaBinder :
    Windows::Media::Core::IMediaBinder
{
    MediaBinder(std::nullptr_t) noexcept {}
    MediaBinder();
};

struct WINRT_EBO MediaBindingEventArgs :
    Windows::Media::Core::IMediaBindingEventArgs
{
    MediaBindingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaCueEventArgs :
    Windows::Media::Core::IMediaCueEventArgs
{
    MediaCueEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaSource :
    Windows::Media::Core::IMediaSource2,
    impl::require<MediaSource, Windows::Media::Core::IMediaSource3>
{
    MediaSource(std::nullptr_t) noexcept {}
    static Windows::Media::Core::MediaSource CreateFromAdaptiveMediaSource(const Windows::Media::Streaming::Adaptive::AdaptiveMediaSource & mediaSource);
    static Windows::Media::Core::MediaSource CreateFromMediaStreamSource(const Windows::Media::Core::MediaStreamSource & mediaSource);
    static Windows::Media::Core::MediaSource CreateFromMseStreamSource(const Windows::Media::Core::MseStreamSource & mediaSource);
    static Windows::Media::Core::MediaSource CreateFromIMediaSource(const Windows::Media::Core::IMediaSource & mediaSource);
    static Windows::Media::Core::MediaSource CreateFromStorageFile(const Windows::Storage::IStorageFile & file);
    static Windows::Media::Core::MediaSource CreateFromStream(const Windows::Storage::Streams::IRandomAccessStream & stream, hstring_view contentType);
    static Windows::Media::Core::MediaSource CreateFromStreamReference(const Windows::Storage::Streams::IRandomAccessStreamReference & stream, hstring_view contentType);
    static Windows::Media::Core::MediaSource CreateFromUri(const Windows::Foundation::Uri & uri);
    static Windows::Media::Core::MediaSource CreateFromMediaBinder(const Windows::Media::Core::MediaBinder & binder);
};

struct WINRT_EBO MediaSourceError :
    Windows::Media::Core::IMediaSourceError
{
    MediaSourceError(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaSourceOpenOperationCompletedEventArgs :
    Windows::Media::Core::IMediaSourceOpenOperationCompletedEventArgs
{
    MediaSourceOpenOperationCompletedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaSourceStateChangedEventArgs :
    Windows::Media::Core::IMediaSourceStateChangedEventArgs
{
    MediaSourceStateChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaStreamSample :
    Windows::Media::Core::IMediaStreamSample
{
    MediaStreamSample(std::nullptr_t) noexcept {}
    static Windows::Media::Core::MediaStreamSample CreateFromBuffer(const Windows::Storage::Streams::IBuffer & buffer, const Windows::Foundation::TimeSpan & timestamp);
    static Windows::Foundation::IAsyncOperation<Windows::Media::Core::MediaStreamSample> CreateFromStreamAsync(const Windows::Storage::Streams::IInputStream & stream, uint32_t count, const Windows::Foundation::TimeSpan & timestamp);
};

struct WINRT_EBO MediaStreamSamplePropertySet :
    Windows::Foundation::Collections::IMap<GUID, Windows::Foundation::IInspectable>
{
    MediaStreamSamplePropertySet(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaStreamSampleProtectionProperties :
    Windows::Media::Core::IMediaStreamSampleProtectionProperties
{
    MediaStreamSampleProtectionProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaStreamSource :
    Windows::Media::Core::IMediaStreamSource,
    impl::require<MediaStreamSource, Windows::Media::Core::IMediaStreamSource2>
{
    MediaStreamSource(std::nullptr_t) noexcept {}
    MediaStreamSource(const Windows::Media::Core::IMediaStreamDescriptor & descriptor);
    MediaStreamSource(const Windows::Media::Core::IMediaStreamDescriptor & descriptor, const Windows::Media::Core::IMediaStreamDescriptor & descriptor2);
};

struct WINRT_EBO MediaStreamSourceClosedEventArgs :
    Windows::Media::Core::IMediaStreamSourceClosedEventArgs
{
    MediaStreamSourceClosedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaStreamSourceClosedRequest :
    Windows::Media::Core::IMediaStreamSourceClosedRequest
{
    MediaStreamSourceClosedRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaStreamSourceSampleRenderedEventArgs :
    Windows::Media::Core::IMediaStreamSourceSampleRenderedEventArgs
{
    MediaStreamSourceSampleRenderedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaStreamSourceSampleRequest :
    Windows::Media::Core::IMediaStreamSourceSampleRequest
{
    MediaStreamSourceSampleRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaStreamSourceSampleRequestDeferral :
    Windows::Media::Core::IMediaStreamSourceSampleRequestDeferral
{
    MediaStreamSourceSampleRequestDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaStreamSourceSampleRequestedEventArgs :
    Windows::Media::Core::IMediaStreamSourceSampleRequestedEventArgs
{
    MediaStreamSourceSampleRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaStreamSourceStartingEventArgs :
    Windows::Media::Core::IMediaStreamSourceStartingEventArgs
{
    MediaStreamSourceStartingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaStreamSourceStartingRequest :
    Windows::Media::Core::IMediaStreamSourceStartingRequest
{
    MediaStreamSourceStartingRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaStreamSourceStartingRequestDeferral :
    Windows::Media::Core::IMediaStreamSourceStartingRequestDeferral
{
    MediaStreamSourceStartingRequestDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaStreamSourceSwitchStreamsRequest :
    Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequest
{
    MediaStreamSourceSwitchStreamsRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaStreamSourceSwitchStreamsRequestDeferral :
    Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequestDeferral
{
    MediaStreamSourceSwitchStreamsRequestDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaStreamSourceSwitchStreamsRequestedEventArgs :
    Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequestedEventArgs
{
    MediaStreamSourceSwitchStreamsRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MseSourceBuffer :
    Windows::Media::Core::IMseSourceBuffer
{
    MseSourceBuffer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MseSourceBufferList :
    Windows::Media::Core::IMseSourceBufferList
{
    MseSourceBufferList(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MseStreamSource :
    Windows::Media::Core::IMseStreamSource
{
    MseStreamSource(std::nullptr_t) noexcept {}
    MseStreamSource();
    static bool IsContentTypeSupported(hstring_view contentType);
};

struct WINRT_EBO SceneAnalysisEffect :
    Windows::Media::Core::ISceneAnalysisEffect
{
    SceneAnalysisEffect(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SceneAnalysisEffectDefinition :
    Windows::Media::Effects::IVideoEffectDefinition
{
    SceneAnalysisEffectDefinition(std::nullptr_t) noexcept {}
    SceneAnalysisEffectDefinition();
};

struct WINRT_EBO SceneAnalysisEffectFrame :
    Windows::Media::Core::ISceneAnalysisEffectFrame
{
    SceneAnalysisEffectFrame(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SceneAnalyzedEventArgs :
    Windows::Media::Core::ISceneAnalyzedEventArgs
{
    SceneAnalyzedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TimedMetadataTrack :
    Windows::Media::Core::ITimedMetadataTrack,
    impl::require<TimedMetadataTrack, Windows::Media::Core::ITimedMetadataTrack2>
{
    TimedMetadataTrack(std::nullptr_t) noexcept {}
    TimedMetadataTrack(hstring_view id, hstring_view language, Windows::Media::Core::TimedMetadataKind kind);
};

struct WINRT_EBO TimedMetadataTrackError :
    Windows::Media::Core::ITimedMetadataTrackError
{
    TimedMetadataTrackError(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TimedMetadataTrackFailedEventArgs :
    Windows::Media::Core::ITimedMetadataTrackFailedEventArgs
{
    TimedMetadataTrackFailedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TimedTextCue :
    Windows::Media::Core::ITimedTextCue
{
    TimedTextCue(std::nullptr_t) noexcept {}
    TimedTextCue();
};

struct WINRT_EBO TimedTextLine :
    Windows::Media::Core::ITimedTextLine
{
    TimedTextLine(std::nullptr_t) noexcept {}
    TimedTextLine();
};

struct WINRT_EBO TimedTextRegion :
    Windows::Media::Core::ITimedTextRegion
{
    TimedTextRegion(std::nullptr_t) noexcept {}
    TimedTextRegion();
};

struct WINRT_EBO TimedTextSource :
    Windows::Media::Core::ITimedTextSource
{
    TimedTextSource(std::nullptr_t) noexcept {}
    static Windows::Media::Core::TimedTextSource CreateFromStream(const Windows::Storage::Streams::IRandomAccessStream & stream);
    static Windows::Media::Core::TimedTextSource CreateFromUri(const Windows::Foundation::Uri & uri);
    static Windows::Media::Core::TimedTextSource CreateFromStream(const Windows::Storage::Streams::IRandomAccessStream & stream, hstring_view defaultLanguage);
    static Windows::Media::Core::TimedTextSource CreateFromUri(const Windows::Foundation::Uri & uri, hstring_view defaultLanguage);
};

struct WINRT_EBO TimedTextSourceResolveResultEventArgs :
    Windows::Media::Core::ITimedTextSourceResolveResultEventArgs
{
    TimedTextSourceResolveResultEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TimedTextStyle :
    Windows::Media::Core::ITimedTextStyle
{
    TimedTextStyle(std::nullptr_t) noexcept {}
    TimedTextStyle();
};

struct WINRT_EBO TimedTextSubformat :
    Windows::Media::Core::ITimedTextSubformat
{
    TimedTextSubformat(std::nullptr_t) noexcept {}
    TimedTextSubformat();
};

struct WINRT_EBO VideoStabilizationEffect :
    Windows::Media::Core::IVideoStabilizationEffect
{
    VideoStabilizationEffect(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VideoStabilizationEffectDefinition :
    Windows::Media::Effects::IVideoEffectDefinition
{
    VideoStabilizationEffectDefinition(std::nullptr_t) noexcept {}
    VideoStabilizationEffectDefinition();
};

struct WINRT_EBO VideoStabilizationEffectEnabledChangedEventArgs :
    Windows::Media::Core::IVideoStabilizationEffectEnabledChangedEventArgs
{
    VideoStabilizationEffectEnabledChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VideoStreamDescriptor :
    Windows::Media::Core::IVideoStreamDescriptor
{
    VideoStreamDescriptor(std::nullptr_t) noexcept {}
    VideoStreamDescriptor(const Windows::Media::MediaProperties::VideoEncodingProperties & encodingProperties);
};

struct WINRT_EBO VideoTrack :
    Windows::Media::Core::IMediaTrack,
    impl::require<VideoTrack, Windows::Media::Core::IVideoTrack>
{
    VideoTrack(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VideoTrackOpenFailedEventArgs :
    Windows::Media::Core::IVideoTrackOpenFailedEventArgs
{
    VideoTrackOpenFailedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VideoTrackSupportInfo :
    Windows::Media::Core::IVideoTrackSupportInfo
{
    VideoTrackSupportInfo(std::nullptr_t) noexcept {}
};

}

}
