// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::UserDataAccounts::Provider {

struct IUserDataAccountPartnerAccountInfo;
struct IUserDataAccountProviderAddAccountOperation;
struct IUserDataAccountProviderOperation;
struct IUserDataAccountProviderResolveErrorsOperation;
struct IUserDataAccountProviderSettingsOperation;
struct UserDataAccountPartnerAccountInfo;
struct UserDataAccountProviderAddAccountOperation;
struct UserDataAccountProviderResolveErrorsOperation;
struct UserDataAccountProviderSettingsOperation;

}

namespace Windows::ApplicationModel::UserDataAccounts::Provider {

struct IUserDataAccountPartnerAccountInfo;
struct IUserDataAccountProviderAddAccountOperation;
struct IUserDataAccountProviderOperation;
struct IUserDataAccountProviderResolveErrorsOperation;
struct IUserDataAccountProviderSettingsOperation;
struct UserDataAccountPartnerAccountInfo;
struct UserDataAccountProviderAddAccountOperation;
struct UserDataAccountProviderResolveErrorsOperation;
struct UserDataAccountProviderSettingsOperation;

}

namespace Windows::ApplicationModel::UserDataAccounts::Provider {

template <typename T> struct impl_IUserDataAccountPartnerAccountInfo;
template <typename T> struct impl_IUserDataAccountProviderAddAccountOperation;
template <typename T> struct impl_IUserDataAccountProviderOperation;
template <typename T> struct impl_IUserDataAccountProviderResolveErrorsOperation;
template <typename T> struct impl_IUserDataAccountProviderSettingsOperation;

}

namespace Windows::ApplicationModel::UserDataAccounts::Provider {

enum class UserDataAccountProviderOperationKind
{
    AddAccount = 0,
    Settings = 1,
    ResolveErrors = 2,
};

enum class UserDataAccountProviderPartnerAccountKind
{
    Exchange = 0,
    PopOrImap = 1,
};

}

}
