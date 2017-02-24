// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.ApplicationModel.Resources.Management.3.h"
#include "Windows.ApplicationModel.Resources.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Resources::Management::IIndexedResourceCandidate> : produce_base<D, Windows::ApplicationModel::Resources::Management::IIndexedResourceCandidate>
{
    HRESULT __stdcall get_Type(Windows::ApplicationModel::Resources::Management::IndexedResourceType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Uri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Metadata(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Metadata());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Qualifiers(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Management::IndexedResourceQualifier>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Qualifiers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ValueAsString(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ValueAsString());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetQualifierValue(impl::abi_arg_in<hstring> qualifierName, impl::abi_arg_out<hstring> qualifierValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *qualifierValue = detach_abi(this->shim().GetQualifierValue(*reinterpret_cast<const hstring *>(&qualifierName)));
            return S_OK;
        }
        catch (...)
        {
            *qualifierValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Resources::Management::IIndexedResourceQualifier> : produce_base<D, Windows::ApplicationModel::Resources::Management::IIndexedResourceQualifier>
{
    HRESULT __stdcall get_QualifierName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QualifierName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_QualifierValue(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QualifierValue());
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
struct produce<D, Windows::ApplicationModel::Resources::Management::IResourceIndexer> : produce_base<D, Windows::ApplicationModel::Resources::Management::IResourceIndexer>
{
    HRESULT __stdcall abi_IndexFilePath(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> filePath, impl::abi_arg_out<Windows::ApplicationModel::Resources::Management::IIndexedResourceCandidate> candidate) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *candidate = detach_abi(this->shim().IndexFilePath(*reinterpret_cast<const Windows::Foundation::Uri *>(&filePath)));
            return S_OK;
        }
        catch (...)
        {
            *candidate = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IndexFileContentsAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().IndexFileContentsAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&file)));
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
struct produce<D, Windows::ApplicationModel::Resources::Management::IResourceIndexerFactory> : produce_base<D, Windows::ApplicationModel::Resources::Management::IResourceIndexerFactory>
{
    HRESULT __stdcall abi_CreateResourceIndexer(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> projectRoot, impl::abi_arg_out<Windows::ApplicationModel::Resources::Management::IResourceIndexer> indexer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *indexer = detach_abi(this->shim().CreateResourceIndexer(*reinterpret_cast<const Windows::Foundation::Uri *>(&projectRoot)));
            return S_OK;
        }
        catch (...)
        {
            *indexer = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Resources::Management::IResourceIndexerFactory2> : produce_base<D, Windows::ApplicationModel::Resources::Management::IResourceIndexerFactory2>
{
    HRESULT __stdcall abi_CreateResourceIndexerWithExtension(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> projectRoot, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> extensionDllPath, impl::abi_arg_out<Windows::ApplicationModel::Resources::Management::IResourceIndexer> indexer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *indexer = detach_abi(this->shim().CreateResourceIndexerWithExtension(*reinterpret_cast<const Windows::Foundation::Uri *>(&projectRoot), *reinterpret_cast<const Windows::Foundation::Uri *>(&extensionDllPath)));
            return S_OK;
        }
        catch (...)
        {
            *indexer = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Resources::Management {

template <typename D> Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate impl_IResourceIndexer<D>::IndexFilePath(const Windows::Foundation::Uri & filePath) const
{
    Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate candidate { nullptr };
    check_hresult(WINRT_SHIM(IResourceIndexer)->abi_IndexFilePath(get_abi(filePath), put_abi(candidate)));
    return candidate;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate>> impl_IResourceIndexer<D>::IndexFileContentsAsync(const Windows::Foundation::Uri & file) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate>> operation;
    check_hresult(WINRT_SHIM(IResourceIndexer)->abi_IndexFileContentsAsync(get_abi(file), put_abi(operation)));
    return operation;
}

template <typename D> Windows::ApplicationModel::Resources::Management::ResourceIndexer impl_IResourceIndexerFactory<D>::CreateResourceIndexer(const Windows::Foundation::Uri & projectRoot) const
{
    Windows::ApplicationModel::Resources::Management::ResourceIndexer indexer { nullptr };
    check_hresult(WINRT_SHIM(IResourceIndexerFactory)->abi_CreateResourceIndexer(get_abi(projectRoot), put_abi(indexer)));
    return indexer;
}

template <typename D> Windows::ApplicationModel::Resources::Management::ResourceIndexer impl_IResourceIndexerFactory2<D>::CreateResourceIndexerWithExtension(const Windows::Foundation::Uri & projectRoot, const Windows::Foundation::Uri & extensionDllPath) const
{
    Windows::ApplicationModel::Resources::Management::ResourceIndexer indexer { nullptr };
    check_hresult(WINRT_SHIM(IResourceIndexerFactory2)->abi_CreateResourceIndexerWithExtension(get_abi(projectRoot), get_abi(extensionDllPath), put_abi(indexer)));
    return indexer;
}

template <typename D> hstring impl_IIndexedResourceQualifier<D>::QualifierName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IIndexedResourceQualifier)->get_QualifierName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IIndexedResourceQualifier<D>::QualifierValue() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IIndexedResourceQualifier)->get_QualifierValue(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Resources::Management::IndexedResourceType impl_IIndexedResourceCandidate<D>::Type() const
{
    Windows::ApplicationModel::Resources::Management::IndexedResourceType value {};
    check_hresult(WINRT_SHIM(IIndexedResourceCandidate)->get_Type(&value));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IIndexedResourceCandidate<D>::Uri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IIndexedResourceCandidate)->get_Uri(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, hstring> impl_IIndexedResourceCandidate<D>::Metadata() const
{
    Windows::Foundation::Collections::IMapView<hstring, hstring> value;
    check_hresult(WINRT_SHIM(IIndexedResourceCandidate)->get_Metadata(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Management::IndexedResourceQualifier> impl_IIndexedResourceCandidate<D>::Qualifiers() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Management::IndexedResourceQualifier> value;
    check_hresult(WINRT_SHIM(IIndexedResourceCandidate)->get_Qualifiers(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IIndexedResourceCandidate<D>::ValueAsString() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IIndexedResourceCandidate)->get_ValueAsString(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IIndexedResourceCandidate<D>::GetQualifierValue(hstring_view qualifierName) const
{
    hstring qualifierValue;
    check_hresult(WINRT_SHIM(IIndexedResourceCandidate)->abi_GetQualifierValue(get_abi(qualifierName), put_abi(qualifierValue)));
    return qualifierValue;
}

inline ResourceIndexer::ResourceIndexer(const Windows::Foundation::Uri & projectRoot, const Windows::Foundation::Uri & extensionDllPath) :
    ResourceIndexer(get_activation_factory<ResourceIndexer, IResourceIndexerFactory2>().CreateResourceIndexerWithExtension(projectRoot, extensionDllPath))
{}

inline ResourceIndexer::ResourceIndexer(const Windows::Foundation::Uri & projectRoot) :
    ResourceIndexer(get_activation_factory<ResourceIndexer, IResourceIndexerFactory>().CreateResourceIndexer(projectRoot))
{}

}

}
#pragma warning(pop)
