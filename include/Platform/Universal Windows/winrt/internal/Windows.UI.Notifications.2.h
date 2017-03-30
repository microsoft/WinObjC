// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Notifications.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_f6d1f700_49c2_52ae_8154_826f9908773c
#define WINRT_GENERIC_f6d1f700_49c2_52ae_8154_826f9908773c
template <> struct __declspec(uuid("f6d1f700-49c2-52ae-8154-826f9908773c")) __declspec(novtable) IMap<hstring, hstring> : impl_IMap<hstring, hstring> {};
#endif

#ifndef WINRT_GENERIC_60310303_49c5_52e6_abc6_a9b36eccc716
#define WINRT_GENERIC_60310303_49c5_52e6_abc6_a9b36eccc716
template <> struct __declspec(uuid("60310303-49c5-52e6-abc6-a9b36eccc716")) __declspec(novtable) IKeyValuePair<hstring, hstring> : impl_IKeyValuePair<hstring, hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5541d8a7_497c_5aa4_86fc_7713adbf2a2c
#define WINRT_GENERIC_5541d8a7_497c_5aa4_86fc_7713adbf2a2c
template <> struct __declspec(uuid("5541d8a7-497c-5aa4-86fc-7713adbf2a2c")) __declspec(novtable) IReference<Windows::Foundation::DateTime> : impl_IReference<Windows::Foundation::DateTime> {};
#endif

#ifndef WINRT_GENERIC_604d0c4c_91de_5c2a_935f_362f13eaf800
#define WINRT_GENERIC_604d0c4c_91de_5c2a_935f_362f13eaf800
template <> struct __declspec(uuid("604d0c4c-91de-5c2a-935f-362f13eaf800")) __declspec(novtable) IReference<Windows::Foundation::TimeSpan> : impl_IReference<Windows::Foundation::TimeSpan> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_b0d63b78_78ad_5e31_b6d8_e32a0e16c447
#define WINRT_GENERIC_b0d63b78_78ad_5e31_b6d8_e32a0e16c447
template <> struct __declspec(uuid("b0d63b78-78ad-5e31-b6d8-e32a0e16c447")) __declspec(novtable) IIterable<Windows::Foundation::Uri> : impl_IIterable<Windows::Foundation::Uri> {};
#endif

#ifndef WINRT_GENERIC_ac7f26f2_feb7_5b2a_8ac4_345bc62caede
#define WINRT_GENERIC_ac7f26f2_feb7_5b2a_8ac4_345bc62caede
template <> struct __declspec(uuid("ac7f26f2-feb7-5b2a-8ac4-345bc62caede")) __declspec(novtable) IMapView<hstring, hstring> : impl_IMapView<hstring, hstring> {};
#endif

#ifndef WINRT_GENERIC_7f7d8ad7_b4d2_5a03_be6f_2b89875fb32d
#define WINRT_GENERIC_7f7d8ad7_b4d2_5a03_be6f_2b89875fb32d
template <> struct __declspec(uuid("7f7d8ad7-b4d2-5a03-be6f-2b89875fb32d")) __declspec(novtable) IVector<Windows::UI::Notifications::NotificationBinding> : impl_IVector<Windows::UI::Notifications::NotificationBinding> {};
#endif

#ifndef WINRT_GENERIC_b60de92b_4e12_55af_b42f_afe2d70ba278
#define WINRT_GENERIC_b60de92b_4e12_55af_b42f_afe2d70ba278
template <> struct __declspec(uuid("b60de92b-4e12-55af-b42f-afe2d70ba278")) __declspec(novtable) IVectorView<Windows::UI::Notifications::AdaptiveNotificationText> : impl_IVectorView<Windows::UI::Notifications::AdaptiveNotificationText> {};
#endif

#ifndef WINRT_GENERIC_4f729c64_a213_52e9_af8b_58adca3e597f
#define WINRT_GENERIC_4f729c64_a213_52e9_af8b_58adca3e597f
template <> struct __declspec(uuid("4f729c64-a213-52e9-af8b-58adca3e597f")) __declspec(novtable) IVectorView<Windows::UI::Notifications::ScheduledTileNotification> : impl_IVectorView<Windows::UI::Notifications::ScheduledTileNotification> {};
#endif

