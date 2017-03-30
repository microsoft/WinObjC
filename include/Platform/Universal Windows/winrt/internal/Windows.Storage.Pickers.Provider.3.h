// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.Pickers.Provider.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Storage::Pickers::Provider {

struct WINRT_EBO FileOpenPickerUI :
    Windows::Storage::Pickers::Provider::IFileOpenPickerUI
{
    FileOpenPickerUI(std::nullptr_t) noexcept {}
};

struct [[deprecated("Since Windows 10, only apps can remove files, not end users so the FileRemoved event will not be raised.")]] WINRT_EBO FileRemovedEventArgs :
    Windows::Storage::Pickers::Provider::IFileRemovedEventArgs
{
    FileRemovedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FileSavePickerUI :
    Windows::Storage::Pickers::Provider::IFileSavePickerUI
{
    FileSavePickerUI(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PickerClosingDeferral :
    Windows::Storage::Pickers::Provider::IPickerClosingDeferral
{
    PickerClosingDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PickerClosingEventArgs :
    Windows::Storage::Pickers::Provider::IPickerClosingEventArgs
{
    PickerClosingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PickerClosingOperation :
    Windows::Storage::Pickers::Provider::IPickerClosingOperation
{
    PickerClosingOperation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TargetFileRequest :
    Windows::Storage::Pickers::Provider::ITargetFileRequest
{
    TargetFileRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TargetFileRequestDeferral :
    Windows::Storage::Pickers::Provider::ITargetFileRequestDeferral
{
    TargetFileRequestDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TargetFileRequestedEventArgs :
    Windows::Storage::Pickers::Provider::ITargetFileRequestedEventArgs
{
    TargetFileRequestedEventArgs(std::nullptr_t) noexcept {}
};

}

}
