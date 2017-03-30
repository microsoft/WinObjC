// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Lights {

struct ILamp;
struct ILampAvailabilityChangedEventArgs;
struct ILampStatics;
struct Lamp;
struct LampAvailabilityChangedEventArgs;

}

namespace Windows::Devices::Lights {

struct ILamp;
struct ILampAvailabilityChangedEventArgs;
struct ILampStatics;
struct Lamp;
struct LampAvailabilityChangedEventArgs;

}

namespace Windows::Devices::Lights {

template <typename T> struct impl_ILamp;
template <typename T> struct impl_ILampAvailabilityChangedEventArgs;
template <typename T> struct impl_ILampStatics;

}

}
