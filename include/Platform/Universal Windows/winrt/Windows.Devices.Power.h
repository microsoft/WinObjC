// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.System.Power.3.h"
#include "internal/Windows.Devices.Power.3.h"
#include "Windows.Devices.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Power::IBattery> : produce_base<D, Windows::Devices::Power::IBattery>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetReport(impl::abi_arg_out<Windows::Devices::Power::IBatteryReport> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetReport());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ReportUpdated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Power::Battery, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReportUpdated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Power::Battery, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ReportUpdated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportUpdated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Power::IBatteryReport> : produce_base<D, Windows::Devices::Power::IBatteryReport>
{
    HRESULT __stdcall get_ChargeRateInMilliwatts(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChargeRateInMilliwatts());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesignCapacityInMilliwattHours(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesignCapacityInMilliwattHours());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FullChargeCapacityInMilliwattHours(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FullChargeCapacityInMilliwattHours());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemainingCapacityInMilliwattHours(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemainingCapacityInMilliwattHours());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::System::Power::BatteryStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Power::IBatteryStatics> : produce_base<D, Windows::Devices::Power::IBatteryStatics>
{
    HRESULT __stdcall get_AggregateBattery(impl::abi_arg_out<Windows::Devices::Power::IBattery> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().AggregateBattery());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Power::Battery>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDeviceSelector());
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

namespace Windows::Devices::Power {

template <typename D> hstring impl_IBattery<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBattery)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Power::BatteryReport impl_IBattery<D>::GetReport() const
{
    Windows::Devices::Power::BatteryReport result { nullptr };
    check_hresult(WINRT_SHIM(IBattery)->abi_GetReport(put_abi(result)));
    return result;
}

template <typename D> event_token impl_IBattery<D>::ReportUpdated(const Windows::Foundation::TypedEventHandler<Windows::Devices::Power::Battery, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IBattery)->add_ReportUpdated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IBattery> impl_IBattery<D>::ReportUpdated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Power::Battery, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IBattery>(this, &ABI::Windows::Devices::Power::IBattery::remove_ReportUpdated, ReportUpdated(handler));
}

template <typename D> void impl_IBattery<D>::ReportUpdated(event_token token) const
{
    check_hresult(WINRT_SHIM(IBattery)->remove_ReportUpdated(token));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IBatteryReport<D>::ChargeRateInMilliwatts() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IBatteryReport)->get_ChargeRateInMilliwatts(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IBatteryReport<D>::DesignCapacityInMilliwattHours() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IBatteryReport)->get_DesignCapacityInMilliwattHours(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IBatteryReport<D>::FullChargeCapacityInMilliwattHours() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IBatteryReport)->get_FullChargeCapacityInMilliwattHours(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IBatteryReport<D>::RemainingCapacityInMilliwattHours() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IBatteryReport)->get_RemainingCapacityInMilliwattHours(put_abi(value)));
    return value;
}

template <typename D> Windows::System::Power::BatteryStatus impl_IBatteryReport<D>::Status() const
{
    Windows::System::Power::BatteryStatus value {};
    check_hresult(WINRT_SHIM(IBatteryReport)->get_Status(&value));
    return value;
}

template <typename D> Windows::Devices::Power::Battery impl_IBatteryStatics<D>::AggregateBattery() const
{
    Windows::Devices::Power::Battery result { nullptr };
    check_hresult(WINRT_SHIM(IBatteryStatics)->get_AggregateBattery(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Power::Battery> impl_IBatteryStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Power::Battery> result;
    check_hresult(WINRT_SHIM(IBatteryStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IBatteryStatics<D>::GetDeviceSelector() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IBatteryStatics)->abi_GetDeviceSelector(put_abi(result)));
    return result;
}

inline Windows::Devices::Power::Battery Battery::AggregateBattery()
{
    return get_activation_factory<Battery, IBatteryStatics>().AggregateBattery();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Power::Battery> Battery::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<Battery, IBatteryStatics>().FromIdAsync(deviceId);
}

inline hstring Battery::GetDeviceSelector()
{
    return get_activation_factory<Battery, IBatteryStatics>().GetDeviceSelector();
}

}

}
#pragma warning(pop)
