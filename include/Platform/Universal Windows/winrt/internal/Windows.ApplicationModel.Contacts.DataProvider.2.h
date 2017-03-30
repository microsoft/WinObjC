// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Contacts.DataProvider.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_bb9f410f_a739_5280_9bb7_b6a938c7a620
#define WINRT_GENERIC_bb9f410f_a739_5280_9bb7_b6a938c7a620
template <> struct __declspec(uuid("bb9f410f-a739-5280-9bb7-b6a938c7a620")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, Windows::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, Windows::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequestEventArgs> {};
#endif

#ifndef WINRT_GENERIC_baee1b2f_a5b6_5a03_ae59_fb18f3e025b7
#define WINRT_GENERIC_baee1b2f_a5b6_5a03_ae59_fb18f3e025b7
template <> struct __declspec(uuid("baee1b2f-a5b6-5a03-ae59-fb18f3e025b7")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, Windows::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, Windows::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequestEventArgs> {};
#endif


}

namespace Windows::ApplicationModel::Contacts::DataProvider {

struct IContactDataProviderConnection :
    Windows::Foundation::IInspectable,
    impl::consume<IContactDataProviderConnection>
{
    IContactDataProviderConnection(std::nullptr_t = nullptr) noexcept {}
};

struct IContactDataProviderTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IContactDataProviderTriggerDetails>
{
    IContactDataProviderTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IContactListServerSearchReadBatchRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IContactListServerSearchReadBatchRequest>
{
    IContactListServerSearchReadBatchRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IContactListServerSearchReadBatchRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IContactListServerSearchReadBatchRequestEventArgs>
{
    IContactListServerSearchReadBatchRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IContactListSyncManagerSyncRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IContactListSyncManagerSyncRequest>
{
    IContactListSyncManagerSyncRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IContactListSyncManagerSyncRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IContactListSyncManagerSyncRequestEventArgs>
{
    IContactListSyncManagerSyncRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

}

}
