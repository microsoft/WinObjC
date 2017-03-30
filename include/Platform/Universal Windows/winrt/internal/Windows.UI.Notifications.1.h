// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Notifications.0.h"
#include "Windows.ApplicationModel.0.h"
#include "Windows.Data.Xml.Dom.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.0.h"
#include "Windows.System.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Notifications {

struct __declspec(uuid("eb0dbe66-7448-448d-9db8-d78acd2abba9")) __declspec(novtable) IAdaptiveNotificationContent : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Kind(winrt::Windows::UI::Notifications::AdaptiveNotificationContentKind * value) = 0;
    virtual HRESULT __stdcall get_Hints(Windows::Foundation::Collections::IMap<hstring, hstring> ** value) = 0;
};

struct __declspec(uuid("46d4a3be-609a-4326-a40b-bfde872034a3")) __declspec(novtable) IAdaptiveNotificationText : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall put_Text(hstring value) = 0;
    virtual HRESULT __stdcall get_Language(hstring * value) = 0;
    virtual HRESULT __stdcall put_Language(hstring value) = 0;
};

struct __declspec(uuid("075cb4ca-d08a-4e2f-9233-7e289c1f7722")) __declspec(novtable) IBadgeNotification : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Content(Windows::Data::Xml::Dom::IXmlDocument ** value) = 0;
    virtual HRESULT __stdcall put_ExpirationTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_ExpirationTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
};

struct __declspec(uuid("edf255ce-0618-4d59-948a-5a61040c52f9")) __declspec(novtable) IBadgeNotificationFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateBadgeNotification(Windows::Data::Xml::Dom::IXmlDocument * content, Windows::UI::Notifications::IBadgeNotification ** notification) = 0;
};

struct __declspec(uuid("996b21bc-0386-44e5-ba8d-0c1077a62e92")) __declspec(novtable) IBadgeUpdateManagerForUser : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateBadgeUpdaterForApplication(Windows::UI::Notifications::IBadgeUpdater ** result) = 0;
    virtual HRESULT __stdcall abi_CreateBadgeUpdaterForApplicationWithId(hstring applicationId, Windows::UI::Notifications::IBadgeUpdater ** result) = 0;
    virtual HRESULT __stdcall abi_CreateBadgeUpdaterForSecondaryTile(hstring tileId, Windows::UI::Notifications::IBadgeUpdater ** result) = 0;
    virtual HRESULT __stdcall get_User(Windows::System::IUser ** value) = 0;
};

struct __declspec(uuid("33400faa-6dd5-4105-aebc-9b50fca492da")) __declspec(novtable) IBadgeUpdateManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateBadgeUpdaterForApplication(Windows::UI::Notifications::IBadgeUpdater ** updater) = 0;
    virtual HRESULT __stdcall abi_CreateBadgeUpdaterForApplicationWithId(hstring applicationId, Windows::UI::Notifications::IBadgeUpdater ** updater) = 0;
    virtual HRESULT __stdcall abi_CreateBadgeUpdaterForSecondaryTile(hstring tileId, Windows::UI::Notifications::IBadgeUpdater ** updater) = 0;
    virtual HRESULT __stdcall abi_GetTemplateContent(winrt::Windows::UI::Notifications::BadgeTemplateType type, Windows::Data::Xml::Dom::IXmlDocument ** content) = 0;
};

struct __declspec(uuid("979a35ce-f940-48bf-94e8-ca244d400b41")) __declspec(novtable) IBadgeUpdateManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForUser(Windows::System::IUser * user, Windows::UI::Notifications::IBadgeUpdateManagerForUser ** result) = 0;
};

struct __declspec(uuid("b5fa1fd4-7562-4f6c-bfa3-1b6ed2e57f2f")) __declspec(novtable) IBadgeUpdater : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Update(Windows::UI::Notifications::IBadgeNotification * notification) = 0;
    virtual HRESULT __stdcall abi_Clear() = 0;
    virtual HRESULT __stdcall abi_StartPeriodicUpdate(Windows::Foundation::IUriRuntimeClass * badgeContent, winrt::Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) = 0;
    virtual HRESULT __stdcall abi_StartPeriodicUpdateAtTime(Windows::Foundation::IUriRuntimeClass * badgeContent, Windows::Foundation::DateTime startTime, winrt::Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) = 0;
    virtual HRESULT __stdcall abi_StopPeriodicUpdate() = 0;
};

struct __declspec(uuid("06206598-d496-497d-8692-4f7d7c2770df")) __declspec(novtable) IKnownAdaptiveNotificationHintsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Style(hstring * value) = 0;
    virtual HRESULT __stdcall get_Wrap(hstring * value) = 0;
    virtual HRESULT __stdcall get_MaxLines(hstring * value) = 0;
    virtual HRESULT __stdcall get_MinLines(hstring * value) = 0;
    virtual HRESULT __stdcall get_TextStacking(hstring * value) = 0;
    virtual HRESULT __stdcall get_Align(hstring * value) = 0;
};

struct __declspec(uuid("202192d7-8996-45aa-8ba1-d461d72c2a1b")) __declspec(novtable) IKnownAdaptiveNotificationTextStylesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Caption(hstring * value) = 0;
    virtual HRESULT __stdcall get_Body(hstring * value) = 0;
    virtual HRESULT __stdcall get_Base(hstring * value) = 0;
    virtual HRESULT __stdcall get_Subtitle(hstring * value) = 0;
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall get_Subheader(hstring * value) = 0;
    virtual HRESULT __stdcall get_Header(hstring * value) = 0;
    virtual HRESULT __stdcall get_TitleNumeral(hstring * value) = 0;
    virtual HRESULT __stdcall get_SubheaderNumeral(hstring * value) = 0;
    virtual HRESULT __stdcall get_HeaderNumeral(hstring * value) = 0;
    virtual HRESULT __stdcall get_CaptionSubtle(hstring * value) = 0;
    virtual HRESULT __stdcall get_BodySubtle(hstring * value) = 0;
    virtual HRESULT __stdcall get_BaseSubtle(hstring * value) = 0;
    virtual HRESULT __stdcall get_SubtitleSubtle(hstring * value) = 0;
    virtual HRESULT __stdcall get_TitleSubtle(hstring * value) = 0;
    virtual HRESULT __stdcall get_SubheaderSubtle(hstring * value) = 0;
    virtual HRESULT __stdcall get_SubheaderNumeralSubtle(hstring * value) = 0;
    virtual HRESULT __stdcall get_HeaderSubtle(hstring * value) = 0;
    virtual HRESULT __stdcall get_HeaderNumeralSubtle(hstring * value) = 0;
};

struct __declspec(uuid("79427bae-a8b7-4d58-89ea-76a7b7bccded")) __declspec(novtable) IKnownNotificationBindingsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ToastGeneric(hstring * value) = 0;
};

struct __declspec(uuid("108037fe-eb76-4f82-97bc-da07530a2e20")) __declspec(novtable) INotification : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ExpirationTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_ExpirationTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_Visual(Windows::UI::Notifications::INotificationVisual ** value) = 0;
    virtual HRESULT __stdcall put_Visual(Windows::UI::Notifications::INotificationVisual * value) = 0;
};

struct __declspec(uuid("f29e4b85-0370-4ad3-b4ea-da9e35e7eabf")) __declspec(novtable) INotificationBinding : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Template(hstring * value) = 0;
    virtual HRESULT __stdcall put_Template(hstring value) = 0;
    virtual HRESULT __stdcall get_Language(hstring * value) = 0;
    virtual HRESULT __stdcall put_Language(hstring value) = 0;
    virtual HRESULT __stdcall get_Hints(Windows::Foundation::Collections::IMap<hstring, hstring> ** value) = 0;
    virtual HRESULT __stdcall abi_GetTextElements(Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::AdaptiveNotificationText> ** result) = 0;
};

struct __declspec(uuid("68835b8e-aa56-4e11-86d3-5f9a6957bc5b")) __declspec(novtable) INotificationVisual : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Language(hstring * value) = 0;
    virtual HRESULT __stdcall put_Language(hstring value) = 0;
    virtual HRESULT __stdcall get_Bindings(Windows::Foundation::Collections::IVector<Windows::UI::Notifications::NotificationBinding> ** result) = 0;
    virtual HRESULT __stdcall abi_GetBinding(hstring templateName, Windows::UI::Notifications::INotificationBinding ** result) = 0;
};

