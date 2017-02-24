// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.ApplicationModel.Email.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.ApplicationModel.Email.DataProvider.3.h"
#include "Windows.ApplicationModel.Email.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>
{
    HRESULT __stdcall add_MailboxSyncRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MailboxSyncRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MailboxSyncRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MailboxSyncRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DownloadMessageRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DownloadMessageRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DownloadMessageRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DownloadMessageRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DownloadAttachmentRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DownloadAttachmentRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DownloadAttachmentRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DownloadAttachmentRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CreateFolderRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CreateFolderRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CreateFolderRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CreateFolderRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DeleteFolderRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DeleteFolderRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DeleteFolderRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeleteFolderRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_EmptyFolderRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().EmptyFolderRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_EmptyFolderRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EmptyFolderRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MoveFolderRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MoveFolderRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MoveFolderRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MoveFolderRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_UpdateMeetingResponseRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().UpdateMeetingResponseRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_UpdateMeetingResponseRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateMeetingResponseRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ForwardMeetingRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ForwardMeetingRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ForwardMeetingRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ForwardMeetingRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ProposeNewTimeForMeetingRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ProposeNewTimeForMeetingRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ProposeNewTimeForMeetingRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProposeNewTimeForMeetingRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SetAutoReplySettingsRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SetAutoReplySettingsRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SetAutoReplySettingsRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetAutoReplySettingsRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_GetAutoReplySettingsRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().GetAutoReplySettingsRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_GetAutoReplySettingsRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetAutoReplySettingsRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ResolveRecipientsRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ResolveRecipientsRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ResolveRecipientsRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResolveRecipientsRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ValidateCertificatesRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ValidateCertificatesRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ValidateCertificatesRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ValidateCertificatesRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ServerSearchReadBatchRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ServerSearchReadBatchRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ServerSearchReadBatchRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServerSearchReadBatchRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderTriggerDetails> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderTriggerDetails>
{
    HRESULT __stdcall get_Connection(impl::abi_arg_out<Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Connection());
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest>
{
    HRESULT __stdcall get_EmailMailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMailboxId());
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

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailFolder> folder, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailFolder *>(&folder)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(Windows::ApplicationModel::Email::EmailMailboxCreateFolderStatus status, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync(status));
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest> value) noexcept override
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequest> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequest>
{
    HRESULT __stdcall get_EmailMailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EmailFolderId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailFolderId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus status, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync(status));
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequest> value) noexcept override
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest>
{
    HRESULT __stdcall get_EmailMailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EmailMessageId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMessageId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EmailAttachmentId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailAttachmentId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync());
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest> value) noexcept override
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequest> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequest>
{
    HRESULT __stdcall get_EmailMailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EmailMessageId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMessageId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync());
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequest> value) noexcept override
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequest> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequest>
{
    HRESULT __stdcall get_EmailMailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EmailFolderId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailFolderId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus status, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync(status));
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequest> value) noexcept override
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest>
{
    HRESULT __stdcall get_EmailMailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EmailMessageId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMessageId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Recipients(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailRecipient>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Recipients());
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

    HRESULT __stdcall get_ForwardHeaderType(Windows::ApplicationModel::Email::EmailMessageBodyKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ForwardHeaderType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ForwardHeader(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ForwardHeader());
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

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync());
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest> value) noexcept override
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequest> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequest>
{
    HRESULT __stdcall get_EmailMailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequestedFormat(Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestedFormat());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_in<Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings> autoReplySettings, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync(*reinterpret_cast<const Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings *>(&autoReplySettings)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync());
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequest> value) noexcept override
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest>
{
    HRESULT __stdcall get_EmailMailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EmailFolderId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailFolderId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NewParentFolderId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewParentFolderId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NewFolderName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewFolderName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync());
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest> value) noexcept override
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest>
{
    HRESULT __stdcall get_EmailMailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EmailMessageId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMessageId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NewStartTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewStartTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NewDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewDuration());
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync());
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest> value) noexcept override
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequest> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequest>
{
    HRESULT __stdcall get_EmailMailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Recipients(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Recipients());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Email::EmailRecipientResolutionResult>> resolutionResults, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Email::EmailRecipientResolutionResult> *>(&resolutionResults)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync());
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequest> value) noexcept override
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest>
{
    HRESULT __stdcall get_SessionId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SessionId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EmailMailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EmailFolderId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailFolderId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Options(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailQueryOptions> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Options());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuggestedBatchSize(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SuggestedBatchSize());
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(Windows::ApplicationModel::Email::EmailBatchStatus batchStatus, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync(batchStatus));
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest> value) noexcept override
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequest> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequest>
{
    HRESULT __stdcall get_EmailMailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoReplySettings(impl::abi_arg_out<Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoReplySettings());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync());
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequest> value) noexcept override
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequest> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequest>
{
    HRESULT __stdcall get_EmailMailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync());
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequest> value) noexcept override
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest>
{
    HRESULT __stdcall get_EmailMailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EmailMessageId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMessageId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Response(Windows::ApplicationModel::Email::EmailMeetingResponseType * response) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *response = detach_abi(this->shim().Response());
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall get_SendUpdate(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SendUpdate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync());
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest> value) noexcept override
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequest> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequest>
{
    HRESULT __stdcall get_EmailMailboxId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailMailboxId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Certificates(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Certificates());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>> validationStatuses, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus> *>(&validationStatuses)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync());
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
struct produce<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequest> value) noexcept override
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
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

}

