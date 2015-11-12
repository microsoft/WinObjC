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
@class WFDTracingStatusChangedEventArgs, WFDAsyncCausalityTracer, WFDRuntimeBrokerErrorSettings, WFDErrorDetails, WFDLoggingOptions,
    WFDLoggingChannelOptions, WFDLoggingFields, WFDLoggingActivity, WFDLoggingChannel, WFDLoggingSession, WFDLogFileGeneratedEventArgs,
    WFDFileLoggingSession;
@protocol WFDITracingStatusChangedEventArgs
, WFDIAsyncCausalityTracerStatics, WFDIErrorReportingSettings, WFDIErrorDetailsStatics, WFDIErrorDetails, WFDILoggingOptions,
    WFDILoggingOptionsFactory, WFDILoggingChannelOptions, WFDILoggingChannelOptionsFactory, WFDILoggingFields, WFDILoggingTarget,
    WFDILoggingChannel, WFDILoggingChannel2, WFDILoggingChannelFactory, WFDILoggingChannelFactory2, WFDILoggingActivity,
    WFDILoggingActivity2, WFDILoggingActivityFactory, WFDILoggingSession, WFDILoggingSessionFactory, WFDILogFileGeneratedEventArgs,
    WFDIFileLoggingSession, WFDIFileLoggingSessionFactory;

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

// Windows.Foundation.Diagnostics.LoggingOpcode
enum _WFDLoggingOpcode {
    WFDLoggingOpcodeInfo = 0,
    WFDLoggingOpcodeStart = 1,
    WFDLoggingOpcodeStop = 2,
    WFDLoggingOpcodeReply = 6,
    WFDLoggingOpcodeResume = 7,
    WFDLoggingOpcodeSuspend = 8,
    WFDLoggingOpcodeSend = 9,
};
typedef unsigned WFDLoggingOpcode;

// Windows.Foundation.Diagnostics.LoggingFieldFormat
enum _WFDLoggingFieldFormat {
    WFDLoggingFieldFormatDefault = 0,
    WFDLoggingFieldFormatHidden = 1,
    WFDLoggingFieldFormatString = 2,
    WFDLoggingFieldFormatBoolean = 3,
    WFDLoggingFieldFormatHexadecimal = 4,
    WFDLoggingFieldFormatProcessId = 5,
    WFDLoggingFieldFormatThreadId = 6,
    WFDLoggingFieldFormatPort = 7,
    WFDLoggingFieldFormatIpv4Address = 8,
    WFDLoggingFieldFormatIpv6Address = 9,
    WFDLoggingFieldFormatSocketAddress = 10,
    WFDLoggingFieldFormatXml = 11,
    WFDLoggingFieldFormatJson = 12,
    WFDLoggingFieldFormatWin32Error = 13,
    WFDLoggingFieldFormatNTStatus = 14,
    WFDLoggingFieldFormatHResult = 15,
    WFDLoggingFieldFormatFileTime = 16,
    WFDLoggingFieldFormatSigned = 17,
    WFDLoggingFieldFormatUnsigned = 18,
};
typedef unsigned WFDLoggingFieldFormat;

#include "WindowsStorage.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.Diagnostics.IErrorReportingSettings
#ifndef __WFDIErrorReportingSettings_DEFINED__
#define __WFDIErrorReportingSettings_DEFINED__

@protocol WFDIErrorReportingSettings
- (void)setErrorOptions:(WFDErrorOptions)value;
- (WFDErrorOptions)getErrorOptions;
@end

#endif // __WFDIErrorReportingSettings_DEFINED__

// Windows.Foundation.Diagnostics.ILoggingTarget
#ifndef __WFDILoggingTarget_DEFINED__
#define __WFDILoggingTarget_DEFINED__

