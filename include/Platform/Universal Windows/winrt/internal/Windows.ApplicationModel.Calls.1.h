// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Calls.0.h"
#include "Windows.ApplicationModel.Contacts.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.System.0.h"
#include "Windows.UI.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Calls {

struct __declspec(uuid("fd789617-2dd7-4c8c-b2bd-95d17a5bb733")) __declspec(novtable) ICallAnswerEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AcceptedMedia(winrt::Windows::ApplicationModel::Calls::VoipPhoneCallMedia * value) = 0;
};

struct __declspec(uuid("da47fad7-13d4-4d92-a1c2-b77811ee37ec")) __declspec(novtable) ICallRejectEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RejectReason(winrt::Windows::ApplicationModel::Calls::VoipPhoneCallRejectReason * value) = 0;
};

struct __declspec(uuid("eab2349e-66f5-47f9-9fb5-459c5198c720")) __declspec(novtable) ICallStateChangeEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_State(winrt::Windows::ApplicationModel::Calls::VoipPhoneCallState * value) = 0;
};

struct __declspec(uuid("2dd7ed0d-98ed-4041-9632-50ff812b773f")) __declspec(novtable) ILockScreenCallEndCallDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("8190a363-6f27-46e9-aeb6-c0ae83e47dc7")) __declspec(novtable) ILockScreenCallEndRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeferral(Windows::ApplicationModel::Calls::ILockScreenCallEndCallDeferral ** value) = 0;
    virtual HRESULT __stdcall get_Deadline(Windows::Foundation::DateTime * value) = 0;
};

struct __declspec(uuid("c596fd8d-73c9-4a14-b021-ec1c50a3b727")) __declspec(novtable) ILockScreenCallUI : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Dismiss() = 0;
    virtual HRESULT __stdcall add_EndRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::LockScreenCallUI, Windows::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_EndRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_Closed(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::LockScreenCallUI, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Closed(event_token token) = 0;
    virtual HRESULT __stdcall get_CallTitle(hstring * value) = 0;
    virtual HRESULT __stdcall put_CallTitle(hstring value) = 0;
};

struct __declspec(uuid("8585e159-0c41-432c-814d-c5f1fdf530be")) __declspec(novtable) IMuteChangeEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Muted(bool * value) = 0;
};

struct __declspec(uuid("19646f84-2b79-26f1-a46f-694be043f313")) __declspec(novtable) IPhoneCallBlockingStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BlockUnknownNumbers(bool * value) = 0;
    virtual HRESULT __stdcall put_BlockUnknownNumbers(bool value) = 0;
    virtual HRESULT __stdcall get_BlockPrivateNumbers(bool * value) = 0;
    virtual HRESULT __stdcall put_BlockPrivateNumbers(bool value) = 0;
    virtual HRESULT __stdcall abi_SetCallBlockingListAsync(Windows::Foundation::Collections::IIterable<hstring> * phoneNumberList, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
};

struct __declspec(uuid("fab0e129-32a4-4b85-83d1-f90d8c23a857")) __declspec(novtable) IPhoneCallHistoryEntry : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_Address(Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress ** value) = 0;
    virtual HRESULT __stdcall put_Address(Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress * value) = 0;
    virtual HRESULT __stdcall get_Duration(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall put_Duration(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> * value) = 0;
    virtual HRESULT __stdcall get_IsCallerIdBlocked(bool * value) = 0;
    virtual HRESULT __stdcall put_IsCallerIdBlocked(bool value) = 0;
    virtual HRESULT __stdcall get_IsEmergency(bool * value) = 0;
    virtual HRESULT __stdcall put_IsEmergency(bool value) = 0;
    virtual HRESULT __stdcall get_IsIncoming(bool * value) = 0;
    virtual HRESULT __stdcall put_IsIncoming(bool value) = 0;
    virtual HRESULT __stdcall get_IsMissed(bool * value) = 0;
    virtual HRESULT __stdcall put_IsMissed(bool value) = 0;
    virtual HRESULT __stdcall get_IsRinging(bool * value) = 0;
    virtual HRESULT __stdcall put_IsRinging(bool value) = 0;
    virtual HRESULT __stdcall get_IsSeen(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSeen(bool value) = 0;
    virtual HRESULT __stdcall get_IsSuppressed(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSuppressed(bool value) = 0;
    virtual HRESULT __stdcall get_IsVoicemail(bool * value) = 0;
    virtual HRESULT __stdcall put_IsVoicemail(bool value) = 0;
    virtual HRESULT __stdcall get_Media(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia * value) = 0;
    virtual HRESULT __stdcall put_Media(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia value) = 0;
    virtual HRESULT __stdcall get_OtherAppReadAccess(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess * value) = 0;
    virtual HRESULT __stdcall put_OtherAppReadAccess(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess value) = 0;
    virtual HRESULT __stdcall get_RemoteId(hstring * value) = 0;
    virtual HRESULT __stdcall put_RemoteId(hstring value) = 0;
    virtual HRESULT __stdcall get_SourceDisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_SourceId(hstring * value) = 0;
    virtual HRESULT __stdcall put_SourceId(hstring value) = 0;
    virtual HRESULT __stdcall get_SourceIdKind(winrt::Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind * value) = 0;
    virtual HRESULT __stdcall put_SourceIdKind(winrt::Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind value) = 0;
    virtual HRESULT __stdcall get_StartTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_StartTime(Windows::Foundation::DateTime value) = 0;
};

struct __declspec(uuid("30f159da-3955-4042-84e6-66eebf82e67f")) __declspec(novtable) IPhoneCallHistoryEntryAddress : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContactId(hstring * value) = 0;
    virtual HRESULT __stdcall put_ContactId(hstring value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_RawAddress(hstring * value) = 0;
    virtual HRESULT __stdcall put_RawAddress(hstring value) = 0;
    virtual HRESULT __stdcall get_RawAddressKind(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind * value) = 0;
    virtual HRESULT __stdcall put_RawAddressKind(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind value) = 0;
};

struct __declspec(uuid("fb0fadba-c7f0-4bb6-9f6b-ba5d73209aca")) __declspec(novtable) IPhoneCallHistoryEntryAddressFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring rawAddress, winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind rawAddressKind, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress ** result) = 0;
};

