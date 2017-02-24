// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.ApplicationModel.Resources.3.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Resources::IResourceLoader> : produce_base<D, Windows::ApplicationModel::Resources::IResourceLoader>
{
    HRESULT __stdcall abi_GetString(impl::abi_arg_in<hstring> resource, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetString(*reinterpret_cast<const hstring *>(&resource)));
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
struct produce<D, Windows::ApplicationModel::Resources::IResourceLoader2> : produce_base<D, Windows::ApplicationModel::Resources::IResourceLoader2>
{
    HRESULT __stdcall abi_GetStringForUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStringForUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
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
struct produce<D, Windows::ApplicationModel::Resources::IResourceLoaderFactory> : produce_base<D, Windows::ApplicationModel::Resources::IResourceLoaderFactory>
{
    HRESULT __stdcall abi_CreateResourceLoaderByName(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::ApplicationModel::Resources::IResourceLoader> loader) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *loader = detach_abi(this->shim().CreateResourceLoaderByName(*reinterpret_cast<const hstring *>(&name)));
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
struct produce<D, Windows::ApplicationModel::Resources::IResourceLoaderStatics> : produce_base<D, Windows::ApplicationModel::Resources::IResourceLoaderStatics>
{
    HRESULT __stdcall abi_GetStringForReference(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStringForReference(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
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
struct produce<D, Windows::ApplicationModel::Resources::IResourceLoaderStatics2> : produce_base<D, Windows::ApplicationModel::Resources::IResourceLoaderStatics2>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::ApplicationModel::Resources::IResourceLoader> loader) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *loader = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *loader = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetForCurrentViewWithName(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::ApplicationModel::Resources::IResourceLoader> loader) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *loader = detach_abi(this->shim().GetForCurrentView(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *loader = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetForViewIndependentUse(impl::abi_arg_out<Windows::ApplicationModel::Resources::IResourceLoader> loader) noexcept override
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

    HRESULT __stdcall abi_GetForViewIndependentUseWithName(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::ApplicationModel::Resources::IResourceLoader> loader) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *loader = detach_abi(this->shim().GetForViewIndependentUse(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *loader = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Resources {

template <typename D> hstring impl_IResourceLoader<D>::GetString(hstring_view resource) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IResourceLoader)->abi_GetString(get_abi(resource), put_abi(value)));
    return value;
}

template <typename D> hstring impl_IResourceLoader2<D>::GetStringForUri(const Windows::Foundation::Uri & uri) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IResourceLoader2)->abi_GetStringForUri(get_abi(uri), put_abi(value)));
    return value;
}

template <typename D> hstring impl_IResourceLoaderStatics<D>::GetStringForReference(const Windows::Foundation::Uri & uri) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IResourceLoaderStatics)->abi_GetStringForReference(get_abi(uri), put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Resources::ResourceLoader impl_IResourceLoaderStatics2<D>::GetForCurrentView() const
{
    Windows::ApplicationModel::Resources::ResourceLoader loader { nullptr };
    check_hresult(WINRT_SHIM(IResourceLoaderStatics2)->abi_GetForCurrentView(put_abi(loader)));
    return loader;
}

template <typename D> Windows::ApplicationModel::Resources::ResourceLoader impl_IResourceLoaderStatics2<D>::GetForCurrentView(hstring_view name) const
{
    Windows::ApplicationModel::Resources::ResourceLoader loader { nullptr };
    check_hresult(WINRT_SHIM(IResourceLoaderStatics2)->abi_GetForCurrentViewWithName(get_abi(name), put_abi(loader)));
    return loader;
}

template <typename D> Windows::ApplicationModel::Resources::ResourceLoader impl_IResourceLoaderStatics2<D>::GetForViewIndependentUse() const
{
    Windows::ApplicationModel::Resources::ResourceLoader loader { nullptr };
    check_hresult(WINRT_SHIM(IResourceLoaderStatics2)->abi_GetForViewIndependentUse(put_abi(loader)));
    return loader;
}

template <typename D> Windows::ApplicationModel::Resources::ResourceLoader impl_IResourceLoaderStatics2<D>::GetForViewIndependentUse(hstring_view name) const
{
    Windows::ApplicationModel::Resources::ResourceLoader loader { nullptr };
    check_hresult(WINRT_SHIM(IResourceLoaderStatics2)->abi_GetForViewIndependentUseWithName(get_abi(name), put_abi(loader)));
    return loader;
}

template <typename D> Windows::ApplicationModel::Resources::ResourceLoader impl_IResourceLoaderFactory<D>::CreateResourceLoaderByName(hstring_view name) const
{
    Windows::ApplicationModel::Resources::ResourceLoader loader { nullptr };
    check_hresult(WINRT_SHIM(IResourceLoaderFactory)->abi_CreateResourceLoaderByName(get_abi(name), put_abi(loader)));
    return loader;
}

inline ResourceLoader::ResourceLoader() :
    ResourceLoader(activate_instance<ResourceLoader>())
{}

inline ResourceLoader::ResourceLoader(hstring_view name) :
    ResourceLoader(get_activation_factory<ResourceLoader, IResourceLoaderFactory>().CreateResourceLoaderByName(name))
{}

inline hstring ResourceLoader::GetStringForReference(const Windows::Foundation::Uri & uri)
{
    return get_activation_factory<ResourceLoader, IResourceLoaderStatics>().GetStringForReference(uri);
}

inline Windows::ApplicationModel::Resources::ResourceLoader ResourceLoader::GetForCurrentView()
{
    return get_activation_factory<ResourceLoader, IResourceLoaderStatics2>().GetForCurrentView();
}

inline Windows::ApplicationModel::Resources::ResourceLoader ResourceLoader::GetForCurrentView(hstring_view name)
{
    return get_activation_factory<ResourceLoader, IResourceLoaderStatics2>().GetForCurrentView(name);
}

inline Windows::ApplicationModel::Resources::ResourceLoader ResourceLoader::GetForViewIndependentUse()
{
    return get_activation_factory<ResourceLoader, IResourceLoaderStatics2>().GetForViewIndependentUse();
}

inline Windows::ApplicationModel::Resources::ResourceLoader ResourceLoader::GetForViewIndependentUse(hstring_view name)
{
    return get_activation_factory<ResourceLoader, IResourceLoaderStatics2>().GetForViewIndependentUse(name);
}

}

}
#pragma warning(pop)
