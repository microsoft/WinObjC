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

// WindowsApplicationModelActivation.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAACameraSettingsActivatedEventArgs, WAAContactPickerActivatedEventArgs, WAAContactCallActivatedEventArgs, WAAContactMessageActivatedEventArgs, WAAContactMapActivatedEventArgs, WAAContactPostActivatedEventArgs, WAAContactVideoCallActivatedEventArgs, WAAWalletActionActivatedEventArgs, WAAAppointmentsProviderAddAppointmentActivatedEventArgs, WAAAppointmentsProviderReplaceAppointmentActivatedEventArgs, WAAAppointmentsProviderRemoveAppointmentActivatedEventArgs, WAAAppointmentsProviderShowAppointmentDetailsActivatedEventArgs, WAAAppointmentsProviderShowTimeFrameActivatedEventArgs, WAABackgroundActivatedEventArgs, WAAContactPanelActivatedEventArgs, WAAUserDataAccountProviderActivatedEventArgs, WAASplashScreen, WAATileActivatedInfo, WAALaunchActivatedEventArgs, WAASearchActivatedEventArgs, WAAShareTargetActivatedEventArgs, WAAFileActivatedEventArgs, WAAProtocolActivatedEventArgs, WAAProtocolForResultsActivatedEventArgs, WAAFileOpenPickerActivatedEventArgs, WAAFileSavePickerActivatedEventArgs, WAACachedFileUpdaterActivatedEventArgs, WAADeviceActivatedEventArgs, WAAPickerReturnedActivatedEventArgs, WAARestrictedLaunchActivatedEventArgs, WAALockScreenActivatedEventArgs, WAAFileOpenPickerContinuationEventArgs, WAAFileSavePickerContinuationEventArgs, WAAFolderPickerContinuationEventArgs, WAAWebAuthenticationBrokerContinuationEventArgs, WAAWebAccountProviderActivatedEventArgs, WAAToastNotificationActivatedEventArgs, WAADialReceiverActivatedEventArgs, WAALockScreenComponentActivatedEventArgs, WAACommandLineActivationOperation, WAACommandLineActivatedEventArgs, WAAStartupTaskActivatedEventArgs, WAADevicePairingActivatedEventArgs, WAAVoiceCommandActivatedEventArgs;
@protocol WAAIBackgroundActivatedEventArgs, WAAIContactPanelActivatedEventArgs, WAAISplashScreen, WAAIActivatedEventArgs, WAAICameraSettingsActivatedEventArgs, WAAIContactPickerActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIContactCallActivatedEventArgs, WAAIContactMessageActivatedEventArgs, WAAIContactMapActivatedEventArgs, WAAIContactPostActivatedEventArgs, WAAIContactVideoCallActivatedEventArgs, WAAIContactsProviderActivatedEventArgs, WAAIWalletActionActivatedEventArgs, WAAIAppointmentsProviderActivatedEventArgs, WAAIAppointmentsProviderAddAppointmentActivatedEventArgs, WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs, WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs, WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs, WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs, WAAIUserDataAccountProviderActivatedEventArgs, WAAIActivatedEventArgsWithUser, WAAIApplicationViewActivatedEventArgs, WAAIViewSwitcherProvider, WAAIPrelaunchActivatedEventArgs, WAAILaunchActivatedEventArgs, WAAILaunchActivatedEventArgs2, WAAISearchActivatedEventArgs, WAAISearchActivatedEventArgsWithLinguisticDetails, WAAIShareTargetActivatedEventArgs, WAAIFileActivatedEventArgs, WAAIFileActivatedEventArgsWithNeighboringFiles, WAAIFileActivatedEventArgsWithCallerPackageFamilyName, WAAIProtocolActivatedEventArgs, WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData, WAAIProtocolForResultsActivatedEventArgs, WAAIFileOpenPickerActivatedEventArgs, WAAIFileOpenPickerActivatedEventArgs2, WAAIFileSavePickerActivatedEventArgs, WAAIFileSavePickerActivatedEventArgs2, WAAICachedFileUpdaterActivatedEventArgs, WAAIDeviceActivatedEventArgs, WAAIPickerReturnedActivatedEventArgs, WAAIRestrictedLaunchActivatedEventArgs, WAAILockScreenActivatedEventArgs, WAAIContinuationActivatedEventArgs, WAAIFileOpenPickerContinuationEventArgs, WAAIFileSavePickerContinuationEventArgs, WAAIFolderPickerContinuationEventArgs, WAAIWebAuthenticationBrokerContinuationEventArgs, WAAIWebAccountProviderActivatedEventArgs, WAAIToastNotificationActivatedEventArgs, WAAIDialReceiverActivatedEventArgs, WAAITileActivatedInfo, WAAICommandLineActivationOperation, WAAICommandLineActivatedEventArgs, WAAIStartupTaskActivatedEventArgs, WAAIDevicePairingActivatedEventArgs, WAAIVoiceCommandActivatedEventArgs;

// Windows.ApplicationModel.Activation.ApplicationExecutionState
enum _WAAApplicationExecutionState {
    WAAApplicationExecutionStateNotRunning = 0,
    WAAApplicationExecutionStateRunning = 1,
    WAAApplicationExecutionStateSuspended = 2,
    WAAApplicationExecutionStateTerminated = 3,
    WAAApplicationExecutionStateClosedByUser = 4,
};
typedef unsigned WAAApplicationExecutionState;

