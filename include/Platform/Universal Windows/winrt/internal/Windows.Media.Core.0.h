// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Core {

struct MseTimeRange;
struct TimedTextPadding;
struct TimedTextSize;
struct TimedTextDouble;
struct TimedTextPoint;

}

namespace Windows::Media::Core {

using MseTimeRange = ABI::Windows::Media::Core::MseTimeRange;
using TimedTextPadding = ABI::Windows::Media::Core::TimedTextPadding;
using TimedTextSize = ABI::Windows::Media::Core::TimedTextSize;
using TimedTextDouble = ABI::Windows::Media::Core::TimedTextDouble;
using TimedTextPoint = ABI::Windows::Media::Core::TimedTextPoint;

}

namespace ABI::Windows::Media::Core {

struct IAudioStreamDescriptor;
struct IAudioStreamDescriptor2;
struct IAudioStreamDescriptorFactory;
struct IAudioTrack;
struct IAudioTrackOpenFailedEventArgs;
struct IAudioTrackSupportInfo;
struct IDataCue;
struct IFaceDetectedEventArgs;
struct IFaceDetectionEffect;
struct IFaceDetectionEffectDefinition;
struct IFaceDetectionEffectFrame;
struct IHighDynamicRangeControl;
struct IHighDynamicRangeOutput;
struct IMediaBinder;
struct IMediaBindingEventArgs;
struct IMediaCue;
struct IMediaCueEventArgs;
struct IMediaSource;
struct IMediaSource2;
struct IMediaSource3;
struct IMediaSourceError;
struct IMediaSourceOpenOperationCompletedEventArgs;
struct IMediaSourceStateChangedEventArgs;
struct IMediaSourceStatics;
struct IMediaSourceStatics2;
struct IMediaStreamDescriptor;
struct IMediaStreamSample;
struct IMediaStreamSampleProtectionProperties;
struct IMediaStreamSampleStatics;
struct IMediaStreamSource;
struct IMediaStreamSource2;
struct IMediaStreamSourceClosedEventArgs;
struct IMediaStreamSourceClosedRequest;
struct IMediaStreamSourceFactory;
struct IMediaStreamSourceSampleRenderedEventArgs;
struct IMediaStreamSourceSampleRequest;
struct IMediaStreamSourceSampleRequestDeferral;
struct IMediaStreamSourceSampleRequestedEventArgs;
struct IMediaStreamSourceStartingEventArgs;
struct IMediaStreamSourceStartingRequest;
struct IMediaStreamSourceStartingRequestDeferral;
struct IMediaStreamSourceSwitchStreamsRequest;
struct IMediaStreamSourceSwitchStreamsRequestDeferral;
struct IMediaStreamSourceSwitchStreamsRequestedEventArgs;
struct IMediaTrack;
struct IMseSourceBuffer;
struct IMseSourceBufferList;
struct IMseStreamSource;
struct IMseStreamSourceStatics;
struct ISceneAnalysisEffect;
struct ISceneAnalysisEffectFrame;
struct ISceneAnalyzedEventArgs;
struct ISingleSelectMediaTrackList;
struct ITimedMetadataTrack;
struct ITimedMetadataTrack2;
struct ITimedMetadataTrackError;
struct ITimedMetadataTrackFactory;
struct ITimedMetadataTrackFailedEventArgs;
struct ITimedTextCue;
struct ITimedTextLine;
struct ITimedTextRegion;
struct ITimedTextSource;
struct ITimedTextSourceResolveResultEventArgs;
struct ITimedTextSourceStatics;
struct ITimedTextStyle;
struct ITimedTextSubformat;
struct IVideoStabilizationEffect;
struct IVideoStabilizationEffectEnabledChangedEventArgs;
struct IVideoStreamDescriptor;
struct IVideoStreamDescriptorFactory;
struct IVideoTrack;
struct IVideoTrackOpenFailedEventArgs;
struct IVideoTrackSupportInfo;
struct AudioStreamDescriptor;
struct AudioTrack;
struct AudioTrackOpenFailedEventArgs;
struct AudioTrackSupportInfo;
struct DataCue;
struct FaceDetectedEventArgs;
struct FaceDetectionEffect;
struct FaceDetectionEffectDefinition;
struct FaceDetectionEffectFrame;
struct HighDynamicRangeControl;
struct HighDynamicRangeOutput;
struct MediaBinder;
struct MediaBindingEventArgs;
struct MediaCueEventArgs;
struct MediaSource;
struct MediaSourceError;
struct MediaSourceOpenOperationCompletedEventArgs;
struct MediaSourceStateChangedEventArgs;
struct MediaStreamSample;
struct MediaStreamSamplePropertySet;
struct MediaStreamSampleProtectionProperties;
struct MediaStreamSource;
struct MediaStreamSourceClosedEventArgs;
struct MediaStreamSourceClosedRequest;
struct MediaStreamSourceSampleRenderedEventArgs;
struct MediaStreamSourceSampleRequest;
struct MediaStreamSourceSampleRequestDeferral;
struct MediaStreamSourceSampleRequestedEventArgs;
struct MediaStreamSourceStartingEventArgs;
struct MediaStreamSourceStartingRequest;
struct MediaStreamSourceStartingRequestDeferral;
struct MediaStreamSourceSwitchStreamsRequest;
struct MediaStreamSourceSwitchStreamsRequestDeferral;
struct MediaStreamSourceSwitchStreamsRequestedEventArgs;
struct MseSourceBuffer;
struct MseSourceBufferList;
struct MseStreamSource;
struct SceneAnalysisEffect;
struct SceneAnalysisEffectDefinition;
struct SceneAnalysisEffectFrame;
struct SceneAnalyzedEventArgs;
struct TimedMetadataTrack;
struct TimedMetadataTrackError;
struct TimedMetadataTrackFailedEventArgs;
struct TimedTextCue;
struct TimedTextLine;
struct TimedTextRegion;
struct TimedTextSource;
struct TimedTextSourceResolveResultEventArgs;
struct TimedTextStyle;
struct TimedTextSubformat;
struct VideoStabilizationEffect;
struct VideoStabilizationEffectDefinition;
struct VideoStabilizationEffectEnabledChangedEventArgs;
struct VideoStreamDescriptor;
struct VideoTrack;
struct VideoTrackOpenFailedEventArgs;
struct VideoTrackSupportInfo;

}

