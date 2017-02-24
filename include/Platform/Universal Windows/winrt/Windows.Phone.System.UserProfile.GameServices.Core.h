// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Phone.System.UserProfile.GameServices.Core.3.h"
#include "Windows.Phone.System.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Phone::System::UserProfile::GameServices::Core::IGameService> : produce_base<D, Windows::Phone::System::UserProfile::GameServices::Core::IGameService>
{
    HRESULT __stdcall get_ServiceUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetGamerProfileAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetGamerProfileAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetInstalledGameItemsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetInstalledGameItemsAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPartnerTokenAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> audienceUri, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetPartnerTokenAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&audienceUri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPrivilegesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetPrivilegesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GrantAchievement(uint32_t achievementId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GrantAchievement(achievementId);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GrantAvatarAward(uint32_t avatarAwardId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GrantAvatarAward(avatarAwardId);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PostResult(uint32_t gameVariant, Windows::Phone::System::UserProfile::GameServices::Core::GameServiceScoreKind scoreKind, int64_t scoreValue, Windows::Phone::System::UserProfile::GameServices::Core::GameServiceGameOutcome gameOutcome, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PostResult(gameVariant, scoreKind, scoreValue, gameOutcome, *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::System::UserProfile::GameServices::Core::IGameService2> : produce_base<D, Windows::Phone::System::UserProfile::GameServices::Core::IGameService2>
{
    HRESULT __stdcall abi_NotifyPartnerTokenExpired(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> audienceUri) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyPartnerTokenExpired(*reinterpret_cast<const Windows::Foundation::Uri *>(&audienceUri));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAuthenticationStatus(uint32_t * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().GetAuthenticationStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::System::UserProfile::GameServices::Core::IGameServicePropertyCollection> : produce_base<D, Windows::Phone::System::UserProfile::GameServices::Core::IGameServicePropertyCollection>
{
    HRESULT __stdcall abi_GetPropertyAsync(impl::abi_arg_in<hstring> propertyName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::IInspectable>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetPropertyAsync(*reinterpret_cast<const hstring *>(&propertyName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Phone::System::UserProfile::GameServices::Core {

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::IInspectable> impl_IGameServicePropertyCollection<D>::GetPropertyAsync(hstring_view propertyName) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::IInspectable> operation;
    check_hresult(WINRT_SHIM(IGameServicePropertyCollection)->abi_GetPropertyAsync(get_abi(propertyName), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::Uri impl_IGameService<D>::ServiceUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IGameService)->get_ServiceUri(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection> impl_IGameService<D>::GetGamerProfileAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection> operation;
    check_hresult(WINRT_SHIM(IGameService)->abi_GetGamerProfileAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection> impl_IGameService<D>::GetInstalledGameItemsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection> operation;
    check_hresult(WINRT_SHIM(IGameService)->abi_GetInstalledGameItemsAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IGameService<D>::GetPartnerTokenAsync(const Windows::Foundation::Uri & audienceUri) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IGameService)->abi_GetPartnerTokenAsync(get_abi(audienceUri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IGameService<D>::GetPrivilegesAsync() const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IGameService)->abi_GetPrivilegesAsync(put_abi(operation)));
    return operation;
}

template <typename D> void impl_IGameService<D>::GrantAchievement(uint32_t achievementId) const
{
    check_hresult(WINRT_SHIM(IGameService)->abi_GrantAchievement(achievementId));
}

template <typename D> void impl_IGameService<D>::GrantAvatarAward(uint32_t avatarAwardId) const
{
    check_hresult(WINRT_SHIM(IGameService)->abi_GrantAvatarAward(avatarAwardId));
}

template <typename D> void impl_IGameService<D>::PostResult(uint32_t gameVariant, Windows::Phone::System::UserProfile::GameServices::Core::GameServiceScoreKind scoreKind, int64_t scoreValue, Windows::Phone::System::UserProfile::GameServices::Core::GameServiceGameOutcome gameOutcome, const Windows::Storage::Streams::IBuffer & buffer) const
{
    check_hresult(WINRT_SHIM(IGameService)->abi_PostResult(gameVariant, scoreKind, scoreValue, gameOutcome, get_abi(buffer)));
}

template <typename D> void impl_IGameService2<D>::NotifyPartnerTokenExpired(const Windows::Foundation::Uri & audienceUri) const
{
    check_hresult(WINRT_SHIM(IGameService2)->abi_NotifyPartnerTokenExpired(get_abi(audienceUri)));
}

template <typename D> uint32_t impl_IGameService2<D>::GetAuthenticationStatus() const
{
    uint32_t status {};
    check_hresult(WINRT_SHIM(IGameService2)->abi_GetAuthenticationStatus(&status));
    return status;
}

inline Windows::Foundation::Uri GameService::ServiceUri()
{
    return get_activation_factory<GameService, IGameService>().ServiceUri();
}

inline Windows::Foundation::IAsyncOperation<Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection> GameService::GetGamerProfileAsync()
{
    return get_activation_factory<GameService, IGameService>().GetGamerProfileAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection> GameService::GetInstalledGameItemsAsync()
{
    return get_activation_factory<GameService, IGameService>().GetInstalledGameItemsAsync();
}

inline Windows::Foundation::IAsyncOperation<hstring> GameService::GetPartnerTokenAsync(const Windows::Foundation::Uri & audienceUri)
{
    return get_activation_factory<GameService, IGameService>().GetPartnerTokenAsync(audienceUri);
}

inline Windows::Foundation::IAsyncOperation<hstring> GameService::GetPrivilegesAsync()
{
    return get_activation_factory<GameService, IGameService>().GetPrivilegesAsync();
}

inline void GameService::GrantAchievement(uint32_t achievementId)
{
    get_activation_factory<GameService, IGameService>().GrantAchievement(achievementId);
}

inline void GameService::GrantAvatarAward(uint32_t avatarAwardId)
{
    get_activation_factory<GameService, IGameService>().GrantAvatarAward(avatarAwardId);
}

inline void GameService::PostResult(uint32_t gameVariant, Windows::Phone::System::UserProfile::GameServices::Core::GameServiceScoreKind scoreKind, int64_t scoreValue, Windows::Phone::System::UserProfile::GameServices::Core::GameServiceGameOutcome gameOutcome, const Windows::Storage::Streams::IBuffer & buffer)
{
    get_activation_factory<GameService, IGameService>().PostResult(gameVariant, scoreKind, scoreValue, gameOutcome, buffer);
}

inline void GameService::NotifyPartnerTokenExpired(const Windows::Foundation::Uri & audienceUri)
{
    get_activation_factory<GameService, IGameService2>().NotifyPartnerTokenExpired(audienceUri);
}

inline uint32_t GameService::GetAuthenticationStatus()
{
    return get_activation_factory<GameService, IGameService2>().GetAuthenticationStatus();
}

}

}
#pragma warning(pop)
