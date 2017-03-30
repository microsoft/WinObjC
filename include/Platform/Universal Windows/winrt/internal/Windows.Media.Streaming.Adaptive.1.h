// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.Streaming.Adaptive.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Media.Core.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Web.Http.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Streaming::Adaptive {

struct __declspec(uuid("4c7332ef-d39f-4396-b4d9-043957a7c964")) __declspec(novtable) IAdaptiveMediaSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsLive(bool * value) = 0;
    virtual HRESULT __stdcall get_DesiredLiveOffset(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_DesiredLiveOffset(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_InitialBitrate(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_InitialBitrate(uint32_t value) = 0;
    virtual HRESULT __stdcall get_CurrentDownloadBitrate(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_CurrentPlaybackBitrate(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_AvailableBitrates(Windows::Foundation::Collections::IVectorView<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_DesiredMinBitrate(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall put_DesiredMinBitrate(Windows::Foundation::IReference<uint32_t> * value) = 0;
    virtual HRESULT __stdcall get_DesiredMaxBitrate(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall put_DesiredMaxBitrate(Windows::Foundation::IReference<uint32_t> * value) = 0;
    virtual HRESULT __stdcall get_AudioOnlyPlayback(bool * value) = 0;
    virtual HRESULT __stdcall get_InboundBitsPerSecond(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_InboundBitsPerSecondWindow(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_InboundBitsPerSecondWindow(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall add_DownloadBitrateChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource, Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadBitrateChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DownloadBitrateChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_PlaybackBitrateChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource, Windows::Media::Streaming::Adaptive::AdaptiveMediaSourcePlaybackBitrateChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PlaybackBitrateChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_DownloadRequested(Windows::Foundation::TypedEventHandler<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource, Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DownloadRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_DownloadCompleted(Windows::Foundation::TypedEventHandler<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource, Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadCompletedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DownloadCompleted(event_token token) = 0;
    virtual HRESULT __stdcall add_DownloadFailed(Windows::Foundation::TypedEventHandler<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource, Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadFailedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DownloadFailed(event_token token) = 0;
};

struct __declspec(uuid("17890342-6760-4bb9-a58a-f7aa98b08c0e")) __declspec(novtable) IAdaptiveMediaSource2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AdvancedSettings(Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings ** value) = 0;
};

struct __declspec(uuid("55db1680-1aeb-47dc-aa08-9a11610ba45a")) __declspec(novtable) IAdaptiveMediaSourceAdvancedSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AllSegmentsIndependent(bool * value) = 0;
    virtual HRESULT __stdcall put_AllSegmentsIndependent(bool value) = 0;
    virtual HRESULT __stdcall get_DesiredBitrateHeadroomRatio(Windows::Foundation::IReference<double> ** value) = 0;
    virtual HRESULT __stdcall put_DesiredBitrateHeadroomRatio(Windows::Foundation::IReference<double> * value) = 0;
    virtual HRESULT __stdcall get_BitrateDowngradeTriggerRatio(Windows::Foundation::IReference<double> ** value) = 0;
    virtual HRESULT __stdcall put_BitrateDowngradeTriggerRatio(Windows::Foundation::IReference<double> * value) = 0;
};

struct __declspec(uuid("4686b6b2-800f-4e31-9093-76d4782013e7")) __declspec(novtable) IAdaptiveMediaSourceCreationResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationStatus * value) = 0;
    virtual HRESULT __stdcall get_MediaSource(Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource ** value) = 0;
    virtual HRESULT __stdcall get_HttpResponseMessage(Windows::Web::Http::IHttpResponseMessage ** value) = 0;
};

struct __declspec(uuid("670c0a44-e04e-4eff-816a-17399f78f4ba")) __declspec(novtable) IAdaptiveMediaSourceDownloadBitrateChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OldValue(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_NewValue(uint32_t * value) = 0;
};

struct __declspec(uuid("19240dc3-5b37-4a1a-8970-d621cb6ca83b")) __declspec(novtable) IAdaptiveMediaSourceDownloadCompletedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ResourceType(winrt::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType * value) = 0;
    virtual HRESULT __stdcall get_ResourceUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_ResourceByteRangeOffset(Windows::Foundation::IReference<uint64_t> ** value) = 0;
    virtual HRESULT __stdcall get_ResourceByteRangeLength(Windows::Foundation::IReference<uint64_t> ** value) = 0;
    virtual HRESULT __stdcall get_HttpResponseMessage(Windows::Web::Http::IHttpResponseMessage ** value) = 0;
};

struct __declspec(uuid("37739048-f4ab-40a4-b135-c6dfd8bd7ff1")) __declspec(novtable) IAdaptiveMediaSourceDownloadFailedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ResourceType(winrt::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType * value) = 0;
    virtual HRESULT __stdcall get_ResourceUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_ResourceByteRangeOffset(Windows::Foundation::IReference<uint64_t> ** value) = 0;
    virtual HRESULT __stdcall get_ResourceByteRangeLength(Windows::Foundation::IReference<uint64_t> ** value) = 0;
    virtual HRESULT __stdcall get_HttpResponseMessage(Windows::Web::Http::IHttpResponseMessage ** value) = 0;
};

struct __declspec(uuid("05c68f64-fa20-4dbd-9821-4bf4c9bf77ab")) __declspec(novtable) IAdaptiveMediaSourceDownloadRequestedDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("c83fdffd-44a9-47a2-bf96-03398b4bfaaf")) __declspec(novtable) IAdaptiveMediaSourceDownloadRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ResourceType(winrt::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType * value) = 0;
    virtual HRESULT __stdcall get_ResourceUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_ResourceByteRangeOffset(Windows::Foundation::IReference<uint64_t> ** value) = 0;
    virtual HRESULT __stdcall get_ResourceByteRangeLength(Windows::Foundation::IReference<uint64_t> ** value) = 0;
    virtual HRESULT __stdcall get_Result(Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedDeferral ** deferral) = 0;
};

struct __declspec(uuid("f4afdc73-bcee-4a6a-9f0a-fec41e2339b0")) __declspec(novtable) IAdaptiveMediaSourceDownloadResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ResourceUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_ResourceUri(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_InputStream(Windows::Storage::Streams::IInputStream ** value) = 0;
    virtual HRESULT __stdcall put_InputStream(Windows::Storage::Streams::IInputStream * value) = 0;
    virtual HRESULT __stdcall get_Buffer(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_Buffer(Windows::Storage::Streams::IBuffer * value) = 0;
    virtual HRESULT __stdcall get_ContentType(hstring * value) = 0;
    virtual HRESULT __stdcall put_ContentType(hstring value) = 0;
    virtual HRESULT __stdcall get_ExtendedStatus(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ExtendedStatus(uint32_t value) = 0;
};

struct __declspec(uuid("15552cb7-7b80-4ac4-8660-a4b97f7c70f0")) __declspec(novtable) IAdaptiveMediaSourceDownloadResult2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ResourceByteRangeOffset(Windows::Foundation::IReference<uint64_t> ** value) = 0;
    virtual HRESULT __stdcall put_ResourceByteRangeOffset(Windows::Foundation::IReference<uint64_t> * value) = 0;
    virtual HRESULT __stdcall get_ResourceByteRangeLength(Windows::Foundation::IReference<uint64_t> ** value) = 0;
    virtual HRESULT __stdcall put_ResourceByteRangeLength(Windows::Foundation::IReference<uint64_t> * value) = 0;
};

struct __declspec(uuid("23a29f6d-7dda-4a51-87a9-6fa8c5b292be")) __declspec(novtable) IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OldValue(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_NewValue(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_AudioOnly(bool * value) = 0;
};

struct __declspec(uuid("50a6bd5d-66ef-4cd3-9579-9e660507dc3f")) __declspec(novtable) IAdaptiveMediaSourceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_IsContentTypeSupported(hstring contentType, bool * result) = 0;
    virtual HRESULT __stdcall abi_CreateFromUriAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Foundation::IAsyncOperation<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateFromUriWithDownloaderAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Web::Http::IHttpClient * httpClient, Windows::Foundation::IAsyncOperation<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateFromStreamAsync(Windows::Storage::Streams::IInputStream * stream, Windows::Foundation::IUriRuntimeClass * uri, hstring contentType, Windows::Foundation::IAsyncOperation<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateFromStreamWithDownloaderAsync(Windows::Storage::Streams::IInputStream * stream, Windows::Foundation::IUriRuntimeClass * uri, hstring contentType, Windows::Web::Http::IHttpClient * httpClient, Windows::Foundation::IAsyncOperation<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult> ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource> { using default_interface = Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource; };
template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceAdvancedSettings> { using default_interface = Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings; };
template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult> { using default_interface = Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult; };
template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadBitrateChangedEventArgs> { using default_interface = Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs; };
template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadCompletedEventArgs> { using default_interface = Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs; };
template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadFailedEventArgs> { using default_interface = Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs; };
template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedDeferral> { using default_interface = Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedDeferral; };
template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedEventArgs> { using default_interface = Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs; };
template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadResult> { using default_interface = Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult; };
template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourcePlaybackBitrateChangedEventArgs> { using default_interface = Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs; };

}

namespace Windows::Media::Streaming::Adaptive {

template <typename D>
struct WINRT_EBO impl_IAdaptiveMediaSource
{
    bool IsLive() const;
    Windows::Foundation::TimeSpan DesiredLiveOffset() const;
    void DesiredLiveOffset(const Windows::Foundation::TimeSpan & value) const;
    uint32_t InitialBitrate() const;
    void InitialBitrate(uint32_t value) const;
    uint32_t CurrentDownloadBitrate() const;
    uint32_t CurrentPlaybackBitrate() const;
    Windows::Foundation::Collections::IVectorView<uint32_t> AvailableBitrates() const;
    Windows::Foundation::IReference<uint32_t> DesiredMinBitrate() const;
    void DesiredMinBitrate(const optional<uint32_t> & value) const;
    Windows::Foundation::IReference<uint32_t> DesiredMaxBitrate() const;
    void DesiredMaxBitrate(const optional<uint32_t> & value) const;
    bool AudioOnlyPlayback() const;
    uint64_t InboundBitsPerSecond() const;
    Windows::Foundation::TimeSpan InboundBitsPerSecondWindow() const;
    void InboundBitsPerSecondWindow(const Windows::Foundation::TimeSpan & value) const;
    event_token DownloadBitrateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource, Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadBitrateChangedEventArgs> & handler) const;
    using DownloadBitrateChanged_revoker = event_revoker<IAdaptiveMediaSource>;
    DownloadBitrateChanged_revoker DownloadBitrateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource, Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadBitrateChangedEventArgs> & handler) const;
    void DownloadBitrateChanged(event_token token) const;
    event_token PlaybackBitrateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource, Windows::Media::Streaming::Adaptive::AdaptiveMediaSourcePlaybackBitrateChangedEventArgs> & handler) const;
    using PlaybackBitrateChanged_revoker = event_revoker<IAdaptiveMediaSource>;
    PlaybackBitrateChanged_revoker PlaybackBitrateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource, Windows::Media::Streaming::Adaptive::AdaptiveMediaSourcePlaybackBitrateChangedEventArgs> & handler) const;
    void PlaybackBitrateChanged(event_token token) const;
    event_token DownloadRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource, Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedEventArgs> & handler) const;
    using DownloadRequested_revoker = event_revoker<IAdaptiveMediaSource>;
    DownloadRequested_revoker DownloadRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource, Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedEventArgs> & handler) const;
    void DownloadRequested(event_token token) const;
    event_token DownloadCompleted(const Windows::Foundation::TypedEventHandler<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource, Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadCompletedEventArgs> & handler) const;
    using DownloadCompleted_revoker = event_revoker<IAdaptiveMediaSource>;
    DownloadCompleted_revoker DownloadCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource, Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadCompletedEventArgs> & handler) const;
    void DownloadCompleted(event_token token) const;
    event_token DownloadFailed(const Windows::Foundation::TypedEventHandler<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource, Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadFailedEventArgs> & handler) const;
    using DownloadFailed_revoker = event_revoker<IAdaptiveMediaSource>;
    DownloadFailed_revoker DownloadFailed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource, Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadFailedEventArgs> & handler) const;
    void DownloadFailed(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IAdaptiveMediaSource2
{
    Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceAdvancedSettings AdvancedSettings() const;
};

template <typename D>
struct WINRT_EBO impl_IAdaptiveMediaSourceAdvancedSettings
{
    bool AllSegmentsIndependent() const;
    void AllSegmentsIndependent(bool value) const;
    Windows::Foundation::IReference<double> DesiredBitrateHeadroomRatio() const;
    void DesiredBitrateHeadroomRatio(const optional<double> & value) const;
    Windows::Foundation::IReference<double> BitrateDowngradeTriggerRatio() const;
    void BitrateDowngradeTriggerRatio(const optional<double> & value) const;
};

template <typename D>
struct WINRT_EBO impl_IAdaptiveMediaSourceCreationResult
{
    Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationStatus Status() const;
    Windows::Media::Streaming::Adaptive::AdaptiveMediaSource MediaSource() const;
    Windows::Web::Http::HttpResponseMessage HttpResponseMessage() const;
};

template <typename D>
struct WINRT_EBO impl_IAdaptiveMediaSourceDownloadBitrateChangedEventArgs
{
    uint32_t OldValue() const;
    uint32_t NewValue() const;
};

template <typename D>
struct WINRT_EBO impl_IAdaptiveMediaSourceDownloadCompletedEventArgs
{
    Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType ResourceType() const;
    Windows::Foundation::Uri ResourceUri() const;
    Windows::Foundation::IReference<uint64_t> ResourceByteRangeOffset() const;
    Windows::Foundation::IReference<uint64_t> ResourceByteRangeLength() const;
    Windows::Web::Http::HttpResponseMessage HttpResponseMessage() const;
};

template <typename D>
struct WINRT_EBO impl_IAdaptiveMediaSourceDownloadFailedEventArgs
{
    Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType ResourceType() const;
    Windows::Foundation::Uri ResourceUri() const;
    Windows::Foundation::IReference<uint64_t> ResourceByteRangeOffset() const;
    Windows::Foundation::IReference<uint64_t> ResourceByteRangeLength() const;
    Windows::Web::Http::HttpResponseMessage HttpResponseMessage() const;
};

template <typename D>
struct WINRT_EBO impl_IAdaptiveMediaSourceDownloadRequestedDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IAdaptiveMediaSourceDownloadRequestedEventArgs
{
    Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType ResourceType() const;
    Windows::Foundation::Uri ResourceUri() const;
    Windows::Foundation::IReference<uint64_t> ResourceByteRangeOffset() const;
    Windows::Foundation::IReference<uint64_t> ResourceByteRangeLength() const;
    Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadResult Result() const;
    Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IAdaptiveMediaSourceDownloadResult
{
    Windows::Foundation::Uri ResourceUri() const;
    void ResourceUri(const Windows::Foundation::Uri & value) const;
    Windows::Storage::Streams::IInputStream InputStream() const;
    void InputStream(const Windows::Storage::Streams::IInputStream & value) const;
    Windows::Storage::Streams::IBuffer Buffer() const;
    void Buffer(const Windows::Storage::Streams::IBuffer & value) const;
    hstring ContentType() const;
    void ContentType(hstring_view value) const;
    uint32_t ExtendedStatus() const;
    void ExtendedStatus(uint32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IAdaptiveMediaSourceDownloadResult2
{
    Windows::Foundation::IReference<uint64_t> ResourceByteRangeOffset() const;
    void ResourceByteRangeOffset(const optional<uint64_t> & value) const;
    Windows::Foundation::IReference<uint64_t> ResourceByteRangeLength() const;
    void ResourceByteRangeLength(const optional<uint64_t> & value) const;
};

template <typename D>
struct WINRT_EBO impl_IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs
{
    uint32_t OldValue() const;
    uint32_t NewValue() const;
    bool AudioOnly() const;
};

template <typename D>
struct WINRT_EBO impl_IAdaptiveMediaSourceStatics
{
    bool IsContentTypeSupported(hstring_view contentType) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult> CreateFromUriAsync(const Windows::Foundation::Uri & uri) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult> CreateFromUriAsync(const Windows::Foundation::Uri & uri, const Windows::Web::Http::HttpClient & httpClient) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult> CreateFromStreamAsync(const Windows::Storage::Streams::IInputStream & stream, const Windows::Foundation::Uri & uri, hstring_view contentType) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult> CreateFromStreamAsync(const Windows::Storage::Streams::IInputStream & stream, const Windows::Foundation::Uri & uri, hstring_view contentType, const Windows::Web::Http::HttpClient & httpClient) const;
};

}

namespace impl {

template <> struct traits<Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource;
    template <typename D> using consume = Windows::Media::Streaming::Adaptive::impl_IAdaptiveMediaSource<D>;
};

template <> struct traits<Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource2>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource2;
    template <typename D> using consume = Windows::Media::Streaming::Adaptive::impl_IAdaptiveMediaSource2<D>;
};

template <> struct traits<Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings;
    template <typename D> using consume = Windows::Media::Streaming::Adaptive::impl_IAdaptiveMediaSourceAdvancedSettings<D>;
};

template <> struct traits<Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult;
    template <typename D> using consume = Windows::Media::Streaming::Adaptive::impl_IAdaptiveMediaSourceCreationResult<D>;
};

template <> struct traits<Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs;
    template <typename D> using consume = Windows::Media::Streaming::Adaptive::impl_IAdaptiveMediaSourceDownloadBitrateChangedEventArgs<D>;
};

template <> struct traits<Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs;
    template <typename D> using consume = Windows::Media::Streaming::Adaptive::impl_IAdaptiveMediaSourceDownloadCompletedEventArgs<D>;
};

