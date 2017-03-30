// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Services.Maps.LocalSearch.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_548cefbd_bc8a_5fa0_8df2_957440fc8bf4
#define WINRT_GENERIC_548cefbd_bc8a_5fa0_8df2_957440fc8bf4
template <> struct __declspec(uuid("548cefbd-bc8a-5fa0-8df2-957440fc8bf4")) __declspec(novtable) IReference<int32_t> : impl_IReference<int32_t> {};
#endif

#ifndef WINRT_GENERIC_2f2d6c29_5473_5f3e_92e7_96572bb990e2
#define WINRT_GENERIC_2f2d6c29_5473_5f3e_92e7_96572bb990e2
template <> struct __declspec(uuid("2f2d6c29-5473-5f3e-92e7-96572bb990e2")) __declspec(novtable) IReference<double> : impl_IReference<double> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_619192f2_4f9d_5629_ab01_b18512503d73
#define WINRT_GENERIC_619192f2_4f9d_5629_ab01_b18512503d73
template <> struct __declspec(uuid("619192f2-4f9d-5629-ab01-b18512503d73")) __declspec(novtable) IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> : impl_IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_08e69b32_f420_5280_a721_075b4fd03d94
#define WINRT_GENERIC_08e69b32_f420_5280_a721_075b4fd03d94
template <> struct __declspec(uuid("08e69b32-f420-5280-a721-075b4fd03d94")) __declspec(novtable) IAsyncOperation<Windows::Services::Maps::LocalSearch::LocalLocationFinderResult> : impl_IAsyncOperation<Windows::Services::Maps::LocalSearch::LocalLocationFinderResult> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_65535172_cd91_5b4c_aa60_dab146301284
#define WINRT_GENERIC_65535172_cd91_5b4c_aa60_dab146301284
template <> struct __declspec(uuid("65535172-cd91-5b4c-aa60-dab146301284")) __declspec(novtable) IVectorView<Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem> : impl_IVectorView<Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem> {};
#endif

#ifndef WINRT_GENERIC_a23c2e87_a8e7_568f_96a1_69e98f86b9d3
#define WINRT_GENERIC_a23c2e87_a8e7_568f_96a1_69e98f86b9d3
template <> struct __declspec(uuid("a23c2e87-a8e7-568f-96a1-69e98f86b9d3")) __declspec(novtable) IIterator<Windows::Services::Maps::LocalSearch::LocalLocation> : impl_IIterator<Windows::Services::Maps::LocalSearch::LocalLocation> {};
#endif

#ifndef WINRT_GENERIC_5474eefb_60f4_58ac_89e2_6e83f79fa76c
#define WINRT_GENERIC_5474eefb_60f4_58ac_89e2_6e83f79fa76c
template <> struct __declspec(uuid("5474eefb-60f4-58ac-89e2-6e83f79fa76c")) __declspec(novtable) IIterable<Windows::Services::Maps::LocalSearch::LocalLocation> : impl_IIterable<Windows::Services::Maps::LocalSearch::LocalLocation> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_7b4a1b93_2943_5e50_a010_ee9aec1bbfe7
#define WINRT_GENERIC_7b4a1b93_2943_5e50_a010_ee9aec1bbfe7
template <> struct __declspec(uuid("7b4a1b93-2943-5e50-a010-ee9aec1bbfe7")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Services::Maps::LocalSearch::LocalLocationFinderResult> : impl_AsyncOperationCompletedHandler<Windows::Services::Maps::LocalSearch::LocalLocationFinderResult> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_3f9ba5c0_b2dc_5777_a81e_b0a2839b152b
#define WINRT_GENERIC_3f9ba5c0_b2dc_5777_a81e_b0a2839b152b
template <> struct __declspec(uuid("3f9ba5c0-b2dc-5777-a81e-b0a2839b152b")) __declspec(novtable) IIterator<Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem> : impl_IIterator<Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem> {};
#endif

#ifndef WINRT_GENERIC_f298f515_b9bd_5297_b8bd_1c0040daac76
#define WINRT_GENERIC_f298f515_b9bd_5297_b8bd_1c0040daac76
template <> struct __declspec(uuid("f298f515-b9bd-5297-b8bd-1c0040daac76")) __declspec(novtable) IIterable<Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem> : impl_IIterable<Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem> {};
#endif


}

namespace Windows::Services::Maps::LocalSearch {

struct ILocalCategoriesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ILocalCategoriesStatics>
{
    ILocalCategoriesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ILocalLocation :
    Windows::Foundation::IInspectable,
    impl::consume<ILocalLocation>
{
    ILocalLocation(std::nullptr_t = nullptr) noexcept {}
};

struct ILocalLocation2 :
    Windows::Foundation::IInspectable,
    impl::consume<ILocalLocation2>
{
    ILocalLocation2(std::nullptr_t = nullptr) noexcept {}
};

struct ILocalLocationFinderResult :
    Windows::Foundation::IInspectable,
    impl::consume<ILocalLocationFinderResult>
{
    ILocalLocationFinderResult(std::nullptr_t = nullptr) noexcept {}
};

struct ILocalLocationFinderStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ILocalLocationFinderStatics>
{
    ILocalLocationFinderStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ILocalLocationHoursOfOperationItem :
    Windows::Foundation::IInspectable,
    impl::consume<ILocalLocationHoursOfOperationItem>
{
    ILocalLocationHoursOfOperationItem(std::nullptr_t = nullptr) noexcept {}
};

struct ILocalLocationRatingInfo :
    Windows::Foundation::IInspectable,
    impl::consume<ILocalLocationRatingInfo>
{
    ILocalLocationRatingInfo(std::nullptr_t = nullptr) noexcept {}
};

}

}
