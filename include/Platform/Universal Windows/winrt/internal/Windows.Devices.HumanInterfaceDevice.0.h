// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::HumanInterfaceDevice {

struct IHidBooleanControl;
struct IHidBooleanControlDescription;
struct IHidBooleanControlDescription2;
struct IHidCollection;
struct IHidDevice;
struct IHidDeviceStatics;
struct IHidFeatureReport;
struct IHidInputReport;
struct IHidInputReportReceivedEventArgs;
struct IHidNumericControl;
struct IHidNumericControlDescription;
struct IHidOutputReport;
struct HidBooleanControl;
struct HidBooleanControlDescription;
struct HidCollection;
struct HidDevice;
struct HidFeatureReport;
struct HidInputReport;
struct HidInputReportReceivedEventArgs;
struct HidNumericControl;
struct HidNumericControlDescription;
struct HidOutputReport;

}

namespace Windows::Devices::HumanInterfaceDevice {

struct IHidBooleanControl;
struct IHidBooleanControlDescription;
struct IHidBooleanControlDescription2;
struct IHidCollection;
struct IHidDevice;
struct IHidDeviceStatics;
struct IHidFeatureReport;
struct IHidInputReport;
struct IHidInputReportReceivedEventArgs;
struct IHidNumericControl;
struct IHidNumericControlDescription;
struct IHidOutputReport;
struct HidBooleanControl;
struct HidBooleanControlDescription;
struct HidCollection;
struct HidDevice;
struct HidFeatureReport;
struct HidInputReport;
struct HidInputReportReceivedEventArgs;
struct HidNumericControl;
struct HidNumericControlDescription;
struct HidOutputReport;

}

namespace Windows::Devices::HumanInterfaceDevice {

template <typename T> struct impl_IHidBooleanControl;
template <typename T> struct impl_IHidBooleanControlDescription;
template <typename T> struct impl_IHidBooleanControlDescription2;
template <typename T> struct impl_IHidCollection;
template <typename T> struct impl_IHidDevice;
template <typename T> struct impl_IHidDeviceStatics;
template <typename T> struct impl_IHidFeatureReport;
template <typename T> struct impl_IHidInputReport;
template <typename T> struct impl_IHidInputReportReceivedEventArgs;
template <typename T> struct impl_IHidNumericControl;
template <typename T> struct impl_IHidNumericControlDescription;
template <typename T> struct impl_IHidOutputReport;

}

namespace Windows::Devices::HumanInterfaceDevice {

enum class HidCollectionType
{
    Physical = 0,
    Application = 1,
    Logical = 2,
    Report = 3,
    NamedArray = 4,
    UsageSwitch = 5,
    UsageModifier = 6,
    Other = 7,
};

enum class HidReportType
{
    Input = 0,
    Output = 1,
    Feature = 2,
};

}

}
