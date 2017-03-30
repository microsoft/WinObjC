// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Contacts.DataProvider.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Contacts::DataProvider {

struct WINRT_EBO ContactDataProviderConnection :
    Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection
{
    ContactDataProviderConnection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactDataProviderTriggerDetails :
    Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderTriggerDetails
{
    ContactDataProviderTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactListServerSearchReadBatchRequest :
    Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest
{
    ContactListServerSearchReadBatchRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactListServerSearchReadBatchRequestEventArgs :
    Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequestEventArgs
{
    ContactListServerSearchReadBatchRequestEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactListSyncManagerSyncRequest :
    Windows::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest
{
    ContactListSyncManagerSyncRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactListSyncManagerSyncRequestEventArgs :
    Windows::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequestEventArgs
{
    ContactListSyncManagerSyncRequestEventArgs(std::nullptr_t) noexcept {}
};

}

}
