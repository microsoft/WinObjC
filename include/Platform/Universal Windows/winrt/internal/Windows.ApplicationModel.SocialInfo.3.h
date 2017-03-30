// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.SocialInfo.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::SocialInfo {

struct WINRT_EBO SocialFeedChildItem :
    Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem
{
    SocialFeedChildItem(std::nullptr_t) noexcept {}
    SocialFeedChildItem();
};

struct WINRT_EBO SocialFeedContent :
    Windows::ApplicationModel::SocialInfo::ISocialFeedContent
{
    SocialFeedContent(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SocialFeedItem :
    Windows::ApplicationModel::SocialInfo::ISocialFeedItem
{
    SocialFeedItem(std::nullptr_t) noexcept {}
    SocialFeedItem();
};

struct WINRT_EBO SocialFeedSharedItem :
    Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem
{
    SocialFeedSharedItem(std::nullptr_t) noexcept {}
    SocialFeedSharedItem();
};

struct WINRT_EBO SocialItemThumbnail :
    Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail
{
    SocialItemThumbnail(std::nullptr_t) noexcept {}
    SocialItemThumbnail();
};

struct WINRT_EBO SocialUserInfo :
    Windows::ApplicationModel::SocialInfo::ISocialUserInfo
{
    SocialUserInfo(std::nullptr_t) noexcept {}
};

}

}
