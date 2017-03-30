// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Streaming::Adaptive {

struct IAdaptiveMediaSource;
struct IAdaptiveMediaSource2;
struct IAdaptiveMediaSourceAdvancedSettings;
struct IAdaptiveMediaSourceCreationResult;
struct IAdaptiveMediaSourceDownloadBitrateChangedEventArgs;
struct IAdaptiveMediaSourceDownloadCompletedEventArgs;
struct IAdaptiveMediaSourceDownloadFailedEventArgs;
struct IAdaptiveMediaSourceDownloadRequestedDeferral;
struct IAdaptiveMediaSourceDownloadRequestedEventArgs;
struct IAdaptiveMediaSourceDownloadResult;
struct IAdaptiveMediaSourceDownloadResult2;
struct IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs;
struct IAdaptiveMediaSourceStatics;
struct AdaptiveMediaSource;
struct AdaptiveMediaSourceAdvancedSettings;
struct AdaptiveMediaSourceCreationResult;
struct AdaptiveMediaSourceDownloadBitrateChangedEventArgs;
struct AdaptiveMediaSourceDownloadCompletedEventArgs;
struct AdaptiveMediaSourceDownloadFailedEventArgs;
struct AdaptiveMediaSourceDownloadRequestedDeferral;
struct AdaptiveMediaSourceDownloadRequestedEventArgs;
struct AdaptiveMediaSourceDownloadResult;
struct AdaptiveMediaSourcePlaybackBitrateChangedEventArgs;

}

namespace Windows::Media::Streaming::Adaptive {

struct IAdaptiveMediaSource;
struct IAdaptiveMediaSource2;
struct IAdaptiveMediaSourceAdvancedSettings;
struct IAdaptiveMediaSourceCreationResult;
struct IAdaptiveMediaSourceDownloadBitrateChangedEventArgs;
struct IAdaptiveMediaSourceDownloadCompletedEventArgs;
struct IAdaptiveMediaSourceDownloadFailedEventArgs;
struct IAdaptiveMediaSourceDownloadRequestedDeferral;
struct IAdaptiveMediaSourceDownloadRequestedEventArgs;
struct IAdaptiveMediaSourceDownloadResult;
struct IAdaptiveMediaSourceDownloadResult2;
struct IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs;
struct IAdaptiveMediaSourceStatics;
struct AdaptiveMediaSource;
struct AdaptiveMediaSourceAdvancedSettings;
struct AdaptiveMediaSourceCreationResult;
struct AdaptiveMediaSourceDownloadBitrateChangedEventArgs;
struct AdaptiveMediaSourceDownloadCompletedEventArgs;
struct AdaptiveMediaSourceDownloadFailedEventArgs;
struct AdaptiveMediaSourceDownloadRequestedDeferral;
struct AdaptiveMediaSourceDownloadRequestedEventArgs;
struct AdaptiveMediaSourceDownloadResult;
struct AdaptiveMediaSourcePlaybackBitrateChangedEventArgs;

}

namespace Windows::Media::Streaming::Adaptive {

template <typename T> struct impl_IAdaptiveMediaSource;
template <typename T> struct impl_IAdaptiveMediaSource2;
template <typename T> struct impl_IAdaptiveMediaSourceAdvancedSettings;
template <typename T> struct impl_IAdaptiveMediaSourceCreationResult;
template <typename T> struct impl_IAdaptiveMediaSourceDownloadBitrateChangedEventArgs;
template <typename T> struct impl_IAdaptiveMediaSourceDownloadCompletedEventArgs;
template <typename T> struct impl_IAdaptiveMediaSourceDownloadFailedEventArgs;
template <typename T> struct impl_IAdaptiveMediaSourceDownloadRequestedDeferral;
template <typename T> struct impl_IAdaptiveMediaSourceDownloadRequestedEventArgs;
template <typename T> struct impl_IAdaptiveMediaSourceDownloadResult;
template <typename T> struct impl_IAdaptiveMediaSourceDownloadResult2;
template <typename T> struct impl_IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs;
template <typename T> struct impl_IAdaptiveMediaSourceStatics;

}

namespace Windows::Media::Streaming::Adaptive {

enum class AdaptiveMediaSourceCreationStatus
{
    Success = 0,
    ManifestDownloadFailure = 1,
    ManifestParseFailure = 2,
    UnsupportedManifestContentType = 3,
    UnsupportedManifestVersion = 4,
    UnsupportedManifestProfile = 5,
    UnknownFailure = 6,
};

enum class AdaptiveMediaSourceResourceType
{
    Manifest = 0,
    InitializationSegment = 1,
    MediaSegment = 2,
    Key = 3,
    InitializationVector = 4,
};

}

}
