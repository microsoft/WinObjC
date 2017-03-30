// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Phone.PersonalInformation.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Storage.Streams.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Phone::PersonalInformation {

struct __declspec(uuid("5f24f927-94a9-44a2-a155-2d0b37d1dccd")) __declspec(novtable) IContactAddress : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Country(hstring * value) = 0;
    virtual HRESULT __stdcall put_Country(hstring value) = 0;
    virtual HRESULT __stdcall get_Locality(hstring * value) = 0;
    virtual HRESULT __stdcall put_Locality(hstring value) = 0;
    virtual HRESULT __stdcall get_Region(hstring * value) = 0;
    virtual HRESULT __stdcall put_Region(hstring value) = 0;
    virtual HRESULT __stdcall get_PostalCode(hstring * value) = 0;
    virtual HRESULT __stdcall put_PostalCode(hstring value) = 0;
    virtual HRESULT __stdcall get_StreetAddress(hstring * value) = 0;
    virtual HRESULT __stdcall put_StreetAddress(hstring value) = 0;
};

struct __declspec(uuid("b9d3f78f-513b-4742-be00-cc5c5c236b04")) __declspec(novtable) IContactChangeRecord : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ChangeType(winrt::Windows::Phone::PersonalInformation::ContactChangeType * value) = 0;
    virtual HRESULT __stdcall get_RevisionNumber(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_RemoteId(hstring * value) = 0;
};

struct __declspec(uuid("e2b51ffc-e792-4ab7-b15b-f2e078664dea")) __declspec(novtable) IContactInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_FamilyName(hstring * value) = 0;
    virtual HRESULT __stdcall put_FamilyName(hstring value) = 0;
    virtual HRESULT __stdcall get_GivenName(hstring * value) = 0;
    virtual HRESULT __stdcall put_GivenName(hstring value) = 0;
    virtual HRESULT __stdcall get_HonorificPrefix(hstring * value) = 0;
    virtual HRESULT __stdcall put_HonorificPrefix(hstring value) = 0;
    virtual HRESULT __stdcall get_HonorificSuffix(hstring * value) = 0;
    virtual HRESULT __stdcall put_HonorificSuffix(hstring value) = 0;
    virtual HRESULT __stdcall abi_GetDisplayPictureAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> ** operation) = 0;
    virtual HRESULT __stdcall abi_SetDisplayPictureAsync(Windows::Storage::Streams::IInputStream * stream, Windows::Foundation::IAsyncAction ** action) = 0;
    virtual HRESULT __stdcall get_DisplayPicture(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall abi_GetPropertiesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> ** operation) = 0;
    virtual HRESULT __stdcall abi_ToVcardAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> ** operation) = 0;
    virtual HRESULT __stdcall abi_ToVcardWithOptionsAsync(winrt::Windows::Phone::PersonalInformation::VCardFormat format, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> ** operation) = 0;
};

struct __declspec(uuid("3198b20c-621e-4668-ac38-d667b87d06d5")) __declspec(novtable) IContactInformation2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayPictureDate(Windows::Foundation::DateTime * returnValue) = 0;
    virtual HRESULT __stdcall put_DisplayPictureDate(Windows::Foundation::DateTime returnValue) = 0;
};

struct __declspec(uuid("0f67bb29-03d0-4be6-b2a5-fb13859f1202")) __declspec(novtable) IContactInformationStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ParseVcardAsync(Windows::Storage::Streams::IInputStream * vcard, Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactInformation> ** operation) = 0;
};

struct __declspec(uuid("580cab76-3f31-46c1-9a50-424a53dacae3")) __declspec(novtable) IContactQueryOptions : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DesiredFields(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_OrderBy(winrt::Windows::Phone::PersonalInformation::ContactQueryResultOrdering * value) = 0;
    virtual HRESULT __stdcall put_OrderBy(winrt::Windows::Phone::PersonalInformation::ContactQueryResultOrdering value) = 0;
};

