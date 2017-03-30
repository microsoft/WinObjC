// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Editing.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::Editing {

struct WINRT_EBO BackgroundAudioTrack :
    Windows::Media::Editing::IBackgroundAudioTrack
{
    BackgroundAudioTrack(std::nullptr_t) noexcept {}
    static Windows::Media::Editing::BackgroundAudioTrack CreateFromEmbeddedAudioTrack(const Windows::Media::Editing::EmbeddedAudioTrack & embeddedAudioTrack);
    static Windows::Foundation::IAsyncOperation<Windows::Media::Editing::BackgroundAudioTrack> CreateFromFileAsync(const Windows::Storage::IStorageFile & file);
};

struct WINRT_EBO EmbeddedAudioTrack :
    Windows::Media::Editing::IEmbeddedAudioTrack
{
    EmbeddedAudioTrack(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaClip :
    Windows::Media::Editing::IMediaClip
{
    MediaClip(std::nullptr_t) noexcept {}
    static Windows::Media::Editing::MediaClip CreateFromColor(const Windows::UI::Color & color, const Windows::Foundation::TimeSpan & originalDuration);
    static Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaClip> CreateFromFileAsync(const Windows::Storage::IStorageFile & file);
    static Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaClip> CreateFromImageFileAsync(const Windows::Storage::IStorageFile & file, const Windows::Foundation::TimeSpan & originalDuration);
    static Windows::Media::Editing::MediaClip CreateFromSurface(const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface & surface, const Windows::Foundation::TimeSpan & originalDuration);
};

struct WINRT_EBO MediaComposition :
    Windows::Media::Editing::IMediaComposition,
    impl::require<MediaComposition, Windows::Media::Editing::IMediaComposition2>
{
    MediaComposition(std::nullptr_t) noexcept {}
    MediaComposition();
    static Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaComposition> LoadAsync(const Windows::Storage::StorageFile & file);
};

struct WINRT_EBO MediaOverlay :
    Windows::Media::Editing::IMediaOverlay
{
    MediaOverlay(std::nullptr_t) noexcept {}
    MediaOverlay(const Windows::Media::Editing::MediaClip & clip);
    MediaOverlay(const Windows::Media::Editing::MediaClip & clip, const Windows::Foundation::Rect & position, double opacity);
};

struct WINRT_EBO MediaOverlayLayer :
    Windows::Media::Editing::IMediaOverlayLayer
{
    MediaOverlayLayer(std::nullptr_t) noexcept {}
    MediaOverlayLayer();
    MediaOverlayLayer(const Windows::Media::Effects::IVideoCompositorDefinition & compositorDefinition);
};

}

}
