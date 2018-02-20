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

// WindowsSystemDiagnostics.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSDProcessDiagnosticInfo, WSDProcessDiskUsage, WSDProcessMemoryUsage, WSDProcessCpuUsage, WSDProcessMemoryUsageReport, WSDProcessDiskUsageReport, WSDProcessCpuUsageReport, WSDSystemMemoryUsage, WSDSystemCpuUsage, WSDSystemDiagnosticInfo, WSDSystemMemoryUsageReport, WSDSystemCpuUsageReport, WSDDiagnosticInvoker, WSDDiagnosticActionResult;
@protocol WSDIProcessDiagnosticInfo, WSDIProcessDiagnosticInfo2, WSDIProcessDiagnosticInfoStatics, WSDIProcessDiagnosticInfoStatics2, WSDIProcessMemoryUsage, WSDIProcessMemoryUsageReport, WSDIProcessDiskUsage, WSDIProcessDiskUsageReport, WSDIProcessCpuUsage, WSDIProcessCpuUsageReport, WSDISystemDiagnosticInfo, WSDISystemDiagnosticInfoStatics, WSDISystemMemoryUsage, WSDISystemMemoryUsageReport, WSDISystemCpuUsage, WSDISystemCpuUsageReport, WSDIDiagnosticActionResult, WSDIDiagnosticInvokerStatics, WSDIDiagnosticInvoker;

// Windows.System.Diagnostics.DiagnosticActionState
enum _WSDDiagnosticActionState {
    WSDDiagnosticActionStateInitializing = 0,
    WSDDiagnosticActionStateDownloading = 1,
    WSDDiagnosticActionStateVerifyingTrust = 2,
    WSDDiagnosticActionStateDetecting = 3,
    WSDDiagnosticActionStateResolving = 4,
    WSDDiagnosticActionStateVerifyingResolution = 5,
};
typedef unsigned WSDDiagnosticActionState;

#include "WindowsFoundation.h"
#include "WindowsSystem.h"
#include "WindowsFoundationCollections.h"
#include "WindowsDataJson.h"

#import <Foundation/Foundation.h>

// Windows.System.Diagnostics.ProcessDiagnosticInfo
#ifndef __WSDProcessDiagnosticInfo_DEFINED__
#define __WSDProcessDiagnosticInfo_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDProcessDiagnosticInfo : RTObject
+ (NSArray* /* WSDProcessDiagnosticInfo* */)getForProcesses;
+ (WSDProcessDiagnosticInfo*)getForCurrentProcess;
+ (WSDProcessDiagnosticInfo*)tryGetForProcessId:(unsigned int)processId;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSDProcessCpuUsage* cpuUsage;
@property (readonly) WSDProcessDiskUsage* diskUsage;
@property (readonly) NSString * executableFileName;
@property (readonly) WSDProcessMemoryUsage* memoryUsage;
@property (readonly) WSDProcessDiagnosticInfo* parent;
@property (readonly) unsigned int processId;
@property (readonly) WFDateTime* processStartTime;
@property (readonly) BOOL isPackaged;
- (NSMutableArray* /* WSAppDiagnosticInfo* */)getAppDiagnosticInfos;
@end

#endif // __WSDProcessDiagnosticInfo_DEFINED__

// Windows.System.Diagnostics.ProcessDiskUsage
#ifndef __WSDProcessDiskUsage_DEFINED__
#define __WSDProcessDiskUsage_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDProcessDiskUsage : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WSDProcessDiskUsageReport*)getReport;
@end

#endif // __WSDProcessDiskUsage_DEFINED__

// Windows.System.Diagnostics.ProcessMemoryUsage
#ifndef __WSDProcessMemoryUsage_DEFINED__
#define __WSDProcessMemoryUsage_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDProcessMemoryUsage : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WSDProcessMemoryUsageReport*)getReport;
@end

#endif // __WSDProcessMemoryUsage_DEFINED__

