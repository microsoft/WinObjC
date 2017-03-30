// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.HumanInterfaceDevice.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::HumanInterfaceDevice {

struct WINRT_EBO HidBooleanControl :
    Windows::Devices::HumanInterfaceDevice::IHidBooleanControl
{
    HidBooleanControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HidBooleanControlDescription :
    Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription,
    impl::require<HidBooleanControlDescription, Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription2>
{
    HidBooleanControlDescription(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HidCollection :
    Windows::Devices::HumanInterfaceDevice::IHidCollection
{
    HidCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HidDevice :
    Windows::Devices::HumanInterfaceDevice::IHidDevice
{
    HidDevice(std::nullptr_t) noexcept {}
    static hstring GetDeviceSelector(uint16_t usagePage, uint16_t usageId);
    static hstring GetDeviceSelector(uint16_t usagePage, uint16_t usageId, uint16_t vendorId, uint16_t productId);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidDevice> FromIdAsync(hstring_view deviceId, Windows::Storage::FileAccessMode accessMode);
};

struct WINRT_EBO HidFeatureReport :
    Windows::Devices::HumanInterfaceDevice::IHidFeatureReport
{
    HidFeatureReport(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HidInputReport :
    Windows::Devices::HumanInterfaceDevice::IHidInputReport
{
    HidInputReport(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HidInputReportReceivedEventArgs :
    Windows::Devices::HumanInterfaceDevice::IHidInputReportReceivedEventArgs
{
    HidInputReportReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HidNumericControl :
    Windows::Devices::HumanInterfaceDevice::IHidNumericControl
{
    HidNumericControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HidNumericControlDescription :
    Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription
{
    HidNumericControlDescription(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HidOutputReport :
    Windows::Devices::HumanInterfaceDevice::IHidOutputReport
{
    HidOutputReport(std::nullptr_t) noexcept {}
};

}

}