struct __declspec(uuid("c03db722-ecdb-4700-857e-3e786426b04b")) __declspec(novtable) IContactQueryResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetContactCountAsync(Windows::Foundation::IAsyncOperation<uint32_t> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetContactsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::StoredContact>> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetContactsAsyncInRange(uint32_t startIndex, uint32_t maxNumberOfItems, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::StoredContact>> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetCurrentQueryOptions(Windows::Phone::PersonalInformation::IContactQueryOptions ** value) = 0;
};

struct __declspec(uuid("b2cd6fef-2bfd-4fad-8552-4e698097e8eb")) __declspec(novtable) IContactStore : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindContactByRemoteIdAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact> ** operation) = 0;
    virtual HRESULT __stdcall abi_FindContactByIdAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact> ** operation) = 0;
    virtual HRESULT __stdcall abi_DeleteContactAsync(hstring id, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_CreateContactQueryDefault(Windows::Phone::PersonalInformation::IContactQueryResult ** result) = 0;
    virtual HRESULT __stdcall abi_CreateContactQueryWithOptions(Windows::Phone::PersonalInformation::IContactQueryOptions * options, Windows::Phone::PersonalInformation::IContactQueryResult ** result) = 0;
    virtual HRESULT __stdcall abi_DeleteAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall get_RevisionNumber(uint64_t * value) = 0;
    virtual HRESULT __stdcall abi_GetChangesAsync(uint64_t baseRevisionNumber, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::ContactChangeRecord>> ** operation) = 0;
    virtual HRESULT __stdcall abi_LoadExtendedPropertiesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> ** operation) = 0;
    virtual HRESULT __stdcall abi_SaveExtendedPropertiesAsync(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> * data, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("65f1b64f-d653-43a7-b236-b30c0f4d7269")) __declspec(novtable) IContactStore2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateMeContactAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact> ** operation) = 0;
};

struct __declspec(uuid("a804fe22-4beb-44cc-a572-67a5b92e8567")) __declspec(novtable) IContactStoreStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateOrOpenAsync(Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactStore> ** operation) = 0;
    virtual HRESULT __stdcall abi_CreateOrOpenWithOptionsAsync(winrt::Windows::Phone::PersonalInformation::ContactStoreSystemAccessMode access, winrt::Windows::Phone::PersonalInformation::ContactStoreApplicationAccessMode sharing, Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactStore> ** operation) = 0;
};

struct __declspec(uuid("d5812b01-2ced-4ee6-b1d6-094bf88ef0b6")) __declspec(novtable) IKnownContactPropertiesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_FamilyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_GivenName(hstring * value) = 0;
    virtual HRESULT __stdcall get_HonorificPrefix(hstring * value) = 0;
    virtual HRESULT __stdcall get_HonorificSuffix(hstring * value) = 0;
    virtual HRESULT __stdcall get_AdditionalName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Address(hstring * value) = 0;
    virtual HRESULT __stdcall get_OtherAddress(hstring * value) = 0;
    virtual HRESULT __stdcall get_Email(hstring * value) = 0;
    virtual HRESULT __stdcall get_WorkAddress(hstring * value) = 0;
    virtual HRESULT __stdcall get_WorkTelephone(hstring * value) = 0;
    virtual HRESULT __stdcall get_JobTitle(hstring * value) = 0;
    virtual HRESULT __stdcall get_Birthdate(hstring * value) = 0;
    virtual HRESULT __stdcall get_Anniversary(hstring * value) = 0;
    virtual HRESULT __stdcall get_Telephone(hstring * value) = 0;
    virtual HRESULT __stdcall get_MobileTelephone(hstring * value) = 0;
    virtual HRESULT __stdcall get_Url(hstring * value) = 0;
    virtual HRESULT __stdcall get_Notes(hstring * value) = 0;
    virtual HRESULT __stdcall get_WorkFax(hstring * value) = 0;
    virtual HRESULT __stdcall get_Children(hstring * value) = 0;
    virtual HRESULT __stdcall get_SignificantOther(hstring * value) = 0;
    virtual HRESULT __stdcall get_CompanyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_CompanyTelephone(hstring * value) = 0;
    virtual HRESULT __stdcall get_HomeFax(hstring * value) = 0;
    virtual HRESULT __stdcall get_AlternateTelephone(hstring * value) = 0;
    virtual HRESULT __stdcall get_Manager(hstring * value) = 0;
    virtual HRESULT __stdcall get_Nickname(hstring * value) = 0;
    virtual HRESULT __stdcall get_OfficeLocation(hstring * value) = 0;
    virtual HRESULT __stdcall get_WorkEmail(hstring * value) = 0;
    virtual HRESULT __stdcall get_YomiGivenName(hstring * value) = 0;
    virtual HRESULT __stdcall get_YomiFamilyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_YomiCompanyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_OtherEmail(hstring * value) = 0;
    virtual HRESULT __stdcall get_AlternateMobileTelephone(hstring * value) = 0;
    virtual HRESULT __stdcall get_AlternateWorkTelephone(hstring * value) = 0;
};

