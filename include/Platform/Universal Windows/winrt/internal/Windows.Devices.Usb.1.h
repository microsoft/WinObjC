// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Usb.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Storage.Streams.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Usb {

struct __declspec(uuid("3c6e4846-06cf-42a9-9dc2-971c1b14b6e3")) __declspec(novtable) IUsbBulkInEndpointDescriptor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxPacketSize(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_EndpointNumber(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Pipe(Windows::Devices::Usb::IUsbBulkInPipe ** value) = 0;
};

struct __declspec(uuid("f01d2d3b-4548-4d50-b326-d82cdabe1220")) __declspec(novtable) IUsbBulkInPipe : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxTransferSizeBytes(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_EndpointDescriptor(Windows::Devices::Usb::IUsbBulkInEndpointDescriptor ** value) = 0;
    virtual HRESULT __stdcall abi_ClearStallAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall put_ReadOptions(winrt::Windows::Devices::Usb::UsbReadOptions value) = 0;
    virtual HRESULT __stdcall get_ReadOptions(winrt::Windows::Devices::Usb::UsbReadOptions * value) = 0;
    virtual HRESULT __stdcall abi_FlushBuffer() = 0;
    virtual HRESULT __stdcall get_InputStream(Windows::Storage::Streams::IInputStream ** value) = 0;
};

struct __declspec(uuid("2820847a-ffee-4f60-9be1-956cac3ecb65")) __declspec(novtable) IUsbBulkOutEndpointDescriptor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxPacketSize(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_EndpointNumber(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Pipe(Windows::Devices::Usb::IUsbBulkOutPipe ** value) = 0;
};

struct __declspec(uuid("a8e9ee6e-0115-45aa-8b21-37b225bccee7")) __declspec(novtable) IUsbBulkOutPipe : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EndpointDescriptor(Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor ** value) = 0;
    virtual HRESULT __stdcall abi_ClearStallAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall put_WriteOptions(winrt::Windows::Devices::Usb::UsbWriteOptions value) = 0;
    virtual HRESULT __stdcall get_WriteOptions(winrt::Windows::Devices::Usb::UsbWriteOptions * value) = 0;
    virtual HRESULT __stdcall get_OutputStream(Windows::Storage::Streams::IOutputStream ** value) = 0;
};

struct __declspec(uuid("68177429-36a9-46d7-b873-fc689251ec30")) __declspec(novtable) IUsbConfiguration : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UsbInterfaces(Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterface> ** value) = 0;
    virtual HRESULT __stdcall get_ConfigurationDescriptor(Windows::Devices::Usb::IUsbConfigurationDescriptor ** value) = 0;
    virtual HRESULT __stdcall get_Descriptors(Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbDescriptor> ** value) = 0;
};

struct __declspec(uuid("f2176d92-b442-407a-8207-7d646c0385f3")) __declspec(novtable) IUsbConfigurationDescriptor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ConfigurationValue(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_MaxPowerMilliamps(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_SelfPowered(bool * value) = 0;
    virtual HRESULT __stdcall get_RemoteWakeup(bool * value) = 0;
};

struct __declspec(uuid("424ced93-e740-40a1-92bd-da120ea04914")) __declspec(novtable) IUsbConfigurationDescriptorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_TryParse(Windows::Devices::Usb::IUsbDescriptor * descriptor, Windows::Devices::Usb::IUsbConfigurationDescriptor ** parsed, bool * success) = 0;
    virtual HRESULT __stdcall abi_Parse(Windows::Devices::Usb::IUsbDescriptor * descriptor, Windows::Devices::Usb::IUsbConfigurationDescriptor ** parsed) = 0;
};

struct __declspec(uuid("8e9465a6-d73d-46de-94be-aae7f07c0f5c")) __declspec(novtable) IUsbControlRequestType : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Direction(winrt::Windows::Devices::Usb::UsbTransferDirection * value) = 0;
    virtual HRESULT __stdcall put_Direction(winrt::Windows::Devices::Usb::UsbTransferDirection value) = 0;
    virtual HRESULT __stdcall get_ControlTransferType(winrt::Windows::Devices::Usb::UsbControlTransferType * value) = 0;
    virtual HRESULT __stdcall put_ControlTransferType(winrt::Windows::Devices::Usb::UsbControlTransferType value) = 0;
    virtual HRESULT __stdcall get_Recipient(winrt::Windows::Devices::Usb::UsbControlRecipient * value) = 0;
    virtual HRESULT __stdcall put_Recipient(winrt::Windows::Devices::Usb::UsbControlRecipient value) = 0;
    virtual HRESULT __stdcall get_AsByte(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_AsByte(uint8_t value) = 0;
};

