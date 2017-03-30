// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Phone::PersonalInformation {

struct IContactAddress;
struct IContactChangeRecord;
struct IContactInformation;
struct IContactInformation2;
struct IContactInformationStatics;
struct IContactQueryOptions;
struct IContactQueryResult;
struct IContactStore;
struct IContactStore2;
struct IContactStoreStatics;
struct IKnownContactPropertiesStatics;
struct IStoredContact;
struct IStoredContactFactory;
struct ContactAddress;
struct ContactChangeRecord;
struct ContactInformation;
struct ContactQueryOptions;
struct ContactQueryResult;
struct ContactStore;
struct StoredContact;

}

namespace Windows::Phone::PersonalInformation {

struct IContactAddress;
struct IContactChangeRecord;
struct IContactInformation;
struct IContactInformation2;
struct IContactInformationStatics;
struct IContactQueryOptions;
struct IContactQueryResult;
struct IContactStore;
struct IContactStore2;
struct IContactStoreStatics;
struct IKnownContactPropertiesStatics;
struct IStoredContact;
struct IStoredContactFactory;
struct ContactAddress;
struct ContactChangeRecord;
struct ContactInformation;
struct ContactQueryOptions;
struct ContactQueryResult;
struct ContactStore;
struct KnownContactProperties;
struct StoredContact;

}

namespace Windows::Phone::PersonalInformation {

template <typename T> struct impl_IContactAddress;
template <typename T> struct impl_IContactChangeRecord;
template <typename T> struct impl_IContactInformation;
template <typename T> struct impl_IContactInformation2;
template <typename T> struct impl_IContactInformationStatics;
template <typename T> struct impl_IContactQueryOptions;
template <typename T> struct impl_IContactQueryResult;
template <typename T> struct impl_IContactStore;
template <typename T> struct impl_IContactStore2;
template <typename T> struct impl_IContactStoreStatics;
template <typename T> struct impl_IKnownContactPropertiesStatics;
template <typename T> struct impl_IStoredContact;
template <typename T> struct impl_IStoredContactFactory;

}

namespace Windows::Phone::PersonalInformation {

enum class ContactChangeType
{
    Created = 0,
    Modified = 1,
    Deleted = 2,
};

enum class ContactQueryResultOrdering
{
    SystemDefault = 0,
    GivenNameFamilyName = 1,
    FamilyNameGivenName = 2,
};

enum class ContactStoreApplicationAccessMode
{
    LimitedReadOnly = 0,
    ReadOnly = 1,
};

enum class ContactStoreSystemAccessMode
{
    ReadOnly = 0,
    ReadWrite = 1,
};

enum class VCardFormat
{
    Version2_1 = 0,
    Version3 = 1,
};

}

}
