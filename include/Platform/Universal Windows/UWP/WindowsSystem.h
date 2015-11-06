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

// WindowsSystem.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSAppMemoryUsageLimitChangingEventArgs, WSAppMemoryReport, WSProcessMemoryReport, WSMemoryManager, WSProtocolForResultsOperation,
    WSUserWatcher, WSUser, WSUserChangedEventArgs, WSUserAuthenticationStatusChangingEventArgs, WSUserAuthenticationStatusChangeDeferral,
    WSKnownUserProperties, WSLaunchUriResult, WSLauncherUIOptions, WSLauncherOptions, WSFolderLauncherOptions, WSLauncher;
@protocol WSIAppMemoryReport
, WSIProcessMemoryReport, WSIAppMemoryUsageLimitChangingEventArgs, WSIMemoryManagerStatics, WSIMemoryManagerStatics2,
    WSIProtocolForResultsOperation, WSIUser, WSIUserStatics, WSIUserWatcher, WSIUserChangedEventArgs,
    WSIUserAuthenticationStatusChangeDeferral, WSIUserAuthenticationStatusChangingEventArgs, WSIKnownUserPropertiesStatics,
    WSILaunchUriResult, WSILauncherUIOptions, WSILauncherOptions, WSILauncherOptions2, WSILauncherViewOptions, WSIFolderLauncherOptions,
    WSILauncherStatics, WSILauncherStatics2, WSILauncherStatics3;

// Windows.System.AppMemoryUsageLevel
enum _WSAppMemoryUsageLevel {
    WSAppMemoryUsageLevelLow = 0,
    WSAppMemoryUsageLevelMedium = 1,
    WSAppMemoryUsageLevelHigh = 2,
};
typedef unsigned WSAppMemoryUsageLevel;

// Windows.System.ProcessorArchitecture
enum _WSProcessorArchitecture {
    WSProcessorArchitectureX86 = 0,
    WSProcessorArchitectureArm = 5,
    WSProcessorArchitectureX64 = 9,
    WSProcessorArchitectureNeutral = 11,
    WSProcessorArchitectureUnknown = 65535,
};
typedef unsigned WSProcessorArchitecture;

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

#include "WindowsApplicationModel.h"
#include "WindowsUIPopups.h"
#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorage.h"
#include "WindowsStorageSearch.h"
#include "WindowsUIViewManagement.h"

#import <Foundation/Foundation.h>

// Windows.System.ILauncherViewOptions
#ifndef __WSILauncherViewOptions_DEFINED__
#define __WSILauncherViewOptions_DEFINED__

@protocol WSILauncherViewOptions
@property WUVViewSizePreference desiredRemainingView;
@end

#endif // __WSILauncherViewOptions_DEFINED__

// Windows.System.AppMemoryUsageLimitChangingEventArgs
#ifndef __WSAppMemoryUsageLimitChangingEventArgs_DEFINED__
#define __WSAppMemoryUsageLimitChangingEventArgs_DEFINED__

WINRT_EXPORT
@interface WSAppMemoryUsageLimitChangingEventArgs : RTObject
@property (readonly) uint64_t newLimit;
@property (readonly) uint64_t oldLimit;
@end

#endif // __WSAppMemoryUsageLimitChangingEventArgs_DEFINED__

// Windows.System.AppMemoryReport
#ifndef __WSAppMemoryReport_DEFINED__
#define __WSAppMemoryReport_DEFINED__

WINRT_EXPORT
@interface WSAppMemoryReport : RTObject
@property (readonly) uint64_t peakPrivateCommitUsage;
@property (readonly) uint64_t privateCommitUsage;
@property (readonly) uint64_t totalCommitLimit;
@property (readonly) uint64_t totalCommitUsage;
@end

#endif // __WSAppMemoryReport_DEFINED__

// Windows.System.ProcessMemoryReport
#ifndef __WSProcessMemoryReport_DEFINED__
#define __WSProcessMemoryReport_DEFINED__

