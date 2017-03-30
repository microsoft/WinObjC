// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.WiFi.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::WiFi {

struct WINRT_EBO WiFiAdapter :
    Windows::Devices::WiFi::IWiFiAdapter
{
    WiFiAdapter(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAdapter>> FindAllAdaptersAsync();
    static hstring GetDeviceSelector();
    static Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiAdapter> FromIdAsync(hstring_view deviceId);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::WiFi::WiFiAccessStatus> RequestAccessAsync();
};

struct WINRT_EBO WiFiAvailableNetwork :
    Windows::Devices::WiFi::IWiFiAvailableNetwork
{
    WiFiAvailableNetwork(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WiFiConnectionResult :
    Windows::Devices::WiFi::IWiFiConnectionResult
{
    WiFiConnectionResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WiFiNetworkReport :
    Windows::Devices::WiFi::IWiFiNetworkReport
{
    WiFiNetworkReport(std::nullptr_t) noexcept {}
};

}

}