namespace Windows::ApplicationModel::Email::DataProvider {

template <typename D> Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection impl_IEmailDataProviderTriggerDetails<D>::Connection() const
{
    Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection value { nullptr };
    check_hresult(WINRT_SHIM(IEmailDataProviderTriggerDetails)->get_Connection(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IEmailDataProviderConnection<D>::MailboxSyncRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->add_MailboxSyncRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IEmailDataProviderConnection> impl_IEmailDataProviderConnection<D>::MailboxSyncRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IEmailDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection::remove_MailboxSyncRequested, MailboxSyncRequested(handler));
}

template <typename D> void impl_IEmailDataProviderConnection<D>::MailboxSyncRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->remove_MailboxSyncRequested(token));
}

template <typename D> event_token impl_IEmailDataProviderConnection<D>::DownloadMessageRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->add_DownloadMessageRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IEmailDataProviderConnection> impl_IEmailDataProviderConnection<D>::DownloadMessageRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IEmailDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection::remove_DownloadMessageRequested, DownloadMessageRequested(handler));
}

template <typename D> void impl_IEmailDataProviderConnection<D>::DownloadMessageRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->remove_DownloadMessageRequested(token));
}

template <typename D> event_token impl_IEmailDataProviderConnection<D>::DownloadAttachmentRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->add_DownloadAttachmentRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IEmailDataProviderConnection> impl_IEmailDataProviderConnection<D>::DownloadAttachmentRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IEmailDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection::remove_DownloadAttachmentRequested, DownloadAttachmentRequested(handler));
}

template <typename D> void impl_IEmailDataProviderConnection<D>::DownloadAttachmentRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->remove_DownloadAttachmentRequested(token));
}

template <typename D> event_token impl_IEmailDataProviderConnection<D>::CreateFolderRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->add_CreateFolderRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IEmailDataProviderConnection> impl_IEmailDataProviderConnection<D>::CreateFolderRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IEmailDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection::remove_CreateFolderRequested, CreateFolderRequested(handler));
}

template <typename D> void impl_IEmailDataProviderConnection<D>::CreateFolderRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->remove_CreateFolderRequested(token));
}

template <typename D> event_token impl_IEmailDataProviderConnection<D>::DeleteFolderRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->add_DeleteFolderRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IEmailDataProviderConnection> impl_IEmailDataProviderConnection<D>::DeleteFolderRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IEmailDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection::remove_DeleteFolderRequested, DeleteFolderRequested(handler));
}

template <typename D> void impl_IEmailDataProviderConnection<D>::DeleteFolderRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->remove_DeleteFolderRequested(token));
}

