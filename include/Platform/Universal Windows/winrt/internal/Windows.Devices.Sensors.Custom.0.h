// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Sensors::Custom {

struct ICustomSensor;
struct ICustomSensorReading;
struct ICustomSensorReadingChangedEventArgs;
struct ICustomSensorStatics;
struct CustomSensor;
struct CustomSensorReading;
struct CustomSensorReadingChangedEventArgs;

}

namespace Windows::Devices::Sensors::Custom {

struct ICustomSensor;
struct ICustomSensorReading;
struct ICustomSensorReadingChangedEventArgs;
struct ICustomSensorStatics;
struct CustomSensor;
struct CustomSensorReading;
struct CustomSensorReadingChangedEventArgs;

}

namespace Windows::Devices::Sensors::Custom {

template <typename T> struct impl_ICustomSensor;
template <typename T> struct impl_ICustomSensorReading;
template <typename T> struct impl_ICustomSensorReadingChangedEventArgs;
template <typename T> struct impl_ICustomSensorStatics;

}

}
