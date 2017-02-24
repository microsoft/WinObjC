// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Storage.FileProperties.3.h"
#include "internal/Windows.Storage.3.h"
#include "Windows.Foundation.h"
#include "Windows.Foundation.Collections.h"
#include "Windows.Storage.Search.h"
#include "Windows.Storage.Streams.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Storage {

template <typename L> ApplicationDataSetVersionHandler::ApplicationDataSetVersionHandler(L lambda) :
    ApplicationDataSetVersionHandler(impl::make_delegate<impl_ApplicationDataSetVersionHandler<L>, ApplicationDataSetVersionHandler>(std::forward<L>(lambda)))
{}

template <typename F> ApplicationDataSetVersionHandler::ApplicationDataSetVersionHandler(F * function) :
    ApplicationDataSetVersionHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> ApplicationDataSetVersionHandler::ApplicationDataSetVersionHandler(O * object, M method) :
    ApplicationDataSetVersionHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void ApplicationDataSetVersionHandler::operator()(const Windows::Storage::SetVersionRequest & setVersionRequest) const
{
    check_hresult((*(abi<ApplicationDataSetVersionHandler> **)this)->abi_Invoke(get_abi(setVersionRequest)));
}

template <typename L> StreamedFileDataRequestedHandler::StreamedFileDataRequestedHandler(L lambda) :
    StreamedFileDataRequestedHandler(impl::make_delegate<impl_StreamedFileDataRequestedHandler<L>, StreamedFileDataRequestedHandler>(std::forward<L>(lambda)))
{}