template <typename D> event_token impl_IEmailDataProviderConnection<D>::EmptyFolderRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->add_EmptyFolderRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IEmailDataProviderConnection> impl_IEmailDataProviderConnection<D>::EmptyFolderRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IEmailDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection::remove_EmptyFolderRequested, EmptyFolderRequested(handler));
}

template <typename D> void impl_IEmailDataProviderConnection<D>::EmptyFolderRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->remove_EmptyFolderRequested(token));
}

template <typename D> event_token impl_IEmailDataProviderConnection<D>::MoveFolderRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->add_MoveFolderRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IEmailDataProviderConnection> impl_IEmailDataProviderConnection<D>::MoveFolderRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IEmailDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection::remove_MoveFolderRequested, MoveFolderRequested(handler));
}

template <typename D> void impl_IEmailDataProviderConnection<D>::MoveFolderRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->remove_MoveFolderRequested(token));
}

template <typename D> event_token impl_IEmailDataProviderConnection<D>::UpdateMeetingResponseRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->add_UpdateMeetingResponseRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IEmailDataProviderConnection> impl_IEmailDataProviderConnection<D>::UpdateMeetingResponseRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IEmailDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection::remove_UpdateMeetingResponseRequested, UpdateMeetingResponseRequested(handler));
}

template <typename D> void impl_IEmailDataProviderConnection<D>::UpdateMeetingResponseRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->remove_UpdateMeetingResponseRequested(token));
}

template <typename D> event_token impl_IEmailDataProviderConnection<D>::ForwardMeetingRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->add_ForwardMeetingRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IEmailDataProviderConnection> impl_IEmailDataProviderConnection<D>::ForwardMeetingRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IEmailDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection::remove_ForwardMeetingRequested, ForwardMeetingRequested(handler));
}

template <typename D> void impl_IEmailDataProviderConnection<D>::ForwardMeetingRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->remove_ForwardMeetingRequested(token));
}

template <typename D> event_token impl_IEmailDataProviderConnection<D>::ProposeNewTimeForMeetingRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->add_ProposeNewTimeForMeetingRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IEmailDataProviderConnection> impl_IEmailDataProviderConnection<D>::ProposeNewTimeForMeetingRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IEmailDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection::remove_ProposeNewTimeForMeetingRequested, ProposeNewTimeForMeetingRequested(handler));
}

template <typename D> void impl_IEmailDataProviderConnection<D>::ProposeNewTimeForMeetingRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->remove_ProposeNewTimeForMeetingRequested(token));
}

template <typename D> event_token impl_IEmailDataProviderConnection<D>::SetAutoReplySettingsRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->add_SetAutoReplySettingsRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IEmailDataProviderConnection> impl_IEmailDataProviderConnection<D>::SetAutoReplySettingsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IEmailDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection::remove_SetAutoReplySettingsRequested, SetAutoReplySettingsRequested(handler));
}

template <typename D> void impl_IEmailDataProviderConnection<D>::SetAutoReplySettingsRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->remove_SetAutoReplySettingsRequested(token));
}

template <typename D> event_token impl_IEmailDataProviderConnection<D>::GetAutoReplySettingsRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->add_GetAutoReplySettingsRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IEmailDataProviderConnection> impl_IEmailDataProviderConnection<D>::GetAutoReplySettingsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IEmailDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection::remove_GetAutoReplySettingsRequested, GetAutoReplySettingsRequested(handler));
}

template <typename D> void impl_IEmailDataProviderConnection<D>::GetAutoReplySettingsRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->remove_GetAutoReplySettingsRequested(token));
}

template <typename D> event_token impl_IEmailDataProviderConnection<D>::ResolveRecipientsRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->add_ResolveRecipientsRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IEmailDataProviderConnection> impl_IEmailDataProviderConnection<D>::ResolveRecipientsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IEmailDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection::remove_ResolveRecipientsRequested, ResolveRecipientsRequested(handler));
}

template <typename D> void impl_IEmailDataProviderConnection<D>::ResolveRecipientsRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->remove_ResolveRecipientsRequested(token));
}

