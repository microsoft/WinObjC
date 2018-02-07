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

// WindowsApplicationModelUserActivities.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELUSERACTIVITIESEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELUSERACTIVITIESEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelUserActivities.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAUUserActivityAttribution, WAUUserActivityContentInfo, WAUUserActivityVisualElements, WAUUserActivitySession, WAUUserActivity, WAUUserActivityChannel;
@protocol WAUIUserActivityAttributionFactory, WAUIUserActivityAttribution, WAUIUserActivityContentInfo, WAUIUserActivityContentInfoStatics, WAUIUserActivityVisualElements, WAUIUserActivitySession, WAUIUserActivity, WAUIUserActivityChannelStatics, WAUIUserActivityChannel;

// Windows.ApplicationModel.UserActivities.UserActivityState
enum _WAUUserActivityState {
    WAUUserActivityStateNew = 0,
    WAUUserActivityStatePublished = 1,
};
typedef unsigned WAUUserActivityState;

#include "WindowsFoundation.h"
#include "WindowsUIShell.h"
#include "WindowsUI.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.UserActivities.IUserActivityContentInfo
#ifndef __WAUIUserActivityContentInfo_DEFINED__
#define __WAUIUserActivityContentInfo_DEFINED__

@protocol WAUIUserActivityContentInfo
- (NSString *)toJson;
@end

OBJCUWPWINDOWSAPPLICATIONMODELUSERACTIVITIESEXPORT
@interface WAUIUserActivityContentInfo : RTObject <WAUIUserActivityContentInfo>
@end

#endif // __WAUIUserActivityContentInfo_DEFINED__

// Windows.ApplicationModel.UserActivities.UserActivityAttribution
#ifndef __WAUUserActivityAttribution_DEFINED__
#define __WAUUserActivityAttribution_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERACTIVITIESEXPORT
@interface WAUUserActivityAttribution : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
+ (WAUUserActivityAttribution*)makeWithUri:(WFUri*)iconUri ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* iconUri;
@property (retain) NSString * alternateText;
@property BOOL addImageQuery;
@end

#endif // __WAUUserActivityAttribution_DEFINED__

// Windows.ApplicationModel.UserActivities.UserActivityContentInfo
#ifndef __WAUUserActivityContentInfo_DEFINED__
#define __WAUUserActivityContentInfo_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERACTIVITIESEXPORT
@interface WAUUserActivityContentInfo : RTObject <WAUIUserActivityContentInfo>
+ (WAUUserActivityContentInfo*)fromJson:(NSString *)value;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (NSString *)toJson;
@end

#endif // __WAUUserActivityContentInfo_DEFINED__

// Windows.ApplicationModel.UserActivities.UserActivityVisualElements
#ifndef __WAUUserActivityVisualElements_DEFINED__
#define __WAUUserActivityVisualElements_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERACTIVITIESEXPORT
@interface WAUUserActivityVisualElements : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * displayText;
@property (retain) NSString * Description;
@property (retain) RTObject<WUSIAdaptiveCard>* content;
@property (retain) WUColor* backgroundColor;
@property (retain) WAUUserActivityAttribution* attribution;
@end

#endif // __WAUUserActivityVisualElements_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSAPPLICATIONMODELUSERACTIVITIESEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.ApplicationModel.UserActivities.UserActivitySession
#ifndef __WAUUserActivitySession_DEFINED__
#define __WAUUserActivitySession_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERACTIVITIESEXPORT
@interface WAUUserActivitySession : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * activityId;
- (void)close;
@end

#endif // __WAUUserActivitySession_DEFINED__

// Windows.ApplicationModel.UserActivities.UserActivity
#ifndef __WAUUserActivity_DEFINED__
#define __WAUUserActivity_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERACTIVITIESEXPORT
@interface WAUUserActivity : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* fallbackUri;
@property (retain) WFUri* contentUri;
@property (retain) NSString * contentType;
@property (retain) RTObject<WAUIUserActivityContentInfo>* contentInfo;
@property (retain) WFUri* activationUri;
@property (readonly) NSString * activityId;
@property (readonly) WAUUserActivityState state;
@property (readonly) WAUUserActivityVisualElements* visualElements;
- (RTObject<WFIAsyncAction>*)saveAsync;
- (WAUUserActivitySession*)createSession;
@end

#endif // __WAUUserActivity_DEFINED__

// Windows.ApplicationModel.UserActivities.UserActivityChannel
#ifndef __WAUUserActivityChannel_DEFINED__
#define __WAUUserActivityChannel_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERACTIVITIESEXPORT
@interface WAUUserActivityChannel : RTObject
+ (WAUUserActivityChannel*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)getOrCreateUserActivityAsync:(NSString *)activityId success:(void (^)(WAUUserActivity*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)deleteActivityAsync:(NSString *)activityId;
- (RTObject<WFIAsyncAction>*)deleteAllActivitiesAsync;
@end

#endif // __WAUUserActivityChannel_DEFINED__

