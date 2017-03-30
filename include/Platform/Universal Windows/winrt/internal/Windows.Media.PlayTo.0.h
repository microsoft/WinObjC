// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::PlayTo {

struct ICurrentTimeChangeRequestedEventArgs;
struct IMuteChangeRequestedEventArgs;
struct IPlayToConnection;
struct IPlayToConnectionErrorEventArgs;
struct IPlayToConnectionStateChangedEventArgs;
struct IPlayToConnectionTransferredEventArgs;
struct IPlayToManager;
struct IPlayToManagerStatics;
struct IPlayToReceiver;
struct IPlayToSource;
struct IPlayToSourceDeferral;
struct IPlayToSourceRequest;
struct IPlayToSourceRequestedEventArgs;
struct IPlayToSourceSelectedEventArgs;
struct IPlayToSourceWithPreferredSourceUri;
struct IPlaybackRateChangeRequestedEventArgs;
struct ISourceChangeRequestedEventArgs;
struct IVolumeChangeRequestedEventArgs;
struct CurrentTimeChangeRequestedEventArgs;
struct MuteChangeRequestedEventArgs;
struct PlayToConnection;
struct PlayToConnectionErrorEventArgs;
struct PlayToConnectionStateChangedEventArgs;
struct PlayToConnectionTransferredEventArgs;
struct PlayToManager;
struct PlayToReceiver;
struct PlayToSource;
struct PlayToSourceDeferral;
struct PlayToSourceRequest;
struct PlayToSourceRequestedEventArgs;
struct PlayToSourceSelectedEventArgs;
struct PlaybackRateChangeRequestedEventArgs;
struct SourceChangeRequestedEventArgs;
struct VolumeChangeRequestedEventArgs;

}

namespace Windows::Media::PlayTo {

struct ICurrentTimeChangeRequestedEventArgs;
struct IMuteChangeRequestedEventArgs;
struct IPlayToConnection;
struct IPlayToConnectionErrorEventArgs;
struct IPlayToConnectionStateChangedEventArgs;
struct IPlayToConnectionTransferredEventArgs;
struct IPlayToManager;
struct IPlayToManagerStatics;
struct IPlayToReceiver;
struct IPlayToSource;
struct IPlayToSourceDeferral;
struct IPlayToSourceRequest;
struct IPlayToSourceRequestedEventArgs;
struct IPlayToSourceSelectedEventArgs;
struct IPlayToSourceWithPreferredSourceUri;
struct IPlaybackRateChangeRequestedEventArgs;
struct ISourceChangeRequestedEventArgs;
struct IVolumeChangeRequestedEventArgs;
struct CurrentTimeChangeRequestedEventArgs;
struct MuteChangeRequestedEventArgs;
struct PlayToConnection;
struct PlayToConnectionErrorEventArgs;
struct PlayToConnectionStateChangedEventArgs;
struct PlayToConnectionTransferredEventArgs;
struct PlayToManager;
struct PlayToReceiver;
struct PlayToSource;
struct PlayToSourceDeferral;
struct PlayToSourceRequest;
struct PlayToSourceRequestedEventArgs;
struct PlayToSourceSelectedEventArgs;
struct PlaybackRateChangeRequestedEventArgs;
struct SourceChangeRequestedEventArgs;
struct VolumeChangeRequestedEventArgs;

}

namespace Windows::Media::PlayTo {

template <typename T> struct impl_ICurrentTimeChangeRequestedEventArgs;
template <typename T> struct impl_IMuteChangeRequestedEventArgs;
template <typename T> struct impl_IPlayToConnection;
template <typename T> struct impl_IPlayToConnectionErrorEventArgs;
template <typename T> struct impl_IPlayToConnectionStateChangedEventArgs;
template <typename T> struct impl_IPlayToConnectionTransferredEventArgs;
template <typename T> struct impl_IPlayToManager;
template <typename T> struct impl_IPlayToManagerStatics;
template <typename T> struct impl_IPlayToReceiver;
template <typename T> struct impl_IPlayToSource;
template <typename T> struct impl_IPlayToSourceDeferral;
template <typename T> struct impl_IPlayToSourceRequest;
template <typename T> struct impl_IPlayToSourceRequestedEventArgs;
template <typename T> struct impl_IPlayToSourceSelectedEventArgs;
template <typename T> struct impl_IPlayToSourceWithPreferredSourceUri;
template <typename T> struct impl_IPlaybackRateChangeRequestedEventArgs;
template <typename T> struct impl_ISourceChangeRequestedEventArgs;
template <typename T> struct impl_IVolumeChangeRequestedEventArgs;

}

namespace Windows::Media::PlayTo {

enum class [[deprecated("PlayToConnectionError may be altered or unavailable for releases after Windows 10. Instead, use CastingConnectionErrorStatus.")]] PlayToConnectionError
{
    None = 0,
    DeviceNotResponding = 1,
    DeviceError = 2,
    DeviceLocked = 3,
    ProtectedPlaybackFailed = 4,
};

enum class [[deprecated("PlayToConnectionState may be altered or unavailable for releases after Windows 10. Instead, use CastingConnectionState.")]] PlayToConnectionState
{
    Disconnected = 0,
    Connected = 1,
    Rendering = 2,
};

}

}
