// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Popups.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Popups {

struct __declspec(uuid("33f59b01-5325-43ab-9ab3-bdae440e4121")) __declspec(novtable) IMessageDialog : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall put_Title(hstring value) = 0;
    virtual HRESULT __stdcall get_Commands(Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand> ** value) = 0;
    virtual HRESULT __stdcall get_DefaultCommandIndex(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_DefaultCommandIndex(uint32_t value) = 0;
    virtual HRESULT __stdcall get_CancelCommandIndex(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_CancelCommandIndex(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Content(hstring * value) = 0;
    virtual HRESULT __stdcall put_Content(hstring value) = 0;
    virtual HRESULT __stdcall abi_ShowAsync(Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> ** messageDialogAsyncOperation) = 0;
    virtual HRESULT __stdcall get_Options(winrt::Windows::UI::Popups::MessageDialogOptions * value) = 0;
    virtual HRESULT __stdcall put_Options(winrt::Windows::UI::Popups::MessageDialogOptions value) = 0;
};

struct __declspec(uuid("2d161777-a66f-4ea5-bb87-793ffa4941f2")) __declspec(novtable) IMessageDialogFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring content, Windows::UI::Popups::IMessageDialog ** messageDialog) = 0;
    virtual HRESULT __stdcall abi_CreateWithTitle(hstring content, hstring title, Windows::UI::Popups::IMessageDialog ** messageDialog) = 0;
};

struct __declspec(uuid("4e9bc6dc-880d-47fc-a0a1-72b639e62559")) __declspec(novtable) IPopupMenu : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Commands(Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand> ** value) = 0;
    virtual HRESULT __stdcall abi_ShowAsync(Windows::Foundation::Point invocationPoint, Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_ShowAsyncWithRect(Windows::Foundation::Rect selection, Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_ShowAsyncWithRectAndPlacement(Windows::Foundation::Rect selection, winrt::Windows::UI::Popups::Placement preferredPlacement, Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> ** asyncOperation) = 0;
};

struct __declspec(uuid("4ff93a75-4145-47ff-ac7f-dff1c1fa5b0f")) __declspec(novtable) IUICommand : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Label(hstring * value) = 0;
    virtual HRESULT __stdcall put_Label(hstring value) = 0;
    virtual HRESULT __stdcall get_Invoked(Windows::UI::Popups::UICommandInvokedHandler ** value) = 0;
    virtual HRESULT __stdcall put_Invoked(Windows::UI::Popups::UICommandInvokedHandler * value) = 0;
    virtual HRESULT __stdcall get_Id(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Id(Windows::Foundation::IInspectable * value) = 0;
};

struct __declspec(uuid("a21a8189-26b0-4676-ae94-54041bc125e8")) __declspec(novtable) IUICommandFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring label, Windows::UI::Popups::IUICommand ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateWithHandler(hstring label, Windows::UI::Popups::UICommandInvokedHandler * action, Windows::UI::Popups::IUICommand ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateWithHandlerAndId(hstring label, Windows::UI::Popups::UICommandInvokedHandler * action, Windows::Foundation::IInspectable * commandId, Windows::UI::Popups::IUICommand ** instance) = 0;
};

struct __declspec(uuid("daf77a4f-c27a-4298-9ac6-2922c45e7da6")) __declspec(novtable) UICommandInvokedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::UI::Popups::IUICommand * command) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Popups::MessageDialog> { using default_interface = Windows::UI::Popups::IMessageDialog; };
template <> struct traits<Windows::UI::Popups::PopupMenu> { using default_interface = Windows::UI::Popups::IPopupMenu; };
template <> struct traits<Windows::UI::Popups::UICommand> { using default_interface = Windows::UI::Popups::IUICommand; };
template <> struct traits<Windows::UI::Popups::UICommandSeparator> { using default_interface = Windows::UI::Popups::IUICommand; };

}

