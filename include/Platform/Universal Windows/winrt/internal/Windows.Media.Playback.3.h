// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Playback.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::Playback {

struct BackgroundMediaPlayer
{
    BackgroundMediaPlayer() = delete;
    static Windows::Media::Playback::MediaPlayer Current();
    static event_token MessageReceivedFromBackground(const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> & value);
    using MessageReceivedFromBackground_revoker = factory_event_revoker<IBackgroundMediaPlayerStatics>;
    static MessageReceivedFromBackground_revoker MessageReceivedFromBackground(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> & value);
    static void MessageReceivedFromBackground(event_token token);
    static event_token MessageReceivedFromForeground(const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> & value);
    using MessageReceivedFromForeground_revoker = factory_event_revoker<IBackgroundMediaPlayerStatics>;
    static MessageReceivedFromForeground_revoker MessageReceivedFromForeground(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> & value);
    static void MessageReceivedFromForeground(event_token token);
    static void SendMessageToBackground(const Windows::Foundation::Collections::ValueSet & value);
    static void SendMessageToForeground(const Windows::Foundation::Collections::ValueSet & value);
    static bool IsMediaPlaying();
    static void Shutdown();
};

struct WINRT_EBO CurrentMediaPlaybackItemChangedEventArgs :
    Windows::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs
{
    CurrentMediaPlaybackItemChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaBreak :
    Windows::Media::Playback::IMediaBreak
{
    MediaBreak(std::nullptr_t) noexcept {}
    MediaBreak(Windows::Media::Playback::MediaBreakInsertionMethod insertionMethod);
    MediaBreak(Windows::Media::Playback::MediaBreakInsertionMethod insertionMethod, const Windows::Foundation::TimeSpan & presentationPosition);
};

struct WINRT_EBO MediaBreakEndedEventArgs :
    Windows::Media::Playback::IMediaBreakEndedEventArgs
{
    MediaBreakEndedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaBreakManager :
    Windows::Media::Playback::IMediaBreakManager
{
    MediaBreakManager(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaBreakSchedule :
    Windows::Media::Playback::IMediaBreakSchedule
{
    MediaBreakSchedule(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaBreakSeekedOverEventArgs :
    Windows::Media::Playback::IMediaBreakSeekedOverEventArgs
{
    MediaBreakSeekedOverEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaBreakSkippedEventArgs :
    Windows::Media::Playback::IMediaBreakSkippedEventArgs
{
    MediaBreakSkippedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaBreakStartedEventArgs :
    Windows::Media::Playback::IMediaBreakStartedEventArgs
{
    MediaBreakStartedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaItemDisplayProperties :
    Windows::Media::Playback::IMediaItemDisplayProperties
{
    MediaItemDisplayProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackAudioTrackList :
    Windows::Foundation::Collections::IVectorView<Windows::Media::Core::AudioTrack>,
    impl::require<MediaPlaybackAudioTrackList, Windows::Media::Core::ISingleSelectMediaTrackList>
{
    MediaPlaybackAudioTrackList(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackCommandManager :
    Windows::Media::Playback::IMediaPlaybackCommandManager
{
    MediaPlaybackCommandManager(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs :
    Windows::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs
{
    MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackCommandManagerCommandBehavior :
    Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior
{
    MediaPlaybackCommandManagerCommandBehavior(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackCommandManagerFastForwardReceivedEventArgs :
    Windows::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs
{
    MediaPlaybackCommandManagerFastForwardReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackCommandManagerNextReceivedEventArgs :
    Windows::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs
{
    MediaPlaybackCommandManagerNextReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackCommandManagerPauseReceivedEventArgs :
    Windows::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs
{
    MediaPlaybackCommandManagerPauseReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackCommandManagerPlayReceivedEventArgs :
    Windows::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs
{
    MediaPlaybackCommandManagerPlayReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackCommandManagerPositionReceivedEventArgs :
    Windows::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs
{
    MediaPlaybackCommandManagerPositionReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackCommandManagerPreviousReceivedEventArgs :
    Windows::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs
{
    MediaPlaybackCommandManagerPreviousReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackCommandManagerRateReceivedEventArgs :
    Windows::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs
{
    MediaPlaybackCommandManagerRateReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackCommandManagerRewindReceivedEventArgs :
    Windows::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs
{
    MediaPlaybackCommandManagerRewindReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackCommandManagerShuffleReceivedEventArgs :
    Windows::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs
{
    MediaPlaybackCommandManagerShuffleReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackItem :
    Windows::Media::Playback::IMediaPlaybackItem,
    impl::require<MediaPlaybackItem, Windows::Media::Playback::IMediaPlaybackItem2>
{
    MediaPlaybackItem(std::nullptr_t) noexcept {}
    MediaPlaybackItem(const Windows::Media::Core::MediaSource & source);
    MediaPlaybackItem(const Windows::Media::Core::MediaSource & source, const Windows::Foundation::TimeSpan & startTime);
    MediaPlaybackItem(const Windows::Media::Core::MediaSource & source, const Windows::Foundation::TimeSpan & startTime, const Windows::Foundation::TimeSpan & durationLimit);
    static Windows::Media::Playback::MediaPlaybackItem FindFromMediaSource(const Windows::Media::Core::MediaSource & source);
};

struct WINRT_EBO MediaPlaybackItemError :
    Windows::Media::Playback::IMediaPlaybackItemError
{
    MediaPlaybackItemError(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackItemFailedEventArgs :
    Windows::Media::Playback::IMediaPlaybackItemFailedEventArgs
{
    MediaPlaybackItemFailedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackItemOpenedEventArgs :
    Windows::Media::Playback::IMediaPlaybackItemOpenedEventArgs
{
    MediaPlaybackItemOpenedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackList :
    Windows::Media::Playback::IMediaPlaybackList,
    impl::require<MediaPlaybackList, Windows::Media::Playback::IMediaPlaybackList2>
{
    MediaPlaybackList(std::nullptr_t) noexcept {}
    MediaPlaybackList();
};

struct WINRT_EBO MediaPlaybackSession :
    Windows::Media::Playback::IMediaPlaybackSession
{
    MediaPlaybackSession(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackTimedMetadataTrackList :
    Windows::Foundation::Collections::IVectorView<Windows::Media::Core::TimedMetadataTrack>,
    impl::require<MediaPlaybackTimedMetadataTrackList, Windows::Media::Playback::IMediaPlaybackTimedMetadataTrackList>
{
    MediaPlaybackTimedMetadataTrackList(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlaybackVideoTrackList :
    Windows::Foundation::Collections::IVectorView<Windows::Media::Core::VideoTrack>,
    impl::require<MediaPlaybackVideoTrackList, Windows::Media::Core::ISingleSelectMediaTrackList>
{
    MediaPlaybackVideoTrackList(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlayer :
    Windows::Media::Playback::IMediaPlayer,
    impl::require<MediaPlayer, Windows::Foundation::IClosable, Windows::Media::Playback::IMediaPlayer2, Windows::Media::Playback::IMediaPlayer3, Windows::Media::Playback::IMediaPlayer4, Windows::Media::Playback::IMediaPlayerSource, Windows::Media::Playback::IMediaPlayerSource2, Windows::Media::Playback::IMediaPlayerEffects, Windows::Media::Playback::IMediaPlayerEffects2>
{
    MediaPlayer(std::nullptr_t) noexcept {}
    MediaPlayer();
};

struct WINRT_EBO MediaPlayerDataReceivedEventArgs :
    Windows::Media::Playback::IMediaPlayerDataReceivedEventArgs
{
    MediaPlayerDataReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlayerFailedEventArgs :
    Windows::Media::Playback::IMediaPlayerFailedEventArgs
{
    MediaPlayerFailedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlayerRateChangedEventArgs :
    Windows::Media::Playback::IMediaPlayerRateChangedEventArgs
{
    MediaPlayerRateChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaPlayerSurface :
    Windows::Media::Playback::IMediaPlayerSurface,
    impl::require<MediaPlayerSurface, Windows::Foundation::IClosable>
{
    MediaPlayerSurface(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PlaybackMediaMarker :
    Windows::Media::Playback::IPlaybackMediaMarker
{
    PlaybackMediaMarker(std::nullptr_t) noexcept {}
    PlaybackMediaMarker(const Windows::Foundation::TimeSpan & value);
    PlaybackMediaMarker(const Windows::Foundation::TimeSpan & value, hstring_view mediaMarketType, hstring_view text);
};

struct WINRT_EBO PlaybackMediaMarkerReachedEventArgs :
    Windows::Media::Playback::IPlaybackMediaMarkerReachedEventArgs
{
    PlaybackMediaMarkerReachedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PlaybackMediaMarkerSequence :
    Windows::Media::Playback::IPlaybackMediaMarkerSequence
{
    PlaybackMediaMarkerSequence(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TimedMetadataPresentationModeChangedEventArgs :
    Windows::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs
{
    TimedMetadataPresentationModeChangedEventArgs(std::nullptr_t) noexcept {}
};

}

}
