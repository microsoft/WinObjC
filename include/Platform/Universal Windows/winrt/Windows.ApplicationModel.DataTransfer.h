// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.Security.EnterpriseData.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.ApplicationModel.DataTransfer.3.h"
#include "Windows.ApplicationModel.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::DataTransfer {

template <typename L> DataProviderHandler::DataProviderHandler(L lambda) :
    DataProviderHandler(impl::make_delegate<impl_DataProviderHandler<L>, DataProviderHandler>(std::forward<L>(lambda)))
{}

template <typename F> DataProviderHandler::DataProviderHandler(F * function) :
    DataProviderHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> DataProviderHandler::DataProviderHandler(O * object, M method) :
    DataProviderHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void DataProviderHandler::operator()(const Windows::ApplicationModel::DataTransfer::DataProviderRequest & request) const
{
    check_hresult((*(abi<DataProviderHandler> **)this)->abi_Invoke(get_abi(request)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IClipboardStatics> : produce_base<D, Windows::ApplicationModel::DataTransfer::IClipboardStatics>
{
    HRESULT __stdcall abi_GetContent(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::IDataPackageView> content) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *content = detach_abi(this->shim().GetContent());
            return S_OK;
        }
        catch (...)
        {
            *content = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetContent(impl::abi_arg_in<Windows::ApplicationModel::DataTransfer::IDataPackage> content) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetContent(*reinterpret_cast<const Windows::ApplicationModel::DataTransfer::DataPackage *>(&content));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Flush() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Flush();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clear() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ContentChanged(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> changeHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ContentChanged(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&changeHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ContentChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataPackage> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataPackage>
{
    HRESULT __stdcall abi_GetView(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::IDataPackageView> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetView());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequestedOperation(Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestedOperation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RequestedOperation(Windows::ApplicationModel::DataTransfer::DataPackageOperation value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestedOperation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_OperationCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataPackage, Windows::ApplicationModel::DataTransfer::OperationCompletedEventArgs>> handler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().OperationCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataPackage, Windows::ApplicationModel::DataTransfer::OperationCompletedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_OperationCompleted(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OperationCompleted(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Destroyed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataPackage, Windows::Foundation::IInspectable>> handler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().Destroyed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataPackage, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Destroyed(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Destroyed(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetData(impl::abi_arg_in<hstring> formatId, impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetData(*reinterpret_cast<const hstring *>(&formatId), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDataProvider(impl::abi_arg_in<hstring> formatId, impl::abi_arg_in<Windows::ApplicationModel::DataTransfer::DataProviderHandler> delayRenderer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDataProvider(*reinterpret_cast<const hstring *>(&formatId), *reinterpret_cast<const Windows::ApplicationModel::DataTransfer::DataProviderHandler *>(&delayRenderer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetText(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetHtmlFormat(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetHtmlFormat(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResourceMap(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, Windows::Storage::Streams::RandomAccessStreamReference>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResourceMap());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetRtf(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetRtf(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetBitmap(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBitmap(*reinterpret_cast<const Windows::Storage::Streams::RandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStorageItemsReadOnly(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Storage::IStorageItem>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStorageItems(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Storage::IStorageItem> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStorageItems(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Storage::IStorageItem>> value, bool readOnly) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStorageItems(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Storage::IStorageItem> *>(&value), readOnly);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataPackage2> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataPackage2>
{
    HRESULT __stdcall abi_SetApplicationLink(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetApplicationLink(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetWebLink(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetWebLink(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet>
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

    HRESULT __stdcall get_Description(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Description());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Description(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<const hstring *>(&value));
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
            this->shim().Thumbnail(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FileTypes(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FileTypes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ApplicationName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ApplicationName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ApplicationName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ApplicationName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ApplicationListingUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ApplicationListingUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ApplicationListingUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ApplicationListingUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet2> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet2>
{
    HRESULT __stdcall get_ContentSourceWebLink(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentSourceWebLink());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentSourceWebLink(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentSourceWebLink(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentSourceApplicationLink(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentSourceApplicationLink());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentSourceApplicationLink(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentSourceApplicationLink(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PackageFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PackageFamilyName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PackageFamilyName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Square30x30Logo(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Square30x30Logo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Square30x30Logo(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Square30x30Logo(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LogoBackgroundColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LogoBackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LogoBackgroundColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogoBackgroundColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet3> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet3>
{
    HRESULT __stdcall get_EnterpriseId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnterpriseId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EnterpriseId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnterpriseId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView>
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

    HRESULT __stdcall get_Description(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Description());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
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

    HRESULT __stdcall get_FileTypes(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FileTypes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ApplicationName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ApplicationName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ApplicationListingUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ApplicationListingUri());
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
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView2> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView2>
{
    HRESULT __stdcall get_PackageFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentSourceWebLink(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentSourceWebLink());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentSourceApplicationLink(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentSourceApplicationLink());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Square30x30Logo(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Square30x30Logo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LogoBackgroundColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LogoBackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView3> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView3>
{
    HRESULT __stdcall get_EnterpriseId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnterpriseId());
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
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataPackageView> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataPackageView>
{
    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequestedOperation(Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestedOperation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportOperationCompleted(Windows::ApplicationModel::DataTransfer::DataPackageOperation value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportOperationCompleted(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AvailableFormats(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> formatIds) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *formatIds = detach_abi(this->shim().AvailableFormats());
            return S_OK;
        }
        catch (...)
        {
            *formatIds = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Contains(impl::abi_arg_in<hstring> formatId, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Contains(*reinterpret_cast<const hstring *>(&formatId)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDataAsync(impl::abi_arg_in<hstring> formatId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::IInspectable>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetDataAsync(*reinterpret_cast<const hstring *>(&formatId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTextAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetTextAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCustomTextAsync(impl::abi_arg_in<hstring> formatId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetTextAsync(*reinterpret_cast<const hstring *>(&formatId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetUriAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Uri>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetUriAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetHtmlFormatAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetHtmlFormatAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetResourceMapAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Storage::Streams::RandomAccessStreamReference>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetResourceMapAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRtfAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetRtfAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetBitmapAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetBitmapAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStorageItemsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetStorageItemsAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataPackageView2> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataPackageView2>
{
    HRESULT __stdcall abi_GetApplicationLinkAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Uri>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetApplicationLinkAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetWebLinkAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Uri>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetWebLinkAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataPackageView3> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataPackageView3>
{
    HRESULT __stdcall abi_RequestAccessAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestAccessAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAccessWithEnterpriseIdAsync(impl::abi_arg_in<hstring> enterpriseId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestAccessAsync(*reinterpret_cast<const hstring *>(&enterpriseId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnlockAndAssumeEnterpriseIdentity(Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UnlockAndAssumeEnterpriseIdentity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataPackageView4> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataPackageView4>
{
    HRESULT __stdcall abi_SetAcceptedFormatId(impl::abi_arg_in<hstring> formatId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetAcceptedFormatId(*reinterpret_cast<const hstring *>(&formatId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataProviderDeferral> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataProviderDeferral>
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
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataProviderRequest> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataProviderRequest>
{
    HRESULT __stdcall get_FormatId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FormatId());
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::IDataProviderDeferral> value) noexcept override
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

    HRESULT __stdcall abi_SetData(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetData(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataRequest> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataRequest>
{
    HRESULT __stdcall get_Data(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::IDataPackage> value) noexcept override
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

    HRESULT __stdcall put_Data(impl::abi_arg_in<Windows::ApplicationModel::DataTransfer::IDataPackage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Data(*reinterpret_cast<const Windows::ApplicationModel::DataTransfer::DataPackage *>(&value));
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall abi_FailWithDisplayText(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FailWithDisplayText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::IDataRequestDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataRequestDeferral> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataRequestDeferral>
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
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataRequestedEventArgs> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataRequestedEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::IDataRequest> value) noexcept override
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

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataTransferManager> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataTransferManager>
{
    HRESULT __stdcall add_DataRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataTransferManager, Windows::ApplicationModel::DataTransfer::DataRequestedEventArgs>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().DataRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataTransferManager, Windows::ApplicationModel::DataTransfer::DataRequestedEventArgs> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DataRequested(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataRequested(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TargetApplicationChosen(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataTransferManager, Windows::ApplicationModel::DataTransfer::TargetApplicationChosenEventArgs>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().TargetApplicationChosen(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataTransferManager, Windows::ApplicationModel::DataTransfer::TargetApplicationChosenEventArgs> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TargetApplicationChosen(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetApplicationChosen(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataTransferManagerStatics> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataTransferManagerStatics>
{
    HRESULT __stdcall abi_ShowShareUI() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowShareUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::IDataTransferManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetForCurrentView());
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
struct produce<D, Windows::ApplicationModel::DataTransfer::IDataTransferManagerStatics2> : produce_base<D, Windows::ApplicationModel::DataTransfer::IDataTransferManagerStatics2>
{
    HRESULT __stdcall abi_IsSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IHtmlFormatHelperStatics> : produce_base<D, Windows::ApplicationModel::DataTransfer::IHtmlFormatHelperStatics>
{
    HRESULT __stdcall abi_GetStaticFragment(impl::abi_arg_in<hstring> htmlFormat, impl::abi_arg_out<hstring> htmlFragment) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *htmlFragment = detach_abi(this->shim().GetStaticFragment(*reinterpret_cast<const hstring *>(&htmlFormat)));
            return S_OK;
        }
        catch (...)
        {
            *htmlFragment = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateHtmlFormat(impl::abi_arg_in<hstring> htmlFragment, impl::abi_arg_out<hstring> htmlFormat) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *htmlFormat = detach_abi(this->shim().CreateHtmlFormat(*reinterpret_cast<const hstring *>(&htmlFragment)));
            return S_OK;
        }
        catch (...)
        {
            *htmlFormat = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IOperationCompletedEventArgs> : produce_base<D, Windows::ApplicationModel::DataTransfer::IOperationCompletedEventArgs>
{
    HRESULT __stdcall get_Operation(Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Operation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IOperationCompletedEventArgs2> : produce_base<D, Windows::ApplicationModel::DataTransfer::IOperationCompletedEventArgs2>
{
    HRESULT __stdcall get_AcceptedFormatId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AcceptedFormatId());
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
struct produce<D, Windows::ApplicationModel::DataTransfer::ISharedStorageAccessManagerStatics> : produce_base<D, Windows::ApplicationModel::DataTransfer::ISharedStorageAccessManagerStatics>
{
    HRESULT __stdcall abi_AddFile(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<hstring> outToken) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *outToken = detach_abi(this->shim().AddFile(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *outToken = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RedeemTokenForFileAsync(impl::abi_arg_in<hstring> token, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RedeemTokenForFileAsync(*reinterpret_cast<const hstring *>(&token)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveFile(impl::abi_arg_in<hstring> token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveFile(*reinterpret_cast<const hstring *>(&token));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::IStandardDataFormatsStatics> : produce_base<D, Windows::ApplicationModel::DataTransfer::IStandardDataFormatsStatics>
{
    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Uri(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Html(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Html());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Rtf(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Rtf());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Bitmap(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bitmap());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StorageItems(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StorageItems());
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
struct produce<D, Windows::ApplicationModel::DataTransfer::IStandardDataFormatsStatics2> : produce_base<D, Windows::ApplicationModel::DataTransfer::IStandardDataFormatsStatics2>
{
    HRESULT __stdcall get_WebLink(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WebLink());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ApplicationLink(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ApplicationLink());
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
struct produce<D, Windows::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs> : produce_base<D, Windows::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs>
{
    HRESULT __stdcall get_ApplicationName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ApplicationName());
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

namespace Windows::ApplicationModel::DataTransfer {

template <typename D> hstring impl_IStandardDataFormatsStatics<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStandardDataFormatsStatics)->get_Text(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStandardDataFormatsStatics<D>::Uri() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStandardDataFormatsStatics)->get_Uri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStandardDataFormatsStatics<D>::Html() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStandardDataFormatsStatics)->get_Html(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStandardDataFormatsStatics<D>::Rtf() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStandardDataFormatsStatics)->get_Rtf(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStandardDataFormatsStatics<D>::Bitmap() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStandardDataFormatsStatics)->get_Bitmap(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStandardDataFormatsStatics<D>::StorageItems() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStandardDataFormatsStatics)->get_StorageItems(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStandardDataFormatsStatics2<D>::WebLink() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStandardDataFormatsStatics2)->get_WebLink(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStandardDataFormatsStatics2<D>::ApplicationLink() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStandardDataFormatsStatics2)->get_ApplicationLink(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDataPackagePropertySetView<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDataPackagePropertySetView)->get_Title(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDataPackagePropertySetView<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDataPackagePropertySetView)->get_Description(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::RandomAccessStreamReference impl_IDataPackagePropertySetView<D>::Thumbnail() const
{
    Windows::Storage::Streams::RandomAccessStreamReference value { nullptr };
    check_hresult(WINRT_SHIM(IDataPackagePropertySetView)->get_Thumbnail(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IDataPackagePropertySetView<D>::FileTypes() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IDataPackagePropertySetView)->get_FileTypes(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDataPackagePropertySetView<D>::ApplicationName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDataPackagePropertySetView)->get_ApplicationName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IDataPackagePropertySetView<D>::ApplicationListingUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IDataPackagePropertySetView)->get_ApplicationListingUri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDataPackagePropertySetView2<D>::PackageFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDataPackagePropertySetView2)->get_PackageFamilyName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IDataPackagePropertySetView2<D>::ContentSourceWebLink() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IDataPackagePropertySetView2)->get_ContentSourceWebLink(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IDataPackagePropertySetView2<D>::ContentSourceApplicationLink() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IDataPackagePropertySetView2)->get_ContentSourceApplicationLink(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IDataPackagePropertySetView2<D>::Square30x30Logo() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IDataPackagePropertySetView2)->get_Square30x30Logo(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Color impl_IDataPackagePropertySetView2<D>::LogoBackgroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IDataPackagePropertySetView2)->get_LogoBackgroundColor(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDataPackagePropertySetView3<D>::EnterpriseId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDataPackagePropertySetView3)->get_EnterpriseId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDataPackagePropertySet<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDataPackagePropertySet)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataPackagePropertySet<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDataPackagePropertySet)->put_Title(get_abi(value)));
}

template <typename D> hstring impl_IDataPackagePropertySet<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDataPackagePropertySet)->get_Description(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataPackagePropertySet<D>::Description(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDataPackagePropertySet)->put_Description(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IDataPackagePropertySet<D>::Thumbnail() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IDataPackagePropertySet)->get_Thumbnail(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataPackagePropertySet<D>::Thumbnail(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IDataPackagePropertySet)->put_Thumbnail(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IDataPackagePropertySet<D>::FileTypes() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IDataPackagePropertySet)->get_FileTypes(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDataPackagePropertySet<D>::ApplicationName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDataPackagePropertySet)->get_ApplicationName(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataPackagePropertySet<D>::ApplicationName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDataPackagePropertySet)->put_ApplicationName(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_IDataPackagePropertySet<D>::ApplicationListingUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IDataPackagePropertySet)->get_ApplicationListingUri(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataPackagePropertySet<D>::ApplicationListingUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IDataPackagePropertySet)->put_ApplicationListingUri(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_IDataPackagePropertySet2<D>::ContentSourceWebLink() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IDataPackagePropertySet2)->get_ContentSourceWebLink(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataPackagePropertySet2<D>::ContentSourceWebLink(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IDataPackagePropertySet2)->put_ContentSourceWebLink(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_IDataPackagePropertySet2<D>::ContentSourceApplicationLink() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IDataPackagePropertySet2)->get_ContentSourceApplicationLink(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataPackagePropertySet2<D>::ContentSourceApplicationLink(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IDataPackagePropertySet2)->put_ContentSourceApplicationLink(get_abi(value)));
}

template <typename D> hstring impl_IDataPackagePropertySet2<D>::PackageFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDataPackagePropertySet2)->get_PackageFamilyName(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataPackagePropertySet2<D>::PackageFamilyName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDataPackagePropertySet2)->put_PackageFamilyName(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IDataPackagePropertySet2<D>::Square30x30Logo() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IDataPackagePropertySet2)->get_Square30x30Logo(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataPackagePropertySet2<D>::Square30x30Logo(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IDataPackagePropertySet2)->put_Square30x30Logo(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IDataPackagePropertySet2<D>::LogoBackgroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IDataPackagePropertySet2)->get_LogoBackgroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataPackagePropertySet2<D>::LogoBackgroundColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IDataPackagePropertySet2)->put_LogoBackgroundColor(get_abi(value)));
}

template <typename D> hstring impl_IDataPackagePropertySet3<D>::EnterpriseId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDataPackagePropertySet3)->get_EnterpriseId(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataPackagePropertySet3<D>::EnterpriseId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDataPackagePropertySet3)->put_EnterpriseId(get_abi(value)));
}

template <typename D> void impl_IDataProviderDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IDataProviderDeferral)->abi_Complete());
}

template <typename D> hstring impl_IDataProviderRequest<D>::FormatId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDataProviderRequest)->get_FormatId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IDataProviderRequest<D>::Deadline() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IDataProviderRequest)->get_Deadline(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataProviderDeferral impl_IDataProviderRequest<D>::GetDeferral() const
{
    Windows::ApplicationModel::DataTransfer::DataProviderDeferral value { nullptr };
    check_hresult(WINRT_SHIM(IDataProviderRequest)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataProviderRequest<D>::SetData(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IDataProviderRequest)->abi_SetData(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackageOperation impl_IOperationCompletedEventArgs<D>::Operation() const
{
    Windows::ApplicationModel::DataTransfer::DataPackageOperation value {};
    check_hresult(WINRT_SHIM(IOperationCompletedEventArgs)->get_Operation(&value));
    return value;
}

template <typename D> hstring impl_IOperationCompletedEventArgs2<D>::AcceptedFormatId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IOperationCompletedEventArgs2)->get_AcceptedFormatId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackagePropertySetView impl_IDataPackageView<D>::Properties() const
{
    Windows::ApplicationModel::DataTransfer::DataPackagePropertySetView value { nullptr };
    check_hresult(WINRT_SHIM(IDataPackageView)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackageOperation impl_IDataPackageView<D>::RequestedOperation() const
{
    Windows::ApplicationModel::DataTransfer::DataPackageOperation value {};
    check_hresult(WINRT_SHIM(IDataPackageView)->get_RequestedOperation(&value));
    return value;
}

template <typename D> void impl_IDataPackageView<D>::ReportOperationCompleted(Windows::ApplicationModel::DataTransfer::DataPackageOperation value) const
{
    check_hresult(WINRT_SHIM(IDataPackageView)->abi_ReportOperationCompleted(value));
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IDataPackageView<D>::AvailableFormats() const
{
    Windows::Foundation::Collections::IVectorView<hstring> formatIds;
    check_hresult(WINRT_SHIM(IDataPackageView)->get_AvailableFormats(put_abi(formatIds)));
    return formatIds;
}

template <typename D> bool impl_IDataPackageView<D>::Contains(hstring_view formatId) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDataPackageView)->abi_Contains(get_abi(formatId), &value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::IInspectable> impl_IDataPackageView<D>::GetDataAsync(hstring_view formatId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::IInspectable> operation;
    check_hresult(WINRT_SHIM(IDataPackageView)->abi_GetDataAsync(get_abi(formatId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IDataPackageView<D>::GetTextAsync() const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IDataPackageView)->abi_GetTextAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IDataPackageView<D>::GetTextAsync(hstring_view formatId) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IDataPackageView)->abi_GetCustomTextAsync(get_abi(formatId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Uri> impl_IDataPackageView<D>::GetUriAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Uri> operation;
    check_hresult(WINRT_SHIM(IDataPackageView)->abi_GetUriAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IDataPackageView<D>::GetHtmlFormatAsync() const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IDataPackageView)->abi_GetHtmlFormatAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Storage::Streams::RandomAccessStreamReference>> impl_IDataPackageView<D>::GetResourceMapAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Storage::Streams::RandomAccessStreamReference>> operation;
    check_hresult(WINRT_SHIM(IDataPackageView)->abi_GetResourceMapAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IDataPackageView<D>::GetRtfAsync() const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IDataPackageView)->abi_GetRtfAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> impl_IDataPackageView<D>::GetBitmapAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::RandomAccessStreamReference> operation;
    check_hresult(WINRT_SHIM(IDataPackageView)->abi_GetBitmapAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> impl_IDataPackageView<D>::GetStorageItemsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> operation;
    check_hresult(WINRT_SHIM(IDataPackageView)->abi_GetStorageItemsAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Uri> impl_IDataPackageView2<D>::GetApplicationLinkAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Uri> operation;
    check_hresult(WINRT_SHIM(IDataPackageView2)->abi_GetApplicationLinkAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Uri> impl_IDataPackageView2<D>::GetWebLinkAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Uri> operation;
    check_hresult(WINRT_SHIM(IDataPackageView2)->abi_GetWebLinkAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> impl_IDataPackageView3<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> operation;
    check_hresult(WINRT_SHIM(IDataPackageView3)->abi_RequestAccessAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> impl_IDataPackageView3<D>::RequestAccessAsync(hstring_view enterpriseId) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult> operation;
    check_hresult(WINRT_SHIM(IDataPackageView3)->abi_RequestAccessWithEnterpriseIdAsync(get_abi(enterpriseId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult impl_IDataPackageView3<D>::UnlockAndAssumeEnterpriseIdentity() const
{
    Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult result {};
    check_hresult(WINRT_SHIM(IDataPackageView3)->abi_UnlockAndAssumeEnterpriseIdentity(&result));
    return result;
}

template <typename D> void impl_IDataPackageView4<D>::SetAcceptedFormatId(hstring_view formatId) const
{
    check_hresult(WINRT_SHIM(IDataPackageView4)->abi_SetAcceptedFormatId(get_abi(formatId)));
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackageView impl_IDataPackage<D>::GetView() const
{
    Windows::ApplicationModel::DataTransfer::DataPackageView value { nullptr };
    check_hresult(WINRT_SHIM(IDataPackage)->abi_GetView(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackagePropertySet impl_IDataPackage<D>::Properties() const
{
    Windows::ApplicationModel::DataTransfer::DataPackagePropertySet value { nullptr };
    check_hresult(WINRT_SHIM(IDataPackage)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackageOperation impl_IDataPackage<D>::RequestedOperation() const
{
    Windows::ApplicationModel::DataTransfer::DataPackageOperation value {};
    check_hresult(WINRT_SHIM(IDataPackage)->get_RequestedOperation(&value));
    return value;
}

template <typename D> void impl_IDataPackage<D>::RequestedOperation(Windows::ApplicationModel::DataTransfer::DataPackageOperation value) const
{
    check_hresult(WINRT_SHIM(IDataPackage)->put_RequestedOperation(value));
}

template <typename D> event_token impl_IDataPackage<D>::OperationCompleted(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataPackage, Windows::ApplicationModel::DataTransfer::OperationCompletedEventArgs> & handler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IDataPackage)->add_OperationCompleted(get_abi(handler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IDataPackage> impl_IDataPackage<D>::OperationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataPackage, Windows::ApplicationModel::DataTransfer::OperationCompletedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IDataPackage>(this, &ABI::Windows::ApplicationModel::DataTransfer::IDataPackage::remove_OperationCompleted, OperationCompleted(handler));
}

template <typename D> void impl_IDataPackage<D>::OperationCompleted(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IDataPackage)->remove_OperationCompleted(eventCookie));
}

template <typename D> event_token impl_IDataPackage<D>::Destroyed(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataPackage, Windows::Foundation::IInspectable> & handler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IDataPackage)->add_Destroyed(get_abi(handler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IDataPackage> impl_IDataPackage<D>::Destroyed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataPackage, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IDataPackage>(this, &ABI::Windows::ApplicationModel::DataTransfer::IDataPackage::remove_Destroyed, Destroyed(handler));
}

template <typename D> void impl_IDataPackage<D>::Destroyed(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IDataPackage)->remove_Destroyed(eventCookie));
}

template <typename D> void impl_IDataPackage<D>::SetData(hstring_view formatId, const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IDataPackage)->abi_SetData(get_abi(formatId), get_abi(value)));
}

template <typename D> void impl_IDataPackage<D>::SetDataProvider(hstring_view formatId, const Windows::ApplicationModel::DataTransfer::DataProviderHandler & delayRenderer) const
{
    check_hresult(WINRT_SHIM(IDataPackage)->abi_SetDataProvider(get_abi(formatId), get_abi(delayRenderer)));
}

template <typename D> void impl_IDataPackage<D>::SetText(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDataPackage)->abi_SetText(get_abi(value)));
}

template <typename D> void impl_IDataPackage<D>::SetUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IDataPackage)->abi_SetUri(get_abi(value)));
}

template <typename D> void impl_IDataPackage<D>::SetHtmlFormat(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDataPackage)->abi_SetHtmlFormat(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, Windows::Storage::Streams::RandomAccessStreamReference> impl_IDataPackage<D>::ResourceMap() const
{
    Windows::Foundation::Collections::IMap<hstring, Windows::Storage::Streams::RandomAccessStreamReference> value;
    check_hresult(WINRT_SHIM(IDataPackage)->get_ResourceMap(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataPackage<D>::SetRtf(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDataPackage)->abi_SetRtf(get_abi(value)));
}

template <typename D> void impl_IDataPackage<D>::SetBitmap(const Windows::Storage::Streams::RandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IDataPackage)->abi_SetBitmap(get_abi(value)));
}

template <typename D> void impl_IDataPackage<D>::SetStorageItems(iterable<Windows::Storage::IStorageItem> value) const
{
    check_hresult(WINRT_SHIM(IDataPackage)->abi_SetStorageItemsReadOnly(get_abi(value)));
}

template <typename D> void impl_IDataPackage<D>::SetStorageItems(iterable<Windows::Storage::IStorageItem> value, bool readOnly) const
{
    check_hresult(WINRT_SHIM(IDataPackage)->abi_SetStorageItems(get_abi(value), readOnly));
}

template <typename D> void impl_IDataPackage2<D>::SetApplicationLink(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IDataPackage2)->abi_SetApplicationLink(get_abi(value)));
}

template <typename D> void impl_IDataPackage2<D>::SetWebLink(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IDataPackage2)->abi_SetWebLink(get_abi(value)));
}

template <typename D> hstring impl_IHtmlFormatHelperStatics<D>::GetStaticFragment(hstring_view htmlFormat) const
{
    hstring htmlFragment;
    check_hresult(WINRT_SHIM(IHtmlFormatHelperStatics)->abi_GetStaticFragment(get_abi(htmlFormat), put_abi(htmlFragment)));
    return htmlFragment;
}

template <typename D> hstring impl_IHtmlFormatHelperStatics<D>::CreateHtmlFormat(hstring_view htmlFragment) const
{
    hstring htmlFormat;
    check_hresult(WINRT_SHIM(IHtmlFormatHelperStatics)->abi_CreateHtmlFormat(get_abi(htmlFragment), put_abi(htmlFormat)));
    return htmlFormat;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackageView impl_IClipboardStatics<D>::GetContent() const
{
    Windows::ApplicationModel::DataTransfer::DataPackageView content { nullptr };
    check_hresult(WINRT_SHIM(IClipboardStatics)->abi_GetContent(put_abi(content)));
    return content;
}

template <typename D> void impl_IClipboardStatics<D>::SetContent(const Windows::ApplicationModel::DataTransfer::DataPackage & content) const
{
    check_hresult(WINRT_SHIM(IClipboardStatics)->abi_SetContent(get_abi(content)));
}

template <typename D> void impl_IClipboardStatics<D>::Flush() const
{
    check_hresult(WINRT_SHIM(IClipboardStatics)->abi_Flush());
}

template <typename D> void impl_IClipboardStatics<D>::Clear() const
{
    check_hresult(WINRT_SHIM(IClipboardStatics)->abi_Clear());
}

template <typename D> event_token impl_IClipboardStatics<D>::ContentChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & changeHandler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IClipboardStatics)->add_ContentChanged(get_abi(changeHandler), &token));
    return token;
}

template <typename D> event_revoker<IClipboardStatics> impl_IClipboardStatics<D>::ContentChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & changeHandler) const
{
    return impl::make_event_revoker<D, IClipboardStatics>(this, &ABI::Windows::ApplicationModel::DataTransfer::IClipboardStatics::remove_ContentChanged, ContentChanged(changeHandler));
}

template <typename D> void impl_IClipboardStatics<D>::ContentChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IClipboardStatics)->remove_ContentChanged(token));
}

template <typename D> void impl_IDataRequestDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IDataRequestDeferral)->abi_Complete());
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackage impl_IDataRequest<D>::Data() const
{
    Windows::ApplicationModel::DataTransfer::DataPackage value { nullptr };
    check_hresult(WINRT_SHIM(IDataRequest)->get_Data(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataRequest<D>::Data(const Windows::ApplicationModel::DataTransfer::DataPackage & value) const
{
    check_hresult(WINRT_SHIM(IDataRequest)->put_Data(get_abi(value)));
}

template <typename D> Windows::Foundation::DateTime impl_IDataRequest<D>::Deadline() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IDataRequest)->get_Deadline(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataRequest<D>::FailWithDisplayText(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDataRequest)->abi_FailWithDisplayText(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataRequestDeferral impl_IDataRequest<D>::GetDeferral() const
{
    Windows::ApplicationModel::DataTransfer::DataRequestDeferral value { nullptr };
    check_hresult(WINRT_SHIM(IDataRequest)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataRequest impl_IDataRequestedEventArgs<D>::Request() const
{
    Windows::ApplicationModel::DataTransfer::DataRequest value { nullptr };
    check_hresult(WINRT_SHIM(IDataRequestedEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ITargetApplicationChosenEventArgs<D>::ApplicationName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITargetApplicationChosenEventArgs)->get_ApplicationName(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IDataTransferManager<D>::DataRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataTransferManager, Windows::ApplicationModel::DataTransfer::DataRequestedEventArgs> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IDataTransferManager)->add_DataRequested(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IDataTransferManager> impl_IDataTransferManager<D>::DataRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataTransferManager, Windows::ApplicationModel::DataTransfer::DataRequestedEventArgs> & eventHandler) const
{
    return impl::make_event_revoker<D, IDataTransferManager>(this, &ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManager::remove_DataRequested, DataRequested(eventHandler));
}

template <typename D> void impl_IDataTransferManager<D>::DataRequested(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IDataTransferManager)->remove_DataRequested(eventCookie));
}

template <typename D> event_token impl_IDataTransferManager<D>::TargetApplicationChosen(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataTransferManager, Windows::ApplicationModel::DataTransfer::TargetApplicationChosenEventArgs> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IDataTransferManager)->add_TargetApplicationChosen(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IDataTransferManager> impl_IDataTransferManager<D>::TargetApplicationChosen(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DataTransferManager, Windows::ApplicationModel::DataTransfer::TargetApplicationChosenEventArgs> & eventHandler) const
{
    return impl::make_event_revoker<D, IDataTransferManager>(this, &ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManager::remove_TargetApplicationChosen, TargetApplicationChosen(eventHandler));
}

template <typename D> void impl_IDataTransferManager<D>::TargetApplicationChosen(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IDataTransferManager)->remove_TargetApplicationChosen(eventCookie));
}

template <typename D> void impl_IDataTransferManagerStatics<D>::ShowShareUI() const
{
    check_hresult(WINRT_SHIM(IDataTransferManagerStatics)->abi_ShowShareUI());
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataTransferManager impl_IDataTransferManagerStatics<D>::GetForCurrentView() const
{
    Windows::ApplicationModel::DataTransfer::DataTransferManager value { nullptr };
    check_hresult(WINRT_SHIM(IDataTransferManagerStatics)->abi_GetForCurrentView(put_abi(value)));
    return value;
}

template <typename D> bool impl_IDataTransferManagerStatics2<D>::IsSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDataTransferManagerStatics2)->abi_IsSupported(&value));
    return value;
}

template <typename D> hstring impl_ISharedStorageAccessManagerStatics<D>::AddFile(const Windows::Storage::IStorageFile & file) const
{
    hstring outToken;
    check_hresult(WINRT_SHIM(ISharedStorageAccessManagerStatics)->abi_AddFile(get_abi(file), put_abi(outToken)));
    return outToken;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_ISharedStorageAccessManagerStatics<D>::RedeemTokenForFileAsync(hstring_view token) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(ISharedStorageAccessManagerStatics)->abi_RedeemTokenForFileAsync(get_abi(token), put_abi(operation)));
    return operation;
}

template <typename D> void impl_ISharedStorageAccessManagerStatics<D>::RemoveFile(hstring_view token) const
{
    check_hresult(WINRT_SHIM(ISharedStorageAccessManagerStatics)->abi_RemoveFile(get_abi(token)));
}

inline Windows::ApplicationModel::DataTransfer::DataPackageView Clipboard::GetContent()
{
    return get_activation_factory<Clipboard, IClipboardStatics>().GetContent();
}

inline void Clipboard::SetContent(const Windows::ApplicationModel::DataTransfer::DataPackage & content)
{
    get_activation_factory<Clipboard, IClipboardStatics>().SetContent(content);
}

inline void Clipboard::Flush()
{
    get_activation_factory<Clipboard, IClipboardStatics>().Flush();
}

inline void Clipboard::Clear()
{
    get_activation_factory<Clipboard, IClipboardStatics>().Clear();
}

inline event_token Clipboard::ContentChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & changeHandler)
{
    return get_activation_factory<Clipboard, IClipboardStatics>().ContentChanged(changeHandler);
}

inline factory_event_revoker<IClipboardStatics> Clipboard::ContentChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & changeHandler)
{
    auto factory = get_activation_factory<Clipboard, IClipboardStatics>();
    return { factory, &ABI::Windows::ApplicationModel::DataTransfer::IClipboardStatics::remove_ContentChanged, factory.ContentChanged(changeHandler) };
}

inline void Clipboard::ContentChanged(event_token token)
{
    get_activation_factory<Clipboard, IClipboardStatics>().ContentChanged(token);
}

inline DataPackage::DataPackage() :
    DataPackage(activate_instance<DataPackage>())
{}

inline void DataTransferManager::ShowShareUI()
{
    get_activation_factory<DataTransferManager, IDataTransferManagerStatics>().ShowShareUI();
}

inline Windows::ApplicationModel::DataTransfer::DataTransferManager DataTransferManager::GetForCurrentView()
{
    return get_activation_factory<DataTransferManager, IDataTransferManagerStatics>().GetForCurrentView();
}

inline bool DataTransferManager::IsSupported()
{
    return get_activation_factory<DataTransferManager, IDataTransferManagerStatics2>().IsSupported();
}

inline hstring HtmlFormatHelper::GetStaticFragment(hstring_view htmlFormat)
{
    return get_activation_factory<HtmlFormatHelper, IHtmlFormatHelperStatics>().GetStaticFragment(htmlFormat);
}

inline hstring HtmlFormatHelper::CreateHtmlFormat(hstring_view htmlFragment)
{
    return get_activation_factory<HtmlFormatHelper, IHtmlFormatHelperStatics>().CreateHtmlFormat(htmlFragment);
}

inline hstring SharedStorageAccessManager::AddFile(const Windows::Storage::IStorageFile & file)
{
    return get_activation_factory<SharedStorageAccessManager, ISharedStorageAccessManagerStatics>().AddFile(file);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> SharedStorageAccessManager::RedeemTokenForFileAsync(hstring_view token)
{
    return get_activation_factory<SharedStorageAccessManager, ISharedStorageAccessManagerStatics>().RedeemTokenForFileAsync(token);
}

inline void SharedStorageAccessManager::RemoveFile(hstring_view token)
{
    get_activation_factory<SharedStorageAccessManager, ISharedStorageAccessManagerStatics>().RemoveFile(token);
}

inline hstring StandardDataFormats::Text()
{
    return get_activation_factory<StandardDataFormats, IStandardDataFormatsStatics>().Text();
}

inline hstring StandardDataFormats::Uri()
{
    return get_activation_factory<StandardDataFormats, IStandardDataFormatsStatics>().Uri();
}

inline hstring StandardDataFormats::Html()
{
    return get_activation_factory<StandardDataFormats, IStandardDataFormatsStatics>().Html();
}

inline hstring StandardDataFormats::Rtf()
{
    return get_activation_factory<StandardDataFormats, IStandardDataFormatsStatics>().Rtf();
}

inline hstring StandardDataFormats::Bitmap()
{
    return get_activation_factory<StandardDataFormats, IStandardDataFormatsStatics>().Bitmap();
}

inline hstring StandardDataFormats::StorageItems()
{
    return get_activation_factory<StandardDataFormats, IStandardDataFormatsStatics>().StorageItems();
}

inline hstring StandardDataFormats::WebLink()
{
    return get_activation_factory<StandardDataFormats, IStandardDataFormatsStatics2>().WebLink();
}

inline hstring StandardDataFormats::ApplicationLink()
{
    return get_activation_factory<StandardDataFormats, IStandardDataFormatsStatics2>().ApplicationLink();
}

}

}
#pragma warning(pop)
