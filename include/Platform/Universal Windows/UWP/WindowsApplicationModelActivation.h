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

// WindowsApplicationModelActivation.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WAASplashScreen, WAALaunchActivatedEventArgs, WAASearchActivatedEventArgs, WAAShareTargetActivatedEventArgs,
    WAAFileActivatedEventArgs, WAAProtocolActivatedEventArgs, WAAProtocolForResultsActivatedEventArgs, WAAFileOpenPickerActivatedEventArgs,
    WAAFileSavePickerActivatedEventArgs, WAACachedFileUpdaterActivatedEventArgs, WAADeviceActivatedEventArgs,
    WAAAppointmentsProviderAddAppointmentActivatedEventArgs, WAAAppointmentsProviderReplaceAppointmentActivatedEventArgs,
    WAAPickerReturnedActivatedEventArgs, WAAAppointmentsProviderRemoveAppointmentActivatedEventArgs,
    WAAAppointmentsProviderShowAppointmentDetailsActivatedEventArgs, WAAAppointmentsProviderShowTimeFrameActivatedEventArgs,
    WAARestrictedLaunchActivatedEventArgs, WAALockScreenActivatedEventArgs, WAAFileOpenPickerContinuationEventArgs,
    WAAFileSavePickerContinuationEventArgs, WAAFolderPickerContinuationEventArgs, WAAWebAuthenticationBrokerContinuationEventArgs,
    WAAWebAccountProviderActivatedEventArgs, WAAToastNotificationActivatedEventArgs, WAADialReceiverActivatedEventArgs,
    WAAVoiceCommandActivatedEventArgs;
@protocol WAAISplashScreen
, WAAIActivatedEventArgs, WAAIApplicationViewActivatedEventArgs, WAAIViewSwitcherProvider, WAAIPrelaunchActivatedEventArgs,
    WAAILaunchActivatedEventArgs, WAAISearchActivatedEventArgs, WAAISearchActivatedEventArgsWithLinguisticDetails,
    WAAIShareTargetActivatedEventArgs, WAAIFileActivatedEventArgs, WAAIFileActivatedEventArgsWithNeighboringFiles,
    WAAIFileActivatedEventArgsWithCallerPackageFamilyName, WAAIProtocolActivatedEventArgs,
    WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData, WAAIProtocolForResultsActivatedEventArgs,
    WAAIFileOpenPickerActivatedEventArgs, WAAIFileOpenPickerActivatedEventArgs2, WAAIFileSavePickerActivatedEventArgs,
    WAAIFileSavePickerActivatedEventArgs2, WAAICachedFileUpdaterActivatedEventArgs, WAAIDeviceActivatedEventArgs,
    WAAIAppointmentsProviderActivatedEventArgs, WAAIAppointmentsProviderAddAppointmentActivatedEventArgs,
    WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs, WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs,
    WAAIPickerReturnedActivatedEventArgs, WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs,
    WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs, WAAIRestrictedLaunchActivatedEventArgs, WAAILockScreenActivatedEventArgs,
    WAAIContinuationActivatedEventArgs, WAAIFileOpenPickerContinuationEventArgs, WAAIFileSavePickerContinuationEventArgs,
    WAAIFolderPickerContinuationEventArgs, WAAIWebAuthenticationBrokerContinuationEventArgs, WAAIWebAccountProviderActivatedEventArgs,
    WAAIToastNotificationActivatedEventArgs, WAAIDialReceiverActivatedEventArgs, WAAIVoiceCommandActivatedEventArgs;

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
    WAAActivationKindDialReceiver = 1012,
};
typedef unsigned WAAActivationKind;

#include "WindowsFoundation.h"
#include "WindowsUIViewManagement.h"
#include "WindowsStoragePickersProvider.h"
#include "WindowsSystem.h"
#include "WindowsMediaSpeechRecognition.h"
#include "WindowsApplicationModelSearch.h"
#include "WindowsApplicationModelDataTransferShareTarget.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageSearch.h"
#include "WindowsStorage.h"
#include "WindowsStorageProvider.h"
#include "WindowsApplicationModelAppointmentsAppointmentsProvider.h"
#include "WindowsSecurityAuthenticationWeb.h"
#include "WindowsSecurityAuthenticationWebProvider.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Activation.IActivatedEventArgs
#ifndef __WAAIActivatedEventArgs_DEFINED__
#define __WAAIActivatedEventArgs_DEFINED__

