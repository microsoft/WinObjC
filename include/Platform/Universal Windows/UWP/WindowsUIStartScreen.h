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

// WindowsUIStartScreen.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUISTARTSCREENEXPORT
#define OBJCUWPWINDOWSUISTARTSCREENEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIStartScreen.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUSJumpListItem, WUSJumpList, WUSSecondaryTileVisualElements, WUSSecondaryTile, WUSVisualElementsRequestedEventArgs, WUSTileMixedRealityModel, WUSVisualElementsRequest, WUSVisualElementsRequestDeferral, WUSStartScreenManager;
@protocol WUSIJumpListItem, WUSIJumpListItemStatics, WUSIJumpList, WUSIJumpListStatics, WUSISecondaryTile, WUSISecondaryTile2, WUSISecondaryTileVisualElements, WUSISecondaryTileVisualElements2, WUSISecondaryTileVisualElements3, WUSITileMixedRealityModel, WUSISecondaryTileVisualElements4, WUSISecondaryTileFactory, WUSISecondaryTileFactory2, WUSISecondaryTileStatics, WUSIVisualElementsRequestedEventArgs, WUSIVisualElementsRequest, WUSIVisualElementsRequestDeferral, WUSIStartScreenManager, WUSIStartScreenManagerStatics;

// Windows.UI.StartScreen.JumpListSystemGroupKind
enum _WUSJumpListSystemGroupKind {
    WUSJumpListSystemGroupKindNone = 0,
    WUSJumpListSystemGroupKindFrequent = 1,
    WUSJumpListSystemGroupKindRecent = 2,
};
typedef unsigned WUSJumpListSystemGroupKind;

// Windows.UI.StartScreen.JumpListItemKind
enum _WUSJumpListItemKind {
    WUSJumpListItemKindArguments = 0,
    WUSJumpListItemKindSeparator = 1,
};
typedef unsigned WUSJumpListItemKind;

// Windows.UI.StartScreen.TileOptions
enum _WUSTileOptions {
    WUSTileOptionsNone = 0,
    WUSTileOptionsShowNameOnLogo = 1,
    WUSTileOptionsShowNameOnWideLogo = 2,
    WUSTileOptionsCopyOnDeployment = 4,
};
typedef unsigned WUSTileOptions;

// Windows.UI.StartScreen.TileSize
enum _WUSTileSize {
    WUSTileSizeDefault = 0,
    WUSTileSizeSquare30x30 = 1,
    WUSTileSizeSquare70x70 = 2,
    WUSTileSizeSquare150x150 = 3,
    WUSTileSizeWide310x150 = 4,
    WUSTileSizeSquare310x310 = 5,
    WUSTileSizeSquare71x71 = 6,
    WUSTileSizeSquare44x44 = 7,
};
typedef unsigned WUSTileSize;

// Windows.UI.StartScreen.ForegroundText
enum _WUSForegroundText {
    WUSForegroundTextDark = 0,
    WUSForegroundTextLight = 1,
};
typedef unsigned WUSForegroundText;

#include "WindowsUIPopups.h"
#include "WindowsFoundation.h"
#include "WindowsUI.h"
#include "WindowsPerceptionSpatial.h"
#include "WindowsSystem.h"
#include "WindowsApplicationModelCore.h"

#import <Foundation/Foundation.h>

// Windows.UI.StartScreen.JumpListItem
#ifndef __WUSJumpListItem_DEFINED__
#define __WUSJumpListItem_DEFINED__

OBJCUWPWINDOWSUISTARTSCREENEXPORT
@interface WUSJumpListItem : RTObject
+ (WUSJumpListItem*)createWithArguments:(NSString *)arguments displayName:(NSString *)displayName;
+ (WUSJumpListItem*)createSeparator;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* logo;
@property (retain) NSString * groupName;
@property (retain) NSString * displayName;
@property (retain) NSString * Description;
@property (readonly) NSString * arguments;
@property (readonly) WUSJumpListItemKind kind;
@property (readonly) BOOL removedByUser;
@end

