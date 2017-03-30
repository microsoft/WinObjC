// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Gaming.UI.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Gaming::UI {

struct GameBar
{
    GameBar() = delete;
    static event_token VisibilityChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using VisibilityChanged_revoker = factory_event_revoker<IGameBarStatics>;
    static VisibilityChanged_revoker VisibilityChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void VisibilityChanged(event_token token);
    static event_token IsInputRedirectedChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using IsInputRedirectedChanged_revoker = factory_event_revoker<IGameBarStatics>;
    static IsInputRedirectedChanged_revoker IsInputRedirectedChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void IsInputRedirectedChanged(event_token token);
    static bool Visible();
    static bool IsInputRedirected();
};

}

}