struct __declspec(uuid("0abca6d5-99dc-4c78-a11c-c9e7f86d7ef7")) __declspec(novtable) IScheduledTileNotification : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Content(Windows::Data::Xml::Dom::IXmlDocument ** value) = 0;
    virtual HRESULT __stdcall get_DeliveryTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_ExpirationTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_ExpirationTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_Tag(hstring value) = 0;
    virtual HRESULT __stdcall get_Tag(hstring * value) = 0;
    virtual HRESULT __stdcall put_Id(hstring value) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
};

struct __declspec(uuid("3383138a-98c0-4c3b-bbd6-4a633c7cfc29")) __declspec(novtable) IScheduledTileNotificationFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateScheduledTileNotification(Windows::Data::Xml::Dom::IXmlDocument * content, Windows::Foundation::DateTime deliveryTime, Windows::UI::Notifications::IScheduledTileNotification ** notification) = 0;
};

struct __declspec(uuid("79f577f8-0de7-48cd-9740-9b370490c838")) __declspec(novtable) IScheduledToastNotification : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Content(Windows::Data::Xml::Dom::IXmlDocument ** value) = 0;
    virtual HRESULT __stdcall get_DeliveryTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_SnoozeInterval(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall get_MaximumSnoozeCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Id(hstring value) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
};

struct __declspec(uuid("a66ea09c-31b4-43b0-b5dd-7a40e85363b1")) __declspec(novtable) IScheduledToastNotification2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Tag(hstring value) = 0;
    virtual HRESULT __stdcall get_Tag(hstring * value) = 0;
    virtual HRESULT __stdcall put_Group(hstring value) = 0;
    virtual HRESULT __stdcall get_Group(hstring * value) = 0;
    virtual HRESULT __stdcall put_SuppressPopup(bool value) = 0;
    virtual HRESULT __stdcall get_SuppressPopup(bool * value) = 0;
};

struct __declspec(uuid("98429e8b-bd32-4a3b-9d15-22aea49462a1")) __declspec(novtable) IScheduledToastNotification3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NotificationMirroring(winrt::Windows::UI::Notifications::NotificationMirroring * value) = 0;
    virtual HRESULT __stdcall put_NotificationMirroring(winrt::Windows::UI::Notifications::NotificationMirroring value) = 0;
    virtual HRESULT __stdcall get_RemoteId(hstring * value) = 0;
    virtual HRESULT __stdcall put_RemoteId(hstring value) = 0;
};

struct __declspec(uuid("e7bed191-0bb9-4189-8394-31761b476fd7")) __declspec(novtable) IScheduledToastNotificationFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateScheduledToastNotification(Windows::Data::Xml::Dom::IXmlDocument * content, Windows::Foundation::DateTime deliveryTime, Windows::UI::Notifications::IScheduledToastNotification ** notification) = 0;
    virtual HRESULT __stdcall abi_CreateScheduledToastNotificationRecurring(Windows::Data::Xml::Dom::IXmlDocument * content, Windows::Foundation::DateTime deliveryTime, Windows::Foundation::TimeSpan snoozeInterval, uint32_t maximumSnoozeCount, Windows::UI::Notifications::IScheduledToastNotification ** notification) = 0;
};

struct __declspec(uuid("342d8988-5af2-481a-a6a3-f2fdc78de88e")) __declspec(novtable) IShownTileNotification : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Arguments(hstring * value) = 0;
};

struct __declspec(uuid("9a53b261-c70c-42be-b2f3-f42aa97d34e5")) __declspec(novtable) ITileFlyoutNotification : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Content(Windows::Data::Xml::Dom::IXmlDocument ** value) = 0;
    virtual HRESULT __stdcall put_ExpirationTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_ExpirationTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
};

struct __declspec(uuid("ef556ff5-5226-4f2b-b278-88a35dfe569f")) __declspec(novtable) ITileFlyoutNotificationFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateTileFlyoutNotification(Windows::Data::Xml::Dom::IXmlDocument * content, Windows::UI::Notifications::ITileFlyoutNotification ** notification) = 0;
};

struct __declspec(uuid("04363b0b-1ac0-4b99-88e7-ada83e953d48")) __declspec(novtable) ITileFlyoutUpdateManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateTileFlyoutUpdaterForApplication(Windows::UI::Notifications::ITileFlyoutUpdater ** updater) = 0;
    virtual HRESULT __stdcall abi_CreateTileFlyoutUpdaterForApplicationWithId(hstring applicationId, Windows::UI::Notifications::ITileFlyoutUpdater ** updater) = 0;
    virtual HRESULT __stdcall abi_CreateTileFlyoutUpdaterForSecondaryTile(hstring tileId, Windows::UI::Notifications::ITileFlyoutUpdater ** updater) = 0;
    virtual HRESULT __stdcall abi_GetTemplateContent(winrt::Windows::UI::Notifications::TileFlyoutTemplateType type, Windows::Data::Xml::Dom::IXmlDocument ** content) = 0;
};

struct __declspec(uuid("8d40c76a-c465-4052-a740-5c2654c1a089")) __declspec(novtable) ITileFlyoutUpdater : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Update(Windows::UI::Notifications::ITileFlyoutNotification * notification) = 0;
    virtual HRESULT __stdcall abi_Clear() = 0;
    virtual HRESULT __stdcall abi_StartPeriodicUpdate(Windows::Foundation::IUriRuntimeClass * tileFlyoutContent, winrt::Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) = 0;
    virtual HRESULT __stdcall abi_StartPeriodicUpdateAtTime(Windows::Foundation::IUriRuntimeClass * tileFlyoutContent, Windows::Foundation::DateTime startTime, winrt::Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) = 0;
    virtual HRESULT __stdcall abi_StopPeriodicUpdate() = 0;
    virtual HRESULT __stdcall get_Setting(winrt::Windows::UI::Notifications::NotificationSetting * value) = 0;
};

struct __declspec(uuid("ebaec8fa-50ec-4c18-b4d0-3af02e5540ab")) __declspec(novtable) ITileNotification : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Content(Windows::Data::Xml::Dom::IXmlDocument ** value) = 0;
    virtual HRESULT __stdcall put_ExpirationTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_ExpirationTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_Tag(hstring value) = 0;
    virtual HRESULT __stdcall get_Tag(hstring * value) = 0;
};

struct __declspec(uuid("c6abdd6e-4928-46c8-bdbf-81a047dea0d4")) __declspec(novtable) ITileNotificationFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateTileNotification(Windows::Data::Xml::Dom::IXmlDocument * content, Windows::UI::Notifications::ITileNotification ** notification) = 0;
};

struct __declspec(uuid("55141348-2ee2-4e2d-9cc1-216a20decc9f")) __declspec(novtable) ITileUpdateManagerForUser : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateTileUpdaterForApplication(Windows::UI::Notifications::ITileUpdater ** updater) = 0;
    virtual HRESULT __stdcall abi_CreateTileUpdaterForApplicationWithId(hstring applicationId, Windows::UI::Notifications::ITileUpdater ** updater) = 0;
    virtual HRESULT __stdcall abi_CreateTileUpdaterForSecondaryTile(hstring tileId, Windows::UI::Notifications::ITileUpdater ** updater) = 0;
    virtual HRESULT __stdcall get_User(Windows::System::IUser ** value) = 0;
};

struct __declspec(uuid("da159e5d-3ea9-4986-8d84-b09d5e12276d")) __declspec(novtable) ITileUpdateManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateTileUpdaterForApplication(Windows::UI::Notifications::ITileUpdater ** updater) = 0;
    virtual HRESULT __stdcall abi_CreateTileUpdaterForApplicationWithId(hstring applicationId, Windows::UI::Notifications::ITileUpdater ** updater) = 0;
    virtual HRESULT __stdcall abi_CreateTileUpdaterForSecondaryTile(hstring tileId, Windows::UI::Notifications::ITileUpdater ** updater) = 0;
    virtual HRESULT __stdcall abi_GetTemplateContent(winrt::Windows::UI::Notifications::TileTemplateType type, Windows::Data::Xml::Dom::IXmlDocument ** content) = 0;
};

struct __declspec(uuid("731c1ddc-8e14-4b7c-a34b-9d22de76c84d")) __declspec(novtable) ITileUpdateManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForUser(Windows::System::IUser * user, Windows::UI::Notifications::ITileUpdateManagerForUser ** result) = 0;
};

