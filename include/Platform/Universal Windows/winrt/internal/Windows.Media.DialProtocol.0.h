// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::DialProtocol {

struct IDialApp;
struct IDialAppStateDetails;
struct IDialDevice;
struct IDialDevice2;
struct IDialDevicePicker;
struct IDialDevicePickerFilter;
struct IDialDeviceSelectedEventArgs;
struct IDialDeviceStatics;
struct IDialDisconnectButtonClickedEventArgs;
struct DialApp;
struct DialAppStateDetails;
struct DialDevice;
struct DialDevicePicker;
struct DialDevicePickerFilter;
struct DialDeviceSelectedEventArgs;
struct DialDisconnectButtonClickedEventArgs;

}

namespace Windows::Media::DialProtocol {

struct IDialApp;
struct IDialAppStateDetails;
struct IDialDevice;
struct IDialDevice2;
struct IDialDevicePicker;
struct IDialDevicePickerFilter;
struct IDialDeviceSelectedEventArgs;
struct IDialDeviceStatics;
struct IDialDisconnectButtonClickedEventArgs;
struct DialApp;
struct DialAppStateDetails;
struct DialDevice;
struct DialDevicePicker;
struct DialDevicePickerFilter;
struct DialDeviceSelectedEventArgs;
struct DialDisconnectButtonClickedEventArgs;

}

namespace Windows::Media::DialProtocol {

template <typename T> struct impl_IDialApp;
template <typename T> struct impl_IDialAppStateDetails;
template <typename T> struct impl_IDialDevice;
template <typename T> struct impl_IDialDevice2;
template <typename T> struct impl_IDialDevicePicker;
template <typename T> struct impl_IDialDevicePickerFilter;
template <typename T> struct impl_IDialDeviceSelectedEventArgs;
template <typename T> struct impl_IDialDeviceStatics;
template <typename T> struct impl_IDialDisconnectButtonClickedEventArgs;

}

namespace Windows::Media::DialProtocol {

enum class DialAppLaunchResult
{
    Launched = 0,
    FailedToLaunch = 1,
    NotFound = 2,
    NetworkFailure = 3,
};

enum class DialAppState
{
    Unknown = 0,
    Stopped = 1,
    Running = 2,
    NetworkFailure = 3,
};

enum class DialAppStopResult
{
    Stopped = 0,
    StopFailed = 1,
    OperationNotSupported = 2,
    NetworkFailure = 3,
};

enum class DialDeviceDisplayStatus
{
    None = 0,
    Connecting = 1,
    Connected = 2,
    Disconnecting = 3,
    Disconnected = 4,
    Error = 5,
};

}

}