@protocol WFDILoggingTarget
- (BOOL)isEnabled;
- (BOOL)isEnabledWithLevel:(WFDLoggingLevel)level;
- (BOOL)isEnabledWithLevelAndKeywords:(WFDLoggingLevel)level keywords:(int64_t)keywords;
- (void)logEvent:(NSString*)eventName;
- (void)logEventWithFields:(NSString*)eventName fields:(WFDLoggingFields*)fields;
- (void)logEventWithFieldsAndLevel:(NSString*)eventName fields:(WFDLoggingFields*)fields level:(WFDLoggingLevel)level;
- (void)logEventWithFieldsAndOptions:(NSString*)eventName
                              fields:(WFDLoggingFields*)fields
                               level:(WFDLoggingLevel)level
                             options:(WFDLoggingOptions*)options;
- (WFDLoggingActivity*)startActivity:(NSString*)startEventName;
- (WFDLoggingActivity*)startActivityWithFields:(NSString*)startEventName fields:(WFDLoggingFields*)fields;
- (WFDLoggingActivity*)startActivityWithFieldsAndLevel:(NSString*)startEventName
                                                fields:(WFDLoggingFields*)fields
                                                 level:(WFDLoggingLevel)level;
- (WFDLoggingActivity*)startActivityWithFieldsAndOptions:(NSString*)startEventName
                                                  fields:(WFDLoggingFields*)fields
                                                   level:(WFDLoggingLevel)level
                                                 options:(WFDLoggingOptions*)options;
@end

#endif // __WFDILoggingTarget_DEFINED__

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

// Windows.Foundation.Diagnostics.ErrorDetails
#ifndef __WFDErrorDetails_DEFINED__
#define __WFDErrorDetails_DEFINED__

WINRT_EXPORT
@interface WFDErrorDetails : RTObject
+ (void)createFromHResultAsync:(int)errorCode success:(void (^)(WFDErrorDetails*))success failure:(void (^)(NSError*))failure;
@property (readonly) NSString* description;
@property (readonly) WFUri* helpUri;
@property (readonly) NSString* longDescription;
@end

#endif // __WFDErrorDetails_DEFINED__

// Windows.Foundation.Diagnostics.LoggingOptions
#ifndef __WFDLoggingOptions_DEFINED__
#define __WFDLoggingOptions_DEFINED__

WINRT_EXPORT
@interface WFDLoggingOptions : RTObject
+ (instancetype)create ACTIVATOR;
+ (WFDLoggingOptions*)createWithKeywords:(int64_t)keywords ACTIVATOR;
@property int16_t task;
@property int tags;
@property WFGUID* relatedActivityId;
@property WFDLoggingOpcode opcode;
@property int64_t keywords;
@property WFGUID* activityId;
@end

#endif // __WFDLoggingOptions_DEFINED__

// Windows.Foundation.Diagnostics.LoggingChannelOptions
#ifndef __WFDLoggingChannelOptions_DEFINED__
#define __WFDLoggingChannelOptions_DEFINED__

WINRT_EXPORT
@interface WFDLoggingChannelOptions : RTObject
+ (WFDLoggingChannelOptions*)create:(WFGUID*)group ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property WFGUID* group;
@end

#endif // __WFDLoggingChannelOptions_DEFINED__

// Windows.Foundation.Diagnostics.LoggingFields
#ifndef __WFDLoggingFields_DEFINED__
#define __WFDLoggingFields_DEFINED__

WINRT_EXPORT
@interface WFDLoggingFields : RTObject
+ (instancetype)create ACTIVATOR;
- (void)clear;
- (void)beginStruct:(NSString*)name;
- (void)beginStructWithTags:(NSString*)name tags:(int)tags;
- (void)endStruct;
- (void)addEmpty:(NSString*)name;
- (void)addEmptyWithFormat:(NSString*)name format:(WFDLoggingFieldFormat)format;
- (void)addEmptyWithFormatAndTags:(NSString*)name format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addUInt8:(NSString*)name value:(uint8_t)value;
- (void)addUInt8WithFormat:(NSString*)name value:(uint8_t)value format:(WFDLoggingFieldFormat)format;
- (void)addUInt8WithFormatAndTags:(NSString*)name value:(uint8_t)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addUInt8Array:(NSString*)name value:(id<NSFastEnumeration> /* uint8_t */)value;
- (void)addUInt8ArrayWithFormat:(NSString*)name value:(id<NSFastEnumeration> /* uint8_t */)value format:(WFDLoggingFieldFormat)format;
- (void)addUInt8ArrayWithFormatAndTags:(NSString*)name
                                 value:(id<NSFastEnumeration> /* uint8_t */)value
                                format:(WFDLoggingFieldFormat)format
                                  tags:(int)tags;