#endif // __WUSJumpListItem_DEFINED__

// Windows.UI.StartScreen.JumpList
#ifndef __WUSJumpList_DEFINED__
#define __WUSJumpList_DEFINED__

OBJCUWPWINDOWSUISTARTSCREENEXPORT
@interface WUSJumpList : RTObject
+ (void)loadCurrentAsyncWithSuccess:(void (^)(WUSJumpList*))success failure:(void (^)(NSError*))failure;
+ (BOOL)isSupported;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUSJumpListSystemGroupKind systemGroupKind;
@property (readonly) NSMutableArray* /* WUSJumpListItem* */ items;
- (RTObject<WFIAsyncAction>*)saveAsync;
@end

#endif // __WUSJumpList_DEFINED__

// Windows.UI.StartScreen.SecondaryTileVisualElements
#ifndef __WUSSecondaryTileVisualElements_DEFINED__
#define __WUSSecondaryTileVisualElements_DEFINED__

OBJCUWPWINDOWSUISTARTSCREENEXPORT
@interface WUSSecondaryTileVisualElements : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* square150x150Logo;
@property BOOL showNameOnWide310x150Logo;
@property BOOL showNameOnSquare310x310Logo;
@property BOOL showNameOnSquare150x150Logo;
@property WUSForegroundText foregroundText;
@property (retain) WUColor* backgroundColor;
@property (retain) WFUri* wide310x150Logo;
@property (retain) WFUri* square70x70Logo;
@property (retain) WFUri* square310x310Logo;
@property (retain) WFUri* square30x30Logo;
@property (retain) WFUri* square71x71Logo;
@property (retain) WFUri* square44x44Logo;
@property (readonly) WUSTileMixedRealityModel* mixedRealityModel;
@end

#endif // __WUSSecondaryTileVisualElements_DEFINED__

// Windows.UI.StartScreen.SecondaryTile
#ifndef __WUSSecondaryTile_DEFINED__
#define __WUSSecondaryTile_DEFINED__

OBJCUWPWINDOWSUISTARTSCREENEXPORT
@interface WUSSecondaryTile : RTObject
+ (BOOL)exists:(NSString *)tileId;
+ (void)findAllAsyncWithSuccess:(void (^)(NSArray* /* WUSSecondaryTile* */))success failure:(void (^)(NSError*))failure;
+ (void)findAllForApplicationAsync:(NSString *)applicationId success:(void (^)(NSArray* /* WUSSecondaryTile* */))success failure:(void (^)(NSError*))failure;
+ (void)findAllForPackageAsyncWithSuccess:(void (^)(NSArray* /* WUSSecondaryTile* */))success failure:(void (^)(NSError*))failure;
+ (instancetype)make __attribute__ ((ns_returns_retained));
+ (WUSSecondaryTile*)makeTile:(NSString *)tileId shortName:(NSString *)shortName displayName:(NSString *)displayName arguments:(NSString *)arguments tileOptions:(WUSTileOptions)tileOptions logoReference:(WFUri*)logoReference ACTIVATOR;
+ (WUSSecondaryTile*)makeWideTile:(NSString *)tileId shortName:(NSString *)shortName displayName:(NSString *)displayName arguments:(NSString *)arguments tileOptions:(WUSTileOptions)tileOptions logoReference:(WFUri*)logoReference wideLogoReference:(WFUri*)wideLogoReference ACTIVATOR;
+ (WUSSecondaryTile*)makeWithId:(NSString *)tileId ACTIVATOR;
+ (WUSSecondaryTile*)makeMinimalTile:(NSString *)tileId displayName:(NSString *)displayName arguments:(NSString *)arguments square150x150Logo:(WFUri*)square150x150Logo desiredSize:(WUSTileSize)desiredSize ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * shortName;
@property (retain) WFUri* logo;
@property (retain) NSString * tileId;
@property BOOL lockScreenDisplayBadgeAndTileText;
@property (retain) WFUri* lockScreenBadgeLogo;
@property (retain) NSString * arguments;
@property WUSForegroundText foregroundText;
@property (retain) NSString * displayName;
@property (retain) WUColor* backgroundColor;
@property (retain) WFUri* wideLogo;
@property WUSTileOptions tileOptions;
@property (retain) WFUri* smallLogo;
@property BOOL roamingEnabled;
@property (retain) NSString * phoneticName;
@property (readonly) WUSSecondaryTileVisualElements* visualElements;
- (EventRegistrationToken)addVisualElementsRequestedEvent:(void(^)(WUSSecondaryTile*, WUSVisualElementsRequestedEventArgs*))del;
- (void)removeVisualElementsRequestedEvent:(EventRegistrationToken)tok;
- (void)requestCreateAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestCreateAsyncWithPoint:(WFPoint*)invocationPoint success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestCreateAsyncWithRect:(WFRect*)selection success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestCreateAsyncWithRectAndPlacement:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestDeleteAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestDeleteAsyncWithPoint:(WFPoint*)invocationPoint success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestDeleteAsyncWithRect:(WFRect*)selection success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestDeleteAsyncWithRectAndPlacement:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)updateAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WUSSecondaryTile_DEFINED__

