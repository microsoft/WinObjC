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

#include "interopBase.h"
@class WSSContentIndexer, WSSValueAndLanguage, WSSContentIndexerQuery, WSSIndexableContent, WSSQueryOptions, WSSStorageFileQueryResult,
    WSSStorageFolderQueryResult, WSSStorageItemQueryResult, WSSSortEntryVector;
@class WSSSortEntry;
@protocol WSSIContentIndexerStatics
, WSSIIndexableContent, WSSIContentIndexer, WSSIValueAndLanguage, WSSIContentIndexerQueryOperations, WSSIContentIndexerQuery,
    WSSIQueryOptions, WSSIQueryOptionsWithProviderFilter, WSSIQueryOptionsFactory, WSSIStorageQueryResultBase, WSSIStorageFileQueryResult,
    WSSIStorageFileQueryResult2, WSSIStorageFolderQueryResult, WSSIStorageItemQueryResult, WSSIStorageFolderQueryOperations;

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
#include "WindowsFoundationCollections.h"
#include "WindowsDataText.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Storage.Search.SortEntry
WINRT_EXPORT
@interface WSSSortEntry : NSObject
+ (instancetype) new;
@property (copy) NSString* propertyName;
@property BOOL ascendingOrder;
@end

// Windows.Storage.Search.IIndexableContent
#ifndef __WSSIIndexableContent_DEFINED__
#define __WSSIIndexableContent_DEFINED__

@protocol WSSIIndexableContent
@property (copy) NSString* id;
// Failed to generate property Properties (Can't marshal Windows.Foundation.Collections.IMap`2<String,System.Object>)
@property (copy) RTObject<WSSIRandomAccessStream>* stream;
@property (copy) NSString* streamContentType;
// Failed to generate member get_Properties (Can't marshal Windows.Foundation.Collections.IMap`2<String,System.Object>)
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
- (void)getItemCountAsyncWithSuccess:(void (^)(unsigned))success failure:(void (^)(NSError*))failure;
- (void)findStartIndexAsync:(RTObject*)value success:(void (^)(unsigned))success failure:(void (^)(NSError*))failure;
- (WSSQueryOptions*)getCurrentQueryOptions;
- (void)applyNewQueryOptions:(WSSQueryOptions*)newQueryOptions;
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
           startIndex:(unsigned)startIndex
   maxItemsToRetrieve:(unsigned)maxItemsToRetrieve
              success:(void (^)(id<NSFastEnumeration> /*WSStorageFile*/))success
              failure:(void (^)(NSError*))failure;
- (void)getFilesAsyncOverloadDefaultStartAndCount:(WSSCommonFileQuery)query
                                          success:(void (^)(id<NSFastEnumeration> /*WSStorageFile*/))success
                                          failure:(void (^)(NSError*))failure;
- (void)getFoldersAsync:(WSSCommonFolderQuery)query
             startIndex:(unsigned)startIndex
     maxItemsToRetrieve:(unsigned)maxItemsToRetrieve
                success:(void (^)(id<NSFastEnumeration> /*WSStorageFolder*/))success
                failure:(void (^)(NSError*))failure;
- (void)getFoldersAsyncOverloadDefaultStartAndCount:(WSSCommonFolderQuery)query
                                            success:(void (^)(id<NSFastEnumeration> /*WSStorageFolder*/))success
                                            failure:(void (^)(NSError*))failure;
- (void)getItemsAsync:(unsigned)startIndex
   maxItemsToRetrieve:(unsigned)maxItemsToRetrieve
              success:(void (^)(id<NSFastEnumeration> /*WSIStorageItem*/))success
              failure:(void (^)(NSError*))failure;
- (BOOL)areQueryOptionsSupported:(WSSQueryOptions*)queryOptions;
- (BOOL)isCommonFolderQuerySupported:(WSSCommonFolderQuery)query;
- (BOOL)isCommonFileQuerySupported:(WSSCommonFileQuery)query;
@end

#endif // __WSSIStorageFolderQueryOperations_DEFINED__

// Windows.Storage.Search.ContentIndexer
#ifndef __WSSContentIndexer_DEFINED__
#define __WSSContentIndexer_DEFINED__

WINRT_EXPORT
@interface WSSContentIndexer : RTObject
+ (WSSContentIndexer*)getIndexerWithName:(NSString*)indexName;
+ (WSSContentIndexer*)getIndexer;
@property (readonly) uint64_t revision;
- (RTObject<WFIAsyncAction>*)addAsync:(RTObject<WSSIIndexableContent>*)indexableContent;
- (RTObject<WFIAsyncAction>*)updateAsync:(RTObject<WSSIIndexableContent>*)indexableContent;
- (RTObject<WFIAsyncAction>*)deleteAsync:(NSString*)contentId;
- (RTObject<WFIAsyncAction>*)deleteMultipleAsync:(id<NSFastEnumeration> /*String*/)contentIds;
- (RTObject<WFIAsyncAction>*)deleteAllAsync;
- (void)retrievePropertiesAsync:(NSString*)contentId
           propertiesToRetrieve:(id<NSFastEnumeration> /*String*/)propertiesToRetrieve
                        success:(void (^)(NSDictionary* /*String, SObject*/))success
                        failure:(void (^)(NSError*))failure;
