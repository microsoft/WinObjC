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
    WAAFileActivatedEventArgs, WAAProtocolActivatedEventArgs, WAAFileOpenPickerActivatedEventArgs, WAAFileSavePickerActivatedEventArgs,
    WAACachedFileUpdaterActivatedEventArgs, WAAContactPickerActivatedEventArgs, WAADeviceActivatedEventArgs,
    WAAPrintTaskSettingsActivatedEventArgs, WAACameraSettingsActivatedEventArgs, WAAAppointmentsProviderAddAppointmentActivatedEventArgs,
    WAAAppointmentsProviderReplaceAppointmentActivatedEventArgs, WAAAppointmentsProviderRemoveAppointmentActivatedEventArgs,
    WAAAppointmentsProviderShowTimeFrameActivatedEventArgs, WAAContactCallActivatedEventArgs, WAAContactMessageActivatedEventArgs,
    WAAContactMapActivatedEventArgs, WAAContactPostActivatedEventArgs, WAAContactVideoCallActivatedEventArgs,
    WAARestrictedLaunchActivatedEventArgs, WAALockScreenCallActivatedEventArgs;
@protocol WAAISplashScreen
, WAAIActivatedEventArgs, WAAIApplicationViewActivatedEventArgs, WAAIPrelaunchActivatedEventArgs, WAAILaunchActivatedEventArgs,
    WAAISearchActivatedEventArgs, WAAISearchActivatedEventArgsWithLinguisticDetails, WAAIShareTargetActivatedEventArgs,
    WAAIFileActivatedEventArgs, WAAIFileActivatedEventArgsWithNeighboringFiles, WAAIProtocolActivatedEventArgs,
    WAAIFileOpenPickerActivatedEventArgs, WAAIFileSavePickerActivatedEventArgs, WAAICachedFileUpdaterActivatedEventArgs,
    WAAIContactPickerActivatedEventArgs, WAAIDeviceActivatedEventArgs, WAAIPrintTaskSettingsActivatedEventArgs,
    WAAICameraSettingsActivatedEventArgs, WAAIAppointmentsProviderActivatedEventArgs,
    WAAIAppointmentsProviderAddAppointmentActivatedEventArgs, WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs,
    WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs, WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs,
    WAAIContactActivatedEventArgs, WAAIContactCallActivatedEventArgs, WAAIContactMessageActivatedEventArgs,
    WAAIContactMapActivatedEventArgs, WAAIContactPostActivatedEventArgs, WAAIContactVideoCallActivatedEventArgs,
    WAAIContactsProviderActivatedEventArgs, WAAIRestrictedLaunchActivatedEventArgs, WAAILockScreenCallActivatedEventArgs;

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
};
typedef unsigned WAAActivationKind;

#include "WindowsFoundation.h"
#include "WindowsStoragePickersProvider.h"
#include "WindowsApplicationModelSearch.h"
#include "WindowsApplicationModelDataTransferShareTarget.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageSearch.h"
#include "WindowsStorage.h"
#include "WindowsStorageProvider.h"
#include "WindowsApplicationModelContactsProvider.h"
#include "WindowsDevicesPrintersExtensions.h"
#include "WindowsApplicationModelAppointmentsAppointmentsProvider.h"
#include "WindowsApplicationModelContacts.h"
#include "WindowsApplicationModelCalls.h"

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

// Windows.ApplicationModel.Activation.IProtocolActivatedEventArgs
#ifndef __WAAIProtocolActivatedEventArgs_DEFINED__
#define __WAAIProtocolActivatedEventArgs_DEFINED__

@protocol WAAIProtocolActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WFUri* uri;
@end

#endif // __WAAIProtocolActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileOpenPickerActivatedEventArgs
#ifndef __WAAIFileOpenPickerActivatedEventArgs_DEFINED__
#define __WAAIFileOpenPickerActivatedEventArgs_DEFINED__

@protocol WAAIFileOpenPickerActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WSPPFileOpenPickerUI* fileOpenPickerUI;
@end

#endif // __WAAIFileOpenPickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IFileSavePickerActivatedEventArgs
#ifndef __WAAIFileSavePickerActivatedEventArgs_DEFINED__
#define __WAAIFileSavePickerActivatedEventArgs_DEFINED__

@protocol WAAIFileSavePickerActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WSPPFileSavePickerUI* fileSavePickerUI;
@end

