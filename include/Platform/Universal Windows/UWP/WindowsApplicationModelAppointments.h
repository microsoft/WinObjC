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
@class WAAAppointment, WAAAppointmentStore, WAAAppointmentOrganizer, WAAAppointmentInvitee, WAAAppointmentRecurrence, WAAAppointmentManager,
    WAAFindAppointmentsOptions, WAAAppointmentException, WAAAppointmentCalendarSyncManager, WAAAppointmentCalendar,
    WAAAppointmentStoreChange, WAAAppointmentStoreChangeReader, WAAAppointmentStoreChangedDeferral, WAAAppointmentStoreChangeTracker,
    WAAAppointmentConflictResult, WAAAppointmentStoreChangedEventArgs, WAAAppointmentProperties,
    WAAAppointmentStoreNotificationTriggerDetails;
@protocol WAAIAppointmentManagerStatics
, WAAIAppointmentManagerStatics2, WAAIAppointmentParticipant, WAAIAppointmentInvitee, WAAIAppointmentRecurrence, WAAIAppointmentRecurrence2,
    WAAIAppointmentRecurrence3, WAAIAppointment, WAAIAppointment2, WAAIAppointment3, WAAIFindAppointmentsOptions, WAAIAppointmentCalendar,
    WAAIAppointmentCalendar2, WAAIAppointmentCalendarSyncManager, WAAIAppointmentPropertiesStatics, WAAIAppointmentPropertiesStatics2,
    WAAIAppointmentConflictResult, WAAIAppointmentStoreChange, WAAIAppointmentStoreChange2, WAAIAppointmentStoreChangeReader,
    WAAIAppointmentStoreChangeTracker, WAAIAppointmentStoreChangedEventArgs, WAAIAppointmentStoreChangedDeferral,
    WAAIAppointmentStoreNotificationTriggerDetails, WAAIAppointmentStore, WAAIAppointmentStore2, WAAIAppointmentException;

// Windows.ApplicationModel.Appointments.AppointmentStoreAccessType
enum _WAAAppointmentStoreAccessType {
    WAAAppointmentStoreAccessTypeAppCalendarsReadWrite = 0,
    WAAAppointmentStoreAccessTypeAllCalendarsReadOnly = 1,
    WAAAppointmentStoreAccessTypeAllCalendarsReadWrite = 2,
};
typedef unsigned WAAAppointmentStoreAccessType;

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

// Windows.ApplicationModel.Appointments.AppointmentCalendarSyncStatus
enum _WAAAppointmentCalendarSyncStatus {
    WAAAppointmentCalendarSyncStatusIdle = 0,
    WAAAppointmentCalendarSyncStatusSyncing = 1,
    WAAAppointmentCalendarSyncStatusUpToDate = 2,
    WAAAppointmentCalendarSyncStatusAuthenticationError = 3,
    WAAAppointmentCalendarSyncStatusPolicyError = 4,
    WAAAppointmentCalendarSyncStatusUnknownError = 5,
};
typedef unsigned WAAAppointmentCalendarSyncStatus;

// Windows.ApplicationModel.Appointments.RecurrenceType
enum _WAARecurrenceType {
    WAARecurrenceTypeMaster = 0,
    WAARecurrenceTypeInstance = 1,
    WAARecurrenceTypeExceptionInstance = 2,
};
typedef unsigned WAARecurrenceType;

// Windows.ApplicationModel.Appointments.AppointmentDetailsKind
enum _WAAAppointmentDetailsKind {
    WAAAppointmentDetailsKindPlainText = 0,
    WAAAppointmentDetailsKindHtml = 1,
};
typedef unsigned WAAAppointmentDetailsKind;

// Windows.ApplicationModel.Appointments.FindAppointmentCalendarsOptions
enum _WAAFindAppointmentCalendarsOptions {
    WAAFindAppointmentCalendarsOptionsNone = 0,
    WAAFindAppointmentCalendarsOptionsIncludeHidden = 1,
};
typedef unsigned WAAFindAppointmentCalendarsOptions;