struct __declspec(uuid("9c5fe15c-8bed-40ca-b06e-c4ca8eae5c87")) __declspec(novtable) IPhoneCallHistoryEntryQueryOptions : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DesiredMedia(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia * value) = 0;
    virtual HRESULT __stdcall put_DesiredMedia(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia value) = 0;
    virtual HRESULT __stdcall get_SourceIds(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
};

struct __declspec(uuid("61ece4be-8d86-479f-8404-a9846920fee6")) __declspec(novtable) IPhoneCallHistoryEntryReader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ReadBatchAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> ** result) = 0;
};

struct __declspec(uuid("d925c523-f55f-4353-9db4-0205a5265a55")) __declspec(novtable) IPhoneCallHistoryManagerForUser : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestStoreAsync(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> ** result) = 0;
    virtual HRESULT __stdcall get_User(Windows::System::IUser ** value) = 0;
};

struct __declspec(uuid("f5a6da39-b31f-4f45-ac8e-1b08893c1b50")) __declspec(novtable) IPhoneCallHistoryManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestStoreAsync(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> ** result) = 0;
};

struct __declspec(uuid("efd474f0-a2db-4188-9e92-bc3cfa6813cf")) __declspec(novtable) IPhoneCallHistoryManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForUser(Windows::System::IUser * user, Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser ** result) = 0;
};

