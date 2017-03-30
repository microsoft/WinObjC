// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Power.Diagnostics.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::Power::Diagnostics {

struct IBackgroundEnergyDiagnosticsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IBackgroundEnergyDiagnosticsStatics>
{
    IBackgroundEnergyDiagnosticsStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IForegroundEnergyDiagnosticsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IForegroundEnergyDiagnosticsStatics>
{
    IForegroundEnergyDiagnosticsStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