// Windows.ApplicationModel.Appointments.AppointmentSummaryCardView
enum _WAAAppointmentSummaryCardView {
    WAAAppointmentSummaryCardViewSystem = 0,
    WAAAppointmentSummaryCardViewApp = 1,
};
typedef unsigned WAAAppointmentSummaryCardView;

// Windows.ApplicationModel.Appointments.AppointmentCalendarOtherAppReadAccess
enum _WAAAppointmentCalendarOtherAppReadAccess {
    WAAAppointmentCalendarOtherAppReadAccessSystemOnly = 0,
    WAAAppointmentCalendarOtherAppReadAccessLimited = 1,
    WAAAppointmentCalendarOtherAppReadAccessFull = 2,
};
typedef unsigned WAAAppointmentCalendarOtherAppReadAccess;

// Windows.ApplicationModel.Appointments.AppointmentCalendarOtherAppWriteAccess
enum _WAAAppointmentCalendarOtherAppWriteAccess {
    WAAAppointmentCalendarOtherAppWriteAccessNone = 0,
    WAAAppointmentCalendarOtherAppWriteAccessSystemOnly = 1,
};
typedef unsigned WAAAppointmentCalendarOtherAppWriteAccess;

// Windows.ApplicationModel.Appointments.AppointmentConflictType
enum _WAAAppointmentConflictType {
    WAAAppointmentConflictTypeNone = 0,
    WAAAppointmentConflictTypeAdjacent = 1,
    WAAAppointmentConflictTypeOverlap = 2,
};
typedef unsigned WAAAppointmentConflictType;

// Windows.ApplicationModel.Appointments.AppointmentStoreChangeType
enum _WAAAppointmentStoreChangeType {
    WAAAppointmentStoreChangeTypeAppointmentCreated = 0,
    WAAAppointmentStoreChangeTypeAppointmentModified = 1,
    WAAAppointmentStoreChangeTypeAppointmentDeleted = 2,
    WAAAppointmentStoreChangeTypeChangeTrackingLost = 3,
    WAAAppointmentStoreChangeTypeCalendarCreated = 4,
    WAAAppointmentStoreChangeTypeCalendarModified = 5,
    WAAAppointmentStoreChangeTypeCalendarDeleted = 6,
};
typedef unsigned WAAAppointmentStoreChangeType;

#include "WindowsUIPopups.h"
#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsUI.h"

#import <Foundation/Foundation.h>

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
@property (copy) NSString* location;
@property BOOL allDay;
@property (copy) WAAAppointmentOrganizer* organizer;
@property (copy) WFTimeSpan* duration;
@property (copy) NSString* details;
@property (copy) WFUri* uri;
@property WAAAppointmentBusyStatus busyStatus;
@property (copy) WAAAppointmentRecurrence* recurrence;
@property (copy) NSString* subject;
@property (copy) WFDateTime* startTime;
@property WAAAppointmentSensitivity sensitivity;
@property (copy) id reminder;
@property (readonly) NSMutableArray* invitees;
@property BOOL allowNewTimeProposal;
@property WAAAppointmentParticipantResponse userResponse;
@property (copy) NSString* roamingId;
@property (copy) id replyTime;
@property BOOL isResponseRequested;
@property BOOL isOrganizedByUser;
@property BOOL isCanceledMeeting;
@property (copy) NSString* onlineMeetingLink;
@property (readonly) BOOL hasInvitees;
@property (readonly) NSString* calendarId;
@property (readonly) NSString* localId;
@property (readonly) id originalStartTime;
@property uint64_t remoteChangeNumber;
@property WAAAppointmentDetailsKind detailsKind;
@property (readonly) uint64_t changeNumber;
@end

#endif // __WAAAppointment_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentStore
#ifndef __WAAAppointmentStore_DEFINED__
#define __WAAAppointmentStore_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentStore : RTObject
@property (readonly) WAAAppointmentStoreChangeTracker* changeTracker;
- (EventRegistrationToken)addStoreChangedEvent:(void (^)(WAAAppointmentStore*, WAAAppointmentStoreChangedEventArgs*))del;
- (void)removeStoreChangedEvent:(EventRegistrationToken)tok;
- (void)createAppointmentCalendarAsync:(NSString*)name
                               success:(void (^)(WAAAppointmentCalendar*))success
                               failure:(void (^)(NSError*))failure;
