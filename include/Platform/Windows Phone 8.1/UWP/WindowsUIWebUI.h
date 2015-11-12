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
@class WUWActivatedDeferral, WUWActivatedOperation, WUWWebUILaunchActivatedEventArgs, WUWWebUISearchActivatedEventArgs,
    WUWWebUIShareTargetActivatedEventArgs, WUWWebUIFileActivatedEventArgs, WUWWebUIProtocolActivatedEventArgs,
    WUWWebUIFileOpenPickerActivatedEventArgs, WUWWebUIFileSavePickerActivatedEventArgs, WUWWebUICachedFileUpdaterActivatedEventArgs,
    WUWWebUIContactPickerActivatedEventArgs, WUWWebUIDeviceActivatedEventArgs, WUWWebUIPrintTaskSettingsActivatedEventArgs,
    WUWWebUICameraSettingsActivatedEventArgs, WUWWebUIAppointmentsProviderAddAppointmentActivatedEventArgs,
    WUWWebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs, WUWWebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs,
    WUWWebUIAppointmentsProviderShowTimeFrameActivatedEventArgs, WUWWebUIContactCallActivatedEventArgs,
    WUWWebUIContactMessageActivatedEventArgs, WUWWebUIContactMapActivatedEventArgs, WUWWebUIContactPostActivatedEventArgs,
    WUWWebUIContactVideoCallActivatedEventArgs, WUWWebUILockScreenCallActivatedEventArgs, WUWWebUIRestrictedLaunchActivatedEventArgs,
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
#include "WindowsApplicationModelCalls.h"
#include "WindowsGraphicsPrinting.h"
#include "WindowsApplicationModelActivation.h"
#include "WindowsApplicationModelSearch.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageSearch.h"
#include "WindowsStorage.h"
#include "WindowsStoragePickersProvider.h"
#include "WindowsStorageProvider.h"
#include "WindowsApplicationModelContactsProvider.h"
#include "WindowsDevicesPrintersExtensions.h"
#include "WindowsApplicationModelAppointmentsAppointmentsProvider.h"
#include "WindowsApplicationModelContacts.h"
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

// Windows.ApplicationModel.Activation.IActivatedEventArgs
#ifndef __WAAIActivatedEventArgs_DEFINED__
#define __WAAIActivatedEventArgs_DEFINED__

@protocol WAAIActivatedEventArgs
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WAAIActivatedEventArgs_DEFINED__

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
@property (readonly) NSString* arguments;
@property (readonly) NSString* tileId;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) BOOL prelaunchActivated;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUILaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ISearchActivatedEventArgs
#ifndef __WAAISearchActivatedEventArgs_DEFINED__
#define __WAAISearchActivatedEventArgs_DEFINED__

@protocol WAAISearchActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString* language;
@property (readonly) NSString* queryText;
@end

#endif // __WAAISearchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ISearchActivatedEventArgsWithLinguisticDetails
#ifndef __WAAISearchActivatedEventArgsWithLinguisticDetails_DEFINED__
#define __WAAISearchActivatedEventArgsWithLinguisticDetails_DEFINED__

@protocol WAAISearchActivatedEventArgsWithLinguisticDetails
@property (readonly) WASSearchPaneQueryLinguisticDetails* linguisticDetails;
@end

#endif // __WAAISearchActivatedEventArgsWithLinguisticDetails_DEFINED__

// Windows.UI.WebUI.WebUISearchActivatedEventArgs
#ifndef __WUWWebUISearchActivatedEventArgs_DEFINED__
#define __WUWWebUISearchActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUISearchActivatedEventArgs : RTObject <WAAISearchActivatedEventArgs,
                                                        WAAIActivatedEventArgs,
                                                        WAAISearchActivatedEventArgsWithLinguisticDetails,
                                                        WAAIApplicationViewActivatedEventArgs,
                                                        WUWIActivatedEventArgsDeferral>
@property (readonly) NSString* language;
@property (readonly) NSString* queryText;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WASSearchPaneQueryLinguisticDetails* linguisticDetails;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUISearchActivatedEventArgs_DEFINED__

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
@property (readonly) WADSShareOperation* shareOperation;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIShareTargetActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileActivatedEventArgs
#ifndef __WAAIFileActivatedEventArgs_DEFINED__
#define __WAAIFileActivatedEventArgs_DEFINED__

