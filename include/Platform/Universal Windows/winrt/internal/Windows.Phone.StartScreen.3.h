// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.StartScreen.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Phone::StartScreen {

struct WINRT_EBO DualSimTile :
    Windows::Phone::StartScreen::IDualSimTile
{
    DualSimTile(std::nullptr_t) noexcept {}
    DualSimTile();
    static Windows::Phone::StartScreen::DualSimTile GetTileForSim2();
    static Windows::Foundation::IAsyncOperation<bool> UpdateDisplayNameForSim1Async(hstring_view name);
    static Windows::UI::Notifications::TileUpdater CreateTileUpdaterForSim1();
    static Windows::UI::Notifications::TileUpdater CreateTileUpdaterForSim2();
    static Windows::UI::Notifications::BadgeUpdater CreateBadgeUpdaterForSim1();
    static Windows::UI::Notifications::BadgeUpdater CreateBadgeUpdaterForSim2();
    static Windows::UI::Notifications::ToastNotifier CreateToastNotifierForSim1();
    static Windows::UI::Notifications::ToastNotifier CreateToastNotifierForSim2();
};

}

}
