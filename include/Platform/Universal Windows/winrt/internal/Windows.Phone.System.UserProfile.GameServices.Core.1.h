// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Phone.System.UserProfile.GameServices.Core.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Phone::System::UserProfile::GameServices::Core {

struct __declspec(uuid("2e2d5098-48a9-4efc-afd6-8e6da09003fb")) __declspec(novtable) IGameService : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServiceUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall abi_GetGamerProfileAsync(Windows::Foundation::IAsyncOperation<Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetInstalledGameItemsAsync(Windows::Foundation::IAsyncOperation<Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetPartnerTokenAsync(Windows::Foundation::IUriRuntimeClass * audienceUri, Windows::Foundation::IAsyncOperation<hstring> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetPrivilegesAsync(Windows::Foundation::IAsyncOperation<hstring> ** operation) = 0;
    virtual HRESULT __stdcall abi_GrantAchievement(uint32_t achievementId) = 0;
    virtual HRESULT __stdcall abi_GrantAvatarAward(uint32_t avatarAwardId) = 0;
    virtual HRESULT __stdcall abi_PostResult(uint32_t gameVariant, winrt::Windows::Phone::System::UserProfile::GameServices::Core::GameServiceScoreKind scoreKind, int64_t scoreValue, winrt::Windows::Phone::System::UserProfile::GameServices::Core::GameServiceGameOutcome gameOutcome, Windows::Storage::Streams::IBuffer * buffer) = 0;
};

struct __declspec(uuid("d2364ef6-ea17-4be5-8d8a-c860885e051f")) __declspec(novtable) IGameService2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_NotifyPartnerTokenExpired(Windows::Foundation::IUriRuntimeClass * audienceUri) = 0;
    virtual HRESULT __stdcall abi_GetAuthenticationStatus(uint32_t * status) = 0;
};

struct __declspec(uuid("07e57fc8-debb-4609-9cc8-529d16bc2bd9")) __declspec(novtable) IGameServicePropertyCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetPropertyAsync(hstring propertyName, Windows::Foundation::IAsyncOperation<Windows::Foundation::IInspectable> ** operation) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection> { using default_interface = Windows::Phone::System::UserProfile::GameServices::Core::IGameServicePropertyCollection; };

}

namespace Windows::Phone::System::UserProfile::GameServices::Core {

template <typename D>
struct WINRT_EBO impl_IGameService
{
    Windows::Foundation::Uri ServiceUri() const;
    Windows::Foundation::IAsyncOperation<Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection> GetGamerProfileAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection> GetInstalledGameItemsAsync() const;
    Windows::Foundation::IAsyncOperation<hstring> GetPartnerTokenAsync(const Windows::Foundation::Uri & audienceUri) const;
    Windows::Foundation::IAsyncOperation<hstring> GetPrivilegesAsync() const;
    void GrantAchievement(uint32_t achievementId) const;
    void GrantAvatarAward(uint32_t avatarAwardId) const;
    void PostResult(uint32_t gameVariant, Windows::Phone::System::UserProfile::GameServices::Core::GameServiceScoreKind scoreKind, int64_t scoreValue, Windows::Phone::System::UserProfile::GameServices::Core::GameServiceGameOutcome gameOutcome, const Windows::Storage::Streams::IBuffer & buffer) const;
};

template <typename D>
struct WINRT_EBO impl_IGameService2
{
    void NotifyPartnerTokenExpired(const Windows::Foundation::Uri & audienceUri) const;
    uint32_t GetAuthenticationStatus() const;
};

template <typename D>
struct WINRT_EBO impl_IGameServicePropertyCollection
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::IInspectable> GetPropertyAsync(hstring_view propertyName) const;
};

}

namespace impl {

template <> struct traits<Windows::Phone::System::UserProfile::GameServices::Core::IGameService>
{
    using abi = ABI::Windows::Phone::System::UserProfile::GameServices::Core::IGameService;
    template <typename D> using consume = Windows::Phone::System::UserProfile::GameServices::Core::impl_IGameService<D>;
};

template <> struct traits<Windows::Phone::System::UserProfile::GameServices::Core::IGameService2>
{
    using abi = ABI::Windows::Phone::System::UserProfile::GameServices::Core::IGameService2;
    template <typename D> using consume = Windows::Phone::System::UserProfile::GameServices::Core::impl_IGameService2<D>;
};

template <> struct traits<Windows::Phone::System::UserProfile::GameServices::Core::IGameServicePropertyCollection>
{
    using abi = ABI::Windows::Phone::System::UserProfile::GameServices::Core::IGameServicePropertyCollection;
    template <typename D> using consume = Windows::Phone::System::UserProfile::GameServices::Core::impl_IGameServicePropertyCollection<D>;
};

template <> struct traits<Windows::Phone::System::UserProfile::GameServices::Core::GameService>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.System.UserProfile.GameServices.Core.GameService"; }
};

template <> struct traits<Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection>
{
    using abi = ABI::Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.System.UserProfile.GameServices.Core.GameServicePropertyCollection"; }
};

}

}
