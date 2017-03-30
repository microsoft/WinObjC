// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.System.UserProfile.GameServices.Core.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Phone::System::UserProfile::GameServices::Core {

struct GameService
{
    GameService() = delete;
    static Windows::Foundation::Uri ServiceUri();
    static Windows::Foundation::IAsyncOperation<Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection> GetGamerProfileAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection> GetInstalledGameItemsAsync();
    static Windows::Foundation::IAsyncOperation<hstring> GetPartnerTokenAsync(const Windows::Foundation::Uri & audienceUri);
    static Windows::Foundation::IAsyncOperation<hstring> GetPrivilegesAsync();
    static void GrantAchievement(uint32_t achievementId);
    static void GrantAvatarAward(uint32_t avatarAwardId);
    static void PostResult(uint32_t gameVariant, Windows::Phone::System::UserProfile::GameServices::Core::GameServiceScoreKind scoreKind, int64_t scoreValue, Windows::Phone::System::UserProfile::GameServices::Core::GameServiceGameOutcome gameOutcome, const Windows::Storage::Streams::IBuffer & buffer);
    static void NotifyPartnerTokenExpired(const Windows::Foundation::Uri & audienceUri);
    static uint32_t GetAuthenticationStatus();
};

struct WINRT_EBO GameServicePropertyCollection :
    Windows::Phone::System::UserProfile::GameServices::Core::IGameServicePropertyCollection
{
    GameServicePropertyCollection(std::nullptr_t) noexcept {}
};

}

}
