// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::System::Power::Diagnostics {

struct IBackgroundEnergyDiagnosticsStatics;
struct IForegroundEnergyDiagnosticsStatics;

}

namespace Windows::System::Power::Diagnostics {

struct IBackgroundEnergyDiagnosticsStatics;
struct IForegroundEnergyDiagnosticsStatics;
struct BackgroundEnergyDiagnostics;
struct ForegroundEnergyDiagnostics;

}

namespace Windows::System::Power::Diagnostics {

template <typename T> struct impl_IBackgroundEnergyDiagnosticsStatics;
template <typename T> struct impl_IForegroundEnergyDiagnosticsStatics;

}

}
