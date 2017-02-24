// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Web.Http.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Security.Cryptography.Certificates.3.h"
#include "internal/Windows.Networking.Sockets.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Security.Credentials.3.h"
#include "internal/Windows.Web.Http.Filters.3.h"
#include "Windows.Web.Http.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Web::Http::Filters::IHttpBaseProtocolFilter> : produce_base<D, Windows::Web::Http::Filters::IHttpBaseProtocolFilter>
{
    HRESULT __stdcall get_AllowAutoRedirect(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowAutoRedirect());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowAutoRedirect(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowAutoRedirect(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowUI(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowUI());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowUI(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowUI(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutomaticDecompression(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutomaticDecompression());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutomaticDecompression(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutomaticDecompression(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CacheControl(impl::abi_arg_out<Windows::Web::Http::Filters::IHttpCacheControl> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CacheControl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CookieManager(impl::abi_arg_out<Windows::Web::Http::IHttpCookieManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CookieManager());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClientCertificate(impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ICertificate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClientCertificate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ClientCertificate(impl::abi_arg_in<Windows::Security::Cryptography::Certificates::ICertificate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClientCertificate(*reinterpret_cast<const Windows::Security::Cryptography::Certificates::Certificate *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IgnorableServerCertificateErrors(impl::abi_arg_out<Windows::Foundation::Collections::IVector<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IgnorableServerCertificateErrors());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxConnectionsPerServer(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxConnectionsPerServer());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxConnectionsPerServer(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxConnectionsPerServer(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProxyCredential(impl::abi_arg_out<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProxyCredential());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProxyCredential(impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProxyCredential(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServerCredential(impl::abi_arg_out<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerCredential());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ServerCredential(impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServerCredential(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UseProxy(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UseProxy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UseProxy(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UseProxy(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Filters::IHttpBaseProtocolFilter2> : produce_base<D, Windows::Web::Http::Filters::IHttpBaseProtocolFilter2>
{
    HRESULT __stdcall get_MaxVersion(Windows::Web::Http::HttpVersion * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxVersion());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxVersion(Windows::Web::Http::HttpVersion value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxVersion(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Filters::IHttpBaseProtocolFilter3> : produce_base<D, Windows::Web::Http::Filters::IHttpBaseProtocolFilter3>
{
    HRESULT __stdcall get_CookieUsageBehavior(Windows::Web::Http::Filters::HttpCookieUsageBehavior * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CookieUsageBehavior());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CookieUsageBehavior(Windows::Web::Http::Filters::HttpCookieUsageBehavior value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CookieUsageBehavior(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Filters::IHttpBaseProtocolFilter4> : produce_base<D, Windows::Web::Http::Filters::IHttpBaseProtocolFilter4>
{
    HRESULT __stdcall add_ServerCustomValidationRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Web::Http::Filters::HttpBaseProtocolFilter, Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().ServerCustomValidationRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Filters::HttpBaseProtocolFilter, Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ServerCustomValidationRequested(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServerCustomValidationRequested(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearAuthenticationCache() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearAuthenticationCache();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Filters::IHttpCacheControl> : produce_base<D, Windows::Web::Http::Filters::IHttpCacheControl>
{
    HRESULT __stdcall get_ReadBehavior(Windows::Web::Http::Filters::HttpCacheReadBehavior * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadBehavior());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ReadBehavior(Windows::Web::Http::Filters::HttpCacheReadBehavior value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReadBehavior(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WriteBehavior(Windows::Web::Http::Filters::HttpCacheWriteBehavior * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WriteBehavior());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_WriteBehavior(Windows::Web::Http::Filters::HttpCacheWriteBehavior value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteBehavior(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Filters::IHttpFilter> : produce_base<D, Windows::Web::Http::Filters::IHttpFilter>
{
    HRESULT __stdcall abi_SendRequestAsync(impl::abi_arg_in<Windows::Web::Http::IHttpRequestMessage> request, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SendRequestAsync(*reinterpret_cast<const Windows::Web::Http::HttpRequestMessage *>(&request)));
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
struct produce<D, Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs> : produce_base<D, Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs>
{
    HRESULT __stdcall get_RequestMessage(impl::abi_arg_out<Windows::Web::Http::IHttpRequestMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServerCertificate(impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ICertificate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerCertificate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServerCertificateErrorSeverity(Windows::Networking::Sockets::SocketSslErrorSeverity * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerCertificateErrorSeverity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServerCertificateErrors(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerCertificateErrors());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServerIntermediateCertificates(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerIntermediateCertificates());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Reject() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Reject();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Web::Http::Filters {

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> impl_IHttpFilter<D>::SendRequestAsync(const Windows::Web::Http::HttpRequestMessage & request) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> operation;
    check_hresult(WINRT_SHIM(IHttpFilter)->abi_SendRequestAsync(get_abi(request), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Web::Http::Filters::HttpCacheReadBehavior impl_IHttpCacheControl<D>::ReadBehavior() const
{
    Windows::Web::Http::Filters::HttpCacheReadBehavior value {};
    check_hresult(WINRT_SHIM(IHttpCacheControl)->get_ReadBehavior(&value));
    return value;
}

template <typename D> void impl_IHttpCacheControl<D>::ReadBehavior(Windows::Web::Http::Filters::HttpCacheReadBehavior value) const
{
    check_hresult(WINRT_SHIM(IHttpCacheControl)->put_ReadBehavior(value));
}

template <typename D> Windows::Web::Http::Filters::HttpCacheWriteBehavior impl_IHttpCacheControl<D>::WriteBehavior() const
{
    Windows::Web::Http::Filters::HttpCacheWriteBehavior value {};
    check_hresult(WINRT_SHIM(IHttpCacheControl)->get_WriteBehavior(&value));
    return value;
}

template <typename D> void impl_IHttpCacheControl<D>::WriteBehavior(Windows::Web::Http::Filters::HttpCacheWriteBehavior value) const
{
    check_hresult(WINRT_SHIM(IHttpCacheControl)->put_WriteBehavior(value));
}

template <typename D> Windows::Web::Http::HttpRequestMessage impl_IHttpServerCustomValidationRequestedEventArgs<D>::RequestMessage() const
{
    Windows::Web::Http::HttpRequestMessage value { nullptr };
    check_hresult(WINRT_SHIM(IHttpServerCustomValidationRequestedEventArgs)->get_RequestMessage(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::Certificate impl_IHttpServerCustomValidationRequestedEventArgs<D>::ServerCertificate() const
{
    Windows::Security::Cryptography::Certificates::Certificate value { nullptr };
    check_hresult(WINRT_SHIM(IHttpServerCustomValidationRequestedEventArgs)->get_ServerCertificate(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::Sockets::SocketSslErrorSeverity impl_IHttpServerCustomValidationRequestedEventArgs<D>::ServerCertificateErrorSeverity() const
{
    Windows::Networking::Sockets::SocketSslErrorSeverity value {};
    check_hresult(WINRT_SHIM(IHttpServerCustomValidationRequestedEventArgs)->get_ServerCertificateErrorSeverity(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> impl_IHttpServerCustomValidationRequestedEventArgs<D>::ServerCertificateErrors() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> value;
    check_hresult(WINRT_SHIM(IHttpServerCustomValidationRequestedEventArgs)->get_ServerCertificateErrors(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> impl_IHttpServerCustomValidationRequestedEventArgs<D>::ServerIntermediateCertificates() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> value;
    check_hresult(WINRT_SHIM(IHttpServerCustomValidationRequestedEventArgs)->get_ServerIntermediateCertificates(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpServerCustomValidationRequestedEventArgs<D>::Reject() const
{
    check_hresult(WINRT_SHIM(IHttpServerCustomValidationRequestedEventArgs)->abi_Reject());
}

template <typename D> Windows::Foundation::Deferral impl_IHttpServerCustomValidationRequestedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral result { nullptr };
    check_hresult(WINRT_SHIM(IHttpServerCustomValidationRequestedEventArgs)->abi_GetDeferral(put_abi(result)));
    return result;
}

template <typename D> bool impl_IHttpBaseProtocolFilter<D>::AllowAutoRedirect() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->get_AllowAutoRedirect(&value));
    return value;
}

template <typename D> void impl_IHttpBaseProtocolFilter<D>::AllowAutoRedirect(bool value) const
{
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->put_AllowAutoRedirect(value));
}

template <typename D> bool impl_IHttpBaseProtocolFilter<D>::AllowUI() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->get_AllowUI(&value));
    return value;
}

template <typename D> void impl_IHttpBaseProtocolFilter<D>::AllowUI(bool value) const
{
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->put_AllowUI(value));
}

template <typename D> bool impl_IHttpBaseProtocolFilter<D>::AutomaticDecompression() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->get_AutomaticDecompression(&value));
    return value;
}

template <typename D> void impl_IHttpBaseProtocolFilter<D>::AutomaticDecompression(bool value) const
{
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->put_AutomaticDecompression(value));
}

template <typename D> Windows::Web::Http::Filters::HttpCacheControl impl_IHttpBaseProtocolFilter<D>::CacheControl() const
{
    Windows::Web::Http::Filters::HttpCacheControl value { nullptr };
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->get_CacheControl(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::HttpCookieManager impl_IHttpBaseProtocolFilter<D>::CookieManager() const
{
    Windows::Web::Http::HttpCookieManager value { nullptr };
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->get_CookieManager(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::Certificate impl_IHttpBaseProtocolFilter<D>::ClientCertificate() const
{
    Windows::Security::Cryptography::Certificates::Certificate value { nullptr };
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->get_ClientCertificate(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpBaseProtocolFilter<D>::ClientCertificate(const Windows::Security::Cryptography::Certificates::Certificate & value) const
{
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->put_ClientCertificate(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> impl_IHttpBaseProtocolFilter<D>::IgnorableServerCertificateErrors() const
{
    Windows::Foundation::Collections::IVector<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> value;
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->get_IgnorableServerCertificateErrors(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IHttpBaseProtocolFilter<D>::MaxConnectionsPerServer() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->get_MaxConnectionsPerServer(&value));
    return value;
}

template <typename D> void impl_IHttpBaseProtocolFilter<D>::MaxConnectionsPerServer(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->put_MaxConnectionsPerServer(value));
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_IHttpBaseProtocolFilter<D>::ProxyCredential() const
{
    Windows::Security::Credentials::PasswordCredential value { nullptr };
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->get_ProxyCredential(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpBaseProtocolFilter<D>::ProxyCredential(const Windows::Security::Credentials::PasswordCredential & value) const
{
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->put_ProxyCredential(get_abi(value)));
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_IHttpBaseProtocolFilter<D>::ServerCredential() const
{
    Windows::Security::Credentials::PasswordCredential value { nullptr };
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->get_ServerCredential(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpBaseProtocolFilter<D>::ServerCredential(const Windows::Security::Credentials::PasswordCredential & value) const
{
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->put_ServerCredential(get_abi(value)));
}

template <typename D> bool impl_IHttpBaseProtocolFilter<D>::UseProxy() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->get_UseProxy(&value));
    return value;
}

template <typename D> void impl_IHttpBaseProtocolFilter<D>::UseProxy(bool value) const
{
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter)->put_UseProxy(value));
}

template <typename D> Windows::Web::Http::HttpVersion impl_IHttpBaseProtocolFilter2<D>::MaxVersion() const
{
    Windows::Web::Http::HttpVersion value {};
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter2)->get_MaxVersion(&value));
    return value;
}

template <typename D> void impl_IHttpBaseProtocolFilter2<D>::MaxVersion(Windows::Web::Http::HttpVersion value) const
{
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter2)->put_MaxVersion(value));
}

template <typename D> Windows::Web::Http::Filters::HttpCookieUsageBehavior impl_IHttpBaseProtocolFilter3<D>::CookieUsageBehavior() const
{
    Windows::Web::Http::Filters::HttpCookieUsageBehavior value {};
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter3)->get_CookieUsageBehavior(&value));
    return value;
}

template <typename D> void impl_IHttpBaseProtocolFilter3<D>::CookieUsageBehavior(Windows::Web::Http::Filters::HttpCookieUsageBehavior value) const
{
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter3)->put_CookieUsageBehavior(value));
}

template <typename D> event_token impl_IHttpBaseProtocolFilter4<D>::ServerCustomValidationRequested(const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Filters::HttpBaseProtocolFilter, Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter4)->add_ServerCustomValidationRequested(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IHttpBaseProtocolFilter4> impl_IHttpBaseProtocolFilter4<D>::ServerCustomValidationRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Filters::HttpBaseProtocolFilter, Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs> & eventHandler) const
{
    return impl::make_event_revoker<D, IHttpBaseProtocolFilter4>(this, &ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter4::remove_ServerCustomValidationRequested, ServerCustomValidationRequested(eventHandler));
}

template <typename D> void impl_IHttpBaseProtocolFilter4<D>::ServerCustomValidationRequested(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter4)->remove_ServerCustomValidationRequested(eventCookie));
}

template <typename D> void impl_IHttpBaseProtocolFilter4<D>::ClearAuthenticationCache() const
{
    check_hresult(WINRT_SHIM(IHttpBaseProtocolFilter4)->abi_ClearAuthenticationCache());
}

inline HttpBaseProtocolFilter::HttpBaseProtocolFilter() :
    HttpBaseProtocolFilter(activate_instance<HttpBaseProtocolFilter>())
{}

}

}
#pragma warning(pop)
