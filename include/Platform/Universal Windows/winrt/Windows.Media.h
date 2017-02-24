// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Graphics.Imaging.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Graphics.DirectX.Direct3D11.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Media.3.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::IAudioBuffer> : produce_base<D, Windows::Media::IAudioBuffer>
{
    HRESULT __stdcall get_Capacity(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Capacity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Length(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Length());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Length(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Length(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IAudioFrame> : produce_base<D, Windows::Media::IAudioFrame>
{
    HRESULT __stdcall abi_LockBuffer(Windows::Media::AudioBufferAccessMode mode, impl::abi_arg_out<Windows::Media::IAudioBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LockBuffer(mode));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IAudioFrameFactory> : produce_base<D, Windows::Media::IAudioFrameFactory>
{
    HRESULT __stdcall abi_Create(uint32_t capacity, impl::abi_arg_out<Windows::Media::IAudioFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(capacity));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IAutoRepeatModeChangeRequestedEventArgs> : produce_base<D, Windows::Media::IAutoRepeatModeChangeRequestedEventArgs>
{
    HRESULT __stdcall get_RequestedAutoRepeatMode(Windows::Media::MediaPlaybackAutoRepeatMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestedAutoRepeatMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IImageDisplayProperties> : produce_base<D, Windows::Media::IImageDisplayProperties>
{
    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Subtitle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Subtitle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Subtitle(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Subtitle(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IMediaControl> : produce_base<D, Windows::Media::IMediaControl>
{
    HRESULT __stdcall add_SoundLevelChanged(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().SoundLevelChanged(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SoundLevelChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SoundLevelChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PlayPressed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PlayPressed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PlayPressed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlayPressed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PausePressed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PausePressed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PausePressed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PausePressed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StopPressed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().StopPressed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StopPressed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopPressed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PlayPauseTogglePressed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PlayPauseTogglePressed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PlayPauseTogglePressed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlayPauseTogglePressed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RecordPressed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().RecordPressed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RecordPressed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RecordPressed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_NextTrackPressed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().NextTrackPressed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_NextTrackPressed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NextTrackPressed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PreviousTrackPressed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PreviousTrackPressed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PreviousTrackPressed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreviousTrackPressed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_FastForwardPressed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().FastForwardPressed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_FastForwardPressed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FastForwardPressed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RewindPressed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().RewindPressed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RewindPressed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RewindPressed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ChannelUpPressed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().ChannelUpPressed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ChannelUpPressed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChannelUpPressed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ChannelDownPressed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().ChannelDownPressed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ChannelDownPressed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChannelDownPressed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SoundLevel(Windows::Media::SoundLevel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SoundLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TrackName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrackName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrackName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrackName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ArtistName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ArtistName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ArtistName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ArtistName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsPlaying(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPlaying(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPlaying(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPlaying());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AlbumArt(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlbumArt(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlbumArt(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlbumArt());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IMediaExtension> : produce_base<D, Windows::Media::IMediaExtension>
{
    HRESULT __stdcall abi_SetProperties(impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> configuration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetProperties(*reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&configuration));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IMediaExtensionManager> : produce_base<D, Windows::Media::IMediaExtensionManager>
{
    HRESULT __stdcall abi_RegisterSchemeHandler(impl::abi_arg_in<hstring> activatableClassId, impl::abi_arg_in<hstring> scheme) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterSchemeHandler(*reinterpret_cast<const hstring *>(&activatableClassId), *reinterpret_cast<const hstring *>(&scheme));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterSchemeHandlerWithSettings(impl::abi_arg_in<hstring> activatableClassId, impl::abi_arg_in<hstring> scheme, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> configuration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterSchemeHandler(*reinterpret_cast<const hstring *>(&activatableClassId), *reinterpret_cast<const hstring *>(&scheme), *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&configuration));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterByteStreamHandler(impl::abi_arg_in<hstring> activatableClassId, impl::abi_arg_in<hstring> fileExtension, impl::abi_arg_in<hstring> mimeType) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterByteStreamHandler(*reinterpret_cast<const hstring *>(&activatableClassId), *reinterpret_cast<const hstring *>(&fileExtension), *reinterpret_cast<const hstring *>(&mimeType));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterByteStreamHandlerWithSettings(impl::abi_arg_in<hstring> activatableClassId, impl::abi_arg_in<hstring> fileExtension, impl::abi_arg_in<hstring> mimeType, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> configuration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterByteStreamHandler(*reinterpret_cast<const hstring *>(&activatableClassId), *reinterpret_cast<const hstring *>(&fileExtension), *reinterpret_cast<const hstring *>(&mimeType), *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&configuration));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterAudioDecoder(impl::abi_arg_in<hstring> activatableClassId, GUID inputSubtype, GUID outputSubtype) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterAudioDecoder(*reinterpret_cast<const hstring *>(&activatableClassId), inputSubtype, outputSubtype);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterAudioDecoderWithSettings(impl::abi_arg_in<hstring> activatableClassId, GUID inputSubtype, GUID outputSubtype, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> configuration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterAudioDecoder(*reinterpret_cast<const hstring *>(&activatableClassId), inputSubtype, outputSubtype, *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&configuration));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterAudioEncoder(impl::abi_arg_in<hstring> activatableClassId, GUID inputSubtype, GUID outputSubtype) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterAudioEncoder(*reinterpret_cast<const hstring *>(&activatableClassId), inputSubtype, outputSubtype);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterAudioEncoderWithSettings(impl::abi_arg_in<hstring> activatableClassId, GUID inputSubtype, GUID outputSubtype, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> configuration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterAudioEncoder(*reinterpret_cast<const hstring *>(&activatableClassId), inputSubtype, outputSubtype, *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&configuration));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterVideoDecoder(impl::abi_arg_in<hstring> activatableClassId, GUID inputSubtype, GUID outputSubtype) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterVideoDecoder(*reinterpret_cast<const hstring *>(&activatableClassId), inputSubtype, outputSubtype);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterVideoDecoderWithSettings(impl::abi_arg_in<hstring> activatableClassId, GUID inputSubtype, GUID outputSubtype, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> configuration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterVideoDecoder(*reinterpret_cast<const hstring *>(&activatableClassId), inputSubtype, outputSubtype, *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&configuration));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterVideoEncoder(impl::abi_arg_in<hstring> activatableClassId, GUID inputSubtype, GUID outputSubtype) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterVideoEncoder(*reinterpret_cast<const hstring *>(&activatableClassId), inputSubtype, outputSubtype);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterVideoEncoderWithSettings(impl::abi_arg_in<hstring> activatableClassId, GUID inputSubtype, GUID outputSubtype, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> configuration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterVideoEncoder(*reinterpret_cast<const hstring *>(&activatableClassId), inputSubtype, outputSubtype, *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&configuration));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IMediaFrame> : produce_base<D, Windows::Media::IMediaFrame>
{
    HRESULT __stdcall get_Type(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsReadOnly(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsReadOnly());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RelativeTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RelativeTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RelativeTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RelativeTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SystemRelativeTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SystemRelativeTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemRelativeTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemRelativeTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Duration(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Duration(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duration(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsDiscontinuous(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDiscontinuous(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDiscontinuous(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDiscontinuous());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedProperties(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IMediaMarker> : produce_base<D, Windows::Media::IMediaMarker>
{
    HRESULT __stdcall get_Time(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Time());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaMarkerType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaMarkerType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IMediaMarkerTypesStatics> : produce_base<D, Windows::Media::IMediaMarkerTypesStatics>
{
    HRESULT __stdcall get_Bookmark(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bookmark());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IMediaMarkers> : produce_base<D, Windows::Media::IMediaMarkers>
{
    HRESULT __stdcall get_Markers(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::IMediaMarker>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Markers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IMediaProcessingTriggerDetails> : produce_base<D, Windows::Media::IMediaProcessingTriggerDetails>
{
    HRESULT __stdcall get_Arguments(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Arguments());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IMediaTimelineController> : produce_base<D, Windows::Media::IMediaTimelineController>
{
    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Resume() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resume();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Pause() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Pause();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Position(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Position(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClockRate(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClockRate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ClockRate(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClockRate(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_State(Windows::Media::MediaTimelineControllerState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().State());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PositionChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::MediaTimelineController, Windows::Foundation::IInspectable>> positionChangedEventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().PositionChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::MediaTimelineController, Windows::Foundation::IInspectable> *>(&positionChangedEventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PositionChanged(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionChanged(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StateChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::MediaTimelineController, Windows::Foundation::IInspectable>> stateChangedEventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().StateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::MediaTimelineController, Windows::Foundation::IInspectable> *>(&stateChangedEventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StateChanged(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StateChanged(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IMusicDisplayProperties> : produce_base<D, Windows::Media::IMusicDisplayProperties>
{
    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlbumArtist(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlbumArtist());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AlbumArtist(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlbumArtist(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Artist(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Artist());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Artist(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Artist(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IMusicDisplayProperties2> : produce_base<D, Windows::Media::IMusicDisplayProperties2>
{
    HRESULT __stdcall get_AlbumTitle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlbumTitle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AlbumTitle(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlbumTitle(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrackNumber(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrackNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TrackNumber(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrackNumber(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Genres(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Genres());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IMusicDisplayProperties3> : produce_base<D, Windows::Media::IMusicDisplayProperties3>
{
    HRESULT __stdcall get_AlbumTrackCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlbumTrackCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AlbumTrackCount(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlbumTrackCount(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IPlaybackPositionChangeRequestedEventArgs> : produce_base<D, Windows::Media::IPlaybackPositionChangeRequestedEventArgs>
{
    HRESULT __stdcall get_RequestedPlaybackPosition(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestedPlaybackPosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IPlaybackRateChangeRequestedEventArgs> : produce_base<D, Windows::Media::IPlaybackRateChangeRequestedEventArgs>
{
    HRESULT __stdcall get_RequestedPlaybackRate(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestedPlaybackRate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IShuffleEnabledChangeRequestedEventArgs> : produce_base<D, Windows::Media::IShuffleEnabledChangeRequestedEventArgs>
{
    HRESULT __stdcall get_RequestedShuffleEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestedShuffleEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::ISystemMediaTransportControls> : produce_base<D, Windows::Media::ISystemMediaTransportControls>
{
    HRESULT __stdcall get_PlaybackStatus(Windows::Media::MediaPlaybackStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaybackStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PlaybackStatus(Windows::Media::MediaPlaybackStatus value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackStatus(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayUpdater(impl::abi_arg_out<Windows::Media::ISystemMediaTransportControlsDisplayUpdater> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayUpdater());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SoundLevel(Windows::Media::SoundLevel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SoundLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPlayEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPlayEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsPlayEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPlayEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStopEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStopEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsStopEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsStopEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPauseEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPauseEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsPauseEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPauseEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsRecordEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsRecordEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsRecordEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsRecordEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsFastForwardEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsFastForwardEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsFastForwardEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsFastForwardEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsRewindEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsRewindEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsRewindEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsRewindEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPreviousEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPreviousEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsPreviousEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPreviousEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsNextEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsNextEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsNextEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsNextEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsChannelUpEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsChannelUpEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsChannelUpEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsChannelUpEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsChannelDownEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsChannelDownEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsChannelDownEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsChannelDownEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ButtonPressed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::SystemMediaTransportControlsButtonPressedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ButtonPressed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::SystemMediaTransportControlsButtonPressedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ButtonPressed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonPressed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PropertyChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::SystemMediaTransportControlsPropertyChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PropertyChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::SystemMediaTransportControlsPropertyChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PropertyChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PropertyChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::ISystemMediaTransportControls2> : produce_base<D, Windows::Media::ISystemMediaTransportControls2>
{
    HRESULT __stdcall get_AutoRepeatMode(Windows::Media::MediaPlaybackAutoRepeatMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoRepeatMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutoRepeatMode(Windows::Media::MediaPlaybackAutoRepeatMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoRepeatMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShuffleEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShuffleEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ShuffleEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShuffleEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PlaybackRate(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaybackRate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PlaybackRate(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackRate(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateTimelineProperties(impl::abi_arg_in<Windows::Media::ISystemMediaTransportControlsTimelineProperties> timelineProperties) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateTimelineProperties(*reinterpret_cast<const Windows::Media::SystemMediaTransportControlsTimelineProperties *>(&timelineProperties));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PlaybackPositionChangeRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::PlaybackPositionChangeRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PlaybackPositionChangeRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::PlaybackPositionChangeRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PlaybackPositionChangeRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackPositionChangeRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PlaybackRateChangeRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::PlaybackRateChangeRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PlaybackRateChangeRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::PlaybackRateChangeRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PlaybackRateChangeRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackRateChangeRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ShuffleEnabledChangeRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::ShuffleEnabledChangeRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ShuffleEnabledChangeRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::ShuffleEnabledChangeRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ShuffleEnabledChangeRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShuffleEnabledChangeRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AutoRepeatModeChangeRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::AutoRepeatModeChangeRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AutoRepeatModeChangeRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::AutoRepeatModeChangeRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AutoRepeatModeChangeRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoRepeatModeChangeRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::ISystemMediaTransportControlsButtonPressedEventArgs> : produce_base<D, Windows::Media::ISystemMediaTransportControlsButtonPressedEventArgs>
{
    HRESULT __stdcall get_Button(Windows::Media::SystemMediaTransportControlsButton * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Button());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::ISystemMediaTransportControlsDisplayUpdater> : produce_base<D, Windows::Media::ISystemMediaTransportControlsDisplayUpdater>
{
    HRESULT __stdcall get_Type(Windows::Media::MediaPlaybackType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Type(Windows::Media::MediaPlaybackType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Type(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppMediaId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppMediaId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AppMediaId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppMediaId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thumbnail(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Thumbnail());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Thumbnail(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Thumbnail(*reinterpret_cast<const Windows::Storage::Streams::RandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MusicProperties(impl::abi_arg_out<Windows::Media::IMusicDisplayProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MusicProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoProperties(impl::abi_arg_out<Windows::Media::IVideoDisplayProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ImageProperties(impl::abi_arg_out<Windows::Media::IImageDisplayProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImageProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyFromFileAsync(Windows::Media::MediaPlaybackType type, impl::abi_arg_in<Windows::Storage::IStorageFile> source, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CopyFromFileAsync(type, *reinterpret_cast<const Windows::Storage::StorageFile *>(&source)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearAll() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearAll();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Update() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Update();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::ISystemMediaTransportControlsPropertyChangedEventArgs> : produce_base<D, Windows::Media::ISystemMediaTransportControlsPropertyChangedEventArgs>
{
    HRESULT __stdcall get_Property(Windows::Media::SystemMediaTransportControlsProperty * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Property());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::ISystemMediaTransportControlsStatics> : produce_base<D, Windows::Media::ISystemMediaTransportControlsStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::Media::ISystemMediaTransportControls> mediaControl) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *mediaControl = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *mediaControl = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::ISystemMediaTransportControlsTimelineProperties> : produce_base<D, Windows::Media::ISystemMediaTransportControlsTimelineProperties>
{
    HRESULT __stdcall get_StartTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StartTime(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartTime(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EndTime(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EndTime(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinSeekTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinSeekTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MinSeekTime(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinSeekTime(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxSeekTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxSeekTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxSeekTime(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxSeekTime(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Position(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Position(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IVideoDisplayProperties> : produce_base<D, Windows::Media::IVideoDisplayProperties>
{
    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Subtitle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Subtitle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Subtitle(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Subtitle(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IVideoDisplayProperties2> : produce_base<D, Windows::Media::IVideoDisplayProperties2>
{
    HRESULT __stdcall get_Genres(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Genres());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IVideoEffectsStatics> : produce_base<D, Windows::Media::IVideoEffectsStatics>
{
    HRESULT __stdcall get_VideoStabilization(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoStabilization());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IVideoFrame> : produce_base<D, Windows::Media::IVideoFrame>
{
    HRESULT __stdcall get_SoftwareBitmap(impl::abi_arg_out<Windows::Graphics::Imaging::ISoftwareBitmap> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SoftwareBitmap());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyToAsync(impl::abi_arg_in<Windows::Media::IVideoFrame> frame, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CopyToAsync(*reinterpret_cast<const Windows::Media::VideoFrame *>(&frame)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Direct3DSurface(impl::abi_arg_out<Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Direct3DSurface());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::IVideoFrameFactory> : produce_base<D, Windows::Media::IVideoFrameFactory>
{
    HRESULT __stdcall abi_Create(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, impl::abi_arg_out<Windows::Media::IVideoFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(format, width, height));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithAlpha(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::BitmapAlphaMode alpha, impl::abi_arg_out<Windows::Media::IVideoFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithAlpha(format, width, height, alpha));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media {

template <typename D> Windows::Foundation::Collections::ValueSet impl_IMediaProcessingTriggerDetails<D>::Arguments() const
{
    Windows::Foundation::Collections::ValueSet value { nullptr };
    check_hresult(WINRT_SHIM(IMediaProcessingTriggerDetails)->get_Arguments(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::VideoFrame impl_IVideoFrameFactory<D>::Create(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height) const
{
    Windows::Media::VideoFrame value { nullptr };
    check_hresult(WINRT_SHIM(IVideoFrameFactory)->abi_Create(format, width, height, put_abi(value)));
    return value;
}

template <typename D> Windows::Media::VideoFrame impl_IVideoFrameFactory<D>::CreateWithAlpha(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::BitmapAlphaMode alpha) const
{
    Windows::Media::VideoFrame value { nullptr };
    check_hresult(WINRT_SHIM(IVideoFrameFactory)->abi_CreateWithAlpha(format, width, height, alpha, put_abi(value)));
    return value;
}

template <typename D> Windows::Media::AudioFrame impl_IAudioFrameFactory<D>::Create(uint32_t capacity) const
{
    Windows::Media::AudioFrame value { nullptr };
    check_hresult(WINRT_SHIM(IAudioFrameFactory)->abi_Create(capacity, put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMediaFrame<D>::Type() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaFrame)->get_Type(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaFrame<D>::IsReadOnly() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaFrame)->get_IsReadOnly(&value));
    return value;
}

template <typename D> void impl_IMediaFrame<D>::RelativeTime(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IMediaFrame)->put_RelativeTime(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IMediaFrame<D>::RelativeTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IMediaFrame)->get_RelativeTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaFrame<D>::SystemRelativeTime(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IMediaFrame)->put_SystemRelativeTime(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IMediaFrame<D>::SystemRelativeTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IMediaFrame)->get_SystemRelativeTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaFrame<D>::Duration(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IMediaFrame)->put_Duration(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IMediaFrame<D>::Duration() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IMediaFrame)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaFrame<D>::IsDiscontinuous(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaFrame)->put_IsDiscontinuous(value));
}

template <typename D> bool impl_IMediaFrame<D>::IsDiscontinuous() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaFrame)->get_IsDiscontinuous(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IPropertySet impl_IMediaFrame<D>::ExtendedProperties() const
{
    Windows::Foundation::Collections::IPropertySet value;
    check_hresult(WINRT_SHIM(IMediaFrame)->get_ExtendedProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Imaging::SoftwareBitmap impl_IVideoFrame<D>::SoftwareBitmap() const
{
    Windows::Graphics::Imaging::SoftwareBitmap value { nullptr };
    check_hresult(WINRT_SHIM(IVideoFrame)->get_SoftwareBitmap(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVideoFrame<D>::CopyToAsync(const Windows::Media::VideoFrame & frame) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IVideoFrame)->abi_CopyToAsync(get_abi(frame), put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface impl_IVideoFrame<D>::Direct3DSurface() const
{
    Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface value;
    check_hresult(WINRT_SHIM(IVideoFrame)->get_Direct3DSurface(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::AudioBuffer impl_IAudioFrame<D>::LockBuffer(Windows::Media::AudioBufferAccessMode mode) const
{
    Windows::Media::AudioBuffer value { nullptr };
    check_hresult(WINRT_SHIM(IAudioFrame)->abi_LockBuffer(mode, put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IAudioBuffer<D>::Capacity() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IAudioBuffer)->get_Capacity(&value));
    return value;
}

template <typename D> uint32_t impl_IAudioBuffer<D>::Length() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IAudioBuffer)->get_Length(&value));
    return value;
}

template <typename D> void impl_IAudioBuffer<D>::Length(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IAudioBuffer)->put_Length(value));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaMarker<D>::Time() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaMarker)->get_Time(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMediaMarker<D>::MediaMarkerType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaMarker)->get_MediaMarkerType(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMediaMarker<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaMarker)->get_Text(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::IMediaMarker> impl_IMediaMarkers<D>::Markers() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::IMediaMarker> value;
    check_hresult(WINRT_SHIM(IMediaMarkers)->get_Markers(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMediaMarkerTypesStatics<D>::Bookmark() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaMarkerTypesStatics)->get_Bookmark(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_ISystemMediaTransportControlsTimelineProperties<D>::StartTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsTimelineProperties)->get_StartTime(put_abi(value)));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControlsTimelineProperties<D>::StartTime(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsTimelineProperties)->put_StartTime(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_ISystemMediaTransportControlsTimelineProperties<D>::EndTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsTimelineProperties)->get_EndTime(put_abi(value)));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControlsTimelineProperties<D>::EndTime(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsTimelineProperties)->put_EndTime(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_ISystemMediaTransportControlsTimelineProperties<D>::MinSeekTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsTimelineProperties)->get_MinSeekTime(put_abi(value)));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControlsTimelineProperties<D>::MinSeekTime(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsTimelineProperties)->put_MinSeekTime(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_ISystemMediaTransportControlsTimelineProperties<D>::MaxSeekTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsTimelineProperties)->get_MaxSeekTime(put_abi(value)));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControlsTimelineProperties<D>::MaxSeekTime(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsTimelineProperties)->put_MaxSeekTime(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_ISystemMediaTransportControlsTimelineProperties<D>::Position() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsTimelineProperties)->get_Position(put_abi(value)));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControlsTimelineProperties<D>::Position(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsTimelineProperties)->put_Position(get_abi(value)));
}

template <typename D> hstring impl_IMusicDisplayProperties<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMusicDisplayProperties)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_IMusicDisplayProperties<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMusicDisplayProperties)->put_Title(get_abi(value)));
}

template <typename D> hstring impl_IMusicDisplayProperties<D>::AlbumArtist() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMusicDisplayProperties)->get_AlbumArtist(put_abi(value)));
    return value;
}

template <typename D> void impl_IMusicDisplayProperties<D>::AlbumArtist(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMusicDisplayProperties)->put_AlbumArtist(get_abi(value)));
}

template <typename D> hstring impl_IMusicDisplayProperties<D>::Artist() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMusicDisplayProperties)->get_Artist(put_abi(value)));
    return value;
}

template <typename D> void impl_IMusicDisplayProperties<D>::Artist(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMusicDisplayProperties)->put_Artist(get_abi(value)));
}

template <typename D> hstring impl_IMusicDisplayProperties2<D>::AlbumTitle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMusicDisplayProperties2)->get_AlbumTitle(put_abi(value)));
    return value;
}

template <typename D> void impl_IMusicDisplayProperties2<D>::AlbumTitle(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMusicDisplayProperties2)->put_AlbumTitle(get_abi(value)));
}

template <typename D> uint32_t impl_IMusicDisplayProperties2<D>::TrackNumber() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMusicDisplayProperties2)->get_TrackNumber(&value));
    return value;
}

template <typename D> void impl_IMusicDisplayProperties2<D>::TrackNumber(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IMusicDisplayProperties2)->put_TrackNumber(value));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IMusicDisplayProperties2<D>::Genres() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IMusicDisplayProperties2)->get_Genres(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IMusicDisplayProperties3<D>::AlbumTrackCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMusicDisplayProperties3)->get_AlbumTrackCount(&value));
    return value;
}

template <typename D> void impl_IMusicDisplayProperties3<D>::AlbumTrackCount(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IMusicDisplayProperties3)->put_AlbumTrackCount(value));
}

template <typename D> hstring impl_IVideoDisplayProperties<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVideoDisplayProperties)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_IVideoDisplayProperties<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVideoDisplayProperties)->put_Title(get_abi(value)));
}

template <typename D> hstring impl_IVideoDisplayProperties<D>::Subtitle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVideoDisplayProperties)->get_Subtitle(put_abi(value)));
    return value;
}

template <typename D> void impl_IVideoDisplayProperties<D>::Subtitle(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVideoDisplayProperties)->put_Subtitle(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IVideoDisplayProperties2<D>::Genres() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IVideoDisplayProperties2)->get_Genres(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IImageDisplayProperties<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IImageDisplayProperties)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_IImageDisplayProperties<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IImageDisplayProperties)->put_Title(get_abi(value)));
}

template <typename D> hstring impl_IImageDisplayProperties<D>::Subtitle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IImageDisplayProperties)->get_Subtitle(put_abi(value)));
    return value;
}

template <typename D> void impl_IImageDisplayProperties<D>::Subtitle(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IImageDisplayProperties)->put_Subtitle(get_abi(value)));
}

template <typename D> Windows::Media::MediaPlaybackType impl_ISystemMediaTransportControlsDisplayUpdater<D>::Type() const
{
    Windows::Media::MediaPlaybackType value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsDisplayUpdater)->get_Type(&value));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControlsDisplayUpdater<D>::Type(Windows::Media::MediaPlaybackType value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsDisplayUpdater)->put_Type(value));
}

template <typename D> hstring impl_ISystemMediaTransportControlsDisplayUpdater<D>::AppMediaId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsDisplayUpdater)->get_AppMediaId(put_abi(value)));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControlsDisplayUpdater<D>::AppMediaId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsDisplayUpdater)->put_AppMediaId(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::RandomAccessStreamReference impl_ISystemMediaTransportControlsDisplayUpdater<D>::Thumbnail() const
{
    Windows::Storage::Streams::RandomAccessStreamReference value { nullptr };
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsDisplayUpdater)->get_Thumbnail(put_abi(value)));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControlsDisplayUpdater<D>::Thumbnail(const Windows::Storage::Streams::RandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsDisplayUpdater)->put_Thumbnail(get_abi(value)));
}

template <typename D> Windows::Media::MusicDisplayProperties impl_ISystemMediaTransportControlsDisplayUpdater<D>::MusicProperties() const
{
    Windows::Media::MusicDisplayProperties value { nullptr };
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsDisplayUpdater)->get_MusicProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::VideoDisplayProperties impl_ISystemMediaTransportControlsDisplayUpdater<D>::VideoProperties() const
{
    Windows::Media::VideoDisplayProperties value { nullptr };
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsDisplayUpdater)->get_VideoProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::ImageDisplayProperties impl_ISystemMediaTransportControlsDisplayUpdater<D>::ImageProperties() const
{
    Windows::Media::ImageDisplayProperties value { nullptr };
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsDisplayUpdater)->get_ImageProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISystemMediaTransportControlsDisplayUpdater<D>::CopyFromFileAsync(Windows::Media::MediaPlaybackType type, const Windows::Storage::StorageFile & source) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsDisplayUpdater)->abi_CopyFromFileAsync(type, get_abi(source), put_abi(operation)));
    return operation;
}

template <typename D> void impl_ISystemMediaTransportControlsDisplayUpdater<D>::ClearAll() const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsDisplayUpdater)->abi_ClearAll());
}

template <typename D> void impl_ISystemMediaTransportControlsDisplayUpdater<D>::Update() const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsDisplayUpdater)->abi_Update());
}

template <typename D> Windows::Media::SystemMediaTransportControlsButton impl_ISystemMediaTransportControlsButtonPressedEventArgs<D>::Button() const
{
    Windows::Media::SystemMediaTransportControlsButton value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsButtonPressedEventArgs)->get_Button(&value));
    return value;
}

template <typename D> Windows::Media::SystemMediaTransportControlsProperty impl_ISystemMediaTransportControlsPropertyChangedEventArgs<D>::Property() const
{
    Windows::Media::SystemMediaTransportControlsProperty value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsPropertyChangedEventArgs)->get_Property(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IPlaybackPositionChangeRequestedEventArgs<D>::RequestedPlaybackPosition() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IPlaybackPositionChangeRequestedEventArgs)->get_RequestedPlaybackPosition(put_abi(value)));
    return value;
}

template <typename D> double impl_IPlaybackRateChangeRequestedEventArgs<D>::RequestedPlaybackRate() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPlaybackRateChangeRequestedEventArgs)->get_RequestedPlaybackRate(&value));
    return value;
}

template <typename D> bool impl_IShuffleEnabledChangeRequestedEventArgs<D>::RequestedShuffleEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IShuffleEnabledChangeRequestedEventArgs)->get_RequestedShuffleEnabled(&value));
    return value;
}

template <typename D> Windows::Media::MediaPlaybackAutoRepeatMode impl_IAutoRepeatModeChangeRequestedEventArgs<D>::RequestedAutoRepeatMode() const
{
    Windows::Media::MediaPlaybackAutoRepeatMode value {};
    check_hresult(WINRT_SHIM(IAutoRepeatModeChangeRequestedEventArgs)->get_RequestedAutoRepeatMode(&value));
    return value;
}

template <typename D> Windows::Media::MediaPlaybackStatus impl_ISystemMediaTransportControls<D>::PlaybackStatus() const
{
    Windows::Media::MediaPlaybackStatus value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->get_PlaybackStatus(&value));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControls<D>::PlaybackStatus(Windows::Media::MediaPlaybackStatus value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->put_PlaybackStatus(value));
}

template <typename D> Windows::Media::SystemMediaTransportControlsDisplayUpdater impl_ISystemMediaTransportControls<D>::DisplayUpdater() const
{
    Windows::Media::SystemMediaTransportControlsDisplayUpdater value { nullptr };
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->get_DisplayUpdater(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::SoundLevel impl_ISystemMediaTransportControls<D>::SoundLevel() const
{
    Windows::Media::SoundLevel value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->get_SoundLevel(&value));
    return value;
}

template <typename D> bool impl_ISystemMediaTransportControls<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->get_IsEnabled(&value));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControls<D>::IsEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->put_IsEnabled(value));
}

template <typename D> bool impl_ISystemMediaTransportControls<D>::IsPlayEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->get_IsPlayEnabled(&value));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControls<D>::IsPlayEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->put_IsPlayEnabled(value));
}

template <typename D> bool impl_ISystemMediaTransportControls<D>::IsStopEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->get_IsStopEnabled(&value));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControls<D>::IsStopEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->put_IsStopEnabled(value));
}

template <typename D> bool impl_ISystemMediaTransportControls<D>::IsPauseEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->get_IsPauseEnabled(&value));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControls<D>::IsPauseEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->put_IsPauseEnabled(value));
}

template <typename D> bool impl_ISystemMediaTransportControls<D>::IsRecordEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->get_IsRecordEnabled(&value));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControls<D>::IsRecordEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->put_IsRecordEnabled(value));
}

template <typename D> bool impl_ISystemMediaTransportControls<D>::IsFastForwardEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->get_IsFastForwardEnabled(&value));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControls<D>::IsFastForwardEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->put_IsFastForwardEnabled(value));
}

template <typename D> bool impl_ISystemMediaTransportControls<D>::IsRewindEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->get_IsRewindEnabled(&value));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControls<D>::IsRewindEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->put_IsRewindEnabled(value));
}

template <typename D> bool impl_ISystemMediaTransportControls<D>::IsPreviousEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->get_IsPreviousEnabled(&value));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControls<D>::IsPreviousEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->put_IsPreviousEnabled(value));
}

template <typename D> bool impl_ISystemMediaTransportControls<D>::IsNextEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->get_IsNextEnabled(&value));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControls<D>::IsNextEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->put_IsNextEnabled(value));
}

template <typename D> bool impl_ISystemMediaTransportControls<D>::IsChannelUpEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->get_IsChannelUpEnabled(&value));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControls<D>::IsChannelUpEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->put_IsChannelUpEnabled(value));
}

template <typename D> bool impl_ISystemMediaTransportControls<D>::IsChannelDownEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->get_IsChannelDownEnabled(&value));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControls<D>::IsChannelDownEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->put_IsChannelDownEnabled(value));
}

template <typename D> event_token impl_ISystemMediaTransportControls<D>::ButtonPressed(const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::SystemMediaTransportControlsButtonPressedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->add_ButtonPressed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISystemMediaTransportControls> impl_ISystemMediaTransportControls<D>::ButtonPressed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::SystemMediaTransportControlsButtonPressedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISystemMediaTransportControls>(this, &ABI::Windows::Media::ISystemMediaTransportControls::remove_ButtonPressed, ButtonPressed(handler));
}

template <typename D> void impl_ISystemMediaTransportControls<D>::ButtonPressed(event_token token) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->remove_ButtonPressed(token));
}

template <typename D> event_token impl_ISystemMediaTransportControls<D>::PropertyChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::SystemMediaTransportControlsPropertyChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->add_PropertyChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISystemMediaTransportControls> impl_ISystemMediaTransportControls<D>::PropertyChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::SystemMediaTransportControlsPropertyChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISystemMediaTransportControls>(this, &ABI::Windows::Media::ISystemMediaTransportControls::remove_PropertyChanged, PropertyChanged(handler));
}

template <typename D> void impl_ISystemMediaTransportControls<D>::PropertyChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls)->remove_PropertyChanged(token));
}