template <typename D> event_token impl_IEmailDataProviderConnection<D>::ValidateCertificatesRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->add_ValidateCertificatesRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IEmailDataProviderConnection> impl_IEmailDataProviderConnection<D>::ValidateCertificatesRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IEmailDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection::remove_ValidateCertificatesRequested, ValidateCertificatesRequested(handler));
}

template <typename D> void impl_IEmailDataProviderConnection<D>::ValidateCertificatesRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->remove_ValidateCertificatesRequested(token));
}

template <typename D> event_token impl_IEmailDataProviderConnection<D>::ServerSearchReadBatchRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->add_ServerSearchReadBatchRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IEmailDataProviderConnection> impl_IEmailDataProviderConnection<D>::ServerSearchReadBatchRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IEmailDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection::remove_ServerSearchReadBatchRequested, ServerSearchReadBatchRequested(handler));
}

template <typename D> void impl_IEmailDataProviderConnection<D>::ServerSearchReadBatchRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->remove_ServerSearchReadBatchRequested(token));
}

template <typename D> void impl_IEmailDataProviderConnection<D>::Start() const
{
    check_hresult(WINRT_SHIM(IEmailDataProviderConnection)->abi_Start());
}

template <typename D> hstring impl_IEmailMailboxSyncManagerSyncRequest<D>::EmailMailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxSyncManagerSyncRequest)->get_EmailMailboxId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxSyncManagerSyncRequest<D>::ReportCompletedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxSyncManagerSyncRequest)->abi_ReportCompletedAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxSyncManagerSyncRequest<D>::ReportFailedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxSyncManagerSyncRequest)->abi_ReportFailedAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailMailboxDownloadMessageRequest<D>::EmailMailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxDownloadMessageRequest)->get_EmailMailboxId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxDownloadMessageRequest<D>::EmailMessageId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxDownloadMessageRequest)->get_EmailMessageId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxDownloadMessageRequest<D>::ReportCompletedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxDownloadMessageRequest)->abi_ReportCompletedAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxDownloadMessageRequest<D>::ReportFailedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxDownloadMessageRequest)->abi_ReportFailedAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailMailboxDownloadAttachmentRequest<D>::EmailMailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxDownloadAttachmentRequest)->get_EmailMailboxId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxDownloadAttachmentRequest<D>::EmailMessageId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxDownloadAttachmentRequest)->get_EmailMessageId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxDownloadAttachmentRequest<D>::EmailAttachmentId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxDownloadAttachmentRequest)->get_EmailAttachmentId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxDownloadAttachmentRequest<D>::ReportCompletedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxDownloadAttachmentRequest)->abi_ReportCompletedAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxDownloadAttachmentRequest<D>::ReportFailedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxDownloadAttachmentRequest)->abi_ReportFailedAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailMailboxCreateFolderRequest<D>::EmailMailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxCreateFolderRequest)->get_EmailMailboxId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxCreateFolderRequest<D>::ParentFolderId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxCreateFolderRequest)->get_ParentFolderId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxCreateFolderRequest<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxCreateFolderRequest)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxCreateFolderRequest<D>::ReportCompletedAsync(const Windows::ApplicationModel::Email::EmailFolder & folder) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxCreateFolderRequest)->abi_ReportCompletedAsync(get_abi(folder), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxCreateFolderRequest<D>::ReportFailedAsync(Windows::ApplicationModel::Email::EmailMailboxCreateFolderStatus status) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxCreateFolderRequest)->abi_ReportFailedAsync(status, put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailMailboxDeleteFolderRequest<D>::EmailMailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxDeleteFolderRequest)->get_EmailMailboxId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxDeleteFolderRequest<D>::EmailFolderId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxDeleteFolderRequest)->get_EmailFolderId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxDeleteFolderRequest<D>::ReportCompletedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxDeleteFolderRequest)->abi_ReportCompletedAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxDeleteFolderRequest<D>::ReportFailedAsync(Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus status) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxDeleteFolderRequest)->abi_ReportFailedAsync(status, put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailMailboxEmptyFolderRequest<D>::EmailMailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxEmptyFolderRequest)->get_EmailMailboxId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxEmptyFolderRequest<D>::EmailFolderId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxEmptyFolderRequest)->get_EmailFolderId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxEmptyFolderRequest<D>::ReportCompletedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxEmptyFolderRequest)->abi_ReportCompletedAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxEmptyFolderRequest<D>::ReportFailedAsync(Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus status) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxEmptyFolderRequest)->abi_ReportFailedAsync(status, put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailMailboxMoveFolderRequest<D>::EmailMailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxMoveFolderRequest)->get_EmailMailboxId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxMoveFolderRequest<D>::EmailFolderId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxMoveFolderRequest)->get_EmailFolderId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxMoveFolderRequest<D>::NewParentFolderId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxMoveFolderRequest)->get_NewParentFolderId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxMoveFolderRequest<D>::NewFolderName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxMoveFolderRequest)->get_NewFolderName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxMoveFolderRequest<D>::ReportCompletedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxMoveFolderRequest)->abi_ReportCompletedAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxMoveFolderRequest<D>::ReportFailedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxMoveFolderRequest)->abi_ReportFailedAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailMailboxUpdateMeetingResponseRequest<D>::EmailMailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxUpdateMeetingResponseRequest)->get_EmailMailboxId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxUpdateMeetingResponseRequest<D>::EmailMessageId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxUpdateMeetingResponseRequest)->get_EmailMessageId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailMeetingResponseType impl_IEmailMailboxUpdateMeetingResponseRequest<D>::Response() const
{
    Windows::ApplicationModel::Email::EmailMeetingResponseType response {};
    check_hresult(WINRT_SHIM(IEmailMailboxUpdateMeetingResponseRequest)->get_Response(&response));
    return response;
}

