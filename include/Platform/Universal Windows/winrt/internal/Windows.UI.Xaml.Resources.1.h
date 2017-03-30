// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.Resources.0.h"
#include "Windows.Foundation.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Resources {

struct __declspec(uuid("511a84ab-4a88-419f-852e-54083b90b078")) __declspec(novtable) ICustomXamlResourceLoader : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("5bfd7e49-7886-44f3-8ed3-6fec0463ed69")) __declspec(novtable) ICustomXamlResourceLoaderFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Resources::ICustomXamlResourceLoader ** instance) = 0;
};

struct __declspec(uuid("f851e991-af02-46e8-9af8-427b7ebfe9f8")) __declspec(novtable) ICustomXamlResourceLoaderOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetResource(hstring resourceId, hstring objectType, hstring propertyName, hstring propertyType, Windows::Foundation::IInspectable ** returnValue) = 0;
};

struct __declspec(uuid("224ff617-e4dc-4c27-ad32-db93d5d0e5da")) __declspec(novtable) ICustomXamlResourceLoaderStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Current(Windows::UI::Xaml::Resources::ICustomXamlResourceLoader ** value) = 0;
    virtual HRESULT __stdcall put_Current(Windows::UI::Xaml::Resources::ICustomXamlResourceLoader * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::Resources::CustomXamlResourceLoader> { using default_interface = Windows::UI::Xaml::Resources::ICustomXamlResourceLoader; };

}

namespace Windows::UI::Xaml::Resources {

template <typename D>
struct WINRT_EBO impl_ICustomXamlResourceLoader
{
};

template <typename D>
struct WINRT_EBO impl_ICustomXamlResourceLoaderFactory
{
    Windows::UI::Xaml::Resources::CustomXamlResourceLoader CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ICustomXamlResourceLoaderOverrides
{
    Windows::Foundation::IInspectable GetResource(hstring_view resourceId, hstring_view objectType, hstring_view propertyName, hstring_view propertyType) const;
};

template <typename D>
struct WINRT_EBO impl_ICustomXamlResourceLoaderStatics
{
    Windows::UI::Xaml::Resources::CustomXamlResourceLoader Current() const;
    void Current(const Windows::UI::Xaml::Resources::CustomXamlResourceLoader & value) const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Resources::ICustomXamlResourceLoader>
{
    using abi = ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoader;
    template <typename D> using consume = Windows::UI::Xaml::Resources::impl_ICustomXamlResourceLoader<D>;
};

template <> struct traits<Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderFactory>
{
    using abi = ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderFactory;
    template <typename D> using consume = Windows::UI::Xaml::Resources::impl_ICustomXamlResourceLoaderFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Resources::impl_ICustomXamlResourceLoaderOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderStatics>
{
    using abi = ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderStatics;
    template <typename D> using consume = Windows::UI::Xaml::Resources::impl_ICustomXamlResourceLoaderStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Resources::CustomXamlResourceLoader>
{
    using abi = ABI::Windows::UI::Xaml::Resources::CustomXamlResourceLoader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Resources.CustomXamlResourceLoader"; }
};

}

}