WINRT_EXPORT
@interface WSProcessMemoryReport : RTObject
@property (readonly) uint64_t privateWorkingSetUsage;
@property (readonly) uint64_t totalWorkingSetUsage;
@end

#endif // __WSProcessMemoryReport_DEFINED__

// Windows.System.MemoryManager
#ifndef __WSMemoryManager_DEFINED__
#define __WSMemoryManager_DEFINED__

WINRT_EXPORT
@interface WSMemoryManager : RTObject
+ (WSAppMemoryReport*)getAppMemoryReport;
+ (WSProcessMemoryReport*)getProcessMemoryReport;
+ (uint64_t)appMemoryUsage;
+ (WSAppMemoryUsageLevel)appMemoryUsageLevel;
+ (uint64_t)appMemoryUsageLimit;
+ (EventRegistrationToken)addAppMemoryUsageDecreasedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeAppMemoryUsageDecreasedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addAppMemoryUsageIncreasedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeAppMemoryUsageIncreasedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addAppMemoryUsageLimitChangingEvent:(void (^)(RTObject*, WSAppMemoryUsageLimitChangingEventArgs*))del;
+ (void)removeAppMemoryUsageLimitChangingEvent:(EventRegistrationToken)tok;
@end

#endif // __WSMemoryManager_DEFINED__

// Windows.System.ProtocolForResultsOperation
#ifndef __WSProtocolForResultsOperation_DEFINED__
#define __WSProtocolForResultsOperation_DEFINED__

WINRT_EXPORT
@interface WSProtocolForResultsOperation : RTObject
- (void)reportCompleted:(WFCValueSet*)data;
@end

#endif // __WSProtocolForResultsOperation_DEFINED__

// Windows.System.UserWatcher
#ifndef __WSUserWatcher_DEFINED__
#define __WSUserWatcher_DEFINED__

WINRT_EXPORT
@interface WSUserWatcher : RTObject
@property (readonly) WSUserWatcherStatus status;
- (EventRegistrationToken)addAddedEvent:(void (^)(WSUserWatcher*, WSUserChangedEventArgs*))del;
- (void)removeAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAuthenticationStatusChangedEvent:(void (^)(WSUserWatcher*, WSUserChangedEventArgs*))del;
- (void)removeAuthenticationStatusChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAuthenticationStatusChangingEvent:(void (^)(WSUserWatcher*, WSUserAuthenticationStatusChangingEventArgs*))del;
- (void)removeAuthenticationStatusChangingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WSUserWatcher*, RTObject*))del;
- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRemovedEvent:(void (^)(WSUserWatcher*, WSUserChangedEventArgs*))del;
- (void)removeRemovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStoppedEvent:(void (^)(WSUserWatcher*, RTObject*))del;
- (void)removeStoppedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUpdatedEvent:(void (^)(WSUserWatcher*, WSUserChangedEventArgs*))del;
- (void)removeUpdatedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WSUserWatcher_DEFINED__

// Windows.System.User
#ifndef __WSUser_DEFINED__
#define __WSUser_DEFINED__

WINRT_EXPORT
@interface WSUser : RTObject
+ (WSUserWatcher*)createWatcher;
+ (void)findAllAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
+ (void)findAllAsyncByType:(WSUserType)type success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
+ (void)findAllAsyncByTypeAndStatus:(WSUserType)type
                             status:(WSUserAuthenticationStatus)status
                            success:(void (^)(NSArray*))success
                            failure:(void (^)(NSError*))failure;
+ (WSUser*)getFromId:(NSString*)nonRoamableId;
@property (readonly) WSUserAuthenticationStatus authenticationStatus;
@property (readonly) NSString* nonRoamableId;
@property (readonly) WSUserType type;
- (void)getPropertyAsync:(NSString*)value success:(void (^)(RTObject*))success failure:(void (^)(NSError*))failure;
- (void)getPropertiesAsync:(id<NSFastEnumeration> /* NSString * */)values
                   success:(void (^)(RTObject<WFCIPropertySet>*))success
                   failure:(void (^)(NSError*))failure;
