// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Usb {

struct IUsbBulkInEndpointDescriptor;
struct IUsbBulkInPipe;
struct IUsbBulkOutEndpointDescriptor;
struct IUsbBulkOutPipe;
struct IUsbConfiguration;
struct IUsbConfigurationDescriptor;
struct IUsbConfigurationDescriptorStatics;
struct IUsbControlRequestType;
struct IUsbDescriptor;
struct IUsbDevice;
struct IUsbDeviceClass;
struct IUsbDeviceClasses;
struct IUsbDeviceClassesStatics;
struct IUsbDeviceDescriptor;
struct IUsbDeviceStatics;
struct IUsbEndpointDescriptor;
struct IUsbEndpointDescriptorStatics;
struct IUsbInterface;
struct IUsbInterfaceDescriptor;
struct IUsbInterfaceDescriptorStatics;
struct IUsbInterfaceSetting;
struct IUsbInterruptInEndpointDescriptor;
struct IUsbInterruptInEventArgs;
struct IUsbInterruptInPipe;
struct IUsbInterruptOutEndpointDescriptor;
struct IUsbInterruptOutPipe;
struct IUsbSetupPacket;
struct IUsbSetupPacketFactory;
struct UsbBulkInEndpointDescriptor;
struct UsbBulkInPipe;
struct UsbBulkOutEndpointDescriptor;
struct UsbBulkOutPipe;
struct UsbConfiguration;
struct UsbConfigurationDescriptor;
struct UsbControlRequestType;
struct UsbDescriptor;
struct UsbDevice;
struct UsbDeviceClass;
struct UsbDeviceClasses;
struct UsbDeviceDescriptor;
struct UsbEndpointDescriptor;
struct UsbInterface;
struct UsbInterfaceDescriptor;
struct UsbInterfaceSetting;
struct UsbInterruptInEndpointDescriptor;
struct UsbInterruptInEventArgs;
struct UsbInterruptInPipe;
struct UsbInterruptOutEndpointDescriptor;
struct UsbInterruptOutPipe;
struct UsbSetupPacket;

}

namespace Windows::Devices::Usb {

struct IUsbBulkInEndpointDescriptor;
struct IUsbBulkInPipe;
struct IUsbBulkOutEndpointDescriptor;
struct IUsbBulkOutPipe;
struct IUsbConfiguration;
struct IUsbConfigurationDescriptor;
struct IUsbConfigurationDescriptorStatics;
struct IUsbControlRequestType;
struct IUsbDescriptor;
struct IUsbDevice;
struct IUsbDeviceClass;
struct IUsbDeviceClasses;
struct IUsbDeviceClassesStatics;
struct IUsbDeviceDescriptor;
struct IUsbDeviceStatics;
struct IUsbEndpointDescriptor;
struct IUsbEndpointDescriptorStatics;
struct IUsbInterface;
struct IUsbInterfaceDescriptor;
struct IUsbInterfaceDescriptorStatics;
struct IUsbInterfaceSetting;
struct IUsbInterruptInEndpointDescriptor;
struct IUsbInterruptInEventArgs;
struct IUsbInterruptInPipe;
struct IUsbInterruptOutEndpointDescriptor;
struct IUsbInterruptOutPipe;
struct IUsbSetupPacket;
struct IUsbSetupPacketFactory;
struct UsbBulkInEndpointDescriptor;
struct UsbBulkInPipe;
struct UsbBulkOutEndpointDescriptor;
struct UsbBulkOutPipe;
struct UsbConfiguration;
struct UsbConfigurationDescriptor;
struct UsbControlRequestType;
struct UsbDescriptor;
struct UsbDevice;
struct UsbDeviceClass;
struct UsbDeviceClasses;
struct UsbDeviceDescriptor;
struct UsbEndpointDescriptor;
struct UsbInterface;
struct UsbInterfaceDescriptor;
struct UsbInterfaceSetting;
struct UsbInterruptInEndpointDescriptor;
struct UsbInterruptInEventArgs;
struct UsbInterruptInPipe;
struct UsbInterruptOutEndpointDescriptor;
struct UsbInterruptOutPipe;
struct UsbSetupPacket;

}

namespace Windows::Devices::Usb {

template <typename T> struct impl_IUsbBulkInEndpointDescriptor;
template <typename T> struct impl_IUsbBulkInPipe;
template <typename T> struct impl_IUsbBulkOutEndpointDescriptor;
template <typename T> struct impl_IUsbBulkOutPipe;
template <typename T> struct impl_IUsbConfiguration;
template <typename T> struct impl_IUsbConfigurationDescriptor;
template <typename T> struct impl_IUsbConfigurationDescriptorStatics;
template <typename T> struct impl_IUsbControlRequestType;
template <typename T> struct impl_IUsbDescriptor;
template <typename T> struct impl_IUsbDevice;
template <typename T> struct impl_IUsbDeviceClass;
template <typename T> struct impl_IUsbDeviceClasses;
template <typename T> struct impl_IUsbDeviceClassesStatics;
template <typename T> struct impl_IUsbDeviceDescriptor;
template <typename T> struct impl_IUsbDeviceStatics;
template <typename T> struct impl_IUsbEndpointDescriptor;
template <typename T> struct impl_IUsbEndpointDescriptorStatics;
template <typename T> struct impl_IUsbInterface;
template <typename T> struct impl_IUsbInterfaceDescriptor;
template <typename T> struct impl_IUsbInterfaceDescriptorStatics;
template <typename T> struct impl_IUsbInterfaceSetting;
template <typename T> struct impl_IUsbInterruptInEndpointDescriptor;
template <typename T> struct impl_IUsbInterruptInEventArgs;
template <typename T> struct impl_IUsbInterruptInPipe;
template <typename T> struct impl_IUsbInterruptOutEndpointDescriptor;
template <typename T> struct impl_IUsbInterruptOutPipe;
template <typename T> struct impl_IUsbSetupPacket;
template <typename T> struct impl_IUsbSetupPacketFactory;

}

namespace Windows::Devices::Usb {

enum class UsbControlRecipient
{
    Device = 0,
    SpecifiedInterface = 1,
    Endpoint = 2,
    Other = 3,
    DefaultInterface = 4,
};

enum class UsbControlTransferType
{
    Standard = 0,
    Class = 1,
    Vendor = 2,
};

enum class UsbEndpointType
{
    Control = 0,
    Isochronous = 1,
    Bulk = 2,
    Interrupt = 3,
};

enum class UsbReadOptions : unsigned
{
    None = 0x0,
    AutoClearStall = 0x1,
    OverrideAutomaticBufferManagement = 0x2,
    IgnoreShortPacket = 0x4,
    AllowPartialReads = 0x8,
};

DEFINE_ENUM_FLAG_OPERATORS(UsbReadOptions)

enum class UsbTransferDirection
{
    Out = 0,
    In = 1,
};

enum class UsbWriteOptions : unsigned
{
    None = 0x0,
    AutoClearStall = 0x1,
    ShortPacketTerminate = 0x2,
};

DEFINE_ENUM_FLAG_OPERATORS(UsbWriteOptions)

}

}