struct __declspec(uuid("2f907db8-b40e-422b-8545-cb1910a61c52")) __declspec(novtable) IPhoneCallHistoryStore : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetEntryAsync(hstring callHistoryEntryId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> ** result) = 0;
    virtual HRESULT __stdcall abi_GetEntryReader(Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader ** result) = 0;
    virtual HRESULT __stdcall abi_GetEntryReaderWithOptions(Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions * queryOptions, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader ** result) = 0;
    virtual HRESULT __stdcall abi_SaveEntryAsync(Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry * callHistoryEntry, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_DeleteEntryAsync(Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry * callHistoryEntry, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_DeleteEntriesAsync(Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> * callHistoryEntries, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_MarkEntryAsSeenAsync(Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry * callHistoryEntry, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_MarkEntriesAsSeenAsync(Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> * callHistoryEntries, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_GetUnseenCountAsync(Windows::Foundation::IAsyncOperation<uint32_t> ** result) = 0;
    virtual HRESULT __stdcall abi_MarkAllAsSeenAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_GetSourcesUnseenCountAsync(Windows::Foundation::Collections::IIterable<hstring> * sourceIds, Windows::Foundation::IAsyncOperation<uint32_t> ** result) = 0;
    virtual HRESULT __stdcall abi_MarkSourcesAsSeenAsync(Windows::Foundation::Collections::IIterable<hstring> * sourceIds, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("60edac78-78a6-4872-a3ef-98325ec8b843")) __declspec(novtable) IPhoneCallManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ShowPhoneCallUI(hstring phoneNumber, hstring displayName) = 0;
};

struct __declspec(uuid("c7e3c8bc-2370-431c-98fd-43be5f03086d")) __declspec(novtable) IPhoneCallManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_CallStateChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CallStateChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_IsCallActive(bool * value) = 0;
    virtual HRESULT __stdcall get_IsCallIncoming(bool * value) = 0;
    virtual HRESULT __stdcall abi_ShowPhoneCallSettingsUI() = 0;
    virtual HRESULT __stdcall abi_RequestStoreAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallStore> ** result) = 0;
};

struct __declspec(uuid("5f610748-18a6-4173-86d1-28be9dc62dba")) __declspec(novtable) IPhoneCallStore : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_IsEmergencyPhoneNumberAsync(hstring number, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_GetDefaultLineAsync(Windows::Foundation::IAsyncOperation<GUID> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestLineWatcher(Windows::ApplicationModel::Calls::IPhoneLineWatcher ** result) = 0;
};

struct __declspec(uuid("02382786-b16a-4fdb-be3b-c4240e13ad0d")) __declspec(novtable) IPhoneCallVideoCapabilities : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsVideoCallingCapable(bool * pValue) = 0;
};

struct __declspec(uuid("f3c64b56-f00b-4a1c-a0c6-ee1910749ce7")) __declspec(novtable) IPhoneCallVideoCapabilitiesManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCapabilitiesAsync(hstring phoneNumber, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallVideoCapabilities> ** result) = 0;
};

struct __declspec(uuid("b639c4b8-f06f-36cb-a863-823742b5f2d4")) __declspec(novtable) IPhoneDialOptions : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Number(hstring * value) = 0;
    virtual HRESULT __stdcall put_Number(hstring value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_Contact(Windows::ApplicationModel::Contacts::IContact ** value) = 0;
    virtual HRESULT __stdcall put_Contact(Windows::ApplicationModel::Contacts::IContact * value) = 0;
    virtual HRESULT __stdcall get_ContactPhone(Windows::ApplicationModel::Contacts::IContactPhone ** value) = 0;
    virtual HRESULT __stdcall put_ContactPhone(Windows::ApplicationModel::Contacts::IContactPhone * value) = 0;
    virtual HRESULT __stdcall get_Media(winrt::Windows::ApplicationModel::Calls::PhoneCallMedia * value) = 0;
    virtual HRESULT __stdcall put_Media(winrt::Windows::ApplicationModel::Calls::PhoneCallMedia value) = 0;
    virtual HRESULT __stdcall get_AudioEndpoint(winrt::Windows::ApplicationModel::Calls::PhoneAudioRoutingEndpoint * value) = 0;
    virtual HRESULT __stdcall put_AudioEndpoint(winrt::Windows::ApplicationModel::Calls::PhoneAudioRoutingEndpoint value) = 0;
};

struct __declspec(uuid("27c66f30-6a69-34ca-a2ba-65302530c311")) __declspec(novtable) IPhoneLine : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_LineChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLine, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_LineChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_Id(GUID * value) = 0;
    virtual HRESULT __stdcall get_DisplayColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_NetworkState(winrt::Windows::ApplicationModel::Calls::PhoneNetworkState * value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Voicemail(Windows::ApplicationModel::Calls::IPhoneVoicemail ** value) = 0;
    virtual HRESULT __stdcall get_NetworkName(hstring * value) = 0;
    virtual HRESULT __stdcall get_CellularDetails(Windows::ApplicationModel::Calls::IPhoneLineCellularDetails ** value) = 0;
    virtual HRESULT __stdcall get_Transport(winrt::Windows::ApplicationModel::Calls::PhoneLineTransport * value) = 0;
    virtual HRESULT __stdcall get_CanDial(bool * value) = 0;
    virtual HRESULT __stdcall get_SupportsTile(bool * value) = 0;
    virtual HRESULT __stdcall get_VideoCallingCapabilities(Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilities ** value) = 0;
    virtual HRESULT __stdcall get_LineConfiguration(Windows::ApplicationModel::Calls::IPhoneLineConfiguration ** value) = 0;
    virtual HRESULT __stdcall abi_IsImmediateDialNumberAsync(hstring number, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_Dial(hstring number, hstring displayName) = 0;
    virtual HRESULT __stdcall abi_DialWithOptions(Windows::ApplicationModel::Calls::IPhoneDialOptions * options) = 0;
};

struct __declspec(uuid("192601d5-147c-4769-b673-98a5ec8426cb")) __declspec(novtable) IPhoneLineCellularDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SimState(winrt::Windows::ApplicationModel::Calls::PhoneSimState * value) = 0;
    virtual HRESULT __stdcall get_SimSlotIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_IsModemOn(bool * value) = 0;
    virtual HRESULT __stdcall get_RegistrationRejectCode(int32_t * value) = 0;
    virtual HRESULT __stdcall abi_GetNetworkOperatorDisplayText(winrt::Windows::ApplicationModel::Calls::PhoneLineNetworkOperatorDisplayTextLocation location, hstring * value) = 0;
};

struct __declspec(uuid("fe265862-f64f-4312-b2a8-4e257721aa95")) __declspec(novtable) IPhoneLineConfiguration : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsVideoCallingEnabled(bool * value) = 0;
    virtual HRESULT __stdcall get_ExtendedProperties(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> ** value) = 0;
};

struct __declspec(uuid("f38b5f23-ceb0-404f-bcf2-ba9f697d8adf")) __declspec(novtable) IPhoneLineStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromIdAsync(GUID lineId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneLine> ** result) = 0;
};