template <typename D> Windows::Media::MediaPlaybackAutoRepeatMode impl_ISystemMediaTransportControls2<D>::AutoRepeatMode() const
{
    Windows::Media::MediaPlaybackAutoRepeatMode value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls2)->get_AutoRepeatMode(&value));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControls2<D>::AutoRepeatMode(Windows::Media::MediaPlaybackAutoRepeatMode value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls2)->put_AutoRepeatMode(value));
}

template <typename D> bool impl_ISystemMediaTransportControls2<D>::ShuffleEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls2)->get_ShuffleEnabled(&value));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControls2<D>::ShuffleEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls2)->put_ShuffleEnabled(value));
}

template <typename D> double impl_ISystemMediaTransportControls2<D>::PlaybackRate() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls2)->get_PlaybackRate(&value));
    return value;
}

template <typename D> void impl_ISystemMediaTransportControls2<D>::PlaybackRate(double value) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls2)->put_PlaybackRate(value));
}

template <typename D> void impl_ISystemMediaTransportControls2<D>::UpdateTimelineProperties(const Windows::Media::SystemMediaTransportControlsTimelineProperties & timelineProperties) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls2)->abi_UpdateTimelineProperties(get_abi(timelineProperties)));
}

template <typename D> event_token impl_ISystemMediaTransportControls2<D>::PlaybackPositionChangeRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::PlaybackPositionChangeRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls2)->add_PlaybackPositionChangeRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISystemMediaTransportControls2> impl_ISystemMediaTransportControls2<D>::PlaybackPositionChangeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::PlaybackPositionChangeRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISystemMediaTransportControls2>(this, &ABI::Windows::Media::ISystemMediaTransportControls2::remove_PlaybackPositionChangeRequested, PlaybackPositionChangeRequested(handler));
}

