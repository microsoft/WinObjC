//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// WindowsApplicationModelAppointmentsDataProvider.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELAPPOINTMENTSDATAPROVIDEREXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELAPPOINTMENTSDATAPROVIDEREXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelAppointmentsDataProvider.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAADAppointmentDataProviderConnection, WAADAppointmentCalendarSyncManagerSyncRequestEventArgs, WAADAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs, WAADAppointmentCalendarCancelMeetingRequestEventArgs, WAADAppointmentCalendarForwardMeetingRequestEventArgs, WAADAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs, WAADAppointmentCalendarUpdateMeetingResponseRequestEventArgs, WAADAppointmentDataProviderTriggerDetails, WAADAppointmentCalendarSyncManagerSyncRequest, WAADAppointmentCalendarCreateOrUpdateAppointmentRequest, WAADAppointmentCalendarCancelMeetingRequest, WAADAppointmentCalendarForwardMeetingRequest, WAADAppointmentCalendarProposeNewTimeForMeetingRequest, WAADAppointmentCalendarUpdateMeetingResponseRequest;
@protocol WAADIAppointmentDataProviderTriggerDetails, WAADIAppointmentDataProviderConnection, WAADIAppointmentCalendarSyncManagerSyncRequest, WAADIAppointmentCalendarCreateOrUpdateAppointmentRequest, WAADIAppointmentCalendarCancelMeetingRequest, WAADIAppointmentCalendarForwardMeetingRequest, WAADIAppointmentCalendarProposeNewTimeForMeetingRequest, WAADIAppointmentCalendarUpdateMeetingResponseRequest, WAADIAppointmentCalendarSyncManagerSyncRequestEventArgs, WAADIAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs, WAADIAppointmentCalendarCancelMeetingRequestEventArgs, WAADIAppointmentCalendarForwardMeetingRequestEventArgs, WAADIAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs, WAADIAppointmentCalendarUpdateMeetingResponseRequestEventArgs;

#include "WindowsFoundation.h"
#include "WindowsApplicationModelAppointments.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Appointments.DataProvider.AppointmentDataProviderConnection
#ifndef __WAADAppointmentDataProviderConnection_DEFINED__
#define __WAADAppointmentDataProviderConnection_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPOINTMENTSDATAPROVIDEREXPORT
@interface WAADAppointmentDataProviderConnection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addCancelMeetingRequestedEvent:(void(^)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarCancelMeetingRequestEventArgs*))del;
- (void)removeCancelMeetingRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCreateOrUpdateAppointmentRequestedEvent:(void(^)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs*))del;
- (void)removeCreateOrUpdateAppointmentRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addForwardMeetingRequestedEvent:(void(^)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarForwardMeetingRequestEventArgs*))del;
- (void)removeForwardMeetingRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addProposeNewTimeForMeetingRequestedEvent:(void(^)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs*))del;
- (void)removeProposeNewTimeForMeetingRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSyncRequestedEvent:(void(^)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarSyncManagerSyncRequestEventArgs*))del;
- (void)removeSyncRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUpdateMeetingResponseRequestedEvent:(void(^)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarUpdateMeetingResponseRequestEventArgs*))del;
- (void)removeUpdateMeetingResponseRequestedEvent:(EventRegistrationToken)tok;
- (void)start;
@end

#endif // __WAADAppointmentDataProviderConnection_DEFINED__

// Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarSyncManagerSyncRequestEventArgs
#ifndef __WAADAppointmentCalendarSyncManagerSyncRequestEventArgs_DEFINED__
#define __WAADAppointmentCalendarSyncManagerSyncRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPOINTMENTSDATAPROVIDEREXPORT
@interface WAADAppointmentCalendarSyncManagerSyncRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAADAppointmentCalendarSyncManagerSyncRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAADAppointmentCalendarSyncManagerSyncRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs
#ifndef __WAADAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs_DEFINED__
#define __WAADAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPOINTMENTSDATAPROVIDEREXPORT
@interface WAADAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAADAppointmentCalendarCreateOrUpdateAppointmentRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAADAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarCancelMeetingRequestEventArgs
#ifndef __WAADAppointmentCalendarCancelMeetingRequestEventArgs_DEFINED__
#define __WAADAppointmentCalendarCancelMeetingRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPOINTMENTSDATAPROVIDEREXPORT
@interface WAADAppointmentCalendarCancelMeetingRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAADAppointmentCalendarCancelMeetingRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAADAppointmentCalendarCancelMeetingRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarForwardMeetingRequestEventArgs
#ifndef __WAADAppointmentCalendarForwardMeetingRequestEventArgs_DEFINED__
#define __WAADAppointmentCalendarForwardMeetingRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPOINTMENTSDATAPROVIDEREXPORT
@interface WAADAppointmentCalendarForwardMeetingRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAADAppointmentCalendarForwardMeetingRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAADAppointmentCalendarForwardMeetingRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarProposeNewTimeForMeetingRequestEventArgs
#ifndef __WAADAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs_DEFINED__
#define __WAADAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPOINTMENTSDATAPROVIDEREXPORT
@interface WAADAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAADAppointmentCalendarProposeNewTimeForMeetingRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAADAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarUpdateMeetingResponseRequestEventArgs
#ifndef __WAADAppointmentCalendarUpdateMeetingResponseRequestEventArgs_DEFINED__
#define __WAADAppointmentCalendarUpdateMeetingResponseRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPOINTMENTSDATAPROVIDEREXPORT
@interface WAADAppointmentCalendarUpdateMeetingResponseRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAADAppointmentCalendarUpdateMeetingResponseRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAADAppointmentCalendarUpdateMeetingResponseRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Appointments.DataProvider.AppointmentDataProviderTriggerDetails
#ifndef __WAADAppointmentDataProviderTriggerDetails_DEFINED__
#define __WAADAppointmentDataProviderTriggerDetails_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPOINTMENTSDATAPROVIDEREXPORT
@interface WAADAppointmentDataProviderTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAADAppointmentDataProviderConnection* connection;
@end

