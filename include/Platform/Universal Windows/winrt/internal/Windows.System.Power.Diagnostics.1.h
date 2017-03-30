// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.System.Power.Diagnostics.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::System::Power::Diagnostics {

struct __declspec(uuid("d7663702-d3a6-46e0-8f9b-50b95bb4f9c5")) __declspec(novtable) IBackgroundEnergyDiagnosticsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceSpecificConversionFactor(double * value) = 0;
    virtual HRESULT __stdcall abi_ComputeTotalEnergyUsage(uint64_t * value) = 0;
    virtual HRESULT __stdcall abi_ResetTotalEnergyUsage() = 0;
};

struct __declspec(uuid("23ca0917-cd07-4609-be15-8fe894c5e41e")) __declspec(novtable) IForegroundEnergyDiagnosticsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceSpecificConversionFactor(double * value) = 0;
    virtual HRESULT __stdcall abi_ComputeTotalEnergyUsage(uint64_t * value) = 0;
    virtual HRESULT __stdcall abi_ResetTotalEnergyUsage() = 0;
};

}

namespace ABI {


}

namespace Windows::System::Power::Diagnostics {

template <typename D>
struct WINRT_EBO impl_IBackgroundEnergyDiagnosticsStatics
{
    double DeviceSpecificConversionFactor() const;
    uint64_t ComputeTotalEnergyUsage() const;
    void ResetTotalEnergyUsage() const;
};

template <typename D>
struct WINRT_EBO impl_IForegroundEnergyDiagnosticsStatics
{
    double DeviceSpecificConversionFactor() const;
    uint64_t ComputeTotalEnergyUsage() const;
    void ResetTotalEnergyUsage() const;
};

}

namespace impl {

template <> struct traits<Windows::System::Power::Diagnostics::IBackgroundEnergyDiagnosticsStatics>
{
    using abi = ABI::Windows::System::Power::Diagnostics::IBackgroundEnergyDiagnosticsStatics;
    template <typename D> using consume = Windows::System::Power::Diagnostics::impl_IBackgroundEnergyDiagnosticsStatics<D>;
};

template <> struct traits<Windows::System::Power::Diagnostics::IForegroundEnergyDiagnosticsStatics>
{
    using abi = ABI::Windows::System::Power::Diagnostics::IForegroundEnergyDiagnosticsStatics;
    template <typename D> using consume = Windows::System::Power::Diagnostics::impl_IForegroundEnergyDiagnosticsStatics<D>;
};

template <> struct traits<Windows::System::Power::Diagnostics::BackgroundEnergyDiagnostics>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Power.Diagnostics.BackgroundEnergyDiagnostics"; }
};

template <> struct traits<Windows::System::Power::Diagnostics::ForegroundEnergyDiagnostics>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Power.Diagnostics.ForegroundEnergyDiagnostics"; }
};

}

}
