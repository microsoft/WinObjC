// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::UserDataAccounts {

struct IUserDataAccount;
struct IUserDataAccount2;
struct IUserDataAccount3;
struct IUserDataAccountManagerForUser;
struct IUserDataAccountManagerStatics;
struct IUserDataAccountManagerStatics2;
struct IUserDataAccountStore;
struct IUserDataAccountStore2;
struct IUserDataAccountStoreChangedEventArgs;
struct UserDataAccount;
struct UserDataAccountManagerForUser;
struct UserDataAccountStore;
struct UserDataAccountStoreChangedEventArgs;

}

namespace Windows::ApplicationModel::UserDataAccounts {

struct IUserDataAccount;
struct IUserDataAccount2;
struct IUserDataAccount3;
struct IUserDataAccountManagerForUser;
struct IUserDataAccountManagerStatics;
struct IUserDataAccountManagerStatics2;
struct IUserDataAccountStore;
struct IUserDataAccountStore2;
struct IUserDataAccountStoreChangedEventArgs;
struct UserDataAccount;
struct UserDataAccountManager;
struct UserDataAccountManagerForUser;
struct UserDataAccountStore;
struct UserDataAccountStoreChangedEventArgs;

}

namespace Windows::ApplicationModel::UserDataAccounts {

template <typename T> struct impl_IUserDataAccount;
template <typename T> struct impl_IUserDataAccount2;
template <typename T> struct impl_IUserDataAccount3;
template <typename T> struct impl_IUserDataAccountManagerForUser;
template <typename T> struct impl_IUserDataAccountManagerStatics;
template <typename T> struct impl_IUserDataAccountManagerStatics2;
template <typename T> struct impl_IUserDataAccountStore;
template <typename T> struct impl_IUserDataAccountStore2;
template <typename T> struct impl_IUserDataAccountStoreChangedEventArgs;

}

namespace Windows::ApplicationModel::UserDataAccounts {

enum class UserDataAccountContentKinds : unsigned
{
    Email = 0x1,
    Contact = 0x2,
    Appointment = 0x4,
};

DEFINE_ENUM_FLAG_OPERATORS(UserDataAccountContentKinds)

enum class UserDataAccountOtherAppReadAccess
{
    SystemOnly = 0,
    Full = 1,
    None = 2,
};

enum class UserDataAccountStoreAccessType
{
    AllAccountsReadOnly = 0,
    AppAccountsReadWrite = 1,
};

}

}