namespace Windows::Media::Core {

struct IAudioStreamDescriptor;
struct IAudioStreamDescriptor2;
struct IAudioStreamDescriptorFactory;
struct IAudioTrack;
struct IAudioTrackOpenFailedEventArgs;
struct IAudioTrackSupportInfo;
struct IDataCue;
struct IFaceDetectedEventArgs;
struct IFaceDetectionEffect;
struct IFaceDetectionEffectDefinition;
struct IFaceDetectionEffectFrame;
struct IHighDynamicRangeControl;
struct IHighDynamicRangeOutput;
struct IMediaBinder;
struct IMediaBindingEventArgs;
struct IMediaCue;
struct IMediaCueEventArgs;
struct IMediaSource;
struct IMediaSource2;
struct IMediaSource3;
struct IMediaSourceError;
struct IMediaSourceOpenOperationCompletedEventArgs;
struct IMediaSourceStateChangedEventArgs;
struct IMediaSourceStatics;
struct IMediaSourceStatics2;
struct IMediaStreamDescriptor;
struct IMediaStreamSample;
struct IMediaStreamSampleProtectionProperties;
struct IMediaStreamSampleStatics;
struct IMediaStreamSource;
struct IMediaStreamSource2;
struct IMediaStreamSourceClosedEventArgs;
struct IMediaStreamSourceClosedRequest;
struct IMediaStreamSourceFactory;
struct IMediaStreamSourceSampleRenderedEventArgs;
struct IMediaStreamSourceSampleRequest;
struct IMediaStreamSourceSampleRequestDeferral;
struct IMediaStreamSourceSampleRequestedEventArgs;
struct IMediaStreamSourceStartingEventArgs;
struct IMediaStreamSourceStartingRequest;
struct IMediaStreamSourceStartingRequestDeferral;
struct IMediaStreamSourceSwitchStreamsRequest;
struct IMediaStreamSourceSwitchStreamsRequestDeferral;
struct IMediaStreamSourceSwitchStreamsRequestedEventArgs;
struct IMediaTrack;
struct IMseSourceBuffer;
struct IMseSourceBufferList;
struct IMseStreamSource;
struct IMseStreamSourceStatics;
struct ISceneAnalysisEffect;
struct ISceneAnalysisEffectFrame;
struct ISceneAnalyzedEventArgs;
struct ISingleSelectMediaTrackList;
struct ITimedMetadataTrack;
struct ITimedMetadataTrack2;
struct ITimedMetadataTrackError;
struct ITimedMetadataTrackFactory;
struct ITimedMetadataTrackFailedEventArgs;
struct ITimedTextCue;
struct ITimedTextLine;
struct ITimedTextRegion;
struct ITimedTextSource;
struct ITimedTextSourceResolveResultEventArgs;
struct ITimedTextSourceStatics;
struct ITimedTextStyle;
struct ITimedTextSubformat;
struct IVideoStabilizationEffect;
struct IVideoStabilizationEffectEnabledChangedEventArgs;
struct IVideoStreamDescriptor;
struct IVideoStreamDescriptorFactory;
struct IVideoTrack;
struct IVideoTrackOpenFailedEventArgs;
struct IVideoTrackSupportInfo;
struct AudioStreamDescriptor;
struct AudioTrack;
struct AudioTrackOpenFailedEventArgs;
struct AudioTrackSupportInfo;
struct DataCue;
struct FaceDetectedEventArgs;
struct FaceDetectionEffect;
struct FaceDetectionEffectDefinition;
struct FaceDetectionEffectFrame;
struct HighDynamicRangeControl;
struct HighDynamicRangeOutput;
struct MediaBinder;
struct MediaBindingEventArgs;
struct MediaCueEventArgs;
struct MediaSource;
struct MediaSourceError;
struct MediaSourceOpenOperationCompletedEventArgs;
struct MediaSourceStateChangedEventArgs;
struct MediaStreamSample;
struct MediaStreamSamplePropertySet;
struct MediaStreamSampleProtectionProperties;
struct MediaStreamSource;
struct MediaStreamSourceClosedEventArgs;
struct MediaStreamSourceClosedRequest;
struct MediaStreamSourceSampleRenderedEventArgs;
struct MediaStreamSourceSampleRequest;
struct MediaStreamSourceSampleRequestDeferral;
struct MediaStreamSourceSampleRequestedEventArgs;
struct MediaStreamSourceStartingEventArgs;
struct MediaStreamSourceStartingRequest;
struct MediaStreamSourceStartingRequestDeferral;
struct MediaStreamSourceSwitchStreamsRequest;
struct MediaStreamSourceSwitchStreamsRequestDeferral;
struct MediaStreamSourceSwitchStreamsRequestedEventArgs;
struct MseSourceBuffer;
struct MseSourceBufferList;
struct MseStreamSource;
struct SceneAnalysisEffect;
struct SceneAnalysisEffectDefinition;
struct SceneAnalysisEffectFrame;
struct SceneAnalyzedEventArgs;
struct TimedMetadataTrack;
struct TimedMetadataTrackError;
struct TimedMetadataTrackFailedEventArgs;
struct TimedTextCue;
struct TimedTextLine;
struct TimedTextRegion;
struct TimedTextSource;
struct TimedTextSourceResolveResultEventArgs;
struct TimedTextStyle;
struct TimedTextSubformat;
struct VideoStabilizationEffect;
struct VideoStabilizationEffectDefinition;
struct VideoStabilizationEffectEnabledChangedEventArgs;
struct VideoStreamDescriptor;
struct VideoTrack;
struct VideoTrackOpenFailedEventArgs;
struct VideoTrackSupportInfo;

}

