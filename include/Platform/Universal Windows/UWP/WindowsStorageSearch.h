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

// WindowsStorageSearch.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_STORAGE_EXPORT
#define OBJCUWP_WINDOWS_STORAGE_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Storage.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSSContentIndexer, WSSValueAndLanguage, WSSContentIndexerQuery, WSSIndexableContent, WSSQueryOptions, WSSStorageFileQueryResult,
    WSSStorageFolderQueryResult, WSSStorageItemQueryResult, WSSSortEntryVector, WSSStorageLibraryContentChangedTriggerDetails;
@class WSSSortEntry;
@protocol WSSIContentIndexerStatics
, WSSIIndexableContent, WSSIContentIndexer, WSSIValueAndLanguage, WSSIContentIndexerQueryOperations, WSSIContentIndexerQuery,
    WSSIQueryOptions, WSSIQueryOptionsWithProviderFilter, WSSIQueryOptionsFactory, WSSIStorageQueryResultBase, WSSIStorageFileQueryResult,
    WSSIStorageFileQueryResult2, WSSIStorageFolderQueryResult, WSSIStorageItemQueryResult, WSSIStorageFolderQueryOperations,
    WSSIStorageLibraryContentChangedTriggerDetails;

// Windows.Storage.Search.DateStackOption
enum _WSSDateStackOption {
    WSSDateStackOptionNone = 0,
    WSSDateStackOptionYear = 1,
    WSSDateStackOptionMonth = 2,
};
typedef unsigned WSSDateStackOption;

// Windows.Storage.Search.IndexerOption
enum _WSSIndexerOption {
    WSSIndexerOptionUseIndexerWhenAvailable = 0,
    WSSIndexerOptionOnlyUseIndexer = 1,
    WSSIndexerOptionDoNotUseIndexer = 2,
};
typedef unsigned WSSIndexerOption;

// Windows.Storage.Search.FolderDepth
enum _WSSFolderDepth {
    WSSFolderDepthShallow = 0,
    WSSFolderDepthDeep = 1,
};
typedef unsigned WSSFolderDepth;

// Windows.Storage.Search.CommonFileQuery
enum _WSSCommonFileQuery {
    WSSCommonFileQueryDefaultQuery = 0,
    WSSCommonFileQueryOrderByName = 1,
    WSSCommonFileQueryOrderByTitle = 2,
    WSSCommonFileQueryOrderByMusicProperties = 3,
    WSSCommonFileQueryOrderBySearchRank = 4,
    WSSCommonFileQueryOrderByDate = 5,
};
typedef unsigned WSSCommonFileQuery;

// Windows.Storage.Search.CommonFolderQuery
enum _WSSCommonFolderQuery {
    WSSCommonFolderQueryDefaultQuery = 0,
    WSSCommonFolderQueryGroupByYear = 100,
    WSSCommonFolderQueryGroupByMonth = 101,
    WSSCommonFolderQueryGroupByArtist = 102,
    WSSCommonFolderQueryGroupByAlbum = 103,
    WSSCommonFolderQueryGroupByAlbumArtist = 104,
    WSSCommonFolderQueryGroupByComposer = 105,
    WSSCommonFolderQueryGroupByGenre = 106,
    WSSCommonFolderQueryGroupByPublishedYear = 107,
    WSSCommonFolderQueryGroupByRating = 108,
    WSSCommonFolderQueryGroupByTag = 109,
    WSSCommonFolderQueryGroupByAuthor = 110,
    WSSCommonFolderQueryGroupByType = 111,
};
typedef unsigned WSSCommonFolderQuery;

// Windows.Storage.Search.IndexedState
enum _WSSIndexedState {
    WSSIndexedStateUnknown = 0,
    WSSIndexedStateNotIndexed = 1,
    WSSIndexedStatePartiallyIndexed = 2,
    WSSIndexedStateFullyIndexed = 3,
};
typedef unsigned WSSIndexedState;

