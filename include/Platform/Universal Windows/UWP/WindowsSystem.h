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

// WindowsSystem.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSDispatcherQueueTimer, WSDispatcherQueue, WSDispatcherQueueShutdownStartingEventArgs, WSDispatcherQueueController, WSUserWatcher, WSUser, WSUserChangedEventArgs, WSUserAuthenticationStatusChangingEventArgs, WSUserAuthenticationStatusChangeDeferral, WSKnownUserProperties, WSUserPicker, WSUserDeviceAssociationChangedEventArgs, WSUserDeviceAssociation, WSAppMemoryUsageLimitChangingEventArgs, WSAppMemoryReport, WSProcessMemoryReport, WSMemoryManager, WSProtocolForResultsOperation, WSAppDiagnosticInfo, WSAppDiagnosticInfoWatcher, WSAppResourceGroupInfo, WSAppResourceGroupInfoWatcher, WSAppDiagnosticInfoWatcherEventArgs, WSAppResourceGroupBackgroundTaskReport, WSAppResourceGroupMemoryReport, WSAppResourceGroupStateReport, WSAppResourceGroupInfoWatcherEventArgs, WSAppResourceGroupInfoWatcherExecutionStateChangedEventArgs, WSLaunchUriResult, WSLauncherUIOptions, WSLauncherOptions, WSRemoteLauncherOptions, WSFolderLauncherOptions, WSLauncher, WSRemoteLauncher, WSDateTimeSettings, WSProcessLauncherOptions, WSProcessLauncherResult, WSProcessLauncher, WSShutdownManager, WSTimeZoneSettings;
@protocol WSIDispatcherQueueShutdownStartingEventArgs, WSIDispatcherQueue, WSIDispatcherQueueController, WSIDispatcherQueueControllerStatics, WSIDispatcherQueueStatics, WSIDispatcherQueueTimer, WSIUser, WSIUserStatics, WSIUserWatcher, WSIUserChangedEventArgs, WSIUserAuthenticationStatusChangeDeferral, WSIUserAuthenticationStatusChangingEventArgs, WSIKnownUserPropertiesStatics, WSIUserPickerStatics, WSIUserPicker, WSIUserDeviceAssociationChangedEventArgs, WSIUserDeviceAssociationStatics, WSIAppMemoryReport, WSIAppMemoryReport2, WSIProcessMemoryReport, WSIAppMemoryUsageLimitChangingEventArgs, WSIMemoryManagerStatics, WSIMemoryManagerStatics2, WSIMemoryManagerStatics3, WSIMemoryManagerStatics4, WSIProtocolForResultsOperation, WSIAppDiagnosticInfoStatics, WSIAppDiagnosticInfoStatics2, WSIAppDiagnosticInfo, WSIAppDiagnosticInfo2, WSIAppDiagnosticInfoWatcherEventArgs, WSIAppDiagnosticInfoWatcher, WSIAppResourceGroupBackgroundTaskReport, WSIAppResourceGroupMemoryReport, WSIAppResourceGroupInfo, WSIAppResourceGroupInfoWatcherEventArgs, WSIAppResourceGroupInfoWatcherExecutionStateChangedEventArgs, WSIAppResourceGroupInfoWatcher, WSIAppResourceGroupStateReport, WSILaunchUriResult, WSILauncherUIOptions, WSILauncherOptions, WSILauncherOptions2, WSILauncherOptions3, WSILauncherOptions4, WSILauncherViewOptions, WSIRemoteLauncherOptions, WSIFolderLauncherOptions, WSILauncherStatics, WSILauncherStatics2, WSILauncherStatics3, WSILauncherStatics4, WSIRemoteLauncherStatics, WSIDateTimeSettingsStatics, WSIProcessLauncherOptions, WSIProcessLauncherStatics, WSIProcessLauncherResult, WSIShutdownManagerStatics, WSIShutdownManagerStatics2, WSITimeZoneSettingsStatics;

// Windows.System.ProcessorArchitecture
enum _WSProcessorArchitecture {
    WSProcessorArchitectureX86 = 0,
    WSProcessorArchitectureArm = 5,
    WSProcessorArchitectureX64 = 9,
    WSProcessorArchitectureNeutral = 11,
    WSProcessorArchitectureUnknown = 65535,
};
typedef unsigned WSProcessorArchitecture;

// Windows.System.DispatcherQueuePriority
enum _WSDispatcherQueuePriority {
    WSDispatcherQueuePriorityLow = -10,
    WSDispatcherQueuePriorityNormal = 0,
    WSDispatcherQueuePriorityHigh = 10,
};
typedef unsigned WSDispatcherQueuePriority;

// Windows.System.UserAuthenticationStatus
enum _WSUserAuthenticationStatus {
    WSUserAuthenticationStatusUnauthenticated = 0,
    WSUserAuthenticationStatusLocallyAuthenticated = 1,
    WSUserAuthenticationStatusRemotelyAuthenticated = 2,
};
typedef unsigned WSUserAuthenticationStatus;

// Windows.System.UserType
enum _WSUserType {
    WSUserTypeLocalUser = 0,
    WSUserTypeRemoteUser = 1,
    WSUserTypeLocalGuest = 2,
    WSUserTypeRemoteGuest = 3,
};
typedef unsigned WSUserType;

// Windows.System.UserPictureSize
enum _WSUserPictureSize {
    WSUserPictureSizeSize64x64 = 0,
    WSUserPictureSizeSize208x208 = 1,
    WSUserPictureSizeSize424x424 = 2,
    WSUserPictureSizeSize1080x1080 = 3,
};
typedef unsigned WSUserPictureSize;

// Windows.System.UserWatcherStatus
enum _WSUserWatcherStatus {
    WSUserWatcherStatusCreated = 0,
    WSUserWatcherStatusStarted = 1,
    WSUserWatcherStatusEnumerationCompleted = 2,
    WSUserWatcherStatusStopping = 3,
    WSUserWatcherStatusStopped = 4,
    WSUserWatcherStatusAborted = 5,
};
typedef unsigned WSUserWatcherStatus;

// Windows.System.AppMemoryUsageLevel
enum _WSAppMemoryUsageLevel {
    WSAppMemoryUsageLevelLow = 0,
    WSAppMemoryUsageLevelMedium = 1,
    WSAppMemoryUsageLevelHigh = 2,
    WSAppMemoryUsageLevelOverLimit = 3,
};
typedef unsigned WSAppMemoryUsageLevel;

