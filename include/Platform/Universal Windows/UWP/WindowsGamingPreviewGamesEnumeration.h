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

// WindowsGamingPreviewGamesEnumeration.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGAMINGPREVIEWGAMESENUMERATIONEXPORT
#define OBJCUWPWINDOWSGAMINGPREVIEWGAMESENUMERATIONEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGamingPreviewGamesEnumeration.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGPGGameModeConfiguration, WGPGGameListEntry, WGPGGameModeUserConfiguration, WGPGGameList;
@protocol WGPGIGameListEntry, WGPGIGameModeConfiguration, WGPGIGameListEntry2, WGPGIGameModeUserConfiguration, WGPGIGameModeUserConfigurationStatics, WGPGIGameListStatics, WGPGIGameListStatics2;

// Windows.Gaming.Preview.GamesEnumeration.GameListCategory
enum _WGPGGameListCategory {
    WGPGGameListCategoryCandidate = 0,
    WGPGGameListCategoryConfirmedBySystem = 1,
    WGPGGameListCategoryConfirmedByUser = 2,
};
typedef unsigned WGPGGameListCategory;

// Windows.Gaming.Preview.GamesEnumeration.GameListEntryLaunchableState
enum _WGPGGameListEntryLaunchableState {
    WGPGGameListEntryLaunchableStateNotLaunchable = 0,
    WGPGGameListEntryLaunchableStateByLastRunningFullPath = 1,
    WGPGGameListEntryLaunchableStateByUserProvidedPath = 2,
    WGPGGameListEntryLaunchableStateByTile = 3,
};
typedef unsigned WGPGGameListEntryLaunchableState;

#include "WindowsApplicationModel.h"
#include "WindowsFoundation.h"
#include "WindowsStorage.h"
// Windows.Gaming.Preview.GamesEnumeration.GameListChangedEventHandler
#ifndef __WGPGGameListChangedEventHandler__DEFINED
#define __WGPGGameListChangedEventHandler__DEFINED
typedef void(^WGPGGameListChangedEventHandler)(WGPGGameListEntry* game);
#endif // __WGPGGameListChangedEventHandler__DEFINED

// Windows.Gaming.Preview.GamesEnumeration.GameListRemovedEventHandler
#ifndef __WGPGGameListRemovedEventHandler__DEFINED
#define __WGPGGameListRemovedEventHandler__DEFINED
typedef void(^WGPGGameListRemovedEventHandler)(NSString * identifier);
#endif // __WGPGGameListRemovedEventHandler__DEFINED


#import <Foundation/Foundation.h>

// Windows.Gaming.Preview.GamesEnumeration.GameListChangedEventHandler
#ifndef __WGPGGameListChangedEventHandler__DEFINED
#define __WGPGGameListChangedEventHandler__DEFINED
typedef void(^WGPGGameListChangedEventHandler)(WGPGGameListEntry* game);
#endif // __WGPGGameListChangedEventHandler__DEFINED

// Windows.Gaming.Preview.GamesEnumeration.GameListRemovedEventHandler
#ifndef __WGPGGameListRemovedEventHandler__DEFINED
#define __WGPGGameListRemovedEventHandler__DEFINED
typedef void(^WGPGGameListRemovedEventHandler)(NSString * identifier);
#endif // __WGPGGameListRemovedEventHandler__DEFINED

// Windows.Gaming.Preview.GamesEnumeration.IGameListEntry
#ifndef __WGPGIGameListEntry_DEFINED__
#define __WGPGIGameListEntry_DEFINED__

@protocol WGPGIGameListEntry
@property (readonly) WGPGGameListCategory category;
@property (readonly) WAAppDisplayInfo* displayInfo;
@property (readonly) NSDictionary* /* NSString *, RTObject* */ properties;
- (void)launchAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)setCategoryAsync:(WGPGGameListCategory)value;
@end

OBJCUWPWINDOWSGAMINGPREVIEWGAMESENUMERATIONEXPORT
@interface WGPGIGameListEntry : RTObject <WGPGIGameListEntry>
@end

#endif // __WGPGIGameListEntry_DEFINED__

// Windows.Gaming.Preview.GamesEnumeration.GameModeConfiguration
#ifndef __WGPGGameModeConfiguration_DEFINED__
#define __WGPGGameModeConfiguration_DEFINED__

