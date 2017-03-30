// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media {

struct IAudioBuffer;
struct IAudioFrame;
struct IAudioFrameFactory;
struct IAutoRepeatModeChangeRequestedEventArgs;
struct IImageDisplayProperties;
struct IMediaControl;
struct IMediaExtension;
struct IMediaExtensionManager;
struct IMediaFrame;
struct IMediaMarker;
struct IMediaMarkerTypesStatics;
struct IMediaMarkers;
struct IMediaProcessingTriggerDetails;
struct IMediaTimelineController;
struct IMusicDisplayProperties;
struct IMusicDisplayProperties2;
struct IMusicDisplayProperties3;
struct IPlaybackPositionChangeRequestedEventArgs;
struct IPlaybackRateChangeRequestedEventArgs;
struct IShuffleEnabledChangeRequestedEventArgs;
struct ISystemMediaTransportControls;
struct ISystemMediaTransportControls2;
struct ISystemMediaTransportControlsButtonPressedEventArgs;
struct ISystemMediaTransportControlsDisplayUpdater;
struct ISystemMediaTransportControlsPropertyChangedEventArgs;
struct ISystemMediaTransportControlsStatics;
struct ISystemMediaTransportControlsTimelineProperties;
struct IVideoDisplayProperties;
struct IVideoDisplayProperties2;
struct IVideoEffectsStatics;
struct IVideoFrame;
struct IVideoFrameFactory;
struct AudioBuffer;
struct AudioFrame;
struct AutoRepeatModeChangeRequestedEventArgs;
struct ImageDisplayProperties;
struct MediaExtensionManager;
struct MediaProcessingTriggerDetails;
struct MediaTimelineController;
struct MusicDisplayProperties;
struct PlaybackPositionChangeRequestedEventArgs;
struct PlaybackRateChangeRequestedEventArgs;
struct ShuffleEnabledChangeRequestedEventArgs;
struct SystemMediaTransportControls;
struct SystemMediaTransportControlsButtonPressedEventArgs;
struct SystemMediaTransportControlsDisplayUpdater;
struct SystemMediaTransportControlsPropertyChangedEventArgs;
struct SystemMediaTransportControlsTimelineProperties;
struct VideoDisplayProperties;
struct VideoFrame;

}

namespace Windows::Media {

struct IAudioBuffer;
struct IAudioFrame;
struct IAudioFrameFactory;
struct IAutoRepeatModeChangeRequestedEventArgs;
struct IImageDisplayProperties;
struct IMediaControl;
struct IMediaExtension;
struct IMediaExtensionManager;
struct IMediaFrame;
struct IMediaMarker;
struct IMediaMarkerTypesStatics;
struct IMediaMarkers;
struct IMediaProcessingTriggerDetails;
struct IMediaTimelineController;
struct IMusicDisplayProperties;
struct IMusicDisplayProperties2;
struct IMusicDisplayProperties3;
struct IPlaybackPositionChangeRequestedEventArgs;
struct IPlaybackRateChangeRequestedEventArgs;
struct IShuffleEnabledChangeRequestedEventArgs;
struct ISystemMediaTransportControls;
struct ISystemMediaTransportControls2;
struct ISystemMediaTransportControlsButtonPressedEventArgs;
struct ISystemMediaTransportControlsDisplayUpdater;
struct ISystemMediaTransportControlsPropertyChangedEventArgs;
struct ISystemMediaTransportControlsStatics;
struct ISystemMediaTransportControlsTimelineProperties;
struct IVideoDisplayProperties;
struct IVideoDisplayProperties2;
struct IVideoEffectsStatics;
struct IVideoFrame;
struct IVideoFrameFactory;
struct AudioBuffer;
struct AudioFrame;
struct AutoRepeatModeChangeRequestedEventArgs;
struct ImageDisplayProperties;
struct MediaControl;
struct MediaExtensionManager;
struct MediaMarkerTypes;
struct MediaProcessingTriggerDetails;
struct MediaTimelineController;
struct MusicDisplayProperties;
struct PlaybackPositionChangeRequestedEventArgs;
struct PlaybackRateChangeRequestedEventArgs;
struct ShuffleEnabledChangeRequestedEventArgs;
struct SystemMediaTransportControls;
struct SystemMediaTransportControlsButtonPressedEventArgs;
struct SystemMediaTransportControlsDisplayUpdater;
struct SystemMediaTransportControlsPropertyChangedEventArgs;
struct SystemMediaTransportControlsTimelineProperties;
struct VideoDisplayProperties;
struct VideoEffects;
struct VideoFrame;

}

