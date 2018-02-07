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

// WindowsSystemUserProfile.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSYSTEMUSERPROFILEEXPORT
#define OBJCUWPWINDOWSSYSTEMUSERPROFILEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsSystemUserProfile.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSUAdvertisingManagerForUser, WSUAdvertisingManager, WSUDiagnosticsSettings, WSUUserProfilePersonalizationSettings, WSUGlobalizationPreferences, WSUFirstSignInSettings, WSUUserInformation, WSULockScreen;
@protocol WSUIAdvertisingManagerStatics, WSUIAdvertisingManagerForUser, WSUIAdvertisingManagerStatics2, WSUIDiagnosticsSettingsStatics, WSUIDiagnosticsSettings, WSUIUserProfilePersonalizationSettings, WSUIUserProfilePersonalizationSettingsStatics, WSUIGlobalizationPreferencesStatics, WSUIGlobalizationPreferencesStatics2, WSUIFirstSignInSettings, WSUIFirstSignInSettingsStatics, WSUIUserInformationStatics, WSUILockScreenStatics, WSUILockScreenImageFeedStatics;

// Windows.System.UserProfile.AccountPictureKind
enum _WSUAccountPictureKind {
    WSUAccountPictureKindSmallImage = 0,
    WSUAccountPictureKindLargeImage = 1,
    WSUAccountPictureKindVideo = 2,
};
typedef unsigned WSUAccountPictureKind;

// Windows.System.UserProfile.SetAccountPictureResult
enum _WSUSetAccountPictureResult {
    WSUSetAccountPictureResultSuccess = 0,
    WSUSetAccountPictureResultChangeDisabled = 1,
    WSUSetAccountPictureResultLargeOrDynamicError = 2,
    WSUSetAccountPictureResultVideoFrameSizeError = 3,
    WSUSetAccountPictureResultFileSizeError = 4,
    WSUSetAccountPictureResultFailure = 5,
};
typedef unsigned WSUSetAccountPictureResult;

// Windows.System.UserProfile.SetImageFeedResult
enum _WSUSetImageFeedResult {
    WSUSetImageFeedResultSuccess = 0,
    WSUSetImageFeedResultChangeDisabled = 1,
    WSUSetImageFeedResultUserCanceled = 2,
};
typedef unsigned WSUSetImageFeedResult;

#include "WindowsStorage.h"
#include "WindowsGlobalization.h"
#include "WindowsSystem.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.System.UserProfile.AdvertisingManagerForUser
#ifndef __WSUAdvertisingManagerForUser_DEFINED__
#define __WSUAdvertisingManagerForUser_DEFINED__

OBJCUWPWINDOWSSYSTEMUSERPROFILEEXPORT
@interface WSUAdvertisingManagerForUser : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * advertisingId;
@property (readonly) WSUser* user;
@end

#endif // __WSUAdvertisingManagerForUser_DEFINED__

// Windows.System.UserProfile.AdvertisingManager
#ifndef __WSUAdvertisingManager_DEFINED__
#define __WSUAdvertisingManager_DEFINED__

OBJCUWPWINDOWSSYSTEMUSERPROFILEEXPORT
@interface WSUAdvertisingManager : RTObject
+ (WSUAdvertisingManagerForUser*)getForUser:(WSUser*)user;
+ (NSString *)advertisingId;
@end

#endif // __WSUAdvertisingManager_DEFINED__

// Windows.System.UserProfile.DiagnosticsSettings
#ifndef __WSUDiagnosticsSettings_DEFINED__
#define __WSUDiagnosticsSettings_DEFINED__

OBJCUWPWINDOWSSYSTEMUSERPROFILEEXPORT
@interface WSUDiagnosticsSettings : RTObject
+ (WSUDiagnosticsSettings*)getDefault;
+ (WSUDiagnosticsSettings*)getForUser:(WSUser*)user;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL canUseDiagnosticsToTailorExperiences;
@property (readonly) WSUser* user;
@end

#endif // __WSUDiagnosticsSettings_DEFINED__

// Windows.System.UserProfile.UserProfilePersonalizationSettings
#ifndef __WSUUserProfilePersonalizationSettings_DEFINED__
#define __WSUUserProfilePersonalizationSettings_DEFINED__

OBJCUWPWINDOWSSYSTEMUSERPROFILEEXPORT
@interface WSUUserProfilePersonalizationSettings : RTObject
+ (BOOL)isSupported;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
+ (WSUUserProfilePersonalizationSettings*)current;
- (void)trySetLockScreenImageAsync:(WSStorageFile*)imageFile success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)trySetWallpaperImageAsync:(WSStorageFile*)imageFile success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSUUserProfilePersonalizationSettings_DEFINED__