- (void)getPictureAsync:(WSUserPictureSize)desiredSize
                success:(void (^)(RTObject<WSSIRandomAccessStreamReference>*))success
                failure:(void (^)(NSError*))failure;
@end

#endif // __WSUser_DEFINED__

// Windows.System.UserChangedEventArgs
#ifndef __WSUserChangedEventArgs_DEFINED__
#define __WSUserChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WSUserChangedEventArgs : RTObject
@property (readonly) WSUser* user;
@end

#endif // __WSUserChangedEventArgs_DEFINED__

// Windows.System.UserAuthenticationStatusChangingEventArgs
#ifndef __WSUserAuthenticationStatusChangingEventArgs_DEFINED__
#define __WSUserAuthenticationStatusChangingEventArgs_DEFINED__

WINRT_EXPORT
@interface WSUserAuthenticationStatusChangingEventArgs : RTObject
@property (readonly) WSUserAuthenticationStatus currentStatus;
@property (readonly) WSUserAuthenticationStatus newStatus;
@property (readonly) WSUser* user;
- (WSUserAuthenticationStatusChangeDeferral*)getDeferral;
@end

#endif // __WSUserAuthenticationStatusChangingEventArgs_DEFINED__

// Windows.System.UserAuthenticationStatusChangeDeferral
#ifndef __WSUserAuthenticationStatusChangeDeferral_DEFINED__
#define __WSUserAuthenticationStatusChangeDeferral_DEFINED__

WINRT_EXPORT
@interface WSUserAuthenticationStatusChangeDeferral : RTObject
- (void)complete;
@end

#endif // __WSUserAuthenticationStatusChangeDeferral_DEFINED__

// Windows.System.KnownUserProperties
#ifndef __WSKnownUserProperties_DEFINED__
#define __WSKnownUserProperties_DEFINED__

WINRT_EXPORT
@interface WSKnownUserProperties : RTObject
+ (NSString*)accountName;
+ (NSString*)displayName;
+ (NSString*)domainName;
+ (NSString*)firstName;
+ (NSString*)guestHost;
+ (NSString*)lastName;
+ (NSString*)principalName;
+ (NSString*)providerName;
+ (NSString*)sessionInitiationProtocolUri;
@end

#endif // __WSKnownUserProperties_DEFINED__

// Windows.System.LaunchUriResult
#ifndef __WSLaunchUriResult_DEFINED__
#define __WSLaunchUriResult_DEFINED__

WINRT_EXPORT
@interface WSLaunchUriResult : RTObject
@property (readonly) WFCValueSet* result;
@property (readonly) WSLaunchUriStatus status;
@end

#endif // __WSLaunchUriResult_DEFINED__

// Windows.System.LauncherUIOptions
#ifndef __WSLauncherUIOptions_DEFINED__
#define __WSLauncherUIOptions_DEFINED__

WINRT_EXPORT
@interface WSLauncherUIOptions : RTObject
@property (copy) id selectionRect;
@property WUPPlacement preferredPlacement;
@property (copy) id invocationPoint;
@end

#endif // __WSLauncherUIOptions_DEFINED__

// Windows.System.LauncherOptions
#ifndef __WSLauncherOptions_DEFINED__
#define __WSLauncherOptions_DEFINED__

WINRT_EXPORT
@interface WSLauncherOptions : RTObject <WSILauncherViewOptions>
+ (instancetype)create ACTIVATOR;
@property BOOL treatAsUntrusted;
@property (copy) NSString* preferredApplicationPackageFamilyName;
@property (copy) NSString* preferredApplicationDisplayName;
@property (copy) WFUri* fallbackUri;
@property BOOL displayApplicationPicker;
@property (copy) NSString* contentType;
@property (readonly) WSLauncherUIOptions* uI;
@property (copy) NSString* targetApplicationPackageFamilyName;
@property (copy) WSSStorageFileQueryResult* neighboringFilesQuery;
@property WUVViewSizePreference desiredRemainingView;
@end

