// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Contacts.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.System.0.h"
#include "Windows.UI.Popups.0.h"
#include "Windows.UI.ViewManagement.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Storage.Streams.1.h"
#include "Windows.Data.Text.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Contacts {

struct __declspec(uuid("0379d5dd-db5a-4fd3-b54e-4df17917a212")) __declspec(novtable) IAggregateContactManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindRawContactsAsync(Windows::ApplicationModel::Contacts::IContact * contact, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact>> ** value) = 0;
    virtual HRESULT __stdcall abi_TryLinkContactsAsync(Windows::ApplicationModel::Contacts::IContact * primaryContact, Windows::ApplicationModel::Contacts::IContact * secondaryContact, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> ** contact) = 0;
    virtual HRESULT __stdcall abi_UnlinkRawContactAsync(Windows::ApplicationModel::Contacts::IContact * contact, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_TrySetPreferredSourceForPictureAsync(Windows::ApplicationModel::Contacts::IContact * aggregateContact, Windows::ApplicationModel::Contacts::IContact * rawContact, Windows::Foundation::IAsyncOperation<bool> ** value) = 0;
};

struct __declspec(uuid("5e8cc2d8-a9cd-4430-9c4b-01348db2ca50")) __declspec(novtable) IAggregateContactManager2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetRemoteIdentificationInformationAsync(hstring contactListId, hstring remoteSourceId, hstring accountId, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("ec0072f3-2118-4049-9ebc-17f0ab692b64")) __declspec(novtable) IContact : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall put_Name(hstring value) = 0;
    virtual HRESULT __stdcall get_Thumbnail(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_Thumbnail(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall get_Fields(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::IContactField> ** value) = 0;
};

struct __declspec(uuid("f312f365-bb77-4c94-802d-8328cee40c08")) __declspec(novtable) IContact2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall put_Id(hstring value) = 0;
    virtual HRESULT __stdcall get_Notes(hstring * value) = 0;
    virtual HRESULT __stdcall put_Notes(hstring value) = 0;
    virtual HRESULT __stdcall get_Phones(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactPhone> ** value) = 0;
    virtual HRESULT __stdcall get_Emails(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactEmail> ** value) = 0;
    virtual HRESULT __stdcall get_Addresses(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactAddress> ** value) = 0;
    virtual HRESULT __stdcall get_ConnectedServiceAccounts(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactConnectedServiceAccount> ** value) = 0;
    virtual HRESULT __stdcall get_ImportantDates(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactDate> ** value) = 0;
    virtual HRESULT __stdcall get_DataSuppliers(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_JobInfo(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactJobInfo> ** value) = 0;
    virtual HRESULT __stdcall get_SignificantOthers(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactSignificantOther> ** value) = 0;
    virtual HRESULT __stdcall get_Websites(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactWebsite> ** value) = 0;
    virtual HRESULT __stdcall get_ProviderProperties(Windows::Foundation::Collections::IPropertySet ** value) = 0;
};

struct __declspec(uuid("48201e67-e08e-42a4-b561-41d08ca9575d")) __declspec(novtable) IContact3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContactListId(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayPictureUserUpdateTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_DisplayPictureUserUpdateTime(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_IsMe(bool * value) = 0;
    virtual HRESULT __stdcall get_AggregateId(hstring * value) = 0;
    virtual HRESULT __stdcall get_RemoteId(hstring * value) = 0;
    virtual HRESULT __stdcall put_RemoteId(hstring value) = 0;
    virtual HRESULT __stdcall get_RingToneToken(hstring * value) = 0;
    virtual HRESULT __stdcall put_RingToneToken(hstring value) = 0;
    virtual HRESULT __stdcall get_IsDisplayPictureManuallySet(bool * value) = 0;
    virtual HRESULT __stdcall get_LargeDisplayPicture(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall get_SmallDisplayPicture(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall get_SourceDisplayPicture(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_SourceDisplayPicture(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall get_TextToneToken(hstring * value) = 0;
    virtual HRESULT __stdcall put_TextToneToken(hstring value) = 0;
    virtual HRESULT __stdcall get_IsAggregate(bool * value) = 0;
    virtual HRESULT __stdcall get_FullName(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayNameOverride(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayNameOverride(hstring value) = 0;
    virtual HRESULT __stdcall get_Nickname(hstring * value) = 0;
    virtual HRESULT __stdcall put_Nickname(hstring value) = 0;
    virtual HRESULT __stdcall get_SortName(hstring * value) = 0;
};

struct __declspec(uuid("9739d39a-42ce-4872-8d70-3063aa584b70")) __declspec(novtable) IContactAddress : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_StreetAddress(hstring * value) = 0;
    virtual HRESULT __stdcall put_StreetAddress(hstring value) = 0;
    virtual HRESULT __stdcall get_Locality(hstring * value) = 0;
    virtual HRESULT __stdcall put_Locality(hstring value) = 0;
    virtual HRESULT __stdcall get_Region(hstring * value) = 0;
    virtual HRESULT __stdcall put_Region(hstring value) = 0;
    virtual HRESULT __stdcall get_Country(hstring * value) = 0;
    virtual HRESULT __stdcall put_Country(hstring value) = 0;
    virtual HRESULT __stdcall get_PostalCode(hstring * value) = 0;
    virtual HRESULT __stdcall put_PostalCode(hstring value) = 0;
    virtual HRESULT __stdcall get_Kind(winrt::Windows::ApplicationModel::Contacts::ContactAddressKind * value) = 0;
    virtual HRESULT __stdcall put_Kind(winrt::Windows::ApplicationModel::Contacts::ContactAddressKind value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall put_Description(hstring value) = 0;
};

struct __declspec(uuid("821fc2ef-7d41-44a2-84c3-60a281dd7b86")) __declspec(novtable) IContactAnnotation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_AnnotationListId(hstring * value) = 0;
    virtual HRESULT __stdcall get_ContactId(hstring * value) = 0;
    virtual HRESULT __stdcall put_ContactId(hstring value) = 0;
    virtual HRESULT __stdcall get_RemoteId(hstring * value) = 0;
    virtual HRESULT __stdcall put_RemoteId(hstring value) = 0;
    virtual HRESULT __stdcall get_SupportedOperations(winrt::Windows::ApplicationModel::Contacts::ContactAnnotationOperations * value) = 0;
    virtual HRESULT __stdcall put_SupportedOperations(winrt::Windows::ApplicationModel::Contacts::ContactAnnotationOperations value) = 0;
    virtual HRESULT __stdcall get_IsDisabled(bool * value) = 0;
    virtual HRESULT __stdcall get_ProviderProperties(Windows::Foundation::Collections::IPropertySet ** value) = 0;
};

struct __declspec(uuid("92a486aa-5c88-45b9-aad0-461888e68d8a")) __declspec(novtable) IContactAnnotationList : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_ProviderPackageFamilyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_UserDataAccountId(hstring * value) = 0;
    virtual HRESULT __stdcall abi_DeleteAsync(Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_TrySaveAnnotationAsync(Windows::ApplicationModel::Contacts::IContactAnnotation * annotation, Windows::Foundation::IAsyncOperation<bool> ** ppResult) = 0;
    virtual HRESULT __stdcall abi_GetAnnotationAsync(hstring annotationId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotation> ** annotation) = 0;
    virtual HRESULT __stdcall abi_FindAnnotationsByRemoteIdAsync(hstring remoteId, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotation>> ** annotations) = 0;
    virtual HRESULT __stdcall abi_FindAnnotationsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotation>> ** annotations) = 0;
    virtual HRESULT __stdcall abi_DeleteAnnotationAsync(Windows::ApplicationModel::Contacts::IContactAnnotation * annotation, Windows::Foundation::IAsyncAction ** value) = 0;
};

struct __declspec(uuid("23acf4aa-7a77-457d-8203-987f4b31af09")) __declspec(novtable) IContactAnnotationStore : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindContactIdsByEmailAsync(hstring emailAddress, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> ** contactIds) = 0;
    virtual HRESULT __stdcall abi_FindContactIdsByPhoneNumberAsync(hstring phoneNumber, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> ** contactIds) = 0;
    virtual HRESULT __stdcall abi_FindAnnotationsForContactAsync(Windows::ApplicationModel::Contacts::IContact * contact, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotation>> ** annotations) = 0;
    virtual HRESULT __stdcall abi_DisableAnnotationAsync(Windows::ApplicationModel::Contacts::IContactAnnotation * annotation, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_CreateAnnotationListAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationList> ** value) = 0;
    virtual HRESULT __stdcall abi_CreateAnnotationListInAccountAsync(hstring userDataAccountId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationList> ** value) = 0;
    virtual HRESULT __stdcall abi_GetAnnotationListAsync(hstring annotationListId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationList> ** value) = 0;
    virtual HRESULT __stdcall abi_FindAnnotationListsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotationList>> ** lists) = 0;
};

struct __declspec(uuid("35d1972d-bfce-46bb-93f8-a5b06ec5e201")) __declspec(novtable) IContactBatch : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Contacts(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact> ** value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::ApplicationModel::Contacts::ContactBatchStatus * value) = 0;
};

struct __declspec(uuid("b60af902-1546-434d-869c-6e3520760ef3")) __declspec(novtable) IContactCardDelayedDataLoader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetData(Windows::ApplicationModel::Contacts::IContact * contact) = 0;
};

struct __declspec(uuid("8c0a4f7e-6ab6-4f3f-be72-817236eeea5b")) __declspec(novtable) IContactCardOptions : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeaderKind(winrt::Windows::ApplicationModel::Contacts::ContactCardHeaderKind * value) = 0;
    virtual HRESULT __stdcall put_HeaderKind(winrt::Windows::ApplicationModel::Contacts::ContactCardHeaderKind value) = 0;
    virtual HRESULT __stdcall get_InitialTabKind(winrt::Windows::ApplicationModel::Contacts::ContactCardTabKind * value) = 0;
    virtual HRESULT __stdcall put_InitialTabKind(winrt::Windows::ApplicationModel::Contacts::ContactCardTabKind value) = 0;
};

struct __declspec(uuid("8f271ba0-d74b-4cc6-9f53-1b0eb5d1273c")) __declspec(novtable) IContactCardOptions2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServerSearchContactListIds(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
};

struct __declspec(uuid("951d4b10-6a59-4720-a4e1-363d98c135d5")) __declspec(novtable) IContactChange : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ChangeType(winrt::Windows::ApplicationModel::Contacts::ContactChangeType * value) = 0;
    virtual HRESULT __stdcall get_Contact(Windows::ApplicationModel::Contacts::IContact ** value) = 0;
};