namespace Windows::Media::Core {

template <typename T> struct impl_IAudioStreamDescriptor;
template <typename T> struct impl_IAudioStreamDescriptor2;
template <typename T> struct impl_IAudioStreamDescriptorFactory;
template <typename T> struct impl_IAudioTrack;
template <typename T> struct impl_IAudioTrackOpenFailedEventArgs;
template <typename T> struct impl_IAudioTrackSupportInfo;
template <typename T> struct impl_IDataCue;
template <typename T> struct impl_IFaceDetectedEventArgs;
template <typename T> struct impl_IFaceDetectionEffect;
template <typename T> struct impl_IFaceDetectionEffectDefinition;
template <typename T> struct impl_IFaceDetectionEffectFrame;
template <typename T> struct impl_IHighDynamicRangeControl;
template <typename T> struct impl_IHighDynamicRangeOutput;
template <typename T> struct impl_IMediaBinder;
template <typename T> struct impl_IMediaBindingEventArgs;
template <typename T> struct impl_IMediaCue;
template <typename T> struct impl_IMediaCueEventArgs;
template <typename T> struct impl_IMediaSource;
template <typename T> struct impl_IMediaSource2;
template <typename T> struct impl_IMediaSource3;
template <typename T> struct impl_IMediaSourceError;
template <typename T> struct impl_IMediaSourceOpenOperationCompletedEventArgs;
template <typename T> struct impl_IMediaSourceStateChangedEventArgs;
template <typename T> struct impl_IMediaSourceStatics;
template <typename T> struct impl_IMediaSourceStatics2;
template <typename T> struct impl_IMediaStreamDescriptor;
template <typename T> struct impl_IMediaStreamSample;
template <typename T> struct impl_IMediaStreamSampleProtectionProperties;
template <typename T> struct impl_IMediaStreamSampleStatics;
template <typename T> struct impl_IMediaStreamSource;
template <typename T> struct impl_IMediaStreamSource2;
template <typename T> struct impl_IMediaStreamSourceClosedEventArgs;
template <typename T> struct impl_IMediaStreamSourceClosedRequest;
template <typename T> struct impl_IMediaStreamSourceFactory;
template <typename T> struct impl_IMediaStreamSourceSampleRenderedEventArgs;
template <typename T> struct impl_IMediaStreamSourceSampleRequest;
template <typename T> struct impl_IMediaStreamSourceSampleRequestDeferral;
template <typename T> struct impl_IMediaStreamSourceSampleRequestedEventArgs;
template <typename T> struct impl_IMediaStreamSourceStartingEventArgs;
template <typename T> struct impl_IMediaStreamSourceStartingRequest;
template <typename T> struct impl_IMediaStreamSourceStartingRequestDeferral;
template <typename T> struct impl_IMediaStreamSourceSwitchStreamsRequest;
template <typename T> struct impl_IMediaStreamSourceSwitchStreamsRequestDeferral;
template <typename T> struct impl_IMediaStreamSourceSwitchStreamsRequestedEventArgs;
template <typename T> struct impl_IMediaTrack;
template <typename T> struct impl_IMseSourceBuffer;
template <typename T> struct impl_IMseSourceBufferList;
template <typename T> struct impl_IMseStreamSource;
template <typename T> struct impl_IMseStreamSourceStatics;
template <typename T> struct impl_ISceneAnalysisEffect;
template <typename T> struct impl_ISceneAnalysisEffectFrame;
template <typename T> struct impl_ISceneAnalyzedEventArgs;
template <typename T> struct impl_ISingleSelectMediaTrackList;
template <typename T> struct impl_ITimedMetadataTrack;
template <typename T> struct impl_ITimedMetadataTrack2;
template <typename T> struct impl_ITimedMetadataTrackError;
template <typename T> struct impl_ITimedMetadataTrackFactory;
template <typename T> struct impl_ITimedMetadataTrackFailedEventArgs;
template <typename T> struct impl_ITimedTextCue;
template <typename T> struct impl_ITimedTextLine;
template <typename T> struct impl_ITimedTextRegion;
template <typename T> struct impl_ITimedTextSource;
template <typename T> struct impl_ITimedTextSourceResolveResultEventArgs;
template <typename T> struct impl_ITimedTextSourceStatics;
template <typename T> struct impl_ITimedTextStyle;
template <typename T> struct impl_ITimedTextSubformat;
template <typename T> struct impl_IVideoStabilizationEffect;
template <typename T> struct impl_IVideoStabilizationEffectEnabledChangedEventArgs;
template <typename T> struct impl_IVideoStreamDescriptor;
template <typename T> struct impl_IVideoStreamDescriptorFactory;
template <typename T> struct impl_IVideoTrack;
template <typename T> struct impl_IVideoTrackOpenFailedEventArgs;
template <typename T> struct impl_IVideoTrackSupportInfo;

}

