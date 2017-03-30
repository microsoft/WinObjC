// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.System.Diagnostics.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::System::Diagnostics {

struct __declspec(uuid("0bbb2472-c8bf-423a-a810-b559ae4354e2")) __declspec(novtable) IProcessCpuUsage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetReport(Windows::System::Diagnostics::IProcessCpuUsageReport ** value) = 0;
};

struct __declspec(uuid("8a6d9cac-3987-4e2f-a119-6b5fa214f1b4")) __declspec(novtable) IProcessCpuUsageReport : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_KernelTime(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_UserTime(Windows::Foundation::TimeSpan * value) = 0;
};

struct __declspec(uuid("e830b04b-300e-4ee6-a0ab-5b5f5231b434")) __declspec(novtable) IProcessDiagnosticInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ProcessId(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_ExecutableFileName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Parent(Windows::System::Diagnostics::IProcessDiagnosticInfo ** value) = 0;
    virtual HRESULT __stdcall get_ProcessStartTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_DiskUsage(Windows::System::Diagnostics::IProcessDiskUsage ** value) = 0;
    virtual HRESULT __stdcall get_MemoryUsage(Windows::System::Diagnostics::IProcessMemoryUsage ** value) = 0;
    virtual HRESULT __stdcall get_CpuUsage(Windows::System::Diagnostics::IProcessCpuUsage ** value) = 0;
};

struct __declspec(uuid("2f41b260-b49f-428c-aa0e-84744f49ca95")) __declspec(novtable) IProcessDiagnosticInfoStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForProcesses(Windows::Foundation::Collections::IVectorView<Windows::System::Diagnostics::ProcessDiagnosticInfo> ** processes) = 0;
    virtual HRESULT __stdcall abi_GetForCurrentProcess(Windows::System::Diagnostics::IProcessDiagnosticInfo ** processes) = 0;
};

struct __declspec(uuid("5ad78bfd-7e51-4e53-bfaa-5a6ee1aabbf8")) __declspec(novtable) IProcessDiskUsage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetReport(Windows::System::Diagnostics::IProcessDiskUsageReport ** value) = 0;
};

struct __declspec(uuid("401627fd-535d-4c1f-81b8-da54e1be635e")) __declspec(novtable) IProcessDiskUsageReport : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ReadOperationCount(int64_t * value) = 0;
    virtual HRESULT __stdcall get_WriteOperationCount(int64_t * value) = 0;
    virtual HRESULT __stdcall get_OtherOperationCount(int64_t * value) = 0;
    virtual HRESULT __stdcall get_BytesReadCount(int64_t * value) = 0;
    virtual HRESULT __stdcall get_BytesWrittenCount(int64_t * value) = 0;
    virtual HRESULT __stdcall get_OtherBytesCount(int64_t * value) = 0;
};

struct __declspec(uuid("f50b229b-827c-42b7-b07c-0e32627e6b3e")) __declspec(novtable) IProcessMemoryUsage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetReport(Windows::System::Diagnostics::IProcessMemoryUsageReport ** value) = 0;
};

