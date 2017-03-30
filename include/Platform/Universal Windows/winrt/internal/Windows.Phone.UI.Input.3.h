// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.UI.Input.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Phone::UI::Input {

struct WINRT_EBO BackPressedEventArgs :
    Windows::Phone::UI::Input::IBackPressedEventArgs
{
    BackPressedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CameraEventArgs :
    Windows::Phone::UI::Input::ICameraEventArgs
{
    CameraEventArgs(std::nullptr_t) noexcept {}
};

struct HardwareButtons
{
    HardwareButtons() = delete;
    static event_token BackPressed(const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::BackPressedEventArgs> & handler);
    using BackPressed_revoker = factory_event_revoker<IHardwareButtonsStatics>;
    static BackPressed_revoker BackPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::BackPressedEventArgs> & handler);
    static void BackPressed(event_token token);
    static event_token CameraHalfPressed(const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler);
    using CameraHalfPressed_revoker = factory_event_revoker<IHardwareButtonsStatics2>;
    static CameraHalfPressed_revoker CameraHalfPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler);
    static void CameraHalfPressed(event_token token);
    static event_token CameraPressed(const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler);
    using CameraPressed_revoker = factory_event_revoker<IHardwareButtonsStatics2>;
    static CameraPressed_revoker CameraPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler);
    static void CameraPressed(event_token token);
    static event_token CameraReleased(const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler);
    using CameraReleased_revoker = factory_event_revoker<IHardwareButtonsStatics2>;
    static CameraReleased_revoker CameraReleased(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler);
    static void CameraReleased(event_token token);
};

}

}
