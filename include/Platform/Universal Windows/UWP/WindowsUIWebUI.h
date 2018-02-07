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

// WindowsUIWebUI.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIWEBUIEXPORT
#define OBJCUWPWINDOWSUIWEBUIEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIWebUI.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUWWebUICameraSettingsActivatedEventArgs, WUWWebUIContactPickerActivatedEventArgs, WUWWebUIContactCallActivatedEventArgs, WUWWebUIContactMessageActivatedEventArgs, WUWWebUIContactMapActivatedEventArgs, WUWWebUIContactPostActivatedEventArgs, WUWWebUIContactVideoCallActivatedEventArgs, WUWWebUISearchActivatedEventArgs, WUWWebUIWalletActionActivatedEventArgs, WUWWebUIAppointmentsProviderAddAppointmentActivatedEventArgs, WUWWebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs, WUWWebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs, WUWWebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs, WUWWebUIAppointmentsProviderShowTimeFrameActivatedEventArgs, WUWWebUIContactPanelActivatedEventArgs, WUWWebUIUserDataAccountProviderActivatedEventArgs, WUWWebUIDevicePairingActivatedEventArgs, WUWWebUIVoiceCommandActivatedEventArgs, WUWActivatedDeferral, WUWActivatedOperation, WUWWebUILaunchActivatedEventArgs, WUWWebUIShareTargetActivatedEventArgs, WUWWebUIFileActivatedEventArgs, WUWWebUIProtocolActivatedEventArgs, WUWWebUIProtocolForResultsActivatedEventArgs, WUWWebUIFileOpenPickerActivatedEventArgs, WUWWebUIFileSavePickerActivatedEventArgs, WUWWebUICachedFileUpdaterActivatedEventArgs, WUWWebUIDeviceActivatedEventArgs, WUWWebUILockScreenActivatedEventArgs, WUWWebUIRestrictedLaunchActivatedEventArgs, WUWWebUIFileOpenPickerContinuationEventArgs, WUWWebUIFileSavePickerContinuationEventArgs, WUWWebUIFolderPickerContinuationEventArgs, WUWWebUIWebAuthenticationBrokerContinuationEventArgs, WUWWebUIWebAccountProviderActivatedEventArgs, WUWWebUIDialReceiverActivatedEventArgs, WUWWebUIToastNotificationActivatedEventArgs, WUWWebUILockScreenComponentActivatedEventArgs, WUWWebUIPrintWorkflowForegroundTaskActivatedEventArgs, WUWWebUICommandLineActivatedEventArgs, WUWWebUIStartupTaskActivatedEventArgs, WUWWebUINavigatedOperation, WUWSuspendingDeferral, WUWSuspendingOperation, WUWSuspendingEventArgs, WUWLeavingBackgroundEventArgs, WUWEnteredBackgroundEventArgs, WUWWebUIBackgroundTaskInstanceRuntimeClass, WUWWebUIBackgroundTaskInstance, WUWWebUINavigatedDeferral, WUWWebUINavigatedEventArgs, WUWWebUIApplication, WUWHtmlPrintDocumentSource;
@protocol WUWIActivatedDeferral, WUWIActivatedOperation, WUWIActivatedEventArgsDeferral, WUWIWebUINavigatedEventArgs, WUWIWebUIBackgroundTaskInstance, WUWIWebUIBackgroundTaskInstanceStatics, WUWIWebUINavigatedDeferral, WUWIWebUINavigatedOperation, WUWIWebUIActivationStatics, WUWIWebUIActivationStatics2, WUWIWebUIActivationStatics3, WUWIHtmlPrintDocumentSource;

// Windows.UI.WebUI.PrintContent
enum _WUWPrintContent {
    WUWPrintContentAllPages = 0,
    WUWPrintContentCurrentPage = 1,
    WUWPrintContentCustomPageRange = 2,
    WUWPrintContentCurrentSelection = 3,
};
typedef unsigned WUWPrintContent;

#include "WindowsFoundation.h"
#include "WindowsApplicationModelContacts.h"
#include "WindowsApplicationModelCore.h"
#include "WindowsMediaSpeechRecognition.h"
#include "WindowsApplicationModelSearch.h"
#include "WindowsStoragePickersProvider.h"
#include "WindowsSystem.h"
#include "WindowsGraphicsPrinting.h"
#include "WindowsApplicationModelContactsProvider.h"
#include "WindowsApplicationModelActivation.h"
#include "WindowsApplicationModelWallet.h"
#include "WindowsApplicationModelAppointmentsAppointmentsProvider.h"
#include "WindowsApplicationModelUserDataAccountsProvider.h"
#include "WindowsDevicesEnumeration.h"
#include "WindowsApplicationModelDataTransferShareTarget.h"
#include "WindowsStorage.h"
#include "WindowsStorageSearch.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageProvider.h"
#include "WindowsSecurityAuthenticationWeb.h"
#include "WindowsSecurityAuthenticationWebProvider.h"
#include "WindowsApplicationModel.h"
#include "WindowsApplicationModelBackground.h"
// Windows.ApplicationModel.Background.BackgroundTaskCanceledEventHandler
#ifndef __WABBackgroundTaskCanceledEventHandler__DEFINED
#define __WABBackgroundTaskCanceledEventHandler__DEFINED
typedef void(^WABBackgroundTaskCanceledEventHandler)(RTObject<WABIBackgroundTaskInstance>* sender, WABBackgroundTaskCancellationReason reason);
#endif // __WABBackgroundTaskCanceledEventHandler__DEFINED

// Windows.UI.WebUI.ActivatedEventHandler
#ifndef __WUWActivatedEventHandler__DEFINED
#define __WUWActivatedEventHandler__DEFINED
typedef void(^WUWActivatedEventHandler)(RTObject* sender, RTObject<WAAIActivatedEventArgs>* eventArgs);
#endif // __WUWActivatedEventHandler__DEFINED

// Windows.UI.WebUI.EnteredBackgroundEventHandler
#ifndef __WUWEnteredBackgroundEventHandler__DEFINED
#define __WUWEnteredBackgroundEventHandler__DEFINED
typedef void(^WUWEnteredBackgroundEventHandler)(RTObject* sender, RTObject<WAIEnteredBackgroundEventArgs>* e);
#endif // __WUWEnteredBackgroundEventHandler__DEFINED

// Windows.UI.WebUI.LeavingBackgroundEventHandler
#ifndef __WUWLeavingBackgroundEventHandler__DEFINED
#define __WUWLeavingBackgroundEventHandler__DEFINED
typedef void(^WUWLeavingBackgroundEventHandler)(RTObject* sender, RTObject<WAILeavingBackgroundEventArgs>* e);
#endif // __WUWLeavingBackgroundEventHandler__DEFINED

