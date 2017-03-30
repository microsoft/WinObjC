// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Foundation.Collections.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

struct __declspec(uuid("8a43ed9f-f4e6-4421-acf9-1dab2986820c")) __declspec(novtable) IPropertySet : Windows::Foundation::IInspectable
{
};

}

namespace ABI {

template <> struct traits<Windows::Foundation::Collections::PropertySet> { using default_interface = Windows::Foundation::Collections::IPropertySet; };
template <> struct traits<Windows::Foundation::Collections::StringMap> { using default_interface = Windows::Foundation::Collections::IMap<hstring, hstring>; };
template <> struct traits<Windows::Foundation::Collections::ValueSet> { using default_interface = Windows::Foundation::Collections::IPropertySet; };

}

namespace Windows::Foundation::Collections {

template <typename D>
struct WINRT_EBO impl_IPropertySet
{
};

}

namespace impl {

template <> struct traits<Windows::Foundation::Collections::IPropertySet>
{
    using abi = ABI::Windows::Foundation::Collections::IPropertySet;
    template <typename D> using consume = Windows::Foundation::Collections::impl_IPropertySet<D>;
};

template <> struct traits<Windows::Foundation::Collections::PropertySet>
{
    using abi = ABI::Windows::Foundation::Collections::PropertySet;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Foundation.Collections.PropertySet"; }
};

template <> struct traits<Windows::Foundation::Collections::StringMap>
{
    using abi = ABI::Windows::Foundation::Collections::StringMap;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Foundation.Collections.StringMap"; }
};

template <> struct traits<Windows::Foundation::Collections::ValueSet>
{
    using abi = ABI::Windows::Foundation::Collections::ValueSet;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Foundation.Collections.ValueSet"; }
};

}

}
