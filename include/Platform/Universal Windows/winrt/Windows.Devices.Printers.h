// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Devices.Printers.3.h"
#include "Windows.Devices.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Printers::IPrint3DDevice> : produce_base<D, Windows::Devices::Printers::IPrint3DDevice>
{
    HRESULT __stdcall get_PrintSchema(impl::abi_arg_out<Windows::Devices::Printers::IPrintSchema> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrintSchema());
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
struct produce<D, Windows::Devices::Printers::IPrint3DDeviceStatics> : produce_base<D, Windows::Devices::Printers::IPrint3DDeviceStatics>
{
    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Printers::Print3DDevice>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Printers::IPrintSchema> : produce_base<D, Windows::Devices::Printers::IPrintSchema>
{
    HRESULT __stdcall abi_GetDefaultPrintTicketAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetDefaultPrintTicketAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCapabilitiesAsync(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamWithContentType> constrainTicket, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetCapabilitiesAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamWithContentType *>(&constrainTicket)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MergeAndValidateWithDefaultPrintTicketAsync(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamWithContentType> deltaTicket, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().MergeAndValidateWithDefaultPrintTicketAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamWithContentType *>(&deltaTicket)));
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

namespace Windows::Devices::Printers {

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Printers::Print3DDevice> impl_IPrint3DDeviceStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Printers::Print3DDevice> operation;
    check_hresult(WINRT_SHIM(IPrint3DDeviceStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IPrint3DDeviceStatics<D>::GetDeviceSelector() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IPrint3DDeviceStatics)->abi_GetDeviceSelector(put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Printers::PrintSchema impl_IPrint3DDevice<D>::PrintSchema() const
{
    Windows::Devices::Printers::PrintSchema value { nullptr };
    check_hresult(WINRT_SHIM(IPrint3DDevice)->get_PrintSchema(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> impl_IPrintSchema<D>::GetDefaultPrintTicketAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> operation;
    check_hresult(WINRT_SHIM(IPrintSchema)->abi_GetDefaultPrintTicketAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> impl_IPrintSchema<D>::GetCapabilitiesAsync(const Windows::Storage::Streams::IRandomAccessStreamWithContentType & constrainTicket) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> operation;
    check_hresult(WINRT_SHIM(IPrintSchema)->abi_GetCapabilitiesAsync(get_abi(constrainTicket), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> impl_IPrintSchema<D>::MergeAndValidateWithDefaultPrintTicketAsync(const Windows::Storage::Streams::IRandomAccessStreamWithContentType & deltaTicket) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> operation;
    check_hresult(WINRT_SHIM(IPrintSchema)->abi_MergeAndValidateWithDefaultPrintTicketAsync(get_abi(deltaTicket), put_abi(operation)));
    return operation;
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Printers::Print3DDevice> Print3DDevice::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<Print3DDevice, IPrint3DDeviceStatics>().FromIdAsync(deviceId);
}

inline hstring Print3DDevice::GetDeviceSelector()
{
    return get_activation_factory<Print3DDevice, IPrint3DDeviceStatics>().GetDeviceSelector();
}

}

}
#pragma warning(pop)
