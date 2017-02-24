// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Devices.Sensors.Custom.3.h"
#include "Windows.Devices.Sensors.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Sensors::Custom::ICustomSensor> : produce_base<D, Windows::Devices::Sensors::Custom::ICustomSensor>
{
    HRESULT __stdcall abi_GetCurrentReading(impl::abi_arg_out<Windows::Devices::Sensors::Custom::ICustomSensorReading> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCurrentReading());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinimumReportInterval(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinimumReportInterval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ReportInterval(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportInterval(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReportInterval(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReportInterval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall add_ReadingChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Custom::CustomSensor, Windows::Devices::Sensors::Custom::CustomSensorReadingChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReadingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Custom::CustomSensor, Windows::Devices::Sensors::Custom::CustomSensorReadingChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ReadingChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReadingChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::Custom::ICustomSensorReading> : produce_base<D, Windows::Devices::Sensors::Custom::ICustomSensorReading>
{
    HRESULT __stdcall get_Timestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::Custom::ICustomSensorReadingChangedEventArgs> : produce_base<D, Windows::Devices::Sensors::Custom::ICustomSensorReadingChangedEventArgs>
{
    HRESULT __stdcall get_Reading(impl::abi_arg_out<Windows::Devices::Sensors::Custom::ICustomSensorReading> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Reading());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::Custom::ICustomSensorStatics> : produce_base<D, Windows::Devices::Sensors::Custom::ICustomSensorStatics>
{
    HRESULT __stdcall abi_GetDeviceSelector(GUID interfaceId, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDeviceSelector(interfaceId));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> sensorId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Custom::CustomSensor>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&sensorId)));
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

namespace Windows::Devices::Sensors::Custom {

template <typename D> hstring impl_ICustomSensorStatics<D>::GetDeviceSelector(GUID interfaceId) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICustomSensorStatics)->abi_GetDeviceSelector(interfaceId, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Custom::CustomSensor> impl_ICustomSensorStatics<D>::FromIdAsync(hstring_view sensorId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Custom::CustomSensor> result;
    check_hresult(WINRT_SHIM(ICustomSensorStatics)->abi_FromIdAsync(get_abi(sensorId), put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::Custom::CustomSensorReading impl_ICustomSensor<D>::GetCurrentReading() const
{
    Windows::Devices::Sensors::Custom::CustomSensorReading value { nullptr };
    check_hresult(WINRT_SHIM(ICustomSensor)->abi_GetCurrentReading(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_ICustomSensor<D>::MinimumReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICustomSensor)->get_MinimumReportInterval(&value));
    return value;
}

template <typename D> void impl_ICustomSensor<D>::ReportInterval(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ICustomSensor)->put_ReportInterval(value));
}

template <typename D> uint32_t impl_ICustomSensor<D>::ReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICustomSensor)->get_ReportInterval(&value));
    return value;
}

template <typename D> hstring impl_ICustomSensor<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICustomSensor)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ICustomSensor<D>::ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Custom::CustomSensor, Windows::Devices::Sensors::Custom::CustomSensorReadingChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICustomSensor)->add_ReadingChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICustomSensor> impl_ICustomSensor<D>::ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Custom::CustomSensor, Windows::Devices::Sensors::Custom::CustomSensorReadingChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICustomSensor>(this, &ABI::Windows::Devices::Sensors::Custom::ICustomSensor::remove_ReadingChanged, ReadingChanged(handler));
}

template <typename D> void impl_ICustomSensor<D>::ReadingChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(ICustomSensor)->remove_ReadingChanged(token));
}

template <typename D> Windows::Foundation::DateTime impl_ICustomSensorReading<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ICustomSensorReading)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_ICustomSensorReading<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(ICustomSensorReading)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::Custom::CustomSensorReading impl_ICustomSensorReadingChangedEventArgs<D>::Reading() const
{
    Windows::Devices::Sensors::Custom::CustomSensorReading value { nullptr };
    check_hresult(WINRT_SHIM(ICustomSensorReadingChangedEventArgs)->get_Reading(put_abi(value)));
    return value;
}

inline hstring CustomSensor::GetDeviceSelector(GUID interfaceId)
{
    return get_activation_factory<CustomSensor, ICustomSensorStatics>().GetDeviceSelector(interfaceId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Custom::CustomSensor> CustomSensor::FromIdAsync(hstring_view sensorId)
{
    return get_activation_factory<CustomSensor, ICustomSensorStatics>().FromIdAsync(sensorId);
}

}

}
#pragma warning(pop)
