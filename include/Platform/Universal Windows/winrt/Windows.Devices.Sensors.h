// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Graphics.Display.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Devices.Sensors.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Sensors::IAccelerometer> : produce_base<D, Windows::Devices::Sensors::IAccelerometer>
{
    HRESULT __stdcall abi_GetCurrentReading(impl::abi_arg_out<Windows::Devices::Sensors::IAccelerometerReading> value) noexcept override
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

    HRESULT __stdcall add_ReadingChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReadingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs> *>(&handler)));
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

    HRESULT __stdcall add_Shaken(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerShakenEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Shaken(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerShakenEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Shaken(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Shaken(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IAccelerometer2> : produce_base<D, Windows::Devices::Sensors::IAccelerometer2>
{
    HRESULT __stdcall put_ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReadingTransform(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReadingTransform(Windows::Graphics::Display::DisplayOrientations * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadingTransform());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IAccelerometer3> : produce_base<D, Windows::Devices::Sensors::IAccelerometer3>
{
    HRESULT __stdcall put_ReportLatency(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportLatency(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReportLatency(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReportLatency());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxBatchSize(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxBatchSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IAccelerometer4> : produce_base<D, Windows::Devices::Sensors::IAccelerometer4>
{
    HRESULT __stdcall get_ReadingType(Windows::Devices::Sensors::AccelerometerReadingType * type) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *type = detach_abi(this->shim().ReadingType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IAccelerometerDeviceId> : produce_base<D, Windows::Devices::Sensors::IAccelerometerDeviceId>
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
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IAccelerometerReading> : produce_base<D, Windows::Devices::Sensors::IAccelerometerReading>
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

    HRESULT __stdcall get_AccelerationX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccelerationX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccelerationY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccelerationY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccelerationZ(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccelerationZ());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IAccelerometerReadingChangedEventArgs> : produce_base<D, Windows::Devices::Sensors::IAccelerometerReadingChangedEventArgs>
{
    HRESULT __stdcall get_Reading(impl::abi_arg_out<Windows::Devices::Sensors::IAccelerometerReading> value) noexcept override
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
struct produce<D, Windows::Devices::Sensors::IAccelerometerShakenEventArgs> : produce_base<D, Windows::Devices::Sensors::IAccelerometerShakenEventArgs>
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
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IAccelerometerStatics> : produce_base<D, Windows::Devices::Sensors::IAccelerometerStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Devices::Sensors::IAccelerometer> result) noexcept override
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

template <typename D>
struct produce<D, Windows::Devices::Sensors::IAccelerometerStatics2> : produce_base<D, Windows::Devices::Sensors::IAccelerometerStatics2>
{
    HRESULT __stdcall abi_GetDefaultWithAccelerometerReadingType(Windows::Devices::Sensors::AccelerometerReadingType readingType, impl::abi_arg_out<Windows::Devices::Sensors::IAccelerometer> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDefault(readingType));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IActivitySensor> : produce_base<D, Windows::Devices::Sensors::IActivitySensor>
{
    HRESULT __stdcall abi_GetCurrentReadingAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensorReading>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetCurrentReadingAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SubscribedActivities(impl::abi_arg_out<Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sensors::ActivityType>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SubscribedActivities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PowerInMilliwatts(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PowerInMilliwatts());
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

    HRESULT __stdcall get_SupportedActivities(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::Sensors::ActivityType>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedActivities());
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

    HRESULT __stdcall add_ReadingChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::ActivitySensor, Windows::Devices::Sensors::ActivitySensorReadingChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReadingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::ActivitySensor, Windows::Devices::Sensors::ActivitySensorReadingChangedEventArgs> *>(&handler)));
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
struct produce<D, Windows::Devices::Sensors::IActivitySensorReading> : produce_base<D, Windows::Devices::Sensors::IActivitySensorReading>
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

    HRESULT __stdcall get_Activity(Windows::Devices::Sensors::ActivityType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Activity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Confidence(Windows::Devices::Sensors::ActivitySensorReadingConfidence * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Confidence());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IActivitySensorReadingChangeReport> : produce_base<D, Windows::Devices::Sensors::IActivitySensorReadingChangeReport>
{
    HRESULT __stdcall get_Reading(impl::abi_arg_out<Windows::Devices::Sensors::IActivitySensorReading> value) noexcept override
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
struct produce<D, Windows::Devices::Sensors::IActivitySensorReadingChangedEventArgs> : produce_base<D, Windows::Devices::Sensors::IActivitySensorReadingChangedEventArgs>
{
    HRESULT __stdcall get_Reading(impl::abi_arg_out<Windows::Devices::Sensors::IActivitySensorReading> value) noexcept override
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
struct produce<D, Windows::Devices::Sensors::IActivitySensorStatics> : produce_base<D, Windows::Devices::Sensors::IActivitySensorStatics>
{
    HRESULT __stdcall abi_GetDefaultAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensor>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDefaultAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensor>> result) noexcept override
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

    HRESULT __stdcall abi_GetSystemHistoryAsync(impl::abi_arg_in<Windows::Foundation::DateTime> fromTime, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReading>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetSystemHistoryAsync(*reinterpret_cast<const Windows::Foundation::DateTime *>(&fromTime)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSystemHistoryWithDurationAsync(impl::abi_arg_in<Windows::Foundation::DateTime> fromTime, impl::abi_arg_in<Windows::Foundation::TimeSpan> duration, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReading>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetSystemHistoryAsync(*reinterpret_cast<const Windows::Foundation::DateTime *>(&fromTime), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&duration)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IActivitySensorTriggerDetails> : produce_base<D, Windows::Devices::Sensors::IActivitySensorTriggerDetails>
{
    HRESULT __stdcall abi_ReadReports(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReadingChangeReport>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadReports());
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
struct produce<D, Windows::Devices::Sensors::IAltimeter> : produce_base<D, Windows::Devices::Sensors::IAltimeter>
{
    HRESULT __stdcall abi_GetCurrentReading(impl::abi_arg_out<Windows::Devices::Sensors::IAltimeterReading> value) noexcept override
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

    HRESULT __stdcall add_ReadingChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Altimeter, Windows::Devices::Sensors::AltimeterReadingChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReadingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Altimeter, Windows::Devices::Sensors::AltimeterReadingChangedEventArgs> *>(&handler)));
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
struct produce<D, Windows::Devices::Sensors::IAltimeterReading> : produce_base<D, Windows::Devices::Sensors::IAltimeterReading>
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

    HRESULT __stdcall get_AltitudeChangeInMeters(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AltitudeChangeInMeters());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IAltimeterReadingChangedEventArgs> : produce_base<D, Windows::Devices::Sensors::IAltimeterReadingChangedEventArgs>
{
    HRESULT __stdcall get_Reading(impl::abi_arg_out<Windows::Devices::Sensors::IAltimeterReading> value) noexcept override
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
struct produce<D, Windows::Devices::Sensors::IAltimeterStatics> : produce_base<D, Windows::Devices::Sensors::IAltimeterStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Devices::Sensors::IAltimeter> result) noexcept override
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

template <typename D>
struct produce<D, Windows::Devices::Sensors::IBarometer> : produce_base<D, Windows::Devices::Sensors::IBarometer>
{
    HRESULT __stdcall abi_GetCurrentReading(impl::abi_arg_out<Windows::Devices::Sensors::IBarometerReading> value) noexcept override
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

    HRESULT __stdcall add_ReadingChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Barometer, Windows::Devices::Sensors::BarometerReadingChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReadingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Barometer, Windows::Devices::Sensors::BarometerReadingChangedEventArgs> *>(&handler)));
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
struct produce<D, Windows::Devices::Sensors::IBarometerReading> : produce_base<D, Windows::Devices::Sensors::IBarometerReading>
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

    HRESULT __stdcall get_StationPressureInHectopascals(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StationPressureInHectopascals());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IBarometerReadingChangedEventArgs> : produce_base<D, Windows::Devices::Sensors::IBarometerReadingChangedEventArgs>
{
    HRESULT __stdcall get_Reading(impl::abi_arg_out<Windows::Devices::Sensors::IBarometerReading> value) noexcept override
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
struct produce<D, Windows::Devices::Sensors::IBarometerStatics> : produce_base<D, Windows::Devices::Sensors::IBarometerStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Devices::Sensors::IBarometer> result) noexcept override
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

template <typename D>
struct produce<D, Windows::Devices::Sensors::ICompass> : produce_base<D, Windows::Devices::Sensors::ICompass>
{
    HRESULT __stdcall abi_GetCurrentReading(impl::abi_arg_out<Windows::Devices::Sensors::ICompassReading> value) noexcept override
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

    HRESULT __stdcall add_ReadingChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Compass, Windows::Devices::Sensors::CompassReadingChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReadingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Compass, Windows::Devices::Sensors::CompassReadingChangedEventArgs> *>(&handler)));
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
struct produce<D, Windows::Devices::Sensors::ICompass2> : produce_base<D, Windows::Devices::Sensors::ICompass2>
{
    HRESULT __stdcall put_ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReadingTransform(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReadingTransform(Windows::Graphics::Display::DisplayOrientations * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadingTransform());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::ICompassDeviceId> : produce_base<D, Windows::Devices::Sensors::ICompassDeviceId>
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
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::ICompassReading> : produce_base<D, Windows::Devices::Sensors::ICompassReading>
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

    HRESULT __stdcall get_HeadingMagneticNorth(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HeadingMagneticNorth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeadingTrueNorth(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HeadingTrueNorth());
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
struct produce<D, Windows::Devices::Sensors::ICompassReadingChangedEventArgs> : produce_base<D, Windows::Devices::Sensors::ICompassReadingChangedEventArgs>
{
    HRESULT __stdcall get_Reading(impl::abi_arg_out<Windows::Devices::Sensors::ICompassReading> value) noexcept override
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
struct produce<D, Windows::Devices::Sensors::ICompassReadingHeadingAccuracy> : produce_base<D, Windows::Devices::Sensors::ICompassReadingHeadingAccuracy>
{
    HRESULT __stdcall get_HeadingAccuracy(Windows::Devices::Sensors::MagnetometerAccuracy * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HeadingAccuracy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::ICompassStatics> : produce_base<D, Windows::Devices::Sensors::ICompassStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Devices::Sensors::ICompass> result) noexcept override
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

template <typename D>
struct produce<D, Windows::Devices::Sensors::IGyrometer> : produce_base<D, Windows::Devices::Sensors::IGyrometer>
{
    HRESULT __stdcall abi_GetCurrentReading(impl::abi_arg_out<Windows::Devices::Sensors::IGyrometerReading> value) noexcept override
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

    HRESULT __stdcall add_ReadingChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Gyrometer, Windows::Devices::Sensors::GyrometerReadingChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReadingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Gyrometer, Windows::Devices::Sensors::GyrometerReadingChangedEventArgs> *>(&handler)));
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
struct produce<D, Windows::Devices::Sensors::IGyrometer2> : produce_base<D, Windows::Devices::Sensors::IGyrometer2>
{
    HRESULT __stdcall put_ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReadingTransform(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReadingTransform(Windows::Graphics::Display::DisplayOrientations * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadingTransform());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IGyrometerDeviceId> : produce_base<D, Windows::Devices::Sensors::IGyrometerDeviceId>
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
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IGyrometerReading> : produce_base<D, Windows::Devices::Sensors::IGyrometerReading>
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

    HRESULT __stdcall get_AngularVelocityX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AngularVelocityX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AngularVelocityY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AngularVelocityY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AngularVelocityZ(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AngularVelocityZ());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IGyrometerReadingChangedEventArgs> : produce_base<D, Windows::Devices::Sensors::IGyrometerReadingChangedEventArgs>
{
    HRESULT __stdcall get_Reading(impl::abi_arg_out<Windows::Devices::Sensors::IGyrometerReading> value) noexcept override
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
struct produce<D, Windows::Devices::Sensors::IGyrometerStatics> : produce_base<D, Windows::Devices::Sensors::IGyrometerStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Devices::Sensors::IGyrometer> result) noexcept override
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

template <typename D>
struct produce<D, Windows::Devices::Sensors::IInclinometer> : produce_base<D, Windows::Devices::Sensors::IInclinometer>
{
    HRESULT __stdcall abi_GetCurrentReading(impl::abi_arg_out<Windows::Devices::Sensors::IInclinometerReading> value) noexcept override
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

    HRESULT __stdcall add_ReadingChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Inclinometer, Windows::Devices::Sensors::InclinometerReadingChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReadingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Inclinometer, Windows::Devices::Sensors::InclinometerReadingChangedEventArgs> *>(&handler)));
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
struct produce<D, Windows::Devices::Sensors::IInclinometer2> : produce_base<D, Windows::Devices::Sensors::IInclinometer2>
{
    HRESULT __stdcall put_ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReadingTransform(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReadingTransform(Windows::Graphics::Display::DisplayOrientations * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadingTransform());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReadingType(Windows::Devices::Sensors::SensorReadingType * type) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *type = detach_abi(this->shim().ReadingType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IInclinometerDeviceId> : produce_base<D, Windows::Devices::Sensors::IInclinometerDeviceId>
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
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IInclinometerReading> : produce_base<D, Windows::Devices::Sensors::IInclinometerReading>
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

    HRESULT __stdcall get_PitchDegrees(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PitchDegrees());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RollDegrees(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RollDegrees());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_YawDegrees(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().YawDegrees());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IInclinometerReadingChangedEventArgs> : produce_base<D, Windows::Devices::Sensors::IInclinometerReadingChangedEventArgs>
{
    HRESULT __stdcall get_Reading(impl::abi_arg_out<Windows::Devices::Sensors::IInclinometerReading> value) noexcept override
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
struct produce<D, Windows::Devices::Sensors::IInclinometerReadingYawAccuracy> : produce_base<D, Windows::Devices::Sensors::IInclinometerReadingYawAccuracy>
{
    HRESULT __stdcall get_YawAccuracy(Windows::Devices::Sensors::MagnetometerAccuracy * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().YawAccuracy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IInclinometerStatics> : produce_base<D, Windows::Devices::Sensors::IInclinometerStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Devices::Sensors::IInclinometer> result) noexcept override
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

template <typename D>
struct produce<D, Windows::Devices::Sensors::IInclinometerStatics2> : produce_base<D, Windows::Devices::Sensors::IInclinometerStatics2>
{
    HRESULT __stdcall abi_GetDefaultForRelativeReadings(impl::abi_arg_out<Windows::Devices::Sensors::IInclinometer> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDefaultForRelativeReadings());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IInclinometerStatics3> : produce_base<D, Windows::Devices::Sensors::IInclinometerStatics3>
{
    HRESULT __stdcall abi_GetDefaultWithSensorReadingType(Windows::Devices::Sensors::SensorReadingType sensorReadingtype, impl::abi_arg_out<Windows::Devices::Sensors::IInclinometer> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDefault(sensorReadingtype));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::ILightSensor> : produce_base<D, Windows::Devices::Sensors::ILightSensor>
{
    HRESULT __stdcall abi_GetCurrentReading(impl::abi_arg_out<Windows::Devices::Sensors::ILightSensorReading> value) noexcept override
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

    HRESULT __stdcall add_ReadingChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::LightSensor, Windows::Devices::Sensors::LightSensorReadingChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReadingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::LightSensor, Windows::Devices::Sensors::LightSensorReadingChangedEventArgs> *>(&handler)));
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
struct produce<D, Windows::Devices::Sensors::ILightSensorDeviceId> : produce_base<D, Windows::Devices::Sensors::ILightSensorDeviceId>
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
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::ILightSensorReading> : produce_base<D, Windows::Devices::Sensors::ILightSensorReading>
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

    HRESULT __stdcall get_IlluminanceInLux(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IlluminanceInLux());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::ILightSensorReadingChangedEventArgs> : produce_base<D, Windows::Devices::Sensors::ILightSensorReadingChangedEventArgs>
{
    HRESULT __stdcall get_Reading(impl::abi_arg_out<Windows::Devices::Sensors::ILightSensorReading> value) noexcept override
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
struct produce<D, Windows::Devices::Sensors::ILightSensorStatics> : produce_base<D, Windows::Devices::Sensors::ILightSensorStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Devices::Sensors::ILightSensor> result) noexcept override
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

template <typename D>
struct produce<D, Windows::Devices::Sensors::IMagnetometer> : produce_base<D, Windows::Devices::Sensors::IMagnetometer>
{
    HRESULT __stdcall abi_GetCurrentReading(impl::abi_arg_out<Windows::Devices::Sensors::IMagnetometerReading> value) noexcept override
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

    HRESULT __stdcall add_ReadingChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Magnetometer, Windows::Devices::Sensors::MagnetometerReadingChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReadingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Magnetometer, Windows::Devices::Sensors::MagnetometerReadingChangedEventArgs> *>(&handler)));
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
struct produce<D, Windows::Devices::Sensors::IMagnetometer2> : produce_base<D, Windows::Devices::Sensors::IMagnetometer2>
{
    HRESULT __stdcall put_ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReadingTransform(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReadingTransform(Windows::Graphics::Display::DisplayOrientations * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadingTransform());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IMagnetometerDeviceId> : produce_base<D, Windows::Devices::Sensors::IMagnetometerDeviceId>
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
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IMagnetometerReading> : produce_base<D, Windows::Devices::Sensors::IMagnetometerReading>
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

    HRESULT __stdcall get_MagneticFieldX(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MagneticFieldX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MagneticFieldY(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MagneticFieldY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MagneticFieldZ(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MagneticFieldZ());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DirectionalAccuracy(Windows::Devices::Sensors::MagnetometerAccuracy * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DirectionalAccuracy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IMagnetometerReadingChangedEventArgs> : produce_base<D, Windows::Devices::Sensors::IMagnetometerReadingChangedEventArgs>
{
    HRESULT __stdcall get_Reading(impl::abi_arg_out<Windows::Devices::Sensors::IMagnetometerReading> value) noexcept override
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
struct produce<D, Windows::Devices::Sensors::IMagnetometerStatics> : produce_base<D, Windows::Devices::Sensors::IMagnetometerStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Devices::Sensors::IMagnetometer> result) noexcept override
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

template <typename D>
struct produce<D, Windows::Devices::Sensors::IOrientationSensor> : produce_base<D, Windows::Devices::Sensors::IOrientationSensor>
{
    HRESULT __stdcall abi_GetCurrentReading(impl::abi_arg_out<Windows::Devices::Sensors::IOrientationSensorReading> value) noexcept override
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

    HRESULT __stdcall add_ReadingChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::OrientationSensor, Windows::Devices::Sensors::OrientationSensorReadingChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReadingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::OrientationSensor, Windows::Devices::Sensors::OrientationSensorReadingChangedEventArgs> *>(&handler)));
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
struct produce<D, Windows::Devices::Sensors::IOrientationSensor2> : produce_base<D, Windows::Devices::Sensors::IOrientationSensor2>
{
    HRESULT __stdcall put_ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReadingTransform(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReadingTransform(Windows::Graphics::Display::DisplayOrientations * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadingTransform());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReadingType(Windows::Devices::Sensors::SensorReadingType * type) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *type = detach_abi(this->shim().ReadingType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IOrientationSensorDeviceId> : produce_base<D, Windows::Devices::Sensors::IOrientationSensorDeviceId>
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
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IOrientationSensorReading> : produce_base<D, Windows::Devices::Sensors::IOrientationSensorReading>
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

    HRESULT __stdcall get_RotationMatrix(impl::abi_arg_out<Windows::Devices::Sensors::ISensorRotationMatrix> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationMatrix());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Quaternion(impl::abi_arg_out<Windows::Devices::Sensors::ISensorQuaternion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Quaternion());
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
struct produce<D, Windows::Devices::Sensors::IOrientationSensorReadingChangedEventArgs> : produce_base<D, Windows::Devices::Sensors::IOrientationSensorReadingChangedEventArgs>
{
    HRESULT __stdcall get_Reading(impl::abi_arg_out<Windows::Devices::Sensors::IOrientationSensorReading> value) noexcept override
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
struct produce<D, Windows::Devices::Sensors::IOrientationSensorReadingYawAccuracy> : produce_base<D, Windows::Devices::Sensors::IOrientationSensorReadingYawAccuracy>
{
    HRESULT __stdcall get_YawAccuracy(Windows::Devices::Sensors::MagnetometerAccuracy * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().YawAccuracy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IOrientationSensorStatics> : produce_base<D, Windows::Devices::Sensors::IOrientationSensorStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Devices::Sensors::IOrientationSensor> result) noexcept override
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

template <typename D>
struct produce<D, Windows::Devices::Sensors::IOrientationSensorStatics2> : produce_base<D, Windows::Devices::Sensors::IOrientationSensorStatics2>
{
    HRESULT __stdcall abi_GetDefaultForRelativeReadings(impl::abi_arg_out<Windows::Devices::Sensors::IOrientationSensor> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDefaultForRelativeReadings());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IOrientationSensorStatics3> : produce_base<D, Windows::Devices::Sensors::IOrientationSensorStatics3>
{
    HRESULT __stdcall abi_GetDefaultWithSensorReadingType(Windows::Devices::Sensors::SensorReadingType sensorReadingtype, impl::abi_arg_out<Windows::Devices::Sensors::IOrientationSensor> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDefault(sensorReadingtype));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDefaultWithSensorReadingTypeAndSensorOptimizationGoal(Windows::Devices::Sensors::SensorReadingType sensorReadingType, Windows::Devices::Sensors::SensorOptimizationGoal optimizationGoal, impl::abi_arg_out<Windows::Devices::Sensors::IOrientationSensor> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDefault(sensorReadingType, optimizationGoal));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IPedometer> : produce_base<D, Windows::Devices::Sensors::IPedometer>
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

    HRESULT __stdcall get_PowerInMilliwatts(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PowerInMilliwatts());
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall add_ReadingChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Pedometer, Windows::Devices::Sensors::PedometerReadingChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReadingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Pedometer, Windows::Devices::Sensors::PedometerReadingChangedEventArgs> *>(&handler)));
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
struct produce<D, Windows::Devices::Sensors::IPedometer2> : produce_base<D, Windows::Devices::Sensors::IPedometer2>
{
    HRESULT __stdcall abi_GetCurrentReadings(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<winrt::Windows::Devices::Sensors::PedometerStepKind, Windows::Devices::Sensors::PedometerReading>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCurrentReadings());
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
struct produce<D, Windows::Devices::Sensors::IPedometerDataThresholdFactory> : produce_base<D, Windows::Devices::Sensors::IPedometerDataThresholdFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Devices::Sensors::IPedometer> sensor, int32_t stepGoal, impl::abi_arg_out<Windows::Devices::Sensors::ISensorDataThreshold> threshold) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *threshold = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Devices::Sensors::Pedometer *>(&sensor), stepGoal));
            return S_OK;
        }
        catch (...)
        {
            *threshold = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IPedometerReading> : produce_base<D, Windows::Devices::Sensors::IPedometerReading>
{
    HRESULT __stdcall get_StepKind(Windows::Devices::Sensors::PedometerStepKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StepKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CumulativeSteps(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CumulativeSteps());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_CumulativeStepsDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CumulativeStepsDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IPedometerReadingChangedEventArgs> : produce_base<D, Windows::Devices::Sensors::IPedometerReadingChangedEventArgs>
{
    HRESULT __stdcall get_Reading(impl::abi_arg_out<Windows::Devices::Sensors::IPedometerReading> value) noexcept override
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
struct produce<D, Windows::Devices::Sensors::IPedometerStatics> : produce_base<D, Windows::Devices::Sensors::IPedometerStatics>
{
    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Pedometer>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDefaultAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Pedometer>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetDefaultAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
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

    HRESULT __stdcall abi_GetSystemHistoryAsync(impl::abi_arg_in<Windows::Foundation::DateTime> fromTime, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetSystemHistoryAsync(*reinterpret_cast<const Windows::Foundation::DateTime *>(&fromTime)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSystemHistoryWithDurationAsync(impl::abi_arg_in<Windows::Foundation::DateTime> fromTime, impl::abi_arg_in<Windows::Foundation::TimeSpan> duration, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetSystemHistoryAsync(*reinterpret_cast<const Windows::Foundation::DateTime *>(&fromTime), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&duration)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IPedometerStatics2> : produce_base<D, Windows::Devices::Sensors::IPedometerStatics2>
{
    HRESULT __stdcall abi_GetReadingsFromTriggerDetails(impl::abi_arg_in<Windows::Devices::Sensors::ISensorDataThresholdTriggerDetails> triggerDetails, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetReadingsFromTriggerDetails(*reinterpret_cast<const Windows::Devices::Sensors::SensorDataThresholdTriggerDetails *>(&triggerDetails)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IProximitySensor> : produce_base<D, Windows::Devices::Sensors::IProximitySensor>
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

    HRESULT __stdcall get_MaxDistanceInMillimeters(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxDistanceInMillimeters());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinDistanceInMillimeters(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinDistanceInMillimeters());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentReading(impl::abi_arg_out<Windows::Devices::Sensors::IProximitySensorReading> value) noexcept override
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

    HRESULT __stdcall add_ReadingChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::ProximitySensor, Windows::Devices::Sensors::ProximitySensorReadingChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReadingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::ProximitySensor, Windows::Devices::Sensors::ProximitySensorReadingChangedEventArgs> *>(&handler)));
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

    HRESULT __stdcall abi_CreateDisplayOnOffController(impl::abi_arg_out<Windows::Foundation::IClosable> controller) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *controller = detach_abi(this->shim().CreateDisplayOnOffController());
            return S_OK;
        }
        catch (...)
        {
            *controller = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IProximitySensorDataThresholdFactory> : produce_base<D, Windows::Devices::Sensors::IProximitySensorDataThresholdFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Devices::Sensors::IProximitySensor> sensor, impl::abi_arg_out<Windows::Devices::Sensors::ISensorDataThreshold> threshold) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *threshold = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Devices::Sensors::ProximitySensor *>(&sensor)));
            return S_OK;
        }
        catch (...)
        {
            *threshold = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IProximitySensorReading> : produce_base<D, Windows::Devices::Sensors::IProximitySensorReading>
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

    HRESULT __stdcall get_IsDetected(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDetected());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DistanceInMillimeters(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DistanceInMillimeters());
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
struct produce<D, Windows::Devices::Sensors::IProximitySensorReadingChangedEventArgs> : produce_base<D, Windows::Devices::Sensors::IProximitySensorReadingChangedEventArgs>
{
    HRESULT __stdcall get_Reading(impl::abi_arg_out<Windows::Devices::Sensors::IProximitySensorReading> value) noexcept override
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
struct produce<D, Windows::Devices::Sensors::IProximitySensorStatics> : produce_base<D, Windows::Devices::Sensors::IProximitySensorStatics>
{
    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromId(impl::abi_arg_in<hstring> sensorId, impl::abi_arg_out<Windows::Devices::Sensors::IProximitySensor> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FromId(*reinterpret_cast<const hstring *>(&sensorId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::IProximitySensorStatics2> : produce_base<D, Windows::Devices::Sensors::IProximitySensorStatics2>
{
    HRESULT __stdcall abi_GetReadingsFromTriggerDetails(impl::abi_arg_in<Windows::Devices::Sensors::ISensorDataThresholdTriggerDetails> triggerDetails, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ProximitySensorReading>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetReadingsFromTriggerDetails(*reinterpret_cast<const Windows::Devices::Sensors::SensorDataThresholdTriggerDetails *>(&triggerDetails)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::ISensorDataThreshold> : produce_base<D, Windows::Devices::Sensors::ISensorDataThreshold>
{};

template <typename D>
struct produce<D, Windows::Devices::Sensors::ISensorDataThresholdTriggerDetails> : produce_base<D, Windows::Devices::Sensors::ISensorDataThresholdTriggerDetails>
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

    HRESULT __stdcall get_SensorType(Windows::Devices::Sensors::SensorType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SensorType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::ISensorQuaternion> : produce_base<D, Windows::Devices::Sensors::ISensorQuaternion>
{
    HRESULT __stdcall get_W(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().W());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_X(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().X());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Y(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Y());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Z(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Z());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::ISensorRotationMatrix> : produce_base<D, Windows::Devices::Sensors::ISensorRotationMatrix>
{
    HRESULT __stdcall get_M11(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().M11());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_M12(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().M12());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_M13(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().M13());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_M21(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().M21());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_M22(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().M22());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_M23(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().M23());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_M31(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().M31());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_M32(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().M32());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_M33(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().M33());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::ISimpleOrientationSensor> : produce_base<D, Windows::Devices::Sensors::ISimpleOrientationSensor>
{
    HRESULT __stdcall abi_GetCurrentOrientation(Windows::Devices::Sensors::SimpleOrientation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCurrentOrientation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_OrientationChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::SimpleOrientationSensor, Windows::Devices::Sensors::SimpleOrientationSensorOrientationChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().OrientationChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::SimpleOrientationSensor, Windows::Devices::Sensors::SimpleOrientationSensorOrientationChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_OrientationChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OrientationChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::ISimpleOrientationSensor2> : produce_base<D, Windows::Devices::Sensors::ISimpleOrientationSensor2>
{
    HRESULT __stdcall put_ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReadingTransform(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReadingTransform(Windows::Graphics::Display::DisplayOrientations * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadingTransform());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::ISimpleOrientationSensorDeviceId> : produce_base<D, Windows::Devices::Sensors::ISimpleOrientationSensorDeviceId>
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
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::ISimpleOrientationSensorOrientationChangedEventArgs> : produce_base<D, Windows::Devices::Sensors::ISimpleOrientationSensorOrientationChangedEventArgs>
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

    HRESULT __stdcall get_Orientation(Windows::Devices::Sensors::SimpleOrientation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Orientation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sensors::ISimpleOrientationSensorStatics> : produce_base<D, Windows::Devices::Sensors::ISimpleOrientationSensorStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Devices::Sensors::ISimpleOrientationSensor> result) noexcept override
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

namespace Windows::Devices::Sensors {

template <typename D> hstring impl_ISensorDataThresholdTriggerDetails<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISensorDataThresholdTriggerDetails)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::SensorType impl_ISensorDataThresholdTriggerDetails<D>::SensorType() const
{
    Windows::Devices::Sensors::SensorType value {};
    check_hresult(WINRT_SHIM(ISensorDataThresholdTriggerDetails)->get_SensorType(&value));
    return value;
}

template <typename D> hstring impl_IAccelerometerDeviceId<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAccelerometerDeviceId)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::Accelerometer impl_IAccelerometerStatics<D>::GetDefault() const
{
    Windows::Devices::Sensors::Accelerometer result { nullptr };
    check_hresult(WINRT_SHIM(IAccelerometerStatics)->abi_GetDefault(put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::Accelerometer impl_IAccelerometerStatics2<D>::GetDefault(Windows::Devices::Sensors::AccelerometerReadingType readingType) const
{
    Windows::Devices::Sensors::Accelerometer result { nullptr };
    check_hresult(WINRT_SHIM(IAccelerometerStatics2)->abi_GetDefaultWithAccelerometerReadingType(readingType, put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::AccelerometerReading impl_IAccelerometer<D>::GetCurrentReading() const
{
    Windows::Devices::Sensors::AccelerometerReading value { nullptr };
    check_hresult(WINRT_SHIM(IAccelerometer)->abi_GetCurrentReading(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IAccelerometer<D>::MinimumReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IAccelerometer)->get_MinimumReportInterval(&value));
    return value;
}

template <typename D> void impl_IAccelerometer<D>::ReportInterval(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IAccelerometer)->put_ReportInterval(value));
}

template <typename D> uint32_t impl_IAccelerometer<D>::ReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IAccelerometer)->get_ReportInterval(&value));
    return value;
}

template <typename D> event_token impl_IAccelerometer<D>::ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAccelerometer)->add_ReadingChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAccelerometer> impl_IAccelerometer<D>::ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IAccelerometer>(this, &ABI::Windows::Devices::Sensors::IAccelerometer::remove_ReadingChanged, ReadingChanged(handler));
}

template <typename D> void impl_IAccelerometer<D>::ReadingChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IAccelerometer)->remove_ReadingChanged(token));
}

template <typename D> event_token impl_IAccelerometer<D>::Shaken(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerShakenEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAccelerometer)->add_Shaken(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAccelerometer> impl_IAccelerometer<D>::Shaken(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerShakenEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IAccelerometer>(this, &ABI::Windows::Devices::Sensors::IAccelerometer::remove_Shaken, Shaken(handler));
}

template <typename D> void impl_IAccelerometer<D>::Shaken(event_token token) const
{
    check_hresult(WINRT_SHIM(IAccelerometer)->remove_Shaken(token));
}

template <typename D> void impl_IAccelerometer2<D>::ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) const
{
    check_hresult(WINRT_SHIM(IAccelerometer2)->put_ReadingTransform(value));
}

template <typename D> Windows::Graphics::Display::DisplayOrientations impl_IAccelerometer2<D>::ReadingTransform() const
{
    Windows::Graphics::Display::DisplayOrientations value {};
    check_hresult(WINRT_SHIM(IAccelerometer2)->get_ReadingTransform(&value));
    return value;
}

template <typename D> void impl_IAccelerometer3<D>::ReportLatency(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IAccelerometer3)->put_ReportLatency(value));
}

template <typename D> uint32_t impl_IAccelerometer3<D>::ReportLatency() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IAccelerometer3)->get_ReportLatency(&value));
    return value;
}

template <typename D> uint32_t impl_IAccelerometer3<D>::MaxBatchSize() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IAccelerometer3)->get_MaxBatchSize(&value));
    return value;
}

template <typename D> Windows::Devices::Sensors::AccelerometerReadingType impl_IAccelerometer4<D>::ReadingType() const
{
    Windows::Devices::Sensors::AccelerometerReadingType type {};
    check_hresult(WINRT_SHIM(IAccelerometer4)->get_ReadingType(&type));
    return type;
}

template <typename D> Windows::Foundation::DateTime impl_IAccelerometerReading<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IAccelerometerReading)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> double impl_IAccelerometerReading<D>::AccelerationX() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAccelerometerReading)->get_AccelerationX(&value));
    return value;
}

template <typename D> double impl_IAccelerometerReading<D>::AccelerationY() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAccelerometerReading)->get_AccelerationY(&value));
    return value;
}

template <typename D> double impl_IAccelerometerReading<D>::AccelerationZ() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAccelerometerReading)->get_AccelerationZ(&value));
    return value;
}

template <typename D> Windows::Devices::Sensors::AccelerometerReading impl_IAccelerometerReadingChangedEventArgs<D>::Reading() const
{
    Windows::Devices::Sensors::AccelerometerReading value { nullptr };
    check_hresult(WINRT_SHIM(IAccelerometerReadingChangedEventArgs)->get_Reading(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IAccelerometerShakenEventArgs<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IAccelerometerShakenEventArgs)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IInclinometerDeviceId<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IInclinometerDeviceId)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::Inclinometer impl_IInclinometerStatics<D>::GetDefault() const
{
    Windows::Devices::Sensors::Inclinometer result { nullptr };
    check_hresult(WINRT_SHIM(IInclinometerStatics)->abi_GetDefault(put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::Inclinometer impl_IInclinometerStatics2<D>::GetDefaultForRelativeReadings() const
{
    Windows::Devices::Sensors::Inclinometer result { nullptr };
    check_hresult(WINRT_SHIM(IInclinometerStatics2)->abi_GetDefaultForRelativeReadings(put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::Inclinometer impl_IInclinometerStatics3<D>::GetDefault(Windows::Devices::Sensors::SensorReadingType sensorReadingtype) const
{
    Windows::Devices::Sensors::Inclinometer result { nullptr };
    check_hresult(WINRT_SHIM(IInclinometerStatics3)->abi_GetDefaultWithSensorReadingType(sensorReadingtype, put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::InclinometerReading impl_IInclinometer<D>::GetCurrentReading() const
{
    Windows::Devices::Sensors::InclinometerReading value { nullptr };
    check_hresult(WINRT_SHIM(IInclinometer)->abi_GetCurrentReading(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IInclinometer<D>::MinimumReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IInclinometer)->get_MinimumReportInterval(&value));
    return value;
}

template <typename D> void impl_IInclinometer<D>::ReportInterval(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IInclinometer)->put_ReportInterval(value));
}

template <typename D> uint32_t impl_IInclinometer<D>::ReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IInclinometer)->get_ReportInterval(&value));
    return value;
}

template <typename D> event_token impl_IInclinometer<D>::ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Inclinometer, Windows::Devices::Sensors::InclinometerReadingChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IInclinometer)->add_ReadingChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IInclinometer> impl_IInclinometer<D>::ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Inclinometer, Windows::Devices::Sensors::InclinometerReadingChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IInclinometer>(this, &ABI::Windows::Devices::Sensors::IInclinometer::remove_ReadingChanged, ReadingChanged(handler));
}

template <typename D> void impl_IInclinometer<D>::ReadingChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IInclinometer)->remove_ReadingChanged(token));
}

template <typename D> void impl_IInclinometer2<D>::ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) const
{
    check_hresult(WINRT_SHIM(IInclinometer2)->put_ReadingTransform(value));
}

template <typename D> Windows::Graphics::Display::DisplayOrientations impl_IInclinometer2<D>::ReadingTransform() const
{
    Windows::Graphics::Display::DisplayOrientations value {};
    check_hresult(WINRT_SHIM(IInclinometer2)->get_ReadingTransform(&value));
    return value;
}

template <typename D> Windows::Devices::Sensors::SensorReadingType impl_IInclinometer2<D>::ReadingType() const
{
    Windows::Devices::Sensors::SensorReadingType type {};
    check_hresult(WINRT_SHIM(IInclinometer2)->get_ReadingType(&type));
    return type;
}

template <typename D> Windows::Foundation::DateTime impl_IInclinometerReading<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IInclinometerReading)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> float impl_IInclinometerReading<D>::PitchDegrees() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInclinometerReading)->get_PitchDegrees(&value));
    return value;
}

template <typename D> float impl_IInclinometerReading<D>::RollDegrees() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInclinometerReading)->get_RollDegrees(&value));
    return value;
}

template <typename D> float impl_IInclinometerReading<D>::YawDegrees() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInclinometerReading)->get_YawDegrees(&value));
    return value;
}

template <typename D> Windows::Devices::Sensors::MagnetometerAccuracy impl_IInclinometerReadingYawAccuracy<D>::YawAccuracy() const
{
    Windows::Devices::Sensors::MagnetometerAccuracy value {};
    check_hresult(WINRT_SHIM(IInclinometerReadingYawAccuracy)->get_YawAccuracy(&value));
    return value;
}

template <typename D> Windows::Devices::Sensors::InclinometerReading impl_IInclinometerReadingChangedEventArgs<D>::Reading() const
{
    Windows::Devices::Sensors::InclinometerReading value { nullptr };
    check_hresult(WINRT_SHIM(IInclinometerReadingChangedEventArgs)->get_Reading(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGyrometerDeviceId<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGyrometerDeviceId)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::Gyrometer impl_IGyrometerStatics<D>::GetDefault() const
{
    Windows::Devices::Sensors::Gyrometer result { nullptr };
    check_hresult(WINRT_SHIM(IGyrometerStatics)->abi_GetDefault(put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::GyrometerReading impl_IGyrometer<D>::GetCurrentReading() const
{
    Windows::Devices::Sensors::GyrometerReading value { nullptr };
    check_hresult(WINRT_SHIM(IGyrometer)->abi_GetCurrentReading(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IGyrometer<D>::MinimumReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IGyrometer)->get_MinimumReportInterval(&value));
    return value;
}

template <typename D> void impl_IGyrometer<D>::ReportInterval(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IGyrometer)->put_ReportInterval(value));
}

template <typename D> uint32_t impl_IGyrometer<D>::ReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IGyrometer)->get_ReportInterval(&value));
    return value;
}

template <typename D> event_token impl_IGyrometer<D>::ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Gyrometer, Windows::Devices::Sensors::GyrometerReadingChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGyrometer)->add_ReadingChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IGyrometer> impl_IGyrometer<D>::ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Gyrometer, Windows::Devices::Sensors::GyrometerReadingChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IGyrometer>(this, &ABI::Windows::Devices::Sensors::IGyrometer::remove_ReadingChanged, ReadingChanged(handler));
}

template <typename D> void impl_IGyrometer<D>::ReadingChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IGyrometer)->remove_ReadingChanged(token));
}

template <typename D> void impl_IGyrometer2<D>::ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) const
{
    check_hresult(WINRT_SHIM(IGyrometer2)->put_ReadingTransform(value));
}

template <typename D> Windows::Graphics::Display::DisplayOrientations impl_IGyrometer2<D>::ReadingTransform() const
{
    Windows::Graphics::Display::DisplayOrientations value {};
    check_hresult(WINRT_SHIM(IGyrometer2)->get_ReadingTransform(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IGyrometerReading<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IGyrometerReading)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> double impl_IGyrometerReading<D>::AngularVelocityX() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGyrometerReading)->get_AngularVelocityX(&value));
    return value;
}

template <typename D> double impl_IGyrometerReading<D>::AngularVelocityY() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGyrometerReading)->get_AngularVelocityY(&value));
    return value;
}

template <typename D> double impl_IGyrometerReading<D>::AngularVelocityZ() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGyrometerReading)->get_AngularVelocityZ(&value));
    return value;
}

template <typename D> Windows::Devices::Sensors::GyrometerReading impl_IGyrometerReadingChangedEventArgs<D>::Reading() const
{
    Windows::Devices::Sensors::GyrometerReading value { nullptr };
    check_hresult(WINRT_SHIM(IGyrometerReadingChangedEventArgs)->get_Reading(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICompassDeviceId<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICompassDeviceId)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::Compass impl_ICompassStatics<D>::GetDefault() const
{
    Windows::Devices::Sensors::Compass result { nullptr };
    check_hresult(WINRT_SHIM(ICompassStatics)->abi_GetDefault(put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::CompassReading impl_ICompass<D>::GetCurrentReading() const
{
    Windows::Devices::Sensors::CompassReading value { nullptr };
    check_hresult(WINRT_SHIM(ICompass)->abi_GetCurrentReading(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_ICompass<D>::MinimumReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICompass)->get_MinimumReportInterval(&value));
    return value;
}

template <typename D> void impl_ICompass<D>::ReportInterval(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ICompass)->put_ReportInterval(value));
}

template <typename D> uint32_t impl_ICompass<D>::ReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICompass)->get_ReportInterval(&value));
    return value;
}

template <typename D> event_token impl_ICompass<D>::ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Compass, Windows::Devices::Sensors::CompassReadingChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICompass)->add_ReadingChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICompass> impl_ICompass<D>::ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Compass, Windows::Devices::Sensors::CompassReadingChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICompass>(this, &ABI::Windows::Devices::Sensors::ICompass::remove_ReadingChanged, ReadingChanged(handler));
}

template <typename D> void impl_ICompass<D>::ReadingChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(ICompass)->remove_ReadingChanged(token));
}

template <typename D> void impl_ICompass2<D>::ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) const
{
    check_hresult(WINRT_SHIM(ICompass2)->put_ReadingTransform(value));
}

template <typename D> Windows::Graphics::Display::DisplayOrientations impl_ICompass2<D>::ReadingTransform() const
{
    Windows::Graphics::Display::DisplayOrientations value {};
    check_hresult(WINRT_SHIM(ICompass2)->get_ReadingTransform(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ICompassReading<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ICompassReading)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> double impl_ICompassReading<D>::HeadingMagneticNorth() const
{
    double value {};
    check_hresult(WINRT_SHIM(ICompassReading)->get_HeadingMagneticNorth(&value));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_ICompassReading<D>::HeadingTrueNorth() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(ICompassReading)->get_HeadingTrueNorth(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::MagnetometerAccuracy impl_ICompassReadingHeadingAccuracy<D>::HeadingAccuracy() const
{
    Windows::Devices::Sensors::MagnetometerAccuracy value {};
    check_hresult(WINRT_SHIM(ICompassReadingHeadingAccuracy)->get_HeadingAccuracy(&value));
    return value;
}

template <typename D> Windows::Devices::Sensors::CompassReading impl_ICompassReadingChangedEventArgs<D>::Reading() const
{
    Windows::Devices::Sensors::CompassReading value { nullptr };
    check_hresult(WINRT_SHIM(ICompassReadingChangedEventArgs)->get_Reading(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILightSensorDeviceId<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILightSensorDeviceId)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::LightSensor impl_ILightSensorStatics<D>::GetDefault() const
{
    Windows::Devices::Sensors::LightSensor result { nullptr };
    check_hresult(WINRT_SHIM(ILightSensorStatics)->abi_GetDefault(put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::LightSensorReading impl_ILightSensor<D>::GetCurrentReading() const
{
    Windows::Devices::Sensors::LightSensorReading value { nullptr };
    check_hresult(WINRT_SHIM(ILightSensor)->abi_GetCurrentReading(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_ILightSensor<D>::MinimumReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ILightSensor)->get_MinimumReportInterval(&value));
    return value;
}

template <typename D> void impl_ILightSensor<D>::ReportInterval(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ILightSensor)->put_ReportInterval(value));
}

template <typename D> uint32_t impl_ILightSensor<D>::ReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ILightSensor)->get_ReportInterval(&value));
    return value;
}

template <typename D> event_token impl_ILightSensor<D>::ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::LightSensor, Windows::Devices::Sensors::LightSensorReadingChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ILightSensor)->add_ReadingChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ILightSensor> impl_ILightSensor<D>::ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::LightSensor, Windows::Devices::Sensors::LightSensorReadingChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ILightSensor>(this, &ABI::Windows::Devices::Sensors::ILightSensor::remove_ReadingChanged, ReadingChanged(handler));
}

template <typename D> void impl_ILightSensor<D>::ReadingChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(ILightSensor)->remove_ReadingChanged(token));
}

template <typename D> Windows::Foundation::DateTime impl_ILightSensorReading<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ILightSensorReading)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> float impl_ILightSensorReading<D>::IlluminanceInLux() const
{
    float value {};
    check_hresult(WINRT_SHIM(ILightSensorReading)->get_IlluminanceInLux(&value));
    return value;
}

template <typename D> Windows::Devices::Sensors::LightSensorReading impl_ILightSensorReadingChangedEventArgs<D>::Reading() const
{
    Windows::Devices::Sensors::LightSensorReading value { nullptr };
    check_hresult(WINRT_SHIM(ILightSensorReadingChangedEventArgs)->get_Reading(put_abi(value)));
    return value;
}

template <typename D> float impl_ISensorRotationMatrix<D>::M11() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISensorRotationMatrix)->get_M11(&value));
    return value;
}

