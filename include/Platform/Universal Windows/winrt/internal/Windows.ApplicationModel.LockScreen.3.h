// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.LockScreen.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::LockScreen {

struct WINRT_EBO LockApplicationHost :
    Windows::ApplicationModel::LockScreen::ILockApplicationHost
{
    LockApplicationHost(std::nullptr_t) noexcept {}
    static Windows::ApplicationModel::LockScreen::LockApplicationHost GetForCurrentView();
};

struct WINRT_EBO LockScreenBadge :
    Windows::ApplicationModel::LockScreen::ILockScreenBadge
{
    LockScreenBadge(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LockScreenInfo :
    Windows::ApplicationModel::LockScreen::ILockScreenInfo
{
    LockScreenInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LockScreenUnlockingDeferral :
    Windows::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral
{
    LockScreenUnlockingDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LockScreenUnlockingEventArgs :
    Windows::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs
{
    LockScreenUnlockingEventArgs(std::nullptr_t) noexcept {}
};

}

}
