// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.UI.Notifications.3.h"
#include "internal/Windows.Networking.PushNotifications.3.h"
#include "Windows.Networking.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Networking::PushNotifications::IPushNotificationChannel> : produce_base<D, Windows::Networking::PushNotifications::IPushNotificationChannel>
{
    HRESULT __stdcall get_Uri(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExpirationTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExpirationTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Close() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Close();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PushNotificationReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::PushNotifications::PushNotificationChannel, Windows::Networking::PushNotifications::PushNotificationReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PushNotificationReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::PushNotifications::PushNotificationChannel, Windows::Networking::PushNotifications::PushNotificationReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PushNotificationReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PushNotificationReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::PushNotifications::IPushNotificationChannelManagerForUser> : produce_base<D, Windows::Networking::PushNotifications::IPushNotificationChannelManagerForUser>
{
    HRESULT __stdcall abi_CreatePushNotificationChannelForApplicationAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreatePushNotificationChannelForApplicationAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreatePushNotificationChannelForApplicationAsyncWithId(impl::abi_arg_in<hstring> applicationId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreatePushNotificationChannelForApplicationAsync(*reinterpret_cast<const hstring *>(&applicationId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreatePushNotificationChannelForSecondaryTileAsync(impl::abi_arg_in<hstring> tileId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreatePushNotificationChannelForSecondaryTileAsync(*reinterpret_cast<const hstring *>(&tileId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_User(impl::abi_arg_out<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().User());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::PushNotifications::IPushNotificationChannelManagerStatics> : produce_base<D, Windows::Networking::PushNotifications::IPushNotificationChannelManagerStatics>
{
    HRESULT __stdcall abi_CreatePushNotificationChannelForApplicationAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreatePushNotificationChannelForApplicationAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreatePushNotificationChannelForApplicationAsyncWithId(impl::abi_arg_in<hstring> applicationId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreatePushNotificationChannelForApplicationAsync(*reinterpret_cast<const hstring *>(&applicationId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreatePushNotificationChannelForSecondaryTileAsync(impl::abi_arg_in<hstring> tileId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreatePushNotificationChannelForSecondaryTileAsync(*reinterpret_cast<const hstring *>(&tileId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::PushNotifications::IPushNotificationChannelManagerStatics2> : produce_base<D, Windows::Networking::PushNotifications::IPushNotificationChannelManagerStatics2>
{
    HRESULT __stdcall abi_GetForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_out<Windows::Networking::PushNotifications::IPushNotificationChannelManagerForUser> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetForUser(*reinterpret_cast<const Windows::System::User *>(&user)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::PushNotifications::IPushNotificationReceivedEventArgs> : produce_base<D, Windows::Networking::PushNotifications::IPushNotificationReceivedEventArgs>
{
    HRESULT __stdcall put_Cancel(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Cancel(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Cancel(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Cancel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NotificationType(Windows::Networking::PushNotifications::PushNotificationType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NotificationType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToastNotification(impl::abi_arg_out<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToastNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TileNotification(impl::abi_arg_out<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TileNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BadgeNotification(impl::abi_arg_out<Windows::UI::Notifications::IBadgeNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BadgeNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RawNotification(impl::abi_arg_out<Windows::Networking::PushNotifications::IRawNotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RawNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::PushNotifications::IRawNotification> : produce_base<D, Windows::Networking::PushNotifications::IRawNotification>
{
    HRESULT __stdcall get_Content(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Content());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Networking::PushNotifications {

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> impl_IPushNotificationChannelManagerStatics<D>::CreatePushNotificationChannelForApplicationAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> operation;
    check_hresult(WINRT_SHIM(IPushNotificationChannelManagerStatics)->abi_CreatePushNotificationChannelForApplicationAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> impl_IPushNotificationChannelManagerStatics<D>::CreatePushNotificationChannelForApplicationAsync(hstring_view applicationId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> operation;
    check_hresult(WINRT_SHIM(IPushNotificationChannelManagerStatics)->abi_CreatePushNotificationChannelForApplicationAsyncWithId(get_abi(applicationId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> impl_IPushNotificationChannelManagerStatics<D>::CreatePushNotificationChannelForSecondaryTileAsync(hstring_view tileId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> operation;
    check_hresult(WINRT_SHIM(IPushNotificationChannelManagerStatics)->abi_CreatePushNotificationChannelForSecondaryTileAsync(get_abi(tileId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Networking::PushNotifications::PushNotificationChannelManagerForUser impl_IPushNotificationChannelManagerStatics2<D>::GetForUser(const Windows::System::User & user) const
{
    Windows::Networking::PushNotifications::PushNotificationChannelManagerForUser result { nullptr };
    check_hresult(WINRT_SHIM(IPushNotificationChannelManagerStatics2)->abi_GetForUser(get_abi(user), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> impl_IPushNotificationChannelManagerForUser<D>::CreatePushNotificationChannelForApplicationAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> operation;
    check_hresult(WINRT_SHIM(IPushNotificationChannelManagerForUser)->abi_CreatePushNotificationChannelForApplicationAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> impl_IPushNotificationChannelManagerForUser<D>::CreatePushNotificationChannelForApplicationAsync(hstring_view applicationId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> operation;
    check_hresult(WINRT_SHIM(IPushNotificationChannelManagerForUser)->abi_CreatePushNotificationChannelForApplicationAsyncWithId(get_abi(applicationId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> impl_IPushNotificationChannelManagerForUser<D>::CreatePushNotificationChannelForSecondaryTileAsync(hstring_view tileId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> operation;
    check_hresult(WINRT_SHIM(IPushNotificationChannelManagerForUser)->abi_CreatePushNotificationChannelForSecondaryTileAsync(get_abi(tileId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::System::User impl_IPushNotificationChannelManagerForUser<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IPushNotificationChannelManagerForUser)->get_User(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPushNotificationChannel<D>::Uri() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPushNotificationChannel)->get_Uri(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IPushNotificationChannel<D>::ExpirationTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IPushNotificationChannel)->get_ExpirationTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IPushNotificationChannel<D>::Close() const
{
    check_hresult(WINRT_SHIM(IPushNotificationChannel)->abi_Close());
}

template <typename D> event_token impl_IPushNotificationChannel<D>::PushNotificationReceived(const Windows::Foundation::TypedEventHandler<Windows::Networking::PushNotifications::PushNotificationChannel, Windows::Networking::PushNotifications::PushNotificationReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPushNotificationChannel)->add_PushNotificationReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPushNotificationChannel> impl_IPushNotificationChannel<D>::PushNotificationReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::PushNotifications::PushNotificationChannel, Windows::Networking::PushNotifications::PushNotificationReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPushNotificationChannel>(this, &ABI::Windows::Networking::PushNotifications::IPushNotificationChannel::remove_PushNotificationReceived, PushNotificationReceived(handler));
}

template <typename D> void impl_IPushNotificationChannel<D>::PushNotificationReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IPushNotificationChannel)->remove_PushNotificationReceived(token));
}

template <typename D> void impl_IPushNotificationReceivedEventArgs<D>::Cancel(bool value) const
{
    check_hresult(WINRT_SHIM(IPushNotificationReceivedEventArgs)->put_Cancel(value));
}

template <typename D> bool impl_IPushNotificationReceivedEventArgs<D>::Cancel() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPushNotificationReceivedEventArgs)->get_Cancel(&value));
    return value;
}

template <typename D> Windows::Networking::PushNotifications::PushNotificationType impl_IPushNotificationReceivedEventArgs<D>::NotificationType() const
{
    Windows::Networking::PushNotifications::PushNotificationType value {};
    check_hresult(WINRT_SHIM(IPushNotificationReceivedEventArgs)->get_NotificationType(&value));
    return value;
}

template <typename D> Windows::UI::Notifications::ToastNotification impl_IPushNotificationReceivedEventArgs<D>::ToastNotification() const
{
    Windows::UI::Notifications::ToastNotification value { nullptr };
    check_hresult(WINRT_SHIM(IPushNotificationReceivedEventArgs)->get_ToastNotification(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Notifications::TileNotification impl_IPushNotificationReceivedEventArgs<D>::TileNotification() const
{
    Windows::UI::Notifications::TileNotification value { nullptr };
    check_hresult(WINRT_SHIM(IPushNotificationReceivedEventArgs)->get_TileNotification(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Notifications::BadgeNotification impl_IPushNotificationReceivedEventArgs<D>::BadgeNotification() const
{
    Windows::UI::Notifications::BadgeNotification value { nullptr };
    check_hresult(WINRT_SHIM(IPushNotificationReceivedEventArgs)->get_BadgeNotification(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::PushNotifications::RawNotification impl_IPushNotificationReceivedEventArgs<D>::RawNotification() const
{
    Windows::Networking::PushNotifications::RawNotification value { nullptr };
    check_hresult(WINRT_SHIM(IPushNotificationReceivedEventArgs)->get_RawNotification(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRawNotification<D>::Content() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRawNotification)->get_Content(put_abi(value)));
    return value;
}

inline Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> PushNotificationChannelManager::CreatePushNotificationChannelForApplicationAsync()
{
    return get_activation_factory<PushNotificationChannelManager, IPushNotificationChannelManagerStatics>().CreatePushNotificationChannelForApplicationAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> PushNotificationChannelManager::CreatePushNotificationChannelForApplicationAsync(hstring_view applicationId)
{
    return get_activation_factory<PushNotificationChannelManager, IPushNotificationChannelManagerStatics>().CreatePushNotificationChannelForApplicationAsync(applicationId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> PushNotificationChannelManager::CreatePushNotificationChannelForSecondaryTileAsync(hstring_view tileId)
{
    return get_activation_factory<PushNotificationChannelManager, IPushNotificationChannelManagerStatics>().CreatePushNotificationChannelForSecondaryTileAsync(tileId);
}

inline Windows::Networking::PushNotifications::PushNotificationChannelManagerForUser PushNotificationChannelManager::GetForUser(const Windows::System::User & user)
{
    return get_activation_factory<PushNotificationChannelManager, IPushNotificationChannelManagerStatics2>().GetForUser(user);
}

}

}
#pragma warning(pop)
