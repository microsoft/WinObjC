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

// WindowsServicesCortana.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSERVICESCORTANAEXPORT
#define OBJCUWPWINDOWSSERVICESCORTANAEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsServicesCortana.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSCCortanaPermissionsManager, WSCCortanaSettings;
@protocol WSCICortanaPermissionsManager, WSCICortanaPermissionsManagerStatics, WSCICortanaSettings, WSCICortanaSettingsStatics;

// Windows.Services.Cortana.CortanaPermissionsChangeResult
enum _WSCCortanaPermissionsChangeResult {
    WSCCortanaPermissionsChangeResultSuccess = 0,
    WSCCortanaPermissionsChangeResultUnavailable = 1,
    WSCCortanaPermissionsChangeResultDisabledByPolicy = 2,
};
typedef unsigned WSCCortanaPermissionsChangeResult;

// Windows.Services.Cortana.CortanaPermission
enum _WSCCortanaPermission {
    WSCCortanaPermissionBrowsingHistory = 0,
    WSCCortanaPermissionCalendar = 1,
    WSCCortanaPermissionCallHistory = 2,
    WSCCortanaPermissionContacts = 3,
    WSCCortanaPermissionEmail = 4,
    WSCCortanaPermissionInputPersonalization = 5,
    WSCCortanaPermissionLocation = 6,
    WSCCortanaPermissionMessaging = 7,
    WSCCortanaPermissionMicrophone = 8,
    WSCCortanaPermissionPersonalization = 9,
    WSCCortanaPermissionPhoneCall = 10,
};
typedef unsigned WSCCortanaPermission;

#import <Foundation/Foundation.h>

// Windows.Services.Cortana.CortanaPermissionsManager
#ifndef __WSCCortanaPermissionsManager_DEFINED__
#define __WSCCortanaPermissionsManager_DEFINED__

OBJCUWPWINDOWSSERVICESCORTANAEXPORT
@interface WSCCortanaPermissionsManager : RTObject
+ (WSCCortanaPermissionsManager*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (BOOL)isSupported;
- (void)arePermissionsGrantedAsync:(id<NSFastEnumeration> /* WSCCortanaPermission */)permissions success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)grantPermissionsAsync:(id<NSFastEnumeration> /* WSCCortanaPermission */)permissions success:(void (^)(WSCCortanaPermissionsChangeResult))success failure:(void (^)(NSError*))failure;
- (void)revokePermissionsAsync:(id<NSFastEnumeration> /* WSCCortanaPermission */)permissions success:(void (^)(WSCCortanaPermissionsChangeResult))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSCCortanaPermissionsManager_DEFINED__

// Windows.Services.Cortana.CortanaSettings
#ifndef __WSCCortanaSettings_DEFINED__
#define __WSCCortanaSettings_DEFINED__

OBJCUWPWINDOWSSERVICESCORTANAEXPORT
@interface WSCCortanaSettings : RTObject
+ (BOOL)isSupported;
+ (WSCCortanaSettings*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isVoiceActivationEnabled;
@property (readonly) BOOL hasUserConsentToVoiceActivation;
@end

#endif // __WSCCortanaSettings_DEFINED__

