// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.ApplicationModel.Resources.Core.3.h"
#include "Windows.ApplicationModel.Resources.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Resources::Core::INamedResource> : produce_base<D, Windows::ApplicationModel::Resources::Core::INamedResource>
{
    HRESULT __stdcall get_Uri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> uri) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *uri = detach_abi(this->shim().Uri());
            return S_OK;
        }
        catch (...)
        {
            *uri = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Candidates(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceCandidate>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Candidates());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Resolve(impl::abi_arg_out<Windows::ApplicationModel::Resources::Core::IResourceCandidate> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Resolve());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResolveForContext(impl::abi_arg_in<Windows::ApplicationModel::Resources::Core::IResourceContext> resourceContext, impl::abi_arg_out<Windows::ApplicationModel::Resources::Core::IResourceCandidate> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Resolve(*reinterpret_cast<const Windows::ApplicationModel::Resources::Core::ResourceContext *>(&resourceContext)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResolveAll(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceCandidate>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ResolveAll());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResolveAllForContext(impl::abi_arg_in<Windows::ApplicationModel::Resources::Core::IResourceContext> resourceContext, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceCandidate>> instances) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instances = detach_abi(this->shim().ResolveAll(*reinterpret_cast<const Windows::ApplicationModel::Resources::Core::ResourceContext *>(&resourceContext)));
            return S_OK;
        }
        catch (...)
        {
            *instances = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Resources::Core::IResourceCandidate> : produce_base<D, Windows::ApplicationModel::Resources::Core::IResourceCandidate>
{
    HRESULT __stdcall get_Qualifiers(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceQualifier>> value) noexcept override
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

    HRESULT __stdcall get_IsMatch(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMatch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsMatchAsDefault(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMatchAsDefault());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDefault(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDefault());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ValueAsString(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ValueAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetValueAsFileAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetValueAsFileAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetQualifierValue(impl::abi_arg_in<hstring> qualifierName, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetQualifierValue(*reinterpret_cast<const hstring *>(&qualifierName)));
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
struct produce<D, Windows::ApplicationModel::Resources::Core::IResourceCandidate2> : produce_base<D, Windows::ApplicationModel::Resources::Core::IResourceCandidate2>
{
    HRESULT __stdcall abi_GetValueAsStreamAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetValueAsStreamAsync());
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
struct produce<D, Windows::ApplicationModel::Resources::Core::IResourceContext> : produce_base<D, Windows::ApplicationModel::Resources::Core::IResourceContext>
{
    HRESULT __stdcall get_QualifierValues(impl::abi_arg_out<Windows::Foundation::Collections::IObservableMap<hstring, hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QualifierValues());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Reset() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Reset();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResetQualifierValues(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> qualifierNames) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Reset(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&qualifierNames));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OverrideToMatch(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Resources::Core::ResourceQualifier>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OverrideToMatch(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Resources::Core::ResourceQualifier> *>(&result));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clone(impl::abi_arg_out<Windows::ApplicationModel::Resources::Core::IResourceContext> clone) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *clone = detach_abi(this->shim().Clone());
            return S_OK;
        }
        catch (...)
        {
            *clone = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Languages(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Languages());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Languages(impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<hstring>> languages) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Languages(*reinterpret_cast<const Windows::Foundation::Collections::IVectorView<hstring> *>(&languages));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Resources::Core::IResourceContextStatics> : produce_base<D, Windows::ApplicationModel::Resources::Core::IResourceContextStatics>
{
    HRESULT __stdcall abi_CreateMatchingContext(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Resources::Core::ResourceQualifier>> result, impl::abi_arg_out<Windows::ApplicationModel::Resources::Core::IResourceContext> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateMatchingContext(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Resources::Core::ResourceQualifier> *>(&result)));
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
struct produce<D, Windows::ApplicationModel::Resources::Core::IResourceContextStatics2> : produce_base<D, Windows::ApplicationModel::Resources::Core::IResourceContextStatics2>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::ApplicationModel::Resources::Core::IResourceContext> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetGlobalQualifierValue(impl::abi_arg_in<hstring> key, impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetGlobalQualifierValue(*reinterpret_cast<const hstring *>(&key), *reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResetGlobalQualifierValues() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResetGlobalQualifierValues();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResetGlobalQualifierValuesForSpecifiedQualifiers(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> qualifierNames) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResetGlobalQualifierValues(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&qualifierNames));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetForViewIndependentUse(impl::abi_arg_out<Windows::ApplicationModel::Resources::Core::IResourceContext> loader) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *loader = detach_abi(this->shim().GetForViewIndependentUse());
            return S_OK;
        }
        catch (...)
        {
            *loader = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Resources::Core::IResourceContextStatics3> : produce_base<D, Windows::ApplicationModel::Resources::Core::IResourceContextStatics3>
{
    HRESULT __stdcall abi_SetGlobalQualifierValueWithPersistence(impl::abi_arg_in<hstring> key, impl::abi_arg_in<hstring> value, Windows::ApplicationModel::Resources::Core::ResourceQualifierPersistence persistence) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetGlobalQualifierValue(*reinterpret_cast<const hstring *>(&key), *reinterpret_cast<const hstring *>(&value), persistence);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Resources::Core::IResourceManager> : produce_base<D, Windows::ApplicationModel::Resources::Core::IResourceManager>
{
    HRESULT __stdcall get_MainResourceMap(impl::abi_arg_out<Windows::ApplicationModel::Resources::Core::IResourceMap> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MainResourceMap());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllResourceMaps(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Resources::Core::ResourceMap>> maps) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *maps = detach_abi(this->shim().AllResourceMaps());
            return S_OK;
        }
        catch (...)
        {
            *maps = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultContext(impl::abi_arg_out<Windows::ApplicationModel::Resources::Core::IResourceContext> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultContext());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadPriFiles(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Storage::IStorageFile>> files) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LoadPriFiles(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Storage::IStorageFile> *>(&files));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnloadPriFiles(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Storage::IStorageFile>> files) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnloadPriFiles(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Storage::IStorageFile> *>(&files));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Resources::Core::IResourceManager2> : produce_base<D, Windows::ApplicationModel::Resources::Core::IResourceManager2>
{
    HRESULT __stdcall abi_GetAllNamedResourcesForPackage(impl::abi_arg_in<hstring> packageName, impl::abi_arg_in<Windows::ApplicationModel::Resources::Core::ResourceLayoutInfo> resourceLayoutInfo, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::NamedResource>> table) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *table = detach_abi(this->shim().GetAllNamedResourcesForPackage(*reinterpret_cast<const hstring *>(&packageName), *reinterpret_cast<const Windows::ApplicationModel::Resources::Core::ResourceLayoutInfo *>(&resourceLayoutInfo)));
            return S_OK;
        }
        catch (...)
        {
            *table = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAllSubtreesForPackage(impl::abi_arg_in<hstring> packageName, impl::abi_arg_in<Windows::ApplicationModel::Resources::Core::ResourceLayoutInfo> resourceLayoutInfo, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceMap>> table) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *table = detach_abi(this->shim().GetAllSubtreesForPackage(*reinterpret_cast<const hstring *>(&packageName), *reinterpret_cast<const Windows::ApplicationModel::Resources::Core::ResourceLayoutInfo *>(&resourceLayoutInfo)));
            return S_OK;
        }
        catch (...)
        {
            *table = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Resources::Core::IResourceManagerStatics> : produce_base<D, Windows::ApplicationModel::Resources::Core::IResourceManagerStatics>
{
    HRESULT __stdcall get_Current(impl::abi_arg_out<Windows::ApplicationModel::Resources::Core::IResourceManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Current());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsResourceReference(impl::abi_arg_in<hstring> resourceReference, bool * isReference) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *isReference = detach_abi(this->shim().IsResourceReference(*reinterpret_cast<const hstring *>(&resourceReference)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Resources::Core::IResourceMap> : produce_base<D, Windows::ApplicationModel::Resources::Core::IResourceMap>
{
    HRESULT __stdcall get_Uri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> uri) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *uri = detach_abi(this->shim().Uri());
            return S_OK;
        }
        catch (...)
        {
            *uri = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetValue(impl::abi_arg_in<hstring> resource, impl::abi_arg_out<Windows::ApplicationModel::Resources::Core::IResourceCandidate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetValue(*reinterpret_cast<const hstring *>(&resource)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetValueForContext(impl::abi_arg_in<hstring> resource, impl::abi_arg_in<Windows::ApplicationModel::Resources::Core::IResourceContext> context, impl::abi_arg_out<Windows::ApplicationModel::Resources::Core::IResourceCandidate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetValue(*reinterpret_cast<const hstring *>(&resource), *reinterpret_cast<const Windows::ApplicationModel::Resources::Core::ResourceContext *>(&context)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSubtree(impl::abi_arg_in<hstring> reference, impl::abi_arg_out<Windows::ApplicationModel::Resources::Core::IResourceMap> map) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *map = detach_abi(this->shim().GetSubtree(*reinterpret_cast<const hstring *>(&reference)));
            return S_OK;
        }
        catch (...)
        {
            *map = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Resources::Core::IResourceQualifier> : produce_base<D, Windows::ApplicationModel::Resources::Core::IResourceQualifier>
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

    HRESULT __stdcall get_IsDefault(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDefault());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsMatch(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMatch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Score(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Score());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Resources::Core {

template <typename D> Windows::ApplicationModel::Resources::Core::ResourceMap impl_IResourceManager<D>::MainResourceMap() const
{
    Windows::ApplicationModel::Resources::Core::ResourceMap value { nullptr };
    check_hresult(WINRT_SHIM(IResourceManager)->get_MainResourceMap(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Resources::Core::ResourceMap> impl_IResourceManager<D>::AllResourceMaps() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Resources::Core::ResourceMap> maps;
    check_hresult(WINRT_SHIM(IResourceManager)->get_AllResourceMaps(put_abi(maps)));
    return maps;
}

template <typename D> Windows::ApplicationModel::Resources::Core::ResourceContext impl_IResourceManager<D>::DefaultContext() const
{
    Windows::ApplicationModel::Resources::Core::ResourceContext value { nullptr };
    check_hresult(WINRT_SHIM(IResourceManager)->get_DefaultContext(put_abi(value)));
    return value;
}

template <typename D> void impl_IResourceManager<D>::LoadPriFiles(iterable<Windows::Storage::IStorageFile> files) const
{
    check_hresult(WINRT_SHIM(IResourceManager)->abi_LoadPriFiles(get_abi(files)));
}

template <typename D> void impl_IResourceManager<D>::UnloadPriFiles(iterable<Windows::Storage::IStorageFile> files) const
{
    check_hresult(WINRT_SHIM(IResourceManager)->abi_UnloadPriFiles(get_abi(files)));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::NamedResource> impl_IResourceManager2<D>::GetAllNamedResourcesForPackage(hstring_view packageName, const Windows::ApplicationModel::Resources::Core::ResourceLayoutInfo & resourceLayoutInfo) const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::NamedResource> table;
    check_hresult(WINRT_SHIM(IResourceManager2)->abi_GetAllNamedResourcesForPackage(get_abi(packageName), get_abi(resourceLayoutInfo), put_abi(table)));
    return table;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceMap> impl_IResourceManager2<D>::GetAllSubtreesForPackage(hstring_view packageName, const Windows::ApplicationModel::Resources::Core::ResourceLayoutInfo & resourceLayoutInfo) const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceMap> table;
    check_hresult(WINRT_SHIM(IResourceManager2)->abi_GetAllSubtreesForPackage(get_abi(packageName), get_abi(resourceLayoutInfo), put_abi(table)));
    return table;
}

template <typename D> Windows::ApplicationModel::Resources::Core::ResourceManager impl_IResourceManagerStatics<D>::Current() const
{
    Windows::ApplicationModel::Resources::Core::ResourceManager value { nullptr };
    check_hresult(WINRT_SHIM(IResourceManagerStatics)->get_Current(put_abi(value)));
    return value;
}

template <typename D> bool impl_IResourceManagerStatics<D>::IsResourceReference(hstring_view resourceReference) const
{
    bool isReference {};
    check_hresult(WINRT_SHIM(IResourceManagerStatics)->abi_IsResourceReference(get_abi(resourceReference), &isReference));
    return isReference;
}

template <typename D> hstring impl_IResourceQualifier<D>::QualifierName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IResourceQualifier)->get_QualifierName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IResourceQualifier<D>::QualifierValue() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IResourceQualifier)->get_QualifierValue(put_abi(value)));
    return value;
}

template <typename D> bool impl_IResourceQualifier<D>::IsDefault() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IResourceQualifier)->get_IsDefault(&value));
    return value;
}

template <typename D> bool impl_IResourceQualifier<D>::IsMatch() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IResourceQualifier)->get_IsMatch(&value));
    return value;
}

template <typename D> double impl_IResourceQualifier<D>::Score() const
{
    double value {};
    check_hresult(WINRT_SHIM(IResourceQualifier)->get_Score(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IObservableMap<hstring, hstring> impl_IResourceContext<D>::QualifierValues() const
{
    Windows::Foundation::Collections::IObservableMap<hstring, hstring> value;
    check_hresult(WINRT_SHIM(IResourceContext)->get_QualifierValues(put_abi(value)));
    return value;
}

template <typename D> void impl_IResourceContext<D>::Reset() const
{
    check_hresult(WINRT_SHIM(IResourceContext)->abi_Reset());
}

template <typename D> void impl_IResourceContext<D>::Reset(iterable<hstring> qualifierNames) const
{
    check_hresult(WINRT_SHIM(IResourceContext)->abi_ResetQualifierValues(get_abi(qualifierNames)));
}

template <typename D> void impl_IResourceContext<D>::OverrideToMatch(iterable<Windows::ApplicationModel::Resources::Core::ResourceQualifier> result) const
{
    check_hresult(WINRT_SHIM(IResourceContext)->abi_OverrideToMatch(get_abi(result)));
}

template <typename D> Windows::ApplicationModel::Resources::Core::ResourceContext impl_IResourceContext<D>::Clone() const
{
    Windows::ApplicationModel::Resources::Core::ResourceContext clone { nullptr };
    check_hresult(WINRT_SHIM(IResourceContext)->abi_Clone(put_abi(clone)));
    return clone;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IResourceContext<D>::Languages() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IResourceContext)->get_Languages(put_abi(value)));
    return value;
}

template <typename D> void impl_IResourceContext<D>::Languages(const Windows::Foundation::Collections::IVectorView<hstring> & languages) const
{
    check_hresult(WINRT_SHIM(IResourceContext)->put_Languages(get_abi(languages)));
}

template <typename D> Windows::ApplicationModel::Resources::Core::ResourceContext impl_IResourceContextStatics<D>::CreateMatchingContext(iterable<Windows::ApplicationModel::Resources::Core::ResourceQualifier> result) const
{
    Windows::ApplicationModel::Resources::Core::ResourceContext value { nullptr };
    check_hresult(WINRT_SHIM(IResourceContextStatics)->abi_CreateMatchingContext(get_abi(result), put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Resources::Core::ResourceContext impl_IResourceContextStatics2<D>::GetForCurrentView() const
{
    Windows::ApplicationModel::Resources::Core::ResourceContext value { nullptr };
    check_hresult(WINRT_SHIM(IResourceContextStatics2)->abi_GetForCurrentView(put_abi(value)));
    return value;
}

template <typename D> void impl_IResourceContextStatics2<D>::SetGlobalQualifierValue(hstring_view key, hstring_view value) const
{
    check_hresult(WINRT_SHIM(IResourceContextStatics2)->abi_SetGlobalQualifierValue(get_abi(key), get_abi(value)));
}

template <typename D> void impl_IResourceContextStatics2<D>::ResetGlobalQualifierValues() const
{
    check_hresult(WINRT_SHIM(IResourceContextStatics2)->abi_ResetGlobalQualifierValues());
}

template <typename D> void impl_IResourceContextStatics2<D>::ResetGlobalQualifierValues(iterable<hstring> qualifierNames) const
{
    check_hresult(WINRT_SHIM(IResourceContextStatics2)->abi_ResetGlobalQualifierValuesForSpecifiedQualifiers(get_abi(qualifierNames)));
}

template <typename D> Windows::ApplicationModel::Resources::Core::ResourceContext impl_IResourceContextStatics2<D>::GetForViewIndependentUse() const
{
    Windows::ApplicationModel::Resources::Core::ResourceContext loader { nullptr };
    check_hresult(WINRT_SHIM(IResourceContextStatics2)->abi_GetForViewIndependentUse(put_abi(loader)));
    return loader;
}

template <typename D> void impl_IResourceContextStatics3<D>::SetGlobalQualifierValue(hstring_view key, hstring_view value, Windows::ApplicationModel::Resources::Core::ResourceQualifierPersistence persistence) const
{
    check_hresult(WINRT_SHIM(IResourceContextStatics3)->abi_SetGlobalQualifierValueWithPersistence(get_abi(key), get_abi(value), persistence));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceQualifier> impl_IResourceCandidate<D>::Qualifiers() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceQualifier> value;
    check_hresult(WINRT_SHIM(IResourceCandidate)->get_Qualifiers(put_abi(value)));
    return value;
}

template <typename D> bool impl_IResourceCandidate<D>::IsMatch() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IResourceCandidate)->get_IsMatch(&value));
    return value;
}

template <typename D> bool impl_IResourceCandidate<D>::IsMatchAsDefault() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IResourceCandidate)->get_IsMatchAsDefault(&value));
    return value;
}

template <typename D> bool impl_IResourceCandidate<D>::IsDefault() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IResourceCandidate)->get_IsDefault(&value));
    return value;
}

template <typename D> hstring impl_IResourceCandidate<D>::ValueAsString() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IResourceCandidate)->get_ValueAsString(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IResourceCandidate<D>::GetValueAsFileAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IResourceCandidate)->abi_GetValueAsFileAsync(put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IResourceCandidate<D>::GetQualifierValue(hstring_view qualifierName) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IResourceCandidate)->abi_GetQualifierValue(get_abi(qualifierName), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> impl_IResourceCandidate2<D>::GetValueAsStreamAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> operation;
    check_hresult(WINRT_SHIM(IResourceCandidate2)->abi_GetValueAsStreamAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::Uri impl_INamedResource<D>::Uri() const
{
    Windows::Foundation::Uri uri { nullptr };
    check_hresult(WINRT_SHIM(INamedResource)->get_Uri(put_abi(uri)));
    return uri;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceCandidate> impl_INamedResource<D>::Candidates() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceCandidate> value;
    check_hresult(WINRT_SHIM(INamedResource)->get_Candidates(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Resources::Core::ResourceCandidate impl_INamedResource<D>::Resolve() const
{
    Windows::ApplicationModel::Resources::Core::ResourceCandidate result { nullptr };
    check_hresult(WINRT_SHIM(INamedResource)->abi_Resolve(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Resources::Core::ResourceCandidate impl_INamedResource<D>::Resolve(const Windows::ApplicationModel::Resources::Core::ResourceContext & resourceContext) const
{
    Windows::ApplicationModel::Resources::Core::ResourceCandidate result { nullptr };
    check_hresult(WINRT_SHIM(INamedResource)->abi_ResolveForContext(get_abi(resourceContext), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceCandidate> impl_INamedResource<D>::ResolveAll() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceCandidate> result;
    check_hresult(WINRT_SHIM(INamedResource)->abi_ResolveAll(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceCandidate> impl_INamedResource<D>::ResolveAll(const Windows::ApplicationModel::Resources::Core::ResourceContext & resourceContext) const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceCandidate> instances;
    check_hresult(WINRT_SHIM(INamedResource)->abi_ResolveAllForContext(get_abi(resourceContext), put_abi(instances)));
    return instances;
}

template <typename D> Windows::Foundation::Uri impl_IResourceMap<D>::Uri() const
{
    Windows::Foundation::Uri uri { nullptr };
    check_hresult(WINRT_SHIM(IResourceMap)->get_Uri(put_abi(uri)));
    return uri;
}

template <typename D> Windows::ApplicationModel::Resources::Core::ResourceCandidate impl_IResourceMap<D>::GetValue(hstring_view resource) const
{
    Windows::ApplicationModel::Resources::Core::ResourceCandidate value { nullptr };
    check_hresult(WINRT_SHIM(IResourceMap)->abi_GetValue(get_abi(resource), put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Resources::Core::ResourceCandidate impl_IResourceMap<D>::GetValue(hstring_view resource, const Windows::ApplicationModel::Resources::Core::ResourceContext & context) const
{
    Windows::ApplicationModel::Resources::Core::ResourceCandidate value { nullptr };
    check_hresult(WINRT_SHIM(IResourceMap)->abi_GetValueForContext(get_abi(resource), get_abi(context), put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Resources::Core::ResourceMap impl_IResourceMap<D>::GetSubtree(hstring_view reference) const
{
    Windows::ApplicationModel::Resources::Core::ResourceMap map { nullptr };
    check_hresult(WINRT_SHIM(IResourceMap)->abi_GetSubtree(get_abi(reference), put_abi(map)));
    return map;
}

inline ResourceContext::ResourceContext() :
    ResourceContext(activate_instance<ResourceContext>())
{}

inline Windows::ApplicationModel::Resources::Core::ResourceContext ResourceContext::CreateMatchingContext(iterable<Windows::ApplicationModel::Resources::Core::ResourceQualifier> result)
{
    return get_activation_factory<ResourceContext, IResourceContextStatics>().CreateMatchingContext(result);
}

inline Windows::ApplicationModel::Resources::Core::ResourceContext ResourceContext::GetForCurrentView()
{
    return get_activation_factory<ResourceContext, IResourceContextStatics2>().GetForCurrentView();
}

inline void ResourceContext::SetGlobalQualifierValue(hstring_view key, hstring_view value)
{
    get_activation_factory<ResourceContext, IResourceContextStatics2>().SetGlobalQualifierValue(key, value);
}

inline void ResourceContext::ResetGlobalQualifierValues()
{
    get_activation_factory<ResourceContext, IResourceContextStatics2>().ResetGlobalQualifierValues();
}

inline void ResourceContext::ResetGlobalQualifierValues(iterable<hstring> qualifierNames)
{
    get_activation_factory<ResourceContext, IResourceContextStatics2>().ResetGlobalQualifierValues(qualifierNames);
}

inline Windows::ApplicationModel::Resources::Core::ResourceContext ResourceContext::GetForViewIndependentUse()
{
    return get_activation_factory<ResourceContext, IResourceContextStatics2>().GetForViewIndependentUse();
}

inline void ResourceContext::SetGlobalQualifierValue(hstring_view key, hstring_view value, Windows::ApplicationModel::Resources::Core::ResourceQualifierPersistence persistence)
{
    get_activation_factory<ResourceContext, IResourceContextStatics3>().SetGlobalQualifierValue(key, value, persistence);
}

inline Windows::ApplicationModel::Resources::Core::ResourceManager ResourceManager::Current()
{
    return get_activation_factory<ResourceManager, IResourceManagerStatics>().Current();
}

inline bool ResourceManager::IsResourceReference(hstring_view resourceReference)
{
    return get_activation_factory<ResourceManager, IResourceManagerStatics>().IsResourceReference(resourceReference);
}

}

}
#pragma warning(pop)
