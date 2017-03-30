// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Printers::Extensions {

struct IPrint3DWorkflow;
struct IPrint3DWorkflow2;
struct IPrint3DWorkflowPrintRequestedEventArgs;
struct IPrint3DWorkflowPrinterChangedEventArgs;
struct IPrintExtensionContextStatic;
struct IPrintNotificationEventDetails;
struct IPrintTaskConfiguration;
struct IPrintTaskConfigurationSaveRequest;
struct IPrintTaskConfigurationSaveRequestedDeferral;
struct IPrintTaskConfigurationSaveRequestedEventArgs;
struct Print3DWorkflow;
struct Print3DWorkflowPrintRequestedEventArgs;
struct Print3DWorkflowPrinterChangedEventArgs;
struct PrintNotificationEventDetails;
struct PrintTaskConfiguration;
struct PrintTaskConfigurationSaveRequest;
struct PrintTaskConfigurationSaveRequestedDeferral;
struct PrintTaskConfigurationSaveRequestedEventArgs;

}

namespace Windows::Devices::Printers::Extensions {

struct IPrint3DWorkflow;
struct IPrint3DWorkflow2;
struct IPrint3DWorkflowPrintRequestedEventArgs;
struct IPrint3DWorkflowPrinterChangedEventArgs;
struct IPrintExtensionContextStatic;
struct IPrintNotificationEventDetails;
struct IPrintTaskConfiguration;
struct IPrintTaskConfigurationSaveRequest;
struct IPrintTaskConfigurationSaveRequestedDeferral;
struct IPrintTaskConfigurationSaveRequestedEventArgs;
struct Print3DWorkflow;
struct Print3DWorkflowPrintRequestedEventArgs;
struct Print3DWorkflowPrinterChangedEventArgs;
struct PrintExtensionContext;
struct PrintNotificationEventDetails;
struct PrintTaskConfiguration;
struct PrintTaskConfigurationSaveRequest;
struct PrintTaskConfigurationSaveRequestedDeferral;
struct PrintTaskConfigurationSaveRequestedEventArgs;

}

namespace Windows::Devices::Printers::Extensions {

template <typename T> struct impl_IPrint3DWorkflow;
template <typename T> struct impl_IPrint3DWorkflow2;
template <typename T> struct impl_IPrint3DWorkflowPrintRequestedEventArgs;
template <typename T> struct impl_IPrint3DWorkflowPrinterChangedEventArgs;
template <typename T> struct impl_IPrintExtensionContextStatic;
template <typename T> struct impl_IPrintNotificationEventDetails;
template <typename T> struct impl_IPrintTaskConfiguration;
template <typename T> struct impl_IPrintTaskConfigurationSaveRequest;
template <typename T> struct impl_IPrintTaskConfigurationSaveRequestedDeferral;
template <typename T> struct impl_IPrintTaskConfigurationSaveRequestedEventArgs;

}

namespace Windows::Devices::Printers::Extensions {

enum class Print3DWorkflowDetail
{
    Unknown = 0,
    ModelExceedsPrintBed = 1,
    UploadFailed = 2,
    InvalidMaterialSelection = 3,
    InvalidModel = 4,
    ModelNotManifold = 5,
    InvalidPrintTicket = 6,
};

enum class Print3DWorkflowStatus
{
    Abandoned = 0,
    Canceled = 1,
    Failed = 2,
    Slicing = 3,
    Submitted = 4,
};

}

}
