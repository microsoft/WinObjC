// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.RemoteDesktop.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::RemoteDesktop {

struct InteractiveSession
{
    InteractiveSession() = delete;
    static bool IsRemote();
};

}

}