#include "WindowsStorage.h"
#include "WindowsStorageFileProperties.h"
#include "WindowsStorageStreams.h"
#include "WindowsDataText.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Storage.Search.SortEntry
OBJCUWP_WINDOWS_STORAGE_EXPORT
@interface WSSSortEntry : NSObject
+ (instancetype) new;
@property (retain) NSString* propertyName;
@property BOOL ascendingOrder;
@end

// Windows.Storage.Search.IIndexableContent
#ifndef __WSSIIndexableContent_DEFINED__
#define __WSSIIndexableContent_DEFINED__

@protocol WSSIIndexableContent
@property (retain) NSString* id;
@property (readonly) NSMutableDictionary* /* NSString *, RTObject* */ properties;
@property (retain) RTObject<WSSIRandomAccessStream>* stream;
@property (retain) NSString* streamContentType;
@end

OBJCUWP_WINDOWS_STORAGE_EXPORT
@interface WSSIIndexableContent : RTObject <WSSIIndexableContent>
@end

#endif // __WSSIIndexableContent_DEFINED__

// Windows.Storage.Search.IStorageQueryResultBase
#ifndef __WSSIStorageQueryResultBase_DEFINED__
#define __WSSIStorageQueryResultBase_DEFINED__

@protocol WSSIStorageQueryResultBase
@property (readonly) WSStorageFolder* folder;
- (EventRegistrationToken)addContentsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))del;
- (void)removeContentsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOptionsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))del;
- (void)removeOptionsChangedEvent:(EventRegistrationToken)tok;
- (void)getItemCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (void)findStartIndexAsync:(RTObject*)value success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (WSSQueryOptions*)getCurrentQueryOptions;
- (void)applyNewQueryOptions:(WSSQueryOptions*)newQueryOptions;
@end

OBJCUWP_WINDOWS_STORAGE_EXPORT
@interface WSSIStorageQueryResultBase : RTObject <WSSIStorageQueryResultBase>
@end

#endif // __WSSIStorageQueryResultBase_DEFINED__

// Windows.Storage.Search.IStorageFolderQueryOperations
#ifndef __WSSIStorageFolderQueryOperations_DEFINED__
#define __WSSIStorageFolderQueryOperations_DEFINED__

@protocol WSSIStorageFolderQueryOperations
- (void)getIndexedStateAsyncWithSuccess:(void (^)(WSSIndexedState))success failure:(void (^)(NSError*))failure;
- (WSSStorageFileQueryResult*)createFileQueryOverloadDefault;
- (WSSStorageFileQueryResult*)createFileQuery:(WSSCommonFileQuery)query;
- (WSSStorageFileQueryResult*)createFileQueryWithOptions:(WSSQueryOptions*)queryOptions;
- (WSSStorageFolderQueryResult*)createFolderQueryOverloadDefault;
- (WSSStorageFolderQueryResult*)createFolderQuery:(WSSCommonFolderQuery)query;
- (WSSStorageFolderQueryResult*)createFolderQueryWithOptions:(WSSQueryOptions*)queryOptions;
- (WSSStorageItemQueryResult*)createItemQuery;
- (WSSStorageItemQueryResult*)createItemQueryWithOptions:(WSSQueryOptions*)queryOptions;
- (void)getFilesAsync:(WSSCommonFileQuery)query
            startIndex:(unsigned int)startIndex
    maxItemsToRetrieve:(unsigned int)maxItemsToRetrieve
               success:(void (^)(NSArray* /* WSStorageFile* */))success
               failure:(void (^)(NSError*))failure;
- (void)getFilesAsyncOverloadDefaultStartAndCount:(WSSCommonFileQuery)query
                                          success:(void (^)(NSArray* /* WSStorageFile* */))success
                                          failure:(void (^)(NSError*))failure;
- (void)getFoldersAsync:(WSSCommonFolderQuery)query
             startIndex:(unsigned int)startIndex
     maxItemsToRetrieve:(unsigned int)maxItemsToRetrieve
                success:(void (^)(NSArray* /* WSStorageFolder* */))success
                failure:(void (^)(NSError*))failure;