struct __declspec(uuid("b070b7b1-263d-4e71-abe7-591d2466570e")) __declspec(novtable) IStoredContact : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Store(Windows::Phone::PersonalInformation::IContactStore ** value) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_RemoteId(hstring * value) = 0;
    virtual HRESULT __stdcall put_RemoteId(hstring value) = 0;
    virtual HRESULT __stdcall abi_GetExtendedPropertiesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> ** operation) = 0;
    virtual HRESULT __stdcall abi_SaveAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReplaceExistingContactAsync(hstring id, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("49ede921-c225-4fd9-89c5-cecc2c8a4b79")) __declspec(novtable) IStoredContactFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateStoredContact(Windows::Phone::PersonalInformation::IContactStore * store, Windows::Phone::PersonalInformation::IStoredContact ** result) = 0;
    virtual HRESULT __stdcall abi_CreateStoredContactFromInformation(Windows::Phone::PersonalInformation::IContactStore * store, Windows::Phone::PersonalInformation::IContactInformation * contact, Windows::Phone::PersonalInformation::IStoredContact ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Phone::PersonalInformation::ContactAddress> { using default_interface = Windows::Phone::PersonalInformation::IContactAddress; };
template <> struct traits<Windows::Phone::PersonalInformation::ContactChangeRecord> { using default_interface = Windows::Phone::PersonalInformation::IContactChangeRecord; };
template <> struct traits<Windows::Phone::PersonalInformation::ContactInformation> { using default_interface = Windows::Phone::PersonalInformation::IContactInformation; };
template <> struct traits<Windows::Phone::PersonalInformation::ContactQueryOptions> { using default_interface = Windows::Phone::PersonalInformation::IContactQueryOptions; };
template <> struct traits<Windows::Phone::PersonalInformation::ContactQueryResult> { using default_interface = Windows::Phone::PersonalInformation::IContactQueryResult; };
template <> struct traits<Windows::Phone::PersonalInformation::ContactStore> { using default_interface = Windows::Phone::PersonalInformation::IContactStore; };
template <> struct traits<Windows::Phone::PersonalInformation::StoredContact> { using default_interface = Windows::Phone::PersonalInformation::IStoredContact; };

}

