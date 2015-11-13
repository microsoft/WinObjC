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

// WindowsFoundationDiagnostics.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WFDTracingStatusChangedEventArgs, WFDAsyncCausalityTracer, WFDRuntimeBrokerErrorSettings, WFDLoggingChannel, WFDLoggingActivity,
    WFDLoggingSession, WFDLogFileGeneratedEventArgs, WFDFileLoggingSession;
@protocol WFDITracingStatusChangedEventArgs
, WFDIAsyncCausalityTracerStatics, WFDIErrorReportingSettings, WFDILoggingChannel, WFDILoggingChannelFactory, WFDILoggingActivity,
    WFDILoggingActivityFactory, WFDILoggingSession, WFDILoggingSessionFactory, WFDILogFileGeneratedEventArgs, WFDIFileLoggingSession,
    WFDIFileLoggingSessionFactory;

// Windows.Foundation.Diagnostics.CausalityTraceLevel
enum _WFDCausalityTraceLevel {
    WFDCausalityTraceLevelRequired = 0,
    WFDCausalityTraceLevelImportant = 1,
    WFDCausalityTraceLevelVerbose = 2,
};
typedef unsigned WFDCausalityTraceLevel;

// Windows.Foundation.Diagnostics.CausalitySource
enum _WFDCausalitySource {
    WFDCausalitySourceApplication = 0,
    WFDCausalitySourceLibrary = 1,
    WFDCausalitySourceSystem = 2,
};
typedef unsigned WFDCausalitySource;

// Windows.Foundation.Diagnostics.CausalityRelation
enum _WFDCausalityRelation {
    WFDCausalityRelationAssignDelegate = 0,
    WFDCausalityRelationJoin = 1,
    WFDCausalityRelationChoice = 2,
    WFDCausalityRelationCancel = 3,
    WFDCausalityRelationError = 4,
};
typedef unsigned WFDCausalityRelation;

// Windows.Foundation.Diagnostics.CausalitySynchronousWork
enum _WFDCausalitySynchronousWork {
    WFDCausalitySynchronousWorkCompletionNotification = 0,
    WFDCausalitySynchronousWorkProgressNotification = 1,
    WFDCausalitySynchronousWorkExecution = 2,
};
typedef unsigned WFDCausalitySynchronousWork;

// Windows.Foundation.Diagnostics.ErrorOptions
enum _WFDErrorOptions {
    WFDErrorOptionsNone = 0,
    WFDErrorOptionsSuppressExceptions = 1,
    WFDErrorOptionsForceExceptions = 2,
    WFDErrorOptionsUseSetErrorInfo = 4,
    WFDErrorOptionsSuppressSetErrorInfo = 8,
};
typedef unsigned WFDErrorOptions;

// Windows.Foundation.Diagnostics.LoggingLevel
enum _WFDLoggingLevel {
    WFDLoggingLevelVerbose = 0,
    WFDLoggingLevelInformation = 1,
    WFDLoggingLevelWarning = 2,
    WFDLoggingLevelError = 3,
    WFDLoggingLevelCritical = 4,
};
typedef unsigned WFDLoggingLevel;

#include "WindowsStorage.h"
#include "WindowsFoundation.h"

// Windows.Foundation.Diagnostics.IErrorReportingSettings
#ifndef __WFDIErrorReportingSettings_DEFINED__
#define __WFDIErrorReportingSettings_DEFINED__

@protocol WFDIErrorReportingSettings
- (void)setErrorOptions:(WFDErrorOptions)value;
- (WFDErrorOptions)getErrorOptions;
@end

#endif // __WFDIErrorReportingSettings_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Foundation.Diagnostics.ILoggingChannel
#ifndef __WFDILoggingChannel_DEFINED__
#define __WFDILoggingChannel_DEFINED__

@protocol WFDILoggingChannel <WFIClosable>
@property (readonly) BOOL enabled;
@property (readonly) WFDLoggingLevel level;
@property (readonly) NSString* name;
- (EventRegistrationToken)addLoggingEnabledEvent:(void (^)(RTObject<WFDILoggingChannel>*, RTObject*))del;
- (void)removeLoggingEnabledEvent:(EventRegistrationToken)tok;
- (void)logMessage:(NSString*)eventString;
- (void)logMessageWithLevel:(NSString*)eventString level:(WFDLoggingLevel)level;
- (void)logValuePair:(NSString*)value1 value2:(int)value2;
- (void)logValuePairWithLevel:(NSString*)value1 value2:(int)value2 level:(WFDLoggingLevel)level;
- (void)close;
@end

