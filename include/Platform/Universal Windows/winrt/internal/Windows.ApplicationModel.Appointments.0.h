// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Appointments {

struct IAppointment;
struct IAppointment2;
struct IAppointment3;
struct IAppointmentCalendar;
struct IAppointmentCalendar2;
struct IAppointmentCalendar3;
struct IAppointmentCalendarSyncManager;
struct IAppointmentCalendarSyncManager2;
struct IAppointmentConflictResult;
struct IAppointmentException;
struct IAppointmentInvitee;
struct IAppointmentManagerForUser;
struct IAppointmentManagerStatics;
struct IAppointmentManagerStatics2;
struct IAppointmentManagerStatics3;
struct IAppointmentParticipant;
struct IAppointmentPropertiesStatics;
struct IAppointmentPropertiesStatics2;
struct IAppointmentRecurrence;
struct IAppointmentRecurrence2;
struct IAppointmentRecurrence3;
struct IAppointmentStore;
struct IAppointmentStore2;
struct IAppointmentStoreChange;
struct IAppointmentStoreChange2;
struct IAppointmentStoreChangeReader;
struct IAppointmentStoreChangeTracker;
struct IAppointmentStoreChangedDeferral;
struct IAppointmentStoreChangedEventArgs;
struct IAppointmentStoreNotificationTriggerDetails;
struct IFindAppointmentsOptions;
struct Appointment;
struct AppointmentCalendar;
struct AppointmentCalendarSyncManager;
struct AppointmentConflictResult;
struct AppointmentException;
struct AppointmentInvitee;
struct AppointmentManagerForUser;
struct AppointmentOrganizer;
struct AppointmentRecurrence;
struct AppointmentStore;
struct AppointmentStoreChange;
struct AppointmentStoreChangeReader;
struct AppointmentStoreChangeTracker;
struct AppointmentStoreChangedDeferral;
struct AppointmentStoreChangedEventArgs;
struct AppointmentStoreNotificationTriggerDetails;
struct FindAppointmentsOptions;

}

namespace Windows::ApplicationModel::Appointments {

struct IAppointment;
struct IAppointment2;
struct IAppointment3;
struct IAppointmentCalendar;
struct IAppointmentCalendar2;
struct IAppointmentCalendar3;
struct IAppointmentCalendarSyncManager;
struct IAppointmentCalendarSyncManager2;
struct IAppointmentConflictResult;
struct IAppointmentException;
struct IAppointmentInvitee;
struct IAppointmentManagerForUser;
struct IAppointmentManagerStatics;
struct IAppointmentManagerStatics2;
struct IAppointmentManagerStatics3;
struct IAppointmentParticipant;
struct IAppointmentPropertiesStatics;
struct IAppointmentPropertiesStatics2;
struct IAppointmentRecurrence;
struct IAppointmentRecurrence2;
struct IAppointmentRecurrence3;
struct IAppointmentStore;
struct IAppointmentStore2;
struct IAppointmentStoreChange;
struct IAppointmentStoreChange2;
struct IAppointmentStoreChangeReader;
struct IAppointmentStoreChangeTracker;
struct IAppointmentStoreChangedDeferral;
struct IAppointmentStoreChangedEventArgs;
struct IAppointmentStoreNotificationTriggerDetails;
struct IFindAppointmentsOptions;
struct Appointment;
struct AppointmentCalendar;
struct AppointmentCalendarSyncManager;
struct AppointmentConflictResult;
struct AppointmentException;
struct AppointmentInvitee;
struct AppointmentManager;
struct AppointmentManagerForUser;
struct AppointmentOrganizer;
struct AppointmentProperties;
struct AppointmentRecurrence;
struct AppointmentStore;
struct AppointmentStoreChange;
struct AppointmentStoreChangeReader;
struct AppointmentStoreChangeTracker;
struct AppointmentStoreChangedDeferral;
struct AppointmentStoreChangedEventArgs;
struct AppointmentStoreNotificationTriggerDetails;
struct FindAppointmentsOptions;

}