#endif // __WAAIFileSavePickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ICachedFileUpdaterActivatedEventArgs
#ifndef __WAAICachedFileUpdaterActivatedEventArgs_DEFINED__
#define __WAAICachedFileUpdaterActivatedEventArgs_DEFINED__

@protocol WAAICachedFileUpdaterActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WSPCachedFileUpdaterUI* cachedFileUpdaterUI;
@end

#endif // __WAAICachedFileUpdaterActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactPickerActivatedEventArgs
#ifndef __WAAIContactPickerActivatedEventArgs_DEFINED__
#define __WAAIContactPickerActivatedEventArgs_DEFINED__

@protocol WAAIContactPickerActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WACPContactPickerUI* contactPickerUI;
@end

#endif // __WAAIContactPickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IDeviceActivatedEventArgs
#ifndef __WAAIDeviceActivatedEventArgs_DEFINED__
#define __WAAIDeviceActivatedEventArgs_DEFINED__

@protocol WAAIDeviceActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString* deviceInformationId;
@property (readonly) NSString* verb;
@end

#endif // __WAAIDeviceActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IPrintTaskSettingsActivatedEventArgs
#ifndef __WAAIPrintTaskSettingsActivatedEventArgs_DEFINED__
#define __WAAIPrintTaskSettingsActivatedEventArgs_DEFINED__

@protocol WAAIPrintTaskSettingsActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) WDPEPrintTaskConfiguration* configuration;
@end

#endif // __WAAIPrintTaskSettingsActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ICameraSettingsActivatedEventArgs
#ifndef __WAAICameraSettingsActivatedEventArgs_DEFINED__
#define __WAAICameraSettingsActivatedEventArgs_DEFINED__

@protocol WAAICameraSettingsActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) RTObject* videoDeviceController;
@property (readonly) RTObject* videoDeviceExtension;
@end

#endif // __WAAICameraSettingsActivatedEventArgs_DEFINED__

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

// Windows.ApplicationModel.Activation.IAppointmentsProviderShowTimeFrameActivatedEventArgs
#ifndef __WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__
#define __WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

@protocol WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs <WAAIAppointmentsProviderActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WFTimeSpan* duration;
@property (readonly) WFDateTime* timeToShow;
@end

#endif // __WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs_DEFINED__

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

// Windows.ApplicationModel.Activation.IContactMessageActivatedEventArgs
#ifndef __WAAIContactMessageActivatedEventArgs_DEFINED__
#define __WAAIContactMessageActivatedEventArgs_DEFINED__

@protocol WAAIContactMessageActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString* serviceId;
@property (readonly) NSString* serviceUserId;
@end

#endif // __WAAIContactMessageActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactMapActivatedEventArgs
#ifndef __WAAIContactMapActivatedEventArgs_DEFINED__
#define __WAAIContactMapActivatedEventArgs_DEFINED__

@protocol WAAIContactMapActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContactAddress* address;
@property (readonly) WACContact* contact;
@end

#endif // __WAAIContactMapActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactPostActivatedEventArgs
#ifndef __WAAIContactPostActivatedEventArgs_DEFINED__
#define __WAAIContactPostActivatedEventArgs_DEFINED__

@protocol WAAIContactPostActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString* serviceId;
@property (readonly) NSString* serviceUserId;
@end

#endif // __WAAIContactPostActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactVideoCallActivatedEventArgs
#ifndef __WAAIContactVideoCallActivatedEventArgs_DEFINED__
#define __WAAIContactVideoCallActivatedEventArgs_DEFINED__

@protocol WAAIContactVideoCallActivatedEventArgs <WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString* serviceId;
@property (readonly) NSString* serviceUserId;
@end

#endif // __WAAIContactVideoCallActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IContactsProviderActivatedEventArgs
#ifndef __WAAIContactsProviderActivatedEventArgs_DEFINED__
#define __WAAIContactsProviderActivatedEventArgs_DEFINED__

@protocol WAAIContactsProviderActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) NSString* verb;
@end

#endif // __WAAIContactsProviderActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IRestrictedLaunchActivatedEventArgs
#ifndef __WAAIRestrictedLaunchActivatedEventArgs_DEFINED__
#define __WAAIRestrictedLaunchActivatedEventArgs_DEFINED__

