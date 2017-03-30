// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Background {

struct IDeviceServicingDetails;
struct IDeviceUseDetails;
struct DeviceServicingDetails;
struct DeviceUseDetails;

}

namespace Windows::Devices::Background {

struct IDeviceServicingDetails;
struct IDeviceUseDetails;
struct DeviceServicingDetails;
struct DeviceUseDetails;

}

namespace Windows::Devices::Background {

template <typename T> struct impl_IDeviceServicingDetails;
template <typename T> struct impl_IDeviceUseDetails;

}

}
