// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Web.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Web::IUriToStreamResolver> : produce_base<D, Windows::Web::IUriToStreamResolver>
{
    HRESULT __stdcall abi_UriToStreamAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IInputStream>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().UriToStreamAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::IWebErrorStatics> : produce_base<D, Windows::Web::IWebErrorStatics>
{
    HRESULT __stdcall abi_GetStatus(int32_t hresult, Windows::Web::WebErrorStatus * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().GetStatus(hresult));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Web {

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IInputStream> impl_IUriToStreamResolver<D>::UriToStreamAsync(const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IInputStream> operation;
    check_hresult(WINRT_SHIM(IUriToStreamResolver)->abi_UriToStreamAsync(get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Web::WebErrorStatus impl_IWebErrorStatics<D>::GetStatus(int32_t hresult) const
{
    Windows::Web::WebErrorStatus status {};
    check_hresult(WINRT_SHIM(IWebErrorStatics)->abi_GetStatus(hresult, &status));
    return status;
}

inline Windows::Web::WebErrorStatus WebError::GetStatus(int32_t hresult)
{
    return get_activation_factory<WebError, IWebErrorStatics>().GetStatus(hresult);
}

}

}
#pragma warning(pop)
