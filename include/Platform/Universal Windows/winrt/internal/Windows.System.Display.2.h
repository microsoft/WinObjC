// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Display.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::Display {

struct IDisplayRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IDisplayRequest>
{
    IDisplayRequest(std::nullptr_t = nullptr) noexcept {}
};

}

}