namespace Windows::Media::Core {

enum class AudioDecoderDegradation
{
    None = 0,
    DownmixTo2Channels = 1,
    DownmixTo6Channels = 2,
    DownmixTo8Channels = 3,
};

enum class AudioDecoderDegradationReason
{
    None = 0,
    LicensingRequirement = 1,
};

enum class FaceDetectionMode
{
    HighPerformance = 0,
    Balanced = 1,
    HighQuality = 2,
};

enum class MediaDecoderStatus
{
    FullySupported = 0,
    UnsupportedSubtype = 1,
    UnsupportedEncoderProperties = 2,
    Degraded = 3,
};

enum class MediaSourceState
{
    Initial = 0,
    Opening = 1,
    Opened = 2,
    Failed = 3,
    Closed = 4,
};

enum class MediaSourceStatus
{
    FullySupported = 0,
    Unknown = 1,
};

enum class MediaStreamSourceClosedReason
{
    Done = 0,
    UnknownError = 1,
    AppReportedError = 2,
    UnsupportedProtectionSystem = 3,
    ProtectionSystemFailure = 4,
    UnsupportedEncodingFormat = 5,
    MissingSampleRequestedEventHandler = 6,
};

enum class MediaStreamSourceErrorStatus
{
    Other = 0,
    OutOfMemory = 1,
    FailedToOpenFile = 2,
    FailedToConnectToServer = 3,
    ConnectionToServerLost = 4,
    UnspecifiedNetworkError = 5,
    DecodeError = 6,
    UnsupportedMediaFormat = 7,
};

enum class MediaTrackKind
{
    Audio = 0,
    Video = 1,
    TimedMetadata = 2,
};

enum class MseAppendMode
{
    Segments = 0,
    Sequence = 1,
};

enum class MseEndOfStreamStatus
{
    Success = 0,
    NetworkError = 1,
    DecodeError = 2,
    UnknownError = 3,
};

enum class MseReadyState
{
    Closed = 0,
    Open = 1,
    Ended = 2,
};

enum class TimedMetadataKind
{
    Caption = 0,
    Chapter = 1,
    Custom = 2,
    Data = 3,
    Description = 4,
    Subtitle = 5,
};

enum class TimedMetadataTrackErrorCode
{
    None = 0,
    DataFormatError = 1,
    NetworkError = 2,
    InternalError = 3,
};

enum class TimedTextDisplayAlignment
{
    Before = 0,
    After = 1,
    Center = 2,
};

enum class TimedTextFlowDirection
{
    LeftToRight = 0,
    RightToLeft = 1,
};

enum class TimedTextLineAlignment
{
    Start = 0,
    End = 1,
    Center = 2,
};

enum class TimedTextScrollMode
{
    Popon = 0,
    Rollup = 1,
};

enum class TimedTextUnit
{
    Pixels = 0,
    Percentage = 1,
};

enum class TimedTextWeight
{
    Normal = 400,
    Bold = 700,
};

enum class TimedTextWrapping
{
    NoWrap = 0,
    Wrap = 1,
};

enum class TimedTextWritingMode
{
    LeftRightTopBottom = 0,
    RightLeftTopBottom = 1,
    TopBottomRightLeft = 2,
    TopBottomLeftRight = 3,
    LeftRight = 4,
    RightLeft = 5,
    TopBottom = 6,
};

enum class VideoStabilizationEffectEnabledChangedReason
{
    Programmatic = 0,
    PixelRateTooHigh = 1,
    RunningSlowly = 2,
};

}

}
