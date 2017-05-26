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

// WindowsSystemPower.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.System.Power.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSystemPower.h"
#include "WindowsSystemPower_priv.h"

@implementation WSPPowerManager

ComPtr<ABI::Windows::System::Power::IPowerManagerStatics> WSPIPowerManagerStatics_inst() {
    ComPtr<ABI::Windows::System::Power::IPowerManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Power.PowerManager").Get(), &inst));
    return inst;
}

+ (WSPEnergySaverStatus)energySaverStatus {
    ABI::Windows::System::Power::EnergySaverStatus unmarshalledReturn;
    auto _comInst = WSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EnergySaverStatus(&unmarshalledReturn));
    return (WSPEnergySaverStatus)unmarshalledReturn;
}

+ (EventRegistrationToken)addEnergySaverStatusChangedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_EnergySaverStatusChanged(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeEnergySaverStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_EnergySaverStatusChanged(token));
}

+ (WSPBatteryStatus)batteryStatus {
    ABI::Windows::System::Power::BatteryStatus unmarshalledReturn;
    auto _comInst = WSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BatteryStatus(&unmarshalledReturn));
    return (WSPBatteryStatus)unmarshalledReturn;
}

+ (EventRegistrationToken)addBatteryStatusChangedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_BatteryStatusChanged(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeBatteryStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_BatteryStatusChanged(token));
}

+ (WSPPowerSupplyStatus)powerSupplyStatus {
    ABI::Windows::System::Power::PowerSupplyStatus unmarshalledReturn;
    auto _comInst = WSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PowerSupplyStatus(&unmarshalledReturn));
    return (WSPPowerSupplyStatus)unmarshalledReturn;
}

+ (EventRegistrationToken)addPowerSupplyStatusChangedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_PowerSupplyStatusChanged(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removePowerSupplyStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_PowerSupplyStatusChanged(token));
}

+ (int)remainingChargePercent {
    int unmarshalledReturn;
    auto _comInst = WSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RemainingChargePercent(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (EventRegistrationToken)addRemainingChargePercentChangedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_RemainingChargePercentChanged(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeRemainingChargePercentChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_RemainingChargePercentChanged(token));
}

+ (WFTimeSpan*)remainingDischargeTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = WSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RemainingDischargeTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

+ (EventRegistrationToken)addRemainingDischargeTimeChangedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_RemainingDischargeTimeChanged(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeRemainingDischargeTimeChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WSPIPowerManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_RemainingDischargeTimeChanged(token));
}

@end

@implementation WSPBackgroundEnergyManager

ComPtr<ABI::Windows::System::Power::IBackgroundEnergyManagerStatics> WSPIBackgroundEnergyManagerStatics_inst() {
    ComPtr<ABI::Windows::System::Power::IBackgroundEnergyManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Power.BackgroundEnergyManager").Get(),
                                                       &inst));
    return inst;
}

+ (unsigned int)lowUsageLevel {
    unsigned int unmarshalledReturn;
    auto _comInst = WSPIBackgroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LowUsageLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)nearMaxAcceptableUsageLevel {
    unsigned int unmarshalledReturn;
    auto _comInst = WSPIBackgroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NearMaxAcceptableUsageLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)maxAcceptableUsageLevel {
    unsigned int unmarshalledReturn;
    auto _comInst = WSPIBackgroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MaxAcceptableUsageLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)excessiveUsageLevel {
    unsigned int unmarshalledReturn;
    auto _comInst = WSPIBackgroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExcessiveUsageLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)nearTerminationUsageLevel {
    unsigned int unmarshalledReturn;
    auto _comInst = WSPIBackgroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NearTerminationUsageLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)terminationUsageLevel {
    unsigned int unmarshalledReturn;
    auto _comInst = WSPIBackgroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TerminationUsageLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)recentEnergyUsage {
    unsigned int unmarshalledReturn;
    auto _comInst = WSPIBackgroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RecentEnergyUsage(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)recentEnergyUsageLevel {
    unsigned int unmarshalledReturn;
    auto _comInst = WSPIBackgroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RecentEnergyUsageLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (EventRegistrationToken)addRecentEnergyUsageIncreasedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSPIBackgroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_RecentEnergyUsageIncreased(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeRecentEnergyUsageIncreasedEvent:(EventRegistrationToken)token {
    auto _comInst = WSPIBackgroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_RecentEnergyUsageIncreased(token));
}

+ (EventRegistrationToken)addRecentEnergyUsageReturnedToLowEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSPIBackgroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_RecentEnergyUsageReturnedToLow(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeRecentEnergyUsageReturnedToLowEvent:(EventRegistrationToken)token {
    auto _comInst = WSPIBackgroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_RecentEnergyUsageReturnedToLow(token));
}

@end

@implementation WSPForegroundEnergyManager

ComPtr<ABI::Windows::System::Power::IForegroundEnergyManagerStatics> WSPIForegroundEnergyManagerStatics_inst() {
    ComPtr<ABI::Windows::System::Power::IForegroundEnergyManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Power.ForegroundEnergyManager").Get(),
                                                       &inst));
    return inst;
}

+ (unsigned int)lowUsageLevel {
    unsigned int unmarshalledReturn;
    auto _comInst = WSPIForegroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LowUsageLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)nearMaxAcceptableUsageLevel {
    unsigned int unmarshalledReturn;
    auto _comInst = WSPIForegroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NearMaxAcceptableUsageLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)maxAcceptableUsageLevel {
    unsigned int unmarshalledReturn;
    auto _comInst = WSPIForegroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MaxAcceptableUsageLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)excessiveUsageLevel {
    unsigned int unmarshalledReturn;
    auto _comInst = WSPIForegroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExcessiveUsageLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)recentEnergyUsage {
    unsigned int unmarshalledReturn;
    auto _comInst = WSPIForegroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RecentEnergyUsage(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)recentEnergyUsageLevel {
    unsigned int unmarshalledReturn;
    auto _comInst = WSPIForegroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RecentEnergyUsageLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (EventRegistrationToken)addRecentEnergyUsageIncreasedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSPIForegroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_RecentEnergyUsageIncreased(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeRecentEnergyUsageIncreasedEvent:(EventRegistrationToken)token {
    auto _comInst = WSPIForegroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_RecentEnergyUsageIncreased(token));
}

+ (EventRegistrationToken)addRecentEnergyUsageReturnedToLowEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSPIForegroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_RecentEnergyUsageReturnedToLow(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeRecentEnergyUsageReturnedToLowEvent:(EventRegistrationToken)token {
    auto _comInst = WSPIForegroundEnergyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_RecentEnergyUsageReturnedToLow(token));
}

@end