template <typename D> void impl_ISystemMediaTransportControls2<D>::PlaybackPositionChangeRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls2)->remove_PlaybackPositionChangeRequested(token));
}

template <typename D> event_token impl_ISystemMediaTransportControls2<D>::PlaybackRateChangeRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::PlaybackRateChangeRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls2)->add_PlaybackRateChangeRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISystemMediaTransportControls2> impl_ISystemMediaTransportControls2<D>::PlaybackRateChangeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::PlaybackRateChangeRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISystemMediaTransportControls2>(this, &ABI::Windows::Media::ISystemMediaTransportControls2::remove_PlaybackRateChangeRequested, PlaybackRateChangeRequested(handler));
}

template <typename D> void impl_ISystemMediaTransportControls2<D>::PlaybackRateChangeRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls2)->remove_PlaybackRateChangeRequested(token));
}

template <typename D> event_token impl_ISystemMediaTransportControls2<D>::ShuffleEnabledChangeRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::ShuffleEnabledChangeRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls2)->add_ShuffleEnabledChangeRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISystemMediaTransportControls2> impl_ISystemMediaTransportControls2<D>::ShuffleEnabledChangeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::ShuffleEnabledChangeRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISystemMediaTransportControls2>(this, &ABI::Windows::Media::ISystemMediaTransportControls2::remove_ShuffleEnabledChangeRequested, ShuffleEnabledChangeRequested(handler));
}

