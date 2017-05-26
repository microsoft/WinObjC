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

// WindowsPhoneDevicesPower.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Phone.Devices.Power.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPhoneDevicesPower.h"
#include "WindowsPhoneDevicesPower_priv.h"

@implementation WPDPBattery

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Devices::Power::IBattery> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Phone::Devices::Power::IBatteryStatics> WPDPIBatteryStatics_inst() {
    ComPtr<ABI::Windows::Phone::Devices::Power::IBatteryStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Phone.Devices.Power.Battery").Get(), &inst));
    return inst;
}

+ (WPDPBattery*)getDefault {
    ComPtr<ABI::Windows::Phone::Devices::Power::IBattery> unmarshalledReturn;
    auto _comInst = WPDPIBatteryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPDPBattery>(unmarshalledReturn.Get());
}

- (int)remainingChargePercent {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Devices::Power::IBattery>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemainingChargePercent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)remainingDischargeTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Devices::Power::IBattery>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemainingDischargeTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (EventRegistrationToken)addRemainingChargePercentChangedEvent:(void (^)(RTObject*, RTObject*))changeHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Devices::Power::IBattery>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_RemainingChargePercentChanged(Make<EventHandler_System_Object>(changeHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRemainingChargePercentChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Devices::Power::IBattery>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RemainingChargePercentChanged(token));
}

@end
