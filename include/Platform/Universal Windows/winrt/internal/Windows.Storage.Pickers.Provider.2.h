// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.Pickers.Provider.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_f1fb2939_695b_5f56_841a_a52a7d148572
#define WINRT_GENERIC_f1fb2939_695b_5f56_841a_a52a7d148572
template <> struct __declspec(uuid("f1fb2939-695b-5f56-841a-a52a7d148572")) __declspec(novtable) TypedEventHandler<Windows::Storage::Pickers::Provider::FileOpenPickerUI, Windows::Storage::Pickers::Provider::FileRemovedEventArgs> : impl_TypedEventHandler<Windows::Storage::Pickers::Provider::FileOpenPickerUI, Windows::Storage::Pickers::Provider::FileRemovedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_2b06bdac_983b_5552_b5c9_b0990a2db3a1
#define WINRT_GENERIC_2b06bdac_983b_5552_b5c9_b0990a2db3a1
template <> struct __declspec(uuid("2b06bdac-983b-5552-b5c9-b0990a2db3a1")) __declspec(novtable) TypedEventHandler<Windows::Storage::Pickers::Provider::FileOpenPickerUI, Windows::Storage::Pickers::Provider::PickerClosingEventArgs> : impl_TypedEventHandler<Windows::Storage::Pickers::Provider::FileOpenPickerUI, Windows::Storage::Pickers::Provider::PickerClosingEventArgs> {};
#endif

#ifndef WINRT_GENERIC_f1e6a632_f97f_54d9_9e1b_a714edc3ff06
#define WINRT_GENERIC_f1e6a632_f97f_54d9_9e1b_a714edc3ff06
template <> struct __declspec(uuid("f1e6a632-f97f-54d9-9e1b-a714edc3ff06")) __declspec(novtable) TypedEventHandler<Windows::Storage::Pickers::Provider::FileSavePickerUI, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Storage::Pickers::Provider::FileSavePickerUI, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_d3e1f8c7_45c5_5249_b336_a111bfaa985b
#define WINRT_GENERIC_d3e1f8c7_45c5_5249_b336_a111bfaa985b
template <> struct __declspec(uuid("d3e1f8c7-45c5-5249-b336-a111bfaa985b")) __declspec(novtable) TypedEventHandler<Windows::Storage::Pickers::Provider::FileSavePickerUI, Windows::Storage::Pickers::Provider::TargetFileRequestedEventArgs> : impl_TypedEventHandler<Windows::Storage::Pickers::Provider::FileSavePickerUI, Windows::Storage::Pickers::Provider::TargetFileRequestedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif


}

namespace Windows::Storage::Pickers::Provider {

struct IFileOpenPickerUI :
    Windows::Foundation::IInspectable,
    impl::consume<IFileOpenPickerUI>
{
    IFileOpenPickerUI(std::nullptr_t = nullptr) noexcept {}
};

struct [[deprecated("Since Windows 10, only apps can remove files, not end users so the FileRemoved event will not be raised.")]] IFileRemovedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IFileRemovedEventArgs>
{
    IFileRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IFileSavePickerUI :
    Windows::Foundation::IInspectable,
    impl::consume<IFileSavePickerUI>
{
    IFileSavePickerUI(std::nullptr_t = nullptr) noexcept {}
};

struct IPickerClosingDeferral :
    Windows::Foundation::IInspectable,
    impl::consume<IPickerClosingDeferral>
{
    IPickerClosingDeferral(std::nullptr_t = nullptr) noexcept {}
};

struct IPickerClosingEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPickerClosingEventArgs>
{
    IPickerClosingEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPickerClosingOperation :
    Windows::Foundation::IInspectable,
    impl::consume<IPickerClosingOperation>
{
    IPickerClosingOperation(std::nullptr_t = nullptr) noexcept {}
};

struct ITargetFileRequest :
    Windows::Foundation::IInspectable,
    impl::consume<ITargetFileRequest>
{
    ITargetFileRequest(std::nullptr_t = nullptr) noexcept {}
};

struct ITargetFileRequestDeferral :
    Windows::Foundation::IInspectable,
    impl::consume<ITargetFileRequestDeferral>
{
    ITargetFileRequestDeferral(std::nullptr_t = nullptr) noexcept {}
};

struct ITargetFileRequestedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ITargetFileRequestedEventArgs>
{
    ITargetFileRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

}

}
