// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Perception.People.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Perception::People {

struct WINRT_EBO HeadPose :
    Windows::Perception::People::IHeadPose
{
    HeadPose(std::nullptr_t) noexcept {}
};

}

}
