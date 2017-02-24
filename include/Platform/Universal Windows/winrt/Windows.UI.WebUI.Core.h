// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.WebUI.Core.3.h"
#include "Windows.UI.WebUI.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::WebUI::Core {

template <typename L> MenuClosedEventHandler::MenuClosedEventHandler(L lambda) :
    MenuClosedEventHandler(impl::make_delegate<impl_MenuClosedEventHandler<L>, MenuClosedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> MenuClosedEventHandler::MenuClosedEventHandler(F * function) :
    MenuClosedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> MenuClosedEventHandler::MenuClosedEventHandler(O * object, M method) :
    MenuClosedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void MenuClosedEventHandler::operator()() const
{
    check_hresult((*(abi<MenuClosedEventHandler> **)this)->abi_Invoke());
}

template <typename L> MenuOpenedEventHandler::MenuOpenedEventHandler(L lambda) :
    MenuOpenedEventHandler(impl::make_delegate<impl_MenuOpenedEventHandler<L>, MenuOpenedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> MenuOpenedEventHandler::MenuOpenedEventHandler(F * function) :
    MenuOpenedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> MenuOpenedEventHandler::MenuOpenedEventHandler(O * object, M method) :
    MenuOpenedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void MenuOpenedEventHandler::operator()() const
{
    check_hresult((*(abi<MenuOpenedEventHandler> **)this)->abi_Invoke());
}

template <typename L> SizeChangedEventHandler::SizeChangedEventHandler(L lambda) :
    SizeChangedEventHandler(impl::make_delegate<impl_SizeChangedEventHandler<L>, SizeChangedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> SizeChangedEventHandler::SizeChangedEventHandler(F * function) :
    SizeChangedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> SizeChangedEventHandler::SizeChangedEventHandler(O * object, M method) :
    SizeChangedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void SizeChangedEventHandler::operator()(const Windows::UI::WebUI::Core::WebUICommandBarSizeChangedEventArgs & eventArgs) const
{
    check_hresult((*(abi<SizeChangedEventHandler> **)this)->abi_Invoke(get_abi(eventArgs)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::UI::WebUI::Core::IWebUICommandBar> : produce_base<D, Windows::UI::WebUI::Core::IWebUICommandBar>
{
    HRESULT __stdcall get_Visible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Visible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Visible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Visible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Opacity(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Opacity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Opacity(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Opacity(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ForegroundColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ForegroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ForegroundColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ForegroundColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackgroundColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BackgroundColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClosedDisplayMode(Windows::UI::WebUI::Core::WebUICommandBarClosedDisplayMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClosedDisplayMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ClosedDisplayMode(Windows::UI::WebUI::Core::WebUICommandBarClosedDisplayMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClosedDisplayMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsOpen(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOpen());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsOpen(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsOpen(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Size(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Size());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PrimaryCommands(impl::abi_arg_out<Windows::Foundation::Collections::IObservableVector<Windows::UI::WebUI::Core::IWebUICommandBarElement>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrimaryCommands());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SecondaryCommands(impl::abi_arg_out<Windows::Foundation::Collections::IObservableVector<Windows::UI::WebUI::Core::IWebUICommandBarElement>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SecondaryCommands());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MenuOpened(impl::abi_arg_in<Windows::UI::WebUI::Core::MenuOpenedEventHandler> handler, event_token * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MenuOpened(*reinterpret_cast<const Windows::UI::WebUI::Core::MenuOpenedEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MenuOpened(event_token value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MenuOpened(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MenuClosed(impl::abi_arg_in<Windows::UI::WebUI::Core::MenuClosedEventHandler> handler, event_token * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MenuClosed(*reinterpret_cast<const Windows::UI::WebUI::Core::MenuClosedEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MenuClosed(event_token value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MenuClosed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SizeChanged(impl::abi_arg_in<Windows::UI::WebUI::Core::SizeChangedEventHandler> handler, event_token * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SizeChanged(*reinterpret_cast<const Windows::UI::WebUI::Core::SizeChangedEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SizeChanged(event_token value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SizeChanged(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::WebUI::Core::IWebUICommandBarBitmapIcon> : produce_base<D, Windows::UI::WebUI::Core::IWebUICommandBarBitmapIcon>
{
    HRESULT __stdcall get_Uri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Uri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Uri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::WebUI::Core::IWebUICommandBarBitmapIconFactory> : produce_base<D, Windows::UI::WebUI::Core::IWebUICommandBarBitmapIconFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::UI::WebUI::Core::IWebUICommandBarBitmapIcon> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
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
struct produce<D, Windows::UI::WebUI::Core::IWebUICommandBarConfirmationButton> : produce_base<D, Windows::UI::WebUI::Core::IWebUICommandBarConfirmationButton>
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

    HRESULT __stdcall add_ItemInvoked(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::WebUI::Core::WebUICommandBarConfirmationButton, Windows::UI::WebUI::Core::WebUICommandBarItemInvokedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ItemInvoked(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::WebUI::Core::WebUICommandBarConfirmationButton, Windows::UI::WebUI::Core::WebUICommandBarItemInvokedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ItemInvoked(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemInvoked(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::WebUI::Core::IWebUICommandBarElement> : produce_base<D, Windows::UI::WebUI::Core::IWebUICommandBarElement>
{};

template <typename D>
struct produce<D, Windows::UI::WebUI::Core::IWebUICommandBarIcon> : produce_base<D, Windows::UI::WebUI::Core::IWebUICommandBarIcon>
{};

template <typename D>
struct produce<D, Windows::UI::WebUI::Core::IWebUICommandBarIconButton> : produce_base<D, Windows::UI::WebUI::Core::IWebUICommandBarIconButton>
{
    HRESULT __stdcall get_Enabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Enabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Enabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Enabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Label(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Label());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Label(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Label(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsToggleButton(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsToggleButton());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsToggleButton(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsToggleButton(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsChecked(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsChecked());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsChecked(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsChecked(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Icon(impl::abi_arg_out<Windows::UI::WebUI::Core::IWebUICommandBarIcon> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Icon());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Icon(impl::abi_arg_in<Windows::UI::WebUI::Core::IWebUICommandBarIcon> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Icon(*reinterpret_cast<const Windows::UI::WebUI::Core::IWebUICommandBarIcon *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ItemInvoked(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::WebUI::Core::WebUICommandBarIconButton, Windows::UI::WebUI::Core::WebUICommandBarItemInvokedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ItemInvoked(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::WebUI::Core::WebUICommandBarIconButton, Windows::UI::WebUI::Core::WebUICommandBarItemInvokedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ItemInvoked(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemInvoked(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::WebUI::Core::IWebUICommandBarItemInvokedEventArgs> : produce_base<D, Windows::UI::WebUI::Core::IWebUICommandBarItemInvokedEventArgs>
{
    HRESULT __stdcall get_IsPrimaryCommand(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPrimaryCommand());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::WebUI::Core::IWebUICommandBarSizeChangedEventArgs> : produce_base<D, Windows::UI::WebUI::Core::IWebUICommandBarSizeChangedEventArgs>
{
    HRESULT __stdcall get_Size(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Size());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::WebUI::Core::IWebUICommandBarStatics> : produce_base<D, Windows::UI::WebUI::Core::IWebUICommandBarStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::UI::WebUI::Core::IWebUICommandBar> commandBar) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *commandBar = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *commandBar = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::WebUI::Core::IWebUICommandBarSymbolIcon> : produce_base<D, Windows::UI::WebUI::Core::IWebUICommandBarSymbolIcon>
{
    HRESULT __stdcall get_Symbol(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Symbol());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Symbol(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Symbol(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::WebUI::Core::IWebUICommandBarSymbolIconFactory> : produce_base<D, Windows::UI::WebUI::Core::IWebUICommandBarSymbolIconFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> symbol, impl::abi_arg_out<Windows::UI::WebUI::Core::IWebUICommandBarSymbolIcon> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&symbol)));
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

namespace Windows::UI::WebUI::Core {

template <typename D> bool impl_IWebUICommandBarItemInvokedEventArgs<D>::IsPrimaryCommand() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWebUICommandBarItemInvokedEventArgs)->get_IsPrimaryCommand(&value));
    return value;
}

template <typename D> bool impl_IWebUICommandBarIconButton<D>::Enabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWebUICommandBarIconButton)->get_Enabled(&value));
    return value;
}

template <typename D> void impl_IWebUICommandBarIconButton<D>::Enabled(bool value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBarIconButton)->put_Enabled(value));
}

template <typename D> hstring impl_IWebUICommandBarIconButton<D>::Label() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWebUICommandBarIconButton)->get_Label(put_abi(value)));
    return value;
}

template <typename D> void impl_IWebUICommandBarIconButton<D>::Label(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBarIconButton)->put_Label(get_abi(value)));
}

template <typename D> bool impl_IWebUICommandBarIconButton<D>::IsToggleButton() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWebUICommandBarIconButton)->get_IsToggleButton(&value));
    return value;
}

template <typename D> void impl_IWebUICommandBarIconButton<D>::IsToggleButton(bool value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBarIconButton)->put_IsToggleButton(value));
}

template <typename D> bool impl_IWebUICommandBarIconButton<D>::IsChecked() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWebUICommandBarIconButton)->get_IsChecked(&value));
    return value;
}

template <typename D> void impl_IWebUICommandBarIconButton<D>::IsChecked(bool value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBarIconButton)->put_IsChecked(value));
}

template <typename D> Windows::UI::WebUI::Core::IWebUICommandBarIcon impl_IWebUICommandBarIconButton<D>::Icon() const
{
    Windows::UI::WebUI::Core::IWebUICommandBarIcon value;
    check_hresult(WINRT_SHIM(IWebUICommandBarIconButton)->get_Icon(put_abi(value)));
    return value;
}

template <typename D> void impl_IWebUICommandBarIconButton<D>::Icon(const Windows::UI::WebUI::Core::IWebUICommandBarIcon & value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBarIconButton)->put_Icon(get_abi(value)));
}

template <typename D> event_token impl_IWebUICommandBarIconButton<D>::ItemInvoked(const Windows::Foundation::TypedEventHandler<Windows::UI::WebUI::Core::WebUICommandBarIconButton, Windows::UI::WebUI::Core::WebUICommandBarItemInvokedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IWebUICommandBarIconButton)->add_ItemInvoked(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IWebUICommandBarIconButton> impl_IWebUICommandBarIconButton<D>::ItemInvoked(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::WebUI::Core::WebUICommandBarIconButton, Windows::UI::WebUI::Core::WebUICommandBarItemInvokedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IWebUICommandBarIconButton>(this, &ABI::Windows::UI::WebUI::Core::IWebUICommandBarIconButton::remove_ItemInvoked, ItemInvoked(handler));
}

template <typename D> void impl_IWebUICommandBarIconButton<D>::ItemInvoked(event_token token) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBarIconButton)->remove_ItemInvoked(token));
}

template <typename D> hstring impl_IWebUICommandBarConfirmationButton<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWebUICommandBarConfirmationButton)->get_Text(put_abi(value)));
    return value;
}

template <typename D> void impl_IWebUICommandBarConfirmationButton<D>::Text(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBarConfirmationButton)->put_Text(get_abi(value)));
}

template <typename D> event_token impl_IWebUICommandBarConfirmationButton<D>::ItemInvoked(const Windows::Foundation::TypedEventHandler<Windows::UI::WebUI::Core::WebUICommandBarConfirmationButton, Windows::UI::WebUI::Core::WebUICommandBarItemInvokedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IWebUICommandBarConfirmationButton)->add_ItemInvoked(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IWebUICommandBarConfirmationButton> impl_IWebUICommandBarConfirmationButton<D>::ItemInvoked(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::WebUI::Core::WebUICommandBarConfirmationButton, Windows::UI::WebUI::Core::WebUICommandBarItemInvokedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IWebUICommandBarConfirmationButton>(this, &ABI::Windows::UI::WebUI::Core::IWebUICommandBarConfirmationButton::remove_ItemInvoked, ItemInvoked(handler));
}

template <typename D> void impl_IWebUICommandBarConfirmationButton<D>::ItemInvoked(event_token token) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBarConfirmationButton)->remove_ItemInvoked(token));
}

template <typename D> Windows::Foundation::Uri impl_IWebUICommandBarBitmapIcon<D>::Uri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IWebUICommandBarBitmapIcon)->get_Uri(put_abi(value)));
    return value;
}

template <typename D> void impl_IWebUICommandBarBitmapIcon<D>::Uri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBarBitmapIcon)->put_Uri(get_abi(value)));
}

template <typename D> Windows::UI::WebUI::Core::WebUICommandBarBitmapIcon impl_IWebUICommandBarBitmapIconFactory<D>::Create(const Windows::Foundation::Uri & uri) const
{
    Windows::UI::WebUI::Core::WebUICommandBarBitmapIcon instance { nullptr };
    check_hresult(WINRT_SHIM(IWebUICommandBarBitmapIconFactory)->abi_Create(get_abi(uri), put_abi(instance)));
    return instance;
}

template <typename D> hstring impl_IWebUICommandBarSymbolIcon<D>::Symbol() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWebUICommandBarSymbolIcon)->get_Symbol(put_abi(value)));
    return value;
}

template <typename D> void impl_IWebUICommandBarSymbolIcon<D>::Symbol(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBarSymbolIcon)->put_Symbol(get_abi(value)));
}

