// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Playback {

struct IBackgroundMediaPlayerStatics;
struct ICurrentMediaPlaybackItemChangedEventArgs;
struct IMediaBreak;
struct IMediaBreakEndedEventArgs;
struct IMediaBreakFactory;
struct IMediaBreakManager;
struct IMediaBreakSchedule;
struct IMediaBreakSeekedOverEventArgs;
struct IMediaBreakSkippedEventArgs;
struct IMediaBreakStartedEventArgs;
struct IMediaEnginePlaybackSource;
struct IMediaItemDisplayProperties;
struct IMediaPlaybackCommandManager;
struct IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs;
struct IMediaPlaybackCommandManagerCommandBehavior;
struct IMediaPlaybackCommandManagerFastForwardReceivedEventArgs;
struct IMediaPlaybackCommandManagerNextReceivedEventArgs;
struct IMediaPlaybackCommandManagerPauseReceivedEventArgs;
struct IMediaPlaybackCommandManagerPlayReceivedEventArgs;
struct IMediaPlaybackCommandManagerPositionReceivedEventArgs;
struct IMediaPlaybackCommandManagerPreviousReceivedEventArgs;
struct IMediaPlaybackCommandManagerRateReceivedEventArgs;
struct IMediaPlaybackCommandManagerRewindReceivedEventArgs;
struct IMediaPlaybackCommandManagerShuffleReceivedEventArgs;
struct IMediaPlaybackItem;
struct IMediaPlaybackItem2;
struct IMediaPlaybackItemError;
struct IMediaPlaybackItemFactory;
struct IMediaPlaybackItemFactory2;
struct IMediaPlaybackItemFailedEventArgs;
struct IMediaPlaybackItemOpenedEventArgs;
struct IMediaPlaybackItemStatics;
struct IMediaPlaybackList;
struct IMediaPlaybackList2;
struct IMediaPlaybackSession;
struct IMediaPlaybackSource;
struct IMediaPlaybackTimedMetadataTrackList;
struct IMediaPlayer;
struct IMediaPlayer2;
struct IMediaPlayer3;
struct IMediaPlayer4;
struct IMediaPlayerDataReceivedEventArgs;
struct IMediaPlayerEffects;
struct IMediaPlayerEffects2;
struct IMediaPlayerFailedEventArgs;
struct IMediaPlayerRateChangedEventArgs;
struct IMediaPlayerSource;
struct IMediaPlayerSource2;
struct IMediaPlayerSurface;
struct IPlaybackMediaMarker;
struct IPlaybackMediaMarkerFactory;
struct IPlaybackMediaMarkerReachedEventArgs;
struct IPlaybackMediaMarkerSequence;
struct ITimedMetadataPresentationModeChangedEventArgs;
struct CurrentMediaPlaybackItemChangedEventArgs;
struct MediaBreak;
struct MediaBreakEndedEventArgs;
struct MediaBreakManager;
struct MediaBreakSchedule;
struct MediaBreakSeekedOverEventArgs;
struct MediaBreakSkippedEventArgs;
struct MediaBreakStartedEventArgs;
struct MediaItemDisplayProperties;
struct MediaPlaybackAudioTrackList;
struct MediaPlaybackCommandManager;
struct MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs;
struct MediaPlaybackCommandManagerCommandBehavior;
struct MediaPlaybackCommandManagerFastForwardReceivedEventArgs;
struct MediaPlaybackCommandManagerNextReceivedEventArgs;
struct MediaPlaybackCommandManagerPauseReceivedEventArgs;
struct MediaPlaybackCommandManagerPlayReceivedEventArgs;
struct MediaPlaybackCommandManagerPositionReceivedEventArgs;
struct MediaPlaybackCommandManagerPreviousReceivedEventArgs;
struct MediaPlaybackCommandManagerRateReceivedEventArgs;
struct MediaPlaybackCommandManagerRewindReceivedEventArgs;
struct MediaPlaybackCommandManagerShuffleReceivedEventArgs;
struct MediaPlaybackItem;
struct MediaPlaybackItemError;
struct MediaPlaybackItemFailedEventArgs;
struct MediaPlaybackItemOpenedEventArgs;
struct MediaPlaybackList;
struct MediaPlaybackSession;
struct MediaPlaybackTimedMetadataTrackList;
struct MediaPlaybackVideoTrackList;
struct MediaPlayer;
struct MediaPlayerDataReceivedEventArgs;
struct MediaPlayerFailedEventArgs;
struct MediaPlayerRateChangedEventArgs;
struct MediaPlayerSurface;
struct PlaybackMediaMarker;
struct PlaybackMediaMarkerReachedEventArgs;
struct PlaybackMediaMarkerSequence;
struct TimedMetadataPresentationModeChangedEventArgs;

}