namespace Windows::ApplicationModel::Appointments {

template <typename T> struct impl_IAppointment;
template <typename T> struct impl_IAppointment2;
template <typename T> struct impl_IAppointment3;
template <typename T> struct impl_IAppointmentCalendar;
template <typename T> struct impl_IAppointmentCalendar2;
template <typename T> struct impl_IAppointmentCalendar3;
template <typename T> struct impl_IAppointmentCalendarSyncManager;
template <typename T> struct impl_IAppointmentCalendarSyncManager2;
template <typename T> struct impl_IAppointmentConflictResult;
template <typename T> struct impl_IAppointmentException;
template <typename T> struct impl_IAppointmentInvitee;
template <typename T> struct impl_IAppointmentManagerForUser;
template <typename T> struct impl_IAppointmentManagerStatics;
template <typename T> struct impl_IAppointmentManagerStatics2;
template <typename T> struct impl_IAppointmentManagerStatics3;
template <typename T> struct impl_IAppointmentParticipant;
template <typename T> struct impl_IAppointmentPropertiesStatics;
template <typename T> struct impl_IAppointmentPropertiesStatics2;
template <typename T> struct impl_IAppointmentRecurrence;
template <typename T> struct impl_IAppointmentRecurrence2;
template <typename T> struct impl_IAppointmentRecurrence3;
template <typename T> struct impl_IAppointmentStore;
template <typename T> struct impl_IAppointmentStore2;
template <typename T> struct impl_IAppointmentStoreChange;
template <typename T> struct impl_IAppointmentStoreChange2;
template <typename T> struct impl_IAppointmentStoreChangeReader;
template <typename T> struct impl_IAppointmentStoreChangeTracker;
template <typename T> struct impl_IAppointmentStoreChangedDeferral;
template <typename T> struct impl_IAppointmentStoreChangedEventArgs;
template <typename T> struct impl_IAppointmentStoreNotificationTriggerDetails;
template <typename T> struct impl_IFindAppointmentsOptions;

}

namespace Windows::ApplicationModel::Appointments {

enum class AppointmentBusyStatus
{
    Busy = 0,
    Tentative = 1,
    Free = 2,
    OutOfOffice = 3,
    WorkingElsewhere = 4,
};

enum class AppointmentCalendarOtherAppReadAccess
{
    SystemOnly = 0,
    Limited = 1,
    Full = 2,
    None = 3,
};

enum class AppointmentCalendarOtherAppWriteAccess
{
    None = 0,
    SystemOnly = 1,
    Limited = 2,
};

enum class AppointmentCalendarSyncStatus
{
    Idle = 0,
    Syncing = 1,
    UpToDate = 2,
    AuthenticationError = 3,
    PolicyError = 4,
    UnknownError = 5,
    ManualAccountRemovalRequired = 6,
};

enum class AppointmentConflictType
{
    None = 0,
    Adjacent = 1,
    Overlap = 2,
};

enum class AppointmentDaysOfWeek : unsigned
{
    None = 0x0,
    Sunday = 0x1,
    Monday = 0x2,
    Tuesday = 0x4,
    Wednesday = 0x8,
    Thursday = 0x10,
    Friday = 0x20,
    Saturday = 0x40,
};

DEFINE_ENUM_FLAG_OPERATORS(AppointmentDaysOfWeek)

enum class AppointmentDetailsKind
{
    PlainText = 0,
    Html = 1,
};

enum class AppointmentParticipantResponse
{
    None = 0,
    Tentative = 1,
    Accepted = 2,
    Declined = 3,
    Unknown = 4,
};

enum class AppointmentParticipantRole
{
    RequiredAttendee = 0,
    OptionalAttendee = 1,
    Resource = 2,
};

enum class AppointmentRecurrenceUnit
{
    Daily = 0,
    Weekly = 1,
    Monthly = 2,
    MonthlyOnDay = 3,
    Yearly = 4,
    YearlyOnDay = 5,
};

enum class AppointmentSensitivity
{
    Public = 0,
    Private = 1,
};

enum class AppointmentStoreAccessType
{
    AppCalendarsReadWrite = 0,
    AllCalendarsReadOnly = 1,
    AllCalendarsReadWrite = 2,
};

enum class AppointmentStoreChangeType
{
    AppointmentCreated = 0,
    AppointmentModified = 1,
    AppointmentDeleted = 2,
    ChangeTrackingLost = 3,
    CalendarCreated = 4,
    CalendarModified = 5,
    CalendarDeleted = 6,
};

enum class AppointmentSummaryCardView
{
    System = 0,
    App = 1,
};

enum class AppointmentWeekOfMonth
{
    First = 0,
    Second = 1,
    Third = 2,
    Fourth = 3,
    Last = 4,
};

enum class FindAppointmentCalendarsOptions : unsigned
{
    None = 0x0,
    IncludeHidden = 0x1,
};

DEFINE_ENUM_FLAG_OPERATORS(FindAppointmentCalendarsOptions)

enum class RecurrenceType
{
    Master = 0,
    Instance = 1,
    ExceptionInstance = 2,
};

}

}