- (void)getAppointmentCalendarAsync:(NSString*)calendarId
                            success:(void (^)(WAAAppointmentCalendar*))success
                            failure:(void (^)(NSError*))failure;
- (void)getAppointmentAsync:(NSString*)localId success:(void (^)(WAAAppointment*))success failure:(void (^)(NSError*))failure;
- (void)getAppointmentInstanceAsync:(NSString*)localId
                  instanceStartTime:(WFDateTime*)instanceStartTime
                            success:(void (^)(WAAAppointment*))success
                            failure:(void (^)(NSError*))failure;
- (void)findAppointmentCalendarsAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)findAppointmentCalendarsAsyncWithOptions:(WAAFindAppointmentCalendarsOptions)options
                                         success:(void (^)(NSArray*))success
                                         failure:(void (^)(NSError*))failure;
- (void)findAppointmentsAsync:(WFDateTime*)rangeStart
                  rangeLength:(WFTimeSpan*)rangeLength
                      success:(void (^)(NSArray*))success
                      failure:(void (^)(NSError*))failure;
- (void)findAppointmentsAsyncWithOptions:(WFDateTime*)rangeStart
                             rangeLength:(WFTimeSpan*)rangeLength
                                 options:(WAAFindAppointmentsOptions*)options
                                 success:(void (^)(NSArray*))success
                                 failure:(void (^)(NSError*))failure;
- (void)findConflictAsync:(WAAAppointment*)appointment
                  success:(void (^)(WAAAppointmentConflictResult*))success
                  failure:(void (^)(NSError*))failure;
- (void)findConflictAsyncWithInstanceStart:(WAAAppointment*)appointment
                         instanceStartTime:(WFDateTime*)instanceStartTime
                                   success:(void (^)(WAAAppointmentConflictResult*))success
                                   failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)moveAppointmentAsync:(WAAAppointment*)appointment
                              destinationCalendar:(WAAAppointmentCalendar*)destinationCalendar;
- (void)showAddAppointmentAsync:(WAAAppointment*)appointment
                      selection:(WFRect*)selection
                        success:(void (^)(NSString*))success
                        failure:(void (^)(NSError*))failure;
- (void)showReplaceAppointmentAsync:(NSString*)localId
                        appointment:(WAAAppointment*)appointment
                          selection:(WFRect*)selection
                            success:(void (^)(NSString*))success
                            failure:(void (^)(NSError*))failure;
- (void)showReplaceAppointmentWithPlacementAndDateAsync:(NSString*)localId
                                            appointment:(WAAAppointment*)appointment
                                              selection:(WFRect*)selection
                                     preferredPlacement:(WUPPlacement)preferredPlacement
                                      instanceStartDate:(WFDateTime*)instanceStartDate
                                                success:(void (^)(NSString*))success
                                                failure:(void (^)(NSError*))failure;
- (void)showRemoveAppointmentAsync:(NSString*)localId
                         selection:(WFRect*)selection
                           success:(void (^)(BOOL))success
                           failure:(void (^)(NSError*))failure;
- (void)showRemoveAppointmentWithPlacementAndDateAsync:(NSString*)localId
                                             selection:(WFRect*)selection
                                    preferredPlacement:(WUPPlacement)preferredPlacement
                                     instanceStartDate:(WFDateTime*)instanceStartDate
                                               success:(void (^)(BOOL))success
                                               failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)showAppointmentDetailsAsync:(NSString*)localId;
