// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Storage.FileProperties.3.h"
#include "internal/Windows.Storage.Search.3.h"
#include "Windows.Storage.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Storage::Search::IContentIndexer> : produce_base<D, Windows::Storage::Search::IContentIndexer>
{
    HRESULT __stdcall abi_AddAsync(impl::abi_arg_in<Windows::Storage::Search::IIndexableContent> indexableContent, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().AddAsync(*reinterpret_cast<const Windows::Storage::Search::IIndexableContent *>(&indexableContent)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateAsync(impl::abi_arg_in<Windows::Storage::Search::IIndexableContent> indexableContent, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().UpdateAsync(*reinterpret_cast<const Windows::Storage::Search::IIndexableContent *>(&indexableContent)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAsync(impl::abi_arg_in<hstring> contentId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().DeleteAsync(*reinterpret_cast<const hstring *>(&contentId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteMultipleAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> contentIds, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().DeleteMultipleAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&contentIds)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAllAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().DeleteAllAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RetrievePropertiesAsync(impl::abi_arg_in<hstring> contentId, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> propertiesToRetrieve, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RetrievePropertiesAsync(*reinterpret_cast<const hstring *>(&contentId), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&propertiesToRetrieve)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Revision(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Revision());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Search::IContentIndexerQuery> : produce_base<D, Windows::Storage::Search::IContentIndexerQuery>
{
    HRESULT __stdcall abi_GetCountAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<uint32_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetCountAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPropertiesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetPropertiesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPropertiesRangeAsync(uint32_t startIndex, uint32_t maxItems, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetPropertiesAsync(startIndex, maxItems));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::Search::IIndexableContent>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRangeAsync(uint32_t startIndex, uint32_t maxItems, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::Search::IIndexableContent>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetAsync(startIndex, maxItems));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_QueryFolder(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QueryFolder());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Search::IContentIndexerQueryOperations> : produce_base<D, Windows::Storage::Search::IContentIndexerQueryOperations>
{
    HRESULT __stdcall abi_CreateQueryWithSortOrderAndLanguage(impl::abi_arg_in<hstring> searchFilter, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> propertiesToRetrieve, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Storage::Search::SortEntry>> sortOrder, impl::abi_arg_in<hstring> searchFilterLanguage, impl::abi_arg_out<Windows::Storage::Search::IContentIndexerQuery> query) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *query = detach_abi(this->shim().CreateQuery(*reinterpret_cast<const hstring *>(&searchFilter), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&propertiesToRetrieve), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Storage::Search::SortEntry> *>(&sortOrder), *reinterpret_cast<const hstring *>(&searchFilterLanguage)));
            return S_OK;
        }
        catch (...)
        {
            *query = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateQueryWithSortOrder(impl::abi_arg_in<hstring> searchFilter, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> propertiesToRetrieve, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Storage::Search::SortEntry>> sortOrder, impl::abi_arg_out<Windows::Storage::Search::IContentIndexerQuery> query) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *query = detach_abi(this->shim().CreateQuery(*reinterpret_cast<const hstring *>(&searchFilter), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&propertiesToRetrieve), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Storage::Search::SortEntry> *>(&sortOrder)));
            return S_OK;
        }
        catch (...)
        {
            *query = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateQuery(impl::abi_arg_in<hstring> searchFilter, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> propertiesToRetrieve, impl::abi_arg_out<Windows::Storage::Search::IContentIndexerQuery> query) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *query = detach_abi(this->shim().CreateQuery(*reinterpret_cast<const hstring *>(&searchFilter), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&propertiesToRetrieve)));
            return S_OK;
        }
        catch (...)
        {
            *query = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Search::IContentIndexerStatics> : produce_base<D, Windows::Storage::Search::IContentIndexerStatics>
{
    HRESULT __stdcall abi_GetIndexerWithName(impl::abi_arg_in<hstring> indexName, impl::abi_arg_out<Windows::Storage::Search::IContentIndexer> index) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *index = detach_abi(this->shim().GetIndexer(*reinterpret_cast<const hstring *>(&indexName)));
            return S_OK;
        }
        catch (...)
        {
            *index = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIndexer(impl::abi_arg_out<Windows::Storage::Search::IContentIndexer> index) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *index = detach_abi(this->shim().GetIndexer());
            return S_OK;
        }
        catch (...)
        {
            *index = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Search::IIndexableContent> : produce_base<D, Windows::Storage::Search::IIndexableContent>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Id(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Id(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Stream(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Stream());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Stream(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stream(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StreamContentType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StreamContentType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StreamContentType(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StreamContentType(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Search::IQueryOptions> : produce_base<D, Windows::Storage::Search::IQueryOptions>
{
    HRESULT __stdcall get_FileTypeFilter(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FileTypeFilter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FolderDepth(Windows::Storage::Search::FolderDepth * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FolderDepth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FolderDepth(Windows::Storage::Search::FolderDepth value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FolderDepth(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ApplicationSearchFilter(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ApplicationSearchFilter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ApplicationSearchFilter(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ApplicationSearchFilter(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserSearchFilter(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserSearchFilter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UserSearchFilter(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UserSearchFilter(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Language(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Language(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Language(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IndexerOption(Windows::Storage::Search::IndexerOption * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IndexerOption());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IndexerOption(Windows::Storage::Search::IndexerOption value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IndexerOption(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SortOrder(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Storage::Search::SortEntry>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SortOrder());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GroupPropertyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GroupPropertyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DateStackOption(Windows::Storage::Search::DateStackOption * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DateStackOption());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveToString(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SaveToString());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadFromString(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LoadFromString(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetThumbnailPrefetch(Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedSize, Windows::Storage::FileProperties::ThumbnailOptions options) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetThumbnailPrefetch(mode, requestedSize, options);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyPrefetch(Windows::Storage::FileProperties::PropertyPrefetchOptions options, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> propertiesToRetrieve) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyPrefetch(options, *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&propertiesToRetrieve));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Search::IQueryOptionsFactory> : produce_base<D, Windows::Storage::Search::IQueryOptionsFactory>
{
    HRESULT __stdcall abi_CreateCommonFileQuery(Windows::Storage::Search::CommonFileQuery query, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> fileTypeFilter, impl::abi_arg_out<Windows::Storage::Search::IQueryOptions> queryOptions) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *queryOptions = detach_abi(this->shim().CreateCommonFileQuery(query, *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&fileTypeFilter)));
            return S_OK;
        }
        catch (...)
        {
            *queryOptions = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCommonFolderQuery(Windows::Storage::Search::CommonFolderQuery query, impl::abi_arg_out<Windows::Storage::Search::IQueryOptions> queryOptions) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *queryOptions = detach_abi(this->shim().CreateCommonFolderQuery(query));
            return S_OK;
        }
        catch (...)
        {
            *queryOptions = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Search::IQueryOptionsWithProviderFilter> : produce_base<D, Windows::Storage::Search::IQueryOptionsWithProviderFilter>
{
    HRESULT __stdcall get_StorageProviderIdFilter(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StorageProviderIdFilter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Search::IStorageFileQueryResult> : produce_base<D, Windows::Storage::Search::IStorageFileQueryResult>
{
    HRESULT __stdcall abi_GetFilesAsync(uint32_t startIndex, uint32_t maxNumberOfItems, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFilesAsync(startIndex, maxNumberOfItems));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFilesAsyncDefaultStartAndCount(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFilesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Search::IStorageFileQueryResult2> : produce_base<D, Windows::Storage::Search::IStorageFileQueryResult2>
{
    HRESULT __stdcall abi_GetMatchingPropertiesWithRanges(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetMatchingPropertiesWithRanges(*reinterpret_cast<const Windows::Storage::StorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Search::IStorageFolderQueryOperations> : produce_base<D, Windows::Storage::Search::IStorageFolderQueryOperations>
{
    HRESULT __stdcall abi_GetIndexedStateAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Storage::Search::IndexedState>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetIndexedStateAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFileQueryOverloadDefault(impl::abi_arg_out<Windows::Storage::Search::IStorageFileQueryResult> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFileQuery());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFileQuery(Windows::Storage::Search::CommonFileQuery query, impl::abi_arg_out<Windows::Storage::Search::IStorageFileQueryResult> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFileQuery(query));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFileQueryWithOptions(impl::abi_arg_in<Windows::Storage::Search::IQueryOptions> queryOptions, impl::abi_arg_out<Windows::Storage::Search::IStorageFileQueryResult> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFileQueryWithOptions(*reinterpret_cast<const Windows::Storage::Search::QueryOptions *>(&queryOptions)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFolderQueryOverloadDefault(impl::abi_arg_out<Windows::Storage::Search::IStorageFolderQueryResult> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFolderQuery());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFolderQuery(Windows::Storage::Search::CommonFolderQuery query, impl::abi_arg_out<Windows::Storage::Search::IStorageFolderQueryResult> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFolderQuery(query));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFolderQueryWithOptions(impl::abi_arg_in<Windows::Storage::Search::IQueryOptions> queryOptions, impl::abi_arg_out<Windows::Storage::Search::IStorageFolderQueryResult> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFolderQueryWithOptions(*reinterpret_cast<const Windows::Storage::Search::QueryOptions *>(&queryOptions)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateItemQuery(impl::abi_arg_out<Windows::Storage::Search::IStorageItemQueryResult> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateItemQuery());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateItemQueryWithOptions(impl::abi_arg_in<Windows::Storage::Search::IQueryOptions> queryOptions, impl::abi_arg_out<Windows::Storage::Search::IStorageItemQueryResult> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateItemQueryWithOptions(*reinterpret_cast<const Windows::Storage::Search::QueryOptions *>(&queryOptions)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFilesAsync(Windows::Storage::Search::CommonFileQuery query, uint32_t startIndex, uint32_t maxItemsToRetrieve, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFilesAsync(query, startIndex, maxItemsToRetrieve));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFilesAsyncOverloadDefaultStartAndCount(Windows::Storage::Search::CommonFileQuery query, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFilesAsync(query));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFoldersAsync(Windows::Storage::Search::CommonFolderQuery query, uint32_t startIndex, uint32_t maxItemsToRetrieve, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFoldersAsync(query, startIndex, maxItemsToRetrieve));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFoldersAsyncOverloadDefaultStartAndCount(Windows::Storage::Search::CommonFolderQuery query, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFoldersAsync(query));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemsAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetItemsAsync(startIndex, maxItemsToRetrieve));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AreQueryOptionsSupported(impl::abi_arg_in<Windows::Storage::Search::IQueryOptions> queryOptions, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AreQueryOptionsSupported(*reinterpret_cast<const Windows::Storage::Search::QueryOptions *>(&queryOptions)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsCommonFolderQuerySupported(Windows::Storage::Search::CommonFolderQuery query, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCommonFolderQuerySupported(query));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsCommonFileQuerySupported(Windows::Storage::Search::CommonFileQuery query, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCommonFileQuerySupported(query));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Search::IStorageFolderQueryResult> : produce_base<D, Windows::Storage::Search::IStorageFolderQueryResult>
{
    HRESULT __stdcall abi_GetFoldersAsync(uint32_t startIndex, uint32_t maxNumberOfItems, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFoldersAsync(startIndex, maxNumberOfItems));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFoldersAsyncDefaultStartAndCount(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFoldersAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Search::IStorageItemQueryResult> : produce_base<D, Windows::Storage::Search::IStorageItemQueryResult>
{
    HRESULT __stdcall abi_GetItemsAsync(uint32_t startIndex, uint32_t maxNumberOfItems, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetItemsAsync(startIndex, maxNumberOfItems));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemsAsyncDefaultStartAndCount(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetItemsAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Search::IStorageLibraryContentChangedTriggerDetails> : produce_base<D, Windows::Storage::Search::IStorageLibraryContentChangedTriggerDetails>
{
    HRESULT __stdcall get_Folder(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Folder());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateModifiedSinceQuery(impl::abi_arg_in<Windows::Foundation::DateTime> lastQueryTime, impl::abi_arg_out<Windows::Storage::Search::IStorageItemQueryResult> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateModifiedSinceQuery(*reinterpret_cast<const Windows::Foundation::DateTime *>(&lastQueryTime)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Search::IStorageQueryResultBase> : produce_base<D, Windows::Storage::Search::IStorageQueryResultBase>
{
    HRESULT __stdcall abi_GetItemCountAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<uint32_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetItemCountAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Folder(impl::abi_arg_out<Windows::Storage::IStorageFolder> container) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *container = detach_abi(this->shim().Folder());
            return S_OK;
        }
        catch (...)
        {
            *container = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ContentsChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Storage::Search::IStorageQueryResultBase, Windows::Foundation::IInspectable>> handler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().ContentsChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Storage::Search::IStorageQueryResultBase, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ContentsChanged(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentsChanged(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_OptionsChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Storage::Search::IStorageQueryResultBase, Windows::Foundation::IInspectable>> changedHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().OptionsChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Storage::Search::IStorageQueryResultBase, Windows::Foundation::IInspectable> *>(&changedHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_OptionsChanged(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OptionsChanged(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindStartIndexAsync(impl::abi_arg_in<Windows::Foundation::IInspectable> value, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<uint32_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindStartIndexAsync(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentQueryOptions(impl::abi_arg_out<Windows::Storage::Search::IQueryOptions> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCurrentQueryOptions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ApplyNewQueryOptions(impl::abi_arg_in<Windows::Storage::Search::IQueryOptions> newQueryOptions) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ApplyNewQueryOptions(*reinterpret_cast<const Windows::Storage::Search::QueryOptions *>(&newQueryOptions));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Search::IValueAndLanguage> : produce_base<D, Windows::Storage::Search::IValueAndLanguage>
{
    HRESULT __stdcall get_Language(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Language(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Language(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Value(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Storage::Search {

template <typename D> Windows::Storage::Search::ContentIndexer impl_IContentIndexerStatics<D>::GetIndexer(hstring_view indexName) const
{
    Windows::Storage::Search::ContentIndexer index { nullptr };
    check_hresult(WINRT_SHIM(IContentIndexerStatics)->abi_GetIndexerWithName(get_abi(indexName), put_abi(index)));
    return index;
}

template <typename D> Windows::Storage::Search::ContentIndexer impl_IContentIndexerStatics<D>::GetIndexer() const
{
    Windows::Storage::Search::ContentIndexer index { nullptr };
    check_hresult(WINRT_SHIM(IContentIndexerStatics)->abi_GetIndexer(put_abi(index)));
    return index;
}

template <typename D> hstring impl_IIndexableContent<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IIndexableContent)->get_Id(put_abi(value)));
    return value;
}

template <typename D> void impl_IIndexableContent<D>::Id(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IIndexableContent)->put_Id(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable> impl_IIndexableContent<D>::Properties() const
{
    Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IIndexableContent)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStream impl_IIndexableContent<D>::Stream() const
{
    Windows::Storage::Streams::IRandomAccessStream value;
    check_hresult(WINRT_SHIM(IIndexableContent)->get_Stream(put_abi(value)));
    return value;
}

template <typename D> void impl_IIndexableContent<D>::Stream(const Windows::Storage::Streams::IRandomAccessStream & value) const
{
    check_hresult(WINRT_SHIM(IIndexableContent)->put_Stream(get_abi(value)));
}

template <typename D> hstring impl_IIndexableContent<D>::StreamContentType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IIndexableContent)->get_StreamContentType(put_abi(value)));
    return value;
}

template <typename D> void impl_IIndexableContent<D>::StreamContentType(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IIndexableContent)->put_StreamContentType(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContentIndexer<D>::AddAsync(const Windows::Storage::Search::IIndexableContent & indexableContent) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IContentIndexer)->abi_AddAsync(get_abi(indexableContent), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContentIndexer<D>::UpdateAsync(const Windows::Storage::Search::IIndexableContent & indexableContent) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IContentIndexer)->abi_UpdateAsync(get_abi(indexableContent), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContentIndexer<D>::DeleteAsync(hstring_view contentId) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IContentIndexer)->abi_DeleteAsync(get_abi(contentId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContentIndexer<D>::DeleteMultipleAsync(iterable<hstring> contentIds) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IContentIndexer)->abi_DeleteMultipleAsync(get_abi(contentIds), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContentIndexer<D>::DeleteAllAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IContentIndexer)->abi_DeleteAllAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> impl_IContentIndexer<D>::RetrievePropertiesAsync(hstring_view contentId, iterable<hstring> propertiesToRetrieve) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> operation;
    check_hresult(WINRT_SHIM(IContentIndexer)->abi_RetrievePropertiesAsync(get_abi(contentId), get_abi(propertiesToRetrieve), put_abi(operation)));
    return operation;
}

template <typename D> uint64_t impl_IContentIndexer<D>::Revision() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IContentIndexer)->get_Revision(&value));
    return value;
}

template <typename D> hstring impl_IValueAndLanguage<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IValueAndLanguage)->get_Language(put_abi(value)));
    return value;
}

template <typename D> void impl_IValueAndLanguage<D>::Language(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IValueAndLanguage)->put_Language(get_abi(value)));
}

template <typename D> Windows::Foundation::IInspectable impl_IValueAndLanguage<D>::Value() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IValueAndLanguage)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IValueAndLanguage<D>::Value(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IValueAndLanguage)->put_Value(get_abi(value)));
}

template <typename D> Windows::Storage::Search::ContentIndexerQuery impl_IContentIndexerQueryOperations<D>::CreateQuery(hstring_view searchFilter, iterable<hstring> propertiesToRetrieve, iterable<Windows::Storage::Search::SortEntry> sortOrder, hstring_view searchFilterLanguage) const
{
    Windows::Storage::Search::ContentIndexerQuery query { nullptr };
    check_hresult(WINRT_SHIM(IContentIndexerQueryOperations)->abi_CreateQueryWithSortOrderAndLanguage(get_abi(searchFilter), get_abi(propertiesToRetrieve), get_abi(sortOrder), get_abi(searchFilterLanguage), put_abi(query)));
    return query;
}

template <typename D> Windows::Storage::Search::ContentIndexerQuery impl_IContentIndexerQueryOperations<D>::CreateQuery(hstring_view searchFilter, iterable<hstring> propertiesToRetrieve, iterable<Windows::Storage::Search::SortEntry> sortOrder) const
{
    Windows::Storage::Search::ContentIndexerQuery query { nullptr };
    check_hresult(WINRT_SHIM(IContentIndexerQueryOperations)->abi_CreateQueryWithSortOrder(get_abi(searchFilter), get_abi(propertiesToRetrieve), get_abi(sortOrder), put_abi(query)));
    return query;
}

template <typename D> Windows::Storage::Search::ContentIndexerQuery impl_IContentIndexerQueryOperations<D>::CreateQuery(hstring_view searchFilter, iterable<hstring> propertiesToRetrieve) const
{
    Windows::Storage::Search::ContentIndexerQuery query { nullptr };
    check_hresult(WINRT_SHIM(IContentIndexerQueryOperations)->abi_CreateQuery(get_abi(searchFilter), get_abi(propertiesToRetrieve), put_abi(query)));
    return query;
}

template <typename D> Windows::Foundation::IAsyncOperation<uint32_t> impl_IContentIndexerQuery<D>::GetCountAsync() const
{
    Windows::Foundation::IAsyncOperation<uint32_t> operation;
    check_hresult(WINRT_SHIM(IContentIndexerQuery)->abi_GetCountAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>>> impl_IContentIndexerQuery<D>::GetPropertiesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>>> operation;
    check_hresult(WINRT_SHIM(IContentIndexerQuery)->abi_GetPropertiesAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>>> impl_IContentIndexerQuery<D>::GetPropertiesAsync(uint32_t startIndex, uint32_t maxItems) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>>> operation;
    check_hresult(WINRT_SHIM(IContentIndexerQuery)->abi_GetPropertiesRangeAsync(startIndex, maxItems, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::Search::IIndexableContent>> impl_IContentIndexerQuery<D>::GetAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::Search::IIndexableContent>> operation;
    check_hresult(WINRT_SHIM(IContentIndexerQuery)->abi_GetAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::Search::IIndexableContent>> impl_IContentIndexerQuery<D>::GetAsync(uint32_t startIndex, uint32_t maxItems) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::Search::IIndexableContent>> operation;
    check_hresult(WINRT_SHIM(IContentIndexerQuery)->abi_GetRangeAsync(startIndex, maxItems, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Storage::StorageFolder impl_IContentIndexerQuery<D>::QueryFolder() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IContentIndexerQuery)->get_QueryFolder(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IQueryOptions<D>::FileTypeFilter() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IQueryOptions)->get_FileTypeFilter(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Search::FolderDepth impl_IQueryOptions<D>::FolderDepth() const
{
    Windows::Storage::Search::FolderDepth value {};
    check_hresult(WINRT_SHIM(IQueryOptions)->get_FolderDepth(&value));
    return value;
}

template <typename D> void impl_IQueryOptions<D>::FolderDepth(Windows::Storage::Search::FolderDepth value) const
{
    check_hresult(WINRT_SHIM(IQueryOptions)->put_FolderDepth(value));
}

template <typename D> hstring impl_IQueryOptions<D>::ApplicationSearchFilter() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IQueryOptions)->get_ApplicationSearchFilter(put_abi(value)));
    return value;
}

template <typename D> void impl_IQueryOptions<D>::ApplicationSearchFilter(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IQueryOptions)->put_ApplicationSearchFilter(get_abi(value)));
}

template <typename D> hstring impl_IQueryOptions<D>::UserSearchFilter() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IQueryOptions)->get_UserSearchFilter(put_abi(value)));
    return value;
}

template <typename D> void impl_IQueryOptions<D>::UserSearchFilter(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IQueryOptions)->put_UserSearchFilter(get_abi(value)));
}

template <typename D> hstring impl_IQueryOptions<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IQueryOptions)->get_Language(put_abi(value)));
    return value;
}

template <typename D> void impl_IQueryOptions<D>::Language(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IQueryOptions)->put_Language(get_abi(value)));
}

template <typename D> Windows::Storage::Search::IndexerOption impl_IQueryOptions<D>::IndexerOption() const
{
    Windows::Storage::Search::IndexerOption value {};
    check_hresult(WINRT_SHIM(IQueryOptions)->get_IndexerOption(&value));
    return value;
}

template <typename D> void impl_IQueryOptions<D>::IndexerOption(Windows::Storage::Search::IndexerOption value) const
{
    check_hresult(WINRT_SHIM(IQueryOptions)->put_IndexerOption(value));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Storage::Search::SortEntry> impl_IQueryOptions<D>::SortOrder() const
{
    Windows::Foundation::Collections::IVector<Windows::Storage::Search::SortEntry> value;
    check_hresult(WINRT_SHIM(IQueryOptions)->get_SortOrder(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IQueryOptions<D>::GroupPropertyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IQueryOptions)->get_GroupPropertyName(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Search::DateStackOption impl_IQueryOptions<D>::DateStackOption() const
{
    Windows::Storage::Search::DateStackOption value {};
    check_hresult(WINRT_SHIM(IQueryOptions)->get_DateStackOption(&value));
    return value;
}

template <typename D> hstring impl_IQueryOptions<D>::SaveToString() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IQueryOptions)->abi_SaveToString(put_abi(value)));
    return value;
}

template <typename D> void impl_IQueryOptions<D>::LoadFromString(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IQueryOptions)->abi_LoadFromString(get_abi(value)));
}

template <typename D> void impl_IQueryOptions<D>::SetThumbnailPrefetch(Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedSize, Windows::Storage::FileProperties::ThumbnailOptions options) const
{
    check_hresult(WINRT_SHIM(IQueryOptions)->abi_SetThumbnailPrefetch(mode, requestedSize, options));
}

template <typename D> void impl_IQueryOptions<D>::SetPropertyPrefetch(Windows::Storage::FileProperties::PropertyPrefetchOptions options, iterable<hstring> propertiesToRetrieve) const
{
    check_hresult(WINRT_SHIM(IQueryOptions)->abi_SetPropertyPrefetch(options, get_abi(propertiesToRetrieve)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IQueryOptionsWithProviderFilter<D>::StorageProviderIdFilter() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IQueryOptionsWithProviderFilter)->get_StorageProviderIdFilter(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Search::QueryOptions impl_IQueryOptionsFactory<D>::CreateCommonFileQuery(Windows::Storage::Search::CommonFileQuery query, iterable<hstring> fileTypeFilter) const
{
    Windows::Storage::Search::QueryOptions queryOptions { nullptr };
    check_hresult(WINRT_SHIM(IQueryOptionsFactory)->abi_CreateCommonFileQuery(query, get_abi(fileTypeFilter), put_abi(queryOptions)));
    return queryOptions;
}

template <typename D> Windows::Storage::Search::QueryOptions impl_IQueryOptionsFactory<D>::CreateCommonFolderQuery(Windows::Storage::Search::CommonFolderQuery query) const
{
    Windows::Storage::Search::QueryOptions queryOptions { nullptr };
    check_hresult(WINRT_SHIM(IQueryOptionsFactory)->abi_CreateCommonFolderQuery(query, put_abi(queryOptions)));
    return queryOptions;
}

template <typename D> Windows::Foundation::IAsyncOperation<uint32_t> impl_IStorageQueryResultBase<D>::GetItemCountAsync() const
{
    Windows::Foundation::IAsyncOperation<uint32_t> operation;
    check_hresult(WINRT_SHIM(IStorageQueryResultBase)->abi_GetItemCountAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Storage::StorageFolder impl_IStorageQueryResultBase<D>::Folder() const
{
    Windows::Storage::StorageFolder container { nullptr };
    check_hresult(WINRT_SHIM(IStorageQueryResultBase)->get_Folder(put_abi(container)));
    return container;
}

template <typename D> event_token impl_IStorageQueryResultBase<D>::ContentsChanged(const Windows::Foundation::TypedEventHandler<Windows::Storage::Search::IStorageQueryResultBase, Windows::Foundation::IInspectable> & handler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IStorageQueryResultBase)->add_ContentsChanged(get_abi(handler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IStorageQueryResultBase> impl_IStorageQueryResultBase<D>::ContentsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Storage::Search::IStorageQueryResultBase, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IStorageQueryResultBase>(this, &ABI::Windows::Storage::Search::IStorageQueryResultBase::remove_ContentsChanged, ContentsChanged(handler));
}

template <typename D> void impl_IStorageQueryResultBase<D>::ContentsChanged(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IStorageQueryResultBase)->remove_ContentsChanged(eventCookie));
}

template <typename D> event_token impl_IStorageQueryResultBase<D>::OptionsChanged(const Windows::Foundation::TypedEventHandler<Windows::Storage::Search::IStorageQueryResultBase, Windows::Foundation::IInspectable> & changedHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IStorageQueryResultBase)->add_OptionsChanged(get_abi(changedHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IStorageQueryResultBase> impl_IStorageQueryResultBase<D>::OptionsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Storage::Search::IStorageQueryResultBase, Windows::Foundation::IInspectable> & changedHandler) const
{
    return impl::make_event_revoker<D, IStorageQueryResultBase>(this, &ABI::Windows::Storage::Search::IStorageQueryResultBase::remove_OptionsChanged, OptionsChanged(changedHandler));
}

template <typename D> void impl_IStorageQueryResultBase<D>::OptionsChanged(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IStorageQueryResultBase)->remove_OptionsChanged(eventCookie));
}

template <typename D> Windows::Foundation::IAsyncOperation<uint32_t> impl_IStorageQueryResultBase<D>::FindStartIndexAsync(const Windows::Foundation::IInspectable & value) const
{
    Windows::Foundation::IAsyncOperation<uint32_t> operation;
    check_hresult(WINRT_SHIM(IStorageQueryResultBase)->abi_FindStartIndexAsync(get_abi(value), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Storage::Search::QueryOptions impl_IStorageQueryResultBase<D>::GetCurrentQueryOptions() const
{
    Windows::Storage::Search::QueryOptions value { nullptr };
    check_hresult(WINRT_SHIM(IStorageQueryResultBase)->abi_GetCurrentQueryOptions(put_abi(value)));
    return value;
}

template <typename D> void impl_IStorageQueryResultBase<D>::ApplyNewQueryOptions(const Windows::Storage::Search::QueryOptions & newQueryOptions) const
{
    check_hresult(WINRT_SHIM(IStorageQueryResultBase)->abi_ApplyNewQueryOptions(get_abi(newQueryOptions)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> impl_IStorageFileQueryResult<D>::GetFilesAsync(uint32_t startIndex, uint32_t maxNumberOfItems) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> operation;
    check_hresult(WINRT_SHIM(IStorageFileQueryResult)->abi_GetFilesAsync(startIndex, maxNumberOfItems, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> impl_IStorageFileQueryResult<D>::GetFilesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> operation;
    check_hresult(WINRT_SHIM(IStorageFileQueryResult)->abi_GetFilesAsyncDefaultStartAndCount(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment>> impl_IStorageFileQueryResult2<D>::GetMatchingPropertiesWithRanges(const Windows::Storage::StorageFile & file) const
{
    Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment>> result;
    check_hresult(WINRT_SHIM(IStorageFileQueryResult2)->abi_GetMatchingPropertiesWithRanges(get_abi(file), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>> impl_IStorageFolderQueryResult<D>::GetFoldersAsync(uint32_t startIndex, uint32_t maxNumberOfItems) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>> operation;
    check_hresult(WINRT_SHIM(IStorageFolderQueryResult)->abi_GetFoldersAsync(startIndex, maxNumberOfItems, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>> impl_IStorageFolderQueryResult<D>::GetFoldersAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>> operation;
    check_hresult(WINRT_SHIM(IStorageFolderQueryResult)->abi_GetFoldersAsyncDefaultStartAndCount(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> impl_IStorageItemQueryResult<D>::GetItemsAsync(uint32_t startIndex, uint32_t maxNumberOfItems) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> operation;
    check_hresult(WINRT_SHIM(IStorageItemQueryResult)->abi_GetItemsAsync(startIndex, maxNumberOfItems, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> impl_IStorageItemQueryResult<D>::GetItemsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> operation;
    check_hresult(WINRT_SHIM(IStorageItemQueryResult)->abi_GetItemsAsyncDefaultStartAndCount(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Storage::Search::IndexedState> impl_IStorageFolderQueryOperations<D>::GetIndexedStateAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Storage::Search::IndexedState> operation;
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_GetIndexedStateAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Storage::Search::StorageFileQueryResult impl_IStorageFolderQueryOperations<D>::CreateFileQuery() const
{
    Windows::Storage::Search::StorageFileQueryResult value { nullptr };
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_CreateFileQueryOverloadDefault(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Search::StorageFileQueryResult impl_IStorageFolderQueryOperations<D>::CreateFileQuery(Windows::Storage::Search::CommonFileQuery query) const
{
    Windows::Storage::Search::StorageFileQueryResult value { nullptr };
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_CreateFileQuery(query, put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Search::StorageFileQueryResult impl_IStorageFolderQueryOperations<D>::CreateFileQueryWithOptions(const Windows::Storage::Search::QueryOptions & queryOptions) const
{
    Windows::Storage::Search::StorageFileQueryResult value { nullptr };
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_CreateFileQueryWithOptions(get_abi(queryOptions), put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Search::StorageFolderQueryResult impl_IStorageFolderQueryOperations<D>::CreateFolderQuery() const
{
    Windows::Storage::Search::StorageFolderQueryResult value { nullptr };
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_CreateFolderQueryOverloadDefault(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Search::StorageFolderQueryResult impl_IStorageFolderQueryOperations<D>::CreateFolderQuery(Windows::Storage::Search::CommonFolderQuery query) const
{
    Windows::Storage::Search::StorageFolderQueryResult value { nullptr };
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_CreateFolderQuery(query, put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Search::StorageFolderQueryResult impl_IStorageFolderQueryOperations<D>::CreateFolderQueryWithOptions(const Windows::Storage::Search::QueryOptions & queryOptions) const
{
    Windows::Storage::Search::StorageFolderQueryResult value { nullptr };
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_CreateFolderQueryWithOptions(get_abi(queryOptions), put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Search::StorageItemQueryResult impl_IStorageFolderQueryOperations<D>::CreateItemQuery() const
{
    Windows::Storage::Search::StorageItemQueryResult value { nullptr };
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_CreateItemQuery(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Search::StorageItemQueryResult impl_IStorageFolderQueryOperations<D>::CreateItemQueryWithOptions(const Windows::Storage::Search::QueryOptions & queryOptions) const
{
    Windows::Storage::Search::StorageItemQueryResult value { nullptr };
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_CreateItemQueryWithOptions(get_abi(queryOptions), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> impl_IStorageFolderQueryOperations<D>::GetFilesAsync(Windows::Storage::Search::CommonFileQuery query, uint32_t startIndex, uint32_t maxItemsToRetrieve) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> operation;
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_GetFilesAsync(query, startIndex, maxItemsToRetrieve, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> impl_IStorageFolderQueryOperations<D>::GetFilesAsync(Windows::Storage::Search::CommonFileQuery query) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> operation;
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_GetFilesAsyncOverloadDefaultStartAndCount(query, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>> impl_IStorageFolderQueryOperations<D>::GetFoldersAsync(Windows::Storage::Search::CommonFolderQuery query, uint32_t startIndex, uint32_t maxItemsToRetrieve) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>> operation;
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_GetFoldersAsync(query, startIndex, maxItemsToRetrieve, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>> impl_IStorageFolderQueryOperations<D>::GetFoldersAsync(Windows::Storage::Search::CommonFolderQuery query) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>> operation;
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_GetFoldersAsyncOverloadDefaultStartAndCount(query, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> impl_IStorageFolderQueryOperations<D>::GetItemsAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> operation;
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_GetItemsAsync(startIndex, maxItemsToRetrieve, put_abi(operation)));
    return operation;
}

template <typename D> bool impl_IStorageFolderQueryOperations<D>::AreQueryOptionsSupported(const Windows::Storage::Search::QueryOptions & queryOptions) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_AreQueryOptionsSupported(get_abi(queryOptions), &value));
    return value;
}

template <typename D> bool impl_IStorageFolderQueryOperations<D>::IsCommonFolderQuerySupported(Windows::Storage::Search::CommonFolderQuery query) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_IsCommonFolderQuerySupported(query, &value));
    return value;
}

template <typename D> bool impl_IStorageFolderQueryOperations<D>::IsCommonFileQuerySupported(Windows::Storage::Search::CommonFileQuery query) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStorageFolderQueryOperations)->abi_IsCommonFileQuerySupported(query, &value));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IStorageLibraryContentChangedTriggerDetails<D>::Folder() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IStorageLibraryContentChangedTriggerDetails)->get_Folder(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Search::StorageItemQueryResult impl_IStorageLibraryContentChangedTriggerDetails<D>::CreateModifiedSinceQuery(const Windows::Foundation::DateTime & lastQueryTime) const
{
    Windows::Storage::Search::StorageItemQueryResult result { nullptr };
    check_hresult(WINRT_SHIM(IStorageLibraryContentChangedTriggerDetails)->abi_CreateModifiedSinceQuery(get_abi(lastQueryTime), put_abi(result)));
    return result;
}

inline Windows::Storage::Search::ContentIndexer ContentIndexer::GetIndexer(hstring_view indexName)
{
    return get_activation_factory<ContentIndexer, IContentIndexerStatics>().GetIndexer(indexName);
}

inline Windows::Storage::Search::ContentIndexer ContentIndexer::GetIndexer()
{
    return get_activation_factory<ContentIndexer, IContentIndexerStatics>().GetIndexer();
}

inline IndexableContent::IndexableContent() :
    IndexableContent(activate_instance<IndexableContent>())
{}

inline QueryOptions::QueryOptions() :
    QueryOptions(activate_instance<QueryOptions>())
{}

inline QueryOptions::QueryOptions(Windows::Storage::Search::CommonFileQuery query, iterable<hstring> fileTypeFilter) :
    QueryOptions(get_activation_factory<QueryOptions, IQueryOptionsFactory>().CreateCommonFileQuery(query, fileTypeFilter))
{}

inline QueryOptions::QueryOptions(Windows::Storage::Search::CommonFolderQuery query) :
    QueryOptions(get_activation_factory<QueryOptions, IQueryOptionsFactory>().CreateCommonFolderQuery(query))
{}

inline ValueAndLanguage::ValueAndLanguage() :
    ValueAndLanguage(activate_instance<ValueAndLanguage>())
{}

}

}
#pragma warning(pop)
