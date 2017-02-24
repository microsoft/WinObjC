// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Storage.Provider.3.h"
#include "Windows.Storage.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Storage::Provider::ICachedFileUpdaterStatics> : produce_base<D, Windows::Storage::Provider::ICachedFileUpdaterStatics>
{
    HRESULT __stdcall abi_SetUpdateInformation(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<hstring> contentId, Windows::Storage::Provider::ReadActivationMode readMode, Windows::Storage::Provider::WriteActivationMode writeMode, Windows::Storage::Provider::CachedFileOptions options) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetUpdateInformation(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const hstring *>(&contentId), readMode, writeMode, options);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Provider::ICachedFileUpdaterUI> : produce_base<D, Windows::Storage::Provider::ICachedFileUpdaterUI>
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

    HRESULT __stdcall get_UpdateTarget(Windows::Storage::Provider::CachedFileTarget * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UpdateTarget());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_FileUpdateRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Storage::Provider::FileUpdateRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().FileUpdateRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Storage::Provider::FileUpdateRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_FileUpdateRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FileUpdateRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_UIRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().UIRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_UIRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UIRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UIStatus(Windows::Storage::Provider::UIStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UIStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Provider::ICachedFileUpdaterUI2> : produce_base<D, Windows::Storage::Provider::ICachedFileUpdaterUI2>
{
    HRESULT __stdcall get_UpdateRequest(impl::abi_arg_out<Windows::Storage::Provider::IFileUpdateRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UpdateRequest());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Storage::Provider::IFileUpdateRequestDeferral> value) noexcept override
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
struct produce<D, Windows::Storage::Provider::IFileUpdateRequest> : produce_base<D, Windows::Storage::Provider::IFileUpdateRequest>
{
    HRESULT __stdcall get_ContentId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_File(impl::abi_arg_out<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().File());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Storage::Provider::FileUpdateStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Status(Windows::Storage::Provider::FileUpdateStatus value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Status(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Storage::Provider::IFileUpdateRequestDeferral> value) noexcept override
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

    HRESULT __stdcall abi_UpdateLocalFile(impl::abi_arg_in<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateLocalFile(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Provider::IFileUpdateRequest2> : produce_base<D, Windows::Storage::Provider::IFileUpdateRequest2>
{
    HRESULT __stdcall get_UserInputNeededMessage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserInputNeededMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UserInputNeededMessage(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UserInputNeededMessage(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Provider::IFileUpdateRequestDeferral> : produce_base<D, Windows::Storage::Provider::IFileUpdateRequestDeferral>
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
struct produce<D, Windows::Storage::Provider::IFileUpdateRequestedEventArgs> : produce_base<D, Windows::Storage::Provider::IFileUpdateRequestedEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::Storage::Provider::IFileUpdateRequest> value) noexcept override
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

namespace Windows::Storage::Provider {

template <typename D> hstring impl_ICachedFileUpdaterUI<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICachedFileUpdaterUI)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_ICachedFileUpdaterUI<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICachedFileUpdaterUI)->put_Title(get_abi(value)));
}

template <typename D> Windows::Storage::Provider::CachedFileTarget impl_ICachedFileUpdaterUI<D>::UpdateTarget() const
{
    Windows::Storage::Provider::CachedFileTarget value {};
    check_hresult(WINRT_SHIM(ICachedFileUpdaterUI)->get_UpdateTarget(&value));
    return value;
}

template <typename D> event_token impl_ICachedFileUpdaterUI<D>::FileUpdateRequested(const Windows::Foundation::TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Storage::Provider::FileUpdateRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICachedFileUpdaterUI)->add_FileUpdateRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICachedFileUpdaterUI> impl_ICachedFileUpdaterUI<D>::FileUpdateRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Storage::Provider::FileUpdateRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICachedFileUpdaterUI>(this, &ABI::Windows::Storage::Provider::ICachedFileUpdaterUI::remove_FileUpdateRequested, FileUpdateRequested(handler));
}

template <typename D> void impl_ICachedFileUpdaterUI<D>::FileUpdateRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(ICachedFileUpdaterUI)->remove_FileUpdateRequested(token));
}

template <typename D> event_token impl_ICachedFileUpdaterUI<D>::UIRequested(const Windows::Foundation::TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICachedFileUpdaterUI)->add_UIRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICachedFileUpdaterUI> impl_ICachedFileUpdaterUI<D>::UIRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, ICachedFileUpdaterUI>(this, &ABI::Windows::Storage::Provider::ICachedFileUpdaterUI::remove_UIRequested, UIRequested(handler));
}

template <typename D> void impl_ICachedFileUpdaterUI<D>::UIRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(ICachedFileUpdaterUI)->remove_UIRequested(token));
}