#endif // __WAADAppointmentDataProviderTriggerDetails_DEFINED__

// Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarSyncManagerSyncRequest
#ifndef __WAADAppointmentCalendarSyncManagerSyncRequest_DEFINED__
#define __WAADAppointmentCalendarSyncManagerSyncRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPOINTMENTSDATAPROVIDEREXPORT
@interface WAADAppointmentCalendarSyncManagerSyncRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appointmentCalendarLocalId;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAADAppointmentCalendarSyncManagerSyncRequest_DEFINED__

// Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarCreateOrUpdateAppointmentRequest
#ifndef __WAADAppointmentCalendarCreateOrUpdateAppointmentRequest_DEFINED__
#define __WAADAppointmentCalendarCreateOrUpdateAppointmentRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPOINTMENTSDATAPROVIDEREXPORT
@interface WAADAppointmentCalendarCreateOrUpdateAppointmentRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAAppointment* appointment;
@property (readonly) NSString * appointmentCalendarLocalId;
@property (readonly) NSArray* /* NSString * */ changedProperties;
@property (readonly) BOOL notifyInvitees;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync:(WAAAppointment*)createdOrUpdatedAppointment;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAADAppointmentCalendarCreateOrUpdateAppointmentRequest_DEFINED__

// Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarCancelMeetingRequest
#ifndef __WAADAppointmentCalendarCancelMeetingRequest_DEFINED__
#define __WAADAppointmentCalendarCancelMeetingRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPOINTMENTSDATAPROVIDEREXPORT
@interface WAADAppointmentCalendarCancelMeetingRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appointmentCalendarLocalId;
@property (readonly) NSString * appointmentLocalId;
@property (readonly) id /* WFDateTime* */ appointmentOriginalStartTime;
@property (readonly) NSString * comment;
@property (readonly) BOOL notifyInvitees;
@property (readonly) NSString * subject;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAADAppointmentCalendarCancelMeetingRequest_DEFINED__

// Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarForwardMeetingRequest
#ifndef __WAADAppointmentCalendarForwardMeetingRequest_DEFINED__
#define __WAADAppointmentCalendarForwardMeetingRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPOINTMENTSDATAPROVIDEREXPORT
@interface WAADAppointmentCalendarForwardMeetingRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appointmentCalendarLocalId;
@property (readonly) NSString * appointmentLocalId;
@property (readonly) id /* WFDateTime* */ appointmentOriginalStartTime;
@property (readonly) NSString * comment;
@property (readonly) NSString * forwardHeader;
@property (readonly) NSArray* /* WAAAppointmentInvitee* */ invitees;
@property (readonly) NSString * subject;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAADAppointmentCalendarForwardMeetingRequest_DEFINED__

// Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarProposeNewTimeForMeetingRequest
#ifndef __WAADAppointmentCalendarProposeNewTimeForMeetingRequest_DEFINED__
#define __WAADAppointmentCalendarProposeNewTimeForMeetingRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPOINTMENTSDATAPROVIDEREXPORT
@interface WAADAppointmentCalendarProposeNewTimeForMeetingRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appointmentCalendarLocalId;
@property (readonly) NSString * appointmentLocalId;
@property (readonly) id /* WFDateTime* */ appointmentOriginalStartTime;
@property (readonly) NSString * comment;
@property (readonly) WFTimeSpan* newDuration __attribute__ ((ns_returns_not_retained));
@property (readonly) WFDateTime* newStartTime __attribute__ ((ns_returns_not_retained));
@property (readonly) NSString * subject;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAADAppointmentCalendarProposeNewTimeForMeetingRequest_DEFINED__

// Windows.ApplicationModel.Appointments.DataProvider.AppointmentCalendarUpdateMeetingResponseRequest
#ifndef __WAADAppointmentCalendarUpdateMeetingResponseRequest_DEFINED__
#define __WAADAppointmentCalendarUpdateMeetingResponseRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPOINTMENTSDATAPROVIDEREXPORT
@interface WAADAppointmentCalendarUpdateMeetingResponseRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appointmentCalendarLocalId;
@property (readonly) NSString * appointmentLocalId;
@property (readonly) id /* WFDateTime* */ appointmentOriginalStartTime;
@property (readonly) NSString * comment;
@property (readonly) WAAAppointmentParticipantResponse response;
@property (readonly) BOOL sendUpdate;
@property (readonly) NSString * subject;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAADAppointmentCalendarUpdateMeetingResponseRequest_DEFINED__

