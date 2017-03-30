// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.SerialCommunication.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::SerialCommunication {

struct WINRT_EBO ErrorReceivedEventArgs :
    Windows::Devices::SerialCommunication::IErrorReceivedEventArgs
{
    ErrorReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PinChangedEventArgs :
    Windows::Devices::SerialCommunication::IPinChangedEventArgs
{
    PinChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SerialDevice :
    Windows::Devices::SerialCommunication::ISerialDevice
{
    SerialDevice(std::nullptr_t) noexcept {}
    static hstring GetDeviceSelector();
    static hstring GetDeviceSelector(hstring_view portName);
    static hstring GetDeviceSelectorFromUsbVidPid(uint16_t vendorId, uint16_t productId);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::SerialCommunication::SerialDevice> FromIdAsync(hstring_view deviceId);
};

}

}
