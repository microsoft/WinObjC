//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// WindowsApplicationModelAppointments.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WAAAppointment, WAAAppointmentOrganizer, WAAAppointmentInvitee, WAAAppointmentRecurrence, WAAAppointmentManager;
@protocol WAAIAppointmentManagerStatics
, WAAIAppointmentParticipant, WAAIAppointmentInvitee, WAAIAppointmentRecurrence, WAAIAppointment;

// Windows.ApplicationModel.Appointments.AppointmentSensitivity
enum _WAAAppointmentSensitivity {
    WAAAppointmentSensitivityPublic = 0,
    WAAAppointmentSensitivityPrivate = 1,
};
typedef unsigned WAAAppointmentSensitivity;

// Windows.ApplicationModel.Appointments.AppointmentBusyStatus
enum _WAAAppointmentBusyStatus {
    WAAAppointmentBusyStatusBusy = 0,
    WAAAppointmentBusyStatusTentative = 1,
    WAAAppointmentBusyStatusFree = 2,
    WAAAppointmentBusyStatusOutOfOffice = 3,
    WAAAppointmentBusyStatusWorkingElsewhere = 4,
};
typedef unsigned WAAAppointmentBusyStatus;

// Windows.ApplicationModel.Appointments.AppointmentParticipantResponse
enum _WAAAppointmentParticipantResponse {
    WAAAppointmentParticipantResponseNone = 0,
    WAAAppointmentParticipantResponseTentative = 1,
    WAAAppointmentParticipantResponseAccepted = 2,
    WAAAppointmentParticipantResponseDeclined = 3,
    WAAAppointmentParticipantResponseUnknown = 4,
};
typedef unsigned WAAAppointmentParticipantResponse;

// Windows.ApplicationModel.Appointments.AppointmentParticipantRole
enum _WAAAppointmentParticipantRole {
    WAAAppointmentParticipantRoleRequiredAttendee = 0,
    WAAAppointmentParticipantRoleOptionalAttendee = 1,
    WAAAppointmentParticipantRoleResource = 2,
};
typedef unsigned WAAAppointmentParticipantRole;

// Windows.ApplicationModel.Appointments.AppointmentRecurrenceUnit
enum _WAAAppointmentRecurrenceUnit {
    WAAAppointmentRecurrenceUnitDaily = 0,
    WAAAppointmentRecurrenceUnitWeekly = 1,
    WAAAppointmentRecurrenceUnitMonthly = 2,
    WAAAppointmentRecurrenceUnitMonthlyOnDay = 3,
    WAAAppointmentRecurrenceUnitYearly = 4,
    WAAAppointmentRecurrenceUnitYearlyOnDay = 5,
};
typedef unsigned WAAAppointmentRecurrenceUnit;

// Windows.ApplicationModel.Appointments.AppointmentDaysOfWeek
enum _WAAAppointmentDaysOfWeek {
    WAAAppointmentDaysOfWeekNone = 0,
    WAAAppointmentDaysOfWeekSunday = 1,
    WAAAppointmentDaysOfWeekMonday = 2,
    WAAAppointmentDaysOfWeekTuesday = 4,
    WAAAppointmentDaysOfWeekWednesday = 8,
    WAAAppointmentDaysOfWeekThursday = 16,
    WAAAppointmentDaysOfWeekFriday = 32,
    WAAAppointmentDaysOfWeekSaturday = 64,
};
typedef unsigned WAAAppointmentDaysOfWeek;

// Windows.ApplicationModel.Appointments.AppointmentWeekOfMonth
enum _WAAAppointmentWeekOfMonth {
    WAAAppointmentWeekOfMonthFirst = 0,
    WAAAppointmentWeekOfMonthSecond = 1,
    WAAAppointmentWeekOfMonthThird = 2,
    WAAAppointmentWeekOfMonthFourth = 3,
    WAAAppointmentWeekOfMonthLast = 4,
};
typedef unsigned WAAAppointmentWeekOfMonth;

#include "WindowsUIPopups.h"
#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"

// Windows.ApplicationModel.Appointments.IAppointmentParticipant
#ifndef __WAAIAppointmentParticipant_DEFINED__
#define __WAAIAppointmentParticipant_DEFINED__

@protocol WAAIAppointmentParticipant
@property (copy) NSString* address;
@property (copy) NSString* displayName;
@end

#endif // __WAAIAppointmentParticipant_DEFINED__

// Windows.ApplicationModel.Appointments.Appointment
#ifndef __WAAAppointment_DEFINED__
#define __WAAAppointment_DEFINED__

