// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Printers.Extensions.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Printers::Extensions {

struct WINRT_EBO Print3DWorkflow :
    Windows::Devices::Printers::Extensions::IPrint3DWorkflow,
    impl::require<Print3DWorkflow, Windows::Devices::Printers::Extensions::IPrint3DWorkflow2>
{
    Print3DWorkflow(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Print3DWorkflowPrintRequestedEventArgs :
    Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs
{
    Print3DWorkflowPrintRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Print3DWorkflowPrinterChangedEventArgs :
    Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs
{
    Print3DWorkflowPrinterChangedEventArgs(std::nullptr_t) noexcept {}
};

struct PrintExtensionContext
{
    PrintExtensionContext() = delete;
    static Windows::Foundation::IInspectable FromDeviceId(hstring_view deviceId);
};

struct WINRT_EBO PrintNotificationEventDetails :
    Windows::Devices::Printers::Extensions::IPrintNotificationEventDetails
{
    PrintNotificationEventDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintTaskConfiguration :
    Windows::Devices::Printers::Extensions::IPrintTaskConfiguration
{
    PrintTaskConfiguration(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintTaskConfigurationSaveRequest :
    Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest
{
    PrintTaskConfigurationSaveRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintTaskConfigurationSaveRequestedDeferral :
    Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral
{
    PrintTaskConfigurationSaveRequestedDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintTaskConfigurationSaveRequestedEventArgs :
    Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedEventArgs
{
    PrintTaskConfigurationSaveRequestedEventArgs(std::nullptr_t) noexcept {}
};

}

}
