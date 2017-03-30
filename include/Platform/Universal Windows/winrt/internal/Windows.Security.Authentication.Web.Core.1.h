// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Security.Authentication.Web.Core.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Security.Credentials.0.h"
#include "Windows.System.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Security.Credentials.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::Authentication::Web::Core {

struct __declspec(uuid("6fb7037d-424e-44ec-977c-ef2415462a5a")) __declspec(novtable) IWebAccountEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Account(Windows::Security::Credentials::IWebAccount ** value) = 0;
};

struct __declspec(uuid("7445f5fd-aa9d-4619-8d5d-c138a4ede3e5")) __declspec(novtable) IWebAccountMonitor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_Updated(Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Security::Authentication::Web::Core::WebAccountEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Updated(event_token token) = 0;
    virtual HRESULT __stdcall add_Removed(Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Security::Authentication::Web::Core::WebAccountEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Removed(event_token token) = 0;
    virtual HRESULT __stdcall add_DefaultSignInAccountChanged(Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DefaultSignInAccountChanged(event_token token) = 0;
};

struct __declspec(uuid("6aca7c92-a581-4479-9c10-752eff44fd34")) __declspec(novtable) IWebAuthenticationCoreManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetTokenSilentlyAsync(Windows::Security::Authentication::Web::Core::IWebTokenRequest * request, Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_GetTokenSilentlyWithWebAccountAsync(Windows::Security::Authentication::Web::Core::IWebTokenRequest * request, Windows::Security::Credentials::IWebAccount * webAccount, Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_RequestTokenAsync(Windows::Security::Authentication::Web::Core::IWebTokenRequest * request, Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_RequestTokenWithWebAccountAsync(Windows::Security::Authentication::Web::Core::IWebTokenRequest * request, Windows::Security::Credentials::IWebAccount * webAccount, Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_FindAccountAsync(Windows::Security::Credentials::IWebAccountProvider * provider, hstring webAccountId, Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_FindAccountProviderAsync(hstring webAccountProviderId, Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_FindAccountProviderWithAuthorityAsync(hstring webAccountProviderId, hstring authority, Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> ** asyncInfo) = 0;
};

struct __declspec(uuid("f584184a-8b57-4820-b6a4-70a5b6fcf44a")) __declspec(novtable) IWebAuthenticationCoreManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindAccountProviderWithAuthorityForUserAsync(hstring webAccountProviderId, hstring authority, Windows::System::IUser * user, Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> ** asyncInfo) = 0;
};

struct __declspec(uuid("2404eeb2-8924-4d93-ab3a-99688b419d56")) __declspec(novtable) IWebAuthenticationCoreManagerStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWebAccountMonitor(Windows::Foundation::Collections::IIterable<Windows::Security::Credentials::WebAccount> * webAccounts, Windows::Security::Authentication::Web::Core::IWebAccountMonitor ** result) = 0;
};

struct __declspec(uuid("db191bb1-50c5-4809-8dca-09c99410245c")) __declspec(novtable) IWebProviderError : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ErrorCode(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_ErrorMessage(hstring * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMap<hstring, hstring> ** value) = 0;
};

struct __declspec(uuid("e3c40a2d-89ef-4e37-847f-a8b9d5a32910")) __declspec(novtable) IWebProviderErrorFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(uint32_t errorCode, hstring errorMessage, Windows::Security::Authentication::Web::Core::IWebProviderError ** webProviderError) = 0;
};

struct __declspec(uuid("b77b4d68-adcb-4673-b364-0cf7b35caf97")) __declspec(novtable) IWebTokenRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_WebAccountProvider(Windows::Security::Credentials::IWebAccountProvider ** value) = 0;
    virtual HRESULT __stdcall get_Scope(hstring * value) = 0;
    virtual HRESULT __stdcall get_ClientId(hstring * value) = 0;
    virtual HRESULT __stdcall get_PromptType(winrt::Windows::Security::Authentication::Web::Core::WebTokenRequestPromptType * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMap<hstring, hstring> ** requestProperties) = 0;
};

struct __declspec(uuid("d700c079-30c8-4397-9654-961c3be8b855")) __declspec(novtable) IWebTokenRequest2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppProperties(Windows::Foundation::Collections::IMap<hstring, hstring> ** requestProperties) = 0;
};

struct __declspec(uuid("6cf2141c-0ff0-4c67-b84f-99ddbe4a72c9")) __declspec(novtable) IWebTokenRequestFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Security::Credentials::IWebAccountProvider * provider, hstring scope, hstring clientId, Windows::Security::Authentication::Web::Core::IWebTokenRequest ** webTokenRequest) = 0;
    virtual HRESULT __stdcall abi_CreateWithPromptType(Windows::Security::Credentials::IWebAccountProvider * provider, hstring scope, hstring clientId, winrt::Windows::Security::Authentication::Web::Core::WebTokenRequestPromptType promptType, Windows::Security::Authentication::Web::Core::IWebTokenRequest ** webTokenRequest) = 0;
    virtual HRESULT __stdcall abi_CreateWithProvider(Windows::Security::Credentials::IWebAccountProvider * provider, Windows::Security::Authentication::Web::Core::IWebTokenRequest ** webTokenRequest) = 0;
    virtual HRESULT __stdcall abi_CreateWithScope(Windows::Security::Credentials::IWebAccountProvider * provider, hstring scope, Windows::Security::Authentication::Web::Core::IWebTokenRequest ** webTokenRequest) = 0;
};

