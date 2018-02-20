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

// WindowsApplicationModelSocialInfoProvider.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELSOCIALINFOPROVIDEREXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELSOCIALINFOPROVIDEREXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelSocialInfoProvider.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WASPSocialFeedUpdater, WASPSocialDashboardItemUpdater, WASPSocialInfoProviderManager;
@protocol WASPISocialFeedUpdater, WASPISocialDashboardItemUpdater, WASPISocialInfoProviderManagerStatics;

#include "WindowsApplicationModelSocialInfo.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.SocialInfo.Provider.SocialFeedUpdater
#ifndef __WASPSocialFeedUpdater_DEFINED__
#define __WASPSocialFeedUpdater_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSOCIALINFOPROVIDEREXPORT
@interface WASPSocialFeedUpdater : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray* /* WASSocialFeedItem* */ items;
@property (readonly) WASSocialFeedKind kind;
@property (readonly) NSString * ownerRemoteId;
- (RTObject<WFIAsyncAction>*)commitAsync;
@end

#endif // __WASPSocialFeedUpdater_DEFINED__

// Windows.ApplicationModel.SocialInfo.Provider.SocialDashboardItemUpdater
#ifndef __WASPSocialDashboardItemUpdater_DEFINED__
#define __WASPSocialDashboardItemUpdater_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSOCIALINFOPROVIDEREXPORT
@interface WASPSocialDashboardItemUpdater : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFDateTime* timestamp;
@property (retain) WASSocialItemThumbnail* thumbnail;
@property (retain) WFUri* targetUri;
@property (readonly) WASSocialFeedContent* content;
@property (readonly) NSString * ownerRemoteId;
- (RTObject<WFIAsyncAction>*)commitAsync;
@end

#endif // __WASPSocialDashboardItemUpdater_DEFINED__

// Windows.ApplicationModel.SocialInfo.Provider.SocialInfoProviderManager
#ifndef __WASPSocialInfoProviderManager_DEFINED__
#define __WASPSocialInfoProviderManager_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSOCIALINFOPROVIDEREXPORT
@interface WASPSocialInfoProviderManager : RTObject
+ (void)createSocialFeedUpdaterAsync:(WASSocialFeedKind)kind mode:(WASSocialFeedUpdateMode)mode ownerRemoteId:(NSString *)ownerRemoteId success:(void (^)(WASPSocialFeedUpdater*))success failure:(void (^)(NSError*))failure;
+ (void)createDashboardItemUpdaterAsync:(NSString *)ownerRemoteId success:(void (^)(WASPSocialDashboardItemUpdater*))success failure:(void (^)(NSError*))failure;
+ (void)updateBadgeCountValue:(NSString *)itemRemoteId newCount:(int)newCount;
+ (void)reportNewContentAvailable:(NSString *)contactRemoteId kind:(WASSocialFeedKind)kind;
+ (void)provisionAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)deprovisionAsync;
@end

#endif // __WASPSocialInfoProviderManager_DEFINED__

