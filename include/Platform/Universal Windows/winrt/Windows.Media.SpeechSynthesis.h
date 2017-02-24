// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Media.SpeechSynthesis.3.h"
#include "Windows.Media.h"
#include "Windows.Foundation.h"
#include "Windows.Storage.Streams.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::SpeechSynthesis::IInstalledVoicesStatic> : produce_base<D, Windows::Media::SpeechSynthesis::IInstalledVoicesStatic>
{
    HRESULT __stdcall get_AllVoices(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::SpeechSynthesis::VoiceInformation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllVoices());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultVoice(impl::abi_arg_out<Windows::Media::SpeechSynthesis::IVoiceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultVoice());
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
struct produce<D, Windows::Media::SpeechSynthesis::ISpeechSynthesisStream> : produce_base<D, Windows::Media::SpeechSynthesis::ISpeechSynthesisStream>
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
struct produce<D, Windows::Media::SpeechSynthesis::ISpeechSynthesizer> : produce_base<D, Windows::Media::SpeechSynthesis::ISpeechSynthesizer>
{
    HRESULT __stdcall abi_SynthesizeTextToStreamAsync(impl::abi_arg_in<hstring> text, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::SpeechSynthesis::SpeechSynthesisStream>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SynthesizeTextToStreamAsync(*reinterpret_cast<const hstring *>(&text)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SynthesizeSsmlToStreamAsync(impl::abi_arg_in<hstring> Ssml, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::SpeechSynthesis::SpeechSynthesisStream>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SynthesizeSsmlToStreamAsync(*reinterpret_cast<const hstring *>(&Ssml)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Voice(impl::abi_arg_in<Windows::Media::SpeechSynthesis::IVoiceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Voice(*reinterpret_cast<const Windows::Media::SpeechSynthesis::VoiceInformation *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Voice(impl::abi_arg_out<Windows::Media::SpeechSynthesis::IVoiceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Voice());
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
struct produce<D, Windows::Media::SpeechSynthesis::IVoiceInformation> : produce_base<D, Windows::Media::SpeechSynthesis::IVoiceInformation>
{
    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Language(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Description(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Description());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gender(Windows::Media::SpeechSynthesis::VoiceGender * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gender());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::SpeechSynthesis {

template <typename D> hstring impl_IVoiceInformation<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceInformation)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVoiceInformation<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceInformation)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVoiceInformation<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceInformation)->get_Language(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVoiceInformation<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceInformation)->get_Description(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::SpeechSynthesis::VoiceGender impl_IVoiceInformation<D>::Gender() const
{
    Windows::Media::SpeechSynthesis::VoiceGender value {};
    check_hresult(WINRT_SHIM(IVoiceInformation)->get_Gender(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::SpeechSynthesis::VoiceInformation> impl_IInstalledVoicesStatic<D>::AllVoices() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::SpeechSynthesis::VoiceInformation> value;
    check_hresult(WINRT_SHIM(IInstalledVoicesStatic)->get_AllVoices(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::SpeechSynthesis::VoiceInformation impl_IInstalledVoicesStatic<D>::DefaultVoice() const
{
    Windows::Media::SpeechSynthesis::VoiceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IInstalledVoicesStatic)->get_DefaultVoice(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::IMediaMarker> impl_ISpeechSynthesisStream<D>::Markers() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::IMediaMarker> value;
    check_hresult(WINRT_SHIM(ISpeechSynthesisStream)->get_Markers(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::SpeechSynthesis::SpeechSynthesisStream> impl_ISpeechSynthesizer<D>::SynthesizeTextToStreamAsync(hstring_view text) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::SpeechSynthesis::SpeechSynthesisStream> operation;
    check_hresult(WINRT_SHIM(ISpeechSynthesizer)->abi_SynthesizeTextToStreamAsync(get_abi(text), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::SpeechSynthesis::SpeechSynthesisStream> impl_ISpeechSynthesizer<D>::SynthesizeSsmlToStreamAsync(hstring_view Ssml) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::SpeechSynthesis::SpeechSynthesisStream> operation;
    check_hresult(WINRT_SHIM(ISpeechSynthesizer)->abi_SynthesizeSsmlToStreamAsync(get_abi(Ssml), put_abi(operation)));
    return operation;
}

template <typename D> void impl_ISpeechSynthesizer<D>::Voice(const Windows::Media::SpeechSynthesis::VoiceInformation & value) const
{
    check_hresult(WINRT_SHIM(ISpeechSynthesizer)->put_Voice(get_abi(value)));
}

template <typename D> Windows::Media::SpeechSynthesis::VoiceInformation impl_ISpeechSynthesizer<D>::Voice() const
{
    Windows::Media::SpeechSynthesis::VoiceInformation value { nullptr };
    check_hresult(WINRT_SHIM(ISpeechSynthesizer)->get_Voice(put_abi(value)));
    return value;
}

inline SpeechSynthesizer::SpeechSynthesizer() :
    SpeechSynthesizer(activate_instance<SpeechSynthesizer>())
{}

inline Windows::Foundation::Collections::IVectorView<Windows::Media::SpeechSynthesis::VoiceInformation> SpeechSynthesizer::AllVoices()
{
    return get_activation_factory<SpeechSynthesizer, IInstalledVoicesStatic>().AllVoices();
}

inline Windows::Media::SpeechSynthesis::VoiceInformation SpeechSynthesizer::DefaultVoice()
{
    return get_activation_factory<SpeechSynthesizer, IInstalledVoicesStatic>().DefaultVoice();
}

}

}
#pragma warning(pop)
