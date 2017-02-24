// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.System.Diagnostics.3.h"
#include "Windows.System.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::System::Diagnostics::IProcessCpuUsage> : produce_base<D, Windows::System::Diagnostics::IProcessCpuUsage>
{
    HRESULT __stdcall abi_GetReport(impl::abi_arg_out<Windows::System::Diagnostics::IProcessCpuUsageReport> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetReport());
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
struct produce<D, Windows::System::Diagnostics::IProcessCpuUsageReport> : produce_base<D, Windows::System::Diagnostics::IProcessCpuUsageReport>
{
    HRESULT __stdcall get_KernelTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KernelTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::Diagnostics::IProcessDiagnosticInfo> : produce_base<D, Windows::System::Diagnostics::IProcessDiagnosticInfo>
{
    HRESULT __stdcall get_ProcessId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProcessId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExecutableFileName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExecutableFileName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Parent(impl::abi_arg_out<Windows::System::Diagnostics::IProcessDiagnosticInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Parent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProcessStartTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProcessStartTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DiskUsage(impl::abi_arg_out<Windows::System::Diagnostics::IProcessDiskUsage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DiskUsage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MemoryUsage(impl::abi_arg_out<Windows::System::Diagnostics::IProcessMemoryUsage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MemoryUsage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CpuUsage(impl::abi_arg_out<Windows::System::Diagnostics::IProcessCpuUsage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CpuUsage());
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
struct produce<D, Windows::System::Diagnostics::IProcessDiagnosticInfoStatics> : produce_base<D, Windows::System::Diagnostics::IProcessDiagnosticInfoStatics>
{
    HRESULT __stdcall abi_GetForProcesses(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::System::Diagnostics::ProcessDiagnosticInfo>> processes) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *processes = detach_abi(this->shim().GetForProcesses());
            return S_OK;
        }
        catch (...)
        {
            *processes = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetForCurrentProcess(impl::abi_arg_out<Windows::System::Diagnostics::IProcessDiagnosticInfo> processes) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *processes = detach_abi(this->shim().GetForCurrentProcess());
            return S_OK;
        }
        catch (...)
        {
            *processes = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::Diagnostics::IProcessDiskUsage> : produce_base<D, Windows::System::Diagnostics::IProcessDiskUsage>
{
    HRESULT __stdcall abi_GetReport(impl::abi_arg_out<Windows::System::Diagnostics::IProcessDiskUsageReport> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetReport());
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
struct produce<D, Windows::System::Diagnostics::IProcessDiskUsageReport> : produce_base<D, Windows::System::Diagnostics::IProcessDiskUsageReport>
{
    HRESULT __stdcall get_ReadOperationCount(int64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadOperationCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WriteOperationCount(int64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WriteOperationCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OtherOperationCount(int64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OtherOperationCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BytesReadCount(int64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BytesReadCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BytesWrittenCount(int64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BytesWrittenCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OtherBytesCount(int64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OtherBytesCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::Diagnostics::IProcessMemoryUsage> : produce_base<D, Windows::System::Diagnostics::IProcessMemoryUsage>
{
    HRESULT __stdcall abi_GetReport(impl::abi_arg_out<Windows::System::Diagnostics::IProcessMemoryUsageReport> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetReport());
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
struct produce<D, Windows::System::Diagnostics::IProcessMemoryUsageReport> : produce_base<D, Windows::System::Diagnostics::IProcessMemoryUsageReport>
{
    HRESULT __stdcall get_NonPagedPoolSizeInBytes(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NonPagedPoolSizeInBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PageFaultCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PageFaultCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PageFileSizeInBytes(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PageFileSizeInBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PagedPoolSizeInBytes(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PagedPoolSizeInBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PeakNonPagedPoolSizeInBytes(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PeakNonPagedPoolSizeInBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PeakPageFileSizeInBytes(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PeakPageFileSizeInBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PeakPagedPoolSizeInBytes(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PeakPagedPoolSizeInBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PeakVirtualMemorySizeInBytes(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PeakVirtualMemorySizeInBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PeakWorkingSetSizeInBytes(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PeakWorkingSetSizeInBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PrivatePageCount(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrivatePageCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VirtualMemorySizeInBytes(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VirtualMemorySizeInBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WorkingSetSizeInBytes(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WorkingSetSizeInBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::System::Diagnostics {

template <typename D> uint32_t impl_IProcessDiagnosticInfo<D>::ProcessId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IProcessDiagnosticInfo)->get_ProcessId(&value));
    return value;
}

template <typename D> hstring impl_IProcessDiagnosticInfo<D>::ExecutableFileName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProcessDiagnosticInfo)->get_ExecutableFileName(put_abi(value)));
    return value;
}

template <typename D> Windows::System::Diagnostics::ProcessDiagnosticInfo impl_IProcessDiagnosticInfo<D>::Parent() const
{
    Windows::System::Diagnostics::ProcessDiagnosticInfo value { nullptr };
    check_hresult(WINRT_SHIM(IProcessDiagnosticInfo)->get_Parent(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IProcessDiagnosticInfo<D>::ProcessStartTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IProcessDiagnosticInfo)->get_ProcessStartTime(put_abi(value)));
    return value;
}

template <typename D> Windows::System::Diagnostics::ProcessDiskUsage impl_IProcessDiagnosticInfo<D>::DiskUsage() const
{
    Windows::System::Diagnostics::ProcessDiskUsage value { nullptr };
    check_hresult(WINRT_SHIM(IProcessDiagnosticInfo)->get_DiskUsage(put_abi(value)));
    return value;
}

template <typename D> Windows::System::Diagnostics::ProcessMemoryUsage impl_IProcessDiagnosticInfo<D>::MemoryUsage() const
{
    Windows::System::Diagnostics::ProcessMemoryUsage value { nullptr };
    check_hresult(WINRT_SHIM(IProcessDiagnosticInfo)->get_MemoryUsage(put_abi(value)));
    return value;
}

template <typename D> Windows::System::Diagnostics::ProcessCpuUsage impl_IProcessDiagnosticInfo<D>::CpuUsage() const
{
    Windows::System::Diagnostics::ProcessCpuUsage value { nullptr };
    check_hresult(WINRT_SHIM(IProcessDiagnosticInfo)->get_CpuUsage(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::System::Diagnostics::ProcessDiagnosticInfo> impl_IProcessDiagnosticInfoStatics<D>::GetForProcesses() const
{
    Windows::Foundation::Collections::IVectorView<Windows::System::Diagnostics::ProcessDiagnosticInfo> processes;
    check_hresult(WINRT_SHIM(IProcessDiagnosticInfoStatics)->abi_GetForProcesses(put_abi(processes)));
    return processes;
}

template <typename D> Windows::System::Diagnostics::ProcessDiagnosticInfo impl_IProcessDiagnosticInfoStatics<D>::GetForCurrentProcess() const
{
    Windows::System::Diagnostics::ProcessDiagnosticInfo processes { nullptr };
    check_hresult(WINRT_SHIM(IProcessDiagnosticInfoStatics)->abi_GetForCurrentProcess(put_abi(processes)));
    return processes;
}

template <typename D> Windows::System::Diagnostics::ProcessMemoryUsageReport impl_IProcessMemoryUsage<D>::GetReport() const
{
    Windows::System::Diagnostics::ProcessMemoryUsageReport value { nullptr };
    check_hresult(WINRT_SHIM(IProcessMemoryUsage)->abi_GetReport(put_abi(value)));
    return value;
}

template <typename D> uint64_t impl_IProcessMemoryUsageReport<D>::NonPagedPoolSizeInBytes() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IProcessMemoryUsageReport)->get_NonPagedPoolSizeInBytes(&value));
    return value;
}

template <typename D> uint32_t impl_IProcessMemoryUsageReport<D>::PageFaultCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IProcessMemoryUsageReport)->get_PageFaultCount(&value));
    return value;
}

template <typename D> uint64_t impl_IProcessMemoryUsageReport<D>::PageFileSizeInBytes() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IProcessMemoryUsageReport)->get_PageFileSizeInBytes(&value));
    return value;
}

template <typename D> uint64_t impl_IProcessMemoryUsageReport<D>::PagedPoolSizeInBytes() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IProcessMemoryUsageReport)->get_PagedPoolSizeInBytes(&value));
    return value;
}

template <typename D> uint64_t impl_IProcessMemoryUsageReport<D>::PeakNonPagedPoolSizeInBytes() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IProcessMemoryUsageReport)->get_PeakNonPagedPoolSizeInBytes(&value));
    return value;
}

template <typename D> uint64_t impl_IProcessMemoryUsageReport<D>::PeakPageFileSizeInBytes() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IProcessMemoryUsageReport)->get_PeakPageFileSizeInBytes(&value));
    return value;
}

template <typename D> uint64_t impl_IProcessMemoryUsageReport<D>::PeakPagedPoolSizeInBytes() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IProcessMemoryUsageReport)->get_PeakPagedPoolSizeInBytes(&value));
    return value;
}

template <typename D> uint64_t impl_IProcessMemoryUsageReport<D>::PeakVirtualMemorySizeInBytes() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IProcessMemoryUsageReport)->get_PeakVirtualMemorySizeInBytes(&value));
    return value;
}

template <typename D> uint64_t impl_IProcessMemoryUsageReport<D>::PeakWorkingSetSizeInBytes() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IProcessMemoryUsageReport)->get_PeakWorkingSetSizeInBytes(&value));
    return value;
}

