// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Devices.SerialCommunication.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::SerialCommunication::IErrorReceivedEventArgs> : produce_base<D, Windows::Devices::SerialCommunication::IErrorReceivedEventArgs>
{
    HRESULT __stdcall get_Error(Windows::Devices::SerialCommunication::SerialError * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Error());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SerialCommunication::IPinChangedEventArgs> : produce_base<D, Windows::Devices::SerialCommunication::IPinChangedEventArgs>
{
    HRESULT __stdcall get_PinChange(Windows::Devices::SerialCommunication::SerialPinChange * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PinChange());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SerialCommunication::ISerialDevice> : produce_base<D, Windows::Devices::SerialCommunication::ISerialDevice>
{
    HRESULT __stdcall get_BaudRate(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BaudRate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BaudRate(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BaudRate(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BreakSignalState(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BreakSignalState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BreakSignalState(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BreakSignalState(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BytesReceived(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BytesReceived());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CarrierDetectState(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CarrierDetectState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClearToSendState(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClearToSendState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DataBits(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataBits());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DataBits(uint16_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataBits(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DataSetReadyState(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataSetReadyState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Handshake(Windows::Devices::SerialCommunication::SerialHandshake * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handshake());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handshake(Windows::Devices::SerialCommunication::SerialHandshake value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handshake(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDataTerminalReadyEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDataTerminalReadyEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsDataTerminalReadyEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDataTerminalReadyEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsRequestToSendEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsRequestToSendEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsRequestToSendEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsRequestToSendEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Parity(Windows::Devices::SerialCommunication::SerialParity * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Parity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Parity(Windows::Devices::SerialCommunication::SerialParity value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Parity(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PortName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PortName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReadTimeout(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadTimeout());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ReadTimeout(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReadTimeout(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StopBits(Windows::Devices::SerialCommunication::SerialStopBitCount * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StopBits());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StopBits(Windows::Devices::SerialCommunication::SerialStopBitCount value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopBits(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UsbVendorId(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UsbVendorId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UsbProductId(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UsbProductId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WriteTimeout(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WriteTimeout());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_WriteTimeout(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteTimeout(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
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

    HRESULT __stdcall add_ErrorReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::ErrorReceivedEventArgs>> reportHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ErrorReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::ErrorReceivedEventArgs> *>(&reportHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ErrorReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ErrorReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PinChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::PinChangedEventArgs>> reportHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PinChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::PinChangedEventArgs> *>(&reportHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PinChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PinChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SerialCommunication::ISerialDeviceStatics> : produce_base<D, Windows::Devices::SerialCommunication::ISerialDeviceStatics>
{
    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromPortName(impl::abi_arg_in<hstring> portName, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDeviceSelector(*reinterpret_cast<const hstring *>(&portName)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromUsbVidPid(uint16_t vendorId, uint16_t productId, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDeviceSelectorFromUsbVidPid(vendorId, productId));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SerialCommunication::SerialDevice>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::SerialCommunication {

template <typename D> hstring impl_ISerialDeviceStatics<D>::GetDeviceSelector() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISerialDeviceStatics)->abi_GetDeviceSelector(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISerialDeviceStatics<D>::GetDeviceSelector(hstring_view portName) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ISerialDeviceStatics)->abi_GetDeviceSelectorFromPortName(get_abi(portName), put_abi(result)));
    return result;
}

template <typename D> hstring impl_ISerialDeviceStatics<D>::GetDeviceSelectorFromUsbVidPid(uint16_t vendorId, uint16_t productId) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ISerialDeviceStatics)->abi_GetDeviceSelectorFromUsbVidPid(vendorId, productId, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SerialCommunication::SerialDevice> impl_ISerialDeviceStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SerialCommunication::SerialDevice> result;
    check_hresult(WINRT_SHIM(ISerialDeviceStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::SerialCommunication::SerialError impl_IErrorReceivedEventArgs<D>::Error() const
{
    Windows::Devices::SerialCommunication::SerialError value {};
    check_hresult(WINRT_SHIM(IErrorReceivedEventArgs)->get_Error(&value));
    return value;
}

template <typename D> Windows::Devices::SerialCommunication::SerialPinChange impl_IPinChangedEventArgs<D>::PinChange() const
{
    Windows::Devices::SerialCommunication::SerialPinChange value {};
    check_hresult(WINRT_SHIM(IPinChangedEventArgs)->get_PinChange(&value));
    return value;
}

template <typename D> uint32_t impl_ISerialDevice<D>::BaudRate() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISerialDevice)->get_BaudRate(&value));
    return value;
}

template <typename D> void impl_ISerialDevice<D>::BaudRate(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ISerialDevice)->put_BaudRate(value));
}

template <typename D> bool impl_ISerialDevice<D>::BreakSignalState() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISerialDevice)->get_BreakSignalState(&value));
    return value;
}

template <typename D> void impl_ISerialDevice<D>::BreakSignalState(bool value) const
{
    check_hresult(WINRT_SHIM(ISerialDevice)->put_BreakSignalState(value));
}

template <typename D> uint32_t impl_ISerialDevice<D>::BytesReceived() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISerialDevice)->get_BytesReceived(&value));
    return value;
}

template <typename D> bool impl_ISerialDevice<D>::CarrierDetectState() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISerialDevice)->get_CarrierDetectState(&value));
    return value;
}

template <typename D> bool impl_ISerialDevice<D>::ClearToSendState() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISerialDevice)->get_ClearToSendState(&value));
    return value;
}

template <typename D> uint16_t impl_ISerialDevice<D>::DataBits() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(ISerialDevice)->get_DataBits(&value));
    return value;
}

template <typename D> void impl_ISerialDevice<D>::DataBits(uint16_t value) const
{
    check_hresult(WINRT_SHIM(ISerialDevice)->put_DataBits(value));
}

template <typename D> bool impl_ISerialDevice<D>::DataSetReadyState() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISerialDevice)->get_DataSetReadyState(&value));
    return value;
}

template <typename D> Windows::Devices::SerialCommunication::SerialHandshake impl_ISerialDevice<D>::Handshake() const
{
    Windows::Devices::SerialCommunication::SerialHandshake value {};
    check_hresult(WINRT_SHIM(ISerialDevice)->get_Handshake(&value));
    return value;
}

template <typename D> void impl_ISerialDevice<D>::Handshake(Windows::Devices::SerialCommunication::SerialHandshake value) const
{
    check_hresult(WINRT_SHIM(ISerialDevice)->put_Handshake(value));
}

template <typename D> bool impl_ISerialDevice<D>::IsDataTerminalReadyEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISerialDevice)->get_IsDataTerminalReadyEnabled(&value));
    return value;
}

template <typename D> void impl_ISerialDevice<D>::IsDataTerminalReadyEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISerialDevice)->put_IsDataTerminalReadyEnabled(value));
}

template <typename D> bool impl_ISerialDevice<D>::IsRequestToSendEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISerialDevice)->get_IsRequestToSendEnabled(&value));
    return value;
}

template <typename D> void impl_ISerialDevice<D>::IsRequestToSendEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISerialDevice)->put_IsRequestToSendEnabled(value));
}

