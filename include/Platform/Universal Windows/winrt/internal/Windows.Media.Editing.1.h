// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.Editing.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Graphics.DirectX.Direct3D11.0.h"
#include "Windows.Media.Core.0.h"
#include "Windows.Media.Effects.0.h"
#include "Windows.Media.MediaProperties.0.h"
#include "Windows.Storage.0.h"
#include "Windows.UI.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Media.Effects.1.h"
#include "Windows.Graphics.Imaging.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Media.Transcoding.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Editing {

struct __declspec(uuid("4b91b3bd-9e21-4266-a9c2-67dd011a2357")) __declspec(novtable) IBackgroundAudioTrack : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TrimTimeFromStart(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_TrimTimeFromStart(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_TrimTimeFromEnd(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_TrimTimeFromEnd(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_OriginalDuration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_TrimmedDuration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_UserData(Windows::Foundation::Collections::IMap<hstring, hstring> ** value) = 0;
    virtual HRESULT __stdcall put_Delay(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_Delay(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_Volume(double value) = 0;
    virtual HRESULT __stdcall get_Volume(double * value) = 0;
    virtual HRESULT __stdcall abi_Clone(Windows::Media::Editing::IBackgroundAudioTrack ** value) = 0;
    virtual HRESULT __stdcall abi_GetAudioEncodingProperties(Windows::Media::MediaProperties::IAudioEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall get_AudioEffectDefinitions(Windows::Foundation::Collections::IVector<Windows::Media::Effects::IAudioEffectDefinition> ** value) = 0;
};

struct __declspec(uuid("d9b1c0d7-d018-42a8-a559-cb4d9e97e664")) __declspec(novtable) IBackgroundAudioTrackStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromEmbeddedAudioTrack(Windows::Media::Editing::IEmbeddedAudioTrack * embeddedAudioTrack, Windows::Media::Editing::IBackgroundAudioTrack ** value) = 0;
    virtual HRESULT __stdcall abi_CreateFromFileAsync(Windows::Storage::IStorageFile * file, Windows::Foundation::IAsyncOperation<Windows::Media::Editing::BackgroundAudioTrack> ** operation) = 0;
};

struct __declspec(uuid("55ee5a7a-2d30-3fba-a190-4f1a6454f88f")) __declspec(novtable) IEmbeddedAudioTrack : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAudioEncodingProperties(Windows::Media::MediaProperties::IAudioEncodingProperties ** value) = 0;
};

struct __declspec(uuid("53f25366-5fba-3ea4-8693-24761811140a")) __declspec(novtable) IMediaClip : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TrimTimeFromStart(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_TrimTimeFromStart(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_TrimTimeFromEnd(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_TrimTimeFromEnd(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_OriginalDuration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_TrimmedDuration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_UserData(Windows::Foundation::Collections::IMap<hstring, hstring> ** value) = 0;
    virtual HRESULT __stdcall abi_Clone(Windows::Media::Editing::IMediaClip ** result) = 0;
    virtual HRESULT __stdcall get_StartTimeInComposition(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_EndTimeInComposition(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_EmbeddedAudioTracks(Windows::Foundation::Collections::IVectorView<Windows::Media::Editing::EmbeddedAudioTrack> ** value) = 0;
    virtual HRESULT __stdcall get_SelectedEmbeddedAudioTrackIndex(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_SelectedEmbeddedAudioTrackIndex(uint32_t value) = 0;
    virtual HRESULT __stdcall put_Volume(double value) = 0;
    virtual HRESULT __stdcall get_Volume(double * value) = 0;
    virtual HRESULT __stdcall abi_GetVideoEncodingProperties(Windows::Media::MediaProperties::IVideoEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall get_AudioEffectDefinitions(Windows::Foundation::Collections::IVector<Windows::Media::Effects::IAudioEffectDefinition> ** value) = 0;
    virtual HRESULT __stdcall get_VideoEffectDefinitions(Windows::Foundation::Collections::IVector<Windows::Media::Effects::IVideoEffectDefinition> ** value) = 0;
};

struct __declspec(uuid("fa402b68-928f-43c4-bc6e-783a1a359656")) __declspec(novtable) IMediaClipStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromColor(Windows::UI::Color color, Windows::Foundation::TimeSpan originalDuration, Windows::Media::Editing::IMediaClip ** value) = 0;
    virtual HRESULT __stdcall abi_CreateFromFileAsync(Windows::Storage::IStorageFile * file, Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaClip> ** operation) = 0;
    virtual HRESULT __stdcall abi_CreateFromImageFileAsync(Windows::Storage::IStorageFile * file, Windows::Foundation::TimeSpan originalDuration, Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaClip> ** operation) = 0;
};

struct __declspec(uuid("5b1dd7b3-854e-4d9b-877d-4774a556cd12")) __declspec(novtable) IMediaClipStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromSurface(Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface * surface, Windows::Foundation::TimeSpan originalDuration, Windows::Media::Editing::IMediaClip ** value) = 0;
};

struct __declspec(uuid("2e06e605-dc71-41d6-b837-2d2bc14a2947")) __declspec(novtable) IMediaComposition : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Duration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Clips(Windows::Foundation::Collections::IVector<Windows::Media::Editing::MediaClip> ** value) = 0;
    virtual HRESULT __stdcall get_BackgroundAudioTracks(Windows::Foundation::Collections::IVector<Windows::Media::Editing::BackgroundAudioTrack> ** value) = 0;
    virtual HRESULT __stdcall get_UserData(Windows::Foundation::Collections::IMap<hstring, hstring> ** value) = 0;
    virtual HRESULT __stdcall abi_Clone(Windows::Media::Editing::IMediaComposition ** result) = 0;
    virtual HRESULT __stdcall abi_SaveAsync(Windows::Storage::IStorageFile * file, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_GetThumbnailAsync(Windows::Foundation::TimeSpan timeFromStart, int32_t scaledWidth, int32_t scaledHeight, winrt::Windows::Media::Editing::VideoFramePrecision framePrecision, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetThumbnailsAsync(Windows::Foundation::Collections::IIterable<Windows::Foundation::TimeSpan> * timesFromStart, int32_t scaledWidth, int32_t scaledHeight, winrt::Windows::Media::Editing::VideoFramePrecision framePrecision, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::ImageStream>> ** operation) = 0;
    virtual HRESULT __stdcall abi_RenderToFileAsync(Windows::Storage::IStorageFile * destination, Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Transcoding::TranscodeFailureReason, double> ** operation) = 0;
    virtual HRESULT __stdcall abi_RenderToFileWithTrimmingPreferenceAsync(Windows::Storage::IStorageFile * destination, winrt::Windows::Media::Editing::MediaTrimmingPreference trimmingPreference, Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Transcoding::TranscodeFailureReason, double> ** operation) = 0;
    virtual HRESULT __stdcall abi_RenderToFileWithProfileAsync(Windows::Storage::IStorageFile * destination, winrt::Windows::Media::Editing::MediaTrimmingPreference trimmingPreference, Windows::Media::MediaProperties::IMediaEncodingProfile * encodingProfile, Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Transcoding::TranscodeFailureReason, double> ** operation) = 0;
    virtual HRESULT __stdcall abi_CreateDefaultEncodingProfile(Windows::Media::MediaProperties::IMediaEncodingProfile ** value) = 0;
    virtual HRESULT __stdcall abi_GenerateMediaStreamSource(Windows::Media::Core::IMediaStreamSource ** value) = 0;
    virtual HRESULT __stdcall abi_GenerateMediaStreamSourceWithProfile(Windows::Media::MediaProperties::IMediaEncodingProfile * encodingProfile, Windows::Media::Core::IMediaStreamSource ** value) = 0;
    virtual HRESULT __stdcall abi_GeneratePreviewMediaStreamSource(int32_t scaledWidth, int32_t scaledHeight, Windows::Media::Core::IMediaStreamSource ** value) = 0;
};

struct __declspec(uuid("a59e5372-2366-492c-bec8-e6dfba6d0281")) __declspec(novtable) IMediaComposition2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OverlayLayers(Windows::Foundation::Collections::IVector<Windows::Media::Editing::MediaOverlayLayer> ** value) = 0;
};

struct __declspec(uuid("87a08f04-e32a-45ce-8f66-a30df0766224")) __declspec(novtable) IMediaCompositionStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_LoadAsync(Windows::Storage::IStorageFile * file, Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaComposition> ** operation) = 0;
};

struct __declspec(uuid("a902ae5d-7869-4830-8ab1-94dc01c05fa4")) __declspec(novtable) IMediaOverlay : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall put_Position(Windows::Foundation::Rect value) = 0;
    virtual HRESULT __stdcall put_Delay(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_Delay(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Opacity(double * value) = 0;
    virtual HRESULT __stdcall put_Opacity(double value) = 0;
    virtual HRESULT __stdcall abi_Clone(Windows::Media::Editing::IMediaOverlay ** result) = 0;
    virtual HRESULT __stdcall get_Clip(Windows::Media::Editing::IMediaClip ** value) = 0;
    virtual HRESULT __stdcall get_AudioEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_AudioEnabled(bool value) = 0;
};

struct __declspec(uuid("b584828a-6188-4f8f-a2e0-aa552d598e18")) __declspec(novtable) IMediaOverlayFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Media::Editing::IMediaClip * clip, Windows::Media::Editing::IMediaOverlay ** mediaOverlay) = 0;
    virtual HRESULT __stdcall abi_CreateWithPositionAndOpacity(Windows::Media::Editing::IMediaClip * clip, Windows::Foundation::Rect position, double opacity, Windows::Media::Editing::IMediaOverlay ** mediaOverlay) = 0;
};

struct __declspec(uuid("a6d9ba57-eeda-46c6-bbe5-e398c84168ac")) __declspec(novtable) IMediaOverlayLayer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Clone(Windows::Media::Editing::IMediaOverlayLayer ** result) = 0;
    virtual HRESULT __stdcall get_Overlays(Windows::Foundation::Collections::IVector<Windows::Media::Editing::MediaOverlay> ** value) = 0;
    virtual HRESULT __stdcall get_CustomCompositorDefinition(Windows::Media::Effects::IVideoCompositorDefinition ** value) = 0;
};

struct __declspec(uuid("947cb473-a39e-4362-abbf-9f8b5070a062")) __declspec(novtable) IMediaOverlayLayerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWithCompositorDefinition(Windows::Media::Effects::IVideoCompositorDefinition * compositorDefinition, Windows::Media::Editing::IMediaOverlayLayer ** mediaOverlayLayer) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::Editing::BackgroundAudioTrack> { using default_interface = Windows::Media::Editing::IBackgroundAudioTrack; };
template <> struct traits<Windows::Media::Editing::EmbeddedAudioTrack> { using default_interface = Windows::Media::Editing::IEmbeddedAudioTrack; };
template <> struct traits<Windows::Media::Editing::MediaClip> { using default_interface = Windows::Media::Editing::IMediaClip; };
template <> struct traits<Windows::Media::Editing::MediaComposition> { using default_interface = Windows::Media::Editing::IMediaComposition; };
template <> struct traits<Windows::Media::Editing::MediaOverlay> { using default_interface = Windows::Media::Editing::IMediaOverlay; };
template <> struct traits<Windows::Media::Editing::MediaOverlayLayer> { using default_interface = Windows::Media::Editing::IMediaOverlayLayer; };

}

namespace Windows::Media::Editing {

template <typename D>
struct WINRT_EBO impl_IBackgroundAudioTrack
{
    Windows::Foundation::TimeSpan TrimTimeFromStart() const;
    void TrimTimeFromStart(const Windows::Foundation::TimeSpan & value) const;
    Windows::Foundation::TimeSpan TrimTimeFromEnd() const;
    void TrimTimeFromEnd(const Windows::Foundation::TimeSpan & value) const;
    Windows::Foundation::TimeSpan OriginalDuration() const;
    Windows::Foundation::TimeSpan TrimmedDuration() const;
    Windows::Foundation::Collections::IMap<hstring, hstring> UserData() const;
    void Delay(const Windows::Foundation::TimeSpan & value) const;
    Windows::Foundation::TimeSpan Delay() const;
    void Volume(double value) const;
    double Volume() const;
    Windows::Media::Editing::BackgroundAudioTrack Clone() const;
    Windows::Media::MediaProperties::AudioEncodingProperties GetAudioEncodingProperties() const;
    Windows::Foundation::Collections::IVector<Windows::Media::Effects::IAudioEffectDefinition> AudioEffectDefinitions() const;
};

template <typename D>
struct WINRT_EBO impl_IBackgroundAudioTrackStatics
{
    Windows::Media::Editing::BackgroundAudioTrack CreateFromEmbeddedAudioTrack(const Windows::Media::Editing::EmbeddedAudioTrack & embeddedAudioTrack) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Editing::BackgroundAudioTrack> CreateFromFileAsync(const Windows::Storage::IStorageFile & file) const;
};

template <typename D>
struct WINRT_EBO impl_IEmbeddedAudioTrack
{
    Windows::Media::MediaProperties::AudioEncodingProperties GetAudioEncodingProperties() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaClip
{
    Windows::Foundation::TimeSpan TrimTimeFromStart() const;
    void TrimTimeFromStart(const Windows::Foundation::TimeSpan & value) const;
    Windows::Foundation::TimeSpan TrimTimeFromEnd() const;
    void TrimTimeFromEnd(const Windows::Foundation::TimeSpan & value) const;
    Windows::Foundation::TimeSpan OriginalDuration() const;
    Windows::Foundation::TimeSpan TrimmedDuration() const;
    Windows::Foundation::Collections::IMap<hstring, hstring> UserData() const;
    Windows::Media::Editing::MediaClip Clone() const;
    Windows::Foundation::TimeSpan StartTimeInComposition() const;
    Windows::Foundation::TimeSpan EndTimeInComposition() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Editing::EmbeddedAudioTrack> EmbeddedAudioTracks() const;
    uint32_t SelectedEmbeddedAudioTrackIndex() const;
    void SelectedEmbeddedAudioTrackIndex(uint32_t value) const;
    void Volume(double value) const;
    double Volume() const;
    Windows::Media::MediaProperties::VideoEncodingProperties GetVideoEncodingProperties() const;
    Windows::Foundation::Collections::IVector<Windows::Media::Effects::IAudioEffectDefinition> AudioEffectDefinitions() const;
    Windows::Foundation::Collections::IVector<Windows::Media::Effects::IVideoEffectDefinition> VideoEffectDefinitions() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaClipStatics
{
    Windows::Media::Editing::MediaClip CreateFromColor(const Windows::UI::Color & color, const Windows::Foundation::TimeSpan & originalDuration) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaClip> CreateFromFileAsync(const Windows::Storage::IStorageFile & file) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaClip> CreateFromImageFileAsync(const Windows::Storage::IStorageFile & file, const Windows::Foundation::TimeSpan & originalDuration) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaClipStatics2
{
    Windows::Media::Editing::MediaClip CreateFromSurface(const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface & surface, const Windows::Foundation::TimeSpan & originalDuration) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaComposition
{
    Windows::Foundation::TimeSpan Duration() const;
    Windows::Foundation::Collections::IVector<Windows::Media::Editing::MediaClip> Clips() const;
    Windows::Foundation::Collections::IVector<Windows::Media::Editing::BackgroundAudioTrack> BackgroundAudioTracks() const;
    Windows::Foundation::Collections::IMap<hstring, hstring> UserData() const;
    Windows::Media::Editing::MediaComposition Clone() const;
    Windows::Foundation::IAsyncAction SaveAsync(const Windows::Storage::IStorageFile & file) const;
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream> GetThumbnailAsync(const Windows::Foundation::TimeSpan & timeFromStart, int32_t scaledWidth, int32_t scaledHeight, Windows::Media::Editing::VideoFramePrecision framePrecision) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::ImageStream>> GetThumbnailsAsync(iterable<Windows::Foundation::TimeSpan> timesFromStart, int32_t scaledWidth, int32_t scaledHeight, Windows::Media::Editing::VideoFramePrecision framePrecision) const;
    Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Transcoding::TranscodeFailureReason, double> RenderToFileAsync(const Windows::Storage::IStorageFile & destination) const;
    Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Transcoding::TranscodeFailureReason, double> RenderToFileAsync(const Windows::Storage::IStorageFile & destination, Windows::Media::Editing::MediaTrimmingPreference trimmingPreference) const;
    Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Transcoding::TranscodeFailureReason, double> RenderToFileAsync(const Windows::Storage::IStorageFile & destination, Windows::Media::Editing::MediaTrimmingPreference trimmingPreference, const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile) const;
    Windows::Media::MediaProperties::MediaEncodingProfile CreateDefaultEncodingProfile() const;
    Windows::Media::Core::MediaStreamSource GenerateMediaStreamSource() const;
    Windows::Media::Core::MediaStreamSource GenerateMediaStreamSource(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile) const;
    Windows::Media::Core::MediaStreamSource GeneratePreviewMediaStreamSource(int32_t scaledWidth, int32_t scaledHeight) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaComposition2
{
    Windows::Foundation::Collections::IVector<Windows::Media::Editing::MediaOverlayLayer> OverlayLayers() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCompositionStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaComposition> LoadAsync(const Windows::Storage::StorageFile & file) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaOverlay
{
    Windows::Foundation::Rect Position() const;
    void Position(const Windows::Foundation::Rect & value) const;
    void Delay(const Windows::Foundation::TimeSpan & value) const;
    Windows::Foundation::TimeSpan Delay() const;
    double Opacity() const;
    void Opacity(double value) const;
    Windows::Media::Editing::MediaOverlay Clone() const;
    Windows::Media::Editing::MediaClip Clip() const;
    bool AudioEnabled() const;
    void AudioEnabled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaOverlayFactory
{
    Windows::Media::Editing::MediaOverlay Create(const Windows::Media::Editing::MediaClip & clip) const;
    Windows::Media::Editing::MediaOverlay CreateWithPositionAndOpacity(const Windows::Media::Editing::MediaClip & clip, const Windows::Foundation::Rect & position, double opacity) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaOverlayLayer
{
    Windows::Media::Editing::MediaOverlayLayer Clone() const;
    Windows::Foundation::Collections::IVector<Windows::Media::Editing::MediaOverlay> Overlays() const;
    Windows::Media::Effects::IVideoCompositorDefinition CustomCompositorDefinition() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaOverlayLayerFactory
{
    Windows::Media::Editing::MediaOverlayLayer CreateWithCompositorDefinition(const Windows::Media::Effects::IVideoCompositorDefinition & compositorDefinition) const;
};

}

namespace impl {

template <> struct traits<Windows::Media::Editing::IBackgroundAudioTrack>
{
    using abi = ABI::Windows::Media::Editing::IBackgroundAudioTrack;
    template <typename D> using consume = Windows::Media::Editing::impl_IBackgroundAudioTrack<D>;
};

template <> struct traits<Windows::Media::Editing::IBackgroundAudioTrackStatics>
{
    using abi = ABI::Windows::Media::Editing::IBackgroundAudioTrackStatics;
    template <typename D> using consume = Windows::Media::Editing::impl_IBackgroundAudioTrackStatics<D>;
};

template <> struct traits<Windows::Media::Editing::IEmbeddedAudioTrack>
{
    using abi = ABI::Windows::Media::Editing::IEmbeddedAudioTrack;
    template <typename D> using consume = Windows::Media::Editing::impl_IEmbeddedAudioTrack<D>;
};

template <> struct traits<Windows::Media::Editing::IMediaClip>
{
    using abi = ABI::Windows::Media::Editing::IMediaClip;
    template <typename D> using consume = Windows::Media::Editing::impl_IMediaClip<D>;
};

template <> struct traits<Windows::Media::Editing::IMediaClipStatics>
{
    using abi = ABI::Windows::Media::Editing::IMediaClipStatics;
    template <typename D> using consume = Windows::Media::Editing::impl_IMediaClipStatics<D>;
};

template <> struct traits<Windows::Media::Editing::IMediaClipStatics2>
{
    using abi = ABI::Windows::Media::Editing::IMediaClipStatics2;
    template <typename D> using consume = Windows::Media::Editing::impl_IMediaClipStatics2<D>;
};

template <> struct traits<Windows::Media::Editing::IMediaComposition>
{
    using abi = ABI::Windows::Media::Editing::IMediaComposition;
    template <typename D> using consume = Windows::Media::Editing::impl_IMediaComposition<D>;
};

template <> struct traits<Windows::Media::Editing::IMediaComposition2>
{
    using abi = ABI::Windows::Media::Editing::IMediaComposition2;
    template <typename D> using consume = Windows::Media::Editing::impl_IMediaComposition2<D>;
};

template <> struct traits<Windows::Media::Editing::IMediaCompositionStatics>
{
    using abi = ABI::Windows::Media::Editing::IMediaCompositionStatics;
    template <typename D> using consume = Windows::Media::Editing::impl_IMediaCompositionStatics<D>;
};

template <> struct traits<Windows::Media::Editing::IMediaOverlay>
{
    using abi = ABI::Windows::Media::Editing::IMediaOverlay;
    template <typename D> using consume = Windows::Media::Editing::impl_IMediaOverlay<D>;
};

template <> struct traits<Windows::Media::Editing::IMediaOverlayFactory>
{
    using abi = ABI::Windows::Media::Editing::IMediaOverlayFactory;
    template <typename D> using consume = Windows::Media::Editing::impl_IMediaOverlayFactory<D>;
};

template <> struct traits<Windows::Media::Editing::IMediaOverlayLayer>
{
    using abi = ABI::Windows::Media::Editing::IMediaOverlayLayer;
    template <typename D> using consume = Windows::Media::Editing::impl_IMediaOverlayLayer<D>;
};

template <> struct traits<Windows::Media::Editing::IMediaOverlayLayerFactory>
{
    using abi = ABI::Windows::Media::Editing::IMediaOverlayLayerFactory;
    template <typename D> using consume = Windows::Media::Editing::impl_IMediaOverlayLayerFactory<D>;
};

template <> struct traits<Windows::Media::Editing::BackgroundAudioTrack>
{
    using abi = ABI::Windows::Media::Editing::BackgroundAudioTrack;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Editing.BackgroundAudioTrack"; }
};

template <> struct traits<Windows::Media::Editing::EmbeddedAudioTrack>
{
    using abi = ABI::Windows::Media::Editing::EmbeddedAudioTrack;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Editing.EmbeddedAudioTrack"; }
};

template <> struct traits<Windows::Media::Editing::MediaClip>
{
    using abi = ABI::Windows::Media::Editing::MediaClip;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Editing.MediaClip"; }
};

template <> struct traits<Windows::Media::Editing::MediaComposition>
{
    using abi = ABI::Windows::Media::Editing::MediaComposition;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Editing.MediaComposition"; }
};

template <> struct traits<Windows::Media::Editing::MediaOverlay>
{
    using abi = ABI::Windows::Media::Editing::MediaOverlay;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Editing.MediaOverlay"; }
};

template <> struct traits<Windows::Media::Editing::MediaOverlayLayer>
{
    using abi = ABI::Windows::Media::Editing::MediaOverlayLayer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Editing.MediaOverlayLayer"; }
};

}

}
