// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Portable.0.h"
#include "Windows.Storage.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Portable {

struct __declspec(uuid("a88214e1-59c7-4a20-aba6-9f6707937230")) __declspec(novtable) IServiceDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelector(winrt::Windows::Devices::Portable::ServiceDeviceType serviceType, hstring * selector) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromServiceId(GUID serviceId, hstring * selector) = 0;
};

struct __declspec(uuid("5ece44ee-1b23-4dd2-8652-bc164f003128")) __declspec(novtable) IStorageDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromId(hstring deviceId, Windows::Storage::IStorageFolder ** deviceRoot) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * selector) = 0;
};

}

namespace ABI {


}

namespace Windows::Devices::Portable {

template <typename D>
struct WINRT_EBO impl_IServiceDeviceStatics
{
    hstring GetDeviceSelector(Windows::Devices::Portable::ServiceDeviceType serviceType) const;
    hstring GetDeviceSelectorFromServiceId(GUID serviceId) const;
};

template <typename D>
struct WINRT_EBO impl_IStorageDeviceStatics
{
    Windows::Storage::StorageFolder FromId(hstring_view deviceId) const;
    hstring GetDeviceSelector() const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Portable::IServiceDeviceStatics>
{
    using abi = ABI::Windows::Devices::Portable::IServiceDeviceStatics;
    template <typename D> using consume = Windows::Devices::Portable::impl_IServiceDeviceStatics<D>;
};

template <> struct traits<Windows::Devices::Portable::IStorageDeviceStatics>
{
    using abi = ABI::Windows::Devices::Portable::IStorageDeviceStatics;
    template <typename D> using consume = Windows::Devices::Portable::impl_IStorageDeviceStatics<D>;
};

template <> struct traits<Windows::Devices::Portable::ServiceDevice>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Portable.ServiceDevice"; }
};

template <> struct traits<Windows::Devices::Portable::StorageDevice>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Portable.StorageDevice"; }
};

}

}
