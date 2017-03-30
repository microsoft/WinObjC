// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.Import.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Import {

struct PhotoImportProgress
{
    uint32_t ItemsImported;
    uint32_t TotalItemsToImport;
    uint64_t BytesImported;
    uint64_t TotalBytesToImport;
    double ImportProgress;
};

}

namespace Windows::Media::Import {

using PhotoImportProgress = ABI::Windows::Media::Import::PhotoImportProgress;

}

namespace ABI::Windows::Media::Import {

struct __declspec(uuid("f4e112f8-843d-428a-a1a6-81510292b0ae")) __declspec(novtable) IPhotoImportDeleteImportedItemsFromSourceResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Session(Windows::Media::Import::IPhotoImportSession ** value) = 0;
    virtual HRESULT __stdcall get_HasSucceeded(bool * value) = 0;
    virtual HRESULT __stdcall get_DeletedItems(Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportItem> ** value) = 0;
    virtual HRESULT __stdcall get_PhotosCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_PhotosSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_VideosCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_VideosSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_SidecarsCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_SidecarsSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_SiblingsCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_SiblingsSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_TotalCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_TotalSizeInBytes(uint64_t * value) = 0;
};

struct __declspec(uuid("3915e647-6c78-492b-844e-8fe5e8f6bfb9")) __declspec(novtable) IPhotoImportFindItemsResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Session(Windows::Media::Import::IPhotoImportSession ** value) = 0;
    virtual HRESULT __stdcall get_HasSucceeded(bool * value) = 0;
    virtual HRESULT __stdcall get_FoundItems(Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportItem> ** value) = 0;
    virtual HRESULT __stdcall get_PhotosCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_PhotosSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_VideosCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_VideosSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_SidecarsCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_SidecarsSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_SiblingsCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_SiblingsSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_TotalCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_TotalSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall abi_SelectAll() = 0;
    virtual HRESULT __stdcall abi_SelectNone() = 0;
    virtual HRESULT __stdcall abi_SelectNewAsync(Windows::Foundation::IAsyncAction ** action) = 0;
    virtual HRESULT __stdcall abi_SetImportMode(winrt::Windows::Media::Import::PhotoImportImportMode value) = 0;
    virtual HRESULT __stdcall get_ImportMode(winrt::Windows::Media::Import::PhotoImportImportMode * value) = 0;
    virtual HRESULT __stdcall get_SelectedPhotosCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_SelectedPhotosSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_SelectedVideosCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_SelectedVideosSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_SelectedSidecarsCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_SelectedSidecarsSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_SelectedSiblingsCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_SelectedSiblingsSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_SelectedTotalCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_SelectedTotalSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall add_SelectionChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Import::PhotoImportFindItemsResult, Windows::Media::Import::PhotoImportSelectionChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SelectionChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_ImportItemsAsync(Windows::Foundation::IAsyncOperationWithProgress<Windows::Media::Import::PhotoImportImportItemsResult, Windows::Media::Import::PhotoImportProgress> ** operation) = 0;
    virtual HRESULT __stdcall add_ItemImported(Windows::Foundation::TypedEventHandler<Windows::Media::Import::PhotoImportFindItemsResult, Windows::Media::Import::PhotoImportItemImportedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ItemImported(event_token token) = 0;
};

struct __declspec(uuid("fbdd6a3b-ecf9-406a-815e-5015625b0a88")) __declspec(novtable) IPhotoImportFindItemsResult2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AddItemsInDateRangeToSelection(Windows::Foundation::DateTime rangeStart, Windows::Foundation::TimeSpan rangeLength) = 0;
};

struct __declspec(uuid("e4d4f478-d419-4443-a84e-f06a850c0b00")) __declspec(novtable) IPhotoImportImportItemsResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Session(Windows::Media::Import::IPhotoImportSession ** value) = 0;
    virtual HRESULT __stdcall get_HasSucceeded(bool * value) = 0;
    virtual HRESULT __stdcall get_ImportedItems(Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportItem> ** value) = 0;
    virtual HRESULT __stdcall get_PhotosCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_PhotosSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_VideosCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_VideosSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_SidecarsCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_SidecarsSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_SiblingsCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_SiblingsSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_TotalCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_TotalSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall abi_DeleteImportedItemsFromSourceAsync(Windows::Foundation::IAsyncOperationWithProgress<Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult, double> ** result) = 0;
};

