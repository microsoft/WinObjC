// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Portable.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Portable {

struct IServiceDeviceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IServiceDeviceStatics>
{
    IServiceDeviceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IStorageDeviceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IStorageDeviceStatics>
{
    IStorageDeviceStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
