// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.Media.Devices.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Phone::Media::Devices {

struct WINRT_EBO AudioRoutingManager :
    Windows::Phone::Media::Devices::IAudioRoutingManager
{
    AudioRoutingManager(std::nullptr_t) noexcept {}
    static Windows::Phone::Media::Devices::AudioRoutingManager GetDefault();
};

}

}