@protocol WAAIFileActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) id<NSFastEnumeration> /*WSIStorageItem*/ files;
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
@property (readonly) id<NSFastEnumeration> /*WSIStorageItem*/ files;
@property (readonly) NSString* verb;
@property (readonly) int currentlyShownApplicationViewId;
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

// Windows.UI.WebUI.WebUIProtocolActivatedEventArgs
#ifndef __WUWWebUIProtocolActivatedEventArgs_DEFINED__
#define __WUWWebUIProtocolActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIProtocolActivatedEventArgs : RTObject <WAAIProtocolActivatedEventArgs,
                                                          WAAIActivatedEventArgs,
                                                          WAAIApplicationViewActivatedEventArgs,
                                                          WUWIActivatedEventArgsDeferral>
@property (readonly) WUWActivatedOperation* activatedOperation;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) WFUri* uri;
@end

#endif // __WUWWebUIProtocolActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileOpenPickerActivatedEventArgs
#ifndef __WAAIFileOpenPickerActivatedEventArgs_DEFINED__
#define __WAAIFileOpenPickerActivatedEventArgs_DEFINED__

@protocol WAAIFileOpenPickerActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WSPPFileOpenPickerUI* fileOpenPickerUI;
@end

#endif // __WAAIFileOpenPickerActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIFileOpenPickerActivatedEventArgs
#ifndef __WUWWebUIFileOpenPickerActivatedEventArgs_DEFINED__
#define __WUWWebUIFileOpenPickerActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIFileOpenPickerActivatedEventArgs
    : RTObject <WAAIFileOpenPickerActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSPPFileOpenPickerUI* fileOpenPickerUI;
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

// Windows.UI.WebUI.WebUIFileSavePickerActivatedEventArgs
#ifndef __WUWWebUIFileSavePickerActivatedEventArgs_DEFINED__
#define __WUWWebUIFileSavePickerActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIFileSavePickerActivatedEventArgs
    : RTObject <WAAIFileSavePickerActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
@property (readonly) WUWActivatedOperation* activatedOperation;
@property (readonly) WSPPFileSavePickerUI* fileSavePickerUI;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
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
@property (readonly) WUWActivatedOperation* activatedOperation;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSPCachedFileUpdaterUI* cachedFileUpdaterUI;
@end

#endif // __WUWWebUICachedFileUpdaterActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactPickerActivatedEventArgs
#ifndef __WAAIContactPickerActivatedEventArgs_DEFINED__
#define __WAAIContactPickerActivatedEventArgs_DEFINED__

@protocol WAAIContactPickerActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WACPContactPickerUI* contactPickerUI;
@end

#endif // __WAAIContactPickerActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIContactPickerActivatedEventArgs
#ifndef __WUWWebUIContactPickerActivatedEventArgs_DEFINED__
#define __WUWWebUIContactPickerActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIContactPickerActivatedEventArgs
    : RTObject <WAAIContactPickerActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
@property (readonly) WACPContactPickerUI* contactPickerUI;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIContactPickerActivatedEventArgs_DEFINED__

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
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WUWActivatedOperation* activatedOperation;
@property (readonly) NSString* deviceInformationId;
@property (readonly) NSString* verb;
@end

#endif // __WUWWebUIDeviceActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IPrintTaskSettingsActivatedEventArgs
#ifndef __WAAIPrintTaskSettingsActivatedEventArgs_DEFINED__
#define __WAAIPrintTaskSettingsActivatedEventArgs_DEFINED__

@protocol WAAIPrintTaskSettingsActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WDPEPrintTaskConfiguration* configuration;
@end

#endif // __WAAIPrintTaskSettingsActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIPrintTaskSettingsActivatedEventArgs
#ifndef __WUWWebUIPrintTaskSettingsActivatedEventArgs_DEFINED__
#define __WUWWebUIPrintTaskSettingsActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIPrintTaskSettingsActivatedEventArgs
    : RTObject <WAAIPrintTaskSettingsActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
