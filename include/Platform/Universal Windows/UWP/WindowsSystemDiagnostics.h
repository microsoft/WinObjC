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

// WindowsSystemDiagnostics.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSDProcessDiagnosticInfo, WSDProcessDiskUsage, WSDProcessMemoryUsage, WSDProcessCpuUsage, WSDProcessMemoryUsageReport,
    WSDProcessDiskUsageReport, WSDProcessCpuUsageReport;
@protocol WSDIProcessDiagnosticInfo
, WSDIProcessDiagnosticInfoStatics, WSDIProcessMemoryUsage, WSDIProcessMemoryUsageReport, WSDIProcessDiskUsage, WSDIProcessDiskUsageReport,
    WSDIProcessCpuUsage, WSDIProcessCpuUsageReport;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// Windows.System.Diagnostics.ProcessDiagnosticInfo
#ifndef __WSDProcessDiagnosticInfo_DEFINED__
#define __WSDProcessDiagnosticInfo_DEFINED__

WINRT_EXPORT
@interface WSDProcessDiagnosticInfo : RTObject
+ (NSArray*)getForProcesses;
+ (WSDProcessDiagnosticInfo*)getForCurrentProcess;
@property (readonly) WSDProcessCpuUsage* cpuUsage;
@property (readonly) WSDProcessDiskUsage* diskUsage;
@property (readonly) NSString* executableFileName;
@property (readonly) WSDProcessMemoryUsage* memoryUsage;
@property (readonly) WSDProcessDiagnosticInfo* parent;
@property (readonly) unsigned int processId;
@property (readonly) WFDateTime* processStartTime;
@end

#endif // __WSDProcessDiagnosticInfo_DEFINED__

// Windows.System.Diagnostics.ProcessDiskUsage
#ifndef __WSDProcessDiskUsage_DEFINED__
#define __WSDProcessDiskUsage_DEFINED__

WINRT_EXPORT
@interface WSDProcessDiskUsage : RTObject
- (WSDProcessDiskUsageReport*)getReport;
@end

#endif // __WSDProcessDiskUsage_DEFINED__

// Windows.System.Diagnostics.ProcessMemoryUsage
#ifndef __WSDProcessMemoryUsage_DEFINED__
#define __WSDProcessMemoryUsage_DEFINED__

WINRT_EXPORT
@interface WSDProcessMemoryUsage : RTObject
- (WSDProcessMemoryUsageReport*)getReport;
@end

#endif // __WSDProcessMemoryUsage_DEFINED__

// Windows.System.Diagnostics.ProcessCpuUsage
#ifndef __WSDProcessCpuUsage_DEFINED__
#define __WSDProcessCpuUsage_DEFINED__

WINRT_EXPORT
@interface WSDProcessCpuUsage : RTObject
- (WSDProcessCpuUsageReport*)getReport;
@end

#endif // __WSDProcessCpuUsage_DEFINED__

// Windows.System.Diagnostics.ProcessMemoryUsageReport
#ifndef __WSDProcessMemoryUsageReport_DEFINED__
#define __WSDProcessMemoryUsageReport_DEFINED__

WINRT_EXPORT
@interface WSDProcessMemoryUsageReport : RTObject
@property (readonly) uint64_t nonPagedPoolSizeInBytes;
@property (readonly) unsigned int pageFaultCount;
@property (readonly) uint64_t pageFileSizeInBytes;
@property (readonly) uint64_t pagedPoolSizeInBytes;
@property (readonly) uint64_t peakNonPagedPoolSizeInBytes;
@property (readonly) uint64_t peakPageFileSizeInBytes;
@property (readonly) uint64_t peakPagedPoolSizeInBytes;
@property (readonly) uint64_t peakVirtualMemorySizeInBytes;
@property (readonly) uint64_t peakWorkingSetSizeInBytes;
@property (readonly) uint64_t privatePageCount;
@property (readonly) uint64_t virtualMemorySizeInBytes;
@property (readonly) uint64_t workingSetSizeInBytes;
@end

#endif // __WSDProcessMemoryUsageReport_DEFINED__

// Windows.System.Diagnostics.ProcessDiskUsageReport
#ifndef __WSDProcessDiskUsageReport_DEFINED__
#define __WSDProcessDiskUsageReport_DEFINED__

WINRT_EXPORT
@interface WSDProcessDiskUsageReport : RTObject
@property (readonly) int64_t bytesReadCount;
@property (readonly) int64_t bytesWrittenCount;
@property (readonly) int64_t otherBytesCount;
@property (readonly) int64_t otherOperationCount;
@property (readonly) int64_t readOperationCount;
@property (readonly) int64_t writeOperationCount;
@end

#endif // __WSDProcessDiskUsageReport_DEFINED__

// Windows.System.Diagnostics.ProcessCpuUsageReport
#ifndef __WSDProcessCpuUsageReport_DEFINED__
#define __WSDProcessCpuUsageReport_DEFINED__

WINRT_EXPORT
@interface WSDProcessCpuUsageReport : RTObject
@property (readonly) WFTimeSpan* kernelTime;
@property (readonly) WFTimeSpan* userTime;
@end

#endif // __WSDProcessCpuUsageReport_DEFINED__
