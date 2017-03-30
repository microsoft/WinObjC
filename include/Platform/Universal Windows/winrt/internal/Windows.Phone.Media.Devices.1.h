// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Phone.Media.Devices.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Phone::Media::Devices {

struct __declspec(uuid("79340d20-71cc-4526-9f29-fc8d2486418b")) __declspec(novtable) IAudioRoutingManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAudioEndpoint(winrt::Windows::Phone::Media::Devices::AudioRoutingEndpoint * endpoint) = 0;
    virtual HRESULT __stdcall abi_SetAudioEndpoint(winrt::Windows::Phone::Media::Devices::AudioRoutingEndpoint endpoint) = 0;
    virtual HRESULT __stdcall add_AudioEndpointChanged(Windows::Foundation::TypedEventHandler<Windows::Phone::Media::Devices::AudioRoutingManager, Windows::Foundation::IInspectable> * endpointChangeHandler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AudioEndpointChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_AvailableAudioEndpoints(winrt::Windows::Phone::Media::Devices::AvailableAudioRoutingEndpoints * value) = 0;
};

struct __declspec(uuid("977fb2a4-5590-4a6f-adde-6a3d0ad58250")) __declspec(novtable) IAudioRoutingManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::Phone::Media::Devices::IAudioRoutingManager ** audioRoutingManager) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Phone::Media::Devices::AudioRoutingManager> { using default_interface = Windows::Phone::Media::Devices::IAudioRoutingManager; };

}

namespace Windows::Phone::Media::Devices {

template <typename D>
struct WINRT_EBO impl_IAudioRoutingManager
{
    Windows::Phone::Media::Devices::AudioRoutingEndpoint GetAudioEndpoint() const;
    void SetAudioEndpoint(Windows::Phone::Media::Devices::AudioRoutingEndpoint endpoint) const;
    event_token AudioEndpointChanged(const Windows::Foundation::TypedEventHandler<Windows::Phone::Media::Devices::AudioRoutingManager, Windows::Foundation::IInspectable> & endpointChangeHandler) const;
    using AudioEndpointChanged_revoker = event_revoker<IAudioRoutingManager>;
    AudioEndpointChanged_revoker AudioEndpointChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Phone::Media::Devices::AudioRoutingManager, Windows::Foundation::IInspectable> & endpointChangeHandler) const;
    void AudioEndpointChanged(event_token token) const;
    Windows::Phone::Media::Devices::AvailableAudioRoutingEndpoints AvailableAudioEndpoints() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioRoutingManagerStatics
{
    Windows::Phone::Media::Devices::AudioRoutingManager GetDefault() const;
};

}

namespace impl {

template <> struct traits<Windows::Phone::Media::Devices::IAudioRoutingManager>
{
    using abi = ABI::Windows::Phone::Media::Devices::IAudioRoutingManager;
    template <typename D> using consume = Windows::Phone::Media::Devices::impl_IAudioRoutingManager<D>;
};

template <> struct traits<Windows::Phone::Media::Devices::IAudioRoutingManagerStatics>
{
    using abi = ABI::Windows::Phone::Media::Devices::IAudioRoutingManagerStatics;
    template <typename D> using consume = Windows::Phone::Media::Devices::impl_IAudioRoutingManagerStatics<D>;
};

template <> struct traits<Windows::Phone::Media::Devices::AudioRoutingManager>
{
    using abi = ABI::Windows::Phone::Media::Devices::AudioRoutingManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.Media.Devices.AudioRoutingManager"; }
};

}

}
