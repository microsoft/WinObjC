// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::ApplicationSettings {

struct CredentialCommandCredentialDeletedHandler;
struct IAccountsSettingsPane;
struct IAccountsSettingsPaneCommandsRequestedEventArgs;
struct IAccountsSettingsPaneEventDeferral;
struct IAccountsSettingsPaneStatics;
struct IAccountsSettingsPaneStatics2;
struct ICredentialCommand;
struct ICredentialCommandFactory;
struct ISettingsCommandFactory;
struct ISettingsCommandStatics;
struct ISettingsPane;
struct ISettingsPaneCommandsRequest;
struct ISettingsPaneCommandsRequestedEventArgs;
struct ISettingsPaneStatics;
struct IWebAccountCommand;
struct IWebAccountCommandFactory;
struct IWebAccountInvokedArgs;
struct IWebAccountProviderCommand;
struct IWebAccountProviderCommandFactory;
struct WebAccountCommandInvokedHandler;
struct WebAccountProviderCommandInvokedHandler;
struct AccountsSettingsPane;
struct AccountsSettingsPaneCommandsRequestedEventArgs;
struct AccountsSettingsPaneEventDeferral;
struct CredentialCommand;
struct SettingsCommand;
struct SettingsPane;
struct SettingsPaneCommandsRequest;
struct SettingsPaneCommandsRequestedEventArgs;
struct WebAccountCommand;
struct WebAccountInvokedArgs;
struct WebAccountProviderCommand;

}

namespace Windows::UI::ApplicationSettings {

struct CredentialCommandCredentialDeletedHandler;
struct WebAccountCommandInvokedHandler;
struct WebAccountProviderCommandInvokedHandler;
struct IAccountsSettingsPane;
struct IAccountsSettingsPaneCommandsRequestedEventArgs;
struct IAccountsSettingsPaneEventDeferral;
struct IAccountsSettingsPaneStatics;
struct IAccountsSettingsPaneStatics2;
struct ICredentialCommand;
struct ICredentialCommandFactory;
struct ISettingsCommandFactory;
struct ISettingsCommandStatics;
struct ISettingsPane;
struct ISettingsPaneCommandsRequest;
struct ISettingsPaneCommandsRequestedEventArgs;
struct ISettingsPaneStatics;
struct IWebAccountCommand;
struct IWebAccountCommandFactory;
struct IWebAccountInvokedArgs;
struct IWebAccountProviderCommand;
struct IWebAccountProviderCommandFactory;
struct AccountsSettingsPane;
struct AccountsSettingsPaneCommandsRequestedEventArgs;
struct AccountsSettingsPaneEventDeferral;
struct CredentialCommand;
struct SettingsCommand;
struct SettingsPane;
struct SettingsPaneCommandsRequest;
struct SettingsPaneCommandsRequestedEventArgs;
struct WebAccountCommand;
struct WebAccountInvokedArgs;
struct WebAccountProviderCommand;

}

namespace Windows::UI::ApplicationSettings {

template <typename T> struct impl_IAccountsSettingsPane;
template <typename T> struct impl_IAccountsSettingsPaneCommandsRequestedEventArgs;
template <typename T> struct impl_IAccountsSettingsPaneEventDeferral;
template <typename T> struct impl_IAccountsSettingsPaneStatics;
template <typename T> struct impl_IAccountsSettingsPaneStatics2;
template <typename T> struct impl_ICredentialCommand;
template <typename T> struct impl_ICredentialCommandFactory;
template <typename T> struct impl_ISettingsCommandFactory;
template <typename T> struct impl_ISettingsCommandStatics;
template <typename T> struct impl_ISettingsPane;
template <typename T> struct impl_ISettingsPaneCommandsRequest;
template <typename T> struct impl_ISettingsPaneCommandsRequestedEventArgs;
template <typename T> struct impl_ISettingsPaneStatics;
template <typename T> struct impl_IWebAccountCommand;
template <typename T> struct impl_IWebAccountCommandFactory;
template <typename T> struct impl_IWebAccountInvokedArgs;
template <typename T> struct impl_IWebAccountProviderCommand;
template <typename T> struct impl_IWebAccountProviderCommandFactory;
template <typename T> struct impl_CredentialCommandCredentialDeletedHandler;
template <typename T> struct impl_WebAccountCommandInvokedHandler;
template <typename T> struct impl_WebAccountProviderCommandInvokedHandler;

}

namespace Windows::UI::ApplicationSettings {

enum class [[deprecated("SettingsEdgeLocation is deprecated and might not work on all platforms. For more info, see MSDN.")]] SettingsEdgeLocation
{
    Right = 0,
    Left = 1,
};

enum class SupportedWebAccountActions : unsigned
{
    None = 0x0,
    Reconnect = 0x1,
    Remove = 0x2,
    ViewDetails = 0x4,
    Manage = 0x8,
    More = 0x10,
};

DEFINE_ENUM_FLAG_OPERATORS(SupportedWebAccountActions)

enum class WebAccountAction
{
    Reconnect = 0,
    Remove = 1,
    ViewDetails = 2,
    Manage = 3,
    More = 4,
};

}

}