#ifndef WINRT_GENERIC_ba0aff1f_6a8a_5a7e_a9f7_505b6266a436
#define WINRT_GENERIC_ba0aff1f_6a8a_5a7e_a9f7_505b6266a436
template <> struct __declspec(uuid("ba0aff1f-6a8a-5a7e-a9f7-505b6266a436")) __declspec(novtable) IVectorView<Windows::UI::Notifications::ScheduledToastNotification> : impl_IVectorView<Windows::UI::Notifications::ScheduledToastNotification> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_61c2402f_0ed0_5a18_ab69_59f4aa99a368
#define WINRT_GENERIC_61c2402f_0ed0_5a18_ab69_59f4aa99a368
template <> struct __declspec(uuid("61c2402f-0ed0-5a18-ab69-59f4aa99a368")) __declspec(novtable) TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastDismissedEventArgs> : impl_TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastDismissedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_ab54de2d_97d9_5528_b6ad_105afe156530
#define WINRT_GENERIC_ab54de2d_97d9_5528_b6ad_105afe156530
template <> struct __declspec(uuid("ab54de2d-97d9-5528-b6ad-105afe156530")) __declspec(novtable) TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_95e3e803_c969_5e3a_9753_ea2ad22a9a33
#define WINRT_GENERIC_95e3e803_c969_5e3a_9753_ea2ad22a9a33
template <> struct __declspec(uuid("95e3e803-c969-5e3a-9753-ea2ad22a9a33")) __declspec(novtable) TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastFailedEventArgs> : impl_TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastFailedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_a819f3de_60aa_5159_8407_f0a7fb1f6832
#define WINRT_GENERIC_a819f3de_60aa_5159_8407_f0a7fb1f6832
template <> struct __declspec(uuid("a819f3de-60aa-5159-8407-f0a7fb1f6832")) __declspec(novtable) IVectorView<Windows::UI::Notifications::ToastNotification> : impl_IVectorView<Windows::UI::Notifications::ToastNotification> {};
#endif

#ifndef WINRT_GENERIC_1c157d0f_5efe_5cec_bbd6_0c6ce9af07a5
#define WINRT_GENERIC_1c157d0f_5efe_5cec_bbd6_0c6ce9af07a5
template <> struct __declspec(uuid("1c157d0f-5efe-5cec-bbd6-0c6ce9af07a5")) __declspec(novtable) IIterator<Windows::Foundation::Uri> : impl_IIterator<Windows::Foundation::Uri> {};
#endif

#ifndef WINRT_GENERIC_66187f56_9ee1_5c48_82da_6cb9ddf879e7
#define WINRT_GENERIC_66187f56_9ee1_5c48_82da_6cb9ddf879e7
template <> struct __declspec(uuid("66187f56-9ee1-5c48-82da-6cb9ddf879e7")) __declspec(novtable) IIterator<Windows::UI::Notifications::NotificationBinding> : impl_IIterator<Windows::UI::Notifications::NotificationBinding> {};
#endif

#ifndef WINRT_GENERIC_e8d9489c_635e_5153_8ab7_389f2ee9faca
#define WINRT_GENERIC_e8d9489c_635e_5153_8ab7_389f2ee9faca
template <> struct __declspec(uuid("e8d9489c-635e-5153-8ab7-389f2ee9faca")) __declspec(novtable) IIterable<Windows::UI::Notifications::NotificationBinding> : impl_IIterable<Windows::UI::Notifications::NotificationBinding> {};
#endif

#ifndef WINRT_GENERIC_9e4d0240_6d5c_582a_a29d_734e84750738
#define WINRT_GENERIC_9e4d0240_6d5c_582a_a29d_734e84750738
template <> struct __declspec(uuid("9e4d0240-6d5c-582a-a29d-734e84750738")) __declspec(novtable) IVectorView<Windows::UI::Notifications::NotificationBinding> : impl_IVectorView<Windows::UI::Notifications::NotificationBinding> {};
#endif

#ifndef WINRT_GENERIC_18015daa_cbc3_5a51_9f4b_3c069135b0e0
#define WINRT_GENERIC_18015daa_cbc3_5a51_9f4b_3c069135b0e0
template <> struct __declspec(uuid("18015daa-cbc3-5a51-9f4b-3c069135b0e0")) __declspec(novtable) IIterator<Windows::UI::Notifications::AdaptiveNotificationText> : impl_IIterator<Windows::UI::Notifications::AdaptiveNotificationText> {};
#endif

