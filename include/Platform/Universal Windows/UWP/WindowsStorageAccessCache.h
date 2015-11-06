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

// WindowsStorageAccessCache.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSAAccessListEntryView, WSAStorageItemMostRecentlyUsedList, WSAItemRemovedEventArgs, WSAStorageItemAccessList,
    WSAStorageApplicationPermissions;
@class WSAAccessListEntry;
@protocol WSAIItemRemovedEventArgs
, WSAIStorageItemAccessList, WSAIStorageItemMostRecentlyUsedList, WSAIStorageItemMostRecentlyUsedList2,
    WSAIStorageApplicationPermissionsStatics;

// Windows.Storage.AccessCache.AccessCacheOptions
enum _WSAAccessCacheOptions {
    WSAAccessCacheOptionsNone = 0,
    WSAAccessCacheOptionsDisallowUserInput = 1,
    WSAAccessCacheOptionsFastLocationsOnly = 2,
    WSAAccessCacheOptionsUseReadOnlyCachedCopy = 4,
    WSAAccessCacheOptionsSuppressAccessTimeUpdate = 8,
};
typedef unsigned WSAAccessCacheOptions;

// Windows.Storage.AccessCache.RecentStorageItemVisibility
enum _WSARecentStorageItemVisibility {
    WSARecentStorageItemVisibilityAppOnly = 0,
    WSARecentStorageItemVisibilityAppAndSystem = 1,
};
typedef unsigned WSARecentStorageItemVisibility;

#include "WindowsStorage.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Storage.AccessCache.AccessListEntry
WINRT_EXPORT
@interface WSAAccessListEntry : NSObject
+ (instancetype) new;
@property (copy) NSString* token;
@property (copy) NSString* metadata;
@end

// Windows.Storage.AccessCache.IStorageItemAccessList
#ifndef __WSAIStorageItemAccessList_DEFINED__
#define __WSAIStorageItemAccessList_DEFINED__

@protocol WSAIStorageItemAccessList
@property (readonly) WSAAccessListEntryView* entries;
@property (readonly) unsigned int maximumItemsAllowed;
- (NSString*)addOverloadDefaultMetadata:(RTObject<WSIStorageItem>*)file;
- (NSString*)add:(RTObject<WSIStorageItem>*)file metadata:(NSString*)metadata;
- (void)addOrReplaceOverloadDefaultMetadata:(NSString*)token file:(RTObject<WSIStorageItem>*)file;
- (void)addOrReplace:(NSString*)token file:(RTObject<WSIStorageItem>*)file metadata:(NSString*)metadata;
- (void)getItemAsync:(NSString*)token success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure;
- (void)getFileAsync:(NSString*)token success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)getFolderAsync:(NSString*)token success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (void)getItemWithOptionsAsync:(NSString*)token
                        options:(WSAAccessCacheOptions)options
                        success:(void (^)(RTObject<WSIStorageItem>*))success
                        failure:(void (^)(NSError*))failure;
- (void)getFileWithOptionsAsync:(NSString*)token
                        options:(WSAAccessCacheOptions)options
                        success:(void (^)(WSStorageFile*))success
                        failure:(void (^)(NSError*))failure;
- (void)getFolderWithOptionsAsync:(NSString*)token
                          options:(WSAAccessCacheOptions)options
                          success:(void (^)(WSStorageFolder*))success
                          failure:(void (^)(NSError*))failure;
- (void)remove:(NSString*)token;
- (BOOL)containsItem:(NSString*)token;
- (void)clear;
- (BOOL)checkAccess:(RTObject<WSIStorageItem>*)file;
@end

#endif // __WSAIStorageItemAccessList_DEFINED__

// Windows.Storage.AccessCache.AccessListEntryView
#ifndef __WSAAccessListEntryView_DEFINED__
#define __WSAAccessListEntryView_DEFINED__

WINRT_EXPORT
@interface WSAAccessListEntryView : RTObject
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

@end

#endif // __WSAAccessListEntryView_DEFINED__

// Windows.Storage.AccessCache.StorageItemMostRecentlyUsedList
#ifndef __WSAStorageItemMostRecentlyUsedList_DEFINED__
#define __WSAStorageItemMostRecentlyUsedList_DEFINED__

