// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Notifications.Management.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_0fbad8c7_086f_5bf9_81e2_8d79e7184803
#define WINRT_GENERIC_0fbad8c7_086f_5bf9_81e2_8d79e7184803
template <> struct __declspec(uuid("0fbad8c7-086f-5bf9-81e2-8d79e7184803")) __declspec(novtable) IAsyncOperation<winrt::Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus> : impl_IAsyncOperation<winrt::Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus> {};
#endif

#ifndef WINRT_GENERIC_10242902_b897_5507_9922_2c0a7d34464d
#define WINRT_GENERIC_10242902_b897_5507_9922_2c0a7d34464d
template <> struct __declspec(uuid("10242902-b897-5507-9922-2c0a7d34464d")) __declspec(novtable) TypedEventHandler<Windows::UI::Notifications::Management::UserNotificationListener, Windows::UI::Notifications::UserNotificationChangedEventArgs> : impl_TypedEventHandler<Windows::UI::Notifications::Management::UserNotificationListener, Windows::UI::Notifications::UserNotificationChangedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_5a08f98c_8e45_5705_af54_f5418e598392
#define WINRT_GENERIC_5a08f98c_8e45_5705_af54_f5418e598392
template <> struct __declspec(uuid("5a08f98c-8e45-5705-af54-f5418e598392")) __declspec(novtable) IVectorView<Windows::UI::Notifications::UserNotification> : impl_IVectorView<Windows::UI::Notifications::UserNotification> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_f09e843a_13cb_559b_a9fc_015722c2cd57
#define WINRT_GENERIC_f09e843a_13cb_559b_a9fc_015722c2cd57
template <> struct __declspec(uuid("f09e843a-13cb-559b-a9fc-015722c2cd57")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus> : impl_AsyncOperationCompletedHandler<winrt::Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_6ee1200d_dd13_5050_88cb_5352af113fd1
#define WINRT_GENERIC_6ee1200d_dd13_5050_88cb_5352af113fd1
template <> struct __declspec(uuid("6ee1200d-dd13-5050-88cb-5352af113fd1")) __declspec(novtable) IIterator<Windows::UI::Notifications::UserNotification> : impl_IIterator<Windows::UI::Notifications::UserNotification> {};
#endif

#ifndef WINRT_GENERIC_18170480_1bd8_5cd0_bb32_67e71d5b4d7c
#define WINRT_GENERIC_18170480_1bd8_5cd0_bb32_67e71d5b4d7c
template <> struct __declspec(uuid("18170480-1bd8-5cd0-bb32-67e71d5b4d7c")) __declspec(novtable) IIterable<Windows::UI::Notifications::UserNotification> : impl_IIterable<Windows::UI::Notifications::UserNotification> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_bf7f3d3c_230f_54ea_ad74_0cf6c55cd8d1
#define WINRT_GENERIC_bf7f3d3c_230f_54ea_ad74_0cf6c55cd8d1
template <> struct __declspec(uuid("bf7f3d3c-230f-54ea-ad74-0cf6c55cd8d1")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::UserNotification>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::UserNotification>> {};
#endif

#ifndef WINRT_GENERIC_9e42ed08_45b3_5643_b5c7_b216f5781594
#define WINRT_GENERIC_9e42ed08_45b3_5643_b5c7_b216f5781594
template <> struct __declspec(uuid("9e42ed08-45b3-5643-b5c7-b216f5781594")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::UserNotification>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::UserNotification>> {};
#endif


}

namespace Windows::UI::Notifications::Management {

struct IUserNotificationListener :
    Windows::Foundation::IInspectable,
    impl::consume<IUserNotificationListener>
{
    IUserNotificationListener(std::nullptr_t = nullptr) noexcept {}
};

struct IUserNotificationListenerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IUserNotificationListenerStatics>
{
    IUserNotificationListenerStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