template <typename D> uint64_t impl_IProcessMemoryUsageReport<D>::PrivatePageCount() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IProcessMemoryUsageReport)->get_PrivatePageCount(&value));
    return value;
}

template <typename D> uint64_t impl_IProcessMemoryUsageReport<D>::VirtualMemorySizeInBytes() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IProcessMemoryUsageReport)->get_VirtualMemorySizeInBytes(&value));
    return value;
}

template <typename D> uint64_t impl_IProcessMemoryUsageReport<D>::WorkingSetSizeInBytes() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IProcessMemoryUsageReport)->get_WorkingSetSizeInBytes(&value));
    return value;
}

template <typename D> Windows::System::Diagnostics::ProcessDiskUsageReport impl_IProcessDiskUsage<D>::GetReport() const
{
    Windows::System::Diagnostics::ProcessDiskUsageReport value { nullptr };
    check_hresult(WINRT_SHIM(IProcessDiskUsage)->abi_GetReport(put_abi(value)));
    return value;
}

template <typename D> int64_t impl_IProcessDiskUsageReport<D>::ReadOperationCount() const
{
    int64_t value {};
    check_hresult(WINRT_SHIM(IProcessDiskUsageReport)->get_ReadOperationCount(&value));
    return value;
}

template <typename D> int64_t impl_IProcessDiskUsageReport<D>::WriteOperationCount() const
{
    int64_t value {};
    check_hresult(WINRT_SHIM(IProcessDiskUsageReport)->get_WriteOperationCount(&value));
    return value;
}

