// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Printers.Extensions.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5f4c6603_5512_59aa_8d96_b1389d8b5796
#define WINRT_GENERIC_5f4c6603_5512_59aa_8d96_b1389d8b5796
template <> struct __declspec(uuid("5f4c6603-5512-59aa-8d96-b1389d8b5796")) __declspec(novtable) TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> : impl_TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_b4b5ddc2_1a74_5905_9fc5_ddaae9a3ab93
#define WINRT_GENERIC_b4b5ddc2_1a74_5905_9fc5_ddaae9a3ab93
template <> struct __declspec(uuid("b4b5ddc2-1a74-5905-9fc5-ddaae9a3ab93")) __declspec(novtable) TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_0363f57a_b7a2_5e20_a156_253423e7ee40
#define WINRT_GENERIC_0363f57a_b7a2_5e20_a156_253423e7ee40
template <> struct __declspec(uuid("0363f57a-b7a2-5e20-a156-253423e7ee40")) __declspec(novtable) TypedEventHandler<Windows::Devices::Printers::Extensions::PrintTaskConfiguration, Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedEventArgs> : impl_TypedEventHandler<Windows::Devices::Printers::Extensions::PrintTaskConfiguration, Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedEventArgs> {};
#endif


}

namespace Windows::Devices::Printers::Extensions {

struct IPrint3DWorkflow :
    Windows::Foundation::IInspectable,
    impl::consume<IPrint3DWorkflow>
{
    IPrint3DWorkflow(std::nullptr_t = nullptr) noexcept {}
};

struct IPrint3DWorkflow2 :
    Windows::Foundation::IInspectable,
    impl::consume<IPrint3DWorkflow2>
{
    IPrint3DWorkflow2(std::nullptr_t = nullptr) noexcept {}
};

struct IPrint3DWorkflowPrintRequestedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPrint3DWorkflowPrintRequestedEventArgs>
{
    IPrint3DWorkflowPrintRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPrint3DWorkflowPrinterChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPrint3DWorkflowPrinterChangedEventArgs>
{
    IPrint3DWorkflowPrinterChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintExtensionContextStatic :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintExtensionContextStatic>
{
    IPrintExtensionContextStatic(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintNotificationEventDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintNotificationEventDetails>
{
    IPrintNotificationEventDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskConfiguration :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskConfiguration>
{
    IPrintTaskConfiguration(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskConfigurationSaveRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskConfigurationSaveRequest>
{
    IPrintTaskConfigurationSaveRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskConfigurationSaveRequestedDeferral :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskConfigurationSaveRequestedDeferral>
{
    IPrintTaskConfigurationSaveRequestedDeferral(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskConfigurationSaveRequestedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskConfigurationSaveRequestedEventArgs>
{
    IPrintTaskConfigurationSaveRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

}

}
