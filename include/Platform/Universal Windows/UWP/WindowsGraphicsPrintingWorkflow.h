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

// WindowsGraphicsPrintingWorkflow.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
#define OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGraphicsPrintingWorkflow.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGPWPrintWorkflowBackgroundSession, WGPWPrintWorkflowBackgroundSetupRequestedEventArgs, WGPWPrintWorkflowSubmittedEventArgs, WGPWPrintWorkflowForegroundSession, WGPWPrintWorkflowForegroundSetupRequestedEventArgs, WGPWPrintWorkflowXpsDataAvailableEventArgs, WGPWPrintWorkflowConfiguration, WGPWPrintWorkflowSourceContent, WGPWPrintWorkflowSubmittedOperation, WGPWPrintWorkflowTarget, WGPWPrintWorkflowStreamTarget, WGPWPrintWorkflowObjectModelTargetPackage, WGPWPrintWorkflowSpoolStreamContent, WGPWPrintWorkflowObjectModelSourceFileContent, WGPWPrintWorkflowUIActivatedEventArgs, WGPWPrintWorkflowTriggerDetails;
@protocol WGPWIPrintWorkflowBackgroundSession, WGPWIPrintWorkflowConfiguration, WGPWIPrintWorkflowForegroundSession, WGPWIPrintWorkflowBackgroundSetupRequestedEventArgs, WGPWIPrintWorkflowForegroundSetupRequestedEventArgs, WGPWIPrintWorkflowSubmittedOperation, WGPWIPrintWorkflowSubmittedEventArgs, WGPWIPrintWorkflowTarget, WGPWIPrintWorkflowUIActivatedEventArgs, WGPWIPrintWorkflowXpsDataAvailableEventArgs, WGPWIPrintWorkflowSourceContent, WGPWIPrintWorkflowSpoolStreamContent, WGPWIPrintWorkflowObjectModelSourceFileContent, WGPWIPrintWorkflowStreamTarget, WGPWIPrintWorkflowTriggerDetails, WGPWIPrintWorkflowObjectModelTargetPackage;

// Windows.Graphics.Printing.Workflow.PrintWorkflowSessionStatus
enum _WGPWPrintWorkflowSessionStatus {
    WGPWPrintWorkflowSessionStatusStarted = 0,
    WGPWPrintWorkflowSessionStatusCompleted = 1,
    WGPWPrintWorkflowSessionStatusAborted = 2,
    WGPWPrintWorkflowSessionStatusClosed = 3,
};
typedef unsigned WGPWPrintWorkflowSessionStatus;

// Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedStatus
enum _WGPWPrintWorkflowSubmittedStatus {
    WGPWPrintWorkflowSubmittedStatusSucceeded = 0,
    WGPWPrintWorkflowSubmittedStatusCanceled = 1,
    WGPWPrintWorkflowSubmittedStatusFailed = 2,
};
typedef unsigned WGPWPrintWorkflowSubmittedStatus;

#include "WindowsApplicationModelActivation.h"
#include "WindowsFoundation.h"
#include "WindowsGraphicsPrintingPrintTicket.h"
#include "WindowsStorageStreams.h"
#include "WindowsSystem.h"

#import <Foundation/Foundation.h>

// Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSession
#ifndef __WGPWPrintWorkflowBackgroundSession_DEFINED__
#define __WGPWPrintWorkflowBackgroundSession_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WGPWPrintWorkflowBackgroundSession : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPWPrintWorkflowSessionStatus status;
- (EventRegistrationToken)addSetupRequestedEvent:(void(^)(WGPWPrintWorkflowBackgroundSession*, WGPWPrintWorkflowBackgroundSetupRequestedEventArgs*))del;
- (void)removeSetupRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSubmittedEvent:(void(^)(WGPWPrintWorkflowBackgroundSession*, WGPWPrintWorkflowSubmittedEventArgs*))del;
- (void)removeSubmittedEvent:(EventRegistrationToken)tok;
- (void)start;
@end

#endif // __WGPWPrintWorkflowBackgroundSession_DEFINED__

// Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSetupRequestedEventArgs
#ifndef __WGPWPrintWorkflowBackgroundSetupRequestedEventArgs_DEFINED__
#define __WGPWPrintWorkflowBackgroundSetupRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WGPWPrintWorkflowBackgroundSetupRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPWPrintWorkflowConfiguration* configuration;
- (void)getUserPrintTicketAsyncWithSuccess:(void (^)(WGPPWorkflowPrintTicket*))success failure:(void (^)(NSError*))failure;
- (void)setRequiresUI;
- (WFDeferral*)getDeferral;
@end