template <typename D> int64_t impl_IProcessDiskUsageReport<D>::OtherOperationCount() const
{
    int64_t value {};
    check_hresult(WINRT_SHIM(IProcessDiskUsageReport)->get_OtherOperationCount(&value));
    return value;
}

template <typename D> int64_t impl_IProcessDiskUsageReport<D>::BytesReadCount() const
{
    int64_t value {};
    check_hresult(WINRT_SHIM(IProcessDiskUsageReport)->get_BytesReadCount(&value));
    return value;
}

template <typename D> int64_t impl_IProcessDiskUsageReport<D>::BytesWrittenCount() const
{
    int64_t value {};
    check_hresult(WINRT_SHIM(IProcessDiskUsageReport)->get_BytesWrittenCount(&value));
    return value;
}

template <typename D> int64_t impl_IProcessDiskUsageReport<D>::OtherBytesCount() const
{
    int64_t value {};
    check_hresult(WINRT_SHIM(IProcessDiskUsageReport)->get_OtherBytesCount(&value));
    return value;
}

template <typename D> Windows::System::Diagnostics::ProcessCpuUsageReport impl_IProcessCpuUsage<D>::GetReport() const
{
    Windows::System::Diagnostics::ProcessCpuUsageReport value { nullptr };
    check_hresult(WINRT_SHIM(IProcessCpuUsage)->abi_GetReport(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IProcessCpuUsageReport<D>::KernelTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IProcessCpuUsageReport)->get_KernelTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IProcessCpuUsageReport<D>::UserTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IProcessCpuUsageReport)->get_UserTime(put_abi(value)));
    return value;
}

inline Windows::Foundation::Collections::IVectorView<Windows::System::Diagnostics::ProcessDiagnosticInfo> ProcessDiagnosticInfo::GetForProcesses()
{
    return get_activation_factory<ProcessDiagnosticInfo, IProcessDiagnosticInfoStatics>().GetForProcesses();
}

inline Windows::System::Diagnostics::ProcessDiagnosticInfo ProcessDiagnosticInfo::GetForCurrentProcess()
{
    return get_activation_factory<ProcessDiagnosticInfo, IProcessDiagnosticInfoStatics>().GetForCurrentProcess();
}

}

}
#pragma warning(pop)
