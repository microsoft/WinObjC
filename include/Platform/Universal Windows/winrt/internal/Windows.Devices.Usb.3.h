// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Usb.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Usb {

struct WINRT_EBO UsbBulkInEndpointDescriptor :
    Windows::Devices::Usb::IUsbBulkInEndpointDescriptor
{
    UsbBulkInEndpointDescriptor(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UsbBulkInPipe :
    Windows::Devices::Usb::IUsbBulkInPipe
{
    UsbBulkInPipe(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UsbBulkOutEndpointDescriptor :
    Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor
{
    UsbBulkOutEndpointDescriptor(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UsbBulkOutPipe :
    Windows::Devices::Usb::IUsbBulkOutPipe
{
    UsbBulkOutPipe(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UsbConfiguration :
    Windows::Devices::Usb::IUsbConfiguration
{
    UsbConfiguration(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UsbConfigurationDescriptor :
    Windows::Devices::Usb::IUsbConfigurationDescriptor
{
    UsbConfigurationDescriptor(std::nullptr_t) noexcept {}
    static bool TryParse(const Windows::Devices::Usb::UsbDescriptor & descriptor, Windows::Devices::Usb::UsbConfigurationDescriptor & parsed);
    static Windows::Devices::Usb::UsbConfigurationDescriptor Parse(const Windows::Devices::Usb::UsbDescriptor & descriptor);
};

struct WINRT_EBO UsbControlRequestType :
    Windows::Devices::Usb::IUsbControlRequestType
{
    UsbControlRequestType(std::nullptr_t) noexcept {}
    UsbControlRequestType();
};

struct WINRT_EBO UsbDescriptor :
    Windows::Devices::Usb::IUsbDescriptor
{
    UsbDescriptor(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UsbDevice :
    Windows::Devices::Usb::IUsbDevice
{
    UsbDevice(std::nullptr_t) noexcept {}
    static hstring GetDeviceSelector(uint32_t vendorId, uint32_t productId, GUID winUsbInterfaceClass);
    static hstring GetDeviceSelector(GUID winUsbInterfaceClass);
    static hstring GetDeviceSelector(uint32_t vendorId, uint32_t productId);
    static hstring GetDeviceClassSelector(const Windows::Devices::Usb::UsbDeviceClass & usbClass);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Usb::UsbDevice> FromIdAsync(hstring_view deviceId);
};

struct WINRT_EBO UsbDeviceClass :
    Windows::Devices::Usb::IUsbDeviceClass
{
    UsbDeviceClass(std::nullptr_t) noexcept {}
    UsbDeviceClass();
};

struct WINRT_EBO UsbDeviceClasses :
    Windows::Devices::Usb::IUsbDeviceClasses
{
    UsbDeviceClasses(std::nullptr_t) noexcept {}
    static Windows::Devices::Usb::UsbDeviceClass CdcControl();
    static Windows::Devices::Usb::UsbDeviceClass Physical();
    static Windows::Devices::Usb::UsbDeviceClass PersonalHealthcare();
    static Windows::Devices::Usb::UsbDeviceClass ActiveSync();
    static Windows::Devices::Usb::UsbDeviceClass PalmSync();
    static Windows::Devices::Usb::UsbDeviceClass DeviceFirmwareUpdate();
    static Windows::Devices::Usb::UsbDeviceClass Irda();
    static Windows::Devices::Usb::UsbDeviceClass Measurement();
    static Windows::Devices::Usb::UsbDeviceClass VendorSpecific();
};

struct WINRT_EBO UsbDeviceDescriptor :
    Windows::Devices::Usb::IUsbDeviceDescriptor
{
    UsbDeviceDescriptor(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UsbEndpointDescriptor :
    Windows::Devices::Usb::IUsbEndpointDescriptor
{
    UsbEndpointDescriptor(std::nullptr_t) noexcept {}
    static bool TryParse(const Windows::Devices::Usb::UsbDescriptor & descriptor, Windows::Devices::Usb::UsbEndpointDescriptor & parsed);
    static Windows::Devices::Usb::UsbEndpointDescriptor Parse(const Windows::Devices::Usb::UsbDescriptor & descriptor);
};

struct WINRT_EBO UsbInterface :
    Windows::Devices::Usb::IUsbInterface
{
    UsbInterface(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UsbInterfaceDescriptor :
    Windows::Devices::Usb::IUsbInterfaceDescriptor
{
    UsbInterfaceDescriptor(std::nullptr_t) noexcept {}
    static bool TryParse(const Windows::Devices::Usb::UsbDescriptor & descriptor, Windows::Devices::Usb::UsbInterfaceDescriptor & parsed);
    static Windows::Devices::Usb::UsbInterfaceDescriptor Parse(const Windows::Devices::Usb::UsbDescriptor & descriptor);
};

struct WINRT_EBO UsbInterfaceSetting :
    Windows::Devices::Usb::IUsbInterfaceSetting
{
    UsbInterfaceSetting(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UsbInterruptInEndpointDescriptor :
    Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor
{
    UsbInterruptInEndpointDescriptor(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UsbInterruptInEventArgs :
    Windows::Devices::Usb::IUsbInterruptInEventArgs
{
    UsbInterruptInEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UsbInterruptInPipe :
    Windows::Devices::Usb::IUsbInterruptInPipe
{
    UsbInterruptInPipe(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UsbInterruptOutEndpointDescriptor :
    Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor
{
    UsbInterruptOutEndpointDescriptor(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UsbInterruptOutPipe :
    Windows::Devices::Usb::IUsbInterruptOutPipe
{
    UsbInterruptOutPipe(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UsbSetupPacket :
    Windows::Devices::Usb::IUsbSetupPacket
{
    UsbSetupPacket(std::nullptr_t) noexcept {}
    UsbSetupPacket();
    UsbSetupPacket(const Windows::Storage::Streams::IBuffer & eightByteBuffer);
};

}

}
