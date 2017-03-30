// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Management.Orchestration.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Management::Orchestration {

struct WINRT_EBO CurrentAppOrchestration :
    Windows::Management::Orchestration::ICurrentAppOrchestration
{
    CurrentAppOrchestration(std::nullptr_t) noexcept {}
    static Windows::Management::Orchestration::CurrentAppOrchestration GetForCurrentView();
};

struct WINRT_EBO SingleAppModeContext :
    Windows::Management::Orchestration::ISingleAppModeContext
{
    SingleAppModeContext(std::nullptr_t) noexcept {}
};

}

}