@protocol WAAIActivatedEventArgs
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WAAIActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IApplicationViewActivatedEventArgs
#ifndef __WAAIApplicationViewActivatedEventArgs_DEFINED__
#define __WAAIApplicationViewActivatedEventArgs_DEFINED__

@protocol WAAIApplicationViewActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) int currentlyShownApplicationViewId;
@end

#endif // __WAAIApplicationViewActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IViewSwitcherProvider
#ifndef __WAAIViewSwitcherProvider_DEFINED__
#define __WAAIViewSwitcherProvider_DEFINED__

@protocol WAAIViewSwitcherProvider <WAAIActivatedEventArgs>
@property (readonly) WUVActivationViewSwitcher* viewSwitcher;
@end

#endif // __WAAIViewSwitcherProvider_DEFINED__

// Windows.ApplicationModel.Activation.IPrelaunchActivatedEventArgs
#ifndef __WAAIPrelaunchActivatedEventArgs_DEFINED__
#define __WAAIPrelaunchActivatedEventArgs_DEFINED__

@protocol WAAIPrelaunchActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) BOOL prelaunchActivated;
@end

#endif // __WAAIPrelaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ILaunchActivatedEventArgs
#ifndef __WAAILaunchActivatedEventArgs_DEFINED__
#define __WAAILaunchActivatedEventArgs_DEFINED__

@protocol WAAILaunchActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString* arguments;
@property (readonly) NSString* tileId;
@end

#endif // __WAAILaunchActivatedEventArgs_DEFINED__

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

// Windows.ApplicationModel.Activation.IShareTargetActivatedEventArgs
#ifndef __WAAIShareTargetActivatedEventArgs_DEFINED__
#define __WAAIShareTargetActivatedEventArgs_DEFINED__

@protocol WAAIShareTargetActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WADSShareOperation* shareOperation;
@end

#endif // __WAAIShareTargetActivatedEventArgs_DEFINED__

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

// Windows.ApplicationModel.Activation.IFileActivatedEventArgsWithCallerPackageFamilyName
#ifndef __WAAIFileActivatedEventArgsWithCallerPackageFamilyName_DEFINED__
#define __WAAIFileActivatedEventArgsWithCallerPackageFamilyName_DEFINED__

@protocol WAAIFileActivatedEventArgsWithCallerPackageFamilyName <WAAIActivatedEventArgs>
@property (readonly) NSString* callerPackageFamilyName;
@end

#endif // __WAAIFileActivatedEventArgsWithCallerPackageFamilyName_DEFINED__

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

// Windows.ApplicationModel.Activation.IProtocolForResultsActivatedEventArgs
#ifndef __WAAIProtocolForResultsActivatedEventArgs_DEFINED__
#define __WAAIProtocolForResultsActivatedEventArgs_DEFINED__

@protocol WAAIProtocolForResultsActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WSProtocolForResultsOperation* protocolForResultsOperation;
@end

#endif // __WAAIProtocolForResultsActivatedEventArgs_DEFINED__

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

// Windows.ApplicationModel.Activation.ICachedFileUpdaterActivatedEventArgs
#ifndef __WAAICachedFileUpdaterActivatedEventArgs_DEFINED__
#define __WAAICachedFileUpdaterActivatedEventArgs_DEFINED__

@protocol WAAICachedFileUpdaterActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WSPCachedFileUpdaterUI* cachedFileUpdaterUI;
@end

#endif // __WAAICachedFileUpdaterActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IDeviceActivatedEventArgs
#ifndef __WAAIDeviceActivatedEventArgs_DEFINED__
#define __WAAIDeviceActivatedEventArgs_DEFINED__

@protocol WAAIDeviceActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString* deviceInformationId;
@property (readonly) NSString* verb;
@end

#endif // __WAAIDeviceActivatedEventArgs_DEFINED__

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

// Windows.ApplicationModel.Activation.IAppointmentsProviderReplaceAppointmentActivatedEventArgs
#ifndef __WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs <WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAAReplaceAppointmentOperation* replaceAppointmentOperation;
@end

#endif // __WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IAppointmentsProviderRemoveAppointmentActivatedEventArgs
#ifndef __WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs <WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAARemoveAppointmentOperation* removeAppointmentOperation;
@end