// Windows.ApplicationModel.Activation.ActivationKind
enum _WAAActivationKind {
    WAAActivationKindLaunch = 0,
    WAAActivationKindSearch = 1,
    WAAActivationKindShareTarget = 2,
    WAAActivationKindFile = 3,
    WAAActivationKindProtocol = 4,
    WAAActivationKindFileOpenPicker = 5,
    WAAActivationKindFileSavePicker = 6,
    WAAActivationKindCachedFileUpdater = 7,
    WAAActivationKindContactPicker = 8,
    WAAActivationKindDevice = 9,
    WAAActivationKindPrintTaskSettings = 10,
    WAAActivationKindCameraSettings = 11,
    WAAActivationKindRestrictedLaunch = 12,
    WAAActivationKindAppointmentsProvider = 13,
    WAAActivationKindContact = 14,
    WAAActivationKindLockScreenCall = 15,
    WAAActivationKindVoiceCommand = 16,
    WAAActivationKindLockScreen = 17,
    WAAActivationKindPickerReturned = 1000,
    WAAActivationKindWalletAction = 1001,
    WAAActivationKindPickFileContinuation = 1002,
    WAAActivationKindPickSaveFileContinuation = 1003,
    WAAActivationKindPickFolderContinuation = 1004,
    WAAActivationKindWebAuthenticationBrokerContinuation = 1005,
    WAAActivationKindWebAccountProvider = 1006,
    WAAActivationKindComponentUI = 1007,
    WAAActivationKindProtocolForResults = 1009,
    WAAActivationKindToastNotification = 1010,
    WAAActivationKindPrint3DWorkflow = 1011,
    WAAActivationKindDialReceiver = 1012,
    WAAActivationKindDevicePairing = 1013,
    WAAActivationKindUserDataAccountsProvider = 1014,
    WAAActivationKindFilePickerExperience = 1015,
    WAAActivationKindLockScreenComponent = 1016,
    WAAActivationKindContactPanel = 1017,
    WAAActivationKindPrintWorkflowForegroundTask = 1018,
    WAAActivationKindGameUIProvider = 1019,
    WAAActivationKindStartupTask = 1020,
    WAAActivationKindCommandLineLaunch = 1021,
};
typedef unsigned WAAActivationKind;

#include "WindowsApplicationModelUserDataAccountsProvider.h"
#include "WindowsApplicationModelContactsProvider.h"
#include "WindowsStoragePickersProvider.h"
#include "WindowsSystem.h"
#include "WindowsApplicationModelBackground.h"
#include "WindowsApplicationModelContacts.h"
#include "WindowsFoundation.h"
#include "WindowsUINotifications.h"
#include "WindowsApplicationModelAppointmentsAppointmentsProvider.h"
#include "WindowsApplicationModelWallet.h"
#include "WindowsDevicesEnumeration.h"
#include "WindowsUIViewManagement.h"
#include "WindowsMediaSpeechRecognition.h"
#include "WindowsApplicationModelSearch.h"
#include "WindowsApplicationModelDataTransferShareTarget.h"
#include "WindowsStorage.h"
#include "WindowsStorageSearch.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageProvider.h"
#include "WindowsSecurityAuthenticationWeb.h"
#include "WindowsSecurityAuthenticationWebProvider.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Activation.IBackgroundActivatedEventArgs
#ifndef __WAAIBackgroundActivatedEventArgs_DEFINED__
#define __WAAIBackgroundActivatedEventArgs_DEFINED__

@protocol WAAIBackgroundActivatedEventArgs
@property (readonly) RTObject<WABIBackgroundTaskInstance>* taskInstance;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIBackgroundActivatedEventArgs : RTObject <WAAIBackgroundActivatedEventArgs>
@end

#endif // __WAAIBackgroundActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactPanelActivatedEventArgs
#ifndef __WAAIContactPanelActivatedEventArgs_DEFINED__
#define __WAAIContactPanelActivatedEventArgs_DEFINED__

@protocol WAAIContactPanelActivatedEventArgs
@property (readonly) WACContact* contact;
@property (readonly) WACContactPanel* contactPanel;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIContactPanelActivatedEventArgs : RTObject <WAAIContactPanelActivatedEventArgs>
@end

#endif // __WAAIContactPanelActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IActivatedEventArgs
#ifndef __WAAIActivatedEventArgs_DEFINED__
#define __WAAIActivatedEventArgs_DEFINED__

@protocol WAAIActivatedEventArgs
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
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

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAICameraSettingsActivatedEventArgs : RTObject <WAAICameraSettingsActivatedEventArgs>
@end

#endif // __WAAICameraSettingsActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactPickerActivatedEventArgs
#ifndef __WAAIContactPickerActivatedEventArgs_DEFINED__
#define __WAAIContactPickerActivatedEventArgs_DEFINED__

@protocol WAAIContactPickerActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WACPContactPickerUI* contactPickerUI;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIContactPickerActivatedEventArgs : RTObject <WAAIContactPickerActivatedEventArgs>
@end

#endif // __WAAIContactPickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactActivatedEventArgs
#ifndef __WAAIContactActivatedEventArgs_DEFINED__
#define __WAAIContactActivatedEventArgs_DEFINED__

@protocol WAAIContactActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * verb;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
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

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIContactCallActivatedEventArgs : RTObject <WAAIContactCallActivatedEventArgs>
@end

#endif // __WAAIContactCallActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactMessageActivatedEventArgs
#ifndef __WAAIContactMessageActivatedEventArgs_DEFINED__
#define __WAAIContactMessageActivatedEventArgs_DEFINED__

@protocol WAAIContactMessageActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString * serviceId;
@property (readonly) NSString * serviceUserId;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIContactMessageActivatedEventArgs : RTObject <WAAIContactMessageActivatedEventArgs>
@end

#endif // __WAAIContactMessageActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactMapActivatedEventArgs
#ifndef __WAAIContactMapActivatedEventArgs_DEFINED__
#define __WAAIContactMapActivatedEventArgs_DEFINED__

@protocol WAAIContactMapActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContactAddress* address;
@property (readonly) WACContact* contact;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIContactMapActivatedEventArgs : RTObject <WAAIContactMapActivatedEventArgs>
@end

#endif // __WAAIContactMapActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactPostActivatedEventArgs
#ifndef __WAAIContactPostActivatedEventArgs_DEFINED__
#define __WAAIContactPostActivatedEventArgs_DEFINED__

@protocol WAAIContactPostActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString * serviceId;
@property (readonly) NSString * serviceUserId;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIContactPostActivatedEventArgs : RTObject <WAAIContactPostActivatedEventArgs>
@end

#endif // __WAAIContactPostActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactVideoCallActivatedEventArgs
#ifndef __WAAIContactVideoCallActivatedEventArgs_DEFINED__
#define __WAAIContactVideoCallActivatedEventArgs_DEFINED__

@protocol WAAIContactVideoCallActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString * serviceId;
@property (readonly) NSString * serviceUserId;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIContactVideoCallActivatedEventArgs : RTObject <WAAIContactVideoCallActivatedEventArgs>
@end

#endif // __WAAIContactVideoCallActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactsProviderActivatedEventArgs
#ifndef __WAAIContactsProviderActivatedEventArgs_DEFINED__
#define __WAAIContactsProviderActivatedEventArgs_DEFINED__