template <typename D> void impl_ISystemMediaTransportControls2<D>::ShuffleEnabledChangeRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls2)->remove_ShuffleEnabledChangeRequested(token));
}

template <typename D> event_token impl_ISystemMediaTransportControls2<D>::AutoRepeatModeChangeRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::AutoRepeatModeChangeRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls2)->add_AutoRepeatModeChangeRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISystemMediaTransportControls2> impl_ISystemMediaTransportControls2<D>::AutoRepeatModeChangeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::AutoRepeatModeChangeRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISystemMediaTransportControls2>(this, &ABI::Windows::Media::ISystemMediaTransportControls2::remove_AutoRepeatModeChangeRequested, AutoRepeatModeChangeRequested(handler));
}

template <typename D> void impl_ISystemMediaTransportControls2<D>::AutoRepeatModeChangeRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(ISystemMediaTransportControls2)->remove_AutoRepeatModeChangeRequested(token));
}

template <typename D> Windows::Media::SystemMediaTransportControls impl_ISystemMediaTransportControlsStatics<D>::GetForCurrentView() const
{
    Windows::Media::SystemMediaTransportControls mediaControl { nullptr };
    check_hresult(WINRT_SHIM(ISystemMediaTransportControlsStatics)->abi_GetForCurrentView(put_abi(mediaControl)));
    return mediaControl;
}