struct __declspec(uuid("a9d07e76-9bfc-43b8-b356-633b6a988c9e")) __declspec(novtable) IPhotoImportItem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_ItemKey(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_ContentType(winrt::Windows::Media::Import::PhotoImportContentType * value) = 0;
    virtual HRESULT __stdcall get_SizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_Date(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_Sibling(Windows::Media::Import::IPhotoImportSidecar ** value) = 0;
    virtual HRESULT __stdcall get_Sidecars(Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportSidecar> ** value) = 0;
    virtual HRESULT __stdcall get_VideoSegments(Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportVideoSegment> ** value) = 0;
    virtual HRESULT __stdcall get_IsSelected(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSelected(bool value) = 0;
    virtual HRESULT __stdcall get_Thumbnail(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall get_ImportedFileNames(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_DeletedFileNames(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
};

struct __declspec(uuid("42cb2fdd-7d68-47b5-bc7c-ceb73e0c77dc")) __declspec(novtable) IPhotoImportItemImportedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ImportedItem(Windows::Media::Import::IPhotoImportItem ** value) = 0;
};

struct __declspec(uuid("2771903d-a046-4f06-9b9c-bfd662e83287")) __declspec(novtable) IPhotoImportManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_IsSupportedAsync(Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
    virtual HRESULT __stdcall abi_FindAllSourcesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportSource>> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetPendingOperations(Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportOperation> ** result) = 0;
};

struct __declspec(uuid("d9f797e4-a09a-4ee4-a4b1-20940277a5be")) __declspec(novtable) IPhotoImportOperation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Stage(winrt::Windows::Media::Import::PhotoImportStage * value) = 0;
    virtual HRESULT __stdcall get_Session(Windows::Media::Import::IPhotoImportSession ** value) = 0;
    virtual HRESULT __stdcall get_ContinueFindingItemsAsync(Windows::Foundation::IAsyncOperationWithProgress<Windows::Media::Import::PhotoImportFindItemsResult, uint32_t> ** operation) = 0;
    virtual HRESULT __stdcall get_ContinueImportingItemsAsync(Windows::Foundation::IAsyncOperationWithProgress<Windows::Media::Import::PhotoImportImportItemsResult, Windows::Media::Import::PhotoImportProgress> ** operation) = 0;
    virtual HRESULT __stdcall get_ContinueDeletingImportedItemsFromSourceAsync(Windows::Foundation::IAsyncOperationWithProgress<Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult, double> ** operation) = 0;
};

struct __declspec(uuid("10461782-fa9d-4c30-8bc9-4d64911572d5")) __declspec(novtable) IPhotoImportSelectionChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsSelectionEmpty(bool * value) = 0;
};

struct __declspec(uuid("aa63916e-ecdb-4efe-94c6-5f5cafe34cfb")) __declspec(novtable) IPhotoImportSession : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Source(Windows::Media::Import::IPhotoImportSource ** value) = 0;
    virtual HRESULT __stdcall get_SessionId(GUID * value) = 0;
    virtual HRESULT __stdcall put_DestinationFolder(Windows::Storage::IStorageFolder * value) = 0;
    virtual HRESULT __stdcall get_DestinationFolder(Windows::Storage::IStorageFolder ** value) = 0;
    virtual HRESULT __stdcall put_AppendSessionDateToDestinationFolder(bool value) = 0;
    virtual HRESULT __stdcall get_AppendSessionDateToDestinationFolder(bool * value) = 0;
    virtual HRESULT __stdcall put_SubfolderCreationMode(winrt::Windows::Media::Import::PhotoImportSubfolderCreationMode value) = 0;
    virtual HRESULT __stdcall get_SubfolderCreationMode(winrt::Windows::Media::Import::PhotoImportSubfolderCreationMode * value) = 0;
    virtual HRESULT __stdcall put_DestinationFileNamePrefix(hstring value) = 0;
    virtual HRESULT __stdcall get_DestinationFileNamePrefix(hstring * value) = 0;
    virtual HRESULT __stdcall abi_FindItemsAsync(winrt::Windows::Media::Import::PhotoImportContentTypeFilter contentTypeFilter, winrt::Windows::Media::Import::PhotoImportItemSelectionMode itemSelectionMode, Windows::Foundation::IAsyncOperationWithProgress<Windows::Media::Import::PhotoImportFindItemsResult, uint32_t> ** operation) = 0;
};

struct __declspec(uuid("2a526710-3ec6-469d-a375-2b9f4785391e")) __declspec(novtable) IPhotoImportSession2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_SubfolderDateFormat(winrt::Windows::Media::Import::PhotoImportSubfolderDateFormat value) = 0;
    virtual HRESULT __stdcall get_SubfolderDateFormat(winrt::Windows::Media::Import::PhotoImportSubfolderDateFormat * value) = 0;
    virtual HRESULT __stdcall put_RememberDeselectedItems(bool value) = 0;
    virtual HRESULT __stdcall get_RememberDeselectedItems(bool * value) = 0;
};