struct __declspec(uuid("0942a48b-1d91-44ec-9243-c1e821c29a20")) __declspec(novtable) ITileUpdater : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Update(Windows::UI::Notifications::ITileNotification * notification) = 0;
    virtual HRESULT __stdcall abi_Clear() = 0;
    virtual HRESULT __stdcall abi_EnableNotificationQueue(bool enable) = 0;
    virtual HRESULT __stdcall get_Setting(winrt::Windows::UI::Notifications::NotificationSetting * value) = 0;
    virtual HRESULT __stdcall abi_AddToSchedule(Windows::UI::Notifications::IScheduledTileNotification * scheduledTile) = 0;
    virtual HRESULT __stdcall abi_RemoveFromSchedule(Windows::UI::Notifications::IScheduledTileNotification * scheduledTile) = 0;
    virtual HRESULT __stdcall abi_GetScheduledTileNotifications(Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ScheduledTileNotification> ** scheduledTiles) = 0;
    virtual HRESULT __stdcall abi_StartPeriodicUpdate(Windows::Foundation::IUriRuntimeClass * tileContent, winrt::Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) = 0;
    virtual HRESULT __stdcall abi_StartPeriodicUpdateAtTime(Windows::Foundation::IUriRuntimeClass * tileContent, Windows::Foundation::DateTime startTime, winrt::Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) = 0;
    virtual HRESULT __stdcall abi_StopPeriodicUpdate() = 0;
    virtual HRESULT __stdcall abi_StartPeriodicUpdateBatch(Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> * tileContents, winrt::Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) = 0;
    virtual HRESULT __stdcall abi_StartPeriodicUpdateBatchAtTime(Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> * tileContents, Windows::Foundation::DateTime startTime, winrt::Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) = 0;
};

struct __declspec(uuid("a2266e12-15ee-43ed-83f5-65b352bb1a84")) __declspec(novtable) ITileUpdater2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_EnableNotificationQueueForSquare150x150(bool enable) = 0;
    virtual HRESULT __stdcall abi_EnableNotificationQueueForWide310x150(bool enable) = 0;
    virtual HRESULT __stdcall abi_EnableNotificationQueueForSquare310x310(bool enable) = 0;
};

struct __declspec(uuid("e3bf92f3-c197-436f-8265-0625824f8dac")) __declspec(novtable) IToastActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Arguments(hstring * value) = 0;
};

struct __declspec(uuid("3f89d935-d9cb-4538-a0f0-ffe7659938f8")) __declspec(novtable) IToastDismissedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reason(winrt::Windows::UI::Notifications::ToastDismissalReason * value) = 0;
};

struct __declspec(uuid("35176862-cfd4-44f8-ad64-f500fd896c3b")) __declspec(novtable) IToastFailedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ErrorCode(HRESULT * value) = 0;
};

struct __declspec(uuid("997e2675-059e-4e60-8b06-1760917c8b80")) __declspec(novtable) IToastNotification : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Content(Windows::Data::Xml::Dom::IXmlDocument ** value) = 0;
    virtual HRESULT __stdcall put_ExpirationTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_ExpirationTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall add_Dismissed(Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastDismissedEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_Dismissed(event_token cookie) = 0;
    virtual HRESULT __stdcall add_Activated(Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::Foundation::IInspectable> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_Activated(event_token cookie) = 0;
    virtual HRESULT __stdcall add_Failed(Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastFailedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Failed(event_token token) = 0;
};

struct __declspec(uuid("9dfb9fd1-143a-490e-90bf-b9fba7132de7")) __declspec(novtable) IToastNotification2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Tag(hstring value) = 0;
    virtual HRESULT __stdcall get_Tag(hstring * value) = 0;
    virtual HRESULT __stdcall put_Group(hstring value) = 0;
    virtual HRESULT __stdcall get_Group(hstring * value) = 0;
    virtual HRESULT __stdcall put_SuppressPopup(bool value) = 0;
    virtual HRESULT __stdcall get_SuppressPopup(bool * value) = 0;
};

struct __declspec(uuid("31e8aed8-8141-4f99-bc0a-c4ed21297d77")) __declspec(novtable) IToastNotification3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NotificationMirroring(winrt::Windows::UI::Notifications::NotificationMirroring * value) = 0;
    virtual HRESULT __stdcall put_NotificationMirroring(winrt::Windows::UI::Notifications::NotificationMirroring value) = 0;
    virtual HRESULT __stdcall get_RemoteId(hstring * value) = 0;
    virtual HRESULT __stdcall put_RemoteId(hstring value) = 0;
};

struct __declspec(uuid("9445135a-38f3-42f6-96aa-7955b0f03da2")) __declspec(novtable) IToastNotificationActionTriggerDetail : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Argument(hstring * argument) = 0;
    virtual HRESULT __stdcall get_UserInput(Windows::Foundation::Collections::IPropertySet ** inputs) = 0;
};

struct __declspec(uuid("04124b20-82c6-4229-b109-fd9ed4662b53")) __declspec(novtable) IToastNotificationFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateToastNotification(Windows::Data::Xml::Dom::IXmlDocument * content, Windows::UI::Notifications::IToastNotification ** notification) = 0;
};

struct __declspec(uuid("5caddc63-01d3-4c97-986f-0533483fee14")) __declspec(novtable) IToastNotificationHistory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RemoveGroup(hstring group) = 0;
    virtual HRESULT __stdcall abi_RemoveGroupWithId(hstring group, hstring applicationId) = 0;
    virtual HRESULT __stdcall abi_RemoveGroupedTagWithId(hstring tag, hstring group, hstring applicationId) = 0;
    virtual HRESULT __stdcall abi_RemoveGroupedTag(hstring tag, hstring group) = 0;
    virtual HRESULT __stdcall abi_Remove(hstring tag) = 0;
    virtual HRESULT __stdcall abi_Clear() = 0;
    virtual HRESULT __stdcall abi_ClearWithId(hstring applicationId) = 0;
};

struct __declspec(uuid("3bc3d253-2f31-4092-9129-8ad5abf067da")) __declspec(novtable) IToastNotificationHistory2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetHistory(Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ToastNotification> ** toasts) = 0;
    virtual HRESULT __stdcall abi_GetHistoryWithId(hstring applicationId, Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ToastNotification> ** toasts) = 0;
};

struct __declspec(uuid("db037ffa-0068-412c-9c83-267c37f65670")) __declspec(novtable) IToastNotificationHistoryChangedTriggerDetail : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ChangeType(winrt::Windows::UI::Notifications::ToastHistoryChangedType * value) = 0;
};

struct __declspec(uuid("79ab57f6-43fe-487b-8a7f-99567200ae94")) __declspec(novtable) IToastNotificationManagerForUser : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateToastNotifier(Windows::UI::Notifications::IToastNotifier ** result) = 0;
    virtual HRESULT __stdcall abi_CreateToastNotifierWithId(hstring applicationId, Windows::UI::Notifications::IToastNotifier ** result) = 0;
    virtual HRESULT __stdcall get_History(Windows::UI::Notifications::IToastNotificationHistory ** value) = 0;
    virtual HRESULT __stdcall get_User(Windows::System::IUser ** value) = 0;
};

struct __declspec(uuid("50ac103f-d235-4598-bbef-98fe4d1a3ad4")) __declspec(novtable) IToastNotificationManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateToastNotifier(Windows::UI::Notifications::IToastNotifier ** notifier) = 0;
    virtual HRESULT __stdcall abi_CreateToastNotifierWithId(hstring applicationId, Windows::UI::Notifications::IToastNotifier ** notifier) = 0;
    virtual HRESULT __stdcall abi_GetTemplateContent(winrt::Windows::UI::Notifications::ToastTemplateType type, Windows::Data::Xml::Dom::IXmlDocument ** content) = 0;
};

struct __declspec(uuid("7ab93c52-0e48-4750-ba9d-1a4113981847")) __declspec(novtable) IToastNotificationManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_History(Windows::UI::Notifications::IToastNotificationHistory ** value) = 0;
};

struct __declspec(uuid("8f993fd3-e516-45fb-8130-398e93fa52c3")) __declspec(novtable) IToastNotificationManagerStatics4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForUser(Windows::System::IUser * user, Windows::UI::Notifications::IToastNotificationManagerForUser ** result) = 0;
    virtual HRESULT __stdcall abi_ConfigureNotificationMirroring(winrt::Windows::UI::Notifications::NotificationMirroring value) = 0;
};

struct __declspec(uuid("75927b93-03f3-41ec-91d3-6e5bac1b38e7")) __declspec(novtable) IToastNotifier : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Show(Windows::UI::Notifications::IToastNotification * notification) = 0;
    virtual HRESULT __stdcall abi_Hide(Windows::UI::Notifications::IToastNotification * notification) = 0;
    virtual HRESULT __stdcall get_Setting(winrt::Windows::UI::Notifications::NotificationSetting * value) = 0;
    virtual HRESULT __stdcall abi_AddToSchedule(Windows::UI::Notifications::IScheduledToastNotification * scheduledToast) = 0;
    virtual HRESULT __stdcall abi_RemoveFromSchedule(Windows::UI::Notifications::IScheduledToastNotification * scheduledToast) = 0;
    virtual HRESULT __stdcall abi_GetScheduledToastNotifications(Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ScheduledToastNotification> ** scheduledToasts) = 0;
};