OBJCUWPWINDOWSGAMINGPREVIEWGAMESENUMERATIONEXPORT
@interface WGPGGameModeConfiguration : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* int */ percentGpuTimeAllocatedToGame;
@property (retain) id /* int */ percentGpuMemoryAllocatedToSystemCompositor;
@property (retain) id /* int */ percentGpuMemoryAllocatedToGame;
@property (retain) id /* int */ maxCpuCount;
@property BOOL isEnabled;
@property (retain) id /* int */ cpuExclusivityMaskLow;
@property (retain) id /* int */ cpuExclusivityMaskHigh;
@property BOOL affinitizeToExclusiveCpus;
@property (readonly) NSMutableArray* /* NSString * */ relatedProcessNames;
- (RTObject<WFIAsyncAction>*)saveAsync;
@end

#endif // __WGPGGameModeConfiguration_DEFINED__

// Windows.Gaming.Preview.GamesEnumeration.GameListEntry
#ifndef __WGPGGameListEntry_DEFINED__
#define __WGPGGameListEntry_DEFINED__

OBJCUWPWINDOWSGAMINGPREVIEWGAMESENUMERATIONEXPORT
@interface WGPGGameListEntry : RTObject <WGPGIGameListEntry>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPGGameListCategory category;
@property (readonly) WAAppDisplayInfo* displayInfo;
@property (readonly) NSDictionary* /* NSString *, RTObject* */ properties;
@property (readonly) WGPGGameModeConfiguration* gameModeConfiguration;
@property (readonly) NSString * launchParameters;
@property (readonly) WGPGGameListEntryLaunchableState launchableState;
@property (readonly) RTObject<WSIStorageFile>* launcherExecutable;
@property (readonly) NSString * titleId;
- (void)launchAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)setCategoryAsync:(WGPGGameListCategory)value;
- (RTObject<WFIAsyncAction>*)setLauncherExecutableFileAsync:(RTObject<WSIStorageFile>*)executableFile;
- (RTObject<WFIAsyncAction>*)setLauncherExecutableFileWithParamsAsync:(RTObject<WSIStorageFile>*)executableFile launchParams:(NSString *)launchParams;
- (RTObject<WFIAsyncAction>*)setTitleIdAsync:(NSString *)id;
@end

#endif // __WGPGGameListEntry_DEFINED__

// Windows.Gaming.Preview.GamesEnumeration.GameModeUserConfiguration
#ifndef __WGPGGameModeUserConfiguration_DEFINED__
#define __WGPGGameModeUserConfiguration_DEFINED__

OBJCUWPWINDOWSGAMINGPREVIEWGAMESENUMERATIONEXPORT
@interface WGPGGameModeUserConfiguration : RTObject
+ (WGPGGameModeUserConfiguration*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray* /* NSString * */ gamingRelatedProcessNames;
- (RTObject<WFIAsyncAction>*)saveAsync;
@end

#endif // __WGPGGameModeUserConfiguration_DEFINED__

// Windows.Gaming.Preview.GamesEnumeration.GameList
#ifndef __WGPGGameList_DEFINED__
#define __WGPGGameList_DEFINED__

OBJCUWPWINDOWSGAMINGPREVIEWGAMESENUMERATIONEXPORT
@interface WGPGGameList : RTObject
+ (void)mergeEntriesAsync:(WGPGGameListEntry*)left right:(WGPGGameListEntry*)right success:(void (^)(WGPGGameListEntry*))success failure:(void (^)(NSError*))failure;
+ (void)unmergeEntryAsync:(WGPGGameListEntry*)mergedEntry success:(void (^)(NSArray* /* WGPGGameListEntry* */))success failure:(void (^)(NSError*))failure;
+ (void)findAllAsyncWithSuccess:(void (^)(NSArray* /* WGPGGameListEntry* */))success failure:(void (^)(NSError*))failure;
+ (void)findAllAsyncPackageFamilyName:(NSString *)packageFamilyName success:(void (^)(NSArray* /* WGPGGameListEntry* */))success failure:(void (^)(NSError*))failure;
+ (EventRegistrationToken)addGameAddedEvent:(WGPGGameListChangedEventHandler)del;
+ (void)removeGameAddedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addGameRemovedEvent:(WGPGGameListRemovedEventHandler)del;
+ (void)removeGameRemovedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addGameUpdatedEvent:(WGPGGameListChangedEventHandler)del;
+ (void)removeGameUpdatedEvent:(EventRegistrationToken)tok;
@end

#endif // __WGPGGameList_DEFINED__

