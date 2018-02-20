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

// WindowsSystemDiagnosticsTelemetry.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSYSTEMDIAGNOSTICSTELEMETRYEXPORT
#define OBJCUWPWINDOWSSYSTEMDIAGNOSTICSTELEMETRYEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsSystemDiagnosticsTelemetry.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSDTPlatformTelemetryRegistrationResult, WSDTPlatformTelemetryRegistrationSettings, WSDTPlatformTelemetryClient;
@protocol WSDTIPlatformTelemetryRegistrationSettings, WSDTIPlatformTelemetryRegistrationResult, WSDTIPlatformTelemetryClientStatics;

// Windows.System.Diagnostics.Telemetry.PlatformTelemetryRegistrationStatus
enum _WSDTPlatformTelemetryRegistrationStatus {
    WSDTPlatformTelemetryRegistrationStatusSuccess = 0,
    WSDTPlatformTelemetryRegistrationStatusSettingsOutOfRange = 1,
    WSDTPlatformTelemetryRegistrationStatusUnknownFailure = 2,
};
typedef unsigned WSDTPlatformTelemetryRegistrationStatus;

#import <Foundation/Foundation.h>

// Windows.System.Diagnostics.Telemetry.PlatformTelemetryRegistrationResult
#ifndef __WSDTPlatformTelemetryRegistrationResult_DEFINED__
#define __WSDTPlatformTelemetryRegistrationResult_DEFINED__

OBJCUWPWINDOWSSYSTEMDIAGNOSTICSTELEMETRYEXPORT
@interface WSDTPlatformTelemetryRegistrationResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSDTPlatformTelemetryRegistrationStatus status;
@end

#endif // __WSDTPlatformTelemetryRegistrationResult_DEFINED__

// Windows.System.Diagnostics.Telemetry.PlatformTelemetryRegistrationSettings
#ifndef __WSDTPlatformTelemetryRegistrationSettings_DEFINED__
#define __WSDTPlatformTelemetryRegistrationSettings_DEFINED__

OBJCUWPWINDOWSSYSTEMDIAGNOSTICSTELEMETRYEXPORT
@interface WSDTPlatformTelemetryRegistrationSettings : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int uploadQuotaSize;
@property unsigned int storageSize;
@end

#endif // __WSDTPlatformTelemetryRegistrationSettings_DEFINED__

// Windows.System.Diagnostics.Telemetry.PlatformTelemetryClient
#ifndef __WSDTPlatformTelemetryClient_DEFINED__
#define __WSDTPlatformTelemetryClient_DEFINED__

OBJCUWPWINDOWSSYSTEMDIAGNOSTICSTELEMETRYEXPORT
@interface WSDTPlatformTelemetryClient : RTObject
+ (WSDTPlatformTelemetryRegistrationResult*)Register:(NSString *)id;
+ (WSDTPlatformTelemetryRegistrationResult*)registerWithSettings:(NSString *)id settings:(WSDTPlatformTelemetryRegistrationSettings*)settings;
@end

#endif // __WSDTPlatformTelemetryClient_DEFINED__

