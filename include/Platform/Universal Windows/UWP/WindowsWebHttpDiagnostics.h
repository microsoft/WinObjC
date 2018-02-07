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

// WindowsWebHttpDiagnostics.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSWEBHTTPDIAGNOSTICSEXPORT
#define OBJCUWPWINDOWSWEBHTTPDIAGNOSTICSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsWebHttpDiagnostics.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WWHDHttpDiagnosticSourceLocation, WWHDHttpDiagnosticProviderRequestSentEventArgs, WWHDHttpDiagnosticProviderResponseReceivedEventArgs, WWHDHttpDiagnosticProviderRequestResponseTimestamps, WWHDHttpDiagnosticProviderRequestResponseCompletedEventArgs, WWHDHttpDiagnosticProvider;
@protocol WWHDIHttpDiagnosticSourceLocation, WWHDIHttpDiagnosticProviderRequestSentEventArgs, WWHDIHttpDiagnosticProviderResponseReceivedEventArgs, WWHDIHttpDiagnosticProviderRequestResponseTimestamps, WWHDIHttpDiagnosticProviderRequestResponseCompletedEventArgs, WWHDIHttpDiagnosticProviderStatics, WWHDIHttpDiagnosticProvider;

// Windows.Web.Http.Diagnostics.HttpDiagnosticRequestInitiator
enum _WWHDHttpDiagnosticRequestInitiator {
    WWHDHttpDiagnosticRequestInitiatorParsedElement = 0,
    WWHDHttpDiagnosticRequestInitiatorScript = 1,
    WWHDHttpDiagnosticRequestInitiatorImage = 2,
    WWHDHttpDiagnosticRequestInitiatorLink = 3,
    WWHDHttpDiagnosticRequestInitiatorStyle = 4,
    WWHDHttpDiagnosticRequestInitiatorXmlHttpRequest = 5,
    WWHDHttpDiagnosticRequestInitiatorMedia = 6,
    WWHDHttpDiagnosticRequestInitiatorHtmlDownload = 7,
    WWHDHttpDiagnosticRequestInitiatorPrefetch = 8,
    WWHDHttpDiagnosticRequestInitiatorOther = 9,
    WWHDHttpDiagnosticRequestInitiatorCrossOriginPreFlight = 10,
    WWHDHttpDiagnosticRequestInitiatorFetch = 11,
    WWHDHttpDiagnosticRequestInitiatorBeacon = 12,
};
typedef unsigned WWHDHttpDiagnosticRequestInitiator;

#include "WindowsFoundation.h"
#include "WindowsWebHttp.h"
#include "WindowsSystemDiagnostics.h"

#import <Foundation/Foundation.h>

// Windows.Web.Http.Diagnostics.HttpDiagnosticSourceLocation
#ifndef __WWHDHttpDiagnosticSourceLocation_DEFINED__
#define __WWHDHttpDiagnosticSourceLocation_DEFINED__

OBJCUWPWINDOWSWEBHTTPDIAGNOSTICSEXPORT
@interface WWHDHttpDiagnosticSourceLocation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) uint64_t columnNumber;
@property (readonly) uint64_t lineNumber;
@property (readonly) WFUri* sourceUri;
@end

#endif // __WWHDHttpDiagnosticSourceLocation_DEFINED__

// Windows.Web.Http.Diagnostics.HttpDiagnosticProviderRequestSentEventArgs
#ifndef __WWHDHttpDiagnosticProviderRequestSentEventArgs_DEFINED__
#define __WWHDHttpDiagnosticProviderRequestSentEventArgs_DEFINED__

OBJCUWPWINDOWSWEBHTTPDIAGNOSTICSEXPORT
@interface WWHDHttpDiagnosticProviderRequestSentEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFGUID* activityId;
@property (readonly) WWHDHttpDiagnosticRequestInitiator initiator;
@property (readonly) WWHHttpRequestMessage* message;
@property (readonly) unsigned int processId;
@property (readonly) NSArray* /* WWHDHttpDiagnosticSourceLocation* */ sourceLocations;
@property (readonly) unsigned int threadId;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WWHDHttpDiagnosticProviderRequestSentEventArgs_DEFINED__

