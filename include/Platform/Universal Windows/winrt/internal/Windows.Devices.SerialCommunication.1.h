// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.SerialCommunication.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::SerialCommunication {

struct __declspec(uuid("fcc6bf59-1283-4d8a-bfdf-566b33ddb28f")) __declspec(novtable) IErrorReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Error(winrt::Windows::Devices::SerialCommunication::SerialError * value) = 0;
};

struct __declspec(uuid("a2bf1db0-fc9c-4607-93d0-fa5e8343ee22")) __declspec(novtable) IPinChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PinChange(winrt::Windows::Devices::SerialCommunication::SerialPinChange * value) = 0;
};

struct __declspec(uuid("e187ccc6-2210-414f-b65a-f5553a03372a")) __declspec(novtable) ISerialDevice : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BaudRate(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_BaudRate(uint32_t value) = 0;
    virtual HRESULT __stdcall get_BreakSignalState(bool * value) = 0;
    virtual HRESULT __stdcall put_BreakSignalState(bool value) = 0;
    virtual HRESULT __stdcall get_BytesReceived(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_CarrierDetectState(bool * value) = 0;
    virtual HRESULT __stdcall get_ClearToSendState(bool * value) = 0;
    virtual HRESULT __stdcall get_DataBits(uint16_t * value) = 0;
    virtual HRESULT __stdcall put_DataBits(uint16_t value) = 0;
    virtual HRESULT __stdcall get_DataSetReadyState(bool * value) = 0;
    virtual HRESULT __stdcall get_Handshake(winrt::Windows::Devices::SerialCommunication::SerialHandshake * value) = 0;
    virtual HRESULT __stdcall put_Handshake(winrt::Windows::Devices::SerialCommunication::SerialHandshake value) = 0;
    virtual HRESULT __stdcall get_IsDataTerminalReadyEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsDataTerminalReadyEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsRequestToSendEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsRequestToSendEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_Parity(winrt::Windows::Devices::SerialCommunication::SerialParity * value) = 0;
    virtual HRESULT __stdcall put_Parity(winrt::Windows::Devices::SerialCommunication::SerialParity value) = 0;
    virtual HRESULT __stdcall get_PortName(hstring * value) = 0;
    virtual HRESULT __stdcall get_ReadTimeout(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_ReadTimeout(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_StopBits(winrt::Windows::Devices::SerialCommunication::SerialStopBitCount * value) = 0;
    virtual HRESULT __stdcall put_StopBits(winrt::Windows::Devices::SerialCommunication::SerialStopBitCount value) = 0;
    virtual HRESULT __stdcall get_UsbVendorId(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_UsbProductId(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_WriteTimeout(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_WriteTimeout(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_InputStream(Windows::Storage::Streams::IInputStream ** value) = 0;
    virtual HRESULT __stdcall get_OutputStream(Windows::Storage::Streams::IOutputStream ** value) = 0;
    virtual HRESULT __stdcall add_ErrorReceived(Windows::Foundation::TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::ErrorReceivedEventArgs> * reportHandler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ErrorReceived(event_token token) = 0;
    virtual HRESULT __stdcall add_PinChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::PinChangedEventArgs> * reportHandler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PinChanged(event_token token) = 0;
};

struct __declspec(uuid("058c4a70-0836-4993-ae1a-b61ae3be056b")) __declspec(novtable) ISerialDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromPortName(hstring portName, hstring * result) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromUsbVidPid(uint16_t vendorId, uint16_t productId, hstring * result) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::SerialCommunication::SerialDevice> ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::SerialCommunication::ErrorReceivedEventArgs> { using default_interface = Windows::Devices::SerialCommunication::IErrorReceivedEventArgs; };
template <> struct traits<Windows::Devices::SerialCommunication::PinChangedEventArgs> { using default_interface = Windows::Devices::SerialCommunication::IPinChangedEventArgs; };
template <> struct traits<Windows::Devices::SerialCommunication::SerialDevice> { using default_interface = Windows::Devices::SerialCommunication::ISerialDevice; };

}

namespace Windows::Devices::SerialCommunication {

template <typename D>
struct WINRT_EBO impl_IErrorReceivedEventArgs
{
    Windows::Devices::SerialCommunication::SerialError Error() const;
};

template <typename D>
struct WINRT_EBO impl_IPinChangedEventArgs
{
    Windows::Devices::SerialCommunication::SerialPinChange PinChange() const;
};

template <typename D>
struct WINRT_EBO impl_ISerialDevice
{
    uint32_t BaudRate() const;
    void BaudRate(uint32_t value) const;
    bool BreakSignalState() const;
    void BreakSignalState(bool value) const;
    uint32_t BytesReceived() const;
    bool CarrierDetectState() const;
    bool ClearToSendState() const;
    uint16_t DataBits() const;
    void DataBits(uint16_t value) const;
    bool DataSetReadyState() const;
    Windows::Devices::SerialCommunication::SerialHandshake Handshake() const;
    void Handshake(Windows::Devices::SerialCommunication::SerialHandshake value) const;
    bool IsDataTerminalReadyEnabled() const;
    void IsDataTerminalReadyEnabled(bool value) const;
    bool IsRequestToSendEnabled() const;
    void IsRequestToSendEnabled(bool value) const;
    Windows::Devices::SerialCommunication::SerialParity Parity() const;
    void Parity(Windows::Devices::SerialCommunication::SerialParity value) const;
    hstring PortName() const;
    Windows::Foundation::TimeSpan ReadTimeout() const;
    void ReadTimeout(const Windows::Foundation::TimeSpan & value) const;
    Windows::Devices::SerialCommunication::SerialStopBitCount StopBits() const;
    void StopBits(Windows::Devices::SerialCommunication::SerialStopBitCount value) const;
    uint16_t UsbVendorId() const;
    uint16_t UsbProductId() const;
    Windows::Foundation::TimeSpan WriteTimeout() const;
    void WriteTimeout(const Windows::Foundation::TimeSpan & value) const;
    Windows::Storage::Streams::IInputStream InputStream() const;
    Windows::Storage::Streams::IOutputStream OutputStream() const;
    event_token ErrorReceived(const Windows::Foundation::TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::ErrorReceivedEventArgs> & reportHandler) const;
    using ErrorReceived_revoker = event_revoker<ISerialDevice>;
    ErrorReceived_revoker ErrorReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::ErrorReceivedEventArgs> & reportHandler) const;
    void ErrorReceived(event_token token) const;
    event_token PinChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::PinChangedEventArgs> & reportHandler) const;
    using PinChanged_revoker = event_revoker<ISerialDevice>;
    PinChanged_revoker PinChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::PinChangedEventArgs> & reportHandler) const;
    void PinChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ISerialDeviceStatics
{
    hstring GetDeviceSelector() const;
    hstring GetDeviceSelector(hstring_view portName) const;
    hstring GetDeviceSelectorFromUsbVidPid(uint16_t vendorId, uint16_t productId) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::SerialCommunication::SerialDevice> FromIdAsync(hstring_view deviceId) const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::SerialCommunication::IErrorReceivedEventArgs>
{
    using abi = ABI::Windows::Devices::SerialCommunication::IErrorReceivedEventArgs;
    template <typename D> using consume = Windows::Devices::SerialCommunication::impl_IErrorReceivedEventArgs<D>;
};

template <> struct traits<Windows::Devices::SerialCommunication::IPinChangedEventArgs>
{
    using abi = ABI::Windows::Devices::SerialCommunication::IPinChangedEventArgs;
    template <typename D> using consume = Windows::Devices::SerialCommunication::impl_IPinChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::SerialCommunication::ISerialDevice>
{
    using abi = ABI::Windows::Devices::SerialCommunication::ISerialDevice;
    template <typename D> using consume = Windows::Devices::SerialCommunication::impl_ISerialDevice<D>;
};

template <> struct traits<Windows::Devices::SerialCommunication::ISerialDeviceStatics>
{
    using abi = ABI::Windows::Devices::SerialCommunication::ISerialDeviceStatics;
    template <typename D> using consume = Windows::Devices::SerialCommunication::impl_ISerialDeviceStatics<D>;
};

template <> struct traits<Windows::Devices::SerialCommunication::ErrorReceivedEventArgs>
{
    using abi = ABI::Windows::Devices::SerialCommunication::ErrorReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SerialCommunication.ErrorReceivedEventArgs"; }
};

template <> struct traits<Windows::Devices::SerialCommunication::PinChangedEventArgs>
{
    using abi = ABI::Windows::Devices::SerialCommunication::PinChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SerialCommunication.PinChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::SerialCommunication::SerialDevice>
{
    using abi = ABI::Windows::Devices::SerialCommunication::SerialDevice;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.SerialCommunication.SerialDevice"; }
};

}

}
