// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.Pickers.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Storage::Pickers {

struct WINRT_EBO FileExtensionVector :
    Windows::Foundation::Collections::IVector<hstring>
{
    FileExtensionVector(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FileOpenPicker :
    Windows::Storage::Pickers::IFileOpenPicker,
    impl::require<FileOpenPicker, Windows::Storage::Pickers::IFileOpenPicker2, Windows::Storage::Pickers::IFileOpenPickerWithOperationId>
{
    FileOpenPicker(std::nullptr_t) noexcept {}
    FileOpenPicker();
    using impl_IFileOpenPicker::PickSingleFileAsync;
    using impl_IFileOpenPickerWithOperationId::PickSingleFileAsync;
    [[deprecated("Instead, use PickSingleFileAsync")]] static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> ResumePickSingleFileAsync();
};

struct WINRT_EBO FilePickerFileTypesOrderedMap :
    Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::Collections::IVector<hstring>>
{
    FilePickerFileTypesOrderedMap(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FilePickerSelectedFilesArray :
    Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>
{
    FilePickerSelectedFilesArray(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FileSavePicker :
    Windows::Storage::Pickers::IFileSavePicker,
    impl::require<FileSavePicker, Windows::Storage::Pickers::IFileSavePicker2, Windows::Storage::Pickers::IFileSavePicker3>
{
    FileSavePicker(std::nullptr_t) noexcept {}
    FileSavePicker();
};

struct WINRT_EBO FolderPicker :
    Windows::Storage::Pickers::IFolderPicker,
    impl::require<FolderPicker, Windows::Storage::Pickers::IFolderPicker2>
{
    FolderPicker(std::nullptr_t) noexcept {}
    FolderPicker();
};

}

}
