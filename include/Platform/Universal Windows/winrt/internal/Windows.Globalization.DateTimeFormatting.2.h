// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Globalization.DateTimeFormatting.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif


}

namespace Windows::Globalization::DateTimeFormatting {

struct IDateTimeFormatter :
    Windows::Foundation::IInspectable,
    impl::consume<IDateTimeFormatter>
{
    IDateTimeFormatter(std::nullptr_t = nullptr) noexcept {}
};

struct IDateTimeFormatter2 :
    Windows::Foundation::IInspectable,
    impl::consume<IDateTimeFormatter2>
{
    IDateTimeFormatter2(std::nullptr_t = nullptr) noexcept {}
};

struct IDateTimeFormatterFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IDateTimeFormatterFactory>
{
    IDateTimeFormatterFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IDateTimeFormatterStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IDateTimeFormatterStatics>
{
    IDateTimeFormatterStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
