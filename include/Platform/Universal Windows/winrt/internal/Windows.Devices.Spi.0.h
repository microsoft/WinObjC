// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Spi {

struct ISpiBusInfo;
struct ISpiConnectionSettings;
struct ISpiConnectionSettingsFactory;
struct ISpiController;
struct ISpiControllerStatics;
struct ISpiDevice;
struct ISpiDeviceStatics;
struct SpiBusInfo;
struct SpiConnectionSettings;
struct SpiController;
struct SpiDevice;

}

namespace Windows::Devices::Spi {

struct ISpiBusInfo;
struct ISpiConnectionSettings;
struct ISpiConnectionSettingsFactory;
struct ISpiController;
struct ISpiControllerStatics;
struct ISpiDevice;
struct ISpiDeviceStatics;
struct SpiBusInfo;
struct SpiConnectionSettings;
struct SpiController;
struct SpiDevice;

}

namespace Windows::Devices::Spi {

template <typename T> struct impl_ISpiBusInfo;
template <typename T> struct impl_ISpiConnectionSettings;
template <typename T> struct impl_ISpiConnectionSettingsFactory;
template <typename T> struct impl_ISpiController;
template <typename T> struct impl_ISpiControllerStatics;
template <typename T> struct impl_ISpiDevice;
template <typename T> struct impl_ISpiDeviceStatics;

}

namespace Windows::Devices::Spi {

enum class SpiMode
{
    Mode0 = 0,
    Mode1 = 1,
    Mode2 = 2,
    Mode3 = 3,
};

enum class SpiSharingMode
{
    Exclusive = 0,
    Shared = 1,
};

}

}