// Windows.System.DiagnosticAccessStatus
enum _WSDiagnosticAccessStatus {
    WSDiagnosticAccessStatusUnspecified = 0,
    WSDiagnosticAccessStatusDenied = 1,
    WSDiagnosticAccessStatusLimited = 2,
    WSDiagnosticAccessStatusAllowed = 3,
};
typedef unsigned WSDiagnosticAccessStatus;

// Windows.System.AppDiagnosticInfoWatcherStatus
enum _WSAppDiagnosticInfoWatcherStatus {
    WSAppDiagnosticInfoWatcherStatusCreated = 0,
    WSAppDiagnosticInfoWatcherStatusStarted = 1,
    WSAppDiagnosticInfoWatcherStatusEnumerationCompleted = 2,
    WSAppDiagnosticInfoWatcherStatusStopping = 3,
    WSAppDiagnosticInfoWatcherStatusStopped = 4,
    WSAppDiagnosticInfoWatcherStatusAborted = 5,
};
typedef unsigned WSAppDiagnosticInfoWatcherStatus;

// Windows.System.AppResourceGroupInfoWatcherStatus
enum _WSAppResourceGroupInfoWatcherStatus {
    WSAppResourceGroupInfoWatcherStatusCreated = 0,
    WSAppResourceGroupInfoWatcherStatusStarted = 1,
    WSAppResourceGroupInfoWatcherStatusEnumerationCompleted = 2,
    WSAppResourceGroupInfoWatcherStatusStopping = 3,
    WSAppResourceGroupInfoWatcherStatusStopped = 4,
    WSAppResourceGroupInfoWatcherStatusAborted = 5,
};
typedef unsigned WSAppResourceGroupInfoWatcherStatus;

// Windows.System.AppResourceGroupExecutionState
enum _WSAppResourceGroupExecutionState {
    WSAppResourceGroupExecutionStateUnknown = 0,
    WSAppResourceGroupExecutionStateRunning = 1,
    WSAppResourceGroupExecutionStateSuspending = 2,
    WSAppResourceGroupExecutionStateSuspended = 3,
    WSAppResourceGroupExecutionStateNotRunning = 4,
};
typedef unsigned WSAppResourceGroupExecutionState;

// Windows.System.AppResourceGroupEnergyQuotaState
enum _WSAppResourceGroupEnergyQuotaState {
    WSAppResourceGroupEnergyQuotaStateUnknown = 0,
    WSAppResourceGroupEnergyQuotaStateOver = 1,
    WSAppResourceGroupEnergyQuotaStateUnder = 2,
};
typedef unsigned WSAppResourceGroupEnergyQuotaState;

// Windows.System.VirtualKeyModifiers
enum _WSVirtualKeyModifiers {
    WSVirtualKeyModifiersNone = 0,
    WSVirtualKeyModifiersControl = 1,
    WSVirtualKeyModifiersMenu = 2,
    WSVirtualKeyModifiersShift = 4,
    WSVirtualKeyModifiersWindows = 8,
};
typedef unsigned WSVirtualKeyModifiers;