// Windows.UI.WebUI.NavigatedEventHandler
#ifndef __WUWNavigatedEventHandler__DEFINED
#define __WUWNavigatedEventHandler__DEFINED
typedef void(^WUWNavigatedEventHandler)(RTObject* sender, RTObject<WUWIWebUINavigatedEventArgs>* e);
#endif // __WUWNavigatedEventHandler__DEFINED

// Windows.UI.WebUI.ResumingEventHandler
#ifndef __WUWResumingEventHandler__DEFINED
#define __WUWResumingEventHandler__DEFINED
typedef void(^WUWResumingEventHandler)(RTObject* sender);
#endif // __WUWResumingEventHandler__DEFINED

// Windows.UI.WebUI.SuspendingEventHandler
#ifndef __WUWSuspendingEventHandler__DEFINED
#define __WUWSuspendingEventHandler__DEFINED
typedef void(^WUWSuspendingEventHandler)(RTObject* sender, RTObject<WAISuspendingEventArgs>* e);
#endif // __WUWSuspendingEventHandler__DEFINED


#import <Foundation/Foundation.h>

// Windows.UI.WebUI.ActivatedEventHandler
#ifndef __WUWActivatedEventHandler__DEFINED
#define __WUWActivatedEventHandler__DEFINED
typedef void(^WUWActivatedEventHandler)(RTObject* sender, RTObject<WAAIActivatedEventArgs>* eventArgs);
#endif // __WUWActivatedEventHandler__DEFINED

// Windows.UI.WebUI.ResumingEventHandler
#ifndef __WUWResumingEventHandler__DEFINED
#define __WUWResumingEventHandler__DEFINED
typedef void(^WUWResumingEventHandler)(RTObject* sender);
#endif // __WUWResumingEventHandler__DEFINED

// Windows.UI.WebUI.SuspendingEventHandler
#ifndef __WUWSuspendingEventHandler__DEFINED
#define __WUWSuspendingEventHandler__DEFINED
typedef void(^WUWSuspendingEventHandler)(RTObject* sender, RTObject<WAISuspendingEventArgs>* e);
#endif // __WUWSuspendingEventHandler__DEFINED

// Windows.UI.WebUI.LeavingBackgroundEventHandler
#ifndef __WUWLeavingBackgroundEventHandler__DEFINED
#define __WUWLeavingBackgroundEventHandler__DEFINED
typedef void(^WUWLeavingBackgroundEventHandler)(RTObject* sender, RTObject<WAILeavingBackgroundEventArgs>* e);
#endif // __WUWLeavingBackgroundEventHandler__DEFINED

// Windows.UI.WebUI.EnteredBackgroundEventHandler
#ifndef __WUWEnteredBackgroundEventHandler__DEFINED
#define __WUWEnteredBackgroundEventHandler__DEFINED
typedef void(^WUWEnteredBackgroundEventHandler)(RTObject* sender, RTObject<WAIEnteredBackgroundEventArgs>* e);
#endif // __WUWEnteredBackgroundEventHandler__DEFINED

// Windows.UI.WebUI.NavigatedEventHandler
#ifndef __WUWNavigatedEventHandler__DEFINED
#define __WUWNavigatedEventHandler__DEFINED
typedef void(^WUWNavigatedEventHandler)(RTObject* sender, RTObject<WUWIWebUINavigatedEventArgs>* e);
#endif // __WUWNavigatedEventHandler__DEFINED

// Windows.UI.WebUI.IActivatedEventArgsDeferral
#ifndef __WUWIActivatedEventArgsDeferral_DEFINED__
#define __WUWIActivatedEventArgsDeferral_DEFINED__

@protocol WUWIActivatedEventArgsDeferral
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWIActivatedEventArgsDeferral : RTObject <WUWIActivatedEventArgsDeferral>
@end

#endif // __WUWIActivatedEventArgsDeferral_DEFINED__

// Windows.UI.WebUI.IWebUINavigatedEventArgs
#ifndef __WUWIWebUINavigatedEventArgs_DEFINED__
#define __WUWIWebUINavigatedEventArgs_DEFINED__

@protocol WUWIWebUINavigatedEventArgs
@property (readonly) WUWWebUINavigatedOperation* navigatedOperation;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWIWebUINavigatedEventArgs : RTObject <WUWIWebUINavigatedEventArgs>
@end

#endif // __WUWIWebUINavigatedEventArgs_DEFINED__

// Windows.UI.WebUI.IWebUIBackgroundTaskInstance
#ifndef __WUWIWebUIBackgroundTaskInstance_DEFINED__
#define __WUWIWebUIBackgroundTaskInstance_DEFINED__

@protocol WUWIWebUIBackgroundTaskInstance
@property BOOL succeeded;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWIWebUIBackgroundTaskInstance : RTObject <WUWIWebUIBackgroundTaskInstance>
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIActivatedEventArgs : RTObject <WAAIActivatedEventArgs>
@end

#endif // __WAAIActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ICameraSettingsActivatedEventArgs
#ifndef __WAAICameraSettingsActivatedEventArgs_DEFINED__
#define __WAAICameraSettingsActivatedEventArgs_DEFINED__

@protocol WAAICameraSettingsActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) RTObject* videoDeviceController;
@property (readonly) RTObject* videoDeviceExtension;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAICameraSettingsActivatedEventArgs : RTObject <WAAICameraSettingsActivatedEventArgs>
@end

#endif // __WAAICameraSettingsActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUICameraSettingsActivatedEventArgs
#ifndef __WUWWebUICameraSettingsActivatedEventArgs_DEFINED__
#define __WUWWebUICameraSettingsActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUICameraSettingsActivatedEventArgs : RTObject <WAAICameraSettingsActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) RTObject* videoDeviceController;
@property (readonly) RTObject* videoDeviceExtension;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUICameraSettingsActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactPickerActivatedEventArgs
#ifndef __WAAIContactPickerActivatedEventArgs_DEFINED__
#define __WAAIContactPickerActivatedEventArgs_DEFINED__

@protocol WAAIContactPickerActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WACPContactPickerUI* contactPickerUI;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIContactPickerActivatedEventArgs : RTObject <WAAIContactPickerActivatedEventArgs>
@end

#endif // __WAAIContactPickerActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIContactPickerActivatedEventArgs
#ifndef __WUWWebUIContactPickerActivatedEventArgs_DEFINED__
#define __WUWWebUIContactPickerActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIContactPickerActivatedEventArgs : RTObject <WAAIContactPickerActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WACPContactPickerUI* contactPickerUI;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIContactPickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactActivatedEventArgs
#ifndef __WAAIContactActivatedEventArgs_DEFINED__
#define __WAAIContactActivatedEventArgs_DEFINED__

