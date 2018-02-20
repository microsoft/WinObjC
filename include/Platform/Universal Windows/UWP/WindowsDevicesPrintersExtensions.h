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

// WindowsDevicesPrintersExtensions.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDEVICESPRINTERSEXTENSIONSEXPORT
#define OBJCUWPWINDOWSDEVICESPRINTERSEXTENSIONSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDevicesPrintersExtensions.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDPEPrintTaskConfigurationSaveRequestedDeferral, WDPEPrintTaskConfigurationSaveRequest, WDPEPrintTaskConfigurationSaveRequestedEventArgs, WDPEPrintTaskConfiguration, WDPEPrintNotificationEventDetails, WDPEPrintExtensionContext, WDPEPrint3DWorkflowPrintRequestedEventArgs, WDPEPrint3DWorkflowPrinterChangedEventArgs, WDPEPrint3DWorkflow;
@protocol WDPEIPrintTaskConfigurationSaveRequestedDeferral, WDPEIPrintTaskConfigurationSaveRequest, WDPEIPrintTaskConfigurationSaveRequestedEventArgs, WDPEIPrintTaskConfiguration, WDPEIPrintNotificationEventDetails, WDPEIPrintExtensionContextStatic, WDPEIPrint3DWorkflowPrintRequestedEventArgs, WDPEIPrint3DWorkflowPrinterChangedEventArgs, WDPEIPrint3DWorkflow, WDPEIPrint3DWorkflow2;

// Windows.Devices.Printers.Extensions.Print3DWorkflowStatus
enum _WDPEPrint3DWorkflowStatus {
    WDPEPrint3DWorkflowStatusAbandoned = 0,
    WDPEPrint3DWorkflowStatusCanceled = 1,
    WDPEPrint3DWorkflowStatusFailed = 2,
    WDPEPrint3DWorkflowStatusSlicing = 3,
    WDPEPrint3DWorkflowStatusSubmitted = 4,
};
typedef unsigned WDPEPrint3DWorkflowStatus;

// Windows.Devices.Printers.Extensions.Print3DWorkflowDetail
enum _WDPEPrint3DWorkflowDetail {
    WDPEPrint3DWorkflowDetailUnknown = 0,
    WDPEPrint3DWorkflowDetailModelExceedsPrintBed = 1,
    WDPEPrint3DWorkflowDetailUploadFailed = 2,
    WDPEPrint3DWorkflowDetailInvalidMaterialSelection = 3,
    WDPEPrint3DWorkflowDetailInvalidModel = 4,
    WDPEPrint3DWorkflowDetailModelNotManifold = 5,
    WDPEPrint3DWorkflowDetailInvalidPrintTicket = 6,
};
typedef unsigned WDPEPrint3DWorkflowDetail;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Printers.Extensions.PrintTaskConfigurationSaveRequestedDeferral
#ifndef __WDPEPrintTaskConfigurationSaveRequestedDeferral_DEFINED__
#define __WDPEPrintTaskConfigurationSaveRequestedDeferral_DEFINED__

OBJCUWPWINDOWSDEVICESPRINTERSEXTENSIONSEXPORT
@interface WDPEPrintTaskConfigurationSaveRequestedDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WDPEPrintTaskConfigurationSaveRequestedDeferral_DEFINED__

// Windows.Devices.Printers.Extensions.PrintTaskConfigurationSaveRequest
#ifndef __WDPEPrintTaskConfigurationSaveRequest_DEFINED__
#define __WDPEPrintTaskConfigurationSaveRequest_DEFINED__

OBJCUWPWINDOWSDEVICESPRINTERSEXTENSIONSEXPORT
@interface WDPEPrintTaskConfigurationSaveRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFDateTime* deadline;
- (void)cancel;
- (void)save:(RTObject*)printerExtensionContext;
- (WDPEPrintTaskConfigurationSaveRequestedDeferral*)getDeferral;
@end

#endif // __WDPEPrintTaskConfigurationSaveRequest_DEFINED__

// Windows.Devices.Printers.Extensions.PrintTaskConfigurationSaveRequestedEventArgs
#ifndef __WDPEPrintTaskConfigurationSaveRequestedEventArgs_DEFINED__
#define __WDPEPrintTaskConfigurationSaveRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESPRINTERSEXTENSIONSEXPORT
@interface WDPEPrintTaskConfigurationSaveRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPEPrintTaskConfigurationSaveRequest* request;
@end

