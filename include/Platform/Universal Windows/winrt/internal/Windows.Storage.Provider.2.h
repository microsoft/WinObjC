// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.Provider.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_ed56ab72_ebd3_52c8_b0ac_987d30090351
#define WINRT_GENERIC_ed56ab72_ebd3_52c8_b0ac_987d30090351
template <> struct __declspec(uuid("ed56ab72-ebd3-52c8-b0ac-987d30090351")) __declspec(novtable) TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Storage::Provider::FileUpdateRequestedEventArgs> : impl_TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Storage::Provider::FileUpdateRequestedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_45fdd443_c0b9_57b0_a84f_7d876edc3149
#define WINRT_GENERIC_45fdd443_c0b9_57b0_a84f_7d876edc3149
template <> struct __declspec(uuid("45fdd443-c0b9-57b0-a84f-7d876edc3149")) __declspec(novtable) TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Foundation::IInspectable> {};
#endif


}

namespace Windows::Storage::Provider {

struct ICachedFileUpdaterStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICachedFileUpdaterStatics>
{
    ICachedFileUpdaterStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ICachedFileUpdaterUI :
    Windows::Foundation::IInspectable,
    impl::consume<ICachedFileUpdaterUI>
{
    ICachedFileUpdaterUI(std::nullptr_t = nullptr) noexcept {}
};

struct ICachedFileUpdaterUI2 :
    Windows::Foundation::IInspectable,
    impl::consume<ICachedFileUpdaterUI2>,
    impl::require<ICachedFileUpdaterUI2, Windows::Storage::Provider::ICachedFileUpdaterUI>
{
    ICachedFileUpdaterUI2(std::nullptr_t = nullptr) noexcept {}
};

struct IFileUpdateRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IFileUpdateRequest>
{
    IFileUpdateRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IFileUpdateRequest2 :
    Windows::Foundation::IInspectable,
    impl::consume<IFileUpdateRequest2>,
    impl::require<IFileUpdateRequest2, Windows::Storage::Provider::IFileUpdateRequest>
{
    IFileUpdateRequest2(std::nullptr_t = nullptr) noexcept {}
};

struct IFileUpdateRequestDeferral :
    Windows::Foundation::IInspectable,
    impl::consume<IFileUpdateRequestDeferral>
{
    IFileUpdateRequestDeferral(std::nullptr_t = nullptr) noexcept {}
};

struct IFileUpdateRequestedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IFileUpdateRequestedEventArgs>
{
    IFileUpdateRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

}

}
