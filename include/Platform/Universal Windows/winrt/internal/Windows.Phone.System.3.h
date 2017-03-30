// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.System.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Phone::System {

struct SystemProtection
{
    SystemProtection() = delete;
    static bool ScreenLocked();
    static void RequestScreenUnlock();
};

}

}
