// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Popups.3.h"
#include "internal/Windows.Security.Credentials.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.ApplicationSettings.3.h"
#include "Windows.UI.h"
#include "Windows.UI.Popups.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::ApplicationSettings {

template <typename L> CredentialCommandCredentialDeletedHandler::CredentialCommandCredentialDeletedHandler(L lambda) :
    CredentialCommandCredentialDeletedHandler(impl::make_delegate<impl_CredentialCommandCredentialDeletedHandler<L>, CredentialCommandCredentialDeletedHandler>(std::forward<L>(lambda)))
{}

template <typename F> CredentialCommandCredentialDeletedHandler::CredentialCommandCredentialDeletedHandler(F * function) :
    CredentialCommandCredentialDeletedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> CredentialCommandCredentialDeletedHandler::CredentialCommandCredentialDeletedHandler(O * object, M method) :
    CredentialCommandCredentialDeletedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void CredentialCommandCredentialDeletedHandler::operator()(const Windows::UI::ApplicationSettings::CredentialCommand & command) const
{
    check_hresult((*(abi<CredentialCommandCredentialDeletedHandler> **)this)->abi_Invoke(get_abi(command)));
}

template <typename L> WebAccountCommandInvokedHandler::WebAccountCommandInvokedHandler(L lambda) :
    WebAccountCommandInvokedHandler(impl::make_delegate<impl_WebAccountCommandInvokedHandler<L>, WebAccountCommandInvokedHandler>(std::forward<L>(lambda)))
{}

template <typename F> WebAccountCommandInvokedHandler::WebAccountCommandInvokedHandler(F * function) :
    WebAccountCommandInvokedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> WebAccountCommandInvokedHandler::WebAccountCommandInvokedHandler(O * object, M method) :
    WebAccountCommandInvokedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void WebAccountCommandInvokedHandler::operator()(const Windows::UI::ApplicationSettings::WebAccountCommand & command, const Windows::UI::ApplicationSettings::WebAccountInvokedArgs & args) const
{
    check_hresult((*(abi<WebAccountCommandInvokedHandler> **)this)->abi_Invoke(get_abi(command), get_abi(args)));
}

template <typename L> WebAccountProviderCommandInvokedHandler::WebAccountProviderCommandInvokedHandler(L lambda) :
    WebAccountProviderCommandInvokedHandler(impl::make_delegate<impl_WebAccountProviderCommandInvokedHandler<L>, WebAccountProviderCommandInvokedHandler>(std::forward<L>(lambda)))
{}