struct __declspec(uuid("c12a8305-d1f8-4483-8d54-38fe292784ff")) __declspec(novtable) IWebTokenRequestResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ResponseData(Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Web::Core::WebTokenResponse> ** value) = 0;
    virtual HRESULT __stdcall get_ResponseStatus(winrt::Windows::Security::Authentication::Web::Core::WebTokenRequestStatus * value) = 0;
    virtual HRESULT __stdcall get_ResponseError(Windows::Security::Authentication::Web::Core::IWebProviderError ** value) = 0;
    virtual HRESULT __stdcall abi_InvalidateCacheAsync(Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
};

struct __declspec(uuid("67a7c5ca-83f6-44c6-a3b1-0eb69e41fa8a")) __declspec(novtable) IWebTokenResponse : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Token(hstring * value) = 0;
    virtual HRESULT __stdcall get_ProviderError(Windows::Security::Authentication::Web::Core::IWebProviderError ** value) = 0;
    virtual HRESULT __stdcall get_WebAccount(Windows::Security::Credentials::IWebAccount ** value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMap<hstring, hstring> ** value) = 0;
};

struct __declspec(uuid("ab6bf7f8-5450-4ef6-97f7-052b0431c0f0")) __declspec(novtable) IWebTokenResponseFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWithToken(hstring token, Windows::Security::Authentication::Web::Core::IWebTokenResponse ** webTokenResponse) = 0;
    virtual HRESULT __stdcall abi_CreateWithTokenAndAccount(hstring token, Windows::Security::Credentials::IWebAccount * webAccount, Windows::Security::Authentication::Web::Core::IWebTokenResponse ** webTokenResponse) = 0;
    virtual HRESULT __stdcall abi_CreateWithTokenAccountAndError(hstring token, Windows::Security::Credentials::IWebAccount * webAccount, Windows::Security::Authentication::Web::Core::IWebProviderError * error, Windows::Security::Authentication::Web::Core::IWebTokenResponse ** webTokenResponse) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Security::Authentication::Web::Core::WebAccountEventArgs> { using default_interface = Windows::Security::Authentication::Web::Core::IWebAccountEventArgs; };
template <> struct traits<Windows::Security::Authentication::Web::Core::WebAccountMonitor> { using default_interface = Windows::Security::Authentication::Web::Core::IWebAccountMonitor; };
template <> struct traits<Windows::Security::Authentication::Web::Core::WebProviderError> { using default_interface = Windows::Security::Authentication::Web::Core::IWebProviderError; };
template <> struct traits<Windows::Security::Authentication::Web::Core::WebTokenRequest> { using default_interface = Windows::Security::Authentication::Web::Core::IWebTokenRequest; };
template <> struct traits<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> { using default_interface = Windows::Security::Authentication::Web::Core::IWebTokenRequestResult; };
template <> struct traits<Windows::Security::Authentication::Web::Core::WebTokenResponse> { using default_interface = Windows::Security::Authentication::Web::Core::IWebTokenResponse; };

}

