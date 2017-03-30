// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.System.Profile.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Phone::System::Profile {

struct [[deprecated("Use Windows.System.Profile.RetailInfo instead.")]] RetailMode
{
    RetailMode() = delete;
    [[deprecated("Use Windows.System.Profile.IRetailInfoStatics instead.")]] static bool RetailModeEnabled();
};

}

}