#ifndef WINRT_GENERIC_0343e8f2_ca4c_5f40_b8d1_3ff47047ce43
#define WINRT_GENERIC_0343e8f2_ca4c_5f40_b8d1_3ff47047ce43
template <> struct __declspec(uuid("0343e8f2-ca4c-5f40-b8d1-3ff47047ce43")) __declspec(novtable) IIterable<Windows::UI::Notifications::AdaptiveNotificationText> : impl_IIterable<Windows::UI::Notifications::AdaptiveNotificationText> {};
#endif

#ifndef WINRT_GENERIC_5665e491_6543_5036_935f_b5157950b359
#define WINRT_GENERIC_5665e491_6543_5036_935f_b5157950b359
template <> struct __declspec(uuid("5665e491-6543-5036-935f-b5157950b359")) __declspec(novtable) IIterator<Windows::UI::Notifications::ScheduledTileNotification> : impl_IIterator<Windows::UI::Notifications::ScheduledTileNotification> {};
#endif

#ifndef WINRT_GENERIC_4b60d1e5_52ae_5766_9720_be4ad086f952
#define WINRT_GENERIC_4b60d1e5_52ae_5766_9720_be4ad086f952
template <> struct __declspec(uuid("4b60d1e5-52ae-5766-9720-be4ad086f952")) __declspec(novtable) IIterable<Windows::UI::Notifications::ScheduledTileNotification> : impl_IIterable<Windows::UI::Notifications::ScheduledTileNotification> {};
#endif

#ifndef WINRT_GENERIC_304238b6_888a_5dd2_96cd_bfca8927483b
#define WINRT_GENERIC_304238b6_888a_5dd2_96cd_bfca8927483b
template <> struct __declspec(uuid("304238b6-888a-5dd2-96cd-bfca8927483b")) __declspec(novtable) IIterator<Windows::UI::Notifications::ScheduledToastNotification> : impl_IIterator<Windows::UI::Notifications::ScheduledToastNotification> {};
#endif

#ifndef WINRT_GENERIC_7a7b2a51_c182_5846_a861_4f9c036f24ad
#define WINRT_GENERIC_7a7b2a51_c182_5846_a861_4f9c036f24ad
template <> struct __declspec(uuid("7a7b2a51-c182-5846-a861-4f9c036f24ad")) __declspec(novtable) IIterable<Windows::UI::Notifications::ScheduledToastNotification> : impl_IIterable<Windows::UI::Notifications::ScheduledToastNotification> {};
#endif

#ifndef WINRT_GENERIC_fe1e726a_3aa9_5d98_b19b_97e3e17eec7b
#define WINRT_GENERIC_fe1e726a_3aa9_5d98_b19b_97e3e17eec7b
template <> struct __declspec(uuid("fe1e726a-3aa9-5d98-b19b-97e3e17eec7b")) __declspec(novtable) IIterator<Windows::UI::Notifications::ToastNotification> : impl_IIterator<Windows::UI::Notifications::ToastNotification> {};
#endif

#ifndef WINRT_GENERIC_52c9428b_d37a_554d_bf55_b8685d5f552d
#define WINRT_GENERIC_52c9428b_d37a_554d_bf55_b8685d5f552d
template <> struct __declspec(uuid("52c9428b-d37a-554d-bf55-b8685d5f552d")) __declspec(novtable) IIterable<Windows::UI::Notifications::ToastNotification> : impl_IIterable<Windows::UI::Notifications::ToastNotification> {};
#endif

