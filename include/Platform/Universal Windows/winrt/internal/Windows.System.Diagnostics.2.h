// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Diagnostics.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_74ab2473_9624_5a06_9025_6d91e622bf8e
#define WINRT_GENERIC_74ab2473_9624_5a06_9025_6d91e622bf8e
template <> struct __declspec(uuid("74ab2473-9624-5a06-9025-6d91e622bf8e")) __declspec(novtable) IVectorView<Windows::System::Diagnostics::ProcessDiagnosticInfo> : impl_IVectorView<Windows::System::Diagnostics::ProcessDiagnosticInfo> {};
#endif

#ifndef WINRT_GENERIC_a89b4418_4c3b_5f49_b957_785697c99abf
#define WINRT_GENERIC_a89b4418_4c3b_5f49_b957_785697c99abf
template <> struct __declspec(uuid("a89b4418-4c3b-5f49-b957-785697c99abf")) __declspec(novtable) IIterator<Windows::System::Diagnostics::ProcessDiagnosticInfo> : impl_IIterator<Windows::System::Diagnostics::ProcessDiagnosticInfo> {};
#endif

#ifndef WINRT_GENERIC_97b73627_b296_5076_b8cd_6bd8a240e966
#define WINRT_GENERIC_97b73627_b296_5076_b8cd_6bd8a240e966
template <> struct __declspec(uuid("97b73627-b296-5076-b8cd-6bd8a240e966")) __declspec(novtable) IIterable<Windows::System::Diagnostics::ProcessDiagnosticInfo> : impl_IIterable<Windows::System::Diagnostics::ProcessDiagnosticInfo> {};
#endif


}

namespace Windows::System::Diagnostics {

struct IProcessCpuUsage :
    Windows::Foundation::IInspectable,
    impl::consume<IProcessCpuUsage>
{
    IProcessCpuUsage(std::nullptr_t = nullptr) noexcept {}
};

struct IProcessCpuUsageReport :
    Windows::Foundation::IInspectable,
    impl::consume<IProcessCpuUsageReport>
{
    IProcessCpuUsageReport(std::nullptr_t = nullptr) noexcept {}
};

struct IProcessDiagnosticInfo :
    Windows::Foundation::IInspectable,
    impl::consume<IProcessDiagnosticInfo>
{
    IProcessDiagnosticInfo(std::nullptr_t = nullptr) noexcept {}
};

struct IProcessDiagnosticInfoStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IProcessDiagnosticInfoStatics>
{
    IProcessDiagnosticInfoStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IProcessDiskUsage :
    Windows::Foundation::IInspectable,
    impl::consume<IProcessDiskUsage>
{
    IProcessDiskUsage(std::nullptr_t = nullptr) noexcept {}
};

struct IProcessDiskUsageReport :
    Windows::Foundation::IInspectable,
    impl::consume<IProcessDiskUsageReport>
{
    IProcessDiskUsageReport(std::nullptr_t = nullptr) noexcept {}
};

struct IProcessMemoryUsage :
    Windows::Foundation::IInspectable,
    impl::consume<IProcessMemoryUsage>
{
    IProcessMemoryUsage(std::nullptr_t = nullptr) noexcept {}
};

struct IProcessMemoryUsageReport :
    Windows::Foundation::IInspectable,
    impl::consume<IProcessMemoryUsageReport>
{
    IProcessMemoryUsageReport(std::nullptr_t = nullptr) noexcept {}
};

}

}