template <typename D> Windows::UI::WebUI::Core::WebUICommandBarSymbolIcon impl_IWebUICommandBarSymbolIconFactory<D>::Create(hstring_view symbol) const
{
    Windows::UI::WebUI::Core::WebUICommandBarSymbolIcon instance { nullptr };
    check_hresult(WINRT_SHIM(IWebUICommandBarSymbolIconFactory)->abi_Create(get_abi(symbol), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::Size impl_IWebUICommandBarSizeChangedEventArgs<D>::Size() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IWebUICommandBarSizeChangedEventArgs)->get_Size(put_abi(value)));
    return value;
}

template <typename D> bool impl_IWebUICommandBar<D>::Visible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWebUICommandBar)->get_Visible(&value));
    return value;
}

template <typename D> void impl_IWebUICommandBar<D>::Visible(bool value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBar)->put_Visible(value));
}

template <typename D> double impl_IWebUICommandBar<D>::Opacity() const
{
    double value {};
    check_hresult(WINRT_SHIM(IWebUICommandBar)->get_Opacity(&value));
    return value;
}

template <typename D> void impl_IWebUICommandBar<D>::Opacity(double value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBar)->put_Opacity(value));
}

template <typename D> Windows::UI::Color impl_IWebUICommandBar<D>::ForegroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IWebUICommandBar)->get_ForegroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IWebUICommandBar<D>::ForegroundColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBar)->put_ForegroundColor(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IWebUICommandBar<D>::BackgroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IWebUICommandBar)->get_BackgroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IWebUICommandBar<D>::BackgroundColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBar)->put_BackgroundColor(get_abi(value)));
}