struct __declspec(uuid("8a45cd0a-6323-44e0-a6f6-9f21f64dc90a")) __declspec(novtable) IPhoneLineWatcher : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
    virtual HRESULT __stdcall add_LineAdded(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_LineAdded(event_token token) = 0;
    virtual HRESULT __stdcall add_LineRemoved(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_LineRemoved(event_token token) = 0;
    virtual HRESULT __stdcall add_LineUpdated(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_LineUpdated(event_token token) = 0;
    virtual HRESULT __stdcall add_EnumerationCompleted(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_EnumerationCompleted(event_token token) = 0;
    virtual HRESULT __stdcall add_Stopped(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Stopped(event_token token) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::ApplicationModel::Calls::PhoneLineWatcherStatus * status) = 0;
};

struct __declspec(uuid("d07c753e-9e12-4a37-82b7-ad535dad6a67")) __declspec(novtable) IPhoneLineWatcherEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LineId(GUID * value) = 0;
};

struct __declspec(uuid("c9ce77f6-6e9f-3a8b-b727-6e0cf6998224")) __declspec(novtable) IPhoneVoicemail : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Number(hstring * value) = 0;
    virtual HRESULT __stdcall get_MessageCount(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Type(winrt::Windows::ApplicationModel::Calls::PhoneVoicemailType * value) = 0;
    virtual HRESULT __stdcall abi_DialVoicemailAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("4f118bcf-e8ef-4434-9c5f-a8d893fafe79")) __declspec(novtable) IVoipCallCoordinator : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ReserveCallResourcesAsync(hstring taskEntryPoint, Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus> ** operation) = 0;
    virtual HRESULT __stdcall add_MuteStateChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> * muteChangeHandler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MuteStateChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_RequestNewIncomingCall(hstring context, hstring contactName, hstring contactNumber, Windows::Foundation::IUriRuntimeClass * contactImage, hstring serviceName, Windows::Foundation::IUriRuntimeClass * brandingImage, hstring callDetails, Windows::Foundation::IUriRuntimeClass * ringtone, winrt::Windows::ApplicationModel::Calls::VoipPhoneCallMedia media, Windows::Foundation::TimeSpan ringTimeout, Windows::ApplicationModel::Calls::IVoipPhoneCall ** call) = 0;
    virtual HRESULT __stdcall abi_RequestNewOutgoingCall(hstring context, hstring contactName, hstring serviceName, winrt::Windows::ApplicationModel::Calls::VoipPhoneCallMedia media, Windows::ApplicationModel::Calls::IVoipPhoneCall ** call) = 0;
    virtual HRESULT __stdcall abi_NotifyMuted() = 0;
    virtual HRESULT __stdcall abi_NotifyUnmuted() = 0;
    virtual HRESULT __stdcall abi_RequestOutgoingUpgradeToVideoCall(GUID callUpgradeGuid, hstring context, hstring contactName, hstring serviceName, Windows::ApplicationModel::Calls::IVoipPhoneCall ** call) = 0;
    virtual HRESULT __stdcall abi_RequestIncomingUpgradeToVideoCall(hstring context, hstring contactName, hstring contactNumber, Windows::Foundation::IUriRuntimeClass * contactImage, hstring serviceName, Windows::Foundation::IUriRuntimeClass * brandingImage, hstring callDetails, Windows::Foundation::IUriRuntimeClass * ringtone, Windows::Foundation::TimeSpan ringTimeout, Windows::ApplicationModel::Calls::IVoipPhoneCall ** call) = 0;
    virtual HRESULT __stdcall abi_TerminateCellularCall(GUID callUpgradeGuid) = 0;
    virtual HRESULT __stdcall abi_CancelUpgrade(GUID callUpgradeGuid) = 0;
};

struct __declspec(uuid("7f5d1f2b-e04a-4d10-b31a-a55c922cc2fb")) __declspec(novtable) IVoipCallCoordinatorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::ApplicationModel::Calls::IVoipCallCoordinator ** coordinator) = 0;
};

