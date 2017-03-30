// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.UserDataAccounts.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::UserDataAccounts {

struct WINRT_EBO UserDataAccount :
    Windows::ApplicationModel::UserDataAccounts::IUserDataAccount,
    impl::require<UserDataAccount, Windows::ApplicationModel::UserDataAccounts::IUserDataAccount2, Windows::ApplicationModel::UserDataAccounts::IUserDataAccount3>
{
    UserDataAccount(std::nullptr_t) noexcept {}
};

struct UserDataAccountManager
{
    UserDataAccountManager() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::UserDataAccountStore> RequestStoreAsync(Windows::ApplicationModel::UserDataAccounts::UserDataAccountStoreAccessType storeAccessType);
    static Windows::Foundation::IAsyncOperation<hstring> ShowAddAccountAsync(Windows::ApplicationModel::UserDataAccounts::UserDataAccountContentKinds contentKinds);
    static Windows::Foundation::IAsyncAction ShowAccountSettingsAsync(hstring_view id);
    static Windows::Foundation::IAsyncAction ShowAccountErrorResolverAsync(hstring_view id);
    static Windows::ApplicationModel::UserDataAccounts::UserDataAccountManagerForUser GetForUser(const Windows::System::User & user);
};

struct WINRT_EBO UserDataAccountManagerForUser :
    Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerForUser
{
    UserDataAccountManagerForUser(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UserDataAccountStore :
    Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore,
    impl::require<UserDataAccountStore, Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore2>
{
    UserDataAccountStore(std::nullptr_t) noexcept {}
    using impl_IUserDataAccountStore::CreateAccountAsync;
    using impl_IUserDataAccountStore2::CreateAccountAsync;
};

struct WINRT_EBO UserDataAccountStoreChangedEventArgs :
    Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStoreChangedEventArgs
{
    UserDataAccountStoreChangedEventArgs(std::nullptr_t) noexcept {}
};

}

}
