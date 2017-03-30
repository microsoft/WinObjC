// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Power.Diagnostics.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::Power::Diagnostics {

struct BackgroundEnergyDiagnostics
{
    BackgroundEnergyDiagnostics() = delete;
    static double DeviceSpecificConversionFactor();
    static uint64_t ComputeTotalEnergyUsage();
    static void ResetTotalEnergyUsage();
};

struct ForegroundEnergyDiagnostics
{
    ForegroundEnergyDiagnostics() = delete;
    static double DeviceSpecificConversionFactor();
    static uint64_t ComputeTotalEnergyUsage();
    static void ResetTotalEnergyUsage();
};

}

}