- (void)getFoldersAsyncOverloadDefaultStartAndCount:(WSSCommonFolderQuery)query
                                            success:(void (^)(NSArray* /* WSStorageFolder* */))success
                                            failure:(void (^)(NSError*))failure;
- (void)getItemsAsync:(unsigned int)startIndex
    maxItemsToRetrieve:(unsigned int)maxItemsToRetrieve
               success:(void (^)(NSArray* /* RTObject<WSIStorageItem>* */))success
               failure:(void (^)(NSError*))failure;
- (BOOL)areQueryOptionsSupported:(WSSQueryOptions*)queryOptions;
- (BOOL)isCommonFolderQuerySupported:(WSSCommonFolderQuery)query;
- (BOOL)isCommonFileQuerySupported:(WSSCommonFileQuery)query;
@end

OBJCUWP_WINDOWS_STORAGE_EXPORT
@interface WSSIStorageFolderQueryOperations : RTObject <WSSIStorageFolderQueryOperations>
@end

#endif // __WSSIStorageFolderQueryOperations_DEFINED__

// Windows.Storage.Search.ContentIndexer
#ifndef __WSSContentIndexer_DEFINED__
#define __WSSContentIndexer_DEFINED__

OBJCUWP_WINDOWS_STORAGE_EXPORT
@interface WSSContentIndexer : RTObject
+ (WSSContentIndexer*)getIndexerWithName:(NSString*)indexName;
+ (WSSContentIndexer*)getIndexer;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) uint64_t revision;
- (RTObject<WFIAsyncAction>*)addAsync:(RTObject<WSSIIndexableContent>*)indexableContent;
- (RTObject<WFIAsyncAction>*)updateAsync:(RTObject<WSSIIndexableContent>*)indexableContent;
- (RTObject<WFIAsyncAction>*)deleteAsync:(NSString*)contentId;
- (RTObject<WFIAsyncAction>*)deleteMultipleAsync:(id<NSFastEnumeration> /* NSString * */)contentIds;
- (RTObject<WFIAsyncAction>*)deleteAllAsync;
- (void)retrievePropertiesAsync:(NSString*)contentId
           propertiesToRetrieve:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                        success:(void (^)(NSDictionary* /* NSString *, RTObject* */))success
                        failure:(void (^)(NSError*))failure;
- (WSSContentIndexerQuery*)createQueryWithSortOrderAndLanguage:(NSString*)searchFilter
                                          propertiesToRetrieve:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                                                     sortOrder:(id<NSFastEnumeration> /* WSSSortEntry* */)sortOrder
                                          searchFilterLanguage:(NSString*)searchFilterLanguage;
- (WSSContentIndexerQuery*)createQueryWithSortOrder:(NSString*)searchFilter
                               propertiesToRetrieve:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                                          sortOrder:(id<NSFastEnumeration> /* WSSSortEntry* */)sortOrder;
- (WSSContentIndexerQuery*)createQuery:(NSString*)searchFilter
                  propertiesToRetrieve:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve;
@end

#endif // __WSSContentIndexer_DEFINED__

// Windows.Storage.Search.ValueAndLanguage
#ifndef __WSSValueAndLanguage_DEFINED__
#define __WSSValueAndLanguage_DEFINED__

OBJCUWP_WINDOWS_STORAGE_EXPORT
@interface WSSValueAndLanguage : RTObject
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (retain) RTObject* value;
@property (retain) NSString* language;
@end

#endif // __WSSValueAndLanguage_DEFINED__

// Windows.Storage.Search.ContentIndexerQuery
#ifndef __WSSContentIndexerQuery_DEFINED__
#define __WSSContentIndexerQuery_DEFINED__

OBJCUWP_WINDOWS_STORAGE_EXPORT
@interface WSSContentIndexerQuery : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WSStorageFolder* queryFolder;
- (void)getCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (void)getPropertiesAsyncWithSuccess:(void (^)(NSArray* /* NSDictionary* < NSString *, RTObject* > */))success
                              failure:(void (^)(NSError*))failure;
