// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Bluetooth.Background.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Bluetooth::Background {

struct WINRT_EBO BluetoothLEAdvertisementPublisherTriggerDetails :
    Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails
{
    BluetoothLEAdvertisementPublisherTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BluetoothLEAdvertisementWatcherTriggerDetails :
    Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails
{
    BluetoothLEAdvertisementWatcherTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO GattCharacteristicNotificationTriggerDetails :
    Windows::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails
{
    GattCharacteristicNotificationTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RfcommConnectionTriggerDetails :
    Windows::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails
{
    RfcommConnectionTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RfcommInboundConnectionInformation :
    Windows::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation
{
    RfcommInboundConnectionInformation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RfcommOutboundConnectionInformation :
    Windows::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation
{
    RfcommOutboundConnectionInformation(std::nullptr_t) noexcept {}
};

}

}
