// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Markup.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2736b66b_daa3_5e0c_9842_6a0f44b5440b
#define WINRT_GENERIC_2736b66b_daa3_5e0c_9842_6a0f44b5440b
template <> struct __declspec(uuid("2736b66b-daa3-5e0c-9842-6a0f44b5440b")) __declspec(novtable) IVector<Windows::Storage::Streams::IRandomAccessStream> : impl_IVector<Windows::Storage::Streams::IRandomAccessStream> {};
#endif

#ifndef WINRT_GENERIC_c875446a_587f_58da_897e_3bbe5ec7c30b
#define WINRT_GENERIC_c875446a_587f_58da_897e_3bbe5ec7c30b
template <> struct __declspec(uuid("c875446a-587f-58da-897e-3bbe5ec7c30b")) __declspec(novtable) IIterator<Windows::Storage::Streams::IRandomAccessStream> : impl_IIterator<Windows::Storage::Streams::IRandomAccessStream> {};
#endif

#ifndef WINRT_GENERIC_ba666a00_1555_5df4_81a5_07d23f7ffceb
#define WINRT_GENERIC_ba666a00_1555_5df4_81a5_07d23f7ffceb
template <> struct __declspec(uuid("ba666a00-1555-5df4-81a5-07d23f7ffceb")) __declspec(novtable) IIterable<Windows::Storage::Streams::IRandomAccessStream> : impl_IIterable<Windows::Storage::Streams::IRandomAccessStream> {};
#endif

#ifndef WINRT_GENERIC_92cd0a46_2266_5cd6_9293_e111299f2793
#define WINRT_GENERIC_92cd0a46_2266_5cd6_9293_e111299f2793
template <> struct __declspec(uuid("92cd0a46-2266-5cd6-9293-e111299f2793")) __declspec(novtable) IVectorView<Windows::Storage::Streams::IRandomAccessStream> : impl_IVectorView<Windows::Storage::Streams::IRandomAccessStream> {};
#endif


}

namespace Windows::UI::Xaml::Markup {

struct IComponentConnector :
    Windows::Foundation::IInspectable,
    impl::consume<IComponentConnector>
{
    IComponentConnector(std::nullptr_t = nullptr) noexcept {}
};

struct IComponentConnector2 :
    Windows::Foundation::IInspectable,
    impl::consume<IComponentConnector2>
{
    IComponentConnector2(std::nullptr_t = nullptr) noexcept {}
};

struct IDataTemplateComponent :
    Windows::Foundation::IInspectable,
    impl::consume<IDataTemplateComponent>
{
    IDataTemplateComponent(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlBinaryWriter :
    Windows::Foundation::IInspectable,
    impl::consume<IXamlBinaryWriter>
{
    IXamlBinaryWriter(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlBinaryWriterStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IXamlBinaryWriterStatics>
{
    IXamlBinaryWriterStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlBindingHelper :
    Windows::Foundation::IInspectable,
    impl::consume<IXamlBindingHelper>
{
    IXamlBindingHelper(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlBindingHelperStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IXamlBindingHelperStatics>
{
    IXamlBindingHelperStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlMember :
    Windows::Foundation::IInspectable,
    impl::consume<IXamlMember>
{
    IXamlMember(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlMetadataProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IXamlMetadataProvider>
{
    IXamlMetadataProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlReader :
    Windows::Foundation::IInspectable,
    impl::consume<IXamlReader>
{
    IXamlReader(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlReaderStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IXamlReaderStatics>
{
    IXamlReaderStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlType :
    Windows::Foundation::IInspectable,
    impl::consume<IXamlType>
{
    IXamlType(std::nullptr_t = nullptr) noexcept {}
};

}

}
