// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Radios {

struct IRadio;
struct IRadioStatics;
struct Radio;

}

namespace Windows::Devices::Radios {

struct IRadio;
struct IRadioStatics;
struct Radio;

}

namespace Windows::Devices::Radios {

template <typename T> struct impl_IRadio;
template <typename T> struct impl_IRadioStatics;

}

namespace Windows::Devices::Radios {

enum class RadioAccessStatus
{
    Unspecified = 0,
    Allowed = 1,
    DeniedByUser = 2,
    DeniedBySystem = 3,
};

enum class RadioKind
{
    Other = 0,
    WiFi = 1,
    MobileBroadband = 2,
    Bluetooth = 3,
    FM = 4,
};

enum class RadioState
{
    Unknown = 0,
    On = 1,
    Off = 2,
    Disabled = 3,
};

}

}