struct __declspec(uuid("217319fa-2d0c-42e0-a9da-3ecd56a78a47")) __declspec(novtable) IContactChangeReader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AcceptChanges() = 0;
    virtual HRESULT __stdcall abi_AcceptChangesThrough(Windows::ApplicationModel::Contacts::IContactChange * lastChangeToAccept) = 0;
    virtual HRESULT __stdcall abi_ReadBatchAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactChange>> ** value) = 0;
};

struct __declspec(uuid("6e992952-309b-404d-9712-b37bd30278aa")) __declspec(novtable) IContactChangeTracker : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Enable() = 0;
    virtual HRESULT __stdcall abi_GetChangeReader(Windows::ApplicationModel::Contacts::IContactChangeReader ** value) = 0;
    virtual HRESULT __stdcall abi_Reset() = 0;
};

struct __declspec(uuid("c5143ae8-1b03-46f8-b694-a523e83cfcb6")) __declspec(novtable) IContactChangedDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("525e7fd1-73f3-4b7d-a918-580be4366121")) __declspec(novtable) IContactChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeferral(Windows::ApplicationModel::Contacts::IContactChangedDeferral ** value) = 0;
};

struct __declspec(uuid("f6f83553-aa27-4731-8e4a-3dec5ce9eec9")) __declspec(novtable) IContactConnectedServiceAccount : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall put_Id(hstring value) = 0;
    virtual HRESULT __stdcall get_ServiceName(hstring * value) = 0;
    virtual HRESULT __stdcall put_ServiceName(hstring value) = 0;
};

struct __declspec(uuid("fe98ae66-b205-4934-9174-0ff2b0565707")) __declspec(novtable) IContactDate : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Day(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall put_Day(Windows::Foundation::IReference<uint32_t> * value) = 0;
    virtual HRESULT __stdcall get_Month(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall put_Month(Windows::Foundation::IReference<uint32_t> * value) = 0;
    virtual HRESULT __stdcall get_Year(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_Year(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_Kind(winrt::Windows::ApplicationModel::Contacts::ContactDateKind * value) = 0;
    virtual HRESULT __stdcall put_Kind(winrt::Windows::ApplicationModel::Contacts::ContactDateKind value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall put_Description(hstring value) = 0;
};

struct __declspec(uuid("90a219a9-e3d3-4d63-993b-05b9a5393abf")) __declspec(novtable) IContactEmail : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Address(hstring * value) = 0;
    virtual HRESULT __stdcall put_Address(hstring value) = 0;
    virtual HRESULT __stdcall get_Kind(winrt::Windows::ApplicationModel::Contacts::ContactEmailKind * value) = 0;
    virtual HRESULT __stdcall put_Kind(winrt::Windows::ApplicationModel::Contacts::ContactEmailKind value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall put_Description(hstring value) = 0;
};

struct __declspec(uuid("b176486a-d293-492c-a058-db575b3e3c0f")) __declspec(novtable) IContactField : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Type(winrt::Windows::ApplicationModel::Contacts::ContactFieldType * value) = 0;
    virtual HRESULT __stdcall get_Category(winrt::Windows::ApplicationModel::Contacts::ContactFieldCategory * value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_Value(hstring * value) = 0;
};

struct __declspec(uuid("85e2913f-0e4a-4a3e-8994-406ae7ed646e")) __declspec(novtable) IContactFieldFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateField_Default(hstring value, winrt::Windows::ApplicationModel::Contacts::ContactFieldType type, Windows::ApplicationModel::Contacts::IContactField ** field) = 0;
    virtual HRESULT __stdcall abi_CreateField_Category(hstring value, winrt::Windows::ApplicationModel::Contacts::ContactFieldType type, winrt::Windows::ApplicationModel::Contacts::ContactFieldCategory category, Windows::ApplicationModel::Contacts::IContactField ** field) = 0;
    virtual HRESULT __stdcall abi_CreateField_Custom(hstring name, hstring value, winrt::Windows::ApplicationModel::Contacts::ContactFieldType type, winrt::Windows::ApplicationModel::Contacts::ContactFieldCategory category, Windows::ApplicationModel::Contacts::IContactField ** field) = 0;
};

struct __declspec(uuid("275eb6d4-6a2e-4278-a914-e460d5f088f6")) __declspec(novtable) IContactInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetThumbnailAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> ** operation) = 0;
    virtual HRESULT __stdcall get_Emails(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField> ** value) = 0;
    virtual HRESULT __stdcall get_PhoneNumbers(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField> ** value) = 0;
    virtual HRESULT __stdcall get_Locations(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactLocationField> ** value) = 0;
    virtual HRESULT __stdcall get_InstantMessages(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactInstantMessageField> ** value) = 0;
    virtual HRESULT __stdcall get_CustomFields(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField> ** value) = 0;
    virtual HRESULT __stdcall abi_QueryCustomFields(hstring customName, Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField> ** value) = 0;
};

struct __declspec(uuid("cce33b37-0d85-41fa-b43d-da599c3eb009")) __declspec(novtable) IContactInstantMessageField : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UserName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Service(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayText(hstring * value) = 0;
    virtual HRESULT __stdcall get_LaunchUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
};

struct __declspec(uuid("ba0b6794-91a3-4bb2-b1b9-69a5dff0ba09")) __declspec(novtable) IContactInstantMessageFieldFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstantMessage_Default(hstring userName, Windows::ApplicationModel::Contacts::IContactInstantMessageField ** field) = 0;
    virtual HRESULT __stdcall abi_CreateInstantMessage_Category(hstring userName, winrt::Windows::ApplicationModel::Contacts::ContactFieldCategory category, Windows::ApplicationModel::Contacts::IContactInstantMessageField ** field) = 0;
    virtual HRESULT __stdcall abi_CreateInstantMessage_All(hstring userName, winrt::Windows::ApplicationModel::Contacts::ContactFieldCategory category, hstring service, hstring displayText, Windows::Foundation::IUriRuntimeClass * verb, Windows::ApplicationModel::Contacts::IContactInstantMessageField ** field) = 0;
};

struct __declspec(uuid("6d117b4c-ce50-4b43-9e69-b18258ea5315")) __declspec(novtable) IContactJobInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CompanyName(hstring * value) = 0;
    virtual HRESULT __stdcall put_CompanyName(hstring value) = 0;
    virtual HRESULT __stdcall get_CompanyYomiName(hstring * value) = 0;
    virtual HRESULT __stdcall put_CompanyYomiName(hstring value) = 0;
    virtual HRESULT __stdcall get_Department(hstring * value) = 0;
    virtual HRESULT __stdcall put_Department(hstring value) = 0;
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall put_Title(hstring value) = 0;
    virtual HRESULT __stdcall get_Manager(hstring * value) = 0;
    virtual HRESULT __stdcall put_Manager(hstring value) = 0;
    virtual HRESULT __stdcall get_Office(hstring * value) = 0;
    virtual HRESULT __stdcall put_Office(hstring value) = 0;
    virtual HRESULT __stdcall get_CompanyAddress(hstring * value) = 0;
    virtual HRESULT __stdcall put_CompanyAddress(hstring value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall put_Description(hstring value) = 0;
};

struct __declspec(uuid("fb1232d6-ee73-46e7-8761-11cd0157728f")) __declspec(novtable) IContactLaunchActionVerbsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Call(hstring * value) = 0;
    virtual HRESULT __stdcall get_Message(hstring * value) = 0;
    virtual HRESULT __stdcall get_Map(hstring * value) = 0;
    virtual HRESULT __stdcall get_Post(hstring * value) = 0;
    virtual HRESULT __stdcall get_VideoCall(hstring * value) = 0;
};

struct __declspec(uuid("16ddec75-392c-4845-9dfb-51a3e7ef3e42")) __declspec(novtable) IContactList : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_SourceDisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_IsHidden(bool * value) = 0;
    virtual HRESULT __stdcall put_IsHidden(bool value) = 0;
    virtual HRESULT __stdcall get_OtherAppReadAccess(winrt::Windows::ApplicationModel::Contacts::ContactListOtherAppReadAccess * value) = 0;
    virtual HRESULT __stdcall put_OtherAppReadAccess(winrt::Windows::ApplicationModel::Contacts::ContactListOtherAppReadAccess value) = 0;
    virtual HRESULT __stdcall get_OtherAppWriteAccess(winrt::Windows::ApplicationModel::Contacts::ContactListOtherAppWriteAccess * value) = 0;
    virtual HRESULT __stdcall put_OtherAppWriteAccess(winrt::Windows::ApplicationModel::Contacts::ContactListOtherAppWriteAccess value) = 0;
    virtual HRESULT __stdcall get_ChangeTracker(Windows::ApplicationModel::Contacts::IContactChangeTracker ** value) = 0;
    virtual HRESULT __stdcall get_SyncManager(Windows::ApplicationModel::Contacts::IContactListSyncManager ** value) = 0;
    virtual HRESULT __stdcall get_SupportsServerSearch(bool * value) = 0;
    virtual HRESULT __stdcall get_UserDataAccountId(hstring * value) = 0;
    virtual HRESULT __stdcall add_ContactChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactList, Windows::ApplicationModel::Contacts::ContactChangedEventArgs> * value, event_token * returnValue) = 0;
    virtual HRESULT __stdcall remove_ContactChanged(event_token value) = 0;
    virtual HRESULT __stdcall abi_SaveAsync(Windows::Foundation::IAsyncAction ** returnValue) = 0;
    virtual HRESULT __stdcall abi_DeleteAsync(Windows::Foundation::IAsyncAction ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetContactFromRemoteIdAsync(hstring remoteId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> ** contact) = 0;
    virtual HRESULT __stdcall abi_GetMeContactAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> ** meContact) = 0;
    virtual HRESULT __stdcall abi_GetContactReader(Windows::ApplicationModel::Contacts::IContactReader ** value) = 0;
    virtual HRESULT __stdcall abi_GetContactReaderWithOptions(Windows::ApplicationModel::Contacts::IContactQueryOptions * options, Windows::ApplicationModel::Contacts::IContactReader ** value) = 0;
    virtual HRESULT __stdcall abi_SaveContactAsync(Windows::ApplicationModel::Contacts::IContact * contact, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_DeleteContactAsync(Windows::ApplicationModel::Contacts::IContact * contact, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_GetContactAsync(hstring contactId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> ** contacts) = 0;
};

struct __declspec(uuid("cb3943b4-4550-4dcb-9229-40ff91fb0203")) __declspec(novtable) IContactList2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RegisterSyncManagerAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall put_SupportsServerSearch(bool value) = 0;
    virtual HRESULT __stdcall get_SyncConstraints(Windows::ApplicationModel::Contacts::IContactListSyncConstraints ** value) = 0;
};