namespace Windows::Media::Playback {

struct IBackgroundMediaPlayerStatics;
struct ICurrentMediaPlaybackItemChangedEventArgs;
struct IMediaBreak;
struct IMediaBreakEndedEventArgs;
struct IMediaBreakFactory;
struct IMediaBreakManager;
struct IMediaBreakSchedule;
struct IMediaBreakSeekedOverEventArgs;
struct IMediaBreakSkippedEventArgs;
struct IMediaBreakStartedEventArgs;
struct IMediaEnginePlaybackSource;
struct IMediaItemDisplayProperties;
struct IMediaPlaybackCommandManager;
struct IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs;
struct IMediaPlaybackCommandManagerCommandBehavior;
struct IMediaPlaybackCommandManagerFastForwardReceivedEventArgs;
struct IMediaPlaybackCommandManagerNextReceivedEventArgs;
struct IMediaPlaybackCommandManagerPauseReceivedEventArgs;
struct IMediaPlaybackCommandManagerPlayReceivedEventArgs;
struct IMediaPlaybackCommandManagerPositionReceivedEventArgs;
struct IMediaPlaybackCommandManagerPreviousReceivedEventArgs;
struct IMediaPlaybackCommandManagerRateReceivedEventArgs;
struct IMediaPlaybackCommandManagerRewindReceivedEventArgs;
struct IMediaPlaybackCommandManagerShuffleReceivedEventArgs;
struct IMediaPlaybackItem;
struct IMediaPlaybackItem2;
struct IMediaPlaybackItemError;
struct IMediaPlaybackItemFactory;
struct IMediaPlaybackItemFactory2;
struct IMediaPlaybackItemFailedEventArgs;
struct IMediaPlaybackItemOpenedEventArgs;
struct IMediaPlaybackItemStatics;
struct IMediaPlaybackList;
struct IMediaPlaybackList2;
struct IMediaPlaybackSession;
struct IMediaPlaybackSource;
struct IMediaPlaybackTimedMetadataTrackList;
struct IMediaPlayer;
struct IMediaPlayer2;
struct IMediaPlayer3;
struct IMediaPlayer4;
struct IMediaPlayerDataReceivedEventArgs;
struct IMediaPlayerEffects;
struct IMediaPlayerEffects2;
struct IMediaPlayerFailedEventArgs;
struct IMediaPlayerRateChangedEventArgs;
struct IMediaPlayerSource;
struct IMediaPlayerSource2;
struct IMediaPlayerSurface;
struct IPlaybackMediaMarker;
struct IPlaybackMediaMarkerFactory;
struct IPlaybackMediaMarkerReachedEventArgs;
struct IPlaybackMediaMarkerSequence;
struct ITimedMetadataPresentationModeChangedEventArgs;
struct BackgroundMediaPlayer;
struct CurrentMediaPlaybackItemChangedEventArgs;
struct MediaBreak;
struct MediaBreakEndedEventArgs;
struct MediaBreakManager;
struct MediaBreakSchedule;
struct MediaBreakSeekedOverEventArgs;
struct MediaBreakSkippedEventArgs;
struct MediaBreakStartedEventArgs;
struct MediaItemDisplayProperties;
struct MediaPlaybackAudioTrackList;
struct MediaPlaybackCommandManager;
struct MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs;
struct MediaPlaybackCommandManagerCommandBehavior;
struct MediaPlaybackCommandManagerFastForwardReceivedEventArgs;
struct MediaPlaybackCommandManagerNextReceivedEventArgs;
struct MediaPlaybackCommandManagerPauseReceivedEventArgs;
struct MediaPlaybackCommandManagerPlayReceivedEventArgs;
struct MediaPlaybackCommandManagerPositionReceivedEventArgs;
struct MediaPlaybackCommandManagerPreviousReceivedEventArgs;
struct MediaPlaybackCommandManagerRateReceivedEventArgs;
struct MediaPlaybackCommandManagerRewindReceivedEventArgs;
struct MediaPlaybackCommandManagerShuffleReceivedEventArgs;
struct MediaPlaybackItem;
struct MediaPlaybackItemError;
struct MediaPlaybackItemFailedEventArgs;
struct MediaPlaybackItemOpenedEventArgs;
struct MediaPlaybackList;
struct MediaPlaybackSession;
struct MediaPlaybackTimedMetadataTrackList;
struct MediaPlaybackVideoTrackList;
struct MediaPlayer;
struct MediaPlayerDataReceivedEventArgs;
struct MediaPlayerFailedEventArgs;
struct MediaPlayerRateChangedEventArgs;
struct MediaPlayerSurface;
struct PlaybackMediaMarker;
struct PlaybackMediaMarkerReachedEventArgs;
struct PlaybackMediaMarkerSequence;
struct TimedMetadataPresentationModeChangedEventArgs;

}

