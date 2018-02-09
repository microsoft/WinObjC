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

// WindowsServicesTargetedContent.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT
#define OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsServicesTargetedContent.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSTTargetedContentSubscription, WSTTargetedContentSubscriptionOptions, WSTTargetedContentContainer, WSTTargetedContentChangedEventArgs, WSTTargetedContentAvailabilityChangedEventArgs, WSTTargetedContentStateChangedEventArgs, WSTTargetedContentCollection, WSTTargetedContentObject, WSTTargetedContentItem, WSTTargetedContentValue, WSTTargetedContentItemState, WSTTargetedContentFile, WSTTargetedContentImage, WSTTargetedContentAction;
@protocol WSTITargetedContentSubscriptionOptions, WSTITargetedContentSubscriptionStatics, WSTITargetedContentSubscription, WSTITargetedContentChangedEventArgs, WSTITargetedContentAvailabilityChangedEventArgs, WSTITargetedContentStateChangedEventArgs, WSTITargetedContentImage, WSTITargetedContentAction, WSTITargetedContentContainerStatics, WSTITargetedContentContainer, WSTITargetedContentObject, WSTITargetedContentCollection, WSTITargetedContentItemState, WSTITargetedContentItem, WSTITargetedContentValue;

// Windows.Services.TargetedContent.TargetedContentInteraction
enum _WSTTargetedContentInteraction {
    WSTTargetedContentInteractionImpression = 0,
    WSTTargetedContentInteractionClickThrough = 1,
    WSTTargetedContentInteractionHover = 2,
    WSTTargetedContentInteractionLike = 3,
    WSTTargetedContentInteractionDislike = 4,
    WSTTargetedContentInteractionDismiss = 5,
    WSTTargetedContentInteractionIneligible = 6,
    WSTTargetedContentInteractionAccept = 7,
    WSTTargetedContentInteractionDecline = 8,
    WSTTargetedContentInteractionDefer = 9,
    WSTTargetedContentInteractionCanceled = 10,
    WSTTargetedContentInteractionConversion = 11,
    WSTTargetedContentInteractionOpportunity = 12,
};
typedef unsigned WSTTargetedContentInteraction;

// Windows.Services.TargetedContent.TargetedContentValueKind
enum _WSTTargetedContentValueKind {
    WSTTargetedContentValueKindString = 0,
    WSTTargetedContentValueKindUri = 1,
    WSTTargetedContentValueKindNumber = 2,
    WSTTargetedContentValueKindBoolean = 3,
    WSTTargetedContentValueKindFile = 4,
    WSTTargetedContentValueKindImageFile = 5,
    WSTTargetedContentValueKindAction = 6,
    WSTTargetedContentValueKindStrings = 7,
    WSTTargetedContentValueKindUris = 8,
    WSTTargetedContentValueKindNumbers = 9,
    WSTTargetedContentValueKindBooleans = 10,
    WSTTargetedContentValueKindFiles = 11,
    WSTTargetedContentValueKindImageFiles = 12,
    WSTTargetedContentValueKindActions = 13,
};
typedef unsigned WSTTargetedContentValueKind;

// Windows.Services.TargetedContent.TargetedContentObjectKind
enum _WSTTargetedContentObjectKind {
    WSTTargetedContentObjectKindCollection = 0,
    WSTTargetedContentObjectKindItem = 1,
    WSTTargetedContentObjectKindValue = 2,
};
typedef unsigned WSTTargetedContentObjectKind;

// Windows.Services.TargetedContent.TargetedContentAvailability
enum _WSTTargetedContentAvailability {
    WSTTargetedContentAvailabilityNone = 0,
    WSTTargetedContentAvailabilityPartial = 1,
    WSTTargetedContentAvailabilityAll = 2,
};
typedef unsigned WSTTargetedContentAvailability;

// Windows.Services.TargetedContent.TargetedContentAppInstallationState
enum _WSTTargetedContentAppInstallationState {
    WSTTargetedContentAppInstallationStateNotApplicable = 0,
    WSTTargetedContentAppInstallationStateNotInstalled = 1,
    WSTTargetedContentAppInstallationStateInstalled = 2,
};
typedef unsigned WSTTargetedContentAppInstallationState;

#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// Windows.Services.TargetedContent.TargetedContentSubscription
#ifndef __WSTTargetedContentSubscription_DEFINED__
#define __WSTTargetedContentSubscription_DEFINED__

OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT
@interface WSTTargetedContentSubscription : RTObject
+ (void)getAsync:(NSString *)subscriptionId success:(void (^)(WSTTargetedContentSubscription*))success failure:(void (^)(NSError*))failure;
+ (WSTTargetedContentSubscriptionOptions*)getOptions:(NSString *)subscriptionId;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * id;
- (EventRegistrationToken)addAvailabilityChangedEvent:(void(^)(WSTTargetedContentSubscription*, WSTTargetedContentAvailabilityChangedEventArgs*))del;
- (void)removeAvailabilityChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addContentChangedEvent:(void(^)(WSTTargetedContentSubscription*, WSTTargetedContentChangedEventArgs*))del;
- (void)removeContentChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStateChangedEvent:(void(^)(WSTTargetedContentSubscription*, WSTTargetedContentStateChangedEventArgs*))del;
- (void)removeStateChangedEvent:(EventRegistrationToken)tok;
- (void)getContentContainerAsyncWithSuccess:(void (^)(WSTTargetedContentContainer*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSTTargetedContentSubscription_DEFINED__

// Windows.Services.TargetedContent.TargetedContentSubscriptionOptions
#ifndef __WSTTargetedContentSubscriptionOptions_DEFINED__
#define __WSTTargetedContentSubscriptionOptions_DEFINED__

OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT
@interface WSTTargetedContentSubscriptionOptions : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL allowPartialContentAvailability;
@property (readonly) NSMutableDictionary* /* NSString *, NSString * */ cloudQueryParameters;
@property (readonly) NSMutableArray* /* NSString * */ localFilters;
@property (readonly) NSString * subscriptionId;
- (void)update;
@end

#endif // __WSTTargetedContentSubscriptionOptions_DEFINED__

// Windows.Services.TargetedContent.TargetedContentContainer
#ifndef __WSTTargetedContentContainer_DEFINED__
#define __WSTTargetedContentContainer_DEFINED__

OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT
@interface WSTTargetedContentContainer : RTObject
+ (void)getAsync:(NSString *)contentId success:(void (^)(WSTTargetedContentContainer*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSTTargetedContentAvailability availability;
@property (readonly) WSTTargetedContentCollection* content;
@property (readonly) NSString * id;
@property (readonly) WFDateTime* timestamp;
- (WSTTargetedContentObject*)selectSingleObject:(NSString *)path;
@end

#endif // __WSTTargetedContentContainer_DEFINED__

// Windows.Services.TargetedContent.TargetedContentChangedEventArgs
#ifndef __WSTTargetedContentChangedEventArgs_DEFINED__
#define __WSTTargetedContentChangedEventArgs_DEFINED__

OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT
@interface WSTTargetedContentChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL hasPreviousContentExpired;
- (WFDeferral*)getDeferral;
@end

#endif // __WSTTargetedContentChangedEventArgs_DEFINED__

// Windows.Services.TargetedContent.TargetedContentAvailabilityChangedEventArgs
#ifndef __WSTTargetedContentAvailabilityChangedEventArgs_DEFINED__
#define __WSTTargetedContentAvailabilityChangedEventArgs_DEFINED__

OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT
@interface WSTTargetedContentAvailabilityChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WFDeferral*)getDeferral;
@end

#endif // __WSTTargetedContentAvailabilityChangedEventArgs_DEFINED__

// Windows.Services.TargetedContent.TargetedContentStateChangedEventArgs
#ifndef __WSTTargetedContentStateChangedEventArgs_DEFINED__
#define __WSTTargetedContentStateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT
@interface WSTTargetedContentStateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WFDeferral*)getDeferral;
@end

#endif // __WSTTargetedContentStateChangedEventArgs_DEFINED__

// Windows.Services.TargetedContent.TargetedContentCollection
#ifndef __WSTTargetedContentCollection_DEFINED__
#define __WSTTargetedContentCollection_DEFINED__

OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT
@interface WSTTargetedContentCollection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WSTTargetedContentCollection* */ collections;
@property (readonly) NSString * id;
@property (readonly) NSArray* /* WSTTargetedContentItem* */ items;
@property (readonly) NSString * path;
@property (readonly) NSDictionary* /* NSString *, WSTTargetedContentValue* */ properties;
- (void)reportInteraction:(WSTTargetedContentInteraction)interaction;
- (void)reportCustomInteraction:(NSString *)customInteractionName;
@end

#endif // __WSTTargetedContentCollection_DEFINED__

// Windows.Services.TargetedContent.TargetedContentObject
#ifndef __WSTTargetedContentObject_DEFINED__
#define __WSTTargetedContentObject_DEFINED__

OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT
@interface WSTTargetedContentObject : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSTTargetedContentCollection* collection;
@property (readonly) WSTTargetedContentItem* item;
@property (readonly) WSTTargetedContentObjectKind objectKind;
@property (readonly) WSTTargetedContentValue* value;
@end

#endif // __WSTTargetedContentObject_DEFINED__

// Windows.Services.TargetedContent.TargetedContentItem
#ifndef __WSTTargetedContentItem_DEFINED__
#define __WSTTargetedContentItem_DEFINED__

OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT
@interface WSTTargetedContentItem : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WSTTargetedContentCollection* */ collections;
@property (readonly) NSString * path;
@property (readonly) NSDictionary* /* NSString *, WSTTargetedContentValue* */ properties;
@property (readonly) WSTTargetedContentItemState* state;
- (void)reportInteraction:(WSTTargetedContentInteraction)interaction;
- (void)reportCustomInteraction:(NSString *)customInteractionName;
@end

#endif // __WSTTargetedContentItem_DEFINED__

// Windows.Services.TargetedContent.TargetedContentValue
#ifndef __WSTTargetedContentValue_DEFINED__
#define __WSTTargetedContentValue_DEFINED__

OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT
@interface WSTTargetedContentValue : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSTTargetedContentAction* action;
@property (readonly) NSArray* /* WSTTargetedContentAction* */ actions;
@property (readonly) BOOL boolean;
@property (readonly) NSArray* /* BOOL */ booleans;
@property (readonly) WSTTargetedContentFile* file;
@property (readonly) NSArray* /* WSTTargetedContentFile* */ files;
@property (readonly) WSTTargetedContentImage* imageFile;
@property (readonly) NSArray* /* WSTTargetedContentImage* */ imageFiles;
@property (readonly) double number;
@property (readonly) NSArray* /* double */ numbers;
@property (readonly) NSString * path;
@property (readonly) NSString * string;
@property (readonly) NSArray* /* NSString * */ strings;
@property (readonly) WFUri* uri;
@property (readonly) NSArray* /* WFUri* */ uris;
@property (readonly) WSTTargetedContentValueKind valueKind;
@end

#endif // __WSTTargetedContentValue_DEFINED__

// Windows.Services.TargetedContent.TargetedContentItemState
#ifndef __WSTTargetedContentItemState_DEFINED__
#define __WSTTargetedContentItemState_DEFINED__

OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT
@interface WSTTargetedContentItemState : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSTTargetedContentAppInstallationState appInstallationState;
@property (readonly) BOOL shouldDisplay;
@end

#endif // __WSTTargetedContentItemState_DEFINED__

// Windows.Storage.Streams.IRandomAccessStreamReference
#ifndef __WSSIRandomAccessStreamReference_DEFINED__
#define __WSSIRandomAccessStreamReference_DEFINED__

@protocol WSSIRandomAccessStreamReference
- (void)openReadAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT
@interface WSSIRandomAccessStreamReference : RTObject <WSSIRandomAccessStreamReference>
@end

#endif // __WSSIRandomAccessStreamReference_DEFINED__

// Windows.Services.TargetedContent.TargetedContentFile
#ifndef __WSTTargetedContentFile_DEFINED__
#define __WSTTargetedContentFile_DEFINED__

OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT
@interface WSTTargetedContentFile : RTObject <WSSIRandomAccessStreamReference>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)openReadAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSTTargetedContentFile_DEFINED__

// Windows.Services.TargetedContent.TargetedContentImage
#ifndef __WSTTargetedContentImage_DEFINED__
#define __WSTTargetedContentImage_DEFINED__

OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT
@interface WSTTargetedContentImage : RTObject <WSSIRandomAccessStreamReference>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int height;
@property (readonly) unsigned int width;
- (void)openReadAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSTTargetedContentImage_DEFINED__

// Windows.Services.TargetedContent.TargetedContentAction
#ifndef __WSTTargetedContentAction_DEFINED__
#define __WSTTargetedContentAction_DEFINED__

OBJCUWPWINDOWSSERVICESTARGETEDCONTENTEXPORT
@interface WSTTargetedContentAction : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (RTObject<WFIAsyncAction>*)invokeAsync;
@end

#endif // __WSTTargetedContentAction_DEFINED__