@protocol WAAIContactActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * verb;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIContactActivatedEventArgs : RTObject <WAAIContactActivatedEventArgs>
@end

#endif // __WAAIContactActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactCallActivatedEventArgs
#ifndef __WAAIContactCallActivatedEventArgs_DEFINED__
#define __WAAIContactCallActivatedEventArgs_DEFINED__

@protocol WAAIContactCallActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString * serviceId;
@property (readonly) NSString * serviceUserId;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIContactCallActivatedEventArgs : RTObject <WAAIContactCallActivatedEventArgs>
@end

#endif // __WAAIContactCallActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIContactCallActivatedEventArgs
#ifndef __WUWWebUIContactCallActivatedEventArgs_DEFINED__
#define __WUWWebUIContactCallActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIContactCallActivatedEventArgs : RTObject <WAAIContactCallActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString * verb;
@property (readonly) WACContact* contact;
@property (readonly) NSString * serviceId;
@property (readonly) NSString * serviceUserId;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIContactCallActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactMessageActivatedEventArgs
#ifndef __WAAIContactMessageActivatedEventArgs_DEFINED__
#define __WAAIContactMessageActivatedEventArgs_DEFINED__

@protocol WAAIContactMessageActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString * serviceId;
@property (readonly) NSString * serviceUserId;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIContactMessageActivatedEventArgs : RTObject <WAAIContactMessageActivatedEventArgs>
@end

#endif // __WAAIContactMessageActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIContactMessageActivatedEventArgs
#ifndef __WUWWebUIContactMessageActivatedEventArgs_DEFINED__
#define __WUWWebUIContactMessageActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIContactMessageActivatedEventArgs : RTObject <WAAIContactMessageActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString * verb;
@property (readonly) WACContact* contact;
@property (readonly) NSString * serviceId;
@property (readonly) NSString * serviceUserId;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIContactMessageActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactMapActivatedEventArgs
#ifndef __WAAIContactMapActivatedEventArgs_DEFINED__
#define __WAAIContactMapActivatedEventArgs_DEFINED__

@protocol WAAIContactMapActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContactAddress* address;
@property (readonly) WACContact* contact;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIContactMapActivatedEventArgs : RTObject <WAAIContactMapActivatedEventArgs>
@end

#endif // __WAAIContactMapActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIContactMapActivatedEventArgs
#ifndef __WUWWebUIContactMapActivatedEventArgs_DEFINED__
#define __WUWWebUIContactMapActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIContactMapActivatedEventArgs : RTObject <WAAIContactMapActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString * verb;
@property (readonly) WACContactAddress* address;
@property (readonly) WACContact* contact;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIContactMapActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactPostActivatedEventArgs
#ifndef __WAAIContactPostActivatedEventArgs_DEFINED__
#define __WAAIContactPostActivatedEventArgs_DEFINED__

@protocol WAAIContactPostActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString * serviceId;
@property (readonly) NSString * serviceUserId;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIContactPostActivatedEventArgs : RTObject <WAAIContactPostActivatedEventArgs>
@end

#endif // __WAAIContactPostActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIContactPostActivatedEventArgs
#ifndef __WUWWebUIContactPostActivatedEventArgs_DEFINED__
#define __WUWWebUIContactPostActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIContactPostActivatedEventArgs : RTObject <WAAIContactPostActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString * verb;
@property (readonly) WACContact* contact;
@property (readonly) NSString * serviceId;
@property (readonly) NSString * serviceUserId;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIContactPostActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactVideoCallActivatedEventArgs
#ifndef __WAAIContactVideoCallActivatedEventArgs_DEFINED__
#define __WAAIContactVideoCallActivatedEventArgs_DEFINED__

@protocol WAAIContactVideoCallActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString * serviceId;
@property (readonly) NSString * serviceUserId;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIContactVideoCallActivatedEventArgs : RTObject <WAAIContactVideoCallActivatedEventArgs>
@end

#endif // __WAAIContactVideoCallActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIContactVideoCallActivatedEventArgs
#ifndef __WUWWebUIContactVideoCallActivatedEventArgs_DEFINED__
#define __WUWWebUIContactVideoCallActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIContactVideoCallActivatedEventArgs : RTObject <WAAIContactVideoCallActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString * verb;
@property (readonly) WACContact* contact;
@property (readonly) NSString * serviceId;
@property (readonly) NSString * serviceUserId;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIContactVideoCallActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ISearchActivatedEventArgs
#ifndef __WAAISearchActivatedEventArgs_DEFINED__
#define __WAAISearchActivatedEventArgs_DEFINED__

@protocol WAAISearchActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * language;
@property (readonly) NSString * queryText;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAISearchActivatedEventArgs : RTObject <WAAISearchActivatedEventArgs>
@end

#endif // __WAAISearchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ISearchActivatedEventArgsWithLinguisticDetails
#ifndef __WAAISearchActivatedEventArgsWithLinguisticDetails_DEFINED__
#define __WAAISearchActivatedEventArgsWithLinguisticDetails_DEFINED__

@protocol WAAISearchActivatedEventArgsWithLinguisticDetails
@property (readonly) WASSearchPaneQueryLinguisticDetails* linguisticDetails;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAISearchActivatedEventArgsWithLinguisticDetails : RTObject <WAAISearchActivatedEventArgsWithLinguisticDetails>
@end

#endif // __WAAISearchActivatedEventArgsWithLinguisticDetails_DEFINED__

// Windows.ApplicationModel.Activation.IApplicationViewActivatedEventArgs
#ifndef __WAAIApplicationViewActivatedEventArgs_DEFINED__
#define __WAAIApplicationViewActivatedEventArgs_DEFINED__

@protocol WAAIApplicationViewActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) int currentlyShownApplicationViewId;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIApplicationViewActivatedEventArgs : RTObject <WAAIApplicationViewActivatedEventArgs>
@end

#endif // __WAAIApplicationViewActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUISearchActivatedEventArgs
#ifndef __WUWWebUISearchActivatedEventArgs_DEFINED__
#define __WUWWebUISearchActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUISearchActivatedEventArgs : RTObject <WAAISearchActivatedEventArgs, WAAIActivatedEventArgs, WAAISearchActivatedEventArgsWithLinguisticDetails, WAAIApplicationViewActivatedEventArgs, WUWIActivatedEventArgsDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) NSString * language;
@property (readonly) NSString * queryText;
@property (readonly) WASSearchPaneQueryLinguisticDetails* linguisticDetails;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUISearchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IWalletActionActivatedEventArgs
#ifndef __WAAIWalletActionActivatedEventArgs_DEFINED__
#define __WAAIWalletActionActivatedEventArgs_DEFINED__

