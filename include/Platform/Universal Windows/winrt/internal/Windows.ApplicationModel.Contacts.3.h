// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Contacts.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Contacts {

struct WINRT_EBO AggregateContactManager :
    Windows::ApplicationModel::Contacts::IAggregateContactManager,
    impl::require<AggregateContactManager, Windows::ApplicationModel::Contacts::IAggregateContactManager2>
{
    AggregateContactManager(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Contact :
    Windows::ApplicationModel::Contacts::IContact,
    impl::require<Contact, Windows::ApplicationModel::Contacts::IContactName, Windows::ApplicationModel::Contacts::IContact2, Windows::ApplicationModel::Contacts::IContact3>
{
    Contact(std::nullptr_t) noexcept {}
    Contact();
};

struct WINRT_EBO ContactAddress :
    Windows::ApplicationModel::Contacts::IContactAddress
{
    ContactAddress(std::nullptr_t) noexcept {}
    ContactAddress();
};

struct WINRT_EBO ContactAnnotation :
    Windows::ApplicationModel::Contacts::IContactAnnotation
{
    ContactAnnotation(std::nullptr_t) noexcept {}
    ContactAnnotation();
};

struct WINRT_EBO ContactAnnotationList :
    Windows::ApplicationModel::Contacts::IContactAnnotationList
{
    ContactAnnotationList(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactAnnotationStore :
    Windows::ApplicationModel::Contacts::IContactAnnotationStore
{
    ContactAnnotationStore(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactBatch :
    Windows::ApplicationModel::Contacts::IContactBatch
{
    ContactBatch(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactCardDelayedDataLoader :
    Windows::ApplicationModel::Contacts::IContactCardDelayedDataLoader
{
    ContactCardDelayedDataLoader(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactCardOptions :
    Windows::ApplicationModel::Contacts::IContactCardOptions,
    impl::require<ContactCardOptions, Windows::ApplicationModel::Contacts::IContactCardOptions2>
{
    ContactCardOptions(std::nullptr_t) noexcept {}
    ContactCardOptions();
};

struct WINRT_EBO ContactChange :
    Windows::ApplicationModel::Contacts::IContactChange
{
    ContactChange(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactChangeReader :
    Windows::ApplicationModel::Contacts::IContactChangeReader
{
    ContactChangeReader(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactChangeTracker :
    Windows::ApplicationModel::Contacts::IContactChangeTracker
{
    ContactChangeTracker(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactChangedDeferral :
    Windows::ApplicationModel::Contacts::IContactChangedDeferral
{
    ContactChangedDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactChangedEventArgs :
    Windows::ApplicationModel::Contacts::IContactChangedEventArgs
{
    ContactChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactConnectedServiceAccount :
    Windows::ApplicationModel::Contacts::IContactConnectedServiceAccount
{
    ContactConnectedServiceAccount(std::nullptr_t) noexcept {}
    ContactConnectedServiceAccount();
};

struct WINRT_EBO ContactDate :
    Windows::ApplicationModel::Contacts::IContactDate
{
    ContactDate(std::nullptr_t) noexcept {}
    ContactDate();
};

struct WINRT_EBO ContactEmail :
    Windows::ApplicationModel::Contacts::IContactEmail
{
    ContactEmail(std::nullptr_t) noexcept {}
    ContactEmail();
};

struct WINRT_EBO ContactField :
    Windows::ApplicationModel::Contacts::IContactField
{
    ContactField(std::nullptr_t) noexcept {}
    ContactField(hstring_view value, Windows::ApplicationModel::Contacts::ContactFieldType type);
    ContactField(hstring_view value, Windows::ApplicationModel::Contacts::ContactFieldType type, Windows::ApplicationModel::Contacts::ContactFieldCategory category);
    ContactField(hstring_view name, hstring_view value, Windows::ApplicationModel::Contacts::ContactFieldType type, Windows::ApplicationModel::Contacts::ContactFieldCategory category);
};

struct WINRT_EBO ContactFieldFactory :
    Windows::ApplicationModel::Contacts::IContactFieldFactory,
    impl::require<ContactFieldFactory, Windows::ApplicationModel::Contacts::IContactLocationFieldFactory, Windows::ApplicationModel::Contacts::IContactInstantMessageFieldFactory>
{
    ContactFieldFactory(std::nullptr_t) noexcept {}
    ContactFieldFactory();
};

struct WINRT_EBO ContactInformation :
    Windows::ApplicationModel::Contacts::IContactInformation
{
    ContactInformation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactInstantMessageField :
    Windows::ApplicationModel::Contacts::IContactInstantMessageField
{
    ContactInstantMessageField(std::nullptr_t) noexcept {}
    ContactInstantMessageField(hstring_view userName);
    ContactInstantMessageField(hstring_view userName, Windows::ApplicationModel::Contacts::ContactFieldCategory category);
    ContactInstantMessageField(hstring_view userName, Windows::ApplicationModel::Contacts::ContactFieldCategory category, hstring_view service, hstring_view displayText, const Windows::Foundation::Uri & verb);
};

struct WINRT_EBO ContactJobInfo :
    Windows::ApplicationModel::Contacts::IContactJobInfo
{
    ContactJobInfo(std::nullptr_t) noexcept {}
    ContactJobInfo();
};

struct ContactLaunchActionVerbs
{
    ContactLaunchActionVerbs() = delete;
    static hstring Call();
    static hstring Message();
    static hstring Map();
    static hstring Post();
    static hstring VideoCall();
};

struct WINRT_EBO ContactList :
    Windows::ApplicationModel::Contacts::IContactList,
    impl::require<ContactList, Windows::ApplicationModel::Contacts::IContactList2>
{
    ContactList(std::nullptr_t) noexcept {}
    using impl_IContactList::SupportsServerSearch;
    using impl_IContactList2::SupportsServerSearch;
};

struct WINRT_EBO ContactListSyncConstraints :
    Windows::ApplicationModel::Contacts::IContactListSyncConstraints
{
    ContactListSyncConstraints(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactListSyncManager :
    Windows::ApplicationModel::Contacts::IContactListSyncManager,
    impl::require<ContactListSyncManager, Windows::ApplicationModel::Contacts::IContactListSyncManager2>
{
    ContactListSyncManager(std::nullptr_t) noexcept {}
    using impl_IContactListSyncManager::LastAttemptedSyncTime;
    using impl_IContactListSyncManager::LastSuccessfulSyncTime;
    using impl_IContactListSyncManager::Status;
    using impl_IContactListSyncManager2::LastAttemptedSyncTime;
    using impl_IContactListSyncManager2::LastSuccessfulSyncTime;
    using impl_IContactListSyncManager2::Status;
};

struct WINRT_EBO ContactLocationField :
    Windows::ApplicationModel::Contacts::IContactLocationField
{
    ContactLocationField(std::nullptr_t) noexcept {}
    ContactLocationField(hstring_view unstructuredAddress);
    ContactLocationField(hstring_view unstructuredAddress, Windows::ApplicationModel::Contacts::ContactFieldCategory category);
    ContactLocationField(hstring_view unstructuredAddress, Windows::ApplicationModel::Contacts::ContactFieldCategory category, hstring_view street, hstring_view city, hstring_view region, hstring_view country, hstring_view postalCode);
};

struct ContactManager
{
    ContactManager() = delete;
    static void ShowContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection);
    static void ShowContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement);
    static Windows::ApplicationModel::Contacts::ContactCardDelayedDataLoader ShowDelayLoadedContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement);
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore> RequestStoreAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> ConvertContactToVCardAsync(const Windows::ApplicationModel::Contacts::Contact & contact);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> ConvertContactToVCardAsync(const Windows::ApplicationModel::Contacts::Contact & contact, uint32_t maxBytes);
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> ConvertVCardToContactAsync(const Windows::Storage::Streams::IRandomAccessStreamReference & vCard);
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore> RequestStoreAsync(Windows::ApplicationModel::Contacts::ContactStoreAccessType accessType);
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationStore> RequestAnnotationStoreAsync(Windows::ApplicationModel::Contacts::ContactAnnotationStoreAccessType accessType);
    static bool IsShowContactCardSupported();
    static void ShowContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::ApplicationModel::Contacts::ContactCardOptions & contactCardOptions);
    static bool IsShowDelayLoadedContactCardSupported();
    static Windows::ApplicationModel::Contacts::ContactCardDelayedDataLoader ShowDelayLoadedContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::ApplicationModel::Contacts::ContactCardOptions & contactCardOptions);
    static void ShowFullContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::ApplicationModel::Contacts::FullContactCardOptions & fullContactCardOptions);
    static Windows::ApplicationModel::Contacts::ContactNameOrder SystemDisplayNameOrder();
    static void SystemDisplayNameOrder(Windows::ApplicationModel::Contacts::ContactNameOrder value);
    static Windows::ApplicationModel::Contacts::ContactNameOrder SystemSortOrder();
    static void SystemSortOrder(Windows::ApplicationModel::Contacts::ContactNameOrder value);
    static Windows::ApplicationModel::Contacts::ContactManagerForUser GetForUser(const Windows::System::User & user);
};

struct WINRT_EBO ContactManagerForUser :
    Windows::ApplicationModel::Contacts::IContactManagerForUser
{
    ContactManagerForUser(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactMatchReason :
    Windows::ApplicationModel::Contacts::IContactMatchReason
{
    ContactMatchReason(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactPhone :
    Windows::ApplicationModel::Contacts::IContactPhone
{
    ContactPhone(std::nullptr_t) noexcept {}
    ContactPhone();
};

struct WINRT_EBO ContactPicker :
    Windows::ApplicationModel::Contacts::IContactPicker,
    impl::require<ContactPicker, Windows::ApplicationModel::Contacts::IContactPicker2>
{
    ContactPicker(std::nullptr_t) noexcept {}
    ContactPicker();
};

struct WINRT_EBO ContactQueryOptions :
    Windows::ApplicationModel::Contacts::IContactQueryOptions
{
    ContactQueryOptions(std::nullptr_t) noexcept {}
    ContactQueryOptions();
    ContactQueryOptions(hstring_view text);
    ContactQueryOptions(hstring_view text, Windows::ApplicationModel::Contacts::ContactQuerySearchFields fields);
};

struct WINRT_EBO ContactQueryTextSearch :
    Windows::ApplicationModel::Contacts::IContactQueryTextSearch
{
    ContactQueryTextSearch(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactReader :
    Windows::ApplicationModel::Contacts::IContactReader
{
    ContactReader(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactSignificantOther :
    Windows::ApplicationModel::Contacts::IContactSignificantOther,
    impl::require<ContactSignificantOther, Windows::ApplicationModel::Contacts::IContactSignificantOther2>
{
    ContactSignificantOther(std::nullptr_t) noexcept {}
    ContactSignificantOther();
};

struct WINRT_EBO ContactStore :
    Windows::ApplicationModel::Contacts::IContactStore,
    impl::require<ContactStore, Windows::ApplicationModel::Contacts::IContactStore2>
{
    ContactStore(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactStoreNotificationTriggerDetails :
    Windows::ApplicationModel::Contacts::IContactStoreNotificationTriggerDetails
{
    ContactStoreNotificationTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactWebsite :
    Windows::ApplicationModel::Contacts::IContactWebsite,
    impl::require<ContactWebsite, Windows::ApplicationModel::Contacts::IContactWebsite2>
{
    ContactWebsite(std::nullptr_t) noexcept {}
    ContactWebsite();
};

struct WINRT_EBO FullContactCardOptions :
    Windows::ApplicationModel::Contacts::IFullContactCardOptions
{
    FullContactCardOptions(std::nullptr_t) noexcept {}
    FullContactCardOptions();
};

struct [[deprecated("KnownContactField  may be altered or unavailable for releases after Windows 8.1. Instead, use ContactAddress, ContactPhone, ContactConnectedServiceAccount or ContactEmail.")]] KnownContactField
{
    KnownContactField() = delete;
    [[deprecated("IKnownContactFieldStatics may be altered or unavailable for releases after Windows 8.1. Instead, use ContactAddress, ContactPhone, ContactConnectedServiceAccount or ContactEmail.")]] static hstring Email();
    [[deprecated("IKnownContactFieldStatics may be altered or unavailable for releases after Windows 8.1. Instead, use ContactAddress, ContactPhone, ContactConnectedServiceAccount or ContactEmail.")]] static hstring PhoneNumber();
    [[deprecated("IKnownContactFieldStatics may be altered or unavailable for releases after Windows 8.1. Instead, use ContactAddress, ContactPhone, ContactConnectedServiceAccount or ContactEmail.")]] static hstring Location();
    [[deprecated("IKnownContactFieldStatics may be altered or unavailable for releases after Windows 8.1. Instead, use ContactAddress, ContactPhone, ContactConnectedServiceAccount or ContactEmail.")]] static hstring InstantMessage();
    [[deprecated("IKnownContactFieldStatics may be altered or unavailable for releases after Windows 8.1. Instead, use ContactAddress, ContactPhone, ContactConnectedServiceAccount or ContactEmail.")]] static Windows::ApplicationModel::Contacts::ContactFieldType ConvertNameToType(hstring_view name);
    [[deprecated("IKnownContactFieldStatics may be altered or unavailable for releases after Windows 8.1. Instead, use ContactAddress, ContactPhone, ContactConnectedServiceAccount or ContactEmail.")]] static hstring ConvertTypeToName(Windows::ApplicationModel::Contacts::ContactFieldType type);
};

}

}