template <typename D> Windows::Devices::SerialCommunication::SerialParity impl_ISerialDevice<D>::Parity() const
{
    Windows::Devices::SerialCommunication::SerialParity value {};
    check_hresult(WINRT_SHIM(ISerialDevice)->get_Parity(&value));
    return value;
}

template <typename D> void impl_ISerialDevice<D>::Parity(Windows::Devices::SerialCommunication::SerialParity value) const
{
    check_hresult(WINRT_SHIM(ISerialDevice)->put_Parity(value));
}

template <typename D> hstring impl_ISerialDevice<D>::PortName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISerialDevice)->get_PortName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_ISerialDevice<D>::ReadTimeout() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ISerialDevice)->get_ReadTimeout(put_abi(value)));
    return value;
}

template <typename D> void impl_ISerialDevice<D>::ReadTimeout(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ISerialDevice)->put_ReadTimeout(get_abi(value)));
}

template <typename D> Windows::Devices::SerialCommunication::SerialStopBitCount impl_ISerialDevice<D>::StopBits() const
{
    Windows::Devices::SerialCommunication::SerialStopBitCount value {};
    check_hresult(WINRT_SHIM(ISerialDevice)->get_StopBits(&value));
    return value;
}

template <typename D> void impl_ISerialDevice<D>::StopBits(Windows::Devices::SerialCommunication::SerialStopBitCount value) const
{
    check_hresult(WINRT_SHIM(ISerialDevice)->put_StopBits(value));
}