struct __declspec(uuid("c2c77cba-1951-4685-8532-7e749ecf8eeb")) __declspec(novtable) IProcessMemoryUsageReport : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NonPagedPoolSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_PageFaultCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_PageFileSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_PagedPoolSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_PeakNonPagedPoolSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_PeakPageFileSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_PeakPagedPoolSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_PeakVirtualMemorySizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_PeakWorkingSetSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_PrivatePageCount(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_VirtualMemorySizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_WorkingSetSizeInBytes(uint64_t * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::System::Diagnostics::ProcessCpuUsage> { using default_interface = Windows::System::Diagnostics::IProcessCpuUsage; };
template <> struct traits<Windows::System::Diagnostics::ProcessCpuUsageReport> { using default_interface = Windows::System::Diagnostics::IProcessCpuUsageReport; };
template <> struct traits<Windows::System::Diagnostics::ProcessDiagnosticInfo> { using default_interface = Windows::System::Diagnostics::IProcessDiagnosticInfo; };
template <> struct traits<Windows::System::Diagnostics::ProcessDiskUsage> { using default_interface = Windows::System::Diagnostics::IProcessDiskUsage; };
template <> struct traits<Windows::System::Diagnostics::ProcessDiskUsageReport> { using default_interface = Windows::System::Diagnostics::IProcessDiskUsageReport; };
template <> struct traits<Windows::System::Diagnostics::ProcessMemoryUsage> { using default_interface = Windows::System::Diagnostics::IProcessMemoryUsage; };
template <> struct traits<Windows::System::Diagnostics::ProcessMemoryUsageReport> { using default_interface = Windows::System::Diagnostics::IProcessMemoryUsageReport; };

}

namespace Windows::System::Diagnostics {

template <typename D>
struct WINRT_EBO impl_IProcessCpuUsage
{
    Windows::System::Diagnostics::ProcessCpuUsageReport GetReport() const;
};

template <typename D>
struct WINRT_EBO impl_IProcessCpuUsageReport
{
    Windows::Foundation::TimeSpan KernelTime() const;
    Windows::Foundation::TimeSpan UserTime() const;
};

template <typename D>
struct WINRT_EBO impl_IProcessDiagnosticInfo
{
    uint32_t ProcessId() const;
    hstring ExecutableFileName() const;
    Windows::System::Diagnostics::ProcessDiagnosticInfo Parent() const;
    Windows::Foundation::DateTime ProcessStartTime() const;
    Windows::System::Diagnostics::ProcessDiskUsage DiskUsage() const;
    Windows::System::Diagnostics::ProcessMemoryUsage MemoryUsage() const;
    Windows::System::Diagnostics::ProcessCpuUsage CpuUsage() const;
};

template <typename D>
struct WINRT_EBO impl_IProcessDiagnosticInfoStatics
{
    Windows::Foundation::Collections::IVectorView<Windows::System::Diagnostics::ProcessDiagnosticInfo> GetForProcesses() const;
    Windows::System::Diagnostics::ProcessDiagnosticInfo GetForCurrentProcess() const;
};

template <typename D>
struct WINRT_EBO impl_IProcessDiskUsage
{
    Windows::System::Diagnostics::ProcessDiskUsageReport GetReport() const;
};

template <typename D>
struct WINRT_EBO impl_IProcessDiskUsageReport
{
    int64_t ReadOperationCount() const;
    int64_t WriteOperationCount() const;
    int64_t OtherOperationCount() const;
    int64_t BytesReadCount() const;
    int64_t BytesWrittenCount() const;
    int64_t OtherBytesCount() const;
};

template <typename D>
struct WINRT_EBO impl_IProcessMemoryUsage
{
    Windows::System::Diagnostics::ProcessMemoryUsageReport GetReport() const;
};

template <typename D>
struct WINRT_EBO impl_IProcessMemoryUsageReport
{
    uint64_t NonPagedPoolSizeInBytes() const;
    uint32_t PageFaultCount() const;
    uint64_t PageFileSizeInBytes() const;
    uint64_t PagedPoolSizeInBytes() const;
    uint64_t PeakNonPagedPoolSizeInBytes() const;
    uint64_t PeakPageFileSizeInBytes() const;
    uint64_t PeakPagedPoolSizeInBytes() const;
    uint64_t PeakVirtualMemorySizeInBytes() const;
    uint64_t PeakWorkingSetSizeInBytes() const;
    uint64_t PrivatePageCount() const;
    uint64_t VirtualMemorySizeInBytes() const;
    uint64_t WorkingSetSizeInBytes() const;
};

}

namespace impl {

template <> struct traits<Windows::System::Diagnostics::IProcessCpuUsage>
{
    using abi = ABI::Windows::System::Diagnostics::IProcessCpuUsage;
    template <typename D> using consume = Windows::System::Diagnostics::impl_IProcessCpuUsage<D>;
};

template <> struct traits<Windows::System::Diagnostics::IProcessCpuUsageReport>
{
    using abi = ABI::Windows::System::Diagnostics::IProcessCpuUsageReport;
    template <typename D> using consume = Windows::System::Diagnostics::impl_IProcessCpuUsageReport<D>;
};

template <> struct traits<Windows::System::Diagnostics::IProcessDiagnosticInfo>
{
    using abi = ABI::Windows::System::Diagnostics::IProcessDiagnosticInfo;
    template <typename D> using consume = Windows::System::Diagnostics::impl_IProcessDiagnosticInfo<D>;
};

template <> struct traits<Windows::System::Diagnostics::IProcessDiagnosticInfoStatics>
{
    using abi = ABI::Windows::System::Diagnostics::IProcessDiagnosticInfoStatics;
    template <typename D> using consume = Windows::System::Diagnostics::impl_IProcessDiagnosticInfoStatics<D>;
};

template <> struct traits<Windows::System::Diagnostics::IProcessDiskUsage>
{
    using abi = ABI::Windows::System::Diagnostics::IProcessDiskUsage;
    template <typename D> using consume = Windows::System::Diagnostics::impl_IProcessDiskUsage<D>;
};

template <> struct traits<Windows::System::Diagnostics::IProcessDiskUsageReport>
{
    using abi = ABI::Windows::System::Diagnostics::IProcessDiskUsageReport;
    template <typename D> using consume = Windows::System::Diagnostics::impl_IProcessDiskUsageReport<D>;
};

template <> struct traits<Windows::System::Diagnostics::IProcessMemoryUsage>
{
    using abi = ABI::Windows::System::Diagnostics::IProcessMemoryUsage;
    template <typename D> using consume = Windows::System::Diagnostics::impl_IProcessMemoryUsage<D>;
};

template <> struct traits<Windows::System::Diagnostics::IProcessMemoryUsageReport>
{
    using abi = ABI::Windows::System::Diagnostics::IProcessMemoryUsageReport;
    template <typename D> using consume = Windows::System::Diagnostics::impl_IProcessMemoryUsageReport<D>;
};

template <> struct traits<Windows::System::Diagnostics::ProcessCpuUsage>
{
    using abi = ABI::Windows::System::Diagnostics::ProcessCpuUsage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Diagnostics.ProcessCpuUsage"; }
};

template <> struct traits<Windows::System::Diagnostics::ProcessCpuUsageReport>
{
    using abi = ABI::Windows::System::Diagnostics::ProcessCpuUsageReport;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Diagnostics.ProcessCpuUsageReport"; }
};

template <> struct traits<Windows::System::Diagnostics::ProcessDiagnosticInfo>
{
    using abi = ABI::Windows::System::Diagnostics::ProcessDiagnosticInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Diagnostics.ProcessDiagnosticInfo"; }
};

template <> struct traits<Windows::System::Diagnostics::ProcessDiskUsage>
{
    using abi = ABI::Windows::System::Diagnostics::ProcessDiskUsage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Diagnostics.ProcessDiskUsage"; }
};

template <> struct traits<Windows::System::Diagnostics::ProcessDiskUsageReport>
{
    using abi = ABI::Windows::System::Diagnostics::ProcessDiskUsageReport;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Diagnostics.ProcessDiskUsageReport"; }
};

template <> struct traits<Windows::System::Diagnostics::ProcessMemoryUsage>
{
    using abi = ABI::Windows::System::Diagnostics::ProcessMemoryUsage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Diagnostics.ProcessMemoryUsage"; }
};

template <> struct traits<Windows::System::Diagnostics::ProcessMemoryUsageReport>
{
    using abi = ABI::Windows::System::Diagnostics::ProcessMemoryUsageReport;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Diagnostics.ProcessMemoryUsageReport"; }
};

}

}
