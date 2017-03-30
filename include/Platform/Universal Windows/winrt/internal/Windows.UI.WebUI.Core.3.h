// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.WebUI.Core.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::WebUI::Core {

template <typename H> struct impl_MenuClosedEventHandler : implements<impl_MenuClosedEventHandler<H>, abi<MenuClosedEventHandler>>, H
{
    impl_MenuClosedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke() noexcept override
    {
        try
        {
            (*this)();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_MenuOpenedEventHandler : implements<impl_MenuOpenedEventHandler<H>, abi<MenuOpenedEventHandler>>, H
{
    impl_MenuOpenedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke() noexcept override
    {
        try
        {
            (*this)();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_SizeChangedEventHandler : implements<impl_SizeChangedEventHandler<H>, abi<SizeChangedEventHandler>>, H
{
    impl_SizeChangedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::UI::WebUI::Core::IWebUICommandBarSizeChangedEventArgs> eventArgs) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::UI::WebUI::Core::WebUICommandBarSizeChangedEventArgs *>(&eventArgs));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::WebUI::Core {

struct WINRT_EBO WebUICommandBar :
    Windows::UI::WebUI::Core::IWebUICommandBar
{
    WebUICommandBar(std::nullptr_t) noexcept {}
    static Windows::UI::WebUI::Core::WebUICommandBar GetForCurrentView();
};

struct WINRT_EBO WebUICommandBarBitmapIcon :
    Windows::UI::WebUI::Core::IWebUICommandBarBitmapIcon
{
    WebUICommandBarBitmapIcon(std::nullptr_t) noexcept {}
    WebUICommandBarBitmapIcon();
    WebUICommandBarBitmapIcon(const Windows::Foundation::Uri & uri);
};

struct WINRT_EBO WebUICommandBarConfirmationButton :
    Windows::UI::WebUI::Core::IWebUICommandBarConfirmationButton
{
    WebUICommandBarConfirmationButton(std::nullptr_t) noexcept {}
    WebUICommandBarConfirmationButton();
};

struct WINRT_EBO WebUICommandBarIconButton :
    Windows::UI::WebUI::Core::IWebUICommandBarIconButton
{
    WebUICommandBarIconButton(std::nullptr_t) noexcept {}
    WebUICommandBarIconButton();
};

struct WINRT_EBO WebUICommandBarItemInvokedEventArgs :
    Windows::UI::WebUI::Core::IWebUICommandBarItemInvokedEventArgs
{
    WebUICommandBarItemInvokedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebUICommandBarSizeChangedEventArgs :
    Windows::UI::WebUI::Core::IWebUICommandBarSizeChangedEventArgs
{
    WebUICommandBarSizeChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebUICommandBarSymbolIcon :
    Windows::UI::WebUI::Core::IWebUICommandBarSymbolIcon
{
    WebUICommandBarSymbolIcon(std::nullptr_t) noexcept {}
    WebUICommandBarSymbolIcon();
    WebUICommandBarSymbolIcon(hstring_view symbol);
};

}

}