- (RTObject<WFIAsyncAction>*)showAppointmentDetailsWithDateAsync:(NSString*)localId instanceStartDate:(WFDateTime*)instanceStartDate;
- (void)showEditNewAppointmentAsync:(WAAAppointment*)appointment success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
- (void)findLocalIdsFromRoamingIdAsync:(NSString*)roamingId success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)createAppointmentCalendarInAccountAsync:(NSString*)name
                              userDataAccountId:(NSString*)userDataAccountId
                                        success:(void (^)(WAAAppointmentCalendar*))success
                                        failure:(void (^)(NSError*))failure;
@end

#endif // __WAAAppointmentStore_DEFINED__

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
@property WAAAppointmentRecurrenceUnit unit;
@property (copy) id occurrences;
@property unsigned int month;
@property unsigned int interval;
@property WAAAppointmentDaysOfWeek daysOfWeek;
@property unsigned int day;
@property WAAAppointmentWeekOfMonth weekOfMonth;
@property (copy) id until;
@property (copy) NSString* timeZone;
@property (readonly) WAARecurrenceType recurrenceType;
@property (readonly) NSString* calendarIdentifier;
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
+ (RTObject<WFIAsyncAction>*)showAppointmentDetailsAsync:(NSString*)appointmentId;
+ (RTObject<WFIAsyncAction>*)showAppointmentDetailsWithDateAsync:(NSString*)appointmentId instanceStartDate:(WFDateTime*)instanceStartDate;
+ (void)showEditNewAppointmentAsync:(WAAAppointment*)appointment success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
+ (void)requestStoreAsync:(WAAAppointmentStoreAccessType)options
                  success:(void (^)(WAAAppointmentStore*))success
                  failure:(void (^)(NSError*))failure;
@end

#endif // __WAAAppointmentManager_DEFINED__

// Windows.ApplicationModel.Appointments.FindAppointmentsOptions
#ifndef __WAAFindAppointmentsOptions_DEFINED__
#define __WAAFindAppointmentsOptions_DEFINED__

WINRT_EXPORT
@interface WAAFindAppointmentsOptions : RTObject
+ (instancetype)create ACTIVATOR;
@property unsigned int maxCount;
@property BOOL includeHidden;
@property (readonly) NSMutableArray* calendarIds;
@property (readonly) NSMutableArray* fetchProperties;
@end

#endif // __WAAFindAppointmentsOptions_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentException
#ifndef __WAAAppointmentException_DEFINED__
#define __WAAAppointmentException_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentException : RTObject
@property (readonly) WAAAppointment* appointment;
@property (readonly) NSArray* exceptionProperties;
@property (readonly) BOOL isDeleted;
@end

#endif // __WAAAppointmentException_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentCalendarSyncManager
#ifndef __WAAAppointmentCalendarSyncManager_DEFINED__
#define __WAAAppointmentCalendarSyncManager_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentCalendarSyncManager : RTObject
@property (readonly) WFDateTime* lastAttemptedSyncTime;
@property (readonly) WFDateTime* lastSuccessfulSyncTime;
@property (readonly) WAAAppointmentCalendarSyncStatus status;
- (EventRegistrationToken)addSyncStatusChangedEvent:(void (^)(WAAAppointmentCalendarSyncManager*, RTObject*))del;
- (void)removeSyncStatusChangedEvent:(EventRegistrationToken)tok;
- (void)syncAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAAAppointmentCalendarSyncManager_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentCalendar
#ifndef __WAAAppointmentCalendar_DEFINED__
#define __WAAAppointmentCalendar_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentCalendar : RTObject
@property WAAAppointmentSummaryCardView summaryCardView;
@property WAAAppointmentCalendarOtherAppWriteAccess otherAppWriteAccess;
@property (copy) WUColor* displayColor;
@property BOOL isHidden;
@property (copy) NSString* displayName;
@property WAAAppointmentCalendarOtherAppReadAccess otherAppReadAccess;
@property (readonly) NSString* localId;
@property (readonly) NSString* sourceDisplayName;
@property BOOL canCancelMeetings;
@property BOOL canNotifyInvitees;
@property (copy) NSString* remoteId;
@property BOOL mustNofityInvitees;
@property BOOL canUpdateMeetingResponses;
@property BOOL canProposeNewTimeForMeetings;
@property BOOL canCreateOrUpdateAppointments;
@property BOOL canForwardMeetings;
@property (readonly) WAAAppointmentCalendarSyncManager* syncManager;
@property (readonly) NSString* userDataAccountId;
- (void)findAppointmentsAsync:(WFDateTime*)rangeStart
                  rangeLength:(WFTimeSpan*)rangeLength
                      success:(void (^)(NSArray*))success
                      failure:(void (^)(NSError*))failure;
