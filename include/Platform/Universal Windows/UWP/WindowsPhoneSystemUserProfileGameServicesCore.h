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

// WindowsPhoneSystemUserProfileGameServicesCore.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSPHONESYSTEMUSERPROFILEGAMESERVICESCOREEXPORT
#define OBJCUWPWINDOWSPHONESYSTEMUSERPROFILEGAMESERVICESCOREEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsPhoneSystemUserProfileGameServicesCore.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPSUGCGameServicePropertyCollection, WPSUGCGameService;
@protocol WPSUGCIGameServicePropertyCollection, WPSUGCIGameService, WPSUGCIGameService2;

// Windows.Phone.System.UserProfile.GameServices.Core.GameServiceScoreKind
enum _WPSUGCGameServiceScoreKind {
    WPSUGCGameServiceScoreKindNumber = 0,
    WPSUGCGameServiceScoreKindTime = 1,
};
typedef unsigned WPSUGCGameServiceScoreKind;

// Windows.Phone.System.UserProfile.GameServices.Core.GameServiceGameOutcome
enum _WPSUGCGameServiceGameOutcome {
    WPSUGCGameServiceGameOutcomeNone = 0,
    WPSUGCGameServiceGameOutcomeWin = 1,
    WPSUGCGameServiceGameOutcomeLoss = 2,
    WPSUGCGameServiceGameOutcomeTie = 3,
};
typedef unsigned WPSUGCGameServiceGameOutcome;

#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Phone.System.UserProfile.GameServices.Core.GameServicePropertyCollection
#ifndef __WPSUGCGameServicePropertyCollection_DEFINED__
#define __WPSUGCGameServicePropertyCollection_DEFINED__

OBJCUWPWINDOWSPHONESYSTEMUSERPROFILEGAMESERVICESCOREEXPORT
@interface WPSUGCGameServicePropertyCollection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)getPropertyAsync:(NSString *)propertyName success:(void (^)(RTObject*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WPSUGCGameServicePropertyCollection_DEFINED__

// Windows.Phone.System.UserProfile.GameServices.Core.GameService
#ifndef __WPSUGCGameService_DEFINED__
#define __WPSUGCGameService_DEFINED__

OBJCUWPWINDOWSPHONESYSTEMUSERPROFILEGAMESERVICESCOREEXPORT
@interface WPSUGCGameService : RTObject
+ (void)getGamerProfileAsyncWithSuccess:(void (^)(WPSUGCGameServicePropertyCollection*))success failure:(void (^)(NSError*))failure;
+ (void)getInstalledGameItemsAsyncWithSuccess:(void (^)(WPSUGCGameServicePropertyCollection*))success failure:(void (^)(NSError*))failure;
+ (void)getPartnerTokenAsync:(WFUri*)audienceUri success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
+ (void)getPrivilegesAsyncWithSuccess:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
+ (void)grantAchievement:(unsigned int)achievementId;
+ (void)grantAvatarAward:(unsigned int)avatarAwardId;
+ (void)postResult:(unsigned int)gameVariant scoreKind:(WPSUGCGameServiceScoreKind)scoreKind scoreValue:(int64_t)scoreValue gameOutcome:(WPSUGCGameServiceGameOutcome)gameOutcome buffer:(RTObject<WSSIBuffer>*)buffer;
+ (void)notifyPartnerTokenExpired:(WFUri*)audienceUri;
+ (unsigned int)getAuthenticationStatus;
+ (WFUri*)serviceUri;
@end

#endif // __WPSUGCGameService_DEFINED__

