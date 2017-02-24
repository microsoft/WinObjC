// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Notifications.3.h"
#include "internal/Windows.UI.Notifications.Management.3.h"
#include "Windows.UI.Notifications.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Notifications::Management::IUserNotificationListener> : produce_base<D, Windows::UI::Notifications::Management::IUserNotificationListener>
{
    HRESULT __stdcall abi_RequestAccessAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAccessAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAccessStatus(Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus * accessStatus) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *accessStatus = detach_abi(this->shim().GetAccessStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_NotificationChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::Management::UserNotificationListener, Windows::UI::Notifications::UserNotificationChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().NotificationChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::Management::UserNotificationListener, Windows::UI::Notifications::UserNotificationChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_NotificationChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotificationChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNotificationsAsync(Windows::UI::Notifications::NotificationKinds kinds, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::UserNotification>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetNotificationsAsync(kinds));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNotification(uint32_t notificationId, impl::abi_arg_out<Windows::UI::Notifications::IUserNotification> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetNotification(notificationId));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearNotifications() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearNotifications();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveNotification(uint32_t notificationId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveNotification(notificationId);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::Management::IUserNotificationListenerStatics> : produce_base<D, Windows::UI::Notifications::Management::IUserNotificationListenerStatics>
{
    HRESULT __stdcall get_Current(impl::abi_arg_out<Windows::UI::Notifications::Management::IUserNotificationListener> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Current());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Notifications::Management {

template <typename D> Windows::UI::Notifications::Management::UserNotificationListener impl_IUserNotificationListenerStatics<D>::Current() const
{
    Windows::UI::Notifications::Management::UserNotificationListener result { nullptr };
    check_hresult(WINRT_SHIM(IUserNotificationListenerStatics)->get_Current(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus> impl_IUserNotificationListener<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus> result;
    check_hresult(WINRT_SHIM(IUserNotificationListener)->abi_RequestAccessAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus impl_IUserNotificationListener<D>::GetAccessStatus() const
{
    Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus accessStatus {};
    check_hresult(WINRT_SHIM(IUserNotificationListener)->abi_GetAccessStatus(&accessStatus));
    return accessStatus;
}

template <typename D> event_token impl_IUserNotificationListener<D>::NotificationChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::Management::UserNotificationListener, Windows::UI::Notifications::UserNotificationChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUserNotificationListener)->add_NotificationChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IUserNotificationListener> impl_IUserNotificationListener<D>::NotificationChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::Management::UserNotificationListener, Windows::UI::Notifications::UserNotificationChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IUserNotificationListener>(this, &ABI::Windows::UI::Notifications::Management::IUserNotificationListener::remove_NotificationChanged, NotificationChanged(handler));
}

template <typename D> void impl_IUserNotificationListener<D>::NotificationChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IUserNotificationListener)->remove_NotificationChanged(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::UserNotification>> impl_IUserNotificationListener<D>::GetNotificationsAsync(Windows::UI::Notifications::NotificationKinds kinds) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::UserNotification>> result;
    check_hresult(WINRT_SHIM(IUserNotificationListener)->abi_GetNotificationsAsync(kinds, put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Notifications::UserNotification impl_IUserNotificationListener<D>::GetNotification(uint32_t notificationId) const
{
    Windows::UI::Notifications::UserNotification result { nullptr };
    check_hresult(WINRT_SHIM(IUserNotificationListener)->abi_GetNotification(notificationId, put_abi(result)));
    return result;
}

template <typename D> void impl_IUserNotificationListener<D>::ClearNotifications() const
{
    check_hresult(WINRT_SHIM(IUserNotificationListener)->abi_ClearNotifications());
}

template <typename D> void impl_IUserNotificationListener<D>::RemoveNotification(uint32_t notificationId) const
{
    check_hresult(WINRT_SHIM(IUserNotificationListener)->abi_RemoveNotification(notificationId));
}

inline Windows::UI::Notifications::Management::UserNotificationListener UserNotificationListener::Current()
{
    return get_activation_factory<UserNotificationListener, IUserNotificationListenerStatics>().Current();
}

}

}
#pragma warning(pop)
