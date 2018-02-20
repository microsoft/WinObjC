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

// WindowsApplicationModelSocialInfo.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELSOCIALINFOEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELSOCIALINFOEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelSocialInfo.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WASSocialUserInfo, WASSocialFeedContent, WASSocialItemThumbnail, WASSocialFeedSharedItem, WASSocialFeedChildItem, WASSocialFeedItem;
@protocol WASISocialItemThumbnail, WASISocialFeedContent, WASISocialUserInfo, WASISocialFeedItem, WASISocialFeedChildItem, WASISocialFeedSharedItem;

// Windows.ApplicationModel.SocialInfo.SocialItemBadgeStyle
enum _WASSocialItemBadgeStyle {
    WASSocialItemBadgeStyleHidden = 0,
    WASSocialItemBadgeStyleVisible = 1,
    WASSocialItemBadgeStyleVisibleWithCount = 2,
};
typedef unsigned WASSocialItemBadgeStyle;

// Windows.ApplicationModel.SocialInfo.SocialFeedKind
enum _WASSocialFeedKind {
    WASSocialFeedKindHomeFeed = 0,
    WASSocialFeedKindContactFeed = 1,
    WASSocialFeedKindDashboard = 2,
};
typedef unsigned WASSocialFeedKind;

// Windows.ApplicationModel.SocialInfo.SocialFeedItemStyle
enum _WASSocialFeedItemStyle {
    WASSocialFeedItemStyleDefault = 0,
    WASSocialFeedItemStylePhoto = 1,
};
typedef unsigned WASSocialFeedItemStyle;

// Windows.ApplicationModel.SocialInfo.SocialFeedUpdateMode
enum _WASSocialFeedUpdateMode {
    WASSocialFeedUpdateModeAppend = 0,
    WASSocialFeedUpdateModeReplace = 1,
};
typedef unsigned WASSocialFeedUpdateMode;

#include "WindowsFoundation.h"
#include "WindowsGraphicsImaging.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.SocialInfo.SocialUserInfo
#ifndef __WASSocialUserInfo_DEFINED__
#define __WASSocialUserInfo_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSOCIALINFOEXPORT
@interface WASSocialUserInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * userName;
@property (retain) WFUri* targetUri;
@property (retain) NSString * remoteId;
@property (retain) NSString * displayName;
@end

#endif // __WASSocialUserInfo_DEFINED__

// Windows.ApplicationModel.SocialInfo.SocialFeedContent
#ifndef __WASSocialFeedContent_DEFINED__
#define __WASSocialFeedContent_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSOCIALINFOEXPORT
@interface WASSocialFeedContent : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * title;
@property (retain) WFUri* targetUri;
@property (retain) NSString * message;
@end

#endif // __WASSocialFeedContent_DEFINED__

// Windows.ApplicationModel.SocialInfo.SocialItemThumbnail
#ifndef __WASSocialItemThumbnail_DEFINED__
#define __WASSocialItemThumbnail_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSOCIALINFOEXPORT
@interface WASSocialItemThumbnail : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* targetUri;
@property (retain) WFUri* imageUri;
@property (retain) WGIBitmapSize* bitmapSize;
- (RTObject<WFIAsyncAction>*)setImageAsync:(RTObject<WSSIInputStream>*)image;
@end

#endif // __WASSocialItemThumbnail_DEFINED__

// Windows.ApplicationModel.SocialInfo.SocialFeedSharedItem
#ifndef __WASSocialFeedSharedItem_DEFINED__
#define __WASSocialFeedSharedItem_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSOCIALINFOEXPORT
@interface WASSocialFeedSharedItem : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFDateTime* timestamp;
@property (retain) WASSocialItemThumbnail* thumbnail;
@property (retain) WFUri* targetUri;
@property (retain) WFUri* originalSource;
@property (readonly) WASSocialFeedContent* content;
@end

#endif // __WASSocialFeedSharedItem_DEFINED__

// Windows.ApplicationModel.SocialInfo.SocialFeedChildItem
#ifndef __WASSocialFeedChildItem_DEFINED__
#define __WASSocialFeedChildItem_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSOCIALINFOEXPORT
@interface WASSocialFeedChildItem : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFDateTime* timestamp;
@property (retain) WFUri* targetUri;
@property (retain) WASSocialFeedSharedItem* sharedItem;
@property (readonly) WASSocialUserInfo* author;
@property (readonly) WASSocialFeedContent* primaryContent;
@property (readonly) WASSocialFeedContent* secondaryContent;
@property (readonly) NSMutableArray* /* WASSocialItemThumbnail* */ thumbnails;
@end

#endif // __WASSocialFeedChildItem_DEFINED__

// Windows.ApplicationModel.SocialInfo.SocialFeedItem
#ifndef __WASSocialFeedItem_DEFINED__
#define __WASSocialFeedItem_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSOCIALINFOEXPORT
@interface WASSocialFeedItem : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFDateTime* timestamp;
@property (retain) WFUri* targetUri;
@property WASSocialFeedItemStyle style;
@property (retain) WASSocialFeedSharedItem* sharedItem;
@property (retain) NSString * remoteId;
@property (retain) WASSocialFeedChildItem* childItem;
@property WASSocialItemBadgeStyle badgeStyle;
@property int badgeCountValue;
@property (readonly) WASSocialUserInfo* author;
@property (readonly) NSMutableArray* /* WASSocialItemThumbnail* */ thumbnails;
@property (readonly) WASSocialFeedContent* primaryContent;
@property (readonly) WASSocialFeedContent* secondaryContent;
@end

#endif // __WASSocialFeedItem_DEFINED__