- (void)getPropertiesRangeAsync:(unsigned int)startIndex
                       maxItems:(unsigned int)maxItems
                        success:(void (^)(NSArray* /* NSDictionary* < NSString *, RTObject* > */))success
                        failure:(void (^)(NSError*))failure;
- (void)getAsyncWithSuccess:(void (^)(NSArray* /* RTObject<WSSIIndexableContent>* */))success failure:(void (^)(NSError*))failure;
- (void)getRangeAsync:(unsigned int)startIndex
             maxItems:(unsigned int)maxItems
              success:(void (^)(NSArray* /* RTObject<WSSIIndexableContent>* */))success
              failure:(void (^)(NSError*))failure;
@end

#endif // __WSSContentIndexerQuery_DEFINED__

// Windows.Storage.Search.IndexableContent
#ifndef __WSSIndexableContent_DEFINED__
#define __WSSIndexableContent_DEFINED__

OBJCUWP_WINDOWS_STORAGE_EXPORT
@interface WSSIndexableContent : RTObject <WSSIIndexableContent>
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (retain) NSString* streamContentType;
@property (retain) RTObject<WSSIRandomAccessStream>* stream;
@property (retain) NSString* id;
@property (readonly) NSMutableDictionary* /* NSString *, RTObject* */ properties;
@end

#endif // __WSSIndexableContent_DEFINED__

// Windows.Storage.Search.QueryOptions
#ifndef __WSSQueryOptions_DEFINED__
#define __WSSQueryOptions_DEFINED__

OBJCUWP_WINDOWS_STORAGE_EXPORT
@interface WSSQueryOptions : RTObject
+ (WSSQueryOptions*)makeCommonFileQuery:(WSSCommonFileQuery)query
                         fileTypeFilter:(id<NSFastEnumeration> /* NSString * */)fileTypeFilter ACTIVATOR;
+ (WSSQueryOptions*)makeCommonFolderQuery:(WSSCommonFolderQuery)query ACTIVATOR;
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (retain) NSString* userSearchFilter;
@property (retain) NSString* language;
@property WSSIndexerOption indexerOption;
@property WSSFolderDepth folderDepth;
@property (retain) NSString* applicationSearchFilter;
@property (readonly) WSSDateStackOption dateStackOption;
@property (readonly) NSMutableArray* /* NSString * */ fileTypeFilter;
@property (readonly) NSString* groupPropertyName;
@property (readonly) NSMutableArray* /* WSSSortEntry* */ sortOrder;
@property (readonly) NSMutableArray* /* NSString * */ storageProviderIdFilter;
- (NSString*)saveToString;
- (void)loadFromString:(NSString*)value;
- (void)setThumbnailPrefetch:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize options:(WSFThumbnailOptions)options;
- (void)setPropertyPrefetch:(WSFPropertyPrefetchOptions)options
       propertiesToRetrieve:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve;
@end

#endif // __WSSQueryOptions_DEFINED__

// Windows.Storage.Search.StorageFileQueryResult
#ifndef __WSSStorageFileQueryResult_DEFINED__
#define __WSSStorageFileQueryResult_DEFINED__

OBJCUWP_WINDOWS_STORAGE_EXPORT
@interface WSSStorageFileQueryResult : RTObject <WSSIStorageQueryResultBase>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WSStorageFolder* folder;
- (EventRegistrationToken)addContentsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))del;
- (void)removeContentsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOptionsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))del;
- (void)removeOptionsChangedEvent:(EventRegistrationToken)tok;
- (void)getFilesAsync:(unsigned int)startIndex
     maxNumberOfItems:(unsigned int)maxNumberOfItems
              success:(void (^)(NSArray* /* WSStorageFile* */))success
              failure:(void (^)(NSError*))failure;
- (void)getFilesAsyncDefaultStartAndCountWithSuccess:(void (^)(NSArray* /* WSStorageFile* */))success failure:(void (^)(NSError*))failure;
- (void)getItemCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (void)findStartIndexAsync:(RTObject*)value success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (WSSQueryOptions*)getCurrentQueryOptions;
- (void)applyNewQueryOptions:(WSSQueryOptions*)newQueryOptions;
- (NSMutableDictionary* /* NSString *, NSArray* < WDTTextSegment* > */)getMatchingPropertiesWithRanges:(WSStorageFile*)file;
@end

