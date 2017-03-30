// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Resources.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Resources {

struct ICustomXamlResourceLoader :
    Windows::Foundation::IInspectable,
    impl::consume<ICustomXamlResourceLoader>
{
    ICustomXamlResourceLoader(std::nullptr_t = nullptr) noexcept {}
};

struct ICustomXamlResourceLoaderFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ICustomXamlResourceLoaderFactory>
{
    ICustomXamlResourceLoaderFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ICustomXamlResourceLoaderOverrides :
    Windows::Foundation::IInspectable,
    impl::consume<ICustomXamlResourceLoaderOverrides>
{
    ICustomXamlResourceLoaderOverrides(std::nullptr_t = nullptr) noexcept {}
};

struct ICustomXamlResourceLoaderStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICustomXamlResourceLoaderStatics>
{
    ICustomXamlResourceLoaderStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