template <typename D> hstring impl_IEmailMailboxUpdateMeetingResponseRequest<D>::Subject() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxUpdateMeetingResponseRequest)->get_Subject(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxUpdateMeetingResponseRequest<D>::Comment() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxUpdateMeetingResponseRequest)->get_Comment(put_abi(value)));
    return value;
}

template <typename D> bool impl_IEmailMailboxUpdateMeetingResponseRequest<D>::SendUpdate() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEmailMailboxUpdateMeetingResponseRequest)->get_SendUpdate(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxUpdateMeetingResponseRequest<D>::ReportCompletedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxUpdateMeetingResponseRequest)->abi_ReportCompletedAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxUpdateMeetingResponseRequest<D>::ReportFailedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxUpdateMeetingResponseRequest)->abi_ReportFailedAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailMailboxForwardMeetingRequest<D>::EmailMailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxForwardMeetingRequest)->get_EmailMailboxId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxForwardMeetingRequest<D>::EmailMessageId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxForwardMeetingRequest)->get_EmailMessageId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailRecipient> impl_IEmailMailboxForwardMeetingRequest<D>::Recipients() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailRecipient> value;
    check_hresult(WINRT_SHIM(IEmailMailboxForwardMeetingRequest)->get_Recipients(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxForwardMeetingRequest<D>::Subject() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxForwardMeetingRequest)->get_Subject(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailMessageBodyKind impl_IEmailMailboxForwardMeetingRequest<D>::ForwardHeaderType() const
{
    Windows::ApplicationModel::Email::EmailMessageBodyKind value {};
    check_hresult(WINRT_SHIM(IEmailMailboxForwardMeetingRequest)->get_ForwardHeaderType(&value));
    return value;
}

template <typename D> hstring impl_IEmailMailboxForwardMeetingRequest<D>::ForwardHeader() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxForwardMeetingRequest)->get_ForwardHeader(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxForwardMeetingRequest<D>::Comment() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxForwardMeetingRequest)->get_Comment(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxForwardMeetingRequest<D>::ReportCompletedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxForwardMeetingRequest)->abi_ReportCompletedAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxForwardMeetingRequest<D>::ReportFailedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxForwardMeetingRequest)->abi_ReportFailedAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailMailboxProposeNewTimeForMeetingRequest<D>::EmailMailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxProposeNewTimeForMeetingRequest)->get_EmailMailboxId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxProposeNewTimeForMeetingRequest<D>::EmailMessageId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxProposeNewTimeForMeetingRequest)->get_EmailMessageId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IEmailMailboxProposeNewTimeForMeetingRequest<D>::NewStartTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IEmailMailboxProposeNewTimeForMeetingRequest)->get_NewStartTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IEmailMailboxProposeNewTimeForMeetingRequest<D>::NewDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IEmailMailboxProposeNewTimeForMeetingRequest)->get_NewDuration(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxProposeNewTimeForMeetingRequest<D>::Subject() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxProposeNewTimeForMeetingRequest)->get_Subject(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxProposeNewTimeForMeetingRequest<D>::Comment() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxProposeNewTimeForMeetingRequest)->get_Comment(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxProposeNewTimeForMeetingRequest<D>::ReportCompletedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxProposeNewTimeForMeetingRequest)->abi_ReportCompletedAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxProposeNewTimeForMeetingRequest<D>::ReportFailedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxProposeNewTimeForMeetingRequest)->abi_ReportFailedAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailMailboxSetAutoReplySettingsRequest<D>::EmailMailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxSetAutoReplySettingsRequest)->get_EmailMailboxId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings impl_IEmailMailboxSetAutoReplySettingsRequest<D>::AutoReplySettings() const
{
    Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxSetAutoReplySettingsRequest)->get_AutoReplySettings(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxSetAutoReplySettingsRequest<D>::ReportCompletedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxSetAutoReplySettingsRequest)->abi_ReportCompletedAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxSetAutoReplySettingsRequest<D>::ReportFailedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxSetAutoReplySettingsRequest)->abi_ReportFailedAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailMailboxGetAutoReplySettingsRequest<D>::EmailMailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxGetAutoReplySettingsRequest)->get_EmailMailboxId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind impl_IEmailMailboxGetAutoReplySettingsRequest<D>::RequestedFormat() const
{
    Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind value {};
    check_hresult(WINRT_SHIM(IEmailMailboxGetAutoReplySettingsRequest)->get_RequestedFormat(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxGetAutoReplySettingsRequest<D>::ReportCompletedAsync(const Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings & autoReplySettings) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxGetAutoReplySettingsRequest)->abi_ReportCompletedAsync(get_abi(autoReplySettings), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxGetAutoReplySettingsRequest<D>::ReportFailedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxGetAutoReplySettingsRequest)->abi_ReportFailedAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailMailboxResolveRecipientsRequest<D>::EmailMailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxResolveRecipientsRequest)->get_EmailMailboxId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IEmailMailboxResolveRecipientsRequest<D>::Recipients() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IEmailMailboxResolveRecipientsRequest)->get_Recipients(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxResolveRecipientsRequest<D>::ReportCompletedAsync(iterable<Windows::ApplicationModel::Email::EmailRecipientResolutionResult> resolutionResults) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxResolveRecipientsRequest)->abi_ReportCompletedAsync(get_abi(resolutionResults), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxResolveRecipientsRequest<D>::ReportFailedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxResolveRecipientsRequest)->abi_ReportFailedAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailMailboxValidateCertificatesRequest<D>::EmailMailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxValidateCertificatesRequest)->get_EmailMailboxId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> impl_IEmailMailboxValidateCertificatesRequest<D>::Certificates() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> value;
    check_hresult(WINRT_SHIM(IEmailMailboxValidateCertificatesRequest)->get_Certificates(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxValidateCertificatesRequest<D>::ReportCompletedAsync(iterable<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus> validationStatuses) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxValidateCertificatesRequest)->abi_ReportCompletedAsync(get_abi(validationStatuses), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxValidateCertificatesRequest<D>::ReportFailedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxValidateCertificatesRequest)->abi_ReportFailedAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IEmailMailboxServerSearchReadBatchRequest<D>::SessionId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxServerSearchReadBatchRequest)->get_SessionId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxServerSearchReadBatchRequest<D>::EmailMailboxId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxServerSearchReadBatchRequest)->get_EmailMailboxId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEmailMailboxServerSearchReadBatchRequest<D>::EmailFolderId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEmailMailboxServerSearchReadBatchRequest)->get_EmailFolderId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::EmailQueryOptions impl_IEmailMailboxServerSearchReadBatchRequest<D>::Options() const
{
    Windows::ApplicationModel::Email::EmailQueryOptions value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxServerSearchReadBatchRequest)->get_Options(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IEmailMailboxServerSearchReadBatchRequest<D>::SuggestedBatchSize() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IEmailMailboxServerSearchReadBatchRequest)->get_SuggestedBatchSize(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxServerSearchReadBatchRequest<D>::SaveMessageAsync(const Windows::ApplicationModel::Email::EmailMessage & message) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxServerSearchReadBatchRequest)->abi_SaveMessageAsync(get_abi(message), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxServerSearchReadBatchRequest<D>::ReportCompletedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxServerSearchReadBatchRequest)->abi_ReportCompletedAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEmailMailboxServerSearchReadBatchRequest<D>::ReportFailedAsync(Windows::ApplicationModel::Email::EmailBatchStatus batchStatus) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEmailMailboxServerSearchReadBatchRequest)->abi_ReportFailedAsync(batchStatus, put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequest impl_IEmailMailboxSyncManagerSyncRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequest value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxSyncManagerSyncRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IEmailMailboxSyncManagerSyncRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxSyncManagerSyncRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequest impl_IEmailMailboxDownloadMessageRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequest value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxDownloadMessageRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IEmailMailboxDownloadMessageRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxDownloadMessageRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequest impl_IEmailMailboxDownloadAttachmentRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequest value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxDownloadAttachmentRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IEmailMailboxDownloadAttachmentRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxDownloadAttachmentRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequest impl_IEmailMailboxCreateFolderRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequest value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxCreateFolderRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IEmailMailboxCreateFolderRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxCreateFolderRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequest impl_IEmailMailboxDeleteFolderRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequest value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxDeleteFolderRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IEmailMailboxDeleteFolderRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxDeleteFolderRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequest impl_IEmailMailboxEmptyFolderRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequest value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxEmptyFolderRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IEmailMailboxEmptyFolderRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxEmptyFolderRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequest impl_IEmailMailboxMoveFolderRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequest value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxMoveFolderRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IEmailMailboxMoveFolderRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxMoveFolderRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequest impl_IEmailMailboxUpdateMeetingResponseRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequest value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxUpdateMeetingResponseRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IEmailMailboxUpdateMeetingResponseRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxUpdateMeetingResponseRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequest impl_IEmailMailboxForwardMeetingRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequest value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxForwardMeetingRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IEmailMailboxForwardMeetingRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxForwardMeetingRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequest impl_IEmailMailboxProposeNewTimeForMeetingRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequest value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxProposeNewTimeForMeetingRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IEmailMailboxProposeNewTimeForMeetingRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxProposeNewTimeForMeetingRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequest impl_IEmailMailboxSetAutoReplySettingsRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequest value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxSetAutoReplySettingsRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IEmailMailboxSetAutoReplySettingsRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxSetAutoReplySettingsRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequest impl_IEmailMailboxGetAutoReplySettingsRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequest value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxGetAutoReplySettingsRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IEmailMailboxGetAutoReplySettingsRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxGetAutoReplySettingsRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequest impl_IEmailMailboxResolveRecipientsRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequest value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxResolveRecipientsRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IEmailMailboxResolveRecipientsRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxResolveRecipientsRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequest impl_IEmailMailboxValidateCertificatesRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequest value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxValidateCertificatesRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IEmailMailboxValidateCertificatesRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxValidateCertificatesRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequest impl_IEmailMailboxServerSearchReadBatchRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequest value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxServerSearchReadBatchRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IEmailMailboxServerSearchReadBatchRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IEmailMailboxServerSearchReadBatchRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

}

}
#pragma warning(pop)
