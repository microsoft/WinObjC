// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Spi::Provider {

struct IProviderSpiConnectionSettings;
struct IProviderSpiConnectionSettingsFactory;
struct ISpiControllerProvider;
struct ISpiDeviceProvider;
struct ISpiProvider;
struct ProviderSpiConnectionSettings;

}

namespace Windows::Devices::Spi::Provider {

struct IProviderSpiConnectionSettings;
struct IProviderSpiConnectionSettingsFactory;
struct ISpiControllerProvider;
struct ISpiDeviceProvider;
struct ISpiProvider;
struct ProviderSpiConnectionSettings;

}

namespace Windows::Devices::Spi::Provider {

template <typename T> struct impl_IProviderSpiConnectionSettings;
template <typename T> struct impl_IProviderSpiConnectionSettingsFactory;
template <typename T> struct impl_ISpiControllerProvider;
template <typename T> struct impl_ISpiDeviceProvider;
template <typename T> struct impl_ISpiProvider;

}

namespace Windows::Devices::Spi::Provider {

enum class ProviderSpiMode
{
    Mode0 = 0,
    Mode1 = 1,
    Mode2 = 2,
    Mode3 = 3,
};

enum class ProviderSpiSharingMode
{
    Exclusive = 0,
    Shared = 1,
};

}

}
