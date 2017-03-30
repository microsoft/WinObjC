// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Storage.Pickers.0.h"
#include "Windows.Foundation.Collections.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Storage.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Storage::Pickers {

struct __declspec(uuid("2ca8278a-12c5-4c5f-8977-94547793c241")) __declspec(novtable) IFileOpenPicker : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ViewMode(winrt::Windows::Storage::Pickers::PickerViewMode * value) = 0;
    virtual HRESULT __stdcall put_ViewMode(winrt::Windows::Storage::Pickers::PickerViewMode value) = 0;
    virtual HRESULT __stdcall get_SettingsIdentifier(hstring * value) = 0;
    virtual HRESULT __stdcall put_SettingsIdentifier(hstring value) = 0;
    virtual HRESULT __stdcall get_SuggestedStartLocation(winrt::Windows::Storage::Pickers::PickerLocationId * value) = 0;
    virtual HRESULT __stdcall put_SuggestedStartLocation(winrt::Windows::Storage::Pickers::PickerLocationId value) = 0;
    virtual HRESULT __stdcall get_CommitButtonText(hstring * value) = 0;
    virtual HRESULT __stdcall put_CommitButtonText(hstring value) = 0;
    virtual HRESULT __stdcall get_FileTypeFilter(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall abi_PickSingleFileAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> ** pickSingleFileOperation) = 0;
    virtual HRESULT __stdcall abi_PickMultipleFilesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> ** pickMultipleFilesOperation) = 0;
};

struct __declspec(uuid("8ceb6cd2-b446-46f7-b265-90f8e55ad650")) __declspec(novtable) IFileOpenPicker2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContinuationData(Windows::Foundation::Collections::IPropertySet ** value) = 0;
    virtual HRESULT __stdcall abi_PickSingleFileAndContinue() = 0;
    virtual HRESULT __stdcall abi_PickMultipleFilesAndContinue() = 0;
};

struct __declspec(uuid("6821573b-2f02-4833-96d4-abbfad72b67b")) __declspec(novtable) IFileOpenPickerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ResumePickSingleFileAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> ** pickSingleFileOperation) = 0;
};

struct __declspec(uuid("3f57b569-2522-4ca5-aa73-a15509f1fcbf")) __declspec(novtable) IFileOpenPickerWithOperationId : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_PickSingleFileAsync(hstring pickerOperationId, Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> ** pickSingleFileOperation) = 0;
};

struct __declspec(uuid("3286ffcb-617f-4cc5-af6a-b3fdf29ad145")) __declspec(novtable) IFileSavePicker : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SettingsIdentifier(hstring * value) = 0;
    virtual HRESULT __stdcall put_SettingsIdentifier(hstring value) = 0;
    virtual HRESULT __stdcall get_SuggestedStartLocation(winrt::Windows::Storage::Pickers::PickerLocationId * value) = 0;
    virtual HRESULT __stdcall put_SuggestedStartLocation(winrt::Windows::Storage::Pickers::PickerLocationId value) = 0;
    virtual HRESULT __stdcall get_CommitButtonText(hstring * value) = 0;
    virtual HRESULT __stdcall put_CommitButtonText(hstring value) = 0;
    virtual HRESULT __stdcall get_FileTypeChoices(Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::Collections::IVector<hstring>> ** value) = 0;
    virtual HRESULT __stdcall get_DefaultFileExtension(hstring * value) = 0;
    virtual HRESULT __stdcall put_DefaultFileExtension(hstring value) = 0;
    virtual HRESULT __stdcall get_SuggestedSaveFile(Windows::Storage::IStorageFile ** value) = 0;
    virtual HRESULT __stdcall put_SuggestedSaveFile(Windows::Storage::IStorageFile * value) = 0;
    virtual HRESULT __stdcall get_SuggestedFileName(hstring * value) = 0;
    virtual HRESULT __stdcall put_SuggestedFileName(hstring value) = 0;
    virtual HRESULT __stdcall abi_PickSaveFileAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> ** pickSaveFileOperation) = 0;
};

struct __declspec(uuid("0ec313a2-d24b-449a-8197-e89104fd42cc")) __declspec(novtable) IFileSavePicker2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContinuationData(Windows::Foundation::Collections::IPropertySet ** value) = 0;
    virtual HRESULT __stdcall abi_PickSaveFileAndContinue() = 0;
};

struct __declspec(uuid("698aec69-ba3c-4e51-bd90-4abcbbf4cfaf")) __declspec(novtable) IFileSavePicker3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EnterpriseId(hstring * value) = 0;
    virtual HRESULT __stdcall put_EnterpriseId(hstring value) = 0;
};