namespace Windows::Phone::PersonalInformation {

template <typename D>
struct WINRT_EBO impl_IContactAddress
{
    hstring Country() const;
    void Country(hstring_view value) const;
    hstring Locality() const;
    void Locality(hstring_view value) const;
    hstring Region() const;
    void Region(hstring_view value) const;
    hstring PostalCode() const;
    void PostalCode(hstring_view value) const;
    hstring StreetAddress() const;
    void StreetAddress(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IContactChangeRecord
{
    Windows::Phone::PersonalInformation::ContactChangeType ChangeType() const;
    uint64_t RevisionNumber() const;
    hstring Id() const;
    hstring RemoteId() const;
};

template <typename D>
struct WINRT_EBO impl_IContactInformation
{
    hstring DisplayName() const;
    void DisplayName(hstring_view value) const;
    hstring FamilyName() const;
    void FamilyName(hstring_view value) const;
    hstring GivenName() const;
    void GivenName(hstring_view value) const;
    hstring HonorificPrefix() const;
    void HonorificPrefix(hstring_view value) const;
    hstring HonorificSuffix() const;
    void HonorificSuffix(hstring_view value) const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> GetDisplayPictureAsync() const;
    Windows::Foundation::IAsyncAction SetDisplayPictureAsync(const Windows::Storage::Streams::IInputStream & stream) const;
    Windows::Storage::Streams::IRandomAccessStreamReference DisplayPicture() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> GetPropertiesAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> ToVcardAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> ToVcardAsync(Windows::Phone::PersonalInformation::VCardFormat format) const;
};

template <typename D>
struct WINRT_EBO impl_IContactInformation2
{
    Windows::Foundation::DateTime DisplayPictureDate() const;
    void DisplayPictureDate(const Windows::Foundation::DateTime & returnValue) const;
};

template <typename D>
struct WINRT_EBO impl_IContactInformationStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactInformation> ParseVcardAsync(const Windows::Storage::Streams::IInputStream & vcard) const;
};

template <typename D>
struct WINRT_EBO impl_IContactQueryOptions
{
    Windows::Foundation::Collections::IVector<hstring> DesiredFields() const;
    Windows::Phone::PersonalInformation::ContactQueryResultOrdering OrderBy() const;
    void OrderBy(Windows::Phone::PersonalInformation::ContactQueryResultOrdering value) const;
};

template <typename D>
struct WINRT_EBO impl_IContactQueryResult
{
    Windows::Foundation::IAsyncOperation<uint32_t> GetContactCountAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::StoredContact>> GetContactsAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::StoredContact>> GetContactsAsync(uint32_t startIndex, uint32_t maxNumberOfItems) const;
    Windows::Phone::PersonalInformation::ContactQueryOptions GetCurrentQueryOptions() const;
};

template <typename D>
struct WINRT_EBO impl_IContactStore
{
    Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact> FindContactByRemoteIdAsync(hstring_view id) const;
    Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact> FindContactByIdAsync(hstring_view id) const;
    Windows::Foundation::IAsyncAction DeleteContactAsync(hstring_view id) const;
    Windows::Phone::PersonalInformation::ContactQueryResult CreateContactQuery() const;
    Windows::Phone::PersonalInformation::ContactQueryResult CreateContactQuery(const Windows::Phone::PersonalInformation::ContactQueryOptions & options) const;
    Windows::Foundation::IAsyncAction DeleteAsync() const;
    uint64_t RevisionNumber() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::ContactChangeRecord>> GetChangesAsync(uint64_t baseRevisionNumber) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> LoadExtendedPropertiesAsync() const;
    Windows::Foundation::IAsyncAction SaveExtendedPropertiesAsync(map_view<hstring, Windows::Foundation::IInspectable> data) const;
};

template <typename D>
struct WINRT_EBO impl_IContactStore2
{
    Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact> CreateMeContactAsync(hstring_view id) const;
};

template <typename D>
struct WINRT_EBO impl_IContactStoreStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactStore> CreateOrOpenAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Phone::PersonalInformation::ContactStore> CreateOrOpenAsync(Windows::Phone::PersonalInformation::ContactStoreSystemAccessMode access, Windows::Phone::PersonalInformation::ContactStoreApplicationAccessMode sharing) const;
};

template <typename D>
struct WINRT_EBO impl_IKnownContactPropertiesStatics
{
    hstring DisplayName() const;
    hstring FamilyName() const;
    hstring GivenName() const;
    hstring HonorificPrefix() const;
    hstring HonorificSuffix() const;
    hstring AdditionalName() const;
    hstring Address() const;
    hstring OtherAddress() const;
    hstring Email() const;
    hstring WorkAddress() const;
    hstring WorkTelephone() const;
    hstring JobTitle() const;
    hstring Birthdate() const;
    hstring Anniversary() const;
    hstring Telephone() const;
    hstring MobileTelephone() const;
    hstring Url() const;
    hstring Notes() const;
    hstring WorkFax() const;
    hstring Children() const;
    hstring SignificantOther() const;
    hstring CompanyName() const;
    hstring CompanyTelephone() const;
    hstring HomeFax() const;
    hstring AlternateTelephone() const;
    hstring Manager() const;
    hstring Nickname() const;
    hstring OfficeLocation() const;
    hstring WorkEmail() const;
    hstring YomiGivenName() const;
    hstring YomiFamilyName() const;
    hstring YomiCompanyName() const;
    hstring OtherEmail() const;
    hstring AlternateMobileTelephone() const;
    hstring AlternateWorkTelephone() const;
};

template <typename D>
struct WINRT_EBO impl_IStoredContact
{
    Windows::Phone::PersonalInformation::ContactStore Store() const;
    hstring Id() const;
    hstring RemoteId() const;
    void RemoteId(hstring_view value) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> GetExtendedPropertiesAsync() const;
    Windows::Foundation::IAsyncAction SaveAsync() const;
    Windows::Foundation::IAsyncAction ReplaceExistingContactAsync(hstring_view id) const;
};

template <typename D>
struct WINRT_EBO impl_IStoredContactFactory
{
    Windows::Phone::PersonalInformation::StoredContact CreateStoredContact(const Windows::Phone::PersonalInformation::ContactStore & store) const;
    Windows::Phone::PersonalInformation::StoredContact CreateStoredContactFromInformation(const Windows::Phone::PersonalInformation::ContactStore & store, const Windows::Phone::PersonalInformation::ContactInformation & contact) const;
};

}