WINRT_EXPORT
@interface WSAStorageItemMostRecentlyUsedList : RTObject <WSAIStorageItemAccessList>
@property (readonly) WSAAccessListEntryView* entries;
@property (readonly) unsigned int maximumItemsAllowed;
- (EventRegistrationToken)addItemRemovedEvent:(void (^)(WSAStorageItemMostRecentlyUsedList*, WSAItemRemovedEventArgs*))del;
- (void)removeItemRemovedEvent:(EventRegistrationToken)tok;
- (NSString*)addOverloadDefaultMetadata:(RTObject<WSIStorageItem>*)file;
- (NSString*)add:(RTObject<WSIStorageItem>*)file metadata:(NSString*)metadata;
- (void)addOrReplaceOverloadDefaultMetadata:(NSString*)token file:(RTObject<WSIStorageItem>*)file;
- (void)addOrReplace:(NSString*)token file:(RTObject<WSIStorageItem>*)file metadata:(NSString*)metadata;
- (void)getItemAsync:(NSString*)token success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure;
- (void)getFileAsync:(NSString*)token success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)getFolderAsync:(NSString*)token success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (void)getItemWithOptionsAsync:(NSString*)token
                        options:(WSAAccessCacheOptions)options
                        success:(void (^)(RTObject<WSIStorageItem>*))success
                        failure:(void (^)(NSError*))failure;
- (void)getFileWithOptionsAsync:(NSString*)token
                        options:(WSAAccessCacheOptions)options
                        success:(void (^)(WSStorageFile*))success
                        failure:(void (^)(NSError*))failure;
- (void)getFolderWithOptionsAsync:(NSString*)token
                          options:(WSAAccessCacheOptions)options
                          success:(void (^)(WSStorageFolder*))success
                          failure:(void (^)(NSError*))failure;
- (void)remove:(NSString*)token;
- (BOOL)containsItem:(NSString*)token;
- (void)clear;
- (BOOL)checkAccess:(RTObject<WSIStorageItem>*)file;
- (NSString*)addWithMetadataAndVisibility:(RTObject<WSIStorageItem>*)file
                                 metadata:(NSString*)metadata
                               visibility:(WSARecentStorageItemVisibility)visibility;
- (void)addOrReplaceWithMetadataAndVisibility:(NSString*)token
                                         file:(RTObject<WSIStorageItem>*)file
                                     metadata:(NSString*)metadata
                                   visibility:(WSARecentStorageItemVisibility)visibility;
@end

#endif // __WSAStorageItemMostRecentlyUsedList_DEFINED__

// Windows.Storage.AccessCache.ItemRemovedEventArgs
#ifndef __WSAItemRemovedEventArgs_DEFINED__
#define __WSAItemRemovedEventArgs_DEFINED__

WINRT_EXPORT
@interface WSAItemRemovedEventArgs : RTObject
@property (readonly) WSAAccessListEntry* removedEntry;
@end

#endif // __WSAItemRemovedEventArgs_DEFINED__

// Windows.Storage.AccessCache.StorageItemAccessList
#ifndef __WSAStorageItemAccessList_DEFINED__
#define __WSAStorageItemAccessList_DEFINED__

WINRT_EXPORT
@interface WSAStorageItemAccessList : RTObject <WSAIStorageItemAccessList>
@property (readonly) WSAAccessListEntryView* entries;
@property (readonly) unsigned int maximumItemsAllowed;
- (NSString*)addOverloadDefaultMetadata:(RTObject<WSIStorageItem>*)file;
- (NSString*)add:(RTObject<WSIStorageItem>*)file metadata:(NSString*)metadata;
- (void)addOrReplaceOverloadDefaultMetadata:(NSString*)token file:(RTObject<WSIStorageItem>*)file;
- (void)addOrReplace:(NSString*)token file:(RTObject<WSIStorageItem>*)file metadata:(NSString*)metadata;
- (void)getItemAsync:(NSString*)token success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure;
- (void)getFileAsync:(NSString*)token success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)getFolderAsync:(NSString*)token success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (void)getItemWithOptionsAsync:(NSString*)token
                        options:(WSAAccessCacheOptions)options
                        success:(void (^)(RTObject<WSIStorageItem>*))success
                        failure:(void (^)(NSError*))failure;
- (void)getFileWithOptionsAsync:(NSString*)token
                        options:(WSAAccessCacheOptions)options
                        success:(void (^)(WSStorageFile*))success
                        failure:(void (^)(NSError*))failure;
- (void)getFolderWithOptionsAsync:(NSString*)token
                          options:(WSAAccessCacheOptions)options
                          success:(void (^)(WSStorageFolder*))success
                          failure:(void (^)(NSError*))failure;
- (void)remove:(NSString*)token;
- (BOOL)containsItem:(NSString*)token;
- (void)clear;
- (BOOL)checkAccess:(RTObject<WSIStorageItem>*)file;
@end

#endif // __WSAStorageItemAccessList_DEFINED__

// Windows.Storage.AccessCache.StorageApplicationPermissions
#ifndef __WSAStorageApplicationPermissions_DEFINED__
#define __WSAStorageApplicationPermissions_DEFINED__

WINRT_EXPORT
@interface WSAStorageApplicationPermissions : RTObject
+ (WSAStorageItemAccessList*)futureAccessList;
+ (WSAStorageItemMostRecentlyUsedList*)mostRecentlyUsedList;
@end

#endif // __WSAStorageApplicationPermissions_DEFINED__