#endif // __WFDILoggingChannel_DEFINED__

// Windows.Foundation.Diagnostics.ILoggingSession
#ifndef __WFDILoggingSession_DEFINED__
#define __WFDILoggingSession_DEFINED__

@protocol WFDILoggingSession <WFIClosable>
@property (readonly) NSString* name;
- (void)saveToFileAsync:(RTObject<WSIStorageFolder>*)folder
               fileName:(NSString*)fileName
                success:(void (^)(WSStorageFile*))success
                failure:(void (^)(NSError*))failure;
- (void)addLoggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel;
- (void)addLoggingChannelWithLevel:(RTObject<WFDILoggingChannel>*)loggingChannel maxLevel:(WFDLoggingLevel)maxLevel;
- (void)removeLoggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel;
- (void)close;
@end

#endif // __WFDILoggingSession_DEFINED__

// Windows.Foundation.Diagnostics.IFileLoggingSession
#ifndef __WFDIFileLoggingSession_DEFINED__
#define __WFDIFileLoggingSession_DEFINED__

@protocol WFDIFileLoggingSession <WFIClosable>
@property (readonly) NSString* name;
- (EventRegistrationToken)addLogFileGeneratedEvent:(void (^)(RTObject<WFDIFileLoggingSession>*, WFDLogFileGeneratedEventArgs*))del;
- (void)removeLogFileGeneratedEvent:(EventRegistrationToken)tok;
- (void)addLoggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel;
- (void)addLoggingChannelWithLevel:(RTObject<WFDILoggingChannel>*)loggingChannel maxLevel:(WFDLoggingLevel)maxLevel;
- (void)removeLoggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel;
- (void)closeAndSaveToFileAsyncWithSuccess:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WFDIFileLoggingSession_DEFINED__

// Windows.Foundation.Diagnostics.TracingStatusChangedEventArgs
#ifndef __WFDTracingStatusChangedEventArgs_DEFINED__
#define __WFDTracingStatusChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WFDTracingStatusChangedEventArgs : RTObject
@property (readonly) BOOL enabled;
@property (readonly) WFDCausalityTraceLevel traceLevel;
@end

#endif // __WFDTracingStatusChangedEventArgs_DEFINED__

// Windows.Foundation.Diagnostics.AsyncCausalityTracer
#ifndef __WFDAsyncCausalityTracer_DEFINED__
#define __WFDAsyncCausalityTracer_DEFINED__

WINRT_EXPORT
@interface WFDAsyncCausalityTracer : RTObject
+ (void)traceOperationCreation:(WFDCausalityTraceLevel)traceLevel
                        source:(WFDCausalitySource)source
                    platformId:(WFGUID*)platformId
                   operationId:(uint64_t)operationId
                 operationName:(NSString*)operationName
                relatedContext:(uint64_t)relatedContext;
+ (void)traceOperationCompletion:(WFDCausalityTraceLevel)traceLevel
                          source:(WFDCausalitySource)source
                      platformId:(WFGUID*)platformId
                     operationId:(uint64_t)operationId
                          status:(WFAsyncStatus)status;
+ (void)traceOperationRelation:(WFDCausalityTraceLevel)traceLevel
                        source:(WFDCausalitySource)source
                    platformId:(WFGUID*)platformId
                   operationId:(uint64_t)operationId
                      relation:(WFDCausalityRelation)relation;
+ (void)traceSynchronousWorkStart:(WFDCausalityTraceLevel)traceLevel
                           source:(WFDCausalitySource)source
                       platformId:(WFGUID*)platformId
                      operationId:(uint64_t)operationId
                             work:(WFDCausalitySynchronousWork)work;
+ (void)traceSynchronousWorkCompletion:(WFDCausalityTraceLevel)traceLevel
                                source:(WFDCausalitySource)source
                                  work:(WFDCausalitySynchronousWork)work;
+ (EventRegistrationToken)addTracingStatusChangedEvent:(void (^)(RTObject*, WFDTracingStatusChangedEventArgs*))del;
+ (void)removeTracingStatusChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WFDAsyncCausalityTracer_DEFINED__

// Windows.Foundation.Diagnostics.RuntimeBrokerErrorSettings
#ifndef __WFDRuntimeBrokerErrorSettings_DEFINED__
#define __WFDRuntimeBrokerErrorSettings_DEFINED__

WINRT_EXPORT
@interface WFDRuntimeBrokerErrorSettings : RTObject <WFDIErrorReportingSettings>
+ (instancetype)create ACTIVATOR;
- (void)setErrorOptions:(WFDErrorOptions)value;
- (WFDErrorOptions)getErrorOptions;
@end

