// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Appointments.DataProvider.0.h"
#include "Windows.ApplicationModel.Appointments.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.ApplicationModel.Appointments.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Appointments::DataProvider {

struct __declspec(uuid("49460f8d-6434-40d7-ad46-6297419314d1")) __declspec(novtable) IAppointmentCalendarCancelMeetingRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppointmentCalendarLocalId(hstring * value) = 0;
    virtual HRESULT __stdcall get_AppointmentLocalId(hstring * value) = 0;
    virtual HRESULT __stdcall get_AppointmentOriginalStartTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_Subject(hstring * value) = 0;
    virtual HRESULT __stdcall get_Comment(hstring * value) = 0;
    virtual HRESULT __stdcall get_NotifyInvitees(bool * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("1a79be16-7f30-4e35-beef-9d2c7b6dcae1")) __declspec(novtable) IAppointmentCalendarCancelMeetingRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("2e62f2b2-ca96-48ac-9124-406b19fefa70")) __declspec(novtable) IAppointmentCalendarCreateOrUpdateAppointmentRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppointmentCalendarLocalId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Appointment(Windows::ApplicationModel::Appointments::IAppointment ** value) = 0;
    virtual HRESULT __stdcall get_NotifyInvitees(bool * value) = 0;
    virtual HRESULT __stdcall get_ChangedProperties(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::ApplicationModel::Appointments::IAppointment * createdOrUpdatedAppointment, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("cf8ded28-002e-4bf7-8e9d-5e20d49aa3ba")) __declspec(novtable) IAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("82e5ee56-26b6-4253-8a8f-6cf5f2ff7884")) __declspec(novtable) IAppointmentCalendarForwardMeetingRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppointmentCalendarLocalId(hstring * value) = 0;
    virtual HRESULT __stdcall get_AppointmentLocalId(hstring * value) = 0;
    virtual HRESULT __stdcall get_AppointmentOriginalStartTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_Invitees(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentInvitee> ** value) = 0;
    virtual HRESULT __stdcall get_Subject(hstring * value) = 0;
    virtual HRESULT __stdcall get_ForwardHeader(hstring * value) = 0;
    virtual HRESULT __stdcall get_Comment(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("3109151a-23a2-42fd-9c82-c9a60d59f8a8")) __declspec(novtable) IAppointmentCalendarForwardMeetingRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("ce1c63f5-edf6-43c3-82b7-be6b368c6900")) __declspec(novtable) IAppointmentCalendarProposeNewTimeForMeetingRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppointmentCalendarLocalId(hstring * value) = 0;
    virtual HRESULT __stdcall get_AppointmentLocalId(hstring * value) = 0;
    virtual HRESULT __stdcall get_AppointmentOriginalStartTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_NewStartTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_NewDuration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Subject(hstring * value) = 0;
    virtual HRESULT __stdcall get_Comment(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("d2d777d8-fed1-4280-a3ba-2e1f47609aa2")) __declspec(novtable) IAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("12ab382b-7163-4a56-9a4e-7223a84adf46")) __declspec(novtable) IAppointmentCalendarSyncManagerSyncRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppointmentCalendarLocalId(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("ca17c6f7-0284-4edd-87ba-4d8f69dcf5c0")) __declspec(novtable) IAppointmentCalendarSyncManagerSyncRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarSyncManagerSyncRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("a36d608c-c29d-4b94-b086-7e9ff7bd84a0")) __declspec(novtable) IAppointmentCalendarUpdateMeetingResponseRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppointmentCalendarLocalId(hstring * value) = 0;
    virtual HRESULT __stdcall get_AppointmentLocalId(hstring * value) = 0;
    virtual HRESULT __stdcall get_AppointmentOriginalStartTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_Response(winrt::Windows::ApplicationModel::Appointments::AppointmentParticipantResponse * response) = 0;
    virtual HRESULT __stdcall get_Subject(hstring * value) = 0;
    virtual HRESULT __stdcall get_Comment(hstring * value) = 0;
    virtual HRESULT __stdcall get_SendUpdate(bool * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("88759883-97bf-479d-aed5-0be8ce567d1e")) __declspec(novtable) IAppointmentCalendarUpdateMeetingResponseRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("f3dd9d83-3254-465f-abdb-928046552cf4")) __declspec(novtable) IAppointmentDataProviderConnection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_SyncRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarSyncManagerSyncRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SyncRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_CreateOrUpdateAppointmentRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CreateOrUpdateAppointmentRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_CancelMeetingRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCancelMeetingRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CancelMeetingRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_ForwardMeetingRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarForwardMeetingRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ForwardMeetingRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_ProposeNewTimeForMeetingRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarProposeNewTimeForMeetingRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ProposeNewTimeForMeetingRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_UpdateMeetingResponseRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarUpdateMeetingResponseRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_UpdateMeetingResponseRequested(event_token token) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
};

