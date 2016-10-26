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

#ifndef OBJCUWP_WINDOWS_SYSTEM_DIAGNOSTICS_EXPORT
#define OBJCUWP_WINDOWS_SYSTEM_DIAGNOSTICS_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_System_Diagnostics.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSDProcessDiagnosticInfo, WSDProcessDiskUsage, WSDProcessMemoryUsage, WSDProcessCpuUsage, WSDProcessMemoryUsageReport,
    WSDProcessDiskUsageReport, WSDProcessCpuUsageReport;
@protocol WSDIProcessDiagnosticInfo
, WSDIProcessDiagnosticInfoStatics, WSDIProcessMemoryUsage, WSDIProcessMemoryUsageReport, WSDIProcessDiskUsage, WSDIProcessDiskUsageReport,
    WSDIProcessCpuUsage, WSDIProcessCpuUsageReport;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.System.Diagnostics.ProcessDiagnosticInfo
#ifndef __WSDProcessDiagnosticInfo_DEFINED__
#define __WSDProcessDiagnosticInfo_DEFINED__

OBJCUWP_WINDOWS_SYSTEM_DIAGNOSTICS_EXPORT
@interface WSDProcessDiagnosticInfo : RTObject
+ (NSArray* /* WSDProcessDiagnosticInfo* */)getForProcesses;
+ (WSDProcessDiagnosticInfo*)getForCurrentProcess;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
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

OBJCUWP_WINDOWS_SYSTEM_DIAGNOSTICS_EXPORT
@interface WSDProcessDiskUsage : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (WSDProcessDiskUsageReport*)getReport;
@end

#endif // __WSDProcessDiskUsage_DEFINED__

// Windows.System.Diagnostics.ProcessMemoryUsage
#ifndef __WSDProcessMemoryUsage_DEFINED__
#define __WSDProcessMemoryUsage_DEFINED__

OBJCUWP_WINDOWS_SYSTEM_DIAGNOSTICS_EXPORT
@interface WSDProcessMemoryUsage : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (WSDProcessMemoryUsageReport*)getReport;
@end

#endif // __WSDProcessMemoryUsage_DEFINED__

// Windows.System.Diagnostics.ProcessCpuUsage
#ifndef __WSDProcessCpuUsage_DEFINED__
#define __WSDProcessCpuUsage_DEFINED__

OBJCUWP_WINDOWS_SYSTEM_DIAGNOSTICS_EXPORT
@interface WSDProcessCpuUsage : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (WSDProcessCpuUsageReport*)getReport;
@end

#endif // __WSDProcessCpuUsage_DEFINED__

// Windows.System.Diagnostics.ProcessMemoryUsageReport
#ifndef __WSDProcessMemoryUsageReport_DEFINED__
#define __WSDProcessMemoryUsageReport_DEFINED__

OBJCUWP_WINDOWS_SYSTEM_DIAGNOSTICS_EXPORT
@interface WSDProcessMemoryUsageReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
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

OBJCUWP_WINDOWS_SYSTEM_DIAGNOSTICS_EXPORT
@interface WSDProcessDiskUsageReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
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

OBJCUWP_WINDOWS_SYSTEM_DIAGNOSTICS_EXPORT
@interface WSDProcessCpuUsageReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WFTimeSpan* kernelTime;
@property (readonly) WFTimeSpan* userTime;
@end

#endif // __WSDProcessCpuUsageReport_DEFINED__