// Windows.System.VirtualKey
enum _WSVirtualKey {
    WSVirtualKeyNone = 0,
    WSVirtualKeyLeftButton = 1,
    WSVirtualKeyRightButton = 2,
    WSVirtualKeyCancel = 3,
    WSVirtualKeyMiddleButton = 4,
    WSVirtualKeyXButton1 = 5,
    WSVirtualKeyXButton2 = 6,
    WSVirtualKeyBack = 8,
    WSVirtualKeyTab = 9,
    WSVirtualKeyClear = 12,
    WSVirtualKeyEnter = 13,
    WSVirtualKeyShift = 16,
    WSVirtualKeyControl = 17,
    WSVirtualKeyMenu = 18,
    WSVirtualKeyPause = 19,
    WSVirtualKeyCapitalLock = 20,
    WSVirtualKeyKana = 21,
    WSVirtualKeyHangul = 21,
    WSVirtualKeyJunja = 23,
    WSVirtualKeyFinal = 24,
    WSVirtualKeyHanja = 25,
    WSVirtualKeyKanji = 25,
    WSVirtualKeyEscape = 27,
    WSVirtualKeyConvert = 28,
    WSVirtualKeyNonConvert = 29,
    WSVirtualKeyAccept = 30,
    WSVirtualKeyModeChange = 31,
    WSVirtualKeySpace = 32,
    WSVirtualKeyPageUp = 33,
    WSVirtualKeyPageDown = 34,
    WSVirtualKeyEnd = 35,
    WSVirtualKeyHome = 36,
    WSVirtualKeyLeft = 37,
    WSVirtualKeyUp = 38,
    WSVirtualKeyRight = 39,
    WSVirtualKeyDown = 40,
    WSVirtualKeySelect = 41,
    WSVirtualKeyPrint = 42,
    WSVirtualKeyExecute = 43,
    WSVirtualKeySnapshot = 44,
    WSVirtualKeyInsert = 45,
    WSVirtualKeyDelete = 46,
    WSVirtualKeyHelp = 47,
    WSVirtualKeyNumber0 = 48,
    WSVirtualKeyNumber1 = 49,
    WSVirtualKeyNumber2 = 50,
    WSVirtualKeyNumber3 = 51,
    WSVirtualKeyNumber4 = 52,
    WSVirtualKeyNumber5 = 53,
    WSVirtualKeyNumber6 = 54,
    WSVirtualKeyNumber7 = 55,
    WSVirtualKeyNumber8 = 56,
    WSVirtualKeyNumber9 = 57,
    WSVirtualKeyA = 65,
    WSVirtualKeyB = 66,
    WSVirtualKeyC = 67,
    WSVirtualKeyD = 68,
    WSVirtualKeyE = 69,
    WSVirtualKeyF = 70,
    WSVirtualKeyG = 71,
    WSVirtualKeyH = 72,
    WSVirtualKeyI = 73,
    WSVirtualKeyJ = 74,
    WSVirtualKeyK = 75,
    WSVirtualKeyL = 76,
    WSVirtualKeyM = 77,
    WSVirtualKeyN = 78,
    WSVirtualKeyO = 79,
    WSVirtualKeyP = 80,
    WSVirtualKeyQ = 81,
    WSVirtualKeyR = 82,
    WSVirtualKeyS = 83,
    WSVirtualKeyT = 84,
    WSVirtualKeyU = 85,
    WSVirtualKeyV = 86,
    WSVirtualKeyW = 87,
    WSVirtualKeyX = 88,
    WSVirtualKeyY = 89,
    WSVirtualKeyZ = 90,
    WSVirtualKeyLeftWindows = 91,
    WSVirtualKeyRightWindows = 92,
    WSVirtualKeyApplication = 93,
    WSVirtualKeySleep = 95,
    WSVirtualKeyNumberPad0 = 96,
    WSVirtualKeyNumberPad1 = 97,
    WSVirtualKeyNumberPad2 = 98,
    WSVirtualKeyNumberPad3 = 99,
    WSVirtualKeyNumberPad4 = 100,
    WSVirtualKeyNumberPad5 = 101,
    WSVirtualKeyNumberPad6 = 102,
    WSVirtualKeyNumberPad7 = 103,
    WSVirtualKeyNumberPad8 = 104,
    WSVirtualKeyNumberPad9 = 105,
    WSVirtualKeyMultiply = 106,
    WSVirtualKeyAdd = 107,
    WSVirtualKeySeparator = 108,
    WSVirtualKeySubtract = 109,
    WSVirtualKeyDecimal = 110,
    WSVirtualKeyDivide = 111,
    WSVirtualKeyF1 = 112,
    WSVirtualKeyF2 = 113,
    WSVirtualKeyF3 = 114,
    WSVirtualKeyF4 = 115,
    WSVirtualKeyF5 = 116,
    WSVirtualKeyF6 = 117,
    WSVirtualKeyF7 = 118,
    WSVirtualKeyF8 = 119,
    WSVirtualKeyF9 = 120,
    WSVirtualKeyF10 = 121,
    WSVirtualKeyF11 = 122,
    WSVirtualKeyF12 = 123,
    WSVirtualKeyF13 = 124,
    WSVirtualKeyF14 = 125,
    WSVirtualKeyF15 = 126,
    WSVirtualKeyF16 = 127,
    WSVirtualKeyF17 = 128,
    WSVirtualKeyF18 = 129,
    WSVirtualKeyF19 = 130,
    WSVirtualKeyF20 = 131,
    WSVirtualKeyF21 = 132,
    WSVirtualKeyF22 = 133,
    WSVirtualKeyF23 = 134,
    WSVirtualKeyF24 = 135,
    WSVirtualKeyNavigationView = 136,
    WSVirtualKeyNavigationMenu = 137,
    WSVirtualKeyNavigationUp = 138,
    WSVirtualKeyNavigationDown = 139,
    WSVirtualKeyNavigationLeft = 140,
    WSVirtualKeyNavigationRight = 141,
    WSVirtualKeyNavigationAccept = 142,
    WSVirtualKeyNavigationCancel = 143,
    WSVirtualKeyNumberKeyLock = 144,
    WSVirtualKeyScroll = 145,
    WSVirtualKeyLeftShift = 160,
    WSVirtualKeyRightShift = 161,
    WSVirtualKeyLeftControl = 162,
    WSVirtualKeyRightControl = 163,
    WSVirtualKeyLeftMenu = 164,
    WSVirtualKeyRightMenu = 165,
    WSVirtualKeyGoBack = 166,
    WSVirtualKeyGoForward = 167,
    WSVirtualKeyRefresh = 168,
    WSVirtualKeyStop = 169,
    WSVirtualKeySearch = 170,
    WSVirtualKeyFavorites = 171,
    WSVirtualKeyGoHome = 172,
    WSVirtualKeyGamepadA = 195,
    WSVirtualKeyGamepadB = 196,
    WSVirtualKeyGamepadX = 197,
    WSVirtualKeyGamepadY = 198,
    WSVirtualKeyGamepadRightShoulder = 199,
    WSVirtualKeyGamepadLeftShoulder = 200,
    WSVirtualKeyGamepadLeftTrigger = 201,
    WSVirtualKeyGamepadRightTrigger = 202,
    WSVirtualKeyGamepadDPadUp = 203,
    WSVirtualKeyGamepadDPadDown = 204,
    WSVirtualKeyGamepadDPadLeft = 205,
    WSVirtualKeyGamepadDPadRight = 206,
    WSVirtualKeyGamepadMenu = 207,
    WSVirtualKeyGamepadView = 208,
    WSVirtualKeyGamepadLeftThumbstickButton = 209,
    WSVirtualKeyGamepadRightThumbstickButton = 210,
    WSVirtualKeyGamepadLeftThumbstickUp = 211,
    WSVirtualKeyGamepadLeftThumbstickDown = 212,
    WSVirtualKeyGamepadLeftThumbstickRight = 213,
    WSVirtualKeyGamepadLeftThumbstickLeft = 214,
    WSVirtualKeyGamepadRightThumbstickUp = 215,
    WSVirtualKeyGamepadRightThumbstickDown = 216,
    WSVirtualKeyGamepadRightThumbstickRight = 217,
    WSVirtualKeyGamepadRightThumbstickLeft = 218,
};
typedef unsigned WSVirtualKey;

// Windows.System.LaunchQuerySupportType
enum _WSLaunchQuerySupportType {
    WSLaunchQuerySupportTypeUri = 0,
    WSLaunchQuerySupportTypeUriForResults = 1,
};
typedef unsigned WSLaunchQuerySupportType;

// Windows.System.LaunchQuerySupportStatus
enum _WSLaunchQuerySupportStatus {
    WSLaunchQuerySupportStatusAvailable = 0,
    WSLaunchQuerySupportStatusAppNotInstalled = 1,
    WSLaunchQuerySupportStatusAppUnavailable = 2,
    WSLaunchQuerySupportStatusNotSupported = 3,
    WSLaunchQuerySupportStatusUnknown = 4,
};
typedef unsigned WSLaunchQuerySupportStatus;

// Windows.System.LaunchUriStatus
enum _WSLaunchUriStatus {
    WSLaunchUriStatusSuccess = 0,
    WSLaunchUriStatusAppUnavailable = 1,
    WSLaunchUriStatusProtocolUnavailable = 2,
    WSLaunchUriStatusUnknown = 3,
};
typedef unsigned WSLaunchUriStatus;