// Windows.System.UserProfile.GlobalizationPreferences
#ifndef __WSUGlobalizationPreferences_DEFINED__
#define __WSUGlobalizationPreferences_DEFINED__

OBJCUWPWINDOWSSYSTEMUSERPROFILEEXPORT
@interface WSUGlobalizationPreferences : RTObject
+ (BOOL)trySetHomeGeographicRegion:(NSString *)region;
+ (BOOL)trySetLanguages:(id<NSFastEnumeration> /* NSString * */)languageTags;
+ (NSArray* /* NSString * */)calendars;
+ (NSArray* /* NSString * */)clocks;
+ (NSArray* /* NSString * */)currencies;
+ (NSString *)homeGeographicRegion;
+ (NSArray* /* NSString * */)languages;
+ (WGDayOfWeek)weekStartsOn;
@end

#endif // __WSUGlobalizationPreferences_DEFINED__

// Windows.System.UserProfile.FirstSignInSettings
#ifndef __WSUFirstSignInSettings_DEFINED__
#define __WSUFirstSignInSettings_DEFINED__

OBJCUWPWINDOWSSYSTEMUSERPROFILEEXPORT
@interface WSUFirstSignInSettings : RTObject
+ (WSUFirstSignInSettings*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (id)objectForKey: (id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject: (id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

@end

#endif // __WSUFirstSignInSettings_DEFINED__

// Windows.System.UserProfile.UserInformation
#ifndef __WSUUserInformation_DEFINED__
#define __WSUUserInformation_DEFINED__

OBJCUWPWINDOWSSYSTEMUSERPROFILEEXPORT
@interface WSUUserInformation : RTObject
+ (RTObject<WSIStorageFile>*)getAccountPicture:(WSUAccountPictureKind)kind;
+ (void)setAccountPictureAsync:(RTObject<WSIStorageFile>*)image success:(void (^)(WSUSetAccountPictureResult))success failure:(void (^)(NSError*))failure;
+ (void)setAccountPicturesAsync:(RTObject<WSIStorageFile>*)smallImage largeImage:(RTObject<WSIStorageFile>*)largeImage video:(RTObject<WSIStorageFile>*)video success:(void (^)(WSUSetAccountPictureResult))success failure:(void (^)(NSError*))failure;
+ (void)setAccountPictureFromStreamAsync:(RTObject<WSSIRandomAccessStream>*)image success:(void (^)(WSUSetAccountPictureResult))success failure:(void (^)(NSError*))failure;
+ (void)setAccountPicturesFromStreamsAsync:(RTObject<WSSIRandomAccessStream>*)smallImage largeImage:(RTObject<WSSIRandomAccessStream>*)largeImage video:(RTObject<WSSIRandomAccessStream>*)video success:(void (^)(WSUSetAccountPictureResult))success failure:(void (^)(NSError*))failure;
+ (void)getDisplayNameAsyncWithSuccess:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
+ (void)getFirstNameAsyncWithSuccess:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
+ (void)getLastNameAsyncWithSuccess:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
+ (void)getPrincipalNameAsyncWithSuccess:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
+ (void)getSessionInitiationProtocolUriAsyncWithSuccess:(void (^)(WFUri*))success failure:(void (^)(NSError*))failure;
+ (void)getDomainNameAsyncWithSuccess:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
+ (BOOL)accountPictureChangeEnabled;
+ (BOOL)nameAccessAllowed;
+ (EventRegistrationToken)addAccountPictureChangedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeAccountPictureChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WSUUserInformation_DEFINED__

// Windows.System.UserProfile.LockScreen
#ifndef __WSULockScreen_DEFINED__
#define __WSULockScreen_DEFINED__

OBJCUWPWINDOWSSYSTEMUSERPROFILEEXPORT
@interface WSULockScreen : RTObject
+ (RTObject<WSSIRandomAccessStream>*)getImageStream;
+ (RTObject<WFIAsyncAction>*)setImageFileAsync:(RTObject<WSIStorageFile>*)value;
+ (RTObject<WFIAsyncAction>*)setImageStreamAsync:(RTObject<WSSIRandomAccessStream>*)value;
+ (void)requestSetImageFeedAsync:(WFUri*)syndicationFeedUri success:(void (^)(WSUSetImageFeedResult))success failure:(void (^)(NSError*))failure;
+ (BOOL)tryRemoveImageFeed;
+ (WFUri*)originalImageFile;
@end

#endif // __WSULockScreen_DEFINED__

