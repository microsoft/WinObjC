// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Calls.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Calls {

struct WINRT_EBO CallAnswerEventArgs :
    Windows::ApplicationModel::Calls::ICallAnswerEventArgs
{
    CallAnswerEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CallRejectEventArgs :
    Windows::ApplicationModel::Calls::ICallRejectEventArgs
{
    CallRejectEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CallStateChangeEventArgs :
    Windows::ApplicationModel::Calls::ICallStateChangeEventArgs
{
    CallStateChangeEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LockScreenCallEndCallDeferral :
    Windows::ApplicationModel::Calls::ILockScreenCallEndCallDeferral
{
    LockScreenCallEndCallDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LockScreenCallEndRequestedEventArgs :
    Windows::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs
{
    LockScreenCallEndRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LockScreenCallUI :
    Windows::ApplicationModel::Calls::ILockScreenCallUI
{
    LockScreenCallUI(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MuteChangeEventArgs :
    Windows::ApplicationModel::Calls::IMuteChangeEventArgs
{
    MuteChangeEventArgs(std::nullptr_t) noexcept {}
};

struct PhoneCallBlocking
{
    PhoneCallBlocking() = delete;
    static bool BlockUnknownNumbers();
    static void BlockUnknownNumbers(bool value);
    static bool BlockPrivateNumbers();
    static void BlockPrivateNumbers(bool value);
    static Windows::Foundation::IAsyncOperation<bool> SetCallBlockingListAsync(iterable<hstring> phoneNumberList);
};

struct WINRT_EBO PhoneCallHistoryEntry :
    Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry
{
    PhoneCallHistoryEntry(std::nullptr_t) noexcept {}
    PhoneCallHistoryEntry();
};

struct WINRT_EBO PhoneCallHistoryEntryAddress :
    Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress
{
    PhoneCallHistoryEntryAddress(std::nullptr_t) noexcept {}
    PhoneCallHistoryEntryAddress();
    PhoneCallHistoryEntryAddress(hstring_view rawAddress, Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind rawAddressKind);
};

struct WINRT_EBO PhoneCallHistoryEntryQueryOptions :
    Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions
{
    PhoneCallHistoryEntryQueryOptions(std::nullptr_t) noexcept {}
    PhoneCallHistoryEntryQueryOptions();
};

struct WINRT_EBO PhoneCallHistoryEntryReader :
    Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader
{
    PhoneCallHistoryEntryReader(std::nullptr_t) noexcept {}
};

struct PhoneCallHistoryManager
{
    PhoneCallHistoryManager() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType);
    static Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser GetForUser(const Windows::System::User & user);
};

struct WINRT_EBO PhoneCallHistoryManagerForUser :
    Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser
{
    PhoneCallHistoryManagerForUser(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhoneCallHistoryStore :
    Windows::ApplicationModel::Calls::IPhoneCallHistoryStore
{
    PhoneCallHistoryStore(std::nullptr_t) noexcept {}
};

struct PhoneCallManager
{
    PhoneCallManager() = delete;
    static void ShowPhoneCallUI(hstring_view phoneNumber, hstring_view displayName);
    static event_token CallStateChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using CallStateChanged_revoker = factory_event_revoker<IPhoneCallManagerStatics2>;
    static CallStateChanged_revoker CallStateChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void CallStateChanged(event_token token);
    static bool IsCallActive();
    static bool IsCallIncoming();
    static void ShowPhoneCallSettingsUI();
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallStore> RequestStoreAsync();
};

struct WINRT_EBO PhoneCallStore :
    Windows::ApplicationModel::Calls::IPhoneCallStore
{
    PhoneCallStore(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhoneCallVideoCapabilities :
    Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilities
{
    PhoneCallVideoCapabilities(std::nullptr_t) noexcept {}
};

struct PhoneCallVideoCapabilitiesManager
{
    PhoneCallVideoCapabilitiesManager() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallVideoCapabilities> GetCapabilitiesAsync(hstring_view phoneNumber);
};

struct WINRT_EBO PhoneDialOptions :
    Windows::ApplicationModel::Calls::IPhoneDialOptions
{
    PhoneDialOptions(std::nullptr_t) noexcept {}
    PhoneDialOptions();
};

struct WINRT_EBO PhoneLine :
    Windows::ApplicationModel::Calls::IPhoneLine
{
    PhoneLine(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneLine> FromIdAsync(GUID lineId);
};

struct WINRT_EBO PhoneLineCellularDetails :
    Windows::ApplicationModel::Calls::IPhoneLineCellularDetails
{
    PhoneLineCellularDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhoneLineConfiguration :
    Windows::ApplicationModel::Calls::IPhoneLineConfiguration
{
    PhoneLineConfiguration(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhoneLineWatcher :
    Windows::ApplicationModel::Calls::IPhoneLineWatcher
{
    PhoneLineWatcher(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhoneLineWatcherEventArgs :
    Windows::ApplicationModel::Calls::IPhoneLineWatcherEventArgs
{
    PhoneLineWatcherEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhoneVoicemail :
    Windows::ApplicationModel::Calls::IPhoneVoicemail
{
    PhoneVoicemail(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VoipCallCoordinator :
    Windows::ApplicationModel::Calls::IVoipCallCoordinator
{
    VoipCallCoordinator(std::nullptr_t) noexcept {}
    static Windows::ApplicationModel::Calls::VoipCallCoordinator GetDefault();
};

struct WINRT_EBO VoipPhoneCall :
    Windows::ApplicationModel::Calls::IVoipPhoneCall
{
    VoipPhoneCall(std::nullptr_t) noexcept {}
};

}

}