#ifndef WINRT_GENERIC_e9bdaaf0_cbf6_5c72_be90_29cbf3a1319b
#define WINRT_GENERIC_e9bdaaf0_cbf6_5c72_be90_29cbf3a1319b
template <> struct __declspec(uuid("e9bdaaf0-cbf6-5c72-be90-29cbf3a1319b")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> {};
#endif

#ifndef WINRT_GENERIC_05eb86f1_7140_5517_b88d_cbaebe57e6b1
#define WINRT_GENERIC_05eb86f1_7140_5517_b88d_cbaebe57e6b1
template <> struct __declspec(uuid("05eb86f1-7140-5517-b88d-cbaebe57e6b1")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> {};
#endif


}

namespace Windows::UI::Notifications {

struct IAdaptiveNotificationContent :
    Windows::Foundation::IInspectable,
    impl::consume<IAdaptiveNotificationContent>
{
    IAdaptiveNotificationContent(std::nullptr_t = nullptr) noexcept {}
};

struct IAdaptiveNotificationText :
    Windows::Foundation::IInspectable,
    impl::consume<IAdaptiveNotificationText>,
    impl::require<IAdaptiveNotificationText, Windows::UI::Notifications::IAdaptiveNotificationContent>
{
    IAdaptiveNotificationText(std::nullptr_t = nullptr) noexcept {}
};

struct IBadgeNotification :
    Windows::Foundation::IInspectable,
    impl::consume<IBadgeNotification>
{
    IBadgeNotification(std::nullptr_t = nullptr) noexcept {}
};

struct IBadgeNotificationFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IBadgeNotificationFactory>
{
    IBadgeNotificationFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IBadgeUpdateManagerForUser :
    Windows::Foundation::IInspectable,
    impl::consume<IBadgeUpdateManagerForUser>
{
    IBadgeUpdateManagerForUser(std::nullptr_t = nullptr) noexcept {}
};

struct IBadgeUpdateManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IBadgeUpdateManagerStatics>
{
    IBadgeUpdateManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IBadgeUpdateManagerStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IBadgeUpdateManagerStatics2>
{
    IBadgeUpdateManagerStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IBadgeUpdater :
    Windows::Foundation::IInspectable,
    impl::consume<IBadgeUpdater>
{
    IBadgeUpdater(std::nullptr_t = nullptr) noexcept {}
};

struct IKnownAdaptiveNotificationHintsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IKnownAdaptiveNotificationHintsStatics>
{
    IKnownAdaptiveNotificationHintsStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IKnownAdaptiveNotificationTextStylesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IKnownAdaptiveNotificationTextStylesStatics>
{
    IKnownAdaptiveNotificationTextStylesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IKnownNotificationBindingsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IKnownNotificationBindingsStatics>
{
    IKnownNotificationBindingsStatics(std::nullptr_t = nullptr) noexcept {}
};

struct INotification :
    Windows::Foundation::IInspectable,
    impl::consume<INotification>
{
    INotification(std::nullptr_t = nullptr) noexcept {}
};

struct INotificationBinding :
    Windows::Foundation::IInspectable,
    impl::consume<INotificationBinding>
{
    INotificationBinding(std::nullptr_t = nullptr) noexcept {}
};

struct INotificationVisual :
    Windows::Foundation::IInspectable,
    impl::consume<INotificationVisual>
{
    INotificationVisual(std::nullptr_t = nullptr) noexcept {}
};

struct IScheduledTileNotification :
    Windows::Foundation::IInspectable,
    impl::consume<IScheduledTileNotification>
{
    IScheduledTileNotification(std::nullptr_t = nullptr) noexcept {}
};

struct IScheduledTileNotificationFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IScheduledTileNotificationFactory>
{
    IScheduledTileNotificationFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IScheduledToastNotification :
    Windows::Foundation::IInspectable,
    impl::consume<IScheduledToastNotification>
{
    IScheduledToastNotification(std::nullptr_t = nullptr) noexcept {}
};

struct IScheduledToastNotification2 :
    Windows::Foundation::IInspectable,
    impl::consume<IScheduledToastNotification2>
{
    IScheduledToastNotification2(std::nullptr_t = nullptr) noexcept {}
};

struct IScheduledToastNotification3 :
    Windows::Foundation::IInspectable,
    impl::consume<IScheduledToastNotification3>
{
    IScheduledToastNotification3(std::nullptr_t = nullptr) noexcept {}
};

struct IScheduledToastNotificationFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IScheduledToastNotificationFactory>
{
    IScheduledToastNotificationFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IShownTileNotification :
    Windows::Foundation::IInspectable,
    impl::consume<IShownTileNotification>
{
    IShownTileNotification(std::nullptr_t = nullptr) noexcept {}
};

struct ITileFlyoutNotification :
    Windows::Foundation::IInspectable,
    impl::consume<ITileFlyoutNotification>
{
    ITileFlyoutNotification(std::nullptr_t = nullptr) noexcept {}
};

struct ITileFlyoutNotificationFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ITileFlyoutNotificationFactory>
{
    ITileFlyoutNotificationFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ITileFlyoutUpdateManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ITileFlyoutUpdateManagerStatics>
{
    ITileFlyoutUpdateManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ITileFlyoutUpdater :
    Windows::Foundation::IInspectable,
    impl::consume<ITileFlyoutUpdater>
{
    ITileFlyoutUpdater(std::nullptr_t = nullptr) noexcept {}
};

struct ITileNotification :
    Windows::Foundation::IInspectable,
    impl::consume<ITileNotification>
{
    ITileNotification(std::nullptr_t = nullptr) noexcept {}
};

struct ITileNotificationFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ITileNotificationFactory>
{
    ITileNotificationFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ITileUpdateManagerForUser :
    Windows::Foundation::IInspectable,
    impl::consume<ITileUpdateManagerForUser>
{
    ITileUpdateManagerForUser(std::nullptr_t = nullptr) noexcept {}
};

struct ITileUpdateManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ITileUpdateManagerStatics>
{
    ITileUpdateManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ITileUpdateManagerStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<ITileUpdateManagerStatics2>
{
    ITileUpdateManagerStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct ITileUpdater :
    Windows::Foundation::IInspectable,
    impl::consume<ITileUpdater>
{
    ITileUpdater(std::nullptr_t = nullptr) noexcept {}
};

struct ITileUpdater2 :
    Windows::Foundation::IInspectable,
    impl::consume<ITileUpdater2>
{
    ITileUpdater2(std::nullptr_t = nullptr) noexcept {}
};

struct IToastActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IToastActivatedEventArgs>
{
    IToastActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IToastDismissedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IToastDismissedEventArgs>
{
    IToastDismissedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IToastFailedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IToastFailedEventArgs>
{
    IToastFailedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IToastNotification :
    Windows::Foundation::IInspectable,
    impl::consume<IToastNotification>
{
    IToastNotification(std::nullptr_t = nullptr) noexcept {}
};

struct IToastNotification2 :
    Windows::Foundation::IInspectable,
    impl::consume<IToastNotification2>
{
    IToastNotification2(std::nullptr_t = nullptr) noexcept {}
};

struct IToastNotification3 :
    Windows::Foundation::IInspectable,
    impl::consume<IToastNotification3>
{
    IToastNotification3(std::nullptr_t = nullptr) noexcept {}
};

struct IToastNotificationActionTriggerDetail :
    Windows::Foundation::IInspectable,
    impl::consume<IToastNotificationActionTriggerDetail>
{
    IToastNotificationActionTriggerDetail(std::nullptr_t = nullptr) noexcept {}
};

struct IToastNotificationFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IToastNotificationFactory>
{
    IToastNotificationFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IToastNotificationHistory :
    Windows::Foundation::IInspectable,
    impl::consume<IToastNotificationHistory>
{
    IToastNotificationHistory(std::nullptr_t = nullptr) noexcept {}
};

struct IToastNotificationHistory2 :
    Windows::Foundation::IInspectable,
    impl::consume<IToastNotificationHistory2>
{
    IToastNotificationHistory2(std::nullptr_t = nullptr) noexcept {}
};

struct IToastNotificationHistoryChangedTriggerDetail :
    Windows::Foundation::IInspectable,
    impl::consume<IToastNotificationHistoryChangedTriggerDetail>
{
    IToastNotificationHistoryChangedTriggerDetail(std::nullptr_t = nullptr) noexcept {}
};

struct IToastNotificationManagerForUser :
    Windows::Foundation::IInspectable,
    impl::consume<IToastNotificationManagerForUser>
{
    IToastNotificationManagerForUser(std::nullptr_t = nullptr) noexcept {}
};

struct IToastNotificationManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IToastNotificationManagerStatics>
{
    IToastNotificationManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IToastNotificationManagerStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IToastNotificationManagerStatics2>
{
    IToastNotificationManagerStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IToastNotificationManagerStatics4 :
    Windows::Foundation::IInspectable,
    impl::consume<IToastNotificationManagerStatics4>
{
    IToastNotificationManagerStatics4(std::nullptr_t = nullptr) noexcept {}
};

struct IToastNotifier :
    Windows::Foundation::IInspectable,
    impl::consume<IToastNotifier>
{
    IToastNotifier(std::nullptr_t = nullptr) noexcept {}
};

struct IUserNotification :
    Windows::Foundation::IInspectable,
    impl::consume<IUserNotification>
{
    IUserNotification(std::nullptr_t = nullptr) noexcept {}
};

struct IUserNotificationChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IUserNotificationChangedEventArgs>
{
    IUserNotificationChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

}

}
