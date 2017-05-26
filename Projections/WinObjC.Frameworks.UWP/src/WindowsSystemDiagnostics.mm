//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// WindowsSystemDiagnostics.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.System.Diagnostics.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSystemDiagnostics.h"
#include "WindowsSystemDiagnostics_priv.h"

@implementation WSDProcessDiagnosticInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::Diagnostics::IProcessDiagnosticInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::System::Diagnostics::IProcessDiagnosticInfoStatics> WSDIProcessDiagnosticInfoStatics_inst() {
    ComPtr<ABI::Windows::System::Diagnostics::IProcessDiagnosticInfoStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Diagnostics.ProcessDiagnosticInfo").Get(),
                                                       &inst));
    return inst;
}

+ (NSArray* /* WSDProcessDiagnosticInfo* */)getForProcesses {
    ComPtr<IVectorView<ABI::Windows::System::Diagnostics::ProcessDiagnosticInfo*>> unmarshalledReturn;
    auto _comInst = WSDIProcessDiagnosticInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForProcesses(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSDProcessDiagnosticInfo_create(unmarshalledReturn.Get());
}

+ (WSDProcessDiagnosticInfo*)getForCurrentProcess {
    ComPtr<ABI::Windows::System::Diagnostics::IProcessDiagnosticInfo> unmarshalledReturn;
    auto _comInst = WSDIProcessDiagnosticInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentProcess(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSDProcessDiagnosticInfo>(unmarshalledReturn.Get());
}

- (unsigned int)processId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessDiagnosticInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProcessId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)executableFileName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessDiagnosticInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExecutableFileName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSDProcessDiagnosticInfo*)parent {
    ComPtr<ABI::Windows::System::Diagnostics::IProcessDiagnosticInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessDiagnosticInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Parent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSDProcessDiagnosticInfo>(unmarshalledReturn.Get());
}

- (WFDateTime*)processStartTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessDiagnosticInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProcessStartTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WSDProcessDiskUsage*)diskUsage {
    ComPtr<ABI::Windows::System::Diagnostics::IProcessDiskUsage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessDiagnosticInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DiskUsage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSDProcessDiskUsage>(unmarshalledReturn.Get());
}

- (WSDProcessMemoryUsage*)memoryUsage {
    ComPtr<ABI::Windows::System::Diagnostics::IProcessMemoryUsage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessDiagnosticInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_MemoryUsage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSDProcessMemoryUsage>(unmarshalledReturn.Get());
}

- (WSDProcessCpuUsage*)cpuUsage {
    ComPtr<ABI::Windows::System::Diagnostics::IProcessCpuUsage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessDiagnosticInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CpuUsage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSDProcessCpuUsage>(unmarshalledReturn.Get());
}

@end

@implementation WSDProcessDiskUsage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::Diagnostics::IProcessDiskUsage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSDProcessDiskUsageReport*)getReport {
    ComPtr<ABI::Windows::System::Diagnostics::IProcessDiskUsageReport> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessDiskUsage>(self);
    THROW_NS_IF_FAILED(_comInst->GetReport(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSDProcessDiskUsageReport>(unmarshalledReturn.Get());
}

@end

@implementation WSDProcessMemoryUsage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::Diagnostics::IProcessMemoryUsage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSDProcessMemoryUsageReport*)getReport {
    ComPtr<ABI::Windows::System::Diagnostics::IProcessMemoryUsageReport> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessMemoryUsage>(self);
    THROW_NS_IF_FAILED(_comInst->GetReport(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSDProcessMemoryUsageReport>(unmarshalledReturn.Get());
}

@end

@implementation WSDProcessCpuUsage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::Diagnostics::IProcessCpuUsage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSDProcessCpuUsageReport*)getReport {
    ComPtr<ABI::Windows::System::Diagnostics::IProcessCpuUsageReport> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessCpuUsage>(self);
    THROW_NS_IF_FAILED(_comInst->GetReport(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSDProcessCpuUsageReport>(unmarshalledReturn.Get());
}

@end

@implementation WSDProcessMemoryUsageReport

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::Diagnostics::IProcessMemoryUsageReport> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (uint64_t)nonPagedPoolSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessMemoryUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_NonPagedPoolSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)pageFaultCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessMemoryUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_PageFaultCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)pageFileSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessMemoryUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_PageFileSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)pagedPoolSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessMemoryUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_PagedPoolSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)peakNonPagedPoolSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessMemoryUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_PeakNonPagedPoolSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)peakPageFileSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessMemoryUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_PeakPageFileSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)peakPagedPoolSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessMemoryUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_PeakPagedPoolSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)peakVirtualMemorySizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessMemoryUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_PeakVirtualMemorySizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)peakWorkingSetSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessMemoryUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_PeakWorkingSetSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)privatePageCount {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessMemoryUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrivatePageCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)virtualMemorySizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessMemoryUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_VirtualMemorySizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)workingSetSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessMemoryUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_WorkingSetSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WSDProcessDiskUsageReport

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::Diagnostics::IProcessDiskUsageReport> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int64_t)readOperationCount {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessDiskUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadOperationCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)writeOperationCount {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessDiskUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_WriteOperationCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)otherOperationCount {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessDiskUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_OtherOperationCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)bytesReadCount {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessDiskUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_BytesReadCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)bytesWrittenCount {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessDiskUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_BytesWrittenCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)otherBytesCount {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessDiskUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_OtherBytesCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WSDProcessCpuUsageReport

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::Diagnostics::IProcessCpuUsageReport> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFTimeSpan*)kernelTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessCpuUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_KernelTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)userTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Diagnostics::IProcessCpuUsageReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

@end

id RTProxiedNSArray_WSDProcessDiagnosticInfo_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::System::Diagnostics::ProcessDiagnosticInfo*>,
                                         RTArrayObj<ABI::Windows::System::Diagnostics::IProcessDiagnosticInfo*,
                                                    IVectorView<ABI::Windows::System::Diagnostics::ProcessDiagnosticInfo*>,
                                                    WSDProcessDiagnosticInfo,
                                                    ABI::Windows::System::Diagnostics::ProcessDiagnosticInfo*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
