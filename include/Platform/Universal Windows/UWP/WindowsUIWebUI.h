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

// WindowsUIWebUI.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUWWebUIVoiceCommandActivatedEventArgs, WUWActivatedDeferral, WUWActivatedOperation, WUWWebUILaunchActivatedEventArgs,
    WUWWebUIShareTargetActivatedEventArgs, WUWWebUIFileActivatedEventArgs, WUWWebUIProtocolActivatedEventArgs,
    WUWWebUIProtocolForResultsActivatedEventArgs, WUWWebUIFileOpenPickerActivatedEventArgs, WUWWebUIFileSavePickerActivatedEventArgs,
    WUWWebUICachedFileUpdaterActivatedEventArgs, WUWWebUIDeviceActivatedEventArgs,
    WUWWebUIAppointmentsProviderAddAppointmentActivatedEventArgs, WUWWebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs,
    WUWWebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs, WUWWebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs,
    WUWWebUIAppointmentsProviderShowTimeFrameActivatedEventArgs, WUWWebUILockScreenActivatedEventArgs,
    WUWWebUIRestrictedLaunchActivatedEventArgs, WUWWebUIFileOpenPickerContinuationEventArgs, WUWWebUIFileSavePickerContinuationEventArgs,
    WUWWebUIFolderPickerContinuationEventArgs, WUWWebUIWebAuthenticationBrokerContinuationEventArgs,
    WUWWebUIWebAccountProviderActivatedEventArgs, WUWWebUIDialReceiverActivatedEventArgs, WUWWebUIToastNotificationActivatedEventArgs,
    WUWWebUINavigatedOperation, WUWSuspendingDeferral, WUWSuspendingOperation, WUWSuspendingEventArgs,
    WUWWebUIBackgroundTaskInstanceRuntimeClass, WUWWebUIBackgroundTaskInstance, WUWWebUINavigatedDeferral, WUWWebUINavigatedEventArgs,
    WUWWebUIApplication, WUWHtmlPrintDocumentSource;
@protocol WUWIActivatedDeferral
, WUWIActivatedOperation, WUWIActivatedEventArgsDeferral, WUWIWebUINavigatedEventArgs, WUWIWebUIBackgroundTaskInstance,
    WUWIWebUIBackgroundTaskInstanceStatics, WUWIWebUINavigatedDeferral, WUWIWebUINavigatedOperation, WUWIWebUIActivationStatics,
    WUWIHtmlPrintDocumentSource;

// Windows.UI.WebUI.PrintContent
enum _WUWPrintContent {
    WUWPrintContentAllPages = 0,
    WUWPrintContentCurrentPage = 1,
    WUWPrintContentCustomPageRange = 2,
    WUWPrintContentCurrentSelection = 3,
};
typedef unsigned WUWPrintContent;

#include "WindowsFoundation.h"
#include "WindowsApplicationModelDataTransferShareTarget.h"
#include "WindowsGraphicsPrinting.h"
#include "WindowsApplicationModelActivation.h"
#include "WindowsMediaSpeechRecognition.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageSearch.h"
#include "WindowsStorage.h"
#include "WindowsStoragePickersProvider.h"
#include "WindowsSystem.h"
#include "WindowsStorageProvider.h"
#include "WindowsApplicationModelAppointmentsAppointmentsProvider.h"
#include "WindowsSecurityAuthenticationWeb.h"
#include "WindowsSecurityAuthenticationWebProvider.h"
#include "WindowsApplicationModel.h"
#include "WindowsApplicationModelBackground.h"
// Windows.ApplicationModel.Background.BackgroundTaskCanceledEventHandler
#ifndef __WABBackgroundTaskCanceledEventHandler__DEFINED
#define __WABBackgroundTaskCanceledEventHandler__DEFINED
typedef void (^WABBackgroundTaskCanceledEventHandler)(RTObject<WABIBackgroundTaskInstance>* sender,
                                                      WABBackgroundTaskCancellationReason reason);
#endif // __WABBackgroundTaskCanceledEventHandler__DEFINED

// Windows.UI.WebUI.ActivatedEventHandler
#ifndef __WUWActivatedEventHandler__DEFINED
#define __WUWActivatedEventHandler__DEFINED
typedef void (^WUWActivatedEventHandler)(RTObject* sender, RTObject<WAAIActivatedEventArgs>* eventArgs);
#endif // __WUWActivatedEventHandler__DEFINED

// Windows.UI.WebUI.NavigatedEventHandler
#ifndef __WUWNavigatedEventHandler__DEFINED
#define __WUWNavigatedEventHandler__DEFINED
typedef void (^WUWNavigatedEventHandler)(RTObject* sender, RTObject<WUWIWebUINavigatedEventArgs>* e);
#endif // __WUWNavigatedEventHandler__DEFINED