template <typename F> StreamedFileDataRequestedHandler::StreamedFileDataRequestedHandler(F * function) :
    StreamedFileDataRequestedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> StreamedFileDataRequestedHandler::StreamedFileDataRequestedHandler(O * object, M method) :
    StreamedFileDataRequestedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void StreamedFileDataRequestedHandler::operator()(const Windows::Storage::StreamedFileDataRequest & stream) const
{
    check_hresult((*(abi<StreamedFileDataRequestedHandler> **)this)->abi_Invoke(get_abi(stream)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::Storage::IApplicationData> : produce_base<D, Windows::Storage::IApplicationData>
{
    HRESULT __stdcall get_Version(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Version());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetVersionAsync(uint32_t desiredVersion, impl::abi_arg_in<Windows::Storage::ApplicationDataSetVersionHandler> handler, impl::abi_arg_out<Windows::Foundation::IAsyncAction> setVersionOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *setVersionOperation = detach_abi(this->shim().SetVersionAsync(desiredVersion, *reinterpret_cast<const Windows::Storage::ApplicationDataSetVersionHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            *setVersionOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearAllAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> clearOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *clearOperation = detach_abi(this->shim().ClearAsync());
            return S_OK;
        }
        catch (...)
        {
            *clearOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearAsync(Windows::Storage::ApplicationDataLocality locality, impl::abi_arg_out<Windows::Foundation::IAsyncAction> clearOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *clearOperation = detach_abi(this->shim().ClearAsync(locality));
            return S_OK;
        }
        catch (...)
        {
            *clearOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocalSettings(impl::abi_arg_out<Windows::Storage::IApplicationDataContainer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalSettings());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RoamingSettings(impl::abi_arg_out<Windows::Storage::IApplicationDataContainer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoamingSettings());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocalFolder(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalFolder());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RoamingFolder(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoamingFolder());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TemporaryFolder(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TemporaryFolder());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DataChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Storage::ApplicationData, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DataChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Storage::ApplicationData, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DataChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SignalDataChanged() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SignalDataChanged();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RoamingStorageQuota(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoamingStorageQuota());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::IApplicationData2> : produce_base<D, Windows::Storage::IApplicationData2>
{
    HRESULT __stdcall get_LocalCacheFolder(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalCacheFolder());
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
struct produce<D, Windows::Storage::IApplicationData3> : produce_base<D, Windows::Storage::IApplicationData3>
{
    HRESULT __stdcall abi_GetPublisherCacheFolder(impl::abi_arg_in<hstring> folderName, impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetPublisherCacheFolder(*reinterpret_cast<const hstring *>(&folderName)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearPublisherCacheFolderAsync(impl::abi_arg_in<hstring> folderName, impl::abi_arg_out<Windows::Foundation::IAsyncAction> clearOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *clearOperation = detach_abi(this->shim().ClearPublisherCacheFolderAsync(*reinterpret_cast<const hstring *>(&folderName)));
            return S_OK;
        }
        catch (...)
        {
            *clearOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SharedLocalFolder(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SharedLocalFolder());
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
struct produce<D, Windows::Storage::IApplicationDataContainer> : produce_base<D, Windows::Storage::IApplicationDataContainer>
{
    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Locality(Windows::Storage::ApplicationDataLocality * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Locality());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Values(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Values());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Containers(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Storage::ApplicationDataContainer>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Containers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateContainer(impl::abi_arg_in<hstring> name, Windows::Storage::ApplicationDataCreateDisposition disposition, impl::abi_arg_out<Windows::Storage::IApplicationDataContainer> container) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *container = detach_abi(this->shim().CreateContainer(*reinterpret_cast<const hstring *>(&name), disposition));
            return S_OK;
        }
        catch (...)
        {
            *container = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteContainer(impl::abi_arg_in<hstring> name) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeleteContainer(*reinterpret_cast<const hstring *>(&name));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::IApplicationDataStatics> : produce_base<D, Windows::Storage::IApplicationDataStatics>
{
    HRESULT __stdcall get_Current(impl::abi_arg_out<Windows::Storage::IApplicationData> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Current());
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
struct produce<D, Windows::Storage::IApplicationDataStatics2> : produce_base<D, Windows::Storage::IApplicationDataStatics2>
{
    HRESULT __stdcall abi_GetForUserAsync(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::ApplicationData>> getForUserOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *getForUserOperation = detach_abi(this->shim().GetForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user)));
            return S_OK;
        }
        catch (...)
        {
            *getForUserOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::ICachedFileManagerStatics> : produce_base<D, Windows::Storage::ICachedFileManagerStatics>
{
    HRESULT __stdcall abi_DeferUpdates(impl::abi_arg_in<Windows::Storage::IStorageFile> file) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeferUpdates(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CompleteUpdatesAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Storage::Provider::FileUpdateStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CompleteUpdatesAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
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
struct produce<D, Windows::Storage::IDownloadsFolderStatics> : produce_base<D, Windows::Storage::IDownloadsFolderStatics>
{
    HRESULT __stdcall abi_CreateFileAsync(impl::abi_arg_in<hstring> desiredName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateFileAsync(*reinterpret_cast<const hstring *>(&desiredName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFolderAsync(impl::abi_arg_in<hstring> desiredName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateFolderAsync(*reinterpret_cast<const hstring *>(&desiredName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFileWithCollisionOptionAsync(impl::abi_arg_in<hstring> desiredName, Windows::Storage::CreationCollisionOption option, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateFileAsync(*reinterpret_cast<const hstring *>(&desiredName), option));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFolderWithCollisionOptionAsync(impl::abi_arg_in<hstring> desiredName, Windows::Storage::CreationCollisionOption option, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateFolderAsync(*reinterpret_cast<const hstring *>(&desiredName), option));
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
struct produce<D, Windows::Storage::IDownloadsFolderStatics2> : produce_base<D, Windows::Storage::IDownloadsFolderStatics2>
{
    HRESULT __stdcall abi_CreateFileForUserAsync(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<hstring> desiredName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateFileForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const hstring *>(&desiredName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFolderForUserAsync(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<hstring> desiredName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateFolderForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const hstring *>(&desiredName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFileForUserWithCollisionOptionAsync(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<hstring> desiredName, Windows::Storage::CreationCollisionOption option, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateFileForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const hstring *>(&desiredName), option));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFolderForUserWithCollisionOptionAsync(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<hstring> desiredName, Windows::Storage::CreationCollisionOption option, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateFolderForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const hstring *>(&desiredName), option));
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
struct produce<D, Windows::Storage::IFileIOStatics> : produce_base<D, Windows::Storage::IFileIOStatics>
{
    HRESULT __stdcall abi_ReadTextAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> textOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *textOperation = detach_abi(this->shim().ReadTextAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *textOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadTextWithEncodingAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, Windows::Storage::Streams::UnicodeEncoding encoding, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> textOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *textOperation = detach_abi(this->shim().ReadTextAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), encoding));
            return S_OK;
        }
        catch (...)
        {
            *textOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteTextAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<hstring> contents, impl::abi_arg_out<Windows::Foundation::IAsyncAction> textOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *textOperation = detach_abi(this->shim().WriteTextAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const hstring *>(&contents)));
            return S_OK;
        }
        catch (...)
        {
            *textOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteTextWithEncodingAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<hstring> contents, Windows::Storage::Streams::UnicodeEncoding encoding, impl::abi_arg_out<Windows::Foundation::IAsyncAction> textOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *textOperation = detach_abi(this->shim().WriteTextAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const hstring *>(&contents), encoding));
            return S_OK;
        }
        catch (...)
        {
            *textOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendTextAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<hstring> contents, impl::abi_arg_out<Windows::Foundation::IAsyncAction> textOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *textOperation = detach_abi(this->shim().AppendTextAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const hstring *>(&contents)));
            return S_OK;
        }
        catch (...)
        {
            *textOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendTextWithEncodingAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<hstring> contents, Windows::Storage::Streams::UnicodeEncoding encoding, impl::abi_arg_out<Windows::Foundation::IAsyncAction> textOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *textOperation = detach_abi(this->shim().AppendTextAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const hstring *>(&contents), encoding));
            return S_OK;
        }
        catch (...)
        {
            *textOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadLinesAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>>> linesOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *linesOperation = detach_abi(this->shim().ReadLinesAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *linesOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadLinesWithEncodingAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, Windows::Storage::Streams::UnicodeEncoding encoding, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>>> linesOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *linesOperation = detach_abi(this->shim().ReadLinesAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), encoding));
            return S_OK;
        }
        catch (...)
        {
            *linesOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteLinesAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> lines, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().WriteLinesAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&lines)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteLinesWithEncodingAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> lines, Windows::Storage::Streams::UnicodeEncoding encoding, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().WriteLinesAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&lines), encoding));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendLinesAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> lines, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().AppendLinesAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&lines)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendLinesWithEncodingAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> lines, Windows::Storage::Streams::UnicodeEncoding encoding, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().AppendLinesAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&lines), encoding));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadBufferAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ReadBufferAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteBufferAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().WriteBufferAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteBytesAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, uint32_t __bufferSize, impl::abi_arg_in<uint8_t> * buffer, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().WriteBytesAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), array_view<const uint8_t>(buffer, buffer + __bufferSize)));
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
struct produce<D, Windows::Storage::IKnownFoldersCameraRollStatics> : produce_base<D, Windows::Storage::IKnownFoldersCameraRollStatics>
{
    HRESULT __stdcall get_CameraRoll(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CameraRoll());
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
struct produce<D, Windows::Storage::IKnownFoldersPlaylistsStatics> : produce_base<D, Windows::Storage::IKnownFoldersPlaylistsStatics>
{
    HRESULT __stdcall get_Playlists(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Playlists());
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
struct produce<D, Windows::Storage::IKnownFoldersSavedPicturesStatics> : produce_base<D, Windows::Storage::IKnownFoldersSavedPicturesStatics>
{
    HRESULT __stdcall get_SavedPictures(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SavedPictures());
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
struct produce<D, Windows::Storage::IKnownFoldersStatics> : produce_base<D, Windows::Storage::IKnownFoldersStatics>
{
    HRESULT __stdcall get_MusicLibrary(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MusicLibrary());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PicturesLibrary(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PicturesLibrary());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideosLibrary(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideosLibrary());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DocumentsLibrary(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DocumentsLibrary());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HomeGroup(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HomeGroup());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemovableDevices(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemovableDevices());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaServerDevices(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaServerDevices());
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
struct produce<D, Windows::Storage::IKnownFoldersStatics2> : produce_base<D, Windows::Storage::IKnownFoldersStatics2>
{
    HRESULT __stdcall get_Objects3D(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Objects3D());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppCaptures(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppCaptures());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RecordedCalls(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RecordedCalls());
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
struct produce<D, Windows::Storage::IKnownFoldersStatics3> : produce_base<D, Windows::Storage::IKnownFoldersStatics3>
{
    HRESULT __stdcall abi_GetFolderForUserAsync(impl::abi_arg_in<Windows::System::IUser> user, Windows::Storage::KnownFolderId folderId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFolderForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), folderId));
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
struct produce<D, Windows::Storage::IPathIOStatics> : produce_base<D, Windows::Storage::IPathIOStatics>
{
    HRESULT __stdcall abi_ReadTextAsync(impl::abi_arg_in<hstring> absolutePath, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> textOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *textOperation = detach_abi(this->shim().ReadTextAsync(*reinterpret_cast<const hstring *>(&absolutePath)));
            return S_OK;
        }
        catch (...)
        {
            *textOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadTextWithEncodingAsync(impl::abi_arg_in<hstring> absolutePath, Windows::Storage::Streams::UnicodeEncoding encoding, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> textOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *textOperation = detach_abi(this->shim().ReadTextAsync(*reinterpret_cast<const hstring *>(&absolutePath), encoding));
            return S_OK;
        }
        catch (...)
        {
            *textOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteTextAsync(impl::abi_arg_in<hstring> absolutePath, impl::abi_arg_in<hstring> contents, impl::abi_arg_out<Windows::Foundation::IAsyncAction> textOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *textOperation = detach_abi(this->shim().WriteTextAsync(*reinterpret_cast<const hstring *>(&absolutePath), *reinterpret_cast<const hstring *>(&contents)));
            return S_OK;
        }
        catch (...)
        {
            *textOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteTextWithEncodingAsync(impl::abi_arg_in<hstring> absolutePath, impl::abi_arg_in<hstring> contents, Windows::Storage::Streams::UnicodeEncoding encoding, impl::abi_arg_out<Windows::Foundation::IAsyncAction> textOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *textOperation = detach_abi(this->shim().WriteTextAsync(*reinterpret_cast<const hstring *>(&absolutePath), *reinterpret_cast<const hstring *>(&contents), encoding));
            return S_OK;
        }
        catch (...)
        {
            *textOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendTextAsync(impl::abi_arg_in<hstring> absolutePath, impl::abi_arg_in<hstring> contents, impl::abi_arg_out<Windows::Foundation::IAsyncAction> textOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *textOperation = detach_abi(this->shim().AppendTextAsync(*reinterpret_cast<const hstring *>(&absolutePath), *reinterpret_cast<const hstring *>(&contents)));
            return S_OK;
        }
        catch (...)
        {
            *textOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendTextWithEncodingAsync(impl::abi_arg_in<hstring> absolutePath, impl::abi_arg_in<hstring> contents, Windows::Storage::Streams::UnicodeEncoding encoding, impl::abi_arg_out<Windows::Foundation::IAsyncAction> textOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *textOperation = detach_abi(this->shim().AppendTextAsync(*reinterpret_cast<const hstring *>(&absolutePath), *reinterpret_cast<const hstring *>(&contents), encoding));
            return S_OK;
        }
        catch (...)
        {
            *textOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadLinesAsync(impl::abi_arg_in<hstring> absolutePath, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>>> linesOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *linesOperation = detach_abi(this->shim().ReadLinesAsync(*reinterpret_cast<const hstring *>(&absolutePath)));
            return S_OK;
        }
        catch (...)
        {
            *linesOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadLinesWithEncodingAsync(impl::abi_arg_in<hstring> absolutePath, Windows::Storage::Streams::UnicodeEncoding encoding, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>>> linesOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *linesOperation = detach_abi(this->shim().ReadLinesAsync(*reinterpret_cast<const hstring *>(&absolutePath), encoding));
            return S_OK;
        }
        catch (...)
        {
            *linesOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteLinesAsync(impl::abi_arg_in<hstring> absolutePath, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> lines, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().WriteLinesAsync(*reinterpret_cast<const hstring *>(&absolutePath), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&lines)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteLinesWithEncodingAsync(impl::abi_arg_in<hstring> absolutePath, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> lines, Windows::Storage::Streams::UnicodeEncoding encoding, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().WriteLinesAsync(*reinterpret_cast<const hstring *>(&absolutePath), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&lines), encoding));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendLinesAsync(impl::abi_arg_in<hstring> absolutePath, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> lines, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().AppendLinesAsync(*reinterpret_cast<const hstring *>(&absolutePath), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&lines)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendLinesWithEncodingAsync(impl::abi_arg_in<hstring> absolutePath, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> lines, Windows::Storage::Streams::UnicodeEncoding encoding, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().AppendLinesAsync(*reinterpret_cast<const hstring *>(&absolutePath), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&lines), encoding));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadBufferAsync(impl::abi_arg_in<hstring> absolutePath, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ReadBufferAsync(*reinterpret_cast<const hstring *>(&absolutePath)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteBufferAsync(impl::abi_arg_in<hstring> absolutePath, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().WriteBufferAsync(*reinterpret_cast<const hstring *>(&absolutePath), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteBytesAsync(impl::abi_arg_in<hstring> absolutePath, uint32_t __bufferSize, impl::abi_arg_in<uint8_t> * buffer, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().WriteBytesAsync(*reinterpret_cast<const hstring *>(&absolutePath), array_view<const uint8_t>(buffer, buffer + __bufferSize)));
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
struct produce<D, Windows::Storage::ISetVersionDeferral> : produce_base<D, Windows::Storage::ISetVersionDeferral>
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
struct produce<D, Windows::Storage::ISetVersionRequest> : produce_base<D, Windows::Storage::ISetVersionRequest>
{
    HRESULT __stdcall get_CurrentVersion(uint32_t * currentVersion) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *currentVersion = detach_abi(this->shim().CurrentVersion());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredVersion(uint32_t * desiredVersion) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *desiredVersion = detach_abi(this->shim().DesiredVersion());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Storage::ISetVersionDeferral> deferral) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deferral = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *deferral = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::IStorageFile> : produce_base<D, Windows::Storage::IStorageFile>
{
    HRESULT __stdcall get_FileType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FileType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenAsync(Windows::Storage::FileAccessMode accessMode, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().OpenAsync(accessMode));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenTransactedWriteAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageStreamTransaction>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().OpenTransactedWriteAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyOverloadDefaultNameAndOptions(impl::abi_arg_in<Windows::Storage::IStorageFolder> destinationFolder, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CopyAsync(*reinterpret_cast<const Windows::Storage::IStorageFolder *>(&destinationFolder)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyOverloadDefaultOptions(impl::abi_arg_in<Windows::Storage::IStorageFolder> destinationFolder, impl::abi_arg_in<hstring> desiredNewName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CopyAsync(*reinterpret_cast<const Windows::Storage::IStorageFolder *>(&destinationFolder), *reinterpret_cast<const hstring *>(&desiredNewName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyOverload(impl::abi_arg_in<Windows::Storage::IStorageFolder> destinationFolder, impl::abi_arg_in<hstring> desiredNewName, Windows::Storage::NameCollisionOption option, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CopyAsync(*reinterpret_cast<const Windows::Storage::IStorageFolder *>(&destinationFolder), *reinterpret_cast<const hstring *>(&desiredNewName), option));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyAndReplaceAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> fileToReplace, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CopyAndReplaceAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&fileToReplace)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveOverloadDefaultNameAndOptions(impl::abi_arg_in<Windows::Storage::IStorageFolder> destinationFolder, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().MoveAsync(*reinterpret_cast<const Windows::Storage::IStorageFolder *>(&destinationFolder)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveOverloadDefaultOptions(impl::abi_arg_in<Windows::Storage::IStorageFolder> destinationFolder, impl::abi_arg_in<hstring> desiredNewName, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().MoveAsync(*reinterpret_cast<const Windows::Storage::IStorageFolder *>(&destinationFolder), *reinterpret_cast<const hstring *>(&desiredNewName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveOverload(impl::abi_arg_in<Windows::Storage::IStorageFolder> destinationFolder, impl::abi_arg_in<hstring> desiredNewName, Windows::Storage::NameCollisionOption option, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().MoveAsync(*reinterpret_cast<const Windows::Storage::IStorageFolder *>(&destinationFolder), *reinterpret_cast<const hstring *>(&desiredNewName), option));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveAndReplaceAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> fileToReplace, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().MoveAndReplaceAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&fileToReplace)));
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
struct produce<D, Windows::Storage::IStorageFile2> : produce_base<D, Windows::Storage::IStorageFile2>
{
    HRESULT __stdcall abi_OpenWithOptionsAsync(Windows::Storage::FileAccessMode accessMode, Windows::Storage::StorageOpenOptions options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().OpenAsync(accessMode, options));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenTransactedWriteWithOptionsAsync(Windows::Storage::StorageOpenOptions options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageStreamTransaction>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().OpenTransactedWriteAsync(options));
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
struct produce<D, Windows::Storage::IStorageFilePropertiesWithAvailability> : produce_base<D, Windows::Storage::IStorageFilePropertiesWithAvailability>
{
    HRESULT __stdcall get_IsAvailable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAvailable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::IStorageFileStatics> : produce_base<D, Windows::Storage::IStorageFileStatics>
{
    HRESULT __stdcall abi_GetFileFromPathAsync(impl::abi_arg_in<hstring> path, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFileFromPathAsync(*reinterpret_cast<const hstring *>(&path)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFileFromApplicationUriAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFileFromApplicationUriAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateStreamedFileAsync(impl::abi_arg_in<hstring> displayNameWithExtension, impl::abi_arg_in<Windows::Storage::StreamedFileDataRequestedHandler> dataRequested, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> thumbnail, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateStreamedFileAsync(*reinterpret_cast<const hstring *>(&displayNameWithExtension), *reinterpret_cast<const Windows::Storage::StreamedFileDataRequestedHandler *>(&dataRequested), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&thumbnail)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReplaceWithStreamedFileAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> fileToReplace, impl::abi_arg_in<Windows::Storage::StreamedFileDataRequestedHandler> dataRequested, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> thumbnail, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ReplaceWithStreamedFileAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&fileToReplace), *reinterpret_cast<const Windows::Storage::StreamedFileDataRequestedHandler *>(&dataRequested), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&thumbnail)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateStreamedFileFromUriAsync(impl::abi_arg_in<hstring> displayNameWithExtension, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> thumbnail, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateStreamedFileFromUriAsync(*reinterpret_cast<const hstring *>(&displayNameWithExtension), *reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&thumbnail)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReplaceWithStreamedFileFromUriAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> fileToReplace, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> thumbnail, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ReplaceWithStreamedFileFromUriAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&fileToReplace), *reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&thumbnail)));
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
struct produce<D, Windows::Storage::IStorageFolder> : produce_base<D, Windows::Storage::IStorageFolder>
{
    HRESULT __stdcall abi_CreateFileAsyncOverloadDefaultOptions(impl::abi_arg_in<hstring> desiredName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateFileAsync(*reinterpret_cast<const hstring *>(&desiredName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFileAsync(impl::abi_arg_in<hstring> desiredName, Windows::Storage::CreationCollisionOption options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateFileAsync(*reinterpret_cast<const hstring *>(&desiredName), options));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFolderAsyncOverloadDefaultOptions(impl::abi_arg_in<hstring> desiredName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateFolderAsync(*reinterpret_cast<const hstring *>(&desiredName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFolderAsync(impl::abi_arg_in<hstring> desiredName, Windows::Storage::CreationCollisionOption options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateFolderAsync(*reinterpret_cast<const hstring *>(&desiredName), options));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFileAsync(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFileAsync(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFolderAsync(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFolderAsync(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemAsync(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetItemAsync(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFilesAsyncOverloadDefaultOptionsStartAndCount(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFilesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFoldersAsyncOverloadDefaultOptionsStartAndCount(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFoldersAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemsAsyncOverloadDefaultStartAndCount(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetItemsAsync());
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
struct produce<D, Windows::Storage::IStorageFolder2> : produce_base<D, Windows::Storage::IStorageFolder2>
{
    HRESULT __stdcall abi_TryGetItemAsync(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().TryGetItemAsync(*reinterpret_cast<const hstring *>(&name)));
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
struct produce<D, Windows::Storage::IStorageFolderStatics> : produce_base<D, Windows::Storage::IStorageFolderStatics>
{
    HRESULT __stdcall abi_GetFolderFromPathAsync(impl::abi_arg_in<hstring> path, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFolderFromPathAsync(*reinterpret_cast<const hstring *>(&path)));
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
struct produce<D, Windows::Storage::IStorageItem> : produce_base<D, Windows::Storage::IStorageItem>
{
    HRESULT __stdcall abi_RenameAsyncOverloadDefaultOptions(impl::abi_arg_in<hstring> desiredName, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RenameAsync(*reinterpret_cast<const hstring *>(&desiredName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RenameAsync(impl::abi_arg_in<hstring> desiredName, Windows::Storage::NameCollisionOption option, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RenameAsync(*reinterpret_cast<const hstring *>(&desiredName), option));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAsyncOverloadDefaultOptions(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().DeleteAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAsync(Windows::Storage::StorageDeleteOption option, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().DeleteAsync(option));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetBasicPropertiesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::BasicProperties>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetBasicPropertiesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Path(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Path());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Attributes(Windows::Storage::FileAttributes * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Attributes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DateCreated(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DateCreated());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsOfType(Windows::Storage::StorageItemTypes type, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOfType(type));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::IStorageItem2> : produce_base<D, Windows::Storage::IStorageItem2>
{
    HRESULT __stdcall abi_GetParentAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetParentAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsEqual(impl::abi_arg_in<Windows::Storage::IStorageItem> item, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEqual(*reinterpret_cast<const Windows::Storage::IStorageItem *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::IStorageItemProperties> : produce_base<D, Windows::Storage::IStorageItemProperties>
{
    HRESULT __stdcall abi_GetThumbnailAsyncOverloadDefaultSizeDefaultOptions(Windows::Storage::FileProperties::ThumbnailMode mode, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetThumbnailAsync(mode));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetThumbnailAsyncOverloadDefaultOptions(Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedSize, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetThumbnailAsync(mode, requestedSize));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetThumbnailAsync(Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedSize, Windows::Storage::FileProperties::ThumbnailOptions options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetThumbnailAsync(mode, requestedSize, options));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FolderRelativeId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FolderRelativeId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Storage::FileProperties::IStorageItemContentProperties> value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::Storage::IStorageItemProperties2> : produce_base<D, Windows::Storage::IStorageItemProperties2>
{
    HRESULT __stdcall abi_GetScaledImageAsThumbnailAsyncOverloadDefaultSizeDefaultOptions(Windows::Storage::FileProperties::ThumbnailMode mode, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetScaledImageAsThumbnailAsync(mode));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetScaledImageAsThumbnailAsyncOverloadDefaultOptions(Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedSize, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetScaledImageAsThumbnailAsync(mode, requestedSize));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetScaledImageAsThumbnailAsync(Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedSize, Windows::Storage::FileProperties::ThumbnailOptions options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetScaledImageAsThumbnailAsync(mode, requestedSize, options));
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
struct produce<D, Windows::Storage::IStorageItemPropertiesWithProvider> : produce_base<D, Windows::Storage::IStorageItemPropertiesWithProvider>
{
    HRESULT __stdcall get_Provider(impl::abi_arg_out<Windows::Storage::IStorageProvider> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Provider());
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
struct produce<D, Windows::Storage::IStorageLibrary> : produce_base<D, Windows::Storage::IStorageLibrary>
{
    HRESULT __stdcall abi_RequestAddFolderAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestAddFolderAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestRemoveFolderAsync(impl::abi_arg_in<Windows::Storage::IStorageFolder> folder, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestRemoveFolderAsync(*reinterpret_cast<const Windows::Storage::StorageFolder *>(&folder)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Folders(impl::abi_arg_out<Windows::Foundation::Collections::IObservableVector<Windows::Storage::StorageFolder>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Folders());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SaveFolder(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SaveFolder());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DefinitionChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Storage::StorageLibrary, Windows::Foundation::IInspectable>> handler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().DefinitionChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Storage::StorageLibrary, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DefinitionChanged(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefinitionChanged(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::IStorageLibrary2> : produce_base<D, Windows::Storage::IStorageLibrary2>
{
    HRESULT __stdcall get_ChangeTracker(impl::abi_arg_out<Windows::Storage::IStorageLibraryChangeTracker> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChangeTracker());
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
struct produce<D, Windows::Storage::IStorageLibraryChange> : produce_base<D, Windows::Storage::IStorageLibraryChange>
{
    HRESULT __stdcall get_ChangeType(Windows::Storage::StorageLibraryChangeType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChangeType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Path(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Path());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreviousPath(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreviousPath());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsOfType(Windows::Storage::StorageItemTypes type, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOfType(type));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStorageItemAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetStorageItemAsync());
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
struct produce<D, Windows::Storage::IStorageLibraryChangeReader> : produce_base<D, Windows::Storage::IStorageLibraryChangeReader>
{
    HRESULT __stdcall abi_ReadBatchAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageLibraryChange>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ReadBatchAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AcceptChangesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().AcceptChangesAsync());
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
struct produce<D, Windows::Storage::IStorageLibraryChangeTracker> : produce_base<D, Windows::Storage::IStorageLibraryChangeTracker>
{
    HRESULT __stdcall abi_GetChangeReader(impl::abi_arg_out<Windows::Storage::IStorageLibraryChangeReader> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetChangeReader());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Enable() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Enable();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Reset() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Reset();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::IStorageLibraryStatics> : produce_base<D, Windows::Storage::IStorageLibraryStatics>
{
    HRESULT __stdcall abi_GetLibraryAsync(Windows::Storage::KnownLibraryId libraryId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageLibrary>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetLibraryAsync(libraryId));
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
struct produce<D, Windows::Storage::IStorageLibraryStatics2> : produce_base<D, Windows::Storage::IStorageLibraryStatics2>
{
    HRESULT __stdcall abi_GetLibraryForUserAsync(impl::abi_arg_in<Windows::System::IUser> user, Windows::Storage::KnownLibraryId libraryId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageLibrary>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetLibraryForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), libraryId));
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
struct produce<D, Windows::Storage::IStorageProvider> : produce_base<D, Windows::Storage::IStorageProvider>
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

    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
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
struct produce<D, Windows::Storage::IStorageStreamTransaction> : produce_base<D, Windows::Storage::IStorageStreamTransaction>
{
    HRESULT __stdcall get_Stream(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Stream());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CommitAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CommitAsync());
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
struct produce<D, Windows::Storage::IStreamedFileDataRequest> : produce_base<D, Windows::Storage::IStreamedFileDataRequest>
{
    HRESULT __stdcall abi_FailAndClose(Windows::Storage::StreamedFileFailureMode failureMode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FailAndClose(failureMode);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::ISystemAudioProperties> : produce_base<D, Windows::Storage::ISystemAudioProperties>
{
    HRESULT __stdcall get_EncodingBitrate(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EncodingBitrate());
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
struct produce<D, Windows::Storage::ISystemGPSProperties> : produce_base<D, Windows::Storage::ISystemGPSProperties>
{
    HRESULT __stdcall get_LatitudeDecimal(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LatitudeDecimal());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LongitudeDecimal(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LongitudeDecimal());
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
struct produce<D, Windows::Storage::ISystemImageProperties> : produce_base<D, Windows::Storage::ISystemImageProperties>
{
    HRESULT __stdcall get_HorizontalSize(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HorizontalSize());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VerticalSize(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VerticalSize());
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
struct produce<D, Windows::Storage::ISystemMediaProperties> : produce_base<D, Windows::Storage::ISystemMediaProperties>
{
    HRESULT __stdcall get_Duration(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Producer(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Producer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Publisher(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Publisher());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SubTitle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SubTitle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Writer(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Writer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Year(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Year());
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
struct produce<D, Windows::Storage::ISystemMusicProperties> : produce_base<D, Windows::Storage::ISystemMusicProperties>
{
    HRESULT __stdcall get_AlbumArtist(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlbumArtist());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlbumTitle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlbumTitle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Artist(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Artist());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Composer(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Composer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Conductor(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Conductor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayArtist(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayArtist());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Genre(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Genre());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrackNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrackNumber());
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
struct produce<D, Windows::Storage::ISystemPhotoProperties> : produce_base<D, Windows::Storage::ISystemPhotoProperties>
{
    HRESULT __stdcall get_CameraManufacturer(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CameraManufacturer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CameraModel(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CameraModel());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DateTaken(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DateTaken());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Orientation(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Orientation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PeopleNames(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PeopleNames());
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
struct produce<D, Windows::Storage::ISystemProperties> : produce_base<D, Windows::Storage::ISystemProperties>
{
    HRESULT __stdcall get_Author(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Author());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Comment(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Comment());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ItemNameDisplay(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItemNameDisplay());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Keywords(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Keywords());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Rating(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Rating());
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

    HRESULT __stdcall get_Audio(impl::abi_arg_out<Windows::Storage::ISystemAudioProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Audio());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GPS(impl::abi_arg_out<Windows::Storage::ISystemGPSProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GPS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Media(impl::abi_arg_out<Windows::Storage::ISystemMediaProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Media());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Music(impl::abi_arg_out<Windows::Storage::ISystemMusicProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Music());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Photo(impl::abi_arg_out<Windows::Storage::ISystemPhotoProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Photo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Video(impl::abi_arg_out<Windows::Storage::ISystemVideoProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Video());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Image(impl::abi_arg_out<Windows::Storage::ISystemImageProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Image());
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
struct produce<D, Windows::Storage::ISystemVideoProperties> : produce_base<D, Windows::Storage::ISystemVideoProperties>
{
    HRESULT __stdcall get_Director(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Director());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FrameHeight(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameHeight());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FrameWidth(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameWidth());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Orientation(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Orientation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TotalBitrate(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TotalBitrate());
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

namespace Windows::Storage {

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageLibrary> impl_IStorageLibraryStatics<D>::GetLibraryAsync(Windows::Storage::KnownLibraryId libraryId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageLibrary> operation;
    check_hresult(WINRT_SHIM(IStorageLibraryStatics)->abi_GetLibraryAsync(libraryId, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageLibrary> impl_IStorageLibraryStatics2<D>::GetLibraryForUserAsync(const Windows::System::User & user, Windows::Storage::KnownLibraryId libraryId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageLibrary> operation;
    check_hresult(WINRT_SHIM(IStorageLibraryStatics2)->abi_GetLibraryForUserAsync(get_abi(user), libraryId, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> impl_IStorageLibrary<D>::RequestAddFolderAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> operation;
    check_hresult(WINRT_SHIM(IStorageLibrary)->abi_RequestAddFolderAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IStorageLibrary<D>::RequestRemoveFolderAsync(const Windows::Storage::StorageFolder & folder) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IStorageLibrary)->abi_RequestRemoveFolderAsync(get_abi(folder), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::Collections::IObservableVector<Windows::Storage::StorageFolder> impl_IStorageLibrary<D>::Folders() const
{
    Windows::Foundation::Collections::IObservableVector<Windows::Storage::StorageFolder> value;
    check_hresult(WINRT_SHIM(IStorageLibrary)->get_Folders(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IStorageLibrary<D>::SaveFolder() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IStorageLibrary)->get_SaveFolder(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IStorageLibrary<D>::DefinitionChanged(const Windows::Foundation::TypedEventHandler<Windows::Storage::StorageLibrary, Windows::Foundation::IInspectable> & handler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IStorageLibrary)->add_DefinitionChanged(get_abi(handler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IStorageLibrary> impl_IStorageLibrary<D>::DefinitionChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Storage::StorageLibrary, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IStorageLibrary>(this, &ABI::Windows::Storage::IStorageLibrary::remove_DefinitionChanged, DefinitionChanged(handler));
}

template <typename D> void impl_IStorageLibrary<D>::DefinitionChanged(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IStorageLibrary)->remove_DefinitionChanged(eventCookie));
}

template <typename D> Windows::Storage::StorageLibraryChangeTracker impl_IStorageLibrary2<D>::ChangeTracker() const
{
    Windows::Storage::StorageLibraryChangeTracker value { nullptr };
    check_hresult(WINRT_SHIM(IStorageLibrary2)->get_ChangeTracker(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IKnownFoldersStatics<D>::MusicLibrary() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IKnownFoldersStatics)->get_MusicLibrary(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IKnownFoldersStatics<D>::PicturesLibrary() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IKnownFoldersStatics)->get_PicturesLibrary(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IKnownFoldersStatics<D>::VideosLibrary() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IKnownFoldersStatics)->get_VideosLibrary(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IKnownFoldersStatics<D>::DocumentsLibrary() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IKnownFoldersStatics)->get_DocumentsLibrary(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IKnownFoldersStatics<D>::HomeGroup() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IKnownFoldersStatics)->get_HomeGroup(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IKnownFoldersStatics<D>::RemovableDevices() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IKnownFoldersStatics)->get_RemovableDevices(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IKnownFoldersStatics<D>::MediaServerDevices() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IKnownFoldersStatics)->get_MediaServerDevices(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IKnownFoldersStatics2<D>::Objects3D() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IKnownFoldersStatics2)->get_Objects3D(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IKnownFoldersStatics2<D>::AppCaptures() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IKnownFoldersStatics2)->get_AppCaptures(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IKnownFoldersStatics2<D>::RecordedCalls() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IKnownFoldersStatics2)->get_RecordedCalls(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> impl_IKnownFoldersStatics3<D>::GetFolderForUserAsync(const Windows::System::User & user, Windows::Storage::KnownFolderId folderId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> operation;
    check_hresult(WINRT_SHIM(IKnownFoldersStatics3)->abi_GetFolderForUserAsync(get_abi(user), folderId, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Storage::StorageFolder impl_IKnownFoldersPlaylistsStatics<D>::Playlists() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IKnownFoldersPlaylistsStatics)->get_Playlists(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IKnownFoldersCameraRollStatics<D>::CameraRoll() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IKnownFoldersCameraRollStatics)->get_CameraRoll(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IKnownFoldersSavedPicturesStatics<D>::SavedPictures() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IKnownFoldersSavedPicturesStatics)->get_SavedPictures(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IDownloadsFolderStatics<D>::CreateFileAsync(hstring_view desiredName) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IDownloadsFolderStatics)->abi_CreateFileAsync(get_abi(desiredName), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> impl_IDownloadsFolderStatics<D>::CreateFolderAsync(hstring_view desiredName) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> operation;
    check_hresult(WINRT_SHIM(IDownloadsFolderStatics)->abi_CreateFolderAsync(get_abi(desiredName), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IDownloadsFolderStatics<D>::CreateFileAsync(hstring_view desiredName, Windows::Storage::CreationCollisionOption option) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IDownloadsFolderStatics)->abi_CreateFileWithCollisionOptionAsync(get_abi(desiredName), option, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> impl_IDownloadsFolderStatics<D>::CreateFolderAsync(hstring_view desiredName, Windows::Storage::CreationCollisionOption option) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> operation;
    check_hresult(WINRT_SHIM(IDownloadsFolderStatics)->abi_CreateFolderWithCollisionOptionAsync(get_abi(desiredName), option, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IDownloadsFolderStatics2<D>::CreateFileForUserAsync(const Windows::System::User & user, hstring_view desiredName) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IDownloadsFolderStatics2)->abi_CreateFileForUserAsync(get_abi(user), get_abi(desiredName), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> impl_IDownloadsFolderStatics2<D>::CreateFolderForUserAsync(const Windows::System::User & user, hstring_view desiredName) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> operation;
    check_hresult(WINRT_SHIM(IDownloadsFolderStatics2)->abi_CreateFolderForUserAsync(get_abi(user), get_abi(desiredName), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IDownloadsFolderStatics2<D>::CreateFileForUserAsync(const Windows::System::User & user, hstring_view desiredName, Windows::Storage::CreationCollisionOption option) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IDownloadsFolderStatics2)->abi_CreateFileForUserWithCollisionOptionAsync(get_abi(user), get_abi(desiredName), option, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> impl_IDownloadsFolderStatics2<D>::CreateFolderForUserAsync(const Windows::System::User & user, hstring_view desiredName, Windows::Storage::CreationCollisionOption option) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> operation;
    check_hresult(WINRT_SHIM(IDownloadsFolderStatics2)->abi_CreateFolderForUserWithCollisionOptionAsync(get_abi(user), get_abi(desiredName), option, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Storage::StorageLibraryChangeType impl_IStorageLibraryChange<D>::ChangeType() const
{
    Windows::Storage::StorageLibraryChangeType value {};
    check_hresult(WINRT_SHIM(IStorageLibraryChange)->get_ChangeType(&value));
    return value;
}

template <typename D> hstring impl_IStorageLibraryChange<D>::Path() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorageLibraryChange)->get_Path(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorageLibraryChange<D>::PreviousPath() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorageLibraryChange)->get_PreviousPath(put_abi(value)));
    return value;
}

template <typename D> bool impl_IStorageLibraryChange<D>::IsOfType(Windows::Storage::StorageItemTypes type) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStorageLibraryChange)->abi_IsOfType(type, &value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem> impl_IStorageLibraryChange<D>::GetStorageItemAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem> operation;
    check_hresult(WINRT_SHIM(IStorageLibraryChange)->abi_GetStorageItemAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStorageItem<D>::RenameAsync(hstring_view desiredName) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IStorageItem)->abi_RenameAsyncOverloadDefaultOptions(get_abi(desiredName), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStorageItem<D>::RenameAsync(hstring_view desiredName, Windows::Storage::NameCollisionOption option) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IStorageItem)->abi_RenameAsync(get_abi(desiredName), option, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStorageItem<D>::DeleteAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IStorageItem)->abi_DeleteAsyncOverloadDefaultOptions(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStorageItem<D>::DeleteAsync(Windows::Storage::StorageDeleteOption option) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IStorageItem)->abi_DeleteAsync(option, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::BasicProperties> impl_IStorageItem<D>::GetBasicPropertiesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::BasicProperties> operation;
    check_hresult(WINRT_SHIM(IStorageItem)->abi_GetBasicPropertiesAsync(put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IStorageItem<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorageItem)->get_Name(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorageItem<D>::Path() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorageItem)->get_Path(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::FileAttributes impl_IStorageItem<D>::Attributes() const
{
    Windows::Storage::FileAttributes value {};
    check_hresult(WINRT_SHIM(IStorageItem)->get_Attributes(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IStorageItem<D>::DateCreated() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IStorageItem)->get_DateCreated(put_abi(value)));
    return value;
}

template <typename D> bool impl_IStorageItem<D>::IsOfType(Windows::Storage::StorageItemTypes type) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStorageItem)->abi_IsOfType(type, &value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageLibraryChange>> impl_IStorageLibraryChangeReader<D>::ReadBatchAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageLibraryChange>> operation;
    check_hresult(WINRT_SHIM(IStorageLibraryChangeReader)->abi_ReadBatchAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStorageLibraryChangeReader<D>::AcceptChangesAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IStorageLibraryChangeReader)->abi_AcceptChangesAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Storage::StorageLibraryChangeReader impl_IStorageLibraryChangeTracker<D>::GetChangeReader() const
{
    Windows::Storage::StorageLibraryChangeReader value { nullptr };
    check_hresult(WINRT_SHIM(IStorageLibraryChangeTracker)->abi_GetChangeReader(put_abi(value)));
    return value;
}

template <typename D> void impl_IStorageLibraryChangeTracker<D>::Enable() const
{
    check_hresult(WINRT_SHIM(IStorageLibraryChangeTracker)->abi_Enable());
}

template <typename D> void impl_IStorageLibraryChangeTracker<D>::Reset() const
{
    check_hresult(WINRT_SHIM(IStorageLibraryChangeTracker)->abi_Reset());
}

template <typename D> void impl_IStreamedFileDataRequest<D>::FailAndClose(Windows::Storage::StreamedFileFailureMode failureMode) const
{
    check_hresult(WINRT_SHIM(IStreamedFileDataRequest)->abi_FailAndClose(failureMode));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IStorageFileStatics<D>::GetFileFromPathAsync(hstring_view path) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IStorageFileStatics)->abi_GetFileFromPathAsync(get_abi(path), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IStorageFileStatics<D>::GetFileFromApplicationUriAsync(const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IStorageFileStatics)->abi_GetFileFromApplicationUriAsync(get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IStorageFileStatics<D>::CreateStreamedFileAsync(hstring_view displayNameWithExtension, const Windows::Storage::StreamedFileDataRequestedHandler & dataRequested, const Windows::Storage::Streams::IRandomAccessStreamReference & thumbnail) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IStorageFileStatics)->abi_CreateStreamedFileAsync(get_abi(displayNameWithExtension), get_abi(dataRequested), get_abi(thumbnail), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IStorageFileStatics<D>::ReplaceWithStreamedFileAsync(const Windows::Storage::IStorageFile & fileToReplace, const Windows::Storage::StreamedFileDataRequestedHandler & dataRequested, const Windows::Storage::Streams::IRandomAccessStreamReference & thumbnail) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IStorageFileStatics)->abi_ReplaceWithStreamedFileAsync(get_abi(fileToReplace), get_abi(dataRequested), get_abi(thumbnail), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IStorageFileStatics<D>::CreateStreamedFileFromUriAsync(hstring_view displayNameWithExtension, const Windows::Foundation::Uri & uri, const Windows::Storage::Streams::IRandomAccessStreamReference & thumbnail) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IStorageFileStatics)->abi_CreateStreamedFileFromUriAsync(get_abi(displayNameWithExtension), get_abi(uri), get_abi(thumbnail), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IStorageFileStatics<D>::ReplaceWithStreamedFileFromUriAsync(const Windows::Storage::IStorageFile & fileToReplace, const Windows::Foundation::Uri & uri, const Windows::Storage::Streams::IRandomAccessStreamReference & thumbnail) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IStorageFileStatics)->abi_ReplaceWithStreamedFileFromUriAsync(get_abi(fileToReplace), get_abi(uri), get_abi(thumbnail), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IStorageFolder<D>::CreateFileAsync(hstring_view desiredName) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IStorageFolder)->abi_CreateFileAsyncOverloadDefaultOptions(get_abi(desiredName), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IStorageFolder<D>::CreateFileAsync(hstring_view desiredName, Windows::Storage::CreationCollisionOption options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IStorageFolder)->abi_CreateFileAsync(get_abi(desiredName), options, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> impl_IStorageFolder<D>::CreateFolderAsync(hstring_view desiredName) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> operation;
    check_hresult(WINRT_SHIM(IStorageFolder)->abi_CreateFolderAsyncOverloadDefaultOptions(get_abi(desiredName), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> impl_IStorageFolder<D>::CreateFolderAsync(hstring_view desiredName, Windows::Storage::CreationCollisionOption options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> operation;
    check_hresult(WINRT_SHIM(IStorageFolder)->abi_CreateFolderAsync(get_abi(desiredName), options, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IStorageFolder<D>::GetFileAsync(hstring_view name) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IStorageFolder)->abi_GetFileAsync(get_abi(name), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> impl_IStorageFolder<D>::GetFolderAsync(hstring_view name) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> operation;
    check_hresult(WINRT_SHIM(IStorageFolder)->abi_GetFolderAsync(get_abi(name), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem> impl_IStorageFolder<D>::GetItemAsync(hstring_view name) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem> operation;
    check_hresult(WINRT_SHIM(IStorageFolder)->abi_GetItemAsync(get_abi(name), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> impl_IStorageFolder<D>::GetFilesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> operation;
    check_hresult(WINRT_SHIM(IStorageFolder)->abi_GetFilesAsyncOverloadDefaultOptionsStartAndCount(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>> impl_IStorageFolder<D>::GetFoldersAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>> operation;
    check_hresult(WINRT_SHIM(IStorageFolder)->abi_GetFoldersAsyncOverloadDefaultOptionsStartAndCount(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> impl_IStorageFolder<D>::GetItemsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> operation;
    check_hresult(WINRT_SHIM(IStorageFolder)->abi_GetItemsAsyncOverloadDefaultStartAndCount(put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IStorageFile<D>::FileType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorageFile)->get_FileType(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorageFile<D>::ContentType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorageFile)->get_ContentType(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> impl_IStorageFile<D>::OpenAsync(Windows::Storage::FileAccessMode accessMode) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> operation;
    check_hresult(WINRT_SHIM(IStorageFile)->abi_OpenAsync(accessMode, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageStreamTransaction> impl_IStorageFile<D>::OpenTransactedWriteAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageStreamTransaction> operation;
    check_hresult(WINRT_SHIM(IStorageFile)->abi_OpenTransactedWriteAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IStorageFile<D>::CopyAsync(const Windows::Storage::IStorageFolder & destinationFolder) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IStorageFile)->abi_CopyOverloadDefaultNameAndOptions(get_abi(destinationFolder), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IStorageFile<D>::CopyAsync(const Windows::Storage::IStorageFolder & destinationFolder, hstring_view desiredNewName) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IStorageFile)->abi_CopyOverloadDefaultOptions(get_abi(destinationFolder), get_abi(desiredNewName), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IStorageFile<D>::CopyAsync(const Windows::Storage::IStorageFolder & destinationFolder, hstring_view desiredNewName, Windows::Storage::NameCollisionOption option) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IStorageFile)->abi_CopyOverload(get_abi(destinationFolder), get_abi(desiredNewName), option, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStorageFile<D>::CopyAndReplaceAsync(const Windows::Storage::IStorageFile & fileToReplace) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IStorageFile)->abi_CopyAndReplaceAsync(get_abi(fileToReplace), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStorageFile<D>::MoveAsync(const Windows::Storage::IStorageFolder & destinationFolder) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IStorageFile)->abi_MoveOverloadDefaultNameAndOptions(get_abi(destinationFolder), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStorageFile<D>::MoveAsync(const Windows::Storage::IStorageFolder & destinationFolder, hstring_view desiredNewName) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IStorageFile)->abi_MoveOverloadDefaultOptions(get_abi(destinationFolder), get_abi(desiredNewName), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStorageFile<D>::MoveAsync(const Windows::Storage::IStorageFolder & destinationFolder, hstring_view desiredNewName, Windows::Storage::NameCollisionOption option) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IStorageFile)->abi_MoveOverload(get_abi(destinationFolder), get_abi(desiredNewName), option, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStorageFile<D>::MoveAndReplaceAsync(const Windows::Storage::IStorageFile & fileToReplace) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IStorageFile)->abi_MoveAndReplaceAsync(get_abi(fileToReplace), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> impl_IStorageFolderStatics<D>::GetFolderFromPathAsync(hstring_view path) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> operation;
    check_hresult(WINRT_SHIM(IStorageFolderStatics)->abi_GetFolderFromPathAsync(get_abi(path), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> impl_IStorageItem2<D>::GetParentAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> operation;
    check_hresult(WINRT_SHIM(IStorageItem2)->abi_GetParentAsync(put_abi(operation)));
    return operation;
}

template <typename D> bool impl_IStorageItem2<D>::IsEqual(const Windows::Storage::IStorageItem & item) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStorageItem2)->abi_IsEqual(get_abi(item), &value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail> impl_IStorageItemProperties<D>::GetThumbnailAsync(Windows::Storage::FileProperties::ThumbnailMode mode) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail> operation;
    check_hresult(WINRT_SHIM(IStorageItemProperties)->abi_GetThumbnailAsyncOverloadDefaultSizeDefaultOptions(mode, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail> impl_IStorageItemProperties<D>::GetThumbnailAsync(Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedSize) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail> operation;
    check_hresult(WINRT_SHIM(IStorageItemProperties)->abi_GetThumbnailAsyncOverloadDefaultOptions(mode, requestedSize, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail> impl_IStorageItemProperties<D>::GetThumbnailAsync(Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedSize, Windows::Storage::FileProperties::ThumbnailOptions options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail> operation;
    check_hresult(WINRT_SHIM(IStorageItemProperties)->abi_GetThumbnailAsync(mode, requestedSize, options, put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IStorageItemProperties<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorageItemProperties)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorageItemProperties<D>::DisplayType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorageItemProperties)->get_DisplayType(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorageItemProperties<D>::FolderRelativeId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorageItemProperties)->get_FolderRelativeId(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::FileProperties::StorageItemContentProperties impl_IStorageItemProperties<D>::Properties() const
{
    Windows::Storage::FileProperties::StorageItemContentProperties value { nullptr };
    check_hresult(WINRT_SHIM(IStorageItemProperties)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail> impl_IStorageItemProperties2<D>::GetScaledImageAsThumbnailAsync(Windows::Storage::FileProperties::ThumbnailMode mode) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail> operation;
    check_hresult(WINRT_SHIM(IStorageItemProperties2)->abi_GetScaledImageAsThumbnailAsyncOverloadDefaultSizeDefaultOptions(mode, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail> impl_IStorageItemProperties2<D>::GetScaledImageAsThumbnailAsync(Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedSize) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail> operation;
    check_hresult(WINRT_SHIM(IStorageItemProperties2)->abi_GetScaledImageAsThumbnailAsyncOverloadDefaultOptions(mode, requestedSize, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail> impl_IStorageItemProperties2<D>::GetScaledImageAsThumbnailAsync(Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedSize, Windows::Storage::FileProperties::ThumbnailOptions options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::StorageItemThumbnail> operation;
    check_hresult(WINRT_SHIM(IStorageItemProperties2)->abi_GetScaledImageAsThumbnailAsync(mode, requestedSize, options, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Storage::StorageProvider impl_IStorageItemPropertiesWithProvider<D>::Provider() const
{
    Windows::Storage::StorageProvider value { nullptr };
    check_hresult(WINRT_SHIM(IStorageItemPropertiesWithProvider)->get_Provider(put_abi(value)));
    return value;
}

template <typename D> bool impl_IStorageFilePropertiesWithAvailability<D>::IsAvailable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStorageFilePropertiesWithAvailability)->get_IsAvailable(&value));
    return value;
}

template <typename D> hstring impl_IStorageProvider<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorageProvider)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorageProvider<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorageProvider)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem> impl_IStorageFolder2<D>::TryGetItemAsync(hstring_view name) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem> operation;
    check_hresult(WINRT_SHIM(IStorageFolder2)->abi_TryGetItemAsync(get_abi(name), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> impl_IStorageFile2<D>::OpenAsync(Windows::Storage::FileAccessMode accessMode, Windows::Storage::StorageOpenOptions options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> operation;
    check_hresult(WINRT_SHIM(IStorageFile2)->abi_OpenWithOptionsAsync(accessMode, options, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageStreamTransaction> impl_IStorageFile2<D>::OpenTransactedWriteAsync(Windows::Storage::StorageOpenOptions options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageStreamTransaction> operation;
    check_hresult(WINRT_SHIM(IStorageFile2)->abi_OpenTransactedWriteWithOptionsAsync(options, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IFileIOStatics<D>::ReadTextAsync(const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<hstring> textOperation;
    check_hresult(WINRT_SHIM(IFileIOStatics)->abi_ReadTextAsync(get_abi(file), put_abi(textOperation)));
    return textOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IFileIOStatics<D>::ReadTextAsync(const Windows::Storage::IStorageFile & file, Windows::Storage::Streams::UnicodeEncoding encoding) const
{
    Windows::Foundation::IAsyncOperation<hstring> textOperation;
    check_hresult(WINRT_SHIM(IFileIOStatics)->abi_ReadTextWithEncodingAsync(get_abi(file), encoding, put_abi(textOperation)));
    return textOperation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IFileIOStatics<D>::WriteTextAsync(const Windows::Storage::IStorageFile & file, hstring_view contents) const
{
    Windows::Foundation::IAsyncAction textOperation;
    check_hresult(WINRT_SHIM(IFileIOStatics)->abi_WriteTextAsync(get_abi(file), get_abi(contents), put_abi(textOperation)));
    return textOperation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IFileIOStatics<D>::WriteTextAsync(const Windows::Storage::IStorageFile & file, hstring_view contents, Windows::Storage::Streams::UnicodeEncoding encoding) const
{
    Windows::Foundation::IAsyncAction textOperation;
    check_hresult(WINRT_SHIM(IFileIOStatics)->abi_WriteTextWithEncodingAsync(get_abi(file), get_abi(contents), encoding, put_abi(textOperation)));
    return textOperation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IFileIOStatics<D>::AppendTextAsync(const Windows::Storage::IStorageFile & file, hstring_view contents) const
{
    Windows::Foundation::IAsyncAction textOperation;
    check_hresult(WINRT_SHIM(IFileIOStatics)->abi_AppendTextAsync(get_abi(file), get_abi(contents), put_abi(textOperation)));
    return textOperation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IFileIOStatics<D>::AppendTextAsync(const Windows::Storage::IStorageFile & file, hstring_view contents, Windows::Storage::Streams::UnicodeEncoding encoding) const
{
    Windows::Foundation::IAsyncAction textOperation;
    check_hresult(WINRT_SHIM(IFileIOStatics)->abi_AppendTextWithEncodingAsync(get_abi(file), get_abi(contents), encoding, put_abi(textOperation)));
    return textOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>> impl_IFileIOStatics<D>::ReadLinesAsync(const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>> linesOperation;
    check_hresult(WINRT_SHIM(IFileIOStatics)->abi_ReadLinesAsync(get_abi(file), put_abi(linesOperation)));
    return linesOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>> impl_IFileIOStatics<D>::ReadLinesAsync(const Windows::Storage::IStorageFile & file, Windows::Storage::Streams::UnicodeEncoding encoding) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>> linesOperation;
    check_hresult(WINRT_SHIM(IFileIOStatics)->abi_ReadLinesWithEncodingAsync(get_abi(file), encoding, put_abi(linesOperation)));
    return linesOperation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IFileIOStatics<D>::WriteLinesAsync(const Windows::Storage::IStorageFile & file, iterable<hstring> lines) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IFileIOStatics)->abi_WriteLinesAsync(get_abi(file), get_abi(lines), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IFileIOStatics<D>::WriteLinesAsync(const Windows::Storage::IStorageFile & file, iterable<hstring> lines, Windows::Storage::Streams::UnicodeEncoding encoding) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IFileIOStatics)->abi_WriteLinesWithEncodingAsync(get_abi(file), get_abi(lines), encoding, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IFileIOStatics<D>::AppendLinesAsync(const Windows::Storage::IStorageFile & file, iterable<hstring> lines) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IFileIOStatics)->abi_AppendLinesAsync(get_abi(file), get_abi(lines), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IFileIOStatics<D>::AppendLinesAsync(const Windows::Storage::IStorageFile & file, iterable<hstring> lines, Windows::Storage::Streams::UnicodeEncoding encoding) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IFileIOStatics)->abi_AppendLinesWithEncodingAsync(get_abi(file), get_abi(lines), encoding, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_IFileIOStatics<D>::ReadBufferAsync(const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> operation;
    check_hresult(WINRT_SHIM(IFileIOStatics)->abi_ReadBufferAsync(get_abi(file), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IFileIOStatics<D>::WriteBufferAsync(const Windows::Storage::IStorageFile & file, const Windows::Storage::Streams::IBuffer & buffer) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IFileIOStatics)->abi_WriteBufferAsync(get_abi(file), get_abi(buffer), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IFileIOStatics<D>::WriteBytesAsync(const Windows::Storage::IStorageFile & file, array_view<const uint8_t> buffer) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IFileIOStatics)->abi_WriteBytesAsync(get_abi(file), buffer.size(), get_abi(buffer), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IPathIOStatics<D>::ReadTextAsync(hstring_view absolutePath) const
{
    Windows::Foundation::IAsyncOperation<hstring> textOperation;
    check_hresult(WINRT_SHIM(IPathIOStatics)->abi_ReadTextAsync(get_abi(absolutePath), put_abi(textOperation)));
    return textOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IPathIOStatics<D>::ReadTextAsync(hstring_view absolutePath, Windows::Storage::Streams::UnicodeEncoding encoding) const
{
    Windows::Foundation::IAsyncOperation<hstring> textOperation;
    check_hresult(WINRT_SHIM(IPathIOStatics)->abi_ReadTextWithEncodingAsync(get_abi(absolutePath), encoding, put_abi(textOperation)));
    return textOperation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPathIOStatics<D>::WriteTextAsync(hstring_view absolutePath, hstring_view contents) const
{
    Windows::Foundation::IAsyncAction textOperation;
    check_hresult(WINRT_SHIM(IPathIOStatics)->abi_WriteTextAsync(get_abi(absolutePath), get_abi(contents), put_abi(textOperation)));
    return textOperation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPathIOStatics<D>::WriteTextAsync(hstring_view absolutePath, hstring_view contents, Windows::Storage::Streams::UnicodeEncoding encoding) const
{
    Windows::Foundation::IAsyncAction textOperation;
    check_hresult(WINRT_SHIM(IPathIOStatics)->abi_WriteTextWithEncodingAsync(get_abi(absolutePath), get_abi(contents), encoding, put_abi(textOperation)));
    return textOperation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPathIOStatics<D>::AppendTextAsync(hstring_view absolutePath, hstring_view contents) const
{
    Windows::Foundation::IAsyncAction textOperation;
    check_hresult(WINRT_SHIM(IPathIOStatics)->abi_AppendTextAsync(get_abi(absolutePath), get_abi(contents), put_abi(textOperation)));
    return textOperation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPathIOStatics<D>::AppendTextAsync(hstring_view absolutePath, hstring_view contents, Windows::Storage::Streams::UnicodeEncoding encoding) const
{
    Windows::Foundation::IAsyncAction textOperation;
    check_hresult(WINRT_SHIM(IPathIOStatics)->abi_AppendTextWithEncodingAsync(get_abi(absolutePath), get_abi(contents), encoding, put_abi(textOperation)));
    return textOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>> impl_IPathIOStatics<D>::ReadLinesAsync(hstring_view absolutePath) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>> linesOperation;
    check_hresult(WINRT_SHIM(IPathIOStatics)->abi_ReadLinesAsync(get_abi(absolutePath), put_abi(linesOperation)));
    return linesOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>> impl_IPathIOStatics<D>::ReadLinesAsync(hstring_view absolutePath, Windows::Storage::Streams::UnicodeEncoding encoding) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>> linesOperation;
    check_hresult(WINRT_SHIM(IPathIOStatics)->abi_ReadLinesWithEncodingAsync(get_abi(absolutePath), encoding, put_abi(linesOperation)));
    return linesOperation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPathIOStatics<D>::WriteLinesAsync(hstring_view absolutePath, iterable<hstring> lines) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IPathIOStatics)->abi_WriteLinesAsync(get_abi(absolutePath), get_abi(lines), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPathIOStatics<D>::WriteLinesAsync(hstring_view absolutePath, iterable<hstring> lines, Windows::Storage::Streams::UnicodeEncoding encoding) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IPathIOStatics)->abi_WriteLinesWithEncodingAsync(get_abi(absolutePath), get_abi(lines), encoding, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPathIOStatics<D>::AppendLinesAsync(hstring_view absolutePath, iterable<hstring> lines) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IPathIOStatics)->abi_AppendLinesAsync(get_abi(absolutePath), get_abi(lines), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPathIOStatics<D>::AppendLinesAsync(hstring_view absolutePath, iterable<hstring> lines, Windows::Storage::Streams::UnicodeEncoding encoding) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IPathIOStatics)->abi_AppendLinesWithEncodingAsync(get_abi(absolutePath), get_abi(lines), encoding, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_IPathIOStatics<D>::ReadBufferAsync(hstring_view absolutePath) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> operation;
    check_hresult(WINRT_SHIM(IPathIOStatics)->abi_ReadBufferAsync(get_abi(absolutePath), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPathIOStatics<D>::WriteBufferAsync(hstring_view absolutePath, const Windows::Storage::Streams::IBuffer & buffer) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IPathIOStatics)->abi_WriteBufferAsync(get_abi(absolutePath), get_abi(buffer), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPathIOStatics<D>::WriteBytesAsync(hstring_view absolutePath, array_view<const uint8_t> buffer) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IPathIOStatics)->abi_WriteBytesAsync(get_abi(absolutePath), buffer.size(), get_abi(buffer), put_abi(operation)));
    return operation;
}

template <typename D> void impl_ICachedFileManagerStatics<D>::DeferUpdates(const Windows::Storage::IStorageFile & file) const
{
    check_hresult(WINRT_SHIM(ICachedFileManagerStatics)->abi_DeferUpdates(get_abi(file)));
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Storage::Provider::FileUpdateStatus> impl_ICachedFileManagerStatics<D>::CompleteUpdatesAsync(const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Storage::Provider::FileUpdateStatus> operation;
    check_hresult(WINRT_SHIM(ICachedFileManagerStatics)->abi_CompleteUpdatesAsync(get_abi(file), put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_ISystemAudioProperties<D>::EncodingBitrate() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemAudioProperties)->get_EncodingBitrate(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemGPSProperties<D>::LatitudeDecimal() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemGPSProperties)->get_LatitudeDecimal(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemGPSProperties<D>::LongitudeDecimal() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemGPSProperties)->get_LongitudeDecimal(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemImageProperties<D>::HorizontalSize() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemImageProperties)->get_HorizontalSize(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemImageProperties<D>::VerticalSize() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemImageProperties)->get_VerticalSize(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemMediaProperties<D>::Duration() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemMediaProperties)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemMediaProperties<D>::Producer() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemMediaProperties)->get_Producer(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemMediaProperties<D>::Publisher() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemMediaProperties)->get_Publisher(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemMediaProperties<D>::SubTitle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemMediaProperties)->get_SubTitle(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemMediaProperties<D>::Writer() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemMediaProperties)->get_Writer(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemMediaProperties<D>::Year() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemMediaProperties)->get_Year(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemMusicProperties<D>::AlbumArtist() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemMusicProperties)->get_AlbumArtist(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemMusicProperties<D>::AlbumTitle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemMusicProperties)->get_AlbumTitle(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemMusicProperties<D>::Artist() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemMusicProperties)->get_Artist(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemMusicProperties<D>::Composer() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemMusicProperties)->get_Composer(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemMusicProperties<D>::Conductor() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemMusicProperties)->get_Conductor(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemMusicProperties<D>::DisplayArtist() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemMusicProperties)->get_DisplayArtist(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemMusicProperties<D>::Genre() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemMusicProperties)->get_Genre(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemMusicProperties<D>::TrackNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemMusicProperties)->get_TrackNumber(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemPhotoProperties<D>::CameraManufacturer() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemPhotoProperties)->get_CameraManufacturer(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemPhotoProperties<D>::CameraModel() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemPhotoProperties)->get_CameraModel(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemPhotoProperties<D>::DateTaken() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemPhotoProperties)->get_DateTaken(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemPhotoProperties<D>::Orientation() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemPhotoProperties)->get_Orientation(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemPhotoProperties<D>::PeopleNames() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemPhotoProperties)->get_PeopleNames(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemVideoProperties<D>::Director() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemVideoProperties)->get_Director(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemVideoProperties<D>::FrameHeight() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemVideoProperties)->get_FrameHeight(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemVideoProperties<D>::FrameWidth() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemVideoProperties)->get_FrameWidth(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemVideoProperties<D>::Orientation() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemVideoProperties)->get_Orientation(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemVideoProperties<D>::TotalBitrate() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemVideoProperties)->get_TotalBitrate(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemProperties<D>::Author() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemProperties)->get_Author(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemProperties<D>::Comment() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemProperties)->get_Comment(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemProperties<D>::ItemNameDisplay() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemProperties)->get_ItemNameDisplay(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemProperties<D>::Keywords() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemProperties)->get_Keywords(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemProperties<D>::Rating() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemProperties)->get_Rating(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISystemProperties<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISystemProperties)->get_Title(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::SystemAudioProperties impl_ISystemProperties<D>::Audio() const
{
    Windows::Storage::SystemAudioProperties value { nullptr };
    check_hresult(WINRT_SHIM(ISystemProperties)->get_Audio(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::SystemGPSProperties impl_ISystemProperties<D>::GPS() const
{
    Windows::Storage::SystemGPSProperties value { nullptr };
    check_hresult(WINRT_SHIM(ISystemProperties)->get_GPS(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::SystemMediaProperties impl_ISystemProperties<D>::Media() const
{
    Windows::Storage::SystemMediaProperties value { nullptr };
    check_hresult(WINRT_SHIM(ISystemProperties)->get_Media(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::SystemMusicProperties impl_ISystemProperties<D>::Music() const
{
    Windows::Storage::SystemMusicProperties value { nullptr };
    check_hresult(WINRT_SHIM(ISystemProperties)->get_Music(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::SystemPhotoProperties impl_ISystemProperties<D>::Photo() const
{
    Windows::Storage::SystemPhotoProperties value { nullptr };
    check_hresult(WINRT_SHIM(ISystemProperties)->get_Photo(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::SystemVideoProperties impl_ISystemProperties<D>::Video() const
{
    Windows::Storage::SystemVideoProperties value { nullptr };
    check_hresult(WINRT_SHIM(ISystemProperties)->get_Video(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::SystemImageProperties impl_ISystemProperties<D>::Image() const
{
    Windows::Storage::SystemImageProperties value { nullptr };
    check_hresult(WINRT_SHIM(ISystemProperties)->get_Image(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStream impl_IStorageStreamTransaction<D>::Stream() const
{
    Windows::Storage::Streams::IRandomAccessStream value;
    check_hresult(WINRT_SHIM(IStorageStreamTransaction)->get_Stream(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStorageStreamTransaction<D>::CommitAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IStorageStreamTransaction)->abi_CommitAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Storage::ApplicationData impl_IApplicationDataStatics<D>::Current() const
{
    Windows::Storage::ApplicationData value { nullptr };
    check_hresult(WINRT_SHIM(IApplicationDataStatics)->get_Current(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::ApplicationData> impl_IApplicationDataStatics2<D>::GetForUserAsync(const Windows::System::User & user) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::ApplicationData> getForUserOperation;
    check_hresult(WINRT_SHIM(IApplicationDataStatics2)->abi_GetForUserAsync(get_abi(user), put_abi(getForUserOperation)));
    return getForUserOperation;
}

template <typename D> uint32_t impl_IApplicationData<D>::Version() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IApplicationData)->get_Version(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IApplicationData<D>::SetVersionAsync(uint32_t desiredVersion, const Windows::Storage::ApplicationDataSetVersionHandler & handler) const
{
    Windows::Foundation::IAsyncAction setVersionOperation;
    check_hresult(WINRT_SHIM(IApplicationData)->abi_SetVersionAsync(desiredVersion, get_abi(handler), put_abi(setVersionOperation)));
    return setVersionOperation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IApplicationData<D>::ClearAsync() const
{
    Windows::Foundation::IAsyncAction clearOperation;
    check_hresult(WINRT_SHIM(IApplicationData)->abi_ClearAllAsync(put_abi(clearOperation)));
    return clearOperation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IApplicationData<D>::ClearAsync(Windows::Storage::ApplicationDataLocality locality) const
{
    Windows::Foundation::IAsyncAction clearOperation;
    check_hresult(WINRT_SHIM(IApplicationData)->abi_ClearAsync(locality, put_abi(clearOperation)));
    return clearOperation;
}

template <typename D> Windows::Storage::ApplicationDataContainer impl_IApplicationData<D>::LocalSettings() const
{
    Windows::Storage::ApplicationDataContainer value { nullptr };
    check_hresult(WINRT_SHIM(IApplicationData)->get_LocalSettings(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::ApplicationDataContainer impl_IApplicationData<D>::RoamingSettings() const
{
    Windows::Storage::ApplicationDataContainer value { nullptr };
    check_hresult(WINRT_SHIM(IApplicationData)->get_RoamingSettings(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IApplicationData<D>::LocalFolder() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IApplicationData)->get_LocalFolder(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IApplicationData<D>::RoamingFolder() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IApplicationData)->get_RoamingFolder(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IApplicationData<D>::TemporaryFolder() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IApplicationData)->get_TemporaryFolder(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IApplicationData<D>::DataChanged(const Windows::Foundation::TypedEventHandler<Windows::Storage::ApplicationData, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IApplicationData)->add_DataChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IApplicationData> impl_IApplicationData<D>::DataChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Storage::ApplicationData, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IApplicationData>(this, &ABI::Windows::Storage::IApplicationData::remove_DataChanged, DataChanged(handler));
}

template <typename D> void impl_IApplicationData<D>::DataChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IApplicationData)->remove_DataChanged(token));
}

template <typename D> void impl_IApplicationData<D>::SignalDataChanged() const
{
    check_hresult(WINRT_SHIM(IApplicationData)->abi_SignalDataChanged());
}

template <typename D> uint64_t impl_IApplicationData<D>::RoamingStorageQuota() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IApplicationData)->get_RoamingStorageQuota(&value));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IApplicationData2<D>::LocalCacheFolder() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IApplicationData2)->get_LocalCacheFolder(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IApplicationData3<D>::GetPublisherCacheFolder(hstring_view folderName) const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IApplicationData3)->abi_GetPublisherCacheFolder(get_abi(folderName), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IApplicationData3<D>::ClearPublisherCacheFolderAsync(hstring_view folderName) const
{
    Windows::Foundation::IAsyncAction clearOperation;
    check_hresult(WINRT_SHIM(IApplicationData3)->abi_ClearPublisherCacheFolderAsync(get_abi(folderName), put_abi(clearOperation)));
    return clearOperation;
}

template <typename D> Windows::Storage::StorageFolder impl_IApplicationData3<D>::SharedLocalFolder() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IApplicationData3)->get_SharedLocalFolder(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_ISetVersionRequest<D>::CurrentVersion() const
{
    uint32_t currentVersion {};
    check_hresult(WINRT_SHIM(ISetVersionRequest)->get_CurrentVersion(&currentVersion));
    return currentVersion;
}

template <typename D> uint32_t impl_ISetVersionRequest<D>::DesiredVersion() const
{
    uint32_t desiredVersion {};
    check_hresult(WINRT_SHIM(ISetVersionRequest)->get_DesiredVersion(&desiredVersion));
    return desiredVersion;
}

template <typename D> Windows::Storage::SetVersionDeferral impl_ISetVersionRequest<D>::GetDeferral() const
{
    Windows::Storage::SetVersionDeferral deferral { nullptr };
    check_hresult(WINRT_SHIM(ISetVersionRequest)->abi_GetDeferral(put_abi(deferral)));
    return deferral;
}

template <typename D> void impl_ISetVersionDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(ISetVersionDeferral)->abi_Complete());
}

template <typename D> hstring impl_IApplicationDataContainer<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IApplicationDataContainer)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::ApplicationDataLocality impl_IApplicationDataContainer<D>::Locality() const
{
    Windows::Storage::ApplicationDataLocality value {};
    check_hresult(WINRT_SHIM(IApplicationDataContainer)->get_Locality(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IPropertySet impl_IApplicationDataContainer<D>::Values() const
{
    Windows::Foundation::Collections::IPropertySet value;
    check_hresult(WINRT_SHIM(IApplicationDataContainer)->get_Values(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Storage::ApplicationDataContainer> impl_IApplicationDataContainer<D>::Containers() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Storage::ApplicationDataContainer> value;
    check_hresult(WINRT_SHIM(IApplicationDataContainer)->get_Containers(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::ApplicationDataContainer impl_IApplicationDataContainer<D>::CreateContainer(hstring_view name, Windows::Storage::ApplicationDataCreateDisposition disposition) const
{
    Windows::Storage::ApplicationDataContainer container { nullptr };
    check_hresult(WINRT_SHIM(IApplicationDataContainer)->abi_CreateContainer(get_abi(name), disposition, put_abi(container)));
    return container;
}

template <typename D> void impl_IApplicationDataContainer<D>::DeleteContainer(hstring_view name) const
{
    check_hresult(WINRT_SHIM(IApplicationDataContainer)->abi_DeleteContainer(get_abi(name)));
}

inline Windows::Storage::ApplicationData ApplicationData::Current()
{
    return get_activation_factory<ApplicationData, IApplicationDataStatics>().Current();
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::ApplicationData> ApplicationData::GetForUserAsync(const Windows::System::User & user)
{
    return get_activation_factory<ApplicationData, IApplicationDataStatics2>().GetForUserAsync(user);
}

inline ApplicationDataCompositeValue::ApplicationDataCompositeValue() :
    ApplicationDataCompositeValue(activate_instance<ApplicationDataCompositeValue>())
{}

inline void CachedFileManager::DeferUpdates(const Windows::Storage::IStorageFile & file)
{
    get_activation_factory<CachedFileManager, ICachedFileManagerStatics>().DeferUpdates(file);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Storage::Provider::FileUpdateStatus> CachedFileManager::CompleteUpdatesAsync(const Windows::Storage::IStorageFile & file)
{
    return get_activation_factory<CachedFileManager, ICachedFileManagerStatics>().CompleteUpdatesAsync(file);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> DownloadsFolder::CreateFileAsync(hstring_view desiredName)
{
    return get_activation_factory<DownloadsFolder, IDownloadsFolderStatics>().CreateFileAsync(desiredName);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> DownloadsFolder::CreateFolderAsync(hstring_view desiredName)
{
    return get_activation_factory<DownloadsFolder, IDownloadsFolderStatics>().CreateFolderAsync(desiredName);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> DownloadsFolder::CreateFileAsync(hstring_view desiredName, Windows::Storage::CreationCollisionOption option)
{
    return get_activation_factory<DownloadsFolder, IDownloadsFolderStatics>().CreateFileAsync(desiredName, option);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> DownloadsFolder::CreateFolderAsync(hstring_view desiredName, Windows::Storage::CreationCollisionOption option)
{
    return get_activation_factory<DownloadsFolder, IDownloadsFolderStatics>().CreateFolderAsync(desiredName, option);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> DownloadsFolder::CreateFileForUserAsync(const Windows::System::User & user, hstring_view desiredName)
{
    return get_activation_factory<DownloadsFolder, IDownloadsFolderStatics2>().CreateFileForUserAsync(user, desiredName);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> DownloadsFolder::CreateFolderForUserAsync(const Windows::System::User & user, hstring_view desiredName)
{
    return get_activation_factory<DownloadsFolder, IDownloadsFolderStatics2>().CreateFolderForUserAsync(user, desiredName);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> DownloadsFolder::CreateFileForUserAsync(const Windows::System::User & user, hstring_view desiredName, Windows::Storage::CreationCollisionOption option)
{
    return get_activation_factory<DownloadsFolder, IDownloadsFolderStatics2>().CreateFileForUserAsync(user, desiredName, option);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> DownloadsFolder::CreateFolderForUserAsync(const Windows::System::User & user, hstring_view desiredName, Windows::Storage::CreationCollisionOption option)
{
    return get_activation_factory<DownloadsFolder, IDownloadsFolderStatics2>().CreateFolderForUserAsync(user, desiredName, option);
}

inline Windows::Foundation::IAsyncOperation<hstring> FileIO::ReadTextAsync(const Windows::Storage::IStorageFile & file)
{
    return get_activation_factory<FileIO, IFileIOStatics>().ReadTextAsync(file);
}

inline Windows::Foundation::IAsyncOperation<hstring> FileIO::ReadTextAsync(const Windows::Storage::IStorageFile & file, Windows::Storage::Streams::UnicodeEncoding encoding)
{
    return get_activation_factory<FileIO, IFileIOStatics>().ReadTextAsync(file, encoding);
}

inline Windows::Foundation::IAsyncAction FileIO::WriteTextAsync(const Windows::Storage::IStorageFile & file, hstring_view contents)
{
    return get_activation_factory<FileIO, IFileIOStatics>().WriteTextAsync(file, contents);
}

inline Windows::Foundation::IAsyncAction FileIO::WriteTextAsync(const Windows::Storage::IStorageFile & file, hstring_view contents, Windows::Storage::Streams::UnicodeEncoding encoding)
{
    return get_activation_factory<FileIO, IFileIOStatics>().WriteTextAsync(file, contents, encoding);
}

inline Windows::Foundation::IAsyncAction FileIO::AppendTextAsync(const Windows::Storage::IStorageFile & file, hstring_view contents)
{
    return get_activation_factory<FileIO, IFileIOStatics>().AppendTextAsync(file, contents);
}

inline Windows::Foundation::IAsyncAction FileIO::AppendTextAsync(const Windows::Storage::IStorageFile & file, hstring_view contents, Windows::Storage::Streams::UnicodeEncoding encoding)
{
    return get_activation_factory<FileIO, IFileIOStatics>().AppendTextAsync(file, contents, encoding);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>> FileIO::ReadLinesAsync(const Windows::Storage::IStorageFile & file)
{
    return get_activation_factory<FileIO, IFileIOStatics>().ReadLinesAsync(file);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>> FileIO::ReadLinesAsync(const Windows::Storage::IStorageFile & file, Windows::Storage::Streams::UnicodeEncoding encoding)
{
    return get_activation_factory<FileIO, IFileIOStatics>().ReadLinesAsync(file, encoding);
}

inline Windows::Foundation::IAsyncAction FileIO::WriteLinesAsync(const Windows::Storage::IStorageFile & file, iterable<hstring> lines)
{
    return get_activation_factory<FileIO, IFileIOStatics>().WriteLinesAsync(file, lines);
}

inline Windows::Foundation::IAsyncAction FileIO::WriteLinesAsync(const Windows::Storage::IStorageFile & file, iterable<hstring> lines, Windows::Storage::Streams::UnicodeEncoding encoding)
{
    return get_activation_factory<FileIO, IFileIOStatics>().WriteLinesAsync(file, lines, encoding);
}

inline Windows::Foundation::IAsyncAction FileIO::AppendLinesAsync(const Windows::Storage::IStorageFile & file, iterable<hstring> lines)
{
    return get_activation_factory<FileIO, IFileIOStatics>().AppendLinesAsync(file, lines);
}

inline Windows::Foundation::IAsyncAction FileIO::AppendLinesAsync(const Windows::Storage::IStorageFile & file, iterable<hstring> lines, Windows::Storage::Streams::UnicodeEncoding encoding)
{
    return get_activation_factory<FileIO, IFileIOStatics>().AppendLinesAsync(file, lines, encoding);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> FileIO::ReadBufferAsync(const Windows::Storage::IStorageFile & file)
{
    return get_activation_factory<FileIO, IFileIOStatics>().ReadBufferAsync(file);
}

inline Windows::Foundation::IAsyncAction FileIO::WriteBufferAsync(const Windows::Storage::IStorageFile & file, const Windows::Storage::Streams::IBuffer & buffer)
{
    return get_activation_factory<FileIO, IFileIOStatics>().WriteBufferAsync(file, buffer);
}

inline Windows::Foundation::IAsyncAction FileIO::WriteBytesAsync(const Windows::Storage::IStorageFile & file, array_view<const uint8_t> buffer)
{
    return get_activation_factory<FileIO, IFileIOStatics>().WriteBytesAsync(file, buffer);
}

inline Windows::Storage::StorageFolder KnownFolders::CameraRoll()
{
    return get_activation_factory<KnownFolders, IKnownFoldersCameraRollStatics>().CameraRoll();
}

inline Windows::Storage::StorageFolder KnownFolders::Playlists()
{
    return get_activation_factory<KnownFolders, IKnownFoldersPlaylistsStatics>().Playlists();
}

inline Windows::Storage::StorageFolder KnownFolders::SavedPictures()
{
    return get_activation_factory<KnownFolders, IKnownFoldersSavedPicturesStatics>().SavedPictures();
}

inline Windows::Storage::StorageFolder KnownFolders::MusicLibrary()
{
    return get_activation_factory<KnownFolders, IKnownFoldersStatics>().MusicLibrary();
}

inline Windows::Storage::StorageFolder KnownFolders::PicturesLibrary()
{
    return get_activation_factory<KnownFolders, IKnownFoldersStatics>().PicturesLibrary();
}

inline Windows::Storage::StorageFolder KnownFolders::VideosLibrary()
{
    return get_activation_factory<KnownFolders, IKnownFoldersStatics>().VideosLibrary();
}

inline Windows::Storage::StorageFolder KnownFolders::DocumentsLibrary()
{
    return get_activation_factory<KnownFolders, IKnownFoldersStatics>().DocumentsLibrary();
}

inline Windows::Storage::StorageFolder KnownFolders::HomeGroup()
{
    return get_activation_factory<KnownFolders, IKnownFoldersStatics>().HomeGroup();
}

inline Windows::Storage::StorageFolder KnownFolders::RemovableDevices()
{
    return get_activation_factory<KnownFolders, IKnownFoldersStatics>().RemovableDevices();
}

inline Windows::Storage::StorageFolder KnownFolders::MediaServerDevices()
{
    return get_activation_factory<KnownFolders, IKnownFoldersStatics>().MediaServerDevices();
}

inline Windows::Storage::StorageFolder KnownFolders::Objects3D()
{
    return get_activation_factory<KnownFolders, IKnownFoldersStatics2>().Objects3D();
}

inline Windows::Storage::StorageFolder KnownFolders::AppCaptures()
{
    return get_activation_factory<KnownFolders, IKnownFoldersStatics2>().AppCaptures();
}

inline Windows::Storage::StorageFolder KnownFolders::RecordedCalls()
{
    return get_activation_factory<KnownFolders, IKnownFoldersStatics2>().RecordedCalls();
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> KnownFolders::GetFolderForUserAsync(const Windows::System::User & user, Windows::Storage::KnownFolderId folderId)
{
    return get_activation_factory<KnownFolders, IKnownFoldersStatics3>().GetFolderForUserAsync(user, folderId);
}

inline Windows::Foundation::IAsyncOperation<hstring> PathIO::ReadTextAsync(hstring_view absolutePath)
{
    return get_activation_factory<PathIO, IPathIOStatics>().ReadTextAsync(absolutePath);
}

inline Windows::Foundation::IAsyncOperation<hstring> PathIO::ReadTextAsync(hstring_view absolutePath, Windows::Storage::Streams::UnicodeEncoding encoding)
{
    return get_activation_factory<PathIO, IPathIOStatics>().ReadTextAsync(absolutePath, encoding);
}

inline Windows::Foundation::IAsyncAction PathIO::WriteTextAsync(hstring_view absolutePath, hstring_view contents)
{
    return get_activation_factory<PathIO, IPathIOStatics>().WriteTextAsync(absolutePath, contents);
}

inline Windows::Foundation::IAsyncAction PathIO::WriteTextAsync(hstring_view absolutePath, hstring_view contents, Windows::Storage::Streams::UnicodeEncoding encoding)
{
    return get_activation_factory<PathIO, IPathIOStatics>().WriteTextAsync(absolutePath, contents, encoding);
}

inline Windows::Foundation::IAsyncAction PathIO::AppendTextAsync(hstring_view absolutePath, hstring_view contents)
{
    return get_activation_factory<PathIO, IPathIOStatics>().AppendTextAsync(absolutePath, contents);
}

inline Windows::Foundation::IAsyncAction PathIO::AppendTextAsync(hstring_view absolutePath, hstring_view contents, Windows::Storage::Streams::UnicodeEncoding encoding)
{
    return get_activation_factory<PathIO, IPathIOStatics>().AppendTextAsync(absolutePath, contents, encoding);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>> PathIO::ReadLinesAsync(hstring_view absolutePath)
{
    return get_activation_factory<PathIO, IPathIOStatics>().ReadLinesAsync(absolutePath);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>> PathIO::ReadLinesAsync(hstring_view absolutePath, Windows::Storage::Streams::UnicodeEncoding encoding)
{
    return get_activation_factory<PathIO, IPathIOStatics>().ReadLinesAsync(absolutePath, encoding);
}

inline Windows::Foundation::IAsyncAction PathIO::WriteLinesAsync(hstring_view absolutePath, iterable<hstring> lines)
{
    return get_activation_factory<PathIO, IPathIOStatics>().WriteLinesAsync(absolutePath, lines);
}

inline Windows::Foundation::IAsyncAction PathIO::WriteLinesAsync(hstring_view absolutePath, iterable<hstring> lines, Windows::Storage::Streams::UnicodeEncoding encoding)
{
    return get_activation_factory<PathIO, IPathIOStatics>().WriteLinesAsync(absolutePath, lines, encoding);
}

inline Windows::Foundation::IAsyncAction PathIO::AppendLinesAsync(hstring_view absolutePath, iterable<hstring> lines)
{
    return get_activation_factory<PathIO, IPathIOStatics>().AppendLinesAsync(absolutePath, lines);
}

inline Windows::Foundation::IAsyncAction PathIO::AppendLinesAsync(hstring_view absolutePath, iterable<hstring> lines, Windows::Storage::Streams::UnicodeEncoding encoding)
{
    return get_activation_factory<PathIO, IPathIOStatics>().AppendLinesAsync(absolutePath, lines, encoding);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> PathIO::ReadBufferAsync(hstring_view absolutePath)
{
    return get_activation_factory<PathIO, IPathIOStatics>().ReadBufferAsync(absolutePath);
}

inline Windows::Foundation::IAsyncAction PathIO::WriteBufferAsync(hstring_view absolutePath, const Windows::Storage::Streams::IBuffer & buffer)
{
    return get_activation_factory<PathIO, IPathIOStatics>().WriteBufferAsync(absolutePath, buffer);
}

inline Windows::Foundation::IAsyncAction PathIO::WriteBytesAsync(hstring_view absolutePath, array_view<const uint8_t> buffer)
{
    return get_activation_factory<PathIO, IPathIOStatics>().WriteBytesAsync(absolutePath, buffer);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> StorageFile::GetFileFromPathAsync(hstring_view path)
{
    return get_activation_factory<StorageFile, IStorageFileStatics>().GetFileFromPathAsync(path);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> StorageFile::GetFileFromApplicationUriAsync(const Windows::Foundation::Uri & uri)
{
    return get_activation_factory<StorageFile, IStorageFileStatics>().GetFileFromApplicationUriAsync(uri);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> StorageFile::CreateStreamedFileAsync(hstring_view displayNameWithExtension, const Windows::Storage::StreamedFileDataRequestedHandler & dataRequested, const Windows::Storage::Streams::IRandomAccessStreamReference & thumbnail)
{
    return get_activation_factory<StorageFile, IStorageFileStatics>().CreateStreamedFileAsync(displayNameWithExtension, dataRequested, thumbnail);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> StorageFile::ReplaceWithStreamedFileAsync(const Windows::Storage::IStorageFile & fileToReplace, const Windows::Storage::StreamedFileDataRequestedHandler & dataRequested, const Windows::Storage::Streams::IRandomAccessStreamReference & thumbnail)
{
    return get_activation_factory<StorageFile, IStorageFileStatics>().ReplaceWithStreamedFileAsync(fileToReplace, dataRequested, thumbnail);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> StorageFile::CreateStreamedFileFromUriAsync(hstring_view displayNameWithExtension, const Windows::Foundation::Uri & uri, const Windows::Storage::Streams::IRandomAccessStreamReference & thumbnail)
{
    return get_activation_factory<StorageFile, IStorageFileStatics>().CreateStreamedFileFromUriAsync(displayNameWithExtension, uri, thumbnail);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> StorageFile::ReplaceWithStreamedFileFromUriAsync(const Windows::Storage::IStorageFile & fileToReplace, const Windows::Foundation::Uri & uri, const Windows::Storage::Streams::IRandomAccessStreamReference & thumbnail)
{
    return get_activation_factory<StorageFile, IStorageFileStatics>().ReplaceWithStreamedFileFromUriAsync(fileToReplace, uri, thumbnail);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> StorageFolder::GetFolderFromPathAsync(hstring_view path)
{
    return get_activation_factory<StorageFolder, IStorageFolderStatics>().GetFolderFromPathAsync(path);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageLibrary> StorageLibrary::GetLibraryAsync(Windows::Storage::KnownLibraryId libraryId)
{
    return get_activation_factory<StorageLibrary, IStorageLibraryStatics>().GetLibraryAsync(libraryId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageLibrary> StorageLibrary::GetLibraryForUserAsync(const Windows::System::User & user, Windows::Storage::KnownLibraryId libraryId)
{
    return get_activation_factory<StorageLibrary, IStorageLibraryStatics2>().GetLibraryForUserAsync(user, libraryId);
}

inline hstring SystemProperties::Author()
{
    return get_activation_factory<SystemProperties, ISystemProperties>().Author();
}

inline hstring SystemProperties::Comment()
{
    return get_activation_factory<SystemProperties, ISystemProperties>().Comment();
}

inline hstring SystemProperties::ItemNameDisplay()
{
    return get_activation_factory<SystemProperties, ISystemProperties>().ItemNameDisplay();
}

inline hstring SystemProperties::Keywords()
{
    return get_activation_factory<SystemProperties, ISystemProperties>().Keywords();
}

inline hstring SystemProperties::Rating()
{
    return get_activation_factory<SystemProperties, ISystemProperties>().Rating();
}

inline hstring SystemProperties::Title()
{
    return get_activation_factory<SystemProperties, ISystemProperties>().Title();
}

inline Windows::Storage::SystemAudioProperties SystemProperties::Audio()
{
    return get_activation_factory<SystemProperties, ISystemProperties>().Audio();
}

inline Windows::Storage::SystemGPSProperties SystemProperties::GPS()
{
    return get_activation_factory<SystemProperties, ISystemProperties>().GPS();
}

inline Windows::Storage::SystemMediaProperties SystemProperties::Media()
{
    return get_activation_factory<SystemProperties, ISystemProperties>().Media();
}

inline Windows::Storage::SystemMusicProperties SystemProperties::Music()
{
    return get_activation_factory<SystemProperties, ISystemProperties>().Music();
}

inline Windows::Storage::SystemPhotoProperties SystemProperties::Photo()
{
    return get_activation_factory<SystemProperties, ISystemProperties>().Photo();
}

inline Windows::Storage::SystemVideoProperties SystemProperties::Video()
{
    return get_activation_factory<SystemProperties, ISystemProperties>().Video();
}

inline Windows::Storage::SystemImageProperties SystemProperties::Image()
{
    return get_activation_factory<SystemProperties, ISystemProperties>().Image();
}

}

}
#pragma warning(pop)