#endif // __WSSStorageFileQueryResult_DEFINED__

// Windows.Storage.Search.StorageFolderQueryResult
#ifndef __WSSStorageFolderQueryResult_DEFINED__
#define __WSSStorageFolderQueryResult_DEFINED__

OBJCUWP_WINDOWS_STORAGE_EXPORT
@interface WSSStorageFolderQueryResult : RTObject <WSSIStorageQueryResultBase>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WSStorageFolder* folder;
- (EventRegistrationToken)addContentsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))del;
- (void)removeContentsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOptionsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))del;
- (void)removeOptionsChangedEvent:(EventRegistrationToken)tok;
- (void)getFoldersAsync:(unsigned int)startIndex
       maxNumberOfItems:(unsigned int)maxNumberOfItems
                success:(void (^)(NSArray* /* WSStorageFolder* */))success
                failure:(void (^)(NSError*))failure;
- (void)getFoldersAsyncDefaultStartAndCountWithSuccess:(void (^)(NSArray* /* WSStorageFolder* */))success
                                               failure:(void (^)(NSError*))failure;
- (void)getItemCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (void)findStartIndexAsync:(RTObject*)value success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (WSSQueryOptions*)getCurrentQueryOptions;
- (void)applyNewQueryOptions:(WSSQueryOptions*)newQueryOptions;
@end

#endif // __WSSStorageFolderQueryResult_DEFINED__

// Windows.Storage.Search.StorageItemQueryResult
#ifndef __WSSStorageItemQueryResult_DEFINED__
#define __WSSStorageItemQueryResult_DEFINED__

OBJCUWP_WINDOWS_STORAGE_EXPORT
@interface WSSStorageItemQueryResult : RTObject <WSSIStorageQueryResultBase>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WSStorageFolder* folder;
- (EventRegistrationToken)addContentsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))del;
- (void)removeContentsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOptionsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))del;
- (void)removeOptionsChangedEvent:(EventRegistrationToken)tok;
- (void)getItemsAsync:(unsigned int)startIndex
     maxNumberOfItems:(unsigned int)maxNumberOfItems
              success:(void (^)(NSArray* /* RTObject<WSIStorageItem>* */))success
              failure:(void (^)(NSError*))failure;
- (void)getItemsAsyncDefaultStartAndCountWithSuccess:(void (^)(NSArray* /* RTObject<WSIStorageItem>* */))success
                                             failure:(void (^)(NSError*))failure;
- (void)getItemCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (void)findStartIndexAsync:(RTObject*)value success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (WSSQueryOptions*)getCurrentQueryOptions;
- (void)applyNewQueryOptions:(WSSQueryOptions*)newQueryOptions;
@end

#endif // __WSSStorageItemQueryResult_DEFINED__

// Windows.Storage.Search.SortEntryVector
#ifndef __WSSSortEntryVector_DEFINED__
#define __WSSSortEntryVector_DEFINED__

OBJCUWP_WINDOWS_STORAGE_EXPORT
@interface WSSSortEntryVector : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

- (void)insertObject:(id)obj atIndex:(NSUInteger)idx;
- (void)removeObjectAtIndex:(NSUInteger)idx;
- (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(id)obj;
- (void)addObject:(id)obj;
- (void)removeLastObject;

@end

#endif // __WSSSortEntryVector_DEFINED__

// Windows.Storage.Search.StorageLibraryContentChangedTriggerDetails
#ifndef __WSSStorageLibraryContentChangedTriggerDetails_DEFINED__
#define __WSSStorageLibraryContentChangedTriggerDetails_DEFINED__

OBJCUWP_WINDOWS_STORAGE_EXPORT
@interface WSSStorageLibraryContentChangedTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WSStorageFolder* folder;
- (WSSStorageItemQueryResult*)createModifiedSinceQuery:(WFDateTime*)lastQueryTime;
@end

#endif // __WSSStorageLibraryContentChangedTriggerDetails_DEFINED__