@protocol WAAIWalletActionActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * actionId;
@property (readonly) WAWWalletActionKind actionKind;
@property (readonly) NSString * itemId;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIWalletActionActivatedEventArgs : RTObject <WAAIWalletActionActivatedEventArgs>
@end

#endif // __WAAIWalletActionActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIWalletActionActivatedEventArgs
#ifndef __WUWWebUIWalletActionActivatedEventArgs_DEFINED__
#define __WUWWebUIWalletActionActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIWalletActionActivatedEventArgs : RTObject <WAAIWalletActionActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString * actionId;
@property (readonly) WAWWalletActionKind actionKind;
@property (readonly) NSString * itemId;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIWalletActionActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IAppointmentsProviderActivatedEventArgs
#ifndef __WAAIAppointmentsProviderActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * verb;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIAppointmentsProviderActivatedEventArgs : RTObject <WAAIAppointmentsProviderActivatedEventArgs>
@end

#endif // __WAAIAppointmentsProviderActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IAppointmentsProviderAddAppointmentActivatedEventArgs
#ifndef __WAAIAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderAddAppointmentActivatedEventArgs <WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAAAddAppointmentOperation* addAppointmentOperation;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIAppointmentsProviderAddAppointmentActivatedEventArgs : RTObject <WAAIAppointmentsProviderAddAppointmentActivatedEventArgs>
@end

#endif // __WAAIAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IActivatedEventArgsWithUser
#ifndef __WAAIActivatedEventArgsWithUser_DEFINED__
#define __WAAIActivatedEventArgsWithUser_DEFINED__

@protocol WAAIActivatedEventArgsWithUser <WAAIActivatedEventArgs>
@property (readonly) WSUser* user;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIActivatedEventArgsWithUser : RTObject <WAAIActivatedEventArgsWithUser>
@end

#endif // __WAAIActivatedEventArgsWithUser_DEFINED__

// Windows.UI.WebUI.WebUIAppointmentsProviderAddAppointmentActivatedEventArgs
#ifndef __WUWWebUIAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__
#define __WUWWebUIAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIAppointmentsProviderAddAppointmentActivatedEventArgs : RTObject <WAAIAppointmentsProviderAddAppointmentActivatedEventArgs, WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) NSString * verb;
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs : RTObject <WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs>
@end

#endif // __WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs
#ifndef __WUWWebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__
#define __WUWWebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs : RTObject <WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs, WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) NSString * verb;
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs : RTObject <WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs>
@end

#endif // __WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs
#ifndef __WUWWebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__
#define __WUWWebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs : RTObject <WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs, WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) NSString * verb;
@property (readonly) WAAARemoveAppointmentOperation* removeAppointmentOperation;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs
#ifndef __WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs <WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) id /* WFDateTime* */ instanceStartDate;
@property (readonly) NSString * localId;
@property (readonly) NSString * roamingId;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs : RTObject <WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs>
@end

#endif // __WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs
#ifndef __WUWWebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__
#define __WUWWebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs : RTObject <WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs, WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) NSString * verb;
@property (readonly) id /* WFDateTime* */ instanceStartDate;
@property (readonly) NSString * localId;
@property (readonly) NSString * roamingId;
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs : RTObject <WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs>
@end

#endif // __WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIAppointmentsProviderShowTimeFrameActivatedEventArgs
#ifndef __WUWWebUIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__
#define __WUWWebUIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIAppointmentsProviderShowTimeFrameActivatedEventArgs : RTObject <WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs, WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) NSString * verb;
@property (readonly) WFTimeSpan* duration;
@property (readonly) WFDateTime* timeToShow;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactPanelActivatedEventArgs
#ifndef __WAAIContactPanelActivatedEventArgs_DEFINED__
#define __WAAIContactPanelActivatedEventArgs_DEFINED__

@protocol WAAIContactPanelActivatedEventArgs
@property (readonly) WACContact* contact;
@property (readonly) WACContactPanel* contactPanel;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIContactPanelActivatedEventArgs : RTObject <WAAIContactPanelActivatedEventArgs>
@end

#endif // __WAAIContactPanelActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIContactPanelActivatedEventArgs
#ifndef __WUWWebUIContactPanelActivatedEventArgs_DEFINED__
#define __WUWWebUIContactPanelActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIContactPanelActivatedEventArgs : RTObject <WAAIContactPanelActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WACContact* contact;
@property (readonly) WACContactPanel* contactPanel;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIContactPanelActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IUserDataAccountProviderActivatedEventArgs
#ifndef __WAAIUserDataAccountProviderActivatedEventArgs_DEFINED__
#define __WAAIUserDataAccountProviderActivatedEventArgs_DEFINED__

@protocol WAAIUserDataAccountProviderActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) RTObject<WAUPIUserDataAccountProviderOperation>* operation;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIUserDataAccountProviderActivatedEventArgs : RTObject <WAAIUserDataAccountProviderActivatedEventArgs>
@end

#endif // __WAAIUserDataAccountProviderActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIUserDataAccountProviderActivatedEventArgs
#ifndef __WUWWebUIUserDataAccountProviderActivatedEventArgs_DEFINED__
#define __WUWWebUIUserDataAccountProviderActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIUserDataAccountProviderActivatedEventArgs : RTObject <WAAIUserDataAccountProviderActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) RTObject<WAUPIUserDataAccountProviderOperation>* operation;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIUserDataAccountProviderActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IDevicePairingActivatedEventArgs
#ifndef __WAAIDevicePairingActivatedEventArgs_DEFINED__
#define __WAAIDevicePairingActivatedEventArgs_DEFINED__

@protocol WAAIDevicePairingActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WDEDeviceInformation* deviceInformation;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIDevicePairingActivatedEventArgs : RTObject <WAAIDevicePairingActivatedEventArgs>
@end

#endif // __WAAIDevicePairingActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIDevicePairingActivatedEventArgs
#ifndef __WUWWebUIDevicePairingActivatedEventArgs_DEFINED__
#define __WUWWebUIDevicePairingActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIDevicePairingActivatedEventArgs : RTObject <WAAIDevicePairingActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WDEDeviceInformation* deviceInformation;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIDevicePairingActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IVoiceCommandActivatedEventArgs
#ifndef __WAAIVoiceCommandActivatedEventArgs_DEFINED__
#define __WAAIVoiceCommandActivatedEventArgs_DEFINED__

