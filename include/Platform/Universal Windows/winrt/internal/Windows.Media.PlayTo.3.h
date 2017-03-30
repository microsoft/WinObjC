// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.PlayTo.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::PlayTo {

struct WINRT_EBO CurrentTimeChangeRequestedEventArgs :
    Windows::Media::PlayTo::ICurrentTimeChangeRequestedEventArgs
{
    CurrentTimeChangeRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MuteChangeRequestedEventArgs :
    Windows::Media::PlayTo::IMuteChangeRequestedEventArgs
{
    MuteChangeRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct [[deprecated("PlayToConnection may be altered or unavailable for releases after Windows 10. Instead, use CastingConnection.")]] WINRT_EBO PlayToConnection :
    Windows::Media::PlayTo::IPlayToConnection
{
    PlayToConnection(std::nullptr_t) noexcept {}
};

struct [[deprecated("PlayToConnectionErrorEventArgs may be altered or unavailable for releases after Windows 10. Instead, use CastingConnectionErrorOccurredEventArgs.")]] WINRT_EBO PlayToConnectionErrorEventArgs :
    Windows::Media::PlayTo::IPlayToConnectionErrorEventArgs
{
    PlayToConnectionErrorEventArgs(std::nullptr_t) noexcept {}
};

struct [[deprecated("PlayToConnectionStateChangedEventArgs may be altered or unavailable for releases after Windows 10.")]] WINRT_EBO PlayToConnectionStateChangedEventArgs :
    Windows::Media::PlayTo::IPlayToConnectionStateChangedEventArgs
{
    PlayToConnectionStateChangedEventArgs(std::nullptr_t) noexcept {}
};

struct [[deprecated("PlayToConnectionTransferredEventArgs may be altered or unavailable for releases after Windows 10.")]] WINRT_EBO PlayToConnectionTransferredEventArgs :
    Windows::Media::PlayTo::IPlayToConnectionTransferredEventArgs
{
    PlayToConnectionTransferredEventArgs(std::nullptr_t) noexcept {}
};

struct [[deprecated("PlayToManager may be altered or unavailable for releases after Windows 10.")]] WINRT_EBO PlayToManager :
    Windows::Media::PlayTo::IPlayToManager
{
    PlayToManager(std::nullptr_t) noexcept {}
    [[deprecated("PlayToManager may be altered or unavailable for releases after Windows 10.")]] static Windows::Media::PlayTo::PlayToManager GetForCurrentView();
    [[deprecated("PlayToManager may be altered or unavailable for releases after Windows 10.")]] static void ShowPlayToUI();
};

struct WINRT_EBO PlayToReceiver :
    Windows::Media::PlayTo::IPlayToReceiver
{
    PlayToReceiver(std::nullptr_t) noexcept {}
    PlayToReceiver();
};

struct [[deprecated("PlayToSource may be altered or unavailable for releases after Windows 10. Instead, use CastingSource.")]] WINRT_EBO PlayToSource :
    Windows::Media::PlayTo::IPlayToSource,
    impl::require<PlayToSource, Windows::Media::PlayTo::IPlayToSourceWithPreferredSourceUri>
{
    PlayToSource(std::nullptr_t) noexcept {}
};

struct [[deprecated("PlayToSourceDeferral may be altered or unavailable for releases after Windows 10.")]] WINRT_EBO PlayToSourceDeferral :
    Windows::Media::PlayTo::IPlayToSourceDeferral
{
    PlayToSourceDeferral(std::nullptr_t) noexcept {}
};

struct [[deprecated("PlayToSourceRequest may be altered or unavailable for releases after Windows 10.")]] WINRT_EBO PlayToSourceRequest :
    Windows::Media::PlayTo::IPlayToSourceRequest
{
    PlayToSourceRequest(std::nullptr_t) noexcept {}
};

struct [[deprecated("PlayToSourceRequestedEventArgs may be altered or unavailable for releases after Windows 10.")]] WINRT_EBO PlayToSourceRequestedEventArgs :
    Windows::Media::PlayTo::IPlayToSourceRequestedEventArgs
{
    PlayToSourceRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct [[deprecated("PlayToSourceSelectedEventArgs may be altered or unavailable for releases after Windows 10.")]] WINRT_EBO PlayToSourceSelectedEventArgs :
    Windows::Media::PlayTo::IPlayToSourceSelectedEventArgs
{
    PlayToSourceSelectedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PlaybackRateChangeRequestedEventArgs :
    Windows::Media::PlayTo::IPlaybackRateChangeRequestedEventArgs
{
    PlaybackRateChangeRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SourceChangeRequestedEventArgs :
    Windows::Media::PlayTo::ISourceChangeRequestedEventArgs
{
    SourceChangeRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VolumeChangeRequestedEventArgs :
    Windows::Media::PlayTo::IVolumeChangeRequestedEventArgs
{
    VolumeChangeRequestedEventArgs(std::nullptr_t) noexcept {}
};

}

}