struct __declspec(uuid("084f7799-f3fb-400a-99b1-7b4a772fd60d")) __declspec(novtable) IFolderPicker : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ViewMode(winrt::Windows::Storage::Pickers::PickerViewMode * value) = 0;
    virtual HRESULT __stdcall put_ViewMode(winrt::Windows::Storage::Pickers::PickerViewMode value) = 0;
    virtual HRESULT __stdcall get_SettingsIdentifier(hstring * value) = 0;
    virtual HRESULT __stdcall put_SettingsIdentifier(hstring value) = 0;
    virtual HRESULT __stdcall get_SuggestedStartLocation(winrt::Windows::Storage::Pickers::PickerLocationId * value) = 0;
    virtual HRESULT __stdcall put_SuggestedStartLocation(winrt::Windows::Storage::Pickers::PickerLocationId value) = 0;
    virtual HRESULT __stdcall get_CommitButtonText(hstring * value) = 0;
    virtual HRESULT __stdcall put_CommitButtonText(hstring value) = 0;
    virtual HRESULT __stdcall get_FileTypeFilter(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall abi_PickSingleFolderAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> ** pickSingleFolderOperation) = 0;
};

struct __declspec(uuid("8eb3ba97-dc85-4616-be94-9660881f2f5d")) __declspec(novtable) IFolderPicker2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContinuationData(Windows::Foundation::Collections::IPropertySet ** value) = 0;
    virtual HRESULT __stdcall abi_PickFolderAndContinue() = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Storage::Pickers::FileExtensionVector> { using default_interface = Windows::Foundation::Collections::IVector<hstring>; };
template <> struct traits<Windows::Storage::Pickers::FileOpenPicker> { using default_interface = Windows::Storage::Pickers::IFileOpenPicker; };
template <> struct traits<Windows::Storage::Pickers::FilePickerFileTypesOrderedMap> { using default_interface = Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::Collections::IVector<hstring>>; };
template <> struct traits<Windows::Storage::Pickers::FilePickerSelectedFilesArray> { using default_interface = Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>; };
template <> struct traits<Windows::Storage::Pickers::FileSavePicker> { using default_interface = Windows::Storage::Pickers::IFileSavePicker; };
template <> struct traits<Windows::Storage::Pickers::FolderPicker> { using default_interface = Windows::Storage::Pickers::IFolderPicker; };

}