@protocol WAAIVoiceCommandActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WMSSpeechRecognitionResult* result;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIVoiceCommandActivatedEventArgs : RTObject <WAAIVoiceCommandActivatedEventArgs>
@end

#endif // __WAAIVoiceCommandActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIVoiceCommandActivatedEventArgs
#ifndef __WUWWebUIVoiceCommandActivatedEventArgs_DEFINED__
#define __WUWWebUIVoiceCommandActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIVoiceCommandActivatedEventArgs : RTObject <WAAIVoiceCommandActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WMSSpeechRecognitionResult* result;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIVoiceCommandActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.ActivatedDeferral
#ifndef __WUWActivatedDeferral_DEFINED__
#define __WUWActivatedDeferral_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWActivatedDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WUWActivatedDeferral_DEFINED__

// Windows.UI.WebUI.ActivatedOperation
#ifndef __WUWActivatedOperation_DEFINED__
#define __WUWActivatedOperation_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWActivatedOperation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WUWActivatedDeferral*)getDeferral;
@end

#endif // __WUWActivatedOperation_DEFINED__

// Windows.ApplicationModel.Activation.ILaunchActivatedEventArgs
#ifndef __WAAILaunchActivatedEventArgs_DEFINED__
#define __WAAILaunchActivatedEventArgs_DEFINED__

@protocol WAAILaunchActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * arguments;
@property (readonly) NSString * tileId;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAILaunchActivatedEventArgs : RTObject <WAAILaunchActivatedEventArgs>
@end

#endif // __WAAILaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IPrelaunchActivatedEventArgs
#ifndef __WAAIPrelaunchActivatedEventArgs_DEFINED__
#define __WAAIPrelaunchActivatedEventArgs_DEFINED__

@protocol WAAIPrelaunchActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) BOOL prelaunchActivated;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIPrelaunchActivatedEventArgs : RTObject <WAAIPrelaunchActivatedEventArgs>
@end

#endif // __WAAIPrelaunchActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUILaunchActivatedEventArgs
#ifndef __WUWWebUILaunchActivatedEventArgs_DEFINED__
#define __WUWWebUILaunchActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUILaunchActivatedEventArgs : RTObject <WAAILaunchActivatedEventArgs, WAAIActivatedEventArgs, WAAIPrelaunchActivatedEventArgs, WAAIApplicationViewActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) NSString * arguments;
@property (readonly) NSString * tileId;
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIShareTargetActivatedEventArgs : RTObject <WAAIShareTargetActivatedEventArgs>
@end

#endif // __WAAIShareTargetActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIShareTargetActivatedEventArgs
#ifndef __WUWWebUIShareTargetActivatedEventArgs_DEFINED__
#define __WUWWebUIShareTargetActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIShareTargetActivatedEventArgs : RTObject <WAAIShareTargetActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WADSShareOperation* shareOperation;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIShareTargetActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileActivatedEventArgs
#ifndef __WAAIFileActivatedEventArgs_DEFINED__
#define __WAAIFileActivatedEventArgs_DEFINED__

@protocol WAAIFileActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSArray* /* RTObject<WSIStorageItem>* */ files;
@property (readonly) NSString * verb;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIFileActivatedEventArgs : RTObject <WAAIFileActivatedEventArgs>
@end

#endif // __WAAIFileActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileActivatedEventArgsWithNeighboringFiles
#ifndef __WAAIFileActivatedEventArgsWithNeighboringFiles_DEFINED__
#define __WAAIFileActivatedEventArgsWithNeighboringFiles_DEFINED__

@protocol WAAIFileActivatedEventArgsWithNeighboringFiles <WAAIFileActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WSSStorageFileQueryResult* neighboringFilesQuery;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIFileActivatedEventArgsWithNeighboringFiles : RTObject <WAAIFileActivatedEventArgsWithNeighboringFiles>
@end

#endif // __WAAIFileActivatedEventArgsWithNeighboringFiles_DEFINED__

// Windows.UI.WebUI.WebUIFileActivatedEventArgs
#ifndef __WUWWebUIFileActivatedEventArgs_DEFINED__
#define __WUWWebUIFileActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIFileActivatedEventArgs : RTObject <WAAIFileActivatedEventArgs, WAAIActivatedEventArgs, WAAIApplicationViewActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIFileActivatedEventArgsWithNeighboringFiles, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) NSArray* /* RTObject<WSIStorageItem>* */ files;
@property (readonly) NSString * verb;
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIProtocolActivatedEventArgs : RTObject <WAAIProtocolActivatedEventArgs>
@end

#endif // __WAAIProtocolActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData
#ifndef __WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData_DEFINED__
#define __WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData_DEFINED__

@protocol WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData <WAAIActivatedEventArgs>
@property (readonly) NSString * callerPackageFamilyName;
@property (readonly) WFCValueSet* data;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData : RTObject <WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData>
@end

#endif // __WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData_DEFINED__

// Windows.UI.WebUI.WebUIProtocolActivatedEventArgs
#ifndef __WUWWebUIProtocolActivatedEventArgs_DEFINED__
#define __WUWWebUIProtocolActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIProtocolActivatedEventArgs : RTObject <WAAIProtocolActivatedEventArgs, WAAIActivatedEventArgs, WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData, WAAIApplicationViewActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) WFUri* uri;
@property (readonly) NSString * callerPackageFamilyName;
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIProtocolForResultsActivatedEventArgs : RTObject <WAAIProtocolForResultsActivatedEventArgs>
@end

#endif // __WAAIProtocolForResultsActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIProtocolForResultsActivatedEventArgs
#ifndef __WUWWebUIProtocolForResultsActivatedEventArgs_DEFINED__
#define __WUWWebUIProtocolForResultsActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIProtocolForResultsActivatedEventArgs : RTObject <WAAIProtocolForResultsActivatedEventArgs, WAAIActivatedEventArgs, WAAIProtocolActivatedEventArgs, WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData, WAAIApplicationViewActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) WFUri* uri;
@property (readonly) NSString * callerPackageFamilyName;
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIFileOpenPickerActivatedEventArgs : RTObject <WAAIFileOpenPickerActivatedEventArgs>
@end

#endif // __WAAIFileOpenPickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileOpenPickerActivatedEventArgs2
#ifndef __WAAIFileOpenPickerActivatedEventArgs2_DEFINED__
#define __WAAIFileOpenPickerActivatedEventArgs2_DEFINED__

@protocol WAAIFileOpenPickerActivatedEventArgs2
@property (readonly) NSString * callerPackageFamilyName;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIFileOpenPickerActivatedEventArgs2 : RTObject <WAAIFileOpenPickerActivatedEventArgs2>
@end