- (void)findAppointmentsAsyncWithOptions:(WFDateTime*)rangeStart
                             rangeLength:(WFTimeSpan*)rangeLength
                                 options:(WAAFindAppointmentsOptions*)options
                                 success:(void (^)(NSArray*))success
                                 failure:(void (^)(NSError*))failure;
- (void)findExceptionsFromMasterAsync:(NSString*)masterLocalId success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)findAllInstancesAsync:(NSString*)masterLocalId
                   rangeStart:(WFDateTime*)rangeStart
                  rangeLength:(WFTimeSpan*)rangeLength
                      success:(void (^)(NSArray*))success
                      failure:(void (^)(NSError*))failure;
- (void)findAllInstancesAsyncWithOptions:(NSString*)masterLocalId
                              rangeStart:(WFDateTime*)rangeStart
                             rangeLength:(WFTimeSpan*)rangeLength
                                pOptions:(WAAFindAppointmentsOptions*)pOptions
                                 success:(void (^)(NSArray*))success
                                 failure:(void (^)(NSError*))failure;
- (void)getAppointmentAsync:(NSString*)localId success:(void (^)(WAAAppointment*))success failure:(void (^)(NSError*))failure;
- (void)getAppointmentInstanceAsync:(NSString*)localId
                  instanceStartTime:(WFDateTime*)instanceStartTime
                            success:(void (^)(WAAAppointment*))success
                            failure:(void (^)(NSError*))failure;
- (void)findUnexpandedAppointmentsAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)findUnexpandedAppointmentsAsyncWithOptions:(WAAFindAppointmentsOptions*)options
                                           success:(void (^)(NSArray*))success
                                           failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)deleteAsync;
- (RTObject<WFIAsyncAction>*)saveAsync;
- (RTObject<WFIAsyncAction>*)deleteAppointmentAsync:(NSString*)localId;
- (RTObject<WFIAsyncAction>*)deleteAppointmentInstanceAsync:(NSString*)localId instanceStartTime:(WFDateTime*)instanceStartTime;
- (RTObject<WFIAsyncAction>*)saveAppointmentAsync:(WAAAppointment*)pAppointment;
- (void)tryCreateOrUpdateAppointmentAsync:(WAAAppointment*)appointment
                           notifyInvitees:(BOOL)notifyInvitees
                                  success:(void (^)(BOOL))success
                                  failure:(void (^)(NSError*))failure;
- (void)tryCancelMeetingAsync:(WAAAppointment*)meeting
                      subject:(NSString*)subject
                      comment:(NSString*)comment
               notifyInvitees:(BOOL)notifyInvitees
                      success:(void (^)(BOOL))success
                      failure:(void (^)(NSError*))failure;
- (void)tryForwardMeetingAsync:(WAAAppointment*)meeting
                      invitees:(id<NSFastEnumeration> /* WAAAppointmentInvitee* */)invitees
                       subject:(NSString*)subject
                 forwardHeader:(NSString*)forwardHeader
                       comment:(NSString*)comment
                       success:(void (^)(BOOL))success
                       failure:(void (^)(NSError*))failure;
- (void)tryProposeNewTimeForMeetingAsync:(WAAAppointment*)meeting
                            newStartTime:(WFDateTime*)newStartTime
                             newDuration:(WFTimeSpan*)newDuration
                                 subject:(NSString*)subject
                                 comment:(NSString*)comment
                                 success:(void (^)(BOOL))success
                                 failure:(void (^)(NSError*))failure;