template <typename D> void impl_IMediaExtension<D>::SetProperties(const Windows::Foundation::Collections::IPropertySet & configuration) const
{
    check_hresult(WINRT_SHIM(IMediaExtension)->abi_SetProperties(get_abi(configuration)));
}

template <typename D> void impl_IMediaExtensionManager<D>::RegisterSchemeHandler(hstring_view activatableClassId, hstring_view scheme) const
{
    check_hresult(WINRT_SHIM(IMediaExtensionManager)->abi_RegisterSchemeHandler(get_abi(activatableClassId), get_abi(scheme)));
}

template <typename D> void impl_IMediaExtensionManager<D>::RegisterSchemeHandler(hstring_view activatableClassId, hstring_view scheme, const Windows::Foundation::Collections::IPropertySet & configuration) const
{
    check_hresult(WINRT_SHIM(IMediaExtensionManager)->abi_RegisterSchemeHandlerWithSettings(get_abi(activatableClassId), get_abi(scheme), get_abi(configuration)));
}

template <typename D> void impl_IMediaExtensionManager<D>::RegisterByteStreamHandler(hstring_view activatableClassId, hstring_view fileExtension, hstring_view mimeType) const
{
    check_hresult(WINRT_SHIM(IMediaExtensionManager)->abi_RegisterByteStreamHandler(get_abi(activatableClassId), get_abi(fileExtension), get_abi(mimeType)));
}