namespace Windows::Security::Authentication::Web::Core {

template <typename D>
struct WINRT_EBO impl_IWebAccountEventArgs
{
    Windows::Security::Credentials::WebAccount Account() const;
};

template <typename D>
struct WINRT_EBO impl_IWebAccountMonitor
{
    event_token Updated(const Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Security::Authentication::Web::Core::WebAccountEventArgs> & handler) const;
    using Updated_revoker = event_revoker<IWebAccountMonitor>;
    Updated_revoker Updated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Security::Authentication::Web::Core::WebAccountEventArgs> & handler) const;
    void Updated(event_token token) const;
    event_token Removed(const Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Security::Authentication::Web::Core::WebAccountEventArgs> & handler) const;
    using Removed_revoker = event_revoker<IWebAccountMonitor>;
    Removed_revoker Removed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Security::Authentication::Web::Core::WebAccountEventArgs> & handler) const;
    void Removed(event_token token) const;
    event_token DefaultSignInAccountChanged(const Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Foundation::IInspectable> & handler) const;
    using DefaultSignInAccountChanged_revoker = event_revoker<IWebAccountMonitor>;
    DefaultSignInAccountChanged_revoker DefaultSignInAccountChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Foundation::IInspectable> & handler) const;
    void DefaultSignInAccountChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IWebAuthenticationCoreManagerStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> GetTokenSilentlyAsync(const Windows::Security::Authentication::Web::Core::WebTokenRequest & request) const;
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> GetTokenSilentlyAsync(const Windows::Security::Authentication::Web::Core::WebTokenRequest & request, const Windows::Security::Credentials::WebAccount & webAccount) const;
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> RequestTokenAsync(const Windows::Security::Authentication::Web::Core::WebTokenRequest & request) const;
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> RequestTokenAsync(const Windows::Security::Authentication::Web::Core::WebTokenRequest & request, const Windows::Security::Credentials::WebAccount & webAccount) const;
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> FindAccountAsync(const Windows::Security::Credentials::WebAccountProvider & provider, hstring_view webAccountId) const;
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> FindAccountProviderAsync(hstring_view webAccountProviderId) const;
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> FindAccountProviderAsync(hstring_view webAccountProviderId, hstring_view authority) const;
};

template <typename D>
struct WINRT_EBO impl_IWebAuthenticationCoreManagerStatics2
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> FindAccountProviderAsync(hstring_view webAccountProviderId, hstring_view authority, const Windows::System::User & user) const;
};

template <typename D>
struct WINRT_EBO impl_IWebAuthenticationCoreManagerStatics3
{
    Windows::Security::Authentication::Web::Core::WebAccountMonitor CreateWebAccountMonitor(iterable<Windows::Security::Credentials::WebAccount> webAccounts) const;
};

template <typename D>
struct WINRT_EBO impl_IWebProviderError
{
    uint32_t ErrorCode() const;
    hstring ErrorMessage() const;
    Windows::Foundation::Collections::IMap<hstring, hstring> Properties() const;
};

template <typename D>
struct WINRT_EBO impl_IWebProviderErrorFactory
{
    Windows::Security::Authentication::Web::Core::WebProviderError Create(uint32_t errorCode, hstring_view errorMessage) const;
};

template <typename D>
struct WINRT_EBO impl_IWebTokenRequest
{
    Windows::Security::Credentials::WebAccountProvider WebAccountProvider() const;
    hstring Scope() const;
    hstring ClientId() const;
    Windows::Security::Authentication::Web::Core::WebTokenRequestPromptType PromptType() const;
    Windows::Foundation::Collections::IMap<hstring, hstring> Properties() const;
};

template <typename D>
struct WINRT_EBO impl_IWebTokenRequest2
{
    Windows::Foundation::Collections::IMap<hstring, hstring> AppProperties() const;
};

template <typename D>
struct WINRT_EBO impl_IWebTokenRequestFactory
{
    Windows::Security::Authentication::Web::Core::WebTokenRequest Create(const Windows::Security::Credentials::WebAccountProvider & provider, hstring_view scope, hstring_view clientId) const;
    Windows::Security::Authentication::Web::Core::WebTokenRequest CreateWithPromptType(const Windows::Security::Credentials::WebAccountProvider & provider, hstring_view scope, hstring_view clientId, Windows::Security::Authentication::Web::Core::WebTokenRequestPromptType promptType) const;
    Windows::Security::Authentication::Web::Core::WebTokenRequest CreateWithProvider(const Windows::Security::Credentials::WebAccountProvider & provider) const;
    Windows::Security::Authentication::Web::Core::WebTokenRequest CreateWithScope(const Windows::Security::Credentials::WebAccountProvider & provider, hstring_view scope) const;
};

template <typename D>
struct WINRT_EBO impl_IWebTokenRequestResult
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Web::Core::WebTokenResponse> ResponseData() const;
    Windows::Security::Authentication::Web::Core::WebTokenRequestStatus ResponseStatus() const;
    Windows::Security::Authentication::Web::Core::WebProviderError ResponseError() const;
    Windows::Foundation::IAsyncAction InvalidateCacheAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IWebTokenResponse
{
    hstring Token() const;
    Windows::Security::Authentication::Web::Core::WebProviderError ProviderError() const;
    Windows::Security::Credentials::WebAccount WebAccount() const;
    Windows::Foundation::Collections::IMap<hstring, hstring> Properties() const;
};

