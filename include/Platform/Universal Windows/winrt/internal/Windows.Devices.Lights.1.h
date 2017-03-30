// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Lights.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.UI.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Lights {

struct __declspec(uuid("047d5b9a-ea45-4b2b-b1a2-14dff00bde7b")) __declspec(novtable) ILamp : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_IsEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_BrightnessLevel(float * value) = 0;
    virtual HRESULT __stdcall put_BrightnessLevel(float value) = 0;
    virtual HRESULT __stdcall get_IsColorSettable(bool * value) = 0;
    virtual HRESULT __stdcall get_Color(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_Color(Windows::UI::Color value) = 0;
    virtual HRESULT __stdcall add_AvailabilityChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Lights::Lamp, Windows::Devices::Lights::LampAvailabilityChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AvailabilityChanged(event_token token) = 0;
};

struct __declspec(uuid("4f6e3ded-07a2-499d-9260-67e304532ba4")) __declspec(novtable) ILampAvailabilityChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsAvailable(bool * value) = 0;
};

struct __declspec(uuid("a822416c-8885-401e-b821-8e8b38a8e8ec")) __declspec(novtable) ILampStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * value) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::Lights::Lamp> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetDefaultAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::Lights::Lamp> ** operation) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Lights::Lamp> { using default_interface = Windows::Devices::Lights::ILamp; };
template <> struct traits<Windows::Devices::Lights::LampAvailabilityChangedEventArgs> { using default_interface = Windows::Devices::Lights::ILampAvailabilityChangedEventArgs; };

}

namespace Windows::Devices::Lights {

template <typename D>
struct WINRT_EBO impl_ILamp
{
    hstring DeviceId() const;
    bool IsEnabled() const;
    void IsEnabled(bool value) const;
    float BrightnessLevel() const;
    void BrightnessLevel(float value) const;
    bool IsColorSettable() const;
    Windows::UI::Color Color() const;
    void Color(const Windows::UI::Color & value) const;
    event_token AvailabilityChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Lights::Lamp, Windows::Devices::Lights::LampAvailabilityChangedEventArgs> & handler) const;
    using AvailabilityChanged_revoker = event_revoker<ILamp>;
    AvailabilityChanged_revoker AvailabilityChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Lights::Lamp, Windows::Devices::Lights::LampAvailabilityChangedEventArgs> & handler) const;
    void AvailabilityChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ILampAvailabilityChangedEventArgs
{
    bool IsAvailable() const;
};

template <typename D>
struct WINRT_EBO impl_ILampStatics
{
    hstring GetDeviceSelector() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Lights::Lamp> FromIdAsync(hstring_view deviceId) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Lights::Lamp> GetDefaultAsync() const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Lights::ILamp>
{
    using abi = ABI::Windows::Devices::Lights::ILamp;
    template <typename D> using consume = Windows::Devices::Lights::impl_ILamp<D>;
};

template <> struct traits<Windows::Devices::Lights::ILampAvailabilityChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Lights::ILampAvailabilityChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Lights::impl_ILampAvailabilityChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Lights::ILampStatics>
{
    using abi = ABI::Windows::Devices::Lights::ILampStatics;
    template <typename D> using consume = Windows::Devices::Lights::impl_ILampStatics<D>;
};

template <> struct traits<Windows::Devices::Lights::Lamp>
{
    using abi = ABI::Windows::Devices::Lights::Lamp;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Lights.Lamp"; }
};

template <> struct traits<Windows::Devices::Lights::LampAvailabilityChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Lights::LampAvailabilityChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Lights.LampAvailabilityChangedEventArgs"; }
};

}

}
