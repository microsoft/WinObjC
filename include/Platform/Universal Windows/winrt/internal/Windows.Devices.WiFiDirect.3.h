// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.WiFiDirect.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::WiFiDirect {

struct WINRT_EBO WiFiDirectAdvertisement :
    Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement,
    impl::require<WiFiDirectAdvertisement, Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement2>
{
    WiFiDirectAdvertisement(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WiFiDirectAdvertisementPublisher :
    Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher
{
    WiFiDirectAdvertisementPublisher(std::nullptr_t) noexcept {}
    WiFiDirectAdvertisementPublisher();
};

struct WINRT_EBO WiFiDirectAdvertisementPublisherStatusChangedEventArgs :
    Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisherStatusChangedEventArgs
{
    WiFiDirectAdvertisementPublisherStatusChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WiFiDirectConnectionListener :
    Windows::Devices::WiFiDirect::IWiFiDirectConnectionListener
{
    WiFiDirectConnectionListener(std::nullptr_t) noexcept {}
    WiFiDirectConnectionListener();
};

struct WINRT_EBO WiFiDirectConnectionParameters :
    Windows::Devices::WiFiDirect::IWiFiDirectConnectionParameters,
    impl::require<WiFiDirectConnectionParameters, Windows::Devices::Enumeration::IDevicePairingSettings, Windows::Devices::WiFiDirect::IWiFiDirectConnectionParameters2>
{
    WiFiDirectConnectionParameters(std::nullptr_t) noexcept {}
    WiFiDirectConnectionParameters();
    static Windows::Devices::Enumeration::DevicePairingKinds GetDevicePairingKinds(Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod configurationMethod);
};

struct WINRT_EBO WiFiDirectConnectionRequest :
    Windows::Devices::WiFiDirect::IWiFiDirectConnectionRequest
{
    WiFiDirectConnectionRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WiFiDirectConnectionRequestedEventArgs :
    Windows::Devices::WiFiDirect::IWiFiDirectConnectionRequestedEventArgs
{
    WiFiDirectConnectionRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WiFiDirectDevice :
    Windows::Devices::WiFiDirect::IWiFiDirectDevice
{
    WiFiDirectDevice(std::nullptr_t) noexcept {}
    static hstring GetDeviceSelector();
    static Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::WiFiDirectDevice> FromIdAsync(hstring_view deviceId);
    static hstring GetDeviceSelector(Windows::Devices::WiFiDirect::WiFiDirectDeviceSelectorType type);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::WiFiDirectDevice> FromIdAsync(hstring_view deviceId, const Windows::Devices::WiFiDirect::WiFiDirectConnectionParameters & connectionParameters);
};

struct WINRT_EBO WiFiDirectInformationElement :
    Windows::Devices::WiFiDirect::IWiFiDirectInformationElement
{
    WiFiDirectInformationElement(std::nullptr_t) noexcept {}
    WiFiDirectInformationElement();
    static Windows::Foundation::Collections::IVector<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> CreateFromBuffer(const Windows::Storage::Streams::IBuffer & buffer);
    static Windows::Foundation::Collections::IVector<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> CreateFromDeviceInformation(const Windows::Devices::Enumeration::DeviceInformation & deviceInformation);
};

struct WINRT_EBO WiFiDirectLegacySettings :
    Windows::Devices::WiFiDirect::IWiFiDirectLegacySettings
{
    WiFiDirectLegacySettings(std::nullptr_t) noexcept {}
};

}

}