namespace impl {

template <> struct traits<Windows::Phone::PersonalInformation::IContactAddress>
{
    using abi = ABI::Windows::Phone::PersonalInformation::IContactAddress;
    template <typename D> using consume = Windows::Phone::PersonalInformation::impl_IContactAddress<D>;
};

template <> struct traits<Windows::Phone::PersonalInformation::IContactChangeRecord>
{
    using abi = ABI::Windows::Phone::PersonalInformation::IContactChangeRecord;
    template <typename D> using consume = Windows::Phone::PersonalInformation::impl_IContactChangeRecord<D>;
};

template <> struct traits<Windows::Phone::PersonalInformation::IContactInformation>
{
    using abi = ABI::Windows::Phone::PersonalInformation::IContactInformation;
    template <typename D> using consume = Windows::Phone::PersonalInformation::impl_IContactInformation<D>;
};

template <> struct traits<Windows::Phone::PersonalInformation::IContactInformation2>
{
    using abi = ABI::Windows::Phone::PersonalInformation::IContactInformation2;
    template <typename D> using consume = Windows::Phone::PersonalInformation::impl_IContactInformation2<D>;
};

template <> struct traits<Windows::Phone::PersonalInformation::IContactInformationStatics>
{
    using abi = ABI::Windows::Phone::PersonalInformation::IContactInformationStatics;
    template <typename D> using consume = Windows::Phone::PersonalInformation::impl_IContactInformationStatics<D>;
};

template <> struct traits<Windows::Phone::PersonalInformation::IContactQueryOptions>
{
    using abi = ABI::Windows::Phone::PersonalInformation::IContactQueryOptions;
    template <typename D> using consume = Windows::Phone::PersonalInformation::impl_IContactQueryOptions<D>;
};

template <> struct traits<Windows::Phone::PersonalInformation::IContactQueryResult>
{
    using abi = ABI::Windows::Phone::PersonalInformation::IContactQueryResult;
    template <typename D> using consume = Windows::Phone::PersonalInformation::impl_IContactQueryResult<D>;
};

template <> struct traits<Windows::Phone::PersonalInformation::IContactStore>
{
    using abi = ABI::Windows::Phone::PersonalInformation::IContactStore;
    template <typename D> using consume = Windows::Phone::PersonalInformation::impl_IContactStore<D>;
};

template <> struct traits<Windows::Phone::PersonalInformation::IContactStore2>
{
    using abi = ABI::Windows::Phone::PersonalInformation::IContactStore2;
    template <typename D> using consume = Windows::Phone::PersonalInformation::impl_IContactStore2<D>;
};

template <> struct traits<Windows::Phone::PersonalInformation::IContactStoreStatics>
{
    using abi = ABI::Windows::Phone::PersonalInformation::IContactStoreStatics;
    template <typename D> using consume = Windows::Phone::PersonalInformation::impl_IContactStoreStatics<D>;
};

template <> struct traits<Windows::Phone::PersonalInformation::IKnownContactPropertiesStatics>
{
    using abi = ABI::Windows::Phone::PersonalInformation::IKnownContactPropertiesStatics;
    template <typename D> using consume = Windows::Phone::PersonalInformation::impl_IKnownContactPropertiesStatics<D>;
};

template <> struct traits<Windows::Phone::PersonalInformation::IStoredContact>
{
    using abi = ABI::Windows::Phone::PersonalInformation::IStoredContact;
    template <typename D> using consume = Windows::Phone::PersonalInformation::impl_IStoredContact<D>;
};

template <> struct traits<Windows::Phone::PersonalInformation::IStoredContactFactory>
{
    using abi = ABI::Windows::Phone::PersonalInformation::IStoredContactFactory;
    template <typename D> using consume = Windows::Phone::PersonalInformation::impl_IStoredContactFactory<D>;
};

template <> struct traits<Windows::Phone::PersonalInformation::ContactAddress>
{
    using abi = ABI::Windows::Phone::PersonalInformation::ContactAddress;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.PersonalInformation.ContactAddress"; }
};

template <> struct traits<Windows::Phone::PersonalInformation::ContactChangeRecord>
{
    using abi = ABI::Windows::Phone::PersonalInformation::ContactChangeRecord;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.PersonalInformation.ContactChangeRecord"; }
};

template <> struct traits<Windows::Phone::PersonalInformation::ContactInformation>
{
    using abi = ABI::Windows::Phone::PersonalInformation::ContactInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.PersonalInformation.ContactInformation"; }
};

template <> struct traits<Windows::Phone::PersonalInformation::ContactQueryOptions>
{
    using abi = ABI::Windows::Phone::PersonalInformation::ContactQueryOptions;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.PersonalInformation.ContactQueryOptions"; }
};

template <> struct traits<Windows::Phone::PersonalInformation::ContactQueryResult>
{
    using abi = ABI::Windows::Phone::PersonalInformation::ContactQueryResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.PersonalInformation.ContactQueryResult"; }
};

template <> struct traits<Windows::Phone::PersonalInformation::ContactStore>
{
    using abi = ABI::Windows::Phone::PersonalInformation::ContactStore;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.PersonalInformation.ContactStore"; }
};

template <> struct traits<Windows::Phone::PersonalInformation::KnownContactProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.PersonalInformation.KnownContactProperties"; }
};

template <> struct traits<Windows::Phone::PersonalInformation::StoredContact>
{
    using abi = ABI::Windows::Phone::PersonalInformation::StoredContact;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.PersonalInformation.StoredContact"; }
};

}

}
