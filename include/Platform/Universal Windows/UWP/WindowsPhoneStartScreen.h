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

// WindowsPhoneStartScreen.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_PHONE_STARTSCREEN_EXPORT
#define OBJCUWP_WINDOWS_PHONE_STARTSCREEN_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Phone_StartScreen.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPSDualSimTile;
@protocol WPSIToastNotificationManagerStatics3, WPSIDualSimTile, WPSIDualSimTileStatics;

#include "WindowsUINotifications.h"

#import <Foundation/Foundation.h>

// Windows.Phone.StartScreen.IToastNotificationManagerStatics3
#ifndef __WPSIToastNotificationManagerStatics3_DEFINED__
#define __WPSIToastNotificationManagerStatics3_DEFINED__

@protocol WPSIToastNotificationManagerStatics3
- (WUNToastNotifier*)createToastNotifierForSecondaryTile:(NSString *)tileId;
@end

OBJCUWP_WINDOWS_PHONE_STARTSCREEN_EXPORT
@interface WPSIToastNotificationManagerStatics3 : RTObject <WPSIToastNotificationManagerStatics3>
@end

#endif // __WPSIToastNotificationManagerStatics3_DEFINED__

// Windows.Phone.StartScreen.DualSimTile
#ifndef __WPSDualSimTile_DEFINED__
#define __WPSDualSimTile_DEFINED__

OBJCUWP_WINDOWS_PHONE_STARTSCREEN_EXPORT
@interface WPSDualSimTile : RTObject
+ (WPSDualSimTile*)getTileForSim2;
+ (void)updateDisplayNameForSim1Async:(NSString *)name success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (WUNTileUpdater*)createTileUpdaterForSim1;
+ (WUNTileUpdater*)createTileUpdaterForSim2;
+ (WUNBadgeUpdater*)createBadgeUpdaterForSim1;
+ (WUNBadgeUpdater*)createBadgeUpdaterForSim2;
+ (WUNToastNotifier*)createToastNotifierForSim1;
+ (WUNToastNotifier*)createToastNotifierForSim2;
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (retain) NSString * displayName;
@property (readonly) BOOL isPinnedToStart;
- (void)createAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)updateAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)deleteAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WPSDualSimTile_DEFINED__

