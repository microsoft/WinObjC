// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Networking.PushNotifications.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_70945a09_331a_5e40_b854_66b7a3233bab
#define WINRT_GENERIC_70945a09_331a_5e40_b854_66b7a3233bab
template <> struct __declspec(uuid("70945a09-331a-5e40-b854-66b7a3233bab")) __declspec(novtable) IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> : impl_IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> {};
#endif

#ifndef WINRT_GENERIC_55fa217d_1fc3_5863_b980_7094d4379694
#define WINRT_GENERIC_55fa217d_1fc3_5863_b980_7094d4379694
template <> struct __declspec(uuid("55fa217d-1fc3-5863-b980-7094d4379694")) __declspec(novtable) TypedEventHandler<Windows::Networking::PushNotifications::PushNotificationChannel, Windows::Networking::PushNotifications::PushNotificationReceivedEventArgs> : impl_TypedEventHandler<Windows::Networking::PushNotifications::PushNotificationChannel, Windows::Networking::PushNotifications::PushNotificationReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_cf7c902f_0f0d_5b22_90b1_85141b5816cd
#define WINRT_GENERIC_cf7c902f_0f0d_5b22_90b1_85141b5816cd
template <> struct __declspec(uuid("cf7c902f-0f0d-5b22-90b1-85141b5816cd")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Networking::PushNotifications::PushNotificationChannel> : impl_AsyncOperationCompletedHandler<Windows::Networking::PushNotifications::PushNotificationChannel> {};
#endif


}

namespace Windows::Networking::PushNotifications {

struct IPushNotificationChannel :
    Windows::Foundation::IInspectable,
    impl::consume<IPushNotificationChannel>
{
    IPushNotificationChannel(std::nullptr_t = nullptr) noexcept {}
};

struct IPushNotificationChannelManagerForUser :
    Windows::Foundation::IInspectable,
    impl::consume<IPushNotificationChannelManagerForUser>
{
    IPushNotificationChannelManagerForUser(std::nullptr_t = nullptr) noexcept {}
};

struct IPushNotificationChannelManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPushNotificationChannelManagerStatics>
{
    IPushNotificationChannelManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPushNotificationChannelManagerStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IPushNotificationChannelManagerStatics2>
{
    IPushNotificationChannelManagerStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IPushNotificationReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPushNotificationReceivedEventArgs>
{
    IPushNotificationReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IRawNotification :
    Windows::Foundation::IInspectable,
    impl::consume<IRawNotification>
{
    IRawNotification(std::nullptr_t = nullptr) noexcept {}
};

}

}
