// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Bluetooth.Background.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8aef9bca_fe7d_5966_9789_fede24cb41c4
#define WINRT_GENERIC_8aef9bca_fe7d_5966_9789_fede24cb41c4
template <> struct __declspec(uuid("8aef9bca-fe7d-5966-9789-fede24cb41c4")) __declspec(novtable) IVectorView<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs> : impl_IVectorView<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_096edbb8_ecef_5724_be62_240dcff6aca9
#define WINRT_GENERIC_096edbb8_ecef_5724_be62_240dcff6aca9
template <> struct __declspec(uuid("096edbb8-ecef-5724-be62-240dcff6aca9")) __declspec(novtable) IIterator<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs> : impl_IIterator<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_34f6412f_8314_5205_967c_db357c9a42a7
#define WINRT_GENERIC_34f6412f_8314_5205_967c_db357c9a42a7
template <> struct __declspec(uuid("34f6412f-8314-5205-967c-db357c9a42a7")) __declspec(novtable) IIterable<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs> : impl_IIterable<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs> {};
#endif


}

namespace Windows::Devices::Bluetooth::Background {

struct IBluetoothLEAdvertisementPublisherTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IBluetoothLEAdvertisementPublisherTriggerDetails>
{
    IBluetoothLEAdvertisementPublisherTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IBluetoothLEAdvertisementWatcherTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IBluetoothLEAdvertisementWatcherTriggerDetails>
{
    IBluetoothLEAdvertisementWatcherTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IGattCharacteristicNotificationTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IGattCharacteristicNotificationTriggerDetails>
{
    IGattCharacteristicNotificationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IRfcommConnectionTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IRfcommConnectionTriggerDetails>
{
    IRfcommConnectionTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IRfcommInboundConnectionInformation :
    Windows::Foundation::IInspectable,
    impl::consume<IRfcommInboundConnectionInformation>
{
    IRfcommInboundConnectionInformation(std::nullptr_t = nullptr) noexcept {}
};

struct IRfcommOutboundConnectionInformation :
    Windows::Foundation::IInspectable,
    impl::consume<IRfcommOutboundConnectionInformation>
{
    IRfcommOutboundConnectionInformation(std::nullptr_t = nullptr) noexcept {}
};

}

}
