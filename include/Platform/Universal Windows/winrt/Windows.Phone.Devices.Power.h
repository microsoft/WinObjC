// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Phone.Devices.Power.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Phone::Devices::Power::IBattery> : produce_base<D, Windows::Phone::Devices::Power::IBattery>
{
    HRESULT __stdcall get_RemainingChargePercent(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemainingChargePercent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemainingDischargeTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemainingDischargeTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RemainingChargePercentChanged(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> changeHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RemainingChargePercentChanged(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&changeHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RemainingChargePercentChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemainingChargePercentChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::Devices::Power::IBatteryStatics> : produce_base<D, Windows::Phone::Devices::Power::IBatteryStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Phone::Devices::Power::IBattery> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDefault());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Phone::Devices::Power {

template <typename D> Windows::Phone::Devices::Power::Battery impl_IBatteryStatics<D>::GetDefault() const
{
    Windows::Phone::Devices::Power::Battery result { nullptr };
    check_hresult(WINRT_SHIM(IBatteryStatics)->abi_GetDefault(put_abi(result)));
    return result;
}

template <typename D> int32_t impl_IBattery<D>::RemainingChargePercent() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IBattery)->get_RemainingChargePercent(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IBattery<D>::RemainingDischargeTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IBattery)->get_RemainingDischargeTime(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IBattery<D>::RemainingChargePercentChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & changeHandler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IBattery)->add_RemainingChargePercentChanged(get_abi(changeHandler), &token));
    return token;
}

template <typename D> event_revoker<IBattery> impl_IBattery<D>::RemainingChargePercentChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & changeHandler) const
{
    return impl::make_event_revoker<D, IBattery>(this, &ABI::Windows::Phone::Devices::Power::IBattery::remove_RemainingChargePercentChanged, RemainingChargePercentChanged(changeHandler));
}

template <typename D> void impl_IBattery<D>::RemainingChargePercentChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IBattery)->remove_RemainingChargePercentChanged(token));
}

inline Windows::Phone::Devices::Power::Battery Battery::GetDefault()
{
    return get_activation_factory<Battery, IBatteryStatics>().GetDefault();
}

}

}
#pragma warning(pop)
