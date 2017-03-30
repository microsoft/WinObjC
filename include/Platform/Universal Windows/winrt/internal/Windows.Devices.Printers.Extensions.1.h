// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Printers.Extensions.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Printers::Extensions {

struct __declspec(uuid("c56f74bd-3669-4a66-ab42-c8151930cd34")) __declspec(novtable) IPrint3DWorkflow : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceID(hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetPrintModelPackage(Windows::Foundation::IInspectable ** printModelPackage) = 0;
    virtual HRESULT __stdcall get_IsPrintReady(bool * value) = 0;
    virtual HRESULT __stdcall put_IsPrintReady(bool value) = 0;
    virtual HRESULT __stdcall add_PrintRequested(Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_PrintRequested(event_token eventCookie) = 0;
};

struct __declspec(uuid("a2a6c54f-8ac1-4918-9741-e34f3004239e")) __declspec(novtable) IPrint3DWorkflow2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_PrinterChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_PrinterChanged(event_token eventCookie) = 0;
};

struct __declspec(uuid("19f8c858-5ac8-4b55-8a5f-e61567dafb4d")) __declspec(novtable) IPrint3DWorkflowPrintRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Printers::Extensions::Print3DWorkflowStatus * value) = 0;
    virtual HRESULT __stdcall abi_SetExtendedStatus(winrt::Windows::Devices::Printers::Extensions::Print3DWorkflowDetail value) = 0;
    virtual HRESULT __stdcall abi_SetSource(Windows::Foundation::IInspectable * source) = 0;
    virtual HRESULT __stdcall abi_SetSourceChanged(bool value) = 0;
};

struct __declspec(uuid("45226402-95fc-4847-93b3-134dbf5c60f7")) __declspec(novtable) IPrint3DWorkflowPrinterChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NewDeviceId(hstring * value) = 0;
};

struct __declspec(uuid("e70d9fc1-ff79-4aa4-8c9b-0c93aedfde8a")) __declspec(novtable) IPrintExtensionContextStatic : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromDeviceId(hstring deviceId, Windows::Foundation::IInspectable ** context) = 0;
};

struct __declspec(uuid("e00e4c8a-4828-4da1-8bb8-8672df8515e7")) __declspec(novtable) IPrintNotificationEventDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PrinterName(hstring * value) = 0;
    virtual HRESULT __stdcall get_EventData(hstring * value) = 0;
    virtual HRESULT __stdcall put_EventData(hstring value) = 0;
};

struct __declspec(uuid("e3c22451-3aa4-4885-9240-311f5f8fbe9d")) __declspec(novtable) IPrintTaskConfiguration : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PrinterExtensionContext(Windows::Foundation::IInspectable ** context) = 0;
    virtual HRESULT __stdcall add_SaveRequested(Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::PrintTaskConfiguration, Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_SaveRequested(event_token eventCookie) = 0;
};

struct __declspec(uuid("eeaf2fcb-621e-4b62-ac77-b281cce08d60")) __declspec(novtable) IPrintTaskConfigurationSaveRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Cancel() = 0;
    virtual HRESULT __stdcall abi_Save(Windows::Foundation::IInspectable * printerExtensionContext) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral ** deferral) = 0;
    virtual HRESULT __stdcall get_Deadline(Windows::Foundation::DateTime * value) = 0;
};

struct __declspec(uuid("e959d568-f729-44a4-871d-bd0628696a33")) __declspec(novtable) IPrintTaskConfigurationSaveRequestedDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("e06c2879-0d61-4938-91d0-96a45bee8479")) __declspec(novtable) IPrintTaskConfigurationSaveRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest ** context) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Printers::Extensions::Print3DWorkflow> { using default_interface = Windows::Devices::Printers::Extensions::IPrint3DWorkflow; };
template <> struct traits<Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> { using default_interface = Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs; };
template <> struct traits<Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> { using default_interface = Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs; };
template <> struct traits<Windows::Devices::Printers::Extensions::PrintNotificationEventDetails> { using default_interface = Windows::Devices::Printers::Extensions::IPrintNotificationEventDetails; };
template <> struct traits<Windows::Devices::Printers::Extensions::PrintTaskConfiguration> { using default_interface = Windows::Devices::Printers::Extensions::IPrintTaskConfiguration; };
template <> struct traits<Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequest> { using default_interface = Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest; };
template <> struct traits<Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedDeferral> { using default_interface = Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral; };
template <> struct traits<Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedEventArgs> { using default_interface = Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedEventArgs; };

}