#endif // __WFDRuntimeBrokerErrorSettings_DEFINED__

// Windows.Foundation.Diagnostics.LoggingChannel
#ifndef __WFDLoggingChannel_DEFINED__
#define __WFDLoggingChannel_DEFINED__

WINRT_EXPORT
@interface WFDLoggingChannel : RTObject <WFDILoggingChannel, WFIClosable>
+ (WFDLoggingChannel*)create:(NSString*)name ACTIVATOR;
@property (readonly) BOOL enabled;
@property (readonly) WFDLoggingLevel level;
@property (readonly) NSString* name;
- (EventRegistrationToken)addLoggingEnabledEvent:(void (^)(RTObject<WFDILoggingChannel>*, RTObject*))del;
- (void)removeLoggingEnabledEvent:(EventRegistrationToken)tok;
- (void)logMessage:(NSString*)eventString;
- (void)logMessageWithLevel:(NSString*)eventString level:(WFDLoggingLevel)level;
- (void)logValuePair:(NSString*)value1 value2:(int)value2;
- (void)logValuePairWithLevel:(NSString*)value1 value2:(int)value2 level:(WFDLoggingLevel)level;
- (void)close;
@end

#endif // __WFDLoggingChannel_DEFINED__

// Windows.Foundation.Diagnostics.LoggingActivity
#ifndef __WFDLoggingActivity_DEFINED__
#define __WFDLoggingActivity_DEFINED__

WINRT_EXPORT
@interface WFDLoggingActivity : RTObject <WFIClosable>
+ (WFDLoggingActivity*)createLoggingActivity:(NSString*)activityName loggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel ACTIVATOR;
+ (WFDLoggingActivity*)createLoggingActivityWithLevel:(NSString*)activityName
                                       loggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel
                                                level:(WFDLoggingLevel)level ACTIVATOR;
@property (readonly) WFGUID* id;
@property (readonly) NSString* name;
- (void)close;
@end

#endif // __WFDLoggingActivity_DEFINED__

// Windows.Foundation.Diagnostics.LoggingSession
#ifndef __WFDLoggingSession_DEFINED__
#define __WFDLoggingSession_DEFINED__

WINRT_EXPORT
@interface WFDLoggingSession : RTObject <WFDILoggingSession, WFIClosable>
+ (WFDLoggingSession*)create:(NSString*)name ACTIVATOR;
@property (readonly) NSString* name;
- (void)saveToFileAsync:(RTObject<WSIStorageFolder>*)folder
               fileName:(NSString*)fileName
                success:(void (^)(WSStorageFile*))success
                failure:(void (^)(NSError*))failure;
- (void)addLoggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel;
- (void)addLoggingChannelWithLevel:(RTObject<WFDILoggingChannel>*)loggingChannel maxLevel:(WFDLoggingLevel)maxLevel;
- (void)removeLoggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel;
- (void)close;
@end

#endif // __WFDLoggingSession_DEFINED__

// Windows.Foundation.Diagnostics.LogFileGeneratedEventArgs
#ifndef __WFDLogFileGeneratedEventArgs_DEFINED__
#define __WFDLogFileGeneratedEventArgs_DEFINED__

WINRT_EXPORT
@interface WFDLogFileGeneratedEventArgs : RTObject
@property (readonly) WSStorageFile* file;
@end

#endif // __WFDLogFileGeneratedEventArgs_DEFINED__

// Windows.Foundation.Diagnostics.FileLoggingSession
#ifndef __WFDFileLoggingSession_DEFINED__
#define __WFDFileLoggingSession_DEFINED__

WINRT_EXPORT
@interface WFDFileLoggingSession : RTObject <WFDIFileLoggingSession, WFIClosable>
+ (WFDFileLoggingSession*)create:(NSString*)name ACTIVATOR;
@property (readonly) NSString* name;
- (EventRegistrationToken)addLogFileGeneratedEvent:(void (^)(RTObject<WFDIFileLoggingSession>*, WFDLogFileGeneratedEventArgs*))del;
- (void)removeLogFileGeneratedEvent:(EventRegistrationToken)tok;
- (void)addLoggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel;
- (void)addLoggingChannelWithLevel:(RTObject<WFDILoggingChannel>*)loggingChannel maxLevel:(WFDLoggingLevel)maxLevel;
- (void)removeLoggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel;
- (void)closeAndSaveToFileAsyncWithSuccess:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WFDFileLoggingSession_DEFINED__
