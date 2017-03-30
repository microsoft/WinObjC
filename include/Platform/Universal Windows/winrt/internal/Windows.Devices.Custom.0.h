// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Custom {

struct ICustomDevice;
struct ICustomDeviceStatics;
struct IIOControlCode;
struct IIOControlCodeFactory;
struct IKnownDeviceTypesStatics;
struct CustomDevice;
struct IOControlCode;

}

namespace Windows::Devices::Custom {

struct ICustomDevice;
struct ICustomDeviceStatics;
struct IIOControlCode;
struct IIOControlCodeFactory;
struct IKnownDeviceTypesStatics;
struct CustomDevice;
struct IOControlCode;
struct KnownDeviceTypes;

}

namespace Windows::Devices::Custom {

template <typename T> struct impl_ICustomDevice;
template <typename T> struct impl_ICustomDeviceStatics;
template <typename T> struct impl_IIOControlCode;
template <typename T> struct impl_IIOControlCodeFactory;
template <typename T> struct impl_IKnownDeviceTypesStatics;

}

namespace Windows::Devices::Custom {

enum class DeviceAccessMode
{
    Read = 0,
    Write = 1,
    ReadWrite = 2,
};

enum class DeviceSharingMode
{
    Shared = 0,
    Exclusive = 1,
};

enum class IOControlAccessMode
{
    Any = 0,
    Read = 1,
    Write = 2,
    ReadWrite = 3,
};

enum class IOControlBufferingMethod
{
    Buffered = 0,
    DirectInput = 1,
    DirectOutput = 2,
    Neither = 3,
};

}

}