// Windows.UI.WebUI.ResumingEventHandler
#ifndef __WUWResumingEventHandler__DEFINED
#define __WUWResumingEventHandler__DEFINED
typedef void (^WUWResumingEventHandler)(RTObject* sender);
#endif // __WUWResumingEventHandler__DEFINED

// Windows.UI.WebUI.SuspendingEventHandler
#ifndef __WUWSuspendingEventHandler__DEFINED
#define __WUWSuspendingEventHandler__DEFINED
typedef void (^WUWSuspendingEventHandler)(RTObject* sender, RTObject<WAISuspendingEventArgs>* e);
#endif // __WUWSuspendingEventHandler__DEFINED

#import <Foundation/Foundation.h>

// Windows.UI.WebUI.ActivatedEventHandler
#ifndef __WUWActivatedEventHandler__DEFINED
#define __WUWActivatedEventHandler__DEFINED
typedef void (^WUWActivatedEventHandler)(RTObject* sender, RTObject<WAAIActivatedEventArgs>* eventArgs);
#endif // __WUWActivatedEventHandler__DEFINED

// Windows.UI.WebUI.ResumingEventHandler
#ifndef __WUWResumingEventHandler__DEFINED
#define __WUWResumingEventHandler__DEFINED
typedef void (^WUWResumingEventHandler)(RTObject* sender);
#endif // __WUWResumingEventHandler__DEFINED

// Windows.UI.WebUI.SuspendingEventHandler
#ifndef __WUWSuspendingEventHandler__DEFINED
#define __WUWSuspendingEventHandler__DEFINED
typedef void (^WUWSuspendingEventHandler)(RTObject* sender, RTObject<WAISuspendingEventArgs>* e);
#endif // __WUWSuspendingEventHandler__DEFINED

// Windows.UI.WebUI.NavigatedEventHandler
#ifndef __WUWNavigatedEventHandler__DEFINED
#define __WUWNavigatedEventHandler__DEFINED
typedef void (^WUWNavigatedEventHandler)(RTObject* sender, RTObject<WUWIWebUINavigatedEventArgs>* e);
#endif // __WUWNavigatedEventHandler__DEFINED

// Windows.UI.WebUI.IActivatedEventArgsDeferral
#ifndef __WUWIActivatedEventArgsDeferral_DEFINED__
#define __WUWIActivatedEventArgsDeferral_DEFINED__

@protocol WUWIActivatedEventArgsDeferral
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWIActivatedEventArgsDeferral_DEFINED__

// Windows.UI.WebUI.IWebUINavigatedEventArgs
#ifndef __WUWIWebUINavigatedEventArgs_DEFINED__
#define __WUWIWebUINavigatedEventArgs_DEFINED__

@protocol WUWIWebUINavigatedEventArgs
@property (readonly) WUWWebUINavigatedOperation* navigatedOperation;
@end

#endif // __WUWIWebUINavigatedEventArgs_DEFINED__

// Windows.UI.WebUI.IWebUIBackgroundTaskInstance
#ifndef __WUWIWebUIBackgroundTaskInstance_DEFINED__
#define __WUWIWebUIBackgroundTaskInstance_DEFINED__

@protocol WUWIWebUIBackgroundTaskInstance
@property BOOL succeeded;
@end

#endif // __WUWIWebUIBackgroundTaskInstance_DEFINED__

// Windows.ApplicationModel.Activation.IActivatedEventArgs
#ifndef __WAAIActivatedEventArgs_DEFINED__
#define __WAAIActivatedEventArgs_DEFINED__

@protocol WAAIActivatedEventArgs
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WAAIActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IVoiceCommandActivatedEventArgs
#ifndef __WAAIVoiceCommandActivatedEventArgs_DEFINED__
#define __WAAIVoiceCommandActivatedEventArgs_DEFINED__

@protocol WAAIVoiceCommandActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WMSSpeechRecognitionResult* result;
@end

#endif // __WAAIVoiceCommandActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIVoiceCommandActivatedEventArgs
#ifndef __WUWWebUIVoiceCommandActivatedEventArgs_DEFINED__
#define __WUWWebUIVoiceCommandActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIVoiceCommandActivatedEventArgs
    : RTObject <WAAIVoiceCommandActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WMSSpeechRecognitionResult* result;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIVoiceCommandActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.ActivatedDeferral
#ifndef __WUWActivatedDeferral_DEFINED__
#define __WUWActivatedDeferral_DEFINED__

WINRT_EXPORT
@interface WUWActivatedDeferral : RTObject
- (void)complete;
@end

#endif // __WUWActivatedDeferral_DEFINED__

// Windows.UI.WebUI.ActivatedOperation
#ifndef __WUWActivatedOperation_DEFINED__
#define __WUWActivatedOperation_DEFINED__

WINRT_EXPORT
@interface WUWActivatedOperation : RTObject
- (WUWActivatedDeferral*)getDeferral;
@end

#endif // __WUWActivatedOperation_DEFINED__

