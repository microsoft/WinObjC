// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.DataTransfer.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Security.EnterpriseData.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.UI.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Storage.Streams.1.h"
#include "Windows.Storage.1.h"
#include "Windows.Security.EnterpriseData.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::DataTransfer {

struct __declspec(uuid("e7ecd720-f2f4-4a2d-920e-170a2f482a27")) __declspec(novtable) DataProviderHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::ApplicationModel::DataTransfer::IDataProviderRequest * request) = 0;
};

struct __declspec(uuid("c627e291-34e2-4963-8eed-93cbb0ea3d70")) __declspec(novtable) IClipboardStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetContent(Windows::ApplicationModel::DataTransfer::IDataPackageView ** content) = 0;
    virtual HRESULT __stdcall abi_SetContent(Windows::ApplicationModel::DataTransfer::IDataPackage * content) = 0;
    virtual HRESULT __stdcall abi_Flush() = 0;
    virtual HRESULT __stdcall abi_Clear() = 0;
    virtual HRESULT __stdcall add_ContentChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * changeHandler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ContentChanged(event_token token) = 0;
};

struct __declspec(uuid("61ebf5c7-efea-4346-9554-981d7e198ffe")) __declspec(novtable) IDataPackage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetView(Windows::ApplicationModel::DataTransfer::IDataPackageView ** value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet ** value) = 0;
    virtual HRESULT __stdcall get_RequestedOperation(winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) = 0;
    virtual HRESULT __stdcall put_RequestedOperation(winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation value) = 0;
    virtual HRESULT __stdcall add_OperationCompleted(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataPackage, Windows::ApplicationModel::DataTransfer::OperationCompletedEventArgs> * handler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_OperationCompleted(event_token eventCookie) = 0;
    virtual HRESULT __stdcall add_Destroyed(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataPackage, Windows::Foundation::IInspectable> * handler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_Destroyed(event_token eventCookie) = 0;
    virtual HRESULT __stdcall abi_SetData(hstring formatId, Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall abi_SetDataProvider(hstring formatId, Windows::ApplicationModel::DataTransfer::DataProviderHandler * delayRenderer) = 0;
    virtual HRESULT __stdcall abi_SetText(hstring value) = 0;
    virtual HRESULT __stdcall abi_SetUri(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall abi_SetHtmlFormat(hstring value) = 0;
    virtual HRESULT __stdcall get_ResourceMap(Windows::Foundation::Collections::IMap<hstring, Windows::Storage::Streams::RandomAccessStreamReference> ** value) = 0;
    virtual HRESULT __stdcall abi_SetRtf(hstring value) = 0;
    virtual HRESULT __stdcall abi_SetBitmap(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall abi_SetStorageItemsReadOnly(Windows::Foundation::Collections::IIterable<Windows::Storage::IStorageItem> * value) = 0;
    virtual HRESULT __stdcall abi_SetStorageItems(Windows::Foundation::Collections::IIterable<Windows::Storage::IStorageItem> * value, bool readOnly) = 0;
};

struct __declspec(uuid("041c1fe9-2409-45e1-a538-4c53eeee04a7")) __declspec(novtable) IDataPackage2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetApplicationLink(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall abi_SetWebLink(Windows::Foundation::IUriRuntimeClass * value) = 0;
};

struct __declspec(uuid("cd1c93eb-4c4c-443a-a8d3-f5c241e91689")) __declspec(novtable) IDataPackagePropertySet : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall put_Title(hstring value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall put_Description(hstring value) = 0;
    virtual HRESULT __stdcall get_Thumbnail(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_Thumbnail(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall get_FileTypes(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_ApplicationName(hstring * value) = 0;
    virtual HRESULT __stdcall put_ApplicationName(hstring value) = 0;
    virtual HRESULT __stdcall get_ApplicationListingUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_ApplicationListingUri(Windows::Foundation::IUriRuntimeClass * value) = 0;
};

struct __declspec(uuid("eb505d4a-9800-46aa-b181-7b6f0f2b919a")) __declspec(novtable) IDataPackagePropertySet2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContentSourceWebLink(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_ContentSourceWebLink(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_ContentSourceApplicationLink(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_ContentSourceApplicationLink(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_PackageFamilyName(hstring * value) = 0;
    virtual HRESULT __stdcall put_PackageFamilyName(hstring value) = 0;
    virtual HRESULT __stdcall get_Square30x30Logo(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_Square30x30Logo(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall get_LogoBackgroundColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_LogoBackgroundColor(Windows::UI::Color value) = 0;
};

struct __declspec(uuid("9e87fd9b-5205-401b-874a-455653bd39e8")) __declspec(novtable) IDataPackagePropertySet3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EnterpriseId(hstring * value) = 0;
    virtual HRESULT __stdcall put_EnterpriseId(hstring value) = 0;
};

struct __declspec(uuid("b94cec01-0c1a-4c57-be55-75d01289735d")) __declspec(novtable) IDataPackagePropertySetView : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall get_Thumbnail(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall get_FileTypes(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_ApplicationName(hstring * value) = 0;
    virtual HRESULT __stdcall get_ApplicationListingUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
};

struct __declspec(uuid("6054509b-8ebe-4feb-9c1e-75e69de54b84")) __declspec(novtable) IDataPackagePropertySetView2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PackageFamilyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_ContentSourceWebLink(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_ContentSourceApplicationLink(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_Square30x30Logo(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall get_LogoBackgroundColor(Windows::UI::Color * value) = 0;
};

struct __declspec(uuid("db764ce5-d174-495c-84fc-1a51f6ab45d7")) __declspec(novtable) IDataPackagePropertySetView3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EnterpriseId(hstring * value) = 0;
};

struct __declspec(uuid("7b840471-5900-4d85-a90b-10cb85fe3552")) __declspec(novtable) IDataPackageView : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Properties(Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView ** value) = 0;
    virtual HRESULT __stdcall get_RequestedOperation(winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) = 0;
    virtual HRESULT __stdcall abi_ReportOperationCompleted(winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation value) = 0;
    virtual HRESULT __stdcall get_AvailableFormats(Windows::Foundation::Collections::IVectorView<hstring> ** formatIds) = 0;
    virtual HRESULT __stdcall abi_Contains(hstring formatId, bool * value) = 0;
    virtual HRESULT __stdcall abi_GetDataAsync(hstring formatId, Windows::Foundation::IAsyncOperation<Windows::Foundation::IInspectable> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetTextAsync(Windows::Foundation::IAsyncOperation<hstring> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetCustomTextAsync(hstring formatId, Windows::Foundation::IAsyncOperation<hstring> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetUriAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Uri> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetHtmlFormatAsync(Windows::Foundation::IAsyncOperation<hstring> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetResourceMapAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Storage::Streams::RandomAccessStreamReference>> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetRtfAsync(Windows::Foundation::IAsyncOperation<hstring> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetBitmapAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetStorageItemsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> ** operation) = 0;
};

struct __declspec(uuid("40ecba95-2450-4c1d-b6b4-ed45463dee9c")) __declspec(novtable) IDataPackageView2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetApplicationLinkAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Uri> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetWebLinkAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Uri> ** operation) = 0;
};

struct __declspec(uuid("d37771a8-ddad-4288-8428-d1cae394128b")) __declspec(novtable) IDataPackageView3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestAccessAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> ** operation) = 0;
    virtual HRESULT __stdcall abi_RequestAccessWithEnterpriseIdAsync(hstring enterpriseId, Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> ** operation) = 0;
    virtual HRESULT __stdcall abi_UnlockAndAssumeEnterpriseIdentity(winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult * result) = 0;
};

struct __declspec(uuid("dfe96f1f-e042-4433-a09f-26d6ffda8b85")) __declspec(novtable) IDataPackageView4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetAcceptedFormatId(hstring formatId) = 0;
};

struct __declspec(uuid("c2cf2373-2d26-43d9-b69d-dcb86d03f6da")) __declspec(novtable) IDataProviderDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("ebbc7157-d3c8-47da-acde-f82388d5f716")) __declspec(novtable) IDataProviderRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FormatId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Deadline(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::ApplicationModel::DataTransfer::IDataProviderDeferral ** value) = 0;
    virtual HRESULT __stdcall abi_SetData(Windows::Foundation::IInspectable * value) = 0;
};

struct __declspec(uuid("4341ae3b-fc12-4e53-8c02-ac714c415a27")) __declspec(novtable) IDataRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Data(Windows::ApplicationModel::DataTransfer::IDataPackage ** value) = 0;
    virtual HRESULT __stdcall put_Data(Windows::ApplicationModel::DataTransfer::IDataPackage * value) = 0;
    virtual HRESULT __stdcall get_Deadline(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall abi_FailWithDisplayText(hstring value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::ApplicationModel::DataTransfer::IDataRequestDeferral ** value) = 0;
};

struct __declspec(uuid("6dc4b89f-0386-4263-87c1-ed7dce30890e")) __declspec(novtable) IDataRequestDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("cb8ba807-6ac5-43c9-8ac5-9ba232163182")) __declspec(novtable) IDataRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::DataTransfer::IDataRequest ** value) = 0;
};

struct __declspec(uuid("a5caee9b-8708-49d1-8d36-67d25a8da00c")) __declspec(novtable) IDataTransferManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_DataRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataTransferManager, Windows::ApplicationModel::DataTransfer::DataRequestedEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_DataRequested(event_token eventCookie) = 0;
    virtual HRESULT __stdcall add_TargetApplicationChosen(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataTransferManager, Windows::ApplicationModel::DataTransfer::TargetApplicationChosenEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_TargetApplicationChosen(event_token eventCookie) = 0;
};

struct __declspec(uuid("a9da01aa-e00e-4cfe-aa44-2dd932dca3d8")) __declspec(novtable) IDataTransferManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ShowShareUI() = 0;
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::ApplicationModel::DataTransfer::IDataTransferManager ** value) = 0;
};

struct __declspec(uuid("c54ec2ec-9f97-4d63-9868-395e271ad8f5")) __declspec(novtable) IDataTransferManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_IsSupported(bool * value) = 0;
};

struct __declspec(uuid("e22e7749-dd70-446f-aefc-61cee59f655e")) __declspec(novtable) IHtmlFormatHelperStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetStaticFragment(hstring htmlFormat, hstring * htmlFragment) = 0;
    virtual HRESULT __stdcall abi_CreateHtmlFormat(hstring htmlFragment, hstring * htmlFormat) = 0;
};

struct __declspec(uuid("e7af329d-051d-4fab-b1a9-47fd77f70a41")) __declspec(novtable) IOperationCompletedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Operation(winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) = 0;
};

struct __declspec(uuid("858fa073-1e19-4105-b2f7-c8478808d562")) __declspec(novtable) IOperationCompletedEventArgs2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AcceptedFormatId(hstring * value) = 0;
};