- (void)addInt16:(NSString*)name value:(int16_t)value;
- (void)addInt16WithFormat:(NSString*)name value:(int16_t)value format:(WFDLoggingFieldFormat)format;
- (void)addInt16WithFormatAndTags:(NSString*)name value:(int16_t)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addInt16Array:(NSString*)name value:(id<NSFastEnumeration> /* int16_t */)value;
- (void)addInt16ArrayWithFormat:(NSString*)name value:(id<NSFastEnumeration> /* int16_t */)value format:(WFDLoggingFieldFormat)format;
- (void)addInt16ArrayWithFormatAndTags:(NSString*)name
                                 value:(id<NSFastEnumeration> /* int16_t */)value
                                format:(WFDLoggingFieldFormat)format
                                  tags:(int)tags;
- (void)addUInt16:(NSString*)name value:(unsigned short)value;
- (void)addUInt16WithFormat:(NSString*)name value:(unsigned short)value format:(WFDLoggingFieldFormat)format;
- (void)addUInt16WithFormatAndTags:(NSString*)name value:(unsigned short)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addUInt16Array:(NSString*)name value:(id<NSFastEnumeration> /* unsigned short */)value;
- (void)addUInt16ArrayWithFormat:(NSString*)name
                           value:(id<NSFastEnumeration> /* unsigned short */)value
                          format:(WFDLoggingFieldFormat)format;
- (void)addUInt16ArrayWithFormatAndTags:(NSString*)name
                                  value:(id<NSFastEnumeration> /* unsigned short */)value
                                 format:(WFDLoggingFieldFormat)format
                                   tags:(int)tags;
- (void)addInt32:(NSString*)name value:(int)value;
- (void)addInt32WithFormat:(NSString*)name value:(int)value format:(WFDLoggingFieldFormat)format;
- (void)addInt32WithFormatAndTags:(NSString*)name value:(int)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addInt32Array:(NSString*)name value:(id<NSFastEnumeration> /* int */)value;
- (void)addInt32ArrayWithFormat:(NSString*)name value:(id<NSFastEnumeration> /* int */)value format:(WFDLoggingFieldFormat)format;
- (void)addInt32ArrayWithFormatAndTags:(NSString*)name
                                 value:(id<NSFastEnumeration> /* int */)value
                                format:(WFDLoggingFieldFormat)format
                                  tags:(int)tags;
- (void)addUInt32:(NSString*)name value:(unsigned int)value;
- (void)addUInt32WithFormat:(NSString*)name value:(unsigned int)value format:(WFDLoggingFieldFormat)format;
- (void)addUInt32WithFormatAndTags:(NSString*)name value:(unsigned int)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addUInt32Array:(NSString*)name value:(id<NSFastEnumeration> /* unsigned int */)value;
- (void)addUInt32ArrayWithFormat:(NSString*)name value:(id<NSFastEnumeration> /* unsigned int */)value format:(WFDLoggingFieldFormat)format;
- (void)addUInt32ArrayWithFormatAndTags:(NSString*)name
                                  value:(id<NSFastEnumeration> /* unsigned int */)value
                                 format:(WFDLoggingFieldFormat)format
                                   tags:(int)tags;
