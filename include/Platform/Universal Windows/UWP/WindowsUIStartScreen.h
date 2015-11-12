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

// WindowsUIStartScreen.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUSSecondaryTileVisualElements, WUSSecondaryTile, WUSVisualElementsRequestedEventArgs, WUSVisualElementsRequest,
    WUSVisualElementsRequestDeferral;
@protocol WUSISecondaryTile
, WUSISecondaryTile2, WUSISecondaryTileVisualElements, WUSISecondaryTileVisualElements2, WUSISecondaryTileVisualElements3,
    WUSISecondaryTileFactory, WUSISecondaryTileFactory2, WUSISecondaryTileStatics, WUSIVisualElementsRequestedEventArgs,
    WUSIVisualElementsRequest, WUSIVisualElementsRequestDeferral;

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
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// Windows.UI.StartScreen.SecondaryTileVisualElements
#ifndef __WUSSecondaryTileVisualElements_DEFINED__
#define __WUSSecondaryTileVisualElements_DEFINED__

WINRT_EXPORT
@interface WUSSecondaryTileVisualElements : RTObject
@property (copy) WFUri* square150x150Logo;
@property BOOL showNameOnWide310x150Logo;
@property BOOL showNameOnSquare310x310Logo;
@property BOOL showNameOnSquare150x150Logo;
@property WUSForegroundText foregroundText;
@property (copy) WUColor* backgroundColor;
@property (copy) WFUri* wide310x150Logo;
@property (copy) WFUri* square70x70Logo;
@property (copy) WFUri* square310x310Logo;
@property (copy) WFUri* square30x30Logo;
@property (copy) WFUri* square71x71Logo;
@property (copy) WFUri* square44x44Logo;
@end

#endif // __WUSSecondaryTileVisualElements_DEFINED__

// Windows.UI.StartScreen.SecondaryTile
#ifndef __WUSSecondaryTile_DEFINED__
#define __WUSSecondaryTile_DEFINED__

WINRT_EXPORT
@interface WUSSecondaryTile : RTObject
+ (BOOL)exists:(NSString*)tileId;
+ (void)findAllAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
+ (void)findAllForApplicationAsync:(NSString*)applicationId success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
+ (void)findAllForPackageAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
+ (WUSSecondaryTile*)createMinimalTile:(NSString*)tileId
                           displayName:(NSString*)displayName
                             arguments:(NSString*)arguments
                     square150x150Logo:(WFUri*)square150x150Logo
                           desiredSize:(WUSTileSize)desiredSize ACTIVATOR;
+ (WUSSecondaryTile*)createTile:(NSString*)tileId
                      shortName:(NSString*)shortName
                    displayName:(NSString*)displayName
                      arguments:(NSString*)arguments
                    tileOptions:(WUSTileOptions)tileOptions
                  logoReference:(WFUri*)logoReference ACTIVATOR;
+ (WUSSecondaryTile*)createWideTile:(NSString*)tileId
                          shortName:(NSString*)shortName
                        displayName:(NSString*)displayName
                          arguments:(NSString*)arguments
                        tileOptions:(WUSTileOptions)tileOptions
                      logoReference:(WFUri*)logoReference
                  wideLogoReference:(WFUri*)wideLogoReference ACTIVATOR;
+ (WUSSecondaryTile*)createWithId:(NSString*)tileId ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* shortName;
@property (copy) WFUri* logo;
@property (copy) NSString* tileId;
@property BOOL lockScreenDisplayBadgeAndTileText;
@property (copy) WFUri* lockScreenBadgeLogo;
@property (copy) NSString* arguments;
@property WUSForegroundText foregroundText;
@property (copy) NSString* displayName;
@property (copy) WUColor* backgroundColor;
@property (copy) WFUri* wideLogo;
@property WUSTileOptions tileOptions;
@property (copy) WFUri* smallLogo;
@property BOOL roamingEnabled;
@property (copy) NSString* phoneticName;
@property (readonly) WUSSecondaryTileVisualElements* visualElements;
- (EventRegistrationToken)addVisualElementsRequestedEvent:(void (^)(WUSSecondaryTile*, WUSVisualElementsRequestedEventArgs*))del;
- (void)removeVisualElementsRequestedEvent:(EventRegistrationToken)tok;
- (void)requestCreateAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestCreateAsyncWithPoint:(WFPoint*)invocationPoint success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestCreateAsyncWithRect:(WFRect*)selection success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestCreateAsyncWithRectAndPlacement:(WFRect*)selection
                            preferredPlacement:(WUPPlacement)preferredPlacement
                                       success:(void (^)(BOOL))success
                                       failure:(void (^)(NSError*))failure;
- (void)requestDeleteAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestDeleteAsyncWithPoint:(WFPoint*)invocationPoint success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestDeleteAsyncWithRect:(WFRect*)selection success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestDeleteAsyncWithRectAndPlacement:(WFRect*)selection
                            preferredPlacement:(WUPPlacement)preferredPlacement
                                       success:(void (^)(BOOL))success
                                       failure:(void (^)(NSError*))failure;
- (void)updateAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WUSSecondaryTile_DEFINED__

// Windows.UI.StartScreen.VisualElementsRequestedEventArgs
#ifndef __WUSVisualElementsRequestedEventArgs_DEFINED__
#define __WUSVisualElementsRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUSVisualElementsRequestedEventArgs : RTObject
@property (readonly) WUSVisualElementsRequest* request;
@end

#endif // __WUSVisualElementsRequestedEventArgs_DEFINED__

// Windows.UI.StartScreen.VisualElementsRequest
#ifndef __WUSVisualElementsRequest_DEFINED__
#define __WUSVisualElementsRequest_DEFINED__

WINRT_EXPORT
@interface WUSVisualElementsRequest : RTObject
@property (readonly) NSArray* alternateVisualElements;
@property (readonly) WFDateTime* deadline;
@property (readonly) WUSSecondaryTileVisualElements* visualElements;
- (WUSVisualElementsRequestDeferral*)getDeferral;
@end

#endif // __WUSVisualElementsRequest_DEFINED__

// Windows.UI.StartScreen.VisualElementsRequestDeferral
#ifndef __WUSVisualElementsRequestDeferral_DEFINED__
#define __WUSVisualElementsRequestDeferral_DEFINED__

WINRT_EXPORT
@interface WUSVisualElementsRequestDeferral : RTObject
- (void)complete;
@end

#endif // __WUSVisualElementsRequestDeferral_DEFINED__