// Windows.System.LaunchFileStatus
enum _WSLaunchFileStatus {
    WSLaunchFileStatusSuccess = 0,
    WSLaunchFileStatusAppUnavailable = 1,
    WSLaunchFileStatusDeniedByPolicy = 2,
    WSLaunchFileStatusFileTypeNotSupported = 3,
    WSLaunchFileStatusUnknown = 4,
};
typedef unsigned WSLaunchFileStatus;

// Windows.System.RemoteLaunchUriStatus
enum _WSRemoteLaunchUriStatus {
    WSRemoteLaunchUriStatusUnknown = 0,
    WSRemoteLaunchUriStatusSuccess = 1,
    WSRemoteLaunchUriStatusAppUnavailable = 2,
    WSRemoteLaunchUriStatusProtocolUnavailable = 3,
    WSRemoteLaunchUriStatusRemoteSystemUnavailable = 4,
    WSRemoteLaunchUriStatusValueSetTooLarge = 5,
    WSRemoteLaunchUriStatusDeniedByLocalSystem = 6,
    WSRemoteLaunchUriStatusDeniedByRemoteSystem = 7,
};
typedef unsigned WSRemoteLaunchUriStatus;

// Windows.System.ShutdownKind
enum _WSShutdownKind {
    WSShutdownKindShutdown = 0,
    WSShutdownKindRestart = 1,
};
typedef unsigned WSShutdownKind;

// Windows.System.PowerState
enum _WSPowerState {
    WSPowerStateConnectedStandby = 0,
    WSPowerStateSleepS3 = 1,
};
typedef unsigned WSPowerState;

#include "WindowsApplicationModel.h"
#include "WindowsUIPopups.h"
#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsSystemDiagnostics.h"
#include "WindowsStorageSearch.h"
#include "WindowsUIViewManagement.h"
#include "WindowsStorage.h"
#include "WindowsSystemRemoteSystems.h"
// Windows.System.DispatcherQueueHandler
#ifndef __WSDispatcherQueueHandler__DEFINED
#define __WSDispatcherQueueHandler__DEFINED
typedef void(^WSDispatcherQueueHandler)();
#endif // __WSDispatcherQueueHandler__DEFINED


#import <Foundation/Foundation.h>

// Windows.System.DispatcherQueueHandler
#ifndef __WSDispatcherQueueHandler__DEFINED
#define __WSDispatcherQueueHandler__DEFINED
typedef void(^WSDispatcherQueueHandler)();
#endif // __WSDispatcherQueueHandler__DEFINED

// Windows.System.ILauncherViewOptions
#ifndef __WSILauncherViewOptions_DEFINED__
#define __WSILauncherViewOptions_DEFINED__

@protocol WSILauncherViewOptions
@property WUVViewSizePreference desiredRemainingView;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSILauncherViewOptions : RTObject <WSILauncherViewOptions>
@end

#endif // __WSILauncherViewOptions_DEFINED__

// Windows.System.DispatcherQueueTimer
#ifndef __WSDispatcherQueueTimer_DEFINED__
#define __WSDispatcherQueueTimer_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDispatcherQueueTimer : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isRepeating;
@property (retain) WFTimeSpan* interval;
@property (readonly) BOOL isRunning;
- (EventRegistrationToken)addTickEvent:(void(^)(WSDispatcherQueueTimer*, RTObject*))del;
- (void)removeTickEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WSDispatcherQueueTimer_DEFINED__

// Windows.System.DispatcherQueue
#ifndef __WSDispatcherQueue_DEFINED__
#define __WSDispatcherQueue_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDispatcherQueue : RTObject
+ (WSDispatcherQueue*)getForCurrentThread;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addShutdownCompletedEvent:(void(^)(WSDispatcherQueue*, RTObject*))del;
- (void)removeShutdownCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addShutdownStartingEvent:(void(^)(WSDispatcherQueue*, WSDispatcherQueueShutdownStartingEventArgs*))del;
- (void)removeShutdownStartingEvent:(EventRegistrationToken)tok;
- (WSDispatcherQueueTimer*)createTimer;
- (BOOL)tryEnqueue:(WSDispatcherQueueHandler)callback;
- (BOOL)tryEnqueueWithPriority:(WSDispatcherQueuePriority)priority callback:(WSDispatcherQueueHandler)callback;
@end

#endif // __WSDispatcherQueue_DEFINED__

// Windows.System.DispatcherQueueShutdownStartingEventArgs
#ifndef __WSDispatcherQueueShutdownStartingEventArgs_DEFINED__
#define __WSDispatcherQueueShutdownStartingEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDispatcherQueueShutdownStartingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WFDeferral*)getDeferral;
@end

#endif // __WSDispatcherQueueShutdownStartingEventArgs_DEFINED__

// Windows.System.DispatcherQueueController
#ifndef __WSDispatcherQueueController_DEFINED__
#define __WSDispatcherQueueController_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDispatcherQueueController : RTObject
+ (WSDispatcherQueueController*)createOnDedicatedThread;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSDispatcherQueue* dispatcherQueue;
- (RTObject<WFIAsyncAction>*)shutdownQueueAsync;
@end

#endif // __WSDispatcherQueueController_DEFINED__

// Windows.System.UserWatcher
#ifndef __WSUserWatcher_DEFINED__
#define __WSUserWatcher_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSUserWatcher : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSUserWatcherStatus status;
- (EventRegistrationToken)addAddedEvent:(void(^)(WSUserWatcher*, WSUserChangedEventArgs*))del;
- (void)removeAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAuthenticationStatusChangedEvent:(void(^)(WSUserWatcher*, WSUserChangedEventArgs*))del;
- (void)removeAuthenticationStatusChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAuthenticationStatusChangingEvent:(void(^)(WSUserWatcher*, WSUserAuthenticationStatusChangingEventArgs*))del;
- (void)removeAuthenticationStatusChangingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addEnumerationCompletedEvent:(void(^)(WSUserWatcher*, RTObject*))del;
- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRemovedEvent:(void(^)(WSUserWatcher*, WSUserChangedEventArgs*))del;
- (void)removeRemovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStoppedEvent:(void(^)(WSUserWatcher*, RTObject*))del;
- (void)removeStoppedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUpdatedEvent:(void(^)(WSUserWatcher*, WSUserChangedEventArgs*))del;
- (void)removeUpdatedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WSUserWatcher_DEFINED__

