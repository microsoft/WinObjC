// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.WiFiDirect.Services.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::WiFiDirect::Services {

struct WINRT_EBO WiFiDirectService :
    Windows::Devices::WiFiDirect::Services::IWiFiDirectService
{
    WiFiDirectService(std::nullptr_t) noexcept {}
    static hstring GetSelector(hstring_view serviceName);
    static hstring GetSelector(hstring_view serviceName, const Windows::Storage::Streams::IBuffer & serviceInfoFilter);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectService> FromIdAsync(hstring_view deviceId);
};

struct WINRT_EBO WiFiDirectServiceAdvertiser :
    Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser
{
    WiFiDirectServiceAdvertiser(std::nullptr_t) noexcept {}
    WiFiDirectServiceAdvertiser(hstring_view serviceName);
};

struct WINRT_EBO WiFiDirectServiceAutoAcceptSessionConnectedEventArgs :
    Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs
{
    WiFiDirectServiceAutoAcceptSessionConnectedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WiFiDirectServiceProvisioningInfo :
    Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo
{
    WiFiDirectServiceProvisioningInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WiFiDirectServiceRemotePortAddedEventArgs :
    Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceRemotePortAddedEventArgs
{
    WiFiDirectServiceRemotePortAddedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WiFiDirectServiceSession :
    Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession
{
    WiFiDirectServiceSession(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WiFiDirectServiceSessionDeferredEventArgs :
    Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionDeferredEventArgs
{
    WiFiDirectServiceSessionDeferredEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WiFiDirectServiceSessionRequest :
    Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest
{
    WiFiDirectServiceSessionRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WiFiDirectServiceSessionRequestedEventArgs :
    Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequestedEventArgs
{
    WiFiDirectServiceSessionRequestedEventArgs(std::nullptr_t) noexcept {}
};

}

}