struct __declspec(uuid("46d7d757-f802-44c7-9c98-7a71f4bc1486")) __declspec(novtable) IPhotoImportSidecar : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_SizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_Date(Windows::Foundation::DateTime * value) = 0;
};

struct __declspec(uuid("1f8ea35e-145b-4cd6-87f1-54965a982fef")) __declspec(novtable) IPhotoImportSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall get_Manufacturer(hstring * value) = 0;
    virtual HRESULT __stdcall get_Model(hstring * value) = 0;
    virtual HRESULT __stdcall get_SerialNumber(hstring * value) = 0;
    virtual HRESULT __stdcall get_ConnectionProtocol(hstring * value) = 0;
    virtual HRESULT __stdcall get_ConnectionTransport(winrt::Windows::Media::Import::PhotoImportConnectionTransport * value) = 0;
    virtual HRESULT __stdcall get_Type(winrt::Windows::Media::Import::PhotoImportSourceType * value) = 0;
    virtual HRESULT __stdcall get_PowerSource(winrt::Windows::Media::Import::PhotoImportPowerSource * value) = 0;
    virtual HRESULT __stdcall get_BatteryLevelPercent(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_DateTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_StorageMedia(Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportStorageMedium> ** value) = 0;
    virtual HRESULT __stdcall get_IsLocked(Windows::Foundation::IReference<bool> ** value) = 0;
    virtual HRESULT __stdcall get_IsMassStorage(bool * value) = 0;
    virtual HRESULT __stdcall get_Thumbnail(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall abi_CreateImportSession(Windows::Media::Import::IPhotoImportSession ** result) = 0;
};

struct __declspec(uuid("0528e586-32d8-467c-8cee-23a1b2f43e85")) __declspec(novtable) IPhotoImportSourceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromIdAsync(hstring sourceId, Windows::Foundation::IAsyncOperation<Windows::Media::Import::PhotoImportSource> ** operation) = 0;
    virtual HRESULT __stdcall abi_FromFolderAsync(Windows::Storage::IStorageFolder * sourceRootFolder, Windows::Foundation::IAsyncOperation<Windows::Media::Import::PhotoImportSource> ** operation) = 0;
};

struct __declspec(uuid("f2b9b093-fc85-487f-87c2-58d675d05b07")) __declspec(novtable) IPhotoImportStorageMedium : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall get_SerialNumber(hstring * value) = 0;
    virtual HRESULT __stdcall get_StorageMediumType(winrt::Windows::Media::Import::PhotoImportStorageMediumType * value) = 0;
    virtual HRESULT __stdcall get_SupportedAccessMode(winrt::Windows::Media::Import::PhotoImportAccessMode * value) = 0;
    virtual HRESULT __stdcall get_CapacityInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_AvailableSpaceInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall abi_Refresh() = 0;
};