template <typename D> float impl_ISensorRotationMatrix<D>::M12() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISensorRotationMatrix)->get_M12(&value));
    return value;
}

template <typename D> float impl_ISensorRotationMatrix<D>::M13() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISensorRotationMatrix)->get_M13(&value));
    return value;
}

template <typename D> float impl_ISensorRotationMatrix<D>::M21() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISensorRotationMatrix)->get_M21(&value));
    return value;
}

template <typename D> float impl_ISensorRotationMatrix<D>::M22() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISensorRotationMatrix)->get_M22(&value));
    return value;
}

template <typename D> float impl_ISensorRotationMatrix<D>::M23() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISensorRotationMatrix)->get_M23(&value));
    return value;
}

template <typename D> float impl_ISensorRotationMatrix<D>::M31() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISensorRotationMatrix)->get_M31(&value));
    return value;
}

template <typename D> float impl_ISensorRotationMatrix<D>::M32() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISensorRotationMatrix)->get_M32(&value));
    return value;
}

template <typename D> float impl_ISensorRotationMatrix<D>::M33() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISensorRotationMatrix)->get_M33(&value));
    return value;
}

template <typename D> float impl_ISensorQuaternion<D>::W() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISensorQuaternion)->get_W(&value));
    return value;
}

