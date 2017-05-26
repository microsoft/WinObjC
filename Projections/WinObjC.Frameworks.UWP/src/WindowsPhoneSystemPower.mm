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

// WindowsPhoneSystemPower.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Phone.System.Power.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPhoneSystemPower.h"
#include "WindowsPhoneSystemPower_priv.h"

@implementation WPSPPowerManager

ComPtr<ABI::Windows::Phone::System::Power::IPowerManagerStatics2> WPSPIPowerManagerStatics2_inst() {
    ComPtr<ABI::Windows::Phone::System::Power::IPowerManagerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Phone.System.Power.PowerManager").Get(), &inst));
    return inst;
}

+ (BOOL)powerSavingModeEnabled {
    boolean unmarshalledReturn;
    auto _comInst = WPSPIPowerManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_PowerSavingModeEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

ComPtr<ABI::Windows::Phone::System::Power::IPowerManagerStatics> WPSPIPowerManagerStatics_inst() {
    ComPtr<ABI::Windows::Phone::System::Power::IPowerManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Phone.System.Power.PowerManager").Get(), &inst));
    return inst;
}

+ (WPSPPowerSavingMode)powerSavingMode {
    ABI::Windows::Phone::System::Power::PowerSavingMode unmarshalledReturn;
    auto _comInst = WPSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PowerSavingMode(&unmarshalledReturn));
    return (WPSPPowerSavingMode)unmarshalledReturn;
}

+ (EventRegistrationToken)addPowerSavingModeChangedEvent:(void (^)(RTObject*, RTObject*))changeHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WPSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_PowerSavingModeChanged(Make<EventHandler_System_Object>(changeHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removePowerSavingModeChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WPSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_PowerSavingModeChanged(token));
}

@end