// Windows.ApplicationModel.Activation.ILaunchActivatedEventArgs
#ifndef __WAAILaunchActivatedEventArgs_DEFINED__
#define __WAAILaunchActivatedEventArgs_DEFINED__

@protocol WAAILaunchActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString* arguments;
@property (readonly) NSString* tileId;
@end

#endif // __WAAILaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IPrelaunchActivatedEventArgs
#ifndef __WAAIPrelaunchActivatedEventArgs_DEFINED__
#define __WAAIPrelaunchActivatedEventArgs_DEFINED__

@protocol WAAIPrelaunchActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) BOOL prelaunchActivated;
@end

#endif // __WAAIPrelaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IApplicationViewActivatedEventArgs
#ifndef __WAAIApplicationViewActivatedEventArgs_DEFINED__
#define __WAAIApplicationViewActivatedEventArgs_DEFINED__

@protocol WAAIApplicationViewActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) int currentlyShownApplicationViewId;
@end

#endif // __WAAIApplicationViewActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUILaunchActivatedEventArgs
#ifndef __WUWWebUILaunchActivatedEventArgs_DEFINED__
#define __WUWWebUILaunchActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUILaunchActivatedEventArgs : RTObject <WAAILaunchActivatedEventArgs,
                                                        WAAIActivatedEventArgs,
                                                        WAAIPrelaunchActivatedEventArgs,
                                                        WAAIApplicationViewActivatedEventArgs,
                                                        WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) NSString* arguments;
@property (readonly) NSString* tileId;
@property (readonly) BOOL prelaunchActivated;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUILaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IShareTargetActivatedEventArgs
#ifndef __WAAIShareTargetActivatedEventArgs_DEFINED__
#define __WAAIShareTargetActivatedEventArgs_DEFINED__

@protocol WAAIShareTargetActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WADSShareOperation* shareOperation;
@end

#endif // __WAAIShareTargetActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIShareTargetActivatedEventArgs
#ifndef __WUWWebUIShareTargetActivatedEventArgs_DEFINED__
#define __WUWWebUIShareTargetActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIShareTargetActivatedEventArgs
    : RTObject <WAAIShareTargetActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WADSShareOperation* shareOperation;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIShareTargetActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileActivatedEventArgs
#ifndef __WAAIFileActivatedEventArgs_DEFINED__
#define __WAAIFileActivatedEventArgs_DEFINED__

@protocol WAAIFileActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSArray* files;
@property (readonly) NSString* verb;
@end

#endif // __WAAIFileActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileActivatedEventArgsWithNeighboringFiles
#ifndef __WAAIFileActivatedEventArgsWithNeighboringFiles_DEFINED__
#define __WAAIFileActivatedEventArgsWithNeighboringFiles_DEFINED__

@protocol WAAIFileActivatedEventArgsWithNeighboringFiles <WAAIFileActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WSSStorageFileQueryResult* neighboringFilesQuery;
@end

#endif // __WAAIFileActivatedEventArgsWithNeighboringFiles_DEFINED__

// Windows.UI.WebUI.WebUIFileActivatedEventArgs
#ifndef __WUWWebUIFileActivatedEventArgs_DEFINED__
#define __WUWWebUIFileActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIFileActivatedEventArgs : RTObject <WAAIFileActivatedEventArgs,
                                                      WAAIActivatedEventArgs,
                                                      WAAIApplicationViewActivatedEventArgs,
                                                      WUWIActivatedEventArgsDeferral,
                                                      WAAIFileActivatedEventArgsWithNeighboringFiles>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) NSArray* files;
@property (readonly) NSString* verb;
@property (readonly) WSSStorageFileQueryResult* neighboringFilesQuery;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIFileActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IProtocolActivatedEventArgs
#ifndef __WAAIProtocolActivatedEventArgs_DEFINED__
#define __WAAIProtocolActivatedEventArgs_DEFINED__

@protocol WAAIProtocolActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WFUri* uri;
@end

#endif // __WAAIProtocolActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData
#ifndef __WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData_DEFINED__
#define __WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData_DEFINED__

@protocol WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData <WAAIActivatedEventArgs>
@property (readonly) NSString* callerPackageFamilyName;
@property (readonly) WFCValueSet* data;
@end

#endif // __WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData_DEFINED__

// Windows.UI.WebUI.WebUIProtocolActivatedEventArgs
#ifndef __WUWWebUIProtocolActivatedEventArgs_DEFINED__
#define __WUWWebUIProtocolActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIProtocolActivatedEventArgs : RTObject <WAAIProtocolActivatedEventArgs,
                                                          WAAIActivatedEventArgs,
                                                          WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData,
                                                          WAAIApplicationViewActivatedEventArgs,
                                                          WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) WFUri* uri;
@property (readonly) NSString* callerPackageFamilyName;
@property (readonly) WFCValueSet* data;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIProtocolActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IProtocolForResultsActivatedEventArgs
#ifndef __WAAIProtocolForResultsActivatedEventArgs_DEFINED__
#define __WAAIProtocolForResultsActivatedEventArgs_DEFINED__

@protocol WAAIProtocolForResultsActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WSProtocolForResultsOperation* protocolForResultsOperation;
@end

#endif // __WAAIProtocolForResultsActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIProtocolForResultsActivatedEventArgs
#ifndef __WUWWebUIProtocolForResultsActivatedEventArgs_DEFINED__
#define __WUWWebUIProtocolForResultsActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIProtocolForResultsActivatedEventArgs : RTObject <WAAIProtocolForResultsActivatedEventArgs,
                                                                    WAAIActivatedEventArgs,
                                                                    WAAIProtocolActivatedEventArgs,
                                                                    WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData,
                                                                    WAAIApplicationViewActivatedEventArgs,
                                                                    WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) WFUri* uri;
@property (readonly) NSString* callerPackageFamilyName;
@property (readonly) WFCValueSet* data;
@property (readonly) WSProtocolForResultsOperation* protocolForResultsOperation;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIProtocolForResultsActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileOpenPickerActivatedEventArgs
#ifndef __WAAIFileOpenPickerActivatedEventArgs_DEFINED__
#define __WAAIFileOpenPickerActivatedEventArgs_DEFINED__

@protocol WAAIFileOpenPickerActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WSPPFileOpenPickerUI* fileOpenPickerUI;
@end

#endif // __WAAIFileOpenPickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileOpenPickerActivatedEventArgs2
#ifndef __WAAIFileOpenPickerActivatedEventArgs2_DEFINED__
#define __WAAIFileOpenPickerActivatedEventArgs2_DEFINED__

@protocol WAAIFileOpenPickerActivatedEventArgs2
@property (readonly) NSString* callerPackageFamilyName;
@end

#endif // __WAAIFileOpenPickerActivatedEventArgs2_DEFINED__

// Windows.UI.WebUI.WebUIFileOpenPickerActivatedEventArgs
#ifndef __WUWWebUIFileOpenPickerActivatedEventArgs_DEFINED__
#define __WUWWebUIFileOpenPickerActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIFileOpenPickerActivatedEventArgs : RTObject <WAAIFileOpenPickerActivatedEventArgs,
                                                                WAAIActivatedEventArgs,
                                                                WAAIFileOpenPickerActivatedEventArgs2,
                                                                WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSPPFileOpenPickerUI* fileOpenPickerUI;
@property (readonly) NSString* callerPackageFamilyName;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIFileOpenPickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileSavePickerActivatedEventArgs
#ifndef __WAAIFileSavePickerActivatedEventArgs_DEFINED__
#define __WAAIFileSavePickerActivatedEventArgs_DEFINED__

@protocol WAAIFileSavePickerActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WSPPFileSavePickerUI* fileSavePickerUI;
@end

#endif // __WAAIFileSavePickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileSavePickerActivatedEventArgs2
#ifndef __WAAIFileSavePickerActivatedEventArgs2_DEFINED__
#define __WAAIFileSavePickerActivatedEventArgs2_DEFINED__

@protocol WAAIFileSavePickerActivatedEventArgs2
@property (readonly) NSString* callerPackageFamilyName;
@property (readonly) NSString* enterpriseId;
@end

#endif // __WAAIFileSavePickerActivatedEventArgs2_DEFINED__

// Windows.UI.WebUI.WebUIFileSavePickerActivatedEventArgs
#ifndef __WUWWebUIFileSavePickerActivatedEventArgs_DEFINED__
#define __WUWWebUIFileSavePickerActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIFileSavePickerActivatedEventArgs : RTObject <WAAIFileSavePickerActivatedEventArgs,
                                                                WAAIActivatedEventArgs,
                                                                WAAIFileSavePickerActivatedEventArgs2,
                                                                WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSPPFileSavePickerUI* fileSavePickerUI;
@property (readonly) NSString* callerPackageFamilyName;
@property (readonly) NSString* enterpriseId;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIFileSavePickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ICachedFileUpdaterActivatedEventArgs
#ifndef __WAAICachedFileUpdaterActivatedEventArgs_DEFINED__
#define __WAAICachedFileUpdaterActivatedEventArgs_DEFINED__

@protocol WAAICachedFileUpdaterActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WSPCachedFileUpdaterUI* cachedFileUpdaterUI;
@end

#endif // __WAAICachedFileUpdaterActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUICachedFileUpdaterActivatedEventArgs
#ifndef __WUWWebUICachedFileUpdaterActivatedEventArgs_DEFINED__
#define __WUWWebUICachedFileUpdaterActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUICachedFileUpdaterActivatedEventArgs
    : RTObject <WAAICachedFileUpdaterActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSPCachedFileUpdaterUI* cachedFileUpdaterUI;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUICachedFileUpdaterActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IDeviceActivatedEventArgs