template <typename D>
struct WINRT_EBO impl_IWebTokenResponseFactory
{
    Windows::Security::Authentication::Web::Core::WebTokenResponse CreateWithToken(hstring_view token) const;
    Windows::Security::Authentication::Web::Core::WebTokenResponse CreateWithTokenAndAccount(hstring_view token, const Windows::Security::Credentials::WebAccount & webAccount) const;
    Windows::Security::Authentication::Web::Core::WebTokenResponse CreateWithTokenAccountAndError(hstring_view token, const Windows::Security::Credentials::WebAccount & webAccount, const Windows::Security::Authentication::Web::Core::WebProviderError & error) const;
};

}

namespace impl {

template <> struct traits<Windows::Security::Authentication::Web::Core::IWebAccountEventArgs>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::IWebAccountEventArgs;
    template <typename D> using consume = Windows::Security::Authentication::Web::Core::impl_IWebAccountEventArgs<D>;
};

template <> struct traits<Windows::Security::Authentication::Web::Core::IWebAccountMonitor>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::IWebAccountMonitor;
    template <typename D> using consume = Windows::Security::Authentication::Web::Core::impl_IWebAccountMonitor<D>;
};

template <> struct traits<Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics;
    template <typename D> using consume = Windows::Security::Authentication::Web::Core::impl_IWebAuthenticationCoreManagerStatics<D>;
};

template <> struct traits<Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics2>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics2;
    template <typename D> using consume = Windows::Security::Authentication::Web::Core::impl_IWebAuthenticationCoreManagerStatics2<D>;
};

template <> struct traits<Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics3>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics3;
    template <typename D> using consume = Windows::Security::Authentication::Web::Core::impl_IWebAuthenticationCoreManagerStatics3<D>;
};

template <> struct traits<Windows::Security::Authentication::Web::Core::IWebProviderError>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::IWebProviderError;
    template <typename D> using consume = Windows::Security::Authentication::Web::Core::impl_IWebProviderError<D>;
};

template <> struct traits<Windows::Security::Authentication::Web::Core::IWebProviderErrorFactory>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::IWebProviderErrorFactory;
    template <typename D> using consume = Windows::Security::Authentication::Web::Core::impl_IWebProviderErrorFactory<D>;
};

template <> struct traits<Windows::Security::Authentication::Web::Core::IWebTokenRequest>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest;
    template <typename D> using consume = Windows::Security::Authentication::Web::Core::impl_IWebTokenRequest<D>;
};

template <> struct traits<Windows::Security::Authentication::Web::Core::IWebTokenRequest2>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest2;
    template <typename D> using consume = Windows::Security::Authentication::Web::Core::impl_IWebTokenRequest2<D>;
};

template <> struct traits<Windows::Security::Authentication::Web::Core::IWebTokenRequestFactory>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequestFactory;
    template <typename D> using consume = Windows::Security::Authentication::Web::Core::impl_IWebTokenRequestFactory<D>;
};

template <> struct traits<Windows::Security::Authentication::Web::Core::IWebTokenRequestResult>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequestResult;
    template <typename D> using consume = Windows::Security::Authentication::Web::Core::impl_IWebTokenRequestResult<D>;
};

template <> struct traits<Windows::Security::Authentication::Web::Core::IWebTokenResponse>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::IWebTokenResponse;
    template <typename D> using consume = Windows::Security::Authentication::Web::Core::impl_IWebTokenResponse<D>;
};

template <> struct traits<Windows::Security::Authentication::Web::Core::IWebTokenResponseFactory>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::IWebTokenResponseFactory;
    template <typename D> using consume = Windows::Security::Authentication::Web::Core::impl_IWebTokenResponseFactory<D>;
};

template <> struct traits<Windows::Security::Authentication::Web::Core::WebAccountEventArgs>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::WebAccountEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Web.Core.WebAccountEventArgs"; }
};

template <> struct traits<Windows::Security::Authentication::Web::Core::WebAccountMonitor>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::WebAccountMonitor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Web.Core.WebAccountMonitor"; }
};

template <> struct traits<Windows::Security::Authentication::Web::Core::WebAuthenticationCoreManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Web.Core.WebAuthenticationCoreManager"; }
};

template <> struct traits<Windows::Security::Authentication::Web::Core::WebProviderError>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::WebProviderError;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Web.Core.WebProviderError"; }
};

template <> struct traits<Windows::Security::Authentication::Web::Core::WebTokenRequest>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::WebTokenRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Web.Core.WebTokenRequest"; }
};

template <> struct traits<Windows::Security::Authentication::Web::Core::WebTokenRequestResult>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::WebTokenRequestResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Web.Core.WebTokenRequestResult"; }
};

template <> struct traits<Windows::Security::Authentication::Web::Core::WebTokenResponse>
{
    using abi = ABI::Windows::Security::Authentication::Web::Core::WebTokenResponse;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Web.Core.WebTokenResponse"; }
};

}

}
