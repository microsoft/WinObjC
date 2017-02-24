// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Background.3.h"
#include "Windows.Devices.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Background::IDeviceServicingDetails> : produce_base<D, Windows::Devices::Background::IDeviceServicingDetails>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Arguments(impl::abi_arg_out<hstring> value) noexcept override
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

    HRESULT __stdcall get_ExpectedDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExpectedDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Background::IDeviceUseDetails> : produce_base<D, Windows::Devices::Background::IDeviceUseDetails>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Arguments(impl::abi_arg_out<hstring> value) noexcept override
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

}

namespace Windows::Devices::Background {

template <typename D> hstring impl_IDeviceUseDetails<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceUseDetails)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDeviceUseDetails<D>::Arguments() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceUseDetails)->get_Arguments(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDeviceServicingDetails<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceServicingDetails)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDeviceServicingDetails<D>::Arguments() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceServicingDetails)->get_Arguments(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IDeviceServicingDetails<D>::ExpectedDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IDeviceServicingDetails)->get_ExpectedDuration(put_abi(value)));
    return value;
}

}

}
#pragma warning(pop)
