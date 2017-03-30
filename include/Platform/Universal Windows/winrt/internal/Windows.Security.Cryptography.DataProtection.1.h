// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Security.Cryptography.DataProtection.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Storage.Streams.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::Cryptography::DataProtection {

struct __declspec(uuid("09639948-ed22-4270-bd1c-6d72c00f8787")) __declspec(novtable) IDataProtectionProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ProtectAsync(Windows::Storage::Streams::IBuffer * data, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> ** value) = 0;
    virtual HRESULT __stdcall abi_UnprotectAsync(Windows::Storage::Streams::IBuffer * data, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> ** value) = 0;
    virtual HRESULT __stdcall abi_ProtectStreamAsync(Windows::Storage::Streams::IInputStream * src, Windows::Storage::Streams::IOutputStream * dest, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_UnprotectStreamAsync(Windows::Storage::Streams::IInputStream * src, Windows::Storage::Streams::IOutputStream * dest, Windows::Foundation::IAsyncAction ** value) = 0;
};

struct __declspec(uuid("adf33dac-4932-4cdf-ac41-7214333514ca")) __declspec(novtable) IDataProtectionProviderFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateOverloadExplicit(hstring protectionDescriptor, Windows::Security::Cryptography::DataProtection::IDataProtectionProvider ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Security::Cryptography::DataProtection::DataProtectionProvider> { using default_interface = Windows::Security::Cryptography::DataProtection::IDataProtectionProvider; };

}

namespace Windows::Security::Cryptography::DataProtection {

template <typename D>
struct WINRT_EBO impl_IDataProtectionProvider
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> ProtectAsync(const Windows::Storage::Streams::IBuffer & data) const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> UnprotectAsync(const Windows::Storage::Streams::IBuffer & data) const;
    Windows::Foundation::IAsyncAction ProtectStreamAsync(const Windows::Storage::Streams::IInputStream & src, const Windows::Storage::Streams::IOutputStream & dest) const;
    Windows::Foundation::IAsyncAction UnprotectStreamAsync(const Windows::Storage::Streams::IInputStream & src, const Windows::Storage::Streams::IOutputStream & dest) const;
};

template <typename D>
struct WINRT_EBO impl_IDataProtectionProviderFactory
{
    Windows::Security::Cryptography::DataProtection::DataProtectionProvider CreateOverloadExplicit(hstring_view protectionDescriptor) const;
};

}

namespace impl {

template <> struct traits<Windows::Security::Cryptography::DataProtection::IDataProtectionProvider>
{
    using abi = ABI::Windows::Security::Cryptography::DataProtection::IDataProtectionProvider;
    template <typename D> using consume = Windows::Security::Cryptography::DataProtection::impl_IDataProtectionProvider<D>;
};

template <> struct traits<Windows::Security::Cryptography::DataProtection::IDataProtectionProviderFactory>
{
    using abi = ABI::Windows::Security::Cryptography::DataProtection::IDataProtectionProviderFactory;
    template <typename D> using consume = Windows::Security::Cryptography::DataProtection::impl_IDataProtectionProviderFactory<D>;
};

template <> struct traits<Windows::Security::Cryptography::DataProtection::DataProtectionProvider>
{
    using abi = ABI::Windows::Security::Cryptography::DataProtection::DataProtectionProvider;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.DataProtection.DataProtectionProvider"; }
};

}

}