@property (readonly) WUWActivatedOperation* activatedOperation;
@property (readonly) WDPEPrintTaskConfiguration* configuration;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WUWWebUIPrintTaskSettingsActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ICameraSettingsActivatedEventArgs
#ifndef __WAAICameraSettingsActivatedEventArgs_DEFINED__
#define __WAAICameraSettingsActivatedEventArgs_DEFINED__

@protocol WAAICameraSettingsActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) RTObject* videoDeviceController;
@property (readonly) RTObject* videoDeviceExtension;
@end

#endif // __WAAICameraSettingsActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUICameraSettingsActivatedEventArgs
#ifndef __WUWWebUICameraSettingsActivatedEventArgs_DEFINED__
#define __WUWWebUICameraSettingsActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUICameraSettingsActivatedEventArgs
    : RTObject <WAAICameraSettingsActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
@property (readonly) RTObject* videoDeviceController;
@property (readonly) RTObject* videoDeviceExtension;
@property (readonly) WUWActivatedOperation* activatedOperation;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WUWWebUICameraSettingsActivatedEventArgs_DEFINED__

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
@property (readonly) WUWActivatedOperation* activatedOperation;
@property (readonly) WAAAAddAppointmentOperation* addAppointmentOperation;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* verb;
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
@property (readonly) WAAAReplaceAppointmentOperation* replaceAppointmentOperation;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WUWActivatedOperation* activatedOperation;
@property (readonly) NSString* verb;
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
@property (readonly) WAAARemoveAppointmentOperation* removeAppointmentOperation;
@property (readonly) WUWActivatedOperation* activatedOperation;
@property (readonly) NSString* verb;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WUWWebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

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
@property (readonly) NSString* verb;
@property (readonly) WFTimeSpan* duration;
@property (readonly) WFDateTime* timeToShow;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactActivatedEventArgs
#ifndef __WAAIContactActivatedEventArgs_DEFINED__
#define __WAAIContactActivatedEventArgs_DEFINED__

@protocol WAAIContactActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString* verb;
@end

#endif // __WAAIContactActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactCallActivatedEventArgs
#ifndef __WAAIContactCallActivatedEventArgs_DEFINED__
#define __WAAIContactCallActivatedEventArgs_DEFINED__

@protocol WAAIContactCallActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString* serviceId;
@property (readonly) NSString* serviceUserId;
@end

#endif // __WAAIContactCallActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIContactCallActivatedEventArgs
#ifndef __WUWWebUIContactCallActivatedEventArgs_DEFINED__
#define __WUWWebUIContactCallActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIContactCallActivatedEventArgs
    : RTObject <WAAIContactCallActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
@property (readonly) WACContact* contact;
@property (readonly) NSString* serviceId;
@property (readonly) NSString* serviceUserId;
@property (readonly) WUWActivatedOperation* activatedOperation;
@property (readonly) NSString* verb;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WUWWebUIContactCallActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactMessageActivatedEventArgs
#ifndef __WAAIContactMessageActivatedEventArgs_DEFINED__
#define __WAAIContactMessageActivatedEventArgs_DEFINED__

@protocol WAAIContactMessageActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString* serviceId;
@property (readonly) NSString* serviceUserId;
@end

#endif // __WAAIContactMessageActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIContactMessageActivatedEventArgs
#ifndef __WUWWebUIContactMessageActivatedEventArgs_DEFINED__
#define __WUWWebUIContactMessageActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIContactMessageActivatedEventArgs
    : RTObject <WAAIContactMessageActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
@property (readonly) NSString* verb;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WUWActivatedOperation* activatedOperation;
@property (readonly) WACContact* contact;
@property (readonly) NSString* serviceId;
@property (readonly) NSString* serviceUserId;
@end

#endif // __WUWWebUIContactMessageActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactMapActivatedEventArgs
#ifndef __WAAIContactMapActivatedEventArgs_DEFINED__
#define __WAAIContactMapActivatedEventArgs_DEFINED__

@protocol WAAIContactMapActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContactAddress* address;
@property (readonly) WACContact* contact;
@end