// Windows.UI.StartScreen.VisualElementsRequestedEventArgs
#ifndef __WUSVisualElementsRequestedEventArgs_DEFINED__
#define __WUSVisualElementsRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSUISTARTSCREENEXPORT
@interface WUSVisualElementsRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUSVisualElementsRequest* request;
@end

#endif // __WUSVisualElementsRequestedEventArgs_DEFINED__

// Windows.UI.StartScreen.TileMixedRealityModel
#ifndef __WUSTileMixedRealityModel_DEFINED__
#define __WUSTileMixedRealityModel_DEFINED__

OBJCUWPWINDOWSUISTARTSCREENEXPORT
@interface WUSTileMixedRealityModel : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* uri;
@property (retain) id /* WPSSpatialBoundingBox* */ boundingBox;
@end

#endif // __WUSTileMixedRealityModel_DEFINED__

// Windows.UI.StartScreen.VisualElementsRequest
#ifndef __WUSVisualElementsRequest_DEFINED__
#define __WUSVisualElementsRequest_DEFINED__

OBJCUWPWINDOWSUISTARTSCREENEXPORT
@interface WUSVisualElementsRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WUSSecondaryTileVisualElements* */ alternateVisualElements;
@property (readonly) WFDateTime* deadline;
@property (readonly) WUSSecondaryTileVisualElements* visualElements;
- (WUSVisualElementsRequestDeferral*)getDeferral;
@end

#endif // __WUSVisualElementsRequest_DEFINED__

// Windows.UI.StartScreen.VisualElementsRequestDeferral
#ifndef __WUSVisualElementsRequestDeferral_DEFINED__
#define __WUSVisualElementsRequestDeferral_DEFINED__

OBJCUWPWINDOWSUISTARTSCREENEXPORT
@interface WUSVisualElementsRequestDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WUSVisualElementsRequestDeferral_DEFINED__

// Windows.UI.StartScreen.StartScreenManager
#ifndef __WUSStartScreenManager_DEFINED__
#define __WUSStartScreenManager_DEFINED__

OBJCUWPWINDOWSUISTARTSCREENEXPORT
@interface WUSStartScreenManager : RTObject
+ (WUSStartScreenManager*)getDefault;
+ (WUSStartScreenManager*)getForUser:(WSUser*)user;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSUser* user;
- (BOOL)supportsAppListEntry:(WACAppListEntry*)appListEntry;
- (void)containsAppListEntryAsync:(WACAppListEntry*)appListEntry success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestAddAppListEntryAsync:(WACAppListEntry*)appListEntry success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WUSStartScreenManager_DEFINED__