struct __declspec(uuid("c6132ada-34b1-4849-bd5f-d09fee3158c5")) __declspec(novtable) ISharedStorageAccessManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AddFile(Windows::Storage::IStorageFile * file, hstring * outToken) = 0;
    virtual HRESULT __stdcall abi_RedeemTokenForFileAsync(hstring token, Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> ** operation) = 0;
    virtual HRESULT __stdcall abi_RemoveFile(hstring token) = 0;
};

struct __declspec(uuid("7ed681a1-a880-40c9-b4ed-0bee1e15f549")) __declspec(novtable) IStandardDataFormatsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall get_Uri(hstring * value) = 0;
    virtual HRESULT __stdcall get_Html(hstring * value) = 0;
    virtual HRESULT __stdcall get_Rtf(hstring * value) = 0;
    virtual HRESULT __stdcall get_Bitmap(hstring * value) = 0;
    virtual HRESULT __stdcall get_StorageItems(hstring * value) = 0;
};

struct __declspec(uuid("42a254f4-9d76-42e8-861b-47c25dd0cf71")) __declspec(novtable) IStandardDataFormatsStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_WebLink(hstring * value) = 0;
    virtual HRESULT __stdcall get_ApplicationLink(hstring * value) = 0;
};

struct __declspec(uuid("ca6fb8ac-2987-4ee3-9c54-d8afbcb86c1d")) __declspec(novtable) ITargetApplicationChosenEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ApplicationName(hstring * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::DataTransfer::DataPackage> { using default_interface = Windows::ApplicationModel::DataTransfer::IDataPackage; };
template <> struct traits<Windows::ApplicationModel::DataTransfer::DataPackagePropertySet> { using default_interface = Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet; };
template <> struct traits<Windows::ApplicationModel::DataTransfer::DataPackagePropertySetView> { using default_interface = Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView; };
template <> struct traits<Windows::ApplicationModel::DataTransfer::DataPackageView> { using default_interface = Windows::ApplicationModel::DataTransfer::IDataPackageView; };
template <> struct traits<Windows::ApplicationModel::DataTransfer::DataProviderDeferral> { using default_interface = Windows::ApplicationModel::DataTransfer::IDataProviderDeferral; };
template <> struct traits<Windows::ApplicationModel::DataTransfer::DataProviderRequest> { using default_interface = Windows::ApplicationModel::DataTransfer::IDataProviderRequest; };
template <> struct traits<Windows::ApplicationModel::DataTransfer::DataRequest> { using default_interface = Windows::ApplicationModel::DataTransfer::IDataRequest; };
template <> struct traits<Windows::ApplicationModel::DataTransfer::DataRequestDeferral> { using default_interface = Windows::ApplicationModel::DataTransfer::IDataRequestDeferral; };
template <> struct traits<Windows::ApplicationModel::DataTransfer::DataRequestedEventArgs> { using default_interface = Windows::ApplicationModel::DataTransfer::IDataRequestedEventArgs; };
template <> struct traits<Windows::ApplicationModel::DataTransfer::DataTransferManager> { using default_interface = Windows::ApplicationModel::DataTransfer::IDataTransferManager; };
template <> struct traits<Windows::ApplicationModel::DataTransfer::OperationCompletedEventArgs> { using default_interface = Windows::ApplicationModel::DataTransfer::IOperationCompletedEventArgs; };
template <> struct traits<Windows::ApplicationModel::DataTransfer::TargetApplicationChosenEventArgs> { using default_interface = Windows::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs; };

}