#endif // __WAAIContactMapActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIContactMapActivatedEventArgs
#ifndef __WUWWebUIContactMapActivatedEventArgs_DEFINED__
#define __WUWWebUIContactMapActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIContactMapActivatedEventArgs
    : RTObject <WAAIContactMapActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
@property (readonly) WACContactAddress* address;
@property (readonly) WACContact* contact;
@property (readonly) WUWActivatedOperation* activatedOperation;
@property (readonly) NSString* verb;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WUWWebUIContactMapActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactPostActivatedEventArgs
#ifndef __WAAIContactPostActivatedEventArgs_DEFINED__
#define __WAAIContactPostActivatedEventArgs_DEFINED__

@protocol WAAIContactPostActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString* serviceId;
@property (readonly) NSString* serviceUserId;
@end

#endif // __WAAIContactPostActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIContactPostActivatedEventArgs
#ifndef __WUWWebUIContactPostActivatedEventArgs_DEFINED__
#define __WUWWebUIContactPostActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIContactPostActivatedEventArgs
    : RTObject <WAAIContactPostActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
@property (readonly) WACContact* contact;
@property (readonly) NSString* serviceId;
@property (readonly) NSString* serviceUserId;
@property (readonly) NSString* verb;
@property (readonly) WUWActivatedOperation* activatedOperation;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WUWWebUIContactPostActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactVideoCallActivatedEventArgs
#ifndef __WAAIContactVideoCallActivatedEventArgs_DEFINED__
#define __WAAIContactVideoCallActivatedEventArgs_DEFINED__

@protocol WAAIContactVideoCallActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString* serviceId;
@property (readonly) NSString* serviceUserId;
@end

#endif // __WAAIContactVideoCallActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIContactVideoCallActivatedEventArgs
#ifndef __WUWWebUIContactVideoCallActivatedEventArgs_DEFINED__
#define __WUWWebUIContactVideoCallActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUIContactVideoCallActivatedEventArgs : RTObject <WAAIContactVideoCallActivatedEventArgs,
                                                                  WAAIContactActivatedEventArgs,
                                                                  WAAIActivatedEventArgs,
                                                                  WUWIActivatedEventArgsDeferral>
@property (readonly) WUWActivatedOperation* activatedOperation;
@property (readonly) WACContact* contact;
@property (readonly) NSString* serviceId;
@property (readonly) NSString* serviceUserId;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* verb;
@end

#endif // __WUWWebUIContactVideoCallActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ILockScreenCallActivatedEventArgs
#ifndef __WAAILockScreenCallActivatedEventArgs_DEFINED__
#define __WAAILockScreenCallActivatedEventArgs_DEFINED__

@protocol WAAILockScreenCallActivatedEventArgs <WAAILaunchActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACLockScreenCallUI* callUI;
@end

#endif // __WAAILockScreenCallActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUILockScreenCallActivatedEventArgs
#ifndef __WUWWebUILockScreenCallActivatedEventArgs_DEFINED__
#define __WUWWebUILockScreenCallActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUWWebUILockScreenCallActivatedEventArgs : RTObject <WAAILockScreenCallActivatedEventArgs,
                                                                WAAILaunchActivatedEventArgs,
                                                                WAAIActivatedEventArgs,
                                                                WAAIApplicationViewActivatedEventArgs,
                                                                WUWIActivatedEventArgsDeferral>
@property (readonly) WUWActivatedOperation* activatedOperation;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WACLockScreenCallUI* callUI;
@property (readonly) NSString* arguments;
@property (readonly) NSString* tileId;
@end

#endif // __WUWWebUILockScreenCallActivatedEventArgs_DEFINED__

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
@property (readonly) WUWActivatedOperation* activatedOperation;
@property (readonly) RTObject* sharedContext;
@end

#endif // __WUWWebUIRestrictedLaunchActivatedEventArgs_DEFINED__

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
@property unsigned progress;
@property (readonly) unsigned suspendedCount;
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
@property BOOL succeeded;
@property unsigned progress;
@property (readonly) WFGUID* instanceId;
@property (readonly) unsigned suspendedCount;
@property (readonly) WABBackgroundTaskRegistration* task;
@property (readonly) RTObject* triggerDetails;
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
