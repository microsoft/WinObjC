// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Devices.Usb.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbBulkInEndpointDescriptor> : produce_base<D, Windows::Devices::Usb::IUsbBulkInEndpointDescriptor>
{
    HRESULT __stdcall get_MaxPacketSize(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPacketSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndpointNumber(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndpointNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pipe(impl::abi_arg_out<Windows::Devices::Usb::IUsbBulkInPipe> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pipe());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbBulkInPipe> : produce_base<D, Windows::Devices::Usb::IUsbBulkInPipe>
{
    HRESULT __stdcall get_MaxTransferSizeBytes(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxTransferSizeBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndpointDescriptor(impl::abi_arg_out<Windows::Devices::Usb::IUsbBulkInEndpointDescriptor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndpointDescriptor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearStallAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ClearStallAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ReadOptions(Windows::Devices::Usb::UsbReadOptions value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReadOptions(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReadOptions(Windows::Devices::Usb::UsbReadOptions * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadOptions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FlushBuffer() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FlushBuffer();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InputStream(impl::abi_arg_out<Windows::Storage::Streams::IInputStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InputStream());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor> : produce_base<D, Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor>
{
    HRESULT __stdcall get_MaxPacketSize(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPacketSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndpointNumber(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndpointNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pipe(impl::abi_arg_out<Windows::Devices::Usb::IUsbBulkOutPipe> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pipe());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbBulkOutPipe> : produce_base<D, Windows::Devices::Usb::IUsbBulkOutPipe>
{
    HRESULT __stdcall get_EndpointDescriptor(impl::abi_arg_out<Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndpointDescriptor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearStallAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ClearStallAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_WriteOptions(Windows::Devices::Usb::UsbWriteOptions value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteOptions(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WriteOptions(Windows::Devices::Usb::UsbWriteOptions * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WriteOptions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutputStream(impl::abi_arg_out<Windows::Storage::Streams::IOutputStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutputStream());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbConfiguration> : produce_base<D, Windows::Devices::Usb::IUsbConfiguration>
{
    HRESULT __stdcall get_UsbInterfaces(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterface>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UsbInterfaces());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConfigurationDescriptor(impl::abi_arg_out<Windows::Devices::Usb::IUsbConfigurationDescriptor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConfigurationDescriptor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Descriptors(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbDescriptor>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Descriptors());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbConfigurationDescriptor> : produce_base<D, Windows::Devices::Usb::IUsbConfigurationDescriptor>
{
    HRESULT __stdcall get_ConfigurationValue(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConfigurationValue());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxPowerMilliamps(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPowerMilliamps());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SelfPowered(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelfPowered());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemoteWakeup(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteWakeup());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbConfigurationDescriptorStatics> : produce_base<D, Windows::Devices::Usb::IUsbConfigurationDescriptorStatics>
{
    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<Windows::Devices::Usb::IUsbDescriptor> descriptor, impl::abi_arg_out<Windows::Devices::Usb::IUsbConfigurationDescriptor> parsed, bool * success) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *success = detach_abi(this->shim().TryParse(*reinterpret_cast<const Windows::Devices::Usb::UsbDescriptor *>(&descriptor), *parsed));
            return S_OK;
        }
        catch (...)
        {
            *parsed = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Parse(impl::abi_arg_in<Windows::Devices::Usb::IUsbDescriptor> descriptor, impl::abi_arg_out<Windows::Devices::Usb::IUsbConfigurationDescriptor> parsed) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *parsed = detach_abi(this->shim().Parse(*reinterpret_cast<const Windows::Devices::Usb::UsbDescriptor *>(&descriptor)));
            return S_OK;
        }
        catch (...)
        {
            *parsed = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbControlRequestType> : produce_base<D, Windows::Devices::Usb::IUsbControlRequestType>
{
    HRESULT __stdcall get_Direction(Windows::Devices::Usb::UsbTransferDirection * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Direction());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Direction(Windows::Devices::Usb::UsbTransferDirection value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Direction(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ControlTransferType(Windows::Devices::Usb::UsbControlTransferType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ControlTransferType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ControlTransferType(Windows::Devices::Usb::UsbControlTransferType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ControlTransferType(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Recipient(Windows::Devices::Usb::UsbControlRecipient * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Recipient());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Recipient(Windows::Devices::Usb::UsbControlRecipient value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Recipient(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AsByte(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AsByte());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AsByte(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AsByte(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbDescriptor> : produce_base<D, Windows::Devices::Usb::IUsbDescriptor>
{
    HRESULT __stdcall get_Length(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Length());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DescriptorType(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DescriptorType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadDescriptorBuffer(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReadDescriptorBuffer(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbDevice> : produce_base<D, Windows::Devices::Usb::IUsbDevice>
{
    HRESULT __stdcall abi_SendControlOutTransferAsync(impl::abi_arg_in<Windows::Devices::Usb::IUsbSetupPacket> setupPacket, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<uint32_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SendControlOutTransferAsync(*reinterpret_cast<const Windows::Devices::Usb::UsbSetupPacket *>(&setupPacket), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendControlOutTransferAsyncNoBuffer(impl::abi_arg_in<Windows::Devices::Usb::IUsbSetupPacket> setupPacket, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<uint32_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SendControlOutTransferAsync(*reinterpret_cast<const Windows::Devices::Usb::UsbSetupPacket *>(&setupPacket)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendControlInTransferAsync(impl::abi_arg_in<Windows::Devices::Usb::IUsbSetupPacket> setupPacket, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SendControlInTransferAsync(*reinterpret_cast<const Windows::Devices::Usb::UsbSetupPacket *>(&setupPacket), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendControlInTransferAsyncNoBuffer(impl::abi_arg_in<Windows::Devices::Usb::IUsbSetupPacket> setupPacket, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SendControlInTransferAsync(*reinterpret_cast<const Windows::Devices::Usb::UsbSetupPacket *>(&setupPacket)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultInterface(impl::abi_arg_out<Windows::Devices::Usb::IUsbInterface> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultInterface());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceDescriptor(impl::abi_arg_out<Windows::Devices::Usb::IUsbDeviceDescriptor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceDescriptor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Configuration(impl::abi_arg_out<Windows::Devices::Usb::IUsbConfiguration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Configuration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbDeviceClass> : produce_base<D, Windows::Devices::Usb::IUsbDeviceClass>
{
    HRESULT __stdcall get_ClassCode(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClassCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ClassCode(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClassCode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SubclassCode(impl::abi_arg_out<Windows::Foundation::IReference<uint8_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SubclassCode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SubclassCode(impl::abi_arg_in<Windows::Foundation::IReference<uint8_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SubclassCode(*reinterpret_cast<const Windows::Foundation::IReference<uint8_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProtocolCode(impl::abi_arg_out<Windows::Foundation::IReference<uint8_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProtocolCode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProtocolCode(impl::abi_arg_in<Windows::Foundation::IReference<uint8_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProtocolCode(*reinterpret_cast<const Windows::Foundation::IReference<uint8_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbDeviceClasses> : produce_base<D, Windows::Devices::Usb::IUsbDeviceClasses>
{};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbDeviceClassesStatics> : produce_base<D, Windows::Devices::Usb::IUsbDeviceClassesStatics>
{
    HRESULT __stdcall get_CdcControl(impl::abi_arg_out<Windows::Devices::Usb::IUsbDeviceClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CdcControl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Physical(impl::abi_arg_out<Windows::Devices::Usb::IUsbDeviceClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Physical());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PersonalHealthcare(impl::abi_arg_out<Windows::Devices::Usb::IUsbDeviceClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PersonalHealthcare());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActiveSync(impl::abi_arg_out<Windows::Devices::Usb::IUsbDeviceClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActiveSync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PalmSync(impl::abi_arg_out<Windows::Devices::Usb::IUsbDeviceClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PalmSync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceFirmwareUpdate(impl::abi_arg_out<Windows::Devices::Usb::IUsbDeviceClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceFirmwareUpdate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Irda(impl::abi_arg_out<Windows::Devices::Usb::IUsbDeviceClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Irda());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Measurement(impl::abi_arg_out<Windows::Devices::Usb::IUsbDeviceClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Measurement());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VendorSpecific(impl::abi_arg_out<Windows::Devices::Usb::IUsbDeviceClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VendorSpecific());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbDeviceDescriptor> : produce_base<D, Windows::Devices::Usb::IUsbDeviceDescriptor>
{
    HRESULT __stdcall get_BcdUsb(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BcdUsb());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxPacketSize0(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPacketSize0());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VendorId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VendorId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProductId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProductId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BcdDeviceRevision(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BcdDeviceRevision());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfConfigurations(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NumberOfConfigurations());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbDeviceStatics> : produce_base<D, Windows::Devices::Usb::IUsbDeviceStatics>
{
    HRESULT __stdcall abi_GetDeviceSelector(uint32_t vendorId, uint32_t productId, GUID winUsbInterfaceClass, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector(vendorId, productId, winUsbInterfaceClass));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorGuidOnly(GUID winUsbInterfaceClass, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector(winUsbInterfaceClass));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorVidPidOnly(uint32_t vendorId, uint32_t productId, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector(vendorId, productId));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceClassSelector(impl::abi_arg_in<Windows::Devices::Usb::IUsbDeviceClass> usbClass, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceClassSelector(*reinterpret_cast<const Windows::Devices::Usb::UsbDeviceClass *>(&usbClass)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Usb::UsbDevice>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbEndpointDescriptor> : produce_base<D, Windows::Devices::Usb::IUsbEndpointDescriptor>
{
    HRESULT __stdcall get_EndpointNumber(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndpointNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Direction(Windows::Devices::Usb::UsbTransferDirection * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Direction());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndpointType(Windows::Devices::Usb::UsbEndpointType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndpointType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AsBulkInEndpointDescriptor(impl::abi_arg_out<Windows::Devices::Usb::IUsbBulkInEndpointDescriptor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AsBulkInEndpointDescriptor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AsInterruptInEndpointDescriptor(impl::abi_arg_out<Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AsInterruptInEndpointDescriptor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AsBulkOutEndpointDescriptor(impl::abi_arg_out<Windows::Devices::Usb::IUsbBulkOutEndpointDescriptor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AsBulkOutEndpointDescriptor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AsInterruptOutEndpointDescriptor(impl::abi_arg_out<Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AsInterruptOutEndpointDescriptor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbEndpointDescriptorStatics> : produce_base<D, Windows::Devices::Usb::IUsbEndpointDescriptorStatics>
{
    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<Windows::Devices::Usb::IUsbDescriptor> descriptor, impl::abi_arg_out<Windows::Devices::Usb::IUsbEndpointDescriptor> parsed, bool * success) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *success = detach_abi(this->shim().TryParse(*reinterpret_cast<const Windows::Devices::Usb::UsbDescriptor *>(&descriptor), *parsed));
            return S_OK;
        }
        catch (...)
        {
            *parsed = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Parse(impl::abi_arg_in<Windows::Devices::Usb::IUsbDescriptor> descriptor, impl::abi_arg_out<Windows::Devices::Usb::IUsbEndpointDescriptor> parsed) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *parsed = detach_abi(this->shim().Parse(*reinterpret_cast<const Windows::Devices::Usb::UsbDescriptor *>(&descriptor)));
            return S_OK;
        }
        catch (...)
        {
            *parsed = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbInterface> : produce_base<D, Windows::Devices::Usb::IUsbInterface>
{
    HRESULT __stdcall get_BulkInPipes(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkInPipe>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BulkInPipes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InterruptInPipes(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptInPipe>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InterruptInPipes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BulkOutPipes(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkOutPipe>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BulkOutPipes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InterruptOutPipes(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptOutPipe>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InterruptOutPipes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InterfaceSettings(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterfaceSetting>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InterfaceSettings());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InterfaceNumber(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InterfaceNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Descriptors(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbDescriptor>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Descriptors());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbInterfaceDescriptor> : produce_base<D, Windows::Devices::Usb::IUsbInterfaceDescriptor>
{
    HRESULT __stdcall get_ClassCode(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClassCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SubclassCode(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SubclassCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProtocolCode(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProtocolCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlternateSettingNumber(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlternateSettingNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InterfaceNumber(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InterfaceNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbInterfaceDescriptorStatics> : produce_base<D, Windows::Devices::Usb::IUsbInterfaceDescriptorStatics>
{
    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<Windows::Devices::Usb::IUsbDescriptor> descriptor, impl::abi_arg_out<Windows::Devices::Usb::IUsbInterfaceDescriptor> parsed, bool * success) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *success = detach_abi(this->shim().TryParse(*reinterpret_cast<const Windows::Devices::Usb::UsbDescriptor *>(&descriptor), *parsed));
            return S_OK;
        }
        catch (...)
        {
            *parsed = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Parse(impl::abi_arg_in<Windows::Devices::Usb::IUsbDescriptor> descriptor, impl::abi_arg_out<Windows::Devices::Usb::IUsbInterfaceDescriptor> parsed) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *parsed = detach_abi(this->shim().Parse(*reinterpret_cast<const Windows::Devices::Usb::UsbDescriptor *>(&descriptor)));
            return S_OK;
        }
        catch (...)
        {
            *parsed = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbInterfaceSetting> : produce_base<D, Windows::Devices::Usb::IUsbInterfaceSetting>
{
    HRESULT __stdcall get_BulkInEndpoints(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkInEndpointDescriptor>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BulkInEndpoints());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InterruptInEndpoints(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptInEndpointDescriptor>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InterruptInEndpoints());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BulkOutEndpoints(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkOutEndpointDescriptor>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BulkOutEndpoints());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InterruptOutEndpoints(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InterruptOutEndpoints());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Selected(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Selected());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SelectSettingAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SelectSettingAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InterfaceDescriptor(impl::abi_arg_out<Windows::Devices::Usb::IUsbInterfaceDescriptor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InterfaceDescriptor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Descriptors(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbDescriptor>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Descriptors());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor> : produce_base<D, Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor>
{
    HRESULT __stdcall get_MaxPacketSize(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPacketSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndpointNumber(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndpointNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Interval(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Interval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pipe(impl::abi_arg_out<Windows::Devices::Usb::IUsbInterruptInPipe> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pipe());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbInterruptInEventArgs> : produce_base<D, Windows::Devices::Usb::IUsbInterruptInEventArgs>
{
    HRESULT __stdcall get_InterruptData(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InterruptData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbInterruptInPipe> : produce_base<D, Windows::Devices::Usb::IUsbInterruptInPipe>
{
    HRESULT __stdcall get_EndpointDescriptor(impl::abi_arg_out<Windows::Devices::Usb::IUsbInterruptInEndpointDescriptor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndpointDescriptor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearStallAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ClearStallAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DataReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Usb::UsbInterruptInPipe, Windows::Devices::Usb::UsbInterruptInEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DataReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Usb::UsbInterruptInPipe, Windows::Devices::Usb::UsbInterruptInEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DataReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor> : produce_base<D, Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor>
{
    HRESULT __stdcall get_MaxPacketSize(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPacketSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndpointNumber(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndpointNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Interval(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Interval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pipe(impl::abi_arg_out<Windows::Devices::Usb::IUsbInterruptOutPipe> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pipe());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbInterruptOutPipe> : produce_base<D, Windows::Devices::Usb::IUsbInterruptOutPipe>
{
    HRESULT __stdcall get_EndpointDescriptor(impl::abi_arg_out<Windows::Devices::Usb::IUsbInterruptOutEndpointDescriptor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndpointDescriptor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearStallAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ClearStallAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_WriteOptions(Windows::Devices::Usb::UsbWriteOptions value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteOptions(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WriteOptions(Windows::Devices::Usb::UsbWriteOptions * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WriteOptions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutputStream(impl::abi_arg_out<Windows::Storage::Streams::IOutputStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutputStream());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbSetupPacket> : produce_base<D, Windows::Devices::Usb::IUsbSetupPacket>
{
    HRESULT __stdcall get_RequestType(impl::abi_arg_out<Windows::Devices::Usb::IUsbControlRequestType> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RequestType(impl::abi_arg_in<Windows::Devices::Usb::IUsbControlRequestType> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestType(*reinterpret_cast<const Windows::Devices::Usb::UsbControlRequestType *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Request(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Request());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Request(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Request(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Value(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Index(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Index());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Index(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Index(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Length(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Length());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Length(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Length(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Usb::IUsbSetupPacketFactory> : produce_base<D, Windows::Devices::Usb::IUsbSetupPacketFactory>
{
    HRESULT __stdcall abi_CreateWithEightByteBuffer(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> eightByteBuffer, impl::abi_arg_out<Windows::Devices::Usb::IUsbSetupPacket> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithEightByteBuffer(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&eightByteBuffer)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Usb {

template <typename D> Windows::Devices::Usb::UsbTransferDirection impl_IUsbControlRequestType<D>::Direction() const
{
    Windows::Devices::Usb::UsbTransferDirection value {};
    check_hresult(WINRT_SHIM(IUsbControlRequestType)->get_Direction(&value));
    return value;
}

template <typename D> void impl_IUsbControlRequestType<D>::Direction(Windows::Devices::Usb::UsbTransferDirection value) const
{
    check_hresult(WINRT_SHIM(IUsbControlRequestType)->put_Direction(value));
}

template <typename D> Windows::Devices::Usb::UsbControlTransferType impl_IUsbControlRequestType<D>::ControlTransferType() const
{
    Windows::Devices::Usb::UsbControlTransferType value {};
    check_hresult(WINRT_SHIM(IUsbControlRequestType)->get_ControlTransferType(&value));
    return value;
}

template <typename D> void impl_IUsbControlRequestType<D>::ControlTransferType(Windows::Devices::Usb::UsbControlTransferType value) const
{
    check_hresult(WINRT_SHIM(IUsbControlRequestType)->put_ControlTransferType(value));
}

template <typename D> Windows::Devices::Usb::UsbControlRecipient impl_IUsbControlRequestType<D>::Recipient() const
{
    Windows::Devices::Usb::UsbControlRecipient value {};
    check_hresult(WINRT_SHIM(IUsbControlRequestType)->get_Recipient(&value));
    return value;
}

template <typename D> void impl_IUsbControlRequestType<D>::Recipient(Windows::Devices::Usb::UsbControlRecipient value) const
{
    check_hresult(WINRT_SHIM(IUsbControlRequestType)->put_Recipient(value));
}

template <typename D> uint8_t impl_IUsbControlRequestType<D>::AsByte() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbControlRequestType)->get_AsByte(&value));
    return value;
}

template <typename D> void impl_IUsbControlRequestType<D>::AsByte(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IUsbControlRequestType)->put_AsByte(value));
}

template <typename D> Windows::Devices::Usb::UsbSetupPacket impl_IUsbSetupPacketFactory<D>::CreateWithEightByteBuffer(const Windows::Storage::Streams::IBuffer & eightByteBuffer) const
{
    Windows::Devices::Usb::UsbSetupPacket value { nullptr };
    check_hresult(WINRT_SHIM(IUsbSetupPacketFactory)->abi_CreateWithEightByteBuffer(get_abi(eightByteBuffer), put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbControlRequestType impl_IUsbSetupPacket<D>::RequestType() const
{
    Windows::Devices::Usb::UsbControlRequestType value { nullptr };
    check_hresult(WINRT_SHIM(IUsbSetupPacket)->get_RequestType(put_abi(value)));
    return value;
}

template <typename D> void impl_IUsbSetupPacket<D>::RequestType(const Windows::Devices::Usb::UsbControlRequestType & value) const
{
    check_hresult(WINRT_SHIM(IUsbSetupPacket)->put_RequestType(get_abi(value)));
}

template <typename D> uint8_t impl_IUsbSetupPacket<D>::Request() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbSetupPacket)->get_Request(&value));
    return value;
}

template <typename D> void impl_IUsbSetupPacket<D>::Request(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IUsbSetupPacket)->put_Request(value));
}

template <typename D> uint32_t impl_IUsbSetupPacket<D>::Value() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUsbSetupPacket)->get_Value(&value));
    return value;
}

template <typename D> void impl_IUsbSetupPacket<D>::Value(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IUsbSetupPacket)->put_Value(value));
}

template <typename D> uint32_t impl_IUsbSetupPacket<D>::Index() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUsbSetupPacket)->get_Index(&value));
    return value;
}

template <typename D> void impl_IUsbSetupPacket<D>::Index(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IUsbSetupPacket)->put_Index(value));
}

template <typename D> uint32_t impl_IUsbSetupPacket<D>::Length() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUsbSetupPacket)->get_Length(&value));
    return value;
}

template <typename D> void impl_IUsbSetupPacket<D>::Length(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IUsbSetupPacket)->put_Length(value));
}

template <typename D> uint8_t impl_IUsbDeviceClass<D>::ClassCode() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbDeviceClass)->get_ClassCode(&value));
    return value;
}

template <typename D> void impl_IUsbDeviceClass<D>::ClassCode(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IUsbDeviceClass)->put_ClassCode(value));
}

template <typename D> Windows::Foundation::IReference<uint8_t> impl_IUsbDeviceClass<D>::SubclassCode() const
{
    Windows::Foundation::IReference<uint8_t> value;
    check_hresult(WINRT_SHIM(IUsbDeviceClass)->get_SubclassCode(put_abi(value)));
    return value;
}

template <typename D> void impl_IUsbDeviceClass<D>::SubclassCode(const optional<uint8_t> & value) const
{
    check_hresult(WINRT_SHIM(IUsbDeviceClass)->put_SubclassCode(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<uint8_t> impl_IUsbDeviceClass<D>::ProtocolCode() const
{
    Windows::Foundation::IReference<uint8_t> value;
    check_hresult(WINRT_SHIM(IUsbDeviceClass)->get_ProtocolCode(put_abi(value)));
    return value;
}

template <typename D> void impl_IUsbDeviceClass<D>::ProtocolCode(const optional<uint8_t> & value) const
{
    check_hresult(WINRT_SHIM(IUsbDeviceClass)->put_ProtocolCode(get_abi(value)));
}

template <typename D> Windows::Devices::Usb::UsbDeviceClass impl_IUsbDeviceClassesStatics<D>::CdcControl() const
{
    Windows::Devices::Usb::UsbDeviceClass value { nullptr };
    check_hresult(WINRT_SHIM(IUsbDeviceClassesStatics)->get_CdcControl(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbDeviceClass impl_IUsbDeviceClassesStatics<D>::Physical() const
{
    Windows::Devices::Usb::UsbDeviceClass value { nullptr };
    check_hresult(WINRT_SHIM(IUsbDeviceClassesStatics)->get_Physical(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbDeviceClass impl_IUsbDeviceClassesStatics<D>::PersonalHealthcare() const
{
    Windows::Devices::Usb::UsbDeviceClass value { nullptr };
    check_hresult(WINRT_SHIM(IUsbDeviceClassesStatics)->get_PersonalHealthcare(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbDeviceClass impl_IUsbDeviceClassesStatics<D>::ActiveSync() const
{
    Windows::Devices::Usb::UsbDeviceClass value { nullptr };
    check_hresult(WINRT_SHIM(IUsbDeviceClassesStatics)->get_ActiveSync(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbDeviceClass impl_IUsbDeviceClassesStatics<D>::PalmSync() const
{
    Windows::Devices::Usb::UsbDeviceClass value { nullptr };
    check_hresult(WINRT_SHIM(IUsbDeviceClassesStatics)->get_PalmSync(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbDeviceClass impl_IUsbDeviceClassesStatics<D>::DeviceFirmwareUpdate() const
{
    Windows::Devices::Usb::UsbDeviceClass value { nullptr };
    check_hresult(WINRT_SHIM(IUsbDeviceClassesStatics)->get_DeviceFirmwareUpdate(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbDeviceClass impl_IUsbDeviceClassesStatics<D>::Irda() const
{
    Windows::Devices::Usb::UsbDeviceClass value { nullptr };
    check_hresult(WINRT_SHIM(IUsbDeviceClassesStatics)->get_Irda(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbDeviceClass impl_IUsbDeviceClassesStatics<D>::Measurement() const
{
    Windows::Devices::Usb::UsbDeviceClass value { nullptr };
    check_hresult(WINRT_SHIM(IUsbDeviceClassesStatics)->get_Measurement(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbDeviceClass impl_IUsbDeviceClassesStatics<D>::VendorSpecific() const
{
    Windows::Devices::Usb::UsbDeviceClass value { nullptr };
    check_hresult(WINRT_SHIM(IUsbDeviceClassesStatics)->get_VendorSpecific(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUsbDeviceStatics<D>::GetDeviceSelector(uint32_t vendorId, uint32_t productId, GUID winUsbInterfaceClass) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUsbDeviceStatics)->abi_GetDeviceSelector(vendorId, productId, winUsbInterfaceClass, put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUsbDeviceStatics<D>::GetDeviceSelector(GUID winUsbInterfaceClass) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUsbDeviceStatics)->abi_GetDeviceSelectorGuidOnly(winUsbInterfaceClass, put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUsbDeviceStatics<D>::GetDeviceSelector(uint32_t vendorId, uint32_t productId) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUsbDeviceStatics)->abi_GetDeviceSelectorVidPidOnly(vendorId, productId, put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUsbDeviceStatics<D>::GetDeviceClassSelector(const Windows::Devices::Usb::UsbDeviceClass & usbClass) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUsbDeviceStatics)->abi_GetDeviceClassSelector(get_abi(usbClass), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Usb::UsbDevice> impl_IUsbDeviceStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Usb::UsbDevice> operation;
    check_hresult(WINRT_SHIM(IUsbDeviceStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(operation)));
    return operation;
}

template <typename D> uint32_t impl_IUsbDeviceDescriptor<D>::BcdUsb() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUsbDeviceDescriptor)->get_BcdUsb(&value));
    return value;
}

template <typename D> uint8_t impl_IUsbDeviceDescriptor<D>::MaxPacketSize0() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbDeviceDescriptor)->get_MaxPacketSize0(&value));
    return value;
}

template <typename D> uint32_t impl_IUsbDeviceDescriptor<D>::VendorId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUsbDeviceDescriptor)->get_VendorId(&value));
    return value;
}

template <typename D> uint32_t impl_IUsbDeviceDescriptor<D>::ProductId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUsbDeviceDescriptor)->get_ProductId(&value));
    return value;
}

template <typename D> uint32_t impl_IUsbDeviceDescriptor<D>::BcdDeviceRevision() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUsbDeviceDescriptor)->get_BcdDeviceRevision(&value));
    return value;
}

template <typename D> uint8_t impl_IUsbDeviceDescriptor<D>::NumberOfConfigurations() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbDeviceDescriptor)->get_NumberOfConfigurations(&value));
    return value;
}

template <typename D> uint8_t impl_IUsbConfigurationDescriptor<D>::ConfigurationValue() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbConfigurationDescriptor)->get_ConfigurationValue(&value));
    return value;
}

template <typename D> uint32_t impl_IUsbConfigurationDescriptor<D>::MaxPowerMilliamps() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUsbConfigurationDescriptor)->get_MaxPowerMilliamps(&value));
    return value;
}

template <typename D> bool impl_IUsbConfigurationDescriptor<D>::SelfPowered() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUsbConfigurationDescriptor)->get_SelfPowered(&value));
    return value;
}

template <typename D> bool impl_IUsbConfigurationDescriptor<D>::RemoteWakeup() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUsbConfigurationDescriptor)->get_RemoteWakeup(&value));
    return value;
}

template <typename D> bool impl_IUsbConfigurationDescriptorStatics<D>::TryParse(const Windows::Devices::Usb::UsbDescriptor & descriptor, Windows::Devices::Usb::UsbConfigurationDescriptor & parsed) const
{
    bool success {};
    check_hresult(WINRT_SHIM(IUsbConfigurationDescriptorStatics)->abi_TryParse(get_abi(descriptor), put_abi(parsed), &success));
    return success;
}

template <typename D> Windows::Devices::Usb::UsbConfigurationDescriptor impl_IUsbConfigurationDescriptorStatics<D>::Parse(const Windows::Devices::Usb::UsbDescriptor & descriptor) const
{
    Windows::Devices::Usb::UsbConfigurationDescriptor parsed { nullptr };
    check_hresult(WINRT_SHIM(IUsbConfigurationDescriptorStatics)->abi_Parse(get_abi(descriptor), put_abi(parsed)));
    return parsed;
}

template <typename D> uint8_t impl_IUsbInterfaceDescriptor<D>::ClassCode() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbInterfaceDescriptor)->get_ClassCode(&value));
    return value;
}

template <typename D> uint8_t impl_IUsbInterfaceDescriptor<D>::SubclassCode() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbInterfaceDescriptor)->get_SubclassCode(&value));
    return value;
}

template <typename D> uint8_t impl_IUsbInterfaceDescriptor<D>::ProtocolCode() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbInterfaceDescriptor)->get_ProtocolCode(&value));
    return value;
}

template <typename D> uint8_t impl_IUsbInterfaceDescriptor<D>::AlternateSettingNumber() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbInterfaceDescriptor)->get_AlternateSettingNumber(&value));
    return value;
}

template <typename D> uint8_t impl_IUsbInterfaceDescriptor<D>::InterfaceNumber() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbInterfaceDescriptor)->get_InterfaceNumber(&value));
    return value;
}

template <typename D> bool impl_IUsbInterfaceDescriptorStatics<D>::TryParse(const Windows::Devices::Usb::UsbDescriptor & descriptor, Windows::Devices::Usb::UsbInterfaceDescriptor & parsed) const
{
    bool success {};
    check_hresult(WINRT_SHIM(IUsbInterfaceDescriptorStatics)->abi_TryParse(get_abi(descriptor), put_abi(parsed), &success));
    return success;
}

template <typename D> Windows::Devices::Usb::UsbInterfaceDescriptor impl_IUsbInterfaceDescriptorStatics<D>::Parse(const Windows::Devices::Usb::UsbDescriptor & descriptor) const
{
    Windows::Devices::Usb::UsbInterfaceDescriptor parsed { nullptr };
    check_hresult(WINRT_SHIM(IUsbInterfaceDescriptorStatics)->abi_Parse(get_abi(descriptor), put_abi(parsed)));
    return parsed;
}

template <typename D> uint8_t impl_IUsbEndpointDescriptor<D>::EndpointNumber() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbEndpointDescriptor)->get_EndpointNumber(&value));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbTransferDirection impl_IUsbEndpointDescriptor<D>::Direction() const
{
    Windows::Devices::Usb::UsbTransferDirection value {};
    check_hresult(WINRT_SHIM(IUsbEndpointDescriptor)->get_Direction(&value));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbEndpointType impl_IUsbEndpointDescriptor<D>::EndpointType() const
{
    Windows::Devices::Usb::UsbEndpointType value {};
    check_hresult(WINRT_SHIM(IUsbEndpointDescriptor)->get_EndpointType(&value));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbBulkInEndpointDescriptor impl_IUsbEndpointDescriptor<D>::AsBulkInEndpointDescriptor() const
{
    Windows::Devices::Usb::UsbBulkInEndpointDescriptor value { nullptr };
    check_hresult(WINRT_SHIM(IUsbEndpointDescriptor)->get_AsBulkInEndpointDescriptor(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbInterruptInEndpointDescriptor impl_IUsbEndpointDescriptor<D>::AsInterruptInEndpointDescriptor() const
{
    Windows::Devices::Usb::UsbInterruptInEndpointDescriptor value { nullptr };
    check_hresult(WINRT_SHIM(IUsbEndpointDescriptor)->get_AsInterruptInEndpointDescriptor(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbBulkOutEndpointDescriptor impl_IUsbEndpointDescriptor<D>::AsBulkOutEndpointDescriptor() const
{
    Windows::Devices::Usb::UsbBulkOutEndpointDescriptor value { nullptr };
    check_hresult(WINRT_SHIM(IUsbEndpointDescriptor)->get_AsBulkOutEndpointDescriptor(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor impl_IUsbEndpointDescriptor<D>::AsInterruptOutEndpointDescriptor() const
{
    Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor value { nullptr };
    check_hresult(WINRT_SHIM(IUsbEndpointDescriptor)->get_AsInterruptOutEndpointDescriptor(put_abi(value)));
    return value;
}

template <typename D> bool impl_IUsbEndpointDescriptorStatics<D>::TryParse(const Windows::Devices::Usb::UsbDescriptor & descriptor, Windows::Devices::Usb::UsbEndpointDescriptor & parsed) const
{
    bool success {};
    check_hresult(WINRT_SHIM(IUsbEndpointDescriptorStatics)->abi_TryParse(get_abi(descriptor), put_abi(parsed), &success));
    return success;
}

template <typename D> Windows::Devices::Usb::UsbEndpointDescriptor impl_IUsbEndpointDescriptorStatics<D>::Parse(const Windows::Devices::Usb::UsbDescriptor & descriptor) const
{
    Windows::Devices::Usb::UsbEndpointDescriptor parsed { nullptr };
    check_hresult(WINRT_SHIM(IUsbEndpointDescriptorStatics)->abi_Parse(get_abi(descriptor), put_abi(parsed)));
    return parsed;
}

template <typename D> uint8_t impl_IUsbDescriptor<D>::Length() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbDescriptor)->get_Length(&value));
    return value;
}

template <typename D> uint8_t impl_IUsbDescriptor<D>::DescriptorType() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbDescriptor)->get_DescriptorType(&value));
    return value;
}

template <typename D> void impl_IUsbDescriptor<D>::ReadDescriptorBuffer(const Windows::Storage::Streams::IBuffer & buffer) const
{
    check_hresult(WINRT_SHIM(IUsbDescriptor)->abi_ReadDescriptorBuffer(get_abi(buffer)));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IUsbInterruptInEventArgs<D>::InterruptData() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IUsbInterruptInEventArgs)->get_InterruptData(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IUsbBulkInPipe<D>::MaxTransferSizeBytes() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUsbBulkInPipe)->get_MaxTransferSizeBytes(&value));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbBulkInEndpointDescriptor impl_IUsbBulkInPipe<D>::EndpointDescriptor() const
{
    Windows::Devices::Usb::UsbBulkInEndpointDescriptor value { nullptr };
    check_hresult(WINRT_SHIM(IUsbBulkInPipe)->get_EndpointDescriptor(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IUsbBulkInPipe<D>::ClearStallAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IUsbBulkInPipe)->abi_ClearStallAsync(put_abi(operation)));
    return operation;
}

template <typename D> void impl_IUsbBulkInPipe<D>::ReadOptions(Windows::Devices::Usb::UsbReadOptions value) const
{
    check_hresult(WINRT_SHIM(IUsbBulkInPipe)->put_ReadOptions(value));
}

template <typename D> Windows::Devices::Usb::UsbReadOptions impl_IUsbBulkInPipe<D>::ReadOptions() const
{
    Windows::Devices::Usb::UsbReadOptions value {};
    check_hresult(WINRT_SHIM(IUsbBulkInPipe)->get_ReadOptions(&value));
    return value;
}

template <typename D> void impl_IUsbBulkInPipe<D>::FlushBuffer() const
{
    check_hresult(WINRT_SHIM(IUsbBulkInPipe)->abi_FlushBuffer());
}

template <typename D> Windows::Storage::Streams::IInputStream impl_IUsbBulkInPipe<D>::InputStream() const
{
    Windows::Storage::Streams::IInputStream value;
    check_hresult(WINRT_SHIM(IUsbBulkInPipe)->get_InputStream(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbInterruptInEndpointDescriptor impl_IUsbInterruptInPipe<D>::EndpointDescriptor() const
{
    Windows::Devices::Usb::UsbInterruptInEndpointDescriptor value { nullptr };
    check_hresult(WINRT_SHIM(IUsbInterruptInPipe)->get_EndpointDescriptor(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IUsbInterruptInPipe<D>::ClearStallAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IUsbInterruptInPipe)->abi_ClearStallAsync(put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_IUsbInterruptInPipe<D>::DataReceived(const Windows::Foundation::TypedEventHandler<Windows::Devices::Usb::UsbInterruptInPipe, Windows::Devices::Usb::UsbInterruptInEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUsbInterruptInPipe)->add_DataReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IUsbInterruptInPipe> impl_IUsbInterruptInPipe<D>::DataReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Usb::UsbInterruptInPipe, Windows::Devices::Usb::UsbInterruptInEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IUsbInterruptInPipe>(this, &ABI::Windows::Devices::Usb::IUsbInterruptInPipe::remove_DataReceived, DataReceived(handler));
}

template <typename D> void impl_IUsbInterruptInPipe<D>::DataReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IUsbInterruptInPipe)->remove_DataReceived(token));
}

template <typename D> Windows::Devices::Usb::UsbBulkOutEndpointDescriptor impl_IUsbBulkOutPipe<D>::EndpointDescriptor() const
{
    Windows::Devices::Usb::UsbBulkOutEndpointDescriptor value { nullptr };
    check_hresult(WINRT_SHIM(IUsbBulkOutPipe)->get_EndpointDescriptor(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IUsbBulkOutPipe<D>::ClearStallAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IUsbBulkOutPipe)->abi_ClearStallAsync(put_abi(operation)));
    return operation;
}

template <typename D> void impl_IUsbBulkOutPipe<D>::WriteOptions(Windows::Devices::Usb::UsbWriteOptions value) const
{
    check_hresult(WINRT_SHIM(IUsbBulkOutPipe)->put_WriteOptions(value));
}

template <typename D> Windows::Devices::Usb::UsbWriteOptions impl_IUsbBulkOutPipe<D>::WriteOptions() const
{
    Windows::Devices::Usb::UsbWriteOptions value {};
    check_hresult(WINRT_SHIM(IUsbBulkOutPipe)->get_WriteOptions(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IOutputStream impl_IUsbBulkOutPipe<D>::OutputStream() const
{
    Windows::Storage::Streams::IOutputStream value;
    check_hresult(WINRT_SHIM(IUsbBulkOutPipe)->get_OutputStream(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor impl_IUsbInterruptOutPipe<D>::EndpointDescriptor() const
{
    Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor value { nullptr };
    check_hresult(WINRT_SHIM(IUsbInterruptOutPipe)->get_EndpointDescriptor(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IUsbInterruptOutPipe<D>::ClearStallAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IUsbInterruptOutPipe)->abi_ClearStallAsync(put_abi(operation)));
    return operation;
}

template <typename D> void impl_IUsbInterruptOutPipe<D>::WriteOptions(Windows::Devices::Usb::UsbWriteOptions value) const
{
    check_hresult(WINRT_SHIM(IUsbInterruptOutPipe)->put_WriteOptions(value));
}

template <typename D> Windows::Devices::Usb::UsbWriteOptions impl_IUsbInterruptOutPipe<D>::WriteOptions() const
{
    Windows::Devices::Usb::UsbWriteOptions value {};
    check_hresult(WINRT_SHIM(IUsbInterruptOutPipe)->get_WriteOptions(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IOutputStream impl_IUsbInterruptOutPipe<D>::OutputStream() const
{
    Windows::Storage::Streams::IOutputStream value;
    check_hresult(WINRT_SHIM(IUsbInterruptOutPipe)->get_OutputStream(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterface> impl_IUsbConfiguration<D>::UsbInterfaces() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterface> value;
    check_hresult(WINRT_SHIM(IUsbConfiguration)->get_UsbInterfaces(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbConfigurationDescriptor impl_IUsbConfiguration<D>::ConfigurationDescriptor() const
{
    Windows::Devices::Usb::UsbConfigurationDescriptor value { nullptr };
    check_hresult(WINRT_SHIM(IUsbConfiguration)->get_ConfigurationDescriptor(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbDescriptor> impl_IUsbConfiguration<D>::Descriptors() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbDescriptor> value;
    check_hresult(WINRT_SHIM(IUsbConfiguration)->get_Descriptors(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkInPipe> impl_IUsbInterface<D>::BulkInPipes() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkInPipe> value;
    check_hresult(WINRT_SHIM(IUsbInterface)->get_BulkInPipes(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptInPipe> impl_IUsbInterface<D>::InterruptInPipes() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptInPipe> value;
    check_hresult(WINRT_SHIM(IUsbInterface)->get_InterruptInPipes(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkOutPipe> impl_IUsbInterface<D>::BulkOutPipes() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkOutPipe> value;
    check_hresult(WINRT_SHIM(IUsbInterface)->get_BulkOutPipes(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptOutPipe> impl_IUsbInterface<D>::InterruptOutPipes() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptOutPipe> value;
    check_hresult(WINRT_SHIM(IUsbInterface)->get_InterruptOutPipes(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterfaceSetting> impl_IUsbInterface<D>::InterfaceSettings() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterfaceSetting> value;
    check_hresult(WINRT_SHIM(IUsbInterface)->get_InterfaceSettings(put_abi(value)));
    return value;
}

template <typename D> uint8_t impl_IUsbInterface<D>::InterfaceNumber() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbInterface)->get_InterfaceNumber(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbDescriptor> impl_IUsbInterface<D>::Descriptors() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbDescriptor> value;
    check_hresult(WINRT_SHIM(IUsbInterface)->get_Descriptors(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkInEndpointDescriptor> impl_IUsbInterfaceSetting<D>::BulkInEndpoints() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkInEndpointDescriptor> value;
    check_hresult(WINRT_SHIM(IUsbInterfaceSetting)->get_BulkInEndpoints(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptInEndpointDescriptor> impl_IUsbInterfaceSetting<D>::InterruptInEndpoints() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptInEndpointDescriptor> value;
    check_hresult(WINRT_SHIM(IUsbInterfaceSetting)->get_InterruptInEndpoints(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkOutEndpointDescriptor> impl_IUsbInterfaceSetting<D>::BulkOutEndpoints() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbBulkOutEndpointDescriptor> value;
    check_hresult(WINRT_SHIM(IUsbInterfaceSetting)->get_BulkOutEndpoints(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor> impl_IUsbInterfaceSetting<D>::InterruptOutEndpoints() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor> value;
    check_hresult(WINRT_SHIM(IUsbInterfaceSetting)->get_InterruptOutEndpoints(put_abi(value)));
    return value;
}

template <typename D> bool impl_IUsbInterfaceSetting<D>::Selected() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUsbInterfaceSetting)->get_Selected(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IUsbInterfaceSetting<D>::SelectSettingAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IUsbInterfaceSetting)->abi_SelectSettingAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Devices::Usb::UsbInterfaceDescriptor impl_IUsbInterfaceSetting<D>::InterfaceDescriptor() const
{
    Windows::Devices::Usb::UsbInterfaceDescriptor value { nullptr };
    check_hresult(WINRT_SHIM(IUsbInterfaceSetting)->get_InterfaceDescriptor(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbDescriptor> impl_IUsbInterfaceSetting<D>::Descriptors() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Usb::UsbDescriptor> value;
    check_hresult(WINRT_SHIM(IUsbInterfaceSetting)->get_Descriptors(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IUsbBulkInEndpointDescriptor<D>::MaxPacketSize() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUsbBulkInEndpointDescriptor)->get_MaxPacketSize(&value));
    return value;
}

template <typename D> uint8_t impl_IUsbBulkInEndpointDescriptor<D>::EndpointNumber() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbBulkInEndpointDescriptor)->get_EndpointNumber(&value));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbBulkInPipe impl_IUsbBulkInEndpointDescriptor<D>::Pipe() const
{
    Windows::Devices::Usb::UsbBulkInPipe value { nullptr };
    check_hresult(WINRT_SHIM(IUsbBulkInEndpointDescriptor)->get_Pipe(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IUsbInterruptInEndpointDescriptor<D>::MaxPacketSize() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUsbInterruptInEndpointDescriptor)->get_MaxPacketSize(&value));
    return value;
}

template <typename D> uint8_t impl_IUsbInterruptInEndpointDescriptor<D>::EndpointNumber() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbInterruptInEndpointDescriptor)->get_EndpointNumber(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IUsbInterruptInEndpointDescriptor<D>::Interval() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IUsbInterruptInEndpointDescriptor)->get_Interval(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbInterruptInPipe impl_IUsbInterruptInEndpointDescriptor<D>::Pipe() const
{
    Windows::Devices::Usb::UsbInterruptInPipe value { nullptr };
    check_hresult(WINRT_SHIM(IUsbInterruptInEndpointDescriptor)->get_Pipe(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IUsbBulkOutEndpointDescriptor<D>::MaxPacketSize() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUsbBulkOutEndpointDescriptor)->get_MaxPacketSize(&value));
    return value;
}

template <typename D> uint8_t impl_IUsbBulkOutEndpointDescriptor<D>::EndpointNumber() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbBulkOutEndpointDescriptor)->get_EndpointNumber(&value));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbBulkOutPipe impl_IUsbBulkOutEndpointDescriptor<D>::Pipe() const
{
    Windows::Devices::Usb::UsbBulkOutPipe value { nullptr };
    check_hresult(WINRT_SHIM(IUsbBulkOutEndpointDescriptor)->get_Pipe(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IUsbInterruptOutEndpointDescriptor<D>::MaxPacketSize() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUsbInterruptOutEndpointDescriptor)->get_MaxPacketSize(&value));
    return value;
}

template <typename D> uint8_t impl_IUsbInterruptOutEndpointDescriptor<D>::EndpointNumber() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUsbInterruptOutEndpointDescriptor)->get_EndpointNumber(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IUsbInterruptOutEndpointDescriptor<D>::Interval() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IUsbInterruptOutEndpointDescriptor)->get_Interval(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbInterruptOutPipe impl_IUsbInterruptOutEndpointDescriptor<D>::Pipe() const
{
    Windows::Devices::Usb::UsbInterruptOutPipe value { nullptr };
    check_hresult(WINRT_SHIM(IUsbInterruptOutEndpointDescriptor)->get_Pipe(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<uint32_t> impl_IUsbDevice<D>::SendControlOutTransferAsync(const Windows::Devices::Usb::UsbSetupPacket & setupPacket, const Windows::Storage::Streams::IBuffer & buffer) const
{
    Windows::Foundation::IAsyncOperation<uint32_t> operation;
    check_hresult(WINRT_SHIM(IUsbDevice)->abi_SendControlOutTransferAsync(get_abi(setupPacket), get_abi(buffer), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<uint32_t> impl_IUsbDevice<D>::SendControlOutTransferAsync(const Windows::Devices::Usb::UsbSetupPacket & setupPacket) const
{
    Windows::Foundation::IAsyncOperation<uint32_t> operation;
    check_hresult(WINRT_SHIM(IUsbDevice)->abi_SendControlOutTransferAsyncNoBuffer(get_abi(setupPacket), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_IUsbDevice<D>::SendControlInTransferAsync(const Windows::Devices::Usb::UsbSetupPacket & setupPacket, const Windows::Storage::Streams::IBuffer & buffer) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> operation;
    check_hresult(WINRT_SHIM(IUsbDevice)->abi_SendControlInTransferAsync(get_abi(setupPacket), get_abi(buffer), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_IUsbDevice<D>::SendControlInTransferAsync(const Windows::Devices::Usb::UsbSetupPacket & setupPacket) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> operation;
    check_hresult(WINRT_SHIM(IUsbDevice)->abi_SendControlInTransferAsyncNoBuffer(get_abi(setupPacket), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Devices::Usb::UsbInterface impl_IUsbDevice<D>::DefaultInterface() const
{
    Windows::Devices::Usb::UsbInterface value { nullptr };
    check_hresult(WINRT_SHIM(IUsbDevice)->get_DefaultInterface(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbDeviceDescriptor impl_IUsbDevice<D>::DeviceDescriptor() const
{
    Windows::Devices::Usb::UsbDeviceDescriptor value { nullptr };
    check_hresult(WINRT_SHIM(IUsbDevice)->get_DeviceDescriptor(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Usb::UsbConfiguration impl_IUsbDevice<D>::Configuration() const
{
    Windows::Devices::Usb::UsbConfiguration value { nullptr };
    check_hresult(WINRT_SHIM(IUsbDevice)->get_Configuration(put_abi(value)));
    return value;
}

inline bool UsbConfigurationDescriptor::TryParse(const Windows::Devices::Usb::UsbDescriptor & descriptor, Windows::Devices::Usb::UsbConfigurationDescriptor & parsed)
{
    return get_activation_factory<UsbConfigurationDescriptor, IUsbConfigurationDescriptorStatics>().TryParse(descriptor, parsed);
}

inline Windows::Devices::Usb::UsbConfigurationDescriptor UsbConfigurationDescriptor::Parse(const Windows::Devices::Usb::UsbDescriptor & descriptor)
{
    return get_activation_factory<UsbConfigurationDescriptor, IUsbConfigurationDescriptorStatics>().Parse(descriptor);
}

inline UsbControlRequestType::UsbControlRequestType() :
    UsbControlRequestType(activate_instance<UsbControlRequestType>())
{}

inline hstring UsbDevice::GetDeviceSelector(uint32_t vendorId, uint32_t productId, GUID winUsbInterfaceClass)
{
    return get_activation_factory<UsbDevice, IUsbDeviceStatics>().GetDeviceSelector(vendorId, productId, winUsbInterfaceClass);
}

inline hstring UsbDevice::GetDeviceSelector(GUID winUsbInterfaceClass)
{
    return get_activation_factory<UsbDevice, IUsbDeviceStatics>().GetDeviceSelector(winUsbInterfaceClass);
}

inline hstring UsbDevice::GetDeviceSelector(uint32_t vendorId, uint32_t productId)
{
    return get_activation_factory<UsbDevice, IUsbDeviceStatics>().GetDeviceSelector(vendorId, productId);
}

inline hstring UsbDevice::GetDeviceClassSelector(const Windows::Devices::Usb::UsbDeviceClass & usbClass)
{
    return get_activation_factory<UsbDevice, IUsbDeviceStatics>().GetDeviceClassSelector(usbClass);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Usb::UsbDevice> UsbDevice::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<UsbDevice, IUsbDeviceStatics>().FromIdAsync(deviceId);
}

inline UsbDeviceClass::UsbDeviceClass() :
    UsbDeviceClass(activate_instance<UsbDeviceClass>())
{}

inline Windows::Devices::Usb::UsbDeviceClass UsbDeviceClasses::CdcControl()
{
    return get_activation_factory<UsbDeviceClasses, IUsbDeviceClassesStatics>().CdcControl();
}

inline Windows::Devices::Usb::UsbDeviceClass UsbDeviceClasses::Physical()
{
    return get_activation_factory<UsbDeviceClasses, IUsbDeviceClassesStatics>().Physical();
}

inline Windows::Devices::Usb::UsbDeviceClass UsbDeviceClasses::PersonalHealthcare()
{
    return get_activation_factory<UsbDeviceClasses, IUsbDeviceClassesStatics>().PersonalHealthcare();
}

inline Windows::Devices::Usb::UsbDeviceClass UsbDeviceClasses::ActiveSync()
{
    return get_activation_factory<UsbDeviceClasses, IUsbDeviceClassesStatics>().ActiveSync();
}

inline Windows::Devices::Usb::UsbDeviceClass UsbDeviceClasses::PalmSync()
{
    return get_activation_factory<UsbDeviceClasses, IUsbDeviceClassesStatics>().PalmSync();
}

inline Windows::Devices::Usb::UsbDeviceClass UsbDeviceClasses::DeviceFirmwareUpdate()
{
    return get_activation_factory<UsbDeviceClasses, IUsbDeviceClassesStatics>().DeviceFirmwareUpdate();
}

inline Windows::Devices::Usb::UsbDeviceClass UsbDeviceClasses::Irda()
{
    return get_activation_factory<UsbDeviceClasses, IUsbDeviceClassesStatics>().Irda();
}

inline Windows::Devices::Usb::UsbDeviceClass UsbDeviceClasses::Measurement()
{
    return get_activation_factory<UsbDeviceClasses, IUsbDeviceClassesStatics>().Measurement();
}

inline Windows::Devices::Usb::UsbDeviceClass UsbDeviceClasses::VendorSpecific()
{
    return get_activation_factory<UsbDeviceClasses, IUsbDeviceClassesStatics>().VendorSpecific();
}

inline bool UsbEndpointDescriptor::TryParse(const Windows::Devices::Usb::UsbDescriptor & descriptor, Windows::Devices::Usb::UsbEndpointDescriptor & parsed)
{
    return get_activation_factory<UsbEndpointDescriptor, IUsbEndpointDescriptorStatics>().TryParse(descriptor, parsed);
}

inline Windows::Devices::Usb::UsbEndpointDescriptor UsbEndpointDescriptor::Parse(const Windows::Devices::Usb::UsbDescriptor & descriptor)
{
    return get_activation_factory<UsbEndpointDescriptor, IUsbEndpointDescriptorStatics>().Parse(descriptor);
}

inline bool UsbInterfaceDescriptor::TryParse(const Windows::Devices::Usb::UsbDescriptor & descriptor, Windows::Devices::Usb::UsbInterfaceDescriptor & parsed)
{
    return get_activation_factory<UsbInterfaceDescriptor, IUsbInterfaceDescriptorStatics>().TryParse(descriptor, parsed);
}

inline Windows::Devices::Usb::UsbInterfaceDescriptor UsbInterfaceDescriptor::Parse(const Windows::Devices::Usb::UsbDescriptor & descriptor)
{
    return get_activation_factory<UsbInterfaceDescriptor, IUsbInterfaceDescriptorStatics>().Parse(descriptor);
}

inline UsbSetupPacket::UsbSetupPacket() :
    UsbSetupPacket(activate_instance<UsbSetupPacket>())
{}

inline UsbSetupPacket::UsbSetupPacket(const Windows::Storage::Streams::IBuffer & eightByteBuffer) :
    UsbSetupPacket(get_activation_factory<UsbSetupPacket, IUsbSetupPacketFactory>().CreateWithEightByteBuffer(eightByteBuffer))
{}

}

}
#pragma warning(pop)