struct __declspec(uuid("adf7e52f-4e53-42d5-9c33-eb5ea515b23e")) __declspec(novtable) IUserNotification : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Notification(Windows::UI::Notifications::INotification ** value) = 0;
    virtual HRESULT __stdcall get_AppInfo(Windows::ApplicationModel::IAppInfo ** value) = 0;
    virtual HRESULT __stdcall get_Id(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_CreationTime(Windows::Foundation::DateTime * value) = 0;
};

struct __declspec(uuid("b6bd6839-79cf-4b25-82c0-0ce1eef81f8c")) __declspec(novtable) IUserNotificationChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ChangeKind(winrt::Windows::UI::Notifications::UserNotificationChangedKind * value) = 0;
    virtual HRESULT __stdcall get_UserNotificationId(uint32_t * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Notifications::AdaptiveNotificationText> { using default_interface = Windows::UI::Notifications::IAdaptiveNotificationText; };
template <> struct traits<Windows::UI::Notifications::BadgeNotification> { using default_interface = Windows::UI::Notifications::IBadgeNotification; };
template <> struct traits<Windows::UI::Notifications::BadgeUpdateManagerForUser> { using default_interface = Windows::UI::Notifications::IBadgeUpdateManagerForUser; };
template <> struct traits<Windows::UI::Notifications::BadgeUpdater> { using default_interface = Windows::UI::Notifications::IBadgeUpdater; };
template <> struct traits<Windows::UI::Notifications::Notification> { using default_interface = Windows::UI::Notifications::INotification; };
template <> struct traits<Windows::UI::Notifications::NotificationBinding> { using default_interface = Windows::UI::Notifications::INotificationBinding; };
template <> struct traits<Windows::UI::Notifications::NotificationVisual> { using default_interface = Windows::UI::Notifications::INotificationVisual; };
template <> struct traits<Windows::UI::Notifications::ScheduledTileNotification> { using default_interface = Windows::UI::Notifications::IScheduledTileNotification; };
template <> struct traits<Windows::UI::Notifications::ScheduledToastNotification> { using default_interface = Windows::UI::Notifications::IScheduledToastNotification; };
template <> struct traits<Windows::UI::Notifications::ShownTileNotification> { using default_interface = Windows::UI::Notifications::IShownTileNotification; };
template <> struct traits<Windows::UI::Notifications::TileFlyoutNotification> { using default_interface = Windows::UI::Notifications::ITileFlyoutNotification; };
template <> struct traits<Windows::UI::Notifications::TileFlyoutUpdater> { using default_interface = Windows::UI::Notifications::ITileFlyoutUpdater; };
template <> struct traits<Windows::UI::Notifications::TileNotification> { using default_interface = Windows::UI::Notifications::ITileNotification; };
template <> struct traits<Windows::UI::Notifications::TileUpdateManagerForUser> { using default_interface = Windows::UI::Notifications::ITileUpdateManagerForUser; };
template <> struct traits<Windows::UI::Notifications::TileUpdater> { using default_interface = Windows::UI::Notifications::ITileUpdater; };
template <> struct traits<Windows::UI::Notifications::ToastActivatedEventArgs> { using default_interface = Windows::UI::Notifications::IToastActivatedEventArgs; };
template <> struct traits<Windows::UI::Notifications::ToastDismissedEventArgs> { using default_interface = Windows::UI::Notifications::IToastDismissedEventArgs; };
template <> struct traits<Windows::UI::Notifications::ToastFailedEventArgs> { using default_interface = Windows::UI::Notifications::IToastFailedEventArgs; };
template <> struct traits<Windows::UI::Notifications::ToastNotification> { using default_interface = Windows::UI::Notifications::IToastNotification; };
template <> struct traits<Windows::UI::Notifications::ToastNotificationActionTriggerDetail> { using default_interface = Windows::UI::Notifications::IToastNotificationActionTriggerDetail; };
template <> struct traits<Windows::UI::Notifications::ToastNotificationHistory> { using default_interface = Windows::UI::Notifications::IToastNotificationHistory; };
template <> struct traits<Windows::UI::Notifications::ToastNotificationHistoryChangedTriggerDetail> { using default_interface = Windows::UI::Notifications::IToastNotificationHistoryChangedTriggerDetail; };
template <> struct traits<Windows::UI::Notifications::ToastNotificationManagerForUser> { using default_interface = Windows::UI::Notifications::IToastNotificationManagerForUser; };
template <> struct traits<Windows::UI::Notifications::ToastNotifier> { using default_interface = Windows::UI::Notifications::IToastNotifier; };
template <> struct traits<Windows::UI::Notifications::UserNotification> { using default_interface = Windows::UI::Notifications::IUserNotification; };
template <> struct traits<Windows::UI::Notifications::UserNotificationChangedEventArgs> { using default_interface = Windows::UI::Notifications::IUserNotificationChangedEventArgs; };

}

