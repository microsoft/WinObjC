// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Security.Authentication.Web.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::Authentication::Web {

struct __declspec(uuid("2f149f1a-e673-40b5-bc22-201a6864a37b")) __declspec(novtable) IWebAuthenticationBrokerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AuthenticateWithCallbackUriAsync(winrt::Windows::Security::Authentication::Web::WebAuthenticationOptions options, Windows::Foundation::IUriRuntimeClass * requestUri, Windows::Foundation::IUriRuntimeClass * callbackUri, Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_AuthenticateWithoutCallbackUriAsync(winrt::Windows::Security::Authentication::Web::WebAuthenticationOptions options, Windows::Foundation::IUriRuntimeClass * requestUri, Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_GetCurrentApplicationCallbackUri(Windows::Foundation::IUriRuntimeClass ** callbackUri) = 0;
};

struct __declspec(uuid("73cdfb9e-14e7-41da-a971-aaf4410b621e")) __declspec(novtable) IWebAuthenticationBrokerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AuthenticateAndContinue(Windows::Foundation::IUriRuntimeClass * requestUri) = 0;
    virtual HRESULT __stdcall abi_AuthenticateWithCallbackUriAndContinue(Windows::Foundation::IUriRuntimeClass * requestUri, Windows::Foundation::IUriRuntimeClass * callbackUri) = 0;
    virtual HRESULT __stdcall abi_AuthenticateWithCallbackUriContinuationDataAndOptionsAndContinue(Windows::Foundation::IUriRuntimeClass * requestUri, Windows::Foundation::IUriRuntimeClass * callbackUri, Windows::Foundation::Collections::IPropertySet * continuationData, winrt::Windows::Security::Authentication::Web::WebAuthenticationOptions options) = 0;
    virtual HRESULT __stdcall abi_AuthenticateSilentlyAsync(Windows::Foundation::IUriRuntimeClass * requestUri, Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_AuthenticateSilentlyWithOptionsAsync(Windows::Foundation::IUriRuntimeClass * requestUri, winrt::Windows::Security::Authentication::Web::WebAuthenticationOptions options, Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> ** asyncInfo) = 0;
};

struct __declspec(uuid("64002b4b-ede9-470a-a5cd-0323faf6e262")) __declspec(novtable) IWebAuthenticationResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ResponseData(hstring * value) = 0;
    virtual HRESULT __stdcall get_ResponseStatus(winrt::Windows::Security::Authentication::Web::WebAuthenticationStatus * value) = 0;
    virtual HRESULT __stdcall get_ResponseErrorDetail(uint32_t * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Security::Authentication::Web::WebAuthenticationResult> { using default_interface = Windows::Security::Authentication::Web::IWebAuthenticationResult; };

}

namespace Windows::Security::Authentication::Web {

template <typename D>
struct WINRT_EBO impl_IWebAuthenticationBrokerStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> AuthenticateAsync(Windows::Security::Authentication::Web::WebAuthenticationOptions options, const Windows::Foundation::Uri & requestUri, const Windows::Foundation::Uri & callbackUri) const;
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> AuthenticateAsync(Windows::Security::Authentication::Web::WebAuthenticationOptions options, const Windows::Foundation::Uri & requestUri) const;
    Windows::Foundation::Uri GetCurrentApplicationCallbackUri() const;
};

template <typename D>
struct WINRT_EBO impl_IWebAuthenticationBrokerStatics2
{
    void AuthenticateAndContinue(const Windows::Foundation::Uri & requestUri) const;
    void AuthenticateAndContinue(const Windows::Foundation::Uri & requestUri, const Windows::Foundation::Uri & callbackUri) const;
    void AuthenticateAndContinue(const Windows::Foundation::Uri & requestUri, const Windows::Foundation::Uri & callbackUri, const Windows::Foundation::Collections::ValueSet & continuationData, Windows::Security::Authentication::Web::WebAuthenticationOptions options) const;
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> AuthenticateSilentlyAsync(const Windows::Foundation::Uri & requestUri) const;
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> AuthenticateSilentlyAsync(const Windows::Foundation::Uri & requestUri, Windows::Security::Authentication::Web::WebAuthenticationOptions options) const;
};

template <typename D>
struct WINRT_EBO impl_IWebAuthenticationResult
{
    hstring ResponseData() const;
    Windows::Security::Authentication::Web::WebAuthenticationStatus ResponseStatus() const;
    uint32_t ResponseErrorDetail() const;
};

}

namespace impl {

template <> struct traits<Windows::Security::Authentication::Web::IWebAuthenticationBrokerStatics>
{
    using abi = ABI::Windows::Security::Authentication::Web::IWebAuthenticationBrokerStatics;
    template <typename D> using consume = Windows::Security::Authentication::Web::impl_IWebAuthenticationBrokerStatics<D>;
};

template <> struct traits<Windows::Security::Authentication::Web::IWebAuthenticationBrokerStatics2>
{
    using abi = ABI::Windows::Security::Authentication::Web::IWebAuthenticationBrokerStatics2;
    template <typename D> using consume = Windows::Security::Authentication::Web::impl_IWebAuthenticationBrokerStatics2<D>;
};

template <> struct traits<Windows::Security::Authentication::Web::IWebAuthenticationResult>
{
    using abi = ABI::Windows::Security::Authentication::Web::IWebAuthenticationResult;
    template <typename D> using consume = Windows::Security::Authentication::Web::impl_IWebAuthenticationResult<D>;
};

template <> struct traits<Windows::Security::Authentication::Web::WebAuthenticationBroker>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Web.WebAuthenticationBroker"; }
};

template <> struct traits<Windows::Security::Authentication::Web::WebAuthenticationResult>
{
    using abi = ABI::Windows::Security::Authentication::Web::WebAuthenticationResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Web.WebAuthenticationResult"; }
};

}

}