struct __declspec(uuid("0a89f216-5f9d-4874-8904-da9ad3f5528f")) __declspec(novtable) IUsbDescriptor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Length(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_DescriptorType(uint8_t * value) = 0;
    virtual HRESULT __stdcall abi_ReadDescriptorBuffer(Windows::Storage::Streams::IBuffer * buffer) = 0;
};

struct __declspec(uuid("5249b992-c456-44d5-ad5e-24f5a089f63b")) __declspec(novtable) IUsbDevice : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SendControlOutTransferAsync(Windows::Devices::Usb::IUsbSetupPacket * setupPacket, Windows::Storage::Streams::IBuffer * buffer, Windows::Foundation::IAsyncOperation<uint32_t> ** operation) = 0;
    virtual HRESULT __stdcall abi_SendControlOutTransferAsyncNoBuffer(Windows::Devices::Usb::IUsbSetupPacket * setupPacket, Windows::Foundation::IAsyncOperation<uint32_t> ** operation) = 0;
    virtual HRESULT __stdcall abi_SendControlInTransferAsync(Windows::Devices::Usb::IUsbSetupPacket * setupPacket, Windows::Storage::Streams::IBuffer * buffer, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> ** operation) = 0;
    virtual HRESULT __stdcall abi_SendControlInTransferAsyncNoBuffer(Windows::Devices::Usb::IUsbSetupPacket * setupPacket, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> ** operation) = 0;
    virtual HRESULT __stdcall get_DefaultInterface(Windows::Devices::Usb::IUsbInterface ** value) = 0;
    virtual HRESULT __stdcall get_DeviceDescriptor(Windows::Devices::Usb::IUsbDeviceDescriptor ** value) = 0;
    virtual HRESULT __stdcall get_Configuration(Windows::Devices::Usb::IUsbConfiguration ** value) = 0;
};

struct __declspec(uuid("051942f9-845e-47eb-b12a-38f2f617afe7")) __declspec(novtable) IUsbDeviceClass : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ClassCode(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_ClassCode(uint8_t value) = 0;
    virtual HRESULT __stdcall get_SubclassCode(Windows::Foundation::IReference<uint8_t> ** value) = 0;
    virtual HRESULT __stdcall put_SubclassCode(Windows::Foundation::IReference<uint8_t> * value) = 0;
    virtual HRESULT __stdcall get_ProtocolCode(Windows::Foundation::IReference<uint8_t> ** value) = 0;
    virtual HRESULT __stdcall put_ProtocolCode(Windows::Foundation::IReference<uint8_t> * value) = 0;
};

struct __declspec(uuid("686f955d-9b92-4b30-9781-c22c55ac35cb")) __declspec(novtable) IUsbDeviceClasses : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("b20b0527-c580-4599-a165-981b4fd03230")) __declspec(novtable) IUsbDeviceClassesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CdcControl(Windows::Devices::Usb::IUsbDeviceClass ** value) = 0;
    virtual HRESULT __stdcall get_Physical(Windows::Devices::Usb::IUsbDeviceClass ** value) = 0;
    virtual HRESULT __stdcall get_PersonalHealthcare(Windows::Devices::Usb::IUsbDeviceClass ** value) = 0;
    virtual HRESULT __stdcall get_ActiveSync(Windows::Devices::Usb::IUsbDeviceClass ** value) = 0;
    virtual HRESULT __stdcall get_PalmSync(Windows::Devices::Usb::IUsbDeviceClass ** value) = 0;
    virtual HRESULT __stdcall get_DeviceFirmwareUpdate(Windows::Devices::Usb::IUsbDeviceClass ** value) = 0;
    virtual HRESULT __stdcall get_Irda(Windows::Devices::Usb::IUsbDeviceClass ** value) = 0;
    virtual HRESULT __stdcall get_Measurement(Windows::Devices::Usb::IUsbDeviceClass ** value) = 0;
    virtual HRESULT __stdcall get_VendorSpecific(Windows::Devices::Usb::IUsbDeviceClass ** value) = 0;
};