@protocol WAAIContactsProviderActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * verb;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIContactsProviderActivatedEventArgs : RTObject <WAAIContactsProviderActivatedEventArgs>
@end

#endif // __WAAIContactsProviderActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IWalletActionActivatedEventArgs
#ifndef __WAAIWalletActionActivatedEventArgs_DEFINED__
#define __WAAIWalletActionActivatedEventArgs_DEFINED__

@protocol WAAIWalletActionActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * actionId;
@property (readonly) WAWWalletActionKind actionKind;
@property (readonly) NSString * itemId;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIWalletActionActivatedEventArgs : RTObject <WAAIWalletActionActivatedEventArgs>
@end

#endif // __WAAIWalletActionActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IAppointmentsProviderActivatedEventArgs
#ifndef __WAAIAppointmentsProviderActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * verb;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIAppointmentsProviderActivatedEventArgs : RTObject <WAAIAppointmentsProviderActivatedEventArgs>
@end

#endif // __WAAIAppointmentsProviderActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IAppointmentsProviderAddAppointmentActivatedEventArgs
#ifndef __WAAIAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderAddAppointmentActivatedEventArgs <WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAAAddAppointmentOperation* addAppointmentOperation;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIAppointmentsProviderAddAppointmentActivatedEventArgs : RTObject <WAAIAppointmentsProviderAddAppointmentActivatedEventArgs>
@end

#endif // __WAAIAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IAppointmentsProviderReplaceAppointmentActivatedEventArgs
#ifndef __WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs <WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAAReplaceAppointmentOperation* replaceAppointmentOperation;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs : RTObject <WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs>
@end

#endif // __WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IAppointmentsProviderRemoveAppointmentActivatedEventArgs
#ifndef __WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs <WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAARemoveAppointmentOperation* removeAppointmentOperation;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs : RTObject <WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs>
@end

#endif // __WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs
#ifndef __WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs <WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) id /* WFDateTime* */ instanceStartDate;
@property (readonly) NSString * localId;
@property (readonly) NSString * roamingId;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs : RTObject <WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs>
@end

#endif // __WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IAppointmentsProviderShowTimeFrameActivatedEventArgs
#ifndef __WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs <WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WFTimeSpan* duration;
@property (readonly) WFDateTime* timeToShow;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs : RTObject <WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs>
@end

#endif // __WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IUserDataAccountProviderActivatedEventArgs
#ifndef __WAAIUserDataAccountProviderActivatedEventArgs_DEFINED__
#define __WAAIUserDataAccountProviderActivatedEventArgs_DEFINED__

@protocol WAAIUserDataAccountProviderActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) RTObject<WAUPIUserDataAccountProviderOperation>* operation;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIUserDataAccountProviderActivatedEventArgs : RTObject <WAAIUserDataAccountProviderActivatedEventArgs>
@end

#endif // __WAAIUserDataAccountProviderActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IActivatedEventArgsWithUser
#ifndef __WAAIActivatedEventArgsWithUser_DEFINED__
#define __WAAIActivatedEventArgsWithUser_DEFINED__

@protocol WAAIActivatedEventArgsWithUser <WAAIActivatedEventArgs>
@property (readonly) WSUser* user;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIActivatedEventArgsWithUser : RTObject <WAAIActivatedEventArgsWithUser>
@end

#endif // __WAAIActivatedEventArgsWithUser_DEFINED__

// Windows.ApplicationModel.Activation.IApplicationViewActivatedEventArgs
#ifndef __WAAIApplicationViewActivatedEventArgs_DEFINED__
#define __WAAIApplicationViewActivatedEventArgs_DEFINED__

@protocol WAAIApplicationViewActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) int currentlyShownApplicationViewId;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIApplicationViewActivatedEventArgs : RTObject <WAAIApplicationViewActivatedEventArgs>
@end

#endif // __WAAIApplicationViewActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IViewSwitcherProvider
#ifndef __WAAIViewSwitcherProvider_DEFINED__
#define __WAAIViewSwitcherProvider_DEFINED__

@protocol WAAIViewSwitcherProvider <WAAIActivatedEventArgs>
@property (readonly) WUVActivationViewSwitcher* viewSwitcher;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIViewSwitcherProvider : RTObject <WAAIViewSwitcherProvider>
@end

#endif // __WAAIViewSwitcherProvider_DEFINED__

// Windows.ApplicationModel.Activation.IPrelaunchActivatedEventArgs
#ifndef __WAAIPrelaunchActivatedEventArgs_DEFINED__
#define __WAAIPrelaunchActivatedEventArgs_DEFINED__

@protocol WAAIPrelaunchActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) BOOL prelaunchActivated;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIPrelaunchActivatedEventArgs : RTObject <WAAIPrelaunchActivatedEventArgs>
@end

#endif // __WAAIPrelaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ILaunchActivatedEventArgs
#ifndef __WAAILaunchActivatedEventArgs_DEFINED__
#define __WAAILaunchActivatedEventArgs_DEFINED__

@protocol WAAILaunchActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * arguments;
@property (readonly) NSString * tileId;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAILaunchActivatedEventArgs : RTObject <WAAILaunchActivatedEventArgs>
@end

#endif // __WAAILaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ILaunchActivatedEventArgs2
#ifndef __WAAILaunchActivatedEventArgs2_DEFINED__
#define __WAAILaunchActivatedEventArgs2_DEFINED__

@protocol WAAILaunchActivatedEventArgs2 <WAAILaunchActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAATileActivatedInfo* tileActivatedInfo;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAILaunchActivatedEventArgs2 : RTObject <WAAILaunchActivatedEventArgs2>
@end

#endif // __WAAILaunchActivatedEventArgs2_DEFINED__

// Windows.ApplicationModel.Activation.ISearchActivatedEventArgs
#ifndef __WAAISearchActivatedEventArgs_DEFINED__
#define __WAAISearchActivatedEventArgs_DEFINED__

@protocol WAAISearchActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * language;
@property (readonly) NSString * queryText;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAISearchActivatedEventArgs : RTObject <WAAISearchActivatedEventArgs>
@end

#endif // __WAAISearchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ISearchActivatedEventArgsWithLinguisticDetails
#ifndef __WAAISearchActivatedEventArgsWithLinguisticDetails_DEFINED__
#define __WAAISearchActivatedEventArgsWithLinguisticDetails_DEFINED__