template <typename D> void impl_IMediaExtensionManager<D>::RegisterByteStreamHandler(hstring_view activatableClassId, hstring_view fileExtension, hstring_view mimeType, const Windows::Foundation::Collections::IPropertySet & configuration) const
{
    check_hresult(WINRT_SHIM(IMediaExtensionManager)->abi_RegisterByteStreamHandlerWithSettings(get_abi(activatableClassId), get_abi(fileExtension), get_abi(mimeType), get_abi(configuration)));
}

template <typename D> void impl_IMediaExtensionManager<D>::RegisterAudioDecoder(hstring_view activatableClassId, GUID inputSubtype, GUID outputSubtype) const
{
    check_hresult(WINRT_SHIM(IMediaExtensionManager)->abi_RegisterAudioDecoder(get_abi(activatableClassId), inputSubtype, outputSubtype));
}

template <typename D> void impl_IMediaExtensionManager<D>::RegisterAudioDecoder(hstring_view activatableClassId, GUID inputSubtype, GUID outputSubtype, const Windows::Foundation::Collections::IPropertySet & configuration) const
{
    check_hresult(WINRT_SHIM(IMediaExtensionManager)->abi_RegisterAudioDecoderWithSettings(get_abi(activatableClassId), inputSubtype, outputSubtype, get_abi(configuration)));
}

template <typename D> void impl_IMediaExtensionManager<D>::RegisterAudioEncoder(hstring_view activatableClassId, GUID inputSubtype, GUID outputSubtype) const
{
    check_hresult(WINRT_SHIM(IMediaExtensionManager)->abi_RegisterAudioEncoder(get_abi(activatableClassId), inputSubtype, outputSubtype));
}

template <typename D> void impl_IMediaExtensionManager<D>::RegisterAudioEncoder(hstring_view activatableClassId, GUID inputSubtype, GUID outputSubtype, const Windows::Foundation::Collections::IPropertySet & configuration) const
{
    check_hresult(WINRT_SHIM(IMediaExtensionManager)->abi_RegisterAudioEncoderWithSettings(get_abi(activatableClassId), inputSubtype, outputSubtype, get_abi(configuration)));
}

template <typename D> void impl_IMediaExtensionManager<D>::RegisterVideoDecoder(hstring_view activatableClassId, GUID inputSubtype, GUID outputSubtype) const
{
    check_hresult(WINRT_SHIM(IMediaExtensionManager)->abi_RegisterVideoDecoder(get_abi(activatableClassId), inputSubtype, outputSubtype));
}

template <typename D> void impl_IMediaExtensionManager<D>::RegisterVideoDecoder(hstring_view activatableClassId, GUID inputSubtype, GUID outputSubtype, const Windows::Foundation::Collections::IPropertySet & configuration) const
{
    check_hresult(WINRT_SHIM(IMediaExtensionManager)->abi_RegisterVideoDecoderWithSettings(get_abi(activatableClassId), inputSubtype, outputSubtype, get_abi(configuration)));
}

template <typename D> void impl_IMediaExtensionManager<D>::RegisterVideoEncoder(hstring_view activatableClassId, GUID inputSubtype, GUID outputSubtype) const
{
    check_hresult(WINRT_SHIM(IMediaExtensionManager)->abi_RegisterVideoEncoder(get_abi(activatableClassId), inputSubtype, outputSubtype));
}

template <typename D> void impl_IMediaExtensionManager<D>::RegisterVideoEncoder(hstring_view activatableClassId, GUID inputSubtype, GUID outputSubtype, const Windows::Foundation::Collections::IPropertySet & configuration) const
{
    check_hresult(WINRT_SHIM(IMediaExtensionManager)->abi_RegisterVideoEncoderWithSettings(get_abi(activatableClassId), inputSubtype, outputSubtype, get_abi(configuration)));
}

template <typename D> hstring impl_IVideoEffectsStatics<D>::VideoStabilization() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVideoEffectsStatics)->get_VideoStabilization(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaTimelineController<D>::Start() const
{
    check_hresult(WINRT_SHIM(IMediaTimelineController)->abi_Start());
}

template <typename D> void impl_IMediaTimelineController<D>::Resume() const
{
    check_hresult(WINRT_SHIM(IMediaTimelineController)->abi_Resume());
}

template <typename D> void impl_IMediaTimelineController<D>::Pause() const
{
    check_hresult(WINRT_SHIM(IMediaTimelineController)->abi_Pause());
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaTimelineController<D>::Position() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaTimelineController)->get_Position(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaTimelineController<D>::Position(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMediaTimelineController)->put_Position(get_abi(value)));
}

template <typename D> double impl_IMediaTimelineController<D>::ClockRate() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMediaTimelineController)->get_ClockRate(&value));
    return value;
}

template <typename D> void impl_IMediaTimelineController<D>::ClockRate(double value) const
{
    check_hresult(WINRT_SHIM(IMediaTimelineController)->put_ClockRate(value));
}

template <typename D> Windows::Media::MediaTimelineControllerState impl_IMediaTimelineController<D>::State() const
{
    Windows::Media::MediaTimelineControllerState value {};
    check_hresult(WINRT_SHIM(IMediaTimelineController)->get_State(&value));
    return value;
}

template <typename D> event_token impl_IMediaTimelineController<D>::PositionChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::MediaTimelineController, Windows::Foundation::IInspectable> & positionChangedEventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IMediaTimelineController)->add_PositionChanged(get_abi(positionChangedEventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IMediaTimelineController> impl_IMediaTimelineController<D>::PositionChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::MediaTimelineController, Windows::Foundation::IInspectable> & positionChangedEventHandler) const
{
    return impl::make_event_revoker<D, IMediaTimelineController>(this, &ABI::Windows::Media::IMediaTimelineController::remove_PositionChanged, PositionChanged(positionChangedEventHandler));
}

template <typename D> void impl_IMediaTimelineController<D>::PositionChanged(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IMediaTimelineController)->remove_PositionChanged(eventCookie));
}

template <typename D> event_token impl_IMediaTimelineController<D>::StateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::MediaTimelineController, Windows::Foundation::IInspectable> & stateChangedEventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IMediaTimelineController)->add_StateChanged(get_abi(stateChangedEventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IMediaTimelineController> impl_IMediaTimelineController<D>::StateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::MediaTimelineController, Windows::Foundation::IInspectable> & stateChangedEventHandler) const
{
    return impl::make_event_revoker<D, IMediaTimelineController>(this, &ABI::Windows::Media::IMediaTimelineController::remove_StateChanged, StateChanged(stateChangedEventHandler));
}

template <typename D> void impl_IMediaTimelineController<D>::StateChanged(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IMediaTimelineController)->remove_StateChanged(eventCookie));
}

template <typename D> event_token impl_IMediaControl<D>::SoundLevelChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMediaControl)->add_SoundLevelChanged(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMediaControl> impl_IMediaControl<D>::SoundLevelChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaControl>(this, &ABI::Windows::Media::IMediaControl::remove_SoundLevelChanged, SoundLevelChanged(handler));
}

