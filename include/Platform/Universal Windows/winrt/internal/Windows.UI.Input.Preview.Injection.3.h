// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Input.Preview.Injection.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Input::Preview::Injection {

struct WINRT_EBO InjectedInputKeyboardInfo :
    Windows::UI::Input::Preview::Injection::IInjectedInputKeyboardInfo
{
    InjectedInputKeyboardInfo(std::nullptr_t) noexcept {}
    InjectedInputKeyboardInfo();
};

struct WINRT_EBO InjectedInputMouseInfo :
    Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo
{
    InjectedInputMouseInfo(std::nullptr_t) noexcept {}
    InjectedInputMouseInfo();
};

struct WINRT_EBO InjectedInputPenInfo :
    Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo
{
    InjectedInputPenInfo(std::nullptr_t) noexcept {}
    InjectedInputPenInfo();
};

struct WINRT_EBO InjectedInputTouchInfo :
    Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo
{
    InjectedInputTouchInfo(std::nullptr_t) noexcept {}
    InjectedInputTouchInfo();
};

struct WINRT_EBO InputInjector :
    Windows::UI::Input::Preview::Injection::IInputInjector
{
    InputInjector(std::nullptr_t) noexcept {}
    static Windows::UI::Input::Preview::Injection::InputInjector TryCreate();
};

}

}