#endif // __WDPEPrintTaskConfigurationSaveRequestedEventArgs_DEFINED__

// Windows.Devices.Printers.Extensions.PrintTaskConfiguration
#ifndef __WDPEPrintTaskConfiguration_DEFINED__
#define __WDPEPrintTaskConfiguration_DEFINED__

OBJCUWPWINDOWSDEVICESPRINTERSEXTENSIONSEXPORT
@interface WDPEPrintTaskConfiguration : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject* printerExtensionContext;
- (EventRegistrationToken)addSaveRequestedEvent:(void(^)(WDPEPrintTaskConfiguration*, WDPEPrintTaskConfigurationSaveRequestedEventArgs*))del;
- (void)removeSaveRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WDPEPrintTaskConfiguration_DEFINED__

// Windows.Devices.Printers.Extensions.PrintNotificationEventDetails
#ifndef __WDPEPrintNotificationEventDetails_DEFINED__
#define __WDPEPrintNotificationEventDetails_DEFINED__

OBJCUWPWINDOWSDEVICESPRINTERSEXTENSIONSEXPORT
@interface WDPEPrintNotificationEventDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * eventData;
@property (readonly) NSString * printerName;
@end

#endif // __WDPEPrintNotificationEventDetails_DEFINED__

// Windows.Devices.Printers.Extensions.PrintExtensionContext
#ifndef __WDPEPrintExtensionContext_DEFINED__
#define __WDPEPrintExtensionContext_DEFINED__

OBJCUWPWINDOWSDEVICESPRINTERSEXTENSIONSEXPORT
@interface WDPEPrintExtensionContext : RTObject
+ (RTObject*)fromDeviceId:(NSString *)deviceId;
@end

#endif // __WDPEPrintExtensionContext_DEFINED__

// Windows.Devices.Printers.Extensions.Print3DWorkflowPrintRequestedEventArgs
#ifndef __WDPEPrint3DWorkflowPrintRequestedEventArgs_DEFINED__
#define __WDPEPrint3DWorkflowPrintRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESPRINTERSEXTENSIONSEXPORT
@interface WDPEPrint3DWorkflowPrintRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPEPrint3DWorkflowStatus status;
- (void)setExtendedStatus:(WDPEPrint3DWorkflowDetail)value;
- (void)setSource:(RTObject*)source;
- (void)setSourceChanged:(BOOL)value;
@end

#endif // __WDPEPrint3DWorkflowPrintRequestedEventArgs_DEFINED__

// Windows.Devices.Printers.Extensions.Print3DWorkflowPrinterChangedEventArgs
#ifndef __WDPEPrint3DWorkflowPrinterChangedEventArgs_DEFINED__
#define __WDPEPrint3DWorkflowPrinterChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESPRINTERSEXTENSIONSEXPORT
@interface WDPEPrint3DWorkflowPrinterChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * newDeviceId __attribute__ ((ns_returns_not_retained));
@end

#endif // __WDPEPrint3DWorkflowPrinterChangedEventArgs_DEFINED__

// Windows.Devices.Printers.Extensions.Print3DWorkflow
#ifndef __WDPEPrint3DWorkflow_DEFINED__
#define __WDPEPrint3DWorkflow_DEFINED__

OBJCUWPWINDOWSDEVICESPRINTERSEXTENSIONSEXPORT
@interface WDPEPrint3DWorkflow : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isPrintReady;
@property (readonly) NSString * deviceID;
- (EventRegistrationToken)addPrintRequestedEvent:(void(^)(WDPEPrint3DWorkflow*, WDPEPrint3DWorkflowPrintRequestedEventArgs*))del;
- (void)removePrintRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPrinterChangedEvent:(void(^)(WDPEPrint3DWorkflow*, WDPEPrint3DWorkflowPrinterChangedEventArgs*))del;
- (void)removePrinterChangedEvent:(EventRegistrationToken)tok;
- (RTObject*)getPrintModelPackage;
@end

#endif // __WDPEPrint3DWorkflow_DEFINED__

