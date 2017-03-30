// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Perception.Automation.Core.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Perception::Automation::Core {

struct ICorePerceptionAutomationStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICorePerceptionAutomationStatics>
{
    ICorePerceptionAutomationStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
