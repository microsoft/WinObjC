// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Appointments.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Appointments {

struct WINRT_EBO Appointment :
    Windows::ApplicationModel::Appointments::IAppointment,
    impl::require<Appointment, Windows::ApplicationModel::Appointments::IAppointment2, Windows::ApplicationModel::Appointments::IAppointment3>
{
    Appointment(std::nullptr_t) noexcept {}
    Appointment();
};

struct WINRT_EBO AppointmentCalendar :
    Windows::ApplicationModel::Appointments::IAppointmentCalendar,
    impl::require<AppointmentCalendar, Windows::ApplicationModel::Appointments::IAppointmentCalendar2, Windows::ApplicationModel::Appointments::IAppointmentCalendar3>
{
    AppointmentCalendar(std::nullptr_t) noexcept {}
    using impl_IAppointmentCalendar::DisplayColor;
    using impl_IAppointmentCalendar::IsHidden;
    using impl_IAppointmentCalendar2::DisplayColor;
    using impl_IAppointmentCalendar2::IsHidden;
};

struct WINRT_EBO AppointmentCalendarSyncManager :
    Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager,
    impl::require<AppointmentCalendarSyncManager, Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager2>
{
    AppointmentCalendarSyncManager(std::nullptr_t) noexcept {}
    using impl_IAppointmentCalendarSyncManager::LastAttemptedSyncTime;
    using impl_IAppointmentCalendarSyncManager::LastSuccessfulSyncTime;
    using impl_IAppointmentCalendarSyncManager::Status;
    using impl_IAppointmentCalendarSyncManager2::LastAttemptedSyncTime;
    using impl_IAppointmentCalendarSyncManager2::LastSuccessfulSyncTime;
    using impl_IAppointmentCalendarSyncManager2::Status;
};

struct WINRT_EBO AppointmentConflictResult :
    Windows::ApplicationModel::Appointments::IAppointmentConflictResult
{
    AppointmentConflictResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppointmentException :
    Windows::ApplicationModel::Appointments::IAppointmentException
{
    AppointmentException(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppointmentInvitee :
    Windows::ApplicationModel::Appointments::IAppointmentInvitee
{
    AppointmentInvitee(std::nullptr_t) noexcept {}
    AppointmentInvitee();
};

struct AppointmentManager
{
    AppointmentManager() = delete;
    static Windows::Foundation::IAsyncOperation<hstring> ShowAddAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection);
    static Windows::Foundation::IAsyncOperation<hstring> ShowAddAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement);
    static Windows::Foundation::IAsyncOperation<hstring> ShowReplaceAppointmentAsync(hstring_view appointmentId, const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection);
    static Windows::Foundation::IAsyncOperation<hstring> ShowReplaceAppointmentAsync(hstring_view appointmentId, const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement);
    static Windows::Foundation::IAsyncOperation<hstring> ShowReplaceAppointmentAsync(hstring_view appointmentId, const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::Foundation::DateTime & instanceStartDate);
    static Windows::Foundation::IAsyncOperation<bool> ShowRemoveAppointmentAsync(hstring_view appointmentId, const Windows::Foundation::Rect & selection);
    static Windows::Foundation::IAsyncOperation<bool> ShowRemoveAppointmentAsync(hstring_view appointmentId, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement);
    static Windows::Foundation::IAsyncOperation<bool> ShowRemoveAppointmentAsync(hstring_view appointmentId, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::Foundation::DateTime & instanceStartDate);
    static Windows::Foundation::IAsyncAction ShowTimeFrameAsync(const Windows::Foundation::DateTime & timeToShow, const Windows::Foundation::TimeSpan & duration);
    static Windows::Foundation::IAsyncAction ShowAppointmentDetailsAsync(hstring_view appointmentId);
    static Windows::Foundation::IAsyncAction ShowAppointmentDetailsAsync(hstring_view appointmentId, const Windows::Foundation::DateTime & instanceStartDate);
    static Windows::Foundation::IAsyncOperation<hstring> ShowEditNewAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment);
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentStore> RequestStoreAsync(Windows::ApplicationModel::Appointments::AppointmentStoreAccessType options);
    static Windows::ApplicationModel::Appointments::AppointmentManagerForUser GetForUser(const Windows::System::User & user);
};

