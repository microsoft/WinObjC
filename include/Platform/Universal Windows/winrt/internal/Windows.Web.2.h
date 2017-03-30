// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Web.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_a8fe0732_556d_5841_b7ee_b3450fb52666
#define WINRT_GENERIC_a8fe0732_556d_5841_b7ee_b3450fb52666
template <> struct __declspec(uuid("a8fe0732-556d-5841-b7ee-b3450fb52666")) __declspec(novtable) IAsyncOperation<Windows::Storage::Streams::IInputStream> : impl_IAsyncOperation<Windows::Storage::Streams::IInputStream> {};
#endif

#ifndef WINRT_GENERIC_d0bd0125_9049_57a3_bd66_e2525d98c814
#define WINRT_GENERIC_d0bd0125_9049_57a3_bd66_e2525d98c814
template <> struct __declspec(uuid("d0bd0125-9049-57a3-bd66-e2525d98c814")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::Streams::IInputStream> : impl_AsyncOperationCompletedHandler<Windows::Storage::Streams::IInputStream> {};
#endif


}

namespace Windows::Web {

struct IUriToStreamResolver :
    Windows::Foundation::IInspectable,
    impl::consume<IUriToStreamResolver>
{
    IUriToStreamResolver(std::nullptr_t = nullptr) noexcept {}
};

struct IWebErrorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IWebErrorStatics>
{
    IWebErrorStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
