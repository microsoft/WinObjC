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

// MicrosoftAdvertisingSharedWinRT.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPMICROSOFTADVERTISINGEXPORT
#define OBJCUWPMICROSOFTADVERTISINGEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_MSAds_BUILD
#pragma comment(lib, "ObjCUWPMicrosoftAdvertising.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class MASWAdvertisement, MASWAdErrorEventArgs, MASWAdTagCollection, MASWProjectedContext, MASWAdPlacement, MASWVideoResource, MASWAdExtension, MASWActivityReporter, MASWAdPackage, MASWAdPod, MASWAdSchedule, MASWProjectedMediaConstraints, MASWAdScheduleResult, MASWAdScheduler, MASWSdkInfoProvider, MASWEventLogging, MASWProjectedIAdLogger, MASWPlatformDependency;
@class MASWSdkInfo;
@protocol MASW__IAdvertisementPublicNonVirtuals, MASW__IAdErrorEventArgsPublicNonVirtuals, MASW__IAdErrorEventArgsFactory, MASW__IAdTagCollectionPublicNonVirtuals, MASW__IProjectedContextPublicNonVirtuals, MASW__IAdPlacementPublicNonVirtuals, MASW__IAdPlacementFactory, MASW__IVideoResourcePublicNonVirtuals, MASW__IAdExtensionPublicNonVirtuals, MASW__IAdExtensionFactory, MASW__IActivityReporterPublicNonVirtuals, MASW__IAdPackagePublicNonVirtuals, MASW__IAdPodPublicNonVirtuals, MASW__IAdSchedulePublicNonVirtuals, MASW__IProjectedMediaConstraintsPublicNonVirtuals, MASW__IProjectedMediaConstraintsFactory, MASW__IProjectedMediaConstraintsStatics, MASW__IAdScheduleResultPublicNonVirtuals, MASW__IAdSchedulerPublicNonVirtuals, MASW__IAdSchedulerStatics, MASW__ISdkInfoProviderPublicNonVirtuals, MASW__ISdkInfoProviderStatics, MASW__IEventLoggingPublicNonVirtuals, MASW__IEventLoggingStatics, MASW__IProjectedIAdLoggerPublicNonVirtuals, MASW__IPlatformDependencyPublicNonVirtuals, MASW__IPlatformDependencyStatics;

// Microsoft.Advertising.Shared.WinRT.SdkType
enum _MASWSdkType {
    MASWSdkTypeUnknown = 0,
    MASWSdkTypeUniversalDisplayWwa = 1,
    MASWSdkTypeUniversalDisplayXaml = 2,
    MASWSdkTypeUniversalVideoWwa = 4,
    MASWSdkTypeUniversalVideoXaml = 8,
    MASWSdkTypeLinearVideoWwa = 16,
    MASWSdkTypeLinearVideoXaml = 32,
};
typedef unsigned MASWSdkType;

#include "MicrosoftAdvertising.h"

#import <Foundation/Foundation.h>

// [struct] Microsoft.Advertising.Shared.WinRT.SdkInfo
OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWSdkInfo : NSObject
+ (instancetype)new;
@property (retain) NSString * sdkVersion;
@property (retain) NSString * client;
@property (retain) NSString * runtimeType;
@end

// Microsoft.Advertising.Shared.WinRT.Advertisement
#ifndef __MASWAdvertisement_DEFINED__
#define __MASWAdvertisement_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWAdvertisement : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isPoly;
@property (readonly) NSString * payloadContent;
@property (readonly) NSString * guid;
@end

#endif // __MASWAdvertisement_DEFINED__

// Microsoft.Advertising.Shared.WinRT.AdErrorEventArgs
#ifndef __MASWAdErrorEventArgs_DEFINED__
#define __MASWAdErrorEventArgs_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWAdErrorEventArgs : RTObject
+ (MASWAdErrorEventArgs*)makeInstance1:(NSString *)msg code:(NSString *)code ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) MAErrorCode errorCodeEnum;
@property (readonly) NSString * errorCode;
@property (readonly) NSString * errorMessage;
@end

#endif // __MASWAdErrorEventArgs_DEFINED__

// Microsoft.Advertising.Shared.WinRT.AdTagCollection
#ifndef __MASWAdTagCollection_DEFINED__
#define __MASWAdTagCollection_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWAdTagCollection : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)addAdTag:(NSString *)tagName tagValue:(NSString *)tagValue;
- (void)removeAdTag:(NSString *)tagName;
- (void)clearAdTags;
- (NSString *)getAdTagsJson;
- (NSMutableDictionary* /* NSString *, NSString * */)getAdTags;
@end

#endif // __MASWAdTagCollection_DEFINED__

// Microsoft.Advertising.Shared.WinRT.ProjectedContext
#ifndef __MASWProjectedContext_DEFINED__
#define __MASWProjectedContext_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWProjectedContext : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (MASWProjectedIAdLogger*)getLogger;
@end

#endif // __MASWProjectedContext_DEFINED__

