// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Printers.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Storage.Streams.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Printers {

struct __declspec(uuid("041c3d19-9713-42a2-9813-7dc3337428d3")) __declspec(novtable) IPrint3DDevice : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PrintSchema(Windows::Devices::Printers::IPrintSchema ** value) = 0;
};

struct __declspec(uuid("fde3620a-67cd-41b7-a344-5150a1fd75b5")) __declspec(novtable) IPrint3DDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::Printers::Print3DDevice> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * result) = 0;
};

struct __declspec(uuid("c2b98316-26b8-4bfb-8138-9f962c22a35b")) __declspec(novtable) IPrintSchema : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefaultPrintTicketAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetCapabilitiesAsync(Windows::Storage::Streams::IRandomAccessStreamWithContentType * constrainTicket, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> ** operation) = 0;
    virtual HRESULT __stdcall abi_MergeAndValidateWithDefaultPrintTicketAsync(Windows::Storage::Streams::IRandomAccessStreamWithContentType * deltaTicket, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> ** operation) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Printers::Print3DDevice> { using default_interface = Windows::Devices::Printers::IPrint3DDevice; };
template <> struct traits<Windows::Devices::Printers::PrintSchema> { using default_interface = Windows::Devices::Printers::IPrintSchema; };

}

namespace Windows::Devices::Printers {

template <typename D>
struct WINRT_EBO impl_IPrint3DDevice
{
    Windows::Devices::Printers::PrintSchema PrintSchema() const;
};

template <typename D>
struct WINRT_EBO impl_IPrint3DDeviceStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Printers::Print3DDevice> FromIdAsync(hstring_view deviceId) const;
    hstring GetDeviceSelector() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintSchema
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> GetDefaultPrintTicketAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> GetCapabilitiesAsync(const Windows::Storage::Streams::IRandomAccessStreamWithContentType & constrainTicket) const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> MergeAndValidateWithDefaultPrintTicketAsync(const Windows::Storage::Streams::IRandomAccessStreamWithContentType & deltaTicket) const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Printers::IPrint3DDevice>
{
    using abi = ABI::Windows::Devices::Printers::IPrint3DDevice;
    template <typename D> using consume = Windows::Devices::Printers::impl_IPrint3DDevice<D>;
};

template <> struct traits<Windows::Devices::Printers::IPrint3DDeviceStatics>
{
    using abi = ABI::Windows::Devices::Printers::IPrint3DDeviceStatics;
    template <typename D> using consume = Windows::Devices::Printers::impl_IPrint3DDeviceStatics<D>;
};

template <> struct traits<Windows::Devices::Printers::IPrintSchema>
{
    using abi = ABI::Windows::Devices::Printers::IPrintSchema;
    template <typename D> using consume = Windows::Devices::Printers::impl_IPrintSchema<D>;
};

template <> struct traits<Windows::Devices::Printers::Print3DDevice>
{
    using abi = ABI::Windows::Devices::Printers::Print3DDevice;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Printers.Print3DDevice"; }
};

template <> struct traits<Windows::Devices::Printers::PrintSchema>
{
    using abi = ABI::Windows::Devices::Printers::PrintSchema;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Printers.PrintSchema"; }
};

}

}