- (void)addInt64:(NSString*)name value:(int64_t)value;
- (void)addInt64WithFormat:(NSString*)name value:(int64_t)value format:(WFDLoggingFieldFormat)format;
- (void)addInt64WithFormatAndTags:(NSString*)name value:(int64_t)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addInt64Array:(NSString*)name value:(id<NSFastEnumeration> /* int64_t */)value;
- (void)addInt64ArrayWithFormat:(NSString*)name value:(id<NSFastEnumeration> /* int64_t */)value format:(WFDLoggingFieldFormat)format;
- (void)addInt64ArrayWithFormatAndTags:(NSString*)name
                                 value:(id<NSFastEnumeration> /* int64_t */)value
                                format:(WFDLoggingFieldFormat)format
                                  tags:(int)tags;
- (void)addUInt64:(NSString*)name value:(uint64_t)value;
- (void)addUInt64WithFormat:(NSString*)name value:(uint64_t)value format:(WFDLoggingFieldFormat)format;
- (void)addUInt64WithFormatAndTags:(NSString*)name value:(uint64_t)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addUInt64Array:(NSString*)name value:(id<NSFastEnumeration> /* uint64_t */)value;
- (void)addUInt64ArrayWithFormat:(NSString*)name value:(id<NSFastEnumeration> /* uint64_t */)value format:(WFDLoggingFieldFormat)format;
- (void)addUInt64ArrayWithFormatAndTags:(NSString*)name
                                  value:(id<NSFastEnumeration> /* uint64_t */)value
                                 format:(WFDLoggingFieldFormat)format
                                   tags:(int)tags;
- (void)addSingle:(NSString*)name value:(float)value;
- (void)addSingleWithFormat:(NSString*)name value:(float)value format:(WFDLoggingFieldFormat)format;
- (void)addSingleWithFormatAndTags:(NSString*)name value:(float)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addSingleArray:(NSString*)name value:(id<NSFastEnumeration> /* float */)value;
- (void)addSingleArrayWithFormat:(NSString*)name value:(id<NSFastEnumeration> /* float */)value format:(WFDLoggingFieldFormat)format;
- (void)addSingleArrayWithFormatAndTags:(NSString*)name
                                  value:(id<NSFastEnumeration> /* float */)value
                                 format:(WFDLoggingFieldFormat)format
                                   tags:(int)tags;
- (void)addDouble:(NSString*)name value:(double)value;
- (void)addDoubleWithFormat:(NSString*)name value:(double)value format:(WFDLoggingFieldFormat)format;
- (void)addDoubleWithFormatAndTags:(NSString*)name value:(double)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addDoubleArray:(NSString*)name value:(id<NSFastEnumeration> /* double */)value;
- (void)addDoubleArrayWithFormat:(NSString*)name value:(id<NSFastEnumeration> /* double */)value format:(WFDLoggingFieldFormat)format;
- (void)addDoubleArrayWithFormatAndTags:(NSString*)name
                                  value:(id<NSFastEnumeration> /* double */)value
                                 format:(WFDLoggingFieldFormat)format
                                   tags:(int)tags;
- (void)addChar16:(NSString*)name value:(WCHAR)value;
- (void)addChar16WithFormat:(NSString*)name value:(WCHAR)value format:(WFDLoggingFieldFormat)format;
- (void)addChar16WithFormatAndTags:(NSString*)name value:(WCHAR)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addChar16Array:(NSString*)name value:(id<NSFastEnumeration> /* WCHAR */)value;
- (void)addChar16ArrayWithFormat:(NSString*)name value:(id<NSFastEnumeration> /* WCHAR */)value format:(WFDLoggingFieldFormat)format;
- (void)addChar16ArrayWithFormatAndTags:(NSString*)name
                                  value:(id<NSFastEnumeration> /* WCHAR */)value
                                 format:(WFDLoggingFieldFormat)format
                                   tags:(int)tags;