namespace Windows::Media {

template <typename T> struct impl_IAudioBuffer;
template <typename T> struct impl_IAudioFrame;
template <typename T> struct impl_IAudioFrameFactory;
template <typename T> struct impl_IAutoRepeatModeChangeRequestedEventArgs;
template <typename T> struct impl_IImageDisplayProperties;
template <typename T> struct impl_IMediaControl;
template <typename T> struct impl_IMediaExtension;
template <typename T> struct impl_IMediaExtensionManager;
template <typename T> struct impl_IMediaFrame;
template <typename T> struct impl_IMediaMarker;
template <typename T> struct impl_IMediaMarkerTypesStatics;
template <typename T> struct impl_IMediaMarkers;
template <typename T> struct impl_IMediaProcessingTriggerDetails;
template <typename T> struct impl_IMediaTimelineController;
template <typename T> struct impl_IMusicDisplayProperties;
template <typename T> struct impl_IMusicDisplayProperties2;
template <typename T> struct impl_IMusicDisplayProperties3;
template <typename T> struct impl_IPlaybackPositionChangeRequestedEventArgs;
template <typename T> struct impl_IPlaybackRateChangeRequestedEventArgs;
template <typename T> struct impl_IShuffleEnabledChangeRequestedEventArgs;
template <typename T> struct impl_ISystemMediaTransportControls;
template <typename T> struct impl_ISystemMediaTransportControls2;
template <typename T> struct impl_ISystemMediaTransportControlsButtonPressedEventArgs;
template <typename T> struct impl_ISystemMediaTransportControlsDisplayUpdater;
template <typename T> struct impl_ISystemMediaTransportControlsPropertyChangedEventArgs;
template <typename T> struct impl_ISystemMediaTransportControlsStatics;
template <typename T> struct impl_ISystemMediaTransportControlsTimelineProperties;
template <typename T> struct impl_IVideoDisplayProperties;
template <typename T> struct impl_IVideoDisplayProperties2;
template <typename T> struct impl_IVideoEffectsStatics;
template <typename T> struct impl_IVideoFrame;
template <typename T> struct impl_IVideoFrameFactory;

}

namespace Windows::Media {

enum class AudioBufferAccessMode
{
    Read = 0,
    ReadWrite = 1,
    Write = 2,
};

enum class AudioProcessing
{
    Default = 0,
    Raw = 1,
};

enum class MediaPlaybackAutoRepeatMode
{
    None = 0,
    Track = 1,
    List = 2,
};

enum class MediaPlaybackStatus
{
    Closed = 0,
    Changing = 1,
    Stopped = 2,
    Playing = 3,
    Paused = 4,
};

enum class MediaPlaybackType
{
    Unknown = 0,
    Music = 1,
    Video = 2,
    Image = 3,
};

enum class MediaTimelineControllerState
{
    Paused = 0,
    Running = 1,
};

enum class SoundLevel
{
    Muted = 0,
    Low = 1,
    Full = 2,
};

enum class SystemMediaTransportControlsButton
{
    Play = 0,
    Pause = 1,
    Stop = 2,
    Record = 3,
    FastForward = 4,
    Rewind = 5,
    Next = 6,
    Previous = 7,
    ChannelUp = 8,
    ChannelDown = 9,
};

enum class SystemMediaTransportControlsProperty
{
    SoundLevel = 0,
};

}

}
