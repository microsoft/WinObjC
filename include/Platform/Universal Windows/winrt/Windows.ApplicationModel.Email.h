// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.ApplicationModel.Appointments.3.h"
#include "internal/Windows.ApplicationModel.Email.3.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailAttachment> : produce_base<D, Windows::ApplicationModel::Email::IEmailAttachment>
{
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

    HRESULT __stdcall put_FileName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FileName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Data(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
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

    HRESULT __stdcall put_Data(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Data(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailAttachment2> : produce_base<D, Windows::ApplicationModel::Email::IEmailAttachment2>
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

    HRESULT __stdcall put_ContentId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentLocation(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentLocation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentLocation(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentLocation(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DownloadState(Windows::ApplicationModel::Email::EmailAttachmentDownloadState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DownloadState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DownloadState(Windows::ApplicationModel::Email::EmailAttachmentDownloadState value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DownloadState(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EstimatedDownloadSizeInBytes(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EstimatedDownloadSizeInBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EstimatedDownloadSizeInBytes(uint64_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EstimatedDownloadSizeInBytes(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsFromBaseMessage(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsFromBaseMessage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsInline(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsInline());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsInline(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsInline(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MimeType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MimeType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MimeType(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MimeType(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailAttachmentFactory> : produce_base<D, Windows::ApplicationModel::Email::IEmailAttachmentFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> fileName, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> data, impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailAttachment> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&fileName), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&data)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailAttachmentFactory2> : produce_base<D, Windows::ApplicationModel::Email::IEmailAttachmentFactory2>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> fileName, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> data, impl::abi_arg_in<hstring> mimeType, impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailAttachment> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&fileName), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&data), *reinterpret_cast<const hstring *>(&mimeType)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailConversation> : produce_base<D, Windows::ApplicationModel::Email::IEmailConversation>
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

    HRESULT __stdcall get_MailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FlagState(Windows::ApplicationModel::Email::EmailFlagState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FlagState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasAttachment(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasAttachment());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Importance(Windows::ApplicationModel::Email::EmailImportance * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Importance());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastEmailResponseKind(Windows::ApplicationModel::Email::EmailMessageResponseKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastEmailResponseKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MessageCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MostRecentMessageId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MostRecentMessageId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MostRecentMessageTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MostRecentMessageTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Preview(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Preview());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LatestSender(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailRecipient> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LatestSender());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Subject(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Subject());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UnreadMessageCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnreadMessageCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindMessagesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindMessagesAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindMessagesWithCountAsync(uint32_t count, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindMessagesAsync(count));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailConversationBatch> : produce_base<D, Windows::ApplicationModel::Email::IEmailConversationBatch>
{
    HRESULT __stdcall get_Conversations(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailConversation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Conversations());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::ApplicationModel::Email::EmailBatchStatus * value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailConversationReader> : produce_base<D, Windows::ApplicationModel::Email::IEmailConversationReader>
{
    HRESULT __stdcall abi_ReadBatchAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailConversationBatch>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReadBatchAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailFolder> : produce_base<D, Windows::ApplicationModel::Email::IEmailFolder>
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

    HRESULT __stdcall get_RemoteId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RemoteId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ParentFolderId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ParentFolderId());
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

    HRESULT __stdcall put_DisplayName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSyncEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSyncEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsSyncEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsSyncEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastSuccessfulSyncTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastSuccessfulSyncTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LastSuccessfulSyncTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LastSuccessfulSyncTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::ApplicationModel::Email::EmailSpecialFolderKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFolderAsync(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFolderAsync(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DeleteAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindChildFoldersAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailFolder>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindChildFoldersAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConversationReader(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailConversationReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetConversationReader());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConversationReaderWithOptions(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailQueryOptions> options, impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailConversationReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetConversationReader(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailQueryOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMessageAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetMessageAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMessageReader(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMessageReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetMessageReader());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMessageReaderWithOptions(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailQueryOptions> options, impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMessageReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetMessageReader(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailQueryOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMessageCountsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailItemCounts>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetMessageCountsAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryMoveAsync(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailFolder> newParentFolder, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryMoveAsync(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailFolder *>(&newParentFolder)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryMoveWithNewNameAsync(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailFolder> newParentFolder, impl::abi_arg_in<hstring> newFolderName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryMoveAsync(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailFolder *>(&newParentFolder), *reinterpret_cast<const hstring *>(&newFolderName)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySaveAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TrySaveAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveMessageAsync(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailMessage> message, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SaveMessageAsync(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailMessage *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailIrmInfo> : produce_base<D, Windows::ApplicationModel::Email::IEmailIrmInfo>
{
    HRESULT __stdcall get_CanEdit(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanEdit());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanEdit(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanEdit(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanExtractData(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanExtractData());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanExtractData(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanExtractData(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanForward(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanForward());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanForward(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanForward(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanModifyRecipientsOnResponse(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanModifyRecipientsOnResponse());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanModifyRecipientsOnResponse(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanModifyRecipientsOnResponse(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanPrintData(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanPrintData());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanPrintData(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanPrintData(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanRemoveIrmOnResponse(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanRemoveIrmOnResponse());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanRemoveIrmOnResponse(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanRemoveIrmOnResponse(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanReply(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanReply());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanReply(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanReply(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanReplyAll(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanReplyAll());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanReplyAll(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanReplyAll(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExpirationDate(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExpirationDate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExpirationDate(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExpirationDate(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsIrmOriginator(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsIrmOriginator());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsIrmOriginator(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsIrmOriginator(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsProgramaticAccessAllowed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsProgramaticAccessAllowed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsProgramaticAccessAllowed(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsProgramaticAccessAllowed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Template(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailIrmTemplate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Template());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Template(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailIrmTemplate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Template(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailIrmTemplate *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailIrmInfoFactory> : produce_base<D, Windows::ApplicationModel::Email::IEmailIrmInfoFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::DateTime> expiration, impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailIrmTemplate> irmTemplate, impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailIrmInfo> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::DateTime *>(&expiration), *reinterpret_cast<const Windows::ApplicationModel::Email::EmailIrmTemplate *>(&irmTemplate)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailIrmTemplate> : produce_base<D, Windows::ApplicationModel::Email::IEmailIrmTemplate>
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

    HRESULT __stdcall put_Name(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailIrmTemplateFactory> : produce_base<D, Windows::ApplicationModel::Email::IEmailIrmTemplateFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> id, impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> description, impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailIrmTemplate> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&id), *reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&description)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailItemCounts> : produce_base<D, Windows::ApplicationModel::Email::IEmailItemCounts>
{
    HRESULT __stdcall get_Flagged(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Flagged());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Important(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Important());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Total(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Total());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Unread(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Unread());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMailbox> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailbox>
{
    HRESULT __stdcall get_Capabilities(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMailboxCapabilities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Capabilities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ChangeTracker(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMailboxChangeTracker> value) noexcept override
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

    HRESULT __stdcall put_DisplayName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<const hstring *>(&value));
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

    HRESULT __stdcall get_IsOwnedByCurrentApp(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOwnedByCurrentApp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDataEncryptedUnderLock(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDataEncryptedUnderLock());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MailAddress(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MailAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MailAddress(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MailAddress(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MailAddressAliases(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MailAddressAliases());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OtherAppReadAccess(Windows::ApplicationModel::Email::EmailMailboxOtherAppReadAccess * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OtherAppReadAccess());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OtherAppReadAccess(Windows::ApplicationModel::Email::EmailMailboxOtherAppReadAccess value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OtherAppReadAccess(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OtherAppWriteAccess(Windows::ApplicationModel::Email::EmailMailboxOtherAppWriteAccess * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OtherAppWriteAccess());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OtherAppWriteAccess(Windows::ApplicationModel::Email::EmailMailboxOtherAppWriteAccess value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OtherAppWriteAccess(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Policies(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMailboxPolicies> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Policies());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceDisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceDisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SyncManager(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMailboxSyncManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SyncManager());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserDataAccountId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserDataAccountId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConversationReader(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailConversationReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetConversationReader());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConversationReaderWithOptions(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailQueryOptions> options, impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailConversationReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetConversationReader(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailQueryOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMessageReader(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMessageReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetMessageReader());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMessageReaderWithOptions(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailQueryOptions> options, impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMessageReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetMessageReader(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailQueryOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DeleteAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConversationAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailConversation>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetConversationAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFolderAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetFolderAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMessageAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetMessageAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSpecialFolderAsync(Windows::ApplicationModel::Email::EmailSpecialFolderKind folderType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetSpecialFolderAsync(folderType));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SaveAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkMessageAsSeenAsync(impl::abi_arg_in<hstring> messageId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MarkMessageAsSeenAsync(*reinterpret_cast<const hstring *>(&messageId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkFolderAsSeenAsync(impl::abi_arg_in<hstring> folderId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MarkFolderAsSeenAsync(*reinterpret_cast<const hstring *>(&folderId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkMessageReadAsync(impl::abi_arg_in<hstring> messageId, bool isRead, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MarkMessageReadAsync(*reinterpret_cast<const hstring *>(&messageId), isRead));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ChangeMessageFlagStateAsync(impl::abi_arg_in<hstring> messageId, Windows::ApplicationModel::Email::EmailFlagState flagState, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ChangeMessageFlagStateAsync(*reinterpret_cast<const hstring *>(&messageId), flagState));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryMoveMessageAsync(impl::abi_arg_in<hstring> messageId, impl::abi_arg_in<hstring> newParentFolderId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryMoveMessageAsync(*reinterpret_cast<const hstring *>(&messageId), *reinterpret_cast<const hstring *>(&newParentFolderId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryMoveFolderAsync(impl::abi_arg_in<hstring> folderId, impl::abi_arg_in<hstring> newParentFolderId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryMoveFolderAsync(*reinterpret_cast<const hstring *>(&folderId), *reinterpret_cast<const hstring *>(&newParentFolderId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryMoveFolderWithNewNameAsync(impl::abi_arg_in<hstring> folderId, impl::abi_arg_in<hstring> newParentFolderId, impl::abi_arg_in<hstring> newFolderName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryMoveFolderAsync(*reinterpret_cast<const hstring *>(&folderId), *reinterpret_cast<const hstring *>(&newParentFolderId), *reinterpret_cast<const hstring *>(&newFolderName)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteMessageAsync(impl::abi_arg_in<hstring> messageId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DeleteMessageAsync(*reinterpret_cast<const hstring *>(&messageId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkFolderSyncEnabledAsync(impl::abi_arg_in<hstring> folderId, bool isSyncEnabled, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MarkFolderSyncEnabledAsync(*reinterpret_cast<const hstring *>(&folderId), isSyncEnabled));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendMessageAsync(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailMessage> message, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SendMessageAsync(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailMessage *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveDraftAsync(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailMessage> message, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SaveDraftAsync(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailMessage *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DownloadMessageAsync(impl::abi_arg_in<hstring> messageId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DownloadMessageAsync(*reinterpret_cast<const hstring *>(&messageId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DownloadAttachmentAsync(impl::abi_arg_in<hstring> attachmentId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DownloadAttachmentAsync(*reinterpret_cast<const hstring *>(&attachmentId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateResponseMessageAsync(impl::abi_arg_in<hstring> messageId, Windows::ApplicationModel::Email::EmailMessageResponseKind responseType, impl::abi_arg_in<hstring> subject, Windows::ApplicationModel::Email::EmailMessageBodyKind responseHeaderType, impl::abi_arg_in<hstring> responseHeader, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateResponseMessageAsync(*reinterpret_cast<const hstring *>(&messageId), responseType, *reinterpret_cast<const hstring *>(&subject), responseHeaderType, *reinterpret_cast<const hstring *>(&responseHeader)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryUpdateMeetingResponseAsync(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailMessage> meeting, Windows::ApplicationModel::Email::EmailMeetingResponseType response, impl::abi_arg_in<hstring> subject, impl::abi_arg_in<hstring> comment, bool sendUpdate, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryUpdateMeetingResponseAsync(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailMessage *>(&meeting), response, *reinterpret_cast<const hstring *>(&subject), *reinterpret_cast<const hstring *>(&comment), sendUpdate));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryForwardMeetingAsync(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailMessage> meeting, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Email::EmailRecipient>> recipients, impl::abi_arg_in<hstring> subject, Windows::ApplicationModel::Email::EmailMessageBodyKind forwardHeaderType, impl::abi_arg_in<hstring> forwardHeader, impl::abi_arg_in<hstring> comment, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryForwardMeetingAsync(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailMessage *>(&meeting), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Email::EmailRecipient> *>(&recipients), *reinterpret_cast<const hstring *>(&subject), forwardHeaderType, *reinterpret_cast<const hstring *>(&forwardHeader), *reinterpret_cast<const hstring *>(&comment)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryProposeNewTimeForMeetingAsync(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailMessage> meeting, impl::abi_arg_in<Windows::Foundation::DateTime> newStartTime, impl::abi_arg_in<Windows::Foundation::TimeSpan> newDuration, impl::abi_arg_in<hstring> subject, impl::abi_arg_in<hstring> comment, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryProposeNewTimeForMeetingAsync(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailMessage *>(&meeting), *reinterpret_cast<const Windows::Foundation::DateTime *>(&newStartTime), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&newDuration), *reinterpret_cast<const hstring *>(&subject), *reinterpret_cast<const hstring *>(&comment)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MailboxChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::EmailMailbox, Windows::ApplicationModel::Email::EmailMailboxChangedEventArgs>> pHandler, event_token * pToken) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pToken = detach_abi(this->shim().MailboxChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::EmailMailbox, Windows::ApplicationModel::Email::EmailMailboxChangedEventArgs> *>(&pHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MailboxChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MailboxChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SmartSendMessageAsync(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailMessage> message, bool smartSend, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SendMessageAsync(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailMessage *>(&message), smartSend));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetAutoReplySettingsAsync(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings> autoReplySettings, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TrySetAutoReplySettingsAsync(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings *>(&autoReplySettings)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetAutoReplySettingsAsync(Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind requestedFormat, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings>> autoReplySettings) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *autoReplySettings = detach_abi(this->shim().TryGetAutoReplySettingsAsync(requestedFormat));
            return S_OK;
        }
        catch (...)
        {
            *autoReplySettings = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMailbox2> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailbox2>
{
    HRESULT __stdcall get_LinkedMailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LinkedMailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NetworkAccountId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkAccountId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NetworkId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkId());
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
struct produce<D, Windows::ApplicationModel::Email::IEmailMailbox3> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailbox3>
{
    HRESULT __stdcall abi_ResolveRecipientsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> recipients, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailRecipientResolutionResult>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ResolveRecipientsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&recipients)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ValidateCertificatesAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate>> certificates, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ValidateCertificatesAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate> *>(&certificates)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryEmptyFolderAsync(impl::abi_arg_in<hstring> folderId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryEmptyFolderAsync(*reinterpret_cast<const hstring *>(&folderId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryCreateFolderAsync(impl::abi_arg_in<hstring> parentFolderId, impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailboxCreateFolderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryCreateFolderAsync(*reinterpret_cast<const hstring *>(&parentFolderId), *reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryDeleteFolderAsync(impl::abi_arg_in<hstring> folderId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryDeleteFolderAsync(*reinterpret_cast<const hstring *>(&folderId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMailbox4> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailbox4>
{
    HRESULT __stdcall abi_RegisterSyncManagerAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RegisterSyncManagerAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxAction> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxAction>
{
    HRESULT __stdcall get_Kind(Windows::ApplicationModel::Email::EmailMailboxActionKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ChangeNumber(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChangeNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxAutoReply> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxAutoReply>
{
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

    HRESULT __stdcall put_IsEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Response(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Response());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Response(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Response(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings>
{
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

    HRESULT __stdcall put_IsEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResponseKind(Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResponseKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ResponseKind(Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResponseKind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StartTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StartTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EndTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EndTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InternalReply(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMailboxAutoReply> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InternalReply());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KnownExternalReply(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMailboxAutoReply> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KnownExternalReply());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UnknownExternalReply(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMailboxAutoReply> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnknownExternalReply());
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
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxCapabilities> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxCapabilities>
{
    HRESULT __stdcall get_CanForwardMeetings(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanForwardMeetings());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanGetAndSetExternalAutoReplies(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanGetAndSetExternalAutoReplies());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanGetAndSetInternalAutoReplies(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanGetAndSetInternalAutoReplies());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanUpdateMeetingResponses(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanUpdateMeetingResponses());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanServerSearchFolders(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanServerSearchFolders());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanServerSearchMailbox(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanServerSearchMailbox());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanProposeNewTimeForMeetings(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanProposeNewTimeForMeetings());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanSmartSend(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanSmartSend());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxCapabilities2> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxCapabilities2>
{
    HRESULT __stdcall get_CanResolveRecipients(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanResolveRecipients());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanValidateCertificates(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanValidateCertificates());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanEmptyFolder(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanEmptyFolder());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanCreateFolder(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanCreateFolder());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanDeleteFolder(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanDeleteFolder());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanMoveFolder(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanMoveFolder());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxCapabilities3> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>
{
    HRESULT __stdcall put_CanForwardMeetings(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanForwardMeetings(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanGetAndSetExternalAutoReplies(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanGetAndSetExternalAutoReplies(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanGetAndSetInternalAutoReplies(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanGetAndSetInternalAutoReplies(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanUpdateMeetingResponses(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanUpdateMeetingResponses(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanServerSearchFolders(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanServerSearchFolders(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanServerSearchMailbox(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanServerSearchMailbox(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanProposeNewTimeForMeetings(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanProposeNewTimeForMeetings(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanSmartSend(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanSmartSend(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanResolveRecipients(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanResolveRecipients(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanValidateCertificates(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanValidateCertificates(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanEmptyFolder(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanEmptyFolder(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanCreateFolder(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanCreateFolder(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanDeleteFolder(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanDeleteFolder(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanMoveFolder(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanMoveFolder(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxChange> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxChange>
{
    HRESULT __stdcall get_ChangeType(Windows::ApplicationModel::Email::EmailMailboxChangeType * value) noexcept override
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

    HRESULT __stdcall get_MailboxActions(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailMailboxAction>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MailboxActions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Message(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Message());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Folder(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Folder());
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
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxChangeReader> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxChangeReader>
{
    HRESULT __stdcall abi_AcceptChanges() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcceptChanges();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AcceptChangesThrough(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailMailboxChange> lastChangeToAcknowledge) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcceptChangesThrough(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailMailboxChange *>(&lastChangeToAcknowledge));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadBatchAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailboxChange>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadBatchAsync());
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
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxChangeTracker> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxChangeTracker>
{
    HRESULT __stdcall get_IsTracking(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTracking());
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

    HRESULT __stdcall abi_GetChangeReader(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMailboxChangeReader> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxChangedDeferral> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxChangedDeferral>
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
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxChangedEventArgs> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxChangedEventArgs>
{
    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMailboxChangedDeferral> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxCreateFolderResult> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxCreateFolderResult>
{
    HRESULT __stdcall get_Status(Windows::ApplicationModel::Email::EmailMailboxCreateFolderStatus * value) noexcept override
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

    HRESULT __stdcall get_Folder(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Folder());
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
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxPolicies> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxPolicies>
{
    HRESULT __stdcall get_AllowedSmimeEncryptionAlgorithmNegotiation(Windows::ApplicationModel::Email::EmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowedSmimeEncryptionAlgorithmNegotiation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowSmimeSoftCertificates(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowSmimeSoftCertificates());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequiredSmimeEncryptionAlgorithm(impl::abi_arg_out<Windows::Foundation::IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeEncryptionAlgorithm>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequiredSmimeEncryptionAlgorithm());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequiredSmimeSigningAlgorithm(impl::abi_arg_out<Windows::Foundation::IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeSigningAlgorithm>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequiredSmimeSigningAlgorithm());
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
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxPolicies2> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxPolicies2>
{
    HRESULT __stdcall get_MustEncryptSmimeMessages(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MustEncryptSmimeMessages());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MustSignSmimeMessages(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MustSignSmimeMessages());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxPolicies3> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxPolicies3>
{
    HRESULT __stdcall put_AllowedSmimeEncryptionAlgorithmNegotiation(Windows::ApplicationModel::Email::EmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowedSmimeEncryptionAlgorithmNegotiation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowSmimeSoftCertificates(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowSmimeSoftCertificates(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RequiredSmimeEncryptionAlgorithm(impl::abi_arg_in<Windows::Foundation::IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeEncryptionAlgorithm>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequiredSmimeEncryptionAlgorithm(*reinterpret_cast<const Windows::Foundation::IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeEncryptionAlgorithm> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RequiredSmimeSigningAlgorithm(impl::abi_arg_in<Windows::Foundation::IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeSigningAlgorithm>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequiredSmimeSigningAlgorithm(*reinterpret_cast<const Windows::Foundation::IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeSigningAlgorithm> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MustEncryptSmimeMessages(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MustEncryptSmimeMessages(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MustSignSmimeMessages(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MustSignSmimeMessages(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxSyncManager> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxSyncManager>
{
    HRESULT __stdcall get_Status(Windows::ApplicationModel::Email::EmailMailboxSyncStatus * value) noexcept override
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

    HRESULT __stdcall get_LastSuccessfulSyncTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastSuccessfulSyncTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastAttemptedSyncTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastAttemptedSyncTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SyncAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SyncAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SyncStatusChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::EmailMailboxSyncManager, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SyncStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::EmailMailboxSyncManager, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SyncStatusChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SyncStatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMailboxSyncManager2> : produce_base<D, Windows::ApplicationModel::Email::IEmailMailboxSyncManager2>
{
    HRESULT __stdcall put_Status(Windows::ApplicationModel::Email::EmailMailboxSyncStatus value) noexcept override
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

    HRESULT __stdcall put_LastSuccessfulSyncTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LastSuccessfulSyncTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LastAttemptedSyncTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LastAttemptedSyncTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailManagerForUser> : produce_base<D, Windows::ApplicationModel::Email::IEmailManagerForUser>
{
    HRESULT __stdcall abi_ShowComposeNewEmailAsync(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailMessage> message, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShowComposeNewEmailAsync(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailMessage *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestStoreAsync(Windows::ApplicationModel::Email::EmailStoreAccessType accessType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailStore>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestStoreAsync(accessType));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_User(impl::abi_arg_out<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().User());
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
struct produce<D, Windows::ApplicationModel::Email::IEmailManagerStatics> : produce_base<D, Windows::ApplicationModel::Email::IEmailManagerStatics>
{
    HRESULT __stdcall abi_ShowComposeNewEmailAsync(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailMessage> message, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_abi(this->shim().ShowComposeNewEmailAsync(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailMessage *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            *asyncAction = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailManagerStatics2> : produce_base<D, Windows::ApplicationModel::Email::IEmailManagerStatics2>
{
    HRESULT __stdcall abi_RequestStoreAsync(Windows::ApplicationModel::Email::EmailStoreAccessType accessType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailStore>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestStoreAsync(accessType));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailManagerStatics3> : produce_base<D, Windows::ApplicationModel::Email::IEmailManagerStatics3>
{
    HRESULT __stdcall abi_GetForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailManagerForUser> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetForUser(*reinterpret_cast<const Windows::System::User *>(&user)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMeetingInfo> : produce_base<D, Windows::ApplicationModel::Email::IEmailMeetingInfo>
{
    HRESULT __stdcall get_AllowNewTimeProposal(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowNewTimeProposal());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowNewTimeProposal(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowNewTimeProposal(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppointmentRoamingId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppointmentRoamingId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AppointmentRoamingId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppointmentRoamingId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppointmentOriginalStartTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppointmentOriginalStartTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AppointmentOriginalStartTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppointmentOriginalStartTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Duration(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Duration(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsAllDay(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAllDay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsAllDay(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsAllDay(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsResponseRequested(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsResponseRequested());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsResponseRequested(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsResponseRequested(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Location(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Location(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Location(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProposedStartTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> proposedStartTime) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *proposedStartTime = detach_abi(this->shim().ProposedStartTime());
            return S_OK;
        }
        catch (...)
        {
            *proposedStartTime = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProposedStartTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> proposedStartTime) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProposedStartTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&proposedStartTime));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProposedDuration(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> duration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *duration = detach_abi(this->shim().ProposedDuration());
            return S_OK;
        }
        catch (...)
        {
            *duration = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProposedDuration(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> duration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProposedDuration(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&duration));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RecurrenceStartTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RecurrenceStartTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RecurrenceStartTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RecurrenceStartTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Recurrence(impl::abi_arg_out<Windows::ApplicationModel::Appointments::IAppointmentRecurrence> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Recurrence());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Recurrence(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointmentRecurrence> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Recurrence(*reinterpret_cast<const Windows::ApplicationModel::Appointments::AppointmentRecurrence *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemoteChangeNumber(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteChangeNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RemoteChangeNumber(uint64_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteChangeNumber(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StartTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StartTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMeetingInfo2> : produce_base<D, Windows::ApplicationModel::Email::IEmailMeetingInfo2>
{
    HRESULT __stdcall get_IsReportedOutOfDateByServer(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsReportedOutOfDateByServer());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMessage> : produce_base<D, Windows::ApplicationModel::Email::IEmailMessage>
{
    HRESULT __stdcall get_Subject(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Subject());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Subject(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Subject(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Body(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Body());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Body(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Body(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_To(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CC(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CC());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Bcc(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bcc());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Attachments(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailAttachment>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Attachments());
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
struct produce<D, Windows::ApplicationModel::Email::IEmailMessage2> : produce_base<D, Windows::ApplicationModel::Email::IEmailMessage2>
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

    HRESULT __stdcall get_RemoteId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RemoteId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConversationId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConversationId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FolderId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FolderId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowInternetImages(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowInternetImages());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowInternetImages(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowInternetImages(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ChangeNumber(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChangeNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DownloadState(Windows::ApplicationModel::Email::EmailMessageDownloadState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DownloadState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DownloadState(Windows::ApplicationModel::Email::EmailMessageDownloadState value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DownloadState(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EstimatedDownloadSizeInBytes(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EstimatedDownloadSizeInBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EstimatedDownloadSizeInBytes(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EstimatedDownloadSizeInBytes(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FlagState(Windows::ApplicationModel::Email::EmailFlagState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FlagState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FlagState(Windows::ApplicationModel::Email::EmailFlagState value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FlagState(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasPartialBodies(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasPartialBodies());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Importance(Windows::ApplicationModel::Email::EmailImportance * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Importance());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Importance(Windows::ApplicationModel::Email::EmailImportance value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Importance(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InResponseToMessageId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InResponseToMessageId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IrmInfo(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailIrmInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IrmInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IrmInfo(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailIrmInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IrmInfo(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailIrmInfo *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDraftMessage(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDraftMessage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsRead(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsRead());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsRead(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsRead(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSeen(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSeen());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsSeen(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsSeen(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsServerSearchMessage(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsServerSearchMessage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSmartSendable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSmartSendable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageClass(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MessageClass());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MessageClass(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MessageClass(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NormalizedSubject(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NormalizedSubject());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OriginalCodePage(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OriginalCodePage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OriginalCodePage(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OriginalCodePage(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Preview(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Preview());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Preview(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Preview(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastResponseKind(Windows::ApplicationModel::Email::EmailMessageResponseKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastResponseKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LastResponseKind(Windows::ApplicationModel::Email::EmailMessageResponseKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LastResponseKind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Sender(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailRecipient> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Sender());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Sender(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailRecipient> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Sender(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailRecipient *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SentTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SentTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SentTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SentTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MeetingInfo(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMeetingInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MeetingInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MeetingInfo(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailMeetingInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MeetingInfo(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailMeetingInfo *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetBodyStream(Windows::ApplicationModel::Email::EmailMessageBodyKind type, impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetBodyStream(type));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetBodyStream(Windows::ApplicationModel::Email::EmailMessageBodyKind type, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> stream) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBodyStream(type, *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&stream));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMessage3> : produce_base<D, Windows::ApplicationModel::Email::IEmailMessage3>
{
    HRESULT __stdcall get_SmimeData(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmimeData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SmimeData(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SmimeData(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SmimeKind(Windows::ApplicationModel::Email::EmailMessageSmimeKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmimeKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SmimeKind(Windows::ApplicationModel::Email::EmailMessageSmimeKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SmimeKind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMessageBatch> : produce_base<D, Windows::ApplicationModel::Email::IEmailMessageBatch>
{
    HRESULT __stdcall get_Messages(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Messages());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::ApplicationModel::Email::EmailBatchStatus * value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailMessageReader> : produce_base<D, Windows::ApplicationModel::Email::IEmailMessageReader>
{
    HRESULT __stdcall abi_ReadBatchAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessageBatch>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReadBatchAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailQueryOptions> : produce_base<D, Windows::ApplicationModel::Email::IEmailQueryOptions>
{
    HRESULT __stdcall get_TextSearch(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailQueryTextSearch> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextSearch());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SortDirection(Windows::ApplicationModel::Email::EmailQuerySortDirection * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SortDirection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SortDirection(Windows::ApplicationModel::Email::EmailQuerySortDirection value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SortDirection(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SortProperty(Windows::ApplicationModel::Email::EmailQuerySortProperty * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SortProperty());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SortProperty(Windows::ApplicationModel::Email::EmailQuerySortProperty value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SortProperty(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::ApplicationModel::Email::EmailQueryKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Kind(Windows::ApplicationModel::Email::EmailQueryKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Kind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FolderIds(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FolderIds());
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
struct produce<D, Windows::ApplicationModel::Email::IEmailQueryOptionsFactory> : produce_base<D, Windows::ApplicationModel::Email::IEmailQueryOptionsFactory>
{
    HRESULT __stdcall abi_CreateWithText(impl::abi_arg_in<hstring> text, impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailQueryOptions> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithText(*reinterpret_cast<const hstring *>(&text)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithTextAndFields(impl::abi_arg_in<hstring> text, Windows::ApplicationModel::Email::EmailQuerySearchFields fields, impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailQueryOptions> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithTextAndFields(*reinterpret_cast<const hstring *>(&text), fields));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailQueryTextSearch> : produce_base<D, Windows::ApplicationModel::Email::IEmailQueryTextSearch>
{
    HRESULT __stdcall get_Fields(Windows::ApplicationModel::Email::EmailQuerySearchFields * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Fields());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Fields(Windows::ApplicationModel::Email::EmailQuerySearchFields value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Fields(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SearchScope(Windows::ApplicationModel::Email::EmailQuerySearchScope * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SearchScope());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SearchScope(Windows::ApplicationModel::Email::EmailQuerySearchScope value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SearchScope(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall put_Text(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Text(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailRecipient> : produce_base<D, Windows::ApplicationModel::Email::IEmailRecipient>
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

    HRESULT __stdcall put_Name(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Address(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Address());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Address(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Address(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailRecipientFactory> : produce_base<D, Windows::ApplicationModel::Email::IEmailRecipientFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> address, impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailRecipient> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&address)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithName(impl::abi_arg_in<hstring> address, impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailRecipient> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithName(*reinterpret_cast<const hstring *>(&address), *reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailRecipientResolutionResult> : produce_base<D, Windows::ApplicationModel::Email::IEmailRecipientResolutionResult>
{
    HRESULT __stdcall get_Status(Windows::ApplicationModel::Email::EmailRecipientResolutionStatus * value) noexcept override
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

    HRESULT __stdcall get_PublicKeys(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PublicKeys());
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
struct produce<D, Windows::ApplicationModel::Email::IEmailRecipientResolutionResult2> : produce_base<D, Windows::ApplicationModel::Email::IEmailRecipientResolutionResult2>
{
    HRESULT __stdcall put_Status(Windows::ApplicationModel::Email::EmailRecipientResolutionStatus value) noexcept override
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

    HRESULT __stdcall abi_SetPublicKeys(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPublicKeys(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailStore> : produce_base<D, Windows::ApplicationModel::Email::IEmailStore>
{
    HRESULT __stdcall abi_FindMailboxesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailbox>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindMailboxesAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConversationReader(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailConversationReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetConversationReader());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConversationReaderWithOptions(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailQueryOptions> options, impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailConversationReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetConversationReader(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailQueryOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMessageReader(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMessageReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetMessageReader());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMessageReaderWithOptions(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailQueryOptions> options, impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMessageReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetMessageReader(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailQueryOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMailboxAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetMailboxAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConversationAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailConversation>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetConversationAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFolderAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetFolderAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMessageAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetMessageAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateMailboxAsync(impl::abi_arg_in<hstring> accountName, impl::abi_arg_in<hstring> accountAddress, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateMailboxAsync(*reinterpret_cast<const hstring *>(&accountName), *reinterpret_cast<const hstring *>(&accountAddress)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateMailboxInAccountAsync(impl::abi_arg_in<hstring> accountName, impl::abi_arg_in<hstring> accountAddress, impl::abi_arg_in<hstring> userDataAccountId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateMailboxAsync(*reinterpret_cast<const hstring *>(&accountName), *reinterpret_cast<const hstring *>(&accountAddress), *reinterpret_cast<const hstring *>(&userDataAccountId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::IEmailStoreNotificationTriggerDetails> : produce_base<D, Windows::ApplicationModel::Email::IEmailStoreNotificationTriggerDetails>
{};

}

namespace Windows::ApplicationModel::Email {

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailManagerStatics<D>::ShowComposeNewEmailAsync(const Windows::ApplicationModel::Email::EmailMessage & message) const
{
    Windows::Foundation::IAsyncAction asyncAction;
    check_hresult(WINRT_SHIM(IEmailManagerStatics)->abi_ShowComposeNewEmailAsync(get_abi(message), put_abi(asyncAction)));
    return asyncAction;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailStore> impl_IEmailManagerStatics2<D>::RequestStoreAsync(Windows::ApplicationModel::Email::EmailStoreAccessType accessType) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailStore> result;
    check_hresult(WINRT_SHIM(IEmailManagerStatics2)->abi_RequestStoreAsync(accessType, put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailManagerForUser impl_IEmailManagerStatics3<D>::GetForUser(const Windows::System::User & user) const
{
    Windows::ApplicationModel::Email::EmailManagerForUser result { nullptr };
    check_hresult(WINRT_SHIM(IEmailManagerStatics3)->abi_GetForUser(get_abi(user), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailManagerForUser<D>::ShowComposeNewEmailAsync(const Windows::ApplicationModel::Email::EmailMessage & message) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailManagerForUser)->abi_ShowComposeNewEmailAsync(get_abi(message), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailStore> impl_IEmailManagerForUser<D>::RequestStoreAsync(Windows::ApplicationModel::Email::EmailStoreAccessType accessType) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailStore> result;
    check_hresult(WINRT_SHIM(IEmailManagerForUser)->abi_RequestStoreAsync(accessType, put_abi(result)));
    return result;
}

template <typename D> Windows::System::User impl_IEmailManagerForUser<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IEmailManagerForUser)->get_User(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailbox>> impl_IEmailStore<D>::FindMailboxesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailbox>> result;
    check_hresult(WINRT_SHIM(IEmailStore)->abi_FindMailboxesAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailConversationReader impl_IEmailStore<D>::GetConversationReader() const
{
    Windows::ApplicationModel::Email::EmailConversationReader result { nullptr };
    check_hresult(WINRT_SHIM(IEmailStore)->abi_GetConversationReader(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailConversationReader impl_IEmailStore<D>::GetConversationReader(const Windows::ApplicationModel::Email::EmailQueryOptions & options) const
{
    Windows::ApplicationModel::Email::EmailConversationReader result { nullptr };
    check_hresult(WINRT_SHIM(IEmailStore)->abi_GetConversationReaderWithOptions(get_abi(options), put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailMessageReader impl_IEmailStore<D>::GetMessageReader() const
{
    Windows::ApplicationModel::Email::EmailMessageReader result { nullptr };
    check_hresult(WINRT_SHIM(IEmailStore)->abi_GetMessageReader(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailMessageReader impl_IEmailStore<D>::GetMessageReader(const Windows::ApplicationModel::Email::EmailQueryOptions & options) const
{
    Windows::ApplicationModel::Email::EmailMessageReader result { nullptr };
    check_hresult(WINRT_SHIM(IEmailStore)->abi_GetMessageReaderWithOptions(get_abi(options), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox> impl_IEmailStore<D>::GetMailboxAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox> result;
    check_hresult(WINRT_SHIM(IEmailStore)->abi_GetMailboxAsync(get_abi(id), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailConversation> impl_IEmailStore<D>::GetConversationAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailConversation> result;
    check_hresult(WINRT_SHIM(IEmailStore)->abi_GetConversationAsync(get_abi(id), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> impl_IEmailStore<D>::GetFolderAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> result;
    check_hresult(WINRT_SHIM(IEmailStore)->abi_GetFolderAsync(get_abi(id), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> impl_IEmailStore<D>::GetMessageAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> result;
    check_hresult(WINRT_SHIM(IEmailStore)->abi_GetMessageAsync(get_abi(id), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox> impl_IEmailStore<D>::CreateMailboxAsync(hstring_view accountName, hstring_view accountAddress) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox> result;
    check_hresult(WINRT_SHIM(IEmailStore)->abi_CreateMailboxAsync(get_abi(accountName), get_abi(accountAddress), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox> impl_IEmailStore<D>::CreateMailboxAsync(hstring_view accountName, hstring_view accountAddress, hstring_view userDataAccountId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox> result;
    check_hresult(WINRT_SHIM(IEmailStore)->abi_CreateMailboxInAccountAsync(get_abi(accountName), get_abi(accountAddress), get_abi(userDataAccountId), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailRecipient<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailRecipient)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailRecipient<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailRecipient)->put_Name(get_abi(value)));
}

template <typename D> hstring impl_IEmailRecipient<D>::Address() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailRecipient)->get_Address(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailRecipient<D>::Address(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailRecipient)->put_Address(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Email::EmailRecipient impl_IEmailRecipientFactory<D>::Create(hstring_view address) const
{
    Windows::ApplicationModel::Email::EmailRecipient result { nullptr };
    check_hresult(WINRT_SHIM(IEmailRecipientFactory)->abi_Create(get_abi(address), put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailRecipient impl_IEmailRecipientFactory<D>::CreateWithName(hstring_view address, hstring_view name) const
{
    Windows::ApplicationModel::Email::EmailRecipient result { nullptr };
    check_hresult(WINRT_SHIM(IEmailRecipientFactory)->abi_CreateWithName(get_abi(address), get_abi(name), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailIrmTemplate<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailIrmTemplate)->get_Id(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailIrmTemplate<D>::Id(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailIrmTemplate)->put_Id(get_abi(value)));
}

template <typename D> hstring impl_IEmailIrmTemplate<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailIrmTemplate)->get_Description(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailIrmTemplate<D>::Description(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailIrmTemplate)->put_Description(get_abi(value)));
}

template <typename D> hstring impl_IEmailIrmTemplate<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailIrmTemplate)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailIrmTemplate<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailIrmTemplate)->put_Name(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Email::EmailIrmTemplate impl_IEmailIrmTemplateFactory<D>::Create(hstring_view id, hstring_view name, hstring_view description) const
{
    Windows::ApplicationModel::Email::EmailIrmTemplate result { nullptr };
    check_hresult(WINRT_SHIM(IEmailIrmTemplateFactory)->abi_Create(get_abi(id), get_abi(name), get_abi(description), put_abi(result)));
    return result;
}

template <typename D> bool impl_IEmailIrmInfo<D>::CanEdit() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->get_CanEdit(&value));
    return value;
}

template <typename D> void impl_IEmailIrmInfo<D>::CanEdit(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->put_CanEdit(value));
}

template <typename D> bool impl_IEmailIrmInfo<D>::CanExtractData() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->get_CanExtractData(&value));
    return value;
}

template <typename D> void impl_IEmailIrmInfo<D>::CanExtractData(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->put_CanExtractData(value));
}

template <typename D> bool impl_IEmailIrmInfo<D>::CanForward() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->get_CanForward(&value));
    return value;
}

template <typename D> void impl_IEmailIrmInfo<D>::CanForward(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->put_CanForward(value));
}

template <typename D> bool impl_IEmailIrmInfo<D>::CanModifyRecipientsOnResponse() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->get_CanModifyRecipientsOnResponse(&value));
    return value;
}

template <typename D> void impl_IEmailIrmInfo<D>::CanModifyRecipientsOnResponse(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->put_CanModifyRecipientsOnResponse(value));
}

template <typename D> bool impl_IEmailIrmInfo<D>::CanPrintData() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->get_CanPrintData(&value));
    return value;
}

template <typename D> void impl_IEmailIrmInfo<D>::CanPrintData(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->put_CanPrintData(value));
}

template <typename D> bool impl_IEmailIrmInfo<D>::CanRemoveIrmOnResponse() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->get_CanRemoveIrmOnResponse(&value));
    return value;
}

template <typename D> void impl_IEmailIrmInfo<D>::CanRemoveIrmOnResponse(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->put_CanRemoveIrmOnResponse(value));
}

template <typename D> bool impl_IEmailIrmInfo<D>::CanReply() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->get_CanReply(&value));
    return value;
}

template <typename D> void impl_IEmailIrmInfo<D>::CanReply(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->put_CanReply(value));
}

template <typename D> bool impl_IEmailIrmInfo<D>::CanReplyAll() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->get_CanReplyAll(&value));
    return value;
}

template <typename D> void impl_IEmailIrmInfo<D>::CanReplyAll(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->put_CanReplyAll(value));
}

template <typename D> Windows::Foundation::DateTime impl_IEmailIrmInfo<D>::ExpirationDate() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->get_ExpirationDate(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailIrmInfo<D>::ExpirationDate(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->put_ExpirationDate(get_abi(value)));
}

template <typename D> bool impl_IEmailIrmInfo<D>::IsIrmOriginator() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->get_IsIrmOriginator(&value));
    return value;
}

template <typename D> void impl_IEmailIrmInfo<D>::IsIrmOriginator(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->put_IsIrmOriginator(value));
}

template <typename D> bool impl_IEmailIrmInfo<D>::IsProgramaticAccessAllowed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->get_IsProgramaticAccessAllowed(&value));
    return value;
}

template <typename D> void impl_IEmailIrmInfo<D>::IsProgramaticAccessAllowed(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->put_IsProgramaticAccessAllowed(value));
}

template <typename D> Windows::ApplicationModel::Email::EmailIrmTemplate impl_IEmailIrmInfo<D>::Template() const
{
    Windows::ApplicationModel::Email::EmailIrmTemplate value { nullptr };
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->get_Template(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailIrmInfo<D>::Template(const Windows::ApplicationModel::Email::EmailIrmTemplate & value) const
{
    check_hresult(WINRT_SHIM(IEmailIrmInfo)->put_Template(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Email::EmailIrmInfo impl_IEmailIrmInfoFactory<D>::Create(const Windows::Foundation::DateTime & expiration, const Windows::ApplicationModel::Email::EmailIrmTemplate & irmTemplate) const
{
    Windows::ApplicationModel::Email::EmailIrmInfo result { nullptr };
    check_hresult(WINRT_SHIM(IEmailIrmInfoFactory)->abi_Create(get_abi(expiration), get_abi(irmTemplate), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailMessage<D>::Subject() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMessage)->get_Subject(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMessage<D>::Subject(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage)->put_Subject(get_abi(value)));
}

template <typename D> hstring impl_IEmailMessage<D>::Body() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMessage)->get_Body(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMessage<D>::Body(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage)->put_Body(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient> impl_IEmailMessage<D>::To() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient> value;
    check_hresult(WINRT_SHIM(IEmailMessage)->get_To(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient> impl_IEmailMessage<D>::CC() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient> value;
    check_hresult(WINRT_SHIM(IEmailMessage)->get_CC(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient> impl_IEmailMessage<D>::Bcc() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient> value;
    check_hresult(WINRT_SHIM(IEmailMessage)->get_Bcc(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailAttachment> impl_IEmailMessage<D>::Attachments() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailAttachment> value;
    check_hresult(WINRT_SHIM(IEmailMessage)->get_Attachments(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMessage2<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMessage2<D>::RemoteId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_RemoteId(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMessage2<D>::RemoteId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->put_RemoteId(get_abi(value)));
}

template <typename D> hstring impl_IEmailMessage2<D>::MailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_MailboxId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMessage2<D>::ConversationId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_ConversationId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMessage2<D>::FolderId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_FolderId(put_abi(value)));
    return value;
}

template <typename D> bool impl_IEmailMessage2<D>::AllowInternetImages() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_AllowInternetImages(&value));
    return value;
}

template <typename D> void impl_IEmailMessage2<D>::AllowInternetImages(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->put_AllowInternetImages(value));
}

template <typename D> uint64_t impl_IEmailMessage2<D>::ChangeNumber() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_ChangeNumber(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailMessageDownloadState impl_IEmailMessage2<D>::DownloadState() const
{
    Windows::ApplicationModel::Email::EmailMessageDownloadState value {};
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_DownloadState(&value));
    return value;
}

template <typename D> void impl_IEmailMessage2<D>::DownloadState(Windows::ApplicationModel::Email::EmailMessageDownloadState value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->put_DownloadState(value));
}

template <typename D> uint32_t impl_IEmailMessage2<D>::EstimatedDownloadSizeInBytes() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_EstimatedDownloadSizeInBytes(&value));
    return value;
}

template <typename D> void impl_IEmailMessage2<D>::EstimatedDownloadSizeInBytes(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->put_EstimatedDownloadSizeInBytes(value));
}

template <typename D> Windows::ApplicationModel::Email::EmailFlagState impl_IEmailMessage2<D>::FlagState() const
{
    Windows::ApplicationModel::Email::EmailFlagState value {};
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_FlagState(&value));
    return value;
}

template <typename D> void impl_IEmailMessage2<D>::FlagState(Windows::ApplicationModel::Email::EmailFlagState value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->put_FlagState(value));
}

template <typename D> bool impl_IEmailMessage2<D>::HasPartialBodies() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_HasPartialBodies(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailImportance impl_IEmailMessage2<D>::Importance() const
{
    Windows::ApplicationModel::Email::EmailImportance value {};
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_Importance(&value));
    return value;
}

template <typename D> void impl_IEmailMessage2<D>::Importance(Windows::ApplicationModel::Email::EmailImportance value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->put_Importance(value));
}

template <typename D> hstring impl_IEmailMessage2<D>::InResponseToMessageId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_InResponseToMessageId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailIrmInfo impl_IEmailMessage2<D>::IrmInfo() const
{
    Windows::ApplicationModel::Email::EmailIrmInfo value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_IrmInfo(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMessage2<D>::IrmInfo(const Windows::ApplicationModel::Email::EmailIrmInfo & value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->put_IrmInfo(get_abi(value)));
}

template <typename D> bool impl_IEmailMessage2<D>::IsDraftMessage() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_IsDraftMessage(&value));
    return value;
}

template <typename D> bool impl_IEmailMessage2<D>::IsRead() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_IsRead(&value));
    return value;
}

template <typename D> void impl_IEmailMessage2<D>::IsRead(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->put_IsRead(value));
}

template <typename D> bool impl_IEmailMessage2<D>::IsSeen() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_IsSeen(&value));
    return value;
}

template <typename D> void impl_IEmailMessage2<D>::IsSeen(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->put_IsSeen(value));
}

template <typename D> bool impl_IEmailMessage2<D>::IsServerSearchMessage() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_IsServerSearchMessage(&value));
    return value;
}

template <typename D> bool impl_IEmailMessage2<D>::IsSmartSendable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_IsSmartSendable(&value));
    return value;
}

template <typename D> hstring impl_IEmailMessage2<D>::MessageClass() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_MessageClass(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMessage2<D>::MessageClass(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->put_MessageClass(get_abi(value)));
}

template <typename D> hstring impl_IEmailMessage2<D>::NormalizedSubject() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_NormalizedSubject(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IEmailMessage2<D>::OriginalCodePage() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_OriginalCodePage(&value));
    return value;
}

template <typename D> void impl_IEmailMessage2<D>::OriginalCodePage(int32_t value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->put_OriginalCodePage(value));
}

template <typename D> hstring impl_IEmailMessage2<D>::Preview() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_Preview(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMessage2<D>::Preview(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->put_Preview(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Email::EmailMessageResponseKind impl_IEmailMessage2<D>::LastResponseKind() const
{
    Windows::ApplicationModel::Email::EmailMessageResponseKind value {};
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_LastResponseKind(&value));
    return value;
}

template <typename D> void impl_IEmailMessage2<D>::LastResponseKind(Windows::ApplicationModel::Email::EmailMessageResponseKind value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->put_LastResponseKind(value));
}

template <typename D> Windows::ApplicationModel::Email::EmailRecipient impl_IEmailMessage2<D>::Sender() const
{
    Windows::ApplicationModel::Email::EmailRecipient value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_Sender(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMessage2<D>::Sender(const Windows::ApplicationModel::Email::EmailRecipient & value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->put_Sender(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IEmailMessage2<D>::SentTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_SentTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMessage2<D>::SentTime(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->put_SentTime(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Email::EmailMeetingInfo impl_IEmailMessage2<D>::MeetingInfo() const
{
    Windows::ApplicationModel::Email::EmailMeetingInfo value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMessage2)->get_MeetingInfo(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMessage2<D>::MeetingInfo(const Windows::ApplicationModel::Email::EmailMeetingInfo & value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->put_MeetingInfo(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IEmailMessage2<D>::GetBodyStream(Windows::ApplicationModel::Email::EmailMessageBodyKind type) const
{
    Windows::Storage::Streams::IRandomAccessStreamReference result;
    check_hresult(WINRT_SHIM(IEmailMessage2)->abi_GetBodyStream(type, put_abi(result)));
    return result;
}

template <typename D> void impl_IEmailMessage2<D>::SetBodyStream(Windows::ApplicationModel::Email::EmailMessageBodyKind type, const Windows::Storage::Streams::IRandomAccessStreamReference & stream) const
{
    check_hresult(WINRT_SHIM(IEmailMessage2)->abi_SetBodyStream(type, get_abi(stream)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IEmailMessage3<D>::SmimeData() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IEmailMessage3)->get_SmimeData(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMessage3<D>::SmimeData(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage3)->put_SmimeData(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Email::EmailMessageSmimeKind impl_IEmailMessage3<D>::SmimeKind() const
{
    Windows::ApplicationModel::Email::EmailMessageSmimeKind value {};
    check_hresult(WINRT_SHIM(IEmailMessage3)->get_SmimeKind(&value));
    return value;
}

template <typename D> void impl_IEmailMessage3<D>::SmimeKind(Windows::ApplicationModel::Email::EmailMessageSmimeKind value) const
{
    check_hresult(WINRT_SHIM(IEmailMessage3)->put_SmimeKind(value));
}

template <typename D> hstring impl_IEmailAttachment<D>::FileName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailAttachment)->get_FileName(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailAttachment<D>::FileName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailAttachment)->put_FileName(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IEmailAttachment<D>::Data() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IEmailAttachment)->get_Data(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailAttachment<D>::Data(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IEmailAttachment)->put_Data(get_abi(value)));
}

template <typename D> hstring impl_IEmailAttachment2<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailAttachment2)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailAttachment2<D>::ContentId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailAttachment2)->get_ContentId(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailAttachment2<D>::ContentId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailAttachment2)->put_ContentId(get_abi(value)));
}

template <typename D> hstring impl_IEmailAttachment2<D>::ContentLocation() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailAttachment2)->get_ContentLocation(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailAttachment2<D>::ContentLocation(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailAttachment2)->put_ContentLocation(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Email::EmailAttachmentDownloadState impl_IEmailAttachment2<D>::DownloadState() const
{
    Windows::ApplicationModel::Email::EmailAttachmentDownloadState value {};
    check_hresult(WINRT_SHIM(IEmailAttachment2)->get_DownloadState(&value));
    return value;
}

template <typename D> void impl_IEmailAttachment2<D>::DownloadState(Windows::ApplicationModel::Email::EmailAttachmentDownloadState value) const
{
    check_hresult(WINRT_SHIM(IEmailAttachment2)->put_DownloadState(value));
}

template <typename D> uint64_t impl_IEmailAttachment2<D>::EstimatedDownloadSizeInBytes() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IEmailAttachment2)->get_EstimatedDownloadSizeInBytes(&value));
    return value;
}

template <typename D> void impl_IEmailAttachment2<D>::EstimatedDownloadSizeInBytes(uint64_t value) const
{
    check_hresult(WINRT_SHIM(IEmailAttachment2)->put_EstimatedDownloadSizeInBytes(value));
}

template <typename D> bool impl_IEmailAttachment2<D>::IsFromBaseMessage() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailAttachment2)->get_IsFromBaseMessage(&value));
    return value;
}

template <typename D> bool impl_IEmailAttachment2<D>::IsInline() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailAttachment2)->get_IsInline(&value));
    return value;
}

template <typename D> void impl_IEmailAttachment2<D>::IsInline(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailAttachment2)->put_IsInline(value));
}

template <typename D> hstring impl_IEmailAttachment2<D>::MimeType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailAttachment2)->get_MimeType(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailAttachment2<D>::MimeType(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailAttachment2)->put_MimeType(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Email::EmailAttachment impl_IEmailAttachmentFactory<D>::Create(hstring_view fileName, const Windows::Storage::Streams::IRandomAccessStreamReference & data) const
{
    Windows::ApplicationModel::Email::EmailAttachment result { nullptr };
    check_hresult(WINRT_SHIM(IEmailAttachmentFactory)->abi_Create(get_abi(fileName), get_abi(data), put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailAttachment impl_IEmailAttachmentFactory2<D>::Create(hstring_view fileName, const Windows::Storage::Streams::IRandomAccessStreamReference & data, hstring_view mimeType) const
{
    Windows::ApplicationModel::Email::EmailAttachment result { nullptr };
    check_hresult(WINRT_SHIM(IEmailAttachmentFactory2)->abi_Create(get_abi(fileName), get_abi(data), get_abi(mimeType), put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxChangedDeferral impl_IEmailMailboxChangedEventArgs<D>::GetDeferral() const
{
    Windows::ApplicationModel::Email::EmailMailboxChangedDeferral result { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxChangedEventArgs)->abi_GetDeferral(put_abi(result)));
    return result;
}

template <typename D> void impl_IEmailMailboxChangedDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IEmailMailboxChangedDeferral)->abi_Complete());
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation impl_IEmailMailboxPolicies<D>::AllowedSmimeEncryptionAlgorithmNegotiation() const
{
    Windows::ApplicationModel::Email::EmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation value {};
    check_hresult(WINRT_SHIM(IEmailMailboxPolicies)->get_AllowedSmimeEncryptionAlgorithmNegotiation(&value));
    return value;
}

template <typename D> bool impl_IEmailMailboxPolicies<D>::AllowSmimeSoftCertificates() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxPolicies)->get_AllowSmimeSoftCertificates(&value));
    return value;
}

template <typename D> Windows::Foundation::IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeEncryptionAlgorithm> impl_IEmailMailboxPolicies<D>::RequiredSmimeEncryptionAlgorithm() const
{
    Windows::Foundation::IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeEncryptionAlgorithm> value;
    check_hresult(WINRT_SHIM(IEmailMailboxPolicies)->get_RequiredSmimeEncryptionAlgorithm(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeSigningAlgorithm> impl_IEmailMailboxPolicies<D>::RequiredSmimeSigningAlgorithm() const
{
    Windows::Foundation::IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeSigningAlgorithm> value;
    check_hresult(WINRT_SHIM(IEmailMailboxPolicies)->get_RequiredSmimeSigningAlgorithm(put_abi(value)));
    return value;
}

template <typename D> bool impl_IEmailMailboxPolicies2<D>::MustEncryptSmimeMessages() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxPolicies2)->get_MustEncryptSmimeMessages(&value));
    return value;
}

template <typename D> bool impl_IEmailMailboxPolicies2<D>::MustSignSmimeMessages() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxPolicies2)->get_MustSignSmimeMessages(&value));
    return value;
}

template <typename D> void impl_IEmailMailboxPolicies3<D>::AllowedSmimeEncryptionAlgorithmNegotiation(Windows::ApplicationModel::Email::EmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxPolicies3)->put_AllowedSmimeEncryptionAlgorithmNegotiation(value));
}

template <typename D> void impl_IEmailMailboxPolicies3<D>::AllowSmimeSoftCertificates(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxPolicies3)->put_AllowSmimeSoftCertificates(value));
}

template <typename D> void impl_IEmailMailboxPolicies3<D>::RequiredSmimeEncryptionAlgorithm(const optional<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeEncryptionAlgorithm> & value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxPolicies3)->put_RequiredSmimeEncryptionAlgorithm(get_abi(value)));
}

template <typename D> void impl_IEmailMailboxPolicies3<D>::RequiredSmimeSigningAlgorithm(const optional<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeSigningAlgorithm> & value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxPolicies3)->put_RequiredSmimeSigningAlgorithm(get_abi(value)));
}

template <typename D> void impl_IEmailMailboxPolicies3<D>::MustEncryptSmimeMessages(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxPolicies3)->put_MustEncryptSmimeMessages(value));
}

template <typename D> void impl_IEmailMailboxPolicies3<D>::MustSignSmimeMessages(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxPolicies3)->put_MustSignSmimeMessages(value));
}

template <typename D> bool impl_IEmailMailboxCapabilities<D>::CanForwardMeetings() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities)->get_CanForwardMeetings(&value));
    return value;
}

template <typename D> bool impl_IEmailMailboxCapabilities<D>::CanGetAndSetExternalAutoReplies() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities)->get_CanGetAndSetExternalAutoReplies(&value));
    return value;
}

template <typename D> bool impl_IEmailMailboxCapabilities<D>::CanGetAndSetInternalAutoReplies() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities)->get_CanGetAndSetInternalAutoReplies(&value));
    return value;
}

template <typename D> bool impl_IEmailMailboxCapabilities<D>::CanUpdateMeetingResponses() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities)->get_CanUpdateMeetingResponses(&value));
    return value;
}

template <typename D> bool impl_IEmailMailboxCapabilities<D>::CanServerSearchFolders() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities)->get_CanServerSearchFolders(&value));
    return value;
}

template <typename D> bool impl_IEmailMailboxCapabilities<D>::CanServerSearchMailbox() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities)->get_CanServerSearchMailbox(&value));
    return value;
}

template <typename D> bool impl_IEmailMailboxCapabilities<D>::CanProposeNewTimeForMeetings() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities)->get_CanProposeNewTimeForMeetings(&value));
    return value;
}

template <typename D> bool impl_IEmailMailboxCapabilities<D>::CanSmartSend() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities)->get_CanSmartSend(&value));
    return value;
}

template <typename D> bool impl_IEmailMailboxCapabilities2<D>::CanResolveRecipients() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities2)->get_CanResolveRecipients(&value));
    return value;
}

template <typename D> bool impl_IEmailMailboxCapabilities2<D>::CanValidateCertificates() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities2)->get_CanValidateCertificates(&value));
    return value;
}

template <typename D> bool impl_IEmailMailboxCapabilities2<D>::CanEmptyFolder() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities2)->get_CanEmptyFolder(&value));
    return value;
}

template <typename D> bool impl_IEmailMailboxCapabilities2<D>::CanCreateFolder() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities2)->get_CanCreateFolder(&value));
    return value;
}

template <typename D> bool impl_IEmailMailboxCapabilities2<D>::CanDeleteFolder() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities2)->get_CanDeleteFolder(&value));
    return value;
}

template <typename D> bool impl_IEmailMailboxCapabilities2<D>::CanMoveFolder() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities2)->get_CanMoveFolder(&value));
    return value;
}

template <typename D> void impl_IEmailMailboxCapabilities3<D>::CanForwardMeetings(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities3)->put_CanForwardMeetings(value));
}

template <typename D> void impl_IEmailMailboxCapabilities3<D>::CanGetAndSetExternalAutoReplies(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities3)->put_CanGetAndSetExternalAutoReplies(value));
}

template <typename D> void impl_IEmailMailboxCapabilities3<D>::CanGetAndSetInternalAutoReplies(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities3)->put_CanGetAndSetInternalAutoReplies(value));
}

template <typename D> void impl_IEmailMailboxCapabilities3<D>::CanUpdateMeetingResponses(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities3)->put_CanUpdateMeetingResponses(value));
}

template <typename D> void impl_IEmailMailboxCapabilities3<D>::CanServerSearchFolders(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities3)->put_CanServerSearchFolders(value));
}

template <typename D> void impl_IEmailMailboxCapabilities3<D>::CanServerSearchMailbox(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities3)->put_CanServerSearchMailbox(value));
}

template <typename D> void impl_IEmailMailboxCapabilities3<D>::CanProposeNewTimeForMeetings(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities3)->put_CanProposeNewTimeForMeetings(value));
}

template <typename D> void impl_IEmailMailboxCapabilities3<D>::CanSmartSend(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities3)->put_CanSmartSend(value));
}

template <typename D> void impl_IEmailMailboxCapabilities3<D>::CanResolveRecipients(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities3)->put_CanResolveRecipients(value));
}

template <typename D> void impl_IEmailMailboxCapabilities3<D>::CanValidateCertificates(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities3)->put_CanValidateCertificates(value));
}

template <typename D> void impl_IEmailMailboxCapabilities3<D>::CanEmptyFolder(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities3)->put_CanEmptyFolder(value));
}

template <typename D> void impl_IEmailMailboxCapabilities3<D>::CanCreateFolder(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities3)->put_CanCreateFolder(value));
}

template <typename D> void impl_IEmailMailboxCapabilities3<D>::CanDeleteFolder(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities3)->put_CanDeleteFolder(value));
}

template <typename D> void impl_IEmailMailboxCapabilities3<D>::CanMoveFolder(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxCapabilities3)->put_CanMoveFolder(value));
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxCapabilities impl_IEmailMailbox<D>::Capabilities() const
{
    Windows::ApplicationModel::Email::EmailMailboxCapabilities value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailbox)->get_Capabilities(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxChangeTracker impl_IEmailMailbox<D>::ChangeTracker() const
{
    Windows::ApplicationModel::Email::EmailMailboxChangeTracker value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailbox)->get_ChangeTracker(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailbox<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailbox)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMailbox<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailMailbox)->put_DisplayName(get_abi(value)));
}

template <typename D> hstring impl_IEmailMailbox<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailbox)->get_Id(put_abi(value)));
    return value;
}

template <typename D> bool impl_IEmailMailbox<D>::IsOwnedByCurrentApp() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailbox)->get_IsOwnedByCurrentApp(&value));
    return value;
}

template <typename D> bool impl_IEmailMailbox<D>::IsDataEncryptedUnderLock() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailbox)->get_IsDataEncryptedUnderLock(&value));
    return value;
}

template <typename D> hstring impl_IEmailMailbox<D>::MailAddress() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailbox)->get_MailAddress(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMailbox<D>::MailAddress(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailMailbox)->put_MailAddress(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IEmailMailbox<D>::MailAddressAliases() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IEmailMailbox)->get_MailAddressAliases(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxOtherAppReadAccess impl_IEmailMailbox<D>::OtherAppReadAccess() const
{
    Windows::ApplicationModel::Email::EmailMailboxOtherAppReadAccess value {};
    check_hresult(WINRT_SHIM(IEmailMailbox)->get_OtherAppReadAccess(&value));
    return value;
}

template <typename D> void impl_IEmailMailbox<D>::OtherAppReadAccess(Windows::ApplicationModel::Email::EmailMailboxOtherAppReadAccess value) const
{
    check_hresult(WINRT_SHIM(IEmailMailbox)->put_OtherAppReadAccess(value));
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxOtherAppWriteAccess impl_IEmailMailbox<D>::OtherAppWriteAccess() const
{
    Windows::ApplicationModel::Email::EmailMailboxOtherAppWriteAccess value {};
    check_hresult(WINRT_SHIM(IEmailMailbox)->get_OtherAppWriteAccess(&value));
    return value;
}

template <typename D> void impl_IEmailMailbox<D>::OtherAppWriteAccess(Windows::ApplicationModel::Email::EmailMailboxOtherAppWriteAccess value) const
{
    check_hresult(WINRT_SHIM(IEmailMailbox)->put_OtherAppWriteAccess(value));
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxPolicies impl_IEmailMailbox<D>::Policies() const
{
    Windows::ApplicationModel::Email::EmailMailboxPolicies value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailbox)->get_Policies(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailbox<D>::SourceDisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailbox)->get_SourceDisplayName(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxSyncManager impl_IEmailMailbox<D>::SyncManager() const
{
    Windows::ApplicationModel::Email::EmailMailboxSyncManager value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailbox)->get_SyncManager(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailbox<D>::UserDataAccountId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailbox)->get_UserDataAccountId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailConversationReader impl_IEmailMailbox<D>::GetConversationReader() const
{
    Windows::ApplicationModel::Email::EmailConversationReader result { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_GetConversationReader(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailConversationReader impl_IEmailMailbox<D>::GetConversationReader(const Windows::ApplicationModel::Email::EmailQueryOptions & options) const
{
    Windows::ApplicationModel::Email::EmailConversationReader result { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_GetConversationReaderWithOptions(get_abi(options), put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailMessageReader impl_IEmailMailbox<D>::GetMessageReader() const
{
    Windows::ApplicationModel::Email::EmailMessageReader result { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_GetMessageReader(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailMessageReader impl_IEmailMailbox<D>::GetMessageReader(const Windows::ApplicationModel::Email::EmailQueryOptions & options) const
{
    Windows::ApplicationModel::Email::EmailMessageReader result { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_GetMessageReaderWithOptions(get_abi(options), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailbox<D>::DeleteAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_DeleteAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailConversation> impl_IEmailMailbox<D>::GetConversationAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailConversation> result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_GetConversationAsync(get_abi(id), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> impl_IEmailMailbox<D>::GetFolderAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_GetFolderAsync(get_abi(id), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> impl_IEmailMailbox<D>::GetMessageAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_GetMessageAsync(get_abi(id), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> impl_IEmailMailbox<D>::GetSpecialFolderAsync(Windows::ApplicationModel::Email::EmailSpecialFolderKind folderType) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_GetSpecialFolderAsync(folderType, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailbox<D>::SaveAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_SaveAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailbox<D>::MarkMessageAsSeenAsync(hstring_view messageId) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_MarkMessageAsSeenAsync(get_abi(messageId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailbox<D>::MarkFolderAsSeenAsync(hstring_view folderId) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_MarkFolderAsSeenAsync(get_abi(folderId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailbox<D>::MarkMessageReadAsync(hstring_view messageId, bool isRead) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_MarkMessageReadAsync(get_abi(messageId), isRead, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailbox<D>::ChangeMessageFlagStateAsync(hstring_view messageId, Windows::ApplicationModel::Email::EmailFlagState flagState) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_ChangeMessageFlagStateAsync(get_abi(messageId), flagState, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IEmailMailbox<D>::TryMoveMessageAsync(hstring_view messageId, hstring_view newParentFolderId) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_TryMoveMessageAsync(get_abi(messageId), get_abi(newParentFolderId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IEmailMailbox<D>::TryMoveFolderAsync(hstring_view folderId, hstring_view newParentFolderId) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_TryMoveFolderAsync(get_abi(folderId), get_abi(newParentFolderId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IEmailMailbox<D>::TryMoveFolderAsync(hstring_view folderId, hstring_view newParentFolderId, hstring_view newFolderName) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_TryMoveFolderWithNewNameAsync(get_abi(folderId), get_abi(newParentFolderId), get_abi(newFolderName), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailbox<D>::DeleteMessageAsync(hstring_view messageId) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_DeleteMessageAsync(get_abi(messageId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailbox<D>::MarkFolderSyncEnabledAsync(hstring_view folderId, bool isSyncEnabled) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_MarkFolderSyncEnabledAsync(get_abi(folderId), isSyncEnabled, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailbox<D>::SendMessageAsync(const Windows::ApplicationModel::Email::EmailMessage & message) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_SendMessageAsync(get_abi(message), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailbox<D>::SaveDraftAsync(const Windows::ApplicationModel::Email::EmailMessage & message) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_SaveDraftAsync(get_abi(message), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailbox<D>::DownloadMessageAsync(hstring_view messageId) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_DownloadMessageAsync(get_abi(messageId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailbox<D>::DownloadAttachmentAsync(hstring_view attachmentId) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_DownloadAttachmentAsync(get_abi(attachmentId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> impl_IEmailMailbox<D>::CreateResponseMessageAsync(hstring_view messageId, Windows::ApplicationModel::Email::EmailMessageResponseKind responseType, hstring_view subject, Windows::ApplicationModel::Email::EmailMessageBodyKind responseHeaderType, hstring_view responseHeader) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_CreateResponseMessageAsync(get_abi(messageId), responseType, get_abi(subject), responseHeaderType, get_abi(responseHeader), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IEmailMailbox<D>::TryUpdateMeetingResponseAsync(const Windows::ApplicationModel::Email::EmailMessage & meeting, Windows::ApplicationModel::Email::EmailMeetingResponseType response, hstring_view subject, hstring_view comment, bool sendUpdate) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_TryUpdateMeetingResponseAsync(get_abi(meeting), response, get_abi(subject), get_abi(comment), sendUpdate, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IEmailMailbox<D>::TryForwardMeetingAsync(const Windows::ApplicationModel::Email::EmailMessage & meeting, iterable<Windows::ApplicationModel::Email::EmailRecipient> recipients, hstring_view subject, Windows::ApplicationModel::Email::EmailMessageBodyKind forwardHeaderType, hstring_view forwardHeader, hstring_view comment) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_TryForwardMeetingAsync(get_abi(meeting), get_abi(recipients), get_abi(subject), forwardHeaderType, get_abi(forwardHeader), get_abi(comment), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IEmailMailbox<D>::TryProposeNewTimeForMeetingAsync(const Windows::ApplicationModel::Email::EmailMessage & meeting, const Windows::Foundation::DateTime & newStartTime, const Windows::Foundation::TimeSpan & newDuration, hstring_view subject, hstring_view comment) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_TryProposeNewTimeForMeetingAsync(get_abi(meeting), get_abi(newStartTime), get_abi(newDuration), get_abi(subject), get_abi(comment), put_abi(result)));
    return result;
}

template <typename D> event_token impl_IEmailMailbox<D>::MailboxChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::EmailMailbox, Windows::ApplicationModel::Email::EmailMailboxChangedEventArgs> & pHandler) const
{
    event_token pToken {};
    check_hresult(WINRT_SHIM(IEmailMailbox)->add_MailboxChanged(get_abi(pHandler), &pToken));
    return pToken;
}

template <typename D> event_revoker<IEmailMailbox> impl_IEmailMailbox<D>::MailboxChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::EmailMailbox, Windows::ApplicationModel::Email::EmailMailboxChangedEventArgs> & pHandler) const
{
    return impl::make_event_revoker<D, IEmailMailbox>(this, &ABI::Windows::ApplicationModel::Email::IEmailMailbox::remove_MailboxChanged, MailboxChanged(pHandler));
}

template <typename D> void impl_IEmailMailbox<D>::MailboxChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailMailbox)->remove_MailboxChanged(token));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailbox<D>::SendMessageAsync(const Windows::ApplicationModel::Email::EmailMessage & message, bool smartSend) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_SmartSendMessageAsync(get_abi(message), smartSend, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IEmailMailbox<D>::TrySetAutoReplySettingsAsync(const Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings & autoReplySettings) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_TrySetAutoReplySettingsAsync(get_abi(autoReplySettings), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings> impl_IEmailMailbox<D>::TryGetAutoReplySettingsAsync(Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind requestedFormat) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings> autoReplySettings;
    check_hresult(WINRT_SHIM(IEmailMailbox)->abi_TryGetAutoReplySettingsAsync(requestedFormat, put_abi(autoReplySettings)));
    return autoReplySettings;
}

template <typename D> hstring impl_IEmailMailbox2<D>::LinkedMailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailbox2)->get_LinkedMailboxId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailbox2<D>::NetworkAccountId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailbox2)->get_NetworkAccountId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailbox2<D>::NetworkId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailbox2)->get_NetworkId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailRecipientResolutionResult>> impl_IEmailMailbox3<D>::ResolveRecipientsAsync(iterable<hstring> recipients) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailRecipientResolutionResult>> result;
    check_hresult(WINRT_SHIM(IEmailMailbox3)->abi_ResolveRecipientsAsync(get_abi(recipients), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>> impl_IEmailMailbox3<D>::ValidateCertificatesAsync(iterable<Windows::Security::Cryptography::Certificates::Certificate> certificates) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>> result;
    check_hresult(WINRT_SHIM(IEmailMailbox3)->abi_ValidateCertificatesAsync(get_abi(certificates), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus> impl_IEmailMailbox3<D>::TryEmptyFolderAsync(hstring_view folderId) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus> result;
    check_hresult(WINRT_SHIM(IEmailMailbox3)->abi_TryEmptyFolderAsync(get_abi(folderId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailboxCreateFolderResult> impl_IEmailMailbox3<D>::TryCreateFolderAsync(hstring_view parentFolderId, hstring_view name) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailboxCreateFolderResult> result;
    check_hresult(WINRT_SHIM(IEmailMailbox3)->abi_TryCreateFolderAsync(get_abi(parentFolderId), get_abi(name), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus> impl_IEmailMailbox3<D>::TryDeleteFolderAsync(hstring_view folderId) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus> result;
    check_hresult(WINRT_SHIM(IEmailMailbox3)->abi_TryDeleteFolderAsync(get_abi(folderId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailbox4<D>::RegisterSyncManagerAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailbox4)->abi_RegisterSyncManagerAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailRecipientResolutionStatus impl_IEmailRecipientResolutionResult<D>::Status() const
{
    Windows::ApplicationModel::Email::EmailRecipientResolutionStatus value {};
    check_hresult(WINRT_SHIM(IEmailRecipientResolutionResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> impl_IEmailRecipientResolutionResult<D>::PublicKeys() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> value;
    check_hresult(WINRT_SHIM(IEmailRecipientResolutionResult)->get_PublicKeys(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailRecipientResolutionResult2<D>::Status(Windows::ApplicationModel::Email::EmailRecipientResolutionStatus value) const
{
    check_hresult(WINRT_SHIM(IEmailRecipientResolutionResult2)->put_Status(value));
}

template <typename D> void impl_IEmailRecipientResolutionResult2<D>::SetPublicKeys(iterable<Windows::Security::Cryptography::Certificates::Certificate> value) const
{
    check_hresult(WINRT_SHIM(IEmailRecipientResolutionResult2)->abi_SetPublicKeys(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxCreateFolderStatus impl_IEmailMailboxCreateFolderResult<D>::Status() const
{
    Windows::ApplicationModel::Email::EmailMailboxCreateFolderStatus value {};
    check_hresult(WINRT_SHIM(IEmailMailboxCreateFolderResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailFolder impl_IEmailMailboxCreateFolderResult<D>::Folder() const
{
    Windows::ApplicationModel::Email::EmailFolder value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxCreateFolderResult)->get_Folder(put_abi(value)));
    return value;
}

template <typename D> bool impl_IEmailMailboxAutoReplySettings<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxAutoReplySettings)->get_IsEnabled(&value));
    return value;
}

template <typename D> void impl_IEmailMailboxAutoReplySettings<D>::IsEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxAutoReplySettings)->put_IsEnabled(value));
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind impl_IEmailMailboxAutoReplySettings<D>::ResponseKind() const
{
    Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind value {};
    check_hresult(WINRT_SHIM(IEmailMailboxAutoReplySettings)->get_ResponseKind(&value));
    return value;
}

template <typename D> void impl_IEmailMailboxAutoReplySettings<D>::ResponseKind(Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxAutoReplySettings)->put_ResponseKind(value));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IEmailMailboxAutoReplySettings<D>::StartTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IEmailMailboxAutoReplySettings)->get_StartTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMailboxAutoReplySettings<D>::StartTime(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxAutoReplySettings)->put_StartTime(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IEmailMailboxAutoReplySettings<D>::EndTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IEmailMailboxAutoReplySettings)->get_EndTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMailboxAutoReplySettings<D>::EndTime(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxAutoReplySettings)->put_EndTime(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxAutoReply impl_IEmailMailboxAutoReplySettings<D>::InternalReply() const
{
    Windows::ApplicationModel::Email::EmailMailboxAutoReply value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxAutoReplySettings)->get_InternalReply(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxAutoReply impl_IEmailMailboxAutoReplySettings<D>::KnownExternalReply() const
{
    Windows::ApplicationModel::Email::EmailMailboxAutoReply value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxAutoReplySettings)->get_KnownExternalReply(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxAutoReply impl_IEmailMailboxAutoReplySettings<D>::UnknownExternalReply() const
{
    Windows::ApplicationModel::Email::EmailMailboxAutoReply value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxAutoReplySettings)->get_UnknownExternalReply(put_abi(value)));
    return value;
}

template <typename D> bool impl_IEmailMailboxAutoReply<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxAutoReply)->get_IsEnabled(&value));
    return value;
}

template <typename D> void impl_IEmailMailboxAutoReply<D>::IsEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxAutoReply)->put_IsEnabled(value));
}

template <typename D> hstring impl_IEmailMailboxAutoReply<D>::Response() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxAutoReply)->get_Response(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMailboxAutoReply<D>::Response(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxAutoReply)->put_Response(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxSyncStatus impl_IEmailMailboxSyncManager<D>::Status() const
{
    Windows::ApplicationModel::Email::EmailMailboxSyncStatus value {};
    check_hresult(WINRT_SHIM(IEmailMailboxSyncManager)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IEmailMailboxSyncManager<D>::LastSuccessfulSyncTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IEmailMailboxSyncManager)->get_LastSuccessfulSyncTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IEmailMailboxSyncManager<D>::LastAttemptedSyncTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IEmailMailboxSyncManager)->get_LastAttemptedSyncTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IEmailMailboxSyncManager<D>::SyncAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IEmailMailboxSyncManager)->abi_SyncAsync(put_abi(result)));
    return result;
}

template <typename D> event_token impl_IEmailMailboxSyncManager<D>::SyncStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::EmailMailboxSyncManager, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IEmailMailboxSyncManager)->add_SyncStatusChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IEmailMailboxSyncManager> impl_IEmailMailboxSyncManager<D>::SyncStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::EmailMailboxSyncManager, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IEmailMailboxSyncManager>(this, &ABI::Windows::ApplicationModel::Email::IEmailMailboxSyncManager::remove_SyncStatusChanged, SyncStatusChanged(handler));
}

template <typename D> void impl_IEmailMailboxSyncManager<D>::SyncStatusChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxSyncManager)->remove_SyncStatusChanged(token));
}

template <typename D> void impl_IEmailMailboxSyncManager2<D>::Status(Windows::ApplicationModel::Email::EmailMailboxSyncStatus value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxSyncManager2)->put_Status(value));
}

template <typename D> void impl_IEmailMailboxSyncManager2<D>::LastSuccessfulSyncTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxSyncManager2)->put_LastSuccessfulSyncTime(get_abi(value)));
}

template <typename D> void impl_IEmailMailboxSyncManager2<D>::LastAttemptedSyncTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxSyncManager2)->put_LastAttemptedSyncTime(get_abi(value)));
}

template <typename D> hstring impl_IEmailFolder<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailFolder)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailFolder<D>::RemoteId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailFolder)->get_RemoteId(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailFolder<D>::RemoteId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailFolder)->put_RemoteId(get_abi(value)));
}

template <typename D> hstring impl_IEmailFolder<D>::MailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailFolder)->get_MailboxId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailFolder<D>::ParentFolderId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailFolder)->get_ParentFolderId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailFolder<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailFolder)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailFolder<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailFolder)->put_DisplayName(get_abi(value)));
}

template <typename D> bool impl_IEmailFolder<D>::IsSyncEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailFolder)->get_IsSyncEnabled(&value));
    return value;
}

template <typename D> void impl_IEmailFolder<D>::IsSyncEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailFolder)->put_IsSyncEnabled(value));
}

template <typename D> Windows::Foundation::DateTime impl_IEmailFolder<D>::LastSuccessfulSyncTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IEmailFolder)->get_LastSuccessfulSyncTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailFolder<D>::LastSuccessfulSyncTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IEmailFolder)->put_LastSuccessfulSyncTime(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Email::EmailSpecialFolderKind impl_IEmailFolder<D>::Kind() const
{
    Windows::ApplicationModel::Email::EmailSpecialFolderKind value {};
    check_hresult(WINRT_SHIM(IEmailFolder)->get_Kind(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> impl_IEmailFolder<D>::CreateFolderAsync(hstring_view name) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> result;
    check_hresult(WINRT_SHIM(IEmailFolder)->abi_CreateFolderAsync(get_abi(name), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailFolder<D>::DeleteAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailFolder)->abi_DeleteAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailFolder>> impl_IEmailFolder<D>::FindChildFoldersAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailFolder>> result;
    check_hresult(WINRT_SHIM(IEmailFolder)->abi_FindChildFoldersAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailConversationReader impl_IEmailFolder<D>::GetConversationReader() const
{
    Windows::ApplicationModel::Email::EmailConversationReader result { nullptr };
    check_hresult(WINRT_SHIM(IEmailFolder)->abi_GetConversationReader(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailConversationReader impl_IEmailFolder<D>::GetConversationReader(const Windows::ApplicationModel::Email::EmailQueryOptions & options) const
{
    Windows::ApplicationModel::Email::EmailConversationReader result { nullptr };
    check_hresult(WINRT_SHIM(IEmailFolder)->abi_GetConversationReaderWithOptions(get_abi(options), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> impl_IEmailFolder<D>::GetMessageAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> result;
    check_hresult(WINRT_SHIM(IEmailFolder)->abi_GetMessageAsync(get_abi(id), put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailMessageReader impl_IEmailFolder<D>::GetMessageReader() const
{
    Windows::ApplicationModel::Email::EmailMessageReader result { nullptr };
    check_hresult(WINRT_SHIM(IEmailFolder)->abi_GetMessageReader(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailMessageReader impl_IEmailFolder<D>::GetMessageReader(const Windows::ApplicationModel::Email::EmailQueryOptions & options) const
{
    Windows::ApplicationModel::Email::EmailMessageReader result { nullptr };
    check_hresult(WINRT_SHIM(IEmailFolder)->abi_GetMessageReaderWithOptions(get_abi(options), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailItemCounts> impl_IEmailFolder<D>::GetMessageCountsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailItemCounts> result;
    check_hresult(WINRT_SHIM(IEmailFolder)->abi_GetMessageCountsAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IEmailFolder<D>::TryMoveAsync(const Windows::ApplicationModel::Email::EmailFolder & newParentFolder) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IEmailFolder)->abi_TryMoveAsync(get_abi(newParentFolder), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IEmailFolder<D>::TryMoveAsync(const Windows::ApplicationModel::Email::EmailFolder & newParentFolder, hstring_view newFolderName) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IEmailFolder)->abi_TryMoveWithNewNameAsync(get_abi(newParentFolder), get_abi(newFolderName), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IEmailFolder<D>::TrySaveAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IEmailFolder)->abi_TrySaveAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailFolder<D>::SaveMessageAsync(const Windows::ApplicationModel::Email::EmailMessage & message) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailFolder)->abi_SaveMessageAsync(get_abi(message), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailConversation<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailConversation)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailConversation<D>::MailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailConversation)->get_MailboxId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailFlagState impl_IEmailConversation<D>::FlagState() const
{
    Windows::ApplicationModel::Email::EmailFlagState value {};
    check_hresult(WINRT_SHIM(IEmailConversation)->get_FlagState(&value));
    return value;
}

template <typename D> bool impl_IEmailConversation<D>::HasAttachment() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailConversation)->get_HasAttachment(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailImportance impl_IEmailConversation<D>::Importance() const
{
    Windows::ApplicationModel::Email::EmailImportance value {};
    check_hresult(WINRT_SHIM(IEmailConversation)->get_Importance(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailMessageResponseKind impl_IEmailConversation<D>::LastEmailResponseKind() const
{
    Windows::ApplicationModel::Email::EmailMessageResponseKind value {};
    check_hresult(WINRT_SHIM(IEmailConversation)->get_LastEmailResponseKind(&value));
    return value;
}

template <typename D> uint32_t impl_IEmailConversation<D>::MessageCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IEmailConversation)->get_MessageCount(&value));
    return value;
}

template <typename D> hstring impl_IEmailConversation<D>::MostRecentMessageId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailConversation)->get_MostRecentMessageId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IEmailConversation<D>::MostRecentMessageTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IEmailConversation)->get_MostRecentMessageTime(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailConversation<D>::Preview() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailConversation)->get_Preview(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailRecipient impl_IEmailConversation<D>::LatestSender() const
{
    Windows::ApplicationModel::Email::EmailRecipient value { nullptr };
    check_hresult(WINRT_SHIM(IEmailConversation)->get_LatestSender(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailConversation<D>::Subject() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailConversation)->get_Subject(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IEmailConversation<D>::UnreadMessageCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IEmailConversation)->get_UnreadMessageCount(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage>> impl_IEmailConversation<D>::FindMessagesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage>> result;
    check_hresult(WINRT_SHIM(IEmailConversation)->abi_FindMessagesAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage>> impl_IEmailConversation<D>::FindMessagesAsync(uint32_t count) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage>> result;
    check_hresult(WINRT_SHIM(IEmailConversation)->abi_FindMessagesWithCountAsync(count, put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxActionKind impl_IEmailMailboxAction<D>::Kind() const
{
    Windows::ApplicationModel::Email::EmailMailboxActionKind value {};
    check_hresult(WINRT_SHIM(IEmailMailboxAction)->get_Kind(&value));
    return value;
}

template <typename D> uint64_t impl_IEmailMailboxAction<D>::ChangeNumber() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IEmailMailboxAction)->get_ChangeNumber(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailQuerySearchFields impl_IEmailQueryTextSearch<D>::Fields() const
{
    Windows::ApplicationModel::Email::EmailQuerySearchFields value {};
    check_hresult(WINRT_SHIM(IEmailQueryTextSearch)->get_Fields(&value));
    return value;
}

template <typename D> void impl_IEmailQueryTextSearch<D>::Fields(Windows::ApplicationModel::Email::EmailQuerySearchFields value) const
{
    check_hresult(WINRT_SHIM(IEmailQueryTextSearch)->put_Fields(value));
}

template <typename D> Windows::ApplicationModel::Email::EmailQuerySearchScope impl_IEmailQueryTextSearch<D>::SearchScope() const
{
    Windows::ApplicationModel::Email::EmailQuerySearchScope value {};
    check_hresult(WINRT_SHIM(IEmailQueryTextSearch)->get_SearchScope(&value));
    return value;
}

template <typename D> void impl_IEmailQueryTextSearch<D>::SearchScope(Windows::ApplicationModel::Email::EmailQuerySearchScope value) const
{
    check_hresult(WINRT_SHIM(IEmailQueryTextSearch)->put_SearchScope(value));
}

template <typename D> hstring impl_IEmailQueryTextSearch<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailQueryTextSearch)->get_Text(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailQueryTextSearch<D>::Text(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailQueryTextSearch)->put_Text(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Email::EmailQueryOptions impl_IEmailQueryOptionsFactory<D>::CreateWithText(hstring_view text) const
{
    Windows::ApplicationModel::Email::EmailQueryOptions result { nullptr };
    check_hresult(WINRT_SHIM(IEmailQueryOptionsFactory)->abi_CreateWithText(get_abi(text), put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailQueryOptions impl_IEmailQueryOptionsFactory<D>::CreateWithTextAndFields(hstring_view text, Windows::ApplicationModel::Email::EmailQuerySearchFields fields) const
{
    Windows::ApplicationModel::Email::EmailQueryOptions result { nullptr };
    check_hresult(WINRT_SHIM(IEmailQueryOptionsFactory)->abi_CreateWithTextAndFields(get_abi(text), fields, put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailQueryTextSearch impl_IEmailQueryOptions<D>::TextSearch() const
{
    Windows::ApplicationModel::Email::EmailQueryTextSearch value { nullptr };
    check_hresult(WINRT_SHIM(IEmailQueryOptions)->get_TextSearch(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailQuerySortDirection impl_IEmailQueryOptions<D>::SortDirection() const
{
    Windows::ApplicationModel::Email::EmailQuerySortDirection value {};
    check_hresult(WINRT_SHIM(IEmailQueryOptions)->get_SortDirection(&value));
    return value;
}

template <typename D> void impl_IEmailQueryOptions<D>::SortDirection(Windows::ApplicationModel::Email::EmailQuerySortDirection value) const
{
    check_hresult(WINRT_SHIM(IEmailQueryOptions)->put_SortDirection(value));
}

template <typename D> Windows::ApplicationModel::Email::EmailQuerySortProperty impl_IEmailQueryOptions<D>::SortProperty() const
{
    Windows::ApplicationModel::Email::EmailQuerySortProperty value {};
    check_hresult(WINRT_SHIM(IEmailQueryOptions)->get_SortProperty(&value));
    return value;
}

template <typename D> void impl_IEmailQueryOptions<D>::SortProperty(Windows::ApplicationModel::Email::EmailQuerySortProperty value) const
{
    check_hresult(WINRT_SHIM(IEmailQueryOptions)->put_SortProperty(value));
}

template <typename D> Windows::ApplicationModel::Email::EmailQueryKind impl_IEmailQueryOptions<D>::Kind() const
{
    Windows::ApplicationModel::Email::EmailQueryKind value {};
    check_hresult(WINRT_SHIM(IEmailQueryOptions)->get_Kind(&value));
    return value;
}

template <typename D> void impl_IEmailQueryOptions<D>::Kind(Windows::ApplicationModel::Email::EmailQueryKind value) const
{
    check_hresult(WINRT_SHIM(IEmailQueryOptions)->put_Kind(value));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IEmailQueryOptions<D>::FolderIds() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IEmailQueryOptions)->get_FolderIds(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailConversation> impl_IEmailConversationBatch<D>::Conversations() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailConversation> value;
    check_hresult(WINRT_SHIM(IEmailConversationBatch)->get_Conversations(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailBatchStatus impl_IEmailConversationBatch<D>::Status() const
{
    Windows::ApplicationModel::Email::EmailBatchStatus value {};
    check_hresult(WINRT_SHIM(IEmailConversationBatch)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailConversationBatch> impl_IEmailConversationReader<D>::ReadBatchAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailConversationBatch> result;
    check_hresult(WINRT_SHIM(IEmailConversationReader)->abi_ReadBatchAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage> impl_IEmailMessageBatch<D>::Messages() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage> value;
    check_hresult(WINRT_SHIM(IEmailMessageBatch)->get_Messages(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailBatchStatus impl_IEmailMessageBatch<D>::Status() const
{
    Windows::ApplicationModel::Email::EmailBatchStatus value {};
    check_hresult(WINRT_SHIM(IEmailMessageBatch)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessageBatch> impl_IEmailMessageReader<D>::ReadBatchAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessageBatch> result;
    check_hresult(WINRT_SHIM(IEmailMessageReader)->abi_ReadBatchAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxChangeType impl_IEmailMailboxChange<D>::ChangeType() const
{
    Windows::ApplicationModel::Email::EmailMailboxChangeType value {};
    check_hresult(WINRT_SHIM(IEmailMailboxChange)->get_ChangeType(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailMailboxAction> impl_IEmailMailboxChange<D>::MailboxActions() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailMailboxAction> value;
    check_hresult(WINRT_SHIM(IEmailMailboxChange)->get_MailboxActions(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailMessage impl_IEmailMailboxChange<D>::Message() const
{
    Windows::ApplicationModel::Email::EmailMessage value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxChange)->get_Message(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailFolder impl_IEmailMailboxChange<D>::Folder() const
{
    Windows::ApplicationModel::Email::EmailFolder value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxChange)->get_Folder(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMailboxChangeReader<D>::AcceptChanges() const
{
    check_hresult(WINRT_SHIM(IEmailMailboxChangeReader)->abi_AcceptChanges());
}

template <typename D> void impl_IEmailMailboxChangeReader<D>::AcceptChangesThrough(const Windows::ApplicationModel::Email::EmailMailboxChange & lastChangeToAcknowledge) const
{
    check_hresult(WINRT_SHIM(IEmailMailboxChangeReader)->abi_AcceptChangesThrough(get_abi(lastChangeToAcknowledge)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailboxChange>> impl_IEmailMailboxChangeReader<D>::ReadBatchAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailboxChange>> value;
    check_hresult(WINRT_SHIM(IEmailMailboxChangeReader)->abi_ReadBatchAsync(put_abi(value)));
    return value;
}

template <typename D> bool impl_IEmailMailboxChangeTracker<D>::IsTracking() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxChangeTracker)->get_IsTracking(&value));
    return value;
}

template <typename D> void impl_IEmailMailboxChangeTracker<D>::Enable() const
{
    check_hresult(WINRT_SHIM(IEmailMailboxChangeTracker)->abi_Enable());
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxChangeReader impl_IEmailMailboxChangeTracker<D>::GetChangeReader() const
{
    Windows::ApplicationModel::Email::EmailMailboxChangeReader value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxChangeTracker)->abi_GetChangeReader(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMailboxChangeTracker<D>::Reset() const
{
    check_hresult(WINRT_SHIM(IEmailMailboxChangeTracker)->abi_Reset());
}

template <typename D> bool impl_IEmailMeetingInfo<D>::AllowNewTimeProposal() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->get_AllowNewTimeProposal(&value));
    return value;
}

template <typename D> void impl_IEmailMeetingInfo<D>::AllowNewTimeProposal(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->put_AllowNewTimeProposal(value));
}

template <typename D> hstring impl_IEmailMeetingInfo<D>::AppointmentRoamingId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->get_AppointmentRoamingId(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMeetingInfo<D>::AppointmentRoamingId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->put_AppointmentRoamingId(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IEmailMeetingInfo<D>::AppointmentOriginalStartTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->get_AppointmentOriginalStartTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMeetingInfo<D>::AppointmentOriginalStartTime(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->put_AppointmentOriginalStartTime(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IEmailMeetingInfo<D>::Duration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMeetingInfo<D>::Duration(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->put_Duration(get_abi(value)));
}

template <typename D> bool impl_IEmailMeetingInfo<D>::IsAllDay() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->get_IsAllDay(&value));
    return value;
}

template <typename D> void impl_IEmailMeetingInfo<D>::IsAllDay(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->put_IsAllDay(value));
}

template <typename D> bool impl_IEmailMeetingInfo<D>::IsResponseRequested() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->get_IsResponseRequested(&value));
    return value;
}

template <typename D> void impl_IEmailMeetingInfo<D>::IsResponseRequested(bool value) const
{
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->put_IsResponseRequested(value));
}

template <typename D> hstring impl_IEmailMeetingInfo<D>::Location() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->get_Location(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMeetingInfo<D>::Location(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->put_Location(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IEmailMeetingInfo<D>::ProposedStartTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> proposedStartTime;
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->get_ProposedStartTime(put_abi(proposedStartTime)));
    return proposedStartTime;
}

template <typename D> void impl_IEmailMeetingInfo<D>::ProposedStartTime(const optional<Windows::Foundation::DateTime> & proposedStartTime) const
{
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->put_ProposedStartTime(get_abi(proposedStartTime)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IEmailMeetingInfo<D>::ProposedDuration() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> duration;
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->get_ProposedDuration(put_abi(duration)));
    return duration;
}

template <typename D> void impl_IEmailMeetingInfo<D>::ProposedDuration(const optional<Windows::Foundation::TimeSpan> & duration) const
{
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->put_ProposedDuration(get_abi(duration)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IEmailMeetingInfo<D>::RecurrenceStartTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->get_RecurrenceStartTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMeetingInfo<D>::RecurrenceStartTime(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->put_RecurrenceStartTime(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentRecurrence impl_IEmailMeetingInfo<D>::Recurrence() const
{
    Windows::ApplicationModel::Appointments::AppointmentRecurrence value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->get_Recurrence(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMeetingInfo<D>::Recurrence(const Windows::ApplicationModel::Appointments::AppointmentRecurrence & value) const
{
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->put_Recurrence(get_abi(value)));
}

template <typename D> uint64_t impl_IEmailMeetingInfo<D>::RemoteChangeNumber() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->get_RemoteChangeNumber(&value));
    return value;
}

template <typename D> void impl_IEmailMeetingInfo<D>::RemoteChangeNumber(uint64_t value) const
{
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->put_RemoteChangeNumber(value));
}

template <typename D> Windows::Foundation::DateTime impl_IEmailMeetingInfo<D>::StartTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->get_StartTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IEmailMeetingInfo<D>::StartTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IEmailMeetingInfo)->put_StartTime(get_abi(value)));
}

template <typename D> bool impl_IEmailMeetingInfo2<D>::IsReportedOutOfDateByServer() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMeetingInfo2)->get_IsReportedOutOfDateByServer(&value));
    return value;
}

template <typename D> uint32_t impl_IEmailItemCounts<D>::Flagged() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IEmailItemCounts)->get_Flagged(&value));
    return value;
}

template <typename D> uint32_t impl_IEmailItemCounts<D>::Important() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IEmailItemCounts)->get_Important(&value));
    return value;
}

template <typename D> uint32_t impl_IEmailItemCounts<D>::Total() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IEmailItemCounts)->get_Total(&value));
    return value;
}

template <typename D> uint32_t impl_IEmailItemCounts<D>::Unread() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IEmailItemCounts)->get_Unread(&value));
    return value;
}

inline EmailAttachment::EmailAttachment() :
    EmailAttachment(activate_instance<EmailAttachment>())
{}

inline EmailAttachment::EmailAttachment(hstring_view fileName, const Windows::Storage::Streams::IRandomAccessStreamReference & data) :
    EmailAttachment(get_activation_factory<EmailAttachment, IEmailAttachmentFactory>().Create(fileName, data))
{}

inline EmailAttachment::EmailAttachment(hstring_view fileName, const Windows::Storage::Streams::IRandomAccessStreamReference & data, hstring_view mimeType) :
    EmailAttachment(get_activation_factory<EmailAttachment, IEmailAttachmentFactory2>().Create(fileName, data, mimeType))
{}

inline EmailIrmInfo::EmailIrmInfo() :
    EmailIrmInfo(activate_instance<EmailIrmInfo>())
{}

inline EmailIrmInfo::EmailIrmInfo(const Windows::Foundation::DateTime & expiration, const Windows::ApplicationModel::Email::EmailIrmTemplate & irmTemplate) :
    EmailIrmInfo(get_activation_factory<EmailIrmInfo, IEmailIrmInfoFactory>().Create(expiration, irmTemplate))
{}

inline EmailIrmTemplate::EmailIrmTemplate() :
    EmailIrmTemplate(activate_instance<EmailIrmTemplate>())
{}

inline EmailIrmTemplate::EmailIrmTemplate(hstring_view id, hstring_view name, hstring_view description) :
    EmailIrmTemplate(get_activation_factory<EmailIrmTemplate, IEmailIrmTemplateFactory>().Create(id, name, description))
{}

inline EmailMailboxAutoReplySettings::EmailMailboxAutoReplySettings() :
    EmailMailboxAutoReplySettings(activate_instance<EmailMailboxAutoReplySettings>())
{}

inline Windows::Foundation::IAsyncAction EmailManager::ShowComposeNewEmailAsync(const Windows::ApplicationModel::Email::EmailMessage & message)
{
    return get_activation_factory<EmailManager, IEmailManagerStatics>().ShowComposeNewEmailAsync(message);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailStore> EmailManager::RequestStoreAsync(Windows::ApplicationModel::Email::EmailStoreAccessType accessType)
{
    return get_activation_factory<EmailManager, IEmailManagerStatics2>().RequestStoreAsync(accessType);
}

inline Windows::ApplicationModel::Email::EmailManagerForUser EmailManager::GetForUser(const Windows::System::User & user)
{
    return get_activation_factory<EmailManager, IEmailManagerStatics3>().GetForUser(user);
}

inline EmailMeetingInfo::EmailMeetingInfo() :
    EmailMeetingInfo(activate_instance<EmailMeetingInfo>())
{}

inline EmailMessage::EmailMessage() :
    EmailMessage(activate_instance<EmailMessage>())
{}

inline EmailQueryOptions::EmailQueryOptions() :
    EmailQueryOptions(activate_instance<EmailQueryOptions>())
{}

inline EmailQueryOptions::EmailQueryOptions(hstring_view text) :
    EmailQueryOptions(get_activation_factory<EmailQueryOptions, IEmailQueryOptionsFactory>().CreateWithText(text))
{}

inline EmailQueryOptions::EmailQueryOptions(hstring_view text, Windows::ApplicationModel::Email::EmailQuerySearchFields fields) :
    EmailQueryOptions(get_activation_factory<EmailQueryOptions, IEmailQueryOptionsFactory>().CreateWithTextAndFields(text, fields))
{}

inline EmailRecipient::EmailRecipient() :
    EmailRecipient(activate_instance<EmailRecipient>())
{}

inline EmailRecipient::EmailRecipient(hstring_view address) :
    EmailRecipient(get_activation_factory<EmailRecipient, IEmailRecipientFactory>().Create(address))
{}

inline EmailRecipient::EmailRecipient(hstring_view address, hstring_view name) :
    EmailRecipient(get_activation_factory<EmailRecipient, IEmailRecipientFactory>().CreateWithName(address, name))
{}

inline EmailRecipientResolutionResult::EmailRecipientResolutionResult() :
    EmailRecipientResolutionResult(activate_instance<EmailRecipientResolutionResult>())
{}

}

}
#pragma warning(pop)
