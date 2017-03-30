// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Profile.SystemManufacturers.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::Profile::SystemManufacturers {

struct ISmbiosInformationStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISmbiosInformationStatics>
{
    ISmbiosInformationStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
