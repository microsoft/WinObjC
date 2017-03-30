// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Networking.PushNotifications.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Networking::PushNotifications {

struct WINRT_EBO PushNotificationChannel :
    Windows::Networking::PushNotifications::IPushNotificationChannel
{
    PushNotificationChannel(std::nullptr_t) noexcept {}
};

struct PushNotificationChannelManager
{
    PushNotificationChannelManager() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> CreatePushNotificationChannelForApplicationAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> CreatePushNotificationChannelForApplicationAsync(hstring_view applicationId);
    static Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> CreatePushNotificationChannelForSecondaryTileAsync(hstring_view tileId);
    static Windows::Networking::PushNotifications::PushNotificationChannelManagerForUser GetForUser(const Windows::System::User & user);
};

struct WINRT_EBO PushNotificationChannelManagerForUser :
    Windows::Networking::PushNotifications::IPushNotificationChannelManagerForUser
{
    PushNotificationChannelManagerForUser(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PushNotificationReceivedEventArgs :
    Windows::Networking::PushNotifications::IPushNotificationReceivedEventArgs
{
    PushNotificationReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RawNotification :
    Windows::Networking::PushNotifications::IRawNotification
{
    RawNotification(std::nullptr_t) noexcept {}
};

}

}
