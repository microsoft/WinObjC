// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.UserDataAccounts.Provider.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::UserDataAccounts::Provider {

struct WINRT_EBO UserDataAccountPartnerAccountInfo :
    Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo
{
    UserDataAccountPartnerAccountInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UserDataAccountProviderAddAccountOperation :
    Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation
{
    UserDataAccountProviderAddAccountOperation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UserDataAccountProviderResolveErrorsOperation :
    Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation
{
    UserDataAccountProviderResolveErrorsOperation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UserDataAccountProviderSettingsOperation :
    Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation
{
    UserDataAccountProviderSettingsOperation(std::nullptr_t) noexcept {}
};

}

}
