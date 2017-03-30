// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Bluetooth::Advertisement {

struct IBluetoothLEAdvertisement;
struct IBluetoothLEAdvertisementBytePattern;
struct IBluetoothLEAdvertisementBytePatternFactory;
struct IBluetoothLEAdvertisementDataSection;
struct IBluetoothLEAdvertisementDataSectionFactory;
struct IBluetoothLEAdvertisementDataTypesStatics;
struct IBluetoothLEAdvertisementFilter;
struct IBluetoothLEAdvertisementPublisher;
struct IBluetoothLEAdvertisementPublisherFactory;
struct IBluetoothLEAdvertisementPublisherStatusChangedEventArgs;
struct IBluetoothLEAdvertisementReceivedEventArgs;
struct IBluetoothLEAdvertisementWatcher;
struct IBluetoothLEAdvertisementWatcherFactory;
struct IBluetoothLEAdvertisementWatcherStoppedEventArgs;
struct IBluetoothLEManufacturerData;
struct IBluetoothLEManufacturerDataFactory;
struct BluetoothLEAdvertisement;
struct BluetoothLEAdvertisementBytePattern;
struct BluetoothLEAdvertisementDataSection;
struct BluetoothLEAdvertisementFilter;
struct BluetoothLEAdvertisementPublisher;
struct BluetoothLEAdvertisementPublisherStatusChangedEventArgs;
struct BluetoothLEAdvertisementReceivedEventArgs;
struct BluetoothLEAdvertisementWatcher;
struct BluetoothLEAdvertisementWatcherStoppedEventArgs;
struct BluetoothLEManufacturerData;

}

namespace Windows::Devices::Bluetooth::Advertisement {

struct IBluetoothLEAdvertisement;
struct IBluetoothLEAdvertisementBytePattern;
struct IBluetoothLEAdvertisementBytePatternFactory;
struct IBluetoothLEAdvertisementDataSection;
struct IBluetoothLEAdvertisementDataSectionFactory;
struct IBluetoothLEAdvertisementDataTypesStatics;
struct IBluetoothLEAdvertisementFilter;
struct IBluetoothLEAdvertisementPublisher;
struct IBluetoothLEAdvertisementPublisherFactory;
struct IBluetoothLEAdvertisementPublisherStatusChangedEventArgs;
struct IBluetoothLEAdvertisementReceivedEventArgs;
struct IBluetoothLEAdvertisementWatcher;
struct IBluetoothLEAdvertisementWatcherFactory;
struct IBluetoothLEAdvertisementWatcherStoppedEventArgs;
struct IBluetoothLEManufacturerData;
struct IBluetoothLEManufacturerDataFactory;
struct BluetoothLEAdvertisement;
struct BluetoothLEAdvertisementBytePattern;
struct BluetoothLEAdvertisementDataSection;
struct BluetoothLEAdvertisementDataTypes;
struct BluetoothLEAdvertisementFilter;
struct BluetoothLEAdvertisementPublisher;
struct BluetoothLEAdvertisementPublisherStatusChangedEventArgs;
struct BluetoothLEAdvertisementReceivedEventArgs;
struct BluetoothLEAdvertisementWatcher;
struct BluetoothLEAdvertisementWatcherStoppedEventArgs;
struct BluetoothLEManufacturerData;

}

namespace Windows::Devices::Bluetooth::Advertisement {

template <typename T> struct impl_IBluetoothLEAdvertisement;
template <typename T> struct impl_IBluetoothLEAdvertisementBytePattern;
template <typename T> struct impl_IBluetoothLEAdvertisementBytePatternFactory;
template <typename T> struct impl_IBluetoothLEAdvertisementDataSection;
template <typename T> struct impl_IBluetoothLEAdvertisementDataSectionFactory;
template <typename T> struct impl_IBluetoothLEAdvertisementDataTypesStatics;
template <typename T> struct impl_IBluetoothLEAdvertisementFilter;
template <typename T> struct impl_IBluetoothLEAdvertisementPublisher;
template <typename T> struct impl_IBluetoothLEAdvertisementPublisherFactory;
template <typename T> struct impl_IBluetoothLEAdvertisementPublisherStatusChangedEventArgs;
template <typename T> struct impl_IBluetoothLEAdvertisementReceivedEventArgs;
template <typename T> struct impl_IBluetoothLEAdvertisementWatcher;
template <typename T> struct impl_IBluetoothLEAdvertisementWatcherFactory;
template <typename T> struct impl_IBluetoothLEAdvertisementWatcherStoppedEventArgs;
template <typename T> struct impl_IBluetoothLEManufacturerData;
template <typename T> struct impl_IBluetoothLEManufacturerDataFactory;

}

namespace Windows::Devices::Bluetooth::Advertisement {

enum class BluetoothLEAdvertisementFlags : unsigned
{
    None = 0x0,
    LimitedDiscoverableMode = 0x1,
    GeneralDiscoverableMode = 0x2,
    ClassicNotSupported = 0x4,
    DualModeControllerCapable = 0x8,
    DualModeHostCapable = 0x10,
};

DEFINE_ENUM_FLAG_OPERATORS(BluetoothLEAdvertisementFlags)

enum class BluetoothLEAdvertisementPublisherStatus
{
    Created = 0,
    Waiting = 1,
    Started = 2,
    Stopping = 3,
    Stopped = 4,
    Aborted = 5,
};

enum class BluetoothLEAdvertisementType
{
    ConnectableUndirected = 0,
    ConnectableDirected = 1,
    ScannableUndirected = 2,
    NonConnectableUndirected = 3,
    ScanResponse = 4,
};

enum class BluetoothLEAdvertisementWatcherStatus
{
    Created = 0,
    Started = 1,
    Stopping = 2,
    Stopped = 3,
    Aborted = 4,
};

enum class BluetoothLEScanningMode
{
    Passive = 0,
    Active = 1,
};

}

}