template <typename D> float impl_ISensorQuaternion<D>::X() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISensorQuaternion)->get_X(&value));
    return value;
}

template <typename D> float impl_ISensorQuaternion<D>::Y() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISensorQuaternion)->get_Y(&value));
    return value;
}

template <typename D> float impl_ISensorQuaternion<D>::Z() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISensorQuaternion)->get_Z(&value));
    return value;
}

template <typename D> hstring impl_IOrientationSensorDeviceId<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IOrientationSensorDeviceId)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::OrientationSensor impl_IOrientationSensorStatics<D>::GetDefault() const
{
    Windows::Devices::Sensors::OrientationSensor result { nullptr };
    check_hresult(WINRT_SHIM(IOrientationSensorStatics)->abi_GetDefault(put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::OrientationSensor impl_IOrientationSensorStatics2<D>::GetDefaultForRelativeReadings() const
{
    Windows::Devices::Sensors::OrientationSensor result { nullptr };
    check_hresult(WINRT_SHIM(IOrientationSensorStatics2)->abi_GetDefaultForRelativeReadings(put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::OrientationSensor impl_IOrientationSensorStatics3<D>::GetDefault(Windows::Devices::Sensors::SensorReadingType sensorReadingtype) const
{
    Windows::Devices::Sensors::OrientationSensor result { nullptr };
    check_hresult(WINRT_SHIM(IOrientationSensorStatics3)->abi_GetDefaultWithSensorReadingType(sensorReadingtype, put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::OrientationSensor impl_IOrientationSensorStatics3<D>::GetDefault(Windows::Devices::Sensors::SensorReadingType sensorReadingType, Windows::Devices::Sensors::SensorOptimizationGoal optimizationGoal) const
{
    Windows::Devices::Sensors::OrientationSensor result { nullptr };
    check_hresult(WINRT_SHIM(IOrientationSensorStatics3)->abi_GetDefaultWithSensorReadingTypeAndSensorOptimizationGoal(sensorReadingType, optimizationGoal, put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::OrientationSensorReading impl_IOrientationSensor<D>::GetCurrentReading() const
{
    Windows::Devices::Sensors::OrientationSensorReading value { nullptr };
    check_hresult(WINRT_SHIM(IOrientationSensor)->abi_GetCurrentReading(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IOrientationSensor<D>::MinimumReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IOrientationSensor)->get_MinimumReportInterval(&value));
    return value;
}

template <typename D> void impl_IOrientationSensor<D>::ReportInterval(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IOrientationSensor)->put_ReportInterval(value));
}

template <typename D> uint32_t impl_IOrientationSensor<D>::ReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IOrientationSensor)->get_ReportInterval(&value));
    return value;
}

template <typename D> event_token impl_IOrientationSensor<D>::ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::OrientationSensor, Windows::Devices::Sensors::OrientationSensorReadingChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IOrientationSensor)->add_ReadingChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IOrientationSensor> impl_IOrientationSensor<D>::ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::OrientationSensor, Windows::Devices::Sensors::OrientationSensorReadingChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IOrientationSensor>(this, &ABI::Windows::Devices::Sensors::IOrientationSensor::remove_ReadingChanged, ReadingChanged(handler));
}

template <typename D> void impl_IOrientationSensor<D>::ReadingChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IOrientationSensor)->remove_ReadingChanged(token));
}

template <typename D> void impl_IOrientationSensor2<D>::ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) const
{
    check_hresult(WINRT_SHIM(IOrientationSensor2)->put_ReadingTransform(value));
}

template <typename D> Windows::Graphics::Display::DisplayOrientations impl_IOrientationSensor2<D>::ReadingTransform() const
{
    Windows::Graphics::Display::DisplayOrientations value {};
    check_hresult(WINRT_SHIM(IOrientationSensor2)->get_ReadingTransform(&value));
    return value;
}

template <typename D> Windows::Devices::Sensors::SensorReadingType impl_IOrientationSensor2<D>::ReadingType() const
{
    Windows::Devices::Sensors::SensorReadingType type {};
    check_hresult(WINRT_SHIM(IOrientationSensor2)->get_ReadingType(&type));
    return type;
}

template <typename D> Windows::Foundation::DateTime impl_IOrientationSensorReading<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IOrientationSensorReading)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::SensorRotationMatrix impl_IOrientationSensorReading<D>::RotationMatrix() const
{
    Windows::Devices::Sensors::SensorRotationMatrix value { nullptr };
    check_hresult(WINRT_SHIM(IOrientationSensorReading)->get_RotationMatrix(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::SensorQuaternion impl_IOrientationSensorReading<D>::Quaternion() const
{
    Windows::Devices::Sensors::SensorQuaternion value { nullptr };
    check_hresult(WINRT_SHIM(IOrientationSensorReading)->get_Quaternion(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::MagnetometerAccuracy impl_IOrientationSensorReadingYawAccuracy<D>::YawAccuracy() const
{
    Windows::Devices::Sensors::MagnetometerAccuracy value {};
    check_hresult(WINRT_SHIM(IOrientationSensorReadingYawAccuracy)->get_YawAccuracy(&value));
    return value;
}

template <typename D> Windows::Devices::Sensors::OrientationSensorReading impl_IOrientationSensorReadingChangedEventArgs<D>::Reading() const
{
    Windows::Devices::Sensors::OrientationSensorReading value { nullptr };
    check_hresult(WINRT_SHIM(IOrientationSensorReadingChangedEventArgs)->get_Reading(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISimpleOrientationSensorDeviceId<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISimpleOrientationSensorDeviceId)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::SimpleOrientationSensor impl_ISimpleOrientationSensorStatics<D>::GetDefault() const
{
    Windows::Devices::Sensors::SimpleOrientationSensor result { nullptr };
    check_hresult(WINRT_SHIM(ISimpleOrientationSensorStatics)->abi_GetDefault(put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::SimpleOrientation impl_ISimpleOrientationSensor<D>::GetCurrentOrientation() const
{
    Windows::Devices::Sensors::SimpleOrientation value {};
    check_hresult(WINRT_SHIM(ISimpleOrientationSensor)->abi_GetCurrentOrientation(&value));
    return value;
}

template <typename D> event_token impl_ISimpleOrientationSensor<D>::OrientationChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::SimpleOrientationSensor, Windows::Devices::Sensors::SimpleOrientationSensorOrientationChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISimpleOrientationSensor)->add_OrientationChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISimpleOrientationSensor> impl_ISimpleOrientationSensor<D>::OrientationChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::SimpleOrientationSensor, Windows::Devices::Sensors::SimpleOrientationSensorOrientationChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISimpleOrientationSensor>(this, &ABI::Windows::Devices::Sensors::ISimpleOrientationSensor::remove_OrientationChanged, OrientationChanged(handler));
}

template <typename D> void impl_ISimpleOrientationSensor<D>::OrientationChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(ISimpleOrientationSensor)->remove_OrientationChanged(token));
}

template <typename D> void impl_ISimpleOrientationSensor2<D>::ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) const
{
    check_hresult(WINRT_SHIM(ISimpleOrientationSensor2)->put_ReadingTransform(value));
}

template <typename D> Windows::Graphics::Display::DisplayOrientations impl_ISimpleOrientationSensor2<D>::ReadingTransform() const
{
    Windows::Graphics::Display::DisplayOrientations value {};
    check_hresult(WINRT_SHIM(ISimpleOrientationSensor2)->get_ReadingTransform(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISimpleOrientationSensorOrientationChangedEventArgs<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISimpleOrientationSensorOrientationChangedEventArgs)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::SimpleOrientation impl_ISimpleOrientationSensorOrientationChangedEventArgs<D>::Orientation() const
{
    Windows::Devices::Sensors::SimpleOrientation value {};
    check_hresult(WINRT_SHIM(ISimpleOrientationSensorOrientationChangedEventArgs)->get_Orientation(&value));
    return value;
}

template <typename D> hstring impl_IMagnetometerDeviceId<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagnetometerDeviceId)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::Magnetometer impl_IMagnetometerStatics<D>::GetDefault() const
{
    Windows::Devices::Sensors::Magnetometer result { nullptr };
    check_hresult(WINRT_SHIM(IMagnetometerStatics)->abi_GetDefault(put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::MagnetometerReading impl_IMagnetometer<D>::GetCurrentReading() const
{
    Windows::Devices::Sensors::MagnetometerReading value { nullptr };
    check_hresult(WINRT_SHIM(IMagnetometer)->abi_GetCurrentReading(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IMagnetometer<D>::MinimumReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMagnetometer)->get_MinimumReportInterval(&value));
    return value;
}

template <typename D> void impl_IMagnetometer<D>::ReportInterval(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IMagnetometer)->put_ReportInterval(value));
}

template <typename D> uint32_t impl_IMagnetometer<D>::ReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMagnetometer)->get_ReportInterval(&value));
    return value;
}

template <typename D> event_token impl_IMagnetometer<D>::ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Magnetometer, Windows::Devices::Sensors::MagnetometerReadingChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMagnetometer)->add_ReadingChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMagnetometer> impl_IMagnetometer<D>::ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Magnetometer, Windows::Devices::Sensors::MagnetometerReadingChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMagnetometer>(this, &ABI::Windows::Devices::Sensors::IMagnetometer::remove_ReadingChanged, ReadingChanged(handler));
}

template <typename D> void impl_IMagnetometer<D>::ReadingChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMagnetometer)->remove_ReadingChanged(token));
}