- (WSSContentIndexerQuery*)createQueryWithSortOrderAndLanguage:(NSString*)searchFilter
                                          propertiesToRetrieve:(id<NSFastEnumeration> /*String*/)propertiesToRetrieve
                                                     sortOrder:(id<NSFastEnumeration> /*WSSSortEntry*/)sortOrder
                                          searchFilterLanguage:(NSString*)searchFilterLanguage;
- (WSSContentIndexerQuery*)createQueryWithSortOrder:(NSString*)searchFilter
                               propertiesToRetrieve:(id<NSFastEnumeration> /*String*/)propertiesToRetrieve
                                          sortOrder:(id<NSFastEnumeration> /*WSSSortEntry*/)sortOrder;
- (WSSContentIndexerQuery*)createQuery:(NSString*)searchFilter propertiesToRetrieve:(id<NSFastEnumeration> /*String*/)propertiesToRetrieve;
@end

#endif // __WSSContentIndexer_DEFINED__

// Windows.Storage.Search.ValueAndLanguage
#ifndef __WSSValueAndLanguage_DEFINED__
#define __WSSValueAndLanguage_DEFINED__

WINRT_EXPORT
@interface WSSValueAndLanguage : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) RTObject* value;
@property (copy) NSString* language;
@end

#endif // __WSSValueAndLanguage_DEFINED__

// Windows.Storage.Search.ContentIndexerQuery
#ifndef __WSSContentIndexerQuery_DEFINED__
#define __WSSContentIndexerQuery_DEFINED__

WINRT_EXPORT
@interface WSSContentIndexerQuery : RTObject
@property (readonly) WSStorageFolder* queryFolder;
- (void)getCountAsyncWithSuccess:(void (^)(unsigned))success failure:(void (^)(NSError*))failure;
// Failed to generate member GetPropertiesAsync (Cannot marshal contained object of unknown type
// Windows.Foundation.Collections.IMapView`2<String,System.Object>)
// Failed to generate member GetPropertiesAsync (Cannot marshal contained object of unknown type
// Windows.Foundation.Collections.IMapView`2<String,System.Object>)
- (void)getAsyncWithSuccess:(void (^)(id<NSFastEnumeration> /*WSSIIndexableContent*/))success failure:(void (^)(NSError*))failure;
- (void)getRangeAsync:(unsigned)startIndex
             maxItems:(unsigned)maxItems
              success:(void (^)(id<NSFastEnumeration> /*WSSIIndexableContent*/))success
              failure:(void (^)(NSError*))failure;
@end

#endif // __WSSContentIndexerQuery_DEFINED__

// Windows.Storage.Search.IndexableContent
#ifndef __WSSIndexableContent_DEFINED__
#define __WSSIndexableContent_DEFINED__

WINRT_EXPORT
@interface WSSIndexableContent : RTObject <WSSIIndexableContent>
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* streamContentType;
@property (copy) RTObject<WSSIRandomAccessStream>* stream;
@property (copy) NSString* id;
// Failed to generate property Properties (Can't marshal Windows.Foundation.Collections.IMap`2<String,System.Object>)
// Failed to generate member get_Properties (Can't marshal Windows.Foundation.Collections.IMap`2<String,System.Object>)
@end

#endif // __WSSIndexableContent_DEFINED__

// Windows.Storage.Search.QueryOptions
#ifndef __WSSQueryOptions_DEFINED__
#define __WSSQueryOptions_DEFINED__

WINRT_EXPORT
@interface WSSQueryOptions : RTObject
+ (WSSQueryOptions*)createCommonFileQuery:(WSSCommonFileQuery)query
                           fileTypeFilter:(id<NSFastEnumeration> /*String*/)fileTypeFilter ACTIVATOR;
+ (WSSQueryOptions*)createCommonFolderQuery:(WSSCommonFolderQuery)query ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (readonly) id<NSFastEnumeration> /*String*/ storageProviderIdFilter;
@property (copy) NSString* userSearchFilter;
@property (copy) NSString* language;
@property WSSIndexerOption indexerOption;
@property WSSFolderDepth folderDepth;
@property (copy) NSString* applicationSearchFilter;
@property (readonly) WSSDateStackOption dateStackOption;
@property (readonly) id<NSFastEnumeration> /*String*/ fileTypeFilter;
@property (readonly) NSString* groupPropertyName;
@property (readonly) id<NSFastEnumeration> /*WSSSortEntry*/ sortOrder;
- (NSString*)saveToString;
- (void)loadFromString:(NSString*)value;
- (void)setThumbnailPrefetch:(WSFThumbnailMode)mode requestedSize:(unsigned)requestedSize options:(WSFThumbnailOptions)options;
- (void)setPropertyPrefetch:(WSFPropertyPrefetchOptions)options propertiesToRetrieve:(id<NSFastEnumeration> /*String*/)propertiesToRetrieve;
@end

#endif // __WSSQueryOptions_DEFINED__