#endif // __WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IPickerReturnedActivatedEventArgs
#ifndef __WAAIPickerReturnedActivatedEventArgs_DEFINED__
#define __WAAIPickerReturnedActivatedEventArgs_DEFINED__

@protocol WAAIPickerReturnedActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString* pickerOperationId;
@end

#endif // __WAAIPickerReturnedActivatedEventArgs_DEFINED__

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

// Windows.ApplicationModel.Activation.IAppointmentsProviderShowTimeFrameActivatedEventArgs
#ifndef __WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs <WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WFTimeSpan* duration;
@property (readonly) WFDateTime* timeToShow;
@end

#endif // __WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IRestrictedLaunchActivatedEventArgs
#ifndef __WAAIRestrictedLaunchActivatedEventArgs_DEFINED__
#define __WAAIRestrictedLaunchActivatedEventArgs_DEFINED__

@protocol WAAIRestrictedLaunchActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) RTObject* sharedContext;
@end

#endif // __WAAIRestrictedLaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ILockScreenActivatedEventArgs
#ifndef __WAAILockScreenActivatedEventArgs_DEFINED__
#define __WAAILockScreenActivatedEventArgs_DEFINED__

@protocol WAAILockScreenActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) RTObject* info;
@end

#endif // __WAAILockScreenActivatedEventArgs_DEFINED__

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

// Windows.ApplicationModel.Activation.IFileSavePickerContinuationEventArgs
#ifndef __WAAIFileSavePickerContinuationEventArgs_DEFINED__
#define __WAAIFileSavePickerContinuationEventArgs_DEFINED__

@protocol WAAIFileSavePickerContinuationEventArgs <WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WSStorageFile* file;
@end

#endif // __WAAIFileSavePickerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFolderPickerContinuationEventArgs
#ifndef __WAAIFolderPickerContinuationEventArgs_DEFINED__
#define __WAAIFolderPickerContinuationEventArgs_DEFINED__

@protocol WAAIFolderPickerContinuationEventArgs <WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WSStorageFolder* folder;
@end

#endif // __WAAIFolderPickerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IWebAuthenticationBrokerContinuationEventArgs
#ifndef __WAAIWebAuthenticationBrokerContinuationEventArgs_DEFINED__
#define __WAAIWebAuthenticationBrokerContinuationEventArgs_DEFINED__

@protocol WAAIWebAuthenticationBrokerContinuationEventArgs <WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WSAWWebAuthenticationResult* webAuthenticationResult;
@end

#endif // __WAAIWebAuthenticationBrokerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IWebAccountProviderActivatedEventArgs
#ifndef __WAAIWebAccountProviderActivatedEventArgs_DEFINED__
#define __WAAIWebAccountProviderActivatedEventArgs_DEFINED__

@protocol WAAIWebAccountProviderActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) RTObject<WSAWPIWebAccountProviderOperation>* operation;
@end

#endif // __WAAIWebAccountProviderActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IToastNotificationActivatedEventArgs
#ifndef __WAAIToastNotificationActivatedEventArgs_DEFINED__
#define __WAAIToastNotificationActivatedEventArgs_DEFINED__

@protocol WAAIToastNotificationActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString* argument;
@property (readonly) WFCValueSet* userInput;
@end

#endif // __WAAIToastNotificationActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IDialReceiverActivatedEventArgs
#ifndef __WAAIDialReceiverActivatedEventArgs_DEFINED__
#define __WAAIDialReceiverActivatedEventArgs_DEFINED__

@protocol WAAIDialReceiverActivatedEventArgs <WAAILaunchActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) NSString* appName;
@end

#endif // __WAAIDialReceiverActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IVoiceCommandActivatedEventArgs
#ifndef __WAAIVoiceCommandActivatedEventArgs_DEFINED__
#define __WAAIVoiceCommandActivatedEventArgs_DEFINED__

@protocol WAAIVoiceCommandActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WMSSpeechRecognitionResult* result;
@end

#endif // __WAAIVoiceCommandActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.SplashScreen
#ifndef __WAASplashScreen_DEFINED__
#define __WAASplashScreen_DEFINED__

WINRT_EXPORT
@interface WAASplashScreen : RTObject
@property (readonly) WFRect* imageLocation;
- (EventRegistrationToken)addDismissedEvent:(void (^)(WAASplashScreen*, RTObject*))del;
- (void)removeDismissedEvent:(EventRegistrationToken)tok;
@end

