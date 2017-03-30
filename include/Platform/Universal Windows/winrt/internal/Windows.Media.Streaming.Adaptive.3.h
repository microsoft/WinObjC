// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Streaming.Adaptive.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::Streaming::Adaptive {

struct WINRT_EBO AdaptiveMediaSource :
    Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource,
    impl::require<AdaptiveMediaSource, Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource2>
{
    AdaptiveMediaSource(std::nullptr_t) noexcept {}
    static bool IsContentTypeSupported(hstring_view contentType);
    static Windows::Foundation::IAsyncOperation<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult> CreateFromUriAsync(const Windows::Foundation::Uri & uri);
    static Windows::Foundation::IAsyncOperation<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult> CreateFromUriAsync(const Windows::Foundation::Uri & uri, const Windows::Web::Http::HttpClient & httpClient);
    static Windows::Foundation::IAsyncOperation<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult> CreateFromStreamAsync(const Windows::Storage::Streams::IInputStream & stream, const Windows::Foundation::Uri & uri, hstring_view contentType);
    static Windows::Foundation::IAsyncOperation<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult> CreateFromStreamAsync(const Windows::Storage::Streams::IInputStream & stream, const Windows::Foundation::Uri & uri, hstring_view contentType, const Windows::Web::Http::HttpClient & httpClient);
};

struct WINRT_EBO AdaptiveMediaSourceAdvancedSettings :
    Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings
{
    AdaptiveMediaSourceAdvancedSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AdaptiveMediaSourceCreationResult :
    Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult
{
    AdaptiveMediaSourceCreationResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AdaptiveMediaSourceDownloadBitrateChangedEventArgs :
    Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs
{
    AdaptiveMediaSourceDownloadBitrateChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AdaptiveMediaSourceDownloadCompletedEventArgs :
    Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs
{
    AdaptiveMediaSourceDownloadCompletedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AdaptiveMediaSourceDownloadFailedEventArgs :
    Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs
{
    AdaptiveMediaSourceDownloadFailedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AdaptiveMediaSourceDownloadRequestedDeferral :
    Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedDeferral
{
    AdaptiveMediaSourceDownloadRequestedDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AdaptiveMediaSourceDownloadRequestedEventArgs :
    Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs
{
    AdaptiveMediaSourceDownloadRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AdaptiveMediaSourceDownloadResult :
    Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult,
    impl::require<AdaptiveMediaSourceDownloadResult, Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult2>
{
    AdaptiveMediaSourceDownloadResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AdaptiveMediaSourcePlaybackBitrateChangedEventArgs :
    Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs
{
    AdaptiveMediaSourcePlaybackBitrateChangedEventArgs(std::nullptr_t) noexcept {}
};

}

}
