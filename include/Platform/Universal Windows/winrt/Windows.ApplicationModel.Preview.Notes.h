// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.ApplicationModel.Preview.Notes.3.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Preview::Notes::INotePlacementChangedPreviewEventArgs> : produce_base<D, Windows::ApplicationModel::Preview::Notes::INotePlacementChangedPreviewEventArgs>
{
    HRESULT __stdcall get_ViewId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ViewId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Preview::Notes::INoteVisibilityChangedPreviewEventArgs> : produce_base<D, Windows::ApplicationModel::Preview::Notes::INoteVisibilityChangedPreviewEventArgs>
{
    HRESULT __stdcall get_ViewId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ViewId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview> : produce_base<D, Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>
{
    HRESULT __stdcall get_IsScreenLocked(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsScreenLocked());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowNote(int32_t noteViewId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowNote(noteViewId);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowNoteRelativeTo(int32_t noteViewId, int32_t anchorNoteViewId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowNoteRelativeTo(noteViewId, anchorNoteViewId);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowNoteWithPlacement(int32_t noteViewId, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> data) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowNoteWithPlacement(noteViewId, *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&data));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_HideNote(int32_t noteViewId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HideNote(noteViewId);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNotePlacement(int32_t noteViewId, impl::abi_arg_out<Windows::Storage::Streams::IBuffer> data) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *data = detach_abi(this->shim().GetNotePlacement(noteViewId));
            return S_OK;
        }
        catch (...)
        {
            *data = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetNoteSize(int32_t noteViewId, impl::abi_arg_in<Windows::Foundation::Size> size, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TrySetNoteSize(noteViewId, *reinterpret_cast<const Windows::Foundation::Size *>(&size)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetFocusToNextView() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFocusToNextView();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetNotesThumbnailAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> thumbnail, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SetNotesThumbnailAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&thumbnail)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SystemLockStateChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SystemLockStateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SystemLockStateChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SystemLockStateChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_NotePlacementChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NotePlacementChangedPreviewEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().NotePlacementChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NotePlacementChangedPreviewEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_NotePlacementChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotePlacementChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_NoteVisibilityChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NoteVisibilityChangedPreviewEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().NoteVisibilityChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NoteVisibilityChangedPreviewEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_NoteVisibilityChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NoteVisibilityChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewStatics> : produce_base<D, Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewStatics>
{
    HRESULT __stdcall abi_GetForCurrentApp(impl::abi_arg_out<Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview> current) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *current = detach_abi(this->shim().GetForCurrentApp());
            return S_OK;
        }
        catch (...)
        {
            *current = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Preview::Notes {

template <typename D> int32_t impl_INotePlacementChangedPreviewEventArgs<D>::ViewId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(INotePlacementChangedPreviewEventArgs)->get_ViewId(&value));
    return value;
}

template <typename D> int32_t impl_INoteVisibilityChangedPreviewEventArgs<D>::ViewId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(INoteVisibilityChangedPreviewEventArgs)->get_ViewId(&value));
    return value;
}

template <typename D> bool impl_INoteVisibilityChangedPreviewEventArgs<D>::IsVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(INoteVisibilityChangedPreviewEventArgs)->get_IsVisible(&value));
    return value;
}

template <typename D> bool impl_INotesWindowManagerPreview<D>::IsScreenLocked() const
{
    bool value {};
    check_hresult(WINRT_SHIM(INotesWindowManagerPreview)->get_IsScreenLocked(&value));
    return value;
}

template <typename D> void impl_INotesWindowManagerPreview<D>::ShowNote(int32_t noteViewId) const
{
    check_hresult(WINRT_SHIM(INotesWindowManagerPreview)->abi_ShowNote(noteViewId));
}

template <typename D> void impl_INotesWindowManagerPreview<D>::ShowNoteRelativeTo(int32_t noteViewId, int32_t anchorNoteViewId) const
{
    check_hresult(WINRT_SHIM(INotesWindowManagerPreview)->abi_ShowNoteRelativeTo(noteViewId, anchorNoteViewId));
}

template <typename D> void impl_INotesWindowManagerPreview<D>::ShowNoteWithPlacement(int32_t noteViewId, const Windows::Storage::Streams::IBuffer & data) const
{
    check_hresult(WINRT_SHIM(INotesWindowManagerPreview)->abi_ShowNoteWithPlacement(noteViewId, get_abi(data)));
}

template <typename D> void impl_INotesWindowManagerPreview<D>::HideNote(int32_t noteViewId) const
{
    check_hresult(WINRT_SHIM(INotesWindowManagerPreview)->abi_HideNote(noteViewId));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_INotesWindowManagerPreview<D>::GetNotePlacement(int32_t noteViewId) const
{
    Windows::Storage::Streams::IBuffer data;
    check_hresult(WINRT_SHIM(INotesWindowManagerPreview)->abi_GetNotePlacement(noteViewId, put_abi(data)));
    return data;
}

template <typename D> bool impl_INotesWindowManagerPreview<D>::TrySetNoteSize(int32_t noteViewId, const Windows::Foundation::Size & size) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(INotesWindowManagerPreview)->abi_TrySetNoteSize(noteViewId, get_abi(size), &succeeded));
    return succeeded;
}

template <typename D> void impl_INotesWindowManagerPreview<D>::SetFocusToNextView() const
{
    check_hresult(WINRT_SHIM(INotesWindowManagerPreview)->abi_SetFocusToNextView());
}

template <typename D> Windows::Foundation::IAsyncAction impl_INotesWindowManagerPreview<D>::SetNotesThumbnailAsync(const Windows::Storage::Streams::IBuffer & thumbnail) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(INotesWindowManagerPreview)->abi_SetNotesThumbnailAsync(get_abi(thumbnail), put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_INotesWindowManagerPreview<D>::SystemLockStateChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(INotesWindowManagerPreview)->add_SystemLockStateChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<INotesWindowManagerPreview> impl_INotesWindowManagerPreview<D>::SystemLockStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, INotesWindowManagerPreview>(this, &ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview::remove_SystemLockStateChanged, SystemLockStateChanged(handler));
}

template <typename D> void impl_INotesWindowManagerPreview<D>::SystemLockStateChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(INotesWindowManagerPreview)->remove_SystemLockStateChanged(token));
}

