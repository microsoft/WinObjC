// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.Search.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Storage::Search {

struct WINRT_EBO ContentIndexer :
    Windows::Storage::Search::IContentIndexer,
    impl::require<ContentIndexer, Windows::Storage::Search::IContentIndexerQueryOperations>
{
    ContentIndexer(std::nullptr_t) noexcept {}
    static Windows::Storage::Search::ContentIndexer GetIndexer(hstring_view indexName);
    static Windows::Storage::Search::ContentIndexer GetIndexer();
};

struct WINRT_EBO ContentIndexerQuery :
    Windows::Storage::Search::IContentIndexerQuery
{
    ContentIndexerQuery(std::nullptr_t) noexcept {}
};

struct WINRT_EBO IndexableContent :
    Windows::Storage::Search::IIndexableContent
{
    IndexableContent(std::nullptr_t) noexcept {}
    IndexableContent();
};

struct WINRT_EBO QueryOptions :
    Windows::Storage::Search::IQueryOptions,
    impl::require<QueryOptions, Windows::Storage::Search::IQueryOptionsWithProviderFilter>
{
    QueryOptions(std::nullptr_t) noexcept {}
    QueryOptions();
    QueryOptions(Windows::Storage::Search::CommonFileQuery query, iterable<hstring> fileTypeFilter);
    QueryOptions(Windows::Storage::Search::CommonFolderQuery query);
};

struct WINRT_EBO SortEntryVector :
    Windows::Foundation::Collections::IVector<Windows::Storage::Search::SortEntry>
{
    SortEntryVector(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StorageFileQueryResult :
    Windows::Storage::Search::IStorageFileQueryResult,
    impl::require<StorageFileQueryResult, Windows::Storage::Search::IStorageFileQueryResult2>
{
    StorageFileQueryResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StorageFolderQueryResult :
    Windows::Storage::Search::IStorageFolderQueryResult
{
    StorageFolderQueryResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StorageItemQueryResult :
    Windows::Storage::Search::IStorageItemQueryResult
{
    StorageItemQueryResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StorageLibraryContentChangedTriggerDetails :
    Windows::Storage::Search::IStorageLibraryContentChangedTriggerDetails
{
    StorageLibraryContentChangedTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ValueAndLanguage :
    Windows::Storage::Search::IValueAndLanguage
{
    ValueAndLanguage(std::nullptr_t) noexcept {}
    ValueAndLanguage();
};

}

}