namespace Windows::Media::Playback {

template <typename T> struct impl_IBackgroundMediaPlayerStatics;
template <typename T> struct impl_ICurrentMediaPlaybackItemChangedEventArgs;
template <typename T> struct impl_IMediaBreak;
template <typename T> struct impl_IMediaBreakEndedEventArgs;
template <typename T> struct impl_IMediaBreakFactory;
template <typename T> struct impl_IMediaBreakManager;
template <typename T> struct impl_IMediaBreakSchedule;
template <typename T> struct impl_IMediaBreakSeekedOverEventArgs;
template <typename T> struct impl_IMediaBreakSkippedEventArgs;
template <typename T> struct impl_IMediaBreakStartedEventArgs;
template <typename T> struct impl_IMediaEnginePlaybackSource;
template <typename T> struct impl_IMediaItemDisplayProperties;
template <typename T> struct impl_IMediaPlaybackCommandManager;
template <typename T> struct impl_IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs;
template <typename T> struct impl_IMediaPlaybackCommandManagerCommandBehavior;
template <typename T> struct impl_IMediaPlaybackCommandManagerFastForwardReceivedEventArgs;
template <typename T> struct impl_IMediaPlaybackCommandManagerNextReceivedEventArgs;
template <typename T> struct impl_IMediaPlaybackCommandManagerPauseReceivedEventArgs;
template <typename T> struct impl_IMediaPlaybackCommandManagerPlayReceivedEventArgs;
template <typename T> struct impl_IMediaPlaybackCommandManagerPositionReceivedEventArgs;
template <typename T> struct impl_IMediaPlaybackCommandManagerPreviousReceivedEventArgs;
template <typename T> struct impl_IMediaPlaybackCommandManagerRateReceivedEventArgs;
template <typename T> struct impl_IMediaPlaybackCommandManagerRewindReceivedEventArgs;
template <typename T> struct impl_IMediaPlaybackCommandManagerShuffleReceivedEventArgs;
template <typename T> struct impl_IMediaPlaybackItem;
template <typename T> struct impl_IMediaPlaybackItem2;
template <typename T> struct impl_IMediaPlaybackItemError;
template <typename T> struct impl_IMediaPlaybackItemFactory;
template <typename T> struct impl_IMediaPlaybackItemFactory2;
template <typename T> struct impl_IMediaPlaybackItemFailedEventArgs;
template <typename T> struct impl_IMediaPlaybackItemOpenedEventArgs;
template <typename T> struct impl_IMediaPlaybackItemStatics;
template <typename T> struct impl_IMediaPlaybackList;
template <typename T> struct impl_IMediaPlaybackList2;
template <typename T> struct impl_IMediaPlaybackSession;
template <typename T> struct impl_IMediaPlaybackSource;
template <typename T> struct impl_IMediaPlaybackTimedMetadataTrackList;
template <typename T> struct impl_IMediaPlayer;
template <typename T> struct impl_IMediaPlayer2;
template <typename T> struct impl_IMediaPlayer3;
template <typename T> struct impl_IMediaPlayer4;
template <typename T> struct impl_IMediaPlayerDataReceivedEventArgs;
template <typename T> struct impl_IMediaPlayerEffects;
template <typename T> struct impl_IMediaPlayerEffects2;
template <typename T> struct impl_IMediaPlayerFailedEventArgs;
template <typename T> struct impl_IMediaPlayerRateChangedEventArgs;
template <typename T> struct impl_IMediaPlayerSource;
template <typename T> struct impl_IMediaPlayerSource2;
template <typename T> struct impl_IMediaPlayerSurface;
template <typename T> struct impl_IPlaybackMediaMarker;
template <typename T> struct impl_IPlaybackMediaMarkerFactory;
template <typename T> struct impl_IPlaybackMediaMarkerReachedEventArgs;
template <typename T> struct impl_IPlaybackMediaMarkerSequence;
template <typename T> struct impl_ITimedMetadataPresentationModeChangedEventArgs;

}