template <typename D> void impl_IMagnetometer2<D>::ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) const
{
    check_hresult(WINRT_SHIM(IMagnetometer2)->put_ReadingTransform(value));
}

template <typename D> Windows::Graphics::Display::DisplayOrientations impl_IMagnetometer2<D>::ReadingTransform() const
{
    Windows::Graphics::Display::DisplayOrientations value {};
    check_hresult(WINRT_SHIM(IMagnetometer2)->get_ReadingTransform(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IMagnetometerReading<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IMagnetometerReading)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> float impl_IMagnetometerReading<D>::MagneticFieldX() const
{
    float value {};
    check_hresult(WINRT_SHIM(IMagnetometerReading)->get_MagneticFieldX(&value));
    return value;
}

template <typename D> float impl_IMagnetometerReading<D>::MagneticFieldY() const
{
    float value {};
    check_hresult(WINRT_SHIM(IMagnetometerReading)->get_MagneticFieldY(&value));
    return value;
}

template <typename D> float impl_IMagnetometerReading<D>::MagneticFieldZ() const
{
    float value {};
    check_hresult(WINRT_SHIM(IMagnetometerReading)->get_MagneticFieldZ(&value));
    return value;
}

template <typename D> Windows::Devices::Sensors::MagnetometerAccuracy impl_IMagnetometerReading<D>::DirectionalAccuracy() const
{
    Windows::Devices::Sensors::MagnetometerAccuracy value {};
    check_hresult(WINRT_SHIM(IMagnetometerReading)->get_DirectionalAccuracy(&value));
    return value;
}

template <typename D> Windows::Devices::Sensors::MagnetometerReading impl_IMagnetometerReadingChangedEventArgs<D>::Reading() const
{
    Windows::Devices::Sensors::MagnetometerReading value { nullptr };
    check_hresult(WINRT_SHIM(IMagnetometerReadingChangedEventArgs)->get_Reading(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensor> impl_IActivitySensorStatics<D>::GetDefaultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensor> result;
    check_hresult(WINRT_SHIM(IActivitySensorStatics)->abi_GetDefaultAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IActivitySensorStatics<D>::GetDeviceSelector() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IActivitySensorStatics)->abi_GetDeviceSelector(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensor> impl_IActivitySensorStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensor> result;
    check_hresult(WINRT_SHIM(IActivitySensorStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReading>> impl_IActivitySensorStatics<D>::GetSystemHistoryAsync(const Windows::Foundation::DateTime & fromTime) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReading>> result;
    check_hresult(WINRT_SHIM(IActivitySensorStatics)->abi_GetSystemHistoryAsync(get_abi(fromTime), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReading>> impl_IActivitySensorStatics<D>::GetSystemHistoryAsync(const Windows::Foundation::DateTime & fromTime, const Windows::Foundation::TimeSpan & duration) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReading>> result;
    check_hresult(WINRT_SHIM(IActivitySensorStatics)->abi_GetSystemHistoryWithDurationAsync(get_abi(fromTime), get_abi(duration), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensorReading> impl_IActivitySensor<D>::GetCurrentReadingAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensorReading> result;
    check_hresult(WINRT_SHIM(IActivitySensor)->abi_GetCurrentReadingAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sensors::ActivityType> impl_IActivitySensor<D>::SubscribedActivities() const
{
    Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sensors::ActivityType> value;
    check_hresult(WINRT_SHIM(IActivitySensor)->get_SubscribedActivities(put_abi(value)));
    return value;
}

template <typename D> double impl_IActivitySensor<D>::PowerInMilliwatts() const
{
    double value {};
    check_hresult(WINRT_SHIM(IActivitySensor)->get_PowerInMilliwatts(&value));
    return value;
}

template <typename D> hstring impl_IActivitySensor<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IActivitySensor)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::Sensors::ActivityType> impl_IActivitySensor<D>::SupportedActivities() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::Sensors::ActivityType> value;
    check_hresult(WINRT_SHIM(IActivitySensor)->get_SupportedActivities(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IActivitySensor<D>::MinimumReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IActivitySensor)->get_MinimumReportInterval(&value));
    return value;
}

template <typename D> event_token impl_IActivitySensor<D>::ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::ActivitySensor, Windows::Devices::Sensors::ActivitySensorReadingChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IActivitySensor)->add_ReadingChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IActivitySensor> impl_IActivitySensor<D>::ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::ActivitySensor, Windows::Devices::Sensors::ActivitySensorReadingChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IActivitySensor>(this, &ABI::Windows::Devices::Sensors::IActivitySensor::remove_ReadingChanged, ReadingChanged(handler));
}

template <typename D> void impl_IActivitySensor<D>::ReadingChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IActivitySensor)->remove_ReadingChanged(token));
}

template <typename D> Windows::Foundation::DateTime impl_IActivitySensorReading<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IActivitySensorReading)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::ActivityType impl_IActivitySensorReading<D>::Activity() const
{
    Windows::Devices::Sensors::ActivityType value {};
    check_hresult(WINRT_SHIM(IActivitySensorReading)->get_Activity(&value));
    return value;
}

template <typename D> Windows::Devices::Sensors::ActivitySensorReadingConfidence impl_IActivitySensorReading<D>::Confidence() const
{
    Windows::Devices::Sensors::ActivitySensorReadingConfidence value {};
    check_hresult(WINRT_SHIM(IActivitySensorReading)->get_Confidence(&value));
    return value;
}

template <typename D> Windows::Devices::Sensors::ActivitySensorReading impl_IActivitySensorReadingChangedEventArgs<D>::Reading() const
{
    Windows::Devices::Sensors::ActivitySensorReading value { nullptr };
    check_hresult(WINRT_SHIM(IActivitySensorReadingChangedEventArgs)->get_Reading(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::ActivitySensorReading impl_IActivitySensorReadingChangeReport<D>::Reading() const
{
    Windows::Devices::Sensors::ActivitySensorReading value { nullptr };
    check_hresult(WINRT_SHIM(IActivitySensorReadingChangeReport)->get_Reading(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReadingChangeReport> impl_IActivitySensorTriggerDetails<D>::ReadReports() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReadingChangeReport> value;
    check_hresult(WINRT_SHIM(IActivitySensorTriggerDetails)->abi_ReadReports(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::Barometer impl_IBarometerStatics<D>::GetDefault() const
{
    Windows::Devices::Sensors::Barometer result { nullptr };
    check_hresult(WINRT_SHIM(IBarometerStatics)->abi_GetDefault(put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::BarometerReading impl_IBarometer<D>::GetCurrentReading() const
{
    Windows::Devices::Sensors::BarometerReading value { nullptr };
    check_hresult(WINRT_SHIM(IBarometer)->abi_GetCurrentReading(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IBarometer<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBarometer)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IBarometer<D>::MinimumReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarometer)->get_MinimumReportInterval(&value));
    return value;
}

template <typename D> void impl_IBarometer<D>::ReportInterval(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IBarometer)->put_ReportInterval(value));
}

template <typename D> uint32_t impl_IBarometer<D>::ReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarometer)->get_ReportInterval(&value));
    return value;
}

template <typename D> event_token impl_IBarometer<D>::ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Barometer, Windows::Devices::Sensors::BarometerReadingChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IBarometer)->add_ReadingChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IBarometer> impl_IBarometer<D>::ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Barometer, Windows::Devices::Sensors::BarometerReadingChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IBarometer>(this, &ABI::Windows::Devices::Sensors::IBarometer::remove_ReadingChanged, ReadingChanged(handler));
}

template <typename D> void impl_IBarometer<D>::ReadingChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IBarometer)->remove_ReadingChanged(token));
}

template <typename D> Windows::Foundation::DateTime impl_IBarometerReading<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IBarometerReading)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> double impl_IBarometerReading<D>::StationPressureInHectopascals() const
{
    double value {};
    check_hresult(WINRT_SHIM(IBarometerReading)->get_StationPressureInHectopascals(&value));
    return value;
}

template <typename D> Windows::Devices::Sensors::BarometerReading impl_IBarometerReadingChangedEventArgs<D>::Reading() const
{
    Windows::Devices::Sensors::BarometerReading value { nullptr };
    check_hresult(WINRT_SHIM(IBarometerReadingChangedEventArgs)->get_Reading(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::PedometerStepKind impl_IPedometerReading<D>::StepKind() const
{
    Windows::Devices::Sensors::PedometerStepKind value {};
    check_hresult(WINRT_SHIM(IPedometerReading)->get_StepKind(&value));
    return value;
}

template <typename D> int32_t impl_IPedometerReading<D>::CumulativeSteps() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IPedometerReading)->get_CumulativeSteps(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IPedometerReading<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IPedometerReading)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IPedometerReading<D>::CumulativeStepsDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IPedometerReading)->get_CumulativeStepsDuration(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::PedometerReading impl_IPedometerReadingChangedEventArgs<D>::Reading() const
{
    Windows::Devices::Sensors::PedometerReading value { nullptr };
    check_hresult(WINRT_SHIM(IPedometerReadingChangedEventArgs)->get_Reading(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Pedometer> impl_IPedometerStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Pedometer> operation;
    check_hresult(WINRT_SHIM(IPedometerStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Pedometer> impl_IPedometerStatics<D>::GetDefaultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Pedometer> operation;
    check_hresult(WINRT_SHIM(IPedometerStatics)->abi_GetDefaultAsync(put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IPedometerStatics<D>::GetDeviceSelector() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IPedometerStatics)->abi_GetDeviceSelector(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>> impl_IPedometerStatics<D>::GetSystemHistoryAsync(const Windows::Foundation::DateTime & fromTime) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>> operation;
    check_hresult(WINRT_SHIM(IPedometerStatics)->abi_GetSystemHistoryAsync(get_abi(fromTime), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>> impl_IPedometerStatics<D>::GetSystemHistoryAsync(const Windows::Foundation::DateTime & fromTime, const Windows::Foundation::TimeSpan & duration) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>> operation;
    check_hresult(WINRT_SHIM(IPedometerStatics)->abi_GetSystemHistoryWithDurationAsync(get_abi(fromTime), get_abi(duration), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading> impl_IPedometerStatics2<D>::GetReadingsFromTriggerDetails(const Windows::Devices::Sensors::SensorDataThresholdTriggerDetails & triggerDetails) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading> result;
    check_hresult(WINRT_SHIM(IPedometerStatics2)->abi_GetReadingsFromTriggerDetails(get_abi(triggerDetails), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IMapView<winrt::Windows::Devices::Sensors::PedometerStepKind, Windows::Devices::Sensors::PedometerReading> impl_IPedometer2<D>::GetCurrentReadings() const
{
    Windows::Foundation::Collections::IMapView<winrt::Windows::Devices::Sensors::PedometerStepKind, Windows::Devices::Sensors::PedometerReading> value;
    check_hresult(WINRT_SHIM(IPedometer2)->abi_GetCurrentReadings(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPedometer<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPedometer)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> double impl_IPedometer<D>::PowerInMilliwatts() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPedometer)->get_PowerInMilliwatts(&value));
    return value;
}

template <typename D> uint32_t impl_IPedometer<D>::MinimumReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPedometer)->get_MinimumReportInterval(&value));
    return value;
}

template <typename D> void impl_IPedometer<D>::ReportInterval(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IPedometer)->put_ReportInterval(value));
}

template <typename D> uint32_t impl_IPedometer<D>::ReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPedometer)->get_ReportInterval(&value));
    return value;
}

template <typename D> event_token impl_IPedometer<D>::ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Pedometer, Windows::Devices::Sensors::PedometerReadingChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPedometer)->add_ReadingChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPedometer> impl_IPedometer<D>::ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Pedometer, Windows::Devices::Sensors::PedometerReadingChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPedometer>(this, &ABI::Windows::Devices::Sensors::IPedometer::remove_ReadingChanged, ReadingChanged(handler));
}

template <typename D> void impl_IPedometer<D>::ReadingChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPedometer)->remove_ReadingChanged(token));
}

template <typename D> Windows::Devices::Sensors::PedometerDataThreshold impl_IPedometerDataThresholdFactory<D>::Create(const Windows::Devices::Sensors::Pedometer & sensor, int32_t stepGoal) const
{
    Windows::Devices::Sensors::PedometerDataThreshold threshold { nullptr };
    check_hresult(WINRT_SHIM(IPedometerDataThresholdFactory)->abi_Create(get_abi(sensor), stepGoal, put_abi(threshold)));
    return threshold;
}

template <typename D> hstring impl_IProximitySensorStatics<D>::GetDeviceSelector() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProximitySensorStatics)->abi_GetDeviceSelector(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::ProximitySensor impl_IProximitySensorStatics<D>::FromId(hstring_view sensorId) const
{
    Windows::Devices::Sensors::ProximitySensor result { nullptr };
    check_hresult(WINRT_SHIM(IProximitySensorStatics)->abi_FromId(get_abi(sensorId), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IProximitySensor<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProximitySensor)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IProximitySensor<D>::MaxDistanceInMillimeters() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IProximitySensor)->get_MaxDistanceInMillimeters(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IProximitySensor<D>::MinDistanceInMillimeters() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IProximitySensor)->get_MinDistanceInMillimeters(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::ProximitySensorReading impl_IProximitySensor<D>::GetCurrentReading() const
{
    Windows::Devices::Sensors::ProximitySensorReading value { nullptr };
    check_hresult(WINRT_SHIM(IProximitySensor)->abi_GetCurrentReading(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IProximitySensor<D>::ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::ProximitySensor, Windows::Devices::Sensors::ProximitySensorReadingChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IProximitySensor)->add_ReadingChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IProximitySensor> impl_IProximitySensor<D>::ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::ProximitySensor, Windows::Devices::Sensors::ProximitySensorReadingChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IProximitySensor>(this, &ABI::Windows::Devices::Sensors::IProximitySensor::remove_ReadingChanged, ReadingChanged(handler));
}

template <typename D> void impl_IProximitySensor<D>::ReadingChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IProximitySensor)->remove_ReadingChanged(token));
}

template <typename D> Windows::Devices::Sensors::ProximitySensorDisplayOnOffController impl_IProximitySensor<D>::CreateDisplayOnOffController() const
{
    Windows::Devices::Sensors::ProximitySensorDisplayOnOffController controller { nullptr };
    check_hresult(WINRT_SHIM(IProximitySensor)->abi_CreateDisplayOnOffController(put_abi(controller)));
    return controller;
}

template <typename D> Windows::Devices::Sensors::ProximitySensorReading impl_IProximitySensorReadingChangedEventArgs<D>::Reading() const
{
    Windows::Devices::Sensors::ProximitySensorReading value { nullptr };
    check_hresult(WINRT_SHIM(IProximitySensorReadingChangedEventArgs)->get_Reading(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IProximitySensorReading<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IProximitySensorReading)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> bool impl_IProximitySensorReading<D>::IsDetected() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IProximitySensorReading)->get_IsDetected(&value));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IProximitySensorReading<D>::DistanceInMillimeters() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IProximitySensorReading)->get_DistanceInMillimeters(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sensors::ProximitySensorDataThreshold impl_IProximitySensorDataThresholdFactory<D>::Create(const Windows::Devices::Sensors::ProximitySensor & sensor) const
{
    Windows::Devices::Sensors::ProximitySensorDataThreshold threshold { nullptr };
    check_hresult(WINRT_SHIM(IProximitySensorDataThresholdFactory)->abi_Create(get_abi(sensor), put_abi(threshold)));
    return threshold;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ProximitySensorReading> impl_IProximitySensorStatics2<D>::GetReadingsFromTriggerDetails(const Windows::Devices::Sensors::SensorDataThresholdTriggerDetails & triggerDetails) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ProximitySensorReading> result;
    check_hresult(WINRT_SHIM(IProximitySensorStatics2)->abi_GetReadingsFromTriggerDetails(get_abi(triggerDetails), put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::Altimeter impl_IAltimeterStatics<D>::GetDefault() const
{
    Windows::Devices::Sensors::Altimeter result { nullptr };
    check_hresult(WINRT_SHIM(IAltimeterStatics)->abi_GetDefault(put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Sensors::AltimeterReading impl_IAltimeter<D>::GetCurrentReading() const
{
    Windows::Devices::Sensors::AltimeterReading value { nullptr };
    check_hresult(WINRT_SHIM(IAltimeter)->abi_GetCurrentReading(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAltimeter<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAltimeter)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IAltimeter<D>::MinimumReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IAltimeter)->get_MinimumReportInterval(&value));
    return value;
}

template <typename D> void impl_IAltimeter<D>::ReportInterval(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IAltimeter)->put_ReportInterval(value));
}

template <typename D> uint32_t impl_IAltimeter<D>::ReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IAltimeter)->get_ReportInterval(&value));
    return value;
}

template <typename D> event_token impl_IAltimeter<D>::ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Altimeter, Windows::Devices::Sensors::AltimeterReadingChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAltimeter)->add_ReadingChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAltimeter> impl_IAltimeter<D>::ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Altimeter, Windows::Devices::Sensors::AltimeterReadingChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IAltimeter>(this, &ABI::Windows::Devices::Sensors::IAltimeter::remove_ReadingChanged, ReadingChanged(handler));
}

template <typename D> void impl_IAltimeter<D>::ReadingChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IAltimeter)->remove_ReadingChanged(token));
}

