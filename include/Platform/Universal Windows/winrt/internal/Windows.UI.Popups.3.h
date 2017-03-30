// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Popups.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Popups {

template <typename H> struct impl_UICommandInvokedHandler : implements<impl_UICommandInvokedHandler<H>, abi<UICommandInvokedHandler>>, H
{
    impl_UICommandInvokedHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::UI::Popups::IUICommand> command) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::UI::Popups::IUICommand *>(&command));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Popups {

struct WINRT_EBO MessageDialog :
    Windows::UI::Popups::IMessageDialog
{
    MessageDialog(std::nullptr_t) noexcept {}
    MessageDialog(hstring_view content);
    MessageDialog(hstring_view content, hstring_view title);
};

struct WINRT_EBO PopupMenu :
    Windows::UI::Popups::IPopupMenu
{
    PopupMenu(std::nullptr_t) noexcept {}
    PopupMenu();
};

struct WINRT_EBO UICommand :
    Windows::UI::Popups::IUICommand
{
    UICommand(std::nullptr_t) noexcept {}
    UICommand();
    UICommand(hstring_view label);
    UICommand(hstring_view label, const Windows::UI::Popups::UICommandInvokedHandler & action);
    UICommand(hstring_view label, const Windows::UI::Popups::UICommandInvokedHandler & action, const Windows::Foundation::IInspectable & commandId);
};

struct WINRT_EBO UICommandSeparator :
    Windows::UI::Popups::IUICommand
{
    UICommandSeparator(std::nullptr_t) noexcept {}
    UICommandSeparator();
};

}

}