namespace Windows::ApplicationModel::DataTransfer {

template <typename D>
struct WINRT_EBO impl_IClipboardStatics
{
    Windows::ApplicationModel::DataTransfer::DataPackageView GetContent() const;
    void SetContent(const Windows::ApplicationModel::DataTransfer::DataPackage & content) const;
    void Flush() const;
    void Clear() const;
    event_token ContentChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & changeHandler) const;
    using ContentChanged_revoker = event_revoker<IClipboardStatics>;
    ContentChanged_revoker ContentChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & changeHandler) const;
    void ContentChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IDataPackage
{
    Windows::ApplicationModel::DataTransfer::DataPackageView GetView() const;
    Windows::ApplicationModel::DataTransfer::DataPackagePropertySet Properties() const;
    Windows::ApplicationModel::DataTransfer::DataPackageOperation RequestedOperation() const;
    void RequestedOperation(Windows::ApplicationModel::DataTransfer::DataPackageOperation value) const;
    event_token OperationCompleted(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataPackage, Windows::ApplicationModel::DataTransfer::OperationCompletedEventArgs> & handler) const;
    using OperationCompleted_revoker = event_revoker<IDataPackage>;
    OperationCompleted_revoker OperationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataPackage, Windows::ApplicationModel::DataTransfer::OperationCompletedEventArgs> & handler) const;
    void OperationCompleted(event_token eventCookie) const;
    event_token Destroyed(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataPackage, Windows::Foundation::IInspectable> & handler) const;
    using Destroyed_revoker = event_revoker<IDataPackage>;
    Destroyed_revoker Destroyed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataPackage, Windows::Foundation::IInspectable> & handler) const;
    void Destroyed(event_token eventCookie) const;
    void SetData(hstring_view formatId, const Windows::Foundation::IInspectable & value) const;
    void SetDataProvider(hstring_view formatId, const Windows::ApplicationModel::DataTransfer::DataProviderHandler & delayRenderer) const;
    void SetText(hstring_view value) const;
    [[deprecated("SetUri may be altered or unavailable for releases after Windows Phone 'OSVersion' (TBD). Instead, use SetWebLink or SetApplicationLink.")]] void SetUri(const Windows::Foundation::Uri & value) const;
    void SetHtmlFormat(hstring_view value) const;
    Windows::Foundation::Collections::IMap<hstring, Windows::Storage::Streams::RandomAccessStreamReference> ResourceMap() const;
    void SetRtf(hstring_view value) const;
    void SetBitmap(const Windows::Storage::Streams::RandomAccessStreamReference & value) const;
    void SetStorageItems(iterable<Windows::Storage::IStorageItem> value) const;
    void SetStorageItems(iterable<Windows::Storage::IStorageItem> value, bool readOnly) const;
};