namespace Windows::Media::Playback {

enum class FailedMediaStreamKind
{
    Unknown = 0,
    Audio = 1,
    Video = 2,
};

enum class MediaBreakInsertionMethod
{
    Interrupt = 0,
    Replace = 1,
};

enum class MediaCommandEnablingRule
{
    Auto = 0,
    Always = 1,
    Never = 2,
};

enum class MediaPlaybackItemErrorCode
{
    None = 0,
    Aborted = 1,
    NetworkError = 2,
    DecodeError = 3,
    SourceNotSupportedError = 4,
    EncryptionError = 5,
};

enum class MediaPlaybackState
{
    None = 0,
    Opening = 1,
    Buffering = 2,
    Playing = 3,
    Paused = 4,
};

enum class MediaPlayerAudioCategory
{
    Other = 0,
    Communications = 3,
    Alerts = 4,
    SoundEffects = 5,
    GameEffects = 6,
    GameMedia = 7,
    GameChat = 8,
    Speech = 9,
    Movie = 10,
    Media = 11,
};

enum class MediaPlayerAudioDeviceType
{
    Console = 0,
    Multimedia = 1,
    Communications = 2,
};

enum class MediaPlayerError
{
    Unknown = 0,
    Aborted = 1,
    NetworkError = 2,
    DecodingError = 3,
    SourceNotSupported = 4,
};

enum class [[deprecated("Use MediaPlaybackState instead of MediaPlayerState.  For more info, see MSDN.")]] MediaPlayerState
{
    Closed = 0,
    Opening = 1,
    Buffering = 2,
    Playing = 3,
    Paused = 4,
    Stopped = 5,
};

enum class StereoscopicVideoRenderMode
{
    Mono = 0,
    Stereo = 1,
};

enum class TimedMetadataTrackPresentationMode
{
    Disabled = 0,
    Hidden = 1,
    ApplicationPresented = 2,
    PlatformPresented = 3,
};

}

}