template <typename D> Windows::UI::WebUI::Core::WebUICommandBarClosedDisplayMode impl_IWebUICommandBar<D>::ClosedDisplayMode() const
{
    Windows::UI::WebUI::Core::WebUICommandBarClosedDisplayMode value {};
    check_hresult(WINRT_SHIM(IWebUICommandBar)->get_ClosedDisplayMode(&value));
    return value;
}

template <typename D> void impl_IWebUICommandBar<D>::ClosedDisplayMode(Windows::UI::WebUI::Core::WebUICommandBarClosedDisplayMode value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBar)->put_ClosedDisplayMode(value));
}

template <typename D> bool impl_IWebUICommandBar<D>::IsOpen() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWebUICommandBar)->get_IsOpen(&value));
    return value;
}

template <typename D> void impl_IWebUICommandBar<D>::IsOpen(bool value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBar)->put_IsOpen(value));
}

template <typename D> Windows::Foundation::Size impl_IWebUICommandBar<D>::Size() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IWebUICommandBar)->get_Size(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IObservableVector<Windows::UI::WebUI::Core::IWebUICommandBarElement> impl_IWebUICommandBar<D>::PrimaryCommands() const
{
    Windows::Foundation::Collections::IObservableVector<Windows::UI::WebUI::Core::IWebUICommandBarElement> value;
    check_hresult(WINRT_SHIM(IWebUICommandBar)->get_PrimaryCommands(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IObservableVector<Windows::UI::WebUI::Core::IWebUICommandBarElement> impl_IWebUICommandBar<D>::SecondaryCommands() const
{
    Windows::Foundation::Collections::IObservableVector<Windows::UI::WebUI::Core::IWebUICommandBarElement> value;
    check_hresult(WINRT_SHIM(IWebUICommandBar)->get_SecondaryCommands(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IWebUICommandBar<D>::MenuOpened(const Windows::UI::WebUI::Core::MenuOpenedEventHandler & handler) const
{
    event_token value {};
    check_hresult(WINRT_SHIM(IWebUICommandBar)->add_MenuOpened(get_abi(handler), &value));
    return value;
}

template <typename D> event_revoker<IWebUICommandBar> impl_IWebUICommandBar<D>::MenuOpened(auto_revoke_t, const Windows::UI::WebUI::Core::MenuOpenedEventHandler & handler) const
{
    return impl::make_event_revoker<D, IWebUICommandBar>(this, &ABI::Windows::UI::WebUI::Core::IWebUICommandBar::remove_MenuOpened, MenuOpened(handler));
}

template <typename D> void impl_IWebUICommandBar<D>::MenuOpened(event_token value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBar)->remove_MenuOpened(value));
}

template <typename D> event_token impl_IWebUICommandBar<D>::MenuClosed(const Windows::UI::WebUI::Core::MenuClosedEventHandler & handler) const
{
    event_token value {};
    check_hresult(WINRT_SHIM(IWebUICommandBar)->add_MenuClosed(get_abi(handler), &value));
    return value;
}

template <typename D> event_revoker<IWebUICommandBar> impl_IWebUICommandBar<D>::MenuClosed(auto_revoke_t, const Windows::UI::WebUI::Core::MenuClosedEventHandler & handler) const
{
    return impl::make_event_revoker<D, IWebUICommandBar>(this, &ABI::Windows::UI::WebUI::Core::IWebUICommandBar::remove_MenuClosed, MenuClosed(handler));
}

template <typename D> void impl_IWebUICommandBar<D>::MenuClosed(event_token value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBar)->remove_MenuClosed(value));
}

template <typename D> event_token impl_IWebUICommandBar<D>::SizeChanged(const Windows::UI::WebUI::Core::SizeChangedEventHandler & handler) const
{
    event_token value {};
    check_hresult(WINRT_SHIM(IWebUICommandBar)->add_SizeChanged(get_abi(handler), &value));
    return value;
}

template <typename D> event_revoker<IWebUICommandBar> impl_IWebUICommandBar<D>::SizeChanged(auto_revoke_t, const Windows::UI::WebUI::Core::SizeChangedEventHandler & handler) const
{
    return impl::make_event_revoker<D, IWebUICommandBar>(this, &ABI::Windows::UI::WebUI::Core::IWebUICommandBar::remove_SizeChanged, SizeChanged(handler));
}

template <typename D> void impl_IWebUICommandBar<D>::SizeChanged(event_token value) const
{
    check_hresult(WINRT_SHIM(IWebUICommandBar)->remove_SizeChanged(value));
}

template <typename D> Windows::UI::WebUI::Core::WebUICommandBar impl_IWebUICommandBarStatics<D>::GetForCurrentView() const
{
    Windows::UI::WebUI::Core::WebUICommandBar commandBar { nullptr };
    check_hresult(WINRT_SHIM(IWebUICommandBarStatics)->abi_GetForCurrentView(put_abi(commandBar)));
    return commandBar;
}

inline Windows::UI::WebUI::Core::WebUICommandBar WebUICommandBar::GetForCurrentView()
{
    return get_activation_factory<WebUICommandBar, IWebUICommandBarStatics>().GetForCurrentView();
}

inline WebUICommandBarBitmapIcon::WebUICommandBarBitmapIcon() :
    WebUICommandBarBitmapIcon(activate_instance<WebUICommandBarBitmapIcon>())
{}

inline WebUICommandBarBitmapIcon::WebUICommandBarBitmapIcon(const Windows::Foundation::Uri & uri) :
    WebUICommandBarBitmapIcon(get_activation_factory<WebUICommandBarBitmapIcon, IWebUICommandBarBitmapIconFactory>().Create(uri))
{}

inline WebUICommandBarConfirmationButton::WebUICommandBarConfirmationButton() :
    WebUICommandBarConfirmationButton(activate_instance<WebUICommandBarConfirmationButton>())
{}

inline WebUICommandBarIconButton::WebUICommandBarIconButton() :
    WebUICommandBarIconButton(activate_instance<WebUICommandBarIconButton>())
{}

inline WebUICommandBarSymbolIcon::WebUICommandBarSymbolIcon() :
    WebUICommandBarSymbolIcon(activate_instance<WebUICommandBarSymbolIcon>())
{}

inline WebUICommandBarSymbolIcon::WebUICommandBarSymbolIcon(hstring_view symbol) :
    WebUICommandBarSymbolIcon(get_activation_factory<WebUICommandBarSymbolIcon, IWebUICommandBarSymbolIconFactory>().Create(symbol))
{}

}

}
#pragma warning(pop)
