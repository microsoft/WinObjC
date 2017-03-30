// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Authentication.Web.Provider.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Security::Authentication::Web::Provider {

struct WINRT_EBO WebAccountClientView :
    Windows::Security::Authentication::Web::Provider::IWebAccountClientView
{
    WebAccountClientView(std::nullptr_t) noexcept {}
    WebAccountClientView(Windows::Security::Authentication::Web::Provider::WebAccountClientViewType viewType, const Windows::Foundation::Uri & applicationCallbackUri);
    WebAccountClientView(Windows::Security::Authentication::Web::Provider::WebAccountClientViewType viewType, const Windows::Foundation::Uri & applicationCallbackUri, hstring_view accountPairwiseId);
};

struct WebAccountManager
{
    WebAccountManager() = delete;
    static Windows::Foundation::IAsyncAction UpdateWebAccountPropertiesAsync(const Windows::Security::Credentials::WebAccount & webAccount, hstring_view webAccountUserName, map_view<hstring, hstring> additionalProperties);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> AddWebAccountAsync(hstring_view webAccountId, hstring_view webAccountUserName, map_view<hstring, hstring> props);
    static Windows::Foundation::IAsyncAction DeleteWebAccountAsync(const Windows::Security::Credentials::WebAccount & webAccount);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::WebAccount>> FindAllProviderWebAccountsAsync();
    static Windows::Foundation::IAsyncAction PushCookiesAsync(const Windows::Foundation::Uri & uri, vector_view<Windows::Web::Http::HttpCookie> cookies);
    static Windows::Foundation::IAsyncAction SetViewAsync(const Windows::Security::Credentials::WebAccount & webAccount, const Windows::Security::Authentication::Web::Provider::WebAccountClientView & view);
    static Windows::Foundation::IAsyncAction ClearViewAsync(const Windows::Security::Credentials::WebAccount & webAccount, const Windows::Foundation::Uri & applicationCallbackUri);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Web::Provider::WebAccountClientView>> GetViewsAsync(const Windows::Security::Credentials::WebAccount & webAccount);
    static Windows::Foundation::IAsyncAction SetWebAccountPictureAsync(const Windows::Security::Credentials::WebAccount & webAccount, const Windows::Storage::Streams::IRandomAccessStream & webAccountPicture);
    static Windows::Foundation::IAsyncAction ClearWebAccountPictureAsync(const Windows::Security::Credentials::WebAccount & webAccount);
    static Windows::Foundation::IAsyncAction PullCookiesAsync(hstring_view uriString, hstring_view callerPFN);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> AddWebAccountAsync(hstring_view webAccountId, hstring_view webAccountUserName, map_view<hstring, hstring> props, Windows::Security::Authentication::Web::Provider::WebAccountScope scope, hstring_view perUserWebAccountId);
    static Windows::Foundation::IAsyncAction SetPerAppToPerUserAccountAsync(const Windows::Security::Credentials::WebAccount & perAppAccount, hstring_view perUserWebAccountId);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> GetPerUserFromPerAppAccountAsync(const Windows::Security::Credentials::WebAccount & perAppAccount);
    static Windows::Foundation::IAsyncAction ClearPerUserFromPerAppAccountAsync(const Windows::Security::Credentials::WebAccount & perAppAccount);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> AddWebAccountAsync(hstring_view webAccountId, hstring_view webAccountUserName, map_view<hstring, hstring> props, Windows::Security::Authentication::Web::Provider::WebAccountScope scope);
    static Windows::Foundation::IAsyncAction SetScopeAsync(const Windows::Security::Credentials::WebAccount & webAccount, Windows::Security::Authentication::Web::Provider::WebAccountScope scope);
    static Windows::Security::Authentication::Web::Provider::WebAccountScope GetScope(const Windows::Security::Credentials::WebAccount & webAccount);
};

struct WINRT_EBO WebAccountProviderAddAccountOperation :
    Windows::Security::Authentication::Web::Provider::IWebAccountProviderAddAccountOperation
{
    WebAccountProviderAddAccountOperation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebAccountProviderDeleteAccountOperation :
    Windows::Security::Authentication::Web::Provider::IWebAccountProviderDeleteAccountOperation,
    impl::require<WebAccountProviderDeleteAccountOperation, Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>
{
    WebAccountProviderDeleteAccountOperation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebAccountProviderGetTokenSilentOperation :
    Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation,
    impl::require<WebAccountProviderGetTokenSilentOperation, Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation, Windows::Security::Authentication::Web::Provider::IWebAccountProviderSilentReportOperation>
{
    WebAccountProviderGetTokenSilentOperation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebAccountProviderManageAccountOperation :
    Windows::Security::Authentication::Web::Provider::IWebAccountProviderManageAccountOperation
{
    WebAccountProviderManageAccountOperation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebAccountProviderRequestTokenOperation :
    Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation,
    impl::require<WebAccountProviderRequestTokenOperation, Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation, Windows::Security::Authentication::Web::Provider::IWebAccountProviderUIReportOperation>
{
    WebAccountProviderRequestTokenOperation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebAccountProviderRetrieveCookiesOperation :
    Windows::Security::Authentication::Web::Provider::IWebAccountProviderRetrieveCookiesOperation,
    impl::require<WebAccountProviderRetrieveCookiesOperation, Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>
{
    WebAccountProviderRetrieveCookiesOperation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebAccountProviderSignOutAccountOperation :
    Windows::Security::Authentication::Web::Provider::IWebAccountProviderSignOutAccountOperation,
    impl::require<WebAccountProviderSignOutAccountOperation, Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>
{
    WebAccountProviderSignOutAccountOperation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebAccountProviderTriggerDetails :
    Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenObjects
{
    WebAccountProviderTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebProviderTokenRequest :
    Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest,
    impl::require<WebProviderTokenRequest, Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest2>
{
    WebProviderTokenRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebProviderTokenResponse :
    Windows::Security::Authentication::Web::Provider::IWebProviderTokenResponse
{
    WebProviderTokenResponse(std::nullptr_t) noexcept {}
    WebProviderTokenResponse(const Windows::Security::Authentication::Web::Core::WebTokenResponse & webTokenResponse);
};

}

}