struct __declspec(uuid("1f48d1f6-ba97-4322-b92c-b5b189216588")) __declspec(novtable) IUsbDeviceDescriptor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BcdUsb(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_MaxPacketSize0(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_VendorId(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_ProductId(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_BcdDeviceRevision(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_NumberOfConfigurations(uint8_t * value) = 0;
};

struct __declspec(uuid("066b85a2-09b7-4446-8502-6fe6dcaa7309")) __declspec(novtable) IUsbDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelector(uint32_t vendorId, uint32_t productId, GUID winUsbInterfaceClass, hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorGuidOnly(GUID winUsbInterfaceClass, hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorVidPidOnly(uint32_t vendorId, uint32_t productId, hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetDeviceClassSelector(Windows::Devices::Usb::IUsbDeviceClass * usbClass, hstring * value) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::Usb::UsbDevice> ** operation) = 0;
};

struct __declspec(uuid("6b4862d9-8df7-4b40-ac83-578f139f0575")) __declspec(novtable) IUsbEndpointDescriptor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EndpointNumber(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Direction(winrt::Windows::Devices::Usb::UsbTransferDirection * value) = 0;
    virtual HRESULT __stdcall get_EndpointType(winrt::Windows::Devices::Usb::UsbEndpointType * value) = 0;
    virtual HRESULT __stdcall get_AsBulkInEndpointDescriptor(Windows::Devices::Usb::IUsbBulkInEndpointDescriptor ** value) = 0;
    virtual HRESULT __stdcall get_AsInterruptInEndpointDescriptor(Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor ** value) = 0;
    virtual HRESULT __stdcall get_AsBulkOutEndpointDescriptor(Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor ** value) = 0;
    virtual HRESULT __stdcall get_AsInterruptOutEndpointDescriptor(Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor ** value) = 0;
};

struct __declspec(uuid("c890b201-9a6a-495e-a82c-295b9e708106")) __declspec(novtable) IUsbEndpointDescriptorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_TryParse(Windows::Devices::Usb::IUsbDescriptor * descriptor, Windows::Devices::Usb::IUsbEndpointDescriptor ** parsed, bool * success) = 0;
    virtual HRESULT __stdcall abi_Parse(Windows::Devices::Usb::IUsbDescriptor * descriptor, Windows::Devices::Usb::IUsbEndpointDescriptor ** parsed) = 0;
};

struct __declspec(uuid("a0322b95-7f47-48ab-a727-678c25be2112")) __declspec(novtable) IUsbInterface : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BulkInPipes(Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkInPipe> ** value) = 0;
    virtual HRESULT __stdcall get_InterruptInPipes(Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptInPipe> ** value) = 0;
    virtual HRESULT __stdcall get_BulkOutPipes(Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkOutPipe> ** value) = 0;
    virtual HRESULT __stdcall get_InterruptOutPipes(Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptOutPipe> ** value) = 0;
    virtual HRESULT __stdcall get_InterfaceSettings(Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterfaceSetting> ** value) = 0;
    virtual HRESULT __stdcall get_InterfaceNumber(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Descriptors(Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbDescriptor> ** value) = 0;
};

struct __declspec(uuid("199670c7-b7ee-4f90-8cd5-94a2e257598a")) __declspec(novtable) IUsbInterfaceDescriptor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ClassCode(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_SubclassCode(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_ProtocolCode(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_AlternateSettingNumber(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_InterfaceNumber(uint8_t * value) = 0;
};

struct __declspec(uuid("e34a9ff5-77d6-48b6-b0be-16c6422316fe")) __declspec(novtable) IUsbInterfaceDescriptorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_TryParse(Windows::Devices::Usb::IUsbDescriptor * descriptor, Windows::Devices::Usb::IUsbInterfaceDescriptor ** parsed, bool * success) = 0;
    virtual HRESULT __stdcall abi_Parse(Windows::Devices::Usb::IUsbDescriptor * descriptor, Windows::Devices::Usb::IUsbInterfaceDescriptor ** parsed) = 0;
};

struct __declspec(uuid("1827bba7-8da7-4af7-8f4c-7f3032e781f5")) __declspec(novtable) IUsbInterfaceSetting : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BulkInEndpoints(Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkInEndpointDescriptor> ** value) = 0;
    virtual HRESULT __stdcall get_InterruptInEndpoints(Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptInEndpointDescriptor> ** value) = 0;
    virtual HRESULT __stdcall get_BulkOutEndpoints(Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkOutEndpointDescriptor> ** value) = 0;
    virtual HRESULT __stdcall get_InterruptOutEndpoints(Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor> ** value) = 0;
    virtual HRESULT __stdcall get_Selected(bool * value) = 0;
    virtual HRESULT __stdcall abi_SelectSettingAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall get_InterfaceDescriptor(Windows::Devices::Usb::IUsbInterfaceDescriptor ** value) = 0;
    virtual HRESULT __stdcall get_Descriptors(Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbDescriptor> ** value) = 0;
};

struct __declspec(uuid("c0528967-c911-4c3a-86b2-419c2da89039")) __declspec(novtable) IUsbInterruptInEndpointDescriptor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxPacketSize(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_EndpointNumber(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Interval(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Pipe(Windows::Devices::Usb::IUsbInterruptInPipe ** value) = 0;
};

struct __declspec(uuid("b7b04092-1418-4936-8209-299cf5605583")) __declspec(novtable) IUsbInterruptInEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InterruptData(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("fa007116-84d7-48c7-8a3f-4c0b235f2ea6")) __declspec(novtable) IUsbInterruptInPipe : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EndpointDescriptor(Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor ** value) = 0;
    virtual HRESULT __stdcall abi_ClearStallAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall add_DataReceived(Windows::Foundation::TypedEventHandler<Windows::Devices::Usb::UsbInterruptInPipe, Windows::Devices::Usb::UsbInterruptInEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DataReceived(event_token token) = 0;
};

struct __declspec(uuid("cc9fed81-10ca-4533-952d-9e278341e80f")) __declspec(novtable) IUsbInterruptOutEndpointDescriptor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxPacketSize(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_EndpointNumber(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Interval(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Pipe(Windows::Devices::Usb::IUsbInterruptOutPipe ** value) = 0;
};

struct __declspec(uuid("e984c8a9-aaf9-49d0-b96c-f661ab4a7f95")) __declspec(novtable) IUsbInterruptOutPipe : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EndpointDescriptor(Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor ** value) = 0;
    virtual HRESULT __stdcall abi_ClearStallAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall put_WriteOptions(winrt::Windows::Devices::Usb::UsbWriteOptions value) = 0;
    virtual HRESULT __stdcall get_WriteOptions(winrt::Windows::Devices::Usb::UsbWriteOptions * value) = 0;
    virtual HRESULT __stdcall get_OutputStream(Windows::Storage::Streams::IOutputStream ** value) = 0;
};

struct __declspec(uuid("104ba132-c78f-4c51-b654-e49d02f2cb03")) __declspec(novtable) IUsbSetupPacket : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RequestType(Windows::Devices::Usb::IUsbControlRequestType ** value) = 0;
    virtual HRESULT __stdcall put_RequestType(Windows::Devices::Usb::IUsbControlRequestType * value) = 0;
    virtual HRESULT __stdcall get_Request(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_Request(uint8_t value) = 0;
    virtual HRESULT __stdcall get_Value(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Value(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Index(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Index(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Length(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Length(uint32_t value) = 0;
};

struct __declspec(uuid("c9257d50-1b2e-4a41-a2a7-338f0cef3c14")) __declspec(novtable) IUsbSetupPacketFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWithEightByteBuffer(Windows::Storage::Streams::IBuffer * eightByteBuffer, Windows::Devices::Usb::IUsbSetupPacket ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Usb::UsbBulkInEndpointDescriptor> { using default_interface = Windows::Devices::Usb::IUsbBulkInEndpointDescriptor; };
template <> struct traits<Windows::Devices::Usb::UsbBulkInPipe> { using default_interface = Windows::Devices::Usb::IUsbBulkInPipe; };
template <> struct traits<Windows::Devices::Usb::UsbBulkOutEndpointDescriptor> { using default_interface = Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor; };
template <> struct traits<Windows::Devices::Usb::UsbBulkOutPipe> { using default_interface = Windows::Devices::Usb::IUsbBulkOutPipe; };
template <> struct traits<Windows::Devices::Usb::UsbConfiguration> { using default_interface = Windows::Devices::Usb::IUsbConfiguration; };
template <> struct traits<Windows::Devices::Usb::UsbConfigurationDescriptor> { using default_interface = Windows::Devices::Usb::IUsbConfigurationDescriptor; };
template <> struct traits<Windows::Devices::Usb::UsbControlRequestType> { using default_interface = Windows::Devices::Usb::IUsbControlRequestType; };
template <> struct traits<Windows::Devices::Usb::UsbDescriptor> { using default_interface = Windows::Devices::Usb::IUsbDescriptor; };
template <> struct traits<Windows::Devices::Usb::UsbDevice> { using default_interface = Windows::Devices::Usb::IUsbDevice; };
template <> struct traits<Windows::Devices::Usb::UsbDeviceClass> { using default_interface = Windows::Devices::Usb::IUsbDeviceClass; };
template <> struct traits<Windows::Devices::Usb::UsbDeviceClasses> { using default_interface = Windows::Devices::Usb::IUsbDeviceClasses; };
template <> struct traits<Windows::Devices::Usb::UsbDeviceDescriptor> { using default_interface = Windows::Devices::Usb::IUsbDeviceDescriptor; };
template <> struct traits<Windows::Devices::Usb::UsbEndpointDescriptor> { using default_interface = Windows::Devices::Usb::IUsbEndpointDescriptor; };
template <> struct traits<Windows::Devices::Usb::UsbInterface> { using default_interface = Windows::Devices::Usb::IUsbInterface; };
template <> struct traits<Windows::Devices::Usb::UsbInterfaceDescriptor> { using default_interface = Windows::Devices::Usb::IUsbInterfaceDescriptor; };
template <> struct traits<Windows::Devices::Usb::UsbInterfaceSetting> { using default_interface = Windows::Devices::Usb::IUsbInterfaceSetting; };
template <> struct traits<Windows::Devices::Usb::UsbInterruptInEndpointDescriptor> { using default_interface = Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor; };
template <> struct traits<Windows::Devices::Usb::UsbInterruptInEventArgs> { using default_interface = Windows::Devices::Usb::IUsbInterruptInEventArgs; };
template <> struct traits<Windows::Devices::Usb::UsbInterruptInPipe> { using default_interface = Windows::Devices::Usb::IUsbInterruptInPipe; };
template <> struct traits<Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor> { using default_interface = Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor; };
template <> struct traits<Windows::Devices::Usb::UsbInterruptOutPipe> { using default_interface = Windows::Devices::Usb::IUsbInterruptOutPipe; };
template <> struct traits<Windows::Devices::Usb::UsbSetupPacket> { using default_interface = Windows::Devices::Usb::IUsbSetupPacket; };

}

namespace Windows::Devices::Usb {

template <typename D>
struct WINRT_EBO impl_IUsbBulkInEndpointDescriptor
{
    uint32_t MaxPacketSize() const;
    uint8_t EndpointNumber() const;
    Windows::Devices::Usb::UsbBulkInPipe Pipe() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbBulkInPipe
{
    uint32_t MaxTransferSizeBytes() const;
    Windows::Devices::Usb::UsbBulkInEndpointDescriptor EndpointDescriptor() const;
    Windows::Foundation::IAsyncAction ClearStallAsync() const;
    void ReadOptions(Windows::Devices::Usb::UsbReadOptions value) const;
    Windows::Devices::Usb::UsbReadOptions ReadOptions() const;
    void FlushBuffer() const;
    Windows::Storage::Streams::IInputStream InputStream() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbBulkOutEndpointDescriptor
{
    uint32_t MaxPacketSize() const;
    uint8_t EndpointNumber() const;
    Windows::Devices::Usb::UsbBulkOutPipe Pipe() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbBulkOutPipe
{
    Windows::Devices::Usb::UsbBulkOutEndpointDescriptor EndpointDescriptor() const;
    Windows::Foundation::IAsyncAction ClearStallAsync() const;
    void WriteOptions(Windows::Devices::Usb::UsbWriteOptions value) const;
    Windows::Devices::Usb::UsbWriteOptions WriteOptions() const;
    Windows::Storage::Streams::IOutputStream OutputStream() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbConfiguration
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterface> UsbInterfaces() const;
    Windows::Devices::Usb::UsbConfigurationDescriptor ConfigurationDescriptor() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbDescriptor> Descriptors() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbConfigurationDescriptor
{
    uint8_t ConfigurationValue() const;
    uint32_t MaxPowerMilliamps() const;
    bool SelfPowered() const;
    bool RemoteWakeup() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbConfigurationDescriptorStatics
{
    bool TryParse(const Windows::Devices::Usb::UsbDescriptor & descriptor, Windows::Devices::Usb::UsbConfigurationDescriptor & parsed) const;
    Windows::Devices::Usb::UsbConfigurationDescriptor Parse(const Windows::Devices::Usb::UsbDescriptor & descriptor) const;
};

template <typename D>
struct WINRT_EBO impl_IUsbControlRequestType
{
    Windows::Devices::Usb::UsbTransferDirection Direction() const;
    void Direction(Windows::Devices::Usb::UsbTransferDirection value) const;
    Windows::Devices::Usb::UsbControlTransferType ControlTransferType() const;
    void ControlTransferType(Windows::Devices::Usb::UsbControlTransferType value) const;
    Windows::Devices::Usb::UsbControlRecipient Recipient() const;
    void Recipient(Windows::Devices::Usb::UsbControlRecipient value) const;
    uint8_t AsByte() const;
    void AsByte(uint8_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IUsbDescriptor
{
    uint8_t Length() const;
    uint8_t DescriptorType() const;
    void ReadDescriptorBuffer(const Windows::Storage::Streams::IBuffer & buffer) const;
};

template <typename D>
struct WINRT_EBO impl_IUsbDevice
{
    Windows::Foundation::IAsyncOperation<uint32_t> SendControlOutTransferAsync(const Windows::Devices::Usb::UsbSetupPacket & setupPacket, const Windows::Storage::Streams::IBuffer & buffer) const;
    Windows::Foundation::IAsyncOperation<uint32_t> SendControlOutTransferAsync(const Windows::Devices::Usb::UsbSetupPacket & setupPacket) const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> SendControlInTransferAsync(const Windows::Devices::Usb::UsbSetupPacket & setupPacket, const Windows::Storage::Streams::IBuffer & buffer) const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> SendControlInTransferAsync(const Windows::Devices::Usb::UsbSetupPacket & setupPacket) const;
    Windows::Devices::Usb::UsbInterface DefaultInterface() const;
    Windows::Devices::Usb::UsbDeviceDescriptor DeviceDescriptor() const;
    Windows::Devices::Usb::UsbConfiguration Configuration() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbDeviceClass
{
    uint8_t ClassCode() const;
    void ClassCode(uint8_t value) const;
    Windows::Foundation::IReference<uint8_t> SubclassCode() const;
    void SubclassCode(const optional<uint8_t> & value) const;
    Windows::Foundation::IReference<uint8_t> ProtocolCode() const;
    void ProtocolCode(const optional<uint8_t> & value) const;
};

template <typename D>
struct WINRT_EBO impl_IUsbDeviceClasses
{
};

template <typename D>
struct WINRT_EBO impl_IUsbDeviceClassesStatics
{
    Windows::Devices::Usb::UsbDeviceClass CdcControl() const;
    Windows::Devices::Usb::UsbDeviceClass Physical() const;
    Windows::Devices::Usb::UsbDeviceClass PersonalHealthcare() const;
    Windows::Devices::Usb::UsbDeviceClass ActiveSync() const;
    Windows::Devices::Usb::UsbDeviceClass PalmSync() const;
    Windows::Devices::Usb::UsbDeviceClass DeviceFirmwareUpdate() const;
    Windows::Devices::Usb::UsbDeviceClass Irda() const;
    Windows::Devices::Usb::UsbDeviceClass Measurement() const;
    Windows::Devices::Usb::UsbDeviceClass VendorSpecific() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbDeviceDescriptor
{
    uint32_t BcdUsb() const;
    uint8_t MaxPacketSize0() const;
    uint32_t VendorId() const;
    uint32_t ProductId() const;
    uint32_t BcdDeviceRevision() const;
    uint8_t NumberOfConfigurations() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbDeviceStatics
{
    hstring GetDeviceSelector(uint32_t vendorId, uint32_t productId, GUID winUsbInterfaceClass) const;
    hstring GetDeviceSelector(GUID winUsbInterfaceClass) const;
    hstring GetDeviceSelector(uint32_t vendorId, uint32_t productId) const;
    hstring GetDeviceClassSelector(const Windows::Devices::Usb::UsbDeviceClass & usbClass) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Usb::UsbDevice> FromIdAsync(hstring_view deviceId) const;
};

template <typename D>
struct WINRT_EBO impl_IUsbEndpointDescriptor
{
    uint8_t EndpointNumber() const;
    Windows::Devices::Usb::UsbTransferDirection Direction() const;
    Windows::Devices::Usb::UsbEndpointType EndpointType() const;
    Windows::Devices::Usb::UsbBulkInEndpointDescriptor AsBulkInEndpointDescriptor() const;
    Windows::Devices::Usb::UsbInterruptInEndpointDescriptor AsInterruptInEndpointDescriptor() const;
    Windows::Devices::Usb::UsbBulkOutEndpointDescriptor AsBulkOutEndpointDescriptor() const;
    Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor AsInterruptOutEndpointDescriptor() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbEndpointDescriptorStatics
{
    bool TryParse(const Windows::Devices::Usb::UsbDescriptor & descriptor, Windows::Devices::Usb::UsbEndpointDescriptor & parsed) const;
    Windows::Devices::Usb::UsbEndpointDescriptor Parse(const Windows::Devices::Usb::UsbDescriptor & descriptor) const;
};

template <typename D>
struct WINRT_EBO impl_IUsbInterface
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkInPipe> BulkInPipes() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptInPipe> InterruptInPipes() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkOutPipe> BulkOutPipes() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptOutPipe> InterruptOutPipes() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterfaceSetting> InterfaceSettings() const;
    uint8_t InterfaceNumber() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbDescriptor> Descriptors() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbInterfaceDescriptor
{
    uint8_t ClassCode() const;
    uint8_t SubclassCode() const;
    uint8_t ProtocolCode() const;
    uint8_t AlternateSettingNumber() const;
    uint8_t InterfaceNumber() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbInterfaceDescriptorStatics
{
    bool TryParse(const Windows::Devices::Usb::UsbDescriptor & descriptor, Windows::Devices::Usb::UsbInterfaceDescriptor & parsed) const;
    Windows::Devices::Usb::UsbInterfaceDescriptor Parse(const Windows::Devices::Usb::UsbDescriptor & descriptor) const;
};

template <typename D>
struct WINRT_EBO impl_IUsbInterfaceSetting
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkInEndpointDescriptor> BulkInEndpoints() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptInEndpointDescriptor> InterruptInEndpoints() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkOutEndpointDescriptor> BulkOutEndpoints() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor> InterruptOutEndpoints() const;
    bool Selected() const;
    Windows::Foundation::IAsyncAction SelectSettingAsync() const;
    Windows::Devices::Usb::UsbInterfaceDescriptor InterfaceDescriptor() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbDescriptor> Descriptors() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbInterruptInEndpointDescriptor
{
    uint32_t MaxPacketSize() const;
    uint8_t EndpointNumber() const;
    Windows::Foundation::TimeSpan Interval() const;
    Windows::Devices::Usb::UsbInterruptInPipe Pipe() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbInterruptInEventArgs
{
    Windows::Storage::Streams::IBuffer InterruptData() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbInterruptInPipe
{
    Windows::Devices::Usb::UsbInterruptInEndpointDescriptor EndpointDescriptor() const;
    Windows::Foundation::IAsyncAction ClearStallAsync() const;
    event_token DataReceived(const Windows::Foundation::TypedEventHandler<Windows::Devices::Usb::UsbInterruptInPipe, Windows::Devices::Usb::UsbInterruptInEventArgs> & handler) const;
    using DataReceived_revoker = event_revoker<IUsbInterruptInPipe>;
    DataReceived_revoker DataReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Usb::UsbInterruptInPipe, Windows::Devices::Usb::UsbInterruptInEventArgs> & handler) const;
    void DataReceived(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IUsbInterruptOutEndpointDescriptor
{
    uint32_t MaxPacketSize() const;
    uint8_t EndpointNumber() const;
    Windows::Foundation::TimeSpan Interval() const;
    Windows::Devices::Usb::UsbInterruptOutPipe Pipe() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbInterruptOutPipe
{
    Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor EndpointDescriptor() const;
    Windows::Foundation::IAsyncAction ClearStallAsync() const;
    void WriteOptions(Windows::Devices::Usb::UsbWriteOptions value) const;
    Windows::Devices::Usb::UsbWriteOptions WriteOptions() const;
    Windows::Storage::Streams::IOutputStream OutputStream() const;
};

template <typename D>
struct WINRT_EBO impl_IUsbSetupPacket
{
    Windows::Devices::Usb::UsbControlRequestType RequestType() const;
    void RequestType(const Windows::Devices::Usb::UsbControlRequestType & value) const;
    uint8_t Request() const;
    void Request(uint8_t value) const;
    uint32_t Value() const;
    void Value(uint32_t value) const;
    uint32_t Index() const;
    void Index(uint32_t value) const;
    uint32_t Length() const;
    void Length(uint32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IUsbSetupPacketFactory
{
    Windows::Devices::Usb::UsbSetupPacket CreateWithEightByteBuffer(const Windows::Storage::Streams::IBuffer & eightByteBuffer) const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Usb::IUsbBulkInEndpointDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::IUsbBulkInEndpointDescriptor;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbBulkInEndpointDescriptor<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbBulkInPipe>
{
    using abi = ABI::Windows::Devices::Usb::IUsbBulkInPipe;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbBulkInPipe<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbBulkOutEndpointDescriptor<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbBulkOutPipe>
{
    using abi = ABI::Windows::Devices::Usb::IUsbBulkOutPipe;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbBulkOutPipe<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbConfiguration>
{
    using abi = ABI::Windows::Devices::Usb::IUsbConfiguration;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbConfiguration<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbConfigurationDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::IUsbConfigurationDescriptor;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbConfigurationDescriptor<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbConfigurationDescriptorStatics>
{
    using abi = ABI::Windows::Devices::Usb::IUsbConfigurationDescriptorStatics;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbConfigurationDescriptorStatics<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbControlRequestType>
{
    using abi = ABI::Windows::Devices::Usb::IUsbControlRequestType;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbControlRequestType<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::IUsbDescriptor;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbDescriptor<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbDevice>
{
    using abi = ABI::Windows::Devices::Usb::IUsbDevice;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbDevice<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbDeviceClass>
{
    using abi = ABI::Windows::Devices::Usb::IUsbDeviceClass;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbDeviceClass<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbDeviceClasses>
{
    using abi = ABI::Windows::Devices::Usb::IUsbDeviceClasses;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbDeviceClasses<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbDeviceClassesStatics>
{
    using abi = ABI::Windows::Devices::Usb::IUsbDeviceClassesStatics;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbDeviceClassesStatics<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbDeviceDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::IUsbDeviceDescriptor;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbDeviceDescriptor<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbDeviceStatics>
{
    using abi = ABI::Windows::Devices::Usb::IUsbDeviceStatics;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbDeviceStatics<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbEndpointDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::IUsbEndpointDescriptor;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbEndpointDescriptor<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbEndpointDescriptorStatics>
{
    using abi = ABI::Windows::Devices::Usb::IUsbEndpointDescriptorStatics;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbEndpointDescriptorStatics<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbInterface>
{
    using abi = ABI::Windows::Devices::Usb::IUsbInterface;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbInterface<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbInterfaceDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::IUsbInterfaceDescriptor;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbInterfaceDescriptor<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbInterfaceDescriptorStatics>
{
    using abi = ABI::Windows::Devices::Usb::IUsbInterfaceDescriptorStatics;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbInterfaceDescriptorStatics<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbInterfaceSetting>
{
    using abi = ABI::Windows::Devices::Usb::IUsbInterfaceSetting;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbInterfaceSetting<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbInterruptInEndpointDescriptor<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbInterruptInEventArgs>
{
    using abi = ABI::Windows::Devices::Usb::IUsbInterruptInEventArgs;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbInterruptInEventArgs<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbInterruptInPipe>
{
    using abi = ABI::Windows::Devices::Usb::IUsbInterruptInPipe;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbInterruptInPipe<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbInterruptOutEndpointDescriptor<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbInterruptOutPipe>
{
    using abi = ABI::Windows::Devices::Usb::IUsbInterruptOutPipe;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbInterruptOutPipe<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbSetupPacket>
{
    using abi = ABI::Windows::Devices::Usb::IUsbSetupPacket;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbSetupPacket<D>;
};

template <> struct traits<Windows::Devices::Usb::IUsbSetupPacketFactory>
{
    using abi = ABI::Windows::Devices::Usb::IUsbSetupPacketFactory;
    template <typename D> using consume = Windows::Devices::Usb::impl_IUsbSetupPacketFactory<D>;
};

template <> struct traits<Windows::Devices::Usb::UsbBulkInEndpointDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::UsbBulkInEndpointDescriptor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbBulkInEndpointDescriptor"; }
};

template <> struct traits<Windows::Devices::Usb::UsbBulkInPipe>
{
    using abi = ABI::Windows::Devices::Usb::UsbBulkInPipe;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbBulkInPipe"; }
};

template <> struct traits<Windows::Devices::Usb::UsbBulkOutEndpointDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::UsbBulkOutEndpointDescriptor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbBulkOutEndpointDescriptor"; }
};

template <> struct traits<Windows::Devices::Usb::UsbBulkOutPipe>
{
    using abi = ABI::Windows::Devices::Usb::UsbBulkOutPipe;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbBulkOutPipe"; }
};

template <> struct traits<Windows::Devices::Usb::UsbConfiguration>
{
    using abi = ABI::Windows::Devices::Usb::UsbConfiguration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbConfiguration"; }
};

template <> struct traits<Windows::Devices::Usb::UsbConfigurationDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::UsbConfigurationDescriptor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbConfigurationDescriptor"; }
};

template <> struct traits<Windows::Devices::Usb::UsbControlRequestType>
{
    using abi = ABI::Windows::Devices::Usb::UsbControlRequestType;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbControlRequestType"; }
};

template <> struct traits<Windows::Devices::Usb::UsbDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::UsbDescriptor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbDescriptor"; }
};

template <> struct traits<Windows::Devices::Usb::UsbDevice>
{
    using abi = ABI::Windows::Devices::Usb::UsbDevice;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbDevice"; }
};

template <> struct traits<Windows::Devices::Usb::UsbDeviceClass>
{
    using abi = ABI::Windows::Devices::Usb::UsbDeviceClass;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbDeviceClass"; }
};

template <> struct traits<Windows::Devices::Usb::UsbDeviceClasses>
{
    using abi = ABI::Windows::Devices::Usb::UsbDeviceClasses;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbDeviceClasses"; }
};

template <> struct traits<Windows::Devices::Usb::UsbDeviceDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::UsbDeviceDescriptor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbDeviceDescriptor"; }
};

template <> struct traits<Windows::Devices::Usb::UsbEndpointDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::UsbEndpointDescriptor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbEndpointDescriptor"; }
};

template <> struct traits<Windows::Devices::Usb::UsbInterface>
{
    using abi = ABI::Windows::Devices::Usb::UsbInterface;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbInterface"; }
};

template <> struct traits<Windows::Devices::Usb::UsbInterfaceDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::UsbInterfaceDescriptor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbInterfaceDescriptor"; }
};

template <> struct traits<Windows::Devices::Usb::UsbInterfaceSetting>
{
    using abi = ABI::Windows::Devices::Usb::UsbInterfaceSetting;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbInterfaceSetting"; }
};

template <> struct traits<Windows::Devices::Usb::UsbInterruptInEndpointDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::UsbInterruptInEndpointDescriptor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbInterruptInEndpointDescriptor"; }
};

template <> struct traits<Windows::Devices::Usb::UsbInterruptInEventArgs>
{
    using abi = ABI::Windows::Devices::Usb::UsbInterruptInEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbInterruptInEventArgs"; }
};

template <> struct traits<Windows::Devices::Usb::UsbInterruptInPipe>
{
    using abi = ABI::Windows::Devices::Usb::UsbInterruptInPipe;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbInterruptInPipe"; }
};

template <> struct traits<Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor>
{
    using abi = ABI::Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbInterruptOutEndpointDescriptor"; }
};

template <> struct traits<Windows::Devices::Usb::UsbInterruptOutPipe>
{
    using abi = ABI::Windows::Devices::Usb::UsbInterruptOutPipe;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbInterruptOutPipe"; }
};

template <> struct traits<Windows::Devices::Usb::UsbSetupPacket>
{
    using abi = ABI::Windows::Devices::Usb::UsbSetupPacket;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Usb.UsbSetupPacket"; }
};

}

}
