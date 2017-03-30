// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Storage::Search {

struct SortEntry;

}

namespace Windows::Storage::Search {

struct SortEntry;

}

namespace ABI::Windows::Storage::Search {

struct IContentIndexer;
struct IContentIndexerQuery;
struct IContentIndexerQueryOperations;
struct IContentIndexerStatics;
struct IIndexableContent;
struct IQueryOptions;
struct IQueryOptionsFactory;
struct IQueryOptionsWithProviderFilter;
struct IStorageFileQueryResult;
struct IStorageFileQueryResult2;
struct IStorageFolderQueryOperations;
struct IStorageFolderQueryResult;
struct IStorageItemQueryResult;
struct IStorageLibraryContentChangedTriggerDetails;
struct IStorageQueryResultBase;
struct IValueAndLanguage;
struct ContentIndexer;
struct ContentIndexerQuery;
struct IndexableContent;
struct QueryOptions;
struct SortEntryVector;
struct StorageFileQueryResult;
struct StorageFolderQueryResult;
struct StorageItemQueryResult;
struct StorageLibraryContentChangedTriggerDetails;
struct ValueAndLanguage;

}

namespace Windows::Storage::Search {

struct IContentIndexer;
struct IContentIndexerQuery;
struct IContentIndexerQueryOperations;
struct IContentIndexerStatics;
struct IIndexableContent;
struct IQueryOptions;
struct IQueryOptionsFactory;
struct IQueryOptionsWithProviderFilter;
struct IStorageFileQueryResult;
struct IStorageFileQueryResult2;
struct IStorageFolderQueryOperations;
struct IStorageFolderQueryResult;
struct IStorageItemQueryResult;
struct IStorageLibraryContentChangedTriggerDetails;
struct IStorageQueryResultBase;
struct IValueAndLanguage;
struct ContentIndexer;
struct ContentIndexerQuery;
struct IndexableContent;
struct QueryOptions;
struct SortEntryVector;
struct StorageFileQueryResult;
struct StorageFolderQueryResult;
struct StorageItemQueryResult;
struct StorageLibraryContentChangedTriggerDetails;
struct ValueAndLanguage;

}

namespace Windows::Storage::Search {

template <typename T> struct impl_IContentIndexer;
template <typename T> struct impl_IContentIndexerQuery;
template <typename T> struct impl_IContentIndexerQueryOperations;
template <typename T> struct impl_IContentIndexerStatics;
template <typename T> struct impl_IIndexableContent;
template <typename T> struct impl_IQueryOptions;
template <typename T> struct impl_IQueryOptionsFactory;
template <typename T> struct impl_IQueryOptionsWithProviderFilter;
template <typename T> struct impl_IStorageFileQueryResult;
template <typename T> struct impl_IStorageFileQueryResult2;
template <typename T> struct impl_IStorageFolderQueryOperations;
template <typename T> struct impl_IStorageFolderQueryResult;
template <typename T> struct impl_IStorageItemQueryResult;
template <typename T> struct impl_IStorageLibraryContentChangedTriggerDetails;
template <typename T> struct impl_IStorageQueryResultBase;
template <typename T> struct impl_IValueAndLanguage;

}

namespace Windows::Storage::Search {

enum class CommonFileQuery
{
    DefaultQuery = 0,
    OrderByName = 1,
    OrderByTitle = 2,
    OrderByMusicProperties = 3,
    OrderBySearchRank = 4,
    OrderByDate = 5,
};

enum class CommonFolderQuery
{
    DefaultQuery = 0,
    GroupByYear = 100,
    GroupByMonth = 101,
    GroupByArtist = 102,
    GroupByAlbum = 103,
    GroupByAlbumArtist = 104,
    GroupByComposer = 105,
    GroupByGenre = 106,
    GroupByPublishedYear = 107,
    GroupByRating = 108,
    GroupByTag = 109,
    GroupByAuthor = 110,
    GroupByType = 111,
};

enum class DateStackOption
{
    None = 0,
    Year = 1,
    Month = 2,
};

enum class FolderDepth
{
    Shallow = 0,
    Deep = 1,
};

enum class IndexedState
{
    Unknown = 0,
    NotIndexed = 1,
    PartiallyIndexed = 2,
    FullyIndexed = 3,
};

enum class IndexerOption
{
    UseIndexerWhenAvailable = 0,
    OnlyUseIndexer = 1,
    DoNotUseIndexer = 2,
};

}

}