template <typename F> WebAccountProviderCommandInvokedHandler::WebAccountProviderCommandInvokedHandler(F * function) :
    WebAccountProviderCommandInvokedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> WebAccountProviderCommandInvokedHandler::WebAccountProviderCommandInvokedHandler(O * object, M method) :
    WebAccountProviderCommandInvokedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void WebAccountProviderCommandInvokedHandler::operator()(const Windows::UI::ApplicationSettings::WebAccountProviderCommand & command) const
{
    check_hresult((*(abi<WebAccountProviderCommandInvokedHandler> **)this)->abi_Invoke(get_abi(command)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::IAccountsSettingsPane> : produce_base<D, Windows::UI::ApplicationSettings::IAccountsSettingsPane>
{
    HRESULT __stdcall add_AccountCommandsRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::ApplicationSettings::AccountsSettingsPane, Windows::UI::ApplicationSettings::AccountsSettingsPaneCommandsRequestedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().AccountCommandsRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::ApplicationSettings::AccountsSettingsPane, Windows::UI::ApplicationSettings::AccountsSettingsPaneCommandsRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AccountCommandsRequested(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccountCommandsRequested(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs> : produce_base<D, Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs>
{
    HRESULT __stdcall get_WebAccountProviderCommands(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::WebAccountProviderCommand>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WebAccountProviderCommands());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WebAccountCommands(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::WebAccountCommand>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WebAccountCommands());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CredentialCommands(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::CredentialCommand>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CredentialCommands());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Commands(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::SettingsCommand>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Commands());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeaderText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HeaderText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HeaderText(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HeaderText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral> deferral) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deferral = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *deferral = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral> : produce_base<D, Windows::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::IAccountsSettingsPaneStatics> : produce_base<D, Windows::UI::ApplicationSettings::IAccountsSettingsPaneStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::UI::ApplicationSettings::IAccountsSettingsPane> current) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *current = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *current = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Show() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::IAccountsSettingsPaneStatics2> : produce_base<D, Windows::UI::ApplicationSettings::IAccountsSettingsPaneStatics2>
{
    HRESULT __stdcall abi_ShowManageAccountsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().ShowManageAccountsAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAddAccountAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().ShowAddAccountAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::ICredentialCommand> : produce_base<D, Windows::UI::ApplicationSettings::ICredentialCommand>
{
    HRESULT __stdcall get_PasswordCredential(impl::abi_arg_out<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PasswordCredential());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CredentialDeleted(impl::abi_arg_out<Windows::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CredentialDeleted());
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
struct produce<D, Windows::UI::ApplicationSettings::ICredentialCommandFactory> : produce_base<D, Windows::UI::ApplicationSettings::ICredentialCommandFactory>
{
    HRESULT __stdcall abi_CreateCredentialCommand(impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> passwordCredential, impl::abi_arg_out<Windows::UI::ApplicationSettings::ICredentialCommand> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateCredentialCommand(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&passwordCredential)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCredentialCommandWithHandler(impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> passwordCredential, impl::abi_arg_in<Windows::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler> deleted, impl::abi_arg_out<Windows::UI::ApplicationSettings::ICredentialCommand> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateCredentialCommandWithHandler(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&passwordCredential), *reinterpret_cast<const Windows::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler *>(&deleted)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::ISettingsCommandFactory> : produce_base<D, Windows::UI::ApplicationSettings::ISettingsCommandFactory>
{
    HRESULT __stdcall abi_CreateSettingsCommand(impl::abi_arg_in<Windows::Foundation::IInspectable> settingsCommandId, impl::abi_arg_in<hstring> label, impl::abi_arg_in<Windows::UI::Popups::UICommandInvokedHandler> handler, impl::abi_arg_out<Windows::UI::Popups::IUICommand> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateSettingsCommand(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&settingsCommandId), *reinterpret_cast<const hstring *>(&label), *reinterpret_cast<const Windows::UI::Popups::UICommandInvokedHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::ISettingsCommandStatics> : produce_base<D, Windows::UI::ApplicationSettings::ISettingsCommandStatics>
{
    HRESULT __stdcall get_AccountsCommand(impl::abi_arg_out<Windows::UI::Popups::IUICommand> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccountsCommand());
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
struct produce<D, Windows::UI::ApplicationSettings::ISettingsPane> : produce_base<D, Windows::UI::ApplicationSettings::ISettingsPane>
{
    HRESULT __stdcall add_CommandsRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::ApplicationSettings::SettingsPane, Windows::UI::ApplicationSettings::SettingsPaneCommandsRequestedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().CommandsRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::ApplicationSettings::SettingsPane, Windows::UI::ApplicationSettings::SettingsPaneCommandsRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CommandsRequested(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CommandsRequested(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequest> : produce_base<D, Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequest>
{
    HRESULT __stdcall get_ApplicationCommands(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::SettingsCommand>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ApplicationCommands());
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
struct produce<D, Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequestedEventArgs> : produce_base<D, Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequestedEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequest> request) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *request = detach_abi(this->shim().Request());
            return S_OK;
        }
        catch (...)
        {
            *request = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::ISettingsPaneStatics> : produce_base<D, Windows::UI::ApplicationSettings::ISettingsPaneStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::UI::ApplicationSettings::ISettingsPane> current) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *current = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *current = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Show() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Edge(Windows::UI::ApplicationSettings::SettingsEdgeLocation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Edge());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::IWebAccountCommand> : produce_base<D, Windows::UI::ApplicationSettings::IWebAccountCommand>
{
    HRESULT __stdcall get_WebAccount(impl::abi_arg_out<Windows::Security::Credentials::IWebAccount> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WebAccount());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Invoked(impl::abi_arg_out<Windows::UI::ApplicationSettings::WebAccountCommandInvokedHandler> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Invoked());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Actions(Windows::UI::ApplicationSettings::SupportedWebAccountActions * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Actions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::IWebAccountCommandFactory> : produce_base<D, Windows::UI::ApplicationSettings::IWebAccountCommandFactory>
{
    HRESULT __stdcall abi_CreateWebAccountCommand(impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, impl::abi_arg_in<Windows::UI::ApplicationSettings::WebAccountCommandInvokedHandler> invoked, Windows::UI::ApplicationSettings::SupportedWebAccountActions actions, impl::abi_arg_out<Windows::UI::ApplicationSettings::IWebAccountCommand> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateWebAccountCommand(*reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount), *reinterpret_cast<const Windows::UI::ApplicationSettings::WebAccountCommandInvokedHandler *>(&invoked), actions));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::IWebAccountInvokedArgs> : produce_base<D, Windows::UI::ApplicationSettings::IWebAccountInvokedArgs>
{
    HRESULT __stdcall get_Action(Windows::UI::ApplicationSettings::WebAccountAction * action) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *action = detach_abi(this->shim().Action());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::IWebAccountProviderCommand> : produce_base<D, Windows::UI::ApplicationSettings::IWebAccountProviderCommand>
{
    HRESULT __stdcall get_WebAccountProvider(impl::abi_arg_out<Windows::Security::Credentials::IWebAccountProvider> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WebAccountProvider());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Invoked(impl::abi_arg_out<Windows::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Invoked());
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
struct produce<D, Windows::UI::ApplicationSettings::IWebAccountProviderCommandFactory> : produce_base<D, Windows::UI::ApplicationSettings::IWebAccountProviderCommandFactory>
{
    HRESULT __stdcall abi_CreateWebAccountProviderCommand(impl::abi_arg_in<Windows::Security::Credentials::IWebAccountProvider> webAccountProvider, impl::abi_arg_in<Windows::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler> invoked, impl::abi_arg_out<Windows::UI::ApplicationSettings::IWebAccountProviderCommand> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateWebAccountProviderCommand(*reinterpret_cast<const Windows::Security::Credentials::WebAccountProvider *>(&webAccountProvider), *reinterpret_cast<const Windows::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler *>(&invoked)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::ApplicationSettings {

template <typename D> Windows::UI::ApplicationSettings::SettingsCommand impl_ISettingsCommandFactory<D>::CreateSettingsCommand(const Windows::Foundation::IInspectable & settingsCommandId, hstring_view label, const Windows::UI::Popups::UICommandInvokedHandler & handler) const
{
    Windows::UI::ApplicationSettings::SettingsCommand instance { nullptr };
    check_hresult(WINRT_SHIM(ISettingsCommandFactory)->abi_CreateSettingsCommand(get_abi(settingsCommandId), get_abi(label), get_abi(handler), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::ApplicationSettings::SettingsCommand impl_ISettingsCommandStatics<D>::AccountsCommand() const
{
    Windows::UI::ApplicationSettings::SettingsCommand value { nullptr };
    check_hresult(WINRT_SHIM(ISettingsCommandStatics)->get_AccountsCommand(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::ApplicationSettings::WebAccountProviderCommand impl_IWebAccountProviderCommandFactory<D>::CreateWebAccountProviderCommand(const Windows::Security::Credentials::WebAccountProvider & webAccountProvider, const Windows::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler & invoked) const
{
    Windows::UI::ApplicationSettings::WebAccountProviderCommand instance { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountProviderCommandFactory)->abi_CreateWebAccountProviderCommand(get_abi(webAccountProvider), get_abi(invoked), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Security::Credentials::WebAccountProvider impl_IWebAccountProviderCommand<D>::WebAccountProvider() const
{
    Windows::Security::Credentials::WebAccountProvider value { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountProviderCommand)->get_WebAccountProvider(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler impl_IWebAccountProviderCommand<D>::Invoked() const
{
    Windows::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler value {};
    check_hresult(WINRT_SHIM(IWebAccountProviderCommand)->get_Invoked(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::ApplicationSettings::WebAccountAction impl_IWebAccountInvokedArgs<D>::Action() const
{
    Windows::UI::ApplicationSettings::WebAccountAction action {};
    check_hresult(WINRT_SHIM(IWebAccountInvokedArgs)->get_Action(&action));
    return action;
}

template <typename D> Windows::UI::ApplicationSettings::WebAccountCommand impl_IWebAccountCommandFactory<D>::CreateWebAccountCommand(const Windows::Security::Credentials::WebAccount & webAccount, const Windows::UI::ApplicationSettings::WebAccountCommandInvokedHandler & invoked, Windows::UI::ApplicationSettings::SupportedWebAccountActions actions) const
{
    Windows::UI::ApplicationSettings::WebAccountCommand instance { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountCommandFactory)->abi_CreateWebAccountCommand(get_abi(webAccount), get_abi(invoked), actions, put_abi(instance)));
    return instance;
}

template <typename D> Windows::Security::Credentials::WebAccount impl_IWebAccountCommand<D>::WebAccount() const
{
    Windows::Security::Credentials::WebAccount value { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountCommand)->get_WebAccount(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::ApplicationSettings::WebAccountCommandInvokedHandler impl_IWebAccountCommand<D>::Invoked() const
{
    Windows::UI::ApplicationSettings::WebAccountCommandInvokedHandler value {};
    check_hresult(WINRT_SHIM(IWebAccountCommand)->get_Invoked(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::ApplicationSettings::SupportedWebAccountActions impl_IWebAccountCommand<D>::Actions() const
{
    Windows::UI::ApplicationSettings::SupportedWebAccountActions value {};
    check_hresult(WINRT_SHIM(IWebAccountCommand)->get_Actions(&value));
    return value;
}

template <typename D> Windows::UI::ApplicationSettings::CredentialCommand impl_ICredentialCommandFactory<D>::CreateCredentialCommand(const Windows::Security::Credentials::PasswordCredential & passwordCredential) const
{
    Windows::UI::ApplicationSettings::CredentialCommand instance { nullptr };
    check_hresult(WINRT_SHIM(ICredentialCommandFactory)->abi_CreateCredentialCommand(get_abi(passwordCredential), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::ApplicationSettings::CredentialCommand impl_ICredentialCommandFactory<D>::CreateCredentialCommandWithHandler(const Windows::Security::Credentials::PasswordCredential & passwordCredential, const Windows::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler & deleted) const
{
    Windows::UI::ApplicationSettings::CredentialCommand instance { nullptr };
    check_hresult(WINRT_SHIM(ICredentialCommandFactory)->abi_CreateCredentialCommandWithHandler(get_abi(passwordCredential), get_abi(deleted), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_ICredentialCommand<D>::PasswordCredential() const
{
    Windows::Security::Credentials::PasswordCredential value { nullptr };
    check_hresult(WINRT_SHIM(ICredentialCommand)->get_PasswordCredential(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler impl_ICredentialCommand<D>::CredentialDeleted() const
{
    Windows::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler value {};
    check_hresult(WINRT_SHIM(ICredentialCommand)->get_CredentialDeleted(put_abi(value)));
    return value;
}

template <typename D> void impl_IAccountsSettingsPaneEventDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IAccountsSettingsPaneEventDeferral)->abi_Complete());
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::WebAccountProviderCommand> impl_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::WebAccountProviderCommands() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::WebAccountProviderCommand> value;
    check_hresult(WINRT_SHIM(IAccountsSettingsPaneCommandsRequestedEventArgs)->get_WebAccountProviderCommands(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::WebAccountCommand> impl_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::WebAccountCommands() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::WebAccountCommand> value;
    check_hresult(WINRT_SHIM(IAccountsSettingsPaneCommandsRequestedEventArgs)->get_WebAccountCommands(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::CredentialCommand> impl_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::CredentialCommands() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::CredentialCommand> value;
    check_hresult(WINRT_SHIM(IAccountsSettingsPaneCommandsRequestedEventArgs)->get_CredentialCommands(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::SettingsCommand> impl_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::Commands() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::SettingsCommand> value;
    check_hresult(WINRT_SHIM(IAccountsSettingsPaneCommandsRequestedEventArgs)->get_Commands(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::HeaderText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAccountsSettingsPaneCommandsRequestedEventArgs)->get_HeaderText(put_abi(value)));
    return value;
}

template <typename D> void impl_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::HeaderText(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAccountsSettingsPaneCommandsRequestedEventArgs)->put_HeaderText(get_abi(value)));
}

template <typename D> Windows::UI::ApplicationSettings::AccountsSettingsPaneEventDeferral impl_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::GetDeferral() const
{
    Windows::UI::ApplicationSettings::AccountsSettingsPaneEventDeferral deferral { nullptr };
    check_hresult(WINRT_SHIM(IAccountsSettingsPaneCommandsRequestedEventArgs)->abi_GetDeferral(put_abi(deferral)));
    return deferral;
}

template <typename D> Windows::UI::ApplicationSettings::AccountsSettingsPane impl_IAccountsSettingsPaneStatics<D>::GetForCurrentView() const
{
    Windows::UI::ApplicationSettings::AccountsSettingsPane current { nullptr };
    check_hresult(WINRT_SHIM(IAccountsSettingsPaneStatics)->abi_GetForCurrentView(put_abi(current)));
    return current;
}

template <typename D> void impl_IAccountsSettingsPaneStatics<D>::Show() const
{
    check_hresult(WINRT_SHIM(IAccountsSettingsPaneStatics)->abi_Show());
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAccountsSettingsPaneStatics2<D>::ShowManageAccountsAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IAccountsSettingsPaneStatics2)->abi_ShowManageAccountsAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAccountsSettingsPaneStatics2<D>::ShowAddAccountAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IAccountsSettingsPaneStatics2)->abi_ShowAddAccountAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> event_token impl_IAccountsSettingsPane<D>::AccountCommandsRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::ApplicationSettings::AccountsSettingsPane, Windows::UI::ApplicationSettings::AccountsSettingsPaneCommandsRequestedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IAccountsSettingsPane)->add_AccountCommandsRequested(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IAccountsSettingsPane> impl_IAccountsSettingsPane<D>::AccountCommandsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ApplicationSettings::AccountsSettingsPane, Windows::UI::ApplicationSettings::AccountsSettingsPaneCommandsRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IAccountsSettingsPane>(this, &ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPane::remove_AccountCommandsRequested, AccountCommandsRequested(handler));
}

template <typename D> void impl_IAccountsSettingsPane<D>::AccountCommandsRequested(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IAccountsSettingsPane)->remove_AccountCommandsRequested(cookie));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::SettingsCommand> impl_ISettingsPaneCommandsRequest<D>::ApplicationCommands() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::SettingsCommand> value;
    check_hresult(WINRT_SHIM(ISettingsPaneCommandsRequest)->get_ApplicationCommands(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::ApplicationSettings::SettingsPaneCommandsRequest impl_ISettingsPaneCommandsRequestedEventArgs<D>::Request() const
{
    Windows::UI::ApplicationSettings::SettingsPaneCommandsRequest request { nullptr };
    check_hresult(WINRT_SHIM(ISettingsPaneCommandsRequestedEventArgs)->get_Request(put_abi(request)));
    return request;
}

template <typename D> Windows::UI::ApplicationSettings::SettingsPane impl_ISettingsPaneStatics<D>::GetForCurrentView() const
{
    Windows::UI::ApplicationSettings::SettingsPane current { nullptr };
    check_hresult(WINRT_SHIM(ISettingsPaneStatics)->abi_GetForCurrentView(put_abi(current)));
    return current;
}

template <typename D> void impl_ISettingsPaneStatics<D>::Show() const
{
    check_hresult(WINRT_SHIM(ISettingsPaneStatics)->abi_Show());
}

template <typename D> Windows::UI::ApplicationSettings::SettingsEdgeLocation impl_ISettingsPaneStatics<D>::Edge() const
{
    Windows::UI::ApplicationSettings::SettingsEdgeLocation value {};
    check_hresult(WINRT_SHIM(ISettingsPaneStatics)->get_Edge(&value));
    return value;
}

template <typename D> event_token impl_ISettingsPane<D>::CommandsRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::ApplicationSettings::SettingsPane, Windows::UI::ApplicationSettings::SettingsPaneCommandsRequestedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ISettingsPane)->add_CommandsRequested(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ISettingsPane> impl_ISettingsPane<D>::CommandsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ApplicationSettings::SettingsPane, Windows::UI::ApplicationSettings::SettingsPaneCommandsRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISettingsPane>(this, &ABI::Windows::UI::ApplicationSettings::ISettingsPane::remove_CommandsRequested, CommandsRequested(handler));
}

template <typename D> void impl_ISettingsPane<D>::CommandsRequested(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ISettingsPane)->remove_CommandsRequested(cookie));
}

inline Windows::UI::ApplicationSettings::AccountsSettingsPane AccountsSettingsPane::GetForCurrentView()
{
    return get_activation_factory<AccountsSettingsPane, IAccountsSettingsPaneStatics>().GetForCurrentView();
}

inline void AccountsSettingsPane::Show()
{
    get_activation_factory<AccountsSettingsPane, IAccountsSettingsPaneStatics>().Show();
}

inline Windows::Foundation::IAsyncAction AccountsSettingsPane::ShowManageAccountsAsync()
{
    return get_activation_factory<AccountsSettingsPane, IAccountsSettingsPaneStatics2>().ShowManageAccountsAsync();
}

inline Windows::Foundation::IAsyncAction AccountsSettingsPane::ShowAddAccountAsync()
{
    return get_activation_factory<AccountsSettingsPane, IAccountsSettingsPaneStatics2>().ShowAddAccountAsync();
}

inline CredentialCommand::CredentialCommand(const Windows::Security::Credentials::PasswordCredential & passwordCredential) :
    CredentialCommand(get_activation_factory<CredentialCommand, ICredentialCommandFactory>().CreateCredentialCommand(passwordCredential))
{}

inline CredentialCommand::CredentialCommand(const Windows::Security::Credentials::PasswordCredential & passwordCredential, const Windows::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler & deleted) :
    CredentialCommand(get_activation_factory<CredentialCommand, ICredentialCommandFactory>().CreateCredentialCommandWithHandler(passwordCredential, deleted))
{}

inline SettingsCommand::SettingsCommand(const Windows::Foundation::IInspectable & settingsCommandId, hstring_view label, const Windows::UI::Popups::UICommandInvokedHandler & handler) :
    SettingsCommand(get_activation_factory<SettingsCommand, ISettingsCommandFactory>().CreateSettingsCommand(settingsCommandId, label, handler))
{}

inline Windows::UI::ApplicationSettings::SettingsCommand SettingsCommand::AccountsCommand()
{
    return get_activation_factory<SettingsCommand, ISettingsCommandStatics>().AccountsCommand();
}

inline Windows::UI::ApplicationSettings::SettingsPane SettingsPane::GetForCurrentView()
{
    return get_activation_factory<SettingsPane, ISettingsPaneStatics>().GetForCurrentView();
}

inline void SettingsPane::Show()
{
    get_activation_factory<SettingsPane, ISettingsPaneStatics>().Show();
}

inline Windows::UI::ApplicationSettings::SettingsEdgeLocation SettingsPane::Edge()
{
    return get_activation_factory<SettingsPane, ISettingsPaneStatics>().Edge();
}

inline WebAccountCommand::WebAccountCommand(const Windows::Security::Credentials::WebAccount & webAccount, const Windows::UI::ApplicationSettings::WebAccountCommandInvokedHandler & invoked, Windows::UI::ApplicationSettings::SupportedWebAccountActions actions) :
    WebAccountCommand(get_activation_factory<WebAccountCommand, IWebAccountCommandFactory>().CreateWebAccountCommand(webAccount, invoked, actions))
{}

inline WebAccountProviderCommand::WebAccountProviderCommand(const Windows::Security::Credentials::WebAccountProvider & webAccountProvider, const Windows::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler & invoked) :
    WebAccountProviderCommand(get_activation_factory<WebAccountProviderCommand, IWebAccountProviderCommandFactory>().CreateWebAccountProviderCommand(webAccountProvider, invoked))
{}

}

}
#pragma warning(pop)