template <typename D> Windows::Foundation::DateTime impl_IAltimeterReading<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IAltimeterReading)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> double impl_IAltimeterReading<D>::AltitudeChangeInMeters() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAltimeterReading)->get_AltitudeChangeInMeters(&value));
    return value;
}

template <typename D> Windows::Devices::Sensors::AltimeterReading impl_IAltimeterReadingChangedEventArgs<D>::Reading() const
{
    Windows::Devices::Sensors::AltimeterReading value { nullptr };
    check_hresult(WINRT_SHIM(IAltimeterReadingChangedEventArgs)->get_Reading(put_abi(value)));
    return value;
}

inline Windows::Devices::Sensors::Accelerometer Accelerometer::GetDefault()
{
    return get_activation_factory<Accelerometer, IAccelerometerStatics>().GetDefault();
}

inline Windows::Devices::Sensors::Accelerometer Accelerometer::GetDefault(Windows::Devices::Sensors::AccelerometerReadingType readingType)
{
    return get_activation_factory<Accelerometer, IAccelerometerStatics2>().GetDefault(readingType);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensor> ActivitySensor::GetDefaultAsync()
{
    return get_activation_factory<ActivitySensor, IActivitySensorStatics>().GetDefaultAsync();
}

inline hstring ActivitySensor::GetDeviceSelector()
{
    return get_activation_factory<ActivitySensor, IActivitySensorStatics>().GetDeviceSelector();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensor> ActivitySensor::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<ActivitySensor, IActivitySensorStatics>().FromIdAsync(deviceId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReading>> ActivitySensor::GetSystemHistoryAsync(const Windows::Foundation::DateTime & fromTime)
{
    return get_activation_factory<ActivitySensor, IActivitySensorStatics>().GetSystemHistoryAsync(fromTime);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReading>> ActivitySensor::GetSystemHistoryAsync(const Windows::Foundation::DateTime & fromTime, const Windows::Foundation::TimeSpan & duration)
{
    return get_activation_factory<ActivitySensor, IActivitySensorStatics>().GetSystemHistoryAsync(fromTime, duration);
}

inline Windows::Devices::Sensors::Altimeter Altimeter::GetDefault()
{
    return get_activation_factory<Altimeter, IAltimeterStatics>().GetDefault();
}

inline Windows::Devices::Sensors::Barometer Barometer::GetDefault()
{
    return get_activation_factory<Barometer, IBarometerStatics>().GetDefault();
}

inline Windows::Devices::Sensors::Compass Compass::GetDefault()
{
    return get_activation_factory<Compass, ICompassStatics>().GetDefault();
}

inline Windows::Devices::Sensors::Gyrometer Gyrometer::GetDefault()
{
    return get_activation_factory<Gyrometer, IGyrometerStatics>().GetDefault();
}

inline Windows::Devices::Sensors::Inclinometer Inclinometer::GetDefault()
{
    return get_activation_factory<Inclinometer, IInclinometerStatics>().GetDefault();
}

inline Windows::Devices::Sensors::Inclinometer Inclinometer::GetDefaultForRelativeReadings()
{
    return get_activation_factory<Inclinometer, IInclinometerStatics2>().GetDefaultForRelativeReadings();
}

inline Windows::Devices::Sensors::Inclinometer Inclinometer::GetDefault(Windows::Devices::Sensors::SensorReadingType sensorReadingtype)
{
    return get_activation_factory<Inclinometer, IInclinometerStatics3>().GetDefault(sensorReadingtype);
}

inline Windows::Devices::Sensors::LightSensor LightSensor::GetDefault()
{
    return get_activation_factory<LightSensor, ILightSensorStatics>().GetDefault();
}

inline Windows::Devices::Sensors::Magnetometer Magnetometer::GetDefault()
{
    return get_activation_factory<Magnetometer, IMagnetometerStatics>().GetDefault();
}

inline Windows::Devices::Sensors::OrientationSensor OrientationSensor::GetDefault()
{
    return get_activation_factory<OrientationSensor, IOrientationSensorStatics>().GetDefault();
}

inline Windows::Devices::Sensors::OrientationSensor OrientationSensor::GetDefaultForRelativeReadings()
{
    return get_activation_factory<OrientationSensor, IOrientationSensorStatics2>().GetDefaultForRelativeReadings();
}

inline Windows::Devices::Sensors::OrientationSensor OrientationSensor::GetDefault(Windows::Devices::Sensors::SensorReadingType sensorReadingtype)
{
    return get_activation_factory<OrientationSensor, IOrientationSensorStatics3>().GetDefault(sensorReadingtype);
}

inline Windows::Devices::Sensors::OrientationSensor OrientationSensor::GetDefault(Windows::Devices::Sensors::SensorReadingType sensorReadingType, Windows::Devices::Sensors::SensorOptimizationGoal optimizationGoal)
{
    return get_activation_factory<OrientationSensor, IOrientationSensorStatics3>().GetDefault(sensorReadingType, optimizationGoal);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Pedometer> Pedometer::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<Pedometer, IPedometerStatics>().FromIdAsync(deviceId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Pedometer> Pedometer::GetDefaultAsync()
{
    return get_activation_factory<Pedometer, IPedometerStatics>().GetDefaultAsync();
}

inline hstring Pedometer::GetDeviceSelector()
{
    return get_activation_factory<Pedometer, IPedometerStatics>().GetDeviceSelector();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>> Pedometer::GetSystemHistoryAsync(const Windows::Foundation::DateTime & fromTime)
{
    return get_activation_factory<Pedometer, IPedometerStatics>().GetSystemHistoryAsync(fromTime);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>> Pedometer::GetSystemHistoryAsync(const Windows::Foundation::DateTime & fromTime, const Windows::Foundation::TimeSpan & duration)
{
    return get_activation_factory<Pedometer, IPedometerStatics>().GetSystemHistoryAsync(fromTime, duration);
}

inline Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading> Pedometer::GetReadingsFromTriggerDetails(const Windows::Devices::Sensors::SensorDataThresholdTriggerDetails & triggerDetails)
{
    return get_activation_factory<Pedometer, IPedometerStatics2>().GetReadingsFromTriggerDetails(triggerDetails);
}

inline PedometerDataThreshold::PedometerDataThreshold(const Windows::Devices::Sensors::Pedometer & sensor, int32_t stepGoal) :
    PedometerDataThreshold(get_activation_factory<PedometerDataThreshold, IPedometerDataThresholdFactory>().Create(sensor, stepGoal))
{}

inline hstring ProximitySensor::GetDeviceSelector()
{
    return get_activation_factory<ProximitySensor, IProximitySensorStatics>().GetDeviceSelector();
}

inline Windows::Devices::Sensors::ProximitySensor ProximitySensor::FromId(hstring_view sensorId)
{
    return get_activation_factory<ProximitySensor, IProximitySensorStatics>().FromId(sensorId);
}

inline Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ProximitySensorReading> ProximitySensor::GetReadingsFromTriggerDetails(const Windows::Devices::Sensors::SensorDataThresholdTriggerDetails & triggerDetails)
{
    return get_activation_factory<ProximitySensor, IProximitySensorStatics2>().GetReadingsFromTriggerDetails(triggerDetails);
}

inline ProximitySensorDataThreshold::ProximitySensorDataThreshold(const Windows::Devices::Sensors::ProximitySensor & sensor) :
    ProximitySensorDataThreshold(get_activation_factory<ProximitySensorDataThreshold, IProximitySensorDataThresholdFactory>().Create(sensor))
{}

inline Windows::Devices::Sensors::SimpleOrientationSensor SimpleOrientationSensor::GetDefault()
{
    return get_activation_factory<SimpleOrientationSensor, ISimpleOrientationSensorStatics>().GetDefault();
}

}

}
#pragma warning(pop)
