// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::SocialInfo::Provider {

struct ISocialDashboardItemUpdater;
struct ISocialFeedUpdater;
struct ISocialInfoProviderManagerStatics;
struct SocialDashboardItemUpdater;
struct SocialFeedUpdater;

}

namespace Windows::ApplicationModel::SocialInfo::Provider {

struct ISocialDashboardItemUpdater;
struct ISocialFeedUpdater;
struct ISocialInfoProviderManagerStatics;
struct SocialDashboardItemUpdater;
struct SocialFeedUpdater;
struct SocialInfoProviderManager;

}

namespace Windows::ApplicationModel::SocialInfo::Provider {

template <typename T> struct impl_ISocialDashboardItemUpdater;
template <typename T> struct impl_ISocialFeedUpdater;
template <typename T> struct impl_ISocialInfoProviderManagerStatics;

}

}