struct WINRT_EBO AppointmentManagerForUser :
    Windows::ApplicationModel::Appointments::IAppointmentManagerForUser
{
    AppointmentManagerForUser(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppointmentOrganizer :
    Windows::ApplicationModel::Appointments::IAppointmentParticipant
{
    AppointmentOrganizer(std::nullptr_t) noexcept {}
    AppointmentOrganizer();
};

struct AppointmentProperties
{
    AppointmentProperties() = delete;
    static hstring Subject();
    static hstring Location();
    static hstring StartTime();
    static hstring Duration();
    static hstring Reminder();
    static hstring BusyStatus();
    static hstring Sensitivity();
    static hstring OriginalStartTime();
    static hstring IsResponseRequested();
    static hstring AllowNewTimeProposal();
    static hstring AllDay();
    static hstring Details();
    static hstring OnlineMeetingLink();
    static hstring ReplyTime();
    static hstring Organizer();
    static hstring UserResponse();
    static hstring HasInvitees();
    static hstring IsCanceledMeeting();
    static hstring IsOrganizedByUser();
    static hstring Recurrence();
    static hstring Uri();
    static hstring Invitees();
    static Windows::Foundation::Collections::IVector<hstring> DefaultProperties();
    static hstring ChangeNumber();
    static hstring RemoteChangeNumber();
    static hstring DetailsKind();
};

struct WINRT_EBO AppointmentRecurrence :
    Windows::ApplicationModel::Appointments::IAppointmentRecurrence,
    impl::require<AppointmentRecurrence, Windows::ApplicationModel::Appointments::IAppointmentRecurrence2, Windows::ApplicationModel::Appointments::IAppointmentRecurrence3>
{
    AppointmentRecurrence(std::nullptr_t) noexcept {}
    AppointmentRecurrence();
};

struct WINRT_EBO AppointmentStore :
    Windows::ApplicationModel::Appointments::IAppointmentStore,
    impl::require<AppointmentStore, Windows::ApplicationModel::Appointments::IAppointmentStore2>
{
    AppointmentStore(std::nullptr_t) noexcept {}
    using impl_IAppointmentStore::CreateAppointmentCalendarAsync;
    using impl_IAppointmentStore2::CreateAppointmentCalendarAsync;
};

struct WINRT_EBO AppointmentStoreChange :
    Windows::ApplicationModel::Appointments::IAppointmentStoreChange,
    impl::require<AppointmentStoreChange, Windows::ApplicationModel::Appointments::IAppointmentStoreChange2>
{
    AppointmentStoreChange(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppointmentStoreChangeReader :
    Windows::ApplicationModel::Appointments::IAppointmentStoreChangeReader
{
    AppointmentStoreChangeReader(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppointmentStoreChangeTracker :
    Windows::ApplicationModel::Appointments::IAppointmentStoreChangeTracker
{
    AppointmentStoreChangeTracker(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppointmentStoreChangedDeferral :
    Windows::ApplicationModel::Appointments::IAppointmentStoreChangedDeferral
{
    AppointmentStoreChangedDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppointmentStoreChangedEventArgs :
    Windows::ApplicationModel::Appointments::IAppointmentStoreChangedEventArgs
{
    AppointmentStoreChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppointmentStoreNotificationTriggerDetails :
    Windows::ApplicationModel::Appointments::IAppointmentStoreNotificationTriggerDetails
{
    AppointmentStoreNotificationTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FindAppointmentsOptions :
    Windows::ApplicationModel::Appointments::IFindAppointmentsOptions
{
    FindAppointmentsOptions(std::nullptr_t) noexcept {}
    FindAppointmentsOptions();
};

}

}