template <typename D> event_token impl_INotesWindowManagerPreview<D>::NotePlacementChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NotePlacementChangedPreviewEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(INotesWindowManagerPreview)->add_NotePlacementChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<INotesWindowManagerPreview> impl_INotesWindowManagerPreview<D>::NotePlacementChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NotePlacementChangedPreviewEventArgs> & handler) const
{
    return impl::make_event_revoker<D, INotesWindowManagerPreview>(this, &ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview::remove_NotePlacementChanged, NotePlacementChanged(handler));
}

template <typename D> void impl_INotesWindowManagerPreview<D>::NotePlacementChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(INotesWindowManagerPreview)->remove_NotePlacementChanged(token));
}

template <typename D> event_token impl_INotesWindowManagerPreview<D>::NoteVisibilityChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NoteVisibilityChangedPreviewEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(INotesWindowManagerPreview)->add_NoteVisibilityChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<INotesWindowManagerPreview> impl_INotesWindowManagerPreview<D>::NoteVisibilityChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, Windows::ApplicationModel::Preview::Notes::NoteVisibilityChangedPreviewEventArgs> & handler) const
{
    return impl::make_event_revoker<D, INotesWindowManagerPreview>(this, &ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview::remove_NoteVisibilityChanged, NoteVisibilityChanged(handler));
}

template <typename D> void impl_INotesWindowManagerPreview<D>::NoteVisibilityChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(INotesWindowManagerPreview)->remove_NoteVisibilityChanged(token));
}

template <typename D> Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview impl_INotesWindowManagerPreviewStatics<D>::GetForCurrentApp() const
{
    Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview current { nullptr };
    check_hresult(WINRT_SHIM(INotesWindowManagerPreviewStatics)->abi_GetForCurrentApp(put_abi(current)));
    return current;
}

inline Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview NotesWindowManagerPreview::GetForCurrentApp()
{
    return get_activation_factory<NotesWindowManagerPreview, INotesWindowManagerPreviewStatics>().GetForCurrentApp();
}

}

}
#pragma warning(pop)
