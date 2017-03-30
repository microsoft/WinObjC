// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Resources.0.h"
#include "Windows.Foundation.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Resources {

struct __declspec(uuid("08524908-16ef-45ad-a602-293637d7e61a")) __declspec(novtable) IResourceLoader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetString(hstring resource, hstring * value) = 0;
};

struct __declspec(uuid("10eb6ec6-8138-48c1-bc65-e1f14207367c")) __declspec(novtable) IResourceLoader2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetStringForUri(Windows::Foundation::IUriRuntimeClass * uri, hstring * value) = 0;
};

struct __declspec(uuid("c33a3603-69dc-4285-a077-d5c0e47ccbe8")) __declspec(novtable) IResourceLoaderFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateResourceLoaderByName(hstring name, Windows::ApplicationModel::Resources::IResourceLoader ** loader) = 0;
};

struct __declspec(uuid("bf777ce1-19c8-49c2-953c-47e9227b334e")) __declspec(novtable) IResourceLoaderStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetStringForReference(Windows::Foundation::IUriRuntimeClass * uri, hstring * value) = 0;
};

struct __declspec(uuid("0cc04141-6466-4989-9494-0b82dfc53f1f")) __declspec(novtable) IResourceLoaderStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::ApplicationModel::Resources::IResourceLoader ** loader) = 0;
    virtual HRESULT __stdcall abi_GetForCurrentViewWithName(hstring name, Windows::ApplicationModel::Resources::IResourceLoader ** loader) = 0;
    virtual HRESULT __stdcall abi_GetForViewIndependentUse(Windows::ApplicationModel::Resources::IResourceLoader ** loader) = 0;
    virtual HRESULT __stdcall abi_GetForViewIndependentUseWithName(hstring name, Windows::ApplicationModel::Resources::IResourceLoader ** loader) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Resources::ResourceLoader> { using default_interface = Windows::ApplicationModel::Resources::IResourceLoader; };

}

namespace Windows::ApplicationModel::Resources {

template <typename D>
struct WINRT_EBO impl_IResourceLoader
{
    hstring GetString(hstring_view resource) const;
};

template <typename D>
struct WINRT_EBO impl_IResourceLoader2
{
    hstring GetStringForUri(const Windows::Foundation::Uri & uri) const;
};

template <typename D>
struct WINRT_EBO impl_IResourceLoaderFactory
{
    [[deprecated("ResourceLoader may be altered or unavailable for releases after Windows 8.1. Instead, use GetForCurrentView.")]] Windows::ApplicationModel::Resources::ResourceLoader CreateResourceLoaderByName(hstring_view name) const;
};

template <typename D>
struct WINRT_EBO impl_IResourceLoaderStatics
{
    [[deprecated("GetStringForReference may be altered or unavailable for releases after Windows Phone 'OSVersion' (TBD). Instead, use GetStringForUri.")]] hstring GetStringForReference(const Windows::Foundation::Uri & uri) const;
};

template <typename D>
struct WINRT_EBO impl_IResourceLoaderStatics2
{
    Windows::ApplicationModel::Resources::ResourceLoader GetForCurrentView() const;
    Windows::ApplicationModel::Resources::ResourceLoader GetForCurrentView(hstring_view name) const;
    Windows::ApplicationModel::Resources::ResourceLoader GetForViewIndependentUse() const;
    Windows::ApplicationModel::Resources::ResourceLoader GetForViewIndependentUse(hstring_view name) const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Resources::IResourceLoader>
{
    using abi = ABI::Windows::ApplicationModel::Resources::IResourceLoader;
    template <typename D> using consume = Windows::ApplicationModel::Resources::impl_IResourceLoader<D>;
};

template <> struct traits<Windows::ApplicationModel::Resources::IResourceLoader2>
{
    using abi = ABI::Windows::ApplicationModel::Resources::IResourceLoader2;
    template <typename D> using consume = Windows::ApplicationModel::Resources::impl_IResourceLoader2<D>;
};

template <> struct traits<Windows::ApplicationModel::Resources::IResourceLoaderFactory>
{
    using abi = ABI::Windows::ApplicationModel::Resources::IResourceLoaderFactory;
    template <typename D> using consume = Windows::ApplicationModel::Resources::impl_IResourceLoaderFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Resources::IResourceLoaderStatics>
{
    using abi = ABI::Windows::ApplicationModel::Resources::IResourceLoaderStatics;
    template <typename D> using consume = Windows::ApplicationModel::Resources::impl_IResourceLoaderStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Resources::IResourceLoaderStatics2>
{
    using abi = ABI::Windows::ApplicationModel::Resources::IResourceLoaderStatics2;
    template <typename D> using consume = Windows::ApplicationModel::Resources::impl_IResourceLoaderStatics2<D>;
};

template <> struct traits<Windows::ApplicationModel::Resources::ResourceLoader>
{
    using abi = ABI::Windows::ApplicationModel::Resources::ResourceLoader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Resources.ResourceLoader"; }
};

}

}