@protocol WAAISearchActivatedEventArgsWithLinguisticDetails
@property (readonly) WASSearchPaneQueryLinguisticDetails* linguisticDetails;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAISearchActivatedEventArgsWithLinguisticDetails : RTObject <WAAISearchActivatedEventArgsWithLinguisticDetails>
@end

#endif // __WAAISearchActivatedEventArgsWithLinguisticDetails_DEFINED__

// Windows.ApplicationModel.Activation.IShareTargetActivatedEventArgs
#ifndef __WAAIShareTargetActivatedEventArgs_DEFINED__
#define __WAAIShareTargetActivatedEventArgs_DEFINED__

@protocol WAAIShareTargetActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WADSShareOperation* shareOperation;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIShareTargetActivatedEventArgs : RTObject <WAAIShareTargetActivatedEventArgs>
@end

#endif // __WAAIShareTargetActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileActivatedEventArgs
#ifndef __WAAIFileActivatedEventArgs_DEFINED__
#define __WAAIFileActivatedEventArgs_DEFINED__

@protocol WAAIFileActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSArray* /* RTObject<WSIStorageItem>* */ files;
@property (readonly) NSString * verb;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIFileActivatedEventArgs : RTObject <WAAIFileActivatedEventArgs>
@end

#endif // __WAAIFileActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileActivatedEventArgsWithNeighboringFiles
#ifndef __WAAIFileActivatedEventArgsWithNeighboringFiles_DEFINED__
#define __WAAIFileActivatedEventArgsWithNeighboringFiles_DEFINED__

@protocol WAAIFileActivatedEventArgsWithNeighboringFiles <WAAIFileActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WSSStorageFileQueryResult* neighboringFilesQuery;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIFileActivatedEventArgsWithNeighboringFiles : RTObject <WAAIFileActivatedEventArgsWithNeighboringFiles>
@end

#endif // __WAAIFileActivatedEventArgsWithNeighboringFiles_DEFINED__

// Windows.ApplicationModel.Activation.IFileActivatedEventArgsWithCallerPackageFamilyName
#ifndef __WAAIFileActivatedEventArgsWithCallerPackageFamilyName_DEFINED__
#define __WAAIFileActivatedEventArgsWithCallerPackageFamilyName_DEFINED__

@protocol WAAIFileActivatedEventArgsWithCallerPackageFamilyName <WAAIActivatedEventArgs>
@property (readonly) NSString * callerPackageFamilyName;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIFileActivatedEventArgsWithCallerPackageFamilyName : RTObject <WAAIFileActivatedEventArgsWithCallerPackageFamilyName>
@end

#endif // __WAAIFileActivatedEventArgsWithCallerPackageFamilyName_DEFINED__

// Windows.ApplicationModel.Activation.IProtocolActivatedEventArgs
#ifndef __WAAIProtocolActivatedEventArgs_DEFINED__
#define __WAAIProtocolActivatedEventArgs_DEFINED__

@protocol WAAIProtocolActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WFUri* uri;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
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

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData : RTObject <WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData>
@end

#endif // __WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData_DEFINED__

// Windows.ApplicationModel.Activation.IProtocolForResultsActivatedEventArgs
#ifndef __WAAIProtocolForResultsActivatedEventArgs_DEFINED__
#define __WAAIProtocolForResultsActivatedEventArgs_DEFINED__

@protocol WAAIProtocolForResultsActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WSProtocolForResultsOperation* protocolForResultsOperation;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIProtocolForResultsActivatedEventArgs : RTObject <WAAIProtocolForResultsActivatedEventArgs>
@end

#endif // __WAAIProtocolForResultsActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileOpenPickerActivatedEventArgs
#ifndef __WAAIFileOpenPickerActivatedEventArgs_DEFINED__
#define __WAAIFileOpenPickerActivatedEventArgs_DEFINED__

@protocol WAAIFileOpenPickerActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WSPPFileOpenPickerUI* fileOpenPickerUI;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIFileOpenPickerActivatedEventArgs : RTObject <WAAIFileOpenPickerActivatedEventArgs>
@end

#endif // __WAAIFileOpenPickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileOpenPickerActivatedEventArgs2
#ifndef __WAAIFileOpenPickerActivatedEventArgs2_DEFINED__
#define __WAAIFileOpenPickerActivatedEventArgs2_DEFINED__

@protocol WAAIFileOpenPickerActivatedEventArgs2
@property (readonly) NSString * callerPackageFamilyName;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIFileOpenPickerActivatedEventArgs2 : RTObject <WAAIFileOpenPickerActivatedEventArgs2>
@end

#endif // __WAAIFileOpenPickerActivatedEventArgs2_DEFINED__

// Windows.ApplicationModel.Activation.IFileSavePickerActivatedEventArgs
#ifndef __WAAIFileSavePickerActivatedEventArgs_DEFINED__
#define __WAAIFileSavePickerActivatedEventArgs_DEFINED__

@protocol WAAIFileSavePickerActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WSPPFileSavePickerUI* fileSavePickerUI;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
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

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIFileSavePickerActivatedEventArgs2 : RTObject <WAAIFileSavePickerActivatedEventArgs2>
@end

#endif // __WAAIFileSavePickerActivatedEventArgs2_DEFINED__

// Windows.ApplicationModel.Activation.ICachedFileUpdaterActivatedEventArgs
#ifndef __WAAICachedFileUpdaterActivatedEventArgs_DEFINED__
#define __WAAICachedFileUpdaterActivatedEventArgs_DEFINED__

@protocol WAAICachedFileUpdaterActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WSPCachedFileUpdaterUI* cachedFileUpdaterUI;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAICachedFileUpdaterActivatedEventArgs : RTObject <WAAICachedFileUpdaterActivatedEventArgs>
@end

#endif // __WAAICachedFileUpdaterActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IDeviceActivatedEventArgs
#ifndef __WAAIDeviceActivatedEventArgs_DEFINED__
#define __WAAIDeviceActivatedEventArgs_DEFINED__

@protocol WAAIDeviceActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * deviceInformationId;
@property (readonly) NSString * verb;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIDeviceActivatedEventArgs : RTObject <WAAIDeviceActivatedEventArgs>
@end