// Windows.System.Diagnostics.ProcessCpuUsage
#ifndef __WSDProcessCpuUsage_DEFINED__
#define __WSDProcessCpuUsage_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDProcessCpuUsage : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WSDProcessCpuUsageReport*)getReport;
@end

#endif // __WSDProcessCpuUsage_DEFINED__

// Windows.System.Diagnostics.ProcessMemoryUsageReport
#ifndef __WSDProcessMemoryUsageReport_DEFINED__
#define __WSDProcessMemoryUsageReport_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDProcessMemoryUsageReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
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

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDProcessDiskUsageReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
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

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDProcessCpuUsageReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFTimeSpan* kernelTime;
@property (readonly) WFTimeSpan* userTime;
@end

#endif // __WSDProcessCpuUsageReport_DEFINED__

// Windows.System.Diagnostics.SystemMemoryUsage
#ifndef __WSDSystemMemoryUsage_DEFINED__
#define __WSDSystemMemoryUsage_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDSystemMemoryUsage : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WSDSystemMemoryUsageReport*)getReport;
@end

#endif // __WSDSystemMemoryUsage_DEFINED__

// Windows.System.Diagnostics.SystemCpuUsage
#ifndef __WSDSystemCpuUsage_DEFINED__
#define __WSDSystemCpuUsage_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDSystemCpuUsage : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WSDSystemCpuUsageReport*)getReport;
@end

#endif // __WSDSystemCpuUsage_DEFINED__

// Windows.System.Diagnostics.SystemDiagnosticInfo
#ifndef __WSDSystemDiagnosticInfo_DEFINED__
#define __WSDSystemDiagnosticInfo_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDSystemDiagnosticInfo : RTObject
+ (WSDSystemDiagnosticInfo*)getForCurrentSystem;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSDSystemCpuUsage* cpuUsage;
@property (readonly) WSDSystemMemoryUsage* memoryUsage;
@end

#endif // __WSDSystemDiagnosticInfo_DEFINED__

// Windows.System.Diagnostics.SystemMemoryUsageReport
#ifndef __WSDSystemMemoryUsageReport_DEFINED__
#define __WSDSystemMemoryUsageReport_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDSystemMemoryUsageReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) uint64_t availableSizeInBytes;
@property (readonly) uint64_t committedSizeInBytes;
@property (readonly) uint64_t totalPhysicalSizeInBytes;
@end

#endif // __WSDSystemMemoryUsageReport_DEFINED__

// Windows.System.Diagnostics.SystemCpuUsageReport
#ifndef __WSDSystemCpuUsageReport_DEFINED__
#define __WSDSystemCpuUsageReport_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDSystemCpuUsageReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFTimeSpan* idleTime;
@property (readonly) WFTimeSpan* kernelTime;
@property (readonly) WFTimeSpan* userTime;
@end

#endif // __WSDSystemCpuUsageReport_DEFINED__

// Windows.System.Diagnostics.DiagnosticInvoker
#ifndef __WSDDiagnosticInvoker_DEFINED__
#define __WSDDiagnosticInvoker_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDDiagnosticInvoker : RTObject
+ (WSDDiagnosticInvoker*)getDefault;
+ (WSDDiagnosticInvoker*)getForUser:(WSUser*)user;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
+ (BOOL)isSupported;
- (void)runDiagnosticActionAsync:(WDJJsonObject*)context success:(void (^)(WSDDiagnosticActionResult*))success progress:(void (^)(WSDDiagnosticActionState))progress failure:(void (^)(NSError*))failure;
@end

#endif // __WSDDiagnosticInvoker_DEFINED__

// Windows.System.Diagnostics.DiagnosticActionResult
#ifndef __WSDDiagnosticActionResult_DEFINED__
#define __WSDDiagnosticActionResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSDDiagnosticActionResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@property (readonly) WFCValueSet* results;
@end

#endif // __WSDDiagnosticActionResult_DEFINED__