namespace Windows::UI::Popups {

template <typename D>
struct WINRT_EBO impl_IMessageDialog
{
    hstring Title() const;
    void Title(hstring_view value) const;
    Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand> Commands() const;
    uint32_t DefaultCommandIndex() const;
    void DefaultCommandIndex(uint32_t value) const;
    uint32_t CancelCommandIndex() const;
    void CancelCommandIndex(uint32_t value) const;
    hstring Content() const;
    void Content(hstring_view value) const;
    Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> ShowAsync() const;
    Windows::UI::Popups::MessageDialogOptions Options() const;
    void Options(Windows::UI::Popups::MessageDialogOptions value) const;
};

template <typename D>
struct WINRT_EBO impl_IMessageDialogFactory
{
    Windows::UI::Popups::MessageDialog Create(hstring_view content) const;
    Windows::UI::Popups::MessageDialog CreateWithTitle(hstring_view content, hstring_view title) const;
};

template <typename D>
struct WINRT_EBO impl_IPopupMenu
{
    Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand> Commands() const;
    Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> ShowAsync(const Windows::Foundation::Point & invocationPoint) const;
    Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> ShowForSelectionAsync(const Windows::Foundation::Rect & selection) const;
    Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> ShowForSelectionAsync(const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const;
};

template <typename D>
struct WINRT_EBO impl_IUICommand
{
    hstring Label() const;
    void Label(hstring_view value) const;
    Windows::UI::Popups::UICommandInvokedHandler Invoked() const;
    void Invoked(const Windows::UI::Popups::UICommandInvokedHandler & value) const;
    Windows::Foundation::IInspectable Id() const;
    void Id(const Windows::Foundation::IInspectable & value) const;
};

template <typename D>
struct WINRT_EBO impl_IUICommandFactory
{
    Windows::UI::Popups::UICommand Create(hstring_view label) const;
    Windows::UI::Popups::UICommand CreateWithHandler(hstring_view label, const Windows::UI::Popups::UICommandInvokedHandler & action) const;
    Windows::UI::Popups::UICommand CreateWithHandlerAndId(hstring_view label, const Windows::UI::Popups::UICommandInvokedHandler & action, const Windows::Foundation::IInspectable & commandId) const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Popups::IMessageDialog>
{
    using abi = ABI::Windows::UI::Popups::IMessageDialog;
    template <typename D> using consume = Windows::UI::Popups::impl_IMessageDialog<D>;
};

template <> struct traits<Windows::UI::Popups::IMessageDialogFactory>
{
    using abi = ABI::Windows::UI::Popups::IMessageDialogFactory;
    template <typename D> using consume = Windows::UI::Popups::impl_IMessageDialogFactory<D>;
};

template <> struct traits<Windows::UI::Popups::IPopupMenu>
{
    using abi = ABI::Windows::UI::Popups::IPopupMenu;
    template <typename D> using consume = Windows::UI::Popups::impl_IPopupMenu<D>;
};

template <> struct traits<Windows::UI::Popups::IUICommand>
{
    using abi = ABI::Windows::UI::Popups::IUICommand;
    template <typename D> using consume = Windows::UI::Popups::impl_IUICommand<D>;
};

template <> struct traits<Windows::UI::Popups::IUICommandFactory>
{
    using abi = ABI::Windows::UI::Popups::IUICommandFactory;
    template <typename D> using consume = Windows::UI::Popups::impl_IUICommandFactory<D>;
};

template <> struct traits<Windows::UI::Popups::UICommandInvokedHandler>
{
    using abi = ABI::Windows::UI::Popups::UICommandInvokedHandler;
};

template <> struct traits<Windows::UI::Popups::MessageDialog>
{
    using abi = ABI::Windows::UI::Popups::MessageDialog;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Popups.MessageDialog"; }
};

template <> struct traits<Windows::UI::Popups::PopupMenu>
{
    using abi = ABI::Windows::UI::Popups::PopupMenu;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Popups.PopupMenu"; }
};

template <> struct traits<Windows::UI::Popups::UICommand>
{
    using abi = ABI::Windows::UI::Popups::UICommand;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Popups.UICommand"; }
};

template <> struct traits<Windows::UI::Popups::UICommandSeparator>
{
    using abi = ABI::Windows::UI::Popups::UICommandSeparator;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Popups.UICommandSeparator"; }
};

}

}