struct __declspec(uuid("6cf1f19a-7794-4a5a-8c68-ae87947a6990")) __declspec(novtable) IVoipPhoneCall : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_EndRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_EndRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_HoldRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_HoldRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_ResumeRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ResumeRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_AnswerRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> * acceptHandler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AnswerRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_RejectRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> * rejectHandler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RejectRequested(event_token token) = 0;
    virtual HRESULT __stdcall abi_NotifyCallHeld() = 0;
    virtual HRESULT __stdcall abi_NotifyCallActive() = 0;
    virtual HRESULT __stdcall abi_NotifyCallEnded() = 0;
    virtual HRESULT __stdcall get_ContactName(hstring * value) = 0;
    virtual HRESULT __stdcall put_ContactName(hstring value) = 0;
    virtual HRESULT __stdcall get_StartTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_StartTime(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_CallMedia(winrt::Windows::ApplicationModel::Calls::VoipPhoneCallMedia * value) = 0;
    virtual HRESULT __stdcall put_CallMedia(winrt::Windows::ApplicationModel::Calls::VoipPhoneCallMedia value) = 0;
    virtual HRESULT __stdcall abi_NotifyCallReady() = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Calls::CallAnswerEventArgs> { using default_interface = Windows::ApplicationModel::Calls::ICallAnswerEventArgs; };
template <> struct traits<Windows::ApplicationModel::Calls::CallRejectEventArgs> { using default_interface = Windows::ApplicationModel::Calls::ICallRejectEventArgs; };
template <> struct traits<Windows::ApplicationModel::Calls::CallStateChangeEventArgs> { using default_interface = Windows::ApplicationModel::Calls::ICallStateChangeEventArgs; };
template <> struct traits<Windows::ApplicationModel::Calls::LockScreenCallEndCallDeferral> { using default_interface = Windows::ApplicationModel::Calls::ILockScreenCallEndCallDeferral; };
template <> struct traits<Windows::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs> { using default_interface = Windows::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Calls::LockScreenCallUI> { using default_interface = Windows::ApplicationModel::Calls::ILockScreenCallUI; };
template <> struct traits<Windows::ApplicationModel::Calls::MuteChangeEventArgs> { using default_interface = Windows::ApplicationModel::Calls::IMuteChangeEventArgs; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> { using default_interface = Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress> { using default_interface = Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions> { using default_interface = Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader> { using default_interface = Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser> { using default_interface = Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> { using default_interface = Windows::ApplicationModel::Calls::IPhoneCallHistoryStore; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallStore> { using default_interface = Windows::ApplicationModel::Calls::IPhoneCallStore; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallVideoCapabilities> { using default_interface = Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilities; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneDialOptions> { using default_interface = Windows::ApplicationModel::Calls::IPhoneDialOptions; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneLine> { using default_interface = Windows::ApplicationModel::Calls::IPhoneLine; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneLineCellularDetails> { using default_interface = Windows::ApplicationModel::Calls::IPhoneLineCellularDetails; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneLineConfiguration> { using default_interface = Windows::ApplicationModel::Calls::IPhoneLineConfiguration; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneLineWatcher> { using default_interface = Windows::ApplicationModel::Calls::IPhoneLineWatcher; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> { using default_interface = Windows::ApplicationModel::Calls::IPhoneLineWatcherEventArgs; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneVoicemail> { using default_interface = Windows::ApplicationModel::Calls::IPhoneVoicemail; };
template <> struct traits<Windows::ApplicationModel::Calls::VoipCallCoordinator> { using default_interface = Windows::ApplicationModel::Calls::IVoipCallCoordinator; };
template <> struct traits<Windows::ApplicationModel::Calls::VoipPhoneCall> { using default_interface = Windows::ApplicationModel::Calls::IVoipPhoneCall; };

}

namespace Windows::ApplicationModel::Calls {

template <typename D>
struct WINRT_EBO impl_ICallAnswerEventArgs
{
    Windows::ApplicationModel::Calls::VoipPhoneCallMedia AcceptedMedia() const;
};

template <typename D>
struct WINRT_EBO impl_ICallRejectEventArgs
{
    Windows::ApplicationModel::Calls::VoipPhoneCallRejectReason RejectReason() const;
};

template <typename D>
struct WINRT_EBO impl_ICallStateChangeEventArgs
{
    Windows::ApplicationModel::Calls::VoipPhoneCallState State() const;
};

template <typename D>
struct WINRT_EBO impl_ILockScreenCallEndCallDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_ILockScreenCallEndRequestedEventArgs
{
    Windows::ApplicationModel::Calls::LockScreenCallEndCallDeferral GetDeferral() const;
    Windows::Foundation::DateTime Deadline() const;
};

template <typename D>
struct WINRT_EBO impl_ILockScreenCallUI
{
    void Dismiss() const;
    event_token EndRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::LockScreenCallUI, Windows::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs> & handler) const;
    using EndRequested_revoker = event_revoker<ILockScreenCallUI>;
    EndRequested_revoker EndRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::LockScreenCallUI, Windows::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs> & handler) const;
    void EndRequested(event_token token) const;
    event_token Closed(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::LockScreenCallUI, Windows::Foundation::IInspectable> & handler) const;
    using Closed_revoker = event_revoker<ILockScreenCallUI>;
    Closed_revoker Closed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::LockScreenCallUI, Windows::Foundation::IInspectable> & handler) const;
    void Closed(event_token token) const;
    hstring CallTitle() const;
    void CallTitle(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IMuteChangeEventArgs
{
    bool Muted() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallBlockingStatics
{
    bool BlockUnknownNumbers() const;
    void BlockUnknownNumbers(bool value) const;
    bool BlockPrivateNumbers() const;
    void BlockPrivateNumbers(bool value) const;
    Windows::Foundation::IAsyncOperation<bool> SetCallBlockingListAsync(iterable<hstring> phoneNumberList) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryEntry
{
    hstring Id() const;
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress Address() const;
    void Address(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress & value) const;
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> Duration() const;
    void Duration(const optional<Windows::Foundation::TimeSpan> & value) const;
    bool IsCallerIdBlocked() const;
    void IsCallerIdBlocked(bool value) const;
    bool IsEmergency() const;
    void IsEmergency(bool value) const;
    bool IsIncoming() const;
    void IsIncoming(bool value) const;
    bool IsMissed() const;
    void IsMissed(bool value) const;
    bool IsRinging() const;
    void IsRinging(bool value) const;
    bool IsSeen() const;
    void IsSeen(bool value) const;
    bool IsSuppressed() const;
    void IsSuppressed(bool value) const;
    bool IsVoicemail() const;
    void IsVoicemail(bool value) const;
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia Media() const;
    void Media(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia value) const;
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess OtherAppReadAccess() const;
    void OtherAppReadAccess(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess value) const;
    hstring RemoteId() const;
    void RemoteId(hstring_view value) const;
    hstring SourceDisplayName() const;
    hstring SourceId() const;
    void SourceId(hstring_view value) const;
    Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind SourceIdKind() const;
    void SourceIdKind(Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind value) const;
    Windows::Foundation::DateTime StartTime() const;
    void StartTime(const Windows::Foundation::DateTime & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryEntryAddress
{
    hstring ContactId() const;
    void ContactId(hstring_view value) const;
    hstring DisplayName() const;
    void DisplayName(hstring_view value) const;
    hstring RawAddress() const;
    void RawAddress(hstring_view value) const;
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind RawAddressKind() const;
    void RawAddressKind(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind value) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryEntryAddressFactory
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress Create(hstring_view rawAddress, Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind rawAddressKind) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryEntryQueryOptions
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia DesiredMedia() const;
    void DesiredMedia(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia value) const;
    Windows::Foundation::Collections::IVector<hstring> SourceIds() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryEntryReader
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> ReadBatchAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryManagerForUser
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType) const;
    Windows::System::User User() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryManagerStatics
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryManagerStatics2
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser GetForUser(const Windows::System::User & user) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryStore
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> GetEntryAsync(hstring_view callHistoryEntryId) const;
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader GetEntryReader() const;
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader GetEntryReader(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions & queryOptions) const;
    Windows::Foundation::IAsyncAction SaveEntryAsync(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry & callHistoryEntry) const;
    Windows::Foundation::IAsyncAction DeleteEntryAsync(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry & callHistoryEntry) const;
    Windows::Foundation::IAsyncAction DeleteEntriesAsync(iterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> callHistoryEntries) const;
    Windows::Foundation::IAsyncAction MarkEntryAsSeenAsync(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry & callHistoryEntry) const;
    Windows::Foundation::IAsyncAction MarkEntriesAsSeenAsync(iterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> callHistoryEntries) const;
    Windows::Foundation::IAsyncOperation<uint32_t> GetUnseenCountAsync() const;
    Windows::Foundation::IAsyncAction MarkAllAsSeenAsync() const;
    Windows::Foundation::IAsyncOperation<uint32_t> GetSourcesUnseenCountAsync(iterable<hstring> sourceIds) const;
    Windows::Foundation::IAsyncAction MarkSourcesAsSeenAsync(iterable<hstring> sourceIds) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallManagerStatics
{
    void ShowPhoneCallUI(hstring_view phoneNumber, hstring_view displayName) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallManagerStatics2
{
    event_token CallStateChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    using CallStateChanged_revoker = event_revoker<IPhoneCallManagerStatics2>;
    CallStateChanged_revoker CallStateChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    void CallStateChanged(event_token token) const;
    bool IsCallActive() const;
    bool IsCallIncoming() const;
    void ShowPhoneCallSettingsUI() const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallStore> RequestStoreAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallStore
{
    Windows::Foundation::IAsyncOperation<bool> IsEmergencyPhoneNumberAsync(hstring_view number) const;
    Windows::Foundation::IAsyncOperation<GUID> GetDefaultLineAsync() const;
    Windows::ApplicationModel::Calls::PhoneLineWatcher RequestLineWatcher() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallVideoCapabilities
{
    bool IsVideoCallingCapable() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallVideoCapabilitiesManagerStatics
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallVideoCapabilities> GetCapabilitiesAsync(hstring_view phoneNumber) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneDialOptions
{
    hstring Number() const;
    void Number(hstring_view value) const;
    hstring DisplayName() const;
    void DisplayName(hstring_view value) const;
    Windows::ApplicationModel::Contacts::Contact Contact() const;
    void Contact(const Windows::ApplicationModel::Contacts::Contact & value) const;
    Windows::ApplicationModel::Contacts::ContactPhone ContactPhone() const;
    void ContactPhone(const Windows::ApplicationModel::Contacts::ContactPhone & value) const;
    Windows::ApplicationModel::Calls::PhoneCallMedia Media() const;
    void Media(Windows::ApplicationModel::Calls::PhoneCallMedia value) const;
    Windows::ApplicationModel::Calls::PhoneAudioRoutingEndpoint AudioEndpoint() const;
    void AudioEndpoint(Windows::ApplicationModel::Calls::PhoneAudioRoutingEndpoint value) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneLine
{
    event_token LineChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLine, Windows::Foundation::IInspectable> & handler) const;
    using LineChanged_revoker = event_revoker<IPhoneLine>;
    LineChanged_revoker LineChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLine, Windows::Foundation::IInspectable> & handler) const;
    void LineChanged(event_token token) const;
    GUID Id() const;
    Windows::UI::Color DisplayColor() const;
    Windows::ApplicationModel::Calls::PhoneNetworkState NetworkState() const;
    hstring DisplayName() const;
    Windows::ApplicationModel::Calls::PhoneVoicemail Voicemail() const;
    hstring NetworkName() const;
    Windows::ApplicationModel::Calls::PhoneLineCellularDetails CellularDetails() const;
    Windows::ApplicationModel::Calls::PhoneLineTransport Transport() const;
    bool CanDial() const;
    bool SupportsTile() const;
    Windows::ApplicationModel::Calls::PhoneCallVideoCapabilities VideoCallingCapabilities() const;
    Windows::ApplicationModel::Calls::PhoneLineConfiguration LineConfiguration() const;
    Windows::Foundation::IAsyncOperation<bool> IsImmediateDialNumberAsync(hstring_view number) const;
    void Dial(hstring_view number, hstring_view displayName) const;
    void DialWithOptions(const Windows::ApplicationModel::Calls::PhoneDialOptions & options) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneLineCellularDetails
{
    Windows::ApplicationModel::Calls::PhoneSimState SimState() const;
    int32_t SimSlotIndex() const;
    bool IsModemOn() const;
    int32_t RegistrationRejectCode() const;
    hstring GetNetworkOperatorDisplayText(Windows::ApplicationModel::Calls::PhoneLineNetworkOperatorDisplayTextLocation location) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneLineConfiguration
{
    bool IsVideoCallingEnabled() const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> ExtendedProperties() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneLineStatics
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneLine> FromIdAsync(GUID lineId) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneLineWatcher
{
    void Start() const;
    void Stop() const;
    event_token LineAdded(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> & handler) const;
    using LineAdded_revoker = event_revoker<IPhoneLineWatcher>;
    LineAdded_revoker LineAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> & handler) const;
    void LineAdded(event_token token) const;
    event_token LineRemoved(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> & handler) const;
    using LineRemoved_revoker = event_revoker<IPhoneLineWatcher>;
    LineRemoved_revoker LineRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> & handler) const;
    void LineRemoved(event_token token) const;
    event_token LineUpdated(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> & handler) const;
    using LineUpdated_revoker = event_revoker<IPhoneLineWatcher>;
    LineUpdated_revoker LineUpdated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs> & handler) const;
    void LineUpdated(event_token token) const;
    event_token EnumerationCompleted(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::Foundation::IInspectable> & handler) const;
    using EnumerationCompleted_revoker = event_revoker<IPhoneLineWatcher>;
    EnumerationCompleted_revoker EnumerationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::Foundation::IInspectable> & handler) const;
    void EnumerationCompleted(event_token token) const;
    event_token Stopped(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::Foundation::IInspectable> & handler) const;
    using Stopped_revoker = event_revoker<IPhoneLineWatcher>;
    Stopped_revoker Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::PhoneLineWatcher, Windows::Foundation::IInspectable> & handler) const;
    void Stopped(event_token token) const;
    Windows::ApplicationModel::Calls::PhoneLineWatcherStatus Status() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneLineWatcherEventArgs
{
    GUID LineId() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneVoicemail
{
    hstring Number() const;
    int32_t MessageCount() const;
    Windows::ApplicationModel::Calls::PhoneVoicemailType Type() const;
    Windows::Foundation::IAsyncAction DialVoicemailAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IVoipCallCoordinator
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus> ReserveCallResourcesAsync(hstring_view taskEntryPoint) const;
    event_token MuteStateChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> & muteChangeHandler) const;
    using MuteStateChanged_revoker = event_revoker<IVoipCallCoordinator>;
    MuteStateChanged_revoker MuteStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> & muteChangeHandler) const;
    void MuteStateChanged(event_token token) const;
    Windows::ApplicationModel::Calls::VoipPhoneCall RequestNewIncomingCall(hstring_view context, hstring_view contactName, hstring_view contactNumber, const Windows::Foundation::Uri & contactImage, hstring_view serviceName, const Windows::Foundation::Uri & brandingImage, hstring_view callDetails, const Windows::Foundation::Uri & ringtone, Windows::ApplicationModel::Calls::VoipPhoneCallMedia media, const Windows::Foundation::TimeSpan & ringTimeout) const;
    Windows::ApplicationModel::Calls::VoipPhoneCall RequestNewOutgoingCall(hstring_view context, hstring_view contactName, hstring_view serviceName, Windows::ApplicationModel::Calls::VoipPhoneCallMedia media) const;
    void NotifyMuted() const;
    void NotifyUnmuted() const;
    Windows::ApplicationModel::Calls::VoipPhoneCall RequestOutgoingUpgradeToVideoCall(GUID callUpgradeGuid, hstring_view context, hstring_view contactName, hstring_view serviceName) const;
    Windows::ApplicationModel::Calls::VoipPhoneCall RequestIncomingUpgradeToVideoCall(hstring_view context, hstring_view contactName, hstring_view contactNumber, const Windows::Foundation::Uri & contactImage, hstring_view serviceName, const Windows::Foundation::Uri & brandingImage, hstring_view callDetails, const Windows::Foundation::Uri & ringtone, const Windows::Foundation::TimeSpan & ringTimeout) const;
    void TerminateCellularCall(GUID callUpgradeGuid) const;
    void CancelUpgrade(GUID callUpgradeGuid) const;
};

template <typename D>
struct WINRT_EBO impl_IVoipCallCoordinatorStatics
{
    Windows::ApplicationModel::Calls::VoipCallCoordinator GetDefault() const;
};

template <typename D>
struct WINRT_EBO impl_IVoipPhoneCall
{
    event_token EndRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const;
    using EndRequested_revoker = event_revoker<IVoipPhoneCall>;
    EndRequested_revoker EndRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const;
    void EndRequested(event_token token) const;
    event_token HoldRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const;
    using HoldRequested_revoker = event_revoker<IVoipPhoneCall>;
    HoldRequested_revoker HoldRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const;
    void HoldRequested(event_token token) const;
    event_token ResumeRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const;
    using ResumeRequested_revoker = event_revoker<IVoipPhoneCall>;
    ResumeRequested_revoker ResumeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const;
    void ResumeRequested(event_token token) const;
    event_token AnswerRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> & acceptHandler) const;
    using AnswerRequested_revoker = event_revoker<IVoipPhoneCall>;
    AnswerRequested_revoker AnswerRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> & acceptHandler) const;
    void AnswerRequested(event_token token) const;
    event_token RejectRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> & rejectHandler) const;
    using RejectRequested_revoker = event_revoker<IVoipPhoneCall>;
    RejectRequested_revoker RejectRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> & rejectHandler) const;
    void RejectRequested(event_token token) const;
    void NotifyCallHeld() const;
    void NotifyCallActive() const;
    void NotifyCallEnded() const;
    hstring ContactName() const;
    void ContactName(hstring_view value) const;
    Windows::Foundation::DateTime StartTime() const;
    void StartTime(const Windows::Foundation::DateTime & value) const;
    Windows::ApplicationModel::Calls::VoipPhoneCallMedia CallMedia() const;
    void CallMedia(Windows::ApplicationModel::Calls::VoipPhoneCallMedia value) const;
    void NotifyCallReady() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Calls::ICallAnswerEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::ICallAnswerEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_ICallAnswerEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::ICallRejectEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::ICallRejectEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_ICallRejectEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::ICallStateChangeEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::ICallStateChangeEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_ICallStateChangeEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::ILockScreenCallEndCallDeferral>
{
    using abi = ABI::Windows::ApplicationModel::Calls::ILockScreenCallEndCallDeferral;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_ILockScreenCallEndCallDeferral<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_ILockScreenCallEndRequestedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::ILockScreenCallUI>
{
    using abi = ABI::Windows::ApplicationModel::Calls::ILockScreenCallUI;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_ILockScreenCallUI<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IMuteChangeEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IMuteChangeEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IMuteChangeEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallBlockingStatics>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallBlockingStatics;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallBlockingStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryEntry<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryEntryAddress<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryEntryAddressFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryEntryQueryOptions<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryEntryReader<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryManagerForUser<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryManagerStatics2<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryStore<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallManagerStatics2>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallManagerStatics2;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallManagerStatics2<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallStore>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallStore;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallStore<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilities>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilities;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallVideoCapabilities<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilitiesManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilitiesManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallVideoCapabilitiesManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneDialOptions>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneDialOptions;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneDialOptions<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneLine>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneLine;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneLine<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneLineCellularDetails>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneLineCellularDetails;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneLineCellularDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneLineConfiguration>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneLineConfiguration;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneLineConfiguration<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneLineStatics>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneLineStatics;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneLineStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneLineWatcher>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneLineWatcher<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneLineWatcherEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcherEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneLineWatcherEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneVoicemail>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneVoicemail;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneVoicemail<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IVoipCallCoordinator>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IVoipCallCoordinator<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IVoipCallCoordinatorStatics>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinatorStatics;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IVoipCallCoordinatorStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IVoipPhoneCall>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IVoipPhoneCall<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::CallAnswerEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::CallAnswerEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.CallAnswerEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::CallRejectEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::CallRejectEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.CallRejectEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::CallStateChangeEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::CallStateChangeEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.CallStateChangeEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::LockScreenCallEndCallDeferral>
{
    using abi = ABI::Windows::ApplicationModel::Calls::LockScreenCallEndCallDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.LockScreenCallEndCallDeferral"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.LockScreenCallEndRequestedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::LockScreenCallUI>
{
    using abi = ABI::Windows::ApplicationModel::Calls::LockScreenCallUI;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.LockScreenCallUI"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::MuteChangeEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::MuteChangeEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.MuteChangeEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallBlocking>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallBlocking"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntry"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntryAddress"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntryQueryOptions"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntryReader"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallHistoryManager"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallHistoryManagerForUser"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryStore>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryStore;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallHistoryStore"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallManager"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallStore>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneCallStore;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallStore"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallVideoCapabilities>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneCallVideoCapabilities;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallVideoCapabilities"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallVideoCapabilitiesManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallVideoCapabilitiesManager"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneDialOptions>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneDialOptions;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneDialOptions"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneLine>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneLine;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneLine"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneLineCellularDetails>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneLineCellularDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneLineCellularDetails"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneLineConfiguration>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneLineConfiguration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneLineConfiguration"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneLineWatcher>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneLineWatcher;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneLineWatcher"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneLineWatcherEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneVoicemail>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneVoicemail;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneVoicemail"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::VoipCallCoordinator>
{
    using abi = ABI::Windows::ApplicationModel::Calls::VoipCallCoordinator;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.VoipCallCoordinator"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::VoipPhoneCall>
{
    using abi = ABI::Windows::ApplicationModel::Calls::VoipPhoneCall;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.VoipPhoneCall"; }
};

}

}