template <typename D>
struct WINRT_EBO impl_IDataPackage2
{
    void SetApplicationLink(const Windows::Foundation::Uri & value) const;
    void SetWebLink(const Windows::Foundation::Uri & value) const;
};

template <typename D>
struct WINRT_EBO impl_IDataPackagePropertySet
{
    hstring Title() const;
    void Title(hstring_view value) const;
    hstring Description() const;
    void Description(hstring_view value) const;
    Windows::Storage::Streams::IRandomAccessStreamReference Thumbnail() const;
    void Thumbnail(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
    Windows::Foundation::Collections::IVector<hstring> FileTypes() const;
    hstring ApplicationName() const;
    void ApplicationName(hstring_view value) const;
    Windows::Foundation::Uri ApplicationListingUri() const;
    void ApplicationListingUri(const Windows::Foundation::Uri & value) const;
};

template <typename D>
struct WINRT_EBO impl_IDataPackagePropertySet2
{
    Windows::Foundation::Uri ContentSourceWebLink() const;
    void ContentSourceWebLink(const Windows::Foundation::Uri & value) const;
    Windows::Foundation::Uri ContentSourceApplicationLink() const;
    void ContentSourceApplicationLink(const Windows::Foundation::Uri & value) const;
    hstring PackageFamilyName() const;
    void PackageFamilyName(hstring_view value) const;
    Windows::Storage::Streams::IRandomAccessStreamReference Square30x30Logo() const;
    void Square30x30Logo(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
    Windows::UI::Color LogoBackgroundColor() const;
    void LogoBackgroundColor(const Windows::UI::Color & value) const;
};

template <typename D>
struct WINRT_EBO impl_IDataPackagePropertySet3
{
    hstring EnterpriseId() const;
    void EnterpriseId(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IDataPackagePropertySetView
{
    hstring Title() const;
    hstring Description() const;
    Windows::Storage::Streams::RandomAccessStreamReference Thumbnail() const;
    Windows::Foundation::Collections::IVectorView<hstring> FileTypes() const;
    hstring ApplicationName() const;
    Windows::Foundation::Uri ApplicationListingUri() const;
};

template <typename D>
struct WINRT_EBO impl_IDataPackagePropertySetView2
{
    hstring PackageFamilyName() const;
    Windows::Foundation::Uri ContentSourceWebLink() const;
    Windows::Foundation::Uri ContentSourceApplicationLink() const;
    Windows::Storage::Streams::IRandomAccessStreamReference Square30x30Logo() const;
    Windows::UI::Color LogoBackgroundColor() const;
};

template <typename D>
struct WINRT_EBO impl_IDataPackagePropertySetView3
{
    hstring EnterpriseId() const;
};

template <typename D>
struct WINRT_EBO impl_IDataPackageView
{
    Windows::ApplicationModel::DataTransfer::DataPackagePropertySetView Properties() const;
    Windows::ApplicationModel::DataTransfer::DataPackageOperation RequestedOperation() const;
    void ReportOperationCompleted(Windows::ApplicationModel::DataTransfer::DataPackageOperation value) const;
    Windows::Foundation::Collections::IVectorView<hstring> AvailableFormats() const;
    bool Contains(hstring_view formatId) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::IInspectable> GetDataAsync(hstring_view formatId) const;
    Windows::Foundation::IAsyncOperation<hstring> GetTextAsync() const;
    Windows::Foundation::IAsyncOperation<hstring> GetTextAsync(hstring_view formatId) const;
    [[deprecated("GetUriAsync may be altered or unavailable for releases after Windows 8.1. Instead, use GetWebLinkAsync or GetApplicationLinkAsync.")]] Windows::Foundation::IAsyncOperation<Windows::Foundation::Uri> GetUriAsync() const;
    Windows::Foundation::IAsyncOperation<hstring> GetHtmlFormatAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Storage::Streams::RandomAccessStreamReference>> GetResourceMapAsync() const;
    Windows::Foundation::IAsyncOperation<hstring> GetRtfAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> GetBitmapAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> GetStorageItemsAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IDataPackageView2
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Uri> GetApplicationLinkAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Uri> GetWebLinkAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IDataPackageView3
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> RequestAccessAsync() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> RequestAccessAsync(hstring_view enterpriseId) const;
    Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult UnlockAndAssumeEnterpriseIdentity() const;
};

template <typename D>
struct WINRT_EBO impl_IDataPackageView4
{
    void SetAcceptedFormatId(hstring_view formatId) const;
};

template <typename D>
struct WINRT_EBO impl_IDataProviderDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IDataProviderRequest
{
    hstring FormatId() const;
    Windows::Foundation::DateTime Deadline() const;
    Windows::ApplicationModel::DataTransfer::DataProviderDeferral GetDeferral() const;
    void SetData(const Windows::Foundation::IInspectable & value) const;
};

template <typename D>
struct WINRT_EBO impl_IDataRequest
{
    Windows::ApplicationModel::DataTransfer::DataPackage Data() const;
    void Data(const Windows::ApplicationModel::DataTransfer::DataPackage & value) const;
    Windows::Foundation::DateTime Deadline() const;
    [[deprecated("FailWithDisplayText is deprecated and might not work on all platforms. For more info, see MSDN.")]] void FailWithDisplayText(hstring_view value) const;
    Windows::ApplicationModel::DataTransfer::DataRequestDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IDataRequestDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IDataRequestedEventArgs
{
    Windows::ApplicationModel::DataTransfer::DataRequest Request() const;
};

template <typename D>
struct WINRT_EBO impl_IDataTransferManager
{
    event_token DataRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataTransferManager, Windows::ApplicationModel::DataTransfer::DataRequestedEventArgs> & eventHandler) const;
    using DataRequested_revoker = event_revoker<IDataTransferManager>;
    DataRequested_revoker DataRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataTransferManager, Windows::ApplicationModel::DataTransfer::DataRequestedEventArgs> & eventHandler) const;
    void DataRequested(event_token eventCookie) const;
    event_token TargetApplicationChosen(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataTransferManager, Windows::ApplicationModel::DataTransfer::TargetApplicationChosenEventArgs> & eventHandler) const;
    using TargetApplicationChosen_revoker = event_revoker<IDataTransferManager>;
    TargetApplicationChosen_revoker TargetApplicationChosen(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataTransferManager, Windows::ApplicationModel::DataTransfer::TargetApplicationChosenEventArgs> & eventHandler) const;
    void TargetApplicationChosen(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_IDataTransferManagerStatics
{
    void ShowShareUI() const;
    Windows::ApplicationModel::DataTransfer::DataTransferManager GetForCurrentView() const;
};

template <typename D>
struct WINRT_EBO impl_IDataTransferManagerStatics2
{
    bool IsSupported() const;
};

template <typename D>
struct WINRT_EBO impl_IHtmlFormatHelperStatics
{
    hstring GetStaticFragment(hstring_view htmlFormat) const;
    hstring CreateHtmlFormat(hstring_view htmlFragment) const;
};

template <typename D>
struct WINRT_EBO impl_IOperationCompletedEventArgs
{
    Windows::ApplicationModel::DataTransfer::DataPackageOperation Operation() const;
};

template <typename D>
struct WINRT_EBO impl_IOperationCompletedEventArgs2
{
    hstring AcceptedFormatId() const;
};

template <typename D>
struct WINRT_EBO impl_ISharedStorageAccessManagerStatics
{
    hstring AddFile(const Windows::Storage::IStorageFile & file) const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> RedeemTokenForFileAsync(hstring_view token) const;
    void RemoveFile(hstring_view token) const;
};

template <typename D>
struct WINRT_EBO impl_IStandardDataFormatsStatics
{
    hstring Text() const;
    [[deprecated("Uri may be altered or unavailable for releases after Windows Phone 'OSVersion' (TBD). Instead, use WebLink or ApplicationLink.")]] hstring Uri() const;
    hstring Html() const;
    hstring Rtf() const;
    hstring Bitmap() const;
    hstring StorageItems() const;
};

template <typename D>
struct WINRT_EBO impl_IStandardDataFormatsStatics2
{
    hstring WebLink() const;
    hstring ApplicationLink() const;
};

template <typename D>
struct WINRT_EBO impl_ITargetApplicationChosenEventArgs
{
    hstring ApplicationName() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::DataTransfer::DataProviderHandler>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::DataProviderHandler;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IClipboardStatics>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IClipboardStatics;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IClipboardStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataPackage>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataPackage;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataPackage<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataPackage2>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataPackage2;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataPackage2<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataPackagePropertySet<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet2>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet2;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataPackagePropertySet2<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet3>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet3;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataPackagePropertySet3<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataPackagePropertySetView<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView2>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView2;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataPackagePropertySetView2<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView3>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView3;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataPackagePropertySetView3<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataPackageView>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataPackageView<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataPackageView2>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView2;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataPackageView2<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataPackageView3>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView3;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataPackageView3<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataPackageView4>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView4;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataPackageView4<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataProviderDeferral>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataProviderDeferral;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataProviderDeferral<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataProviderRequest>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataProviderRequest;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataProviderRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataRequest>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataRequest;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataRequestDeferral>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataRequestDeferral;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataRequestDeferral<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataRequestedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataRequestedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataRequestedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataTransferManager>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManager;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataTransferManager<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataTransferManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataTransferManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IDataTransferManagerStatics2>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManagerStatics2;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IDataTransferManagerStatics2<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IHtmlFormatHelperStatics>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IHtmlFormatHelperStatics;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IHtmlFormatHelperStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IOperationCompletedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IOperationCompletedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IOperationCompletedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IOperationCompletedEventArgs2>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IOperationCompletedEventArgs2;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IOperationCompletedEventArgs2<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::ISharedStorageAccessManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::ISharedStorageAccessManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_ISharedStorageAccessManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IStandardDataFormatsStatics>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IStandardDataFormatsStatics;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IStandardDataFormatsStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::IStandardDataFormatsStatics2>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::IStandardDataFormatsStatics2;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_IStandardDataFormatsStatics2<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::DataTransfer::impl_ITargetApplicationChosenEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::Clipboard>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.Clipboard"; }
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::DataPackage>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::DataPackage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.DataPackage"; }
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::DataPackagePropertySet>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::DataPackagePropertySet;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.DataPackagePropertySet"; }
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::DataPackagePropertySetView>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::DataPackagePropertySetView;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.DataPackagePropertySetView"; }
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::DataPackageView>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::DataPackageView;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.DataPackageView"; }
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::DataProviderDeferral>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::DataProviderDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.DataProviderDeferral"; }
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::DataProviderRequest>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::DataProviderRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.DataProviderRequest"; }
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::DataRequest>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::DataRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.DataRequest"; }
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::DataRequestDeferral>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::DataRequestDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.DataRequestDeferral"; }
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::DataRequestedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::DataRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.DataRequestedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::DataTransferManager>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::DataTransferManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.DataTransferManager"; }
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::HtmlFormatHelper>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.HtmlFormatHelper"; }
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::OperationCompletedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::OperationCompletedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.OperationCompletedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::SharedStorageAccessManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.SharedStorageAccessManager"; }
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::StandardDataFormats>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.StandardDataFormats"; }
};

template <> struct traits<Windows::ApplicationModel::DataTransfer::TargetApplicationChosenEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::DataTransfer::TargetApplicationChosenEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DataTransfer.TargetApplicationChosenEventArgs"; }
};

}

}