template <typename D> void impl_IMediaControl<D>::SoundLevelChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMediaControl)->remove_SoundLevelChanged(cookie));
}

template <typename D> event_token impl_IMediaControl<D>::PlayPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMediaControl)->add_PlayPressed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMediaControl> impl_IMediaControl<D>::PlayPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaControl>(this, &ABI::Windows::Media::IMediaControl::remove_PlayPressed, PlayPressed(handler));
}

template <typename D> void impl_IMediaControl<D>::PlayPressed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMediaControl)->remove_PlayPressed(cookie));
}

template <typename D> event_token impl_IMediaControl<D>::PausePressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMediaControl)->add_PausePressed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMediaControl> impl_IMediaControl<D>::PausePressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaControl>(this, &ABI::Windows::Media::IMediaControl::remove_PausePressed, PausePressed(handler));
}

template <typename D> void impl_IMediaControl<D>::PausePressed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMediaControl)->remove_PausePressed(cookie));
}

template <typename D> event_token impl_IMediaControl<D>::StopPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMediaControl)->add_StopPressed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMediaControl> impl_IMediaControl<D>::StopPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaControl>(this, &ABI::Windows::Media::IMediaControl::remove_StopPressed, StopPressed(handler));
}

template <typename D> void impl_IMediaControl<D>::StopPressed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMediaControl)->remove_StopPressed(cookie));
}

template <typename D> event_token impl_IMediaControl<D>::PlayPauseTogglePressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMediaControl)->add_PlayPauseTogglePressed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMediaControl> impl_IMediaControl<D>::PlayPauseTogglePressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaControl>(this, &ABI::Windows::Media::IMediaControl::remove_PlayPauseTogglePressed, PlayPauseTogglePressed(handler));
}

template <typename D> void impl_IMediaControl<D>::PlayPauseTogglePressed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMediaControl)->remove_PlayPauseTogglePressed(cookie));
}

template <typename D> event_token impl_IMediaControl<D>::RecordPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMediaControl)->add_RecordPressed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMediaControl> impl_IMediaControl<D>::RecordPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaControl>(this, &ABI::Windows::Media::IMediaControl::remove_RecordPressed, RecordPressed(handler));
}

template <typename D> void impl_IMediaControl<D>::RecordPressed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMediaControl)->remove_RecordPressed(cookie));
}

template <typename D> event_token impl_IMediaControl<D>::NextTrackPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMediaControl)->add_NextTrackPressed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMediaControl> impl_IMediaControl<D>::NextTrackPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaControl>(this, &ABI::Windows::Media::IMediaControl::remove_NextTrackPressed, NextTrackPressed(handler));
}

template <typename D> void impl_IMediaControl<D>::NextTrackPressed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMediaControl)->remove_NextTrackPressed(cookie));
}

template <typename D> event_token impl_IMediaControl<D>::PreviousTrackPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMediaControl)->add_PreviousTrackPressed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMediaControl> impl_IMediaControl<D>::PreviousTrackPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaControl>(this, &ABI::Windows::Media::IMediaControl::remove_PreviousTrackPressed, PreviousTrackPressed(handler));
}

template <typename D> void impl_IMediaControl<D>::PreviousTrackPressed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMediaControl)->remove_PreviousTrackPressed(cookie));
}

template <typename D> event_token impl_IMediaControl<D>::FastForwardPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMediaControl)->add_FastForwardPressed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMediaControl> impl_IMediaControl<D>::FastForwardPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaControl>(this, &ABI::Windows::Media::IMediaControl::remove_FastForwardPressed, FastForwardPressed(handler));
}

template <typename D> void impl_IMediaControl<D>::FastForwardPressed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMediaControl)->remove_FastForwardPressed(cookie));
}

template <typename D> event_token impl_IMediaControl<D>::RewindPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMediaControl)->add_RewindPressed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMediaControl> impl_IMediaControl<D>::RewindPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaControl>(this, &ABI::Windows::Media::IMediaControl::remove_RewindPressed, RewindPressed(handler));
}

template <typename D> void impl_IMediaControl<D>::RewindPressed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMediaControl)->remove_RewindPressed(cookie));
}

template <typename D> event_token impl_IMediaControl<D>::ChannelUpPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMediaControl)->add_ChannelUpPressed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMediaControl> impl_IMediaControl<D>::ChannelUpPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaControl>(this, &ABI::Windows::Media::IMediaControl::remove_ChannelUpPressed, ChannelUpPressed(handler));
}

template <typename D> void impl_IMediaControl<D>::ChannelUpPressed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMediaControl)->remove_ChannelUpPressed(cookie));
}

template <typename D> event_token impl_IMediaControl<D>::ChannelDownPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMediaControl)->add_ChannelDownPressed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMediaControl> impl_IMediaControl<D>::ChannelDownPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaControl>(this, &ABI::Windows::Media::IMediaControl::remove_ChannelDownPressed, ChannelDownPressed(handler));
}

template <typename D> void impl_IMediaControl<D>::ChannelDownPressed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMediaControl)->remove_ChannelDownPressed(cookie));
}

template <typename D> Windows::Media::SoundLevel impl_IMediaControl<D>::SoundLevel() const
{
    Windows::Media::SoundLevel value {};
    check_hresult(WINRT_SHIM(IMediaControl)->get_SoundLevel(&value));
    return value;
}

template <typename D> void impl_IMediaControl<D>::TrackName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMediaControl)->put_TrackName(get_abi(value)));
}

template <typename D> hstring impl_IMediaControl<D>::TrackName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaControl)->get_TrackName(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaControl<D>::ArtistName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMediaControl)->put_ArtistName(get_abi(value)));
}

template <typename D> hstring impl_IMediaControl<D>::ArtistName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaControl)->get_ArtistName(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaControl<D>::IsPlaying(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaControl)->put_IsPlaying(value));
}

template <typename D> bool impl_IMediaControl<D>::IsPlaying() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaControl)->get_IsPlaying(&value));
    return value;
}

template <typename D> void impl_IMediaControl<D>::AlbumArt(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IMediaControl)->put_AlbumArt(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_IMediaControl<D>::AlbumArt() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IMediaControl)->get_AlbumArt(put_abi(value)));
    return value;
}

inline AudioFrame::AudioFrame(uint32_t capacity) :
    AudioFrame(get_activation_factory<AudioFrame, IAudioFrameFactory>().Create(capacity))
{}

inline event_token MediaControl::SoundLevelChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<MediaControl, IMediaControl>().SoundLevelChanged(handler);
}

inline factory_event_revoker<IMediaControl> MediaControl::SoundLevelChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<MediaControl, IMediaControl>();
    return { factory, &ABI::Windows::Media::IMediaControl::remove_SoundLevelChanged, factory.SoundLevelChanged(handler) };
}

inline void MediaControl::SoundLevelChanged(event_token cookie)
{
    get_activation_factory<MediaControl, IMediaControl>().SoundLevelChanged(cookie);
}

inline event_token MediaControl::PlayPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<MediaControl, IMediaControl>().PlayPressed(handler);
}

inline factory_event_revoker<IMediaControl> MediaControl::PlayPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<MediaControl, IMediaControl>();
    return { factory, &ABI::Windows::Media::IMediaControl::remove_PlayPressed, factory.PlayPressed(handler) };
}

inline void MediaControl::PlayPressed(event_token cookie)
{
    get_activation_factory<MediaControl, IMediaControl>().PlayPressed(cookie);
}

inline event_token MediaControl::PausePressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<MediaControl, IMediaControl>().PausePressed(handler);
}

inline factory_event_revoker<IMediaControl> MediaControl::PausePressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<MediaControl, IMediaControl>();
    return { factory, &ABI::Windows::Media::IMediaControl::remove_PausePressed, factory.PausePressed(handler) };
}

