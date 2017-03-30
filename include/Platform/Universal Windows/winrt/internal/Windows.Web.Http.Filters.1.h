// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Web.Http.Filters.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Networking.Sockets.0.h"
#include "Windows.Security.Credentials.0.h"
#include "Windows.Security.Cryptography.Certificates.0.h"
#include "Windows.Web.Http.0.h"
#include "Windows.Web.Http.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Security.Cryptography.Certificates.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Web::Http::Filters {

struct __declspec(uuid("71c89b09-e131-4b54-a53c-eb43ff37e9bb")) __declspec(novtable) IHttpBaseProtocolFilter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AllowAutoRedirect(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowAutoRedirect(bool value) = 0;
    virtual HRESULT __stdcall get_AllowUI(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowUI(bool value) = 0;
    virtual HRESULT __stdcall get_AutomaticDecompression(bool * value) = 0;
    virtual HRESULT __stdcall put_AutomaticDecompression(bool value) = 0;
    virtual HRESULT __stdcall get_CacheControl(Windows::Web::Http::Filters::IHttpCacheControl ** value) = 0;
    virtual HRESULT __stdcall get_CookieManager(Windows::Web::Http::IHttpCookieManager ** value) = 0;
    virtual HRESULT __stdcall get_ClientCertificate(Windows::Security::Cryptography::Certificates::ICertificate ** value) = 0;
    virtual HRESULT __stdcall put_ClientCertificate(Windows::Security::Cryptography::Certificates::ICertificate * value) = 0;
    virtual HRESULT __stdcall get_IgnorableServerCertificateErrors(Windows::Foundation::Collections::IVector<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> ** value) = 0;
    virtual HRESULT __stdcall get_MaxConnectionsPerServer(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_MaxConnectionsPerServer(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ProxyCredential(Windows::Security::Credentials::IPasswordCredential ** value) = 0;
    virtual HRESULT __stdcall put_ProxyCredential(Windows::Security::Credentials::IPasswordCredential * value) = 0;
    virtual HRESULT __stdcall get_ServerCredential(Windows::Security::Credentials::IPasswordCredential ** value) = 0;
    virtual HRESULT __stdcall put_ServerCredential(Windows::Security::Credentials::IPasswordCredential * value) = 0;
    virtual HRESULT __stdcall get_UseProxy(bool * value) = 0;
    virtual HRESULT __stdcall put_UseProxy(bool value) = 0;
};

struct __declspec(uuid("2ec30013-9427-4900-a017-fa7da3b5c9ae")) __declspec(novtable) IHttpBaseProtocolFilter2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxVersion(winrt::Windows::Web::Http::HttpVersion * value) = 0;
    virtual HRESULT __stdcall put_MaxVersion(winrt::Windows::Web::Http::HttpVersion value) = 0;
};

struct __declspec(uuid("d43f4d4c-bd42-43ae-8717-ad2c8f4b2937")) __declspec(novtable) IHttpBaseProtocolFilter3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CookieUsageBehavior(winrt::Windows::Web::Http::Filters::HttpCookieUsageBehavior * value) = 0;
    virtual HRESULT __stdcall put_CookieUsageBehavior(winrt::Windows::Web::Http::Filters::HttpCookieUsageBehavior value) = 0;
};

struct __declspec(uuid("9fe36ccf-2983-4893-941f-eb518ca8cef9")) __declspec(novtable) IHttpBaseProtocolFilter4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_ServerCustomValidationRequested(Windows::Foundation::TypedEventHandler<Windows::Web::Http::Filters::HttpBaseProtocolFilter, Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_ServerCustomValidationRequested(event_token eventCookie) = 0;
    virtual HRESULT __stdcall abi_ClearAuthenticationCache() = 0;
};

struct __declspec(uuid("c77e1cb4-3cea-4eb5-ac85-04e186e63ab7")) __declspec(novtable) IHttpCacheControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ReadBehavior(winrt::Windows::Web::Http::Filters::HttpCacheReadBehavior * value) = 0;
    virtual HRESULT __stdcall put_ReadBehavior(winrt::Windows::Web::Http::Filters::HttpCacheReadBehavior value) = 0;
    virtual HRESULT __stdcall get_WriteBehavior(winrt::Windows::Web::Http::Filters::HttpCacheWriteBehavior * value) = 0;
    virtual HRESULT __stdcall put_WriteBehavior(winrt::Windows::Web::Http::Filters::HttpCacheWriteBehavior value) = 0;
};

struct __declspec(uuid("a4cb6dd5-0902-439e-bfd7-e12552b165ce")) __declspec(novtable) IHttpFilter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SendRequestAsync(Windows::Web::Http::IHttpRequestMessage * request, Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> ** operation) = 0;
};

struct __declspec(uuid("3165fe32-e7dd-48b7-a361-939c750e63cc")) __declspec(novtable) IHttpServerCustomValidationRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RequestMessage(Windows::Web::Http::IHttpRequestMessage ** value) = 0;
    virtual HRESULT __stdcall get_ServerCertificate(Windows::Security::Cryptography::Certificates::ICertificate ** value) = 0;
    virtual HRESULT __stdcall get_ServerCertificateErrorSeverity(winrt::Windows::Networking::Sockets::SocketSslErrorSeverity * value) = 0;
    virtual HRESULT __stdcall get_ServerCertificateErrors(Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> ** value) = 0;
    virtual HRESULT __stdcall get_ServerIntermediateCertificates(Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ** value) = 0;
    virtual HRESULT __stdcall abi_Reject() = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Web::Http::Filters::HttpBaseProtocolFilter> { using default_interface = Windows::Web::Http::Filters::IHttpBaseProtocolFilter; };
