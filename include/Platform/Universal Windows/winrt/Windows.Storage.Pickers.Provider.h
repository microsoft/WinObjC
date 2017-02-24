// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Pickers.Provider.3.h"
#include "Windows.Storage.Pickers.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Storage::Pickers::Provider::IFileOpenPickerUI> : produce_base<D, Windows::Storage::Pickers::Provider::IFileOpenPickerUI>
{
    HRESULT __stdcall abi_AddFile(impl::abi_arg_in<hstring> id, impl::abi_arg_in<Windows::Storage::IStorageFile> file, Windows::Storage::Pickers::Provider::AddFileResult * addResult) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *addResult = detach_abi(this->shim().AddFile(*reinterpret_cast<const hstring *>(&id), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveFile(impl::abi_arg_in<hstring> id) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveFile(*reinterpret_cast<const hstring *>(&id));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ContainsFile(impl::abi_arg_in<hstring> id, bool * isContained) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *isContained = detach_abi(this->shim().ContainsFile(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CanAddFile(impl::abi_arg_in<Windows::Storage::IStorageFile> file, bool * canAdd) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *canAdd = detach_abi(this->shim().CanAddFile(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowedFileTypes(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowedFileTypes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SelectionMode(Windows::Storage::Pickers::Provider::FileSelectionMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelectionMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SettingsIdentifier(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SettingsIdentifier());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_FileRemoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Storage::Pickers::Provider::FileOpenPickerUI, Windows::Storage::Pickers::Provider::FileRemovedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().FileRemoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Storage::Pickers::Provider::FileOpenPickerUI, Windows::Storage::Pickers::Provider::FileRemovedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_FileRemoved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FileRemoved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Closing(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Storage::Pickers::Provider::FileOpenPickerUI, Windows::Storage::Pickers::Provider::PickerClosingEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Closing(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Storage::Pickers::Provider::FileOpenPickerUI, Windows::Storage::Pickers::Provider::PickerClosingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Closing(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Closing(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Pickers::Provider::IFileRemovedEventArgs> : produce_base<D, Windows::Storage::Pickers::Provider::IFileRemovedEventArgs>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Pickers::Provider::IFileSavePickerUI> : produce_base<D, Windows::Storage::Pickers::Provider::IFileSavePickerUI>
{
    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowedFileTypes(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowedFileTypes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SettingsIdentifier(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SettingsIdentifier());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FileName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FileName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetFileName(impl::abi_arg_in<hstring> value, Windows::Storage::Pickers::Provider::SetFileNameResult * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TrySetFileName(*reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_FileNameChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Storage::Pickers::Provider::FileSavePickerUI, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().FileNameChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Storage::Pickers::Provider::FileSavePickerUI, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_FileNameChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FileNameChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TargetFileRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Storage::Pickers::Provider::FileSavePickerUI, Windows::Storage::Pickers::Provider::TargetFileRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().TargetFileRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Storage::Pickers::Provider::FileSavePickerUI, Windows::Storage::Pickers::Provider::TargetFileRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TargetFileRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetFileRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Pickers::Provider::IPickerClosingDeferral> : produce_base<D, Windows::Storage::Pickers::Provider::IPickerClosingDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Pickers::Provider::IPickerClosingEventArgs> : produce_base<D, Windows::Storage::Pickers::Provider::IPickerClosingEventArgs>
{
    HRESULT __stdcall get_ClosingOperation(impl::abi_arg_out<Windows::Storage::Pickers::Provider::IPickerClosingOperation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClosingOperation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCanceled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCanceled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Pickers::Provider::IPickerClosingOperation> : produce_base<D, Windows::Storage::Pickers::Provider::IPickerClosingOperation>
{
    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Storage::Pickers::Provider::IPickerClosingDeferral> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Deadline(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Deadline());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Pickers::Provider::ITargetFileRequest> : produce_base<D, Windows::Storage::Pickers::Provider::ITargetFileRequest>
{
    HRESULT __stdcall get_TargetFile(impl::abi_arg_out<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetFile());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetFile(impl::abi_arg_in<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetFile(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Storage::Pickers::Provider::ITargetFileRequestDeferral> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Pickers::Provider::ITargetFileRequestDeferral> : produce_base<D, Windows::Storage::Pickers::Provider::ITargetFileRequestDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Pickers::Provider::ITargetFileRequestedEventArgs> : produce_base<D, Windows::Storage::Pickers::Provider::ITargetFileRequestedEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::Storage::Pickers::Provider::ITargetFileRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Request());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Storage::Pickers::Provider {

template <typename D> hstring impl_IFileRemovedEventArgs<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileRemovedEventArgs)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Pickers::Provider::AddFileResult impl_IFileOpenPickerUI<D>::AddFile(hstring_view id, const Windows::Storage::IStorageFile & file) const
{
    Windows::Storage::Pickers::Provider::AddFileResult addResult {};
    check_hresult(WINRT_SHIM(IFileOpenPickerUI)->abi_AddFile(get_abi(id), get_abi(file), &addResult));
    return addResult;
}

template <typename D> void impl_IFileOpenPickerUI<D>::RemoveFile(hstring_view id) const
{
    check_hresult(WINRT_SHIM(IFileOpenPickerUI)->abi_RemoveFile(get_abi(id)));
}

template <typename D> bool impl_IFileOpenPickerUI<D>::ContainsFile(hstring_view id) const
{
    bool isContained {};
    check_hresult(WINRT_SHIM(IFileOpenPickerUI)->abi_ContainsFile(get_abi(id), &isContained));
    return isContained;
}

template <typename D> bool impl_IFileOpenPickerUI<D>::CanAddFile(const Windows::Storage::IStorageFile & file) const
{
    bool canAdd {};
    check_hresult(WINRT_SHIM(IFileOpenPickerUI)->abi_CanAddFile(get_abi(file), &canAdd));
    return canAdd;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IFileOpenPickerUI<D>::AllowedFileTypes() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IFileOpenPickerUI)->get_AllowedFileTypes(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Pickers::Provider::FileSelectionMode impl_IFileOpenPickerUI<D>::SelectionMode() const
{
    Windows::Storage::Pickers::Provider::FileSelectionMode value {};
    check_hresult(WINRT_SHIM(IFileOpenPickerUI)->get_SelectionMode(&value));
    return value;
}

template <typename D> hstring impl_IFileOpenPickerUI<D>::SettingsIdentifier() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileOpenPickerUI)->get_SettingsIdentifier(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IFileOpenPickerUI<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileOpenPickerUI)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_IFileOpenPickerUI<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IFileOpenPickerUI)->put_Title(get_abi(value)));
}

template <typename D> event_token impl_IFileOpenPickerUI<D>::FileRemoved(const Windows::Foundation::TypedEventHandler<Windows::Storage::Pickers::Provider::FileOpenPickerUI, Windows::Storage::Pickers::Provider::FileRemovedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IFileOpenPickerUI)->add_FileRemoved(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IFileOpenPickerUI> impl_IFileOpenPickerUI<D>::FileRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Storage::Pickers::Provider::FileOpenPickerUI, Windows::Storage::Pickers::Provider::FileRemovedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IFileOpenPickerUI>(this, &ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI::remove_FileRemoved, FileRemoved(handler));
}

template <typename D> void impl_IFileOpenPickerUI<D>::FileRemoved(event_token token) const
{
    check_hresult(WINRT_SHIM(IFileOpenPickerUI)->remove_FileRemoved(token));
}

template <typename D> event_token impl_IFileOpenPickerUI<D>::Closing(const Windows::Foundation::TypedEventHandler<Windows::Storage::Pickers::Provider::FileOpenPickerUI, Windows::Storage::Pickers::Provider::PickerClosingEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IFileOpenPickerUI)->add_Closing(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IFileOpenPickerUI> impl_IFileOpenPickerUI<D>::Closing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Storage::Pickers::Provider::FileOpenPickerUI, Windows::Storage::Pickers::Provider::PickerClosingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IFileOpenPickerUI>(this, &ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI::remove_Closing, Closing(handler));
}

template <typename D> void impl_IFileOpenPickerUI<D>::Closing(event_token token) const
{
    check_hresult(WINRT_SHIM(IFileOpenPickerUI)->remove_Closing(token));
}

template <typename D> Windows::Storage::Pickers::Provider::PickerClosingOperation impl_IPickerClosingEventArgs<D>::ClosingOperation() const
{
    Windows::Storage::Pickers::Provider::PickerClosingOperation value { nullptr };
    check_hresult(WINRT_SHIM(IPickerClosingEventArgs)->get_ClosingOperation(put_abi(value)));
    return value;
}

template <typename D> bool impl_IPickerClosingEventArgs<D>::IsCanceled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPickerClosingEventArgs)->get_IsCanceled(&value));
    return value;
}

template <typename D> Windows::Storage::Pickers::Provider::PickerClosingDeferral impl_IPickerClosingOperation<D>::GetDeferral() const
{
    Windows::Storage::Pickers::Provider::PickerClosingDeferral value { nullptr };
    check_hresult(WINRT_SHIM(IPickerClosingOperation)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IPickerClosingOperation<D>::Deadline() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IPickerClosingOperation)->get_Deadline(put_abi(value)));
    return value;
}

template <typename D> void impl_IPickerClosingDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IPickerClosingDeferral)->abi_Complete());
}

template <typename D> hstring impl_IFileSavePickerUI<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileSavePickerUI)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_IFileSavePickerUI<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IFileSavePickerUI)->put_Title(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IFileSavePickerUI<D>::AllowedFileTypes() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IFileSavePickerUI)->get_AllowedFileTypes(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IFileSavePickerUI<D>::SettingsIdentifier() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileSavePickerUI)->get_SettingsIdentifier(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IFileSavePickerUI<D>::FileName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileSavePickerUI)->get_FileName(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Pickers::Provider::SetFileNameResult impl_IFileSavePickerUI<D>::TrySetFileName(hstring_view value) const
{
    Windows::Storage::Pickers::Provider::SetFileNameResult result {};
    check_hresult(WINRT_SHIM(IFileSavePickerUI)->abi_TrySetFileName(get_abi(value), &result));
    return result;
}

template <typename D> event_token impl_IFileSavePickerUI<D>::FileNameChanged(const Windows::Foundation::TypedEventHandler<Windows::Storage::Pickers::Provider::FileSavePickerUI, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IFileSavePickerUI)->add_FileNameChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IFileSavePickerUI> impl_IFileSavePickerUI<D>::FileNameChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Storage::Pickers::Provider::FileSavePickerUI, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IFileSavePickerUI>(this, &ABI::Windows::Storage::Pickers::Provider::IFileSavePickerUI::remove_FileNameChanged, FileNameChanged(handler));
}

template <typename D> void impl_IFileSavePickerUI<D>::FileNameChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IFileSavePickerUI)->remove_FileNameChanged(token));
}

template <typename D> event_token impl_IFileSavePickerUI<D>::TargetFileRequested(const Windows::Foundation::TypedEventHandler<Windows::Storage::Pickers::Provider::FileSavePickerUI, Windows::Storage::Pickers::Provider::TargetFileRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IFileSavePickerUI)->add_TargetFileRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IFileSavePickerUI> impl_IFileSavePickerUI<D>::TargetFileRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Storage::Pickers::Provider::FileSavePickerUI, Windows::Storage::Pickers::Provider::TargetFileRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IFileSavePickerUI>(this, &ABI::Windows::Storage::Pickers::Provider::IFileSavePickerUI::remove_TargetFileRequested, TargetFileRequested(handler));
}

template <typename D> void impl_IFileSavePickerUI<D>::TargetFileRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IFileSavePickerUI)->remove_TargetFileRequested(token));
}

template <typename D> Windows::Storage::Pickers::Provider::TargetFileRequest impl_ITargetFileRequestedEventArgs<D>::Request() const
{
    Windows::Storage::Pickers::Provider::TargetFileRequest value { nullptr };
    check_hresult(WINRT_SHIM(ITargetFileRequestedEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::IStorageFile impl_ITargetFileRequest<D>::TargetFile() const
{
    Windows::Storage::IStorageFile value;
    check_hresult(WINRT_SHIM(ITargetFileRequest)->get_TargetFile(put_abi(value)));
    return value;
}

template <typename D> void impl_ITargetFileRequest<D>::TargetFile(const Windows::Storage::IStorageFile & value) const
{
    check_hresult(WINRT_SHIM(ITargetFileRequest)->put_TargetFile(get_abi(value)));
}

template <typename D> Windows::Storage::Pickers::Provider::TargetFileRequestDeferral impl_ITargetFileRequest<D>::GetDeferral() const
{
    Windows::Storage::Pickers::Provider::TargetFileRequestDeferral value { nullptr };
    check_hresult(WINRT_SHIM(ITargetFileRequest)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> void impl_ITargetFileRequestDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(ITargetFileRequestDeferral)->abi_Complete());
}

}

}
#pragma warning(pop)