#endif // __WAASplashScreen_DEFINED__

// Windows.ApplicationModel.Activation.LaunchActivatedEventArgs
#ifndef __WAALaunchActivatedEventArgs_DEFINED__
#define __WAALaunchActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAALaunchActivatedEventArgs : RTObject <WAAILaunchActivatedEventArgs,
                                                   WAAIActivatedEventArgs,
                                                   WAAIApplicationViewActivatedEventArgs,
                                                   WAAIPrelaunchActivatedEventArgs,
                                                   WAAIViewSwitcherProvider>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) NSString* arguments;
@property (readonly) NSString* tileId;
@property (readonly) BOOL prelaunchActivated;
@property (readonly) WUVActivationViewSwitcher* viewSwitcher;
@end

#endif // __WAALaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.SearchActivatedEventArgs
#ifndef __WAASearchActivatedEventArgs_DEFINED__
#define __WAASearchActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAASearchActivatedEventArgs : RTObject <WAAISearchActivatedEventArgs,
                                                   WAAIActivatedEventArgs,
                                                   WAAIApplicationViewActivatedEventArgs,
                                                   WAAISearchActivatedEventArgsWithLinguisticDetails,
                                                   WAAIViewSwitcherProvider>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) NSString* language;
@property (readonly) NSString* queryText;
@property (readonly) WASSearchPaneQueryLinguisticDetails* linguisticDetails;
@property (readonly) WUVActivationViewSwitcher* viewSwitcher;
@end

#endif // __WAASearchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ShareTargetActivatedEventArgs
#ifndef __WAAShareTargetActivatedEventArgs_DEFINED__
#define __WAAShareTargetActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAShareTargetActivatedEventArgs : RTObject <WAAIShareTargetActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WADSShareOperation* shareOperation;
@end

#endif // __WAAShareTargetActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.FileActivatedEventArgs
#ifndef __WAAFileActivatedEventArgs_DEFINED__
#define __WAAFileActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAFileActivatedEventArgs : RTObject <WAAIFileActivatedEventArgs,
                                                 WAAIActivatedEventArgs,
                                                 WAAIFileActivatedEventArgsWithNeighboringFiles,
                                                 WAAIFileActivatedEventArgsWithCallerPackageFamilyName,
                                                 WAAIApplicationViewActivatedEventArgs,
                                                 WAAIViewSwitcherProvider>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) NSArray* files;
@property (readonly) NSString* verb;
@property (readonly) NSString* callerPackageFamilyName;
@property (readonly) WSSStorageFileQueryResult* neighboringFilesQuery;
@property (readonly) WUVActivationViewSwitcher* viewSwitcher;
@end

#endif // __WAAFileActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ProtocolActivatedEventArgs
#ifndef __WAAProtocolActivatedEventArgs_DEFINED__
#define __WAAProtocolActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAProtocolActivatedEventArgs : RTObject <WAAIProtocolActivatedEventArgs,
                                                     WAAIActivatedEventArgs,
                                                     WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData,
                                                     WAAIApplicationViewActivatedEventArgs,
                                                     WAAIViewSwitcherProvider>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) WFUri* uri;
@property (readonly) NSString* callerPackageFamilyName;
@property (readonly) WFCValueSet* data;
@property (readonly) WUVActivationViewSwitcher* viewSwitcher;
@end

#endif // __WAAProtocolActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ProtocolForResultsActivatedEventArgs
#ifndef __WAAProtocolForResultsActivatedEventArgs_DEFINED__
#define __WAAProtocolForResultsActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAProtocolForResultsActivatedEventArgs : RTObject <WAAIProtocolForResultsActivatedEventArgs,
                                                               WAAIActivatedEventArgs,
                                                               WAAIProtocolActivatedEventArgs,
                                                               WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData,
                                                               WAAIApplicationViewActivatedEventArgs,
                                                               WAAIViewSwitcherProvider>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) WFUri* uri;
@property (readonly) NSString* callerPackageFamilyName;
@property (readonly) WFCValueSet* data;
@property (readonly) WSProtocolForResultsOperation* protocolForResultsOperation;
@property (readonly) WUVActivationViewSwitcher* viewSwitcher;
@end