namespace Windows::Devices::Printers::Extensions {

template <typename D>
struct WINRT_EBO impl_IPrint3DWorkflow
{
    hstring DeviceID() const;
    Windows::Foundation::IInspectable GetPrintModelPackage() const;
    bool IsPrintReady() const;
    void IsPrintReady(bool value) const;
    event_token PrintRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> & eventHandler) const;
    using PrintRequested_revoker = event_revoker<IPrint3DWorkflow>;
    PrintRequested_revoker PrintRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> & eventHandler) const;
    void PrintRequested(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_IPrint3DWorkflow2
{
    event_token PrinterChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> & eventHandler) const;
    using PrinterChanged_revoker = event_revoker<IPrint3DWorkflow2>;
    PrinterChanged_revoker PrinterChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> & eventHandler) const;
    void PrinterChanged(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_IPrint3DWorkflowPrintRequestedEventArgs
{
    Windows::Devices::Printers::Extensions::Print3DWorkflowStatus Status() const;
    void SetExtendedStatus(Windows::Devices::Printers::Extensions::Print3DWorkflowDetail value) const;
    void SetSource(const Windows::Foundation::IInspectable & source) const;
    void SetSourceChanged(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IPrint3DWorkflowPrinterChangedEventArgs
{
    hstring NewDeviceId() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintExtensionContextStatic
{
    Windows::Foundation::IInspectable FromDeviceId(hstring_view deviceId) const;
};

template <typename D>
struct WINRT_EBO impl_IPrintNotificationEventDetails
{
    hstring PrinterName() const;
    hstring EventData() const;
    void EventData(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskConfiguration
{
    Windows::Foundation::IInspectable PrinterExtensionContext() const;
    event_token SaveRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::PrintTaskConfiguration, Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedEventArgs> & eventHandler) const;
    using SaveRequested_revoker = event_revoker<IPrintTaskConfiguration>;
    SaveRequested_revoker SaveRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::PrintTaskConfiguration, Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedEventArgs> & eventHandler) const;
    void SaveRequested(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskConfigurationSaveRequest
{
    void Cancel() const;
    void Save(const Windows::Foundation::IInspectable & printerExtensionContext) const;
    Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedDeferral GetDeferral() const;
    Windows::Foundation::DateTime Deadline() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskConfigurationSaveRequestedDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskConfigurationSaveRequestedEventArgs
{
    Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequest Request() const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Printers::Extensions::IPrint3DWorkflow>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow;
    template <typename D> using consume = Windows::Devices::Printers::Extensions::impl_IPrint3DWorkflow<D>;
};

template <> struct traits<Windows::Devices::Printers::Extensions::IPrint3DWorkflow2>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow2;
    template <typename D> using consume = Windows::Devices::Printers::Extensions::impl_IPrint3DWorkflow2<D>;
};

template <> struct traits<Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs;
    template <typename D> using consume = Windows::Devices::Printers::Extensions::impl_IPrint3DWorkflowPrintRequestedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Printers::Extensions::impl_IPrint3DWorkflowPrinterChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Printers::Extensions::IPrintExtensionContextStatic>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::IPrintExtensionContextStatic;
    template <typename D> using consume = Windows::Devices::Printers::Extensions::impl_IPrintExtensionContextStatic<D>;
};

template <> struct traits<Windows::Devices::Printers::Extensions::IPrintNotificationEventDetails>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::IPrintNotificationEventDetails;
    template <typename D> using consume = Windows::Devices::Printers::Extensions::impl_IPrintNotificationEventDetails<D>;
};

template <> struct traits<Windows::Devices::Printers::Extensions::IPrintTaskConfiguration>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfiguration;
    template <typename D> using consume = Windows::Devices::Printers::Extensions::impl_IPrintTaskConfiguration<D>;
};

template <> struct traits<Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest;
    template <typename D> using consume = Windows::Devices::Printers::Extensions::impl_IPrintTaskConfigurationSaveRequest<D>;
};

template <> struct traits<Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral;
    template <typename D> using consume = Windows::Devices::Printers::Extensions::impl_IPrintTaskConfigurationSaveRequestedDeferral<D>;
};

template <> struct traits<Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedEventArgs>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedEventArgs;
    template <typename D> using consume = Windows::Devices::Printers::Extensions::impl_IPrintTaskConfigurationSaveRequestedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Printers::Extensions::Print3DWorkflow>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::Print3DWorkflow;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Printers.Extensions.Print3DWorkflow"; }
};

template <> struct traits<Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Printers.Extensions.Print3DWorkflowPrintRequestedEventArgs"; }
};

template <> struct traits<Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Printers.Extensions.Print3DWorkflowPrinterChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Printers::Extensions::PrintExtensionContext>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Printers.Extensions.PrintExtensionContext"; }
};

template <> struct traits<Windows::Devices::Printers::Extensions::PrintNotificationEventDetails>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::PrintNotificationEventDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Printers.Extensions.PrintNotificationEventDetails"; }
};

template <> struct traits<Windows::Devices::Printers::Extensions::PrintTaskConfiguration>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::PrintTaskConfiguration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Printers.Extensions.PrintTaskConfiguration"; }
};

template <> struct traits<Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequest>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Printers.Extensions.PrintTaskConfigurationSaveRequest"; }
};

template <> struct traits<Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedDeferral>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Printers.Extensions.PrintTaskConfigurationSaveRequestedDeferral"; }
};

template <> struct traits<Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedEventArgs>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Printers.Extensions.PrintTaskConfigurationSaveRequestedEventArgs"; }
};

}

}
