// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Media.MediaProperties.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Media.Core.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.Graphics.DirectX.Direct3D11.3.h"
#include "internal/Windows.Media.Effects.3.h"
#include "internal/Windows.Media.Editing.3.h"
#include "Windows.Media.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::Editing::IBackgroundAudioTrack> : produce_base<D, Windows::Media::Editing::IBackgroundAudioTrack>
{
    HRESULT __stdcall get_TrimTimeFromStart(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrimTimeFromStart());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TrimTimeFromStart(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrimTimeFromStart(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrimTimeFromEnd(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrimTimeFromEnd());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TrimTimeFromEnd(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrimTimeFromEnd(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OriginalDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OriginalDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrimmedDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrimmedDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserData(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Delay(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Delay(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Delay(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Delay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Volume(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Volume(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Volume(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Volume());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clone(impl::abi_arg_out<Windows::Media::Editing::IBackgroundAudioTrack> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Clone());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAudioEncodingProperties(impl::abi_arg_out<Windows::Media::MediaProperties::IAudioEncodingProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetAudioEncodingProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioEffectDefinitions(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Media::Effects::IAudioEffectDefinition>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioEffectDefinitions());
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
struct produce<D, Windows::Media::Editing::IBackgroundAudioTrackStatics> : produce_base<D, Windows::Media::Editing::IBackgroundAudioTrackStatics>
{
    HRESULT __stdcall abi_CreateFromEmbeddedAudioTrack(impl::abi_arg_in<Windows::Media::Editing::IEmbeddedAudioTrack> embeddedAudioTrack, impl::abi_arg_out<Windows::Media::Editing::IBackgroundAudioTrack> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFromEmbeddedAudioTrack(*reinterpret_cast<const Windows::Media::Editing::EmbeddedAudioTrack *>(&embeddedAudioTrack)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromFileAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Editing::BackgroundAudioTrack>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateFromFileAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Editing::IEmbeddedAudioTrack> : produce_base<D, Windows::Media::Editing::IEmbeddedAudioTrack>
{
    HRESULT __stdcall abi_GetAudioEncodingProperties(impl::abi_arg_out<Windows::Media::MediaProperties::IAudioEncodingProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetAudioEncodingProperties());
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
struct produce<D, Windows::Media::Editing::IMediaClip> : produce_base<D, Windows::Media::Editing::IMediaClip>
{
    HRESULT __stdcall get_TrimTimeFromStart(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrimTimeFromStart());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TrimTimeFromStart(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrimTimeFromStart(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrimTimeFromEnd(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrimTimeFromEnd());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TrimTimeFromEnd(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrimTimeFromEnd(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OriginalDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OriginalDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrimmedDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrimmedDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserData(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clone(impl::abi_arg_out<Windows::Media::Editing::IMediaClip> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Clone());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StartTimeInComposition(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartTimeInComposition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndTimeInComposition(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndTimeInComposition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EmbeddedAudioTracks(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Editing::EmbeddedAudioTrack>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmbeddedAudioTracks());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SelectedEmbeddedAudioTrackIndex(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelectedEmbeddedAudioTrackIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SelectedEmbeddedAudioTrackIndex(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectedEmbeddedAudioTrackIndex(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Volume(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Volume(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Volume(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Volume());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetVideoEncodingProperties(impl::abi_arg_out<Windows::Media::MediaProperties::IVideoEncodingProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetVideoEncodingProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioEffectDefinitions(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Media::Effects::IAudioEffectDefinition>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioEffectDefinitions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoEffectDefinitions(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Media::Effects::IVideoEffectDefinition>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoEffectDefinitions());
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
struct produce<D, Windows::Media::Editing::IMediaClipStatics> : produce_base<D, Windows::Media::Editing::IMediaClipStatics>
{
    HRESULT __stdcall abi_CreateFromColor(impl::abi_arg_in<Windows::UI::Color> color, impl::abi_arg_in<Windows::Foundation::TimeSpan> originalDuration, impl::abi_arg_out<Windows::Media::Editing::IMediaClip> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFromColor(*reinterpret_cast<const Windows::UI::Color *>(&color), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&originalDuration)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromFileAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaClip>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateFromFileAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromImageFileAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<Windows::Foundation::TimeSpan> originalDuration, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaClip>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateFromImageFileAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&originalDuration)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Editing::IMediaClipStatics2> : produce_base<D, Windows::Media::Editing::IMediaClipStatics2>
{
    HRESULT __stdcall abi_CreateFromSurface(impl::abi_arg_in<Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> surface, impl::abi_arg_in<Windows::Foundation::TimeSpan> originalDuration, impl::abi_arg_out<Windows::Media::Editing::IMediaClip> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFromSurface(*reinterpret_cast<const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface *>(&surface), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&originalDuration)));
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
struct produce<D, Windows::Media::Editing::IMediaComposition> : produce_base<D, Windows::Media::Editing::IMediaComposition>
{
    HRESULT __stdcall get_Duration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Clips(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Media::Editing::MediaClip>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Clips());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackgroundAudioTracks(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Media::Editing::BackgroundAudioTrack>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BackgroundAudioTracks());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserData(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clone(impl::abi_arg_out<Windows::Media::Editing::IMediaComposition> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Clone());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SaveAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetThumbnailAsync(impl::abi_arg_in<Windows::Foundation::TimeSpan> timeFromStart, int32_t scaledWidth, int32_t scaledHeight, Windows::Media::Editing::VideoFramePrecision framePrecision, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetThumbnailAsync(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&timeFromStart), scaledWidth, scaledHeight, framePrecision));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetThumbnailsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::TimeSpan>> timesFromStart, int32_t scaledWidth, int32_t scaledHeight, Windows::Media::Editing::VideoFramePrecision framePrecision, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::ImageStream>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetThumbnailsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::TimeSpan> *>(&timesFromStart), scaledWidth, scaledHeight, framePrecision));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RenderToFileAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> destination, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Transcoding::TranscodeFailureReason, double>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RenderToFileAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&destination)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RenderToFileWithTrimmingPreferenceAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> destination, Windows::Media::Editing::MediaTrimmingPreference trimmingPreference, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Transcoding::TranscodeFailureReason, double>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RenderToFileAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&destination), trimmingPreference));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RenderToFileWithProfileAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> destination, Windows::Media::Editing::MediaTrimmingPreference trimmingPreference, impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Transcoding::TranscodeFailureReason, double>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RenderToFileAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&destination), trimmingPreference, *reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDefaultEncodingProfile(impl::abi_arg_out<Windows::Media::MediaProperties::IMediaEncodingProfile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateDefaultEncodingProfile());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GenerateMediaStreamSource(impl::abi_arg_out<Windows::Media::Core::IMediaStreamSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GenerateMediaStreamSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GenerateMediaStreamSourceWithProfile(impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, impl::abi_arg_out<Windows::Media::Core::IMediaStreamSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GenerateMediaStreamSource(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GeneratePreviewMediaStreamSource(int32_t scaledWidth, int32_t scaledHeight, impl::abi_arg_out<Windows::Media::Core::IMediaStreamSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GeneratePreviewMediaStreamSource(scaledWidth, scaledHeight));
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
struct produce<D, Windows::Media::Editing::IMediaComposition2> : produce_base<D, Windows::Media::Editing::IMediaComposition2>
{
    HRESULT __stdcall get_OverlayLayers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Media::Editing::MediaOverlayLayer>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OverlayLayers());
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
struct produce<D, Windows::Media::Editing::IMediaCompositionStatics> : produce_base<D, Windows::Media::Editing::IMediaCompositionStatics>
{
    HRESULT __stdcall abi_LoadAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaComposition>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LoadAsync(*reinterpret_cast<const Windows::Storage::StorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Editing::IMediaOverlay> : produce_base<D, Windows::Media::Editing::IMediaOverlay>
{
    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
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

    HRESULT __stdcall put_Position(impl::abi_arg_in<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Position(*reinterpret_cast<const Windows::Foundation::Rect *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Delay(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Delay(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Delay(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Delay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Opacity(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Opacity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Opacity(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Opacity(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clone(impl::abi_arg_out<Windows::Media::Editing::IMediaOverlay> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Clone());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Clip(impl::abi_arg_out<Windows::Media::Editing::IMediaClip> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Clip());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AudioEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Editing::IMediaOverlayFactory> : produce_base<D, Windows::Media::Editing::IMediaOverlayFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Media::Editing::IMediaClip> clip, impl::abi_arg_out<Windows::Media::Editing::IMediaOverlay> mediaOverlay) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *mediaOverlay = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Media::Editing::MediaClip *>(&clip)));
            return S_OK;
        }
        catch (...)
        {
            *mediaOverlay = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithPositionAndOpacity(impl::abi_arg_in<Windows::Media::Editing::IMediaClip> clip, impl::abi_arg_in<Windows::Foundation::Rect> position, double opacity, impl::abi_arg_out<Windows::Media::Editing::IMediaOverlay> mediaOverlay) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *mediaOverlay = detach_abi(this->shim().CreateWithPositionAndOpacity(*reinterpret_cast<const Windows::Media::Editing::MediaClip *>(&clip), *reinterpret_cast<const Windows::Foundation::Rect *>(&position), opacity));
            return S_OK;
        }
        catch (...)
        {
            *mediaOverlay = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Editing::IMediaOverlayLayer> : produce_base<D, Windows::Media::Editing::IMediaOverlayLayer>
{
    HRESULT __stdcall abi_Clone(impl::abi_arg_out<Windows::Media::Editing::IMediaOverlayLayer> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Clone());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Overlays(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Media::Editing::MediaOverlay>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Overlays());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CustomCompositorDefinition(impl::abi_arg_out<Windows::Media::Effects::IVideoCompositorDefinition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CustomCompositorDefinition());
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
struct produce<D, Windows::Media::Editing::IMediaOverlayLayerFactory> : produce_base<D, Windows::Media::Editing::IMediaOverlayLayerFactory>
{
    HRESULT __stdcall abi_CreateWithCompositorDefinition(impl::abi_arg_in<Windows::Media::Effects::IVideoCompositorDefinition> compositorDefinition, impl::abi_arg_out<Windows::Media::Editing::IMediaOverlayLayer> mediaOverlayLayer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *mediaOverlayLayer = detach_abi(this->shim().CreateWithCompositorDefinition(*reinterpret_cast<const Windows::Media::Effects::IVideoCompositorDefinition *>(&compositorDefinition)));
            return S_OK;
        }
        catch (...)
        {
            *mediaOverlayLayer = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::Editing {

template <typename D> Windows::Foundation::TimeSpan impl_IMediaClip<D>::TrimTimeFromStart() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaClip)->get_TrimTimeFromStart(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaClip<D>::TrimTimeFromStart(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMediaClip)->put_TrimTimeFromStart(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaClip<D>::TrimTimeFromEnd() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaClip)->get_TrimTimeFromEnd(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaClip<D>::TrimTimeFromEnd(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMediaClip)->put_TrimTimeFromEnd(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaClip<D>::OriginalDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaClip)->get_OriginalDuration(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaClip<D>::TrimmedDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaClip)->get_TrimmedDuration(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, hstring> impl_IMediaClip<D>::UserData() const
{
    Windows::Foundation::Collections::IMap<hstring, hstring> value;
    check_hresult(WINRT_SHIM(IMediaClip)->get_UserData(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Editing::MediaClip impl_IMediaClip<D>::Clone() const
{
    Windows::Media::Editing::MediaClip result { nullptr };
    check_hresult(WINRT_SHIM(IMediaClip)->abi_Clone(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaClip<D>::StartTimeInComposition() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaClip)->get_StartTimeInComposition(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaClip<D>::EndTimeInComposition() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaClip)->get_EndTimeInComposition(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Editing::EmbeddedAudioTrack> impl_IMediaClip<D>::EmbeddedAudioTracks() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Editing::EmbeddedAudioTrack> value;
    check_hresult(WINRT_SHIM(IMediaClip)->get_EmbeddedAudioTracks(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IMediaClip<D>::SelectedEmbeddedAudioTrackIndex() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMediaClip)->get_SelectedEmbeddedAudioTrackIndex(&value));
    return value;
}

template <typename D> void impl_IMediaClip<D>::SelectedEmbeddedAudioTrackIndex(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IMediaClip)->put_SelectedEmbeddedAudioTrackIndex(value));
}

template <typename D> void impl_IMediaClip<D>::Volume(double value) const
{
    check_hresult(WINRT_SHIM(IMediaClip)->put_Volume(value));
}

template <typename D> double impl_IMediaClip<D>::Volume() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMediaClip)->get_Volume(&value));
    return value;
}

template <typename D> Windows::Media::MediaProperties::VideoEncodingProperties impl_IMediaClip<D>::GetVideoEncodingProperties() const
{
    Windows::Media::MediaProperties::VideoEncodingProperties value { nullptr };
    check_hresult(WINRT_SHIM(IMediaClip)->abi_GetVideoEncodingProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Media::Effects::IAudioEffectDefinition> impl_IMediaClip<D>::AudioEffectDefinitions() const
{
    Windows::Foundation::Collections::IVector<Windows::Media::Effects::IAudioEffectDefinition> value;
    check_hresult(WINRT_SHIM(IMediaClip)->get_AudioEffectDefinitions(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Media::Effects::IVideoEffectDefinition> impl_IMediaClip<D>::VideoEffectDefinitions() const
{
    Windows::Foundation::Collections::IVector<Windows::Media::Effects::IVideoEffectDefinition> value;
    check_hresult(WINRT_SHIM(IMediaClip)->get_VideoEffectDefinitions(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaComposition<D>::Duration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaComposition)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Media::Editing::MediaClip> impl_IMediaComposition<D>::Clips() const
{
    Windows::Foundation::Collections::IVector<Windows::Media::Editing::MediaClip> value;
    check_hresult(WINRT_SHIM(IMediaComposition)->get_Clips(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Media::Editing::BackgroundAudioTrack> impl_IMediaComposition<D>::BackgroundAudioTracks() const
{
    Windows::Foundation::Collections::IVector<Windows::Media::Editing::BackgroundAudioTrack> value;
    check_hresult(WINRT_SHIM(IMediaComposition)->get_BackgroundAudioTracks(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, hstring> impl_IMediaComposition<D>::UserData() const
{
    Windows::Foundation::Collections::IMap<hstring, hstring> value;
    check_hresult(WINRT_SHIM(IMediaComposition)->get_UserData(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Editing::MediaComposition impl_IMediaComposition<D>::Clone() const
{
    Windows::Media::Editing::MediaComposition result { nullptr };
    check_hresult(WINRT_SHIM(IMediaComposition)->abi_Clone(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaComposition<D>::SaveAsync(const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IMediaComposition)->abi_SaveAsync(get_abi(file), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream> impl_IMediaComposition<D>::GetThumbnailAsync(const Windows::Foundation::TimeSpan & timeFromStart, int32_t scaledWidth, int32_t scaledHeight, Windows::Media::Editing::VideoFramePrecision framePrecision) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream> operation;
    check_hresult(WINRT_SHIM(IMediaComposition)->abi_GetThumbnailAsync(get_abi(timeFromStart), scaledWidth, scaledHeight, framePrecision, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::ImageStream>> impl_IMediaComposition<D>::GetThumbnailsAsync(iterable<Windows::Foundation::TimeSpan> timesFromStart, int32_t scaledWidth, int32_t scaledHeight, Windows::Media::Editing::VideoFramePrecision framePrecision) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::ImageStream>> operation;
    check_hresult(WINRT_SHIM(IMediaComposition)->abi_GetThumbnailsAsync(get_abi(timesFromStart), scaledWidth, scaledHeight, framePrecision, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Transcoding::TranscodeFailureReason, double> impl_IMediaComposition<D>::RenderToFileAsync(const Windows::Storage::IStorageFile & destination) const
{
    Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Transcoding::TranscodeFailureReason, double> operation;
    check_hresult(WINRT_SHIM(IMediaComposition)->abi_RenderToFileAsync(get_abi(destination), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Transcoding::TranscodeFailureReason, double> impl_IMediaComposition<D>::RenderToFileAsync(const Windows::Storage::IStorageFile & destination, Windows::Media::Editing::MediaTrimmingPreference trimmingPreference) const
{
    Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Transcoding::TranscodeFailureReason, double> operation;
    check_hresult(WINRT_SHIM(IMediaComposition)->abi_RenderToFileWithTrimmingPreferenceAsync(get_abi(destination), trimmingPreference, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Transcoding::TranscodeFailureReason, double> impl_IMediaComposition<D>::RenderToFileAsync(const Windows::Storage::IStorageFile & destination, Windows::Media::Editing::MediaTrimmingPreference trimmingPreference, const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile) const
{
    Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Transcoding::TranscodeFailureReason, double> operation;
    check_hresult(WINRT_SHIM(IMediaComposition)->abi_RenderToFileWithProfileAsync(get_abi(destination), trimmingPreference, get_abi(encodingProfile), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Media::MediaProperties::MediaEncodingProfile impl_IMediaComposition<D>::CreateDefaultEncodingProfile() const
{
    Windows::Media::MediaProperties::MediaEncodingProfile value { nullptr };
    check_hresult(WINRT_SHIM(IMediaComposition)->abi_CreateDefaultEncodingProfile(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::MediaStreamSource impl_IMediaComposition<D>::GenerateMediaStreamSource() const
{
    Windows::Media::Core::MediaStreamSource value { nullptr };
    check_hresult(WINRT_SHIM(IMediaComposition)->abi_GenerateMediaStreamSource(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::MediaStreamSource impl_IMediaComposition<D>::GenerateMediaStreamSource(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile) const
{
    Windows::Media::Core::MediaStreamSource value { nullptr };
    check_hresult(WINRT_SHIM(IMediaComposition)->abi_GenerateMediaStreamSourceWithProfile(get_abi(encodingProfile), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::MediaStreamSource impl_IMediaComposition<D>::GeneratePreviewMediaStreamSource(int32_t scaledWidth, int32_t scaledHeight) const
{
    Windows::Media::Core::MediaStreamSource value { nullptr };
    check_hresult(WINRT_SHIM(IMediaComposition)->abi_GeneratePreviewMediaStreamSource(scaledWidth, scaledHeight, put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Editing::MediaClip impl_IMediaClipStatics<D>::CreateFromColor(const Windows::UI::Color & color, const Windows::Foundation::TimeSpan & originalDuration) const
{
    Windows::Media::Editing::MediaClip value { nullptr };
    check_hresult(WINRT_SHIM(IMediaClipStatics)->abi_CreateFromColor(get_abi(color), get_abi(originalDuration), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaClip> impl_IMediaClipStatics<D>::CreateFromFileAsync(const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaClip> operation;
    check_hresult(WINRT_SHIM(IMediaClipStatics)->abi_CreateFromFileAsync(get_abi(file), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaClip> impl_IMediaClipStatics<D>::CreateFromImageFileAsync(const Windows::Storage::IStorageFile & file, const Windows::Foundation::TimeSpan & originalDuration) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaClip> operation;
    check_hresult(WINRT_SHIM(IMediaClipStatics)->abi_CreateFromImageFileAsync(get_abi(file), get_abi(originalDuration), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Media::Editing::MediaClip impl_IMediaClipStatics2<D>::CreateFromSurface(const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface & surface, const Windows::Foundation::TimeSpan & originalDuration) const
{
    Windows::Media::Editing::MediaClip value { nullptr };
    check_hresult(WINRT_SHIM(IMediaClipStatics2)->abi_CreateFromSurface(get_abi(surface), get_abi(originalDuration), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaComposition> impl_IMediaCompositionStatics<D>::LoadAsync(const Windows::Storage::StorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaComposition> operation;
    check_hresult(WINRT_SHIM(IMediaCompositionStatics)->abi_LoadAsync(get_abi(file), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Media::MediaProperties::AudioEncodingProperties impl_IEmbeddedAudioTrack<D>::GetAudioEncodingProperties() const
{
    Windows::Media::MediaProperties::AudioEncodingProperties value { nullptr };
    check_hresult(WINRT_SHIM(IEmbeddedAudioTrack)->abi_GetAudioEncodingProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IBackgroundAudioTrack<D>::TrimTimeFromStart() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IBackgroundAudioTrack)->get_TrimTimeFromStart(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundAudioTrack<D>::TrimTimeFromStart(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IBackgroundAudioTrack)->put_TrimTimeFromStart(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IBackgroundAudioTrack<D>::TrimTimeFromEnd() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IBackgroundAudioTrack)->get_TrimTimeFromEnd(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundAudioTrack<D>::TrimTimeFromEnd(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IBackgroundAudioTrack)->put_TrimTimeFromEnd(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IBackgroundAudioTrack<D>::OriginalDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IBackgroundAudioTrack)->get_OriginalDuration(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IBackgroundAudioTrack<D>::TrimmedDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IBackgroundAudioTrack)->get_TrimmedDuration(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, hstring> impl_IBackgroundAudioTrack<D>::UserData() const
{
    Windows::Foundation::Collections::IMap<hstring, hstring> value;
    check_hresult(WINRT_SHIM(IBackgroundAudioTrack)->get_UserData(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundAudioTrack<D>::Delay(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IBackgroundAudioTrack)->put_Delay(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IBackgroundAudioTrack<D>::Delay() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IBackgroundAudioTrack)->get_Delay(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundAudioTrack<D>::Volume(double value) const
{
    check_hresult(WINRT_SHIM(IBackgroundAudioTrack)->put_Volume(value));
}

template <typename D> double impl_IBackgroundAudioTrack<D>::Volume() const
{
    double value {};
    check_hresult(WINRT_SHIM(IBackgroundAudioTrack)->get_Volume(&value));
    return value;
}

template <typename D> Windows::Media::Editing::BackgroundAudioTrack impl_IBackgroundAudioTrack<D>::Clone() const
{
    Windows::Media::Editing::BackgroundAudioTrack value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundAudioTrack)->abi_Clone(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::MediaProperties::AudioEncodingProperties impl_IBackgroundAudioTrack<D>::GetAudioEncodingProperties() const
{
    Windows::Media::MediaProperties::AudioEncodingProperties value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundAudioTrack)->abi_GetAudioEncodingProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Media::Effects::IAudioEffectDefinition> impl_IBackgroundAudioTrack<D>::AudioEffectDefinitions() const
{
    Windows::Foundation::Collections::IVector<Windows::Media::Effects::IAudioEffectDefinition> value;
    check_hresult(WINRT_SHIM(IBackgroundAudioTrack)->get_AudioEffectDefinitions(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Editing::BackgroundAudioTrack impl_IBackgroundAudioTrackStatics<D>::CreateFromEmbeddedAudioTrack(const Windows::Media::Editing::EmbeddedAudioTrack & embeddedAudioTrack) const
{
    Windows::Media::Editing::BackgroundAudioTrack value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundAudioTrackStatics)->abi_CreateFromEmbeddedAudioTrack(get_abi(embeddedAudioTrack), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Editing::BackgroundAudioTrack> impl_IBackgroundAudioTrackStatics<D>::CreateFromFileAsync(const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Editing::BackgroundAudioTrack> operation;
    check_hresult(WINRT_SHIM(IBackgroundAudioTrackStatics)->abi_CreateFromFileAsync(get_abi(file), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Media::Editing::MediaOverlayLayer> impl_IMediaComposition2<D>::OverlayLayers() const
{
    Windows::Foundation::Collections::IVector<Windows::Media::Editing::MediaOverlayLayer> value;
    check_hresult(WINRT_SHIM(IMediaComposition2)->get_OverlayLayers(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IMediaOverlay<D>::Position() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IMediaOverlay)->get_Position(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaOverlay<D>::Position(const Windows::Foundation::Rect & value) const
{
    check_hresult(WINRT_SHIM(IMediaOverlay)->put_Position(get_abi(value)));
}

template <typename D> void impl_IMediaOverlay<D>::Delay(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMediaOverlay)->put_Delay(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaOverlay<D>::Delay() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaOverlay)->get_Delay(put_abi(value)));
    return value;
}

template <typename D> double impl_IMediaOverlay<D>::Opacity() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMediaOverlay)->get_Opacity(&value));
    return value;
}

template <typename D> void impl_IMediaOverlay<D>::Opacity(double value) const
{
    check_hresult(WINRT_SHIM(IMediaOverlay)->put_Opacity(value));
}

template <typename D> Windows::Media::Editing::MediaOverlay impl_IMediaOverlay<D>::Clone() const
{
    Windows::Media::Editing::MediaOverlay result { nullptr };
    check_hresult(WINRT_SHIM(IMediaOverlay)->abi_Clone(put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Editing::MediaClip impl_IMediaOverlay<D>::Clip() const
{
    Windows::Media::Editing::MediaClip value { nullptr };
    check_hresult(WINRT_SHIM(IMediaOverlay)->get_Clip(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaOverlay<D>::AudioEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaOverlay)->get_AudioEnabled(&value));
    return value;
}

template <typename D> void impl_IMediaOverlay<D>::AudioEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaOverlay)->put_AudioEnabled(value));
}

template <typename D> Windows::Media::Editing::MediaOverlay impl_IMediaOverlayFactory<D>::Create(const Windows::Media::Editing::MediaClip & clip) const
{
    Windows::Media::Editing::MediaOverlay mediaOverlay { nullptr };
    check_hresult(WINRT_SHIM(IMediaOverlayFactory)->abi_Create(get_abi(clip), put_abi(mediaOverlay)));
    return mediaOverlay;
}

template <typename D> Windows::Media::Editing::MediaOverlay impl_IMediaOverlayFactory<D>::CreateWithPositionAndOpacity(const Windows::Media::Editing::MediaClip & clip, const Windows::Foundation::Rect & position, double opacity) const
{
    Windows::Media::Editing::MediaOverlay mediaOverlay { nullptr };
    check_hresult(WINRT_SHIM(IMediaOverlayFactory)->abi_CreateWithPositionAndOpacity(get_abi(clip), get_abi(position), opacity, put_abi(mediaOverlay)));
    return mediaOverlay;
}

template <typename D> Windows::Media::Editing::MediaOverlayLayer impl_IMediaOverlayLayerFactory<D>::CreateWithCompositorDefinition(const Windows::Media::Effects::IVideoCompositorDefinition & compositorDefinition) const
{
    Windows::Media::Editing::MediaOverlayLayer mediaOverlayLayer { nullptr };
    check_hresult(WINRT_SHIM(IMediaOverlayLayerFactory)->abi_CreateWithCompositorDefinition(get_abi(compositorDefinition), put_abi(mediaOverlayLayer)));
    return mediaOverlayLayer;
}

template <typename D> Windows::Media::Editing::MediaOverlayLayer impl_IMediaOverlayLayer<D>::Clone() const
{
    Windows::Media::Editing::MediaOverlayLayer result { nullptr };
    check_hresult(WINRT_SHIM(IMediaOverlayLayer)->abi_Clone(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Media::Editing::MediaOverlay> impl_IMediaOverlayLayer<D>::Overlays() const
{
    Windows::Foundation::Collections::IVector<Windows::Media::Editing::MediaOverlay> value;
    check_hresult(WINRT_SHIM(IMediaOverlayLayer)->get_Overlays(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Effects::IVideoCompositorDefinition impl_IMediaOverlayLayer<D>::CustomCompositorDefinition() const
{
    Windows::Media::Effects::IVideoCompositorDefinition value;
    check_hresult(WINRT_SHIM(IMediaOverlayLayer)->get_CustomCompositorDefinition(put_abi(value)));
    return value;
}

inline Windows::Media::Editing::BackgroundAudioTrack BackgroundAudioTrack::CreateFromEmbeddedAudioTrack(const Windows::Media::Editing::EmbeddedAudioTrack & embeddedAudioTrack)
{
    return get_activation_factory<BackgroundAudioTrack, IBackgroundAudioTrackStatics>().CreateFromEmbeddedAudioTrack(embeddedAudioTrack);
}

inline Windows::Foundation::IAsyncOperation<Windows::Media::Editing::BackgroundAudioTrack> BackgroundAudioTrack::CreateFromFileAsync(const Windows::Storage::IStorageFile & file)
{
    return get_activation_factory<BackgroundAudioTrack, IBackgroundAudioTrackStatics>().CreateFromFileAsync(file);
}

inline Windows::Media::Editing::MediaClip MediaClip::CreateFromColor(const Windows::UI::Color & color, const Windows::Foundation::TimeSpan & originalDuration)
{
    return get_activation_factory<MediaClip, IMediaClipStatics>().CreateFromColor(color, originalDuration);
}

inline Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaClip> MediaClip::CreateFromFileAsync(const Windows::Storage::IStorageFile & file)
{
    return get_activation_factory<MediaClip, IMediaClipStatics>().CreateFromFileAsync(file);
}

inline Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaClip> MediaClip::CreateFromImageFileAsync(const Windows::Storage::IStorageFile & file, const Windows::Foundation::TimeSpan & originalDuration)
{
    return get_activation_factory<MediaClip, IMediaClipStatics>().CreateFromImageFileAsync(file, originalDuration);
}

inline Windows::Media::Editing::MediaClip MediaClip::CreateFromSurface(const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface & surface, const Windows::Foundation::TimeSpan & originalDuration)
{
    return get_activation_factory<MediaClip, IMediaClipStatics2>().CreateFromSurface(surface, originalDuration);
}

inline MediaComposition::MediaComposition() :
    MediaComposition(activate_instance<MediaComposition>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::Media::Editing::MediaComposition> MediaComposition::LoadAsync(const Windows::Storage::StorageFile & file)
{
    return get_activation_factory<MediaComposition, IMediaCompositionStatics>().LoadAsync(file);
}

inline MediaOverlay::MediaOverlay(const Windows::Media::Editing::MediaClip & clip) :
    MediaOverlay(get_activation_factory<MediaOverlay, IMediaOverlayFactory>().Create(clip))
{}

inline MediaOverlay::MediaOverlay(const Windows::Media::Editing::MediaClip & clip, const Windows::Foundation::Rect & position, double opacity) :
    MediaOverlay(get_activation_factory<MediaOverlay, IMediaOverlayFactory>().CreateWithPositionAndOpacity(clip, position, opacity))
{}

inline MediaOverlayLayer::MediaOverlayLayer() :
    MediaOverlayLayer(activate_instance<MediaOverlayLayer>())
{}

inline MediaOverlayLayer::MediaOverlayLayer(const Windows::Media::Effects::IVideoCompositorDefinition & compositorDefinition) :
    MediaOverlayLayer(get_activation_factory<MediaOverlayLayer, IMediaOverlayLayerFactory>().CreateWithCompositorDefinition(compositorDefinition))
{}

}

}
#pragma warning(pop)
