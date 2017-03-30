// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Authentication.Web.Core.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Security::Authentication::Web::Core {

struct WINRT_EBO WebAccountEventArgs :
    Windows::Security::Authentication::Web::Core::IWebAccountEventArgs
{
    WebAccountEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebAccountMonitor :
    Windows::Security::Authentication::Web::Core::IWebAccountMonitor
{
    WebAccountMonitor(std::nullptr_t) noexcept {}
};

struct WebAuthenticationCoreManager
{
    WebAuthenticationCoreManager() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> GetTokenSilentlyAsync(const Windows::Security::Authentication::Web::Core::WebTokenRequest & request);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> GetTokenSilentlyAsync(const Windows::Security::Authentication::Web::Core::WebTokenRequest & request, const Windows::Security::Credentials::WebAccount & webAccount);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> RequestTokenAsync(const Windows::Security::Authentication::Web::Core::WebTokenRequest & request);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> RequestTokenAsync(const Windows::Security::Authentication::Web::Core::WebTokenRequest & request, const Windows::Security::Credentials::WebAccount & webAccount);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> FindAccountAsync(const Windows::Security::Credentials::WebAccountProvider & provider, hstring_view webAccountId);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> FindAccountProviderAsync(hstring_view webAccountProviderId);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> FindAccountProviderAsync(hstring_view webAccountProviderId, hstring_view authority);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> FindAccountProviderAsync(hstring_view webAccountProviderId, hstring_view authority, const Windows::System::User & user);
    static Windows::Security::Authentication::Web::Core::WebAccountMonitor CreateWebAccountMonitor(iterable<Windows::Security::Credentials::WebAccount> webAccounts);
};

struct WINRT_EBO WebProviderError :
    Windows::Security::Authentication::Web::Core::IWebProviderError
{
    WebProviderError(std::nullptr_t) noexcept {}
    WebProviderError(uint32_t errorCode, hstring_view errorMessage);
};

struct WINRT_EBO WebTokenRequest :
    Windows::Security::Authentication::Web::Core::IWebTokenRequest,
    impl::require<WebTokenRequest, Windows::Security::Authentication::Web::Core::IWebTokenRequest2>
{
    WebTokenRequest(std::nullptr_t) noexcept {}
    WebTokenRequest(const Windows::Security::Credentials::WebAccountProvider & provider, hstring_view scope, hstring_view clientId);
    WebTokenRequest(const Windows::Security::Credentials::WebAccountProvider & provider, hstring_view scope, hstring_view clientId, Windows::Security::Authentication::Web::Core::WebTokenRequestPromptType promptType);
    WebTokenRequest(const Windows::Security::Credentials::WebAccountProvider & provider);
    WebTokenRequest(const Windows::Security::Credentials::WebAccountProvider & provider, hstring_view scope);
};

struct WINRT_EBO WebTokenRequestResult :
    Windows::Security::Authentication::Web::Core::IWebTokenRequestResult
{
    WebTokenRequestResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebTokenResponse :
    Windows::Security::Authentication::Web::Core::IWebTokenResponse
{
    WebTokenResponse(std::nullptr_t) noexcept {}
    WebTokenResponse();
    WebTokenResponse(hstring_view token);
    WebTokenResponse(hstring_view token, const Windows::Security::Credentials::WebAccount & webAccount);
    WebTokenResponse(hstring_view token, const Windows::Security::Credentials::WebAccount & webAccount, const Windows::Security::Authentication::Web::Core::WebProviderError & error);
};

}

}