#endif // __WAAIFileOpenPickerActivatedEventArgs2_DEFINED__

// Windows.UI.WebUI.WebUIFileOpenPickerActivatedEventArgs
#ifndef __WUWWebUIFileOpenPickerActivatedEventArgs_DEFINED__
#define __WUWWebUIFileOpenPickerActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIFileOpenPickerActivatedEventArgs : RTObject <WAAIFileOpenPickerActivatedEventArgs, WAAIActivatedEventArgs, WAAIFileOpenPickerActivatedEventArgs2, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WSPPFileOpenPickerUI* fileOpenPickerUI;
@property (readonly) NSString * callerPackageFamilyName;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIFileOpenPickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileSavePickerActivatedEventArgs
#ifndef __WAAIFileSavePickerActivatedEventArgs_DEFINED__
#define __WAAIFileSavePickerActivatedEventArgs_DEFINED__

@protocol WAAIFileSavePickerActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WSPPFileSavePickerUI* fileSavePickerUI;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIFileSavePickerActivatedEventArgs : RTObject <WAAIFileSavePickerActivatedEventArgs>
@end

#endif // __WAAIFileSavePickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileSavePickerActivatedEventArgs2
#ifndef __WAAIFileSavePickerActivatedEventArgs2_DEFINED__
#define __WAAIFileSavePickerActivatedEventArgs2_DEFINED__

@protocol WAAIFileSavePickerActivatedEventArgs2
@property (readonly) NSString * callerPackageFamilyName;
@property (readonly) NSString * enterpriseId;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIFileSavePickerActivatedEventArgs2 : RTObject <WAAIFileSavePickerActivatedEventArgs2>
@end

#endif // __WAAIFileSavePickerActivatedEventArgs2_DEFINED__

// Windows.UI.WebUI.WebUIFileSavePickerActivatedEventArgs
#ifndef __WUWWebUIFileSavePickerActivatedEventArgs_DEFINED__
#define __WUWWebUIFileSavePickerActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIFileSavePickerActivatedEventArgs : RTObject <WAAIFileSavePickerActivatedEventArgs, WAAIActivatedEventArgs, WAAIFileSavePickerActivatedEventArgs2, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WSPPFileSavePickerUI* fileSavePickerUI;
@property (readonly) NSString * callerPackageFamilyName;
@property (readonly) NSString * enterpriseId;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIFileSavePickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ICachedFileUpdaterActivatedEventArgs
#ifndef __WAAICachedFileUpdaterActivatedEventArgs_DEFINED__
#define __WAAICachedFileUpdaterActivatedEventArgs_DEFINED__

@protocol WAAICachedFileUpdaterActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WSPCachedFileUpdaterUI* cachedFileUpdaterUI;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAICachedFileUpdaterActivatedEventArgs : RTObject <WAAICachedFileUpdaterActivatedEventArgs>
@end

#endif // __WAAICachedFileUpdaterActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUICachedFileUpdaterActivatedEventArgs
#ifndef __WUWWebUICachedFileUpdaterActivatedEventArgs_DEFINED__
#define __WUWWebUICachedFileUpdaterActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUICachedFileUpdaterActivatedEventArgs : RTObject <WAAICachedFileUpdaterActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WSPCachedFileUpdaterUI* cachedFileUpdaterUI;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUICachedFileUpdaterActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IDeviceActivatedEventArgs
#ifndef __WAAIDeviceActivatedEventArgs_DEFINED__
#define __WAAIDeviceActivatedEventArgs_DEFINED__

@protocol WAAIDeviceActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * deviceInformationId;
@property (readonly) NSString * verb;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIDeviceActivatedEventArgs : RTObject <WAAIDeviceActivatedEventArgs>
@end

#endif // __WAAIDeviceActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIDeviceActivatedEventArgs
#ifndef __WUWWebUIDeviceActivatedEventArgs_DEFINED__
#define __WUWWebUIDeviceActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIDeviceActivatedEventArgs : RTObject <WAAIDeviceActivatedEventArgs, WAAIActivatedEventArgs, WAAIApplicationViewActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) NSString * deviceInformationId;
@property (readonly) NSString * verb;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIDeviceActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ILockScreenActivatedEventArgs
#ifndef __WAAILockScreenActivatedEventArgs_DEFINED__
#define __WAAILockScreenActivatedEventArgs_DEFINED__

@protocol WAAILockScreenActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) RTObject* info;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAILockScreenActivatedEventArgs : RTObject <WAAILockScreenActivatedEventArgs>
@end

#endif // __WAAILockScreenActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUILockScreenActivatedEventArgs
#ifndef __WUWWebUILockScreenActivatedEventArgs_DEFINED__
#define __WUWWebUILockScreenActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUILockScreenActivatedEventArgs : RTObject <WAAILockScreenActivatedEventArgs, WAAIActivatedEventArgs, WAAIApplicationViewActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIRestrictedLaunchActivatedEventArgs : RTObject <WAAIRestrictedLaunchActivatedEventArgs>
@end

#endif // __WAAIRestrictedLaunchActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIRestrictedLaunchActivatedEventArgs
#ifndef __WUWWebUIRestrictedLaunchActivatedEventArgs_DEFINED__
#define __WUWWebUIRestrictedLaunchActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIRestrictedLaunchActivatedEventArgs : RTObject <WAAIRestrictedLaunchActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIContinuationActivatedEventArgs : RTObject <WAAIContinuationActivatedEventArgs>
@end

#endif // __WAAIContinuationActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileOpenPickerContinuationEventArgs
#ifndef __WAAIFileOpenPickerContinuationEventArgs_DEFINED__
#define __WAAIFileOpenPickerContinuationEventArgs_DEFINED__

@protocol WAAIFileOpenPickerContinuationEventArgs <WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) NSArray* /* WSStorageFile* */ files;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIFileOpenPickerContinuationEventArgs : RTObject <WAAIFileOpenPickerContinuationEventArgs>
@end

#endif // __WAAIFileOpenPickerContinuationEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIFileOpenPickerContinuationEventArgs
#ifndef __WUWWebUIFileOpenPickerContinuationEventArgs_DEFINED__
#define __WUWWebUIFileOpenPickerContinuationEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIFileOpenPickerContinuationEventArgs : RTObject <WAAIFileOpenPickerContinuationEventArgs, WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WFCValueSet* continuationData;
@property (readonly) NSArray* /* WSStorageFile* */ files;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIFileOpenPickerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileSavePickerContinuationEventArgs
#ifndef __WAAIFileSavePickerContinuationEventArgs_DEFINED__
#define __WAAIFileSavePickerContinuationEventArgs_DEFINED__

