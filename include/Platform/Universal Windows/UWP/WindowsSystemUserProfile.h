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

// WindowsSystemUserProfile.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_SYSTEM_USERPROFILE_EXPORT
#define OBJCUWP_WINDOWS_SYSTEM_USERPROFILE_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_System_UserProfile.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSUAdvertisingManager, WSUUserProfilePersonalizationSettings, WSUGlobalizationPreferences, WSUFirstSignInSettings;
@protocol WSUIAdvertisingManagerStatics
, WSUIUserProfilePersonalizationSettings, WSUIUserProfilePersonalizationSettingsStatics, WSUIGlobalizationPreferencesStatics,
    WSUIFirstSignInSettings, WSUIFirstSignInSettingsStatics;

#include "WindowsStorage.h"
#include "WindowsGlobalization.h"

#import <Foundation/Foundation.h>

// Windows.System.UserProfile.AdvertisingManager
#ifndef __WSUAdvertisingManager_DEFINED__
#define __WSUAdvertisingManager_DEFINED__

OBJCUWP_WINDOWS_SYSTEM_USERPROFILE_EXPORT
@interface WSUAdvertisingManager : RTObject
+ (NSString*)advertisingId;
@end

#endif // __WSUAdvertisingManager_DEFINED__

// Windows.System.UserProfile.UserProfilePersonalizationSettings
#ifndef __WSUUserProfilePersonalizationSettings_DEFINED__
#define __WSUUserProfilePersonalizationSettings_DEFINED__

OBJCUWP_WINDOWS_SYSTEM_USERPROFILE_EXPORT
@interface WSUUserProfilePersonalizationSettings : RTObject
+ (BOOL)isSupported;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
+ (WSUUserProfilePersonalizationSettings*)current;
- (void)trySetLockScreenImageAsync:(WSStorageFile*)imageFile success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)trySetWallpaperImageAsync:(WSStorageFile*)imageFile success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSUUserProfilePersonalizationSettings_DEFINED__

// Windows.System.UserProfile.GlobalizationPreferences
#ifndef __WSUGlobalizationPreferences_DEFINED__
#define __WSUGlobalizationPreferences_DEFINED__

OBJCUWP_WINDOWS_SYSTEM_USERPROFILE_EXPORT
@interface WSUGlobalizationPreferences : RTObject
+ (NSArray* /* NSString * */)calendars;
+ (NSArray* /* NSString * */)clocks;
+ (NSArray* /* NSString * */)currencies;
+ (NSString*)homeGeographicRegion;
+ (NSArray* /* NSString * */)languages;
+ (WGDayOfWeek)weekStartsOn;
@end

#endif // __WSUGlobalizationPreferences_DEFINED__

// Windows.System.UserProfile.FirstSignInSettings
#ifndef __WSUFirstSignInSettings_DEFINED__
#define __WSUFirstSignInSettings_DEFINED__

OBJCUWP_WINDOWS_SYSTEM_USERPROFILE_EXPORT
@interface WSUFirstSignInSettings : RTObject
+ (WSUFirstSignInSettings*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) unsigned int size;
- (id)objectForKey:(id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject:(id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

@end

#endif // __WSUFirstSignInSettings_DEFINED__
