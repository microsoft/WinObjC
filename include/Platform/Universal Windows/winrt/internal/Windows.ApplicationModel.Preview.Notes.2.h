// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Preview.Notes.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_6f2755fb_6c33_543c_9ab4_de486bc7bfe2
#define WINRT_GENERIC_6f2755fb_6c33_543c_9ab4_de486bc7bfe2
template <> struct __declspec(uuid("6f2755fb-6c33-543c-9ab4-de486bc7bfe2")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_a28af2c7_4012_5999_a322_5236b30d995f
#define WINRT_GENERIC_a28af2c7_4012_5999_a322_5236b30d995f
template <> struct __declspec(uuid("a28af2c7-4012-5999-a322-5236b30d995f")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NotePlacementChangedPreviewEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NotePlacementChangedPreviewEventArgs> {};
#endif

#ifndef WINRT_GENERIC_16d825c8_5271_51c8_a00f_0cfb1b029ab6
#define WINRT_GENERIC_16d825c8_5271_51c8_a00f_0cfb1b029ab6
template <> struct __declspec(uuid("16d825c8-5271-51c8-a00f-0cfb1b029ab6")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NoteVisibilityChangedPreviewEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NoteVisibilityChangedPreviewEventArgs> {};
#endif


}

namespace Windows::ApplicationModel::Preview::Notes {

struct INotePlacementChangedPreviewEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<INotePlacementChangedPreviewEventArgs>
{
    INotePlacementChangedPreviewEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct INoteVisibilityChangedPreviewEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<INoteVisibilityChangedPreviewEventArgs>
{
    INoteVisibilityChangedPreviewEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct INotesWindowManagerPreview :
    Windows::Foundation::IInspectable,
    impl::consume<INotesWindowManagerPreview>
{
    INotesWindowManagerPreview(std::nullptr_t = nullptr) noexcept {}
};

struct INotesWindowManagerPreviewStatics :
    Windows::Foundation::IInspectable,
    impl::consume<INotesWindowManagerPreviewStatics>
{
    INotesWindowManagerPreviewStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
