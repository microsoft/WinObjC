// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Xaml.Resources.3.h"
#include "Windows.UI.Xaml.h"
#include "internal/Windows.UI.Xaml.Resources.4.h"
#include "internal/Windows.UI.Xaml.Resources.5.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoader> : produce_base<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoader>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderFactory> : produce_base<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Resources::ICustomXamlResourceLoader> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides> : produce_base<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides>
{
    HRESULT __stdcall abi_GetResource(impl::abi_arg_in<hstring> resourceId, impl::abi_arg_in<hstring> objectType, impl::abi_arg_in<hstring> propertyName, impl::abi_arg_in<hstring> propertyType, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetResource(*reinterpret_cast<const hstring *>(&resourceId), *reinterpret_cast<const hstring *>(&objectType), *reinterpret_cast<const hstring *>(&propertyName), *reinterpret_cast<const hstring *>(&propertyType)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderStatics> : produce_base<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderStatics>
{
    HRESULT __stdcall get_Current(impl::abi_arg_out<Windows::UI::Xaml::Resources::ICustomXamlResourceLoader> value) noexcept override
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

    HRESULT __stdcall put_Current(impl::abi_arg_in<Windows::UI::Xaml::Resources::ICustomXamlResourceLoader> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Current(*reinterpret_cast<const Windows::UI::Xaml::Resources::CustomXamlResourceLoader *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Resources {

template <typename D> Windows::Foundation::IInspectable impl_ICustomXamlResourceLoaderOverrides<D>::GetResource(hstring_view resourceId, hstring_view objectType, hstring_view propertyName, hstring_view propertyType) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(ICustomXamlResourceLoaderOverrides)->abi_GetResource(get_abi(resourceId), get_abi(objectType), get_abi(propertyName), get_abi(propertyType), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Resources::CustomXamlResourceLoader impl_ICustomXamlResourceLoaderStatics<D>::Current() const
{
    Windows::UI::Xaml::Resources::CustomXamlResourceLoader value { nullptr };
    check_hresult(WINRT_SHIM(ICustomXamlResourceLoaderStatics)->get_Current(put_abi(value)));
    return value;
}

template <typename D> void impl_ICustomXamlResourceLoaderStatics<D>::Current(const Windows::UI::Xaml::Resources::CustomXamlResourceLoader & value) const
{
    check_hresult(WINRT_SHIM(ICustomXamlResourceLoaderStatics)->put_Current(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Resources::CustomXamlResourceLoader impl_ICustomXamlResourceLoaderFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Resources::CustomXamlResourceLoader instance { nullptr };
    check_hresult(WINRT_SHIM(ICustomXamlResourceLoaderFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

inline CustomXamlResourceLoader::CustomXamlResourceLoader()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<CustomXamlResourceLoader, ICustomXamlResourceLoaderFactory>().CreateInstance(outer, inner));
}

inline Windows::UI::Xaml::Resources::CustomXamlResourceLoader CustomXamlResourceLoader::Current()
{
    return get_activation_factory<CustomXamlResourceLoader, ICustomXamlResourceLoaderStatics>().Current();
}

inline void CustomXamlResourceLoader::Current(const Windows::UI::Xaml::Resources::CustomXamlResourceLoader & value)
{
    get_activation_factory<CustomXamlResourceLoader, ICustomXamlResourceLoaderStatics>().Current(value);
}

}

}
#pragma warning(pop)
