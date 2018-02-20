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

// WindowsPhoneStartScreen.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSPHONESTARTSCREENEXPORT
#define OBJCUWPWINDOWSPHONESTARTSCREENEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsPhoneStartScreen.lib")
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

OBJCUWPWINDOWSPHONESTARTSCREENEXPORT
@interface WPSIToastNotificationManagerStatics3 : RTObject <WPSIToastNotificationManagerStatics3>
@end

#endif // __WPSIToastNotificationManagerStatics3_DEFINED__

// Windows.Phone.StartScreen.DualSimTile
#ifndef __WPSDualSimTile_DEFINED__
#define __WPSDualSimTile_DEFINED__

OBJCUWPWINDOWSPHONESTARTSCREENEXPORT
@interface WPSDualSimTile : RTObject
+ (WPSDualSimTile*)getTileForSim2;
+ (void)updateDisplayNameForSim1Async:(NSString *)name success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (WUNTileUpdater*)createTileUpdaterForSim1;
+ (WUNTileUpdater*)createTileUpdaterForSim2;
+ (WUNBadgeUpdater*)createBadgeUpdaterForSim1;
+ (WUNBadgeUpdater*)createBadgeUpdaterForSim2;
+ (WUNToastNotifier*)createToastNotifierForSim1;
+ (WUNToastNotifier*)createToastNotifierForSim2;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * displayName;
@property (readonly) BOOL isPinnedToStart;
- (void)createAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)updateAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)deleteAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WPSDualSimTile_DEFINED__

