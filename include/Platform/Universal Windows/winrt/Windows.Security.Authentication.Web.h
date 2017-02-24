// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Security.Authentication.Web.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::IWebAuthenticationBrokerStatics> : produce_base<D, Windows::Security::Authentication::Web::IWebAuthenticationBrokerStatics>
{
    HRESULT __stdcall abi_AuthenticateWithCallbackUriAsync(Windows::Security::Authentication::Web::WebAuthenticationOptions options, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> requestUri, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> callbackUri, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().AuthenticateAsync(options, *reinterpret_cast<const Windows::Foundation::Uri *>(&requestUri), *reinterpret_cast<const Windows::Foundation::Uri *>(&callbackUri)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AuthenticateWithoutCallbackUriAsync(Windows::Security::Authentication::Web::WebAuthenticationOptions options, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> requestUri, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().AuthenticateAsync(options, *reinterpret_cast<const Windows::Foundation::Uri *>(&requestUri)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentApplicationCallbackUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> callbackUri) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *callbackUri = detach_abi(this->shim().GetCurrentApplicationCallbackUri());
            return S_OK;
        }
        catch (...)
        {
            *callbackUri = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::IWebAuthenticationBrokerStatics2> : produce_base<D, Windows::Security::Authentication::Web::IWebAuthenticationBrokerStatics2>
{
    HRESULT __stdcall abi_AuthenticateAndContinue(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> requestUri) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthenticateAndContinue(*reinterpret_cast<const Windows::Foundation::Uri *>(&requestUri));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AuthenticateWithCallbackUriAndContinue(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> requestUri, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> callbackUri) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthenticateAndContinue(*reinterpret_cast<const Windows::Foundation::Uri *>(&requestUri), *reinterpret_cast<const Windows::Foundation::Uri *>(&callbackUri));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AuthenticateWithCallbackUriContinuationDataAndOptionsAndContinue(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> requestUri, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> callbackUri, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> continuationData, Windows::Security::Authentication::Web::WebAuthenticationOptions options) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthenticateAndContinue(*reinterpret_cast<const Windows::Foundation::Uri *>(&requestUri), *reinterpret_cast<const Windows::Foundation::Uri *>(&callbackUri), *reinterpret_cast<const Windows::Foundation::Collections::ValueSet *>(&continuationData), options);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AuthenticateSilentlyAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> requestUri, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().AuthenticateSilentlyAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&requestUri)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AuthenticateSilentlyWithOptionsAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> requestUri, Windows::Security::Authentication::Web::WebAuthenticationOptions options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().AuthenticateSilentlyAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&requestUri), options));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::IWebAuthenticationResult> : produce_base<D, Windows::Security::Authentication::Web::IWebAuthenticationResult>
{
    HRESULT __stdcall get_ResponseData(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResponseData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResponseStatus(Windows::Security::Authentication::Web::WebAuthenticationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResponseStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResponseErrorDetail(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResponseErrorDetail());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Security::Authentication::Web {

template <typename D> hstring impl_IWebAuthenticationResult<D>::ResponseData() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWebAuthenticationResult)->get_ResponseData(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Web::WebAuthenticationStatus impl_IWebAuthenticationResult<D>::ResponseStatus() const
{
    Windows::Security::Authentication::Web::WebAuthenticationStatus value {};
    check_hresult(WINRT_SHIM(IWebAuthenticationResult)->get_ResponseStatus(&value));
    return value;
}

template <typename D> uint32_t impl_IWebAuthenticationResult<D>::ResponseErrorDetail() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IWebAuthenticationResult)->get_ResponseErrorDetail(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> impl_IWebAuthenticationBrokerStatics<D>::AuthenticateAsync(Windows::Security::Authentication::Web::WebAuthenticationOptions options, const Windows::Foundation::Uri & requestUri, const Windows::Foundation::Uri & callbackUri) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAuthenticationBrokerStatics)->abi_AuthenticateWithCallbackUriAsync(options, get_abi(requestUri), get_abi(callbackUri), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> impl_IWebAuthenticationBrokerStatics<D>::AuthenticateAsync(Windows::Security::Authentication::Web::WebAuthenticationOptions options, const Windows::Foundation::Uri & requestUri) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAuthenticationBrokerStatics)->abi_AuthenticateWithoutCallbackUriAsync(options, get_abi(requestUri), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::Uri impl_IWebAuthenticationBrokerStatics<D>::GetCurrentApplicationCallbackUri() const
{
    Windows::Foundation::Uri callbackUri { nullptr };
    check_hresult(WINRT_SHIM(IWebAuthenticationBrokerStatics)->abi_GetCurrentApplicationCallbackUri(put_abi(callbackUri)));
    return callbackUri;
}

template <typename D> void impl_IWebAuthenticationBrokerStatics2<D>::AuthenticateAndContinue(const Windows::Foundation::Uri & requestUri) const
{
    check_hresult(WINRT_SHIM(IWebAuthenticationBrokerStatics2)->abi_AuthenticateAndContinue(get_abi(requestUri)));
}

template <typename D> void impl_IWebAuthenticationBrokerStatics2<D>::AuthenticateAndContinue(const Windows::Foundation::Uri & requestUri, const Windows::Foundation::Uri & callbackUri) const
{
    check_hresult(WINRT_SHIM(IWebAuthenticationBrokerStatics2)->abi_AuthenticateWithCallbackUriAndContinue(get_abi(requestUri), get_abi(callbackUri)));
}

template <typename D> void impl_IWebAuthenticationBrokerStatics2<D>::AuthenticateAndContinue(const Windows::Foundation::Uri & requestUri, const Windows::Foundation::Uri & callbackUri, const Windows::Foundation::Collections::ValueSet & continuationData, Windows::Security::Authentication::Web::WebAuthenticationOptions options) const
{
    check_hresult(WINRT_SHIM(IWebAuthenticationBrokerStatics2)->abi_AuthenticateWithCallbackUriContinuationDataAndOptionsAndContinue(get_abi(requestUri), get_abi(callbackUri), get_abi(continuationData), options));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> impl_IWebAuthenticationBrokerStatics2<D>::AuthenticateSilentlyAsync(const Windows::Foundation::Uri & requestUri) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAuthenticationBrokerStatics2)->abi_AuthenticateSilentlyAsync(get_abi(requestUri), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> impl_IWebAuthenticationBrokerStatics2<D>::AuthenticateSilentlyAsync(const Windows::Foundation::Uri & requestUri, Windows::Security::Authentication::Web::WebAuthenticationOptions options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAuthenticationBrokerStatics2)->abi_AuthenticateSilentlyWithOptionsAsync(get_abi(requestUri), options, put_abi(asyncInfo)));
    return asyncInfo;
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> WebAuthenticationBroker::AuthenticateAsync(Windows::Security::Authentication::Web::WebAuthenticationOptions options, const Windows::Foundation::Uri & requestUri, const Windows::Foundation::Uri & callbackUri)
{
    return get_activation_factory<WebAuthenticationBroker, IWebAuthenticationBrokerStatics>().AuthenticateAsync(options, requestUri, callbackUri);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> WebAuthenticationBroker::AuthenticateAsync(Windows::Security::Authentication::Web::WebAuthenticationOptions options, const Windows::Foundation::Uri & requestUri)
{
    return get_activation_factory<WebAuthenticationBroker, IWebAuthenticationBrokerStatics>().AuthenticateAsync(options, requestUri);
}

inline Windows::Foundation::Uri WebAuthenticationBroker::GetCurrentApplicationCallbackUri()
{
    return get_activation_factory<WebAuthenticationBroker, IWebAuthenticationBrokerStatics>().GetCurrentApplicationCallbackUri();
}

inline void WebAuthenticationBroker::AuthenticateAndContinue(const Windows::Foundation::Uri & requestUri)
{
    get_activation_factory<WebAuthenticationBroker, IWebAuthenticationBrokerStatics2>().AuthenticateAndContinue(requestUri);
}

inline void WebAuthenticationBroker::AuthenticateAndContinue(const Windows::Foundation::Uri & requestUri, const Windows::Foundation::Uri & callbackUri)
{
    get_activation_factory<WebAuthenticationBroker, IWebAuthenticationBrokerStatics2>().AuthenticateAndContinue(requestUri, callbackUri);
}

inline void WebAuthenticationBroker::AuthenticateAndContinue(const Windows::Foundation::Uri & requestUri, const Windows::Foundation::Uri & callbackUri, const Windows::Foundation::Collections::ValueSet & continuationData, Windows::Security::Authentication::Web::WebAuthenticationOptions options)
{
    get_activation_factory<WebAuthenticationBroker, IWebAuthenticationBrokerStatics2>().AuthenticateAndContinue(requestUri, callbackUri, continuationData, options);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> WebAuthenticationBroker::AuthenticateSilentlyAsync(const Windows::Foundation::Uri & requestUri)
{
    return get_activation_factory<WebAuthenticationBroker, IWebAuthenticationBrokerStatics2>().AuthenticateSilentlyAsync(requestUri);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> WebAuthenticationBroker::AuthenticateSilentlyAsync(const Windows::Foundation::Uri & requestUri, Windows::Security::Authentication::Web::WebAuthenticationOptions options)
{
    return get_activation_factory<WebAuthenticationBroker, IWebAuthenticationBrokerStatics2>().AuthenticateSilentlyAsync(requestUri, options);
}

}

}
#pragma warning(pop)