template <typename D> Windows::Storage::Provider::UIStatus impl_ICachedFileUpdaterUI<D>::UIStatus() const
{
    Windows::Storage::Provider::UIStatus value {};
    check_hresult(WINRT_SHIM(ICachedFileUpdaterUI)->get_UIStatus(&value));
    return value;
}

template <typename D> Windows::Storage::Provider::FileUpdateRequest impl_IFileUpdateRequestedEventArgs<D>::Request() const
{
    Windows::Storage::Provider::FileUpdateRequest value { nullptr };
    check_hresult(WINRT_SHIM(IFileUpdateRequestedEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IFileUpdateRequest<D>::ContentId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileUpdateRequest)->get_ContentId(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFile impl_IFileUpdateRequest<D>::File() const
{
    Windows::Storage::StorageFile value { nullptr };
    check_hresult(WINRT_SHIM(IFileUpdateRequest)->get_File(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Provider::FileUpdateStatus impl_IFileUpdateRequest<D>::Status() const
{
    Windows::Storage::Provider::FileUpdateStatus value {};
    check_hresult(WINRT_SHIM(IFileUpdateRequest)->get_Status(&value));
    return value;
}

template <typename D> void impl_IFileUpdateRequest<D>::Status(Windows::Storage::Provider::FileUpdateStatus value) const
{
    check_hresult(WINRT_SHIM(IFileUpdateRequest)->put_Status(value));
}

template <typename D> Windows::Storage::Provider::FileUpdateRequestDeferral impl_IFileUpdateRequest<D>::GetDeferral() const
{
    Windows::Storage::Provider::FileUpdateRequestDeferral value { nullptr };
    check_hresult(WINRT_SHIM(IFileUpdateRequest)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> void impl_IFileUpdateRequest<D>::UpdateLocalFile(const Windows::Storage::IStorageFile & value) const
{
    check_hresult(WINRT_SHIM(IFileUpdateRequest)->abi_UpdateLocalFile(get_abi(value)));
}

template <typename D> void impl_IFileUpdateRequestDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IFileUpdateRequestDeferral)->abi_Complete());
}

template <typename D> Windows::Storage::Provider::FileUpdateRequest impl_ICachedFileUpdaterUI2<D>::UpdateRequest() const
{
    Windows::Storage::Provider::FileUpdateRequest value { nullptr };
    check_hresult(WINRT_SHIM(ICachedFileUpdaterUI2)->get_UpdateRequest(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Provider::FileUpdateRequestDeferral impl_ICachedFileUpdaterUI2<D>::GetDeferral() const
{
    Windows::Storage::Provider::FileUpdateRequestDeferral value { nullptr };
    check_hresult(WINRT_SHIM(ICachedFileUpdaterUI2)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IFileUpdateRequest2<D>::UserInputNeededMessage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileUpdateRequest2)->get_UserInputNeededMessage(put_abi(value)));
    return value;
}

template <typename D> void impl_IFileUpdateRequest2<D>::UserInputNeededMessage(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IFileUpdateRequest2)->put_UserInputNeededMessage(get_abi(value)));
}

template <typename D> void impl_ICachedFileUpdaterStatics<D>::SetUpdateInformation(const Windows::Storage::IStorageFile & file, hstring_view contentId, Windows::Storage::Provider::ReadActivationMode readMode, Windows::Storage::Provider::WriteActivationMode writeMode, Windows::Storage::Provider::CachedFileOptions options) const
{
    check_hresult(WINRT_SHIM(ICachedFileUpdaterStatics)->abi_SetUpdateInformation(get_abi(file), get_abi(contentId), readMode, writeMode, options));
}

inline void CachedFileUpdater::SetUpdateInformation(const Windows::Storage::IStorageFile & file, hstring_view contentId, Windows::Storage::Provider::ReadActivationMode readMode, Windows::Storage::Provider::WriteActivationMode writeMode, Windows::Storage::Provider::CachedFileOptions options)
{
    get_activation_factory<CachedFileUpdater, ICachedFileUpdaterStatics>().SetUpdateInformation(file, contentId, readMode, writeMode, options);
}

}

}
#pragma warning(pop)