template <typename D> uint16_t impl_ISerialDevice<D>::UsbVendorId() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(ISerialDevice)->get_UsbVendorId(&value));
    return value;
}

template <typename D> uint16_t impl_ISerialDevice<D>::UsbProductId() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(ISerialDevice)->get_UsbProductId(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_ISerialDevice<D>::WriteTimeout() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ISerialDevice)->get_WriteTimeout(put_abi(value)));
    return value;
}

template <typename D> void impl_ISerialDevice<D>::WriteTimeout(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ISerialDevice)->put_WriteTimeout(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IInputStream impl_ISerialDevice<D>::InputStream() const
{
    Windows::Storage::Streams::IInputStream value;
    check_hresult(WINRT_SHIM(ISerialDevice)->get_InputStream(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IOutputStream impl_ISerialDevice<D>::OutputStream() const
{
    Windows::Storage::Streams::IOutputStream value;
    check_hresult(WINRT_SHIM(ISerialDevice)->get_OutputStream(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ISerialDevice<D>::ErrorReceived(const Windows::Foundation::TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::ErrorReceivedEventArgs> & reportHandler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISerialDevice)->add_ErrorReceived(get_abi(reportHandler), &token));
    return token;
}

template <typename D> event_revoker<ISerialDevice> impl_ISerialDevice<D>::ErrorReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::ErrorReceivedEventArgs> & reportHandler) const
{
    return impl::make_event_revoker<D, ISerialDevice>(this, &ABI::Windows::Devices::SerialCommunication::ISerialDevice::remove_ErrorReceived, ErrorReceived(reportHandler));
}

template <typename D> void impl_ISerialDevice<D>::ErrorReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(ISerialDevice)->remove_ErrorReceived(token));
}

template <typename D> event_token impl_ISerialDevice<D>::PinChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::PinChangedEventArgs> & reportHandler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISerialDevice)->add_PinChanged(get_abi(reportHandler), &token));
    return token;
}

template <typename D> event_revoker<ISerialDevice> impl_ISerialDevice<D>::PinChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::PinChangedEventArgs> & reportHandler) const
{
    return impl::make_event_revoker<D, ISerialDevice>(this, &ABI::Windows::Devices::SerialCommunication::ISerialDevice::remove_PinChanged, PinChanged(reportHandler));
}

template <typename D> void impl_ISerialDevice<D>::PinChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(ISerialDevice)->remove_PinChanged(token));
}

inline hstring SerialDevice::GetDeviceSelector()
{
    return get_activation_factory<SerialDevice, ISerialDeviceStatics>().GetDeviceSelector();
}

inline hstring SerialDevice::GetDeviceSelector(hstring_view portName)
{
    return get_activation_factory<SerialDevice, ISerialDeviceStatics>().GetDeviceSelector(portName);
}

inline hstring SerialDevice::GetDeviceSelectorFromUsbVidPid(uint16_t vendorId, uint16_t productId)
{
    return get_activation_factory<SerialDevice, ISerialDeviceStatics>().GetDeviceSelectorFromUsbVidPid(vendorId, productId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::SerialCommunication::SerialDevice> SerialDevice::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<SerialDevice, ISerialDeviceStatics>().FromIdAsync(deviceId);
}

}

}
#pragma warning(pop)
