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

// WindowsDevicesPrintersExtensions.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDPEPrintTaskConfigurationSaveRequestedDeferral, WDPEPrintTaskConfigurationSaveRequest,
    WDPEPrintTaskConfigurationSaveRequestedEventArgs, WDPEPrintTaskConfiguration, WDPEPrintNotificationEventDetails,
    WDPEPrintExtensionContext;
@protocol WDPEIPrintTaskConfigurationSaveRequestedDeferral
, WDPEIPrintTaskConfigurationSaveRequest, WDPEIPrintTaskConfigurationSaveRequestedEventArgs, WDPEIPrintTaskConfiguration,
    WDPEIPrintNotificationEventDetails, WDPEIPrintExtensionContextStatic;

#include "WindowsFoundation.h"

// Windows.Devices.Printers.Extensions.PrintTaskConfigurationSaveRequestedDeferral
#ifndef __WDPEPrintTaskConfigurationSaveRequestedDeferral_DEFINED__
#define __WDPEPrintTaskConfigurationSaveRequestedDeferral_DEFINED__

WINRT_EXPORT
@interface WDPEPrintTaskConfigurationSaveRequestedDeferral : RTObject
- (void)complete;
@end

#endif // __WDPEPrintTaskConfigurationSaveRequestedDeferral_DEFINED__

// Windows.Devices.Printers.Extensions.PrintTaskConfigurationSaveRequest
#ifndef __WDPEPrintTaskConfigurationSaveRequest_DEFINED__
#define __WDPEPrintTaskConfigurationSaveRequest_DEFINED__

WINRT_EXPORT
@interface WDPEPrintTaskConfigurationSaveRequest : RTObject
@property (readonly) WFDateTime* deadline;
- (void)cancel;
- (void)save:(RTObject*)printerExtensionContext;
- (WDPEPrintTaskConfigurationSaveRequestedDeferral*)getDeferral;
@end

#endif // __WDPEPrintTaskConfigurationSaveRequest_DEFINED__

// Windows.Devices.Printers.Extensions.PrintTaskConfigurationSaveRequestedEventArgs
#ifndef __WDPEPrintTaskConfigurationSaveRequestedEventArgs_DEFINED__
#define __WDPEPrintTaskConfigurationSaveRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPEPrintTaskConfigurationSaveRequestedEventArgs : RTObject
@property (readonly) WDPEPrintTaskConfigurationSaveRequest* request;
@end

#endif // __WDPEPrintTaskConfigurationSaveRequestedEventArgs_DEFINED__

// Windows.Devices.Printers.Extensions.PrintTaskConfiguration
#ifndef __WDPEPrintTaskConfiguration_DEFINED__
#define __WDPEPrintTaskConfiguration_DEFINED__

WINRT_EXPORT
@interface WDPEPrintTaskConfiguration : RTObject
@property (readonly) RTObject* printerExtensionContext;
- (EventRegistrationToken)addSaveRequestedEvent:(void (^)(WDPEPrintTaskConfiguration*,
                                                          WDPEPrintTaskConfigurationSaveRequestedEventArgs*))del;
- (void)removeSaveRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WDPEPrintTaskConfiguration_DEFINED__

// Windows.Devices.Printers.Extensions.PrintNotificationEventDetails
#ifndef __WDPEPrintNotificationEventDetails_DEFINED__
#define __WDPEPrintNotificationEventDetails_DEFINED__

WINRT_EXPORT
@interface WDPEPrintNotificationEventDetails : RTObject
@property (copy) NSString* eventData;
@property (readonly) NSString* printerName;
@end

#endif // __WDPEPrintNotificationEventDetails_DEFINED__

// Windows.Devices.Printers.Extensions.PrintExtensionContext
#ifndef __WDPEPrintExtensionContext_DEFINED__
#define __WDPEPrintExtensionContext_DEFINED__

WINRT_EXPORT
@interface WDPEPrintExtensionContext : RTObject
+ (RTObject*)fromDeviceId:(NSString*)deviceId;
@end

#endif // __WDPEPrintExtensionContext_DEFINED__
