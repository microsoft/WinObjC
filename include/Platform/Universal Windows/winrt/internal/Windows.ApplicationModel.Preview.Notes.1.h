// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Preview.Notes.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Preview::Notes {

struct __declspec(uuid("491d57b7-f780-4e7f-a939-9a4caf965214")) __declspec(novtable) INotePlacementChangedPreviewEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ViewId(int32_t * value) = 0;
};

struct __declspec(uuid("0e34649e-3815-4ff6-83b3-a14d17120e24")) __declspec(novtable) INoteVisibilityChangedPreviewEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ViewId(int32_t * value) = 0;
    virtual HRESULT __stdcall get_IsVisible(bool * value) = 0;
};

struct __declspec(uuid("dc2ac23e-4850-4f13-9cc7-ff487efdfcde")) __declspec(novtable) INotesWindowManagerPreview : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsScreenLocked(bool * value) = 0;
    virtual HRESULT __stdcall abi_ShowNote(int32_t noteViewId) = 0;
    virtual HRESULT __stdcall abi_ShowNoteRelativeTo(int32_t noteViewId, int32_t anchorNoteViewId) = 0;
    virtual HRESULT __stdcall abi_ShowNoteWithPlacement(int32_t noteViewId, Windows::Storage::Streams::IBuffer * data) = 0;
    virtual HRESULT __stdcall abi_HideNote(int32_t noteViewId) = 0;
    virtual HRESULT __stdcall abi_GetNotePlacement(int32_t noteViewId, Windows::Storage::Streams::IBuffer ** data) = 0;
    virtual HRESULT __stdcall abi_TrySetNoteSize(int32_t noteViewId, Windows::Foundation::Size size, bool * succeeded) = 0;
    virtual HRESULT __stdcall abi_SetFocusToNextView() = 0;
    virtual HRESULT __stdcall abi_SetNotesThumbnailAsync(Windows::Storage::Streams::IBuffer * thumbnail, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall add_SystemLockStateChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SystemLockStateChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_NotePlacementChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NotePlacementChangedPreviewEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_NotePlacementChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_NoteVisibilityChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NoteVisibilityChangedPreviewEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_NoteVisibilityChanged(event_token token) = 0;
};

struct __declspec(uuid("6668cc88-0a8e-4127-a38e-995445868a78")) __declspec(novtable) INotesWindowManagerPreviewStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentApp(Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview ** current) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Preview::Notes::NotePlacementChangedPreviewEventArgs> { using default_interface = Windows::ApplicationModel::Preview::Notes::INotePlacementChangedPreviewEventArgs; };
template <> struct traits<Windows::ApplicationModel::Preview::Notes::NoteVisibilityChangedPreviewEventArgs> { using default_interface = Windows::ApplicationModel::Preview::Notes::INoteVisibilityChangedPreviewEventArgs; };
template <> struct traits<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview> { using default_interface = Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview; };

}

namespace Windows::ApplicationModel::Preview::Notes {

template <typename D>
struct WINRT_EBO impl_INotePlacementChangedPreviewEventArgs
{
    int32_t ViewId() const;
};

template <typename D>
struct WINRT_EBO impl_INoteVisibilityChangedPreviewEventArgs
{
    int32_t ViewId() const;
    bool IsVisible() const;
};

template <typename D>
struct WINRT_EBO impl_INotesWindowManagerPreview
{
    bool IsScreenLocked() const;
    void ShowNote(int32_t noteViewId) const;
    void ShowNoteRelativeTo(int32_t noteViewId, int32_t anchorNoteViewId) const;
    void ShowNoteWithPlacement(int32_t noteViewId, const Windows::Storage::Streams::IBuffer & data) const;
    void HideNote(int32_t noteViewId) const;
    Windows::Storage::Streams::IBuffer GetNotePlacement(int32_t noteViewId) const;
    bool TrySetNoteSize(int32_t noteViewId, const Windows::Foundation::Size & size) const;
    void SetFocusToNextView() const;
    Windows::Foundation::IAsyncAction SetNotesThumbnailAsync(const Windows::Storage::Streams::IBuffer & thumbnail) const;
    event_token SystemLockStateChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::Foundation::IInspectable> & handler) const;
    using SystemLockStateChanged_revoker = event_revoker<INotesWindowManagerPreview>;
    SystemLockStateChanged_revoker SystemLockStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::Foundation::IInspectable> & handler) const;
    void SystemLockStateChanged(event_token token) const;
    event_token NotePlacementChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NotePlacementChangedPreviewEventArgs> & handler) const;
    using NotePlacementChanged_revoker = event_revoker<INotesWindowManagerPreview>;
    NotePlacementChanged_revoker NotePlacementChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NotePlacementChangedPreviewEventArgs> & handler) const;
    void NotePlacementChanged(event_token token) const;
    event_token NoteVisibilityChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NoteVisibilityChangedPreviewEventArgs> & handler) const;
    using NoteVisibilityChanged_revoker = event_revoker<INotesWindowManagerPreview>;
    NoteVisibilityChanged_revoker NoteVisibilityChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NoteVisibilityChangedPreviewEventArgs> & handler) const;
    void NoteVisibilityChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_INotesWindowManagerPreviewStatics
{
    Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview GetForCurrentApp() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Preview::Notes::INotePlacementChangedPreviewEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Preview::Notes::INotePlacementChangedPreviewEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Preview::Notes::impl_INotePlacementChangedPreviewEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Preview::Notes::INoteVisibilityChangedPreviewEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Preview::Notes::INoteVisibilityChangedPreviewEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Preview::Notes::impl_INoteVisibilityChangedPreviewEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>
{
    using abi = ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview;
    template <typename D> using consume = Windows::ApplicationModel::Preview::Notes::impl_INotesWindowManagerPreview<D>;
};

template <> struct traits<Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewStatics>
{
    using abi = ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewStatics;
    template <typename D> using consume = Windows::ApplicationModel::Preview::Notes::impl_INotesWindowManagerPreviewStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Preview::Notes::NotePlacementChangedPreviewEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Preview::Notes::NotePlacementChangedPreviewEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Preview.Notes.NotePlacementChangedPreviewEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Preview::Notes::NoteVisibilityChangedPreviewEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Preview::Notes::NoteVisibilityChangedPreviewEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Preview.Notes.NoteVisibilityChangedPreviewEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview>
{
    using abi = ABI::Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Preview.Notes.NotesWindowManagerPreview"; }
};

}

}
