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

// WindowsSystemDiagnosticsTraceReporting.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSYSTEMDIAGNOSTICSTRACEREPORTINGEXPORT
#define OBJCUWPWINDOWSSYSTEMDIAGNOSTICSTRACEREPORTINGEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsSystemDiagnosticsTraceReporting.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSDTPlatformDiagnosticTraceInfo, WSDTPlatformDiagnosticTraceRuntimeInfo, WSDTPlatformDiagnosticActions;
@protocol WSDTIPlatformDiagnosticTraceInfo, WSDTIPlatformDiagnosticTraceRuntimeInfo, WSDTIPlatformDiagnosticActionsStatics;

// Windows.System.Diagnostics.TraceReporting.PlatformDiagnosticEscalationType
enum _WSDTPlatformDiagnosticEscalationType {
    WSDTPlatformDiagnosticEscalationTypeOnCompletion = 0,
    WSDTPlatformDiagnosticEscalationTypeOnFailure = 1,
};
typedef unsigned WSDTPlatformDiagnosticEscalationType;

// Windows.System.Diagnostics.TraceReporting.PlatformDiagnosticTraceSlotType
enum _WSDTPlatformDiagnosticTraceSlotType {
    WSDTPlatformDiagnosticTraceSlotTypeAlternative = 0,
    WSDTPlatformDiagnosticTraceSlotTypeAlwaysOn = 1,
    WSDTPlatformDiagnosticTraceSlotTypeMini = 2,
};
typedef unsigned WSDTPlatformDiagnosticTraceSlotType;

// Windows.System.Diagnostics.TraceReporting.PlatformDiagnosticTracePriority
enum _WSDTPlatformDiagnosticTracePriority {
    WSDTPlatformDiagnosticTracePriorityNormal = 0,
    WSDTPlatformDiagnosticTracePriorityUserElevated = 1,
};
typedef unsigned WSDTPlatformDiagnosticTracePriority;

// Windows.System.Diagnostics.TraceReporting.PlatformDiagnosticTraceSlotState
enum _WSDTPlatformDiagnosticTraceSlotState {
    WSDTPlatformDiagnosticTraceSlotStateNotRunning = 0,
    WSDTPlatformDiagnosticTraceSlotStateRunning = 1,
    WSDTPlatformDiagnosticTraceSlotStateThrottled = 2,
};
typedef unsigned WSDTPlatformDiagnosticTraceSlotState;

// Windows.System.Diagnostics.TraceReporting.PlatformDiagnosticActionState
enum _WSDTPlatformDiagnosticActionState {
    WSDTPlatformDiagnosticActionStateSuccess = 0,
    WSDTPlatformDiagnosticActionStateFreeNetworkNotAvailable = 1,
    WSDTPlatformDiagnosticActionStateACPowerNotAvailable = 2,
};
typedef unsigned WSDTPlatformDiagnosticActionState;

// Windows.System.Diagnostics.TraceReporting.PlatformDiagnosticEventBufferLatencies
enum _WSDTPlatformDiagnosticEventBufferLatencies {
    WSDTPlatformDiagnosticEventBufferLatenciesNormal = 1,
    WSDTPlatformDiagnosticEventBufferLatenciesCostDeferred = 2,
    WSDTPlatformDiagnosticEventBufferLatenciesRealtime = 4,
};
typedef unsigned WSDTPlatformDiagnosticEventBufferLatencies;

#import <Foundation/Foundation.h>

// Windows.System.Diagnostics.TraceReporting.PlatformDiagnosticTraceInfo
#ifndef __WSDTPlatformDiagnosticTraceInfo_DEFINED__
#define __WSDTPlatformDiagnosticTraceInfo_DEFINED__

OBJCUWPWINDOWSSYSTEMDIAGNOSTICSTRACEREPORTINGEXPORT
@interface WSDTPlatformDiagnosticTraceInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isAutoLogger;
@property (readonly) BOOL isExclusive;
@property (readonly) int64_t maxTraceDurationFileTime;
@property (readonly) WSDTPlatformDiagnosticTracePriority priority;
@property (readonly) uint64_t profileHash;
@property (readonly) WFGUID* scenarioId;
@end

#endif // __WSDTPlatformDiagnosticTraceInfo_DEFINED__

// Windows.System.Diagnostics.TraceReporting.PlatformDiagnosticTraceRuntimeInfo
#ifndef __WSDTPlatformDiagnosticTraceRuntimeInfo_DEFINED__
#define __WSDTPlatformDiagnosticTraceRuntimeInfo_DEFINED__

OBJCUWPWINDOWSSYSTEMDIAGNOSTICSTRACEREPORTINGEXPORT
@interface WSDTPlatformDiagnosticTraceRuntimeInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int64_t etwRuntimeFileTime;
@property (readonly) int64_t runtimeFileTime;
@end

#endif // __WSDTPlatformDiagnosticTraceRuntimeInfo_DEFINED__

// Windows.System.Diagnostics.TraceReporting.PlatformDiagnosticActions
#ifndef __WSDTPlatformDiagnosticActions_DEFINED__
#define __WSDTPlatformDiagnosticActions_DEFINED__

OBJCUWPWINDOWSSYSTEMDIAGNOSTICSTRACEREPORTINGEXPORT
@interface WSDTPlatformDiagnosticActions : RTObject
+ (BOOL)isScenarioEnabled:(WFGUID*)scenarioId;
+ (BOOL)tryEscalateScenario:(WFGUID*)scenarioId escalationType:(WSDTPlatformDiagnosticEscalationType)escalationType outputDirectory:(NSString *)outputDirectory timestampOutputDirectory:(BOOL)timestampOutputDirectory forceEscalationUpload:(BOOL)forceEscalationUpload triggers:(NSDictionary* /* NSString *, NSString * */)triggers;
+ (WSDTPlatformDiagnosticActionState)downloadLatestSettingsForNamespace:(NSString *)partner feature:(NSString *)feature isScenarioNamespace:(BOOL)isScenarioNamespace downloadOverCostedNetwork:(BOOL)downloadOverCostedNetwork downloadOverBattery:(BOOL)downloadOverBattery;
+ (NSArray* /* WFGUID* */)getActiveScenarioList;
+ (WSDTPlatformDiagnosticActionState)forceUpload:(WSDTPlatformDiagnosticEventBufferLatencies)latency uploadOverCostedNetwork:(BOOL)uploadOverCostedNetwork uploadOverBattery:(BOOL)uploadOverBattery;
+ (WSDTPlatformDiagnosticTraceSlotState)isTraceRunning:(WSDTPlatformDiagnosticTraceSlotType)slotType scenarioId:(WFGUID*)scenarioId traceProfileHash:(uint64_t)traceProfileHash;
+ (WSDTPlatformDiagnosticTraceRuntimeInfo*)getActiveTraceRuntime:(WSDTPlatformDiagnosticTraceSlotType)slotType;
+ (NSArray* /* WSDTPlatformDiagnosticTraceInfo* */)getKnownTraceList:(WSDTPlatformDiagnosticTraceSlotType)slotType;
@end

#endif // __WSDTPlatformDiagnosticActions_DEFINED__

