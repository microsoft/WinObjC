// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Phone::System {

struct ISystemProtectionStatics;
struct ISystemProtectionUnlockStatics;

}

namespace Windows::Phone::System {

struct ISystemProtectionStatics;
struct ISystemProtectionUnlockStatics;
struct SystemProtection;

}

namespace Windows::Phone::System {

template <typename T> struct impl_ISystemProtectionStatics;
template <typename T> struct impl_ISystemProtectionUnlockStatics;

}

}
