// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Notifications.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Notifications {

struct WINRT_EBO AdaptiveNotificationText :
    Windows::UI::Notifications::IAdaptiveNotificationText
{
    AdaptiveNotificationText(std::nullptr_t) noexcept {}
    AdaptiveNotificationText();
};

struct WINRT_EBO BadgeNotification :
    Windows::UI::Notifications::IBadgeNotification
{
    BadgeNotification(std::nullptr_t) noexcept {}
    BadgeNotification(const Windows::Data::Xml::Dom::XmlDocument & content);
};

struct BadgeUpdateManager
{
    BadgeUpdateManager() = delete;
    static Windows::UI::Notifications::BadgeUpdater CreateBadgeUpdaterForApplication();
    static Windows::UI::Notifications::BadgeUpdater CreateBadgeUpdaterForApplication(hstring_view applicationId);
    static Windows::UI::Notifications::BadgeUpdater CreateBadgeUpdaterForSecondaryTile(hstring_view tileId);
    static Windows::Data::Xml::Dom::XmlDocument GetTemplateContent(Windows::UI::Notifications::BadgeTemplateType type);
    static Windows::UI::Notifications::BadgeUpdateManagerForUser GetForUser(const Windows::System::User & user);
};

struct WINRT_EBO BadgeUpdateManagerForUser :
    Windows::UI::Notifications::IBadgeUpdateManagerForUser
{
    BadgeUpdateManagerForUser(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BadgeUpdater :
    Windows::UI::Notifications::IBadgeUpdater
{
    BadgeUpdater(std::nullptr_t) noexcept {}
};

struct KnownAdaptiveNotificationHints
{
    KnownAdaptiveNotificationHints() = delete;
    static hstring Style();
    static hstring Wrap();
    static hstring MaxLines();
    static hstring MinLines();
    static hstring TextStacking();
    static hstring Align();
};

struct KnownAdaptiveNotificationTextStyles
{
    KnownAdaptiveNotificationTextStyles() = delete;
    static hstring Caption();
    static hstring Body();
    static hstring Base();
    static hstring Subtitle();
    static hstring Title();
    static hstring Subheader();
    static hstring Header();
    static hstring TitleNumeral();
    static hstring SubheaderNumeral();
    static hstring HeaderNumeral();
    static hstring CaptionSubtle();
    static hstring BodySubtle();
    static hstring BaseSubtle();
    static hstring SubtitleSubtle();
    static hstring TitleSubtle();
    static hstring SubheaderSubtle();
    static hstring SubheaderNumeralSubtle();
    static hstring HeaderSubtle();
    static hstring HeaderNumeralSubtle();
};

struct KnownNotificationBindings
{
    KnownNotificationBindings() = delete;
    static hstring ToastGeneric();
};

struct WINRT_EBO Notification :
    Windows::UI::Notifications::INotification
{
    Notification(std::nullptr_t) noexcept {}
    Notification();
};

struct WINRT_EBO NotificationBinding :
    Windows::UI::Notifications::INotificationBinding
{
    NotificationBinding(std::nullptr_t) noexcept {}
};

struct WINRT_EBO NotificationVisual :
    Windows::UI::Notifications::INotificationVisual
{
    NotificationVisual(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ScheduledTileNotification :
    Windows::UI::Notifications::IScheduledTileNotification
{
    ScheduledTileNotification(std::nullptr_t) noexcept {}
    ScheduledTileNotification(const Windows::Data::Xml::Dom::XmlDocument & content, const Windows::Foundation::DateTime & deliveryTime);
};

struct WINRT_EBO ScheduledToastNotification :
    Windows::UI::Notifications::IScheduledToastNotification,
    impl::require<ScheduledToastNotification, Windows::UI::Notifications::IScheduledToastNotification2, Windows::UI::Notifications::IScheduledToastNotification3>
{
    ScheduledToastNotification(std::nullptr_t) noexcept {}
    ScheduledToastNotification(const Windows::Data::Xml::Dom::XmlDocument & content, const Windows::Foundation::DateTime & deliveryTime);
    ScheduledToastNotification(const Windows::Data::Xml::Dom::XmlDocument & content, const Windows::Foundation::DateTime & deliveryTime, const Windows::Foundation::TimeSpan & snoozeInterval, uint32_t maximumSnoozeCount);
};

struct WINRT_EBO ShownTileNotification :
    Windows::UI::Notifications::IShownTileNotification
{
    ShownTileNotification(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TileFlyoutNotification :
    Windows::UI::Notifications::ITileFlyoutNotification
{
    TileFlyoutNotification(std::nullptr_t) noexcept {}
    TileFlyoutNotification(const Windows::Data::Xml::Dom::XmlDocument & content);
};

struct TileFlyoutUpdateManager
{
    TileFlyoutUpdateManager() = delete;
    static Windows::UI::Notifications::TileFlyoutUpdater CreateTileFlyoutUpdaterForApplication();
    static Windows::UI::Notifications::TileFlyoutUpdater CreateTileFlyoutUpdaterForApplication(hstring_view applicationId);
    static Windows::UI::Notifications::TileFlyoutUpdater CreateTileFlyoutUpdaterForSecondaryTile(hstring_view tileId);
    static Windows::Data::Xml::Dom::XmlDocument GetTemplateContent(Windows::UI::Notifications::TileFlyoutTemplateType type);
};

struct WINRT_EBO TileFlyoutUpdater :
    Windows::UI::Notifications::ITileFlyoutUpdater
{
    TileFlyoutUpdater(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TileNotification :
    Windows::UI::Notifications::ITileNotification
{
    TileNotification(std::nullptr_t) noexcept {}
    TileNotification(const Windows::Data::Xml::Dom::XmlDocument & content);
};

struct TileUpdateManager
{
    TileUpdateManager() = delete;
    static Windows::UI::Notifications::TileUpdater CreateTileUpdaterForApplication();
    static Windows::UI::Notifications::TileUpdater CreateTileUpdaterForApplication(hstring_view applicationId);
    static Windows::UI::Notifications::TileUpdater CreateTileUpdaterForSecondaryTile(hstring_view tileId);
    static Windows::Data::Xml::Dom::XmlDocument GetTemplateContent(Windows::UI::Notifications::TileTemplateType type);
    static Windows::UI::Notifications::TileUpdateManagerForUser GetForUser(const Windows::System::User & user);
};

struct WINRT_EBO TileUpdateManagerForUser :
    Windows::UI::Notifications::ITileUpdateManagerForUser
{
    TileUpdateManagerForUser(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TileUpdater :
    Windows::UI::Notifications::ITileUpdater,
    impl::require<TileUpdater, Windows::UI::Notifications::ITileUpdater2>
{
    TileUpdater(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ToastActivatedEventArgs :
    Windows::UI::Notifications::IToastActivatedEventArgs
{
    ToastActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ToastDismissedEventArgs :
    Windows::UI::Notifications::IToastDismissedEventArgs
{
    ToastDismissedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ToastFailedEventArgs :
    Windows::UI::Notifications::IToastFailedEventArgs
{
    ToastFailedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ToastNotification :
    Windows::UI::Notifications::IToastNotification,
    impl::require<ToastNotification, Windows::UI::Notifications::IToastNotification2, Windows::UI::Notifications::IToastNotification3>
{
    ToastNotification(std::nullptr_t) noexcept {}
    ToastNotification(const Windows::Data::Xml::Dom::XmlDocument & content);
};

struct WINRT_EBO ToastNotificationActionTriggerDetail :
    Windows::UI::Notifications::IToastNotificationActionTriggerDetail
{
    ToastNotificationActionTriggerDetail(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ToastNotificationHistory :
    Windows::UI::Notifications::IToastNotificationHistory,
    impl::require<ToastNotificationHistory, Windows::UI::Notifications::IToastNotificationHistory2>
{
    ToastNotificationHistory(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ToastNotificationHistoryChangedTriggerDetail :
    Windows::UI::Notifications::IToastNotificationHistoryChangedTriggerDetail
{
    ToastNotificationHistoryChangedTriggerDetail(std::nullptr_t) noexcept {}
};

struct ToastNotificationManager
{
    ToastNotificationManager() = delete;
    static Windows::UI::Notifications::ToastNotifier CreateToastNotifier();
    static Windows::UI::Notifications::ToastNotifier CreateToastNotifier(hstring_view applicationId);
    static Windows::Data::Xml::Dom::XmlDocument GetTemplateContent(Windows::UI::Notifications::ToastTemplateType type);
    static Windows::UI::Notifications::ToastNotificationHistory History();
    static Windows::UI::Notifications::ToastNotificationManagerForUser GetForUser(const Windows::System::User & user);
    static void ConfigureNotificationMirroring(Windows::UI::Notifications::NotificationMirroring value);
};

struct WINRT_EBO ToastNotificationManagerForUser :
    Windows::UI::Notifications::IToastNotificationManagerForUser
{
    ToastNotificationManagerForUser(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ToastNotifier :
    Windows::UI::Notifications::IToastNotifier
{
    ToastNotifier(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UserNotification :
    Windows::UI::Notifications::IUserNotification
{
    UserNotification(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UserNotificationChangedEventArgs :
    Windows::UI::Notifications::IUserNotificationChangedEventArgs
{
    UserNotificationChangedEventArgs(std::nullptr_t) noexcept {}
};

}

}