@protocol WAAIRestrictedLaunchActivatedEventArgs <WAAIActivatedEventArgs>
@property (readonly) RTObject* sharedContext;
@end

#endif // __WAAIRestrictedLaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ILockScreenCallActivatedEventArgs
#ifndef __WAAILockScreenCallActivatedEventArgs_DEFINED__
#define __WAAILockScreenCallActivatedEventArgs_DEFINED__

@protocol WAAILockScreenCallActivatedEventArgs <WAAILaunchActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACLockScreenCallUI* callUI;
@end

#endif // __WAAILockScreenCallActivatedEventArgs_DEFINED__

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
                                                   WAAIPrelaunchActivatedEventArgs>
@property (readonly) BOOL prelaunchActivated;
@property (readonly) NSString* arguments;
@property (readonly) NSString* tileId;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@end

#endif // __WAALaunchActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.SearchActivatedEventArgs
#ifndef __WAASearchActivatedEventArgs_DEFINED__
#define __WAASearchActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAASearchActivatedEventArgs : RTObject <WAAISearchActivatedEventArgs,
                                                   WAAIActivatedEventArgs,
                                                   WAAIApplicationViewActivatedEventArgs,
                                                   WAAISearchActivatedEventArgsWithLinguisticDetails>
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) WASSearchPaneQueryLinguisticDetails* linguisticDetails;
@property (readonly) NSString* language;
@property (readonly) NSString* queryText;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
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
                                                 WAAIApplicationViewActivatedEventArgs>
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) id<NSFastEnumeration> /*WSIStorageItem*/ files;
@property (readonly) NSString* verb;
@property (readonly) WSSStorageFileQueryResult* neighboringFilesQuery;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WAAFileActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ProtocolActivatedEventArgs
#ifndef __WAAProtocolActivatedEventArgs_DEFINED__
#define __WAAProtocolActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAProtocolActivatedEventArgs
    : RTObject <WAAIProtocolActivatedEventArgs, WAAIActivatedEventArgs, WAAIApplicationViewActivatedEventArgs>
@property (readonly) WFUri* uri;
@property (readonly) int currentlyShownApplicationViewId;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WAAProtocolActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.FileOpenPickerActivatedEventArgs
#ifndef __WAAFileOpenPickerActivatedEventArgs_DEFINED__
#define __WAAFileOpenPickerActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAFileOpenPickerActivatedEventArgs : RTObject <WAAIFileOpenPickerActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WSPPFileOpenPickerUI* fileOpenPickerUI;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WAAFileOpenPickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.FileSavePickerActivatedEventArgs
#ifndef __WAAFileSavePickerActivatedEventArgs_DEFINED__
#define __WAAFileSavePickerActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAFileSavePickerActivatedEventArgs : RTObject <WAAIFileSavePickerActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WSPPFileSavePickerUI* fileSavePickerUI;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WAAFileSavePickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.CachedFileUpdaterActivatedEventArgs
#ifndef __WAACachedFileUpdaterActivatedEventArgs_DEFINED__
#define __WAACachedFileUpdaterActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAACachedFileUpdaterActivatedEventArgs : RTObject <WAAICachedFileUpdaterActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WSPCachedFileUpdaterUI* cachedFileUpdaterUI;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WAACachedFileUpdaterActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ContactPickerActivatedEventArgs
#ifndef __WAAContactPickerActivatedEventArgs_DEFINED__
#define __WAAContactPickerActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAContactPickerActivatedEventArgs : RTObject <WAAIContactPickerActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACPContactPickerUI* contactPickerUI;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WAAContactPickerActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.DeviceActivatedEventArgs
#ifndef __WAADeviceActivatedEventArgs_DEFINED__
#define __WAADeviceActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAADeviceActivatedEventArgs
    : RTObject <WAAIDeviceActivatedEventArgs, WAAIActivatedEventArgs, WAAIApplicationViewActivatedEventArgs>
@property (readonly) NSString* deviceInformationId;
@property (readonly) NSString* verb;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@end