#endif // __WAAProtocolForResultsActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.FileOpenPickerActivatedEventArgs
#ifndef __WAAFileOpenPickerActivatedEventArgs_DEFINED__
#define __WAAFileOpenPickerActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAFileOpenPickerActivatedEventArgs
    : RTObject <WAAIFileOpenPickerActivatedEventArgs, WAAIActivatedEventArgs, WAAIFileOpenPickerActivatedEventArgs2>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSPPFileOpenPickerUI* fileOpenPickerUI;
@property (readonly) NSString* callerPackageFamilyName;
@end

#endif // __WAAFileOpenPickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.FileSavePickerActivatedEventArgs
#ifndef __WAAFileSavePickerActivatedEventArgs_DEFINED__
#define __WAAFileSavePickerActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAFileSavePickerActivatedEventArgs
    : RTObject <WAAIFileSavePickerActivatedEventArgs, WAAIActivatedEventArgs, WAAIFileSavePickerActivatedEventArgs2>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSPPFileSavePickerUI* fileSavePickerUI;
@property (readonly) NSString* callerPackageFamilyName;
@property (readonly) NSString* enterpriseId;
@end

#endif // __WAAFileSavePickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.CachedFileUpdaterActivatedEventArgs
#ifndef __WAACachedFileUpdaterActivatedEventArgs_DEFINED__
#define __WAACachedFileUpdaterActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAACachedFileUpdaterActivatedEventArgs : RTObject <WAAICachedFileUpdaterActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WSPCachedFileUpdaterUI* cachedFileUpdaterUI;
@end

#endif // __WAACachedFileUpdaterActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.DeviceActivatedEventArgs
#ifndef __WAADeviceActivatedEventArgs_DEFINED__
#define __WAADeviceActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAADeviceActivatedEventArgs
    : RTObject <WAAIDeviceActivatedEventArgs, WAAIActivatedEventArgs, WAAIApplicationViewActivatedEventArgs, WAAIViewSwitcherProvider>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) NSString* deviceInformationId;
@property (readonly) NSString* verb;
@property (readonly) WUVActivationViewSwitcher* viewSwitcher;
@end

#endif // __WAADeviceActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.AppointmentsProviderAddAppointmentActivatedEventArgs
#ifndef __WAAAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__
#define __WAAAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentsProviderAddAppointmentActivatedEventArgs : RTObject <WAAIAppointmentsProviderAddAppointmentActivatedEventArgs,
                                                                               WAAIAppointmentsProviderActivatedEventArgs,
                                                                               WAAIActivatedEventArgs>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* verb;
@property (readonly) WAAAAddAppointmentOperation* addAppointmentOperation;
@end

#endif // __WAAAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.AppointmentsProviderReplaceAppointmentActivatedEventArgs
#ifndef __WAAAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__
#define __WAAAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentsProviderReplaceAppointmentActivatedEventArgs
    : RTObject <WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs,
                WAAIAppointmentsProviderActivatedEventArgs,
                WAAIActivatedEventArgs>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* verb;
@property (readonly) WAAAReplaceAppointmentOperation* replaceAppointmentOperation;
@end

#endif // __WAAAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.PickerReturnedActivatedEventArgs
#ifndef __WAAPickerReturnedActivatedEventArgs_DEFINED__
#define __WAAPickerReturnedActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAPickerReturnedActivatedEventArgs : RTObject <WAAIPickerReturnedActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* pickerOperationId;
@end

#endif // __WAAPickerReturnedActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.AppointmentsProviderRemoveAppointmentActivatedEventArgs
#ifndef __WAAAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__
#define __WAAAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentsProviderRemoveAppointmentActivatedEventArgs
    : RTObject <WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs,
                WAAIAppointmentsProviderActivatedEventArgs,
                WAAIActivatedEventArgs>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* verb;
@property (readonly) WAAARemoveAppointmentOperation* removeAppointmentOperation;
@end

#endif // __WAAAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.AppointmentsProviderShowAppointmentDetailsActivatedEventArgs
#ifndef __WAAAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__
#define __WAAAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentsProviderShowAppointmentDetailsActivatedEventArgs
    : RTObject <WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs,
                WAAIAppointmentsProviderActivatedEventArgs,
                WAAIActivatedEventArgs>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* verb;
@property (readonly) id instanceStartDate;
@property (readonly) NSString* localId;
@property (readonly) NSString* roamingId;
@end

#endif // __WAAAppointmentsProviderShowAppointmentDetailsActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.AppointmentsProviderShowTimeFrameActivatedEventArgs
#ifndef __WAAAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__
#define __WAAAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentsProviderShowTimeFrameActivatedEventArgs
    : RTObject <WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs, WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* verb;