#ifndef __WAAIDeviceActivatedEventArgs_DEFINED__
#define __WAAIDeviceActivatedEventArgs_DEFINED__

@protocol WAAIDeviceActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString* deviceInformationId;
@property (readonly) NSString* verb;
@end

#endif // __WAAIDeviceActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIDeviceActivatedEventArgs
#ifndef __WUWWebUIDeviceActivatedEventArgs_DEFINED__
#define __WUWWebUIDeviceActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIDeviceActivatedEventArgs
    : RTObject <WAAIDeviceActivatedEventArgs, WAAIActivatedEventArgs, WAAIApplicationViewActivatedEventArgs, WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) NSString* deviceInformationId;
@property (readonly) NSString* verb;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIDeviceActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IAppointmentsProviderActivatedEventArgs
#ifndef __WAAIAppointmentsProviderActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString* verb;
@end

#endif // __WAAIAppointmentsProviderActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IAppointmentsProviderAddAppointmentActivatedEventArgs
#ifndef __WAAIAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderAddAppointmentActivatedEventArgs <WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAAAddAppointmentOperation* addAppointmentOperation;
@end

#endif // __WAAIAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIAppointmentsProviderAddAppointmentActivatedEventArgs
#ifndef __WUWWebUIAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__
#define __WUWWebUIAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIAppointmentsProviderAddAppointmentActivatedEventArgs
    : RTObject <WAAIAppointmentsProviderAddAppointmentActivatedEventArgs,
                WAAIAppointmentsProviderActivatedEventArgs,
                WAAIActivatedEventArgs,
                WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* verb;
@property (readonly) WAAAAddAppointmentOperation* addAppointmentOperation;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IAppointmentsProviderReplaceAppointmentActivatedEventArgs
#ifndef __WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs <WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAAReplaceAppointmentOperation* replaceAppointmentOperation;
@end

#endif // __WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs
#ifndef __WUWWebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__
#define __WUWWebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs
    : RTObject <WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs,
                WAAIAppointmentsProviderActivatedEventArgs,
                WAAIActivatedEventArgs,
                WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* verb;
@property (readonly) WAAAReplaceAppointmentOperation* replaceAppointmentOperation;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IAppointmentsProviderRemoveAppointmentActivatedEventArgs
#ifndef __WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs <WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAARemoveAppointmentOperation* removeAppointmentOperation;
@end

#endif // __WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs
#ifndef __WUWWebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__
#define __WUWWebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs
    : RTObject <WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs,
                WAAIAppointmentsProviderActivatedEventArgs,
                WAAIActivatedEventArgs,
                WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* verb;
@property (readonly) WAAARemoveAppointmentOperation* removeAppointmentOperation;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs
#ifndef __WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__

@protocol
    WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs <WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) id instanceStartDate;
@property (readonly) NSString* localId;
@property (readonly) NSString* roamingId;
@end

#endif // __WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs
#ifndef __WUWWebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__
#define __WUWWebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs
    : RTObject <WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs,
                WAAIAppointmentsProviderActivatedEventArgs,
                WAAIActivatedEventArgs,
                WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* verb;
@property (readonly) id instanceStartDate;
@property (readonly) NSString* localId;
@property (readonly) NSString* roamingId;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IAppointmentsProviderShowTimeFrameActivatedEventArgs
#ifndef __WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs <WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WFTimeSpan* duration;
@property (readonly) WFDateTime* timeToShow;
@end

#endif // __WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIAppointmentsProviderShowTimeFrameActivatedEventArgs
#ifndef __WUWWebUIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__
#define __WUWWebUIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIAppointmentsProviderShowTimeFrameActivatedEventArgs : RTObject <WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs,
                                                                                   WAAIAppointmentsProviderActivatedEventArgs,
                                                                                   WAAIActivatedEventArgs,
                                                                                   WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* verb;
@property (readonly) WFTimeSpan* duration;
@property (readonly) WFDateTime* timeToShow;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ILockScreenActivatedEventArgs
#ifndef __WAAILockScreenActivatedEventArgs_DEFINED__
#define __WAAILockScreenActivatedEventArgs_DEFINED__

@protocol WAAILockScreenActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) RTObject* info;
@end

#endif // __WAAILockScreenActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUILockScreenActivatedEventArgs
#ifndef __WUWWebUILockScreenActivatedEventArgs_DEFINED__
#define __WUWWebUILockScreenActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUILockScreenActivatedEventArgs : RTObject <WAAILockScreenActivatedEventArgs,
                                                            WAAIActivatedEventArgs,
                                                            WAAIApplicationViewActivatedEventArgs,
                                                            WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) RTObject* info;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUILockScreenActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IRestrictedLaunchActivatedEventArgs
#ifndef __WAAIRestrictedLaunchActivatedEventArgs_DEFINED__
#define __WAAIRestrictedLaunchActivatedEventArgs_DEFINED__

@protocol WAAIRestrictedLaunchActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) RTObject* sharedContext;
@end

#endif // __WAAIRestrictedLaunchActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIRestrictedLaunchActivatedEventArgs
#ifndef __WUWWebUIRestrictedLaunchActivatedEventArgs_DEFINED__
#define __WUWWebUIRestrictedLaunchActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIRestrictedLaunchActivatedEventArgs
    : RTObject <WAAIRestrictedLaunchActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) RTObject* sharedContext;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIRestrictedLaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContinuationActivatedEventArgs
#ifndef __WAAIContinuationActivatedEventArgs_DEFINED__
#define __WAAIContinuationActivatedEventArgs_DEFINED__

@protocol WAAIContinuationActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WFCValueSet* continuationData;
@end

#endif // __WAAIContinuationActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileOpenPickerContinuationEventArgs
#ifndef __WAAIFileOpenPickerContinuationEventArgs_DEFINED__
#define __WAAIFileOpenPickerContinuationEventArgs_DEFINED__

@protocol WAAIFileOpenPickerContinuationEventArgs <WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) NSArray* files;
@end

#endif // __WAAIFileOpenPickerContinuationEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIFileOpenPickerContinuationEventArgs
#ifndef __WUWWebUIFileOpenPickerContinuationEventArgs_DEFINED__
#define __WUWWebUIFileOpenPickerContinuationEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIFileOpenPickerContinuationEventArgs : RTObject <WAAIFileOpenPickerContinuationEventArgs,
                                                                   WAAIContinuationActivatedEventArgs,
                                                                   WAAIActivatedEventArgs,
                                                                   WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WFCValueSet* continuationData;
@property (readonly) NSArray* files;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIFileOpenPickerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileSavePickerContinuationEventArgs
#ifndef __WAAIFileSavePickerContinuationEventArgs_DEFINED__
#define __WAAIFileSavePickerContinuationEventArgs_DEFINED__

@protocol WAAIFileSavePickerContinuationEventArgs <WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WSStorageFile* file;
@end

#endif // __WAAIFileSavePickerContinuationEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIFileSavePickerContinuationEventArgs
#ifndef __WUWWebUIFileSavePickerContinuationEventArgs_DEFINED__
#define __WUWWebUIFileSavePickerContinuationEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIFileSavePickerContinuationEventArgs : RTObject <WAAIFileSavePickerContinuationEventArgs,
                                                                   WAAIContinuationActivatedEventArgs,
                                                                   WAAIActivatedEventArgs,
                                                                   WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WFCValueSet* continuationData;
@property (readonly) WSStorageFile* file;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIFileSavePickerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFolderPickerContinuationEventArgs
#ifndef __WAAIFolderPickerContinuationEventArgs_DEFINED__
#define __WAAIFolderPickerContinuationEventArgs_DEFINED__

@protocol WAAIFolderPickerContinuationEventArgs <WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WSStorageFolder* folder;
@end

#endif // __WAAIFolderPickerContinuationEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIFolderPickerContinuationEventArgs
#ifndef __WUWWebUIFolderPickerContinuationEventArgs_DEFINED__
#define __WUWWebUIFolderPickerContinuationEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIFolderPickerContinuationEventArgs : RTObject <WAAIFolderPickerContinuationEventArgs,
                                                                 WAAIContinuationActivatedEventArgs,
                                                                 WAAIActivatedEventArgs,
                                                                 WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WFCValueSet* continuationData;
@property (readonly) WSStorageFolder* folder;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIFolderPickerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IWebAuthenticationBrokerContinuationEventArgs
#ifndef __WAAIWebAuthenticationBrokerContinuationEventArgs_DEFINED__
#define __WAAIWebAuthenticationBrokerContinuationEventArgs_DEFINED__

@protocol WAAIWebAuthenticationBrokerContinuationEventArgs <WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WSAWWebAuthenticationResult* webAuthenticationResult;
@end

#endif // __WAAIWebAuthenticationBrokerContinuationEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIWebAuthenticationBrokerContinuationEventArgs
#ifndef __WUWWebUIWebAuthenticationBrokerContinuationEventArgs_DEFINED__
#define __WUWWebUIWebAuthenticationBrokerContinuationEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIWebAuthenticationBrokerContinuationEventArgs : RTObject <WAAIWebAuthenticationBrokerContinuationEventArgs,
                                                                            WAAIContinuationActivatedEventArgs,
                                                                            WAAIActivatedEventArgs,
                                                                            WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WFCValueSet* continuationData;
@property (readonly) WSAWWebAuthenticationResult* webAuthenticationResult;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIWebAuthenticationBrokerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IWebAccountProviderActivatedEventArgs
#ifndef __WAAIWebAccountProviderActivatedEventArgs_DEFINED__
#define __WAAIWebAccountProviderActivatedEventArgs_DEFINED__

@protocol WAAIWebAccountProviderActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) RTObject<WSAWPIWebAccountProviderOperation>* operation;
@end

#endif // __WAAIWebAccountProviderActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIWebAccountProviderActivatedEventArgs
#ifndef __WUWWebUIWebAccountProviderActivatedEventArgs_DEFINED__
#define __WUWWebUIWebAccountProviderActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIWebAccountProviderActivatedEventArgs
    : RTObject <WAAIWebAccountProviderActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) RTObject<WSAWPIWebAccountProviderOperation>* operation;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIWebAccountProviderActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IDialReceiverActivatedEventArgs
#ifndef __WAAIDialReceiverActivatedEventArgs_DEFINED__
#define __WAAIDialReceiverActivatedEventArgs_DEFINED__

@protocol WAAIDialReceiverActivatedEventArgs <WAAILaunchActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) NSString* appName;
@end

#endif // __WAAIDialReceiverActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIDialReceiverActivatedEventArgs
#ifndef __WUWWebUIDialReceiverActivatedEventArgs_DEFINED__
#define __WUWWebUIDialReceiverActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIDialReceiverActivatedEventArgs : RTObject <WAAIDialReceiverActivatedEventArgs,
                                                              WAAILaunchActivatedEventArgs,
                                                              WAAIActivatedEventArgs,
                                                              WAAIApplicationViewActivatedEventArgs,
                                                              WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) NSString* appName;
@property (readonly) NSString* arguments;
@property (readonly) NSString* tileId;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIDialReceiverActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IToastNotificationActivatedEventArgs
#ifndef __WAAIToastNotificationActivatedEventArgs_DEFINED__
#define __WAAIToastNotificationActivatedEventArgs_DEFINED__

@protocol WAAIToastNotificationActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString* argument;
@property (readonly) WFCValueSet* userInput;
@end

#endif // __WAAIToastNotificationActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIToastNotificationActivatedEventArgs
#ifndef __WUWWebUIToastNotificationActivatedEventArgs_DEFINED__
#define __WUWWebUIToastNotificationActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIToastNotificationActivatedEventArgs
    : RTObject <WAAIToastNotificationActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* argument;
@property (readonly) WFCValueSet* userInput;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIToastNotificationActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUINavigatedOperation
#ifndef __WUWWebUINavigatedOperation_DEFINED__
#define __WUWWebUINavigatedOperation_DEFINED__

WINRT_EXPORT
@interface WUWWebUINavigatedOperation : RTObject
- (WUWWebUINavigatedDeferral*)getDeferral;
@end

#endif // __WUWWebUINavigatedOperation_DEFINED__

// Windows.ApplicationModel.ISuspendingDeferral
#ifndef __WAISuspendingDeferral_DEFINED__
#define __WAISuspendingDeferral_DEFINED__

@protocol WAISuspendingDeferral
- (void)complete;
@end

#endif // __WAISuspendingDeferral_DEFINED__

// Windows.UI.WebUI.SuspendingDeferral
#ifndef __WUWSuspendingDeferral_DEFINED__
#define __WUWSuspendingDeferral_DEFINED__

WINRT_EXPORT
@interface WUWSuspendingDeferral : RTObject <WAISuspendingDeferral>
- (void)complete;
@end

#endif // __WUWSuspendingDeferral_DEFINED__

// Windows.ApplicationModel.ISuspendingOperation
#ifndef __WAISuspendingOperation_DEFINED__
#define __WAISuspendingOperation_DEFINED__

@protocol WAISuspendingOperation
@property (readonly) WFDateTime* deadline;
- (WASuspendingDeferral*)getDeferral;
@end

#endif // __WAISuspendingOperation_DEFINED__

// Windows.UI.WebUI.SuspendingOperation
#ifndef __WUWSuspendingOperation_DEFINED__
#define __WUWSuspendingOperation_DEFINED__

WINRT_EXPORT
@interface WUWSuspendingOperation : RTObject <WAISuspendingOperation>
@property (readonly) WFDateTime* deadline;
- (WASuspendingDeferral*)getDeferral;
@end

#endif // __WUWSuspendingOperation_DEFINED__

// Windows.ApplicationModel.ISuspendingEventArgs
#ifndef __WAISuspendingEventArgs_DEFINED__
#define __WAISuspendingEventArgs_DEFINED__

@protocol WAISuspendingEventArgs
@property (readonly) WASuspendingOperation* suspendingOperation;
@end

#endif // __WAISuspendingEventArgs_DEFINED__

// Windows.UI.WebUI.SuspendingEventArgs
#ifndef __WUWSuspendingEventArgs_DEFINED__
#define __WUWSuspendingEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWSuspendingEventArgs : RTObject <WAISuspendingEventArgs>
@property (readonly) WASuspendingOperation* suspendingOperation;
@end

#endif // __WUWSuspendingEventArgs_DEFINED__

