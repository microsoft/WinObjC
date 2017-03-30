// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.SocialInfo.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_c210bbd7_2f56_5076_bb0e_b7497726cf95
#define WINRT_GENERIC_c210bbd7_2f56_5076_bb0e_b7497726cf95
template <> struct __declspec(uuid("c210bbd7-2f56-5076-bb0e-b7497726cf95")) __declspec(novtable) IVector<Windows::ApplicationModel::SocialInfo::SocialItemThumbnail> : impl_IVector<Windows::ApplicationModel::SocialInfo::SocialItemThumbnail> {};
#endif

#ifndef WINRT_GENERIC_fabcf39f_fd48_5550_8f47_a0f1573e1f53
#define WINRT_GENERIC_fabcf39f_fd48_5550_8f47_a0f1573e1f53
template <> struct __declspec(uuid("fabcf39f-fd48-5550-8f47-a0f1573e1f53")) __declspec(novtable) IIterator<Windows::ApplicationModel::SocialInfo::SocialItemThumbnail> : impl_IIterator<Windows::ApplicationModel::SocialInfo::SocialItemThumbnail> {};
#endif

#ifndef WINRT_GENERIC_5d102c6d_92c3_59f3_b1dc_5986c56445a5
#define WINRT_GENERIC_5d102c6d_92c3_59f3_b1dc_5986c56445a5
template <> struct __declspec(uuid("5d102c6d-92c3-59f3-b1dc-5986c56445a5")) __declspec(novtable) IIterable<Windows::ApplicationModel::SocialInfo::SocialItemThumbnail> : impl_IIterable<Windows::ApplicationModel::SocialInfo::SocialItemThumbnail> {};
#endif

#ifndef WINRT_GENERIC_9a3e6d46_e880_5deb_9006_92fe5c43ace1
#define WINRT_GENERIC_9a3e6d46_e880_5deb_9006_92fe5c43ace1
template <> struct __declspec(uuid("9a3e6d46-e880-5deb-9006-92fe5c43ace1")) __declspec(novtable) IVectorView<Windows::ApplicationModel::SocialInfo::SocialItemThumbnail> : impl_IVectorView<Windows::ApplicationModel::SocialInfo::SocialItemThumbnail> {};
#endif


}

namespace Windows::ApplicationModel::SocialInfo {

struct ISocialFeedChildItem :
    Windows::Foundation::IInspectable,
    impl::consume<ISocialFeedChildItem>
{
    ISocialFeedChildItem(std::nullptr_t = nullptr) noexcept {}
};

struct ISocialFeedContent :
    Windows::Foundation::IInspectable,
    impl::consume<ISocialFeedContent>
{
    ISocialFeedContent(std::nullptr_t = nullptr) noexcept {}
};

struct ISocialFeedItem :
    Windows::Foundation::IInspectable,
    impl::consume<ISocialFeedItem>
{
    ISocialFeedItem(std::nullptr_t = nullptr) noexcept {}
};

struct ISocialFeedSharedItem :
    Windows::Foundation::IInspectable,
    impl::consume<ISocialFeedSharedItem>
{
    ISocialFeedSharedItem(std::nullptr_t = nullptr) noexcept {}
};

struct ISocialItemThumbnail :
    Windows::Foundation::IInspectable,
    impl::consume<ISocialItemThumbnail>
{
    ISocialItemThumbnail(std::nullptr_t = nullptr) noexcept {}
};

struct ISocialUserInfo :
    Windows::Foundation::IInspectable,
    impl::consume<ISocialUserInfo>
{
    ISocialUserInfo(std::nullptr_t = nullptr) noexcept {}
};

}

}