@property (readonly) WFTimeSpan* duration;
@property (readonly) WFDateTime* timeToShow;
@end

#endif // __WAAAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.RestrictedLaunchActivatedEventArgs
#ifndef __WAARestrictedLaunchActivatedEventArgs_DEFINED__
#define __WAARestrictedLaunchActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAARestrictedLaunchActivatedEventArgs : RTObject <WAAIRestrictedLaunchActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) RTObject* sharedContext;
@end

#endif // __WAARestrictedLaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.LockScreenActivatedEventArgs
#ifndef __WAALockScreenActivatedEventArgs_DEFINED__
#define __WAALockScreenActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAALockScreenActivatedEventArgs : RTObject <WAAILockScreenActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) RTObject* info;
@end

#endif // __WAALockScreenActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.FileOpenPickerContinuationEventArgs
#ifndef __WAAFileOpenPickerContinuationEventArgs_DEFINED__
#define __WAAFileOpenPickerContinuationEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAFileOpenPickerContinuationEventArgs
    : RTObject <WAAIFileOpenPickerContinuationEventArgs, WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WFCValueSet* continuationData;
@property (readonly) NSArray* files;
@end

#endif // __WAAFileOpenPickerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.FileSavePickerContinuationEventArgs
#ifndef __WAAFileSavePickerContinuationEventArgs_DEFINED__
#define __WAAFileSavePickerContinuationEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAFileSavePickerContinuationEventArgs
    : RTObject <WAAIFileSavePickerContinuationEventArgs, WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WFCValueSet* continuationData;
@property (readonly) WSStorageFile* file;
@end

#endif // __WAAFileSavePickerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.FolderPickerContinuationEventArgs
#ifndef __WAAFolderPickerContinuationEventArgs_DEFINED__
#define __WAAFolderPickerContinuationEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAFolderPickerContinuationEventArgs
    : RTObject <WAAIFolderPickerContinuationEventArgs, WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WFCValueSet* continuationData;
@property (readonly) WSStorageFolder* folder;
@end

#endif // __WAAFolderPickerContinuationEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.WebAuthenticationBrokerContinuationEventArgs
#ifndef __WAAWebAuthenticationBrokerContinuationEventArgs_DEFINED__
#define __WAAWebAuthenticationBrokerContinuationEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAWebAuthenticationBrokerContinuationEventArgs
    : RTObject <WAAIWebAuthenticationBrokerContinuationEventArgs, WAAIContinuationActivatedEventArgs, WAAIActivatedEventArgs>
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

WINRT_EXPORT
@interface WAAWebAccountProviderActivatedEventArgs : RTObject <WAAIWebAccountProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) RTObject<WSAWPIWebAccountProviderOperation>* operation;
@end

#endif // __WAAWebAccountProviderActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ToastNotificationActivatedEventArgs
#ifndef __WAAToastNotificationActivatedEventArgs_DEFINED__
#define __WAAToastNotificationActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAToastNotificationActivatedEventArgs : RTObject <WAAIToastNotificationActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* argument;
@property (readonly) WFCValueSet* userInput;
@end

#endif // __WAAToastNotificationActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.DialReceiverActivatedEventArgs
#ifndef __WAADialReceiverActivatedEventArgs_DEFINED__
#define __WAADialReceiverActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAADialReceiverActivatedEventArgs : RTObject <WAAIDialReceiverActivatedEventArgs,
                                                         WAAILaunchActivatedEventArgs,
                                                         WAAIActivatedEventArgs,
                                                         WAAIApplicationViewActivatedEventArgs,
                                                         WAAIViewSwitcherProvider>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) NSString* appName;
@property (readonly) NSString* arguments;
@property (readonly) NSString* tileId;
@property (readonly) WUVActivationViewSwitcher* viewSwitcher;
@end

#endif // __WAADialReceiverActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.VoiceCommandActivatedEventArgs
#ifndef __WAAVoiceCommandActivatedEventArgs_DEFINED__
#define __WAAVoiceCommandActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAVoiceCommandActivatedEventArgs : RTObject <WAAIVoiceCommandActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WMSSpeechRecognitionResult* result;
@end

#endif // __WAAVoiceCommandActivatedEventArgs_DEFINED__