- (void)tryUpdateMeetingResponseAsync:(WAAAppointment*)meeting
                             response:(WAAAppointmentParticipantResponse)response
                              subject:(NSString*)subject
                              comment:(NSString*)comment
                           sendUpdate:(BOOL)sendUpdate
                              success:(void (^)(BOOL))success
                              failure:(void (^)(NSError*))failure;
@end

#endif // __WAAAppointmentCalendar_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentStoreChange
#ifndef __WAAAppointmentStoreChange_DEFINED__
#define __WAAAppointmentStoreChange_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentStoreChange : RTObject
@property (readonly) WAAAppointment* appointment;
@property (readonly) WAAAppointmentStoreChangeType changeType;
@property (readonly) WAAAppointmentCalendar* appointmentCalendar;
@end

#endif // __WAAAppointmentStoreChange_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentStoreChangeReader
#ifndef __WAAAppointmentStoreChangeReader_DEFINED__
#define __WAAAppointmentStoreChangeReader_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentStoreChangeReader : RTObject
- (void)readBatchAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)acceptChanges;
- (void)acceptChangesThrough:(WAAAppointmentStoreChange*)lastChangeToAccept;
@end

#endif // __WAAAppointmentStoreChangeReader_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentStoreChangedDeferral
#ifndef __WAAAppointmentStoreChangedDeferral_DEFINED__
#define __WAAAppointmentStoreChangedDeferral_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentStoreChangedDeferral : RTObject
- (void)complete;
@end

#endif // __WAAAppointmentStoreChangedDeferral_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentStoreChangeTracker
#ifndef __WAAAppointmentStoreChangeTracker_DEFINED__
#define __WAAAppointmentStoreChangeTracker_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentStoreChangeTracker : RTObject
- (WAAAppointmentStoreChangeReader*)getChangeReader;
- (void)enable;
- (void)reset;
@end

#endif // __WAAAppointmentStoreChangeTracker_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentConflictResult
#ifndef __WAAAppointmentConflictResult_DEFINED__
#define __WAAAppointmentConflictResult_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentConflictResult : RTObject
@property (readonly) WFDateTime* date;
@property (readonly) WAAAppointmentConflictType type;
@end

#endif // __WAAAppointmentConflictResult_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentStoreChangedEventArgs
#ifndef __WAAAppointmentStoreChangedEventArgs_DEFINED__
#define __WAAAppointmentStoreChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentStoreChangedEventArgs : RTObject
- (WAAAppointmentStoreChangedDeferral*)getDeferral;
@end

#endif // __WAAAppointmentStoreChangedEventArgs_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentProperties
#ifndef __WAAAppointmentProperties_DEFINED__
#define __WAAAppointmentProperties_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentProperties : RTObject
+ (NSString*)hasInvitees;
+ (NSString*)allDay;
+ (NSString*)allowNewTimeProposal;
+ (NSString*)busyStatus;
+ (NSMutableArray*)defaultProperties;
+ (NSString*)details;
+ (NSString*)duration;
+ (NSString*)recurrence;
+ (NSString*)invitees;
+ (NSString*)isCanceledMeeting;
+ (NSString*)isOrganizedByUser;
+ (NSString*)isResponseRequested;
+ (NSString*)location;
+ (NSString*)onlineMeetingLink;
+ (NSString*)organizer;
+ (NSString*)originalStartTime;
+ (NSString*)reminder;
+ (NSString*)replyTime;
+ (NSString*)sensitivity;
+ (NSString*)startTime;
+ (NSString*)subject;
+ (NSString*)uri;
+ (NSString*)userResponse;
+ (NSString*)detailsKind;
+ (NSString*)remoteChangeNumber;
+ (NSString*)changeNumber;
@end

#endif // __WAAAppointmentProperties_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentStoreNotificationTriggerDetails
#ifndef __WAAAppointmentStoreNotificationTriggerDetails_DEFINED__
#define __WAAAppointmentStoreNotificationTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentStoreNotificationTriggerDetails : RTObject
@end

#endif // __WAAAppointmentStoreNotificationTriggerDetails_DEFINED__
