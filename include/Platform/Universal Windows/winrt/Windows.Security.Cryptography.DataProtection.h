// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Security.Cryptography.DataProtection.3.h"
#include "Windows.Security.Cryptography.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Security::Cryptography::DataProtection::IDataProtectionProvider> : produce_base<D, Windows::Security::Cryptography::DataProtection::IDataProtectionProvider>
{
    HRESULT __stdcall abi_ProtectAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> data, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProtectAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&data)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnprotectAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> data, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnprotectAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&data)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProtectStreamAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> src, impl::abi_arg_in<Windows::Storage::Streams::IOutputStream> dest, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProtectStreamAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&src), *reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&dest)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnprotectStreamAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> src, impl::abi_arg_in<Windows::Storage::Streams::IOutputStream> dest, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnprotectStreamAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&src), *reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&dest)));
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
struct produce<D, Windows::Security::Cryptography::DataProtection::IDataProtectionProviderFactory> : produce_base<D, Windows::Security::Cryptography::DataProtection::IDataProtectionProviderFactory>
{
    HRESULT __stdcall abi_CreateOverloadExplicit(impl::abi_arg_in<hstring> protectionDescriptor, impl::abi_arg_out<Windows::Security::Cryptography::DataProtection::IDataProtectionProvider> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateOverloadExplicit(*reinterpret_cast<const hstring *>(&protectionDescriptor)));
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

namespace Windows::Security::Cryptography::DataProtection {

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_IDataProtectionProvider<D>::ProtectAsync(const Windows::Storage::Streams::IBuffer & data) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> value;
    check_hresult(WINRT_SHIM(IDataProtectionProvider)->abi_ProtectAsync(get_abi(data), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_IDataProtectionProvider<D>::UnprotectAsync(const Windows::Storage::Streams::IBuffer & data) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> value;
    check_hresult(WINRT_SHIM(IDataProtectionProvider)->abi_UnprotectAsync(get_abi(data), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IDataProtectionProvider<D>::ProtectStreamAsync(const Windows::Storage::Streams::IInputStream & src, const Windows::Storage::Streams::IOutputStream & dest) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IDataProtectionProvider)->abi_ProtectStreamAsync(get_abi(src), get_abi(dest), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IDataProtectionProvider<D>::UnprotectStreamAsync(const Windows::Storage::Streams::IInputStream & src, const Windows::Storage::Streams::IOutputStream & dest) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IDataProtectionProvider)->abi_UnprotectStreamAsync(get_abi(src), get_abi(dest), put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Cryptography::DataProtection::DataProtectionProvider impl_IDataProtectionProviderFactory<D>::CreateOverloadExplicit(hstring_view protectionDescriptor) const
{
    Windows::Security::Cryptography::DataProtection::DataProtectionProvider value { nullptr };
    check_hresult(WINRT_SHIM(IDataProtectionProviderFactory)->abi_CreateOverloadExplicit(get_abi(protectionDescriptor), put_abi(value)));
    return value;
}

inline DataProtectionProvider::DataProtectionProvider() :
    DataProtectionProvider(activate_instance<DataProtectionProvider>())
{}

inline DataProtectionProvider::DataProtectionProvider(hstring_view protectionDescriptor) :
    DataProtectionProvider(get_activation_factory<DataProtectionProvider, IDataProtectionProviderFactory>().CreateOverloadExplicit(protectionDescriptor))
{}

}

}
#pragma warning(pop)
