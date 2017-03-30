// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Sensors.Custom.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Sensors::Custom {

struct WINRT_EBO CustomSensor :
    Windows::Devices::Sensors::Custom::ICustomSensor
{
    CustomSensor(std::nullptr_t) noexcept {}
    static hstring GetDeviceSelector(GUID interfaceId);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Custom::CustomSensor> FromIdAsync(hstring_view sensorId);
};

struct WINRT_EBO CustomSensorReading :
    Windows::Devices::Sensors::Custom::ICustomSensorReading
{
    CustomSensorReading(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CustomSensorReadingChangedEventArgs :
    Windows::Devices::Sensors::Custom::ICustomSensorReadingChangedEventArgs
{
    CustomSensorReadingChangedEventArgs(std::nullptr_t) noexcept {}
};

}

}