@protocol WAAIFileSavePickerContinuationEventArgs <WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WSStorageFile* file;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIFileSavePickerContinuationEventArgs : RTObject <WAAIFileSavePickerContinuationEventArgs>
@end

#endif // __WAAIFileSavePickerContinuationEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIFileSavePickerContinuationEventArgs
#ifndef __WUWWebUIFileSavePickerContinuationEventArgs_DEFINED__
#define __WUWWebUIFileSavePickerContinuationEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIFileSavePickerContinuationEventArgs : RTObject <WAAIFileSavePickerContinuationEventArgs, WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIFolderPickerContinuationEventArgs : RTObject <WAAIFolderPickerContinuationEventArgs>
@end

#endif // __WAAIFolderPickerContinuationEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIFolderPickerContinuationEventArgs
#ifndef __WUWWebUIFolderPickerContinuationEventArgs_DEFINED__
#define __WUWWebUIFolderPickerContinuationEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIFolderPickerContinuationEventArgs : RTObject <WAAIFolderPickerContinuationEventArgs, WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIWebAuthenticationBrokerContinuationEventArgs : RTObject <WAAIWebAuthenticationBrokerContinuationEventArgs>
@end

#endif // __WAAIWebAuthenticationBrokerContinuationEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIWebAuthenticationBrokerContinuationEventArgs
#ifndef __WUWWebUIWebAuthenticationBrokerContinuationEventArgs_DEFINED__
#define __WUWWebUIWebAuthenticationBrokerContinuationEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIWebAuthenticationBrokerContinuationEventArgs : RTObject <WAAIWebAuthenticationBrokerContinuationEventArgs, WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIWebAccountProviderActivatedEventArgs : RTObject <WAAIWebAccountProviderActivatedEventArgs>
@end

#endif // __WAAIWebAccountProviderActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIWebAccountProviderActivatedEventArgs
#ifndef __WUWWebUIWebAccountProviderActivatedEventArgs_DEFINED__
#define __WUWWebUIWebAccountProviderActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIWebAccountProviderActivatedEventArgs : RTObject <WAAIWebAccountProviderActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) RTObject<WSAWPIWebAccountProviderOperation>* operation;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIWebAccountProviderActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IDialReceiverActivatedEventArgs
#ifndef __WAAIDialReceiverActivatedEventArgs_DEFINED__
#define __WAAIDialReceiverActivatedEventArgs_DEFINED__

@protocol WAAIDialReceiverActivatedEventArgs <WAAILaunchActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) NSString * appName;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIDialReceiverActivatedEventArgs : RTObject <WAAIDialReceiverActivatedEventArgs>
@end

#endif // __WAAIDialReceiverActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIDialReceiverActivatedEventArgs
#ifndef __WUWWebUIDialReceiverActivatedEventArgs_DEFINED__
#define __WUWWebUIDialReceiverActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIDialReceiverActivatedEventArgs : RTObject <WAAIDialReceiverActivatedEventArgs, WAAILaunchActivatedEventArgs, WAAIActivatedEventArgs, WAAIApplicationViewActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) NSString * appName;
@property (readonly) NSString * arguments;
@property (readonly) NSString * tileId;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIDialReceiverActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IToastNotificationActivatedEventArgs
#ifndef __WAAIToastNotificationActivatedEventArgs_DEFINED__
#define __WAAIToastNotificationActivatedEventArgs_DEFINED__

@protocol WAAIToastNotificationActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * argument;
@property (readonly) WFCValueSet* userInput;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIToastNotificationActivatedEventArgs : RTObject <WAAIToastNotificationActivatedEventArgs>
@end

#endif // __WAAIToastNotificationActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIToastNotificationActivatedEventArgs
#ifndef __WUWWebUIToastNotificationActivatedEventArgs_DEFINED__
#define __WUWWebUIToastNotificationActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIToastNotificationActivatedEventArgs : RTObject <WAAIToastNotificationActivatedEventArgs, WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) NSString * argument;
@property (readonly) WFCValueSet* userInput;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIToastNotificationActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUILockScreenComponentActivatedEventArgs
#ifndef __WUWWebUILockScreenComponentActivatedEventArgs_DEFINED__
#define __WUWWebUILockScreenComponentActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUILockScreenComponentActivatedEventArgs : RTObject <WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUILockScreenComponentActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIPrintWorkflowForegroundTaskActivatedEventArgs
#ifndef __WUWWebUIPrintWorkflowForegroundTaskActivatedEventArgs_DEFINED__
#define __WUWWebUIPrintWorkflowForegroundTaskActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIPrintWorkflowForegroundTaskActivatedEventArgs : RTObject <WAAIActivatedEventArgs, WUWIActivatedEventArgsDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIPrintWorkflowForegroundTaskActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ICommandLineActivatedEventArgs
#ifndef __WAAICommandLineActivatedEventArgs_DEFINED__
#define __WAAICommandLineActivatedEventArgs_DEFINED__

@protocol WAAICommandLineActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WAACommandLineActivationOperation* operation;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAICommandLineActivatedEventArgs : RTObject <WAAICommandLineActivatedEventArgs>
@end

#endif // __WAAICommandLineActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUICommandLineActivatedEventArgs
#ifndef __WUWWebUICommandLineActivatedEventArgs_DEFINED__
#define __WUWWebUICommandLineActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUICommandLineActivatedEventArgs : RTObject <WAAICommandLineActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser, WUWIActivatedEventArgsDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WAACommandLineActivationOperation* operation;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUICommandLineActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IStartupTaskActivatedEventArgs
#ifndef __WAAIStartupTaskActivatedEventArgs_DEFINED__
#define __WAAIStartupTaskActivatedEventArgs_DEFINED__

@protocol WAAIStartupTaskActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * taskId;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAAIStartupTaskActivatedEventArgs : RTObject <WAAIStartupTaskActivatedEventArgs>
@end

#endif // __WAAIStartupTaskActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIStartupTaskActivatedEventArgs
#ifndef __WUWWebUIStartupTaskActivatedEventArgs_DEFINED__
#define __WUWWebUIStartupTaskActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIStartupTaskActivatedEventArgs : RTObject <WAAIStartupTaskActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser, WUWIActivatedEventArgsDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) NSString * taskId;
@property (readonly) WUWActivatedOperation* activatedOperation;
@end

#endif // __WUWWebUIStartupTaskActivatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUINavigatedOperation
#ifndef __WUWWebUINavigatedOperation_DEFINED__
#define __WUWWebUINavigatedOperation_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUINavigatedOperation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WUWWebUINavigatedDeferral*)getDeferral;
@end

