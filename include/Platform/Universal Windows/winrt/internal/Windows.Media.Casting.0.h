// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Casting {

struct ICastingConnection;
struct ICastingConnectionErrorOccurredEventArgs;
struct ICastingDevice;
struct ICastingDevicePicker;
struct ICastingDevicePickerFilter;
struct ICastingDeviceSelectedEventArgs;
struct ICastingDeviceStatics;
struct ICastingSource;
struct CastingConnection;
struct CastingConnectionErrorOccurredEventArgs;
struct CastingDevice;
struct CastingDevicePicker;
struct CastingDevicePickerFilter;
struct CastingDeviceSelectedEventArgs;
struct CastingSource;

}

namespace Windows::Media::Casting {

struct ICastingConnection;
struct ICastingConnectionErrorOccurredEventArgs;
struct ICastingDevice;
struct ICastingDevicePicker;
struct ICastingDevicePickerFilter;
struct ICastingDeviceSelectedEventArgs;
struct ICastingDeviceStatics;
struct ICastingSource;
struct CastingConnection;
struct CastingConnectionErrorOccurredEventArgs;
struct CastingDevice;
struct CastingDevicePicker;
struct CastingDevicePickerFilter;
struct CastingDeviceSelectedEventArgs;
struct CastingSource;

}

namespace Windows::Media::Casting {

template <typename T> struct impl_ICastingConnection;
template <typename T> struct impl_ICastingConnectionErrorOccurredEventArgs;
template <typename T> struct impl_ICastingDevice;
template <typename T> struct impl_ICastingDevicePicker;
template <typename T> struct impl_ICastingDevicePickerFilter;
template <typename T> struct impl_ICastingDeviceSelectedEventArgs;
template <typename T> struct impl_ICastingDeviceStatics;
template <typename T> struct impl_ICastingSource;

}

namespace Windows::Media::Casting {

enum class CastingConnectionErrorStatus
{
    Succeeded = 0,
    DeviceDidNotRespond = 1,
    DeviceError = 2,
    DeviceLocked = 3,
    ProtectedPlaybackFailed = 4,
    InvalidCastingSource = 5,
    Unknown = 6,
};

enum class CastingConnectionState
{
    Disconnected = 0,
    Connected = 1,
    Rendering = 2,
    Disconnecting = 3,
    Connecting = 4,
};

enum class CastingPlaybackTypes : unsigned
{
    None = 0x0,
    Audio = 0x1,
    Video = 0x2,
    Picture = 0x4,
};

DEFINE_ENUM_FLAG_OPERATORS(CastingPlaybackTypes)

}

}
