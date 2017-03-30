// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media {

struct WINRT_EBO AudioBuffer :
    Windows::Media::IAudioBuffer
{
    AudioBuffer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AudioFrame :
    Windows::Media::IAudioFrame
{
    AudioFrame(std::nullptr_t) noexcept {}
    AudioFrame(uint32_t capacity);
};

struct WINRT_EBO AutoRepeatModeChangeRequestedEventArgs :
    Windows::Media::IAutoRepeatModeChangeRequestedEventArgs
{
    AutoRepeatModeChangeRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ImageDisplayProperties :
    Windows::Media::IImageDisplayProperties
{
    ImageDisplayProperties(std::nullptr_t) noexcept {}
};

struct [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] MediaControl
{
    MediaControl() = delete;
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static event_token SoundLevelChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using SoundLevelChanged_revoker = factory_event_revoker<IMediaControl>;
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static SoundLevelChanged_revoker SoundLevelChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static void SoundLevelChanged(event_token cookie);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static event_token PlayPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using PlayPressed_revoker = factory_event_revoker<IMediaControl>;
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static PlayPressed_revoker PlayPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static void PlayPressed(event_token cookie);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static event_token PausePressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using PausePressed_revoker = factory_event_revoker<IMediaControl>;
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static PausePressed_revoker PausePressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static void PausePressed(event_token cookie);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static event_token StopPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using StopPressed_revoker = factory_event_revoker<IMediaControl>;
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static StopPressed_revoker StopPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static void StopPressed(event_token cookie);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static event_token PlayPauseTogglePressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using PlayPauseTogglePressed_revoker = factory_event_revoker<IMediaControl>;
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static PlayPauseTogglePressed_revoker PlayPauseTogglePressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static void PlayPauseTogglePressed(event_token cookie);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static event_token RecordPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using RecordPressed_revoker = factory_event_revoker<IMediaControl>;
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static RecordPressed_revoker RecordPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static void RecordPressed(event_token cookie);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static event_token NextTrackPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using NextTrackPressed_revoker = factory_event_revoker<IMediaControl>;
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static NextTrackPressed_revoker NextTrackPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static void NextTrackPressed(event_token cookie);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static event_token PreviousTrackPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using PreviousTrackPressed_revoker = factory_event_revoker<IMediaControl>;
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static PreviousTrackPressed_revoker PreviousTrackPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static void PreviousTrackPressed(event_token cookie);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static event_token FastForwardPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using FastForwardPressed_revoker = factory_event_revoker<IMediaControl>;
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static FastForwardPressed_revoker FastForwardPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static void FastForwardPressed(event_token cookie);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static event_token RewindPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using RewindPressed_revoker = factory_event_revoker<IMediaControl>;
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static RewindPressed_revoker RewindPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static void RewindPressed(event_token cookie);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static event_token ChannelUpPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using ChannelUpPressed_revoker = factory_event_revoker<IMediaControl>;
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static ChannelUpPressed_revoker ChannelUpPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static void ChannelUpPressed(event_token cookie);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static event_token ChannelDownPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using ChannelDownPressed_revoker = factory_event_revoker<IMediaControl>;
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static ChannelDownPressed_revoker ChannelDownPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static void ChannelDownPressed(event_token cookie);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static Windows::Media::SoundLevel SoundLevel();
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static void TrackName(hstring_view value);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static hstring TrackName();
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static void ArtistName(hstring_view value);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static hstring ArtistName();
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static void IsPlaying(bool value);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static bool IsPlaying();
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static void AlbumArt(const Windows::Foundation::Uri & value);
    [[deprecated("MediaControl may be altered or unavailable for releases after Windows 8.1. Instead, use SystemMediaTransportControls.")]] static Windows::Foundation::Uri AlbumArt();
};

struct WINRT_EBO MediaExtensionManager :
    Windows::Media::IMediaExtensionManager
{
    MediaExtensionManager(std::nullptr_t) noexcept {}
    MediaExtensionManager();
};

struct MediaMarkerTypes
{
    MediaMarkerTypes() = delete;
    static hstring Bookmark();
};

struct WINRT_EBO MediaProcessingTriggerDetails :
    Windows::Media::IMediaProcessingTriggerDetails
{
    MediaProcessingTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaTimelineController :
    Windows::Media::IMediaTimelineController
{
    MediaTimelineController(std::nullptr_t) noexcept {}
    MediaTimelineController();
};

struct WINRT_EBO MusicDisplayProperties :
    Windows::Media::IMusicDisplayProperties,
    impl::require<MusicDisplayProperties, Windows::Media::IMusicDisplayProperties2, Windows::Media::IMusicDisplayProperties3>
{
    MusicDisplayProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PlaybackPositionChangeRequestedEventArgs :
    Windows::Media::IPlaybackPositionChangeRequestedEventArgs
{
    PlaybackPositionChangeRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PlaybackRateChangeRequestedEventArgs :
    Windows::Media::IPlaybackRateChangeRequestedEventArgs
{
    PlaybackRateChangeRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ShuffleEnabledChangeRequestedEventArgs :
    Windows::Media::IShuffleEnabledChangeRequestedEventArgs
{
    ShuffleEnabledChangeRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SystemMediaTransportControls :
    Windows::Media::ISystemMediaTransportControls,
    impl::require<SystemMediaTransportControls, Windows::Media::ISystemMediaTransportControls2>
{
    SystemMediaTransportControls(std::nullptr_t) noexcept {}
    static Windows::Media::SystemMediaTransportControls GetForCurrentView();
};

struct WINRT_EBO SystemMediaTransportControlsButtonPressedEventArgs :
    Windows::Media::ISystemMediaTransportControlsButtonPressedEventArgs
{
    SystemMediaTransportControlsButtonPressedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SystemMediaTransportControlsDisplayUpdater :
    Windows::Media::ISystemMediaTransportControlsDisplayUpdater
{
    SystemMediaTransportControlsDisplayUpdater(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SystemMediaTransportControlsPropertyChangedEventArgs :
    Windows::Media::ISystemMediaTransportControlsPropertyChangedEventArgs
{
    SystemMediaTransportControlsPropertyChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SystemMediaTransportControlsTimelineProperties :
    Windows::Media::ISystemMediaTransportControlsTimelineProperties
{
    SystemMediaTransportControlsTimelineProperties(std::nullptr_t) noexcept {}
    SystemMediaTransportControlsTimelineProperties();
};

struct WINRT_EBO VideoDisplayProperties :
    Windows::Media::IVideoDisplayProperties,
    impl::require<VideoDisplayProperties, Windows::Media::IVideoDisplayProperties2>
{
    VideoDisplayProperties(std::nullptr_t) noexcept {}
};

struct VideoEffects
{
    VideoEffects() = delete;
    static hstring VideoStabilization();
};

struct WINRT_EBO VideoFrame :
    Windows::Media::IVideoFrame
{
    VideoFrame(std::nullptr_t) noexcept {}
    VideoFrame(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height);
    VideoFrame(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::BitmapAlphaMode alpha);
};

}

}