// Windows.ApplicationModel.Background.IBackgroundTaskInstance
#ifndef __WABIBackgroundTaskInstance_DEFINED__
#define __WABIBackgroundTaskInstance_DEFINED__

@protocol WABIBackgroundTaskInstance
@property (readonly) WFGUID* instanceId;
@property unsigned int progress;
@property (readonly) unsigned int suspendedCount;
@property (readonly) WABBackgroundTaskRegistration* task;
@property (readonly) RTObject* triggerDetails;
- (EventRegistrationToken)addCanceledEvent:(WABBackgroundTaskCanceledEventHandler)del;
- (void)removeCanceledEvent:(EventRegistrationToken)tok;
- (WABBackgroundTaskDeferral*)getDeferral;
@end

#endif // __WABIBackgroundTaskInstance_DEFINED__

// Windows.UI.WebUI.WebUIBackgroundTaskInstanceRuntimeClass
#ifndef __WUWWebUIBackgroundTaskInstanceRuntimeClass_DEFINED__
#define __WUWWebUIBackgroundTaskInstanceRuntimeClass_DEFINED__

WINRT_EXPORT
@interface WUWWebUIBackgroundTaskInstanceRuntimeClass : RTObject <WUWIWebUIBackgroundTaskInstance, WABIBackgroundTaskInstance>
@property unsigned int progress;
@property (readonly) WFGUID* instanceId;
@property (readonly) unsigned int suspendedCount;
@property (readonly) WABBackgroundTaskRegistration* task;
@property (readonly) RTObject* triggerDetails;
@property BOOL succeeded;
- (EventRegistrationToken)addCanceledEvent:(WABBackgroundTaskCanceledEventHandler)del;
- (void)removeCanceledEvent:(EventRegistrationToken)tok;
- (WABBackgroundTaskDeferral*)getDeferral;
@end

#endif // __WUWWebUIBackgroundTaskInstanceRuntimeClass_DEFINED__

// Windows.UI.WebUI.WebUIBackgroundTaskInstance
#ifndef __WUWWebUIBackgroundTaskInstance_DEFINED__
#define __WUWWebUIBackgroundTaskInstance_DEFINED__

WINRT_EXPORT
@interface WUWWebUIBackgroundTaskInstance : RTObject
+ (RTObject<WUWIWebUIBackgroundTaskInstance>*)current;
@end

#endif // __WUWWebUIBackgroundTaskInstance_DEFINED__

// Windows.UI.WebUI.WebUINavigatedDeferral
#ifndef __WUWWebUINavigatedDeferral_DEFINED__
#define __WUWWebUINavigatedDeferral_DEFINED__

WINRT_EXPORT
@interface WUWWebUINavigatedDeferral : RTObject
- (void)complete;
@end

#endif // __WUWWebUINavigatedDeferral_DEFINED__

// Windows.UI.WebUI.WebUINavigatedEventArgs
#ifndef __WUWWebUINavigatedEventArgs_DEFINED__
#define __WUWWebUINavigatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUINavigatedEventArgs : RTObject <WUWIWebUINavigatedEventArgs>
@property (readonly) WUWWebUINavigatedOperation* navigatedOperation;
@end

#endif // __WUWWebUINavigatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIApplication
#ifndef __WUWWebUIApplication_DEFINED__
#define __WUWWebUIApplication_DEFINED__

WINRT_EXPORT
@interface WUWWebUIApplication : RTObject
+ (EventRegistrationToken)addActivatedEvent:(WUWActivatedEventHandler)del;
+ (void)removeActivatedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addNavigatedEvent:(WUWNavigatedEventHandler)del;
+ (void)removeNavigatedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addResumingEvent:(WUWResumingEventHandler)del;
+ (void)removeResumingEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addSuspendingEvent:(WUWSuspendingEventHandler)del;
+ (void)removeSuspendingEvent:(EventRegistrationToken)tok;
@end

#endif // __WUWWebUIApplication_DEFINED__

// Windows.Graphics.Printing.IPrintDocumentSource
#ifndef __WGPIPrintDocumentSource_DEFINED__
#define __WGPIPrintDocumentSource_DEFINED__

@protocol WGPIPrintDocumentSource
@end

#endif // __WGPIPrintDocumentSource_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.UI.WebUI.HtmlPrintDocumentSource
#ifndef __WUWHtmlPrintDocumentSource_DEFINED__
#define __WUWHtmlPrintDocumentSource_DEFINED__

WINRT_EXPORT
@interface WUWHtmlPrintDocumentSource : RTObject <WGPIPrintDocumentSource, WFIClosable>
@property float topMargin;
@property BOOL shrinkToFit;
@property float rightMargin;
@property float percentScale;
@property float leftMargin;
@property BOOL enableHeaderFooter;
@property WUWPrintContent content;
@property float bottomMargin;
@property (readonly) NSString* pageRange;
- (BOOL)trySetPageRange:(NSString*)strPageRange;
- (void)close;
@end

#endif // __WUWHtmlPrintDocumentSource_DEFINED__