struct __declspec(uuid("623c0289-321a-41d8-9166-8c62a333276c")) __declspec(novtable) IPhotoImportVideoSegment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_SizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_Date(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_Sibling(Windows::Media::Import::IPhotoImportSidecar ** value) = 0;
    virtual HRESULT __stdcall get_Sidecars(Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportSidecar> ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult> { using default_interface = Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult; };
template <> struct traits<Windows::Media::Import::PhotoImportFindItemsResult> { using default_interface = Windows::Media::Import::IPhotoImportFindItemsResult; };
template <> struct traits<Windows::Media::Import::PhotoImportImportItemsResult> { using default_interface = Windows::Media::Import::IPhotoImportImportItemsResult; };
template <> struct traits<Windows::Media::Import::PhotoImportItem> { using default_interface = Windows::Media::Import::IPhotoImportItem; };
template <> struct traits<Windows::Media::Import::PhotoImportItemImportedEventArgs> { using default_interface = Windows::Media::Import::IPhotoImportItemImportedEventArgs; };
template <> struct traits<Windows::Media::Import::PhotoImportOperation> { using default_interface = Windows::Media::Import::IPhotoImportOperation; };
template <> struct traits<Windows::Media::Import::PhotoImportSelectionChangedEventArgs> { using default_interface = Windows::Media::Import::IPhotoImportSelectionChangedEventArgs; };
template <> struct traits<Windows::Media::Import::PhotoImportSession> { using default_interface = Windows::Media::Import::IPhotoImportSession; };
template <> struct traits<Windows::Media::Import::PhotoImportSidecar> { using default_interface = Windows::Media::Import::IPhotoImportSidecar; };
template <> struct traits<Windows::Media::Import::PhotoImportSource> { using default_interface = Windows::Media::Import::IPhotoImportSource; };
template <> struct traits<Windows::Media::Import::PhotoImportStorageMedium> { using default_interface = Windows::Media::Import::IPhotoImportStorageMedium; };
template <> struct traits<Windows::Media::Import::PhotoImportVideoSegment> { using default_interface = Windows::Media::Import::IPhotoImportVideoSegment; };

}

namespace Windows::Media::Import {

template <typename D>
struct WINRT_EBO impl_IPhotoImportDeleteImportedItemsFromSourceResult
{
    Windows::Media::Import::PhotoImportSession Session() const;
    bool HasSucceeded() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportItem> DeletedItems() const;
    uint32_t PhotosCount() const;
    uint64_t PhotosSizeInBytes() const;
    uint32_t VideosCount() const;
    uint64_t VideosSizeInBytes() const;
    uint32_t SidecarsCount() const;
    uint64_t SidecarsSizeInBytes() const;
    uint32_t SiblingsCount() const;
    uint64_t SiblingsSizeInBytes() const;
    uint32_t TotalCount() const;
    uint64_t TotalSizeInBytes() const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoImportFindItemsResult
{
    Windows::Media::Import::PhotoImportSession Session() const;
    bool HasSucceeded() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportItem> FoundItems() const;
    uint32_t PhotosCount() const;
    uint64_t PhotosSizeInBytes() const;
    uint32_t VideosCount() const;
    uint64_t VideosSizeInBytes() const;
    uint32_t SidecarsCount() const;
    uint64_t SidecarsSizeInBytes() const;
    uint32_t SiblingsCount() const;
    uint64_t SiblingsSizeInBytes() const;
    uint32_t TotalCount() const;
    uint64_t TotalSizeInBytes() const;
    void SelectAll() const;
    void SelectNone() const;
    Windows::Foundation::IAsyncAction SelectNewAsync() const;
    void SetImportMode(Windows::Media::Import::PhotoImportImportMode value) const;
    Windows::Media::Import::PhotoImportImportMode ImportMode() const;
    uint32_t SelectedPhotosCount() const;
    uint64_t SelectedPhotosSizeInBytes() const;
    uint32_t SelectedVideosCount() const;
    uint64_t SelectedVideosSizeInBytes() const;
    uint32_t SelectedSidecarsCount() const;
    uint64_t SelectedSidecarsSizeInBytes() const;
    uint32_t SelectedSiblingsCount() const;
    uint64_t SelectedSiblingsSizeInBytes() const;
    uint32_t SelectedTotalCount() const;
    uint64_t SelectedTotalSizeInBytes() const;
    event_token SelectionChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Import::PhotoImportFindItemsResult, Windows::Media::Import::PhotoImportSelectionChangedEventArgs> & value) const;
    using SelectionChanged_revoker = event_revoker<IPhotoImportFindItemsResult>;
    SelectionChanged_revoker SelectionChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Import::PhotoImportFindItemsResult, Windows::Media::Import::PhotoImportSelectionChangedEventArgs> & value) const;
    void SelectionChanged(event_token token) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Media::Import::PhotoImportImportItemsResult, Windows::Media::Import::PhotoImportProgress> ImportItemsAsync() const;
    event_token ItemImported(const Windows::Foundation::TypedEventHandler<Windows::Media::Import::PhotoImportFindItemsResult, Windows::Media::Import::PhotoImportItemImportedEventArgs> & value) const;
    using ItemImported_revoker = event_revoker<IPhotoImportFindItemsResult>;
    ItemImported_revoker ItemImported(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Import::PhotoImportFindItemsResult, Windows::Media::Import::PhotoImportItemImportedEventArgs> & value) const;
    void ItemImported(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoImportFindItemsResult2
{
    void AddItemsInDateRangeToSelection(const Windows::Foundation::DateTime & rangeStart, const Windows::Foundation::TimeSpan & rangeLength) const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoImportImportItemsResult
{
    Windows::Media::Import::PhotoImportSession Session() const;
    bool HasSucceeded() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportItem> ImportedItems() const;
    uint32_t PhotosCount() const;
    uint64_t PhotosSizeInBytes() const;
    uint32_t VideosCount() const;
    uint64_t VideosSizeInBytes() const;
    uint32_t SidecarsCount() const;
    uint64_t SidecarsSizeInBytes() const;
    uint32_t SiblingsCount() const;
    uint64_t SiblingsSizeInBytes() const;
    uint32_t TotalCount() const;
    uint64_t TotalSizeInBytes() const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult, double> DeleteImportedItemsFromSourceAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoImportItem
{
    hstring Name() const;
    uint64_t ItemKey() const;
    Windows::Media::Import::PhotoImportContentType ContentType() const;
    uint64_t SizeInBytes() const;
    Windows::Foundation::DateTime Date() const;
    Windows::Media::Import::PhotoImportSidecar Sibling() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportSidecar> Sidecars() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportVideoSegment> VideoSegments() const;
    bool IsSelected() const;
    void IsSelected(bool value) const;
    Windows::Storage::Streams::IRandomAccessStreamReference Thumbnail() const;
    Windows::Foundation::Collections::IVectorView<hstring> ImportedFileNames() const;
    Windows::Foundation::Collections::IVectorView<hstring> DeletedFileNames() const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoImportItemImportedEventArgs
{
    Windows::Media::Import::PhotoImportItem ImportedItem() const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoImportManagerStatics
{
    Windows::Foundation::IAsyncOperation<bool> IsSupportedAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportSource>> FindAllSourcesAsync() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportOperation> GetPendingOperations() const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoImportOperation
{
    Windows::Media::Import::PhotoImportStage Stage() const;
    Windows::Media::Import::PhotoImportSession Session() const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Media::Import::PhotoImportFindItemsResult, uint32_t> ContinueFindingItemsAsync() const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Media::Import::PhotoImportImportItemsResult, Windows::Media::Import::PhotoImportProgress> ContinueImportingItemsAsync() const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult, double> ContinueDeletingImportedItemsFromSourceAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoImportSelectionChangedEventArgs
{
    bool IsSelectionEmpty() const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoImportSession
{
    Windows::Media::Import::PhotoImportSource Source() const;
    GUID SessionId() const;
    void DestinationFolder(const Windows::Storage::IStorageFolder & value) const;
    Windows::Storage::IStorageFolder DestinationFolder() const;
    void AppendSessionDateToDestinationFolder(bool value) const;
    bool AppendSessionDateToDestinationFolder() const;
    void SubfolderCreationMode(Windows::Media::Import::PhotoImportSubfolderCreationMode value) const;
    Windows::Media::Import::PhotoImportSubfolderCreationMode SubfolderCreationMode() const;
    void DestinationFileNamePrefix(hstring_view value) const;
    hstring DestinationFileNamePrefix() const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Media::Import::PhotoImportFindItemsResult, uint32_t> FindItemsAsync(Windows::Media::Import::PhotoImportContentTypeFilter contentTypeFilter, Windows::Media::Import::PhotoImportItemSelectionMode itemSelectionMode) const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoImportSession2
{
    void SubfolderDateFormat(Windows::Media::Import::PhotoImportSubfolderDateFormat value) const;
    Windows::Media::Import::PhotoImportSubfolderDateFormat SubfolderDateFormat() const;
    void RememberDeselectedItems(bool value) const;
    bool RememberDeselectedItems() const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoImportSidecar
{
    hstring Name() const;
    uint64_t SizeInBytes() const;
    Windows::Foundation::DateTime Date() const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoImportSource
{
    hstring Id() const;
    hstring DisplayName() const;
    hstring Description() const;
    hstring Manufacturer() const;
    hstring Model() const;
    hstring SerialNumber() const;
    hstring ConnectionProtocol() const;
    Windows::Media::Import::PhotoImportConnectionTransport ConnectionTransport() const;
    Windows::Media::Import::PhotoImportSourceType Type() const;
    Windows::Media::Import::PhotoImportPowerSource PowerSource() const;
    Windows::Foundation::IReference<uint32_t> BatteryLevelPercent() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> DateTime() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportStorageMedium> StorageMedia() const;
    Windows::Foundation::IReference<bool> IsLocked() const;
    bool IsMassStorage() const;
    Windows::Storage::Streams::IRandomAccessStreamReference Thumbnail() const;
    Windows::Media::Import::PhotoImportSession CreateImportSession() const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoImportSourceStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Import::PhotoImportSource> FromIdAsync(hstring_view sourceId) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Import::PhotoImportSource> FromFolderAsync(const Windows::Storage::IStorageFolder & sourceRootFolder) const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoImportStorageMedium
{
    hstring Name() const;
    hstring Description() const;
    hstring SerialNumber() const;
    Windows::Media::Import::PhotoImportStorageMediumType StorageMediumType() const;
    Windows::Media::Import::PhotoImportAccessMode SupportedAccessMode() const;
    uint64_t CapacityInBytes() const;
    uint64_t AvailableSpaceInBytes() const;
    void Refresh() const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoImportVideoSegment
{
    hstring Name() const;
    uint64_t SizeInBytes() const;
    Windows::Foundation::DateTime Date() const;
    Windows::Media::Import::PhotoImportSidecar Sibling() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportSidecar> Sidecars() const;
};

}

namespace impl {

template <> struct traits<Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>
{
    using abi = ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult;
    template <typename D> using consume = Windows::Media::Import::impl_IPhotoImportDeleteImportedItemsFromSourceResult<D>;
};

template <> struct traits<Windows::Media::Import::IPhotoImportFindItemsResult>
{
    using abi = ABI::Windows::Media::Import::IPhotoImportFindItemsResult;
    template <typename D> using consume = Windows::Media::Import::impl_IPhotoImportFindItemsResult<D>;
};

template <> struct traits<Windows::Media::Import::IPhotoImportFindItemsResult2>
{
    using abi = ABI::Windows::Media::Import::IPhotoImportFindItemsResult2;
    template <typename D> using consume = Windows::Media::Import::impl_IPhotoImportFindItemsResult2<D>;
};

template <> struct traits<Windows::Media::Import::IPhotoImportImportItemsResult>
{
    using abi = ABI::Windows::Media::Import::IPhotoImportImportItemsResult;
    template <typename D> using consume = Windows::Media::Import::impl_IPhotoImportImportItemsResult<D>;
};

template <> struct traits<Windows::Media::Import::IPhotoImportItem>
{
    using abi = ABI::Windows::Media::Import::IPhotoImportItem;
    template <typename D> using consume = Windows::Media::Import::impl_IPhotoImportItem<D>;
};

template <> struct traits<Windows::Media::Import::IPhotoImportItemImportedEventArgs>
{
    using abi = ABI::Windows::Media::Import::IPhotoImportItemImportedEventArgs;
    template <typename D> using consume = Windows::Media::Import::impl_IPhotoImportItemImportedEventArgs<D>;
};

template <> struct traits<Windows::Media::Import::IPhotoImportManagerStatics>
{
    using abi = ABI::Windows::Media::Import::IPhotoImportManagerStatics;
    template <typename D> using consume = Windows::Media::Import::impl_IPhotoImportManagerStatics<D>;
};

template <> struct traits<Windows::Media::Import::IPhotoImportOperation>
{
    using abi = ABI::Windows::Media::Import::IPhotoImportOperation;
    template <typename D> using consume = Windows::Media::Import::impl_IPhotoImportOperation<D>;
};

template <> struct traits<Windows::Media::Import::IPhotoImportSelectionChangedEventArgs>
{
    using abi = ABI::Windows::Media::Import::IPhotoImportSelectionChangedEventArgs;
    template <typename D> using consume = Windows::Media::Import::impl_IPhotoImportSelectionChangedEventArgs<D>;
};

template <> struct traits<Windows::Media::Import::IPhotoImportSession>
{
    using abi = ABI::Windows::Media::Import::IPhotoImportSession;
    template <typename D> using consume = Windows::Media::Import::impl_IPhotoImportSession<D>;
};

template <> struct traits<Windows::Media::Import::IPhotoImportSession2>
{
    using abi = ABI::Windows::Media::Import::IPhotoImportSession2;
    template <typename D> using consume = Windows::Media::Import::impl_IPhotoImportSession2<D>;
};

template <> struct traits<Windows::Media::Import::IPhotoImportSidecar>
{
    using abi = ABI::Windows::Media::Import::IPhotoImportSidecar;
    template <typename D> using consume = Windows::Media::Import::impl_IPhotoImportSidecar<D>;
};

template <> struct traits<Windows::Media::Import::IPhotoImportSource>
{
    using abi = ABI::Windows::Media::Import::IPhotoImportSource;
    template <typename D> using consume = Windows::Media::Import::impl_IPhotoImportSource<D>;
};

template <> struct traits<Windows::Media::Import::IPhotoImportSourceStatics>
{
    using abi = ABI::Windows::Media::Import::IPhotoImportSourceStatics;
    template <typename D> using consume = Windows::Media::Import::impl_IPhotoImportSourceStatics<D>;
};

template <> struct traits<Windows::Media::Import::IPhotoImportStorageMedium>
{
    using abi = ABI::Windows::Media::Import::IPhotoImportStorageMedium;
    template <typename D> using consume = Windows::Media::Import::impl_IPhotoImportStorageMedium<D>;
};

template <> struct traits<Windows::Media::Import::IPhotoImportVideoSegment>
{
    using abi = ABI::Windows::Media::Import::IPhotoImportVideoSegment;
    template <typename D> using consume = Windows::Media::Import::impl_IPhotoImportVideoSegment<D>;
};

template <> struct traits<Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult>
{
    using abi = ABI::Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Import.PhotoImportDeleteImportedItemsFromSourceResult"; }
};

template <> struct traits<Windows::Media::Import::PhotoImportFindItemsResult>
{
    using abi = ABI::Windows::Media::Import::PhotoImportFindItemsResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Import.PhotoImportFindItemsResult"; }
};

template <> struct traits<Windows::Media::Import::PhotoImportImportItemsResult>
{
    using abi = ABI::Windows::Media::Import::PhotoImportImportItemsResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Import.PhotoImportImportItemsResult"; }
};

template <> struct traits<Windows::Media::Import::PhotoImportItem>
{
    using abi = ABI::Windows::Media::Import::PhotoImportItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Import.PhotoImportItem"; }
};

template <> struct traits<Windows::Media::Import::PhotoImportItemImportedEventArgs>
{
    using abi = ABI::Windows::Media::Import::PhotoImportItemImportedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Import.PhotoImportItemImportedEventArgs"; }
};

template <> struct traits<Windows::Media::Import::PhotoImportManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Import.PhotoImportManager"; }
};

template <> struct traits<Windows::Media::Import::PhotoImportOperation>
{
    using abi = ABI::Windows::Media::Import::PhotoImportOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Import.PhotoImportOperation"; }
};

template <> struct traits<Windows::Media::Import::PhotoImportSelectionChangedEventArgs>
{
    using abi = ABI::Windows::Media::Import::PhotoImportSelectionChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Import.PhotoImportSelectionChangedEventArgs"; }
};

template <> struct traits<Windows::Media::Import::PhotoImportSession>
{
    using abi = ABI::Windows::Media::Import::PhotoImportSession;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Import.PhotoImportSession"; }
};

template <> struct traits<Windows::Media::Import::PhotoImportSidecar>
{
    using abi = ABI::Windows::Media::Import::PhotoImportSidecar;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Import.PhotoImportSidecar"; }
};

template <> struct traits<Windows::Media::Import::PhotoImportSource>
{
    using abi = ABI::Windows::Media::Import::PhotoImportSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Import.PhotoImportSource"; }
};

template <> struct traits<Windows::Media::Import::PhotoImportStorageMedium>
{
    using abi = ABI::Windows::Media::Import::PhotoImportStorageMedium;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Import.PhotoImportStorageMedium"; }
};

template <> struct traits<Windows::Media::Import::PhotoImportVideoSegment>
{
    using abi = ABI::Windows::Media::Import::PhotoImportVideoSegment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Import.PhotoImportVideoSegment"; }
};

}

}