#endif // __WSLauncherOptions_DEFINED__

// Windows.System.FolderLauncherOptions
#ifndef __WSFolderLauncherOptions_DEFINED__
#define __WSFolderLauncherOptions_DEFINED__

WINRT_EXPORT
@interface WSFolderLauncherOptions : RTObject <WSILauncherViewOptions>
+ (instancetype)create ACTIVATOR;
@property (readonly) NSMutableArray* itemsToSelect;
@property WUVViewSizePreference desiredRemainingView;
@end

#endif // __WSFolderLauncherOptions_DEFINED__

// Windows.System.Launcher
#ifndef __WSLauncher_DEFINED__
#define __WSLauncher_DEFINED__

WINRT_EXPORT
@interface WSLauncher : RTObject
+ (void)launchFileAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)launchFileWithOptionsAsync:(RTObject<WSIStorageFile>*)file
                           options:(WSLauncherOptions*)options
                           success:(void (^)(BOOL))success
                           failure:(void (^)(NSError*))failure;
+ (void)launchUriAsync:(WFUri*)uri success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)launchUriWithOptionsAsync:(WFUri*)uri
                          options:(WSLauncherOptions*)options
                          success:(void (^)(BOOL))success
                          failure:(void (^)(NSError*))failure;
+ (void)launchFolderAsync:(RTObject<WSIStorageFolder>*)folder success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)launchFolderWithOptionsAsync:(RTObject<WSIStorageFolder>*)folder
                             options:(WSFolderLauncherOptions*)options
                             success:(void (^)(BOOL))success
                             failure:(void (^)(NSError*))failure;
+ (void)launchUriForResultsAsync:(WFUri*)uri
                         options:(WSLauncherOptions*)options
                         success:(void (^)(WSLaunchUriResult*))success
                         failure:(void (^)(NSError*))failure;
+ (void)launchUriForResultsWithDataAsync:(WFUri*)uri
                                 options:(WSLauncherOptions*)options
                               inputData:(WFCValueSet*)inputData
                                 success:(void (^)(WSLaunchUriResult*))success
                                 failure:(void (^)(NSError*))failure;
+ (void)launchUriWithDataAsync:(WFUri*)uri
                       options:(WSLauncherOptions*)options
                     inputData:(WFCValueSet*)inputData
                       success:(void (^)(BOOL))success
                       failure:(void (^)(NSError*))failure;
+ (void)queryUriSupportAsync:(WFUri*)uri
      launchQuerySupportType:(WSLaunchQuerySupportType)launchQuerySupportType
                     success:(void (^)(WSLaunchQuerySupportStatus))success
                     failure:(void (^)(NSError*))failure;
+ (void)queryUriSupportWithPackageFamilyNameAsync:(WFUri*)uri
                           launchQuerySupportType:(WSLaunchQuerySupportType)launchQuerySupportType
                                packageFamilyName:(NSString*)packageFamilyName
                                          success:(void (^)(WSLaunchQuerySupportStatus))success
                                          failure:(void (^)(NSError*))failure;
+ (void)queryFileSupportAsync:(WSStorageFile*)file
                      success:(void (^)(WSLaunchQuerySupportStatus))success
                      failure:(void (^)(NSError*))failure;
+ (void)queryFileSupportWithPackageFamilyNameAsync:(WSStorageFile*)file
                                 packageFamilyName:(NSString*)packageFamilyName
                                           success:(void (^)(WSLaunchQuerySupportStatus))success
                                           failure:(void (^)(NSError*))failure;
+ (void)findUriSchemeHandlersAsync:(NSString*)scheme success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
+ (void)findUriSchemeHandlersWithLaunchUriTypeAsync:(NSString*)scheme
                             launchQuerySupportType:(WSLaunchQuerySupportType)launchQuerySupportType
                                            success:(void (^)(NSArray*))success
                                            failure:(void (^)(NSError*))failure;
+ (void)findFileHandlersAsync:(NSString*)extension success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSLauncher_DEFINED__