// Windows.System.User
#ifndef __WSUser_DEFINED__
#define __WSUser_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSUser : RTObject
+ (WSUserWatcher*)createWatcher;
+ (void)findAllAsyncWithSuccess:(void (^)(NSArray* /* WSUser* */))success failure:(void (^)(NSError*))failure;
+ (void)findAllAsyncByType:(WSUserType)type success:(void (^)(NSArray* /* WSUser* */))success failure:(void (^)(NSError*))failure;
+ (void)findAllAsyncByTypeAndStatus:(WSUserType)type status:(WSUserAuthenticationStatus)status success:(void (^)(NSArray* /* WSUser* */))success failure:(void (^)(NSError*))failure;
+ (WSUser*)getFromId:(NSString *)nonRoamableId;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSUserAuthenticationStatus authenticationStatus;
@property (readonly) NSString * nonRoamableId;
@property (readonly) WSUserType type;
- (void)getPropertyAsync:(NSString *)value success:(void (^)(RTObject*))success failure:(void (^)(NSError*))failure;
- (void)getPropertiesAsync:(NSArray* /* NSString * */)values success:(void (^)(RTObject<WFCIPropertySet>*))success failure:(void (^)(NSError*))failure;
- (void)getPictureAsync:(WSUserPictureSize)desiredSize success:(void (^)(RTObject<WSSIRandomAccessStreamReference>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSUser_DEFINED__

// Windows.System.UserChangedEventArgs
#ifndef __WSUserChangedEventArgs_DEFINED__
#define __WSUserChangedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSUserChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSUser* user;
@end

#endif // __WSUserChangedEventArgs_DEFINED__

// Windows.System.UserAuthenticationStatusChangingEventArgs
#ifndef __WSUserAuthenticationStatusChangingEventArgs_DEFINED__
#define __WSUserAuthenticationStatusChangingEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSUserAuthenticationStatusChangingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSUserAuthenticationStatus currentStatus;
@property (readonly) WSUserAuthenticationStatus newStatus;
@property (readonly) WSUser* user;
- (WSUserAuthenticationStatusChangeDeferral*)getDeferral;
@end

#endif // __WSUserAuthenticationStatusChangingEventArgs_DEFINED__

// Windows.System.UserAuthenticationStatusChangeDeferral
#ifndef __WSUserAuthenticationStatusChangeDeferral_DEFINED__
#define __WSUserAuthenticationStatusChangeDeferral_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSUserAuthenticationStatusChangeDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WSUserAuthenticationStatusChangeDeferral_DEFINED__

// Windows.System.KnownUserProperties
#ifndef __WSKnownUserProperties_DEFINED__
#define __WSKnownUserProperties_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSKnownUserProperties : RTObject
+ (NSString *)accountName;
+ (NSString *)displayName;
+ (NSString *)domainName;
+ (NSString *)firstName;
+ (NSString *)guestHost;
+ (NSString *)lastName;
+ (NSString *)principalName;
+ (NSString *)providerName;
+ (NSString *)sessionInitiationProtocolUri;
@end

#endif // __WSKnownUserProperties_DEFINED__

// Windows.System.UserPicker
#ifndef __WSUserPicker_DEFINED__
#define __WSUserPicker_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSUserPicker : RTObject
+ (BOOL)isSupported;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WSUser* suggestedSelectedUser;
@property BOOL allowGuestAccounts;
- (void)pickSingleUserAsyncWithSuccess:(void (^)(WSUser*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSUserPicker_DEFINED__

// Windows.System.UserDeviceAssociationChangedEventArgs
#ifndef __WSUserDeviceAssociationChangedEventArgs_DEFINED__
#define __WSUserDeviceAssociationChangedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSUserDeviceAssociationChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * deviceId;
@property (readonly) WSUser* newUser __attribute__ ((ns_returns_not_retained));
@property (readonly) WSUser* oldUser;
@end

#endif // __WSUserDeviceAssociationChangedEventArgs_DEFINED__

// Windows.System.UserDeviceAssociation
#ifndef __WSUserDeviceAssociation_DEFINED__
#define __WSUserDeviceAssociation_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSUserDeviceAssociation : RTObject
+ (WSUser*)findUserFromDeviceId:(NSString *)deviceId;
+ (EventRegistrationToken)addUserDeviceAssociationChangedEvent:(void(^)(RTObject*, WSUserDeviceAssociationChangedEventArgs*))del;
+ (void)removeUserDeviceAssociationChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WSUserDeviceAssociation_DEFINED__

// Windows.System.AppMemoryUsageLimitChangingEventArgs
#ifndef __WSAppMemoryUsageLimitChangingEventArgs_DEFINED__
#define __WSAppMemoryUsageLimitChangingEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAppMemoryUsageLimitChangingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) uint64_t newLimit;
@property (readonly) uint64_t oldLimit;
@end

#endif // __WSAppMemoryUsageLimitChangingEventArgs_DEFINED__

// Windows.System.AppMemoryReport
#ifndef __WSAppMemoryReport_DEFINED__
#define __WSAppMemoryReport_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAppMemoryReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) uint64_t peakPrivateCommitUsage;
@property (readonly) uint64_t privateCommitUsage;
@property (readonly) uint64_t totalCommitLimit;
@property (readonly) uint64_t totalCommitUsage;
@property (readonly) uint64_t expectedTotalCommitLimit;
@end

#endif // __WSAppMemoryReport_DEFINED__

// Windows.System.ProcessMemoryReport
#ifndef __WSProcessMemoryReport_DEFINED__
#define __WSProcessMemoryReport_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSProcessMemoryReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) uint64_t privateWorkingSetUsage;
@property (readonly) uint64_t totalWorkingSetUsage;
@end

#endif // __WSProcessMemoryReport_DEFINED__

// Windows.System.MemoryManager
#ifndef __WSMemoryManager_DEFINED__
#define __WSMemoryManager_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSMemoryManager : RTObject
+ (BOOL)trySetAppMemoryUsageLimit:(uint64_t)value;
+ (WSAppMemoryReport*)getAppMemoryReport;
+ (WSProcessMemoryReport*)getProcessMemoryReport;
+ (uint64_t)appMemoryUsage;
+ (WSAppMemoryUsageLevel)appMemoryUsageLevel;
+ (uint64_t)appMemoryUsageLimit;
+ (uint64_t)expectedAppMemoryUsageLimit;
+ (EventRegistrationToken)addAppMemoryUsageDecreasedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeAppMemoryUsageDecreasedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addAppMemoryUsageIncreasedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeAppMemoryUsageIncreasedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addAppMemoryUsageLimitChangingEvent:(void(^)(RTObject*, WSAppMemoryUsageLimitChangingEventArgs*))del;
+ (void)removeAppMemoryUsageLimitChangingEvent:(EventRegistrationToken)tok;
@end

#endif // __WSMemoryManager_DEFINED__

// Windows.System.ProtocolForResultsOperation
#ifndef __WSProtocolForResultsOperation_DEFINED__
#define __WSProtocolForResultsOperation_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSProtocolForResultsOperation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)reportCompleted:(WFCValueSet*)data;
@end

#endif // __WSProtocolForResultsOperation_DEFINED__

// Windows.System.AppDiagnosticInfo
#ifndef __WSAppDiagnosticInfo_DEFINED__
#define __WSAppDiagnosticInfo_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAppDiagnosticInfo : RTObject
+ (WSAppDiagnosticInfoWatcher*)createWatcher;
+ (void)requestAccessAsyncWithSuccess:(void (^)(WSDiagnosticAccessStatus))success failure:(void (^)(NSError*))failure;
+ (void)requestInfoForPackageAsync:(NSString *)packageFamilyName success:(void (^)(NSMutableArray* /* WSAppDiagnosticInfo* */))success failure:(void (^)(NSError*))failure;
+ (void)requestInfoForAppAsyncWithSuccess:(void (^)(NSMutableArray* /* WSAppDiagnosticInfo* */))success failure:(void (^)(NSError*))failure;
+ (void)requestInfoForAppUserModelId:(NSString *)appUserModelId success:(void (^)(NSMutableArray* /* WSAppDiagnosticInfo* */))success failure:(void (^)(NSError*))failure;
+ (void)requestInfoAsyncWithSuccess:(void (^)(NSMutableArray* /* WSAppDiagnosticInfo* */))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAppInfo* appInfo;
- (NSMutableArray* /* WSAppResourceGroupInfo* */)getResourceGroups;
- (WSAppResourceGroupInfoWatcher*)createResourceGroupWatcher;
@end

#endif // __WSAppDiagnosticInfo_DEFINED__

// Windows.System.AppDiagnosticInfoWatcher
#ifndef __WSAppDiagnosticInfoWatcher_DEFINED__
#define __WSAppDiagnosticInfoWatcher_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAppDiagnosticInfoWatcher : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSAppDiagnosticInfoWatcherStatus status;
- (EventRegistrationToken)addAddedEvent:(void(^)(WSAppDiagnosticInfoWatcher*, WSAppDiagnosticInfoWatcherEventArgs*))del;
- (void)removeAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addEnumerationCompletedEvent:(void(^)(WSAppDiagnosticInfoWatcher*, RTObject*))del;
- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRemovedEvent:(void(^)(WSAppDiagnosticInfoWatcher*, WSAppDiagnosticInfoWatcherEventArgs*))del;
- (void)removeRemovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStoppedEvent:(void(^)(WSAppDiagnosticInfoWatcher*, RTObject*))del;
- (void)removeStoppedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WSAppDiagnosticInfoWatcher_DEFINED__

// Windows.System.AppResourceGroupInfo
#ifndef __WSAppResourceGroupInfo_DEFINED__
#define __WSAppResourceGroupInfo_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAppResourceGroupInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFGUID* instanceId;
@property (readonly) BOOL isShared;
- (NSMutableArray* /* WSAppResourceGroupBackgroundTaskReport* */)getBackgroundTaskReports;
- (WSAppResourceGroupMemoryReport*)getMemoryReport;
- (NSMutableArray* /* WSDProcessDiagnosticInfo* */)getProcessDiagnosticInfos;
- (WSAppResourceGroupStateReport*)getStateReport;
@end

#endif // __WSAppResourceGroupInfo_DEFINED__

// Windows.System.AppResourceGroupInfoWatcher
#ifndef __WSAppResourceGroupInfoWatcher_DEFINED__
#define __WSAppResourceGroupInfoWatcher_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAppResourceGroupInfoWatcher : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSAppResourceGroupInfoWatcherStatus status;
- (EventRegistrationToken)addAddedEvent:(void(^)(WSAppResourceGroupInfoWatcher*, WSAppResourceGroupInfoWatcherEventArgs*))del;
- (void)removeAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addEnumerationCompletedEvent:(void(^)(WSAppResourceGroupInfoWatcher*, RTObject*))del;
- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addExecutionStateChangedEvent:(void(^)(WSAppResourceGroupInfoWatcher*, WSAppResourceGroupInfoWatcherExecutionStateChangedEventArgs*))del;
- (void)removeExecutionStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRemovedEvent:(void(^)(WSAppResourceGroupInfoWatcher*, WSAppResourceGroupInfoWatcherEventArgs*))del;
- (void)removeRemovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStoppedEvent:(void(^)(WSAppResourceGroupInfoWatcher*, RTObject*))del;
- (void)removeStoppedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WSAppResourceGroupInfoWatcher_DEFINED__

// Windows.System.AppDiagnosticInfoWatcherEventArgs
#ifndef __WSAppDiagnosticInfoWatcherEventArgs_DEFINED__
#define __WSAppDiagnosticInfoWatcherEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAppDiagnosticInfoWatcherEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSAppDiagnosticInfo* appDiagnosticInfo;
@end

#endif // __WSAppDiagnosticInfoWatcherEventArgs_DEFINED__

// Windows.System.AppResourceGroupBackgroundTaskReport
#ifndef __WSAppResourceGroupBackgroundTaskReport_DEFINED__
#define __WSAppResourceGroupBackgroundTaskReport_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAppResourceGroupBackgroundTaskReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * entryPoint;
@property (readonly) NSString * name;
@property (readonly) WFGUID* taskId;
@property (readonly) NSString * trigger;
@end

#endif // __WSAppResourceGroupBackgroundTaskReport_DEFINED__

// Windows.System.AppResourceGroupMemoryReport
#ifndef __WSAppResourceGroupMemoryReport_DEFINED__
#define __WSAppResourceGroupMemoryReport_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAppResourceGroupMemoryReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSAppMemoryUsageLevel commitUsageLevel;
@property (readonly) uint64_t commitUsageLimit;
@property (readonly) uint64_t privateCommitUsage;
@property (readonly) uint64_t totalCommitUsage;
@end

#endif // __WSAppResourceGroupMemoryReport_DEFINED__

// Windows.System.AppResourceGroupStateReport
#ifndef __WSAppResourceGroupStateReport_DEFINED__
#define __WSAppResourceGroupStateReport_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAppResourceGroupStateReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSAppResourceGroupEnergyQuotaState energyQuotaState;
@property (readonly) WSAppResourceGroupExecutionState executionState;
@end

#endif // __WSAppResourceGroupStateReport_DEFINED__

// Windows.System.AppResourceGroupInfoWatcherEventArgs
#ifndef __WSAppResourceGroupInfoWatcherEventArgs_DEFINED__
#define __WSAppResourceGroupInfoWatcherEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAppResourceGroupInfoWatcherEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WSAppDiagnosticInfo* */ appDiagnosticInfos;
@property (readonly) WSAppResourceGroupInfo* appResourceGroupInfo;
@end

#endif // __WSAppResourceGroupInfoWatcherEventArgs_DEFINED__

// Windows.System.AppResourceGroupInfoWatcherExecutionStateChangedEventArgs
#ifndef __WSAppResourceGroupInfoWatcherExecutionStateChangedEventArgs_DEFINED__
#define __WSAppResourceGroupInfoWatcherExecutionStateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAppResourceGroupInfoWatcherExecutionStateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WSAppDiagnosticInfo* */ appDiagnosticInfos;
@property (readonly) WSAppResourceGroupInfo* appResourceGroupInfo;
@end

#endif // __WSAppResourceGroupInfoWatcherExecutionStateChangedEventArgs_DEFINED__

// Windows.System.LaunchUriResult
#ifndef __WSLaunchUriResult_DEFINED__
#define __WSLaunchUriResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSLaunchUriResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFCValueSet* result;
@property (readonly) WSLaunchUriStatus status;
@end

#endif // __WSLaunchUriResult_DEFINED__

// Windows.System.LauncherUIOptions
#ifndef __WSLauncherUIOptions_DEFINED__
#define __WSLauncherUIOptions_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSLauncherUIOptions : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* WFRect* */ selectionRect;
@property WUPPlacement preferredPlacement;
@property (retain) id /* WFPoint* */ invocationPoint;
@end

#endif // __WSLauncherUIOptions_DEFINED__

// Windows.System.LauncherOptions
#ifndef __WSLauncherOptions_DEFINED__
#define __WSLauncherOptions_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSLauncherOptions : RTObject <WSILauncherViewOptions>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL treatAsUntrusted;
@property (retain) NSString * preferredApplicationPackageFamilyName;
@property (retain) NSString * preferredApplicationDisplayName;
@property (retain) WFUri* fallbackUri;
@property BOOL displayApplicationPicker;
@property (retain) NSString * contentType;
@property (readonly) WSLauncherUIOptions* uI;
@property (retain) NSString * targetApplicationPackageFamilyName;
@property (retain) WSSStorageFileQueryResult* neighboringFilesQuery;
@property BOOL ignoreAppUriHandlers;
@property BOOL limitPickerToCurrentAppAndAppUriHandlers;
@property WUVViewSizePreference desiredRemainingView;
@end

#endif // __WSLauncherOptions_DEFINED__

// Windows.System.RemoteLauncherOptions
#ifndef __WSRemoteLauncherOptions_DEFINED__
#define __WSRemoteLauncherOptions_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSRemoteLauncherOptions : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* fallbackUri;
@property (readonly) NSMutableArray* /* NSString * */ preferredAppIds;
@end

#endif // __WSRemoteLauncherOptions_DEFINED__

// Windows.System.FolderLauncherOptions
#ifndef __WSFolderLauncherOptions_DEFINED__
#define __WSFolderLauncherOptions_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSFolderLauncherOptions : RTObject <WSILauncherViewOptions>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray* /* RTObject<WSIStorageItem>* */ itemsToSelect;
@property WUVViewSizePreference desiredRemainingView;
@end

#endif // __WSFolderLauncherOptions_DEFINED__

// Windows.System.Launcher
#ifndef __WSLauncher_DEFINED__
#define __WSLauncher_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSLauncher : RTObject
+ (void)launchFileAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)launchFileWithOptionsAsync:(RTObject<WSIStorageFile>*)file options:(WSLauncherOptions*)options success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)launchUriAsync:(WFUri*)uri success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)launchUriWithOptionsAsync:(WFUri*)uri options:(WSLauncherOptions*)options success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)queryAppUriSupportAsync:(WFUri*)uri success:(void (^)(WSLaunchQuerySupportStatus))success failure:(void (^)(NSError*))failure;
+ (void)queryAppUriSupportWithPackageFamilyNameAsync:(WFUri*)uri packageFamilyName:(NSString *)packageFamilyName success:(void (^)(WSLaunchQuerySupportStatus))success failure:(void (^)(NSError*))failure;
+ (void)findAppUriHandlersAsync:(WFUri*)uri success:(void (^)(NSArray* /* WAAppInfo* */))success failure:(void (^)(NSError*))failure;
+ (void)launchUriForUserAsync:(WSUser*)user uri:(WFUri*)uri success:(void (^)(WSLaunchUriStatus))success failure:(void (^)(NSError*))failure;
+ (void)launchUriWithOptionsForUserAsync:(WSUser*)user uri:(WFUri*)uri options:(WSLauncherOptions*)options success:(void (^)(WSLaunchUriStatus))success failure:(void (^)(NSError*))failure;
+ (void)launchUriWithDataForUserAsync:(WSUser*)user uri:(WFUri*)uri options:(WSLauncherOptions*)options inputData:(WFCValueSet*)inputData success:(void (^)(WSLaunchUriStatus))success failure:(void (^)(NSError*))failure;
+ (void)launchUriForResultsForUserAsync:(WSUser*)user uri:(WFUri*)uri options:(WSLauncherOptions*)options success:(void (^)(WSLaunchUriResult*))success failure:(void (^)(NSError*))failure;
+ (void)launchUriForResultsWithDataForUserAsync:(WSUser*)user uri:(WFUri*)uri options:(WSLauncherOptions*)options inputData:(WFCValueSet*)inputData success:(void (^)(WSLaunchUriResult*))success failure:(void (^)(NSError*))failure;
+ (void)launchFolderAsync:(RTObject<WSIStorageFolder>*)folder success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)launchFolderWithOptionsAsync:(RTObject<WSIStorageFolder>*)folder options:(WSFolderLauncherOptions*)options success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)launchUriForResultsAsync:(WFUri*)uri options:(WSLauncherOptions*)options success:(void (^)(WSLaunchUriResult*))success failure:(void (^)(NSError*))failure;
+ (void)launchUriForResultsWithDataAsync:(WFUri*)uri options:(WSLauncherOptions*)options inputData:(WFCValueSet*)inputData success:(void (^)(WSLaunchUriResult*))success failure:(void (^)(NSError*))failure;
+ (void)launchUriWithDataAsync:(WFUri*)uri options:(WSLauncherOptions*)options inputData:(WFCValueSet*)inputData success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)queryUriSupportAsync:(WFUri*)uri launchQuerySupportType:(WSLaunchQuerySupportType)launchQuerySupportType success:(void (^)(WSLaunchQuerySupportStatus))success failure:(void (^)(NSError*))failure;
+ (void)queryUriSupportWithPackageFamilyNameAsync:(WFUri*)uri launchQuerySupportType:(WSLaunchQuerySupportType)launchQuerySupportType packageFamilyName:(NSString *)packageFamilyName success:(void (^)(WSLaunchQuerySupportStatus))success failure:(void (^)(NSError*))failure;
+ (void)queryFileSupportAsync:(WSStorageFile*)file success:(void (^)(WSLaunchQuerySupportStatus))success failure:(void (^)(NSError*))failure;
+ (void)queryFileSupportWithPackageFamilyNameAsync:(WSStorageFile*)file packageFamilyName:(NSString *)packageFamilyName success:(void (^)(WSLaunchQuerySupportStatus))success failure:(void (^)(NSError*))failure;
+ (void)findUriSchemeHandlersAsync:(NSString *)scheme success:(void (^)(NSArray* /* WAAppInfo* */))success failure:(void (^)(NSError*))failure;
+ (void)findUriSchemeHandlersWithLaunchUriTypeAsync:(NSString *)scheme launchQuerySupportType:(WSLaunchQuerySupportType)launchQuerySupportType success:(void (^)(NSArray* /* WAAppInfo* */))success failure:(void (^)(NSError*))failure;
+ (void)findFileHandlersAsync:(NSString *)extension success:(void (^)(NSArray* /* WAAppInfo* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSLauncher_DEFINED__

// Windows.System.RemoteLauncher
#ifndef __WSRemoteLauncher_DEFINED__
#define __WSRemoteLauncher_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSRemoteLauncher : RTObject
+ (void)launchUriAsync:(WSRRemoteSystemConnectionRequest*)remoteSystemConnectionRequest uri:(WFUri*)uri success:(void (^)(WSRemoteLaunchUriStatus))success failure:(void (^)(NSError*))failure;
+ (void)launchUriWithOptionsAsync:(WSRRemoteSystemConnectionRequest*)remoteSystemConnectionRequest uri:(WFUri*)uri options:(WSRemoteLauncherOptions*)options success:(void (^)(WSRemoteLaunchUriStatus))success failure:(void (^)(NSError*))failure;
+ (void)launchUriWithDataAsync:(WSRRemoteSystemConnectionRequest*)remoteSystemConnectionRequest uri:(WFUri*)uri options:(WSRemoteLauncherOptions*)options inputData:(WFCValueSet*)inputData success:(void (^)(WSRemoteLaunchUriStatus))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSRemoteLauncher_DEFINED__

// Windows.System.DateTimeSettings
#ifndef __WSDateTimeSettings_DEFINED__
#define __WSDateTimeSettings_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDateTimeSettings : RTObject
+ (void)setSystemDateTime:(WFDateTime*)utcDateTime;
@end

#endif // __WSDateTimeSettings_DEFINED__

// Windows.System.ProcessLauncherOptions
#ifndef __WSProcessLauncherOptions_DEFINED__
#define __WSProcessLauncherOptions_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSProcessLauncherOptions : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * workingDirectory;
@property (retain) RTObject<WSSIOutputStream>* standardOutput;
@property (retain) RTObject<WSSIInputStream>* standardInput;
@property (retain) RTObject<WSSIOutputStream>* standardError;
@end

#endif // __WSProcessLauncherOptions_DEFINED__

// Windows.System.ProcessLauncherResult
#ifndef __WSProcessLauncherResult_DEFINED__
#define __WSProcessLauncherResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSProcessLauncherResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int exitCode;
@end

#endif // __WSProcessLauncherResult_DEFINED__

// Windows.System.ProcessLauncher
#ifndef __WSProcessLauncher_DEFINED__
#define __WSProcessLauncher_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSProcessLauncher : RTObject
+ (void)runToCompletionAsync:(NSString *)fileName args:(NSString *)args success:(void (^)(WSProcessLauncherResult*))success failure:(void (^)(NSError*))failure;
+ (void)runToCompletionAsyncWithOptions:(NSString *)fileName args:(NSString *)args options:(WSProcessLauncherOptions*)options success:(void (^)(WSProcessLauncherResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSProcessLauncher_DEFINED__

// Windows.System.ShutdownManager
#ifndef __WSShutdownManager_DEFINED__
#define __WSShutdownManager_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSShutdownManager : RTObject
+ (BOOL)isPowerStateSupported:(WSPowerState)powerState;
+ (void)enterPowerState:(WSPowerState)powerState;
+ (void)enterPowerStateWithTimeSpan:(WSPowerState)powerState wakeUpAfter:(WFTimeSpan*)wakeUpAfter;
+ (void)beginShutdown:(WSShutdownKind)shutdownKind timeout:(WFTimeSpan*)timeout;
+ (void)cancelShutdown;
+ (void)beginShutdown:(WSShutdownKind)shutdownKind timeout:(WFTimeSpan*)timeout;
+ (void)cancelShutdown;
@end

#endif // __WSShutdownManager_DEFINED__

// Windows.System.TimeZoneSettings
#ifndef __WSTimeZoneSettings_DEFINED__
#define __WSTimeZoneSettings_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSTimeZoneSettings : RTObject
+ (void)changeTimeZoneByDisplayName:(NSString *)timeZoneDisplayName;
+ (BOOL)canChangeTimeZone;
+ (NSString *)currentTimeZoneDisplayName;
+ (NSArray* /* NSString * */)supportedTimeZoneDisplayNames;
@end

#endif // __WSTimeZoneSettings_DEFINED__