inline void MediaControl::PausePressed(event_token cookie)
{
    get_activation_factory<MediaControl, IMediaControl>().PausePressed(cookie);
}

inline event_token MediaControl::StopPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<MediaControl, IMediaControl>().StopPressed(handler);
}

inline factory_event_revoker<IMediaControl> MediaControl::StopPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<MediaControl, IMediaControl>();
    return { factory, &ABI::Windows::Media::IMediaControl::remove_StopPressed, factory.StopPressed(handler) };
}

inline void MediaControl::StopPressed(event_token cookie)
{
    get_activation_factory<MediaControl, IMediaControl>().StopPressed(cookie);
}

inline event_token MediaControl::PlayPauseTogglePressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<MediaControl, IMediaControl>().PlayPauseTogglePressed(handler);
}

inline factory_event_revoker<IMediaControl> MediaControl::PlayPauseTogglePressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<MediaControl, IMediaControl>();
    return { factory, &ABI::Windows::Media::IMediaControl::remove_PlayPauseTogglePressed, factory.PlayPauseTogglePressed(handler) };
}

inline void MediaControl::PlayPauseTogglePressed(event_token cookie)
{
    get_activation_factory<MediaControl, IMediaControl>().PlayPauseTogglePressed(cookie);
}

inline event_token MediaControl::RecordPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<MediaControl, IMediaControl>().RecordPressed(handler);
}

inline factory_event_revoker<IMediaControl> MediaControl::RecordPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<MediaControl, IMediaControl>();
    return { factory, &ABI::Windows::Media::IMediaControl::remove_RecordPressed, factory.RecordPressed(handler) };
}

inline void MediaControl::RecordPressed(event_token cookie)
{
    get_activation_factory<MediaControl, IMediaControl>().RecordPressed(cookie);
}

inline event_token MediaControl::NextTrackPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<MediaControl, IMediaControl>().NextTrackPressed(handler);
}

inline factory_event_revoker<IMediaControl> MediaControl::NextTrackPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<MediaControl, IMediaControl>();
    return { factory, &ABI::Windows::Media::IMediaControl::remove_NextTrackPressed, factory.NextTrackPressed(handler) };
}

inline void MediaControl::NextTrackPressed(event_token cookie)
{
    get_activation_factory<MediaControl, IMediaControl>().NextTrackPressed(cookie);
}

inline event_token MediaControl::PreviousTrackPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<MediaControl, IMediaControl>().PreviousTrackPressed(handler);
}

inline factory_event_revoker<IMediaControl> MediaControl::PreviousTrackPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<MediaControl, IMediaControl>();
    return { factory, &ABI::Windows::Media::IMediaControl::remove_PreviousTrackPressed, factory.PreviousTrackPressed(handler) };
}

inline void MediaControl::PreviousTrackPressed(event_token cookie)
{
    get_activation_factory<MediaControl, IMediaControl>().PreviousTrackPressed(cookie);
}

inline event_token MediaControl::FastForwardPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<MediaControl, IMediaControl>().FastForwardPressed(handler);
}

inline factory_event_revoker<IMediaControl> MediaControl::FastForwardPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<MediaControl, IMediaControl>();
    return { factory, &ABI::Windows::Media::IMediaControl::remove_FastForwardPressed, factory.FastForwardPressed(handler) };
}

inline void MediaControl::FastForwardPressed(event_token cookie)
{
    get_activation_factory<MediaControl, IMediaControl>().FastForwardPressed(cookie);
}

inline event_token MediaControl::RewindPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<MediaControl, IMediaControl>().RewindPressed(handler);
}

inline factory_event_revoker<IMediaControl> MediaControl::RewindPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<MediaControl, IMediaControl>();
    return { factory, &ABI::Windows::Media::IMediaControl::remove_RewindPressed, factory.RewindPressed(handler) };
}

inline void MediaControl::RewindPressed(event_token cookie)
{
    get_activation_factory<MediaControl, IMediaControl>().RewindPressed(cookie);
}

inline event_token MediaControl::ChannelUpPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<MediaControl, IMediaControl>().ChannelUpPressed(handler);
}

inline factory_event_revoker<IMediaControl> MediaControl::ChannelUpPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<MediaControl, IMediaControl>();
    return { factory, &ABI::Windows::Media::IMediaControl::remove_ChannelUpPressed, factory.ChannelUpPressed(handler) };
}

inline void MediaControl::ChannelUpPressed(event_token cookie)
{
    get_activation_factory<MediaControl, IMediaControl>().ChannelUpPressed(cookie);
}

inline event_token MediaControl::ChannelDownPressed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<MediaControl, IMediaControl>().ChannelDownPressed(handler);
}

inline factory_event_revoker<IMediaControl> MediaControl::ChannelDownPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<MediaControl, IMediaControl>();
    return { factory, &ABI::Windows::Media::IMediaControl::remove_ChannelDownPressed, factory.ChannelDownPressed(handler) };
}

inline void MediaControl::ChannelDownPressed(event_token cookie)
{
    get_activation_factory<MediaControl, IMediaControl>().ChannelDownPressed(cookie);
}

inline Windows::Media::SoundLevel MediaControl::SoundLevel()
{
    return get_activation_factory<MediaControl, IMediaControl>().SoundLevel();
}

inline void MediaControl::TrackName(hstring_view value)
{
    get_activation_factory<MediaControl, IMediaControl>().TrackName(value);
}

inline hstring MediaControl::TrackName()
{
    return get_activation_factory<MediaControl, IMediaControl>().TrackName();
}

inline void MediaControl::ArtistName(hstring_view value)
{
    get_activation_factory<MediaControl, IMediaControl>().ArtistName(value);
}

inline hstring MediaControl::ArtistName()
{
    return get_activation_factory<MediaControl, IMediaControl>().ArtistName();
}

inline void MediaControl::IsPlaying(bool value)
{
    get_activation_factory<MediaControl, IMediaControl>().IsPlaying(value);
}

inline bool MediaControl::IsPlaying()
{
    return get_activation_factory<MediaControl, IMediaControl>().IsPlaying();
}

inline void MediaControl::AlbumArt(const Windows::Foundation::Uri & value)
{
    get_activation_factory<MediaControl, IMediaControl>().AlbumArt(value);
}

inline Windows::Foundation::Uri MediaControl::AlbumArt()
{
    return get_activation_factory<MediaControl, IMediaControl>().AlbumArt();
}

inline MediaExtensionManager::MediaExtensionManager() :
    MediaExtensionManager(activate_instance<MediaExtensionManager>())
{}

inline hstring MediaMarkerTypes::Bookmark()
{
    return get_activation_factory<MediaMarkerTypes, IMediaMarkerTypesStatics>().Bookmark();
}

inline MediaTimelineController::MediaTimelineController() :
    MediaTimelineController(activate_instance<MediaTimelineController>())
{}

inline Windows::Media::SystemMediaTransportControls SystemMediaTransportControls::GetForCurrentView()
{
    return get_activation_factory<SystemMediaTransportControls, ISystemMediaTransportControlsStatics>().GetForCurrentView();
}

inline SystemMediaTransportControlsTimelineProperties::SystemMediaTransportControlsTimelineProperties() :
    SystemMediaTransportControlsTimelineProperties(activate_instance<SystemMediaTransportControlsTimelineProperties>())
{}

inline hstring VideoEffects::VideoStabilization()
{
    return get_activation_factory<VideoEffects, IVideoEffectsStatics>().VideoStabilization();
}

inline VideoFrame::VideoFrame(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height) :
    VideoFrame(get_activation_factory<VideoFrame, IVideoFrameFactory>().Create(format, width, height))
{}

inline VideoFrame::VideoFrame(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::BitmapAlphaMode alpha) :
    VideoFrame(get_activation_factory<VideoFrame, IVideoFrameFactory>().CreateWithAlpha(format, width, height, alpha))
{}

}

}
#pragma warning(pop)
