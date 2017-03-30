// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Authentication.Web.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Security::Authentication::Web {

struct WebAuthenticationBroker
{
    WebAuthenticationBroker() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> AuthenticateAsync(Windows::Security::Authentication::Web::WebAuthenticationOptions options, const Windows::Foundation::Uri & requestUri, const Windows::Foundation::Uri & callbackUri);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> AuthenticateAsync(Windows::Security::Authentication::Web::WebAuthenticationOptions options, const Windows::Foundation::Uri & requestUri);
    static Windows::Foundation::Uri GetCurrentApplicationCallbackUri();
    static void AuthenticateAndContinue(const Windows::Foundation::Uri & requestUri);
    static void AuthenticateAndContinue(const Windows::Foundation::Uri & requestUri, const Windows::Foundation::Uri & callbackUri);
    static void AuthenticateAndContinue(const Windows::Foundation::Uri & requestUri, const Windows::Foundation::Uri & callbackUri, const Windows::Foundation::Collections::ValueSet & continuationData, Windows::Security::Authentication::Web::WebAuthenticationOptions options);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> AuthenticateSilentlyAsync(const Windows::Foundation::Uri & requestUri);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> AuthenticateSilentlyAsync(const Windows::Foundation::Uri & requestUri, Windows::Security::Authentication::Web::WebAuthenticationOptions options);
};

struct WINRT_EBO WebAuthenticationResult :
    Windows::Security::Authentication::Web::IWebAuthenticationResult
{
    WebAuthenticationResult(std::nullptr_t) noexcept {}
};

}

}