#endif // __WGPWPrintWorkflowBackgroundSetupRequestedEventArgs_DEFINED__

// Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedEventArgs
#ifndef __WGPWPrintWorkflowSubmittedEventArgs_DEFINED__
#define __WGPWPrintWorkflowSubmittedEventArgs_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WGPWPrintWorkflowSubmittedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPWPrintWorkflowSubmittedOperation* operation;
- (WGPWPrintWorkflowTarget*)getTarget:(WGPPWorkflowPrintTicket*)jobPrintTicket;
- (WFDeferral*)getDeferral;
@end

#endif // __WGPWPrintWorkflowSubmittedEventArgs_DEFINED__

// Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSession
#ifndef __WGPWPrintWorkflowForegroundSession_DEFINED__
#define __WGPWPrintWorkflowForegroundSession_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WGPWPrintWorkflowForegroundSession : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPWPrintWorkflowSessionStatus status;
- (EventRegistrationToken)addSetupRequestedEvent:(void(^)(WGPWPrintWorkflowForegroundSession*, WGPWPrintWorkflowForegroundSetupRequestedEventArgs*))del;
- (void)removeSetupRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addXpsDataAvailableEvent:(void(^)(WGPWPrintWorkflowForegroundSession*, WGPWPrintWorkflowXpsDataAvailableEventArgs*))del;
- (void)removeXpsDataAvailableEvent:(EventRegistrationToken)tok;
- (void)start;
@end

#endif // __WGPWPrintWorkflowForegroundSession_DEFINED__

// Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSetupRequestedEventArgs
#ifndef __WGPWPrintWorkflowForegroundSetupRequestedEventArgs_DEFINED__
#define __WGPWPrintWorkflowForegroundSetupRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WGPWPrintWorkflowForegroundSetupRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPWPrintWorkflowConfiguration* configuration;
- (void)getUserPrintTicketAsyncWithSuccess:(void (^)(WGPPWorkflowPrintTicket*))success failure:(void (^)(NSError*))failure;
- (WFDeferral*)getDeferral;
@end

#endif // __WGPWPrintWorkflowForegroundSetupRequestedEventArgs_DEFINED__

// Windows.Graphics.Printing.Workflow.PrintWorkflowXpsDataAvailableEventArgs
#ifndef __WGPWPrintWorkflowXpsDataAvailableEventArgs_DEFINED__
#define __WGPWPrintWorkflowXpsDataAvailableEventArgs_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WGPWPrintWorkflowXpsDataAvailableEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPWPrintWorkflowSubmittedOperation* operation;
- (WFDeferral*)getDeferral;
@end

#endif // __WGPWPrintWorkflowXpsDataAvailableEventArgs_DEFINED__

// Windows.Graphics.Printing.Workflow.PrintWorkflowConfiguration
#ifndef __WGPWPrintWorkflowConfiguration_DEFINED__
#define __WGPWPrintWorkflowConfiguration_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WGPWPrintWorkflowConfiguration : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * jobTitle;
@property (readonly) NSString * sessionId;
@property (readonly) NSString * sourceAppDisplayName;
@end

#endif // __WGPWPrintWorkflowConfiguration_DEFINED__

// Windows.Graphics.Printing.Workflow.PrintWorkflowSourceContent
#ifndef __WGPWPrintWorkflowSourceContent_DEFINED__
#define __WGPWPrintWorkflowSourceContent_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WGPWPrintWorkflowSourceContent : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)getJobPrintTicketAsyncWithSuccess:(void (^)(WGPPWorkflowPrintTicket*))success failure:(void (^)(NSError*))failure;
- (WGPWPrintWorkflowSpoolStreamContent*)getSourceSpoolDataAsStreamContent;
- (WGPWPrintWorkflowObjectModelSourceFileContent*)getSourceSpoolDataAsXpsObjectModel;
@end

#endif // __WGPWPrintWorkflowSourceContent_DEFINED__

// Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedOperation
#ifndef __WGPWPrintWorkflowSubmittedOperation_DEFINED__
#define __WGPWPrintWorkflowSubmittedOperation_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WGPWPrintWorkflowSubmittedOperation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPWPrintWorkflowConfiguration* configuration;
@property (readonly) WGPWPrintWorkflowSourceContent* xpsContent;
- (void)complete:(WGPWPrintWorkflowSubmittedStatus)status;
@end

#endif // __WGPWPrintWorkflowSubmittedOperation_DEFINED__

// Windows.Graphics.Printing.Workflow.PrintWorkflowTarget
#ifndef __WGPWPrintWorkflowTarget_DEFINED__
#define __WGPWPrintWorkflowTarget_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WGPWPrintWorkflowTarget : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPWPrintWorkflowStreamTarget* targetAsStream;
@property (readonly) WGPWPrintWorkflowObjectModelTargetPackage* targetAsXpsObjectModelPackage;
@end

#endif // __WGPWPrintWorkflowTarget_DEFINED__

// Windows.Graphics.Printing.Workflow.PrintWorkflowStreamTarget
#ifndef __WGPWPrintWorkflowStreamTarget_DEFINED__
#define __WGPWPrintWorkflowStreamTarget_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WGPWPrintWorkflowStreamTarget : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (RTObject<WSSIOutputStream>*)getOutputStream;
@end

#endif // __WGPWPrintWorkflowStreamTarget_DEFINED__

// Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelTargetPackage
#ifndef __WGPWPrintWorkflowObjectModelTargetPackage_DEFINED__
#define __WGPWPrintWorkflowObjectModelTargetPackage_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WGPWPrintWorkflowObjectModelTargetPackage : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WGPWPrintWorkflowObjectModelTargetPackage_DEFINED__

// Windows.Graphics.Printing.Workflow.PrintWorkflowSpoolStreamContent
#ifndef __WGPWPrintWorkflowSpoolStreamContent_DEFINED__
#define __WGPWPrintWorkflowSpoolStreamContent_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WGPWPrintWorkflowSpoolStreamContent : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (RTObject<WSSIInputStream>*)getInputStream;
@end

#endif // __WGPWPrintWorkflowSpoolStreamContent_DEFINED__

// Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelSourceFileContent
#ifndef __WGPWPrintWorkflowObjectModelSourceFileContent_DEFINED__
#define __WGPWPrintWorkflowObjectModelSourceFileContent_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WGPWPrintWorkflowObjectModelSourceFileContent : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WGPWPrintWorkflowObjectModelSourceFileContent_DEFINED__

// Windows.ApplicationModel.Activation.IActivatedEventArgs
#ifndef __WAAIActivatedEventArgs_DEFINED__
#define __WAAIActivatedEventArgs_DEFINED__

@protocol WAAIActivatedEventArgs
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WAAIActivatedEventArgs : RTObject <WAAIActivatedEventArgs>
@end

#endif // __WAAIActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IActivatedEventArgsWithUser
#ifndef __WAAIActivatedEventArgsWithUser_DEFINED__
#define __WAAIActivatedEventArgsWithUser_DEFINED__

@protocol WAAIActivatedEventArgsWithUser <WAAIActivatedEventArgs>
@property (readonly) WSUser* user;
@end

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WAAIActivatedEventArgsWithUser : RTObject <WAAIActivatedEventArgsWithUser>
@end

#endif // __WAAIActivatedEventArgsWithUser_DEFINED__

// Windows.Graphics.Printing.Workflow.PrintWorkflowUIActivatedEventArgs
#ifndef __WGPWPrintWorkflowUIActivatedEventArgs_DEFINED__
#define __WGPWPrintWorkflowUIActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WGPWPrintWorkflowUIActivatedEventArgs : RTObject <WAAIActivatedEventArgsWithUser, WAAIActivatedEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WGPWPrintWorkflowForegroundSession* printWorkflowSession;
@end

#endif // __WGPWPrintWorkflowUIActivatedEventArgs_DEFINED__

// Windows.Graphics.Printing.Workflow.PrintWorkflowTriggerDetails
#ifndef __WGPWPrintWorkflowTriggerDetails_DEFINED__
#define __WGPWPrintWorkflowTriggerDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGWORKFLOWEXPORT
@interface WGPWPrintWorkflowTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPWPrintWorkflowBackgroundSession* printWorkflowSession;
@end

#endif // __WGPWPrintWorkflowTriggerDetails_DEFINED__