#endif // __WUWWebUINavigatedOperation_DEFINED__

// Windows.ApplicationModel.ISuspendingDeferral
#ifndef __WAISuspendingDeferral_DEFINED__
#define __WAISuspendingDeferral_DEFINED__

@protocol WAISuspendingDeferral
- (void)complete;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAISuspendingDeferral : RTObject <WAISuspendingDeferral>
@end

#endif // __WAISuspendingDeferral_DEFINED__

// Windows.UI.WebUI.SuspendingDeferral
#ifndef __WUWSuspendingDeferral_DEFINED__
#define __WUWSuspendingDeferral_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWSuspendingDeferral : RTObject <WAISuspendingDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAISuspendingOperation : RTObject <WAISuspendingOperation>
@end

#endif // __WAISuspendingOperation_DEFINED__

// Windows.UI.WebUI.SuspendingOperation
#ifndef __WUWSuspendingOperation_DEFINED__
#define __WUWSuspendingOperation_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWSuspendingOperation : RTObject <WAISuspendingOperation>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAISuspendingEventArgs : RTObject <WAISuspendingEventArgs>
@end

#endif // __WAISuspendingEventArgs_DEFINED__

// Windows.UI.WebUI.SuspendingEventArgs
#ifndef __WUWSuspendingEventArgs_DEFINED__
#define __WUWSuspendingEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWSuspendingEventArgs : RTObject <WAISuspendingEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WASuspendingOperation* suspendingOperation;
@end

#endif // __WUWSuspendingEventArgs_DEFINED__

// Windows.ApplicationModel.ILeavingBackgroundEventArgs
#ifndef __WAILeavingBackgroundEventArgs_DEFINED__
#define __WAILeavingBackgroundEventArgs_DEFINED__

@protocol WAILeavingBackgroundEventArgs
- (WFDeferral*)getDeferral;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAILeavingBackgroundEventArgs : RTObject <WAILeavingBackgroundEventArgs>
@end

#endif // __WAILeavingBackgroundEventArgs_DEFINED__

// Windows.UI.WebUI.LeavingBackgroundEventArgs
#ifndef __WUWLeavingBackgroundEventArgs_DEFINED__
#define __WUWLeavingBackgroundEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWLeavingBackgroundEventArgs : RTObject <WAILeavingBackgroundEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WFDeferral*)getDeferral;
@end

#endif // __WUWLeavingBackgroundEventArgs_DEFINED__

// Windows.ApplicationModel.IEnteredBackgroundEventArgs
#ifndef __WAIEnteredBackgroundEventArgs_DEFINED__
#define __WAIEnteredBackgroundEventArgs_DEFINED__

@protocol WAIEnteredBackgroundEventArgs
- (WFDeferral*)getDeferral;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WAIEnteredBackgroundEventArgs : RTObject <WAIEnteredBackgroundEventArgs>
@end

#endif // __WAIEnteredBackgroundEventArgs_DEFINED__

// Windows.UI.WebUI.EnteredBackgroundEventArgs
#ifndef __WUWEnteredBackgroundEventArgs_DEFINED__
#define __WUWEnteredBackgroundEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWEnteredBackgroundEventArgs : RTObject <WAIEnteredBackgroundEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WFDeferral*)getDeferral;
@end

#endif // __WUWEnteredBackgroundEventArgs_DEFINED__

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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WABIBackgroundTaskInstance : RTObject <WABIBackgroundTaskInstance>
@end

#endif // __WABIBackgroundTaskInstance_DEFINED__

// Windows.UI.WebUI.WebUIBackgroundTaskInstanceRuntimeClass
#ifndef __WUWWebUIBackgroundTaskInstanceRuntimeClass_DEFINED__
#define __WUWWebUIBackgroundTaskInstanceRuntimeClass_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIBackgroundTaskInstanceRuntimeClass : RTObject <WUWIWebUIBackgroundTaskInstance, WABIBackgroundTaskInstance>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIBackgroundTaskInstance : RTObject
+ (RTObject<WUWIWebUIBackgroundTaskInstance>*)current;
@end

#endif // __WUWWebUIBackgroundTaskInstance_DEFINED__

// Windows.UI.WebUI.WebUINavigatedDeferral
#ifndef __WUWWebUINavigatedDeferral_DEFINED__
#define __WUWWebUINavigatedDeferral_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUINavigatedDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WUWWebUINavigatedDeferral_DEFINED__

// Windows.UI.WebUI.WebUINavigatedEventArgs
#ifndef __WUWWebUINavigatedEventArgs_DEFINED__
#define __WUWWebUINavigatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUINavigatedEventArgs : RTObject <WUWIWebUINavigatedEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUWWebUINavigatedOperation* navigatedOperation;
@end

#endif // __WUWWebUINavigatedEventArgs_DEFINED__

// Windows.UI.WebUI.WebUIApplication
#ifndef __WUWWebUIApplication_DEFINED__
#define __WUWWebUIApplication_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWWebUIApplication : RTObject
+ (void)requestRestartAsync:(NSString *)launchArguments success:(void (^)(WACAppRestartFailureReason))success failure:(void (^)(NSError*))failure;
+ (void)requestRestartForUserAsync:(WSUser*)user launchArguments:(NSString *)launchArguments success:(void (^)(WACAppRestartFailureReason))success failure:(void (^)(NSError*))failure;
+ (void)enablePrelaunch:(BOOL)value;
+ (EventRegistrationToken)addEnteredBackgroundEvent:(WUWEnteredBackgroundEventHandler)del;
+ (void)removeEnteredBackgroundEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addLeavingBackgroundEvent:(WUWLeavingBackgroundEventHandler)del;
+ (void)removeLeavingBackgroundEvent:(EventRegistrationToken)tok;
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

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WGPIPrintDocumentSource : RTObject <WGPIPrintDocumentSource>
@end

#endif // __WGPIPrintDocumentSource_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.UI.WebUI.HtmlPrintDocumentSource
#ifndef __WUWHtmlPrintDocumentSource_DEFINED__
#define __WUWHtmlPrintDocumentSource_DEFINED__

OBJCUWPWINDOWSUIWEBUIEXPORT
@interface WUWHtmlPrintDocumentSource : RTObject <WGPIPrintDocumentSource, WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property float topMargin;
@property BOOL shrinkToFit;
@property float rightMargin;
@property float percentScale;
@property float leftMargin;
@property BOOL enableHeaderFooter;
@property WUWPrintContent content;
@property float bottomMargin;
@property (readonly) NSString * pageRange;
- (BOOL)trySetPageRange:(NSString *)strPageRange;
- (void)close;
@end

#endif // __WUWHtmlPrintDocumentSource_DEFINED__