#endif // __WAAIDeviceActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IPickerReturnedActivatedEventArgs
#ifndef __WAAIPickerReturnedActivatedEventArgs_DEFINED__
#define __WAAIPickerReturnedActivatedEventArgs_DEFINED__

@protocol WAAIPickerReturnedActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * pickerOperationId;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIPickerReturnedActivatedEventArgs : RTObject <WAAIPickerReturnedActivatedEventArgs>
@end

#endif // __WAAIPickerReturnedActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IRestrictedLaunchActivatedEventArgs
#ifndef __WAAIRestrictedLaunchActivatedEventArgs_DEFINED__
#define __WAAIRestrictedLaunchActivatedEventArgs_DEFINED__

@protocol WAAIRestrictedLaunchActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) RTObject* sharedContext;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIRestrictedLaunchActivatedEventArgs : RTObject <WAAIRestrictedLaunchActivatedEventArgs>
@end

#endif // __WAAIRestrictedLaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ILockScreenActivatedEventArgs
#ifndef __WAAILockScreenActivatedEventArgs_DEFINED__
#define __WAAILockScreenActivatedEventArgs_DEFINED__

@protocol WAAILockScreenActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) RTObject* info;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAILockScreenActivatedEventArgs : RTObject <WAAILockScreenActivatedEventArgs>
@end

#endif // __WAAILockScreenActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContinuationActivatedEventArgs
#ifndef __WAAIContinuationActivatedEventArgs_DEFINED__
#define __WAAIContinuationActivatedEventArgs_DEFINED__

@protocol WAAIContinuationActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WFCValueSet* continuationData;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIContinuationActivatedEventArgs : RTObject <WAAIContinuationActivatedEventArgs>
@end

#endif // __WAAIContinuationActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileOpenPickerContinuationEventArgs
#ifndef __WAAIFileOpenPickerContinuationEventArgs_DEFINED__
#define __WAAIFileOpenPickerContinuationEventArgs_DEFINED__

@protocol WAAIFileOpenPickerContinuationEventArgs <WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) NSArray* /* WSStorageFile* */ files;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIFileOpenPickerContinuationEventArgs : RTObject <WAAIFileOpenPickerContinuationEventArgs>
@end

#endif // __WAAIFileOpenPickerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileSavePickerContinuationEventArgs
#ifndef __WAAIFileSavePickerContinuationEventArgs_DEFINED__
#define __WAAIFileSavePickerContinuationEventArgs_DEFINED__

@protocol WAAIFileSavePickerContinuationEventArgs <WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WSStorageFile* file;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIFileSavePickerContinuationEventArgs : RTObject <WAAIFileSavePickerContinuationEventArgs>
@end

#endif // __WAAIFileSavePickerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFolderPickerContinuationEventArgs
#ifndef __WAAIFolderPickerContinuationEventArgs_DEFINED__
#define __WAAIFolderPickerContinuationEventArgs_DEFINED__

@protocol WAAIFolderPickerContinuationEventArgs <WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WSStorageFolder* folder;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIFolderPickerContinuationEventArgs : RTObject <WAAIFolderPickerContinuationEventArgs>
@end

#endif // __WAAIFolderPickerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IWebAuthenticationBrokerContinuationEventArgs
#ifndef __WAAIWebAuthenticationBrokerContinuationEventArgs_DEFINED__
#define __WAAIWebAuthenticationBrokerContinuationEventArgs_DEFINED__

@protocol WAAIWebAuthenticationBrokerContinuationEventArgs <WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WSAWWebAuthenticationResult* webAuthenticationResult;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIWebAuthenticationBrokerContinuationEventArgs : RTObject <WAAIWebAuthenticationBrokerContinuationEventArgs>
@end

#endif // __WAAIWebAuthenticationBrokerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IWebAccountProviderActivatedEventArgs
#ifndef __WAAIWebAccountProviderActivatedEventArgs_DEFINED__
#define __WAAIWebAccountProviderActivatedEventArgs_DEFINED__

@protocol WAAIWebAccountProviderActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) RTObject<WSAWPIWebAccountProviderOperation>* operation;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIWebAccountProviderActivatedEventArgs : RTObject <WAAIWebAccountProviderActivatedEventArgs>
@end

#endif // __WAAIWebAccountProviderActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IToastNotificationActivatedEventArgs
#ifndef __WAAIToastNotificationActivatedEventArgs_DEFINED__
#define __WAAIToastNotificationActivatedEventArgs_DEFINED__

@protocol WAAIToastNotificationActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * argument;
@property (readonly) WFCValueSet* userInput;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIToastNotificationActivatedEventArgs : RTObject <WAAIToastNotificationActivatedEventArgs>
@end

#endif // __WAAIToastNotificationActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IDialReceiverActivatedEventArgs
#ifndef __WAAIDialReceiverActivatedEventArgs_DEFINED__
#define __WAAIDialReceiverActivatedEventArgs_DEFINED__

@protocol WAAIDialReceiverActivatedEventArgs <WAAILaunchActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) NSString * appName;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIDialReceiverActivatedEventArgs : RTObject <WAAIDialReceiverActivatedEventArgs>
@end

#endif // __WAAIDialReceiverActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ICommandLineActivatedEventArgs
#ifndef __WAAICommandLineActivatedEventArgs_DEFINED__
#define __WAAICommandLineActivatedEventArgs_DEFINED__

@protocol WAAICommandLineActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WAACommandLineActivationOperation* operation;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAICommandLineActivatedEventArgs : RTObject <WAAICommandLineActivatedEventArgs>
@end

#endif // __WAAICommandLineActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IStartupTaskActivatedEventArgs
#ifndef __WAAIStartupTaskActivatedEventArgs_DEFINED__
#define __WAAIStartupTaskActivatedEventArgs_DEFINED__

@protocol WAAIStartupTaskActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString * taskId;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIStartupTaskActivatedEventArgs : RTObject <WAAIStartupTaskActivatedEventArgs>
@end

#endif // __WAAIStartupTaskActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IDevicePairingActivatedEventArgs
#ifndef __WAAIDevicePairingActivatedEventArgs_DEFINED__
#define __WAAIDevicePairingActivatedEventArgs_DEFINED__

@protocol WAAIDevicePairingActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WDEDeviceInformation* deviceInformation;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIDevicePairingActivatedEventArgs : RTObject <WAAIDevicePairingActivatedEventArgs>
@end

