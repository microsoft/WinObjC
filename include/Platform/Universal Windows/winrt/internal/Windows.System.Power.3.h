// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Power.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::Power {

struct BackgroundEnergyManager
{
    BackgroundEnergyManager() = delete;
    static uint32_t LowUsageLevel();
    static uint32_t NearMaxAcceptableUsageLevel();
    static uint32_t MaxAcceptableUsageLevel();
    static uint32_t ExcessiveUsageLevel();
    static uint32_t NearTerminationUsageLevel();
    static uint32_t TerminationUsageLevel();
    static uint32_t RecentEnergyUsage();
    static uint32_t RecentEnergyUsageLevel();
    static event_token RecentEnergyUsageIncreased(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using RecentEnergyUsageIncreased_revoker = factory_event_revoker<IBackgroundEnergyManagerStatics>;
    static RecentEnergyUsageIncreased_revoker RecentEnergyUsageIncreased(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void RecentEnergyUsageIncreased(event_token token);
    static event_token RecentEnergyUsageReturnedToLow(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using RecentEnergyUsageReturnedToLow_revoker = factory_event_revoker<IBackgroundEnergyManagerStatics>;
    static RecentEnergyUsageReturnedToLow_revoker RecentEnergyUsageReturnedToLow(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void RecentEnergyUsageReturnedToLow(event_token token);
};

struct ForegroundEnergyManager
{
    ForegroundEnergyManager() = delete;
    static uint32_t LowUsageLevel();
    static uint32_t NearMaxAcceptableUsageLevel();
    static uint32_t MaxAcceptableUsageLevel();
    static uint32_t ExcessiveUsageLevel();
    static uint32_t RecentEnergyUsage();
    static uint32_t RecentEnergyUsageLevel();
    static event_token RecentEnergyUsageIncreased(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using RecentEnergyUsageIncreased_revoker = factory_event_revoker<IForegroundEnergyManagerStatics>;
    static RecentEnergyUsageIncreased_revoker RecentEnergyUsageIncreased(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void RecentEnergyUsageIncreased(event_token token);
    static event_token RecentEnergyUsageReturnedToLow(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using RecentEnergyUsageReturnedToLow_revoker = factory_event_revoker<IForegroundEnergyManagerStatics>;
    static RecentEnergyUsageReturnedToLow_revoker RecentEnergyUsageReturnedToLow(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void RecentEnergyUsageReturnedToLow(event_token token);
};

struct PowerManager
{
    PowerManager() = delete;
    static Windows::System::Power::EnergySaverStatus EnergySaverStatus();
    static event_token EnergySaverStatusChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using EnergySaverStatusChanged_revoker = factory_event_revoker<IPowerManagerStatics>;
    static EnergySaverStatusChanged_revoker EnergySaverStatusChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void EnergySaverStatusChanged(event_token token);
    static Windows::System::Power::BatteryStatus BatteryStatus();
    static event_token BatteryStatusChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using BatteryStatusChanged_revoker = factory_event_revoker<IPowerManagerStatics>;
    static BatteryStatusChanged_revoker BatteryStatusChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void BatteryStatusChanged(event_token token);
    static Windows::System::Power::PowerSupplyStatus PowerSupplyStatus();
    static event_token PowerSupplyStatusChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using PowerSupplyStatusChanged_revoker = factory_event_revoker<IPowerManagerStatics>;
    static PowerSupplyStatusChanged_revoker PowerSupplyStatusChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void PowerSupplyStatusChanged(event_token token);
    static int32_t RemainingChargePercent();
    static event_token RemainingChargePercentChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using RemainingChargePercentChanged_revoker = factory_event_revoker<IPowerManagerStatics>;
    static RemainingChargePercentChanged_revoker RemainingChargePercentChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void RemainingChargePercentChanged(event_token token);
    static Windows::Foundation::TimeSpan RemainingDischargeTime();
    static event_token RemainingDischargeTimeChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using RemainingDischargeTimeChanged_revoker = factory_event_revoker<IPowerManagerStatics>;
    static RemainingDischargeTimeChanged_revoker RemainingDischargeTimeChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void RemainingDischargeTimeChanged(event_token token);
};

}

}
