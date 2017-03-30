// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Resources {

struct ICustomXamlResourceLoader;
struct ICustomXamlResourceLoaderFactory;
struct ICustomXamlResourceLoaderOverrides;
struct ICustomXamlResourceLoaderStatics;
struct CustomXamlResourceLoader;

}

namespace Windows::UI::Xaml::Resources {

struct ICustomXamlResourceLoader;
struct ICustomXamlResourceLoaderFactory;
struct ICustomXamlResourceLoaderOverrides;
struct ICustomXamlResourceLoaderStatics;
struct CustomXamlResourceLoader;

}

namespace Windows::UI::Xaml::Resources {

template <typename T> struct impl_ICustomXamlResourceLoader;
template <typename T> struct impl_ICustomXamlResourceLoaderFactory;
template <typename T> struct impl_ICustomXamlResourceLoaderOverrides;
template <typename T> struct impl_ICustomXamlResourceLoaderStatics;

}

}
