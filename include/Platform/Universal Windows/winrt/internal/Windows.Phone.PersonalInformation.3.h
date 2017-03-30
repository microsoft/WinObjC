// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.PersonalInformation.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Phone::PersonalInformation {

struct WINRT_EBO ContactAddress :
    Windows::Phone::PersonalInformation::IContactAddress
{
    ContactAddress(std::nullptr_t) noexcept {}
    ContactAddress();
};

struct WINRT_EBO ContactChangeRecord :
    Windows::Phone::PersonalInformation::IContactChangeRecord
{
    ContactChangeRecord(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactInformation :
    Windows::Phone::PersonalInformation::IContactInformation
{
    ContactInformation(std::nullptr_t) noexcept {}
    ContactInformation();
    static Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactInformation> ParseVcardAsync(const Windows::Storage::Streams::IInputStream & vcard);
};

struct WINRT_EBO ContactQueryOptions :
    Windows::Phone::PersonalInformation::IContactQueryOptions
{
    ContactQueryOptions(std::nullptr_t) noexcept {}
    ContactQueryOptions();
};

struct WINRT_EBO ContactQueryResult :
    Windows::Phone::PersonalInformation::IContactQueryResult
{
    ContactQueryResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactStore :
    Windows::Phone::PersonalInformation::IContactStore,
    impl::require<ContactStore, Windows::Phone::PersonalInformation::IContactStore2>
{
    ContactStore(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactStore> CreateOrOpenAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactStore> CreateOrOpenAsync(Windows::Phone::PersonalInformation::ContactStoreSystemAccessMode access, Windows::Phone::PersonalInformation::ContactStoreApplicationAccessMode sharing);
};

struct KnownContactProperties
{
    KnownContactProperties() = delete;
    static hstring DisplayName();
    static hstring FamilyName();
    static hstring GivenName();
    static hstring HonorificPrefix();
    static hstring HonorificSuffix();
    static hstring AdditionalName();
    static hstring Address();
    static hstring OtherAddress();
    static hstring Email();
    static hstring WorkAddress();
    static hstring WorkTelephone();
    static hstring JobTitle();
    static hstring Birthdate();
    static hstring Anniversary();
    static hstring Telephone();
    static hstring MobileTelephone();
    static hstring Url();
    static hstring Notes();
    static hstring WorkFax();
    static hstring Children();
    static hstring SignificantOther();
    static hstring CompanyName();
    static hstring CompanyTelephone();
    static hstring HomeFax();
    static hstring AlternateTelephone();
    static hstring Manager();
    static hstring Nickname();
    static hstring OfficeLocation();
    static hstring WorkEmail();
    static hstring YomiGivenName();
    static hstring YomiFamilyName();
    static hstring YomiCompanyName();
    static hstring OtherEmail();
    static hstring AlternateMobileTelephone();
    static hstring AlternateWorkTelephone();
};

struct WINRT_EBO StoredContact :
    Windows::Phone::PersonalInformation::IStoredContact,
    impl::require<StoredContact, Windows::Phone::PersonalInformation::IContactInformation2>
{
    StoredContact(std::nullptr_t) noexcept {}
    StoredContact(const Windows::Phone::PersonalInformation::ContactStore & store);
    StoredContact(const Windows::Phone::PersonalInformation::ContactStore & store, const Windows::Phone::PersonalInformation::ContactInformation & contact);
};

}

}