struct __declspec(uuid("b2b0bf01-3062-4e2e-969d-018d1987f314")) __declspec(novtable) IContactListSyncConstraints : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CanSyncDescriptions(bool * value) = 0;
    virtual HRESULT __stdcall put_CanSyncDescriptions(bool value) = 0;
    virtual HRESULT __stdcall get_MaxHomePhoneNumbers(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxHomePhoneNumbers(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxMobilePhoneNumbers(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxMobilePhoneNumbers(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxWorkPhoneNumbers(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxWorkPhoneNumbers(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxOtherPhoneNumbers(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxOtherPhoneNumbers(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxPagerPhoneNumbers(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxPagerPhoneNumbers(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxBusinessFaxPhoneNumbers(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxBusinessFaxPhoneNumbers(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxHomeFaxPhoneNumbers(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxHomeFaxPhoneNumbers(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxCompanyPhoneNumbers(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxCompanyPhoneNumbers(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxAssistantPhoneNumbers(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxAssistantPhoneNumbers(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxRadioPhoneNumbers(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxRadioPhoneNumbers(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxPersonalEmailAddresses(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxPersonalEmailAddresses(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxWorkEmailAddresses(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxWorkEmailAddresses(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxOtherEmailAddresses(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxOtherEmailAddresses(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxHomeAddresses(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxHomeAddresses(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxWorkAddresses(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxWorkAddresses(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxOtherAddresses(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxOtherAddresses(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxBirthdayDates(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxBirthdayDates(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxAnniversaryDates(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxAnniversaryDates(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxOtherDates(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxOtherDates(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxOtherRelationships(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxOtherRelationships(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxSpouseRelationships(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxSpouseRelationships(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxPartnerRelationships(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxPartnerRelationships(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxSiblingRelationships(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxSiblingRelationships(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxParentRelationships(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxParentRelationships(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxChildRelationships(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxChildRelationships(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxJobInfo(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxJobInfo(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_MaxWebsites(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxWebsites(Windows::Foundation::IReference<int32_t> * value) = 0;
};

struct __declspec(uuid("146e83be-7925-4acc-9de5-21ddd06f8674")) __declspec(novtable) IContactListSyncManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::ApplicationModel::Contacts::ContactListSyncStatus * value) = 0;
    virtual HRESULT __stdcall get_LastSuccessfulSyncTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_LastAttemptedSyncTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall abi_SyncAsync(Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall add_SyncStatusChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactListSyncManager, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SyncStatusChanged(event_token token) = 0;
};

struct __declspec(uuid("a9591247-bb55-4e23-8128-370134a85d0d")) __declspec(novtable) IContactListSyncManager2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Status(winrt::Windows::ApplicationModel::Contacts::ContactListSyncStatus value) = 0;
    virtual HRESULT __stdcall put_LastSuccessfulSyncTime(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall put_LastAttemptedSyncTime(Windows::Foundation::DateTime value) = 0;
};

struct __declspec(uuid("9ec00f82-ab6e-4b36-89e3-b23bc0a1dacc")) __declspec(novtable) IContactLocationField : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UnstructuredAddress(hstring * value) = 0;
    virtual HRESULT __stdcall get_Street(hstring * value) = 0;
    virtual HRESULT __stdcall get_City(hstring * value) = 0;
    virtual HRESULT __stdcall get_Region(hstring * value) = 0;
    virtual HRESULT __stdcall get_Country(hstring * value) = 0;
    virtual HRESULT __stdcall get_PostalCode(hstring * value) = 0;
};

struct __declspec(uuid("f79932d7-2fdf-43fe-8f18-41897390bcfe")) __declspec(novtable) IContactLocationFieldFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateLocation_Default(hstring unstructuredAddress, Windows::ApplicationModel::Contacts::IContactLocationField ** field) = 0;
    virtual HRESULT __stdcall abi_CreateLocation_Category(hstring unstructuredAddress, winrt::Windows::ApplicationModel::Contacts::ContactFieldCategory category, Windows::ApplicationModel::Contacts::IContactLocationField ** field) = 0;
    virtual HRESULT __stdcall abi_CreateLocation_All(hstring unstructuredAddress, winrt::Windows::ApplicationModel::Contacts::ContactFieldCategory category, hstring street, hstring city, hstring region, hstring country, hstring postalCode, Windows::ApplicationModel::Contacts::IContactLocationField ** field) = 0;
};

struct __declspec(uuid("b74bba57-1076-4bef-aef3-54686d18387d")) __declspec(novtable) IContactManagerForUser : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ConvertContactToVCardAsync(Windows::ApplicationModel::Contacts::IContact * contact, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> ** result) = 0;
    virtual HRESULT __stdcall abi_ConvertContactToVCardAsyncWithMaxBytes(Windows::ApplicationModel::Contacts::IContact * contact, uint32_t maxBytes, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> ** result) = 0;
    virtual HRESULT __stdcall abi_ConvertVCardToContactAsync(Windows::Storage::Streams::IRandomAccessStreamReference * vCard, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestStoreAsync(winrt::Windows::ApplicationModel::Contacts::ContactStoreAccessType accessType, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestAnnotationStoreAsync(winrt::Windows::ApplicationModel::Contacts::ContactAnnotationStoreAccessType accessType, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationStore> ** result) = 0;
    virtual HRESULT __stdcall get_SystemDisplayNameOrder(winrt::Windows::ApplicationModel::Contacts::ContactNameOrder * value) = 0;
    virtual HRESULT __stdcall put_SystemDisplayNameOrder(winrt::Windows::ApplicationModel::Contacts::ContactNameOrder value) = 0;
    virtual HRESULT __stdcall get_SystemSortOrder(winrt::Windows::ApplicationModel::Contacts::ContactNameOrder * value) = 0;
    virtual HRESULT __stdcall put_SystemSortOrder(winrt::Windows::ApplicationModel::Contacts::ContactNameOrder value) = 0;
    virtual HRESULT __stdcall get_User(Windows::System::IUser ** value) = 0;
};

struct __declspec(uuid("81f21ac0-f661-4708-ba4f-d386bd0d622e")) __declspec(novtable) IContactManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ShowContactCard(Windows::ApplicationModel::Contacts::IContact * contact, Windows::Foundation::Rect selection) = 0;
    virtual HRESULT __stdcall abi_ShowContactCardWithPlacement(Windows::ApplicationModel::Contacts::IContact * contact, Windows::Foundation::Rect selection, winrt::Windows::UI::Popups::Placement preferredPlacement) = 0;
    virtual HRESULT __stdcall abi_ShowDelayLoadedContactCard(Windows::ApplicationModel::Contacts::IContact * contact, Windows::Foundation::Rect selection, winrt::Windows::UI::Popups::Placement preferredPlacement, Windows::ApplicationModel::Contacts::IContactCardDelayedDataLoader ** dataLoader) = 0;
};

struct __declspec(uuid("a178e620-47d8-48cc-963c-9592b6e510c6")) __declspec(novtable) IContactManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestStoreAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore> ** store) = 0;
};

struct __declspec(uuid("c4cc3d42-7586-492a-930b-7bc138fc2139")) __declspec(novtable) IContactManagerStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ConvertContactToVCardAsync(Windows::ApplicationModel::Contacts::IContact * contact, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> ** vCard) = 0;
    virtual HRESULT __stdcall abi_ConvertContactToVCardAsyncWithMaxBytes(Windows::ApplicationModel::Contacts::IContact * contact, uint32_t maxBytes, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> ** vCard) = 0;
    virtual HRESULT __stdcall abi_ConvertVCardToContactAsync(Windows::Storage::Streams::IRandomAccessStreamReference * vCard, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> ** contact) = 0;
    virtual HRESULT __stdcall abi_RequestStoreAsyncWithAccessType(winrt::Windows::ApplicationModel::Contacts::ContactStoreAccessType accessType, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore> ** store) = 0;
    virtual HRESULT __stdcall abi_RequestAnnotationStoreAsync(winrt::Windows::ApplicationModel::Contacts::ContactAnnotationStoreAccessType accessType, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationStore> ** store) = 0;
    virtual HRESULT __stdcall abi_IsShowContactCardSupported(bool * result) = 0;
    virtual HRESULT __stdcall abi_ShowContactCardWithOptions(Windows::ApplicationModel::Contacts::IContact * contact, Windows::Foundation::Rect selection, winrt::Windows::UI::Popups::Placement preferredPlacement, Windows::ApplicationModel::Contacts::IContactCardOptions * contactCardOptions) = 0;
    virtual HRESULT __stdcall abi_IsShowDelayLoadedContactCardSupported(bool * result) = 0;
    virtual HRESULT __stdcall abi_ShowDelayLoadedContactCardWithOptions(Windows::ApplicationModel::Contacts::IContact * contact, Windows::Foundation::Rect selection, winrt::Windows::UI::Popups::Placement preferredPlacement, Windows::ApplicationModel::Contacts::IContactCardOptions * contactCardOptions, Windows::ApplicationModel::Contacts::IContactCardDelayedDataLoader ** dataLoader) = 0;
    virtual HRESULT __stdcall abi_ShowFullContactCard(Windows::ApplicationModel::Contacts::IContact * contact, Windows::ApplicationModel::Contacts::IFullContactCardOptions * fullContactCardOptions) = 0;
    virtual HRESULT __stdcall get_SystemDisplayNameOrder(winrt::Windows::ApplicationModel::Contacts::ContactNameOrder * value) = 0;
    virtual HRESULT __stdcall put_SystemDisplayNameOrder(winrt::Windows::ApplicationModel::Contacts::ContactNameOrder value) = 0;
    virtual HRESULT __stdcall get_SystemSortOrder(winrt::Windows::ApplicationModel::Contacts::ContactNameOrder * value) = 0;
    virtual HRESULT __stdcall put_SystemSortOrder(winrt::Windows::ApplicationModel::Contacts::ContactNameOrder value) = 0;
};

struct __declspec(uuid("24982272-347b-46dc-8d95-51bd41e15aaf")) __declspec(novtable) IContactManagerStatics4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForUser(Windows::System::IUser * user, Windows::ApplicationModel::Contacts::IContactManagerForUser ** result) = 0;
};

struct __declspec(uuid("bc922504-e7d8-413e-95f4-b75c54c74077")) __declspec(novtable) IContactMatchReason : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Field(winrt::Windows::ApplicationModel::Contacts::ContactMatchReasonKind * value) = 0;
    virtual HRESULT __stdcall get_Segments(Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment> ** value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
};

struct __declspec(uuid("f404e97b-9034-453c-8ebf-140a38c86f1d")) __declspec(novtable) IContactName : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FirstName(hstring * value) = 0;
    virtual HRESULT __stdcall put_FirstName(hstring value) = 0;
    virtual HRESULT __stdcall get_LastName(hstring * value) = 0;
    virtual HRESULT __stdcall put_LastName(hstring value) = 0;
    virtual HRESULT __stdcall get_MiddleName(hstring * value) = 0;
    virtual HRESULT __stdcall put_MiddleName(hstring value) = 0;
    virtual HRESULT __stdcall get_YomiGivenName(hstring * value) = 0;
    virtual HRESULT __stdcall put_YomiGivenName(hstring value) = 0;
    virtual HRESULT __stdcall get_YomiFamilyName(hstring * value) = 0;
    virtual HRESULT __stdcall put_YomiFamilyName(hstring value) = 0;
    virtual HRESULT __stdcall get_HonorificNameSuffix(hstring * value) = 0;
    virtual HRESULT __stdcall put_HonorificNameSuffix(hstring value) = 0;
    virtual HRESULT __stdcall get_HonorificNamePrefix(hstring * value) = 0;
    virtual HRESULT __stdcall put_HonorificNamePrefix(hstring value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_YomiDisplayName(hstring * value) = 0;
};

struct __declspec(uuid("467dab65-2712-4f52-b783-9ea8111c63cd")) __declspec(novtable) IContactPhone : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Number(hstring * value) = 0;
    virtual HRESULT __stdcall put_Number(hstring value) = 0;
    virtual HRESULT __stdcall get_Kind(winrt::Windows::ApplicationModel::Contacts::ContactPhoneKind * value) = 0;
    virtual HRESULT __stdcall put_Kind(winrt::Windows::ApplicationModel::Contacts::ContactPhoneKind value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall put_Description(hstring value) = 0;
};

struct __declspec(uuid("0e09fd91-42f8-4055-90a0-896f96738936")) __declspec(novtable) IContactPicker : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CommitButtonText(hstring * value) = 0;
    virtual HRESULT __stdcall put_CommitButtonText(hstring value) = 0;
    virtual HRESULT __stdcall get_SelectionMode(winrt::Windows::ApplicationModel::Contacts::ContactSelectionMode * value) = 0;
    virtual HRESULT __stdcall put_SelectionMode(winrt::Windows::ApplicationModel::Contacts::ContactSelectionMode value) = 0;
    virtual HRESULT __stdcall get_DesiredFields(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall abi_PickSingleContactAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactInformation> ** result) = 0;
    virtual HRESULT __stdcall abi_PickMultipleContactsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactInformation>> ** result) = 0;
};

struct __declspec(uuid("b35011cf-5cef-4d24-aa0c-340c5208725d")) __declspec(novtable) IContactPicker2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DesiredFieldsWithContactFieldType(Windows::Foundation::Collections::IVector<winrt::Windows::ApplicationModel::Contacts::ContactFieldType> ** value) = 0;
    virtual HRESULT __stdcall abi_PickContactAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> ** result) = 0;
    virtual HRESULT __stdcall abi_PickContactsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::Contact>> ** result) = 0;
};

struct __declspec(uuid("4408cc9e-7d7c-42f0-8ac7-f50733ecdbc1")) __declspec(novtable) IContactQueryOptions : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TextSearch(Windows::ApplicationModel::Contacts::IContactQueryTextSearch ** value) = 0;
    virtual HRESULT __stdcall get_ContactListIds(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_IncludeContactsFromHiddenLists(bool * value) = 0;
    virtual HRESULT __stdcall put_IncludeContactsFromHiddenLists(bool value) = 0;
    virtual HRESULT __stdcall get_DesiredFields(winrt::Windows::ApplicationModel::Contacts::ContactQueryDesiredFields * value) = 0;
    virtual HRESULT __stdcall put_DesiredFields(winrt::Windows::ApplicationModel::Contacts::ContactQueryDesiredFields value) = 0;
    virtual HRESULT __stdcall get_DesiredOperations(winrt::Windows::ApplicationModel::Contacts::ContactAnnotationOperations * value) = 0;
    virtual HRESULT __stdcall put_DesiredOperations(winrt::Windows::ApplicationModel::Contacts::ContactAnnotationOperations value) = 0;
    virtual HRESULT __stdcall get_AnnotationListIds(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
};

struct __declspec(uuid("543fba47-8ce7-46cb-9dac-9aa42a1bc8e2")) __declspec(novtable) IContactQueryOptionsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWithText(hstring text, Windows::ApplicationModel::Contacts::IContactQueryOptions ** result) = 0;
    virtual HRESULT __stdcall abi_CreateWithTextAndFields(hstring text, winrt::Windows::ApplicationModel::Contacts::ContactQuerySearchFields fields, Windows::ApplicationModel::Contacts::IContactQueryOptions ** result) = 0;
};

struct __declspec(uuid("f7e3f9cb-a957-439b-a0b7-1c02a1963ff0")) __declspec(novtable) IContactQueryTextSearch : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Fields(winrt::Windows::ApplicationModel::Contacts::ContactQuerySearchFields * value) = 0;
    virtual HRESULT __stdcall put_Fields(winrt::Windows::ApplicationModel::Contacts::ContactQuerySearchFields value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall put_Text(hstring value) = 0;
    virtual HRESULT __stdcall get_SearchScope(winrt::Windows::ApplicationModel::Contacts::ContactQuerySearchScope * value) = 0;
    virtual HRESULT __stdcall put_SearchScope(winrt::Windows::ApplicationModel::Contacts::ContactQuerySearchScope value) = 0;
};

struct __declspec(uuid("d397e42e-1488-42f2-bf64-253f4884bfed")) __declspec(novtable) IContactReader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ReadBatchAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactBatch> ** value) = 0;
    virtual HRESULT __stdcall abi_GetMatchingPropertiesWithMatchReason(Windows::ApplicationModel::Contacts::IContact * contact, Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactMatchReason> ** ppRetVal) = 0;
};

struct __declspec(uuid("8873b5ab-c5fb-46d8-93fe-da3ff1934054")) __declspec(novtable) IContactSignificantOther : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall put_Name(hstring value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall put_Description(hstring value) = 0;
};

struct __declspec(uuid("8d7bd474-3f03-45f8-ba0f-c4ed37d64219")) __declspec(novtable) IContactSignificantOther2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Relationship(winrt::Windows::ApplicationModel::Contacts::ContactRelationship * value) = 0;
    virtual HRESULT __stdcall put_Relationship(winrt::Windows::ApplicationModel::Contacts::ContactRelationship value) = 0;
};

struct __declspec(uuid("2c220b10-3a6c-4293-b9bc-fe987f6e0d52")) __declspec(novtable) IContactStore : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindContactsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact>> ** contacts) = 0;
    virtual HRESULT __stdcall abi_FindContactsWithSearchTextAsync(hstring searchText, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact>> ** contacts) = 0;
    virtual HRESULT __stdcall abi_GetContactAsync(hstring contactId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> ** contacts) = 0;
};

struct __declspec(uuid("18ce1c22-ebd5-4bfb-b690-5f4f27c4f0e8")) __declspec(novtable) IContactStore2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ChangeTracker(Windows::ApplicationModel::Contacts::IContactChangeTracker ** value) = 0;
    virtual HRESULT __stdcall add_ContactChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactStore, Windows::ApplicationModel::Contacts::ContactChangedEventArgs> * value, event_token * returnValue) = 0;
    virtual HRESULT __stdcall remove_ContactChanged(event_token value) = 0;
    virtual HRESULT __stdcall get_AggregateContactManager(Windows::ApplicationModel::Contacts::IAggregateContactManager ** value) = 0;
    virtual HRESULT __stdcall abi_FindContactListsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactList>> ** value) = 0;
    virtual HRESULT __stdcall abi_GetContactListAsync(hstring contactListId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactList> ** value) = 0;
    virtual HRESULT __stdcall abi_CreateContactListAsync(hstring displayName, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactList> ** value) = 0;
    virtual HRESULT __stdcall abi_GetMeContactAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> ** meContact) = 0;
    virtual HRESULT __stdcall abi_GetContactReader(Windows::ApplicationModel::Contacts::IContactReader ** value) = 0;
    virtual HRESULT __stdcall abi_GetContactReaderWithOptions(Windows::ApplicationModel::Contacts::IContactQueryOptions * options, Windows::ApplicationModel::Contacts::IContactReader ** value) = 0;
    virtual HRESULT __stdcall abi_CreateContactListInAccountAsync(hstring displayName, hstring userDataAccountId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactList> ** value) = 0;
};

struct __declspec(uuid("abb298d6-878a-4f8b-a9ce-46bb7d1c84ce")) __declspec(novtable) IContactStoreNotificationTriggerDetails : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("9f130176-dc1b-4055-ad66-652f39d990e8")) __declspec(novtable) IContactWebsite : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_Uri(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall put_Description(hstring value) = 0;
};

struct __declspec(uuid("f87ee91e-5647-4068-bb5e-4b6f437ce308")) __declspec(novtable) IContactWebsite2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RawValue(hstring * value) = 0;
    virtual HRESULT __stdcall put_RawValue(hstring value) = 0;
};

struct __declspec(uuid("8744436c-5cf9-4683-bdca-a1fdebf8dbce")) __declspec(novtable) IFullContactCardOptions : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DesiredRemainingView(winrt::Windows::UI::ViewManagement::ViewSizePreference * value) = 0;
    virtual HRESULT __stdcall put_DesiredRemainingView(winrt::Windows::UI::ViewManagement::ViewSizePreference value) = 0;
};

struct __declspec(uuid("2e0e1b12-d627-4fca-bad4-1faf168c7d14")) __declspec(novtable) IKnownContactFieldStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Email(hstring * value) = 0;
    virtual HRESULT __stdcall get_PhoneNumber(hstring * value) = 0;
    virtual HRESULT __stdcall get_Location(hstring * value) = 0;
    virtual HRESULT __stdcall get_InstantMessage(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ConvertNameToType(hstring name, winrt::Windows::ApplicationModel::Contacts::ContactFieldType * type) = 0;
    virtual HRESULT __stdcall abi_ConvertTypeToName(winrt::Windows::ApplicationModel::Contacts::ContactFieldType type, hstring * name) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Contacts::AggregateContactManager> { using default_interface = Windows::ApplicationModel::Contacts::IAggregateContactManager; };
template <> struct traits<Windows::ApplicationModel::Contacts::Contact> { using default_interface = Windows::ApplicationModel::Contacts::IContact; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactAddress> { using default_interface = Windows::ApplicationModel::Contacts::IContactAddress; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactAnnotation> { using default_interface = Windows::ApplicationModel::Contacts::IContactAnnotation; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactAnnotationList> { using default_interface = Windows::ApplicationModel::Contacts::IContactAnnotationList; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactAnnotationStore> { using default_interface = Windows::ApplicationModel::Contacts::IContactAnnotationStore; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactBatch> { using default_interface = Windows::ApplicationModel::Contacts::IContactBatch; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactCardDelayedDataLoader> { using default_interface = Windows::ApplicationModel::Contacts::IContactCardDelayedDataLoader; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactCardOptions> { using default_interface = Windows::ApplicationModel::Contacts::IContactCardOptions; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactChange> { using default_interface = Windows::ApplicationModel::Contacts::IContactChange; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactChangeReader> { using default_interface = Windows::ApplicationModel::Contacts::IContactChangeReader; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactChangeTracker> { using default_interface = Windows::ApplicationModel::Contacts::IContactChangeTracker; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactChangedDeferral> { using default_interface = Windows::ApplicationModel::Contacts::IContactChangedDeferral; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactChangedEventArgs> { using default_interface = Windows::ApplicationModel::Contacts::IContactChangedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactConnectedServiceAccount> { using default_interface = Windows::ApplicationModel::Contacts::IContactConnectedServiceAccount; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactDate> { using default_interface = Windows::ApplicationModel::Contacts::IContactDate; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactEmail> { using default_interface = Windows::ApplicationModel::Contacts::IContactEmail; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactField> { using default_interface = Windows::ApplicationModel::Contacts::IContactField; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactFieldFactory> { using default_interface = Windows::ApplicationModel::Contacts::IContactFieldFactory; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactInformation> { using default_interface = Windows::ApplicationModel::Contacts::IContactInformation; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactInstantMessageField> { using default_interface = Windows::ApplicationModel::Contacts::IContactInstantMessageField; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactJobInfo> { using default_interface = Windows::ApplicationModel::Contacts::IContactJobInfo; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactList> { using default_interface = Windows::ApplicationModel::Contacts::IContactList; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactListSyncConstraints> { using default_interface = Windows::ApplicationModel::Contacts::IContactListSyncConstraints; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactListSyncManager> { using default_interface = Windows::ApplicationModel::Contacts::IContactListSyncManager; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactLocationField> { using default_interface = Windows::ApplicationModel::Contacts::IContactLocationField; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactManagerForUser> { using default_interface = Windows::ApplicationModel::Contacts::IContactManagerForUser; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactMatchReason> { using default_interface = Windows::ApplicationModel::Contacts::IContactMatchReason; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactPhone> { using default_interface = Windows::ApplicationModel::Contacts::IContactPhone; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactPicker> { using default_interface = Windows::ApplicationModel::Contacts::IContactPicker; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactQueryOptions> { using default_interface = Windows::ApplicationModel::Contacts::IContactQueryOptions; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactQueryTextSearch> { using default_interface = Windows::ApplicationModel::Contacts::IContactQueryTextSearch; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactReader> { using default_interface = Windows::ApplicationModel::Contacts::IContactReader; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactSignificantOther> { using default_interface = Windows::ApplicationModel::Contacts::IContactSignificantOther; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactStore> { using default_interface = Windows::ApplicationModel::Contacts::IContactStore; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactStoreNotificationTriggerDetails> { using default_interface = Windows::ApplicationModel::Contacts::IContactStoreNotificationTriggerDetails; };
template <> struct traits<Windows::ApplicationModel::Contacts::ContactWebsite> { using default_interface = Windows::ApplicationModel::Contacts::IContactWebsite; };
template <> struct traits<Windows::ApplicationModel::Contacts::FullContactCardOptions> { using default_interface = Windows::ApplicationModel::Contacts::IFullContactCardOptions; };

}

namespace Windows::ApplicationModel::Contacts {

template <typename D>
struct WINRT_EBO impl_IAggregateContactManager
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact>> FindRawContactsAsync(const Windows::ApplicationModel::Contacts::Contact & contact) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> TryLinkContactsAsync(const Windows::ApplicationModel::Contacts::Contact & primaryContact, const Windows::ApplicationModel::Contacts::Contact & secondaryContact) const;
    Windows::Foundation::IAsyncAction UnlinkRawContactAsync(const Windows::ApplicationModel::Contacts::Contact & contact) const;
    Windows::Foundation::IAsyncOperation<bool> TrySetPreferredSourceForPictureAsync(const Windows::ApplicationModel::Contacts::Contact & aggregateContact, const Windows::ApplicationModel::Contacts::Contact & rawContact) const;
};

template <typename D>
struct WINRT_EBO impl_IAggregateContactManager2
{
    Windows::Foundation::IAsyncAction SetRemoteIdentificationInformationAsync(hstring_view contactListId, hstring_view remoteSourceId, hstring_view accountId) const;
};

template <typename D>
struct WINRT_EBO impl_IContact
{
    hstring Name() const;
    void Name(hstring_view value) const;
    Windows::Storage::Streams::IRandomAccessStreamReference Thumbnail() const;
    void Thumbnail(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::IContactField> Fields() const;
};

template <typename D>
struct WINRT_EBO impl_IContact2
{
    hstring Id() const;
    void Id(hstring_view value) const;
    hstring Notes() const;
    void Notes(hstring_view value) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactPhone> Phones() const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactEmail> Emails() const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactAddress> Addresses() const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactConnectedServiceAccount> ConnectedServiceAccounts() const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactDate> ImportantDates() const;
    Windows::Foundation::Collections::IVector<hstring> DataSuppliers() const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactJobInfo> JobInfo() const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactSignificantOther> SignificantOthers() const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::ContactWebsite> Websites() const;
    Windows::Foundation::Collections::IPropertySet ProviderProperties() const;
};

template <typename D>
struct WINRT_EBO impl_IContact3
{
    hstring ContactListId() const;
    Windows::Foundation::DateTime DisplayPictureUserUpdateTime() const;
    void DisplayPictureUserUpdateTime(const Windows::Foundation::DateTime & value) const;
    bool IsMe() const;
    hstring AggregateId() const;
    hstring RemoteId() const;
    void RemoteId(hstring_view value) const;
    hstring RingToneToken() const;
    void RingToneToken(hstring_view value) const;
    bool IsDisplayPictureManuallySet() const;
    Windows::Storage::Streams::IRandomAccessStreamReference LargeDisplayPicture() const;
    Windows::Storage::Streams::IRandomAccessStreamReference SmallDisplayPicture() const;
    Windows::Storage::Streams::IRandomAccessStreamReference SourceDisplayPicture() const;
    void SourceDisplayPicture(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
    hstring TextToneToken() const;
    void TextToneToken(hstring_view value) const;
    bool IsAggregate() const;
    hstring FullName() const;
    hstring DisplayNameOverride() const;
    void DisplayNameOverride(hstring_view value) const;
    hstring Nickname() const;
    void Nickname(hstring_view value) const;
    hstring SortName() const;
};

template <typename D>
struct WINRT_EBO impl_IContactAddress
{
    hstring StreetAddress() const;
    void StreetAddress(hstring_view value) const;
    hstring Locality() const;
    void Locality(hstring_view value) const;
    hstring Region() const;
    void Region(hstring_view value) const;
    hstring Country() const;
    void Country(hstring_view value) const;
    hstring PostalCode() const;
    void PostalCode(hstring_view value) const;
    Windows::ApplicationModel::Contacts::ContactAddressKind Kind() const;
    void Kind(Windows::ApplicationModel::Contacts::ContactAddressKind value) const;
    hstring Description() const;
    void Description(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IContactAnnotation
{
    hstring Id() const;
    hstring AnnotationListId() const;
    hstring ContactId() const;
    void ContactId(hstring_view value) const;
    hstring RemoteId() const;
    void RemoteId(hstring_view value) const;
    Windows::ApplicationModel::Contacts::ContactAnnotationOperations SupportedOperations() const;
    void SupportedOperations(Windows::ApplicationModel::Contacts::ContactAnnotationOperations value) const;
    bool IsDisabled() const;
    Windows::Foundation::Collections::ValueSet ProviderProperties() const;
};

template <typename D>
struct WINRT_EBO impl_IContactAnnotationList
{
    hstring Id() const;
    hstring ProviderPackageFamilyName() const;
    hstring UserDataAccountId() const;
    Windows::Foundation::IAsyncAction DeleteAsync() const;
    Windows::Foundation::IAsyncOperation<bool> TrySaveAnnotationAsync(const Windows::ApplicationModel::Contacts::ContactAnnotation & annotation) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotation> GetAnnotationAsync(hstring_view annotationId) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotation>> FindAnnotationsByRemoteIdAsync(hstring_view remoteId) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotation>> FindAnnotationsAsync() const;
    Windows::Foundation::IAsyncAction DeleteAnnotationAsync(const Windows::ApplicationModel::Contacts::ContactAnnotation & annotation) const;
};

template <typename D>
struct WINRT_EBO impl_IContactAnnotationStore
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> FindContactIdsByEmailAsync(hstring_view emailAddress) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> FindContactIdsByPhoneNumberAsync(hstring_view phoneNumber) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotation>> FindAnnotationsForContactAsync(const Windows::ApplicationModel::Contacts::Contact & contact) const;
    Windows::Foundation::IAsyncAction DisableAnnotationAsync(const Windows::ApplicationModel::Contacts::ContactAnnotation & annotation) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationList> CreateAnnotationListAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationList> CreateAnnotationListAsync(hstring_view userDataAccountId) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationList> GetAnnotationListAsync(hstring_view annotationListId) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotationList>> FindAnnotationListsAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IContactBatch
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact> Contacts() const;
    Windows::ApplicationModel::Contacts::ContactBatchStatus Status() const;
};

template <typename D>
struct WINRT_EBO impl_IContactCardDelayedDataLoader
{
    void SetData(const Windows::ApplicationModel::Contacts::Contact & contact) const;
};

template <typename D>
struct WINRT_EBO impl_IContactCardOptions
{
    Windows::ApplicationModel::Contacts::ContactCardHeaderKind HeaderKind() const;
    void HeaderKind(Windows::ApplicationModel::Contacts::ContactCardHeaderKind value) const;
    Windows::ApplicationModel::Contacts::ContactCardTabKind InitialTabKind() const;
    void InitialTabKind(Windows::ApplicationModel::Contacts::ContactCardTabKind value) const;
};

template <typename D>
struct WINRT_EBO impl_IContactCardOptions2
{
    Windows::Foundation::Collections::IVector<hstring> ServerSearchContactListIds() const;
};

template <typename D>
struct WINRT_EBO impl_IContactChange
{
    Windows::ApplicationModel::Contacts::ContactChangeType ChangeType() const;
    Windows::ApplicationModel::Contacts::Contact Contact() const;
};

template <typename D>
struct WINRT_EBO impl_IContactChangeReader
{
    void AcceptChanges() const;
    void AcceptChangesThrough(const Windows::ApplicationModel::Contacts::ContactChange & lastChangeToAccept) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactChange>> ReadBatchAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IContactChangeTracker
{
    void Enable() const;
    Windows::ApplicationModel::Contacts::ContactChangeReader GetChangeReader() const;
    void Reset() const;
};

template <typename D>
struct WINRT_EBO impl_IContactChangedDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IContactChangedEventArgs
{
    Windows::ApplicationModel::Contacts::ContactChangedDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IContactConnectedServiceAccount
{
    hstring Id() const;
    void Id(hstring_view value) const;
    hstring ServiceName() const;
    void ServiceName(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IContactDate
{
    Windows::Foundation::IReference<uint32_t> Day() const;
    void Day(const optional<uint32_t> & value) const;
    Windows::Foundation::IReference<uint32_t> Month() const;
    void Month(const optional<uint32_t> & value) const;
    Windows::Foundation::IReference<int32_t> Year() const;
    void Year(const optional<int32_t> & value) const;
    Windows::ApplicationModel::Contacts::ContactDateKind Kind() const;
    void Kind(Windows::ApplicationModel::Contacts::ContactDateKind value) const;
    hstring Description() const;
    void Description(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IContactEmail
{
    hstring Address() const;
    void Address(hstring_view value) const;
    Windows::ApplicationModel::Contacts::ContactEmailKind Kind() const;
    void Kind(Windows::ApplicationModel::Contacts::ContactEmailKind value) const;
    hstring Description() const;
    void Description(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IContactField
{
    Windows::ApplicationModel::Contacts::ContactFieldType Type() const;
    Windows::ApplicationModel::Contacts::ContactFieldCategory Category() const;
    hstring Name() const;
    hstring Value() const;
};

template <typename D>
struct WINRT_EBO impl_IContactFieldFactory
{
    Windows::ApplicationModel::Contacts::ContactField CreateField(hstring_view value, Windows::ApplicationModel::Contacts::ContactFieldType type) const;
    Windows::ApplicationModel::Contacts::ContactField CreateField(hstring_view value, Windows::ApplicationModel::Contacts::ContactFieldType type, Windows::ApplicationModel::Contacts::ContactFieldCategory category) const;
    Windows::ApplicationModel::Contacts::ContactField CreateField(hstring_view name, hstring_view value, Windows::ApplicationModel::Contacts::ContactFieldType type, Windows::ApplicationModel::Contacts::ContactFieldCategory category) const;
};

template <typename D>
struct WINRT_EBO impl_IContactInformation
{
    hstring Name() const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> GetThumbnailAsync() const;
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField> Emails() const;
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField> PhoneNumbers() const;
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactLocationField> Locations() const;
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactInstantMessageField> InstantMessages() const;
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField> CustomFields() const;
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactField> QueryCustomFields(hstring_view customName) const;
};

template <typename D>
struct WINRT_EBO impl_IContactInstantMessageField
{
    hstring UserName() const;
    hstring Service() const;
    hstring DisplayText() const;
    Windows::Foundation::Uri LaunchUri() const;
};

template <typename D>
struct WINRT_EBO impl_IContactInstantMessageFieldFactory
{
    Windows::ApplicationModel::Contacts::ContactInstantMessageField CreateInstantMessage(hstring_view userName) const;
    Windows::ApplicationModel::Contacts::ContactInstantMessageField CreateInstantMessage(hstring_view userName, Windows::ApplicationModel::Contacts::ContactFieldCategory category) const;
    Windows::ApplicationModel::Contacts::ContactInstantMessageField CreateInstantMessage(hstring_view userName, Windows::ApplicationModel::Contacts::ContactFieldCategory category, hstring_view service, hstring_view displayText, const Windows::Foundation::Uri & verb) const;
};

template <typename D>
struct WINRT_EBO impl_IContactJobInfo
{
    hstring CompanyName() const;
    void CompanyName(hstring_view value) const;
    hstring CompanyYomiName() const;
    void CompanyYomiName(hstring_view value) const;
    hstring Department() const;
    void Department(hstring_view value) const;
    hstring Title() const;
    void Title(hstring_view value) const;
    hstring Manager() const;
    void Manager(hstring_view value) const;
    hstring Office() const;
    void Office(hstring_view value) const;
    hstring CompanyAddress() const;
    void CompanyAddress(hstring_view value) const;
    hstring Description() const;
    void Description(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IContactLaunchActionVerbsStatics
{
    hstring Call() const;
    hstring Message() const;
    hstring Map() const;
    hstring Post() const;
    hstring VideoCall() const;
};

template <typename D>
struct WINRT_EBO impl_IContactList
{
    hstring Id() const;
    hstring DisplayName() const;
    void DisplayName(hstring_view value) const;
    hstring SourceDisplayName() const;
    bool IsHidden() const;
    void IsHidden(bool value) const;
    Windows::ApplicationModel::Contacts::ContactListOtherAppReadAccess OtherAppReadAccess() const;
    void OtherAppReadAccess(Windows::ApplicationModel::Contacts::ContactListOtherAppReadAccess value) const;
    Windows::ApplicationModel::Contacts::ContactListOtherAppWriteAccess OtherAppWriteAccess() const;
    void OtherAppWriteAccess(Windows::ApplicationModel::Contacts::ContactListOtherAppWriteAccess value) const;
    Windows::ApplicationModel::Contacts::ContactChangeTracker ChangeTracker() const;
    Windows::ApplicationModel::Contacts::ContactListSyncManager SyncManager() const;
    bool SupportsServerSearch() const;
    hstring UserDataAccountId() const;
    event_token ContactChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactList, Windows::ApplicationModel::Contacts::ContactChangedEventArgs> & value) const;
    using ContactChanged_revoker = event_revoker<IContactList>;
    ContactChanged_revoker ContactChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactList, Windows::ApplicationModel::Contacts::ContactChangedEventArgs> & value) const;
    void ContactChanged(event_token value) const;
    Windows::Foundation::IAsyncAction SaveAsync() const;
    Windows::Foundation::IAsyncAction DeleteAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> GetContactFromRemoteIdAsync(hstring_view remoteId) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> GetMeContactAsync() const;
    Windows::ApplicationModel::Contacts::ContactReader GetContactReader() const;
    Windows::ApplicationModel::Contacts::ContactReader GetContactReader(const Windows::ApplicationModel::Contacts::ContactQueryOptions & options) const;
    Windows::Foundation::IAsyncAction SaveContactAsync(const Windows::ApplicationModel::Contacts::Contact & contact) const;
    Windows::Foundation::IAsyncAction DeleteContactAsync(const Windows::ApplicationModel::Contacts::Contact & contact) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> GetContactAsync(hstring_view contactId) const;
};

template <typename D>
struct WINRT_EBO impl_IContactList2
{
    Windows::Foundation::IAsyncAction RegisterSyncManagerAsync() const;
    void SupportsServerSearch(bool value) const;
    Windows::ApplicationModel::Contacts::ContactListSyncConstraints SyncConstraints() const;
};

template <typename D>
struct WINRT_EBO impl_IContactListSyncConstraints
{
    bool CanSyncDescriptions() const;
    void CanSyncDescriptions(bool value) const;
    Windows::Foundation::IReference<int32_t> MaxHomePhoneNumbers() const;
    void MaxHomePhoneNumbers(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxMobilePhoneNumbers() const;
    void MaxMobilePhoneNumbers(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxWorkPhoneNumbers() const;
    void MaxWorkPhoneNumbers(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxOtherPhoneNumbers() const;
    void MaxOtherPhoneNumbers(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxPagerPhoneNumbers() const;
    void MaxPagerPhoneNumbers(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxBusinessFaxPhoneNumbers() const;
    void MaxBusinessFaxPhoneNumbers(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxHomeFaxPhoneNumbers() const;
    void MaxHomeFaxPhoneNumbers(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxCompanyPhoneNumbers() const;
    void MaxCompanyPhoneNumbers(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxAssistantPhoneNumbers() const;
    void MaxAssistantPhoneNumbers(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxRadioPhoneNumbers() const;
    void MaxRadioPhoneNumbers(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxPersonalEmailAddresses() const;
    void MaxPersonalEmailAddresses(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxWorkEmailAddresses() const;
    void MaxWorkEmailAddresses(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxOtherEmailAddresses() const;
    void MaxOtherEmailAddresses(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxHomeAddresses() const;
    void MaxHomeAddresses(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxWorkAddresses() const;
    void MaxWorkAddresses(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxOtherAddresses() const;
    void MaxOtherAddresses(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxBirthdayDates() const;
    void MaxBirthdayDates(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxAnniversaryDates() const;
    void MaxAnniversaryDates(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxOtherDates() const;
    void MaxOtherDates(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxOtherRelationships() const;
    void MaxOtherRelationships(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxSpouseRelationships() const;
    void MaxSpouseRelationships(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxPartnerRelationships() const;
    void MaxPartnerRelationships(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxSiblingRelationships() const;
    void MaxSiblingRelationships(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxParentRelationships() const;
    void MaxParentRelationships(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxChildRelationships() const;
    void MaxChildRelationships(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxJobInfo() const;
    void MaxJobInfo(const optional<int32_t> & value) const;
    Windows::Foundation::IReference<int32_t> MaxWebsites() const;
    void MaxWebsites(const optional<int32_t> & value) const;
};

template <typename D>
struct WINRT_EBO impl_IContactListSyncManager
{
    Windows::ApplicationModel::Contacts::ContactListSyncStatus Status() const;
    Windows::Foundation::DateTime LastSuccessfulSyncTime() const;
    Windows::Foundation::DateTime LastAttemptedSyncTime() const;
    Windows::Foundation::IAsyncOperation<bool> SyncAsync() const;
    event_token SyncStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactListSyncManager, Windows::Foundation::IInspectable> & handler) const;
    using SyncStatusChanged_revoker = event_revoker<IContactListSyncManager>;
    SyncStatusChanged_revoker SyncStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactListSyncManager, Windows::Foundation::IInspectable> & handler) const;
    void SyncStatusChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IContactListSyncManager2
{
    void Status(Windows::ApplicationModel::Contacts::ContactListSyncStatus value) const;
    void LastSuccessfulSyncTime(const Windows::Foundation::DateTime & value) const;
    void LastAttemptedSyncTime(const Windows::Foundation::DateTime & value) const;
};

template <typename D>
struct WINRT_EBO impl_IContactLocationField
{
    hstring UnstructuredAddress() const;
    hstring Street() const;
    hstring City() const;
    hstring Region() const;
    hstring Country() const;
    hstring PostalCode() const;
};

template <typename D>
struct WINRT_EBO impl_IContactLocationFieldFactory
{
    Windows::ApplicationModel::Contacts::ContactLocationField CreateLocation(hstring_view unstructuredAddress) const;
    Windows::ApplicationModel::Contacts::ContactLocationField CreateLocation(hstring_view unstructuredAddress, Windows::ApplicationModel::Contacts::ContactFieldCategory category) const;
    Windows::ApplicationModel::Contacts::ContactLocationField CreateLocation(hstring_view unstructuredAddress, Windows::ApplicationModel::Contacts::ContactFieldCategory category, hstring_view street, hstring_view city, hstring_view region, hstring_view country, hstring_view postalCode) const;
};

template <typename D>
struct WINRT_EBO impl_IContactManagerForUser
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> ConvertContactToVCardAsync(const Windows::ApplicationModel::Contacts::Contact & contact) const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> ConvertContactToVCardAsync(const Windows::ApplicationModel::Contacts::Contact & contact, uint32_t maxBytes) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> ConvertVCardToContactAsync(const Windows::Storage::Streams::IRandomAccessStreamReference & vCard) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore> RequestStoreAsync(Windows::ApplicationModel::Contacts::ContactStoreAccessType accessType) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationStore> RequestAnnotationStoreAsync(Windows::ApplicationModel::Contacts::ContactAnnotationStoreAccessType accessType) const;
    Windows::ApplicationModel::Contacts::ContactNameOrder SystemDisplayNameOrder() const;
    void SystemDisplayNameOrder(Windows::ApplicationModel::Contacts::ContactNameOrder value) const;
    Windows::ApplicationModel::Contacts::ContactNameOrder SystemSortOrder() const;
    void SystemSortOrder(Windows::ApplicationModel::Contacts::ContactNameOrder value) const;
    Windows::System::User User() const;
};

template <typename D>
struct WINRT_EBO impl_IContactManagerStatics
{
    void ShowContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection) const;
    void ShowContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const;
    Windows::ApplicationModel::Contacts::ContactCardDelayedDataLoader ShowDelayLoadedContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const;
};

template <typename D>
struct WINRT_EBO impl_IContactManagerStatics2
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore> RequestStoreAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IContactManagerStatics3
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> ConvertContactToVCardAsync(const Windows::ApplicationModel::Contacts::Contact & contact) const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> ConvertContactToVCardAsync(const Windows::ApplicationModel::Contacts::Contact & contact, uint32_t maxBytes) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> ConvertVCardToContactAsync(const Windows::Storage::Streams::IRandomAccessStreamReference & vCard) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactStore> RequestStoreAsync(Windows::ApplicationModel::Contacts::ContactStoreAccessType accessType) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactAnnotationStore> RequestAnnotationStoreAsync(Windows::ApplicationModel::Contacts::ContactAnnotationStoreAccessType accessType) const;
    bool IsShowContactCardSupported() const;
    void ShowContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::ApplicationModel::Contacts::ContactCardOptions & contactCardOptions) const;
    bool IsShowDelayLoadedContactCardSupported() const;
    Windows::ApplicationModel::Contacts::ContactCardDelayedDataLoader ShowDelayLoadedContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::ApplicationModel::Contacts::ContactCardOptions & contactCardOptions) const;
    void ShowFullContactCard(const Windows::ApplicationModel::Contacts::Contact & contact, const Windows::ApplicationModel::Contacts::FullContactCardOptions & fullContactCardOptions) const;
    Windows::ApplicationModel::Contacts::ContactNameOrder SystemDisplayNameOrder() const;
    void SystemDisplayNameOrder(Windows::ApplicationModel::Contacts::ContactNameOrder value) const;
    Windows::ApplicationModel::Contacts::ContactNameOrder SystemSortOrder() const;
    void SystemSortOrder(Windows::ApplicationModel::Contacts::ContactNameOrder value) const;
};

template <typename D>
struct WINRT_EBO impl_IContactManagerStatics4
{
    Windows::ApplicationModel::Contacts::ContactManagerForUser GetForUser(const Windows::System::User & user) const;
};

template <typename D>
struct WINRT_EBO impl_IContactMatchReason
{
    Windows::ApplicationModel::Contacts::ContactMatchReasonKind Field() const;
    Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment> Segments() const;
    hstring Text() const;
};

template <typename D>
struct WINRT_EBO impl_IContactName
{
    hstring FirstName() const;
    void FirstName(hstring_view value) const;
    hstring LastName() const;
    void LastName(hstring_view value) const;
    hstring MiddleName() const;
    void MiddleName(hstring_view value) const;
    hstring YomiGivenName() const;
    void YomiGivenName(hstring_view value) const;
    hstring YomiFamilyName() const;
    void YomiFamilyName(hstring_view value) const;
    hstring HonorificNameSuffix() const;
    void HonorificNameSuffix(hstring_view value) const;
    hstring HonorificNamePrefix() const;
    void HonorificNamePrefix(hstring_view value) const;
    hstring DisplayName() const;
    hstring YomiDisplayName() const;
};

template <typename D>
struct WINRT_EBO impl_IContactPhone
{
    hstring Number() const;
    void Number(hstring_view value) const;
    Windows::ApplicationModel::Contacts::ContactPhoneKind Kind() const;
    void Kind(Windows::ApplicationModel::Contacts::ContactPhoneKind value) const;
    hstring Description() const;
    void Description(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IContactPicker
{
    hstring CommitButtonText() const;
    void CommitButtonText(hstring_view value) const;
    Windows::ApplicationModel::Contacts::ContactSelectionMode SelectionMode() const;
    void SelectionMode(Windows::ApplicationModel::Contacts::ContactSelectionMode value) const;
    Windows::Foundation::Collections::IVector<hstring> DesiredFields() const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactInformation> PickSingleContactAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactInformation>> PickMultipleContactsAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IContactPicker2
{
    Windows::Foundation::Collections::IVector<winrt::Windows::ApplicationModel::Contacts::ContactFieldType> DesiredFieldsWithContactFieldType() const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> PickContactAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Contacts::Contact>> PickContactsAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IContactQueryOptions
{
    Windows::ApplicationModel::Contacts::ContactQueryTextSearch TextSearch() const;
    Windows::Foundation::Collections::IVector<hstring> ContactListIds() const;
    bool IncludeContactsFromHiddenLists() const;
    void IncludeContactsFromHiddenLists(bool value) const;
    Windows::ApplicationModel::Contacts::ContactQueryDesiredFields DesiredFields() const;
    void DesiredFields(Windows::ApplicationModel::Contacts::ContactQueryDesiredFields value) const;
    Windows::ApplicationModel::Contacts::ContactAnnotationOperations DesiredOperations() const;
    void DesiredOperations(Windows::ApplicationModel::Contacts::ContactAnnotationOperations value) const;
    Windows::Foundation::Collections::IVector<hstring> AnnotationListIds() const;
};

template <typename D>
struct WINRT_EBO impl_IContactQueryOptionsFactory
{
    Windows::ApplicationModel::Contacts::ContactQueryOptions CreateWithText(hstring_view text) const;
    Windows::ApplicationModel::Contacts::ContactQueryOptions CreateWithTextAndFields(hstring_view text, Windows::ApplicationModel::Contacts::ContactQuerySearchFields fields) const;
};

template <typename D>
struct WINRT_EBO impl_IContactQueryTextSearch
{
    Windows::ApplicationModel::Contacts::ContactQuerySearchFields Fields() const;
    void Fields(Windows::ApplicationModel::Contacts::ContactQuerySearchFields value) const;
    hstring Text() const;
    void Text(hstring_view value) const;
    Windows::ApplicationModel::Contacts::ContactQuerySearchScope SearchScope() const;
    void SearchScope(Windows::ApplicationModel::Contacts::ContactQuerySearchScope value) const;
};

template <typename D>
struct WINRT_EBO impl_IContactReader
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactBatch> ReadBatchAsync() const;
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactMatchReason> GetMatchingPropertiesWithMatchReason(const Windows::ApplicationModel::Contacts::Contact & contact) const;
};

template <typename D>
struct WINRT_EBO impl_IContactSignificantOther
{
    hstring Name() const;
    void Name(hstring_view value) const;
    hstring Description() const;
    void Description(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IContactSignificantOther2
{
    Windows::ApplicationModel::Contacts::ContactRelationship Relationship() const;
    void Relationship(Windows::ApplicationModel::Contacts::ContactRelationship value) const;
};

template <typename D>
struct WINRT_EBO impl_IContactStore
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact>> FindContactsAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::Contact>> FindContactsAsync(hstring_view searchText) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> GetContactAsync(hstring_view contactId) const;
};

template <typename D>
struct WINRT_EBO impl_IContactStore2
{
    Windows::ApplicationModel::Contacts::ContactChangeTracker ChangeTracker() const;
    event_token ContactChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactStore, Windows::ApplicationModel::Contacts::ContactChangedEventArgs> & value) const;
    using ContactChanged_revoker = event_revoker<IContactStore2>;
    ContactChanged_revoker ContactChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::ContactStore, Windows::ApplicationModel::Contacts::ContactChangedEventArgs> & value) const;
    void ContactChanged(event_token value) const;
    Windows::ApplicationModel::Contacts::AggregateContactManager AggregateContactManager() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactList>> FindContactListsAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactList> GetContactListAsync(hstring_view contactListId) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactList> CreateContactListAsync(hstring_view displayName) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::Contact> GetMeContactAsync() const;
    Windows::ApplicationModel::Contacts::ContactReader GetContactReader() const;
    Windows::ApplicationModel::Contacts::ContactReader GetContactReader(const Windows::ApplicationModel::Contacts::ContactQueryOptions & options) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Contacts::ContactList> CreateContactListAsync(hstring_view displayName, hstring_view userDataAccountId) const;
};

template <typename D>
struct WINRT_EBO impl_IContactStoreNotificationTriggerDetails
{
};

template <typename D>
struct WINRT_EBO impl_IContactWebsite
{
    Windows::Foundation::Uri Uri() const;
    void Uri(const Windows::Foundation::Uri & value) const;
    hstring Description() const;
    void Description(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IContactWebsite2
{
    hstring RawValue() const;
    void RawValue(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IFullContactCardOptions
{
    Windows::UI::ViewManagement::ViewSizePreference DesiredRemainingView() const;
    void DesiredRemainingView(Windows::UI::ViewManagement::ViewSizePreference value) const;
};

template <typename D>
struct WINRT_EBO impl_IKnownContactFieldStatics
{
    [[deprecated("IKnownContactFieldStatics may be altered or unavailable for releases after Windows 8.1. Instead, use ContactAddress, ContactPhone, ContactConnectedServiceAccount or ContactEmail.")]] hstring Email() const;
    [[deprecated("IKnownContactFieldStatics may be altered or unavailable for releases after Windows 8.1. Instead, use ContactAddress, ContactPhone, ContactConnectedServiceAccount or ContactEmail.")]] hstring PhoneNumber() const;
    [[deprecated("IKnownContactFieldStatics may be altered or unavailable for releases after Windows 8.1. Instead, use ContactAddress, ContactPhone, ContactConnectedServiceAccount or ContactEmail.")]] hstring Location() const;
    [[deprecated("IKnownContactFieldStatics may be altered or unavailable for releases after Windows 8.1. Instead, use ContactAddress, ContactPhone, ContactConnectedServiceAccount or ContactEmail.")]] hstring InstantMessage() const;
    [[deprecated("IKnownContactFieldStatics may be altered or unavailable for releases after Windows 8.1. Instead, use ContactAddress, ContactPhone, ContactConnectedServiceAccount or ContactEmail.")]] Windows::ApplicationModel::Contacts::ContactFieldType ConvertNameToType(hstring_view name) const;
    [[deprecated("IKnownContactFieldStatics may be altered or unavailable for releases after Windows 8.1. Instead, use ContactAddress, ContactPhone, ContactConnectedServiceAccount or ContactEmail.")]] hstring ConvertTypeToName(Windows::ApplicationModel::Contacts::ContactFieldType type) const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Contacts::IAggregateContactManager>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IAggregateContactManager;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IAggregateContactManager<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IAggregateContactManager2>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IAggregateContactManager2;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IAggregateContactManager2<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContact>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContact;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContact<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContact2>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContact2;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContact2<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContact3>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContact3;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContact3<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactAddress>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactAddress;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactAddress<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactAnnotation>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactAnnotation;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactAnnotation<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactAnnotationList>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactAnnotationList;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactAnnotationList<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactAnnotationStore>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactAnnotationStore;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactAnnotationStore<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactBatch>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactBatch;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactBatch<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactCardDelayedDataLoader>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactCardDelayedDataLoader;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactCardDelayedDataLoader<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactCardOptions>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactCardOptions;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactCardOptions<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactCardOptions2>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactCardOptions2;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactCardOptions2<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactChange>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactChange;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactChange<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactChangeReader>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactChangeReader;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactChangeReader<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactChangeTracker>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactChangeTracker;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactChangeTracker<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactChangedDeferral>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactChangedDeferral;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactChangedDeferral<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactChangedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactChangedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactConnectedServiceAccount>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactConnectedServiceAccount;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactConnectedServiceAccount<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactDate>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactDate;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactDate<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactEmail>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactEmail;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactEmail<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactField>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactField;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactField<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactFieldFactory>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactFieldFactory;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactFieldFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactInformation>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactInformation;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactInformation<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactInstantMessageField>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageField;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactInstantMessageField<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactInstantMessageFieldFactory>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageFieldFactory;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactInstantMessageFieldFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactJobInfo>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactJobInfo;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactJobInfo<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactLaunchActionVerbsStatics>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactLaunchActionVerbsStatics;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactLaunchActionVerbsStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactList>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactList;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactList<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactList2>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactList2;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactList2<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactListSyncConstraints>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactListSyncConstraints<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactListSyncManager>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactListSyncManager;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactListSyncManager<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactListSyncManager2>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactListSyncManager2;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactListSyncManager2<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactLocationField>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactLocationField;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactLocationField<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactLocationFieldFactory>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactLocationFieldFactory;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactLocationFieldFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactManagerForUser>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactManagerForUser;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactManagerForUser<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactManagerStatics2>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactManagerStatics2;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactManagerStatics2<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactManagerStatics3>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactManagerStatics3;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactManagerStatics3<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactManagerStatics4>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactManagerStatics4;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactManagerStatics4<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactMatchReason>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactMatchReason;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactMatchReason<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactName>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactName;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactName<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactPhone>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactPhone;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactPhone<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactPicker>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactPicker;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactPicker<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactPicker2>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactPicker2;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactPicker2<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactQueryOptions>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactQueryOptions;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactQueryOptions<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactQueryOptionsFactory>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactQueryOptionsFactory;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactQueryOptionsFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactQueryTextSearch>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactQueryTextSearch;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactQueryTextSearch<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactReader>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactReader;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactReader<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactSignificantOther>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactSignificantOther;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactSignificantOther<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactSignificantOther2>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactSignificantOther2;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactSignificantOther2<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactStore>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactStore;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactStore<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactStore2>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactStore2;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactStore2<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactStoreNotificationTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactStoreNotificationTriggerDetails;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactStoreNotificationTriggerDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactWebsite>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactWebsite;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactWebsite<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IContactWebsite2>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IContactWebsite2;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IContactWebsite2<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IFullContactCardOptions>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IFullContactCardOptions;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IFullContactCardOptions<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::IKnownContactFieldStatics>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::IKnownContactFieldStatics;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::impl_IKnownContactFieldStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::AggregateContactManager>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::AggregateContactManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.AggregateContactManager"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::Contact>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::Contact;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.Contact"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactAddress>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactAddress;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactAddress"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactAnnotation>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactAnnotation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactAnnotation"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactAnnotationList>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactAnnotationList"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactAnnotationStore>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactAnnotationStore;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactAnnotationStore"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactBatch>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactBatch;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactBatch"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactCardDelayedDataLoader>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactCardDelayedDataLoader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactCardDelayedDataLoader"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactCardOptions>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactCardOptions;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactCardOptions"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactChange>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactChange;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactChange"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactChangeReader>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactChangeReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactChangeReader"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactChangeTracker>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactChangeTracker;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactChangeTracker"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactChangedDeferral>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactChangedDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactChangedDeferral"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactChangedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactConnectedServiceAccount>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactConnectedServiceAccount;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactConnectedServiceAccount"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactDate>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactDate;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactDate"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactEmail>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactEmail;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactEmail"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactField>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactField;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactField"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactFieldFactory>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactFieldFactory;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactFieldFactory"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactInformation>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactInformation"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactInstantMessageField>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactInstantMessageField;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactInstantMessageField"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactJobInfo>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactJobInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactJobInfo"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactLaunchActionVerbs>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactLaunchActionVerbs"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactList>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactList;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactList"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactListSyncConstraints>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactListSyncConstraints;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactListSyncConstraints"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactListSyncManager>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactListSyncManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactListSyncManager"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactLocationField>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactLocationField;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactLocationField"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactManager"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactManagerForUser>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactManagerForUser;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactManagerForUser"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactMatchReason>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactMatchReason;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactMatchReason"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactPhone>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactPhone;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactPhone"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactPicker>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactPicker;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactPicker"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactQueryOptions>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactQueryOptions;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactQueryOptions"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactQueryTextSearch>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactQueryTextSearch;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactQueryTextSearch"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactReader>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactReader"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactSignificantOther>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactSignificantOther;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactSignificantOther"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactStore>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactStore;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactStore"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactStoreNotificationTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactStoreNotificationTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactStoreNotificationTriggerDetails"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::ContactWebsite>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::ContactWebsite;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.ContactWebsite"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::FullContactCardOptions>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::FullContactCardOptions;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.FullContactCardOptions"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::KnownContactField>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.KnownContactField"; }
};

}

}
