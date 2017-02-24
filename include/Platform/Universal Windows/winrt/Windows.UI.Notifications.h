// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.ApplicationModel.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Data.Xml.Dom.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.UI.Notifications.3.h"
#include "Windows.UI.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Notifications::IAdaptiveNotificationContent> : produce_base<D, Windows::UI::Notifications::IAdaptiveNotificationContent>
{
    HRESULT __stdcall get_Kind(Windows::UI::Notifications::AdaptiveNotificationContentKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Hints(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Hints());
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
struct produce<D, Windows::UI::Notifications::IAdaptiveNotificationText> : produce_base<D, Windows::UI::Notifications::IAdaptiveNotificationText>
{
    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Text(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Text(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Language(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Language(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Language(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IBadgeNotification> : produce_base<D, Windows::UI::Notifications::IBadgeNotification>
{
    HRESULT __stdcall get_Content(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocument> value) noexcept override
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

    HRESULT __stdcall put_ExpirationTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExpirationTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExpirationTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExpirationTime());
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
struct produce<D, Windows::UI::Notifications::IBadgeNotificationFactory> : produce_base<D, Windows::UI::Notifications::IBadgeNotificationFactory>
{
    HRESULT __stdcall abi_CreateBadgeNotification(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlDocument> content, impl::abi_arg_out<Windows::UI::Notifications::IBadgeNotification> notification) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *notification = detach_abi(this->shim().CreateBadgeNotification(*reinterpret_cast<const Windows::Data::Xml::Dom::XmlDocument *>(&content)));
            return S_OK;
        }
        catch (...)
        {
            *notification = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IBadgeUpdateManagerForUser> : produce_base<D, Windows::UI::Notifications::IBadgeUpdateManagerForUser>
{
    HRESULT __stdcall abi_CreateBadgeUpdaterForApplication(impl::abi_arg_out<Windows::UI::Notifications::IBadgeUpdater> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateBadgeUpdaterForApplication());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateBadgeUpdaterForApplicationWithId(impl::abi_arg_in<hstring> applicationId, impl::abi_arg_out<Windows::UI::Notifications::IBadgeUpdater> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateBadgeUpdaterForApplication(*reinterpret_cast<const hstring *>(&applicationId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateBadgeUpdaterForSecondaryTile(impl::abi_arg_in<hstring> tileId, impl::abi_arg_out<Windows::UI::Notifications::IBadgeUpdater> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateBadgeUpdaterForSecondaryTile(*reinterpret_cast<const hstring *>(&tileId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
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
struct produce<D, Windows::UI::Notifications::IBadgeUpdateManagerStatics> : produce_base<D, Windows::UI::Notifications::IBadgeUpdateManagerStatics>
{
    HRESULT __stdcall abi_CreateBadgeUpdaterForApplication(impl::abi_arg_out<Windows::UI::Notifications::IBadgeUpdater> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateBadgeUpdaterForApplication());
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateBadgeUpdaterForApplicationWithId(impl::abi_arg_in<hstring> applicationId, impl::abi_arg_out<Windows::UI::Notifications::IBadgeUpdater> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateBadgeUpdaterForApplication(*reinterpret_cast<const hstring *>(&applicationId)));
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateBadgeUpdaterForSecondaryTile(impl::abi_arg_in<hstring> tileId, impl::abi_arg_out<Windows::UI::Notifications::IBadgeUpdater> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateBadgeUpdaterForSecondaryTile(*reinterpret_cast<const hstring *>(&tileId)));
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTemplateContent(Windows::UI::Notifications::BadgeTemplateType type, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocument> content) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *content = detach_abi(this->shim().GetTemplateContent(type));
            return S_OK;
        }
        catch (...)
        {
            *content = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IBadgeUpdateManagerStatics2> : produce_base<D, Windows::UI::Notifications::IBadgeUpdateManagerStatics2>
{
    HRESULT __stdcall abi_GetForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_out<Windows::UI::Notifications::IBadgeUpdateManagerForUser> result) noexcept override
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
struct produce<D, Windows::UI::Notifications::IBadgeUpdater> : produce_base<D, Windows::UI::Notifications::IBadgeUpdater>
{
    HRESULT __stdcall abi_Update(impl::abi_arg_in<Windows::UI::Notifications::IBadgeNotification> notification) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Update(*reinterpret_cast<const Windows::UI::Notifications::BadgeNotification *>(&notification));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clear() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartPeriodicUpdate(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> badgeContent, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartPeriodicUpdate(*reinterpret_cast<const Windows::Foundation::Uri *>(&badgeContent), requestedInterval);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartPeriodicUpdateAtTime(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> badgeContent, impl::abi_arg_in<Windows::Foundation::DateTime> startTime, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartPeriodicUpdate(*reinterpret_cast<const Windows::Foundation::Uri *>(&badgeContent), *reinterpret_cast<const Windows::Foundation::DateTime *>(&startTime), requestedInterval);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopPeriodicUpdate() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopPeriodicUpdate();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IKnownAdaptiveNotificationHintsStatics> : produce_base<D, Windows::UI::Notifications::IKnownAdaptiveNotificationHintsStatics>
{
    HRESULT __stdcall get_Style(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Style());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Wrap(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Wrap());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxLines(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxLines());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinLines(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinLines());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextStacking(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextStacking());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Align(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Align());
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
struct produce<D, Windows::UI::Notifications::IKnownAdaptiveNotificationTextStylesStatics> : produce_base<D, Windows::UI::Notifications::IKnownAdaptiveNotificationTextStylesStatics>
{
    HRESULT __stdcall get_Caption(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Caption());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Body(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Body());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Base(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Base());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Subtitle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Subtitle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Subheader(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Subheader());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Header(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Header());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TitleNumeral(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TitleNumeral());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SubheaderNumeral(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SubheaderNumeral());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeaderNumeral(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HeaderNumeral());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CaptionSubtle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CaptionSubtle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BodySubtle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BodySubtle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BaseSubtle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BaseSubtle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SubtitleSubtle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SubtitleSubtle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TitleSubtle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TitleSubtle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SubheaderSubtle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SubheaderSubtle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SubheaderNumeralSubtle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SubheaderNumeralSubtle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeaderSubtle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HeaderSubtle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeaderNumeralSubtle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HeaderNumeralSubtle());
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
struct produce<D, Windows::UI::Notifications::IKnownNotificationBindingsStatics> : produce_base<D, Windows::UI::Notifications::IKnownNotificationBindingsStatics>
{
    HRESULT __stdcall get_ToastGeneric(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToastGeneric());
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
struct produce<D, Windows::UI::Notifications::INotification> : produce_base<D, Windows::UI::Notifications::INotification>
{
    HRESULT __stdcall get_ExpirationTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExpirationTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExpirationTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExpirationTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Visual(impl::abi_arg_out<Windows::UI::Notifications::INotificationVisual> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Visual());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Visual(impl::abi_arg_in<Windows::UI::Notifications::INotificationVisual> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Visual(*reinterpret_cast<const Windows::UI::Notifications::NotificationVisual *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::INotificationBinding> : produce_base<D, Windows::UI::Notifications::INotificationBinding>
{
    HRESULT __stdcall get_Template(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Template());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Template(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Template(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Language(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Language(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Language(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Hints(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Hints());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTextElements(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::AdaptiveNotificationText>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetTextElements());
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
struct produce<D, Windows::UI::Notifications::INotificationVisual> : produce_base<D, Windows::UI::Notifications::INotificationVisual>
{
    HRESULT __stdcall get_Language(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Language(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Language(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Bindings(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Notifications::NotificationBinding>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Bindings());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetBinding(impl::abi_arg_in<hstring> templateName, impl::abi_arg_out<Windows::UI::Notifications::INotificationBinding> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetBinding(*reinterpret_cast<const hstring *>(&templateName)));
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
struct produce<D, Windows::UI::Notifications::IScheduledTileNotification> : produce_base<D, Windows::UI::Notifications::IScheduledTileNotification>
{
    HRESULT __stdcall get_Content(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocument> value) noexcept override
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

    HRESULT __stdcall get_DeliveryTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeliveryTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExpirationTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExpirationTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExpirationTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExpirationTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Tag(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Tag(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Tag(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Tag());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Id(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Id(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
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
struct produce<D, Windows::UI::Notifications::IScheduledTileNotificationFactory> : produce_base<D, Windows::UI::Notifications::IScheduledTileNotificationFactory>
{
    HRESULT __stdcall abi_CreateScheduledTileNotification(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlDocument> content, impl::abi_arg_in<Windows::Foundation::DateTime> deliveryTime, impl::abi_arg_out<Windows::UI::Notifications::IScheduledTileNotification> notification) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *notification = detach_abi(this->shim().CreateScheduledTileNotification(*reinterpret_cast<const Windows::Data::Xml::Dom::XmlDocument *>(&content), *reinterpret_cast<const Windows::Foundation::DateTime *>(&deliveryTime)));
            return S_OK;
        }
        catch (...)
        {
            *notification = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IScheduledToastNotification> : produce_base<D, Windows::UI::Notifications::IScheduledToastNotification>
{
    HRESULT __stdcall get_Content(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocument> value) noexcept override
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

    HRESULT __stdcall get_DeliveryTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeliveryTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SnoozeInterval(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SnoozeInterval());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaximumSnoozeCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaximumSnoozeCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Id(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Id(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
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
struct produce<D, Windows::UI::Notifications::IScheduledToastNotification2> : produce_base<D, Windows::UI::Notifications::IScheduledToastNotification2>
{
    HRESULT __stdcall put_Tag(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Tag(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Tag(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Tag());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Group(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Group(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Group(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Group());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuppressPopup(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuppressPopup(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuppressPopup(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SuppressPopup());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IScheduledToastNotification3> : produce_base<D, Windows::UI::Notifications::IScheduledToastNotification3>
{
    HRESULT __stdcall get_NotificationMirroring(Windows::UI::Notifications::NotificationMirroring * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NotificationMirroring());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NotificationMirroring(Windows::UI::Notifications::NotificationMirroring value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotificationMirroring(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemoteId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RemoteId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IScheduledToastNotificationFactory> : produce_base<D, Windows::UI::Notifications::IScheduledToastNotificationFactory>
{
    HRESULT __stdcall abi_CreateScheduledToastNotification(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlDocument> content, impl::abi_arg_in<Windows::Foundation::DateTime> deliveryTime, impl::abi_arg_out<Windows::UI::Notifications::IScheduledToastNotification> notification) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *notification = detach_abi(this->shim().CreateScheduledToastNotification(*reinterpret_cast<const Windows::Data::Xml::Dom::XmlDocument *>(&content), *reinterpret_cast<const Windows::Foundation::DateTime *>(&deliveryTime)));
            return S_OK;
        }
        catch (...)
        {
            *notification = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateScheduledToastNotificationRecurring(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlDocument> content, impl::abi_arg_in<Windows::Foundation::DateTime> deliveryTime, impl::abi_arg_in<Windows::Foundation::TimeSpan> snoozeInterval, uint32_t maximumSnoozeCount, impl::abi_arg_out<Windows::UI::Notifications::IScheduledToastNotification> notification) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *notification = detach_abi(this->shim().CreateScheduledToastNotificationRecurring(*reinterpret_cast<const Windows::Data::Xml::Dom::XmlDocument *>(&content), *reinterpret_cast<const Windows::Foundation::DateTime *>(&deliveryTime), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&snoozeInterval), maximumSnoozeCount));
            return S_OK;
        }
        catch (...)
        {
            *notification = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IShownTileNotification> : produce_base<D, Windows::UI::Notifications::IShownTileNotification>
{
    HRESULT __stdcall get_Arguments(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Arguments());
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
struct produce<D, Windows::UI::Notifications::ITileFlyoutNotification> : produce_base<D, Windows::UI::Notifications::ITileFlyoutNotification>
{
    HRESULT __stdcall get_Content(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocument> value) noexcept override
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

    HRESULT __stdcall put_ExpirationTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExpirationTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExpirationTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExpirationTime());
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
struct produce<D, Windows::UI::Notifications::ITileFlyoutNotificationFactory> : produce_base<D, Windows::UI::Notifications::ITileFlyoutNotificationFactory>
{
    HRESULT __stdcall abi_CreateTileFlyoutNotification(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlDocument> content, impl::abi_arg_out<Windows::UI::Notifications::ITileFlyoutNotification> notification) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *notification = detach_abi(this->shim().CreateTileFlyoutNotification(*reinterpret_cast<const Windows::Data::Xml::Dom::XmlDocument *>(&content)));
            return S_OK;
        }
        catch (...)
        {
            *notification = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::ITileFlyoutUpdateManagerStatics> : produce_base<D, Windows::UI::Notifications::ITileFlyoutUpdateManagerStatics>
{
    HRESULT __stdcall abi_CreateTileFlyoutUpdaterForApplication(impl::abi_arg_out<Windows::UI::Notifications::ITileFlyoutUpdater> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateTileFlyoutUpdaterForApplication());
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateTileFlyoutUpdaterForApplicationWithId(impl::abi_arg_in<hstring> applicationId, impl::abi_arg_out<Windows::UI::Notifications::ITileFlyoutUpdater> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateTileFlyoutUpdaterForApplication(*reinterpret_cast<const hstring *>(&applicationId)));
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateTileFlyoutUpdaterForSecondaryTile(impl::abi_arg_in<hstring> tileId, impl::abi_arg_out<Windows::UI::Notifications::ITileFlyoutUpdater> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateTileFlyoutUpdaterForSecondaryTile(*reinterpret_cast<const hstring *>(&tileId)));
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTemplateContent(Windows::UI::Notifications::TileFlyoutTemplateType type, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocument> content) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *content = detach_abi(this->shim().GetTemplateContent(type));
            return S_OK;
        }
        catch (...)
        {
            *content = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::ITileFlyoutUpdater> : produce_base<D, Windows::UI::Notifications::ITileFlyoutUpdater>
{
    HRESULT __stdcall abi_Update(impl::abi_arg_in<Windows::UI::Notifications::ITileFlyoutNotification> notification) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Update(*reinterpret_cast<const Windows::UI::Notifications::TileFlyoutNotification *>(&notification));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clear() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartPeriodicUpdate(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> tileFlyoutContent, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartPeriodicUpdate(*reinterpret_cast<const Windows::Foundation::Uri *>(&tileFlyoutContent), requestedInterval);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartPeriodicUpdateAtTime(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> tileFlyoutContent, impl::abi_arg_in<Windows::Foundation::DateTime> startTime, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartPeriodicUpdate(*reinterpret_cast<const Windows::Foundation::Uri *>(&tileFlyoutContent), *reinterpret_cast<const Windows::Foundation::DateTime *>(&startTime), requestedInterval);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopPeriodicUpdate() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopPeriodicUpdate();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Setting(Windows::UI::Notifications::NotificationSetting * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Setting());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::ITileNotification> : produce_base<D, Windows::UI::Notifications::ITileNotification>
{
    HRESULT __stdcall get_Content(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocument> value) noexcept override
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

    HRESULT __stdcall put_ExpirationTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExpirationTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExpirationTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExpirationTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Tag(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Tag(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Tag(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Tag());
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
struct produce<D, Windows::UI::Notifications::ITileNotificationFactory> : produce_base<D, Windows::UI::Notifications::ITileNotificationFactory>
{
    HRESULT __stdcall abi_CreateTileNotification(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlDocument> content, impl::abi_arg_out<Windows::UI::Notifications::ITileNotification> notification) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *notification = detach_abi(this->shim().CreateTileNotification(*reinterpret_cast<const Windows::Data::Xml::Dom::XmlDocument *>(&content)));
            return S_OK;
        }
        catch (...)
        {
            *notification = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::ITileUpdateManagerForUser> : produce_base<D, Windows::UI::Notifications::ITileUpdateManagerForUser>
{
    HRESULT __stdcall abi_CreateTileUpdaterForApplication(impl::abi_arg_out<Windows::UI::Notifications::ITileUpdater> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateTileUpdaterForApplicationForUser());
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateTileUpdaterForApplicationWithId(impl::abi_arg_in<hstring> applicationId, impl::abi_arg_out<Windows::UI::Notifications::ITileUpdater> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateTileUpdaterForApplication(*reinterpret_cast<const hstring *>(&applicationId)));
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateTileUpdaterForSecondaryTile(impl::abi_arg_in<hstring> tileId, impl::abi_arg_out<Windows::UI::Notifications::ITileUpdater> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateTileUpdaterForSecondaryTile(*reinterpret_cast<const hstring *>(&tileId)));
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
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
struct produce<D, Windows::UI::Notifications::ITileUpdateManagerStatics> : produce_base<D, Windows::UI::Notifications::ITileUpdateManagerStatics>
{
    HRESULT __stdcall abi_CreateTileUpdaterForApplication(impl::abi_arg_out<Windows::UI::Notifications::ITileUpdater> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateTileUpdaterForApplication());
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateTileUpdaterForApplicationWithId(impl::abi_arg_in<hstring> applicationId, impl::abi_arg_out<Windows::UI::Notifications::ITileUpdater> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateTileUpdaterForApplication(*reinterpret_cast<const hstring *>(&applicationId)));
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateTileUpdaterForSecondaryTile(impl::abi_arg_in<hstring> tileId, impl::abi_arg_out<Windows::UI::Notifications::ITileUpdater> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateTileUpdaterForSecondaryTile(*reinterpret_cast<const hstring *>(&tileId)));
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTemplateContent(Windows::UI::Notifications::TileTemplateType type, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocument> content) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *content = detach_abi(this->shim().GetTemplateContent(type));
            return S_OK;
        }
        catch (...)
        {
            *content = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::ITileUpdateManagerStatics2> : produce_base<D, Windows::UI::Notifications::ITileUpdateManagerStatics2>
{
    HRESULT __stdcall abi_GetForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_out<Windows::UI::Notifications::ITileUpdateManagerForUser> result) noexcept override
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
struct produce<D, Windows::UI::Notifications::ITileUpdater> : produce_base<D, Windows::UI::Notifications::ITileUpdater>
{
    HRESULT __stdcall abi_Update(impl::abi_arg_in<Windows::UI::Notifications::ITileNotification> notification) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Update(*reinterpret_cast<const Windows::UI::Notifications::TileNotification *>(&notification));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clear() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EnableNotificationQueue(bool enable) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableNotificationQueue(enable);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Setting(Windows::UI::Notifications::NotificationSetting * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Setting());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddToSchedule(impl::abi_arg_in<Windows::UI::Notifications::IScheduledTileNotification> scheduledTile) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddToSchedule(*reinterpret_cast<const Windows::UI::Notifications::ScheduledTileNotification *>(&scheduledTile));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveFromSchedule(impl::abi_arg_in<Windows::UI::Notifications::IScheduledTileNotification> scheduledTile) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveFromSchedule(*reinterpret_cast<const Windows::UI::Notifications::ScheduledTileNotification *>(&scheduledTile));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetScheduledTileNotifications(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ScheduledTileNotification>> scheduledTiles) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *scheduledTiles = detach_abi(this->shim().GetScheduledTileNotifications());
            return S_OK;
        }
        catch (...)
        {
            *scheduledTiles = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartPeriodicUpdate(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> tileContent, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartPeriodicUpdate(*reinterpret_cast<const Windows::Foundation::Uri *>(&tileContent), requestedInterval);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartPeriodicUpdateAtTime(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> tileContent, impl::abi_arg_in<Windows::Foundation::DateTime> startTime, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartPeriodicUpdate(*reinterpret_cast<const Windows::Foundation::Uri *>(&tileContent), *reinterpret_cast<const Windows::Foundation::DateTime *>(&startTime), requestedInterval);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopPeriodicUpdate() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopPeriodicUpdate();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartPeriodicUpdateBatch(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri>> tileContents, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartPeriodicUpdateBatch(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> *>(&tileContents), requestedInterval);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartPeriodicUpdateBatchAtTime(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri>> tileContents, impl::abi_arg_in<Windows::Foundation::DateTime> startTime, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartPeriodicUpdateBatch(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> *>(&tileContents), *reinterpret_cast<const Windows::Foundation::DateTime *>(&startTime), requestedInterval);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::ITileUpdater2> : produce_base<D, Windows::UI::Notifications::ITileUpdater2>
{
    HRESULT __stdcall abi_EnableNotificationQueueForSquare150x150(bool enable) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableNotificationQueueForSquare150x150(enable);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EnableNotificationQueueForWide310x150(bool enable) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableNotificationQueueForWide310x150(enable);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EnableNotificationQueueForSquare310x310(bool enable) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableNotificationQueueForSquare310x310(enable);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IToastActivatedEventArgs> : produce_base<D, Windows::UI::Notifications::IToastActivatedEventArgs>
{
    HRESULT __stdcall get_Arguments(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Arguments());
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
struct produce<D, Windows::UI::Notifications::IToastDismissedEventArgs> : produce_base<D, Windows::UI::Notifications::IToastDismissedEventArgs>
{
    HRESULT __stdcall get_Reason(Windows::UI::Notifications::ToastDismissalReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Reason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IToastFailedEventArgs> : produce_base<D, Windows::UI::Notifications::IToastFailedEventArgs>
{
    HRESULT __stdcall get_ErrorCode(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ErrorCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IToastNotification> : produce_base<D, Windows::UI::Notifications::IToastNotification>
{
    HRESULT __stdcall get_Content(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocument> value) noexcept override
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

    HRESULT __stdcall put_ExpirationTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExpirationTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExpirationTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExpirationTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Dismissed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastDismissedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().Dismissed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastDismissedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Dismissed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Dismissed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Activated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().Activated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Activated(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Activated(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Failed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastFailedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Failed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastFailedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Failed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Failed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IToastNotification2> : produce_base<D, Windows::UI::Notifications::IToastNotification2>
{
    HRESULT __stdcall put_Tag(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Tag(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Tag(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Tag());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Group(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Group(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Group(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Group());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuppressPopup(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuppressPopup(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuppressPopup(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SuppressPopup());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IToastNotification3> : produce_base<D, Windows::UI::Notifications::IToastNotification3>
{
    HRESULT __stdcall get_NotificationMirroring(Windows::UI::Notifications::NotificationMirroring * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NotificationMirroring());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NotificationMirroring(Windows::UI::Notifications::NotificationMirroring value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotificationMirroring(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemoteId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RemoteId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IToastNotificationActionTriggerDetail> : produce_base<D, Windows::UI::Notifications::IToastNotificationActionTriggerDetail>
{
    HRESULT __stdcall get_Argument(impl::abi_arg_out<hstring> argument) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *argument = detach_abi(this->shim().Argument());
            return S_OK;
        }
        catch (...)
        {
            *argument = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserInput(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> inputs) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *inputs = detach_abi(this->shim().UserInput());
            return S_OK;
        }
        catch (...)
        {
            *inputs = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IToastNotificationFactory> : produce_base<D, Windows::UI::Notifications::IToastNotificationFactory>
{
    HRESULT __stdcall abi_CreateToastNotification(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlDocument> content, impl::abi_arg_out<Windows::UI::Notifications::IToastNotification> notification) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *notification = detach_abi(this->shim().CreateToastNotification(*reinterpret_cast<const Windows::Data::Xml::Dom::XmlDocument *>(&content)));
            return S_OK;
        }
        catch (...)
        {
            *notification = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IToastNotificationHistory> : produce_base<D, Windows::UI::Notifications::IToastNotificationHistory>
{
    HRESULT __stdcall abi_RemoveGroup(impl::abi_arg_in<hstring> group) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveGroup(*reinterpret_cast<const hstring *>(&group));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveGroupWithId(impl::abi_arg_in<hstring> group, impl::abi_arg_in<hstring> applicationId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveGroup(*reinterpret_cast<const hstring *>(&group), *reinterpret_cast<const hstring *>(&applicationId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveGroupedTagWithId(impl::abi_arg_in<hstring> tag, impl::abi_arg_in<hstring> group, impl::abi_arg_in<hstring> applicationId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<const hstring *>(&tag), *reinterpret_cast<const hstring *>(&group), *reinterpret_cast<const hstring *>(&applicationId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveGroupedTag(impl::abi_arg_in<hstring> tag, impl::abi_arg_in<hstring> group) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<const hstring *>(&tag), *reinterpret_cast<const hstring *>(&group));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Remove(impl::abi_arg_in<hstring> tag) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<const hstring *>(&tag));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clear() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearWithId(impl::abi_arg_in<hstring> applicationId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear(*reinterpret_cast<const hstring *>(&applicationId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IToastNotificationHistory2> : produce_base<D, Windows::UI::Notifications::IToastNotificationHistory2>
{
    HRESULT __stdcall abi_GetHistory(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ToastNotification>> toasts) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *toasts = detach_abi(this->shim().GetHistory());
            return S_OK;
        }
        catch (...)
        {
            *toasts = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetHistoryWithId(impl::abi_arg_in<hstring> applicationId, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ToastNotification>> toasts) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *toasts = detach_abi(this->shim().GetHistory(*reinterpret_cast<const hstring *>(&applicationId)));
            return S_OK;
        }
        catch (...)
        {
            *toasts = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IToastNotificationHistoryChangedTriggerDetail> : produce_base<D, Windows::UI::Notifications::IToastNotificationHistoryChangedTriggerDetail>
{
    HRESULT __stdcall get_ChangeType(Windows::UI::Notifications::ToastHistoryChangedType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChangeType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IToastNotificationManagerForUser> : produce_base<D, Windows::UI::Notifications::IToastNotificationManagerForUser>
{
    HRESULT __stdcall abi_CreateToastNotifier(impl::abi_arg_out<Windows::UI::Notifications::IToastNotifier> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateToastNotifier());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateToastNotifierWithId(impl::abi_arg_in<hstring> applicationId, impl::abi_arg_out<Windows::UI::Notifications::IToastNotifier> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateToastNotifier(*reinterpret_cast<const hstring *>(&applicationId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_History(impl::abi_arg_out<Windows::UI::Notifications::IToastNotificationHistory> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().History());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
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
struct produce<D, Windows::UI::Notifications::IToastNotificationManagerStatics> : produce_base<D, Windows::UI::Notifications::IToastNotificationManagerStatics>
{
    HRESULT __stdcall abi_CreateToastNotifier(impl::abi_arg_out<Windows::UI::Notifications::IToastNotifier> notifier) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *notifier = detach_abi(this->shim().CreateToastNotifier());
            return S_OK;
        }
        catch (...)
        {
            *notifier = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateToastNotifierWithId(impl::abi_arg_in<hstring> applicationId, impl::abi_arg_out<Windows::UI::Notifications::IToastNotifier> notifier) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *notifier = detach_abi(this->shim().CreateToastNotifier(*reinterpret_cast<const hstring *>(&applicationId)));
            return S_OK;
        }
        catch (...)
        {
            *notifier = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTemplateContent(Windows::UI::Notifications::ToastTemplateType type, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocument> content) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *content = detach_abi(this->shim().GetTemplateContent(type));
            return S_OK;
        }
        catch (...)
        {
            *content = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IToastNotificationManagerStatics2> : produce_base<D, Windows::UI::Notifications::IToastNotificationManagerStatics2>
{
    HRESULT __stdcall get_History(impl::abi_arg_out<Windows::UI::Notifications::IToastNotificationHistory> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().History());
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
struct produce<D, Windows::UI::Notifications::IToastNotificationManagerStatics4> : produce_base<D, Windows::UI::Notifications::IToastNotificationManagerStatics4>
{
    HRESULT __stdcall abi_GetForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_out<Windows::UI::Notifications::IToastNotificationManagerForUser> result) noexcept override
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

    HRESULT __stdcall abi_ConfigureNotificationMirroring(Windows::UI::Notifications::NotificationMirroring value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConfigureNotificationMirroring(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IToastNotifier> : produce_base<D, Windows::UI::Notifications::IToastNotifier>
{
    HRESULT __stdcall abi_Show(impl::abi_arg_in<Windows::UI::Notifications::IToastNotification> notification) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show(*reinterpret_cast<const Windows::UI::Notifications::ToastNotification *>(&notification));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Hide(impl::abi_arg_in<Windows::UI::Notifications::IToastNotification> notification) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Hide(*reinterpret_cast<const Windows::UI::Notifications::ToastNotification *>(&notification));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Setting(Windows::UI::Notifications::NotificationSetting * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Setting());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddToSchedule(impl::abi_arg_in<Windows::UI::Notifications::IScheduledToastNotification> scheduledToast) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddToSchedule(*reinterpret_cast<const Windows::UI::Notifications::ScheduledToastNotification *>(&scheduledToast));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveFromSchedule(impl::abi_arg_in<Windows::UI::Notifications::IScheduledToastNotification> scheduledToast) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveFromSchedule(*reinterpret_cast<const Windows::UI::Notifications::ScheduledToastNotification *>(&scheduledToast));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetScheduledToastNotifications(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ScheduledToastNotification>> scheduledToasts) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *scheduledToasts = detach_abi(this->shim().GetScheduledToastNotifications());
            return S_OK;
        }
        catch (...)
        {
            *scheduledToasts = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IUserNotification> : produce_base<D, Windows::UI::Notifications::IUserNotification>
{
    HRESULT __stdcall get_Notification(impl::abi_arg_out<Windows::UI::Notifications::INotification> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Notification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppInfo(impl::abi_arg_out<Windows::ApplicationModel::IAppInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Id(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CreationTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreationTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Notifications::IUserNotificationChangedEventArgs> : produce_base<D, Windows::UI::Notifications::IUserNotificationChangedEventArgs>
{
    HRESULT __stdcall get_ChangeKind(Windows::UI::Notifications::UserNotificationChangedKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChangeKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserNotificationId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserNotificationId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Notifications {

template <typename D> hstring impl_IShownTileNotification<D>::Arguments() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IShownTileNotification)->get_Arguments(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Notifications::UserNotificationChangedKind impl_IUserNotificationChangedEventArgs<D>::ChangeKind() const
{
    Windows::UI::Notifications::UserNotificationChangedKind value {};
    check_hresult(WINRT_SHIM(IUserNotificationChangedEventArgs)->get_ChangeKind(&value));
    return value;
}

template <typename D> uint32_t impl_IUserNotificationChangedEventArgs<D>::UserNotificationId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUserNotificationChangedEventArgs)->get_UserNotificationId(&value));
    return value;
}

template <typename D> Windows::UI::Notifications::Notification impl_IUserNotification<D>::Notification() const
{
    Windows::UI::Notifications::Notification value { nullptr };
    check_hresult(WINRT_SHIM(IUserNotification)->get_Notification(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::AppInfo impl_IUserNotification<D>::AppInfo() const
{
    Windows::ApplicationModel::AppInfo value { nullptr };
    check_hresult(WINRT_SHIM(IUserNotification)->get_AppInfo(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IUserNotification<D>::Id() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUserNotification)->get_Id(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IUserNotification<D>::CreationTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IUserNotification)->get_CreationTime(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INotificationVisual<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INotificationVisual)->get_Language(put_abi(value)));
    return value;
}

template <typename D> void impl_INotificationVisual<D>::Language(hstring_view value) const
{
    check_hresult(WINRT_SHIM(INotificationVisual)->put_Language(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Notifications::NotificationBinding> impl_INotificationVisual<D>::Bindings() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Notifications::NotificationBinding> result;
    check_hresult(WINRT_SHIM(INotificationVisual)->get_Bindings(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Notifications::NotificationBinding impl_INotificationVisual<D>::GetBinding(hstring_view templateName) const
{
    Windows::UI::Notifications::NotificationBinding result { nullptr };
    check_hresult(WINRT_SHIM(INotificationVisual)->abi_GetBinding(get_abi(templateName), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Notifications::AdaptiveNotificationContentKind impl_IAdaptiveNotificationContent<D>::Kind() const
{
    Windows::UI::Notifications::AdaptiveNotificationContentKind value {};
    check_hresult(WINRT_SHIM(IAdaptiveNotificationContent)->get_Kind(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, hstring> impl_IAdaptiveNotificationContent<D>::Hints() const
{
    Windows::Foundation::Collections::IMap<hstring, hstring> value;
    check_hresult(WINRT_SHIM(IAdaptiveNotificationContent)->get_Hints(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INotificationBinding<D>::Template() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INotificationBinding)->get_Template(put_abi(value)));
    return value;
}

template <typename D> void impl_INotificationBinding<D>::Template(hstring_view value) const
{
    check_hresult(WINRT_SHIM(INotificationBinding)->put_Template(get_abi(value)));
}

template <typename D> hstring impl_INotificationBinding<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INotificationBinding)->get_Language(put_abi(value)));
    return value;
}

template <typename D> void impl_INotificationBinding<D>::Language(hstring_view value) const
{
    check_hresult(WINRT_SHIM(INotificationBinding)->put_Language(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, hstring> impl_INotificationBinding<D>::Hints() const
{
    Windows::Foundation::Collections::IMap<hstring, hstring> value;
    check_hresult(WINRT_SHIM(INotificationBinding)->get_Hints(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::AdaptiveNotificationText> impl_INotificationBinding<D>::GetTextElements() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::AdaptiveNotificationText> result;
    check_hresult(WINRT_SHIM(INotificationBinding)->abi_GetTextElements(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IKnownNotificationBindingsStatics<D>::ToastGeneric() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownNotificationBindingsStatics)->get_ToastGeneric(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationHintsStatics<D>::Style() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationHintsStatics)->get_Style(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationHintsStatics<D>::Wrap() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationHintsStatics)->get_Wrap(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationHintsStatics<D>::MaxLines() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationHintsStatics)->get_MaxLines(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationHintsStatics<D>::MinLines() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationHintsStatics)->get_MinLines(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationHintsStatics<D>::TextStacking() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationHintsStatics)->get_TextStacking(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationHintsStatics<D>::Align() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationHintsStatics)->get_Align(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::Caption() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_Caption(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::Body() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_Body(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::Base() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_Base(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::Subtitle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_Subtitle(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_Title(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::Subheader() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_Subheader(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::Header() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_Header(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::TitleNumeral() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_TitleNumeral(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::SubheaderNumeral() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_SubheaderNumeral(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::HeaderNumeral() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_HeaderNumeral(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::CaptionSubtle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_CaptionSubtle(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::BodySubtle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_BodySubtle(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::BaseSubtle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_BaseSubtle(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::SubtitleSubtle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_SubtitleSubtle(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::TitleSubtle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_TitleSubtle(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::SubheaderSubtle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_SubheaderSubtle(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::SubheaderNumeralSubtle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_SubheaderNumeralSubtle(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::HeaderSubtle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_HeaderSubtle(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownAdaptiveNotificationTextStylesStatics<D>::HeaderNumeralSubtle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownAdaptiveNotificationTextStylesStatics)->get_HeaderNumeralSubtle(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAdaptiveNotificationText<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAdaptiveNotificationText)->get_Text(put_abi(value)));
    return value;
}

template <typename D> void impl_IAdaptiveNotificationText<D>::Text(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAdaptiveNotificationText)->put_Text(get_abi(value)));
}

template <typename D> hstring impl_IAdaptiveNotificationText<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAdaptiveNotificationText)->get_Language(put_abi(value)));
    return value;
}

template <typename D> void impl_IAdaptiveNotificationText<D>::Language(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAdaptiveNotificationText)->put_Language(get_abi(value)));
}

template <typename D> Windows::UI::Notifications::ToastDismissalReason impl_IToastDismissedEventArgs<D>::Reason() const
{
    Windows::UI::Notifications::ToastDismissalReason value {};
    check_hresult(WINRT_SHIM(IToastDismissedEventArgs)->get_Reason(&value));
    return value;
}

template <typename D> HRESULT impl_IToastFailedEventArgs<D>::ErrorCode() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IToastFailedEventArgs)->get_ErrorCode(&value));
    return value;
}

template <typename D> hstring impl_IToastActivatedEventArgs<D>::Arguments() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IToastActivatedEventArgs)->get_Arguments(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Notifications::TileUpdater impl_ITileUpdateManagerStatics<D>::CreateTileUpdaterForApplication() const
{
    Windows::UI::Notifications::TileUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(ITileUpdateManagerStatics)->abi_CreateTileUpdaterForApplication(put_abi(updater)));
    return updater;
}

template <typename D> Windows::UI::Notifications::TileUpdater impl_ITileUpdateManagerStatics<D>::CreateTileUpdaterForApplication(hstring_view applicationId) const
{
    Windows::UI::Notifications::TileUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(ITileUpdateManagerStatics)->abi_CreateTileUpdaterForApplicationWithId(get_abi(applicationId), put_abi(updater)));
    return updater;
}

template <typename D> Windows::UI::Notifications::TileUpdater impl_ITileUpdateManagerStatics<D>::CreateTileUpdaterForSecondaryTile(hstring_view tileId) const
{
    Windows::UI::Notifications::TileUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(ITileUpdateManagerStatics)->abi_CreateTileUpdaterForSecondaryTile(get_abi(tileId), put_abi(updater)));
    return updater;
}

template <typename D> Windows::Data::Xml::Dom::XmlDocument impl_ITileUpdateManagerStatics<D>::GetTemplateContent(Windows::UI::Notifications::TileTemplateType type) const
{
    Windows::Data::Xml::Dom::XmlDocument content { nullptr };
    check_hresult(WINRT_SHIM(ITileUpdateManagerStatics)->abi_GetTemplateContent(type, put_abi(content)));
    return content;
}

template <typename D> Windows::UI::Notifications::TileUpdateManagerForUser impl_ITileUpdateManagerStatics2<D>::GetForUser(const Windows::System::User & user) const
{
    Windows::UI::Notifications::TileUpdateManagerForUser result { nullptr };
    check_hresult(WINRT_SHIM(ITileUpdateManagerStatics2)->abi_GetForUser(get_abi(user), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Notifications::TileUpdater impl_ITileUpdateManagerForUser<D>::CreateTileUpdaterForApplicationForUser() const
{
    Windows::UI::Notifications::TileUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(ITileUpdateManagerForUser)->abi_CreateTileUpdaterForApplication(put_abi(updater)));
    return updater;
}

template <typename D> Windows::UI::Notifications::TileUpdater impl_ITileUpdateManagerForUser<D>::CreateTileUpdaterForApplication(hstring_view applicationId) const
{
    Windows::UI::Notifications::TileUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(ITileUpdateManagerForUser)->abi_CreateTileUpdaterForApplicationWithId(get_abi(applicationId), put_abi(updater)));
    return updater;
}

template <typename D> Windows::UI::Notifications::TileUpdater impl_ITileUpdateManagerForUser<D>::CreateTileUpdaterForSecondaryTile(hstring_view tileId) const
{
    Windows::UI::Notifications::TileUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(ITileUpdateManagerForUser)->abi_CreateTileUpdaterForSecondaryTile(get_abi(tileId), put_abi(updater)));
    return updater;
}

template <typename D> Windows::System::User impl_ITileUpdateManagerForUser<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(ITileUpdateManagerForUser)->get_User(put_abi(value)));
    return value;
}

template <typename D> void impl_ITileUpdater<D>::Update(const Windows::UI::Notifications::TileNotification & notification) const
{
    check_hresult(WINRT_SHIM(ITileUpdater)->abi_Update(get_abi(notification)));
}

template <typename D> void impl_ITileUpdater<D>::Clear() const
{
    check_hresult(WINRT_SHIM(ITileUpdater)->abi_Clear());
}

template <typename D> void impl_ITileUpdater<D>::EnableNotificationQueue(bool enable) const
{
    check_hresult(WINRT_SHIM(ITileUpdater)->abi_EnableNotificationQueue(enable));
}

template <typename D> Windows::UI::Notifications::NotificationSetting impl_ITileUpdater<D>::Setting() const
{
    Windows::UI::Notifications::NotificationSetting value {};
    check_hresult(WINRT_SHIM(ITileUpdater)->get_Setting(&value));
    return value;
}

template <typename D> void impl_ITileUpdater<D>::AddToSchedule(const Windows::UI::Notifications::ScheduledTileNotification & scheduledTile) const
{
    check_hresult(WINRT_SHIM(ITileUpdater)->abi_AddToSchedule(get_abi(scheduledTile)));
}

template <typename D> void impl_ITileUpdater<D>::RemoveFromSchedule(const Windows::UI::Notifications::ScheduledTileNotification & scheduledTile) const
{
    check_hresult(WINRT_SHIM(ITileUpdater)->abi_RemoveFromSchedule(get_abi(scheduledTile)));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ScheduledTileNotification> impl_ITileUpdater<D>::GetScheduledTileNotifications() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ScheduledTileNotification> scheduledTiles;
    check_hresult(WINRT_SHIM(ITileUpdater)->abi_GetScheduledTileNotifications(put_abi(scheduledTiles)));
    return scheduledTiles;
}

template <typename D> void impl_ITileUpdater<D>::StartPeriodicUpdate(const Windows::Foundation::Uri & tileContent, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) const
{
    check_hresult(WINRT_SHIM(ITileUpdater)->abi_StartPeriodicUpdate(get_abi(tileContent), requestedInterval));
}

template <typename D> void impl_ITileUpdater<D>::StartPeriodicUpdate(const Windows::Foundation::Uri & tileContent, const Windows::Foundation::DateTime & startTime, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) const
{
    check_hresult(WINRT_SHIM(ITileUpdater)->abi_StartPeriodicUpdateAtTime(get_abi(tileContent), get_abi(startTime), requestedInterval));
}

template <typename D> void impl_ITileUpdater<D>::StopPeriodicUpdate() const
{
    check_hresult(WINRT_SHIM(ITileUpdater)->abi_StopPeriodicUpdate());
}

template <typename D> void impl_ITileUpdater<D>::StartPeriodicUpdateBatch(iterable<Windows::Foundation::Uri> tileContents, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) const
{
    check_hresult(WINRT_SHIM(ITileUpdater)->abi_StartPeriodicUpdateBatch(get_abi(tileContents), requestedInterval));
}

template <typename D> void impl_ITileUpdater<D>::StartPeriodicUpdateBatch(iterable<Windows::Foundation::Uri> tileContents, const Windows::Foundation::DateTime & startTime, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) const
{
    check_hresult(WINRT_SHIM(ITileUpdater)->abi_StartPeriodicUpdateBatchAtTime(get_abi(tileContents), get_abi(startTime), requestedInterval));
}

template <typename D> void impl_ITileUpdater2<D>::EnableNotificationQueueForSquare150x150(bool enable) const
{
    check_hresult(WINRT_SHIM(ITileUpdater2)->abi_EnableNotificationQueueForSquare150x150(enable));
}

template <typename D> void impl_ITileUpdater2<D>::EnableNotificationQueueForWide310x150(bool enable) const
{
    check_hresult(WINRT_SHIM(ITileUpdater2)->abi_EnableNotificationQueueForWide310x150(enable));
}

template <typename D> void impl_ITileUpdater2<D>::EnableNotificationQueueForSquare310x310(bool enable) const
{
    check_hresult(WINRT_SHIM(ITileUpdater2)->abi_EnableNotificationQueueForSquare310x310(enable));
}

template <typename D> Windows::UI::Notifications::TileFlyoutUpdater impl_ITileFlyoutUpdateManagerStatics<D>::CreateTileFlyoutUpdaterForApplication() const
{
    Windows::UI::Notifications::TileFlyoutUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(ITileFlyoutUpdateManagerStatics)->abi_CreateTileFlyoutUpdaterForApplication(put_abi(updater)));
    return updater;
}

template <typename D> Windows::UI::Notifications::TileFlyoutUpdater impl_ITileFlyoutUpdateManagerStatics<D>::CreateTileFlyoutUpdaterForApplication(hstring_view applicationId) const
{
    Windows::UI::Notifications::TileFlyoutUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(ITileFlyoutUpdateManagerStatics)->abi_CreateTileFlyoutUpdaterForApplicationWithId(get_abi(applicationId), put_abi(updater)));
    return updater;
}

template <typename D> Windows::UI::Notifications::TileFlyoutUpdater impl_ITileFlyoutUpdateManagerStatics<D>::CreateTileFlyoutUpdaterForSecondaryTile(hstring_view tileId) const
{
    Windows::UI::Notifications::TileFlyoutUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(ITileFlyoutUpdateManagerStatics)->abi_CreateTileFlyoutUpdaterForSecondaryTile(get_abi(tileId), put_abi(updater)));
    return updater;
}

template <typename D> Windows::Data::Xml::Dom::XmlDocument impl_ITileFlyoutUpdateManagerStatics<D>::GetTemplateContent(Windows::UI::Notifications::TileFlyoutTemplateType type) const
{
    Windows::Data::Xml::Dom::XmlDocument content { nullptr };
    check_hresult(WINRT_SHIM(ITileFlyoutUpdateManagerStatics)->abi_GetTemplateContent(type, put_abi(content)));
    return content;
}

template <typename D> void impl_ITileFlyoutUpdater<D>::Update(const Windows::UI::Notifications::TileFlyoutNotification & notification) const
{
    check_hresult(WINRT_SHIM(ITileFlyoutUpdater)->abi_Update(get_abi(notification)));
}

template <typename D> void impl_ITileFlyoutUpdater<D>::Clear() const
{
    check_hresult(WINRT_SHIM(ITileFlyoutUpdater)->abi_Clear());
}

template <typename D> void impl_ITileFlyoutUpdater<D>::StartPeriodicUpdate(const Windows::Foundation::Uri & tileFlyoutContent, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) const
{
    check_hresult(WINRT_SHIM(ITileFlyoutUpdater)->abi_StartPeriodicUpdate(get_abi(tileFlyoutContent), requestedInterval));
}

template <typename D> void impl_ITileFlyoutUpdater<D>::StartPeriodicUpdate(const Windows::Foundation::Uri & tileFlyoutContent, const Windows::Foundation::DateTime & startTime, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) const
{
    check_hresult(WINRT_SHIM(ITileFlyoutUpdater)->abi_StartPeriodicUpdateAtTime(get_abi(tileFlyoutContent), get_abi(startTime), requestedInterval));
}

template <typename D> void impl_ITileFlyoutUpdater<D>::StopPeriodicUpdate() const
{
    check_hresult(WINRT_SHIM(ITileFlyoutUpdater)->abi_StopPeriodicUpdate());
}

template <typename D> Windows::UI::Notifications::NotificationSetting impl_ITileFlyoutUpdater<D>::Setting() const
{
    Windows::UI::Notifications::NotificationSetting value {};
    check_hresult(WINRT_SHIM(ITileFlyoutUpdater)->get_Setting(&value));
    return value;
}

template <typename D> Windows::UI::Notifications::BadgeUpdater impl_IBadgeUpdateManagerStatics<D>::CreateBadgeUpdaterForApplication() const
{
    Windows::UI::Notifications::BadgeUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(IBadgeUpdateManagerStatics)->abi_CreateBadgeUpdaterForApplication(put_abi(updater)));
    return updater;
}

template <typename D> Windows::UI::Notifications::BadgeUpdater impl_IBadgeUpdateManagerStatics<D>::CreateBadgeUpdaterForApplication(hstring_view applicationId) const
{
    Windows::UI::Notifications::BadgeUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(IBadgeUpdateManagerStatics)->abi_CreateBadgeUpdaterForApplicationWithId(get_abi(applicationId), put_abi(updater)));
    return updater;
}

template <typename D> Windows::UI::Notifications::BadgeUpdater impl_IBadgeUpdateManagerStatics<D>::CreateBadgeUpdaterForSecondaryTile(hstring_view tileId) const
{
    Windows::UI::Notifications::BadgeUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(IBadgeUpdateManagerStatics)->abi_CreateBadgeUpdaterForSecondaryTile(get_abi(tileId), put_abi(updater)));
    return updater;
}

template <typename D> Windows::Data::Xml::Dom::XmlDocument impl_IBadgeUpdateManagerStatics<D>::GetTemplateContent(Windows::UI::Notifications::BadgeTemplateType type) const
{
    Windows::Data::Xml::Dom::XmlDocument content { nullptr };
    check_hresult(WINRT_SHIM(IBadgeUpdateManagerStatics)->abi_GetTemplateContent(type, put_abi(content)));
    return content;
}

template <typename D> Windows::UI::Notifications::BadgeUpdateManagerForUser impl_IBadgeUpdateManagerStatics2<D>::GetForUser(const Windows::System::User & user) const
{
    Windows::UI::Notifications::BadgeUpdateManagerForUser result { nullptr };
    check_hresult(WINRT_SHIM(IBadgeUpdateManagerStatics2)->abi_GetForUser(get_abi(user), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Notifications::BadgeUpdater impl_IBadgeUpdateManagerForUser<D>::CreateBadgeUpdaterForApplication() const
{
    Windows::UI::Notifications::BadgeUpdater result { nullptr };
    check_hresult(WINRT_SHIM(IBadgeUpdateManagerForUser)->abi_CreateBadgeUpdaterForApplication(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Notifications::BadgeUpdater impl_IBadgeUpdateManagerForUser<D>::CreateBadgeUpdaterForApplication(hstring_view applicationId) const
{
    Windows::UI::Notifications::BadgeUpdater result { nullptr };
    check_hresult(WINRT_SHIM(IBadgeUpdateManagerForUser)->abi_CreateBadgeUpdaterForApplicationWithId(get_abi(applicationId), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Notifications::BadgeUpdater impl_IBadgeUpdateManagerForUser<D>::CreateBadgeUpdaterForSecondaryTile(hstring_view tileId) const
{
    Windows::UI::Notifications::BadgeUpdater result { nullptr };
    check_hresult(WINRT_SHIM(IBadgeUpdateManagerForUser)->abi_CreateBadgeUpdaterForSecondaryTile(get_abi(tileId), put_abi(result)));
    return result;
}

template <typename D> Windows::System::User impl_IBadgeUpdateManagerForUser<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IBadgeUpdateManagerForUser)->get_User(put_abi(value)));
    return value;
}

template <typename D> void impl_IBadgeUpdater<D>::Update(const Windows::UI::Notifications::BadgeNotification & notification) const
{
    check_hresult(WINRT_SHIM(IBadgeUpdater)->abi_Update(get_abi(notification)));
}

template <typename D> void impl_IBadgeUpdater<D>::Clear() const
{
    check_hresult(WINRT_SHIM(IBadgeUpdater)->abi_Clear());
}

template <typename D> void impl_IBadgeUpdater<D>::StartPeriodicUpdate(const Windows::Foundation::Uri & badgeContent, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) const
{
    check_hresult(WINRT_SHIM(IBadgeUpdater)->abi_StartPeriodicUpdate(get_abi(badgeContent), requestedInterval));
}

template <typename D> void impl_IBadgeUpdater<D>::StartPeriodicUpdate(const Windows::Foundation::Uri & badgeContent, const Windows::Foundation::DateTime & startTime, Windows::UI::Notifications::PeriodicUpdateRecurrence requestedInterval) const
{
    check_hresult(WINRT_SHIM(IBadgeUpdater)->abi_StartPeriodicUpdateAtTime(get_abi(badgeContent), get_abi(startTime), requestedInterval));
}

template <typename D> void impl_IBadgeUpdater<D>::StopPeriodicUpdate() const
{
    check_hresult(WINRT_SHIM(IBadgeUpdater)->abi_StopPeriodicUpdate());
}

template <typename D> Windows::UI::Notifications::ToastNotifier impl_IToastNotificationManagerStatics<D>::CreateToastNotifier() const
{
    Windows::UI::Notifications::ToastNotifier notifier { nullptr };
    check_hresult(WINRT_SHIM(IToastNotificationManagerStatics)->abi_CreateToastNotifier(put_abi(notifier)));
    return notifier;
}

template <typename D> Windows::UI::Notifications::ToastNotifier impl_IToastNotificationManagerStatics<D>::CreateToastNotifier(hstring_view applicationId) const
{
    Windows::UI::Notifications::ToastNotifier notifier { nullptr };
    check_hresult(WINRT_SHIM(IToastNotificationManagerStatics)->abi_CreateToastNotifierWithId(get_abi(applicationId), put_abi(notifier)));
    return notifier;
}

template <typename D> Windows::Data::Xml::Dom::XmlDocument impl_IToastNotificationManagerStatics<D>::GetTemplateContent(Windows::UI::Notifications::ToastTemplateType type) const
{
    Windows::Data::Xml::Dom::XmlDocument content { nullptr };
    check_hresult(WINRT_SHIM(IToastNotificationManagerStatics)->abi_GetTemplateContent(type, put_abi(content)));
    return content;
}

template <typename D> void impl_IToastNotifier<D>::Show(const Windows::UI::Notifications::ToastNotification & notification) const
{
    check_hresult(WINRT_SHIM(IToastNotifier)->abi_Show(get_abi(notification)));
}

template <typename D> void impl_IToastNotifier<D>::Hide(const Windows::UI::Notifications::ToastNotification & notification) const
{
    check_hresult(WINRT_SHIM(IToastNotifier)->abi_Hide(get_abi(notification)));
}

template <typename D> Windows::UI::Notifications::NotificationSetting impl_IToastNotifier<D>::Setting() const
{
    Windows::UI::Notifications::NotificationSetting value {};
    check_hresult(WINRT_SHIM(IToastNotifier)->get_Setting(&value));
    return value;
}

template <typename D> void impl_IToastNotifier<D>::AddToSchedule(const Windows::UI::Notifications::ScheduledToastNotification & scheduledToast) const
{
    check_hresult(WINRT_SHIM(IToastNotifier)->abi_AddToSchedule(get_abi(scheduledToast)));
}

template <typename D> void impl_IToastNotifier<D>::RemoveFromSchedule(const Windows::UI::Notifications::ScheduledToastNotification & scheduledToast) const
{
    check_hresult(WINRT_SHIM(IToastNotifier)->abi_RemoveFromSchedule(get_abi(scheduledToast)));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ScheduledToastNotification> impl_IToastNotifier<D>::GetScheduledToastNotifications() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ScheduledToastNotification> scheduledToasts;
    check_hresult(WINRT_SHIM(IToastNotifier)->abi_GetScheduledToastNotifications(put_abi(scheduledToasts)));
    return scheduledToasts;
}

template <typename D> Windows::UI::Notifications::TileNotification impl_ITileNotificationFactory<D>::CreateTileNotification(const Windows::Data::Xml::Dom::XmlDocument & content) const
{
    Windows::UI::Notifications::TileNotification notification { nullptr };
    check_hresult(WINRT_SHIM(ITileNotificationFactory)->abi_CreateTileNotification(get_abi(content), put_abi(notification)));
    return notification;
}

template <typename D> Windows::Data::Xml::Dom::XmlDocument impl_ITileNotification<D>::Content() const
{
    Windows::Data::Xml::Dom::XmlDocument value { nullptr };
    check_hresult(WINRT_SHIM(ITileNotification)->get_Content(put_abi(value)));
    return value;
}

template <typename D> void impl_ITileNotification<D>::ExpirationTime(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(ITileNotification)->put_ExpirationTime(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_ITileNotification<D>::ExpirationTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(ITileNotification)->get_ExpirationTime(put_abi(value)));
    return value;
}

template <typename D> void impl_ITileNotification<D>::Tag(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ITileNotification)->put_Tag(get_abi(value)));
}

template <typename D> hstring impl_ITileNotification<D>::Tag() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITileNotification)->get_Tag(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Notifications::TileFlyoutNotification impl_ITileFlyoutNotificationFactory<D>::CreateTileFlyoutNotification(const Windows::Data::Xml::Dom::XmlDocument & content) const
{
    Windows::UI::Notifications::TileFlyoutNotification notification { nullptr };
    check_hresult(WINRT_SHIM(ITileFlyoutNotificationFactory)->abi_CreateTileFlyoutNotification(get_abi(content), put_abi(notification)));
    return notification;
}

template <typename D> Windows::Data::Xml::Dom::XmlDocument impl_ITileFlyoutNotification<D>::Content() const
{
    Windows::Data::Xml::Dom::XmlDocument value { nullptr };
    check_hresult(WINRT_SHIM(ITileFlyoutNotification)->get_Content(put_abi(value)));
    return value;
}

template <typename D> void impl_ITileFlyoutNotification<D>::ExpirationTime(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(ITileFlyoutNotification)->put_ExpirationTime(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_ITileFlyoutNotification<D>::ExpirationTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(ITileFlyoutNotification)->get_ExpirationTime(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Notifications::BadgeNotification impl_IBadgeNotificationFactory<D>::CreateBadgeNotification(const Windows::Data::Xml::Dom::XmlDocument & content) const
{
    Windows::UI::Notifications::BadgeNotification notification { nullptr };
    check_hresult(WINRT_SHIM(IBadgeNotificationFactory)->abi_CreateBadgeNotification(get_abi(content), put_abi(notification)));
    return notification;
}

template <typename D> Windows::Data::Xml::Dom::XmlDocument impl_IBadgeNotification<D>::Content() const
{
    Windows::Data::Xml::Dom::XmlDocument value { nullptr };
    check_hresult(WINRT_SHIM(IBadgeNotification)->get_Content(put_abi(value)));
    return value;
}

template <typename D> void impl_IBadgeNotification<D>::ExpirationTime(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IBadgeNotification)->put_ExpirationTime(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IBadgeNotification<D>::ExpirationTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IBadgeNotification)->get_ExpirationTime(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Notifications::ToastNotification impl_IToastNotificationFactory<D>::CreateToastNotification(const Windows::Data::Xml::Dom::XmlDocument & content) const
{
    Windows::UI::Notifications::ToastNotification notification { nullptr };
    check_hresult(WINRT_SHIM(IToastNotificationFactory)->abi_CreateToastNotification(get_abi(content), put_abi(notification)));
    return notification;
}

template <typename D> Windows::Data::Xml::Dom::XmlDocument impl_IToastNotification<D>::Content() const
{
    Windows::Data::Xml::Dom::XmlDocument value { nullptr };
    check_hresult(WINRT_SHIM(IToastNotification)->get_Content(put_abi(value)));
    return value;
}

template <typename D> void impl_IToastNotification<D>::ExpirationTime(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IToastNotification)->put_ExpirationTime(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IToastNotification<D>::ExpirationTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IToastNotification)->get_ExpirationTime(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IToastNotification<D>::Dismissed(const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastDismissedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IToastNotification)->add_Dismissed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IToastNotification> impl_IToastNotification<D>::Dismissed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastDismissedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IToastNotification>(this, &ABI::Windows::UI::Notifications::IToastNotification::remove_Dismissed, Dismissed(handler));
}

template <typename D> void impl_IToastNotification<D>::Dismissed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IToastNotification)->remove_Dismissed(cookie));
}

template <typename D> event_token impl_IToastNotification<D>::Activated(const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IToastNotification)->add_Activated(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IToastNotification> impl_IToastNotification<D>::Activated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IToastNotification>(this, &ABI::Windows::UI::Notifications::IToastNotification::remove_Activated, Activated(handler));
}

template <typename D> void impl_IToastNotification<D>::Activated(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IToastNotification)->remove_Activated(cookie));
}

template <typename D> event_token impl_IToastNotification<D>::Failed(const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastFailedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IToastNotification)->add_Failed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IToastNotification> impl_IToastNotification<D>::Failed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Notifications::ToastNotification, Windows::UI::Notifications::ToastFailedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IToastNotification>(this, &ABI::Windows::UI::Notifications::IToastNotification::remove_Failed, Failed(handler));
}

template <typename D> void impl_IToastNotification<D>::Failed(event_token token) const
{
    check_hresult(WINRT_SHIM(IToastNotification)->remove_Failed(token));
}

template <typename D> void impl_IToastNotification2<D>::Tag(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IToastNotification2)->put_Tag(get_abi(value)));
}

template <typename D> hstring impl_IToastNotification2<D>::Tag() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IToastNotification2)->get_Tag(put_abi(value)));
    return value;
}

template <typename D> void impl_IToastNotification2<D>::Group(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IToastNotification2)->put_Group(get_abi(value)));
}

template <typename D> hstring impl_IToastNotification2<D>::Group() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IToastNotification2)->get_Group(put_abi(value)));
    return value;
}

template <typename D> void impl_IToastNotification2<D>::SuppressPopup(bool value) const
{
    check_hresult(WINRT_SHIM(IToastNotification2)->put_SuppressPopup(value));
}

template <typename D> bool impl_IToastNotification2<D>::SuppressPopup() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IToastNotification2)->get_SuppressPopup(&value));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_INotification<D>::ExpirationTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(INotification)->get_ExpirationTime(put_abi(value)));
    return value;
}

template <typename D> void impl_INotification<D>::ExpirationTime(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(INotification)->put_ExpirationTime(get_abi(value)));
}

template <typename D> Windows::UI::Notifications::NotificationVisual impl_INotification<D>::Visual() const
{
    Windows::UI::Notifications::NotificationVisual value { nullptr };
    check_hresult(WINRT_SHIM(INotification)->get_Visual(put_abi(value)));
    return value;
}

template <typename D> void impl_INotification<D>::Visual(const Windows::UI::Notifications::NotificationVisual & value) const
{
    check_hresult(WINRT_SHIM(INotification)->put_Visual(get_abi(value)));
}

template <typename D> Windows::UI::Notifications::NotificationMirroring impl_IToastNotification3<D>::NotificationMirroring() const
{
    Windows::UI::Notifications::NotificationMirroring value {};
    check_hresult(WINRT_SHIM(IToastNotification3)->get_NotificationMirroring(&value));
    return value;
}

template <typename D> void impl_IToastNotification3<D>::NotificationMirroring(Windows::UI::Notifications::NotificationMirroring value) const
{
    check_hresult(WINRT_SHIM(IToastNotification3)->put_NotificationMirroring(value));
}

template <typename D> hstring impl_IToastNotification3<D>::RemoteId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IToastNotification3)->get_RemoteId(put_abi(value)));
    return value;
}

template <typename D> void impl_IToastNotification3<D>::RemoteId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IToastNotification3)->put_RemoteId(get_abi(value)));
}

template <typename D> Windows::UI::Notifications::ScheduledToastNotification impl_IScheduledToastNotificationFactory<D>::CreateScheduledToastNotification(const Windows::Data::Xml::Dom::XmlDocument & content, const Windows::Foundation::DateTime & deliveryTime) const
{
    Windows::UI::Notifications::ScheduledToastNotification notification { nullptr };
    check_hresult(WINRT_SHIM(IScheduledToastNotificationFactory)->abi_CreateScheduledToastNotification(get_abi(content), get_abi(deliveryTime), put_abi(notification)));
    return notification;
}

template <typename D> Windows::UI::Notifications::ScheduledToastNotification impl_IScheduledToastNotificationFactory<D>::CreateScheduledToastNotificationRecurring(const Windows::Data::Xml::Dom::XmlDocument & content, const Windows::Foundation::DateTime & deliveryTime, const Windows::Foundation::TimeSpan & snoozeInterval, uint32_t maximumSnoozeCount) const
{
    Windows::UI::Notifications::ScheduledToastNotification notification { nullptr };
    check_hresult(WINRT_SHIM(IScheduledToastNotificationFactory)->abi_CreateScheduledToastNotificationRecurring(get_abi(content), get_abi(deliveryTime), get_abi(snoozeInterval), maximumSnoozeCount, put_abi(notification)));
    return notification;
}

template <typename D> Windows::Data::Xml::Dom::XmlDocument impl_IScheduledToastNotification<D>::Content() const
{
    Windows::Data::Xml::Dom::XmlDocument value { nullptr };
    check_hresult(WINRT_SHIM(IScheduledToastNotification)->get_Content(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IScheduledToastNotification<D>::DeliveryTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IScheduledToastNotification)->get_DeliveryTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IScheduledToastNotification<D>::SnoozeInterval() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IScheduledToastNotification)->get_SnoozeInterval(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IScheduledToastNotification<D>::MaximumSnoozeCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IScheduledToastNotification)->get_MaximumSnoozeCount(&value));
    return value;
}

template <typename D> void impl_IScheduledToastNotification<D>::Id(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IScheduledToastNotification)->put_Id(get_abi(value)));
}

template <typename D> hstring impl_IScheduledToastNotification<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IScheduledToastNotification)->get_Id(put_abi(value)));
    return value;
}

template <typename D> void impl_IScheduledToastNotification2<D>::Tag(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IScheduledToastNotification2)->put_Tag(get_abi(value)));
}

template <typename D> hstring impl_IScheduledToastNotification2<D>::Tag() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IScheduledToastNotification2)->get_Tag(put_abi(value)));
    return value;
}

template <typename D> void impl_IScheduledToastNotification2<D>::Group(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IScheduledToastNotification2)->put_Group(get_abi(value)));
}

template <typename D> hstring impl_IScheduledToastNotification2<D>::Group() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IScheduledToastNotification2)->get_Group(put_abi(value)));
    return value;
}

template <typename D> void impl_IScheduledToastNotification2<D>::SuppressPopup(bool value) const
{
    check_hresult(WINRT_SHIM(IScheduledToastNotification2)->put_SuppressPopup(value));
}

template <typename D> bool impl_IScheduledToastNotification2<D>::SuppressPopup() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IScheduledToastNotification2)->get_SuppressPopup(&value));
    return value;
}

template <typename D> Windows::UI::Notifications::NotificationMirroring impl_IScheduledToastNotification3<D>::NotificationMirroring() const
{
    Windows::UI::Notifications::NotificationMirroring value {};
    check_hresult(WINRT_SHIM(IScheduledToastNotification3)->get_NotificationMirroring(&value));
    return value;
}

template <typename D> void impl_IScheduledToastNotification3<D>::NotificationMirroring(Windows::UI::Notifications::NotificationMirroring value) const
{
    check_hresult(WINRT_SHIM(IScheduledToastNotification3)->put_NotificationMirroring(value));
}

template <typename D> hstring impl_IScheduledToastNotification3<D>::RemoteId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IScheduledToastNotification3)->get_RemoteId(put_abi(value)));
    return value;
}

template <typename D> void impl_IScheduledToastNotification3<D>::RemoteId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IScheduledToastNotification3)->put_RemoteId(get_abi(value)));
}

template <typename D> Windows::UI::Notifications::ScheduledTileNotification impl_IScheduledTileNotificationFactory<D>::CreateScheduledTileNotification(const Windows::Data::Xml::Dom::XmlDocument & content, const Windows::Foundation::DateTime & deliveryTime) const
{
    Windows::UI::Notifications::ScheduledTileNotification notification { nullptr };
    check_hresult(WINRT_SHIM(IScheduledTileNotificationFactory)->abi_CreateScheduledTileNotification(get_abi(content), get_abi(deliveryTime), put_abi(notification)));
    return notification;
}

template <typename D> Windows::Data::Xml::Dom::XmlDocument impl_IScheduledTileNotification<D>::Content() const
{
    Windows::Data::Xml::Dom::XmlDocument value { nullptr };
    check_hresult(WINRT_SHIM(IScheduledTileNotification)->get_Content(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IScheduledTileNotification<D>::DeliveryTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IScheduledTileNotification)->get_DeliveryTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IScheduledTileNotification<D>::ExpirationTime(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IScheduledTileNotification)->put_ExpirationTime(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IScheduledTileNotification<D>::ExpirationTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IScheduledTileNotification)->get_ExpirationTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IScheduledTileNotification<D>::Tag(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IScheduledTileNotification)->put_Tag(get_abi(value)));
}

template <typename D> hstring impl_IScheduledTileNotification<D>::Tag() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IScheduledTileNotification)->get_Tag(put_abi(value)));
    return value;
}

template <typename D> void impl_IScheduledTileNotification<D>::Id(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IScheduledTileNotification)->put_Id(get_abi(value)));
}

template <typename D> hstring impl_IScheduledTileNotification<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IScheduledTileNotification)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Notifications::ToastNotificationHistory impl_IToastNotificationManagerStatics2<D>::History() const
{
    Windows::UI::Notifications::ToastNotificationHistory value { nullptr };
    check_hresult(WINRT_SHIM(IToastNotificationManagerStatics2)->get_History(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Notifications::ToastNotificationManagerForUser impl_IToastNotificationManagerStatics4<D>::GetForUser(const Windows::System::User & user) const
{
    Windows::UI::Notifications::ToastNotificationManagerForUser result { nullptr };
    check_hresult(WINRT_SHIM(IToastNotificationManagerStatics4)->abi_GetForUser(get_abi(user), put_abi(result)));
    return result;
}

template <typename D> void impl_IToastNotificationManagerStatics4<D>::ConfigureNotificationMirroring(Windows::UI::Notifications::NotificationMirroring value) const
{
    check_hresult(WINRT_SHIM(IToastNotificationManagerStatics4)->abi_ConfigureNotificationMirroring(value));
}

template <typename D> Windows::UI::Notifications::ToastNotifier impl_IToastNotificationManagerForUser<D>::CreateToastNotifier() const
{
    Windows::UI::Notifications::ToastNotifier result { nullptr };
    check_hresult(WINRT_SHIM(IToastNotificationManagerForUser)->abi_CreateToastNotifier(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Notifications::ToastNotifier impl_IToastNotificationManagerForUser<D>::CreateToastNotifier(hstring_view applicationId) const
{
    Windows::UI::Notifications::ToastNotifier result { nullptr };
    check_hresult(WINRT_SHIM(IToastNotificationManagerForUser)->abi_CreateToastNotifierWithId(get_abi(applicationId), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Notifications::ToastNotificationHistory impl_IToastNotificationManagerForUser<D>::History() const
{
    Windows::UI::Notifications::ToastNotificationHistory value { nullptr };
    check_hresult(WINRT_SHIM(IToastNotificationManagerForUser)->get_History(put_abi(value)));
    return value;
}

template <typename D> Windows::System::User impl_IToastNotificationManagerForUser<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IToastNotificationManagerForUser)->get_User(put_abi(value)));
    return value;
}

template <typename D> void impl_IToastNotificationHistory<D>::RemoveGroup(hstring_view group) const
{
    check_hresult(WINRT_SHIM(IToastNotificationHistory)->abi_RemoveGroup(get_abi(group)));
}

template <typename D> void impl_IToastNotificationHistory<D>::RemoveGroup(hstring_view group, hstring_view applicationId) const
{
    check_hresult(WINRT_SHIM(IToastNotificationHistory)->abi_RemoveGroupWithId(get_abi(group), get_abi(applicationId)));
}

template <typename D> void impl_IToastNotificationHistory<D>::Remove(hstring_view tag, hstring_view group, hstring_view applicationId) const
{
    check_hresult(WINRT_SHIM(IToastNotificationHistory)->abi_RemoveGroupedTagWithId(get_abi(tag), get_abi(group), get_abi(applicationId)));
}

template <typename D> void impl_IToastNotificationHistory<D>::Remove(hstring_view tag, hstring_view group) const
{
    check_hresult(WINRT_SHIM(IToastNotificationHistory)->abi_RemoveGroupedTag(get_abi(tag), get_abi(group)));
}

template <typename D> void impl_IToastNotificationHistory<D>::Remove(hstring_view tag) const
{
    check_hresult(WINRT_SHIM(IToastNotificationHistory)->abi_Remove(get_abi(tag)));
}

template <typename D> void impl_IToastNotificationHistory<D>::Clear() const
{
    check_hresult(WINRT_SHIM(IToastNotificationHistory)->abi_Clear());
}

template <typename D> void impl_IToastNotificationHistory<D>::Clear(hstring_view applicationId) const
{
    check_hresult(WINRT_SHIM(IToastNotificationHistory)->abi_ClearWithId(get_abi(applicationId)));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ToastNotification> impl_IToastNotificationHistory2<D>::GetHistory() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ToastNotification> toasts;
    check_hresult(WINRT_SHIM(IToastNotificationHistory2)->abi_GetHistory(put_abi(toasts)));
    return toasts;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ToastNotification> impl_IToastNotificationHistory2<D>::GetHistory(hstring_view applicationId) const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ToastNotification> toasts;
    check_hresult(WINRT_SHIM(IToastNotificationHistory2)->abi_GetHistoryWithId(get_abi(applicationId), put_abi(toasts)));
    return toasts;
}

template <typename D> Windows::UI::Notifications::ToastHistoryChangedType impl_IToastNotificationHistoryChangedTriggerDetail<D>::ChangeType() const
{
    Windows::UI::Notifications::ToastHistoryChangedType value {};
    check_hresult(WINRT_SHIM(IToastNotificationHistoryChangedTriggerDetail)->get_ChangeType(&value));
    return value;
}

template <typename D> hstring impl_IToastNotificationActionTriggerDetail<D>::Argument() const
{
    hstring argument;
    check_hresult(WINRT_SHIM(IToastNotificationActionTriggerDetail)->get_Argument(put_abi(argument)));
    return argument;
}

template <typename D> Windows::Foundation::Collections::ValueSet impl_IToastNotificationActionTriggerDetail<D>::UserInput() const
{
    Windows::Foundation::Collections::ValueSet inputs { nullptr };
    check_hresult(WINRT_SHIM(IToastNotificationActionTriggerDetail)->get_UserInput(put_abi(inputs)));
    return inputs;
}

inline AdaptiveNotificationText::AdaptiveNotificationText() :
    AdaptiveNotificationText(activate_instance<AdaptiveNotificationText>())
{}

inline BadgeNotification::BadgeNotification(const Windows::Data::Xml::Dom::XmlDocument & content) :
    BadgeNotification(get_activation_factory<BadgeNotification, IBadgeNotificationFactory>().CreateBadgeNotification(content))
{}

inline Windows::UI::Notifications::BadgeUpdater BadgeUpdateManager::CreateBadgeUpdaterForApplication()
{
    return get_activation_factory<BadgeUpdateManager, IBadgeUpdateManagerStatics>().CreateBadgeUpdaterForApplication();
}

inline Windows::UI::Notifications::BadgeUpdater BadgeUpdateManager::CreateBadgeUpdaterForApplication(hstring_view applicationId)
{
    return get_activation_factory<BadgeUpdateManager, IBadgeUpdateManagerStatics>().CreateBadgeUpdaterForApplication(applicationId);
}

inline Windows::UI::Notifications::BadgeUpdater BadgeUpdateManager::CreateBadgeUpdaterForSecondaryTile(hstring_view tileId)
{
    return get_activation_factory<BadgeUpdateManager, IBadgeUpdateManagerStatics>().CreateBadgeUpdaterForSecondaryTile(tileId);
}

inline Windows::Data::Xml::Dom::XmlDocument BadgeUpdateManager::GetTemplateContent(Windows::UI::Notifications::BadgeTemplateType type)
{
    return get_activation_factory<BadgeUpdateManager, IBadgeUpdateManagerStatics>().GetTemplateContent(type);
}

inline Windows::UI::Notifications::BadgeUpdateManagerForUser BadgeUpdateManager::GetForUser(const Windows::System::User & user)
{
    return get_activation_factory<BadgeUpdateManager, IBadgeUpdateManagerStatics2>().GetForUser(user);
}

inline hstring KnownAdaptiveNotificationHints::Style()
{
    return get_activation_factory<KnownAdaptiveNotificationHints, IKnownAdaptiveNotificationHintsStatics>().Style();
}

inline hstring KnownAdaptiveNotificationHints::Wrap()
{
    return get_activation_factory<KnownAdaptiveNotificationHints, IKnownAdaptiveNotificationHintsStatics>().Wrap();
}

inline hstring KnownAdaptiveNotificationHints::MaxLines()
{
    return get_activation_factory<KnownAdaptiveNotificationHints, IKnownAdaptiveNotificationHintsStatics>().MaxLines();
}

inline hstring KnownAdaptiveNotificationHints::MinLines()
{
    return get_activation_factory<KnownAdaptiveNotificationHints, IKnownAdaptiveNotificationHintsStatics>().MinLines();
}

inline hstring KnownAdaptiveNotificationHints::TextStacking()
{
    return get_activation_factory<KnownAdaptiveNotificationHints, IKnownAdaptiveNotificationHintsStatics>().TextStacking();
}

inline hstring KnownAdaptiveNotificationHints::Align()
{
    return get_activation_factory<KnownAdaptiveNotificationHints, IKnownAdaptiveNotificationHintsStatics>().Align();
}

inline hstring KnownAdaptiveNotificationTextStyles::Caption()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().Caption();
}

inline hstring KnownAdaptiveNotificationTextStyles::Body()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().Body();
}

inline hstring KnownAdaptiveNotificationTextStyles::Base()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().Base();
}

inline hstring KnownAdaptiveNotificationTextStyles::Subtitle()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().Subtitle();
}

inline hstring KnownAdaptiveNotificationTextStyles::Title()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().Title();
}

inline hstring KnownAdaptiveNotificationTextStyles::Subheader()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().Subheader();
}

inline hstring KnownAdaptiveNotificationTextStyles::Header()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().Header();
}

inline hstring KnownAdaptiveNotificationTextStyles::TitleNumeral()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().TitleNumeral();
}

inline hstring KnownAdaptiveNotificationTextStyles::SubheaderNumeral()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().SubheaderNumeral();
}

inline hstring KnownAdaptiveNotificationTextStyles::HeaderNumeral()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().HeaderNumeral();
}

inline hstring KnownAdaptiveNotificationTextStyles::CaptionSubtle()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().CaptionSubtle();
}

inline hstring KnownAdaptiveNotificationTextStyles::BodySubtle()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().BodySubtle();
}

inline hstring KnownAdaptiveNotificationTextStyles::BaseSubtle()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().BaseSubtle();
}

inline hstring KnownAdaptiveNotificationTextStyles::SubtitleSubtle()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().SubtitleSubtle();
}

inline hstring KnownAdaptiveNotificationTextStyles::TitleSubtle()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().TitleSubtle();
}

inline hstring KnownAdaptiveNotificationTextStyles::SubheaderSubtle()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().SubheaderSubtle();
}

inline hstring KnownAdaptiveNotificationTextStyles::SubheaderNumeralSubtle()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().SubheaderNumeralSubtle();
}

inline hstring KnownAdaptiveNotificationTextStyles::HeaderSubtle()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().HeaderSubtle();
}

inline hstring KnownAdaptiveNotificationTextStyles::HeaderNumeralSubtle()
{
    return get_activation_factory<KnownAdaptiveNotificationTextStyles, IKnownAdaptiveNotificationTextStylesStatics>().HeaderNumeralSubtle();
}

inline hstring KnownNotificationBindings::ToastGeneric()
{
    return get_activation_factory<KnownNotificationBindings, IKnownNotificationBindingsStatics>().ToastGeneric();
}

inline Notification::Notification() :
    Notification(activate_instance<Notification>())
{}

inline ScheduledTileNotification::ScheduledTileNotification(const Windows::Data::Xml::Dom::XmlDocument & content, const Windows::Foundation::DateTime & deliveryTime) :
    ScheduledTileNotification(get_activation_factory<ScheduledTileNotification, IScheduledTileNotificationFactory>().CreateScheduledTileNotification(content, deliveryTime))
{}

inline ScheduledToastNotification::ScheduledToastNotification(const Windows::Data::Xml::Dom::XmlDocument & content, const Windows::Foundation::DateTime & deliveryTime) :
    ScheduledToastNotification(get_activation_factory<ScheduledToastNotification, IScheduledToastNotificationFactory>().CreateScheduledToastNotification(content, deliveryTime))
{}

inline ScheduledToastNotification::ScheduledToastNotification(const Windows::Data::Xml::Dom::XmlDocument & content, const Windows::Foundation::DateTime & deliveryTime, const Windows::Foundation::TimeSpan & snoozeInterval, uint32_t maximumSnoozeCount) :
    ScheduledToastNotification(get_activation_factory<ScheduledToastNotification, IScheduledToastNotificationFactory>().CreateScheduledToastNotificationRecurring(content, deliveryTime, snoozeInterval, maximumSnoozeCount))
{}

inline TileFlyoutNotification::TileFlyoutNotification(const Windows::Data::Xml::Dom::XmlDocument & content) :
    TileFlyoutNotification(get_activation_factory<TileFlyoutNotification, ITileFlyoutNotificationFactory>().CreateTileFlyoutNotification(content))
{}

inline Windows::UI::Notifications::TileFlyoutUpdater TileFlyoutUpdateManager::CreateTileFlyoutUpdaterForApplication()
{
    return get_activation_factory<TileFlyoutUpdateManager, ITileFlyoutUpdateManagerStatics>().CreateTileFlyoutUpdaterForApplication();
}

inline Windows::UI::Notifications::TileFlyoutUpdater TileFlyoutUpdateManager::CreateTileFlyoutUpdaterForApplication(hstring_view applicationId)
{
    return get_activation_factory<TileFlyoutUpdateManager, ITileFlyoutUpdateManagerStatics>().CreateTileFlyoutUpdaterForApplication(applicationId);
}

inline Windows::UI::Notifications::TileFlyoutUpdater TileFlyoutUpdateManager::CreateTileFlyoutUpdaterForSecondaryTile(hstring_view tileId)
{
    return get_activation_factory<TileFlyoutUpdateManager, ITileFlyoutUpdateManagerStatics>().CreateTileFlyoutUpdaterForSecondaryTile(tileId);
}

inline Windows::Data::Xml::Dom::XmlDocument TileFlyoutUpdateManager::GetTemplateContent(Windows::UI::Notifications::TileFlyoutTemplateType type)
{
    return get_activation_factory<TileFlyoutUpdateManager, ITileFlyoutUpdateManagerStatics>().GetTemplateContent(type);
}

inline TileNotification::TileNotification(const Windows::Data::Xml::Dom::XmlDocument & content) :
    TileNotification(get_activation_factory<TileNotification, ITileNotificationFactory>().CreateTileNotification(content))
{}

inline Windows::UI::Notifications::TileUpdater TileUpdateManager::CreateTileUpdaterForApplication()
{
    return get_activation_factory<TileUpdateManager, ITileUpdateManagerStatics>().CreateTileUpdaterForApplication();
}

inline Windows::UI::Notifications::TileUpdater TileUpdateManager::CreateTileUpdaterForApplication(hstring_view applicationId)
{
    return get_activation_factory<TileUpdateManager, ITileUpdateManagerStatics>().CreateTileUpdaterForApplication(applicationId);
}

inline Windows::UI::Notifications::TileUpdater TileUpdateManager::CreateTileUpdaterForSecondaryTile(hstring_view tileId)
{
    return get_activation_factory<TileUpdateManager, ITileUpdateManagerStatics>().CreateTileUpdaterForSecondaryTile(tileId);
}

inline Windows::Data::Xml::Dom::XmlDocument TileUpdateManager::GetTemplateContent(Windows::UI::Notifications::TileTemplateType type)
{
    return get_activation_factory<TileUpdateManager, ITileUpdateManagerStatics>().GetTemplateContent(type);
}

inline Windows::UI::Notifications::TileUpdateManagerForUser TileUpdateManager::GetForUser(const Windows::System::User & user)
{
    return get_activation_factory<TileUpdateManager, ITileUpdateManagerStatics2>().GetForUser(user);
}

inline ToastNotification::ToastNotification(const Windows::Data::Xml::Dom::XmlDocument & content) :
    ToastNotification(get_activation_factory<ToastNotification, IToastNotificationFactory>().CreateToastNotification(content))
{}

inline Windows::UI::Notifications::ToastNotifier ToastNotificationManager::CreateToastNotifier()
{
    return get_activation_factory<ToastNotificationManager, IToastNotificationManagerStatics>().CreateToastNotifier();
}

inline Windows::UI::Notifications::ToastNotifier ToastNotificationManager::CreateToastNotifier(hstring_view applicationId)
{
    return get_activation_factory<ToastNotificationManager, IToastNotificationManagerStatics>().CreateToastNotifier(applicationId);
}

inline Windows::Data::Xml::Dom::XmlDocument ToastNotificationManager::GetTemplateContent(Windows::UI::Notifications::ToastTemplateType type)
{
    return get_activation_factory<ToastNotificationManager, IToastNotificationManagerStatics>().GetTemplateContent(type);
}

inline Windows::UI::Notifications::ToastNotificationHistory ToastNotificationManager::History()
{
    return get_activation_factory<ToastNotificationManager, IToastNotificationManagerStatics2>().History();
}

inline Windows::UI::Notifications::ToastNotificationManagerForUser ToastNotificationManager::GetForUser(const Windows::System::User & user)
{
    return get_activation_factory<ToastNotificationManager, IToastNotificationManagerStatics4>().GetForUser(user);
}

inline void ToastNotificationManager::ConfigureNotificationMirroring(Windows::UI::Notifications::NotificationMirroring value)
{
    get_activation_factory<ToastNotificationManager, IToastNotificationManagerStatics4>().ConfigureNotificationMirroring(value);
}

}

}
#pragma warning(pop)
