// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Networking::PushNotifications {

struct IPushNotificationChannel;
struct IPushNotificationChannelManagerForUser;
struct IPushNotificationChannelManagerStatics;
struct IPushNotificationChannelManagerStatics2;
struct IPushNotificationReceivedEventArgs;
struct IRawNotification;
struct PushNotificationChannel;
struct PushNotificationChannelManagerForUser;
struct PushNotificationReceivedEventArgs;
struct RawNotification;

}

namespace Windows::Networking::PushNotifications {

struct IPushNotificationChannel;
struct IPushNotificationChannelManagerForUser;
struct IPushNotificationChannelManagerStatics;
struct IPushNotificationChannelManagerStatics2;
struct IPushNotificationReceivedEventArgs;
struct IRawNotification;
struct PushNotificationChannel;
struct PushNotificationChannelManager;
struct PushNotificationChannelManagerForUser;
struct PushNotificationReceivedEventArgs;
struct RawNotification;

}

namespace Windows::Networking::PushNotifications {

template <typename T> struct impl_IPushNotificationChannel;
template <typename T> struct impl_IPushNotificationChannelManagerForUser;
template <typename T> struct impl_IPushNotificationChannelManagerStatics;
template <typename T> struct impl_IPushNotificationChannelManagerStatics2;
template <typename T> struct impl_IPushNotificationReceivedEventArgs;
template <typename T> struct impl_IRawNotification;

}

namespace Windows::Networking::PushNotifications {

enum class PushNotificationType
{
    Toast = 0,
    Tile = 1,
    Badge = 2,
    Raw = 3,
    TileFlyout = 4,
};

}

}
