// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.ApplicationModel.Contacts.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.ApplicationModel.Calls.3.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::ICallAnswerEventArgs> : produce_base<D, Windows::ApplicationModel::Calls::ICallAnswerEventArgs>
{
    HRESULT __stdcall get_AcceptedMedia(Windows::ApplicationModel::Calls::VoipPhoneCallMedia * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AcceptedMedia());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::ICallRejectEventArgs> : produce_base<D, Windows::ApplicationModel::Calls::ICallRejectEventArgs>
{
    HRESULT __stdcall get_RejectReason(Windows::ApplicationModel::Calls::VoipPhoneCallRejectReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RejectReason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::ICallStateChangeEventArgs> : produce_base<D, Windows::ApplicationModel::Calls::ICallStateChangeEventArgs>
{
    HRESULT __stdcall get_State(Windows::ApplicationModel::Calls::VoipPhoneCallState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().State());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::ILockScreenCallEndCallDeferral> : produce_base<D, Windows::ApplicationModel::Calls::ILockScreenCallEndCallDeferral>
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
struct produce<D, Windows::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs> : produce_base<D, Windows::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs>
{
    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::ApplicationModel::Calls::ILockScreenCallEndCallDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::Calls::ILockScreenCallUI> : produce_base<D, Windows::ApplicationModel::Calls::ILockScreenCallUI>
{
    HRESULT __stdcall abi_Dismiss() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Dismiss();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_EndRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::LockScreenCallUI, Windows::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().EndRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::LockScreenCallUI, Windows::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_EndRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EndRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Closed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::LockScreenCallUI, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Closed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::LockScreenCallUI, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Closed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Closed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CallTitle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CallTitle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CallTitle(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CallTitle(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IMuteChangeEventArgs> : produce_base<D, Windows::ApplicationModel::Calls::IMuteChangeEventArgs>
{
    HRESULT __stdcall get_Muted(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Muted());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallBlockingStatics> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallBlockingStatics>
{
    HRESULT __stdcall get_BlockUnknownNumbers(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BlockUnknownNumbers());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BlockUnknownNumbers(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BlockUnknownNumbers(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BlockPrivateNumbers(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BlockPrivateNumbers());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BlockPrivateNumbers(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BlockPrivateNumbers(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetCallBlockingListAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> phoneNumberList, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SetCallBlockingListAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&phoneNumberList)));
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
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>
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

    HRESULT __stdcall get_Address(impl::abi_arg_out<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> value) noexcept override
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

    HRESULT __stdcall put_Address(impl::abi_arg_in<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Address(*reinterpret_cast<const Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duration(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
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

    HRESULT __stdcall put_Duration(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Duration(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCallerIdBlocked(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCallerIdBlocked());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsCallerIdBlocked(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsCallerIdBlocked(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsEmergency(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEmergency());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsEmergency(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEmergency(value);
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

    HRESULT __stdcall get_IsMissed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMissed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsMissed(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsMissed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsRinging(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsRinging());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsRinging(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsRinging(value);
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

    HRESULT __stdcall get_IsSuppressed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSuppressed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsSuppressed(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsSuppressed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsVoicemail(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsVoicemail());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsVoicemail(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsVoicemail(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Media(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Media());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Media(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Media(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OtherAppReadAccess(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess * value) noexcept override
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

    HRESULT __stdcall put_OtherAppReadAccess(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess value) noexcept override
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

    HRESULT __stdcall get_SourceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SourceId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceIdKind(Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceIdKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SourceIdKind(Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceIdKind(value);
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
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>
{
    HRESULT __stdcall get_ContactId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContactId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
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

    HRESULT __stdcall get_RawAddress(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RawAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RawAddress(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RawAddress(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RawAddressKind(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RawAddressKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RawAddressKind(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RawAddressKind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> rawAddress, Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind rawAddressKind, impl::abi_arg_out<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&rawAddress), rawAddressKind));
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
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions>
{
    HRESULT __stdcall get_DesiredMedia(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredMedia());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredMedia(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredMedia(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceIds(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceIds());
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
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader>
{
    HRESULT __stdcall abi_ReadBatchAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>>> result) noexcept override
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
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser>
{
    HRESULT __stdcall abi_RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore>> result) noexcept override
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
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics>
{
    HRESULT __stdcall abi_RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore>> result) noexcept override
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
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2>
{
    HRESULT __stdcall abi_GetForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_out<Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser> result) noexcept override
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
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryStore> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>
{
    HRESULT __stdcall abi_GetEntryAsync(impl::abi_arg_in<hstring> callHistoryEntryId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetEntryAsync(*reinterpret_cast<const hstring *>(&callHistoryEntryId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEntryReader(impl::abi_arg_out<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetEntryReader());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEntryReaderWithOptions(impl::abi_arg_in<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions> queryOptions, impl::abi_arg_out<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetEntryReader(*reinterpret_cast<const Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions *>(&queryOptions)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveEntryAsync(impl::abi_arg_in<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry> callHistoryEntry, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SaveEntryAsync(*reinterpret_cast<const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry *>(&callHistoryEntry)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteEntryAsync(impl::abi_arg_in<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry> callHistoryEntry, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DeleteEntryAsync(*reinterpret_cast<const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry *>(&callHistoryEntry)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteEntriesAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> callHistoryEntries, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DeleteEntriesAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> *>(&callHistoryEntries)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkEntryAsSeenAsync(impl::abi_arg_in<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry> callHistoryEntry, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MarkEntryAsSeenAsync(*reinterpret_cast<const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry *>(&callHistoryEntry)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkEntriesAsSeenAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> callHistoryEntries, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MarkEntriesAsSeenAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> *>(&callHistoryEntries)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetUnseenCountAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<uint32_t>> result) noexcept override
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

    HRESULT __stdcall abi_MarkAllAsSeenAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MarkAllAsSeenAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSourcesUnseenCountAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> sourceIds, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<uint32_t>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetSourcesUnseenCountAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&sourceIds)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkSourcesAsSeenAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> sourceIds, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MarkSourcesAsSeenAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&sourceIds)));
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
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallManagerStatics> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallManagerStatics>
{
    HRESULT __stdcall abi_ShowPhoneCallUI(impl::abi_arg_in<hstring> phoneNumber, impl::abi_arg_in<hstring> displayName) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowPhoneCallUI(*reinterpret_cast<const hstring *>(&phoneNumber), *reinterpret_cast<const hstring *>(&displayName));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallManagerStatics2> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallManagerStatics2>
{
    HRESULT __stdcall add_CallStateChanged(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CallStateChanged(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CallStateChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CallStateChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCallActive(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCallActive());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCallIncoming(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCallIncoming());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowPhoneCallSettingsUI() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowPhoneCallSettingsUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestStoreAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallStore>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestStoreAsync());
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
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallStore> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallStore>
{
    HRESULT __stdcall abi_IsEmergencyPhoneNumberAsync(impl::abi_arg_in<hstring> number, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsEmergencyPhoneNumberAsync(*reinterpret_cast<const hstring *>(&number)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDefaultLineAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<GUID>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDefaultLineAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestLineWatcher(impl::abi_arg_out<Windows::ApplicationModel::Calls::IPhoneLineWatcher> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestLineWatcher());
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
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilities> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilities>
{
    HRESULT __stdcall get_IsVideoCallingCapable(bool * pValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pValue = detach_abi(this->shim().IsVideoCallingCapable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilitiesManagerStatics> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilitiesManagerStatics>
{
    HRESULT __stdcall abi_GetCapabilitiesAsync(impl::abi_arg_in<hstring> phoneNumber, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallVideoCapabilities>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetCapabilitiesAsync(*reinterpret_cast<const hstring *>(&phoneNumber)));
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
struct produce<D, Windows::ApplicationModel::Calls::IPhoneDialOptions> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneDialOptions>
{
    HRESULT __stdcall get_Number(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Number());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Number(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Number(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall get_Contact(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContact> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Contact());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Contact(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Contact(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContactPhone(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactPhone> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContactPhone());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContactPhone(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContactPhone> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContactPhone(*reinterpret_cast<const Windows::ApplicationModel::Contacts::ContactPhone *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Media(Windows::ApplicationModel::Calls::PhoneCallMedia * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Media());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Media(Windows::ApplicationModel::Calls::PhoneCallMedia value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Media(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioEndpoint(Windows::ApplicationModel::Calls::PhoneAudioRoutingEndpoint * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioEndpoint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AudioEndpoint(Windows::ApplicationModel::Calls::PhoneAudioRoutingEndpoint value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioEndpoint(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IPhoneLine> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneLine>
{
    HRESULT __stdcall add_LineChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLine, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().LineChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLine, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LineChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LineChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Id(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NetworkState(Windows::ApplicationModel::Calls::PhoneNetworkState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkState());
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall get_Voicemail(impl::abi_arg_out<Windows::ApplicationModel::Calls::IPhoneVoicemail> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Voicemail());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NetworkName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CellularDetails(impl::abi_arg_out<Windows::ApplicationModel::Calls::IPhoneLineCellularDetails> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CellularDetails());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Transport(Windows::ApplicationModel::Calls::PhoneLineTransport * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Transport());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanDial(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanDial());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportsTile(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportsTile());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoCallingCapabilities(impl::abi_arg_out<Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoCallingCapabilities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LineConfiguration(impl::abi_arg_out<Windows::ApplicationModel::Calls::IPhoneLineConfiguration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LineConfiguration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsImmediateDialNumberAsync(impl::abi_arg_in<hstring> number, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsImmediateDialNumberAsync(*reinterpret_cast<const hstring *>(&number)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Dial(impl::abi_arg_in<hstring> number, impl::abi_arg_in<hstring> displayName) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Dial(*reinterpret_cast<const hstring *>(&number), *reinterpret_cast<const hstring *>(&displayName));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DialWithOptions(impl::abi_arg_in<Windows::ApplicationModel::Calls::IPhoneDialOptions> options) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DialWithOptions(*reinterpret_cast<const Windows::ApplicationModel::Calls::PhoneDialOptions *>(&options));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IPhoneLineCellularDetails> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneLineCellularDetails>
{
    HRESULT __stdcall get_SimState(Windows::ApplicationModel::Calls::PhoneSimState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SimState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SimSlotIndex(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SimSlotIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsModemOn(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsModemOn());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RegistrationRejectCode(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RegistrationRejectCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNetworkOperatorDisplayText(Windows::ApplicationModel::Calls::PhoneLineNetworkOperatorDisplayTextLocation location, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetNetworkOperatorDisplayText(location));
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
struct produce<D, Windows::ApplicationModel::Calls::IPhoneLineConfiguration> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneLineConfiguration>
{
    HRESULT __stdcall get_IsVideoCallingEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsVideoCallingEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IPhoneLineStatics> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneLineStatics>
{
    HRESULT __stdcall abi_FromIdAsync(GUID lineId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneLine>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FromIdAsync(lineId));
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
struct produce<D, Windows::ApplicationModel::Calls::IPhoneLineWatcher> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneLineWatcher>
{
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

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_LineAdded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().LineAdded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LineAdded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LineAdded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_LineRemoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().LineRemoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LineRemoved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LineRemoved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_LineUpdated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().LineUpdated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LineUpdated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LineUpdated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_EnumerationCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().EnumerationCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_EnumerationCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Stopped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Stopped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Stopped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::ApplicationModel::Calls::PhoneLineWatcherStatus * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IPhoneLineWatcherEventArgs> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneLineWatcherEventArgs>
{
    HRESULT __stdcall get_LineId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LineId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IPhoneVoicemail> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneVoicemail>
{
    HRESULT __stdcall get_Number(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Number());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageCount(int32_t * value) noexcept override
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

    HRESULT __stdcall get_Type(Windows::ApplicationModel::Calls::PhoneVoicemailType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DialVoicemailAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DialVoicemailAsync());
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
struct produce<D, Windows::ApplicationModel::Calls::IVoipCallCoordinator> : produce_base<D, Windows::ApplicationModel::Calls::IVoipCallCoordinator>
{
    HRESULT __stdcall abi_ReserveCallResourcesAsync(impl::abi_arg_in<hstring> taskEntryPoint, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ReserveCallResourcesAsync(*reinterpret_cast<const hstring *>(&taskEntryPoint)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MuteStateChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs>> muteChangeHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MuteStateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> *>(&muteChangeHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MuteStateChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MuteStateChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestNewIncomingCall(impl::abi_arg_in<hstring> context, impl::abi_arg_in<hstring> contactName, impl::abi_arg_in<hstring> contactNumber, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> contactImage, impl::abi_arg_in<hstring> serviceName, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> brandingImage, impl::abi_arg_in<hstring> callDetails, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> ringtone, Windows::ApplicationModel::Calls::VoipPhoneCallMedia media, impl::abi_arg_in<Windows::Foundation::TimeSpan> ringTimeout, impl::abi_arg_out<Windows::ApplicationModel::Calls::IVoipPhoneCall> call) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *call = detach_abi(this->shim().RequestNewIncomingCall(*reinterpret_cast<const hstring *>(&context), *reinterpret_cast<const hstring *>(&contactName), *reinterpret_cast<const hstring *>(&contactNumber), *reinterpret_cast<const Windows::Foundation::Uri *>(&contactImage), *reinterpret_cast<const hstring *>(&serviceName), *reinterpret_cast<const Windows::Foundation::Uri *>(&brandingImage), *reinterpret_cast<const hstring *>(&callDetails), *reinterpret_cast<const Windows::Foundation::Uri *>(&ringtone), media, *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&ringTimeout)));
            return S_OK;
        }
        catch (...)
        {
            *call = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestNewOutgoingCall(impl::abi_arg_in<hstring> context, impl::abi_arg_in<hstring> contactName, impl::abi_arg_in<hstring> serviceName, Windows::ApplicationModel::Calls::VoipPhoneCallMedia media, impl::abi_arg_out<Windows::ApplicationModel::Calls::IVoipPhoneCall> call) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *call = detach_abi(this->shim().RequestNewOutgoingCall(*reinterpret_cast<const hstring *>(&context), *reinterpret_cast<const hstring *>(&contactName), *reinterpret_cast<const hstring *>(&serviceName), media));
            return S_OK;
        }
        catch (...)
        {
            *call = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyMuted() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyMuted();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyUnmuted() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyUnmuted();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestOutgoingUpgradeToVideoCall(GUID callUpgradeGuid, impl::abi_arg_in<hstring> context, impl::abi_arg_in<hstring> contactName, impl::abi_arg_in<hstring> serviceName, impl::abi_arg_out<Windows::ApplicationModel::Calls::IVoipPhoneCall> call) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *call = detach_abi(this->shim().RequestOutgoingUpgradeToVideoCall(callUpgradeGuid, *reinterpret_cast<const hstring *>(&context), *reinterpret_cast<const hstring *>(&contactName), *reinterpret_cast<const hstring *>(&serviceName)));
            return S_OK;
        }
        catch (...)
        {
            *call = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestIncomingUpgradeToVideoCall(impl::abi_arg_in<hstring> context, impl::abi_arg_in<hstring> contactName, impl::abi_arg_in<hstring> contactNumber, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> contactImage, impl::abi_arg_in<hstring> serviceName, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> brandingImage, impl::abi_arg_in<hstring> callDetails, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> ringtone, impl::abi_arg_in<Windows::Foundation::TimeSpan> ringTimeout, impl::abi_arg_out<Windows::ApplicationModel::Calls::IVoipPhoneCall> call) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *call = detach_abi(this->shim().RequestIncomingUpgradeToVideoCall(*reinterpret_cast<const hstring *>(&context), *reinterpret_cast<const hstring *>(&contactName), *reinterpret_cast<const hstring *>(&contactNumber), *reinterpret_cast<const Windows::Foundation::Uri *>(&contactImage), *reinterpret_cast<const hstring *>(&serviceName), *reinterpret_cast<const Windows::Foundation::Uri *>(&brandingImage), *reinterpret_cast<const hstring *>(&callDetails), *reinterpret_cast<const Windows::Foundation::Uri *>(&ringtone), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&ringTimeout)));
            return S_OK;
        }
        catch (...)
        {
            *call = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TerminateCellularCall(GUID callUpgradeGuid) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TerminateCellularCall(callUpgradeGuid);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CancelUpgrade(GUID callUpgradeGuid) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CancelUpgrade(callUpgradeGuid);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IVoipCallCoordinatorStatics> : produce_base<D, Windows::ApplicationModel::Calls::IVoipCallCoordinatorStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::ApplicationModel::Calls::IVoipCallCoordinator> coordinator) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *coordinator = detach_abi(this->shim().GetDefault());
            return S_OK;
        }
        catch (...)
        {
            *coordinator = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IVoipPhoneCall> : produce_base<D, Windows::ApplicationModel::Calls::IVoipPhoneCall>
{
    HRESULT __stdcall add_EndRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().EndRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_EndRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EndRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_HoldRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().HoldRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_HoldRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HoldRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ResumeRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ResumeRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ResumeRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResumeRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AnswerRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs>> acceptHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AnswerRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> *>(&acceptHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AnswerRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AnswerRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RejectRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs>> rejectHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RejectRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> *>(&rejectHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RejectRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RejectRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyCallHeld() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyCallHeld();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyCallActive() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyCallActive();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyCallEnded() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyCallEnded();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContactName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContactName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContactName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContactName(*reinterpret_cast<const hstring *>(&value));
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

    HRESULT __stdcall get_CallMedia(Windows::ApplicationModel::Calls::VoipPhoneCallMedia * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CallMedia());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CallMedia(Windows::ApplicationModel::Calls::VoipPhoneCallMedia value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CallMedia(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyCallReady() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyCallReady();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Calls {

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCallState impl_ICallStateChangeEventArgs<D>::State() const
{
    Windows::ApplicationModel::Calls::VoipPhoneCallState value {};
    check_hresult(WINRT_SHIM(ICallStateChangeEventArgs)->get_State(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCallMedia impl_ICallAnswerEventArgs<D>::AcceptedMedia() const
{
    Windows::ApplicationModel::Calls::VoipPhoneCallMedia value {};
    check_hresult(WINRT_SHIM(ICallAnswerEventArgs)->get_AcceptedMedia(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCallRejectReason impl_ICallRejectEventArgs<D>::RejectReason() const
{
    Windows::ApplicationModel::Calls::VoipPhoneCallRejectReason value {};
    check_hresult(WINRT_SHIM(ICallRejectEventArgs)->get_RejectReason(&value));
    return value;
}

template <typename D> event_token impl_IVoipPhoneCall<D>::EndRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->add_EndRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IVoipPhoneCall> impl_IVoipPhoneCall<D>::EndRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IVoipPhoneCall>(this, &ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall::remove_EndRequested, EndRequested(handler));
}

template <typename D> void impl_IVoipPhoneCall<D>::EndRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->remove_EndRequested(token));
}

template <typename D> event_token impl_IVoipPhoneCall<D>::HoldRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->add_HoldRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IVoipPhoneCall> impl_IVoipPhoneCall<D>::HoldRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IVoipPhoneCall>(this, &ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall::remove_HoldRequested, HoldRequested(handler));
}

template <typename D> void impl_IVoipPhoneCall<D>::HoldRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->remove_HoldRequested(token));
}

template <typename D> event_token impl_IVoipPhoneCall<D>::ResumeRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->add_ResumeRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IVoipPhoneCall> impl_IVoipPhoneCall<D>::ResumeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IVoipPhoneCall>(this, &ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall::remove_ResumeRequested, ResumeRequested(handler));
}

template <typename D> void impl_IVoipPhoneCall<D>::ResumeRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->remove_ResumeRequested(token));
}

template <typename D> event_token impl_IVoipPhoneCall<D>::AnswerRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> & acceptHandler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->add_AnswerRequested(get_abi(acceptHandler), &token));
    return token;
}

template <typename D> event_revoker<IVoipPhoneCall> impl_IVoipPhoneCall<D>::AnswerRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> & acceptHandler) const
{
    return impl::make_event_revoker<D, IVoipPhoneCall>(this, &ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall::remove_AnswerRequested, AnswerRequested(acceptHandler));
}

template <typename D> void impl_IVoipPhoneCall<D>::AnswerRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->remove_AnswerRequested(token));
}

template <typename D> event_token impl_IVoipPhoneCall<D>::RejectRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> & rejectHandler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->add_RejectRequested(get_abi(rejectHandler), &token));
    return token;
}

template <typename D> event_revoker<IVoipPhoneCall> impl_IVoipPhoneCall<D>::RejectRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> & rejectHandler) const
{
    return impl::make_event_revoker<D, IVoipPhoneCall>(this, &ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall::remove_RejectRequested, RejectRequested(rejectHandler));
}

template <typename D> void impl_IVoipPhoneCall<D>::RejectRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->remove_RejectRequested(token));
}

template <typename D> void impl_IVoipPhoneCall<D>::NotifyCallHeld() const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->abi_NotifyCallHeld());
}

template <typename D> void impl_IVoipPhoneCall<D>::NotifyCallActive() const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->abi_NotifyCallActive());
}

template <typename D> void impl_IVoipPhoneCall<D>::NotifyCallEnded() const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->abi_NotifyCallEnded());
}

template <typename D> hstring impl_IVoipPhoneCall<D>::ContactName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->get_ContactName(put_abi(value)));
    return value;
}

template <typename D> void impl_IVoipPhoneCall<D>::ContactName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->put_ContactName(get_abi(value)));
}

template <typename D> Windows::Foundation::DateTime impl_IVoipPhoneCall<D>::StartTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->get_StartTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IVoipPhoneCall<D>::StartTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->put_StartTime(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCallMedia impl_IVoipPhoneCall<D>::CallMedia() const
{
    Windows::ApplicationModel::Calls::VoipPhoneCallMedia value {};
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->get_CallMedia(&value));
    return value;
}

template <typename D> void impl_IVoipPhoneCall<D>::CallMedia(Windows::ApplicationModel::Calls::VoipPhoneCallMedia value) const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->put_CallMedia(value));
}

template <typename D> void impl_IVoipPhoneCall<D>::NotifyCallReady() const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->abi_NotifyCallReady());
}

template <typename D> bool impl_IMuteChangeEventArgs<D>::Muted() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMuteChangeEventArgs)->get_Muted(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus> impl_IVoipCallCoordinator<D>::ReserveCallResourcesAsync(hstring_view taskEntryPoint) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus> operation;
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_ReserveCallResourcesAsync(get_abi(taskEntryPoint), put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_IVoipCallCoordinator<D>::MuteStateChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> & muteChangeHandler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->add_MuteStateChanged(get_abi(muteChangeHandler), &token));
    return token;
}

template <typename D> event_revoker<IVoipCallCoordinator> impl_IVoipCallCoordinator<D>::MuteStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> & muteChangeHandler) const
{
    return impl::make_event_revoker<D, IVoipCallCoordinator>(this, &ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator::remove_MuteStateChanged, MuteStateChanged(muteChangeHandler));
}

template <typename D> void impl_IVoipCallCoordinator<D>::MuteStateChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->remove_MuteStateChanged(token));
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCall impl_IVoipCallCoordinator<D>::RequestNewIncomingCall(hstring_view context, hstring_view contactName, hstring_view contactNumber, const Windows::Foundation::Uri & contactImage, hstring_view serviceName, const Windows::Foundation::Uri & brandingImage, hstring_view callDetails, const Windows::Foundation::Uri & ringtone, Windows::ApplicationModel::Calls::VoipPhoneCallMedia media, const Windows::Foundation::TimeSpan & ringTimeout) const
{
    Windows::ApplicationModel::Calls::VoipPhoneCall call { nullptr };
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_RequestNewIncomingCall(get_abi(context), get_abi(contactName), get_abi(contactNumber), get_abi(contactImage), get_abi(serviceName), get_abi(brandingImage), get_abi(callDetails), get_abi(ringtone), media, get_abi(ringTimeout), put_abi(call)));
    return call;
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCall impl_IVoipCallCoordinator<D>::RequestNewOutgoingCall(hstring_view context, hstring_view contactName, hstring_view serviceName, Windows::ApplicationModel::Calls::VoipPhoneCallMedia media) const
{
    Windows::ApplicationModel::Calls::VoipPhoneCall call { nullptr };
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_RequestNewOutgoingCall(get_abi(context), get_abi(contactName), get_abi(serviceName), media, put_abi(call)));
    return call;
}

template <typename D> void impl_IVoipCallCoordinator<D>::NotifyMuted() const
{
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_NotifyMuted());
}

template <typename D> void impl_IVoipCallCoordinator<D>::NotifyUnmuted() const
{
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_NotifyUnmuted());
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCall impl_IVoipCallCoordinator<D>::RequestOutgoingUpgradeToVideoCall(GUID callUpgradeGuid, hstring_view context, hstring_view contactName, hstring_view serviceName) const
{
    Windows::ApplicationModel::Calls::VoipPhoneCall call { nullptr };
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_RequestOutgoingUpgradeToVideoCall(callUpgradeGuid, get_abi(context), get_abi(contactName), get_abi(serviceName), put_abi(call)));
    return call;
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCall impl_IVoipCallCoordinator<D>::RequestIncomingUpgradeToVideoCall(hstring_view context, hstring_view contactName, hstring_view contactNumber, const Windows::Foundation::Uri & contactImage, hstring_view serviceName, const Windows::Foundation::Uri & brandingImage, hstring_view callDetails, const Windows::Foundation::Uri & ringtone, const Windows::Foundation::TimeSpan & ringTimeout) const
{
    Windows::ApplicationModel::Calls::VoipPhoneCall call { nullptr };
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_RequestIncomingUpgradeToVideoCall(get_abi(context), get_abi(contactName), get_abi(contactNumber), get_abi(contactImage), get_abi(serviceName), get_abi(brandingImage), get_abi(callDetails), get_abi(ringtone), get_abi(ringTimeout), put_abi(call)));
    return call;
}

template <typename D> void impl_IVoipCallCoordinator<D>::TerminateCellularCall(GUID callUpgradeGuid) const
{
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_TerminateCellularCall(callUpgradeGuid));
}

template <typename D> void impl_IVoipCallCoordinator<D>::CancelUpgrade(GUID callUpgradeGuid) const
{
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_CancelUpgrade(callUpgradeGuid));
}

template <typename D> Windows::ApplicationModel::Calls::VoipCallCoordinator impl_IVoipCallCoordinatorStatics<D>::GetDefault() const
{
    Windows::ApplicationModel::Calls::VoipCallCoordinator coordinator { nullptr };
    check_hresult(WINRT_SHIM(IVoipCallCoordinatorStatics)->abi_GetDefault(put_abi(coordinator)));
    return coordinator;
}

template <typename D> hstring impl_IPhoneCallHistoryEntry<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress impl_IPhoneCallHistoryEntry<D>::Address() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress value { nullptr };
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_Address(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::Address(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress & value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_Address(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IPhoneCallHistoryEntry<D>::Duration() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::Duration(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_Duration(get_abi(value)));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsCallerIdBlocked() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_IsCallerIdBlocked(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsCallerIdBlocked(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_IsCallerIdBlocked(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsEmergency() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_IsEmergency(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsEmergency(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_IsEmergency(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsIncoming() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_IsIncoming(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsIncoming(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_IsIncoming(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsMissed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_IsMissed(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsMissed(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_IsMissed(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsRinging() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_IsRinging(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsRinging(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_IsRinging(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsSeen() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_IsSeen(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsSeen(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_IsSeen(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsSuppressed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_IsSuppressed(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsSuppressed(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_IsSuppressed(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsVoicemail() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_IsVoicemail(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsVoicemail(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_IsVoicemail(value));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia impl_IPhoneCallHistoryEntry<D>::Media() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_Media(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::Media(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_Media(value));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess impl_IPhoneCallHistoryEntry<D>::OtherAppReadAccess() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_OtherAppReadAccess(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::OtherAppReadAccess(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_OtherAppReadAccess(value));
}

template <typename D> hstring impl_IPhoneCallHistoryEntry<D>::RemoteId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_RemoteId(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::RemoteId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_RemoteId(get_abi(value)));
}

template <typename D> hstring impl_IPhoneCallHistoryEntry<D>::SourceDisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_SourceDisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPhoneCallHistoryEntry<D>::SourceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_SourceId(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::SourceId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_SourceId(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind impl_IPhoneCallHistoryEntry<D>::SourceIdKind() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_SourceIdKind(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::SourceIdKind(Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_SourceIdKind(value));
}

template <typename D> Windows::Foundation::DateTime impl_IPhoneCallHistoryEntry<D>::StartTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_StartTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::StartTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_StartTime(get_abi(value)));
}

template <typename D> hstring impl_IPhoneCallHistoryEntryAddress<D>::ContactId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddress)->get_ContactId(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntryAddress<D>::ContactId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddress)->put_ContactId(get_abi(value)));
}

template <typename D> hstring impl_IPhoneCallHistoryEntryAddress<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddress)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntryAddress<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddress)->put_DisplayName(get_abi(value)));
}

template <typename D> hstring impl_IPhoneCallHistoryEntryAddress<D>::RawAddress() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddress)->get_RawAddress(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntryAddress<D>::RawAddress(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddress)->put_RawAddress(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind impl_IPhoneCallHistoryEntryAddress<D>::RawAddressKind() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddress)->get_RawAddressKind(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntryAddress<D>::RawAddressKind(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddress)->put_RawAddressKind(value));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress impl_IPhoneCallHistoryEntryAddressFactory<D>::Create(hstring_view rawAddress, Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind rawAddressKind) const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress result { nullptr };
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddressFactory)->abi_Create(get_abi(rawAddress), rawAddressKind, put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia impl_IPhoneCallHistoryEntryQueryOptions<D>::DesiredMedia() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryQueryOptions)->get_DesiredMedia(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntryQueryOptions<D>::DesiredMedia(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryQueryOptions)->put_DesiredMedia(value));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IPhoneCallHistoryEntryQueryOptions<D>::SourceIds() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryQueryOptions)->get_SourceIds(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> impl_IPhoneCallHistoryEntryReader<D>::ReadBatchAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryReader)->abi_ReadBatchAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> impl_IPhoneCallHistoryStore<D>::GetEntryAsync(hstring_view callHistoryEntryId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_GetEntryAsync(get_abi(callHistoryEntryId), put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader impl_IPhoneCallHistoryStore<D>::GetEntryReader() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader result { nullptr };
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_GetEntryReader(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader impl_IPhoneCallHistoryStore<D>::GetEntryReader(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions & queryOptions) const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader result { nullptr };
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_GetEntryReaderWithOptions(get_abi(queryOptions), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::SaveEntryAsync(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry & callHistoryEntry) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_SaveEntryAsync(get_abi(callHistoryEntry), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::DeleteEntryAsync(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry & callHistoryEntry) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_DeleteEntryAsync(get_abi(callHistoryEntry), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::DeleteEntriesAsync(iterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> callHistoryEntries) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_DeleteEntriesAsync(get_abi(callHistoryEntries), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::MarkEntryAsSeenAsync(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry & callHistoryEntry) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_MarkEntryAsSeenAsync(get_abi(callHistoryEntry), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::MarkEntriesAsSeenAsync(iterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> callHistoryEntries) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_MarkEntriesAsSeenAsync(get_abi(callHistoryEntries), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<uint32_t> impl_IPhoneCallHistoryStore<D>::GetUnseenCountAsync() const
{
    Windows::Foundation::IAsyncOperation<uint32_t> result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_GetUnseenCountAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::MarkAllAsSeenAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_MarkAllAsSeenAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<uint32_t> impl_IPhoneCallHistoryStore<D>::GetSourcesUnseenCountAsync(iterable<hstring> sourceIds) const
{
    Windows::Foundation::IAsyncOperation<uint32_t> result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_GetSourcesUnseenCountAsync(get_abi(sourceIds), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::MarkSourcesAsSeenAsync(iterable<hstring> sourceIds) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_MarkSourcesAsSeenAsync(get_abi(sourceIds), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> impl_IPhoneCallHistoryManagerStatics<D>::RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryManagerStatics)->abi_RequestStoreAsync(accessType, put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser impl_IPhoneCallHistoryManagerStatics2<D>::GetForUser(const Windows::System::User & user) const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser result { nullptr };
    check_hresult(WINRT_SHIM(IPhoneCallHistoryManagerStatics2)->abi_GetForUser(get_abi(user), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> impl_IPhoneCallHistoryManagerForUser<D>::RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryManagerForUser)->abi_RequestStoreAsync(accessType, put_abi(result)));
    return result;
}

template <typename D> Windows::System::User impl_IPhoneCallHistoryManagerForUser<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IPhoneCallHistoryManagerForUser)->get_User(put_abi(value)));
    return value;
}

template <typename D> void impl_ILockScreenCallEndCallDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(ILockScreenCallEndCallDeferral)->abi_Complete());
}

template <typename D> Windows::ApplicationModel::Calls::LockScreenCallEndCallDeferral impl_ILockScreenCallEndRequestedEventArgs<D>::GetDeferral() const
{
    Windows::ApplicationModel::Calls::LockScreenCallEndCallDeferral value { nullptr };
    check_hresult(WINRT_SHIM(ILockScreenCallEndRequestedEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ILockScreenCallEndRequestedEventArgs<D>::Deadline() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ILockScreenCallEndRequestedEventArgs)->get_Deadline(put_abi(value)));
    return value;
}

template <typename D> void impl_ILockScreenCallUI<D>::Dismiss() const
{
    check_hresult(WINRT_SHIM(ILockScreenCallUI)->abi_Dismiss());
}

template <typename D> event_token impl_ILockScreenCallUI<D>::EndRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::LockScreenCallUI, Windows::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ILockScreenCallUI)->add_EndRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ILockScreenCallUI> impl_ILockScreenCallUI<D>::EndRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::LockScreenCallUI, Windows::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ILockScreenCallUI>(this, &ABI::Windows::ApplicationModel::Calls::ILockScreenCallUI::remove_EndRequested, EndRequested(handler));
}

template <typename D> void impl_ILockScreenCallUI<D>::EndRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(ILockScreenCallUI)->remove_EndRequested(token));
}

template <typename D> event_token impl_ILockScreenCallUI<D>::Closed(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::LockScreenCallUI, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ILockScreenCallUI)->add_Closed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ILockScreenCallUI> impl_ILockScreenCallUI<D>::Closed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::LockScreenCallUI, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, ILockScreenCallUI>(this, &ABI::Windows::ApplicationModel::Calls::ILockScreenCallUI::remove_Closed, Closed(handler));
}

template <typename D> void impl_ILockScreenCallUI<D>::Closed(event_token token) const
{
    check_hresult(WINRT_SHIM(ILockScreenCallUI)->remove_Closed(token));
}

template <typename D> hstring impl_ILockScreenCallUI<D>::CallTitle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILockScreenCallUI)->get_CallTitle(put_abi(value)));
    return value;
}

template <typename D> void impl_ILockScreenCallUI<D>::CallTitle(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ILockScreenCallUI)->put_CallTitle(get_abi(value)));
}

template <typename D> hstring impl_IPhoneVoicemail<D>::Number() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneVoicemail)->get_Number(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IPhoneVoicemail<D>::MessageCount() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IPhoneVoicemail)->get_MessageCount(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneVoicemailType impl_IPhoneVoicemail<D>::Type() const
{
    Windows::ApplicationModel::Calls::PhoneVoicemailType value {};
    check_hresult(WINRT_SHIM(IPhoneVoicemail)->get_Type(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneVoicemail<D>::DialVoicemailAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPhoneVoicemail)->abi_DialVoicemailAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IPhoneDialOptions<D>::Number() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneDialOptions)->get_Number(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneDialOptions<D>::Number(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPhoneDialOptions)->put_Number(get_abi(value)));
}

template <typename D> hstring impl_IPhoneDialOptions<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneDialOptions)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneDialOptions<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPhoneDialOptions)->put_DisplayName(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Contacts::Contact impl_IPhoneDialOptions<D>::Contact() const
{
    Windows::ApplicationModel::Contacts::Contact value { nullptr };
    check_hresult(WINRT_SHIM(IPhoneDialOptions)->get_Contact(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneDialOptions<D>::Contact(const Windows::ApplicationModel::Contacts::Contact & value) const
{
    check_hresult(WINRT_SHIM(IPhoneDialOptions)->put_Contact(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Contacts::ContactPhone impl_IPhoneDialOptions<D>::ContactPhone() const
{
    Windows::ApplicationModel::Contacts::ContactPhone value { nullptr };
    check_hresult(WINRT_SHIM(IPhoneDialOptions)->get_ContactPhone(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneDialOptions<D>::ContactPhone(const Windows::ApplicationModel::Contacts::ContactPhone & value) const
{
    check_hresult(WINRT_SHIM(IPhoneDialOptions)->put_ContactPhone(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallMedia impl_IPhoneDialOptions<D>::Media() const
{
    Windows::ApplicationModel::Calls::PhoneCallMedia value {};
    check_hresult(WINRT_SHIM(IPhoneDialOptions)->get_Media(&value));
    return value;
}

template <typename D> void impl_IPhoneDialOptions<D>::Media(Windows::ApplicationModel::Calls::PhoneCallMedia value) const
{
    check_hresult(WINRT_SHIM(IPhoneDialOptions)->put_Media(value));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneAudioRoutingEndpoint impl_IPhoneDialOptions<D>::AudioEndpoint() const
{
    Windows::ApplicationModel::Calls::PhoneAudioRoutingEndpoint value {};
    check_hresult(WINRT_SHIM(IPhoneDialOptions)->get_AudioEndpoint(&value));
    return value;
}

template <typename D> void impl_IPhoneDialOptions<D>::AudioEndpoint(Windows::ApplicationModel::Calls::PhoneAudioRoutingEndpoint value) const
{
    check_hresult(WINRT_SHIM(IPhoneDialOptions)->put_AudioEndpoint(value));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneSimState impl_IPhoneLineCellularDetails<D>::SimState() const
{
    Windows::ApplicationModel::Calls::PhoneSimState value {};
    check_hresult(WINRT_SHIM(IPhoneLineCellularDetails)->get_SimState(&value));
    return value;
}

template <typename D> int32_t impl_IPhoneLineCellularDetails<D>::SimSlotIndex() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IPhoneLineCellularDetails)->get_SimSlotIndex(&value));
    return value;
}

template <typename D> bool impl_IPhoneLineCellularDetails<D>::IsModemOn() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneLineCellularDetails)->get_IsModemOn(&value));
    return value;
}

template <typename D> int32_t impl_IPhoneLineCellularDetails<D>::RegistrationRejectCode() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IPhoneLineCellularDetails)->get_RegistrationRejectCode(&value));
    return value;
}

template <typename D> hstring impl_IPhoneLineCellularDetails<D>::GetNetworkOperatorDisplayText(Windows::ApplicationModel::Calls::PhoneLineNetworkOperatorDisplayTextLocation location) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneLineCellularDetails)->abi_GetNetworkOperatorDisplayText(location, put_abi(value)));
    return value;
}

template <typename D> event_token impl_IPhoneLine<D>::LineChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLine, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPhoneLine)->add_LineChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPhoneLine> impl_IPhoneLine<D>::LineChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLine, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPhoneLine>(this, &ABI::Windows::ApplicationModel::Calls::IPhoneLine::remove_LineChanged, LineChanged(handler));
}

template <typename D> void impl_IPhoneLine<D>::LineChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPhoneLine)->remove_LineChanged(token));
}

template <typename D> GUID impl_IPhoneLine<D>::Id() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IPhoneLine)->get_Id(&value));
    return value;
}

template <typename D> Windows::UI::Color impl_IPhoneLine<D>::DisplayColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IPhoneLine)->get_DisplayColor(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneNetworkState impl_IPhoneLine<D>::NetworkState() const
{
    Windows::ApplicationModel::Calls::PhoneNetworkState value {};
    check_hresult(WINRT_SHIM(IPhoneLine)->get_NetworkState(&value));
    return value;
}

template <typename D> hstring impl_IPhoneLine<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneLine)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneVoicemail impl_IPhoneLine<D>::Voicemail() const
{
    Windows::ApplicationModel::Calls::PhoneVoicemail value { nullptr };
    check_hresult(WINRT_SHIM(IPhoneLine)->get_Voicemail(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPhoneLine<D>::NetworkName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneLine)->get_NetworkName(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneLineCellularDetails impl_IPhoneLine<D>::CellularDetails() const
{
    Windows::ApplicationModel::Calls::PhoneLineCellularDetails value { nullptr };
    check_hresult(WINRT_SHIM(IPhoneLine)->get_CellularDetails(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneLineTransport impl_IPhoneLine<D>::Transport() const
{
    Windows::ApplicationModel::Calls::PhoneLineTransport value {};
    check_hresult(WINRT_SHIM(IPhoneLine)->get_Transport(&value));
    return value;
}

template <typename D> bool impl_IPhoneLine<D>::CanDial() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneLine)->get_CanDial(&value));
    return value;
}

template <typename D> bool impl_IPhoneLine<D>::SupportsTile() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneLine)->get_SupportsTile(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallVideoCapabilities impl_IPhoneLine<D>::VideoCallingCapabilities() const
{
    Windows::ApplicationModel::Calls::PhoneCallVideoCapabilities value { nullptr };
    check_hresult(WINRT_SHIM(IPhoneLine)->get_VideoCallingCapabilities(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneLineConfiguration impl_IPhoneLine<D>::LineConfiguration() const
{
    Windows::ApplicationModel::Calls::PhoneLineConfiguration value { nullptr };
    check_hresult(WINRT_SHIM(IPhoneLine)->get_LineConfiguration(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IPhoneLine<D>::IsImmediateDialNumberAsync(hstring_view number) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IPhoneLine)->abi_IsImmediateDialNumberAsync(get_abi(number), put_abi(result)));
    return result;
}

template <typename D> void impl_IPhoneLine<D>::Dial(hstring_view number, hstring_view displayName) const
{
    check_hresult(WINRT_SHIM(IPhoneLine)->abi_Dial(get_abi(number), get_abi(displayName)));
}

template <typename D> void impl_IPhoneLine<D>::DialWithOptions(const Windows::ApplicationModel::Calls::PhoneDialOptions & options) const
{
    check_hresult(WINRT_SHIM(IPhoneLine)->abi_DialWithOptions(get_abi(options)));
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IPhoneCallStore<D>::IsEmergencyPhoneNumberAsync(hstring_view number) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IPhoneCallStore)->abi_IsEmergencyPhoneNumberAsync(get_abi(number), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<GUID> impl_IPhoneCallStore<D>::GetDefaultLineAsync() const
{
    Windows::Foundation::IAsyncOperation<GUID> result;
    check_hresult(WINRT_SHIM(IPhoneCallStore)->abi_GetDefaultLineAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneLineWatcher impl_IPhoneCallStore<D>::RequestLineWatcher() const
{
    Windows::ApplicationModel::Calls::PhoneLineWatcher result { nullptr };
    check_hresult(WINRT_SHIM(IPhoneCallStore)->abi_RequestLineWatcher(put_abi(result)));
    return result;
}

template <typename D> bool impl_IPhoneLineConfiguration<D>::IsVideoCallingEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneLineConfiguration)->get_IsVideoCallingEnabled(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_IPhoneLineConfiguration<D>::ExtendedProperties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IPhoneLineConfiguration)->get_ExtendedProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneLine> impl_IPhoneLineStatics<D>::FromIdAsync(GUID lineId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneLine> result;
    check_hresult(WINRT_SHIM(IPhoneLineStatics)->abi_FromIdAsync(lineId, put_abi(result)));
    return result;
}

template <typename D> void impl_IPhoneLineWatcher<D>::Start() const
{
    check_hresult(WINRT_SHIM(IPhoneLineWatcher)->abi_Start());
}

template <typename D> void impl_IPhoneLineWatcher<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IPhoneLineWatcher)->abi_Stop());
}

template <typename D> event_token impl_IPhoneLineWatcher<D>::LineAdded(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPhoneLineWatcher)->add_LineAdded(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPhoneLineWatcher> impl_IPhoneLineWatcher<D>::LineAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPhoneLineWatcher>(this, &ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher::remove_LineAdded, LineAdded(handler));
}

template <typename D> void impl_IPhoneLineWatcher<D>::LineAdded(event_token token) const
{
    check_hresult(WINRT_SHIM(IPhoneLineWatcher)->remove_LineAdded(token));
}

template <typename D> event_token impl_IPhoneLineWatcher<D>::LineRemoved(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPhoneLineWatcher)->add_LineRemoved(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPhoneLineWatcher> impl_IPhoneLineWatcher<D>::LineRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPhoneLineWatcher>(this, &ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher::remove_LineRemoved, LineRemoved(handler));
}

template <typename D> void impl_IPhoneLineWatcher<D>::LineRemoved(event_token token) const
{
    check_hresult(WINRT_SHIM(IPhoneLineWatcher)->remove_LineRemoved(token));
}

template <typename D> event_token impl_IPhoneLineWatcher<D>::LineUpdated(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPhoneLineWatcher)->add_LineUpdated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPhoneLineWatcher> impl_IPhoneLineWatcher<D>::LineUpdated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPhoneLineWatcher>(this, &ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher::remove_LineUpdated, LineUpdated(handler));
}

template <typename D> void impl_IPhoneLineWatcher<D>::LineUpdated(event_token token) const
{
    check_hresult(WINRT_SHIM(IPhoneLineWatcher)->remove_LineUpdated(token));
}

template <typename D> event_token impl_IPhoneLineWatcher<D>::EnumerationCompleted(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPhoneLineWatcher)->add_EnumerationCompleted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPhoneLineWatcher> impl_IPhoneLineWatcher<D>::EnumerationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPhoneLineWatcher>(this, &ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher::remove_EnumerationCompleted, EnumerationCompleted(handler));
}

template <typename D> void impl_IPhoneLineWatcher<D>::EnumerationCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IPhoneLineWatcher)->remove_EnumerationCompleted(token));
}

template <typename D> event_token impl_IPhoneLineWatcher<D>::Stopped(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPhoneLineWatcher)->add_Stopped(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPhoneLineWatcher> impl_IPhoneLineWatcher<D>::Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPhoneLineWatcher>(this, &ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher::remove_Stopped, Stopped(handler));
}

template <typename D> void impl_IPhoneLineWatcher<D>::Stopped(event_token token) const
{
    check_hresult(WINRT_SHIM(IPhoneLineWatcher)->remove_Stopped(token));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneLineWatcherStatus impl_IPhoneLineWatcher<D>::Status() const
{
    Windows::ApplicationModel::Calls::PhoneLineWatcherStatus status {};
    check_hresult(WINRT_SHIM(IPhoneLineWatcher)->get_Status(&status));
    return status;
}

template <typename D> GUID impl_IPhoneLineWatcherEventArgs<D>::LineId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IPhoneLineWatcherEventArgs)->get_LineId(&value));
    return value;
}

template <typename D> void impl_IPhoneCallManagerStatics<D>::ShowPhoneCallUI(hstring_view phoneNumber, hstring_view displayName) const
{
    check_hresult(WINRT_SHIM(IPhoneCallManagerStatics)->abi_ShowPhoneCallUI(get_abi(phoneNumber), get_abi(displayName)));
}

template <typename D> event_token impl_IPhoneCallManagerStatics2<D>::CallStateChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPhoneCallManagerStatics2)->add_CallStateChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPhoneCallManagerStatics2> impl_IPhoneCallManagerStatics2<D>::CallStateChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPhoneCallManagerStatics2>(this, &ABI::Windows::ApplicationModel::Calls::IPhoneCallManagerStatics2::remove_CallStateChanged, CallStateChanged(handler));
}

template <typename D> void impl_IPhoneCallManagerStatics2<D>::CallStateChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPhoneCallManagerStatics2)->remove_CallStateChanged(token));
}

template <typename D> bool impl_IPhoneCallManagerStatics2<D>::IsCallActive() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallManagerStatics2)->get_IsCallActive(&value));
    return value;
}

template <typename D> bool impl_IPhoneCallManagerStatics2<D>::IsCallIncoming() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallManagerStatics2)->get_IsCallIncoming(&value));
    return value;
}

template <typename D> void impl_IPhoneCallManagerStatics2<D>::ShowPhoneCallSettingsUI() const
{
    check_hresult(WINRT_SHIM(IPhoneCallManagerStatics2)->abi_ShowPhoneCallSettingsUI());
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallStore> impl_IPhoneCallManagerStatics2<D>::RequestStoreAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallStore> result;
    check_hresult(WINRT_SHIM(IPhoneCallManagerStatics2)->abi_RequestStoreAsync(put_abi(result)));
    return result;
}

template <typename D> bool impl_IPhoneCallVideoCapabilities<D>::IsVideoCallingCapable() const
{
    bool pValue {};
    check_hresult(WINRT_SHIM(IPhoneCallVideoCapabilities)->get_IsVideoCallingCapable(&pValue));
    return pValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallVideoCapabilities> impl_IPhoneCallVideoCapabilitiesManagerStatics<D>::GetCapabilitiesAsync(hstring_view phoneNumber) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallVideoCapabilities> result;
    check_hresult(WINRT_SHIM(IPhoneCallVideoCapabilitiesManagerStatics)->abi_GetCapabilitiesAsync(get_abi(phoneNumber), put_abi(result)));
    return result;
}

template <typename D> bool impl_IPhoneCallBlockingStatics<D>::BlockUnknownNumbers() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallBlockingStatics)->get_BlockUnknownNumbers(&value));
    return value;
}

template <typename D> void impl_IPhoneCallBlockingStatics<D>::BlockUnknownNumbers(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallBlockingStatics)->put_BlockUnknownNumbers(value));
}

template <typename D> bool impl_IPhoneCallBlockingStatics<D>::BlockPrivateNumbers() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallBlockingStatics)->get_BlockPrivateNumbers(&value));
    return value;
}

template <typename D> void impl_IPhoneCallBlockingStatics<D>::BlockPrivateNumbers(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallBlockingStatics)->put_BlockPrivateNumbers(value));
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IPhoneCallBlockingStatics<D>::SetCallBlockingListAsync(iterable<hstring> phoneNumberList) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IPhoneCallBlockingStatics)->abi_SetCallBlockingListAsync(get_abi(phoneNumberList), put_abi(result)));
    return result;
}

inline bool PhoneCallBlocking::BlockUnknownNumbers()
{
    return get_activation_factory<PhoneCallBlocking, IPhoneCallBlockingStatics>().BlockUnknownNumbers();
}

inline void PhoneCallBlocking::BlockUnknownNumbers(bool value)
{
    get_activation_factory<PhoneCallBlocking, IPhoneCallBlockingStatics>().BlockUnknownNumbers(value);
}

inline bool PhoneCallBlocking::BlockPrivateNumbers()
{
    return get_activation_factory<PhoneCallBlocking, IPhoneCallBlockingStatics>().BlockPrivateNumbers();
}

inline void PhoneCallBlocking::BlockPrivateNumbers(bool value)
{
    get_activation_factory<PhoneCallBlocking, IPhoneCallBlockingStatics>().BlockPrivateNumbers(value);
}

inline Windows::Foundation::IAsyncOperation<bool> PhoneCallBlocking::SetCallBlockingListAsync(iterable<hstring> phoneNumberList)
{
    return get_activation_factory<PhoneCallBlocking, IPhoneCallBlockingStatics>().SetCallBlockingListAsync(phoneNumberList);
}

inline PhoneCallHistoryEntry::PhoneCallHistoryEntry() :
    PhoneCallHistoryEntry(activate_instance<PhoneCallHistoryEntry>())
{}

inline PhoneCallHistoryEntryAddress::PhoneCallHistoryEntryAddress() :
    PhoneCallHistoryEntryAddress(activate_instance<PhoneCallHistoryEntryAddress>())
{}

inline PhoneCallHistoryEntryAddress::PhoneCallHistoryEntryAddress(hstring_view rawAddress, Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind rawAddressKind) :
    PhoneCallHistoryEntryAddress(get_activation_factory<PhoneCallHistoryEntryAddress, IPhoneCallHistoryEntryAddressFactory>().Create(rawAddress, rawAddressKind))
{}

inline PhoneCallHistoryEntryQueryOptions::PhoneCallHistoryEntryQueryOptions() :
    PhoneCallHistoryEntryQueryOptions(activate_instance<PhoneCallHistoryEntryQueryOptions>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> PhoneCallHistoryManager::RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType)
{
    return get_activation_factory<PhoneCallHistoryManager, IPhoneCallHistoryManagerStatics>().RequestStoreAsync(accessType);
}

inline Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser PhoneCallHistoryManager::GetForUser(const Windows::System::User & user)
{
    return get_activation_factory<PhoneCallHistoryManager, IPhoneCallHistoryManagerStatics2>().GetForUser(user);
}

inline void PhoneCallManager::ShowPhoneCallUI(hstring_view phoneNumber, hstring_view displayName)
{
    get_activation_factory<PhoneCallManager, IPhoneCallManagerStatics>().ShowPhoneCallUI(phoneNumber, displayName);
}

inline event_token PhoneCallManager::CallStateChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<PhoneCallManager, IPhoneCallManagerStatics2>().CallStateChanged(handler);
}

inline factory_event_revoker<IPhoneCallManagerStatics2> PhoneCallManager::CallStateChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<PhoneCallManager, IPhoneCallManagerStatics2>();
    return { factory, &ABI::Windows::ApplicationModel::Calls::IPhoneCallManagerStatics2::remove_CallStateChanged, factory.CallStateChanged(handler) };
}

inline void PhoneCallManager::CallStateChanged(event_token token)
{
    get_activation_factory<PhoneCallManager, IPhoneCallManagerStatics2>().CallStateChanged(token);
}

inline bool PhoneCallManager::IsCallActive()
{
    return get_activation_factory<PhoneCallManager, IPhoneCallManagerStatics2>().IsCallActive();
}

inline bool PhoneCallManager::IsCallIncoming()
{
    return get_activation_factory<PhoneCallManager, IPhoneCallManagerStatics2>().IsCallIncoming();
}

inline void PhoneCallManager::ShowPhoneCallSettingsUI()
{
    get_activation_factory<PhoneCallManager, IPhoneCallManagerStatics2>().ShowPhoneCallSettingsUI();
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallStore> PhoneCallManager::RequestStoreAsync()
{
    return get_activation_factory<PhoneCallManager, IPhoneCallManagerStatics2>().RequestStoreAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallVideoCapabilities> PhoneCallVideoCapabilitiesManager::GetCapabilitiesAsync(hstring_view phoneNumber)
{
    return get_activation_factory<PhoneCallVideoCapabilitiesManager, IPhoneCallVideoCapabilitiesManagerStatics>().GetCapabilitiesAsync(phoneNumber);
}

inline PhoneDialOptions::PhoneDialOptions() :
    PhoneDialOptions(activate_instance<PhoneDialOptions>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneLine> PhoneLine::FromIdAsync(GUID lineId)
{
    return get_activation_factory<PhoneLine, IPhoneLineStatics>().FromIdAsync(lineId);
}

inline Windows::ApplicationModel::Calls::VoipCallCoordinator VoipCallCoordinator::GetDefault()
{
    return get_activation_factory<VoipCallCoordinator, IVoipCallCoordinatorStatics>().GetDefault();
}

}

}
#pragma warning(pop)
