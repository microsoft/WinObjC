// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Credentials.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Security::Credentials {

struct WINRT_EBO KeyCredential :
    Windows::Security::Credentials::IKeyCredential
{
    KeyCredential(std::nullptr_t) noexcept {}
};

struct WINRT_EBO KeyCredentialAttestationResult :
    Windows::Security::Credentials::IKeyCredentialAttestationResult
{
    KeyCredentialAttestationResult(std::nullptr_t) noexcept {}
};

struct KeyCredentialManager
{
    KeyCredentialManager() = delete;
    static Windows::Foundation::IAsyncOperation<bool> IsSupportedAsync();
    static Windows::Foundation::IAsyncAction RenewAttestationAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialRetrievalResult> RequestCreateAsync(hstring_view name, Windows::Security::Credentials::KeyCredentialCreationOption option);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialRetrievalResult> OpenAsync(hstring_view name);
    static Windows::Foundation::IAsyncAction DeleteAsync(hstring_view name);
};

struct WINRT_EBO KeyCredentialOperationResult :
    Windows::Security::Credentials::IKeyCredentialOperationResult
{
    KeyCredentialOperationResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO KeyCredentialRetrievalResult :
    Windows::Security::Credentials::IKeyCredentialRetrievalResult
{
    KeyCredentialRetrievalResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PasswordCredential :
    Windows::Security::Credentials::IPasswordCredential
{
    PasswordCredential(std::nullptr_t) noexcept {}
    PasswordCredential();
    PasswordCredential(hstring_view resource, hstring_view userName, hstring_view password);
};

struct WINRT_EBO PasswordCredentialPropertyStore :
    Windows::Foundation::Collections::IPropertySet
{
    PasswordCredentialPropertyStore(std::nullptr_t) noexcept {}
    PasswordCredentialPropertyStore();
};

struct WINRT_EBO PasswordVault :
    Windows::Security::Credentials::IPasswordVault
{
    PasswordVault(std::nullptr_t) noexcept {}
    PasswordVault();
};

struct WINRT_EBO WebAccount :
    Windows::Security::Credentials::IWebAccount,
    impl::require<WebAccount, Windows::Security::Credentials::IWebAccount2>
{
    WebAccount(std::nullptr_t) noexcept {}
    WebAccount(const Windows::Security::Credentials::WebAccountProvider & webAccountProvider, hstring_view userName, Windows::Security::Credentials::WebAccountState state);
};

struct WINRT_EBO WebAccountProvider :
    Windows::Security::Credentials::IWebAccountProvider,
    impl::require<WebAccountProvider, Windows::Security::Credentials::IWebAccountProvider2, Windows::Security::Credentials::IWebAccountProvider3>
{
    WebAccountProvider(std::nullptr_t) noexcept {}
    WebAccountProvider(hstring_view id, hstring_view displayName, const Windows::Foundation::Uri & iconUri);
};

}

}
