// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Printers.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Printers {

struct WINRT_EBO Print3DDevice :
    Windows::Devices::Printers::IPrint3DDevice
{
    Print3DDevice(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Printers::Print3DDevice> FromIdAsync(hstring_view deviceId);
    static hstring GetDeviceSelector();
};

struct WINRT_EBO PrintSchema :
    Windows::Devices::Printers::IPrintSchema
{
    PrintSchema(std::nullptr_t) noexcept {}
};

}

}
