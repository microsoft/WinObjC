// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.ApplicationModel.DataTransfer.3.h"
#include "internal/Windows.ApplicationModel.DataTransfer.ShareTarget.3.h"
#include "Windows.ApplicationModel.DataTransfer.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink> : produce_base<D, Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink>
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

    HRESULT __stdcall get_Thumbnail(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Thumbnail());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Thumbnail(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Thumbnail(*reinterpret_cast<const Windows::Storage::Streams::RandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall put_Id(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Id(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedDataFormats(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedDataFormats());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedFileTypes(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedFileTypes());
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
struct produce<D, Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation> : produce_base<D, Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation>
{
    HRESULT __stdcall get_Data(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::IDataPackageView> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Data());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_QuickLinkId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QuickLinkId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveThisQuickLink() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveThisQuickLink();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportStarted() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportStarted();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportDataRetrieved() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportDataRetrieved();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportSubmittedBackgroundTask() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportSubmittedBackgroundTask();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompletedWithQuickLink(impl::abi_arg_in<Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink> quicklink) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted(*reinterpret_cast<const Windows::ApplicationModel::DataTransfer::ShareTarget::QuickLink *>(&quicklink));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompleted() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportError(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportError(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation2> : produce_base<D, Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation2>
{
    HRESULT __stdcall abi_DismissUI() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DismissUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::DataTransfer::ShareTarget {

template <typename D> hstring impl_IQuickLink<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IQuickLink)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_IQuickLink<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IQuickLink)->put_Title(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::RandomAccessStreamReference impl_IQuickLink<D>::Thumbnail() const
{
    Windows::Storage::Streams::RandomAccessStreamReference value { nullptr };
    check_hresult(WINRT_SHIM(IQuickLink)->get_Thumbnail(put_abi(value)));
    return value;
}

template <typename D> void impl_IQuickLink<D>::Thumbnail(const Windows::Storage::Streams::RandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IQuickLink)->put_Thumbnail(get_abi(value)));
}

template <typename D> hstring impl_IQuickLink<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IQuickLink)->get_Id(put_abi(value)));
    return value;
}

template <typename D> void impl_IQuickLink<D>::Id(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IQuickLink)->put_Id(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IQuickLink<D>::SupportedDataFormats() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IQuickLink)->get_SupportedDataFormats(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IQuickLink<D>::SupportedFileTypes() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IQuickLink)->get_SupportedFileTypes(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackageView impl_IShareOperation<D>::Data() const
{
    Windows::ApplicationModel::DataTransfer::DataPackageView value { nullptr };
    check_hresult(WINRT_SHIM(IShareOperation)->get_Data(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IShareOperation<D>::QuickLinkId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IShareOperation)->get_QuickLinkId(put_abi(value)));
    return value;
}

template <typename D> void impl_IShareOperation<D>::RemoveThisQuickLink() const
{
    check_hresult(WINRT_SHIM(IShareOperation)->abi_RemoveThisQuickLink());
}

template <typename D> void impl_IShareOperation<D>::ReportStarted() const
{
    check_hresult(WINRT_SHIM(IShareOperation)->abi_ReportStarted());
}

template <typename D> void impl_IShareOperation<D>::ReportDataRetrieved() const
{
    check_hresult(WINRT_SHIM(IShareOperation)->abi_ReportDataRetrieved());
}

template <typename D> void impl_IShareOperation<D>::ReportSubmittedBackgroundTask() const
{
    check_hresult(WINRT_SHIM(IShareOperation)->abi_ReportSubmittedBackgroundTask());
}

template <typename D> void impl_IShareOperation<D>::ReportCompleted(const Windows::ApplicationModel::DataTransfer::ShareTarget::QuickLink & quicklink) const
{
    check_hresult(WINRT_SHIM(IShareOperation)->abi_ReportCompletedWithQuickLink(get_abi(quicklink)));
}

template <typename D> void impl_IShareOperation<D>::ReportCompleted() const
{
    check_hresult(WINRT_SHIM(IShareOperation)->abi_ReportCompleted());
}

template <typename D> void impl_IShareOperation<D>::ReportError(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IShareOperation)->abi_ReportError(get_abi(value)));
}

template <typename D> void impl_IShareOperation2<D>::DismissUI() const
{
    check_hresult(WINRT_SHIM(IShareOperation2)->abi_DismissUI());
}

inline QuickLink::QuickLink() :
    QuickLink(activate_instance<QuickLink>())
{}

}

}
#pragma warning(pop)
