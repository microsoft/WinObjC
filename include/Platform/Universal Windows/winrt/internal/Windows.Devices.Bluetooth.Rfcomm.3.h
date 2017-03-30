// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Bluetooth.Rfcomm.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Bluetooth::Rfcomm {

struct WINRT_EBO RfcommDeviceService :
    Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService,
    impl::require<RfcommDeviceService, Windows::Foundation::IClosable, Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService2, Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService3>
{
    RfcommDeviceService(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> FromIdAsync(hstring_view deviceId);
    static hstring GetDeviceSelector(const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId);
    static hstring GetDeviceSelectorForBluetoothDevice(const Windows::Devices::Bluetooth::BluetoothDevice & bluetoothDevice);
    static hstring GetDeviceSelectorForBluetoothDevice(const Windows::Devices::Bluetooth::BluetoothDevice & bluetoothDevice, Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode);
    static hstring GetDeviceSelectorForBluetoothDeviceAndServiceId(const Windows::Devices::Bluetooth::BluetoothDevice & bluetoothDevice, const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId);
    static hstring GetDeviceSelectorForBluetoothDeviceAndServiceId(const Windows::Devices::Bluetooth::BluetoothDevice & bluetoothDevice, const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId, Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode);
};

struct WINRT_EBO RfcommDeviceServicesResult :
    Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult
{
    RfcommDeviceServicesResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RfcommServiceId :
    Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId
{
    RfcommServiceId(std::nullptr_t) noexcept {}
    static Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId FromUuid(GUID uuid);
    static Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId FromShortId(uint32_t shortId);
    static Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId SerialPort();
    static Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId ObexObjectPush();
    static Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId ObexFileTransfer();
    static Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId PhoneBookAccessPce();
    static Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId PhoneBookAccessPse();
    static Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId GenericFileTransfer();
};

struct WINRT_EBO RfcommServiceProvider :
    Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider,
    impl::require<RfcommServiceProvider, Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider2>
{
    RfcommServiceProvider(std::nullptr_t) noexcept {}
    using impl_IRfcommServiceProvider::StartAdvertising;
    using impl_IRfcommServiceProvider2::StartAdvertising;
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommServiceProvider> CreateAsync(const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId);
};

}

}
