//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#include <Windows.h>
#include <mach/mach.h>

#include <COMIncludes.h>
#include <wrl\wrappers\corewrappers.h>
#include <wrl\client.h>
#include <windows.system.diagnostics.h>
#include <COMIncludes_End.h>
#include <wil\result.h>
#include <ErrorHandling.h>

using namespace Microsoft::WRL;
using namespace ABI::Windows::System::Diagnostics;
using namespace Windows::Foundation;

// helper function to get current process diagnostic info
static HRESULT _getProcessDiagnosticInfo(IProcessDiagnosticInfo** ppProcessDiagnosticInfo) {
    ComPtr<IProcessDiagnosticInfoStatics> processDiagnosticInfoStatics;

    RETURN_IF_FAILED_LOG(
        GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_System_Diagnostics_ProcessDiagnosticInfo).Get(),
                             &processDiagnosticInfoStatics));

    return processDiagnosticInfoStatics->GetForCurrentProcess(ppProcessDiagnosticInfo);
}

// helper function to get the process memory usage through IProcessDiagnosticInfo
static HRESULT _getProcessMemoryUsage(vm_size_t& virtualSize, vm_size_t& workingSetSize) {
    ComPtr<IProcessDiagnosticInfo> processDiagnosticInfo;
    RETURN_IF_FAILED(_getProcessDiagnosticInfo(&processDiagnosticInfo));

    ComPtr<IProcessMemoryUsage> processMemoryUsage;
    RETURN_IF_FAILED(processDiagnosticInfo->get_MemoryUsage(&processMemoryUsage));

    ComPtr<IProcessMemoryUsageReport> processMemoryUsageReport;
    RETURN_IF_FAILED(processMemoryUsage->GetReport(&processMemoryUsageReport));

    unsigned __int64 virtualBytes;
    unsigned __int64 workingSetBytes;

    RETURN_IF_FAILED(processMemoryUsageReport->get_VirtualMemorySizeInBytes(&virtualBytes));
    RETURN_IF_FAILED(processMemoryUsageReport->get_WorkingSetSizeInBytes(&workingSetBytes));

    // NOTE: possible data loss, but we are mostly not dealing with > 4GB address space
    virtualSize = virtualBytes;
    workingSetSize = workingSetBytes;

    return S_OK;
}

static const int MICROSEC_TO_SEC = 1000 * 1000;

// helper function to get the process cpu usage through IProcessDiagnosticInfo
static HRESULT _getProcessCpuUsage(time_value_t& userTime, time_value_t& systemTime) {
    ComPtr<IProcessDiagnosticInfo> processDiagnosticInfo;
    RETURN_IF_FAILED(_getProcessDiagnosticInfo(&processDiagnosticInfo));

    ComPtr<IProcessCpuUsage> processCpuUsage;
    RETURN_IF_FAILED(processDiagnosticInfo->get_CpuUsage(&processCpuUsage));

    ComPtr<IProcessCpuUsageReport> processCpuUsageReport;
    RETURN_IF_FAILED(processCpuUsage->GetReport(&processCpuUsageReport));

    ABI::Windows::Foundation::TimeSpan userTimeSpan;
    ABI::Windows::Foundation::TimeSpan kernelTimeSpan;

    RETURN_IF_FAILED(processCpuUsageReport->get_UserTime(&userTimeSpan));
    RETURN_IF_FAILED(processCpuUsageReport->get_KernelTime(&kernelTimeSpan));

    __int64 microSeconds = userTimeSpan.Duration / 10; // duration is in 100 ns
    // microseconds is the fraction of duration that cannot be added to the second
    userTime.seconds = microSeconds / MICROSEC_TO_SEC;
    userTime.microseconds = microSeconds % MICROSEC_TO_SEC;

    microSeconds = kernelTimeSpan.Duration / 10;
    systemTime.seconds = microSeconds / MICROSEC_TO_SEC;
    systemTime.microseconds = microSeconds % MICROSEC_TO_SEC;

    return S_OK;
}

// Helper function to get basic info
static kern_return_t _getTaskBasicInfo(task_basic_info_t basic_info, mach_msg_type_number_t* count) {
    // reference platform allows count to specify number of integers instead of bytes.
    if (*count < sizeof(task_basic_info) / sizeof(integer_t)) {
        return KERN_INVALID_ARGUMENT;
    }

    if (FAILED(_getProcessMemoryUsage(basic_info->virtual_size, basic_info->resident_size))) {
        return KERN_FAILURE;
    }

    basic_info->suspend_count = 0; // we dont have this value on windows.
    basic_info->base_priority = 1; // arbitrary

    // user_time contains the total user time for all terminated threads.  We dont have that for UWP apps
    basic_info->user_time.seconds = 0;
    basic_info->user_time.microseconds = 0;
    basic_info->system_time.seconds = 0;
    basic_info->system_time.microseconds = 0;

    // default scheduling policy is not exposed.
    basic_info->policy = 0;

    // on exit, count should have number of integers returned.
    *count = sizeof(task_basic_info) / sizeof(integer_t);

    return KERN_SUCCESS;
}

// Helper function to get thread times info
static kern_return_t _getTaskThreadTimesInfo(task_thread_times_info_t info, mach_msg_type_number_t* count) {
    // reference platform allows count to specify number of integers instead of bytes.
    if (*count < sizeof(task_thread_times_info) / sizeof(integer_t)) {
        return KERN_INVALID_ARGUMENT;
    }

    if (FAILED(_getProcessCpuUsage(info->user_time, info->system_time))) {
        return KERN_FAILURE;
    }

    // on exit, count should have number of integers returned.
    *count = sizeof(task_thread_times_info) / sizeof(integer_t);

    return KERN_SUCCESS;
}

/*
@Status interoperable
*/
extern "C" mach_port_t mach_task_self() {
    return UINT_MAX; // arbitrary
}

/**
@Status Caveat
@Notes only supports TASK_BASIC_INFO and TASK_THREAD_TIMES_INFO and only for mach_task_self().
@Notes task_basic_info only supports virtual size and resident size
*/
extern "C" kern_return_t task_info(task_t target_task, int flavor, task_info_t task_info, mach_msg_type_number_t* task_info_count) {
    if (target_task != mach_task_self() || !task_info_count) {
        return KERN_INVALID_ARGUMENT;
    }

    switch (flavor) {
        case TASK_BASIC_INFO:
            return _getTaskBasicInfo(reinterpret_cast<task_basic_info_t>(task_info), task_info_count);
        case TASK_THREAD_TIMES_INFO:
            return _getTaskThreadTimesInfo(reinterpret_cast<task_thread_times_info_t>(task_info), task_info_count);
        default:
            UNIMPLEMENTED_WITH_MSG("Warning: task_info received unsupported flavor %d\n", flavor);
            break;
    }

    return KERN_INVALID_ARGUMENT;
}