template <> struct traits<Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs;
    template <typename D> using consume = Windows::Media::Streaming::Adaptive::impl_IAdaptiveMediaSourceDownloadFailedEventArgs<D>;
};

template <> struct traits<Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedDeferral>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedDeferral;
    template <typename D> using consume = Windows::Media::Streaming::Adaptive::impl_IAdaptiveMediaSourceDownloadRequestedDeferral<D>;
};

template <> struct traits<Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs;
    template <typename D> using consume = Windows::Media::Streaming::Adaptive::impl_IAdaptiveMediaSourceDownloadRequestedEventArgs<D>;
};

template <> struct traits<Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult;
    template <typename D> using consume = Windows::Media::Streaming::Adaptive::impl_IAdaptiveMediaSourceDownloadResult<D>;
};

template <> struct traits<Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult2>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult2;
    template <typename D> using consume = Windows::Media::Streaming::Adaptive::impl_IAdaptiveMediaSourceDownloadResult2<D>;
};

template <> struct traits<Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs;
    template <typename D> using consume = Windows::Media::Streaming::Adaptive::impl_IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs<D>;
};

template <> struct traits<Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceStatics>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceStatics;
    template <typename D> using consume = Windows::Media::Streaming::Adaptive::impl_IAdaptiveMediaSourceStatics<D>;
};

template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSource>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Streaming.Adaptive.AdaptiveMediaSource"; }
};

template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceAdvancedSettings>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceAdvancedSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceAdvancedSettings"; }
};

template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceCreationResult"; }
};

template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadBitrateChangedEventArgs>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadBitrateChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadBitrateChangedEventArgs"; }
};

template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadCompletedEventArgs>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadCompletedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadCompletedEventArgs"; }
};

template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadFailedEventArgs>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadFailedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadFailedEventArgs"; }
};

template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedDeferral>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadRequestedDeferral"; }
};

template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedEventArgs>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadRequestedEventArgs"; }
};

template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadResult>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadResult"; }
};

template <> struct traits<Windows::Media::Streaming::Adaptive::AdaptiveMediaSourcePlaybackBitrateChangedEventArgs>
{
    using abi = ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourcePlaybackBitrateChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Streaming.Adaptive.AdaptiveMediaSourcePlaybackBitrateChangedEventArgs"; }
};

}

}
