// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.SocialInfo.Provider.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::SocialInfo::Provider {

struct WINRT_EBO SocialDashboardItemUpdater :
    Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater
{
    SocialDashboardItemUpdater(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SocialFeedUpdater :
    Windows::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater
{
    SocialFeedUpdater(std::nullptr_t) noexcept {}
};

struct SocialInfoProviderManager
{
    SocialInfoProviderManager() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater> CreateSocialFeedUpdaterAsync(Windows::ApplicationModel::SocialInfo::SocialFeedKind kind, Windows::ApplicationModel::SocialInfo::SocialFeedUpdateMode mode, hstring_view ownerRemoteId);
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater> CreateDashboardItemUpdaterAsync(hstring_view ownerRemoteId);
    static void UpdateBadgeCountValue(hstring_view itemRemoteId, int32_t newCount);
    static void ReportNewContentAvailable(hstring_view contactRemoteId, Windows::ApplicationModel::SocialInfo::SocialFeedKind kind);
    static Windows::Foundation::IAsyncOperation<bool> ProvisionAsync();
    static Windows::Foundation::IAsyncAction DeprovisionAsync();
};

}

}
