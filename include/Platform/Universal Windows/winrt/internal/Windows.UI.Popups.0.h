// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Popups {

struct IMessageDialog;
struct IMessageDialogFactory;
struct IPopupMenu;
struct IUICommand;
struct IUICommandFactory;
struct UICommandInvokedHandler;
struct MessageDialog;
struct PopupMenu;
struct UICommand;
struct UICommandSeparator;

}

namespace Windows::UI::Popups {

struct UICommandInvokedHandler;
struct IMessageDialog;
struct IMessageDialogFactory;
struct IPopupMenu;
struct IUICommand;
struct IUICommandFactory;
struct MessageDialog;
struct PopupMenu;
struct UICommand;
struct UICommandSeparator;

}

namespace Windows::UI::Popups {

template <typename T> struct impl_IMessageDialog;
template <typename T> struct impl_IMessageDialogFactory;
template <typename T> struct impl_IPopupMenu;
template <typename T> struct impl_IUICommand;
template <typename T> struct impl_IUICommandFactory;
template <typename T> struct impl_UICommandInvokedHandler;

}

namespace Windows::UI::Popups {

enum class MessageDialogOptions : unsigned
{
    None = 0x0,
    AcceptUserInputAfterDelay = 0x1,
};

DEFINE_ENUM_FLAG_OPERATORS(MessageDialogOptions)

enum class Placement
{
    Default = 0,
    Above = 1,
    Below = 2,
    Left = 3,
    Right = 4,
};

}

}
