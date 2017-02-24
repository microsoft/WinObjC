// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Media.MediaProperties.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Security.Credentials.3.h"
#include "internal/Windows.ApplicationModel.Chat.3.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatCapabilities> : produce_base<D, Windows::ApplicationModel::Chat::IChatCapabilities>
{
    HRESULT __stdcall get_IsOnline(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsOnline());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsChatCapable(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsChatCapable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsFileTransferCapable(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsFileTransferCapable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsGeoLocationPushCapable(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsGeoLocationPushCapable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsIntegratedMessagingCapable(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsIntegratedMessagingCapable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatCapabilitiesManagerStatics> : produce_base<D, Windows::ApplicationModel::Chat::IChatCapabilitiesManagerStatics>
{
    HRESULT __stdcall abi_GetCachedCapabilitiesAsync(impl::abi_arg_in<hstring> address, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatCapabilities>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetCachedCapabilitiesAsync(*reinterpret_cast<const hstring *>(&address)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCapabilitiesFromNetworkAsync(impl::abi_arg_in<hstring> address, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatCapabilities>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetCapabilitiesFromNetworkAsync(*reinterpret_cast<const hstring *>(&address)));
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
struct produce<D, Windows::ApplicationModel::Chat::IChatConversation> : produce_base<D, Windows::ApplicationModel::Chat::IChatConversation>
{
    HRESULT __stdcall get_HasUnreadMessages(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().HasUnreadMessages());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Subject(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Subject());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
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

    HRESULT __stdcall get_IsConversationMuted(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsConversationMuted());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsConversationMuted(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsConversationMuted(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MostRecentMessageId(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MostRecentMessageId());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Participants(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Participants());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ThreadingInfo(impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatConversationThreadingInfo> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ThreadingInfo());
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

    HRESULT __stdcall abi_GetMessageReader(impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatMessageReader> result) noexcept override
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

    HRESULT __stdcall abi_MarkAllMessagesAsReadAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MarkMessagesAsReadAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkMessagesAsReadAsync(impl::abi_arg_in<Windows::Foundation::DateTime> value, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MarkMessagesAsReadAsync(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value)));
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

    HRESULT __stdcall abi_NotifyLocalParticipantComposing(impl::abi_arg_in<hstring> transportId, impl::abi_arg_in<hstring> participantAddress, bool isComposing) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyLocalParticipantComposing(*reinterpret_cast<const hstring *>(&transportId), *reinterpret_cast<const hstring *>(&participantAddress), isComposing);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyRemoteParticipantComposing(impl::abi_arg_in<hstring> transportId, impl::abi_arg_in<hstring> participantAddress, bool isComposing) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyRemoteParticipantComposing(*reinterpret_cast<const hstring *>(&transportId), *reinterpret_cast<const hstring *>(&participantAddress), isComposing);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RemoteParticipantComposingChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatConversation, Windows::ApplicationModel::Chat::RemoteParticipantComposingChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RemoteParticipantComposingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatConversation, Windows::ApplicationModel::Chat::RemoteParticipantComposingChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RemoteParticipantComposingChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteParticipantComposingChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatConversation2> : produce_base<D, Windows::ApplicationModel::Chat::IChatConversation2>
{
    HRESULT __stdcall get_CanModifyParticipants(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CanModifyParticipants());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanModifyParticipants(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanModifyParticipants(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatConversationReader> : produce_base<D, Windows::ApplicationModel::Chat::IChatConversationReader>
{
    HRESULT __stdcall abi_ReadBatchAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatConversation>>> result) noexcept override
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

    HRESULT __stdcall abi_ReadBatchWithCountAsync(int32_t count, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatConversation>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReadBatchAsync(count));
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
struct produce<D, Windows::ApplicationModel::Chat::IChatConversationThreadingInfo> : produce_base<D, Windows::ApplicationModel::Chat::IChatConversationThreadingInfo>
{
    HRESULT __stdcall get_ContactId(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ContactId());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContactId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContactId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Custom(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Custom());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Custom(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Custom(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConversationId(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ConversationId());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ConversationId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConversationId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Participants(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Participants());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::ApplicationModel::Chat::ChatConversationThreadingKind * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Kind(Windows::ApplicationModel::Chat::ChatConversationThreadingKind value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatItem> : produce_base<D, Windows::ApplicationModel::Chat::IChatItem>
{
    HRESULT __stdcall get_ItemKind(Windows::ApplicationModel::Chat::ChatItemKind * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ItemKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatMessage> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessage>
{
    HRESULT __stdcall get_Attachments(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Chat::ChatMessageAttachment>> value) noexcept override
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

    HRESULT __stdcall get_From(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().From());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
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

    HRESULT __stdcall get_IsForwardingDisabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsForwardingDisabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsIncoming(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsIncoming());
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

    HRESULT __stdcall get_LocalTimestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalTimestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NetworkTimestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkTimestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Recipients(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
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

    HRESULT __stdcall get_RecipientSendStatuses(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, winrt::Windows::ApplicationModel::Chat::ChatMessageStatus>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RecipientSendStatuses());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::ApplicationModel::Chat::ChatMessageStatus * value) noexcept override
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

    HRESULT __stdcall get_TransportFriendlyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransportFriendlyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransportId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransportId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransportId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransportId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatMessage2> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessage2>
{
    HRESULT __stdcall get_EstimatedDownloadSize(uint64_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().EstimatedDownloadSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EstimatedDownloadSize(uint64_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EstimatedDownloadSize(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_From(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().From(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsAutoReply(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsAutoReply());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsAutoReply(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsAutoReply(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsForwardingDisabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsForwardingDisabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsReplyDisabled(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsReplyDisabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsIncoming(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsIncoming(value);
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

    HRESULT __stdcall get_IsSeen(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsSeen());
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

    HRESULT __stdcall get_IsSimMessage(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsSimMessage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LocalTimestamp(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LocalTimestamp(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageKind(Windows::ApplicationModel::Chat::ChatMessageKind * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MessageKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MessageKind(Windows::ApplicationModel::Chat::ChatMessageKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MessageKind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageOperatorKind(Windows::ApplicationModel::Chat::ChatMessageOperatorKind * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MessageOperatorKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MessageOperatorKind(Windows::ApplicationModel::Chat::ChatMessageOperatorKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MessageOperatorKind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NetworkTimestamp(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NetworkTimestamp(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsReceivedDuringQuietHours(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsReceivedDuringQuietHours());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsReceivedDuringQuietHours(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsReceivedDuringQuietHours(value);
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall put_Status(Windows::ApplicationModel::Chat::ChatMessageStatus value) noexcept override
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

    HRESULT __stdcall get_ShouldSuppressNotification(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShouldSuppressNotification());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ShouldSuppressNotification(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShouldSuppressNotification(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ThreadingInfo(impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatConversationThreadingInfo> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ThreadingInfo());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ThreadingInfo(impl::abi_arg_in<Windows::ApplicationModel::Chat::IChatConversationThreadingInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ThreadingInfo(*reinterpret_cast<const Windows::ApplicationModel::Chat::ChatConversationThreadingInfo *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RecipientsDeliveryInfos(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Chat::ChatRecipientDeliveryInfo>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RecipientsDeliveryInfos());
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
struct produce<D, Windows::ApplicationModel::Chat::IChatMessage3> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessage3>
{
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatMessage4> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessage4>
{
    HRESULT __stdcall get_SyncId(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SyncId());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SyncId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SyncId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageAttachment> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageAttachment>
{
    HRESULT __stdcall get_DataStreamReference(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataStreamReference());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DataStreamReference(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataStreamReference(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GroupId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GroupId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_GroupId(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GroupId(value);
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
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageAttachment2> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageAttachment2>
{
    HRESULT __stdcall get_Thumbnail(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Thumbnail());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
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

    HRESULT __stdcall get_TransferProgress(double * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TransferProgress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransferProgress(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransferProgress(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OriginalFileName(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().OriginalFileName());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OriginalFileName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OriginalFileName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageAttachmentFactory> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageAttachmentFactory>
{
    HRESULT __stdcall abi_CreateChatMessageAttachment(impl::abi_arg_in<hstring> mimeType, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> dataStreamReference, impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatMessageAttachment> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateChatMessageAttachment(*reinterpret_cast<const hstring *>(&mimeType), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&dataStreamReference)));
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
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageBlockingStatic> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageBlockingStatic>
{
    HRESULT __stdcall abi_MarkMessageAsBlockedAsync(impl::abi_arg_in<hstring> localChatMessageId, bool blocked, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MarkMessageAsBlockedAsync(*reinterpret_cast<const hstring *>(&localChatMessageId), blocked));
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
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageChange> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageChange>
{
    HRESULT __stdcall get_ChangeType(Windows::ApplicationModel::Chat::ChatMessageChangeType * value) noexcept override
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

    HRESULT __stdcall get_Message(impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatMessage> value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageChangeReader> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageChangeReader>
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

    HRESULT __stdcall abi_AcceptChangesThrough(impl::abi_arg_in<Windows::ApplicationModel::Chat::IChatMessageChange> lastChangeToAcknowledge) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcceptChangesThrough(*reinterpret_cast<const Windows::ApplicationModel::Chat::ChatMessageChange *>(&lastChangeToAcknowledge));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadBatchAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessageChange>>> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageChangeTracker> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageChangeTracker>
{
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

    HRESULT __stdcall abi_GetChangeReader(impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatMessageChangeReader> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageChangedDeferral> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageChangedDeferral>
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
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageChangedEventArgs> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageChangedEventArgs>
{
    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatMessageChangedDeferral> result) noexcept override
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
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageManager2Statics> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageManager2Statics>
{
    HRESULT __stdcall abi_RegisterTransportAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RegisterTransportAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTransportAsync(impl::abi_arg_in<hstring> transportId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessageTransport>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetTransportAsync(*reinterpret_cast<const hstring *>(&transportId)));
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
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageManagerStatic> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageManagerStatic>
{
    HRESULT __stdcall abi_GetTransportsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessageTransport>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetTransportsAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestStoreAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessageStore>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestStoreAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowComposeSmsMessageAsync(impl::abi_arg_in<Windows::ApplicationModel::Chat::IChatMessage> message, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShowComposeSmsMessageAsync(*reinterpret_cast<const Windows::ApplicationModel::Chat::ChatMessage *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowSmsSettings() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowSmsSettings();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageManagerStatics3> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageManagerStatics3>
{
    HRESULT __stdcall abi_RequestSyncManagerAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatSyncManager>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestSyncManagerAsync());
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
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails>
{
    HRESULT __stdcall get_ChatMessage(impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChatMessage());
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
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails2> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails2>
{
    HRESULT __stdcall get_ShouldDisplayToast(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShouldDisplayToast());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShouldUpdateDetailText(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShouldUpdateDetailText());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShouldUpdateBadge(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShouldUpdateBadge());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShouldUpdateActionCenter(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShouldUpdateActionCenter());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageReader> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageReader>
{
    HRESULT __stdcall abi_ReadBatchAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessage>>> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageReader2> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageReader2>
{
    HRESULT __stdcall abi_ReadBatchWithCountAsync(int32_t count, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessage>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReadBatchAsync(count));
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
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageStore> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageStore>
{
    HRESULT __stdcall get_ChangeTracker(impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatMessageChangeTracker> value) noexcept override
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

    HRESULT __stdcall abi_DeleteMessageAsync(impl::abi_arg_in<hstring> localMessageId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeleteMessageAsync(*reinterpret_cast<const hstring *>(&localMessageId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DownloadMessageAsync(impl::abi_arg_in<hstring> localChatMessageId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DownloadMessageAsync(*reinterpret_cast<const hstring *>(&localChatMessageId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMessageAsync(impl::abi_arg_in<hstring> localChatMessageId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetMessageAsync(*reinterpret_cast<const hstring *>(&localChatMessageId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMessageReader1(impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatMessageReader> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetMessageReader());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMessageReader2(impl::abi_arg_in<Windows::Foundation::TimeSpan> recentTimeLimit, impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatMessageReader> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetMessageReader(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&recentTimeLimit)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkMessageReadAsync(impl::abi_arg_in<hstring> localChatMessageId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MarkMessageReadAsync(*reinterpret_cast<const hstring *>(&localChatMessageId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RetrySendMessageAsync(impl::abi_arg_in<hstring> localChatMessageId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RetrySendMessageAsync(*reinterpret_cast<const hstring *>(&localChatMessageId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendMessageAsync(impl::abi_arg_in<Windows::ApplicationModel::Chat::IChatMessage> chatMessage, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SendMessageAsync(*reinterpret_cast<const Windows::ApplicationModel::Chat::ChatMessage *>(&chatMessage)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ValidateMessage(impl::abi_arg_in<Windows::ApplicationModel::Chat::IChatMessage> chatMessage, impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatMessageValidationResult> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ValidateMessage(*reinterpret_cast<const Windows::ApplicationModel::Chat::ChatMessage *>(&chatMessage)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MessageChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatMessageStore, Windows::ApplicationModel::Chat::ChatMessageChangedEventArgs>> value, event_token * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().MessageChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatMessageStore, Windows::ApplicationModel::Chat::ChatMessageChangedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MessageChanged(event_token value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MessageChanged(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageStore2> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageStore2>
{
    HRESULT __stdcall abi_ForwardMessageAsync(impl::abi_arg_in<hstring> localChatMessageId, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> addresses, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ForwardMessageAsync(*reinterpret_cast<const hstring *>(&localChatMessageId), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&addresses)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConversationAsync(impl::abi_arg_in<hstring> conversationId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatConversation>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetConversationAsync(*reinterpret_cast<const hstring *>(&conversationId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConversationForTransportsAsync(impl::abi_arg_in<hstring> conversationId, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> transportIds, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatConversation>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetConversationAsync(*reinterpret_cast<const hstring *>(&conversationId), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&transportIds)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConversationFromThreadingInfoAsync(impl::abi_arg_in<Windows::ApplicationModel::Chat::IChatConversationThreadingInfo> threadingInfo, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatConversation>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetConversationFromThreadingInfoAsync(*reinterpret_cast<const Windows::ApplicationModel::Chat::ChatConversationThreadingInfo *>(&threadingInfo)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConversationReader(impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatConversationReader> result) noexcept override
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

    HRESULT __stdcall abi_GetConversationForTransportsReader(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> transportIds, impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatConversationReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetConversationReader(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&transportIds)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMessageByRemoteIdAsync(impl::abi_arg_in<hstring> transportId, impl::abi_arg_in<hstring> remoteId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetMessageByRemoteIdAsync(*reinterpret_cast<const hstring *>(&transportId), *reinterpret_cast<const hstring *>(&remoteId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetUnseenCountAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<int32_t>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetUnseenCountAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetUnseenCountForTransportsReaderAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> transportIds, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<int32_t>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetUnseenCountAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&transportIds)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkAsSeenAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MarkAsSeenAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkAsSeenForTransportsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> transportIds, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MarkAsSeenAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&transportIds)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSearchReader(impl::abi_arg_in<Windows::ApplicationModel::Chat::IChatQueryOptions> value, impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatSearchReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetSearchReader(*reinterpret_cast<const Windows::ApplicationModel::Chat::ChatQueryOptions *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveMessageAsync(impl::abi_arg_in<Windows::ApplicationModel::Chat::IChatMessage> chatMessage, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SaveMessageAsync(*reinterpret_cast<const Windows::ApplicationModel::Chat::ChatMessage *>(&chatMessage)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryCancelDownloadMessageAsync(impl::abi_arg_in<hstring> localChatMessageId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryCancelDownloadMessageAsync(*reinterpret_cast<const hstring *>(&localChatMessageId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryCancelSendMessageAsync(impl::abi_arg_in<hstring> localChatMessageId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryCancelSendMessageAsync(*reinterpret_cast<const hstring *>(&localChatMessageId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StoreChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatMessageStore, Windows::ApplicationModel::Chat::ChatMessageStoreChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().StoreChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatMessageStore, Windows::ApplicationModel::Chat::ChatMessageStoreChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StoreChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StoreChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageStore3> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageStore3>
{
    HRESULT __stdcall abi_GetMessageBySyncIdAsync(impl::abi_arg_in<hstring> syncId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetMessageBySyncIdAsync(*reinterpret_cast<const hstring *>(&syncId)));
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
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageStoreChangedEventArgs> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageStoreChangedEventArgs>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::ApplicationModel::Chat::ChatStoreChangedEventKind * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageTransport> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageTransport>
{
    HRESULT __stdcall get_IsAppSetAsNotificationProvider(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAppSetAsNotificationProvider());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsActive(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsActive());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransportFriendlyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransportFriendlyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransportId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransportId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestSetAsNotificationProviderAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestSetAsNotificationProviderAsync());
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
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageTransport2> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageTransport2>
{
    HRESULT __stdcall get_Configuration(impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatMessageTransportConfiguration> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Configuration());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransportKind(Windows::ApplicationModel::Chat::ChatMessageTransportKind * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TransportKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageTransportConfiguration> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageTransportConfiguration>
{
    HRESULT __stdcall get_MaxAttachmentCount(int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MaxAttachmentCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxMessageSizeInKilobytes(int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MaxMessageSizeInKilobytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxRecipientCount(int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MaxRecipientCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedVideoFormat(impl::abi_arg_out<Windows::Media::MediaProperties::IMediaEncodingProfile> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SupportedVideoFormat());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedProperties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ExtendedProperties());
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
struct produce<D, Windows::ApplicationModel::Chat::IChatMessageValidationResult> : produce_base<D, Windows::ApplicationModel::Chat::IChatMessageValidationResult>
{
    HRESULT __stdcall get_MaxPartCount(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPartCount());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PartCount(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PartCount());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemainingCharacterCountInPart(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemainingCharacterCountInPart());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::ApplicationModel::Chat::ChatMessageValidationStatus * value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Chat::IChatQueryOptions> : produce_base<D, Windows::ApplicationModel::Chat::IChatQueryOptions>
{
    HRESULT __stdcall get_SearchString(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SearchString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SearchString(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SearchString(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo> : produce_base<D, Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo>
{
    HRESULT __stdcall get_TransportAddress(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TransportAddress());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransportAddress(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransportAddress(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeliveryTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DeliveryTime());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DeliveryTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeliveryTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReadTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReadTime());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ReadTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReadTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransportErrorCodeCategory(Windows::ApplicationModel::Chat::ChatTransportErrorCodeCategory * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TransportErrorCodeCategory());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransportInterpretedErrorCode(Windows::ApplicationModel::Chat::ChatTransportInterpretedErrorCode * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TransportInterpretedErrorCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransportErrorCode(int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TransportErrorCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsErrorPermanent(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsErrorPermanent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::ApplicationModel::Chat::ChatMessageStatus * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatSearchReader> : produce_base<D, Windows::ApplicationModel::Chat::IChatSearchReader>
{
    HRESULT __stdcall abi_ReadBatchAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::IChatItem>>> result) noexcept override
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

    HRESULT __stdcall abi_ReadBatchWithCountAsync(int32_t count, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::IChatItem>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReadBatchAsync(count));
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
struct produce<D, Windows::ApplicationModel::Chat::IChatSyncConfiguration> : produce_base<D, Windows::ApplicationModel::Chat::IChatSyncConfiguration>
{
    HRESULT __stdcall get_IsSyncEnabled(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsSyncEnabled());
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

    HRESULT __stdcall get_RestoreHistorySpan(Windows::ApplicationModel::Chat::ChatRestoreHistorySpan * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RestoreHistorySpan());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RestoreHistorySpan(Windows::ApplicationModel::Chat::ChatRestoreHistorySpan value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RestoreHistorySpan(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IChatSyncManager> : produce_base<D, Windows::ApplicationModel::Chat::IChatSyncManager>
{
    HRESULT __stdcall get_Configuration(impl::abi_arg_out<Windows::ApplicationModel::Chat::IChatSyncConfiguration> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Configuration());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AssociateAccountAsync(impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().AssociateAccountAsync(*reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnassociateAccountAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UnassociateAccountAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsAccountAssociated(impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsAccountAssociated(*reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartSync() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartSync();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetConfigurationAsync(impl::abi_arg_in<Windows::ApplicationModel::Chat::IChatSyncConfiguration> configuration, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SetConfigurationAsync(*reinterpret_cast<const Windows::ApplicationModel::Chat::ChatSyncConfiguration *>(&configuration)));
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
struct produce<D, Windows::ApplicationModel::Chat::IRcsEndUserMessage> : produce_base<D, Windows::ApplicationModel::Chat::IRcsEndUserMessage>
{
    HRESULT __stdcall get_TransportId(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TransportId());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Text());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPinRequired(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsPinRequired());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Actions(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::RcsEndUserMessageAction>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Actions());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendResponseAsync(impl::abi_arg_in<Windows::ApplicationModel::Chat::IRcsEndUserMessageAction> action, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SendResponseAsync(*reinterpret_cast<const Windows::ApplicationModel::Chat::RcsEndUserMessageAction *>(&action)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendResponseWithPinAsync(impl::abi_arg_in<Windows::ApplicationModel::Chat::IRcsEndUserMessageAction> action, impl::abi_arg_in<hstring> pin, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SendResponseWithPinAsync(*reinterpret_cast<const Windows::ApplicationModel::Chat::RcsEndUserMessageAction *>(&action), *reinterpret_cast<const hstring *>(&pin)));
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
struct produce<D, Windows::ApplicationModel::Chat::IRcsEndUserMessageAction> : produce_base<D, Windows::ApplicationModel::Chat::IRcsEndUserMessageAction>
{
    HRESULT __stdcall get_Label(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Label());
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
struct produce<D, Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableEventArgs> : produce_base<D, Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableEventArgs>
{
    HRESULT __stdcall get_IsMessageAvailable(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsMessageAvailable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Message(impl::abi_arg_out<Windows::ApplicationModel::Chat::IRcsEndUserMessage> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Message());
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
struct produce<D, Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableTriggerDetails> : produce_base<D, Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableTriggerDetails>
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IRcsEndUserMessageManager> : produce_base<D, Windows::ApplicationModel::Chat::IRcsEndUserMessageManager>
{
    HRESULT __stdcall add_MessageAvailableChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::RcsEndUserMessageManager, Windows::ApplicationModel::Chat::RcsEndUserMessageAvailableEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MessageAvailableChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::RcsEndUserMessageManager, Windows::ApplicationModel::Chat::RcsEndUserMessageAvailableEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MessageAvailableChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MessageAvailableChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IRcsManagerStatics> : produce_base<D, Windows::ApplicationModel::Chat::IRcsManagerStatics>
{
    HRESULT __stdcall abi_GetEndUserMessageManager(impl::abi_arg_out<Windows::ApplicationModel::Chat::IRcsEndUserMessageManager> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetEndUserMessageManager());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTransportsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::RcsTransport>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetTransportsAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTransportAsync(impl::abi_arg_in<hstring> transportId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::RcsTransport>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetTransportAsync(*reinterpret_cast<const hstring *>(&transportId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LeaveConversationAsync(impl::abi_arg_in<Windows::ApplicationModel::Chat::IChatConversation> conversation, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LeaveConversationAsync(*reinterpret_cast<const Windows::ApplicationModel::Chat::ChatConversation *>(&conversation)));
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
struct produce<D, Windows::ApplicationModel::Chat::IRcsServiceKindSupportedChangedEventArgs> : produce_base<D, Windows::ApplicationModel::Chat::IRcsServiceKindSupportedChangedEventArgs>
{
    HRESULT __stdcall get_ServiceKind(Windows::ApplicationModel::Chat::RcsServiceKind * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ServiceKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IRcsTransport> : produce_base<D, Windows::ApplicationModel::Chat::IRcsTransport>
{
    HRESULT __stdcall get_ExtendedProperties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsActive(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsActive());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransportFriendlyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransportFriendlyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransportId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransportId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Configuration(impl::abi_arg_out<Windows::ApplicationModel::Chat::IRcsTransportConfiguration> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Configuration());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsStoreAndForwardEnabled(Windows::ApplicationModel::Chat::RcsServiceKind serviceKind, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsStoreAndForwardEnabled(serviceKind));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsServiceKindSupported(Windows::ApplicationModel::Chat::RcsServiceKind serviceKind, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsServiceKindSupported(serviceKind));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ServiceKindSupportedChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::RcsTransport, Windows::ApplicationModel::Chat::RcsServiceKindSupportedChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ServiceKindSupportedChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::RcsTransport, Windows::ApplicationModel::Chat::RcsServiceKindSupportedChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ServiceKindSupportedChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServiceKindSupportedChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IRcsTransportConfiguration> : produce_base<D, Windows::ApplicationModel::Chat::IRcsTransportConfiguration>
{
    HRESULT __stdcall get_MaxAttachmentCount(int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MaxAttachmentCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxMessageSizeInKilobytes(int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MaxMessageSizeInKilobytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxGroupMessageSizeInKilobytes(int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MaxGroupMessageSizeInKilobytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxRecipientCount(int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MaxRecipientCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxFileSizeInKilobytes(int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MaxFileSizeInKilobytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WarningFileSizeInKilobytes(int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().WarningFileSizeInKilobytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Chat::IRemoteParticipantComposingChangedEventArgs> : produce_base<D, Windows::ApplicationModel::Chat::IRemoteParticipantComposingChangedEventArgs>
{
    HRESULT __stdcall get_TransportId(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TransportId());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ParticipantAddress(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ParticipantAddress());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsComposing(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsComposing());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Chat {

template <typename D> bool impl_IChatMessageTransport<D>::IsAppSetAsNotificationProvider() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IChatMessageTransport)->get_IsAppSetAsNotificationProvider(&value));
    return value;
}

template <typename D> bool impl_IChatMessageTransport<D>::IsActive() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IChatMessageTransport)->get_IsActive(&value));
    return value;
}

template <typename D> hstring impl_IChatMessageTransport<D>::TransportFriendlyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IChatMessageTransport)->get_TransportFriendlyName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IChatMessageTransport<D>::TransportId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IChatMessageTransport)->get_TransportId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatMessageTransport<D>::RequestSetAsNotificationProviderAsync() const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IChatMessageTransport)->abi_RequestSetAsNotificationProviderAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessageTransportConfiguration impl_IChatMessageTransport2<D>::Configuration() const
{
    Windows::ApplicationModel::Chat::ChatMessageTransportConfiguration result { nullptr };
    check_hresult(WINRT_SHIM(IChatMessageTransport2)->get_Configuration(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessageTransportKind impl_IChatMessageTransport2<D>::TransportKind() const
{
    Windows::ApplicationModel::Chat::ChatMessageTransportKind result {};
    check_hresult(WINRT_SHIM(IChatMessageTransport2)->get_TransportKind(&result));
    return result;
}

template <typename D> int32_t impl_IChatMessageTransportConfiguration<D>::MaxAttachmentCount() const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(IChatMessageTransportConfiguration)->get_MaxAttachmentCount(&result));
    return result;
}

template <typename D> int32_t impl_IChatMessageTransportConfiguration<D>::MaxMessageSizeInKilobytes() const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(IChatMessageTransportConfiguration)->get_MaxMessageSizeInKilobytes(&result));
    return result;
}

template <typename D> int32_t impl_IChatMessageTransportConfiguration<D>::MaxRecipientCount() const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(IChatMessageTransportConfiguration)->get_MaxRecipientCount(&result));
    return result;
}

template <typename D> Windows::Media::MediaProperties::MediaEncodingProfile impl_IChatMessageTransportConfiguration<D>::SupportedVideoFormat() const
{
    Windows::Media::MediaProperties::MediaEncodingProfile result { nullptr };
    check_hresult(WINRT_SHIM(IChatMessageTransportConfiguration)->get_SupportedVideoFormat(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_IChatMessageTransportConfiguration<D>::ExtendedProperties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> result;
    check_hresult(WINRT_SHIM(IChatMessageTransportConfiguration)->get_ExtendedProperties(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessageChangeType impl_IChatMessageChange<D>::ChangeType() const
{
    Windows::ApplicationModel::Chat::ChatMessageChangeType value {};
    check_hresult(WINRT_SHIM(IChatMessageChange)->get_ChangeType(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessage impl_IChatMessageChange<D>::Message() const
{
    Windows::ApplicationModel::Chat::ChatMessage value { nullptr };
    check_hresult(WINRT_SHIM(IChatMessageChange)->get_Message(put_abi(value)));
    return value;
}

template <typename D> void impl_IChatMessageChangeReader<D>::AcceptChanges() const
{
    check_hresult(WINRT_SHIM(IChatMessageChangeReader)->abi_AcceptChanges());
}

template <typename D> void impl_IChatMessageChangeReader<D>::AcceptChangesThrough(const Windows::ApplicationModel::Chat::ChatMessageChange & lastChangeToAcknowledge) const
{
    check_hresult(WINRT_SHIM(IChatMessageChangeReader)->abi_AcceptChangesThrough(get_abi(lastChangeToAcknowledge)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessageChange>> impl_IChatMessageChangeReader<D>::ReadBatchAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessageChange>> value;
    check_hresult(WINRT_SHIM(IChatMessageChangeReader)->abi_ReadBatchAsync(put_abi(value)));
    return value;
}

template <typename D> void impl_IChatMessageChangeTracker<D>::Enable() const
{
    check_hresult(WINRT_SHIM(IChatMessageChangeTracker)->abi_Enable());
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessageChangeReader impl_IChatMessageChangeTracker<D>::GetChangeReader() const
{
    Windows::ApplicationModel::Chat::ChatMessageChangeReader value { nullptr };
    check_hresult(WINRT_SHIM(IChatMessageChangeTracker)->abi_GetChangeReader(put_abi(value)));
    return value;
}

template <typename D> void impl_IChatMessageChangeTracker<D>::Reset() const
{
    check_hresult(WINRT_SHIM(IChatMessageChangeTracker)->abi_Reset());
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IChatMessageValidationResult<D>::MaxPartCount() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IChatMessageValidationResult)->get_MaxPartCount(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IChatMessageValidationResult<D>::PartCount() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IChatMessageValidationResult)->get_PartCount(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IChatMessageValidationResult<D>::RemainingCharacterCountInPart() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IChatMessageValidationResult)->get_RemainingCharacterCountInPart(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessageValidationStatus impl_IChatMessageValidationResult<D>::Status() const
{
    Windows::ApplicationModel::Chat::ChatMessageValidationStatus value {};
    check_hresult(WINRT_SHIM(IChatMessageValidationResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Chat::ChatMessageAttachment> impl_IChatMessage<D>::Attachments() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Chat::ChatMessageAttachment> value;
    check_hresult(WINRT_SHIM(IChatMessage)->get_Attachments(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IChatMessage<D>::Body() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IChatMessage)->get_Body(put_abi(value)));
    return value;
}

template <typename D> void impl_IChatMessage<D>::Body(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IChatMessage)->put_Body(get_abi(value)));
}

template <typename D> hstring impl_IChatMessage<D>::From() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IChatMessage)->get_From(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IChatMessage<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IChatMessage)->get_Id(put_abi(value)));
    return value;
}

template <typename D> bool impl_IChatMessage<D>::IsForwardingDisabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IChatMessage)->get_IsForwardingDisabled(&value));
    return value;
}

template <typename D> bool impl_IChatMessage<D>::IsIncoming() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IChatMessage)->get_IsIncoming(&value));
    return value;
}

template <typename D> bool impl_IChatMessage<D>::IsRead() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IChatMessage)->get_IsRead(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IChatMessage<D>::LocalTimestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IChatMessage)->get_LocalTimestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IChatMessage<D>::NetworkTimestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IChatMessage)->get_NetworkTimestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IChatMessage<D>::Recipients() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IChatMessage)->get_Recipients(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, winrt::Windows::ApplicationModel::Chat::ChatMessageStatus> impl_IChatMessage<D>::RecipientSendStatuses() const
{
    Windows::Foundation::Collections::IMapView<hstring, winrt::Windows::ApplicationModel::Chat::ChatMessageStatus> value;
    check_hresult(WINRT_SHIM(IChatMessage)->get_RecipientSendStatuses(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessageStatus impl_IChatMessage<D>::Status() const
{
    Windows::ApplicationModel::Chat::ChatMessageStatus value {};
    check_hresult(WINRT_SHIM(IChatMessage)->get_Status(&value));
    return value;
}

template <typename D> hstring impl_IChatMessage<D>::Subject() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IChatMessage)->get_Subject(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IChatMessage<D>::TransportFriendlyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IChatMessage)->get_TransportFriendlyName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IChatMessage<D>::TransportId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IChatMessage)->get_TransportId(put_abi(value)));
    return value;
}

template <typename D> void impl_IChatMessage<D>::TransportId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IChatMessage)->put_TransportId(get_abi(value)));
}

template <typename D> hstring impl_IChatMessage3<D>::RemoteId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IChatMessage3)->get_RemoteId(put_abi(value)));
    return value;
}

template <typename D> uint64_t impl_IChatMessage2<D>::EstimatedDownloadSize() const
{
    uint64_t result {};
    check_hresult(WINRT_SHIM(IChatMessage2)->get_EstimatedDownloadSize(&result));
    return result;
}

template <typename D> void impl_IChatMessage2<D>::EstimatedDownloadSize(uint64_t value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_EstimatedDownloadSize(value));
}

template <typename D> void impl_IChatMessage2<D>::From(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_From(get_abi(value)));
}

template <typename D> bool impl_IChatMessage2<D>::IsAutoReply() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatMessage2)->get_IsAutoReply(&result));
    return result;
}

template <typename D> void impl_IChatMessage2<D>::IsAutoReply(bool value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_IsAutoReply(value));
}

template <typename D> void impl_IChatMessage2<D>::IsForwardingDisabled(bool value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_IsForwardingDisabled(value));
}

template <typename D> bool impl_IChatMessage2<D>::IsReplyDisabled() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatMessage2)->get_IsReplyDisabled(&result));
    return result;
}

template <typename D> void impl_IChatMessage2<D>::IsIncoming(bool value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_IsIncoming(value));
}

template <typename D> void impl_IChatMessage2<D>::IsRead(bool value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_IsRead(value));
}

template <typename D> bool impl_IChatMessage2<D>::IsSeen() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatMessage2)->get_IsSeen(&result));
    return result;
}

template <typename D> void impl_IChatMessage2<D>::IsSeen(bool value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_IsSeen(value));
}

template <typename D> bool impl_IChatMessage2<D>::IsSimMessage() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatMessage2)->get_IsSimMessage(&result));
    return result;
}

template <typename D> void impl_IChatMessage2<D>::LocalTimestamp(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_LocalTimestamp(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessageKind impl_IChatMessage2<D>::MessageKind() const
{
    Windows::ApplicationModel::Chat::ChatMessageKind result {};
    check_hresult(WINRT_SHIM(IChatMessage2)->get_MessageKind(&result));
    return result;
}

template <typename D> void impl_IChatMessage2<D>::MessageKind(Windows::ApplicationModel::Chat::ChatMessageKind value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_MessageKind(value));
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessageOperatorKind impl_IChatMessage2<D>::MessageOperatorKind() const
{
    Windows::ApplicationModel::Chat::ChatMessageOperatorKind result {};
    check_hresult(WINRT_SHIM(IChatMessage2)->get_MessageOperatorKind(&result));
    return result;
}

template <typename D> void impl_IChatMessage2<D>::MessageOperatorKind(Windows::ApplicationModel::Chat::ChatMessageOperatorKind value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_MessageOperatorKind(value));
}

template <typename D> void impl_IChatMessage2<D>::NetworkTimestamp(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_NetworkTimestamp(get_abi(value)));
}

template <typename D> bool impl_IChatMessage2<D>::IsReceivedDuringQuietHours() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatMessage2)->get_IsReceivedDuringQuietHours(&result));
    return result;
}

template <typename D> void impl_IChatMessage2<D>::IsReceivedDuringQuietHours(bool value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_IsReceivedDuringQuietHours(value));
}

template <typename D> void impl_IChatMessage2<D>::RemoteId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_RemoteId(get_abi(value)));
}

template <typename D> void impl_IChatMessage2<D>::Status(Windows::ApplicationModel::Chat::ChatMessageStatus value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_Status(value));
}

template <typename D> void impl_IChatMessage2<D>::Subject(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_Subject(get_abi(value)));
}

template <typename D> bool impl_IChatMessage2<D>::ShouldSuppressNotification() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatMessage2)->get_ShouldSuppressNotification(&result));
    return result;
}

template <typename D> void impl_IChatMessage2<D>::ShouldSuppressNotification(bool value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_ShouldSuppressNotification(value));
}

template <typename D> Windows::ApplicationModel::Chat::ChatConversationThreadingInfo impl_IChatMessage2<D>::ThreadingInfo() const
{
    Windows::ApplicationModel::Chat::ChatConversationThreadingInfo result { nullptr };
    check_hresult(WINRT_SHIM(IChatMessage2)->get_ThreadingInfo(put_abi(result)));
    return result;
}

template <typename D> void impl_IChatMessage2<D>::ThreadingInfo(const Windows::ApplicationModel::Chat::ChatConversationThreadingInfo & value) const
{
    check_hresult(WINRT_SHIM(IChatMessage2)->put_ThreadingInfo(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Chat::ChatRecipientDeliveryInfo> impl_IChatMessage2<D>::RecipientsDeliveryInfos() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Chat::ChatRecipientDeliveryInfo> result;
    check_hresult(WINRT_SHIM(IChatMessage2)->get_RecipientsDeliveryInfos(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IChatMessage4<D>::SyncId() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IChatMessage4)->get_SyncId(put_abi(result)));
    return result;
}

template <typename D> void impl_IChatMessage4<D>::SyncId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IChatMessage4)->put_SyncId(get_abi(value)));
}

template <typename D> hstring impl_IChatQueryOptions<D>::SearchString() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IChatQueryOptions)->get_SearchString(put_abi(result)));
    return result;
}

template <typename D> void impl_IChatQueryOptions<D>::SearchString(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IChatQueryOptions)->put_SearchString(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessageChangeTracker impl_IChatMessageStore<D>::ChangeTracker() const
{
    Windows::ApplicationModel::Chat::ChatMessageChangeTracker value { nullptr };
    check_hresult(WINRT_SHIM(IChatMessageStore)->get_ChangeTracker(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatMessageStore<D>::DeleteMessageAsync(hstring_view localMessageId) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IChatMessageStore)->abi_DeleteMessageAsync(get_abi(localMessageId), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatMessageStore<D>::DownloadMessageAsync(hstring_view localChatMessageId) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IChatMessageStore)->abi_DownloadMessageAsync(get_abi(localChatMessageId), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage> impl_IChatMessageStore<D>::GetMessageAsync(hstring_view localChatMessageId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage> value;
    check_hresult(WINRT_SHIM(IChatMessageStore)->abi_GetMessageAsync(get_abi(localChatMessageId), put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessageReader impl_IChatMessageStore<D>::GetMessageReader() const
{
    Windows::ApplicationModel::Chat::ChatMessageReader value { nullptr };
    check_hresult(WINRT_SHIM(IChatMessageStore)->abi_GetMessageReader1(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessageReader impl_IChatMessageStore<D>::GetMessageReader(const Windows::Foundation::TimeSpan & recentTimeLimit) const
{
    Windows::ApplicationModel::Chat::ChatMessageReader value { nullptr };
    check_hresult(WINRT_SHIM(IChatMessageStore)->abi_GetMessageReader2(get_abi(recentTimeLimit), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatMessageStore<D>::MarkMessageReadAsync(hstring_view localChatMessageId) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IChatMessageStore)->abi_MarkMessageReadAsync(get_abi(localChatMessageId), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatMessageStore<D>::RetrySendMessageAsync(hstring_view localChatMessageId) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IChatMessageStore)->abi_RetrySendMessageAsync(get_abi(localChatMessageId), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatMessageStore<D>::SendMessageAsync(const Windows::ApplicationModel::Chat::ChatMessage & chatMessage) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IChatMessageStore)->abi_SendMessageAsync(get_abi(chatMessage), put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessageValidationResult impl_IChatMessageStore<D>::ValidateMessage(const Windows::ApplicationModel::Chat::ChatMessage & chatMessage) const
{
    Windows::ApplicationModel::Chat::ChatMessageValidationResult value { nullptr };
    check_hresult(WINRT_SHIM(IChatMessageStore)->abi_ValidateMessage(get_abi(chatMessage), put_abi(value)));
    return value;
}

template <typename D> event_token impl_IChatMessageStore<D>::MessageChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatMessageStore, Windows::ApplicationModel::Chat::ChatMessageChangedEventArgs> & value) const
{
    event_token returnValue {};
    check_hresult(WINRT_SHIM(IChatMessageStore)->add_MessageChanged(get_abi(value), &returnValue));
    return returnValue;
}

template <typename D> event_revoker<IChatMessageStore> impl_IChatMessageStore<D>::MessageChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatMessageStore, Windows::ApplicationModel::Chat::ChatMessageChangedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IChatMessageStore>(this, &ABI::Windows::ApplicationModel::Chat::IChatMessageStore::remove_MessageChanged, MessageChanged(value));
}

template <typename D> void impl_IChatMessageStore<D>::MessageChanged(event_token value) const
{
    check_hresult(WINRT_SHIM(IChatMessageStore)->remove_MessageChanged(value));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage> impl_IChatMessageStore2<D>::ForwardMessageAsync(hstring_view localChatMessageId, iterable<hstring> addresses) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage> result;
    check_hresult(WINRT_SHIM(IChatMessageStore2)->abi_ForwardMessageAsync(get_abi(localChatMessageId), get_abi(addresses), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatConversation> impl_IChatMessageStore2<D>::GetConversationAsync(hstring_view conversationId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatConversation> result;
    check_hresult(WINRT_SHIM(IChatMessageStore2)->abi_GetConversationAsync(get_abi(conversationId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatConversation> impl_IChatMessageStore2<D>::GetConversationAsync(hstring_view conversationId, iterable<hstring> transportIds) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatConversation> result;
    check_hresult(WINRT_SHIM(IChatMessageStore2)->abi_GetConversationForTransportsAsync(get_abi(conversationId), get_abi(transportIds), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatConversation> impl_IChatMessageStore2<D>::GetConversationFromThreadingInfoAsync(const Windows::ApplicationModel::Chat::ChatConversationThreadingInfo & threadingInfo) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatConversation> result;
    check_hresult(WINRT_SHIM(IChatMessageStore2)->abi_GetConversationFromThreadingInfoAsync(get_abi(threadingInfo), put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Chat::ChatConversationReader impl_IChatMessageStore2<D>::GetConversationReader() const
{
    Windows::ApplicationModel::Chat::ChatConversationReader result { nullptr };
    check_hresult(WINRT_SHIM(IChatMessageStore2)->abi_GetConversationReader(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Chat::ChatConversationReader impl_IChatMessageStore2<D>::GetConversationReader(iterable<hstring> transportIds) const
{
    Windows::ApplicationModel::Chat::ChatConversationReader result { nullptr };
    check_hresult(WINRT_SHIM(IChatMessageStore2)->abi_GetConversationForTransportsReader(get_abi(transportIds), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage> impl_IChatMessageStore2<D>::GetMessageByRemoteIdAsync(hstring_view transportId, hstring_view remoteId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage> result;
    check_hresult(WINRT_SHIM(IChatMessageStore2)->abi_GetMessageByRemoteIdAsync(get_abi(transportId), get_abi(remoteId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<int32_t> impl_IChatMessageStore2<D>::GetUnseenCountAsync() const
{
    Windows::Foundation::IAsyncOperation<int32_t> result;
    check_hresult(WINRT_SHIM(IChatMessageStore2)->abi_GetUnseenCountAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<int32_t> impl_IChatMessageStore2<D>::GetUnseenCountAsync(iterable<hstring> transportIds) const
{
    Windows::Foundation::IAsyncOperation<int32_t> result;
    check_hresult(WINRT_SHIM(IChatMessageStore2)->abi_GetUnseenCountForTransportsReaderAsync(get_abi(transportIds), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatMessageStore2<D>::MarkAsSeenAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IChatMessageStore2)->abi_MarkAsSeenAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatMessageStore2<D>::MarkAsSeenAsync(iterable<hstring> transportIds) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IChatMessageStore2)->abi_MarkAsSeenForTransportsAsync(get_abi(transportIds), put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Chat::ChatSearchReader impl_IChatMessageStore2<D>::GetSearchReader(const Windows::ApplicationModel::Chat::ChatQueryOptions & value) const
{
    Windows::ApplicationModel::Chat::ChatSearchReader result { nullptr };
    check_hresult(WINRT_SHIM(IChatMessageStore2)->abi_GetSearchReader(get_abi(value), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatMessageStore2<D>::SaveMessageAsync(const Windows::ApplicationModel::Chat::ChatMessage & chatMessage) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IChatMessageStore2)->abi_SaveMessageAsync(get_abi(chatMessage), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IChatMessageStore2<D>::TryCancelDownloadMessageAsync(hstring_view localChatMessageId) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IChatMessageStore2)->abi_TryCancelDownloadMessageAsync(get_abi(localChatMessageId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IChatMessageStore2<D>::TryCancelSendMessageAsync(hstring_view localChatMessageId) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IChatMessageStore2)->abi_TryCancelSendMessageAsync(get_abi(localChatMessageId), put_abi(result)));
    return result;
}

template <typename D> event_token impl_IChatMessageStore2<D>::StoreChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatMessageStore, Windows::ApplicationModel::Chat::ChatMessageStoreChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IChatMessageStore2)->add_StoreChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IChatMessageStore2> impl_IChatMessageStore2<D>::StoreChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatMessageStore, Windows::ApplicationModel::Chat::ChatMessageStoreChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IChatMessageStore2>(this, &ABI::Windows::ApplicationModel::Chat::IChatMessageStore2::remove_StoreChanged, StoreChanged(handler));
}

template <typename D> void impl_IChatMessageStore2<D>::StoreChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IChatMessageStore2)->remove_StoreChanged(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage> impl_IChatMessageStore3<D>::GetMessageBySyncIdAsync(hstring_view syncId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage> result;
    check_hresult(WINRT_SHIM(IChatMessageStore3)->abi_GetMessageBySyncIdAsync(get_abi(syncId), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IChatMessageStoreChangedEventArgs<D>::Id() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IChatMessageStoreChangedEventArgs)->get_Id(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Chat::ChatStoreChangedEventKind impl_IChatMessageStoreChangedEventArgs<D>::Kind() const
{
    Windows::ApplicationModel::Chat::ChatStoreChangedEventKind result {};
    check_hresult(WINRT_SHIM(IChatMessageStoreChangedEventArgs)->get_Kind(&result));
    return result;
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessageChangedDeferral impl_IChatMessageChangedEventArgs<D>::GetDeferral() const
{
    Windows::ApplicationModel::Chat::ChatMessageChangedDeferral result { nullptr };
    check_hresult(WINRT_SHIM(IChatMessageChangedEventArgs)->abi_GetDeferral(put_abi(result)));
    return result;
}

template <typename D> void impl_IChatMessageChangedDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IChatMessageChangedDeferral)->abi_Complete());
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatMessageBlockingStatic<D>::MarkMessageAsBlockedAsync(hstring_view localChatMessageId, bool blocked) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IChatMessageBlockingStatic)->abi_MarkMessageAsBlockedAsync(get_abi(localChatMessageId), blocked, put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessageTransport>> impl_IChatMessageManagerStatic<D>::GetTransportsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessageTransport>> value;
    check_hresult(WINRT_SHIM(IChatMessageManagerStatic)->abi_GetTransportsAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessageStore> impl_IChatMessageManagerStatic<D>::RequestStoreAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessageStore> value;
    check_hresult(WINRT_SHIM(IChatMessageManagerStatic)->abi_RequestStoreAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatMessageManagerStatic<D>::ShowComposeSmsMessageAsync(const Windows::ApplicationModel::Chat::ChatMessage & message) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IChatMessageManagerStatic)->abi_ShowComposeSmsMessageAsync(get_abi(message), put_abi(value)));
    return value;
}

template <typename D> void impl_IChatMessageManagerStatic<D>::ShowSmsSettings() const
{
    check_hresult(WINRT_SHIM(IChatMessageManagerStatic)->abi_ShowSmsSettings());
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IChatMessageManager2Statics<D>::RegisterTransportAsync() const
{
    Windows::Foundation::IAsyncOperation<hstring> result;
    check_hresult(WINRT_SHIM(IChatMessageManager2Statics)->abi_RegisterTransportAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessageTransport> impl_IChatMessageManager2Statics<D>::GetTransportAsync(hstring_view transportId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessageTransport> result;
    check_hresult(WINRT_SHIM(IChatMessageManager2Statics)->abi_GetTransportAsync(get_abi(transportId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatSyncManager> impl_IChatMessageManagerStatics3<D>::RequestSyncManagerAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatSyncManager> result;
    check_hresult(WINRT_SHIM(IChatMessageManagerStatics3)->abi_RequestSyncManagerAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessage>> impl_IChatMessageReader<D>::ReadBatchAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessage>> value;
    check_hresult(WINRT_SHIM(IChatMessageReader)->abi_ReadBatchAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessage>> impl_IChatMessageReader2<D>::ReadBatchAsync(int32_t count) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessage>> result;
    check_hresult(WINRT_SHIM(IChatMessageReader2)->abi_ReadBatchWithCountAsync(count, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::IChatItem>> impl_IChatSearchReader<D>::ReadBatchAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::IChatItem>> result;
    check_hresult(WINRT_SHIM(IChatSearchReader)->abi_ReadBatchAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::IChatItem>> impl_IChatSearchReader<D>::ReadBatchAsync(int32_t count) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::IChatItem>> result;
    check_hresult(WINRT_SHIM(IChatSearchReader)->abi_ReadBatchWithCountAsync(count, put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Chat::ChatItemKind impl_IChatItem<D>::ItemKind() const
{
    Windows::ApplicationModel::Chat::ChatItemKind result {};
    check_hresult(WINRT_SHIM(IChatItem)->get_ItemKind(&result));
    return result;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IChatMessageAttachment<D>::DataStreamReference() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IChatMessageAttachment)->get_DataStreamReference(put_abi(value)));
    return value;
}

template <typename D> void impl_IChatMessageAttachment<D>::DataStreamReference(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IChatMessageAttachment)->put_DataStreamReference(get_abi(value)));
}

template <typename D> uint32_t impl_IChatMessageAttachment<D>::GroupId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IChatMessageAttachment)->get_GroupId(&value));
    return value;
}

template <typename D> void impl_IChatMessageAttachment<D>::GroupId(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IChatMessageAttachment)->put_GroupId(value));
}

template <typename D> hstring impl_IChatMessageAttachment<D>::MimeType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IChatMessageAttachment)->get_MimeType(put_abi(value)));
    return value;
}

template <typename D> void impl_IChatMessageAttachment<D>::MimeType(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IChatMessageAttachment)->put_MimeType(get_abi(value)));
}

template <typename D> hstring impl_IChatMessageAttachment<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IChatMessageAttachment)->get_Text(put_abi(value)));
    return value;
}

template <typename D> void impl_IChatMessageAttachment<D>::Text(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IChatMessageAttachment)->put_Text(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IChatMessageAttachment2<D>::Thumbnail() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference result;
    check_hresult(WINRT_SHIM(IChatMessageAttachment2)->get_Thumbnail(put_abi(result)));
    return result;
}

template <typename D> void impl_IChatMessageAttachment2<D>::Thumbnail(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IChatMessageAttachment2)->put_Thumbnail(get_abi(value)));
}

template <typename D> double impl_IChatMessageAttachment2<D>::TransferProgress() const
{
    double result {};
    check_hresult(WINRT_SHIM(IChatMessageAttachment2)->get_TransferProgress(&result));
    return result;
}

template <typename D> void impl_IChatMessageAttachment2<D>::TransferProgress(double value) const
{
    check_hresult(WINRT_SHIM(IChatMessageAttachment2)->put_TransferProgress(value));
}

template <typename D> hstring impl_IChatMessageAttachment2<D>::OriginalFileName() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IChatMessageAttachment2)->get_OriginalFileName(put_abi(result)));
    return result;
}

template <typename D> void impl_IChatMessageAttachment2<D>::OriginalFileName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IChatMessageAttachment2)->put_OriginalFileName(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessageAttachment impl_IChatMessageAttachmentFactory<D>::CreateChatMessageAttachment(hstring_view mimeType, const Windows::Storage::Streams::IRandomAccessStreamReference & dataStreamReference) const
{
    Windows::ApplicationModel::Chat::ChatMessageAttachment value { nullptr };
    check_hresult(WINRT_SHIM(IChatMessageAttachmentFactory)->abi_CreateChatMessageAttachment(get_abi(mimeType), get_abi(dataStreamReference), put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessage impl_IChatMessageNotificationTriggerDetails<D>::ChatMessage() const
{
    Windows::ApplicationModel::Chat::ChatMessage value { nullptr };
    check_hresult(WINRT_SHIM(IChatMessageNotificationTriggerDetails)->get_ChatMessage(put_abi(value)));
    return value;
}

template <typename D> bool impl_IChatMessageNotificationTriggerDetails2<D>::ShouldDisplayToast() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatMessageNotificationTriggerDetails2)->get_ShouldDisplayToast(&result));
    return result;
}

template <typename D> bool impl_IChatMessageNotificationTriggerDetails2<D>::ShouldUpdateDetailText() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatMessageNotificationTriggerDetails2)->get_ShouldUpdateDetailText(&result));
    return result;
}

template <typename D> bool impl_IChatMessageNotificationTriggerDetails2<D>::ShouldUpdateBadge() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatMessageNotificationTriggerDetails2)->get_ShouldUpdateBadge(&result));
    return result;
}

template <typename D> bool impl_IChatMessageNotificationTriggerDetails2<D>::ShouldUpdateActionCenter() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatMessageNotificationTriggerDetails2)->get_ShouldUpdateActionCenter(&result));
    return result;
}

template <typename D> bool impl_IChatCapabilities<D>::IsOnline() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatCapabilities)->get_IsOnline(&result));
    return result;
}

template <typename D> bool impl_IChatCapabilities<D>::IsChatCapable() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatCapabilities)->get_IsChatCapable(&result));
    return result;
}

template <typename D> bool impl_IChatCapabilities<D>::IsFileTransferCapable() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatCapabilities)->get_IsFileTransferCapable(&result));
    return result;
}

template <typename D> bool impl_IChatCapabilities<D>::IsGeoLocationPushCapable() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatCapabilities)->get_IsGeoLocationPushCapable(&result));
    return result;
}

template <typename D> bool impl_IChatCapabilities<D>::IsIntegratedMessagingCapable() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatCapabilities)->get_IsIntegratedMessagingCapable(&result));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatCapabilities> impl_IChatCapabilitiesManagerStatics<D>::GetCachedCapabilitiesAsync(hstring_view address) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatCapabilities> result;
    check_hresult(WINRT_SHIM(IChatCapabilitiesManagerStatics)->abi_GetCachedCapabilitiesAsync(get_abi(address), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatCapabilities> impl_IChatCapabilitiesManagerStatics<D>::GetCapabilitiesFromNetworkAsync(hstring_view address) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatCapabilities> result;
    check_hresult(WINRT_SHIM(IChatCapabilitiesManagerStatics)->abi_GetCapabilitiesFromNetworkAsync(get_abi(address), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IChatRecipientDeliveryInfo<D>::TransportAddress() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IChatRecipientDeliveryInfo)->get_TransportAddress(put_abi(result)));
    return result;
}

template <typename D> void impl_IChatRecipientDeliveryInfo<D>::TransportAddress(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IChatRecipientDeliveryInfo)->put_TransportAddress(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IChatRecipientDeliveryInfo<D>::DeliveryTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> result;
    check_hresult(WINRT_SHIM(IChatRecipientDeliveryInfo)->get_DeliveryTime(put_abi(result)));
    return result;
}

template <typename D> void impl_IChatRecipientDeliveryInfo<D>::DeliveryTime(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IChatRecipientDeliveryInfo)->put_DeliveryTime(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IChatRecipientDeliveryInfo<D>::ReadTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> result;
    check_hresult(WINRT_SHIM(IChatRecipientDeliveryInfo)->get_ReadTime(put_abi(result)));
    return result;
}

template <typename D> void impl_IChatRecipientDeliveryInfo<D>::ReadTime(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IChatRecipientDeliveryInfo)->put_ReadTime(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Chat::ChatTransportErrorCodeCategory impl_IChatRecipientDeliveryInfo<D>::TransportErrorCodeCategory() const
{
    Windows::ApplicationModel::Chat::ChatTransportErrorCodeCategory result {};
    check_hresult(WINRT_SHIM(IChatRecipientDeliveryInfo)->get_TransportErrorCodeCategory(&result));
    return result;
}

template <typename D> Windows::ApplicationModel::Chat::ChatTransportInterpretedErrorCode impl_IChatRecipientDeliveryInfo<D>::TransportInterpretedErrorCode() const
{
    Windows::ApplicationModel::Chat::ChatTransportInterpretedErrorCode result {};
    check_hresult(WINRT_SHIM(IChatRecipientDeliveryInfo)->get_TransportInterpretedErrorCode(&result));
    return result;
}

template <typename D> int32_t impl_IChatRecipientDeliveryInfo<D>::TransportErrorCode() const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(IChatRecipientDeliveryInfo)->get_TransportErrorCode(&result));
    return result;
}

template <typename D> bool impl_IChatRecipientDeliveryInfo<D>::IsErrorPermanent() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatRecipientDeliveryInfo)->get_IsErrorPermanent(&result));
    return result;
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessageStatus impl_IChatRecipientDeliveryInfo<D>::Status() const
{
    Windows::ApplicationModel::Chat::ChatMessageStatus result {};
    check_hresult(WINRT_SHIM(IChatRecipientDeliveryInfo)->get_Status(&result));
    return result;
}

template <typename D> hstring impl_IChatConversationThreadingInfo<D>::ContactId() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IChatConversationThreadingInfo)->get_ContactId(put_abi(result)));
    return result;
}

template <typename D> void impl_IChatConversationThreadingInfo<D>::ContactId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IChatConversationThreadingInfo)->put_ContactId(get_abi(value)));
}

template <typename D> hstring impl_IChatConversationThreadingInfo<D>::Custom() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IChatConversationThreadingInfo)->get_Custom(put_abi(result)));
    return result;
}

template <typename D> void impl_IChatConversationThreadingInfo<D>::Custom(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IChatConversationThreadingInfo)->put_Custom(get_abi(value)));
}

template <typename D> hstring impl_IChatConversationThreadingInfo<D>::ConversationId() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IChatConversationThreadingInfo)->get_ConversationId(put_abi(result)));
    return result;
}

template <typename D> void impl_IChatConversationThreadingInfo<D>::ConversationId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IChatConversationThreadingInfo)->put_ConversationId(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IChatConversationThreadingInfo<D>::Participants() const
{
    Windows::Foundation::Collections::IVector<hstring> result;
    check_hresult(WINRT_SHIM(IChatConversationThreadingInfo)->get_Participants(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Chat::ChatConversationThreadingKind impl_IChatConversationThreadingInfo<D>::Kind() const
{
    Windows::ApplicationModel::Chat::ChatConversationThreadingKind result {};
    check_hresult(WINRT_SHIM(IChatConversationThreadingInfo)->get_Kind(&result));
    return result;
}

template <typename D> void impl_IChatConversationThreadingInfo<D>::Kind(Windows::ApplicationModel::Chat::ChatConversationThreadingKind value) const
{
    check_hresult(WINRT_SHIM(IChatConversationThreadingInfo)->put_Kind(value));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatConversation>> impl_IChatConversationReader<D>::ReadBatchAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatConversation>> result;
    check_hresult(WINRT_SHIM(IChatConversationReader)->abi_ReadBatchAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatConversation>> impl_IChatConversationReader<D>::ReadBatchAsync(int32_t count) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatConversation>> result;
    check_hresult(WINRT_SHIM(IChatConversationReader)->abi_ReadBatchWithCountAsync(count, put_abi(result)));
    return result;
}

template <typename D> bool impl_IChatConversation<D>::HasUnreadMessages() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatConversation)->get_HasUnreadMessages(&result));
    return result;
}

template <typename D> hstring impl_IChatConversation<D>::Id() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IChatConversation)->get_Id(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IChatConversation<D>::Subject() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IChatConversation)->get_Subject(put_abi(result)));
    return result;
}

template <typename D> void impl_IChatConversation<D>::Subject(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IChatConversation)->put_Subject(get_abi(value)));
}

template <typename D> bool impl_IChatConversation<D>::IsConversationMuted() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatConversation)->get_IsConversationMuted(&result));
    return result;
}

template <typename D> void impl_IChatConversation<D>::IsConversationMuted(bool value) const
{
    check_hresult(WINRT_SHIM(IChatConversation)->put_IsConversationMuted(value));
}

template <typename D> hstring impl_IChatConversation<D>::MostRecentMessageId() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IChatConversation)->get_MostRecentMessageId(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IChatConversation<D>::Participants() const
{
    Windows::Foundation::Collections::IVector<hstring> result;
    check_hresult(WINRT_SHIM(IChatConversation)->get_Participants(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Chat::ChatConversationThreadingInfo impl_IChatConversation<D>::ThreadingInfo() const
{
    Windows::ApplicationModel::Chat::ChatConversationThreadingInfo result { nullptr };
    check_hresult(WINRT_SHIM(IChatConversation)->get_ThreadingInfo(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatConversation<D>::DeleteAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IChatConversation)->abi_DeleteAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Chat::ChatMessageReader impl_IChatConversation<D>::GetMessageReader() const
{
    Windows::ApplicationModel::Chat::ChatMessageReader result { nullptr };
    check_hresult(WINRT_SHIM(IChatConversation)->abi_GetMessageReader(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatConversation<D>::MarkMessagesAsReadAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IChatConversation)->abi_MarkAllMessagesAsReadAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatConversation<D>::MarkMessagesAsReadAsync(const Windows::Foundation::DateTime & value) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IChatConversation)->abi_MarkMessagesAsReadAsync(get_abi(value), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatConversation<D>::SaveAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IChatConversation)->abi_SaveAsync(put_abi(result)));
    return result;
}

template <typename D> void impl_IChatConversation<D>::NotifyLocalParticipantComposing(hstring_view transportId, hstring_view participantAddress, bool isComposing) const
{
    check_hresult(WINRT_SHIM(IChatConversation)->abi_NotifyLocalParticipantComposing(get_abi(transportId), get_abi(participantAddress), isComposing));
}

template <typename D> void impl_IChatConversation<D>::NotifyRemoteParticipantComposing(hstring_view transportId, hstring_view participantAddress, bool isComposing) const
{
    check_hresult(WINRT_SHIM(IChatConversation)->abi_NotifyRemoteParticipantComposing(get_abi(transportId), get_abi(participantAddress), isComposing));
}

template <typename D> event_token impl_IChatConversation<D>::RemoteParticipantComposingChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatConversation, Windows::ApplicationModel::Chat::RemoteParticipantComposingChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IChatConversation)->add_RemoteParticipantComposingChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IChatConversation> impl_IChatConversation<D>::RemoteParticipantComposingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatConversation, Windows::ApplicationModel::Chat::RemoteParticipantComposingChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IChatConversation>(this, &ABI::Windows::ApplicationModel::Chat::IChatConversation::remove_RemoteParticipantComposingChanged, RemoteParticipantComposingChanged(handler));
}

template <typename D> void impl_IChatConversation<D>::RemoteParticipantComposingChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IChatConversation)->remove_RemoteParticipantComposingChanged(token));
}

template <typename D> bool impl_IChatConversation2<D>::CanModifyParticipants() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatConversation2)->get_CanModifyParticipants(&result));
    return result;
}

template <typename D> void impl_IChatConversation2<D>::CanModifyParticipants(bool value) const
{
    check_hresult(WINRT_SHIM(IChatConversation2)->put_CanModifyParticipants(value));
}

template <typename D> hstring impl_IRemoteParticipantComposingChangedEventArgs<D>::TransportId() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IRemoteParticipantComposingChangedEventArgs)->get_TransportId(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IRemoteParticipantComposingChangedEventArgs<D>::ParticipantAddress() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IRemoteParticipantComposingChangedEventArgs)->get_ParticipantAddress(put_abi(result)));
    return result;
}

template <typename D> bool impl_IRemoteParticipantComposingChangedEventArgs<D>::IsComposing() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IRemoteParticipantComposingChangedEventArgs)->get_IsComposing(&result));
    return result;
}

template <typename D> Windows::ApplicationModel::Chat::ChatSyncConfiguration impl_IChatSyncManager<D>::Configuration() const
{
    Windows::ApplicationModel::Chat::ChatSyncConfiguration result { nullptr };
    check_hresult(WINRT_SHIM(IChatSyncManager)->get_Configuration(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatSyncManager<D>::AssociateAccountAsync(const Windows::Security::Credentials::WebAccount & webAccount) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IChatSyncManager)->abi_AssociateAccountAsync(get_abi(webAccount), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatSyncManager<D>::UnassociateAccountAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IChatSyncManager)->abi_UnassociateAccountAsync(put_abi(result)));
    return result;
}

template <typename D> bool impl_IChatSyncManager<D>::IsAccountAssociated(const Windows::Security::Credentials::WebAccount & webAccount) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatSyncManager)->abi_IsAccountAssociated(get_abi(webAccount), &result));
    return result;
}

template <typename D> void impl_IChatSyncManager<D>::StartSync() const
{
    check_hresult(WINRT_SHIM(IChatSyncManager)->abi_StartSync());
}

template <typename D> Windows::Foundation::IAsyncAction impl_IChatSyncManager<D>::SetConfigurationAsync(const Windows::ApplicationModel::Chat::ChatSyncConfiguration & configuration) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IChatSyncManager)->abi_SetConfigurationAsync(get_abi(configuration), put_abi(result)));
    return result;
}

template <typename D> bool impl_IChatSyncConfiguration<D>::IsSyncEnabled() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IChatSyncConfiguration)->get_IsSyncEnabled(&result));
    return result;
}

template <typename D> void impl_IChatSyncConfiguration<D>::IsSyncEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IChatSyncConfiguration)->put_IsSyncEnabled(value));
}

template <typename D> Windows::ApplicationModel::Chat::ChatRestoreHistorySpan impl_IChatSyncConfiguration<D>::RestoreHistorySpan() const
{
    Windows::ApplicationModel::Chat::ChatRestoreHistorySpan result {};
    check_hresult(WINRT_SHIM(IChatSyncConfiguration)->get_RestoreHistorySpan(&result));
    return result;
}

template <typename D> void impl_IChatSyncConfiguration<D>::RestoreHistorySpan(Windows::ApplicationModel::Chat::ChatRestoreHistorySpan value) const
{
    check_hresult(WINRT_SHIM(IChatSyncConfiguration)->put_RestoreHistorySpan(value));
}

template <typename D> Windows::ApplicationModel::Chat::RcsServiceKind impl_IRcsServiceKindSupportedChangedEventArgs<D>::ServiceKind() const
{
    Windows::ApplicationModel::Chat::RcsServiceKind result {};
    check_hresult(WINRT_SHIM(IRcsServiceKindSupportedChangedEventArgs)->get_ServiceKind(&result));
    return result;
}

template <typename D> Windows::ApplicationModel::Chat::RcsEndUserMessageManager impl_IRcsManagerStatics<D>::GetEndUserMessageManager() const
{
    Windows::ApplicationModel::Chat::RcsEndUserMessageManager result { nullptr };
    check_hresult(WINRT_SHIM(IRcsManagerStatics)->abi_GetEndUserMessageManager(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::RcsTransport>> impl_IRcsManagerStatics<D>::GetTransportsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::RcsTransport>> value;
    check_hresult(WINRT_SHIM(IRcsManagerStatics)->abi_GetTransportsAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::RcsTransport> impl_IRcsManagerStatics<D>::GetTransportAsync(hstring_view transportId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::RcsTransport> result;
    check_hresult(WINRT_SHIM(IRcsManagerStatics)->abi_GetTransportAsync(get_abi(transportId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IRcsManagerStatics<D>::LeaveConversationAsync(const Windows::ApplicationModel::Chat::ChatConversation & conversation) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IRcsManagerStatics)->abi_LeaveConversationAsync(get_abi(conversation), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_IRcsTransport<D>::ExtendedProperties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IRcsTransport)->get_ExtendedProperties(put_abi(value)));
    return value;
}

template <typename D> bool impl_IRcsTransport<D>::IsActive() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IRcsTransport)->get_IsActive(&value));
    return value;
}

template <typename D> hstring impl_IRcsTransport<D>::TransportFriendlyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRcsTransport)->get_TransportFriendlyName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRcsTransport<D>::TransportId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRcsTransport)->get_TransportId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Chat::RcsTransportConfiguration impl_IRcsTransport<D>::Configuration() const
{
    Windows::ApplicationModel::Chat::RcsTransportConfiguration result { nullptr };
    check_hresult(WINRT_SHIM(IRcsTransport)->get_Configuration(put_abi(result)));
    return result;
}

template <typename D> bool impl_IRcsTransport<D>::IsStoreAndForwardEnabled(Windows::ApplicationModel::Chat::RcsServiceKind serviceKind) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IRcsTransport)->abi_IsStoreAndForwardEnabled(serviceKind, &result));
    return result;
}

template <typename D> bool impl_IRcsTransport<D>::IsServiceKindSupported(Windows::ApplicationModel::Chat::RcsServiceKind serviceKind) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IRcsTransport)->abi_IsServiceKindSupported(serviceKind, &result));
    return result;
}

template <typename D> event_token impl_IRcsTransport<D>::ServiceKindSupportedChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::RcsTransport, Windows::ApplicationModel::Chat::RcsServiceKindSupportedChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IRcsTransport)->add_ServiceKindSupportedChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IRcsTransport> impl_IRcsTransport<D>::ServiceKindSupportedChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::RcsTransport, Windows::ApplicationModel::Chat::RcsServiceKindSupportedChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IRcsTransport>(this, &ABI::Windows::ApplicationModel::Chat::IRcsTransport::remove_ServiceKindSupportedChanged, ServiceKindSupportedChanged(handler));
}

template <typename D> void impl_IRcsTransport<D>::ServiceKindSupportedChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IRcsTransport)->remove_ServiceKindSupportedChanged(token));
}

template <typename D> int32_t impl_IRcsTransportConfiguration<D>::MaxAttachmentCount() const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(IRcsTransportConfiguration)->get_MaxAttachmentCount(&result));
    return result;
}

template <typename D> int32_t impl_IRcsTransportConfiguration<D>::MaxMessageSizeInKilobytes() const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(IRcsTransportConfiguration)->get_MaxMessageSizeInKilobytes(&result));
    return result;
}

template <typename D> int32_t impl_IRcsTransportConfiguration<D>::MaxGroupMessageSizeInKilobytes() const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(IRcsTransportConfiguration)->get_MaxGroupMessageSizeInKilobytes(&result));
    return result;
}

template <typename D> int32_t impl_IRcsTransportConfiguration<D>::MaxRecipientCount() const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(IRcsTransportConfiguration)->get_MaxRecipientCount(&result));
    return result;
}

template <typename D> int32_t impl_IRcsTransportConfiguration<D>::MaxFileSizeInKilobytes() const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(IRcsTransportConfiguration)->get_MaxFileSizeInKilobytes(&result));
    return result;
}

template <typename D> int32_t impl_IRcsTransportConfiguration<D>::WarningFileSizeInKilobytes() const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(IRcsTransportConfiguration)->get_WarningFileSizeInKilobytes(&result));
    return result;
}

template <typename D> event_token impl_IRcsEndUserMessageManager<D>::MessageAvailableChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::RcsEndUserMessageManager, Windows::ApplicationModel::Chat::RcsEndUserMessageAvailableEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IRcsEndUserMessageManager)->add_MessageAvailableChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IRcsEndUserMessageManager> impl_IRcsEndUserMessageManager<D>::MessageAvailableChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::RcsEndUserMessageManager, Windows::ApplicationModel::Chat::RcsEndUserMessageAvailableEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IRcsEndUserMessageManager>(this, &ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageManager::remove_MessageAvailableChanged, MessageAvailableChanged(handler));
}

template <typename D> void impl_IRcsEndUserMessageManager<D>::MessageAvailableChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IRcsEndUserMessageManager)->remove_MessageAvailableChanged(token));
}

template <typename D> hstring impl_IRcsEndUserMessageAction<D>::Label() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IRcsEndUserMessageAction)->get_Label(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IRcsEndUserMessage<D>::TransportId() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IRcsEndUserMessage)->get_TransportId(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IRcsEndUserMessage<D>::Title() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IRcsEndUserMessage)->get_Title(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IRcsEndUserMessage<D>::Text() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IRcsEndUserMessage)->get_Text(put_abi(result)));
    return result;
}

template <typename D> bool impl_IRcsEndUserMessage<D>::IsPinRequired() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IRcsEndUserMessage)->get_IsPinRequired(&result));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::RcsEndUserMessageAction> impl_IRcsEndUserMessage<D>::Actions() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::RcsEndUserMessageAction> result;
    check_hresult(WINRT_SHIM(IRcsEndUserMessage)->get_Actions(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IRcsEndUserMessage<D>::SendResponseAsync(const Windows::ApplicationModel::Chat::RcsEndUserMessageAction & action) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IRcsEndUserMessage)->abi_SendResponseAsync(get_abi(action), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IRcsEndUserMessage<D>::SendResponseWithPinAsync(const Windows::ApplicationModel::Chat::RcsEndUserMessageAction & action, hstring_view pin) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IRcsEndUserMessage)->abi_SendResponseWithPinAsync(get_abi(action), get_abi(pin), put_abi(result)));
    return result;
}

template <typename D> bool impl_IRcsEndUserMessageAvailableEventArgs<D>::IsMessageAvailable() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IRcsEndUserMessageAvailableEventArgs)->get_IsMessageAvailable(&result));
    return result;
}

template <typename D> Windows::ApplicationModel::Chat::RcsEndUserMessage impl_IRcsEndUserMessageAvailableEventArgs<D>::Message() const
{
    Windows::ApplicationModel::Chat::RcsEndUserMessage result { nullptr };
    check_hresult(WINRT_SHIM(IRcsEndUserMessageAvailableEventArgs)->get_Message(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IRcsEndUserMessageAvailableTriggerDetails<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRcsEndUserMessageAvailableTriggerDetails)->get_Title(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRcsEndUserMessageAvailableTriggerDetails<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRcsEndUserMessageAvailableTriggerDetails)->get_Text(put_abi(value)));
    return value;
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatCapabilities> ChatCapabilitiesManager::GetCachedCapabilitiesAsync(hstring_view address)
{
    return get_activation_factory<ChatCapabilitiesManager, IChatCapabilitiesManagerStatics>().GetCachedCapabilitiesAsync(address);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatCapabilities> ChatCapabilitiesManager::GetCapabilitiesFromNetworkAsync(hstring_view address)
{
    return get_activation_factory<ChatCapabilitiesManager, IChatCapabilitiesManagerStatics>().GetCapabilitiesFromNetworkAsync(address);
}

inline ChatConversationThreadingInfo::ChatConversationThreadingInfo() :
    ChatConversationThreadingInfo(activate_instance<ChatConversationThreadingInfo>())
{}

inline ChatMessage::ChatMessage() :
    ChatMessage(activate_instance<ChatMessage>())
{}

inline ChatMessageAttachment::ChatMessageAttachment(hstring_view mimeType, const Windows::Storage::Streams::IRandomAccessStreamReference & dataStreamReference) :
    ChatMessageAttachment(get_activation_factory<ChatMessageAttachment, IChatMessageAttachmentFactory>().CreateChatMessageAttachment(mimeType, dataStreamReference))
{}

inline Windows::Foundation::IAsyncAction ChatMessageBlocking::MarkMessageAsBlockedAsync(hstring_view localChatMessageId, bool blocked)
{
    return get_activation_factory<ChatMessageBlocking, IChatMessageBlockingStatic>().MarkMessageAsBlockedAsync(localChatMessageId, blocked);
}

inline Windows::Foundation::IAsyncOperation<hstring> ChatMessageManager::RegisterTransportAsync()
{
    return get_activation_factory<ChatMessageManager, IChatMessageManager2Statics>().RegisterTransportAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessageTransport> ChatMessageManager::GetTransportAsync(hstring_view transportId)
{
    return get_activation_factory<ChatMessageManager, IChatMessageManager2Statics>().GetTransportAsync(transportId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessageTransport>> ChatMessageManager::GetTransportsAsync()
{
    return get_activation_factory<ChatMessageManager, IChatMessageManagerStatic>().GetTransportsAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessageStore> ChatMessageManager::RequestStoreAsync()
{
    return get_activation_factory<ChatMessageManager, IChatMessageManagerStatic>().RequestStoreAsync();
}

inline Windows::Foundation::IAsyncAction ChatMessageManager::ShowComposeSmsMessageAsync(const Windows::ApplicationModel::Chat::ChatMessage & message)
{
    return get_activation_factory<ChatMessageManager, IChatMessageManagerStatic>().ShowComposeSmsMessageAsync(message);
}

inline void ChatMessageManager::ShowSmsSettings()
{
    get_activation_factory<ChatMessageManager, IChatMessageManagerStatic>().ShowSmsSettings();
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatSyncManager> ChatMessageManager::RequestSyncManagerAsync()
{
    return get_activation_factory<ChatMessageManager, IChatMessageManagerStatics3>().RequestSyncManagerAsync();
}

inline ChatQueryOptions::ChatQueryOptions() :
    ChatQueryOptions(activate_instance<ChatQueryOptions>())
{}

inline ChatRecipientDeliveryInfo::ChatRecipientDeliveryInfo() :
    ChatRecipientDeliveryInfo(activate_instance<ChatRecipientDeliveryInfo>())
{}

inline Windows::ApplicationModel::Chat::RcsEndUserMessageManager RcsManager::GetEndUserMessageManager()
{
    return get_activation_factory<RcsManager, IRcsManagerStatics>().GetEndUserMessageManager();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::RcsTransport>> RcsManager::GetTransportsAsync()
{
    return get_activation_factory<RcsManager, IRcsManagerStatics>().GetTransportsAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::RcsTransport> RcsManager::GetTransportAsync(hstring_view transportId)
{
    return get_activation_factory<RcsManager, IRcsManagerStatics>().GetTransportAsync(transportId);
}

inline Windows::Foundation::IAsyncAction RcsManager::LeaveConversationAsync(const Windows::ApplicationModel::Chat::ChatConversation & conversation)
{
    return get_activation_factory<RcsManager, IRcsManagerStatics>().LeaveConversationAsync(conversation);
}

}

}
#pragma warning(pop)