// Microsoft.Advertising.Shared.WinRT.AdPlacement
#ifndef __MASWAdPlacement_DEFINED__
#define __MASWAdPlacement_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWAdPlacement : RTObject
+ (MASWAdPlacement*)makeInstance3:(MASWSdkType)sdkType ACTIVATOR;
+ (MASWAdPlacement*)makeInstance2:(MASWSdkType)sdkType serviceUrl:(NSString *)serviceUrl ACTIVATOR;
+ (MASWAdPlacement*)makeInstance1:(MASWSdkType)sdkType applicationId:(NSString *)applicationId adUnitId:(NSString *)adUnitId ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) MASWSdkType sdkType;
@property (retain) NSString * postalCode;
@property (retain) NSString * countryOrRegion;
@property (retain) NSString * keywords;
@property int height;
@property int width;
@property (readonly) MASWAdErrorEventArgs* lastError;
@property (retain) MASWAdTagCollection* adTags;
@property (retain) NSString * serviceUrl;
@property (retain) NSString * adUnitId;
@property (retain) NSString * applicationId;
- (void)getAdAsync1:(unsigned int)timeoutInMilliseconds success:(void (^)(MASWAdvertisement*))success failure:(void (^)(NSError*))failure;
- (void)reportEvent:(NSString *)eventName;
- (void)clearLastError;
@end

#endif // __MASWAdPlacement_DEFINED__

// Microsoft.Advertising.Shared.WinRT.VideoResource
#ifndef __MASWVideoResource_DEFINED__
#define __MASWVideoResource_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWVideoResource : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL scalable;
@property (readonly) BOOL maintainAspect;
@property (readonly) unsigned int height;
@property (readonly) unsigned int width;
@property (readonly) unsigned int maxBitrate;
@property (readonly) unsigned int minBitrate;
@property (readonly) unsigned int bitrate;
@property (readonly) NSString * codec;
@property (readonly) NSString * uri;
@property (readonly) NSString * apiFramework;
@property (readonly) NSString * type;
@property (readonly) NSString * delivery;
@property (readonly) NSString * id;
@end

#endif // __MASWVideoResource_DEFINED__

// Microsoft.Advertising.Shared.WinRT.AdExtension
#ifndef __MASWAdExtension_DEFINED__
#define __MASWAdExtension_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWAdExtension : RTObject
+ (MASWAdExtension*)makeInstance1:(NSString *)type xmlData:(NSString *)xmlData ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * jsonData;
@property (readonly) NSString * xmlData;
@property (readonly) NSString * type;
@end

#endif // __MASWAdExtension_DEFINED__

// Microsoft.Advertising.Shared.WinRT.ActivityReporter
#ifndef __MASWActivityReporter_DEFINED__
#define __MASWActivityReporter_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWActivityReporter : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)reportAsync2:(NSString *)activity macros:(NSDictionary* /* NSString *, NSString * */)macros success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (void)reportAsync1:(NSString *)activity macros:(NSDictionary* /* NSString *, RTObject* */)macros success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
@end

#endif // __MASWActivityReporter_DEFINED__

// Microsoft.Advertising.Shared.WinRT.AdPackage
#ifndef __MASWAdPackage_DEFINED__
#define __MASWAdPackage_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWAdPackage : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * clickThroughUrl;
@property (readonly) NSString * skipOffset;
@property (readonly) NSString * adParameters;
@property (readonly) NSString * duration;
@property (readonly) NSArray* /* MASWAdExtension* */ adExtensions;
@property (readonly) NSArray* /* MASWVideoResource* */ video;
- (void)reportAsync3:(NSString *)activity success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (void)reportAsync2:(NSString *)activity macros:(NSDictionary* /* NSString *, NSString * */)macros success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (void)reportAsync1:(NSString *)activity macros:(NSDictionary* /* NSString *, RTObject* */)macros success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
@end

#endif // __MASWAdPackage_DEFINED__

// Microsoft.Advertising.Shared.WinRT.AdPod
#ifndef __MASWAdPod_DEFINED__
#define __MASWAdPod_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWAdPod : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* MASWAdPackage* */ packages;
@property (readonly) NSString * repeatAfter;
@property (readonly) NSString * id;
@property (readonly) NSString * time;
- (void)reportAsync3:(NSString *)activity success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (void)reportAsync2:(NSString *)activity macros:(NSDictionary* /* NSString *, NSString * */)macros success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (void)reportAsync1:(NSString *)activity macros:(NSDictionary* /* NSString *, RTObject* */)macros success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
@end

#endif // __MASWAdPod_DEFINED__

// Microsoft.Advertising.Shared.WinRT.AdSchedule
#ifndef __MASWAdSchedule_DEFINED__
#define __MASWAdSchedule_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWAdSchedule : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* MASWAdPod* */ pods;
@end

#endif // __MASWAdSchedule_DEFINED__