#endif // __WAAIDevicePairingActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IVoiceCommandActivatedEventArgs
#ifndef __WAAIVoiceCommandActivatedEventArgs_DEFINED__
#define __WAAIVoiceCommandActivatedEventArgs_DEFINED__

@protocol WAAIVoiceCommandActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WMSSpeechRecognitionResult* result;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAIVoiceCommandActivatedEventArgs : RTObject <WAAIVoiceCommandActivatedEventArgs>
@end

#endif // __WAAIVoiceCommandActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.CameraSettingsActivatedEventArgs
#ifndef __WAACameraSettingsActivatedEventArgs_DEFINED__
#define __WAACameraSettingsActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAACameraSettingsActivatedEventArgs : RTObject <WAAICameraSettingsActivatedEventArgs, WAAIActivatedEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) RTObject* videoDeviceController;
@property (readonly) RTObject* videoDeviceExtension;
@end

#endif // __WAACameraSettingsActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ContactPickerActivatedEventArgs
#ifndef __WAAContactPickerActivatedEventArgs_DEFINED__
#define __WAAContactPickerActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAContactPickerActivatedEventArgs : RTObject <WAAIContactPickerActivatedEventArgs, WAAIActivatedEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WACPContactPickerUI* contactPickerUI;
@end

#endif // __WAAContactPickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ContactCallActivatedEventArgs
#ifndef __WAAContactCallActivatedEventArgs_DEFINED__
#define __WAAContactCallActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAContactCallActivatedEventArgs : RTObject <WAAIContactCallActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
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
@end

#endif // __WAAContactCallActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ContactMessageActivatedEventArgs
#ifndef __WAAContactMessageActivatedEventArgs_DEFINED__
#define __WAAContactMessageActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAContactMessageActivatedEventArgs : RTObject <WAAIContactMessageActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
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
@end

#endif // __WAAContactMessageActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ContactMapActivatedEventArgs
#ifndef __WAAContactMapActivatedEventArgs_DEFINED__
#define __WAAContactMapActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAContactMapActivatedEventArgs : RTObject <WAAIContactMapActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString * verb;
@property (readonly) WACContactAddress* address;
@property (readonly) WACContact* contact;
@end

#endif // __WAAContactMapActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ContactPostActivatedEventArgs
#ifndef __WAAContactPostActivatedEventArgs_DEFINED__
#define __WAAContactPostActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAContactPostActivatedEventArgs : RTObject <WAAIContactPostActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
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
@end

#endif // __WAAContactPostActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ContactVideoCallActivatedEventArgs
#ifndef __WAAContactVideoCallActivatedEventArgs_DEFINED__
#define __WAAContactVideoCallActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAContactVideoCallActivatedEventArgs : RTObject <WAAIContactVideoCallActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
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
@end

#endif // __WAAContactVideoCallActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.WalletActionActivatedEventArgs
#ifndef __WAAWalletActionActivatedEventArgs_DEFINED__
#define __WAAWalletActionActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAWalletActionActivatedEventArgs : RTObject <WAAIWalletActionActivatedEventArgs, WAAIActivatedEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString * actionId;
@property (readonly) WAWWalletActionKind actionKind;
@property (readonly) NSString * itemId;
@end

#endif // __WAAWalletActionActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.AppointmentsProviderAddAppointmentActivatedEventArgs
#ifndef __WAAAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__
#define __WAAAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAAppointmentsProviderAddAppointmentActivatedEventArgs : RTObject <WAAIAppointmentsProviderAddAppointmentActivatedEventArgs, WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) NSString * verb;
@property (readonly) WAAAAddAppointmentOperation* addAppointmentOperation;
@end

#endif // __WAAAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.AppointmentsProviderReplaceAppointmentActivatedEventArgs
#ifndef __WAAAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__
#define __WAAAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAAppointmentsProviderReplaceAppointmentActivatedEventArgs : RTObject <WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs, WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) NSString * verb;
@property (readonly) WAAAReplaceAppointmentOperation* replaceAppointmentOperation;
@end

#endif // __WAAAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.AppointmentsProviderRemoveAppointmentActivatedEventArgs
#ifndef __WAAAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__
#define __WAAAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAAppointmentsProviderRemoveAppointmentActivatedEventArgs : RTObject <WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs, WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) NSString * verb;
@property (readonly) WAAARemoveAppointmentOperation* removeAppointmentOperation;
@end

#endif // __WAAAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.AppointmentsProviderShowAppointmentDetailsActivatedEventArgs
#ifndef __WAAAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__
#define __WAAAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAAppointmentsProviderShowAppointmentDetailsActivatedEventArgs : RTObject <WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs, WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
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
@end

#endif // __WAAAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.AppointmentsProviderShowTimeFrameActivatedEventArgs
#ifndef __WAAAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__
#define __WAAAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAAppointmentsProviderShowTimeFrameActivatedEventArgs : RTObject <WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs, WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
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
@end

#endif // __WAAAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.BackgroundActivatedEventArgs
#ifndef __WAABackgroundActivatedEventArgs_DEFINED__
#define __WAABackgroundActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAABackgroundActivatedEventArgs : RTObject <WAAIBackgroundActivatedEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WABIBackgroundTaskInstance>* taskInstance;
@end

#endif // __WAABackgroundActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ContactPanelActivatedEventArgs
#ifndef __WAAContactPanelActivatedEventArgs_DEFINED__
#define __WAAContactPanelActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAContactPanelActivatedEventArgs : RTObject <WAAIContactPanelActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WACContact* contact;
@property (readonly) WACContactPanel* contactPanel;
@end

#endif // __WAAContactPanelActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.UserDataAccountProviderActivatedEventArgs
#ifndef __WAAUserDataAccountProviderActivatedEventArgs_DEFINED__
#define __WAAUserDataAccountProviderActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAUserDataAccountProviderActivatedEventArgs : RTObject <WAAIUserDataAccountProviderActivatedEventArgs, WAAIActivatedEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) RTObject<WAUPIUserDataAccountProviderOperation>* operation;
@end

#endif // __WAAUserDataAccountProviderActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.SplashScreen
#ifndef __WAASplashScreen_DEFINED__
#define __WAASplashScreen_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAASplashScreen : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFRect* imageLocation;
- (EventRegistrationToken)addDismissedEvent:(void(^)(WAASplashScreen*, RTObject*))del;
- (void)removeDismissedEvent:(EventRegistrationToken)tok;
@end