- (void)addBoolean:(NSString*)name value:(BOOL)value;
- (void)addBooleanWithFormat:(NSString*)name value:(BOOL)value format:(WFDLoggingFieldFormat)format;
- (void)addBooleanWithFormatAndTags:(NSString*)name value:(BOOL)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addBooleanArray:(NSString*)name value:(id<NSFastEnumeration> /* BOOL */)value;
- (void)addBooleanArrayWithFormat:(NSString*)name value:(id<NSFastEnumeration> /* BOOL */)value format:(WFDLoggingFieldFormat)format;
- (void)addBooleanArrayWithFormatAndTags:(NSString*)name
                                   value:(id<NSFastEnumeration> /* BOOL */)value
                                  format:(WFDLoggingFieldFormat)format
                                    tags:(int)tags;
- (void)addString:(NSString*)name value:(NSString*)value;
- (void)addStringWithFormat:(NSString*)name value:(NSString*)value format:(WFDLoggingFieldFormat)format;
- (void)addStringWithFormatAndTags:(NSString*)name value:(NSString*)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addStringArray:(NSString*)name value:(id<NSFastEnumeration> /* NSString * */)value;
- (void)addStringArrayWithFormat:(NSString*)name value:(id<NSFastEnumeration> /* NSString * */)value format:(WFDLoggingFieldFormat)format;
- (void)addStringArrayWithFormatAndTags:(NSString*)name
                                  value:(id<NSFastEnumeration> /* NSString * */)value
                                 format:(WFDLoggingFieldFormat)format
                                   tags:(int)tags;
- (void)addGuid:(NSString*)name value:(WFGUID*)value;
- (void)addGuidWithFormat:(NSString*)name value:(WFGUID*)value format:(WFDLoggingFieldFormat)format;
- (void)addGuidWithFormatAndTags:(NSString*)name value:(WFGUID*)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addGuidArray:(NSString*)name value:(id<NSFastEnumeration> /* WFGUID* */)value;
- (void)addGuidArrayWithFormat:(NSString*)name value:(id<NSFastEnumeration> /* WFGUID* */)value format:(WFDLoggingFieldFormat)format;
- (void)addGuidArrayWithFormatAndTags:(NSString*)name
                                value:(id<NSFastEnumeration> /* WFGUID* */)value
                               format:(WFDLoggingFieldFormat)format
                                 tags:(int)tags;
- (void)addDateTime:(NSString*)name value:(WFDateTime*)value;
- (void)addDateTimeWithFormat:(NSString*)name value:(WFDateTime*)value format:(WFDLoggingFieldFormat)format;
- (void)addDateTimeWithFormatAndTags:(NSString*)name value:(WFDateTime*)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addDateTimeArray:(NSString*)name value:(id<NSFastEnumeration> /* WFDateTime* */)value;
- (void)addDateTimeArrayWithFormat:(NSString*)name
                             value:(id<NSFastEnumeration> /* WFDateTime* */)value
                            format:(WFDLoggingFieldFormat)format;
- (void)addDateTimeArrayWithFormatAndTags:(NSString*)name
                                    value:(id<NSFastEnumeration> /* WFDateTime* */)value
                                   format:(WFDLoggingFieldFormat)format
                                     tags:(int)tags;
- (void)addTimeSpan:(NSString*)name value:(WFTimeSpan*)value;
- (void)addTimeSpanWithFormat:(NSString*)name value:(WFTimeSpan*)value format:(WFDLoggingFieldFormat)format;
- (void)addTimeSpanWithFormatAndTags:(NSString*)name value:(WFTimeSpan*)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addTimeSpanArray:(NSString*)name value:(id<NSFastEnumeration> /* WFTimeSpan* */)value;
- (void)addTimeSpanArrayWithFormat:(NSString*)name
                             value:(id<NSFastEnumeration> /* WFTimeSpan* */)value
                            format:(WFDLoggingFieldFormat)format;
- (void)addTimeSpanArrayWithFormatAndTags:(NSString*)name
                                    value:(id<NSFastEnumeration> /* WFTimeSpan* */)value
                                   format:(WFDLoggingFieldFormat)format
                                     tags:(int)tags;