// Microsoft.Advertising.Shared.WinRT.ProjectedMediaConstraints
#ifndef __MASWProjectedMediaConstraints_DEFINED__
#define __MASWProjectedMediaConstraints_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWProjectedMediaConstraints : RTObject
+ (MASWProjectedMediaConstraints*)makeInstance1:(NSArray* /* NSString * */)supportedMimeTypes ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
+ (MASWProjectedMediaConstraints*)defaultMediaConstraints;
@property (readonly) NSArray* /* NSString * */ supportedMimeTypes;
@end

#endif // __MASWProjectedMediaConstraints_DEFINED__

// Microsoft.Advertising.Shared.WinRT.AdScheduleResult
#ifndef __MASWAdScheduleResult_DEFINED__
#define __MASWAdScheduleResult_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWAdScheduleResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) MASWAdSchedule* value;
@property (readonly) MASWAdErrorEventArgs* error;
@end

#endif // __MASWAdScheduleResult_DEFINED__

// Microsoft.Advertising.Shared.WinRT.AdScheduler
#ifndef __MASWAdScheduler_DEFINED__
#define __MASWAdScheduler_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWAdScheduler : RTObject
+ (void)getScheduleAsync2:(NSString *)appId adId:(NSString *)adId timeoutMS:(unsigned int)timeoutMS sdkType:(MASWSdkType)sdkType adTags:(MASWAdTagCollection*)adTags success:(void (^)(MASWAdScheduleResult*))success failure:(void (^)(NSError*))failure;
+ (void)getScheduleAsync1:(NSString *)serviceUrl timeoutMS:(unsigned int)timeoutMS sdkType:(MASWSdkType)sdkType success:(void (^)(MASWAdScheduleResult*))success failure:(void (^)(NSError*))failure;
+ (void)getScheduleStrictAsync4:(NSString *)appId adId:(NSString *)adId timeoutMS:(unsigned int)timeoutMS sdkType:(MASWSdkType)sdkType adTags:(MASWAdTagCollection*)adTags mediaConstraints:(MASWProjectedMediaConstraints*)mediaConstraints success:(void (^)(MASWAdScheduleResult*))success failure:(void (^)(NSError*))failure;
+ (void)getScheduleStrictAsync3:(NSString *)appId adId:(NSString *)adId timeoutMS:(unsigned int)timeoutMS sdkType:(MASWSdkType)sdkType adTags:(MASWAdTagCollection*)adTags projectedContext:(MASWProjectedContext*)projectedContext mediaConstraints:(MASWProjectedMediaConstraints*)mediaConstraints success:(void (^)(MASWAdScheduleResult*))success failure:(void (^)(NSError*))failure;
+ (void)getScheduleStrictAsync2:(NSString *)serviceUrl timeoutMS:(unsigned int)timeoutMS sdkType:(MASWSdkType)sdkType mediaConstraints:(MASWProjectedMediaConstraints*)mediaConstraints success:(void (^)(MASWAdScheduleResult*))success failure:(void (^)(NSError*))failure;
+ (void)getScheduleStrictAsync1:(NSString *)serviceUrl timeoutMS:(unsigned int)timeoutMS sdkType:(MASWSdkType)sdkType projectedContext:(MASWProjectedContext*)projectedContext mediaConstraints:(MASWProjectedMediaConstraints*)mediaConstraints success:(void (^)(MASWAdScheduleResult*))success failure:(void (^)(NSError*))failure;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __MASWAdScheduler_DEFINED__

// Microsoft.Advertising.Shared.WinRT.SdkInfoProvider
#ifndef __MASWSdkInfoProvider_DEFINED__
#define __MASWSdkInfoProvider_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWSdkInfoProvider : RTObject
+ (MASWSdkInfo*)getSdkInfo;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __MASWSdkInfoProvider_DEFINED__

// Microsoft.Advertising.Shared.WinRT.EventLogging
#ifndef __MASWEventLogging_DEFINED__
#define __MASWEventLogging_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWEventLogging : RTObject
+ (unsigned int)adRendererPageAction;
+ (unsigned int)adRendererPageView;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __MASWEventLogging_DEFINED__

// Microsoft.Advertising.Shared.WinRT.ProjectedIAdLogger
#ifndef __MASWProjectedIAdLogger_DEFINED__
#define __MASWProjectedIAdLogger_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWProjectedIAdLogger : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (BOOL)logError:(unsigned int)code message:(NSString *)message;
- (void)setPublisherId:(NSString *)publisherId;
- (void)setAdUnitId:(NSString *)adUnitId;
- (void)setSourceUrl:(NSString *)sourceUrl;
- (void)setSdkType:(MASWSdkType)sdkType;
- (void)setASID:(NSString *)asid;
@end

#endif // __MASWProjectedIAdLogger_DEFINED__

// Microsoft.Advertising.Shared.WinRT.PlatformDependency
#ifndef __MASWPlatformDependency_DEFINED__
#define __MASWPlatformDependency_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MASWPlatformDependency : RTObject
+ (NSString *)getBootstrapZoomStyle;
+ (BOOL)isMobile;
+ (BOOL)isWindows;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __MASWPlatformDependency_DEFINED__