namespace Windows::UI::Notifications {

template <typename D>
struct WINRT_EBO impl_IAdaptiveNotificationContent
{
    Windows::UI::Notifications::AdaptiveNotificationContentKind Kind() const;
    Windows::Foundation::Collections::IMap<hstring, hstring> Hints() const;
};

template <typename D>
struct WINRT_EBO impl_IAdaptiveNotificationText
{
    hstring Text() const;
    void Text(hstring_view value) const;
    hstring Language() const;
    void Language(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IBadgeNotification
{
    Windows::Data::Xml::Dom::XmlDocument Content() const;
    void ExpirationTime(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> ExpirationTime() const;
};

template <typename D>
struct WINRT_EBO impl_IBadgeNotificationFactory
{
    Windows::UI::Notifications::BadgeNotification CreateBadgeNotification(const Windows::Data::Xml::Dom::XmlDocument & content) const;
};

template <typename D>
struct WINRT_EBO impl_IBadgeUpdateManagerForUser
{
    Windows::UI::Notifications::BadgeUpdater CreateBadgeUpdaterForApplication() const;
    Windows::UI::Notifications::BadgeUpdater CreateBadgeUpdaterForApplication(hstring_view applicationId) const;
    Windows::UI::Notifications::BadgeUpdater CreateBadgeUpdaterForSecondaryTile(hstring_view tileId) const;
    Windows::System::User User() const;
};

template <typename D>
struct WINRT_EBO impl_IBadgeUpdateManagerStatics
{
    Windows::UI::Notifications::BadgeUpdater CreateBadgeUpdaterForApplication() const;
    Windows::UI::Notifications::BadgeUpdater CreateBadgeUpdaterForApplication(hstring_view applicationId) const;
    Windows::UI::Notifications::BadgeUpdater CreateBadgeUpdaterForSecondaryTile(hstring_view tileId) const;
    Windows::Data::Xml::Dom::XmlDocument GetTemplateContent(Windows::UI::Notifications::BadgeTemplateType type) const;
};

template <typename D>
struct WINRT_EBO impl_IBadgeUpdateManagerStatics2
{
    Windows::UI::Notifications::BadgeUpdateManagerForUser GetForUser(const Windows::System::User & user) const;
};

template <typename D>
struct WINRT_EBO impl_IBadgeUpdater
{
    void Update(const Windows::UI::Notifications::BadgeNotification & notification) const;
    void Clear() const;
    void StartPeriodicUpdate(const Windows::Foundation::Uri & badgeContent, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) const;
    void StartPeriodicUpdate(const Windows::Foundation::Uri & badgeContent, const Windows::Foundation::DateTime & startTime, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) const;
    void StopPeriodicUpdate() const;
};

template <typename D>
struct WINRT_EBO impl_IKnownAdaptiveNotificationHintsStatics
{
    hstring Style() const;
    hstring Wrap() const;
    hstring MaxLines() const;
    hstring MinLines() const;
    hstring TextStacking() const;
    hstring Align() const;
};

template <typename D>
struct WINRT_EBO impl_IKnownAdaptiveNotificationTextStylesStatics
{
    hstring Caption() const;
    hstring Body() const;
    hstring Base() const;
    hstring Subtitle() const;
    hstring Title() const;
    hstring Subheader() const;
    hstring Header() const;
    hstring TitleNumeral() const;
    hstring SubheaderNumeral() const;
    hstring HeaderNumeral() const;
    hstring CaptionSubtle() const;
    hstring BodySubtle() const;
    hstring BaseSubtle() const;
    hstring SubtitleSubtle() const;
    hstring TitleSubtle() const;
    hstring SubheaderSubtle() const;
    hstring SubheaderNumeralSubtle() const;
    hstring HeaderSubtle() const;
    hstring HeaderNumeralSubtle() const;
};

template <typename D>
struct WINRT_EBO impl_IKnownNotificationBindingsStatics
{
    hstring ToastGeneric() const;
};

template <typename D>
struct WINRT_EBO impl_INotification
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> ExpirationTime() const;
    void ExpirationTime(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::UI::Notifications::NotificationVisual Visual() const;
    void Visual(const Windows::UI::Notifications::NotificationVisual & value) const;
};

template <typename D>
struct WINRT_EBO impl_INotificationBinding
{
    hstring Template() const;
    void Template(hstring_view value) const;
    hstring Language() const;
    void Language(hstring_view value) const;
    Windows::Foundation::Collections::IMap<hstring, hstring> Hints() const;
    Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::AdaptiveNotificationText> GetTextElements() const;
};

template <typename D>
struct WINRT_EBO impl_INotificationVisual
{
    hstring Language() const;
    void Language(hstring_view value) const;
    Windows::Foundation::Collections::IVector<Windows::UI::Notifications::NotificationBinding> Bindings() const;
    Windows::UI::Notifications::NotificationBinding GetBinding(hstring_view templateName) const;
};

template <typename D>
struct WINRT_EBO impl_IScheduledTileNotification
{
    Windows::Data::Xml::Dom::XmlDocument Content() const;
    Windows::Foundation::DateTime DeliveryTime() const;
    void ExpirationTime(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> ExpirationTime() const;
    void Tag(hstring_view value) const;
    hstring Tag() const;
    void Id(hstring_view value) const;
    hstring Id() const;
};

template <typename D>
struct WINRT_EBO impl_IScheduledTileNotificationFactory
{
    Windows::UI::Notifications::ScheduledTileNotification CreateScheduledTileNotification(const Windows::Data::Xml::Dom::XmlDocument & content, const Windows::Foundation::DateTime & deliveryTime) const;
};

template <typename D>
struct WINRT_EBO impl_IScheduledToastNotification
{
    Windows::Data::Xml::Dom::XmlDocument Content() const;
    Windows::Foundation::DateTime DeliveryTime() const;
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> SnoozeInterval() const;
    uint32_t MaximumSnoozeCount() const;
    void Id(hstring_view value) const;
    hstring Id() const;
};

template <typename D>
struct WINRT_EBO impl_IScheduledToastNotification2
{
    void Tag(hstring_view value) const;
    hstring Tag() const;
    void Group(hstring_view value) const;
    hstring Group() const;
    void SuppressPopup(bool value) const;
    bool SuppressPopup() const;
};

template <typename D>
struct WINRT_EBO impl_IScheduledToastNotification3
{
    Windows::UI::Notifications::NotificationMirroring NotificationMirroring() const;
    void NotificationMirroring(Windows::UI::Notifications::NotificationMirroring value) const;
    hstring RemoteId() const;
    void RemoteId(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IScheduledToastNotificationFactory
{
    Windows::UI::Notifications::ScheduledToastNotification CreateScheduledToastNotification(const Windows::Data::Xml::Dom::XmlDocument & content, const Windows::Foundation::DateTime & deliveryTime) const;
    Windows::UI::Notifications::ScheduledToastNotification CreateScheduledToastNotificationRecurring(const Windows::Data::Xml::Dom::XmlDocument & content, const Windows::Foundation::DateTime & deliveryTime, const Windows::Foundation::TimeSpan & snoozeInterval, uint32_t maximumSnoozeCount) const;
};

template <typename D>
struct WINRT_EBO impl_IShownTileNotification
{
    hstring Arguments() const;
};

template <typename D>
struct WINRT_EBO impl_ITileFlyoutNotification
{
    Windows::Data::Xml::Dom::XmlDocument Content() const;
    void ExpirationTime(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> ExpirationTime() const;
};

template <typename D>
struct WINRT_EBO impl_ITileFlyoutNotificationFactory
{
    Windows::UI::Notifications::TileFlyoutNotification CreateTileFlyoutNotification(const Windows::Data::Xml::Dom::XmlDocument & content) const;
};

template <typename D>
struct WINRT_EBO impl_ITileFlyoutUpdateManagerStatics
{
    Windows::UI::Notifications::TileFlyoutUpdater CreateTileFlyoutUpdaterForApplication() const;
    Windows::UI::Notifications::TileFlyoutUpdater CreateTileFlyoutUpdaterForApplication(hstring_view applicationId) const;
    Windows::UI::Notifications::TileFlyoutUpdater CreateTileFlyoutUpdaterForSecondaryTile(hstring_view tileId) const;
    Windows::Data::Xml::Dom::XmlDocument GetTemplateContent(Windows::UI::Notifications::TileFlyoutTemplateType type) const;
};

template <typename D>
struct WINRT_EBO impl_ITileFlyoutUpdater
{
    void Update(const Windows::UI::Notifications::TileFlyoutNotification & notification) const;
    void Clear() const;
    void StartPeriodicUpdate(const Windows::Foundation::Uri & tileFlyoutContent, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) const;
    void StartPeriodicUpdate(const Windows::Foundation::Uri & tileFlyoutContent, const Windows::Foundation::DateTime & startTime, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) const;
    void StopPeriodicUpdate() const;
    Windows::UI::Notifications::NotificationSetting Setting() const;
};

template <typename D>
struct WINRT_EBO impl_ITileNotification
{
    Windows::Data::Xml::Dom::XmlDocument Content() const;
    void ExpirationTime(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> ExpirationTime() const;
    void Tag(hstring_view value) const;
    hstring Tag() const;
};

template <typename D>
struct WINRT_EBO impl_ITileNotificationFactory
{
    Windows::UI::Notifications::TileNotification CreateTileNotification(const Windows::Data::Xml::Dom::XmlDocument & content) const;
};

template <typename D>
struct WINRT_EBO impl_ITileUpdateManagerForUser
{
    Windows::UI::Notifications::TileUpdater CreateTileUpdaterForApplicationForUser() const;
    Windows::UI::Notifications::TileUpdater CreateTileUpdaterForApplication(hstring_view applicationId) const;
    Windows::UI::Notifications::TileUpdater CreateTileUpdaterForSecondaryTile(hstring_view tileId) const;
    Windows::System::User User() const;
};

template <typename D>
struct WINRT_EBO impl_ITileUpdateManagerStatics
{
    Windows::UI::Notifications::TileUpdater CreateTileUpdaterForApplication() const;
    Windows::UI::Notifications::TileUpdater CreateTileUpdaterForApplication(hstring_view applicationId) const;
    Windows::UI::Notifications::TileUpdater CreateTileUpdaterForSecondaryTile(hstring_view tileId) const;
    Windows::Data::Xml::Dom::XmlDocument GetTemplateContent(Windows::UI::Notifications::TileTemplateType type) const;
};

template <typename D>
struct WINRT_EBO impl_ITileUpdateManagerStatics2
{
    Windows::UI::Notifications::TileUpdateManagerForUser GetForUser(const Windows::System::User & user) const;
};

template <typename D>
struct WINRT_EBO impl_ITileUpdater
{
    void Update(const Windows::UI::Notifications::TileNotification & notification) const;
    void Clear() const;
    void EnableNotificationQueue(bool enable) const;
    Windows::UI::Notifications::NotificationSetting Setting() const;
    void AddToSchedule(const Windows::UI::Notifications::ScheduledTileNotification & scheduledTile) const;
    void RemoveFromSchedule(const Windows::UI::Notifications::ScheduledTileNotification & scheduledTile) const;
    Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ScheduledTileNotification> GetScheduledTileNotifications() const;
    void StartPeriodicUpdate(const Windows::Foundation::Uri & tileContent, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) const;
    void StartPeriodicUpdate(const Windows::Foundation::Uri & tileContent, const Windows::Foundation::DateTime & startTime, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) const;
    void StopPeriodicUpdate() const;
    void StartPeriodicUpdateBatch(iterable<Windows::Foundation::Uri> tileContents, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) const;
    void StartPeriodicUpdateBatch(iterable<Windows::Foundation::Uri> tileContents, const Windows::Foundation::DateTime & startTime, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) const;
};

template <typename D>
struct WINRT_EBO impl_ITileUpdater2
{
    void EnableNotificationQueueForSquare150x150(bool enable) const;
    void EnableNotificationQueueForWide310x150(bool enable) const;
    void EnableNotificationQueueForSquare310x310(bool enable) const;
};

template <typename D>
struct WINRT_EBO impl_IToastActivatedEventArgs
{
    hstring Arguments() const;
};

template <typename D>
struct WINRT_EBO impl_IToastDismissedEventArgs
{
    Windows::UI::Notifications::ToastDismissalReason Reason() const;
};

template <typename D>
struct WINRT_EBO impl_IToastFailedEventArgs
{
    HRESULT ErrorCode() const;
};

template <typename D>
struct WINRT_EBO impl_IToastNotification
{
    Windows::Data::Xml::Dom::XmlDocument Content() const;
    void ExpirationTime(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> ExpirationTime() const;
    event_token Dismissed(const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastDismissedEventArgs> & handler) const;
    using Dismissed_revoker = event_revoker<IToastNotification>;
    Dismissed_revoker Dismissed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastDismissedEventArgs> & handler) const;
    void Dismissed(event_token cookie) const;
    event_token Activated(const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::Foundation::IInspectable> & handler) const;
    using Activated_revoker = event_revoker<IToastNotification>;
    Activated_revoker Activated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::Foundation::IInspectable> & handler) const;
    void Activated(event_token cookie) const;
    event_token Failed(const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastFailedEventArgs> & handler) const;
    using Failed_revoker = event_revoker<IToastNotification>;
    Failed_revoker Failed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastFailedEventArgs> & handler) const;
    void Failed(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IToastNotification2
{
    void Tag(hstring_view value) const;
    hstring Tag() const;
    void Group(hstring_view value) const;
    hstring Group() const;
    void SuppressPopup(bool value) const;
    bool SuppressPopup() const;
};

template <typename D>
struct WINRT_EBO impl_IToastNotification3
{
    Windows::UI::Notifications::NotificationMirroring NotificationMirroring() const;
    void NotificationMirroring(Windows::UI::Notifications::NotificationMirroring value) const;
    hstring RemoteId() const;
    void RemoteId(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IToastNotificationActionTriggerDetail
{
    hstring Argument() const;
    Windows::Foundation::Collections::ValueSet UserInput() const;
};

template <typename D>
struct WINRT_EBO impl_IToastNotificationFactory
{
    Windows::UI::Notifications::ToastNotification CreateToastNotification(const Windows::Data::Xml::Dom::XmlDocument & content) const;
};

template <typename D>
struct WINRT_EBO impl_IToastNotificationHistory
{
    void RemoveGroup(hstring_view group) const;
    void RemoveGroup(hstring_view group, hstring_view applicationId) const;
    void Remove(hstring_view tag, hstring_view group, hstring_view applicationId) const;
    void Remove(hstring_view tag, hstring_view group) const;
    void Remove(hstring_view tag) const;
    void Clear() const;
    void Clear(hstring_view applicationId) const;
};

template <typename D>
struct WINRT_EBO impl_IToastNotificationHistory2
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ToastNotification> GetHistory() const;
    Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ToastNotification> GetHistory(hstring_view applicationId) const;
};

template <typename D>
struct WINRT_EBO impl_IToastNotificationHistoryChangedTriggerDetail
{
    Windows::UI::Notifications::ToastHistoryChangedType ChangeType() const;
};

template <typename D>
struct WINRT_EBO impl_IToastNotificationManagerForUser
{
    Windows::UI::Notifications::ToastNotifier CreateToastNotifier() const;
    Windows::UI::Notifications::ToastNotifier CreateToastNotifier(hstring_view applicationId) const;
    Windows::UI::Notifications::ToastNotificationHistory History() const;
    Windows::System::User User() const;
};

template <typename D>
struct WINRT_EBO impl_IToastNotificationManagerStatics
{
    Windows::UI::Notifications::ToastNotifier CreateToastNotifier() const;
    Windows::UI::Notifications::ToastNotifier CreateToastNotifier(hstring_view applicationId) const;
    Windows::Data::Xml::Dom::XmlDocument GetTemplateContent(Windows::UI::Notifications::ToastTemplateType type) const;
};

template <typename D>
struct WINRT_EBO impl_IToastNotificationManagerStatics2
{
    Windows::UI::Notifications::ToastNotificationHistory History() const;
};

template <typename D>
struct WINRT_EBO impl_IToastNotificationManagerStatics4
{
    Windows::UI::Notifications::ToastNotificationManagerForUser GetForUser(const Windows::System::User & user) const;
    void ConfigureNotificationMirroring(Windows::UI::Notifications::NotificationMirroring value) const;
};

template <typename D>
struct WINRT_EBO impl_IToastNotifier
{
    void Show(const Windows::UI::Notifications::ToastNotification & notification) const;
    void Hide(const Windows::UI::Notifications::ToastNotification & notification) const;
    Windows::UI::Notifications::NotificationSetting Setting() const;
    void AddToSchedule(const Windows::UI::Notifications::ScheduledToastNotification & scheduledToast) const;
    void RemoveFromSchedule(const Windows::UI::Notifications::ScheduledToastNotification & scheduledToast) const;
    Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ScheduledToastNotification> GetScheduledToastNotifications() const;
};

template <typename D>
struct WINRT_EBO impl_IUserNotification
{
    Windows::UI::Notifications::Notification Notification() const;
    Windows::ApplicationModel::AppInfo AppInfo() const;
    uint32_t Id() const;
    Windows::Foundation::DateTime CreationTime() const;
};

template <typename D>
struct WINRT_EBO impl_IUserNotificationChangedEventArgs
{
    Windows::UI::Notifications::UserNotificationChangedKind ChangeKind() const;
    uint32_t UserNotificationId() const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Notifications::IAdaptiveNotificationContent>
{
    using abi = ABI::Windows::UI::Notifications::IAdaptiveNotificationContent;
    template <typename D> using consume = Windows::UI::Notifications::impl_IAdaptiveNotificationContent<D>;
};

template <> struct traits<Windows::UI::Notifications::IAdaptiveNotificationText>
{
    using abi = ABI::Windows::UI::Notifications::IAdaptiveNotificationText;
    template <typename D> using consume = Windows::UI::Notifications::impl_IAdaptiveNotificationText<D>;
};

template <> struct traits<Windows::UI::Notifications::IBadgeNotification>
{
    using abi = ABI::Windows::UI::Notifications::IBadgeNotification;
    template <typename D> using consume = Windows::UI::Notifications::impl_IBadgeNotification<D>;
};

template <> struct traits<Windows::UI::Notifications::IBadgeNotificationFactory>
{
    using abi = ABI::Windows::UI::Notifications::IBadgeNotificationFactory;
    template <typename D> using consume = Windows::UI::Notifications::impl_IBadgeNotificationFactory<D>;
};

template <> struct traits<Windows::UI::Notifications::IBadgeUpdateManagerForUser>
{
    using abi = ABI::Windows::UI::Notifications::IBadgeUpdateManagerForUser;
    template <typename D> using consume = Windows::UI::Notifications::impl_IBadgeUpdateManagerForUser<D>;
};

template <> struct traits<Windows::UI::Notifications::IBadgeUpdateManagerStatics>
{
    using abi = ABI::Windows::UI::Notifications::IBadgeUpdateManagerStatics;
    template <typename D> using consume = Windows::UI::Notifications::impl_IBadgeUpdateManagerStatics<D>;
};

template <> struct traits<Windows::UI::Notifications::IBadgeUpdateManagerStatics2>
{
    using abi = ABI::Windows::UI::Notifications::IBadgeUpdateManagerStatics2;
    template <typename D> using consume = Windows::UI::Notifications::impl_IBadgeUpdateManagerStatics2<D>;
};

template <> struct traits<Windows::UI::Notifications::IBadgeUpdater>
{
    using abi = ABI::Windows::UI::Notifications::IBadgeUpdater;
    template <typename D> using consume = Windows::UI::Notifications::impl_IBadgeUpdater<D>;
};

template <> struct traits<Windows::UI::Notifications::IKnownAdaptiveNotificationHintsStatics>
{
    using abi = ABI::Windows::UI::Notifications::IKnownAdaptiveNotificationHintsStatics;
    template <typename D> using consume = Windows::UI::Notifications::impl_IKnownAdaptiveNotificationHintsStatics<D>;
};

template <> struct traits<Windows::UI::Notifications::IKnownAdaptiveNotificationTextStylesStatics>
{
    using abi = ABI::Windows::UI::Notifications::IKnownAdaptiveNotificationTextStylesStatics;
    template <typename D> using consume = Windows::UI::Notifications::impl_IKnownAdaptiveNotificationTextStylesStatics<D>;
};

template <> struct traits<Windows::UI::Notifications::IKnownNotificationBindingsStatics>
{
    using abi = ABI::Windows::UI::Notifications::IKnownNotificationBindingsStatics;
    template <typename D> using consume = Windows::UI::Notifications::impl_IKnownNotificationBindingsStatics<D>;
};

template <> struct traits<Windows::UI::Notifications::INotification>
{
    using abi = ABI::Windows::UI::Notifications::INotification;
    template <typename D> using consume = Windows::UI::Notifications::impl_INotification<D>;
};

template <> struct traits<Windows::UI::Notifications::INotificationBinding>
{
    using abi = ABI::Windows::UI::Notifications::INotificationBinding;
    template <typename D> using consume = Windows::UI::Notifications::impl_INotificationBinding<D>;
};

template <> struct traits<Windows::UI::Notifications::INotificationVisual>
{
    using abi = ABI::Windows::UI::Notifications::INotificationVisual;
    template <typename D> using consume = Windows::UI::Notifications::impl_INotificationVisual<D>;
};

template <> struct traits<Windows::UI::Notifications::IScheduledTileNotification>
{
    using abi = ABI::Windows::UI::Notifications::IScheduledTileNotification;
    template <typename D> using consume = Windows::UI::Notifications::impl_IScheduledTileNotification<D>;
};

template <> struct traits<Windows::UI::Notifications::IScheduledTileNotificationFactory>
{
    using abi = ABI::Windows::UI::Notifications::IScheduledTileNotificationFactory;
    template <typename D> using consume = Windows::UI::Notifications::impl_IScheduledTileNotificationFactory<D>;
};

template <> struct traits<Windows::UI::Notifications::IScheduledToastNotification>
{
    using abi = ABI::Windows::UI::Notifications::IScheduledToastNotification;
    template <typename D> using consume = Windows::UI::Notifications::impl_IScheduledToastNotification<D>;
};

template <> struct traits<Windows::UI::Notifications::IScheduledToastNotification2>
{
    using abi = ABI::Windows::UI::Notifications::IScheduledToastNotification2;
    template <typename D> using consume = Windows::UI::Notifications::impl_IScheduledToastNotification2<D>;
};

template <> struct traits<Windows::UI::Notifications::IScheduledToastNotification3>
{
    using abi = ABI::Windows::UI::Notifications::IScheduledToastNotification3;
    template <typename D> using consume = Windows::UI::Notifications::impl_IScheduledToastNotification3<D>;
};

template <> struct traits<Windows::UI::Notifications::IScheduledToastNotificationFactory>
{
    using abi = ABI::Windows::UI::Notifications::IScheduledToastNotificationFactory;
    template <typename D> using consume = Windows::UI::Notifications::impl_IScheduledToastNotificationFactory<D>;
};

template <> struct traits<Windows::UI::Notifications::IShownTileNotification>
{
    using abi = ABI::Windows::UI::Notifications::IShownTileNotification;
    template <typename D> using consume = Windows::UI::Notifications::impl_IShownTileNotification<D>;
};

template <> struct traits<Windows::UI::Notifications::ITileFlyoutNotification>
{
    using abi = ABI::Windows::UI::Notifications::ITileFlyoutNotification;
    template <typename D> using consume = Windows::UI::Notifications::impl_ITileFlyoutNotification<D>;
};

template <> struct traits<Windows::UI::Notifications::ITileFlyoutNotificationFactory>
{
    using abi = ABI::Windows::UI::Notifications::ITileFlyoutNotificationFactory;
    template <typename D> using consume = Windows::UI::Notifications::impl_ITileFlyoutNotificationFactory<D>;
};

template <> struct traits<Windows::UI::Notifications::ITileFlyoutUpdateManagerStatics>
{
    using abi = ABI::Windows::UI::Notifications::ITileFlyoutUpdateManagerStatics;
    template <typename D> using consume = Windows::UI::Notifications::impl_ITileFlyoutUpdateManagerStatics<D>;
};

template <> struct traits<Windows::UI::Notifications::ITileFlyoutUpdater>
{
    using abi = ABI::Windows::UI::Notifications::ITileFlyoutUpdater;
    template <typename D> using consume = Windows::UI::Notifications::impl_ITileFlyoutUpdater<D>;
};

template <> struct traits<Windows::UI::Notifications::ITileNotification>
{
    using abi = ABI::Windows::UI::Notifications::ITileNotification;
    template <typename D> using consume = Windows::UI::Notifications::impl_ITileNotification<D>;
};

template <> struct traits<Windows::UI::Notifications::ITileNotificationFactory>
{
    using abi = ABI::Windows::UI::Notifications::ITileNotificationFactory;
    template <typename D> using consume = Windows::UI::Notifications::impl_ITileNotificationFactory<D>;
};

template <> struct traits<Windows::UI::Notifications::ITileUpdateManagerForUser>
{
    using abi = ABI::Windows::UI::Notifications::ITileUpdateManagerForUser;
    template <typename D> using consume = Windows::UI::Notifications::impl_ITileUpdateManagerForUser<D>;
};

template <> struct traits<Windows::UI::Notifications::ITileUpdateManagerStatics>
{
    using abi = ABI::Windows::UI::Notifications::ITileUpdateManagerStatics;
    template <typename D> using consume = Windows::UI::Notifications::impl_ITileUpdateManagerStatics<D>;
};

template <> struct traits<Windows::UI::Notifications::ITileUpdateManagerStatics2>
{
    using abi = ABI::Windows::UI::Notifications::ITileUpdateManagerStatics2;
    template <typename D> using consume = Windows::UI::Notifications::impl_ITileUpdateManagerStatics2<D>;
};

template <> struct traits<Windows::UI::Notifications::ITileUpdater>
{
    using abi = ABI::Windows::UI::Notifications::ITileUpdater;
    template <typename D> using consume = Windows::UI::Notifications::impl_ITileUpdater<D>;
};

template <> struct traits<Windows::UI::Notifications::ITileUpdater2>
{
    using abi = ABI::Windows::UI::Notifications::ITileUpdater2;
    template <typename D> using consume = Windows::UI::Notifications::impl_ITileUpdater2<D>;
};

template <> struct traits<Windows::UI::Notifications::IToastActivatedEventArgs>
{
    using abi = ABI::Windows::UI::Notifications::IToastActivatedEventArgs;
    template <typename D> using consume = Windows::UI::Notifications::impl_IToastActivatedEventArgs<D>;
};

template <> struct traits<Windows::UI::Notifications::IToastDismissedEventArgs>
{
    using abi = ABI::Windows::UI::Notifications::IToastDismissedEventArgs;
    template <typename D> using consume = Windows::UI::Notifications::impl_IToastDismissedEventArgs<D>;
};

template <> struct traits<Windows::UI::Notifications::IToastFailedEventArgs>
{
    using abi = ABI::Windows::UI::Notifications::IToastFailedEventArgs;
    template <typename D> using consume = Windows::UI::Notifications::impl_IToastFailedEventArgs<D>;
};

template <> struct traits<Windows::UI::Notifications::IToastNotification>
{
    using abi = ABI::Windows::UI::Notifications::IToastNotification;
    template <typename D> using consume = Windows::UI::Notifications::impl_IToastNotification<D>;
};

template <> struct traits<Windows::UI::Notifications::IToastNotification2>
{
    using abi = ABI::Windows::UI::Notifications::IToastNotification2;
    template <typename D> using consume = Windows::UI::Notifications::impl_IToastNotification2<D>;
};

template <> struct traits<Windows::UI::Notifications::IToastNotification3>
{
    using abi = ABI::Windows::UI::Notifications::IToastNotification3;
    template <typename D> using consume = Windows::UI::Notifications::impl_IToastNotification3<D>;
};

template <> struct traits<Windows::UI::Notifications::IToastNotificationActionTriggerDetail>
{
    using abi = ABI::Windows::UI::Notifications::IToastNotificationActionTriggerDetail;
    template <typename D> using consume = Windows::UI::Notifications::impl_IToastNotificationActionTriggerDetail<D>;
};

template <> struct traits<Windows::UI::Notifications::IToastNotificationFactory>
{
    using abi = ABI::Windows::UI::Notifications::IToastNotificationFactory;
    template <typename D> using consume = Windows::UI::Notifications::impl_IToastNotificationFactory<D>;
};

template <> struct traits<Windows::UI::Notifications::IToastNotificationHistory>
{
    using abi = ABI::Windows::UI::Notifications::IToastNotificationHistory;
    template <typename D> using consume = Windows::UI::Notifications::impl_IToastNotificationHistory<D>;
};

template <> struct traits<Windows::UI::Notifications::IToastNotificationHistory2>
{
    using abi = ABI::Windows::UI::Notifications::IToastNotificationHistory2;
    template <typename D> using consume = Windows::UI::Notifications::impl_IToastNotificationHistory2<D>;
};

template <> struct traits<Windows::UI::Notifications::IToastNotificationHistoryChangedTriggerDetail>
{
    using abi = ABI::Windows::UI::Notifications::IToastNotificationHistoryChangedTriggerDetail;
    template <typename D> using consume = Windows::UI::Notifications::impl_IToastNotificationHistoryChangedTriggerDetail<D>;
};

template <> struct traits<Windows::UI::Notifications::IToastNotificationManagerForUser>
{
    using abi = ABI::Windows::UI::Notifications::IToastNotificationManagerForUser;
    template <typename D> using consume = Windows::UI::Notifications::impl_IToastNotificationManagerForUser<D>;
};

template <> struct traits<Windows::UI::Notifications::IToastNotificationManagerStatics>
{
    using abi = ABI::Windows::UI::Notifications::IToastNotificationManagerStatics;
    template <typename D> using consume = Windows::UI::Notifications::impl_IToastNotificationManagerStatics<D>;
};

template <> struct traits<Windows::UI::Notifications::IToastNotificationManagerStatics2>
{
    using abi = ABI::Windows::UI::Notifications::IToastNotificationManagerStatics2;
    template <typename D> using consume = Windows::UI::Notifications::impl_IToastNotificationManagerStatics2<D>;
};

template <> struct traits<Windows::UI::Notifications::IToastNotificationManagerStatics4>
{
    using abi = ABI::Windows::UI::Notifications::IToastNotificationManagerStatics4;
    template <typename D> using consume = Windows::UI::Notifications::impl_IToastNotificationManagerStatics4<D>;
};

template <> struct traits<Windows::UI::Notifications::IToastNotifier>
{
    using abi = ABI::Windows::UI::Notifications::IToastNotifier;
    template <typename D> using consume = Windows::UI::Notifications::impl_IToastNotifier<D>;
};

template <> struct traits<Windows::UI::Notifications::IUserNotification>
{
    using abi = ABI::Windows::UI::Notifications::IUserNotification;
    template <typename D> using consume = Windows::UI::Notifications::impl_IUserNotification<D>;
};

template <> struct traits<Windows::UI::Notifications::IUserNotificationChangedEventArgs>
{
    using abi = ABI::Windows::UI::Notifications::IUserNotificationChangedEventArgs;
    template <typename D> using consume = Windows::UI::Notifications::impl_IUserNotificationChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Notifications::AdaptiveNotificationText>
{
    using abi = ABI::Windows::UI::Notifications::AdaptiveNotificationText;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.AdaptiveNotificationText"; }
};

template <> struct traits<Windows::UI::Notifications::BadgeNotification>
{
    using abi = ABI::Windows::UI::Notifications::BadgeNotification;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.BadgeNotification"; }
};

template <> struct traits<Windows::UI::Notifications::BadgeUpdateManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.BadgeUpdateManager"; }
};

template <> struct traits<Windows::UI::Notifications::BadgeUpdateManagerForUser>
{
    using abi = ABI::Windows::UI::Notifications::BadgeUpdateManagerForUser;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.BadgeUpdateManagerForUser"; }
};

template <> struct traits<Windows::UI::Notifications::BadgeUpdater>
{
    using abi = ABI::Windows::UI::Notifications::BadgeUpdater;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.BadgeUpdater"; }
};

template <> struct traits<Windows::UI::Notifications::KnownAdaptiveNotificationHints>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.KnownAdaptiveNotificationHints"; }
};

template <> struct traits<Windows::UI::Notifications::KnownAdaptiveNotificationTextStyles>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.KnownAdaptiveNotificationTextStyles"; }
};

template <> struct traits<Windows::UI::Notifications::KnownNotificationBindings>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.KnownNotificationBindings"; }
};

template <> struct traits<Windows::UI::Notifications::Notification>
{
    using abi = ABI::Windows::UI::Notifications::Notification;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.Notification"; }
};

template <> struct traits<Windows::UI::Notifications::NotificationBinding>
{
    using abi = ABI::Windows::UI::Notifications::NotificationBinding;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.NotificationBinding"; }
};

template <> struct traits<Windows::UI::Notifications::NotificationVisual>
{
    using abi = ABI::Windows::UI::Notifications::NotificationVisual;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.NotificationVisual"; }
};

template <> struct traits<Windows::UI::Notifications::ScheduledTileNotification>
{
    using abi = ABI::Windows::UI::Notifications::ScheduledTileNotification;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.ScheduledTileNotification"; }
};

template <> struct traits<Windows::UI::Notifications::ScheduledToastNotification>
{
    using abi = ABI::Windows::UI::Notifications::ScheduledToastNotification;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.ScheduledToastNotification"; }
};

template <> struct traits<Windows::UI::Notifications::ShownTileNotification>
{
    using abi = ABI::Windows::UI::Notifications::ShownTileNotification;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.ShownTileNotification"; }
};

template <> struct traits<Windows::UI::Notifications::TileFlyoutNotification>
{
    using abi = ABI::Windows::UI::Notifications::TileFlyoutNotification;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.TileFlyoutNotification"; }
};

template <> struct traits<Windows::UI::Notifications::TileFlyoutUpdateManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.TileFlyoutUpdateManager"; }
};

template <> struct traits<Windows::UI::Notifications::TileFlyoutUpdater>
{
    using abi = ABI::Windows::UI::Notifications::TileFlyoutUpdater;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.TileFlyoutUpdater"; }
};

template <> struct traits<Windows::UI::Notifications::TileNotification>
{
    using abi = ABI::Windows::UI::Notifications::TileNotification;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.TileNotification"; }
};

template <> struct traits<Windows::UI::Notifications::TileUpdateManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.TileUpdateManager"; }
};

template <> struct traits<Windows::UI::Notifications::TileUpdateManagerForUser>
{
    using abi = ABI::Windows::UI::Notifications::TileUpdateManagerForUser;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.TileUpdateManagerForUser"; }
};

template <> struct traits<Windows::UI::Notifications::TileUpdater>
{
    using abi = ABI::Windows::UI::Notifications::TileUpdater;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.TileUpdater"; }
};

template <> struct traits<Windows::UI::Notifications::ToastActivatedEventArgs>
{
    using abi = ABI::Windows::UI::Notifications::ToastActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.ToastActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::Notifications::ToastDismissedEventArgs>
{
    using abi = ABI::Windows::UI::Notifications::ToastDismissedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.ToastDismissedEventArgs"; }
};

template <> struct traits<Windows::UI::Notifications::ToastFailedEventArgs>
{
    using abi = ABI::Windows::UI::Notifications::ToastFailedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.ToastFailedEventArgs"; }
};

template <> struct traits<Windows::UI::Notifications::ToastNotification>
{
    using abi = ABI::Windows::UI::Notifications::ToastNotification;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.ToastNotification"; }
};

template <> struct traits<Windows::UI::Notifications::ToastNotificationActionTriggerDetail>
{
    using abi = ABI::Windows::UI::Notifications::ToastNotificationActionTriggerDetail;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.ToastNotificationActionTriggerDetail"; }
};

template <> struct traits<Windows::UI::Notifications::ToastNotificationHistory>
{
    using abi = ABI::Windows::UI::Notifications::ToastNotificationHistory;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.ToastNotificationHistory"; }
};

template <> struct traits<Windows::UI::Notifications::ToastNotificationHistoryChangedTriggerDetail>
{
    using abi = ABI::Windows::UI::Notifications::ToastNotificationHistoryChangedTriggerDetail;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.ToastNotificationHistoryChangedTriggerDetail"; }
};

template <> struct traits<Windows::UI::Notifications::ToastNotificationManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.ToastNotificationManager"; }
};

template <> struct traits<Windows::UI::Notifications::ToastNotificationManagerForUser>
{
    using abi = ABI::Windows::UI::Notifications::ToastNotificationManagerForUser;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.ToastNotificationManagerForUser"; }
};

template <> struct traits<Windows::UI::Notifications::ToastNotifier>
{
    using abi = ABI::Windows::UI::Notifications::ToastNotifier;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.ToastNotifier"; }
};

template <> struct traits<Windows::UI::Notifications::UserNotification>
{
    using abi = ABI::Windows::UI::Notifications::UserNotification;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.UserNotification"; }
};

template <> struct traits<Windows::UI::Notifications::UserNotificationChangedEventArgs>
{
    using abi = ABI::Windows::UI::Notifications::UserNotificationChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Notifications.UserNotificationChangedEventArgs"; }
};

}

}
