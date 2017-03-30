// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Storage::Pickers::Provider {

struct IFileOpenPickerUI;
struct IFileRemovedEventArgs;
struct IFileSavePickerUI;
struct IPickerClosingDeferral;
struct IPickerClosingEventArgs;
struct IPickerClosingOperation;
struct ITargetFileRequest;
struct ITargetFileRequestDeferral;
struct ITargetFileRequestedEventArgs;
struct FileOpenPickerUI;
struct FileRemovedEventArgs;
struct FileSavePickerUI;
struct PickerClosingDeferral;
struct PickerClosingEventArgs;
struct PickerClosingOperation;
struct TargetFileRequest;
struct TargetFileRequestDeferral;
struct TargetFileRequestedEventArgs;

}

namespace Windows::Storage::Pickers::Provider {

struct IFileOpenPickerUI;
struct IFileRemovedEventArgs;
struct IFileSavePickerUI;
struct IPickerClosingDeferral;
struct IPickerClosingEventArgs;
struct IPickerClosingOperation;
struct ITargetFileRequest;
struct ITargetFileRequestDeferral;
struct ITargetFileRequestedEventArgs;
struct FileOpenPickerUI;
struct FileRemovedEventArgs;
struct FileSavePickerUI;
struct PickerClosingDeferral;
struct PickerClosingEventArgs;
struct PickerClosingOperation;
struct TargetFileRequest;
struct TargetFileRequestDeferral;
struct TargetFileRequestedEventArgs;

}

namespace Windows::Storage::Pickers::Provider {

template <typename T> struct impl_IFileOpenPickerUI;
template <typename T> struct impl_IFileRemovedEventArgs;
template <typename T> struct impl_IFileSavePickerUI;
template <typename T> struct impl_IPickerClosingDeferral;
template <typename T> struct impl_IPickerClosingEventArgs;
template <typename T> struct impl_IPickerClosingOperation;
template <typename T> struct impl_ITargetFileRequest;
template <typename T> struct impl_ITargetFileRequestDeferral;
template <typename T> struct impl_ITargetFileRequestedEventArgs;

}

namespace Windows::Storage::Pickers::Provider {

enum class AddFileResult
{
    Added = 0,
    AlreadyAdded = 1,
    NotAllowed = 2,
    Unavailable = 3,
};

enum class FileSelectionMode
{
    Single = 0,
    Multiple = 1,
};

enum class SetFileNameResult
{
    Succeeded = 0,
    NotAllowed = 1,
    Unavailable = 2,
};

}

}
