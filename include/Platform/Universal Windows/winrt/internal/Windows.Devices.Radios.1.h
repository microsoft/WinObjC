// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Radios.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Radios {

struct __declspec(uuid("252118df-b33e-416a-875f-1cf38ae2d83e")) __declspec(novtable) IRadio : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetStateAsync(winrt::Windows::Devices::Radios::RadioState value, Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Radios::RadioAccessStatus> ** retval) = 0;
    virtual HRESULT __stdcall add_StateChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Radios::Radio, Windows::Foundation::IInspectable> * handler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_StateChanged(event_token eventCookie) = 0;
    virtual HRESULT __stdcall get_State(winrt::Windows::Devices::Radios::RadioState * value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_Kind(winrt::Windows::Devices::Radios::RadioKind * value) = 0;
};

struct __declspec(uuid("5fb6a12e-67cb-46ae-aae9-65919f86eff4")) __declspec(novtable) IRadioStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetRadiosAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Radios::Radio>> ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * deviceSelector) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::Radios::Radio> ** value) = 0;
    virtual HRESULT __stdcall abi_RequestAccessAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Radios::RadioAccessStatus> ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Radios::Radio> { using default_interface = Windows::Devices::Radios::IRadio; };

}

namespace Windows::Devices::Radios {

template <typename D>
struct WINRT_EBO impl_IRadio
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Radios::RadioAccessStatus> SetStateAsync(Windows::Devices::Radios::RadioState value) const;
    event_token StateChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Radios::Radio, Windows::Foundation::IInspectable> & handler) const;
    using StateChanged_revoker = event_revoker<IRadio>;
    StateChanged_revoker StateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Radios::Radio, Windows::Foundation::IInspectable> & handler) const;
    void StateChanged(event_token eventCookie) const;
    Windows::Devices::Radios::RadioState State() const;
    hstring Name() const;
    Windows::Devices::Radios::RadioKind Kind() const;
};

template <typename D>
struct WINRT_EBO impl_IRadioStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Radios::Radio>> GetRadiosAsync() const;
    hstring GetDeviceSelector() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Radios::Radio> FromIdAsync(hstring_view deviceId) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Radios::RadioAccessStatus> RequestAccessAsync() const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Radios::IRadio>
{
    using abi = ABI::Windows::Devices::Radios::IRadio;
    template <typename D> using consume = Windows::Devices::Radios::impl_IRadio<D>;
};

template <> struct traits<Windows::Devices::Radios::IRadioStatics>
{
    using abi = ABI::Windows::Devices::Radios::IRadioStatics;
    template <typename D> using consume = Windows::Devices::Radios::impl_IRadioStatics<D>;
};

template <> struct traits<Windows::Devices::Radios::Radio>
{
    using abi = ABI::Windows::Devices::Radios::Radio;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Radios.Radio"; }
};

}

}