struct __declspec(uuid("b3283c01-7e12-4e5e-b1ef-74fb68ac6f2a")) __declspec(novtable) IAppointmentDataProviderTriggerDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Connection(Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCancelMeetingRequest> { using default_interface = Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequest; };
template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCancelMeetingRequestEventArgs> { using default_interface = Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCreateOrUpdateAppointmentRequest> { using default_interface = Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequest; };
template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs> { using default_interface = Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarForwardMeetingRequest> { using default_interface = Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequest; };
template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarForwardMeetingRequestEventArgs> { using default_interface = Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarProposeNewTimeForMeetingRequest> { using default_interface = Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequest; };
template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarProposeNewTimeForMeetingRequestEventArgs> { using default_interface = Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarSyncManagerSyncRequest> { using default_interface = Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarSyncManagerSyncRequest; };
template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarSyncManagerSyncRequestEventArgs> { using default_interface = Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarSyncManagerSyncRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarUpdateMeetingResponseRequest> { using default_interface = Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequest; };
template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarUpdateMeetingResponseRequestEventArgs> { using default_interface = Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection> { using default_interface = Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection; };
template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderTriggerDetails> { using default_interface = Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderTriggerDetails; };

}

namespace Windows::ApplicationModel::Appointments::DataProvider {

template <typename D>
struct WINRT_EBO impl_IAppointmentCalendarCancelMeetingRequest
{
    hstring AppointmentCalendarLocalId() const;
    hstring AppointmentLocalId() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> AppointmentOriginalStartTime() const;
    hstring Subject() const;
    hstring Comment() const;
    bool NotifyInvitees() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync() const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentCalendarCancelMeetingRequestEventArgs
{
    Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCancelMeetingRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentCalendarCreateOrUpdateAppointmentRequest
{
    hstring AppointmentCalendarLocalId() const;
    Windows::ApplicationModel::Appointments::Appointment Appointment() const;
    bool NotifyInvitees() const;
    Windows::Foundation::Collections::IVectorView<hstring> ChangedProperties() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync(const Windows::ApplicationModel::Appointments::Appointment & createdOrUpdatedAppointment) const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs
{
    Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCreateOrUpdateAppointmentRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentCalendarForwardMeetingRequest
{
    hstring AppointmentCalendarLocalId() const;
    hstring AppointmentLocalId() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> AppointmentOriginalStartTime() const;
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentInvitee> Invitees() const;
    hstring Subject() const;
    hstring ForwardHeader() const;
    hstring Comment() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync() const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentCalendarForwardMeetingRequestEventArgs
{
    Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarForwardMeetingRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentCalendarProposeNewTimeForMeetingRequest
{
    hstring AppointmentCalendarLocalId() const;
    hstring AppointmentLocalId() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> AppointmentOriginalStartTime() const;
    Windows::Foundation::DateTime NewStartTime() const;
    Windows::Foundation::TimeSpan NewDuration() const;
    hstring Subject() const;
    hstring Comment() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync() const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs
{
    Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarProposeNewTimeForMeetingRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentCalendarSyncManagerSyncRequest
{
    hstring AppointmentCalendarLocalId() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync() const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentCalendarSyncManagerSyncRequestEventArgs
{
    Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarSyncManagerSyncRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentCalendarUpdateMeetingResponseRequest
{
    hstring AppointmentCalendarLocalId() const;
    hstring AppointmentLocalId() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> AppointmentOriginalStartTime() const;
    Windows::ApplicationModel::Appointments::AppointmentParticipantResponse Response() const;
    hstring Subject() const;
    hstring Comment() const;
    bool SendUpdate() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync() const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentCalendarUpdateMeetingResponseRequestEventArgs
{
    Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarUpdateMeetingResponseRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentDataProviderConnection
{
    event_token SyncRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarSyncManagerSyncRequestEventArgs> & handler) const;
    using SyncRequested_revoker = event_revoker<IAppointmentDataProviderConnection>;
    SyncRequested_revoker SyncRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarSyncManagerSyncRequestEventArgs> & handler) const;
    void SyncRequested(event_token token) const;
    event_token CreateOrUpdateAppointmentRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs> & handler) const;
    using CreateOrUpdateAppointmentRequested_revoker = event_revoker<IAppointmentDataProviderConnection>;
    CreateOrUpdateAppointmentRequested_revoker CreateOrUpdateAppointmentRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs> & handler) const;
    void CreateOrUpdateAppointmentRequested(event_token token) const;
    event_token CancelMeetingRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCancelMeetingRequestEventArgs> & handler) const;
    using CancelMeetingRequested_revoker = event_revoker<IAppointmentDataProviderConnection>;
    CancelMeetingRequested_revoker CancelMeetingRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCancelMeetingRequestEventArgs> & handler) const;
    void CancelMeetingRequested(event_token token) const;
    event_token ForwardMeetingRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarForwardMeetingRequestEventArgs> & handler) const;
    using ForwardMeetingRequested_revoker = event_revoker<IAppointmentDataProviderConnection>;
    ForwardMeetingRequested_revoker ForwardMeetingRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarForwardMeetingRequestEventArgs> & handler) const;
    void ForwardMeetingRequested(event_token token) const;
    event_token ProposeNewTimeForMeetingRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarProposeNewTimeForMeetingRequestEventArgs> & handler) const;
    using ProposeNewTimeForMeetingRequested_revoker = event_revoker<IAppointmentDataProviderConnection>;
    ProposeNewTimeForMeetingRequested_revoker ProposeNewTimeForMeetingRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarProposeNewTimeForMeetingRequestEventArgs> & handler) const;
    void ProposeNewTimeForMeetingRequested(event_token token) const;
    event_token UpdateMeetingResponseRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarUpdateMeetingResponseRequestEventArgs> & handler) const;
    using UpdateMeetingResponseRequested_revoker = event_revoker<IAppointmentDataProviderConnection>;
    UpdateMeetingResponseRequested_revoker UpdateMeetingResponseRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection, Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarUpdateMeetingResponseRequestEventArgs> & handler) const;
    void UpdateMeetingResponseRequested(event_token token) const;
    void Start() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentDataProviderTriggerDetails
{
    Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection Connection() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequest>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequest;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::DataProvider::impl_IAppointmentCalendarCancelMeetingRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::DataProvider::impl_IAppointmentCalendarCancelMeetingRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequest>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequest;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::DataProvider::impl_IAppointmentCalendarCreateOrUpdateAppointmentRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::DataProvider::impl_IAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequest>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequest;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::DataProvider::impl_IAppointmentCalendarForwardMeetingRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::DataProvider::impl_IAppointmentCalendarForwardMeetingRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequest>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequest;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::DataProvider::impl_IAppointmentCalendarProposeNewTimeForMeetingRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::DataProvider::impl_IAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarSyncManagerSyncRequest>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarSyncManagerSyncRequest;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::DataProvider::impl_IAppointmentCalendarSyncManagerSyncRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarSyncManagerSyncRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarSyncManagerSyncRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::DataProvider::impl_IAppointmentCalendarSyncManagerSyncRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequest>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequest;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::DataProvider::impl_IAppointmentCalendarUpdateMeetingResponseRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::DataProvider::impl_IAppointmentCalendarUpdateMeetingResponseRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::DataProvider::impl_IAppointmentDataProviderConnection<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderTriggerDetails;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::DataProvider::impl_IAppointmentDataProviderTriggerDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCancelMeetingRequest>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCancelMeetingRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarCancelMeetingRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCancelMeetingRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCancelMeetingRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarCancelMeetingRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCreateOrUpdateAppointmentRequest>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCreateOrUpdateAppointmentRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarCreateOrUpdateAppointmentRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarForwardMeetingRequest>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarForwardMeetingRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarForwardMeetingRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarForwardMeetingRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarForwardMeetingRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarForwardMeetingRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarProposeNewTimeForMeetingRequest>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarProposeNewTimeForMeetingRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarProposeNewTimeForMeetingRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarProposeNewTimeForMeetingRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarProposeNewTimeForMeetingRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarProposeNewTimeForMeetingRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarSyncManagerSyncRequest>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarSyncManagerSyncRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarSyncManagerSyncRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarSyncManagerSyncRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarSyncManagerSyncRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarSyncManagerSyncRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarUpdateMeetingResponseRequest>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarUpdateMeetingResponseRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarUpdateMeetingResponseRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarUpdateMeetingResponseRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarUpdateMeetingResponseRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarUpdateMeetingResponseRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.DataProvider.AppointmentDataProviderConnection"; }
};

template <> struct traits<Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.DataProvider.AppointmentDataProviderTriggerDetails"; }
};

}

}