namespace Windows::Storage::Pickers {

template <typename D>
struct WINRT_EBO impl_IFileOpenPicker
{
    Windows::Storage::Pickers::PickerViewMode ViewMode() const;
    void ViewMode(Windows::Storage::Pickers::PickerViewMode value) const;
    hstring SettingsIdentifier() const;
    void SettingsIdentifier(hstring_view value) const;
    Windows::Storage::Pickers::PickerLocationId SuggestedStartLocation() const;
    void SuggestedStartLocation(Windows::Storage::Pickers::PickerLocationId value) const;
    hstring CommitButtonText() const;
    void CommitButtonText(hstring_view value) const;
    Windows::Foundation::Collections::IVector<hstring> FileTypeFilter() const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> PickSingleFileAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> PickMultipleFilesAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IFileOpenPicker2
{
    [[deprecated("Instead, use PickSingleFileAsync/PickMultipleFilesAsync")]] Windows::Foundation::Collections::ValueSet ContinuationData() const;
    [[deprecated("Instead, use PickSingleFileAsync")]] void PickSingleFileAndContinue() const;
    [[deprecated("Instead, use PickMultipleFilesAsync")]] void PickMultipleFilesAndContinue() const;
};

template <typename D>
struct WINRT_EBO impl_IFileOpenPickerStatics
{
    [[deprecated("Instead, use PickSingleFileAsync")]] Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> ResumePickSingleFileAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IFileOpenPickerWithOperationId
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> PickSingleFileAsync(hstring_view pickerOperationId) const;
};

template <typename D>
struct WINRT_EBO impl_IFileSavePicker
{
    hstring SettingsIdentifier() const;
    void SettingsIdentifier(hstring_view value) const;
    Windows::Storage::Pickers::PickerLocationId SuggestedStartLocation() const;
    void SuggestedStartLocation(Windows::Storage::Pickers::PickerLocationId value) const;
    hstring CommitButtonText() const;
    void CommitButtonText(hstring_view value) const;
    Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::Collections::IVector<hstring>> FileTypeChoices() const;
    hstring DefaultFileExtension() const;
    void DefaultFileExtension(hstring_view value) const;
    Windows::Storage::StorageFile SuggestedSaveFile() const;
    void SuggestedSaveFile(const Windows::Storage::StorageFile & value) const;
    hstring SuggestedFileName() const;
    void SuggestedFileName(hstring_view value) const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> PickSaveFileAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IFileSavePicker2
{
    Windows::Foundation::Collections::ValueSet ContinuationData() const;
    [[deprecated("Instead, use PickSaveFileAsync")]] void PickSaveFileAndContinue() const;
};

template <typename D>
struct WINRT_EBO impl_IFileSavePicker3
{
    hstring EnterpriseId() const;
    void EnterpriseId(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IFolderPicker
{
    Windows::Storage::Pickers::PickerViewMode ViewMode() const;
    void ViewMode(Windows::Storage::Pickers::PickerViewMode value) const;
    hstring SettingsIdentifier() const;
    void SettingsIdentifier(hstring_view value) const;
    Windows::Storage::Pickers::PickerLocationId SuggestedStartLocation() const;
    void SuggestedStartLocation(Windows::Storage::Pickers::PickerLocationId value) const;
    hstring CommitButtonText() const;
    void CommitButtonText(hstring_view value) const;
    Windows::Foundation::Collections::IVector<hstring> FileTypeFilter() const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> PickSingleFolderAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IFolderPicker2
{
    Windows::Foundation::Collections::ValueSet ContinuationData() const;
    [[deprecated("Instead, use PickSingleFolderAsync")]] void PickFolderAndContinue() const;
};

}

namespace impl {

template <> struct traits<Windows::Storage::Pickers::IFileOpenPicker>
{
    using abi = ABI::Windows::Storage::Pickers::IFileOpenPicker;
    template <typename D> using consume = Windows::Storage::Pickers::impl_IFileOpenPicker<D>;
};

template <> struct traits<Windows::Storage::Pickers::IFileOpenPicker2>
{
    using abi = ABI::Windows::Storage::Pickers::IFileOpenPicker2;
    template <typename D> using consume = Windows::Storage::Pickers::impl_IFileOpenPicker2<D>;
};

template <> struct traits<Windows::Storage::Pickers::IFileOpenPickerStatics>
{
    using abi = ABI::Windows::Storage::Pickers::IFileOpenPickerStatics;
    template <typename D> using consume = Windows::Storage::Pickers::impl_IFileOpenPickerStatics<D>;
};

template <> struct traits<Windows::Storage::Pickers::IFileOpenPickerWithOperationId>
{
    using abi = ABI::Windows::Storage::Pickers::IFileOpenPickerWithOperationId;
    template <typename D> using consume = Windows::Storage::Pickers::impl_IFileOpenPickerWithOperationId<D>;
};

template <> struct traits<Windows::Storage::Pickers::IFileSavePicker>
{
    using abi = ABI::Windows::Storage::Pickers::IFileSavePicker;
    template <typename D> using consume = Windows::Storage::Pickers::impl_IFileSavePicker<D>;
};

template <> struct traits<Windows::Storage::Pickers::IFileSavePicker2>
{
    using abi = ABI::Windows::Storage::Pickers::IFileSavePicker2;
    template <typename D> using consume = Windows::Storage::Pickers::impl_IFileSavePicker2<D>;
};

template <> struct traits<Windows::Storage::Pickers::IFileSavePicker3>
{
    using abi = ABI::Windows::Storage::Pickers::IFileSavePicker3;
    template <typename D> using consume = Windows::Storage::Pickers::impl_IFileSavePicker3<D>;
};

template <> struct traits<Windows::Storage::Pickers::IFolderPicker>
{
    using abi = ABI::Windows::Storage::Pickers::IFolderPicker;
    template <typename D> using consume = Windows::Storage::Pickers::impl_IFolderPicker<D>;
};

template <> struct traits<Windows::Storage::Pickers::IFolderPicker2>
{
    using abi = ABI::Windows::Storage::Pickers::IFolderPicker2;
    template <typename D> using consume = Windows::Storage::Pickers::impl_IFolderPicker2<D>;
};

template <> struct traits<Windows::Storage::Pickers::FileExtensionVector>
{
    using abi = ABI::Windows::Storage::Pickers::FileExtensionVector;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.Pickers.FileExtensionVector"; }
};

template <> struct traits<Windows::Storage::Pickers::FileOpenPicker>
{
    using abi = ABI::Windows::Storage::Pickers::FileOpenPicker;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.Pickers.FileOpenPicker"; }
};

template <> struct traits<Windows::Storage::Pickers::FilePickerFileTypesOrderedMap>
{
    using abi = ABI::Windows::Storage::Pickers::FilePickerFileTypesOrderedMap;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.Pickers.FilePickerFileTypesOrderedMap"; }
};

template <> struct traits<Windows::Storage::Pickers::FilePickerSelectedFilesArray>
{
    using abi = ABI::Windows::Storage::Pickers::FilePickerSelectedFilesArray;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.Pickers.FilePickerSelectedFilesArray"; }
};

template <> struct traits<Windows::Storage::Pickers::FileSavePicker>
{
    using abi = ABI::Windows::Storage::Pickers::FileSavePicker;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.Pickers.FileSavePicker"; }
};

template <> struct traits<Windows::Storage::Pickers::FolderPicker>
{
    using abi = ABI::Windows::Storage::Pickers::FolderPicker;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.Pickers.FolderPicker"; }
};

}

}