- (void)addPoint:(NSString*)name value:(WFPoint*)value;
- (void)addPointWithFormat:(NSString*)name value:(WFPoint*)value format:(WFDLoggingFieldFormat)format;
- (void)addPointWithFormatAndTags:(NSString*)name value:(WFPoint*)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addPointArray:(NSString*)name value:(id<NSFastEnumeration> /* WFPoint* */)value;
- (void)addPointArrayWithFormat:(NSString*)name value:(id<NSFastEnumeration> /* WFPoint* */)value format:(WFDLoggingFieldFormat)format;
- (void)addPointArrayWithFormatAndTags:(NSString*)name
                                 value:(id<NSFastEnumeration> /* WFPoint* */)value
                                format:(WFDLoggingFieldFormat)format
                                  tags:(int)tags;
- (void)addSize:(NSString*)name value:(WFSize*)value;
- (void)addSizeWithFormat:(NSString*)name value:(WFSize*)value format:(WFDLoggingFieldFormat)format;
- (void)addSizeWithFormatAndTags:(NSString*)name value:(WFSize*)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addSizeArray:(NSString*)name value:(id<NSFastEnumeration> /* WFSize* */)value;
- (void)addSizeArrayWithFormat:(NSString*)name value:(id<NSFastEnumeration> /* WFSize* */)value format:(WFDLoggingFieldFormat)format;
- (void)addSizeArrayWithFormatAndTags:(NSString*)name
                                value:(id<NSFastEnumeration> /* WFSize* */)value
                               format:(WFDLoggingFieldFormat)format
                                 tags:(int)tags;
- (void)addRect:(NSString*)name value:(WFRect*)value;
- (void)addRectWithFormat:(NSString*)name value:(WFRect*)value format:(WFDLoggingFieldFormat)format;
- (void)addRectWithFormatAndTags:(NSString*)name value:(WFRect*)value format:(WFDLoggingFieldFormat)format tags:(int)tags;
- (void)addRectArray:(NSString*)name value:(id<NSFastEnumeration> /* WFRect* */)value;
- (void)addRectArrayWithFormat:(NSString*)name value:(id<NSFastEnumeration> /* WFRect* */)value format:(WFDLoggingFieldFormat)format;
- (void)addRectArrayWithFormatAndTags:(NSString*)name
                                value:(id<NSFastEnumeration> /* WFRect* */)value
                               format:(WFDLoggingFieldFormat)format
                                 tags:(int)tags;
@end

#endif // __WFDLoggingFields_DEFINED__

// Windows.Foundation.Diagnostics.LoggingActivity
#ifndef __WFDLoggingActivity_DEFINED__
#define __WFDLoggingActivity_DEFINED__

WINRT_EXPORT
@interface WFDLoggingActivity : RTObject <WFIClosable, WFDILoggingTarget>
+ (WFDLoggingActivity*)createLoggingActivity:(NSString*)activityName loggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel ACTIVATOR;
+ (WFDLoggingActivity*)createLoggingActivityWithLevel:(NSString*)activityName
                                       loggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel
                                                level:(WFDLoggingLevel)level ACTIVATOR;
@property (readonly) WFGUID* id;
@property (readonly) NSString* name;
@property (readonly) WFDLoggingChannel* channel;
- (void)close;
- (void)stopActivity:(NSString*)stopEventName;
- (void)stopActivityWithFields:(NSString*)stopEventName fields:(WFDLoggingFields*)fields;
- (void)stopActivityWithFieldsAndOptions:(NSString*)stopEventName fields:(WFDLoggingFields*)fields options:(WFDLoggingOptions*)options;
- (BOOL)isEnabled;
- (BOOL)isEnabledWithLevel:(WFDLoggingLevel)level;
- (BOOL)isEnabledWithLevelAndKeywords:(WFDLoggingLevel)level keywords:(int64_t)keywords;
- (void)logEvent:(NSString*)eventName;
- (void)logEventWithFields:(NSString*)eventName fields:(WFDLoggingFields*)fields;
- (void)logEventWithFieldsAndLevel:(NSString*)eventName fields:(WFDLoggingFields*)fields level:(WFDLoggingLevel)level;
- (void)logEventWithFieldsAndOptions:(NSString*)eventName
                              fields:(WFDLoggingFields*)fields
                               level:(WFDLoggingLevel)level
                             options:(WFDLoggingOptions*)options;