#endif // __WAASplashScreen_DEFINED__

// Windows.ApplicationModel.Activation.TileActivatedInfo
#ifndef __WAATileActivatedInfo_DEFINED__
#define __WAATileActivatedInfo_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAATileActivatedInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WUNShownTileNotification* */ recentlyShownNotifications;
@end

#endif // __WAATileActivatedInfo_DEFINED__

// Windows.ApplicationModel.Activation.LaunchActivatedEventArgs
#ifndef __WAALaunchActivatedEventArgs_DEFINED__
#define __WAALaunchActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAALaunchActivatedEventArgs : RTObject <WAAILaunchActivatedEventArgs, WAAIActivatedEventArgs, WAAIApplicationViewActivatedEventArgs, WAAIPrelaunchActivatedEventArgs, WAAIViewSwitcherProvider, WAAILaunchActivatedEventArgs2, WAAIActivatedEventArgsWithUser>
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
@property (readonly) WAATileActivatedInfo* tileActivatedInfo;
@property (readonly) BOOL prelaunchActivated;
@property (readonly) WUVActivationViewSwitcher* viewSwitcher;
@end

#endif // __WAALaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.SearchActivatedEventArgs
#ifndef __WAASearchActivatedEventArgs_DEFINED__
#define __WAASearchActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAASearchActivatedEventArgs : RTObject <WAAISearchActivatedEventArgs, WAAIActivatedEventArgs, WAAIApplicationViewActivatedEventArgs, WAAISearchActivatedEventArgsWithLinguisticDetails, WAAIViewSwitcherProvider, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) NSString * language;
@property (readonly) NSString * queryText;
@property (readonly) WASSearchPaneQueryLinguisticDetails* linguisticDetails;
@property (readonly) WUVActivationViewSwitcher* viewSwitcher;
@end

#endif // __WAASearchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ShareTargetActivatedEventArgs
#ifndef __WAAShareTargetActivatedEventArgs_DEFINED__
#define __WAAShareTargetActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAShareTargetActivatedEventArgs : RTObject <WAAIShareTargetActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WADSShareOperation* shareOperation;
@end

#endif // __WAAShareTargetActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.FileActivatedEventArgs
#ifndef __WAAFileActivatedEventArgs_DEFINED__
#define __WAAFileActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAFileActivatedEventArgs : RTObject <WAAIFileActivatedEventArgs, WAAIActivatedEventArgs, WAAIFileActivatedEventArgsWithNeighboringFiles, WAAIFileActivatedEventArgsWithCallerPackageFamilyName, WAAIApplicationViewActivatedEventArgs, WAAIViewSwitcherProvider, WAAIActivatedEventArgsWithUser>
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
@property (readonly) NSString * callerPackageFamilyName;
@property (readonly) WSSStorageFileQueryResult* neighboringFilesQuery;
@property (readonly) WUVActivationViewSwitcher* viewSwitcher;
@end

#endif // __WAAFileActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ProtocolActivatedEventArgs
#ifndef __WAAProtocolActivatedEventArgs_DEFINED__
#define __WAAProtocolActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAProtocolActivatedEventArgs : RTObject <WAAIProtocolActivatedEventArgs, WAAIActivatedEventArgs, WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData, WAAIApplicationViewActivatedEventArgs, WAAIViewSwitcherProvider, WAAIActivatedEventArgsWithUser>
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
@property (readonly) WUVActivationViewSwitcher* viewSwitcher;
@end

#endif // __WAAProtocolActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ProtocolForResultsActivatedEventArgs
#ifndef __WAAProtocolForResultsActivatedEventArgs_DEFINED__
#define __WAAProtocolForResultsActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAProtocolForResultsActivatedEventArgs : RTObject <WAAIProtocolForResultsActivatedEventArgs, WAAIActivatedEventArgs, WAAIProtocolActivatedEventArgs, WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData, WAAIApplicationViewActivatedEventArgs, WAAIViewSwitcherProvider, WAAIActivatedEventArgsWithUser>
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
@property (readonly) WUVActivationViewSwitcher* viewSwitcher;
@end

#endif // __WAAProtocolForResultsActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.FileOpenPickerActivatedEventArgs
#ifndef __WAAFileOpenPickerActivatedEventArgs_DEFINED__
#define __WAAFileOpenPickerActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAFileOpenPickerActivatedEventArgs : RTObject <WAAIFileOpenPickerActivatedEventArgs, WAAIActivatedEventArgs, WAAIFileOpenPickerActivatedEventArgs2, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WSPPFileOpenPickerUI* fileOpenPickerUI;
@property (readonly) NSString * callerPackageFamilyName;
@end

#endif // __WAAFileOpenPickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.FileSavePickerActivatedEventArgs
#ifndef __WAAFileSavePickerActivatedEventArgs_DEFINED__
#define __WAAFileSavePickerActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAFileSavePickerActivatedEventArgs : RTObject <WAAIFileSavePickerActivatedEventArgs, WAAIActivatedEventArgs, WAAIFileSavePickerActivatedEventArgs2, WAAIActivatedEventArgsWithUser>
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
@end

#endif // __WAAFileSavePickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.CachedFileUpdaterActivatedEventArgs
#ifndef __WAACachedFileUpdaterActivatedEventArgs_DEFINED__
#define __WAACachedFileUpdaterActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAACachedFileUpdaterActivatedEventArgs : RTObject <WAAICachedFileUpdaterActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WSPCachedFileUpdaterUI* cachedFileUpdaterUI;
@end

#endif // __WAACachedFileUpdaterActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.DeviceActivatedEventArgs
#ifndef __WAADeviceActivatedEventArgs_DEFINED__
#define __WAADeviceActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAADeviceActivatedEventArgs : RTObject <WAAIDeviceActivatedEventArgs, WAAIActivatedEventArgs, WAAIApplicationViewActivatedEventArgs, WAAIViewSwitcherProvider, WAAIActivatedEventArgsWithUser>
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
@property (readonly) WUVActivationViewSwitcher* viewSwitcher;
@end

