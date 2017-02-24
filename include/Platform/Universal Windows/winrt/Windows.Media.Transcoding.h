// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Media.Core.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Media.MediaProperties.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Media.Transcoding.3.h"
#include "Windows.Media.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::Transcoding::IMediaTranscoder> : produce_base<D, Windows::Media::Transcoding::IMediaTranscoder>
{
    HRESULT __stdcall put_TrimStartTime(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrimStartTime(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrimStartTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrimStartTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TrimStopTime(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrimStopTime(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrimStopTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrimStopTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AlwaysReencode(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlwaysReencode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlwaysReencode(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlwaysReencode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HardwareAccelerationEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HardwareAccelerationEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HardwareAccelerationEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HardwareAccelerationEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddAudioEffect(impl::abi_arg_in<hstring> activatableClassId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddAudioEffect(*reinterpret_cast<const hstring *>(&activatableClassId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddAudioEffectWithSettings(impl::abi_arg_in<hstring> activatableClassId, bool effectRequired, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> configuration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddAudioEffect(*reinterpret_cast<const hstring *>(&activatableClassId), effectRequired, *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&configuration));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddVideoEffect(impl::abi_arg_in<hstring> activatableClassId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddVideoEffect(*reinterpret_cast<const hstring *>(&activatableClassId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddVideoEffectWithSettings(impl::abi_arg_in<hstring> activatableClassId, bool effectRequired, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> configuration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddVideoEffect(*reinterpret_cast<const hstring *>(&activatableClassId), effectRequired, *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&configuration));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearEffects() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearEffects();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareFileTranscodeAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> source, impl::abi_arg_in<Windows::Storage::IStorageFile> destination, impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> profile, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Transcoding::PrepareTranscodeResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PrepareFileTranscodeAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&source), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&destination), *reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&profile)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareStreamTranscodeAsync(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> source, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> destination, impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> profile, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Transcoding::PrepareTranscodeResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PrepareStreamTranscodeAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&source), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&destination), *reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&profile)));
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
struct produce<D, Windows::Media::Transcoding::IMediaTranscoder2> : produce_base<D, Windows::Media::Transcoding::IMediaTranscoder2>
{
    HRESULT __stdcall abi_PrepareMediaStreamSourceTranscodeAsync(impl::abi_arg_in<Windows::Media::Core::IMediaSource> source, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> destination, impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> profile, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Transcoding::PrepareTranscodeResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PrepareMediaStreamSourceTranscodeAsync(*reinterpret_cast<const Windows::Media::Core::IMediaSource *>(&source), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&destination), *reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&profile)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VideoProcessingAlgorithm(Windows::Media::Transcoding::MediaVideoProcessingAlgorithm value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoProcessingAlgorithm(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoProcessingAlgorithm(Windows::Media::Transcoding::MediaVideoProcessingAlgorithm * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoProcessingAlgorithm());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Transcoding::IPrepareTranscodeResult> : produce_base<D, Windows::Media::Transcoding::IPrepareTranscodeResult>
{
    HRESULT __stdcall get_CanTranscode(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanTranscode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FailureReason(Windows::Media::Transcoding::TranscodeFailureReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FailureReason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TranscodeAsync(impl::abi_arg_out<Windows::Foundation::IAsyncActionWithProgress<double>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().TranscodeAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::Transcoding {

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Transcoding::PrepareTranscodeResult> impl_IMediaTranscoder2<D>::PrepareMediaStreamSourceTranscodeAsync(const Windows::Media::Core::IMediaSource & source, const Windows::Storage::Streams::IRandomAccessStream & destination, const Windows::Media::MediaProperties::MediaEncodingProfile & profile) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Transcoding::PrepareTranscodeResult> operation;
    check_hresult(WINRT_SHIM(IMediaTranscoder2)->abi_PrepareMediaStreamSourceTranscodeAsync(get_abi(source), get_abi(destination), get_abi(profile), put_abi(operation)));
    return operation;
}

template <typename D> void impl_IMediaTranscoder2<D>::VideoProcessingAlgorithm(Windows::Media::Transcoding::MediaVideoProcessingAlgorithm value) const
{
    check_hresult(WINRT_SHIM(IMediaTranscoder2)->put_VideoProcessingAlgorithm(value));
}

template <typename D> Windows::Media::Transcoding::MediaVideoProcessingAlgorithm impl_IMediaTranscoder2<D>::VideoProcessingAlgorithm() const
{
    Windows::Media::Transcoding::MediaVideoProcessingAlgorithm value {};
    check_hresult(WINRT_SHIM(IMediaTranscoder2)->get_VideoProcessingAlgorithm(&value));
    return value;
}

template <typename D> void impl_IMediaTranscoder<D>::TrimStartTime(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMediaTranscoder)->put_TrimStartTime(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaTranscoder<D>::TrimStartTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaTranscoder)->get_TrimStartTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaTranscoder<D>::TrimStopTime(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMediaTranscoder)->put_TrimStopTime(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaTranscoder<D>::TrimStopTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaTranscoder)->get_TrimStopTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaTranscoder<D>::AlwaysReencode(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaTranscoder)->put_AlwaysReencode(value));
}

template <typename D> bool impl_IMediaTranscoder<D>::AlwaysReencode() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaTranscoder)->get_AlwaysReencode(&value));
    return value;
}

template <typename D> void impl_IMediaTranscoder<D>::HardwareAccelerationEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaTranscoder)->put_HardwareAccelerationEnabled(value));
}

template <typename D> bool impl_IMediaTranscoder<D>::HardwareAccelerationEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaTranscoder)->get_HardwareAccelerationEnabled(&value));
    return value;
}

template <typename D> void impl_IMediaTranscoder<D>::AddAudioEffect(hstring_view activatableClassId) const
{
    check_hresult(WINRT_SHIM(IMediaTranscoder)->abi_AddAudioEffect(get_abi(activatableClassId)));
}

template <typename D> void impl_IMediaTranscoder<D>::AddAudioEffect(hstring_view activatableClassId, bool effectRequired, const Windows::Foundation::Collections::IPropertySet & configuration) const
{
    check_hresult(WINRT_SHIM(IMediaTranscoder)->abi_AddAudioEffectWithSettings(get_abi(activatableClassId), effectRequired, get_abi(configuration)));
}

template <typename D> void impl_IMediaTranscoder<D>::AddVideoEffect(hstring_view activatableClassId) const
{
    check_hresult(WINRT_SHIM(IMediaTranscoder)->abi_AddVideoEffect(get_abi(activatableClassId)));
}

template <typename D> void impl_IMediaTranscoder<D>::AddVideoEffect(hstring_view activatableClassId, bool effectRequired, const Windows::Foundation::Collections::IPropertySet & configuration) const
{
    check_hresult(WINRT_SHIM(IMediaTranscoder)->abi_AddVideoEffectWithSettings(get_abi(activatableClassId), effectRequired, get_abi(configuration)));
}

template <typename D> void impl_IMediaTranscoder<D>::ClearEffects() const
{
    check_hresult(WINRT_SHIM(IMediaTranscoder)->abi_ClearEffects());
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Transcoding::PrepareTranscodeResult> impl_IMediaTranscoder<D>::PrepareFileTranscodeAsync(const Windows::Storage::IStorageFile & source, const Windows::Storage::IStorageFile & destination, const Windows::Media::MediaProperties::MediaEncodingProfile & profile) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Transcoding::PrepareTranscodeResult> operation;
    check_hresult(WINRT_SHIM(IMediaTranscoder)->abi_PrepareFileTranscodeAsync(get_abi(source), get_abi(destination), get_abi(profile), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Transcoding::PrepareTranscodeResult> impl_IMediaTranscoder<D>::PrepareStreamTranscodeAsync(const Windows::Storage::Streams::IRandomAccessStream & source, const Windows::Storage::Streams::IRandomAccessStream & destination, const Windows::Media::MediaProperties::MediaEncodingProfile & profile) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Transcoding::PrepareTranscodeResult> operation;
    check_hresult(WINRT_SHIM(IMediaTranscoder)->abi_PrepareStreamTranscodeAsync(get_abi(source), get_abi(destination), get_abi(profile), put_abi(operation)));
    return operation;
}

template <typename D> bool impl_IPrepareTranscodeResult<D>::CanTranscode() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPrepareTranscodeResult)->get_CanTranscode(&value));
    return value;
}

template <typename D> Windows::Media::Transcoding::TranscodeFailureReason impl_IPrepareTranscodeResult<D>::FailureReason() const
{
    Windows::Media::Transcoding::TranscodeFailureReason value {};
    check_hresult(WINRT_SHIM(IPrepareTranscodeResult)->get_FailureReason(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncActionWithProgress<double> impl_IPrepareTranscodeResult<D>::TranscodeAsync() const
{
    Windows::Foundation::IAsyncActionWithProgress<double> operation;
    check_hresult(WINRT_SHIM(IPrepareTranscodeResult)->abi_TranscodeAsync(put_abi(operation)));
    return operation;
}

inline MediaTranscoder::MediaTranscoder() :
    MediaTranscoder(activate_instance<MediaTranscoder>())
{}

}

}
#pragma warning(pop)
