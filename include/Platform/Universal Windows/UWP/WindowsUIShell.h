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

// WindowsUIShell.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUISHELLEXPORT
#define OBJCUWPWINDOWSUISHELLEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIShell.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUSAdaptiveCardBuilder, WUSTaskbarManager;
@protocol WUSIAdaptiveCard, WUSIAdaptiveCardBuilderStatics, WUSITaskbarManager, WUSITaskbarManagerStatics;

#include "WindowsApplicationModelCore.h"

#import <Foundation/Foundation.h>

// Windows.UI.Shell.IAdaptiveCard
#ifndef __WUSIAdaptiveCard_DEFINED__
#define __WUSIAdaptiveCard_DEFINED__

@protocol WUSIAdaptiveCard
- (NSString *)toJson;
@end

OBJCUWPWINDOWSUISHELLEXPORT
@interface WUSIAdaptiveCard : RTObject <WUSIAdaptiveCard>
@end

#endif // __WUSIAdaptiveCard_DEFINED__

// Windows.UI.Shell.IAdaptiveCardBuilderStatics
#ifndef __WUSIAdaptiveCardBuilderStatics_DEFINED__
#define __WUSIAdaptiveCardBuilderStatics_DEFINED__

@protocol WUSIAdaptiveCardBuilderStatics
- (RTObject<WUSIAdaptiveCard>*)createAdaptiveCardFromJson:(NSString *)value;
@end

OBJCUWPWINDOWSUISHELLEXPORT
@interface WUSIAdaptiveCardBuilderStatics : RTObject <WUSIAdaptiveCardBuilderStatics>
@end

#endif // __WUSIAdaptiveCardBuilderStatics_DEFINED__

// Windows.UI.Shell.AdaptiveCardBuilder
#ifndef __WUSAdaptiveCardBuilder_DEFINED__
#define __WUSAdaptiveCardBuilder_DEFINED__

OBJCUWPWINDOWSUISHELLEXPORT
@interface WUSAdaptiveCardBuilder : RTObject
+ (RTObject<WUSIAdaptiveCard>*)createAdaptiveCardFromJson:(NSString *)value;
@end

#endif // __WUSAdaptiveCardBuilder_DEFINED__

// Windows.UI.Shell.TaskbarManager
#ifndef __WUSTaskbarManager_DEFINED__
#define __WUSTaskbarManager_DEFINED__

OBJCUWPWINDOWSUISHELLEXPORT
@interface WUSTaskbarManager : RTObject
+ (WUSTaskbarManager*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isPinningAllowed;
@property (readonly) BOOL isSupported;
- (void)isCurrentAppPinnedAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)isAppListEntryPinnedAsync:(WACAppListEntry*)appListEntry success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestPinCurrentAppAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestPinAppListEntryAsync:(WACAppListEntry*)appListEntry success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WUSTaskbarManager_DEFINED__

