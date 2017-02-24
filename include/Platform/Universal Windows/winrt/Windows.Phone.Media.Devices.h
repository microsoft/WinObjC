// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Phone.Media.Devices.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Phone::Media::Devices::IAudioRoutingManager> : produce_base<D, Windows::Phone::Media::Devices::IAudioRoutingManager>
{
    HRESULT __stdcall abi_GetAudioEndpoint(Windows::Phone::Media::Devices::AudioRoutingEndpoint * endpoint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *endpoint = detach_abi(this->shim().GetAudioEndpoint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetAudioEndpoint(Windows::Phone::Media::Devices::AudioRoutingEndpoint endpoint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetAudioEndpoint(endpoint);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AudioEndpointChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Phone::Media::Devices::AudioRoutingManager, Windows::Foundation::IInspectable>> endpointChangeHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AudioEndpointChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Phone::Media::Devices::AudioRoutingManager, Windows::Foundation::IInspectable> *>(&endpointChangeHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AudioEndpointChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioEndpointChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AvailableAudioEndpoints(Windows::Phone::Media::Devices::AvailableAudioRoutingEndpoints * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AvailableAudioEndpoints());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::Media::Devices::IAudioRoutingManagerStatics> : produce_base<D, Windows::Phone::Media::Devices::IAudioRoutingManagerStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Phone::Media::Devices::IAudioRoutingManager> audioRoutingManager) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *audioRoutingManager = detach_abi(this->shim().GetDefault());
            return S_OK;
        }
        catch (...)
        {
            *audioRoutingManager = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Phone::Media::Devices {

template <typename D> Windows::Phone::Media::Devices::AudioRoutingEndpoint impl_IAudioRoutingManager<D>::GetAudioEndpoint() const
{
    Windows::Phone::Media::Devices::AudioRoutingEndpoint endpoint {};
    check_hresult(WINRT_SHIM(IAudioRoutingManager)->abi_GetAudioEndpoint(&endpoint));
    return endpoint;
}

template <typename D> void impl_IAudioRoutingManager<D>::SetAudioEndpoint(Windows::Phone::Media::Devices::AudioRoutingEndpoint endpoint) const
{
    check_hresult(WINRT_SHIM(IAudioRoutingManager)->abi_SetAudioEndpoint(endpoint));
}

template <typename D> event_token impl_IAudioRoutingManager<D>::AudioEndpointChanged(const Windows::Foundation::TypedEventHandler<Windows::Phone::Media::Devices::AudioRoutingManager, Windows::Foundation::IInspectable> & endpointChangeHandler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAudioRoutingManager)->add_AudioEndpointChanged(get_abi(endpointChangeHandler), &token));
    return token;
}

template <typename D> event_revoker<IAudioRoutingManager> impl_IAudioRoutingManager<D>::AudioEndpointChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Phone::Media::Devices::AudioRoutingManager, Windows::Foundation::IInspectable> & endpointChangeHandler) const
{
    return impl::make_event_revoker<D, IAudioRoutingManager>(this, &ABI::Windows::Phone::Media::Devices::IAudioRoutingManager::remove_AudioEndpointChanged, AudioEndpointChanged(endpointChangeHandler));
}

template <typename D> void impl_IAudioRoutingManager<D>::AudioEndpointChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IAudioRoutingManager)->remove_AudioEndpointChanged(token));
}

template <typename D> Windows::Phone::Media::Devices::AvailableAudioRoutingEndpoints impl_IAudioRoutingManager<D>::AvailableAudioEndpoints() const
{
    Windows::Phone::Media::Devices::AvailableAudioRoutingEndpoints value {};
    check_hresult(WINRT_SHIM(IAudioRoutingManager)->get_AvailableAudioEndpoints(&value));
    return value;
}

template <typename D> Windows::Phone::Media::Devices::AudioRoutingManager impl_IAudioRoutingManagerStatics<D>::GetDefault() const
{
    Windows::Phone::Media::Devices::AudioRoutingManager audioRoutingManager { nullptr };
    check_hresult(WINRT_SHIM(IAudioRoutingManagerStatics)->abi_GetDefault(put_abi(audioRoutingManager)));
    return audioRoutingManager;
}

inline Windows::Phone::Media::Devices::AudioRoutingManager AudioRoutingManager::GetDefault()
{
    return get_activation_factory<AudioRoutingManager, IAudioRoutingManagerStatics>().GetDefault();
}

}

}
#pragma warning(pop)
