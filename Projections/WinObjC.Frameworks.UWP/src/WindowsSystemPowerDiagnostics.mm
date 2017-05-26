//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// WindowsSystemPowerDiagnostics.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.System.Power.Diagnostics.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSystemPowerDiagnostics.h"
#include "WindowsSystemPowerDiagnostics_priv.h"

@implementation WSPDBackgroundEnergyDiagnostics

ComPtr<ABI::Windows::System::Power::Diagnostics::IBackgroundEnergyDiagnosticsStatics> WSPDIBackgroundEnergyDiagnosticsStatics_inst() {
    ComPtr<ABI::Windows::System::Power::Diagnostics::IBackgroundEnergyDiagnosticsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.System.Power.Diagnostics.BackgroundEnergyDiagnostics").Get(), &inst));
    return inst;
}

+ (double)deviceSpecificConversionFactor {
    double unmarshalledReturn;
    auto _comInst = WSPDIBackgroundEnergyDiagnosticsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DeviceSpecificConversionFactor(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint64_t)computeTotalEnergyUsage {
    uint64_t unmarshalledReturn;
    auto _comInst = WSPDIBackgroundEnergyDiagnosticsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ComputeTotalEnergyUsage(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (void)resetTotalEnergyUsage {
    auto _comInst = WSPDIBackgroundEnergyDiagnosticsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ResetTotalEnergyUsage());
}

@end

@implementation WSPDForegroundEnergyDiagnostics

ComPtr<ABI::Windows::System::Power::Diagnostics::IForegroundEnergyDiagnosticsStatics> WSPDIForegroundEnergyDiagnosticsStatics_inst() {
    ComPtr<ABI::Windows::System::Power::Diagnostics::IForegroundEnergyDiagnosticsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.System.Power.Diagnostics.ForegroundEnergyDiagnostics").Get(), &inst));
    return inst;
}

+ (double)deviceSpecificConversionFactor {
    double unmarshalledReturn;
    auto _comInst = WSPDIForegroundEnergyDiagnosticsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DeviceSpecificConversionFactor(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint64_t)computeTotalEnergyUsage {
    uint64_t unmarshalledReturn;
    auto _comInst = WSPDIForegroundEnergyDiagnosticsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ComputeTotalEnergyUsage(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (void)resetTotalEnergyUsage {
    auto _comInst = WSPDIForegroundEnergyDiagnosticsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ResetTotalEnergyUsage());
}

@end