WINRT_EXPORT
@interface WAAAppointment : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) WFUri* uri;
@property (copy) NSString* subject;
@property (copy) WFDateTime* startTime;
@property WAAAppointmentSensitivity sensitivity;
@property (copy) WFTimeSpan* reminder;
@property (copy) WAAAppointmentRecurrence* recurrence;
@property (copy) WAAAppointmentOrganizer* organizer;
@property (copy) NSString* location;
@property (copy) WFTimeSpan* duration;
@property (copy) NSString* details;
@property WAAAppointmentBusyStatus busyStatus;
@property BOOL allDay;
@property (readonly) id<NSFastEnumeration> /*WAAAppointmentInvitee*/ invitees;
@end

#endif // __WAAAppointment_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentOrganizer
#ifndef __WAAAppointmentOrganizer_DEFINED__
#define __WAAAppointmentOrganizer_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentOrganizer : RTObject <WAAIAppointmentParticipant>
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* displayName;
@property (copy) NSString* address;
@end

#endif // __WAAAppointmentOrganizer_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentInvitee
#ifndef __WAAAppointmentInvitee_DEFINED__
#define __WAAAppointmentInvitee_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentInvitee : RTObject <WAAIAppointmentParticipant>
+ (instancetype)create ACTIVATOR;
@property WAAAppointmentParticipantRole role;
@property WAAAppointmentParticipantResponse response;
@property (copy) NSString* displayName;
@property (copy) NSString* address;
@end

#endif // __WAAAppointmentInvitee_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentRecurrence
#ifndef __WAAAppointmentRecurrence_DEFINED__
#define __WAAAppointmentRecurrence_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentRecurrence : RTObject
+ (instancetype)create ACTIVATOR;
@property WAAAppointmentWeekOfMonth weekOfMonth;
@property (copy) WFDateTime* until;
@property WAAAppointmentRecurrenceUnit unit;
@property (copy) NSNumber* occurrences;
@property unsigned month;
@property unsigned interval;
@property WAAAppointmentDaysOfWeek daysOfWeek;
@property unsigned day;
@end

#endif // __WAAAppointmentRecurrence_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentManager
#ifndef __WAAAppointmentManager_DEFINED__
#define __WAAAppointmentManager_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentManager : RTObject
+ (void)showAddAppointmentAsync:(WAAAppointment*)appointment
                      selection:(WFRect*)selection
                        success:(void (^)(NSString*))success
                        failure:(void (^)(NSError*))failure;
+ (void)showAddAppointmentWithPlacementAsync:(WAAAppointment*)appointment
                                   selection:(WFRect*)selection
                          preferredPlacement:(WUPPlacement)preferredPlacement
                                     success:(void (^)(NSString*))success
                                     failure:(void (^)(NSError*))failure;
+ (void)showReplaceAppointmentAsync:(NSString*)appointmentId
                        appointment:(WAAAppointment*)appointment
                          selection:(WFRect*)selection
                            success:(void (^)(NSString*))success
                            failure:(void (^)(NSError*))failure;
+ (void)showReplaceAppointmentWithPlacementAsync:(NSString*)appointmentId
                                     appointment:(WAAAppointment*)appointment
                                       selection:(WFRect*)selection
                              preferredPlacement:(WUPPlacement)preferredPlacement
                                         success:(void (^)(NSString*))success
                                         failure:(void (^)(NSError*))failure;
+ (void)showReplaceAppointmentWithPlacementAndDateAsync:(NSString*)appointmentId
                                            appointment:(WAAAppointment*)appointment
                                              selection:(WFRect*)selection
                                     preferredPlacement:(WUPPlacement)preferredPlacement
                                      instanceStartDate:(WFDateTime*)instanceStartDate
                                                success:(void (^)(NSString*))success
                                                failure:(void (^)(NSError*))failure;
+ (void)showRemoveAppointmentAsync:(NSString*)appointmentId
                         selection:(WFRect*)selection
                           success:(void (^)(BOOL))success
                           failure:(void (^)(NSError*))failure;
+ (void)showRemoveAppointmentWithPlacementAsync:(NSString*)appointmentId
                                      selection:(WFRect*)selection
                             preferredPlacement:(WUPPlacement)preferredPlacement
                                        success:(void (^)(BOOL))success
                                        failure:(void (^)(NSError*))failure;
+ (void)showRemoveAppointmentWithPlacementAndDateAsync:(NSString*)appointmentId
                                             selection:(WFRect*)selection
                                    preferredPlacement:(WUPPlacement)preferredPlacement
                                     instanceStartDate:(WFDateTime*)instanceStartDate
                                               success:(void (^)(BOOL))success
                                               failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)showTimeFrameAsync:(WFDateTime*)timeToShow duration:(WFTimeSpan*)duration;
@end

#endif // __WAAAppointmentManager_DEFINED__