- (WFDLoggingActivity*)startActivity:(NSString*)startEventName;
- (WFDLoggingActivity*)startActivityWithFields:(NSString*)startEventName fields:(WFDLoggingFields*)fields;
- (WFDLoggingActivity*)startActivityWithFieldsAndLevel:(NSString*)startEventName
                                                fields:(WFDLoggingFields*)fields
                                                 level:(WFDLoggingLevel)level;
- (WFDLoggingActivity*)startActivityWithFieldsAndOptions:(NSString*)startEventName
                                                  fields:(WFDLoggingFields*)fields
                                                   level:(WFDLoggingLevel)level
                                                 options:(WFDLoggingOptions*)options;
@end

#endif // __WFDLoggingActivity_DEFINED__

// Windows.Foundation.Diagnostics.LoggingChannel
#ifndef __WFDLoggingChannel_DEFINED__
#define __WFDLoggingChannel_DEFINED__

WINRT_EXPORT
@interface WFDLoggingChannel : RTObject <WFDILoggingChannel, WFIClosable, WFDILoggingTarget>
+ (WFDLoggingChannel*)createWithOptions:(NSString*)name options:(WFDLoggingChannelOptions*)options ACTIVATOR;
+ (WFDLoggingChannel*)createWithOptionsAndId:(NSString*)name options:(WFDLoggingChannelOptions*)options id:(WFGUID*)id ACTIVATOR;
+ (WFDLoggingChannel*)create:(NSString*)name ACTIVATOR;
@property (readonly) BOOL enabled;
@property (readonly) WFDLoggingLevel level;
@property (readonly) NSString* name;
@property (readonly) WFGUID* id;
- (EventRegistrationToken)addLoggingEnabledEvent:(void (^)(RTObject<WFDILoggingChannel>*, RTObject*))del;
- (void)removeLoggingEnabledEvent:(EventRegistrationToken)tok;
- (void)logMessage:(NSString*)eventString;
- (void)logMessageWithLevel:(NSString*)eventString level:(WFDLoggingLevel)level;
- (void)logValuePair:(NSString*)value1 value2:(int)value2;
- (void)logValuePairWithLevel:(NSString*)value1 value2:(int)value2 level:(WFDLoggingLevel)level;
- (void)close;
- (BOOL)isEnabled;
- (BOOL)isEnabledWithLevel:(WFDLoggingLevel)level;
- (BOOL)isEnabledWithLevelAndKeywords:(WFDLoggingLevel)level keywords:(int64_t)keywords;
- (void)logEvent:(NSString*)eventName;
- (void)logEventWithFields:(NSString*)eventName fields:(WFDLoggingFields*)fields;
- (void)logEventWithFieldsAndLevel:(NSString*)eventName fields:(WFDLoggingFields*)fields level:(WFDLoggingLevel)level;
- (void)logEventWithFieldsAndOptions:(NSString*)eventName
                              fields:(WFDLoggingFields*)fields
                               level:(WFDLoggingLevel)level
                             options:(WFDLoggingOptions*)options;
- (WFDLoggingActivity*)startActivity:(NSString*)startEventName;
- (WFDLoggingActivity*)startActivityWithFields:(NSString*)startEventName fields:(WFDLoggingFields*)fields;
- (WFDLoggingActivity*)startActivityWithFieldsAndLevel:(NSString*)startEventName
                                                fields:(WFDLoggingFields*)fields
                                                 level:(WFDLoggingLevel)level;
- (WFDLoggingActivity*)startActivityWithFieldsAndOptions:(NSString*)startEventName
                                                  fields:(WFDLoggingFields*)fields
                                                   level:(WFDLoggingLevel)level
                                                 options:(WFDLoggingOptions*)options;
@end

#endif // __WFDLoggingChannel_DEFINED__

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