template <> struct traits<Windows::Web::Http::Filters::HttpCacheControl> { using default_interface = Windows::Web::Http::Filters::IHttpCacheControl; };
template <> struct traits<Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs> { using default_interface = Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs; };

}

namespace Windows::Web::Http::Filters {

template <typename D>
struct WINRT_EBO impl_IHttpBaseProtocolFilter
{
    bool AllowAutoRedirect() const;
    void AllowAutoRedirect(bool value) const;
    bool AllowUI() const;
    void AllowUI(bool value) const;
    bool AutomaticDecompression() const;
    void AutomaticDecompression(bool value) const;
    Windows::Web::Http::Filters::HttpCacheControl CacheControl() const;
    Windows::Web::Http::HttpCookieManager CookieManager() const;
    Windows::Security::Cryptography::Certificates::Certificate ClientCertificate() const;
    void ClientCertificate(const Windows::Security::Cryptography::Certificates::Certificate & value) const;
    Windows::Foundation::Collections::IVector<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> IgnorableServerCertificateErrors() const;
    uint32_t MaxConnectionsPerServer() const;
    void MaxConnectionsPerServer(uint32_t value) const;
    Windows::Security::Credentials::PasswordCredential ProxyCredential() const;
    void ProxyCredential(const Windows::Security::Credentials::PasswordCredential & value) const;
    Windows::Security::Credentials::PasswordCredential ServerCredential() const;
    void ServerCredential(const Windows::Security::Credentials::PasswordCredential & value) const;
    bool UseProxy() const;
    void UseProxy(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpBaseProtocolFilter2
{
    Windows::Web::Http::HttpVersion MaxVersion() const;
    void MaxVersion(Windows::Web::Http::HttpVersion value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpBaseProtocolFilter3
{
    Windows::Web::Http::Filters::HttpCookieUsageBehavior CookieUsageBehavior() const;
    void CookieUsageBehavior(Windows::Web::Http::Filters::HttpCookieUsageBehavior value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpBaseProtocolFilter4
{
    event_token ServerCustomValidationRequested(const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Filters::HttpBaseProtocolFilter, Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs> & eventHandler) const;
    using ServerCustomValidationRequested_revoker = event_revoker<IHttpBaseProtocolFilter4>;
    ServerCustomValidationRequested_revoker ServerCustomValidationRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Filters::HttpBaseProtocolFilter, Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs> & eventHandler) const;
    void ServerCustomValidationRequested(event_token eventCookie) const;
    void ClearAuthenticationCache() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpCacheControl
{
    Windows::Web::Http::Filters::HttpCacheReadBehavior ReadBehavior() const;
    void ReadBehavior(Windows::Web::Http::Filters::HttpCacheReadBehavior value) const;
    Windows::Web::Http::Filters::HttpCacheWriteBehavior WriteBehavior() const;
    void WriteBehavior(Windows::Web::Http::Filters::HttpCacheWriteBehavior value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpFilter
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> SendRequestAsync(const Windows::Web::Http::HttpRequestMessage & request) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpServerCustomValidationRequestedEventArgs
{
    Windows::Web::Http::HttpRequestMessage RequestMessage() const;
    Windows::Security::Cryptography::Certificates::Certificate ServerCertificate() const;
    Windows::Networking::Sockets::SocketSslErrorSeverity ServerCertificateErrorSeverity() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> ServerCertificateErrors() const;
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ServerIntermediateCertificates() const;
    void Reject() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

}

namespace impl {

template <> struct traits<Windows::Web::Http::Filters::IHttpBaseProtocolFilter>
{
    using abi = ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter;
    template <typename D> using consume = Windows::Web::Http::Filters::impl_IHttpBaseProtocolFilter<D>;
};

template <> struct traits<Windows::Web::Http::Filters::IHttpBaseProtocolFilter2>
{
    using abi = ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter2;
    template <typename D> using consume = Windows::Web::Http::Filters::impl_IHttpBaseProtocolFilter2<D>;
};

template <> struct traits<Windows::Web::Http::Filters::IHttpBaseProtocolFilter3>
{
    using abi = ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter3;
    template <typename D> using consume = Windows::Web::Http::Filters::impl_IHttpBaseProtocolFilter3<D>;
};

template <> struct traits<Windows::Web::Http::Filters::IHttpBaseProtocolFilter4>
{
    using abi = ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter4;
    template <typename D> using consume = Windows::Web::Http::Filters::impl_IHttpBaseProtocolFilter4<D>;
};

template <> struct traits<Windows::Web::Http::Filters::IHttpCacheControl>
{
    using abi = ABI::Windows::Web::Http::Filters::IHttpCacheControl;
    template <typename D> using consume = Windows::Web::Http::Filters::impl_IHttpCacheControl<D>;
};

template <> struct traits<Windows::Web::Http::Filters::IHttpFilter>
{
    using abi = ABI::Windows::Web::Http::Filters::IHttpFilter;
    template <typename D> using consume = Windows::Web::Http::Filters::impl_IHttpFilter<D>;
};

template <> struct traits<Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs>
{
    using abi = ABI::Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs;
    template <typename D> using consume = Windows::Web::Http::Filters::impl_IHttpServerCustomValidationRequestedEventArgs<D>;
};

template <> struct traits<Windows::Web::Http::Filters::HttpBaseProtocolFilter>
{
    using abi = ABI::Windows::Web::Http::Filters::HttpBaseProtocolFilter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Filters.HttpBaseProtocolFilter"; }
};

template <> struct traits<Windows::Web::Http::Filters::HttpCacheControl>
{
    using abi = ABI::Windows::Web::Http::Filters::HttpCacheControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Filters.HttpCacheControl"; }
};

template <> struct traits<Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs>
{
    using abi = ABI::Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Filters.HttpServerCustomValidationRequestedEventArgs"; }
};

}

}