#endif // __WAADeviceActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.PrintTaskSettingsActivatedEventArgs
#ifndef __WAAPrintTaskSettingsActivatedEventArgs_DEFINED__
#define __WAAPrintTaskSettingsActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAPrintTaskSettingsActivatedEventArgs : RTObject <WAAIPrintTaskSettingsActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WDPEPrintTaskConfiguration* configuration;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WAAPrintTaskSettingsActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.CameraSettingsActivatedEventArgs
#ifndef __WAACameraSettingsActivatedEventArgs_DEFINED__
#define __WAACameraSettingsActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAACameraSettingsActivatedEventArgs : RTObject <WAAICameraSettingsActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) RTObject* videoDeviceController;
@property (readonly) RTObject* videoDeviceExtension;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WAACameraSettingsActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.AppointmentsProviderAddAppointmentActivatedEventArgs
#ifndef __WAAAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__
#define __WAAAppointmentsProviderAddAppointmentActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAAppointmentsProviderAddAppointmentActivatedEventArgs : RTObject <WAAIAppointmentsProviderAddAppointmentActivatedEventArgs,
                                                                               WAAIAppointmentsProviderActivatedEventArgs,
                                                                               WAAIActivatedEventArgs>
@property (readonly) WAAAAddAppointmentOperation* addAppointmentOperation;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* verb;
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
@property (readonly) NSString* verb;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WAAAReplaceAppointmentOperation* replaceAppointmentOperation;
@end

#endif // __WAAAppointmentsProviderReplaceAppointmentActivatedEventArgs_DEFINED__

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
@property (readonly) WAAARemoveAppointmentOperation* removeAppointmentOperation;
@property (readonly) NSString* verb;
@end

#endif // __WAAAppointmentsProviderRemoveAppointmentActivatedEventArgs_DEFINED__

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

// Windows.ApplicationModel.Activation.ContactCallActivatedEventArgs
#ifndef __WAAContactCallActivatedEventArgs_DEFINED__
#define __WAAContactCallActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAContactCallActivatedEventArgs
    : RTObject <WAAIContactCallActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) NSString* verb;
@property (readonly) WACContact* contact;
@property (readonly) NSString* serviceId;
@property (readonly) NSString* serviceUserId;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WAAContactCallActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ContactMessageActivatedEventArgs
#ifndef __WAAContactMessageActivatedEventArgs_DEFINED__
#define __WAAContactMessageActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAContactMessageActivatedEventArgs
    : RTObject <WAAIContactMessageActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString* serviceId;
@property (readonly) NSString* serviceUserId;
@property (readonly) NSString* verb;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WAAContactMessageActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ContactMapActivatedEventArgs
#ifndef __WAAContactMapActivatedEventArgs_DEFINED__
#define __WAAContactMapActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAContactMapActivatedEventArgs
    : RTObject <WAAIContactMapActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContactAddress* address;
@property (readonly) WACContact* contact;
@property (readonly) NSString* verb;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WAAContactMapActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ContactPostActivatedEventArgs
#ifndef __WAAContactPostActivatedEventArgs_DEFINED__
#define __WAAContactPostActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAContactPostActivatedEventArgs
    : RTObject <WAAIContactPostActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString* serviceId;
@property (readonly) NSString* serviceUserId;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) NSString* verb;
@end

#endif // __WAAContactPostActivatedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.ContactVideoCallActivatedEventArgs
#ifndef __WAAContactVideoCallActivatedEventArgs_DEFINED__
#define __WAAContactVideoCallActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAAContactVideoCallActivatedEventArgs
    : RTObject <WAAIContactVideoCallActivatedEventArgs, WAAIContactActivatedEventArgs, WAAIActivatedEventArgs>
@property (readonly) WACContact* contact;
@property (readonly) NSString* serviceId;
@property (readonly) NSString* serviceUserId;
@property (readonly) NSString* verb;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

#endif // __WAAContactVideoCallActivatedEventArgs_DEFINED__

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

// Windows.ApplicationModel.Activation.LockScreenCallActivatedEventArgs
#ifndef __WAALockScreenCallActivatedEventArgs_DEFINED__
#define __WAALockScreenCallActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAALockScreenCallActivatedEventArgs : RTObject <WAAILockScreenCallActivatedEventArgs,
                                                           WAAILaunchActivatedEventArgs,
                                                           WAAIActivatedEventArgs,
                                                           WAAIApplicationViewActivatedEventArgs>
@property (readonly) WACLockScreenCallUI* callUI;
@property (readonly) NSString* arguments;
@property (readonly) NSString* tileId;
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) int currentlyShownApplicationViewId;
@end

#endif // __WAALockScreenCallActivatedEventArgs_DEFINED__
