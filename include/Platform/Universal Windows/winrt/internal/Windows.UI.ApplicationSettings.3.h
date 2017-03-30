// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.ApplicationSettings.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::ApplicationSettings {

template <typename H> struct impl_CredentialCommandCredentialDeletedHandler : implements<impl_CredentialCommandCredentialDeletedHandler<H>, abi<CredentialCommandCredentialDeletedHandler>>, H
{
    impl_CredentialCommandCredentialDeletedHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::UI::ApplicationSettings::ICredentialCommand> command) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::UI::ApplicationSettings::CredentialCommand *>(&command));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_WebAccountCommandInvokedHandler : implements<impl_WebAccountCommandInvokedHandler<H>, abi<WebAccountCommandInvokedHandler>>, H
{
    impl_WebAccountCommandInvokedHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::UI::ApplicationSettings::IWebAccountCommand> command, impl::abi_arg_in<Windows::UI::ApplicationSettings::IWebAccountInvokedArgs> args) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::UI::ApplicationSettings::WebAccountCommand *>(&command), *reinterpret_cast<const Windows::UI::ApplicationSettings::WebAccountInvokedArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_WebAccountProviderCommandInvokedHandler : implements<impl_WebAccountProviderCommandInvokedHandler<H>, abi<WebAccountProviderCommandInvokedHandler>>, H
{
    impl_WebAccountProviderCommandInvokedHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::UI::ApplicationSettings::IWebAccountProviderCommand> command) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::UI::ApplicationSettings::WebAccountProviderCommand *>(&command));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::ApplicationSettings {

struct WINRT_EBO AccountsSettingsPane :
    Windows::UI::ApplicationSettings::IAccountsSettingsPane
{
    AccountsSettingsPane(std::nullptr_t) noexcept {}
    static Windows::UI::ApplicationSettings::AccountsSettingsPane GetForCurrentView();
    static void Show();
    static Windows::Foundation::IAsyncAction ShowManageAccountsAsync();
    static Windows::Foundation::IAsyncAction ShowAddAccountAsync();
};

struct WINRT_EBO AccountsSettingsPaneCommandsRequestedEventArgs :
    Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs
{
    AccountsSettingsPaneCommandsRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AccountsSettingsPaneEventDeferral :
    Windows::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral
{
    AccountsSettingsPaneEventDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CredentialCommand :
    Windows::UI::ApplicationSettings::ICredentialCommand
{
    CredentialCommand(std::nullptr_t) noexcept {}
    CredentialCommand(const Windows::Security::Credentials::PasswordCredential & passwordCredential);
    CredentialCommand(const Windows::Security::Credentials::PasswordCredential & passwordCredential, const Windows::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler & deleted);
};

struct WINRT_EBO SettingsCommand :
    Windows::UI::Popups::IUICommand
{
    SettingsCommand(std::nullptr_t) noexcept {}
    SettingsCommand(const Windows::Foundation::IInspectable & settingsCommandId, hstring_view label, const Windows::UI::Popups::UICommandInvokedHandler & handler);
    static Windows::UI::ApplicationSettings::SettingsCommand AccountsCommand();
};

struct [[deprecated("SettingsPane is deprecated and might not work on all platforms. For more info, see MSDN.")]] WINRT_EBO SettingsPane :
    Windows::UI::ApplicationSettings::ISettingsPane
{
    SettingsPane(std::nullptr_t) noexcept {}
    [[deprecated("SettingsPane is deprecated and might not work on all platforms. For more info, see MSDN.")]] static Windows::UI::ApplicationSettings::SettingsPane GetForCurrentView();
    [[deprecated("SettingsPane is deprecated and might not work on all platforms. For more info, see MSDN.")]] static void Show();
    [[deprecated("SettingsPane is deprecated and might not work on all platforms. For more info, see MSDN.")]] static Windows::UI::ApplicationSettings::SettingsEdgeLocation Edge();
};

struct [[deprecated("SettingsPaneCommandsRequest is deprecated and might not work on all platforms. For more info, see MSDN.")]] WINRT_EBO SettingsPaneCommandsRequest :
    Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequest
{
    SettingsPaneCommandsRequest(std::nullptr_t) noexcept {}
};

struct [[deprecated("SettingsPaneCommandsRequestedEventArgs is deprecated and might not work on all platforms. For more info, see MSDN.")]] WINRT_EBO SettingsPaneCommandsRequestedEventArgs :
    Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequestedEventArgs
{
    SettingsPaneCommandsRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebAccountCommand :
    Windows::UI::ApplicationSettings::IWebAccountCommand
{
    WebAccountCommand(std::nullptr_t) noexcept {}
    WebAccountCommand(const Windows::Security::Credentials::WebAccount & webAccount, const Windows::UI::ApplicationSettings::WebAccountCommandInvokedHandler & invoked, Windows::UI::ApplicationSettings::SupportedWebAccountActions actions);
};

struct WINRT_EBO WebAccountInvokedArgs :
    Windows::UI::ApplicationSettings::IWebAccountInvokedArgs
{
    WebAccountInvokedArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebAccountProviderCommand :
    Windows::UI::ApplicationSettings::IWebAccountProviderCommand
{
    WebAccountProviderCommand(std::nullptr_t) noexcept {}
    WebAccountProviderCommand(const Windows::Security::Credentials::WebAccountProvider & webAccountProvider, const Windows::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler & invoked);
};

}

}