// Windows.Storage.Search.StorageFileQueryResult
#ifndef __WSSStorageFileQueryResult_DEFINED__
#define __WSSStorageFileQueryResult_DEFINED__

WINRT_EXPORT
@interface WSSStorageFileQueryResult : RTObject <WSSIStorageQueryResultBase>
@property (readonly) WSStorageFolder* folder;
- (EventRegistrationToken)addContentsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))del;
- (void)removeContentsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOptionsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))del;
- (void)removeOptionsChangedEvent:(EventRegistrationToken)tok;
- (void)getFilesAsync:(unsigned)startIndex
     maxNumberOfItems:(unsigned)maxNumberOfItems
              success:(void (^)(id<NSFastEnumeration> /*WSStorageFile*/))success
              failure:(void (^)(NSError*))failure;
- (void)getFilesAsyncDefaultStartAndCountWithSuccess:(void (^)(id<NSFastEnumeration> /*WSStorageFile*/))success
                                             failure:(void (^)(NSError*))failure;
- (void)getItemCountAsyncWithSuccess:(void (^)(unsigned))success failure:(void (^)(NSError*))failure;
- (void)findStartIndexAsync:(RTObject*)value success:(void (^)(unsigned))success failure:(void (^)(NSError*))failure;
- (WSSQueryOptions*)getCurrentQueryOptions;
- (void)applyNewQueryOptions:(WSSQueryOptions*)newQueryOptions;
// Failed to generate member GetMatchingPropertiesWithRanges (Can't marshal
// Windows.Foundation.Collections.IMap`2<String,Windows.Foundation.Collections.IVectorView`1<Windows.Data.Text.TextSegment>>)
@end

#endif // __WSSStorageFileQueryResult_DEFINED__

// Windows.Storage.Search.StorageFolderQueryResult
#ifndef __WSSStorageFolderQueryResult_DEFINED__
#define __WSSStorageFolderQueryResult_DEFINED__

WINRT_EXPORT
@interface WSSStorageFolderQueryResult : RTObject <WSSIStorageQueryResultBase>
@property (readonly) WSStorageFolder* folder;
- (EventRegistrationToken)addContentsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))del;
- (void)removeContentsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOptionsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))del;
- (void)removeOptionsChangedEvent:(EventRegistrationToken)tok;
- (void)getFoldersAsync:(unsigned)startIndex
       maxNumberOfItems:(unsigned)maxNumberOfItems
                success:(void (^)(id<NSFastEnumeration> /*WSStorageFolder*/))success
                failure:(void (^)(NSError*))failure;
- (void)getFoldersAsyncDefaultStartAndCountWithSuccess:(void (^)(id<NSFastEnumeration> /*WSStorageFolder*/))success
                                               failure:(void (^)(NSError*))failure;
- (void)getItemCountAsyncWithSuccess:(void (^)(unsigned))success failure:(void (^)(NSError*))failure;
- (void)findStartIndexAsync:(RTObject*)value success:(void (^)(unsigned))success failure:(void (^)(NSError*))failure;
- (WSSQueryOptions*)getCurrentQueryOptions;
- (void)applyNewQueryOptions:(WSSQueryOptions*)newQueryOptions;
@end

#endif // __WSSStorageFolderQueryResult_DEFINED__

// Windows.Storage.Search.StorageItemQueryResult
#ifndef __WSSStorageItemQueryResult_DEFINED__
#define __WSSStorageItemQueryResult_DEFINED__

WINRT_EXPORT
@interface WSSStorageItemQueryResult : RTObject <WSSIStorageQueryResultBase>
@property (readonly) WSStorageFolder* folder;
- (EventRegistrationToken)addContentsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))del;
- (void)removeContentsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOptionsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))del;
- (void)removeOptionsChangedEvent:(EventRegistrationToken)tok;
- (void)getItemsAsync:(unsigned)startIndex
     maxNumberOfItems:(unsigned)maxNumberOfItems
              success:(void (^)(id<NSFastEnumeration> /*WSIStorageItem*/))success
              failure:(void (^)(NSError*))failure;
- (void)getItemsAsyncDefaultStartAndCountWithSuccess:(void (^)(id<NSFastEnumeration> /*WSIStorageItem*/))success
                                             failure:(void (^)(NSError*))failure;
- (void)getItemCountAsyncWithSuccess:(void (^)(unsigned))success failure:(void (^)(NSError*))failure;
- (void)findStartIndexAsync:(RTObject*)value success:(void (^)(unsigned))success failure:(void (^)(NSError*))failure;
- (WSSQueryOptions*)getCurrentQueryOptions;
- (void)applyNewQueryOptions:(WSSQueryOptions*)newQueryOptions;
@end

#endif // __WSSStorageItemQueryResult_DEFINED__

// Windows.Storage.Search.SortEntryVector
#ifndef __WSSSortEntryVector_DEFINED__
#define __WSSSortEntryVector_DEFINED__

WINRT_EXPORT
@interface WSSSortEntryVector : RTObject
@property (readonly) unsigned size;
@end

#endif // __WSSSortEntryVector_DEFINED__
