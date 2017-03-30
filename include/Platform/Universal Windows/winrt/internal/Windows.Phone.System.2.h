// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.System.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Phone::System {

struct ISystemProtectionStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISystemProtectionStatics>
{
    ISystemProtectionStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISystemProtectionUnlockStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISystemProtectionUnlockStatics>
{
    ISystemProtectionUnlockStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
