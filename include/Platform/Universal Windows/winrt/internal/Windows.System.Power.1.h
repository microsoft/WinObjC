// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.System.Power.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::System::Power {

struct __declspec(uuid("b3161d95-1180-4376-96e1-4095568147ce")) __declspec(novtable) IBackgroundEnergyManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LowUsageLevel(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_NearMaxAcceptableUsageLevel(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_MaxAcceptableUsageLevel(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_ExcessiveUsageLevel(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_NearTerminationUsageLevel(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_TerminationUsageLevel(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_RecentEnergyUsage(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_RecentEnergyUsageLevel(uint32_t * value) = 0;
    virtual HRESULT __stdcall add_RecentEnergyUsageIncreased(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RecentEnergyUsageIncreased(event_token token) = 0;
    virtual HRESULT __stdcall add_RecentEnergyUsageReturnedToLow(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RecentEnergyUsageReturnedToLow(event_token token) = 0;
};

struct __declspec(uuid("9ff86872-e677-4814-9a20-5337ca732b98")) __declspec(novtable) IForegroundEnergyManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LowUsageLevel(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_NearMaxAcceptableUsageLevel(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_MaxAcceptableUsageLevel(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_ExcessiveUsageLevel(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_RecentEnergyUsage(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_RecentEnergyUsageLevel(uint32_t * value) = 0;
    virtual HRESULT __stdcall add_RecentEnergyUsageIncreased(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RecentEnergyUsageIncreased(event_token token) = 0;
    virtual HRESULT __stdcall add_RecentEnergyUsageReturnedToLow(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RecentEnergyUsageReturnedToLow(event_token token) = 0;
};

struct __declspec(uuid("1394825d-62ce-4364-98d5-aa28c7fbd15b")) __declspec(novtable) IPowerManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EnergySaverStatus(winrt::Windows::System::Power::EnergySaverStatus * value) = 0;
    virtual HRESULT __stdcall add_EnergySaverStatusChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_EnergySaverStatusChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_BatteryStatus(winrt::Windows::System::Power::BatteryStatus * value) = 0;
    virtual HRESULT __stdcall add_BatteryStatusChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BatteryStatusChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_PowerSupplyStatus(winrt::Windows::System::Power::PowerSupplyStatus * value) = 0;
    virtual HRESULT __stdcall add_PowerSupplyStatusChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PowerSupplyStatusChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_RemainingChargePercent(int32_t * value) = 0;
    virtual HRESULT __stdcall add_RemainingChargePercentChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RemainingChargePercentChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_RemainingDischargeTime(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall add_RemainingDischargeTimeChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RemainingDischargeTimeChanged(event_token token) = 0;
};

}

namespace ABI {


}

namespace Windows::System::Power {

template <typename D>
struct WINRT_EBO impl_IBackgroundEnergyManagerStatics
{
    uint32_t LowUsageLevel() const;
    uint32_t NearMaxAcceptableUsageLevel() const;
    uint32_t MaxAcceptableUsageLevel() const;
    uint32_t ExcessiveUsageLevel() const;
    uint32_t NearTerminationUsageLevel() const;
    uint32_t TerminationUsageLevel() const;
    uint32_t RecentEnergyUsage() const;
    uint32_t RecentEnergyUsageLevel() const;
    event_token RecentEnergyUsageIncreased(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    using RecentEnergyUsageIncreased_revoker = event_revoker<IBackgroundEnergyManagerStatics>;
    RecentEnergyUsageIncreased_revoker RecentEnergyUsageIncreased(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    void RecentEnergyUsageIncreased(event_token token) const;
    event_token RecentEnergyUsageReturnedToLow(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    using RecentEnergyUsageReturnedToLow_revoker = event_revoker<IBackgroundEnergyManagerStatics>;
    RecentEnergyUsageReturnedToLow_revoker RecentEnergyUsageReturnedToLow(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    void RecentEnergyUsageReturnedToLow(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IForegroundEnergyManagerStatics
{
    uint32_t LowUsageLevel() const;
    uint32_t NearMaxAcceptableUsageLevel() const;
    uint32_t MaxAcceptableUsageLevel() const;
    uint32_t ExcessiveUsageLevel() const;
    uint32_t RecentEnergyUsage() const;
    uint32_t RecentEnergyUsageLevel() const;
    event_token RecentEnergyUsageIncreased(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    using RecentEnergyUsageIncreased_revoker = event_revoker<IForegroundEnergyManagerStatics>;
    RecentEnergyUsageIncreased_revoker RecentEnergyUsageIncreased(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    void RecentEnergyUsageIncreased(event_token token) const;
    event_token RecentEnergyUsageReturnedToLow(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    using RecentEnergyUsageReturnedToLow_revoker = event_revoker<IForegroundEnergyManagerStatics>;
    RecentEnergyUsageReturnedToLow_revoker RecentEnergyUsageReturnedToLow(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    void RecentEnergyUsageReturnedToLow(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IPowerManagerStatics
{
    Windows::System::Power::EnergySaverStatus EnergySaverStatus() const;
    event_token EnergySaverStatusChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    using EnergySaverStatusChanged_revoker = event_revoker<IPowerManagerStatics>;
    EnergySaverStatusChanged_revoker EnergySaverStatusChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    void EnergySaverStatusChanged(event_token token) const;
    Windows::System::Power::BatteryStatus BatteryStatus() const;
    event_token BatteryStatusChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    using BatteryStatusChanged_revoker = event_revoker<IPowerManagerStatics>;
    BatteryStatusChanged_revoker BatteryStatusChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    void BatteryStatusChanged(event_token token) const;
    Windows::System::Power::PowerSupplyStatus PowerSupplyStatus() const;
    event_token PowerSupplyStatusChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    using PowerSupplyStatusChanged_revoker = event_revoker<IPowerManagerStatics>;
    PowerSupplyStatusChanged_revoker PowerSupplyStatusChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    void PowerSupplyStatusChanged(event_token token) const;
    int32_t RemainingChargePercent() const;
    event_token RemainingChargePercentChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    using RemainingChargePercentChanged_revoker = event_revoker<IPowerManagerStatics>;
    RemainingChargePercentChanged_revoker RemainingChargePercentChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    void RemainingChargePercentChanged(event_token token) const;
    Windows::Foundation::TimeSpan RemainingDischargeTime() const;
    event_token RemainingDischargeTimeChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    using RemainingDischargeTimeChanged_revoker = event_revoker<IPowerManagerStatics>;
    RemainingDischargeTimeChanged_revoker RemainingDischargeTimeChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    void RemainingDischargeTimeChanged(event_token token) const;
};

}

namespace impl {

template <> struct traits<Windows::System::Power::IBackgroundEnergyManagerStatics>
{
    using abi = ABI::Windows::System::Power::IBackgroundEnergyManagerStatics;
    template <typename D> using consume = Windows::System::Power::impl_IBackgroundEnergyManagerStatics<D>;
};

template <> struct traits<Windows::System::Power::IForegroundEnergyManagerStatics>
{
    using abi = ABI::Windows::System::Power::IForegroundEnergyManagerStatics;
    template <typename D> using consume = Windows::System::Power::impl_IForegroundEnergyManagerStatics<D>;
};

template <> struct traits<Windows::System::Power::IPowerManagerStatics>
{
    using abi = ABI::Windows::System::Power::IPowerManagerStatics;
    template <typename D> using consume = Windows::System::Power::impl_IPowerManagerStatics<D>;
};

template <> struct traits<Windows::System::Power::BackgroundEnergyManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Power.BackgroundEnergyManager"; }
};

template <> struct traits<Windows::System::Power::ForegroundEnergyManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Power.ForegroundEnergyManager"; }
};

template <> struct traits<Windows::System::Power::PowerManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Power.PowerManager"; }
};

}

}
