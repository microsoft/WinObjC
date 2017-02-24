// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Security.Credentials.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.UI.Notifications.3.h"
#include "internal/Windows.Web.3.h"
#include "internal/Windows.ApplicationModel.Background.3.h"
#include "internal/Windows.Networking.BackgroundTransfer.3.h"
#include "Windows.Networking.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloader> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloader>
{
    HRESULT __stdcall abi_CreateDownload(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::Storage::IStorageFile> resultFile, impl::abi_arg_out<Windows::Networking::BackgroundTransfer::IDownloadOperation> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateDownload(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&resultFile)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDownloadFromFile(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::Storage::IStorageFile> resultFile, impl::abi_arg_in<Windows::Storage::IStorageFile> requestBodyFile, impl::abi_arg_out<Windows::Networking::BackgroundTransfer::IDownloadOperation> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateDownload(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&resultFile), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&requestBodyFile)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDownloadAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::Storage::IStorageFile> resultFile, impl::abi_arg_in<Windows::Storage::Streams::IInputStream> requestBodyStream, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::DownloadOperation>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateDownloadAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&resultFile), *reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&requestBodyStream)));
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloader2> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloader2>
{
    HRESULT __stdcall get_TransferGroup(impl::abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransferGroup());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransferGroup(impl::abi_arg_in<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransferGroup(*reinterpret_cast<const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuccessToastNotification(impl::abi_arg_out<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SuccessToastNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuccessToastNotification(impl::abi_arg_in<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuccessToastNotification(*reinterpret_cast<const Windows::UI::Notifications::ToastNotification *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FailureToastNotification(impl::abi_arg_out<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FailureToastNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FailureToastNotification(impl::abi_arg_in<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FailureToastNotification(*reinterpret_cast<const Windows::UI::Notifications::ToastNotification *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuccessTileNotification(impl::abi_arg_out<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SuccessTileNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuccessTileNotification(impl::abi_arg_in<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuccessTileNotification(*reinterpret_cast<const Windows::UI::Notifications::TileNotification *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FailureTileNotification(impl::abi_arg_out<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FailureTileNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FailureTileNotification(impl::abi_arg_in<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FailureTileNotification(*reinterpret_cast<const Windows::UI::Notifications::TileNotification *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloader3> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloader3>
{
    HRESULT __stdcall get_CompletionGroup(impl::abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CompletionGroup());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloaderFactory> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloaderFactory>
{
    HRESULT __stdcall abi_CreateWithCompletionGroup(impl::abi_arg_in<Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup> completionGroup, impl::abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundDownloader> backgroundDownloader) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *backgroundDownloader = detach_abi(this->shim().CreateWithCompletionGroup(*reinterpret_cast<const Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup *>(&completionGroup)));
            return S_OK;
        }
        catch (...)
        {
            *backgroundDownloader = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods>
{
    HRESULT __stdcall abi_GetCurrentDownloadsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetCurrentDownloadsAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentDownloadsForGroupAsync(impl::abi_arg_in<hstring> group, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetCurrentDownloadsAsync(*reinterpret_cast<const hstring *>(&group)));
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods2> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods2>
{
    HRESULT __stdcall abi_GetCurrentDownloadsForTransferGroupAsync(impl::abi_arg_in<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> group, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetCurrentDownloadsForTransferGroupAsync(*reinterpret_cast<const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup *>(&group)));
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloaderUserConsent> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloaderUserConsent>
{
    HRESULT __stdcall abi_RequestUnconstrainedDownloadsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::DownloadOperation>> operations, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestUnconstrainedDownloadsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::DownloadOperation> *>(&operations)));
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferBase> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>
{
    HRESULT __stdcall abi_SetRequestHeader(impl::abi_arg_in<hstring> headerName, impl::abi_arg_in<hstring> headerValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetRequestHeader(*reinterpret_cast<const hstring *>(&headerName), *reinterpret_cast<const hstring *>(&headerValue));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServerCredential(impl::abi_arg_out<Windows::Security::Credentials::IPasswordCredential> credential) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *credential = detach_abi(this->shim().ServerCredential());
            return S_OK;
        }
        catch (...)
        {
            *credential = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ServerCredential(impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> credential) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServerCredential(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&credential));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProxyCredential(impl::abi_arg_out<Windows::Security::Credentials::IPasswordCredential> credential) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *credential = detach_abi(this->shim().ProxyCredential());
            return S_OK;
        }
        catch (...)
        {
            *credential = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProxyCredential(impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> credential) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProxyCredential(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&credential));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Method(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Method());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Method(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Method(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Group(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Group());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Group(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Group(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CostPolicy(Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CostPolicy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CostPolicy(Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CostPolicy(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup>
{
    HRESULT __stdcall get_Trigger(impl::abi_arg_out<Windows::ApplicationModel::Background::IBackgroundTrigger> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Trigger());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEnabled());
            return S_OK;
        }
        catch (...)
        {
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
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails>
{
    HRESULT __stdcall get_Downloads(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Downloads());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Uploads(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uploads());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart>
{
    HRESULT __stdcall abi_SetHeader(impl::abi_arg_in<hstring> headerName, impl::abi_arg_in<hstring> headerValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetHeader(*reinterpret_cast<const hstring *>(&headerName), *reinterpret_cast<const hstring *>(&headerValue));
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

    HRESULT __stdcall abi_SetFile(impl::abi_arg_in<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFile(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPartFactory> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPartFactory>
{
    HRESULT __stdcall abi_CreateWithName(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithName(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithNameAndFileName(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> fileName, impl::abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithNameAndFileName(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&fileName)));
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferErrorStaticMethods> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferErrorStaticMethods>
{
    HRESULT __stdcall abi_GetStatus(int32_t hresult, Windows::Web::WebErrorStatus * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().GetStatus(hresult));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup>
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

    HRESULT __stdcall get_TransferBehavior(Windows::Networking::BackgroundTransfer::BackgroundTransferBehavior * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransferBehavior());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransferBehavior(Windows::Networking::BackgroundTransfer::BackgroundTransferBehavior value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransferBehavior(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferGroupStatics> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferGroupStatics>
{
    HRESULT __stdcall abi_CreateGroup(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateGroup(*reinterpret_cast<const hstring *>(&name)));
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>
{
    HRESULT __stdcall get_Guid(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Guid());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequestedUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestedUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Method(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Method());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Group(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Group());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CostPolicy(Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CostPolicy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CostPolicy(Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CostPolicy(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetResultStreamAt(uint64_t position, impl::abi_arg_out<Windows::Storage::Streams::IInputStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetResultStreamAt(position));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetResponseInformation(impl::abi_arg_out<Windows::Networking::BackgroundTransfer::IResponseInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetResponseInformation());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority>
{
    HRESULT __stdcall get_Priority(Windows::Networking::BackgroundTransfer::BackgroundTransferPriority * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Priority());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Priority(Windows::Networking::BackgroundTransfer::BackgroundTransferPriority value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Priority(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundUploader> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundUploader>
{
    HRESULT __stdcall abi_CreateUpload(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::Storage::IStorageFile> sourceFile, impl::abi_arg_out<Windows::Networking::BackgroundTransfer::IUploadOperation> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateUpload(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&sourceFile)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateUploadFromStreamAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::Storage::Streams::IInputStream> sourceStream, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateUploadFromStreamAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&sourceStream)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateUploadWithFormDataAndAutoBoundaryAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart>> parts, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateUploadAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart> *>(&parts)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateUploadWithSubTypeAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart>> parts, impl::abi_arg_in<hstring> subType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateUploadAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart> *>(&parts), *reinterpret_cast<const hstring *>(&subType)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateUploadWithSubTypeAndBoundaryAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart>> parts, impl::abi_arg_in<hstring> subType, impl::abi_arg_in<hstring> boundary, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateUploadAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart> *>(&parts), *reinterpret_cast<const hstring *>(&subType), *reinterpret_cast<const hstring *>(&boundary)));
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundUploader2> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundUploader2>
{
    HRESULT __stdcall get_TransferGroup(impl::abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransferGroup());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransferGroup(impl::abi_arg_in<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransferGroup(*reinterpret_cast<const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuccessToastNotification(impl::abi_arg_out<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SuccessToastNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuccessToastNotification(impl::abi_arg_in<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuccessToastNotification(*reinterpret_cast<const Windows::UI::Notifications::ToastNotification *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FailureToastNotification(impl::abi_arg_out<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FailureToastNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FailureToastNotification(impl::abi_arg_in<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FailureToastNotification(*reinterpret_cast<const Windows::UI::Notifications::ToastNotification *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuccessTileNotification(impl::abi_arg_out<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SuccessTileNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuccessTileNotification(impl::abi_arg_in<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuccessTileNotification(*reinterpret_cast<const Windows::UI::Notifications::TileNotification *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FailureTileNotification(impl::abi_arg_out<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FailureTileNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FailureTileNotification(impl::abi_arg_in<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FailureTileNotification(*reinterpret_cast<const Windows::UI::Notifications::TileNotification *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundUploader3> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundUploader3>
{
    HRESULT __stdcall get_CompletionGroup(impl::abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CompletionGroup());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundUploaderFactory> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundUploaderFactory>
{
    HRESULT __stdcall abi_CreateWithCompletionGroup(impl::abi_arg_in<Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup> completionGroup, impl::abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundUploader> backgroundUploader) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *backgroundUploader = detach_abi(this->shim().CreateWithCompletionGroup(*reinterpret_cast<const Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup *>(&completionGroup)));
            return S_OK;
        }
        catch (...)
        {
            *backgroundUploader = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods>
{
    HRESULT __stdcall abi_GetCurrentUploadsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetCurrentUploadsAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentUploadsForGroupAsync(impl::abi_arg_in<hstring> group, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetCurrentUploadsAsync(*reinterpret_cast<const hstring *>(&group)));
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods2> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods2>
{
    HRESULT __stdcall abi_GetCurrentUploadsForTransferGroupAsync(impl::abi_arg_in<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> group, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetCurrentUploadsForTransferGroupAsync(*reinterpret_cast<const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup *>(&group)));
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundUploaderUserConsent> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundUploaderUserConsent>
{
    HRESULT __stdcall abi_RequestUnconstrainedUploadsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::UploadOperation>> operations, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestUnconstrainedUploadsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::UploadOperation> *>(&operations)));
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
struct produce<D, Windows::Networking::BackgroundTransfer::IContentPrefetcher> : produce_base<D, Windows::Networking::BackgroundTransfer::IContentPrefetcher>
{
    HRESULT __stdcall get_ContentUris(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Foundation::Uri>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentUris());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IndirectContentUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IndirectContentUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IndirectContentUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IndirectContentUri());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IContentPrefetcherTime> : produce_base<D, Windows::Networking::BackgroundTransfer::IContentPrefetcherTime>
{
    HRESULT __stdcall get_LastSuccessfulPrefetchTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastSuccessfulPrefetchTime());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IDownloadOperation> : produce_base<D, Windows::Networking::BackgroundTransfer::IDownloadOperation>
{
    HRESULT __stdcall get_ResultFile(impl::abi_arg_out<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResultFile());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Progress(impl::abi_arg_out<Windows::Networking::BackgroundTransfer::BackgroundDownloadProgress> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Progress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::DownloadOperation, Windows::Networking::BackgroundTransfer::DownloadOperation>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StartAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AttachAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::DownloadOperation, Windows::Networking::BackgroundTransfer::DownloadOperation>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().AttachAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Pause() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Pause();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Resume() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resume();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IDownloadOperation2> : produce_base<D, Windows::Networking::BackgroundTransfer::IDownloadOperation2>
{
    HRESULT __stdcall get_TransferGroup(impl::abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransferGroup());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IResponseInformation> : produce_base<D, Windows::Networking::BackgroundTransfer::IResponseInformation>
{
    HRESULT __stdcall get_IsResumable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsResumable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActualUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActualUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StatusCode(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StatusCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Headers(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Headers());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult> : produce_base<D, Windows::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult>
{
    HRESULT __stdcall get_IsUnconstrained(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsUnconstrained());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IUploadOperation> : produce_base<D, Windows::Networking::BackgroundTransfer::IUploadOperation>
{
    HRESULT __stdcall get_SourceFile(impl::abi_arg_out<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceFile());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Progress(impl::abi_arg_out<Windows::Networking::BackgroundTransfer::BackgroundUploadProgress> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Progress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::UploadOperation, Windows::Networking::BackgroundTransfer::UploadOperation>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StartAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AttachAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::UploadOperation, Windows::Networking::BackgroundTransfer::UploadOperation>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().AttachAsync());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IUploadOperation2> : produce_base<D, Windows::Networking::BackgroundTransfer::IUploadOperation2>
{
    HRESULT __stdcall get_TransferGroup(impl::abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransferGroup());
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

namespace Windows::Networking::BackgroundTransfer {

template <typename D> void impl_IBackgroundTransferBase<D>::SetRequestHeader(hstring_view headerName, hstring_view headerValue) const
{
    check_hresult(WINRT_SHIM(IBackgroundTransferBase)->abi_SetRequestHeader(get_abi(headerName), get_abi(headerValue)));
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_IBackgroundTransferBase<D>::ServerCredential() const
{
    Windows::Security::Credentials::PasswordCredential credential { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundTransferBase)->get_ServerCredential(put_abi(credential)));
    return credential;
}

template <typename D> void impl_IBackgroundTransferBase<D>::ServerCredential(const Windows::Security::Credentials::PasswordCredential & credential) const
{
    check_hresult(WINRT_SHIM(IBackgroundTransferBase)->put_ServerCredential(get_abi(credential)));
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_IBackgroundTransferBase<D>::ProxyCredential() const
{
    Windows::Security::Credentials::PasswordCredential credential { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundTransferBase)->get_ProxyCredential(put_abi(credential)));
    return credential;
}

template <typename D> void impl_IBackgroundTransferBase<D>::ProxyCredential(const Windows::Security::Credentials::PasswordCredential & credential) const
{
    check_hresult(WINRT_SHIM(IBackgroundTransferBase)->put_ProxyCredential(get_abi(credential)));
}

template <typename D> hstring impl_IBackgroundTransferBase<D>::Method() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBackgroundTransferBase)->get_Method(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundTransferBase<D>::Method(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IBackgroundTransferBase)->put_Method(get_abi(value)));
}

template <typename D> hstring impl_IBackgroundTransferBase<D>::Group() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBackgroundTransferBase)->get_Group(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundTransferBase<D>::Group(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IBackgroundTransferBase)->put_Group(get_abi(value)));
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy impl_IBackgroundTransferBase<D>::CostPolicy() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy value {};
    check_hresult(WINRT_SHIM(IBackgroundTransferBase)->get_CostPolicy(&value));
    return value;
}

template <typename D> void impl_IBackgroundTransferBase<D>::CostPolicy(Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy value) const
{
    check_hresult(WINRT_SHIM(IBackgroundTransferBase)->put_CostPolicy(value));
}

template <typename D> bool impl_IUnconstrainedTransferRequestResult<D>::IsUnconstrained() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUnconstrainedTransferRequestResult)->get_IsUnconstrained(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult> impl_IBackgroundDownloaderUserConsent<D>::RequestUnconstrainedDownloadsAsync(iterable<Windows::Networking::BackgroundTransfer::DownloadOperation> operations) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult> operation;
    check_hresult(WINRT_SHIM(IBackgroundDownloaderUserConsent)->abi_RequestUnconstrainedDownloadsAsync(get_abi(operations), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult> impl_IBackgroundUploaderUserConsent<D>::RequestUnconstrainedUploadsAsync(iterable<Windows::Networking::BackgroundTransfer::UploadOperation> operations) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult> operation;
    check_hresult(WINRT_SHIM(IBackgroundUploaderUserConsent)->abi_RequestUnconstrainedUploadsAsync(get_abi(operations), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Networking::BackgroundTransfer::DownloadOperation impl_IBackgroundDownloader<D>::CreateDownload(const Windows::Foundation::Uri & uri, const Windows::Storage::IStorageFile & resultFile) const
{
    Windows::Networking::BackgroundTransfer::DownloadOperation operation { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundDownloader)->abi_CreateDownload(get_abi(uri), get_abi(resultFile), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Networking::BackgroundTransfer::DownloadOperation impl_IBackgroundDownloader<D>::CreateDownload(const Windows::Foundation::Uri & uri, const Windows::Storage::IStorageFile & resultFile, const Windows::Storage::IStorageFile & requestBodyFile) const
{
    Windows::Networking::BackgroundTransfer::DownloadOperation operation { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundDownloader)->abi_CreateDownloadFromFile(get_abi(uri), get_abi(resultFile), get_abi(requestBodyFile), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::DownloadOperation> impl_IBackgroundDownloader<D>::CreateDownloadAsync(const Windows::Foundation::Uri & uri, const Windows::Storage::IStorageFile & resultFile, const Windows::Storage::Streams::IInputStream & requestBodyStream) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::DownloadOperation> operation;
    check_hresult(WINRT_SHIM(IBackgroundDownloader)->abi_CreateDownloadAsync(get_abi(uri), get_abi(resultFile), get_abi(requestBodyStream), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferGroup impl_IBackgroundDownloader2<D>::TransferGroup() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferGroup value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundDownloader2)->get_TransferGroup(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundDownloader2<D>::TransferGroup(const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup & value) const
{
    check_hresult(WINRT_SHIM(IBackgroundDownloader2)->put_TransferGroup(get_abi(value)));
}

template <typename D> Windows::UI::Notifications::ToastNotification impl_IBackgroundDownloader2<D>::SuccessToastNotification() const
{
    Windows::UI::Notifications::ToastNotification value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundDownloader2)->get_SuccessToastNotification(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundDownloader2<D>::SuccessToastNotification(const Windows::UI::Notifications::ToastNotification & value) const
{
    check_hresult(WINRT_SHIM(IBackgroundDownloader2)->put_SuccessToastNotification(get_abi(value)));
}

template <typename D> Windows::UI::Notifications::ToastNotification impl_IBackgroundDownloader2<D>::FailureToastNotification() const
{
    Windows::UI::Notifications::ToastNotification value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundDownloader2)->get_FailureToastNotification(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundDownloader2<D>::FailureToastNotification(const Windows::UI::Notifications::ToastNotification & value) const
{
    check_hresult(WINRT_SHIM(IBackgroundDownloader2)->put_FailureToastNotification(get_abi(value)));
}

template <typename D> Windows::UI::Notifications::TileNotification impl_IBackgroundDownloader2<D>::SuccessTileNotification() const
{
    Windows::UI::Notifications::TileNotification value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundDownloader2)->get_SuccessTileNotification(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundDownloader2<D>::SuccessTileNotification(const Windows::UI::Notifications::TileNotification & value) const
{
    check_hresult(WINRT_SHIM(IBackgroundDownloader2)->put_SuccessTileNotification(get_abi(value)));
}

template <typename D> Windows::UI::Notifications::TileNotification impl_IBackgroundDownloader2<D>::FailureTileNotification() const
{
    Windows::UI::Notifications::TileNotification value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundDownloader2)->get_FailureTileNotification(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundDownloader2<D>::FailureTileNotification(const Windows::UI::Notifications::TileNotification & value) const
{
    check_hresult(WINRT_SHIM(IBackgroundDownloader2)->put_FailureTileNotification(get_abi(value)));
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup impl_IBackgroundDownloader3<D>::CompletionGroup() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundDownloader3)->get_CompletionGroup(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::UploadOperation impl_IBackgroundUploader<D>::CreateUpload(const Windows::Foundation::Uri & uri, const Windows::Storage::IStorageFile & sourceFile) const
{
    Windows::Networking::BackgroundTransfer::UploadOperation operation { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundUploader)->abi_CreateUpload(get_abi(uri), get_abi(sourceFile), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation> impl_IBackgroundUploader<D>::CreateUploadFromStreamAsync(const Windows::Foundation::Uri & uri, const Windows::Storage::Streams::IInputStream & sourceStream) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation> operation;
    check_hresult(WINRT_SHIM(IBackgroundUploader)->abi_CreateUploadFromStreamAsync(get_abi(uri), get_abi(sourceStream), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation> impl_IBackgroundUploader<D>::CreateUploadAsync(const Windows::Foundation::Uri & uri, iterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart> parts) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation> operation;
    check_hresult(WINRT_SHIM(IBackgroundUploader)->abi_CreateUploadWithFormDataAndAutoBoundaryAsync(get_abi(uri), get_abi(parts), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation> impl_IBackgroundUploader<D>::CreateUploadAsync(const Windows::Foundation::Uri & uri, iterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart> parts, hstring_view subType) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation> operation;
    check_hresult(WINRT_SHIM(IBackgroundUploader)->abi_CreateUploadWithSubTypeAsync(get_abi(uri), get_abi(parts), get_abi(subType), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation> impl_IBackgroundUploader<D>::CreateUploadAsync(const Windows::Foundation::Uri & uri, iterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart> parts, hstring_view subType, hstring_view boundary) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation> operation;
    check_hresult(WINRT_SHIM(IBackgroundUploader)->abi_CreateUploadWithSubTypeAndBoundaryAsync(get_abi(uri), get_abi(parts), get_abi(subType), get_abi(boundary), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferGroup impl_IBackgroundUploader2<D>::TransferGroup() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferGroup value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundUploader2)->get_TransferGroup(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundUploader2<D>::TransferGroup(const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup & value) const
{
    check_hresult(WINRT_SHIM(IBackgroundUploader2)->put_TransferGroup(get_abi(value)));
}

template <typename D> Windows::UI::Notifications::ToastNotification impl_IBackgroundUploader2<D>::SuccessToastNotification() const
{
    Windows::UI::Notifications::ToastNotification value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundUploader2)->get_SuccessToastNotification(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundUploader2<D>::SuccessToastNotification(const Windows::UI::Notifications::ToastNotification & value) const
{
    check_hresult(WINRT_SHIM(IBackgroundUploader2)->put_SuccessToastNotification(get_abi(value)));
}

template <typename D> Windows::UI::Notifications::ToastNotification impl_IBackgroundUploader2<D>::FailureToastNotification() const
{
    Windows::UI::Notifications::ToastNotification value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundUploader2)->get_FailureToastNotification(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundUploader2<D>::FailureToastNotification(const Windows::UI::Notifications::ToastNotification & value) const
{
    check_hresult(WINRT_SHIM(IBackgroundUploader2)->put_FailureToastNotification(get_abi(value)));
}

template <typename D> Windows::UI::Notifications::TileNotification impl_IBackgroundUploader2<D>::SuccessTileNotification() const
{
    Windows::UI::Notifications::TileNotification value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundUploader2)->get_SuccessTileNotification(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundUploader2<D>::SuccessTileNotification(const Windows::UI::Notifications::TileNotification & value) const
{
    check_hresult(WINRT_SHIM(IBackgroundUploader2)->put_SuccessTileNotification(get_abi(value)));
}

template <typename D> Windows::UI::Notifications::TileNotification impl_IBackgroundUploader2<D>::FailureTileNotification() const
{
    Windows::UI::Notifications::TileNotification value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundUploader2)->get_FailureTileNotification(put_abi(value)));
    return value;
}

template <typename D> void impl_IBackgroundUploader2<D>::FailureTileNotification(const Windows::UI::Notifications::TileNotification & value) const
{
    check_hresult(WINRT_SHIM(IBackgroundUploader2)->put_FailureTileNotification(get_abi(value)));
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup impl_IBackgroundUploader3<D>::CompletionGroup() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundUploader3)->get_CompletionGroup(put_abi(value)));
    return value;
}

template <typename D> GUID impl_IBackgroundTransferOperation<D>::Guid() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBackgroundTransferOperation)->get_Guid(&value));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IBackgroundTransferOperation<D>::RequestedUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundTransferOperation)->get_RequestedUri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IBackgroundTransferOperation<D>::Method() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBackgroundTransferOperation)->get_Method(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IBackgroundTransferOperation<D>::Group() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBackgroundTransferOperation)->get_Group(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy impl_IBackgroundTransferOperation<D>::CostPolicy() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy value {};
    check_hresult(WINRT_SHIM(IBackgroundTransferOperation)->get_CostPolicy(&value));
    return value;
}

template <typename D> void impl_IBackgroundTransferOperation<D>::CostPolicy(Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy value) const
{
    check_hresult(WINRT_SHIM(IBackgroundTransferOperation)->put_CostPolicy(value));
}

template <typename D> Windows::Storage::Streams::IInputStream impl_IBackgroundTransferOperation<D>::GetResultStreamAt(uint64_t position) const
{
    Windows::Storage::Streams::IInputStream value;
    check_hresult(WINRT_SHIM(IBackgroundTransferOperation)->abi_GetResultStreamAt(position, put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::ResponseInformation impl_IBackgroundTransferOperation<D>::GetResponseInformation() const
{
    Windows::Networking::BackgroundTransfer::ResponseInformation value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundTransferOperation)->abi_GetResponseInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferPriority impl_IBackgroundTransferOperationPriority<D>::Priority() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferPriority value {};
    check_hresult(WINRT_SHIM(IBackgroundTransferOperationPriority)->get_Priority(&value));
    return value;
}

template <typename D> void impl_IBackgroundTransferOperationPriority<D>::Priority(Windows::Networking::BackgroundTransfer::BackgroundTransferPriority value) const
{
    check_hresult(WINRT_SHIM(IBackgroundTransferOperationPriority)->put_Priority(value));
}

template <typename D> Windows::Storage::IStorageFile impl_IDownloadOperation<D>::ResultFile() const
{
    Windows::Storage::IStorageFile value;
    check_hresult(WINRT_SHIM(IDownloadOperation)->get_ResultFile(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundDownloadProgress impl_IDownloadOperation<D>::Progress() const
{
    Windows::Networking::BackgroundTransfer::BackgroundDownloadProgress value {};
    check_hresult(WINRT_SHIM(IDownloadOperation)->get_Progress(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::DownloadOperation, Windows::Networking::BackgroundTransfer::DownloadOperation> impl_IDownloadOperation<D>::StartAsync() const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::DownloadOperation, Windows::Networking::BackgroundTransfer::DownloadOperation> operation;
    check_hresult(WINRT_SHIM(IDownloadOperation)->abi_StartAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::DownloadOperation, Windows::Networking::BackgroundTransfer::DownloadOperation> impl_IDownloadOperation<D>::AttachAsync() const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::DownloadOperation, Windows::Networking::BackgroundTransfer::DownloadOperation> operation;
    check_hresult(WINRT_SHIM(IDownloadOperation)->abi_AttachAsync(put_abi(operation)));
    return operation;
}

template <typename D> void impl_IDownloadOperation<D>::Pause() const
{
    check_hresult(WINRT_SHIM(IDownloadOperation)->abi_Pause());
}

template <typename D> void impl_IDownloadOperation<D>::Resume() const
{
    check_hresult(WINRT_SHIM(IDownloadOperation)->abi_Resume());
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferGroup impl_IDownloadOperation2<D>::TransferGroup() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferGroup value { nullptr };
    check_hresult(WINRT_SHIM(IDownloadOperation2)->get_TransferGroup(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::IStorageFile impl_IUploadOperation<D>::SourceFile() const
{
    Windows::Storage::IStorageFile value;
    check_hresult(WINRT_SHIM(IUploadOperation)->get_SourceFile(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundUploadProgress impl_IUploadOperation<D>::Progress() const
{
    Windows::Networking::BackgroundTransfer::BackgroundUploadProgress value {};
    check_hresult(WINRT_SHIM(IUploadOperation)->get_Progress(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::UploadOperation, Windows::Networking::BackgroundTransfer::UploadOperation> impl_IUploadOperation<D>::StartAsync() const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::UploadOperation, Windows::Networking::BackgroundTransfer::UploadOperation> operation;
    check_hresult(WINRT_SHIM(IUploadOperation)->abi_StartAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::UploadOperation, Windows::Networking::BackgroundTransfer::UploadOperation> impl_IUploadOperation<D>::AttachAsync() const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::UploadOperation, Windows::Networking::BackgroundTransfer::UploadOperation> operation;
    check_hresult(WINRT_SHIM(IUploadOperation)->abi_AttachAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferGroup impl_IUploadOperation2<D>::TransferGroup() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferGroup value { nullptr };
    check_hresult(WINRT_SHIM(IUploadOperation2)->get_TransferGroup(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundDownloader impl_IBackgroundDownloaderFactory<D>::CreateWithCompletionGroup(const Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup & completionGroup) const
{
    Windows::Networking::BackgroundTransfer::BackgroundDownloader backgroundDownloader { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundDownloaderFactory)->abi_CreateWithCompletionGroup(get_abi(completionGroup), put_abi(backgroundDownloader)));
    return backgroundDownloader;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> impl_IBackgroundDownloaderStaticMethods<D>::GetCurrentDownloadsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> operation;
    check_hresult(WINRT_SHIM(IBackgroundDownloaderStaticMethods)->abi_GetCurrentDownloadsAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> impl_IBackgroundDownloaderStaticMethods<D>::GetCurrentDownloadsAsync(hstring_view group) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> operation;
    check_hresult(WINRT_SHIM(IBackgroundDownloaderStaticMethods)->abi_GetCurrentDownloadsForGroupAsync(get_abi(group), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> impl_IBackgroundDownloaderStaticMethods2<D>::GetCurrentDownloadsForTransferGroupAsync(const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup & group) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> operation;
    check_hresult(WINRT_SHIM(IBackgroundDownloaderStaticMethods2)->abi_GetCurrentDownloadsForTransferGroupAsync(get_abi(group), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundUploader impl_IBackgroundUploaderFactory<D>::CreateWithCompletionGroup(const Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup & completionGroup) const
{
    Windows::Networking::BackgroundTransfer::BackgroundUploader backgroundUploader { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundUploaderFactory)->abi_CreateWithCompletionGroup(get_abi(completionGroup), put_abi(backgroundUploader)));
    return backgroundUploader;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> impl_IBackgroundUploaderStaticMethods<D>::GetCurrentUploadsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> operation;
    check_hresult(WINRT_SHIM(IBackgroundUploaderStaticMethods)->abi_GetCurrentUploadsAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> impl_IBackgroundUploaderStaticMethods<D>::GetCurrentUploadsAsync(hstring_view group) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> operation;
    check_hresult(WINRT_SHIM(IBackgroundUploaderStaticMethods)->abi_GetCurrentUploadsForGroupAsync(get_abi(group), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> impl_IBackgroundUploaderStaticMethods2<D>::GetCurrentUploadsForTransferGroupAsync(const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup & group) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> operation;
    check_hresult(WINRT_SHIM(IBackgroundUploaderStaticMethods2)->abi_GetCurrentUploadsForTransferGroupAsync(get_abi(group), put_abi(operation)));
    return operation;
}

template <typename D> bool impl_IResponseInformation<D>::IsResumable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IResponseInformation)->get_IsResumable(&value));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IResponseInformation<D>::ActualUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IResponseInformation)->get_ActualUri(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IResponseInformation<D>::StatusCode() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IResponseInformation)->get_StatusCode(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, hstring> impl_IResponseInformation<D>::Headers() const
{
    Windows::Foundation::Collections::IMapView<hstring, hstring> value;
    check_hresult(WINRT_SHIM(IResponseInformation)->get_Headers(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::WebErrorStatus impl_IBackgroundTransferErrorStaticMethods<D>::GetStatus(int32_t hresult) const
{
    Windows::Web::WebErrorStatus status {};
    check_hresult(WINRT_SHIM(IBackgroundTransferErrorStaticMethods)->abi_GetStatus(hresult, &status));
    return status;
}

template <typename D> void impl_IBackgroundTransferContentPart<D>::SetHeader(hstring_view headerName, hstring_view headerValue) const
{
    check_hresult(WINRT_SHIM(IBackgroundTransferContentPart)->abi_SetHeader(get_abi(headerName), get_abi(headerValue)));
}

template <typename D> void impl_IBackgroundTransferContentPart<D>::SetText(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IBackgroundTransferContentPart)->abi_SetText(get_abi(value)));
}

template <typename D> void impl_IBackgroundTransferContentPart<D>::SetFile(const Windows::Storage::IStorageFile & value) const
{
    check_hresult(WINRT_SHIM(IBackgroundTransferContentPart)->abi_SetFile(get_abi(value)));
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart impl_IBackgroundTransferContentPartFactory<D>::CreateWithName(hstring_view name) const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundTransferContentPartFactory)->abi_CreateWithName(get_abi(name), put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart impl_IBackgroundTransferContentPartFactory<D>::CreateWithNameAndFileName(hstring_view name, hstring_view fileName) const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundTransferContentPartFactory)->abi_CreateWithNameAndFileName(get_abi(name), get_abi(fileName), put_abi(value)));
    return value;
}

template <typename D> hstring impl_IBackgroundTransferGroup<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBackgroundTransferGroup)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferBehavior impl_IBackgroundTransferGroup<D>::TransferBehavior() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferBehavior value {};
    check_hresult(WINRT_SHIM(IBackgroundTransferGroup)->get_TransferBehavior(&value));
    return value;
}

template <typename D> void impl_IBackgroundTransferGroup<D>::TransferBehavior(Windows::Networking::BackgroundTransfer::BackgroundTransferBehavior value) const
{
    check_hresult(WINRT_SHIM(IBackgroundTransferGroup)->put_TransferBehavior(value));
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferGroup impl_IBackgroundTransferGroupStatics<D>::CreateGroup(hstring_view name) const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferGroup value { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundTransferGroupStatics)->abi_CreateGroup(get_abi(name), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IContentPrefetcherTime<D>::LastSuccessfulPrefetchTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IContentPrefetcherTime)->get_LastSuccessfulPrefetchTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> impl_IContentPrefetcher<D>::ContentUris() const
{
    Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> value;
    check_hresult(WINRT_SHIM(IContentPrefetcher)->get_ContentUris(put_abi(value)));
    return value;
}

template <typename D> void impl_IContentPrefetcher<D>::IndirectContentUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IContentPrefetcher)->put_IndirectContentUri(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_IContentPrefetcher<D>::IndirectContentUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IContentPrefetcher)->get_IndirectContentUri(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Background::IBackgroundTrigger impl_IBackgroundTransferCompletionGroup<D>::Trigger() const
{
    Windows::ApplicationModel::Background::IBackgroundTrigger value;
    check_hresult(WINRT_SHIM(IBackgroundTransferCompletionGroup)->get_Trigger(put_abi(value)));
    return value;
}

template <typename D> bool impl_IBackgroundTransferCompletionGroup<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBackgroundTransferCompletionGroup)->get_IsEnabled(&value));
    return value;
}

template <typename D> void impl_IBackgroundTransferCompletionGroup<D>::Enable() const
{
    check_hresult(WINRT_SHIM(IBackgroundTransferCompletionGroup)->abi_Enable());
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation> impl_IBackgroundTransferCompletionGroupTriggerDetails<D>::Downloads() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation> value;
    check_hresult(WINRT_SHIM(IBackgroundTransferCompletionGroupTriggerDetails)->get_Downloads(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation> impl_IBackgroundTransferCompletionGroupTriggerDetails<D>::Uploads() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation> value;
    check_hresult(WINRT_SHIM(IBackgroundTransferCompletionGroupTriggerDetails)->get_Uploads(put_abi(value)));
    return value;
}

inline BackgroundDownloader::BackgroundDownloader() :
    BackgroundDownloader(activate_instance<BackgroundDownloader>())
{}

inline BackgroundDownloader::BackgroundDownloader(const Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup & completionGroup) :
    BackgroundDownloader(get_activation_factory<BackgroundDownloader, IBackgroundDownloaderFactory>().CreateWithCompletionGroup(completionGroup))
{}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> BackgroundDownloader::GetCurrentDownloadsAsync()
{
    return get_activation_factory<BackgroundDownloader, IBackgroundDownloaderStaticMethods>().GetCurrentDownloadsAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> BackgroundDownloader::GetCurrentDownloadsAsync(hstring_view group)
{
    return get_activation_factory<BackgroundDownloader, IBackgroundDownloaderStaticMethods>().GetCurrentDownloadsAsync(group);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> BackgroundDownloader::GetCurrentDownloadsForTransferGroupAsync(const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup & group)
{
    return get_activation_factory<BackgroundDownloader, IBackgroundDownloaderStaticMethods2>().GetCurrentDownloadsForTransferGroupAsync(group);
}

inline Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult> BackgroundDownloader::RequestUnconstrainedDownloadsAsync(iterable<Windows::Networking::BackgroundTransfer::DownloadOperation> operations)
{
    return get_activation_factory<BackgroundDownloader, IBackgroundDownloaderUserConsent>().RequestUnconstrainedDownloadsAsync(operations);
}

inline BackgroundTransferCompletionGroup::BackgroundTransferCompletionGroup() :
    BackgroundTransferCompletionGroup(activate_instance<BackgroundTransferCompletionGroup>())
{}

inline BackgroundTransferContentPart::BackgroundTransferContentPart() :
    BackgroundTransferContentPart(activate_instance<BackgroundTransferContentPart>())
{}

inline BackgroundTransferContentPart::BackgroundTransferContentPart(hstring_view name) :
    BackgroundTransferContentPart(get_activation_factory<BackgroundTransferContentPart, IBackgroundTransferContentPartFactory>().CreateWithName(name))
{}

inline BackgroundTransferContentPart::BackgroundTransferContentPart(hstring_view name, hstring_view fileName) :
    BackgroundTransferContentPart(get_activation_factory<BackgroundTransferContentPart, IBackgroundTransferContentPartFactory>().CreateWithNameAndFileName(name, fileName))
{}

inline Windows::Web::WebErrorStatus BackgroundTransferError::GetStatus(int32_t hresult)
{
    return get_activation_factory<BackgroundTransferError, IBackgroundTransferErrorStaticMethods>().GetStatus(hresult);
}

inline Windows::Networking::BackgroundTransfer::BackgroundTransferGroup BackgroundTransferGroup::CreateGroup(hstring_view name)
{
    return get_activation_factory<BackgroundTransferGroup, IBackgroundTransferGroupStatics>().CreateGroup(name);
}

inline BackgroundUploader::BackgroundUploader() :
    BackgroundUploader(activate_instance<BackgroundUploader>())
{}

inline BackgroundUploader::BackgroundUploader(const Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup & completionGroup) :
    BackgroundUploader(get_activation_factory<BackgroundUploader, IBackgroundUploaderFactory>().CreateWithCompletionGroup(completionGroup))
{}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> BackgroundUploader::GetCurrentUploadsAsync()
{
    return get_activation_factory<BackgroundUploader, IBackgroundUploaderStaticMethods>().GetCurrentUploadsAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> BackgroundUploader::GetCurrentUploadsAsync(hstring_view group)
{
    return get_activation_factory<BackgroundUploader, IBackgroundUploaderStaticMethods>().GetCurrentUploadsAsync(group);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> BackgroundUploader::GetCurrentUploadsForTransferGroupAsync(const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup & group)
{
    return get_activation_factory<BackgroundUploader, IBackgroundUploaderStaticMethods2>().GetCurrentUploadsForTransferGroupAsync(group);
}

inline Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult> BackgroundUploader::RequestUnconstrainedUploadsAsync(iterable<Windows::Networking::BackgroundTransfer::UploadOperation> operations)
{
    return get_activation_factory<BackgroundUploader, IBackgroundUploaderUserConsent>().RequestUnconstrainedUploadsAsync(operations);
}

inline Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> ContentPrefetcher::ContentUris()
{
    return get_activation_factory<ContentPrefetcher, IContentPrefetcher>().ContentUris();
}

inline void ContentPrefetcher::IndirectContentUri(const Windows::Foundation::Uri & value)
{
    get_activation_factory<ContentPrefetcher, IContentPrefetcher>().IndirectContentUri(value);
}

inline Windows::Foundation::Uri ContentPrefetcher::IndirectContentUri()
{
    return get_activation_factory<ContentPrefetcher, IContentPrefetcher>().IndirectContentUri();
}

inline Windows::Foundation::IReference<Windows::Foundation::DateTime> ContentPrefetcher::LastSuccessfulPrefetchTime()
{
    return get_activation_factory<ContentPrefetcher, IContentPrefetcherTime>().LastSuccessfulPrefetchTime();
}

}

}
#pragma warning(pop)