#endif // __WAADeviceActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.PickerReturnedActivatedEventArgs
#ifndef __WAAPickerReturnedActivatedEventArgs_DEFINED__
#define __WAAPickerReturnedActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAPickerReturnedActivatedEventArgs : RTObject <WAAIPickerReturnedActivatedEventArgs, WAAIActivatedEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString * pickerOperationId;
@end

#endif // __WAAPickerReturnedActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.RestrictedLaunchActivatedEventArgs
#ifndef __WAARestrictedLaunchActivatedEventArgs_DEFINED__
#define __WAARestrictedLaunchActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAARestrictedLaunchActivatedEventArgs : RTObject <WAAIRestrictedLaunchActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) RTObject* sharedContext;
@end

#endif // __WAARestrictedLaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.LockScreenActivatedEventArgs
#ifndef __WAALockScreenActivatedEventArgs_DEFINED__
#define __WAALockScreenActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAALockScreenActivatedEventArgs : RTObject <WAAILockScreenActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) RTObject* info;
@end

#endif // __WAALockScreenActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.FileOpenPickerContinuationEventArgs
#ifndef __WAAFileOpenPickerContinuationEventArgs_DEFINED__
#define __WAAFileOpenPickerContinuationEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAFileOpenPickerContinuationEventArgs : RTObject <WAAIFileOpenPickerContinuationEventArgs, WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WFCValueSet* continuationData;
@property (readonly) NSArray* /* WSStorageFile* */ files;
@end

#endif // __WAAFileOpenPickerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.FileSavePickerContinuationEventArgs
#ifndef __WAAFileSavePickerContinuationEventArgs_DEFINED__
#define __WAAFileSavePickerContinuationEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAFileSavePickerContinuationEventArgs : RTObject <WAAIFileSavePickerContinuationEventArgs, WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WFCValueSet* continuationData;
@property (readonly) WSStorageFile* file;
@end

#endif // __WAAFileSavePickerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.FolderPickerContinuationEventArgs
#ifndef __WAAFolderPickerContinuationEventArgs_DEFINED__
#define __WAAFolderPickerContinuationEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAFolderPickerContinuationEventArgs : RTObject <WAAIFolderPickerContinuationEventArgs, WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WFCValueSet* continuationData;
@property (readonly) WSStorageFolder* folder;
@end

#endif // __WAAFolderPickerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.WebAuthenticationBrokerContinuationEventArgs
#ifndef __WAAWebAuthenticationBrokerContinuationEventArgs_DEFINED__
#define __WAAWebAuthenticationBrokerContinuationEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAWebAuthenticationBrokerContinuationEventArgs : RTObject <WAAIWebAuthenticationBrokerContinuationEventArgs, WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WFCValueSet* continuationData;
@property (readonly) WSAWWebAuthenticationResult* webAuthenticationResult;
@end

#endif // __WAAWebAuthenticationBrokerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.WebAccountProviderActivatedEventArgs
#ifndef __WAAWebAccountProviderActivatedEventArgs_DEFINED__
#define __WAAWebAccountProviderActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAWebAccountProviderActivatedEventArgs : RTObject <WAAIWebAccountProviderActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) RTObject<WSAWPIWebAccountProviderOperation>* operation;
@end

#endif // __WAAWebAccountProviderActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ToastNotificationActivatedEventArgs
#ifndef __WAAToastNotificationActivatedEventArgs_DEFINED__
#define __WAAToastNotificationActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAToastNotificationActivatedEventArgs : RTObject <WAAIToastNotificationActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser, WAAIApplicationViewActivatedEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) NSString * argument;
@property (readonly) WFCValueSet* userInput;
@end

#endif // __WAAToastNotificationActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.DialReceiverActivatedEventArgs
#ifndef __WAADialReceiverActivatedEventArgs_DEFINED__
#define __WAADialReceiverActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAADialReceiverActivatedEventArgs : RTObject <WAAIDialReceiverActivatedEventArgs, WAAILaunchActivatedEventArgs, WAAIActivatedEventArgs, WAAIApplicationViewActivatedEventArgs, WAAIViewSwitcherProvider, WAAIActivatedEventArgsWithUser>
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
@property (readonly) WUVActivationViewSwitcher* viewSwitcher;
@end

#endif // __WAADialReceiverActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.LockScreenComponentActivatedEventArgs
#ifndef __WAALockScreenComponentActivatedEventArgs_DEFINED__
#define __WAALockScreenComponentActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAALockScreenComponentActivatedEventArgs : RTObject <WAAIActivatedEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WAALockScreenComponentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.CommandLineActivationOperation
#ifndef __WAACommandLineActivationOperation_DEFINED__
#define __WAACommandLineActivationOperation_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAACommandLineActivationOperation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property int exitCode;
@property (readonly) NSString * arguments;
@property (readonly) NSString * currentDirectoryPath;
- (WFDeferral*)getDeferral;
@end

#endif // __WAACommandLineActivationOperation_DEFINED__

// Windows.ApplicationModel.Activation.CommandLineActivatedEventArgs
#ifndef __WAACommandLineActivatedEventArgs_DEFINED__
#define __WAACommandLineActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAACommandLineActivatedEventArgs : RTObject <WAAICommandLineActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WAACommandLineActivationOperation* operation;
@end

#endif // __WAACommandLineActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.StartupTaskActivatedEventArgs
#ifndef __WAAStartupTaskActivatedEventArgs_DEFINED__
#define __WAAStartupTaskActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAStartupTaskActivatedEventArgs : RTObject <WAAIStartupTaskActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) NSString * taskId;
@end

#endif // __WAAStartupTaskActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.DevicePairingActivatedEventArgs
#ifndef __WAADevicePairingActivatedEventArgs_DEFINED__
#define __WAADevicePairingActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAADevicePairingActivatedEventArgs : RTObject <WAAIDevicePairingActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WDEDeviceInformation* deviceInformation;
@end

#endif // __WAADevicePairingActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.VoiceCommandActivatedEventArgs
#ifndef __WAAVoiceCommandActivatedEventArgs_DEFINED__
#define __WAAVoiceCommandActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAVoiceCommandActivatedEventArgs : RTObject <WAAIVoiceCommandActivatedEventArgs, WAAIActivatedEventArgs, WAAIActivatedEventArgsWithUser>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSUser* user;
@property (readonly) WMSSpeechRecognitionResult* result;
@end

#endif // __WAAVoiceCommandActivatedEventArgs_DEFINED__

