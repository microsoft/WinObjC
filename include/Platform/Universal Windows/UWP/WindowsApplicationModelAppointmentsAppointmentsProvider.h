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

// WindowsApplicationModelAppointmentsAppointmentsProvider.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAAAAppointmentsProviderLaunchActionVerbs, WAAAAddAppointmentOperation, WAAAReplaceAppointmentOperation, WAAARemoveAppointmentOperation;
@protocol WAAAIAppointmentsProviderLaunchActionVerbsStatics, WAAAIAppointmentsProviderLaunchActionVerbsStatics2, WAAAIAddAppointmentOperation, WAAAIReplaceAppointmentOperation, WAAAIRemoveAppointmentOperation;

#include "WindowsApplicationModelAppointments.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Appointments.AppointmentsProvider.AppointmentsProviderLaunchActionVerbs
#ifndef __WAAAAppointmentsProviderLaunchActionVerbs_DEFINED__
#define __WAAAAppointmentsProviderLaunchActionVerbs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAAAppointmentsProviderLaunchActionVerbs : RTObject
+ (NSString *)addAppointment;
+ (NSString *)removeAppointment;
+ (NSString *)replaceAppointment;
+ (NSString *)showTimeFrame;
+ (NSString *)showAppointmentDetails;
@end

#endif // __WAAAAppointmentsProviderLaunchActionVerbs_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentsProvider.AddAppointmentOperation
#ifndef __WAAAAddAppointmentOperation_DEFINED__
#define __WAAAAddAppointmentOperation_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAAAddAppointmentOperation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAAppointment* appointmentInformation;
@property (readonly) NSString * sourcePackageFamilyName;
- (void)reportCompleted:(NSString *)itemId;
- (void)reportCanceled;
- (void)reportError:(NSString *)value;
- (void)dismissUI;
@end

#endif // __WAAAAddAppointmentOperation_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentsProvider.ReplaceAppointmentOperation
#ifndef __WAAAReplaceAppointmentOperation_DEFINED__
#define __WAAAReplaceAppointmentOperation_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAAReplaceAppointmentOperation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appointmentId;
@property (readonly) WAAAppointment* appointmentInformation;
@property (readonly) id /* WFDateTime* */ instanceStartDate;
@property (readonly) NSString * sourcePackageFamilyName;
- (void)reportCompleted:(NSString *)itemId;
- (void)reportCanceled;
- (void)reportError:(NSString *)value;
- (void)dismissUI;
@end

#endif // __WAAAReplaceAppointmentOperation_DEFINED__

// Windows.ApplicationModel.Appointments.AppointmentsProvider.RemoveAppointmentOperation
#ifndef __WAAARemoveAppointmentOperation_DEFINED__
#define __WAAARemoveAppointmentOperation_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAARemoveAppointmentOperation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appointmentId;
@property (readonly) id /* WFDateTime* */ instanceStartDate;
@property (readonly) NSString * sourcePackageFamilyName;
- (void)reportCompleted;
- (void)reportCanceled;
- (void)reportError:(NSString *)value;
- (void)dismissUI;
@end

#endif // __WAAARemoveAppointmentOperation_DEFINED__