// Windows.Web.Http.Diagnostics.HttpDiagnosticProviderResponseReceivedEventArgs
#ifndef __WWHDHttpDiagnosticProviderResponseReceivedEventArgs_DEFINED__
#define __WWHDHttpDiagnosticProviderResponseReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSWEBHTTPDIAGNOSTICSEXPORT
@interface WWHDHttpDiagnosticProviderResponseReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFGUID* activityId;
@property (readonly) WWHHttpResponseMessage* message;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WWHDHttpDiagnosticProviderResponseReceivedEventArgs_DEFINED__

// Windows.Web.Http.Diagnostics.HttpDiagnosticProviderRequestResponseTimestamps
#ifndef __WWHDHttpDiagnosticProviderRequestResponseTimestamps_DEFINED__
#define __WWHDHttpDiagnosticProviderRequestResponseTimestamps_DEFINED__

OBJCUWPWINDOWSWEBHTTPDIAGNOSTICSEXPORT
@interface WWHDHttpDiagnosticProviderRequestResponseTimestamps : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) id /* WFDateTime* */ cacheCheckedTimestamp;
@property (readonly) id /* WFDateTime* */ connectionCompletedTimestamp;
@property (readonly) id /* WFDateTime* */ connectionInitiatedTimestamp;
@property (readonly) id /* WFDateTime* */ nameResolvedTimestamp;
@property (readonly) id /* WFDateTime* */ requestCompletedTimestamp;
@property (readonly) id /* WFDateTime* */ requestSentTimestamp;
@property (readonly) id /* WFDateTime* */ responseCompletedTimestamp;
@property (readonly) id /* WFDateTime* */ responseReceivedTimestamp;
@property (readonly) id /* WFDateTime* */ sslNegotiatedTimestamp;
@end

#endif // __WWHDHttpDiagnosticProviderRequestResponseTimestamps_DEFINED__

// Windows.Web.Http.Diagnostics.HttpDiagnosticProviderRequestResponseCompletedEventArgs
#ifndef __WWHDHttpDiagnosticProviderRequestResponseCompletedEventArgs_DEFINED__
#define __WWHDHttpDiagnosticProviderRequestResponseCompletedEventArgs_DEFINED__

OBJCUWPWINDOWSWEBHTTPDIAGNOSTICSEXPORT
@interface WWHDHttpDiagnosticProviderRequestResponseCompletedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFGUID* activityId;
@property (readonly) WWHDHttpDiagnosticRequestInitiator initiator;
@property (readonly) unsigned int processId;
@property (readonly) WFUri* requestedUri;
@property (readonly) NSArray* /* WWHDHttpDiagnosticSourceLocation* */ sourceLocations;
@property (readonly) unsigned int threadId;
@property (readonly) WWHDHttpDiagnosticProviderRequestResponseTimestamps* timestamps;
@end

#endif // __WWHDHttpDiagnosticProviderRequestResponseCompletedEventArgs_DEFINED__

// Windows.Web.Http.Diagnostics.HttpDiagnosticProvider
#ifndef __WWHDHttpDiagnosticProvider_DEFINED__
#define __WWHDHttpDiagnosticProvider_DEFINED__

OBJCUWPWINDOWSWEBHTTPDIAGNOSTICSEXPORT
@interface WWHDHttpDiagnosticProvider : RTObject
+ (WWHDHttpDiagnosticProvider*)createFromProcessDiagnosticInfo:(WSDProcessDiagnosticInfo*)processDiagnosticInfo;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addRequestResponseCompletedEvent:(void(^)(WWHDHttpDiagnosticProvider*, WWHDHttpDiagnosticProviderRequestResponseCompletedEventArgs*))del;
- (void)removeRequestResponseCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRequestSentEvent:(void(^)(WWHDHttpDiagnosticProvider*, WWHDHttpDiagnosticProviderRequestSentEventArgs*))del;
- (void)removeRequestSentEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addResponseReceivedEvent:(void(^)(WWHDHttpDiagnosticProvider*, WWHDHttpDiagnosticProviderResponseReceivedEventArgs*))del;
- (void)removeResponseReceivedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WWHDHttpDiagnosticProvider_DEFINED__

